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
**  SRC-MODULE: Os_Interrupt.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Interrupt functionality.                         **
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
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
**           22-Dec-2015    MJ.Woo        Redmine #2591                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     14-Nov-2013    SH.Yoo,MJ.Woo CR: xar~179, TASK: xar~736          **
** 2.0.3     17-Sep-2013    SH.Yoo        CR: xar~172, TASK: xar~691          **
** 2.0.2     19-Aug-2013    SH.Yoo        CR: xar~168, TASK: xar~675          **
** 2.0.1     13-Aug-2013    MJ.Woo        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     17-Feb-2013    Son           Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */
#include "Os_Error.h"             /* Os Error header file */
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"  /* Os TimerProtection header file */
#endif
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Interrupt.h"         /* Os Interrupt header file */
#include "Os_Arch_Interrupt.h"
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if(OS_STACK_MONITORING == STD_ON)
#include "Os_Stack.h"
#endif
#include "Os_SystemCallTable.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Os_KernSuspendInterrupts                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function disables interrupts, implementing the **
**                        SuspendOSInterrupts(), SuspendAllInterrupts() and   **
**                        DisableAllInterrupts() system services.             **
**                        The type of lock is determined by the locktype      **
**                        parameter.                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : locktype                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GddISRLock, Os_GddISR2Lock, Os_GblISRLock,       **
**                        Os_GddOldSuspendOs, Os_GddOldSuspendAll,            **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_IntDisableConditional(), Os_StartMonitor(),      **
**                        Os_SuspendInterrupts(), Os_IntRestore()             **
*******************************************************************************/
FUNC(void, OS_CODE) Os_KernSuspendInterrupts(OsIntLockType locktype)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  Os_OldLevel_T *olp = NULL_PTR;   /* Pointer to Old level store */
  Os_IsrLockType *ncp = NULL_PTR;  /* Pointer to nesting counter */
  Os_IntStatus_T is;
  Os_IntStatus_T level = 0;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Here we manipulate the global old level/nesting counter variables. */
  if ( locktype == OS_LOCKTYPE_OS )
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* Operation is a no-op if nested inside SuspendAllInterrupts() or
     * DisableAllInterrupts() */
    if ( Os_GddISRLock[OS_CORE_ID] == OS_ZERO )
    {
      #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
      level = Os_CAT2_Max_Priority;
      #else
      level = OS_ONE;
      #endif
      olp = &Os_GddOldSuspendOs[OS_CORE_ID];
      ncp = &Os_GddISR2Lock[OS_CORE_ID];
    }
  }
  else if ( locktype == OS_LOCKTYPE_ALL )
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if ( Os_GblISRLock[OS_CORE_ID] == OS_FALSE )
    {
      level = OS_INT_MAX_PRIORITY;
      olp = &Os_GddOldSuspendAll[OS_CORE_ID];
      ncp = &Os_GddISRLock[OS_CORE_ID];
    }
  }
  else if ( locktype == OS_LOCKTYPE_NONEST )
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if ( (Os_GddISRLock[OS_CORE_ID] == OS_ZERO) &&
        (Os_GddISR2Lock[OS_CORE_ID] == OS_ZERO) )
    {
      #if (OS_ISR_COUNT != OS_PRE_ZERO)
      level = OS_INT_MAX_PRIORITY;
      #else
      level = OS_ONE;
      #endif
      olp = &Os_GddOldSuspendAll[OS_CORE_ID];
      ncp = &Os_GddISRLock[OS_CORE_ID];
    }
  }
  else
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > This is for exceptional case. But this code has already been verified and no impact of this rule violation */
  {
    /* Do nothing */
  }

  if ( ncp != NULL_PTR )
  {
    /* This branch actually does the job ...
     *
     * Interrupts disabled here to prevent a possible execution-time-
     * overrun interrupt from messing things up, especially if the
     * caller is a task.
     */
    is = Os_IntDisableConditional();

    if ( *ncp == 0 )
    {
      /* OS_SuspendInterrupts is a macro that doesn't
       * attempt to ensure that its parameters are only evaluated
       * once. That's OK here because the parameters are simple
       * variables, not expressions
       *
       * OS_SuspendInterrupts() disables OS interrupts in the
       * current context AND in the calling context.
       *
       * We don't need to worry about a Cat1 ISR interrupting us,
       * because SuspendOsInterrupts in Cat1 is a no-op.
       *
       * The saved interrupt state is not restored in this branch
       * because OS_SuspendInterrupts() sets the required
       * level.
       */
      *ncp = 1;

      if (locktype == OS_LOCKTYPE_NONEST)
      {
        Os_GblISRLock[OS_CORE_ID] = OS_TRUE;
      }

      #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
      if (
          #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
          (OS_NOT_IN_CAT1()) &&
          #endif
          ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
         )
      {
        LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
        /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
        /* Check if TP is configured for currently running object */
        /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
        if (LpStaticTask->pStaticTimProtection != NULL_PTR)
        {
          #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
          if (locktype == OS_LOCKTYPE_OS)
          {
            LddRequestedTime =
              /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
              LpStaticTask->pStaticTimProtection->ddInterruptLockTime;
            /* Check if OS Interrupt Lock Budget is configured */
            if (LddRequestedTime != OS_ZERO)
            {
              /* Start monitoring for OS Interrupt Lock Budget */
              Os_StartMonitor(LddRequestedTime, OS_INT_LOCK, OS_INT_LOCK_INDEX);
            }
          }
          else
          #endif
          {
            LddRequestedTime =
              /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
              LpStaticTask->pStaticTimProtection->ddAllInterruptLockTime;
            /* Check if All Interrupt Lock Budget is configured */
            if (LddRequestedTime != OS_ZERO)
            {
              /* Start monitoring for All Interrupt Lock Budget */
              Os_StartMonitor(LddRequestedTime, OS_ALL_INT_LOCK,
                                                         OS_ALL_INT_LOCK_INDEX);
            }
          }
        } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
        /* polyspace:end<MISRA-C3:18.1> */
      }
      #endif /* End of if ((OS_ALLINTLOCK_TP_EB == STD_ON)
              * || (OS_INTLOCK_TP_EB == STD_ON)) */

      Os_SuspendInterrupts(olp, level);
    }
    else if (*ncp < (Os_IsrLockType)OS_SUSPENDNESTLIMIT)
    {
      /* No need to restore the interrupt state here - they remain blocked
       * at the expected level. */
      (*ncp)++;
    }
    else
    {
      Os_IntRestore(is);
    }
  }
  #endif
