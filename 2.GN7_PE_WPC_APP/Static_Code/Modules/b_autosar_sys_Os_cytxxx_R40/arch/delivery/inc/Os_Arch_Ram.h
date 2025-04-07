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
**  SRC-MODULE: Os_Arch_Ram.h                                                 **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related global var                     **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]:      Yes                                     **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:   No                                      **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.1     20-Jan-2022    YH.Cho        Redmine #33850                      **
** 2.4.0     20-Aug-2021    YH.Cho        Redmine #31652                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

#ifndef OS_ARCH_RAM_H_
#define OS_ARCH_RAM_H_

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:8.5:Not a defect:Justify with annotations> Redundant declaration for generated code */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define OS_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
extern VAR(uint32, OS_VAR) Os_GulUserSP[OS_CORE_COUNT];
extern VAR(uint32, OS_VAR) Os_GulUserSPBtm[OS_CORE_COUNT];
extern VAR(uint32, OS_VAR) Os_GulUserSPTop[OS_CORE_COUNT];

#if (OS_APPLICATION == STD_ON)
/* polyspace-begin MISRA-C:8.12 [Justified:Low] "External linkage with array size makes error because of compiler optimization" */
extern VAR(uint32, OS_VAR) Os_GulOsAppSP[];
extern VAR(uint32, OS_VAR) Os_GulOsAppSPBtm[];
extern VAR(uint32, OS_VAR) Os_GulOsAppSPTop[];
/* polyspace-end MISRA-C:8.12 */
#endif /* End of #if (OS_APPLICATION == STD_ON) */

#if (OS_MULTICORE == STD_ON)
extern VAR(uint32, OS_VAR) Os_GulSpinlocks[];
#endif /* End of if (OS_MULTICORE == STD_ON) */

extern VAR(uint32, OS_VAR) Os_GulKernelSP[OS_CORE_COUNT];
extern VAR(uint32, OS_VAR) Os_GulKernelSPBase[OS_CORE_COUNT];
extern VAR(uint32, OS_VAR) Os_GulPSP[OS_CORE_COUNT];
extern VAR(uint32, OS_VAR) Os_GulMSP[OS_CORE_COUNT];
#if (OS_FPU_SUPPORT == STD_ON)
extern VAR(Os_Reg32, OS_VAR) Os_GddTaskInitFPSCR;
#endif
#define OS_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, OS_VAR) Os_GucInKernel[OS_CORE_COUNT];
extern VAR(uint8, OS_VAR) Os_GucSchedReq[OS_CORE_COUNT];
extern VAR(uint8, OS_VAR) Os_GucNestingCAT1ISR[OS_CORE_COUNT];
extern VAR(uint8, OS_VAR) Os_GucNestingCAT2ISR[OS_CORE_COUNT];
extern VAR(uint8, OS_VAR) Os_GucCheckCAT2IsrTF[OS_CORE_COUNT];
extern VAR(uint8, OS_VAR) Os_GucKillCAT2ISR[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
/*Os_GusCurrentIsrNumber will be used to clear pending state of this interrupt
 * when entering into thread mode for executing HOOK function  */
extern VAR(uint16, OS_VAR) Os_GusCurrentIsrNumber;
extern VAR(uint16, OS_VAR) Os_GusPreserveBasepri;
extern VAR(uint16, OS_VAR) Os_GusPreserveControl;

#define OS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#if (OS_APPLICATION == STD_ON)
#define OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Os_StackType, OS_VAR) Os_GaaRamUserStack0[OS_USER_STACK_SIZE];
#define OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
#include "MemMap.h"
#if (OS_MULTICORE == STD_ON)
#define OS_START_SEC_STACK_CORE1_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Os_StackType, OS_VAR) Os_GaaRamUserStack1[OS_USER_STACK_SIZE];
#define OS_STOP_SEC_STACK_CORE1_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif /* #if (OS_MULTICORE == STD_ON) */
#else  /* #if (OS_APPLICATION == STD_ON) */
#define OS_START_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Os_StackType, OS_VAR) Os_GaaRamUserStack[OS_USER_STACK_SIZE];
#define OS_STOP_SEC_STACK_CORE0_CLEARED_UNSPECIFIED
#include "MemMap.h"
#endif /* #if (OS_APPLICATION == STD_ON) */

/* Variable to hold STM Clock Frequency in MHz unit */
#define OS_START_SEC_VAR_INIT_32
#include "MemMap.h"
extern VAR(uint32, OS_VAR) Os_GulStmClock;
#define OS_STOP_SEC_VAR_INIT_32
#include "MemMap.h"

#define OS_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Os_TrapInfoType, OS_VAR) Os_GddTrapInfo[OS_CORE_COUNT];
#if (OS_MULTICORE == STD_ON)
extern Os_MessageQueueType Os_GaaInterCoreMsgQ[];
#endif
#define OS_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#endif /* OS_ARCH_RAM_H_ */

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:8.5:Not a defect:Justify with annotations> Redundant declaration for generated code */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
