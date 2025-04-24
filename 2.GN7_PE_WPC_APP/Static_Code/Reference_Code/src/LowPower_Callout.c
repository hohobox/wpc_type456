/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuInfo.h"

#include "App_ADC.h"
#include "App_CAN_RX.h"
#include "App_CAN_TX.h"
#include "App_NvM.h"
#include "App_PWM.h"
#include "App_Repro.h"
#include "App_UART.h"
#include "App_NFC.h"
#include "App_WCT.h"
#include "App_WDT.h"
#include "App_DTC.h"
#include "App_Uds.h"


#include "LowPower_Callout.h"
#include "Rte_IoHwAb.h"
#include "IoHwAb_IOManager.h"
//#include "CryptoLib_Cfg.h"

//#if (CRYPTOLIB_SUPORT_HSM_HAE_HSM_2_X == STD_ON)
#include "Hsm_HostAPI.h"
#include "Hsm_HostAPI_Traveo2.h"
#include "Os.h"
//#endif

#include "WdgStack_Callout.h"
#include "WdgM.h"
#include "Gpt.h"
#include "Os_Debug.h"

#include "cyt2bl4cas.h"
#include "cy_evtgen.h"
#include "Nml_Integration.h" /* WPC_2410_05 */

#define RTE_ALLOW_CROSS_HEADER_INCLUSION  // 미선언시 컴파일 오류 발생함.
//#include "Rte_IoHwAb.h"



#define cWDT_DeepWakeupTime     40000u // 40ms // wdt 주기 50ms로 변경, // 전원 리셋 전에는 20ms 주기로 설정되고 리셋 후 40ms 로 설정됨.

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define ECUM_SYST_CSR_ENABLE_MASK 0x00000001u
#define ECUM_SCR_SLEEPDEEP_MASK 0x00000004u
/* polyspace-begin MISRA-C3:11.4 [Justified:Low] "It is for accessing register address" */
/* polyspace-begin MISRA-C3:20.7 [Jusitifed:Low] "To access Register address" */

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
/* IPC STURCT2 INTR Register Information */
#define ECUM_IPC_STRUCUT2_INTR_SET_REG       (*(volatile uint32*)0x40221044u)
#define ECUM_IPC_STRUCUT2_INTR_MASK_REG      (*(volatile uint32*)0x40221048u)
#endif

CONSTP2VAR(volatile Mcu_Cm4ScsRegType, AUTOMATIC, REGSPACE) EcuM_Cm4ScsRegBaseAddr =
                                    (volatile Mcu_Cm4ScsRegType *)MCU_SYSTEM_CM4_SCS_REG_BASE_ADDR;
/* polyspace-end MISRA-C3:11.4 [Justified:Low] "It is for accessing register address" */
/* polyspace-end MISRA-C3:20.7 [Jusitifed:Low] "To access Register address" */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"

static void ss_EVTGEN_Deactive(void);
static void ss_EVTGEN_InitSet(void);
static void ss_Icu_Enable_IGN1(void);
static void ss_Icu_Enable_BCAN_RX(void);
static void ss_Icu_Enable_LCAN_RX(void);
static void ss_Icu_Disable_IGN1(void);
static void ss_Icu_Disable_BCAN_RX(void);
static void ss_Icu_Disable_LCAN_RX(void);

static void ss_HSM_WakeupSet_Sleep(void);
/* WPC_1905_02 Start */
// static uint8_t User_SysClk_HfClockSetSource(uint8_t hfClk, uint32_t source);
// static uint8_t User_SysClk_HfClkEnable(uint8_t hfClk);
// static uint8_t User_SysClk_HfClkDisable(uint8_t hfClk);
// ss_EVTGEN_InitSet()이 함수를 callout으로 호출하면 중간에 리셋되지않음.
// gs_EVTGEN_Active() 이 함수를 callout으로 호출하면 금방 리셋 발생함.
// 아래 변수가 static으로 선언되지 않아서 설정값들이 유지가 되지 않아서 발생한 현상임.
// static으로 선언하면 설정값들이 유지가 되므로 gs_EVTGEN_Active()로

static cy_stc_evtgen_struct_context_t evtgenStruct0Context;
static cy_stc_evtgen_struct_config_t evtgenStructureConfig;
static cy_stc_evtgen_config_t evtgenConfig;


