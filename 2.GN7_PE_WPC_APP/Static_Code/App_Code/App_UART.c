/***************************************************************************************************
    THEME NAME  :   WPC
    USE CPU     :	CYT2BL4CAA (80-LQFP)
	MEMORY      :	Code-flash : 4160KB (4032KB + 128KB), Work-Flash 128KB (96KB + 32KB), SRAM : 512KB, ROM 32KB
    USE CLOCK   :
    LANGUAGE    :
    REMARKS     :   Source encoding information is UFT-8.

    (C) Copyright NIDEC MOBILITY KOREA CORPORATION. 2023 All Rights Reserved

***************************************************************************************************/


/***************************************************************************************************
    INCLUDE FILES
***************************************************************************************************/
#include "EcuInfo.h"
#include "App_UART.h"
#include "Rte_App_UART.h"

#include "App_WCT.h"
#include "App_Repro.h"
#include "App_Model_types.h"

#include "cy_syslib.h"
#include "cy_scb_common.h"
#include "cy_scb_uart.h"
#include "Spi_Common.h" // Cy_SysLib_EnterCriticalSection() 대신 spi 의 Spi_Com_SchMEnterCriticalSection() 사용하기 위함


#define App_UART_START_SEC_CODE
#include "App_UART_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/
#define cUART_Disable 		0u
#define cUART_Enable 		1u

#define cNormalRxDataMaxSize 		19u	// 최대 수신 데이터 수 듀얼용 19바이트임.

/* Select UART Echo Type                                                   */
/*                                                                         */
/* Use Low-Level API                                                       */
/*  (1) Polling & Receive by 1 byte unit                                   */
/* Use High-Level API                                                      */
/*  (2) Interrupt & Receive by 1 byte unit                                 */
/*  (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */
/*  (4) Interrupt & Receive using Ring Buffer (Half of RX FIFO size)       */
//#define E_UART_NORMAL_ECHO_POLLING_1BYTE
//#define E_UART_NORMAL_ECHO_INTR_1BYTE
#define E_UART_NORMAL_ECHO_INTR_THRESHOLD
//#define E_UART_NORMAL_ECHO_INTR_RINGBUF

/* Local Definision */
#define E_UART_NORMAL_RECV_THRESHOLD    19
#define E_UART_NORMAL_RING_BUF_SIZE     512
#define E_UART_NORMAL_USER_BUF_SIZE     512
#define E_UART_NORMAL_RX_INTR_FACTER     (                              \
								 CY_SCB_UART_RX_TRIGGER      |   \
							   /*CY_SCB_UART_RX_NOT_EMPTY    | */\
							   /*CY_SCB_UART_RX_FULL         | */\
								 CY_SCB_UART_RX_OVERFLOW     |   \
								 CY_SCB_UART_RX_UNDERFLOW    |   \
								 CY_SCB_UART_RX_ERR_FRAME    |   \
								 CY_SCB_UART_RX_ERR_PARITY   |   \
								 CY_SCB_UART_RX_BREAK_DETECT |   \
								 0UL                               \
								)
#define E_UART_NORMAL_TX_INTR_FACTER     (                              \
							   	CY_SCB_UART_TX_TRIGGER      | \
							   /*CY_SCB_UART_TX_NOT_FULL     | */\
							   /*CY_SCB_UART_TX_EMPTY        | */\
							   	CY_SCB_UART_TX_OVERFLOW     | \
							   /*CY_SCB_UART_TX_UNDERFLOW    | */\
							   	CY_SCB_UART_TX_DONE         | \
							   /*CY_SCB_UART_TX_NACK         | */\
							   /*CY_SCB_UART_TX_ARB_LOST     | */\
								 0UL                               \
								)


/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
typedef enum
{
    AUTH_HANDLER_IDLE                   = 0x00U,
    AUTH_HANDLER_WAIT_SHA256            = 0x01U,
    AUTH_HANDLER_SIGN_WAIT_START        = 0x02U,
    AUTH_HANDLER_SIGN_WAIT_RESULT       = 0x03U
}AUTH_HANDLER_TYPE_E;

typedef enum
{
	AUTH_PACKET_NONE                 	= 0x0U,
	AUTH_PACKET_DIGESTS                 = 0x1U,
	AUTH_PACKET_CERTIFICATE             = 0x2U,
	AUTH_PACKET_CHALLENGE_AUTH          = 0x3U,
	AUTH_PACKET_ERROR                   = 0x7U,
	AUTH_PACKET_GET_DIGESTS             = 0x9U,
	AUTH_PACKET_GET_CERTIFICATE         = 0xAU,
	AUTH_PACKET_CHALLENGE               = 0xBU
}AUTH_PACKET_TYPE_E;

typedef enum
{
	AUTH_NONE               			= 0x0u,
	AUTH_ERROR_1            			= 0x1u,
	AUTH_ERROR_2            			= 0x2u,
	AUTH_ERROR_3            			= 0x3u,
	AUTH_ERROR_4            			= 0x4u,
	AUTH_TIMEOUT_1          			= 0x5u,
	AUTH_TIMEOUT_2          			= 0x6u,
	AUTH_CHALLENGE_RESPONSE 			= 0x7u
}AUTH_RESULT_TYPE_E;

typedef enum
{
	Tim_WctUartRxTimeout,
	//Tim_ReproUartRxTimeout,	
	Tim_UART_MAX
}UART_TMR_ENUM_t;


typedef struct
{
	uint8_t Runnable_State;
	uint8_t App_Init_Completed;
	uint8_t StateCurr;
	uint8_t StateNext;
	uint8_t StateOld;
	uint8_t EntryCnt;
	uint8_t ExitCnt;

	uint8_t TxDataBuf[cRequest_Cmd_Size];	
	uint8_t RxDataBuf[cNormalRxDataMaxSize];
	
	uint8_t WctUartInterruptRecvIndication;
	uint8_t WctUartDataRecvIndication;

	uint8_t UartTxCmdOld[Device_MAX];
	uint8_t DvpStartOld;

	uint16_t NormalTxCnt;
	uint16_t Par_WctRxTimeout;

	uint8_t ActiveCoilID_Old[Device_MAX];
	Event_t WctUartCommReady_Evt;

	uint16_t ChargingVolt_mV[Device_MAX];
	uint32_t ChargingPower_mW[Device_MAX];

	// for degug
	WCT_TX_CHARGING_STATUS_E TxChargingStatus[Device_MAX];
	WCT_TX_CHARGING_ERRORS_E TxChargingErrors[Device_MAX];
	WCT_RX_CHARGING_STATUS_E RxChargingStatus[Device_MAX];
	WCT_RX_CHARGING_ERRORS_E RxChargingErrors[Device_MAX];

	uint8_t SecureFlag;
	
}Inter_t;

typedef struct
{
	IDT_ADC_STR 		Inp_ADC;
	IDT_WCT_STR			Inp_WCT;
	IDT_Uds_STR 		Inp_Uds;
	IDT_Model_STR		Inp_Model;
	IDT_Repro_STR 		Inp_Repro;
	IDT_NvM_STR 		Inp_NvM;

	Inter_t 			Int;
	Timer_t 			Timer[Tim_UART_MAX];

	IDT_UART_STR 	Out;
} UART_struct;



/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

// WPC_21_04
// 모빌젠에서 Ecud_Mcu.arxml 에서 McuClockReferencePoint_SCB4_CLOCK = 307,199.9960678401 이다.
// 아래 oversample의 값으로 나눈값이 baud가 된다.
// (valid range is 8-16). 나누기 값은 8 ~ 16까지만 된다. 즉 2가지 보레이트만 사용 가능할듯.
// 307,199.9960678401 / 16 = 19,199.99
// 307,199.9960678401 / 8 = 38,399.99


 // McuClockReferencePoint_SCB4_CLOCK = 307199.9960678401
// 리프로그래밍 속도가 너무느리면 일반을 57,600, 리프로를 115,200으로 변경해야 할수도 있음.

// McuClockReferencePoint_SCB4_CLOCK = 92159.99528140824 로 하면 115200(oversample=8), 57600(oversample=16) 사용 가능함
// MCUPclkDividerSettings_7 을 86.80556 으로 변경