/* End of #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON)) */
}

/*******************************************************************************
** Function Name        : Os_KernResumeInterrupts                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Implements the ResumeOSInterrupts(),                **
**                        ResumeAllInterrupts() and EnableAllInterrupts()     **
**                        services. The type of interrupt locking             **
**                        being resumed is given by the locktype parameter.   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : locktype                                            **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GddISRLock, Os_GddISR2Lock, Os_GblISRLock,       **
**                        Os_GddOldSuspendOs, Os_GddOldSuspendAll,            **
**                        Os_GpStaticTask, Os_GusCallevelCheck                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_IntDisableConditional(), Os_StopIntMonitor(),    **
**                        Os_ResumeInterrupts(), Os_IntRestore()              **
*******************************************************************************/
FUNC(void, OS_CODE) Os_KernResumeInterrupts(OsIntLockType locktype)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  Os_OldLevel_T *olp = NULL_PTR;   /* Pointer to Old level store */
  Os_IsrLockType *ncp = NULL_PTR;  /* Pointer to nesting counter */
  Os_IntStatus_T is;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  TickType LddRequestedTime;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Here we manipulate the global old level/nesting counter variables. */
  if ( locktype == OS_LOCKTYPE_OS )
  {
    /* Operation is a no-op if nested inside SuspendAllInterrupts() or
     * DisableAllInterrupts() */
    if ( Os_GddISRLock[OS_CORE_ID] == 0 )
    {
      olp = &Os_GddOldSuspendOs[OS_CORE_ID];
      ncp = &Os_GddISR2Lock[OS_CORE_ID];
    }
  }
  else if ( locktype == OS_LOCKTYPE_ALL )
  {
    if ( Os_GblISRLock[OS_CORE_ID] == OS_FALSE )
    {
      olp = &Os_GddOldSuspendAll[OS_CORE_ID];
      ncp = &Os_GddISRLock[OS_CORE_ID];
    }
  }
  else if ( locktype == OS_LOCKTYPE_NONEST )
  {
    if ( Os_GblISRLock[OS_CORE_ID] != OS_FALSE )
    {
      olp = &Os_GddOldSuspendAll[OS_CORE_ID];
      ncp = &Os_GddISRLock[OS_CORE_ID];
    }
  }
  else
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > This is for exceptional case. But this code has already been verified and no impact of this rule violation */
  {
    /* Do nothing */
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  if ( ncp != NULL_PTR )
  {
    /* This branch actually does the job ... */
    is = Os_IntDisableConditional();

    if ( *ncp == 1 )
    {
      #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
      if (
          #if (OS_CAT1_ISR_COUNT != OS_PRE_ZERO)
          (OS_NOT_IN_CAT1()) &&
          #endif
          ((Os_GusCallevelCheck[OS_CORE_ID] & (OS_CONTEXT_HOOK)) == OS_ZERO)
         )
      {
        LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
        /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> poinrter indicates pre-defined range */
        /* Check if TP is configured for currently running object */
        /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
        if (LpStaticTask->pStaticTimProtection != NULL_PTR)
        {
          #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
          if (locktype == OS_LOCKTYPE_OS)
          {
            LddRequestedTime =
              /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
              LpStaticTask->pStaticTimProtection->ddInterruptLockTime;
            /* Check if OS Interrupt Lock Budget is configured */
            if (LddRequestedTime != OS_ZERO)
            {
              /* Stop monitoring for OS Interrupt Lock Budget */
              Os_StopIntMonitor(LpStaticTask, OS_INT_LOCK_INDEX);
            }
          }
          else
          #endif
          {
            LddRequestedTime =
              /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
              LpStaticTask->pStaticTimProtection->ddAllInterruptLockTime;
            /* Check if All interrupt Lock Budget is configured */
            if (LddRequestedTime != OS_ZERO)
            {
              /*Stop monitoring for All Interrupt Lock Budget*/
              Os_StopIntMonitor(LpStaticTask, OS_ALL_INT_LOCK_INDEX);
            }
          }
        } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
        /* polyspace:end<MISRA-C3:18.1> */
      }
      #endif /* End of if ((OS_ALLINTLOCK_TP_EB == STD_ON)
              * || (OS_INTLOCK_TP_EB == STD_ON)) */

      /* Os_ResumeInterrupts is a macro that doesn't
       * attempt to ensure that its parameters are only evaluated
       * once. That's OK here because the parameters are simple
       * variables, not expressions
       */
      *ncp = 0;

      if (locktype == OS_LOCKTYPE_NONEST)
      {
        Os_GblISRLock[OS_CORE_ID] = OS_FALSE;
      }

      Os_ResumeInterrupts(olp);

      /* We do not restore interrupts here because
       * Os_ResumeInterrupts() has set the level correctly
       */
    }
    else if ( (locktype != OS_LOCKTYPE_NONEST) && (*ncp != 0) )
    {
      (*ncp)--;

      /* No need to restore here - already at the correct level */
    }
    else
    {
      Os_IntRestore(is);
    }
  }
  #endif
  /* End of #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON)) */
}

/*******************************************************************************
** Function Name        : Os_KernGetISRID                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to return the Id of the ISR    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : void                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : ISRType                                             **
**                                                                            **
** Preconditions        : StartOS() function should be called.                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpStaticTask                                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
FUNC(ISRType, OS_CODE) Os_KernGetISRID(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  ISRType LddISRValue;
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Initialize variable */
  LddISRValue = OS_INVALID_VALUE;
  /* Set Return status to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETISRID, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Store the global pointer to static task in local variable */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];

    /* check whether the type of task is ISR */
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpStaticTask->usType == OS_ISR2)
    {
      /*Store the ID of the task in the local variable */
      /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LddISRValue = LpStaticTask->ddTaskId;
    }
  } /* End of if (LenStatusReturn == E_OK) */
  /* Return the value */
  return (LddISRValue);
} /* End of GetISRID(void) */
#endif /* End of if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
