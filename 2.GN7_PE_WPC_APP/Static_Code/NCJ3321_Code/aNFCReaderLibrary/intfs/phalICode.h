/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2021
 * All rights reserved.
 *
 * Disclaimer
 * 1. The NXP Software/Source Code is provided to Licensee "AS IS" without any warranties of any kind.
 * NXP makes no warranties to Licensee and shall not indemnify Licensee or hold it harmless for any
 * reason related to the NXP Software/Source Code or otherwise be liable to the NXP customer. The NXP
 * customer acknowledges and agrees that the NXP Software/Source Code is provided AS-IS and accepts
 * all risks of utilizing the NXP Software under the conditions set forth according to this disclaimer.
 *
 * 2. NXP EXPRESSLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NON-INFRINGEMENT OF
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUSTOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGED TO HAVE RESULTED FROM ANY DEFECT, ERROR OR OMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPECIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RELATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGES.
 *
 * 3. NXP reserves the right to make changes to the NXP Software/Source code any time, also without
 * informing customer.
 *
 * 4. Licensee agrees to indemnify and hold harmless NXP and its affiliated companies from and against
 * any claims, suits, losses, damages, liabilities, costs and expenses (including reasonable
 * attorney's fees) resulting from Licensee's and/or Licensee customer's/licensee's use of the NXP
 * Software/Source Code.
 *******************************************************************************/
/**
*   @file    phalICode.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlICode - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalICode ICode
*   @ingroup phalApplication
*   @{
*/
/*==================================================================================================
*   Project              : Anfc Reader Library
*   Platform             : ARM
*   Peripheral           : NCX3320
*   Dependencies         : Driver modules
*
*   Build Version        : S32K14X_S32K144_ANFC_Reader_Lib_1_0_20240401
*
*   Copyright 2016-2023 NXP
*
==================================================================================================*/
/*==================================================================================================
==================================================================================================*/
#ifndef PHALICODE_H
#define PHALICODE_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status.h>
#include <CDD_AnfcRL_Cfg.h>
#include "phhalHw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalICode.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALICODE_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHALICODE_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHALICODE_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHALICODE_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHALICODE_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHALICODE_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALICODE_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALICODE_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALICODE_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalICode.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALICODE_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALICODE_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALICODE_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalICode.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALICODE_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALICODE_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALICODE_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalICode.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHAL_ICODE_SW
/** \defgroup phalICode_Sw Component : Software
 * \ingroup phalICode
 * \brief This component implements the commands of ICode products 
 * @{
 */
#define PHAL_ICODE_SW_ID                                                0x01U   /**< ID for ICode Software layer. */

/**
 * end of group phalICode_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHAL_ICODE_SW */

#ifdef NXPBUILD__PHAL_ICODE

/** \defgroup phalICode ICode
 * \ingroup phalApplication
 * \brief This component implements the commands of ICode products.
 * @{
 */
 
/**
* \name ICode Block Size.
*/
/* @{ */
#define PHAL_ICODE_BLOCK_SIZE                                               4U  /**< Macro to represent the ICode block size. */
/* @} */

/** \defgroup phalICode_Generic Generic
 * \brief This component implements the mandatory commands of ICode products.
 * @{
 */

/**
* \name Response error codes according to ISO15693 specification. 
*/
/* @{ */
#define PHAL_ICODE_RESP_ERR_COMMAND_NOT_SUPPORTED                       0x01U   /**< The command is not supported, i.e. the request code is not recognized. */
#define PHAL_ICODE_RESP_ERR_COMMAND_NOT_RECOGNIZED                      0x02U   /**< The command is not recognized, for example: a format error occurred. */
#define PHAL_ICODE_RESP_ERR_COMMAND_OPTION_NOT_SUPPORTED                0x03U   /**< The command option is not supported. */
#define PHAL_ICODE_RESP_ERR_NO_INFORMATION                              0x0FU   /**< Error with no information given or a specific error code is not supported. */
#define PHAL_ICODE_RESP_ERR_BLOCK_NOT_AVAILABLE                         0x10U   /**< The specified block is not available (doesn't exist). */
#define PHAL_ICODE_RESP_ERR_BLOCK_LOCKED                                0x11U   /**< The specified block is already locked and thus cannot be locked again. */
#define PHAL_ICODE_RESP_ERR_CONTENT_CHANGE_FAILURE                      0x12U   /**< The specified block is locked and its content cannot be changed. */
#define PHAL_ICODE_RESP_ERR_BLOCK_PROGRAMMING_FAILURE                   0x13U   /**< The specified block was not successfully programmed. */
#define PHAL_ICODE_RESP_ERR_BLOCK_NOT_LOCKED                            0x14U   /**< The specified block was not successfully locked. */
#define PHAL_ICODE_RESP_ERR_BLOCK_PROTECTED                             0x15U   /**< The specified block is protected. */
#define PHAL_ICODE_RESP_ERR_GENERIC_CRYPTO_ERROR                        0x40U   /**< Generic crypto graphic error. */
/* @} */

/**
* \name Custom error codes for ISO15693 response code. 
*/
/* @{ */
#define PHAL_ICODE_ERR_CUSTOM_COMMANDS_ERROR        ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U)  /**< Custom commands Error codes. */
#define PHAL_ICODE_ERR_COMMAND_NOT_SUPPORTED        ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 1U)  /**< The command is not supported, i.e. the request code is not recognized. */
#define PHAL_ICODE_ERR_COMMAND_NOT_RECOGNIZED       ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 2U)  /**< The command is not recognized, for example: a format error occurred. */
#define PHAL_ICODE_ERR_COMMAND_OPTION_NOT_SUPPORTED ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 3U)  /**< The command option is not supported. */
#define PHAL_ICODE_ERR_NO_INFORMATION               ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 4U)  /**< Error with no information given or a specific error code is not supported. */
#define PHAL_ICODE_ERR_BLOCK_NOT_AVAILABLE          ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 5U)  /**< The specified block is not available (doesn't exist). */
#define PHAL_ICODE_ERR_BLOCK_LOCKED                 ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 6U)  /**< The specified block is already locked and thus cannot be locked again. */
#define PHAL_ICODE_ERR_CONTENT_CHANGE_FAILURE       ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 7U)  /**< The specified block is locked and its content cannot be changed. */
#define PHAL_ICODE_ERR_BLOCK_PROGRAMMING_FAILURE    ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 8U)  /**< The specified block was not successfully programmed. */
#define PHAL_ICODE_ERR_BLOCK_NOT_LOCKED             ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 9U)  /**< The specified block was not successfully locked. */
#define PHAL_ICODE_ERR_BLOCK_PROTECTED              ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 10U) /**< The specified block is protected. */
#define PHAL_ICODE_ERR_GENERIC_CRYPTO_ERROR         ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 11U) /**< Generic cryptographic error. */
/* @} */

/**
* \name Request Flags according to ISO15693 specification. 
*/
/* @{ */
#define PHAL_ICODE_FLAG_TWO_SUB_CARRIERS                                0x01U   /**< Sub-carrier_flag. If set two sub-carriers shall be used (VICC to VCD). Else a single sub-carrier
 *   frequency shall be used by the VICC.
 */
#define PHAL_ICODE_FLAG_DATA_RATE                                       0x02U   /**< Data_rate_flag. If set high data rate shall be used (VICC to VCD). Else low data rate shall
 *   be used.
 */
#define PHAL_ICODE_FLAG_INVENTORY                                       0x04U   /**< Inventory_flag. Shall be set for inventory request.
 *   If set flags 5 to 8 meaning is as per #PHAL_ICODE_FLAG_AFI, #PHAL_ICODE_FLAG_NBSLOTS and
 *   #PHAL_ICODE_FLAG_OPTION flags.
 *   If not set flags 5 to 8 meaning is as per #PHAL_ICODE_FLAG_SELECTED, #PHAL_ICODE_FLAG_ADDRESSED
 *   and #PHAL_ICODE_FLAG_OPTION flags.
 */
#define PHAL_ICODE_FLAG_PROTOCOL_EXTENSION                              0x08U   /**< Protocol_Extension_flag. If set protocol format is extended. Reserved for future use. No supported
 *   in current version.
 */
#define PHAL_ICODE_FLAG_SELECTED                                        0x10U   /**< Select_flag. If set only VICC in selected state shall respond. The Address_flag #PHAL_ICODE_FLAG_ADDRESSED
 *   shall be set to 0 and the UID field will not be included in the request. If not set Request shall be executed
 *   by any VICC according to the setting of Address_flag #PHAL_ICODE_FLAG_ADDRESSED.
 */
#define PHAL_ICODE_FLAG_AFI                                             0x10U   /**< AFI_flag. If set AFI field is present in request. If not set AFI field is not present in request. */
#define PHAL_ICODE_FLAG_ADDRESSED                                       0x20U   /**< Address_flag. If set request is addressed. UID field is included in request. It shall be executed only by the
 *   VICC whose UID matches the UID specified in the request. If not set request is not addressed. UID field is not
 *   included in request. It shall be executed by any VICC.
 */
#define PHAL_ICODE_FLAG_NBSLOTS                                         0x20U   /**< Nb_slots_flag. If set Use 1 slot instead of 16 slots for inventory. If not set use 16 slots. */
#define PHAL_ICODE_FLAG_OPTION                                          0x40U   /**< Option_flag. Meaning is defined by the command description. It shall be set to 0 if not otherwise defined by
 *   the command.
 */
#define PHAL_ICODE_FLAG_FAST_DATA_RATE                                  0x80U   /**< RFU as per ISO15693 but this flag should be utilized for NTAG5 I2C product only. This flag is used to
 *   set the hardware RX Datarate to Fast_High (~53 kbps) for Fast_Low (~13 kbps). Also to note that this flag
 *   should not be used for any Inventory commands. Currently the support is for \ref phalICode_FastReadMultipleBlocks
 *   and \ref phalICode_ExtendedFastReadMultipleBlocks.
 */
/* @} */

/**
* \name Options 
*/
/* @{ */
#define PHAL_ICODE_OPTION_OFF                           PH_OFF                  /**< Option Bit is cleared. */
#define PHAL_ICODE_OPTION_ON                            PH_ON                   /**< Option Bit is set. */
#define PHAL_ICODE_OPTION_DEFAULT                       PHAL_ICODE_OPTION_OFF   /**< Default Option. This flag represents #PHAL_ICODE_OPTION_OFF value. */
/*@}*/

/**
* \name AuthenticateMAM PurposeMAM2 options. 
*/
/* @{ */
#define PHAL_ICODE_PURPOSE_MAM2_DISABLE_PRIVACY_HF_RESET                0x08U   /**< Option to indicate PurposeMAM2 value as Privacy disable until HF reset. */
#define PHAL_ICODE_PURPOSE_MAM2_ENABLE_PRIVACY                          0x09U   /**< Option to indicate PurposeMAM2 value as Privacy enable. */
#define PHAL_ICODE_PURPOSE_MAM2_DISABLE_PRIVACY                         0x0AU   /**< Option to indicate PurposeMAM2 value as Privacy disable. */
#define PHAL_ICODE_PURPOSE_MAM2_DESTROY                                 0x0BU   /**< Option to indicate PurposeMAM2 value as Destroy. */
/* @} */

/**
* \name Extended Get System Information parameter request fields. 
*/
/* @{ */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_DEFAULT                          0x10U    /**< Option to indicate the default value of VICC response with memory addressing. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_DSFID                            0x01U    /**< Option to indicate the return of DSFID information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_AFI                              0x02U    /**< Option to indicate the return of AFI information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_VICC_MEM_SIZE                    0x04U    /**< Option to indicate the return of VICC memory size information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_IC_REFERENCE                     0x08U    /**< Option to indicate the return of IC Reference information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_MOI                              0x10U    /**< Option to indicate the return of MOI (memory addressing) information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_COMMAND_LIST                     0x20U    /**< Option to indicate the return of Supported Command List information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_CSI_INFORMATION                  0x40U    /**< Option to indicate the return of CSI information from VICC. */
#define PHAL_ICODE_INFO_PARAMS_REQUEST_EXT_GET_SYS_INFO                 0x80U    /**< Option to indicate the return of Two byte length of Ext Get System information from VICC. */
/* @} */

/**
* \name ReadBuffer response verification options. 
*/
/* @{ */
#define PHAL_ICODE_READ_BUFFER_VERIFY_OFF                               PH_OFF  /**< Option to return the received response from VICC without verification and decryption. */
#define PHAL_ICODE_READ_BUFFER_VERIFY_ON                                PH_ON   /**< Option to return the received response from VICC with verification and decryption. */
/* @} */

/**
* \name InventoryRead Extended options. 
*/
/* @{ */
#define PHAL_ICODE_INVENTORY_READ_EXT_DEFAULT                           0x00U    /**< Default option for InventoryReadExtended command. */
#define PHAL_ICODE_INVENTORY_READ_EXT_EAS_MODE                          0x01U    /**< Option to indicate that the VICC with EAS enabled will respond. */
#define PHAL_ICODE_INVENTORY_READ_EXT_UID_MODE                          0x02U    /**< Option to indicate complete UID transmission. */
#define PHAL_ICODE_INVENTORY_READ_EXT_CID_COMPARE                       0x04U    /**< Option to indicate transmission of 16 bit CID and only tags with the same CID will respond. */
#define PHAL_ICODE_INVENTORY_READ_EXT_CID_RESPONSE                      0x08U    /**< Option to indicate transmission of Custom ID. */
#define PHAL_ICODE_INVENTORY_READ_EXT_SKIP_DATA                         0x10U    /**< Option to indicate No user memory data are requested from the tag, first block number byte and
 *   number of blocks byte shall not be transmitted in the command. */
#define PHAL_ICODE_INVENTORY_READ_EXT_QUIET                             0x20U    /**< Option to indicate the state change to Quiet after response. */
#define PHAL_ICODE_INVENTORY_READ_EXT_PERSIST_QUIET                     0x40U    /**< Option to indicate the state change to Persistent Quiet after response. */
#define PHAL_ICODE_INVENTORY_READ_EXT_PERSIST_QUIET_RESPONSE            0x60U    /**< Option to indicate that tags in the PERSISTENT QUIET state will respond to the command. */
/* @} */

/**
* \name SetPassword Password Identifier options. 
*/
/* @{ */
#define PHAL_ICODE_SET_PASSWORD_READ                                    0x01U    /**< Option to indicate Password Identifier as Read. */
#define PHAL_ICODE_SET_PASSWORD_WRITE                                   0x02U    /**< Option to indicate Password Identifier as Write. */
#define PHAL_ICODE_SET_PASSWORD_PRIVACY                                 0x04U    /**< Option to indicate Password Identifier as Privacy. */
#define PHAL_ICODE_SET_PASSWORD_DESTROY                                 0x08U    /**< Option to indicate Password Identifier as Destroy. */
#define PHAL_ICODE_SET_PASSWORD_EAS                                     0x10U    /**< Option to indicate Password Identifier as EAS. */
/* @} */

/**
* \name ProtectPage Protection Status options for the ICode products which do not describe the pages as High and Low. 
*/
/* @{ */

#define PHAL_ICODE_PROTECT_PAGE_PUBLIC                                  0x00U	/**< Option to indicate protection status as public. */
#define PHAL_ICODE_PROTECT_PAGE_READ_WRITE_READ_PASSWORD                0x01U	/**< Option to indicate protection status as
																				 *      \arg 32-bit Password Protection: Read and Write protection by Read password.
																				 *      \arg 64-bit Password Protection: Read and Write protection by Read plus Write password.
																				 *      \arg ICode DNA or other products that supports AES authentication, Mutual authentication
																				 *           with a key with read privilege is required.
																				 */
#define PHAL_ICODE_PROTECT_PAGE_WRITE_PASSWORD                          0x10U   /**< Option to indicate protection status as
																				 *      \arg 32-bit Password Protection: Write protection by Write password.
																				 *      \arg 64-bit Password Protection: Write protection by Read plus Write password.
																				 *      \arg ICode DNA or other products that supports AES authentication, Mutual authentication
																				 *           with a key with write privilege is required.
																				 */
#define PHAL_ICODE_PROTECT_PAGE_READ_WRITE_PASSWORD_SEPERATE            0x11U   /**< Option to indicate protection status as
																				 *      \arg 32-bit Password Protection: Read protected by Read and Write protection by Write password.
																				 *      \arg 64-bit Password Protection: Read and Write protection by Read plus Write password.
																				 *      \arg ICode DNA or other products that supports AES authentication, Mutual authentication
																				 *           with a key with read and write privileges is required.
																				 */
/* @} */

/**
* \name Extended Protection Status options for the ICode products which describes the pages as High and Low. 
*/
/* @{ */
#define PHAL_ICODE_PROTECT_PAGE_READ_LOW                                0x01U   /**< Option to indicate Read protection for Lower pages. */
#define PHAL_ICODE_PROTECT_PAGE_WRITE_LOW                               0x02U   /**< Option to indicate Write protection for Lower pages. */
#define PHAL_ICODE_PROTECT_PAGE_READ_HIGH                               0x10U   /**< Option to indicate Read protection for Higher pages. */
#define PHAL_ICODE_PROTECT_PAGE_WRITE_HIGH                              0x20U   /**< Option to indicate Write protection for Higher pages. */

/* @} */

/**
* \name ParameterRequest and ParameterSelect Bit-rate options. 
*/
/* @{ */
#define PHAL_ICODE_PARAMETERS_BITRATE_26KBPS_BOTH_DIRECTIONS            0x00U    /**< Option to indicate the 26kbps bit rate support in both directions. */
#define PHAL_ICODE_PARAMETERS_BITRATE_53KBPS_VCD_VICC                   0x01U    /**< Option to indicate the 53kbps bit rate support from VCD to VICC. */
#define PHAL_ICODE_PARAMETERS_BITRATE_106KBPS_VCD_VICC                  0x02U    /**< Option to indicate the 106kbps bit rate support from VCD to VICC. */
#define PHAL_ICODE_PARAMETERS_BITRATE_212KBPS_VCD_VICC                  0x04U    /**< Option to indicate the 212kbps bit rate support from VCD to VICC. */
#define PHAL_ICODE_PARAMETERS_BITRATE_53KBPS_VICC_VCD                   0x10U    /**< Option to indicate the 53kbps bit rate support from VICC to VCD. */
#define PHAL_ICODE_PARAMETERS_BITRATE_106KBPS_VICC_VCD                  0x20U    /**< Option to indicate the 106kbps bit rate support from VICC to VCD. */
#define PHAL_ICODE_PARAMETERS_BITRATE_212KBPS_VICC_VCD                  0x40U    /**< Option to indicate the 212kbps bit rate support from VICC to VCD. */
/* @} */

/**
* \name ParameterRequest and ParameterSelect Timing options. 
*/
/* @{ */
#define PHAL_ICODE_PARAMETERS_TIMING_320_9_US                           0x00U    /**< Option to indicate that VICC supports 320.9us timing only. */
#define PHAL_ICODE_PARAMETERS_TIMING_160_5_US                           0x01U    /**< Option to indicate that VICC supports 160.5us timing only. */
#define PHAL_ICODE_PARAMETERS_TIMING_80_2_US                            0x02U    /**< Option to indicate that VICC supports 80.2us timing only. */
#define PHAL_ICODE_PARAMETERS_TIMING_SAME_BOTH_DIRECTIONS               0x10U    /**< Option to indicate that same timing on both the direction is compulsory. */

/* @} */

/**
* \name GetConfig / SetConfig options. 
*/
/* @{ */
#define PHAL_ICODE_CONFIG_FLAGS                                         0x00U    /**< Option to Get / Set the Flags information. */
#define PHAL_ICODE_CONFIG_ADD_INFO                                      0x01U    /**< Option to Get the additional information. */
#define PHAL_ICODE_CONFIG_TIMEOUT_US                                    0x02U    /**< Option to Get the timeout value in milliseconds. */
#define PHAL_ICODE_CONFIG_TIMEOUT_MS                                    0x03U    /**< Option to Get the timeout value in microseconds. */
#define PHAL_ICODE_CONFIG_ENABLE_BUFFERING                              0x04U    /**< Option to Get / Set the buffering of response data to be enabled or disabled.
 *   By default this flag will be disabled.
 */
/* @} */

/**
* \name GetConfig / SetConfig value for #PHAL_ICODE_CONFIG_ENABLE_BUFFERING configuration. 
*/
/* @{ */
#define PHAL_ICODE_DISABLE                                              0x00U    /**< Option to disable the buffering of response data. */
#define PHAL_ICODE_ENABLE                                               0x01U    /**< Option to enable the buffering of response data. */
/* @} */

#define PHAL_ICODE_TIMEOUT_SHORT_US                                     324U    /**< Timeout T1 in us (ISO/IEC15693, 9.1.4.). */
#define PHAL_ICODE_TIMEOUT_LONG_US                                      20000U  /**< Extended timeout for some commands. */

/**
* \name Options for type of tags. 
*/
/* @{ */
#define PHAL_ICODE_TAG_TYPE_UNKNOWN                                     0xFFFFU  /**< Option to Get the tag type as Unknown. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLI                                   0x0001U  /**< Option to Get the tag type as ICode SLI. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLI_S                                 0x0002U  /**< Option to Get the tag type as ICode SLI-S. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLI_L                                 0x0003U  /**< Option to Get the tag type as ICode SLI-L. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLIX                                  0x5001U  /**< Option to Get the tag type as ICode SLIX. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLIX_S                                0x5002U  /**< Option to Get the tag type as ICode SLIX-S. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLIX_L                                0x5003U  /**< Option to Get the tag type as ICode SLIX-L. */
#define PHAL_ICODE_TAG_TYPE_ICODE_SLI_X2                                0x0801U  /**< Option to Get the tag type as ICode SLIX2. */
#define PHAL_ICODE_TAG_TYPE_ICODE_DNA                                   0x1801U  /**< Option to Get the tag type as ICode DNA. */
#define PHAL_ICODE_TAG_TYPE_ICODE_NTAG5_I2C                             0x5801U  /**< Option to Get the tag type as ICode NTAG5 I2C. */
/* @} */
/**
 * end of group phalICode_Generic
 * @}
 */

/** end of group phalICode ICode
 * @}
 */
#endif /* NXPBUILD__PHAL_ICODE */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_ICODE_SW

/** \addtogroup phalICode_Sw Component : Software
 * \ingroup phalICode
 * \brief This component implements the commands of ICode products 
 * @{
 */

/** \brief Parameter structure for Icode Software layer implementation. */
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId;                                                               /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams;                                              /**< Pointer to the parameter structure of the underlying palSli15693 layer. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams;                                                   /**< Pointer to the parameter structure of the underlying Crypto layer for encryption / Decryption. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams;                                                /**< Pointer to the parameter structure of the underlying Crypto layer for random number generation. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                                                 /**< Pointer to the parameter structure of the underlying Keystore layer. */
  VAR(uint8, ANFCRL_VAR) aRnd_Challenge[10];                                                 /**< 10 byte buffer to store the random number generated by Challenge command. */
  VAR(uint8, ANFCRL_VAR) bBuffering;                                                         /**< Enable or disable the data buffering. */
} phalICode_Sw_DataParams_t;

