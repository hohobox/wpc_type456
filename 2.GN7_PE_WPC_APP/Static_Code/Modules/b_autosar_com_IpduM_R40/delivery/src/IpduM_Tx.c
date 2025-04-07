/*******************************************************************************
**                                                                            **
**  (C) 2013 HYUNDAI AUTOEVER Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: IpduM_Tx.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IpduM Module                                          **
**                                                                            **
**  PURPOSE   : Provision of IpduM Transmit process Functions                 **
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
** 2.0.2     15-Jul-2016   Chan Kim    Internal Redmine #5552, #5563          **
** 2.0.1     25-May-2016   Chan Kim    Internal Redmine #5014                 **
** 2.0.0     08-Apr-2016   Chan Kim    Internal Redmine #4599                 **
** 1.0.11    09-Jan-2015   Chan Kim    Internal Redmine #2001                 **
** 1.0.0     29-Apr-2013   Autoever      Initial Version                        **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "PduR_IpduM.h"
#include "IpduM_Ram.h"
#include "IpduM_Internal.h"
#include "IpduM_Tx.h"
#include "IpduM_Cbk.h"
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define IPDUM_TRANSMIT_C_AR_RELEASE_MAJOR_VERSION    4
#define IPDUM_TRANSMIT_C_AR_RELEASE_MINOR_VERSION    0
#define IPDUM_TRANSMIT_C_AR_RELEASE_REVISION_VERSION 3

/* IPDUM software version information */
#define IPDUM_TRANSMIT_C_SW_MAJOR_VERSION            2
#define IPDUM_TRANSMIT_C_SW_MINOR_VERSION            1
/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (IPDUM_AR_RELEASE_MAJOR_VERSION != \
     IPDUM_TRANSMIT_C_AR_RELEASE_MAJOR_VERSION)
#error "IpduM_Tx.c : Mismatch in Specification Major Version"
#endif
#if (IPDUM_AR_RELEASE_MINOR_VERSION != \
     IPDUM_TRANSMIT_C_AR_RELEASE_MINOR_VERSION)
#error "IpduM_Tx.c : Mismatch in Specification Minor Version"
#endif
#if (IPDUM_AR_RELEASE_REVISION_VERSION != \
     IPDUM_TRANSMIT_C_AR_RELEASE_REVISION_VERSION)
#error "IpduM_Tx.c : Mismatch in Specification Revision Version"
#endif
#if (IPDUM_SW_MAJOR_VERSION != IPDUM_TRANSMIT_C_SW_MAJOR_VERSION)
#error "IpduM_Tx.c : Mismatch in Software Major Version"
#endif
#if (IPDUM_SW_MINOR_VERSION != IPDUM_TRANSMIT_C_SW_MINOR_VERSION)
#error "IpduM_Tx.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if (IPDUM_ENABLE == STD_ON)
/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
/* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> Pointer is not outside its bounds - Pointer is generated by Generator*/
/* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > configured  memory access index */

