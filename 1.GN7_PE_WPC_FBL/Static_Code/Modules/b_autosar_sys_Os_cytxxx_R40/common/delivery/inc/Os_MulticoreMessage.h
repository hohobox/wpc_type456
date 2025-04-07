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
**  SRC-MODULE: Os_MulticoreMessage.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_MulticoreMessage.c file containing the     **
**              declaration of Inter-core Message functionality related       **
**              functions.                                                    **
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
** 2.6.11    10-Feb-2022    YH.Han        Redmine #34322                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     08-Apr-2020    JH.Cho        Redmine #22760                      **
** 2.5.0     26-Jun-2018    SH.Yoo        Redmine #12780                      **
** 2.3.0     28-Mar-2017    SH.Yoo        Redmine #5967                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee,MJ.Woo Redmine #3963                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.6     08-Jan-2014    SH.Yoo        TASK: xar~810                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     26-Mar-2013   Son            Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_MULTICOREMESSAGE_H
#define OS_MULTICOREMESSAGE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)

#define OS_MESSAGEQLOCKBASE       (OS_SPIN_LOCK_ZERO+1)

#define OS_IC_UnknownCall                  (0)
#define OS_IC_ActivateTask                 (1)
#define OS_IC_GetTaskState                 (2)
#define OS_IC_SetEvent                     (3)
#define OS_IC_GetEvent                     (4)
#define OS_IC_GetAlarm                     (5)
#define OS_IC_GetAlarmBase                 (6)
#define OS_IC_SetRelAlarm                  (7)
#define OS_IC_SetAbsAlarm                  (8)
#define OS_IC_CancelAlarm                  (9)
#define OS_IC_GetCounterValue              (10)
#define OS_IC_GetElapsedCounterValue       (11)
#define OS_IC_StartScheduleTableRel        (12)
#define OS_IC_StartScheduleTableAbs        (13)
#define OS_IC_ChainScheduleTable           (14)
#define OS_IC_StopScheduleTable            (15)
#define OS_IC_GetScheduleTableStatus       (16)
#define OS_IC_StartScheduleTableSynchron   (17)
#define OS_IC_SetScheduleTableAsync        (18)
#define OS_IC_SyncScheduleTable            (19)
#define OS_IC_TerminateApplication         (20)
#define OS_IC_GetApplicationState          (21)
#define OS_IC_ShutdownCore                 (22)
#define OS_IC_IocPullCB                    (23)

#define OS_N_INTERCORE                     (OS_IC_IocPullCB+1)

/* polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> External linkage with array size makes error because of compiler optimization  */
extern Os_MessageQueueType Os_GaaInterCoreMsgQ[];

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"
FUNC(void, OS_CODE) Os_InitMessageQueue(void);
FUNC(StatusType, OS_CODE) Os_SendMessageWait(uint16 CoreID, Os_MessageType *msg);
FUNC(void, OS_CODE) Os_SendShutdownAllCores(uint16 CoreID, StatusType Error);
FUNC(uint16, OS_CODE) Os_SendMessage(uint16 CoreID, const Os_MessageType *msg);
FUNC(void, OS_CODE) Os_ReceiveMessage(uint16 CoreID);
FUNC(void, OS_CODE) Os_RecvDuringShutdown(uint16 CoreID);

/* Individual message senders */
extern FUNC(StatusType, OS_CODE) Os_SendActivateTask(TaskType TaskID);
extern FUNC(StatusType, OS_CODE) Os_SendGetTaskState
  (P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) t, TaskStateRefType out);
extern FUNC(StatusType, OS_CODE) Os_SendSetEvent
  (P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) t, EventMaskType e);
extern FUNC(StatusType, OS_CODE) Os_SendGetEvent
  (TaskType TaskID, EventMaskRefType Event);

extern FUNC(StatusType, OS_CODE) Os_SendGetAlarm(AlarmType a, TickRefType out);
extern FUNC(StatusType, OS_CODE) Os_SendGetAlarmBase(AlarmType AlarmID, \
    AlarmBaseRefType Info);
extern FUNC(StatusType, OS_CODE) Os_SendSetRelAlarm
  (AlarmType a, TickType inc, TickType cyc);
extern FUNC(StatusType, OS_CODE) Os_SendSetAbsAlarm
  (AlarmType a, TickType Start, TickType cyc);
extern FUNC(StatusType, OS_CODE) Os_SendCancelAlarm(AlarmType a);

extern FUNC(StatusType, OS_CODE) Os_SendGetCounterValue
  (CounterType c, TickRefType out);
extern FUNC(StatusType, OS_CODE) Os_SendGetElapsedCounterValue
  (CounterType c, TickRefType Value, TickRefType ElapsedValue);
extern FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableRel
  (ScheduleTableType s, TickType Offset);
extern FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableAbs
  (ScheduleTableType s, TickType Start);
extern FUNC(StatusType, OS_CODE) Os_SendNextScheduleTable
  (ScheduleTableType sc, ScheduleTableType sn);
extern FUNC(StatusType, OS_CODE) Os_SendStopScheduleTable(ScheduleTableType s);
extern FUNC(StatusType, OS_CODE) Os_SendGetScheduleTableStatus
  (ScheduleTableType s, ScheduleTableStatusRefType out);
extern FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableSynchron
  (ScheduleTableType s);
extern FUNC(StatusType, OS_CODE) Os_SendSetScheduleTableAsync(ScheduleTableType s);
extern FUNC(StatusType, OS_CODE) Os_SendSyncScheduleTable
  (ScheduleTableType s, TickType globalTime);

extern FUNC(StatusType, OS_CODE) Os_SendTerminateApplication
  (ApplicationType a, RestartType restart);
extern FUNC(void, OS_CODE) Os_SendGetApplicationState
  (ApplicationType Application, ApplicationStateRefType out);

extern FUNC(void, OS_CODE) Os_SendIocPullCB(
    P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID);

/* Individual message handlers
 * These are responsible for handling inter-core APIs
*/
FUNC(void, OS_CODE) Os_RecvUnknownCall(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvActivateTask(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetTaskState(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvSetEvent(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetEvent(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetAlarm(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvSetRelAlarm(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvSetAbsAlarm(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvCancelAlarm(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetCounterValue(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetElapsedCounterValue(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvStartScheduleTableRel(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvStartScheduleTableAbs(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvNextScheduleTable(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvStopScheduleTable(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetScheduleTableStatus(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvStartScheduleTableSynchron(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvSetScheduleTableAsync(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvSyncScheduleTable(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvTerminateApplication(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetApplicationState(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvShutdownCore(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvGetAlarmBase(Os_MessageType *msg);
FUNC(void, OS_CODE) Os_RecvIocPullCB(Os_MessageType *msg);

#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* #if (OS_MULTICORE == STD_ON) */

#endif /* OS_MULTICOREMESSAGE_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
