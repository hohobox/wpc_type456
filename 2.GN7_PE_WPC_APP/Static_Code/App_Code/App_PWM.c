
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
#include "App_PWM.h"
#include "Rte_App_PWM.h"

#include "App_WCT.h"
#include "App_Uds.h"

#define App_PWM_START_SEC_CODE
#include "App_PWM_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

#define Par_FanDutyOffset	(500u)		// 100 : 1%  // 출력 요청값보다 항상 5% 높게 출력하도록 로직 수정 (단 100%는 그대로 100% 출력)

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


typedef struct
{
	uint8_t App_Init_Completed;
	uint8_t Runnable_State;

}Inter_t;


typedef struct
{
	IDT_Model_STR	Inp_Model;
	IDT_Uds_STR 	Inp_Uds;
	IDT_DTC_STR		Inp_DTC;
	IDT_Diag_STR 	Inp_Diag;
	IDT_NvM_STR 	Inp_NvM;
	
	Inter_t 		Int;
	IDT_PWM_STR		Out;
} PWM_struct;



/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/

static PWM_struct PWM = {0};


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_PWM_InitSet(void);
static void ss_PWM_RteRead(void);
static void ss_PWM_DutySet(void);
static void ss_PWM_RteWrite(void);


/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
FUNC(void, App_PWM_CODE) PWM_TE_Runnable(void)
{

	switch(PWM.Int.Runnable_State)
	{
		case 0u:// // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&PWM.Int.App_Init_Completed);

			if( PWM.Int.App_Init_Completed == ON ) 	/* SWP Init Complete? */
			{

				ss_PWM_InitSet(); 		/* SWC Init Process */

				PWM.Int.Runnable_State = 1u;
			}
		break;

		case 1u:


			ss_PWM_RteRead();

			ss_PWM_DutySet();

			ss_PWM_RteWrite();


		break;

		default:
			PWM.Int.Runnable_State = 0u;
		break;
	}
}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_PWM_InitSet(void)
{
	memset(&PWM.Out, 0, sizeof(PWM.Out));  				// 구조체 변수를 0으로 클리어
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_PWM_RteRead(void)
{
	// 구조체로 수신
	Rte_Read_R_Model_Model_STR(&PWM.Inp_Model);
	Rte_Read_R_Uds_Uds_STR(&PWM.Inp_Uds);
	Rte_Read_R_DTC_DTC_STR(&PWM.Inp_DTC);
	Rte_Read_R_Diag_Diag_STR(&PWM.Inp_Diag);
	Rte_Read_R_NvM_NvM_STR(&PWM.Inp_NvM);
}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_PWM_RteWrite(void)
{
	// 타 SWC에 RTE로 전달
	Rte_Write_P_PWM_PWM_STR(&PWM.Out);	// 배열로 한꺼번에 전송
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_PWM_DutySet(void)
{
	// PWM 출력값 통합 판단 처리

	for(uint8_t Device = 0; Device < PWM.Inp_NvM.DeviceMaxCnt; Device++)
	{
		// 강제 구동 여부 판단
		if((PWM.Inp_Uds.DiagAmberBlink == ON) || 	 // 강제 구동 일경우
		(PWM.Inp_Uds.DiagGreenBlink == ON) ||
		(PWM.Inp_Uds.DiagFanRotate == ON))
		{
			// 강제 구동 함수에서 생성된 PWM
			PWM.Out.Device[Device].GREEN1_PWM_DUTY = PWM.Inp_Diag.GreenIND1_OUT;
			PWM.Out.Device[Device].GREEN2_PWM_DUTY = PWM.Inp_Diag.GreenIND2_OUT;
			PWM.Out.Device[Device].GREEN3_PWM_DUTY = PWM.Inp_Diag.GreenIND3_OUT;
			PWM.Out.Device[Device].AMBER_PWM_DUTY = PWM.Inp_Diag.AmberIND_OUT;
			PWM.Out.Device[Device].FAN_PWM_DUTY = PWM.Inp_Diag.FAN_PWM;
		}
		else // 모두가 강제 구동 아닐 경우
		{
			// blink 아닐때는 모델에서 보내준 값을 그대로 출력한다.
			PWM.Out.Device[Device].GREEN1_PWM_DUTY = PWM.Inp_Model.Device[Device].GreenIND1_OUT;
			PWM.Out.Device[Device].GREEN2_PWM_DUTY = PWM.Inp_Model.Device[Device].GreenIND2_OUT;
			PWM.Out.Device[Device].GREEN3_PWM_DUTY = PWM.Inp_Model.Device[Device].GreenIND3_OUT;
			PWM.Out.Device[Device].AMBER_PWM_DUTY = PWM.Inp_Model.Device[Device].AmberIND_OUT;
			PWM.Out.Device[Device].FAN_PWM_DUTY = PWM.Inp_Model.Device[Device].FAN_PWM;
		}

		// 진단에서 팬연결하지 않고 초기 구동시에 fan fault 검출전까지 IORead에서 Fan Duty 20%로 출력된다.
		// 이때도 0%로 출력되도록 하기 로직 추가
		if(PWM.Inp_DTC.Device[Device].FanFault == (uint8_t)DETECTED_OFF)
		{
			PWM.Out.Device[Device].FAN_PWM_DUTY_DIAG = PWM.Inp_Model.Device[Device].FAN_PWM;	// 모델에서 수신한 값
		}
		else if(PWM.Inp_DTC.Device[Device].FanFault == (uint8_t)DETECTED_ON)
		{
			PWM.Out.Device[Device].FAN_PWM_DUTY_DIAG = 0u;
		}
		else // DETECTED_DEFAULT
		{
			//if(PWM.Inp_Diag.FanRotateEnable == ON)
			if(PWM.Inp_Uds.DiagFanRotate == ON)
			{
				PWM.Out.Device[Device].FAN_PWM_DUTY_DIAG = PWM.Inp_Diag.FAN_PWM;	// 강제 구동 출력값
			}
			else
			{
				PWM.Out.Device[Device].FAN_PWM_DUTY_DIAG = 0u;
			}
		}

#if defined (DEBUG_TUNE_MODE_USE)

		if(PWM.Inp_Uds.DvpTuneData[0]  == Tune_Index_LED)
    	{
			PWM.Out.Device[Device].GREEN1_PWM_DUTY = ((uint16_t)PWM.Inp_Uds.DvpTuneData[1] * 100u) + (uint16_t)PWM.Inp_Uds.DvpTuneData[2]; // 모델에서 나온값과 동일하게 만단위로 변경시킴
			PWM.Out.Device[Device].GREEN2_PWM_DUTY = PWM.Out.Device[Device].GREEN1_PWM_DUTY;
			PWM.Out.Device[Device].GREEN3_PWM_DUTY = PWM.Out.Device[Device].GREEN1_PWM_DUTY;

			PWM.Out.Device[Device].AMBER_PWM_DUTY = ((uint16_t)PWM.Inp_Uds.DvpTuneData[3] * 100u) + (uint16_t)PWM.Inp_Uds.DvpTuneData[4]; // 모델에서 나온값과 동일하게 만단위로 변경시킴
    	}
#endif

#if defined (DEBUG_TUNE_MODE_USE)

		if(PWM.Inp_Uds.DvpTuneData[0]  == Tune_Index_FAN)
    	{
			PWM.Out.Device[Device].FAN_PWM_DUTY = (uint16_t)PWM.Inp_Uds.DvpTuneData[1] * 100u; // 모델에서 나온값과 동일하게 만단위로 변경시킴
    	}
#endif

	}

	// 애니메이션 삭제로 인해서 rte 함수명 변경됨

	// IoHwAb에 전달
	// blink 일때는 Blink함수에서 생성한 값으로 출력한다.
	Rte_Call_R_AmberIND1_SetDutyCycle(((PWM.Out.Device[D0].AMBER_PWM_DUTY) * 32768u) / 10000u);
	Rte_Call_R_GreenIND1_SetDutyCycle(((PWM.Out.Device[D0].GREEN1_PWM_DUTY) * 32768u) / 10000u);
		

	// 출력 요청값보다 항상 5% 높게 출력하도록 로직 수정 (단 100%는 그대로 100% 출력)

	// on/off 일때는 on/off 함수에서 생성한 값으로 출력한다.
	if((PWM.Out.Device[D0].FAN_PWM_DUTY > 0u) && (PWM.Out.Device[D0].FAN_PWM_DUTY < 10000u)) // 100%
	{
		Rte_Call_R_FANPWM1_SetDutyCycle(((PWM.Out.Device[D0].FAN_PWM_DUTY + Par_FanDutyOffset) * 32768u) / 10000u); // 100% 아닐때는 5% 높게 출력
	}
	else
	{
		Rte_Call_R_FANPWM1_SetDutyCycle((PWM.Out.Device[D0].FAN_PWM_DUTY * 32768u) / 10000u); // 100%일때는 100% 출력
	}
	
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	if((PWM.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
	(PWM.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
	{
		Rte_Call_R_AmberIND2_SetDutyCycle(((PWM.Out.Device[D1].AMBER_PWM_DUTY) * 32768u) / 10000u);
		Rte_Call_R_GreenIND2_SetDutyCycle(((PWM.Out.Device[D1].GREEN1_PWM_DUTY) * 32768u) / 10000u);
		// 출력 요청값보다 항상 5% 높게 출력하도록 로직 수정 (단 100%는 그대로 100% 출력)

		// on/off 일때는 on/off 함수에서 생성한 값으로 출력한다.
		if((PWM.Out.Device[D1].FAN_PWM_DUTY > 0u) && (PWM.Out.Device[D1].FAN_PWM_DUTY < 10000u)) // 100%
		{
			Rte_Call_R_FANPWM2_SetDutyCycle(((PWM.Out.Device[D1].FAN_PWM_DUTY + Par_FanDutyOffset) * 32768u) / 10000u); // 100% 아닐때는 5% 높게 출력
		}
		else
		{
			Rte_Call_R_FANPWM2_SetDutyCycle((PWM.Out.Device[D1].FAN_PWM_DUTY * 32768u) / 10000u); // 100%일때는 100% 출력
		}
	}
//#endif
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_PWM_L2H_Set(void)
{

	PWM.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_PWM_H2L_Set(void)
{
	/* PWM OFF */
	Rte_Call_R_AmberIND1_SetOutputToIdle();
	Rte_Call_R_GreenIND1_SetOutputToIdle();

	Rte_Call_R_FANPWM1_SetOutputToIdle();

//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
	if((PWM.Inp_NvM.WPC_TYPE == cWPC_TYPE5) || /* only dual */
	(PWM.Inp_NvM.WPC_TYPE == cWPC_TYPE6))
	{
		Rte_Call_R_AmberIND2_SetOutputToIdle();
		Rte_Call_R_GreenIND2_SetOutputToIdle();

		Rte_Call_R_FANPWM2_SetOutputToIdle();
	}
//#endif	
}

#define App_PWM_STOP_SEC_CODE
#include "App_PWM_MemMap.h"
