/*******************************************************************************
**                                                                            **
**  (C) 2018 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE:           ComXf.c                                             **
**                                                                            **
**  PRODUCT   :           AUTOSAR COM Based Transformer Module                **
**                                                                            **
**  PURPOSE   :           This file contain function body for generic public  **
**                        API's.                                              **
**                                                                            **
**  HARDWARE DEPENDANT [Yes/No]: No                                           **
**                                                                            **
**  AUTOSAR RELEASE:  4.3.0                                                   **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 1.0.8     11-Jan-2020   SM Kwon     #27586                                 **
** 1.0.7     07-Dec-2020   SM Kwon     #25706                                 **
** 1.0.1     09-Feb-2018   Chan Kim    #11566                                 **
** 1.0.0     31-Jan-2018   AUTOEVER    Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                         Header File Include Section                        **
*******************************************************************************/
/* Include for ComXf.h */
#include "ComXf.h"
/* Include for ComXf_Cfg.h */
#include "ComXf_Cfg.h"
#if(STD_ON == COMXF_DEV_ERROR_DETECT)
/* Include for Det.h */
#include "Det.h"
#endif
/* Include for ComXf_Types.h */
#include "ComXf_Types.h"
/* Include for ComXf_Macros.h */
#include "ComXf_Macros.h"
/* Include for ComXf_GlobalDataDefinition.h */
#include "ComXf_GlobalDataDefinition.h"
/* Include for ComXf_ErrorCheck.h */
#include "ComXf_ErrorCheck.h"
/* Include for memset */
#include "string.h"
/*******************************************************************************
**                            Type Definition                                 **
*******************************************************************************/

/*******************************************************************************
**                        Global Variable Declaration                         **
*******************************************************************************/

/*******************************************************************************
**                            Function Declaration                            **
*******************************************************************************/
/* polyspace:begin <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/*******************************************************************************
**                            Version Check                                   **
*******************************************************************************/
/* Version information check */
#if (COMXF_AR_RELEASE_MAJOR_VERSION != COMXF_CFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "ComXf.c : Mismatch in AUTOSAR Release Major Version"
#endif
#if (COMXF_AR_RELEASE_MINOR_VERSION != COMXF_CFG_C_AR_RELEASE_MINOR_VERSION)
  #error "ComXf.c : Mismatch in AUTOSAR Release Minor Version"
#endif
#if (COMXF_AR_RELEASE_REVISION_VERSION != \
  COMXF_CFG_C_AR_RELEASE_REVISION_VERSION)
  #error "ComXf.c : Mismatch in AUTOSAR Release Revision Version"
#endif
#if (COMXF_SW_MAJOR_VERSION != COMXF_CFG_C_SW_MAJOR_VERSION)
  #error "ComXf.c: Mismatch in Software Major Version"
#endif
#if (COMXF_SW_MINOR_VERSION != COMXF_CFG_C_SW_MINOR_VERSION)
 #error "ComXf.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                           Function Definitions                             **
*******************************************************************************/

/*******************************************************************************
**                             MISRA Exceptions                               **
********************************************************************************
** MISRA Rule No       : Warning 613, info 831                                **
** MISRA Rule          : Possible use of null pointer 'VersionInfo' in left   **
**                     : argument to operator '->'                            **
** Functionality       : VersionInfo pointer used to store version information**
** Occurrences         : In ComXf_GetVersionInfo function                     **
** Verification        : It is manually verified that null pointer checking is**
**                       done before using it                                 **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 20.1, advisory                       **
** MISRA Rule          : declaration of 'ComXf_GetVersionInfo' before #include**
** Functionality       : declaration of 'ComXf_GetVersionInfo' before #include**
** Occurrences         : In ComXf_GetVersionInfo function                     **
** Verification        : It is manually verified declaration of               **
**                       ComXf_GetVersionInfo                                 **
** Verification Method : Code review                                          **

** MISRA Rule No       : info 766                                             **
** MISRA Rule          : Header files ComXf_MemMap.h not used in module       **
** Functionality       : This file provides all the memory abstractions used  **
**                     : in the COMXF Module                                  **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified                              **
** Verification Method : Code review                                          **

** MISRA Rule No       : MISRA 2012 Rule 14.4, required                       **
** MISRA Rule          : Conditional expression should have essentially       **
**                       Boolean type                                         **
** Functionality       : Conditional expression should have essentially       **
**                       Boolean type                                         **
** Occurrences         : In whole file                                        **
** Verification        : It is manually verified                              **
** Verification Method : Code review                                          **
*******************************************************************************/

/*******************************************************************************
**                             MISRA Exceptions                               **
********************************************************************************
** MISRA Rule No       : Warning 613, info 831                                **
** MISRA Rule          : Possible use of null pointer 'VersionInfo' in left   **
**                     : argument to operator '->'                            **
** Functionality       : VersionInfo pointer used to store version information**
** Occurrences         : In ComXf_GetVersionInfo function                     **
** Verification        : It is manually verified that null pointer checking is**
**                       done before using it                                 **
** Verification Method : Code review                                          **
*******************************************************************************/

