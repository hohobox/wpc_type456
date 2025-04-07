/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm_Internal.c                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : APIs implementation for CanNm module                          **
**              CanNm_IntCollectTxData                                        **
**              CanNm_IntGetChannelIndexFromTransmitHandleId                  **
**              CanNm_IntGetChannelIndexFromNmHandleId                        **
**              CanNm_IntUpdateERA                                            **
**              CanNm_IntUpdateEIRA                                           **
**              CanNm_IntRequestBusSleepMode                                  **
**              CanNm_IntRequestPrepareBusSleepMode                           **
**              CanNm_IntRequestReadySleepState                               **
**              CanNm_IntRequestNormalOperationState                          **
**              CanNm_IntRequestRepeatMessageState                            **
**              CanNm_IntTransmit                                             **
**              CanNm_IntCanIfTransmit                                        **
**              CanNm_IntDetReportError                                       **
**              CanNm_IntNmPduTxEnabled                                       **
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
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.3.0	 27-Apr-2022   Jaeho Yang        #35290                           **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.2.7.0   07-Oct-2022   Jaeho Yang        #37629                           **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   24-May-2023   SM Kwon           #40495                           **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CanNm APIs header */
#include "CanNm_Internal.h"       /* CanNm Internal functions header file */
#include "Det.h"                  /* DET header file */
#include "PduR_CanNm.h"           /* PduR Header File */
#include "CanIf.h"                /* CanIf Header File */
#include "SchM_CanNm.h"           /* Schedule Manager header */
#include "Nm_Cbk.h"               /* Nm Interface Call back function Header */
#include "CanSM.h"
#include "CanNm_Ram.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_INTERNAL_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_INTERNAL_C_AR_RELEASE_REVISION_VERSION 3

