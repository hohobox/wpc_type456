/*******************************************************************************
**  FILE-NAME : EcuM_Generated_Callouts.c                                     **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 3.1.4                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_CanCM.arxml
 *                Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_CanSM.arxml
 *                Configuration\ECU\Ecud_CanTp.arxml
 *                Configuration\ECU\Ecud_CanTrcv.arxml
 *                Configuration\ECU\Ecud_Com.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_CryIf.arxml
 *                Configuration\ECU\Ecud_Crypto_76_HaeModule.arxml
 *                Configuration\ECU\Ecud_Csm.arxml
 *                Configuration\ECU\Ecud_CtrlRam.arxml
 *                Configuration\ECU\Ecud_Dcm.arxml
 *                Configuration\ECU\Ecud_Dem.arxml
 *                Configuration\ECU\Ecud_Det.arxml
 *                Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_EcuM.arxml
 *                Configuration\ECU\Ecud_Fota.arxml
 *                Configuration\ECU\Ecud_IoHwAb.arxml
 *                Configuration\ECU\Ecud_IpduM.arxml
 *                Configuration\ECU\Ecud_Nm.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_PduR.arxml
 *                Configuration\ECU\Ecud_RamTst.arxml
 *                Configuration\ECU\Ecud_RomTst.arxml
 *                Configuration\ECU\Ecud_WdgM.arxml
 *                Configuration\ECU\Mcal\Ecud_Adc.arxml
 *                Configuration\ECU\Mcal\Ecud_Can.arxml
 *                Configuration\ECU\Mcal\Ecud_Dio.arxml
 *                Configuration\ECU\Mcal\Ecud_Gpt.arxml
 *                Configuration\ECU\Mcal\Ecud_Icu.arxml
 *                Configuration\ECU\Mcal\Ecud_Mcu.arxml
 *                Configuration\ECU\Mcal\Ecud_Port.arxml
 *                Configuration\ECU\Mcal\Ecud_Pwm.arxml
 *                Configuration\ECU\Mcal\Ecud_Spi.arxml
 *                Configuration\ECU\Mcal\Ecud_Wdg.arxml
 * GENERATED ON: The time-stamp is removed
 */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM_Generated_Callouts.h"
#include "CanSM.h"
#include "Mcu.h"
#include "CanCM.h"
#include "CryIf.h"
#include "Csm.h"
#include "Pwm.h"
#include "PduR.h"
#include "IpduM.h"
#include "Fota.h"
#include "CtrlRam.h"
#include "Port.h"
#include "IoHwAb.h"
#include "Icu.h"
#include "RomTst.h"
#include "Com.h"
#include "Spi.h"
#include "Wdg_66_IA.h"
#include "RamTst.h"
#include "CanTp.h"
#include "CanTrcv.h"
#include "ComM.h"
#include "Dem.h"
#include "Gpt.h"
#include "WdgM.h"
#include "Can.h"
#include "Nm.h"
#include "CanIf.h"
#include "Adc.h"
#include "Det.h"
#include "Wdg_76_Acw.h"
#include "Mem_Integration.h"
#include "WdgStack_Callout.h"
#include "E2EXf.h"
#include "Mem_76_Pfls.h"
#include "ComXf.h"


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Initialization Structure                              **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define ECUM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : EcuM_Gen_AL_DriverInitZero                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities for   **
**                        loading the post-build configuration data. Note:    **
**                        Here only pre-compile and link-time configurable    **
**                        modules may be used.                                **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                          Det_Init()                                        **
**                          Dem_PreInit()                                     **
**                          Fota_Init()                                       **
*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Gen_AL_DriverInitZero(void)
{
  Det_Init();

  Dem_PreInit(NULL_PTR);

  Fota_Init();

}

