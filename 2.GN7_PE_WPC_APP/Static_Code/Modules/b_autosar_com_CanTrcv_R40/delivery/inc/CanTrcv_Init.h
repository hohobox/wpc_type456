/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Init.h                                                **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Header file of CanTrcv_Init.c                                 **
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
 ** 2.10.0    11-Oct-2023   Song Yu Bin    #42559                              **
 ** 2.9.5     24-Aug-2022   Kim Min Uk     #37209                              **
 ** 2.9.4     08-Aug-2022   Kim Min Uk     #36455, #36293, #36981              **
 ** 2.7.0     10-Feb-2021   Lim Jong Sun   #22922                              **
 ** 2.6.2     20-Nov-2020   Lim Jong Sun   #26689                              **
 ** 2.6.1     06-Feb-2020   Lim Jong Sun   #15680                              **
 ** 2.6.0     23-Oct-2018   Lim Jong Sun   #12878, #13347, #14410, #14551      **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805                        **
 ** 2.2.5     26-Nov-2015   Lim Jong Sun   #2786                               **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   #1318                               **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

#ifndef CANTRCV_INIT_H
#define CANTRCV_INIT_H

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "CanTrcv_Driver.h"    /* CAN Transceiver Driver header file */
#include "CanTrcv_PCTypes.h"   /* CAN Transceiver Driver Types header file */
#include "CanTrcv_Ram.h"       /* CAN Transceiver RAM header file */

/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_INIT_C_AR_RELEASE_MAJOR_VERSION    4
#define CANTRCV_INIT_C_AR_RELEASE_MINOR_VERSION    0
#define CANTRCV_INIT_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define CANTRCV_INIT_C_SW_MAJOR_VERSION  2
#define CANTRCV_INIT_C_SW_MINOR_VERSION  10

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/
/* Partial Networking Flag Result */
typedef enum {
  CANTRCV_NOERR = 0,
  CANTRCV_PORERR,
  CANTRCV_SYSERR,
  CANTRCV_SYSPORERR
} CanTrcv_PnErrType;
#if(((CANTRCV_TJA1145_PRESENT == STD_ON)||(CANTRCV_TCAN1145_PRESENT == STD_ON)) && (STD_ON == CANTRCV_SPI_SUPPORT))
/* Undervoltage Flag Result */
typedef enum {
  CANTRCV_NOUNDERVOL = 0,
  CANTRCV_UNDERVOL,
} CanTrcv_UndervolType;
#endif
/*******************************************************************************
 **                      Function Prototypes                                  **
 *******************************************************************************/
#if((STD_ON == CANTRCV_SPI_SUPPORT) && (STD_ON == CANTRCV_PN_SUPPORTED))
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanTrcv_PnErrType, CANTRCV_CODE) CanTrcv_CheckPnFlags(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif


#if(((CANTRCV_TJA1145_PRESENT == STD_ON)||(CANTRCV_TCAN1145_PRESENT == STD_ON) )&& (STD_ON == CANTRCV_SPI_SUPPORT))
#define CANTRCV_START_SEC_CODE
#include "MemMap.h"
extern FUNC(CanTrcv_UndervolType, CANTRCV_CODE) CanTrcv_CheckUndervoltage(uint8 LucTransceiver);
#define CANTRCV_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /* CANTRCV_INIT_H */
/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