// Reprogram : 115200
// Normal    : 57600 --> 115200
static cy_stc_scb_uart_context_t   g_stc_uart_normal_context;
static cy_stc_scb_uart_config_t    g_stc_uart_normal_config = {
												   .uartMode                   = (uint32_t)CY_SCB_UART_STANDARD,
												   .oversample                 = 8,	// WPC_21_04 // 57600--> 115200으로 변경해봄
												   .dataWidth                  = 8,
												   .enableMsbFirst             = false,
												   .stopBits                   = (uint32_t)CY_SCB_UART_STOP_BITS_1,
												   .parity                     = (uint32_t)CY_SCB_UART_PARITY_NONE,
												   .enableInputFilter          = false,
												   .dropOnParityError          = false,
												   .dropOnFrameError           = false,
												   .enableMutliProcessorMode   = false,
												   .receiverAddress            = 0,
												   .receiverAddressMask        = 0,
												   .acceptAddrInFifo           = false,
												   .irdaInvertRx               = false,
												   .irdaEnableLowPowerReceiver = false,
												   .smartCardRetryOnNack       = false,
												   .enableCts                  = false,
												   .ctsPolarity                = (uint32_t)CY_SCB_UART_ACTIVE_LOW,
												   .rtsRxFifoLevel             = 0,
												   .rtsPolarity                = (uint32_t)CY_SCB_UART_ACTIVE_LOW,
												   .breakWidth                 = 0,
												   .rxFifoTriggerLevel         = 0,
												   .rxFifoIntEnableMask        = E_UART_NORMAL_RX_INTR_FACTER,
												   .txFifoTriggerLevel         = 0,
												   .txFifoIntEnableMask        = E_UART_NORMAL_TX_INTR_FACTER
												};
/* Local Variables */
// Interrupt 적용시 사용
//static uint8_t g_uart_out_data[128] = {0};                       // TX Buffer for Terminal Print
//static uint8_t g_uart_normal_in_data[128] = {0};                        // RX Buffer
static uint8_t g_uart_normal_in_data[cNormalRxDataMaxSize] = {0};                        // RX Buffer

// ring buffer 적용시 사용
#if defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
static uint8_t g_uart_normal_rx_ring[E_UART_NORMAL_RING_BUF_SIZE] = {0}; // RX Ring Buffer
static uint8_t g_uart_normal_user_buf[E_UART_NORMAL_USER_BUF_SIZE] = {0};      // User Buffer for coping from Ring Buffer
#endif
static uint8_t num_normal;

static UART_struct UART = {0};


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_UART_InitSet(void);
static void ss_UART_Data_Init(void);

static void ss_UART_RteRead(void);
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE) || defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
static void ss_UART_CommRead(void);
#endif
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE)
static void Term_Input(void);
#endif
static void ss_UART_RteWrite(void);

static void ss_UART_StateMachine(uint8_t CurrState, uint8_t action);

static void ss_UART_Disable(uint8_t action);
static void ss_UART_Enable(uint8_t action);
//static void ss_UART_REPRO_Enable(uint8_t action);

static void ss_UART_BufferClear(void);
static void ss_UART_Scb_Init(void);
static void ss_UART_Scb_DeInit(void);
static void ss_UART_Receive(void);
static void ss_UART_Transmit(void);
static void ss_UART_Wct_RxTimeoutCheck(void);
static void ss_UART_DeviceStatusJudge(uint8_t Device);
static void ss_UART_ActiveCoilIDJudge(uint8_t Device);
//static uint8_t ss_HexToAscii(uint8_t n);
static uint8_t ss_CheckSum(uint8_t const *Buf, uint8_t size);
//static void ss_UartIntRxClear(void);
//static void ss_UartReproISR(void);

static void ss_UART_Scb_Event(unsigned long locEvents);

static void ss_UART_LPConditionCheck(void);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_UART_CODE) UART_TE_Runnable(void)
{

	switch(UART.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&UART.Int.App_Init_Completed);

			if( UART.Int.App_Init_Completed == ON ) 	/* SWP Init Complete? */
			{

				ss_UART_InitSet(); 		/* SWC Init Process */

				UART.Int.Runnable_State = 1u;

			}
		break;

		case 1u:


			//------------------------------------------------------
			// Input
			//------------------------------------------------------
			ss_UART_RteRead();
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE) || defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
			ss_UART_CommRead();
#endif

			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------
			ss_UART_StateMachine(UART.Int.StateCurr, DURING);

			// 상태 천이 발생시에만 실행
			if (UART.Int.StateCurr != UART.Int.StateNext)
			{
				ss_UART_StateMachine(UART.Int.StateCurr, EXIT);
				ss_UART_StateMachine(UART.Int.StateNext, ENTRY);

				// UART.Int.StateOld = UART.Int.StateCurr; // OldState 갱신 //이방식으로 하면 안됨.

				UART.Int.StateCurr = UART.Int.StateNext;
			}

			//------------------------------------------------------
			// Timer
			//------------------------------------------------------

			gs_UpdateTimer(&UART.Timer[0], (uint8_t)Tim_UART_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.

			//-----------------------------------------------------
			// Output
			//------------------------------------------------------

			ss_UART_RteWrite();

			ss_UART_LPConditionCheck();
		break;

		default:
			UART.Int.Runnable_State = 0u;
		break;
	}
}




/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_UART_InitSet(void)
{

	UART.Int.StateCurr = cUART_Disable;
	UART.Int.StateNext = cUART_Disable;
	UART.Int.StateOld = cUART_Disable;
	UART.Int.EntryCnt = 0u;
	UART.Int.ExitCnt = 0u;
	
	// ss_UART_Scb_Init(); // 불필요함.

	ss_UART_Disable(ENTRY);	// 전원 리셋시 Entry를 강제로 1회 실행시켜줘야함.// 초기화 함수가 호출됨.

}



/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_Data_Init(void)
{
	//gs_ClearData(g_uart_normal_in_data, cNormalRxDataMaxSize );	// buf clear
	//memset(g_uart_normal_in_data, 0, sizeof(g_uart_normal_in_data)); /* 010C_07 */ // 표준 라이브러리 함수로 변경

	ss_UART_BufferClear(); /* 010C_07 */

	UART.Int.WctUartInterruptRecvIndication = OFF;
	UART.Int.WctUartDataRecvIndication = OFF;

	//memset(&UART.Out, 0, sizeof(UART.Out));	/ 충전 IC 통신에러 DTC 둔감화 적용하면서 WctUartRxTimeoutCnt를 클리어하면 안되므로 전체 클리어 하면 안됨. // 구조체 변수를 0으로 클리어
	// memset(&UART.Out.Device_DVP, 0, sizeof(UART.Out.Device_DVP)); /* 010C_07 */
	// memset(&UART.Out.Device_WCT, 0, sizeof(UART.Out.Device_WCT)); /* 010C_07 */
	UART.Out.WctSourceVer[0] = '0';
	UART.Out.WctSourceVer[1] = '0';
	UART.Out.WctSourceVer[2] = '0';
	UART.Out.WctUartCommReady = OFF;
	UART.Out.WctUartRxTimeout = DETECTED_DEFAULT;
	UART.Out.WctErrorState = 0;
	

	gs_InitTimer(&UART.Timer[0], (uint8_t)Tim_UART_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_UART_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&UART.Inp_ADC);
	Rte_Read_R_WCT_WCT_STR(&UART.Inp_WCT);
	Rte_Read_R_Uds_Uds_STR(&UART.Inp_Uds);
	Rte_Read_R_Model_Model_STR(&UART.Inp_Model);
	Rte_Read_R_Repro_Repro_STR(&UART.Inp_Repro);
	Rte_Read_R_NvM_NvM_STR(&UART.Inp_NvM);
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE) || defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
static void ss_UART_CommRead(void)
{
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE)
        /* UART Echo Test (Low-Level)           */
        /* (1) Polling & Receive by 1 byte unit */
        Term_Input();
#endif

