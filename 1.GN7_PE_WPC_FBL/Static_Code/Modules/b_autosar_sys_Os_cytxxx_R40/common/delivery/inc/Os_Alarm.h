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
**  SRC-MODULE: Os_Alarm.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Alarm.c file containing the declaration of **
**              Alarm related functions.                                      **
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
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #494                        **
** 2.0.4     23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_ALARM_H
#define OS_ALARM_H

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
#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
extern FUNC(void, OS_CODE) Os_InsertAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC,
                                                               OS_VAR) LpAlarm);

extern FUNC(void, OS_CODE) Os_RemoveAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC,
                                                               OS_VAR) LpAlarm);

extern FUNC(void, OS_CODE) Os_RemoveAlarmSet(P2VAR(Tdd_Os_Counter, AUTOMATIC,
                                                             OS_VAR) LpCounter);

extern FUNC(StatusType, OS_CODE) Os_ProcessAlarm(P2CONST(Tdd_Os_StaticCounter,
                                          AUTOMATIC, OS_CONST) LpStaticCounter);

#if (OS_TASK == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_AlarmActivateTask(P2CONST
                         (Tdd_Os_ActivateTask, AUTOMATIC, OS_CONST) LpAction);
#endif /* (OS_TASK == STD_ON) */

#if (OS_EVENT == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_AlarmSetEvent(P2CONST(Tdd_Os_AlarmEvent,
                                                  AUTOMATIC,OS_CONST) LpAction);
#endif /* #if(OS_EVENT == STD_ON) */
#endif /* #if((OS_ALARM == STD_ON)||(OS_SCHEDTABLE == STD_ON)) */

#if (OS_CALLBACK_COUNT > OS_PRE_ZERO)
extern FUNC(StatusType,OS_CODE) Os_AlarmCallback(P2CONST(Tdd_Os_AlarmCallback,
                                                 AUTOMATIC, OS_CONST) LpAction);
#endif /* (OS_CALLBACK_COUNT > OS_PRE_ZERO) */

#if (OS_INCCOUNTER_COUNT > OS_PRE_ZERO)
extern FUNC(StatusType,  OS_CODE) Os_AlarmIncrementCounter(P2CONST
                         (Tdd_Os_IncrementCounter, AUTOMATIC, OS_CONST) LpAction);
#endif /* (OS_INCCOUNTER_COUNT > OS_PRE_ZERO) */

#if (OS_ALARM == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_DoGetAlarm(AlarmType AlarmID,
                                       TickRefType Tick, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoSetRelAlarm(AlarmType AlarmID,
                     TickType Increment, TickType Cycle, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoSetAbsAlarm(AlarmType AlarmID,
                         TickType Start, TickType Cycle, boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoCancelAlarm(AlarmType AlarmID,
                                                         boolean LblRemoteCall);
extern FUNC(StatusType, OS_CODE) Os_DoGetAlarmBase(AlarmType AlarmID,
                                  AlarmBaseRefType Info, boolean LblRemoteCall);
#endif /* End of if (OS_ALARM == STD_ON) */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_ALARM_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
