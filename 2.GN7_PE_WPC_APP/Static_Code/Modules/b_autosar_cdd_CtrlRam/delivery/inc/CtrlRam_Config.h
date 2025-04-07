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
**  SRC-MODULE: CtrlRam_Config.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CtrlRam Module                                        **
**                                                                            **
**  PURPOSE   : Watchdog Manager API Functionality                            **
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
** 1.0.8       04-Aug-2022  YH.Han        Redmine #36978                      **
** 1.0.2       13-Oct-2016  Hyungho Lee   Redmine #6153                       **
** 1.0.0       25-Jan-2013                Initial version                     **
*******************************************************************************/
#ifndef CTRLRAM_CONFIG_H_
#define CTRLRAM_CONFIG_H_
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CtrlRam_Cfg.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#define RECOVERY_OK   ((uint8)0x00)
#define RECOVERY_FAIL ((uint8)0x01)

#define CTRLRAM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if(CTRLRAM_DEMERROR_REPORT == STD_ON)
extern const uint16 CtrlRam_GusWrongState;
#endif

#if (CTRLRAM_RECOVERY == STD_ON)
extern const uint8 cub_CtrlRAM_DataBuffer_MaxSize;
#endif

#define CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif /* NvM_CONFIG_H_ */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