#if defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
        /* UART Echo Test (High-Level)                                       */
        /* (4) Interrupt & Receive using Ring Buffer (Half of RX FIFO size)  */
        /*     -> Copy receive data to User Buffer from Ring Buffer and Echo */
        //uint32_t num_normal = Cy_SCB_UART_GetNumInRingBuffer(SCB6, &g_stc_uart_normal_context);
        num_normal = Cy_SCB_UART_GetNumInRingBuffer(SCB6, &g_stc_uart_normal_context);
		if (num_normal != 0) {
            Cy_SCB_UART_Receive(SCB6, &g_uart_normal_user_buf[0], num_normal, &g_stc_uart_normal_context);  // 수신할 데이터의 버퍼와 크기를 설정하는 함수
            //Cy_SCB_UART_Transmit(SCB6, &g_uart_normal_user_buf[0], num_normal, &g_stc_uart_normal_context); // 송신할 데이터의 버퍼와 크기를 설정하는 함수
			UART.Int.WctUartInterruptRecvIndication = ON;
        }
#endif
}
#endif

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
#if defined(E_UART_NORMAL_ECHO_POLLING_1BYTE)
static void Term_Input(void)
{
    uint32_t    rx_num;

    /* Check Receive g_uart_normal_in_data[0] */
    rx_num = Cy_SCB_UART_GetNumInRxFifo(SCB6);
    if (0u == rx_num) return;

    /* UART In/Out */
#if 0
    uint32_t    cmd;
    cmd = Cy_SCB_UART_Get(SCB6);
    while (0UL == Cy_SCB_UART_Put(SCB6, cmd)) {}
#endif
#if 1
    Cy_SCB_UART_GetArray(SCB6, g_uart_normal_in_data, rx_num);	// 이벤트 방식이 아닌 직접 receive 하는 방식
    Cy_SCB_UART_PutArray(SCB6, g_uart_normal_in_data, rx_num); // 이벤트 방식이 아닌 직접 transmit 하는 방식
#endif
#if 0
    Cy_SCB_UART_GetArrayBlocking(SCB6, g_uart_normal_in_data, rx_num);
    Cy_SCB_UART_PutArrayBlocking(SCB6, g_uart_normal_in_data, rx_num);
    Cy_SCB_UART_PutString(SCB6, (char_t *)g_uart_normal_in_data);
#endif
}
#endif
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_UART_RteWrite(void)
{	
	for(uint8_t Device=0; Device<UART.Inp_NvM.DeviceMaxCnt; Device++)
	{
		// for degug
		UART.Int.RxChargingErrors[Device] = (WCT_RX_CHARGING_ERRORS_E)UART.Out.Device_WCT[Device].RxChargingErrors;
		UART.Int.RxChargingStatus[Device] = (WCT_RX_CHARGING_STATUS_E)UART.Out.Device_WCT[Device].RxChargingStatus;
		UART.Int.TxChargingErrors[Device] = (WCT_TX_CHARGING_ERRORS_E)UART.Out.Device_WCT[Device].TxChargingErrors;
		UART.Int.TxChargingStatus[Device] = (WCT_TX_CHARGING_STATUS_E)UART.Out.Device_WCT[Device].TxChargingStatus;
	}

	gs_UpdateEvent(UART.Out.WctUartCommReady, &UART.Int.WctUartCommReady_Evt);	// event update
	
	UART.Out.UART_Status = UART.Int.StateCurr;
	
	// 폰방치는 둘중 하나만 검출되도 양쪽 모두 검출된것으로 판단하여 모델에 전달한다. 
	// 모델이 수정되면 좋겠으나 임시 방편으로 이런식으로 사양에 맞게 함.
	if((UART.Out.Device_WCT[0].PhoneLeft == ON) ||
	(UART.Out.Device_WCT[1].PhoneLeft == ON))
	{
		UART.Out.Device_WCT[0].PhoneLeft = ON;
		UART.Out.Device_WCT[1].PhoneLeft = ON;
	}
	
	
	// 타 SWC에 RTE로 전달	
	Rte_Write_P_UART_UART_STR(&UART.Out);	// 한꺼번에 전송


}


