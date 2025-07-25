/*******************************************************************************
**  FILE-NAME: Nm_Cfg.c                                                       **
**                                                                            **
**  MODULE-NAME: AUTOSAR Network Management Module                            **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 2.5.0                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_Nm.arxml
 * GENERATED ON: The time-stamp is removed
 */


/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Nm_Cfg.h" /* For declarations of structures and definition of macros */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define NM_CFG_C_AR_RELEASE_MAJOR_VERSION                  (4)
#define NM_CFG_C_AR_RELEASE_MINOR_VERSION                  (0)
#define NM_CFG_C_AR_RELEASE_REVISION_VERSION               (3)
#define NM_CFG_C_SW_MAJOR_VERSION                          (2)
#define NM_CFG_C_SW_MINOR_VERSION                          (5)
#define NM_CFG_C_SW_PATCH_VERSION                          (0)

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/
#if (NM_PCTYPES_AR_RELEASE_MAJOR_VERSION != NM_CFG_C_AR_RELEASE_MAJOR_VERSION)
  #error "Nm_Cfg.c : Mismatch in Specification Major Version"
#endif

#if (NM_PCTYPES_AR_RELEASE_MINOR_VERSION != NM_CFG_C_AR_RELEASE_MINOR_VERSION)
  #error "Nm_Cfg.c : Mismatch in Specification Minor Version"
#endif

#if (NM_PCTYPES_AR_RELEASE_REVISION_VERSION != \
  NM_CFG_C_AR_RELEASE_REVISION_VERSION)
  #error "Nm_Cfg.c : Mismatch in Specification Revision Version"
#endif

#if (NM_PCTYPES_SW_MAJOR_VERSION != NM_CFG_C_SW_MAJOR_VERSION)
  #error "Nm_Cfg.c : Mismatch in Software Major Version"
#endif

#if (NM_PCTYPES_SW_MINOR_VERSION != NM_CFG_C_SW_MINOR_VERSION)
  #error "Nm_Cfg.c : Mismatch in Software Minor Version"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define NM_START_SEC_VAR_POWER_ON_INIT_8
#include "MemMap.h"

VAR(uint8, NM_VAR_POWER_ON_INIT) Nm_GaaStateChange[NM_NUMBER_OF_CHANNELS];

#define NM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "MemMap.h"

#define NM_START_SEC_VAR_POWER_ON_INIT_8
#include "MemMap.h"

VAR(Nm_ClusterStatusFlagType, NM_VAR_POWER_ON_INIT) Nm_GaaClusterStatusFlag[NM_NUMBER_OF_CHANNELS];

#define NM_STOP_SEC_VAR_POWER_ON_INIT_8
#include "MemMap.h"

#define NM_START_SEC_VAR_POWER_ON_INIT_32
#include "MemMap.h"

VAR(uint32, NM_VAR_POWER_ON_INIT) Nm_GaaNetworkStatusFlag[NM_NUMBER_OF_CHANNELS];

#define NM_STOP_SEC_VAR_POWER_ON_INIT_32
#include "MemMap.h"

#define NM_START_SEC_VAR_POWER_ON_INIT_32
#include "MemMap.h"

VAR(uint32, NM_VAR_POWER_ON_INIT) Nm_GaaShutdownTimer[NM_NUMBER_OF_CHANNELS];

#define NM_STOP_SEC_VAR_POWER_ON_INIT_32
#include "MemMap.h"



/* Structure to store channel details */
#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

