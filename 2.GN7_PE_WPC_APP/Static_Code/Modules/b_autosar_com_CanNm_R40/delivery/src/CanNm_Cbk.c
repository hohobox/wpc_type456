/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Cbk.c                                                   **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : APIs implementation for CanNm module                          **
**              CanNm_TxConfirmation                                          **
**              CanNm_RxIndication                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date         By                  Description                     **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.1.0.1   27-Nov-2020   Sanghoon Kim      #25246                           **
** 2.1.1.0   28-Jan-2021   Sanghoon Kim      #28031                           **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.2.6.0   31-Aug-2022   Jaeho Yang        #35237                           **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   24-May-2023   SM Kwon           #40495                           **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.4.1.0   02-Oct-2023   Jaeho Yang        #39866                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CanNm API Header file */
#include "CanNm_Cbk.h"            /* CanNm Call back function Header file */
#include "CanNm_Internal.h"       /* CanNm Internal function Header file */
#include "Det.h"                  /* DET header file */
#include "CanNm_Error.h"          /* DET Error header file*/
#include "SchM_CanNm.h"           /* Schedule Manager header file */
#include "Nm_Cbk.h"               /* Nm Interface Call back function Header */
#include "PduR_CanNm.h"           /* PduR CallBack Functions Header File */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_CBK_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_CBK_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_CBK_C_AR_RELEASE_REVISION_VERSION 3

/* CanNm software version information */
#define CANNM_CBK_C_SW_MAJOR_VERSION            2
#define CANNM_CBK_C_SW_MINOR_VERSION            5
#define CANNM_CBK_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_CBK_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm_Cbk.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_CBK_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm_Cbk.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION != CANNM_CBK_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm_Cbk.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_CBK_C_SW_MAJOR_VERSION)
#error "CanNm_Cbk.c : Mismatch in Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_CBK_C_SW_MINOR_VERSION)
#error "CanNm_Cbk.c : Mismatch in Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define CANNM_START_SEC_CONST_8
#include "MemMap.h"
CONST(uint8, CANNM_CONST) CanNm_GaaDiscreteDlctoDataLength[CANNM_EIGHT] = {8U,12U,16U,20U,24U,32U,48U,64U};
#define CANNM_STOP_SEC_CONST_8
#include "MemMap.h"
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace-begin RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
#define CANNM_START_SEC_CODE
#include "MemMap.h"
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmTxConfirmationHandleId(
  PduIdType CanNmTxConfirmationHandleId,
  P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex);

static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmRxIndicationHandleId(
    PduIdType RxPduId,
    P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex);
#if (CANNM_COMUSERDATASUPPORT == STD_ON)
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmTriggerTransmitHandleId(
  PduIdType CanNmTriggerTransmitHandleId,
  P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex);
#endif /* (CANNM_COMUSERDATASUPPORT == STD_ON) */
static FUNC(CANNM_RX_HANDLING_METHOD, CANNM_CODE) CanNm_LocalGetRxHandlingMethod(
  uint32 LulCanNmChannelIndex,
  P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) LaaRxPdu);

static FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckDlcFromCanNmRxIndication(
	PduLengthType SduLength);

/*******************************************************************************
** Function Name        : CanNm_LocalGetCanNmChannelIndexFromCanNmTxConfirmat **
**                        ionHandleId                                         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get CanNmChannelIndex                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : CanNmTxConfirmationHandleId                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : CanNmChannelIndex                                   **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GulTxPduSize                                  **
**                        CanNm_GaaTxPdu                                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        N/A                                                 **
*******************************************************************************/

