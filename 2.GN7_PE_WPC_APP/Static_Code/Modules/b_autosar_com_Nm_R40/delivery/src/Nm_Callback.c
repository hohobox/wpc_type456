/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Nm_Callback.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Nm Module                                             **
**                                                                            **
**  PURPOSE   : This file provides definitions of Callback APIs, meant for    **
**              notification received  from respective BusNms                 **
**              Nm_PduRxIndication                                            **
**              Nm_StateChangeNotification                                    **
**              Nm_RepeatMessageIndication                                    **
**              Nm_TxTimeoutException                                         **
**              Nm_CarWakeUpIndication                                        **
**              Nm_CoordReadyToSleepIndication                                **
**              Nm_CoordReadyToSleepCancellation                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision      Date         By         Description                          **
********************************************************************************
** 2.4.0     12-Sep-2023   JH Jang       #38995, #42732                       **
** 2.3.0     30-Nov-2020   HM Shin       #26864                               **
** 2.2.1     23-Jan-2018   JeongSu Lim   #15692                               **
** 2.2.0     28-Dec-2018   JeongSu Lim   #13630, #15277, #15276, #15275,      **
**                                       #15274                               **
** 1.0.3     17-May-2016   Kt Kim        #5954                                **
** 1.0.2     17-May-2016   Kt Kim        #4641                                **
** 1.0.1     24-Aug-2015   Kt Kim        #3000                                **
** 1.0.0     10-Apr-2013   Kt Kim        Initial vsersion                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm_Cbk.h" /* Inclusion for declaration of callback functions */
#include "Nm_Ram.h" /*  For global variables */
#include "Nm_PCTypes.h"
#include "Nm_Internal.h"
/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/
/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define NM_CALLBACK_C_AR_RELEASE_MAJOR_VERSION     (4)
#define NM_CALLBACK_C_AR_RELEASE_MINOR_VERSION     (0)
#define NM_CALLBACK_C_AR_RELEASE_REVISION_VERSION  (3)

/* Software Version Information */
#define NM_CALLBACK_C_SW_MAJOR_VERSION  (2)
#define NM_CALLBACK_C_SW_MINOR_VERSION  (5)

/*******************************************************************************
**                        V E R S I O N      C H E C K                        **
*******************************************************************************/
#if (NM_AR_RELEASE_MAJOR_VERSION != NM_CALLBACK_C_AR_RELEASE_MAJOR_VERSION)
  #error "Nm_Callback.c : Mismatch in Specification Major Version"
#endif

#if (NM_AR_RELEASE_MINOR_VERSION != NM_CALLBACK_C_AR_RELEASE_MINOR_VERSION)
  #error "Nm_Callback.c : Mismatch in Specification Minor Version"
#endif

#if (NM_AR_RELEASE_REVISION_VERSION != NM_CALLBACK_C_AR_RELEASE_REVISION_VERSION)
  #error "Nm_Callback.c : Mismatch in Specification Revision Version"
#endif

#if (NM_SW_MAJOR_VERSION != NM_CALLBACK_C_SW_MAJOR_VERSION)
  #error "Nm_Callback.c : Mismatch in Software Major Version"
#endif

#if (NM_SW_MINOR_VERSION != NM_CALLBACK_C_SW_MINOR_VERSION)
  #error "Nm_Callback.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Nm_PduRxIndication                                  **