/***************************************************************************************************
@param[in]  void
@return     void
@note
*//*
EvtGen Active function
***************************************************************************************************/
void gs_EVTGEN_Active(void)
{
	//uint64_t	currentCounterValue;
	//uint32_t	saveCountValue;

    Cy_Evtgen_ClearStructInterrupt(EVTGEN0,0);

	// 한원진 수석이 최근에 다시 샘플 코드 주면서 개선된 내용이라고 보내준 코드임.
	// 이렇게 하면 evtgen에 의해서 wakeup되어 동작하는 시간을 계산해서 이시간만큼을 이벤트 발생 카운터에 추가해준다.
	// 이렇게 하면 이벤트 발생후 어떤 문제에 의해서 다음 이벤트 주기보다 긴시간 동안 부하가 걸려서 이벤트가 발생하지 못하게 될 경우에도
	// 이벤트 카운터를 재 설정하므로 이벤트는 반드시 발생하게 된다.
	// 하지만 wpc의 경우에는 wdt pulse 용이므로 이벤트 발생 주기가 늘어지면 안되므로 미적용한다.
#if 0

	//
    currentCounterValue = (uint64_t)Cy_Evtgen_GetCounterValue(EVTGEN0);
    /* calculate next compare value of event generator */
    saveCountValue = (uint32_t)(currentCounterValue + (uint64_t)evtgenStructureConfig.valueDeepSleepComparator);
    /* set next compare value of event generator */
    Cy_Evtgen_SetValueComp(EVTGEN0, 0,saveCountValue);

#else
    Cy_Evtgen_DeinitializeCompStruct(EVTGEN0,0);
    Cy_Evtgen_InitializeCompStruct(EVTGEN0,0, &evtgenStructureConfig, &evtgenStruct0Context);// 초기화와 시작 트리거 분리하기 위해서 여기서 초기값 설정함
#endif

}

/***************************************************************************************************
@param[in]  void
@return     void
@note
*//*
EvtGen Deactive function
***************************************************************************************************/
static void ss_EVTGEN_Deactive(void)
{

    // User_SysClk_HfClkDisable(1u);	// CY_SYSCLK_HFCLK_1 = 1
    // User_SysClk_HfClockSetSource(1u, 0u); // CY_SYSCLK_HFCLK_1 = 1, CY_SYSCLK_HFCLK_IN_CLKPATH0 = 0

    Cy_Evtgen_ClearStructInterrupt(EVTGEN0,0);
    Cy_Evtgen_DeinitializeCompStruct(EVTGEN0,0);
	Cy_Evtgen_Deinitialize(EVTGEN0); // 호출하지 않으면 counter는 계속 증가한다.
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
*//*
EvtGen Init Set function
***************************************************************************************************/
static void ss_EVTGEN_InitSet(void) // WPC_3F_02
{

    /*******************************************/
    /*        Deinitialize peripherals         */
    /*******************************************/
    Cy_Evtgen_DeinitializeCompStruct(EVTGEN0,0);
    Cy_Evtgen_Deinitialize(EVTGEN0);

    /*******************************************/
    /*  Interrupt setting for Event Generator  */
    /*******************************************/
    // swp 에서 설정됨

    /*********************/
    /*  Enable clk_hf1   */
    /*********************/
    // swp에서 설정됨


    /*******************************************/
    /*  Initialize and start Event generator   */
    /*******************************************/
	// LPActive 에 IMO 적용하면서 T32연결시에만 evtgen 인터벌이 2배로 늘어지는 현상 발생
	// 그로 인해서 T32 연결하면 wdt reset 걸리는 현상 발생
	// T32연결하지 않으면 정상적인 인터벌 발생함. 그러므로 실제 문제는 되지 않음
	// 그러나 디버그 연결시에도 정상 인터벌 발생하기 위해서 한원진 수석에게 문의하여 아래와 같이 변경함.
	// 이유는 T32를 미연결하면 Deepsleep에서는 evtgenConfig.frequencyLf = 32000; 로 동작하므로 설정 주기로 evtgen이 발생한다.
	// 그러나 T32를 연결하면 Deepsleep에 진입하지 못하고  evtgenConfig.frequencyRef = 8000000; 로 동작한다.
	// 그러나 mcal 설정이 LPActive에서 정상적으로 설정되지 않은 상태이므로 evtget이 설정 주기로 동작하지 않아서 발생한 문제이다.
	// 한원진 수석의 도움을 받아서 LPActive Ecud_Ecu.arxml의 설정을 변경하고
	// 여기 클럭을 4Mhz 로 변경한 후 T32 연결시에도 설정한 주기로 evtgen이 동작함.
	evtgenConfig.frequencyRef = 4000000; //  clk_ref = clk_hf1 = CLK_PATH2 (IMO) -> 8,000,000 for silicon
	//evtgenConfig.frequencyRef = 8000000; //  clk_ref = clk_hf1 = CLK_PATH2 (IMO) -> 8,000,000 for silicon
	evtgenConfig.frequencyLf = 32000; 		// clk_lf = 32,000 for silicon

	evtgenConfig.frequencyTick = 1000000; // Setting 1,000,000 Hz for event generator clock (clk_ref_div)
	evtgenConfig.ratioControlMode = CY_EVTGEN_RATIO_CONTROL_SW;
	evtgenConfig.ratioValueDynamicMode = CY_EVTGEN_RATIO_DYNAMIC_MODE0;
	Cy_Evtgen_Initialize(EVTGEN0,&evtgenConfig); // WPC_7A_01 // 초기화와 시작 트리거 분리하기 위해서 주석 처리함

	/*******************************************/
	/*	Initialize comparator structure 0 	   */
	/*******************************************/
	evtgenStructureConfig.functionalitySelection = CY_EVTGEN_DEEPSLEEP_FUNCTIONALITY;
	evtgenStructureConfig.triggerOutEdge = CY_EVTGEN_EDGE_SENSITIVE;
	evtgenStructureConfig.valueDeepSleepComparator = cWDT_DeepWakeupTime; // In active functionality, this value is used for making period of interrupts/triggers
	  														                                          // ex : 1,000,000 / 1,000,000 (clk_ref_div) = 1[s]
	evtgenStructureConfig.valueActiveComparator = 0;                      // In active functionality, this value is used for making period of interrupts/triggers
	  														                                          // 1,000,000 / 1,000,000 (clk_ref_div) = 1[s]

    /* Put the system to DeeSleep */
}

/*******************************************************************************
 * Function Name        : EcuM_H2LTransition_Callout_Swp
 *
 * Service ID           : NA
 *
 * Description          : Callout for SWP in Sleep Sequence
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        WdgStack_TransitHighToLow()
 *                        IoHwAb_IOMH2L(), Os_DebugH2L(), Gpt_SetMode()
 ******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_H2LTransition_Callout_Swp(void)
{
    SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

    /* Stop OS Counter for Main Core */
    EcuM_Cm4ScsRegBaseAddr->SYST_CSR &= ~ECUM_SYST_CSR_ENABLE_MASK;

    SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();

    #if (IOHWAB_USE_IO_MAN == STD_ON)
    IoHwAb_IOMH2L();
    #endif
    Os_DebugH2L();

    // WPC_7D_03
    // sleep 진입시 호출
    // 내부 wdt disable 처리됨.
    // wakeup시 다시 호출여 내부 wdt start 해야함.
    WdgM_PmModeChange(WDGM_PM_MODE_LP_REQ); // WPC_37_06

    WdgStack_TransitHighToLow();
    /* All Gpt channels that are not enabled for wakeup and
     * all enabled GPT Predef Timers are stopped. */
    Gpt_SetMode(GPT_MODE_SLEEP);
}

