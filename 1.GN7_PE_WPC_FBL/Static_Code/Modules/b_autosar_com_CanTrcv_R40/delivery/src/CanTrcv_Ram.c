/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Ram.c                                                 **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Provision of Global RAM Variables                             **
 **                                                                            **
 **  PLATFORM DEPENDANT [yes/no]: yes                                          **
 **                                                                            **
 **  TO BE CHANGED BY USER [yes/no]: no                                        **
 **                                                                            **
 *******************************************************************************/

/*******************************************************************************
 **                      Revision History                                      **
 ********************************************************************************
 ** Revision  Date          By              Description                        **
 ********************************************************************************
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.0     23-Oct-2018   Lim Jong Sun   #12878, #13347, #14410, #14551      **
 ** 2.5.2     27-Apr-2017   Lim Jong Sun   #8371                               **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.1     11-Nov-2016   Lim Jong Sun   #6332, #6661, #6546                 **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805                        **
 ** 2.0.2     10-Mar-2015   Lim Jong Sun   Add Delay Function                  **
 **                                        CanTrcv_DelayStmTicks               **
 **                                        Fixed Bug #2287 about Delay         **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   support general Transceiver         **
 **                                        Feature#1318                        **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "CanTrcv_Ram.h"         /* Module RAM header */

/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR specification version information */
#define CANTRCV_RAM_C_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_RAM_C_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_RAM_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANTRCV_RAM_C_SW_MAJOR_VERSION    2
#define CANTRCV_RAM_C_SW_MINOR_VERSION    10
/*******************************************************************************
 **                      Version Check                                        **
 *******************************************************************************/
#if (CANTRCV_RAM_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_RAM_C_AR_RELEASE_MAJOR_VERSION)
#error "CanTrcv_Ram.c : Mismatch in Specification Major Version"
#endif
#if (CANTRCV_RAM_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_RAM_C_AR_RELEASE_MINOR_VERSION)
#error "CanTrcv_Ram.c : Mismatch in Specification Minor Version"
#endif
#if (CANTRCV_RAM_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_RAM_C_AR_RELEASE_REVISION_VERSION)
#error "CanTrcv_Ram.c : Mismatch in Specification Revision Version"
#endif
#if (CANTRCV_RAM_SW_MAJOR_VERSION != CANTRCV_RAM_C_SW_MAJOR_VERSION)
#error "CanTrcv_Ram.c : Mismatch in Software Major Version"
#endif
#if (CANTRCV_RAM_SW_MINOR_VERSION != CANTRCV_RAM_C_SW_MINOR_VERSION)
#error "CanTrcv_Ram.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/
#if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
#define CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Driver */
VAR (boolean, CANTRCV_VAR) CanTrcv_GblInitStatus;
#define CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif


#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
VAR(ArisuCan_CanConfigType, CANTRCV_VAR) CanTrcv_GddArisuCanSts;
VAR(ArisuCan_CanConfigType, CANTRCV_VAR) CanTrcv_GddArisuChannelUsed;
VAR(ArisuCan_SBCModeType, CANTRCV_VAR) ArisuCan_GddSBCMode;
VAR(ArisuCan_SBCModeType, CANTRCV_VAR) ArisuCan_GddSBCModeSts;
#define CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define CANTRCV_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
VAR(ArisuCan_DataType, CANTRCV_VAR) ArisuCan_GddSpiDestData;
#define CANTRCV_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define CANTRCV_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
VAR(uint8, CANTRCV_VAR) ArisuCan_GucReadFlag;
#define CANTRCV_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#endif /* STD_ON == CANTRCV_ARISUCAN_SUPPORT */

/*******************************************************************************
 **                      Function Definitions                                 **
 *******************************************************************************/

/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
