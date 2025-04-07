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
**  SRC-MODULE: Os_Event.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Event functionality.                             **
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
** 2.6.7     04-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     19-Mar-2019    SH.Yoo        Redmine #16219                      **
** 2.5.0     14-Jun-2018    SH.Yoo        Redmine #13026                      **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #9530                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
**           04-Apr-2017    SH.Yoo        Redmine #5967                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.7     21-Jan-2014    MJ.Woo        TASK: xar~819, Redmine #558         **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
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
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Event.h"             /* Os Event header file */
#include "Os_Error.h"             /* Os Error header file */
#if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
#include "Os_Resource.h"          /* Os Resource header file */
#endif
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"  /* Os TimerProtection header file */
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

/*******************************************************************************
** Function Name        : Os_DoSetEvent                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to Set the events              **
**                        of task <TaskID> according to the event mask <Mask> **
**                        Calling SetEvent causes the task <TaskID> to be     **
**                        transferred to the ready state, if it was waiting   **
**                        for at least one of the events specified in <Mask>. **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask, Mask, LblRemoteCall                   **
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
**                        Os_TaskPreemptionHook(), Os_TaskReleaseHook(),      **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoSetEvent
(TaskType TaskID, EventMaskType Mask, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpCurrentLink;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LpStaticTask = &Os_GaaStaticTask[TaskID];
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether the requested application is accessible */
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, \
                                         LpStaticTask->ddTaskId, LblRemoteCall);
  /* Check the task is not in the SUSPENDED state */
  OS_CHECK_SUSPENDED_TASK_ERROR(LpStaticTask->ddTaskId, &LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  if (LenStatusReturn == E_OK)
  {
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Get the pointer to RAM Task */
    LpTask = LpStaticTask->pTask;

    /* Cross check the event the task is waiting for and the incoming event */
    if ((LpTask->ddEventWait & Mask) != OS_ZERO)
    {
      /* Check whether task is in the WAITING state */
      if (LpTask->ddState == WAITING)
      {
        #if (OS_TASK_TP_TF == STD_ON)
        /* Check if task is invoked after the expiry of time frame */
        Os_StartTimeFrame(LpStaticTask);
        #endif
        #if (OS_MULTICORE == STD_ON)
        /* GetCoreID into local variable */
        OS_CORE_ID = LpStaticTask->ddCoreId;
        #endif

        /* Check if task to be activated is higher priority task */
        if (LpStaticTask->ulBasePriority >
            (uint32)Os_GpLinkTask[OS_CORE_ID]->ulPriority)
        {
          #if (OS_POSTTASK_HOOK == STD_ON)
          /* Process PostTaskHook */
          OS_PROCESS_POSTTASKHOOK();
          #endif

          /* Take Link list into a local variable */
          LpCurrentLink = LpStaticTask->pLinkTask;
          /* Update the task link list*/
          LpCurrentLink->pLinkList = Os_GpLinkTask[OS_CORE_ID];
          /* Update Os_GpLinkTask */
          Os_GpLinkTask[OS_CORE_ID] = LpCurrentLink;
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
        } /* End of if (LpStaticTask->ulBasePriority > */
        else
        {
          /* Insert Task in Queue */
          Os_InsertTask(LpStaticTask);
        }

        /* Set the state to READY state */
        LpTask->ddState = OS_READY_AND_WAITING;
        #if (OS_PROFILING_HOOK == STD_ON)
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskReleaseHook(OS_CORE_ID, TaskID);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif
      } /* End of if (LpTask->ddState == WAITING) */
      /* Reset the Eventwait of the running task to Zero */
      LpTask->ddEventWait = OS_ZERO;
    } /* End of if ((LpTask->ddEventWait & LddIncomingEvent) != OS_ZERO) */
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */
    /* Merge the incoming event mask with the old one */
    LpTask->ddEventSet |= Mask;
  }

  /* Return The value */
  return (LenStatusReturn);
}
#endif /* End of if (OS_EVENT == STD_ON) */