/**
 * end of group phalICode_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_ICODE_SW */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHAL_ICODE_SW
#define ANFCRL_START_SEC_CODE
#if ((PHALICODE_AR_RELEASE_MAJOR_VERSION == 4) && (PHALICODE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phalICode_Sw Component : Software
 * \ingroup phalICode
 * \brief This component implements the commands of ICode products 
 * @{
 */

/**
 * \brief Initialize this layer.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Sw_Init(
  P2VAR(phalICode_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                /**< [In] Pointer to this layers parameter structure. */
  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                                             /**< [In] Specifies the size of the data parameter structure. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams,                                          /**< [In] Pointer to the parameter structure of the underlying palSli15693 layer. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams,                                               /**< [In] Pointer to the parameter structure of the underlying Crypto layer for encryption / Decryption. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,                                            /**< [In] Pointer to the parameter structure of the underlying Crypto layer for random number generation. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams                                              /**< [In] Pointer to the parameter structure of the underlying Keystore layer. */
);

/**
 * end of group phalICode_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALICODE_AR_RELEASE_MAJOR_VERSION == 4) && (PHALICODE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHAL_ICODE_SW */

#ifdef NXPBUILD__PHAL_ICODE
/** \addtogroup phalICode ICode
 * \ingroup phalApplication
 * \brief This component implements the commands of ICode products.
 * @{
 */

