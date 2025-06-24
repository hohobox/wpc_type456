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
#include "App_Mode.h"
#include "Rte_SWC_AppMode.h" // 배포된 App_Mode.arxml 파일을 그대로 사용한다. 그래야 모빌젠 하모니가 더 잘 된다.

#include "App_WCT.h"
#include "App_NvM.h"
#include "Port.h"


#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/
#define APP_MODE_USER 0u

// NM spec에서 sleep 진입시까지 1초 이내로 걸려야 하는 스펙이 있는데 기존 5초는 너무 길어서 1초로 변경함.
// --> 20241031 : 나중에 다른 평가하다가 추가로 확인된 내용을 하기에 기술함.
// 이 시간이 NM RMS --> NM or RMS --> RSS 로 천이할때 Repeat Message Time Expired 시간과도 상관이 있다.
// Repeat Message Time Expired : Typ (1200ms) 이므로 예전처럼 5초로 설정하면
// NM CVB(Control Bit Vector)의 AWB(Active Wakeup Bit)의 설정이 정상으로 동작하지 않는다.
// Sleep 상태에서 IGN ON에 의해서 Wakeup 시에는 AWB = 1, CAN에 의한 Wakeup시에는 AWB = 0이 되어야 하나
// 예전처럼 5초이면 항상 AWB = 1로만 설정되는 문제가 발생한다.
// 최종적으로는 Wakeup 요인을 구분하여 각각 Wakeup 요인별로 FullComm 호출하는 타이밍등을 구분해야 할것으로 생각됨.

// ES95480-03
// Passive 웨이크업 및 Active 웨이크업 정의
// Passive 웨이크업 : 타 제어기가 전송하는 메시지 (NM 메시지 혹은 APP 메시지)를 수신하여 제어기가 웨이크업 되는 경우를 의미한다.
// Active 웨이크업 : 제어기 스스로의 동작 조건 (예 : 전원조건)이 만족하여 스스로 웨이크업하는 경우를 의미한다.
// [DS_CANFD_NM_0207] Passive 웨이크업과 Active 웨이크업 요청이 중복되는 경우 처리 방법은 다음과 같다.
// -	Passive 웨이크업 요청 처리가 끝나기 전 Active Wakeup 요청이 오거나 그 반대의 경우 모두 Active 웨이크업 요청을 우선하여 처리한다.

#define     cCanSleepWaitTim      	 (uint16_t)(1000u/10u) 		// 타이머 1개로 통합.
#define     cEcuSleepWaitTim       	 (uint16_t)(20u/10u)		// 


typedef enum
{
	APP_MODE_NONE,
	APP_MODE_ACTIVE,
	APP_MODE_SLEEP
} APP_MODE_ENUM_t;

/** redefine for easy to see in debugger */
typedef enum
{
  RTE_MODE_MDG_CanSMBORState_START_ = RTE_MODE_MDG_CanSMBORState_START, 
  RTE_MODE_MDG_CanSMBORState_COMPLETE_ = RTE_MODE_MDG_CanSMBORState_COMPLETE
} CanSMBORState_t;

/** redefine for easy to see in debugger */
typedef enum
{
  RTE_MODE_MDG_PduGroup_STOP_ = RTE_MODE_MDG_PduGroup_STOP,
  RTE_MODE_MDG_PduGroup_START_ = RTE_MODE_MDG_PduGroup_START
} PduGroup_t;

/** redefine for easy to see in debugger */
typedef enum
{
  RTE_MODE_MDG_ComMMode_NO_COM_ = RTE_MODE_MDG_ComMMode_NO_COM,
  RTE_MODE_MDG_ComMMode_SILENT_COM_ = RTE_MODE_MDG_ComMMode_SILENT_COM,
  RTE_MODE_MDG_ComMMode_FULL_COM_ = RTE_MODE_MDG_ComMMode_FULL_COM
} ComMMode_t;

/** redefine for easy to see in debugger */
typedef enum
{
  RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED_ = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED,
  RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP_ = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP,
  RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP_ = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP,
  RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION_ = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION,
  RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION_ = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION
} ComMMode_PNC_t;

/** redefine for easy to see in debugger */
typedef enum
{
 // #define RTE_MODE_MDG_WakeupEvent_POWER ((Rte_ModeType_MDG_WakeupEvent)0U)

  RTE_MODE_MDG_WakeupEvent_POWER_ = RTE_MODE_MDG_WakeupEvent_POWER,  /* 초기값을 0으로 초기화 할때 Power Event define 설정되는것과 동일한 값이 된다. 그러나 실제 rte.c 코드에서 POWER 인베트는 없으므로 사용한다. */
  RTE_MODE_MDG_WakeupEvent_INITIAL_MODE_ = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE,
  RTE_MODE_MDG_WakeupEvent_IGN1_ = RTE_MODE_MDG_WakeupEvent_IGN1,
  RTE_MODE_MDG_WakeupEvent_BCAN_RX_ = RTE_MODE_MDG_WakeupEvent_BCAN_RX,
  RTE_MODE_MDG_WakeupEvent_BCAN_RX_POLL_ = RTE_MODE_MDG_WakeupEvent_BCAN_RX_POLL,
  RTE_MODE_MDG_WakeupEvent_LCAN_RX_ = RTE_MODE_MDG_WakeupEvent_LCAN_RX,
  RTE_MODE_MDG_WakeupEvent_LCAN_RX_POLL_ = RTE_MODE_MDG_WakeupEvent_LCAN_RX_POLL
} WakeupEvent_t;



/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef	struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;

	uint8_t BswInitFlag;     /* BSW Init Completed (Step 1) Flag */
	uint8_t NvMInitFlag;     /* NvM Init Completed (Step 3) Flag */
	/*uint8_t AppInitFlag; */    /* App Init Completed (Step 4) Flag */

	uint16_t BCanSleepWaitCnt;
	uint16_t LCanSleepWaitCnt;
	uint16_t EcuSleepWaitCnt;

	APP_MODE_ENUM_t	Ecu_Mode;
  	APP_MODE_ENUM_t Ecu_ModeOld;

	APP_MODE_ENUM_t	BCan_Mode;
	APP_MODE_ENUM_t	BCan_ModeOld;

  	APP_MODE_ENUM_t LCan_Mode;
	APP_MODE_ENUM_t	LCan_ModeOld;

