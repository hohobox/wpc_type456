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
**  SRC-MODULE: Os_SystemCallTable.h                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : All the OS services utilize CPU system-call.                  **
**              All the OS services renamed as Os_KernXXX().                  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.4     01-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #10100                      **
** 2.3.1     04-May-2017    MJ.Woo        Redmine #8275                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4566, #5368                **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.4     23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:8.8:Not a defect:Justify with annotations> To avoid cross reference, external function is needed.  */
/* polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> Definition for function redirection does not use parenthesised expression */
/* polyspace-begin MISRA-C3:11.1 [Justified:Medium] "To meet system call interface" */


#ifndef OS_SYSTEMCALLTABLE_H_
#define OS_SYSTEMCALLTABLE_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Interrupt.h"         /* Os Interrupt header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Max number of OS service calls */
#define OS_N_SYSCALL   68

extern CONSTP2CONST(void, AUTOMATIC, OS_CONST) Os_GaaSyscallTable[OS_N_SYSCALL];

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*
 OSServiceId_GetApplicationID           0
 OSServiceId_GetISRID                   1
 OSServiceId_CallTrustedFunction        2
 OSServiceId_CheckISRMemoryAccess       3
 OSServiceId_CheckTaskMemoryAccess      4
 OSServiceId_CheckObjectAccess          5
 OSServiceId_CheckObjectOwnership       6
*/
#if (OS_APPLICATION == STD_ON)
extern FUNC(ApplicationType, OS_CODE) Os_KernGetApplicationID(void);
#else
#define Os_KernGetApplicationID   Os_KernUnknownSyscall
#endif
#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
extern FUNC(ISRType, OS_CODE) Os_KernGetISRID(void);
#else
#define Os_KernGetISRID   Os_KernUnknownSyscall
#endif
#if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
extern FUNC(StatusType, OS_CODE) Os_KernCallTrustedFunction(
    TrustedFunctionIndexType FunctionIndex,
    TrustedFunctionParameterRefType FunctionParams);
#else
#define Os_KernCallTrustedFunction   Os_KernUnknownSyscall
#endif
#if (OS_MEMORY_PROTECTION == STD_ON)
extern FUNC(AccessType, OS_CODE) Os_KernCheckISRMemoryAccess(ISRType IsrID,
    MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(AccessType, OS_CODE) Os_KernCheckTaskMemoryAccess(TaskType TaskID,
    MemoryStartAddressType Address, MemorySizeType Size);
extern FUNC(ObjectAccessType, OS_CODE) Os_KernCheckObjectAccess(
    ApplicationType ApplID, ObjectTypeType ObjectType,
    ObjectTypeIndex ObjectID);
#else
#define Os_KernCheckISRMemoryAccess    Os_KernUnknownSyscall
#define Os_KernCheckTaskMemoryAccess   Os_KernUnknownSyscall
#define Os_KernCheckObjectAccess       Os_KernUnknownSyscall
#endif
#if (OS_APPLICATION == STD_ON)
extern FUNC(ApplicationType, OS_CODE) Os_KernCheckObjectOwnership(
    ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);
#else
#define Os_KernCheckObjectOwnership    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_StartScheduleTableRel      7
 OSServiceId_StartScheduleTableAbs      8
 OSServiceId_StopScheduleTable          9
 OSServiceId_NextScheduleTable          10
 OSServiceId_StartScheduleTableSynchron 11
 OSServiceId_SyncScheduleTable          12
 OSServiceId_SetScheduleTableAsync      13
 OSServiceId_GetScheduleTableStatus     14
*/
#if (OS_SCHEDTABLE == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableRel(
    ScheduleTableType ScheduleTableID, TickType Offset);
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableAbs(
    ScheduleTableType ScheduleTableID, TickType Start);