/** \addtogroup phalICode_Generic Generic
 * \brief This component implements the mandatory commands of ICode products.
 * @{
 */
#ifdef  NXPRDLIB_REM_GEN_INTFS
#include "../comps/phalICode/src/Sw/phalICode_Sw.h"


#define phalICode_ReadSingleBlock(pDataParams, bOption, bBlockNo, ppData, pDataLen)  \
        phalICode_Sw_ReadSingleBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockNo, ppData, pDataLen)

#define phalICode_WriteSingleBlock(pDataParams, bOption, bBlockNo, pData, bDataLen)  \
        phalICode_Sw_WriteSingleBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockNo, pData, bDataLen)

#define phalICode_LockBlock(pDataParams, bOption, bBlockNo)  \
        phalICode_Sw_LockBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockNo)

#define phalICode_ReadMultipleBlocks(pDataParams, bOption, bBlockNo, bNumBlocks, pData,  pDataLen)  \
        phalICode_Sw_ReadMultipleBlocks((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockNo, bNumBlocks, pData,  pDataLen)


#define phalICode_WriteAFI(pDataParams, bOption, bAfi)  \
        phalICode_Sw_WriteAFI((phalICode_Sw_DataParams_t *)pDataParams, bOption, bAfi)

#define phalICode_LockAFI(pDataParams, bOption)  \
        phalICode_Sw_LockAFI((phalICode_Sw_DataParams_t *)pDataParams, bOption)

#define phalICode_WriteDSFID(pDataParams, bOption, bDsfid)  \
        phalICode_Sw_WriteDSFID((phalICode_Sw_DataParams_t *)pDataParams, bOption, bDsfid)

#define phalICode_LockDSFID(pDataParams, bOption)  \
        phalICode_Sw_LockDSFID((phalICode_Sw_DataParams_t *)pDataParams, bOption)

#define phalICode_GetSystemInformation(pDataParams, ppSystemInfo, pSystemInfoLen)  \
        phalICode_Sw_GetSystemInformation((phalICode_Sw_DataParams_t *)pDataParams, ppSystemInfo, pSystemInfoLen)

#define phalICode_GetMultipleBlockSecurityStatus(pDataParams, bBlockNo, bNoOfBlocks, pStatus, pStatusLen)  \
        phalICode_Sw_GetMultipleBlockSecurityStatus((phalICode_Sw_DataParams_t *)pDataParams, bBlockNo, bNoOfBlocks, pStatus, pStatusLen)

#define phalICode_FastReadMultipleBlocks(pDataParams, bOption, bBlockNo, bNumBlocks, pData, pDataLen)  \
        phalICode_Sw_FastReadMultipleBlocks((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockNo, bNumBlocks, pData, pDataLen)

#define phalICode_ExtendedReadSingleBlock(pDataParams, bOption, wBlockNo, ppData, pDataLen)  \
        phalICode_Sw_ExtendedReadSingleBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, wBlockNo, ppData, pDataLen)

#define phalICode_ExtendedWriteSingleBlock(pDataParams, bOption, wBlockNo, pData, bDataLen)  \
        phalICode_Sw_ExtendedWriteSingleBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, wBlockNo, pData, bDataLen)