#if ((IPDUM_DEV_ERROR_DETECT == STD_ON) && (IPDUM_TX_IPDU == STD_ON))
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_DetCheckTxFuncs(
  uint8 LucServiceId,PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*#if (IPDUM_DEV_ERROR_DETECT == STD_ON)*/

#if ((IPDUM_TX_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_UpdateJitPart(PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr);
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*#if ((IPDUM_TX_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))*/

/*******************************************************************************
** Function Name        : IpduM_DetCheckTxFuncs                               **
**                                                                            **
** Service ID           : Not applicable                                      **
**                                                                            **
** Description          : This function performs NULL pointer check on        **
**                        PduInfoPtr and reports DET.                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : uint8 LucServiceId,TxPduId                          **
**                        PduInfoType *LpPduInfoPtr                           **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Det_ReportError                                     **
*******************************************************************************/
#if ((IPDUM_DEV_ERROR_DETECT == STD_ON) && (IPDUM_TX_IPDU == STD_ON))
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_DetCheckTxFuncs(
  uint8 LucServiceId, PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr)
{
  Std_ReturnType LddReturnVal;
  LddReturnVal = (Std_ReturnType)E_OK;

  if (IPDUM_UNINIT == IpduM_GblStatus)
  {
    /* report DET with IPDUM_E_UNINIT*/
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
      LucServiceId, (uint8)IPDUM_E_UNINIT);
    LddReturnVal = (Std_ReturnType)E_NOT_OK;
  }/* End of if(IpduM_GblStatus == IPDUM_UNINIT) */
  else
  {
    /* check PdumTxPduId is greater than maximum TxPduId*/
    if (TxPduId > ((PduIdType)IpduM_Max_Tx_Pdu_ID))
    {
      LddReturnVal = (Std_ReturnType)E_NOT_OK;

      /* report DET with IPDUM_E_PARAM*/
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        LucServiceId, (uint8)IPDUM_E_PARAM);
    }
    /* Check if PduInfoPtr is NULL Pointer */
    if(PduInfoPtr == NULL_PTR)
    {
      LddReturnVal = (Std_ReturnType)E_NOT_OK;
      /* Report DET with IPDUM_E_PARAM_POINTER */
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        LucServiceId,(uint8)IPDUM_E_PARAM_POINTER);
    }
    else if(PduInfoPtr->SduDataPtr == NULL_PTR)
    {
      LddReturnVal = (Std_ReturnType)E_NOT_OK;
      /* Report DET with IPDUM_E_PARAM_POINTER */
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        LucServiceId,(uint8)IPDUM_E_PARAM_POINTER);
    }
    else
    {
      /* Do Nothing  */
    }
  }
  return (LddReturnVal);
}
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : IpduM_UpdateJitPart                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called by the IpduM_Transmit       **
**                        function to update one of the part of multiplexed   **
**                        ipdu if JIT is ON                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant for the same PDU-ID. Re-entrant for  **
**                        different PDU-ID.                                   **
**                                                                            **
** Input Parameters     : PduIdType TxPduId,                                  **
**                        const PduInfoType *PduInfoPtr                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : IpduM_GaaTxInIpdu[],       **
**                                                 IpduM_GaaJITDynamicId[],   **
**                                          IpduM_GaaTxConfrmDynamicHandleId[]**
**                        Function(s) invoked    : IpduM_CopySegmentBit,      **
**                                                 IpduM_CopySegmentByte,     **
**                                                 Com_TriggerTransmit,       **
**                                                 PduR_IpduMTriggerTransmit  **
*******************************************************************************/
#if ((IPDUM_TX_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_UpdateJitPart(PduIdType TxPduId,
  P2CONST(PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr)
{
  P2CONST(IpduM_TxInIpdu, AUTOMATIC, IPDUM_CONST) LpTransUpdtedPrtInIpdu;
  /*Local structure of PduInfoType */
  PduInfoType LddPduInfo;
  /* Local pointer to check Sdu pointer DET and
   *   Local variable ptr to PduInfoPtr */
  P2VAR(PduInfoType, AUTOMATIC, IPDUM_VAR) LpPduInfoPointer;
  uint8 LaaSduDataPtr[IPDUM_MAX_PDU_LENGTH];

  /*Local variable for returnvalue*/
  Std_ReturnType LddReturnValue;

  LpPduInfoPointer = &LddPduInfo;
  LddPduInfo.SduDataPtr = &LaaSduDataPtr[IPDUM_ZERO];
  LddReturnValue = (Std_ReturnType)E_OK;

  /* Get the pointer to Tx In Ipdu for 2nd part either dynamic or
     *       static part */
  LpTransUpdtedPrtInIpdu = &IpduM_GaaTxInIpdu[TxPduId];
  if (IPDUM_TRUE == LpTransUpdtedPrtInIpdu->blJitUpdate)
  {
    /* Invoke the trigger transmit function */
    #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
    /* If IpduMRxDirectComInvocation is TRUE
     * ddTxUpIpduId should be from COM layer */
    LddReturnValue = Com_TriggerTransmit(
                  LpTransUpdtedPrtInIpdu->ddTxUpIpduId,&LddPduInfo);
    #else
    /* If IpduMRxDirectComInvocation is FALSE
     * ddTxUpIpduId should be from PDUR layer */
    LddReturnValue = PduR_IpduMTriggerTransmit(
                  LpTransUpdtedPrtInIpdu->ddTxUpIpduId,&LddPduInfo);
    #endif

    if ((Std_ReturnType)E_OK == LddReturnValue)
    {
      /* Multiplex the updated part by Copying the data into static or
        *   dynamic part 2nd part */
      #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
      IpduM_CopySegmentBit(LpTransUpdtedPrtInIpdu->pSegmentBitField,
        LpPduInfoPointer->SduDataPtr,
        LpTransUpdtedPrtInIpdu->ucNoOfSegmentBitField);
      #else

      /* Copy the data into static I-PDUs buffer */
      IpduM_CopySegmentByte(LpTransUpdtedPrtInIpdu, LpPduInfoPointer);
      #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */

      #if (IPDUM_TX_CONFIRMATION == STD_ON)
      if (IPDUM_TRUE == LpTransUpdtedPrtInIpdu->blTxDynamicPart)
      {
        /* Stored Transmitted Dynamic Handle Id*/
        IpduM_GaaTxConfrmDynamicHandleId[LpTransUpdtedPrtInIpdu->ddTxOutIpduId]
          = TxPduId;
      }
      #endif /* (IPDUM_TX_CONFIRMATION == STD_ON) */
    }
  } /* End of *if(IpduM_GaaTxInIpdu[LddPduId].blJitUpdate == IPDUM_TRUE)*/
  else
  {
    /* Copy the data into static or dynamic I-PDUs */
    #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
      IpduM_CopySegmentBit(LpTransUpdtedPrtInIpdu->pSegmentBitField,
       PduInfoPtr->SduDataPtr, LpTransUpdtedPrtInIpdu->ucNoOfSegmentBitField);
    #else
    /* Copy the data into static I-PDUs buffer */
      IpduM_CopySegmentByte(LpTransUpdtedPrtInIpdu,PduInfoPtr);
    #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */

    if (IPDUM_TRUE == LpTransUpdtedPrtInIpdu->blTxDynamicPart)
    {  /* Store the latest Dynamic ID */
      IpduM_GaaJITDynamicId[LpTransUpdtedPrtInIpdu->ddTxOutIpduId] = TxPduId;
    }
  }
  return(LddReturnValue);
}
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /*#if ((IPDUM_TX_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))*/

