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
#include "App_NFC.h"
#include "Rte_App_NFC.h"

#include "App_WCT.h"
#include "App_Uds.h"
#include "App_Model_types.h"

#include "Spi_Common.h"
#include "Icu_Cfg.h"
#include "Icu_Cfg.h"
#include "Icu.h"
#include "IcuCbk.h"


#ifdef NIDEC_PORTING	/* NIDEC_PORTING */
#include "Nfcrdlib.h"
#include "Nfcrdlib2.h"
// #include "phacDiscLoop.h"

#endif


#define App_NFC_START_SEC_CODE
#include "App_NFC_MemMap.h"

/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/


typedef enum
{
	cNFC_Disable,
	cNFC_CardProtection,
	cNFC_Enable,
	cNFC_Lpcd,
	cNFC_Nfc,
	cNFC_Picc,
	cNFC_ResetStandby,
	cNFC_Initial		// WPC_436_07
} NFCMode_ENUM_t;

typedef enum
{
	cNFC_Idle,					// 아무것도 하지 않는 idle 상태
	cNFC_Initialize,			// NFC 초기화 상태
	cNFC_Poll_TechDetect,		// Picc 모드에서 NFC 초기 검출 상태
	cNFC_Collision_Avoidance,	// NFC type까지 확정되어 can통신으로 NFC검출 송신하는 단계
	cNFC_Activation,			// NFC 통신 속도등을 설정하고 통신 enable 처리 하는 단계
	cNFC_CanTpDataReceive,      // IAU --> WPC : TP CAN Data Receive
	cNFC_NfcDataExchange,       // WPC <--> Phone : NFC Data Exchange
	cNFC_CanTpDataTransmit,     // WPC --> IAU : TP CAN Data Transmit
	cNFC_InitWaitDelay,			// st만의 특화된 부분. 초기화시 한번에 초기화 안될때 2번째 초기화 부분
	cNFC_WakeupStart,			// LPCD Start 처리 부분
	cNFC_WakeupCheck,			// LPCD wakeup 검출 대기 부분
	cNFC_PhnRemoveDelay			// picc 검출시 일정간격으로 하기 위해서 딜레이 하는 부분
} PollMode_ENUM_t;

typedef enum
{
	cCardProtection_Wait,
	cCardProtection_Detecting,
	cCardProtection_Detected
} CPMode_ENUM_t;


// WPC_162_07

// NFC Reset Time
#define Par_NFCResetTime   		( 50u / TIME_5MS)
// WPC to NFC Tx/Rx Timeout
#define Par_WPCtoNFCTxRxTimeout (1000u / TIME_5MS)
// WPC to IAU Tx/Rx Timeout
#define Par_WPCtoIAUTxRxTimeout (2000u / TIME_5MS)


//#define Par_PollStartWaitTime 	( 200u / TIME_5MS) // WPC(충전중) --> NFC로 천이시에는 NFC 검출이 안되서 딜레이 타임 적용함.
#define Par_PollStartWaitTime 	(  50u / TIME_5MS) // WPC(충전중) --> NFC로 천이시에는 NFC 검출이 안되서 딜레이 타임 적용함. DK1.0만 해당됨. DK2.0은 잘됨. DK1.0은 지원될 필요 없다고 하므로 50ms 로 변경함
#define Par_rfalOfftWaitTime 	(  50u / TIME_5MS)

#define Par_LPCDIntervalTime 	( 120u / TIME_5MS) // WPC_174_01 // WPC_162_05 // WPC_149_05

// WPC_157_01
#define Par_PhoneRemoveTimeout 	( 1000u / TIME_5MS) // WPC_162_06 // 아이폰은 nfc 응답 대기 시간
#define Par_PhoneRemoveDlyTime 	(  500u / TIME_5MS) // nfc응답 후 fieldoff함. 다음 fieldon까지 대기시간 (너무 빠르게 하면 nfc 응답 안할때 발생함)
#define Par_NidecBusyFailTime	( 2000u / TIME_5MS) // // WPC --> IAU : p_tWaitingDelay4 : 2.0sec 이 타이머와 비슷하게 2초로 함
// WPC_157_01

#define Par_NFCSearchingOffDelayTime	( 400u / TIME_5MS)	// WPC_428_03
#define Par_NFCSearchingOffDelay2Time	( 550u / TIME_5MS)	// 모델에서 대기하는 500ms 보다 50ms 길게하여 먼저 천이 되는 경우 없도록 한다.
#define Par_NFCNoDetectionDelayTime		( 1000u / TIME_5MS)	// No Detection 판단 시간

#define Par_PICCSearchingDelay			( 500u / TIME_5MS)	// WPC_428_01
#define Par_PICCDetectDelay				(1000u / TIME_5MS)	// WPC_436_07 // WPC_428_01 // Type1과 동일사양 적용
#define Par_ForceTransDelay				(2000u / TIME_5MS)	// WPC_436_06

#define Par_SwapDelayLPCD				(1000u / TIME_5MS)	// WPC_436_06
#define Par_SwapDelayPICC				(1000u / TIME_5MS)	// WPC_436_06

// NFCA Poll ==============================================================


/* Data Buffer Length */
#define     DEMO_RXBUF_LEN              270u			// 버퍼 싸이즈 270이 맞는지? 줄어든것 아닌가?
#define     DEMO_TXBUF_LEN              270u


/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

// enum 에 타이머명 추가시 자동으로 타이머 변수 1개가 배열로 추가됨.
typedef enum
{
	Tim_NFCResetWait,
	Tim_WPCtoNFCTxRxTimeout,
	Tim_WPCtoIAUTxRxTimeout,
	Tim_NFCSearchingOffDelay,
	Tim_NFCSearchingOffDelay2,
	Tim_NFCNoDetectionDelay,		/* No Detection 신호 추가 */
	Tim_PICCSearchingDelay,
	Tim_PICCDetectDelay,
	//Tim_NFCCommunicationErrorsDelay, // 타이머 start cancel 을 하지만 비교하는 로직이 없다. 실제로는 미사용코드나 마찬가지여서 start/stop 코드와 선언 주석처리함.
	Tim_LPCDStartDelay,
	Tim_LPCDSwapDelay,
	Tim_PICCSwapDelay,
	Tim_NFC_MAX
}NFC_TMR_ENUM_t;

typedef enum
{
	Self_LPCD,
	Self_NFC,
	Self_PICC,
	Self_MAX
}NFC_State_ENUM_t;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

//=============================================
typedef struct
{
	uint8_t Runnable_State;
	uint8_t App_Init_Completed;

	NFCMode_ENUM_t StateCurr[Device_MAX];				// Current State
	NFCMode_ENUM_t StateNext[Device_MAX];				// Next State
	NFCMode_ENUM_t StateOld[Device_MAX];				// Old State

	uint8_t EntryCnt[Device_MAX];					// Entry Count
	uint8_t ExitCnt[Device_MAX];					// Exit Count
	uint8_t StateSelfTrans[Device_MAX][Self_MAX];	// Self Trans

	PollMode_ENUM_t PollState[Device_MAX];
	CPMode_ENUM_t CardProtectionState[Device_MAX];

	uint8_t InitComplete[Device_MAX];				// Initialize Complete. 230510

	uint8_t CanTpRxCompleteReq;
	uint8_t CanTpRxDataLen;

	uint8_t TpRxTempBuf[DEMO_RXBUF_LEN];
	uint8_t TpTxBuf[DEMO_RXBUF_LEN];
	uint8_t TpRxBuf[DEMO_RXBUF_LEN];

	uint8_t NFC_ExitFlag[Device_MAX];			// WPC_436_06
	uint8_t NFC_CommError[Device_MAX];			// WPC_436_08	// NFC Communication Error
	uint16_t NFC_CommErrorStatus[Device_MAX];	// WPC_436_08	// NFC Communication Error

	Event_t	NFCDetection_Evt[Device_MAX];
	Event_t NFCReset_Evt[Device_MAX];
	Event_t LPCD_Wakeup_Evt[Device_MAX];
	Event_t LC_IAUWPCNFCcmd_Evt[Device_MAX];

	uint8_t NFC_IAUWPCNFCcmd[Device_MAX];		// non event

	uint8_t NFC_NFCSelfTrans[Device_MAX];		// Self Trans
	uint8_t NFC_LPCDSelfTrans[Device_MAX];
	uint8_t NFC_PICCSelfTrans[Device_MAX];

	uint8_t PICC_ResetFlag[Device_MAX];
	uint8_t PICC_SearchDelay[Device_MAX];

	uint8_t NFC_LPCDSwapFunction;
	uint8_t NFC_LPCDSwapDevice;

	uint8_t NFC_PICCSwapFunction;
	uint8_t NFC_PICCSwapDevice;	
}Inter_t;

typedef struct
{
	IDT_ADC_STR 		Inp_ADC;
	IDT_Mode_STR 		Inp_Mode;
	IDT_Model_STR		Inp_Model;
	IDT_CAN_RX_STR		Inp_CAN_RX;
	IDT_Uds_STR 		Inp_Uds;
	IDT_WCT_STR			Inp_WCT;
	IDT_NvM_STR			Inp_NvM;

	Inter_t 			Int;
	Timer_t 			Timer[Device_MAX][Tim_NFC_MAX];

	IDT_NFC_STR 		Out;
} NFC_struct;