/*******************************************************************************
 * Function Name        : EcuM_H2LTransition_Callout_App
 *
 * Service ID           : NA
 *
 * Description          : User Callout for Sleep Sequence
 *                        The application should take the necessary action here
 *                        before switching to Low Power Mode
 *                        - Disable unnecessary peripherals in Low Power Mode
 *                        - Enable Wakeup sources(ex: Icu channel, Gpt channel)
 *                        - Check early wakeup
 *                        - Apply workaround for MCU Errata
 *                        - etc
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Icu_EnableEdgeDetection(), Icu_EnableNotification(),
 *                        Icu_DisableEdgeDetection(), Icu_DisableNotification(),
 *                        IoHwAb_DigDirReadDirect(), EcuM_SetWakeupEvent(),
 *                        SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION()
 ******************************************************************************/

//  Rte_Call_R_staterequest_RequestSleep(APP_MODE_USER); 호출 후 여기가 call 됨.
FUNC(void, ECUM_CALLOUT_CODE) EcuM_H2LTransition_Callout_App(void)
{
    uint8_t WpcTypeOption;
    
    IoHwAb_LevelType LddLevel;
    EcuM_WakeupSourceType LddWakeupMask;

    uint8_t mbIgn1State = 0;
    uint8_t NfcOption = OFF;

    SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();
    LddWakeupMask = ECUM_WKSOURCE_NONE;

  	/* WPC_2410_05 Start */
    // RS4_PE_WPC_APP_Patch_v2.1.9.zip 적용으로 주석처리함.
    // NML 2.1.1 에서 미사용으로 주석 해야 했음. 그러나 휴먼 에러로 놓침.
    // 놓친 이유는 nml 2.1.1 모듈에는 Nml_NvM_WriteBlock()함수가 존재해서 컴파일 에러가 발생하지는 않아서 휴먼에러로 놓침.)
    // NML2.2.0 적용시 컴파일 에러 발생함.(nml 모듈에서 Nml_NvM_WriteBlock()가 삭제되어 컴파일시 에러가 발생하여 발견함) 
    
  	//Nml_NvM_WriteBlock(); 
  	/* WPC_2410_05 End */
    
    NfcOption = gs_Get_NvM_NfcOption(); /* 010D_02 */
  
	ss_Icu_Enable_IGN1(); 	    // IGN Wakeup Enable
	ss_Icu_Enable_BCAN_RX(); 	// BCAN Wakeup Enable

/* 010D_02 */
    if(NfcOption == ON)
    {
        ss_Icu_Enable_LCAN_RX(); 	// LCAN Wakeup Enable    
    }
    else
    {
        ss_Icu_Disable_LCAN_RX(); 	// LCAN Wakeup Disable
    }
/* 010D_02 */    

  	/*****************************************************************************
   	* Check that the pin level has already changed before ICU Edge Detection is
   	* enabled
   	****************************************************************************/
  	// 아래 처리 이유
  	// 슬립 진입 직전에 BCAN, LCAN rx단을 확인해서 Rx 단이 low이면 통신이 발생한것이므로
  	// 슬립 진입하지 않고 즉시 wakeup source에 wakeup 발생 요청을 하는것임.
  	// IGN 신호도 마찬가지임. ign on이면 wakeup 발생 요청을 함.


    /* IGN1 State Read */
    mbIgn1State = gs_Get_ADC_IGN1_IN();
    if (mbIgn1State == ON)
    {
        LddWakeupMask |= ECUM_WKSOURCE_IGN1;
    }

    IoHwAb_DigDirReadDirect((uint16)BCAN_RX, &LddLevel);
    if (LddLevel == (IoHwAb_LevelType)IOHWAB_LOW)
    {
        LddWakeupMask |= ECUM_WKSOURCE_BCAN_RX_POLL;
    }
/* 010D_02 */
    if(NfcOption == ON)
    {    
        IoHwAb_DigDirReadDirect((uint16)LCAN_RX, &LddLevel);
        if (LddLevel == (IoHwAb_LevelType)IOHWAB_LOW)
        {
            LddWakeupMask |= ECUM_WKSOURCE_LCAN_RX_POLL;
        }
    }
/* 010D_02 */

    SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();

    if (LddWakeupMask != ECUM_WKSOURCE_NONE)
    {
    	/* Disable all Wakeup Signals */
		ss_Icu_Disable_IGN1();
		ss_Icu_Disable_BCAN_RX();
		ss_Icu_Disable_LCAN_RX();
    }


    if ((LddWakeupMask & ECUM_WKSOURCE_IGN1) == ECUM_WKSOURCE_IGN1)
    {
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_IGN1);
    }

    if ((LddWakeupMask & ECUM_WKSOURCE_BCAN_RX_POLL) == ECUM_WKSOURCE_BCAN_RX_POLL)
    {
        /* Do not execute in interrupt disabled region */
        EcuM_SetWakeupEvent(ECUM_WKSOURCE_BCAN_RX_POLL);
    }

