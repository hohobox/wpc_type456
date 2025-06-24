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
#include "App_WDT.h"
#include "Rte_App_WDT.h"

#include "App_NvM.h"


#define App_WDT_START_SEC_CODE
#include "App_WDT_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

#define		Par_NvMWriteWaitTime		(600u	/ TIME_10MS)	// nvm write 완료시까지 대기 시간 (최대한 길게 잡음)
#define		Par_ResetRespHoldTime		(60000u	/ TIME_10MS)	// 리셋 결과 출력 유지 시간
#define		Par_ResetReqValidTimeout	(1500u	/ TIME_10MS) // 1.5sec
#define		Par_ResetTryTimeout			(1000u	/ TIME_10MS) // 1.0sec

#define APP_IO_USER							0u

#define	cPDCResetSqn_Init					0u
#define	cPDCResetSqn_ConditionCheck			1u
#define	cPDCResetSqn_TryReset				2u
#define	cPDCResetSqn_ResetFail				3u

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/
typedef enum
{
	Tim_NvMWriteWait,
	Tim_ResetRespHold,
	Tim_ResetReqValid,
	Tim_ResetTry,
	Tim_WDTM_MAX
}WDTM_TMR_t;

typedef struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;
	uint8_t WdtPulseToggle;

	Event_t PDC_ResetPreWrngForOthers_Evt;

	uint8_t ResetValidFlag;
	Event_t ResetValidFlag_Evt;
	Event_t WPC_ResetOpSta_Evt;
	Event_t PDC_ResetReqForOthers_Evt;

	uint8_t RunOnceFlag;
	uint8_t WPC_TYPE_Old;

} Inter_t;

typedef struct
{
	IDT_Uds_STR 	Inp_Uds;
	IDT_CAN_RX_STR 	Inp_CAN_RX;
	IDT_NvM_STR		Inp_NvM;
	IDT_ADC_STR		Inp_ADC;
	Inter_t 		Int;

	Timer_t 		Timer[Tim_WDTM_MAX];
	IDT_WDT_STR 	Out;

} WDT_struct;

/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

static WDT_struct WDTM = {0}; // 타 모듈에서 WDT define명으로 사용중이여서 다른 이름으로 변경함


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_WDT_InitSet(void);
static void ss_WDT_RteRead(void);
static void ss_WDT_RteWrite(void);
static void ss_WDT_Pulse(void);
static void ss_WDT_CCU_Reset(void);
static void ss_WDT_PDC_Reset(void);
static void ss_WDT_WPCTypeChange_Reset(void);
static void ss_WDT_LPConditionCheck(void);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/