/* CanNm software version information */
#define CANNM_INTERNAL_C_SW_MAJOR_VERSION            2
#define CANNM_INTERNAL_C_SW_MINOR_VERSION            5
#define CANNM_INTERNAL_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm_Internal.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_INTERNAL_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm_Internal.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION != CANNM_INTERNAL_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm_Internal.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_INTERNAL_C_SW_MAJOR_VERSION)
#error "CanNm_Internal.c : Mismatch in Software Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_INTERNAL_C_SW_MINOR_VERSION)
#error "CanNm_Internal.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace-begin RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
#define CANNM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : CanNm_IntCollectTxData                              **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Update Tx Data                                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblComUserDataSupport                         **
**                        CanNm_GblNodeDetectionEnabled                       **
**                        CanNm_GblCoordinatorSyncSupport                     **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_Memcpy                                        **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntCollectTxData(uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  uint8 LaaTxUserData[CANNM_MAX_PN_INFO_LENGTH];
  #if (CANNM_COMUSERDATASUPPORT == STD_ON)
  PduInfoType LddUserDataPduInfo;
  #endif
  uint8 LucPduCbvPosition;
  uint8 LucPduNidPosition;
  uint8 LucPduNmStatePosition;
  uint8 LucPduNetworkRequestReasonPosition;
  NM_STATE nmState;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif

  LucPduCbvPosition = LpStaticChannel->ucPduCbvPosition;
  LucPduNidPosition = LpStaticChannel->ucPduNidPosition;
  LucPduNmStatePosition = LpStaticChannel->ucPduNmStatePosition;
  LucPduNetworkRequestReasonPosition = LpStaticChannel->ucPduNetworkRequestReasonPosition;
  nmState = LpChannel->ddNmState;
  #if (CANNM_COMUSERDATASUPPORT == STD_ON)
  /* Point the SduDataPtr to the user data address of the TxUserData array */
  LddUserDataPduInfo.SduDataPtr = LaaTxUserData;

  /* Copy the PduLength into the SduLength */
  LddUserDataPduInfo.SduLength = LpStaticChannel->ucUserDataLength;

  
  if (E_OK == PduR_CanNmTriggerTransmit(LpStaticChannel->ddPduRTriggerTransmitHandleId, &LddUserDataPduInfo))
  {
    uint8 LucDataArrayIndex;

    LucDataArrayIndex = LpStaticChannel->ucDataArrayIndex;

    if ((LddUserDataPduInfo.SduDataPtr != LaaTxUserData) || ((LucDataArrayIndex + LddUserDataPduInfo.SduLength) > CANNM_MAX_PDU_INFO_LENGTH))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRANSMIT_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      (void)CanNm_Memcpy(&(LpChannel->aaTxUserData[LucDataArrayIndex]),
                         LaaTxUserData,
                         LddUserDataPduInfo.SduLength);
    }
  }
  #endif
  #if (CANNM_NODEDETECTIONENABLED == STD_ON)
  /* Update the NodeId for the Channel */
  LpChannel->aaTxUserData[LucPduNidPosition] = LpStaticChannel->ucNodeId;
  #endif

  if (LpChannel->blTxRepeatMessageRequested == CANNM_TRUE)
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] | CANNM_REPTMSG_BIT;
  }
  else
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] & ~(CANNM_REPTMSG_BIT);
  }

  if ((LpChannel->blPnStatusBit == CANNM_TRUE) && (LpStaticChannel->blPnEnabled == CANNM_TRUE))
  {
    /* Update the CBV for the Channel to enable PN */
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] | CANNM_PNI_BIT;
  }
  else
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] & ~(CANNM_PNI_BIT);
  }

  if ((LpStaticChannel->blActiveWakeupBitEnabled == CANNM_TRUE) && (LpChannel->blTxActiveWakeUpBit == CANNM_TRUE))
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] | CANNM_ACTWKP_BIT;
  }
  else
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] & ~(CANNM_ACTWKP_BIT);
  }
  #if (CANNM_COORDINATORSYNCSUPPORT == STD_ON)
  if (LpChannel->blTxNmCoordinatorSleepReadyBit == CANNM_TRUE)
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] | CANNM_SETSLEEP_BIT;
  }
  else
  {
    LpChannel->aaTxUserData[LucPduCbvPosition]
      = LpChannel->aaTxUserData[LucPduCbvPosition] & ~(CANNM_SETSLEEP_BIT);
  }
  #endif

  #if (CANNM_STATE_POSITION_ENABLED == STD_ON)
  #if (CANNM_OPTIONAL_STATE_POSITION == STD_ON)
  if (LucPduNmStatePosition != (uint8)CANNM_PDU_OFF)
  #endif
  {
    if (nmState == NM_STATE_RMS_BSM)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x01u;
    }
    else if (nmState == NM_STATE_RMS_PBSM)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x02u;
    }
    else if (nmState == NM_STATE_NS_RMS)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x04u;
    }
    else if (nmState == NM_STATE_NS_RSS)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x08u;
    }
    else if (nmState == NM_STATE_RMS_RSS)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x10u;
    }
    else if (nmState == NM_STATE_RMS_NS)
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x20u;
    }
    else
    {
      LpChannel->aaTxUserData[LucPduNmStatePosition] = 0x00u;
    }
  }
  #endif

  #if (CANNM_REASON_POSITION_ENABLED == STD_ON)
  #if (CANNM_OPTIONAL_REASON_POSITION == STD_ON)
  if (LucPduNetworkRequestReasonPosition != (uint8)CANNM_PDU_OFF)
  #endif
  {
    LpChannel->aaTxUserData[LucPduNetworkRequestReasonPosition] = LpChannel->ucNetworkRequestReason;
  }
  #endif
}