static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmTxConfirmationHandleId(
  PduIdType CanNmTxConfirmationHandleId,
  P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulIndex;

  for (LulIndex = 0U; LulIndex < CanNm_GulTxPduSize; LulIndex++)
  {
    P2CONST(CanNm_TxPdu, AUTOMATIC, CANNM_CONST) LpTxPdu;

    LpTxPdu = &CanNm_GaaTxPdu[LulIndex];

    if (LpTxPdu->ddCanNmTxPduId == CanNmTxConfirmationHandleId)
    {
      *CanNmChannelIndex = LpTxPdu->ulCanNmChannelIndex;
      LddStdReturnValue = E_OK;
      break;
    }
  }

  return LddStdReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_LocalGetCanNmChannelIndexFromCanNmRxIndicatio **
**                        nHandleId                                           **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get CanNmChannelIndex                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : RxPduId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : CanNmChannelIndex                                   **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GulRxPduSize                                  **
**                        CanNm_GaaRxPdu                                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        N/A                                                 **
*******************************************************************************/

static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmRxIndicationHandleId(
    PduIdType RxPduId,
    P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulIndex;

  for (LulIndex = 0U; LulIndex < CanNm_GulRxPduSize; LulIndex++)
  {
    P2CONST(CanNm_RxPdu, AUTOMATIC, CANNM_CONST) LpRxPdu;

    LpRxPdu = &CanNm_GaaRxPdu[LulIndex];

    if (LpRxPdu->ddCanNmRxPduId == RxPduId)
    {
      *CanNmChannelIndex = LpRxPdu->ulCanNmChannelIndex;
      LddStdReturnValue = E_OK;
      break;
    }
  }

  return LddStdReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_LocalGetCanNmChannelIndexFromCanNmTriggerTran **
**                        smitHandleId                                        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get CanNmChannelIndex                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : CanNmTriggerTransmitHandleId                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : CanNmChannelIndex                                   **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GulTxPduSize                                  **
**                        CanNm_GaaTxPdu                                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        N/A                                                 **
*******************************************************************************/
#if (CANNM_COMUSERDATASUPPORT == STD_ON)
static FUNC(Std_ReturnType, CANNM_CODE) CanNm_LocalGetCanNmChannelIndexFromCanNmTriggerTransmitHandleId(
  PduIdType CanNmTriggerTransmitHandleId,
  P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulIndex;

  for (LulIndex = 0U; LulIndex < CanNm_GulTxPduSize; LulIndex++)
  {
    P2CONST(CanNm_TxPdu, AUTOMATIC, CANNM_CONST) LpTxPdu;

    LpTxPdu = &CanNm_GaaTxPdu[LulIndex];

    if (LpTxPdu->ddCanNmTxPduId == CanNmTriggerTransmitHandleId)
    {
      *CanNmChannelIndex = LpTxPdu->ulCanNmChannelIndex;
      LddStdReturnValue = E_OK;
      break;
    }
  }

  return LddStdReturnValue;
}
#endif /* (CANNM_COMUSERDATASUPPORT == STD_ON) */
/*******************************************************************************
** Function Name        : CanNm_LocalGetRxHandlingMethod                      **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get Rx Handling Method                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex, LaaRxPdu                      **
**                                                                            **
** InOut parameter      : N/A                                                 **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : CANNM_RX_HANDLING_METHOD                            **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblPnEnabled                                  **
**                        CanNm_GucPnInfoLength                               **
**                        CanNm_GaaPnMaskByte                                 **
**                        CanNm_GucPnInfoOffset                               **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

static FUNC(CANNM_RX_HANDLING_METHOD, CANNM_CODE) CanNm_LocalGetRxHandlingMethod(
  uint32 LulCanNmChannelIndex,
  P2CONST(uint8, AUTOMATIC, CANNM_APPL_DATA) LaaRxPdu)
{
  CANNM_RX_HANDLING_METHOD LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_IGNORE;

  #if (CANNM_PNENABLED == STD_ON)
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  boolean LblPNIBitIsSet;
  uint8 LucPduCbvPosition;
  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif
  #endif

  #if (CANNM_PNENABLED == STD_ON)
  LucPduCbvPosition = LpStaticChannel->ucPduCbvPosition;
  if ((LucPduCbvPosition != (uint8)CANNM_PDU_OFF) && ((LaaRxPdu[LucPduCbvPosition] & CANNM_PNI_BIT) == CANNM_PNI_BIT))
  {
    LblPNIBitIsSet = CANNM_TRUE;
  }
  else
  {
    LblPNIBitIsSet = CANNM_FALSE;
  }
  #endif
  #if (CANNM_PNENABLED == STD_OFF)

    LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_PROCESS_WITHOUT_PARTIAL_NETWORK;
    CANNM_UNUSED(LulCanNmChannelIndex);
    CANNM_UNUSED_PTR(LaaRxPdu);
  #else
  if (LpChannel->blPnStatusBit == CANNM_FALSE)
  {
    LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_PROCESS_WITHOUT_PARTIAL_NETWORK;
  }
  #if (CANNM_ALL_NMMESSAGES_KEEPAWAKE_ENABLED == STD_ON)
  else if ((LpStaticChannel->blAllNmMessagesKeepAwake == CANNM_TRUE) && (LblPNIBitIsSet == CANNM_FALSE))
  {
    LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_PROCESS_WITHOUT_PARTIAL_NETWORK;
  }
  else if ((LpStaticChannel->blAllNmMessagesKeepAwake == CANNM_TRUE) && (LblPNIBitIsSet == CANNM_TRUE))
  {
    LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_PROCESS_WITH_PARTIAL_NETWORK;
  }
  #endif
  else if (LblPNIBitIsSet == CANNM_TRUE)
  {
    uint8 LucIndex;

    /* Loop through all the PN bytes configured */
    for (LucIndex = 0U; LucIndex < CanNm_GucPnInfoLength; LucIndex++)
    {
      uint8 LucMask;
      uint8 LucPnInfo;
      uint8 LucReleatedPnInfo;

      /* Take the PN mask byte into local variable */
      #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
      LucMask = CanNm_GpPnMaskByte[LucIndex];
      #else
      LucMask = CanNm_GaaPnMaskByte[LucIndex];
      #endif      

      /* check if PN enabled using the mask byte */
      LucPnInfo = LaaRxPdu[CanNm_GucPnInfoOffset + LucIndex];

      LucReleatedPnInfo = LucPnInfo & LucMask;
      if (LucReleatedPnInfo != 0U)
      {
        LblRxHandlingMethod = CANNM_RX_HANDLING_METHOD_PROCESS_WITH_PARTIAL_NETWORK;
      }
    }
  }
  else
  {
    ;
  }
  #endif
  
  return LblRxHandlingMethod;
}

