/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Co., Ltd.                                       **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Nm_Internal.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Nm Module                                             **
**                                                                            **
**  PURPOSE   : Provides definition of Internal Function                      **
**              Nm_ClusterWakeUp                                              **
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
** 1.0.1     17-May-2016   Kt Kim        #4641                                **
** 1.0.0     01-Feb-2013   Kt Kim        Initial version                      **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm_Cfg.h" /* For Macros */
#include "Nm.h" /* For Macros */
#include "Nm_Internal.h"
#include "ComM_Nm.h"  /* For the ComM Callbacks */
#include "Nm_PCTypes.h" /* Inclusion for declaration of structure types */
#include "Nm_Ram.h" /* For declarations of global variables */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR Specification Version Information */
#define NM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION     (4)
#define NM_INTERNAL_C_AR_RELEASE_MINOR_VERSION     (0)
#define NM_INTERNAL_C_AR_RELEASE_REVISION_VERSION  (3)

/* Software Version Information */
#define NM_INTERNAL_C_SW_MAJOR_VERSION  (2)
#define NM_INTERNAL_C_SW_MINOR_VERSION  (5)

/*******************************************************************************
**                         V E R S I O N      C H E C K                       **
*******************************************************************************/
#if (NM_AR_RELEASE_MAJOR_VERSION != NM_INTERNAL_C_AR_RELEASE_MAJOR_VERSION)
  #error "Nm.c : Mismatch in Specification Major Version"
#endif

#if (NM_AR_RELEASE_MINOR_VERSION != NM_INTERNAL_C_AR_RELEASE_MINOR_VERSION)
  #error "Nm.c : Mismatch in Specification Minor Version"
#endif

#if (NM_AR_RELEASE_REVISION_VERSION != NM_INTERNAL_C_AR_RELEASE_REVISION_VERSION)
  #error "Nm.c : Mismatch in Specification Patch Version"
#endif

#if (NM_SW_MAJOR_VERSION != NM_INTERNAL_C_SW_MAJOR_VERSION)
  #error "Nm.c : Mismatch in Software Major Version"
#endif

#if (NM_SW_MINOR_VERSION != NM_INTERNAL_C_SW_MINOR_VERSION)
  #error "Nm.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define NM_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Nm_ClusterWakeUp                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to keep all the networks in a    **
**                        particular cluster requested.                       **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : MappingIndex, ClusterSize                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Nm_GaaChnlArray,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaClusterStatusFlag, Nm_GaaShutdownTimer,       **
**                        Nm_GaaNetworkStatusFlag,                            **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                        Function(s) Invoked : <BusNm>_GetState,             **
**                        <BusNm>_NetworkRequest                              **
**                                                                            **
*******************************************************************************/

