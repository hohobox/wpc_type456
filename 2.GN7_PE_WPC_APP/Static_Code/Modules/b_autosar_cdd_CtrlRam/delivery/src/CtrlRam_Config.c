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
**  SRC-MODULE: CtrlRam_Config.c                                              **
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
** 1.0.0       25-Jan-2013                Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CtrlRam_Config.h"
#if(CTRLRAM_DEMERROR_REPORT == STD_ON)
#include "CtrlRam_Dem_Cfg.h"                            /* Dem header file */
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define CTRLRAM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (CTRLRAM_RECOVERY == STD_ON)
const uint8 cub_CtrlRAM_DataBuffer_MaxSize            = CTRLRAM_STRUCT_BUFFER_SIZE;
#else
const uint8 cub_CtrlRAM_DataBuffer_MaxSize            = CTRLRAM_ONE;
#endif

#if(CTRLRAM_DEMERROR_REPORT == STD_ON)
const uint16 CtrlRam_GusWrongState                    = CTRLRAM_E_WRONG_STATE;
#endif

#define CTRLRAM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
