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
**  SRC-MODULE: Os_Resource.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of  Resource functionality.                         **
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
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     19-Mar-2019    SH.Yoo        Redmine #16219                      **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #9530                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4707, #5368                **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.6     08-Jan-2014    SH.Yoo        TASK: xar~810                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
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
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"   /* Os TimerProtection header file */
#endif
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Resource.h"          /* Os Resource header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Interrupt.h"         /* Os Interrupt header file */
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

#if (OS_RESOURCE == STD_ON)
static FUNC(StatusType, OS_CODE) Os_DoGetResource(ResourceType ResID);
static FUNC(StatusType, OS_CODE) Os_DoReleaseResource(ResourceType ResID);
#endif

/*******************************************************************************
** Function Name        : Os_DoGetResource                                    **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This Function is used to Get the resource           **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ResourceType ResID                                  **
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
**                        Os_GaaResourceTable, Os_GpLinkTask,                 **
**                        Os_GaaHardWareResource, Os_GaaStaticTask            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StartMonitor(), Os_RaisePriority(),              **
*******************************************************************************/
#if (OS_RESOURCE == STD_ON)
static FUNC(StatusType, OS_CODE) Os_DoGetResource(ResourceType ResID)
{
  #if (OS_RES_INT_SHARE == STD_ON)
  P2CONST(Tdd_Os_HardWareResource, AUTOMATIC, OS_CONST) LpStaticResource;
  #endif
  #if (OS_RES_TP_EB == STD_ON)
  TickType LddRequestedTime;
  #endif
  P2VAR(Tdd_Os_Resource, AUTOMATIC, OS_VAR) LpResource;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  StatusType LenStatusReturn = E_OK;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LpResource = &Os_GaaResourceTable[ResID];
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Get the currently running Task in a local pointer */
  LpStaticTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  #if (OS_RES_TP_EB == STD_ON)

  /* Check if timing protection is configured for currently running object */
  if (LpStaticTask->pStaticTimProtection != NULL_PTR)
  {
    LddRequestedTime =
                   LpStaticTask->pStaticTimProtection->pResourceLockTime[ResID];

    /* Check if Resource Lock Budget is configured */
    if (LddRequestedTime != OS_ZERO)
    {
      Os_StartMonitor(LddRequestedTime, OS_REZ_LOCK,
                                                LpResource->ddResLockTimeIndex);
    }
  } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
  #endif /* End of if (OS_RES_TP_EB == STD_ON) */

  #if (OS_RES_INT_SHARE == STD_ON)
  /* Store the pointer to the resource for corresponding ResID to the
   *   local pointer */
  LpStaticResource = &Os_GaaHardWareResource[ResID];

  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check if hardware priority is not the invalid priority */
  if (LpStaticResource->ulHardwarePriority != OS_INVALID_HW_PRIORITY)
  {
    (void)Os_RaisePriority(LpResource, LpStaticResource->ulHardwarePriority);
  }
  #endif /* End of if (OS_RES_INT_SHARE == STD_ON) */

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpTask = LpStaticTask->pTask;
  /* Set the owner of the resource to the calling task */
  LpResource->pOwner = LpTask;
  /* Add the ressource at the beginning of the resource list stored in the
   *   task descriptor */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
  LpResource->pNextResource = LpTask->pResources;
  /* Occupy requested resource */
  LpTask->pResources = LpResource;
  /* Save the current priority of the task in the resource */
  LpResource->ulOwnerPrevPriority = Os_GpLinkTask[OS_CORE_ID]->ulPriority;
  /* polyspace:end<MISRA-C3:18.1> */

  if (Os_GpLinkTask[OS_CORE_ID]->ulPriority < LpResource->ulCeilingPriority)
  {
    /* Update Priority for Os_GpLinkTask */
    Os_GpLinkTask[OS_CORE_ID]->ulPriority = LpResource->ulCeilingPriority;
  }
  return LenStatusReturn;
}
#endif /* End of if (OS_RESOURCE == STD_ON) */