/*******************************************************************************
** Function Name        : CanNm_CheckDlcFromCanNmRxIndication                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Check CanNm Rx Message Data Length Method           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SduLength                      					  **
**                                                                            **
** InOut parameter      : N/A                                                 **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : LddStdReturnValue                            **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GaaDiscreteDlctoDataLength                                  **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

static FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckDlcFromCanNmRxIndication(
	PduLengthType SduLength) {
	uint8 LucIndex;
	Std_ReturnType LddStdReturnValue = E_NOT_OK;

	/* Check if Can msg is a valid dlc */
	for (LucIndex = 0U; LucIndex < CANNM_EIGHT; LucIndex++){
		if (SduLength == CanNm_GaaDiscreteDlctoDataLength[LucIndex]) {
			LddStdReturnValue = E_OK;
			break;
		}
	}

	return LddStdReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_TxConfirmation                                **
**                                                                            **
** Service ID           : 0x40                                               **
**                                                                            **
** Description          : Notify CAN NM that NM message has been successfully **
**                       transmitted.                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant(but not for the same NM-channel)         **
**                                                                            **
** Input Parameters     : TxPduId                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : The CanNm and the CanIf itself are initialized      **
**                        correctly                                           **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus,                                **
**                        CanNm_GblPassiveModeEnabled                         **
**                        CanNm_GblImmediateTxConfEnabled                     **
**                        CanNm_GblComUserDataSupport                         **
**                                                                            **
**                        Function Invoked:                                   **
**                        CanNm_LocalGetCanNmChannelIndexFromCanNmTxConfirmat **
**                        ionHandleId                                         **
**                        CanNm_IntDetReportError                             **
**                        PduR_CanNmTxConfirmation                            **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_TxConfirmation(PduIdType TxPduId)
{
#if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_IMMEDIATETXCONFENABLED == STD_OFF))
  uint32 LddCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TX_CONFIRMATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_LocalGetCanNmChannelIndexFromCanNmTxConfirmationHandleId(TxPduId, &LddCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TX_CONFIRMATION_SID, CANNM_E_INVALID_PDUID);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LddCanNmChannelIndex];

    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LddCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LddCanNmChannelIndex];
    #endif

    LpChannel->ddTxState = CANNM_TX_STATE_READY;

    if (LpChannel->ucNoOfImmediateNmTx > 0)
    {
      LpChannel->ucNoOfImmediateNmTx--;
    }

    LpChannel->ddMsgTimeOutTime = 0;

    LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
    LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING;

    /*Invoke Pdur function*/
    #if (CANNM_COMUSERDATASUPPORT == STD_ON)
    PduR_CanNmTxConfirmation(LpStaticChannel->ddPduRCanNmTxConfirmationHandleId);
    #endif

  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif
}

