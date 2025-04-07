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
**  SRC-MODULE: Os_Arch_SystemCall.h                                          **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related (OS) SystemaCall API           **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]:     Yes                                      **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.4.0     04-Jun-2021    YH.Han        Redmine #29686                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 2.0.0     01-Jul-2020    JH.Cho        Redmine #24316                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/
#ifndef OS_ARCH_SYSTEMCALL_H_
#define OS_ARCH_SYSTEMCALL_H_

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern FUNC(StatusType, OS_CODE) Os_KernStopScheduleTable(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_KernNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern FUNC(StatusType, OS_CODE) Os_KernGetScheduleTableStatus(ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
#endif
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_KernSyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
extern FUNC(StatusType, OS_CODE) Os_KernSetScheduleTableAsync(ScheduleTableType ScheduleTableID);
#endif
#if (OS_SPINLOCK == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernGetSpinlock(SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) Os_KernReleaseSpinlock(SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) Os_KernTryToGetSpinlock(SpinlockIdType SpinlockId, P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success);
#endif
#if (OS_APPLICATION == STD_ON)
extern FUNC(ApplicationType, OS_CODE) Os_KernGetApplicationID(void);
extern FUNC(StatusType, OS_CODE) Os_KernAllowAccess(void);
extern FUNC(StatusType, OS_CODE) Os_KernGetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
extern FUNC(StatusType, OS_CODE) Os_KernTerminateApplication(ApplicationType Application, RestartType RestartOption);
#endif
#if (OS_SCALABILITY_CLASS >= OS_SC3)
extern FUNC(AccessType, OS_CODE) Os_KernCheckISRMemoryAccess(ISRType IsrID, MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(AccessType, OS_CODE) Os_KernCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(ObjectAccessType, OS_CODE) Os_KernCheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
extern FUNC(ApplicationType, OS_CODE) Os_KernCheckObjectOwnership(ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
#endif
#if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
extern FUNC(StatusType, OS_CODE) Os_KernCallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#endif
#if (OS_MULTICORE == STD_ON)
extern FUNC(void, OS_CODE) Os_KernShutdownAllCores(StatusType Error);
#endif


//======================================================================================


#if (OS_ALARM == STD_ON)
extern StatusType Os_SystemCallGetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info);
extern StatusType Os_SystemCallGetAlarm(AlarmType AlarmID,  TickRefType Tick);
extern StatusType Os_SystemCallSetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle);
extern StatusType Os_SystemCallSetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle);
extern StatusType Os_SystemCallCanCelAlarm(AlarmType AlarmID);
#endif
#if (OS_APPLICATION == STD_ON)
/* Inline function for GetApplicationID() system call */
extern ApplicationType Os_SystemCallGetApplicationID(void);
extern ApplicationType Os_SystemCallCheckObjectOwnership(ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
#if (OS_MEMORY_PROTECTION == STD_ON)
extern ObjectAccessType Os_SystemCallCheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
extern StatusType Os_SystemCallTerminateApplication(ApplicationType Application, RestartType RestartOption);
extern StatusType Os_SystemCallAllowAccess(void);
extern StatusType Os_SystemCallGetApplicationState(ApplicationType Application, ApplicationStateRefType Value);
extern AccessType Os_SystemCallCheckISRMemoryAccess(ISRType IsrID, MemoryStartAddressType Address, MemorySizeType Size);
extern AccessType Os_SystemCallCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size);
#if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
extern StatusType Os_SystemCallCallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams);
#endif /* (OS_TRUSTED_FUNC_COUNT != OS_ZERO) */
#endif /* (OS_MEMORY_PROTECTION == STD_ON) */
#endif /* (OS_APPLICATION == STD_ON) */
#if (OS_COUNTER == STD_ON)
extern StatusType Os_SystemCallIncrementCounter(CounterType CounterID);
extern StatusType Os_SystemCallGetCounterValue(CounterType CounterID, TickRefType Value);
extern StatusType Os_SystemCallGetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue);
#endif
#if (OS_EVENT == STD_ON)
extern StatusType Os_SystemCallSetEvent(TaskType TaskID, EventMaskType Mask);
extern StatusType Os_SystemCallClearEvent(EventMaskType Mask);
extern StatusType Os_SystemCallGetEvent(TaskType TaskID, EventMaskRefType Event);
extern StatusType Os_SystemCallWaitEvent(EventMaskType Mask);
#endif
#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
extern ISRType Os_SystemCallGetISRID(void);
#endif
#if (OS_SPINLOCK == STD_ON)
extern StatusType Os_SystemCallReleaseSpinlock(SpinlockIdType SpinlockId);
extern StatusType Os_SystemCallTryToGetSpinlock(SpinlockIdType SpinlockId,  P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success);
#endif
#if (OS_MULTICORE == STD_ON)
extern void Os_SystemCallShutdownAllCores(StatusType Error);
#endif
extern AppModeType Os_SystemCallGetActiveApplicationMode(void);
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
extern void Os_SystemCallStartOS(AppModeType Mode);
extern void Os_SystemCallShutdownOS(StatusType Error);
#if (OS_RESOURCE == STD_ON)
extern StatusType Os_SystemCallGetResource(ResourceType ResID);
extern StatusType Os_SystemCallReleaseResource(ResourceType ResID);
#endif
#if (OS_SCHEDTABLE == STD_ON)
extern StatusType Os_SystemCallStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset);
extern StatusType Os_SystemCallStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start);
extern StatusType Os_SystemCallStopScheduleTable(ScheduleTableType ScheduleTableID);
extern StatusType Os_SystemCallNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
extern StatusType Os_SystemCallStartScheduleTableSynchron(ScheduleTableType ScheduleTableID);
extern StatusType Os_SystemCallSyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value);
extern StatusType Os_SystemCallSetScheduleTableAsync(ScheduleTableType ScheduleTableID);
extern StatusType Os_SystemCallGetScheduleTableStatus(ScheduleTableType ScheduleTableID,  ScheduleTableStatusRefType ScheduleStatus);
#endif
#if (OS_TASK == STD_ON)
extern StatusType Os_SystemCallActivateTask(TaskType TaskID);
extern StatusType Os_SystemCallTerminateTask(void);
extern StatusType Os_SystemCallChainTask(TaskType TaskID);
extern StatusType Os_SystemCallSchedule(void);
extern StatusType Os_SystemCallGetTaskID(TaskRefType TaskID);
extern StatusType Os_SystemCallGetTaskState(TaskType TaskID, TaskStateRefType State);
#endif
#if (OS_MULTICORE == STD_ON)
extern CoreIdType Os_SystemCallGetCoreID(void);
#endif
#if (OS_APPLICATION == STD_ON)
extern Std_ReturnType Os_SystemCallIocRead(uint32 IocID, P2VAR(uint8, AUTOMATIC, OS_CONST) data[]);
extern Std_ReturnType Os_SystemCallIocWrite(uint32 IocID, CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[]);
extern Std_ReturnType Os_SystemCallIocReceive(uint32 IocID, P2VAR(uint8, AUTOMATIC, OS_CONST) data[]);
extern Std_ReturnType Os_SystemCallIocSend(uint32 IocID, CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[]);
extern Std_ReturnType Os_SystemCallIocEmptyQueue(uint32 IocID);

