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
**  SRC-MODULE: Os_Arch_MemPro.h                                              **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related memory protection API          **
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
** 2.4.0     04-Jun-2021    YH.Han        Redmine #29686                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/
#ifndef OS_ARCH_MEMPRO_H_
#define OS_ARCH_MEMPRO_H_

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Regs.h"
#include "Os_Arch_Interrupt.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#if(OS_MEMORY_PROTECTION == STD_ON)
extern FUNC(void,  OS_CODE) Os_HandleMemoryBlock(P2CONST(Tdd_Os_StaticTask,
                                             AUTOMATIC, OS_CONST) LpStaticTask);
extern FUNC(void, OS_CODE) Os_InitializeDedicatedMemBlock(void);
#endif /* End of if (OS_MEMORY_PROTECTION == STD_ON) */
#if (OS_SCALABILITY_CLASS >= OS_SC3)
extern FUNC(AccessType, OS_CODE) Os_CheckMemoryAccessService(ObjectTypeType
        LddTaskID, MemoryStartAddressType LddStartAddr, MemorySizeType LulSize);
#endif
#if((OS_CAT2_ISR_COUNT != OS_ZERO) && (OS_APPLICATION == STD_ON))
extern FUNC(void, OS_CODE) Os_DisableAppInterrupts(ApplicationType Application);
extern FUNC(void, OS_CODE) Os_EnableAppInterrupts(void);
#endif

#endif /* OS_ARCH_MEMPRO_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:2.5:Not a defect:Justify with annotations> Macro is used for memory mapping */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
