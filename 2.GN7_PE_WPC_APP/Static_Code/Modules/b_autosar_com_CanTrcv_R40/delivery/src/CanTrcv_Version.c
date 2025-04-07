/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
 **  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
 **  Confidential Proprietary Information. Distribution Limited.               **
 **  Do Not Copy Without Prior Permission                                      **
 **                                                                            **
 **  SRC-MODULE: CanTrcv_Version.c                                             **
 **                                                                            **
 **  TARGET    : General CAN Transceiver                                       **
 **                                                                            **
 **  PRODUCT   : AUTOSAR CAN Transceiver Driver Module                         **
 **                                                                            **
 **  PURPOSE   : Provision of Version information                              **
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
 ** 2.6.1     06-Feb-2020   Lim Jong Sun   #19927                              **
 ** 2.6.0     23-Oct-2018   Lim Jong Sun   #12878, #13347, #14410, #14551      **
 ** 2.5.8     27-Feb-2019   Lim Jong Sun   #15511                              **
 ** 2.5.0     27-Dec-2016   Lim Jong Sun   #6921                               **
 ** 2.4.0     21-Oct-2016   Lim Jong Sun   #6309                               **
 ** 2.3.0     15-May-2016   Lim Jong Sun   #4611, #4805                        **
 ** 2.0.0     03-Sep-2014   Lim Jong Sun   support general Transceiver         **
 **                                        Feature#1318                        **
 ** 1.0.0     21-Mar-2013   Lim Jong Sun   Initial Version                     **
 *******************************************************************************/

/*******************************************************************************
 **                      Include Section                                      **
 *******************************************************************************/
#include "CanTrcv_Version.h"     /* Module version check header file */
#include "CanIf.h"               /* CAN Interface module header file */
#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
#include "Det.h"                 /* DET module header file */
#endif

/*******************************************************************************
 **                      Version Information                                  **
 *******************************************************************************/
/* AUTOSAR Specification Version Information */
#define CANTRCV_VERSION_C_AR_RELEASE_MAJOR_VERSION  4
#define CANTRCV_VERSION_C_AR_RELEASE_MINOR_VERSION  0
#define CANTRCV_VERSION_C_AR_RELEASE_REVISION_VERSION 3

/* Software Version Information */
#define CANTRCV_VERSION_C_SW_MAJOR_VERSION  2
#define CANTRCV_VERSION_C_SW_MINOR_VERSION  10
/*******************************************************************************
 **                      Version Check                                        **
 *******************************************************************************/

#if (CANTRCV_VERSION_AR_RELEASE_MAJOR_VERSION != \
  CANTRCV_VERSION_C_AR_RELEASE_MAJOR_VERSION)
#error "CanTrcv_Version.c : Mismatch in CanTrcv Specification Major Version"
#endif

#if (CANTRCV_VERSION_AR_RELEASE_MINOR_VERSION != \
  CANTRCV_VERSION_C_AR_RELEASE_MINOR_VERSION)
#error "CanTrcv_Version.c : Mismatch in CanTrcv Specification Minor Version"
#endif

#if (CANTRCV_VERSION_AR_RELEASE_REVISION_VERSION != \
  CANTRCV_VERSION_C_AR_RELEASE_REVISION_VERSION)
#error "CanTrcv_Version.c : Mismatch in CanTrcv Specification Revision \
  Version"
#endif

#if (CANTRCV_VERSION_SW_MAJOR_VERSION != CANTRCV_VERSION_C_SW_MAJOR_VERSION)
#error "CanTrcv_Version.c : Mismatch in CanTrcv Software Major Version"
#endif

#if (CANTRCV_VERSION_SW_MINOR_VERSION != CANTRCV_VERSION_C_SW_MINOR_VERSION)
#error "CanTrcv_Version.c : Mismatch in CanTrcv Software Minor Version"
#endif

#if (CANIF_AR_RELEASE_MAJOR_VERSION != CANTRCV_CANIF_AR_RELEASE_MAJOR_VERSION)
#error "CanIf.h : Mismatch in CanIf Specification Major Version"
#endif

#if (CANIF_AR_RELEASE_MINOR_VERSION != CANTRCV_CANIF_AR_RELEASE_MINOR_VERSION)
#error "CanIf.h : Mismatch in CanIf Specification Minor Version"
#endif

#if(STD_ON == CANTRCV_DEV_ERROR_DETECT)
#if (DET_AR_RELEASE_MAJOR_VERSION != CANTRCV_DET_AR_RELEASE_MAJOR_VERSION)
#error "Det.h : Mismatch in Det Specification Major Version"
#endif

#if (DET_AR_RELEASE_MINOR_VERSION != CANTRCV_DET_AR_RELEASE_MINOR_VERSION)
#error "Det.h : Mismatch in Det Specification Minor Version"
#endif
#endif

/*******************************************************************************
 **                      Global Data                                          **
 *******************************************************************************/

/*******************************************************************************
 **                      Function Definitions                                 **
 *******************************************************************************/

/*******************************************************************************
 **                      End of File                                          **
 *******************************************************************************/
