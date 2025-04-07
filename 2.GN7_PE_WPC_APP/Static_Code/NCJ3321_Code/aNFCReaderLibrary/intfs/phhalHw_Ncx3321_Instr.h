/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020
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
*   @file    phhalHw_Ncx3321_Instr.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Instr - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#ifndef PHHALHW_NCX3321_INSTR_H
#define PHHALHW_NCX3321_INSTR_H

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
#include "phhalHw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Instr.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTR_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTR_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTR_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321_Instr.h and CDD_AnfcRL_cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INSTR_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Instr.h and CDD_AnfcRL_cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_INSTR_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INSTR_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INSTR_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Instr.h and CDD_AnfcRL_cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
/** \defgroup phhalHw_NCX3321_Instr Instruction
* \ingroup phhalHw_Ncx3321
* \brief Ncx3321 Instruction functions
* @{
*/

/**
* \name NCX3321 Instruction Codes.
*
*/
/*@{*/
#define PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER                                0x00U  /**< Write 32 bit value to a register. */
#define PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_OR_MASK                        0x01U  /**< Perform a logical OR operation on a register using provided mask. */
#define PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_AND_MASK                       0x02U  /**< Perform a logical AND operation on a register using provided mask. */
#define PHHAL_HW_NCX3321_INSTR_WRITE_REGISTER_MULTIPLE                       0x03U  /**< Perform a write register operation using a set of Register-Value pairs. */
#define PHHAL_HW_NCX3321_INSTR_READ_REGISTER                                 0x04U  /**< Read back content of a register. */
#define PHHAL_HW_NCX3321_INSTR_READ_REGISTER_MULTIPLE                        0x05U  /**< Perform a read register operation on a set of registers. */
#define PHHAL_HW_NCX3321_INSTR_WRITE_E2PROM                                  0x06U  /**< Write given values sequentially to E2PROM. */
#define PHHAL_HW_NCX3321_INSTR_READ_E2PROM                                   0x07U  /**< Read out values from E2PROM sequentially. */
#define PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA                              0x08U  /**< Write TX data to internal CLIF transmission buffer. */
#define PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA                              0x09U  /**< Read RX data from internal RF reception buffer. */
#define PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA                              0x0AU  /**< Read RX data from internal RF reception buffer. */
#define PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE                              0x0BU  /**< Perform authentication on an activated Mifare Classic card. */
#define PHHAL_HW_NCX3321_INSTR_LOAD_RF_CONFIGURATION                         0x0DU  /**< Load RF Tx and Rx settings from E2PROM. */
#define PHHAL_HW_NCX3321_INSTR_UPDATE_RF_CONFIGURATION                       0x0EU  /**< Update the RF configuration. */
#define PHHAL_HW_NCX3321_INSTR_GET_RF_CONFIGURATION                          0x0FU  /**< Retrieve the RF configuration. */
#define PHHAL_HW_NCX3321_INSTR_FIELD_ON                                      0x10U  /**< RF Field ON. */
#define PHHAL_HW_NCX3321_INSTR_FIELD_OFF                                     0x11U  /**< RF field OFF.*/
#define PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_DIGITAL                     0x12U  /**< Configure digital test bus. */
#define PHHAL_HW_NCX3321_INSTR_CONFIGURE_TESTBUS_ANALOG                      0x13U  /**< Configure Analog test bus. */
#define PHHAL_HW_NCX3321_INSTR_CTS_ENABLE                                    0x14U  /**< Enable/disable the CTS logging feature. */
#define PHHAL_HW_NCX3321_INSTR_CTS_CONFIGURE                                 0x15U  /**< Configure the all the required CTS registers. */
#define PHHAL_HW_NCX3321_INSTR_CTS_RETRIEVE_LOG                              0x16U  /**< Retrieves the log of the captured data samples stored in the memory buffer. */

#define PHHAL_HW_NCX3321_INSTR_RECEIVE_RF_DATA                               0x1AU  /**< Perform RF RX operation. */

#define PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_NORMAL                            0x20U  /**< Switch operation mode. Possible modes are: Normal */
#define PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_AUTOCOLL                          0x21U  /**< Switch operation mode. - Autocoll. */
#define PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_STANDBY                           0x22U  /**< Switch operation mode. - Standby. */
#define PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_LPCD                              0x23U  /**< Switch operation mode. - LPCD. */
#define PHHAL_HW_NCX3321_INSTR_SWITCH_MODE_DOWNLOAD                          0x25U  /**< Switch operation mode. - DOWNLOAD. */
#define PHHAL_HW_NCX3321_INSTR_GET_DIE_ID                                    0x26U  /**< Read DIE-ID of Front End. */
#define PHHAL_HW_NCX3321_INSTR_GET_VERSION                                   0x27U  /**< Read Version of Front End. */

#define PHHAL_HW_NCX3321_INSTR_PRBS_TEST                                     0x41U  /**< Command to generate Pseudo-random Binary Sequence. */
/*@}*/

/**
* \name NCX3321 Register and EEPROM Variable Addresses.
*
*/
/*@{*/
#define PHHAL_HW_NCX3321_REG_START_ADDRESS           0U
#define PHHAL_HW_NCX3321_REG_END_ADDRESS             0x63

#define PHHAL_HW_NCX3321_EEPROM_START_ADDRS          0U         /** First writable address in EEPROM */
#define PHHAL_HW_NCX3321_EEPROM_END_ADDRS            5120U      /** Last user writable address in EEPROM */

#define PHHAL_HW_NCX3321_SET_LISTEN_EEPROM_ADDR      0x2B3U
#define PHHAL_HW_NCX3321_DYNAMIC_UID_CONFG_ADDR      0x2CBU

#define PHHAL_HW_NCX3321_REG_START_ADDRESS_EXPERT    0x80U
#define PHHAL_HW_NCX3321_REG_END_ADDRESS_EXPERT      0x8FU

/*@}*/

/**
* \name NCX3321 LPCD configuration.
*
*/
/*@{*/
#define PHHAL_HW_NCX3321_LPCD_CONFIG_MASK     0x80U

/*@}*/

/**
* \name NCX3321 EPC GEN2 custom definitions.
*/
/*@{*/
#define PHHAL_HW_NCX3321_MIN_SELECT_COMMAND_LENGTH                           1U    /**< Minimum length of Select command. */
#define PHHAL_HW_NCX3321_MAX_SELECT_COMMAND_LENGTH                          39U   /**< Maximum length of Select command. */
#define PHHAL_HW_NCX3321_BEGIN_COMMAND_LENGTH                                3U   /**< length of Begin command. */

#define PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE                       7U    /**< Maximum number of bits to be transmitted in the last byte of \p pSelectCommand. 0 in case all bits shall be transmitted, otherwise 1-7. */
#define PHHAL_HW_NCX3321_MAX_EPC_GEN2_TIMESLOT                              (PHHAL_HW_NCX3321_EPC_GEN2_TIMESLOT_SINGLE_SELECT_TAG) /**< Maximum EPC GEN2 TIMESLOT parameter. */
/*@}*/