/*******************************************************************************
** Function Name        : EcuM_Gen_AL_DriverInitOne                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities in    **
**                        case of a power on reset                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                          Mcu_Init()                                        **
**                          Port_Init()                                       **
**                          Adc_Init()                                        **
**                          Gpt_Init()                                        **
**                          Pwm_Init()                                        **
**                          Icu_Init()                                        **
**                          Spi_Init()                                        **
**                          CanTrcv_Init()                                    **
**                          Can_Init()                                        **
**                          IoHwAb_Init()                                     **
**                          CanIf_Init()                                      **
**                          CanSM_Init()                                      **
**                          CanTp_Init()                                      **
**                          PduR_Init()                                       **
**                          Com_Init()                                        **
**                          ComM_Init()                                       **
**                          Nm_Init()                                         **
**                          CanNm_Init()                                      **
**                          CanCM_Init()                                      **
**                          IpduM_Init()                                      **
**                          RamTst_Init()                                     **
**                          Wdg_66_IA_Init()                                  **
**                          Wdg_76_Acw_Init()                                 **
**                          WdgM_Init()                                       **
**                          Csm_Init()                                        **
**                          CtrlRam_Init()                                    **
**                          E2EXf_Init()                                      **
**                          ComXf_Init()                                      **
**                          RomTst_Init()                                     **
**                          Dem_PreInit2()                                    **
**                          CryIf_Init()                                      **
**                          Mem_76_Pfls_Init()                                **
**                          Mem_Driver_Init()                                 **
*******************************************************************************/
/* polyspace-begin MISRA-C3:17.7 [Justified:Medium] "AUTOEVER_MISRA_17_7 SWS_EcuM_02980" */
/* polyspace-begin MISRA-C3:2.2 [Justified:Medium] "Empty function will be written by customer and then it will not be a deadcode" */
FUNC(void, ECUM_CODE) EcuM_Gen_AL_DriverInitOne
  (P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{

  /* polyspace +1 RTE:UNR [Justified:Medium] "AUTOEVER_RTE_UNR" */
  ECUM_UNUSED_PTR(ConfigPtr);
  EcuM_GulPllCnt = 0u;
  Mcu_Init(&Mcu_Config);
  EcuM_McuPostInit();
  (void)Mcu_InitClock(ECUM_MCU_NORMAL_CLOCK);
  while(Mcu_GetPllStatus() != MCU_PLL_LOCKED)
  {
    if (EcuM_GulPllCnt >= ECUM_LOOP_COUNT_MAX)
    {
      #if (ECUM_DEV_ERROR_DETECT == STD_ON)
      (void)Det_ReportError(ECUM_MODULE_ID, ECUM_INSTANCE_ID, ECUM_INIT_SID, ECUM_E_INVALID_PAR);
      #endif
      Mcu_PerformReset();
    }
    EcuM_GulPllCnt++;
  }
  Mcu_DistributePllClock();

  Port_Init(&Port_Config);

  Adc_Init(&Adc_Config);

  Gpt_Init(&Gpt_Config);

  Pwm_Init(&Pwm_Config);

  Icu_Init(&Icu_Config);

  Spi_Init(NULL_PTR);

  CanTrcv_Init(NULL_PTR);

  Can_Init(&CanConfigSet);

  IoHwAb_Init();

  CanIf_Init(NULL_PTR);

  CanSM_Init(NULL_PTR);

  CanTp_Init(NULL_PTR);

  PduR_Init(NULL_PTR);

  Com_Init(NULL_PTR);

  ComM_Init();

  Nm_Init();

  CanNm_Init(NULL_PTR);

  CanCM_Init();

  IpduM_Init(NULL_PTR);

  RamTst_Init();

  Wdg_66_IA_Init(&Wdg_66_IA_Config);

  Wdg_76_Acw_Init(NULL_PTR);

  WdgM_Init(NULL_PTR);

  Csm_Init(NULL_PTR);

  CtrlRam_Init();

  E2EXf_Init(NULL_PTR);

  ComXf_Init(NULL_PTR);

  RomTst_Init();

  Dem_PreInit2(NULL_PTR);

  CryIf_Init(NULL_PTR);

  Mem_76_Pfls_Init(NULL_PTR);

  Mem_Driver_Init();

}
/* polyspace-end MISRA-C3:2.2 */
/* polyspace-end MISRA-C3:17.7 */


/*******************************************************************************
** Function Name        : EcuM_Gen_CheckWakeup                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This callout shall provide APIs to poll a wakeup    **
**                        source.                                             **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                          CanCM_CheckWakeup(wakeupSource)                   **
*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Gen_CheckWakeup
(EcuM_WakeupSourceType wakeupSource)
{
  if ((wakeupSource == ECUM_WKSOURCE_BCAN_RX_POLL) ||
(wakeupSource == ECUM_WKSOURCE_LCAN_RX_POLL) )
  {
    CanCM_CheckWakeup(wakeupSource);
  }
  else
  {
  }
}

/*******************************************************************************
** Function Name        : EcuM_Gen_EnableWakeupSources                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This callout shall provide APIs to allow the system **
**                        designer to notify wakeup sources defined in        **
**                        the wakeupSource bitfield that SLEEP will be        **
**                         entered and to adjust their source accordingly.    **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **

*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Gen_EnableWakeupSources
(EcuM_WakeupSourceType wakeupSource)
{
 
}

/*******************************************************************************
** Function Name        : EcuM_Gen_DisableWakeupSources                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This callout shall provide APIs to set up the given **
**                        wakeup source(s) so that they are not able to       **
**                        wakeup the ECU.                                     **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **

*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_Gen_DisableWakeupSources
(EcuM_WakeupSourceType wakeupSource)
{
 
}

#define ECUM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
