/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_PCTypes.h                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Global definitions                         **
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
** 2.0.5     07-Dec-2020   Jongsun Lim #27006                                 **
** 2.0.4     21-Dec-2016   Chan Kim    Internal Redmine #7006                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_PCTYPES_H
#define IPDUM_PCTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_IntTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_PCTYPES_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_PCTYPES_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_PCTYPES_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_PCTYPES_SW_MAJOR_VERSION                     2
#define IPDUM_PCTYPES_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      MACROs                                                **
*******************************************************************************/
/* Instance ID */
#define IPDUM_INSTANCE_ID           0x00

/*Macro for zero*/
#define IPDUM_ZERO                  0x00

/*Macro for one*/
#define IPDUM_ONE                   0x01

/*Macro for eight*/
#define IPDUM_EIGHT                 0x08

/*Macro for invalid  id*/
#define IPDUM_INVALID               ((PduIdType)0xFFFF)

/*Boolean value for initialized state*/
#define IPDUM_INIT                  ((boolean)1)

/*Boolean value for uninitialized state*/
#define IPDUM_UNINIT                ((boolean)0)

/*Boolean value for true*/
#define IPDUM_TRUE                  ((boolean)1)

/*Boolean value for false*/
#define IPDUM_FALSE                 ((boolean)0)

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)

/* polyspace-begin MISRA-C3:8.11 [Not a defect:Justified] "No Impact of this rule violation(Array size will fixed in linking time)" */ 
#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (IPDUM_TX_IPDU == STD_ON)
/* Global array for IpduM structure  */
extern CONST(IpduM_TxInIpdu, IPDUM_CONST) IpduM_GaaTxInIpdu[];
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (IPDUM_TX_IPDU == STD_ON)
extern CONST(IpduM_TxOutIpdu, IPDUM_CONST) IpduM_GaaTxOutIpdu[];
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

extern CONST(PduIdType, IPDUM_CONST) IpduM_GaaTxConfirmMapArray[];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (IPDUM_RX_IPDU == STD_ON)
extern CONST(IpduM_RxIpdu, IPDUM_CONST) IpduM_GaaRxInIpdu[];
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
#if (IPDUM_RX_IPDU == STD_ON)
extern CONST(IpduM_RxPduSegmentBitField, IPDUM_CONST) IpduM_GaaRxSegmentField[];
#endif
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IpduM_Segment, IPDUM_CONST) IpduM_GaaSegmentField[];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IpduM_SelBitField, IPDUM_CONST) IpduM_GaaSelBitField[];
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#if (IPDUM_JIT_UPDATE == STD_ON)
#define IPDUM_START_SEC_VAR_INIT_8
#include "MemMap.h"
extern VAR(PduIdType, IPDUM_VAR) IpduM_GaaJITDynamicId[];
#define IPDUM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"
#endif /*(IPDUM_JIT_UPDATE == STD_ON)*/

#if (IPDUM_TX_CONFIRMATION == STD_ON)
#define IPDUM_START_SEC_VAR_INIT_8
#include "MemMap.h"
extern VAR(PduIdType, IPDUM_VAR) IpduM_GaaTxConfrmDynamicHandleId[];
#define IPDUM_STOP_SEC_VAR_INIT_8
#include "MemMap.h"

#endif /*(IPDUM_TX_CONFIRMATION == STD_ON)*/

#define IPDUM_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(uint8, IPDUM_VAR)IpduM_GaaTxPendingFlag[1];
#define IPDUM_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"




/*******************************************************************************
**                      Variable for Library                                  **
*******************************************************************************/
#define IPDUM_START_SEC_CONST_16
#include "Memmap.h"
extern CONST(uint16, IPDUM_CONST) IpduM_No_Of_Tx_Pathways;
#define IPDUM_STOP_SEC_CONST_16
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_16
#include "Memmap.h"
extern CONST(uint16, IPDUM_CONST) IpduM_Tx_Pending_Flag_Bytes;
#define IPDUM_STOP_SEC_CONST_16
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"
extern CONST(PduIdType, IPDUM_CONST) IpduM_Max_Tx_Pdu_ID;
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"

#define IPDUM_START_SEC_CONST_UNSPECIFIED
#include "Memmap.h"
extern CONST(PduIdType, IPDUM_CONST) IpduM_Max_Rx_Pdu_ID;
#define IPDUM_STOP_SEC_CONST_UNSPECIFIED
#include "Memmap.h"

#endif /*#if (IPDUM_ENABLE == STD_ON)*/

#endif /* IPDUM_PCTYPES_H */
/* polyspace-end MISRA-C3:8.11 [Not a defect:Justified] "No Impact of this rule violation(Array size will fixed in linking time)" */ 

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

