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
**  SRC-MODULE: Os_Gen.h                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for generated Os files containing the declaration **
**              of Task, Counter, Alarm, ScheduleTable related functions.     **
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
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #494, #1189                 **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     12-Jul-2013    ManJe Woo     Creation of Os_Gen.h module         **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:8.5 [Not a defect:Medium] "To avoid cross reference, external function needed." */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_GEN_H
#define OS_GEN_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "Os_InternalTypes.h"
#include "Os_PortTypes.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, OS_CODE) Os_Sleep(void);

#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
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

#if (OS_SCHEDTABLE == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_ProcessSchedTable(P2CONST
                         (Tdd_Os_SchedTable, AUTOMATIC, OS_CONST) LpAction);
#endif /* (OS_SCHEDTABLE == STD_ON) */

#if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
extern FUNC(void, OS_CODE) Os_UpdateCountInCounterISR(
             P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter,
                  P2CONST(Tdd_Os_HardwareCounter, AUTOMATIC, OS_CONST) LpHwCounter);

extern FUNC(void, OS_CODE) Os_ResetTimer(
        CONSTP2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter,
             CONSTP2VAR(Tdd_Os_HardwareCounter, AUTOMATIC, OS_VAR) LpHwCounter);
#endif

#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_GEN_H */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:8.5 */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