/* 010D_02 */    
    if(NfcOption == ON)
    {      
        if ((LddWakeupMask & ECUM_WKSOURCE_LCAN_RX_POLL) == ECUM_WKSOURCE_LCAN_RX_POLL)
        {
            /* Do not execute in interrupt disabled region */
            EcuM_SetWakeupEvent(ECUM_WKSOURCE_LCAN_RX_POLL);
        }
    }
/* 010D_02 */

	// sleep 진입 전에 위의 조건에서 sleep 못하고 wakeup 조건이 되면 아래 코드를
	// 처리하면 안되는것 아닌가? 검토 필요.
	// 실행해도 다시 wakeup되기는 한다.
	// --> 일단 양산(GN7/CE1)에서 문제 없으므로 기존과 동일하게 적용함.

	// WDT  disable 로 포트 설정됨.
	// Sleep 상태 포트로 All 초기화 처리
	// CanTrcv 모듈에서 EN/STB 포트 설정 된 다음 여기 호출된다.
	// 그러므로 포트 설정을 Port_Init()에서 EN=LOW, STB=LOW로 설정해야함.

  	// Application Port DeInit
  	// 해당 어플리케이션 포트 Sleep에 맞도록 Low지정후 Port_Init() 하는게 맞음.
  	// gs_Mdw_Io_H2L_Set();

  	gs_ADC_H2L_Set();
  	gs_CAN_RX_H2L_Set();
  	gs_CAN_TX_H2L_Set();
  	gs_NvM_H2L_Set();
  	gs_PWM_H2L_Set();
  	
  	gs_App_WDT_H2L_Set();
	gs_App_DTC_H2L_Set();
  	gs_App_Uds_H2L_Set();
	gs_App_NFC_H2L_Set();
  	gs_App_Repro_H2L_Set();
  	gs_App_UART_H2L_Set();
  	gs_App_WCT_H2L_Set();

    WpcTypeOption = gs_Get_NvM_WpcType();
     
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
    if((WpcTypeOption == cWPC_TYPE5) || /* only dual */
    (WpcTypeOption == cWPC_TYPE6))
    {
  	    // Sleep 용으로 설정된 포트 설정으로 재 지정.
  	    Port_Init(&PortConf_PortConfigSet_PortConfigSet_1_Dual_deepsleep); // lcan / bcan 이외 All port 미사용 처리. 소비전류 감소, WDT Disable 처리적용됨
    }
//#elif defined(WPC_TYPE4)	// Single
    else
    {
	    Port_Init(&PortConf_PortConfigSet_PortConfigSet_3_Single_deepsleep); // lcan / bcan 이외 All port 미사용 처리. 소비전류 감소, WDT Disable 처리적용됨
    }
