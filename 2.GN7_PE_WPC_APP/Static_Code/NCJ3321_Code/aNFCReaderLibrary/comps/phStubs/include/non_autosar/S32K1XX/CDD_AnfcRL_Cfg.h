/**
*   @file    CDD_AnfcRL_Cfg.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AnfcRL
*   @details This header file includes all the exported API for the Anfc Reader Library.
*
*   @addtogroup ANFCConfigAutosar ANFC Configuration for AUTOSAR
*   @{
*   @ingroup    ANFCConfiguration
*   @brief      AUTOSAR AnfcRL - Brief file description about configuration of AUTOSAR (one line).
*   @details    This component defines the NFC configuration.
*/


/*==================================================================================================
*   Project              : AUTOSAR 4.3 ANFC
*   Platform             : ARM
*   Peripheral           : NCX3320
*   Dependencies         : Base Dem Dio EcuM Gpt Icu Mcl Mcu Port Resource Spi
*
*   Autosar Version      : 4.3.1
*   Autosar Revision     : ASR_REL_4_3_REV_0001
*   Autosar Conf.Variant :
*   SW Version           : 1.0.0
*   Build Version        : S32K14X_S32K144_ANFC_Reader_Lib_1_0_20210909
*
*   Copyright 2016-2022 NXP
*
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/

#ifndef CDD_ANFCRL_CFG_H
#define CDD_ANFCRL_CFG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           CDD_AnfcRL_Cfg.h
* @implements     DESIGN001, DESIGN002
*/
#define ANFCRL_CFG_VENDOR_ID                    43
#define ANFCRL_CFG_MODULE_ID                    255
#define ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION     4
#define ANFCRL_CFG_AR_RELEASE_MINOR_VERSION     3
#define ANFCRL_CFG_AR_RELEASE_REVISION_VERSION  1
#define ANFCRL_CFG_SW_MAJOR_VERSION             1
#define ANFCRL_CFG_SW_MINOR_VERSION             0
#define ANFCRL_CFG_SW_PATCH_VERSION             0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/


/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* @brief   Precompile Support On.
* @details VARIANT-PRE-COMPILE: Only parameters with "Pre-compile time"
*           configuration are allowed in this variant.
*
* @api
*/
#define ANFCRL_PRECOMPILE_SUPPORT                                        (STD_ON)

/**
* @brief   Switches the Upper layer Logging feature ON or OFF.
*
* @api
*/
#define ANFCRL_LOG_ENABLE                                                (STD_ON)

/**
* @brief   Switches the Discovery loop component ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_AC_DISC_LOOP_ENABLE                                  (STD_ON)

/**
* @brief   Switches the protocol Iso14443-4 ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_ISO14443P4_ENABLE                                (STD_ON)

/**
* @brief   Switches the protocol Iso14443-4a ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_ISO14443P4A_ENABLE                               (STD_ON)

/**
* @brief   Switches the protocol Iso14443-3a ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_ISO14443P3A_ENABLE                               (STD_ON)

/**
* @brief   Switches the protocol Iso14443-3b ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_ISO14443P3B_ENABLE                               (STD_ON)

/**
* @brief   Switches the protocol Felica ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_FELICA_ENABLE                                    (STD_ON)

/**
* @brief   Switches the protocol Iso15693 ON or OFF.
*
* @api
*/
#define ANFCRL_COMP_PAL_SLI15693_ENABLE                                  (STD_ON)

/**
* @brief   Switches the LPCD feature ON or OFF.
*
* @api
*/
#define ANFCRL_LPCD_ENABLE                                               (STD_ON)

/**
* @brief   Value used to enable/disable the feature,
*          Wake-up from LPCD mode on external RF field
*/
#define ANFCRL_LPCD_EXT_RF_WAKEUP                                        (STD_ON)

/**
* @brief   Value used for Wake-up counter in msecs
*          i.e. after this amount of time IC will wakes up
*          from standby during calibration.
*/
#define ANFCRL_LPCD_WAKEUP_CALIB                                         5U 

/**
* @brief   Value used for Wake-up counter in msecs
*          i.e. after this amount of time IC will wakes up
*          from standby during LPCD or ULPC.
*/
#define ANFCRL_LPCD_WAKEUP_PW_DOWN                                       100U 

/**
* @brief   Maximum cards supported per technologies in passive poll mode.
*/
#define ANFCRL_MAX_CARDS_SUPPORTED                                       3U

/**
* @brief   Maximum cards supported per vicinity technologies
*          in passive poll mode.
*/
#define ANFCRL_MAX_VINCINITY_CARDS_SUPPORTED                             3U

/**
* @brief   LPCD RFON time(T3) in micro-seconds configured by application for Ncx3320.
*
*/
#define ANFCRL_LPCD_RFON_TIME                                            56U

/**
* @brief   Define which NFC front-end is used
*
*/
#define ANFCRL_HAL_HW_DEVICE_NCX3320

/**
*
* @brief   NCx3321 have 2 LPCD mode. Select LPCD (normal)
*          or ULPCD (power save) mode for LPCD.
*/
#define ANFCRL_MODE_ADVANCED_LPCD

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/


/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/* typedef struct
{
  uint32 AnfcRL_TimerFrequency;
  Gpt_ChannelType AnfcRL_GptChannel;
  Spi_ChannelType AnfcRL_SpiChannel;
  Spi_SequenceType AnfcRL_SpiSequence;
  Spi_JobType AnfcRL_SpiJob;
  Dio_ChannelType AnfcRL_DioChannelCS;
  Dio_ChannelType AnfcRL_DioChannelIRQ;
  Dio_ChannelType AnfcRL_DioChannelRST;
  Icu_ChannelType AnfcRL_IcuIRQ;

} AnfcRL_ConfigType;
 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/* extern CONST(AnfcRL_ConfigType, ANFC_CONST) ANFCLIB_PCConfig; */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

#endif /*CDD_ANFCRL_CFG_H*/

/** @} */
