/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CanIf_Tx.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CanIf                                                 **
**                                                                            **
**  PURPOSE   : Provision of Transmit and Queue Functionality                 **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 3.2.0    17-Jan-2025    Jh.Yang   #40935, #46546, #49837, #50150           **
** 3.1.2    31-Oct-2023    Jh.Yang   #43389                                   **
** 3.1.1    08-Sep-2023    Jh.Yang   #42630                                   **
** 3.1.0    21-Jul-2023    Jh.Yang   #36031, #40215, #41297, #41542, #41572   **
                                     #41669, #41670                           **
** 3.0.6    26-May-2023    Mu.Kim    #38439                                   **
** 3.0.5    12-Aug-2022    Jh.Yang   #36772                                   **
** 3.0.3    15-Mar-2022    Sj.Kim    #34766                                   **
** 3.0.2    21-Feb-2022    Sj.Kim    #34443                                   **
** 3.0.1    28-Dec-2021    Sj.Kim    #33378                                   **
** 3.0.0    08-Nov-2021    Sj.Kim    #32882                                   **
** 2.7.3    20-Jan-2021    Sj.Kim    #27560                                   **
** 2.7.2    12-Jan-2021    Sj.Kim    #27560                                   **
** 2.7.1    25-Nov-2020    Sj.Kim    #26002                                   **
** 2.7.0    07-Oct-2020    Sj.Kim    #25877                                   **
** 2.6.2    15-May-2020    Sj.Kim    #23352, #21882, #23360                   **
** 2.6.1    17-Dec-2019    Js Lim    #20405                                   **
** 2.6.0    22-Aug-2019    Js.Lim    #18384                                   **
** 2.5.7    26-Dec-2018    Js.Lim    #14124, #15285                           **
** 2.5.6    10-May-2018    Js.Lim    #12562, #12222                           **
** 2.5.5    10-Jan-2018    Js.Lim    #10456                                   **
** 2.5.4    11-Oct-2017    C.Kim     #10240                                   **
** 2.5.3    31-Aug-2017    Js.Lim    #9889, #9618                             **
** 2.5.1    23-Mar-2017    Js.Lim    #7042                                    **
** 2.5.0    06-Dec-2016    Js.Lim    #7077                                    **
** 2.4.3    29-Nov-2016    Js.Lim    #6744                                    **
** 2.4.2    12-Aug-2016    Kt.Kim    #5739                                    **
** 2.4.1    13-Jun-2016    Kt.Kim    #5139                                    **
** 2.4.0    11-Mar-2016    Kt.Kim    #4386                                    **
** 2.3.9    05-Mar-2016    Kt.Kim    #4317                                    **
** 2.3.8    05-Jan-2016    Kt.Kim    #3813                                    **
** 2.3.7    14-Dec-2015    Kt.Kim    Cleared violations                       **
**                                   against MISRA rule 10.1/14.2             **
** 2.3.6    13-Jun-2015    Kt.Kim    #2724                                    **
** 2.3.5    16-Mar-2015    Kt.Kim    #2270                                    **
** 2.3.3    21-Aug-2014    Kt.Kim    #1191                                    **
** 2.2.0    30-May-2013    Kt.Kim    Lib-Build Support                        **
** 2.1.0    29-May-2013    Kt.Kim    OsekNm Support                           **
** 1.0.0    28-Mar-2013    Kt.Kim    Initial version                          **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanIf.h"               /* Module header file */
#include "CanIf_Ram.h"           /* Module RAM header file */
#include "CanIf_PCTypes.h"       /* Pre-compile time header file */
#include "CanIf_Tx.h"            /* Transmit header file */
#include "CanIf_TxConfirm.h"     /* Tx Confirmation header file */
#include "CanIf_Cbk.h"           /* Call-back CanIf header file */
#if (STD_ON == CANIF_PDUR_CALLBACK)
#include "PduR_CanIf.h"          /* Call-back PduR header file */
#endif
#if (STD_ON == CANIF_CANTP_CALLBACK)
#include "CanTp_Cbk.h"           /* Call-back CanTp header file */
#endif
#if (STD_ON == CANIF_CANNM_CALLBACK)
#include "CanNm_Cbk.h"           /* Call-back CanNm header file */
#endif
#if (STD_ON == CANIF_OSEKNM_CALLBACK)
#include "OsekNm_Cbk.h"           /* Call-back OsekNm header file */
#endif
#include "SchM_CanIf.h"          /* SchM CanIf Header file */
#if  (STD_ON == CANIF_DEV_ERROR_DETECT)
#include "CanIf_Error.h"         /* Det File Check */
#endif
#if (STD_ON == CANIF_TX_XCP_CALLBACK)
#include "Xcp_Cbk.h"             /* Call-back XCP header file */
#endif
#if (STD_ON == CANIF_TX_J1939TP_CALLBACK)
#include "J1939Tp_Cbk.h"         /* Call-back J1939Tp header file */
#endif
#include "CanIf_UserInc.h"       /* User included header file */
#include "CanIf_Can.h"           /* CAN Driver Module Header File */
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANIF_TX_C_AR_RELEASE_MAJOR_VERSION    4
#define CANIF_TX_C_AR_RELEASE_MINOR_VERSION    0
#define CANIF_TX_C_AR_RELEASE_REVISION_VERSION 3

/* File version information */
#define CANIF_TX_C_SW_MAJOR_VERSION    3
#define CANIF_TX_C_SW_MINOR_VERSION    2

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (CANIF_TX_AR_RELEASE_MAJOR_VERSION != \
  CANIF_TX_C_AR_RELEASE_MAJOR_VERSION)
  #error "CANIF_TX.c : Mismatch in Specification Major Version"
#endif
#if (CANIF_TX_AR_RELEASE_MINOR_VERSION != \
  CANIF_TX_C_AR_RELEASE_MINOR_VERSION)
  #error "CANIF_TX.c : Mismatch in Specification Minor Version"
#endif
#if (CANIF_TX_AR_RELEASE_REVISION_VERSION != \
  CANIF_TX_C_AR_RELEASE_REVISION_VERSION)
  #error "CANIF_TX.c : Mismatch in Specification Revision Version"
#endif
#if (CANIF_TX_SW_MAJOR_VERSION != CANIF_TX_C_SW_MAJOR_VERSION)
  #error "CANIF_TX.c : Mismatch in Software Major Version"
#endif
#if (CANIF_TX_SW_MINOR_VERSION != CANIF_TX_C_SW_MINOR_VERSION)
  #error "CANIF_TX.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#if ((STD_ON == CANIF_TX_LPDU) && (STD_OFF == CANIF_AUTOEVER_AUTOSAR_CANCELLATION_USED) && (STD_ON == CANIF_BASIC_CAN_TXPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(CanIf_TxQueueType, CANIF_CODE) CanIf_CheckQueueStatus (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_TxQueueHandling (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer,
                     VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                          P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu,
                          VAR(Can_HwHandleType, CANIF_VAR) LddHth,
                          P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

