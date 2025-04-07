/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : APIs implementation for CanNm module                          **
**              CanNm_Init                                                    **
**              CanNm_DeInit                                                  **
**              CanNm_PassiveStartUp                                          **
**              CanNm_NetworkRequest                                          **
**              CanNm_NetworkRelease                                          **
**              CanNm_DisableCommunication                                    **
**              CanNm_DisableCommunication_TimerisNotStopped                  **
**              CanNm_EnableCommunication                                     **
**              CanNm_EnableCommunication_TimerisNotStarted                   **
**              CanNm_SetNetworkRequestReason                                 **
**              CanNm_GetNetworkRequestReason                                 **
**              CanNm_SetUserData                                             **
**              CanNm_GetUserData                                             **
**              CanNm_Transmit                                                **
**              CanNm_GetNodeIdentifier                                       **
**              CanNm_GetLocalNodeIdentifier                                  **
**              CanNm_RepeatMessageRequest                                    **
**              CanNm_GetPduData                                              **
**              CanNm_GetState                                                **
**              CanNm_GetVersionInfo                                          **
**              CanNm_RequestBusSynchronization                               **
**              CanNm_CheckRemoteSleepIndication                              **
**              CanNm_SetSleepReadyBit                                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                Description                      **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.1.0     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.1.0.1   27-Nov-2020   Sanghoon Kim      #25246                           **
** 2.1.1.0   28-Jan-2021   Sanghoon Kim      #28031                           **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.3.0.0   10-May-2022   Jaeho Yang        #35336                           **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.2.7.0   07-Oct-2022   Jaeho Yang        #37627, 37628                    **
** 2.2.8.0   13-Jan-2023   Jaeho Yang        #38291                           **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.3.1.0   24-May-2023   SM Kwon           #40495, 40496                    **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.4.1.0   02-Oct-2023   Jaeho Yang        #42234                           **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382                           **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CanNm API Header File */
#include "CanNm_Internal.h"       /* CanNm Internal Functions header file */

#include "Det.h"                  /* Det Header File */
#include "CanNm_Error.h"          /* Det Header File */

#include "SchM_CanNm.h"           /* Schedule Manager header file */
#include "Nm_Cbk.h"               /* NM CallBack Functions Header File */

#include "PduR_CanNm.h"           /* PduR Header File */

#include "CanIf.h"                /* CanIf Header File */

#include "Nm_Cfg.h"             /* Nm configuration header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_FUNC_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_FUNC_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_FUNC_C_AR_RELEASE_REVISION_VERSION 3