//#else
//   error : wpc type is not defined	
//#endif	

	ss_HSM_WakeupSet_Sleep(); // HSM Interrupt Wakeup Set and Sleep

  	// Deep Sleep 중 40ms 주기로 Stobe 처리되도록 EveGen 기능 Active 시킴
  	ss_EVTGEN_InitSet();

	Mcu_InitClock(1u); // ECO (20Mhz) --> IMO (8Mhz)변환

  	gs_EVTGEN_Active();

	// 여기서 다시 WDT Enable 처리 적용됨.
	// 그러므로 Port_Init() 호출후 어느정도 WDT En단 High가 유지 되도록
	// Port_Init() 과 IoHwAb_DigDirWriteDirect() 사이에
	// ss_HSM_WakeupSet_Sleep(),ss_EVTGEN_InitSet(),Mcu_InitClock(1u), gs_EVTGEN_Active()를 호출하도록한다.
	// 이렇게 하면 약 7ms 정도 high 가 유지 된다.
	// 이정도 유지 되야 엣지가 인식된다.
	// Port_Init(), IoHwAb_DigDirWriteDirect()를 나란히 호출하면
	// high 유지 기간이 너무 짧아서 엣지 인식이 안되서
	// 리셋이 발생한다.
#if !defined (DEBUG_EXT_WDT_NOT_USE)
	// 디버그 위해서 일단 sleep에선 펄스만 나오게 하려면 아래를 주석처리
  	IoHwAb_DigDirWriteDirect(Rte_PDAV_IoHwAbP_WDT_EN_1, ON); // WDT Enable (low), low active port
#endif
}

/*******************************************************************************
 * ISR Name             : EcuMIsr_Wakeup_CM7_1
 *
 * Service ID           : NA
 *
 * Description          : ISR to wakeup M7_1 Core
 *                        (It is generated in M7_1 Core)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : None
 *
 * @pre                 : None
 *
 * @remarks             : None
 *
 ******************************************************************************/
#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
ISR(EcuMIsr_Wakeup_CM7_1)
{
  ECUM_IPC_STRUCUT2_INTR_MASK_REG = 0u;
  ECUM_IPC_STRUCUT2_INTR_SET_REG = 0u;
}
#endif
/*******************************************************************************
 * Function Name        : EcuM_L2HTransition_Callout_Swp
 *
 * Service ID           : NA
 *
 * Description          : Callout for SWP in Wakeup Sequence
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        WdgStack_TransitLowToHigh(), WdgM_PmModeChange(),
 *                        SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        IoHwAb_IOML2H(), Gpt_SetMode()
 ******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_L2HTransition_Callout_Swp(void)
{
    #if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
    /* Wakeup for M0+ should be considered */

    /* Wakeup M7_1 Core */
    ECUM_IPC_STRUCUT2_INTR_SET_REG = 1u;
    ECUM_IPC_STRUCUT2_INTR_MASK_REG = 1u;

    #endif

  /* All channels and all enabled GPT Predef Timers are permitted to run.
   * Restart all enabled GPT Predef Timers
   * but does not restart any timer channels that were stopped */
    Gpt_SetMode(GPT_MODE_NORMAL);

    #if (IOHWAB_USE_IO_MAN == STD_ON)
    IoHwAb_IOML2H();
    #endif

    WdgStack_TransitLowToHigh();

  	// WPC_7D_03
  	// sleep 진입시 호출
  	// 내부 wdt disable 처리됨.
  	// wakeup시 다시 호출여 내부 wdt start 해야함.
  	/* Restart Wdg trigger */ // 정확히는 이전 모드로 복귀
  	// WdgStack_TransitLowToHigh() 호출시 자동으로 WdgM_PmModeChange(WDGM_PM_MODE_HP_REQ); 호출되고 있으나
  	// 강건화 차원에서 다시 호출한다.
  	WdgM_PmModeChange(WDGM_PM_MODE_HP_REQ);

    SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

    /* Resume OS Counter for Main Core */
    EcuM_Cm4ScsRegBaseAddr->SYST_CSR |= ECUM_SYST_CSR_ENABLE_MASK;
    /* Clear SLEEPDEEP bit from System Control Register in Core */
    EcuM_Cm4ScsRegBaseAddr->SCR &= ~ECUM_SCR_SLEEPDEEP_MASK;

    SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();
}

/*******************************************************************************
 * Function Name        : EcuM_L2HTransition_Callout_App
 *
 * Service ID           : NA
 *
 * Description          : User Callout for Wakeup Sequence
 *                        The application should take the necessary action here
 *                        before switching to RUN Mode
 *                        - Enable necessary peripherals in High Power Mode
 *                        - Disable Wakeup sources(ex: Icu channel, Gpt channel)
 *                        - Apply workaround for MCU Errata
 *                        - etc
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Lp_GaaAdcStatus, Lp_GulPitStatus, Lp_GaaStm0Status,
 *                        Lp_GaaStm2Status
 *
 *                        Function(s) invoked    :
 *                        Icu_DisableEdgeDetection(), Icu_DisableNotification(),
 *                        SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION(),
 *                        SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION()
 ******************************************************************************/
