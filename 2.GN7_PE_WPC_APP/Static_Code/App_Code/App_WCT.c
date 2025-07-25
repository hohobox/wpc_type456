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
#include "App_WCT.h"
#include "Rte_App_WCT.h"

#include "App_Repro.h"
#include "App_UART.h"
#include "App_NFC.h"
#include "App_NvM.h"
#include "App_Model_types.h"

#define App_WCT_START_SEC_CODE
#include "App_WCT_MemMap.h"


/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

#define Par_InitPowerResetWaitTime  	(0u    / TIME_10MS) // wct 전원 Off 유지 시간 (충전 IC 최초 전원 인가시에는 처음부터 off 상태이므로 off 유지 없이 즉시 천이 하기 위함)
#define Par_PowerResetWaitTime   		(250u  / TIME_10MS) // wct 전원 Off 유지 시간 (충전 IC 확실한 리셋 발생을 위해서 GND 유지시간)
#define Par_ChargingOnThePadWaitTime	(2000u / TIME_10MS)	// 패드위 폰거치 여부 판단 최대 대기 시간
#define Par_ObjectOnThePadWaitTime		(2000u / TIME_10MS)	// 패드위 Object거치 여부 판단 최대 대기 시간
//#define Par_CardProtectionBlinkTime		(4000u / TIME_10MS)	/* 010E_04 */ // 멀티카드 검출로 LED 인디케이터 출력 시간동안 대기 하는 시간 (1초 on/off 2회)
#define Par_CardProtectionCheckTime		(2000u / TIME_10MS)	// 카드 프로텍션 체크 최대 대기 시간 // spec은 500ms 이나 아직 안정화되지 않아서 1초로 설정함

#define VCRM_CLEAR_CNT						5u
#define ManufactureID_APPLE				0x005Au

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
typedef enum
{
	cCardProtection_None,
	cCardProtection_Start,
	cCardProtection_ObjectCheck,
	cCardProtection_Judge,
	cCardProtection_Retry,
} CardProtect_t;

typedef enum
{
	Tim_PowerResetWait,
	Tim_ObjectOnThePadWait,
	Tim_ChargingOnThePadWait,
	Tim_CardProtectionRetry,
	//Tim_CardProtectionBlink,
	Tim_WCT_MAX
}WCT_TMR_ENUM_t;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

typedef struct
{
	uint8_t Runnable_State;
	uint8_t App_Init_Completed;

	WCTStatus_t StateCurr[Device_MAX];
	WCTStatus_t StateNext[Device_MAX];
	WCTStatus_t StateOld[Device_MAX];
	uint8_t EntryCnt[Device_MAX];
	uint8_t ExitCnt[Device_MAX];
	uint8_t SeftTransition[Device_MAX];

	uint8_t PwrRstWaitComplete[Device_MAX];

	Event_t DeviceState_Evt[Device_MAX];
	Event_t WPCStatus_Evt[Device_MAX];
	Event_t IGN1_IN_Evt;
	Event_t ObjectDetection_Evt[Device_MAX];
	Event_t PhoneLeft_Evt[Device_MAX];	
	
	CardProtect_t CardProtection_State[Device_MAX];
	UartCmd_t UartTxCmd[Device_MAX];
	
	uint8_t CardProtection_Running[Device_MAX];
	
	Event_t Repro_Start_Evt;
	
	uint16_t Var_PwrResetWaitTime[Device_MAX];
	
	uint8_t WctLibTypeUnmatch;
	uint8_t WctPowerResetInitFlag;
	
}Inter_t;

typedef struct
{
	IDT_Repro_STR 	Inp_Repro;

	IDT_UART_STR 	Inp_UART;
	IDT_Model_STR	Inp_Model;
	IDT_CAN_RX_STR 	Inp_CAN_RX;
	IDT_ADC_STR 	Inp_ADC;
	IDT_Uds_STR 	Inp_Uds;
	IDT_PWM_STR		Inp_PWM;
	IDT_Diag_STR 	Inp_Diag;
	IDT_NFC_STR		Inp_NFC;
	IDT_DTC_STR		Inp_DTC;
	IDT_NvM_STR   Inp_NvM;

	Inter_t 		Int;
	Timer_t 		Timer[Device_MAX][Tim_WCT_MAX];

	IDT_WCT_STR		Out;
} WCT_struct;


static WCT_struct WCT = {0};

/***************************************************************************************************
    GLOBAL VARIABLES AND CONSTANTS
***************************************************************************************************/
// // 함수 포인터 배열 초기화
// FunctionPtr pRte_Read_R_WCT[] =
// {
//     Rte_Read_R_WCT_STR, // 배열로 하고 싶은 함수 명
// };


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/

static void ss_WCT_InitSet(void);
static void ss_WCT_Data_Init(uint8_t Device);

static void ss_WCT_StateMachine(uint8_t Device, WCTStatus_t CurrState, uint8_t action);
static void ss_WCT_Repro(uint8_t Device, uint8_t action);
static void ss_WCT_Disable(uint8_t Device, uint8_t action);
static void ss_WCT_Charge_Allow(uint8_t Device, uint8_t action);
static void ss_WCT_Enable(uint8_t Device, uint8_t action);
static void ss_WCT_Phone_Left(uint8_t Device, uint8_t action);
static void ss_WCT_ObjectDetection(uint8_t Device, uint8_t action);
static void ss_WCT_CardProtection(uint8_t Device, uint8_t action);
static void ss_WCT_Charge_Prohibit(uint8_t Device, uint8_t action);

static void ss_WCT_LPConditionCheck(uint8_t Device);
static void ss_WCT_RteRead(void);
static void ss_WCT_RteWrite(void);

static void ss_WCT_PowerResetCheck(uint8_t Device);
static void ss_WCT_PowerResetWaitTimeCheck(uint8_t Device);
static void ss_WCT_ObjectOnThePadCheck(uint8_t Device);
static void ss_WCT_ChargingOnThePadCheck(uint8_t Device);

static void ss_WCT_VCRM_Monitor(uint8_t Device);
static void ss_WCT_LibTypeUnmatch(void);


