/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Hook.c                                                     **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS Improvement Code                                   **
**                                                                            **
**  PURPOSE   : Provision of helper functions for OS Hooks                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.1.3     23-Feb-2023    JC.Kim        Redmine #39008                      **
** 2.1.1     03-Mar-2022    MJ.Woo        Redmine #34294                      **
** 2.0.1     14-Aug-2020    JH.Cho        Redmine #25097                      **
** 1.0.0     18-Feb-2020    MJ.Woo        Redmine #20864                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> This code has already been verified and no impact of this rule violation */
/* polyspace:begin<MISRA-C3:8.13:Not a defect:Justify with annotations> The pointer points const-qualified type */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Hook.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define OS_DELAYCOUNTER                 0x10
/* polyspace-begin MISRA-C3:8.7 [Not a Defect] "global variable can be used for external linkage" */
#define OS_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
uint32 GulOsErrorCount;
uint32 GulOsErrorLastPosition;
uint32 Os_GulOsLimitError;
uint32 Os_GulOsStackFaultError;
#define OS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
Os_ErrorType GucOsError[SZ_OSERROR];
#define OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/* polyspace-end MISRA-C3:8.7 */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/***************************************************************************//**
 * Function Name        : Os_ToEnumError
 *
 * Service ID           : NA
 *
 * Description          : This function is used to convert OS error type.
 *                        From StatusType to Os_ErrorValueType
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LddError      Error reason
 *                                      (range : 1 ~ 103)
 *
 * @return              : The error code of Os_ErrorValueType
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static FUNC(Os_ErrorValueType, OS_CODE) Os_ToEnumError(StatusType LddError)
{
  Os_ErrorValueType err;

  switch (LddError)
  {
    case E_OK:
      err = _E_OK;
      break;
    case E_OS_ACCESS:
      err = _E_OS_ACCESS;
      break;
    case E_OS_CALLEVEL:
      err = _E_OS_CALLEVEL;
      break;
    case E_OS_ID:
      err = _E_OS_ID;
      break;
    case E_OS_LIMIT:
      err = _E_OS_LIMIT;
      break;
    case E_OS_NOFUNC:
      err = _E_OS_NOFUNC;
      break;
    case E_OS_RESOURCE:
      err = _E_OS_RESOURCE;
      break;
    case E_OS_STATE:
      err = _E_OS_STATE;
      break;
    case E_OS_VALUE:
      err = _E_OS_VALUE;
      break;
    case E_OS_SERVICEID:
      err = _E_OS_SERVICEID;
      break;
    case E_OS_ILLEGAL_ADDRESS:
      err = _E_OS_ILLEGAL_ADDRESS;
      break;
    case E_OS_MISSINGEND:
      err = _E_OS_MISSINGEND;
      break;
    case E_OS_DISABLEDINT:
      err = _E_OS_DISABLEDINT;
      break;
    case E_OS_CORE:
      err = _E_OS_CORE;
      break;
    case E_OS_INTERFERENCE_DEADLOCK:
      err = _E_OS_INTERFERENCE_DEADLOCK;
      break;
    case E_OS_NESTING_DEADLOCK:
      err = _E_OS_NESTING_DEADLOCK;
      break;
    case E_OS_SPINLOCK:
      err = _E_OS_SPINLOCK;
      break;
    case E_OS_PARAM_POINTER:
      err = _E_OS_PARAM_POINTER;
      break;
    case E_OS_STACKFAULT:
      err = _E_OS_STACKFAULT;
      break;
    case E_OS_PROTECTION_MEMORY:
      err = _E_OS_PROTECTION_MEMORY;
      break;
    case E_OS_PROTECTION_TIME:
      err = _E_OS_PROTECTION_TIME;
      break;
    case E_OS_PROTECTION_LOCKED:
      err = _E_OS_PROTECTION_LOCKED;
      break;
    case E_OS_PROTECTION_EXCEPTION:
      err = _E_OS_PROTECTION_EXCEPTION;
      break;
    case E_OS_PROTECTION_ARRIVAL:
      err = _E_OS_PROTECTION_ARRIVAL;
      break;
    case E_OS_SYS_ALARM_INUSE:
      err = _E_OS_SYS_ALARM_INUSE;
      break;
    case E_OS_SYS_RAMECC:
      err = _E_OS_SYS_RAMECC;
      break;
    case E_OS_SYS_DFLASHECC:
      err = _E_OS_SYS_DFLASHECC;
      break;
    case E_OS_SYS_PFLASHECC:
      err = _E_OS_SYS_PFLASHECC;
      break;
    case E_OS_SYS_CORE_IS_DOWN:
      err = _E_OS_SYS_CORE_IS_DOWN;
      break;
    case E_OS_SYS_NMI:
      err = _E_OS_SYS_NMI;
      break;
    case E_OS_SYS_INTERCOREMSG:
      err = _E_OS_SYS_INTERCOREMSG;
      break;
    default:
      err = _E_OS_SYS_PANIC;
      break;
  }
  return err;
}