// ECU Sleep에서 Wakeup 후 여기가 call 됨.
FUNC(void, ECUM_CALLOUT_CODE) EcuM_L2HTransition_Callout_App(void)
{
    uint8_t WpcTypeOption;
    
  	// wdt enable/disable 여부 무관하게 pulse는 출력되도록 변경.
  	ss_EVTGEN_Deactive(); // WPC_85_02 // WPC_3F_02

	Mcu_InitClock(ECUM_MCU_NORMAL_CLOCK); // IMO (8Mhz) --> ECO (20Mhz) 변환


  	IoHwAb_DigDirWriteDirect(Rte_PDAV_IoHwAbP_WDT_EN_1, OFF); // WDT Disable (high), low active port

  	// WDT  disable 로 포트 설정됨.
 	// Normal 상태 포트로 All 초기화 처리
 	// 이때 Bcan, Lcan도 En단 및 STB 단 low 출력으로 되어있어서
 	// CanTrcv 모듈에 의해서 En = High, STB = High가 포트 초기화로 모두 low가 된다.
 	// 그러므로 여기서 다시 high 처리 해줘야 함.
 	// H/W 나오면 테스트 해보자.
 	// 아니면 포트 normal 초기값을 high로 처리하는 방법도 검토해보자. (변경전 CAN IC가 이방법임. low 가 active 이므로. 이전에는 low 출력 이였음)

 	// 여기가 먼저 호출되서 포트 초기화 된 다음
 	// CanTrcv 모듈에서 EN/STB 포트 설정 된다.
 	// 여기서 포트 초기한 값은 다시 변경된다.
 	// 그래도 Normal 의 값인 EN = High, STB = High 로 포트 초기값 설정하자.
    
    WpcTypeOption = gs_Get_NvM_WpcType();
     
//#if defined(WPC_TYPE5) || defined(WPC_TYPE6)   /* only dual */
    if((WpcTypeOption == cWPC_TYPE5) || /* only dual */
    (WpcTypeOption == cWPC_TYPE6))
    {
  	    Port_Init(&PortConf_PortConfigSet_PortConfigSet_0_Dual_Active);// Dual 포트 설정, 단 LCAN 포트는 사용으로 설정 (Non NFC는 LCAN IC 미실장 및 wakeup Disable 설정으로 대응)
//#elif defined(WPC_TYPE4)	// Single
    }
    else
    {
	// 여기에는 플랫폼 port 설정을 single용으로 다시 만들어서 그 포트로 초기화를 하도록 추가해야한다.
	// 단 플랫폼 자체에서 맨 처음 전원 리셋시에는 자동으로 gen된 코드의 동작대로 dual 포트로 초기화하도록 하고 
	// 그 다음 여기 로직에서 wpc type에 따라서 single 또는 dual 로 다시 포트 초기화를 하자.
	// 이렇게 하면 하나의 플랫폼으로 single / dual 모두 사용 가능하다.
	    Port_Init(&PortConf_PortConfigSet_PortConfigSet_2_Single_Active);// Single 포트 설정, 단 LCAN 포트는 사용으로 설정 (Non NFC는 LCAN IC 미실장 및 wakeup Disable 설정으로 대응)
    }
//#else
//   error : wpc type is not defined	
//#endif	

  	// wakeup 인터럽트를 모두 disable 시킨다.

    SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

  	/* Disable all Wakeup Signals */
  	ss_Icu_Disable_IGN1();
	ss_Icu_Disable_BCAN_RX();
	ss_Icu_Disable_LCAN_RX(); // nfc/non-nfc 구분없이 항상 disable 처리 적용

    SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();

  	gs_ADC_L2H_Set();
  	gs_CAN_RX_L2H_Set();
  	gs_CAN_TX_L2H_Set();
  	gs_NvM_L2H_Set();
  	gs_PWM_L2H_Set();
	
	gs_App_DTC_L2H_Set();
  	gs_App_Uds_L2H_Set();
  	gs_App_WDT_L2H_Set();
  	gs_App_NFC_L2H_Set();
  	gs_App_Repro_L2H_Set();
  	gs_App_UART_L2H_Set();
  	gs_App_WCT_L2H_Set();


	/* HSM Enable */
  	if(HSM_IsSleepStatus() == TRUE) // HSM Core가 아직 Deepsleep 상태일 경우 다시 한번 강제로 Wakeup 호출
  	{
    	HSM_Wakeup();	/* WPC_1900 */ /* HSM Wake-up Trigger로 깨우는 로직이 있지만 만약을 위해 강건화 차원으로 넣어둠 */
  	}
	
  	HSM_ClearWakeupTrigger(); // wakeup 조건 제거하여 비활성화

}