extern FUNC(StatusType, OS_CODE) Os_KernStopScheduleTable(
    ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_KernNextScheduleTable(
    ScheduleTableType ScheduleTableID_From,
    ScheduleTableType ScheduleTableID_To);
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableSynchron(
    ScheduleTableType ScheduleTableID);
extern FUNC(StatusType, OS_CODE) Os_KernSyncScheduleTable(
    ScheduleTableType ScheduleTableID, TickType Value);
extern FUNC(StatusType, OS_CODE) Os_KernSetScheduleTableAsync(
    ScheduleTableType ScheduleTableID);
#else
#define Os_KernStartScheduleTableSynchron   Os_KernUnknownSyscall
#define Os_KernSyncScheduleTable            Os_KernUnknownSyscall
#define Os_KernSetScheduleTableAsync        Os_KernUnknownSyscall
#endif
extern FUNC(StatusType, OS_CODE) Os_KernGetScheduleTableStatus(
    ScheduleTableType ScheduleTableID,
    ScheduleTableStatusRefType ScheduleStatus);
#else
#define Os_KernStartScheduleTableRel        Os_KernUnknownSyscall
#define Os_KernStartScheduleTableAbs        Os_KernUnknownSyscall
#define Os_KernStopScheduleTable            Os_KernUnknownSyscall
#define Os_KernNextScheduleTable            Os_KernUnknownSyscall
#define Os_KernStartScheduleTableSynchron   Os_KernUnknownSyscall
#define Os_KernSyncScheduleTable            Os_KernUnknownSyscall
#define Os_KernSetScheduleTableAsync        Os_KernUnknownSyscall
#define Os_KernGetScheduleTableStatus       Os_KernUnknownSyscall
#endif


/*
 OSServiceId_IncrementCounter           15
 OSServiceId_GetCounterValue            16
 OSServiceId_GetElapsedValue            17
*/
#if (OS_COUNTER == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernIncrementCounter(CounterType CounterID);
extern FUNC(StatusType, OS_CODE) Os_KernGetCounterValue(CounterType CounterID,
    TickRefType Value);
extern FUNC(StatusType, OS_CODE) Os_KernGetElapsedValue(CounterType CounterID,
    TickRefType Value, TickRefType ElapsedValue);
#else
#define Os_KernIncrementCounter   Os_KernUnknownSyscall
#define Os_KernGetCounterValue    Os_KernUnknownSyscall
#define Os_KernGetElapsedValue    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_TerminateApplication       18
 OSServiceId_AllowAccess                19
 OSServiceId_GetApplicationState        20
*/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
extern FUNC(StatusType, OS_CODE) Os_KernTerminateApplication(
    ApplicationType Application, RestartType RestartOption);
extern FUNC(StatusType, OS_CODE) Os_KernAllowAccess(void);
extern FUNC(StatusType, OS_CODE) Os_KernGetApplicationState(
    ApplicationType Application, ApplicationStateRefType Value);
#else
#define Os_KernTerminateApplication   Os_KernUnknownSyscall
#define Os_KernAllowAccess            Os_KernUnknownSyscall
#define Os_KernGetApplicationState    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_ActivateTask               21
 OSServiceId_TerminateTask              22
 OSServiceId_ChainTask                  23
 OSServiceId_Schedule                   24
 OSServiceId_GetTaskID                  25
 OSServiceId_GetTaskState               26
*/
#if (OS_TASK == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernActivateTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_KernTerminateTask(void);
extern FUNC(StatusType, OS_CODE) Os_KernChainTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_KernSchedule(void);
extern FUNC(StatusType, OS_CODE) Os_KernGetTaskID(TaskRefType TaskID);
extern FUNC(StatusType, OS_CODE) Os_KernGetTaskState(TaskType TaskID,
    TaskStateRefType State);
#else
#define Os_KernActivateTask    Os_KernUnknownSyscall
#define Os_KernTerminateTask   Os_KernUnknownSyscall
#define Os_KernChainTask       Os_KernUnknownSyscall
#define Os_KernSchedule        Os_KernUnknownSyscall
#define Os_KernGetTaskID       Os_KernUnknownSyscall
#define Os_KernGetTaskState    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_EnableAllInterrupts        27
 OSServiceId_DisableAllInterrupts       28
 OSServiceId_ResumeAllInterrupts        29
 OSServiceId_SuspendAllInterrupts       30
 OSServiceId_ResumeOSInterrupts         31
 OSServiceId_SuspendOSInterrupts        32
*/
extern FUNC(void, OS_CODE) Os_KernSuspendInterrupts(OsIntLockType locktype);
extern FUNC(void, OS_CODE) Os_KernResumeInterrupts(OsIntLockType locktype);


/*
 OSServiceId_GetResource                33
 OSServiceId_ReleaseResource            34
*/
#if (OS_RESOURCE == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernGetResource(ResourceType ResID);
extern FUNC(StatusType, OS_CODE) Os_KernReleaseResource(ResourceType ResID);
#else
#define Os_KernGetResource       Os_KernUnknownSyscall
#define Os_KernReleaseResource   Os_KernUnknownSyscall
#endif


/*
 OSServiceId_SetEvent                   35
 OSServiceId_ClearEvent                 36
 OSServiceId_GetEvent                   37
 OSServiceId_WaitEvent                  38
*/
#if (OS_EVENT == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernSetEvent(TaskType TaskID,
    EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_KernClearEvent(EventMaskType Mask);
extern FUNC(StatusType, OS_CODE) Os_KernGetEvent(TaskType TaskID,
    EventMaskRefType Event);
extern FUNC(StatusType, OS_CODE) Os_KernWaitEvent(EventMaskType Mask);
#else
#define Os_KernSetEvent     Os_KernUnknownSyscall
#define Os_KernClearEvent   Os_KernUnknownSyscall
#define Os_KernGetEvent     Os_KernUnknownSyscall
#define Os_KernWaitEvent    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_GetAlarmBase               39
 OSServiceId_GetAlarm                   40
 OSServiceId_SetRelAlarm                41
 OSServiceId_SetAbsAlarm                42
 OSServiceId_CancelAlarm                43
*/
#if (OS_ALARM == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernGetAlarmBase(AlarmType AlarmID,
    AlarmBaseRefType Info);
