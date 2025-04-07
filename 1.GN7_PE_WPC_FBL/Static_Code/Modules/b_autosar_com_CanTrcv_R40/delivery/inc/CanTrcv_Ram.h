/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Ram.h                                                 **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Header file of CanTrcv_Ram.c                                  **
 **                                                                            **
 **  PLATFORM DEPENDANT [yes/no]: yes                                          **
 **                                                                            **
 **  TO BE CHANGED BY USER [yes/no]: no                                        **
 **                                                                            **
 *******************************************************************************/

/*******************************************************************************
 **                      Revision History                                      **
 ********************************************************************************
 ** Revision  Date          By             Description                         **
 ********************************************************************************
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878                              **
 ** 2.5.2     27-Apr-2017   Lim Jong Sun   #8371                               **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.1     11-Nov-2016   Lim Jong Sun   #6332, #6661                        **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.2     01-Sep-2016   Lim Jong Sun   #5903                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805, #5333                 **
 ** 2.2.5     10-Nov-2015   Lim Jong Sun   ref#3453 Change Delay logic         **
 ** 2.0.2     10-Mar-2015   Lim Jong Sun   Add Delay Function                  **
 **                                        CanTrcv_DelayStmTicks               **
 **                                        Fixed Bug #2287 about Delay         **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   support general Transceiver         **
 **                                        Feature#1318                        **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

#ifndef CANTRCV_RAM_H
#define CANTRCV_RAM_H

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "ComStack_Types.h"    /* ComStack Types header file*/
#include "CanTrcv_Driver.h"    /* Can Transceiver Driver header file*/
#include "CanTrcv_PCTypes.h"
/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_RAM_AR_RELEASE_MAJOR_VERSION  4
#define CANTRCV_RAM_AR_RELEASE_MINOR_VERSION  0
#define CANTRCV_RAM_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define CANTRCV_RAM_SW_MAJOR_VERSION  2
#define CANTRCV_RAM_SW_MINOR_VERSION  10

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/
#if (STD_ON == CANTRCV_DEV_ERROR_DETECT)
#define CANTRCV_START_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
/* Global variable to store Initialization status of CAN Transceiver Driver */
extern VAR(boolean, CANTRCV_VAR) CanTrcv_GblInitStatus;
#define CANTRCV_STOP_SEC_VAR_CLEARED_BOOLEAN
#include "MemMap.h"
#endif


#define CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(CanTrcv_TrcvModeType, CANTRCV_VAR) CanTrcv_GaaByteArray[CANTRCV_NUM_OF_NETWORKS];
#define CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
/*  polyspace<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation(Array size will fixed in linking time) */
extern VAR(ArisuCan_CanConfigType, CANTRCV_VAR) CanTrcv_GddArisuCanSts;
extern VAR(ArisuCan_CanConfigType, CANTRCV_VAR) CanTrcv_GddArisuChannelUsed;
extern VAR(ArisuCan_SBCModeType, CANTRCV_VAR) ArisuCan_GddSBCModeSts;
extern VAR(ArisuCan_SBCModeType, CANTRCV_VAR) ArisuCan_GddSBCMode;
#define CANTRCV_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"

#define CANTRCV_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
extern VAR(ArisuCan_DataType, CANTRCV_VAR) ArisuCan_GddSpiDestData;
#define CANTRCV_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

#define CANTRCV_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, CANTRCV_VAR) ArisuCan_GucReadFlag;
#define CANTRCV_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"

#define CANTRCV_START_SEC_CONST_8
#include "MemMap.h"
extern CONST(uint8, CANTRCV_CONST) CanTrcv_GucArisuCanPwmAuto;
#define CANTRCV_STOP_SEC_CONST_8
#include "MemMap.h"
#endif/* STD_ON == CANTRCV_ARISUCAN_SUPPORT */

#if (STD_ON == CANTRCV_SPI_SUPPORT)
#define CANTRCV_START_SEC_CONST_16
#include "MemMap.h"
extern CONST(Spi_NumberOfDataType, CANTRCV_CONST) CanTrcv_GddSpiType;
#define CANTRCV_STOP_SEC_CONST_16
#include "MemMap.h"

#endif/* STD_ON == CANTRCV_ARISUCAN_SUPPORT */
/*******************************************************************************
 **                      Function Prototypes                                  **
 *******************************************************************************/

#endif /* CANTRCV_RAM_H */
/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
