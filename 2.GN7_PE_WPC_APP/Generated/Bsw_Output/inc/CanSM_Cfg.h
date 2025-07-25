/*******************************************************************************
**  FILE-NAME: CanSM_Cfg.h                                                    **
**                                                                            **
**  MODULE-NAME: AUTOSAR CAN State Manager Module                             **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **                                                                            **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.12.11                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/

/*
 * INPUT FILE:    Configuration\ECU\Ecud_CanIf.arxml
 *                Configuration\ECU\Ecud_CanSM.arxml
 *                Configuration\ECU\Ecud_CanTrcv.arxml
 *                Configuration\ECU\Ecud_ComM.arxml
 *                Configuration\ECU\Ecud_Dem.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef CANSM_CFG_H
#define CANSM_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
/* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> Necessary in logic */
#include "Platform_Types.h"


/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/
#define CANSM_CFG_AR_RELEASE_MAJOR_VERSION                 (4)
#define CANSM_CFG_AR_RELEASE_MINOR_VERSION                 (0)
#define CANSM_CFG_AR_RELEASE_REVISION_VERSION              (3)
#define CANSM_CFG_SW_MAJOR_VERSION                         (1)
#define CANSM_CFG_SW_MINOR_VERSION                         (12)
#define CANSM_CFG_SW_PATCH_VERSION                         (10)

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define CANSM_AR_RELEASE_MAJOR_VERSION                     (4)
#define CANSM_AR_RELEASE_MINOR_VERSION                     (0)
#define CANSM_AR_RELEASE_REVISION_VERSION                  (3)
#define CANSM_SW_MAJOR_VERSION                             (1)
#define CANSM_SW_MINOR_VERSION                             (12)
#define CANSM_SW_PATCH_VERSION                             (10)
#define CANSM_VENDOR_ID                                    ((uint16)76)
#define CANSM_MODULE_ID                                    ((uint16)140)

/*******************************************************************************
**                      Pre-Compile Options                                   **
*******************************************************************************/

/*  */
#define CANSM_MODEREQ_REPEAT_TIME           (6)

/* Pre-compile option for Development error detection */
#define CANSM_DEV_ERROR_DETECT              (STD_ON)

/* Pre-compile option for CanSM Version Info API */
#define CANSM_VERSION_INFO_API              (STD_OFF)

/* Pre-compile option for Development error detection */
#define CANSM_CHANGE_BAUDRATE_API           (STD_OFF)

/* Pre-Compile option shall be used to Enable/Disable PN mode */
#define CANSM_PN_AVAILABILITY               (STD_OFF)

/* Pre-compile option for CanSM Transreceiver support */
#define CANSM_CANTRCV_SUPPORT               (STD_ON)

/* Pre-compile option for Enabling/Disabling Polling mode */
#define CANSM_BOR_TX_CONFIRMATION_POLLING   (STD_OFF)

/* Pre-compile option for Bus off recovery support */
#define CANSM_BUSOFF_RECOVERY_MACRO_SUPPORT (STD_OFF)

/* Pre-compile option for bor counter support */
#define CANSM_BOR_COUNTER_MACRO_SUPPORT     (STD_OFF)

/* Pre-compile option for single network channel */
#define CANSM_SINGLE_NW_CHANNEL             (STD_OFF)

/* Pre-compile option for single controller channel */
#define CANSM_SINGLE_CNTRL_CHANNEL          (STD_ON)

/*  Pre-Compile option for DemStatus */
#define CANSM_DEM_STATUS                    (STD_ON)

/* Pre-compile option for CanSM no of networks */
#define CANSM_NUMBER_OF_NETWORKS            (2)

/* Pre-compile option for CanSM Highest Transceiver Channel Id */
#define CANSM_LAST_TRANSCEIVER_HANDLE       (1)

/* Pre-compile option for CanSM last network handle */
#define CANSM_LAST_NETWORK_HANDLE           (1)

/* Pre-compile option for the biggest CanIfControllerId configured in CanSM Configurations */
#define CANSM_LAST_CONTROLLER_HANDLE        (1)

/* Pre-compile option for the number of networks per each cfg */
#define CANSM_NETWRKS_PERCFG                (2)

/* Pre-compile option for the number of CanSM Configurations */
#define CANSM_NUMBER_OF_CONFIGURATION       (1)

/* Pre-compile option for the number of CanSMControllers in all configurations */
#define CANSM_NUMBER_OF_STATIC_CONTROLLER   (2)

/* Pre-compile option if given configuration is for Post-Build */
#define CANSM_POST_BUILD                    (STD_OFF)

/* Pre-compile option for the number of static networks */
#define CANSM_NUMBER_OF_STATIC_NETWORKS     (2)

/* Pre-compile option for checking invalid network exists in internal network */
#define CANSM_INVALID_NW_IN_INTERNAL_NW     (STD_OFF)

/* Pre-compile option for checking timeout callout Function exists */
#define CANSM_TIMEOUT_CALLOUT_SUPPORT       (STD_OFF)



/*******************************************************************************
**                      Type Definition                                       **
*******************************************************************************/

/* Type definition for CanSM_BusOffCntType */
typedef uint8 CanSM_BusOffCntType;

/* Type definition for CanSM_TimerType */
typedef uint16 CanSM_TimerType;



/*******************************************************************************
**                      Configuration Sets                                    **
*******************************************************************************/

#define CanSMConfiguration CanSM_GaaConfig[0]




#endif /* #ifndef CANSM_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