extern void Os_SystemCallIocPullCB(P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID);
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*****************************************************************************
 * Function Name        : Os_CanUseSvc
 *
 * Service ID           : NA
 *
 * Description          : Check whether SVC instruction is available
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : TRUE - SVC available, FALSE - SVC not available
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_005}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
static inline boolean Os_CanUseSvc(void)
{
  uint32 ipsrRegVal;
  uint32 faultmaskRegVal;
  uint32 primaskRegVal;
  boolean canUseSvc;

  ipsrRegVal = __MRS(__IPSR);
  faultmaskRegVal = __MRS(__FAULTMASK);
  primaskRegVal = __MRS(__PRIMASK);

  if ((ipsrRegVal == OS_ZERO) &&      /* Check whether Exception handler */
      (faultmaskRegVal == OS_ZERO) && /* To prevent lockup */
      (primaskRegVal == OS_ZERO))     /* To prevent priority escalation */
  {
    canUseSvc = TRUE;
  }
  else
  {
    canUseSvc = FALSE;
  }

  return canUseSvc;
}

#if (OS_ALARM == STD_ON)
/* Inline function for GetAlarmBase() system call */
static inline StatusType OS_SYSCALL_GETALARMBASE(AlarmType AlarmID, AlarmBaseRefType Info)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetAlarmBase);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetAlarmBase(AlarmID, Info);
  }
  return LddStatusReturn;
}

