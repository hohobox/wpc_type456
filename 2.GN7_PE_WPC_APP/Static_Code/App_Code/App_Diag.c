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
#include "App_Diag.h"
#include "Rte_App_Diag.h"

#define App_Diag_START_SEC_CODE
#include "App_Diag_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

#define cDiagForcedIdle		0u
#define cDiagForcedInit 	1u
#define cDiagForcedOff 		2u
#define cDiagForcedOn 		3u


#define cLED_DUTY_100		10000u	// 100 * 100
#define cLED_DUTY_0			0u		// 0 * 100

#define cFAN_DUTY_50		5000u	// 50 * 100
#define cFAN_DUTY_0			0u		// 0 * 100

#define Par_DiagLedBlinkRepeatCnt	5u
#define Par_DiagFanOnOffRepeatCnt	1u

#define Par_DiagLedBlinkTime 		(1000u 	/ TIME_10MS)
#define Par_DiagFanOnTime 			(5000u 	/ TIME_10MS)

typedef enum
{
	Tim_AmberBlink,
	Tim_GreenBlink,
	Tim_FanOnOff,
	Tim_DIAG_MAX
}Diag_Timer_t;

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/

typedef struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;
	uint8_t StateCurr;		// Current State
	uint8_t StateNext;		// Next State
	uint8_t StateOld;		// Old State
	uint8_t EntryCnt;		// Entry Count
	uint8_t ExitCnt;		// Exit Count

	uint8_t AmberDiagBlink_State;
	uint8_t GreenDiagBlink_State;
	uint8_t FanDiagOnOff_State;

	uint16_t AmberDiagBlinkCnt;
	uint16_t GreenDiagBlinkCnt;
	uint16_t FanDiagOnOffCnt;
} Inter_t;

typedef struct
{
	IDT_ADC_STR 		Inp_ADC;
	IDT_Uds_STR 		Inp_Uds;	
	IDT_WCT_STR 		Inp_WCT;
	IDT_CAN_RX_STR 		Inp_CAN_RX;
	Inter_t 			Int;
	Timer_t 			Timer[Tim_DIAG_MAX];
	IDT_Diag_STR 		Out;

} Diag_struct;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