#if ((OS_ERROR_HOOK == STD_ON) && (OS_USE_GET_SERVICE_ID == STD_ON))
/***************************************************************************//**
 * Function Name        : Os_GetErrorEnumServiceId
 *
 * Service ID           : NA
 *
 * Description          : This function is used to get the OS service ID
 *                        where the error occurred.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Paramameters           None
 *
 * @return              : The Os Service Id of Os_ErrorApiType
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        OSErrorGetServiceId()
 ******************************************************************************/
static FUNC(Os_ErrorApiType, OS_CODE) Os_GetErrorEnumServiceId(void)
{
  OSServiceIdType serviceId;
  Os_ErrorApiType enumApiId;

  serviceId = OSErrorGetServiceId();

  switch (serviceId)
  {
    /* services for memory protection */
    #if (OS_MEMORY_PROTECTION == STD_ON)
    #if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
    case OSServiceId_CallTrustedFunction:
      enumApiId = _CallTrustedFunction;
      break;
    #endif
    #endif /* #if (OS_MEMORY_PROTECTION == STD_ON) */

    /* services for OS-Application */
    #if (OS_APPLICATION == STD_ON)
    case OSServiceId_TerminateApplication:
      enumApiId = _TerminateApplication;
      break;
    case OSServiceId_AllowAccess:
      enumApiId = _AllowAccess;
      break;
    case OSServiceId_GetApplicationState:
      enumApiId = _GetApplicationState;
      break;
    #endif /* (OS_APPLICATION == STD_ON) */

    /* services for Task */
    #if (OS_TASK == STD_ON)
    case OSServiceId_ActivateTask:
      enumApiId = _ActivateTask;
      break;
    case OSServiceId_TerminateTask:
      enumApiId = _TerminateTask;
      break;
    case OSServiceId_ChainTask:
      enumApiId = _ChainTask;
      break;
    case OSServiceId_Schedule:
      enumApiId = _Schedule;
      break;
    case OSServiceId_GetTaskID:
      enumApiId = _GetTaskID;
      break;
    case OSServiceId_GetTaskState:
      enumApiId = _GetTaskState;
      break;
    #endif /* #if (OS_TASK == STD_ON) */

    /* services for resource */
    #if (OS_RESOURCE == STD_ON)
    case OSServiceId_GetResource:
      enumApiId = _GetResource;
      break;
    case OSServiceId_ReleaseResource:
      enumApiId = _ReleaseResource;
      break;
    #endif /* #if (OS_RESOURCE == STD_ON) */

    /* services for event */
    #if (OS_EVENT == STD_ON)
    case OSServiceId_SetEvent:
      enumApiId = _SetEvent;
      break;
    case OSServiceId_ClearEvent:
      enumApiId = _ClearEvent;
      break;
    case OSServiceId_GetEvent:
      enumApiId = _GetEvent;
      break;
    #endif /* #if (OS_EVENT == STD_ON) */

    /* services for alarm */
    #if (OS_ALARM == STD_ON)
    case OSServiceId_GetAlarmBase:
      enumApiId = _GetAlarmBase;
      break;
    case OSServiceId_GetAlarm:
      enumApiId = _GetAlarm;
      break;
    case OSServiceId_SetRelAlarm:
      enumApiId = _SetRelAlarm;
      break;
    case OSServiceId_SetAbsAlarm:
      enumApiId = _SetAbsAlarm;
      break;
    case OSServiceId_CancelAlarm:
      enumApiId = _CancelAlarm;
      break;
    #endif /* #if (OS_ALARM == STD_ON) */

    /* services for counter */
    #if (OS_COUNTER == STD_ON)
    case OSServiceId_IncrementCounter:
      enumApiId = _IncrementCounter;
      break;
    case OSServiceId_GetCounterValue:
      enumApiId = _GetCounterValue;
      break;
    case OSServiceId_GetElapsedValue:
      enumApiId = _GetElapsedValue;
      break;
    #endif /* #if (OS_COUNTER == STD_ON) */

    /* services for scheduletable */
    #if (OS_SCHEDTABLE == STD_ON)
    case OSServiceId_StartScheduleTableRel:
      enumApiId = _StartScheduleTableRel;
      break;
    case OSServiceId_StartScheduleTableAbs:
      enumApiId = _StartScheduleTableAbs;
      break;
    case OSServiceId_StopScheduleTable:
      enumApiId = _StopScheduleTable;
      break;
    case OSServiceId_NextScheduleTable:
      enumApiId = _NextScheduleTable;
      break;
    #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
    case OSServiceId_StartScheduleTableSynchron:
      enumApiId = _StartScheduleTableSynchron;
      break;
    case OSServiceId_SyncScheduleTable:
      enumApiId = _SyncScheduleTable;
      break;
    case OSServiceId_SetScheduleTableAsync:
      enumApiId = _SetScheduleTableAsync;
      break;
    #endif /* #if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */
    case OSServiceId_GetScheduleTableStatus:
      enumApiId = _GetScheduleTableStatus;
      break;
    #endif /* #if (OS_SCHEDTABLE == STD_ON) */

    #if (OS_SPINLOCK == STD_ON)
    case OSServiceId_GetSpinlock:
      enumApiId = _GetSpinlock;
      break;
    case OSServiceId_ReleaseSpinlock:
      enumApiId = _ReleaseSpinlock;
      break;
    case OSServiceId_TryToGetSpinlock:
      enumApiId = _TryToGetSpinlock;
      break;
    #endif /* #if (OS_SPINLOCK == STD_ON) */

    default:
      enumApiId = _NoAPI;
      break;
  }
  return enumApiId;
}
#endif /* End of #if ((OS_ERROR_HOOK == STD_ON) && (OS_USE_GET_SERVICE_ID .. */

