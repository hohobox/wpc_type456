/*******************************************************************************
**  FILE-NAME: WdgM_Cfg.h                                                     **
**                                                                            **
**  MODULE-NAME: AUTOSAR Watchdog Manager Module                              **
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Generation Tool Information                           **
*******************************************************************************/
/*
**  Tool Version: 1.2.21                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            */

/*******************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:    Configuration\ECU\Ecud_EcuC.arxml
 *                Configuration\ECU\Ecud_Os.arxml
 *                Configuration\ECU\Ecud_WdgIf.arxml
 *                Configuration\ECU\Ecud_WdgM.arxml
 *                Configuration\ECU\Mcal\Ecud_Mcu.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef WDGM_CFG_H
#define WDGM_CFG_H
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "Rte_Type.h"

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define WDGM_CFG_AR_RELEASE_MAJOR_VERSION                  (4)
#define WDGM_CFG_AR_RELEASE_MINOR_VERSION                  (0)
#define WDGM_CFG_AR_RELEASE_REVISION_VERSION               (3)
#define WDGM_CFG_SW_MAJOR_VERSION                          (1)
#define WDGM_CFG_SW_MINOR_VERSION                          (2)
#define WDGM_CFG_SW_PATCH_VERSION                          (21)

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define WDGM_AR_RELEASE_MAJOR_VERSION                      (4)
#define WDGM_AR_RELEASE_MINOR_VERSION                      (0)
#define WDGM_AR_RELEASE_REVISION_VERSION                   (3)
#define WDGM_SW_MAJOR_VERSION                              (1)
#define WDGM_SW_MINOR_VERSION                              (2)
#define WDGM_SW_PATCH_VERSION                              (21)
#define WDGM_VENDOR_ID                                     ((uint16)39)
#define WDGM_MODULE_ID                                     ((uint16)13)

/*******************************************************************************
**                      Data Types                                            **
*******************************************************************************/
/* Type definition for Checkpoint mapping array index type */
typedef uint32 WdgM_CpMapArrayIndexType;

/* Type definition for Supervised Entity mapping array index type */
typedef uint16 WdgM_SupervisedEntityIndexType;

/* Type definition for Supervised Entity mapping array index type */
typedef uint16 WdgM_ExAliveIndicationsCountType;

/* 
 *  Type based on maximum configured WdgMExpectedAliveIndications in all
 * modes
 */
typedef uint16 WdgM_AliveSupRefCycleCountType;

/* 
 *  Type based on maximum value configured for the parameter
 * WdgMFailedAliveSupervisionRefCycleTol in all modes
 */
typedef uint16 WdgM_FailureTolType;

/*  Type based on maximum number of WdgMInternalTransition configured */
typedef uint16 WdgM_IntLogicSupStatArrIndexType;

/*  Type based on maximum number of WdgMExternalTransition configured */
typedef uint16 WdgM_ExtLogicSupStatArrIndexType;

/* 
 *  Depends on the maximum size of the available
 * WdgM_GaaExLSGraph<MODE_ID><GRAPH_ID> array
 */
typedef uint16 WdgM_ExLSGraphArrayType;

/* 
 *  Type based on maximum value configured for the
 * parameterWdgMExpiredSupervisionCycleTol in all modes i.e 255
 */
typedef uint32 WdgM_ExpSupCycleTolType;


/*******************************************************************************
**                      Precompile Options                                    **
*******************************************************************************/
/* Development error detection Enable or Disable */
#define WDGM_DEV_ERROR_DETECT                         (STD_ON)

/* Enable or Disable Alive supervision */
#define WDGM_ENABLE_ALIVE_SUPERVISION                 (STD_ON)

/* Enable or Disable Deadline supervision */
#define WDGM_ENABLE_DEADLINE_SUPERVISION              (STD_OFF)

/* Enable or Disable Logical supervision */
#define WDGM_ENABLE_LOGICAL_SUPERVISION               (STD_OFF)

/* Enable or Disable Internal Transition */
#define WDGM_ENABLE_INTERNAL_TRANSITION               (STD_OFF)

/* Enable or Disable External Transition */
#define WDGM_ENABLE_EXTERNAL_TRANSITION               (STD_OFF)

/* Enable or Disable DemEventParameter */
#define WDGM_DEM_ERROR_REPORT                         (STD_OFF)

/* Enable or Disable Dem notification */
#define WDGM_DEM_STOPPED_SUPERVISION_REPORT           (STD_OFF)