/**
* \name NCX3321 RF configuration custom definitions.
* To be used with
* #phhalHw_Ncx3321_Instr_LoadRfConfiguration,
* #phhalHw_Ncx3321_Instr_UpdateRfConfiguration,
* #phhalHw_Ncx3321_Instr_RetrieveRfConfiguration.
*/
/*@{*/
#define PHHAL_HW_NCX3321_MIN_RF_TX_CONFIGURATION_INDEX                      0x00U  /**< Minimum RF configuration index for TX. */
#define PHHAL_HW_NCX3321_MAX_RF_TX_CONFIGURATION_INDEX                      PHHAL_HW_NCX3321_RF_TX_NFC_AI_424_424  /**< Maximum RF configuration index for TX. */
#define PHHAL_HW_NCX3321_MIN_RF_RX_CONFIGURATION_INDEX                      0x80U  /**< Minimum RF configuration index for RX. */
#define PHHAL_HW_NCX3321_MAX_RF_RX_CONFIGURATION_INDEX                      0x9DU  /**< Maximum RF configuration index for RX. */
#define PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_INDEX                         PHHAL_HW_NCX3321_MAX_RF_RX_CONFIGURATION_INDEX   /**< Maximum RF configuration index. */
#define PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX                     0xFFU  /**< Current RF configuration index for TX/RX. */
#define PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE                              6U    /**< Size of a single RF configuration
                                                                                  1 Byte Rx or Tx configuration index
                                                                                  1 Byte Register address within the RF configuration
                                                                                  4 Bytes value to be written into the register. */
#define PHHAL_HW_NCX3321_RETRIEVE_RF_EACH_CONFIGURATION                     5U    /**< Size of a single RF configuration
                                                                                  1 Byte Register address within the RF configuration
                                                                                  4 Bytes value of the register. */

#define PHHAL_HW_NCX3321_RETRIEVE_RF_CONFIGURATION_SIZE_RESPONSE             1U
#define PHHAL_HW_NCX3321_MAX_RF_CONFIGURATION_SIZE                          222U  /**< Maximum size of the RF configurations. It must be a multiple of #PHHAL_HW_NCX3321_RF_CONFIGURATION_SIZE. */
#define PHHAL_HW_NCX3321_MIN_RF_CONFIGURATION_BUFFER_SIZE                   185U /**< Minimum buffer size that needs to be passed to get RF register configuration. */
/*@}*/

/**
 * \name NCX3321 Write multiple register operation type.
 * To be used with #phhalHw_Ncx3321_Instr_WriteRegisterMultiple.
 */
 /*@{*/
#define PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE                             0x01U  /**< Write register operation requested. */
#define PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK                     0x02U  /**< Write register OR mask operation requested. */
#define PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK                    0x03U  /**< Write register AND mask operation requested. */
 /*@}*/

/**
   * \name NCX3321 Switch Mode Type type.
   */
   /*@{*/
#define PHHAL_HW_NCX3321_SWITCH_MODE_STANDBY                               0x00U  /**< NCX3321 is in standby/sleep state to save power. */
#define PHHAL_HW_NCX3321_SWITCH_MODE_LPCD                                  0x01U  /**< NCX3321 is in low power card detection mode. */
#define PHHAL_HW_NCX3321_SWITCH_MODE_AUTOCOLL                              0x02U  /**< NCX3321 is acting as RF listener, performing target mode activation autonomously. */
#define PHHAL_HW_NCX3321_SWITCH_MODE_NORMAL                                0x03U  /**< NCX3321 is in Normal modes. */

   /*@}*/

/**
* \name NCX3321 register, EEPROM & TX/RX buffer custom definitions.
* To be used with
* #phhalHw_Ncx3321_Instr_WriteRegister,
* #phhalHw_Ncx3321_Instr_WriteRegisterOrMask,
* #phhalHw_Ncx3321_Instr_WriteRegisterAndMask,
* #phhalHw_Ncx3321_Instr_WriteRegisterMultiple,
* #phhalHw_Ncx3321_Instr_ReadRegister,
* #phhalHw_Ncx3321_Instr_ReadRegisterMultiple,
* #phhalHw_Ncx3321_Instr_WriteE2Prom,
* #phhalHw_Ncx3321_Instr_ReadE2Prom,
* #phhalHw_Ncx3321_Instr_RetrieveRFData.
 */
 /*@{*/
#define PHHAL_HW_NCX3321_MAX_REGISTER_TYPE_VALUE_SET                        (43U * 0x06U) /**< Size of the buffer holding the register-type-value sets. */
#define PHHAL_HW_NCX3321_MIN_REGISTER_TYPE_VALUE_SET                        0x06U /**< Size of the buffer holding the register-type-value sets. Minimum size for one Register operation. */


#define PHHAL_HW_NCX3321_TX_DATA_MAX_LENGTH                                 1024U/**< The Transmission maximum payload length is 1024 byte. */
#define PHHAL_HW_NCX3321_TX_DATA_MIN_LENGTH                                 1U   /**< The Transmission minimum payload length is 1 byte. */

#define PHHAL_HW_NCX3321_RX_DATA_MAX_LENGTH                                 0x200U/**< The Retrieved Maximum data length is 512 byte. */
#define PHHAL_HW_NCX3321_RX_DATA_MIN_LENGTH                                 0x01U /**< The Retrieved Minimum data length is 1 byte. */

#define PHHAL_HW_NCX3321_MAX_NUM_OF_BITS_FOR_LAST_BYTE                      7U    /**< Maximum number of bits to be transmitted in the last byte of \p pSelectCommand. 0 in case all bits shall be transmitted, otherwise 1-7. */

#define PHHAL_HW_NCX3321_MAX_REGISTERS_READ_MULTIPLE                        18U /**< TODO : May need to be removed. */
#define PHHAL_HW_NCX3321_BYTES_PER_REGISTER                                 4U
/*@}*/

/** \name Status codes returned by NCX3321
*/
/*@{*/
#define PH_ERR_NCX3321_SUCCESS                                              PH_ERR_SUCCESS           /**< Returned in case of no error. */
#define PH_ERR_NCX3321_TIMEOUT                                              PH_ERR_IO_TIMEOUT        /**< No reply received, e.g. PICC removal. */
#define PH_ERR_NCX3321_INTEGRITY_ERROR                                      PH_ERR_INTEGRITY_ERROR   /**< Wrong CRC or parity detected. */
#define PH_ERR_NCX3321_COLLISION_ERROR                                      PH_ERR_COLLISION_ERROR   /**< A collision occurred. */
#define PH_ERR_NCX3321_INVALID_CMD                                          ((phStatus_t)0x05U)     /**< NCX3321 received invalid TLV Command. */
#define PH_ERR_NCX3321_AUTH_ERROR                                           PH_ERR_AUTH_ERROR        /**< Authentication error. */
#define PH_ERR_NCX3321_MEMORY_ERROR                                         PH_ERR_READ_WRITE_ERROR  /**< A Read or Write error occurred. */
#define PH_ERR_NCX3321_NO_RF_FIELD                                          PH_ERR_RF_ERROR          /**< Error due to RF. */
#define PH_ERR_NCX3321_SYNTAX_ERROR                                         PH_ERR_LENGTH_ERROR      /**< A length error occurred. */
#define PH_ERR_NCX3321_RESOURCE_ERROR                                       PH_ERR_RESOURCE_ERROR    /**< An resource error. */
#define PH_ERR_NCX3321_EXTERNAL_FIELD_ERROR                                 PH_ERR_EXT_RF_ERROR      /**< Error due to External RF. */
#define PH_ERR_NCX3321_RX_TIMEOUT_ERROR                                     ((phStatus_t)0x11U)     /**< NCX3321 detected/received SC or SOF but RX was not complete after exchange initiated and FDT timer stopped. */
#define PH_ERR_NCX3321_USER_CALNCELLED                                      PH_ERR_ABORTED			/**< Used when HAL Abort is called. */
#define PH_ERR_NCX3321_PREVENT_STANDBY                                      ((phStatus_t)0x13U)     /**< NCX3321 Standby was prevented. */
#define PH_ERR_NCX3321_PARAMETER_ERROR                                      ((phStatus_t)0x14U)     /**< NCX3321 detected a Parameter error. */
#define PH_ERR_NCX3321_PLL_ERROR                                            ((phStatus_t)0x15U)     /**< NCX3321 PLL did not start. */
#define PH_ERR_NCX3321_SEMANTIC_ERROR                                       ((phStatus_t)0x16U)     /**< NCX3321 returns in case of unexpected instructions is been received. */
#define PH_ERR_NCX3321_INSTR_ERROR                                          ((phStatus_t)0x18U)     /**< General error indicating requested operation/command failed. */
#define PH_ERR_NCX3321_ACCESS_DENIED                                        ((phStatus_t)0x19U)
#define PH_ERR_NCX3321_TX_FAILURE                                           ((phStatus_t)0x1AU)     /**< Error that indicates that TX IRQ did not Trigger after Exchange was called. */
#define PH_ERR_NCX3321_TXLDO_ERROR                                          ((phStatus_t)0x1CU)      /**< Error indicating that TX LDO didn't start in case of RF ON. */
#define PH_ERR_NCX3321_NO_LOAD_RF_CFGS                                      ((phStatus_t)0x1DU)      /**< Error in case RF ON is triggered w/o applying proper Load Rf configurations */
#define PH_ERR_NCX3321_INTERNAL_ERROR                                       PH_ERR_INTERNAL_ERROR    /**< An internal error occurred. */
#define PH_ERR_NCX3321_UNEXPECTED_EVT                                       ((phStatus_t)0xAEU)     /**< Error indicated that in current context, unexpected event received from front End. */
#define PH_ERR_NCX3321_SUCCESS_CHAINING                                     ((phStatus_t)0xAFU)
#define PH_ERR_NCX3321_INVALID_DATA_PARAMS                                  PH_ERR_INVALID_DATA_PARAMS		/**< Invalid data parameters supplied (layer id check failed). */
#define PH_ERR_NCX3321_INVALID_PARAMETER                                    PH_ERR_INVALID_PARAMETER		/**< Invalid parameter supplied. */
#define PH_ERR_NCX3321_UNSUPPORTED_PARAMETER                                PH_ERR_UNSUPPORTED_PARAMETER	/**< Parameter not supported. */
/*@}*/