FUNC(void, NM_CODE) Nm_ClusterWakeUp(
  CONST(uint8, NM_APPL_CONST) MappingIndex,
  CONST(uint8, NM_APPL_CONST) ClusterSize)
{
  /* Local index for storing the index to the channel config structure */
  #if (NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
  NetworkHandleType LddNetworkIndex;
  /* Local variable to store the Channel Id */
  NetworkHandleType LddChannelId;
  /* Variable to access the  network state */
  Nm_StateType LenState;
  /* Variable to access the network mode */
  Nm_ModeType LenMode = NM_MODE_BUS_SLEEP;
  /* Local variable to store return value */
  Std_ReturnType LenReturnVal;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart;
  /* Count Variable */
  uint8 LucCount;

  uint8 LucNmClusterListInfoIndex;

  if (Nm_GpChnlArray != NULL_PTR)
  {
    /* Get the start index of the cluster */
    LucClusterStart = Nm_GpChnlArray[MappingIndex];

    for(LucCount = NM_ZERO; LucCount < ClusterSize; LucCount++)
    {
      /* Get the channel index for the next channel in the cluster */
      LddNetworkIndex = Nm_GpChnlArray[MappingIndex + LucCount];

      /* Reset the shutdown timers */
 	    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
      Nm_GaaShutdownTimer[LddNetworkIndex] = NM_TIMER_RESET;
      /* Get the Channel Id */
 	    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
      LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
      /* Call <Bus>Nm_GetState() */
      (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetState(LddChannelId, &LenState, &LenMode);
 
      if ((LenMode != NM_MODE_BUS_SLEEP) && (Nm_GaaClusterStatusFlag[LucClusterStart] ==  NM_SHUTDOWN_ABORTED))
      {
        /* Call <Bus>Nm_NetworkRequest for this network */
 		    /* polyspace +1 RTE:COR [Not a defect:Justified] "Configured function pointer" */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(LddChannelId);
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);

        if (LenReturnVal == E_OK)
        {
          if (LenState != NM_STATE_NORMAL_OPERATION)
          {
            /* Enter Data Protection */
            Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
            /* Change the status of the network */
            Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RSI);
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
      }
      else if ((LenMode == NM_MODE_BUS_SLEEP) &&
 			/* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
              (Nm_GaaClusterStatusFlag[LucClusterStart] ==  NM_SHUTDOWN_ABORTED))
      {
        /* Call ComM_Nm_RestartIndication() */
        ComM_Nm_RestartIndication(LddChannelId);
      }
      else
      {
        /* MISRA Compliance */
      }
    } /* End of for (LucCount = NM_ZERO; LucCount < ClusterSize; LucCount++) */
    
    /* Enter Data Protection */
 	  /* polyspace +1 MISRA-C3:18.1, RTE:IDP,OBAI [Not a defect:Justified] "Genderated array index in range" */
    Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
    /* Change the cluster state to indicate that the cluster is now awake */
    Nm_GaaClusterStatusFlag[LucClusterStart] = NM_AWAKE;
    /* Exit Data Protection */
    Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
  }
  #endif
} /* End of Nm_ClusterWakeUp */

/*******************************************************************************
** Function Name        : Nm_ShutdownTimerRunning                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to shutdown timer running.       **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ClusterStart                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Nm_GaaChnlArray,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaClusterStatusFlag, Nm_GaaShutdownTimer,       **
**                        Nm_GaaNetworkStatusFlag,                            **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                        Function(s) Invoked : <BusNm>_GetState,             **
**                        <BusNm>_NetworkRequest                              **
**                                                                            **
*******************************************************************************/
#if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
FUNC(void, NM_CODE) Nm_ShutdownTimerRunning(
  CONST(uint8, NM_APPL_CONST) ClusterStart)
{
  /* Count Variable */
  uint8 LucCount = NM_ZERO;
  /* Local variable to store the cluster size */
  uint8 LucClusterSize;
  /* Local variable to store the mapping index */
  uint8 LucChnlStartIndex;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart = ClusterStart;
  /* Index to refer to Nm_GaaClusterList structure */
  uint8 LucNmClusterListInfoIndex;
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local variable to store the Channel Id */
  NetworkHandleType LddChannelId;
  /*Variable to hold the Return Value */
  Std_ReturnType LenReturnVal = E_OK;

  /* Get the index to Nm_GaaClusterList structure */
  LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LucClusterStart].ucClusterListInfoIndex;
  /* Getting a mapping index to the array Nm_GaaChnlArray */
  LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
  /* Get the size of the cluster */
  LucClusterSize = Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;
  
  /* For all the networks in the cluster */
  while(LucCount < LucClusterSize)
  {
    /* Get the index to the networks in the cluster */
    LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
    if (Nm_GaaNetworkStatusFlag[LddNetworkIndex] == (uint32)NM_COMM_RELEASE_BUSNM_RSI)
    {
      /* If the timer has elapsed and the bus is not already asleep */
      if (Nm_GaaShutdownTimer[LddNetworkIndex] == 0x0000)
      {
        /* Get the Channel Id */
        LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;

        #if (NM_BUS_SYNCHRONIZATION_ENABLED == STD_ON)
        {
          /* Call BusNm_RequestSynchronization */
          (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_RequestBusSynchronization(LddChannelId);
        }
        #endif
        
        /* Release the bus */								
        /* polyspace +1 RTE:COR [Not a defect:Justified] "Configured function pointer" */
        LenReturnVal = Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRelease(LddChannelId);
        /* Enter Data Protection */
        Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] |= (uint32)(NM_BUSNM_RELEASE);
        /* Exit Data Protection */
        Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
      }
      else
      {
        /* Decrement the timer */
        Nm_GaaShutdownTimer[LddNetworkIndex]--;
      }
    }
    /* Only if the return value from BusNm_NetworkRelease() is NOT OK */
    if (LenReturnVal == E_NOT_OK)
    {
      /* Enter Data Protection */
      Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
      /* Indicate Aborted Shutdown */
      Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SHUTDOWN_ABORTED;
      /* Exit Data Protection */
      Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
      /* Wake up the entire cluster by calling Nm_ClusterWakeUp() */

      #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
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
      #endif

      Nm_ClusterWakeUp(LucChnlStartIndex, LucClusterSize);
      LucCount = LucClusterSize;
    }
    LucCount++;
  }
} /* End of Nm_ShutdownTimerRunning */
#endif