// WDTM 주기 30ms --> 50ms로 변경하면서 WDT_TE 주기도 10ms에서 20ms 주기로변경함.
// Open windwos : 25ms, Close Windows : 25ms
// 20ms 주기로 on/off 하면 됨.
// WDTM Open Close 방법 ()
// Initial (open windows)은 wdt 주기 50ms의 8배이다.
// 이 시간 내에 WDTM Pulse를 High시키면 즉시 Close Windows로 변경된다.
// Close Windows 25ms 동안은 High를 발생시키면 안된다. 단 low는 발생해도 된다.
// 즉 20ms 경과뒤 Low로 변경한다. 아직 Close windows 구간이나 low는 발생해도 된다.
// 그 뒤 20ms 후 High로 바뀌면 이때는 open Windows 구간 바뀌고 15ms 경과된 시점이다.
// 또 이 시점에서 즉시 다시 Close Windows로 바뀐다.
// 또 Close windows 25ms가 시작된다.
// 다시 위의 과정을 반복한다.

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_WDT_CODE) WDT_TE_Runnable(void)
{
	switch(WDTM.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&WDTM.Int.App_Init_Completed);				/* SWP Init Complete Check */

			if( WDTM.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
				/* SWC Init Process */
				ss_WDT_InitSet();

				WDTM.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */
			}
		break;

		case 1u:

			ss_WDT_RteRead();

			ss_WDT_Pulse();

/* 010E_13 */			
			if (WDTM.Inp_CAN_RX.BCAN.C_PDC_ResetFuncOpt == 0x1u)  // 0x0:Not Applied, 0x1:Applied, 0x2:RESERVED, 0.3:Invalid
			{
				ss_WDT_PDC_Reset(); // PDC Reset
			}
			else
			{
				ss_WDT_CCU_Reset();	// CCU Reset
			}

			//ss_WDT_PDC_Reset();
/* 010E_13 */
			ss_WDT_WPCTypeChange_Reset();

			ss_WDT_RteWrite();

			gs_UpdateTimer(&WDTM.Timer[0], (uint8_t)Tim_WDTM_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.

			ss_WDT_LPConditionCheck();

		break;

		default:
			WDTM.Int.Runnable_State = 0u;
		break;
	}

}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static  void    ss_WDT_InitSet(void)
{
	memset(&WDTM.Out, 0, sizeof(WDTM.Out));  		// 구조체 변수를 0으로 클리어

	gs_InitTimer(&WDTM.Timer[0], (uint8_t)Tim_WDTM_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.

	Rte_Read_R_NvM_NvM_STR(&WDTM.Inp_NvM);			// 한꺼번에 수신

	WDTM.Out.m_PDCReset = WDTM.Inp_NvM.m_PDCReset;	// eeprom 불러옴.
	Rte_Write_P_WDT_WDT_STR(&WDTM.Out);	 // 한꺼번에 전송 // 즉시 write 버퍼 값을 변경해줘야함. 그렇지 않으면 Nvm rte read에서 초기값 0을 읽은 후 m_PDCReset eeprom값을 0으로 변경시켜 버린다.

	if(WDTM.Inp_NvM.m_PDCReset == cResetReq_ResetReq)
	{
		WDTM.Out.WPC_ResetOpSta = cResetOpSta_ResetComplete;
		WDTM.Out.m_PDCReset = cResetReq_NoReq;

		gs_StartTimer(&WDTM.Timer[Tim_ResetRespHold]);// 리셋 결과 CAN 출력 유지 시간 60초
	}

	WDTM.Int.WPC_TYPE_Old = WDTM.Inp_NvM.WPC_TYPE; /* 0108_11 */ // 최초 전원 인가시 판단된 값을 old에 넣어야 리셋이 미발생됨.
	WDTM.Int.WdtPulseToggle = 1u; // WPC_434_03 // 1로 해야 첫 pulse가 OFF부터 시작된다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WDT_RteRead(void)
{
	Rte_Read_R_Uds_Uds_STR(&WDTM.Inp_Uds);			// 한꺼번에 수신
	Rte_Read_R_CAN_RX_CAN_RX_STR(&WDTM.Inp_CAN_RX);			// 한꺼번에 수신
	Rte_Read_R_NvM_NvM_STR(&WDTM.Inp_NvM); // nvm 값은 리셋 될때 한번만 read하고 그값으로 로직 구현해야 함. 리셋 요청에 의해서 변경된 값을 실시간으로 반영해서 로직 구현하면 안됨.
											// 잘못된 주석인듯. 주석 해제해도 정상 동작함.
	Rte_Read_R_ADC_ADC_STR(&WDTM.Inp_ADC);			// 한꺼번에 수신
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_WDT_RteWrite(void)
{
	// 타 SWC에 RTE로 전달
	Rte_Write_P_WDT_WDT_STR(&WDTM.Out);	// 배열로 한꺼번에 전송
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WDT_Pulse(void)
{
	static uint8_t Toggle_20ms_Flag = OFF;

// deepsleep에서 wakeup될때 WDTM Disable시킨다. 그후 다시 여기서 enable 시키는데 여기 진입까지
// 약 100ms 걸린다. why? 플랫폼 초기화가 100ms 걸리나? 그래서 WDTM runnable 작동까지 100ms 걸리나?
// --> 100ms 걸림

	if((WDTM.Inp_Uds.WdtDisable_ConfigLock == ON) ||
	(WDTM.Inp_Uds.WdtDisable_ProgramSession == ON))
	{
		Rte_Call_R_WDT_EN_WriteDirect(OFF);	// WDTM disable (port high)
		Rte_Call_R_WDT_CLEAR_PULSE_WriteDirect(OFF);// wdt pulse off
		WDTM.Int.WdtPulseToggle = 1u;// 1로 해야 Pulse 가 Off부터 시작된다.
	}
	else
	{
#if !defined (DEBUG_EXT_WDT_NOT_USE)
		Rte_Call_R_WDT_EN_WriteDirect(ON);	// WDTM Enable (port low)
#endif

		Toggle_20ms_Flag = Toggle_20ms_Flag ^ 1u;
		if(Toggle_20ms_Flag == 1u) // 20ms 주기로 WDTM Pulse Toggle하기 위해서 20ms주기로 실행함.
		{
 			WDTM.Int.WdtPulseToggle = WDTM.Int.WdtPulseToggle ^ 1u;
 			Rte_Call_R_WDT_CLEAR_PULSE_WriteDirect(WDTM.Int.WdtPulseToggle);// wdt pulse toggle
		}

	}
}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/

static void ss_WDT_CCU_Reset(void) /* 0108_10 */
{
	// C_CCU_ForcedPowerOffReq
	// 0x0: OFF
	// 0x1: ON in the non-sleep state
	// 0x2: ON in the normal-sleep state
	// 0x3: Reserved

	// 이벤트 신호가 40m 주기로 3회 on 후 off 이므로 120ms 동안 0x01이 유지된다.
	// 그런데 GN7은 ECU Wakeup Timed이 85ms 여서 빠르다.
	// 그래서 나머지 35ms 동안 ForcedPowerOffReq 신호가 0x1이 유지 하고 있어서
	// 리셋이 한번 더 걸린다. 그래서 리셋이 2번 발생한다.

	if(WDTM.Inp_ADC.PDC_LOW_BAT == ON)	// 9.0V 이하
	{	
		if((WDTM.Inp_CAN_RX.LCAN.LC_CCU_ForcedPowerOffReq == cPowerOffReq_ON_NonSleep) &&	// 이벤트 신호임. (0x1일때 제어기 리셋, 나머지 신호는 사양 미정)
		(WDTM.Inp_ADC.IGN1_IN == OFF)) // 차량 슬립 조건에서만 동작해야함. (IG OFF 상태, IG ON시에는 Request가 오더라도 무시해야함.)
		{
			// MCU_SW_RESET(6) 발생시킴.
			Rte_Call_EcuM_StateRequest_RequestReset(APP_IO_USER); // swp에 의한 리셋이 발생 시켜야 nvm 저장등 정상적으로 종료됨. 그래서 wdt 리셋 발생시키지 않고 rte함수로 리셋 요청하도록 변경함				
		}
	}
	else
	{
		
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WDT_PDC_Reset(void) /* 0108_10 */
{

	// event 신호 판단
	// prewarning 신호가 on인 상태로 전원 리셋시에 gs_UpdateEvent() 함수 특성성 최초 실행시에는
	// 이전값이 0이기때문에 호출하자마자 1이 입력되면 on event가 발생하게 된다.
	// 이를 막기 위해서 can 신호가 수신된 다음 부터 이벤트 판단하고 최초 호출시에는 previous값을
	// 최초 read한 값으로 입력하여 on 이벤트가 발생하지 않도록 한다.
	if(WDTM.Inp_CAN_RX.BCAN.PDC_15_300_RevComplete == ON)
	{
		if(WDTM.Int.RunOnceFlag == OFF)
		{
			WDTM.Int.RunOnceFlag = ON;
			WDTM.Int.PDC_ResetPreWrngForOthers_Evt.previous = WDTM.Inp_CAN_RX.BCAN.C_PDC_ResetPreWrngForOthers;
			WDTM.Int.PDC_ResetReqForOthers_Evt.previous = WDTM.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers;
		}

		gs_UpdateEvent(WDTM.Inp_CAN_RX.BCAN.C_PDC_ResetPreWrngForOthers, &WDTM.Int.PDC_ResetPreWrngForOthers_Evt);	// event update
		gs_UpdateEvent(WDTM.Inp_CAN_RX.BCAN.C_PDC_ResetReqForOthers, &WDTM.Int.PDC_ResetReqForOthers_Evt);	// event update
	}

	gs_UpdateEvent(WDTM.Out.WPC_ResetOpSta, &WDTM.Int.WPC_ResetOpSta_Evt);	// event update

	// 요구 사양.

	// (4)	저전압 상태에서의 PDC 리셋 기능 제한
	// -	8.5V 미만 도달 시 PDC 리셋 기능 금지하며, 9V 이상 도달 시 PDC 리셋 기능 금지를 해제한다.
	// -	초기에는 PDC 리셋 기능 금지 상태로 설정한다.


	if(WDTM.Inp_ADC.BatSysStateFault == OFF)	// 9.0V 이상일때만 리셋 기능 동작
	{
		// 리셋 동작 유효성 판단
		if((WDTM.Int.PDC_ResetPreWrngForOthers_Evt.On_Event == cResetPreWrng_Warning) && // 0(No Warning) --> 1(Warning) 이벤트 발생
		(WDTM.Inp_ADC.IGN1_IN == OFF)) // IGN on/off 판단은 제어기 리셋시에는 30ms 채터링 없이 즉시 판단되어 전송됨.
		{
			WDTM.Int.ResetValidFlag = ON;
		}
		else if((WDTM.Int.PDC_ResetPreWrngForOthers_Evt.Off_Event == ON) || // 1(Warning) --> 0(No Warning)  OFF 이벤트 발생
		(WDTM.Inp_ADC.IGN1_IN != OFF)) 
		{
			WDTM.Int.ResetValidFlag = OFF;
		}		
		else if(WDTM.Timer[Tim_ResetReqValid].Count >= Par_ResetReqValidTimeout) // 1.5초 경과시 무효화 처리,
		{
			gs_CancelTimer(&WDTM.Timer[Tim_ResetReqValid]);
			WDTM.Int.ResetValidFlag = OFF;
		}
		else if(WDTM.Int.WPC_ResetOpSta_Evt.On_Event == cResetOpSta_ResetFail)
		{
			WDTM.Int.ResetValidFlag = OFF;
		}
		else
		{
			// QAC
		}

		gs_UpdateEvent(WDTM.Int.ResetValidFlag, &WDTM.Int.ResetValidFlag_Evt);	// event update
		
		// 유효성 있을 때만 리셋 요청 처리
		if((WDTM.Int.ResetValidFlag == ON) &&
		(WDTM.Int.PDC_ResetReqForOthers_Evt.On_Event == cResetReq_ResetReq)) // Event 신호로 판단
		{
			WDTM.Out.m_PDCReset = cResetReq_ResetReq;	// NvM에 저장하여 리셋 요인이 PDC 요청임을 표시한다.
			gs_StartTimer(&WDTM.Timer[Tim_NvMWriteWait]);	// NvM Write 안정화 시간 600ms			
		}
		// 유효성 없을 때 리셋 요청시 Fail 처리
		else if((WDTM.Int.ResetValidFlag == OFF) &&
		(WDTM.Int.PDC_ResetReqForOthers_Evt.On_Event == cResetReq_ResetReq))	// Event 신호로 판단	
		{
			WDTM.Out.WPC_ResetOpSta = cResetOpSta_ResetFail; 		// 리셋 실패 신호 출력
			gs_StartTimer(&WDTM.Timer[Tim_ResetRespHold]);	// 리셋 결과 CAN 출력 유지 시간 60초			
		}
		// 유효성 있고 리셋 요청 완료 후 NvM 저장시 까지 대기
		else if((WDTM.Int.ResetValidFlag == ON) &&
		(WDTM.Out.m_PDCReset == cResetReq_ResetReq) &&
		(WDTM.Int.WdtPulseToggle == 1u) && 								//Ext WDT으로 인해 Reset이 겹치는 현상이 발생하여 WDT pulse의 Rising Edge와 동기시킴
		(WDTM.Inp_NvM.NvMBlk_1B_Complete[BLK_NO_1B_PDCReset] == ON) && // 저장 완료 플래그 확인
		(WDTM.Timer[Tim_NvMWriteWait].Count >= Par_NvMWriteWaitTime)) // 600ms 경과
		{
			gs_CancelTimer(&WDTM.Timer[Tim_NvMWriteWait]);
			
			Rte_Call_EcuM_StateRequest_RequestReset(APP_IO_USER); // SWP 소프트 리셋 요청
			// swp에 의한 리셋이 발생 시켜야 nvm 저장등 정상적으로 종료됨. 그래서 wdt 리셋 발생시키지 않고 rte함수로 리셋 요청하도록 변경함				
			// SWP 소프트 리셋 요청	이후에는 더이상 다음 로직이 실행되면 안됨.
			// 그러나 만약 리셋 요청 함수가 콜되고 나서도 다음 task가 게속 실행되어진다면
			// 아래 로직에 의해서 1분이 경과되어 Reset Fail이 송출되어야 한다.
		}
		else
		{
			// QAC
		}

		// 리셋 수행 대기 시간 1초 타이미 처리
		if  (WDTM.Timer[Tim_ResetTry].Count >= Par_ResetTryTimeout)
		{
			gs_CancelTimer(&WDTM.Timer[Tim_ResetTry]);
			
			WDTM.Out.WPC_ResetOpSta = cResetOpSta_ResetFail; 	// 리셋 실패 신호 출력
			gs_StartTimer(&WDTM.Timer[Tim_ResetRespHold]);		// 리셋 결과 CAN 출력 유지 시간 60초	
		}

        // Reset Response 1분 경과 타이머 처리
        if ((WDTM.Timer[Tim_ResetRespHold].Count >= Par_ResetRespHoldTime) ||
		(WDTM.Int.ResetValidFlag_Evt.On_Event == cResetPreWrng_Warning))			// 유효성 판단 플래그 On 이벤트 발생시
		{
			gs_CancelTimer(&WDTM.Timer[Tim_ResetRespHold]);
            WDTM.Out.WPC_ResetOpSta = cResetOpSta_Normal; 		// 리셋 Normal 신호 출력
        }
	}
	else	// 리셋 기능 금지 동작
	{
		WDTM.Int.ResetValidFlag = OFF;
		
		gs_CancelTimer(&WDTM.Timer[Tim_NvMWriteWait]);
		gs_CancelTimer(&WDTM.Timer[Tim_ResetRespHold]);
		gs_CancelTimer(&WDTM.Timer[Tim_ResetReqValid]);
		gs_CancelTimer(&WDTM.Timer[Tim_ResetTry]);		
		
		WDTM.Out.WPC_ResetOpSta = cResetOpSta_Normal;
		WDTM.Out.m_PDCReset = cResetReq_NoReq;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note       품번 입력에 의해서 Type이 변경되면 하드 리셋을 하여 재시작 하도록 함.
***************************************************************************************************/
static void ss_WDT_WPCTypeChange_Reset(void) /* 0108_11 */
{
	if(WDTM.Inp_NvM.WPC_TYPE != WDTM.Int.WPC_TYPE_Old)
	{
		Rte_Call_EcuM_StateRequest_RequestReset(APP_IO_USER); // SWP 소프트 리셋 요청
	}
	
	WDTM.Int.WPC_TYPE_Old = WDTM.Inp_NvM.WPC_TYPE; // old value copy

}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_WDT_L2H_Set(void)
{
	WDTM.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_App_WDT_H2L_Set(void)
{

}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_WDT_LPConditionCheck(void)
{
	if((WDTM.Out.WPC_ResetOpSta == (uint8_t)cResetOpSta_ResetComplete) || // 1분간 송신해야 하므로 슬립 진잆하면 안됨
	(WDTM.Out.WPC_ResetOpSta == (uint8_t)cResetOpSta_ResetFail))
	{
		WDTM.Out.WDT_LPConditionFlag = OFF;	// Active
	}
	else
	{
		WDTM.Out.WDT_LPConditionFlag = ON;	// Sleep
	}
}


#define App_WDT_STOP_SEC_CODE
#include "App_WDT_MemMap.h"
