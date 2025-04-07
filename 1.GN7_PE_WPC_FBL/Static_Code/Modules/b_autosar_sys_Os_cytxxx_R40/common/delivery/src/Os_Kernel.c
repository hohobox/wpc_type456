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
**  SRC-MODULE: Os_Kernel.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Kernel functionality                             **
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
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.9     11-Jan-2021    YH.Han        Redmine #27622                      **
** 2.6.8     25-Nov-2020    JH.Cho        Redmine #26808                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     18-Dec-2019    SH.Yoo        Redmine #13546, #16219, #20339      **
** 2.5.0     14-Jun-2018    SH.Yoo        Redmine #13026                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025, #12132              **
** 2.4.2     13-Mar-2018    MJ.Woo        Redmine #10875                      **
** 2.4.1     18-Sep-2017    MJ.Woo        Redmine #9786                       **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #9530                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #8276, #9148                **
** 2.3.0     28-Mar-2017    SH.Yoo        Redmine #5967                       **
**           23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.1.1     10-Jan-2017    MJ.Woo        Redmine #7216                       **
** 2.1.0     05-Oct-2016    SH.Yoo        Redmine #5866                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4592, #5368                **
** 2.0.12    26-Apr-2016    JH.Lee        Redmine #4295                       **
** 2.0.11    16-Feb-2016    JH.Lee,MJ.Woo Redmine #3963                       **
** 2.0.10    09-Dec-2015    SH.Yoo        Redmine #3140                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
**           26-Mar-2015    MJ.Woo        Redmine #2381                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.3     16-Sep-2013    SH.Yoo        CR: xar~172, TASK: xar~691          **
** 2.0.2     11-Sep-2013    SH.Yoo        CR: xar~168, TASK: xar~675          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.1     13-Aug-2013    SH.Yoo        CR: xar~160, TASK: xar~655          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:begin<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Stack.h"             /* Os Stack header file */
#include "Os_Resource.h"          /* Os Resource header file */
#include "Os_Task.h"              /* Os Task header file */
#include "Os_Alarm.h"             /* Os Alarm header file */
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h" /* Os TimerProtection header file */
#endif
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Error.h"             /* Os Error header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Interrupt.h"         /* Os Interrupt header file */
#include "Os_Arch_Interrupt.h"
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
#endif
#if (OS_PROTECTION_HOOK == STD_ON)
#include "Os_Shutdown.h"
#endif
#if (OS_SAFETY_KERNEL == STD_ON)
#include "Os_SK_Controller.h"
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

#if (OS_TASK == STD_ON)
static FUNC(void, OS_CODE) Os_InitOS(void);
#endif
#if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
static FUNC(void, OS_CODE) Os_RunISR(void);
#endif

/*******************************************************************************
** Function Name        : Os_InsertTask                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to put a new task in link list **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
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
**                        Os_GpLinkTask                                       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_InsertTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                         OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpCurrentLink;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpNextLink;
  #if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
  uint32 taskLinkIndex;
  #endif

  #if (OS_MULTICORE == STD_ON)
  /* Take Os_GpLinkTask in local variable */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  LpCurrentLink = Os_GpLinkTask[LpStaticTask->ddCoreId];
  #else
  LpCurrentLink = Os_GpLinkTask[OS_ZERO];
  #endif

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Insert task in queue */
  OS_INSERT_TASK_IN_QUEUE();
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Point to next link list */
  LpNextLink = LpCurrentLink->pLinkList;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check if Next list is not a NULL_PTR and it's priority is greater than
   *   the task priority */
  while ((LpNextLink != NULL_PTR) &&
                             (LpNextLink->ulPriority >= LpLinkTask->ulPriority))
  {
    /* Point to next link list */
    LpCurrentLink = LpNextLink;

    /* Update LpNextLink */
    LpNextLink = LpCurrentLink->pLinkList;
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  /* Insert task in link list */
  LpCurrentLink->pLinkList = LpLinkTask;
  /* Update Next link list for the current task */
  LpLinkTask->pLinkList = LpNextLink;
} /* End of Os_InsertTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   * OS_CONST) LpStaticTask) */

/*******************************************************************************
** Function Name        : Os_InsertPreemptedTask                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to put a preempted task        **
**                        in link list                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
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
**                        Os_GpLinkTask                                       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_InsertPreemptedTask
                 (P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpCurrentLink;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpNextLink;
  #if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
  uint32 taskLinkIndex;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  #if (OS_MULTICORE == STD_ON)
  /* Take Os_GpLinkTask in local variable */
  LpCurrentLink = Os_GpLinkTask[LpStaticTask->ddCoreId];
  #else
  LpCurrentLink = Os_GpLinkTask[OS_ZERO];
  #endif
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  /* Get task in queue */
  #if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
  if (LpStaticTask->ucMaxActivateCount == OS_ONE)
  {
    LpLinkTask = LpStaticTask->pLinkTask;
  }
  else
  {
    taskLinkIndex = Os_GaaLinkIndex[LpStaticTask->ddTaskId];

    if (taskLinkIndex >= LpStaticTask->pTask->ucActivateCount)
    {
      taskLinkIndex -= LpStaticTask->pTask->ucActivateCount;
    }
    else
    {
      /* Intended code:
      taskLinkIndex = LpStaticTask->ucMaxActivateCount -
                      (LpStaticTask->pTask->ucActivateCount - taskLinkIndex); */
      /* Equivalent code: */
      taskLinkIndex += (LpStaticTask->ucMaxActivateCount -
                                          LpStaticTask->pTask->ucActivateCount);
    }
    /* polyspace +2 MISRA-C3:18.4 [Not a defect:Medium] "Pointer arithmetic used to achieve better throughput." */
    LpLinkTask = LpStaticTask->pLinkTask + taskLinkIndex;
  }
  #else
  LpLinkTask = LpStaticTask->pLinkTask;
  #endif
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Point to next link list */
  LpNextLink = LpCurrentLink->pLinkList;
  /* Check if Next list is not a NULL_PTR and it's priority is greater than
   *   the task priority */
  while ((LpNextLink != NULL_PTR) &&
                             (LpNextLink->ulPriority > LpLinkTask->ulPriority))
  {
    /* Point to next link list */
    LpCurrentLink = LpNextLink;
    /* Update LpNextLink */
    LpNextLink = LpCurrentLink->pLinkList;
  }

  /* Insert task in link list */
  LpCurrentLink->pLinkList = LpLinkTask;
  /* Update Next link list for the current task */
  LpLinkTask->pLinkList = LpNextLink;
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
}