#else
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                          VAR(Can_HwHandleType, CANIF_VAR) LddHth,
                          P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if ((STD_ON == CANIF_DEV_ERROR_DETECT) && (STD_ON == CANIF_TX_LPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_DETTransmit (
                       VAR(PduIdType, CANIF_VAR) CanTxPduId,
                       P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_SETDYNAMICTXID_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_ClearTxBuffer (
                    VAR(CanIf_TxPduIdType, CANIF_VAR) LddTxPduId,
                    P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, CANIF_CODE) CanIf_TxTruncation(
    #if ((STD_ON == CANIF_TX_TRUNCATION_SUPPORT) || (STD_ON == CANIF_CANFD_SUPPORT))
    VAR(PduIdType, CANIF_VAR) CanTxPduId,
    #endif
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr);
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_Transmit                                      **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CanTxPduId, PduInfoPtr                              **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GblCanIfStatus,           **
**                                            CanIf_GaaTxLpdu,                **
**                                            CanIf_GaaController             **
**                        Function(s) invoked:CanIf_ClearTxBuffer,            **
**                                            CanIf_TxQueueHandling,          **
**                                            Det_ReportError,                **
**                                            CanIf_StoreLpduInQueue,         **
**                                            CanIf_TxNotification,           **
**                                            CanIf_CanWriteService           **
*******************************************************************************/
#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_Transmit (
                   VAR(PduIdType, CANIF_VAR) CanTxPduId,
                   P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr)
{
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu;
  P2VAR(CanIf_Controller, AUTOMATIC, CANIF_VAR) LpController;
  VAR(Can_PduType, CANIF_VAR) LddCanPduInfo;
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  VAR(Can_ReturnType, CANIF_VAR) LenCanReturn;
  VAR(uint8, CANIF_VAR) LucTruncationFlag;
  #if (STD_ON == CANIF_BASIC_CAN_TXPDU)
  VAR(uint8, CANIF_VAR) LucHthType;
  #endif
  VAR(Can_HwHandleType, CANIF_VAR) LddHthIdOrBufferId;
  VAR(uint8, CANIF_VAR) LucTxStatus;
  P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer;
  VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId;
  VAR(uint16, CANIF_VAR) LddTxQueueIndex;
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxQueue;
  VAR(uint8, CANIF_VAR) LucCount;
  /* #5139 */
  #if (STD_ON == CANIF_META_DATA_SUPPORT)
  #if (STD_ON == CANIF_SETDYNAMICTXID_API)
  uint32 LulCanId;
  uint32 LulTxCanIdMask;
  uint32 Lulpriority;
  LulCanId = CANIF_ZERO;
  #endif
  memset(&LddCanPduInfo, CANIF_ZERO, sizeof(Can_PduType));
  #endif
  #if (STD_OFF == CANIF_DEV_ERROR_DETECT)
  LenStdRetVal = E_OK;
  #else
  /* Invoke the CanIf_DETTransmit to check the errors in the parameters and
  report to DET */
  LenStdRetVal = CanIf_DETTransmit (CanTxPduId, PduInfoPtr);
  #endif
  if ((uint8)E_OK == LenStdRetVal)
  {
    #if ((STD_ON == CANIF_TX_TRUNCATION_SUPPORT) || (STD_ON == CANIF_CANFD_SUPPORT))
    LucTruncationFlag = CanIf_TxTruncation(CanTxPduId, PduInfoPtr);
    #else
    LucTruncationFlag = CanIf_TxTruncation(PduInfoPtr);
    #endif
    if ((uint8)CANIF_TWO == LucTruncationFlag)
    {
      LenStdRetVal = (uint8)E_NOT_OK;
    }
    if ((uint8)E_OK == LenStdRetVal)
    {
      /* Get the pointer to Tx Lpdu */
      #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
      LpTxLpdu = &CanIf_GaaTxLpduSelect[CanTxPduId];
      #else
      LpTxLpdu = &CanIf_GaaTxLpdu[CanTxPduId];
      #endif
      #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
      /* Get the pointer to controller */
      /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
      LpController = &CanIf_GaaController[LpTxLpdu->ucControllerId];
      #else
      LpController = &CanIf_GaaController[CANIF_ZERO];
      #endif
      /* get the Tx status into local variable */
      /* polyspace<RTE: IDP : Not a defect : No Action Planned >
        Its boundary is pre-defined */
      LucTxStatus = ((LpController->ucTxStatus) & (CANIF_TX_STATUS_MASK));

      /*Is any DET error is detected*/
      if (
      #if (STD_ON == CANIF_CANCM_SUPPORT)
          (LpController->ucBatVolStatus == CANIF_TX_BAT_NORMAL) &&
      #endif
          ((LucTxStatus == CANIF_TX_ENABLED) ||
          (LucTxStatus == CANIF_TX_OFFLINE_ACTIVE)))
      {
        /* Check if current status is CANIF_TX_OFFLINE_ACTIVE */
        /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
        if (CANIF_TX_OFFLINE_ACTIVE == LucTxStatus)
        {
          /* Invoke CanIf_TxNotification */
          CanIf_TxNotification(LpTxLpdu);
          /* return status as E_OK */

        }/*if (CANIF_TX_OFFLINE_ACTIVE == LucTxStatus)*/
        else/* Status is active */
        {
          #if (STD_ON == CANIF_PN_SUPPORT)
          /* CANIF750 */
          /* Check whether Partial Networking status is enabled and PnFilterPdu of Tx Pdu is disabled */
          if (((uint8)CANIF_TX_PNENABLED == ((LpController->ucTxStatus) &
              ((uint8)CANIF_TX_PNENABLED))) &&
              ((uint8)CANIF_TX_PDU_PN_ENABLED != ((LpTxLpdu->ucHTHTypeOrTXPN) &
              (uint8)CANIF_TX_PDU_PN_ENABLED)))
          {
            /* Set the return value to E_NOT_OK*/
            LenStdRetVal = (uint8)E_NOT_OK;
          }
          else
          #endif
          {
            /* Prepare message to transmit L-PDU to CAN Driver */
            #if (STD_ON == CANIF_SETDYNAMICTXID_API)
            /* Is CanId index value is CANIF_INVALID_DYNCANID in rxpdu structure*/
            if (CANIF_INVALID_DYNCANID != LpTxLpdu->ddDynCanIdIndex)
            {
              SchM_Enter_CanIf_TX_DYNCANID_PROTECTION();
              /* #5139 */
              #if (STD_ON == CANIF_META_DATA_SUPPORT)
              /* get the Tx mask into local variable */
              LulTxCanIdMask = LpTxLpdu->ddCanIdMask;
              switch (LpTxLpdu->ucMetaDataLength)
              {
                /* if meta data length is one */
                case CANIF_ONE:
                  LulCanId = PduInfoPtr->SduDataPtr[CANIF_ZERO];
                  LulCanId = LulCanId | LulTxCanIdMask;
                  break;

                /* if meta data length is two */
                case CANIF_TWO:
                  LulCanId = PduInfoPtr->SduDataPtr[CANIF_ZERO];
                  LulCanId  = LulCanId  << CANIF_EIGHT;
                  LulCanId = (LulCanId | PduInfoPtr->SduDataPtr[CANIF_ONE]);
                  LulCanId = LulCanId | LulTxCanIdMask;
                  break;

                /* if meta data length is four */
                case CANIF_FOUR:
                  LulCanId = PduInfoPtr->SduDataPtr[CANIF_ZERO];
                  LulCanId  = LulCanId  << CANIF_EIGHT;
                  LulCanId = (LulCanId | PduInfoPtr->SduDataPtr[CANIF_ONE]);
                  LulCanId = LulCanId << CANIF_EIGHT;
                  LulCanId = (LulCanId | PduInfoPtr->SduDataPtr[CANIF_TWO]);
                  LulCanId = LulCanId << CANIF_EIGHT;
                  Lulpriority = PduInfoPtr->SduDataPtr[CANIF_THREE];
                  LulCanId = LulCanId | Lulpriority;
                  LulCanId = LulCanId | CANIF_EXTENDED_BIT_SET;
                  break;

                default:
                  /*Do Nothing*/
                  break;
              }
              CanIf_GddCanId[LpTxLpdu->ddDynCanIdIndex] = LulCanId;
              /* polyspace +1 MISRA-C3:18.4 [Not a defect: Justified] "Decrement and Increment operator is used to achieve better throughput" */
              LddCanPduInfo.sdu = PduInfoPtr->SduDataPtr +
                                                      LpTxLpdu->ucMetaDataLength;
              #else
              /* copy the data pointer  */
              /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
              LddCanPduInfo.sdu = PduInfoPtr->SduDataPtr;
              #endif

              /* Read the CAN ID from the RAM area */
              LddCanPduInfo.id = CanIf_GddCanId[LpTxLpdu->ddDynCanIdIndex];
              SchM_Exit_CanIf_TX_DYNCANID_PROTECTION();
            }
            else
            #endif
            {
              /* Read the CAN ID from ROM area */
              LddCanPduInfo.id = (LpTxLpdu->ddCanId);
              /* copy the data pointer  */
              /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
              LddCanPduInfo.sdu = PduInfoPtr->SduDataPtr;
            }
            /* copy the length */
            #if (STD_ON == CANIF_TX_TRUNCATION_SUPPORT)
            if (CANIF_ONE == LucTruncationFlag)
            {
              LddCanPduInfo.length = (uint8)LpTxLpdu->ucTxDlc;
            }
            else
            #endif
            {
              LddCanPduInfo.length = (uint8)PduInfoPtr->SduLength;
            }
            /* copy the CanTxPduId handle id */
            LddCanPduInfo.swPduHandle = CanTxPduId;
            /* Get the index to HthId or Buffer Index */
            LddHthIdOrBufferId = LpTxLpdu->ddHthIdorBufferId;
            #if (STD_OFF == CANIF_FULL_CAN_TXPDU)
            /* Set the standard Return Type = E_NOT_OK */
            LenStdRetVal = (uint8)E_NOT_OK;
            #endif
            #if (STD_ON == CANIF_FULL_CAN_TXPDU)
            /* Get the HthType as FULL or BASIC Can*/
            #if (STD_ON == CANIF_BASIC_CAN_TXPDU)
            LucHthType = (uint8)(CANIF_HTHTYPE_MASK & LpTxLpdu->ucHTHTypeOrTXPN);
            /* Check if TXPDU is FULL CAN */
            if (CANIF_FULL_CAN == LucHthType)
            #endif
            {
              #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
              /* Call Can_Write() */
              LenCanReturn = CanIf_CanWriteService(LpTxLpdu, LddHthIdOrBufferId, &LddCanPduInfo);
              #else
              /* Call Can_Write() */
              LenCanReturn = CanIf_CanWriteService(LddHthIdOrBufferId, &LddCanPduInfo);
              #endif
              /* Check if TxPDU is transmitted on bus */
              if (CAN_OK == LenCanReturn)
              {
                /* Return E_OK */
                LenStdRetVal = (uint8)E_OK;
              }
              else
              {
                LenStdRetVal = (uint8)E_NOT_OK;
              }
            }/*if (CANIF_FULL_CAN == LucHthType)*/

            #if (STD_ON == CANIF_BASIC_CAN_TXPDU)
            else
            #endif
            #endif
            {
              #if (STD_ON == CANIF_BASIC_CAN_TXPDU)
              /* Get the mapping index to pTxPduToQueueMapping array */
              if (CanIf_GddTxBuffCon.pBasicTxPduIndex != NULL_PTR)
              {
                LddTxQueueIndex = CanIf_GddTxBuffCon.pBasicTxPduIndex[CanTxPduId];
                /* Get the pointer to TX buffer */
                LpTxBuffer = &(CanIf_GddTxBuffCon.pTxBuffer[LddHthIdOrBufferId]);
                /*Get the tx queue Id from the CanTxPduId*/
                /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
                LddTxQueueId = CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex];
                /* Enable interrupts to protect Tx DATA */
                SchM_Enter_CanIf_TX_QUEUE_PROTECTION();
                
                /* Check if queue is free */
                if (CANIF_INVALID_TXQUEUE == LddTxQueueId)
                {
                  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
                  /* Call Can_Write() */
                  LenCanReturn = CanIf_CanWriteService(LpTxLpdu, LpTxBuffer->ddHthId, &LddCanPduInfo);
                  #else
                  /* Call Can_Write() */
                  /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
                  LenCanReturn = CanIf_CanWriteService(LpTxBuffer->ddHthId, &LddCanPduInfo);
                  #endif
                  /* Check if TxPDU is transmitted on bus */
                  if (CAN_OK == LenCanReturn)
                  {
                    /* Return E_OK */
                    LenStdRetVal = (uint8)E_OK;
                  }
                  else
                  {
                    #if (STD_ON == CANIF_CTRLDRV_TX_CANCELLATION)
                    #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
                    /* Call Can_Write() */
                    LenCanReturn = CanIf_CanWriteService(LpTxLpdu, LpTxBuffer->ddHthId, &LddCanPduInfo);
                    #else  /* (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT) */
                    /* Call Can_Write() */
                    LenCanReturn = CanIf_CanWriteService(LpTxBuffer->ddHthId, &LddCanPduInfo);
                    #endif /* (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT) */
                    if (CAN_OK == LenCanReturn)
                    {
                      LenStdRetVal = (uint8)E_OK;
                    }
                    else
                    {
                      LenStdRetVal = (uint8)E_NOT_OK;
                    }
                    #else
                    LenStdRetVal = (uint8)E_NOT_OK;
                    #endif
                  }
                } /*if (CANIF_INVALID_TXQUEUE == LddTxQueueId)*/
                #if (STD_ON == CANIF_SETDYNAMICTXID_API)
                /* Check whether dynamic ID has been changed after Tx request */
                /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
                else if (CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].ddCanId != LddCanPduInfo.id)
                {
                  if (CANIF_ZERO != CanIf_GddPrecompOpt.ddNumOfTxBuffer)
                  {
                    /* Flush data from Tx Queue */
                    CanIf_ClearTxBuffer(CanTxPduId, LpTxBuffer);
                    LddTxQueueId = CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex];
                  }
                  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
                  /* Call Can_Write() */
                  LenCanReturn = CanIf_CanWriteService(LpTxLpdu, LpTxBuffer->ddHthId, &LddCanPduInfo);
                  #else
                  /* Call Can_Write() */
                  LenCanReturn = CanIf_CanWriteService(LpTxBuffer->ddHthId, &LddCanPduInfo);
                  #endif
                  if (CAN_OK == LenCanReturn)
                  {
                    /* Return E_OK */
                    LenStdRetVal = (uint8)E_OK;
                  }
                  else
                  {
                    LenStdRetVal = (uint8)E_NOT_OK;
                  }
                }
                #endif
                else
                {
                  #if (STD_ON == CANIF_TX_BUFFERING)
                  {
                    /* Set CAN return value to busy */
                    LenCanReturn = CAN_BUSY;
                  }
                  #endif
                }
                
                #if (STD_ON == CANIF_TX_BUFFERING)
                {
                  /* Check if can returns busy */
                  if (CAN_BUSY == LenCanReturn)
                  {
                    /* Check if queue is available */
                    if (CANIF_INVALID_TXQUEUE == LddTxQueueId)
                    {
                      /* Check the tx queue status to store the data */
                      LddTxQueueId = CanIf_CheckQueueStatus(LpTxBuffer);
                      if (CANIF_INVALID_TXQUEUE != LddTxQueueId)
                      {
                        CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex] =
                            (CanIf_TxPduIdType)LddTxQueueId;
                        /* Store the pdu in the queue */
                        /* polyspace +2 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Genderated array index in range" */
                        /* polyspace +1 RTE:NIV [Not a defect:Justified] "Initialized Variable" */
                        LpTxQueue = &(CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId]);
                        LpTxQueue->ddTxLPduId = LddCanPduInfo.swPduHandle;
                        #if (STD_ON == CANIF_OPTIMIZE_QUEUE_BUFFER_SIZE)
                        if (LddCanPduInfo.length > LpTxBuffer->ucQueueBufferSize)
                        {
                          LucCount = LpTxBuffer->ucQueueBufferSize;
                        }
                        else
                        #endif
                        {
                          LucCount = LddCanPduInfo.length;
                        }
                        LpTxQueue->ucDlc = LucCount;
                        LpTxQueue->ddCanId = LddCanPduInfo.id;
                        while ((uint8)CANIF_ZERO != LucCount)
                        {
                          LucCount--;
                          LpTxQueue->aaTxBuffer[LucCount] = LddCanPduInfo.sdu[LucCount];
                        }
                        /* Arrange the pdus according to the priority*/
                        CanIf_TxQueueHandling(LpTxBuffer, LddTxQueueId);
                        /* return E_OK */
                        LenStdRetVal = (uint8)E_OK;
                      } /*(CANIF_INVALID_TXQUEUE != LddTxQueueId)*/
                      else
                      {
                        LenStdRetVal = (uint8)E_NOT_OK;
                      }
                    } /*(CANIF_INVALID_TXQUEUE == CanIf_GddTxBuffCon.pTxPduToQueueMapping [...])*/
                    else
                    {
                      /* Store the pdu in the queue*/
                      /* polyspace +2 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Genderated array index in range" */
                      /* polyspace +1 RTE:NIV [Not a defect:Justified] "Initialized Variable" */
                      LpTxQueue = &(CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId]);
                      LpTxQueue->ddTxLPduId = LddCanPduInfo.swPduHandle;
                      #if (STD_ON == CANIF_OPTIMIZE_QUEUE_BUFFER_SIZE)
                      if (LddCanPduInfo.length > LpTxBuffer->ucQueueBufferSize)
                      {
                        LucCount = LpTxBuffer->ucQueueBufferSize;
                      }
                      else
                      #endif
                      {
                        LucCount = LddCanPduInfo.length;
                      }
                      LpTxQueue->ucDlc = LucCount;
                      LpTxQueue->ddCanId = LddCanPduInfo.id;
                      while ((uint8)CANIF_ZERO != LucCount)
                      {
                        LucCount--;
                        LpTxQueue->aaTxBuffer[LucCount] = LddCanPduInfo.sdu[LucCount];
                      }
                      /* Return E_OK */
                      LenStdRetVal = (uint8)E_OK;
                    }
                  } /* if (CAN_BUSY == LenCanReturn) */
                }
                #else
                {
                  if (CAN_OK != LenCanReturn)
                  {
                    LenStdRetVal = (uint8)E_NOT_OK;
                  }
                }
                #endif
                /* Disable interrupts to protect Tx DATA */
                SchM_Exit_CanIf_TX_QUEUE_PROTECTION();
              }
              #endif
            }
          } /* Status is active to transmit message */
        } /* else -> if (CANIF_TX_OFFLINE_ACTIVE == LucTxStatus) */
        /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Not a defect: Justified] "Condition will be executed based on the configured values" */
      }/* if (((LucTxStatus == CANIF_TX_ENABLED) || (LucTxStatus == CANIF_TX_OFFLINE_ACTIVE))) */
      else
      {
        LenStdRetVal = (uint8)E_NOT_OK;
      }
    }
  }/* if (((uint8)E_OK == LenStdRetVal) */
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : CanIf_CancelTransmit                                **
**                                                                            **
** Service ID           : 0x18                                                **
**                                                                            **
** Description          : This is a dummy method introduced for interface     **
**                        compatibility                                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : CanTxPduId                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : QueueIndex                                          **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):None                             **
**                        Function(s) invoked:None                            **
*******************************************************************************/
#if (STD_ON == CANIF_CANCEL_TRANSMIT_SUPPORT)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, CANIF_CODE) CanIf_CancelTransmit (
                                           VAR(PduIdType, CANIF_VAR) CanTxPduId)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  LenStdRetVal = (uint8)E_OK;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Report to DET, if module is not initialized */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_CANCEL_TRANSMIT_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Tx L-PDU is out of range */
  if((uint8)E_OK != CanIf_TxIdRangeError(CANIF_CANCEL_TRANSMIT_SID, CanTxPduId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }

  /* Is any DET error detected*/
  #else
  /* For unused argument compiler warning */
  if(CanTxPduId != CANIF_ZERO)
  {
  	/* Do Nothing */
  }
  #endif
  return(LenStdRetVal);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_CheckQueueStatus                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpTxBuffer                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : QueueIndex                                          **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GddTxBuffCon              **
**                        Function(s) invoked: None                           **
*******************************************************************************/
#if (STD_ON == CANIF_TX_LPDU)
#if (STD_ON == CANIF_BASIC_CAN_TXPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
#if (STD_ON == CANIF_AUTOEVER_AUTOSAR_CANCELLATION_USED)
FUNC(CanIf_TxQueueType, CANIF_CODE) CanIf_CheckQueueStatus (
                      P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer)
#else
static FUNC(CanIf_TxQueueType, CANIF_CODE) CanIf_CheckQueueStatus (
                      P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer)
#endif
{
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxNextQueue;
  VAR(CanIf_TxQueueType, CANIF_VAR) LddNoOfTxQueue;
  VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId;
  VAR(boolean, CANIF_VAR) LblFreeQueue;
  /* Set LblFreeQueue to CANIF_FALSE */
  LblFreeQueue = CANIF_FALSE;
  /* Get the pointer to first queue index */
  /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
  LpTxNextQueue = &(CanIf_GddTxBuffCon.pTxQueue[LpTxBuffer->ddQueueIndex]);
  /* Get the number of Tx Queue associated with this buffer */
  LddNoOfTxQueue = LpTxBuffer->ddNoOfTxQueue;
  /*Get the appropriate queue Id */
  LddTxQueueId = LddNoOfTxQueue + LpTxBuffer->ddQueueIndex;
  
  do
  {
    /* polyspace +1 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    /* Check the queue status */
    if ((CANIF_INVALID_DATA_LENGTH == LpTxNextQueue->ucDlc) && (CANIF_INVALID_CANID == LpTxNextQueue->ddCanId))
    {
      /* Get the correct Queue Id*/
      LddTxQueueId = LddTxQueueId - LddNoOfTxQueue;
      /* to break the loop */
      LddNoOfTxQueue = (CanIf_TxQueueType)CANIF_ZERO;
      /* Set the LblFreeQueue status to CANIF_TRUE*/
      LblFreeQueue = CANIF_TRUE;
    }
    else
    {
      /* shift to next queue location */
      /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment is used to achieve better throughput. */
      LpTxNextQueue++;
      /* Reduce the number of available TX Queue */
      LddNoOfTxQueue--;
    }
  }while((CanIf_TxQueueType)CANIF_ZERO != LddNoOfTxQueue);

  if (CANIF_FALSE == LblFreeQueue)
  {
    /*Reset TxQueueId to indicate that the queue is available*/
    LddTxQueueId = CANIF_INVALID_TXQUEUE;
  }
  return (LddTxQueueId);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : CanIf_TxQueueHandling                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpBuffer, LucIndex                                  **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GddTxBuffCon              **
**                        Function(s) invoked: None                           **
*******************************************************************************/
#if (STD_ON == CANIF_TX_LPDU)
#if (STD_ON == CANIF_BASIC_CAN_TXPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
#if (STD_ON == CANIF_AUTOEVER_AUTOSAR_CANCELLATION_USED)
FUNC(void, CANIF_CODE) CanIf_TxQueueHandling (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer,
                     VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId)
#else
static FUNC(void, CANIF_CODE) CanIf_TxQueueHandling (
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer,
                     VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId)
#endif
{
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxPrevQueue;
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxQueue;
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxCurrentQueue;
  /* Get the pointer to Tx Queue */
  LpTxQueue = &(CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId]);
  /* Get the current pointer to Tx Queue */
  LpTxCurrentQueue = *LpTxBuffer->pTxFirstQueue;
  /* Check for free queue */
  if (NULL_PTR == LpTxCurrentQueue)
  {
    /* update the next queue index to invalid */
    LpTxQueue->pTxNextQueue = NULL_PTR;
    /* Update head entry */
    *LpTxBuffer->pTxFirstQueue = LpTxQueue;
  }
  else
  {
    /* Make the pointer to NULL Pointer */
    LpTxPrevQueue = NULL_PTR;
    /* Check the insertion point */
    /* polyspace +4 RTE:NIV [Not a defect:Justified] "Initialized Variable" */
    /* polyspace +3 RTE:NIP [Not a defect:Justified] "Pointer is not a NULL and valid" */
    /* polyspace +2 MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    while ((NULL_PTR != LpTxCurrentQueue) &&
                              (LpTxCurrentQueue->ddCanId <= LpTxQueue->ddCanId))
    {
      /* Set the current queue to previous queue*/
      LpTxPrevQueue = LpTxCurrentQueue;
      /* get the pointer to the next queue as current queue*/
      /* polyspace +1 RTE:NIP [Not a defect:Justified] "Initialized Pointer" */
      LpTxCurrentQueue = LpTxCurrentQueue->pTxNextQueue;
    }
    /* Store the current queue pointer to next queue pointer */
    LpTxQueue->pTxNextQueue = LpTxCurrentQueue;
    /* Check if the precious queue is a null pointer or not*/
    if (NULL_PTR != LpTxPrevQueue)
    {
      /*Store the LpTxQueue as the next queue */
      LpTxPrevQueue->pTxNextQueue = LpTxQueue;
    }
    else
    {
      /* Update head entry */
      *LpTxBuffer->pTxFirstQueue = LpTxQueue;
    }/*(NULL_PTR != LpTxPrevQueue)*/
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
#endif
/*******************************************************************************
** Function Name        : CanIf_SetDynamicTxId                                **
**                                                                            **
** Service ID           : 0x0C                                                **
**                                                                            **
** Description          : This service re-configures the corresponding CAN    **
**                        identifier of the requested CAN L-PDU.              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CanTxPduId, CanId                                   **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : The function may not be interrupted by              **
**                        CanIf_Transmit(), if the same L-PDU ID is handled.  **
**                        The CAN Interface must be initialized after         **
**                        POWER ON.                                           **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanIf_GaaTxLpdu, CanIf_GblCanIfStatus,              **
**                        CanIf_GddCanId                                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        Det_ReportError,                                    **
**                        SchM_Enter_CanIf_TX_DYNCANID_PROTECTION,            **
**                        SchM_Exit_CanIf_TX_DYNCANID_PROTECTION              **
*******************************************************************************/
#if ((STD_ON == CANIF_TX_LPDU) && (STD_ON == CANIF_SETDYNAMICTXID_API))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE)CanIf_SetDynamicTxId (
                                           VAR(PduIdType, CANIF_VAR) CanTxPduId,
                                           VAR(Can_IdType, CANIF_VAR) CanId)
{
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu;
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_SET_DYNAMIC_TXID_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if CanTxPduId is out of range */
  if((uint8)E_OK != CanIf_TxIdRangeError(CANIF_SET_DYNAMIC_TXID_SID, CanTxPduId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  #endif
  /* Get the pointer to Tx L-PDU structure */
  #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
  LpTxLpdu = &CanIf_GaaTxLpduSelect[CanTxPduId];
  #else
  LpTxLpdu = &CanIf_GaaTxLpdu[CanTxPduId];
  #endif
  #if (STD_ON == CANIF_DEV_ERROR_DETECT)
  /* Is any DET error Invoked */
  if ((uint8)E_OK == LenStdRetVal)
  {
    /* Check the CAN-ID type of Tx L-PDU */
    /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
    if ((CANIF_STANDARD_CANID_TYPE == (LpTxLpdu->ucCanIdType))
    #if (STD_ON == CANIF_CANFD_SUPPORT)
    || (CANIF_CANFD_STANDARD_CANID_TYPE == (LpTxLpdu->ucCanIdType))
    #endif
    )
    {
      /* Report to DET, If requested CAN-ID value is out of range */
      if (CanId > (Can_IdType)CANIF_STANDARD_CANID_VALUE)
      {
        (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_SET_DYNAMIC_TXID_SID, CANIF_E_PARAM_CANID);
        LenStdRetVal = (uint8)E_NOT_OK;
      }
    } /* Standard CAN-ID */
    else
    {
      /* Report to DET, if requested CAN-ID value is out of range */
      if  (CanId > (Can_IdType)CANIF_EXTENDED_CANID_VALUE)
      {
        (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_SET_DYNAMIC_TXID_SID, CANIF_E_PARAM_CANID);
        LenStdRetVal = (uint8)E_NOT_OK;
      }
      /* Extended CAN ID*/
    }/* if (CANIF_STANDARD_CANID_TYPE == (LpTxLpdu->ucCanIdType)) */
    /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  }/* if ((uint8)E_OK == LenStdRetVal) */
  /* Check whether any development error occurred */
  if ((uint8)E_OK == LenStdRetVal)
  #endif /* #if  (STD_ON == CANIF_DEV_ERROR_DETECT) */
  {
    /* Disable relevant interrupts to protect dynamic CAN-ID */
    SchM_Enter_CanIf_TX_DYNCANID_PROTECTION();
    /* Store the requested CAN ID */
    /* polyspace +1 MISRA-C3:18.1, DEFECT:OUT_BOUND_ARRAY, RTE:OBAI,IDP [Not a defect:Justified] "Genderated array index in range" */
    CanIf_GddCanId[LpTxLpdu->ddDynCanIdIndex] = CanId;
    /* Enable relevant interrupts */
    SchM_Exit_CanIf_TX_DYNCANID_PROTECTION();
  } /* Check whether any development error occurred */
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_ClearTxQueue                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service clears the queue status bit for all    **
**                        the for that controller.                            **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Re-entrant but not for same controller.             **
**                                                                            **
** Input Parameters     : LpController                                        **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanIf_GaaTxLpdu, CanIf_GddTxBuffCon                  **
**                        Function(s) invoked: None                           **
*******************************************************************************/
/* Fixed Bug #1191 */
#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_ClearTxQueue (
 P2CONST(CanIf_ControllerConfigType, AUTOMATIC, CANIF_CONST) LpStaticController)
{
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu;
  VAR(CanIf_TxPduIdType, CANIF_VAR) LddNoOfTxPdu;
  VAR(uint16, CANIF_VAR) LddTxQueueIndex;
  VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId;

  /* Get the Number of TxPdu */
  /* polyspace-begin MISRA-C3:D4.14 [Not a defect:Justified] "LpStaticController is not Null pointer" */
  LddNoOfTxPdu = (CanIf_TxPduIdType)LpStaticController->ddNoOfTxPdu;
  if(LddNoOfTxPdu > (CanIf_TxPduIdType)CANIF_ZERO)
  {
    /* Get the respective pointer to TxLpdu */
    LpTxLpdu = LpStaticController->pTxLpdu;
    do
    {
      /* Check the type of the Can for Basic of Full */
      /* polyspace-begin MISRA-C3:18.1, RTE:IDP [Not a defect: Justified] "Pointer is not a NULL and valid" */
      if (CANIF_BASIC_CAN == (CANIF_HTHTYPE_MASK & LpTxLpdu->ucHTHTypeOrTXPN))
      {
        /* Clear the pTxFirstQueue*/
        /* polyspace-begin MISRA-C3:18.1, RTE:IDP, DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */
        #if ((STD_ON == CANIF_BASIC_CAN_TXPDU) || (STD_ON == CANIF_TX_QUEUE))
        *(CanIf_GddTxBuffCon.pTxBuffer
                        [LpTxLpdu->ddHthIdorBufferId].pTxFirstQueue) = NULL_PTR;
        LddTxQueueIndex = CanIf_GddTxBuffCon.pBasicTxPduIndex[LpTxLpdu->ddTxPduId];
        LddTxQueueId = CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex];
        if(LddTxQueueId!=(CanIf_TxPduIdType)CANIF_INVALID_TXQUEUE)
        {
          CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].ucDlc = CANIF_INVALID_DATA_LENGTH;
          CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].ddCanId = CANIF_INVALID_CANID;
          CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].pTxNextQueue = NULL_PTR;
          CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex] =
                                       (CanIf_TxPduIdType)CANIF_INVALID_TXQUEUE;
        }
        #endif
        /* polyspace-end DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */
      }/*if (CANIF_BASIC_CAN == (CANIF_HTHTYPE_MASK))*/
      /* Decrement the number of TxPdu and increment pointer to LpTxPdu*/
      LddNoOfTxPdu--;
      /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment is used to achieve better throughput. */
      LpTxLpdu++;
    }while ((CanIf_TxPduIdType)CANIF_ZERO != LddNoOfTxPdu);
  }
  /* polyspace-end MISRA-C3:D4.14 [Not a defect:Justified] "LpStaticController is not Null pointer" */
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : CanIf_QueueTransmit                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service transmit L-PDU to Can Driver           **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpTxLpdu, LpTxNextQueue                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Can_ReturnType(CAN_OK, CAN_BUSY, CAN_NOT_OK)        **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GddTxBuffCon              **
**                        Function(s) invoked: CanIf_CanWriteService          **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_QueueTransmit (
                          P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu)
{
  P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST)LpTxBuffer;
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR)LpTxQueue;
  VAR(Can_PduType, CANIF_VAR) LddCanPduInfo;
  VAR(Can_ReturnType, CANIF_VAR) LenCanReturn;
  VAR(uint16, CANIF_VAR) LddTxQueueIndex;

  SchM_Enter_CanIf_TX_QUEUE_PROTECTION();
  /* Get the pointer to the TxBuffer*/
  /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
  #if ((STD_ON == CANIF_BASIC_CAN_TXPDU) || (STD_ON == CANIF_TX_QUEUE))
  if (CanIf_GddTxBuffCon.pTxBuffer != NULL_PTR)
  {
    LpTxBuffer = &(CanIf_GddTxBuffCon.pTxBuffer[LpTxLpdu->ddHthIdorBufferId]);
    /* Get the pointer to the TxQueue*/
    LpTxQueue = *LpTxBuffer->pTxFirstQueue;
    if (NULL_PTR != LpTxQueue)
    {
      /* polyspace-begin MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
      /* polyspace-begin RTE:NIV [Not a defect:Justified] "Initialized Variable" */
      /* polyspace-begin RTE:NIP [Not a defect:Justified] "Pointer is not a NULL and valid" */
      LddCanPduInfo.id = LpTxQueue->ddCanId;
      /* Get the DLC */
      LddCanPduInfo.length = (LpTxQueue->ucDlc);
      /* Get the pointer to queue data */
      LddCanPduInfo.sdu = &LpTxQueue->aaTxBuffer[CANIF_ZERO];
      /* Get the Tx L-PDU handle Id */
      LddCanPduInfo.swPduHandle = LpTxQueue->ddTxLPduId;
      /* polyspace-begin MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect:Justified] "Because it is dependent on Mcal logic, it is justified." */
      #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
      /* Call Can_Write() */
      LenCanReturn = CanIf_CanWriteService(LpTxLpdu,
                                             LpTxBuffer->ddHthId, &LddCanPduInfo);
      #else
      /* Call Can_Write() */
      LenCanReturn = CanIf_CanWriteService(LpTxBuffer->ddHthId, &LddCanPduInfo);
      #endif
      if (CAN_OK == LenCanReturn)
      {
        /* Clear the Dlc and CanId so that the tx queue is available for further storing of pdu */
        LpTxQueue->ucDlc = CANIF_INVALID_DATA_LENGTH;
        LpTxQueue->ddCanId = CANIF_INVALID_CANID;
        /* Make the next queue as first queue to be transmitted */
        *LpTxBuffer->pTxFirstQueue = LpTxQueue->pTxNextQueue;
        /* Get the mapping index to pTxPduToQueueMapping array */
        LddTxQueueIndex = CanIf_GddTxBuffCon.pBasicTxPduIndex[LpTxQueue->ddTxLPduId];
        /* Clearing the mapping for the transmitted Pdu */
        CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex] = (CanIf_TxPduIdType)CANIF_INVALID_TXQUEUE;
      }/*(CAN_OK == LenCanReturn)*/
      /* polyspace-end MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect:Justified] "Because it is dependent on Mcal logic, it is justified." */
      /* polyspace-end RTE:NIP [Not a defect:Justified] "Pointer is not a NULL and valid" */
      /* polyspace-end RTE:NIV [Not a defect:Justified] "Initialized Variable" */
      /* polyspace-end MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    }/*if (NULL_PTR != LpTxQueue)*/
  }
  #else
  if(LpTxLpdu != NULL_PTR)
  {
    /* Do Nothing */
  }
  #endif
  SchM_Exit_CanIf_TX_QUEUE_PROTECTION();
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CanIf_TxNotification                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpTxLpdu                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):   CanIf_GaaTxCbkUser            **
**                        Function(s) invoked:  None                          **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(void, CANIF_CODE) CanIf_TxNotification (
                         P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu)
{
  VAR(uint8, CANIF_VAR) LucVar;
  /* Get the upper layer callback user */
  /* polyspace +1 MISRA-C3:18.1,D4.14, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
  LucVar = LpTxLpdu->ucTxCbkUser;
  /* Check if confirmation is configured for that Tx L-PDU */
  if (LucVar < CANIF_MAX_UL)
  {
    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Low] "The value is generated by Generator." */
    #if(STD_ON == CANIF_TX_MULTIPLE_CALLBACK)
    {
      /* Invoke the upper layer Tx Confirmation callback */
      CanIf_GpTxMulCbkUser[LpTxLpdu->ucCallbackIndex].pTxCbkUser
        (LpTxLpdu->ddTxConfirmPduId);
    }
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Low] "The value is generated by Generator." */
    #else
    {
      /* polyspace +1 MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE [Not a defect: Justified] "Condition will be executed based on the configured values" */
      if(CanIf_GaaTxSingleCbkUser[LucVar].pTxCbkUser != NULL_PTR)
      {
        CanIf_GaaTxSingleCbkUser[LucVar].pTxCbkUser(LpTxLpdu->ddTxConfirmPduId);
      }
    }
    #endif

  } /* Check if Tx Confirmation is not disabled */
  #if (STD_ON == CANIF_READTXPDU_NOTIFY_STATUS_API)
  /* Get the mask value */
  LucVar = (LpTxLpdu->ucTxNotifyStsMask);
  /* Check if notification is configured for that Tx L-PDU */
  if ((uint8)CANIF_ZERO != LucVar)
  {
    /* Disable relevant interrupts */
    SchM_Enter_CanIf_TX_NOTIFSTATUS_PROTECTION();
    /* Set the notification status value by applying appropriate mask */
    /* polyspace +2 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
    CanIf_GaaBitArray[LpTxLpdu->ucTxNotifyStatusIndex] =
                    CanIf_GaaBitArray[LpTxLpdu->ucTxNotifyStatusIndex] | LucVar;
    /* Enable relevant interrupts */
    SchM_Exit_CanIf_TX_NOTIFSTATUS_PROTECTION();
  } /* if (LucVar != CANIF_ZERO) */
  #endif
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CanIf_CanWriteService                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpTxLpdu                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s): CanIf_GaaCanDriver              **
**                        Function(s) invoked: Can_Write()                    **
*******************************************************************************/
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin DEFECT:UNCALLED_FUNC [Not a defect: Justified] "A function is used on Transmit" */
#if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
static FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                          P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST)LpTxLpdu,
                          VAR(Can_HwHandleType, CANIF_VAR) LddHth,
                          P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo)
