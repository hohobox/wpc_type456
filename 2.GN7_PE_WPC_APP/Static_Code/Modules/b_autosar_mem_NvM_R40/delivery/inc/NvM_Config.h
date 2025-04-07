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
**  SRC-MODULE: NvM_Config.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NVM                                                   **
**                                                                            **
**  PURPOSE   : Provides Variable for upper layers                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By               Description                       **
********************************************************************************
** 1.6.2     18-Aug-2022   Yun  YJ     Redmine #37103                         **
** 1.5.1     30-Dec-2020   Yun YJ      Redmine #27374                         **
** 1.3.3     20-Sep-2017   Yun  YJ     Redmine #9669                          **
** 1.3.2     10-Oct-2016   Song CY     Redmine #6215                          **
** 1.2.3     24-Mar-2016   Song CY     Redmine #4276                          **
** 1.1.8     02-Oct-2015   Song CY     For Runtime Err, add library variable  **
** 1.0.8     30-Sep-2013   Song CY     Update for Library.                    **
** 1.0.1     04-Jun-2013   CY Song     XAR~603 : NvM library                  **
**                                     Add global variable                    **
**                                     NvM_GusTotalNumOfBlock                 **
** 1.0.0     25-Jan-2013   CY Song     Initial version                        **
*******************************************************************************/
#ifndef NVM_CONFIG_H_
#define NVM_CONFIG_H_

/* polyspace-begin MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define NVM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern const uint8  NvM_GucRepeatMirrorOperations;

#if(NVM_DEMERROR_REPORT == STD_ON)
extern const uint16  NvM_GusIntegrityFailed;
extern const uint16  NvM_GusLossOfRedundancy;
extern const uint16  NvM_GusQueueOverflow;
extern const uint16  NvM_GusReqFailed;
extern const uint16  NvM_GusVerifyFailed;
extern const uint16  NvM_GusWrongBlockId;
#endif

extern const uint16  NvM_GusTotalNumOfWriteAllBlocks;
extern const uint16  NvM_GusBlockNotConFigWriteAll;
extern const uint16  NvM_GusTotalNumOfBlock;


extern const uint8  NvM_GucDataSetSlectionBits;
extern const uint16 NvM_GusCRCNumOfBytes;

#if(NVM_WRITE_VERIFICATION == STD_ON)
extern const uint16  NvM_GusMaxWriteVerBlkLength;
#endif /* (NVM_WRITE_VERIFICATION == STD_ON) */

#define NVM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/* polyspace-end MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification" */

#endif /* NvM_CONFIG_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
