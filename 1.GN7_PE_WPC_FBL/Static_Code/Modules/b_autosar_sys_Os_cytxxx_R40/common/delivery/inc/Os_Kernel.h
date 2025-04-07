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
**  SRC-MODULE: Os_Kernel.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Kernel.c file containing the declaration   **
**              of Kernel functionality related functions.                    **
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
** 2.6.7     04-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee,MJ.Woo Redmine #3963                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
**           26-Mar-2015    MJ.Woo        Redmine #2381                       **
** 2.0.4     23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     11-Sep-2013    MJ.Woo        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_KERNEL_H
#define OS_KERNEL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Init.h"
#include "Os_Arch_Context.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Defination                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
#if (OS_TASK == STD_ON)
extern FUNC(void, OS_CODE) Os_ScheduleFromChain(void);

extern FUNC(void, OS_CODE) Os_InsertTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                       OS_CONST) LpStaticTask);
extern FUNC(void, OS_CODE) Os_InsertPreemptedTask(P2CONST(Tdd_Os_StaticTask,
                                            AUTOMATIC, OS_CONST) LpStaticTask);
#endif /*OS_TASK == STD_ON*/

extern FUNC(void, OS_CODE) Os_Sleep(void);

extern FUNC(void, OS_CODE) Os_RunTask(void);

extern FUNC(void, OS_CODE) Os_ScheduleService(void);

#if ((OS_PROTECTION_HOOK == STD_ON) || (OS_APPLICATION == STD_ON))
extern FUNC(void, OS_CODE) Os_KillTask(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                        OS_CONST) LpStaticTask);

extern FUNC(void, OS_CODE) Os_KillIsr(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                        OS_CONST) LpStaticTask);
#endif

#if (OS_PROTECTION_HOOK == STD_ON)
extern FUNC(StatusType, OS_CODE) Os_ProtectionHookService(
                                                         StatusType Fatalerror);

extern FUNC(StatusType, OS_CODE) Os_KillTaskOrISR(void);
#endif

#if ((OS_PROTECTION_HOOK == STD_ON) || (OS_APPLICATION == STD_ON))
extern FUNC(void, OS_CODE) Os_KillUsedCsa(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                        OS_CONST) LpStaticTask);
#endif /* End of if (OS_PROTECTION_HOOk == STD_ON) */
/* polyspace<MISRA-C:8.8:Not a defect:Justify with annotations> To avoid cross reference, external function needed.  */
extern FUNC(void, OS_CODE) Os_InitTimer(void);

/* polyspace-begin CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
#if (OS_MAX_ACTIVATION_COUNT != OS_ONE)
#define OS_INSERT_TASK_IN_QUEUE()\
  taskLinkIndex = Os_GaaLinkIndex[LpStaticTask->ddTaskId];\
  Os_GaaLinkIndex[LpStaticTask->ddTaskId]++;\
  if (Os_GaaLinkIndex[LpStaticTask->ddTaskId] ==\
      (LpStaticTask->ucMaxActivateCount))\
  {\
    Os_GaaLinkIndex[LpStaticTask->ddTaskId] = OS_ZERO;\
  }\
  LpLinkTask = LpStaticTask->pLinkTask + taskLinkIndex;\
  LpLinkTask->ulPriority = LpStaticTask->ulBasePriority;
#else /* End of if (OS_MAX_ACTIVATION_COUNT != OS_ONE) */
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
#define OS_INSERT_TASK_IN_QUEUE()\
  do{\
    LpLinkTask = LpStaticTask->pLinkTask;\
    LpLinkTask->ulPriority = LpStaticTask->ulBasePriority;\
  } while(0)

#endif /* End of if (OS_MAX_ACTIVATION_COUNT != OS_ONE) */
/* polyspace-end CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

#endif /* OS_KERNEL_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
