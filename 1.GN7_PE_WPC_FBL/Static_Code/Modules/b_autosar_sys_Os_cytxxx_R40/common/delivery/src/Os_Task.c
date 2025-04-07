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
**  SRC-MODULE: Os_Task.c                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Task functionality                               **
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
** 2.6.12    13-May-2022    JC.Kim        Redmine #34669                      **
** 2.6.9     11-Jan-2021    YH.Han        Redmine #27622                      **
** 2.6.7     04-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.5     15-Jul-2020    YH.Han        Redmine #24712                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     20-Dec-2019    SH.Yoo        Redmine #16219                      **
** 2.5.0     14-Jun-2018    SH.Yoo        Redmine #13026                      **
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.4.1     29-Sep-2017    MJ.Woo        Redmine #9786, #10004               **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #9530                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #8275, #9148                **
** 2.3.0     04-Apr-2017    SH.Yoo        Redmine #5967                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.10    11-Dec-2015    SH.Yoo        Redmine #2505                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     18-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.3     16-Sep-2013    SH.Yoo        CR: xar~172, TASK: xar~691          **
** 2.0.2     19-Aug-2013    SH.Yoo        CR: xar~168, TASK: xar~675          **
**                          DG.Lee                                            **
** 2.0.1     13-Aug-2013    SH.Yoo        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "ptr points to a valid value and code is verified manually" */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Task.h"              /* Os Task header file */
#if (OS_RESOURCE == STD_ON)
#include "Os_Resource.h"          /* Os Task header file */
#endif
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"   /* Os TimerProtection header file */
#endif
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
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

/* polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> To avoid cross reference, external function needed.  */

#if (OS_TASK == STD_ON)
static FUNC(StatusType, OS_CODE) Os_ChainTaskError(TaskType TaskID);
static FUNC(StatusType, OS_CODE) Os_GetTaskID(TaskRefType TaskID);
#endif

/* polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> To avoid cross reference, external function is needed.  */

