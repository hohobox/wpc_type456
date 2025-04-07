/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Nm.c                                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Nm Module                                             **
**                                                                            **
**  PURPOSE   : This file provides definitions of following Nm APIs:          **
**              Nm_Init                                                       **
**              Nm_MainFunction                                               **
**              Nm_GetVersionInfo                                             **
**              Nm_PassiveStartUp                                             **
**              Nm_NetworkRequest                                             **
**              Nm_NetworkRelease                                             **
**              Nm_DisableCommunication                                       **
**              Nm_EnableCommunication                                        **
**              Nm_SetUserData                                                **
**              Nm_GetUserData                                                **
**              Nm_GetPduData                                                 **
**              Nm_RepeatMessageRequest                                       **
**              Nm_GetNodeIdentifier                                          **
**              Nm_GetLocalNodeIdentifier                                     **
**              Nm_CheckRemoteSleepIndication                                 **
**              Nm_GetState                                                   **
**              Nm_ChageTWaitBusSleep                                         **
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
** 2.5.0     30-Oct-2023   JH Jang       #43088                               **
** 2.4.0     07-Sep-2023   JH Jang       #38995, #42732                       **
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
#include "Nm.h" /* Inclusion of Nm Header File */
#include "Nm_PCTypes.h" /* Inclusion for declaration  of structure types */
#include "Nm_Ram.h" /* Inclusion for global variables */
#include "Nm_Internal.h"  /* Inclusion of Internal Functions */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define NM_C_AR_RELEASE_MAJOR_VERSION     (4)
#define NM_C_AR_RELEASE_MINOR_VERSION     (0)
#define NM_C_AR_RELEASE_REVISION_VERSION  (3)

/* Software Version Information */
#define NM_C_SW_MAJOR_VERSION  (2)
#define NM_C_SW_MINOR_VERSION  (5)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (NM_AR_RELEASE_MAJOR_VERSION != NM_C_AR_RELEASE_MAJOR_VERSION)
  #error "Nm.c : Mismatch in Specification Major Version"
#endif

#if (NM_AR_RELEASE_MINOR_VERSION != NM_C_AR_RELEASE_MINOR_VERSION)
  #error "Nm.c : Mismatch in Specification Minor Version"
#endif

#if (NM_AR_RELEASE_REVISION_VERSION != NM_C_AR_RELEASE_REVISION_VERSION)
  #error "Nm.c : Mismatch in Specification Patch Version"
#endif

#if (NM_SW_MAJOR_VERSION != NM_C_SW_MAJOR_VERSION)
  #error "Nm.c : Mismatch in Software Major Version"
#endif

#if (NM_SW_MINOR_VERSION != NM_C_SW_MINOR_VERSION)
  #error "Nm.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Symbols                                        **
