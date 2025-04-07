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
**  SRC-MODULE: Os_SchedTable.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_SchedTable.c file containing the           **
**              declaration of Schedule Table functionality related functions **
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
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     31-Oct-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_SCHEDTABLE_H
#define OS_SCHEDTABLE_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"
#if (OS_SCHEDTABLE == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_ProcessSchedTable(P2CONST
                          (Tdd_Os_SchedTable, AUTOMATIC, OS_CONST) pAction);
extern FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableRel(ScheduleTableType
                       ScheduleTableID, TickType Offset, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableAbs(ScheduleTableType
                        ScheduleTableID, TickType Start, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoStopScheduleTable(ScheduleTableType
                                        ScheduleTableID, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoNextScheduleTable(
                                      ScheduleTableType ScheduleTableID_From,
                                      ScheduleTableType ScheduleTableID_To,
                                      boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoGetScheduleTableStatus(
                                      ScheduleTableType ScheduleTableID,
                                      ScheduleTableStatusRefType ScheduleStatus,
                                      boolean LblRemoteCall);
#endif /*(OS_SCHEDTABLE == STD_ON)*/

#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableSynchron(
                                              ScheduleTableType ScheduleTableID,
                                              boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoSyncScheduleTable(ScheduleTableType
                                                        ScheduleTableID,
                                                        TickType Value,
                                                        boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoSetScheduleTableAsync(
                                              ScheduleTableType ScheduleTableID,
                                              boolean LblRemoteCall);
#endif /* #if(OS_SCHED_EXPLICIT_SYNC == STD_ON) */

#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
extern FUNC(StatusType, OS_CODE)Os_SyncScheduleTableError
                             (ScheduleTableType ScheduleTableID,TickType Value);
#endif /* #if(OS_SCHED_EXPLICIT_SYNC == STD_ON) */

#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
extern FUNC(void, OS_CODE)Os_SyncSchedRunning(ScheduleTableType ScheduleTableID,
                                             TickType Value,TickType LddOffSet);
#endif /* #if(OS_SCHED_EXPLICIT_SYNC == STD_ON) */



#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif /* OS_SCHEDTABLE_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