/* CanNm software version information */
#define CANNM_FUNC_C_SW_MAJOR_VERSION            2
#define CANNM_FUNC_C_SW_MINOR_VERSION            5
#define CANNM_FUNC_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_FUNC_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_FUNC_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION != CANNM_FUNC_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_FUNC_C_SW_MAJOR_VERSION)
#error "CanNm.c : Mismatch in Software Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_FUNC_C_SW_MINOR_VERSION)
#error "CanNm.c : Mismatch in Software Minor Version"
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
** Function Name        : CanNm_Init                                          **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Performs complete initialization of the CANNM       **
**                        Module.                                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : cannmConfigPtr                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        CanNm_GddNumberOfChannels                           **
**                        CanNm_GaaStaticChannel                              **
**                        CanNm_GaaChannel                                    **
**                        CanNm_GaaEIRA                                       **
**                        CanNm_GaaPnEIRATimer                                **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_Memset                                        **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_Init(
  CONSTP2CONST(CanNm_ConfigType, AUTOMATIC, CANNM_APPL_CONST) cannmConfigPtr)
{
  uint32 LulCanNmChannelIndex;
  uint32 LulIndex;
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  boolean LblNullPtr = CANNM_FALSE; 
  #endif

  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  if(NULL_PTR == cannmConfigPtr)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_INIT_SID, CANNM_E_PARAM_POINTER);
    LblNullPtr = CANNM_TRUE;
  }
  else
  {
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_NODEID)
    CanNm_GpStaticChannel = cannmConfigPtr->pCanNmStaticChannel;
    #else
    CanNm_GpStaticChannel = &CanNm_GaaStaticChannel[0];
    #endif

    #if(STD_ON == CANNM_VARIANT_POSTBUILD_PNFILTERMASK)
    CanNm_GpPnMaskByte = cannmConfigPtr->pCanNmPnFilterMaskByte;
    #else
    CanNm_GpPnMaskByte = &CanNm_GaaPnMaskByte[0];
    #endif
  }
  #else
  CANNM_UNUSED_PTR(cannmConfigPtr);
  #endif

  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  if(LblNullPtr == CANNM_FALSE)
  #endif
  {
    for (LulCanNmChannelIndex = 0; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
    {
      P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
      P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

      
      #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
      LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
      #else
      LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
      #endif

      LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

      LpChannel->ddRemoteSleepIndTime = 0;
      LpChannel->ddWaitBusSleepTime = 0;
      LpChannel->ddRepeatMessageTime = 0;
      LpChannel->ddNtwkTimeOutTime = 0;
      LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_STOPPED;
      LpChannel->ddMsgCycleTime = 0;
      LpChannel->ddMsgTimeOutTime = 0;

      CanNm_Memset(&LpChannel->aaRxUserData[0], 0, CANNM_MAX_PDU_INFO_LENGTH);
      CanNm_Memset(&LpChannel->aaTxUserData[0], 0, LpStaticChannel->ucDataArrayIndex);

      for (LulIndex = LpStaticChannel->ucDataArrayIndex; (uint8)LulIndex < (LpStaticChannel->ucDataArrayIndex + LpStaticChannel->ucUserDataLength); LulIndex++)
      {
        LpChannel->aaTxUserData[LulIndex] = LpStaticChannel->ucUserDataInitValue;
      }

      for (LulIndex = 0; LulIndex < CANNM_MAX_PN_INFO_LENGTH; LulIndex++)
      {
        LpChannel->aaERA[LulIndex] = 0u;
      }

      for (LulIndex = 0; LulIndex < CANNM_MAX_PN_INFO_LENGTH * 8; LulIndex++)
      {
        LpChannel->aaERATimer[LulIndex] = 0u;
      }

      /* Change the mode status to Bus sleep mode */
      LpChannel->ddModeStatus = CANNM_BUS_SLEEP_MODE;
      LpChannel->ddNextModeState = CANNM_BUS_SLEEP_MODE;
      LpChannel->ucNoOfImmediateNmTx = 0;

      LpChannel->blRemoteSlpDetect = CANNM_FALSE;
      #if (CANNM_FORCEPNAVAILABILITYCONFENABLED == STD_ON)
	  LpChannel->blPnStatusBit = CANNM_TRUE;
      #else
      LpChannel->blPnStatusBit = CANNM_FALSE;
      #endif
      LpChannel->blNetworkRequested = CANNM_FALSE;
      LpChannel->blTxRepeatMessageRequested = CANNM_FALSE;
      LpChannel->blCommunicationEnabled = CANNM_TRUE;
      LpChannel->blTxActiveWakeUpBit = CANNM_FALSE;
      LpChannel->blTxNmCoordinatorSleepReadyBit = CANNM_FALSE;
      LpChannel->blBusLoadReductionEnabled = CANNM_FALSE;
      LpChannel->blNmCoordReadyToSleepIndicationCalled = CANNM_FALSE;
      LpChannel->blTransmissionRequestFailed = CANNM_FALSE;
      LpChannel->ddTxState = CANNM_TX_STATE_READY;
      LpChannel->ddNmState = NM_STATE_UNDEFINED;
      LpChannel->ucNetworkRequestReason = 0x00u;
      /* #40502 Nm Coordinator Feature variables */
      LpChannel->blNmCoordinatorSlpRdyBtMsgReceived = CANNM_FALSE;
      LpChannel->blNmCoordReadyToCancellationCalled = CANNM_FALSE;
      /* end of #40502 Nm Coordinator Feature variables */
    }

    for (LulIndex = 0; LulIndex < CANNM_MAX_PN_INFO_LENGTH; LulIndex++)
    {
      CanNm_GaaEIRA[LulIndex] = 0u;
    }

    for (LulIndex = 0; LulIndex < CANNM_MAX_PN_INFO_LENGTH * 8; LulIndex++)
    {
      CanNm_GaaPnEIRATimer[LulIndex] = 0u;
    }

    /*Set the global init status to true*/
    CanNm_GblInitStatus = CANNM_TRUE;

	#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
	/* [Change Wait Bus Sleep Timer API]
     * Init CanNm_GulUserRequestTWaitBusSleepTime to CANNM_CHANGETWAITBUSSLEEPINVALID
     */
    CanNm_GulUserRequestTWaitBusSleepTime = CANNM_CHANGETWAITBUSSLEEPINVALID;
	#endif

  }
}

