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
**  SRC-MODULE: Os_Arch_Timer.c                                               **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of timer specific functionality                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: Yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.3.0     26-Jan-2021    YH.Han        Redmine #27953                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */

#ifndef OS_ARCH_TIMINGPROTECTION_H
#define OS_ARCH_TIMINGPROTECTION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if ((OS_TIMING_PROTECTION == STD_ON) || (OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON))
#define OS_TIMEFRAME_WATCHDOG               0
#define OS_BUDGET_WATCHDOG                  1
#endif

#if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON) || (OS_RES_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON) || (OS_ALLINTLOCK_TP_EB == STD_ON))
#define OS_INT_LOCK_INDEX                   0
#define OS_ALL_INT_LOCK_INDEX               1
#endif

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
#if (OS_TIMING_PROTECTION == STD_ON)
extern FUNC(void, OS_CODE) Os_StartMonitor(TickType LddRequestedTime,
                           Os_WatchdogType LddWdgType, uint32 LulReqArrayIndx);

#if ((OS_RES_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON) ||\
  (OS_ALLINTLOCK_TP_EB == STD_ON))
extern FUNC(void,  OS_CODE) Os_UpdateTpStructure(P2CONST
                        (Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);
#endif

extern FUNC(void, OS_CODE) Os_StopExecutionBudget(P2CONST
                         (Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);

extern FUNC(void, OS_CODE) Os_PauseTimingProtection(void);

extern FUNC(void, OS_CODE) Os_ContinueTimingProtection(P2CONST
                         (Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);

#if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON))
extern FUNC(void, OS_CODE) Os_StartTimeFrame(P2CONST
                         (Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);
#endif

extern FUNC(void, OS_CODE) Os_EnableBudgetTimer(void);
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_ARCH_TIMINGPROTECTION_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