#define phalICode_ExtendedLockBlock(pDataParams, bOption, wBlockNo)   \
        phalICode_Sw_ExtendedLockBlock((phalICode_Sw_DataParams_t *)pDataParams, bOption, wBlockNo)

#define phalICode_ExtendedReadMultipleBlocks(pDataParams, bOption, wBlockNo, wNumBlocks, pData, pDataLen)  \
        phalICode_Sw_ExtendedReadMultipleBlocks((phalICode_Sw_DataParams_t *)pDataParams, bOption, wBlockNo, wNumBlocks, pData, pDataLen)


#define phalICode_ExtendedGetSystemInformation(pDataParams, bInfoParams, ppSystemInfo, pSystemInfoLen) \
        phalICode_Sw_ExtendedGetSystemInformation((phalICode_Sw_DataParams_t *)pDataParams, bInfoParams, ppSystemInfo, pSystemInfoLen)

#define phalICode_ExtendedGetMultipleBlockSecurityStatus(pDataParams, wBlockNo, wNoOfBlocks, pStatus, pStatusLen) \
        phalICode_Sw_ExtendedGetMultipleBlockSecurityStatus((phalICode_Sw_DataParams_t *)pDataParams, wBlockNo, wNoOfBlocks, pStatus, pStatusLen)

#define phalICode_ExtendedFastReadMultipleBlocks(pDataParams, bOption, wBlockNo, wNumBlocks, pData, pDataLen) \
        phalICode_Sw_ExtendedFastReadMultipleBlocks((phalICode_Sw_DataParams_t *)pDataParams, bOption, wBlockNo, wNumBlocks, pData, pDataLen)


#define phalICode_SetEAS(pDataParams, bOption)  \
        phalICode_Sw_SetEAS((phalICode_Sw_DataParams_t *)pDataParams, bOption)

#define phalICode_ResetEAS(pDataParams, bOption) \
        phalICode_Sw_ResetEAS((phalICode_Sw_DataParams_t *)pDataParams, bOption)

#define phalICode_LockEAS(pDataParams, bOption) \
        phalICode_Sw_LockEAS((phalICode_Sw_DataParams_t *)pDataParams, bOption)

#define phalICode_EASAlarm(pDataParams, bOption, pEasIdValue, bEasIdMaskLen, ppEas, pEasLen) \
        phalICode_Sw_EASAlarm((phalICode_Sw_DataParams_t *)pDataParams, bOption, pEasIdValue, bEasIdMaskLen, ppEas, pEasLen)

#define phalICode_PasswordProtectEAS(pDataParams) \
        phalICode_Sw_PasswordProtectEAS((phalICode_Sw_DataParams_t *)pDataParams)

#define phalICode_PasswordProtectAFI(pDataParams) \
        phalICode_Sw_PasswordProtectAFI((phalICode_Sw_DataParams_t *)pDataParams)

#define phalICode_WriteEASID(pDataParams, pEasIdValue) \
        phalICode_Sw_WriteEASID((phalICode_Sw_DataParams_t *)pDataParams, pEasIdValue)

#define phalICode_ReadEPC(pDataParams, ppEpc, pEpcLen) \
        phalICode_Sw_ReadEPC((phalICode_Sw_DataParams_t *)pDataParams, ppEpc, pEpcLen)

#define phalICode_GetNXPSystemInformation(pDataParams, ppSystemInfo, pSystemInfoLen) \
        phalICode_Sw_GetNXPSystemInformation((phalICode_Sw_DataParams_t *)pDataParams, ppSystemInfo, pSystemInfoLen)