/*******************************************************************************
** Function Name        : CanNm_DeInit                                        **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Performs complete de-initialization of the CANNM    **
**                        Module.                                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GddNumberOfChannels                           **
**                        CanNm_GaaChannel                                    **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_DeInit(void)
{
  uint32 LulCanNmChannelIndex;
  boolean LblNotInBusSleep = CANNM_FALSE;

  if (CanNm_GblInitStatus != CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID,
                            CANNM_INSTANCE_ID,
                            CANNM_DEINIT_SID,
                            CANNM_E_INVALID_REQUEST);
  }

  for (LulCanNmChannelIndex = 0; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
  {
    P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if (LpChannel->ddModeStatus != CANNM_BUS_SLEEP_MODE)
    {
      LblNotInBusSleep = CANNM_TRUE;
    }
  }

  if (LblNotInBusSleep == CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID,
                            CANNM_INSTANCE_ID,
                            CANNM_DEINIT_SID,
                            CANNM_E_NOT_IN_BUS_SLEEP);
  }

  CanNm_GblInitStatus = CANNM_FALSE;

}

/*******************************************************************************
** Function Name        : CanNm_PassiveStartUp                                **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : Triggers the transition from Bus-Sleep Mode to the  **
**                        Network Mode in Repeat Message State.               **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestRepeatMessageState                  **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_PassiveStartUp(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_PASSIVE_STARTUP_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_PASSIVE_STARTUP_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if ((LpChannel->ddModeStatus != CANNM_BUS_SLEEP_MODE) &&
           (LpChannel->ddModeStatus != CANNM_PREPAREBUS_SLEEP_MODE))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_PASSIVE_STARTUP_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);
      LddReturnValue = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_NetworkRequest                                **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : Request the network, since ECU needs to communicate **
**                        on the bus. Network state shall be changed to       **
**                       'requested'.                                         **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same channel)             **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestRepeatMessageState                  **
**                        CanNm_IntRequestNormalOperationState                **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRequest(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_NETWORK_REQUEST_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_NETWORK_REQUEST_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if (CANNM_PASSIVEMODEENABLED == STD_OFF)
    #if (((CANNM_MULTIPLE_REQUEST_ENABLED == STD_ON) && (CANNM_OPTIONAL_MULTIPLE_REQUEST == STD_ON)) ||  \
         ((CANNM_ACTIVE_WAKEUP_ENABLED == STD_ON) && (CANNM_OPTIONAL_ACTIVE_WAKEUP == STD_ON)))

    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    #endif

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    #if (CANNM_MULTIPLE_REQUEST_ENABLED == STD_ON)
    #if (CANNM_OPTIONAL_MULTIPLE_REQUEST == STD_ON)
    if (LpStaticChannel->blPnHandleMultipleNetworkRequests == TRUE)
    #endif
    {
      if ((LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) ||
          (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
          (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE))
      {
        CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);
      }
    }
    #else
      if ((LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE) ||
      ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) && (LpChannel->ddRepeatMessageTime == 0)) ||
      ((LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) && (LpChannel->ddNextModeState == CANNM_READY_SLEEP_STATE)))
      {
        CanNm_IntRequestNormalOperationState(LulCanNmChannelIndex);
      }
    #endif

    if ((LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE) ||
        (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE))
    {
      CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);

      #if (CANNM_ACTIVE_WAKEUP_ENABLED == STD_ON)
      #if (CANNM_OPTIONAL_ACTIVE_WAKEUP == STD_ON)
      if (LpStaticChannel->blActiveWakeupBitEnabled == CANNM_TRUE)
      #endif
      {
        LpChannel->blTxActiveWakeUpBit = CANNM_TRUE;
      }
      #endif
    }
    /* Set the network request bit */
    LpChannel->blNetworkRequested = CANNM_TRUE;

    LddReturnValue = E_OK;
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return (LddReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_NetworkRelease                                **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : Release the network, since ECU does not have to     **
**                        communicate on the bus.Network state shall be       **
**                        changed to 'released'.                              **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same channel)             **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestReadySleepState                     **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_NetworkRelease(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  uint32 LulCanNmChannelIndex = 0;
  Std_ReturnType LddResult = E_NOT_OK;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();
  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_NETWORK_RELEASE_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_NETWORK_RELEASE_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if (CANNM_PASSIVEMODEENABLED == STD_OFF)
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    if ((LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) || (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE))
    {
      /* Set the network request bit */
      LpChannel->blNetworkRequested = CANNM_FALSE;
      if ((LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
      ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) && (LpChannel->ddRepeatMessageTime == 0)))
      {
        CanNm_IntRequestReadySleepState(LulCanNmChannelIndex);
      }
      LddResult = E_OK;
    }
    else
    {
      LddResult = E_NOT_OK;
    }
    #endif
  }
  SchM_Exit_CanNm_INTERNAL_STATUS();
  return LddResult;
}