/**
 * \name NCX3321 MIFARE Classic authentication key type definition, length and status defines
 */
 /*@{*/

#define PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_A                   0x60U  /**< MIFARE Classic Key Type A. */
#define PHHAL_HW_NCX3321_INSTR_MFC_AUTHENTICATE_KEY_TYPE_B                   0x61U  /**< MIFARE Classic Key Type B. */
#define PHHAL_HW_NCX3321_MFC_UID_LEN                                         0x04U  /**< MIFARE Classic Key Key Len. */

 /*@}*/

/**
* \name NCX3321 Timeslot processing behavior.
*/
/*@{*/
#define PHHAL_HW_NCX3321_EPC_GEN2_TIMESLOT_FILL_BUFFER                     0x00U  /**< EPC GEN2 inventory processes timeslots until buffer is full. */
#define PHHAL_HW_NCX3321_EPC_GEN2_TIMESLOT_SINGLE                          0x01U  /**< EPC GEN2 inventory processes one timeslot only. */
#define PHHAL_HW_NCX3321_EPC_GEN2_TIMESLOT_SINGLE_SELECT_TAG               0x02U  /**< EPC GEN2 inventory processes one timeslot only. If timeslot contains a valid tag response, the tag is also selected. */


/*@}*/

/**
 * \name NCX3321 autocoll RF technology bitmask definition
 */
 /*@{*/
#define PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A                    0x01U  /**< Autocoll for NFC-A (ISO14443 mode A) enabled. */
#define PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F                    0x02U  /**< Autocoll for NFC-F (FeliCa) enabled. */
#define PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A_ACTIVE             0x04U  /**< Autocoll for NFC_A target mode active enabled. */
#define PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F_ACTIVE             0x08U  /**< Autocoll for NFC_F target mode active enabled. */
/*@}*/

/**
 * \name NCX3321 autocoll operation mode
 */
 /*@{*/
#define PHHAL_HW_NCX3321_AUTOCOLL_MODE_TERMINATE_ON_RF_OFF                 0x00U  /**< Autocoll terminates when external field vanishes.  */
#define PHHAL_HW_NCX3321_AUTOCOLL_MODE_AUTONOMOUS_WITH_STANDBY             0x01U  /**< Autocoll terminates only upon successful activation. When external field vanishes, PN5180 enters standby. PN5180 wakes up again once external field is detected again. */
#define PHHAL_HW_NCX3321_AUTOCOLL_MODE_AUTONOMOUS_WITHOUT_STANDBY          0x02U  /**< Autocoll terminates only upon successful activation. PN5180 does use standby mode. */
 /*@}*/

/**
 * \name NCX3321 autocoll Event Response
 */
 /*@{*/
#define PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATED                                0x00U  /* NCX3321 has been activated as a card  */
#define PHHAL_HW_NCX3321_AUTOCOLL_EXTRF_OFF                                0x10U  /* No Ext RF field or Ext RF field has vanished */
/*@}*/

/**
 * \name NCX3321 autocoll Event Payload defines
 */
 /*@{*/
#define PHHAL_HW_NCX3321_AUTOCOLL_STATUS_INDEX                             0x00U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACT_INDEX                           0x01U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_STATUS_INDEX                        0x02U

#define PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_MODE_MASK                     0xF0U
#define PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_SPEED_MASK                    0x0FU

#define PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_PASSIVE_MODE                  0x10U
#define PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_ACTIVE_MODE                   0x20U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_A_106                       0x10U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_212                       0x11U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_424                       0x12U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_106                          0x20U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_212                          0x21U
#define PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_424                          0x22U
/*@}*/

/**
* \name LPCD Control options
*/
/*@{*/
#define PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB        0x00U  /**< ULPCD calibration (HW based LPCD) configuration, Ncx3321 after
                                                                 calibration will come of of ULPCD and return Calibration reference value in Event.*/
#define PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD              0x01U  /**< Enter ULPCD (HW based LPCD)  */
#define PHHAL_HW_NCX3321_LPCD_CTRL_LPCD_CALIB         0x02U  /**< SW LPCD calibration configuration, NCX3321 after calibration
                                                                 comes out of SW LPCD and return RSSI value in EVENT*/
#define PHHAL_HW_NCX3321_LPCD_CTRL_LPCD               0x03U  /**< LPCD using SW configuration. */
#define PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_LPCD	  0x04U  /**< Single mode LPCD in SW configuration shall perform Calibration and Detection cycle together in
                                                                 Standby Mode. This mode shall be only used with "PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN" mode. */
#define PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_CALIB    0x0CU  /**< Single mode LPCD SW calibration configuration shall perform Calibration cycle in Standby Mode.
                                                                 This mode shall be only used with "PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT" mode. */
/*@}*/

/**
* \name LPCD modes
*/
/*@{*/
#define PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT            0x00U  /**< Default mode. Used to retrieve and configure the LPCD Calibration values and check if LPCD is already successful or not. */
#define PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN          0x01U  /**< Powers down the IC for a certain amount of time and performs LPC after wakeup.
                                                                 If no card is found the IC is powered down again and the procedure is restarted.
                                                                 If a card is found the function returns and the IC remains powered up. */
/*@}*/

/**
* \name ULPCD WakeUp  configuration
*/
/*@{*/
#define PHHAL_HW_NCX3321_ULPCD_EXT_RF_WAKEUP_MASK     0x01U   /**< ENABLE HW LPCD (ULPCD) to exit due to external mask*/
/*@}*/


/**
* \name LPCD configuration
*/
/*@{*/
/**
* @brief   Value used for Wake-up counter in msecs
*          i.e. after this amount of time IC will wakes up
*          from standby during LPCD or ULPC.
*/
#define PH_NFCRDLIB_LPCD_WAKEUP_PW_DOWN              50U

/**
* @brief   Value used for Wake-up counter in msecs
*          i.e. after this amount of time IC will wakes up
*          from standby during calibration.
*/
#define PH_NFCRDLIB_LPCD_WAKEUP_CALIB                100U