/***************************************************************************//**
 * Function Name        : Os_UpdateOsErrorInfo
 *
 * Service ID           : NA
 *
 * Description          : This service is used to save OS error information.
 *                        API name, error reason and API parameter are saved to
 *                        'GucOsError'
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddError      Error reason
 *                                      (range : 1 ~ 103)
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        GulOsErrorLastPosition, GulOsErrorCount, GucOsError,
 *                        Os_GulOsLimitError, Os_GulOsStackFaultError
 *
 *                        Function(s) invoked    :
 *                        Os_GetErrorEnumServiceId()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_UpdateOsErrorInfo(StatusType LddError)
{
  Os_ErrorApiType LddServiceId;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if ((OS_ERROR_HOOK == STD_ON) && (OS_USE_GET_SERVICE_ID == STD_ON))
  switch (LddError)
  {
    case E_OS_STACKFAULT:
    case E_OS_PROTECTION_MEMORY:
    case E_OS_PROTECTION_TIME:
    case E_OS_PROTECTION_LOCKED:
    case E_OS_PROTECTION_EXCEPTION:
    case E_OS_PROTECTION_ARRIVAL:
    case E_OS_SYS_RAMECC:
    case E_OS_SYS_DFLASHECC:
    case E_OS_SYS_PFLASHECC:
    case E_OS_SYS_PANIC:
    case E_OS_SYS_NMI:
      LddServiceId = _NoAPI;
      break;
    default :
      LddServiceId = Os_GetErrorEnumServiceId();
      break;
  }
  #else
  LddServiceId = _NoAPI;
  #endif

  GulOsErrorLastPosition = GulOsErrorCount & (uint32)MASK_OSERROR_BUF;
  GucOsError[GulOsErrorLastPosition].enApi = LddServiceId;
  GucOsError[GulOsErrorLastPosition].enErrorNo = Os_ToEnumError(LddError);
  #if ((OS_ERROR_HOOK == STD_ON) && (OS_USER_PARAMETER_ACCESS == STD_ON))
  switch (LddServiceId)
  {
    /* below OS APIs doesn't call error hook
     *
     * StartOS, ShutdownOS, GetActiveApplicationMode, CheckISRMemoryAccess,
     * CheckTaskMemoryAccess, GetApplicationID, CheckObjectAccess,
     * CheckObjectOwnership                                                   */

    /* services for memory protection */
    #if (OS_MEMORY_PROTECTION == STD_ON)
    #if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
    case _CallTrustedFunction:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTrustedFunctionIndexId =
                                    OSError_CallTrustedFunction_FunctionIndex();
      GucOsError[GulOsErrorLastPosition].unPar2.OsTrustedFunctionParams =
                                   OSError_CallTrustedFunction_FunctionParams();
      break;
    #endif
    #endif /* #if (OS_MEMORY_PROTECTION == STD_ON) */

    /* services for OS-Application */
    #if (OS_APPLICATION == STD_ON)
    case _TerminateApplication:
      GucOsError[GulOsErrorLastPosition].unPar1.OsApplicationId =
                                     OSError_TerminateApplication_Application();
      GucOsError[GulOsErrorLastPosition].unPar2.OsRestartOption =
                                   OSError_TerminateApplication_RestartOption();
      break;
    case _AllowAccess:
      break;
    case _GetApplicationState:
      GucOsError[GulOsErrorLastPosition].unPar1.OsApplicationId =
                                      OSError_GetApplicationState_Application();
      break;
    #endif /* (OS_APPLICATION == STD_ON) */

    /* services for Task */
    #if (OS_TASK == STD_ON)
    case _ActivateTask:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                                  OSError_ActivateTask_TaskID();
      break;
    case _TerminateTask:
      break;
    case _ChainTask:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                                     OSError_ChainTask_TaskID();
      break;
    case _Schedule:
      break;
    case _GetTaskID:
      break;
    case _GetTaskState:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                                  OSError_GetTaskState_TaskID();
      break;
    #endif /* #if (OS_TASK == STD_ON) */

    /* services for resource */
    #if (OS_RESOURCE == STD_ON)
    case _GetResource:
      GucOsError[GulOsErrorLastPosition].unPar1.OsResourceId =
                                                    OSError_GetResource_ResID();
      break;
    case _ReleaseResource:
      GucOsError[GulOsErrorLastPosition].unPar1.OsResourceId =
                                                OSError_ReleaseResource_ResID();
      break;
    #endif /* #if (OS_RESOURCE == STD_ON) */

    /* services for event */
    #if (OS_EVENT == STD_ON)
    case _SetEvent:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                                      OSError_SetEvent_TaskID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsMaskParam2 =
                                                        OSError_SetEvent_Mask();
      break;
    case _ClearEvent:
      GucOsError[GulOsErrorLastPosition].unPar1.OsMask =
                                                      OSError_ClearEvent_Mask();
      break;
    case _GetEvent:
      GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                                      OSError_GetEvent_TaskID();
      break;
    #endif /* #if (OS_EVENT == STD_ON) */

    /* services for alarm */
    #if (OS_ALARM == STD_ON)
    case _GetAlarmBase:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId =
                                                 OSError_GetAlarmBase_AlarmID();
      break;
    case _GetAlarm:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId =
                                                     OSError_GetAlarm_AlarmID();
      break;
    case _SetRelAlarm:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId =
                                                  OSError_SetRelAlarm_AlarmID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsIncrement =
                                                OSError_SetRelAlarm_Increment();
      GucOsError[GulOsErrorLastPosition].unPar3.OsCycle =
                                                    OSError_SetRelAlarm_Cycle();
      break;
    case _SetAbsAlarm:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId =
                                                  OSError_SetAbsAlarm_AlarmID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsStart =
                                                    OSError_SetAbsAlarm_Start();
      GucOsError[GulOsErrorLastPosition].unPar3.OsCycle =
                                                    OSError_SetAbsAlarm_Cycle();
      break;
    case _CancelAlarm:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId =
                                                  OSError_CancelAlarm_AlarmID();
      break;
    #endif /* #if (OS_ALARM == STD_ON) */

    /* services for counter */
    #if (OS_COUNTER == STD_ON)
    case _IncrementCounter:
      GucOsError[GulOsErrorLastPosition].unPar1.OsCounterId =
                                           OSError_IncrementCounter_CounterID();
      break;
    case _GetCounterValue:
      GucOsError[GulOsErrorLastPosition].unPar1.OsCounterId =
                                            OSError_GetCounterValue_CounterID();
      break;
    case _GetElapsedValue:
      GucOsError[GulOsErrorLastPosition].unPar1.OsCounterId =
                                            OSError_GetElapsedValue_CounterID();
      break;
    #endif /* #if (OS_COUNTER == STD_ON) */

    /* services for scheduletable */
    #if (OS_SCHEDTABLE == STD_ON)
    case _StartScheduleTableRel:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                                OSError_StartScheduleTableRel_ScheduleTableID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsOffset =
                                         OSError_StartScheduleTableRel_Offset();
      break;
    case _StartScheduleTableAbs:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                                OSError_StartScheduleTableAbs_ScheduleTableID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsStart =
                                          OSError_StartScheduleTableAbs_Start();
      break;
    case _StopScheduleTable:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                                    OSError_StopScheduleTable_ScheduleTableID();
      break;
    case _NextScheduleTable:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId_From =
                                OSError_NextScheduleTable_ScheduleTableIDFrom();
      GucOsError[GulOsErrorLastPosition].unPar2.OsScheduleTableId_To =
                                  OSError_NextScheduleTable_ScheduleTableIDTo();
      break;
    #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
    case _StartScheduleTableSynchron:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                           OSError_StartScheduleTableSynchron_ScheduleTableID();
      break;
    case _SyncScheduleTable:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                                    OSError_SyncScheduleTable_ScheduleTableID();
      GucOsError[GulOsErrorLastPosition].unPar2.OsValue =
                                              OSError_SyncScheduleTable_Value();
      break;
    case _SetScheduleTableAsync:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                                OSError_SetScheduleTableAsync_ScheduleTableID();
      break;
    #endif /* #if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */
    case _GetScheduleTableStatus:
      GucOsError[GulOsErrorLastPosition].unPar1.OsScheduleTableId =
                               OSError_GetScheduleTableStatus_ScheduleTableID();
      break;
    #endif /* #if (OS_SCHEDTABLE == STD_ON) */

    #if (OS_SPINLOCK == STD_ON)
    case _GetSpinlock:
      GucOsError[GulOsErrorLastPosition].unPar1.OsSpinlockId =
                                               OSError_GetSpinlock_SpinlockId();
      break;
    case _ReleaseSpinlock:
      GucOsError[GulOsErrorLastPosition].unPar1.OsSpinlockId =
                                           OSError_ReleaseSpinlock_SpinlockId();
      break;
    case _TryToGetSpinlock:
      GucOsError[GulOsErrorLastPosition].unPar1.OsSpinlockId =
                                          OSError_TryToGetSpinlock_SpinlockId();
      break;
    #endif /* #if (OS_SPINLOCK == STD_ON) */

    default:
      GucOsError[GulOsErrorLastPosition].unPar1.OsAlarmId = OS_INVALID_VALUE;
      GucOsError[GulOsErrorLastPosition].unPar2.OsStart = OS_INVALID_VALUE;
      GucOsError[GulOsErrorLastPosition].unPar3.OsCycle = OS_INVALID_VALUE;
      break;
  }
  #endif /* #if (OS_USER_PARAMETER_ACCESS == STD_ON) */

  if (E_OS_LIMIT == LddError)
  {
    Os_GulOsLimitError++;
  }
  if (E_OS_STACKFAULT == LddError)
  {
    Os_GulOsStackFaultError++;

    /* polyspace-begin RTE:IDP [Not a Defect] "array size is limited to number of core" */
    /* polyspace-begin RTE:NIV [Not a Defect] "array size is limited to number of core" */
    /* polyspace-begin RTE:OBAI [Not a Defect] "array size is limited to number of core" */
    /* polyspace-begin MISRA-C3:D4.1 [Not a Defect] "array size is limited to number of core" */
    /* polyspace-begin MISRA-C3:18.1 [Not a Defect] "array size is limited to number of core" */
    GucOsError[GulOsErrorLastPosition].unPar1.OsTaskId =
                                          Os_GpStaticTask[OS_CORE_ID]->ddTaskId;
    /* polyspace-end RTE:IDP */
    /* polyspace-end RTE:NIV */
    /* polyspace-end RTE:OBAI */
    /* polyspace-end MISRA-C3:D4.9 */
    /* polyspace-end MISRA-C3:18.1 */
  }

  GulOsErrorCount++;
} /* End of Os_UpdateErrorHookInfo() */