/*******************************************************************************
** Function Name        : CanNm_DisableCommunication                          **
**                                                                            **
** Service ID           : 0x0C                                                **
**                                                                            **
** Description          : Disables the NM PDU transmission ability.           **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same NM-Channel)          **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblComControlEnabled                          **
**                        CanNm_GblPassiveModeEnabled                         **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        Nm_RemoteSleepCancellation                          **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication(
                      CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  uint32 LulCanNmChannelIndex = 0;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_COMCONTROLENABLED == STD_ON))
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if (LpChannel->blCommunicationEnabled == CANNM_FALSE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else if ((LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE) &&
            (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE) &&
            (LpChannel->ddModeStatus != CANNM_READY_SLEEP_STATE))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      LpChannel->blCommunicationEnabled = CANNM_FALSE;

      /* Stop the Network Timeout Timer */
      LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_STOPPED;

      LpChannel->blTransmissionRequestFailed = CANNM_FALSE;

      #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
      if (LpChannel->blRemoteSlpDetect == CANNM_TRUE)
      {
        P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
        
        #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
        LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
        #else
        LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
        #endif

        LpChannel->blRemoteSlpDetect = CANNM_FALSE;
        pfnNm_RemoteSleepCancellation(LpStaticChannel->ddNmChannelHandle);
      }

      /* Stop the Remote Sleep Timeout */
      LpChannel->ddRemoteSleepIndTime = 0U;
      #endif

      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return (LddReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_DisableCommunication_TimerisNotStopped        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Disables the NM PDU transmission ability.           **
**                        (Don't stop network timeout timer)                  **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same NM-Channel)          **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblComControlEnabled                          **
**                        CanNm_GblPassiveModeEnabled                         **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        Nm_RemoteSleepCancellation                          **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_DisableCommunication_TimerisNotStopped(
                      CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  uint32 LulCanNmChannelIndex = 0;
  Std_ReturnType LddReturnValue = E_NOT_OK;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_COMCONTROLENABLED == STD_ON))
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if (LpChannel->blCommunicationEnabled == CANNM_FALSE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_DISABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      LpChannel->blCommunicationEnabled = CANNM_FALSE;
      LpChannel->blTransmissionRequestFailed = CANNM_FALSE;

      #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
      if (LpChannel->blRemoteSlpDetect == CANNM_TRUE)
      {
        P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
        
        #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
        LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
        #else
        LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
        #endif

        LpChannel->blRemoteSlpDetect = CANNM_FALSE;
        pfnNm_RemoteSleepCancellation(LpStaticChannel->ddNmChannelHandle);
      }

      /* Stop the Remote Sleep Timeout */
      LpChannel->ddRemoteSleepIndTime = 0U;
      #endif

      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return (LddReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_EnableCommunication                           **
**                                                                            **
** Service ID           : 0x0D                                                **
**                                                                            **
** Description          : Enables the NM PDU transmission ability.            **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same NM-Channel)          **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblComControlEnabled                          **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication(
                      CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  volatile Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_COMCONTROLENABLED == STD_ON))
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    if ((LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE) &&
           (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE) &&
           (LpChannel->ddModeStatus != CANNM_READY_SLEEP_STATE))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else if (LpChannel->blCommunicationEnabled == CANNM_TRUE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      /* Start the Network Timeout */
      LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
      LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING;

      #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
      /* Start the Remote Sleep Timeout */
      LpChannel->ddRemoteSleepIndTime = LpStaticChannel->ddRemoteSleepIndTime;
      #endif

      /* Enable the transmission of NM PDUS */
      LpChannel->blCommunicationEnabled = CANNM_TRUE;

      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_EnableCommunication_TimerisNotStarted         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Enables the NM PDU transmission ability.            **
**                        (Don't start network timeout timer)                 **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same NM-Channel)          **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblComControlEnabled                          **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_EnableCommunication_TimerisNotStarted(
                      CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle)
{
  volatile Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_COMCONTROLENABLED == STD_ON))
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if (LpChannel->blCommunicationEnabled == CANNM_TRUE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_ENABLE_COMMUNICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
      /* Start the Remote Sleep Timeout */
      P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
      
      #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
      LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
      #else
      LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
      #endif

      LpChannel->ddRemoteSleepIndTime = LpStaticChannel->ddRemoteSleepIndTime;
      #endif

      /* Enable the transmission of NM PDUS */
      LpChannel->blCommunicationEnabled = CANNM_TRUE;

      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_SetNetworkRequestReason                       **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : Sets Network Request Reason Data for NM messages    **
**                        transmitted next on the bus.                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle, nmNetworkRequestReason             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblUserDataEnabled                            **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetNetworkRequestReason(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONST(uint8, CANNM_APPL_CONST) nmNetworkRequestReason)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_REASON_POSITION_ENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_USERDATAENABLED == STD_ON) && (CANNM_PASSIVEMODEENABLED == STD_OFF))
    #if (CANNM_OPTIONAL_REASON_POSITION == STD_ON)
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    if ((uint8)CANNM_PDU_OFF == LpStaticChannel->ucPduNetworkRequestReasonPosition)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    #endif
    {
      LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
      LpChannel->ucNetworkRequestReason = nmNetworkRequestReason;
      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif
  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetNetworkRequestReason                       **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : Gets the user data out of the most recently received**
**                        NM message.                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmUserDataPtr                                       **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblUserDataEnabled                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetNetworkRequestReason(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) pNmNetworkRequestReason)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;

  #if (CANNM_REASON_POSITION_ENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_CONST) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_USERDATA_SID, CANNM_E_UNINIT);
  }
  else if (pNmNetworkRequestReason == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if (CANNM_USERDATAENABLED == STD_ON)
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    #if (CANNM_OPTIONAL_REASON_POSITION == STD_ON)
    if ((uint8)CANNM_PDU_OFF == LpStaticChannel->ucPduNetworkRequestReasonPosition)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    #endif
    {
      uint8 LucPduNetworkRequestReasonPosition = LpStaticChannel->ucPduNetworkRequestReasonPosition;
      /* polyspace +1 MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
      *pNmNetworkRequestReason = LpChannel->aaRxUserData[LucPduNetworkRequestReasonPosition];

      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif
  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_SetUserData                                   **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : Sets user data for NM messages transmitted next on  **
**                        the bus.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle, nmUserDataPtr                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblUserDataEnabled                            **
**                        CanNm_GblPassiveModeEnabled                         **
**                        CanNm_GblComUserDataSupport                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_Memcpy                                        **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetUserData(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2CONST(uint8, AUTOMATIC, CANNM_APPL_CONST) nmUserDataPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_UNINIT);
  }
  else if (nmUserDataPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_USERDATA_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_USERDATAENABLED == STD_ON) && (CANNM_PASSIVEMODEENABLED == STD_OFF))
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    /* Copy the data in Tx Buffer */
    /* polyspace +1 MISRA-C3:D4.11, RTE:STD_LIB [Not a defect: Justify with annotations] "Valid arguments are passed" */
    CanNm_Memcpy(&(LpChannel->aaTxUserData[LpStaticChannel->ucDataArrayIndex]),
                 nmUserDataPtr,
                 LpStaticChannel->ucUserDataLength);

    LddReturnValue = E_OK;
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetUserData                                   **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : Gets the user data out of the most recently received**
**                        NM message.                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmUserDataPtr                                       **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblUserDataEnabled                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_Memcpy                                        **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetUserData(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmUserDataPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_CONST) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_USERDATA_SID, CANNM_E_UNINIT);
  }
  else if (nmUserDataPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_USERDATA_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_USERDATA_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if (CANNM_USERDATAENABLED == STD_ON)
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    /* Copy the User data from Rx User Data array into nmUser data Pointer */
    /* polyspace +1 MISRA-C3:D4.11, RTE:STD_LIB [Not a defect: Justify with annotations] "Valid arguments are passed" */
    CanNm_Memcpy(nmUserDataPtr,
                 &(LpChannel->aaRxUserData[LpStaticChannel->ucDataArrayIndex]),
                 LpStaticChannel->ucUserDataLength);

    LddReturnValue = E_OK;
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_Transmit                                      **
**                                                                            **
** Service ID           : 0x14                                                **
**                                                                            **
** Description          : Request Transmit Nm PDU                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant(but not for the same NM-channel)         **
**                                                                            **
** Input Parameters     : CanTxPduId, PduInfoPtr                              **
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
**                        CanNm_GblPnEnabled                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntGetChannelIndexFromTransmitHandleId        **
**                        CanNm_IntDetReportErro                              **
**                        CanNm_IntCanIfTransmit                              **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_Transmit(
  PduIdType CanTxPduId,
  P2CONST(PduInfoType, AUTOMATIC, CANNM_APPL_CONST) PduInfoPtr)
{
  Std_ReturnType LddStdReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus != CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRANSMIT_SID, CANNM_E_UNINIT);
  }
  else if (PduInfoPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRANSMIT_SID, CANNM_E_PARAM_POINTER);
  }
  else if (CanNm_IntGetChannelIndexFromTransmitHandleId(CanTxPduId, &LulCanNmChannelIndex) != E_OK)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_TRANSMIT_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    #if ((CANNM_COMUSERDATASUPPORT == STD_ON) || (CANNM_PNENABLED == STD_ON))
    LddStdReturnValue = CanNm_IntCanIfTransmit(LulCanNmChannelIndex);
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return (LddStdReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_GetNodeIdentifier                             **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : Get node identifier out of the most recently        **
**                        received NM message.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmNodeIdPtr                                         **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetNodeIdentifier(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle,
  CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;

  #if (CANNM_NODE_ID_ENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_NODEIDENTIFIER_SID, CANNM_E_UNINIT);
  }
  else if (nmNodeIdPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_NODEIDENTIFIER_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_NODEIDENTIFIER_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    #if (CANNM_OPTIONAL_NODE_ID == STD_ON)
    if (LpStaticChannel->blNodeIdEnabled == CANNM_FALSE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_NODEIDENTIFIER_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    #endif
    {
      P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
      LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
      /* Update the nmNodeIdPtr */
      /* polyspace +1 MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
      *nmNodeIdPtr = LpChannel->aaRxUserData[LpStaticChannel->ucPduNidPosition];
      LddReturnValue = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetLocalNodeIdentifier                        **
**                                                                            **
** Service ID           : 0x07                                                **
**                                                                            **
** Description          : Get node identifier configured for the local node.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmNodeIdPtr                                         **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm is  initialized correctly                     **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetLocalNodeIdentifier(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmNodeIdPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_NODE_ID_ENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_LOCALNODEIDENTIFIER_SID, CANNM_E_UNINIT);
  }
  else if (nmNodeIdPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_LOCALNODEIDENTIFIER_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_LOCALNODEIDENTIFIER_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    #if (CANNM_OPTIONAL_NODE_ID == STD_ON)
    if (LpStaticChannel->blNodeIdEnabled == CANNM_FALSE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_LOCALNODEIDENTIFIER_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    #endif
    {
      /* Update the nmNodeIdPtr */
      /* polyspace +1 MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
      *nmNodeIdPtr = LpStaticChannel->ucNodeId;
      LddReturnValue = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif
  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_RepeatMessageRequest                          **
**                                                                            **
** Service ID           : 0x08                                                **
**                                                                            **
** Description          : Sets Repeat Message Request bit for NM Message      **
**                        transmitted next on the bus.                        **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Reentrant (But not within the same channel)         **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblNodeDetectionEnabled                       **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestRepeatMessageState                  **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_RepeatMessageRequest(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_NODEDETECTIONENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REPEAT_MESSAGEREQUEST_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REPEAT_MESSAGEREQUEST_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if ((LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
        (LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE))
    {
      CanNm_IntRequestRepeatMessageState(LulCanNmChannelIndex);

      /* Set the repeat message request bit of statusbits */
      LpChannel->blTxRepeatMessageRequested = CANNM_TRUE;

      LddReturnValue = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #endif
  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetPduData                                    **
**                                                                            **
** Service ID           : 0x0A                                                **
**                                                                            **
** Description          : Get the whole PDU data out of the most recently     **
**                        received NM message.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmPduDataPtr                                        **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm and the CanIf itself are initialized correctly**
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblNodeDetectionEnabled                       **
**                        CanNm_GblUserDataEnabled                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntGetChannelIndexFromNmHandleId              **
**                        CanNm_IntDetReportError                             **
**                        CanNm_Memcpy                                        **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetPduData(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2VAR(uint8, AUTOMATIC, CANNM_APPL_DATA) nmPduDataPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_NODE_ID_ENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_PDUDATA_SID, CANNM_E_UNINIT);
  }
  else if (nmPduDataPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_PDUDATA_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_PDUDATA_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    #if ((CANNM_NODEDETECTIONENABLED == STD_ON) || (CANNM_USERDATAENABLED == STD_ON))
    #if (CANNM_OPTIONAL_NODE_ID == STD_ON)
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    if (LpStaticChannel->blNodeIdEnabled != CANNM_TRUE)
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_PDUDATA_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    #endif
    {
      P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
      LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
      CanNm_Memcpy(nmPduDataPtr, LpChannel->aaRxUserData, sizeof(LpChannel->aaRxUserData));
      LddReturnValue = E_OK;
    }
    #endif
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  #endif

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetState                                      **
**                                                                            **
** Service ID           : 0x0B                                                **
**                                                                            **
** Description          : Returns the current state and mode of the network   **
**                        management.                                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmStatePtr, nmModePtr                               **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/

FUNC(Std_ReturnType, CANNM_CODE) CanNm_GetState(
  CONST(NetworkHandleType, CANNM_APPL_CONST)nmChannelHandle,
  CONSTP2VAR(Nm_StateType, AUTOMATIC, CANNM_APPL_DATA) nmStatePtr,
  CONSTP2VAR(Nm_ModeType, AUTOMATIC, CANNM_APPL_DATA) nmModePtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_STATE_SID, CANNM_E_UNINIT);
  }
  else if ((nmStatePtr == NULL_PTR) || (nmModePtr == NULL_PTR))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_STATE_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_STATE_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    /* Set the equivalent NM mode */
    switch (LpChannel->ddModeStatus)
    {
      /* polyspace-begin MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
      case CANNM_BUS_SLEEP_MODE:
        *nmModePtr = NM_MODE_BUS_SLEEP;
        *nmStatePtr = NM_STATE_BUS_SLEEP;
        LddReturnValue = E_OK;
        break;

      case CANNM_PREPAREBUS_SLEEP_MODE:
        *nmModePtr = NM_MODE_PREPARE_BUS_SLEEP;
        *nmStatePtr = NM_STATE_PREPARE_BUS_SLEEP;
        LddReturnValue = E_OK;
        break;

      case CANNM_READY_SLEEP_STATE:
        *nmModePtr = NM_MODE_NETWORK;
        *nmStatePtr = NM_STATE_READY_SLEEP;
        LddReturnValue = E_OK;
        break;

      case CANNM_NORMAL_OPERATION_STATE:
        *nmModePtr = NM_MODE_NETWORK;
        *nmStatePtr = NM_STATE_NORMAL_OPERATION;
        LddReturnValue = E_OK;
        break;

      case CANNM_REPEAT_MESSAGE_STATE:
        *nmModePtr = NM_MODE_NETWORK;
        *nmStatePtr = NM_STATE_REPEAT_MESSAGE;
        LddReturnValue = E_OK;
        break;

      default:
        CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_STATE_SID, CANNM_E_INVALID_REQUEST);
        break;
      /* polyspace-end MISRA-C3:D4.14 [Justified:Low] "No Impact of this rule violation" */
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();

  return LddReturnValue;
}

/*******************************************************************************
** Function Name        : CanNm_GetVersionInfo                                **
**                                                                            **
** Service ID           : 0xF1                                                **
**                                                                            **
** Description          : Returns the version information of the module.      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : versioninfo                                         **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        CanNm_GblInitStatus                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

FUNC(void, CANNM_CODE) CanNm_GetVersionInfo(

  P2VAR(Std_VersionInfoType, AUTOMATIC, CANNM_APPL_DATA) cannmVersioninfo)
{
  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_VERSIONINFO_SID, CANNM_E_UNINIT);
  }
  else if (cannmVersioninfo == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_GET_VERSIONINFO_SID, CANNM_E_PARAM_POINTER);
  }
  else
  {
		/* polyspace-begin MISRA-C3:D4.14 [Not a defect: Justify with annotations] "Pointer is not a NULL and valid" */
    /* Copy the vendor Id */
    cannmVersioninfo->vendorID = CANNM_VENDOR_ID;
    /* Copy the module Id */
    cannmVersioninfo->moduleID = CANNM_MODULE_ID;
    /* Copy Software Major Version */
    cannmVersioninfo->sw_major_version = (uint8)CANNM_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    cannmVersioninfo->sw_minor_version = (uint8)CANNM_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    cannmVersioninfo->sw_patch_version = (uint8)CANNM_SW_PATCH_VERSION;
		/* polyspace-end MISRA-C3:D4.14 [Not a defect: Justify with annotations] "Pointer is not a NULL and valid" */
  }
}

/*******************************************************************************
** Function Name        : CanNm_RequestBusSynchronization                     **
**                                                                            **
** Service ID           : 0xC0                                                **
**                                                                            **
** Description          : Request the Bus Synchronization                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant (But not within the same channel)         **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblPassiveModeEnabled                         **
**                        CanNm_GblBusSynchronizationEnabled                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntNmPduTxEnabled                             **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntTransmit                                   **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_RequestBusSynchronization(
  VAR(NetworkHandleType, CANNM_VAR) nmChannelHandle)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if ((CANNM_PASSIVEMODEENABLED == STD_OFF) && (CANNM_BUSSYNCHRONIZATIONENABLED == STD_ON))
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus != CANNM_TRUE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REQUEST_BUSSYNCHRONIZATION_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REQUEST_BUSSYNCHRONIZATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else if (CanNm_IntNmPduTxEnabled(LulCanNmChannelIndex) == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REQUEST_BUSSYNCHRONIZATION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if ((LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE) || (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_REQUEST_BUSSYNCHRONIZATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      LddReturnValue = CanNm_IntTransmit(LulCanNmChannelIndex);
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #else
  CANNM_UNUSED(nmChannelHandle);
  #endif
  return (LddReturnValue);
}

/*******************************************************************************
** Function Name        : CanNm_CheckRemoteSleepIndication                    **
**                                                                            **
** Service ID           : 0xD0                                                **
**                                                                            **
** Description          : Checks if remote sleep indication has taken place or**
**                        not.                                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant(but not for the same NM-Channel)          **
**                                                                            **
** Input Parameters     : nmChannelHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmRemoteSleepIndPtr                                 **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
/* polyspace-begin MISRA2012:8.13 [Justified:Low] "AUTOSAR AR40 Parameter Type is CONSTP2VAR -SWS_CanNm_00227-" */
FUNC(Std_ReturnType, CANNM_CODE) CanNm_CheckRemoteSleepIndication(
  CONST(NetworkHandleType, CANNM_APPL_CONST) nmChannelHandle,
  CONSTP2VAR(boolean, AUTOMATIC, CANNM_APPL_DATA) nmRemoteSleepIndPtr)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CHECK_REMOTESLEEPINDICATION_SID, CANNM_E_UNINIT);
  }
  else if (nmRemoteSleepIndPtr == NULL_PTR)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CHECK_REMOTESLEEPINDICATION_SID, CANNM_E_PARAM_POINTER);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CHECK_REMOTESLEEPINDICATION_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    if ((LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE) ||
           (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE) ||
           (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE))
    {
      CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_CHECK_REMOTESLEEPINDICATION_SID, CANNM_E_INVALID_REQUEST);
    }
    else
    {
      *nmRemoteSleepIndPtr = LpChannel->blRemoteSlpDetect;
      LddReturnValue = E_OK;
    }
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
  #else
  CANNM_UNUSED(nmChannelHandle);
  CANNM_UNUSED_PTR(nmRemoteSleepIndPtr);
  #endif

  return LddReturnValue;
}
/* polyspace-end MISRA2012:8.13 [Justified:Low] "AUTOSAR AR40 Parameter Type is CONSTP2VAR -SWS_CanNm_00227-" */