/**
* @brief   Value used to enable/disable the feature,
*          Wake-up from LPCD mode on external RF field
*/
#define PH_NFCRDLIB_LPCD_EXT_RF_WAKEUP               0x01U
/**< Value used for Wakeup counter in msecs i.e. after this amount of time IC will wakes up from standby during LPCD or ULPCD. */
#define PHHAL_HW_CONFIG_SET_LPCD_WAKEUPTIME_MS       0x0070U
/**< Used to set options  PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT or PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN */
#define PHHAL_HW_CONFIG_LPCD_MODE                    0x0071U
/**< Used to set options  PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB, PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD, PHHAL_HW_NCX3321_LPCD_CTRL_LPCD_CALIB or PHHAL_HW_NCX3321_LPCD_CTRL_LPCD */
#define PHHAL_HW_CONFIG_LPCD_CONFIG                  0x0072U
/**< Used to configure the Wakeup source for LPCD */
#define PHHAL_HW_CONFIG_LPCD_WAKEUP_CTRL             0x0073U
/**< Used to configure the Reference value either obtained during Calibration phase or a known value for LPCD or ULPCD phase */
#define PHHAL_HW_CONFIG_LPCD_REF_VAL                 0x0074U
/**< Used to retrieve the LPCD Event Status after an LPCD or ULPCD phase */
#define PHHAL_HW_CONFIG_LPCD_RETRIEVE_EVENT_STATUS   0x0075U
/**< Used to configure the HFATT Values for ULPCD Calibration and Detection phase */
#define PHHAL_HW_CONFIG_LPCD_HFATT_VAL               0x0076U
/*@}*/

/**
* \name LPCD Event Status Bits
*/
/*@{*/
#define PHHAL_HW_LPCD_EVT_STATUS_CARD_DETECTED           0x0000001U
#define PHHAL_HW_LPCD_EVT_STATUS_GPIO3_ABORT             0x0000002U
#define PHHAL_HW_LPCD_EVT_STATUS_EXTERNALRF_FIELD        0x0000004U
#define PHHAL_HW_LPCD_EVT_STATUS_VDDPA_LDO_OVERCURRENT   0x0000008U
#define PHHAL_HW_LPCD_EVT_STATUS_XTAL_TIMEOUT            0x0000010U
#define PHHAL_HW_LPCD_EVT_STATUS_CLKDET_ERROR            0x0000020U
#define PHHAL_HW_LPCD_EVT_STATUS_HIF_ACTIVITY            0x0000040U
/*@}*/

/**
* \name STANDBY PREVENTION Status Bits
*/
/*@{*/
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_PREV_TEMP       0x1000000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_HOST_COMM       0x0400000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_SPI             0x0200000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_GPIO_3          0x0020000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_GPIO_2          0x0010000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_GPIO_1          0x0008000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_GPIO_0          0x0004000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_WUC             0x0002000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_LPDET           0x0001000U
#define PHHAL_HW_STANDBY_PREV_EVT_STATUS_RX_ULPDET       0x0000800U
/*@}*/

/**
* \name Boot Event Status Bits
*/
/*@{*/
#define PHHAL_HW_BOOT_EVT_STATUS_ULP_STANDBY             0x4000000U
#define PHHAL_HW_BOOT_EVT_STATUS_RX_ULPDET               0x0400000U
#define PHHAL_HW_BOOT_EVT_STATUS_BOOT_SPI                0x0100000U
#define PHHAL_HW_BOOT_EVT_STATUS_GPIO_3                  0x0010000U
#define PHHAL_HW_BOOT_EVT_STATUS_GPIO_2                  0x0008000U
#define PHHAL_HW_BOOT_EVT_STATUS_GPIO_1                  0x0004000U
#define PHHAL_HW_BOOT_EVT_STATUS_GPIO_0                  0x0002000U
#define PHHAL_HW_BOOT_EVT_STATUS_LPDET                   0x0001000U
#define PHHAL_HW_BOOT_EVT_STATUS_WUC                     0x0000010U
/*@}*/

/**
 * \name NCX3321 PRBS parameter definition and status defines
 */
 /*@{*/
#define PHHAL_HW_NCX3321_PRBS_TYPE_PRBS9                                     0x00U
#define PHHAL_HW_NCX3321_PRBS_TYPE_PRBS15                                    0x01U

#define PHHAL_HW_NCX3321_PRBS_TECHNO_ISO14443_A                              0x00U
#define PHHAL_HW_NCX3321_PRBS_TECHNO_ISO14443_B                              0x01U
#define PHHAL_HW_NCX3321_PRBS_TECHNO_FELICA                                  0x02U
#define PHHAL_HW_NCX3321_PRBS_TECHNO_ISO15693                                0x03U

#define PHHAL_HW_NCX3321_PRBS_BAUD_106                                       0x00U
#define PHHAL_HW_NCX3321_PRBS_BAUD_212                                       0x01U
#define PHHAL_HW_NCX3321_PRBS_BAUD_424                                       0x02U
#define PHHAL_HW_NCX3321_PRBS_BAUD_848                                       0x03U
#define PHHAL_HW_NCX3321_PRBS_BAUD_26                                        0x04U

#define PHHAL_HW_NCX3321_PRBS_MIN_LENGTH                                     0x01U
#define PHHAL_HW_NCX3321_PRBS_MAX_LENGTH                                     0x200U

/*@}*/

/**
* \name NCX3321 Load Configuration for Tx and Rx baud rates/reg values.
* To be used with
* #phhalHw_ApplyProtocolSettings.
* Used by internal API phhalHw_Ncx3321_SetCardMode.
*/
 /*@{*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_106_MILLER                      0U      /**< Type A baud rate @ 106 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_212_MILLER                      1U      /**< Type A baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_424_MILLER                      2U      /**< Type A baud rate @ 424 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_848_MILLER                      3U      /**< Type A baud rate @ 848 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443B_106_NRZ                         4U      /**< Type B baud rate @ 106 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443B_212_NRZ                         5U      /**< Type B baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443B_424_NRZ                         6U      /**< Type B baud rate @ 424 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443B_848_NRZ                         7U      /**< Type B baud rate @ 848 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_FELICA_212                                8U      /**< Type F baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_FELICA_424                                9U      /**< Type F baud rate @ 484 load configurations TX Value.*/

#define PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK100                   0x0AU   /**< Type V (ISO 15693 ) load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK10                    0x0BU   /**< Type V (ISO 15693 ) load configurations TX Value.*/

#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_106_MANCH_SUBC             0x13U   /**< Type A Card mode baud rate @ 106 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_212_BPSK                   0x14U   /**< Type A Card mode baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_424_BPSK                   0x15U   /**< Type A Card mode baud rate @ 424 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_848_BPSK                   0x16U   /**< Type A Card mode baud rate @ 848 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_PT_212                                0x17U   /**< Passive Target baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_PT_424                                0x18U   /**< Passive Target baud rate @ 424 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AT_106                                0x19U   /**< Active Target baud rate @ 106 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AT_212                                0x1AU   /**< Active Target baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AT_424                                0x1BU   /**< Active Target baud rate @ 424 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_GTM_All_Al                                0x1CU   /**< General Target Mode configuration.*/
#define PHHAL_HW_NCX3321_RF_TX_B_PRIME_All_All                           0x1DU   /**< B-prime Mode configuration.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AI_106_106                            0x1EU   /**< Active Initiator baud rate @ 106 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AI_212_212                            0x1FU   /**< Active Initiator baud rate @ 212 load configurations TX Value.*/
#define PHHAL_HW_NCX3321_RF_TX_NFC_AI_424_424                            0x20U   /**< Active Initiator baud rate @ 424 load configurations TX Value.*/

#define PHHAL_HW_NCX3321_TX_NO_CHANGE                                    0xFFU