#define phalICode_GetRandomNumber(pDataParams, ppRnd, pRndLen) \
        phalICode_Sw_GetRandomNumber((phalICode_Sw_DataParams_t *)pDataParams, ppRnd, pRndLen)

#define phalICode_SetPassword(pDataParams, bPwdIdentifier, pXorPwd) \
        phalICode_Sw_SetPassword((phalICode_Sw_DataParams_t *)pDataParams, bPwdIdentifier, pXorPwd)


#define phalICode_WritePassword(pDataParams, bPwdIdentifier, pPwd) \
        phalICode_Sw_WritePassword((phalICode_Sw_DataParams_t *)pDataParams, bPwdIdentifier, pPwd)

#define phalICode_LockPassword(pDataParams, bPwdIdentifier) \
        phalICode_Sw_LockPassword((phalICode_Sw_DataParams_t *)pDataParams, bPwdIdentifier)

#define phalICode_ProtectPage(pDataParams, bPPAdd_PageNo, bProtectionStatus) \
        phalICode_Sw_ProtectPage((phalICode_Sw_DataParams_t *)pDataParams, bPPAdd_PageNo, bProtectionStatus)

#define phalICode_LockPageProtectionCondition(pDataParams, bPageNo) \
        phalICode_Sw_LockPageProtectionCondition((phalICode_Sw_DataParams_t *)pDataParams, bPageNo)

#define phalICode_GetMultipleBlockProtectionStatus(pDataParams, bBlockNo, bNoOfBlocks, pProtectionStates, pNumReceivedStates) \
        phalICode_Sw_GetMultipleBlockProtectionStatus((phalICode_Sw_DataParams_t *)pDataParams, bBlockNo, bNoOfBlocks, pProtectionStates, pNumReceivedStates)

#define phalICode_Destroy(pDataParams, pXorPwd) \
        phalICode_Sw_Destroy((phalICode_Sw_DataParams_t *)pDataParams, pXorPwd)

#define  phalICode_EnablePrivacy(pDataParams, pXorPwd) \
        phalICode_Sw_EnablePrivacy((phalICode_Sw_DataParams_t *)pDataParams, pXorPwd)

#define phalICode_64BitPasswordProtection(pDataParams) \
        phalICode_Sw_64BitPasswordProtection((phalICode_Sw_DataParams_t *)pDataParams)


#define phalICode_ReadSignature(pDataParams, ppSign, pSignLen) \
        phalICode_Sw_ReadSignature((phalICode_Sw_DataParams_t *)pDataParams, ppSign, pSignLen)

#define phalICode_ReadConfig(pDataParams, bBlockAddr, bNoOfBlocks, ppData, pDataLen) \
        phalICode_Sw_ReadConfig((phalICode_Sw_DataParams_t *)pDataParams, bBlockAddr, bNoOfBlocks, ppData, pDataLen)

#define phalICode_WriteConfig(pDataParams, bOption, bBlockAddr, pData) \
        phalICode_Sw_WriteConfig((phalICode_Sw_DataParams_t *)pDataParams, bOption, bBlockAddr, pData)

#define phalICode_PickRandomID(pDataParams) \
        phalICode_Sw_PickRandomID((phalICode_Sw_DataParams_t *)pDataParams)



#define phalICode_GetConfig(pDataParams, wConfig, pValue) \
        phalICode_Sw_GetConfig((phalICode_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#define  phalICode_SetConfig(pDataParams, wConfig, wValue) \
        phalICode_Sw_SetConfig((phalICode_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#define phalICode_GetTagType(pDataParams, pTagType) \
        phalICode_Sw_GetTagType((phalICode_Sw_DataParams_t *)pDataParams, pTagType)


#else

#define ANFCRL_START_SEC_CODE
#if ((PHALICODE_AR_RELEASE_MAJOR_VERSION == 4) && (PHALICODE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
/** \defgroup phalICode_Optional Commands_Optional
 * \brief This component implements the optional commands of ICode products.
 * @{
 */

/**
 * \brief Performs a Single block read command. When receiving the Read Single Block command, the VICC shall read the requested block and send
 * back its value in the response. If the Option_flag (bOption = #PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value. If it is not set (bOption = #PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ReadSingleBlock(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, block Security Status information is not available. Only block data
		 *           is available. Format will be 4 byte data
		 *      \arg If #PHAL_ICODE_OPTION_ON, both block Security Status information and Block Data is available.
		 *           Format of the response will be Status, 4 byte data
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] Block number from where the data to be read. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,                                                      /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a Single block write command. When receiving the Write single block command, the VICC shall write the requested block with the
 * data contained in the request and report the success of the operation in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON)
 * is set in the request, the VICC shall wait for the reception of an EOF from the VCD and upon such reception shall return its response.
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WriteSingleBlock(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the write operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] Block number to which the data should be written. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Information to be written to the specified block number. */
    VAR(uint8, ANFCRL_VAR) bDataLen                                                        /**< [In] Number of bytes to be written. */
);

/**
 * \brief Performs a Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested block. If the
 * Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the VCD
 * and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockBlock(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the lock operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bBlockNo                                                        /**< [In] Block number which should be locked. */
);

/**
 * \brief Performs a Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s) and send
 * back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block
 * security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall
 * return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Data buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, Block Security Status information is not available. Only block data
		 *           is available. Format will be 4 byte data 1, 4 byte data 2, 4 byte data N
		 *      \arg If #PHAL_ICODE_OPTION_ON, both Block Security Status information and Block Data is available.
		 *           Format of the response will be Status 1, 4 byte data 1, Status 2, 4 byte data 2, Status N,
		 *           4 byte data N
		 *           Where 1, 2 N is the block number.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] Block number from where the data to be read. */
    VAR(uint8, ANFCRL_VAR) bNumBlocks,                                                     /**< [In] Total number of block to read. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes. */
);


/**
 * \brief Performs a WriteAFI command. When receiving the Write AFI request, the VICC shall write the AFI value into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the write operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WriteAFI(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the write operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bAfi                                                            /**< [In] Value of Application Family Identifier. */
);

/**
 * \brief Performs a LockAFI command. When receiving the Lock AFI request, the VICC shall lock the AFI value permanently into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us)
 * with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockAFI(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                                         /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the lock operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
);

/**
 * \brief Performs WriteDSFID command. When receiving the Write DSFID request, the VICC shall write the DSFID value into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF
 * from the VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return its response when it has completed the write operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a
 * multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the
 * EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WriteDSFID(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the write operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint8, ANFCRL_VAR) bDsfid                                                          /**< [In] Value of DSFID (data storage format identifier). */
);

/**
 * \brief Performs LockDSFID command. When receiving the Lock DSFID request, the VICC shall lock the DSFID value permanently into its memory.
 * If the  Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us)
 * with a total tolerance of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockDSFID(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                                         /**< [In] Option flag;
		*      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the lock operation
		*           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		*           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		*      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		*           shall return its response.
		*      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		*/
);

