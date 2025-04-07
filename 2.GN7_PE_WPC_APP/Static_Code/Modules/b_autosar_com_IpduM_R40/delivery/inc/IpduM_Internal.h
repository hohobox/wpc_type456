/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Internal.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Internal process Functions                 **
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
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #6788, #6822          **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/
#ifndef IPDUM_INTERNAL_H
#define IPDUM_INTERNAL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IpduM_PCTypes.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
/* AUTOSAR Specification Version Information */
#define IPDUM_INTERNAL_AR_RELEASE_MAJOR_VERSION             4
#define IPDUM_INTERNAL_AR_RELEASE_MINOR_VERSION             0
#define IPDUM_INTERNAL_AR_RELEASE_REVISION_VERSION          3

/* Software Version Information */
#define IPDUM_INTERNAL_SW_MAJOR_VERSION                     2
#define IPDUM_INTERNAL_SW_MINOR_VERSION                     1
/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)

/* polyspace-begin MISRA-C3:20.7 [Not a defect:Justified] "No Impact of this rule violation" */
#if (IPDUM_SEGMENT_BITFIELD == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_CopySegmentBit(P2CONST(IpduM_Segment,
    AUTOMATIC,IPDUM_CONST) LpSegmentBitField, P2VAR(
    uint8, AUTOMATIC, IPDUM_VAR) LpSduPtr, uint8 LucNoOfSegmentBitField);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_SEGMENT_BITFIELD == STD_ON)*/

#if (IPDUM_SEGMENT_BITFIELD == STD_OFF)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, IPDUM_CODE) IpduM_CopySegmentByte(P2CONST(IpduM_TxInIpdu,
    AUTOMATIC, IPDUM_CONST) LpTxInIpdu, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) LpSduPointer);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*(IPDUM_SEGMENT_BITFIELD == STD_OFF)*/

#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(uint8, IPDUM_CODE) IpduM_GetSelBitField(P2CONST(IpduM_SelBitField,
    AUTOMATIC,
    IPDUM_CONST) LpSelBitField, P2CONST(
    uint8, AUTOMATIC, IPDUM_CONST) LpDestBuffer);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"

#if (IPDUM_BINARY_SEARCH == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST),
  IPDUM_CODE) IpduM_BinarySearch(P2CONST(IpduM_RxPduSegmentBitField,
    AUTOMATIC, IPDUM_CONST) LpIpdu, uint8 LucSize, uint8 LucSelectorValue);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (IPDUM_BINARY_SEARCH == STD_ON) */

#if (IPDUM_LINEAR_SEARCH == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
extern FUNC(P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST),
  IPDUM_CODE) IpduM_LinearSearch(P2CONST(IpduM_RxPduSegmentBitField,
    AUTOMATIC, IPDUM_CONST) LpRxIpdu, uint8 LucSize, uint8 LucSelectorVal);

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of if (IPDUM_LINEAR_SEARCH == STD_ON) */

#endif /*#if (IPDUM_ENABLE == STD_ON)*/

#endif /* IPDUM_INTERNAL_H */
/* polyspace-end MISRA-C3:20.7 [Not a defect:Justified] "No Impact of this rule violation" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

