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
**  SRC-MODULE: NvM_Cbk.h                                                     **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of Macros and API Prototype Declarations            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.1.7       09-Jul-2015  Song CY       Justify MISRA-Rule Violation        **
** 1.1.6       03-Mar-2015  Song CY       As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_CBK_H
#define NVM_CBK_H

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
polyspace-begin MISRA-C3:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (Mcal FEE violate spec - Not include NvM_Chk.h but declare extern)
polyspace-begin MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification"
polyspace-begin MISRA-C3:8.5 [Justified:Low] "Implemented according to AUTOSAR specification"
*/

/*******************************************************************************
**                   Include Section                                         ***
*******************************************************************************/
#include "NvM_Cfg.h"


/*******************************************************************************
**                   Global Data                                              **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if(NVM_POLLING_MODE == STD_OFF)

#define NVM_START_SEC_CODE
#include "MemMap.h"

/* For MemIf job end notification without error */
extern FUNC(void, NVM_CODE) NvM_JobEndNotification(void);

/* For MemIf job end notification with error */
extern FUNC(void, NVM_CODE) NvM_JobErrorNotification(void);

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
polyspace-end MISRA-C3:8.5 [Justified:Low] "Implemented according to AUTOSAR specification"
polyspace-end MISRA-C3:8.8:Not a defect:Justify with annotations> No Impact of this rule violation (Mcal FEE violate spec - Not include NvM_Chk.h but declare extern)
polyspace-end MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" 
*/


#endif /* NVM_CBK_H */

/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