/***************************************************************************************************
@param[in]  CurrState : Current State
@param[in]	Command : En, Do, Ex Condition
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_StateMachine(uint8_t CurrState, uint8_t action)
{
	switch (CurrState)
	{
		case cUART_Disable:
			ss_UART_Disable(action);
		break;
		
		case cUART_Enable:
		 	ss_UART_Enable(action);
		break;		


		default:
		// M3CM Rule-16.4
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_UART_Disable(uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		ss_UART_Data_Init();
		ss_UART_Scb_DeInit();


		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (UART.Int.StateCurr == UART.Int.StateNext)
		{
			// State's Transitions			
			// if((UART.Inp_WCT.Device[D0].WCT_Status != cWCT_Disable) || // 컨셉 변경 WCT_Disable에서도 uart는 stop을 송신해야한다. 중지되지 않는다.
			// (UART.Inp_WCT.Device[D1].WCT_Status != cWCT_Disable) ||
			// (UART.Inp_Repro.ReproVersionVerifyReq == ON))
			// {
			//if((UART.Inp_Repro.Repro_Status == cRepro_Disable) ||	// 리프로 동작시에는 uart 이 채널은 동작하면 안됨.			
			//if((UART.Inp_Uds.Repro_Start == OFF) ||	// Repro_Status로 했더니 리트라이 할때 uart enable로 이동했다가 다시 disable 되었다가 반복해서 신호 변경함
			if((UART.Inp_WCT.NormalUartStart == ON) ||
			(UART.Inp_Repro.ReproVersionVerifyReq == ON))
			{
				UART.Int.StateNext = cUART_Enable;
				UART.Int.EntryCnt = 0u; // En 실행 : UART WCT Enable
				UART.Int.ExitCnt = 0u;  // Ex 실행 : None
			}		
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행

			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:


		break;

	/********************************************************/
	default:
	// M3CM Rule-16.4
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_UART_Enable(uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		// 상위 level State 없음

		// 2. 하위(자식) Level State en 실행
		ss_UART_Scb_Init();
		gs_StartTimer(&UART.Timer[Tim_WctUartRxTimeout]);
		
		UART.Int.Par_WctRxTimeout = Par_InitUartTimeoutTime; // 4초. 전원 리셋 후에는 충전 IC 부팅시간이 500ms 더 걸리므로 normal보다 2초 길게 대기하도록 함.

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (UART.Int.StateCurr == UART.Int.StateNext)
		{
			// State's Transitions			
			// if((UART.Inp_WCT.Device[D0].WCT_Status == cWCT_Disable) &&
			// (UART.Inp_WCT.Device[D1].WCT_Status == cWCT_Disable) &&
			// (UART.Inp_Repro.ReproVersionVerifyReq == OFF))
			// if((UART.Out.WctUartRxTimeout == (uint8_t)DETECTED_ON) ||
			// ((UART.Inp_Uds.Repro_Start == ON) &&
			//((UART.Inp_Repro.Repro_Status == cRepro_Enable) && // 리프로 동작시에는 uart 이 채널은 동작하면 안됨.	
			if((UART.Inp_WCT.NormalUartStart == OFF) &&
			(UART.Inp_Repro.ReproVersionVerifyReq == OFF))
			{
				UART.Int.StateNext = cUART_Disable; // WPC_32_02
				UART.Int.EntryCnt = 0u; // En 실행 : WCT_Disable // WPC_32_02
				UART.Int.ExitCnt = 0u;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_UART_Receive();
				ss_UART_Wct_RxTimeoutCheck();
				ss_UART_Transmit();
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행
		gs_CancelTimer(&UART.Timer[Tim_WctUartRxTimeout]);

		// 2. 상위(부모) Level State ex 실행
		// 상위 level State 없음


		break;

	//==============================================================
	default:
	// M3CM Rule-16.4
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
// 5w 사양 설명. (gn7에서도 동일하게 동작해야 함.)
// 2초 이상 wct로부터 통신 발생하지 않으면 에러 처리하고 DTC 코드 발생시킴.
// 그리고 WCT 전원 리셋 시킨후 통신 정상인지여부 다시 체크하고 정상이면 DTC 클리어 하고 복귀
// 정상 아니면 계속해서 DTC 코드 발생하고 다시 wCT 전원 리셋하고 반복하는 처리임.

// --> 일단은 동일하게 동작하는 것으로 생각하고 로직 구현함.
static void ss_UART_Wct_RxTimeoutCheck(void)
{
	// 최초 판단시 2초가 소요되므로 2초 전 에러 판단 전까지는
	// DETECTED_DEFAULT (0x00)으로 설정한다.
	// 이렇게 되면 DTC에서 최초 2초간은 DTC 판단을 하지 않게 된다.
	if((UART.Int.WctUartDataRecvIndication == ON) &&
	(UART.Out.WctUartCommReady == ON)) // 최초 통신이 이루어져야 함.
	{
		UART.Int.WctUartDataRecvIndication = OFF;

		UART.Out.WctUartRxTimeout = (uint8_t)DETECTED_OFF;
		gs_ReStartTimer(&UART.Timer[Tim_WctUartRxTimeout]);
		UART.Int.Par_WctRxTimeout = Par_WctUartTimeoutTime;
		
	}
	else if(UART.Timer[Tim_WctUartRxTimeout].Count >= UART.Int.Par_WctRxTimeout)
	{
		UART.Out.WctUartRxTimeout = (uint8_t)DETECTED_ON;
		gs_CancelTimer(&UART.Timer[Tim_WctUartRxTimeout]);
		
	}
	else
	{
		// M3CM Rule-15.7
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_Receive(void)
{
	uint8_t CheckSum;
	uint8_t i = 0;
	uint8_t Device = 0;
	uint8_t Offset = 0;

	if(UART.Int.WctUartInterruptRecvIndication == ON)
	{
		UART.Int.WctUartInterruptRecvIndication = OFF;

		for(i=0; i<cResponse_Data_Size; i++)
		{
			UART.Int.RxDataBuf[i] = g_uart_normal_in_data[i];
			g_uart_normal_in_data[i] = 0;
		}

		CheckSum = ss_CheckSum(UART.Int.RxDataBuf, cResponse_Data_Size);

		// 아래 처럼 전체를 클리어 하니 dvp 시작시 충전 중단 되는 현상이 있음.  or 연산하는 값들만 직접 클리어 처리하자.
		//memset(&UART.Out.Device_WCT, 0, sizeof(UART.Out.Device_WCT)); /* 0106_05 */ // or 연산 때문에 값이 누적되지 않도록 매번 클리어 처리함.
		
		if((UART.Int.RxDataBuf[0] == cHeader_Response) &&
		(CheckSum == UART.Int.RxDataBuf[cResponse_Data_Size - 1u]))
		{
			switch(UART.Int.RxDataBuf[1])	// index별로 분기
			{
				case cResponse_Data_IndexF: // 충전 IC Power On시에 최초 수신되는 버전 정보 및 에러 정보를 취득한다.
					// 특정 패턴을 데이터로 사용하여 초기 구동 확인 및 버전 정보 취득에 사용한다.
					// 또는 1회성으로 전송하면 되는 데이터를 추가한다.
					if((UART.Int.RxDataBuf[2] == 0x11u) && (UART.Int.RxDataBuf[3] == 0x22u) &&
					   (UART.Int.RxDataBuf[4] == 0x33u) && (UART.Int.RxDataBuf[5] == 0x44u) &&
					   (UART.Int.RxDataBuf[6] == 0x55u) && (UART.Int.RxDataBuf[7] == 0x66u) &&
					   (UART.Int.RxDataBuf[8] == 0x77u))
					{
						UART.Out.WctUartCommReady = ON;

						// common data
						UART.Out.WctSourceVer[0] = UART.Int.RxDataBuf[9];
						UART.Out.WctSourceVer[1] = UART.Int.RxDataBuf[10];
						UART.Out.WctSourceVer[2] = UART.Int.RxDataBuf[11];
						UART.Out.WctErrorState = (((uint16_t)UART.Int.RxDataBuf[12] << 8u) | (uint16_t)UART.Int.RxDataBuf[13]);
					}
				break;

				case cResponse_Data_Index0:

					UART.Int.WctUartDataRecvIndication = ON;

					// common data
					// UART.Out.WctSwVersion1 = ss_HexToAscii((UART.Int.RxDataBuf[2] & 0xF0) >> 4u); // hex를 ascii로 변환
					// UART.Out.WctSwVersion2 = ss_HexToAscii(UART.Int.RxDataBuf[2] & 0x0F);
					// UART.Out.WctSwVersion3 = ss_HexToAscii((UART.Int.RxDataBuf[3] & 0xF0) >> 4u);

					//------------------------------------------------------------------------------------------------
					// Device 0 / 1
					//------------------------------------------------------------------------------------------------
					for(Device = 0; Device < UART.Inp_NvM.DeviceMaxCnt; Device++)
					{
						if(Device == 0u)
						{
							Offset = 0u;
						}
						else
						{
							Offset = 8u;
						}

						UART.Out.Device_WCT[Device].RxChargingStatus = (UART.Int.RxDataBuf[2u+Offset] & 0x0FU);
						UART.Out.Device_WCT[Device].TxChargingErrors = (UART.Int.RxDataBuf[2u+Offset] & 0xF0U) >> 4U;
						UART.Out.Device_WCT[Device].TxChargingStatus = (UART.Int.RxDataBuf[3u+Offset] & 0x0FU);
						//UART.Out.Device_WCT[Device]. = (UART.Int.RxDataBuf[3u+Offset] & 0xF0U) >> 4U;
						// TempSnsrErr는 아래쪽에서 판단 후 설정함.
						UART.Out.Device_WCT[Device].CS100 = (UART.Int.RxDataBuf[4u+Offset] & 0x80U) >> 7u;
						UART.Out.Device_WCT[Device].ObjectDetection = (UART.Int.RxDataBuf[4u+Offset] & 0x40U) >> 6u;
						UART.Out.Device_WCT[Device].PhoneLeft = (UART.Int.RxDataBuf[4u+Offset] & 0x10U) >> 4u;
						UART.Out.Device_WCT[Device].AuthState = (UART.Int.RxDataBuf[4u+Offset] & 0x08U) >> 3u;
						UART.Out.Device_WCT[Device].ChargingMode = (UART.Int.RxDataBuf[4u+Offset] & 0x07U);

						ss_UART_DeviceStatusJudge(Device);	// device state check

						ss_UART_ActiveCoilIDJudge(Device);	// UART를 통해서 코일 ID 정보 수신 불필요함. 1coil이므로 항상 0번임. 진단사양때문에 판단처리는 해야함.

						//================================================================
						// UDS 진단 사양서에 충전전류와 전압 파워를 표출할대 1바이트로 표출하도록 되어 있다.
						// 1바이트로 표출하려면 표출 범위가 0 ~ 255이므로 표출시 세분화하여 소숫점까지 표출이 안된다.
						// 그래서 진단 사양서에 보면 표출할수 있는 최대값을 미리 설정하고
						// 그 값을 255가 되도록 상수를 만든다.
						// 그렇게 해서 1바이트로 소숫점까지 표시 할수 있도록 설계 되어 있다.
						// max 20(V) : 0.08
						// max 10(A) : 0.0393
						// max 50(W) : 0.196
						// 예를 들어 13500mv(2byte)을 1byte로 전송하고 수신처에서 13500mV와 가장 근접한 값이 나오는지 확인해보자.
						// 송신 변환데이터 (2byte --> 1byte) = 13500 / 1000 / 0.08 (mV --> V로 변환)
						//                                  = 168.75 (통신으로 전송은 168만 전송함)
						// 수신 변환 데이터 (1byte --> 소숫점까지표시) = 168 * 0.08 * 1000 = 13440mV
						//================================================================

						// 상수 연산은 컴파일시 미리 연산될것이므로 계산량은 크지 않을 듯.
						// 모델에서는 mA 단위로 사용한다.

						// 변환식이여서 충전중 아닐때는 강제로 0으로 진단 IOR에 표시되도록 수정함.
						if(UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cStandby)
						{
							UART.Out.Device_WCT[Device].ChargingCurrent_Convert = 0;
							UART.Out.Device_WCT[Device].ChargingCurrent = 0;
							UART.Out.Device_WCT[Device].ChargingVolt_Convert = 0;
							UART.Int.ChargingVolt_mV[Device] = 0;
						}
						else
						{
							UART.Out.Device_WCT[Device].ChargingCurrent_Convert = UART.Int.RxDataBuf[5u+Offset];
							//UART.Out.Device_WCT[Device].ChargingCurrent = (uint16_t)(UART.Int.RxDataBuf[5u+Offset] * 1000u * 0.0393); // A -->mA 변환
							UART.Out.Device_WCT[Device].ChargingCurrent = (uint16_t)((UART.Int.RxDataBuf[5u+Offset] * 393u) / 10u); // A -->mA 변환

							UART.Out.Device_WCT[Device].ChargingVolt_Convert = UART.Int.RxDataBuf[6u+Offset];
							//UART.Int.ChargingVolt_mV[Device] = (uint16_t)(UART.Int.RxDataBuf[6u+Offset] * 1000u * 0.08); // V -->mV 변환
							UART.Int.ChargingVolt_mV[Device] = (uint16_t)UART.Int.RxDataBuf[6u+Offset] * 80u; // V -->mV 변환
						}

						/* 0106_02 start */
						//UART.Out.Device_WCT[Device].CoilTempDegree = (int16_t)((int16_t)UART.Int.RxDataBuf[7u+Offset] - 40);// wct ic에서 1바이트로 변환하기 위해서 +40했으므로 -40해서 원래 온도로 변환						
						UART.Out.Device_WCT[Device].CoilTempDegree = 0; /* 0107_04 */
						UART.Out.Device_WCT[Device].CoilTempDegree |= UART.Int.RxDataBuf[7u+Offset]; // 최하위 바이트
						UART.Out.Device_WCT[Device].CoilTempDegree |= ((UART.Int.RxDataBuf[3u+Offset] & 0xF0U) << 4u); // 최상위 바이트 // 12비트로 온도 변환 없이 그대로 표출
						if (UART.Out.Device_WCT[Device].CoilTempDegree & 0x0800) {  // 최상위 비트(11번째 비트)가 1이면 음수
							UART.Out.Device_WCT[Device].CoilTempDegree |= 0xF000;   // 상위 4비트를 1로 채워 2의 보수 형태로 만듦
						}
												
						//UART.Out.Device_WCT[Device].CoilTempDegree_Convert = (uint8_t)(UART.Int.RxDataBuf[7u+Offset]);  // WCT에서 1바이트로 변환되어 수신된 값이므로 그대로 전달함.						
						/* 0106_02 stop */
						
						// -30도 이하에서는 온도 센서 페일을 항상 OFF처리함 (온도 센서 FAIL 검출 금지)
						// WCT IC에서는 원래대로 온도 센세 페일 검출하고 어플리케이션에서 임의로 온도 조건에 따라 페일을 OFF 처리함.
						
						// 온도센서 페일 검출 방식이 특정 온도 이하일 경우 검출되므로 
						// 고객에서 저온 챔버에 -40도 이하로 테스트시 온도센서 페일에 의한 DTC 발생함.
						// 이를 방지하기 위해서 아래와 같이 특정 온도 이하에서는 온도센서 페일 검출하지 않도록 함.
						// 그러나 이 방법은 NTC를 미실장할경우 -40도 이하의 극 저온으로 판단하게 됨.
						// 그렇게 되면 NTC 미실장을 판단 할수가 없게 됨.
						// 그래서 저온 챔버에서도 내리수 없는 극 저온의 경우에는 온도센서 판정하도록 변경함.
						// NTC 미실장시 -50도보다 낮은 온도로 측정되므로 온도 센서 페일 검출됨.
						// UART 온도 전달시 8비트 --> 12비트로 변경하여 -40도 이하의 온도 전달 가능하도록 변경함. (uart 프로토콜 변경)
						 
						
						if((UART.Out.Device_WCT[Device].CoilTempDegree <= -30) &&	
						(UART.Out.Device_WCT[Device].CoilTempDegree >= -50)) /* 0106_02 */
						{											
							UART.Out.Device_WCT[Device].TempSnsrError = OFF;
						}
						else
						{
							UART.Out.Device_WCT[Device].TempSnsrError = (UART.Int.RxDataBuf[4u+Offset] & 0x20U) >> 5u;
						}

						// Power는 충전 IC로 부터 수신하지 않고 수신한 current 와 Voltage로 계산하여 사용한다.
						// 나누기시에 / 는 나머지는 없고 몫만 리턴되므로 나머지까지 계산 되도록 계산시 주의가 필요함.--> float 등 사용하면 에러 발생해서 그냥 버림
						// 1w미만에서는 오차가 심함.
						UART.Int.ChargingPower_mW[Device] = (uint32_t)UART.Out.Device_WCT[Device].ChargingCurrent * (uint32_t)UART.Int.ChargingVolt_mV[Device]; // uW (마이크로 와트)
						//UART.Out.Device_WCT[Device].ChargingPower_Convert = (uint8_t)((UART.Int.ChargingPower_mW[Device] / 0.196) / (1000u x 1000u); // 1바이트로 변환 // uW --> W변환
						UART.Out.Device_WCT[Device].ChargingPower_Convert = (uint8_t)(UART.Int.ChargingPower_mW[Device] / 196000u); // 1바이트로 변환 // uW --> W변환

						UART.Out.Device_WCT[Device].RxChargingErrors = ((UART.Int.RxDataBuf[8u+Offset] & 0xF8u) >> 3u);
						UART.Out.Device_WCT[Device].ManufactureID = (((uint16_t)UART.Int.RxDataBuf[8u+Offset] & 0x07u) << 8u) | (uint16_t)UART.Int.RxDataBuf[9u+Offset];
					}

					break;

				case cResponse_Data_Index1:
				case cResponse_Data_Index4:
					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index1)
					{
						Device = 0u;
					}

					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index4)
					{
						Device = 1u;
					}

					// sint16 변수임.
					UART.Out.Device_DVP[Device].swPowerLossDetectionThreshold = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].swPowerLossDetectionThreshold |= (UART.Int.RxDataBuf[2] << 8u);// 최상위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].swPowerLossDetectionThreshold |= UART.Int.RxDataBuf[3];		// 최하위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					
					UART.Out.Device_DVP[Device].swNormalizedParasiticLoss = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].swNormalizedParasiticLoss |= (UART.Int.RxDataBuf[4] << 8u);// 최상위 바이트	  /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].swNormalizedParasiticLoss |= UART.Int.RxDataBuf[5]; 		// 최하위 바이트	  /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					
					UART.Out.Device_DVP[Device].swParasiticLoss = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].swParasiticLoss |= (UART.Int.RxDataBuf[6] << 8u); 	// 최상위 바이트			  /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].swParasiticLoss |= UART.Int.RxDataBuf[7]; 			// 최하위 바이트			  /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					
					UART.Out.Device_DVP[Device].swSFCPowerLossThresholdInOperationMode = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].swSFCPowerLossThresholdInOperationMode |= (UART.Int.RxDataBuf[8] << 8u); 	// 최상위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].swSFCPowerLossThresholdInOperationMode |= UART.Int.RxDataBuf[9]; 			// 최하위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */					
					// sint16 변수임.
						
					UART.Out.Device_DVP[Device].dwActiveFreq = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].dwActiveFreq |= (UART.Int.RxDataBuf[10] << 24u);	// 최상위 바이트
					UART.Out.Device_DVP[Device].dwActiveFreq |= (UART.Int.RxDataBuf[11] << 16u);
					UART.Out.Device_DVP[Device].dwActiveFreq |= (UART.Int.RxDataBuf[12] << 8u);
					UART.Out.Device_DVP[Device].dwActiveFreq |= UART.Int.RxDataBuf[13];			// 최하위 바이트


					// = UART.Int.RxDataBuf[14];
					// = UART.Int.RxDataBuf[15];
					// = UART.Int.RxDataBuf[16];
					// = UART.Int.RxDataBuf[17];
					break;

				case cResponse_Data_Index2:
				case cResponse_Data_Index5:
					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index2)
					{
						Device = 0u;
					}

					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index5)
					{
						Device = 1u;
					}

					UART.Out.Device_DVP[Device].swBPPLPPowerLossThresholdInOperationMode = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].swBPPLPPowerLossThresholdInOperationMode |= (UART.Int.RxDataBuf[2] << 8u); 	// 최상위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].swBPPLPPowerLossThresholdInOperationMode |= UART.Int.RxDataBuf[3]; 			// 최하위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					
					UART.Out.Device_DVP[Device].wMeasuredQFactor = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].wMeasuredQFactor |= (UART.Int.RxDataBuf[4] << 8u);	// 최상위 바이트
					UART.Out.Device_DVP[Device].wMeasuredQFactor |= UART.Int.RxDataBuf[5];			// 최하위 바이트
					
					UART.Out.Device_DVP[Device].sdwTxPowerInCalibMode2 = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].sdwTxPowerInCalibMode2 |= (UART.Int.RxDataBuf[6] << 8u); 	// 최상위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					UART.Out.Device_DVP[Device].sdwTxPowerInCalibMode2 |= UART.Int.RxDataBuf[7]; 			// 최하위 바이트 /* PRQA S 0499 1 */ /* PRQA S 4394 1 */
					
					UART.Out.Device_DVP[Device].dwRxReportedPower = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].dwRxReportedPower |= (UART.Int.RxDataBuf[8] << 24u);	// 최상위 바이트
					UART.Out.Device_DVP[Device].dwRxReportedPower |= (UART.Int.RxDataBuf[9] << 16u);
					UART.Out.Device_DVP[Device].dwRxReportedPower |= (UART.Int.RxDataBuf[10] << 8u);
					UART.Out.Device_DVP[Device].dwRxReportedPower |= UART.Int.RxDataBuf[11];			// 최하위 바이트
					
					UART.Out.Device_DVP[Device].wRetryMeasuredQFactor = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].wRetryMeasuredQFactor |= (UART.Int.RxDataBuf[12] << 8u);	// 최상위 바이트
					UART.Out.Device_DVP[Device].wRetryMeasuredQFactor |= UART.Int.RxDataBuf[13];			// 최하위 바이트

					// = UART.Int.RxDataBuf[14];
					// = UART.Int.RxDataBuf[15];
					// = UART.Int.RxDataBuf[16];
					// = UART.Int.RxDataBuf[17];

					break;

				case cResponse_Data_Index3:
				case cResponse_Data_Index6:
					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index3)
					{
						Device = 0u;
					}

					if(UART.Int.RxDataBuf[1] == cResponse_Data_Index6)
					{
						Device = 1u;
					}

					UART.Out.Device_DVP[Device].wGuaranteedPowerHalfWatt = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].wGuaranteedPowerHalfWatt |= (UART.Int.RxDataBuf[2] << 8u);	// 최상위 바이트
					UART.Out.Device_DVP[Device].wGuaranteedPowerHalfWatt |= UART.Int.RxDataBuf[3];			// 최하위 바이트
					
					UART.Out.Device_DVP[Device].wMaximumPowerHalfWatt = 0; /* 0107_04 */
					UART.Out.Device_DVP[Device].wMaximumPowerHalfWatt |= (UART.Int.RxDataBuf[4] << 8u); 	// 최상위 바이트
					UART.Out.Device_DVP[Device].wMaximumPowerHalfWatt |= UART.Int.RxDataBuf[5];			// 최하위 바이트										
					
					UART.Out.Device_DVP[Device].byPowerPacketType = UART.Int.RxDataBuf[6];
					UART.Out.Device_DVP[Device].Qi_Ver = UART.Int.RxDataBuf[7];
					UART.Out.Device_DVP[Device].byQFactor = UART.Int.RxDataBuf[8];
					UART.Out.Device_DVP[Device].bPLCFlag = (UART.Int.RxDataBuf[9] & 0x01u);
					UART.Int.SecureFlag = (UART.Int.RxDataBuf[9] & 0x02u) >> 1u;
					UART.Out.AutoCalibrated = (UART.Int.RxDataBuf[9] & 0x04u) >> 2u; /* 0108_02 */					
					UART.Out.Device_DVP[Device].ChargingRate = UART.Int.RxDataBuf[10];
					UART.Out.Device_DVP[Device].AutoCalibErr = UART.Int.RxDataBuf[11]; /* 010E_03 */

					// AutoCalibErr flag
					// #define WCT_CALIB_ERR_NONE        (0x00U)
					// #define WCT_CALIB_ERR_RAIL_MIN    (0x01U)
					// #define WCT_CALIB_ERR_RAIL_MAX    (0x02U)
					// #define WCT_CALIB_ERR_QF          (0x04U)
					// #define WCT_CALIB_ERR_RES_F       (0x08U)
					// #define WCT_CALIB_BOARD_ISSUE     (0x10U)					


					// = UART.Int.RxDataBuf[12];
					// = UART.Int.RxDataBuf[13];
					// = UART.Int.RxDataBuf[14];
					// = UART.Int.RxDataBuf[15];
					// = UART.Int.RxDataBuf[16];
					// = UART.Int.RxDataBuf[17];

					break;

					default:
					// M3CM Rule-16.4
					break;
			}
		}
		else
		{
			ss_UART_Scb_Init(); /* 010A_11 */ // uart 레지스터 초기화
		}

		//gs_ClearData(UART.Int.RxDataBuf, cResponse_Data_Size); // buf clear
		memset(UART.Int.RxDataBuf, 0, sizeof(UART.Int.RxDataBuf)); // 표준 라이브러리 함수로 변경
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		더하기 후 하위 1byte
***************************************************************************************************/
static uint8_t ss_CheckSum(uint8_t const *Buf, uint8_t size)
{
	uint16_t CheckSum;
	uint8_t i;

	CheckSum = 0u;
	for(i = 0; i<(size - 1u); i++)
	{
		CheckSum += Buf[i];
	}

	return (uint8_t)(CheckSum & 0x00FFu);
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_DeviceStatusJudge(uint8_t Device)
{

	// 휴대폰 검출 여부는 TxStatus 값과 RxStatus 를 조합하여 판단하기로 한다.
	// 왜냐하면 충전 IC로 부터 TxStatus 가 단계별로 바뀌는데
	// 바뀔수 있는 이유는 RX(휴대폰)으로 부터 응답이 오기 때문이다.
	// 휴대폰이 올려져 있어야만 통신이 이루어지고
	// TxStatus가 다음단계로 이동하기 때문이다.


	// 충전 단계별 시컨스 정리

	// 1. 대기 단계 (패드위에 휴대폰 없음)
	// - TxStatus = WCT_TX_STS_OBJECT_DETECTION , WCT_TX_STS_COIL_SELECTION 번갈아 가면서 반복함.
	// - RxStatus = WCT_RX_STS_NONE

	// 2. 충전 준비 단계 (패드위에 휴대폰 거치)
	// - step1 : TxStatus = WCT_TX_STS_DIGITAL_PING
	// - step2 : TxStatus = WCT_TX_STS_IDENTIFICATION
	// - step3 : TxStatus = WCT_TX_STS_NEGOTIATION (디지털 핑에 의해서 휴대폰임을 식별 후 협상 이 단계까지 오면 패드위의 물체는 휴대폰임으로 판단하자. )
	// - step4 : TxStatus = WCT_TX_STS_CALIBRATION
	// - RxStatus = WCT_RX_STS_PREPARE_CHARGE

	// 3. 충전 시작 단계 (실제 전력 전송됨)
	// - step5 : TxStatus = WCT_TX_STS_POWER_TRANSFER
	// - RxStatus = WCT_RX_STS_CHARGING

	// 4. 충전 완료 단계(미세하게 전력이 전송됨)
	// - TxStatus = WCT_TX_STS_POWER_TRANSFER
	// - RxStatus = WCT_RX_STS_CHARGED


	// 충전 IC와 핸드폰 간에 송수신하는 TxStatus와 RxStatus를 조합하여
	// 모델 및 어플리케이션에서 사용하는 신호를 생성하기로 함.

	//for(uint8_t Device = 0; Device < Device_MAX; Device++)
	{
		if((UART.Out.Device_WCT[Device].TxChargingErrors == (uint8_t)WCT_TX_ERR_PRE_FOD) ||		// 충전 진입 초기화시 FOD 발생. Q-Factor로 확인
		(UART.Out.Device_WCT[Device].TxChargingErrors == (uint8_t)WCT_TX_ERR_FOD) ||			// 충전중 FOD 발생. Power Lowss 로 확인
		(UART.Out.Device_WCT[Device].TxChargingErrors == (uint8_t)WCT_TX_ERR_QFOD)) 			// 협상 단계에서 FOD 발생. EPP로 확인.
		{
			UART.Out.Device_WCT[Device].DeviceState = cFODError;
		}
		else if(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_PREPARE_CHARGE)
		{
			if((UART.Out.Device_WCT[Device].TxChargingStatus == (uint8_t)WCT_TX_STS_CALIBRATION) || // 준비 단계에서 핸드폰임이 식별되고 캘단계부터 LED 점등하도록함.
			(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_TX_STS_POWER_TRANSFER))
			{
				UART.Out.Device_WCT[Device].DeviceState = cCharging;
			}
			else
			{
				UART.Out.Device_WCT[Device].DeviceState = cPrepareCharging;
			}
		}


		else if((UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_CHARGING) ||		// 충전 중
		(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_LIMITED_CHARGING))	// 제한 적인 충전 상태
		{
			if(UART.Out.Device_WCT[Device].CS100 == ON)	// Charge State == 100이면 충전 완료
			{
				UART.Out.Device_WCT[Device].DeviceState = cFull_Charge;
			}
			else
			{
				UART.Out.Device_WCT[Device].DeviceState = cCharging;
			}
		}
		else if(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_CHARGED)	// 충전 완료
		{
			UART.Out.Device_WCT[Device].DeviceState = cFull_Charge;
		}
		else if((UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_UNDEFINE)	|| // 무선 충전 안되는 폰이 거치 중. 정의 안된 상태. Recharge Rerty full 충전으로 5분후 재시도 중
		(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_NONE))	// 핸드폰 감지 안될때, 아날로그 핑 쏠때
		{
			UART.Out.Device_WCT[Device].DeviceState = cStandby;
		}
		else if(UART.Out.Device_WCT[Device].RxChargingStatus == (uint8_t)WCT_RX_STS_FAULT)		// 에러 발생시 모델 state를 초기모드로 이동시킨다. (그리고 충전 Retry 시도하도록 하자.)
		{
			UART.Out.Device_WCT[Device].DeviceState = cInit;		// 에러 발생시 init으로 처리하는것이 타당한지 검토 필요함.
		}
		else
		{
			UART.Out.Device_WCT[Device].DeviceState = cStandby;	// 강건화 처리. 위조건 모두 불만족시 standby로 설정
		}
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_ActiveCoilIDJudge(uint8_t Device) // WPC_462_02
{
// 2023.09.25
// 로직을 변경하는 이유는 IG ON 상태에서 패드위에 폰을 올려놓지 않은 상태에서
// coil id를 진단으로 읽으면 0이 read되는 문제가 발생하여 로직 검토 한 결과 아래처럼 변경하기로 함.
// 충전 IC에서 coil id가 항상 0으로 수신되기 때문에 이와 같은 문제가 발생함.
// 그래서 충전 IC에서 오는 신호를 사용해봐야 의미가 없으므로
// Uart 수신쪽에서 어플리케이션의 제어 정보를 이용하여
// 코일 id를 임으로 생성하여 출력되도록 변경함.
// not active : 0
// active : 1

// 사양서
// ActiveCoilID 관련 케이스별 출력 조건
// 1. FOD 에러 : Error 발생이전 충전 중이던 Coil ID 표출 --> Uds.WPCWarning == Charging_error,Uds.Inp_UART_WCT1.DeviceState == cFODError 일때
// 2. 고온 에러 : '0' 표출 --> Uds.WPCWarning == Charging_error  면 만족함
// 3. 과전류 에러 : '0' 표출 --> Uds.WPCWarning == Charging_error 면 만족함
// 4. 온도센서 에러 : '0' 표출  --> Uds.WPCWarning == Charging_error 면 만족함
// 5. IGN On --> Off 에 따른 미충전상태 : 핑 출력중인 Coil ID 표출 --> Uds.WPCWarning == Cellphoneonthepad 일때
// 6. LF 서칭에 따른 미충전 상태 : '0' 표출 --> Uds.WPCWarning == WPCWarningOff // WPC_462_02 : Inp_Model_WCT[D0].WPC1_WPC1Status == WPC도 and로 추가해야함

	//for(uint8_t Device = 0; Device < Device_MAX; Device++)
	{
		if(UART.Inp_WCT.Device[Device].WCT_Status == (uint8_t)cWCT_Enable)
		{
			if(UART.Inp_Model.Device[Device].WPCWarning == Charging_error) // fod error, 고온에러, 과전류에러, 온도센서에러 모두 charging_error로 임.
			{
				// 아래 로직은 확인해 보니 정상 동작하지 않음. Charging_error 일때 cFODError 가 아닌 경우도 있음. cStandby 상태가 생기기도 함.
				// 아래 응답값은 실제 사용되지 않으므로 일단 현상 유지함.
				if(UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cFODError) // fod error
				{
					UART.Out.Device_WCT[Device].ActiveCoilID = UART.Int.ActiveCoilID_Old[Device];	// 이전 정상 충전중일때 coil id 송신
				}
				else // 고온에러, 과전류에러, 온도센서에러
				{
					UART.Out.Device_WCT[Device].ActiveCoilID = 0;	// 에러 상태일때 0표출
				}
			}
			else
			{
				if((UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cStandby) ||
				(UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cPrepareCharging) || // prepareCharging도 charing으로 Led 점등 되도록 변경
				(UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cCharging) ||
				(UART.Out.Device_WCT[Device].DeviceState == (uint8_t)cFull_Charge))
				{
					UART.Out.Device_WCT[Device].ActiveCoilID = 1u; // coil id 1번 설정

					UART.Int.ActiveCoilID_Old[Device] = UART.Out.Device_WCT[Device].ActiveCoilID;	// 정상 충전 중일때만 old value 복사.
					// +1하는 이유는 3코일때는 1번2번3번으로 표시한듯한데 지금은 코일이 1개여서 무조건 0만 수신된다.
					// 그래서 강제로 어플리케이션에서 구분하여 미충전일때0으로 충전 중일때 1로 변경하여 표시 하기 위함이다.
				}
				else
				{
					UART.Out.Device_WCT[Device].ActiveCoilID = 0;	// 미충전 중일때 0으로 표시
				}
			}
		}
		else if(UART.Inp_WCT.Device[Device].WCT_Status == (uint8_t)cWCT_Phone_Left)
		{
			UART.Out.Device_WCT[Device].ActiveCoilID = 1u; // coil id 1번 설정
		}
		else	// stop, reprogram, disable, diag
		{
			UART.Out.Device_WCT[Device].ActiveCoilID = 0;	// 에러 상태일때 0표출
		}
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
// 전송 주기를 어떻게 해야하나? hi pe에서는 5ms task에서 1byte씩 전송해서 총 20ms 걸렸음. 20ms 주기였음.
// 19200bps 로 계산해 보면
// start bit(1bit) + data (8bit) + end bit (1bit) = 10bit (1byte 전송시)
// 4byte --> 40 bit , 40 / 19200 = 0.002 ( 약 2ms 소요)
// 17byte --> 170 bit , 170 / 19200 = 0.009 ( 약 9ms 소요)
// 10byte --> 100 bit , 100 / 19200 = 0.0052( 약 5.2ms 소요)

// 5w 전송시에는 전송하고 전송이 완료 될때까지 while문으로 대기하고 있었음.
// 그래서 전송시 부하가 커서 5ms 주기당 1byte씩 전송한듯함.
// 전송시에도 인터럽트 방식으로 전송하면 부하에 문제되지 않을듯함.
// 그리고 샘플 코드에서도 while문으로 전송 완료 여부를 먼저 확인하고 그 다음에 보내므로
// 대기시간이 길지 않을 것으로 생각됨.
// 현재 SWP로 4byte / 17byte 전송시 몇 ms 걸리는지 확인해보자. (포트 시간 재는걸로)
// 계산상 시간은 2ms (4byte 전송시 파형의 길이).
// 실제  tx함수 호출하고  2ms 동안 점유하고 있는지 아니면 그냥 버퍼에 넣기만 하면
// uart 전송은 하드웨어에서 알아서 하는것인지 확인이 필요함.

static void ss_UART_Transmit(void)
{
	
	// single 시 강제로 비활성화 값 set
	if(UART.Inp_NvM.WPC_TYPE == cWPC_TYPE4) /* only single */
	{
		UART.Int.UartTxCmdOld[D1] = cChargeStop;
		UART.Inp_WCT.Device[D1].UartTxCmd = cChargeStop;
	}

	if((UART.Int.UartTxCmdOld[D0] != UART.Inp_WCT.Device[D0].UartTxCmd) ||  // Cmd 값 변경 있을 경우에는 즉시 전송
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	(UART.Int.UartTxCmdOld[D1] != UART.Inp_WCT.Device[D1].UartTxCmd) ||
//#endif
	(UART.Int.DvpStartOld != UART.Inp_Uds.DiagDvp1Start)  ||
	(UART.Int.WctUartCommReady_Evt.On_Event == ON))	// WCT ic 전원 인가후 WctUartCommReady on 수신시 즉시 송신하기 위해서
	{
		UART.Int.NormalTxCnt = 0;
		UART.Int.UartTxCmdOld[D0] = UART.Inp_WCT.Device[D0].UartTxCmd;
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
		UART.Int.UartTxCmdOld[D1] = UART.Inp_WCT.Device[D1].UartTxCmd;
//#endif
		UART.Int.DvpStartOld = UART.Inp_Uds.DiagDvp1Start;
	}

	// 연속 송신으로 변경
	if((UART.Int.NormalTxCnt == 0u) &&
	   (UART.Out.WctUartCommReady == ON))	// wct ic로 부터 최초 통신 수신한 다음부터 tx 송신
	{
		UART.Int.TxDataBuf[0] = cHeader_Request;
		UART.Int.TxDataBuf[1] = cRequest_Cmd_Index0;
		// dvp는 devcie0,1로 구분하는걸로 되어있으나 실제 사용은 동시에 on/off한다.

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
		UART.Int.TxDataBuf[2] = (UART.Inp_WCT.Device[D0].UartTxCmd << 5u) |  (UART.Inp_Uds.DiagDvp1Start << 4u) | ( UART.Inp_WCT.Device[D1].UartTxCmd << 1u) | UART.Inp_Uds.DiagDvp1Start;
//#else
//		UART.Int.TxDataBuf[2] = (UART.Inp_WCT.Device[D0].UartTxCmd << 5u) |  (UART.Inp_Uds.DiagDvp1Start << 4u);
//#endif
		UART.Int.TxDataBuf[3] = UART.Int.TxDataBuf[0] + UART.Int.TxDataBuf[1] + UART.Int.TxDataBuf[2];

		//gs_Scb_UART_PutArray(UART.Int.TxDataBuf, cRequest_Cmd_Size);
		Cy_SCB_UART_Transmit(SCB6, UART.Int.TxDataBuf, cRequest_Cmd_Size, &g_stc_uart_normal_context);
	}

	UART.Int.NormalTxCnt ++;
	if(UART.Int.NormalTxCnt >= Par_TransmitIntervalTime)
	{
		UART.Int.NormalTxCnt = 0;
	}

	// 중복 이므로 삭제
	// if(UART.Int.WctUartCommReady_Evt.On_Event == ON)	// 충전 IC 전원 인가시 버전 정보 수신 후 100ms 후가 아닌 10ms 후 즉시 커맨드 전송하도록 수정
	// {
	// 	UART.Int.NormalTxCnt = 0; // 1회만 사용됨
	// }
		
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_BufferClear(void) /* 010C_07 */
{
	memset(g_uart_normal_in_data, 0, sizeof(g_uart_normal_in_data)); 
	memset(UART.Int.RxDataBuf, 0, sizeof(UART.Int.RxDataBuf)); 
	memset(&UART.Out.Device_DVP, 0, sizeof(UART.Out.Device_DVP));
	memset(&UART.Out.Device_WCT, 0, sizeof(UART.Out.Device_WCT));
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       1byte 수신시 마다 인터럽트 발생  (SCB6 사용, interrupt 94), Normal 전용
***************************************************************************************************/
void ISR_Scb_Isr_Vector_94_Cat2(void)
{
#if defined(E_UART_NORMAL_ECHO_INTR_1BYTE)
    /* UART Echo Test (High-Level)            */
    /* (2) Interrupt & Receive by 1 byte unit */
    uint32_t num_normal = Cy_SCB_UART_GetNumInRxFifo(SCB6);
    if (num_normal != 0) {
        Cy_SCB_UART_Receive(SCB6, &g_uart_normal_in_data[0], num_normal, &g_stc_uart_normal_context); // 수신할 데이터의 버퍼와 크기를 설정하는 함수
        //Cy_SCB_UART_Transmit(SCB6, &g_uart_normal_in_data[0], num_normal, &g_stc_uart_normal_context);// 송신할 데이터의 버퍼와 크기를 설정하는 함수
        Cy_SCB_SetRxFifoLevel(SCB6, 0);
		UART.Int.WctUartInterruptRecvIndication = ON;
    }
#endif

    /* UART interrupt handler */
    Cy_SCB_UART_Interrupt(SCB6, &g_stc_uart_normal_context); // 송신 및 수신 하기 위한 버퍼에 복사하는 함수

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_UART_Scb_Event(unsigned long locEvents)	// QAC 0572 방지 unsigned long으로 선언함
{
	switch (locEvents) {

	case CY_SCB_UART_TRANSMIT_IN_FIFO_EVENT:
		break;

	case CY_SCB_UART_TRANSMIT_DONE_EVENT:
		break;

	case CY_SCB_UART_RECEIVE_DONE_EVENT:	// 수신 바이트 수 지정시 사용.
#if defined(E_UART_NORMAL_ECHO_INTR_THRESHOLD)
            /* UART Test (High-Level)                                                 */
            /* (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */

            Cy_SCB_UART_Receive(SCB6, &g_uart_normal_in_data[0], E_UART_NORMAL_RECV_THRESHOLD, &g_stc_uart_normal_context);

			UART.Int.WctUartInterruptRecvIndication = ON;

#endif
			/* Re-Enable Interrupt */
			Cy_SCB_SetRxInterruptMask(SCB6, g_stc_uart_normal_config.rxFifoIntEnableMask);

		break;

	case CY_SCB_UART_RB_FULL_EVENT:
		break;

	case CY_SCB_UART_RECEIVE_ERR_EVENT: /* Get RX error events: a frame error, parity error, and overflow */
		// 에러가 발생하면 데이터 parsing 에러가 발생하고 이로 인해서 리셋 발생함
		ss_UART_Scb_Init(); /* 010A_11 */ // uart 레지스터 초기화 
		break;

	case CY_SCB_UART_TRANSMIT_ERR_EVENT:
		ss_UART_Scb_Init(); /* 010A_11 */ // uart 레지스터 초기화

		break;


	default:
	// M3CM Rule-16.4
		break;
    }
}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_UART_Scb_Init(void)
{
	//ss_UART_Scb_DeInit();

	ss_UART_BufferClear(); /* 010C_07 */ // 버퍼 초기화
	
	Cy_SCB_UART_DeInit(SCB6);	//-> uart 레지스터 초기화
	Cy_SCB_UART_Init(SCB6, &g_stc_uart_normal_config, &g_stc_uart_normal_context); //-> uart 레지스터 초기화
	Cy_SCB_UART_RegisterCallback(SCB6, ss_UART_Scb_Event, &g_stc_uart_normal_context);
#if defined(E_UART_NORMAL_ECHO_INTR_RINGBUF)
    Cy_SCB_UART_StartRingBuffer(SCB6, (void *)g_uart_normal_rx_ring, E_UART_NORMAL_RING_BUF_SIZE, &g_stc_uart_normal_context);
#endif
	Cy_SCB_UART_Enable(SCB6); // uart 인터럽트 enable 레지스터 set

#if defined(E_UART_NORMAL_ECHO_INTR_THRESHOLD)
    /* UART Echo Test (High-Level)                                            */
    /* (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */

    Cy_SCB_UART_Receive(SCB6, g_uart_normal_in_data, E_UART_NORMAL_RECV_THRESHOLD, &g_stc_uart_normal_context);

#endif
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_UART_Scb_DeInit(void)
{
	Cy_SCB_UART_Disable(SCB6, &g_stc_uart_normal_context); //-> uart  Disable
	Cy_SCB_UART_DeInit(SCB6);	//-> uart 레지스터 초기화
}

/* 0108_03 */
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_UART_L2H_Set(void)
{
	UART.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_UART_H2L_Set(void)
{


}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_UART_LPConditionCheck(void)
{
	if(UART.Int.StateCurr != cUART_Disable)
	{
		UART.Out.UART_LPConditionFlag = OFF;	// Active
	}
	else
	{
		UART.Out.UART_LPConditionFlag = ON;	// Sleep
	}
}

#define App_UART_STOP_SEC_CODE
#include "App_UART_MemMap.h"
