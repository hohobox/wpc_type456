/*******************************************************************************
**                                                                            **
** (C) 2021 HYUNDAI AUTOEVER Corp.                                            **
** Confidential Proprietary Information. Distribution Limited.                **
** This source code is permitted to be used only in projects contracted       **
** with Hyundai Autoever, and any other use is prohibited.                    **
** If you use it for other purposes or change the source code,                **
** you may take legal responsibility.                                         **
** In this case, There is no warranty and technical support.                  **
**                                                                            **
**  SRC-MODULE: Dcm_DslManageSecurity.h                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_DslManageSecurity                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.14.0.0  30-Sep-2024   Haewon Seo     #48771                              **
*******************************************************************************/

#ifndef DCM_DSLMANAGESECURITY_H
#define DCM_DSLMANAGESECURITY_H

/*******************************************************************************
**                           Include Section                                  **
*******************************************************************************/
#include "Dcm_PCTypes.h"

#define DCM_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, DCM_CODE) Dcm_InitManageSecurity(
  Dcm_ConfigConstPtrType pConfig);

extern FUNC(void, DCM_CODE) Dcm_InitSecurityLevelState(
  Dcm_ConfigConstPtrType pConfig);

extern FUNC(uint8, DCM_CODE) Dcm_GetSecurityLevelIndex(
  void);

extern FUNC(void, DCM_CODE) Dcm_SetSecurityLevelIndex(
  uint8 SecLvlIdx);

extern FUNC(Dcm_SecurityLevConfigConstPtrType, DCM_CODE) 
  Dcm_GetSecurityLevelConfig(void);

extern FUNC(Dcm_SecurityLevConfigConstPtrType, DCM_CODE) 
  Dcm_GetSecurityLevelConfigByIndex(uint8 SecLvlIdx);

extern FUNC(void, DCM_CODE) Dcm_IncSecurityAttemptCounterOfCurrentLevel(void);

extern FUNC(boolean, DCM_CODE) Dcm_IsSecurityAttemptCounterExceeded(void);

extern FUNC(void, DCM_CODE) Dcm_ResetSecurityAttemptCounterOfCurrentLevel(void);

extern FUNC(uint8, DCM_CODE) Dcm_GetSecurityAttemptCounterOfCurrentLevel(void);

extern FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterOfCurrentLevel(
  uint8 AttCounter);

/* Restore Security Attempt Counters */

extern FUNC(void, DCM_CODE) Dcm_StartRestoreSecurityAttemptCounters(void);

extern FUNC(void, DCM_CODE) Dcm_WaitRestoreSecurityAttemptCounters(void);

extern FUNC(void, DCM_CODE) Dcm_CancelRestoreSecurityAttemptCounters(void);

extern FUNC(void, DCM_CODE) Dcm_RestoreSecurityAttemptCountersDone(void);

extern FUNC(boolean, DCM_CODE) Dcm_IsSecurityAttemptCounterRestored(
  uint8 ServiceId, 
  uint8 SubServiceId, 
  Dcm_NrcPtrType pErrorCode);

/* Inform Security Attempt Counter is changed */

extern FUNC(void, DCM_CODE) Dcm_StartInformSecurityAttemptCounter(void);

extern FUNC(void, DCM_CODE) Dcm_WaitInformSecurityAttemptCounter(void);

extern FUNC(void, DCM_CODE) Dcm_CancelInformSecurityAttemptCounter(void);

extern FUNC(void, DCM_CODE) Dcm_WaitAndExtendInformSecurityAttemptCounter(void);

extern FUNC(void, DCM_CODE) Dcm_ResetAndInformSecurityAttemptCounter(void);

extern FUNC(boolean, DCM_CODE) Dcm_IsSetSecurityAttemptCountersPending(void);

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