/*******************************************************************************
** Function Name        : Os_ScheduleService                                  **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : This service causes scheduling of a  task,          **
**                        if previous task is terminated or pre-empted and    **
**                        updates the task link list if needed                **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GpStaticTask, Os_GpLinkTask                      **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ReleaseInternalResource(),                       **
**                        Os_RunTask(),Os_CheckStack(),                       **
**                        Os_StopExecutionBudget(),Os_PauseTimingProtection(),**
**                        Os_TaskTerminationHook()                            **
*******************************************************************************/
FUNC(void, OS_CODE) Os_ScheduleService(void)
{
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_TASK_TP_EB == STD_ON)
  TickType LddRequestedTime;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  LpStaticTask = Os_GpStaticTask[OS_CORE_ID];

  #if (OS_STACK_MONITORING == STD_ON)
  /* Call function to check Stack if it overflows */
  Os_CheckStack(LpStaticTask);
  #endif /* OS_STACK_MONITORING */
  /* Store current task in local variable */
  LpTask = LpStaticTask->pTask;

  #if (OS_TASK_TP_EB == STD_ON)

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
  /* Check if timing protection is configured for the currently running Task */
  if (LpStaticTask->pStaticTimProtection != NULL_PTR)
  {
    LddRequestedTime = LpStaticTask->pStaticTimProtection->ddExecutionBudget;

    /* Check if Execution Budget is configured */
    if (LddRequestedTime != OS_ZERO)
    {
      /* Check if the task is to be terminated or waiting */
      if ((LpTask->ddState == DYING) || (LpTask->ddState == WAITING))
      {
        /* Stop the execution budget monitoring */
        Os_StopExecutionBudget(LpStaticTask);
      }
      else
      {
        /* Call a function to Pause Execution budget */
        Os_PauseTimingProtection();
      }
    } /* End of if (LddRequestedTime != OS_ZERO) */
  } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
  /* polyspace:end<MISRA-C3:18.1> */
  #endif /* End of if (OS_TASK_TP_EB == STD_ON) */

  /* Check if the task is not in ready state */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if (LpTask->ddState >= WAITING)
  {
    /* Check if the task is to be terminated */
    if (LpTask->ddState == DYING)
    {
      #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
      /* Release internal resource */
      Os_ReleaseInternalResource(LpStaticTask);
      #endif

      #if (OS_EVENT == STD_ON)
      /* If the object is an EXTENDED task, initialize the events */
      if (LpStaticTask->usType == OS_TASK_EXTENDED)
      {
        /* Set ddEventSet to ZERO */
        LpTask->ddEventSet = OS_ZERO;
        /* Set ddEventWait to ZERO */
        LpTask->ddEventWait = OS_ZERO;
      } /* End of if (LpStaticTask->ucType == OS_TASK_EXTENDED) */
      #endif /* End of if (OS_EVENT == STD_ON) */

      /* Decrement Activate count by one */
      LpTask->ucActivateCount--;

      /* Check if Task needs to be activated again */
      if (LpTask->ucActivateCount != OS_ZERO)
      {
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskTerminationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif
        /* Change state of the task to OS_READY_AND_NEW */
        LpTask->ddState = OS_READY_AND_NEW;
      }
      else
      {
        /* Change the state to SUSPENDED */
        LpTask->ddState = SUSPENDED;
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskTerminationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif
      }
    } /* End of if (LpTask->ddState == DYING) */
    /* Update Os_GpLinkTask with next task */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    Os_GpLinkTask[OS_CORE_ID] = Os_GpLinkTask[OS_CORE_ID]->pLinkList;
  } /* End of if (LpTask->ddState >= WAITING) */
  /* NOTE: Os_RunTask() separately executed later.
   * Call Os_RunTask function to put task in Running mode */
} /* End of Os_ScheduleService(void) */