/* Immediate reset feature Enable or Disable */
#define WDGM_IMMEDIATE_RESET                          (STD_OFF)

/* Enable or Disable selection of the OffMode */
#define WDGM_OFF_MODE_ENABLED                         (STD_ON)

/* Enable or Disable defensive behaviour */
#define WDGM_DEFENSIVE_BEHAVIOR                       (STD_OFF)

/* Enable or Disable OS Application */
#define WDGM_ENABLE_OS_APPLICATION                    (STD_OFF)

/* Enable or Disable ECUC partition */
#define WDGM_ENABLE_ECUC_PARTITION                    (STD_OFF)

/* Enable or Disable Trigger */
#define WDGM_ENABLE_TRIGGER                           (STD_ON)

/* Enable or Disable WdgM_GetVersionInfo API */
#define WDGM_VERSION_INFO_API                         (STD_OFF)

/* Enable or Disable WdgM_GetErrorInfo API */
#define WDGM_ERROR_INFO_API                           (STD_OFF)

/* Pre-compile option to get the initial mode */
#define WDGM_INIT_MODE                                ((WdgM_ModeType)0)

/* Total Number of Modes */
#define WDGM_TOTAL_MODES                              ((WdgM_ModeType)3)

/* Total Number of Supervised Entitys */
#define WDGM_TOTAL_SES                                ((WdgM_SupervisedEntityIndexType)2)

/* Maximum number of Alive Supervisions configured */
#define WDGM_MAX_ALIVESUPERVISIONS                    ((uint16)1)

/* Maximum Number of Reference Alive Supervisions cycle configured */
#define WDGM_MAX_ALIVE_SUPERVISION_REF_CYCLE          ((uint32)1000)

/* Timeout value for WdgM_DeInit process */
#define WDGM_DEINIT_TIMEOUT                           ((uint16)4000)

/* Total Number of CallerId configured */
#define WDGM_TOTAL_SET_MODE_API_CALLERS               ((uint8)1)

/* Total Number of Watchdog instances */
#define WDGM_TOTAL_WATCHDOG_INSTANCES                 ((uint8)1)


/*******************************************************************************
**                      Computed Macros                                       **
*******************************************************************************/
#define WDGM_GAAMODE0ALIVESUPERVISION_TOTAL_COUNT ((uint16)1)
#define WDGM_GAAMODE1ALIVESUPERVISION_TOTAL_COUNT ((uint16)1)
#define WDGM_GAAMODE2ALIVESUPERVISION_TOTAL_COUNT ((uint16)1)

#define WDGM_GAASE300CHECKPOINTS_TOTAL_COUNT ((uint16)3)
#define WDGM_GAASE400CHECKPOINTS_TOTAL_COUNT ((uint16)3)

#define WDGM_GAAMODE0ACTIVESE_TOTAL_COUNT ((uint16)1)
#define WDGM_GAAMODE1ACTIVESE_TOTAL_COUNT ((uint16)1)
#define WDGM_GAAMODE2ACTIVESE_TOTAL_COUNT ((uint16)1)

#define WDGM_GAAMODE0TRIGGER_TOTAL_COUNT ((uint8)1)
#define WDGM_GAAMODE1TRIGGER_TOTAL_COUNT ((uint8)1)
#define WDGM_GAAMODE2TRIGGER_TOTAL_COUNT ((uint8)1)


/*******************************************************************************
**                      Configuration Set Handles                             **
*******************************************************************************/
#define WdgMConf_WdgMMode_WdgMMode0 ((WdgM_ModeType)0)
#define WdgMConf_WdgMMode_WdgMMode1 ((WdgM_ModeType)1)
#define WdgMConf_WdgMMode_WdgMMode2 ((WdgM_ModeType)2)

#define WdgMConf_WdgMSupervisedEntity_SE_Init             \
  ((WdgM_SupervisedEntityIdType)300)
#define WdgMConf_WdgMSupervisedEntity_SE_WdgMTest         \
  ((WdgM_SupervisedEntityIdType)400)

#define WdgMConf_WdgMWatchdog_WdgMWatchdog_Int             (Watchdog_Int)

#define WdgMConf_WdgMCheckpoint_CP_Init_AS0 ((WdgM_CheckpointIdType)0)
#define WdgMConf_WdgMCheckpoint_CP_Init_ILS_0 ((WdgM_CheckpointIdType)1)
#define WdgMConf_WdgMCheckpoint_CP_Init_ILS_1 ((WdgM_CheckpointIdType)2)

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

#endif /* WDGM_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