/*******************************************************************************
** Function Name        : CanNm_RxIndication                                  **
**                                                                            **
** Service ID           : 0x42                                                **
**                                                                            **
** Description          : Notify CAN NM that a NM message has been received.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant(but not for the same NM-channel)         **
**                                                                            **
** Input Parameters     : RxPduId, PduInfoPtr                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : The CanNm and the CanIf itself are initialized      **
**                        correctly                                           **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblPnEiraCalcEnabled                          **
**                        CanNm_GblPnEraCalcEnabled                           **
**                        CanNm_GucPnInfoOffset                               **
**                        CanNm_GblPduRxIndicationEnabled                     **
**                        CanNm_GblNodeDetectionEnabled                       **
**                        CanNm_GblRepeatMsgIndEnabled                        **
**                        CanNm_GblCoordinatorSyncSupport                     **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function Invoked:                                   **
**                        CanNm_LocalGetCanNmChannelIndexFromCanNmRxIndicatio **
**                        nHandleId                                           **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalGetRxHandlingMethod                      **
**                        CanNm_Memcpy                                        **
**                        CanNm_IntUpdateEIRA                                 **
**                        CanNm_IntUpdateERA                                  **
**                        Nm_PduRxIndication                                  **
**                        Nm_NetworkStartIndication                           **
**                        CanNm_IntRequestRepeatMessageState                  **
**                        CanNm_IntNmPduTxEnabled                             **
**                        Nm_RepeatMessageIndication                          **
**                        Nm_CoordReadyToSleepIndication                      **
**                        Nm_CoordReadyToSleepCancellation                    **
**                        Nm_RemoteSleepCancellation                          **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_RxIndication(
  PduIdType RxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_DATA) PduInfoPtr)
{
  uint32 LulCanNmChannelIndex = 0;

  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus != CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_RX_INDICATION_SID, CANNM_E_UNINIT);
  }
  /* polyspace +1 MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
  else if ((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_RX_INDICATION_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_LocalGetCanNmChannelIndexFromCanNmRxIndicationHandleId(RxPduId, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_RX_INDICATION_SID, CANNM_E_INVALID_PDUID);
  }
  else if (E_OK != CanNm_CheckDlcFromCanNmRxIndication(PduInfoPtr->SduLength))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_RX_INDICATION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CANNM_RX_HANDLING_METHOD LddRxHandlingMethod;

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    CanNm_Memset(LpChannel->aaRxUserData, 0x00, CANNM_MAX_PDU_INFO_LENGTH);
    CanNm_Memcpy(LpChannel->aaRxUserData, PduInfoPtr->SduDataPtr, PduInfoPtr->SduLength);
    LddRxHandlingMethod = CanNm_LocalGetRxHandlingMethod(LulCanNmChannelIndex, LpChannel->aaRxUserData);
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif
    
    if ((CANNM_RX_HANDLING_METHOD_PROCESS_WITH_PARTIAL_NETWORK == LddRxHandlingMethod) ||
        (CANNM_RX_HANDLING_METHOD_PROCESS_WITHOUT_PARTIAL_NETWORK == LddRxHandlingMethod))
    {
      #if (CANNM_GLOBALPNSUPPORT == STD_ON)
      if (CANNM_RX_HANDLING_METHOD_PROCESS_WITH_PARTIAL_NETWORK == LddRxHandlingMethod)
      {
        #if (CANNM_PNEIRACALCENABLED == STD_ON)
        CanNm_IntUpdateEIRA(LulCanNmChannelIndex, &PduInfoPtr->SduDataPtr[CanNm_GucPnInfoOffset]);
        #endif

        #if (CANNM_PNERACALCENABLED == STD_ON)
        CanNm_IntUpdateERA(LulCanNmChannelIndex, &PduInfoPtr->SduDataPtr[CanNm_GucPnInfoOffset]);
        #endif
      }
      #endif

      #if (CANNM_PDURXINDICATIONENABLED == STD_ON)
      Nm_PduRxIndication(LpStaticChannel->ddNmChannelHandle);
      #endif
      if (LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE)
      {
        CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_RX_INDICATION_SID, CANNM_E_NET_START_IND);
        Nm_NetworkStartIndication(LpStaticChannel->ddNmChannelHandle);
      }
      else if (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE)
      {
        CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);
      }
      else if ((LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) ||
               (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
               (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE))
      {
        if (CanNm_IntNmPduTxEnabled(LulCanNmChannelIndex) == CANNM_TRUE)
        {
          LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
          LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING;
        }
        #if (CANNM_NODEDETECTIONENABLED == STD_ON)
        if (((LpChannel->aaRxUserData[LpStaticChannel->ucPduCbvPosition]) & CANNM_REPTMSG_BIT) != 0U)
        {
          if ((LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) || (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE))
          {
            CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);
          }
          #if (CANNM_REPEATMSGINDENABLED == STD_ON)
          pfnNm_RepeatMessageIndication(LpStaticChannel->ddNmChannelHandle);
          #endif
        }
        #endif


		#if (CANNM_COORDINATORSYNCSUPPORT == STD_ON)

		/* #40502 [SWS_CanNm_00341] 
		* if received data of sleep bit is true(SET) and There has been no receiving of SET Sleep Ready Bit from NM Message,
		* and Network Mode, Invoke Nm_CoordReadyToSleepIndication() and set the flag of blNmCoordReadyToSleepIndicationCalled
		*/
        if ((((LpChannel->aaRxUserData[LpStaticChannel->ucPduCbvPosition]) & CANNM_SETSLEEP_BIT) != 0U))
        {
        	if (LpChannel->blNmCoordinatorSlpRdyBtMsgReceived == CANNM_FALSE){
        		if((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) ||
        				(LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
						(LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) ||
						(LpChannel->blNmCoordReadyToCancellationCalled == CANNM_TRUE)){
        			if(LpChannel->blNmCoordReadyToSleepIndicationCalled == CANNM_FALSE){
        				pfnNm_CoordReadyToSleepIndication(LpStaticChannel->ddNmChannelHandle);
        				LpChannel->blNmCoordReadyToSleepIndicationCalled = CANNM_TRUE;
        				LpChannel->blNmCoordReadyToCancellationCalled = CANNM_FALSE;

        			}
        		}
        	}
        	LpChannel->blNmCoordinatorSlpRdyBtMsgReceived = CANNM_TRUE;
        }
		/* end of #40502 [SWS_CanNm_00341] */
		
		/* #40502 [SWS_CanNm_00348]
		* if received data of sleep bit is false(UNSET) and There has been no receiving of UNSET Sleep Ready Bit from NM Message,
		* Invoke Nm_CoordReadyToSleepCancellation() and set the flag of blNmCoordReadyToCancellationCalled
        */
        else
        {
        	if (LpChannel->blNmCoordinatorSlpRdyBtMsgReceived == CANNM_TRUE){
        		if(((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) ||
        				(LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
						(LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE)) &&
						(LpChannel->blNmCoordReadyToSleepIndicationCalled == CANNM_TRUE)){
        			if(LpChannel->blNmCoordReadyToCancellationCalled == CANNM_FALSE){
        				pfnNm_CoordReadyToSleepCancellation(LpStaticChannel->ddNmChannelHandle);
        				LpChannel->blNmCoordReadyToSleepIndicationCalled = CANNM_FALSE;
        				LpChannel->blNmCoordReadyToCancellationCalled = CANNM_TRUE;

        			}
        		}
        	}
        	LpChannel->blNmCoordinatorSlpRdyBtMsgReceived = CANNM_FALSE;
        }
		/*end of #40502 [SWS_CanNm_00348] */
		#endif

        #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
		#if (CANNM_COMCONTROLENABLED == STD_ON)
        /* #40502 [SWS_CanNm_00175]
        If DisableCommunication State, CanNm should not detect the RemoteSleepInd. RemoteSleepCancellation detection too */
        if(LpChannel->blCommunicationEnabled == CANNM_TRUE)
        /* end of #40502 [SWS_CanNm_00175] */
        #endif
        {
			/* #40502 [SWS_CanNm_00150]
			* if receive the Nm message in Normal Operation State, CanNm should intialize the CanNmRemoteSleepIndTimer
			*/
			if(LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE)
			{
				LpChannel->ddRemoteSleepIndTime = LpStaticChannel->ddRemoteSleepIndTime;
			}
			/* end of #40502 [SWS_CanNm_00150] */

			if (LpChannel->blRemoteSlpDetect == CANNM_TRUE)
			{
				if ((LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) || (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE))
				{
					LpChannel->blRemoteSlpDetect = CANNM_FALSE;

					pfnNm_RemoteSleepCancellation(LpStaticChannel->ddNmChannelHandle);
				}
			}

		}
		#endif
      }
      else
      {
         ;
      }
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
}

