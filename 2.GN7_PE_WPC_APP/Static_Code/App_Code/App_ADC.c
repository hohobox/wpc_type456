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
#include "App_ADC.h"
#include "Rte_App_ADC.h"



#define App_ADC_START_SEC_CODE
#include "App_ADC_MemMap.h"
/***************************************************************************************************
    LOCAL DEFINES AND MACROS
***************************************************************************************************/

/* ss_InpADConvert Define */
#define cInpLPFAlpha						(uint16_t)39
#define cInpLPFBeta							(uint16_t)61

#define cADC_CNT_MAX						(4095u)	// 12bit
#define cADC_mV_MAX							(3300u) // WPC_402_16

#define cBAT_INPUT_VOLTAGE_DIVIDER_REG1		(120000u)// WPC_402_16
#define cBAT_INPUT_VOLTAGE_DIVIDER_REG2		(22000u)

//#define cIGN_INPUT_VOLTAGE_DIVIDER_REG1		(4020u) // WPC_406_02
#define cIGN_INPUT_VOLTAGE_DIVIDER_REG1		(8200u)		// WPC_406_02 // 분압비 변경
#define cIGN_INPUT_VOLTAGE_DIVIDER_REG2		(3320u)


// P2 보드 02.02.00.00 보드는 기존 보드와 달리 다이오드 삭제됨. 보정처리 불필요함.
#define cBAT_INPUT_OFFSET_mV				(uint16_t)(0) // WPC_423_03
#define cIGN_INPUT_OFFSET_mV				(uint16_t)(0) // WPC_402_16
#define AD_CNT_TO_mV(adcCnt)				(((unsigned int)(adcCnt) * cADC_mV_MAX) / cADC_CNT_MAX)
#define BAT_ADC_TO_mV(adcCnt)				((AD_CNT_TO_mV(adcCnt) * (cBAT_INPUT_VOLTAGE_DIVIDER_REG1 + cBAT_INPUT_VOLTAGE_DIVIDER_REG2)) / cBAT_INPUT_VOLTAGE_DIVIDER_REG2)
#define IGN_ADC_TO_mV(adcCnt)				((AD_CNT_TO_mV(adcCnt) * (cIGN_INPUT_VOLTAGE_DIVIDER_REG1 + cIGN_INPUT_VOLTAGE_DIVIDER_REG2)) / cIGN_INPUT_VOLTAGE_DIVIDER_REG2)


// WPC_402_16




// 분압비 변경 : 12V까지 표출가능하도록 변경
#define cIGNOff								(uint16_t)1236	// WPC_406_02 // Ign Off : Connetor : 4V (MCU:0.99V), 12bit ADC
#define cIGN1On								(uint16_t)2293	// WPC_406_02 // Ign On : Connetor : 7V(MCU1.84V), 12bit ADC

#define cFilteringTime						((uint16_t)(30)/TIME_10MS)

/***************************************************************************************************
    LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
***************************************************************************************************/


typedef enum
{
	ADC_BAT,
	ADC_IGN1,
	ADC_NUMBER
} ADC_LIST;

typedef struct
{
	uint8_t 	App_Init_Completed;
	uint8_t 	Runnable_State;

	//uint8_t		BatSysStateFault;
	//uint8_t 	BatCanStateFault;

	//uint8_t 	IGN1_IN;

	uint16_t	BATVolt;
	uint16_t	BatteryVoltAD;

	uint16_t	IGN1Volt;
	uint16_t	IGN1VoltAD;
	
	//uint8_t 	PDC_LOW_BAT;

} Inter_t;

typedef struct
{
	Inter_t 	Int;
	IDT_ADC_STR Out;
} ADC_struct;


/***************************************************************************************************
    LOCAL VARIABLES AND CONSTANTS
***************************************************************************************************/


static ADC_struct ADC = {0};


/***************************************************************************************************
    LOCAL FUNCTION PROTOTYPES
***************************************************************************************************/
static void ss_ADC_InitSet(void);
//static void ss_ADC_RteRead(void);
static void ss_ADC_RteWrite(void);
static void ss_ADC_ADConvert(void);
static void ss_ADC_SysVoltageCtrl(void);
static void ss_ADC_CanVoltageCtrl(void);
static void ss_ADC_IG1SwRead(void);
static void ss_ADC_PDC_LowVoltageCtrl(void);