/*******************************************************************************
** Function Name        : GetResource                                         **
**                                                                            **
** Service ID           : OSServiceId_GetResource                             **
**                                                                            **
** Description          : This Service is used to Get the resource            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ResourceType ResID                                  **
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
**                        Os_GaaResourceTable                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetResource(), Os_DoGetResource()            **
*******************************************************************************/
#if (OS_RESOURCE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetResource(ResourceType ResID)
{
  StatusType LenStatusReturn;
  ResourceType resourceId;
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
  OS_CHECK_E_OS_CALLEVEL(GETRESOURCE, LenStatusReturn);
  /* Check whether ResID is greater than number of Resource count */
  OS_CHECK_RESOURCE_ID_ERROR(ResID, &LenStatusReturn);
  /* Get the pointer to Resource structure */
  #if ((OS_MULTICORE == STD_ON) && (OS_RES_SCHEDULER == STD_ON))
  if(ResID == RES_SCHEDULER)
  {
    resourceId = RES_SCHEDULER + OS_CORE_ID;
  }
  else
  #endif
  {
    resourceId = ResID;
  }
  /* Return an error if the task that attempt to get the resource that has a
   *   higher priority than the resource or the resource is already owned by
   *   another task */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace +3 MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
  OS_CHECK_RESOURCE_PRIO_ERROR_ON_GET(&Os_GaaResourceTable[resourceId],
                                                               LenStatusReturn);
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  /* Check whether resource can access the Application */
  OS_CHECK_RESOURCE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, resourceId);
  /* polyspace:end<MISRA-C3:18.1> */

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Call Os_DoActivateTask and get the return value */
    LenStatusReturn = Os_DoGetResource(resourceId);
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store the service Id of GetResource */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    OS_STORE_SERVICE(OSServiceId_GetResource);
    /* Store the parameter 1 - ResID */
    OS_STORE_PARAM1_RESID(ResID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /*Return the value */
  return (LenStatusReturn);
} /* End of GetResource(ResourceType ResID) */
#endif /* End of if (OS_RESOURCE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoReleaseResource                                **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This Service is used to Release the resource        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : ResourceType ResID                                  **
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
**                        Os_GaaResourceTable, Os_GpLinkTask                  **
**                        Os_GaaHardWareResource, Os_GaaStaticTask            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_OriginalPriority(), Os_InsertPreemptedTask()     **
**                        Os_StopResMonitor(), Os_ScheduleService(),          **
**                        Os_TaskPreemptionHook()                             **
*******************************************************************************/
#if (OS_RESOURCE == STD_ON)
static FUNC(StatusType, OS_CODE) Os_DoReleaseResource(ResourceType ResID)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_RES_INT_SHARE == STD_ON)
  P2CONST(Tdd_Os_HardWareResource, AUTOMATIC, OS_CONST) LpStaticResource;
  #endif
  P2VAR(Tdd_Os_Resource, AUTOMATIC, OS_VAR) LpResource;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpNextLink;
  #if (OS_RES_TP_EB == STD_ON)
  TickType LddRequestedTime;
  #endif
  StatusType LenStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LpResource = &Os_GaaResourceTable[ResID];
  /* Get the currently running Task in a local pointer */
  LpStaticTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  #if (OS_RES_TP_EB == STD_ON)

  /* Check if timing protection is configured for currently running object */
  if (LpStaticTask->pStaticTimProtection != NULL_PTR)
  {
    LddRequestedTime =
                   LpStaticTask->pStaticTimProtection->pResourceLockTime[ResID];

    /* Check if Resource Lock Budget is configured */
    if (LddRequestedTime != OS_ZERO)
    {
      /* Stop resource lock budget */
      Os_StopResMonitor(LpStaticTask, LpResource);
    }
  } /* End of if (LpStaticTask->pStaticTimProtection != NULL_PTR) */
  #endif /* OS_TIMING_PROTECTION */

  /* Save the current priority of the task in the resource   */
  Os_GpLinkTask[OS_CORE_ID]->ulPriority = LpResource->ulOwnerPrevPriority;
  /* Remove the resource from the resource list  */
  LpStaticTask->pTask->pResources = LpResource->pNextResource;
  /* Update NextResource of the Resource with NULL_PTR*/
  LpResource->pNextResource = NULL_PTR;
  /* Remove the owner */
  LpResource->pOwner = NULL_PTR;
  #if (OS_RES_INT_SHARE == STD_ON)
  /* Store the pointer to the resource for corresponding ResID to the
   *   local pointer */
  LpStaticResource = &Os_GaaHardWareResource[ResID];

  /* Check if hardware priority of the resource is not invalid */
  if (LpStaticResource->ulHardwarePriority != OS_INVALID_HW_PRIORITY)
  {
    (void)Os_OriginalPriority(LpResource);
  }
  #endif /* End of if (OS_RES_INT_SHARE == STD_ON) */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
  LpNextLink = Os_GpLinkTask[OS_CORE_ID]->pLinkList;

  /* Check if Context switch is required */
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
    /* Change state of the running task to ready */
    LpStaticTask->pTask->ddState = READY;
    #if (OS_PROFILING_HOOK == STD_ON)
    /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    Os_TaskPreemptionHook(OS_CORE_ID, LpStaticTask->ddTaskId);
    /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
    #endif
    Os_ScheduleService();
    OS_SAVECONTEXT();
  } /* End of if (LpNextLink->ulPriority >
       *Os_GpLinkTask[OS_CORE_ID]->ulPriority) */
  /* polyspace:end<MISRA-C3:18.1> */

  return LenStatusReturn;
}
#endif /* End of if (OS_RESOURCE == STD_ON) */