#else
static FUNC(Can_ReturnType, CANIF_CODE) CanIf_CanWriteService (
                           VAR(Can_HwHandleType, CANIF_VAR) LddHth,
                           P2CONST(Can_PduType, AUTOMATIC, CANIF_CONST) PduInfo)
#endif
{
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  P2CONST(CanIf_CanDriver, AUTOMATIC, CANIF_CONST) LpDriver;
  #endif
  VAR(Can_ReturnType, CANIF_VAR) LenDrvRetVal;
  #if (STD_ON == CANIF_TX_LPDU)
  /* Set GW state to REQUESTED */
  /* polyspace +2 MISRA-C3:D4.14 [Not a defect: Justified] "Array range is pre-defined" */
  /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
  CanIf_GaaTxPduGwStatus[PduInfo->swPduHandle] = CANIF_GW_REQUESTED;
  #endif
  /* polyspace-begin CERT-C:DCL39-C [Not a defect:Justified] "This parameter was defined by specification" */
  #if (STD_ON == CANIF_MULTIPLE_CANDRV_SUPPORT)
  /* Get the pointer to corresponding Can Driver structure */
  LpDriver = &CanIf_GaaCanDriver[LpTxLpdu->ucDriverId];
  /* Invoke the function to set the controller mode for Can Driver*/
  LenDrvRetVal = LpDriver->pCanWrite (LddHth, PduInfo);
  #else
  /* Invoke the function to set the controller mode for Can Driver*/
  LenDrvRetVal = Can_Write(LddHth, PduInfo);
  #endif
  #if ((STD_ON == CANIF_TX_RX_MONITORING_SUPPORT) && (STD_ON == CANIF_TX_LPDU))
  if (CAN_OK == LenDrvRetVal)
  {
    CanIf_GaaTransmitCnt[PduInfo->swPduHandle]++;
  }
  #endif
  /* polyspace-end CERT-C:DCL39-C [Not a defect:Justified] "This parameter was defined by specification" */
  return(LenDrvRetVal);
}
/* polyspace-end DEFECT:UNCALLED_FUNC [Not a defect: Justified] "A function is used on Transmit" */
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CanIf_ClearTxBuffer                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpTxLpdu                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanIf_GddTxBuffCon                                  **
**                                                                            **
**                        Function(s) invoked:  None                          **
*******************************************************************************/
#if (STD_ON == CANIF_SETDYNAMICTXID_API)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
static FUNC(void, CANIF_CODE) CanIf_ClearTxBuffer (
                     VAR(CanIf_TxPduIdType, CANIF_VAR) LddTxPduId,
                     P2CONST(CanIf_TxBuffer, AUTOMATIC, CANIF_CONST) LpTxBuffer)
{
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxQueue;
  P2VAR(CanIf_TxQueue, AUTOMATIC, CANIF_VAR) LpTxFirstQueue;
  VAR(CanIf_TxQueueType, CANIF_VAR) LddTxQueueId;
  VAR(uint16, CANIF_VAR) LddTxQueueIndex;

  /* Get the mapping index to pTxPduToQueueMapping array */
  if(CanIf_GddTxBuffCon.pBasicTxPduIndex != NULL_PTR)
  {
    /* polyspace-begin MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    LddTxQueueIndex = CanIf_GddTxBuffCon.pBasicTxPduIndex[LddTxPduId];
    /* Get the TxqueueId from CanIf_GddTxBuffCon.pTxPduToQueueMapping array */
    LddTxQueueId = CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex];
    if(LddTxQueueIndex != CANIF_INVALID_TXQUEUE)
    {
      /* Mark it as available */
      CanIf_GddTxBuffCon.pTxPduToQueueMapping[LddTxQueueIndex] =
      (CanIf_TxPduIdType)CANIF_INVALID_TXQUEUE;
      /* Set Status of Tx queue as available*/
      CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].ucDlc = CANIF_INVALID_DATA_LENGTH;
      CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId].ddCanId = CANIF_INVALID_CANID;
      /* Get the pointer to respective TxQueue */
      LpTxQueue = &(CanIf_GddTxBuffCon.pTxQueue[LddTxQueueId]);
      /* Get the pointer to respective TxQueue */
      /* polyspace +1 RTE:NIP [Not a defect: Justified] "Pointer is not a NULL and valid" */
      LpTxFirstQueue = *LpTxBuffer->pTxFirstQueue;
      if (LpTxFirstQueue == LpTxQueue)
      { /* Make the next queue as first queue */
        *LpTxBuffer->pTxFirstQueue = LpTxQueue->pTxNextQueue;
      }
      else
      {
        /* polyspace +1 RTE:NIP [Not a defect:Justified] "Pointer is not a NULL and valid" */
        while ((LpTxQueue != LpTxFirstQueue->pTxNextQueue) &&
                                         (LpTxFirstQueue->pTxNextQueue != NULL_PTR))
        {
          /* Make the next queue as first queue */
          LpTxFirstQueue = LpTxFirstQueue->pTxNextQueue;
        }
        /* Update next queue */
        LpTxFirstQueue->pTxNextQueue = LpTxQueue->pTxNextQueue;
      }
      /* polyspace-end MISRA-C3:18.1, RTE:IDP [Not a defect:Justified] "Genderated array index in range" */
    }
  }
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_DETTransmit                                   **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This service initiates a request for transmission of**
**                        the CAN L-PDU specified by the CanTxPduId and CAN   **
**                        related data in the L-PDU structure                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CanTxPduId, PduInfoPtr                              **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanIf_GblCanIfStatus, CanIf_GaaTxLpdu,              **
**                        CanIf_GaaController                                 **
**                        Function(s) invoked:                                **
**                        CanIf_ClearTxBuffer, CanIf_TxQueueHandling,         **
**                        Det_ReportError, CanIf_StoreLpduInQueue,            **
**                        CanIf_TxNotification, CanIf_CanWriteService         **
*******************************************************************************/
#if ((STD_ON == CANIF_DEV_ERROR_DETECT) && (STD_ON == CANIF_TX_LPDU))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin DEFECT:NON_INIT_VAR [Not a defect: Justified] "Variables shall be initiallized" */
/* polyspace-begin MISRA-C3:9.1 [Not a defect: Justified] "Variables shall be initiallized" */
static FUNC(Std_ReturnType, CANIF_CODE) CanIf_DETTransmit (
                        VAR(PduIdType, CANIF_VAR) CanTxPduId,
                        P2CONST(PduInfoType, AUTOMATIC, CANIF_CONST) PduInfoPtr)
{
  #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu;
  #endif
  P2VAR(CanIf_Controller, AUTOMATIC, CANIF_VAR) LpController;
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  VAR(uint8, CANIF_VAR) LucTxStatus;
  VAR(uint8, CANIF_VAR) LucRxStatus;
  VAR(uint8, CANIF_VAR) LucCurrentMode;

  /* Set LenStdRetVal to E_OK */
  LenStdRetVal = (uint8)E_OK;
  /* Report to DET, if module is not initialized */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_GlobalInitStatusError(CANIF_TRANSMIT_SID))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }
  /* Report to DET, if Tx L-PDU is out of range */
  /* polyspace +2 MISRA-C3:8.3 [Not a defect:Justified] "Declaration is matched" */
  /* polyspace +1 DEFECT:DECL_MISMATCH [Not a defect:Justified] "Declaration is matched" */
  if((uint8)E_OK != CanIf_TxIdRangeError(CANIF_TRANSMIT_SID, CanTxPduId))
  {
    LenStdRetVal = (uint8)E_NOT_OK;
  }

  if ((uint8)E_OK == LenStdRetVal)
  {
    #if (CANIF_NO_OF_CONTROLLER > CANIF_ONE)
    /* Get the pointer to Tx Lpdu */
    #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
    LpTxLpdu = &CanIf_GaaTxLpduSelect[CanTxPduId];
    #else
    LpTxLpdu = &CanIf_GaaTxLpdu[CanTxPduId];
    #endif
    /* Get the pointer to controller */
    /* polyspace +2 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    /* polyspace +1 RTE:IDP [Not a defect: Justified] "Pointer is not outside its bounds." */
    LpController = &CanIf_GaaController[LpTxLpdu->ucControllerId];
    #else
    LpController = &CanIf_GaaController[CANIF_ZERO];
    #endif
    /* get the Tx status into local variable */
    /* polyspace<RTE: IDP : Not a defect : No Action Planned >
       Its boundary is pre-defined */
    /* polyspace +1 MISRA-C3:18.1 [Not a defect: Justified] "Pointer is not outside its bounds." */
    LucTxStatus = ((LpController->ucTxStatus) & (CANIF_TX_STATUS_MASK));
    /* get the Rx status into local variable */
    LucRxStatus = ((LpController->ucRxStatus) & (CANIF_RX_STATUS_MASK));
    /* get the ControllerMode into local variable */
    LucCurrentMode  = LpController->ucControllerMode;
    /* Report to DET, if PduInfoptr is a Null Ptr*/
    if (PduInfoPtr == NULL_PTR)
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_TRANSMIT_SID, CANIF_E_PARAM_POINTER);
      LenStdRetVal = (uint8)E_NOT_OK;
    }
    /* Report to DET, if PduInfoPtr or SduDataPtr is equal to NULL */
    if ((uint8)E_OK == LenStdRetVal)
    {
      /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
      if (PduInfoPtr->SduDataPtr == NULL_PTR)
      {
        (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                       CANIF_TRANSMIT_SID, CANIF_E_PARAM_POINTER);
        LenStdRetVal = (uint8)E_NOT_OK;
      }
    }

    /* Report to DET, if PDU mode is Offline or Controller Mode is Stopped */
    if (((CANIF_TX_DISABLED == LucTxStatus) && (CANIF_RX_DISABLED == LucRxStatus))
                                       || (CANIF_TX_DISABLED == LucTxStatus)
                                       || ((uint8)CANIF_CS_STOPPED == LucCurrentMode))
    {
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                            CANIF_TRANSMIT_SID, CANIF_E_STOPPED);
      (LenStdRetVal) = (uint8)E_NOT_OK;
    }
  }
  return(LenStdRetVal);
}
/* polyspace-end MISRA-C3:9.1 [Not a defect: Justified] "Variables shall be initiallized" */
/* polyspace-end DEFECT:NON_INIT_VAR [Not a defect: Justified] "Variables shall be initiallized" */
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_TriggerTransmit                               **
**                                                                            **
** Service ID           : 0x41                                                **
**                                                                            **
** Description          : dummy API                                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : TxPduId, PduInfoPtr                                 **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):None                             **
**                        Function(s) invoked:None                            **
*******************************************************************************/
#if ((CANIF_CANDRV_VERSION_SUPPORT == CANIF_VER_440) || \
      (((CAN_AR_RELEASE_MAJOR_VERSION == CAN_AR_RELEASE_MAJOR_VERSION_FOUR) && \
      (CAN_AR_RELEASE_MINOR_VERSION >= CAN_AR_RELEASE_MINOR_VERSION_TWO)) || \
      (CAN_AR_RELEASE_MAJOR_VERSION > CAN_AR_RELEASE_MAJOR_VERSION_FOUR)))