/***************************************************************************************************
    GLOBAL FUNCTIONS
***************************************************************************************************/


/***************************************************************************************************
@param[in]  void
@return     void
@note 		Runnable
***************************************************************************************************/
FUNC(void, App_ADC_CODE) ADC_TE_Runnable(void)
{
	switch(ADC.Int.Runnable_State)
	{
		case 0u: // // Sleep --> Wakeup 시 마다 Runnable_State를 초기화하여 재시작하도록 설정됨. 모듈에 따라 재시작 안하는 경우도 있음
			Rte_Call_R_CS_Mode_ApplicationInit(&ADC.Int.App_Init_Completed);

			if( ADC.Int.App_Init_Completed == ON ) 	/* SWP Init Complete? */
			{

				ss_ADC_InitSet(); 		/* SWC Init Process */

				ADC.Int.Runnable_State = 1u;

			}
		break;

		case 1u:


			//------------------------------------------------------
			// Input (Rte Read)
			//------------------------------------------------------
			//ss_ADC_RteRead();

			//------------------------------------------------------
			// Control Logic
			//------------------------------------------------------
			ss_ADC_ADConvert();
			ss_ADC_SysVoltageCtrl();
			ss_ADC_CanVoltageCtrl();
			ss_ADC_IG1SwRead();
			ss_ADC_PDC_LowVoltageCtrl();



			//------------------------------------------------------
			// Timer
			//------------------------------------------------------


			//------------------------------------------------------
			// Output (Rte Write)
			//------------------------------------------------------

			ss_ADC_RteWrite();


		break;

		default:
			ADC.Int.Runnable_State = 0u;
		break;
	}
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
uint8_t    gs_Get_ADC_IGN1_IN(void)
{
	VAR(Std_ReturnType, AUTOMATIC) retValue;
	uint8_t mbIgn1WakeupFlag;										/* IGN1 State Return Value */
	uint16_t mwADScanData = 0;												/* ADC Read */
	uint16_t mwIGNVoltBuf;												/* IGN ADC read direct 값 */
	uint16_t mwIGNVoltAD;												/* lowpass filter를 거친 IGN AD값 */

	retValue = Rte_Call_R_IGN1_ADC_ReadDirect(&mwADScanData, 1u);  /* IGN1 ADC Read */
	if(retValue == RTE_E_OK){	 									    /* ADC RTE Ok */
		mwIGNVoltBuf = mwADScanData;

		mwIGNVoltAD = (uint16_t)(((cInpLPFAlpha * mwIGNVoltBuf) + (cInpLPFBeta * mwIGNVoltBuf)) / 100u);

		if( mwIGNVoltAD >= cIGN1On ){
			mbIgn1WakeupFlag = ON;  /* IGN1 ON -> Wakeup */
		}else{
			mbIgn1WakeupFlag = OFF; /* IGN1 OFF -> Sleep */
		}
	}else{
		mbIgn1WakeupFlag = OFF;     /* IGN1 OFF -> Sleep */
	}

	return mbIgn1WakeupFlag;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_ADC_InitSet(void)
{

	memset(&ADC.Out, 0, sizeof(ADC.Out));  				// 구조체 변수를 0으로 클리어

	// ADC.Out.BatSysStateFault = OFF;
	// ADC.Out.BatCanStateFault = OFF;
	// ADC.Out.IGN1_IN = OFF;
	ADC.Int.BATVolt = 0;
	ADC.Int.BatteryVoltAD = 0;
	ADC.Int.IGN1Volt = 0;
	ADC.Int.IGN1VoltAD = 0;
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
// static void ss_ADC_RteRead(void)
// {

// }




/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_ADC_ADConvert(void)
{
	static uint16_t mwADScanData[ADC_NUMBER];										/* ADC완료 후 리턴된 값 저장버퍼 */
	static uint16_t mwBatteryVoltBuf = 0;											/* B+ ADC read direct 값 */
	static uint16_t mwBatteryVoltAD = 0;											/* lowpass filter를 거친 B+ AD값 */
	static uint16_t mwBatteryVoltADOld = 0;											/* lowpass filter를 거친 B+ AD Old값 */
	static uint16_t mwBatteryVolt = 0;												/* mV로 환산된 B+값 */
	static uint16_t mwIGNVoltBuf = 0;												/* IGN ADC read direct 값 */
	static uint16_t mwIGNVoltAD = 0;												/* lowpass filter를 거친 IGN AD값 */
	static uint16_t mwIGNVoltADOld = 0;												/* lowpass filter를 거친 IGN AD Old값 */
	static uint16_t mwIGNVolt = 0;													/* mV로 환산된 IGN 전압값 */

	static uint8_t mbInpADCInitFlg = OFF;											/* ADC최초 실행시, 처음읽은 ADC값을 Old값으로 대입하기 위함. */

	VAR(Std_ReturnType, AUTOMATIC) retValue;

	retValue = Rte_Call_R_VBAT_ADC_ReadDirect(&mwADScanData[ADC_BAT], 1u);	/* B+ ADC Read */
	if(retValue == RTE_E_OK)													/* ADC RTE Ok */
	{
		mwBatteryVoltBuf = mwADScanData[ADC_BAT];
	}

	retValue = Rte_Call_R_IGN1_ADC_ReadDirect(&mwADScanData[ADC_IGN1], 1u);/* IGN1 ADC Read */
	if(retValue == RTE_E_OK)													/* ADC RTE Ok */
	{
		mwIGNVoltBuf = mwADScanData[ADC_IGN1];
	}



	if(mbInpADCInitFlg == OFF)													/* ADC최초 실행시, 처음읽은 ADC값을 Old값으로 대입하기 위함. */
	{
		mbInpADCInitFlg = ON;
		mwBatteryVoltADOld = mwBatteryVoltBuf;
		mwIGNVoltADOld = mwIGNVoltBuf;
	}

	/*----------------------------------------------*/
	/*      LOW PASS FILTER FUNC                    */
	/*----------------------------------------------*/
	/********************************************************************/
	/* SOFT FILTER LOW PASS FILTER ( fc = 10Hz )                        */
	/* ・罹･・・封(n) = ( alpha * ・・･・・封(n) + ( beta * ・罹･・・封(n-1)     */
	/* alpha = t / (t + TA) = 0.39                                      */
	/* beta  = TA / (t + TA) = 0.61                                     */
	/* t = 10ms (main task)                                             */
	/* TA = 1 / (2ﾏ* fc)                                                */
	/********************************************************************/


	// 전압 Table 받아야 함.
	// 게산식으로 하면 안됨.
	// 5개 샘플의 평균값으로 적용해야함.

	// 전압 5개 샘플에서 실측하여 회신 받은 후 적용하기.(계산식으로 적용하지 말것)
	// 계산식으로 계산한 전압은 사용하는 곳이 없음. 불필요시 주석 처리 할것.

	/************* Battery ************/
	mwBatteryVoltAD = (uint16_t)(((cInpLPFAlpha * mwBatteryVoltBuf) + (cInpLPFBeta * mwBatteryVoltADOld)) / 100u); // 나누기 100하는 이유는  알파 베타가 원래는 0.39, 0.61 이다.
	mwBatteryVoltADOld = mwBatteryVoltAD; /* BatteryVoltAD Backup */
	//mwBatteryVolt = (uint16_t)BAT_ADC_TO_mV(mwBatteryVoltAD) + cBAT_INPUT_OFFSET_mV;
	mwBatteryVolt = (uint16_t)BAT_ADC_TO_mV(mwBatteryVoltAD);
	//mwBatteryVolt = mwBatteryVolt + (((mwBatteryVoltBuf-200u)/100u)*100u);    // GN7.12_03 // 이 보정은 어떤 처리인가?  잔여분 더해주는 처리인가?

	/************* L_IGN ************/
	mwIGNVoltAD = (uint16_t)(((cInpLPFAlpha * mwIGNVoltBuf) + (cInpLPFBeta * mwIGNVoltADOld)) / 100u);
	mwIGNVoltADOld = mwIGNVoltAD; /* BatteryVoltAD Backup */
	//mwIGNVolt = (uint16_t)IGN_ADC_TO_mV(mwIGNVoltAD) + cIGN_INPUT_OFFSET_mV;
	mwIGNVolt = (uint16_t)IGN_ADC_TO_mV(mwIGNVoltAD);
	//mwIGNVolt = mwIGNVolt + (((mwIGNVoltBuf-250u)/100u)*100u);// GN7.12_03

	/* 출력변수에 대입 */
	ADC.Int.BATVolt = mwBatteryVolt;
	ADC.Int.BatteryVoltAD = mwBatteryVoltAD;

	ADC.Int.IGN1Volt = mwIGNVolt;
	ADC.Int.IGN1VoltAD = mwIGNVoltAD;
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static	void ss_ADC_SysVoltageCtrl(void)
{
    static  uint16_t    BatSysFaultOnCnt = 0u;
    static  uint16_t    BatSysFaultOffCnt = 0u;

    if(( ADC.Int.BatteryVoltAD < cSysBatValue_Low_Set_AD ) ||
    ( ADC.Int.BatteryVoltAD > cSysBatValue_High_Set_AD ))
	{
		if(BatSysFaultOnCnt >= cFilteringTime)	// 30ms chattering
		{
			ADC.Out.BatSysStateFault = ON;
		}
		else
		{
			BatSysFaultOnCnt ++;
		}

        BatSysFaultOffCnt = 0u;
	}
    else if(( ADC.Int.BatteryVoltAD >= cSysBatValue_Low_Rst_AD ) &&
    ( ADC.Int.BatteryVoltAD <= cSysBatValue_High_Rst_AD ))
	{
		if(BatSysFaultOffCnt >= cFilteringTime)
		{

			ADC.Out.BatSysStateFault = OFF;
		}
		else
		{
			BatSysFaultOffCnt ++;
		}
		BatSysFaultOnCnt = 0u;
	}
    else    // don't care구간에서 카운트 초기화
    {
        BatSysFaultOnCnt = 0u;
        BatSysFaultOffCnt = 0u;
    }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static	void ss_ADC_CanVoltageCtrl(void)
{
    static  uint16_t    BatCanFaultOnCnt = 0u;
    static  uint16_t    BatCanFaultOffCnt = 0u;

    if(( ADC.Int.BatteryVoltAD < cCanBatValue_Low_Set_AD ) ||
    ( ADC.Int.BatteryVoltAD > cCanBatValue_High_Set_AD ))
	{
		if(BatCanFaultOnCnt >= cFilteringTime)	// 30ms chattering
		{
			ADC.Out.BatCanStateFault = ON;
		}
		else
		{
			BatCanFaultOnCnt ++;
		}

        BatCanFaultOffCnt = 0u;
	}
    else if(( ADC.Int.BatteryVoltAD >= cCanBatValue_Low_Rst_AD ) &&
    ( ADC.Int.BatteryVoltAD <= cCanBatValue_High_Rst_AD ))
	{
		if(BatCanFaultOffCnt >= cFilteringTime)
		{
			ADC.Out.BatCanStateFault = OFF;
		}
		else
		{
			BatCanFaultOffCnt ++;
		}
		BatCanFaultOnCnt = 0u;
	}
    else    // don't care구간에서 카운트 초기화
    {
        BatCanFaultOnCnt = 0u;
        BatCanFaultOffCnt = 0u;
    }
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_ADC_IG1SwRead(void)
{
    static uint16_t    	Ig1OnCnt = 0u;
    static uint16_t    	Ig1OffCnt = 0u;
	static uint8_t 		Ig1InitFlag = OFF;

	// 최초 전원 리셋시에는 채터링 타임 없이 최초 read한 값으로 즉시 IGN on/off 판단 처리
	if(Ig1InitFlag == OFF)
	{
		Ig1InitFlag = ON;
		
		if(ADC.Int.IGN1VoltAD >= cIGN1On)
		{	
			ADC.Out.IGN1_IN = ON;
		}
		else if(ADC.Int.IGN1VoltAD <= cIGNOff)
		{
			ADC.Out.IGN1_IN = OFF;
		}
		else
		{
			// QAC
		}
	}
	

	if(ADC.Int.IGN1VoltAD >= cIGN1On)
	{
		if(Ig1OnCnt >= cFilteringTime)	// 30ms chattering
		{
			ADC.Out.IGN1_IN = ON;
		}
		else
		{
			Ig1OnCnt ++;
		}

        Ig1OffCnt = 0u;
	}
	else if(ADC.Int.IGN1VoltAD <= cIGNOff)
	{
		if(Ig1OffCnt >= cFilteringTime)
		{
			ADC.Out.IGN1_IN = OFF;
		}
		else
		{
			Ig1OffCnt ++;
		}
		Ig1OnCnt = 0u;
	}
    else    // don't care구간에서 카운트 초기화
    {
        Ig1OnCnt = 0u;
        Ig1OffCnt = 0u;
    }

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_ADC_PDC_LowVoltageCtrl(void)
{
    static uint16_t    	LowVoltOnCnt = 0u;
	static uint8_t 		LowVoltInitFlag = OFF;

	// 최초 전원 리셋시에는 채터링 타임 없이 최초 read한 값으로 즉시 IGN on/off 판단 처리
	if(LowVoltInitFlag == OFF)
	{
		LowVoltInitFlag = ON;
		
		if(ADC.Int.BatteryVoltAD <= cBAT_LOW_9V_AD)
		{	
			ADC.Out.PDC_LOW_BAT = ON;
		}
		else
		{
			ADC.Out.PDC_LOW_BAT = OFF;
		}
	}
	
	if(ADC.Int.BatteryVoltAD <= cBAT_LOW_9V_AD)
	{
		if(LowVoltOnCnt >= cFilteringTime)	// 30ms chattering
		{
			ADC.Out.PDC_LOW_BAT = ON;
		}
		else
		{
			LowVoltOnCnt ++;
		}
	}
    else
    {
		ADC.Out.PDC_LOW_BAT = OFF;
		
        LowVoltOnCnt = 0u;
    }	
}
/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
static void ss_ADC_RteWrite(void)
{
	// ADC.Out.IGN1_IN = ADC.Out.IGN1_IN;
	// ADC.Out.BatCanStateFault = ADC.Out.BatCanStateFault;
	// ADC.Out.BatSysStateFault = ADC.Out.BatSysStateFault;
	// ADC.Out.PDC_LOW_BAT = ADC.Out.PDC_LOW_BAT;

	// Uds 모듈에서 1바이트로 변경해서 진단기로 보내므로 여기서 미리 변환해서 Rte 1바이트로 전달함.

	// range : 0 ~ 20000mV) : mv -->v로 변환
	// Data[7] = (uint8_t)(((Uds.Inp_WCT_u16.BATVolt /1000u) * 100u) / 8u);// GN7.0F_06
	ADC.Out.BATVolt_Convert = (uint8_t)((ADC.Int.BATVolt / 10u) / 8u); // 연산량 감소 처리 적용 (소수점 사용하지 않기 위해서)

	// Data[8] = (uint8_t)(Uds.Inp_WCT_u16.IGN1Volt * 0.08);     // 사양서에는 전압이나 실제는 ign on/off 로 표시. 진단 사양서 수정 필요
	// Data[8] = (uint8_t)(Uds.Inp_ADC.IGN1_IN);  // ON/OFF

	// range : 0 ~ 20000mV) : mv -->v로 변환
	// Data[8] = (uint8_t)(((Uds.Inp_WCT_u16.IGN1Volt / 1000u) * 100u) / 8u);	// GN7.0F_06 // 사양서 대로 on/off가 아닌 전압으로 일단 표출함.
	ADC.Out.IGN1Volt_Convert = (uint8_t)((ADC.Int.IGN1Volt / 10u) / 8u);	// GN7.0F_06 // 연산량 감소 처리 적용 (소수점 사용하지 않기 위해서)
// 사양서

	Rte_Write_P_ADC_ADC_STR(&ADC.Out);	// 구조체로 한꺼번에 전송

}



/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_ADC_L2H_Set(void)
{

	ADC.Int.Runnable_State = 0u; // wakeup시 State를 처음부터 다시 시작하기 위해서 초기화 함

	Rte_Call_R_VBAT_CTRL_WriteDirect(ON); // VBAT 스트로브 ON // high active
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
***************************************************************************************************/
void    gs_ADC_H2L_Set(void)
{
	Rte_Call_R_VBAT_CTRL_WriteDirect(OFF);	// VBAT 스트로브 OFF // high active


}

#define App_ADC_STOP_SEC_CODE
#include "App_ADC_MemMap.h"