/*******************************************************************************
** Function Name        : Os_KernSchedule                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service checks if a higher-priority task is    **
**                        ready, the internal resource of the task is released**
**                        the current task is put into the ready state        **
**                        and the higher-priority task is executed. Otherwise **
**                        the calling task is continued.                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpStaticTask, Os_GpLinkTask                      **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetInternalResource()                            **
**                        Os_InsertPreemptedTask(), Os_TaskPreemptionHook(),  **
**                        Os_ReleaseInternalResource(), Os_ScheduleService()  **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSchedule(void)
{
  #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpNextLink;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #endif
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SCHEDULE, LenStatusReturn);
  /* Check we are at the task level */
  OS_CHECK_TASK_CALL_LEVEL_ERROR(LenStatusReturn);
  /* Check the task does not own a resource */
  OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> status check */
  /* Check the task does not own a spinlock */
  OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */

  /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> status check */
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Release the internal resource */
    Os_ReleaseInternalResource(LpStaticTask);
    /* Take next link list in local variable */
    LpNextLink = Os_GpLinkTask[OS_CORE_ID]->pLinkList;

    /* Check if the task needs to be */
    if (LpNextLink->ulPriority > Os_GpLinkTask[OS_CORE_ID]->ulPriority)
    {
      #if (OS_POSTTASK_HOOK == STD_ON)
      /* Process PostTaskHook */
      OS_PROCESS_POSTTASKHOOK();
      #endif
      /* Update Os_GpLinkTask */
      Os_GpLinkTask[OS_CORE_ID] = LpNextLink;
      /* Insert the preempted task */
      Os_InsertPreemptedTask(LpStaticTask);
      Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = READY;
      #if (OS_PROFILING_HOOK == STD_ON)
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      Os_TaskPreemptionHook(OS_CORE_ID, Os_GpStaticTask[OS_CORE_ID]->ddTaskId);
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      #endif

      /* Call Function to switch context with new task */
      Os_ScheduleService();
      OS_SAVECONTEXT();
    } /* End of if (LpNextLink->ulPriority >
       *Os_GpLinkTask[OS_CORE_ID]->ulPriority) */
    /* Get the internal resource */
    Os_GetInternalResource(Os_GpStaticTask[OS_CORE_ID]);
    #endif /* End of if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO) */
  } /* End of if (LenStatusReturn == E_OK) */
  /* polyspace-end<RTE:UNR> */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Lock the task or ISR */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    OS_STORE_SERVICE(OSServiceId_Schedule);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* polyspace:end<MISRA-C3:18.1> */
  /* Return the value */
  return (LenStatusReturn);
} /* End of Schedule(void) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ScheduleFromChain                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function does the scheduling when called from  **
**                        a dying object, and when same object is to be       **
**                        inserted again                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GpStaticTask, Os_GpLinkTask                      **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_CheckStack, PostTaskHook, Os_InsertTask          **
**                        Os_StopExecutionBudget, Os_ReleaseInternalResource, **
**                        Os_TaskTerminationHook(), Os_TaskActivationHook()   **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(void, OS_CODE) Os_ScheduleFromChain(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_TASK_TP_EB == STD_ON)
  TickType LddRequestedTime;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Get the pointer to current running task */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> boundary is limited to pre-defined range */
  LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
  /* polyspace:end<MISRA-C3:18.1:Not a defect:Justify with annotations> boundary is limited to pre-defined range */

  #if (OS_STACK_MONITORING == STD_ON)
  /* Call function to check Stack if it overflows */
  Os_CheckStack(LpStaticTask);
  #endif
  #if (OS_POSTTASK_HOOK == STD_ON)
  /* Process PostTaskHook */
  OS_PROCESS_POSTTASKHOOK();
  #endif
  #if (OS_TASK_TP_EB == STD_ON)

  /* Check if timing protection is configured for the currently running Task */
  if (LpStaticTask->pStaticTimProtection != NULL_PTR)
  {
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
    LddRequestedTime = LpStaticTask->pStaticTimProtection->ddExecutionBudget;
    /* polyspace:end<MISRA-C3:18.1> */

    /* Check if Execution Budget is configured */
    if (LddRequestedTime != OS_ZERO)
    {
      /* Stop the execution budget monitoring */
      Os_StopExecutionBudget(LpStaticTask);
    }
  } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
  #endif /* End of if (OS_TASK_TP_EB == STD_ON) */

  #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
  /* Release internal resource */
  Os_ReleaseInternalResource(LpStaticTask);
  #endif

  /* polyspace-begin MISRA-C3:18.1 [Not a defect:Medium] "ptr points to a valid value and code is verified manually" */
  #if (OS_PROFILING_HOOK == STD_ON)
  LpStaticTask->pTask->ddState = SUSPENDED;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
  Os_TaskTerminationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
  #endif
  /* Make state of the Task to READY and NEW*/
  LpStaticTask->pTask->ddState = OS_READY_AND_NEW;
  #if (OS_PROFILING_HOOK == STD_ON)
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
  Os_TaskActivationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
  #endif
  if (Os_GpLinkTask[OS_CORE_ID]->ulPriority <=
                               Os_GpLinkTask[OS_CORE_ID]->pLinkList->ulPriority)
  {
    Os_GpLinkTask[OS_CORE_ID] = Os_GpLinkTask[OS_CORE_ID]->pLinkList;
    /* Put a new executable object in the ready executable object list */
    Os_InsertTask(LpStaticTask);
  }
  /* polyspace-end MISRA-C3:18.1 */
} /* End of Os_ScheduleFromChain(void) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_RunTask                                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to put new task in Running mode**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GpLinkTask, Os_GddAppId,                         **
**                        Os_GaaStaticTask, Os_GpStaticTask                   **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ReInitContext(), Os_StartMonitor()               **
**                        Os_GetInternalResource(), Os_HandleMemoryBlock()    **
**                        Os_SwitchMemoryPartition(), Os_TaskRunningHook(),   **
**                        Os_ContinueTimingProtection(), Os_RunISR()          **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(void, OS_CODE) Os_RunTask(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  #if (OS_TASK_TP_EB == STD_ON)
  TickType LddRequestedTime;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Take the Static task into local pointer */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpStaticTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  /* Update the currently running task */
  Os_GpStaticTask[OS_CORE_ID] = LpStaticTask;

  #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if (LpStaticTask->usType != OS_ISR2)
  #endif
  {

    /* Take the task into local pointer */
    LpTask = LpStaticTask->pTask;

    /* Check if State is in OS_READY_AND_NEW state */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpTask->ddState == OS_READY_AND_NEW)
    {
      #if (OS_EVENT == STD_ON)
      /* If the object is an EXTENDED task, initialize the events */
      if (LpStaticTask->usType == OS_TASK_EXTENDED)
      {
        /* Set ddEventSet to ZERO */
        LpTask->ddEventSet = OS_ZERO;
        /* Set ddEventWait to ZERO */
        LpTask->ddEventWait = OS_ZERO;
      } /* End of if (LpStaticTask->ucType == OS_TASK_EXTENDED) */
      #endif /* End of if (OS_EVENT == STD_ON) */
      /* Re-Initialize the context for task */
      Os_ReInitContext(LpStaticTask);
    } /* End of if (LpTask->ddState == OS_READY_AND_NEW) */

    #if (OS_TASK_TP_EB == STD_ON)
    /* Check if State is in OS_READY_AND_NEW or OS_READY_AND_WAITING state */
    if ((LpTask->ddState == OS_READY_AND_NEW)
    		                          || (LpTask->ddState == OS_READY_AND_WAITING))
    {
      /* Check if timing protection is configured for currently running object */
      if (LpStaticTask->pStaticTimProtection != NULL_PTR)
      {
        /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
        /* Save execution budget time in a local */
        LddRequestedTime = LpStaticTask->pStaticTimProtection->ddExecutionBudget;
        /* polyspace:end<MISRA-C3:18.1> */

        /* Check if Execution Budget is configured */
        if (LddRequestedTime != OS_ZERO)
        {
          /* Invoke the fuction Os_StartMoniter */
          Os_StartMonitor(LddRequestedTime, OS_EXEC_BUDGET,
              LpStaticTask->pStaticTimProtection->ucTaskExeBudgetIndex);
        }
      } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
    } /* End of if (LpTask->ddState == OS_READY_AND_NEW || ... */
    else
    {
      /* Check if timing protection is configured for currently running object */
      if (LpStaticTask->pStaticTimProtection != NULL_PTR)
      {
        /* Continue Execution budget */
        Os_ContinueTimingProtection(LpStaticTask);
      }
    } /* End of else */
    #endif /* End of if (OS_TASK_TP_EB == STD_ON) */
    #if (OS_MEMORY_PROTECTION == STD_ON)
    #if (OS_APP_MEMBLK_CNT != OS_ZERO)
    #if (OS_SAFETY_KERNEL == STD_ON)
    /* Check if Application is non -trusted */
    if (LpStaticTask->ddAppId < Os_Trusted_Start_Indx)
    {
      /* Invoke function Os_HandleMemoryBlock */
      Os_SwitchMemoryPartition(LpStaticTask->ddTaskId);
    }
    #else
    Os_HandleMemoryBlock(LpStaticTask);
    #endif
    #endif /* End of if (OS_APP_MEMBLK_CNT != OS_ZERO) */
    #endif /* End of if (OS_MEMORY_PROTECTION == STD_ON) */
    /* Update the currently running Application */
    #if(OS_APPLICATION == STD_ON)
    Os_GddAppId[OS_CORE_ID] = LpStaticTask->ddAppId;
    #endif
    #if (OS_PROFILING_HOOK == STD_ON)
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    Os_TaskRunningHook(OS_CORE_ID, LpStaticTask->ddTaskId, LpTask->ddState);
    /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    #endif
    /* Make state of task as RUNNING */
    LpTask->ddState = RUNNING;
    #if (OS_PRETASK_HOOK == STD_ON)
    /* Process PreTaskHook */
    OS_PROCESS_PRETASKHOOK();
    #endif
    #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
    /* Get internal Resource */
    Os_GetInternalResource(LpStaticTask);
    #endif
  }
  #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
  else
  {
    Os_RunISR();
  }
  #endif
} /* End of Os_RunTask(void) */
#endif /* End of if (OS_TASK == STD_ON) */