#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC                  0x80U   /**< Type A baud rate @ 106 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_212_BPSK                        0x81U   /**< Type A baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_424_BPSK                        0x82U   /**< Type A baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_848_BPSK                        0x83U   /**< Type A baud rate @ 848 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443B_106_BPSK                        0x84U   /**< Type B baud rate @ 106 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443B_212_BPSK                        0x85U   /**< Type B baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443B_424_BPSK                        0x86U   /**< Type B baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443B_848_BPSK                        0x87U   /**< Type B baud rate @ 848 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_FELICA_212                                0x88U   /**< Type F baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_FELICA_424                                0x89U   /**< Type F baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO15693_6P6_SC                           0x8AU   /**< Type V (ISO 15693 ) load configurations RX 6.6kbps Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO15693_26_SC                            0x8BU   /**< Type V (ISO 15693 ) load configurations RX 26kbps Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO15693_53_SC                            0x8CU   /**< Type V (ISO 15693 ) load configurations RX 53kbps Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO15693_106                              0x8DU   /**< Type (ISO 15693 106kbps) load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO15693_212                              0x8EU   /**< Type (ISO 15693 212kbps) load configurations RX Value.*/

#define PHHAL_HW_NCX3321_RF_RX_NFC_AI_106                                0x99U   /**< Active Initiator @ baud rate 106 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_AI_212                                0x9AU   /**< Active Initiator @ baud rate 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_AI_424                                0x9BU   /**< Active Initiator @ baud rate 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_106_MILLER                 0x93U   /**< Type A Card mode baud rate @ 106 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_212_MILLER                 0x94U   /**< Type A Card mode baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_424_MILLER                 0x95U   /**< Type A Card mode baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_848_MILLER                 0x96U   /**< Type A Card mode baud rate @ 848 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_PT_212                                0x97U   /**< Passive Target baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_PT_424                                0x98U   /**< Passive Target baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_AT_106                                PHHAL_HW_NCX3321_RF_RX_NFC_AI_106   /**< Active Initiator baud rate @ 106 load configurations RX Value. */
#define PHHAL_HW_NCX3321_RF_RX_NFC_AT_212                                PHHAL_HW_NCX3321_RF_RX_NFC_AI_212   /**< Active Initiator baud rate @ 212 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_NFC_AT_424                                PHHAL_HW_NCX3321_RF_RX_NFC_AI_424   /**< Active Initiator baud rate @ 424 load configurations RX Value.*/
#define PHHAL_HW_NCX3321_RF_RX_GTM_All_All                               0x9CU   /**< General Target Mode configuration.*/
#define PHHAL_HW_NCX3321_RF_RX_B_PRIME_All_All                           0x9DU   /**< B-prime Mode configuration.*/
 /*@}*/

/**
 * \name IRQ check wait time
 */
/*@{*/
#ifndef PHHAL_HW_NCX3321_IRQ_CHECK_WAIT_TIME
#define PHHAL_HW_NCX3321_IRQ_CHECK_WAIT_TIME                             0x01U /**< Once IRQ is high, for this time duration, Ncx3321 HAL sleep, before checking next time. */
#endif /* PHHAL_HW_NCX3321_IRQ_CHECK_WAIT_TIME */

/*@}*/

/**
 * \name Byte length of the TVL header's fields
 */
/*@{*/
#define PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN      0x01U
#define PHHAL_HW_NCX3321_TYPE_FIELD_LEN          0x01U
#define PHHAL_HW_NCX3321_LENGTH_FIELD_LEN        0x02U
#define PHHAL_HW_NCX3321_STATUS_FIELD_LEN        0x01U
/*@}*/

/**
 * \name Instr_WriteRegister state
 */
/*@{*/
#define PHHAL_INSTR_STATE_CHECK_PARAM               0U     /**< Instr WriteRegister in Checking data parameters  */
#define PHHAL_INSTR_STATE_SEND_CMD                  1U     /**< Instr WriteRegister in Sending command  */
/*@}*/

/**
 * end of group phhalHw_NCX3321_Instr Instruction
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
/** \addtogroup phhalHw_NCX3321_Instr Instruction
* \ingroup phhalHw_Ncx3321
* \brief Ncx3321 Instruction functions
* @{
*/

/**
 * NCX3321 CTS configuration parameter structure.
 * User shall fill all the configuration parameters that are required
 * for \ref phhalHw_Ncx3321_Instr_CtsConfig in this data structure.
 * operations.
 */

typedef struct __attribute__((__packed__))
{
    VAR(uint8, ANFCRL_VAR) bPreTriggerShift;                         /**< Defines values to be programmed in CTS_PRE_TRIGGER_SHIFT field in CLIF_CTS_MAIN_CTRL_REG */
    VAR(uint8, ANFCRL_VAR) bTriggerMode;                             /**< Specifies Acquisition mode to be used. 0x00 - POST mode. 0x01 - COMB Mode. 0x02 - PRE-Mode. 0x03 - 0xFF - Invalid */
    VAR(uint8, ANFCRL_VAR) bRamPageWidth;                            /**< Defines value to be programmed in CTS_RAM_PAGE_WIDTH field in CLIF_CTS_SAMPLER_REGISTER. Note: FW might end up using a smaller value if the defined value is not feasible. */
    VAR(uint8, ANFCRL_VAR) bSampleClkDiv;                            /**< Defines Value to be programmed in CTS_SAMPLE_CLK_DIV field in CLIF_CTS_SAMPLER_REGISTER. Values > 0x7 are invalid. */
    VAR(uint8, ANFCRL_VAR) bSampleByteSel;                           /**< Defines Value to be programmed in CTS_SAMPLE_BYTE_SEL field in CLIF_CTS_SAMPLER_REGISTER. Values > 0x0F are invalid. */
    VAR(uint8, ANFCRL_VAR) bSampleModeSel;                           /**< Defines Value to be programmed in CTS_SAMPLE_MODE_SEL field in CLIF_CTS_SAMPLER_REGISTER. Values > 0x2 are invalid. */
    VAR(uint8, ANFCRL_VAR) bTB0;                                     /**< Selects which Test bus to be connected to TB0. */
    VAR(uint8, ANFCRL_VAR) bTB1;                                     /**< Selects which Test bus to be connected to TB1. */
    VAR(uint8, ANFCRL_VAR) bTB2;                                     /**< Selects which Test bus to be connected to TB2. */
    VAR(uint8, ANFCRL_VAR) bTB3;                                     /**< Selects which Test bus to be connected to TB3. */
    VAR(uint8, ANFCRL_VAR) bTTBSelect;                               /**< Selects which CLIF Test bus to be connected to the trigger sources. */
    VAR(uint32, ANFCRL_VAR) dwClifCtsTbCtrl;                         /**< Value to be programmed in CLIF_CTS_TBCTRL_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw0Trigger0;                           /**< Value to be programmed in CLIF_CTS_HW0_TRIGGER0_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw0Trigger1;                           /**< Value to be programmed in CLIF_CTS_HW0_TRIGGER1_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw0Trigger2;                           /**< Value to be programmed in CLIF_CTS_HW0_TRIGGER2_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw1Trigger0;                           /**< Value to be programmed in CLIF_CTS_HW1_TRIGGER0_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw1Trigger1;                           /**< Value to be programmed in CLIF_CTS_HW1_TRIGGER1_REG. */
    VAR(uint32, ANFCRL_VAR) dwHw1Trigger2;                           /**< Value to be programmed in CLIF_CTS_HW1_TRIGGER2_REG. */
} phhalHw_Ncx3321_Instr_CtsConfig_t;


