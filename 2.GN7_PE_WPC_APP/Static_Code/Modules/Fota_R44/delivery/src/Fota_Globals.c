/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
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
** Revision  Date          By           Description                           **
** 1.0.1.0   11-Dec-2023   VuPH6        #CP44-3526                            **
** 1.0.0.0   30-Mar-2022   jys          Initial version                       **
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
uint8 Fota_PreviousMetadataBlkId;
uint8 Fota_ProgrammingMetadataBlkId;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
uint8 Fota_Gu8_MetadataPSKidx;
uint8 Fota_ProgrammingFwBlockId = 0xFF;
uint8 Fota_PreviousFwBlockId = 0;

uint8 Fota_BootMode = FOTA_MODE;
/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
uint8 Fota_Ret = 0; /* For Fota_DetReportErr : This variable to store when retVal is not equal 1 and 0 */

uint8 Fota_NumOfSwUnit = FOTA_NUM_OF_SWUNIT;

/* polyspace +1 DEFECT:DATA_RACE [Not a defect:Low] "Fota logic is syncronized with diagnostic services. There is no unpredictable interference." */
Fota_StateType Fota_State;
Fota_InitStatusType Fota_InitStatus;

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
uint32 Fota_PflsWriteAlignmentSize = 0;

uint8 Fota_PflsEraseAlignmentBuffer[4] = {0, 0, 0, 0};
uint32 Fota_PflsEraseAlignmentValue = 0;
uint32 Fota_PflsEraseAlignmentSize = 0;

#if (FOTA_MODE==FOTA_APP_MODE)
/* polyspace-begin CERT-C:INT36-C, MISRA-C3:11.4 [Justified:Low] "The integer value represents the register address. It should be casted to an address so that
* the register value can be read via the address" */
const uint32 rub_PartChkAreaFlag = 0x55;
uint32 rub_PartChkAreaFlagAddr = (uint32)(&rub_PartChkAreaFlag);
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
#define Fota_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "Fota_MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