/*******************************************************************************
** Function Name        : Nm_StartShutdown                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to set shutdown Timer            **
**                        And set shutdown flag.                              **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ChnlStartIndex, ClusterSize, ClusterStart,          **
**                        SynchronizingNetwork                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Nm_GaaChnlArray,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaClusterStatusFlag, Nm_GaaShutdownTimer,       **
**                        Nm_GaaNetworkStatusFlag,                            **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                        Function(s) Invoked : <BusNm>_GetState,             **
**                        <BusNm>_NetworkRequest                              **
**                                                                            **
*******************************************************************************/
#if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
static FUNC(void, NM_CODE) Nm_StartShutdown(
  CONST(uint8, NM_APPL_CONST) ChnlStartIndex,
  CONST(uint8, NM_APPL_CONST) ClusterSize,
  CONST(uint8, NM_APPL_CONST) ClusterStart,
  CONST(boolean, NM_APPL_CONST) SynchronizingNetwork)
{
  /* Count Variable */
  uint8 LucCount;
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local flag to indicate if a synchronizing network is present */
  boolean LblSynchronizingNetwork = SynchronizingNetwork;
  /* Local variable to store the Channel Id */
  NetworkHandleType LddChannelId;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart = ClusterStart;


  #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  for(LucCount = NM_ZERO; LucCount < ClusterSize; LucCount++)
  {
    /* Get the next channel in the cluster */
    LddNetworkIndex = Nm_GpChnlArray[ChnlStartIndex + LucCount];
    /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
    if (Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_TRUE)
    {
      /* Get the Channel Id */
      LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
      /* Set Sleep Ready Bit */
      (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_SetSleepReadyBit(LddChannelId, NM_SLEEP_BIT_SET);
      /* Synchronizing Netowork set FALSE*/
      LblSynchronizingNetwork = NM_FALSE;
    }
  }
  #endif

  /* If no network is a Synchronizing Network */
  if (LblSynchronizingNetwork == NM_FALSE)
  {
    /* For the entire cluster */
    for(LucCount = NM_ZERO; LucCount < ClusterSize; LucCount++)
    {
      /* Get the next channel in the cluster */
      LddNetworkIndex = Nm_GpChnlArray[ChnlStartIndex + LucCount];
      /* Get the index to Nm_GaaChannelCoord_ConfigInfo structure */
      /* Set the shutdown delay timers */
      Nm_GaaShutdownTimer[LddNetworkIndex] = Nm_GaaChannelConfig[LddNetworkIndex].ulShutdownDelayTimerTick;
    } /*  End of for loop */

    /* Enter Data Protection */
    Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
    /* Set the shutdown flag to indicate that timers are set */
    Nm_GaaClusterStatusFlag[LucClusterStart] = NM_TIMERS_SET;
    /* Exit Data Protection */
    Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();

  } /* End of if (LblSynchronizingNetwork == NM_FALSE) */

  /* 2013-06-28 Kt.Kim Fix error in defect list */
  else if (LblSynchronizingNetwork == NM_TRUE)
  {
    /* Enter Data Protection */
    Nm_GaaSchMEnterFuncPtr[LucClusterStart].pSchMFuncPtr();
    /* If there is a synchronizing network do not set the timers */
    Nm_GaaClusterStatusFlag[LucClusterStart] = NM_SHUTDOWN_READY;
    /* Exit Data Protection */
    Nm_GaaSchMExitFuncPtr[LucClusterStart].pSchMFuncPtr();
  }

  else
  {
    /* Do nothing */
  }

} /* End of Nm_StartShutdown */
#endif

/*******************************************************************************
** Function Name        : Nm_ChangeToReadySleepState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to change the state of a         **
**                        Passively Coordinated Channel to Ready Sleep State. **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ChnlStartIndex, ClusterSize                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Nm_GaaChnlArray,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaClusterStatusFlag, Nm_GaaShutdownTimer,       **
**                        Nm_GaaNetworkStatusFlag,                            **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                        Function(s) Invoked : <BusNm>_GetState,             **
**                        <BusNm>_NetworkRequest                              **
**                                                                            **
*******************************************************************************/

#if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
static FUNC(void, NM_CODE) Nm_ChangeToReadySleepState(
  CONST(uint8, NM_APPL_CONST) ChnlStartIndex,
  CONST(uint8, NM_APPL_CONST) ClusterSize)
{
  /* Count Variable */
  uint8 LucCount;
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local variable to store the Channel Id */
  NetworkHandleType LddChannelId;

  LucCount = NM_ZERO;
  
  /* For all the networks in the cluster */
  while(LucCount < ClusterSize)
  {
    /* Get the channel index for the next channel in the cluster */
    /* polyspace +3 MISRA-C3:18.1, DEFECT:OUT_BOUND_PTR [Not a defect:Justified] "Genderated array index in range" */
    LddNetworkIndex = Nm_GpChnlArray[ChnlStartIndex + LucCount];
    /* Get the Channel Id */
    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
    LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;

    if(Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator == NM_FALSE)
    {
	  // SWS_Nm_00236
      if(E_NOT_OK == Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRelease(LddChannelId))
      {
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] &= ~((uint32)NM_BUSNM_RELEASE);
        // SWS_Nm_00235
		if(E_NOT_OK == Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_NetworkRequest(LddChannelId))
        {
          Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_SLEEP_INDICATED;
        }
      }
      else
      {
        Nm_GaaNetworkStatusFlag[LddNetworkIndex] |= (uint32)(NM_BUSNM_RELEASE);
      }
    }
    LucCount++;
  }

} /* End of Nm_ChangeToReadySleepState */
#endif