static Diag_struct Diag = {0};


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_Diag_InitSet(void);
static void ss_Diag_Data_Init(void);
static void ss_Diag_RteRead(void);
static void ss_Diag_RteWrite(void);
static void ss_Diag_StateMachine(uint8_t CurrState, uint8_t action);
static void ss_Diag_Disable(uint8_t action);
static void ss_Diag_Enable(uint8_t action);
static void ss_Diag_AmberForced(void);
static void ss_Diag_GreenForced(void);
static void ss_Diag_FanForced(void);
/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_Diag_CODE) Diag_TE_Runnable(void)
{
	switch(Diag.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&Diag.Int.App_Init_Completed);				/* SWP Init Complete Check */

			if( Diag.Int.App_Init_Completed == ON ) /* SWP Init Complete? */
			{
				ss_Diag_InitSet();

				Diag.Int.Runnable_State = 1u;	/*  Main Runnable Mode Move > App Run */
			}
		break;

		case 1u:

			//------------------------------------------------------
			// Input
			//------------------------------------------------------
			ss_Diag_RteRead();

			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------

			ss_Diag_StateMachine(Diag.Int.StateCurr, DURING);

			// 상태 천이 발생시에만 실행
			if (Diag.Int.StateCurr != Diag.Int.StateNext)
			{
				ss_Diag_StateMachine(Diag.Int.StateCurr, EXIT);
				ss_Diag_StateMachine(Diag.Int.StateNext, ENTRY);

				Diag.Int.StateCurr = Diag.Int.StateNext;
			}

			//------------------------------------------------------
			// Timer
			//------------------------------------------------------
			gs_UpdateTimer(&Diag.Timer[0], (uint8_t)Tim_DIAG_MAX); // 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.

			//-----------------------------------------------------
			// Output
			//------------------------------------------------------
			ss_Diag_RteWrite();

		break;

		default:
			Diag.Int.Runnable_State = 0u;
		break;
	}

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_Diag_InitSet(void)
{
	Diag.Int.StateCurr = cDiag_Disable;
	Diag.Int.StateNext = cDiag_Disable;
	Diag.Int.StateOld = cDiag_Disable;
	Diag.Int.EntryCnt = 0u;
	Diag.Int.ExitCnt = 0u;
	

	ss_Diag_Disable(ENTRY);	// 전원 리셋시 Entry를 강제로 1회 실행시켜줘야함.// 초기화 함수가 호출됨.

}
/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Diag_Data_Init(void)
{
	memset(&Diag.Out, 0, sizeof(Diag.Out));	// 구조체 변수를 0으로 클리어

	Diag.Int.AmberDiagBlink_State = cDiagForcedInit;
	Diag.Int.GreenDiagBlink_State = cDiagForcedInit;
	Diag.Int.FanDiagOnOff_State = cDiagForcedInit;

	Diag.Int.AmberDiagBlinkCnt = 0;
	Diag.Int.GreenDiagBlinkCnt = 0;
	Diag.Int.FanDiagOnOffCnt = 0;

	gs_InitTimer(&Diag.Timer[0], (uint8_t)Tim_DIAG_MAX);	// 반드시 TmerTbl[0] 으로 호출해야 전체 타이머가 적용된다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Diag_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_ADC_ADC_STR(&Diag.Inp_ADC);
	Rte_Read_R_Uds_Uds_STR(&Diag.Inp_Uds);
	Rte_Read_R_WCT_WCT_STR(&Diag.Inp_WCT);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       none
***************************************************************************************************/
static void ss_Diag_RteWrite(void)
{
	Diag.Out.Diag_Status = Diag.Int.StateCurr;
	// 타 SWC에 RTE로 전달
	Rte_Write_P_Diag_Diag_STR(&Diag.Out);	// 한꺼번에 전송
}


/***************************************************************************************************
@param[in]  CurrState : Current State
@param[in]	Command : En, Do, Ex Condition
@return     void
@note       none
***************************************************************************************************/
static void ss_Diag_StateMachine(uint8_t CurrState, uint8_t action)
{
	switch (CurrState)
	{
		case cDiag_Disable:
			ss_Diag_Disable(action);
		break;

		case cDiag_Enable:
		 	ss_Diag_Enable(action);
		break;

		default:
		// M3CM Rule-15.7
		break;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_Diag_Disable(uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:

		ss_Diag_Data_Init();

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:
		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 Level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (Diag.Int.StateCurr == Diag.Int.StateNext)
		{
			// State's Transitions
			//if(Diag.Inp_WCT.DiagStartFlag == ON)
			if((Diag.Inp_ADC.IGN1_IN == ON) &&
			(Diag.Inp_ADC.BatSysStateFault == OFF) &&
			((Diag.Inp_Uds.DiagAmberBlink == ON) ||
			(Diag.Inp_Uds.DiagGreenBlink == ON) ||
			(Diag.Inp_Uds.DiagFanRotate == ON)))		
			{
				Diag.Int.StateNext = cDiag_Enable;
				Diag.Int.EntryCnt = 0u; // En 실행 : None
				Diag.Int.ExitCnt = 0u;  // Ex 실행 : None
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
	// M3CM Rule-15.7
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note       상위(부모) - 하위(자식) 간 천이할 경우만 EntryCnt, ExitCnt를 적용한다.
***************************************************************************************************/
static void ss_Diag_Enable(uint8_t action)
{
	switch (action)
	{
	//============= Sub State 진입 시, 상위(부모) --> 하위(자식) 수행
	case ENTRY:
			ss_Diag_AmberForced();
			ss_Diag_GreenForced();
			ss_Diag_FanForced();

		break;

	//===== Duration 시, 상위(부모) --> 하위(자식) Transition 조건 확인
	//===== 상위(부모) State의 Transition 미 발생시 현재 State의 Transtion 조건 확인
	case DURING:

		// 1. 상위(부모) Level State Transition 조건 확인
		// 상위 level State 없음

		// 2. 하위(자식) Level State Transition 조건 확인
		if (Diag.Int.StateCurr == Diag.Int.StateNext)
		{
			// State's Transitions
			//if(Diag.Inp_WCT.DiagStartFlag == OFF)
			if((Diag.Inp_ADC.IGN1_IN == OFF) ||
			(Diag.Inp_ADC.BatSysStateFault == ON) ||
			((Diag.Inp_Uds.DiagAmberBlink == OFF) &&
			(Diag.Inp_Uds.DiagGreenBlink == OFF) &&
			(Diag.Inp_Uds.DiagFanRotate == OFF)))			
			{
				Diag.Int.StateNext = cDiag_Disable;
				Diag.Int.EntryCnt = 0u; // En 실행 : None
				Diag.Int.ExitCnt = 0u;  // Ex 실행 : None
			}
			else
			{
				// 3. 현재 State의 Transiton 미발생시 Du 수행
				ss_Diag_AmberForced();
				ss_Diag_GreenForced();
				ss_Diag_FanForced();

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
	// M3CM Rule-15.7
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note		duty 100% 로 1초 on, 1초 off 5회 반복
***************************************************************************************************/
static void ss_Diag_AmberForced(void)
{
	switch(Diag.Int.AmberDiagBlink_State)
	{
		case cDiagForcedIdle:
			// M3CM Rule-15.7
			break;

		case cDiagForcedInit:
			if(Diag.Inp_Uds.DiagAmberBlink == ON)			
			{
				gs_StartTimer(&Diag.Timer[Tim_AmberBlink]);

				Diag.Out.AmberIND_OUT = cLED_DUTY_100;	// 강제 구동 100% 출력

				Diag.Int.AmberDiagBlink_State = cDiagForcedOn;
			}
			break;

		case cDiagForcedOn:
			if((Diag.Inp_Uds.DiagAmberBlink == OFF) ||
			(Diag.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH >= 5u))
			{
				gs_CancelTimer(&Diag.Timer[Tim_AmberBlink]);

 				Diag.Out.AmberIND_OUT = cLED_DUTY_0;	// 강제 구동 0% 출력

				Diag.Int.AmberDiagBlink_State = cDiagForcedIdle;
			}
			else if(Diag.Timer[Tim_AmberBlink].Count >= Par_DiagLedBlinkTime) // 1초
			{
				gs_StartTimer(&Diag.Timer[Tim_AmberBlink]);

				Diag.Out.AmberIND_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

				Diag.Int.AmberDiagBlink_State = cDiagForcedOff;
			}
			else
			{
			// M3CM Rule-15.7
			}
			break;

		case cDiagForcedOff:
			if((Diag.Inp_Uds.DiagAmberBlink == OFF) ||
			(Diag.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH >= 5u))
			{
				gs_CancelTimer(&Diag.Timer[Tim_AmberBlink]);

 				Diag.Out.AmberIND_OUT = cLED_DUTY_0;	// 강제 구동 0% 출력

				Diag.Int.AmberDiagBlink_State = cDiagForcedIdle;
			}
			else if(Diag.Timer[Tim_AmberBlink].Count >= Par_DiagLedBlinkTime) // 1초
			{
				Diag.Int.AmberDiagBlinkCnt ++;

				if(Diag.Int.AmberDiagBlinkCnt >= Par_DiagLedBlinkRepeatCnt)
				{
					gs_CancelTimer(&Diag.Timer[Tim_AmberBlink]);

					Diag.Out.AmberIND_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

					Diag.Int.AmberDiagBlink_State = cDiagForcedIdle;
				}
				else
				{
					gs_StartTimer(&Diag.Timer[Tim_AmberBlink]);

					Diag.Out.AmberIND_OUT = cLED_DUTY_100;// 강제 구동 100% 출력

					Diag.Int.AmberDiagBlink_State = cDiagForcedOn;
				}
			}
			else
			{
				// M3CM Rule-15.7
			}
			break;
		default:
		// M3CM Rule-15.7
			break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note		duty 100% 로 1초 on, 1초 off 5회 반복
***************************************************************************************************/
static void ss_Diag_GreenForced(void)
{
	switch(Diag.Int.GreenDiagBlink_State)
	{
		case cDiagForcedIdle:
			// M3CM Rule-15.7
			break;

		case cDiagForcedInit:
			if(Diag.Inp_Uds.DiagGreenBlink == ON)
			{
				gs_StartTimer(&Diag.Timer[Tim_GreenBlink]);

				Diag.Out.GreenIND1_OUT = cLED_DUTY_100;// 강제 구동 100% 출력
				Diag.Out.GreenIND2_OUT = cLED_DUTY_100;// 강제 구동 100% 출력
				Diag.Out.GreenIND3_OUT = cLED_DUTY_100;// 강제 구동 100% 출력

				Diag.Int.GreenDiagBlink_State = cDiagForcedOn;
			}
			break;

		case cDiagForcedOn:
			if((Diag.Inp_Uds.DiagGreenBlink == OFF) ||
			(Diag.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH >= 5u))
			{
				gs_CancelTimer(&Diag.Timer[Tim_GreenBlink]);
				Diag.Out.GreenIND1_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND2_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND3_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

				Diag.Int.GreenDiagBlink_State = cDiagForcedIdle;
			}
			else if(Diag.Timer[Tim_GreenBlink].Count >= Par_DiagLedBlinkTime) // 1초
			{
				gs_StartTimer(&Diag.Timer[Tim_GreenBlink]);
				Diag.Out.GreenIND1_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND2_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND3_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

				Diag.Int.GreenDiagBlink_State = cDiagForcedOff;
			}
			else
			{
				// M3CM Rule-15.7
			}
			break;

		case cDiagForcedOff:
			if((Diag.Inp_Uds.DiagGreenBlink == OFF) ||
			(Diag.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH >= 5u))
			{
				gs_CancelTimer(&Diag.Timer[Tim_GreenBlink]);
				Diag.Out.GreenIND1_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND2_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
				Diag.Out.GreenIND3_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

				Diag.Int.GreenDiagBlink_State = cDiagForcedIdle;
			}
			if(Diag.Timer[Tim_GreenBlink].Count >= Par_DiagLedBlinkTime)
			{
				Diag.Int.GreenDiagBlinkCnt++;

				if(Diag.Int.GreenDiagBlinkCnt >= Par_DiagLedBlinkRepeatCnt)
				{
					gs_CancelTimer(&Diag.Timer[Tim_GreenBlink]);
					Diag.Out.GreenIND1_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
					Diag.Out.GreenIND2_OUT = cLED_DUTY_0;// 강제 구동 0% 출력
					Diag.Out.GreenIND3_OUT = cLED_DUTY_0;// 강제 구동 0% 출력

					Diag.Int.GreenDiagBlink_State = cDiagForcedIdle;
				}
				else
				{
					gs_StartTimer(&Diag.Timer[Tim_GreenBlink]);

					Diag.Out.GreenIND1_OUT = cLED_DUTY_100;// 강제 구동 100% 출력
					Diag.Out.GreenIND2_OUT = cLED_DUTY_100;// 강제 구동 100% 출력
					Diag.Out.GreenIND3_OUT = cLED_DUTY_100;// 강제 구동 100% 출력

					Diag.Int.GreenDiagBlink_State = cDiagForcedOn;
				}
			}
			else
			{
				// M3CM Rule-15.7
			}
			break;

		default:
		// M3CM Rule-15.7
			break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note		duty 50% 로 5초 ON 후 OFF
***************************************************************************************************/
static void ss_Diag_FanForced(void)
{
	switch(Diag.Int.FanDiagOnOff_State)
	{
		case cDiagForcedIdle:
			// M3CM Rule-15.7
			break;

		case cDiagForcedInit:
			if(Diag.Inp_Uds.DiagFanRotate == ON)
			{
				gs_StartTimer(&Diag.Timer[Tim_FanOnOff]);
				Diag.Out.FAN_PWM = cFAN_DUTY_50;	// 강제 구동 50% 출력

				Diag.Int.FanDiagOnOff_State = cDiagForcedOn;
			}
			break;

		case cDiagForcedOn:
			if((Diag.Inp_Uds.DiagFanRotate == OFF) ||
			(Diag.Inp_CAN_RX.BCAN.C_CLU_DisSpdVal_KPH >= 5u))
			{
				Diag.Int.FanDiagOnOffCnt = 0u;
				gs_CancelTimer(&Diag.Timer[Tim_FanOnOff]);
 				Diag.Out.FAN_PWM = cLED_DUTY_0;	// 강제 구동 0% 출력

				Diag.Int.FanDiagOnOff_State = cDiagForcedIdle;
			}
			else if(Diag.Timer[Tim_FanOnOff].Count >= Par_DiagFanOnTime)
			{
				Diag.Int.FanDiagOnOffCnt = 0u;
				gs_CancelTimer(&Diag.Timer[Tim_FanOnOff]);
				Diag.Out.FAN_PWM = cLED_DUTY_0;// 강제 구동 0% 출력


				Diag.Int.FanDiagOnOff_State = cDiagForcedIdle; // off 는 불필요하므로 led와는 다르게 설정함
			}
			else
			{
				// M3CM Rule-15.7
			}
			break;

		// 강제 구동 방식이 LED와 FAN이 다르므로 아래 코드는 불필요하여 주석 처리함.

		// case cDiagForcedOff:
		// 	if(Diag.Inp_Uds.DiagFanRotate == OFF)
		// 	{
		// 		Diag.Int.FanDiagOnOffCnt = 0u;
		// 		gs_CancelTimer(&Diag.Timer[Tim_FanOnOff]);
 		// 		Diag.Out.FAN_PWM = cLED_DUTY_0;	// 강제 구동 0% 출력
		// 		Diag.Out.FanRotateEnable = OFF;

		// 		Diag.Int.FanDiagOnOff_State = cDiagForcedInit;
		// 	}
		// 	else if(Diag.Timer[Tim_FanOnOff].Count >= Par_DiagFanOnTime)
		// 	{
		// 		Diag.Int.FanDiagOnOffCnt++;

		// 		if(Diag.Int.FanDiagOnOffCnt >= Par_DiagFanOnOffRepeatCnt)
		// 		{
		// 			Diag.Int.FanDiagOnOffCnt = 0u;
		// 			gs_CancelTimer(&Diag.Timer[Tim_FanOnOff]);
		// 			Diag.Out.FAN_PWM = cLED_DUTY_0;// 강제 구동 0% 출력
		// 			Diag.Out.FanRotateEnable = OFF;

		// 			Diag.Int.FanDiagOnOff_State = cDiagForcedInit;
		// 		}
		// 		else
		// 		{
		// 			gs_StartTimer(&Diag.Timer[Tim_FanOnOff]);

		// 			Diag.Out.FAN_PWM = cFAN_DUTY_50;// 강제 구동 50% 출력

		// 			Diag.Int.FanDiagOnOff_State = cDiagForcedOn;
		// 		}
		// 	}
		// 	else
		// 	{

		// 	}
		// 	break;

		default:
		// M3CM Rule-15.7
			break;
	}
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_Diag_L2H_Set(void)
{
	Diag.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함

}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_Diag_H2L_Set(void)
{



}


#define App_Diag_STOP_SEC_CODE
#include "App_Diag_MemMap.h"