/*#################################################################################################
    GLOBAL FUNCTIONS
#################################################################################################*/


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_WCT_CODE) WCT_TE_Runnable(void)
{
	uint8_t DeviceMaxCnt;
		
	switch(WCT.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&WCT.Int.App_Init_Completed);

			if( WCT.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
								
				// WPC 모델에서 WPC_Init() 실행하여 초기화 하는줄 알고 있었으나 실제로는 호출하지 않고 있었음
				// 즉 지금까지 버그인 상태였음.
				// 그런데 모델에서는 WPC_Init()을 모델에서 생성된 소스 코드로는 호출하는 방법을 찾지 못하고 있음.
				// 그래서 대신 모빌진에서 비주기 runnable task를 만들어서 그 함수에서 WPC_Init()처리를 하도록 변경함.
				// WCT init할때 아래 비주기 실행 rte를 호출해서 대신 WPC_Init()을 실행하는 것으로 로직 설계함.

				//Rte_Trigger_TriggerInterface_WPC_Init_Trigger_WPC_Init();	// WPC_415_03 // WPC_412_06 // 모델 WPC_Init_Runnable() 함수 호출

				// 결론 : 모델의 WPC_Init() 함수는 dummy 함수임. 사용하지 않은 함수 이므로 호출 불필요함.

				/* SWC Init Process */
				ss_WCT_InitSet();

				WCT.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */

			}
		break;

		case 1u:

			// 전체 State 중에 특정 State Machine만 병렬 처리 해야 하나
			// 로직 구현이 복잡하여 전체 State Machine 을 병렬 처리 하도록
			// 로직 구성한다. (2회 반복 실행)

			// 원래는 병렬 처리 State 와 병렬처리 하지 않아야 하는 State의
			// State 처리 변수를 각각 다르게 설정해야 하나
			// 단순화를 위해서 동일한 변수를 사용한다.

			// 대신 병렬 처리 하지 말아야 하는 Repro, Diag 실행시에
			// 플래그만 설정하고 다른 타스크에서 실행하므로 2번 실행해도(동일 flag2회 설정할뿐)
			// 문제 될것이 없으므로 Device별 State 통일성을 위해서 2회 실행한다.

			//------------------------------------------------------
			// Input
			//------------------------------------------------------				
			ss_WCT_RteRead();
				
			DeviceMaxCnt = WCT.Inp_NvM.DeviceMaxCnt; // CodeSonar : Fix Potential Unbounded Loop			
			
			for(uint8_t Device = 0; Device < DeviceMaxCnt; Device++)	// WCT Device0, Device1 독립제어용으로 변경함.
			{				
				//------------------------------------------------------
				// Control Logic
				//------------------------------------------------------	
				
				WCT.Int.SeftTransition[Device] = OFF;	// 매주기 클리어 처리
				
				ss_WCT_StateMachine(Device, WCT.Int.StateCurr[Device], DURING);

				// 상태 천이 발생시에만 실행
				if ((WCT.Int.StateCurr[Device] != WCT.Int.StateNext[Device]) ||
				(WCT.Int.SeftTransition[Device] == ON))	// Self Transition
				{
					ss_WCT_StateMachine(Device, WCT.Int.StateCurr[Device], EXIT);
					ss_WCT_StateMachine(Device, WCT.Int.StateNext[Device], ENTRY);

					WCT.Int.StateOld[Device] = WCT.Int.StateCurr[Device]; // 다시 통합처리 방식으로 변경. 문제 있는지 확인 필요.
					WCT.Int.StateCurr[Device] = WCT.Int.StateNext[Device];
				}

				//------------------------------------------------------
				// Timer
				//------------------------------------------------------
														// 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
				gs_UpdateTimer(&WCT.Timer[Device][0], (uint8_t)Tim_WCT_MAX);	// device 별로 업데이트
				
				ss_WCT_VCRM_Monitor(Device);

				ss_WCT_LPConditionCheck(Device);
			}
			
			//-----------------------------------------------------
			// Output
			//------------------------------------------------------
				
			ss_WCT_RteWrite();			

		break;

		default:
			WCT.Int.Runnable_State = 0u;
		break;
	}
}