/*******************************************************************************
** Function Name        : IpduM_Transmit                                      **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This function is called by the PDU Router to        **
**                        initiate transmission.                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant for the same PDU-ID. Re-entrant for  **
**                        different PDU-ID.                                   **
**                                                                            **
** Input Parameters     : PduIdType PdumTxPduId,                              **
**                        const PduInfoType *PduInfoPtr                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : IpduM_GblStatus,           **
**                                                 IpduM_GaaTxInIpdu[],       **
**                                                 IpduM_GaaTxOutIpdu[]       **
**                                          IpduM_GaaTxConfrmDynamicHandleId[]**
**                                          IpduM_Max_Tx_Pdu_ID               **
**                                                                            **
**                        Function(s) invoked    : Det_ReportError,           **
**                                                 PduR_IpduMTransmit,        **
**                                                 IpduM_CopySegmentBit,      **
**                                                 IpduM_CopySegmentByte,     **
**                        SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA(),       **
**                        SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA()         **
**                        IpduM_UpdateJitPart()                               **
*******************************************************************************/
#if (IPDUM_TX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_Transmit(PduIdType PdumTxPduId, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr)
{
  /* Local pointer to point the starting location of In Ipdu*/
  P2CONST(IpduM_TxInIpdu, AUTOMATIC, IPDUM_CONST) LpTxInIpdu;

  /* Local pointer to point the starting location of IpduM */
  P2CONST(IpduM_TxOutIpdu, AUTOMATIC, IPDUM_CONST) LpTxOutIpdu;

  /*Local variable for returnvalue*/
  Std_ReturnType LddReturnVal;

  #if (IPDUM_JIT_UPDATE == STD_ON)
  PduIdType LddPduId;
  #endif

  #if (IPDUM_JIT_UPDATE == STD_ON)
  /*Local structure of PduInfoType */
  PduInfoType LddPduInfo;
  /* Local pointer to check Sdu pointer DET and
   *   Local variable ptr to PduInfoPtr */
  uint8 LaaSduDataPtr[IPDUM_MAX_PDU_LENGTH];
  LddPduInfo.SduDataPtr = &LaaSduDataPtr[IPDUM_ZERO];
  LddPduId = IPDUM_INVALID;
  #endif /* #if(IPDUM_JIT_UPDATE == STD_ON)*/
  #if ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON) && \
  (IPDUM_DEV_ERROR_DETECT == STD_OFF))
  LddReturnVal = (Std_ReturnType)E_OK;
  #endif

  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)
   LddReturnVal = IpduM_DetCheckTxFuncs(((uint8)IPDUM_TRANSMIT_SID),PdumTxPduId,
   PduInfoPtr);
  if ((Std_ReturnType)E_OK == LddReturnVal)
  #endif /* #if (IPDUM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Get the pointer to Tx In Ipdu */
    LpTxInIpdu = &IpduM_GaaTxInIpdu[PdumTxPduId];
    /* Get the pointer to Multiplexed Tx Ipdu structure */
    LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LpTxInIpdu->ddTxOutIpduId];

    /*
     * Check whether previous transmission is not pending for confirmation
     * or if timeout for confirmation is configured to zero
     */
    if ((((uint16)IPDUM_ZERO) == LpTxOutIpdu->usTimeoutCount) ||
        (IPDUM_FALSE == (*(LpTxOutIpdu->pTxPendingFlag)
         & (LpTxOutIpdu->ucTxPendingMask))))
    {
      /* Check whether Tx In Ipdu can trigger the transmission */
      if(LpTxInIpdu->blTxTriggerState == IPDUM_TRUE)
      {
        if (IPDUM_TRUE == LpTxInIpdu->blTxDynamicPart)
        {
          #if (IPDUM_TX_CONFIRMATION == STD_ON)
          /* Copy the Multiplexed and Transmitted Dynamic Handle Id*/
          IpduM_GaaTxConfrmDynamicHandleId[LpTxInIpdu->ddTxOutIpduId]
            = PdumTxPduId;
          #endif /*#if (IPDUM_TX_CONFIRMATION == STD_ON)*/

          #if ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
          if (IPDUM_TRUE == LpTxOutIpdu->blStaticIpduExist)
          {
            LddPduId = LpTxOutIpdu->ddStaticPduId;
          }
          #endif /*((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE
                   == STD_ON)) */
        }
        #if ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
        else
        {
          /* Get the dynamic id w.r.t JIT bit */
          LddPduId = IpduM_GaaJITDynamicId[LpTxInIpdu->ddTxOutIpduId];
        }
        #endif /*((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_ */

        #if (IPDUM_TX_STATIC_IPDU == STD_ON)
        if (IPDUM_TRUE == LpTxOutIpdu->blStaticIpduExist)
        {
          /* Copy the data into static or dynamic I-PDUs */
          #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
          IpduM_CopySegmentBit(LpTxInIpdu->pSegmentBitField,
            PduInfoPtr->SduDataPtr,LpTxInIpdu->ucNoOfSegmentBitField);
          #else
          /* Copy the data into static I-PDUs buffer */
          IpduM_CopySegmentByte(LpTxInIpdu, PduInfoPtr);
          #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */

          #if (IPDUM_JIT_UPDATE == STD_ON)
          LddReturnVal = IpduM_UpdateJitPart(LddPduId,PduInfoPtr);
          if ((Std_ReturnType)E_OK == LddReturnVal)
          #endif /*#if (IPDUM_JIT_UPDATE == STD_ON) */
          {
            LddReturnVal = PduR_IpduMTransmit(LpTxOutIpdu->ddTxLoPduId,
              LpTxOutIpdu->pPduInfoPtr);
          }
        }
        else
        {
          /*for Dynamic only configuration transmit incoming ipdu as it is*/
          LddReturnVal = PduR_IpduMTransmit(LpTxOutIpdu->ddTxLoPduId,
            PduInfoPtr);
        }
        #else /*(IPDUM_TX_STATIC_IPDU == STD_OFF)  */
        /*for Dynamic only configuration transmit incoming ipdu as it is*/
          LddReturnVal = PduR_IpduMTransmit(LpTxOutIpdu->ddTxLoPduId,
            PduInfoPtr);
        #endif /* (IPDUM_TX_STATIC_IPDU == STD_ON)  */

        #if (IPDUM_TX_CONFIRMATION == STD_ON)
        if ((Std_ReturnType)E_OK == LddReturnVal)
        {
          /* Enter critical area */
          SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA();
          /* Set Timeout counter to timeout value */
          *(LpTxOutIpdu->pTxTimeoutCounter) = LpTxOutIpdu->usTimeoutCount;
          /* Reset pending flag */
          *(LpTxOutIpdu->pTxPendingFlag) |= (LpTxOutIpdu->ucTxPendingMask);
          /* Exit critical area */
          SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA();
        }
        #endif /*#if (IPDUM_TX_CONFIRMATION == STD_ON) */
      }/* End of if(blTxTriggerState == IPDUM_TRUE)**/
      else
      {
        #if ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_OFF))
        /* Copy the data into static or dynamic I-PDUs */
        #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
        IpduM_CopySegmentBit(LpTxInIpdu->pSegmentBitField,
         PduInfoPtr->SduDataPtr, LpTxInIpdu->ucNoOfSegmentBitField);
        #else
        /* Copy the data into static I-PDUs buffer */
        IpduM_CopySegmentByte(LpTxInIpdu, PduInfoPtr);
        #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */

        #if (IPDUM_TX_CONFIRMATION == STD_ON)
        if (IPDUM_TRUE == LpTxInIpdu->blTxDynamicPart)
        {
          /* Copy the Multiplexed and Transmitted Dynamic Handle Id*/
          IpduM_GaaTxConfrmDynamicHandleId[LpTxInIpdu->ddTxOutIpduId]
            = PdumTxPduId;
        }
        #endif /*#if (IPDUM_TX_CONFIRMATION == STD_ON)*/
        LddReturnVal = (Std_ReturnType)E_OK;
        #elif ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
        if (IPDUM_TRUE != IpduM_GaaTxInIpdu[PdumTxPduId].blJitUpdate)
        {
          /* Check whether JIT update is configured to true or not , if not
          store the data*/
          LddReturnVal = IpduM_UpdateJitPart(PdumTxPduId,PduInfoPtr);
        }
        #endif /*((IPDUM_TX_STATIC_IPDU == STD_ON)
              && (IPDUM_JIT_UPDATE == STD_ON)) */
      }
    } /* end of if ((IPDUM_FALSE == (*(LpTxOutIpdu->pTxPendingFlag) */
    else
    {
      /* Load the return value with E_NOT_OK*/
      LddReturnVal = (Std_ReturnType)E_NOT_OK;
    }
  }/* if(LddReturnValue == E_OK)  */
  return (LddReturnVal);
}/* End of IpduM_Transmit( PduIdType *PdumTxPduId, P2CONST(
    PduInfoType, AUTOMATIC, IPDUM_CONST) PduInfoPtr)*/

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (IPDUM_TX_IPDU == STD_ON) */