/* Inline function for GetAlarm() system call */
static inline StatusType OS_SYSCALL_GETALARM(AlarmType AlarmID,  TickRefType Tick)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetAlarm);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetAlarm(AlarmID, Tick);
  }
  return LddStatusReturn;
}

/* Inline function for GetAlarmBase() system call */
static inline StatusType OS_SYSCALL_SETRELALARM(AlarmType AlarmID, TickType Increment,
                                                                          TickType Cycle)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_SetRelAlarm);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallSetRelAlarm(AlarmID, Increment, Cycle);
  }
  return LddStatusReturn;
}

/* Inline function for SetAbsAlarm() system call */
static inline StatusType OS_SYSCALL_SETABSALARM(AlarmType AlarmID, TickType Start, TickType Cycle)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_SetAbsAlarm);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallSetAbsAlarm(AlarmID, Start, Cycle);
  }
  return LddStatusReturn;
}

/* Inline function for CancelAlarm() system call */
static inline StatusType OS_SYSCALL_CANCELALARM(AlarmType AlarmID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CancelAlarm);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallCanCelAlarm(AlarmID);
  }
  return LddStatusReturn;
}
#endif /* (OS_ALARM == STD_ON) */

#if (OS_APPLICATION == STD_ON)
/* Inline function for GetApplicationID() system call */
static inline ApplicationType OS_SYSCALL_GETAPPLICATIONID(void)
{
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetApplicationID);
    __asm("mov %0, r0" : "=r" (LddApplicationID) :);
  }
  else
  {
    /* Handler Mode */
    LddApplicationID = Os_SystemCallGetApplicationID();
  }
  return LddApplicationID;
}

/* Inline function for CheckObjectOwnership() system call */
static inline ApplicationType OS_SYSCALL_CHECKOBJECTOWNERSHIP(ObjectTypeType ObjectType,
                                                       ObjectTypeIndex ObjectID)
{
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CheckObjectOwnership);
    __asm("mov %0, r0" : "=r" (LddApplicationID) :);
  }
  else
  {
    /* Handler Mode */
    LddApplicationID = Os_SystemCallCheckObjectOwnership(ObjectType, ObjectID);
  }
  return LddApplicationID;
}

#if (OS_MEMORY_PROTECTION == STD_ON)
/* Inline function for CheckObjectAccess() system call */
static inline ObjectAccessType OS_SYSCALL_CHECKOBJECTACCESS(ApplicationType ApplID,
                                                     ObjectTypeType ObjectType,
                                                     ObjectTypeIndex ObjectID)
{
  ObjectAccessType LddAccessReturn = NO_ACCESS;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CheckObjectAccess);
    __asm("mov %0, r0" : "=r" (LddAccessReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddAccessReturn = Os_SystemCallCheckObjectAccess(ApplID, ObjectType, ObjectID);
  }
  return LddAccessReturn;
}

/* Inline function for TerminateApplication() system call */
static inline StatusType OS_SYSCALL_TERMINATEAPPLICATION(ApplicationType Application,
                                                  RestartType RestartOption)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_TerminateApplication);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallTerminateApplication(Application, RestartOption);
  }
  return LddStatusReturn;
}

/* Inline function for AllowAccess() system call */
static inline StatusType OS_SYSCALL_ALLOWACCESS(void)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_AllowAccess);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallAllowAccess();
  }
  return LddStatusReturn;
}