// 디버그시 모니터링용으로 redefine 된 내부 변수 추가함
	ComMMode_t ComMMode_BCAN;
	ComMMode_t ComMMode_LCAN;

	CanSMBORState_t CanSMBORState_BCAN;
	CanSMBORState_t CanSMBORState_LCAN;

	PduGroup_t PduGroupTx_BCAN_PNC32;
	PduGroup_t PduGroupTx_BCAN_PNC141;
	PduGroup_t PduGroupTx_BCAN_PNC153;
	PduGroup_t PduGroupTx_LCAN_PNC32;
	PduGroup_t PduGroupTx_LCAN_PNC159;

	PduGroup_t PduGroupRx_BCAN_PNC32;
	PduGroup_t PduGroupRx_BCAN_PNC141;
	PduGroup_t PduGroupRx_BCAN_PNC153;
	PduGroup_t PduGroupRx_LCAN_PNC32;
	PduGroup_t PduGroupRx_LCAN_PNC159;

	ComMMode_PNC_t BCAN_ComMModePNC32;
	ComMMode_PNC_t BCAN_ComMModePNC141;
	ComMMode_PNC_t BCAN_ComMModePNC153;
	ComMMode_PNC_t LCAN_ComMModePNC32;
	ComMMode_PNC_t LCAN_ComMModePNC159;

	WakeupEvent_t WakeupEventValid;
	
	uint8_t WakeupEvent_INIT_MODE;
	uint8_t WakeupEvent_IGN1;
	uint8_t WakeupEvent_BCAN_RX;
	uint8_t WakeupEvent_BCAN_RX_POLL;
	uint8_t WakeupEvent_LCAN_RX;
	uint8_t WakeupEvent_LCAN_RX_POLL;

} Inter_t;


typedef struct
{
	IDT_Model_STR 	Inp_Model;
	IDT_WCT_STR		Inp_WCT;
	IDT_NFC_STR		Inp_NFC;
	IDT_ADC_STR 	Inp_ADC;
	IDT_Uds_STR 	Inp_Uds;
	IDT_WDT_STR 	Inp_WDT;
	IDT_Repro_STR 	Inp_Repro;
	IDT_NvM_STR 	Inp_NvM;
	IDT_UART_STR 	Inp_UART;

	Inter_t 		Int;
	IDT_Mode_STR 	Out;

} Mode_struct;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

static Mode_struct Mode = {0};


static Rte_ModeType_MDG_WakeupEvent AppMode_GddWakeupEvent = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE;



/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_Mode_InitSet(void);
static void ss_Mode_RteRead(void);
static void ss_Mode_RteWrite(void);

static void ss_Mode_LowPowerCheck_BCAN(void);
static void ss_Mode_LowPowerCheck_LCAN(void);
static void ss_Mode_Timer_Update(void);
static void ss_Mode_EcuSleepCheck(void);