/**
 * \brief Performs GetSystemInformation command. This command allows for retrieving the system information value from the VICC.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetSystemInformation(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo,                                                /**< [Out] The system information of the VICC. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen                                               /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs GetMultipleBlockSecurityStatus. When receiving the Get multiple block security status command, the VICC
 * shall send back the block security status.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Status buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetMultipleBlockSecurityStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] Block number for which the status should be returned. */
    VAR(uint8, ANFCRL_VAR) bNoOfBlocks,                                                    /**< [In] Number of blocks to be used for returning the status. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,                                                      /**< [Out] The status of the block number mentioned in bBlockNo until bNumBlocks. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen                                                   /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the
 * block security status, followed by the block value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC
 * shall return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Data buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_FastReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		*      \arg If #PHAL_ICODE_OPTION_OFF, Block Security Status information is not available. Only block data
		*           is available. Format will be 4 byte data 1, 4 byte data 2, 4 byte data N
		*      \arg If #PHAL_ICODE_OPTION_ON, both Block Security Status information and Block Data is available.
		*           Format of the response will be Status 1, 4 byte data 1, Status 2, 4 byte data 2,  Status N,
		*           4 byte data N
		*           Where 1, 2  N is the block number.
		*      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		*/
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] Block number from where the data to be read. */
    VAR(uint8, ANFCRL_VAR) bNumBlocks,                                                     /**< [In] Total number of block to read. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a Extended Single block read command. When receiving the Extended Read Single Block command, the VICC shall read the
 * requested block and send back its value in the response. If a VICC supports Extended read single block command, it shall also support
 * Read single block command for the first 256 blocks of memory. If the Option_flag (bOption = #PHAL_ICODE_OPTION_ON) is set in the request,
 * the VICC shall return the block security status, followed by the block value. If it is not set (bOption = #PHAL_ICODE_OPTION_OFF), the
 * VICC shall return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedReadSingleBlock(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, block Security Status information is not available. Only block data
		 *           is available. Format will be 4 byte data
		 *      \arg If #PHAL_ICODE_OPTION_ON, both block Security Status information and Block Data is available.
		 *           Format of the response will be Status, 4 byte data
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint16, ANFCRL_VAR) wBlockNo,                                                      /**< [In] Block number from where the data to be read. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,                                                      /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a Extended Single block Write command. When receiving the Extended write single block command, the VICC shall write the
 * requested block with the data contained in the request and report the success of the operation in the response. If a VICC supports
 * Extended write single block command, it shall also support Write single block command for the first 256 blocks of memory.
 *
 * If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its response when it has completed the write operation starting
 * after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance of  32/fc and latest after 20 ms upon
 * detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedWriteSingleBlock(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the write operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint16, ANFCRL_VAR) wBlockNo,                                                      /**< [In] Block number to which the data should be written. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Information to be written to the specified block number. */
    VAR(uint8, ANFCRL_VAR) bDataLen                                                        /**< [In] Number of bytes to be written. */
);

/**
 * \brief Performs a Extended Lock block command. When receiving the Lock block command, the VICC shall lock permanently the requested
 * block. If a VICC supports Extended lock block command, it shall also support Lock block command for the first 256 blocks of memory.
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall wait for the reception of an EOF from the
 * VCD and upon such reception shall return its response. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return its
 * response when it has completed the lock operation starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc
 * (302 us) with a total tolerance of 32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedLockBlock (
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, The VICC shall return its response when it has completed the lock operation
		 *           starting after t1nom [4352/fc (320,9 us), see 9.1.1] + a multiple of 4096/fc (302 us) with a total tolerance
		 *           of  32/fc and latest after 20 ms upon detection of the rising edge of the EOF of the VCD request.
		 *      \arg If #PHAL_ICODE_OPTION_ON, The VICC shall wait for the reception of an EOF from the VCD and upon such reception
		 *           shall return its response.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint16, ANFCRL_VAR) wBlockNo                                                       /**< [In] Block number which should be locked. */
);

/**
 * \brief Performs a Extended Multiple block read command. When receiving the Read Multiple Block command, the VICC shall read the requested block(s)
 * and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple blocks
 * command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Data buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, Block Security Status information is not available. Only block data
		 *           is available. Format will be 4 byte data 1, 4 byte data 2,  4 byte data N
		 *      \arg If #PHAL_ICODE_OPTION_ON, both Block Security Status information and Block Data is available.
		 *           Format of the response will be Status 1, 4 byte data 1, Status 2, 4 byte data 2,  Status N,
		 *           4 byte data N
		 *           Where 1, 2  N is the block number.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint16, ANFCRL_VAR) wBlockNo,                                                      /**< [In] Block number from where the data to be read. */
    VAR(uint16, ANFCRL_VAR) wNumBlocks,                                                    /**< [In] Total number of block to read. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes.*/
);



/**
 * \brief Performs ExtendedGetSystemInformation command. This command allows for retrieving the system information value
 * from the VICC and shall be supported by the VICC if extended memory or security functionalities are supported by the VICC.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedGetSystemInformation(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bInfoParams,                                                    /**< [In] Extend Get System Information parameter request fields.
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_DEFAULT
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_DSFID
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_AFI
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_VICC_MEM_SIZE
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_IC_REFERENCE
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_MOI
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_COMMAND_LIST
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_CSI_INFORMATION
		 *        \arg #PHAL_ICODE_INFO_PARAMS_REQUEST_EXT_GET_SYS_INFO
		 */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo,                                                /**< [Out] The system information of the VICC. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen                                               /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs ExtendedGetMultipleBlockSecurityStatus. When receiving the Extended Get multiple block security status
 * command, the VICC shall send back the block security status. The blocks are numbered from 0000 to FFFF (0 - 65535).
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Status buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedGetMultipleBlockSecurityStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint16, ANFCRL_VAR) wBlockNo,                                                      /**< [In] Block number for which the status should be returned. */
    VAR(uint16, ANFCRL_VAR) wNoOfBlocks,                                                   /**< [In] Number of blocks to be used for returning the status. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pStatus,                                                      /**< [Out] The status of the block number mentioned in wBlockNo until wNumBlocks. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusLen                                                   /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a Extended Multiple block fast read command. When receiving the Read Multiple Block command, the VICC shall read the requested
 * block(s) and send back its value in the response. If a VICC supports Extended read multiple blocks command, it shall also support Read multiple
 * blocks command for the first 256 blocks of memory.
 *
 * If the Option_flag (bOption = PHAL_ICODE_OPTION_ON) is set in the request, the VICC shall return the block security status, followed by the block
 * value sequentially block by block. If it is not set (bOption = PHAL_ICODE_OPTION_OFF), the VICC shall return only the block value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the Data buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ExtendedFastReadMultipleBlocks(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *      \arg If #PHAL_ICODE_OPTION_OFF, Block Security Status information is not available. Only block data
		 *           is available. Format will be 4 byte data 1, 4 byte data 2,  4 byte data N
		 *      \arg If #PHAL_ICODE_OPTION_ON, both Block Security Status information and Block Data is available.
		 *           Format of the response will be Status 1, 4 byte data 1, Status 2, 4 byte data 2,  Status N,
		 *           4 byte data N
		 *           Where 1, 2  N is the block number.
		 *      \arg If #PHAL_ICODE_OPTION_DEFAULT, Same as #PHAL_ICODE_OPTION_OFF
		 */
    VAR(uint16, ANFCRL_VAR) wBlockNo,                                                      /**< [In] Block number from where the data to be read. */
    VAR(uint16, ANFCRL_VAR) wNumBlocks,                                                    /**< [In] Total number of block to read. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [Out] Information received from VICC in with respect to bOption parameter information. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out] Number of received data bytes.*/
);

/**
 * end of phalICode_Optional Commands_Optional
 * @}
 */

/** \defgroup phalICode_Custom Commands_Custom
 * \brief This component implements the custom commands of ICode products.
 * @{
 */

/**
 * \brief This command enables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_SetEAS(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                                         /**< [In] Option flag as per ISO15693; \arg #PHAL_ICODE_OPTION_OFF \arg #PHAL_ICODE_OPTION_ON. */
);

/**
 * \brief This command disables the EAS mode if the EAS mode is not locked. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ResetEAS(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                                         /**< [In] Option flag as per ISO15693; \arg #PHAL_ICODE_OPTION_OFF \arg #PHAL_ICODE_OPTION_ON. */
);

/**
 * \brief This command locks the current state of the EAS mode and the EAS ID. If the EAS mode is password protected
 * the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockEAS(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                                         /**< [In] Option flag as per ISO15693; \arg #PHAL_ICODE_OPTION_OFF \arg #PHAL_ICODE_OPTION_ON. */
);

