/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Cbk.h                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Call back process Functions                **
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
** 2.1.0     19-May-2022   HM Shin     Internal Redmine #34769                **
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #6788                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_CBK_H
#define IPDUM_CBK_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_CBK_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_CBK_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_CBK_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_CBK_SW_MAJOR_VERSION                     2
#define IPDUM_CBK_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_RX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_RxIndication( PduIdType RxPduId, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_RX_IPDU == STD_ON)*/

#if (IPDUM_TX_CONFIRMATION == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_TxConfirmation(PduIdType TxPduId);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_TX_CONFIRMATION == STD_ON)*/

#if (IPDUM_TX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TriggerTransmit(
  PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC,
    IPDUM_VAR) PduInfoPtr);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_TX_IPDU == STD_ON)*/

#if (IPDUM_TX_CONFIRMATION == STD_OFF)
#define IpduM_TxConfirmation(TxPduId)
#endif

#endif /* #if (IPDUM_ENABLE == STD_ON) */

#endif /* IPDUM_CBK_H */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