/*******************************************************************************
 * Function Name        : EcuM_Boot_Callout
 *
 * Service ID           : NA
 *
 * Description          : User Callout for Before SWP Start
 *                        If MCU wakes up in Low Power Mode and operates as a
 *                        reset sequence. This callout can be used to identify
 *                        the wakeup and implement the required behavior.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : Interrupt cannot be used because it is before StartOS
 *                        Can not use SWP and MCAL API
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_Boot_Callout(void)
{
  /* Example: Check Wakeup Factor and action
   * If <Wakeup Factor == External Wakeup>
   * {
   *   <Necessary Functionality Initialize>
   *   <User Action>
   *   <Enter LP Again or Proceed to SWP Init>
   * }
   */
}

/***************************************************************************************************
@param[in]  void
@return     void
@note		P8.2 ioss_interrupts_gpio_8_IRQn
*//*
IGN Wakeup ISR Function (모빌젠 MCAL ICU signal Notificaiton에서 생성한 함수 이름)
***************************************************************************************************/
void IcuChannel_IGN1_Cbk(void)
{
  	// wakeup 된 인터럽트만 disable 시킨다. 나머지는 EcuM_L2HTransition_Callout_App() 호출되면 다시 한번 모두 disable 시킨다.

  	SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

	ss_Icu_Disable_IGN1();

  	/* Wakeup Sequence */
  	EcuM_SetWakeupEvent(ECUM_WKSOURCE_IGN1);

  	SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();
}


/***************************************************************************************************
@param[in]  void
@return     void
@note 		P6.3 ioss_interrupts_gpio_6_IRQn
*//*
BCAN RX  Wakeup ISR Function (모빌젠 MCAL ICU signal Notificaiton에서 생성한 함수 이름)
***************************************************************************************************/
void IcuChannel_BCAN_RX_Cbk(void)
{
  	// wakeup 된 인터럽트만 disable 시킨다. 나머지는 EcuM_L2HTransition_Callout_App() 호출되면 다시 한번 모두 disable 시킨다.

  	SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

  	ss_Icu_Disable_BCAN_RX();

  	/* Wakeup Sequence */
  	EcuM_SetWakeupEvent(ECUM_WKSOURCE_BCAN_RX);

  	SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();
}


/***************************************************************************************************
@param[in]  void
@return     void
@note 		P19.1 ioss_interrupts_gpio_19_IRQn
*//*
LCAN RX  Wakeup ISR Function (모빌젠 MCAL ICU signal Notificaiton에서 생성한 함수 이름)
***************************************************************************************************/
void IcuChannel_LCAN_RX_Cbk(void)
{

  	// wakeup 된 인터럽트만 disable 시킨다. 나머지는 EcuM_L2HTransition_Callout_App() 호출되면 다시 한번 모두 disable 시킨다.

  	SchM_Enter_EcuM_WAKEUP_STATUS_PROTECTION();

  	ss_Icu_Disable_LCAN_RX();

  	/* Wakeup Sequence */
  	EcuM_SetWakeupEvent(ECUM_WKSOURCE_LCAN_RX);

  	SchM_Exit_EcuM_WAKEUP_STATUS_PROTECTION();
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
*//*
EvtGen ISR function
***************************************************************************************************/
void ISR_Evtgen_Deepsleep_Isr_Vector_18_Cat2(void) // WPC_3F_02
{
#if 0 // 한원진 수석한테 최근 evtgen 샘플 코드 받을때 이 코드를 적용하는 것을 추천 받음
	while(Cy_Evtgen_GetCounterStatus(EVTGEN0) == CY_EVTGEN_COUNTER_STATUS_INVALID);
#endif
  	Cy_Evtgen_ClearStructInterruptDeepSleep(EVTGEN0,0);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
*/
/*

***************************************************************************************************/
static void ss_Icu_Enable_IGN1(void)
{
  	// IGN Wakeup Enable
    Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_IGN1);
    Icu_EnableNotification(IcuConf_IcuChannel_IcuChannel_IGN1);
}

static void ss_Icu_Enable_BCAN_RX(void)
{
  	// BCAN Wakeup Enable
    Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_BCAN_RX);
    Icu_EnableNotification(IcuConf_IcuChannel_IcuChannel_BCAN_RX);
}

