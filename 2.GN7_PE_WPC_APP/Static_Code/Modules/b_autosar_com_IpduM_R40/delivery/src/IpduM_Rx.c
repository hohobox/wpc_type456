/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Rx.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Receive process Functions                  **
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
** 2.0.3     30-Nov-2016   Chan Kim    Internal Redmine #6788, #6822          **
** 2.0.2     15-Jul-2016   Chan Kim    Internal Redmine #5563                 **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_IpduM.h"
#include "IpduM_Internal.h"
#include "IpduM_Ram.h"
#include "IpduM_Rx.h"
#include "IpduM_Cbk.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_RECEIVE_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_RECEIVE_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_RECEIVE_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_RECEIVE_C_SW_MAJOR_VERSION            2
#define IPDUM_RECEIVE_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != \
     IPDUM_RECEIVE_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Rx.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != \
     IPDUM_RECEIVE_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Rx.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_RECEIVE_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Rx.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_RECEIVE_C_SW_MAJOR_VERSION)
#error "IpduM_Rx.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_RECEIVE_C_SW_MINOR_VERSION)
#error "IpduM_Rx.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)
/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured  memory access index */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */

/*******************************************************************************
** Function Name        : IpduM_RxIndication                                  **
**                                                                            **
** Service ID           : 0x42                                                **
**                                                                            **
** Description          : This service is indication of a received I-PDU from **
**                        a lower layer communication module. This service    **
**                        generate Rx Indication for dynamic I-PDUs and static**
**                        I-PDU(if configured)                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant for the same PDU-ID. Re-entrant for  **
**                        different PDU-ID.                                   **
**                                                                            **
** Input Parameters     : PduIdType RxPduId, const PduInfoType PduInfoPtr     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        IpduM_GblStatus, IpduM_GaaRxInIpdu[],               **
**                        IpduM_GaaRxSegmentField[]                           **
**                        IpduM_Max_Rx_Pdu_ID                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        IpduM_BinarySearch(), IpduM_LinearSearch(),         **
**                        PduR_IpduMRxIndication(), IpduM_CopySegmentByte(),  **
**                        Det_ReportError(), IpduM_CopySegmentBit(),          **
**                        IpduM_GetSelBitField(), Com_RxIndication()          **
*******************************************************************************/
#if (IPDUM_RX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_RxIndication(PduIdType RxPduId, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr)
{
  /* Local pointer to hold the Rx indication structure*/
  P2CONST(IpduM_RxIpdu, AUTOMATIC, IPDUM_CONST) LpRxInIpdu;

  /* Local pointer to Rx copy bit field selector*/
  P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC,
    IPDUM_CONST) LpRxIpduSegmentField;

  /* Local pointer to Rx copy bit field selector*/
  P2CONST(IpduM_RxPduSegmentBitField, AUTOMATIC, IPDUM_CONST)
  LpRxIpduSegmentFieldDynamic;

  /* Local variable to store Selector value */
  uint8 LucSelBitValue;
  boolean LblReturnValue;

  /* Local variable for returnvalue */
  LblReturnValue = IPDUM_TRUE;

  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)

  if (IPDUM_UNINIT == IpduM_GblStatus)
  {
    /* report DET with IPDUM_E_UNINIT*/
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
      (uint8)IPDUM_RXINDICATION_SID, (uint8)IPDUM_E_UNINIT);
    LblReturnValue = IPDUM_FALSE;
  }                               /* End of if(IpduM_GblStatus == IPDUM_UNINIT)
                                   **/
  else
  {
    if (((PduIdType)IpduM_Max_Rx_Pdu_ID) < RxPduId)
    {
      /* report DET with IPDUM_E_PARAM*/
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        (uint8)IPDUM_RXINDICATION_SID, (uint8)IPDUM_E_PARAM);
      LblReturnValue = IPDUM_FALSE;
    }                             /* End of if(RxPduId >
                                   *((PduIdType)IpduM_Max_Rx_Pdu_ID)) */

    if (NULL_PTR == PduInfoPtr)
    {
      LblReturnValue = (uint8)IPDUM_FALSE;
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        (uint8)IPDUM_RXINDICATION_SID, (uint8)IPDUM_E_PARAM_POINTER);
    }
    else
    {
      /* Check if SduDataPtr is NULL Pointer*/
      if (NULL_PTR == PduInfoPtr->SduDataPtr)
      {
        LblReturnValue = (uint8)IPDUM_FALSE;
        (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
          (uint8)IPDUM_RXINDICATION_SID, (uint8)IPDUM_E_PARAM_POINTER);
      }
    }                             /* End of else */
  }                               /* End of else */
  #else
  if (((PduIdType)IpduM_Max_Rx_Pdu_ID < RxPduId) ||
        ((PduLengthType)IPDUM_ZERO == PduInfoPtr->SduLength))
  {
    LblReturnValue = IPDUM_FALSE;
  }
  #endif /* #if (IPDUM_DEV_ERROR_DETECT == STD_ON) */

  if (IPDUM_TRUE == LblReturnValue)
  {
    /* Get the pointer to Rx Ipdu structure */
    LpRxInIpdu = &IpduM_GaaRxInIpdu[RxPduId];

    /* Get and store the Sel Bit value */
    LucSelBitValue = IpduM_GetSelBitField(LpRxInIpdu->pRxSelBitField,
      PduInfoPtr->SduDataPtr);

    #if (IPDUM_RX_STATIC_IPDU == STD_ON)

    /* Check whether static I-PDU is configured */
    if ((IPDUM_TRUE) == LpRxInIpdu->blStaticIpduExist)
    {
      LpRxIpduSegmentField =
        &IpduM_GaaRxSegmentField[LpRxInIpdu->ucRxSegmentBitFieldIndex];

      #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
      /* LpRxIpduSegmentFieldDynamic->ddUpPduId should be from COM layer */
      Com_RxIndication(LpRxIpduSegmentField->ddUpPduId, PduInfoPtr);
      #else
      /* call PduR_IpduMRxIndication */
      PduR_IpduMRxIndication(LpRxIpduSegmentField->ddUpPduId, PduInfoPtr);
      #endif /* #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
      LpRxIpduSegmentField = 
      &IpduM_GaaRxSegmentField[LpRxInIpdu->ucRxSegmentBitFieldIndex+IPDUM_ONE];
    }                             /* End of if(LpRxInIpdu->blStaticIpduExist ==
                                   *(IPDUM_TRUE)) */
    else
    {
      LpRxIpduSegmentField = (IpduM_RxPduSegmentBitField*) NULL_PTR;
    }
    #else
    LpRxIpduSegmentField =
      &IpduM_GaaRxSegmentField[LpRxInIpdu->ucRxSegmentBitFieldIndex];
    #endif

    /*
     * Check whether received selector field is part of database or not
     * Search selector field in the data base for dynamic I-PDU
     */
    #if (IPDUM_RX_STATIC_IPDU == STD_ON)
    if(NULL_PTR != LpRxIpduSegmentField)
    #endif
    {
      #if (IPDUM_LINEAR_SEARCH == STD_ON)
      LpRxIpduSegmentFieldDynamic = IpduM_LinearSearch(LpRxIpduSegmentField,
        LpRxInIpdu->ucNoOfDynRxIndIpdu, LucSelBitValue);
      #endif /*(IPDUM_LINEAR_SEARCH == STD_ON)*/
      #if (IPDUM_BINARY_SEARCH == STD_ON)

      /* Search selector field in the data base for dynamic I-PDU */
      LpRxIpduSegmentFieldDynamic = IpduM_BinarySearch(LpRxIpduSegmentField,
        LpRxInIpdu->ucNoOfDynRxIndIpdu, LucSelBitValue);
      #endif /*(IPDUM_BINARY_SEARCH == STD_ON)*/
    }
    #if (IPDUM_RX_STATIC_IPDU == STD_ON)
    else
    {
      LpRxIpduSegmentFieldDynamic = (IpduM_RxPduSegmentBitField*) NULL_PTR;
    }
    #endif
    /*Check if base address of segment bit field for dynamic part is not null
                                                                   pointer*/
    if (NULL_PTR != LpRxIpduSegmentFieldDynamic)
    {
      /* call PduR_IpduMRxIndication */
      #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)

      /* LpRxIpduSegmentFieldDynamic->ddUpPduId should be from COM layer */
      Com_RxIndication(LpRxIpduSegmentFieldDynamic->ddUpPduId, PduInfoPtr);
      #else
      PduR_IpduMRxIndication(LpRxIpduSegmentFieldDynamic->ddUpPduId,
        PduInfoPtr);
      #endif /* #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
    }                             /* End of if(LpRxIpduSegmentFieldDynamic !=
                                   *NULL_PTR) */
  }                               /* End of if(LblReturnValue == IPDUM_TRUE) */
}                                 /* End of IpduM_RxIndication( PduIdType
                                   *RxPduId, */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (IPDUM_RX_IPDU == STD_ON) */

/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */

#endif /* #if (IPDUM_ENABLE == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

