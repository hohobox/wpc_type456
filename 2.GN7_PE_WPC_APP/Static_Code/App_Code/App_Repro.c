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
#include "App_Repro.h"
#include "Rte_App_Repro.h"

#include "App_UART.h"
#include "App_NvM.h"
#include "Rte_NvM_Type.h"

#include "FlashImage_TYPE5.h"	// wct srecord image --> string convert file
#include "FlashImage_TYPE6.h"	// wct srecord image --> string convert file

#include "cy_syslib.h"
#include "cy_scb_common.h"
#include "cy_scb_uart.h"


#define RTE_ALLOW_CROSS_HEADER_INCLUSION  // 미선언시 컴파일 오류 발생함.
#include "Rte_App_WCT.h" 	// Rte_Call_R_VCC33_CTRL_WriteDirect(OFF); 사용하기 위해서 인크루드함.


#define App_Repro_START_SEC_CODE
#include "App_Repro_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

// 5ms Taks 및 baurd 115200 변경으로 리프로시간 단축됨 약 20초
#define PARSING_CNT_PER_TASK	2u	
#define cPingRetryCnt			5u
#define WCT_REPRO_RETRY_CNT		6u // 부트시 ping 에러도 1회로 간주되므로 횟수를 좀더 늘린다. (ping에러는 자주 발생할수 있음)

#define cPingResponseWaitTimeout	(100u 	/ TIME_5MS) // 500ms --> 100ms 로 변경함. retry 간격이 너무 길었음. repro 대기 시간이 500ms 로 변경되었으므로 리트라이 간격을 짧게하여 5회정도는 리트라이 가능하게 수정함.
#define cReproRxWaitTimeout			(5000u 	/ TIME_5MS)
#define cCalibrationWaitTimeout 	(6000u 	/ TIME_5MS) // 각 채널당 3초씩 6초로 설정함.
#define cReproPowerResetWaitTime 	(250u 	/ TIME_5MS) // wct 전원 Off 유지 시간
#define cNvMPendingTimeout			(200u 	/ TIME_5MS)
#define Par_VerReadTimeoutTime		(5000u 	/ TIME_10MS) 

// Image buffer size도 2048의 배수로 선언되어야 한다. 그렇지 않으면 Alignment Error 가 발생한다.
// for WCT2013A, WCT22C3A : 듀얼의 경우 150KB, single의 경우 100KB
#define EraseAlignment			2048u		// Sector Size 2048Kb  // erase 블럭 최소 단위
#define IMAGE_BUFFER_SIZE 		EraseAlignment * (150u / 2u)  // MCU Ram 사용량 고려하여 할당할것. (100K로 할당함. 약 70% 사용), 100KB면 한블럭으로 가능함
//#define IMAGE_BUFFER_SIZE 		EraseAlignment * (50u / 2u) // MCU Ram 사용량 고려하여 할당할것. (50K로 할당함. 약 50% 사용), 블럭이 나누어 지므로 진행율이 99%까지 갔다가 다시 1%에서 시작해서 100%된다.

// for WCT20D2A : 
//#define EraseAlignment			1024u		// Sector Size 1024kb. // erase 블럭 최소 단위
//#define IMAGE_BUFFER_SIZE 		EraseAlignment * (100u / 1u)  // WCT20D2A // CYT Ram 사용량 고려하여 할당할것. (100K로 할당함. 약 70% 사용), 100KB면 한블럭으로 가능함


#define START_ADDRESS 			0x00000000
#define APP_ADDRESS				0x00000800	// WCT2013의 어드레스 map과 일치시켜야함. erase 단위 2048의 배수여야함.
#define NvM_ADDRESS				0x0003F800

#define ONE_LINE_BUF_SIZE 		263

#define cPing_PacketSize	10u
#define cFraming_HeaderSize	6u		// 6u:start byte(1), packet(1), length(2), crc16(2)

#define cReproRxDataMaxSize 		38u	// repro 최대 수신 데이터 수 // Header(6byte) + data (32byte)



/* Select UART Echo Type                                                   */
/*                                                                         */
/* Use Low-Level API                                                       */
/*  (1) Polling & Receive by 1 byte unit                                   */
/* Use High-Level API                                                      */
/*  (2) Interrupt & Receive by 1 byte unit                                 */
/*  (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */
/*  (4) Interrupt & Receive using Ring Buffer (Half of RX FIFO size)       */
//#define E_UART_REPRO_ECHO_POLLING_1BYTE
//#define E_UART_REPRO_ECHO_INTR_1BYTE
#define E_UART_REPRO_ECHO_INTR_THRESHOLD
//#define E_UART_REPRO_ECHO_INTR_RINGBUF

/* Local Definision */
#define E_UART_REPRO_RECV_THRESHOLD  	1
#define E_UART_REPRO_RING_BUF_SIZE     512
#define E_UART_REPRO_USER_BUF_SIZE     512
#define E_UART_REPRO_RX_INTR_FACTER     (                              \
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
#define E_UART_REPRO_TX_INTR_FACTER     (                              \
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
    cPing_Command,
    cPing_Response,
    cParsingSrecord,
	cFlashEraseAllUnsecure_Command,
    cFlashEraseRegion_Command,
    cFlashEraseAll_Command,
    cEraseAllUnsecure_Command,
    cWriteMemory_Command,
    cWriteMemory_Data,
	cExecute_Command,
    cAck_Response,
    cGeneric_Response,
    cReproFlash_Calibration,
	cReproFlash_VersionVerify,
	cReproFlash_NvMPending,	
	cReproFlash_Completed,
    cReproFlash_Fail,
}_ReproStatus_t;

typedef enum
{
	cERR_Error_None,
	cERR_Ping_Response_CRC,
	cERR_Ping_Response_Timeout,
	cERR_Ack_Response_NAK,
	cERR_Ack_Response_Aboart,
	cERR_Ack_Response_Timeout,
	cERR_Generic_Response_Status,
	cERR_Generic_Response_CRC,
	cERR_Generic_Response_Timeout,
	cERR_Generic_Response_SecurityViolation,
	cERR_VersionVerify_Unmatch,
	cERR_VersionVerify_Timeout,
	cERR_NvMWrite_Timeout,
	cERR_Calibration_Timeout,
	cERR_LineParsing_SrecordInvalidLen,
	cERR_LineParsing_StartChar,
	cERR_LineParsing_RecordType,
	cERR_LineParsing_LineInvalidLen,
	cERR_LineParsing_CRC,


}_ReproStatus_Err_t;

typedef enum
{
    kRecordStatus_Success,
    kRecordStatus_Fail,
    kRecordStatus_InvalidLength,
    kRecordStatus_InvalidStart,
    kRecordStatus_InvalidType,
    kRecordStatus_InvalidChecksum,
    kRecordStatus_FlashOver,
    kRecordStatus_FlashPartly,
    kRecordStatus_EraseOver,
    kRecordStatus_ErasePartly,
	kRecordStatus_AddressSkip,
}_recordStatus_t;

// typedef enum
// {
// 	//Tim_PowerResetWait,
// 	Tim_REPRO_MAX
// }REPRO_TMR_ENUM_t;


typedef struct
{
	uint8_t Runnable_State;
	uint8_t App_Init_Completed;
	uint8_t StateCurr;		// Current State
	uint8_t StateNext;		// Next State
	uint8_t StateOld;		// Old State
	uint8_t EntryCnt;		// Entry Count
	uint8_t ExitCnt;		// Exit Count

	uint8_t ReproPercentOld;
	uint8_t RxIntDataBuf[cReproRxDataMaxSize];

	uint8_t WctVerCheck_State;

	Event_t Repro_Start_Evt;

	uint8_t WctUartInterruptRecvIndication;

	uint8_t UartRxState;
	uint8_t UartRxDataCnt;
	uint8_t UartRxDataLen;

	uint8_t ReproIntRecvCompleted;
	uint16_t CommandOrData_PacketSize; // Command or g_uart_repro_in_data[0] packet Size

	uint8_t ReproRetryCnt;
	Repro_ENUM_t ReproRequest;
	uint8_t SecurityViolation; // 리트라이시에 초기화되면 안됨.
	uint16_t WctVerReadCnt;
}Inter_t;


typedef struct
{
	srecord_t new_record;
	uint8_t image_buffer[IMAGE_BUFFER_SIZE]; // image max size 200Kbyte
	uint32_t image_buffer_index;
	uint32_t image_start_address;
	uint32_t image_next_address;

	uint32_t image_size;
	uint8_t EraseCompleted;

    uint32_t WriteData_Index;

    uint16_t Line_Arry_Index;

    uint32_t data_packet_num;
    uint32_t erase_bytes;

	uint16_t ErrWaitCnt;

	serial_framing_packet_t framingPacket;

	ping_response_frame_packet_t PingRespData;

	uint8_t loop_flag;
	uint8_t loop_cnt;

	_ReproStatus_Err_t ReproErrCode;
	_ReproStatus_t Repro_OperState;
	_ReproStatus_t Repro_OperState_Old;

	uint16_t PingRetryCnt;

//  MX5 모듈에서 글로벌 변수
	uint8_t RxResponseAck;
	uint8_t RxResponseAckAbort;
	uint8_t RxResponseNak;
	uint8_t RxResponsePing;
	uint8_t RxResponseGeneric;

	uint8_t RxDataBuf[cReproRxDataMaxSize];
	FLASH_State ReproFlashStatus;
//  MX5 모듈에서 글로벌 변수
}Flash_t;

typedef struct
{
	IDT_ADC_STR 		Inp_ADC;
	IDT_WCT_STR			Inp_WCT;
	IDT_UART_STR 		Inp_UART;
	IDT_Uds_STR 		Inp_Uds;
	IDT_NvM_STR 		Inp_NvM;

	//Timer_t 			Timer[Tim_REPRO_MAX];
	Inter_t 			Int;
	Flash_t				Fls;

	IDT_Repro_STR 		Out;
} Repro_Var_t;

static Repro_Var_t Repro = {0};



/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

// Reprogram : 115200
// Normal    : 57600 --> 115200
static cy_stc_scb_uart_context_t   g_stc_uart_repro_context;
static cy_stc_scb_uart_config_t    g_stc_uart_repro_config = {
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
												   .rxFifoIntEnableMask        = E_UART_REPRO_RX_INTR_FACTER,
												   .txFifoTriggerLevel         = 0,
												   .txFifoIntEnableMask        = E_UART_REPRO_TX_INTR_FACTER
												};
/* Local Variables */
// Interrupt 적용시 사용
//static uint8_t g_uart_out_data[128] = {0};                       // TX Buffer for Terminal Print
static uint8_t g_uart_repro_in_data[128] = {0};                        // RX Buffer

// ring buffer 적용시 사용
#if defined(E_UART_REPRO_ECHO_INTR_RINGBUF)
static uint8_t g_uart_repro_rx_ring[E_UART_REPRO_RING_BUF_SIZE] = {0}; // RX Ring Buffer
static uint8_t g_uart_repro_user_buf[E_UART_REPRO_USER_BUF_SIZE] = {0};      // User Buffer for coping from Ring Buffer
#endif
//static uint8_t num_repro;



/***************************************************************************************************
    GLOBAL VARIABLES AND CONSTANTS
***************************************************************************************************/

/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/

static void ss_Repro_StateMachine(uint8_t CurrState, uint8_t action);
static void ss_Repro_Disable(uint8_t action);
static void ss_Repro_Enable(uint8_t action);

static void ss_Repro_Data_Init(void);
static void ss_Repro_InitSet(void);
static void ss_Repro_RteRead(void);
static void ss_Repro_RteWrite(void);
//static void ss_Repro_PowerResetWaitTimeCheck(void);
static void ss_Repro_LPConditionCheck(void);

