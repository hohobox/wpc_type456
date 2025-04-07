/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**  SRC-MODULE: NvM_EraseInvalidate.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Provision of NVRAM Manager Erase and Invalidate functions.    **
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
** 1.1.6       03-Mar-2015  Song CY       As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.1.4       02-Dec-2014  Song CY       RedMine 1719, Update for PolySpace  **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

#ifndef NVM_ERASEINVALIDATE_H
#define NVM_ERASEINVALIDATE_H

/* polyspace-begin MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                       Function Prototypes                                  **
*******************************************************************************/
#if (NVM_API_CONFIG_CLASS  ==  NVM_API_CONFIG_CLASS_3)
#define NVM_START_SEC_CODE
#include "MemMap.h"
/* NvM_ProcessEraseInvalidBlk Prototype Declarations*/
extern FUNC(void, NVM_CODE) NvM_ProcessEraseInvalidBlk(void);

#define NVM_STOP_SEC_CODE
#include "MemMap.h"

#endif  /* (NVM_API_CONFIG_CLASS  ==  NVM_API_CONFIG_CLASS_3) */

/* polyspace-end MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" */

#endif /* NVM_ERASEINVALIDATE_H */

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