/*******************************************************************************
** Function Name        : Os_DoGetEvent                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service returns the current state of all       **
**                        event bits of the task.                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TaskID                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : EventMaskRefType Event                              **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
/* polyspace +2 MISRA-C3:8.7 [Not a defect:Low] "External visible function" */
FUNC(StatusType, OS_CODE) Os_DoGetEvent(TaskType TaskID, EventMaskRefType Event)
{
  StatusType LenStatusReturn;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check the task is not in the SUSPENDED state */
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_SUSPENDED_TASK_ERROR(TaskID, &LenStatusReturn);
  if (LenStatusReturn == E_OK)
  {
    /* Get the Event of Current Task */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace +2 MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
    *Event = (&Os_GaaStaticTask[TaskID])->pTask->ddEventSet;
  }

  return LenStatusReturn;
}
#endif /* End of if (OS_EVENT == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernSetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to Set the events              **
**                        of task <TaskID> according to the event mask <Mask> **
**                        Calling SetEvent causes the task <TaskID> to be     **
**                        transferred to the ready state, if it was waiting   **
**                        for at least one of the events specified in <Mask>. **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : TaskType TaskID, EventMaskType Mask                 **
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
**                        Os_SendSetEvent(), Os_DoSetEvent()                  **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSetEvent(TaskType TaskID, EventMaskType Mask)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
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
  OS_CHECK_E_OS_CALLEVEL(SETEVENT, LenStatusReturn);
  /* Check whether TaskID is greater than number of task count */
  OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn);
  /* Check the task is an extended one  */
  OS_CHECK_NOT_EXTENDED_TASK_ERROR(TaskID, LenStatusReturn);
  /* Check whether the current application can access the task */
  OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, TaskID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to static task */
    LpStaticTask = &Os_GaaStaticTask[TaskID];
    /* Check if new task belongs to same core */
    if (LpStaticTask->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendSetEvent to schedule task on respective core */
      LenStatusReturn = Os_SendSetEvent(LpStaticTask, Mask);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Call Os_DoSetEvent and get the return value */
      LenStatusReturn = Os_DoSetEvent(TaskID, Mask, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of SetEvent */
    OS_STORE_SERVICE(OSServiceId_SetEvent);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Store the parameter 2 - Mask */
    OS_STORE_PARAM2_MASK(Mask);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return The value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of SetEvent(TaskType TaskID, EventMaskType Mask) */
#endif /* End of if (OS_EVENT == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernClearEvent                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : The events of the extended task calling ClearEvent  **
**                        are cleared according to the event mask <Mask>.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : EventMaskType Mask                                  **
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
**                        None                                                **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernClearEvent(EventMaskType Mask)
{
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
  /* Check for call from call level */
  OS_CHECK_E_OS_CALLEVEL(CLEAREVENT, LenStatusReturn);
  /* Check that the calling task is an extended one */
  OS_CHECK_NOT_EXTENDED_RUNNING_ERROR(LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Clear the Event */
	/* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    Os_GpStaticTask[OS_CORE_ID]->pTask->ddEventSet &= (EventMaskType)(~Mask);
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store service ID of ClearEvent */
    OS_STORE_SERVICE(OSServiceId_ClearEvent);
    /* Store the parameter 1 - Mask */
    OS_STORE_PARAM1_MASK(Mask);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return The value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of ClearEvent(EventMaskType Mask) */
#endif /* End of if (OS_EVENT == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service returns the current state of all       **
**                        event bits of the task.                             **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TaskType TaskID, EventMaskRefType Event             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : EventMaskRefType Event                              **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetEvent(), Os_DoGetEvent()                  **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetEvent(TaskType TaskID,
                                                         EventMaskRefType Event)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
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
  OS_CHECK_E_OS_CALLEVEL(GETEVENT, LenStatusReturn);
  /* Check whether TaskID is greater than number of task count */
  OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn);
  /* Check the task is an extended one */
  OS_CHECK_NOT_EXTENDED_TASK_ERROR(TaskID, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Event, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Store the static task corresponding to TaskID in local pointer */
    LpStaticTask = &Os_GaaStaticTask[TaskID];
    /* Check if new task belongs to same core */
    if (LpStaticTask->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendGetEvent to get event on respective core */
      LenStatusReturn = Os_SendGetEvent(TaskID, Event);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Call Os_DoGetEvent and get the return value */
      LenStatusReturn = Os_DoGetEvent(TaskID, Event);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of GetEvent */
    OS_STORE_SERVICE(OSServiceId_GetEvent);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Store the parameter 2 - Event */
    OS_STORE_PARAM2_EVENT(Event);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return The value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of GetEvent(TaskType TaskID, EventMaskRefType Event) */
#endif /* End of if (OS_EVENT == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernWaitEvent                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : The state of the calling task is set to waiting     **
**                        unless at least one of the events specified         **
**                        in <Mask> has already been set.                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : EventMaskType Mask                                  **
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
**                        Os_StartTimeFrame(), Os_ReleaseInternalResource()   **
**                        Os_ScheduleService(), PostTaskHook(),               **
**                        Os_TaskWaitingHook()                                **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernWaitEvent(EventMaskType Mask)
{
  /* XXX: ManJe.Woo 2013.02.04. WaitEvent() Bug!
   * NOTE: The internal resource of the task is released
   *       while the task is in the waiting state
   */
  #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #endif
  /* END: ManJe.Woo 2013.02.04. WaitEvent() Bug! */
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
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
  OS_CHECK_E_OS_CALLEVEL(WAITEVENT, LenStatusReturn);
  /* Check the calling task is an extended one */
  OS_CHECK_NOT_EXTENDED_RUNNING_ERROR(LenStatusReturn);
  /* Check the task does not occupied resource(s) */
  OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> status check */
  /* Check the task does not own a spinlock */
  OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn);

  /* polyspace-begin<RTE:UNR:Not a Defect:Justify with annotations> status check */
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* XXX: ManJe.Woo 2013.02.04. WaitEvent() Bug!
     * NOTE: The internal resource of the task is released
     *       while the task is in the waiting state
     */
    #if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
    LpStaticTask = Os_GpStaticTask[OS_CORE_ID];
    /* Release the internal resource */
    Os_ReleaseInternalResource(LpStaticTask);
    #endif
    /* END: ManJe.Woo 2013.02.04. WaitEvent() Bug! */
    /* Take Task in local variable */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    LpTask = Os_GpStaticTask[OS_CORE_ID]->pTask;
    /* Get the value of Mask into EventWait of running task */
    LpTask->ddEventWait = Mask;

    /* Check one of the event to wait is not already set */
    if (((LpTask->ddEventSet) & Mask) == OS_ZERO)
    {
      #if (OS_POSTTASK_HOOK == STD_ON)
      /* Process PostTaskHook */
      OS_PROCESS_POSTTASKHOOK();
      #endif

      /* Put the running task into the WAITING state */
      LpTask->ddState = WAITING;
      #if (OS_PROFILING_HOOK == STD_ON)
      /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      Os_TaskWaitingHook(OS_CORE_ID, Os_GpStaticTask[OS_CORE_ID]->ddTaskId);
      /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
      #endif

      /* Call Function to switch context of old task with new task */
      Os_ScheduleService();
      OS_SAVECONTEXT();
    } /* End of if (((LpTask->ddEventSet) & Mask) == OS_ZERO) */
    #if (OS_TASK_TP_TF == STD_ON)
    else
    {
      /* Check if task is invoked after the expiry of time frame */
      Os_StartTimeFrame(Os_GpStaticTask[OS_CORE_ID]);
    } /* End of else */
    #endif /* End of if (OS_TASK_TP_TF == STD_ON) */
  } /* End of if (LenStatusReturn == E_OK) */
  /* polyspace-end<RTE:UNR> */
  #if (OS_STATUS == EXTENDED)

  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  if (LenStatusReturn != E_OK)
  {
    /* Store service ID of WaitEvent */
    OS_STORE_SERVICE(OSServiceId_WaitEvent);
    /* Store the parameter 1 - Mask */
    OS_STORE_PARAM1_MASK(Mask);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return The value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of WaitEvent(EventMaskType Mask) */
#endif /* End of if (OS_EVENT == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
