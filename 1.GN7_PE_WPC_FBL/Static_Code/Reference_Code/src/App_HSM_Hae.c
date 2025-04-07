/*******************************************************************************
**                                                                            **
**  (C) 2017 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: App_HSM_Hae.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : Hsm (Hardware Security Module)                                **
**                                                                            **
**  PURPOSE   : Implementation file for HSM                                   **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By           Description                           **
********************************************************************************
** 1.0.0     22-Jun-2020   JaeHyun      Redmine #22362                        **

*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "App_HSM_Hae.h"
#include "Hsm_HostAPI.h"
#include "Os.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
void UserCallout_HsmDriverInit(void)
{
  Std_ReturnType LddRT;

  #if HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
  //LddRT = HSM_EnableService(0,251); /*User must configurate ISR to Ecud_Os.arxml*/
  LddRT = E_OK; 
  #endif /*HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)*/

  #if HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
  //LddRT = HSM_EnableService(0,1); /*User must configurate ISR to Ecud_Os.arxml*/
  LddRT = E_OK; 
  #endif /*HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)*/
  
  #if HWRESOURCE_VENDOR(HWRESOURCE_ST)
  //LddRT = HSM_EnableService(2,1); /*User must configurate ISR to Ecud_Os.arxml*/
  LddRT = E_OK; 
  #endif /* HWRESOURCE_VENDOR(HWRESOURCE_ST)*/

  #if HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
  //LddRT = HSM_EnableService(0,6); /*User must configurate ISR to Ecud_Os.arxml*/
  //LddRT = HSM_SetHsmHandlerIrqN(6); // NVIC Priority of IRQ is 6 due to Autron OS Policy
  //HSM_DisableInterruptService();
  //LddRT = E_OK;
  #endif

  if (LddRT == E_OK)
  {
	LddRT = HSM_DriverInitialize();
  }
  
  if (LddRT != E_OK)
  {
    /*HSM initialize Fail*/
  }
}

#if HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)
ISR(HSM0_ISR)
{
  HSM_IrqHandler();
}

ISR(HSM1_ISR)
{
  HSM_IrqHandler();
}
#endif /*HWRESOURCE_VENDOR(HWRESOURCE_INFINEON)*/

#if HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)
ISR(ICUPS_CAT2_ISR)
{
}

ISR(ICUP_CAT2_ISR)
{
  HSM_IrqHandler();
}

#endif /*HWRESOURCE_VENDOR(HWRESOURCE_RENESAS)*/

#if HWRESOURCE_VENDOR(HWRESOURCE_ST)
ISR(Hsm2Ht_31_ISR)
{
  HSM_IrqHandler();
}
#endif /* HWRESOURCE_VENDOR(HWRESOURCE_ST)*/

#if HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS)
#if ((defined(HWRESOURCE_CYT2BXX)) && HWRESOURCE_FAMILY(HWRESOURCE_CYT2BXX))
/*CYT2BX Serise : You must configure the only IPC4 to Ecud_Os.arxml */
ISR(Hsm_Isr_Vector_4_Cat2)
{
  HSM_IrqHandler();
}
#elif ((defined(HWRESOURCE_CYT4BXX)) && HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX))
/*CYT4BX Serise : You must configure the only IPC6 to Ecud_Os.arxml */
ISR(Hsm_Isr_Vector_3_Cat2)
{
  HSM_IrqHandler();
}
#elif ((defined(HWRESOURCE_CYT6BXX)) && HWRESOURCE_FAMILY(HWRESOURCE_CYT6BXX))
/* CYT6BX Serise : You must configure the only IPC14 to Ecud_Os.arxml */
ISR(Hsm_Isr_Vector_14_Cat2)
{
  HSM_IrqHandler();
}
#endif
#endif /* HWRESOURCE_VENDOR(HWRESOURCE_CYPRESS) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