/**
 * \brief This command returns the EAS sequence if the EAS mode is enabled.
 *
 * \li \c bOption disabled: \c bEasIdMaskLength and \c pEasIdValue are not transmitted, EAS Sequence is returned;
 * \li \c bOption enabled and \c bEasIdMaskLength = \c 0: EAS ID is returned;
 * \li \c bOption enabled and \c bEasIdMaskLength > \c 0: EAS Sequence is returned by ICs with matching \c pEasIdValue;
 *
 * If the EAS mode is disabled, the label remains silent.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_EASAlarm(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag;
		 *          \arg #PHAL_ICODE_OPTION_OFF \n
		 *                  \c EAS ID mask length and EAS ID value shall not be transmitted. \n
		 *                  \c If the EAS mode is enabled, the EAS response is returned from the ICODE IC.
		 *                     This configuration is compliant with the EAS command of the ICODE IC
		 *          \arg #PHAL_ICODE_OPTION_ON. \n
		 *                  \c Within the command the EAS ID mask length has to be transmitted to identify how
		 *                     many bits of the following EAS ID value are valid (multiple of 8-bits). Only those
		 *                     ICODE ICs will respond with the EAS sequence which have stored the corresponding
		 *                     data in the EAS ID configuration (selective EAS) and if the EAS Mode is set. \n
		 *                  \c If the EAS ID mask length is set to 0, the ICODE IC will answer with its EAS ID
		 */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue,                                                  /**< [In] EAS ID; 0, 8 or 16 bits; optional. */
    VAR(uint8, ANFCRL_VAR) bEasIdMaskLen,                                                  /**< [In] 8 bits; optional. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEas,                                                       /**< [Out] EAS ID (16 bits) or EAS Sequence (256 bits). */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEasLen                                                      /**< [Out] Length of bytes available in ppEas buffer. */
);

/**
 * \brief This command enables the password protection for EAS. The EAS password has to be transmitted before with
 * \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_PasswordProtectEAS(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief This command enables the password protection for AFI. The AFI password has to be transmitted before with
 * \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_PasswordProtectAFI(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief With this command, a new EAS identifier is stored in the corresponding configuration memory. If the EAS mode
 * is password protected the EAS password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WriteEASID(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEasIdValue                                                   /**< [In] EAS ID; 16 bits. */
);

/**
 * \brief Performs ReadEPC command. On this command, the label will respond with it's EPC data.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ReadEPC(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEpc,                                                       /**< [Out] EPC data; 96 bits. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pEpcLen                                                      /**< [Out] Length of bytes available in ppEpc buffer. */
);

/**
 * \brief Perform GetNXPSystemInformation command. This command allows for retrieving the NXP system information value from the VICC.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetNXPSystemInformation(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSystemInfo,                                                /**< [Out] The NXP system information of the VICC. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSystemInfoLen                                               /**< [Out] Number of received data bytes. */
);

/**
 * \brief Performs a GetRandomNumber command. On this command, the label will respond with a random number.
 * The received random number shall be used to diversify the password for the \ref phalICode_SetPassword command.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetRandomNumber(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRnd,                                                       /**< [Out] Random number; 16 bits. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRndLen                                                      /**< [Out] Number of bytes in ppRnd buffer. */
);


/**
 * \brief Performs SetPassword command. With this command the different passwords can be transmitted to the label.
 *
 * This command has to be executed just once for the related passwords if the label is powered.
 *
 * \verbatim
 * [XOR password calculation example]
 * pXorPwd[0] = pPassword[0] ^ pRnd[0];
 * pXorPwd[1] = pPassword[1] ^ pRnd[1];
 * pXorPwd[2] = pPassword[2] ^ pRnd[0];
 * pXorPwd[3] = pPassword[3] ^ pRnd[1];
 * \endverbatim
 *
 * \b Remark: This command can only be executed in addressed or selected mode except of Privacy Password.
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_SetPassword(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier,                                                 /**< [In] Password Identifier;
		 *          \arg #PHAL_ICODE_SET_PASSWORD_READ
		 *          \arg #PHAL_ICODE_SET_PASSWORD_WRITE
		 *          \arg #PHAL_ICODE_SET_PASSWORD_PRIVACY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_DESTROY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_EAS
		 */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd                                                       /**< [In] XOR Password; 32 bits. */
);

/**
 * \brief Performs WritePassword command. With this command, a new password is written into the related memory. Note that the
 * old password has to be transmitted before with \ref phalICode_SetPassword. The new password takes effect immediately which
 * means that the new password has to be transmitted with \ref phalICode_SetPassword to get access to protected blocks/pages.
 * \b Remark: This command can only be executed in addressed or selected mode.
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WritePassword(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier,                                                 /**< [In] Password Identifier;
		 *          \arg #PHAL_ICODE_SET_PASSWORD_READ
		 *          \arg #PHAL_ICODE_SET_PASSWORD_WRITE
		 *          \arg #PHAL_ICODE_SET_PASSWORD_PRIVACY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_DESTROY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_EAS
		 */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPwd                                                          /**< [In] Plain Password; 32 bits. */
);

/**
 * \brief Performs LockPassword command. This command locks the addressed password. Note that the addressed password
 * has to be transmitted before with \ref phalICode_SetPassword. A locked password can not be changed any longer.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockPassword(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bPwdIdentifier                                                  /**< [In] Password Identifier;
		 *          \arg #PHAL_ICODE_SET_PASSWORD_READ
		 *          \arg #PHAL_ICODE_SET_PASSWORD_WRITE
		 *          \arg #PHAL_ICODE_SET_PASSWORD_PRIVACY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_DESTROY
		 *          \arg #PHAL_ICODE_SET_PASSWORD_EAS
		 */
);


/**
 * \brief Performs Page protection command. This command changes the protection status of a page. Note that the related
 * passwords have to be transmitted before with \ref phalICode_SetPassword if the page is not public.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ProtectPage(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bPPAdd_PageNo,                                                  /**< [In] Page number to be protected in case of products that do not have pages
																				 *        characterized as high and Low. \n
																				 *        Block number to be protected in case of products that have pages
																				 *        characterized as high and Low.
																				 */
    VAR(uint8, ANFCRL_VAR) bProtectionStatus                                               /**< [In] Protection status options for the products that do not have pages
																				 *        characterized as high and Low.
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_PUBLIC
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_READ_WRITE_READ_PASSWORD
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_WRITE_PASSWORD
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_READ_WRITE_PASSWORD_SEPERATE
																				 *
																				 *        Extended Protection status options for the products that have pages
																				 *        characterized as high and Low.
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_READ_LOW
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_WRITE_LOW
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_READ_HIGH
																				 *          \arg #PHAL_ICODE_PROTECT_PAGE_WRITE_HIGH
																				 */
	);

/**
 * \brief Perform LockPageProtectionCondition command. This command permanently locks the protection status of a page.
 * Note that the related passwords have to be transmitted before with \ref phalICode_SetPassword if the page is not public.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_LockPageProtectionCondition(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bPageNo                                                         /**< [In] Page number to be protected. */
);

/**
 * \brief Perform GetMultipleBlockProtectionStatus command. This instructs the label to return the block protection
 * status of the requested blocks.
 *
 * \b Remark: If \c bBlockNo + \c bNoOfBlocks exceeds the total available number of user blocks, the number of received
 * status bytes is less than the requested number. This means that the last returned status byte corresponds to the
 * highest available user block.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 * Note: The memory should be created and sent to the ProtectionStates buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetMultipleBlockProtectionStatus(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                                       /**< [In] First Block number. */
    VAR(uint8, ANFCRL_VAR) bNoOfBlocks,                                                    /**< [In] First Block number. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProtectionStates,                                            /**< [Out] Protection states of requested blocks. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumReceivedStates                                           /**< [Out] Number of received block protection states. */
);