/*#################################################################################################
    LOCAL FUNCTIONS
#################################################################################################*/

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_RteRead(void)
{
	uint8_t DeviceMaxCnt;
	// 2회 호출되도 상관없음. 동일한 동작을 반복할뿐 로직에 영향은 없음
	// 구조 단순화를위해서 2회 호출하는것으로 함.
	
	// 구조체로 수신
	Rte_Read_R_Model_Model_STR(&WCT.Inp_Model);
	Rte_Read_R_UART_UART_STR(&WCT.Inp_UART);
	Rte_Read_R_CAN_RX_CAN_RX_STR(&WCT.Inp_CAN_RX);
	Rte_Read_R_ADC_ADC_STR(&WCT.Inp_ADC);
	Rte_Read_R_Repro_Repro_STR(&WCT.Inp_Repro);
	Rte_Read_R_Uds_Uds_STR(&WCT.Inp_Uds);
	Rte_Read_R_PWM_PWM_STR(&WCT.Inp_PWM);
	Rte_Read_R_Diag_Diag_STR(&WCT.Inp_Diag);
	Rte_Read_R_NFC_NFC_STR(&WCT.Inp_NFC);
	Rte_Read_R_DTC_DTC_STR(&WCT.Inp_DTC);
	Rte_Read_R_NvM_NvM_STR(&WCT.Inp_NvM);
	
	DeviceMaxCnt = WCT.Inp_NvM.DeviceMaxCnt; // CodeSonar : Fix Potential Unbounded Loop

	for(uint8_t Device = 0; Device < DeviceMaxCnt; Device++)	// WCT Device0, Device1 독립제어용으로 변경함.
	{	
		// On Off Request 신호 이외에는 수신처에서 판단 처리 하도록 하자.
		gs_UpdateEvent(WCT.Inp_Model.Device[Device].WPCStatus, &WCT.Int.WPCStatus_Evt[Device]);				// event update
		gs_UpdateEvent(WCT.Inp_UART.Device_WCT[Device].DeviceState, &WCT.Int.DeviceState_Evt[Device]);	// event update
		gs_UpdateEvent(WCT.Inp_UART.Device_WCT[Device].ObjectDetection, &WCT.Int.ObjectDetection_Evt[Device]);	// event update
		gs_UpdateEvent(WCT.Inp_UART.Device_WCT[Device].PhoneLeft, &WCT.Int.PhoneLeft_Evt[Device]);	/* 010E_04 */ // event update
		
	}
	
	gs_UpdateEvent(WCT.Inp_ADC.IGN1_IN, &WCT.Int.IGN1_IN_Evt);	// event update
	gs_UpdateEvent(WCT.Inp_Uds.WCT_DiagReproStart, &WCT.Int.Repro_Start_Evt);	// event update
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_RteWrite(void)
{
	uint8_t DeviceMaxCnt = WCT.Inp_NvM.DeviceMaxCnt; // CodeSonar : Fix Potential Unbounded Loop
	
	for(uint8_t Device = 0; Device < DeviceMaxCnt; Device++)	// WCT Device0, Device1 독립제어용으로 변경함.
	{	
		WCT.Out.Device[Device].WCT_Status = (uint8_t)WCT.Int.StateCurr[Device];
		WCT.Out.Device[Device].UartTxCmd = (uint8_t)WCT.Int.UartTxCmd[Device];
	}

	// 타 SWC에 RTE로 전달

	// mx5에서는 DrDoorPhnLftHoldComplete 이 신호를 이벤트 방식으로 자동으로 클리어 처리 했었음.
	// dual에서는 적용하지 않음.
	// 일단 ig on하면 클리어 되도록 처리는 되어 있음.
	// 하지만 lpcd --> off, picc --> off, wpc --> off 모드로 천이 할때 항상 초기화 처리가 되는지 확인 필요함.
	// 항상 초기화 처리가 안된다면 아래 처럼 이벤트 자동 클리어 처리 추가 해야함.
	// 어플리케이션에서 항상 WCT_Data_Init() 이 호출되서 DrDoorPhnLftHoldComplete가 클리어 처리되면 아래 이벤트 클리어 처리는 불필요함.

	// 신호 생성처에서 이벤트 신호로 방식으로 송신하도록 설계함. (이벤트 3회 default 3회 송신)
	// 이벤트 메세지는 RTE로 송신시에도 120ms on 유지후 off로 자동 변경
	// 아래 함수는 입력되는 값이이 1로 변경후 1을 계속 유지 하더라도 함수내에서 120ms 후에는 0으로 변경시킨다.
	// gs_EventMsgAutoClear(&WCT.Out[D0].DrDoorPhnLftHoldComplete, &WCT.Int.DrDoorPhnLftHoldComplete_Evt[D0], Par_CanAutoClearTime);
	// gs_EventMsgAutoClear(&WCT.Out[D1].DrDoorPhnLftHoldComplete, &WCT.Int.DrDoorPhnLftHoldComplete_Evt[D1], Par_CanAutoClearTime);

	Rte_Write_P_WCT_WCT_STR(&WCT.Out);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_InitSet(void)
{		
	uint8_t DeviceMaxCnt;
	
	// 전원제어 간단하게 변경함.
	// wakeup 시 on, sleep시 off
	Rte_Call_R_VBAT_SW_CTRL_WriteDirect(ON);	// 12v 제어, WPC, NFC 공통으로 사용
		
	Rte_Read_R_NvM_NvM_STR(&WCT.Inp_NvM); // NvM 값을 먼저 읽어와야 함.
	
	WCT.Out.NormalUartStart = OFF;
	WCT.Out.ReproUartStart = OFF;
	
	DeviceMaxCnt = WCT.Inp_NvM.DeviceMaxCnt; // CodeSonar : Fix Potential Unbounded Loop
			
	for(uint8_t Device = 0; Device < DeviceMaxCnt; Device++)
	{
		memset(&WCT.Out.Device[Device], 0, sizeof(WCT.Out.Device[Device]));  				// 구조체 변수를 0으로 클리어, Parsing관련 변수는 초기화하면 파싱을 다시 해야 하므로 초기화하지 않도록함.

		WCT.Int.StateCurr[Device] = cWCT_Disable;
		WCT.Int.StateNext[Device] = cWCT_Disable;
		WCT.Int.StateOld[Device] = cWCT_Disable;
		WCT.Int.EntryCnt[Device] = 0u;
		WCT.Int.ExitCnt[Device] = 0u;
		WCT.Int.SeftTransition[Device] = OFF;

		// 충전 IC 전원 OFF상태에서 악의 조건으로 폰방치 동작시 최대한 빨리 진입하도록 하기 위함.
		// ss_WCT_Disable(Device, ENTRY) 실행 전에 아래 변수를 설정해야함.
		WCT.Int.Var_PwrResetWaitTime[Device] = Par_InitPowerResetWaitTime; // 충전 IC 최초 전원 인가시 즉시 상태 천이 가능하도록 0 설정
		WCT.Int.WctPowerResetInitFlag = ON; /* 010A_10 */ // 최초 전원인가시, 슬립에서 wakeup시에 ON하여 충전IC 리셋 발생하도록 하는 플래그
					
		ss_WCT_Disable(Device, ENTRY);	// 전원 리셋시 WCT_Stop 의 Entry를 강제로 1회 실행시켜줘야함.// 초기화 함수가 호출됨.
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Wct Data initialize
***************************************************************************************************/
static void ss_WCT_Data_Init(uint8_t Device)
{	
	WCT.Int.UartTxCmd[Device] = cChargeStop;
	//WCT.Int.PwrRstWaitComplete[Device] = OFF;	// 로직에서 타이머 시작할때 클리어 처리하도록 함.
	WCT.Int.CardProtection_State[Device] = cCardProtection_None;

	gs_InitTimer(&WCT.Timer[Device][0], (uint8_t)Tim_WCT_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
}


/***************************************************************************************************
@param[in]  CurrState : Current State
@param[in]	Command : En, Do, Ex Condition
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_StateMachine(uint8_t Device, WCTStatus_t CurrState, uint8_t action)
{
	switch (CurrState)
	{

		case cWCT_Disable:
			ss_WCT_Disable(Device, action);
		break;

		case cWCT_Enable:
			ss_WCT_Enable(Device, action);
		break;

		case cWCT_ObjectDetection:
			ss_WCT_ObjectDetection(Device, action);
		break;

		case cWCT_CardProtection:
			ss_WCT_CardProtection(Device, action);
		break;

		case cWCT_Charge_Prohibit:
			ss_WCT_Charge_Prohibit(Device, action);
		break;

		case cWCT_Charge_Allow:
			ss_WCT_Charge_Allow(Device, action);
		break;

		case cWCT_Phone_Left:
			ss_WCT_Phone_Left(Device, action);
		break;

		case cWCT_Repro: // 플래그만 설정하고 다른 타스크에서 실행하므로 2번 실행해도 무방함
			ss_WCT_Repro(Device, action);
		break;

		default:
		// rule 16.4
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_Disable(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// Rte_Call_R_VCC33_CTRL_WriteDirect(OFF);
		// Rte_Call_R_VBAT_SW_CTRL_WriteDirect(OFF);

		WCT.Int.UartTxCmd[Device] = cChargeStop;
		
		ss_WCT_Data_Init(Device);
		
		ss_WCT_PowerResetCheck(Device); /* 010A_10 */
		
 		// gs_StartTimer(&WCT.Timer[Device][Tim_PowerResetWait]); /* 010A_10 */ // ss_WCT_PowerResetCheck()함수에서 조건에 따라 판단하도록 수정
		
		// 전원제어 이므로 devcie1일때 1회만 해보자. 그런데 Type4일때는 어차피 한번만 실행되므로 조심해야함.
		// 지금은 문제점 테스트 용.

		ss_WCT_PowerResetWaitTimeCheck(Device);	 // 즉시 실행해야 WCT.Int.PwrRstWaitComplete = OFF로 클리어 처리됨

		break;


	case DURING:

		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{			
		// State's Transitions	
				
			if(//(WCT.Inp_ADC.BatSysStateFault == OFF) && // 리프로는 전원 조건 삭제
			(WCT.Int.PwrRstWaitComplete[Device] == ON) &&
			(WCT.Inp_Repro.ReproRequest == cReproReq_On))
			{
				WCT.Int.StateNext[Device] = cWCT_Repro;
				WCT.Int.EntryCnt[Device] = 0u; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0u;  // Ex 실행 : None
			}		
			else if((WCT.Inp_Model.Device[Device].WPCStatus == WPCMode) &&
			(WCT.Inp_Model.Device[Device].ChargingEnable == ON) &&
			(WCT.Inp_ADC.BatSysStateFault == OFF) &&
			(WCT.Int.PwrRstWaitComplete[Device] == ON) &&		
			(WCT.Inp_Uds.WCT_DiagReproStart == OFF) &&
			(WCT.Inp_Repro.ReproRequest != cReproReq_On) &&
			(WCT.Inp_Uds.DiagAmberBlink == OFF) &&
			(WCT.Inp_Uds.DiagGreenBlink == OFF) &&
			(WCT.Inp_Uds.DiagFanRotate == OFF))
			{
#if defined (DEBUG_CARD_PROTECTION_NOT_USE)
				WCT.Int.StateNext[Device] = cWCT_Charge_Allow;
#else
				WCT.Int.StateNext[Device] = cWCT_ObjectDetection;
#endif							
				WCT.Int.EntryCnt[Device] = 1u; // En 실행 : WCT_Enable
				WCT.Int.ExitCnt[Device] = 0u;  // Ex 실행 : None
			}
/* 010E_15 */			
			else if (WCT.Inp_UART.WctUartRxTimeout == (uint8_t)DETECTED_ON)
			{
				WCT.Int.StateNext[Device] = cWCT_Disable;
				WCT.Int.EntryCnt[Device] = 0u; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0u;  // Ex 실행 : None	
				
				WCT.Int.SeftTransition[Device] = ON;	// self transition 요청
			}
/* 010E_15 */			
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_WCT_PowerResetWaitTimeCheck(Device);
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

 		gs_CancelTimer(&WCT.Timer[Device][Tim_PowerResetWait]);

		break;

	/********************************************************/
	default:
		// rule 16.4
		break;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_Enable(uint8_t Device, uint8_t action)
{

	switch (action)
	{

	case ENTRY:

		// Rte_Call_R_VCC33_CTRL_WriteDirect(ON);
		// Rte_Call_R_VBAT_SW_CTRL_WriteDirect(ON);
		
		//WCT.Out.NormalUartStart = ON;
		break;


	case DURING:


		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{

			// State's Transitions
			//if((WCT.Inp_ADC.IGN1_IN == OFF) &&
			if(// (WCT.Int.IGN1_IN_Evt.Off_Event == ON) && // ign 신호는 판단하지 않도록 변경. 이미 ign 엣지 신호로 WPCStatus가 판단되어지므로.
/* 010E_16 */			
			// (WCT.Inp_Model.Device[Device].WPCStatus == ModeOff))
			(WCT.Inp_Model.Device[Device].PhnLeftChk_Enable == ON))
/* 010E_16 */			
			{
				WCT.Int.StateNext[Device] = cWCT_Phone_Left;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 1u;  // Ex 실행 : WCT_Start
			}			
			else if((WCT.Inp_ADC.BatSysStateFault == ON) ||
			(WCT.Inp_Model.Device[Device].WPCStatus != WPCMode) ||
			(WCT.Inp_Model.Device[Device].ChargingEnable == OFF) ||
#if !defined (DEBUG_UART_NOT_RESET_USE)
			(WCT.Inp_UART.WctUartRxTimeout == (uint8_t)DETECTED_ON) ||
#endif
			(WCT.Inp_Uds.WCT_DiagReproStart == ON) ||
			((WCT.Inp_Uds.DiagAmberBlink == ON) ||
			(WCT.Inp_Uds.DiagGreenBlink == ON) ||
			(WCT.Inp_Uds.DiagFanRotate == ON)) ||
			(WCT.Int.WctLibTypeUnmatch == ON) ||/* 0108_12 */
			(WCT.Inp_Repro.ReproRequest == cReproReq_On))
			{
				// 원래는 StateOld 값 비교해가면서 exitCnt 설정해야 하나
				// depth가 모두 동일하여 별도 판단하지 않는다.
				WCT.Int.StateNext[Device] = cWCT_Disable;
				WCT.Int.EntryCnt[Device] = 0u; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 1u;  // Ex 실행 : WCT_Start
			}			
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_WCT_LibTypeUnmatch();/* 0108_12 */
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		//WCT.Out.NormalUartStart = OFF;
		break;

	/********************************************************/
	default:
		// rule 16.4
		break;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
폰방치 동작 중 uart 통신 에러 발생시 폰 없는 것으로 판정된다.
폰방치 동작중 uart 통신 에러 여부까지 판정하여 처리 하더라도
통신 에러로 인해서 폰방치 여부를 판단할수 없다고 클러스터에 알려줄수도 없다.
그러므로 그냥 폰방치중 통신 에러 여부까지는 고려하지 않는다.
어차피 통신에러이므로 wpc가 비정상 동작이고 이때 판정된 폰방치 플래그 또한 비정상이다.

***************************************************************************************************/
static void ss_WCT_Phone_Left(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		WCT.Int.UartTxCmd[Device] = cPhoneLeft;

		break;

	case DURING:

		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			// State's Transitions
			if((WCT.Inp_Model.Device[Device].WPCStatus != ModeOff) ||	// NFC 서칭등의 동작시
			((WCT.Inp_Model.Device[Device].PhnLeftChk_Enable == OFF) && // 폰방치 종료시
			(WCT.Inp_ADC.IGN1_IN == OFF))	||
			(WCT.Inp_Uds.WCT_DiagReproStart == ON)) /* 0108_05 */
			{
				WCT.Int.StateNext[Device] = cWCT_Disable;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else if((WCT.Inp_Model.Device[Device].PhnLeftChk_Enable == OFF) && // 폰방치 종료시
			(WCT.Inp_ADC.IGN1_IN == ON))			
			{
#if defined (DEBUG_CARD_PROTECTION_NOT_USE)
				WCT.Int.StateNext[Device] = cWCT_Charge_Allow;
#else
				WCT.Int.StateNext[Device] = cWCT_ObjectDetection;
#endif		
				WCT.Int.EntryCnt[Device] = 1; // En 실행 : WCT_Enable
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
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

	//==============================================================
	default:
		// rule 16.4
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_ObjectDetection(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		if (WCT.Int.EntryCnt[Device] > 0u)
		{
			WCT.Int.EntryCnt[Device]--;

			ss_WCT_Enable(Device, ENTRY);
		}

		// 2. 하위(자식) Level State en 실행

		WCT.Int.UartTxCmd[Device] = cObjectDetect;

		gs_StartTimer(&WCT.Timer[Device][Tim_ObjectOnThePadWait]);
		WCT.Out.Device[Device].ObjectOnthePad = (uint8_t)DETECTED_DEFAULT;

		ss_WCT_ObjectOnThePadCheck(Device);

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
	  	ss_WCT_Enable(Device, DURING); // 차 상위 Duration 실행

		// 2. 하위(자식) Level State Transition 조건 확인
		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			// State's Transitions
			// 카드프로텍션 감지가 한쪽이 시작되면 상대쪽은 실행하지 않도록 하기 위해서 추가함.
			// 상대쪽 카드프로텍션 감지가 완료되면 ss_WCT_CardProtection() exit 처리에서
			// WCT.Int.CardProtection_Running[Device] = OFF; 처리하여
			// 상대쪽 물체 감지가 시작되도록 한다.
			// 이렇게 하면 동시에 카드프로텍션 요청이 발생하지 않는다.
			if((WCT.Out.Device[Device].ObjectOnthePad == DETECTED_ON) &&
			(WCT.Int.CardProtection_Running[1u - Device] == OFF))
			{
				WCT.Int.StateNext[Device] = cWCT_CardProtection;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None

				WCT.Int.CardProtection_Running[Device] = ON;
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_WCT_ObjectOnThePadCheck(Device);
			}

			//WCT.Int.StateOld[Device] = WCT.Int.StateCurr[Device]; // OldState 갱신
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행

		WCT.Int.UartTxCmd[Device] = cChargeStop;
		
		gs_CancelTimer(&WCT.Timer[Device][Tim_ObjectOnThePadWait]);
		WCT.Out.Device[Device].ObjectOnthePad = (uint8_t)DETECTED_DEFAULT;		

		// 2. 상위(부모) Level State ex 실행
		if (WCT.Int.ExitCnt[Device] > 0u)
		{
			WCT.Int.ExitCnt[Device]--;

			ss_WCT_Enable(Device, EXIT);
		}


		break;

	//==============================================================
	default:
		// rule 16.4
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_CardProtection(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		if (WCT.Int.EntryCnt[Device] > 0u)
		{
			WCT.Int.EntryCnt[Device]--;

			ss_WCT_Enable(Device, ENTRY);
		}

		// 2. 하위(자식) Level State en 실행

		WCT.Int.UartTxCmd[Device] = cChargeStop;

		WCT.Out.Device[Device].CardProtectionReq = ON; // NFC 모듈에 card 검출 요청

		gs_StartTimer(&WCT.Timer[Device][Tim_CardProtectionRetry]);

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
		ss_WCT_Enable(Device, DURING); // 차 상위 Duration 실행

		// 2. 하위(자식) Level State Transition 조건 확인
		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			// State's Transitions
			if(WCT.Inp_NFC.Device[Device].CardProtectionResult == (uint8_t)cCardProtectionResult_ProhibitCharging)
			{
				WCT.Int.StateNext[Device] = cWCT_Charge_Prohibit;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else if(WCT.Inp_NFC.Device[Device].CardProtectionResult == (uint8_t)cCardProtectionResult_AllowCharging)
			{

				WCT.Int.StateNext[Device] = cWCT_Charge_Allow;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else if(WCT.Timer[Device][Tim_CardProtectionRetry].Count >= Par_CardProtectionCheckTime)
			{
				WCT.Int.StateNext[Device] = cWCT_ObjectDetection;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행

			}

			//WCT.Int.StateOld[Device] = WCT.Int.StateCurr[Device]; // OldState 갱신
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행

		WCT.Out.Device[Device].CardProtectionReq = OFF;
		gs_CancelTimer(&WCT.Timer[Device][Tim_CardProtectionRetry]);

		WCT.Int.CardProtection_Running[Device] = OFF;

		// 2. 상위(부모) Level State ex 실행
		if (WCT.Int.ExitCnt[Device] > 0u)
		{
			WCT.Int.ExitCnt[Device]--;

			ss_WCT_Enable(Device, EXIT);
		}


		break;

	//==============================================================
	default:
		// rule 16.4
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_Charge_Prohibit(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		if (WCT.Int.EntryCnt[Device] > 0u)
		{
			WCT.Int.EntryCnt[Device]--;

			ss_WCT_Enable(Device, ENTRY);
		}

		// 2. 하위(자식) Level State en 실행

		//WCT.Int.UartTxCmd[Device] = cChargeStop; /* 010E_04 */
		WCT.Int.UartTxCmd[Device] = cPhoneLeft; /* 010E_04 */

		//gs_StartTimer(&WCT.Timer[Device][Tim_CardProtectionBlink]); /* 010E_04 */

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
	  	ss_WCT_Enable(Device, DURING); // 차 상위 Duration 실행

		// 2. 하위(자식) Level State Transition 조건 확인
		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			// State's Transitions
			//if(WCT.Timer[Device][Tim_CardProtectionBlink].Count >= Par_CardProtectionBlinkTime) /* 010E_04 */	
			if(WCT.Int.PhoneLeft_Evt[Device].Off_Event == ON) // 휴대폰 제거시 /* 010E_04 */
			{
				WCT.Int.StateNext[Device] = cWCT_ObjectDetection;
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
			}

			//WCT.Int.StateOld[Device] = WCT.Int.StateCurr[Device]; // OldState 갱신
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행

		//gs_CancelTimer(&WCT.Timer[Device][Tim_CardProtectionBlink]);/* 010E_04 */
 
		// 2. 상위(부모) Level State ex 실행
		if (WCT.Int.ExitCnt[Device] > 0u)
		{
			WCT.Int.ExitCnt[Device]--;

			ss_WCT_Enable(Device, EXIT);
		}


		break;

	//==============================================================
	default:
		// rule 16.4
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_Charge_Allow(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		// 1. 상위(부모) Level State en 실행
		if (WCT.Int.EntryCnt[Device] > 0u)
		{
			WCT.Int.EntryCnt[Device]--;

			ss_WCT_Enable(Device, ENTRY);
		}

		// 2. 하위(자식) Level State en 실행
		WCT.Int.UartTxCmd[Device] = cChargeStart;

		gs_StartTimer(&WCT.Timer[Device][Tim_ChargingOnThePadWait]);
		WCT.Out.Device[Device].ChargingOnthePad = (uint8_t)DETECTED_DEFAULT;

		ss_WCT_ChargingOnThePadCheck(Device);

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
	  	ss_WCT_Enable(Device, DURING);; // 차 상위 Duration 실행

		// 2. 하위(자식) Level State Transition 조건 확인

		// State's Transitions
		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			if(WCT.Out.Device[Device].ChargingOnthePad == (uint8_t)DETECTED_OFF)
			{
#if defined (DEBUG_CARD_PROTECTION_NOT_USE)
				// 상태 천이 없이 charging 상태 유지
#else 
				WCT.Int.StateNext[Device] = cWCT_ObjectDetection;				
#endif
				WCT.Int.EntryCnt[Device] = 0; // En 실행 : None
				WCT.Int.ExitCnt[Device] = 0;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_WCT_ChargingOnThePadCheck(Device);
			}

			//WCT.Int.StateOld[Device] = WCT.Int.StateCurr[Device]; // OldState 갱신
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		// 1. 하위(자식) Level State ex 실행
		gs_CancelTimer(&WCT.Timer[Device][Tim_ChargingOnThePadWait]);
		WCT.Out.Device[Device].ChargingOnthePad = (uint8_t)DETECTED_DEFAULT;

		// 2. 상위(부모) Level State ex 실행
		if (WCT.Int.ExitCnt[Device] > 0u)
		{
			WCT.Int.ExitCnt[Device]--;

			ss_WCT_Enable(Device, EXIT);
		}
		break;

	//==============================================================
	default:
		// rule 16.4
		break;
	}
}




/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_WCT_Repro(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		//Rte_Call_R_VCC33_CTRL_WriteDirect(ON);

		WCT.Out.ReproUartStart = ON;
		WCT.Out.NormalUartStart = OFF; // 리프로중 normal uart 중지

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (WCT.Int.StateCurr[Device] == WCT.Int.StateNext[Device])
		{
			// State's Transitions

			// 본 State는 병렬 실행하지 않는다.
			// 그러므로 1회만 실행한다.
			// 대신 State 관련 변수는 동일하게 2개 모두 설정한다.

			if(//(WCT.Inp_ADC.BatSysStateFault == ON) || // 리프로는 전원 조건 삭제
			(WCT.Inp_Repro.ReproFlashStatus == FLASH_COMPLETED) || // 리프로 완료, 버전일치
			(WCT.Inp_Repro.ReproFlashStatus == FLASH_COMPLETE_UNMATCH) || //  리프로 완료, 버전 불일치
			(WCT.Inp_Repro.ReproFlashStatus == FLASH_ERROR)) // ||	//  리프로  fail 발생.
			//(WCT.Int.Repro_Start_Evt.Off_Event == ON)) // 자동 off 되므로 삭제
			{
				WCT.Int.StateNext[Device] = cWCT_Disable;
				WCT.Int.EntryCnt[Device] = 0u; // En 실행 : WCT_Disable
				WCT.Int.ExitCnt[Device] = 0u;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				// 로직은 App_Repro.c에서 실행함.
				// 여기서는 전원 제어만 실시함.
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:

		WCT.Out.ReproUartStart = OFF;

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
static void ss_WCT_ObjectOnThePadCheck(uint8_t Device)
{
	if((WCT.Timer[Device][Tim_ObjectOnThePadWait].Count >= Par_ObjectOnThePadWaitTime) &&
	(WCT.Inp_UART.Device_WCT[Device].ObjectDetection == OFF))
	{
		gs_CancelTimer(&WCT.Timer[Device][Tim_ObjectOnThePadWait]);
		WCT.Out.Device[Device].ObjectOnthePad = (uint8_t)DETECTED_OFF;
	}
	else if(WCT.Int.ObjectDetection_Evt[Device].On_Event == ON)
	{
		gs_CancelTimer(&WCT.Timer[Device][Tim_ObjectOnThePadWait]);
		WCT.Out.Device[Device].ObjectOnthePad = (uint8_t)DETECTED_ON;
	}
	else
	{
		// rule 15.7
	}

	if(WCT.Int.DeviceState_Evt[Device].On_Event == cStandby)	// 폰 제거시 재시작
	{
		gs_StartTimer(&WCT.Timer[Device][Tim_ObjectOnThePadWait]); // 채터링의 역할도 함. 차량 진동에 의해서 state가 간헐적으로 바뀌기도함. 이때 즉시 바뀌지 않은 효과있음.
		WCT.Out.Device[Device].ObjectOnthePad = (uint8_t)DETECTED_DEFAULT;
	}

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_WCT_ChargingOnThePadCheck(uint8_t Device)
{
	if((WCT.Timer[Device][Tim_ChargingOnThePadWait].Count >= Par_ChargingOnThePadWaitTime) &&
	((WCT.Inp_UART.Device_WCT[Device].DeviceState == cInit) ||
	(WCT.Inp_UART.Device_WCT[Device].DeviceState == cStandby) ||
	(WCT.Inp_UART.Device_WCT[Device].DeviceState == cFODError)))
	{
		gs_CancelTimer(&WCT.Timer[Device][Tim_ChargingOnThePadWait]);
		WCT.Out.Device[Device].ChargingOnthePad = (uint8_t)DETECTED_OFF;
	}
	else if((WCT.Inp_UART.Device_WCT[Device].DeviceState == cCharging) ||
	(WCT.Inp_UART.Device_WCT[Device].DeviceState == cFull_Charge) ||
	(WCT.Inp_UART.Device_WCT[Device].DeviceState == cPrepareCharging))
	{
		gs_CancelTimer(&WCT.Timer[Device][Tim_ChargingOnThePadWait]);
		WCT.Out.Device[Device].ChargingOnthePad = (uint8_t)DETECTED_ON;
	}
	else
	{
		// rule 15.7
	}

	if(WCT.Int.DeviceState_Evt[Device].On_Event == cStandby)	// 폰 제거시 재시작
	{
		gs_StartTimer(&WCT.Timer[Device][Tim_ChargingOnThePadWait]); // 채터링의 역할도 함. 차량 진동에 의해서 state가 간헐적으로 바뀌기도함. 이때 즉시 바뀌지 않은 효과있음.
		WCT.Out.Device[Device].ChargingOnthePad = (uint8_t)DETECTED_DEFAULT;
	}

}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_PowerResetCheck(uint8_t Device) /* 010A_10 */
{
	// 아래 조건을때만 충전 IC를 리셋처리한다.
	// 그 이외 조건은 리셋하지 않는다.
	if((WCT.Inp_UART.WctUartRxTimeout == (uint8_t)DETECTED_ON) ||
	//(WCT.Inp_Uds.WCT_DiagReproStart == ON) || // repro 모듈에서 자체적으로 리셋 처리 하도록 변경
	(WCT.Int.WctLibTypeUnmatch == ON) ||
	(WCT.Inp_Repro.ReproRequest == cReproReq_On) || // 리프로 완료 후 복귀시 리셋 발생 시켜야 하므로 이 시그널은 유지함.
	(WCT.Int.WctPowerResetInitFlag == ON)) // 최초 전원인가시와 Sleep --> Wakeup시에만 진입
	{
		WCT.Int.WctPowerResetInitFlag = OFF; 
		
		gs_StartTimer(&WCT.Timer[Device][Tim_PowerResetWait]); 
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_PowerResetWaitTimeCheck(uint8_t Device)
{	
	// 리셋 불필요로 Tim_PowerResetWait 타이머가 start되지 않을때 고려가 되어야함.
	// 아직까지는 별도 조건 추가하지는 않음.	
	if((WCT.Timer[Device][Tim_PowerResetWait].Count >= WCT.Int.Var_PwrResetWaitTime[Device]) &&
	(WCT.Timer[Device][Tim_PowerResetWait].Running == ON))
	{
		// 충전 IC 전원 OFF상태에서 악의 조건으로 폰방치 동작시 최대한 빨리 진입하도록 하기 위함.
		WCT.Int.Var_PwrResetWaitTime[Device] = Par_PowerResetWaitTime; // 충전 IC 최초 전원인가 이후 250ms 로 복귀시킴
	
		WCT.Int.PwrRstWaitComplete[Device] = ON;
		gs_CancelTimer(&WCT.Timer[Device][Tim_PowerResetWait]);
		
		Rte_Call_R_VCC33_CTRL_WriteDirect(ON);	
		WCT.Out.NormalUartStart = ON;
	}	
	else if((WCT.Timer[Device][Tim_PowerResetWait].Count < Par_PowerResetWaitTime) &&	// Par_PowerResetWaitTime 동안 OFF 유지
	(WCT.Timer[Device][Tim_PowerResetWait].Running == ON))	
	{
		WCT.Int.PwrRstWaitComplete[Device] = OFF;
		Rte_Call_R_VCC33_CTRL_WriteDirect(OFF);
		WCT.Out.NormalUartStart = OFF;
			
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
static void ss_WCT_VCRM_Monitor(uint8_t Device)
{
	static uint8_t WPCWarningOld[Device_MAX] = {0};
	static uint8_t DeviceStateOld[Device_MAX] = {0};
	static uint16_t PhnUsingTime_10ms[Device_MAX] = {0};


    if(WCT.Int.IGN1_IN_Evt.On_Event == ON) // ign on 입력 즉시 초기화
	{

		memset(&WCT.Out.VCRM[Device], 0, sizeof(WCT.Out.VCRM[Device]));  				// 구조체 변수를 0으로 클리어

	}

	if(WCT.Inp_ADC.IGN1_IN == ON)
	{
		//---------------------------------------------------------------------------------------------------------------
		// IG ON 이후 충전 시간(minute 단위)
		// 0x0~0xFE : IG ON 이후 충전 시간(minute 단위), 0xFF : error
		// IG ON 이후 WPC_PhnLftWrngSta 시그널에 0x2(Charging) 출력 시간 분단위로 COUNT.
		// IG ON 전원 변경이 없이 Value 값이 변경되었다가 다시 0x2(Charging) 출력을 할 경우 시간을 이어서 count 한다.
		//---------------------------------------------------------------------------------------------------------------
		if(WCT.Inp_Model.Device[Device].WPCWarning == PhoneCharging)	/* 충전중이면 */
		{
			PhnUsingTime_10ms[Device]++;	/* 10ms 카운트업 */
		}

		if(PhnUsingTime_10ms[Device] >= 6000u)	/* 10ms카운터가 6000이되면(10ms * 100 * 60 = 60초) */
		{
			PhnUsingTime_10ms[Device] = 0u;	/* 10ms카운터를 초기화하고 */

			if(WCT.Out.VCRM[Device].PhnUsingTime < 0xFEu)	/* UsingTime이 0xFE보다 작을 때 */
			{
				WCT.Out.VCRM[Device].PhnUsingTime++;	/* UsingTime을 카운트업 */
			}
		}



		//---------------------------------------------------------------------------------------------------------------
		// IG ON 이후 충전 완료 횟수
		// 0x0~0xF : IG ON 이후 충전 완료 이벤트 발생 횟수
		// IG ON 이후 WPC_PhnLftWrngSta 시그널 0x3(Charging complete) 출력시 횟수를 count
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_Model.Device[Device].WPCWarning == Charging_Complete) &&
		(WPCWarningOld[Device] != Charging_Complete)) // 충전 완료 이벤트가 발생할때만 진입
		{
			if(WCT.Out.VCRM[Device].PhnChargingCompleteCnt < 0xFu)	/* CompleteCnt가 0xF보다 작을때만 */
			{
				WCT.Out.VCRM[Device].PhnChargingCompleteCnt++;	/* CompleteCnt를 카운트업 */
			}
		}

		//---------------------------------------------------------------------------------------------------------------
		// 안드로이드 휴대폰 충전기 동작 횟수
		// 0x0~0xF : IG ON 이후 EPP 충전 동작 횟수, 16회 이상 발생시 0xF 출력
		// IG ON 이후 WPC_PhnLftWrngSta 시그널에 0x2(Charging) 출력시 발생 횟수 count
		// 단, 휴대폰과 전력통신 후 아이폰이 아닌 경우를 count 한다.
		// (EPP 모드 동작하더라도 아이폰 충전인 경우 count 하지 않음)
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_Model.Device[Device].WPCWarning == PhoneCharging) &&
		(WPCWarningOld[Device] != PhoneCharging) && // 충전 이벤트 발생시에만 진입
		(WCT.Inp_UART.Device_WCT[Device].ManufactureID != ManufactureID_APPLE))	/* 아이폰이 아닌 경우 count */
		{
			if(WCT.Out.VCRM[Device].EPPChargingCnt < 0xFu)	/* ChargingCnt가 0xF보다 작을때만 */
			{
				WCT.Out.VCRM[Device].EPPChargingCnt++;	/* ChargingCnt를 카운트업 */
			}
		}

		//---------------------------------------------------------------------------------------------------------------
		// 아이폰 충전기 동작 횟수
		// 0x0~0xF : IG ON 이후 EPP 충전 동작 횟수, 16회 이상 발생시 0xF 출력
		// IG ON 이후 WPC_PhnLftWrngSta 시그널에 0x2(Charging) 출력시 발생 횟수 count
		// 단, 휴대폰과 전력통신 후 아이폰인 경우를 count 한다.
		// (EPP 모드 동작하더라도 아이폰 충전인 경우 count 한다.)
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_Model.Device[Device].WPCWarning == PhoneCharging) &&
		(WPCWarningOld[Device] != PhoneCharging) && // 충전 이벤트 발생시에만 진입
		(WCT.Inp_UART.Device_WCT[Device].ManufactureID == ManufactureID_APPLE)) /* 아이폰인 경우 count */
		{
			if(WCT.Out.VCRM[Device].MPPChargingCnt < 0xFu)	/* ChargingCnt가 0xF보다 작을때만 */
			{
				WCT.Out.VCRM[Device].MPPChargingCnt++;	/* ChargingCnt를 카운트업하고 */
			}
		}

		//---------------------------------------------------------------------------------------------------------------
		// 디지털키에 의한 차량 시동 인증 여부
		// 0x0 : default, 0x1 : Auth by Digital key
		//LOCAL CAN DB 상에 WPC_Device_On_Cmd 시그널 0x1(Phone) 또는 0x2(Card) 수신시0x1 로 Set
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_CAN_RX.LCAN.LC_DeviceOnWPC == 1u) ||
		(WCT.Inp_CAN_RX.LCAN.LC_DeviceOnWPC == 2u))
		{
			// device가 구분이 안되므로 일단 동일하게 설정함
			WCT.Out.VCRM[Device].DigitalKeyAuth = 1u;	/* DigitalKeyAuth 값 Set */
		}

		//---------------------------------------------------------------------------------------------------------------
		// 디지털키로 차량 시동 인증시 사용한 디지털키 종류
		// 0x0 : default, 0x1 : Androide Device, 0x2 : Androide Devcie(Watch), 0x3 : Apple Device,
		// 0x4 : Apple Device(Watch), 0x5 : Card key, 0X6 ~ 0x7 : Reserved
		// LOCAL CAN DB 상에 WPC_Device_On_Cmd 시그널 0x1(Phone) 또는 0x2(Card) 수신시
		// WPC 와 NFC 통신을 수행했던 Device 기록을 저장
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_CAN_RX.LCAN.LC_DeviceOnWPC == 1u) ||
		(WCT.Inp_CAN_RX.LCAN.LC_DeviceOnWPC == 2u))
		{
			// device가 구분이 안되므로 일단 동일하게 설정함
			WCT.Out.VCRM[Device].DigitalKeyDevice  = 0; // 기능 미구현되어 있으므로 default 설정함.
		}

		//---------------------------------------------------------------------------------------------------------------
		// 충전 FOD 발생 횟수
		// 0x00~0x40 : IG ON 이후 MPP 충전 동작 횟수, 64회 이상 발생시 0x40 출력
		// IG ON 이후 FOD 발생 횟수 count
		//---------------------------------------------------------------------------------------------------------------
		if((WCT.Inp_UART.Device_WCT[Device].DeviceState == cFODError) &&
		(DeviceStateOld[Device] != cFODError))	// fod 이벤트 발생시에만 진입
		{
			if(WCT.Out.VCRM[Device].PhnChargingErrCnt < 0x3Fu) /* PhnChargingErrCnt가 0x3F보다 작을때만 */
			{
				WCT.Out.VCRM[Device].PhnChargingErrCnt++;	/* CompleteCnt를 카운트업 */
			}
		}

		//---------------------------------------------------------------------------------------------------------------
		// 온도 센서 최대 도달 온도
		// 0x0~0xFE : IG ON 최대 도달 온도, 0xFF : error
		// IG ON 이후 온도 세서의 최대 측정 온도값을 저장
		//---------------------------------------------------------------------------------------------------------------
		/* temp입력이 0보다 작으면 현재 온도에 0을 넣고 같거나 크면 unsinged로 캐스팅해서 temp 대입함 */
		if(WCT.Inp_UART.Device_WCT[Device].TempSnsrError == OFF)
		{
			if(WCT.Inp_UART.Device_WCT[Device].CoilTempDegree < 0)
			{
				WCT.Inp_UART.Device_WCT[Device].CoilTempDegree = 0;
			}

			/* 현재 온도가 최대 온도 변수값보다 높으면 대입 */
			if(WCT.Inp_UART.Device_WCT[Device].CoilTempDegree > WCT.Out.VCRM[Device].ThermalSnsrMaxTemp)
			{
				WCT.Out.VCRM[Device].ThermalSnsrMaxTemp = WCT.Inp_UART.Device_WCT[Device].CoilTempDegree;
			}
		}
		else
		{
			WCT.Inp_UART.Device_WCT[Device].CoilTempDegree = 0xFF;
		}

		WPCWarningOld[Device] = WCT.Inp_Model.Device[Device].WPCWarning;
		DeviceStateOld[Device] = WCT.Inp_UART.Device_WCT[Device].DeviceState;


	}

    if(WCT.Int.IGN1_IN_Evt.Off_Event == ON) // ign off 시점 DTC set
	{
		// IGN OFF 시점 DTC가 있을 경우 SET
		// device가 구분이 없는 경우 동일하게 설정함.

		WCT.Out.VCRM[Device].CANBusOffDTC = WCT.Inp_DTC.BcanBusOffDTC;
		WCT.Out.VCRM[Device].LocalCANBusOffDTC = WCT.Inp_DTC.LcanBusOffDTC;
		WCT.Out.VCRM[Device].TempSnsrFltDTC = WCT.Inp_DTC.Device[Device].TempSnsrFaultDTC;
		WCT.Out.VCRM[Device].FANFltDTC = WCT.Inp_DTC.Device[Device].FanFaultDTC;
		WCT.Out.VCRM[Device].InternalECUErrDTC = WCT.Inp_DTC.WctIcErrorDTC;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void    ss_WCT_LibTypeUnmatch(void) /* 0108_12 */
{
	if(WCT.Inp_UART.WctUartCommReady == ON) // 버전 정상 수신
	{
		if(WCT.Inp_NvM.WPC_TYPE == cWPC_TYPE_4)
		{
			if(WCT.Inp_UART.WctSourceVer[0] != cWCT_TARGET_VER1_TYPE4)
			{
				WCT.Int.WctLibTypeUnmatch = ON;
			}
			else
			{
				WCT.Int.WctLibTypeUnmatch = OFF;
			}
		}
		else if(WCT.Inp_NvM.WPC_TYPE == cWPC_TYPE_5)
		{	
			if(WCT.Inp_UART.WctSourceVer[0] != cWCT_TARGET_VER1_TYPE5)
			{
				WCT.Int.WctLibTypeUnmatch = ON;
			}
			else
			{
				WCT.Int.WctLibTypeUnmatch = OFF;
			}		
		}
		else if(WCT.Inp_NvM.WPC_TYPE == cWPC_TYPE_6) 
		{
			if(WCT.Inp_UART.WctSourceVer[0] != cWCT_TARGET_VER1_TYPE6)
			{
				WCT.Int.WctLibTypeUnmatch = ON;
			}
			else
			{
				WCT.Int.WctLibTypeUnmatch = OFF;
			}		
		}
		else
		{
			WCT.Int.WctLibTypeUnmatch = OFF;
		}
	
	}
	
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_WCT_L2H_Set(void)
{
	WCT.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_WCT_H2L_Set(void)
{		
	Rte_Call_R_VCC33_CTRL_WriteDirect(OFF);
	Rte_Call_R_VBAT_SW_CTRL_WriteDirect(OFF);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WCT_LPConditionCheck(uint8_t Device)
{
	if(WCT.Int.StateCurr[Device] != cWCT_Disable)
	{
		WCT.Out.Device[Device].WCT_LPConditionFlag = OFF;	// Active
	}
	else
	{
		WCT.Out.Device[Device].WCT_LPConditionFlag = ON;	// Sleep
	}
}

#define App_WCT_STOP_SEC_CODE
#include "App_WCT_MemMap.h"