/*******************************************************************************
** Function Name        : Os_RunISR                                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to restart ISR                 **
**                        in OS-ApplicationRunning mode                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GpLinkTask, Os_GddAppId,                         **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_HandleMemoryBlock()                              **
**                        Os_SwitchMemoryPartition()                          **
**                        Os_ContinueTimingProtection()                       **
*******************************************************************************/
#if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
static FUNC(void, OS_CODE) Os_RunISR(void)
{
  #if ((OS_ISR_TP_EB == STD_ON) || (OS_APPLICATION == STD_ON) || \
       (OS_MEMORY_PROTECTION == STD_ON))
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  #if ((OS_ISR_TP_EB == STD_ON) || (OS_APPLICATION == STD_ON) || \
       (OS_MEMORY_PROTECTION == STD_ON))
  /* Take the Static task into local pointer */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpStaticTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  #endif

  #if (OS_ISR_TP_EB == STD_ON)
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
  /* Check if timing protection is configured for currently running object */
  if (LpStaticTask->pStaticTimProtection != NULL_PTR)
  {
    /* Continue Execution budget */
    Os_ContinueTimingProtection(LpStaticTask);
  }
  /* polyspace:end<MISRA-C3:18.1> */
  #endif /* End of if (OS_ISR_TP_EB == STD_ON) */

  /* Update the currently running Application */
  #if(OS_APPLICATION == STD_ON)
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  Os_GddAppId[OS_CORE_ID] = LpStaticTask->ddAppId;
  #endif

  #if (OS_MEMORY_PROTECTION == STD_ON)
  #if (OS_APP_MEMBLK_CNT != OS_ZERO)
  /* Check if Application is non -trusted */
  if (Os_GddAppId[OS_CORE_ID] < (ApplicationType)Os_Trusted_Start_Indx)
  {
    /* Invoke function Os_SwitchMemoryPartition or Os_HandleMemoryBlock */
    #if (OS_SAFETY_KERNEL == STD_ON)
    Os_SwitchMemoryPartition(LpStaticTask->ddTaskId);
    #else
    Os_HandleMemoryBlock(LpStaticTask);
    #endif
  }
  #endif /* End of if (OS_APP_MEMBLK_CNT != OS_ZERO) */
  #endif /* End of if (OS_MEMORY_PROTECTION == STD_ON) */
} /* End of Os_RunISR(void) */
#endif

