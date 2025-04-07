/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Nm_Cbk.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Nm Module                                             **
**                                                                            **
**  PURPOSE   : This file provides definitions of Callback APIs               **
**              Nm_NetworkStartIndication                                     **
**              Nm_NetworkMode                                                **
**              Nm_PrepareBusSleepMode                                        **
**              Nm_BusSleepMode                                               **
**              Nm_RemoteSleepIndication                                      **
**              Nm_RemoteSleepCancellation                                    **
**              Nm_SynchronizationPoint                                       **
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
** 2.2.0     28-Dec-2018   JeongSu Lim   #13630, #15277, #15276, #15275,      **
**                                       #15274                               **
** 1.0.2     06-Sep-2016   Kt Kim        #5954                                **
** 1.0.1     17-May-2016   Kt Kim        #4641                                **
** 1.0.0     10-Apr-2013   Kt Kim        Initial version                      **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* Inclusion for declaration of call back functions */
#include "Nm_Cbk.h"
#include "Nm_Ram.h"
#include "Nm_PCTypes.h"
#include "Nm_Internal.h"

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define NM_CBK_C_AR_RELEASE_MAJOR_VERSION     (4)
#define NM_CBK_C_AR_RELEASE_MINOR_VERSION     (0)
#define NM_CBK_C_AR_RELEASE_REVISION_VERSION  (3)

/* Software Version Information */
#define NM_CBK_C_SW_MAJOR_VERSION  (2)
#define NM_CBK_C_SW_MINOR_VERSION  (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (NM_CBK_AR_RELEASE_MAJOR_VERSION != NM_CBK_C_AR_RELEASE_MAJOR_VERSION)
  #error "Nm_Cbk.c : Mismatch in Specification Major Version"
#endif

#if (NM_CBK_AR_RELEASE_MINOR_VERSION != NM_CBK_C_AR_RELEASE_MINOR_VERSION)
  #error "Nm_Cbk.c : Mismatch in Specification Minor Version"
#endif

#if (NM_CBK_AR_RELEASE_REVISION_VERSION != NM_CBK_C_AR_RELEASE_REVISION_VERSION)
  #error "Nm_Cbk.c : Mismatch in Specification Patch Version"
#endif

#if (NM_CBK_SW_MAJOR_VERSION != NM_CBK_C_SW_MAJOR_VERSION)
   #error "Nm_Cbk.c : Mismatch in Software Major Version"
#endif

#if (NM_CBK_SW_MINOR_VERSION != NM_CBK_C_SW_MINOR_VERSION)
   #error "Nm_Cbk.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Nm_NetworkStartIndication                           **