/* Inline function for GetApplicationState() system call */
static inline StatusType OS_SYSCALL_GETAPPLICATIONSTATE(ApplicationType Application,
                                                 ApplicationStateRefType Value)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetApplicationState);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetApplicationState(Application, Value);
  }
  return LddStatusReturn;
}

/* Inline function for CheckISRMemoryAccess() system call */
static inline AccessType OS_SYSCALL_CHECKISRMEMORYACCESS(ISRType IsrID,
                                                  MemoryStartAddressType Address,
                                                  MemorySizeType Size)
{
  AccessType LddAccessReturn = NO_ACCESS;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CheckISRMemoryAccess);
    __asm("mov %0, r0" : "=r" (LddAccessReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddAccessReturn = Os_SystemCallCheckISRMemoryAccess(IsrID, Address, Size);
  }
  return LddAccessReturn;
}

/* Inline function for CheckTaskMemoryAccess() system call */
static inline AccessType OS_SYSCALL_CHECKTASKMEMORYACCESS(TaskType TaskID,
                                                   MemoryStartAddressType Address,
                                                   MemorySizeType Size)
{
  AccessType LddAccessReturn = NO_ACCESS;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CheckTaskMemoryAccess);
    __asm("mov %0, r0" : "=r" (LddAccessReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddAccessReturn = Os_SystemCallCheckTaskMemoryAccess(TaskID, Address, Size);
  }
  return LddAccessReturn;
}

#if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
/* Inline function for CallTrustedFunction() system call */
static inline StatusType OS_SYSCALL_CALLTRUSTEDFUNCTION(TrustedFunctionIndexType FunctionIndex,
                                                 TrustedFunctionParameterRefType FunctionParams)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_CallTrustedFunction);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallCallTrustedFunction(FunctionIndex, FunctionParams);
  }
  return LddStatusReturn;
}
#endif /* (OS_TRUSTED_FUNC_COUNT != OS_ZERO) */
#endif /* (OS_MEMORY_PROTECTION == STD_ON) */
#endif /* (OS_APPLICATION == STD_ON) */

#if (OS_COUNTER == STD_ON)
/* Inline function for IncrementCounter() system call */
static inline StatusType OS_SYSCALL_INCREMENTCOUNTER(CounterType CounterID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_IncrementCounter);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIncrementCounter(CounterID);
  }
  return LddStatusReturn;
}

/* Inline function for GetCounterValue() system call */
static inline StatusType OS_SYSCALL_GETCOUNTERVALUE(CounterType CounterID, TickRefType Value)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetCounterValue);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetCounterValue(CounterID, Value);
  }
  return LddStatusReturn;
}

/* Inline function for GetElapsedValue() system call */
static inline StatusType OS_SYSCALL_GETELAPSEDVALUE(CounterType CounterID,
                                             TickRefType Value,
                                             TickRefType ElapsedValue)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetElapsedValue);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetElapsedValue(CounterID, Value, ElapsedValue);
  }
  return LddStatusReturn;
}
#endif /* (OS_COUNTER == STD_ON) */

#if (OS_EVENT == STD_ON)
/* Inline function for SetEvent() system call */
static inline StatusType OS_SYSCALL_SETEVENT(TaskType TaskID, EventMaskType Mask)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_SetEvent);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallSetEvent(TaskID, Mask);
  }
  return LddStatusReturn;
}

/* Inline function for ClearEvent() system call */
static inline StatusType OS_SYSCALL_CLEAREVENT(EventMaskType Mask)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ClearEvent);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallClearEvent(Mask);
  }
  return LddStatusReturn;
}

/* Inline function for GetEvent() system call */
static inline StatusType OS_SYSCALL_GETEVENT(TaskType TaskID, EventMaskRefType Event)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetEvent);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetEvent(TaskID, Event);
  }
  return LddStatusReturn;
}