/*******************************************************************************
** Function Name        : Os_InitOS                                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called from StartOS().It autostarts**
**                        task, alarm or scheduletable if configured.         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GaaApplMode, Os_GaaAlarm, Os_GddAppMode          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ActivateTaskService(), Os_InsertAlarm()          **
*******************************************************************************/
#if ((OS_TASK == STD_ON) || (OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
static FUNC(void, OS_CODE) Os_InitOS(void)
{
  #if (OS_ALARM == STD_ON)
  P2CONST(Tdd_Os_AutoStartAlarm, AUTOMATIC, OS_CONST) LpAutoStartAlarm;
  #endif
  #if (OS_TASK == STD_ON)
  P2CONST(Tdd_Os_AutoStartTask, AUTOMATIC, OS_CONST) LpAutoStartTask;
  #endif
  #if (OS_SCHEDTABLE == STD_ON)
  P2CONST(Tdd_Os_AutoStartSchedTable, AUTOMATIC, OS_CONST)
  LpAutoStartSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  #endif
  uint32 autoStartCount;
  AppModeType LddMode;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Save Application mode into local variable */
  LddMode = Os_GddAppMode;
  #if (OS_TASK == STD_ON)
  /* Take  Autostart task count in local variable */
  autoStartCount = Os_GaaApplMode[LddMode].ddNoOfAutoStartTask;

  /* Check if count is zero */
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if (autoStartCount != OS_ZERO)
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
  {
    /* Get the pointer to first task */
    LpAutoStartTask = Os_GaaApplMode[LddMode].pAutoStartTask;

    do
    {
      #if (OS_MULTICORE == STD_ON)

      if (LpAutoStartTask->pStaticTask->ddCoreId == OS_CORE_ID)
      #endif
      {
        /* Each AUTOSTART task is activated   */
        (void)Os_ActivateTaskService(LpAutoStartTask->pStaticTask);
      }
      /* Point to next task */
      /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
      LpAutoStartTask++;
      /* Decrement count */
      autoStartCount--;
      /* Check if Autostart tasks exists */
    } while (autoStartCount != OS_ZERO);
  } /* End of if (autoStartCount != OS_ZERO) */
  #endif /* End of if (OS_TASK == STD_ON) */

  #if (OS_ALARM == STD_ON)
  /* Take  Autostart Alarm count in local variable */
  autoStartCount = Os_GaaApplMode[LddMode].ddNoOfAutoStartAlarm;

  /* Check if count is zero */
  /* polyspace:begin<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if (autoStartCount != OS_ZERO)
  {
    /* Get the pointer to first Alarm */
    LpAutoStartAlarm = Os_GaaApplMode[LddMode].pAutoStartAlarm;

    do
    {
      #if (OS_MULTICORE == STD_ON)

      if (LpAutoStartAlarm->pAlarm->ddCoreId == OS_CORE_ID)
      #endif
      {
        /* Each AUTOSTART Alarm is activated   */
        Os_InsertAlarm(LpAutoStartAlarm->pAlarm);
        /* Note: Alarm is not made active by default because it needs to be
         *   active only for the requested Appmode. Thus make the Alarm Active
         * */
        LpAutoStartAlarm->pAlarm->ucAlarmState = OS_ALARM_ACTIVE;
      }
      /* Point to next alarm */
      /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
      LpAutoStartAlarm++;
      /* Decrement count */
      autoStartCount--;
      /* Check if Autostart alarm exists */
    } while (autoStartCount != OS_ZERO);
  } /* End of if (autoStartCount != OS_ZERO) */
  #endif /* End of if (OS_ALARM == STD_ON) */
  /* polyspace:end<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  #if (OS_SCHEDTABLE == STD_ON)
  /* Take  Autostart ScheduleTable count in local variable */
  autoStartCount = Os_GaaApplMode[LddMode].ddNoOfAutoStartSchedTable;

  /* Check if count is zero */
  if (autoStartCount != OS_ZERO)
  {
    /* Get the pointer to first task */
    LpAutoStartSchedTable = Os_GaaApplMode[LddMode].pAutoStartSchedTable;

    do
    {
      /* Point to the respected alarm for the scheduleTable */
      LpAlarm =
        &Os_GaaAlarm[LpAutoStartSchedTable->pStaticSchedTable->ddAlarmIndex];
      #if (OS_MULTICORE == STD_ON)

      if (LpAlarm->ddCoreId == OS_CORE_ID)
      #endif
      {
        /* Insert the alarm */
        Os_InsertAlarm(LpAlarm);
        /* Note: Alarm is not made active by default because it needs to be
         *   active only for the requested Appmode. Thus make the Alarm Active
         * */
        LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
      }
      /* Point to next ScheduleTable */
      LpAutoStartSchedTable++;
      /* Decrement count */
      autoStartCount--;
      /* Check if Autostart ScheduleTable exists */
    } while (autoStartCount != OS_ZERO);
  } /* End of if (autoStartCount != OS_ZERO) */
  #endif /* End of if (OS_SCHEDTABLE == STD_ON) */
} /* End of Os_InitOS(void) */
#endif /* End of if ((OS_TASK == STD_ON) || (OS_ALARM == STD_ON) ||
        *(OS_SCHEDTABLE == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_Sleep
 *
 * Service ID           : NA
 *
 * Description          : This function represents the idle task
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_IdleEntryHook(), Os_Idle(),
 *                        Os_IdleExitHook()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_Sleep(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace<RTE : NTL :Not a defect:Justify with annotations> Infinite loop is intended instruction for sleep. */
  while (OS_ONE)
  {
    #if (OS_PROFILING_HOOK == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> used for future job */
    Os_IdleEntryHook(OS_CORE_ID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif

    /* Go into idle mode */
    Os_Idle(OS_CORE_ID);

    #if (OS_PROFILING_HOOK == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> used for future job */
    Os_IdleExitHook(OS_CORE_ID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
  }
} /* End of Os_Sleep(void) */

/*******************************************************************************
** Function Name        : Os_KernStartOS                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to start the Os             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : AppModeType Mode                                    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GblAppModeCheck, Os_GddAppMode, Os_GpStaticTask, **
**                        Os_GpSchedWatchdog, Os_GpLinkTask, Os_GaaLinkTask,  **
**                        Os_GucActivateCore, Os_GaaStaticTask,               **
**                        Os_GaaRunningWdg, Os_GblStartOS, Os_GaaCore,        **
**                        Os_GaaStaticMemBlock, Os_GddFaultyTask,             **
**                        Os_GblOsInitialized,                                **
**                        Os_GaaStaticAppHook, Os_GaaApplication              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SetISRPriority(), StartupHook(),                 **
**                        Os_SetSyncFirst(), Os_ReleaseSpinlock(),            **
**                        Os_InitTimer(), Os_InitOS(), Os_SetSyncSecond(),    **
**                        Os_GetSpinlock(), Os_InitMessageQueue(),            **
**                        Os_TaskActivationHook(),                            **
**                        Os_InitializeDedicatedMemBlock()                    **
*******************************************************************************/
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
FUNC(void, OS_CODE) Os_KernStartOS(AppModeType Mode)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_APPLICATION == STD_ON)
  ApplicationType LucAppCount;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  StatusType LblErrorMode;
  #endif
  StatusType LenStatusReturn;
  LenStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  LblErrorMode = OS_FALSE;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check if Os is already started on the core */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
  OS_CHECK_STARTOS_ERROR(LenStatusReturn);
  /* polyspace:end<RTE:UNR> */

  /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Acquire the spinlock */
    Os_GetSpinlock(OS_SPIN_LOCK_ZERO);
    /* Increment activated core */
    Os_GucActivateCore++;
    if(Mode != DONOTCARE)
    {
      if((Os_GblAppModeCheck == OS_FALSE) || (Mode == Os_GddAppMode))
      {
        Os_GddAppMode = Mode;
        Os_GblAppModeCheck = OS_TRUE;
      }
      else
      {
        LblErrorMode = OS_TRUE;
      }
    }
    /* Master Core is self-started */
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_GaaCore[OS_CORE_ID].blCoreStatus = OS_TRUE;
    }
    /* Release the spinlock */
    Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);
    #else /* End of if (OS_MULTICORE == STD_ON) */
    /* Store the application mode */
    Os_GddAppMode = Mode;
    #endif /* End of if (OS_MULTICORE == STD_ON) */

    /* Disable the interrupts */
    OS_DISABLEINTERRUPTS();
    /*
     * Store the application mode
     * Update Os_GpLinkTask
     */
    Os_GpLinkTask[OS_CORE_ID] = &Os_GaaLinkTask[OS_CORE_ID];
    #if (OS_TIMING_PROTECTION == STD_ON)
    /* Initialize Global watchdog */
    Os_GpSchedWatchdog[OS_CORE_ID] = NULL_PTR;
    /* Initialize state and the array index of the budget monitoring watchdog */
    Os_GaaRunningWdg[OS_CORE_ID].ulTPArrayIndx = OS_INVALID_VALUE;
    Os_GaaRunningWdg[OS_CORE_ID].ddWdgType = OS_WDG_DISABLED;
    /* Initialize faulty task id for timing budget violation in kernel mode */
    Os_GddFaultyTask[OS_CORE_ID] = INVALID_TASK;
    #endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

    #if (OS_SAFETY_KERNEL != STD_ON)
    #if (OS_MEMORY_PROTECTION == STD_ON)
    /* initialize dedicated memory block*/
    Os_InitializeDedicatedMemBlock();
    #endif
    #endif	/* End of #if (OS_SAFETY_KERNEL != STD_ON) */

    #if (OS_ISR_COUNT != OS_PRE_ZERO)
    /* Set Priority of ISRs*/
    Os_SetISRPriority();
    #endif

    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Make the sleep Tasks as OS_READY_AND_NEW */
    LpStaticTask = &Os_GaaStaticTask[OS_CORE_ID];
    LpStaticTask->pTask->ddState = OS_READY_AND_NEW;
    #if (OS_PROFILING_HOOK == STD_ON)
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    Os_TaskActivationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
    /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    #endif

    /* NOTE: OS Init must be finished before the first SYNC point. */
    /* InitOs function is called to initialize AUTOSTART objects */
    Os_InitOS();

    /* Set the status that OS in initialized globally */
    Os_GblOsInitialized[OS_CORE_ID] = OS_TRUE;

    /* Update the GpStaticTask with the task to start */
    Os_GpStaticTask[OS_CORE_ID] =
        &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */

    #if (OS_MULTICORE == STD_ON)
    /* Init multi-core message queue */
    Os_InitMessageQueue();
    /* Call function to set first synchronization */
    Os_SetSyncFirst();

    /* Call to InitTimer */
    Os_InitTimer();
    /* Initialize the port */
    OS_PORTINITIALIZE();

    if((Os_GblAppModeCheck == OS_TRUE) && (LblErrorMode == FALSE))
    #else
    /* Call to InitTimer */
    Os_InitTimer();
    /* Initialize the port */
    OS_PORTINITIALIZE();
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Initialize the state of all OS-Applications to APPLICATION_ACCESSIBLE */
      #if (OS_APPLICATION == STD_ON)
      #if (OS_MULTICORE == STD_ON)
      if(OS_CORE_ID == OS_CORE_ID_MASTER)
      #endif
      {
        LucAppCount = Os_Application_Count;
        do
        {
          /* Decrement the loop count */
          LucAppCount--;

          /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid value and verified manually */
          /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid value and verified manually */
          Os_GaaApplication[LucAppCount].ddState = APPLICATION_ACCESSIBLE;
        }while(LucAppCount != OS_ZERO);
      }
      #endif

      /* Set a flag for completion of StartOS */
      Os_GblStartOs[OS_CORE_ID] = OS_TRUE;

      #if (OS_STARTUP_HOOK == STD_ON)
      /* Process StartupHook */
      OS_PROCESS_STARTUPHOOK();
      #endif
      #if (OS_APP_STARTUP_HOOK == STD_ON)
      LucAppCount = Os_Application_Count;

      /* Run through the while loop for all the applications */
      do
      {
        /* Decrement the loop count */
        LucAppCount--;

        /* Check if startupHook is configured for the application */
        if (Os_GaaStaticAppHook[LucAppCount].pStartupHook != NULL_PTR)
        {
          #if(OS_MULTICORE == STD_ON)
          if (Os_GaaStaticAppHook[LucAppCount].ddCoreID == OS_CORE_ID)
          #endif
          {
            /*
             * OS requirement <> not implemented
             * Make a call Application specific startuphook
             */
            /* Process Application StartupHook */
            OS_PROCESS_APP_STARTUPHOOK(Os_GaaStaticAppHook[LucAppCount].pStartupHook);
          }
        }
      } while (LucAppCount != OS_ZERO);

      #endif /* End of if (OS_APP_STARTUP_HOOK == STD_ON) */

      #if (OS_MULTICORE == STD_ON)
      /* Call function to set first synchronization */
      Os_SetSyncSecond();
      #endif

      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
      OS_STARTUPCONTEXT();
    }
    #if (OS_MULTICORE == STD_ON)
    else
    {
      OS_INFINITELOOP();
    } /* End of else */
    #endif /* End of if (OS_MULTICORE == STD_ON) */
  }
  /* polyspace:end<RTE:UNR> */
} /* End of Os_KernStartOS(AppModeType Mode) */

