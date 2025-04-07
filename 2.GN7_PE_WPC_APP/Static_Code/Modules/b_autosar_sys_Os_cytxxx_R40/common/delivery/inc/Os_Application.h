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
**  SRC-MODULE: Os_Application.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Application.c file containing the          **
**              declaration of Application functionality related functions.   **
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
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     24-Oct-2013    DG.Lee,MJ.Woo CR: xar~179, TASK: xar~736          **
** 2.0.2     13-Aug-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.1     13-Aug-2013    DG.Lee        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_APPLICATION_H
#define OS_APPLICATION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_MemPro.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
#define APPLICATION_HAS_CALLTRUSTEDFUNC (ApplicationStateType)(0x40)
#define IS_FREE_FROM_CALLTRUSTEDFUNC(AppID) \
  ( (Os_GaaApplication[AppID].ddState & APPLICATION_HAS_CALLTRUSTEDFUNC)? \
                                                           (OS_FALSE):(OS_TRUE))
#endif
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
#if (OS_APPLICATION == STD_ON)
extern FUNC(void, OS_CODE) Os_DoGetApplicationState(ApplicationType Application,
                                                 ApplicationStateRefType Value);
extern FUNC(StatusType, OS_CODE) Os_DoTerminateApplication(
                        ApplicationType Application, RestartType RestartOption);
#endif
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

#endif /* OS_APPLICATION_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