/*******************************************************************************
** Function Name        : Nm_CheckShutdownCondition                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to check shutdown condition.     **
**                                                                            **
** Sync/Async           : None                                                **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ClusterStart                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :  Nm_GaaChnlArray,              **
**                        Nm_GaaChannelConfig,                                **
**                        Nm_GaaClusterStatusFlag, Nm_GaaShutdownTimer,       **
**                        Nm_GaaNetworkStatusFlag,                            **
**                        Nm_GaaSchMEnterFuncPtr, Nm_GaaSchMExitFuncPtr       **
**                        Function(s) Invoked : <BusNm>_GetState,             **
**                        <BusNm>_NetworkRequest                              **
**                                                                            **
*******************************************************************************/
#if(NM_COORDINATOR_SUPPORT_ENABLED == STD_ON)
FUNC(void, NM_CODE) Nm_CheckShutdownCondition(
  CONST(uint8, NM_APPL_CONST) ClusterStart)
{
  /* Count Variable */
  uint8 LucCount;
  /* Local variable to store the cluster size */
  uint8 LucClusterSize;
  /* Local variable to store the mapping index */
  uint8 LucChnlStartIndex;
  /* Local variable to store the cluster size */
  uint8 LucClusterStart = ClusterStart;
  /* Index to refer to Nm_GaaClusterList structure */
  uint8 LucNmClusterListInfoIndex;
  /* Local index for storing the index to to the channel config structure */
  NetworkHandleType LddNetworkIndex;
  /* Local flag to indicate if all the networks can sleep */
  boolean LblSleepFlag = NM_TRUE;
  /* Local flag to indicate if a synchronizing network is present */
  boolean LblSynchronizingNetwork = NM_FALSE;
  /* Local variable to store the Channel Id */
  NetworkHandleType LddChannelId;
  /* Variable to access the  network state */
  Nm_StateType LenState;
  /* Variable to access the network mode */
  Nm_ModeType LenMode = NM_MODE_BUS_SLEEP;
  
  #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  boolean LblPassiveReleaseFlag;
  #endif

  /* Get the index to Nm_GaaClusterList structure */
  LucNmClusterListInfoIndex = Nm_GaaChannelConfig[LucClusterStart].ucClusterListInfoIndex;
  /* Getting a mapping index to the array Nm_GaaChnlArray */
  LucChnlStartIndex = Nm_GpClusterList[LucNmClusterListInfoIndex].ucChnlStartIndex;
  /* Get the size of the cluster */
  LucClusterSize = Nm_GpClusterList[LucNmClusterListInfoIndex].ucNumOfChnls;

  #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  if(Nm_GaaIsTopMost[LucNmClusterListInfoIndex] == NM_FALSE)
  {
    LblPassiveReleaseFlag = NM_TRUE;
  }
  else
  {
    LblPassiveReleaseFlag = NM_FALSE;
  }
  #endif

  /* For all the networks in the cluster */
  for(LucCount = NM_ZERO; LucCount < LucClusterSize; LucCount++)
  {
    /* Get the channel index for the next channel in the cluster */
    LddNetworkIndex = Nm_GpChnlArray[LucChnlStartIndex + LucCount];
    /* Get the Channel Id */
    /* polyspace +1 MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
    LddChannelId = Nm_GaaChannelConfig[LddNetworkIndex].ddChannelId;
    /* Get the state of the bus */
    (void)Nm_GaaChannelConfig[LddNetworkIndex].pfnBusNm_GetState(LddChannelId, &LenState, &LenMode);

    /* If the bus is already in Bus-Sleep Mode */
    if ((LenMode == NM_MODE_BUS_SLEEP) && (Nm_GaaNetworkStatusFlag[LddNetworkIndex] != (uint32)NM_SLEEP_INDICATED))
    {
      /* Enter Data Protection */
      Nm_GaaSchMEnterFuncPtr[LddNetworkIndex].pSchMFuncPtr();
      /* Change Network Status Flag */
      Nm_GaaNetworkStatusFlag[LddNetworkIndex] = (uint32)NM_SLEEP_INDICATED;
      /* Exit Data Protection */
      Nm_GaaSchMExitFuncPtr[LddNetworkIndex].pSchMFuncPtr();
    }

    /* Checking if at least one network is a Synchronizing Network */
    if ((Nm_GaaChannelConfig[LddNetworkIndex].blSynchronizingNetwork == NM_TRUE) && (LblSynchronizingNetwork == NM_FALSE))
    {
      /* Set the flag to true */
      LblSynchronizingNetwork =  NM_TRUE;
    }

    /* Checking if all the networks have been released */
    if ((Nm_GaaNetworkStatusFlag[LddNetworkIndex] != (uint32)NM_COMM_RELEASE_BUSNM_RSI) && (Nm_GaaNetworkStatusFlag[LddNetworkIndex] != (uint32)NM_SLEEP_INDICATED))
    {
      #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
      if(Nm_GaaIsTopMost[LucNmClusterListInfoIndex] == NM_FALSE)
      {
        LblSleepFlag = NM_FALSE;

        if((Nm_GaaChannelConfig[LddNetworkIndex].blActiveCoordinator) == NM_TRUE)
        {
          LblPassiveReleaseFlag = NM_FALSE;
        }
        else
        {
          if(((Nm_GaaNetworkStatusFlag[LddNetworkIndex] & (uint32)NM_COMM_RELEASE) != (uint32)NM_COMM_RELEASE)
            || ((Nm_GaaNetworkStatusFlag[LddNetworkIndex] & (uint32)NM_BUSNM_RELEASE) == (uint32)NM_BUSNM_RELEASE))
          {
            LblPassiveReleaseFlag = NM_FALSE;
          }
        }
      }
      else
      #endif
      {
        LblSleepFlag = NM_FALSE;
      }
    }
  } /* End  of for loop */
  
  #if(NM_COORDINATOR_SYNC_SUPPORT == STD_ON)
  /* Sub-nested support && Passive Release Flag True */
  if(LblPassiveReleaseFlag == NM_TRUE)
  {
    Nm_ChangeToReadySleepState(LucChnlStartIndex, LucClusterSize);
  }
  #endif

  /* If the cluster is ready to sleep */
  /* polyspace-begin MISRA-C3:18.1, RTE:OBAI [Not a defect:Justified] "Genderated array index in range" */
  if (LblSleepFlag == NM_TRUE)
  {
    Nm_StartShutdown(LucChnlStartIndex, LucClusterSize, LucClusterStart, LblSynchronizingNetwork);
  }

  else
  {
    /* Do Nothing */
  }

} /* End of Nm_CheckShutdownCondition */
#endif