/*****************************************************************************
 * Function Name        : OS_ClearInterrupt
 *
 * Service ID           : NA
 *
 * Description          : Clears Active Interrupt Source
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            OS_ptscSYSFLT        The pointer to a structure instance
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static FUNC(void, OS_CODE) OS_ClearInterrupt(volatile OS_FAULT_STRUCT *OS_ptscSYSFLT)
{
  OS_ptscSYSFLT->OS_unINTR.OS_stcField.OS_u1FAULT = (boolean)OS_TRUE;
  (void)OS_ptscSYSFLT->OS_unINTR.OS_u32Register;
}

/*****************************************************************************
 * Function Name        : OS_ClearStatus
 *
 * Service ID           : NA
 *
 * Description          : Clear fault status register
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            OS_ptscSYSFLT        The pointer to a structure instance
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static FUNC(void, OS_CODE) OS_ClearStatus(volatile OS_FAULT_STRUCT *OS_ptscSYSFLT)
{
  OS_ptscSYSFLT->OS_unSTATUS.OS_u32Register = 0x00000000UL;
}

/*****************************************************************************
 * Function Name        : OS_SysFlt_GetErrorSource
 *
 * Service ID           : NA
 *
 * Description          : Returns the source of error for the fault
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            OS_ptscSYSFLT        The pointer to a structure instance
 *
 * @return              : OS_FaultStructErrorType
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static FUNC(OS_FaultStructErrorType, OS_CODE) OS_SysFlt_GetErrorSource(volatile OS_FAULT_STRUCT *OS_ptscSYSFLT)
{
  OS_FaultStructErrorType Os_LddReturn = _E_OS_SYSFLT_NO_FAULT;
  if(OS_ptscSYSFLT->OS_unSTATUS.OS_stcField.OS_u1VALID == 1u)
  {
    /* polyspace-begin MISRA-C3:10.5 [Justified:Low] "Not a defect, this is Infineon's guide" */
    Os_LddReturn = (OS_FaultStructErrorType)(OS_ptscSYSFLT->OS_unSTATUS.OS_stcField.OS_u7IDX);
    /* polyspace-end MISRA-C3:10.5 [Justified:Low] "Not a defect, this is Infineon's guide" */
  }
  else
  {
    /* for MISRA-C:2012 15.7 */
  }
  return Os_LddReturn;
}

