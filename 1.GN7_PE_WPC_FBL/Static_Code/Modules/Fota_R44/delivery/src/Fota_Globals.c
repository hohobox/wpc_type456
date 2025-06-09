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
**  SRC-MODULE: FOTA_Globals.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR FOTA                                                  **
**                                                                            **
**  PURPOSE   : Provides all the Global Variables of a firmware over the air  **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.0.1.0   14-Mar-2025   YWJung         #CP44-15409, #CP44-14095            **
**                                        #CP44-16648, #CP44-16830            **
** 2.0.0.0   31-Dec-2024   ThanhTVP2      #CP44-12051                         **
** 1.0.1.0   11-Dec-2023   VuPH6          #CP44-3526                          **
** 1.0.0.0   30-Mar-2022   jys            Initial version                     **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Fota_Globals.h"

/*******************************************************************************
**                     Global Data                                            **
*******************************************************************************/
#define Fota_START_SEC_VAR_CLEARED_BOOLEAN
#include "Fota_MemMap.h"

#define Fota_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_CLEARED_8
#include "Fota_MemMap.h"
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
boolean Fota_SecureFlashDecryptOn;
uint8 Fota_MemoryInstance;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
uint8 Fota_ProgrammingMemoryArea;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "CP44-15732 comment_1. This function do not re-enter within processing, so datarace can be ignored." */
uint8 Fota_ProgrammingSWUnitId;
uint8 Fota_ProgrammingMetadataBlkId;
#if (FOTA_STD_ON == FOTA_SF20_ENABLE)
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
uint8 Fota_Gu8_MetadataPSKidx;
#endif
uint8 Fota_ProgrammingFwBlockId = 0xFF;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
uint8 Fota_Ret = 0; /* For Fota_DetReportErr : This variable to store when retVal is not equal 1 and 0 */
uint8 Fota_NumOfSwUnit = FOTA_NUM_OF_SWUNIT;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
Fota_StateType Fota_State;
Fota_InitStatusType Fota_InitStatus;
Fota_CmdStatType Fota_CurCmdStat;

boolean Fota_ResetAfterSwapReq;
boolean Fota_NotDefinedSwUnit;
#define Fota_STOP_SEC_VAR_CLEARED_8
#include "Fota_MemMap.h"

#define Fota_START_SEC_CONST_8
#include "Fota_MemMap.h"

#define Fota_STOP_SEC_CONST_8
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_CLEARED_16
#include "Fota_MemMap.h"

#define Fota_STOP_SEC_VAR_CLEARED_16
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_CLEARED_32
#include "Fota_MemMap.h"

uint32 Fota_StartupCommandAddress = FBL_STARTUP_COMMAND_ADDRESS;

uint8 Fota_PflsWriteAlignmentBuffer[4] = {0, 0, 0, 0};
uint32 Fota_PflsWriteAlignmentValue = 0;
uint32 Fota_PflsEraseAlignmentValue = 0;


#if (FOTA_MODE==FOTA_APP_MODE)
/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
* the register value can be read via the address" */

uint32 rub_PartChkAreaFlagAddr;
/* polyspace-end CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
* the register value can be read via the address" */
#endif
#define Fota_STOP_SEC_VAR_CLEARED_32
#include "Fota_MemMap.h"

#define Fota_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"
#if ((FOTA_SOFTWARE_VERSION_CHECK == FOTA_STD_ON) &&\
  (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_SINGLE_TYPE))
Fota_VerStateType Fota_VersionStatus;
#endif
#if (FOTA_MCU_MEMORY_ACCESS_TYPE == FOTA_MMU_TYPE)
Fota_SyncStatType Fota_AreaSyncState = FOTA_SYNC_IDLE;
#endif

#define Fota_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