/*******************************************************************************
** Function Name        : CanNm_InternalGetCanNmChannelIndexFromCanNmTransmit **
**                        HandleId                                            **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get CanNmChannelIndex                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : NmHandleId                                          **
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
**                        CanNm_GddNumberOfChannels                           **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntGetChannelIndexFromTransmitHandleId(
  PduIdType CanNmTransmitHandleId,
  P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulIndex;

  for (LulIndex = 0U; LulIndex < CanNm_GddNumberOfChannels; LulIndex++)
  {
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulIndex];
    #endif

    if (LpStaticChannel->ddCanNmTransmitHandleId == CanNmTransmitHandleId)
    {
      *CanNmChannelIndex = LulIndex;
      LddStdReturnValue = E_OK;
      break;
    }
  }

  return LddStdReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_IntGetChannelIndexFromNmHandleId              **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get CanNmChannelIndex                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : NmHandleId                                          **
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
**                        CanNm_GddNumberOfChannels                           **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntGetChannelIndexFromNmHandleId(
    NetworkHandleType NmHandleId,
    P2VAR(uint32, AUTOMATIC, CANNM_VAR) CanNmChannelIndex)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulIndex;

  for (LulIndex = 0U; LulIndex < CanNm_GddNumberOfChannels; LulIndex++)
  {
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulIndex];
    #endif

    if (LpStaticChannel->ddNmChannelHandle == NmHandleId)
    {
      *CanNmChannelIndex = LulIndex;
      LddStdReturnValue = E_OK;
      break;
    }
  }

  return LddStdReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_IntUpdateERA                                  **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Update ERA                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex, LaaPnInfo                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GucPnInfoLength                               **
**                        CanNm_GaaPnMaskByte                                 **
**                                                                            **
**                        Function(s) invoked:                                **
**                        PduR_CanNmRxIndication                              **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntUpdateERA(
  uint32 LulCanNmChannelIndex,
  P2CONST(uint8, AUTOMATIC, CANNM_CONST) LaaPnInfo)
{
  #if (CANNM_PNERACALCENABLED == STD_ON)
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif


  if (CANNM_TRUE == LpStaticChannel->blPnEraCalcEnabled)
  {
    boolean LblERAChange = CANNM_FALSE;
    uint8 LucIndex;

    /* Loop through all the PN bytes configured */
    for (LucIndex = 0U; LucIndex < CanNm_GucPnInfoLength; LucIndex++)
    {
      uint8 LucPrevERA;
      uint8 LucMask;

      /* Get the ERA array to local variable */
      LucPrevERA = LpChannel->aaERA[LucIndex];
      /* Take the PN mask byte into local variable */
      #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
      LucMask = CanNm_GpPnMaskByte[LucIndex];
      #else
      LucMask = CanNm_GaaPnMaskByte[LucIndex];
      #endif  

      if (0U != LucMask)
      {
        uint8 LucPnTimer;
        uint8 LucSetERA;

        /* check if PN enabled using the mask byte */
        LucSetERA = LaaPnInfo[LucIndex] & LucMask;

        /* Set the bits for which PN is enabled in the ERA array */
        LpChannel->aaERA[LucIndex] = LpChannel->aaERA[LucIndex] | LucSetERA;


        /* Loop through all the eight bits of each PN byte */
        for (LucPnTimer = 0U; LucPnTimer < 8U; LucPnTimer++)
        {
          if (0U != (LucSetERA & 1U))
          {
            P2VAR(CanNm_TimeType, AUTOMATIC, CANNM_VAR) LpTimer;

            /* Get the pointer to timer channel index */
            LpTimer = &LpChannel->aaERATimer[((uint16)LucIndex * 8) + (7 - (uint16)LucPnTimer)];

            /* Load the timer value for each bit that is set */
            *LpTimer = LpStaticChannel->ddPnResetTime;
          }

          LucSetERA = (LucSetERA >> 1U);
        }
      }

      /* Check if there's any change in the received PN data */
      if (LucPrevERA != LpChannel->aaERA[LucIndex])
      {
        /* Set the flag to indicate the change to upper layer */
        LblERAChange = CANNM_TRUE;
      }
    }

    /* Check if there is change in any byte of the received PN data */
    if (CANNM_TRUE == LblERAChange)
    {
      PduInfoType LddPnPduInfo;

      /* Assign the PDU Length */
      LddPnPduInfo.SduLength = CanNm_GucPnInfoLength;
      /* Assign the base address of the PDU */
      LddPnPduInfo.SduDataPtr = &LpChannel->aaERA[0U];

      /* Invoke the upper layer with the changed data */
      PduR_CanNmRxIndication(LpStaticChannel->ddPnEraRxNSduHandleId, &LddPnPduInfo);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : CanNm_IntUpdateEIRA                                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Update EIRA                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex, LaaPnInfo                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GucPnInfoLength                               **
**                        CanNm_GaaEIRA                                       **
**                        CanNm_GaaPnMaskByte                                 **
**                        CanNm_GaaPnEIRATimer                                **
**                        CanNm_PnEiraRxNSduHandleId                          **
**                                                                            **
**                        Function(s) invoked:                                **
**                        PduR_CanNmRxIndication                              **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntUpdateEIRA(
  uint32 LulCanNmChannelIndex,
  P2CONST(uint8, AUTOMATIC, CANNM_CONST) LaaPnInfo)
{
  uint8 LucIndex;
  boolean LblEIRAChange;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  /* Set the EIRA change value  */
  LblEIRAChange = CANNM_FALSE;

  /* Loop through all the PN bytes configured */
  for (LucIndex = 0U; LucIndex < CanNm_GucPnInfoLength; LucIndex++)
  {
    uint8 LucPrevEIRA;
    uint8 LucMask;
    SchM_Enter_CanNm_INTERNAL_STATUS();
    /* Get the EIRA array to local variable */
    LucPrevEIRA = CanNm_GaaEIRA[LucIndex];

    /* Take the PN mask byte into local variable */
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LucMask = CanNm_GpPnMaskByte[LucIndex];
    #else
    LucMask = CanNm_GaaPnMaskByte[LucIndex];
    #endif      

    /* Check if message contains Partial NW information */
    if (0U != LucMask)
    {
      uint8 LucPnTimer;
      uint8 LucSetEIRA;

      /* check if PN enabled using the mask byte */
      LucSetEIRA = LaaPnInfo[LucIndex] & LucMask;

      /* Set the bits for which PN is enabled in the EIRA array */
      CanNm_GaaEIRA[LucIndex] =  CanNm_GaaEIRA[LucIndex] | LucSetEIRA;

      /* Loop through all the eight bits of each PN byte */
      for (LucPnTimer = 0U; LucPnTimer < 8U; LucPnTimer++)
      {
        if (0U != (LucSetEIRA & 1U))
        {
          /* Check if any bit set */
          P2VAR(CanNm_TimeType, AUTOMATIC, CANNM_VAR) LpTimer;

          /* Get the pointer to timer channel index */
          LpTimer = &CanNm_GaaPnEIRATimer[((uint16)LucIndex * 8) + (7 - (uint16)LucPnTimer)];

          /* Load the timer value for each bit that is set */
          *LpTimer = LpStaticChannel->ddPnResetTime;
        }

        /* Check for the next bit */
        LucSetEIRA = (LucSetEIRA >> 1U);
      }
    }

    /* Check if there's any change in the received PN data */
    if (LucPrevEIRA != CanNm_GaaEIRA[LucIndex])
    {
      /* Set the flag in order to indicate the change to upper layer */
      LblEIRAChange = CANNM_TRUE;
    }
    SchM_Exit_CanNm_INTERNAL_STATUS();
  }

  /* Check if there is change in any byte of the received PN data */
  if (CANNM_TRUE == LblEIRAChange)
  {
    PduInfoType LddPduInfo;

    /* Assign the PDU Length */
    LddPduInfo.SduLength = CanNm_GucPnInfoLength;

    /* Assign the base address of the PDU */
    LddPduInfo.SduDataPtr = &CanNm_GaaEIRA[0U];

    /* Invoke the upper layer with the changed data */
    PduR_CanNmRxIndication(CanNm_PnEiraRxNSduHandleId, &LddPduInfo);
  }
}

/*******************************************************************************
** Function Name        : CanNm_IntRequestBusSleepMode                        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Request Bus Sleep Mode                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntRequestBusSleepMode(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  LpChannel->ddNextModeState = CANNM_BUS_SLEEP_MODE;
}

/*******************************************************************************
** Function Name        : CanNm_IntRequestPrepareBusSleepMode                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Request Prepare Bus Sleep Mode                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntRequestPrepareBusSleepMode(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  LpChannel->ddNextModeState = CANNM_PREPAREBUS_SLEEP_MODE;
}

/*******************************************************************************
** Function Name        : CanNm_IntRequestReadySleepState                     **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Request Ready Sleep State                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntRequestReadySleepState(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  LpChannel->ddNextModeState = CANNM_READY_SLEEP_STATE;
}

/*******************************************************************************
** Function Name        : CanNm_IntRequestNormalOperationState                **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Request Normal Operation State                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntRequestNormalOperationState(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  LpChannel->ddNextModeState = CANNM_NORMAL_OPERATION_STATE;
}

/*******************************************************************************
** Function Name        : CanNm_IntRequestRepeatMessageState                  **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Request Repeat Message State                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_IntRequestRepeatMessageState(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  LpChannel->ddNextModeState = CANNM_REPEAT_MESSAGE_STATE;
}

/*******************************************************************************
** Function Name        : CanNm_IntTransmit                                   **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Transmit NM Pdu                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        N/A                                                 **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntCanIfTransmit                              **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntTransmit(uint32 LulCanNmChannelIndex)
{
  Std_ReturnType LddResult;

  LddResult = CanNm_IntCanIfTransmit(LulCanNmChannelIndex);

  return LddResult;
}

/*******************************************************************************
** Function Name        : CanNm_IntCanIfTransmit                              **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Send NM Pdu                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblPnEiraCalcEnabled                          **
**                        CanNm_GucPnInfoOffset                               **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntCollectTxData                              **
**                        CanNm_IntUpdateEIRA                                 **
**                        CanIf_Transmit                                      **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_IntCanIfTransmit(
  uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  Std_ReturnType LddStdReturnValue = E_NOT_OK;

  PduInfoType LddPduInfoType;
  uint8 LaaTxData[CANNM_MAX_PDU_INFO_LENGTH];

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

  
  if ((LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE) && (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRANSMIT_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    SchM_Enter_CanNm_INTERNAL_STATUS();
    CanNm_IntCollectTxData(LulCanNmChannelIndex);

    (void)CanNm_Memcpy(LaaTxData,
                      LpChannel->aaTxUserData,
                      LpStaticChannel->ucPduLength);

    /* copy the PduLength into the SduLength */
    LddPduInfoType.SduLength = LpStaticChannel->ucPduLength;
    LddPduInfoType.SduDataPtr = LaaTxData;
    SchM_Exit_CanNm_INTERNAL_STATUS();
    #if (CANNM_PNEIRACALCENABLED == STD_ON)
    CanNm_IntUpdateEIRA(LulCanNmChannelIndex, &LpChannel->aaTxUserData[CanNm_GucPnInfoOffset]);
    #endif
    
    if (LpChannel->ddTxState == CANNM_TX_STATE_READY)
    {
      SchM_Enter_CanNm_INTERNAL_STATUS();
      if ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) && (LpChannel->ucNoOfImmediateNmTx > 1))
      {
        if (E_OK == CanIf_Transmit(LpStaticChannel->ddTxPduId, &LddPduInfoType))
        {
          LpChannel->ddTxState = CANNM_TX_STATE_WAIT_CONFIRM;
          LpChannel->ddMsgTimeOutTime = LpStaticChannel->ddImmMsgCycleTime;
          LddStdReturnValue = E_OK;
        }  
      }
      else
      {
        (void)CanIf_Transmit(LpStaticChannel->ddTxPduId, &LddPduInfoType);
        LpChannel->ddTxState = CANNM_TX_STATE_WAIT_CONFIRM;
        LpChannel->ddMsgTimeOutTime = LpStaticChannel->ddMsgTimeOutTime;
        LddStdReturnValue = E_OK;
      }
      SchM_Exit_CanNm_INTERNAL_STATUS();
    }
  }

  return (LddStdReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_IntDetReportError                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Report DET Error.                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ModuleId, InstanceId, ApiId, ErrorId                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblDevErrorDetect                             **
**                                                                            **
**                        Function(s) invoked:                                **
**                        Det_ReportError                                     **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_IntDetReportError(
  uint16 ModuleId, uint8 InstanceId, CANNM_SERVICE_ID ApiId, CANNM_ERROR_CODE ErrorId)
{
  /* DET */
  #if (CANNM_DEVERRORDETECT == STD_ON)
  (void)Det_ReportError(ModuleId, InstanceId, (uint8)ApiId, (uint8)ErrorId);
  #endif
}


/*******************************************************************************
** Function Name        : CanNm_IntNmPduTxEnabled                        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Check Nm Pdu Tx Enabled                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : N/a                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/
FUNC(boolean, CANNM_CODE) CanNm_IntNmPduTxEnabled(uint32 LulCanNmChannelIndex)
{
  boolean LblReturn = CANNM_FALSE;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->blCommunicationEnabled == CANNM_TRUE)
  {
    /* return */
    #if (CANNM_PASSIVEMODEENABLED == STD_OFF)
    LblReturn = CANNM_TRUE;
    #endif
  }
  else
  {
    ;
  }

  return LblReturn;
}


#define CANNM_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                          END OF FILE                                       **
*******************************************************************************/