/**
 * \brief NCX3321 Version Information structure
 *
 */
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bHw_Version;                              /**< Hardware version of NCX3321. */
    VAR(uint8, ANFCRL_VAR) bROM_Version;                             /**< ROM version of NCX3321. */
    VAR(uint16, ANFCRL_VAR) wFW_Version;                             /**< Firmware version of NCX33219. */
}phhalHw_Ncx3321_Version_t;

/**
 * end of group phhalHw_NCX3321_Instr Instruction
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phhalHw_NCX3321_Instr Instruction
* \ingroup phhalHw_Ncx3321
* \brief Ncx3321 Instruction functions
* @{
*/

/**
 * \brief Write a 32 bit value (little endian) to a logical register.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Register successfully written.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER Unknown register address.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR front-end returned error.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegister(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRegister,                                /**< [In] Address of the register. */
    VAR(uint32, ANFCRL_VAR) dwValue                                  /**< [In] 32 Bit register value which has to be written. */
    );

/**
 * \brief Perform a logical OR operation on a register using provided mask.
 *
 * This function is used to modify the content of register using a logical OR
 * operation. The content of the register is read and a logical OR operation
 * is performed with the provided mask. The modified content is written back
 * to the register.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Register successfully written.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER Unknown register address.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_MEMORY_ERROR Register is read-only.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterOrMask(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRegister,                                /**< [In] Address of the register. */
    VAR(uint32, ANFCRL_VAR) dwMask                                   /**< [In] Bit-mask used as operand for logical OR operation. */
    );

/**
 * \brief Perform a logical AND operation on a register using provided mask.
 *
 * This function is used to modify the content of register using a logical
 * AND operation. The content of the register is read and a logical AND
 * operation is performed with the provided mask. The modified content is
 * written back to the register.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Register successfully written.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER Unknown register address.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_MEMORY_ERROR Register is read-only.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterAndMask(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRegister,                                /**< [In] Address of the register. */
    VAR(uint32, ANFCRL_VAR) dwMask                                   /**< [In] Bit-mask used as operand for logical AND operation. */
    );

/**
 * \brief Perform a write register operation using a set of Register-Value pairs.
 *
 * This function behaves like #phhalHw_Ncx3321_Instr_WriteRegister,
 * #phhalHw_Ncx3321_Instr_WriteRegisterOrMask and
 * #phhalHw_Ncx3321_Instr_WriteRegisterAndMask with the possibility to combine
 * them. In fact it takes an array of register-type-value set and performs
 * appropriate action. The type reflects the action which is either write
 * register, logical OR operation on a register or logical AND operation on
 * a register. The array is passed in as a buffer (\p pRegTypeValueSets) which
 * contains one or more sets. One set consists of 1 byte register address, 1
 * byte type (see \c #PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE) and 4 bytes
 * value/mask.
 *
 * NOTE: \p wSizeOfRegTypeValueSets size shall be less than \c PHHAL_HW_NCX3321_REG_END_ADDRESS * 6.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS All registers successfully modified.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER At least one unknown register address
 *         provided, or general parameter error (e.g. wSizeOfRegTypeValueSets
 *         is higher than 258)
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_MEMORY_ERROR At least one register is read-only.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteRegisterMultiple(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegTypeValueSets,                      /**< [In] A buffer containing one or more sets Register-Type-Value sets.  */
    VAR(uint16, ANFCRL_VAR) wSizeOfRegTypeValueSets                  /**< [In] Size of the buffer holding the register-type-value sets. */
    );

/**
 * \brief Read back content of a register.
 *
 * This function is used to read back the content of a logical register whose
 * address is given by \p bRegister.
 * The content is available in output parameter \p pValue.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Register successfully read out.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER Unknown register address provided or
 *         pValue set to NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_MEMORY_ERROR At least one register is write-only.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegister(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRegister,                                /**< [In] Address of the register. */
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                 /**< [Out] Pointer to a VAR(uint32, ANFCRL_VAR) variable, where the result (value of the read out register) shall be written to. */
    );

/**
 * \brief Perform a read register operation on a set of registers.
 *
 * This function is used to read multiple logical register at once.
 * The order of the register contents/values within the response (\p ppValues)
 * corresponds to the order of the register addresses within \p pRegisters.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS All requested registers successfully read out.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER At least one unknown register address
 *         provided, or general parameter error (e.g. \p bNumOfRegisters is
 *         higher than 16)
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_MEMORY_ERROR At least one register is write-only.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Time out during handling command.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadRegisterMultiple(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRegisters,                             /**< [In] A buffer containing list of registers (one byte each) to be read out. */
    VAR(uint8, ANFCRL_VAR) bNumOfRegisters,                          /**< [In] Number of registers to be read out (=size of \p pRegisters). Maximum size is 16. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppValues                               /**< [Out] A pointer to a buffer which contains the result, in fact the register values read out. Size of the buffer is 4 * \p bNumOfRegisters. */
    );

/**
 * \brief Write values sequentially to E2PROM.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to write one or more values to E2PROM.
 * \p pDataToWrite shall contain the data to be written to E2PROM starting at
 * the address \p bE2PromAddress.
 * The data is written in sequential order.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS All data written.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p pDataToWrite or \p pDataParams is NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Write operation attempts to write beyond end of E2PROM.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_WriteE2Prom(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wE2PromAddress,                          /**< [In] Start address within E2PROM. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataToWrite,                           /**< [In] Data to be written. */
    VAR(uint16, ANFCRL_VAR) wDataLength                              /**< [In] Number of bytes to be written. */
    );

/**
 * \brief Read values sequentially to E2PROM.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to write one or more values to E2PROM.
 * \p pDataToWrite shall contain the data to be written to E2PROM starting at
 * the address \p bE2PromAddress.
 * The data is written in sequential order.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS All data read.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p pReadData or \p pDataParams is NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_INSTR_ERROR Read operation attempts to read beyond
 *         end of E2PROM.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReadE2Prom(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wE2PromAddress,                          /**< [In] Start address within E2PROM. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pReadData,                              /**< [Out] Read out data. */
    VAR(uint16, ANFCRL_VAR) wDataLength                              /**< [In] Number of bytes to be read. */
    );

/**
 * \brief Perform RF data transmit with initiator/target/PICC in initiator or
 * target modes.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This instruction is used to write TX data to internal RF transmission buffer
 * and start transmission using Transceiver command. The command returns
 * immediately after Transmission is complete.
 *
 * Note: If already a Transceiver command is started, only Data is transmitted by
 * setting Start_Send bit, otherwise a new Transceiver command is started.
 *
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS All data written to internal Tx buffer and
 *         transmission started.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p pTxBuffer or \p pDataParams is NULL,
 *         \p bTxBufferLength > 260 or \p bNumberOfValidBits > 7.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_TransmitRFData(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,                                 /**< [In] Option parameter. */
    VAR(uint8, ANFCRL_VAR) bTxLastBits,                              /**< [In] Number of valid bits in last byte. 0 means all bits are transferred */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                              /**< [In] Buffer containing the data to be used for RF transmission. */
    VAR(uint16, ANFCRL_VAR) wTxBufferLength                          /**< [In] Size of the buffer \p pTxBuffer. */
    );

/**
 * \brief Used to receive data. Can be used in initiator/PCD and
 * target/PICC Modes.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This instruction is used to read data from the internal CLIF RX buffer,
 * if already a reception is complete.
 * \return Status code
 * \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \b wOption is invalid.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRFData(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                             /**< [Out] Pointer to the buffer holding the data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength                          /**< [Out] Number of received data bytes. Range 1 - 1024. */
    );


/**
 * \brief Used to receive data. Can be used in initiator/PCD and
 * target/PICC Modes.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This instruction is a blocking call, returns when probable/expected Event has occurred. If any
 * of the config mask bit is set, then corresponding data is included as part of response.
 * \return Status code
 * \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \b wOption is invalid.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ReceiveRFData(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRespConfigMask,                          /**< [In] Mask to indicate whether to include RX Data OR status registers in response. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                            /**< [Out] Pointer to the buffer holding the data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength                          /**< [Out] Number of received data bytes. Range 1 - 1024. */
    );


