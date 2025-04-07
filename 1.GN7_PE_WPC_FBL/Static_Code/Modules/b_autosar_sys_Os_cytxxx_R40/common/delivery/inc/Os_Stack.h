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
**  SRC-MODULE: OS_Stack.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Stack.c file containing the declaration    **
**              of Stack functionality related functions.                     **
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
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.1.0     05-Oct-2016    SH.Yoo        Redmine #5866                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1311                       **
** 2.0.2     19-Aug-2013    SH.Yoo        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_STACK_H
#define OS_STACK_H

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
#if (OS_STACK_MONITORING == STD_ON)
extern FUNC(void, OS_CODE) Os_CheckStack(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                        OS_CONST) LpStaticTask);
extern FUNC(void, OS_CODE) Os_CheckStackPattern(
                  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);
#endif /*#if(OS_STACK_MONITORING  == STD_ON)*/

extern FUNC(uint16, OS_CODE) Os_GetStackSize(P2CONST(
                          Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask);
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

#endif /*OS_STACK_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