CONST(Nm_ChannelConfig, NM_CONST) Nm_GaaChannelConfig[NM_NUMBER_OF_CHANNELS] =
{
  /* Channel 0 - 0 */
  {
    /* ddNmStateReportSignalId */
    NM_INVALID_NONE,

    /* ucChnlCoordInfoIndex */
    0x00,

    /* ddChannelId */
    0x00,

    /* blStateReportEnabled */
    NM_FALSE,

    /* blPassiveModeEnabled */
    NM_FALSE,

    /* blActiveCoordinator */
    NM_FALSE,

    /* blChannelSleepMaster */
    NM_FALSE,

    /* blSynchronizingNetwork */
    NM_FALSE,

    /* ulShutdownDelayTimerTick */
    0x00000000,

    /* ucClusterListInfoIndex */
    0x00,

    /* pfnBusNm_PassiveStartUp */
    CanNm_PassiveStartUp,

    /* pfnBusNm_NetworkRequest */
    CanNm_NetworkRequest,

    /* pfnBusNm_NetworkRelease */
    CanNm_NetworkRelease,

    /* pfnBusNm_DisableCommunication */
    CanNm_DisableCommunication,

    /* pfnBusNm_EnableCommunication */
    CanNm_EnableCommunication,

    /* pfnBusNm_RepeatMessageRequest */
    CanNm_RepeatMessageRequest,

    /* pfnBusNm_SetUserData */
    NULL_PTR,

    /* pfnBusNm_GetUserData */
    CanNm_GetUserData,

    /* pfnBusNm_GetPduData */
    CanNm_GetPduData,

    /* pfnBusNm_GetNodeIdentifier */
    CanNm_GetNodeIdentifier,

    /* pfnBusNm_GetLocalNodeIdentifier */
    CanNm_GetLocalNodeIdentifier,

    /* pfnBusNm_CheckRemoteSleepIndication */
    NULL_PTR,

    /* pfnBusNm_GetState */
    CanNm_GetState,

    /* pfnBusNm_RequestBusSynchronization */
    NULL_PTR,

    /* pfnBusNm_SetSleepReadyBit */
    NULL_PTR,

    /* pfnBusNm_StateChangeIndUserCallout */
    NULL_PTR,

    /* pfnBusNm_PduRxIndUserCallout */
    NULL_PTR
  },

  /* Channel 1 - 1 */
  {
    /* ddNmStateReportSignalId */
    NM_INVALID_NONE,

    /* ucChnlCoordInfoIndex */
    0x02,

    /* ddChannelId */
    0x01,

    /* blStateReportEnabled */
    NM_FALSE,

    /* blPassiveModeEnabled */
    NM_FALSE,

    /* blActiveCoordinator */
    NM_FALSE,

    /* blChannelSleepMaster */
    NM_FALSE,

    /* blSynchronizingNetwork */
    NM_FALSE,

    /* ulShutdownDelayTimerTick */
    0x00000000,

    /* ucClusterListInfoIndex */
    0x01,

    /* pfnBusNm_PassiveStartUp */
    CanNm_PassiveStartUp,

    /* pfnBusNm_NetworkRequest */
    CanNm_NetworkRequest,

    /* pfnBusNm_NetworkRelease */
    CanNm_NetworkRelease,

    /* pfnBusNm_DisableCommunication */
    CanNm_DisableCommunication,

    /* pfnBusNm_EnableCommunication */
    CanNm_EnableCommunication,

    /* pfnBusNm_RepeatMessageRequest */
    CanNm_RepeatMessageRequest,

    /* pfnBusNm_SetUserData */
    NULL_PTR,

    /* pfnBusNm_GetUserData */
    CanNm_GetUserData,

    /* pfnBusNm_GetPduData */
    CanNm_GetPduData,

    /* pfnBusNm_GetNodeIdentifier */
    CanNm_GetNodeIdentifier,

    /* pfnBusNm_GetLocalNodeIdentifier */
    CanNm_GetLocalNodeIdentifier,

    /* pfnBusNm_CheckRemoteSleepIndication */
    NULL_PTR,

    /* pfnBusNm_GetState */
    CanNm_GetState,

    /* pfnBusNm_RequestBusSynchronization */
    NULL_PTR,

    /* pfnBusNm_SetSleepReadyBit */
    NULL_PTR,

    /* pfnBusNm_StateChangeIndUserCallout */
    NULL_PTR,

    /* pfnBusNm_PduRxIndUserCallout */
    NULL_PTR
  }
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

static CONST(uint8, NM_CONST) Nm_GaaChnlArray[NM_NUMBER_OF_CHANNELS] =
{
  0x00,

  0x01
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

CONST(uint8, NM_CONST) Nm_GaaChnlIndexArray[NM_NUM_OF_CH_IDX_ARRAY] =
{
  0x00,

  0x01
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

/* static CONST(Nm_ClusterList, NM_CONST) Nm_GaaClusterList[NM_NUM_OF_COORD_CLUSTER]; */
#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

CONST(boolean, NM_CONST) Nm_GaaIsTopMost[NM_NUM_OF_COORD_CLUSTER] =
{
  NM_FALSE,

  NM_FALSE
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

CONST(Nm_SchMFuncPtr, NM_CONST) Nm_GaaSchMEnterFuncPtr[NM_NUMBER_OF_CHANNELS] =
{
  /* SchM Enter Function 0 - 0 */
  {
    /* pEnterFuncPtr */
    SchM_Enter_Nm_UPDATE_NETWORK_STATUS_NW0
  },

  /* SchM Enter Function 1 - 1 */
  {
    /* pEnterFuncPtr */
    SchM_Enter_Nm_UPDATE_NETWORK_STATUS_NW1
  }
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

#define NM_START_SEC_CONST_UNSPECIFIED
#include"MemMap.h"

CONST(Nm_SchMFuncPtr, NM_CONST) Nm_GaaSchMExitFuncPtr[NM_NUMBER_OF_CHANNELS] =
{
  /* SchM Exit Function 0 - 0 */
  {
    /* pExitFuncPtr */
    SchM_Exit_Nm_UPDATE_NETWORK_STATUS_NW0
  },

  /* SchM Exit Function 1 - 1 */
  {
    /* pExitFuncPtr */
    SchM_Exit_Nm_UPDATE_NETWORK_STATUS_NW1
  }
};

#define NM_STOP_SEC_CONST_UNSPECIFIED
#include"MemMap.h"


#define NM_START_SEC_CONST_8
#include "MemMap.h"

CONST(uint8, NM_CONST) Nm_GucNumberOfChannels = NM_NUMBER_OF_CHANNELS;

#define NM_STOP_SEC_CONST_8
#include "MemMap.h"

#define NM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

P2CONST(Nm_ClusterList, AUTOMATIC, NM_CONST) Nm_GpClusterList = NULL_PTR;

#define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define NM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

P2CONST(uint8, AUTOMATIC, NM_CONST) Nm_GpChnlArray = Nm_GaaChnlArray;

#define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define NM_START_SEC_CONST_8
#include "MemMap.h"

CONST(uint8, NM_CONST) Nm_GucNumberOfCoordinationClusters = 2;

#define NM_STOP_SEC_CONST_8
#include "MemMap.h"

#define NM_START_SEC_CONST_8
#include "MemMap.h"

CONST(uint8, NM_CONST) Nm_GucMaxChnId = 1;

#define NM_STOP_SEC_CONST_8
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblDevErrorDetect = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblVersionInfoApi = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblUserDataEnabled = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblNodeDetectionEnabled = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblNodeIdEnabled = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblPduRxIndicationEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblStateChangeIndEnabled = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblComControlEnabled = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblComUserDataSupport = STD_ON;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblBusSynchronizationEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblRemoteSleepIndEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblCoordinatorSupportEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblRepeatMsgIndEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblCarWakeUpRxEnabled = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_CONST_BOOLEAN
#include "MemMap.h"

CONST(boolean, NM_CONST) Nm_GblCoordinatorSyncSupport = STD_OFF;

#define NM_STOP_SEC_CONST_BOOLEAN
#include "MemMap.h"

#define NM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

P2FUNC(void, NM_CODE, Nm_GpfnCarWakeUpCallback) (
  VAR(NetworkHandleType, AUTOMATIC) nmNetworkHandle)
  = NULL_PTR;

#define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define NM_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

P2FUNC(uint8, NM_CODE, Nm_GpfnComSendSignal) (
  VAR(Com_SignalIdType, AUTOMATIC) SignalId,
  P2CONST(void, AUTOMATIC, NM_CONST) SignalDataPtr)
  = NULL_PTR;

#define NM_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
