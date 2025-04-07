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
**  SRC-MODULE: Dcm_Timer.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : C header for Dcm_Timer                                        **
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

#ifndef DCM_TIMER_H
#define DCM_TIMER_H

/*******************************************************************************
**                           Include Section                                  **
*******************************************************************************/

#include "Dcm.h"
#include "Dcm_PCTypes.h"

#define DCM_START_SEC_CODE
#include "MemMap.h"

#if (DCM_DSP_SECURITY_SERVICE == STD_ON)
extern FUNC(void, DCM_CODE) Dcm_SecurityAccess_InitTimers(Dcm_ConfigConstPtrType pConfig);

extern FUNC(void, DCM_CODE) Dcm_SecurityAccess_UpdateTimers(void);

extern FUNC(void, DCM_CODE) Dcm_SecurityAccess_StartTimerExt(
  Dcm_SecurityAccess_TimerType Timer
  , uint32 Time
  , Dcm_TimerCallbackFunType PendingCbk
  , Dcm_TimerCallbackFunType TimeoutCbk);

extern FUNC(void, DCM_CODE) Dcm_SecurityAccess_StartTimer(Dcm_SecurityAccess_TimerType Timer, uint32 Time);

extern FUNC(void, DCM_CODE) Dcm_SecurityAccess_StopTimer(Dcm_SecurityAccess_TimerType Timer);

extern FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerRunning(Dcm_SecurityAccess_TimerType Timer);

extern FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerExpired(Dcm_SecurityAccess_TimerType Timer);

extern FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerStarted(Dcm_SecurityAccess_TimerType Timer);
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