**                                                                            **
** Service ID           : 0x11                                                **
**                                                                            **
** Description          : This service shall notify ComM that a NM-message    **
**                        has been received in the Bus-Sleep Mode, what       **
**                        indicates that some nodes in the  network have      **
**                        entered the Network Mode. In case shutdown is       **
**                        underway, this will result in shutdown abort.       **
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
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray                                 **
**                        Function(s) invoked :                               **
**                        ComM_Nm_NetworkStartIndication                      **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_NetworkStartIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is already initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKSTARTINDICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKSTARTINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    /* Call ComM function for this network */
    ComM_Nm_NetworkStartIndication(nmNetworkHandle);
  }
} /* End of Nm_NetworkStartIndication */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_NetworkMode                                      **
**                                                                            **
** Service ID           : 0x12                                                **
**                                                                            **
** Description          : This service shall notify the upper layer(ComM) that**
**                        the network management has entered Network Mode.    **
**                        In case coordinated shutdown is underway, this      **
**                        callback will result in aborted shutdown.           **
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
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,          **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaClusterStatusFlag,           **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                                                                            **
**                        Function(s) invoked : ComM_Nm_NetworkMode,          **
**                        Nm_ClusterWakeUp                                    **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_NetworkMode(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is already initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKMODE_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKMODE_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKMODE_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
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
    /* Local variable to store the Channel ID  */
    uint8 LddChannelId;
    /* Local variable to store the Count  */
    uint8 LucCount;
  
    /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
    LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
    
		/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR) && (LucChnlCoordInfoIndex != NM_INVALID))
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
      if ((Nm_GaaClusterStatusFlag[LucClusterStart] == NM_SHUTDOWN_READY) ||
          (Nm_GaaClusterStatusFlag[LucClusterStart] == NM_TIMERS_SET))
      {
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
        /* Change the status of the flag to indicate abort */
        Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SHUTDOWN_ABORTED;
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();

        #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
        {
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
        }
        #endif

        /* Call Nm_ClusterWakeUp with the mapping index for the cluster */
        Nm_ClusterWakeUp(LucChnlStartIndex, LucClusterSize);
      }
			/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    }
    #endif
    /* Call the appropriate ComM function */
    ComM_Nm_NetworkMode(nmNetworkHandle);
  }
} /* End of Nm_NetworkMode */
#define NM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Nm_PrepareBusSleepMode                              **
**                                                                            **
** Service ID           : 0x13                                                **
**                                                                            **
** Description          : This service provides notification to the upper     **
**                        layer that the network has entered Prepare          **
**                        Bus Sleep Mode.                                     **
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
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray                                **
**                                                                            **
**                        Function(s) invoked : ComM_Nm_PrepareBusSleeMode,   **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_PrepareBusSleepMode(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is already initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PREPAREBUSSLEEPMODE_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PREPAREBUSSLEEPMODE_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    /* Call ComM function for this network */
    ComM_Nm_PrepareBusSleepMode(nmNetworkHandle);
  }
} /* End of Nm_PrepareBusSleepMode */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_BusSleepMode                                     **
**                                                                            **
** Service ID           : 0x14                                                **
**                                                                            **
** Description          : Callback function for bus sleep mode indication     **
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
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,          **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaNetworkStatusFlag,           **
**                        Nm_GaaClusterStatusFlag, Nm_GaaSchMEnterFuncPtr,    **
**                       Nm_GaaSchMExitFuncPtr                                **
**                                                                            **
**                        Function(s) invoked : ComM_Nm_BusSleepMode,         **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_BusSleepMode(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
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
  /* Count Variable */
  uint8 LucCount;
  /* Boolean variable to check if all the networks have indicated sleep */
  boolean LblSleepFlag;
  #endif

  /* Check if the NM module is already initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_BUSSLEEPMODE_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_BUSSLEEPMODE_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_BUSSLEEPMODE_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    /* Call ComM function for this network */
    ComM_Nm_BusSleepMode(nmNetworkHandle);

    #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
		/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    if ((Nm_GblCoordinatorSupportEnabled == STD_ON) && (Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Initialize the sleep flag */
      LblSleepFlag = NM_TRUE;
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;

      if (LucChnlCoordInfoIndex != NM_INVALID)
      {
        /* Get the index to Nm_GaaClusterList structure */
        LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;
        /* Getting a mapping index to the array Nm_GaaChnlArray */
        LucChnlStartIndex =
        Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
        /* Get the cluster size */
        LucClusterSize =
          Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;
        /* Get the start index of the cluster */
        LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Change the status of flag to indicate that bus has indicated sleep */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_SLEEP_INDICATED;
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        LucCount = NM_ZERO;

        while(LucCount < LucClusterSize)
        {
          /* Get the channel index for the next channel in the cluster */	
					/* polyspace +3 MISRA-C3:18.1, DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */					
          LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];				
					/* polyspace +1 RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
          if (Nm_GaaNetworkStatusFlag[LddNetworkIndex] == (uint32)NM_SLEEP_INDICATED)
          {
            LblSleepFlag = (LblSleepFlag) & (NM_TRUE);
          }
          else
          {
            LblSleepFlag = NM_FALSE;
            LucCount = LucClusterSize;
          }
          LucCount++;
        } /* End of for loop */
        if (LblSleepFlag == NM_TRUE)
        {
          /* Enter Data Protection */
					/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
          Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
          /*Change the cluster status to indicate that shutdown is complete*/
          Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SLEEP;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
        }
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
    }
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    #endif
  }
} /* End of Nm_BusSleepMode */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_RemoteSleepIndication                            **
**                                                                            **
** Service ID           : 0x17                                                **
**                                                                            **
** Description          : Callback function for Remote sleep mode indication  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,           **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaNetworkStatusFlag,           **
**                        Nm_GaaClusterStatusFlag, Nm_GaaSchMEnterFuncPtr,    **
**                        Nm_GaaSchMExitFuncPtr,                              **
**                                                                            **
**                        Function(s) invoked : <BusNm>_GetState,             **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_RemoteSleepIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  #if ((NM_REMOTE_SLEEP_IND_ENABLED == STD_ON) && (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON))

  NetworkHandleType LddNetworkIndex;
  /* Index to refer to Nm_GaaChannelCoord_ConfigInfo structure */
  uint8 LucChnlCoordInfoIndex;
  /* Index to refer to Nm_Nm_GaaClusterList structure */
  uint8 LucNmClusterListInfoIndex;
  /* Local variable to store the cluster size */
  uint8 LucClusterSize;
  /* Local variable to store the mapping index */
  uint8 LucChnlStartIndex;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart;

  /* Code snippet to avoid "unused parameter" warnings */
  /*
  * MISRA Rule   : 14.2
  * Message      : This statements has no side effects it can be removed.
  * Reason       : The statement is used only to avoid compilation warning.
  * Verification : However, part of the code is verified manually
  *                and it is not having any impact.
  */
  NM_UNUSED(nmNetworkHandle);

  /* Check if the NM module is already initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPINDICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REMOTESLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
      /* If the channel belongs to a cluster */
      if (LucChnlCoordInfoIndex != NM_INVALID)
      {
        /* Get the index to Nm_GaaClusterList structure */
        LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;
        /* Getting a mapping index to the array Nm_GaaChnlArray */
        LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
        /* Get the start index of the cluster */
        LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];
        
        /* Change the status of the Network Status flag */
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /*Set flag to indicate that Remote Sleep Indication has occured the network*/
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] |= (uint32)(NM_BUSNM_RSI);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();

        Nm_CheckShutdownCondition(LucClusterStart);
      } /* End of if (LucChnlCoordInfoIndex != NM_INVALID) */
    }
  }
  #endif
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
} /* End of Nm_RemoteSleepIndication */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_RemoteSleepCancellation                          **
**                                                                            **
** Service ID           : 0x18                                                **
**                                                                            **
** Description          : Callback function for Remote sleep mode indication  **
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
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,          **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaClusterStatusFlag            **
**                        Nm_GaaSchMEnterFuncPtr,  Nm_GaaSchMExitFuncPtr      **
**                                                                            **
**                        Function(s) invoked : Nm_ClusterWakeUp,             **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_RemoteSleepCancellation(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  #if ((NM_REMOTE_SLEEP_IND_ENABLED == STD_ON) && (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON))
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
  uint8 LddChannelId;
  uint8 LucCount;

  /* Code snippet to avoid "unused parameter" warnings */
  /*
  * MISRA Rule   : 14.2
  * Message      : This statements has no side effects it can be removed.
  * Reason       : The statement is used only to avoid compilation warning.
  * Verification : However, part of the code is verified manually
  *                and it is not having any impact.
  */
  NM_UNUSED(nmNetworkHandle);

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
      LucChnlCoordInfoIndex =
      Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;

      /* If the channel belongs to a cluster */
      if (LucChnlCoordInfoIndex != NM_INVALID)
      {
        /* Get the index to Nm_GaaClusterList structure */
        LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;
        /* Getting a mapping index to the array Nm_GaaChnlArray */
        LucChnlStartIndex =
          Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
        /* Get the cluster size */
        LucClusterSize =
          Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;
        /* Get the start index of the cluster */
        LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];

        /* Change the status of the Network Status flag*/
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /*Set flag to indicate that Remote Sleep Indication has cancelled the network*/
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RSI);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* End of Network Status Flag status Change */

        /* If the appropriate flag has been set to indicate shutdown */
				/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */	
        if ((Nm_GaaClusterStatusFlag[LucClusterStart] == NM_SHUTDOWN_READY) ||
            (Nm_GaaClusterStatusFlag[LucClusterStart] == NM_TIMERS_SET))
        {
          /* Enter Data Protection */
          Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
          /*Change the status of the flag to indicate abort*/
          Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SHUTDOWN_ABORTED;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();

          #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
          {
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
          }
          #endif

          /* Call Nm_ClusterWakeUp with the mapping index for the cluster */
          Nm_ClusterWakeUp(LucChnlStartIndex, LucClusterSize);
        }
        else 
        {
          for(LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
          {
            LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
            if (Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_FALSE)
            {
              if((Nm_GaaNetworkStatusFlag[LddNetworkIndex] & (uint32)NM_BUSNM_RELEASE) == (uint32)NM_BUSNM_RELEASE)
              {
                LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
                (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(LddChannelId);
                Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
              }
            }
          }
        }
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
    }
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
} /* End of Nm_RemoteCancellation */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_SynchronizationPoint                             **
**                                                                            **
** Service ID           : 0x19                                                **
**                                                                            **
** Description          : Callback function for Remote sleep mode indication  **
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
** Preconditions        : Nm Module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,           **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaClusterStatusFlag            **
**                        Nm_GaaSchMEnterFuncPtr,  Nm_GaaSchMExitFuncPtr      **
**                                                                            **
**                        Function(s) invoked :                               **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_SynchronizationPoint(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle)
{
  /* Code snippet to avoid "unused parameter" warnings */
  #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Index to refer to Nm_GaaChannelCoord_ConfigInfo structure */
  uint8 LucChnlCoordInfoIndex;
  /* Index to refer to Nm_Nm_GaaClusterList structure */
  uint8 LucNmClusterListInfoIndex;
  /* Count Variable */
  uint8 LucCount;
  /* Local variable to store the cluster size */
  uint8 LucClusterSize;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart;
  /* Local variable to store the mapping index */
  uint8 LucChnlStartIndex;

  /* Check if the NM module is already initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SYNCHRONIZATIONPOINT_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SYNCHRONIZATIONPOINT_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SYNCHRONIZATIONPOINT_SID, NM_E_HANDLE_UNDEF);
  }
  else
  {
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
      
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
        
        /* If the network is configured as a synchronizing network */
        if (Nm_GaaChannelConfig[LddNetworkIndex].blSynchronizingNetwork == NM_TRUE)
        {
          /* If shutdown has been initiated */
					/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
          if (Nm_GaaClusterStatusFlag[LucClusterStart] == NM_SHUTDOWN_READY)
          {
            for (LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
            {
              /* Get the next channel in the cluster */
              LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
              /* Set the shutdown delay timers */
							/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
              Nm_GaaShutdownTimer[LddNetworkIndex] = Nm_GaaChannelConfig[LddNetworkIndex].ulShutdownDelayTimerTick;
            }
            /* Enter Data Protection */
            Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
            /* Change the status of the flag to indicate timers are set */
            Nm_GaaClusterStatusFlag[LucClusterStart] = NM_TIMERS_SET;
            /* Exit Data Protection */
            Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
          }
        } /* If the network is configured as a synchronizing network */
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
    }
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
} /* End of Nm_SynchronizationPoint */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
 **                          END OF FILE                                      **
 ******************************************************************************/
 