/**
 * \brief Switch to standby mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to put NCX3321 into standby mode. The wake up
 * conditions are defined using \p bWakeupControlMask parameter. The
 * instruction does not check if system actually entered standby or standby
 * was prevented. An Event will generated if standby is prevented Or when
 * Ncx3321 wakes-up due to one of the reason mentioned in bWakeupControlMask.
 *
 * A typical way of using this API is given below\n
 * \li phhalHw_Ncx3321_Instr_SwitchModeStandby()
 * \li phhalHw_EventWait() this will return in following scenarios\n
 *       a) #PH_ERR_IO_TIMEOUT EventWait is timed out\n
 *       b) #PH_ERR_NCX3321_USER_CALNCELLED EventWait is aborted\n
 *       c) #PH_NCX3321_EVT_BOOT Ncx3321 wake-up due one of the standby wake-up control reason\n
 *       d) #PH_NCX3321_EVT_STANDBY_PREV Ncx3321 could not enter standby\n
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER No wake up condition defined or
 *         \p wWakeupCounterInMs is out of range.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeStandby(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint8, ANFCRL_VAR) bConfigMask,                              /**< [In] Bit-mask to use config StandBy or Ultra Low power StandBy and also configuration for standby wake-up.*/
    VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs                       /**< [In] Used value for wake-up counter in milliseconds, i.e. after this amount of time NCX3321 wakes up from standby. Maximum value is 2690. */
    );


/**
 * \brief Set LPCD Configuration parameter.
 *
 * This instruction is used to configure LPCD parameters.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p wValue not is valid for the wConfig.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_UNSUPPORTED_PARAMETER \p wConfig is not supported one.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_SetConfig(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
                                               VAR(uint16, ANFCRL_VAR) wConfig,                                  /**< [In] Configuration identifier. */
                                               VAR(uint32, ANFCRL_VAR) dwValue                                   /**< [In] Configuration value. */
                                               );

/**
 * \brief Get LPCD Configuration parameter.
 *
 * This instruction is used to read back the value of a give LPCD parameter.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_UNSUPPORTED_PARAMETER \p wConfig is not supported one.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LPCD_GetConfig(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
                                               VAR(uint16, ANFCRL_VAR) wConfig,                                  /**< [In] Configuration identifier. */
                                               P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                  /**< [Out] Configuration value. */
                                               );

/**
 * \brief Switch to LPCD mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This single function is used for LPCD/ULPCD calibration and also for making NCX3321
 * to enter LPCD. if Mode is set for calibration, parameters \p bWakeUpCntrlHwLpcd,\p
 * dwLpcdRefValue, and \p wWakeupCounterInMs are don't care. For LPCD mode,
 * wait period in msecs between two LPCD cycles is defined by \p wWakeupCounterInMs.
 * In-case of ULPCD \p bWakeUpCntrlHwLpcd configures source to make Ncx3321 exit ULPCD.
 * During wait period NCX3321 is in standby. The function returns immediately, i.e.
 * it does not wait until a card has been detected. On detection of a card,
 * NCX3321 raises an interrupt and normal mode is entered again.
 *
 * GPIO3 abort for ULPCD, HIF abort for LPCD are available by default to exit low power modes.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p wWakeupCounterInMs is out of range.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeLpcd(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bLpcdMode,                                /**< [In] Lpcd Mode; 1) 0x00 ULPCD Calibration, 2) 0x01 Enter ULPCD, 2) 0x02 LPCD calibration, 3) 0x03 Enter LCPD, 4) 0x04 Single mode,
	                                                                                       5)0x0C Single mode with calibration event. */
    VAR(uint8, ANFCRL_VAR) bWakeUpCntrlHwLpcd,                       /**< [In] BitMask configuring wakeup source in case of ULPCD. */
    VAR(uint32, ANFCRL_VAR) dwLpcdRefValue,                           /**< [In] LPCD/ULPCD calibration reference value. */
    VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs                        /**< [In] Used value for wake-up counter in milliseconds, i.e. after this amount of time NCX3321 wakes up from standby. Maximum value is 2690. */
    );


/**
 * \brief Switch to Autocoll mode.
 *
 * This function is used to put NCX3321 into Autocoll mode in order to handle
 * target mode activation.
 * The termination condition depends on \p bAutocollMode.
 * The function returns immediately, i.e. it does not wait until autocoll
 * terminates. Once terminated, autocoll raises an interrupt and normal mode
 * is entered again.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p wWakeupCounterInMs is 0.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeAutocoll(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRfTechnologyMask,                        /**< [In] Bit-mask indicating the RF technology to listen for during Autocoll. For example see #PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A. */
    VAR(uint8, ANFCRL_VAR) bAutocollMode                             /**< [In] Autocoll operation mode to be used. See for example #PHHAL_HW_NCX3321_AUTOCOLL_MODE_TERMINATE_ON_RF_OFF. */
    );

#ifdef NXPBUILD__PHPAL_MIFARE_SW
/**
 * \brief Perform authentication on an activated Mifare Classic card.
 *
 * This function is used to perform a Mifare Classic Authentication on an
 * activated card. It takes the key, card UID and the key type to authenticate
 * at given block address.
 *
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Authentication successful.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p bKeyType wrong, \p pUid or \p pKey
 *         is NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_TIMEOUT Timeout during authentication.
 * \retval #PH_ERR_AUTH_ERROR Authentication failed.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_MifareAuthenticate(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,                                    /**< [In] Key to be used for authentication. uint8[6]. */
    VAR(uint8, ANFCRL_VAR) bKeyType,                                  /**< [In] Key type. Either #PHHAL_HW_MFC_KEYA or #PHHAL_HW_MFC_KEYB. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                  /**< [In] Block-Number on card to authenticate to. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                                     /**< [In] UID of the activated card. uint8[4]. */
    );

#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_LoadRfConfiguration(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRfTxConfiguration,                       /**< [In] TX configuration index to be used. 0xff means TX Configuration is not modified. */
    VAR(uint8, ANFCRL_VAR) bRfRxConfiguration                        /**< [In] RX configuration index to be used. 0xff means RX Configuration is not modified. */
    );

/**
 * \brief Update the RF configuration
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to update the RF configuration within E2PROM.
 * Only registers available within the respective RF configuration can be
 * updated, registers can't be added or removed.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS RF configuration successfully updated.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p bRfConfigurationSize not a multiple of
 *         6 or out of range. \p pRfConfiguration is NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_UpdateRfConfiguration(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfiguration,                       /**< [In] Array containing one or more configurations to be written. One configuration is a set of
                                                           1 Byte RX or TX configuration index
                                                           1 Byte Register address within the RF configuration
                                                           4 Bytes value to be written into the register. */
    VAR(uint8, ANFCRL_VAR) bRfConfigurationSize                     /**< [In] Size of \p pRfConfiguration. Must be a multiple of 6, maximum value is 252. */
    );


/**
 * \brief Retrieve the RF configuration.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to read out an Protocol RF configuration of NCX3321.
 * User needs to provide \p pRfConfBuf buffer of minimum length #PHHAL_HW_NCX3321_MIN_RF_CONFIGURATION_BUFFER_SIZE
 * to get all the register address-value-pairs of a particular protocol which can be
 * sent using \p bRfConfiguration parameter.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS RF configuration successfully updated.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p bRfConfigurationSize not a multiple of
 *         6 or out of range. \p pRfConfiguration is NULL.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RetrieveRfConfiguration(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRfConfiguration,                         /**< [In] RF TX or RX configuration index to be used. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBuf,                             /**< [Out] Pointer to a buffer containing \p bNumOfRegisters configurations. One configuration is a set of
                                                           1 Byte Register address within the RF configuration
                                                           4 Bytes value to be written into the register. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRfConfBufSize                         /**< [InOut] Input the application buffer size and output with valid RF configuration data to application. */
    );

