/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Det.h                                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Development Error Tracer                              **
**                                                                            **
**  PURPOSE   : This file contains declaration of functions defined in        **
**              Development Error Tracer module which are used by             **
**              the other modules.                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.0.8     06-Mar-2023   KyungTae Kim    Changes made As per Redmine #39564 **
**                                                                            **
** 1.0.1     28-Nov-2012   Youngjin.Yun     Remove Rte_Det_Type.h             **
**				                                   in the included files      **
**                                                                            **
** 1.0.0     01-Jan-2013   Autron           Initial Version                   **
*******************************************************************************/
#ifndef DET_H
#define DET_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* This header file includes all the standard data types, platform dependent
  header file and common return types */
#include "Std_Types.h"              /* standard AUTOSAR types */
#include "Det_Cfg.h"                /* Det Cfg header file */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.5 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      Service IDs                                           **
*******************************************************************************/
/* Service id for Det_GetVersionInfo */
#define DET_GETVERSIONINFO_SID                   ((uint8)0x03)

/*******************************************************************************
**                      DET Error Codes                                       **
*******************************************************************************/
/* DET Error Codes */
#define DET_E_PARAM_POINTER                      ((uint8)0x01)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define DET_START_SEC_CODE
#include "MemMap.h"

/* This function is used to send the version information of Det
  to other modules*/
#if (DET_VERSION_INFO_API == STD_ON)
extern FUNC(void, DET_CODE)Det_GetVersionInfo
  (P2VAR(Std_VersionInfoType, AUTOMATIC, DET_APPL_DATA) versioninfo);
#endif

/* This Det_Init declaration for initialization function */
extern FUNC(void, DET_CODE) Det_Init(void);

/* This function is used to log the reported errors and count the reported
  errors */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> No Impact of this rule violation */
extern FUNC(Std_ReturnType, DET_CODE) Det_ReportError
  (uint16 ModuleId, uint8 InstanceId, uint8 ApiId, uint8 ErrorId);

/* This function is the service for sending development error stored in RAM
  via communication interface */
extern FUNC(void, DET_CODE) Det_Start(void);

/* polyspace +2 MISRA-C3:20.1 [Justified:Low] "Not a defect" */
#define DET_STOP_SEC_CODE
#include "MemMap.h"

#endif /* DET_H */

#define Det_ReportTransientFault(ModuleId,InstanceId,ApiId,ErrorId) Det_ReportError(ModuleId,InstanceId,ApiId,ErrorId)
#define Det_ReportRuntimeError(ModuleId,InstanceId,ApiId,ErrorId) Det_ReportError(ModuleId,InstanceId,ApiId,ErrorId)

/* polyspace-end MISRA-C3:2.5 [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
