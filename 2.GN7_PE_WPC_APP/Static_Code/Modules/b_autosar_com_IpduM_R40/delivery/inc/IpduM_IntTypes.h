/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_IntTypes.h                                              **
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
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #5688                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_INTTYPES_H
#define IPDUM_INTTYPES_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM.h"
#if (IPDUM_ENABLE == STD_ON)
#if (IPDUM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"
#endif
#endif /* #if (IPDUM_ENABLE == STD_ON) */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_INTTYPES_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_INTTYPES_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_INTTYPES_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_INTTYPES_SW_MAJOR_VERSION                     2
#define IPDUM_INTTYPES_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)

/* polyspace-begin MISRA-C3:D4.8 [Not a defect: Justified] "Structure will be derefernenced based on Configuration" */
typedef struct
{
  /* Start Mask for selector bit field */
  uint8 ucStartMask;

  /* Number of shift bits to extract the data */
  uint8 ucNoOfShiftBits;

  /* Offset to Select Bit Position in IpduM buffer */
  uint8 ucOffSetValue;
} IpduM_SelBitField;

typedef struct
{
  /* Pointer to IpduM buffer */
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) pIpduMDestBuffer;

  /* Number of Byte */
  uint8 ucNoOfByte;

  /* Source start mask value */
  uint8 ucSourceStartMask;

  /* Source end mask value */
  uint8 ucSourceEndMask;

  /* Source byte Offset value */
  uint8 ucSourceOffSet;
} IpduM_Segment;

typedef struct
{
  #if (IPDUM_TX_CONFIRMATION == STD_ON)

  /* RAM Pointer to Confirmation counter if configured */
  P2VAR(uint16, AUTOMATIC, IPDUM_VAR) pTxTimeoutCounter;
  #endif

  /* Pointer to Tx Pending Flag. Tool should allocate one bit of RAM for each
   *   Tx Ipdu. This parameter can not be null pointer  */
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) pTxPendingFlag;

  /* Pointer to PduInfoType structure */
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) pPduInfoPtr;

  /* Timeout counter for Tx Confirmation if configured */
  uint16 usTimeoutCount;

  /* Initial Dynamic id for TxOutPDU based on IpduMInitialSelector value */
  PduIdType ddInitialDynamicPduId;

  /* Static PDU ID for which confirmation is required for upper layer, If any
   *   of the out IPDU is not having static part then value will be
   * IPDUM_INVALID
   */
  PduIdType ddStaticPduId;

  /*  source pdu id from PDUR configuration reference (PduRSrcPduRef )*/
  PduIdType ddTxLoPduId;

  /* Tx Pending Mask value. Tool should allocate corresponding mask value
   *   for the RAM bit allocated for pTxPendingFlag */
  uint8 ucTxPendingMask;

  #if (IPDUM_TX_STATIC_IPDU == STD_ON)
  /* Static Ipdu if configured */
  boolean blStaticIpduExist;
  #endif

} IpduM_TxOutIpdu;

typedef struct
{
  #if (IPDUM_SEGMENT_BITFIELD == STD_ON)

  /* Structure to Copy Bit field, can not be null */
  P2CONST(IpduM_Segment, AUTOMATIC, IPDUM_CONST) pSegmentBitField;
  #else

  /* Pointer to IpduM buffer */
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) pIpduMDestBuffer;
  #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */

  /* PDU id for TxOutIpdu of multiplexed IPDU */
  PduIdType ddTxOutIpduId;

  /* Destination PDU ID fetched from PDUR (configurationsPduRDestPduRef) or COM
   * (ComIPduHandleId). ComIPduHandleId will be fetched only in case of
     IpduMRxDirectComInvocation is set to TRUE */
  PduIdType ddTxUpIpduId;

  /* Number of Copy Bit Field */
  uint8 ucNoOfSegmentBitField;

  #if (IPDUM_SEGMENT_BITFIELD == STD_OFF)
  /* Indicates length of static/dynamic part in terms of bytes */
  uint8 ucPduLength;

  /* Source byte Offset value */
  uint8 ucSourceOffset;
  #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_OFF) */

  /* If incoming part is Dynamic Part:IPDUM_TRUE, and for Static Part  :
   *                                                               IPDUM_FALSE
   * */
  boolean blTxDynamicPart;

  #if (IPDUM_JIT_UPDATE == STD_ON)

  /* Boolean variable for JIT Update */
  boolean blJitUpdate;
  #endif

  /* Boolean variable for whether TxConfirmation is required or not */
  boolean blTxConfirmRequired;

  /* IpduM Part : None (0), Trigger (1). Depends upon "IPduMTxTriggerMode"
     parameter. e.g. If configured for static, Tx I-PDU belongs to static I-PDU
     should have true state
  */
  boolean blTxTriggerState;
} IpduM_TxInIpdu;

typedef struct
{
  /* ddUpPduId source pdu id from PDUR configuration reference for static and
   *    dynamic part */
  PduIdType ddUpPduId;

  /* Selector value for comparison, for static part this value will be 0xff */
  uint8 ucSelectorValue;
} IpduM_RxPduSegmentBitField;

typedef struct
{
  /* Structure for Rx Selector Bit Field.This parameter can not be null
   *   pointer */
  P2CONST(IpduM_SelBitField, AUTOMATIC, IPDUM_CONST) pRxSelBitField;

  /* index for Copy Bit Field for Static part */
  uint8 ucRxSegmentBitFieldIndex;

  /* Number of Dynamic Rx Indication Ipdu */
  uint8 ucNoOfDynRxIndIpdu;
  #if (IPDUM_RX_STATIC_IPDU == STD_ON)

  /* Static Ipdu if configured */
  boolean blStaticIpduExist;
  #endif
} IpduM_RxIpdu;

typedef signed int IpduM_PtrType;

#endif /* IPDUM_INTTYPES_H */
/* polyspace-end MISRA-C3:D4.8 [Not a defect: Justified] "Structure will be derefernenced based on Configuration" */

#endif /* #if (IPDUM_ENABLE == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

