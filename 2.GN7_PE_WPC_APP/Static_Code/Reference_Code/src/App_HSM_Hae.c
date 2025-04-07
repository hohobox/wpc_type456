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

//#if (CRYPTOLIB_SUPORT_HSM_HAE_HSM_2_X == STD_ON)
#include "Hsm_HostAPI.h"
#include "Hsm_HostAPI_Traveo2.h"
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
  LddRT = HSM_SetHsmHandlerIrqN(4); // NVIC Priority of IRQ is 6 due to Autron OS Policy
  HSM_DisableInterruptService();
  //LddRT = E_OK;

  #endif

  if (LddRT == E_OK)
  {
  LddRT = HSM_DriverInitialize();

  }
  if (LddRT == E_OK) {
    HSM_EnableInterruptService();
  }
  
  if (LddRT != E_OK)
  {
    /*HSM initialize Fail*/
  }
}

ISR(Hsm_Isr_Vector_4_Cat2)
{
  HSM_IrqHandler();
}

//#endif /* (CRYPTOLIB_SUPORT_HSM_HAE_HSM_2_X == STD_ON) */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