*******************************************************************************/

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
** Function Name        : Nm_Init                                             **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This service initializes the NM module.             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
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
** Remarks              : Global Variable(s)  : Nm_GblInitStatus              **
**                          Nm_GaaClusterStatusFlag, Nm_GaaNetworkStatusFlag  **
**                          Nm_GaaShutdownTimer                               **
**                        Function(s) invoked : None                          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_Init(void)
{
  /* Local variable to store the Count */
  uint8 LucCount;
  
  for(LucCount = 0;LucCount < Nm_GucNumberOfChannels;LucCount++)
  {
    /* Exit Data Protection */
    Nm_GaaSchMEnterFuncPtr[LucCount].pSchMFuncPtr();
    /*Change the status of the flag to indicate SLEEP*/
    Nm_GaaClusterStatusFlag[LucCount] = NM_SLEEP;
    /* Exit Data Protection */
    Nm_GaaSchMExitFuncPtr[LucCount].pSchMFuncPtr();

    /* Exit Data Protection */
    Nm_GaaSchMEnterFuncPtr[LucCount].pSchMFuncPtr();
    /* Change the status of flag to indicate that bus has indicated No Release */
    Nm_GaaNetworkStatusFlag[LucCount] = (uint32)NM_NO_RELEASE;
    /* Exit Data Protection */
    Nm_GaaSchMExitFuncPtr[LucCount].pSchMFuncPtr();

    Nm_GaaShutdownTimer[LucCount] = NM_TIMER_RESET;
  }
  
  /* Set the global variable value TRUE */
  Nm_GblInitStatus = NM_TRUE;  
} /* End of Nm_Init */
#define NM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Nm_MainFunction                                     **
**                                                                            **
** Service ID           : 0x10                                                **
**                                                                            **
** Description          : This function implements the processes of the NM    **
**                        Interface which need a fix cyclic scheduling. The   **
**                        evaluation of shutdown timers is done in this       **
**                        function.                                           **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Timing               : Fixed Cyclic                                        **
**                                                                            **
** Input Parameters     : None                                                **
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
** Remarks              : Global Variable(s)  : Nm_GaaChannelConfig,          **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray,                                    **
**                        Nm_GaaShutdownTimer, Nm_GaaClusterStatusFlag,       **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                                                                            **
**                        Function(s) invoked : <BusNm>_NetworkRelease()      **
**                        Nm_ClusterWakeUp()                                  **
*******************************************************************************/
#if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
#define NM_START_SEC_CODE
#include "MemMap.h"
/* polyspace +1 MISRA-C3:8.4 [Not a defect: Justified] "It will call from RTE" */
FUNC(void, NM_CODE) Nm_MainFunction(void)
{
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_MAINFUNCTION_SID, NM_E_UNINIT);
  }
  else
  {
    /* Local variable to store the Cluster Count */
    uint8 LucClusterCount;

    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */ 
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* For all the possible clusters */
      for(LucClusterCount = NM_ZERO; LucClusterCount < Nm_GucNumberOfChannels; LucClusterCount++)
      {
        /* If shutdown has been initiated and timers have been set */
        if (Nm_GaaClusterStatusFlag[LucClusterCount] == NM_TIMERS_SET)
        {
          Nm_ShutdownTimerRunning(LucClusterCount);
        } /* end if (Nm_GaaClusterStatusFlag[LucClusterCount] == NM_TIMERS_SET) */
        else if(Nm_GaaClusterStatusFlag[LucClusterCount] == NM_AWAKE)
        {
          Nm_CheckShutdownCondition(LucClusterCount);
        } // End of Cluster State = AWAKE
        else
        {
          /* Do Nothing */
        }
      } /* end of for loop */
    }
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
  } /* end of if (Nm_GblInitStatus == NM_INIT) */
} /* End of Nm_MainFunction */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Nm_PassiveStartup()                                 **
**                                                                            **
** Service ID           : 0x01                                                **
**                                                                            **
** Description          : This network is responsible for the passive startup **
**                        of the lower BusNm layer. If the node is a          **
**                        coordinator, Nm_PassiveStartup() is treated as      **
**                        Nm_NetworkRequest(). Hence, in case shutdown is     **
**                        aborted, the entire cluster will be kept requested. **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,           **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaClusterStatusFlag,           **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_PassiveStartUp,       **
**                        <BusNm>_NetworkRequest                              **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_PassiveStartUp(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_OK;
  
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PASSIVESTARTUP_SID, NM_E_UNINIT);

    /* Set the Return value to not OK */
    LenReturnVal = E_NOT_OK;
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PASSIVESTARTUP_SID, NM_E_HANDLE_UNDEF);

    /* Set the Return value to not OK */
    LenReturnVal = E_NOT_OK;
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PASSIVESTARTUP_SID, NM_E_HANDLE_UNDEF);

    /* Set the Return value to not OK */
    LenReturnVal = E_NOT_OK;
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_PassiveStartUp == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_PASSIVESTARTUP_SID, NM_E_INVALID_REQUEST);

    /* Set the Return value to not OK */
    LenReturnVal = E_NOT_OK;
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
    /* Local variable to store the cluster starting index */
    uint8 LucClusterStart;
    /* Local variable to store the mapping index */
    uint8 LucChnlStartIndex;
    /* Local variable to store the Channel ID */
    uint8 LddChannelId;
    /* Local variable to store the Count */
    uint8 LucCount;

    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
      /* If the channel belongs to a cluster */
      if (LucChnlCoordInfoIndex != NM_INVALID)
      {
        // Following SWS_Nm_00245, Nm Coordinator should treat Nm_PassiveStartup as Nm_NetworkRequest,
        // And should consider NM Coordinator requested this network to be awake.
        
        /* Exit Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Change the status of the network */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_COMM_RELEASE);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();

        /* Call BusNm_NetworkRequest for this network */
        /* polyspace +1 RTE:COR [Not a defect:Justified] "Configured function pointer" */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(NetworkHandle);

        if (LenReturnVal == E_OK)
        {
          /* Exit Data Protection */
          Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          /* Change the status of the network */
          Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();

          if (Nm_GaaNetworkStatusFlag[LddNetworkIndex] != (uint32)NM_SLEEP_INDICATED)
          {
            /* Exit Data Protection */
            Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
            /* Change the status of the network */
            Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_COMM_RELEASE);
            /* Exit Data Protection */
            Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          }
          else
          {
            /* Exit Data Protection */
            Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
            /* Change the status of the network */
            Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_NO_RELEASE;
            /* Exit Data Protection */
            Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          }
        }
        else
        {
          /* Enter Data Protection */
          Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          /* Change the status of the network */
          Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_SLEEP_INDICATED;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        }

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
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
      /* If the channel does not belong to a cluster */
      else
      {
        /* Call BusNm_PassiveStartUp for this network */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_PassiveStartUp(NetworkHandle);
      }
    }
    else
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    #endif
    {
      /* Call BusNm_PassiveStartUp for this network */
      LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_PassiveStartUp(NetworkHandle);
    }
  }
  
  return(LenReturnVal);
} /* End of Nm_PassiveStartUp */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_GetVersionInfo                                   **
**                                                                            **
** Service ID           : 0x0f                                                **
**                                                                            **
** Description          : This function returns the version information of the**
**                        Nm Module.                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NmVerInfoPtr                                        **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#if (NM_VERSION_INFO_API == STD_ON)
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(void, NM_CODE) Nm_GetVersionInfo(
  P2VAR(Std_VersionInfoType, AUTOMATIC, NM_APPL_DATA) NmVerInfoPtr)
{
  if (NmVerInfoPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETVERSIONINFO_SID, NM_E_PARAM_POINTER);
  }
  else
  {
    /* Copy the vendor Id */
    /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    NmVerInfoPtr->vendorID = NM_VENDOR_ID;
    /* Copy the module Id */
    NmVerInfoPtr->moduleID = NM_MODULE_ID;
    /* Copy Software Major Version */
    NmVerInfoPtr->sw_major_version = NM_SW_MAJOR_VERSION;
    /* Copy Software Minor Version */
    NmVerInfoPtr->sw_minor_version = NM_SW_MINOR_VERSION;
    /* Copy Software Patch Version */
    NmVerInfoPtr->sw_patch_version = NM_SW_PATCH_VERSION;
  }
} /* End of Nm_GetVersionInfo */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Nm_NetworkRequest()                                 **
**                                                                            **
** Service ID           : 0x02                                                **
**                                                                            **
** Description          : This service requests the appropriate lower BusNm   **
**                        Network. If the node is a coordinator, the entire   **
**                        cluster is requested.                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,           **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaClusterStatusFlag,           **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_NetworkRequest,       **
**                        Nm_ClusterWakeUp                                    **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRequest(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal;

  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKREQUEST_SID, NM_E_UNINIT);

    /* Set the Return value to not Ok */
    LenReturnVal = E_NOT_OK;
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKREQUEST_SID, NM_E_HANDLE_UNDEF);

    /* Set the Return value to not Ok */
    LenReturnVal = E_NOT_OK;
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKREQUEST_SID, NM_E_HANDLE_UNDEF);

    /* Set the Return value to not Ok */
    LenReturnVal = E_NOT_OK;
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].blPassiveModeEnabled == NM_TRUE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKREQUEST_SID, NM_E_INVALID_REQUEST);

    /* Set the Return value to not Ok */
    LenReturnVal = E_NOT_OK;
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKREQUEST_SID, NM_E_INVALID_REQUEST);

    /* Set the Return value to not Ok */
    LenReturnVal = E_NOT_OK;
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
    /* Local variable to store the Channel ID */
    uint8 LddChannelId;
    /* Local variable to store the Count */
    uint8 LucCount;

    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR))
    {
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
      /* Call BusNm_NetworkRequest for this network */
      LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(NetworkHandle);

      if (LenReturnVal == E_OK)
      {
        /* Exit Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Change the status of the network */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();

        if(Nm_GaaNetworkStatusFlag[LddNetworkIndex] != (uint32)NM_SLEEP_INDICATED)
        {
          /* Exit Data Protection */
          Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          /* Change the status of the network */
          Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_COMM_RELEASE);
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        }
        else
        {
          /* Exit Data Protection */
          Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
          /* Change the status of the network */
          Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_NO_RELEASE;
          /* Exit Data Protection */
          Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        }
      }
      else
      {
        /* Exit Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Change the status of the network */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_SLEEP_INDICATED;
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
      }

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
        }
        else
        {
          #if (NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
          {
            for (LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
            {
              LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
              if (Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_FALSE)
              {
                if((Nm_GaaNetworkStatusFlag[LddNetworkIndex] & (uint32)NM_BUSNM_RELEASE) == (uint32)NM_BUSNM_RELEASE)
                {
                  LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
                  (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(LddChannelId);
                  /* Enter Data Protection */
                  Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
                  /* Change the status of the network */
                  Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
                  /* Exit Data Protection */
                  Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
                }
              }
            }
          }
          #endif
        }

        /* Call Nm_ClusterWakeUp with the mapping index for the cluster */
        Nm_ClusterWakeUp(LucChnlStartIndex, LucClusterSize);
      } /* if (LucChnlCoordInfoIndex != NM_INVALID) */
      /* If the channel does not belong to a cluster */
      else
      {
        /* Call BusNm_NetworkRequest for this network */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(NetworkHandle);
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Change the status of the network */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
      }
    }
    else
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    #endif
    {
      /* Call BusNm_NetworkRequest for this network */
      LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(NetworkHandle);
      Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
    }
  }
  
  return(LenReturnVal);
} /* End of Nm_NetworkRequest */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_NetworkRelease()                                 **
**                                                                            **
** Service ID           : 0x03                                                **
**                                                                            **
** Description          : This API releases the appropriate BusNm network.    **
**                        conditions are evaluated i.e., a check is           **
**                        performed to see if all the networks in the cluster **
**                        are ready to go to sleep.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GpChnlIndexArray, Nm_GaaChannelConfig,           **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GaaChnlArray, Nm_GaaNetworkStatusFlag,           **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_NetworkRelease,       **
**                        <BusNm>_GetState                                    **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_NetworkRelease(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local variable to hold the return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;

  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKRELEASE_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKRELEASE_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKRELEASE_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].blPassiveModeEnabled == NM_TRUE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKRELEASE_SID, NM_E_INVALID_REQUEST);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRelease == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_NETWORKRELEASE_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
    /* Index to refer to Nm_GaaChannelCoord_ConfigInfo structure */
    uint8 LucChnlCoordInfoIndex;
    /* Index to refer to Nm_GaaClusterList structure */
    uint8 LucNmClusterListInfoIndex;
    /* Local variable to store the mapping index */
    uint8 LucChnlStartIndex;
    /* Local variable to store the cluster size */
    uint8 LucClusterStart;

    /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
    LucChnlCoordInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucChnlCoordInfoIndex;
    
    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
    if ((Nm_GpClusterList != NULL_PTR) && (Nm_GpChnlArray != NULL_PTR) && (LucChnlCoordInfoIndex != NM_INVALID))
    {
      /* Get the index to Nm_GaaClusterList structure */
      LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LddNetworkIndex].ucClusterListInfoIndex;
      /* Getting a mapping index to the array Nm_GaaChnlArray */
      LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
      /* Get the start index of the cluster */
      LucClusterStart = Nm_GpChnlArray[LucChnlStartIndex];

      /* If the Local ECU is not the sleep master */
      if (Nm_GaaChannelConfig[LddNetworkIndex].blChannelSleepMaster == NM_FALSE)
      {
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        /* Set flag to indicate that ComM has released the network */
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] |= (uint32)(NM_COMM_RELEASE);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();

        Nm_CheckShutdownCondition(LucClusterStart);

        /* polyspace-end MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
        LenReturnVal = E_OK;
      }
      else
      /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE,USELESS_IF [Not a defect:Justified] "Condition will be executed based on the configured values" */
      {
        /* Call BusNm_NetworkRelease for this network */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRelease(NetworkHandle);
      }
    }
    else
    #endif
    {
      /* Call BusNm_NetworkRelease for this network */
      LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRelease(NetworkHandle);
    }
  }
  /* Return the Return Value */
  return (LenReturnVal);
} /* End of Nm_NetworkRelease */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_DisableCommunication()                           **
**                                                                            **
** Service ID           : 0x04                                                **
**                                                                            **
** Description          : This service calls DisableCommunication API of the  **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaChannelCoord_ConfigInfo, Nm_GaaClusterList,   **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_DisableCommunication, **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_DisableCommunication(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_COMCONTROL_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Jutified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_DISABLECOMMUNICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_DISABLECOMMUNICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_DISABLECOMMUNICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_DisableCommunication == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_DISABLECOMMUNICATION_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_DisableCommunication()*/
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_DisableCommunication(NetworkHandle);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_DisableCommunication */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_EnableCommunication()                            **
**                                                                            **
** Service ID           : 0x05                                                **
**                                                                            **
** Description          : This service calls EnableCommunication API of the   **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_EnableCommunication,  **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_EnableCommunication(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_COMCONTROL_ENABLED == STD_ON)
 /* Local index for storing the index to to the channel config structure */
   NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_ENABLECOMMUNICATION_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_ENABLECOMMUNICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_ENABLECOMMUNICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_EnableCommunication == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_ENABLECOMMUNICATION_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_EnableCommunication()*/
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_EnableCommunication(NetworkHandle);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_EnableCommunication */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_RepeatMessageRequest()                           **
**                                                                            **
** Service ID           : 0x09                                                **
**                                                                            **
** Description          : This service calls RepeatMessageRequest API of the  **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_RepeatMessageRequest, **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, NM_CODE) Nm_RepeatMessageRequest(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_NODE_DETECTION_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REPEATMESSAGEREQUEST_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REPEATMESSAGEREQUEST_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REPEATMESSAGEREQUEST_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_RepeatMessageRequest == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_REPEATMESSAGEREQUEST_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_RepeatMessageRequest() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_RepeatMessageRequest(NetworkHandle);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_RepeatMessageRequest */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_SetUserData()                                    **
**                                                                            **
** Service ID           : 0x06                                                **
**                                                                            **
** Description          : This service call the SetUserData API for the       **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle, nmUserDataPtr                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_SetUserData,          **
*******************************************************************************/
#if ((NM_USERDATA_ENABLED == STD_ON) && (NM_COM_USERDATA_SUPPORT == STD_OFF))
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_SetUserData(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle,
  CONSTP2CONST(uint8, AUTOMATIC, NM_APPL_CONST) nmUserDataPtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;

  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (nmUserDataPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].blPassiveModeEnabled == NM_TRUE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_INVALID_REQUEST);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_SetUserData == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_SETUSERDATA_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_EnableCommunication() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_SetUserData(NetworkHandle, nmUserDataPtr);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  return LenReturnVal;
} /* End of Nm_SetUserData */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Nm_GetUserData()                                    **
**                                                                            **
** Service ID           : 0x07                                                **
**                                                                            **
** Description          : This service call the GetUserData API for the       **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmUserDataPtr                                       **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_GetUserData,          **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, NM_CODE) Nm_GetUserData(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle,
  CONSTP2VAR(uint8, AUTOMATIC, NM_APPL_DATA) nmUserDataPtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_USERDATA_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETUSERDATA_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID,  NM_GETUSERDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (nmUserDataPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETUSERDATA_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID,  NM_GETUSERDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetUserData == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID,  NM_GETUSERDATA_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_GetUserData() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetUserData(NetworkHandle, nmUserDataPtr);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_GetUserData */
#define NM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Nm_GetPduData()                                     **
**                                                                            **
** Service ID           : 0x08                                                **
**                                                                            **
** Description          : This service call the GetPduData API for the        **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant for the same NetworkHandle               **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmPduData                                           **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_GetPduData,           **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_GetPduData(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle,
  CONSTP2VAR(uint8, AUTOMATIC, NM_APPL_CONST) nmPduData)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if ((NM_USERDATA_ENABLED == STD_ON) || (NM_NODEID_ENABLED== STD_ON))
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETPDUDATA_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETPDUDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (nmPduData == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETPDUDATA_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETPDUDATA_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetPduData == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETPDUDATA_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_GetPduData() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetPduData(NetworkHandle, nmPduData);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_GetPduData */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_GetNodeIdentifier()                              **
**                                                                            **
** Service ID           : 0x0a                                                **
**                                                                            **
** Description          : This service call the GetNodeIdentifier API for the **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmNodeIdPtr                                         **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s) : Nm_GblInitStatus,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_GetNodeIdentifier,    **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_GetNodeIdentifier(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle,
  CONSTP2VAR(uint8, AUTOMATIC, NM_APPL_CONST) nmNodeIdPtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_NODEID_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETNODEIDENTIFIER_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETNODEIDENTIFIER_SID, NM_E_HANDLE_UNDEF);
  }
  else if (nmNodeIdPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETNODEIDENTIFIER_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETNODEIDENTIFIER_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetNodeIdentifier == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETNODEIDENTIFIER_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_GetNodeIdentifier() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetNodeIdentifier(NetworkHandle, nmNodeIdPtr);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_GetNodeIdentifier */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_GetLocalNodeIdentifier()                         **
**                                                                            **
** Service ID           : 0x0b                                                **
**                                                                            **
** Description          : This service call the GetLocalNodeIdentifier API    **
**                        for the appropriate BusNm layer.                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : NetworkHandle                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmNodeIdPtr                                         **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked :                               **
**                        <BusNm>_GetLocalNodeIdentifier                      **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_GetLocalNodeIdentifier(
  CONST(NetworkHandleType, NM_APPL_CONST) NetworkHandle,
  CONSTP2VAR(uint8, AUTOMATIC, NM_APPL_CONST) nmNodeIdPtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  #if (NM_NODEID_ENABLED == STD_ON)
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETLOCALNODEIDENTIFIER_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(NetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETLOCALNODEIDENTIFIER_SID, NM_E_HANDLE_UNDEF);
  }
  else if (nmNodeIdPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETLOCALNODEIDENTIFIER_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETLOCALNODEIDENTIFIER_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetLocalNodeIdentifier == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETLOCALNODEIDENTIFIER_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_GetLocalNodeIdentifier() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetLocalNodeIdentifier(NetworkHandle, nmNodeIdPtr);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  #endif
  return LenReturnVal;
} /* End of Nm_GetLocalNodeIdentifier */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_CheckRemoteSleepIndication()                     **
**                                                                            **
** Service ID           : 0x0d                                                **
**                                                                            **
** Description          : This service call the CheckRemoteSleepIndication API**
**                        for the appropriate BusNm layer.                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant for the same NetworkHandle,           **
**                        reentrant otherwise                                 **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmRemoteSleepIndPtr                                 **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked :                               **
**                        <BusNm>_CheckRemoteSleepInication                   **
*******************************************************************************/
#if (NM_REMOTE_SLEEP_IND_ENABLED == STD_ON)
#define NM_START_SEC_CODE
#include "MemMap.h"
FUNC(Std_ReturnType, NM_CODE) Nm_CheckRemoteSleepIndication(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle,
  CONSTP2VAR(boolean, AUTOMATIC, NM_APPL_CONST) nmRemoteSleepIndPtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;

  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
	/* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CHECKREMOTESLEEPINDICATION_SID, NM_E_UNINIT);
  }
  else if (nmRemoteSleepIndPtr == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CHECKREMOTESLEEPINDICATION_SID, NM_E_PARAM_POINTER);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CHECKREMOTESLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CHECKREMOTESLEEPINDICATION_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_CheckRemoteSleepIndication == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_CHECKREMOTESLEEPINDICATION_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_CheckRemoteSleepIndication() */
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_CheckRemoteSleepIndication(nmNetworkHandle, nmRemoteSleepIndPtr);
  }
	/* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "Condition will be executed based on the configured values" */
  return LenReturnVal;
} /* End of Nm_CheckRemoteSleepIndication */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
** Function Name        : Nm_GetState()                                       **
**                                                                            **
** Service ID           : 0x0e                                                **
**                                                                            **
** Description          : This service call the GetState API for the          **
**                        appropriate BusNm layer.                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : nmNetworkHandle                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : nmStatePtr, nmModePtr                               **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : BusNm and Nm should be initialized properly         **
**                                                                            **
** Remarks              : Global Variable(s)  : Nm_GblInitStatus,             **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GpChnlIndexArray                                 **
**                                                                            **
**                      : Function(s) invoked : <BusNm>_GetState,             **
*******************************************************************************/
#define NM_START_SEC_CODE
#include "MemMap.h"

FUNC(Std_ReturnType, NM_CODE) Nm_GetState(
  CONST(NetworkHandleType, NM_APPL_CONST) nmNetworkHandle,
  CONSTP2VAR(Nm_StateType, AUTOMATIC, NM_APPL_CONST) nmStatePtr,
  CONSTP2VAR(Nm_ModeType, AUTOMATIC, NM_APPL_CONST) nmModePtr)
{
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal = E_NOT_OK;
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;

  /* Check if the NM module is not initialized */
  if (Nm_GblInitStatus != NM_INIT)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETSTATE_SID, NM_E_UNINIT);
  }
  else if (Nm_IntGetChannelIndexFromChannelId(nmNetworkHandle, &LddNetworkIndex) == NM_FALSE)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETSTATE_SID, NM_E_HANDLE_UNDEF);
  }
  else if ((nmStatePtr == NULL_PTR) || (nmModePtr == NULL_PTR))
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETSTATE_SID, NM_E_PARAM_POINTER);
  }
  else if (LddNetworkIndex >= Nm_GucNumberOfChannels)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETSTATE_SID, NM_E_HANDLE_UNDEF);
  }
  else if (Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetState == NULL_PTR)
  {
    (void)Nm_IntDetReportError(NM_MODULE_ID, NM_INSTANCE_ID, NM_GETSTATE_SID, NM_E_INVALID_REQUEST);
  }
  else
  {
    /* Call BusNm_GetState()*/
    LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetState(nmNetworkHandle, nmStatePtr, nmModePtr);
  }
  
  return LenReturnVal;
} /* End of Nm_GetState */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_ChageTWaitBusSleep()                             **
**                                                                            **
** Service ID           : 0x21                                                **
**                                                                            **
** Description          : This service for Change Wait Bus Sleep Time         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : TwaitBusSleep                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : Nm module should be initialized                     **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                                                                            **
**                      : Function(s) invoked : CanNm_ChangeTWaitBusSleep     **
**                                              OsekNm_ChangeTWaitBusSleep    **
*******************************************************************************/
#if(NM_CHANGE_TWAITBUSSLEEP_ENABLED == STD_ON)
#define NM_START_SEC_CODE
#include "MemMap.h"

FUNC(void, NM_CODE) Nm_ChangeTWaitBusSleep(
  CONST(uint32, NM_APPL_CONST) TwaitBusSleep)
{
  if(TwaitBusSleep <= NM_MAX_TWAITBUSSLEEP)
  {
    #if(CANNM_EXIST == STD_ON)
    CanNm_ChangeTWaitBusSleep(TwaitBusSleep);
    #endif
    #if(OSEKNM_EXIST == STD_ON)
    OsekNm_ChangeTWaitBusSleep(TwaitBusSleep);
    #endif  
  }
  else
  {
    #if(CANNM_EXIST == STD_ON)
    CanNm_ChangeTWaitBusSleep(NM_OUTOFRANGE_DEFAULT_TWAITBUSSLEEP);
    #endif
    #if(OSEKNM_EXIST == STD_ON)
    OsekNm_ChangeTWaitBusSleep(NM_OUTOFRANGE_DEFAULT_TWAITBUSSLEEP);
    #endif
  }
} /* End of Nm_ChangeTWaitBusSleep */
#define NM_STOP_SEC_CODE
#include "MemMap.h"
#endif
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
