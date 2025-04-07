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
**  SRC-MODULE: CtrlRam_Ram.c                                                 **
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
** Revision    Date           By          Description                         **
********************************************************************************
** 1.0.8       04-Aug-2022  YH.Han        Redmine #36978                      **
** 1.0.2       13-Oct-2016  Hyungho Lee   Redmine #6153                       **
** 1.0.0       25-Jan-2013                Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "CtrlRam_Cfg.h"
#include "CtrlRam_Ram.h"     /* Global variables header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (CTRLRAM_RECOVERY == STD_ON)
#ifndef CTRLRAM_STRUCT_BUFFER_SIZE
#define CTRLRAM_STRUCT_BUFFER_SIZE CTRLRAM_ONE
#endif
#endif

#define CTRLRAM_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
uint8 rub_CtrlRAM_Status;
#define CTRLRAM_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

/* non initialized WORDS */
#define CTRLRAM_START_SEC_VAR_NOINIT_16
#include "MemMap.h"
#if ((CTRLRAM_RECOVERY == TRUE) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
uint16 ruw_CtrlRAM_ChkOld;
#endif
#define CTRLRAM_STOP_SEC_VAR_NOINIT_16
#include "MemMap.h"

/* non initialized LONGS and STRUCTURES */
#define CTRLRAM_START_SEC_VAR_NOINIT_32
#include "MemMap.h"
#if ((CTRLRAM_RECOVERY == STD_ON) && (CTRLRAM_VERIFY_AT_INIT == STD_ON))
uint8 * rpub_CtrlRAM_Address;
#endif

#if (CTRLRAM_RECOVERY == STD_ON)
/* Must be aligned long due to some cast in long of the buffer */
uint8 rub_CtrlRAM_DataBuffer[CTRLRAM_STRUCT_BUFFER_SIZE];
#endif
#define CTRLRAM_STOP_SEC_VAR_NOINIT_32
#include "MemMap.h"

/*-----------------------------*/
/* controlled RAM              */
/*-----------------------------*/
/* controlled RAM Key - placed in the specific ram_ctl_begin section */
#define CTRLRAM_START_SEC_VAR_NOINIT_BEGIN
#include "MemMap.h"
uint16 ruw_CtrlRAM_Key;
#define CTRLRAM_STOP_SEC_VAR_NOINIT_BEGIN
#include "MemMap.h"

/* controlled RAM Checksum - placed in the specific ram_ctl_end section */
#define CTRLRAM_START_SEC_VAR_NOINIT_END
#include "MemMap.h"
uint16 ruw_CtrlRAM_Checksum;
#define CTRLRAM_STOP_SEC_VAR_NOINIT_END
#include "MemMap.h"


/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