/*******************************************************************************
** Function Name        : CanNm_SetSleepReadyBit                              **
**                                                                            **
** Service ID           : 0x17                                                **
**                                                                            **
** Description          : Set the NM Coordinator Sleep Ready bit              **
**                                              in the Control Bit Vector     **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non reentrant                                       **
**                                                                            **
** Input Parameters     : nmChannelHandle, nmSleepReadyBit                    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GblCoordinatorSyncSupport                     **
**                                                                            **
**                        Function(s) invoked   :                             **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntTransmit                                   **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
*******************************************************************************/
FUNC(Std_ReturnType, CANNM_CODE) CanNm_SetSleepReadyBit(
  VAR(NetworkHandleType,CANNM_VAR) nmChannelHandle,
  VAR(boolean,CANNM_VAR) nmSleepReadyBit)
{
  Std_ReturnType LddReturnValue = E_NOT_OK;
  #if (CANNM_COORDINATORSYNCSUPPORT == STD_ON)
  uint32 LulCanNmChannelIndex = 0;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_CONST) LpChannel;
  PduInfoType LddPduInfoType;
  uint8 LaaTxData[CANNM_MAX_PDU_INFO_LENGTH];

  SchM_Enter_CanNm_INTERNAL_STATUS();

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_SLEEP_READYBIT_SID, CANNM_E_UNINIT);
  }
  else if (E_OK != CanNm_IntGetChannelIndexFromNmHandleId(nmChannelHandle, &LulCanNmChannelIndex))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_SET_SLEEP_READYBIT_SID, CANNM_E_INVALID_CHANNEL);
  }
  else
  {
	  /* #40502 [SWS_Nm_00267] 
	  * CanNm_SetSleepReadyBit() shall be called to UNSET if Shutdown is aborted 
	  */
	  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

      LpChannel->blTxNmCoordinatorSleepReadyBit = nmSleepReadyBit;

	  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
	    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
	  #else
	    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
	  #endif

	  /* CanNm_IntCollectionTxData() will apply the Nm message bit set by checking the blTxNmCoordinatorSleepReadyBit for channel */
	  CanNm_IntCollectTxData(LulCanNmChannelIndex);

	  (void) CanNm_Memcpy(LaaTxData, LpChannel->aaTxUserData,
	  LpStaticChannel->ucPduLength);

	  /* copy the PduLength into the SduLength */
	  LddPduInfoType.SduLength = LpStaticChannel->ucPduLength;
	  LddPduInfoType.SduDataPtr = LaaTxData;

	  if (E_OK != CanIf_Transmit(LpStaticChannel->ddTxPduId,&LddPduInfoType))
	  {
		  LpChannel->blTransmissionRequestFailed = CANNM_TRUE;
	  }else {
		  LddReturnValue = E_OK;
	  }
      /* end of #40502 [SWS_Nm_00267] */
  }

  SchM_Exit_CanNm_INTERNAL_STATUS();
	  
  #else
  CANNM_UNUSED(nmChannelHandle);
  CANNM_UNUSED(nmSleepReadyBit);
  #endif

  return LddReturnValue;
}

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