static NFC_struct NFC = {0};

/***************************************************************************************************
    GLOBAL VARIABLES AND CONSTANTS
***************************************************************************************************/
//uint32_t	GptCounter_1ms = 0;
//uint32_t	GptCounter_10ms = 0;

#if defined (DEBUG_TUNE_MODE_USE)
// dvp data 수신전에는 기존 default 값으로 동작하도록 한다.
uint16_t Tune_LPCD_RSSI_TARGET = 0x0150; // 0x000 ~ 0xFFF
uint8_t Tune_LPCD_AVG_SAMPLE_NUM = 6; // 0~6 : in power of 2 (6: 2^6=64 samples). See LPCD_AVG_SAMPLES
uint8_t Tune_LPCD_VDDPA = 0x0C; // 1.5 ~ 2.7V	/* NXP Module 230208 */
uint8_t Tune_LPCD_PULSE_WIDTH = 5; // Pulse width of LPCD = LPCD_PULSE_WIDTH + 20 (offset);
uint8_t Tune_LPCD_THRESHOLD_I = 120; // LPCD_THRESHOLD_COARSE 0~1 bytes
uint8_t Tune_LPCD_THRESHOLD_Q = 120; // LPCD_THRESHOLD_COARSE 2~3 btyes
uint8_t  Tune_VDDPA_HIGH_VALUE = 0x12;		// 0x00=1.5V, 0x12=3.3V, 0x20=4.7V, 0x23=5.0V

#endif

/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
//<<함수 선언시 함수설명에 대한 주석을 기입하지 않는다.>>
//<<함수에 대한 설명은 아래 함수 본문 위쪽에 주석으로 기입한다.>>

static void ss_NFC_InitSet(void);
static void ss_NFC_Data_Init(uint8_t Device);
// static void ss_NFC_GptStop1(void);
// static void ss_NFC_GptStart1(uint16_t gtim);

static void ss_NFC_StateMachine(uint8_t Device, uint8_t CurrState, uint8_t action);
static void ss_NFC_Disable(uint8_t Device, uint8_t action);
static void ss_NFC_Enable(uint8_t Device, uint8_t action);
static void ss_NFC_Initial(uint8_t Device, uint8_t action);
static void ss_NFC_Lpcd(uint8_t Device, uint8_t action);
static void ss_NFC_Nfc(uint8_t Device, uint8_t action);
static void ss_NFC_Picc(uint8_t Device, uint8_t action);
static void ss_NFC_ResetStandby(uint8_t Device, uint8_t action);
static void ss_NFC_ResetControl(uint8_t Device);
static void ss_NFC_CardProtection(uint8_t Device, uint8_t action);

static void ss_NFC_LPConditionCheck(uint8_t Device);
static void ss_NFC_RteRead(void);
static void ss_NFC_RteWrite(void);


/* Dual NFC State Main Control Function */
static void ss_Dual_NFC_Initialize(uint8_t Device);
static void ss_Dual_NFC_LPCD(uint8_t Device);
static void ss_Dual_NFC_NFC(uint8_t Device);
static void ss_Dual_NFC_PICC(uint8_t Device);
static void ss_Dual_NFC_CardProtection(uint8_t Device);

/* Dual NFC SWAP MACHINE */
static void ss_Dual_LPCD_Swap_Machine(void);
static void ss_Dual_PICC_Swap_Machine(void);

/* Dual NFC Control */
static uint16_t ss_Dual_NXP_NfcRdLib_Init(uint8_t Device);
static void ss_Dual_NXP_LPCD_MainControl_Init(uint8_t Device);
static void ss_Dual_NXP_LPCD_MainControl(uint8_t Device);
static void ss_Dual_NXP_NFC_MainControl_Init(uint8_t Device);
static uint16_t ss_Dual_NXP_NFC_MainControl(uint8_t Device, uint8_t dataExchange, uint8_t* pTxBuff, uint16_t length);
static void ss_Dual_NXP_PICC_MainControl_Init(uint8_t Device);
static uint16_t ss_Dual_NXP_PICC_MainControl(uint8_t Device);
// static uint16_t ss_Dual_NXP_CardProtection_MainControl_Init(uint8_t Device);
// static uint8_t ss_Dual_NXP_CardProtection_MainControl(uint8_t Device);
static DIST_RESULT_t ss_Dual_NXP_CardProtection_MainControl(uint8_t Device);

static void ss_Dual_NXP_Field_OFF(uint8_t Device);

/* Dual NFC Get Function */
static uint8_t ss_Dual_Get_NXP_NFC_DetectCheck(uint8_t Device);
static uint8_t ss_Dual_Get_NXP_NFC_DataExchangeCheck(uint8_t Device);
static uint8_t * ss_Dual_Get_NXP_NFC_CanTpTxBuf(uint8_t Device);
static uint8_t ss_Dual_Get_NXP_NFC_CanTpTxSize(uint8_t Device);
static uint8_t ss_Dual_Get_NXP_LPCD_WakeupCheck(uint8_t Device);
static uint8_t ss_Dual_Get_NXP_PICC_OnThePad(uint8_t Device);
static uint8_t ss_Dual_Get_NXP_NfcModeExitReady(uint8_t Device);

static uint8_t ss_Dual_Get_NXP_NFC_CommunicationErrorsCheck(uint8_t Device);
static uint16_t ss_Dual_Get_NXP_NFC_CommunicationErrorsStatus(uint8_t Device);

// for nfc test
static uint16_t NFC_Transmit = 1000;
static uint16_t NFC1_JobEnd = 1000;
static uint16_t NFC1_SeqEnd = 1000;
static uint16_t NFC2_JobEnd = 1000;
static uint16_t NFC2_SeqEnd = 1000;

static uint8_t RxDataBuf[38] = {0}; // Rx Data Buf
static uint8_t TxDataBuf[24] = {0};
static uint16_t TxRxLength = 0;
static uint8_t data = 0;

uint8_t  gs_SPI_TxRx(uint8_t Channel, uint8_t * TxBuf, uint8_t* RxBuf, uint16_t TxRxLength);

/*#################################################################################################
    GLOBAL FUNCTIONS
#################################################################################################*/
uint8_t gs_Get_NFC_PollState(uint8_t Device) {return NFC.Int.PollState[Device];}

uint8_t gs_Get_NfcStateCurr(uint8_t Device) {return NFC.Int.StateCurr[Device];}

uint8_t* Get_CanTpRxBuf(void) {return NFC.Int.TpRxBuf;}

uint8_t Get_CanTpRxSize(void) {return NFC.Int.CanTpRxDataLen;}

uint8_t Get_CanTpRxComplete(void) {return NFC.Int.CanTpRxCompleteReq;}

#define RTE_ALLOW_CROSS_HEADER_INCLUSION  // 미선언시 컴파일 오류 발생함.
#include "Rte_App_WDT.h"				// Rte_Call_R_WDT_EN_WriteDirect(OFF) 사용하기 위해서
static uint8_t WdtPulseToggle = 1;
#define Par_NFCToggle				(500u / TIME_5MS)


/***************************************************************************************************
@param[in]  void
@return     void
@note		5ms Task
***************************************************************************************************/

/* 연속 카드 프로텍션 테스트 */
uint8_t TEST_CardProtectionReq[Device_MAX] = {OFF, OFF};
uint16_t tim_test[Device_MAX] = {0u, 0u};
/* 연속 카드 프로텍션 테스트 */