/*******************************************************************************
** Function Name        : Nm_IntGetChannelIndexFromChannelId                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to get channel index from        **
**                        channel id.                                         **
**                                                                            **
** Sync/Async           : Sync                                                **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : LddChannelId                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : LpChannelIndex                                      **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Nm_GucMaxChnId, Nm_GaaChnlIndexArray                **
*******************************************************************************/

FUNC(boolean, NM_CODE) Nm_IntGetChannelIndexFromChannelId(
  CONST(NetworkHandleType, NM_APPL_CONST) LddChannelId,
  P2VAR(NetworkHandleType, AUTOMATIC, NM_APPL_DATA) LpChannelIndex)
{
  boolean LblResult = NM_FALSE;
  
  if (LddChannelId <= Nm_GucMaxChnId)
  {
    *LpChannelIndex = Nm_GaaChnlIndexArray[LddChannelId];
    LblResult = NM_TRUE;
  }

  return LblResult;
}

/*******************************************************************************
** Function Name        : Nm_IntDetReportError                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This API is called to raise DET error.              **
**                                                                            **
** Sync/Async           : Sync                                                **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : ModuleId, InstanceId, ApiId, ErrorId                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Nm_GblDevErrorDetect                                **
**                        Function(s) Invoked :                               **
**                        Det_ReportError                                     **
*******************************************************************************/

FUNC(Std_ReturnType, NM_CODE) Nm_IntDetReportError(
  uint16 ModuleId,
  uint8 InstanceId,
  uint8 ApiId,
  uint8 ErrorId)
{
  Std_ReturnType result = (Std_ReturnType)E_OK;
  #if (NM_DET_REPORT_ERROR == STD_ON)
  result = Det_ReportError(ModuleId, InstanceId, ApiId, ErrorId);
  #endif
  return result;
}

#define NM_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
