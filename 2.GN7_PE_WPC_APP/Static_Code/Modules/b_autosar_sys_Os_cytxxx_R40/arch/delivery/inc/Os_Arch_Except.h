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
**  SRC-MODULE: Os_Arch_Except.h                                              **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related (OS) Exception API             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]:     Yes                                      **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #20861, #22057              **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */

#ifndef OS_ARCH_EXCEPT_H_
#define OS_ARCH_EXCEPT_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

extern FUNC(void, OS_CODE) Reset_Handler(void);
#if (OS_MULTICORE == STD_ON)
extern FUNC(void, OS_CODE) Reset_Handler_Core1(void);
#endif /* End of if (OS_MULTICORE == STD_ON) */
extern FUNC(void, OS_CODE) Os_NMIHandler(void);
extern FUNC(void, OS_CODE) Os_FaultHandler(void);
extern FUNC(void, OS_CODE) Os_SVCallHandler(void);
extern FUNC(void, OS_CODE) Os_ISRHandler(void);
extern FUNC(void, OS_CODE) Os_UnusedExceptionHandler(void);
extern uint32 Os_CallFuncKernelStack(uint32 param0, uint32 param1,
                                                uint32 param2, uint32 function);

/* polyspace<MISRA-C3:8.6:Not a defect:Justify with annotations> Defined in .ld file */
extern uint32 OS_MAIN_TOS;    /* Top of Main Stack(Kernel Stack) */
#if (OS_MULTICORE == STD_ON)
extern uint32 OS_CORE1_TOS;   /* Top of Core1 Stack(Kernel Stack) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_ARCH_TIMER_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:5.4:Not a defect:Justify with annotations> Macro is used for memory mapping */
/* polyspace:end<MISRA-C3:20.1:Not a defect:Justify with annotations> Macro is used for memory mapping */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/