/*******************************************************************************
** Function Name        : Os_KernGetActiveApplicationMode                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns the active application mode   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : AppModeType                                         **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GddAppMode                                       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
FUNC(AppModeType, OS_CODE) Os_KernGetActiveApplicationMode(void)
{
  StatusType LenStatusReturn;
  AppModeType LddReturnVal;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call from call level */
  OS_CHECK_E_OS_CALLEVEL(GETACTIVEAPPLICATIONMODE, LenStatusReturn);
  if (LenStatusReturn == E_OK)
  {
    LddReturnVal = Os_GddAppMode;
  }
  else
  {
    LddReturnVal = OS_INVALID_VALUE;
  }
  return (LddReturnVal);
} /* End of GetActiveApplicationMode(void) */

/*******************************************************************************
** Function Name        : Os_KillTask                                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service Terminates the specified Task.         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
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
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopExecutionBudget(),                           **
**                        Os_ReleaseInternalResource()                        **
*******************************************************************************/
#if ((OS_PROTECTION_HOOK == STD_ON) || (OS_APPLICATION == STD_ON))
FUNC(void, OS_CODE) Os_KillTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                         OS_CONST) LpStaticTask)
{
  #if (OS_TASK_TP_EB == STD_ON)
  /* Invoke StopExecutionBudget */
  Os_StopExecutionBudget(LpStaticTask);
  #endif

  #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
  /* Release internal resource */
  Os_ReleaseInternalResource(LpStaticTask);
  #endif

  /* reset the activate count */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpStaticTask->pTask->ucActivateCount = OS_ZERO;
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Change the state to SUSPENDED */
  LpStaticTask->pTask->ddState = SUSPENDED;
  #if (OS_EVENT == STD_ON)

  /* If the object is an EXTENDED task, initialize the events */
  if (LpStaticTask->usType == OS_TASK_EXTENDED)
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Set ddEventSet to ZERO */
    LpStaticTask->pTask->ddEventSet = OS_ZERO;
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Set ddEventWait to ZERO */
    LpStaticTask->pTask->ddEventWait = OS_ZERO;
  } /* End of if (LpStaticTask->ucType == OS_TASK_EXTENDED) */
  #endif /* End of if (OS_EVENT == STD_ON) */

  OS_REMOVECONTEXT(LpStaticTask);
} /* End of Os_KillTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST)
   *LpStaticTask) */