/*=============================================================================*
** Service Name         : ComXf_GetVersionInfo                                **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This service returns the version information of the **
**                        called transformer module                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : VersionInfo                                         **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : No Preconditions                                    **
**                                                                            **
**============================================================================*/
#if(STD_ON == COMXF_VERSION_INFORMATION)
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, COMXF_VAR) VersionInfo)
{
  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  /* Local variable to store return value */
  uint8 Lu8_ReturnStatus;
  #endif /* End of #if(STD_ON == COMXF_DEV_ERROR_DETECT) */

  #if(STD_ON == COMXF_DEV_ERROR_DETECT)
  /* Store return value into local variable */
  Lu8_ReturnStatus = E_OK;

  /* Check whether pointer is null */
  COMXF_GETVERSIONINFO_NULL_POINTER_CHECK(Lu8_ReturnStatus, VersionInfo,
    COMXF_GETVERSIONINFO_SERVICE_ID);

  /* Check for E_OK */
  if(E_OK == Lu8_ReturnStatus)
  #endif /* End of #if(STD_ON == COMXF_DEV_ERROR_DETECT) */
  {
    /* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    /* Assigning vendor Id to the VersionInfo parameter */
    VersionInfo->vendorID = COMXF_VENDOR_ID;

    /* Assigning module Id to the VersionInfo parameter */
    VersionInfo->moduleID = COMXF_MODULE_ID;

    /* Assigning software major version to the VersionInfo parameter */
    VersionInfo->sw_major_version = COMXF_SW_MAJOR_VERSION;

    /* Assigning software minor version to the VersionInfo parameter */
    VersionInfo->sw_minor_version = COMXF_SW_MINOR_VERSION;

    /* Assigning software patch version to the VersionInfo parameter */
    VersionInfo->sw_patch_version = COMXF_SW_PATCH_VERSION;
    /* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  } /* End of if(VersionInfo == NULL_PTR) */
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"
#endif /* End of #if(STD_ON == COMXF_VERSION_INFORMATION) */

/*=============================================================================*
** Service Name         : ComXf_Init                                          **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : This service initializes the transformer for the    **
**                        further processing.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : config                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : No Preconditions                                    **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_Init(
  P2CONST(ComXf_ConfigType, AUTOMATIC, COMXF_CONST) config)
{
  #if(COMXF_PRECOMPILE_CONFIG == STD_ON)
  COMXF_UNUSED_PTR(config);
  #endif /* End of #if(COMXF_PRECOMPILE_CONFIG == STD_ON) */

  /* Store module initialization value into global */
  ComXf_Gbl_InitStatus = (boolean)COMXF_CS_INIT;

}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"

/*=============================================================================*
** Service Name         : ComXf_DeInit                                        **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This service de-initializes the transformer         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : config                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : ComXf_Init should be called                         **
**                                                                            **
**============================================================================*/
#define COMXF_START_SEC_CODE
#include "ComXf_MemMap.h"
FUNC(void, COMXF_CODE) ComXf_DeInit(void)
{
  /* Store module de-initialization value into global */
  ComXf_Gbl_InitStatus = (boolean)COMXF_CS_DEINIT;
}
#define COMXF_STOP_SEC_CODE
#include "ComXf_MemMap.h"


/*=============================================================================*
** Service Name         : ComXf_FillUnusedBufferArea                          **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : initializes the transformer buffer                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Lu32_ComXfBufferLength,                             **
**                        Lu8_ComXfUnusedAreaValue                            **
**                                                                            **
** InOut parameter      : buffer                                              **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
**============================================================================*/

#define COMXF_START_APPL_SEC_CODE
#include "ComXf_MemMap.h"
extern FUNC(void, COMXF_APPL_CODE) ComXf_FillUnusedBufferArea(
  P2VAR(uint8, AUTOMATIC, COMXF_APPL_DATA) buffer, 
  uint32 Lu32_ComXfBufferLength ,uint8 Lu8_ComXfUnusedAreaValue)
{
  /* polyspace +1 DEFECT:SIGN_CHANGE [Not a defect: Justified] "Overflow will not occur" */
  memset((void*)&buffer[COMXF_ZEROTH_BYTE], (sint8)Lu8_ComXfUnusedAreaValue, (PduLengthType)Lu32_ComXfBufferLength);
}
#define COMXF_STOP_APPL_SEC_CODE
#include "ComXf_MemMap.h"
/* polyspace:end <RTE:UNR:Not a defect:Low> The code will be reachable in diffrent configuration */
/*******************************************************************************
*                       End of File                                            *
*******************************************************************************/