/*******************************************************************************
** Function Name        : IpduM_TxConfirmation                                **
**                                                                            **
** Service ID           : 0x40                                                **
**                                                                            **
** Description          : This function is called by the lower layer after    **
**                        the I-PDU has been transmitted on the network.      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant for the same PDU-ID. Re-entrant for  **
**                        different PDU-ID.                                   **
**                                                                            **
** Input Parameters     : PduIdType TxPduId                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)    : IpduM_GblStatus,            **
**                                                IpduM_GaaTxInIpdu[],        **
**                                                IpduM_GaaTxOutIpdu[],       **
**                                         IpduM_GaaTxConfrmDynamicHandleId[] **
**                                         IpduM_Max_Tx_Pdu_ID                **
**                                                                            **
**                        Function(s) invoked   : PduR_IpduMTxConfirmation(), **
**                                                Det_ReportError(),          **
**                                                Com_TxConfirmation(),       **
**                        SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA(),       **
**                        SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA()         **
*******************************************************************************/
#if (IPDUM_TX_CONFIRMATION == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, IPDUM_CODE) IpduM_TxConfirmation(PduIdType TxPduId)
{
  P2CONST(IpduM_TxOutIpdu, AUTOMATIC, IPDUM_CONST) LpTxOutIpdu;

  P2CONST(IpduM_TxInIpdu, AUTOMATIC, IPDUM_CONST) LpTxInIpdu;

  /* Local variable to store the index of Array*/
  PduIdType LddTxPduIdIndex;

  /* Local variable to store the index of mapping Array*/
  PduIdType LddTxConfirmMapArrayIndex;
  #if (IPDUM_TX_STATIC_IPDU == STD_ON)
  PduIdType LddTxInPduId;
  #endif

  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)

  /*Local variable for returnvalue*/
  boolean LblReturnValue;

  /* set the return value with IPDUM_TRUE*/
  LblReturnValue = IPDUM_TRUE;

  if (IPDUM_UNINIT == IpduM_GblStatus)
  {
    /* report DET with IPDUM_E_UNINIT*/
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
      (uint8)IPDUM_TXCONFIRMATION_SID, (uint8)IPDUM_E_UNINIT);
    LblReturnValue = IPDUM_FALSE;
  }
  else
  {
    if (TxPduId > ((PduIdType)IpduM_Max_Tx_Pdu_ID))
    {
      /* report DET with IPDUM_E_PARAM*/
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        (uint8)IPDUM_TXCONFIRMATION_SID, (uint8)IPDUM_E_PARAM);
      LblReturnValue = IPDUM_FALSE;
    }
  }

  if (IPDUM_TRUE == LblReturnValue)
  #endif /* #if (IPDUM_DEV_ERROR_DETECT == STD_ON) */
  {
    /* Static part confirmation */
    /* Get the index for Txpathway for which confirmation is required */
    LddTxConfirmMapArrayIndex = IpduM_GaaTxConfirmMapArray[TxPduId];
    LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LddTxConfirmMapArrayIndex];

    /* Check whether confirmation is pending*/
    if ((*(LpTxOutIpdu->pTxPendingFlag) & (LpTxOutIpdu->ucTxPendingMask)) ==
        (LpTxOutIpdu->ucTxPendingMask))
    {
      #if (IPDUM_TX_STATIC_IPDU == STD_ON)
      if(LpTxOutIpdu->blStaticIpduExist == IPDUM_TRUE)
      { /* Get the static handle id */
        LddTxInPduId = IpduM_GaaTxOutIpdu[LddTxConfirmMapArrayIndex].
                                                                  ddStaticPduId;
        LpTxInIpdu = &IpduM_GaaTxInIpdu[LddTxInPduId];
        /* Check whether confirmation is required for static part*/
        if (IPDUM_TRUE == LpTxInIpdu->blTxConfirmRequired)
        {
          /* Generate Tx cofirm for static part */
          #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)

          /* TxPduId should be from COM layer */
          Com_TxConfirmation(LpTxInIpdu->ddTxUpIpduId);
          #else
          PduR_IpduMTxConfirmation(LpTxInIpdu->ddTxUpIpduId);
          #endif /* #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
        }/* End of if(IpduM_GaaTxInIpdu[TxPduId].blTxConfirmRequired
                    == IPDUM_TRUE) */
      }
      #endif /* End of if (IPDUM_TX_STATIC_IPDU == STD_ON) */
      LddTxPduIdIndex =
        IpduM_GaaTxConfrmDynamicHandleId[LddTxConfirmMapArrayIndex];
      LpTxInIpdu = &IpduM_GaaTxInIpdu[LddTxPduIdIndex];
      /* Check whether confirmation is required for dynamic part */
      if (IPDUM_TRUE == LpTxInIpdu->blTxConfirmRequired)
      {
        /* Generate Tx cofirm for dynamic part */
        #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)

        /* TxPduId should be from COM layer */
        Com_TxConfirmation(LpTxInIpdu->ddTxUpIpduId);
        #else
        PduR_IpduMTxConfirmation(LpTxInIpdu->ddTxUpIpduId);
        #endif /* #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
      }/* End of if(IpduM_GaaTxInIpdu[LddTxPduIdIndex].blTxConfirmRequired
                    == IPDUM_TRUE) */
      /* Enter critical area */
      SchM_Enter_IpduM_TX_STATUS_PROTECTION_AREA();
      /* Reset pending flag */
      *(LpTxOutIpdu->pTxPendingFlag) &=
                                      (uint8)(~(LpTxOutIpdu->ucTxPendingMask));
      /* Exit critical area */
      SchM_Exit_IpduM_TX_STATUS_PROTECTION_AREA();
    }/* End of if((*(LpTxOutIpdu->pTxPendingFlag) & *(LpTxOutIpdu->
        ucTxPendingMask)) == */
  }/* End of IpduM_TxConfirmation(PduIdType, TxPduId) */
}
#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (IPDUM_TX_CONFIRMATION == STD_ON) */