// 전원 리셋시 Mode.Ecu_Mode, Bcan_Mode, Lcan_Mode 관련 설정 순서
// 1.Mdw_Mode_EcuModeSwitched()가 가장 먼저 호출됨. SWP eeprom 초기화 되기 전에 호출됨. NFC 사양 정보 확인 불가.
// 2.Mode_TE_Runnable()의 cMdw_Mode_Init: 호출됨. 여기는 swp eeprom 초기화완료된 상태임. NFC 사양 정보 확인 가능.
// 3.ss_Mode_LowPowerCheck()의 IGN on/off등 조건에 따라 Mode 값 설정됨.

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) Mode_TE_Runnable(void)
{

	switch (Mode.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			if(Mode.Int.App_Init_Completed == ON)
			{/* Init Process */
				ss_Mode_InitSet();

				Mode.Int.Runnable_State = 1u;   /* Mode Chage >> cMdw_Mode_BatOn */
			}
		break;

		case 1u:

			ss_Mode_RteRead();

			ss_Mode_LowPowerCheck_BCAN();

			ss_Mode_LowPowerCheck_LCAN();

			ss_Mode_EcuSleepCheck();

			ss_Mode_Timer_Update();

			ss_Mode_RteWrite();

		break;

		default:
			Mode.Int.Runnable_State = 0u;        /* Mode Chage >> cMdw_Mode_Init */
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Mode_InitSet(void)
{
	Rte_Read_R_NvM_NvM_STR(&Mode.Inp_NvM); // rte read 전에 읽어야 하므로 미리 호출함.

	// LowPower_Callout.c에서 포트 초기화를 하고 있으나
// 최초 전원 인가시에는 LowPower_Callout.c가 실행되지 않는다.
// 그래서 여기서 강제로 최초 전원 인가사 강제로 포트 재설정을 하도록 여기에 코드를 추가한다.
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	if((Mode.Inp_NvM.WPC_TYPE == cWPC_TYPE_5) || /* only dual */
	(Mode.Inp_NvM.WPC_TYPE == cWPC_TYPE_6))
	{
  		Port_Init(&PortConf_PortConfigSet_PortConfigSet_0_Dual_Active);// nfc, LCAN 사용으로 설정된 포트 (debug는 사용)
	// WPC_7A_01
	}
	else
	{
//#else	// Single
	// 여기에는 플랫폼 port 설정을 single용으로 다시 만들어서 그 포트로 초기화를 하도록 추가해야한다.
	// 단 플랫폼 자체에서 맨 처음 전원 리셋시에는 자동으로 gen된 코드의 동작대로 dual 포트로 초기화 된다.
	// EcuM_Generated_Calluts.c에서 Port_Init(&Port_Config); 에서 0번째가 자동으로 설정되는데 이게 Dual 설정이다.
	// 그 다음 여기 로직에서 wpc type에 따라서 single 또는 dual 로 다시 포트 초기화를 하자.
	// 이렇게 하면 하나의 플랫폼으로 single / dual 모두 사용 가능하다.
	
		Port_Init(&PortConf_PortConfigSet_PortConfigSet_2_Single_Active);// nfc, LCAN 사용으로 설정된 포트 (debug는 사용)
	}
//#endif	

	
	memset(&Mode.Out, 0, sizeof(Mode.Out));  				// 구조체 변수를 0으로 클리어

	Mode.Int.BCanSleepWaitCnt = cCanSleepWaitTim;	// sleep 전 대기 시간
	Mode.Int.LCanSleepWaitCnt = cCanSleepWaitTim;	// sleep 전 대기 시간
	Mode.Int.EcuSleepWaitCnt = cEcuSleepWaitTim;	// sleep 전 대기 시간

    Mode.Int.Ecu_ModeOld = APP_MODE_NONE;
    Mode.Int.BCan_ModeOld = APP_MODE_NONE;
	Mode.Int.LCan_ModeOld = APP_MODE_NONE;

	Mode.Int.WakeupEventValid = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE_;
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Mode_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_Model_Model_STR(&Mode.Inp_Model);
	Rte_Read_R_Uds_Uds_STR(&Mode.Inp_Uds);
	Rte_Read_R_WCT_WCT_STR(&Mode.Inp_WCT);
	Rte_Read_R_NFC_NFC_STR(&Mode.Inp_NFC);
	Rte_Read_R_ADC_ADC_STR(&Mode.Inp_ADC);
	Rte_Read_R_WDT_WDT_STR(&Mode.Inp_WDT);
	Rte_Read_R_Repro_Repro_STR(&Mode.Inp_Repro);
	Rte_Read_R_NvM_NvM_STR(&Mode.Inp_NvM);
	Rte_Read_R_UART_UART_STR(&Mode.Inp_UART);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Mode_Timer_Update(void)
{
	if( Mode.Int.BCanSleepWaitCnt != 0u )
	{
		Mode.Int.BCanSleepWaitCnt--;
	}

	if( Mode.Int.LCanSleepWaitCnt != 0u )
	{
		Mode.Int.LCanSleepWaitCnt--;
	}

	if( Mode.Int.EcuSleepWaitCnt != 0u )
	{
		Mode.Int.EcuSleepWaitCnt--;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Mode_RteWrite(void)// WPC_5D_03
{

	Rte_Write_P_Mode_Mode_STR(&Mode.Out);	// 구조체로 한꺼번에 전송
}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Mode_LowPowerCheck_BCAN(void)
{
// ECU Standard_R4_210309.docx

// 1) LOW POWER MODE (L.P) :
// 다음의 조건이 모두 만족되면 LOW POWER MODE로 진입함
// -	WPC의 B+단에 전원은 공급되어 마이컴이 동작 중에 있음
// -	WPC가 최소 전류를 사용하여 일부 입력(Sleep/Wake-up작동 가능한 입력 단은 모니터링)
// -	단, 통신은 중단되어 있고 출력은 최소한의 상대만 유지
// 조건
// CAN Driver가 Stand-By mode로 진입 시 : Mdw_Mode.c 에서 처리
// 충전기능 OFF  (충전 동작 진행 사항이 없을 시, Timer 진행 사항이 없을 시)
// L_ACC_IN = OFF : 회로 미적용
// L_IGN1_IN = OFF : Mdw_Mode.c 에서 처리
// C_WPCNFCcmd = 0x02
// 진단 요구상태가 아닌경우 ( C_WPCDiagState == 0FF ) : 확인 필요

	// single 시 강제로 Sleep 조건 set
	if(Mode.Inp_NvM.WPC_TYPE == cWPC_TYPE_4) /* only single */
	{
		Mode.Inp_Model.Device[D1].WPCMode_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].WPCMain_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].SMKLF_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].TempSnsrError_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].OverTempDetect_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].OverCurrent_LPConditionFlag = ON;	
		Mode.Inp_Model.Device[D1].FAN_LPConditionFlag = ON;
		Mode.Inp_WCT.Device[D1].WCT_LPConditionFlag = ON;		
	}
	// LCAN / BCAN 완전 독립적으로 wakeup/sleep 되도록 수정

	//=================================================
	// BCAN Sleep 판단
	//=================================================
	if((Mode.Inp_ADC.IGN1_IN == ON) ||
	(Mode.Inp_Uds.Uds_LPConditionFlag == OFF) || 	// Diag 처리 중이면 sleep 빠지면 안됨.

	//(Mode.Inp_Model.USM_LPConditionFlag == OFF) || // 모델 USM Setting Control 판단
	//(Mode.Inp_Model.IndUSM_LPConditionFlag == OFF) || // 모델 IND Animation USM Setting Control 판단
	(Mode.Inp_WDT.WDT_LPConditionFlag == OFF) || // BCAN PDC 리셋 신호 1분간 송신 중
	(Mode.Inp_Repro.Repro_LPConditionFlag == OFF) || // 리프로그래밍 중
	//(Mode.Inp_UART.UART_LPConditionFlag == OFF) || // 충전 IC와 통신 중, uart는 disable에서도 통신하므로 sleep 조건에서 제외시킴. 통신중이라도 sleep 진입되어야함.

	(Mode.Inp_Model.Device[D0].WPCMode_LPConditionFlag == OFF) || // 모델 WPC NFC Mode Control 판단
	(Mode.Inp_Model.Device[D0].WPCMain_LPConditionFlag == OFF) || // 모델 WPC Main Control 판단
	(Mode.Inp_Model.Device[D0].SMKLF_LPConditionFlag == OFF) || // 모델 SMK LF Interface Control 판단
	(Mode.Inp_Model.Device[D0].TempSnsrError_LPConditionFlag == OFF) || // 모델 Temperature snsr Error Control 판단
	(Mode.Inp_Model.Device[D0].OverTempDetect_LPConditionFlag == OFF) || // 모델 Over Temperature Detect Control  판단
	(Mode.Inp_Model.Device[D0].OverCurrent_LPConditionFlag == OFF) || // 모델 Over Current Control 판단
	(Mode.Inp_Model.Device[D0].FAN_LPConditionFlag == OFF) || // 모델  FAN Control 판단
	(Mode.Inp_Model.Device[D0].USM_LPConditionFlag == OFF) || // 모델 USM Setting Control 판단
	(Mode.Inp_WCT.Device[D0].WCT_LPConditionFlag == OFF) ||	// App WCT 판단

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	(Mode.Inp_Model.Device[D1].WPCMode_LPConditionFlag == OFF) ||		
	(Mode.Inp_Model.Device[D1].WPCMain_LPConditionFlag == OFF) ||	
	(Mode.Inp_Model.Device[D1].SMKLF_LPConditionFlag == OFF) ||	
	(Mode.Inp_Model.Device[D1].TempSnsrError_LPConditionFlag == OFF) ||	
	(Mode.Inp_Model.Device[D1].OverTempDetect_LPConditionFlag == OFF) ||
	(Mode.Inp_Model.Device[D1].OverCurrent_LPConditionFlag == OFF) ||	
	(Mode.Inp_Model.Device[D1].FAN_LPConditionFlag == OFF) ||
	(Mode.Inp_Model.Device[D1].USM_LPConditionFlag == OFF) || // 모델 USM Setting Control 판단
	(Mode.Inp_WCT.Device[D1].WCT_LPConditionFlag == OFF) ||	
//#endif		
	
	(Mode.Int.WakeupEvent_INIT_MODE == ON) ||
	(Mode.Int.WakeupEvent_IGN1 == ON) ||		// IGN Wakeup
	(Mode.Int.WakeupEvent_BCAN_RX == ON) ||		// BCAN Wakeup
	(Mode.Int.WakeupEvent_BCAN_RX_POLL == ON))	
	{/* Run State */
		Mode.Int.BCan_Mode = APP_MODE_ACTIVE;
		Mode.Int.BCanSleepWaitCnt = cCanSleepWaitTim;
		
		//Mode.Int.WakeupEvent_INIT_MODE = OFF;	// flag clear // Lcan에서도 공용으로 사용하는 flag이므로 여기서 클리어하면 안되고 Lcan쪽에서 클리어 처리해야함
		//Mode.Int.WakeupEvent_IGN1 = OFF;		// flag clear // Lcan에서도 공용으로 사용하는 flag이므로 여기서 클리어하면 안되고 Lcan쪽에서 클리어 처리해야함
		Mode.Int.WakeupEvent_BCAN_RX = OFF;		// flag clear
		Mode.Int.WakeupEvent_BCAN_RX_POLL = OFF;// flag clear
	}
	else
	{/* Sleep State */
		if( Mode.Int.BCanSleepWaitCnt == 0u )
		{
			Mode.Int.BCan_Mode = APP_MODE_SLEEP;
		}
	}

	switch (Mode.Int.BCan_Mode)
	{
		case APP_MODE_ACTIVE:
			if(Mode.Int.BCan_Mode != Mode.Int.BCan_ModeOld)
			{
				// PNC32는 상위제어기만 제어 가능하고 WPC는 절대 제어하면 안됨.
				Rte_Write_modeRequestPort_ComMMode_PNC141_ComMMode_PNC141(COMM_MODE_FULL_COM); // PNC141 비트를 on하여 full comm 한다.
				Rte_Write_modeRequestPort_ComMMode_PNC153_ComMMode_PNC153(COMM_MODE_FULL_COM); // PNC153 비트를 on하여 full comm 한다.
				Mode.Int.BCan_ModeOld = Mode.Int.BCan_Mode;
			}

		break;

		case APP_MODE_SLEEP:
// 1) Sleep 이전에 전체 통신 채널이 No ComM 상태임을 확인한다.
// 2) No ComM 전환을 요청하기 전에 Full ComM 상태임을 확인한다.
			if((Mode.Int.BCan_Mode != Mode.Int.BCan_ModeOld) &&
			(Mode.Out.ComMMode_BCAN == RTE_MODE_MDG_ComMMode_FULL_COM))
			{
				// PNC32는 상위제어기만 제어 가능하고 WPC는 절대 제어하면 안됨.
				Rte_Write_modeRequestPort_ComMMode_PNC141_ComMMode_PNC141(COMM_MODE_NO_COM);
				Rte_Write_modeRequestPort_ComMMode_PNC153_ComMMode_PNC153(COMM_MODE_NO_COM);
				Mode.Int.BCan_ModeOld = Mode.Int.BCan_Mode;
			}

		break;

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
static void ss_Mode_LowPowerCheck_LCAN(void)
{
// ECU Standard_R4_210309.docx

// 1) LOW POWER MODE (L.P) :
// 다음의 조건이 모두 만족되면 LOW POWER MODE로 진입함
// -	WPC의 B+단에 전원은 공급되어 마이컴이 동작 중에 있음
// -	WPC가 최소 전류를 사용하여 일부 입력(Sleep/Wake-up작동 가능한 입력 단은 모니터링)
// -	단, 통신은 중단되어 있고 출력은 최소한의 상대만 유지
// 조건
// CAN Driver가 Stand-By mode로 진입 시 : Mdw_Mode.c 에서 처리
// 충전기능 OFF  (충전 동작 진행 사항이 없을 시, Timer 진행 사항이 없을 시)
// L_ACC_IN = OFF : 회로 미적용
// L_IGN1_IN = OFF : Mdw_Mode.c 에서 처리
// C_WPCNFCcmd = 0x02
// 진단 요구상태가 아닌경우 ( C_WPCDiagState == 0FF ) : 확인 필요


	// LCAN / BCAN 완전 독립적으로 wakeup/sleep 되도록 수정

	// single 시 강제로 Sleep 조건 set
	if(Mode.Inp_NvM.WPC_TYPE == cWPC_TYPE_4) /* only single */
	{
		Mode.Inp_NFC.Device[D1].NFC_LPConditionFlag = ON;
		Mode.Inp_Model.Device[D1].NFCMode_LPConditionFlag = ON;		
	}
	//=================================================
	// LCAN Sleep 판단
	//=================================================
	if((Mode.Inp_ADC.IGN1_IN == ON) ||
	(Mode.Inp_NFC.Device[D0].NFC_LPConditionFlag == OFF) || 		// lcan polling 수신시
	(Mode.Inp_Model.Device[D0].NFCMode_LPConditionFlag == OFF) || // 모델 WPC NFC Mode Control Control 판단
	//(Mode.Inp_WDT.WDT_LPConditionFlag == OFF) ||

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6) /* only dual */
	(Mode.Inp_NFC.Device[D1].NFC_LPConditionFlag == OFF) ||
	(Mode.Inp_Model.Device[D1].NFCMode_LPConditionFlag == OFF) ||	
//#endif	
	
	(Mode.Int.WakeupEvent_INIT_MODE == ON) ||
	(Mode.Int.WakeupEvent_IGN1 == ON) ||		// IGN Wakeup
	(Mode.Int.WakeupEvent_LCAN_RX == ON) ||		// LCAN Wakeup
	(Mode.Int.WakeupEvent_LCAN_RX_POLL == ON))		
	{/* Run State */

		Mode.Int.LCan_Mode = APP_MODE_ACTIVE;
		Mode.Int.LCanSleepWaitCnt = cCanSleepWaitTim;
		
		Mode.Int.WakeupEvent_INIT_MODE = OFF;	// flag clear // Bcan에서도 공용으로 사용하는 flag이므로 여기서만 클리어한다.
		Mode.Int.WakeupEvent_IGN1 = OFF;		// flag clear // Bcan에서도 공용으로 사용하는 flag이므로 여기서만 클리어한다.
		Mode.Int.WakeupEvent_LCAN_RX = OFF;		// flag clear
		Mode.Int.WakeupEvent_LCAN_RX_POLL = OFF;// flag clear		
	}
	else
	{/* Sleep State */
		if( Mode.Int.LCanSleepWaitCnt == 0u )
		{
			Mode.Int.LCan_Mode = APP_MODE_SLEEP;
		}
	}

	switch (Mode.Int.LCan_Mode)
	{
		case APP_MODE_ACTIVE:

			if(Mode.Int.LCan_Mode != Mode.Int.LCan_ModeOld)
			{
				// PNC32는 상위제어기만 제어 가능하고 WPC는 절대 제어하면 안됨.
				Rte_Write_modeRequestPort_ComMMode_PNC159_ComMMode_PNC159(COMM_MODE_FULL_COM); // PNC159 비트를 on하여 full comm 한다.
				Mode.Int.LCan_ModeOld = Mode.Int.LCan_Mode;
			}

		break;

		case APP_MODE_SLEEP:
// 1) Sleep 이전에 전체 통신 채널이 No ComM 상태임을 확인한다.
// 2) No ComM 전환을 요청하기 전에 Full ComM 상태임을 확인한다.
			if((Mode.Int.LCan_Mode != Mode.Int.LCan_ModeOld) &&
			(Mode.Out.ComMMode_LCAN == RTE_MODE_MDG_ComMMode_FULL_COM))
			{
				// PNC32는 상위제어기만 제어 가능하고 WPC는 절대 제어하면 안됨.
				Rte_Write_modeRequestPort_ComMMode_PNC159_ComMMode_PNC159(COMM_MODE_NO_COM);
				Mode.Int.LCan_ModeOld = Mode.Int.LCan_Mode;
			}

		break;

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
static void ss_Mode_EcuSleepCheck(void)
{
  	Rte_ModeType_EcuMode LddPrevEcuMode, LddNextEcuMode;

	// Ecu_Mode는 개별로 판단하여 ECU Mode 변경하면 안됨.
	// LCAN과 BCAN 모두 Sleep일대 ECU Mode도 sleep으로 판단해야함
	if((Mode.Int.BCan_Mode == APP_MODE_SLEEP) &&
	(Mode.Int.LCan_Mode == APP_MODE_SLEEP))
	{
		Mode.Int.Ecu_Mode = APP_MODE_SLEEP;
	}
	else if((Mode.Int.BCan_Mode == APP_MODE_ACTIVE) ||
	(Mode.Int.LCan_Mode == APP_MODE_ACTIVE))
	{
		Mode.Int.Ecu_Mode = APP_MODE_ACTIVE;
	}
	else
	{
		Mode.Int.Ecu_Mode = APP_MODE_NONE;	// code sonar fix
	}

	switch (Mode.Int.Ecu_Mode)
	{
		// 정식 배포시 포함된 AppMode 샘플코드와 동일하게 수정함.
		case APP_MODE_ACTIVE:
			if(Mode.Int.Ecu_Mode != Mode.Int.Ecu_ModeOld)
			{
				Rte_Mode_modeNotificationPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);

  				if (LddNextEcuMode != RTE_MODE_EcuMode_ECUM_STATE_RUN)
  				{
					Rte_Call_clientPort_StateRequest_RequestRUN(APP_MODE_USER);     /* ECU Mode Change >> RUN */
				}
				else
				{
					Rte_Call_clientPort_StateRequest_SetRunState();
				}
				Mode.Int.Ecu_ModeOld = Mode.Int.Ecu_Mode;
			}

			Mode.Int.EcuSleepWaitCnt = cEcuSleepWaitTim;
		break;

		case APP_MODE_SLEEP:
// 1) Sleep 이전에 전체 통신 채널이 No ComM 상태임을 확인한다.
// 2) No ComM 전환을 요청하기 전에 Full ComM 상태임을 확인한다.
			if((Mode.Int.Ecu_Mode != Mode.Int.Ecu_ModeOld) &&
			(Mode.Out.ComMMode_BCAN == RTE_MODE_MDG_ComMMode_NO_COM) &&
			(Mode.Out.ComMMode_LCAN == RTE_MODE_MDG_ComMMode_NO_COM))
			{
				if( Mode.Int.EcuSleepWaitCnt == 0u ) // ecu sleep 진입 전 대기 시간 추가 // CAN 평가 TNM127 fail 대책으로 적용함.
				{
					Mode.Int.Ecu_ModeOld = Mode.Int.Ecu_Mode;
					Rte_Call_clientPort_StateRequest_RequestSleep(APP_MODE_USER);       /* ECU Mode Change >> SLEEP */

					// TCAN1463사용시 모빌젠 설정은 TCAN1043A로 적용함.
					// SWE timerout에의한 Standby --> Seeep 자동 천이 사용하지 않기 위해서
					// 모빌젠 설정에서 Standby 모드를 Sleep 모드로 변경하여 사용하도록 설정 변경함.
					// 그렇게 하면 Wakeup 을 위한 특정 패턴 적용이 불필요해짐.

					// CanTrcv_ModeCtrl.c CANTRCV_SETOPMODE_MACRO() OpelseMode = Normal 호출됨.  STB = HIGH, EN = HIGH
					// CanTrcv_ModeCtrl.c CANTRCV_SETOPMODE_MACRO() OpMode = Sleep 호출됨. STB = LOW, EN = HIGH (standby 대신 Sleep 모드 사용해야함)
					// 2번 호출됨.
					// Lowpower_Callout.c EcuM_H2LTransition_Callout_App() : Port_Init(Sleep) 호출됨. STB = LOW, EN = HIGH
  					// Lowpower_Callout.c EcuM_H2LTransition_Callout_App() : Mcu_InitClock(1u); // ECO (20Mhz) --> IMO (8Mhz)변환

					//  DeepSleep 진입


					// EcuM_Callout.c 의 EcuM_SetMode() 에서 LowperActive --> DeepSleep --> LowpwerActive --> DeepSleep -->
					// 40msw 주기로 EvtGen에 의해서 Wakeup 되면서 WDT Pulse 출력한다.


					//	DeepSleep 탈출 (AppMode_WakeupEventValidated()에 의한 wakeup 발생시)

					// Lowpower_Callout.c EcuM_L2HTransition_Callout_App() : Mcu_InitClock(ECUM_MCU_NORMAL_CLOCK); // IMO (8Mhz) --> ECO (20Mhz) 변환
					// Lowpower_Callout.c EcuM_L2HTransition_Callout_App() : Port_Init(Normal) 호출됨. STB = HIGH, EN = HIGH
					// CanTrcv_ModeCtrl.c CANTRCV_SETOPMODE_MACRO() OpMode = Normal 호출됨. STB = HIGH, EN = HIGH
					// 1번 호출됨
					// 위처럼 2중으로 STB, EN단 제어 되므로 문제 있음. CAN_Trcv모듈 사용하기 위해서는 포트 일괄제어 문제가 있음. 수정 필요.
				}
			}
			else
			{
				Mode.Int.EcuSleepWaitCnt = cEcuSleepWaitTim;	/* Ecu Sleep Wait Timer Set */
			}

		break;

		default:
			// M3CM Rule-16.4
		break;
	}
}


// 1. 문제현상 : 제어기에서 Sleep 모드를 사용하는 경우 OTA reprogram 이후 memory swap을 위하여 Reset을 요청하는 case 등의 Reset 요청이 제대로 처리되지 않거나 delay 되어 처리되는 현상 발생
// 2. 문제원인 : Sleep 요청 이전에 전체 통신 채널 상태가 No ComM으로 변경되어야 한다.
// 만약 No Com 으로 변경되지 않은 상태에서 Sleep을 요청하는 경우,
// Rule_EcuStateTo_SLEEP 에서 COMM_NO_COMMUNICATION 조건을 만족하지 못하게 되며 Sleep Sequence 상으로 다음 순서인 Rule_EcuState_SLEEP이 호출되지 못한 채 stuck 된다.
// 이후 COMM_NO_COMMUNICATION 상태를 만족하게 되면 Sleep으로 mode 변경이 진행되나, 고착 상태에서 Reset을 요청하는 경우 Reset 처리가 되지 않게 된다.
// 3. 해결방안 :
// 1) Sleep 이전에 전체 통신 채널이 No ComM 상태임을 확인한다.
// 2) No ComM 전환을 요청하기 전에 Full ComM 상태임을 확인한다.
// Sample로 제공되는 App_Mode.c 파일의 AppMode_ComMModeSwitched_XXXX API를 사용하여 통신 채널 상태를 확인한다.
// 그 외 다른 전역 변수나 API (ComM_GetCurrentComMode 등)를 통하여 상태를 확인하는 방법으로는 통신 채널의 정확한 상태를 읽어올 수 없다.

// Internal Main Oscillator (IMO)
// External Crystal Oscillator (ECO)
// Internal Low-speed Oscillator (ILO)

  // <sleep 진입시 클럭 설정 변경 관련 정리>
  // 전원 모드는 Active - LowperActive - Deepsleep 이렇게 3단계가 있다.
  // Active에서 deepsleep 명령에 의해서 Deepsleep으로 진입한다.
  // DeepSleep에서 eventgen 시간마다 wakeup 되면 LowpowerActive가 된다.
  // 이상태에서 wakeup 조건이 만족하지 못하면 다시 DeepSleep 상태가 된다.

  // Active : 20Mhz x 8(pll) = 160Mhz
  // Deepsleep : 32Khz (ILO)
  // LowpowerActive :IMO 미설정시 20Mhz x 8(pll) = 160Mhz,
  //                :IMO 설정시 sleep 진입시 8Hhz

  // 원칙적으로는 Active에서 deepslee 천이 전에 clock설정을 IMO(내부클럭) 설정으로 변경해야햔다.
  // 이렇게 되면
  // Active : 20Mhz x 8(pll) = 160Mhz (외부 클럭)
  // IMO (8Mhz) Clock 설정 변경 (내부 클럭) 후 Deepsleep 진입
  // Deepsleep : 32.768Hz (ILO 내부클럭)으로 동작하여 EvtGen 의 기준 클럭으로 사용.
  // 일정 주기로 Wakeup 발생하면 LowpowerActive 모드로 천이되고 IMO 8Mhz (내부클럭)으로 동작함
  // Wakeup 조건에 만족하여 Wakeup 이 되면
  // ECO (160Mhz) Clock으로 변경함.

  // IMO 설정없이 사용하게 되면 deepsleep에서 LowpowerActive 반복시에 외부 클럭을
  // 반복적으로 start/stop을 하게 되므로 문제가 될수도 있다.
  // 외부 클럭은 안정화 시간도 필요하기 때문에 시간상 편차도 발생한다.
  // 그러므로 IMO 설정을 적용해야 한다.
  // IMO는 내부 클럭이므로 반복하더라도 더 안정적으로 사용가능하다.

  // 위의 클럭 ECO와 IMO 설정은 변경방법은  sleep / acative의 Port 일괄처리 처럼
  // 모빌젠 설정에서 McuClockSettingConfig_ACTIVE, McuClockSettingConfig_1_LPActive  이렇게 설정을 만들어서
  // L2H와 H2L가 호출될때
  // Mcu_InitClock(ECUM_MCU_NORMAL_CLOCK); // IMO (8Mhz) --> ECO (20Mhz) 변환
  // Mcu_InitClock(1u); // ECO (20Mhz) --> IMO (8Mhz)변환
  // 클럭 설정 변경 함수를 실행되도록 한다. (한원진 수석)

/***************************************************************************************************
@param[in]  void
@return     void
@note       Mode Server : BSW Init Completed (POR Init Process : Step 1)
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) AppMode_InitCompleted(void)
{
  Rte_ModeType_MDG_InitState LddPrevInitState, LddNextInitState;
  (void)Rte_Mode_modeNotificationPort_InitState_InitState(&LddPrevInitState, &LddNextInitState);

  /* Condition when BSW initialization completed */
  if (LddNextInitState == RTE_MODE_MDG_InitState_COMPLETE)
  {
	  Mode.Int.BswInitFlag = ON;
  }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Mode Server : Return Value >> BswInitFlag (POR Init Process : Step 2) : NvM Init Start
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) Mode_CS_ModeInit_Runnable(OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) BswInit)/* PRQA S 3432 1 */
{
	*BswInit = Mode.Int.BswInitFlag;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Mode Server : Setting Value >> NvMInitFlag (POR Init Process : Step 3) : NvM Init Completed
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) Mode_CS_NvMInit_Runnable(IN VAR(uint8, AUTOMATIC) NvMInit)
{
	Mode.Int.NvMInitFlag = NvMInit;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Mode Server : Return Value >> Application Start (POR Init Process : Step 4) : Init Complete!! App RUN
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) Mode_CS_ApplicationInit_Runnable(OUT P2VAR(uint8, AUTOMATIC, RTE_APPL_DATA) AppInit)/* PRQA S 3432 1 */
{
	if((Mode.Int.BswInitFlag == ON) &&
	   (Mode.Int.NvMInitFlag == ON)){
		Mode.Int.App_Init_Completed = ON;   /* Application RUN !! */
	}else{
		Mode.Int.App_Init_Completed = OFF;
	}

	*AppInit = Mode.Int.App_Init_Completed;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       EcuMode updated from BswM
***************************************************************************************************/
FUNC(void, SWC_AppMode_CODE) AppMode_EcuModeSwitched(void)
{
  Rte_ModeType_EcuMode LddPrevEcuMode, LddNextEcuMode;
  (void)Rte_Mode_modeNotificationPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);


  if (LddNextEcuMode == RTE_MODE_EcuMode_ECUM_STATE_RUN)
  {
	/* Condition when ECU state changed from STARTUP to RUN */
	if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_INITIAL_MODE)
	{
	/* first It need to the Run Request */
	   	Rte_Call_clientPort_StateRequest_RequestRUN(APP_MODE_USER); // 복구함.. init 초기 처리이므로 해줘야 할것 같음

	/* This code is executed only once shortly after Rte_Start */
	//   Rte_Write_P_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_FULL_COM);
	//   Rte_Write_P_modeRequestPort_ComMMode_LCAN_ComMMode_LCAN(COMM_MODE_FULL_COM);

		Mode.Int.WakeupEvent_INIT_MODE = ON;
		Mode.Int.WakeupEventValid = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE_; // for monitoring
	}
	/* Condition when ECU state changed from SLEEP to RUN */
	else
	{
		// M3CM Rule-15.7
	}
	/* When State is RTE_MODE_EcuMode_ECUM_STATE_RUN, execute last */
	Rte_Call_clientPort_StateRequest_SetRunState();
  }
  /* FullCom Request for Integration Test */
  /* This action depends on Application Requirement, Modify Here */
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       wakeup event occurs
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_WakeupEventValidated(void)
{
  	Rte_ModeType_MDG_WakeupEvent LddPrevWakeupEvent;

 	(void)Rte_Mode_modeNotificationPort_WakeupEvent_WakeupEvent(&LddPrevWakeupEvent, &AppMode_GddWakeupEvent);
  	//LddCurrEcuMode = Rte_Mode_R_modeSwitchPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);

	// 디버그 상에서 가식성 높도록 redefine값으로 설정함.
	if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_IGN1)// ign에 의한 wakeup
	{
		Mode.Int.WakeupEvent_IGN1 = ON;
	}
	else if (AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_BCAN_RX) // bcan에 의한 wakeup
	{
		Mode.Int.WakeupEvent_BCAN_RX = ON;
	}	
	else if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_BCAN_RX_POLL)
	{
		Mode.Int.WakeupEvent_BCAN_RX_POLL = ON;		
	}
	else if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_LCAN_RX) // lcan에 의한 wakeup
	{
		Mode.Int.WakeupEvent_LCAN_RX = ON;
	}	
	else if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_LCAN_RX_POLL)
	{
		Mode.Int.WakeupEvent_LCAN_RX_POLL = ON;
	}
	else
	{
		// M3CM Rule-15.7
	}

	Mode.Int.WakeupEventValid = (WakeupEvent_t)AppMode_GddWakeupEvent; // for monitoring
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
// LCAN도 ComMModeSwitched_PNC32가 있어야 할것 같은데 모빌젠의 BswM에 LCAN/ BCAN으로 CoMMode가 PNC32 구분되어 있지 않아서 2개를 생성할수가 없다.
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_PNC32(void) 
{

  	Rte_ModeType_MDG_ComMMode_PNC LddPrevPncSubState, LddNextPncSubState;
  	Rte_Mode_modeNotificationPort_ComMMode_PNC32_ComMMode_PNC32(&LddPrevPncSubState, &LddNextPncSubState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  /* Conditions when Com Mode PNC Requested switched */
  if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED)
  {
	Mode.Out.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED;
	Mode.Int.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED_;
  }
  /* Conditions when Com Mode PNC Ready Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP;
	Mode.Int.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP_;
  }
  /* Conditions when Com Mode PNC Prepare Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP;
	Mode.Int.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP_;
  }
  /* Conditions when Com Mode NO COM switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION_;
  }
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC32 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION_;
  }
  else
  {
    // M3CM Rule-15.7
  }
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_PNC141(void)
{

  	Rte_ModeType_MDG_ComMMode_PNC LddPrevPncSubState, LddNextPncSubState;
  	Rte_Mode_modeNotificationPort_ComMMode_PNC141_ComMMode_PNC141(&LddPrevPncSubState, &LddNextPncSubState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  /* Conditions when Com Mode PNC Requested switched */
  if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED)
  {
	Mode.Out.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED;
	Mode.Int.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED_;
  }
  /* Conditions when Com Mode PNC Ready Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP;
	Mode.Int.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP_;
  }
  /* Conditions when Com Mode PNC Prepare Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP;
	Mode.Int.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP_;
  }
  /* Conditions when Com Mode NO COM switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION_;
  }
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC141 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION_;
  }
  else
  {
    // M3CM Rule-15.7
  }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_PNC153(void)
{

  Rte_ModeType_MDG_ComMMode_PNC LddPrevPncSubState, LddNextPncSubState;
  Rte_Mode_modeNotificationPort_ComMMode_PNC153_ComMMode_PNC153(&LddPrevPncSubState, &LddNextPncSubState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  /* Conditions when Com Mode PNC Requested switched */
  if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED)
  {
	Mode.Out.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED;
	Mode.Int.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED_;
  }
  /* Conditions when Com Mode PNC Ready Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP;
	Mode.Int.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP_;
  }
  /* Conditions when Com Mode PNC Prepare Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP)
  {
	Mode.Out.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP;
	Mode.Int.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP_;
  }
  /* Conditions when Com Mode NO COM switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION_;
  }
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION)
  {
	Mode.Out.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION;
	Mode.Int.BCAN_ComMModePNC153 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION_;
  }
  else
  {
    // M3CM Rule-15.7
  }

}

/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_PNC159(void)
{

  Rte_ModeType_MDG_ComMMode_PNC LddPrevPncSubState, LddNextPncSubState;
  Rte_Mode_modeNotificationPort_ComMMode_PNC159_ComMMode_PNC159(&LddPrevPncSubState, &LddNextPncSubState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  /* Conditions when Com Mode PNC Requested switched */
  if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED)
  {
	Mode.Out.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED;
	Mode.Int.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_REQUESTED_;
  }
  /* Conditions when Com Mode PNC Ready Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP)
  {
	Mode.Out.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP;
	Mode.Int.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_READY_SLEEP_;
  }
  /* Conditions when Com Mode PNC Prepare Sleep switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP)
  {
	Mode.Out.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP;
	Mode.Int.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_PREPARE_SLEEP_;
  }
  /* Conditions when Com Mode NO COM switched */
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION)
  {
	Mode.Out.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION;
	Mode.Int.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_NO_COMMUNICATION_;
  }
  else if (LddNextPncSubState == RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION)
  {
	Mode.Out.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION;
	Mode.Int.LCAN_ComMModePNC159 = RTE_MODE_MDG_ComMMode_PNC_PNC_FULL_COMMUNICATION_;
  }
  else
  {
    // M3CM Rule-15.7
  }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_BCAN_Runnable(void)
{
	// 디버깅 상으로는 full comm을 치지 않아도 외부 제어기에 의해서
	// 통신이 재개되면 Full Comm으로 브레이크가 걸리는듯함.
	// 확인 필요.

	// 1. Rte_Write_P_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_NO_COM); 호출하면
	// 2. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_SILENT_COM; 호출되고 일정 시간 후 (1.5초)
	// 3. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_NO_COM; 그 다음 no comm 호출된다.


	// 1. Rte_Write_P_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_FULL_COM); 호출하면
	// 2. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_FULL_COM; 호출된다.

  	Rte_ModeType_MDG_ComMMode LddPrevBusState, LddNextBusState;
  	Rte_Mode_modeNotificationPort_ComMMode_BCAN_ComMMode_BCAN(&LddPrevBusState, &LddNextBusState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when Com Mode No Com switched */
  	if (LddNextBusState == RTE_MODE_MDG_ComMMode_NO_COM) 	// no comm 치고 실제 노드가 no comm이 되면 여기로 콜됨. // WPC_82_04
  	{
	  	Mode.Out.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_NO_COM;
		Mode.Int.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_NO_COM_;
  	}
  	/* Conditions when Com Mode Silent Com switched */
  	else if (LddNextBusState == RTE_MODE_MDG_ComMMode_SILENT_COM)
  	{
	  	Mode.Out.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_SILENT_COM;
		Mode.Int.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_SILENT_COM_;
  	}
  	/* Conditions when Com Mode Full Com switched */
  	else if (LddNextBusState == RTE_MODE_MDG_ComMMode_FULL_COM)// can bus에 통신 발생해서 wakeup  발생해서 full comm치고 노드가 full com이 되면 여기 콜됨. // WPC_82_04
  	{
		Mode.Out.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_FULL_COM;
		Mode.Int.ComMMode_BCAN = RTE_MODE_MDG_ComMMode_FULL_COM_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       ComM Mode switched
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_ComMModeSwitched_LCAN_Runnable(void)
{
	// 디버깅 상으로는 full comm을 치지 않아도 외부 제어기에 의해서
	// 통신이 재개되면 Full Comm으로 브레이크가 걸리는듯함.
	// 확인 필요.

	// 1. Rte_Write_P_modeRequestPort_ComMMode_LCAN_ComMMode_LCAN(COMM_MODE_NO_COM); 호출하면
	// 2. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_SILENT_COM; 호출되고 일정 시간 후 (1.5초)
	// 3. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_NO_COM; 그 다음 no comm 호출된다.


	// 1. Rte_Write_P_modeRequestPort_ComMMode_LCAN_ComMMode_LCAN(COMM_MODE_FULL_COM); 호출하면
	// 2. Mode.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_FULL_COM; 호출된다.

  	Rte_ModeType_MDG_ComMMode LddPrevBusState, LddNextBusState;
  	Rte_Mode_modeNotificationPort_ComMMode_LCAN_ComMMode_LCAN(&LddPrevBusState, &LddNextBusState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when Com Mode No Com switched */
  	if (LddNextBusState == RTE_MODE_MDG_ComMMode_NO_COM)
  	{
		Mode.Out.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_NO_COM;
		Mode.Int.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_NO_COM_;
  	}
  	/* Conditions when Com Mode Silent Com switched */
  	else if (LddNextBusState == RTE_MODE_MDG_ComMMode_SILENT_COM)
  	{
		Mode.Out.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_SILENT_COM;
		Mode.Int.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_SILENT_COM_;
  	}
  	/* Conditions when Com Mode Full Com switched */
  	else if (LddNextBusState == RTE_MODE_MDG_ComMMode_FULL_COM)// can bus에 통신 발생해서 wakeup  발생해서 full comm치고 노드가 full com이 되면 여기 콜됨. // WPC_82_04
  	{
		Mode.Out.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_FULL_COM;
		Mode.Int.ComMMode_LCAN = RTE_MODE_MDG_ComMMode_FULL_COM_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Tx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC32_Tx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupTx_BCAN_PNC32_PduGroupTx_BCAN_PNC32(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupTx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupTx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Rx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC32_Rx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupRx_BCAN_PNC32_PduGroupRx_BCAN_PNC32(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupRx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupRx_BCAN_PNC32 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Tx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC141_Tx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupTx_BCAN_PNC141_PduGroupTx_BCAN_PNC141(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupTx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupTx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Rx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC141_Rx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupRx_BCAN_PNC141_PduGroupRx_BCAN_PNC141(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupRx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupRx_BCAN_PNC141 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Tx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC153_Tx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupTx_BCAN_PNC153_PduGroupTx_BCAN_PNC153(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupTx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupTx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupTx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Rx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_BCAN_PNC153_Rx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupRx_BCAN_PNC153_PduGroupRx_BCAN_PNC153(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupRx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
	  	Mode.Out.PduGroupRx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupRx_BCAN_PNC153 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Tx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_LCAN_PNC32_Tx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupTx_LCAN_PNC32_PduGroupTx_LCAN_PNC32(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupTx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupTx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupTx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupTx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Rx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_LCAN_PNC32_Rx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupRx_LCAN_PNC32_PduGroupRx_LCAN_PNC32(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
	  	Mode.Out.PduGroupRx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupRx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
	  	Mode.Out.PduGroupRx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupRx_LCAN_PNC32 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       Com PduGroup Switched (Tx PduGroup 의 START/STOP 알림)
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_LCAN_PNC159_Tx(void)
{

  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupTx_LCAN_PNC159_PduGroupTx_LCAN_PNC159(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupTx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupTx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupTx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupTx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       CanSM PduGroup Switched (Rx PduGroup 의 START/STOP 알림)
***************************************************************************************************/

FUNC (void, SWC_AppMode_CODE) AppMode_PduGroupSwitched_LCAN_PNC159_Rx(void)
{
  	Rte_ModeType_MDG_PduGroup LddPrevPduState, LddNextPduState;
  	Rte_Mode_modeNotificationPort_PduGroupRx_LCAN_PNC159_PduGroupRx_LCAN_PNC159(&LddPrevPduState, &LddNextPduState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when PduGroup stopped */
  	if (LddNextPduState == RTE_MODE_MDG_PduGroup_STOP)
  	{
		Mode.Out.PduGroupRx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_STOP;
		Mode.Int.PduGroupRx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_STOP_;
  	}
  	/* Conditions when PduGroup started */
  	else if (LddNextPduState == RTE_MODE_MDG_PduGroup_START)
  	{
		Mode.Out.PduGroupRx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_START;
		Mode.Int.PduGroupRx_LCAN_PNC159 = RTE_MODE_MDG_PduGroup_START_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       CanSM Busoff Recovery State
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_CanSMBORStateSwitched_BCAN(void)
{
  	Rte_ModeType_MDG_CanSMBORState LddPrevState, LddNextState;
  	Rte_Mode_modeNotificationPort_CanSMBORState_BCAN_CanSMBORState_BCAN(&LddPrevState, &LddNextState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when bus-off recovery started */
  	if (LddNextState == RTE_MODE_MDG_CanSMBORState_START)
  	{
	 	Mode.Out.CanSMBORState_BCAN = RTE_MODE_MDG_CanSMBORState_START;
		Mode.Int.CanSMBORState_BCAN = RTE_MODE_MDG_CanSMBORState_START_;
  	}
  	/* Conditions when bus-off recovery completed */
  	else if (LddNextState == RTE_MODE_MDG_CanSMBORState_COMPLETE)
  	{
	 	Mode.Out.CanSMBORState_BCAN = RTE_MODE_MDG_CanSMBORState_COMPLETE;
		Mode.Int.CanSMBORState_BCAN = RTE_MODE_MDG_CanSMBORState_COMPLETE_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       CanSM Busoff Recovery State
***************************************************************************************************/
FUNC (void, SWC_AppMode_CODE) AppMode_CanSMBORStateSwitched_LCAN(void)
{
  	Rte_ModeType_MDG_CanSMBORState LddPrevState, LddNextState;
  	Rte_Mode_modeNotificationPort_CanSMBORState_LCAN_CanSMBORState_LCAN(&LddPrevState, &LddNextState);

// 디버그 상에서 가식성 높도록 redefine값으로 내부 변수 추가함
  	/* Conditions when bus-off recovery started */
  	if (LddNextState == RTE_MODE_MDG_CanSMBORState_START)
  	{
		Mode.Out.CanSMBORState_LCAN = RTE_MODE_MDG_CanSMBORState_START;
		Mode.Int.CanSMBORState_LCAN = RTE_MODE_MDG_CanSMBORState_START_;
  	}
  	/* Conditions when bus-off recovery completed */
  	else if (LddNextState == RTE_MODE_MDG_CanSMBORState_COMPLETE)
  	{
		Mode.Out.CanSMBORState_LCAN = RTE_MODE_MDG_CanSMBORState_COMPLETE;
		Mode.Int.CanSMBORState_LCAN = RTE_MODE_MDG_CanSMBORState_COMPLETE_;
  	}
  	else	// qac
  	{
		// M3CM Rule-15.7
  	}
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"
