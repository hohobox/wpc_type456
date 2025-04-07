/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_ModeCtrl.h                                            **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Header file of CanTrcv_ModeCtrl.c                             **
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
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
 ** 2.6.1     06-Feb-2020   Lim Jong Sun   #20370                              **
 ** 2.6.0     25-Jun-2018   Lim Jong Sun   #12878                              **
 ** 2.5.8     27-Feb-2019   Lim Jong Sun   #16239                              **
 ** 2.5.2     27-Arp-2017   Lim Jong Sun   #8357, #8358                        **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611                               **
 ** 2.2.5     10-Nov-2015   Lim Jong Sun   #3453                               **
 **                                        #3479                               **
 ** 2.0.2     10-Mar-2015   Lim Jong Sun   #2287                               **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

#ifndef CANTRCV_MODECTRL_H
#define CANTRCV_MODECTRL_H

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "CanTrcv_PCTypes.h"    /* CAN Transceiver Driver Types header file */
#include "CanTrcv_Driver.h"     /* CAN Transceiver Driver  header file */
#include "CanTrcv_Ram.h"        /* CAN Transceiver Driver RAM header file */
#include "SchM_CanTrcv.h"       /* SchM CanTrcv header file */
#include "CanTrcv_Init.h"       /* CAN Transceiver TJA1145 Check Flags */

/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_MODECTRL_AR_RELEASE_MAJOR_VERSION     4
#define CANTRCV_MODECTRL_AR_RELEASE_MINOR_VERSION     0
#define CANTRCV_MODECTRL_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define CANTRCV_MODECTRL_SW_MAJOR_VERSION  2
#define CANTRCV_MODECTRL_SW_MINOR_VERSION  10

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/

/*******************************************************************************
 **                      Function Prototypes                                  **
 *******************************************************************************/
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_NormalMode(
    uint8 LucTransceiver);
extern FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_StandbyMode(
    uint8 LucTransceiver);
extern FUNC(CanTrcv_TrcvModeType, CANTRCV_CODE) CanTrcv_SleepMode(
    uint8 LucTransceiver);
#if(STD_ON == CANTRCV_SPI_SUPPORT)
extern FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_SendSPI(uint8 LucTransceiver,
P2CONST(uint16, AUTOMATIC, CANTRCV_CONST) SpiSrcData,
P2VAR(uint16, AUTOMATIC, CANTRCV_VAR) SpiDestData);
#endif
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"

#if (STD_ON == CANTRCV_ARISUCAN_SUPPORT)
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, CANTRCV_CODE) ArisuCan_GetMode
  (ArisuCan_SBCModeType* pMode);
extern FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_SetMode
  (ArisuCan_SBCModeType Mode);
extern FUNC(Std_ReturnType, CANTRCV_CODE) CanTrcv_ArisuCan_GetMode
   (ArisuCan_SBCModeType* pMode);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif /* STD_ON == CANTRCV_ARISUCAN_SUPPORT */

#endif /* CANTRCV_MODECTRL_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