/*******************************************************************************
** Function Name        : IpduM_TriggerTransmit                               **
**                                                                            **
** Service ID           : 0x41                                                **
**                                                                            **
** Description          : This function is called by the lower layer when     **
**                        an I-PDU shall be transmitted.                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant for the same PDU-ID. Re-entrant for  **
**                        different PDU-ID.                                   **
**                                                                            **
** Input Parameters     : PduIdType TxPduId,  PduInfoType PduInfoPtr          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):IpduM_GblStatus,                 **
**                                           IpduM_GaaTxOutIpdu[],            **
**                                           IpduM_GaaTxInIpdu[],             **
**                                           IpduM_GaaJITDynamicId[]          **
**                                           IpduM_Max_Tx_Pdu_ID              **
**                                                                            **
**                        Function(s) invoked:                                **
**                                            Com_TriggerTransmit,            **
**                                            PduR_IpduMTriggerTransmit,      **
**                                            IpduM_CopySegmentBit,           **
**                                            IpduM_CopySegmentByte           **
**                        SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA(),       **
**                        SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA(),        **
**                                            Det_ReportError                 **
*******************************************************************************/
#if (IPDUM_TX_IPDU == STD_ON)
#define IPDUM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, IPDUM_CODE) IpduM_TriggerTransmit(
  PduIdType TxPduId, P2VAR(PduInfoType, AUTOMATIC,
    IPDUM_VAR) PduInfoPtr)
{
  P2CONST(IpduM_TxOutIpdu, AUTOMATIC, IPDUM_CONST) LpTxOutIpdu;
  P2VAR(uint8, AUTOMATIC, IPDUM_VAR) LpSduPtr;

  PduLengthType LddSduLength;
  /* Local variable to store the index of mapping Array*/
  PduIdType LddTxConfirmMapArrayIndex;
  /*Local variable for returnvalue*/
  Std_ReturnType LddReturnValue;  

  #if (IPDUM_JIT_UPDATE == STD_ON)
  P2CONST(IpduM_TxInIpdu, AUTOMATIC, IPDUM_CONST) LpTxUpdtdPrtInIpdu;

  /*Local structure of PduInfoType */
  PduInfoType LddDerivedPdu;

  /* Local variable ptr to PduInfoPtr */
  P2VAR(PduInfoType, AUTOMATIC, IPDUM_VAR) LpPduInfoPtr;
  PduIdType LddId;
  uint8 LaaSduData[IPDUM_MAX_PDU_LENGTH];

  LpPduInfoPtr = &LddDerivedPdu;
  LpPduInfoPtr->SduDataPtr = &LaaSduData[IPDUM_ZERO];
  #endif /*#if(IPDUM_JIT_UPDATE == STD_ON)*/
  LddReturnValue = (Std_ReturnType)E_OK;
  #if (IPDUM_DEV_ERROR_DETECT == STD_ON)

  if (IPDUM_UNINIT == IpduM_GblStatus)
  {
    /* report DET with IPDUM_E_UNINIT*/
    (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
      (uint8)IPDUM_TRIGGERTRANSMIT_SID, (uint8)IPDUM_E_UNINIT);
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }                               /* End of if(IpduM_GblStatus == IPDUM_UNINIT)
                                   **/
  else
  {
    /* check TxPduId is greater than maximum TxTrigPduId*/
    if (TxPduId > ((PduIdType)IpduM_Max_Tx_Pdu_ID))
    {
      /* report DET with IPDUM_E_PARAM*/
      (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
        (uint8)IPDUM_TRIGGERTRANSMIT_SID, (uint8)IPDUM_E_PARAM);
      LddReturnValue = (Std_ReturnType)E_NOT_OK;
    }                             /* End of if(TxPduId >
                                   *((PduIdType)IpduM_Max_Tx_Pdu_ID)) */
    else
    {
      if ( NULL_PTR == PduInfoPtr )
      {
        /* report DET with IPDUM_E_PARAM*/
        (void)Det_ReportError((uint16)IPDUM_MODULE_ID, (uint8)IPDUM_INSTANCE_ID,
          (uint8)IPDUM_TRIGGERTRANSMIT_SID, (uint8)IPDUM_E_PARAM_POINTER);
        LddReturnValue = (Std_ReturnType)E_NOT_OK;
      }                           /* End of if((TxPduId ==
                                   * IPDUM_INVALID) || (PduInfoPtr ==
                                   * NULL_PTR)) */
      else
      {
      /* Check if SduDataPtr is NULL Pointer*/
       if (NULL_PTR == PduInfoPtr->SduDataPtr)
       {
         (void)Det_ReportError((uint16)IPDUM_MODULE_ID,(uint8)IPDUM_INSTANCE_ID,
           (uint8)IPDUM_TRIGGERTRANSMIT_SID, (uint8)IPDUM_E_PARAM_POINTER);
        LddReturnValue = (Std_ReturnType)E_NOT_OK;
       }
      }                           /* End of else */
    }                             /* End of else */
  }                               /* End of else */
  #else /* #if (IPDUM_DEV_ERROR_DETECT == STD_OFF) */

  if ((NULL_PTR == PduInfoPtr) || (NULL_PTR == PduInfoPtr->SduDataPtr))
  {
    LddReturnValue = (Std_ReturnType)E_NOT_OK;
  }
  #endif /* #if (IPDUM_DEV_ERROR_DETECT == STD_ON) */
  if (((Std_ReturnType)E_OK) == LddReturnValue)
  {
    /* Get the index for Txpathway */
    LddTxConfirmMapArrayIndex = IpduM_GaaTxConfirmMapArray[TxPduId];
    /* Get the pointer to Tx Ipdu structure */
    LpTxOutIpdu = &IpduM_GaaTxOutIpdu[LddTxConfirmMapArrayIndex];
    #if ((IPDUM_TX_STATIC_IPDU == STD_ON) && (IPDUM_JIT_UPDATE == STD_ON))
    /* Update the Static part if JIT is ON */
    if(LpTxOutIpdu->blStaticIpduExist == IPDUM_TRUE)
    {
      /* Get the static Ipdu id */
      LddId = LpTxOutIpdu->ddStaticPduId;
      /* Check whether JIT is configured to true*/
      if (IPDUM_TRUE == IpduM_GaaTxInIpdu[LddId].blJitUpdate)
      {
        /* Get the address of the updated part */
        LpTxUpdtdPrtInIpdu = &IpduM_GaaTxInIpdu[LddId];

        /* Invoke the trigger transmit function and get the data in
           local buffer*/
        #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
        Com_TriggerTransmit(IpduM_GaaTxInIpdu[LddId].ddTxUpIpduId,
          LpPduInfoPtr);
        #else
        PduR_IpduMTriggerTransmit(IpduM_GaaTxInIpdu[LddId].ddTxUpIpduId,
          LpPduInfoPtr);
        #endif /*#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */
        /* copy updated data */
        #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
        IpduM_CopySegmentBit(LpTxUpdtdPrtInIpdu->pSegmentBitField,
          LpPduInfoPtr->SduDataPtr, LpTxUpdtdPrtInIpdu->ucNoOfSegmentBitField);
        #else
        IpduM_CopySegmentByte(LpTxUpdtdPrtInIpdu, LpPduInfoPtr);
        #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */
      }/* End of if(IpduM_GaaTxInIpdu[LddId].blJitUpdate == IPDUM_TRUE) */
    }/* End of if(LpTxOutIpdu->blStaticIpduExist == IPDUM_TRUE) */
    #endif /* #if((IPDUM_TX_STATIC_IPDU == STD_ON) &&
                     (IPDUM_JIT_UPDATE == STD_ON)) */
    #if (IPDUM_JIT_UPDATE == STD_ON)
    LpPduInfoPtr = &LddDerivedPdu;

    /* Get the latest JIT dynamic id for TxOutIpdu sent */
    LddId = IpduM_GaaJITDynamicId[TxPduId];

    /* Update the dynamic part if JIT is ON */
    if (IPDUM_TRUE == IpduM_GaaTxInIpdu[LddId].blJitUpdate)
    {
      /* Get the address of the updated part */
      LpTxUpdtdPrtInIpdu = &IpduM_GaaTxInIpdu[LddId];

      /* Invoke the trigger transmit function and get the data in local buffer*/
      #if (IPDUM_COM_SUPPORT_DIRECT == STD_ON)
      Com_TriggerTransmit(IpduM_GaaTxInIpdu[LddId].ddTxUpIpduId, LpPduInfoPtr);
      #else
      PduR_IpduMTriggerTransmit(IpduM_GaaTxInIpdu[LddId].ddTxUpIpduId,
        LpPduInfoPtr);
      #endif /*#if (IPDUM_COM_SUPPORT_DIRECT == STD_ON) */

      /* copy updated data */
      #if (IPDUM_SEGMENT_BITFIELD == STD_ON)
      IpduM_CopySegmentBit(LpTxUpdtdPrtInIpdu->pSegmentBitField,
        LpPduInfoPtr->SduDataPtr, LpTxUpdtdPrtInIpdu->ucNoOfSegmentBitField);
      #else
      IpduM_CopySegmentByte(LpTxUpdtdPrtInIpdu, LpPduInfoPtr);
      #endif /* #if (IPDUM_SEGMENT_BITFIELD == STD_ON) */
    }/* End of if(IpduM_GaaTxInIpdu[LddId].blJitUpdate == IPDUM_TRUE) */
    #endif /* (IPDUM_JIT_UPDATE == STD_ON) */
    /* Get the pointer to IpduM buffer */
    LpSduPtr = LpTxOutIpdu->pPduInfoPtr->SduDataPtr;

    /* Get the length */
    LddSduLength = LpTxOutIpdu->pPduInfoPtr->SduLength;
    PduInfoPtr->SduLength = LddSduLength;
    
    /* Loop to copy the data from IpduMBuffer to lower layer buffer */
    do
    {
      /* Enter critical area */
      SchM_Enter_IpduM_DEST_DATA_PROTECTION_AREA();
      
      /* Copy the data into SduPtr */
      *(PduInfoPtr->SduDataPtr) = *LpSduPtr;
      
      /* Exit critical area */
      SchM_Exit_IpduM_DEST_DATA_PROTECTION_AREA();

      /* Increment the SduPtr by one */

      /*   MISRA Rule         : 17.4
       *   Message            : Performing pointer arithmetic
       *   Reason             : Increment operator not used
       *                        to achieve better throughput.
       *   Verification       : However, part of the code
       *                        is verified manually and
       *                        it is not having any impact.
       */
      ++(PduInfoPtr->SduDataPtr);

      /* Increment the local pointer by one */

      /*   MISRA Rule         : 17.4
       *   Message            : Performing pointer arithmetic
       *   Reason             : Increment operator not used
       *                        to achieve better throughput.
       *   Verification       : However, part of the code
       *                        is verified manually and
       *                        it is not having any impact.
       */
      ++LpSduPtr;

      /* Decrement length count by one */
      --LddSduLength;
    } while (((uint16)IPDUM_ZERO) != LddSduLength);

  }                       /* End of if(LddReturnValue == ((Std_ReturnType)E_OK))
                          **/
  return (LddReturnValue);
}                                 /* End of IpduM_TriggerTransmit( */

#define IPDUM_STOP_SEC_CODE
#include "MemMap.h"
#endif /* #if (IPDUM_TX_IPDU == STD_ON) */

/* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Not a defect, Decrement and Increment operator is used to achieve better throughput */
/* polyspace:end<RTE: NIV : Not a defect : No Action Planned > initialized variable */
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > configured memory access index */
/* polyspace:end<MISRA-C3:18.1:Not a defect:Justify with annotations> Pointer is not outside its bounds - Pointer is generated by Generator*/
/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */

#endif /* #if (IPDUM_ENABLE == STD_ON) */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