/*******************************************************************************
** Function Name        : Os_DoActivateTask                                   **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This Service transfers the TaskID from suspended    **
**                        state into the ready state                          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask, LblRemoteCall                         **
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
**                        Os_GpLinkTask, Os_GpStaticTask, Os_GblInterCoreInt  **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StartTimeFrame(), Os_ScheduleService(),          **
**                        Os_InsertTask(), PostTaskHook(),                    **
**                        Os_TaskPreemptionHook(), Os_TaskActivationHook()    **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoActivateTask
                                        (TaskType TaskID, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn;
  uint8 LucCount;
  #if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
  uint32 taskLinkIndex;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether the requested application is accessible */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, TaskID,
                                                                 LblRemoteCall);

  LpStaticTask = &Os_GaaStaticTask[TaskID];
  /* Check whether status return is E_OK */
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace +2 MISRA-C3:14.3 [Justified:Medium] "It is determined by configuration" */
  /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> status check */
  /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> status check */
  /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "It is determined by configuration" */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to RAM task */
    LpTask = LpStaticTask->pTask;
    #if (OS_TASK_TP_TF == STD_ON)
    /* Check if task is invoked after the expiry of time frame */
    Os_StartTimeFrame(LpStaticTask);
    #endif
    /* Get the current count into local variable */
    LucCount = LpTask->ucActivateCount;

    /* Check whether limit is exceeded */
    if (LucCount < LpStaticTask->ucMaxActivateCount)
    {
      if (LucCount == OS_ZERO)
      {
        #if (OS_MULTICORE == STD_ON)
        /* Take core ID into local variable */
        OS_CORE_ID = LpStaticTask->ddCoreId;
        #endif

        #if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
        if ( (IS_FREE_FROM_CALLTRUSTEDFUNC(LpStaticTask->ddAppId) == OS_TRUE) &&
         (LpStaticTask->ulBasePriority > Os_GpLinkTask[OS_CORE_ID]->ulPriority))
        #else
        /* Check if task to be activated is higher priority task */
        if (LpStaticTask->ulBasePriority >
                                   (uint32)Os_GpLinkTask[OS_CORE_ID]->ulPriority)
        #endif
        {

          #if (OS_POSTTASK_HOOK == STD_ON)
          /* Process PostTaskHook */
          OS_PROCESS_POSTTASKHOOK();
          #endif

          OS_INSERT_TASK_IN_QUEUE();
          /* Update linklist for the task */
          LpLinkTask->pLinkList = Os_GpLinkTask[OS_CORE_ID];
          /* Update Os_GpLinkTask */
          Os_GpLinkTask[OS_CORE_ID] = LpLinkTask;
          /* Call Function to Switch context of old task with new task */
          /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
          Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = READY;
          #if (OS_PROFILING_HOOK == STD_ON)
          /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
          Os_TaskPreemptionHook(OS_CORE_ID, Os_GpStaticTask[OS_CORE_ID]->ddTaskId);
          /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
          #endif
          Os_ScheduleService();
          #if (OS_MULTICORE == STD_ON)
          if(Os_GblInterCoreInt[OS_CORE_ID] == OS_FALSE)
          #endif
          {
            OS_SAVECONTEXT();
          }
        } /* End of if (LpStaticTask->ulBasePriority >
           *Os_GpLinkTask[OS_CORE_ID]->ulPriority) */
        else
        {
          /* Insert Task in Queue */
          Os_InsertTask(LpStaticTask);
        } /* End of else */
        /* Change the state to READY */
        LpTask->ddState = OS_READY_AND_NEW;
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskActivationHook(OS_CORE_ID, TaskID);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif

        /* Increment Activation count of the task */
        LpTask->ucActivateCount++;
      } /* End of if (LucCount == OS_ZERO) */
      else
      {
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskActivationHook(OS_CORE_ID, TaskID);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif
        /* Increment Activation count of the task */
        LpTask->ucActivateCount++;
        /* Insert Task in Queue */
        Os_InsertTask(LpStaticTask);
      } /* End of else */
    } /* End of if (LucCount < LpStaticTask->ucMaxActivateCount) */
    else
    {
      /* Status Return to E_OS_LIMIT */
      LenStatusReturn = E_OS_LIMIT;
    }
  } /* End of if (LenStatusReturn == E_OK) */
  /* polyspace-end CERT-C:MSC12-C */
  /* polyspace:end<MISRA-C3:14.3:Not a defect:Justify with annotations> status check */
  /* polyspace:end<DEFECT:USELESS_IF> */

  /* Return the value */
  return (LenStatusReturn);
}
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernActivateTask                                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This Service transfers the TaskID from suspended    **
**                        state into the ready state                          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : TaskID                                              **
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
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendActivateTask(), Os_DoActivateTask()          **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernActivateTask(TaskType TaskID)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(ACTIVATETASK, LenStatusReturn);
  /* Check whether TaskID is greater than number of task count */
  OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn);
  /* Check whether the current application can access the task */
  OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, TaskID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Store the static task corresponding to TaskID in local pointer */
    #if (OS_MULTICORE == STD_ON)
    /* Check if new task belongs to same core */
    if (Os_GaaStaticTask[TaskID].ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendActivateTask to schedule task on respective core */
      LenStatusReturn = Os_SendActivateTask(TaskID);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Call Os_DoActivateTask and get the return value */
      LenStatusReturn = Os_DoActivateTask(TaskID, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of ActivateTask */
    OS_STORE_SERVICE(OSServiceId_ActivateTask);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);

} /* End of ActivateTask(TaskType TaskID) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernTerminateTask                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service causes the termination of the          **
**                        calling task. The calling task is transferred       **
**                        from the running state into the suspended state     **
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
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpStaticTask                                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        PostTaskHook(), Os_ScheduleService()                **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernTerminateTask(void)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(TERMINATETASK, LenStatusReturn);
  /* Check the task does not own a resource  */
  OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check the task does not own a spinlock */
  OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn);

  /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> default case is necessary status check */
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_POSTTASK_HOOK == STD_ON)
    /* Process PostTaskHook */
    OS_PROCESS_POSTTASKHOOK();
    #endif

    /* Change state of the running task to DYING */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = DYING;
    /* Call Function to switch context with new task */
    Os_ScheduleService();
    OS_LOADCONTEXT();
  } /* End of if (LenStatusReturn == E_OK) */
  /* polyspace-end<RTE:UNR> */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store service ID of TerminateTask */
    OS_STORE_SERVICE(OSServiceId_TerminateTask);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of TerminateTask(void) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernChainTask                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service causes the termination of the          **