/* Inline function for WaitEvent() system call */
static inline StatusType OS_SYSCALL_WAITEVENT(EventMaskType Mask)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_WaitEvent);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallWaitEvent(Mask);
  }
  return LddStatusReturn;
}
#endif /*(OS_EVENT == STD_ON) */

/* Inline function for EnableAllInterrupts() system call */
static inline void OS_SYSCALL_ENABLEALLINTERRUPTS(void)
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_NONEST;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_EnableAllInterrupts);
}

/* Inline function for EnableAllInterrupts() system call */
static inline void OS_SYSCALL_DISABLEALLINTERRUPTS(void)
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_NONEST;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_DisableAllInterrupts);
}

/* Inline function for EnableAllInterrupts() system call */
static inline void OS_SYSCALL_RESUMEALLINTERRUPTS(void) 
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_ALL;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_ResumeAllInterrupts);
}

/* Inline function for EnableAllInterrupts() system call */
static inline void OS_SYSCALL_SUSPENDALLINTERRUPTS(void) 
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_ALL;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_SuspendAllInterrupts);
}

/* Inline function for ResumeOSInterrupts() system call */
static inline void OS_SYSCALL_RESUMEOSINTERRUPTS(void)
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_OS;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_ResumeOSInterrupts);
}

/* Inline function for SuspendOSInterrupts() system call */
static inline void OS_SYSCALL_SUSPENDOSINTERRUPTS(void)
{
  volatile OsIntLockType LddLock;
  /* To prevent 'r0' to be removed */
  /* polyspace +2 MISRA-C3:10.3 [Justified:Medium] "Same type was used" */
  LddLock = OS_LOCKTYPE_OS;
  /* Thread Mode & non-privilege */
  __SVC(OSServiceId_SuspendOSInterrupts);
}

#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
/* Inline function for GetISRID() system call */
static inline ISRType OS_SYSCALL_GETISRID(void)
{
  ISRType isrId = INVALID_ISR;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetISRID);
    __asm("mov %0, r0" : "=r" (isrId) :);
  }
  else
  {
    isrId = Os_SystemCallGetISRID();
  }
  return isrId;
}
#endif

#if (OS_SPINLOCK == STD_ON)
/* Inline function for ReleaseSpinlock() system call */
static inline StatusType OS_SYSCALL_RELEASESPINLOCK(SpinlockIdType SpinlockId)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ReleaseSpinlock);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallReleaseSpinlock(SpinlockId);
  }
  return LddStatusReturn;
}

/* Inline function for TryToGetSpinlock() system call */
static inline StatusType OS_SYSCALL_TRYTOGETSPINLOCK(SpinlockIdType SpinlockId,
                                             P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_TryToGetSpinlock);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallTryToGetSpinlock(SpinlockId, Success);
  }
  return LddStatusReturn;
}
#endif /* End of if (OS_SPINLOCK == STD_ON) */

#if (OS_MULTICORE == STD_ON)
/* Inline function for ShutdownAllCores() system call */
static inline void OS_SYSCALL_SHUTDOWNALLCORES(StatusType Error)
{
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ShutdownAllCores);
  }
  else
  {
    Os_SystemCallShutdownAllCores(Error);
  }
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

/* Inline function for GetActiveApplicationMode() system call */
static inline AppModeType OS_SYSCALL_GETACTIVEAPPLICATIONMODE(void)
{
  AppModeType LddApplicationMode = OSDEFAULTAPPMODE;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetActiveApplicationMode);
    __asm("mov %0, r0" : "=r" (LddApplicationMode) :);
  }
  else
  {
    LddApplicationMode = Os_SystemCallGetActiveApplicationMode();
  }
  return LddApplicationMode;
}

/* Inline function for StartOS() system call */
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
static inline void OS_SYSCALL_STARTOS(AppModeType Mode)
{
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_StartOS);
  }
  else
  {
    /* Handler Mode */
    Os_SystemCallStartOS(Mode);
  }
}

/* Inline function for StartOS() system call */
static inline void OS_SYSCALL_SHUTDOWNOS(StatusType Error)
{
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ShutdownOS);
  }
  else
  {
    /* Handler Mode */
    Os_SystemCallShutdownOS(Error);
  }
}