static void ss_Icu_Enable_LCAN_RX(void)
{
    // LCAN Wakeup Enable
    Icu_EnableEdgeDetection(IcuConf_IcuChannel_IcuChannel_LCAN_RX);
    Icu_EnableNotification(IcuConf_IcuChannel_IcuChannel_LCAN_RX);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
*/
/*

***************************************************************************************************/
static void ss_Icu_Disable_IGN1(void)
{
    Icu_DisableEdgeDetection(IcuConf_IcuChannel_IcuChannel_IGN1);
    Icu_DisableNotification(IcuConf_IcuChannel_IcuChannel_IGN1);
}

static void ss_Icu_Disable_BCAN_RX(void)
{
    Icu_DisableEdgeDetection(IcuConf_IcuChannel_IcuChannel_BCAN_RX);
    Icu_DisableNotification(IcuConf_IcuChannel_IcuChannel_BCAN_RX);
}

static void ss_Icu_Disable_LCAN_RX(void)
{
    Icu_DisableEdgeDetection(IcuConf_IcuChannel_IcuChannel_LCAN_RX);
    Icu_DisableNotification(IcuConf_IcuChannel_IcuChannel_LCAN_RX);
}


/***************************************************************************************************
@param[in]  void
@return     void
@note
*/
/*

***************************************************************************************************/
static void ss_HSM_WakeupSet_Sleep(void)
{

//#if (CRYPTOLIB_SUPORT_HSM_HAE_HSM_2_X == STD_ON) // define 값이 정의 되지 않아서 강제로 주석 처리함.
  UINT16 irqList[3];
  Std_ReturnType ret = E_NOT_OK;
  BOOL Hsm_Status = FALSE;
  static uint8_t sbHsmSleepCnt = 0;
/* WPC_1900 */ /* HSM_Wakeup() API를 사용하는것보다 Wakeup Trigger를 등록하여 HOST와 HSM 동시에 깨어나게 해야함 */  
// HSM Sleep 처리 방법 변경. 플랫폼 배포시 (2.4.0) 샘플코드로 제시된 방법 적용. HSM 메뉴얼에도 이 방법을 추천하고 있음
// HSM_Sleep() 호출하기 전에 HSM core가 깨어나는 조건을 반드시 추가 해야함.
	
  irqList[0] = (UINT16)ioss_interrupts_gpio_8_IRQn;   	/* IGN */ // P8.2 ioss_interrupts_gpio_8_IRQn
  irqList[1] = (UINT16)ioss_interrupts_gpio_6_IRQn;  	/* BCAN_RX */ // P6.3 ioss_interrupts_gpio_6_IRQn
  irqList[2] = (UINT16)ioss_interrupts_gpio_19_IRQn;	/* LCAN_RX */ // P19.1 ioss_interrupts_gpio_19_IRQn

  sbHsmSleepCnt = 0;
  
  /* set wakeup source of HSM core */
  ret = HSM_SetWakeupTrigger(irqList, 3u);
  if (ret == E_OK)
  {
      /* request to sleep HSM core */
      ret = HSM_Sleep();
      if (ret == E_OK)
      {
		do
		{		
        	/* Check sleep status if HSM_Sleep succeeded */
        	Hsm_Status = HSM_IsSleepStatus();
			
			sbHsmSleepCnt++;
			if(sbHsmSleepCnt >= 250u)
			{
	  			sbHsmSleepCnt = 0;
	  			break;
			}			
		
		}while(Hsm_Status == FALSE);/* TRUE : HSM_Sleep succeeded , FALSE : not sleep */
				
      }

      if (ret != E_OK)
      {
        /* HSM_Sleep failed */
      }
  }

  if (ret != E_OK)
  {
      /* HSM_SetWakeupTrigger failed */
  }
//#endif
}

/***************************************************************************************************
@param[in]  void
@return     void
@note
*//*
SysClk Control for EvtGen
***************************************************************************************************/
/* WPC_1905_02 Start */

/* 슬립 진입 전에 hfclk1의 클럭을 IMO로 변경해줌 */
/* 디버깅모드로 레지스터를 보면 hfclk1는 RTSW에서 안쓰이는거 같음 */
/* 일단 PATH1을 쓰고 있었으니 EVENTGEN DEACTIVE 때 다시 원복해줌 */
#if 0
static uint8_t User_SysClk_HfClockSetSource(uint8_t hfClk, uint32_t source)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return 1ul;
    }
    if(source != 0xFFu /* CY_SYSCLK_HFCLK_IN_CLKIMO */)
    {
        SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u4ROOT_MUX = source;
        SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1DIRECT_MUX = 1ul; /* Select ROOT_MUX */
    }
    else
    {
        SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1DIRECT_MUX = 0ul; /* Select directly IMO */
    }
    return 0ul;
}
static uint8_t User_SysClk_HfClkEnable(uint8_t hfClk)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return 1ul;
    }
    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1ENABLE = 1ul; /* 1 = enable */
    return 0ul;
}
static uint8_t User_SysClk_HfClkDisable(uint8_t hfClk)
{
    if(hfClk >= SRSS_NUM_HFROOT)
    {
        return 1ul;
    }
    SRSS->unCLK_ROOT_SELECT[hfClk].stcField.u1ENABLE = 0ul; /* 0 = disable */
    return 0ul;
}
#endif
/* WPC_1905_02 End */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