**                        calling task. After termination of the calling      **
**                        task a succeeding task <TaskID> is activated.       **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : TaskType TaskID                                     **
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
**                        Os_GpStaticTask, Os_GaaStaticTask, Os_GpLinkTask    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ChainTaskError(), Os_SendActivateTask(),         **
**                        Os_StartTimeFrame(), Os_ScheduleFromChain(),        **
**                        Os_InsertTask(), PostTaskHook(),                    **
**                        Os_ScheduleService(), Os_TaskActivationHook()       **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernChainTask(TaskType TaskID)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  uint8 LucCount;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check for call from hook*/
  LenStatusReturn = Os_ChainTaskError(TaskID);

  /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> default case is necessary status check */
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Store the static task corresponding to TaskID in local pointer */
    LpStaticTask = &Os_GaaStaticTask[TaskID];
    #if (OS_MULTICORE == STD_ON)
    /* Check if new task belongs to same core */
    if (LpStaticTask->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendActivateTask to schedule task on respective core */
      LenStatusReturn = Os_SendActivateTask(TaskID);
      /* Check whether status return is E_OK */
      if (LenStatusReturn == E_OK)
      {
        #if (OS_POSTTASK_HOOK == STD_ON)
        /* Process PostTaskHook */
        OS_PROCESS_POSTTASKHOOK();
        #endif
        /* set LenStatusReturn to OS_E_OK_AND_SCHEDULE */
        LenStatusReturn = OS_E_OK_AND_SCHEDULE;
      }
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Check whether the current application can access the task */
      OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, TaskID);
      /* Check whether the requested application is accessible */
	  /* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> The reason of result invariant is that the project is single core  */
      /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
      OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, TaskID, \
                                                                      OS_FALSE);
      /* Check whether status return is E_OK */
      /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
      /* polyspace +2 MISRA-C3:14.3 [Justified:Medium] "It is determined by configuration" */
      /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> status check */
      /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:Justify with annotations> status check */
      /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "It is determined by configuration" */
      if (LenStatusReturn == E_OK)
      {
        #if (OS_TASK_TP_TF == STD_ON)
        /* Check if task is invoked after the expiry of time frame */
        Os_StartTimeFrame(LpStaticTask);
        #endif

        /*Check whether the activated task and the running task are the same*/
        if (LpStaticTask == Os_GpStaticTask[OS_CORE_ID])
        {
          /* Invoke schedulefromChain to schedule the same task */
          Os_ScheduleFromChain();
          /* Load the context of the new task */
          OS_RELOADCONTEXT();
        } /* End of if (LpStaticTask == Os_GpStaticTask[OS_CORE_ID]) */
        else
        {
          /* Get the pointer to RAM task */
          LpTask = LpStaticTask->pTask;
          /* Get the current count into local variable */
          LucCount = LpTask->ucActivateCount;
          /* Check whether limit is exceeded */
          if (LucCount < LpStaticTask->ucMaxActivateCount)
          {
            #if (OS_POSTTASK_HOOK == STD_ON)
            /* Process PostTaskHook */
            OS_PROCESS_POSTTASKHOOK();
            #endif
            /* Check if task is activated for the first time */
            if (LucCount == OS_ZERO)
            {
              /* Change the state to READY */
              LpTask->ddState = OS_READY_AND_NEW;
            }
            #if (OS_PROFILING_HOOK == STD_ON)
            /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
            Os_TaskActivationHook(OS_CORE_ID, TaskID);
            /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
            #endif
            /* Increment Activation count of the task */
            LpTask->ucActivateCount++;
            /* Insert Task in Queue */
            Os_InsertTask(LpStaticTask);
            /* set LenStatusReturn to OS_E_OK_AND_SCHEDULE */
            LenStatusReturn = OS_E_OK_AND_SCHEDULE;
          } /* End of if (LucCount < LpStaticTask->ucMaxActivateCount) */
          else
          {
            /* Set status to E_OS_LIMIT */
            LenStatusReturn = E_OS_LIMIT;
          }
        } /* End of else */
      } /* End of if (LenStatusReturn == E_OK) */
      /* polyspace-end CERT-C:MSC12-C */
      /* polyspace:end<MISRA-C3:14.3:Not a defect:Justify with annotations> status check */
      /* polyspace:end<DEFECT:USELESS_IF> */
    }
  }
  /* polyspace-end<RTE:UNR> */

  /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> default case is necessary status check */
  /* Check whether status return is E_OK */
  if (LenStatusReturn == OS_E_OK_AND_SCHEDULE)
  {
    /* Set the return status value to "E_OK" */
    LenStatusReturn = E_OK;

    /* the object that is currently running is put in the Dying State */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = DYING;

    /* Call Function to switch context with new task */
    Os_ScheduleService();
    OS_LOADCONTEXT();
  }
  /* polyspace-end<RTE:UNR> */

  #if (OS_STATUS == EXTENDED)
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> status check */
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of ChainTask */
    OS_STORE_SERVICE(OSServiceId_ChainTask);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  }
  #endif /* End of if (OS_STATUS == EXTENDED) */

  return (LenStatusReturn);
} /* End of ChainTask(TaskType TaskID) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ChainTaskError                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function provides the error check of ChainTask **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TaskType TaskID                                     **
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
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_TASK == STD_ON)
static FUNC(StatusType, OS_CODE) Os_ChainTaskError(TaskType TaskID)
{
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CHAINTASK, LenStatusReturn);
  /* Check whether TaskID is greater than number of task count */
  OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn);
  /* Check whether call is made at the task level */
  OS_CHECK_TASK_CALL_LEVEL_ERROR(LenStatusReturn);
  /* Check the task does not own a resource  */
  OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> status check */
  /* Check the task does not own a spinlock */
  OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn);

  return(LenStatusReturn);
}
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetTaskID                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the task id from        **
**                        the task descriptor.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : TaskRefType TaskID                                  **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpStaticTask,                                    **
**                                                                            **
**                                                                            **
**                        Function(s) invoked    : none                       **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetTaskID(TaskRefType TaskID)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to E_OK */
  LenStatusReturn = E_OK;

  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETTASKID, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(TaskID, LenStatusReturn);

  if (LenStatusReturn == E_OK)
  {
    /* Get the value of Current Running Task */
    /* polyspace +2 MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
    *TaskID = Os_GpStaticTask[OS_CORE_ID]->ddTaskId;
    /* Port Specific Code to check if TaskID needs to be updated */
    LenStatusReturn = OS_PROCURE_TASK_ID(TaskID);
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store service ID of GetTaskID */
    /* Store the service ID of GetTaskID */
    OS_STORE_SERVICE(OSServiceId_GetTaskID);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKIDREF(TaskID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of GetTaskID(TaskRefType TaskID) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetTaskState                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the taskstate from      **
**                        the given taskID                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TaskType TaskID                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : TaskStateRefType State                              **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaTask, Os_GaaStaticTask                        **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetTaskState()                               **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetTaskState(TaskType TaskID,
                                                        TaskStateRefType State)
{
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETTASKSTATE, LenStatusReturn);
  /* Check whether TaskID is greater than number of task count */
  OS_CHECK_TASK_ID_STATE_ERROR(TaskID, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(State, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Store the static task corresponding to TaskID in local pointer */
    LpStaticTask = &Os_GaaStaticTask[TaskID];
    /* Check if new task belongs to same core */
    if (LpStaticTask->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendGetTaskState to get task state on respective core */
      LenStatusReturn = Os_SendGetTaskState(LpStaticTask, State);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Store the task corresponding to TaskID in local pointer */
      LpTask = &Os_GaaTask[TaskID];
      /* Get the state of Current Task */
      /* polyspace +2 MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
      *State = ((LpTask->ddState) & OS_TASK_STATUS);

      if (*State == OS_TASK_UNINITIALIZED)
      {
        *State = SUSPENDED;
      }
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store service Id of GetTaskState */
    OS_STORE_SERVICE(OSServiceId_GetTaskState);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Store the parameter 2 - State */
    OS_STORE_PARAM2_STATE(State);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of GetTaskState(TaskType TaskID, TaskStateRefType State) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ActivateTaskService                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called by OSEK/VDX ActivateTask    **
**                        and by raised alarm. if the task is in the          **
**                        SUSPENDED state, its state is changed to            **
**                        READY or RUNNING                                    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
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
**                        Os_GpLinkTask                                       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertTask(), Os_StartTimeFrame(),               **
**                        Os_TaskActivationHook()                             **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_ActivateTaskService(P2CONST(
                          Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn;
  uint8 LucCount;
  #if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
  uint32 taskLinkIndex;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Status Return to E_OS_LIMIT */
  LenStatusReturn = E_OS_LIMIT;
  /* Get the pointer to RAM task */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  LpTask = LpStaticTask->pTask;
  #if (OS_TASK_TP_TF == STD_ON)

  /* Check if task is invoked after the expiry of time frame */
  Os_StartTimeFrame(LpStaticTask);
  #endif

  /* Get the current count into local variable */
  LucCount = LpTask->ucActivateCount;

  /* Check whether limit is exceeded */
  /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
  if (LucCount < LpStaticTask->ucMaxActivateCount)
  {
    if (LucCount == OS_ZERO)
    {
      /* Change the state to READY */
      LpTask->ddState = OS_READY_AND_NEW;
      #if (OS_PROFILING_HOOK == STD_ON)
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      Os_TaskActivationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      #endif

      /* Increment Activation count of the task */
      LpTask->ucActivateCount++;
      #if (OS_MULTICORE == STD_ON)
      /* Take core ID into local variable */
      OS_CORE_ID = LpStaticTask->ddCoreId;
      #endif

      /* Check if task to be activated is higher priority task */
      if (LpStaticTask->ulBasePriority >
                                   (uint32)Os_GpLinkTask[OS_CORE_ID]->ulPriority)
      {
        /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
        OS_INSERT_TASK_IN_QUEUE();
        /* Update linklist for the task */
        LpLinkTask->pLinkList = Os_GpLinkTask[OS_CORE_ID];
        /* Update Os_GpLinkTask */
        Os_GpLinkTask[OS_CORE_ID] = LpLinkTask;
        /* set LenStatusReturn to OS_E_OK_AND_SCHEDULE */
        LenStatusReturn = OS_E_OK_AND_SCHEDULE;
      } /* End of if (LpStaticTask->ulBasePriority >
         *Os_GpLinkTask[OS_CORE_ID]->ulPriority) */
      else
      {
        /* Insert Task in Queue */
        Os_InsertTask(LpStaticTask);
        /* Set the return status value to "E_OK" */
        LenStatusReturn = E_OK;
      } /* End of else */
    } /* End of if (LucCount == OS_ZERO) */
    else
    {
      #if (OS_PROFILING_HOOK == STD_ON)
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      Os_TaskActivationHook(OS_CORE_ID, LpStaticTask->ddTaskId);
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      #endif
      /* Increment Activation count of the task */
      LpTask->ucActivateCount++;
      /* Insert Task in Queue */
      Os_InsertTask(LpStaticTask);
      /* Set the return status value to "E_OK" */
      LenStatusReturn = E_OK;
    } /* End of else */
  } /* End of if (LucCount < LpStaticTask->ucMaxActivateCount) */
  /* polyspace:end<RTE:UNR> */
  /* Return the value */
  return (LenStatusReturn);
} /* End of Os_ActivateTaskService(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   *OS_CONST) LpStaticTask) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernErrorTerminateTask                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called in case if Task             **
**                        is not terminated                                   **
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
**                        Os_GaaTask, Os_GpLinkTask, Os_GblISRLock,           **
**                        Os_GddISRLock, Os_GddISR2Lock, Os_GaaTask,          **
**                        Os_GpLinkTask, Os_GaaSpinlock                       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ReleaseResourceService(), Os_ResumeInterrupts()  **
**                        Os_KernTerminateTask(), Os_ReleaseSpinlock()        **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(void, OS_CODE) Os_KernErrorTerminateTask(void)
{
  #if(OS_ISR_COUNT > OS_ZERO)
  Os_OldLevel_T LddDefaultLevel = OS_ZERO;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if (OS_SPINLOCK == STD_ON)
  SpinlockIdType LusSpinlockId;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Invoke an error hook for missing terminate task */
  OS_PROCESS_ERROR(E_OS_MISSINGEND);

  #if (OS_RESOURCE == STD_ON)
  /* Release all the acquired resources */
  Os_ReleaseResourceService(
                        &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID]);
  #endif

  #if(OS_ISR_COUNT > OS_ZERO)
  /* Release all interrupts */
  Os_GblISRLock[OS_CORE_ID] = OS_FALSE;
  Os_GddISRLock[OS_CORE_ID] = OS_ZERO;
  #if (OS_CAT2_ISR_COUNT >= OS_ONE)
  Os_GddISR2Lock[OS_CORE_ID] = OS_ZERO;
  #endif
  Os_ResumeInterrupts(&LddDefaultLevel);
  #endif

  #if (OS_SPINLOCK == STD_ON)

  if ((Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock) != OS_ZERO)
  {
    do
    {
      LusSpinlockId = \
    		         Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock;
      Os_GaaSpinlock[LusSpinlockId].ddTaskId = OS_INVALID_VALUE;
      Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock = \
    		                      Os_GaaSpinlock[LusSpinlockId].ddNextSpinIndex;
      (void)Os_ReleaseSpinlock(LusSpinlockId);
    } while (
      Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock != OS_ZERO);
  } /* End of if ((Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock)
     *!= OS_ZERO) */
  #endif /* End of if (OS_SPINLOCK == STD_ON) */
  /* Invoke terminate task */
  (void)Os_KernTerminateTask();
} /* End of Os_KernErrorTerminateTask(void) */
#endif /* End of if (OS_TASK == STD_ON) */

/*******************************************************************************
** Function Name        : Os_GetTaskID                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the running object ID   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TaskID                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GpLinkTask, Os_GaaStaticTask                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
static FUNC(StatusType, OS_CODE) Os_GetTaskID(TaskRefType TaskID)
{
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LocalList;
  StatusType LenStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  /* Copy the linklist from global */
  LocalList = Os_GpLinkTask[OS_CORE_ID];
  /* Loop around the linklist */
  while (LocalList != NULL_PTR)
  {
    /* Check if Task is basic or extended and state is RUNNING */
    if (((Os_GaaStaticTask[LocalList->ddTaskID].usType == OS_TASK_BASIC) ||
         (Os_GaaStaticTask[LocalList->ddTaskID].usType == OS_TASK_EXTENDED))
        && (Os_GaaStaticTask[LocalList->ddTaskID].pTask->ddState == RUNNING))
    {
      if(LocalList->ddTaskID == OS_CORE_ID)
      {
        *TaskID = INVALID_TASK;
      }
      else
      {
        /* Update the pointer */
        *TaskID = LocalList->ddTaskID;
      }
      /* Break the loop */
      LocalList = NULL_PTR;
    } /* End of if ((Os_GaaStaticTask[LocalList->ddTaskID].ucType ==
       *OS_TASK_BASIC) || */
    else
    {
      /* Go to the next node */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LocalList = LocalList->pLinkList;
    }
  }

  return LenStatusReturn;
} /* End of Os_GetTaskID(TaskRefType TaskID) */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-end MISRA-C3:18.1 */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