#if (OS_RESOURCE == STD_ON)
/* Inline function for GetResource() system call */
static inline StatusType OS_SYSCALL_GETRESOURCE(ResourceType ResID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetResource);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetResource(ResID);
  }
  return LddStatusReturn;
}

/* Inline function for ReleaseResource() system call */
static inline StatusType OS_SYSCALL_RELEASERESOURCE(ResourceType ResID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ReleaseResource);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallReleaseResource(ResID);
  }
  return LddStatusReturn;
}
#endif /* (OS_RESOURCE == STD_ON) */

#if (OS_SCHEDTABLE == STD_ON)
/* Inline function for StartScheduleTableRel() system call */
static inline StatusType OS_SYSCALL_STARTSCHEDULETABLEREL(ScheduleTableType ScheduleTableID,
                                                   TickType Offset)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_StartScheduleTableRel);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallStartScheduleTableRel(ScheduleTableID, Offset);
  }
  return LddStatusReturn;
}

/* Inline function for StartScheduleTableAbs() system call */
static inline StatusType OS_SYSCALL_STARTSCHEDULETABLEABS(ScheduleTableType ScheduleTableID,
                                                   TickType Start)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_StartScheduleTableAbs);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallStartScheduleTableAbs(ScheduleTableID, Start);
  }
  return LddStatusReturn;
}

/* Inline function for StopScheduleTable() system call */
static inline StatusType OS_SYSCALL_STOPSCHEDULETABLE(ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_StopScheduleTable);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallStopScheduleTable(ScheduleTableID);
  }
  return LddStatusReturn;
}

/* Inline function for NextScheduleTable() system call */
static inline StatusType OS_SYSCALL_NEXTSCHEDULETABLE(ScheduleTableType ScheduleTableID_From,
                                               ScheduleTableType ScheduleTableID_To)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_NextScheduleTable);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallNextScheduleTable(ScheduleTableID_From, ScheduleTableID_To);
  }
  return LddStatusReturn;
}

#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
/* Inline function for StartScheduleTableSynchron() system call */
static inline StatusType OS_SYSCALL_STARTSCHEDULETABLESYNCHRON(ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_StartScheduleTableSynchron);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallStartScheduleTableSynchron(ScheduleTableID);
  }
  return LddStatusReturn;
}

/* Inline function for OSServiceId_SyncScheduleTable() system call */
static inline StatusType OS_SYSCALL_SYNCSCHEDULETABLE(ScheduleTableType ScheduleTableID,
                                                                          TickType Value)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_SyncScheduleTable);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallSyncScheduleTable(ScheduleTableID, Value);
  }
  return LddStatusReturn;
}

/* Inline function for SetScheduleTableAsync() system call */
static inline StatusType OS_SYSCALL_SETSCHEDULETABLEASYNC(ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_SetScheduleTableAsync);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallSetScheduleTableAsync(ScheduleTableID);
  }
  return LddStatusReturn;
}
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/* Inline function for GetScheduleTableStatus() system call */
static inline StatusType OS_SYSCALL_GETSCHEDULETABLESTATUS(ScheduleTableType ScheduleTableID,
                                                    ScheduleTableStatusRefType ScheduleStatus)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetScheduleTableStatus);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    LddStatusReturn = Os_SystemCallGetScheduleTableStatus(ScheduleTableID, ScheduleStatus);
  }
  return LddStatusReturn;
}
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#if (OS_TASK == STD_ON)
/* Inline function for ActivateTask() system call */
static inline StatusType OS_SYSCALL_ACTIVATETASK(TaskType TaskID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ActivateTask);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallActivateTask(TaskID);
  }
  return LddStatusReturn;
}

/* Inline function for TerminateTask() system call */
static inline StatusType OS_SYSCALL_TERMINATETASK(void)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_TerminateTask);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallTerminateTask();
  }
  return LddStatusReturn;
}

/* Inline function for ChainTask() system call */
static inline StatusType OS_SYSCALL_CHAINTASK(TaskType TaskID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_ChainTask);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallChainTask(TaskID);
  }
  return LddStatusReturn;
}