#endif /* End of if (OS_PROTECTION_HOOk == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KillIsr                                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to kill the ISR that has caused**
**                        the timing fault                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GucNestingCAT2ISR, Os_GusCallevelCheck           **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopExecutionBudget(),                           **
**                        Os_ITExitForCPULoad()                               **
*******************************************************************************/
#if ((OS_PROTECTION_HOOK == STD_ON) || (OS_APPLICATION == STD_ON))
#if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
FUNC(void, OS_CODE) Os_KillIsr(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                         OS_CONST) LpStaticTask)
{
  #if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO)
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  #if (OS_ISR_TP_EB == STD_ON)
  /* Invoke StopExecutionBudget */
  Os_StopExecutionBudget(LpStaticTask);
  #endif
  /* Decrement the CAT2 ISR nesting count */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if (Os_GucNestingCAT2ISR[OS_CORE_ID] > 0)
  {
    Os_GucNestingCAT2ISR[OS_CORE_ID]--;
    if(Os_GucNestingCAT2ISR[OS_CORE_ID] == OS_ZERO)
    {
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
      Os_GusCallevelCheck[OS_CORE_ID] &= (uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_CAT2ISR);
    }
  }
  else
  {
    /* TODO: OS Panic */
  }

  OS_REMOVECONTEXT(LpStaticTask);
  #endif/* End of if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO) */
} /* End of Os_KillIsr(P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST)
   *LpStaticTask) */