/*****************************************************************************
 * Function Name        : Os_PreFaultStructureInitCallout
 *
 * Service ID           : NA
 *
 * Description          : This function is used to clear fault structure
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Paramameters           None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        OS_ClearInterrupt(), OS_ClearStatus(),
 *                        OS_SysFlt_GetErrorSource()
 ******************************************************************************/
FUNC(void, OS_CODE) Os_PreFaultStructureInitCallout(void) 
{
  OS_FaultStructErrorType OS_LddFltStatus;

  do {
    OS_ClearInterrupt(OS_FAULT_STRUCT1_REG);
	  OS_ClearStatus(OS_FAULT_STRUCT1_REG);
	  do {
       for(volatile uint32 loop_cnt = 0; loop_cnt < OS_DELAYCOUNTER; loop_cnt++)
       {
         /* Do Nothing. Just for delay of H/W */
       }
    } while(0);
    OS_LddFltStatus = OS_SysFlt_GetErrorSource(OS_FAULT_STRUCT1_REG);
  } while(OS_LddFltStatus != _E_OS_SYSFLT_NO_FAULT);
}

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<MISRA-C3:8.13:Not a defect:Justify with annotations> The pointer points const-qualified type */
/* polyspace:end<RTE:UNR:Not a defect : No Action Planned> This code has already been verified and no impact of this rule violation */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

