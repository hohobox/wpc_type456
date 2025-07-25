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
**  SRC-MODULE: Com_TxIpdu.h                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Com Module                                            **
**                                                                            **
**  PURPOSE   : Provision of declaration of initialization functions.         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By          Description                            **
********************************************************************************
** 2.5.3     10-Sep-2020   SM Kwon     Internal Redmine #23914, #25250        **
** 2.4.2     09-Apr-2019   SM Kwon     Internal Redmine #16805                **
** 2.4.0     29-Jan-2019   SM Kwon     Internal Redmine #14067                **
** 2.2.3     08-Dec-2017   Chan Kim    Internal Redmine #10849, #10851        **
** 2.2.0     16-Apr-2017   Chan Kim    Internal Redmine #7525                 **
** 2.1.0     25-May-2016   Chan Kim    Internal Redmine #4998                 **
** 1.0.16    27-Feb-2015   Chan Kim    Internal Redmine #2202                 **
** 1.0.0     29-Apr-2013   AUTOEVER    Initial Version                        **
*******************************************************************************/

#ifndef COM_TXIPDU_H
#define COM_TXIPDU_H

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define COM_TXIPDU_AR_RELEASE_MAJOR_VERSION  4
#define COM_TXIPDU_AR_RELEASE_MINOR_VERSION  0
#define COM_TXIPDU_AR_RELEASE_REVISION_VERSION  3

/* Software Version Information */
#define COM_TXIPDU_SW_MAJOR_VERSION  2
#define COM_TXIPDU_SW_MINOR_VERSION  9

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if(COM_TX_IPDU == STD_ON)
#define COM_START_SEC_CODE
#include "MemMap.h"
#if ((COM_TX_IPDU_TMS_SIG_BASED == STD_ON) || \
  (COM_TX_IPDU_REPETITION == STD_ON) || \
  ((COM_TX_IPDU_MINDELAY_ENABLED == STD_ON) && (COM_TX_IPDU_GW == STD_ON))|| \
  (COM_TX_IPDU_GW == STD_ON) || \
  (COM_TX_IPDU_DM == STD_ON))
extern FUNC(Std_ReturnType, COM_CODE) Com_TxRequest(PduIdType LddTxPduId,
                                                                uint16 Config);

#else
extern FUNC(Std_ReturnType, COM_CODE) Com_TxRequest
                               (PduIdType LddTxPduId);
#endif

#define COM_STOP_SEC_CODE
#include "MemMap.h"
#endif

#endif /* COM_MAIN_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