/*******************************************************************************
** Function Name        : CanNm_ConfirmPnAvailability                         **
**                                                                            **
** Service ID           : 0x16                                                **
**                                                                            **
** Description          : Enables the PN filter functionality on the          **
**                                            indicated NM channel            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblGlobalPnSupport                            **
**                                                                            **
**                        Function(s) invoked   :                             **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_ConfirmPnAvailability(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
   #if (CANNM_GLOBALPNSUPPORT == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CONFIRM_PNAVAILABILITY_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CONFIRM_PNAVAILABILITY_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    /* Enable the PN algorithm for the channel */
    LpChannel->blPnStatusBit = CANNM_TRUE;
  }
  SchM_Exit_CanNm_INTERNAL_STATUS();
   #endif
}

/*******************************************************************************
** Function Name        : CanNm_TriggerTransmit                               **
**                                                                            **
** Service ID           : 0x41                                                **
**                                                                            **
** Description          : A blank function returning E_OK.                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant for different PduIds.                     **
**                        Non reentrant for the same PduId.                   **
**                                                                            **
** Input Parameters     : TxPduId, PduInfoPtr                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblComUserDataSupport                         **
**                        CanNm_GblPnEiraCalcEnabled                          **
**                        CanNm_GucPnInfoOffset                               **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_LocalGetCanNmChannelIndexFromCanNmTriggerTran **
**                        smitHandleId                                        **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntCollectTxData                              **
**                        CanNm_Memcpy                                        **
**                        CanNm_IntUpdateEIRA                                 **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
/* polyspace +3 MISRA2012:8.13 [Justified:Low] "This function definition follow Autosar requirement SWS_CANNM_91001. No impact" */
FUNC(Std_ReturnType, CANNM_CODE) CanNm_TriggerTransmit(
  PduIdType TxPduId,
  P2VAR(PduInfoType, AUTOMATIC, CANNM_VAR) PduInfoPtr)
{
  Std_ReturnType LddReturnType = E_NOT_OK;
  #if (CANNM_COMUSERDATASUPPORT == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus != CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRIGGER_TRANSMIT_SID, CANNM_E_UNINIT);
  }
  /* polyspace +1 MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
  else if ((PduInfoPtr == NULL_PTR) || (PduInfoPtr->SduDataPtr == NULL_PTR))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRIGGER_TRANSMIT_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_LocalGetCanNmChannelIndexFromCanNmTriggerTransmitHandleId(TxPduId, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRIGGER_TRANSMIT_SID, CANNM_E_INVALID_PDUID);
  }
  else
  {
    PduLengthType LucPduLength;

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif
    
    LucPduLength = LpStaticChannel->ucPduLength;

    if (LucPduLength <= PduInfoPtr->SduLength)
    {
      CanNm_IntCollectTxData(LulCanNmChannelIndex);

      PduInfoPtr->SduLength = LucPduLength;

      (void)CanNm_Memcpy(PduInfoPtr->SduDataPtr,
                         LpChannel->aaTxUserData,
                         LucPduLength);

      #if (CANNM_PNEIRACALCENABLED == STD_ON)
      CanNm_IntUpdateEIRA(LulCanNmChannelIndex, &LpChannel->aaTxUserData[CanNm_GucPnInfoOffset]);
      #endif
      LddReturnType = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #else
  CANNM_UNUSED(TxPduId);
  CANNM_UNUSED_PTR(PduInfoPtr);
  #endif
  return LddReturnType;
}

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/

