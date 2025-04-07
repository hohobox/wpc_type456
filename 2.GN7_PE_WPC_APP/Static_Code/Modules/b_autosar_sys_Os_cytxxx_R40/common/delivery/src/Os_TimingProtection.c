/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Os_TimingProtection.c                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Timing Protection functionality.                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.8     25-Nov-2020    JH.Cho        Redmine #26808                      **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     09-Mar-2017    SH.Yoo        Redmine #7716                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
** 2.0.10    08-Dec-2015    SH.Yoo        Redmine #3499                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1311                       **
** 2.0.8     14-May-2014    MJ.Woo        TASK: xar~842, Redmine #932         **
** 2.0.7     13-Feb-2014    SH.Yoo        TASK: xar~819, Redmine #587         **
** 2.0.4     31-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
**                          MJ.Woo                                            **
** 2.0.2     20-Aug-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
/* polyspace:begin<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations>configured memory access index */
/* polyspace:begin<RTE:OBAI:Not a defect:Justify with annotations> configured array index */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_TimingProtection.h" /* Os TimerProtection header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#if (OS_RESOURCE == STD_ON)
#include "Os_Resource.h"          /* Os Resource header file */
#endif
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"
#endif
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Os_OsWdgHandler                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This handler is used to schedule the next task when **
**                        a particular task has violated the timing protection**
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaRunningWdg, Os_GpStaticTask,                  **
**                        Os_GaaStaticTask, Os_GpLinkTask                     **
**                                                                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopTimer(), Os_ProtectionHookService()          **
*******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_OsWdgHandler(void)
{
  Os_WatchdogType LddWdgType;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Stop the timer */
  Os_StopTimer(OS_BUDGET_WATCHDOG);

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  LddWdgType = Os_GaaRunningWdg[OS_CORE_ID].ddWdgType;
  Os_GaaRunningWdg[OS_CORE_ID].ddWdgType = OS_WDG_DISABLED;
  Os_GaaRunningWdg[OS_CORE_ID].ulTPArrayIndx = OS_INVALID_VALUE;
  /* polyspace:end<MISRA-C3:18.1> */

  switch (LddWdgType)
  {
    /* Execution budget measurement */
    case OS_EXEC_BUDGET:
      (void)Os_ProtectionHookService(E_OS_PROTECTION_TIME);
      break;
      #if (OS_RESOURCE == STD_ON)
    /* Resource lock measurement */
    case OS_REZ_LOCK:
      (void)Os_ProtectionHookService(E_OS_PROTECTION_LOCKED);
      break;
      #endif

      #if (OS_ISR_COUNT != OS_PRE_ZERO)
    /* Interrupt lock measurement */
    case OS_ALL_INT_LOCK:
    case OS_INT_LOCK:
      (void)Os_ProtectionHookService(E_OS_PROTECTION_LOCKED);
      break;

      #endif /* End of if (OS_ISR_COUNT != OS_PRE_ZERO) */
    /* Default */
    default:
      #if(OS_SCALABILITY_CLASS == OS_SC4)
      (void)Os_ProtectionHookService(Os_GucExecFail[OS_CORE_ID]);
      #endif
      break;
  } /* End of switch (LddWdgType) */

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  Os_GpStaticTask[OS_CORE_ID] =
    &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_OsWdgHandler(void) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */
/*******************************************************************************
** Function Name        : Os_TimeFrameHandler                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is the handler for Time Frame Interrupt**
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpSchedWatchdog                                  **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StartTimer(), Os_StopTimer()                     **
*******************************************************************************/
#if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON))
FUNC(void, OS_CODE) Os_TimeFrameHandler(void)
{
  P2VAR(Tdd_Os_ScheduleWatchdog, AUTOMATIC, OS_VAR) LpSchedWatchdog;
  P2VAR(Tdd_Os_ScheduleWatchdog, AUTOMATIC, OS_VAR) LpNextSchedWatchdog;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  if (Os_GpSchedWatchdog[OS_CORE_ID] != NULL_PTR)
  {
    LpSchedWatchdog = Os_GpSchedWatchdog[OS_CORE_ID];

    do
    {
      LpSchedWatchdog->pStaticTask->pTask->blActivateAllowed =
                                                            OS_CAN_BE_ACTIVATED;
      LpSchedWatchdog->ddSchedTick = OS_ZERO;
      LpNextSchedWatchdog = LpSchedWatchdog;
      LpSchedWatchdog = LpSchedWatchdog->pNextSchedWatchdog;
      LpNextSchedWatchdog->pNextSchedWatchdog = NULL_PTR;
    } while ((LpSchedWatchdog != NULL_PTR) &&
                                     (LpSchedWatchdog->ddSchedTick == OS_ZERO));

    if (LpSchedWatchdog != NULL_PTR)
    {
      Os_StartTimer(OS_TIMEFRAME_WATCHDOG, LpSchedWatchdog->ddSchedTick);
    }
    else
    {
      Os_StopTimer(OS_TIMEFRAME_WATCHDOG);
    }
    Os_GpSchedWatchdog[OS_CORE_ID] = LpSchedWatchdog;
  } /* End of if (Os_GpSchedWatchdog[OS_CORE_ID] != NULL_PTR) */
  else
  {
    Os_StopTimer(OS_TIMEFRAME_WATCHDOG);
  }
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_TimeFrameHandler(void) */
#endif /* End of if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON)) */

/*******************************************************************************
** Function Name        : Os_StartAllLockMonitor                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is to start monitoring for all         **
**                        interrupt lock budget                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StartMonitor()                                   **
*******************************************************************************/
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_StartAllLockMonitor(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  if (
      #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
      (OS_NOT_IN_CAT1()) &&
      #endif
      ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
     )
  {
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Check if TP is configured for currently running object */
    if ((LpStaticTask != NULL_PTR)
                            && (LpStaticTask->pStaticTimProtection != NULL_PTR))
    {
      LddRequestedTime =
      LpStaticTask->pStaticTimProtection->ddAllInterruptLockTime;
      /* Check if All Interrupt Lock Budget is configured */
      if (LddRequestedTime != OS_ZERO)
      {
        /* Start monitoring for All Interrupt Lock Budget */
        Os_StartMonitor(LddRequestedTime, OS_ALL_INT_LOCK,
                                             OS_ALL_INT_LOCK_INDEX);
      }
    }
  }
  /* polyspace:end<MISRA-C3:18.1> */
}
#endif

/*******************************************************************************
** Function Name        : Os_StartOsLockMonitor                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is to start monitoring for OS          **
**                        interrupt lock budget                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StartMonitor()                                   **
*******************************************************************************/
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_StartOsLockMonitor(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  if (
      #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
      (OS_NOT_IN_CAT1()) &&
      #endif
      ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
     )
  {
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Check if TP is configured for currently running object */
    if ((LpStaticTask != NULL_PTR)
                            && (LpStaticTask->pStaticTimProtection != NULL_PTR))
    {
      LddRequestedTime =
        LpStaticTask->pStaticTimProtection->ddInterruptLockTime;
      /* Check if OS Interrupt Lock Budget is configured */
      if (LddRequestedTime != OS_ZERO)
      {
        /* Start monitoring for OS Interrupt Lock Budget */
        Os_StartMonitor(LddRequestedTime, OS_INT_LOCK, OS_INT_LOCK_INDEX);
      }
    }
  }
  /* polyspace:end<MISRA-C3:18.1> */
}
#endif

/*******************************************************************************
** Function Name        : Os_StopAllLockMonitor                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is to stop monitoring for all          **
**                        interrupt lock budget                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopIntMonitor()                                 **
*******************************************************************************/
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_StopAllLockMonitor(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  if (
      #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
      (OS_NOT_IN_CAT1()) &&
      #endif
      ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
     )
  {
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Check if TP is configured for currently running object */
    if ((LpStaticTask != NULL_PTR)
                            && (LpStaticTask->pStaticTimProtection != NULL_PTR))
    {
      /* Check if TP is configured for currently running object */
      LddRequestedTime =
        LpStaticTask->pStaticTimProtection->ddAllInterruptLockTime;
      /* Check if All interrupt Lock Budget is configured */
      if (LddRequestedTime != OS_ZERO)
      {
        /*Stop monitoring for All Interrupt Lock Budget*/
        Os_StopIntMonitor(LpStaticTask, OS_ALL_INT_LOCK_INDEX);
      }
    }
  }
  /* polyspace:end<MISRA-C3:18.1> */
}
#endif

/*******************************************************************************
** Function Name        : Os_StopOsLockMonitor                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is to stop monitoring for OS           **
**                        interrupt lock budget                               **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopIntMonitor()                                 **
*******************************************************************************/
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_StopOsLockMonitor(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  if (
      #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
      (OS_NOT_IN_CAT1()) &&
      #endif
      ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
     )
  {
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Check if TP is configured for currently running object */
    if ((LpStaticTask != NULL_PTR)
                            && (LpStaticTask->pStaticTimProtection != NULL_PTR))
    {
      LddRequestedTime =
        LpStaticTask->pStaticTimProtection->ddInterruptLockTime;
      /* Check if OS Interrupt Lock Budget is configured */
      if (LddRequestedTime != OS_ZERO)
      {
        /* Stop monitoring for OS Interrupt Lock Budget */
        Os_StopIntMonitor(LpStaticTask, OS_INT_LOCK_INDEX);
      }
    }
  }
  /* polyspace:end<MISRA-C3:18.1> */
}
#endif

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
/* polyspace:end<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE:OBAI:Not a defect:Justify with annotations> configured array index */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