/*******************************************************************************
** Function Name        : ReleaseResource                                     **
**                                                                            **
** Service ID           : OSServiceId_ReleaseResource                         **
**                                                                            **
** Description          : This Service is used to Release the resource        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : ResourceType ResID                                  **
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
**                        Os_GaaResourceTable                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendReleaseResource(), Os_Os_DoReleaseResource() **
*******************************************************************************/
#if (OS_RESOURCE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernReleaseResource(ResourceType ResID)
{
  StatusType LenStatusReturn;
  ResourceType resourceId;
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
  OS_CHECK_E_OS_CALLEVEL(RELEASERESOURCE, LenStatusReturn);
  /* Check whether ResID is greater than number of Resource count */
  OS_CHECK_RESOURCE_ID_ERROR(ResID, &LenStatusReturn);
  /* Get the pointer to Resource structure */
  #if ((OS_MULTICORE == STD_ON) && (OS_RES_SCHEDULER == STD_ON))
  if(ResID == RES_SCHEDULER)
  {
    resourceId = RES_SCHEDULER + OS_CORE_ID;
  }
  else
  #endif
  {
    resourceId = ResID;
  }

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Return an error if the task that attempt to get the resource has a higher
   *   priority than the resource */
  /* polyspace +3 MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
  OS_CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(&Os_GaaResourceTable[resourceId],
                                                               LenStatusReturn);
  /* Check the order of release */
  /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > Check validity of the point */
  OS_CHECK_RESOURCE_ORDER_ON_RELEASE(&(Os_GaaResourceTable[resourceId]),
                                                               LenStatusReturn);
  /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > Check validity of the point */
  /* Check whether resource can access the Application */
  OS_CHECK_RESOURCE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, resourceId);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    LenStatusReturn = Os_DoReleaseResource(resourceId);
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store the service Id of ReleaseResource */
    OS_STORE_SERVICE(OSServiceId_ReleaseResource);
    /* Store the parameter 1 - ResID */
    OS_STORE_PARAM1_RESID(ResID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* polyspace:end<MISRA-C3:18.1> */

  /* Return The value */
  return (LenStatusReturn);
} /* End of ReleaseResource(ResourceType ResID) */
#endif /* End of if (OS_RESOURCE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_GetInternalResource                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to Take internal resource      **
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
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpLinkTask()                                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
FUNC(void, OS_CODE) Os_GetInternalResource(P2CONST(Tdd_Os_StaticTask,
                                              AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_InternalResource, AUTOMATIC, OS_VAR) LpInternalResource;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Get the pointer to internal resouce */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> pointer indicates pre-defined range */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
  LpInternalResource = LpStaticTask->pInternalResource;
  /* polyspace:end<MISRA-C3:18.1> */

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check If internal resource is configured for the Task and if it is not
   *   taken by any other task */
  if ((LpInternalResource != NULL_PTR) &&
      (LpInternalResource->ucTaken == OS_FALSE))
  {
    /* Change status of the Resource as TAKEN */
    LpInternalResource->ucTaken = OS_TRUE;
    /* BasePriority of the task is assigned to OwenerPrevious priority */
    LpInternalResource->ulOwnerPrevPriority =
      Os_GpLinkTask[OS_CORE_ID]->ulPriority;
    /* Update priority in Os_GpLinkTask */
    Os_GpLinkTask[OS_CORE_ID]->ulPriority =
      LpInternalResource->ulCeilingPriority;
  } /* End of if ((LpInternalResource != NULL_PTR) && */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_GetInternalResource(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   *OS_CONST) LpStaticTask) */