/* Inline function for Schedule() system call */
static inline StatusType OS_SYSCALL_SCHEDULE(void)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_Schedule);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallSchedule();
  }
  return LddStatusReturn;
}

/* Inline function for GetTaskID() system call */
static inline StatusType OS_SYSCALL_GETTASKID(TaskRefType TaskID)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetTaskID);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetTaskID(TaskID);
  }
  return LddStatusReturn;
}

/* Inline function for GetTaskState() system call */
static inline StatusType OS_SYSCALL_GETTASKSTATE(TaskType TaskID, TaskStateRefType State)
{
  StatusType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetTaskState);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallGetTaskState(TaskID, State);
  }
  return LddStatusReturn;
}
#endif /* (OS_TASK == STD_ON) */

#if (OS_MULTICORE == STD_ON)
/* Inline function for GetCoreID() system call */
static inline CoreIdType OS_SYSCALL_GETCOREID(void)
{
  CoreIdType LddCoreID = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_GetCoreID);
    __asm("mov %0, r0" : "=r" (LddCoreID) :);
  }
  else
  {
    /* Handler Mode */
    LddCoreID = Os_SystemCallGetCoreID();
  }
  return LddCoreID;
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

#if (OS_APPLICATION == STD_ON)
/* Inline function for IocRead() system call */
static inline Std_ReturnType OS_SYSCALL_IOCREAD(uint32 IocID,
                                              P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
{
  Std_ReturnType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(IOCServiceId_IOC_Read);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIocRead(IocID, data);
  }
  return LddStatusReturn;
}

/* Inline function for IocWrite() system call */
static inline Std_ReturnType OS_SYSCALL_IOCWRITE(uint32 IocID,
                                         CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  Std_ReturnType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(IOCServiceId_IOC_Write);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIocWrite(IocID, data);
  }
  return LddStatusReturn;
}

/* Inline function for IocReceive() system call */
static inline Std_ReturnType OS_SYSCALL_IOCRECEIVE(uint32 IocID,
                                              P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
{
  Std_ReturnType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(IOCServiceId_IOC_Receive);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIocReceive(IocID, data);
  }
  return LddStatusReturn;
}

/* Inline function for IocSend() system call */
static inline Std_ReturnType OS_SYSCALL_IOCSEND(uint32 IocID,
                                         CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  Std_ReturnType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(IOCServiceId_IOC_Send);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIocSend(IocID, data);
  }
  return LddStatusReturn;
}

/* Inline function for IocSend() system call */
static inline Std_ReturnType OS_SYSCALL_IOCEMPTYQUEUE(uint32 IocID)
{
  Std_ReturnType LddStatusReturn = E_OK;
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(IOCServiceId_IOC_EmptyQueue);
    __asm("mov %0, r0" : "=r" (LddStatusReturn) :);
  }
  else
  {
    /* Handler Mode */
    LddStatusReturn = Os_SystemCallIocEmptyQueue(IocID);
  }
  return LddStatusReturn;
}

/* Inline function for Os_IocPullCB() system call */
static inline void OS_SYSCALL_IOCPULLCB(P2FUNC(void, OS_CONST, pIocPullCB)(void),
                                 ApplicationType recvAppID)
{
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_Os_IocPullCB);
  }
  else
  {
    /* Handler Mode */
    Os_SystemCallIocPullCB(pIocPullCB, recvAppID);
  }
}
#endif /* (OS_APPLICATION == STD_ON)*/

/* Inline function for Os_ErrorTerminateTask() system call */
static inline void OS_SYSCALL_ERRORTERMINATETASK(void)
{
  boolean canUseSvc;

  canUseSvc = Os_CanUseSvc();
  if(canUseSvc == TRUE)
  {
    /* Thread Mode */
    __SVC(OSServiceId_Os_ErrorTerminateTask);
  }
  else
  {
    /* Do nothing */
  }
}

#endif /* OS_ARCH_SYSTEMCALL_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