**                                                                            **
** Service ID           : 0x15                                                **
**                                                                            **
** Description          : Notification form BusNm that a NM message has been  **
**                        received                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : This service function has to be called after the    **
**                        initialization of the respective bus interface.     **
**                                                                            **
** Remarks              : Global Variable(s) : None                           **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_PduRxIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  #if (NM_PDU_RXINDICATION_ENABLED == STD_ON)
  NetworkHandleType LddNetworkIndex;

	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PDURXINDICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PDURXINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PDURXINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_PduRxIndUserCallout != NULL_PTR)
    {
      Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_PduRxIndUserCallout();
    }
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
}
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_StateChangeNotification                          **
**                                                                            **
** Service ID           : 0x16                                                **
**                                                                            **
** Description          : Notification that the state of the lower layer      **
**                        <BusNm> has changed.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmNetworkHandle, nmCurrentState, nmPreviousState    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GpChnlIndexArray, Nm_GaaStateChange             **
**                        Function(s) invoked : Com_SendSignal,               **
**                        BswM_StateChangeNotification                        **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
/* This function is provided for OEM extensions */
FUNC(void, NM_CODE) Nm_StateChangeNotification(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle,
  CONST(Nm_StateType, NM_APPL_CONST) nmPreviousState,
  CONST(Nm_StateType, NM_APPL_CONST) nmCurrentState)
{
  /* Local index for storing the index to to the channel config structure */
  #if (NM_STATECHANGE_IND_ENABLED == STD_ON)
  NetworkHandleType LddNetworkIndex;

  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_STATECHANGENOTIFICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_STATECHANGENOTIFICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_STATECHANGENOTIFICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    Com_SignalIdType LddNmStateReportSignalId;
    boolean LblNmStateReportEnabled;

    LblNmStateReportEnabled = Nm_GaaChannelConfig[LddNetworkIndex].blStateReportEnabled;
    LddNmStateReportSignalId = Nm_GaaChannelConfig[LddNetworkIndex].ddNmStateReportSignalId;
    
    if ((LblNmStateReportEnabled == NM_TRUE) && 
        (LddNmStateReportSignalId != NM_INVALID_NONE) &&
        (Nm_GpfnComSendSignal != NULL_PTR))
    {
      /* Transition from BusSleepMode to RepeatMessage */
      if ((nmPreviousState == NM_STATE_BUS_SLEEP) && (nmCurrentState == NM_STATE_REPEAT_MESSAGE))
      {
        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_RM_BSM;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      /* Transition from PrepareBusSleepMode to RepeatMessage */
      else if ((nmPreviousState == NM_STATE_PREPARE_BUS_SLEEP) && (nmCurrentState == NM_STATE_REPEAT_MESSAGE))
      {

        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_RM_PBSM;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      /* Transition from RepeatMessage to NormalOperation */
      else if ((nmPreviousState == NM_STATE_REPEAT_MESSAGE) && (nmCurrentState == NM_STATE_NORMAL_OPERATION))
      {

        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_NO_RM;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      /* Transition from ReadySleep to NormalOperation */
      else if ((nmPreviousState == NM_STATE_READY_SLEEP) && (nmCurrentState == NM_STATE_NORMAL_OPERATION))
      {

        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_NO_RS;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      /* Transition from ReadySleep to RepeatMessage */
      else if ((nmPreviousState == NM_STATE_READY_SLEEP) && (nmCurrentState == NM_STATE_REPEAT_MESSAGE))
      {
        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_RM_RS;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      /* Transition from NormalOperation to RepeatMessage */
      else if ((nmPreviousState == NM_STATE_NORMAL_OPERATION) && (nmCurrentState == NM_STATE_REPEAT_MESSAGE))
      {
        /* Change the state change variable for the network */
        Nm_GaaStateChange[LddNetworkIndex] = NM_RM_NO;

        /* Call the Com Function to configure NMS */
        (void)Nm_GpfnComSendSignal(LddNmStateReportSignalId,
        (P2CONST(void, NM_VAR_POWER_ON_INIT, NM_CONST))&Nm_GaaStateChange[LddNetworkIndex]);
      }
      else
      {
        /* For MISRA compliance */
      }
    }

    if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_StateChangeIndUserCallout != NULL_PTR)
    {
      Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_StateChangeIndUserCallout(nmPreviousState, nmCurrentState);
    }
  }
  #endif
} /* End of Nm_StateChangeNotification */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_RepeatMessageIndication                          **
**                                                                            **
** Service ID           : 0x1a                                                **
**                                                                            **
** Description          : Service to indicate that an NM message with set     **
**                        Repeat Message Request Bit has been received.       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_RepeatMessageIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  #if (NM_REPEATMSG_IND_ENABLED == STD_ON)
  /* Code snippet to avoid "unused parameter" warnings */
  /*
  * MISRA Rule   : 14.2
  * Message      : This statements has no side effects it can be removed.
  * Reason       : The statement is used only to avoid compilation warning.
  * Verification : However, part of the code is verified manually
  *                and it is not having any impact.
  */
  /* polyspace<MISRA-C:14.2:Not a defect:Justify with annotations> No Impact of this rule violation, part of the code is verified manually  */
  NM_UNUSED(nmNetworkHandle);
  #endif
}
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_TxTimeoutException                               **
**                                                                            **
** Service ID           : 0x1b                                                **
**                                                                            **
** Description          : Service to indicate that an attempt to send an NM   **
**                        message failed.                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_TxTimeoutException(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /*
  * MISRA Rule   : 14.2
  * Message      : This statements has no side effects it can be removed.
  * Reason       : The statement is used only to avoid compilation warning.
  * Verification : However, part of the code is verified manually
  *                and it is not having any impact.
  */
  /* polyspace<MISRA-C:14.2:Not a defect:Justify with annotations> No Impact of this rule violation, part of the code is verified manually  */
  NM_UNUSED(nmNetworkHandle);
}
#define NM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Nm_CarWakeUpIndication                              **
**                                                                            **
** Service ID           : 0x1d                                                **
**                                                                            **
** Description          : This function is called by a <Bus>Nm to indicate    **
**                        reception of a CWU request.                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_CarWakeUpIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  #if (NM_CARWAKEUP_RX_ENABLED == STD_ON)
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is already initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CARWAKEUPINDICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CARWAKEUPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    if (Nm_GpfnCarWakeUpCallback != NULL_PTR)
    {
      Nm_GpfnCarWakeUpCallback(nmNetworkHandle);
    }
  }
  #endif
}
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_CoordReadyToSleepIndication                      **
**                                                                            **
** Service ID           : 0x1e                                                **
**                                                                            **
** Description          : Sets an indication, when the NM Coordinator         **
**                        Sleep Ready bit in the Control  Bit Vector is set   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_CoordReadyToSleepIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Code snippet to avoid "unused parameter" warnings */
  #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  uint8 LucNmClusterListInfoIndex;
  uint8 LucChnlStartIndex;
  uint8 LucClusterSize;
  uint8 LucClusterStart;
  uint8 LucCount;
  uint8 LddChannelId;

  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is already initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_COORDREADYTOSLEEPINDICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_COORDREADYTOSLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_COORDREADYTOSLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    /* This condition is added  to avoid qac warning
     * Indexing array with value that will apparently be out of bounds
     */
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Get the index to Nm_GaaClusterList structure */
      LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;

      /* Getting a mapping index to the array Nm_GaaChnlArray */
      LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
      /* Get the cluster size */
      LucClusterSize = Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;

      LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];

      /* For the entire cluster */
      for (LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
      {
        /* Get the next channel in the cluster */
				/* polyspace +3 MISRA-C3:18.1, DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */
        LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
				/* polyspace +1 RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
        if (Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_TRUE)
        {
          /* Get the Channel Id */
          LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
          /* Set Sleep Ready Bit */
          (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_SetSleepReadyBit(LddChannelId, NM_SLEEP_BIT_SET);
          Nm_GaaShutdownTimer[LddNetworkIndex] = Nm_GaaChannelConfig[LddNetworkIndex].ulShutdownDelayTimerTick;
          Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
          /* Set the shutdown flag to indicate that timers are set */
          Nm_GaaClusterStatusFlag[LucClusterStart] = NM_TIMERS_SET;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
        }
        else
        {
          /* Ignore, To avoid QAC warning */
        }
      }
    }
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
}
#define NM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Nm_CoordReadyToSleepCancellation                    **
**                                                                            **
** Service ID           : 0x1f                                                **
**                                                                            **
** Description          : Cancels an indication, when the NM Coordinator      **
**                        Sleep Ready bit in the Control Bit Vector is set    **
**                        back to 0.                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_CoordReadyToSleepCancellation(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  NetworkHandleType LddNetworkIndex;
  /* Index to refer to Nm_GaaChannelCoord_ConfigInfo structure */
  uint8 LucChnlCoordInfoIndex;
  /* Index to refer to Nm_Nm_GaaClusterList structure */
  uint8 LucNmClusterListInfoIndex;
  /* Local variable to store the cluster size */
  uint8 LucClusterSize;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart;
  /* Local variable to store the mapping index */
  uint8 LucChnlStartIndex;
  /* Local variable to store the Channel ID */
  uint8 LddChannelId;
  /* Local variable to store the Count */
  uint8 LucCount;

  /* Check if the NM module is already initialized */
  /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPCANCELLATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPCANCELLATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPCANCELLATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;

      /* If the channel belongs to a cluster */
      if (LucChnlCoordInfoIndex != NM_INVALID)
      {
        /* Get the index to Nm_GaaClusterList structure */
        LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;
        /* Getting a mapping index to the array Nm_GaaChnlArray */
        LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
        /* Get the cluster size */
        LucClusterSize = Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;
        /* Get the start index of the cluster */
        LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];
        /* If the appropriate flag has been set to indicate shutdown */
        /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
        if ((Nm_GaaClusterStatusFlag[LucClusterStart] == NM_SHUTDOWN_READY) || (Nm_GaaClusterStatusFlag[LucClusterStart] == NM_TIMERS_SET))
        {
          /* Enter Data Protection */
          Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
          /*Change the status of the flag to indicate abort*/
          Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SHUTDOWN_ABORTED;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();

          for (LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
          {
            /* Get the next channel in the cluster */
            /* polyspace +3 MISRA-C3:18.1, DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */
            LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
            /* polyspace +1 RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
            if (Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_TRUE)
            {
              /* Get the Channel Id */
              LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;

              (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_SetSleepReadyBit(LddChannelId, NM_SLEEP_BIT_RESET);
            }
            else
            {
              /* Ignore, To avoid QAC warning */
            }
          }

          /* Call Nm_ClusterWakeUp with the mapping index for the cluster */
          Nm_ClusterWakeUp(LucChnlStartIndex, LucClusterSize);
        }
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
    }
  }
  /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif /* #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON) */
} /* End of Nm_CoordReadyToSleepCancellation */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