#endif /* End of if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO) */

/*******************************************************************************
** Function Name        : Os_ReleaseInternalResource                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to Release internal resource   **
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
#if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO)
FUNC(void, OS_CODE) Os_ReleaseInternalResource(P2CONST(
                           Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_InternalResource, AUTOMATIC, OS_VAR) LpInternalResource;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
  if (LpStaticTask->pInternalResource != NULL_PTR)
  {
    /* Get the pointer to internal resouce */
    LpInternalResource = LpStaticTask->pInternalResource;

    /* Check if internal resource is taken by the task */
    if (LpInternalResource->ucTaken == OS_TRUE)
    {
      /* Change status of the Resource as FALSE */
      LpInternalResource->ucTaken = OS_FALSE;
      /* Update priority in Os_GpLinkTask */
      Os_GpLinkTask[OS_CORE_ID]->ulPriority =
        LpInternalResource->ulOwnerPrevPriority;
    } /* End of if (LpInternalResource->ucTaken == OS_TRUE) */
  } /* End of if (LpStaticTask->pInternalResource != NULL_PTR) */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_ReleaseInternalResource(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   *OS_VAR) LpStaticTask) */
#endif /* End of if (OS_INTERNAL_RESOURCE_COUNT > OS_PRE_ZERO) */
/*******************************************************************************
** Function Name        : Os_ReleaseResourceService                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Service is used to Release resource            **
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
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaHardWareResource                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_OriginalPriority()                               **
*******************************************************************************/
#if (OS_RESOURCE == STD_ON)
FUNC(void, OS_CODE) Os_ReleaseResourceService(P2CONST(Tdd_Os_StaticTask,
                                              AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(Tdd_Os_Resource, AUTOMATIC, OS_VAR) LpResource;

  /* Check if current running task is configured for resouces*/
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if (LpStaticTask->pTask->pResources != NULL_PTR)
  {
    /* Update the resource of the running task in a local */
    LpResource = LpStaticTask->pTask->pResources;

    do
    {
      /*
       * Release the Resource
       * Remove the resource from the resource list
       */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LpStaticTask->pTask->pResources = LpResource->pNextResource;
      /* Update NextResource of the Resource with NULL_PTR*/
      LpResource->pNextResource = NULL_PTR;
      /* Remove the owner */
      LpResource->pOwner = NULL_PTR;
      #if (OS_RES_INT_SHARE == STD_ON)
      /* Store the pointer to the resource for corresponding ResID to the
       *   local pointer */
      LpResource->ulOwnerPrevHwPrio = OS_ZERO;
      #endif /* End of if (OS_RES_INT_SHARE == STD_ON) */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LpResource = LpStaticTask->pTask->pResources;
    } while (LpResource != NULL_PTR);
  } /* End of if (LpStaticTask->pTask->pResources != NULL_PTR) */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_ReleaseResourceService(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   *OS_CONST) LpStaticTask) */
#endif /* End of if (OS_RESOURCE == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
