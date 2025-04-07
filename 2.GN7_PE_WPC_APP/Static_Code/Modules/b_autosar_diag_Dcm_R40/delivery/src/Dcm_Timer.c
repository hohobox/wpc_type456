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
**  SRC-MODULE: Dcm_Timer.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Provided API for Dcm timer handling                           **
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

#include "Dcm_Timer.h"
#include "Dcm.h"
#include "Dcm_Ram.h"
#include "SchM_Dcm.h"

/*******************************************************************************
**                      Static Functions Declaration                          **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

#if (DCM_DSP_SECURITY_SERVICE == STD_ON)
static FUNC(Dcm_TimerInfoPtrType, DCM_CODE) Dcm_SecurityAccess_GetTimerInfoPtr(
  Dcm_SecurityAccess_TimerType Timer);

static FUNC(void, DCM_CODE) Dcm_SecurityAccess_SetTimerInfo(
  Dcm_SecurityAccess_TimerType Timer
  , boolean StartFlag
  , uint32 Time
  , Dcm_TimerCallbackFunType PendingCbk
  , Dcm_TimerCallbackFunType TimeoutCbk);
#endif

/*******************************************************************************
**                           Functions definition                             **
*******************************************************************************/

#if (DCM_DSP_SECURITY_SERVICE == STD_ON)
/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_InitTimers                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function Dcm timer initialize                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : Dcm_Init must be called before call this fucntion   **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_SetTimerInfo       **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SecurityAccess_InitTimers(Dcm_ConfigConstPtrType pConfig)
{
  uint32 Timer = DCM_ZERO;

  for (Timer = DCM_ZERO; Timer < (uint32) DCM_SECURITY_TIMER_MAX_NUM; Timer++)
  {
    /* polyspace +1 MISRA-C3:10.5 [Justified:Low] "To make a type conversion explicit in the interests of clarity" */
    Dcm_SecurityAccess_SetTimerInfo((Dcm_SecurityAccess_TimerType) Timer,
      DCM_FALSE, DCM_ZERO, NULL_PTR, NULL_PTR);
  }

  DCM_UNUSED(pConfig);
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_UpdateTimers                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function update Dcm available timer                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_GetTimerInfoPtr    **
**                                      Dcm_SecurityAccess_StopTimer          **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE)Dcm_SecurityAccess_UpdateTimers(void)
{
  uint32 Timer = DCM_ZERO;
  Dcm_TimerInfoPtrType pTimer = NULL_PTR;
  Dcm_TimerCallbackFunType pCbkFun = NULL_PTR;

  for (Timer = DCM_ZERO; Timer < (uint32) DCM_SECURITY_TIMER_MAX_NUM; Timer++)
  {  
    SchM_Enter_Dcm_TimerProtection();
    /* polyspace +1 MISRA-C3:10.5 [Justified:Low] "To make a type conversion explicit in the interests of clarity" */
    pTimer = Dcm_SecurityAccess_GetTimerInfoPtr((Dcm_SecurityAccess_TimerType) Timer);

    if (DCM_FALSE == pTimer->StartFlag)
    {
      SchM_Exit_Dcm_TimerProtection();
      continue;
    }

    if (DCM_ZERO < pTimer->Time)
    {
      pTimer->Time--;
    }

    pCbkFun = (DCM_ZERO < pTimer->Time) ? pTimer->PendingCbk : pTimer->TimeoutCbk;
    SchM_Exit_Dcm_TimerProtection();

    if (NULL_PTR != pCbkFun)
    {
      pCbkFun();

      if (pCbkFun == pTimer->TimeoutCbk)
      {
        /* polyspace +1 MISRA-C3:10.5 [Justified:Low] "To make a type conversion explicit in the interests of clarity" */
        Dcm_SecurityAccess_StopTimer((Dcm_SecurityAccess_TimerType) Timer);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_StartTimerExt                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function start Dcm available timer                  **
**                        and invoked setup function                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer, Time, PendingCbk, TimeoutCbk                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_SetTimerInfo       **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SecurityAccess_StartTimerExt(
  Dcm_SecurityAccess_TimerType Timer
  , uint32 Time
  , Dcm_TimerCallbackFunType PendingCbk
  , Dcm_TimerCallbackFunType TimeoutCbk)
{
  Dcm_SecurityAccess_SetTimerInfo(Timer, DCM_TRUE, Time, PendingCbk, TimeoutCbk);
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_StartTimer                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function start Dcm available timer                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer, Time                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_SetTimerInfo       **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SecurityAccess_StartTimer(Dcm_SecurityAccess_TimerType Timer, uint32 Time)
{
  Dcm_SecurityAccess_SetTimerInfo(Timer, DCM_TRUE, Time, NULL_PTR, NULL_PTR);
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_StopTimer                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function stop Dcm available timer                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_SetTimerInfo       **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SecurityAccess_StopTimer(Dcm_SecurityAccess_TimerType Timer)
{
  Dcm_SecurityAccess_SetTimerInfo(Timer, DCM_FALSE, DCM_ZERO, NULL_PTR, NULL_PTR);
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_IsTimerRunning                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function check a timer is runing or not             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_GetTimerInfoPtr    **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerRunning(Dcm_SecurityAccess_TimerType Timer)
{
  boolean LblRetVal = DCM_FALSE;
  Dcm_TimerInfoPtrType pTimer = NULL_PTR;

  SchM_Enter_Dcm_TimerProtection();
  pTimer = Dcm_SecurityAccess_GetTimerInfoPtr(Timer);

  if ((DCM_TRUE == pTimer->StartFlag) && ((uint16) DCM_ZERO < pTimer->Time))
  {
    LblRetVal = DCM_TRUE;
  }
  SchM_Exit_Dcm_TimerProtection(); 

  return LblRetVal;
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_IsTimerExpired                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function check a timer expired or not               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_GetTimerInfoPtr    **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerExpired(Dcm_SecurityAccess_TimerType Timer)
{
  boolean LblRetVal = DCM_FALSE;
  Dcm_TimerInfoPtrType pTimer = NULL_PTR;

  SchM_Enter_Dcm_TimerProtection();
  pTimer = Dcm_SecurityAccess_GetTimerInfoPtr(Timer);

  if (((uint16) DCM_ZERO == pTimer->Time) && (DCM_TRUE == pTimer->StartFlag))
  {
    LblRetVal = DCM_TRUE;
  }
  SchM_Exit_Dcm_TimerProtection();

  return LblRetVal;
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_IsTimerStarted                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function check a timer is started or not            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) : Dcm_SecurityAccess_GetTimerInfoPtr    **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_SecurityAccess_IsTimerStarted(Dcm_SecurityAccess_TimerType Timer)
{
  boolean LblRetVal = DCM_FALSE;
  Dcm_TimerInfoPtrType pTimer = NULL_PTR;
  
  SchM_Enter_Dcm_TimerProtection();
  pTimer = Dcm_SecurityAccess_GetTimerInfoPtr(Timer);

  LblRetVal = pTimer->StartFlag;
  SchM_Exit_Dcm_TimerProtection();

  return (LblRetVal);
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_GetTimerInfoPtr                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function get status of a timer                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_TimerInfoPtrType                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Dcm_GaaTimerInfo              **
**                                                                            **
**                        Function(s) :                                       **
**                                                                            **
*******************************************************************************/
static FUNC(Dcm_TimerInfoPtrType, DCM_CODE) Dcm_SecurityAccess_GetTimerInfoPtr(
  Dcm_SecurityAccess_TimerType Timer)
{
  return &Dcm_GaaSecurityTimerInfo[Timer];
}

/*******************************************************************************
** Function Name        : Dcm_SecurityAccess_SetTimerInfo                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to set status of a timer                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : Timer, StartFlag, Time, PendingCbk, TimeoutCbk      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Dcm_GaaTimerInfo              **
**                                                                            **
**                        Function(s) :                                       **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_SecurityAccess_SetTimerInfo(
  Dcm_SecurityAccess_TimerType Timer
  , boolean StartFlag
  , uint32 Time
  , Dcm_TimerCallbackFunType PendingCbk
  , Dcm_TimerCallbackFunType TimeoutCbk)
{
  Dcm_TimerInfoPtrType pTimer = NULL_PTR;

  SchM_Enter_Dcm_TimerProtection();
  pTimer = &Dcm_GaaSecurityTimerInfo[Timer];
  pTimer->StartFlag = StartFlag;
  pTimer->Time = (Time / DCM_TASK_TIME);
  pTimer->PendingCbk = PendingCbk;
  pTimer->TimeoutCbk = TimeoutCbk;
  SchM_Exit_Dcm_TimerProtection();  
}
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