/**
 * \brief Turns the RF field ON.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used to turn the RF field ON.
 * The configurations are available in \p ppRfOnConfig.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS RF Field turn ON sent to IC.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p bRfOnConfig out of range.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOn(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bRfOnConfig                               /**< [In] The ON Configuration.
                                                           Bit 0   0   Use collision avoidance.
                                                                   1   Disable collision avoidance.*/
    );

/**
 * \brief Turns the RF field OFF.
 *
 * This function is used to turn the RF field OFF.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS RF Field turn OFF sent to IC.
 * \retval #PH_ERR_NCX3321_INVALID_PARAMETER \p PData params is null.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
 * \retval #PH_ERR_NCX3321_NO_LOAD_RF_CFGS Error in case RF ON is triggered w/o applying proper Load Rf configurations.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_RfOff(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Switch to Normal Boot mode.
 *
 * This function is used, after POR,  to Boot NCX3321 into Normal mode.
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeBootNormal(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Switch to Normal mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This function is used when system is already operating in Normal mode and
 * is waiting for some event to happen like after sending Switch_Mode_AutoColl.
 * This command brings NCX3321 back to normal mode of operation.
 *
 *
 * \return Status Code
 * \retval #PH_ERR_NCX3321_SUCCESS Instruction successfully executed.
 * \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeNormal(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief Perform RF data exchange for Passive/Active Initiator mode. This
* is a blocking call.
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
*
* This instruction writes data to internal CLIF transmission buffer and, additionally, starts the RF
* transmission. The instruction returns, after end of transmission and end
* of reception.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER \b wOption is invalid.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ExchangeRFData(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,                                 /**< [In] Option parameter. */
    VAR(uint8, ANFCRL_VAR) bTxLastBits,                              /**< [In] Number of valid bits in last TX byte. Range 0 - 7. */
    VAR(uint8, ANFCRL_VAR) bRespControl,                             /**< [In] Control flag to include RX Data and status registers in response. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,                                /**< [In] Data to transmit. */
    VAR(uint16, ANFCRL_VAR) wTxDataLength,                           /**< [In] Number of bytes to transmit. Range 1 - 261. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxData,                              /**< [Out] Pointer to received data (will also contain receive Rf data, if RX Data bit is set in bRespControl). */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxDataLength                          /**< [Out] Number of received data bytes. Range 1 - 1024. */
    );

/**
* \brief This instruction is used to configure the digital test bus feature.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER Parameter structure size is invalid.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusDigital(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bSignalIndex,                             /**< [In] Signal Index. */
    VAR(uint8, ANFCRL_VAR) bBitIndex,                                /**< [In] Bit Index. */
    VAR(uint8, ANFCRL_VAR) bPadIndex                                 /**< [In] Pad Index. */
    );

/**
* \brief This instruction is used to configure the analog test bus feature.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER Parameter structure size is invalid.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_ConfigureTestBusAnalog(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bConfig,                                  /**< [In] */
    VAR(uint8, ANFCRL_VAR) bCombinedMode,                            /**< [In] */
    VAR(uint8, ANFCRL_VAR) bTBIndex0,                                /**< [In] */
    VAR(uint8, ANFCRL_VAR) bTBIndex1,                                /**< [In] */
    VAR(uint8, ANFCRL_VAR) bShiftIndex0,                             /**< [In] */
    VAR(uint8, ANFCRL_VAR) bShiftIndex1,                             /**< [In] */
    VAR(uint8, ANFCRL_VAR) bMask0,                                   /**< [In] */
    VAR(uint8, ANFCRL_VAR) bMask1                                    /**< [In] */
    );

/**
* \brief This instruction is used to enable/disable the CTS logging feature.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER Parameter is invalid.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsEnable(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bOption                                   /**< [In] Enable/Disable the CTS logging feature. 0 - Disable. 1 - Enable. */
    );

/**
* \brief This instruction is used to write configuration values to all the
* required CTS Registers such as Triggers, Test Bus registers, Sampling
* configuration etc.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsConfig(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(phhalHw_Ncx3321_Instr_CtsConfig_t, AUTOMATIC, ANFCRL_APPL_DATA) pCtsConfig     /**< [In] Pointer to CTS configuration data structure. */
    );

/**
* \brief This instruction retrieves the data log of the captured test bus data
* samples stored in the memory buffer. Buffer size of \b pLogData shall one more then
* the \b bChunkSize provided by the user.
*
* If #PH_ERR_NCX3321_SUCCESS_CHAINING is returned by this API then the user shall call this
* API in a loop until #PH_ERR_NCX3321_SUCCESS is returned by this API to analyze the complete
* CTS Log.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_SUCCESS_CHAINING Complete CTS Log data is not yet been retrieved from NCX3321.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_NO_CTS_EVENT Shall be returned if CTS Event is not been received from NCX3321.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_CtsRetrieveLog(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bChunkSize,                               /**< [In] Expected size of Log data that needs to be retrieved from NCX3321. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLogData,                               /**< [Out] The data log of the captured data samples stored in the memory buffer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bLogDataSize                            /**< [Out] Size of the retrieved data log of the captured data samples stored in the memory buffer. */
    );

/**
* \brief This instruction retrieves the DieID of the CHIP
* Buffer size of 16 bytes shall by provided by the user
* to read DieId information.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER Input parameter is invalid.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetDieId(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDieIdValue                             /**< [InOut] User to provide buffer of 16 byte to get DieId of the NCX3321 chip. */
    );

/**
* \brief This instruction retrieves Hw Version, ROM Version
* and FW version. Buffer of size N + 1 bytes shall be provided
* by the user, where N is the number of byte required for version
* information,
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INVALID_PARAMETER Input parameter is invalid.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Operation failed.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_GetVersion(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(phhalHw_Ncx3321_Version_t, AUTOMATIC, ANFCRL_APPL_DATA) pVersion             /**< [InOut] structure pointer for, 4 byte Version Information read from NCX3321. */
    );

/**
* \brief This instruction switches operation mode of
* Ncx3321 to FIRMWARE_DOWNLOAD mode.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Switch Mode has not been Entered.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_SwitchModeDownload(
        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams        /**< [In] Pointer to this layer's parameter structure. */
        );


/**
* \brief This instruction send pseudo-random binary sequence. Once this instruction is received
* the Ncx3321 will continue to send the pseudo-random binary sequence until Switch_Mode_Normal
* command is sent.
*
* Before this function is called, it is expected that the user/upper layer has performed\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
* \li HAL initialization - Example phhalHw_Ncx3321_Init()
* \li Load the protocol -  phhalHw_ApplyProtocolSettings()
* \li Field ON          -  phhalHw_FieldOn()
* \li Call phhalHw_Ncx3321_Instr_PrbsTest() with required PRBS sequence either PRBS9 or PRBS15.
*
* \return Status code
* \retval #PH_ERR_NCX3321_SUCCESS Operation successful.
* \retval #PH_ERR_NCX3321_INVALID_DATA_PARAMS wrong hal layer parameter.
* \retval #PH_ERR_NCX3321_INTERNAL_ERROR Switch Mode has not been Entered.
* \retval #PH_ERR_NCX3321_USER_CALNCELLED Instruction aborted.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Instr_PrbsTest(
        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bPrbs_type                               /**< [In] Prbs_type a) 0x00 PRBS9 b) 0x01 PRBS15 */
        );
/**
 * end of group phhalHw_NCX3321_Instr Instruction
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTR_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INSTR_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
#endif  /* PHHALHW_NCX3321_INSTR_H */