#define CANIF_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin MISRA-C3:8.13 [Not a defect: Justified] "CanIf_TriggeringTransmit is dummy function. So PduInfoPtr pointer struct does not modify an object. Therefore, the function is justified because it is defined in the Autosar specification." */
FUNC(Std_ReturnType, CANIF_CODE) CanIf_TriggerTransmit(
                   VAR(PduIdType, CANIF_VAR) TxPduId,
                   P2VAR(PduInfoType, AUTOMATIC, CANIF_VAR) PduInfoPtr)
{
  VAR(Std_ReturnType, CANIF_VAR) LenStdRetVal;
  LenStdRetVal = (uint8)E_OK;
  /* For unused argument compiler warning */
  if((TxPduId != CANIF_ZERO) && (PduInfoPtr != NULL_PTR))
  {
    /* Do Nothing */
  }

  return(LenStdRetVal);
}
/* polyspace-end MISRA-C3:8.13 [Not a defect: Justified] "CanIf_TriggeringTransmit is dummy function. So PduInfoPtr pointer struct does not modify an object. Therefore, the function is justified because it is defined in the Autosar specification." */
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif

/*******************************************************************************
** Function Name        : CanIf_TxTruncation                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service check truncation of                    **
**                        PDUs that exceed the configured size.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : CanTxPduId,PduInfoPtr                               **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : TruncationFlag                                      **
**                                                                            **
** Preconditions        : The CAN Interface must be initialised.              **
**                                                                            **
** Remarks              : Global Variable(s):None                             **
**                        Function(s) Det_ReportError                         **
*******************************************************************************/
#if (STD_ON == CANIF_TX_LPDU)
#define CANIF_START_SEC_CODE
#include "MemMap.h"
FUNC(uint8, CANIF_CODE) CanIf_TxTruncation(
    #if ((STD_ON == CANIF_TX_TRUNCATION_SUPPORT) || (STD_ON == CANIF_CANFD_SUPPORT))
    VAR(PduIdType, CANIF_VAR) CanTxPduId,
    #endif
    P2CONST(PduInfoType, AUTOMATIC, CANIF_APPL_CONST) PduInfoPtr)
{
  VAR(uint8, CANIF_VAR) LucTruncationFlag;
  #if ((STD_ON == CANIF_TX_TRUNCATION_SUPPORT) || (STD_ON == CANIF_CANFD_SUPPORT))
  P2CONST(CanIf_TxLpdu, AUTOMATIC, CANIF_CONST) LpTxLpdu;
  #if (STD_ON == CANIF_VARIANT_POSTBUILD_SUPPORT)
  LpTxLpdu = &CanIf_GaaTxLpduSelect[CanTxPduId];
  #else
  LpTxLpdu = &CanIf_GaaTxLpdu[CanTxPduId];
  #endif
  #endif
  LucTruncationFlag = (uint8)CANIF_ZERO;
  if ((uint8)CANIF_SDU_MAX_LENGTH < PduInfoPtr->SduLength)
  {
    #if(STD_ON == CANIF_TX_TRUNCATION_SUPPORT)
    if (CANIF_FALSE == LpTxLpdu->blTxPduTruncation)
    #endif
    {
      #if(STD_ON == CANIF_DEV_ERROR_DETECT)
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                 CANIF_TRANSMIT_SID, CANIF_E_INVALID_DLC);
      #endif
      LucTruncationFlag = (uint8)CANIF_TWO;
    }
    #if(STD_ON == CANIF_TX_TRUNCATION_SUPPORT)
    else
    {
      #if(STD_ON == CANIF_DEV_ERROR_DETECT)
      (void)Det_ReportError(CANIF_MODULE_ID, (uint8)CANIF_ZERO,
                                 CANIF_TRANSMIT_SID, CANIF_E_PARAM_DLC);
      #endif
      LucTruncationFlag = (uint8)CANIF_ONE;
    }
    #endif
  }
  return (LucTruncationFlag);
}
#define CANIF_STOP_SEC_CODE
#include "MemMap.h"
#endif
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
