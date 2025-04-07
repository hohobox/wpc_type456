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
**  SRC-MODULE: Os_SystemCallTable.c                                          **
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
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.3.1     04-May-2017    MJ.Woo        Redmine #8275                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.4     22-Nov-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
**                          MJ.Woo                                            **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:begin<MISRA-C:11.1:Not a defect:Justify with annotations> For implementation, conversion from function pointer to void pointer is needed to represent function address */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_SystemCallTable.h"
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Interrupt.h"         /* Os Interrupt header file */
#include "Os_Multicore.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define OS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
CONSTP2CONST(void, AUTOMATIC, OS_CONST) Os_GaaSyscallTable[OS_N_SYSCALL] =
{
  &Os_KernGetApplicationID,
  &Os_KernGetISRID,
  &Os_KernCallTrustedFunction,
  &Os_KernCheckISRMemoryAccess,
  &Os_KernCheckTaskMemoryAccess,
  &Os_KernCheckObjectAccess,
  &Os_KernCheckObjectOwnership,
  &Os_KernStartScheduleTableRel,
  &Os_KernStartScheduleTableAbs,
  &Os_KernStopScheduleTable,
  &Os_KernNextScheduleTable,
  &Os_KernStartScheduleTableSynchron,
  &Os_KernSyncScheduleTable,
  &Os_KernSetScheduleTableAsync,
  &Os_KernGetScheduleTableStatus,
  &Os_KernIncrementCounter,
  &Os_KernGetCounterValue,
  &Os_KernGetElapsedValue,
  &Os_KernTerminateApplication,
  &Os_KernAllowAccess,
  &Os_KernGetApplicationState,
  &Os_KernActivateTask,
  &Os_KernTerminateTask,
  &Os_KernChainTask,
  &Os_KernSchedule,
  &Os_KernGetTaskID,
  &Os_KernGetTaskState,
  &Os_KernResumeInterrupts,
  &Os_KernSuspendInterrupts,
  &Os_KernResumeInterrupts,
  &Os_KernSuspendInterrupts,
  &Os_KernResumeInterrupts,
  &Os_KernSuspendInterrupts,
  &Os_KernGetResource,
  &Os_KernReleaseResource,
  &Os_KernSetEvent,
  &Os_KernClearEvent,
  &Os_KernGetEvent,
  &Os_KernWaitEvent,
  &Os_KernGetAlarmBase,
  &Os_KernGetAlarm,
  &Os_KernSetRelAlarm,
  &Os_KernSetAbsAlarm,
  &Os_KernCancelAlarm,
  &Os_KernGetActiveApplicationMode,
  &Os_KernStartOS,
  &Os_KernShutdownOS,
  &Os_KernGetCoreID,          /* 47 OSServiceId_GetCoreID */
  &Os_KernGetSpinlock,
  &Os_KernReleaseSpinlock,
  &Os_KernTryToGetSpinlock,
  &Os_KernUnknownSyscall,     /* 51 */
  &Os_KernUnknownSyscall,     /* 52 */
  &Os_KernUnknownSyscall,     /* 53 */
  &Os_KernUnknownSyscall,     /* 54 */
  &Os_KernUnknownSyscall,     /* 55 OSServiceId_StartCore */
  &Os_KernShutdownAllCores,
  &Os_KernUnknownSyscall,     /* 57 */
  &Os_KernUnknownSyscall,     /* 58 */
  &Os_KernUnknownSyscall,     /* 59 */
  &Os_KernIocRead,            /* 60 */
  &Os_KernIocWrite,           /* 61 */
  &Os_KernIocReceive,         /* 62 */
  &Os_KernIocSend,            /* 63 */
  &Os_KernIocEmptyQueue,      /* 64 */
  &Os_KernIocPullCB,          /* 65 */
  &Os_KernErrorTerminateTask, /* 66 */
  &Os_KernUnknownSyscall      /* 67 */
};
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Os_KernUnknownSyscall                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function does Nothing                          **
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
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
/* polyspace +2 MISRA-C3:8.7 [Not a defect:Low] "External visible function" */
FUNC(void, OS_CODE) Os_KernUnknownSyscall(void)
{

}
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:end<MISRA-C:11.1:Not a defect:Justify with annotations> For implementation, conversion from function pointer to void pointer is needed to represent function address */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