FUNC(void, App_NFC_CODE) NFC_TE_Runnable(void)
{
	uint8_t retValue;

	switch(NFC.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&NFC.Int.App_Init_Completed);

			if( NFC.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
				/* SWC Init Process */
				ss_NFC_InitSet();

				NFC.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */
			}

		break;

		case 1u:



			//------------------------------------------------------
			// Input
			//------------------------------------------------------

			ss_NFC_RteRead();

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
			if((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
			(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
			{
				ss_Dual_LPCD_Swap_Machine();	// 풀어서 써야 함.
				ss_Dual_PICC_Swap_Machine();	// 풀어서 써야 함.
			}
//#endif
			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------
			for(uint8_t Device = 0; Device < NFC.Inp_NvM.DeviceMaxCnt; Device++)	// WCT Device0, Device1 독립제어용으로 변경함.
			{
				// uint8_t Device = D0;	// TEST 채널별 테스트용
				// uint8_t Device = D1;	// TEST 채널별 테스트용

/* 연속 카드 프로텍션 테스트 */
// if(tim_test[Device]++ >= 250)
// {
// 	if(Device == D0)
// 	// if(Device == D1)
// 	{		
// 		if(TEST_CardProtectionReq[Device] == OFF)	TEST_CardProtectionReq[Device] = ON;
// 		// else 								TEST_CardProtectionReq[Deviece] = OFF;
// 		tim_test[Device] = 0;
// 	}
// }
/* 연속 카드 프로텍션 테스트 */

				NFC.Int.StateSelfTrans[Device][Self_NFC] = OFF;	// 매주기 클리어

				ss_NFC_StateMachine(Device, NFC.Int.StateCurr[Device], DURING);

				// 상태 천이 발생시에만 실행
				if(	(NFC.Int.StateCurr[Device] != NFC.Int.StateNext[Device]) ||
					(NFC.Int.StateSelfTrans[Device][Self_LPCD] == ON) ||
					(NFC.Int.StateSelfTrans[Device][Self_NFC]  == ON) ||
					(NFC.Int.StateSelfTrans[Device][Self_PICC] == ON) )
				{
					// 상태 천이 발생시 ex 실행 후 en 싫행
					ss_NFC_StateMachine(Device, NFC.Int.StateCurr[Device], EXIT);
					ss_NFC_StateMachine(Device, NFC.Int.StateNext[Device], ENTRY);

					NFC.Int.StateCurr[Device] = NFC.Int.StateNext[Device];
				}

				ss_NFC_LPConditionCheck(Device);

				//------------------------------------------------------
				// Time
				//------------------------------------------------------
				// gs_UpdateTimer(NFC.Timer[Tim_NFCResetWait]);
				// gs_UpdateTimer(NFC.Timer[Tim_NFCSearchingOffDelay]);
				// gs_UpdateTimer(NFC.Timer[Tim_NFCSearchingOffDelay2]);
				// gs_UpdateTimer(NFC.Timer[Tim_PICCSearchingDelay]);
				// gs_UpdateTimer(NFC.Timer[Tim_PICCDetectDelay]);
				// gs_UpdateTimer(NFC.Timer[Tim_NFCCommunicationErrorsDelay]);	// 230504. JJH

				gs_UpdateTimer(&NFC.Timer[Device][0], Tim_NFC_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
			}

			//-----------------------------------------------------
			// Output
			//------------------------------------------------------
			ss_NFC_RteWrite();	// WPC_5D_03

		break;

		default:
			NFC.Int.Runnable_State = 0u;
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_NFC_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&NFC.Inp_ADC);
	Rte_Read_R_CAN_RX_CAN_RX_STR(&NFC.Inp_CAN_RX);
	Rte_Read_R_Mode_Mode_STR(&NFC.Inp_Mode);
	Rte_Read_R_Model_Model_STR(&NFC.Inp_Model);
	Rte_Read_R_WCT_WCT_STR(&NFC.Inp_WCT);
	Rte_Read_R_NvM_NvM_STR(&NFC.Inp_NvM);

#if defined (DEBUG_TUNE_MODE_USE) // rf_config.c로 전달하기 위해서 글로벌 변수에 저장함.

	Rte_Read_R_Uds_Uds_STR(&NFC.Inp_Uds);
	if(NFC.Inp_Uds.DvpTuneData[0]  == Tune_Index_LPCD)
    {
		Tune_LPCD_RSSI_TARGET = NFC.Inp_Uds.DvpTuneData[1] << 8u +  NFC.Inp_Uds.DvpTuneData[2];
		Tune_LPCD_AVG_SAMPLE_NUM = NFC.Inp_Uds.DvpTuneData[3];
		Tune_LPCD_VDDPA = NFC.Inp_Uds.DvpTuneData[4];
		Tune_LPCD_PULSE_WIDTH = NFC.Inp_Uds.DvpTuneData[5];
		Tune_LPCD_THRESHOLD_I = NFC.Inp_Uds.DvpTuneData[6];
		Tune_LPCD_THRESHOLD_Q = NFC.Inp_Uds.DvpTuneData[7];
		Tune_VDDPA_HIGH_VALUE = NFC.Inp_Uds.DvpTuneData[8];
    }

#endif
	gs_UpdateEvent(NFC.Inp_CAN_RX.LCAN.LC_WPC_IAUWPCNFCcmd,	 &NFC.Int.LC_IAUWPCNFCcmd_Evt[D0]);		// event update
	NFC.Int.NFC_IAUWPCNFCcmd[D0] = NFC.Inp_CAN_RX.LCAN.LC_WPC_IAUWPCNFCcmd;
	
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	if((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
	(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
	{
		gs_UpdateEvent(NFC.Inp_CAN_RX.LCAN.LC_WPC2_IAUWPCNFCcmd, &NFC.Int.LC_IAUWPCNFCcmd_Evt[D1]);		// event update
		NFC.Int.NFC_IAUWPCNFCcmd[D1] = NFC.Inp_CAN_RX.LCAN.LC_WPC2_IAUWPCNFCcmd;
	}
//#endif
	for(uint8_t Device = 0; Device < NFC.Inp_NvM.DeviceMaxCnt; Device++)
	{
		NFC.Int.NFC_ExitFlag[Device] = ss_Dual_Get_NXP_NfcModeExitReady(Device);						// WPC_436_06	// NFC State 상태 천이 가능 여부 리턴
		NFC.Int.NFC_CommError[Device] = ss_Dual_Get_NXP_NFC_CommunicationErrorsCheck(Device);			// WPC_436_08	// NFC Communication Error
		NFC.Int.NFC_CommErrorStatus[Device] = ss_Dual_Get_NXP_NFC_CommunicationErrorsStatus(Device);	// WPC_436_08	// NFC Communication Error
	}

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_NFC_RteWrite(void)
{
	for(uint8_t Device = 0; Device < NFC.Inp_NvM.DeviceMaxCnt; Device++)
	{
		NFC.Out.Device[Device].NFC_Status = NFC.Int.StateCurr[Device];
		NFC.Out.Device[Device].NFCDetection = ss_Dual_Get_NXP_NFC_DetectCheck(Device);	// NFC Detection 검출 여부 리턴
		NFC.Out.Device[Device].LPCD_Wakeup = ss_Dual_Get_NXP_LPCD_WakeupCheck(Device);	// LPCD Wakeup 검출 여부 리턴

		// 신호 생성처에서 이벤트 신호로 방식으로 송신하도록 설계함. (이벤트 3회 default 3회 송신)
		// 이벤트 메세지는 RTE로 송신시에도 120ms on 유지후 off로 자동 변경
		// 아래 함수는 입력되는 값이이 1로 변경후 1을 계속 유지 하더라도 함수내에서 120ms 후에는 0으로 변경시킨다.
		gs_EventMsgAutoClear(&NFC.Out.Device[Device].NFCDetection, &NFC.Int.NFCDetection_Evt[Device], Par_CanAutoClearTime_Task5ms);
		gs_EventMsgAutoClear(&NFC.Out.Device[Device].NFCReset, &NFC.Int.NFCReset_Evt[Device], Par_CanAutoClearTime_Task5ms);
		gs_EventMsgAutoClear(&NFC.Out.Device[Device].LPCD_Wakeup, &NFC.Int.LPCD_Wakeup_Evt[Device], Par_AutoClearTime_20ms_Task5ms);
	}

	Rte_Write_P_NFC_NFC_STR(&NFC.Out);	// 구조체로 한꺼번에 전송
}


/*#################################################################################################
    LOCAL FUNCTIONS
#################################################################################################*/


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static  void    ss_NFC_InitSet(void)
{
	Rte_Read_R_NvM_NvM_STR(&NFC.Inp_NvM); // 전원 인가시 NvM Read 먼저 함.
	
	for(uint8_t Device = 0; Device < NFC.Inp_NvM.DeviceMaxCnt; Device++)
	{
		memset(&NFC.Out.Device[Device], 0, sizeof(NFC.Out.Device[Device]));  				// 구조체 변수를 0으로 클리어

		NFC.Int.StateCurr[Device] = cNFC_Disable;
		NFC.Int.StateNext[Device] = cNFC_Disable; // GN7.15_07
		NFC.Int.StateOld[Device] = cNFC_Disable;
		NFC.Int.EntryCnt[Device] = 0u;
		NFC.Int.ExitCnt[Device] = 0u;

		ss_NFC_Disable(Device, ENTRY);	// 전원 리셋시 WCT_Disble의 Entry를 강제로 1회 실행시켜줘야함.
	}
	

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static  void    ss_NFC_Data_Init(uint8_t Device)
{
	// gs_CancelTimer(&NFC.Timer[0][Tim_NFCResetWait]);
	// gs_CancelTimer(&NFC.Timer[0][Tim_NFCSearchingOffDelay]);
	// gs_CancelTimer(&NFC.Timer[Tim_NFCSearchingOffDelay2]);
	// gs_CancelTimer(&NFC.Timer[Tim_PICCSearchingDelay]);
	// gs_CancelTimer(&NFC.Timer[Tim_PICCDetectDelay]);
	// gs_CancelTimer(&NFC.Timer[Tim_NFCCommunicationErrorsDelay]);

	gs_InitTimer(&NFC.Timer[Device][0], Tim_NFC_MAX);	// 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
}

/***************************************************************************************************
@param[in]  CurrState : Current State
@param[in]	action : En, Do, Ex Condition
@return     void
@note       none
***************************************************************************************************/
static void ss_NFC_StateMachine(uint8_t Device, uint8_t CurrState, uint8_t action)
{
	switch (CurrState)
	{
	case cNFC_Disable:
		ss_NFC_Disable(Device, action);
		break;
	case cNFC_CardProtection:
		ss_NFC_CardProtection(Device, action);
		break;
	case cNFC_Enable:
		ss_NFC_Enable(Device, action);
		break;
	case cNFC_Lpcd:
		ss_NFC_Lpcd(Device, action);
		break;
	case cNFC_Nfc:
		ss_NFC_Nfc(Device, action);
		break;
	case cNFC_Picc:
		ss_NFC_Picc(Device, action);
		break;
	case cNFC_ResetStandby:
		ss_NFC_ResetStandby(Device, action);
		break;
	case cNFC_Initial:		// WPC_436_07	// Initial State 추가
		ss_NFC_Initial(Device, action);
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
static void ss_NFC_Disable(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		ss_NFC_Data_Init(Device);

		NFC.Int.InitComplete[Device] = OFF;	// WPC_436_07
		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if(NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if(NFC.Inp_WCT.Device[Device].CardProtectionReq == ON)
			// if(TEST_CardProtectionReq[Device] == ON)	/* 연속 카드 프로텍션 테스트 */
				// (NFC.Int.CPInitComplete[Device] == ON))
			{
				NFC.Int.StateNext[Device] = cNFC_CardProtection;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : cNFCMode_Enable
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			}
			else if(((NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode)  ||
					 (NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)   ||
					 (NFC.Inp_Model.Device[Device].WPCStatus == PICCMode)) &&
					 (NFC.Inp_ADC.BatSysStateFault == OFF) &&
					 (NFC.Int.InitComplete[Device] == ON))
			{
				if(NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Lpcd;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else if(NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Nfc;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else if(NFC.Inp_Model.Device[Device].WPCStatus == PICCMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Picc;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else
				{
					/* No Nothing */
				}
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_Initialize(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		/* No Nothing */
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
static void ss_NFC_CardProtection(uint8_t Device, uint8_t action)	// WPC_436_07
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		NFC.Int.CardProtectionState[Device] = cCardProtection_Wait;
		NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if(NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if(NFC.Inp_WCT.Device[Device].CardProtectionReq == OFF)
			// if(TEST_CardProtectionReq[Device] == OFF)	/* 연속 카드 프로텍션 테스트 */
			{
				NFC.Int.StateNext[Device] = cNFC_Disable;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : cNFCMode_Enable
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			} 
			else if(((NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode)  ||
					 (NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)   ||
					 (NFC.Inp_Model.Device[Device].WPCStatus == PICCMode)) &&
					 (NFC.Inp_ADC.BatSysStateFault == OFF) &&
					 (NFC.Int.InitComplete[Device] == ON))
			{
				if(NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Lpcd;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else if(NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Nfc;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else if(NFC.Inp_Model.Device[Device].WPCStatus == PICCMode)
				{
					NFC.Int.StateNext[Device] = cNFC_Picc;
					NFC.Int.EntryCnt[Device] = 1u;	// En 실행 : cNFCMode_Enable
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else
				{
					/* No Nothing */
				}
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_CardProtection(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;

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
static void ss_NFC_Enable(uint8_t Device, uint8_t action)
{
	static uint8_t ForcedTransCnt[Device_MAX] = {0, };

	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		ForcedTransCnt[Device] = 0U;	// WPC_436_06

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if ((NFC.Inp_Model.Device[Device].WPCStatus == ModeOff) ||
			(NFC.Inp_Model.Device[Device].WPCStatus == WPCMode) ||
			(NFC.Inp_ADC.BatSysStateFault == ON))
			{
				// NFC_Lpcd, NFC_Nfc, NFC_Picc 모두 동일한 depth이므로 state별로 만들지 않고 통합하여 1개로 처리함.
				NFC.Int.StateNext[Device] = cNFC_Disable;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 1u;  	// Ex 실행 : cNFCMode_Enable
			}
			// WPC_436_06
			else if(NFC.Int.NFC_IAUWPCNFCcmd[Device] == cIAUWPCNFC_Deselect)	// WPC_436_07
			{
				if(NFC.Int.StateCurr[Device] == cNFC_Nfc)
				{
					if(NFC.Int.NFC_ExitFlag[Device] == ON)
					{
						NFC.Int.StateNext[Device] = cNFC_ResetStandby;
						NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
						NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
					}
				}
				else
				{
					NFC.Int.StateNext[Device] = cNFC_ResetStandby;
					NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}

				if(ForcedTransCnt[Device] >= Par_ForceTransDelay)
				{
					NFC.Int.StateNext[Device] = cNFC_ResetStandby;
					NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				else
				{
					ForcedTransCnt[Device]++;
				}
			// WPC_436_06


			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				/* Do Nothing */
			}
		}
		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		ForcedTransCnt[Device] = 0U;	// WPC_436_06

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
static void ss_NFC_Lpcd(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		// 1. 상위(부모) Level State en 실행
		if (NFC.Int.EntryCnt[Device] > 0u)
		{
			NFC.Int.EntryCnt[Device]--;

			ss_NFC_Enable(Device, ENTRY);// WPC_157_04 // WPC_136_04
		}

		ss_Dual_NXP_LPCD_MainControl_Init(Device);

		// 2. 하위(자식) Level State en 실행
		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		ss_NFC_Enable(Device, DURING); // WPC_157_04 // WPC_136_04

		// 2. 하위(자식) Level State Transition 조건 확인
		if (NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if(NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)
			{
				NFC.Int.StateNext[Device] = cNFC_Initial;	// WPC_436_07
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;	// Ex 실행 : None
			}
			else if(NFC.Int.NFC_LPCDSelfTrans[Device] == ON)
			{
				NFC.Int.NFC_LPCDSelfTrans[Device] = OFF;

				NFC.Int.StateNext[Device] = cNFC_Initial;	// WPC_436_07
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;	// Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_LPCD(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		// 1. 하위(자식) Level State ex 실행


		// 2. 상위(부모) Level State ex 실행
		if (NFC.Int.ExitCnt[Device] > 0u)
		{
			NFC.Int.ExitCnt[Device]--;

			ss_NFC_Enable(Device, EXIT);// WPC_157_04 // WPC_136_04
		}

		break;

	//==============================================================
	default:
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_NFC_Nfc(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		// 1. 상위(부모) Level State en 실행
		if (NFC.Int.EntryCnt[Device] > 0u)
		{
			NFC.Int.EntryCnt[Device]--;

			ss_NFC_Enable(Device, ENTRY);// WPC_157_04 // WPC_136_04
		}

		// TP Flag Reset
		NFC.Int.CanTpRxCompleteReq = OFF;	// WPC_415_04
		//gs_StartTimer(&NFC.Timer[Tim_NFCCommunicationErrorsDelay]);	// WPC_436_08
		gs_StartTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);		/* No Detection 신호 추가 */
		
		// NXP_NFC_MainControl_Init();
		ss_Dual_NXP_NFC_MainControl_Init(Device);

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		ss_NFC_Enable(Device, DURING); // WPC_157_04 // WPC_136_04

		// 2. 하위(자식) Level State Transition 조건 확인
		if (NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if( (NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode) ||
				(NFC.Inp_Model.Device[Device].WPCStatus == PICCMode))
			{
				NFC.Int.StateNext[Device] = cNFC_Initial;	// WPC_436_07
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;	// Ex 실행 : None
			}
			else if(NFC.Int.LC_IAUWPCNFCcmd_Evt[Device].On_Event == cIAUWPCNFC_Polling)
			{
				// WPC_428_03
				NFC.Int.StateNext[Device] = cNFC_Nfc;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None

				NFC.Int.StateSelfTrans[Device][Self_NFC] = ON;	// self transition
				// NFC_StateSelfTransComplete[Device] = OFF;
				NFC.Int.NFC_NFCSelfTrans[Device] = ON;

				gs_StartTimer(&NFC.Timer[Device][Tim_NFCSearchingOffDelay]);
				gs_ReStartTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);	/* No Detection 신호 추가 */	// 여기에 적용하면 1초 그대로 적용
				// WPC_428_03
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_NFC(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		// 1. 하위(자식) Level State ex 실행
		// NXP_Field_OFF();	/* NXP Module 230213 */
		ss_Dual_NXP_Field_OFF(Device);	/* NXP Module 230213 */
		//gs_CancelTimer(&NFC.Timer[Tim_NFCCommunicationErrorsDelay]);	// WPC_436_08
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);	/* No Detection 신호 추가 */
		
		// 2. 상위(부모) Level State ex 실행
		if (NFC.Int.ExitCnt[Device] > 0u)
		{
			NFC.Int.ExitCnt[Device]--;

			ss_NFC_Enable(Device, EXIT);// WPC_157_04 // WPC_136_04
		}

		break;

	//==============================================================
	default:
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_NFC_Picc(uint8_t Device, uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		// 1. 상위(부모) Level State en 실행
		if (NFC.Int.EntryCnt[Device] > 0u)
		{
			NFC.Int.EntryCnt[Device]--;

			ss_NFC_Enable(Device, ENTRY);// WPC_157_04 // WPC_136_04
		}

		// 2. 하위(자식) Level State en 실행
		// gs_StartTimer(NFC_Tim.Tim_PICCSearchingDelay);
		NFC.Int.PICC_SearchDelay[Device] = 0u;				// WPC_428_01
		NFC.Int.PICC_ResetFlag[Device] = OFF;				// WPC_428_01
		NFC.Out.Device[Device].NfcOnThePad = OnThePad_Default;
		//gs_StartTimer(&NFC.Timer[Tim_NFCCommunicationErrorsDelay]);	// WPC_436_08
		gs_StartTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);

		// NXP_PICC_MainControl_Init();
		ss_Dual_NXP_PICC_MainControl_Init(Device);

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		ss_NFC_Enable(Device, DURING); // WPC_157_04 // WPC_136_04

		// 2. 하위(자식) Level State Transition 조건 확인
		if (NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if( (NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode) ||
				(NFC.Inp_Model.Device[Device].WPCStatus == NFCMode))
			{
				NFC.Int.StateNext[Device] = cNFC_Initial;	// WPC_436_07
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			}
			else if(NFC.Int.NFC_PICCSelfTrans[Device] == ON)
			{
				NFC.Int.NFC_PICCSelfTrans[Device] = OFF;

				NFC.Int.StateNext[Device] = cNFC_Initial;	// WPC_436_07
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;	// Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_PICC(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		// 1. 하위(자식) Level State ex 실행
		NFC.Out.Device[Device].NfcOnThePad = OnThePad_Default;

		// NXP_Field_OFF();	/* NXP Module 230213 */
		ss_Dual_NXP_Field_OFF(Device);	/* NXP Module 230213 */
		//gs_CancelTimer(&NFC.Timer[Tim_NFCCommunicationErrorsDelay]);	// WPC_436_08
		gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
		// gs_StartTimer(&NFC.Timer[Tim_PICCSearchingDelay]);

		// 2. 상위(부모) Level State ex 실행
		if (NFC.Int.ExitCnt[Device] > 0u)
		{
			NFC.Int.ExitCnt[Device]--;

			ss_NFC_Enable(Device, EXIT);// WPC_157_04 // WPC_136_04
		}

		break;

	//==============================================================
	default:
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_NFC_ResetStandby(uint8_t Device, uint8_t action) // WPC_136_04
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		// 1. 상위(부모) Level State en 실행
		if (NFC.Int.EntryCnt[Device] > 0u)
		{
			NFC.Int.EntryCnt[Device]--;

			ss_NFC_Enable(Device, ENTRY);
		}

		// 2. 하위(자식) Level State en 실행
		ss_NFC_ResetControl(Device);	// WPC_436_07

		// NFC.Out.Device[Device].LC_WPC_NFCReset = cNFCReset_Default;
		NFC.Out.Device[Device].NFCReset = cNFCReset_Default;
		// NFC field Off 명령 전송해야함.
		// NFC polling 을 멈추고 standby 상태를 유지 하고 있어야 하며 다시 Deselect나 Polling명령에 반응 할수 있는 상태에 있어야 함.
		gs_StartTimer(&NFC.Timer[Device][Tim_NFCResetWait]);			// WPC_436_07
		gs_StartTimer(&NFC.Timer[Device][Tim_NFCSearchingOffDelay2]);	// WPC_436_07

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		ss_NFC_Enable(Device, DURING);

		// 2. 하위(자식) Level State Transition 조건 확인
		if (NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if (NFC.Timer[Device][Tim_NFCSearchingOffDelay2].Count >= Par_NFCSearchingOffDelay2Time)
			{
				// WPC_436_07
				if( (NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode)	||
					(NFC.Inp_Model.Device[Device].WPCStatus == NFCMode)	||
					(NFC.Inp_Model.Device[Device].WPCStatus == PICCMode)	||
					(NFC.Int.NFC_IAUWPCNFCcmd[Device] == cIAUWPCNFC_Polling))
				{
					NFC.Int.StateNext[Device] = cNFC_Initial;
					NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
					NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
				}
				// WPC_436_07
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_NFC_ResetControl(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		// 1. 하위(자식) Level State ex 실행
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCResetWait]);
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCSearchingOffDelay2]);

		// 2. 상위(부모) Level State ex 실행
		if (NFC.Int.ExitCnt[Device] > 0u)
		{
			NFC.Int.ExitCnt[Device]--;

			ss_NFC_Enable(Device, EXIT);
		}

		break;

	//==============================================================
	default:
		break;
	}

}

/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_NFC_Initial(uint8_t Device, uint8_t action)	// WPC_436_07
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
		// 1. 상위(부모) Level State en 실행
		if (NFC.Int.EntryCnt[Device] > 0u)
		{
			NFC.Int.EntryCnt[Device]--;

			ss_NFC_Enable(Device, ENTRY);
		}

		NFC.Int.InitComplete[Device] = OFF;	// WPC_436_07

		// 2. 하위(자식) Level State en 실행
		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		ss_NFC_Enable(Device, DURING);

		// 2. 하위(자식) Level State Transition 조건 확인
		if(NFC.Int.StateCurr[Device] == NFC.Int.StateNext[Device])
		{
			// State's Transitions
			if( (NFC.Inp_Model.Device[Device].WPCStatus == LPCDMode) &&
				(NFC.Int.InitComplete[Device] == ON))
			{
				NFC.Int.StateNext[Device] = cNFC_Lpcd;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			}
			else if((NFC.Inp_Model.Device[Device].WPCStatus == NFCMode) &&
					(NFC.Int.InitComplete[Device] == ON))
			{
				NFC.Int.StateNext[Device] = cNFC_Nfc;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			}
			else if((NFC.Inp_Model.Device[Device].WPCStatus == PICCMode) &&
					(NFC.Int.InitComplete[Device] == ON))
			{
				NFC.Int.StateNext[Device] = cNFC_Picc;
				NFC.Int.EntryCnt[Device] = 0u;	// En 실행 : None
				NFC.Int.ExitCnt[Device] = 0u;  	// Ex 실행 : None
			}
			else
			{				
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Dual_NFC_Initialize(Device);
			}
		}

		break;

	//============= Sub State 탈출 시, 하위(자식) --> 상위(부모)수행
	case EXIT:
		// 1. 하위(자식) Level State ex 실행

		// 2. 상위(부모) Level State ex 실행
		if (NFC.Int.ExitCnt[Device] > 0u)
		{
			NFC.Int.ExitCnt[Device]--;

			ss_NFC_Enable(Device, EXIT);
		}

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
static void ss_NFC_ResetControl(uint8_t Device)
{
	// WPC_436_07
	if (NFC.Timer[Device][Tim_NFCResetWait].Count >= Par_NFCResetTime)

	{
		NFC.Out.Device[Device].NFCReset = cNFCReset_Complete;
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCResetWait]);
	}
	else
	{

	}
	// WPC_436_07
}


// /***************************************************************************************************
// @param[in]  void
// @return     void
// @note		gs_NFC_GptStart(time) 호출시 , time 마다. 이벤트 발생 1000 : 1ms, sleep to wakeup시 여기 호출됨. 조심할것.
// ***************************************************************************************************/
// FUNC (void, Cdd_NFC_CODE) NFC_Gpt_IE_Runnable(void)
// {
// 	gs_NFC_GptStop();
// }


// /***************************************************************************************************
// @param[in]  void
// @return     void
// @note		ss_NFC_GptStart1(time) 호출시 , time 마다. 이벤트 발생 1000 : 1ms sleep to wakeup시 여기 호출됨. 조심할것.
// ***************************************************************************************************/
// FUNC (void, Cdd_NFC_CODE) NFC_Gpt_0_1_IE_Runnable(void)
// {
// 	GptCounter_1ms++;
// }

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
uint8_t gs_NFC_IRQ_ReadDirect(void)
{
	uint8_t L_NFC_IRQ_Read = 0;

	Rte_Call_R_NFC1_IRQ_ReadDirect(&L_NFC_IRQ_Read);

	return L_NFC_IRQ_Read;
}

uint8_t gs_NFC_IRQ_ReadDirect2(void)
{
	uint8_t L_NFC_IRQ_Read = 0;

	Rte_Call_R_NFC2_IRQ_ReadDirect(&L_NFC_IRQ_Read);

	return L_NFC_IRQ_Read;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note 		NXP NFC IC의 VEN (RESET) Pin 제어 함수
***************************************************************************************************/
void gs_NFC_WAKEUP_WriteDirect(uint8_t level)
{

	Rte_Call_R_NFC1_WAKEUP_WriteDirect(level);
}

void gs_NFC_WAKEUP_WriteDirect2(uint8_t level)
{

	Rte_Call_R_NFC2_WAKEUP_WriteDirect(level);
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		CAN TP Data 수신 완료시 호출 함수
***************************************************************************************************/
FUNC(void, App_NFC_CODE) NFC_DRE_LCAN_TP_BDC_C_WPC_IE_Runnable(void)
{
	uint16_t	mwTPRxDataLen;

	Rte_Receive_LCAN_L_TP_BDC_FD_L_WPC_FD_LCAN_L_TP_BDC_FD_L_WPC_FD_signal(NFC.Int.TpRxTempBuf, &mwTPRxDataLen);// N.05_01

	memcpy(NFC.Int.TpRxBuf, NFC.Int.TpRxTempBuf, mwTPRxDataLen); // IAU 수신 데이터를 임시 버퍼(NFC.Int.TpRxTempBuf)에서 TP Data 수신 버퍼(NFC.Int.TpRxBuf)에 복사
	memset(NFC.Int.TpRxTempBuf, 0, mwTPRxDataLen); // 임시 버퍼 클리어, 버퍼 크기를 그냥 DEMO_RXBUF_LEN 크기로 해도 될듯

	NFC.Int.CanTpRxDataLen = mwTPRxDataLen;	// application에서사용하는 버퍼에 복사
	NFC.Int.CanTpRxCompleteReq = ON;
}



// /***************************************************************************************************
// @param[in]  void
// @return     void
// @note		GPT (general purpse timer) Stop Function.
// ***************************************************************************************************/
// void gs_NFC_GptStop(void) // WPC_4E_01
// {
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_3_DisableNotification();
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_3_StopTimer();
// }

// /***************************************************************************************************
// @param[in]  void
// @return     void
// @note		GPT (general purpse timer) Stop Function.
// ***************************************************************************************************/
// static void ss_NFC_GptStop1(void)
// {
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_1_DisableNotification();
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_1_StopTimer();
// }

// /***************************************************************************************************
// @param[in]  gtim : 1MHz 기준 카운트. ex) gtim=1000 입력 시, 1ms Interrupt 발생
// @return     void
// @note		GPT (general purpse timer) Start Function.
// ***************************************************************************************************/
// void gs_NFC_GptStart(uint16_t gtim) // GN7.0D_09
// {
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_3_EnableNotification();
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_3_StartTimer(gtim);
// }



// /***************************************************************************************************
// @param[in]  gtim : 1MHz 기준 카운트. ex) gtim=1000 입력 시, 1ms Interrupt 발생
// @return     void
// @note		GPT (general purpse timer) Start Function. 지정된 시간 후 NFC_Gpt_0_1_IE_Runnable() 이 call 됨
// ***************************************************************************************************/
// static void ss_NFC_GptStart1(uint16_t gtim)
// {
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_1_EnableNotification();
// 	Rte_Call_R_IoHwAbGptLogical_Gpt_0_1_StartTimer(gtim);
// }



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_NFC_L2H_Set(void)
{
	NFC.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_NFC_H2L_Set(void)
{
	Rte_Call_R_NFC1_WAKEUP_WriteDirect(OFF); // Wakup단 Low설정시 Power Down mode 진입함
	Rte_Call_R_NFC2_WAKEUP_WriteDirect(OFF);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_NFC_LPConditionCheck(uint8_t Device)
{
	if(NFC.Int.StateCurr[Device] != cNFC_Disable)
	{
		NFC.Out.Device[Device].NFC_LPConditionFlag = OFF;		// Active
	}
	else
	{
		NFC.Out.Device[Device].NFC_LPConditionFlag = ON;	// Sleep
	}

	// NFC.Out.Device[D1].NFC_LPConditionFlag = ON;	// Sleep // D1에 대한 제어가 없으므로 강제로 항상 D1은 슬립으로 처리함.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
uint8_t  gs_SPI_TxRx(uint8_t Channel, uint8_t * TxBuf, uint8_t* RxBuf, uint16_t TxRxLength)
{
	uint8_t retValue;

	retValue = E_NOT_OK;

	// 함수 구조상 RxDataBuf[0] 값은 항상 쓰레기 값이므로 사용하면 안되다.
	retValue = Spi_SetupEB(Channel, TxBuf, RxBuf, TxRxLength);

	if(retValue == E_OK)
	{
		retValue = Spi_SyncTransmit(Channel);

		if(retValue == E_OK)
		{
			NFC_Transmit++;
		}
		else
		{
			NFC_Transmit--;
		}

	}

	return retValue;
}

void NFC1_Spi_JobEnd_Notification(void) // sync 로 설정시만 호출됨
{
	Spi_JobResultType job_result;

	job_result = Spi_GetJobResult(SpiJob_NFC1);

	if(job_result != SPI_JOB_OK)
	{
		// Notify
		NFC1_JobEnd --;
	}
	else
	{
		// OK
		NFC1_JobEnd ++;
	}
}

void NFC1_Spi_SeqEnd_Notification(void) // sync 로 설정시만 호출됨
{
	Spi_SeqResultType seq_result;

	seq_result = Spi_GetSequenceResult(SpiSequence_NFC1);

	if(seq_result != SPI_SEQ_OK)
	{
		// failed transmission
		NFC1_SeqEnd --;
	}
	else
	{
		// OK
		NFC1_SeqEnd ++;
	}
}

void NFC2_Spi_JobEnd_Notification(void) // sync 로 설정시만 호출됨
{
	Spi_JobResultType job_result;

	job_result = Spi_GetJobResult(SpiJob_NFC2);

	if(job_result != SPI_JOB_OK)
	{
		// Notify
		NFC2_JobEnd --;
	}
	else
	{
		// OK
		NFC2_JobEnd ++;
	}

}

void NFC2_Spi_SeqEnd_Notification(void) // sync 로 설정시만 호출됨
{
	Spi_SeqResultType seq_result;

	seq_result = Spi_GetSequenceResult(SpiSequence_NFC2);

	if(seq_result != SPI_SEQ_OK)
	{
		// failed transmission
		NFC2_SeqEnd --;
	}
	else
	{
		// OK
		NFC2_SeqEnd ++;
	}
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC Initialize
***************************************************************************************************/
static void ss_Dual_NFC_Initialize(uint8_t Device)
{
	uint16_t retval = 0;
	
	if(NFC.Int.InitComplete[Device] == OFF)
	{
		if(ss_Dual_NXP_NfcRdLib_Init(Device) == PH_ERR_SUCCESS)
		{
			NFC.Int.InitComplete[Device] = ON;
		}
	}

// 	if( (NFC.Int.InitComplete[Device] == ON) &&
// 		(NFC.Int.CPInitComplete[Device] == OFF))
// 	{
		
// #if 1
// 		NFC.Int.CPInitComplete[Device] = ON;
		
// #else
// #if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
// 		// D0, D1 순차 Calibration
// 		if(Device == D1)
// 		{
// 			if(NFC.Int.CPInitComplete[D0] == ON)
// 			{
// 				// retval = ss_Dual_NXP_CardProtection_MainControl_Init(Device);
// 				retval = PH_ERR_SUCCESS;

// 				if(retval == PH_ERR_SUCCESS)
// 				{
// 					NFC.Int.CPInitComplete[Device] = ON;
// 				}
// 			}						
// 		}
// 		else
		
// #endif
// 		{
// 			// retval = ss_Dual_NXP_CardProtection_MainControl_Init(Device);						
// 			retval = PH_ERR_SUCCESS;

// 			if(retval == PH_ERR_SUCCESS)
// 			{
// 				NFC.Int.CPInitComplete[Device] = ON;
// 			}
// 		}

// #endif
// 	}
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC LPCD
***************************************************************************************************/
static void ss_Dual_NFC_LPCD(uint8_t Device)
{
	if(NFC.Int.NFC_LPCDSwapFunction == ON)
	{
		if(Device == NFC.Int.NFC_LPCDSwapDevice)
		{
			ss_Dual_NXP_LPCD_MainControl(Device);
		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		ss_Dual_NXP_LPCD_MainControl(Device);
	}
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC NFC
***************************************************************************************************/
static void ss_Dual_NFC_NFC(uint8_t Device)
{
	uint8_t		TpTxLen;
	
	if(NFC.Timer[Device][Tim_NFCSearchingOffDelay].Count > Par_NFCSearchingOffDelayTime)
	{
		NFC.Int.NFC_NFCSelfTrans[Device] = OFF;
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCSearchingOffDelay]);
		// gs_ReStartTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);	/* No Detection 신호 추가 */	// 여기에 적용하면 1.4초(1초+0.4초) 적용
	}

	if(NFC.Int.NFC_NFCSelfTrans[Device] == OFF)
	{
		ss_Dual_NXP_NFC_MainControl(Device, NFC.Int.CanTpRxCompleteReq,
											NFC.Int.TpRxBuf,
											NFC.Int.CanTpRxDataLen);
	}

	if (ss_Dual_Get_NXP_NFC_DataExchangeCheck(Device) == ON)
	{
		memset(NFC.Int.TpTxBuf, 0, sizeof(NFC.Int.TpTxBuf));
		TpTxLen = ss_Dual_Get_NXP_NFC_CanTpTxSize(Device);
		memcpy(NFC.Int.TpTxBuf, ss_Dual_Get_NXP_NFC_CanTpTxBuf(Device), TpTxLen);

		Rte_Send_LCAN_L_TP_L_WPC_FD_BDC_FD_LCAN_L_TP_L_WPC_FD_BDC_FD_signal(NFC.Int.TpTxBuf, TpTxLen);

		NFC.Int.CanTpRxCompleteReq = OFF;	/* 0109_01 */
	}

	/* 0109_01 */
	// if(NFC.Int.CanTpRxCompleteReq == ON)
	// {
	// 	NFC.Int.CanTpRxCompleteReq = OFF;
	// }
	/* 0109_01 */

}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC PICC
***************************************************************************************************/
static void ss_Dual_NFC_PICC(uint8_t Device)
{
	uint8_t			picc_state;
	uint16_t		ret_val;

#if 1
	if(	 (NFC.Int.NFC_PICCSwapFunction == OFF) ||
		((NFC.Int.NFC_PICCSwapFunction == ON) &&
		 (Device == NFC.Int.NFC_PICCSwapDevice)))
	{
		if(NFC.Int.PICC_ResetFlag[Device] == ON)
		{
			ss_Dual_NXP_PICC_MainControl_Init(Device);
			NFC.Int.PICC_ResetFlag[Device] = OFF;
		}

		if(NFC.Int.PICC_SearchDelay[Device] == 0u)
		{
			ret_val = ss_Dual_NXP_PICC_MainControl(Device);
			picc_state = ss_Dual_Get_NXP_PICC_OnThePad(Device);
		}
		else
		{
			picc_state = OnThePad_Default;
			NFC.Int.PICC_SearchDelay[Device]--;
			if(NFC.Int.PICC_SearchDelay[Device] == 0u)
			{
				gs_StartTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			}
		}

		switch(picc_state)
		{
		case OnThePad_On:
			NFC.Out.Device[Device].NfcOnThePad = OnThePad_On;
			NFC.Int.PICC_ResetFlag[Device] = ON;

			NFC.Int.PICC_SearchDelay[Device] = Par_PICCSearchingDelay;
			gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			break;
			
		default:	// OnThePad_Off 조건 Delay 1.5sec
			if(NFC.Timer[Device][Tim_PICCDetectDelay].Count >= Par_PICCDetectDelay)
			{
				NFC.Out.Device[Device].NfcOnThePad = OnThePad_Off;
				gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			}
			break;
		}

	}
	else
	{
		/* Do Nothing */
	}

#else	
	if(NFC.Int.NFC_PICCSwapFunction == ON)
	{
		if(Device == NFC.Int.NFC_PICCSwapDevice)
		{
			if(NFC.Int.PICC_ResetFlag[Device] == ON)
			{
				ss_Dual_NXP_PICC_MainControl_Init(Device);
				NFC.Int.PICC_ResetFlag[Device] = OFF;
			}

			if(NFC.Int.PICC_SearchDelay[Device] == 0u)
			{
				ret_val = ss_Dual_NXP_PICC_MainControl(Device);
				picc_state = ss_Dual_Get_NXP_PICC_OnThePad(Device);
			}
			else
			{
				picc_state = OnThePad_Default;
				NFC.Int.PICC_SearchDelay[Device]--;
				if(NFC.Int.PICC_SearchDelay[Device] == 0u)
				{
					gs_StartTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
				}
			}

			switch(picc_state)
			{
			case OnThePad_On:
				NFC.Out.Device[Device].NfcOnThePad = OnThePad_On;
				NFC.Int.PICC_ResetFlag[Device] = ON;

				NFC.Int.PICC_SearchDelay[Device] = Par_PICCSearchingDelay;
				gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
				break;
				
			default:	// OnThePad_Off 조건 Delay 1.5sec
				if(NFC.Timer[Device][Tim_PICCDetectDelay].Count >= Par_PICCDetectDelay)
				{
					NFC.Out.Device[Device].NfcOnThePad = OnThePad_Off;
					gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
				}
				break;
			}

		}
		else
		{
			/* Do Nothing */
		}
	}
	else
	{
		if(NFC.Int.PICC_ResetFlag[Device] == ON)
		{
			ss_Dual_NXP_PICC_MainControl_Init(Device);
			NFC.Int.PICC_ResetFlag[Device] = OFF;
		}

		if(NFC.Int.PICC_SearchDelay[Device] == 0u)
		{
			ret_val = ss_Dual_NXP_PICC_MainControl(Device);
			picc_state = ss_Dual_Get_NXP_PICC_OnThePad(Device);
		}
		else
		{
			picc_state = OnThePad_Default;
			NFC.Int.PICC_SearchDelay[Device]--;
			if(NFC.Int.PICC_SearchDelay[Device] == 0u)
			{
				gs_StartTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			}
		}

		switch(picc_state)
		{
		case OnThePad_On:
			NFC.Out.Device[Device].NfcOnThePad = OnThePad_On;
			NFC.Int.PICC_ResetFlag[Device] = ON;

			NFC.Int.PICC_SearchDelay[Device] = Par_PICCSearchingDelay;
			gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			break;
			
		default:	// OnThePad_Off 조건 Delay 1.5sec
			if(NFC.Timer[Device][Tim_PICCDetectDelay].Count >= Par_PICCDetectDelay)
			{
				NFC.Out.Device[Device].NfcOnThePad = OnThePad_Off;
				gs_CancelTimer(&NFC.Timer[Device][Tim_PICCDetectDelay]);
			}
			break;
		}
	}
		
#endif
}

uint8_t Allow_Cnt = 0;
uint8_t Prohibit_Cnt = 0;
uint32_t Error_Cnt = 0;
uint8_t Resume_Cnt = 0;
uint8_t InProgress_Cnt = 0;
uint8_t InConclusive_Cnt = 0;
uint8_t NoResult_Cnt = 0;
uint8_t Default_Cnt = 0;
uint32_t OsTick = 0u;
uint32_t OsTick_diff;
/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC Card Protection
***************************************************************************************************/
static void ss_Dual_NFC_CardProtection(uint8_t Device)
{
	// uint8_t ret_val;
	DIST_RESULT_t ret_val;
	
	switch(NFC.Int.CardProtectionState[Device])
	{
	case cCardProtection_Wait:
		if(NFC.Int.InitComplete[Device] == ON)
			// (NFC.Int.CPInitComplete[Device] == ON))
		{
			NFC.Int.CardProtectionState[Device] = cCardProtection_Detecting;
		}
		else
		{
			ss_Dual_NFC_Initialize(Device);
		}
		break;

	case cCardProtection_Detecting:
		// OsTick = *(uint32_t *)0x40390008;
		// OS Tick 시간 읽어서 총 수행시간이 250us 넘으면 종료
		// 최대 걸릴 수 있는 시간 = 249.99us + 함수 마지막 수행 시간
		for(OsTick = *(uint32_t *)0x40390008; (*(uint32_t *)0x40390008 - OsTick) < 250u; )
		{
			// Requset 종료되는 즉시 빠져나감
			if(NFC.Inp_WCT.Device[Device].CardProtectionReq == OFF)
			// if(TEST_CardProtectionReq[Device] == OFF)	/* 연속 카드 프로텍션 테스트 */
			{
				NFC.Int.CardProtectionState[Device] = cCardProtection_Wait;
				break;
			}
			
			ret_val = ss_Dual_NXP_CardProtection_MainControl(Device); // Card Protection Main
			
			switch (ret_val)
			{
			case DIST_RESULT_ERROR:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
				Error_Cnt++;
				break;

			case DIST_RESULT_IN_PROGRESS:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
				InProgress_Cnt++;
				break;

			case DIST_RESULT_RESUME:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
				Resume_Cnt++;
				break;

			case DIST_RESULT_ALLOW:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_AllowCharging;
				Allow_Cnt++;
				break;

			case DIST_RESULT_PROHIBIT:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_ProhibitCharging;
				Prohibit_Cnt++;
				break;

			// case DIST_RESULT_INCONCLUSIVE:
			// 	NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
			// 	InConclusive_Cnt++;
			// 	break;

			case DIST_RESULT_NO_RESULT:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
				NoResult_Cnt++;
				break;

			default:
				NFC.Out.Device[Device].CardProtectionResult = cCardProtectionResult_Default;
				Default_Cnt++;
				break;
			}
			
			if( (NFC.Out.Device[Device].CardProtectionResult == cCardProtectionResult_AllowCharging) ||
				(NFC.Out.Device[Device].CardProtectionResult == cCardProtectionResult_ProhibitCharging) )
			{
				NFC.Int.CardProtectionState[Device] = cCardProtection_Detected;
				// NFC.Int.InitComplete[Device] = OFF;

/* 연속 카드 프로텍션 테스트 */
TEST_CardProtectionReq[Device] = OFF;
tim_test[Device] = 0;
/* 연속 카드 프로텍션 테스트 */

				break;	/* for문 탈출 */
			}
		}
OsTick_diff = *(uint32_t *)0x40390008 - OsTick;
		break;

	case cCardProtection_Detected:
		if(NFC.Inp_WCT.Device[Device].CardProtectionReq == OFF)
		// if(TEST_CardProtectionReq == OFF)
		{
			NFC.Int.CardProtectionState[Device] = cCardProtection_Wait;
		}

		break;
		
	default:
		NFC.Int.CardProtectionState[Device] = cCardProtection_Wait;
		// NFC.Int.InitComplete[Device] = OFF;
		
		break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		Dual NFC LPCD SWAP Machine
***************************************************************************************************/
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
static void ss_Dual_LPCD_Swap_Machine(void)
{
	static uint8_t LPCD_Swap_Channel = D0;
	static uint8_t LPCD_Swap_State = 0u;

	if((NFC.Inp_Model.Device[D0].WPCStatus == LPCDMode) &&
	   (NFC.Inp_Model.Device[D1].WPCStatus == LPCDMode) )
	{
		// Dual LPCD Swap Mode Start
		switch(LPCD_Swap_State)
		{
		case 0u:
			gs_StartTimer(&NFC.Timer[D0][Tim_LPCDSwapDelay]);
			NFC.Int.NFC_LPCDSwapFunction = ON;
			LPCD_Swap_State = 1u;
			break;

		case 1u:
			if(NFC.Timer[D0][Tim_LPCDSwapDelay].Count >= Par_SwapDelayLPCD)
			{
				if(LPCD_Swap_Channel == D0)
				{
					LPCD_Swap_Channel = D1;
					NFC.Int.NFC_LPCDSelfTrans[D0] = ON;
					NFC.Int.NFC_LPCDSelfTrans[D1] = OFF;
				}
				else
				{
					LPCD_Swap_Channel = D0;
					NFC.Int.NFC_LPCDSelfTrans[D0] = OFF;
					NFC.Int.NFC_LPCDSelfTrans[D1] = ON;
				}

				gs_ReStartTimer(&NFC.Timer[D0][Tim_LPCDSwapDelay]);
			}
			break;

		default:
			LPCD_Swap_State = 0u;
			break;
		}
	}
	// Dual Swap Mode End
	else
	{
		gs_CancelTimer(&NFC.Timer[D0][Tim_LPCDSwapDelay]);
		NFC.Int.NFC_LPCDSwapFunction = OFF;
		LPCD_Swap_Channel = D0;
		LPCD_Swap_State = 0u;
	}

	NFC.Int.NFC_LPCDSwapDevice = LPCD_Swap_Channel;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		Dual NFC PICC SWAP Machine
***************************************************************************************************/
static void ss_Dual_PICC_Swap_Machine(void)
{
	static uint8_t PICC_Swap_Channel = D0;
	static uint8_t PICC_Swap_State = 0u;

	if( (NFC.Inp_Model.Device[D0].WPCStatus == PICCMode) &&
		(NFC.Inp_Model.Device[D1].WPCStatus == PICCMode) )
	{
		// Dual PICC Swap Mode Start
		switch(PICC_Swap_State)
		{
		case 0u:
			gs_StartTimer(&NFC.Timer[D0][Tim_PICCSwapDelay]);
			NFC.Int.NFC_PICCSwapFunction = ON;
			PICC_Swap_State = 1u;
			break;

		case 1u:
			if(NFC.Timer[D0][Tim_PICCSwapDelay].Count >= Par_SwapDelayPICC)
			{
				if(PICC_Swap_Channel == D0)
				{
					PICC_Swap_Channel = D1;
					NFC.Int.NFC_PICCSelfTrans[D0] = ON;
					NFC.Int.NFC_PICCSelfTrans[D1] = OFF;
				}
				else
				{
					PICC_Swap_Channel = D0;
					NFC.Int.NFC_PICCSelfTrans[D0] = OFF;
					NFC.Int.NFC_PICCSelfTrans[D1] = ON;
				}

				gs_ReStartTimer(&NFC.Timer[D0][Tim_PICCSwapDelay]);
			}
			break;

		default:
			PICC_Swap_State = 0u;
			break;
		}

	}
	// Dual Swap Mode End
	else
	{
		gs_CancelTimer(&NFC.Timer[D0][Tim_PICCSwapDelay]);
		NFC.Int.NFC_PICCSwapFunction = OFF;
		PICC_Swap_Channel = D0;
		PICC_Swap_State = 0u;
	}

	NFC.Int.NFC_PICCSwapDevice = PICC_Swap_Channel;
}

//#endif

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC LPCD Main Control
***************************************************************************************************/
static void ss_Dual_NXP_LPCD_MainControl(uint8_t Device)
{
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		NXP_LPCD_MainControl2();
	}
	else
	{
		NXP_LPCD_MainControl();
	}
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC LPCD Main Control Init
***************************************************************************************************/
static void ss_Dual_NXP_LPCD_MainControl_Init(uint8_t Device)
{
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		NXP_LPCD_MainControl_Init2();
	}
	else
	{
		NXP_LPCD_MainControl_Init();
	}	
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC NFC Main Control
***************************************************************************************************/
static uint16_t ss_Dual_NXP_NFC_MainControl(uint8_t Device, uint8_t dataExchange, uint8_t* pTxBuff, uint16_t length)
{
	uint16_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = NXP_NFC_MainControl2(dataExchange, pTxBuff, length);
	}
	else
	{
		retval = NXP_NFC_MainControl(dataExchange, pTxBuff, length);
	}	
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC NFC Main Control Init
***************************************************************************************************/
static void ss_Dual_NXP_NFC_MainControl_Init(uint8_t Device)
{
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		NXP_NFC_MainControl_Init2();
	}
	else
	{
		NXP_NFC_MainControl_Init();
	}		
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC PICC Main Control
***************************************************************************************************/
static uint16_t ss_Dual_NXP_PICC_MainControl(uint8_t Device)
{
	uint16_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = NXP_PICC_MainControl2();
	}
	else
	{
		retval = NXP_PICC_MainControl();
	}
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC PICC Main Control Init
***************************************************************************************************/
static void ss_Dual_NXP_PICC_MainControl_Init(uint8_t Device)
{	
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		NXP_PICC_MainControl_Init2();
	}
	else
	{
		NXP_PICC_MainControl_Init();
	}	
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP NFC Detect Check
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_NFC_DetectCheck(uint8_t Device)
{
	uint8_t retval = 0U;
	
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NFC_DetectCheck2();
	}
	else
	{
		retval = Get_NXP_NFC_DetectCheck();
	}	


	if(retval == 1u)
	{
		gs_CancelTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);
		return retval;
	}
	else
	{
		/* No Detection 신호 추가 */
		if(NFC.Timer[Device][Tim_NFCNoDetectionDelay].Count >= Par_NFCNoDetectionDelayTime)
		{
			return 2u;	// No Detection
			// gs_CancelTimer(&NFC.Timer[Device][Tim_NFCNoDetectionDelay]);
		}
		/* No Detection 신호 추가 */
	}

	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP NFC Data Exchange Check
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_NFC_DataExchangeCheck(uint8_t Device)
{
	uint8_t retval = 0U;
	
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NFC_DataExchangeCheck2();
	}
	else
	{
		retval = Get_NXP_NFC_DataExchangeCheck();
	}		

	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     TxBuf
@note		Dual NFC Get NXP NFC Can TP TxBuf
***************************************************************************************************/
static uint8_t * ss_Dual_Get_NXP_NFC_CanTpTxBuf(uint8_t Device)
{	
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		return Get_NXP_NFC_CanTpTxBuf2();
	}
	else
	{
		return Get_NXP_NFC_CanTpTxBuf();
	}		
}

/***************************************************************************************************
@param[in]  Device
@return     TxSize
@note		Dual NFC Get NXP NFC CAN TP TxSize
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_NFC_CanTpTxSize(uint8_t Device)
{
	uint8_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NFC_CanTpTxSize2();
	}
	else
	{
		retval = Get_NXP_NFC_CanTpTxSize();
	}	
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP LPCD Wake-up Check
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_LPCD_WakeupCheck(uint8_t Device)
{
	uint8_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_LPCD_WakeupCheck2();
	}
	else
	{
		retval = Get_NXP_LPCD_WakeupCheck();
	}
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP PICC OnThePad
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_PICC_OnThePad(uint8_t Device)
{
	uint8_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_PICC_OnThePad2();
	}
	else
	{
		retval = Get_NXP_PICC_OnThePad();
	}
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP NFC Mode Exit Ready
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_NfcModeExitReady(uint8_t Device)
{
	uint8_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NfcModeExitReady2();
	}
	else
	{
		retval = Get_NXP_NfcModeExitReady();
	}
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC NXP NFC Ribrary Init
***************************************************************************************************/
static uint16_t  ss_Dual_NXP_NfcRdLib_Init(uint8_t Device)
{
	uint16_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = NXP_NfcRdLib_Init2();
	}
	else
	{
		retval = NXP_NfcRdLib_Init();
	}	
	
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC NXP Card Protection Main Control
***************************************************************************************************/
static DIST_RESULT_t ss_Dual_NXP_CardProtection_MainControl(uint8_t Device)
{
	DIST_RESULT_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = NXP_CardProtection_MainControl2();
	}
	else
	{
		retval = NXP_CardProtection_MainControl();
	}	
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     void
@note		Dual NFC NXP Field OFF
***************************************************************************************************/
static void ss_Dual_NXP_Field_OFF(uint8_t Device)
{
	uint16_t retval = 0U;
	
	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = NXP_Field_OFF2();
	}
	else
	{
		retval = NXP_Field_OFF();
	}
		
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP NFC Communication Errors Check
***************************************************************************************************/
static uint8_t ss_Dual_Get_NXP_NFC_CommunicationErrorsCheck(uint8_t Device)
{
	uint8_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NFC_CommunicationErrorsCheck2();
	}
	else
	{
		retval = Get_NXP_NFC_CommunicationErrorsCheck();
	}
		
	return retval;
}

/***************************************************************************************************
@param[in]  Device
@return     retval
@note		Dual NFC Get NXP NFC Communication Errors Status
***************************************************************************************************/
static uint16_t ss_Dual_Get_NXP_NFC_CommunicationErrorsStatus(uint8_t Device)
{
	uint16_t retval = 0U;

	if(((NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
		(NFC.Inp_NvM.WPC_TYPE == cWPC_TYPE6)) &&
		(Device == D1))
	{
		retval = Get_NXP_NFC_CommunicationErrorsStatus2();
	}
	else
	{
		retval = Get_NXP_NFC_CommunicationErrorsStatus();
	}
		
	return retval;
}

#define App_NFC_STOP_SEC_CODE
#include "App_NFC_MemMap.h"
