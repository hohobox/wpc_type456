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
**  SRC-MODULE: Os_Spinlock.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Spinlock functionality.                          **
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
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.7     03-Feb-2014    MJ.Woo        TASK: xar~819, Redmine #590, #591   **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     03-Sep-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
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
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Spinlock.h"          /* Os Spinlock header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"
#endif
#include "Os_Application.h"       /* Os Application header file */
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
** Function Name        : GetSpinlock                                         **
**                                                                            **
** Service ID           : OSServiceId_GetSpinlock                             **
**                                                                            **
** Description          : GetSpinlock tries to occupy a spin-lock variable.   **
**                        If the function returns, either the lock is         **
**                        successfully taken or an error has occurred.The     **
**                        spinlock mechanism is an active polling mechanism.  **
**                        The function does not cause a de-scheduling.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaSpinlock, Os_GpLinkTask, Os_GaaTask,          **
**                        Os_GddAppId                                         **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock()                                    **
*******************************************************************************/
#if (OS_SPINLOCK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetSpinlock(SpinlockIdType SpinlockId)
{
  P2VAR(Tdd_Os_Spinlock, AUTOMATIC, OS_VAR) LpSpinlock;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  StatusType LenStatusReturn;
  CoreIDType OS_CORE_ID;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether SpinlockId is greater than number of Spinlock count */
  OS_CHECK_SPINLOCK_ID_ERROR(SpinlockId, LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETSPINLOCK, LenStatusReturn);
  /* Check Access for the spinlock */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId);
  /* polyspace:end<MISRA-C3:18.1> */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Check whether Spinlock is already occupied by same task or task belonging
   *   on same core */
  OS_CHECK_SPINLOCK_STATUS_ERROR(SpinlockId, LenStatusReturn);

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  LpTask = &Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check whether Spinlock can create deadlock */
  OS_CHECK_SPINLOCK_DEADLOCK_ERROR(SpinlockId, LpTask, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Get The Spinlock */
    Os_GetSpinlock(SpinlockId);

    /* Take Spinlock into local variable */
    LpSpinlock = &Os_GaaSpinlock[SpinlockId];
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Update taskID into Spinlock structure */
    LpSpinlock->ddTaskId = Os_GpLinkTask[OS_CORE_ID]->ddTaskID;
    /* Update ddNextSpinIndex with Index of the previously aquired Spinlock */
    LpSpinlock->ddNextSpinIndex = LpTask->ddSpinlock;
    /* Update Spinlock ID in Task structure */
    LpTask->ddSpinlock = SpinlockId;
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of GetSpinlock */
    OS_STORE_SERVICE(OSServiceId_GetSpinlock);
    /*Store the parameter 1 - SpinlockId */
    OS_STORE_PARAM1_SPINLOCKID(SpinlockId);
    /* Release the Task or ISR */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of GetSpinlock(SpinlockIdType SpinlockId) */
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*******************************************************************************
** Function Name        : ReleaseSpinlock                                     **
**                                                                            **
** Service ID           : OSServiceId_ReleaseSpinlock                         **
**                                                                            **
** Description          : ReleaseSpinlock releases a spinlock variable that   **
**                       was occupied before. Before terminating a TASK all   **
**                       spinlock variables that have been occupied with      **
**                       GetSpinlock() shall be released.                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaSpinlock, Os_GpLinkTask, Os_GaaTask           **
**                        Os_GddAppId                                         **
**                        Function(s) invoked    :                            **
**                        Os_ReleaseTaskLock()                                **
*******************************************************************************/
#if (OS_SPINLOCK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernReleaseSpinlock(SpinlockIdType SpinlockId)
{
  P2VAR(Tdd_Os_Spinlock, AUTOMATIC, OS_VAR) LpSpinlock;
  StatusType LenStatusReturn;
  CoreIDType OS_CORE_ID;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether SpinlockId is greater than number of Spinlock count */
  OS_CHECK_SPINLOCK_ID_ERROR(SpinlockId, LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(RELEASESPINLOCK, LenStatusReturn);
  /* Check Access for the spinlock */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> array index is in pre-defined range */
  /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId);
  /* polyspace:end<MISRA-C3:18.1> */
  /* Check if Spinlock is not aquired by the task */
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_SPINLOCK_STATE_ERROR(SpinlockId, LenStatusReturn);

  /* check if Releasing order is incorrect */
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_SPINLOCK_RELEASE_ORDER_ERROR(SpinlockId, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Take Spinlock into local variable */
    LpSpinlock = &Os_GaaSpinlock[SpinlockId];
    /* Update taskID into Spinlock structure */
    LpSpinlock->ddTaskId = OS_INVALID_VALUE;
    /* Update Spinlock id in Task structure with next Spinlock ID */
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock =
                                                    LpSpinlock->ddNextSpinIndex;
    /* Release the Spinlock */
    Os_ReleaseSpinlock(SpinlockId);
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Store service ID of ReleaseSpinlock */
    OS_STORE_SERVICE(OSServiceId_ReleaseSpinlock);
    /*Store the parameter 1 - SpinlockId */
    OS_STORE_PARAM1_SPINLOCKID(SpinlockId);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the status */
  return (LenStatusReturn);
} /* End of ReleaseSpinlock(SpinlockIdType SpinlockId) */
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*******************************************************************************
** Function Name        : TryToGetSpinlock                                    **
**                                                                            **
** Service ID           : OSServiceId_TryToGetSpinlock                        **
**                                                                            **
** Description          : The TryToGetSpinlockType indicates if the spinlock  **
**                        has been occupied or not.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Success                                             **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaSpinlock, Os_GpLinkTask, Os_GaaTask           **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SPINLOCK == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernTryToGetSpinlock(SpinlockIdType SpinlockId,
                         P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success)
{
  P2VAR(Tdd_Os_Spinlock, AUTOMATIC, OS_VAR) LpSpinlock;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  StatusType LenStatusReturn;
  CoreIDType OS_CORE_ID;
  boolean LblStatus = OS_FALSE;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether SpinlockId is greater than number of Spinlock count */
  OS_CHECK_SPINLOCK_ID_ERROR(SpinlockId, LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(TRYTOGETSPINLOCK, LenStatusReturn);
  /* Check Access for the spinlock */
  /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId);
  /* Check whether Spinlock is already occupied by same task or task belonging
   *     on same core */
  OS_CHECK_SPINLOCK_STATUS_ERROR(SpinlockId, LenStatusReturn);
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  LpTask = &Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  /* Check whether Spinlock can create deadlock */
  OS_CHECK_SPINLOCK_DEADLOCK_ERROR(SpinlockId, LpTask, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Success, LenStatusReturn);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Get The Spinlock */
    Os_TryToGetSpinlock(SpinlockId, &LblStatus);

    /* Check if Spinlock is aquired */
    if (LblStatus == OS_TRUE)
    {
      /* Update status of the Spinlock  */
      *Success = TRYTOGETSPINLOCK_SUCCESS;
      /* Take Spinlock into local variable */
      LpSpinlock = &Os_GaaSpinlock[SpinlockId];
      /* Update TaskID into Spinlock structure */
      LpSpinlock->ddTaskId = Os_GpLinkTask[OS_CORE_ID]->ddTaskID;
      /* Update ddNextSpinIndex with Index of the previously aquired Spinlock */
      LpSpinlock->ddNextSpinIndex = LpTask->ddSpinlock;
      /* Update Spinlock ID in Task structure */
      LpTask->ddSpinlock = SpinlockId;
    } /* End of if (LblStatus == OS_TRUE) */
    else
    {
      /* Update status of the Spinlock  */
      *Success = TRYTOGETSPINLOCK_NOSUCCESS;
    }
  } /* End of if (LenStatusReturn == E_OK) */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of TryToGetSpinlock */
    OS_STORE_SERVICE(OSServiceId_TryToGetSpinlock);
    /* Store the parameter 1 - SpinlockId */
    OS_STORE_PARAM1_SPINLOCKID(SpinlockId);
    /* Store the parameter 2 - Success */
    OS_STORE_PARAM2_SUCCESS(Success);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of TryToGetSpinlock(SpinlockIdType SpinlockId,
   *P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success) */
#endif /* End of if (OS_SPINLOCK == STD_ON) */
/*******************************************************************************
** Function Name        : Os_ReleaseAllSpinlocks                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function releases all the spinlocks associated **
**                        with the core.                                      **
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
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpLinkTask                                       **
**                        Os_GaaTask, Os_GaaSpinlock                          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ReleaseSpinlock()                                **
**                                                                            **
*******************************************************************************/
#if (OS_SPINLOCK == STD_ON)
FUNC(void, OS_CODE) Os_ReleaseAllSpinlocks(void)
{
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpLinkTask;
  P2VAR(Tdd_Os_Spinlock, AUTOMATIC, OS_VAR) LpSpinlock;
  P2VAR(Tdd_Os_Task, AUTOMATIC, OS_VAR) LpTask;
  CoreIDType OS_CORE_ID;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Point to the link list */
  LpLinkTask = Os_GpLinkTask[OS_CORE_ID];
  /* Point to the task corresponding to the link list */
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  LpTask = &Os_GaaTask[LpLinkTask->ddTaskID];

  do
  {
    /* Run through the loop till any spinlock is assosiated with the task */
    while (LpTask->ddSpinlock != OS_ZERO)
    {
      /* Point to the spinlock */
      LpSpinlock = &Os_GaaSpinlock[LpTask->ddSpinlock];
      /* Update taskID with Invalid value into Spinlock structure */
      LpSpinlock->ddTaskId = OS_INVALID_VALUE;
      /* Update Spinlock id in Task structure with next task ID */
      LpTask->ddSpinlock = LpSpinlock->ddNextSpinIndex;
      /* Release the Spinlock */
      Os_ReleaseSpinlock(LpTask->ddSpinlock);
    }

    /* Point to next link task */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
    LpLinkTask = LpLinkTask->pLinkList;
    /* Point to the task corresponding to the link list */
    /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
    LpTask = &Os_GaaTask[LpLinkTask->ddTaskID];
  } while (LpLinkTask->ddTaskID != OS_CORE_ID);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_ReleaseAllSpinlocks(void) */
#endif /* End of if (OS_SPINLOCK == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"


/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