extern FUNC(StatusType, OS_CODE) Os_KernGetAlarm(AlarmType AlarmID,
    TickRefType Tick);
extern FUNC(StatusType, OS_CODE) Os_KernSetRelAlarm(AlarmType AlarmID,
    TickType Increment, TickType Cycle);
extern FUNC(StatusType, OS_CODE) Os_KernSetAbsAlarm(AlarmType AlarmID,
    TickType Start, TickType Cycle);
extern FUNC(StatusType, OS_CODE) Os_KernCancelAlarm(AlarmType AlarmID);
#else
#define Os_KernGetAlarmBase   Os_KernUnknownSyscall
#define Os_KernGetAlarm       Os_KernUnknownSyscall
#define Os_KernSetRelAlarm    Os_KernUnknownSyscall
#define Os_KernSetAbsAlarm    Os_KernUnknownSyscall
#define Os_KernCancelAlarm    Os_KernUnknownSyscall
#endif


/*
 OSServiceId_GetActiveApplicationMode   44
 OSServiceId_StartOS                    45
 OSServiceId_ShutdownOS                 46
*/
extern FUNC(AppModeType, OS_CODE) Os_KernGetActiveApplicationMode(void);
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
extern FUNC(void, OS_CODE) Os_KernStartOS(AppModeType Mode);
extern FUNC(void, OS_CODE) Os_KernShutdownOS(StatusType Error);



/*
 Missing OSServiceId_GetCoreID          47 (See Os.c)
 OSServiceId_GetSpinlock                48
 OSServiceId_ReleaseSpinlock            49
 OSServiceId_TryToGetSpinlock           50
*/
#if (OS_SPINLOCK == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_KernGetSpinlock(SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) Os_KernReleaseSpinlock(
    SpinlockIdType SpinlockId);
extern FUNC(StatusType, OS_CODE) Os_KernTryToGetSpinlock(
    SpinlockIdType SpinlockId,
    P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success);
#else
#define Os_KernGetSpinlock        Os_KernUnknownSyscall
#define Os_KernReleaseSpinlock    Os_KernUnknownSyscall
#define Os_KernTryToGetSpinlock   Os_KernUnknownSyscall
#endif
/*
 Blank                                  51
 Blank                                  52
 Blank                                  53
 Blank                                  54
 Missing StartCore                      55 (See Os.c)
 OSServiceId_ShutdownAllCores           56
 Missing StartNonAutosarCore            57 (See Os_Definition.h)
 Missing GetNumberOfActivatedCores      58 (See Os_Definition.h)
 */
#if (OS_MULTICORE == STD_ON)
extern FUNC(void, OS_CODE) Os_KernShutdownAllCores(StatusType Error);
#else
#define Os_KernShutdownAllCores      Os_KernUnknownSyscall
#endif

/*
 IOCServiceId_IOC_Read                  60
 IOCServiceId_IOC_Write                 61
 IOCServiceId_IOC_Receive               62
 IOCServiceId_IOC_Send                  63
 IOCServiceId_IOC_EmptyQueue            64
 OSServiceId_Os_IocPullCB               65
 */
#if (OS_APPLICATION == STD_ON)
extern FUNC(Std_ReturnType, OS_CODE) Os_KernIocRead(uint32 IocID,
                                     P2VAR(uint8, AUTOMATIC, OS_CONST) data[]);
extern FUNC(Std_ReturnType, OS_CODE) Os_KernIocWrite(uint32 IocID,
                                CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[]);
extern FUNC(Std_ReturnType, OS_CODE) Os_KernIocReceive(uint32 IocID,
                                     P2VAR(uint8, AUTOMATIC, OS_CONST) data[]);
extern FUNC(Std_ReturnType, OS_CODE) Os_KernIocSend(uint32 IocID,
                                CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[]);
extern FUNC(Std_ReturnType, OS_CODE) Os_KernIocEmptyQueue(uint32 IocID);
extern FUNC(void, OS_CODE) Os_KernIocPullCB(
		P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID);
#else
#define Os_KernIocRead       Os_KernUnknownSyscall
#define Os_KernIocWrite      Os_KernUnknownSyscall
#define Os_KernIocReceive    Os_KernUnknownSyscall
#define Os_KernIocSend       Os_KernUnknownSyscall
#define Os_KernIocEmptyQueue Os_KernUnknownSyscall
#define Os_KernIocPullCB     Os_KernUnknownSyscall
#endif

/*
 OSServiceId_Os_ErrorTerminateTask      66
 */
extern FUNC(void, OS_CODE) Os_KernErrorTerminateTask(void);

extern FUNC(void, OS_CODE) Os_KernUnknownSyscall(void);
#endif /* OS_SYSTEMCALLTABLE_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:8.8:Not a defect:Justify with annotations> To avoid cross reference, external function is needed.  */
/* polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> Definition for function redirection does not use parenthesised expression */
/* polyspace-end MISRA-C3:11.1 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