#endif /* End of if (OS_CAT2_ISR_COUNT != OS_PRE_ZERO) */
#endif /* End of if (OS_PROTECTION_HOOk == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ProtectionHookService                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to take the action for the     **
**                        error occured due to not following the              **
**                        TimingProtection.                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Fatalerror                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GddAppId, Os_GddISR2Lock, Os_GddISRLock          **
**                        Function(s) invoked    :                            **
**                        ProtectionHook(), SyncShutdownOSService(),          **
**                        Os_RunTask(), Os_TerminateApplService(),            **
**                        Os_KillTaskOrISR(), Os_SetTaskStackPointer()        **
*******************************************************************************/
#if (OS_PROTECTION_HOOK == STD_ON)
FUNC(StatusType, OS_CODE) Os_ProtectionHookService(StatusType Fatalerror)
{
  ProtectionReturnType LenResult;
  StatusType LenStatusValue;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  OS_GET_CORE_ID(OS_CORE_ID);

  LenStatusValue = E_OK;

  /* Process ProtectionHook */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  OS_PROCESS_PROTECTIONHOOK(LenResult, Fatalerror);


  #if (OS_TIMING_PROTECTION == STD_ON)
  if ((Fatalerror == E_OS_PROTECTION_ARRIVAL) && (LenResult != PRO_IGNORE))
  {
    LenResult = PRO_SHUTDOWN;
  }
  #endif
  /* polyspace:begin<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Value of LenResult depends on User-Configuration in Hook */
  switch (LenResult)
  {
    case PRO_TERMINATETASKISR:
      /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* Current Task Not RUNNING -> Os_GpStaticTask is not faulty Task */
      if ((Os_GpStaticTask[OS_CORE_ID]->usType != OS_ISR2) &&
          (Os_GpStaticTask[OS_CORE_ID]->pTask->ddState != RUNNING))
      {
        #if (OS_SCALABILITY_CLASS >= OS_SC3)
        if (Os_GddAppId[OS_CORE_ID] != (ApplicationType)INVALID_OSAPPLICATION)
        {
          /* Invoke Os_DoTerminateApplication with NO_RESTART */
          LenStatusValue =
                 Os_DoTerminateApplication(Os_GddAppId[OS_CORE_ID], NO_RESTART);
        }
        else
        #endif
        {
          /*
           * NTC.9 : The called function ShutdownOS (in the current context)
           *         either contains an error or does not terminate
           * Description: As per requirement OS425, ShutdownOS() shall
           *         enter an endless loop, thus this warning is encountered.
           */
          Os_SyncShutdownOSService(Fatalerror);
        }
      }
      else
      {
        LenStatusValue = Os_KillTaskOrISR();
      }
      /* polyspace:end<MISRA-C3:D4.1> */
      /* polyspace:end<MISRA-C3:18.1> */
      break;

    #if (OS_TIMING_PROTECTION == STD_ON)
    case PRO_IGNORE:
      /*
       * NTC.9 : The called function ShutdownOS (in the current context)
       *         either contains an error or does not terminate
       * Description: As per requirement OS425, ShutdownOS() shall
       *              enter an endless loop, thus this warning is encountered.
       */
      if (Fatalerror != E_OS_PROTECTION_ARRIVAL)
      {
        Os_SyncShutdownOSService(Fatalerror);
      }
      break;
    #endif
    case PRO_SHUTDOWN:
      /*
       * NTC.9 : The called function ShutdownOS (in the current context)
       *         either contains an error or does not terminate
       * Description: As per requirement OS425, ShutdownOS() shall
       *              enter an endless loop, thus this warning is encountered.
       */
      Os_SyncShutdownOSService(Fatalerror);
      break;

    #if (OS_SCALABILITY_CLASS >= OS_SC3)
    case PRO_TERMINATEAPPL:
      /* Invoke Os_DoTerminateApplication with NO_RESTART */
      LenStatusValue =
                 Os_DoTerminateApplication(Os_GddAppId[OS_CORE_ID], NO_RESTART);
      break;

    case PRO_TERMINATEAPPL_RESTART:
      /* Invoke Os_DoTerminateApplication with RESTART */
      LenStatusValue =
                    Os_DoTerminateApplication(Os_GddAppId[OS_CORE_ID], RESTART);
      break;
    #endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */

    default:
      /* Default: Go to Shutdown :
       *
       * NTC.9 : The called function ShutdownOS (in the current context)
       *         either contains an error or does not terminate
       * Description: As per requirement OS425, ShutdownOS() shall
       *              enter an endless loop, thus this warning is encountered.
       */
      Os_SyncShutdownOSService(Fatalerror);
      break;
  } /* End of switch (LenResult) */
  /* polyspace:end<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Value of LenResult depends on User-Configuration in Hook */

  /* Reset Interrupt processing services. */
  #if(OS_ISR_COUNT > OS_ZERO)
  Os_GblISRLock[OS_CORE_ID] = OS_FALSE;
  Os_GddISRLock[OS_CORE_ID] = OS_ZERO;
  #if (OS_CAT2_ISR_COUNT >= OS_ONE)
  Os_GddISR2Lock[OS_CORE_ID] = OS_ZERO;
  #endif
  #endif

  /* NOTE: Os_KillTaskOrISR() and Os_DoTerminateApplication()
   *       demands context switching */
  if (LenStatusValue >= OS_E_OK_AND_LOAD)
  {
    /* Set TASK or CAT2 ISR's stack base address */
    Os_SetTaskStackPointer();
    Os_RunTask();
  }

  return (LenStatusValue);
} /* End of Os_ProtectionHookService(StatusType Fatalerror) */
#endif /* End of if (OS_PROTECTION_HOOK == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