static void ss_Repro_Flash_Init(void);
static void ss_Repro_Flash(void);
//static uint8_t read_flash_char(const char *srecord, uint32_t index);
static _recordStatus_t srecord_parse_line(uint8_t *line, uint16_t line_length);

static uint8_t bl_htoi(uint8_t hex);
static uint8_t read_hex_byte(uint8_t *buffer, uint32_t index);

//static void crc16_finalize(crc16_data_t *crc16Config, uint16_t *hash);
static void crc16_update(crc16_data_t *crc16Config, const uint8_t *src, uint32_t lengthInBytes);
static void crc16_init(crc16_data_t *crc16Config);

static void WriteMemory_Command_Send(void);
static void FlashEraseRegion_Command_Send(void);
static void Execute_Command_Send(void);
static void FlashEraseAllUnsecure_Command_Send(void);

static void ss_Scb_UART_Repro_Event(unsigned long locEvents);
//static void ss_UART_Repro_CommRead(void);
//static void Term_Repro_Input(void);
static void ss_UartReproISR(void);
static void ss_Scb_UART_Repro_Init(void);
static void ss_Scb_UART_Repro_DeInit(void);
static void ss_Uart_ReproIntRxClear(void);
static void ss_UartReproWrite(uint8_t *TxDataBuf, uint8_t length);
static void ss_Repro_WctTargetVerSet(void);
static void ss_Repro_WctReproRequestCheck(void);
static void ss_Repro_WctVerUnMatchCheck(void);
/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
@param[in]  void
@return     void
@note		5ms Task (리프로그래밍 속도 단축을 위해서 10ms  Task 보다 짧게 변경함.)
***************************************************************************************************/
FUNC(void, App_Repro_CODE) Repro_TE_Runnable(void)
{
	switch(Repro.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&Repro.Int.App_Init_Completed);

			if( Repro.Int.App_Init_Completed == ON ) 	/* SWP Init Complete? */
			{

				ss_Repro_InitSet(); 		/* SWC Init Process */

				Repro.Int.Runnable_State = 1u;

			}
		break;
		
		// /* 0108_01 */ 
		// case 1u: // 충전IC 버전 저장 완료시까지 1task (10ms) 보다는 더 오래 걸리므로 완료시까지 대기한다.
		// 	if(Repro.Inp_NvM.NvMBlk_Array_Complete[BLK_NO_ARR_WctSourceVer] == ON)
		// 	{
		// 		Repro.Int.Runnable_State = 2u;
		// 	}
			
		// break;
		
		// case 2u:	
		// 	Rte_Read_R_NvM_NvM_STR(&Repro.Inp_NvM); // ss_Repro_InitSet(); 에서 변경된 NvM값을 read한다.
			
		// 	ss_Repro_WctTargetVerSet(); /* 0108_01 */
			
		// 	ss_Repro_Disable(ENTRY);	// 전원 리셋시 Entry를 강제로 1회 실행시켜줘야함. // 초기화 함수가 호출됨.
			
		// 	Repro.Int.Runnable_State = 3u;
		// break;
		// /* 0108_01 */ 

		case 1u:
			//------------------------------------------------------
			// Input
			//------------------------------------------------------
						
			ss_Repro_RteRead();
#if defined(E_UART_REPRO_ECHO_POLLING_1BYTE) || defined(E_UART_REPRO_ECHO_INTR_RINGBUF)
			ss_UART_Repro_CommRead();
#endif
				
			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------
			ss_Repro_StateMachine(Repro.Int.StateCurr, DURING);

			// 상태 천이 발생시에만 실행
			if (Repro.Int.StateCurr != Repro.Int.StateNext)
			{
				ss_Repro_StateMachine(Repro.Int.StateCurr, EXIT);
				ss_Repro_StateMachine(Repro.Int.StateNext, ENTRY);

				// Repro.Int.StateOld = Repro.Int.StateCurr; // OldState 갱신 //이방식으로 하면 안됨.

				Repro.Int.StateCurr = Repro.Int.StateNext;
			}

			//------------------------------------------------------
			// Timer
			//------------------------------------------------------
			//gs_UpdateTimer(&Repro.Timer[0], Tim_REPRO_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.

			//-----------------------------------------------------
			// Output
			//------------------------------------------------------
			ss_Repro_WctTargetVerSet(); /* 0108_01 */					
															
			ss_Repro_RteWrite();

			ss_Repro_LPConditionCheck();
		break;

		default:
			Repro.Int.Runnable_State = 0u;
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       1byte 수신시 마다 인터럽트 발생  (SCB3 사용, interrupt 91), 리프로 전용
***************************************************************************************************/
void ISR_Scb_Isr_Vector_91_Cat2(void)
{
#if defined(E_UART_REPRO_ECHO_INTR_1BYTE)
    /* UART Echo Test (High-Level)            */
    /* (2) Interrupt & Receive by 1 byte unit */
    uint32_t num_repro = Cy_SCB_UART_GetNumInRxFifo(SCB3);
    if (num_repro != 0) {
        Cy_SCB_UART_Receive(SCB3, &g_uart_repro_in_data[0], num, &g_stc_uart_repro_context); // 수신할 데이터의 버퍼와 크기를 설정하는 함수
        //Cy_SCB_UART_Transmit(SCB6, &g_uart_repro_in_data[0], num, &g_stc_uart_repro_context);// 송신할 데이터의 버퍼와 크기를 설정하는 함수
        Cy_SCB_SetRxFifoLevel(SCB3, 0);
		Repro.Int.WctUartInterruptRecvIndication = ON;
    }
#endif

    /* UART interrupt handler */
    Cy_SCB_UART_Interrupt(SCB3, &g_stc_uart_repro_context); // 송신 및 수신 하기 위한 버퍼에 복사하는 함수

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Repro_InitSet(void)
{
	memset(&Repro.Out, 0, sizeof(Repro.Out));  				// 구조체 변수를 0으로 클리어

	Repro.Int.StateCurr = cRepro_Disable;
	Repro.Int.StateNext = cRepro_Disable;
	Repro.Int.StateOld = cRepro_Disable;
	Repro.Int.EntryCnt = 0u;
	Repro.Int.ExitCnt = 0u;
	
	Repro.Out.WctVerCheck = cVerCheck_Default;

	Rte_Read_R_NvM_NvM_STR(&Repro.Inp_NvM); // NvM 값을 먼저 읽어와야 함.
	// wct version은 모든 타입 공통으로 '0' (ascii)로 저장한다.
			
// 	memcpy(Repro.Out.m_WctSourceVer, Repro.Inp_NvM.m_WctSourceVer, WCT_VER_SIZE); // UDS에는 버전 사용하지 않음.
	
// /* 0108_01 */		
// 	if((Repro.Inp_NvM.m_WctSourceVer[0] == '0') &&	// default 저장값일 경우에 1회만 아래 로직 실행한다.
// 	(Repro.Inp_NvM.m_WctSourceVer[1] == '0') &&
// 	(Repro.Inp_NvM.m_WctSourceVer[2] == '0'))
// 	{	
		
// 		// WCT hex 라이팅 전 전원 인가시 WCT 리프로 자동 시도 방지용으로
// 		// 리프로그램될 타겟 버전을 소스 버전에 NvM에 저장하도록 하여 버전이 일치되므로 리프로 진행되지 않도록 함.
// 		// 품번에 따라 변경된 Type으로 NvM에 m_WCT_SwVer이 변경되어 저장되도록 요청함.
// 		// 최초로 cypress 라이팅시 m_WctSourceVer 는 '0' '0' '0' 이다.
// 		// 여기를 통과하면 충전 IC가 아직 라이팅되지 않아도 해당 품번에 맞는 소스 버전이 wct 타켓 버전으로 변경된다.
// 		// 그러므로 리프로그램이 최초에는 진행되지 않는다.
// 		// 그 이후 충전 IC가 동작하게 되면 다시 통신으로 수신한 소스버전이 nvm에 저장된다.
// 		if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE4)
// 		{
// 			Repro.Out.m_WctSourceVer[0] = cWCT_TARGET_VER1_TYPE4;
// 			Repro.Out.m_WctSourceVer[1] = cWCT_TARGET_VER2_TYPE4;
// 			Repro.Out.m_WctSourceVer[2] = cWCT_TARGET_VER3_TYPE4;
// 		}	
// 		else if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE5)
// 		{
// 			Repro.Out.m_WctSourceVer[0] = cWCT_TARGET_VER1_TYPE5;
// 			Repro.Out.m_WctSourceVer[1] = cWCT_TARGET_VER2_TYPE5;
// 			Repro.Out.m_WctSourceVer[2] = cWCT_TARGET_VER3_TYPE5;
// 		}			
// 		else if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE6)
// 		{
// 			Repro.Out.m_WctSourceVer[0] = cWCT_TARGET_VER1_TYPE6;
// 			Repro.Out.m_WctSourceVer[1] = cWCT_TARGET_VER2_TYPE6;
// 			Repro.Out.m_WctSourceVer[2] = cWCT_TARGET_VER3_TYPE6;	
				
// 		}	
// 		else
// 		{
// 			Repro.Out.m_WctSourceVer[0] = '0';
// 			Repro.Out.m_WctSourceVer[1] = '0';
// 			Repro.Out.m_WctSourceVer[2] = '0';
// 		}		
// 	}
	
	Repro.Out.m_WctReproRequest = Repro.Inp_NvM.m_WctReproRequest; /* 0108_13 */
	
/* 0108_01 */		
	Rte_Write_P_Repro_Repro_STR(&Repro.Out);	// 구조체로 한꺼번에 전송 // m_변수 값 즉시 전송하기 위해서 초기화시 호출함.

	// 위에서 버전 정보를 Type별로 변경하였으나 변경된 값이 NvM에 저장되려면 1Task가 필요하다.
	// 그러나 아래처럼 즉시 리프로를 위한 버전 비교를 하게 되면 아직 nvm에 저장이 된것이 아니기 때문에
	// 버전이 다르다고 판단되어 항상 리프로가 진행된다.
	// 그래서 1task 후에 아래 코드를 실행하도록 변경한다.
	// 변경은 runnable_state를 한단계 더 추가하여 10ms 후에 아래 코드 실행하도록 변경함.
	ss_Repro_Disable(ENTRY);	/* 0108_01 */ // 전원 리셋시 Entry를 강제로 1회 실행시켜줘야함. // 초기화 함수가 호출됨.

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Repro_Data_Init(void)
{
	Repro.Int.UartRxDataCnt = 0;
    Repro.Int.UartRxState = 0;
	Repro.Int.UartRxDataLen = 0;

	Repro.Int.ReproIntRecvCompleted = OFF;

	Repro.Int.ReproPercentOld = 0;
	Repro.Int.ReproRequest = cReproReq_Default;

	Repro.Out.ReproVersionVerifyReq = OFF; // normal 버전 수신 종료 처리함.

	//gs_InitTimer(&Repro.Timer[0], Tim_REPRO_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Repro_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_UART_UART_STR(&Repro.Inp_UART);
	Rte_Read_R_ADC_ADC_STR(&Repro.Inp_ADC);
	Rte_Read_R_WCT_WCT_STR(&Repro.Inp_WCT);
	Rte_Read_R_Uds_Uds_STR(&Repro.Inp_Uds);
	Rte_Read_R_NvM_NvM_STR(&Repro.Inp_NvM);

	gs_UpdateEvent(Repro.Inp_Uds.Repro_Start, &Repro.Int.Repro_Start_Evt);	// event update
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
#if defined(E_UART_REPRO_ECHO_POLLING_1BYTE) || defined(E_UART_REPRO_ECHO_INTR_RINGBUF)
static void ss_UART_Repro_CommRead(void)
{
#if defined(E_UART_REPRO_ECHO_POLLING_1BYTE)
        /* UART Echo Test (Low-Level)           */
        /* (1) Polling & Receive by 1 byte unit */
        Term_Repro_Input();
#endif

#if defined(E_UART_REPRO_ECHO_INTR_RINGBUF)
        /* UART Echo Test (High-Level)                                       */
        /* (4) Interrupt & Receive using Ring Buffer (Half of RX FIFO size)  */
        /*     -> Copy receive data to User Buffer from Ring Buffer and Echo */
        //uint32_t num_repro = Cy_SCB_UART_GetNumInRingBuffer(SCB6, &g_stc_uart_repro_context);
        num_repro = Cy_SCB_UART_GetNumInRingBuffer(SCB6, &g_stc_repro_normal_context);
		if (num_repro != 0) {
            Cy_SCB_UART_Receive(SCB3, &g_uart_repro_user_buf[0], num_repro, &g_stc_uart_repro_context);  // 수신할 데이터의 버퍼와 크기를 설정하는 함수
            //Cy_SCB_UART_Transmit(SCB3, &g_uart_repro_user_buf[0], num_repro, &g_stc_uart_repro_context); // 송신할 데이터의 버퍼와 크기를 설정하는 함수
			Repro.Int.WctUartInterruptRecvIndication = ON;
        }
#endif
}
#endif


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
#if defined(E_UART_REPRO_ECHO_POLLING_1BYTE)
static void Term_Repro_Input(void)
{
    uint32_t    rx_num;

    /* Check Receive g_uart_repro_in_data[0] */
    rx_num = Cy_SCB_UART_GetNumInRxFifo(SCB3);
    if (0u == rx_num) return;

    /* UART In/Out */
#if 0
    uint32_t    cmd;
    cmd = Cy_SCB_UART_Get(SCB3);
    while (0UL == Cy_SCB_UART_Put(SCB3, cmd)) {}
#endif
#if 1
    Cy_SCB_UART_GetArray(SCB3, g_uart_repro_in_data, rx_num);	// 이벤트 방식이 아닌 직접 receive 하는 방식
    Cy_SCB_UART_PutArray(SCB3, g_uart_repro_in_data, rx_num); // 이벤트 방식이 아닌 직접 transmit 하는 방식
#endif
#if 0
    Cy_SCB_UART_GetArrayBlocking(SCB3, g_uart_repro_in_data, rx_num);
    Cy_SCB_UART_PutArrayBlocking(SCB3, g_uart_repro_in_data, rx_num);
    Cy_SCB_UART_PutString(SCB3, (char_t *)g_uart_repro_in_data);
#endif
}
#endif

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Repro_RteWrite(void)
{
	Repro.Out.Repro_Status = Repro.Int.StateCurr;
	Repro.Out.ReproRequest = Repro.Int.ReproRequest;
	Repro.Out.ReproErrCode = Repro.Fls.ReproErrCode;
	Repro.Out.ReproFlashStatus = Repro.Fls.ReproFlashStatus;


	// 타 SWC에 RTE로 전달
	Rte_Write_P_Repro_Repro_STR(&Repro.Out);	// 한꺼번에 전송
}



/***************************************************************************************************
@param[in]  CurrState : Current State
@param[in]	Command : En, Do, Ex Condition
@return     void
@note       none
***************************************************************************************************/
static void ss_Repro_StateMachine(uint8_t CurrState, uint8_t action)
{
	switch (CurrState)
	{
		case cRepro_Disable:
			ss_Repro_Disable(action);
		break;

		case cRepro_Enable:
		 	ss_Repro_Enable(action);
		break;


		default:
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_Repro_Disable(uint8_t action)
{
	//static uint16_t IGN_ChatteringCnt = 0;

	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		ss_Repro_Data_Init();
		ss_Scb_UART_Repro_DeInit();

		//gs_StartTimer(&Repro.Timer[Tim_PowerResetWait]);


		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (Repro.Int.StateCurr == Repro.Int.StateNext)
		{
			// State's Transitions
			// if((Repro.Inp_ADC.BatSysStateFault == OFF) &&
			// (Repro.Int.ReproRequest == cReproReq_On))
			if(Repro.Inp_WCT.ReproUartStart == ON)
			{
				Repro.Int.StateNext = cRepro_Enable;
				Repro.Int.EntryCnt = 0u; // En 실행 : WCT_Enable
				Repro.Int.ExitCnt = 0u;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Repro_WctVerUnMatchCheck();
				
				ss_Repro_WctReproRequestCheck(); /* 010A_02 */
				
								
				//ss_Repro_PowerResetWaitTimeCheck();
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		//gs_CancelTimer(&Repro.Timer[Tim_PowerResetWait]);

		break;

	/********************************************************/
	default:
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_Repro_Enable(uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		// 상위 level State 없음

		// 2. 하위(자식) Level State en 실행

		ss_Scb_UART_Repro_Init();

		Repro.Int.ReproRetryCnt++;
		ss_Repro_Flash_Init();

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if(Repro.Int.StateCurr == Repro.Int.StateNext)
		{
			// State's Transitions
			if(Repro.Inp_WCT.ReproUartStart == OFF)
			{
				Repro.Int.StateNext = cRepro_Disable;
				Repro.Int.EntryCnt = 0u; // En 실행 : WCT_Disable
				Repro.Int.ExitCnt = 0u;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Repro_Flash();

			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행

		// 2. 상위(부모) Level State ex 실행
		// 상위 level State 없음


		break;

	//==============================================================
	default:
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Scb_UART_Repro_Event(unsigned long locEvents)	// QAC 0572 방지 unsigned long으로 선언함
{
	switch (locEvents) {

	case CY_SCB_UART_TRANSMIT_IN_FIFO_EVENT:
		break;

	case CY_SCB_UART_TRANSMIT_DONE_EVENT:
		break;

	case CY_SCB_UART_RECEIVE_DONE_EVENT:	// 수신 바이트 수 지정시 사용.
#if defined(E_UART_REPRO_ECHO_INTR_THRESHOLD)
            /* UART Test (High-Level)                                                 */
            /* (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */

            Cy_SCB_UART_Receive(SCB3, &g_uart_repro_in_data[0], E_UART_REPRO_RECV_THRESHOLD, &g_stc_uart_repro_context);

			ss_UartReproISR();

			Repro.Int.WctUartInterruptRecvIndication = ON;

#endif
			/* Re-Enable Interrupt */
			Cy_SCB_SetRxInterruptMask(SCB3, g_stc_uart_repro_config.rxFifoIntEnableMask);

		break;

	case CY_SCB_UART_RB_FULL_EVENT:
		break;

	case CY_SCB_UART_RECEIVE_ERR_EVENT: /* Get RX error events: a frame error, parity error, and overflow */
		// 에러가 발생하면 데이터 parsing 에러가 발생하고 이로 인해서 리셋 발생함
		break;

	case CY_SCB_UART_TRANSMIT_ERR_EVENT:

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
static void    ss_UartReproISR(void)
{
	//if(num_repro != 0u)
	{
		Repro.Int.RxIntDataBuf[Repro.Int.UartRxDataCnt] = g_uart_repro_in_data[0];  /* Save received char to the receive buffer */

		Repro.Int.UartRxDataCnt++;
		Repro.Int.ReproIntRecvCompleted = ON;

		// reprogram 일때만 호출된다.
    	switch( Repro.Int.UartRxState )
    	{
        	//-------------------------------------------------------
        	// 데이터의 시작을 알리는 Header를 판정하는 단계임.
        	//-------------------------------------------------------
        	case 0u:

				if(g_uart_repro_in_data[0] == kFramingPacketStartByte)				// 0x5A
				{
					Repro.Int.UartRxState = 1u;
				}

        	    break;

        	//-------------------------------------------------------
        	// 데이터 수신 Parsing
        	//-------------------------------------------------------
        	case 1u:

				if(g_uart_repro_in_data[0] == kFramingPacketType_Ack)					// 0xA1
				{
					Repro.Fls.RxResponseAck = ON;
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_Nak)			// 0xA2
				{
					Repro.Fls.RxResponseNak = ON;
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_AckAbort)		// 0xA3
				{
					Repro.Fls.RxResponseAckAbort = ON;
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_Command)		// 0xA4
				{
					Repro.Int.CommandOrData_PacketSize = 0;
					Repro.Int.UartRxState = 2;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_Data)			// 0xA5
				{
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_Ping)			// 0xA6
				{
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else if (g_uart_repro_in_data[0] == kFramingPacketType_PingResponse)	// 0xA7
				{
					Repro.Int.UartRxState = 3;
				}
				else
				{
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				break;

        	//-------------------------------------------------------
        	// Reprogram 데이터 수신 : kFramingPacketType_Command
        	//-------------------------------------------------------
        	case 2u:

				// byte 0 : start byte
				// byte 1 : packet type
				// byte 2 : length low
				// byte 3 : length high
				// byte 4 : crc16 low
				// byte 5 : crc16 high
				// byte 6 ~ n : command or data packet payload

				if(Repro.Int.UartRxDataCnt == 3u)// length 수신 완료, Repro.Int.RxIntDataBuf[2] : LSB Repro.Int.RxIntDataBuf[3] : MSB
				{
					Repro.Int.CommandOrData_PacketSize = (Repro.Int.RxIntDataBuf[2] + ((uint16_t)Repro.Int.RxIntDataBuf[3] << 8u));
				}
				else if(Repro.Int.UartRxDataCnt >= (Repro.Int.CommandOrData_PacketSize + cFraming_HeaderSize))
				{
					//gs_CopyData(Repro.Fls.RxDataBuf, Repro.Int.RxIntDataBuf, Repro.Int.CommandOrData_PacketSize + cFraming_HeaderSize);		// Repro.Int.RxIntDataBuf -->  Repro.IntRxDataBuf buf copy
					memcpy(Repro.Fls.RxDataBuf, Repro.Int.RxIntDataBuf, Repro.Int.CommandOrData_PacketSize + cFraming_HeaderSize); // 표준 라이브러리 함수로 변경
					memset(Repro.Int.RxIntDataBuf, 0, sizeof(Repro.Int.RxIntDataBuf)); // 표준 라이브러리 함수로 변경

					Repro.Fls.RxResponseGeneric = ON;			// 10ms Task에서 데이터 판정 및 로컬변수 복사 처리
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				else
				{
					// M3CM Rule-17.7
				}

				break;

        	//-------------------------------------------------------
        	// Reprogram 데이터 수신 : kFramingPacketType_PingResponse
        	//-------------------------------------------------------
        	case 3u:

				if(Repro.Int.UartRxDataCnt >= cPing_PacketSize )
				{
					//gs_CopyData(Repro.Fls.RxDataBuf, Repro.Int.RxIntDataBuf, cPing_PacketSize); // Repro.Int.RxIntDataBuf -->  Repro.Fls.RxDataBuf buf copy
					memcpy(Repro.Fls.RxDataBuf, Repro.Int.RxIntDataBuf, cPing_PacketSize); // 표준 라이브러리 함수로 변경
					memset(Repro.Int.RxIntDataBuf, 0, sizeof(Repro.Int.RxIntDataBuf)); // 표준 라이브러리 함수로 변경

					Repro.Fls.RxResponsePing = ON;							// 10ms Task에서 데이터 판정 및 로컬변수 복사 처리
					Repro.Int.UartRxDataCnt = 0;
					Repro.Int.UartRxState = 0;
				}
				break;

        	//-------------------------------------------------------
        	// Default 처리 단계
        	//-------------------------------------------------------
        	default:
				ss_Uart_ReproIntRxClear();
        	    break;
    	}

		if( Repro.Int.UartRxDataCnt > cReproRxDataMaxSize )		// 최대 수신 byte 초과
		{
			ss_Uart_ReproIntRxClear();
		}
	}
}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_Uart_ReproIntRxClear(void)
{
	Repro.Int.UartRxDataCnt = 0;                      // 카운터 초기화
    Repro.Int.UartRxState = 0;
	Repro.Int.UartRxDataLen = 0;
	Repro.Int.CommandOrData_PacketSize = 0;
	memset(Repro.Int.RxIntDataBuf, 0, sizeof(Repro.Int.RxIntDataBuf)); // 표준 라이브러리 함수로 변경
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_Scb_UART_Repro_Init(void)
{
	Cy_SCB_UART_DeInit(SCB3);	//-> uart 레지스터 초기화
	Cy_SCB_UART_Init(SCB3, &g_stc_uart_repro_config, &g_stc_uart_repro_context); //-> uart 레지스터 초기화
	Cy_SCB_UART_RegisterCallback(SCB3, ss_Scb_UART_Repro_Event, &g_stc_uart_repro_context);
#if defined(E_UART_REPRO_ECHO_INTR_RINGBUF)
    Cy_SCB_UART_StartRingBuffer(SCB3, (void *)g_uart_repro_rx_ring, E_UART_REPRO_RING_BUF_SIZE, &g_stc_uart_repro_context);
#endif
	Cy_SCB_UART_Enable(SCB3); // uart 인터럽트 enable 레지스터 set

#if defined(E_UART_REPRO_ECHO_INTR_THRESHOLD)
    /* UART Echo Test (High-Level)                                            */
    /* (3) Interrupt & Receive by threshold byte unit (E_UART_RECV_THRESHOLD) */

	Cy_SCB_UART_Receive(SCB3, g_uart_repro_in_data, E_UART_REPRO_RECV_THRESHOLD, &g_stc_uart_repro_context);

#endif
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_Scb_UART_Repro_DeInit(void)
{
	Cy_SCB_UART_Disable(SCB3, &g_stc_uart_repro_context); //-> uart  Disable
	Cy_SCB_UART_DeInit(SCB3);	//-> uart 레지스터 초기화
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Repro_Flash_Init(void)
{
	memset(&Repro.Fls, 0, sizeof(Repro.Fls));  				// 구조체 변수를 0으로 클리어
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Repro_Flash(void)
{
    crc16_data_t crc16_value;

	uint8_t Srecord_Char;
	_recordStatus_t Record_Status;
	uint16_t DataPacketLen;
	uint8_t CommandTag;
	uint32_t StatusCode;
	uint8_t SendAck[2];
	uint8_t PingPacket[2];
	uint8_t Line_Buffer[ONE_LINE_BUF_SIZE] = {0};
    /* Send Data */
    serial_framing_packet_t data_packet;
				
	Repro.Fls.loop_flag = ON;

	while(Repro.Fls.loop_flag == ON)
	{

    switch(Repro.Fls.Repro_OperState)
    {
		// 1 : HOST
		// 2 : Target
		/*
		1. 5A A6 : Ping Packet

		*/
    	case cPing_Command:

			//gs_Repro_Flash_Init(); // 재시도할 경우 대비하여 여기서 추가로 초기화가 필요함

			PingPacket[0] = kFramingPacketStartByte;		// 0x5A
			PingPacket[1] = kFramingPacketType_Ping;		// 0xA6

			ss_UartReproWrite(PingPacket, 2u);	// send Ping Packet // 0x5A, 0xA6

			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cPing_Response;
			Repro.Fls.Repro_OperState_Old = cPing_Command;
			Repro.Fls.loop_flag = OFF;
		break;


		// 1 : HOST
		// 2 : Target
		/*
		2. 5A A7 00 02 01 50 00 00 AA EA : Ping Responsed Packet <-- cPing_Response
		*/
// FlashImae 파일 전체 파싱하는데 약 4초 걸림.
// 그런데 erase 할때도 파싱을 하고 write 할때도 다시 파싱을 하므로 약 4초가 반복되어 손해다.
// erase할때 파싱한 어드레스와 주소를 저장했다가 다시 write할대 파싱하지 않고 저장된 주소를 사용하면 4초를 단축할수 있다.
//--> 4초 단축하려고 했으나 FlashImage 파일이 몇조각으로 생성될지 미리 파악을 못하므로
// 저장된 주소를 몇개로 저장해야 할지 미리 파악이 안되므로 그냥 현재처럼 라이팅하기 전에 파싱하는것이 바람직함.
// 4초 손해는 어쩔수 없음
    	case cPing_Response:

			if(Repro.Fls.RxResponsePing == ON)	 // ping data received completed ?
			{
				Repro.Fls.RxResponsePing = OFF;
				
				Repro.Fls.ErrWaitCnt = 0;

				//gs_CopyData((uint8_t *)&Repro.Fls.PingRespData, &Repro.Fls.RxDataBuf, cPing_PacketSize);
				memcpy(&Repro.Fls.PingRespData, Repro.Fls.RxDataBuf, cPing_PacketSize); // 표준 라이브러리 함수로 변경
				//gs_ClearData(Repro.Fls.RxDataBuf, cReproRxDataMaxSize);
				memset(Repro.Fls.RxDataBuf, 0, sizeof(Repro.Fls.RxDataBuf)); // 표준 라이브러리 함수로 변경


				crc16_init(&crc16_value);// Initialize the CRC16 information.
				crc16_update(&crc16_value, (uint8 *)&Repro.Fls.PingRespData, sizeof(Repro.Fls.PingRespData) - sizeof(uint16_t));    // 뒤에 crc16 2byte 제외. // Include the start byte and packetType in the CRC.

				if(crc16_value.currentCrc == Repro.Fls.PingRespData.ping_response_data.crc16)	// crc16 check is OK
				{
					//Repro.Fls.Repro_OperState = cVersionNvMErase;
					
					// 시큐어 락 여부를 확인할수 있는 함수로 락 여부를 확인하고 락 걸린 경우에만 all unsecure 함.
					if(Repro.Int.SecurityViolation == ON)
					{
						Repro.Fls.Repro_OperState = cFlashEraseAllUnsecure_Command;
					}
					else
					{
						Repro.Fls.Repro_OperState = cParsingSrecord;	// Region Erase 을 위한 어드레스 분석
					}					
				}
				else
				{
            		Repro.Fls.Repro_OperState = cReproFlash_Fail;
					Repro.Fls.ReproErrCode = cERR_Ping_Response_CRC;
				}
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cPingResponseWaitTimeout)
			{
				Repro.Fls.ErrWaitCnt = 0;
            	Repro.Fls.Repro_OperState = cPing_Command;	// 통신 이상으로 reset 될때까지 계속 retry
				Repro.Fls.ReproErrCode = cERR_Ping_Response_Timeout;

				if(Repro.Fls.PingRetryCnt < cPingRetryCnt) // pin  response retry
				{
					Repro.Fls.PingRetryCnt ++;
					Repro.Fls.ErrWaitCnt = 0;
            		Repro.Fls.Repro_OperState = cPing_Command;	// 통신 이상으로 reset 될때까지 계속 retry
				}

				if(Repro.Fls.PingRetryCnt >= cPingRetryCnt)
				{
					Repro.Fls.Repro_OperState = cReproFlash_Fail;
					Repro.Fls.ReproErrCode = cERR_Ping_Response_Timeout;
				}
			}

			Repro.Fls.Repro_OperState_Old = cPing_Response;

			Repro.Fls.loop_flag = OFF;
		break;

        // 실제 earse하는데 소요되는 시간 pusle로 측정ㄹ하여 시간 측정하고
        // 필요하다면 적절하게 분할할것.
        case cParsingSrecord: // 이미지 변환한 배열 파싱 처리

        	// 실행시간이 너무 길면 분할 할 필요 있음.
        	// 포트 출력으로 실행시간 측정해서 10ms task 오버되는지 반드시 확인할것.

			memset(Line_Buffer, 0, sizeof(Line_Buffer));	// clear
        	/* Traverse the second time to program target*/
        	// srecord image의 1 line의 최대 길이가 263개이다. 마지막 문자가 NULL
        	// 최대 길이까지 read해야 하므로 for문으로 반복하고 그보다 짧은경우에는 즉시 탈출하도록 한다.
        	for (uint16_t line_cnt = 0; line_cnt < ONE_LINE_BUF_SIZE; line_cnt++)
        	{
				if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE5)
				{
					Srecord_Char = s_record_TYPE5[Repro.Fls.Line_Arry_Index][line_cnt];
				}
				else if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE6)
				{
					Srecord_Char = s_record_TYPE6[Repro.Fls.Line_Arry_Index][line_cnt];
				}
				else // default
				{
					Srecord_Char = s_record_TYPE5[Repro.Fls.Line_Arry_Index][line_cnt];
				}

        	    if (Srecord_Char == NULL) // 문자열 배열 끝이 ASCII NULL 이면 끝나는 것이다.
        	    {
					// 파싱 후 변수 초기화
        	        Repro.Fls.WriteData_Index = 0;
					Repro.Fls.image_size = 0;
        	        Repro.Fls.Line_Arry_Index++;

        	        // 1 line 전체 parsing 처리함.
        	        // Repro.Fls.new_record 구조체에 정보 설정됨.
        	        // 이 구조체 값을 이용해서 srecord_build_image()에서 어드레스가 연속적인 블럭을 찾는다.
					Record_Status = srecord_parse_line(Line_Buffer, line_cnt);

        	        if (Record_Status != kRecordStatus_Success) // 파싱중 에러가 발생하면 에러 값을 리턴하고 중단한다. 호출하는곳에서 리트라이처리 필요함.
        	        {
						if(Record_Status == kRecordStatus_AddressSkip)
						{
							break;	// 아무 처리 하지 않고 다음 라인 parsing 처리
						}
						else
						{
        	            	Repro.Fls.Repro_OperState = cReproFlash_Fail;
							//Repro.Fls.ReproErrCode = cERR_ImageParsing; // 콜되는 함수에서 상세한 에러 코드로 할당함. 여기서는 할당하면 안됨.

							Repro.Fls.loop_cnt = 0;
							Repro.Fls.loop_flag = OFF;
        	            	break;
						}
        	        }

    				uint8_t is_data_record = 0;
    				uint8_t has_data = 0;

        	        /* Handle S3, 2, 1 records */
        	        if ((Repro.Fls.new_record.type == 3u) || (Repro.Fls.new_record.type == 2u) || (Repro.Fls.new_record.type == 1u))
        	        {
        	            is_data_record = 1u;
        	        }
        	        else
        	        {
        	            is_data_record = 0u;
        	        }

        	        //has_data = (Repro.Fls.new_record.data) && (Repro.Fls.new_record.dataCount != 0); // Repro.Fls.new_record.data가 주소여서 항상 상수이다.
					has_data = (Repro.Fls.new_record.dataCount != 0);

        	        if (is_data_record && has_data)
        	        {
        	            if (Repro.Fls.image_buffer_index != 0u)
        	            {
        	                /* If this record's data would overflow the collection buffer, or if the */
        	                /* record is not contiguous with the rest of the data in the collection */
        	                /* buffer, then flush the buffer to the executable image and restart. */
        	                if (((Repro.Fls.image_buffer_index + Repro.Fls.new_record.dataCount) > IMAGE_BUFFER_SIZE) ||
        	                    (Repro.Fls.new_record.address != Repro.Fls.image_next_address))
        	                {
								Repro.Fls.image_size = Repro.Fls.image_buffer_index;

								Repro.Fls.Line_Arry_Index--; // 이번에 읽은 라인이 어드레스가 틀려진 라인이다.
													  // 그러므로 다음번 시작시에 이 번 라인부터 다시 읽어야 한다.
													  // 그래서 index를 한단계 뒤로 되될린다.

								if(Repro.Fls.EraseCompleted == ON)
								{
									// write시에는 data 송신후 image_buffer_index = 0; 처리 한다.
									Repro.Fls.Repro_OperState = cWriteMemory_Command;
								}
        	                    else
								{
									Repro.Fls.image_buffer_index = 0; // 한 블럭이 완료되었으므로 초기화해야함. 그래야 다음번 블럭의 처음부터 시작할수 있다.
									Repro.Fls.Repro_OperState = cFlashEraseRegion_Command;
								}

								Repro.Fls.loop_cnt = 0;
								Repro.Fls.loop_flag = OFF;
        	                    break;
        	                }
        	            }

        	            /* Capture addresses when starting an empty buffer. */
        	            if (Repro.Fls.image_buffer_index == 0u)
        	            {
        	                Repro.Fls.image_start_address = Repro.Fls.new_record.address;
        	                Repro.Fls.image_next_address = Repro.Fls.image_start_address;
        	            }

        	            /* Copy record data into place in the collection buffer and update */
        	            /* size and address. */
        	            memcpy(&Repro.Fls.image_buffer[Repro.Fls.image_buffer_index], Repro.Fls.new_record.data, Repro.Fls.new_record.dataCount);
        	            Repro.Fls.image_buffer_index += Repro.Fls.new_record.dataCount;
        	            Repro.Fls.image_next_address += Repro.Fls.new_record.dataCount;

        	            Repro.Fls.erase_bytes = Repro.Fls.image_buffer_index;
        	        }
        	        else if ((Repro.Fls.new_record.type == 7u) || (Repro.Fls.new_record.type == 8u) || (Repro.Fls.new_record.type == 9u))
        	        {
        	            /* Flash any leftover data to target. */
        	            if (Repro.Fls.image_buffer_index != 0u)
        	            {
							Repro.Fls.image_size = Repro.Fls.image_buffer_index;

							if(Repro.Fls.EraseCompleted == ON)
							{
								// write시에는 data 송신후 image_buffer_index = 0; 처리 한다.
								Repro.Fls.Repro_OperState = cWriteMemory_Command;
							}
        	                else
							{
								Repro.Fls.image_buffer_index = 0; // 한 블럭이 완료되었으므로 초기화해야함. 그래야 다음번 블럭의 처음부터 시작할수 있다.
								Repro.Fls.Repro_OperState = cFlashEraseRegion_Command;
							}

							Repro.Fls.loop_cnt = 0;
							Repro.Fls.loop_flag = OFF;
        	                break;
        	            }
        	        }
        	        else
        	        {
        	            // QAC
        	        }

					Repro.Fls.loop_cnt ++;
					if(Repro.Fls.loop_cnt >= PARSING_CNT_PER_TASK)	// 파싱 속도 높이기 위해서 10ms Task당 라인 2개씩 파싱함. 부하 상태 봐가면서 라인 숫자 늘릴것.
					{
						Repro.Fls.loop_cnt = 0;
						Repro.Fls.loop_flag = OFF;
					}

					break; // 1 line 끝까지 read하면 무조건 for문 탈출하여 다시 시작해야 함.
        	    }
        	    else
        	    {
					Line_Buffer[line_cnt] = Srecord_Char;
        	    }
        	}
			
			Repro.Fls.ErrWaitCnt = 0;
			Repro.Fls.Repro_OperState_Old = cParsingSrecord;

			Repro.Fls.ReproFlashStatus = FLASH_PARSING;
        break;

        case cFlashEraseAllUnsecure_Command:

			FlashEraseAllUnsecure_Command_Send();

			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cAck_Response;
			Repro.Fls.Repro_OperState_Old = cFlashEraseAllUnsecure_Command;

			Repro.Fls.loop_flag = OFF;

			Repro.Fls.ReproFlashStatus = FLASH_ERASING;
		break;

        case cFlashEraseRegion_Command:

			Repro.Out.ReproPercent = 1u; // erase 동안 caone에서 %가 계속 0%이면 문제가 있어 보이므로 1% 강제 출력함

            /* Erase bytes count must be a multiple of 1024 or 2048 */
			// sample code에서는 512byte 였는데 WCT2013A는 2048 임.
			// 512 단위로 erase하면 어플리케이션 시작 주소를 0x600으로 하면 에러 발생함. (0x208 --> 0x600 --> 0x800)
			// 그래서 2048의 배수인 0x800으로 했더니 정상 동작함.
			// 그래서 erase block 단위를 2048로 변경함.

            if (Repro.Fls.erase_bytes % EraseAlignment)
            {
                if (Repro.Fls.erase_bytes > EraseAlignment)
                {
                    Repro.Fls.erase_bytes = ((Repro.Fls.erase_bytes >> 9u) + 1u) << 9u;
                }
                else
                {
                    Repro.Fls.erase_bytes = EraseAlignment;
                }
            }

			FlashEraseRegion_Command_Send();

			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cAck_Response;
			Repro.Fls.Repro_OperState_Old = cFlashEraseRegion_Command;

			Repro.Fls.loop_flag = OFF;

			Repro.Fls.ReproFlashStatus = FLASH_ERASING;
        break;


        case cWriteMemory_Command:

            // 이 수만큼 uart 통신으로 data 를 송신해야 함.
            // 한번만 실행해야 해서 여기서 한다.
            if (Repro.Fls.image_buffer_index % kOutgoingPacketBufferSize)
            {
                Repro.Fls.data_packet_num = (Repro.Fls.image_buffer_index >> 5) + 1;
            }
            else
            {
                Repro.Fls.data_packet_num = (Repro.Fls.image_buffer_index >> 5);
            }


			WriteMemory_Command_Send();

			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cAck_Response;
			Repro.Fls.Repro_OperState_Old = cWriteMemory_Command;

			Repro.Fls.loop_flag = OFF;

			Repro.Fls.ReproFlashStatus = FLASH_PROGRAMMING;
        break;

        case cExecute_Command:

			Execute_Command_Send();

			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cAck_Response;
			Repro.Fls.Repro_OperState_Old = cExecute_Command;

			Repro.Fls.loop_flag = OFF;

			Repro.Fls.ReproFlashStatus = FLASH_VER_CHECK;
        break;

        case cWriteMemory_Data:
            /* Calculate data packet num to send */




            data_packet.dataPacket.header.startByte = kFramingPacketStartByte;
            data_packet.dataPacket.header.packetType = kFramingPacketType_Data;


            if (Repro.Fls.image_buffer_index > kOutgoingPacketBufferSize)
            {
                data_packet.dataPacket.length = kOutgoingPacketBufferSize;

                for (int32_t i = 0; i < kOutgoingPacketBufferSize; i++)
                {
                    data_packet.data[i] = Repro.Fls.image_buffer[Repro.Fls.WriteData_Index];
                    Repro.Fls.WriteData_Index++;
                }
                Repro.Fls.image_buffer_index -= kOutgoingPacketBufferSize;
            }
            else
            {
                data_packet.dataPacket.length = Repro.Fls.image_buffer_index;

                for (int32_t i = 0; i < Repro.Fls.image_buffer_index; i++)
                {
                    data_packet.data[i] = Repro.Fls.image_buffer[Repro.Fls.WriteData_Index];
                    Repro.Fls.WriteData_Index++;
                }
                Repro.Fls.image_buffer_index = 0; // 한 블럭이 완료되었으므로 초기화해야함. 그래야 다음번 블럭의 처음부터 시작할수 있다.
            }

            crc16_init(&crc16_value);
            crc16_update(&crc16_value, (uint8_t *)&data_packet.dataPacket,
                         sizeof(framing_data_packet_t) - sizeof(uint16_t));
            crc16_update(&crc16_value, (uint8_t *)data_packet.data, data_packet.dataPacket.length);
            data_packet.dataPacket.crc16 = crc16_value.currentCrc;

            ss_UartReproWrite((uint8 *)&data_packet, sizeof(framing_data_packet_t) + data_packet.dataPacket.length);

            Repro.Fls.data_packet_num--;

			Repro.Out.ReproPercent = (uint8_t)(((Repro.Fls.image_size - Repro.Fls.image_buffer_index) * 100u) / Repro.Fls.image_size);

			// canoe에서 100%가 블럭 갯수만큼 반복되면 완료라고 표시하는데 문제가 있다.
			// 그래서 FalshImage.h의 마지막 라인까지 파싱 완료된 상태 일때만 100% 출력 되도록 한다.
			// 그 이외의 경우는 99%까지만 출력하여 canoe에서 완료되지 않도록 한다.)

			// 버전 까지 모두 일치 해서 complete 될때 거기서 100% 출력하도록한다.
			// 여기서는 max가 99%이다.


			if(Repro.Out.ReproPercent > 99u)
			{
				Repro.Out.ReproPercent = 99u;
			}



			Repro.Fls.ErrWaitCnt = 0;
            Repro.Fls.Repro_OperState = cAck_Response;     // 다시 이어서 처리
			Repro.Fls.Repro_OperState_Old = cWriteMemory_Data;


			Repro.Fls.loop_flag = OFF;

			Repro.Fls.ReproFlashStatus = FLASH_PROGRAMMING;

        break;

		case cAck_Response: // Try for half a second to get a response

			Repro.Fls.loop_flag = OFF;	// cWriteMemory_Data 일 경우에만 ON으로 설정하여 데이터 전송 인터벌 단축한다.

			if(Repro.Fls.RxResponseAck == ON)	// ACK received completed ? (0x5A, 0xA1 수신완료)
			{
				Repro.Fls.RxResponseAck = OFF;
				Repro.Fls.ErrWaitCnt = 0;
				
				if((Repro.Fls.Repro_OperState_Old == cWriteMemory_Command) ||
				(Repro.Fls.Repro_OperState_Old == cFlashEraseAllUnsecure_Command) ||
				(Repro.Fls.Repro_OperState_Old == cFlashEraseRegion_Command) ||
				(Repro.Fls.Repro_OperState_Old == cExecute_Command) ||
				((Repro.Fls.Repro_OperState_Old == cWriteMemory_Data) &&
				(Repro.Fls.data_packet_num == 0u))) // data 전송 마지막 전송후 ACK 다음에는 generic으로 이동하고 종료해야함.
				{
					
                    Repro.Fls.Repro_OperState = cGeneric_Response;


				}
				else if(Repro.Fls.Repro_OperState_Old == cWriteMemory_Data)
				{
					Repro.Fls.Repro_OperState = cWriteMemory_Data;
					Repro.Fls.loop_flag = ON;

				}
				else
				{
					// QAC
				}
			}
			else if(Repro.Fls.RxResponseNak == ON)
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.RxResponseNak = OFF;

				Repro.Fls.Repro_OperState = cReproFlash_Fail;
				Repro.Fls.ReproErrCode = cERR_Ack_Response_NAK;
			}
			else if(Repro.Fls.RxResponseAckAbort == ON)
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.RxResponseAckAbort = OFF;

				Repro.Fls.Repro_OperState = cReproFlash_Fail;
				Repro.Fls.ReproErrCode = cERR_Ack_Response_Aboart;
			}
			else
			{
				// QAC
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cReproRxWaitTimeout)	// 500ms
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_Fail;
				Repro.Fls.ReproErrCode = cERR_Ack_Response_Timeout;
			}

			// Repro.Fls.Repro_OperState_Old = cAck_Response; // repro에서는 commandtag방식으로 구분 가능하나 충전ic없이 하는 디버그상에서는 응답이 없으므로 일단 주석처리하여 이전 old state를 이용한다.

		break;

		case cGeneric_Response:


			// 통신 로그를 직접 분석해 보니 Ack 신호와 Generic Response 신호가 시간차가 없이 이어서 수신된다.
			// 그러므로 10ms task뒤에 확인했을때는 이미 두신호가 모두 수신된 상태이다.
			// 그러므로 리프로 시간 단축을 위해서 case문 2개를 하나로 통합한다.

			if(Repro.Fls.RxResponseGeneric == ON)	 // Generic Response received completed ? (command packet)
			{
				Repro.Fls.RxResponseGeneric = OFF;

				DataPacketLen = (uint16_t)(Repro.Fls.RxDataBuf[2] + ((uint16_t)Repro.Fls.RxDataBuf[3] << 8u));
				//CommandTag = Repro.Fls.RxDataBuf[14] + (Repro.Fls.RxDataBuf[15] << 8u) +(Repro.Fls.RxDataBuf[16] << 16u) +(Repro.Fls.RxDataBuf[17] << 24u);

				//gs_CopyData((uint8_t *)&Repro.Fls.framingPacket, Repro.Fls.RxDataBuf, DataPacketLen + cFraming_HeaderSize);
				memcpy(&Repro.Fls.framingPacket, Repro.Fls.RxDataBuf, DataPacketLen + cFraming_HeaderSize); // 표준 라이브러리 함수로 변경

				//gs_ClearData(Repro.Fls.RxDataBuf, cReproRxDataMaxSize);
				memset(Repro.Fls.RxDataBuf, 0, sizeof(Repro.Fls.RxDataBuf)); // 표준 라이브러리 함수로 변경

				Repro.Fls.ErrWaitCnt = 0;

				crc16_init(&crc16_value);
				crc16_update(&crc16_value, (uint8_t *)&Repro.Fls.framingPacket.dataPacket, sizeof(Repro.Fls.framingPacket.dataPacket) - sizeof(uint16_t)); // crc16 2byte 제외
				crc16_update(&crc16_value, (uint8_t *)&Repro.Fls.framingPacket.data, Repro.Fls.framingPacket.dataPacket.length);

				if(crc16_value.currentCrc == Repro.Fls.framingPacket.dataPacket.crc16)	// crc16 check is OK
				{
					// 에러 코드는 메뉴얼에서 상세하게 확인 가능함.

					StatusCode = (Repro.Fls.framingPacket.data[4] + ((uint32_t)Repro.Fls.framingPacket.data[5] << 8u) + ((uint32_t)Repro.Fls.framingPacket.data[6] << 16u) + ((uint32_t)Repro.Fls.framingPacket.data[7] << 24u));
					CommandTag = (Repro.Fls.framingPacket.data[8] + ((uint32_t)Repro.Fls.framingPacket.data[9] << 8u) + ((uint32_t)Repro.Fls.framingPacket.data[10] << 16u) + ((uint32_t)Repro.Fls.framingPacket.data[11] << 24u));

					if(StatusCode == kStatus_Success) // 응답 success일 경우 ACK 전송
					{
						SendAck[0] = kFramingPacketStartByte;			// 0x5A
						SendAck[1] = kFramingPacketType_Ack;			// 0xAl

						ss_UartReproWrite(SendAck, 2u);	// send ack // 0x5A, 0xA1

						//gs_ClearData((uint8_t *)&Repro.Fls.framingPacket, sizeof(serial_framing_packet_t));		// 초기화
						memset(&Repro.Fls.framingPacket, 0, sizeof(serial_framing_packet_t)); // 표준 라이브러리 함수로 변경

						// if(CommandTag == kCommandTag_Execute)
						// {
						// 	Repro.Fls.Repro_OperState = cReproFlash_VersionVerify; // 버전 체크
						// }
						// else if(CommandTag == kCommandTag_FlashEraseRegion) // erasae 후 즉시 writing 하는 컨셉이다.
						// {
						// 	Repro.Fls.Repro_OperState = cWriteMemory_Command; // 여기는 항상 Erase 명령에 의해서만 호출되고 Erase 후 Write 해야한다.
						// }
						// else if(CommandTag == kCommandTag_WriteMemory)
						// {
                        	// if(Repro.Fls.data_packet_num != 0u) // 전송해야 할 데이터가 있으면 반복, 없으면
                        	// {
                        	//     // 여기서 data send를 반복 할것인지 아니면 noDataResp이므로 종료 할것인지 정해야함.

                        	//     Repro.Fls.Repro_OperState = cWriteMemory_Data; // Data 반복처리
                        	// }
                        	// else
                        	// {
                    		// 	if ((Repro.Fls.new_record.type == 1u) || (Repro.Fls.new_record.type == 2u) || (Repro.Fls.new_record.type == 3u))
                    		// 	{
                        	// 		Repro.Fls.Repro_OperState = cParsingSrecord; // 나머지 블럭에 대해서 파싱 반복 처리
                    		// 	}
                    		// 	else //if((Repro.Fls.new_record.type == 7u) || (Repro.Fls.new_record.type == 8u) || (Repro.Fls.new_record.type == 9u))
                    		// 	{
                        	// 		Repro.Fls.Repro_OperState = cExecute_Command; // srecord의 마지막 라인까지 read 하고 여기에 온것이므로 더이상 처리할것이 없다. 버전 체크를 위해서 충전 IC 실행한다. reset이 좋을지 excute가 좋을지 판단 필요.
                    		// 	}
                        	// }
						// }
						// else if(CommandTag == kCommandTag_FlashEraseAllUnsecure)
						// {

						// }
						// else
						// {

						// }

						if(Repro.Fls.Repro_OperState_Old == cExecute_Command) // no data response
						{
							Repro.Fls.ErrWaitCnt = 0;
							//Repro.Fls.Repro_OperState = cReproFlash_VersionVerify; // 버전 체크/* 010A_09 */
							Repro.Fls.Repro_OperState = cReproFlash_Calibration; /* 010A_09 */
							
							Repro.Out.ReproVersionVerifyReq = ON; // 버전 체크 가능하도록 normal uart 동작 요청함.
						}
						else if(Repro.Fls.Repro_OperState_Old == cFlashEraseAllUnsecure_Command)
						{
							Repro.Fls.Repro_OperState = cParsingSrecord; // unsecure 한 다음 erase 부터 다시 시작함.// unsecure에서도 지워지나 기존 로직 변경하지 않기 위해서
						}
						else if(Repro.Fls.Repro_OperState_Old == cFlashEraseRegion_Command)// no data response
						{
							if ((Repro.Fls.new_record.type == 1u) || (Repro.Fls.new_record.type == 2u) || (Repro.Fls.new_record.type == 3u))
							{
								Repro.Fls.Repro_OperState = cParsingSrecord;
							}
							else // erase 블럭 모두 완료시
							{
								// 다시 parsing 해야 하므로 필요한 변수 초기화 처리
								memset(Repro.Fls.image_buffer, 0, sizeof(Repro.Fls.image_buffer));  				// 구조체 변수를 0으로 클리어
								Repro.Fls.image_buffer_index = 0;
								Repro.Fls.image_start_address = 0;
								Repro.Fls.image_next_address = 0;
								Repro.Fls.Line_Arry_Index = 0;

								Repro.Fls.EraseCompleted = ON; // erase 완료
								Repro.Fls.Repro_OperState = cParsingSrecord;
							}

						}
						else if((Repro.Fls.Repro_OperState_Old == cWriteMemory_Command) || // data response
						(Repro.Fls.Repro_OperState_Old == cWriteMemory_Data)) // data response
						{
                        	if(Repro.Fls.data_packet_num != 0u) // 전송해야 할 데이터가 있으면 반복, 없으면
                        	{
                        	    // 여기서 data send를 반복 할것인지 아니면 noDataResp이므로 종료 할것인지 정해야함.

                        	    Repro.Fls.Repro_OperState = cWriteMemory_Data; // Data 반복처리
                        	}
                        	else
                        	{
                    			if ((Repro.Fls.new_record.type == 1u) || (Repro.Fls.new_record.type == 2u) || (Repro.Fls.new_record.type == 3u))
                    			{
                        			Repro.Fls.Repro_OperState = cParsingSrecord; // 나머지 블럭에 대해서 파싱 반복 처리

                    			}
                    			else //if((Repro.Fls.new_record.type == 7u) || (Repro.Fls.new_record.type == 8u) || (Repro.Fls.new_record.type == 9u))
                    			{
                        			Repro.Fls.Repro_OperState = cExecute_Command; // srecord의 마지막 라인까지 read 하고 여기에 온것이므로 더이상 처리할것이 없다. 버전 체크를 위해서 충전 IC 실행한다. reset이 좋을지 excute가 좋을지 판단 필요.
                    			}
                        	}
						}
						else
						{

						}
						Repro.Int.SecurityViolation = OFF; // 리트라이 후 정상이되면 플래그 클리어
					}
					// 일단 Secure 에러가 발생함.
					// 무조건 All Unsecure를 해야 하는가?
					else if (StatusCode == kStatus_SecurityViolation)
					{
						// 시큐어락 에러 일 경우에는 Allunsecure 커맨드를 송신하면 해제될것 같으나
						// 테스트시 response 타임아웃이 발생한다.
						// 전원 리셋해서 ping부터 다시 시작해야 되는듯.
						//Repro.Fls.Repro_OperState = cFlashEraseAllUnsecure_Command;
						Repro.Fls.Repro_OperState = cReproFlash_Fail;
						Repro.Fls.ReproErrCode = cERR_Generic_Response_SecurityViolation;

						Repro.Int.SecurityViolation = ON; // parsing 시 전체 어드레스를 취득해야함.
					}
					else
					{
						Repro.Fls.Repro_OperState = cReproFlash_Fail;
						Repro.Fls.ReproErrCode = cERR_Generic_Response_Status;
					}
				}
				else
				{
					Repro.Fls.Repro_OperState = cReproFlash_Fail;
					Repro.Fls.ReproErrCode = cERR_Generic_Response_CRC;
				}
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cReproRxWaitTimeout)	// 500ms
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_Fail;
				Repro.Fls.ReproErrCode = cERR_Generic_Response_Timeout;
			}
			//Repro.Fls.Repro_OperState_Old = cGeneric_Response; // repro에서는 commandtag방식으로 구분 가능하나 충전ic없이 하는 디버그상에서는 응답이 없으므로 일단 주석처리하여 이전 old state를 이용한다.

			Repro.Fls.loop_flag = OFF;
		break;

		
/* 0108_13 */
        case cReproFlash_Calibration:

			// 최초 전원 리셋시에 캘리브레이션 진행한다.
			// 이제는 전원 리셋이 아니라 excute 명령 실행시에 버전을 read하기 위해서 전원이 인가 된다.
			// 이때 동시에 캘리브레이션 진행되므로 일정시간 전원을 유지 해야 한다.
			// Repro.Fls.ReproFlashStatus = FLASH_COMPLETED;이 되면 즉시 충전IC 전원 Off되므로
			// 캘리브레이션 시간 동안 전원이 공급되도록 하기 위해서 일정시간 후 Repro.Fls.ReproFlashStatus = FLASH_COMPLETED;한다.
/* 010A_09 */	
			if(Repro.Inp_UART.WctUartCommReady == ON) // 버전 정상 수신 되면 캘리브레이션 종료 된것임
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_VersionVerify;						
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cCalibrationWaitTimeout)
			{
				Repro.Fls.ErrWaitCnt = 0;			
				Repro.Fls.ReproErrCode = cERR_Calibration_Timeout;
				Repro.Fls.Repro_OperState = cReproFlash_Fail;								
			}			
/* 010A_09 */	
			Repro.Fls.ReproFlashStatus = FLASH_CALIBRATION;;	
			Repro.Fls.Repro_OperState_Old = cReproFlash_Calibration;

			Repro.Fls.loop_flag = OFF;
        break;

		case cReproFlash_VersionVerify:

			if(Repro.Inp_UART.WctUartCommReady == ON) // 버전 정상 수신
			{
				// 버전이 읽어 진것이면 일단 리프로는 성공한것이다.
				// 버전 불일치 하더라도 일단 리프로그램은 성공으로 처리한다.
				if((Repro.Inp_UART.WctSourceVer[0] != Repro.Out.WctTargetVer[0]) || /* 0108_01 */
				   (Repro.Inp_UART.WctSourceVer[1] != Repro.Out.WctTargetVer[1]) || /* 0108_01 */
				   (Repro.Inp_UART.WctSourceVer[2] != Repro.Out.WctTargetVer[2]))   /* 0108_01 */// 리프로 실패 (버전 불일치)
				{	
					Repro.Fls.ReproErrCode = cERR_VersionVerify_Unmatch;										
				}

				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_NvMPending;
				Repro.Out.m_WctReproRequest = OFF; // 캘리브레이션까지 완료되었으므로 NvM에 리프로 요청 플래그를 클리어한다.

				Repro.Out.ReproVersionVerifyReq = OFF; // normal 버전 수신 종료 처리함.
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cReproRxWaitTimeout)	// 500ms
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_Fail;
				Repro.Fls.ReproErrCode = cERR_VersionVerify_Timeout;

				Repro.Out.ReproVersionVerifyReq = OFF; // normal 버전 수신 종료 처리함.
			}

			Repro.Fls.Repro_OperState_Old = cReproFlash_VersionVerify;

			Repro.Fls.ReproFlashStatus = FLASH_VER_CHECK;

			Repro.Fls.loop_flag = OFF;

		break;

		case cReproFlash_NvMPending:

			/* NvM Update Check */
			if((Repro.Inp_NvM.NvMBlk_1B_Complete[BLK_NO_1B_WctReproRequest] == ON) &&
			(Repro.Inp_NvM.m_WctReproRequest == OFF))  // NVM에 저장된 값이 OFF로 변경 완료되면 종료한다.
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.Repro_OperState = cReproFlash_Completed;
			}

			Repro.Fls.ErrWaitCnt ++;
			if(Repro.Fls.ErrWaitCnt >= cNvMPendingTimeout)
			{
				Repro.Fls.ErrWaitCnt = 0;
				Repro.Fls.ReproErrCode = cERR_NvMWrite_Timeout;
					
				Repro.Fls.Repro_OperState = cReproFlash_Fail;					
			}
			

			//Repro.Fls.Repro_OperState_Old = cReproFlash_NvMPending; // pending 할때 이 값이 설정되면 안됨.

			Repro.Fls.loop_flag = OFF;

		break;
				
		
		case cReproFlash_Completed:
			Repro.Out.ReproPercent = 100u;	// caone 시뮬레이터 강제 구동 자동 stop 기능이 100%가 되면 이루어지므로 100%를 가장 마지막에 되어야함.
			
			if(Repro.Fls.ReproErrCode == cERR_VersionVerify_Unmatch)
			{
				Repro.Fls.ReproFlashStatus = FLASH_COMPLETE_UNMATCH;	// 버전 불일치에러 일때는 리트라이 안함
			}
			else
			{
				Repro.Fls.ReproFlashStatus = FLASH_COMPLETED;;	
			}
						
			Repro.Fls.loop_flag = OFF;
		break;
		
/* 0108_13 */		
        case cReproFlash_Fail:
			
			Repro.Fls.ReproFlashStatus = FLASH_ERROR;
			//Repro.Fls.Repro_OperState_Old = cReproFlash_Fail; // debug시 fail된 case 확인되도록 old 값 변경하지 않음
			Repro.Fls.loop_flag = OFF;
        break;		

        default:
            // QAC
			Repro.Fls.loop_flag = OFF;
        break;
    }


	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static _recordStatus_t srecord_parse_line(uint8_t *line, uint16_t line_length)
{
    uint32_t checksum = 0;
    uint32_t i = 0;

    if (line_length < SRECORD_MIN_LENGTH)
    {
		Repro.Fls.ReproErrCode = cERR_LineParsing_SrecordInvalidLen;
        return kRecordStatus_InvalidLength;
    }

    if (line[0] != SRECORD_START_CHAR)
    {
		Repro.Fls.ReproErrCode = cERR_LineParsing_StartChar;
        return kRecordStatus_InvalidStart;
    }

    /* Parse type field*/
    if ((line[1] > '9') || (line[1] < '0'))
    {
		Repro.Fls.ReproErrCode = cERR_LineParsing_RecordType;
        return kRecordStatus_InvalidType;
    }
    Repro.Fls.new_record.type = line[1] - '0'; // ASCII를 int로 변경하는 방법

    /* Parse count field*/
    Repro.Fls.new_record.count = read_hex_byte(line, 2u); // line[2], line[3]의 ascii를 hex로 변경함.
    checksum += Repro.Fls.new_record.count;

    /* verify the record length now that we know the count*/
    if (line_length != 4u + Repro.Fls.new_record.count * 2u) // "S3 81 00000000 54E1589F54E1589F54E2D92754E2D92754E2D
    {
		Repro.Fls.ReproErrCode = cERR_LineParsing_LineInvalidLen;
        return kRecordStatus_InvalidLength;
    }

    /* Get address length*/
    uint8_t address_length = 0;
    uint8_t has_data = 0;
    switch (Repro.Fls.new_record.type)
    {
        case 0u:
            address_length = 2u;
            has_data = 1u;
            break;
        case 1u:
            address_length = 2u;
            has_data = 1u;
            break;
        case 2u:
            address_length = 3u;
            has_data = 1u;
            break;
        case 3u:
            address_length = 4u;
            has_data = 1u;
            break;
        case 5u:
            address_length = 2u;
            break;
        case 7u:
            address_length = 4u;
            break;
        case 8u:
            address_length = 3u;
            break;
        case 9u:
            address_length = 2u;
            break;
        default:
            return kRecordStatus_InvalidType;
    }

    /* Read address*/
    uint32_t address = 0;
    for (i = 0; i < address_length; i++)
    {
        uint8_t address_byte = read_hex_byte(line, SRECORD_ADDRESS_START_CHAR_INDEX + i * 2u); // 문자열 2개씩 read
        address = (address << 8u) | address_byte; // 1byte씩 읽어서 4바이트 만듬.
        checksum += address_byte;
    }
// 어플리케이션 어드레스만 취득하는 로직 추가
// 만약 시큐어 에러 발생시에는 전체 어드레스를 취득하도록 해야 한다.

	if(Repro.Int.SecurityViolation == ON)
	{
		Repro.Fls.new_record.address = address;
	}
	else
	{
#if defined (WCT_REPROGRAM_ALL)
		Repro.Fls.new_record.address = address;
	
#elif defined (WCT_REPROGRAM_APP_ONLY)
		if((address >= APP_ADDRESS) &&
		(address < NvM_ADDRESS))
		{
			Repro.Fls.new_record.address = address;
		}
		else
		{
			return kRecordStatus_AddressSkip;
		}
#elif defined (WCT_REPROGRAM_OFF)
		// none
#else
	Error : WCT_REPROGRAM not defined		
#endif
	}


    /* Read data*/
    if (has_data)
    {
        // "S3 81 00000000 54E1589F54E1589F54E2D92754E2D92754E2D
        int32_t data_start_char_index = 4u + address_length * 2u;
        int32_t data_length = Repro.Fls.new_record.count - address_length - 1u; // count - address - checksum(1)

        for (i = 0; i < data_length; i++)
        {
            uint8_t data_byte = read_hex_byte(line, data_start_char_index + i * 2u); // 문자열 2개씩 read
            Repro.Fls.new_record.data[i] = data_byte;
            checksum += data_byte;
        }
        Repro.Fls.new_record.dataCount = data_length;
    }

    /* Read and compare checksum byte*/
    checksum = (~checksum) & 0xffu; /* low byte of one's complement of sum of other bytes */
    Repro.Fls.new_record.checksum = read_hex_byte(line, line_length - 2u);
    if (checksum != Repro.Fls.new_record.checksum)
    {
		Repro.Fls.ReproErrCode = cERR_LineParsing_CRC;
        return kRecordStatus_InvalidChecksum;
    }

    return kRecordStatus_Success;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static uint8_t bl_htoi(uint8_t hex)
{
    if ((hex >= '0') && (hex <= '9'))
    {
        return hex - '0';
    }
    else if ((hex >= 'a') && (hex <= 'f'))
    {
        return 10 + hex - 'a';
    }
    else if ((hex >= 'A') && (hex <= 'F'))
    {
        return 10 + hex - 'A';
    }

    return 0;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static uint8_t read_hex_byte(uint8_t *buffer, uint32_t index)
{
    uint8_t char_high = buffer[index];
    uint8_t char_low = buffer[index + 1u];

    return (bl_htoi(char_high) << 4u) | (bl_htoi(char_low));
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void crc16_init(crc16_data_t *crc16Config)
{
    // initialize running crc and byte count
    crc16Config->currentCrc = 0;
}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void crc16_update(crc16_data_t *crc16Config, const uint8_t *src, uint32_t lengthInBytes)
{
    uint32_t crc = crc16Config->currentCrc;

    uint32_t j;
    for (j = 0; j < lengthInBytes; ++j)
    {
        uint32_t i;
        uint32_t byte = src[j];
        crc ^= byte << 8u;
        for (i = 0; i < 8; ++i)
        {
            uint32_t temp = crc << 1;
            if (crc & 0x8000u)
            {
                temp ^= 0x1021u;
            }
            crc = temp;
        }
    }

    crc16Config->currentCrc = crc;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void FlashEraseAllUnsecure_Command_Send(void)
{
    crc16_data_t crc16_value;
    /* Command packet. */
    command_frame_packet_t flashEraseAllUnsecure_command;

    /* Packet */
    flashEraseAllUnsecure_command.framing_data.header.startByte = kFramingPacketStartByte;
    flashEraseAllUnsecure_command.framing_data.header.packetType = kFramingPacketType_Command;
    flashEraseAllUnsecure_command.framing_data.length = 0x0004;
    flashEraseAllUnsecure_command.command_data.commandTag = kCommandTag_FlashEraseAllUnsecure;
    flashEraseAllUnsecure_command.command_data.flags = 0x00;
    flashEraseAllUnsecure_command.command_data.reserved = 0x00;
    flashEraseAllUnsecure_command.command_data.parameterCount = 0x00;


    /* Claulate crc16 value */
	crc16_init(&crc16_value);
    crc16_update(&crc16_value, (uint8_t *)&flashEraseAllUnsecure_command.framing_data, sizeof(framing_data_packet_t) - sizeof(uint16_t));
    crc16_update(&crc16_value, (uint8_t *)&flashEraseAllUnsecure_command.command_data.commandTag, flashEraseAllUnsecure_command.framing_data.length);
    flashEraseAllUnsecure_command.framing_data.crc16 = crc16_value.currentCrc;

    ss_UartReproWrite((uint8_t *)&flashEraseAllUnsecure_command, sizeof(framing_data_packet_t) + flashEraseAllUnsecure_command.framing_data.length);

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void Execute_Command_Send(void)
{
    crc16_data_t crc16_value;
    /* Command packet. */
    command_frame_packet_t execute_command;

    /* Packet */
    execute_command.framing_data.header.startByte = kFramingPacketStartByte;
    execute_command.framing_data.header.packetType = kFramingPacketType_Command;
    execute_command.framing_data.length = 0x0010;
    execute_command.command_data.commandTag = kCommandTag_Execute;
    execute_command.command_data.flags = 0x00;
    execute_command.command_data.reserved = 0x00;
    execute_command.command_data.parameterCount = 0x03;
	// Note: Execute command is designed for ARM core. We don’t have arg and stackpointer in DSC core. So we use 0 for these two fields
	execute_command.param[0] = START_ADDRESS;
    execute_command.param[1] = 0u;
    execute_command.param[2] = 0u;

    /* Claulate crc16 value */
    crc16_init(&crc16_value);
    /* Claulate crc16 value */
    crc16_update(&crc16_value, (uint8_t *)&execute_command.framing_data, sizeof(framing_data_packet_t) - sizeof(uint16_t));
    crc16_update(&crc16_value, (uint8_t *)&execute_command.command_data.commandTag, execute_command.framing_data.length);
    execute_command.framing_data.crc16 = crc16_value.currentCrc;

    ss_UartReproWrite((uint8_t *)&execute_command, sizeof(framing_data_packet_t) + execute_command.framing_data.length);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void FlashEraseRegion_Command_Send(void)
{
    crc16_data_t crc16_value;
    /* Command packet. */
    command_frame_packet_t flashEraseRegion_command;

    /* Packet */
    flashEraseRegion_command.framing_data.header.startByte = kFramingPacketStartByte;
    flashEraseRegion_command.framing_data.header.packetType = kFramingPacketType_Command;
    flashEraseRegion_command.framing_data.length = 0x000c;
    flashEraseRegion_command.command_data.commandTag = kCommandTag_FlashEraseRegion;
    flashEraseRegion_command.command_data.flags = 0x00;
    flashEraseRegion_command.command_data.reserved = 0x00;
    flashEraseRegion_command.command_data.parameterCount = 0x02;
    flashEraseRegion_command.param[0] = Repro.Fls.image_start_address;
    flashEraseRegion_command.param[1] = Repro.Fls.erase_bytes;

    /* Claulate crc16 value */
    crc16_init(&crc16_value);
    crc16_update(&crc16_value, (uint8_t *)&flashEraseRegion_command.framing_data, sizeof(framing_data_packet_t) - sizeof(uint16_t));
    crc16_update(&crc16_value, (uint8_t *)&flashEraseRegion_command.command_data.commandTag, flashEraseRegion_command.framing_data.length);
    flashEraseRegion_command.framing_data.crc16 = crc16_value.currentCrc;

    ss_UartReproWrite((uint8_t *)&flashEraseRegion_command, sizeof(framing_data_packet_t) + flashEraseRegion_command.framing_data.length);

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void WriteMemory_Command_Send(void)
{
    crc16_data_t crc16_value;
    /* Command packet. */
    command_frame_packet_t writeMemory_command;

    /* Packet */
    writeMemory_command.framing_data.header.startByte = kFramingPacketStartByte;
    writeMemory_command.framing_data.header.packetType = kFramingPacketType_Command;
    writeMemory_command.framing_data.length = 0x000c;

    writeMemory_command.command_data.commandTag = kCommandTag_WriteMemory;
    writeMemory_command.command_data.flags = 0x01;
    writeMemory_command.command_data.reserved = 0x00;
    writeMemory_command.command_data.parameterCount = 0x02;
    writeMemory_command.param[0] = Repro.Fls.image_start_address;
    writeMemory_command.param[1] = Repro.Fls.image_buffer_index;


    /* Claulate crc16 value */
    crc16_init(&crc16_value);
    crc16_update(&crc16_value, (uint8_t *)&writeMemory_command.framing_data, sizeof(framing_data_packet_t) - sizeof(uint16_t)); // crc16 2byte 제외
    crc16_update(&crc16_value, (uint8_t *)&writeMemory_command.command_data.commandTag, writeMemory_command.framing_data.length);
    writeMemory_command.framing_data.crc16 = crc16_value.currentCrc;

    ss_UartReproWrite((uint8 *)&writeMemory_command, sizeof(framing_data_packet_t) + writeMemory_command.framing_data.length);

}

/***************************************************************************************************
@param[in]  void
@return     void
@note       매주기 체크
***************************************************************************************************/
/* 0108_01 */
static void ss_Repro_WctTargetVerSet(void)
{		
	if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE6)
	{
		Repro.Out.WctTargetVer[0] = cWCT_TARGET_VER1_TYPE6;
		Repro.Out.WctTargetVer[1] = cWCT_TARGET_VER2_TYPE6;
		Repro.Out.WctTargetVer[2] = cWCT_TARGET_VER3_TYPE6;	
			
	}	
	else if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE5)
	{
		Repro.Out.WctTargetVer[0] = cWCT_TARGET_VER1_TYPE5;
		Repro.Out.WctTargetVer[1] = cWCT_TARGET_VER2_TYPE5;
		Repro.Out.WctTargetVer[2] = cWCT_TARGET_VER3_TYPE5;
	}
	else if(Repro.Inp_NvM.WPC_TYPE == cWPC_TYPE4)
	{
		Repro.Out.WctTargetVer[0] = cWCT_TARGET_VER1_TYPE4;
		Repro.Out.WctTargetVer[1] = cWCT_TARGET_VER2_TYPE4;
		Repro.Out.WctTargetVer[2] = cWCT_TARGET_VER3_TYPE4;
	}
	else
	{
		Repro.Out.WctTargetVer[0] = '0';
		Repro.Out.WctTargetVer[1] = '0';
		Repro.Out.WctTargetVer[2] = '0';
	}
}
/* 0108_01 */


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Repro_WctReproRequestCheck(void) /* 010A_02 */
{
	if((Repro.Int.ReproRetryCnt >= WCT_REPRO_RETRY_CNT) && // 리트라이 횟수 초과.
	(Repro.Fls.ReproFlashStatus == FLASH_ERROR)) // 에러 여부와 무관하게 중지해야 하는것 아닌가?
	{
		Repro.Int.ReproRequest = cReproReq_Error; 
		//Repro.Out.m_WctReproRequest = OFF;// 리프로 완료시에만 off해야함
	}
	else if(
#if !defined (WCT_REPROGRAM_OFF)	
	((Repro.Out.m_WctReproRequest == OFF) &&
	(Repro.Inp_Uds.TestPresent == ON) &&	
	(Repro.Out.WctVerCheck == cVerCheck_Unmatch) &&
	(Repro.Fls.ReproFlashStatus != FLASH_COMPLETED) &&
	(Repro.Fls.ReproFlashStatus != FLASH_COMPLETE_UNMATCH)) ||
#endif		
	(Repro.Out.m_WctReproRequest == ON) ||
	(Repro.Int.Repro_Start_Evt.On_Event == ON))
	{
		Repro.Out.m_WctReproRequest = ON;		// 조건 만족시 on되고 그 이후는 리프로 정상 종료되어m_WctReproRequest = off 될때까지 진입 안됨
		
		if(Repro.Int.Repro_Start_Evt.On_Event == ON)
		{
			Repro.Int.ReproRetryCnt = 0;		// Canoe에 의해서 요청시에는 리트라이 카운트 초기화. 그외에는 초기화 하지 않음
		}
				
		Repro.Int.ReproRequest = cReproReq_On; 	// 리프로 요청
	}
	else if((Repro.Out.m_WctReproRequest == OFF) ||
	(Repro.Int.Repro_Start_Evt.Off_Event == ON) ||
	(Repro.Fls.ReproFlashStatus == FLASH_COMPLETED) ||
	(Repro.Fls.ReproFlashStatus == FLASH_COMPLETE_UNMATCH))
	{
		Repro.Int.ReproRequest = cReproReq_Off; // 리프로 불필요
		//Repro.Out.m_WctReproRequest = OFF; // 리프로 완료시에만 off해야함
	}
	else
	{
		// QAC
	}
	
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
// 버전 미스 매치 일때 어떻게 처리 할것인지 검토 필요.
// 계속 리셋 할것인지? 아니면 리프로 할것인지? 아니면 일단 동작은 할것인지
// 1.휴먼 에러로 업데이트는 맞는데 버전 표기만 잘못한 경우 : 리프로 불필요
// 2.실제로 잘못된 버전이 업데이트 된 경우 : 오동작하므로 외부에 에러 상태 알려줄 필요 있음. DTC : ?
/* 0108_03 */
// 버전이 읽어지지 않을 경우에는 어떻게 할것인가?
// 3-state로 flag 전달하여 별도 조치 필요할듯.
static void ss_Repro_WctVerUnMatchCheck(void)
{
	if(Repro.Inp_UART.WctUartCommReady == ON) // 최초 통신으로 버전 수신 완료
	{
		if((Repro.Inp_UART.WctSourceVer[0] != Repro.Out.WctTargetVer[0] ) ||
		(Repro.Inp_UART.WctSourceVer[1] != Repro.Out.WctTargetVer[1] ) ||
		(Repro.Inp_UART.WctSourceVer[2] != Repro.Out.WctTargetVer[2] ))
		{
			Repro.Out.WctVerCheck = cVerCheck_Unmatch;	
		}
		else
		{
			Repro.Out.WctVerCheck = cVerCheck_Match;	
		}
	}
	else
	{		
		if(Repro.Int.WctVerReadCnt < Par_VerReadTimeoutTime)
		{
			Repro.Int.WctVerReadCnt ++;
		}	
		
		if(Repro.Int.WctVerReadCnt >= Par_VerReadTimeoutTime)
		{
			Repro.Out.WctVerCheck = cVerCheck_Error;
		}			
	}	
}
/* 0108_03 */

/***************************************************************************************************
@param[in]  void
@return     void
@note
*/
/*
Uart Write Function
***************************************************************************************************/
static void ss_UartReproWrite(uint8_t *TxDataBuf, uint8_t length)
{
	uint8_t BreakCnt;

	BreakCnt = 0;
	while(Cy_SCB_UART_IsTxComplete(SCB4) != true)// Tx 완료 확인
	{
		BreakCnt ++;
		if(BreakCnt >= 100u)	// 무한루프 진입 방지
		{
			break;
		}
	};
	Cy_SCB_UART_PutArray(SCB3, TxDataBuf, length);		// 4byte Tx 송신 시작

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_Repro_L2H_Set(void)
{
	//Repro.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
	// sleep에서 wakeup 될때는 리프로 동작 하면 안됨.
	// 전원 리셋시에만 동작해야하므로  주석처리함.
}

/***************************************************************************************************
@param[in]  void
@return     void
@note

***************************************************************************************************/
void    gs_App_Repro_H2L_Set(void)
{


}



/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Repro_LPConditionCheck(void)
{
	if((Repro.Int.StateCurr != cRepro_Disable))
	{
		Repro.Out.Repro_LPConditionFlag = OFF;	// Active
	}
	else
	{
		Repro.Out.Repro_LPConditionFlag = ON;	// Sleep
	}
}





#define App_Repro_STOP_SEC_CODE
#include "App_Repro_MemMap.h"