/**
 * \brief Performs Destroy command. This command permanently destroys the label.
 *
 * The Destroy password has to be transmitted before with \ref phalICode_SetPassword.
 * \b Remark: This command is irreversible and the label will never respond to any command again.
 * \b Remark: This command can only be executed in addressed or selected mode.
 *
 * Note: This command is not valid for ICode DNA product as the Destroy feature is part of Mutual
 * Authentication command.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_Destroy(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd                                                       /**< [In] XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
																				 *        for the products that do not support.
																				 */
	);

/**
 * \brief Performs EnablePrivacy command. This command instructs the label to enter privacy mode.
 *
 * In privacy mode, the label will only respond to \ref phalICode_GetRandomNumber and \ref phalICode_SetPassword commands.
 * To get out of the privacy mode, the Privacy password has to be transmitted before with \ref phalICode_SetPassword.
 *
 * Note: This command is not valid for ICode DNA product as the privacy enabling disabling feature is part of Mutual
 * Authentication command.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_EnablePrivacy(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pXorPwd                                                       /**< [In] XOR Password; 32 bits. Pass the password for the ICODE products that supports and NULL
																				 *        for the products that do not support.
																				 */
	);

/**
 * \brief Perform 64-BitPasswordProtection command. This instructs the label that both of the Read and Write passwords
 * are required for protected access.
 *
 * Note that both the Read and Write passwords have to be transmitted before with \ref phalICode_SetPassword.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_64BitPasswordProtection(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layers parameter structure. */
);


/**
 * \brief Performs ReadSignature command. On this command, the label will respond with the signature value.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ReadSignature(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppSign,                                                      /**< [Out] The originality signature returned by the VICC. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pSignLen                                                     /**< [Out] Length of originality signature buffer. */
);

/**
 * \brief Reads a multiple 4 byte(s) data from the mentioned configuration block address. Here the starting address of the
 * configuration block should be given in the parameter wBlockAddr and the number of blocks to read from the starting
 * block should be given in the parameter bNoOfBlocks.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_ReadConfig(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockAddr,                                                     /**< [In] Configuration block address. */
    VAR(uint8, ANFCRL_VAR) bNoOfBlocks,                                                    /**< [In] The n block(s) to read the configuration data. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppData,                                                      /**< [Out] Multiple of 4 (4u * No Of Blocks) byte(s) of data read from the mentioned
		 *         configuration block address.
		 */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                     /**< [Out]  Number of received configuration data bytes. */
);

/**
 * \brief Writes a 4 byte data to the mentioned configuration block address.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_WriteConfig(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option flag as per ISO15693; \arg #PHAL_ICODE_OPTION_OFF \arg #PHAL_ICODE_OPTION_ON. */
    VAR(uint8, ANFCRL_VAR) bBlockAddr,                                                     /**< [In] Configuration block address. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData                                                         /**< [In] A 4 byte data to be written to the mentioned configuration block address. */
);

/**
 * \brief Enables the random ID generation in the tag. This interfaces is used to instruct the tag to generate
 * a random number in privacy mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Flag can be set by using \ref phalICode_SetConfig command
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_PickRandomID(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                              /**< [In] Pointer to this layer's parameter structure. */
);


/**
 * end of group phalICode_Custom Commands_Custom
 * @}
 */

/** \defgroup phalICode_Utils Utilities
 * \brief This component implements the special commands of ease of use. These commands are actually not of
 * ISO15693 or any of the ICode product families. these are generic commands as part of reader library.
 * @{
 */


/**
 * \brief Get the configuration settings.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetConfig(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig,                                                       /**< [In] Configuration to read.
		 *          \arg #PHAL_ICODE_CONFIG_FLAGS
		 *          \arg #PHAL_ICODE_CONFIG_ADD_INFO
		 *          \arg #PHAL_ICODE_CONFIG_TIMEOUT_US
		 *          \arg #PHAL_ICODE_CONFIG_TIMEOUT_MS
		 *          \arg #PHAL_ICODE_CONFIG_ENABLE_BUFFERING
		 */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                       /**< [In] The value for the mentioned configuration information in wConfig parameter.
		 *          \arg #PHAL_ICODE_CONFIG_FLAGS \n
		 *              \c #PHAL_ICODE_FLAG_TWO_SUB_CARRIERS \n
		 *              \c #PHAL_ICODE_FLAG_DATA_RATE \n
		 *              \c #PHAL_ICODE_FLAG_INVENTORY \n
		 *              \c #PHAL_ICODE_FLAG_PROTOCOL_EXTENSION \n
		 *              \c #PHAL_ICODE_FLAG_SELECTED \n
		 *              \c #PHAL_ICODE_FLAG_AFI \n
		 *              \c #PHAL_ICODE_FLAG_ADDRESSED \n
		 *              \c #PHAL_ICODE_FLAG_NBSLOTS \n
		 *              \c #PHAL_ICODE_FLAG_OPTION \n
		 *          \n
		 *          \arg #PHAL_ICODE_CONFIG_ADD_INFO, any additional information like error code will be available.
		 *          \n
		 *          \arg #PHAL_ICODE_CONFIG_ENABLE_BUFFERING \n
		 *              \c #PHAL_ICODE_DISABLE \n
		 *              \c #PHAL_ICODE_ENABLE \n
		 */
);

/**
 * \brief Set the configuration settings.
 *
 * \b NOTE: Both the flags #PHAL_ICODE_FLAG_DATA_RATE and #PHAL_ICODE_FLAG_FAST_DATA_RATE should not be combined,
 *          it should be passed separately along with other flag.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_SetConfig(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig,                                                       /**< [In] Configuration to update.
		 *          \arg #PHAL_ICODE_CONFIG_FLAGS
		 *          \arg #PHAL_ICODE_CONFIG_ENABLE_BUFFERING
		 */
    VAR(uint16, ANFCRL_VAR) wValue                                                         /**< [In] The value for the mentioned configuration information in wConfig parameter.
		 *          \arg #PHAL_ICODE_CONFIG_FLAGS \n
		 *              \c #PHAL_ICODE_FLAG_TWO_SUB_CARRIERS \n
		 *              \c #PHAL_ICODE_FLAG_DATA_RATE \n
		 *              \c #PHAL_ICODE_FLAG_INVENTORY \n
		 *              \c #PHAL_ICODE_FLAG_PROTOCOL_EXTENSION \n
		 *              \c #PHAL_ICODE_FLAG_SELECTED \n
		 *              \c #PHAL_ICODE_FLAG_AFI \n
		 *              \c #PHAL_ICODE_FLAG_ADDRESSED \n
		 *              \c #PHAL_ICODE_FLAG_NBSLOTS \n
		 *              \c #PHAL_ICODE_FLAG_OPTION \n
		 *              \c #PHAL_ICODE_FLAG_FAST_DATA_RATE \n
		 *          \n
		 *          \arg #PHAL_ICODE_CONFIG_ENABLE_BUFFERING \n
		 *              \c #PHAL_ICODE_DISABLE \n
		 *              \c #PHAL_ICODE_ENABLE \n
		 */
);


/**
 * \brief Get the type of Tag
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalICode_GetTagType(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTagType                                                     /**< [In] The type of ICode tag.
		 *          \arg #PHAL_ICODE_TAG_TYPE_UNKNOWN
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLI
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLI_S
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLI_L
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLIX
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLIX_S
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLIX_L
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_SLI_X2
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_DNA
		 *          \arg #PHAL_ICODE_TAG_TYPE_ICODE_NTAG5_I2C
		 */
);

/**
 * end of group phalICode_Utils Utilities
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALICODE_AR_RELEASE_MAJOR_VERSION == 4) && (PHALICODE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phalICode_Generic Generic
 * @}
 */

/**
 * end of group phalICode ICode
 * @}
 */
 

#endif /* NXPBUILD__PHAL_ICODE */



#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHALICODE_H */
