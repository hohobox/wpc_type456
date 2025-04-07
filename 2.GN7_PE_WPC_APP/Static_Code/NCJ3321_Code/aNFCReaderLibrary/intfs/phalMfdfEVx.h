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
*   @file    phalMfdfEVx.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdfEVx MIFARE DESFire EVx
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
#ifndef PHALMFDFEVX_H
#define PHALMFDFEVX_H

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
#include "phTMIUtils.h"
#include "phhalHw.h"
#include "phpalMifare.h"
#include <ph_TypeDefs.h>
#include <ph_RefDefs.h>
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALMFDFEVX_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalMfdfEVx.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALMFDFEVX_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdfEVx.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALMFDFEVX_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALMFDFEVX_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALMFDFEVX_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdfEVx.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHAL_MFDFEVX_SW

/**
 * \defgroup phalMfdfEVx_Sw Component : Software
 * \ingroup phalMfdfEVx
 * \brief Software implementation of the MIFARE DESFire EVx commands 
 * @{
 */

#define PHAL_MFDFEVX_SW_ID                                              0x01U   /**< ID for Software MF DesFire layer. */

/**
* \name Sizes 
*/
/*@{*/
#define PHAL_MFDFEVX_SIZE_TI                                                4U  /**< Size of Transaction Identifier. */
#define PHAL_MFDFEVX_SIZE_MAC                                               16U /**< Size of (un truncated) MAC. */
#define PHAL_MFDFEVX_BLOCK_SIZE                                             16U /**< Block Size */
#define PHAL_MFDFEVX_MAX_WRITE_SIZE                                     0xFFFDU /**< Max size in a Write function. */
/*@}*/


/**
 * end of group phalMfdfEVx_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PHAL_MFDFEVX

/** 
 * \defgroup phalMfdfEVx MIFARE DESFire EVx
 * \ingroup phal
 * \brief These Functions implement the MIFARE DESFire EVx commands.
 * @{
 */

/**
* \name Other Options for various Functions 
*/
/*@{*/
#define PHAL_MFDFEVX_ORIGINALITY_KEY_FIRST                                              0x01U   /**< Originality key for AES */
#define PHAL_MFDFEVX_ORIGINALITY_KEY_LAST                                               0x04U   /**< Originality key for AES  */
#define PHAL_MFDFEVX_MAC_DATA_INCOMPLETE                                                0x01U   /**< Option for indicating more data to come in next call for MAC calculation */
#define PHAL_MFDFEVX_COMMUNICATION_MAC_ON_RC                                            0x02U   /**< MAC is appended over response  */
#define PHAL_MFDFEVX_COMMUNICATION_MAC_ON_CMD                                           0x03U   /**< MAC is appended over command. */
#define PHAL_MFDFEVX_AUTHENTICATE_RESET                                                 0x08U   /**< authentication state shall be reset */
#define PHAL_MFDFEVX_KEYSETVALUES_PRESENT                                               0x01U   /**< Bit 0 of bKeySettings3 decides the presence of the key set values array. */
#define PHAL_MFDFEVX_KEYSETT3_PRESENT                                                   0x10U   /**< Bit 4 of bKeySettings2 decides the presence of the keysetting3. */
#define PHAL_MFDFEVX_MFC_KILL_KEY                                                       0x31U   /**< MFCKill key for AES */
/*@}*/

/**
* \name Error Codes mapping to custom values. 
*/
/*@{*/
#define PHAL_MFDFEVX_NO_CHANGES                                     (PH_ERR_CUSTOM_BEGIN + 0U)   /**< MFDFEVx Response - No changes done to backup files. */
#define PHAL_MFDFEVX_ERR_OUT_OF_EEPROM_ERROR                        (PH_ERR_CUSTOM_BEGIN + 1U)   /**< MFDFEVx Response - Insufficient NV-Memory. */
#define PHAL_MFDFEVX_ERR_NO_SUCH_KEY                                (PH_ERR_CUSTOM_BEGIN + 2U)   /**< MFDFEVx Invalid key number specified. */
#define PHAL_MFDFEVX_ERR_PERMISSION_DENIED                          (PH_ERR_CUSTOM_BEGIN + 3U)   /**< MFDFEVx Current configuration/status does not allow the requested command. */
#define PHAL_MFDFEVX_ERR_APPLICATION_NOT_FOUND                      (PH_ERR_CUSTOM_BEGIN + 4U)   /**< MFDFEVx Requested AID not found on PICC. */
#define PHAL_MFDFEVX_ERR_BOUNDARY_ERROR                             (PH_ERR_CUSTOM_BEGIN + 5U)   /**< MFDFEVx Attempt to read/write data from/to beyond the files/record's limits. */
#define PHAL_MFDFEVX_ERR_COMMAND_ABORTED                            (PH_ERR_CUSTOM_BEGIN + 6U)   /**< MFDFEVx Previous cmd not fully completed. Not all frames were requested or provided by the PCD. */
#define PHAL_MFDFEVX_ERR_COUNT                                      (PH_ERR_CUSTOM_BEGIN + 7U)   /**< MFDFEVx Num. of APPLNS limited to 28. No additional applications possible. */
#define PHAL_MFDFEVX_ERR_DUPLICATE                                  (PH_ERR_CUSTOM_BEGIN + 8U)   /**< MFDFEVx File/Application with same number already exists. */
#define PHAL_MFDFEVX_ERR_FILE_NOT_FOUND                             (PH_ERR_CUSTOM_BEGIN + 9U)   /**< MFDFEVx Specified file number does not exist. */
#define PHAL_MFDFEVX_ERR_PICC_CRYPTO                                (PH_ERR_CUSTOM_BEGIN + 10U)  /**< MFDFEVx Crypto error returned by PICC. */
#define PHAL_MFDFEVX_ERR_PARAMETER_ERROR                            (PH_ERR_CUSTOM_BEGIN + 11U)  /**< MFDFEVx Parameter value error returned by PICC. */
#define PHAL_MFDFEVX_ERR_DF_GEN_ERROR                               (PH_ERR_CUSTOM_BEGIN + 12U)  /**< MFDFEVx DesFire Generic error. Check additional Info. */
#define PHAL_MFDFEVX_ERR_DF_7816_GEN_ERROR                          (PH_ERR_CUSTOM_BEGIN + 13U)  /**< MFDFEVx ISO 7816 Generic error. Check Additional Info. */
#define PHAL_MFDFEVX_ERR_CMD_INVALID                                (PH_ERR_CUSTOM_BEGIN + 14U)  /**< MFDFEVx ISO 7816 Generic error. Check Additional Info. */
#define PHAL_MFDFEVX_ERR_NOT_SUPPORTED                              (PH_ERR_CUSTOM_BEGIN + 15U)  /**< MFDFEVx Not Supported Error. */
#define PHAL_MFDFEVX_ERR_INTEGRITY_ERROR                            (PH_ERR_CUSTOM_BEGIN + 16U)  /**< MFDFEVx integrity error. */
#define PHAL_MFDFEVX_ERR_MEMORY_ERROR                               (PH_ERR_CUSTOM_BEGIN + 17U)  /**< MFDFEVx memory error. */
#define PHAL_MFDFEVX_ERR_OPERATION_OK_LIM                           (PH_ERR_CUSTOM_BEGIN + 27U)  /**< MFDFEVx custom error code for Successful operation with limited functionality. */
#define PHAL_MFDFEVX_ERR_CMD_OVERFLOW                               (PH_ERR_CUSTOM_BEGIN + 28U)  /**< MFDFEVx Too many commands in the session or transaction. */
#define PHAL_MFDFEVX_ERR_GEN_FAILURE                                (PH_ERR_CUSTOM_BEGIN + 29U)  /**< MFDFEVx Failure in the operation of the PD. */
#define PHAL_MFDFEVX_ERR_BNR                                        (PH_ERR_CUSTOM_BEGIN + 30U)  /**< MFDFEVx Invalid Block number: not existing in the implementation or not valid to target with this command. */
#define PHAL_MFDFEVX_ERR_FORMAT                                     (PH_ERR_CUSTOM_BEGIN + 31U)  /**< MFDFEVx Format of the command is not correct (e.g. too many or too few bytes). */
/*@}*/

/**
* \name ISO7816-4 Error Codes mapping to custom values. 
*/
/*@{*/
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_MEMORY_FAILURE              (PH_ERR_CUSTOM_BEGIN + 18U)  /**< ISO7816 custom response code for memory failure. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_WRONG_LENGTH                (PH_ERR_CUSTOM_BEGIN + 19U)  /**< ISO7816 custom response code for wrong length, no further indication. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_SECURITY_STAT_NOT_SATISFIED (PH_ERR_CUSTOM_BEGIN + 20U)  /**< ISO7816 custom response code for security status not satisfied. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_CONDITIONS_NOT_SATISFIED    (PH_ERR_CUSTOM_BEGIN + 21U)  /**< ISO7816 custom response code for conditions of use not satisfied. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_FILE_APPLICATION_NOT_FOUND  (PH_ERR_CUSTOM_BEGIN + 22U)  /**< ISO7816 custom response code for file or application not found. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_INCORRECT_PARAM_P1_P2       (PH_ERR_CUSTOM_BEGIN + 23U)  /**< ISO7816 custom response code for incorrect parameters P1-P2. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_LC_INCONSISTENT             (PH_ERR_CUSTOM_BEGIN + 24U)  /**< ISO7816 custom response code for Lc inconsistent with parameter P1-P2. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_WRONG_LE                    (PH_ERR_CUSTOM_BEGIN + 25U)  /**< ISO7816 custom response code for wrong LE field. */
#define PHAL_MFDFEVX_ISO7816_CUSTOM_ERR_INS_CODE_NOT_SUPPORTED      (PH_ERR_CUSTOM_BEGIN + 26U)  /**< ISO7816 custom response code for instruction code not supported or invalid. */
/*@}*/

/**
* \name Authentication Modes 
*/
/*@{*/
#define PHAL_MFDFEVX_NOT_AUTHENTICATED                                  0xFFU   /**< No authentication. */
#define PHAL_MFDFEVX_AUTHENTICATE                                       0x0AU   /**< D40 Authentication; 0x0A. */
#define PHAL_MFDFEVX_AUTHENTICATEISO                                    0x1AU   /**< ISO Authentication; 0x1A. */
#define PHAL_MFDFEVX_AUTHENTICATEAES                                    0xAAU   /**< AES Authentication; 0xAA. */
#define PHAL_MFDFEVX_AUTHENTICATEEV2                                    0x71U   /**< EV2 Authentication; 0x71. */

#define PHAL_MFDFEVX_AUTH_FIRST                                         0x01U   /**< Option to perform EVx First Authentication. */
#define PHAL_MFDFEVX_AUTH_NONFIRST                                      0x00U   /**< Option to perform EVx NonFirst Authentication. */
/*@}*/

/**
* \name Option to be used for InitializeKeySet amd CreateTransactionMACFile command. 
*/
/*@{*/
#define PHAL_MFDFEVX_KEY_TYPE_2K3DES                                    0x00U   /**< Option for 2 Key Triple Des key type. */
#define PHAL_MFDFEVX_KEY_TYPE_3K3DES                                    0x01U   /**< Option for 3 Key Triple Des key type. */
#define PHAL_MFDFEVX_KEY_TYPE_AES128                                    0x02U   /**< Option for AES 128 key type. */
/*@}*/

/**
* \name Option for most of the commands. 
*/
/*@{*/
#define PHAL_MFDFEVX_SAI                                                0x80U   /**< Option for Secondary application indicator (SAI). */
/*@}*/

/**
* \name Options for application / file creation commands command. 
*/
/*@{*/
#define PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE                        0x00U   /**< Option to indicate no ISO File ID or ISODFName are present. */
#define PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE                              0x01U   /**< Option to indicate the presence of ISO FileID. */
#define PHAL_MFDFEVX_ISO_DF_NAME_AVAILABLE                              0x02U   /**< Option to indicate the presence of ISO DFName. */
#define PHAL_MFDFEVX_ISO_FILE_ID_DF_NAME_AVAILABLE                      0x03U   /**< Option to indicate the presence of both ISO FileID and ISO DFName. */
/*@}*/

/**
* \name The communication mode to be used. 
*/
/*@{*/
#define PHAL_MFDFEVX_COMMUNICATION_PLAIN                                0x00U   /**< Plain mode of communication. */
#define PHAL_MFDFEVX_COMMUNICATION_PLAIN_1                              0x20U   /**< Plain mode of communication. */
#define PHAL_MFDFEVX_COMMUNICATION_MACD                                 0x10U   /**< MAC mode of communication. */
#define PHAL_MFDFEVX_COMMUNICATION_ENC                                  0x30U   /**< Enciphered mode of communication. */
/*@}*/

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/* MIFARE DESFire EVx secure messaging related commands. ------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_SecureMessaging Commands_SecureMessaging
 * \brief These Components implement the MIFARE DESFire EVx Secure Messaging related commands.
 * @{
 */

/**
* \name Diversification options to be used with Authenticate command. 
*/
/*@{*/
#define PHAL_MFDFEVX_NO_DIVERSIFICATION                                 0xFFFFU /**< No diversification. */
#define PHAL_MFDFEVX_DIV_METHOD_ENCR        PH_CRYPTOSYM_DIV_MODE_DESFIRE       /**< Encryption based method of diversification. */
#define PHAL_MFDFEVX_DIV_METHOD_CMAC        PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS   /**< CMAC based method of diversification. */
#define PHAL_MFDFEVX_DIV_OPTION_2K3DES_FULL PH_CRYPTOSYM_DIV_OPTION_2K3DES_FULL /**< Encryption based method, full key diversification. */
#define PHAL_MFDFEVX_DIV_OPTION_2K3DES_HALF PH_CRYPTOSYM_DIV_OPTION_2K3DES_HALF /**< Encryption based method, half key diversification. */
/*@}*/


/**
 * end of group phalMfdfEVx_SecureMessaging Commands_SecureMessaging
 * @}
 */
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Memory and Configuration management commands. ------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_MemoryConfiguration Commands_MemoryConfiguration
 * \brief These Components implement the MIFARE DESFire EVx Memory and Configuration Management related commands.
 * @{
 */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

/**
* \name Options for SetConfiguration command. 
*/
/*@{*/
#define PHAL_MFDFEVX_SET_CONFIG_OPTION0                                 0x00U   /**< Option 0 for updating the PICC Configuration. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION1                                 0x01U   /**< Option 1 for updating the Default Keys. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION2                                 0x02U   /**< Option 2 for updating the ATS. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION3                                 0x03U   /**< Option 3 for updating the SAK. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION4                                 0x04U   /**< Option 4 for updating the Secure Messaging. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION5                                 0x05U   /**< Option 5 for updating the Capability Data. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTION6                                 0x06U   /**< Option 6 for updating the VC Installation Identifier. */
#define PHAL_MFDFEVX_SET_CONFIG_OPTIONC                                 0x0CU   /**< Option C for updating the ATQA information. */
/*@}*/

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
* \name Options for GetCardUID command. 
*/
/*@{*/
#define PHAL_MFDFEVX_GET_CARD_UID_EXCHANGE_OPTION_OFF                   0x00U   /**< Option for not exchanging the Option information to PICC. */
#define PHAL_MFDFEVX_GET_CARD_UID_EXCHANGE_OPTION_ON                    0x01U   /**< Option for exchanging the Option information to PICC. */
#define PHAL_MFDFEVX_GET_CARD_UID_OPTION_NUID_NOT_RETURNED              0x00U   /**< Option for no return of 4 byte NUID from PICC. */
#define PHAL_MFDFEVX_GET_CARD_UID_OPTION_NUID_RETURNED                  0x01U   /**< Option for return of 4 byte NUID from PICC. */
/*@}*/

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_MemoryConfiguration Commands_MemoryConfiguration
 * @}
 */

/* MIFARE DESFire EVx Key management commands. ---------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_KeyManagement Commands_KeyManagement
 * \brief These Components implement the MIFARE DESFire EVx Key Management related commands.
 * @{
 */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

/**
* \name Diversification options to be used with ChangeKey command. 
*/
/*@{*/
#define PHAL_MFDFEVX_CHGKEY_NO_DIVERSIFICATION                          0xFFFFU /**< No diversification. */
#define PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY                                 0x0002U /**< Bit 1. Indicating diversification of new key required. */
#define PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY                                 0x0004U /**< Bit 2 indicating old key was diversified. */
#define PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY_ONERND                          0x0008U /**< Bit 3 indicating new key diversification using one rnd. Default is two rounds. */
#define PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY_ONERND                          0x0010U /**< Bit 4 indicating old key diversification using one rnd. Default is two rounds. */
#define PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC                             0x0020U /**< Bit 5 indicating key diversification method based on CMAC. Default is Encryption method */
/*@}*/


#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

/**
* \name Option to be used for GetKeyVersion command. 
*/
/** @{*/
#define PHAL_MFDFEVX_KEYSETNO_NOT_PRESENT                               0x00U   /**< Option for KeySetNo not available in the command. */
#define PHAL_MFDFEVX_KEYSETNO_PRESENT                                   0x70U   /**< Option for KeySetNo available in the command. */
#define PHAL_MFDFEVX_RETRIVE_KEY_VERSION                                0x00U   /**< Option for retrieving the key version form specific Key Set. */
#define PHAL_MFDFEVX_RETRIVE_KEY_SET_VERSION                            0x80U   /**< Option for retrieving the key set version. */
/** @}*/

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_KeyManagement Commands_KeyManagement
 * @}
 */

/* MIFARE DESFire EVx Application management commands. -------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_AppManagement Commands_ApplicationManagement
 * \brief These Components implement the MIFARE DESFire EVx Application Management related commands.
 * @{
 */

/**
* \name Option to represent the selection of secondary application. 
*/
/*@{*/
#define PHAL_MFDFEVX_SELECT_PRIMARY_APP                                 0x00U   /**< Option for Primary application selection. */
#define PHAL_MFDFEVX_SELECT_SECOND_APP                                  0x01U   /**< Option for Secondary application selection. */
/*@}*/

/**
 * end of group phalMfdfEVx_AppManagement Commands_ApplicationManagement
 * @}
 */




/* MIFARE DESFire EVx File management commands. --------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_FileManagement Commands_FileManagement
 * \brief These Components implement the MIFARE DESFire EVx File Management related commands.
 * @{
 */

/**
* \name The File Option to be used. 
*/
/*@{*/
#define PHAL_MFDFEVX_FILE_OPTION_PLAIN                                                  0x00U   /**< Plain mode of communication. */
#define PHAL_MFDFEVX_FILE_OPTION_PLAIN_1                                                0x02U   /**< Plain mode of communication. */
#define PHAL_MFDFEVX_FILE_OPTION_MACD                                                   0x01U   /**< MAC mode of communication. */
#define PHAL_MFDFEVX_FILE_OPTION_ENC                                                    0x03U   /**< Enciphered mode of communication. */
#define PHAL_MFDFEVX_FILE_OPTION_MFC_MAPPING_ENABLED                                    0x20U   /**< MIFARE Classic contactless IC mapping support enabled. */
#define PHAL_MFDFEVX_FILE_OPTION_SDM_MIRRORING_ENABLED                                  0x40U   /**< Secure Dynamic Messaging and Mirroring support enabled. */
#define PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT                                  0x80U   /**< Additional Access Right enabled. */
/*@}*/

/**
* \name Option for CreateValueFile file command. 
*/
/*@{*/
#define PHAL_MFDFEVX_ENABLE_LIMITEDCREDIT                               0x01U   /**< Bit 0 set to 1 to enable Limited credit. */
#define PHAL_MFDFEVX_ENABLE_FREE_GETVALUE                               0x02U   /**< Bit 1 set to 1 to enable free GetValue. */
/*@}*/

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
* \name Options to diversify the key. 
*/
/*@{*/
#define PHAL_MFDFEVX_CREATE_TMAC_FILE_DIV_OFF                           0x00    /**< Option to disable key diversification. */
#define PHAL_MFDFEVX_CREATE_TMAC_FILE_DIV_ON                            0x01    /**< Option to enable key diversification. */
/*@}*/

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
* \name The File option and other flags for ChangeFileSettings command. 
*/
/*@{*/
#define PHAL_MFDFEVX_EXCHANGE_ADD_INFO_BUFFER_COMPLETE                  0x80U    /**< To exchange the information available in pAddInfo buffer as is. */
#define PHAL_MFDFEVX_FILE_OPTION_TMCLIMIT_PRESENT                       0x20U    /**< 5th Bit of FileOption indicating TMC limit config. */
/*@}*/

/**
 * end of group phalMfdfEVx_FileManagement Commands_FileManagement
 * @}
 */

/* MIFARE DESFire EVx Data management commands. --------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_DataManagement Commands_DataManagement
 * \brief These Components implement the MIFARE DESFire EVx Data Management related commands.
 * @{
 */

/**
* \name Chaining format to be used for DataManagement commands. 
*/
/*@{*/
#define PHAL_MFDFEVX_APPLICATION_CHAINING                               0x00U   /**< Option to represent the application chaining format.
                                                                                 *   Here AF will be available in command and response.
                                                                                 */
#define PHAL_MFDFEVX_ISO_CHAINING                                       0x01U   /**< Option to represent the ISO14443-4 chaining format.
                                                                                 *   Here AF will not be available in command and response rather
                                                                                 *   the chaining will be done using the ISO14443-4 protocol.
                                                                                 */
/*@}*/

/**
 * end of group phalMfdfEVx_DataManagement Commands_DataManagement
 * @}
 */




/* MIFARE DESFire EVx Transaction management commands. -------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_TransactionnManagement Commands_TransactionManagement
 * \brief These Components implement the MIFARE DESFire EVx Transaction Management related commands.
 * @{
 */

/**
* \name Options for CommitTransaction command. 
*/
/*@{*/
#define PHAL_MFDFEVX_COMMIT_TXN_OPTION_NOT_EXCHANGED                    0x00    /**< Option byte is not exchanged to the PICC. */
#define PHAL_MFDFEVX_COMMIT_TXN_NO_TMC_TMV_RETURNED                     0x80    /**< Option byte exchanged to PICC and represent no return of TMC and TMV. */
#define PHAL_MFDFEVX_COMMIT_TXN_TMC_TMV_RETURNED                        0x81    /**< Option byte exchanged to PICC and represent return of TMC and TMV. */
/*@}*/

/**
 * end of group phalMfdfEVx_TransactionnManagement Commands_TransactionManagement
 * @}
 */




/* MIFARE DESFire EVx ISO7816-4 commands. ---------------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_ISO7816 Commands_ISO7816
 * \brief These Components implement the MIFARE DESFire EVx ISO/IEC 7816-4 Basic commands.
 * @{
 */

/**
* \name Options for ISOSelectFile command. 
*/
/*@{*/
#define PHAL_MFDFEVX_FCI_RETURNED                                       0x00U   /**< Option to indicate the return of FCI. */
#define PHAL_MFDFEVX_FCI_NOT_RETURNED                                   0x0CU   /**< Option to indicate the no return of FCI. */
#define PHAL_MFDFEVX_SELECTOR_0                                         0x00U   /**< Option to indicate Selection by 2 byte file Id. */
#define PHAL_MFDFEVX_SELECTOR_1                                         0x01U   /**< Option to indicate Selection by child DF. */
#define PHAL_MFDFEVX_SELECTOR_2                                         0x02U   /**< Option to indicate Select EF under current DF. Fid = EF id. */
#define PHAL_MFDFEVX_SELECTOR_3                                         0x03U   /**< Option to indicate Select parent DF of the current DF. */
#define PHAL_MFDFEVX_SELECTOR_4                                         0x04U   /**< Option to indicate Selection by DF Name. DFName and len is then valid. */
/*@}*/

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_ISO7816 Commands_ISO7816
 * @}
 */



/* MIFARE DESFire EVx Miscellaneous functions. ------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_Miscellaneous Commands_Miscellaneous
 * \brief These Components implement the MIFARE DESFire EVx Miscellaneous functions. These are not part of actual DESFire EVx data sheet
 * rather its for internal purpose.
 * @{
 */

/**
* \name The configuration to be used for SetConfig / GetConfig. 
*/
/*@{*/
#define PHAL_MFDFEVX_ADDITIONAL_INFO                                    0x00A1  /**< Option for Getconfig/SetConfig to get/set additional info of a generic error or some some length exposed by interfaces. */
#define PHAL_MFDFEVX_WRAPPED_MODE                                       0x00A2  /**< Option for GetConfig/SetConfig to get/set current status of command wrapping in ISO 7816-4 APDUs. */
#define PHAL_MFDFEVX_SHORT_LENGTH_APDU                                  0x00A3  /**< Option for Getconfig/SetConfig to get/set current status of Short Length APDU wrapping in ISO 7816-4 APDUs. */
/*@}*/

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

/**
* \name The options to be used for GenerateDAMMAC. 
*/
/*@{*/
#define PHAL_MFDFEVX_GENERATE_DAMMAC_CREATE_APPLICATION                 0x00u    /**< Option to indicate the DAMMAC generation is for \ref phalMfdfEVx_CreateDelegatedApplication command. */
#define PHAL_MFDFEVX_GENERATE_DAMMAC_DELETE_APPLICATION                 0x80u    /**< Option to indicate the DAMMAC generation is for \ref phalMfdfEVx_DeleteApplication command. */
/*@}*/

/**
* \name Options to diversify the key. 
*/
/*@{*/
#define PHAL_MFDFEVX_DIVERSIFICATION_OFF                                0xFFFFU /**< Option to disable key diversification. */
#define PHAL_MFDFEVX_DIVERSIFICATION_ON                                 0x0000U /**< Option to enable key diversification. */
/*@}*/

/**
* \name Options for SDM information. 
*/
/*@{*/
#define PHAL_MFDFEVX_VCUID_PRESENT                                      0x80U   /**< Only VCUID is consider for SDM Session key calculation */
#define PHAL_MFDFEVX_RDCTR_PRESENT                                      0x40U   /**< Only RDCTR  is consider for SDM Session key calculation */
/*@}*/

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_Miscellaneous Commands_Miscellaneous
 * @}
 */

/**
 * end of group phalMfdfEVx MIFARE DESFire EVx
 * @}
 */
#endif /* NXPBUILD__PHAL_MFDFEVx */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHAL_MFDFEVX_SW

/**
 * \addtogroup phalMfdfEVx_Sw Component : Software
 * \ingroup phalMfdfEVx
 * \brief Software implementation of the MIFARE DESFire EVx commands 
 * @{
 */

/** \brief Data structure for MIFARE DESFire EVx Software layer implementation  */
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                                               /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams;                                                /**< Pointer to the parameter structure of the palMifare component. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                                                 /**< Pointer to the parameter structure of the KeyStore layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsEnc;                                                /**< Pointer to the parameter structure of the Crypto layer for encryption. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsMac;                                                /**< Pointer to the parameter structure of the CryptoMAC. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams;                                                /**< Pointer to the parameter structure of the CryptoRng layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;                                                      /**< Pointer to the HAL parameters structure. */
    VAR(uint8, ANFCRL_VAR) bSesAuthENCKey[24];                                                 /**< Session key for this authentication */
    VAR(uint8, ANFCRL_VAR) bKeyNo;                                                             /**< Key number against which this authentication is done */
    VAR(uint8, ANFCRL_VAR) bIv[16];                                                            /**< Max size of IV can be 16 bytes */
    VAR(uint8, ANFCRL_VAR) bAuthMode;                                                          /**< Authenticate (0x0A), AuthISO (0x1A), AuthAES (0xAA) */
    VAR(uint8, ANFCRL_VAR) bCmdCode;                                                           /**< Command code. This will be used for differentiating the command error codes between different commands. */
    VAR(uint8, ANFCRL_VAR) pAid[3];                                                            /**< Aid of the currently selected application */
    VAR(uint8, ANFCRL_VAR) bCryptoMethod;                                                      /**< DES,3DES, 3K3DES or AES */
    VAR(uint8, ANFCRL_VAR) bWrappedMode;                                                       /**< Wrapped APDU mode. All native commands need to be sent wrapped in ISO 7816 APDUs. */
    VAR(uint16, ANFCRL_VAR) wCrc;                                                              /**< 2 Byte CRC initial value in Authenticate mode. */
    VAR(uint32, ANFCRL_VAR) dwCrc;                                                             /**< 4 Byte CRC initial value in 0x1A, 0xAA mode. */
    VAR(uint16, ANFCRL_VAR) wAdditionalInfo;                                                   /**< Specific error codes for Desfire generic errors or To get the response length of some commands. */
    VAR(uint32, ANFCRL_VAR) dwPayLoadLen;                                                      /**< Amount of data to be read. Required for Enc read to verify CRC. */
    VAR(uint16, ANFCRL_VAR) wCmdCtr ;                                                          /**< Command count within transaction. */
    VAR(uint8, ANFCRL_VAR) bTi[PHAL_MFDFEVX_SIZE_TI];                                          /**< Transaction Identifier. */
    VAR(uint8, ANFCRL_VAR) bSesAuthMACKey[16];                                                 /**< Authentication MAC key for the session. */
    VAR(uint8, ANFCRL_VAR) pUnprocByteBuff[PHAL_MFDFEVX_SIZE_MAC];                             /**< Buffer containing unprocessed bytes for read mac answer stream. */
    VAR(uint8, ANFCRL_VAR) bNoUnprocBytes;                                                     /**< Amount of data in the pUnprocByteBuff. */
    VAR(uint8, ANFCRL_VAR) bLastBlockBuffer[16];                                               /**< Buffer to store last Block of encrypted data in case of chaining. */
    VAR(uint8, ANFCRL_VAR) bLastBlockIndex;                                                    /**< Last Block Buffer Index. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pTMIDataParams;                                                      /**< Pointer to the parameter structure for collecting TMI. */
    VAR(uint8, ANFCRL_VAR) bShortLenApdu;                                                      /**< Parameter for force set Short Length APDU in case of BIG ISO read. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pVCADataParams;                                                      /**< Pointer to the parameter structure for Virtual Card. */
    VAR(uint8, ANFCRL_VAR) bUid[15];                                                           /**< Complete UID of the PICC. \cond !PUBLIC This will be updated when phalMfdfEVx_GetCardUID interface is called. \endcond */
    VAR(uint8, ANFCRL_VAR) bUidLength;                                                         /**< Length of bytes available in bUid buffer. */
    VAR(uint8, ANFCRL_VAR) bSDMStatus;                                                         /**< Get / Set the SDM availability in the file. */
    VAR(uint8, ANFCRL_VAR) bMfdfEVxSwState;                                                    /**< State of functions in MfdfEVx component */
    VAR(uint8, ANFCRL_VAR) bMfdfEVxSwIsoState;                                                    /**< State of phalMfdfEVx_Sw_IsoAuthenticate function */
} phalMfdfEVx_Sw_DataParams_t;

/**
 * end of group phalMfdfEVx_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_MFDFEVX_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHAL_MFDFEVX_SW

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
 * \addtogroup phalMfdfEVx_Sw Component : Software
 * \ingroup phalMfdfEVx
 * \brief Software implementation of the MIFARE DESFire EVx commands 
 * @{
 */

/**
 * \brief Initialization API for MIFARE DESFire EVx software component.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Init(
        P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                              /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                                             /**< [In] Specifies the size of the data parameter structure */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,                                            /**< [In] Pointer to a palMifare component context. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,                                             /**< [In] Pointer to Key Store data parameters. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsEnc,                                            /**< [In] Pointer to a Crypto component context for encryption. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsMac,                                            /**< [In] Pointer to a CryptoMAC component context. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,                                            /**< [In] Pointer to a CryptoRng component context. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pTMIDataParams,                                                  /**< [In] Pointer to a TMI component. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pVCADataParams,                                                  /**< [In] Pointer to a VCA component. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                                                   /**< [In] Pointer to the HAL parameters structure. */
    );

/**
 * \brief Assign the dataparams of VCA AL for VCA / PC command executions.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_SetVCAParams(
        P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                              /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlVCADataParams                                                 /**< [In] Pointer to VCA AL parameter structure. */
    );

/**
 * end of group phalMfdfEVx_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PHAL_MFDFEVX

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/** 
 * \addtogroup phalMfdfEVx MIFARE DESFire EVx
 * \ingroup phal
 * \brief These Functions implement the MIFARE DESFire EVx commands.
 * @{
 */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/* MIFARE DESFire EVx secure messaging related commands. ------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_SecureMessaging Commands_SecureMessaging
 * \brief These Components implement the MIFARE DESFire EVx Secure Messaging related commands.
 * @{
 */

/**
 * \brief Performs an Authentication with the specified key number. This command supports the backward compatible D40 authentication.
 * The command can be used with DES and 2K3DES keys and performs DESFire4 native authentication.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Authenticate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR | #PHAL_MFDFEVX_DIV_OPTION_2K3DES_HALF
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR | #PHAL_MFDFEVX_DIV_OPTION_2K3DES_FULL
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_CMAC
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version in the key store of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen                                                         /**< [In] Length of diversification input max 31B. */
    );

/**
 * \brief Performs an DES Authentication in ISO CBS send mode. The command can be used with DES,3DES and 3K3DES keys.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateISO(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR | #PHAL_MFDFEVX_DIV_OPTION_2K3DES_HALF
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR | #PHAL_MFDFEVX_DIV_OPTION_2K3DES_FULL
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_CMAC
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version in the key store of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen                                                         /**< [In] Length of diversification input max 31B. */
    );

/**
 * \brief Performs an AES Authentication. The command should be used with AES128 keys.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateAES(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_CMAC
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version in the key store of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen                                                         /**< [In] Length of diversification input max 31B. */
    );

/**
 * \brief Performs an Ev2 First or Non First Authentication depending upon bFirstAuth Parameter. This will be using the AES128 keys and will
 * generate and verify the contents based on generic AES algorithm.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticateEv2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFirstAuth,                                                     /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_AUTH_FIRST
                                                                                 *          \arg #PHAL_MFDFEVX_AUTH_NONFIRST
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_ENCR
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_CMAC
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version in the key store of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen,                                                        /**< [In] Length of diversification input max 31B. */
        VAR(uint8, ANFCRL_VAR) bLenPcdCapsIn,                                                  /**< [In] Length of PcdCapsIn. Always zero for NonFirst authentication. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPcdCapsIn,                                                    /**< [In] PCD Capabilities. Upto 6 bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPcdCapsOut,                                                   /**< [Out] PCD Capabilities. 6 bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bPdCapsOut                                                     /**< [Out] PD Capabilities. 6 bytes. */
    );

/**
 * end of group phalMfdfEVx_SecureMessaging Commands_SecureMessaging
 * @}
 */
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Memory and Configuration management commands. ------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_MemoryConfiguration Commands_MemoryConfiguration
 * \brief These Components implement the MIFARE DESFire EVx Memory and Configuration Management related commands.
 * @{
 */

/**
 * \brief Returns free memory available on the PICC
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_FreeMem(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMemInfo                                                      /**< [Out] Current free memory available. Will be of 3 bytes with LSB first. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Releases the PICC user memory
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Format(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                       /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Configures the card and pre personalized the card with a key, defines if the UID or the random ID is sent back
 * during communication setup and configures the ATS string.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetConfiguration(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                      /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Configuration Option.
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION0
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION1
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION2
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION3
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION4
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION5
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTION6
                                                                                 *          \arg #PHAL_MFDFEVX_SET_CONFIG_OPTIONC
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Data for the option specified.*/
        VAR(uint8, ANFCRL_VAR) bDataLen                                                        /**< [In] Length of bytes available in Data buffer. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * \brief Returns manufacturing related data of the PICC. Call \ref phalMfdfEVx_GetConfig with #PHAL_MFDFEVX_ADDITIONAL_INFO
 * to the get the length of bytes available in VerInfo buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetVersion(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVerInfo                                                      /**< [Out] The version information of the product. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA

/**
 * \brief Returns the Unique ID of the PICC. Call \ref phalMfdfEVx_GetConfig with #PHAL_MFDFEVX_ADDITIONAL_INFO
 * to the get the length of bytes available in Uid buffer.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetCardUID(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bExchangeOption,                                                /**< [In] Flag to indicate whether the parameter information
                                                                                 *        bOption to be exchanged to PICC or not.
                                                                                 *          \arg PHAL_MFDFEVX_GET_CARD_UID_EXCHANGE_OPTION_OFF
                                                                                 *          \arg PHAL_MFDFEVX_GET_CARD_UID_EXCHANGE_OPTION_ON
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] One of the below options.
                                                                                 *          \arg PHAL_MFDFEVX_GET_CARD_UID_OPTION_NUID_NOT_RETURNED
                                                                                 *          \arg PHAL_MFDFEVX_GET_CARD_UID_OPTION_NUID_RETURNED
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                                                          /**< [Out] The complete UID of the PICC. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_MemoryConfiguration Commands_MemoryConfiguration
 * @}
 */




/* MIFARE DESFire EVx Key management commands. ---------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_KeyManagement Commands_KeyManagement
 * \brief These Components implement the MIFARE DESFire EVx Key Management related commands.
 * @{
 */

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA


/**
 * \brief Changes any key on the PICC
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKey(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY_ONERND
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY_ONERND
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY |
                                                                                 *               #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY |
                                                                                 *               #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY_ONERND | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY_ONERND
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wOldKeyNo,                                                     /**< [In] Old key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wOldKeyVer,                                                    /**< [In] Old key version in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wNewKeyNo,                                                     /**< [In] New key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wNewKeyVer,                                                    /**< [In] New key version in keystore of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen                                                         /**< [In] Length of diversification input max 31B. */
    );

/**
 * \brief Changes any key present in key set on the PICC
 *
 * \remarks
 * The key on the PICC is changed to the new key.
 * The key type of the application keys cannot be changed. The key type of only the PICC master key
 * can be changed. The keys changeable are PICCDAMAuthKey, PICCDAMMACKey, PICCDAMEncKey, VCConfigurationKey,
 * SelectVCKey, VCProximityKey, VCPollingEncKey, VCPollingMACKey.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKeyEv2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY_ONERND
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY_ONERND
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY |
                                                                                 *               #PHAL_MFDFEVX_CHGKEY_DIV_METHOD_CMAC
                                                                                 *          \arg #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY |
                                                                                 *               #PHAL_MFDFEVX_CHGKEY_DIV_NEW_KEY_ONERND | #PHAL_MFDFEVX_CHGKEY_DIV_OLD_KEY_ONERND
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wOldKeyNo,                                                     /**< [In] Old key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wOldKeyVer,                                                    /**< [In] Old key version in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wNewKeyNo,                                                     /**< [In] New key number in keystore of software or SAM. */
        VAR(uint16, ANFCRL_VAR) wNewKeyVer,                                                    /**< [In] New key version in keystore of software or SAM. */
        VAR(uint8, ANFCRL_VAR) bKeySetNo,                                                      /**< [In] Key set number within targeted application. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivLen                                                         /**< [In] Length of diversification input max 31B. */
    );

/**
 * \brief Initializes KeySet with bKeySetNo specified with type of the key set bKeyType
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_InitializeKeySet(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bKeySetNo,                                                      /**< [In] Key set number within targeted application.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeyType                                                        /**< [In] One of the below mentioned options.
                                                                                 *          \arg #PHAL_MFDFEVX_KEY_TYPE_2K3DES
                                                                                 *          \arg #PHAL_MFDFEVX_KEY_TYPE_3K3DES
                                                                                 *          \arg #PHAL_MFDFEVX_KEY_TYPE_AES128
                                                                                 */
    );

/**
 * \brief Finalize KeySet targeted by bKeySetNo by setting the key set version to the bKeySetVersion
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_FinalizeKeySet(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bKeySetNo,                                                      /**< [In] Key set number within targeted application.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeySetVersion                                                  /**< [In] KeySet version of the key set to be finalized. */
    );

/**
 * \brief RollKeySet changes the ActiveKeySet to key set currently targeted with bKeySetNumber
 *
 * \remarks
 * After successful execution of this command the keys of new AKS can be used any active authentication is lost
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE)  phalMfdfEVx_RollKeySet(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bKeySetNo                                                       /**< [In] Key set number within targeted application.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * \brief Gets information on the PICC and application master key settings.
 *
 * \remarks
 * In addition it returns the maximum number of keys which are configured for the selected application.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetKeySettings(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySettings,                                                 /**< [Out] Returns the key settings. Can be 2 or 3 bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRespLen                                                      /**< [Out] Length bytes available in KeySettings buffer. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Changes the master key settings on PICC and application level.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeKeySettings(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bKeySettings                                                    /**< [In] New key settings to be updated. */
    );

/**
 * \brief Reads out the current key version of any key stored on the PICC
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetKeyVersion(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bKeyNo,                                                         /**< [In] Key number of the targeted key. ORed with one of the below options
                                                                                 *          \arg #PHAL_MFDFEVX_SAI
                                                                                 *          \arg #PHAL_MFDFEVX_KEYSETNO_NOT_PRESENT
                                                                                 *          \arg #PHAL_MFDFEVX_KEYSETNO_PRESENT
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeySetNo,                                                      /**< [In] Key set number. ORed with one of the below options
                                                                                 *          \arg #PHAL_MFDFEVX_RETRIVE_KEY_VERSION
                                                                                 *          \arg #PHAL_MFDFEVX_RETRIVE_KEY_SET_VERSION
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion,                                                  /**< [Out] Key set versions of the selected application ordered by ascending
                                                                                 *         key set number, i.e. starting with the AKS.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRxLen                                                        /**< [Out] Length of bytes available in KeyVersion buffer. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_KeyManagement Commands_KeyManagement
 * @}
 */




/* MIFARE DESFire EVx Application management commands. -------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_AppManagement Commands_ApplicationManagement
 * \brief These Components implement the MIFARE DESFire EVx Application Management related commands.
 * @{
 */

/**
 * \brief Creates new applications on the PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateApplication(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_DF_NAME_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_DF_NAME_AVAILABLE
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,                                                         /**< [In] The application identifier to be used. Will be of 3 bytes with LSB first.
                                                                                 *          \c If application 01 need to be created then the Aid will be 01 00 00.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeySettings1,                                                  /**< [In] Application Key settings. */
        VAR(uint8, ANFCRL_VAR) bKeySettings2,                                                  /**< [In] Additional key settings.  */
        VAR(uint8, ANFCRL_VAR) bKeySettings3,                                                  /**< [In] Additional key settings.  */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues,                                                /**< [In] The Key set values for the application. Should as mentioned below.\n
                                                                                 *          \c Byte0 = AKS ver\n
                                                                                 *          \c Byte1 = Number of Key sets\n
                                                                                 *          \c Byte2 = MaxKey size\n
                                                                                 *          \c Byte3 = Application KeySet Settings.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,                                                   /**< [In] ISO DF Name to be used. Will be 16 bytes and can also be NULL based on the option. */
        VAR(uint8, ANFCRL_VAR) bISODFNameLen                                                   /**< [In] Length of bytes available in ISODFName buffer. */
    );

/**
 * \brief Permanently deletes the applications on the PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DeleteApplication(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid                                                          /**< [In] The application identifier to be used. Will be of 3 bytes with LSB first. \n
                                                                                 *          \c If application 01 need to be deleted then the Aid will be 01 00 00.
                                                                                 */
        , P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC,                                                    /**< [In] [Optional, present if PICCDAMAuthKey or NXPDAMAuthKey is used for authentication]
                                                                                 *        The MAC calculated by the card issuer to allow delegated application deletion.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bDAMMAC_Len                                                     /**< [In] Length of bytes available in DAMMAC buffer. */
    );

/**
 * \brief Creates new Delegated application
 * For delegated application creation, the PICC level (AID 0x000000) must have been selected.
 * An active authentication with the PICCDAMAuthKey is required.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateDelegatedApplication(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_DF_NAME_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_DF_NAME_AVAILABLE
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,                                                         /**< [In] The application identifier to be used. Will be of 3 bytes with LSB first.
                                                                                 *          \c If application 01 need to be created then the Aid will be 01 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams,                                                   /**< [In] The DAM information. Should as mentioned below.\n
                                                                                 *          \c Byte0 = DAM Slot No [LSB]\n
                                                                                 *          \c Byte1 = DAM Slot No [MSB]\n
                                                                                 *          \c Byte2 = DAM Slot Version\n
                                                                                 *          \c Byte3 = Quota Limit [LSB]\n
                                                                                 *          \c Byte4 = Quota Limit [MSB]
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeySettings1,                                                  /**< [In] Application Key settings. */
        VAR(uint8, ANFCRL_VAR) bKeySettings2,                                                  /**< [In] Additional key settings.  */
        VAR(uint8, ANFCRL_VAR) bKeySettings3,                                                  /**< [In] Additional key settings.  */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues,                                                /**< [In] The Key set values for the application. Should as mentioned below.\n
                                                                                 *          \c Byte0 = AKS ver\n
                                                                                 *          \c Byte1 = Number of Key sets\n
                                                                                 *          \c Byte2 = MaxKey size\n
                                                                                 *          \c Byte3 = Application KeySet Settings.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,                                                   /**< [In] ISO DF Name to be used. Will be 16 bytes and can also be NULL based on the option. */
        VAR(uint8, ANFCRL_VAR) bISODFNameLen,                                                  /**< [In] Length of bytes available in ISODFName buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK,                                                        /**< [In] Encrypted initial application key. 32 bytes long. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC                                                       /**< [In] 8 byte DAM MAC. */
    );

/**
 * \brief Selects one particular application on the PICC for further access.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SelectApplication(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_SELECT_PRIMARY_APP
                                                                                 *          \arg #PHAL_MFDFEVX_SELECT_SECOND_APP
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,                                                         /**< [In] The primary application identifier to be used. Will be of 3 bytes with LSB first.
                                                                                 *          \c If application 01 need to be selected then the Aid will be 01 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid2                                                         /**< [In] The secondary application identifier to be used. Will be of 3 bytes with LSB first.
                                                                                 *          \c If application 01 need to be selected then the Aid will be 01 00 00.
                                                                                 */
    );

/**
 * \brief Returns application identifiers of all applications on the PICC
 *
 * \remarks
 * This response will be #PH_ERR_SUCCESS if all the application ids can be obtained in one call.
 * If not, then #PH_ERR_SUCCESS_CHAINING is returned. The user has to call this function with
 * bOption = #PH_EXCHANGE_RXCHAINING to get the remaining AIDs.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_SUCCESS_CHAINING Operation successful with chaining.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetApplicationIDs(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] One of the below options.
                                                                                 *          \arg #PH_EXCHANGE_DEFAULT
                                                                                 *          \arg #PH_EXCHANGE_RXCHAINING
                                                                                 */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAidBuff,                                                    /**< [Out] The available identifiers of the application(s). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumAIDs                                                       /**< [Out] The number of available application(s). */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Returns the Dedicated File(DF) names
 *
 * \remarks
 * The pDFBuffer will be filled with 3 byte AID + 2 byte ISO Fid + 1 - 16 bytes DF Name at a time.
 * If there are more DFs, then status PH_ERR_SUCCESS_CHAINING is returned.
 * The caller should call this again with bOption = PH_EXCHANGE_RXCHAINING.
 *
 * CAUTION: This should not be called with AES or ISO authentication DOING SO WILL DAMAGE THE DESFIRE Card
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_SUCCESS_CHAINING More DF Names to be returned
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetDFNames(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] One of the below options.
                                                                                 *          \arg #PH_EXCHANGE_DEFAULT
                                                                                 *          \arg #PH_EXCHANGE_RXCHAINING
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFBuffer,                                                    /**< [Out] The ISO information about the application. At a time the information of one application
                                                                                 *         will be returned. The buffer should be 21 (3 + 2 + 16) bytes long.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFInfoLen                                                    /**< [Out] Length of bytes available in DFBuffer buffer. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * \brief Parameters associated with the delegated application can be retrieved using this command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetDelegatedInfo(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMSlot,                                                     /**< [In] Slot number associated with the memory space of the targeted
                                                                                 *        delegated application. LSB first.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamSlotVer,                                                  /**< [Out] Slot version associated with the memory space of the targeted
                                                                                 *         delegated application.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pQuotaLimit,                                                  /**< [Out] Maximal memory consumption of the targeted delegated application
                                                                                 *         (in 32-byte blocks).
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFreeBlocks,                                                  /**< [Out] Amount of unallocated memory of the targeted delegated application
                                                                                 *         (in 32-byte blocks).
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid                                                          /**< [Out] Application Identifier of the targeted DAM slot. This parameter is set to
                                                                                 *         0x000000 if the DAM slot targeted by DAMSlotNo exists on the card, but is
                                                                                 *         currently not occupied with an application, i.e. the latest application has
                                                                                 *         been deleted.
                                                                                 */
    );

/**
 * end of group phalMfdfEVx_AppManagement Commands_ApplicationManagement
 * @}
 */




/* MIFARE DESFire EVx File management commands. --------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_FileManagement Commands_FileManagement
 * \brief These Components implement the MIFARE DESFire EVx File Management related commands.
 * @{
 */

/**
 * \brief Creates files for the storage of plain unformatted user data within an existing application
 * on the PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateStdDataFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        VAR(uint8, ANFCRL_VAR) bFileOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MFC_MAPPING_ENABLED
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_SDM_MIRRORING_ENABLED
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize                                                     /**< [In] The size of the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the FileSize will be 10 00 00.
                                                                                 */
    );

/**
 * \brief Creates files for the storage of plain unformatted user data within an existing application
 * on the PICC, additionally supporting the feature of an integrated backup
 * mechanism.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateBackupDataFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        VAR(uint8, ANFCRL_VAR) bFileOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MFC_MAPPING_ENABLED
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize                                                     /**< [In] The size of the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the FileSize will be 10 00 00.
                                                                                 */
    );


/**
 * \brief Creates files for the storage and manipulation of 32bit signed integer values within
 * an existing application on the PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateValueFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bCommSett,                                                      /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MFC_MAPPING_ENABLED
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLowerLmit,                                                   /**< [In] The lower limit for the file. Will be of 4 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the value will be 10 00 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUpperLmit,                                                   /**< [In] The upper limit for the file. Will be of 4 bytes with LSB first.
                                                                                 *          \c If size 0x20 need to be created then the value will be 20 00 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue,                                                       /**< [In] The initial value. Will be of 4 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the value will be 10 00 00 00.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bLimitedCredit                                                  /**< [In] One of the below values.
                                                                                 *          \arg #PHAL_MFDFEVX_ENABLE_LIMITEDCREDIT
                                                                                 *          \arg #PHAL_MFDFEVX_ENABLE_FREE_GETVALUE
                                                                                 */
    );

/**
 * \brief Creates files for multiple storage of structural similar data, for example for loyalty programs within an existing application.
 * Once the file is filled, further writing is not possible unless it is cleared.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateLinearRecordFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        VAR(uint8, ANFCRL_VAR) bCommSett,                                                      /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize,                                                  /**< [In] The size of the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the RecordSize will be 10 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec                                                   /**< [In] The maximum number of record in the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x04 need to be created then the value will be 04 00 00.
                                                                                 */
    );

/**
 * \brief Creates files for multiple storage of structural similar data, for example for logging transactions, within an existing application.
 * Once the file is filled, the PICC automatically over writes the oldest record with the latest written one.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateCyclicRecordFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        VAR(uint8, ANFCRL_VAR) bCommSett,                                                      /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize,                                                  /**< [In] The size of the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x10 need to be created then the RecordSize will be 10 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec                                                   /**< [In] The maximum number of record in the file. Will be of 3 bytes with LSB first.
                                                                                 *          \c If size 0x04 need to be created then the value will be 04 00 00.
                                                                                 */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Creates a Transaction MAC File and enables the Transaction MAC feature for the targeted application.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateTransactionMacFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options. Only applicable for SAM S / X component
                                                                                 *          \arg #PHAL_MFDFEVX_CREATE_TMAC_FILE_DIV_OFF
                                                                                 *          \arg #PHAL_MFDFEVX_CREATE_TMAC_FILE_DIV_ON
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bCommSett,                                                      /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number in SAM keystore. For software is not applicable. */
        VAR(uint8, ANFCRL_VAR) bKeyType,                                                       /**< [In] The TMKeyOption and should be always #PHAL_MFDFEVX_KEY_TYPE_AES128. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bTMKey,                                                       /**< [In] The 16 byte key value to be stored in the PICC. This is applicable for Software only. */
        VAR(uint8, ANFCRL_VAR) bTMKeyVer,                                                      /**< [In] The version for the key to be stored in the PICC. This is applicable for Software and SAM. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input. Can be NULL. */
        VAR(uint8, ANFCRL_VAR) bDivInputLength                                                 /**< [In] Length of diversification input max 31B. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * \brief Permanently deactivates a file within the file directory of the currently selected application.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DeleteFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFileNo                                                         /**< [In] The file number to be deleted.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
    );

/**
 * \brief Returns the file IDs of all active files within the currently selected application.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileIDs(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,                                                         /**< [Out] The buffer containing the available file ID(s). Buffer should be 32 bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bNumFid                                                       /**< [Out] The length of bytes available in Fid buffer. */
    );

/**
 * \brief Get the ISO File IDs.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetISOFileIDs(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFidBuffer,                                                   /**< [Out] The buffer containing the available ISO file ID(s). Buffer should be 64 bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumFid                                                       /**< [Out] The number of ISO File ID's read. */
    );

/**
 * \brief Get information on the properties of a specific file
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileSettings(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number for which the setting to be retrieved.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFSBuffer,                                                    /**< [Out] The buffer containing the settings. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bBufferLen                                                    /**< [Out] The length of bytes available in FSBuffer buffer. */
    );

/**
 * \brief Get file related counters used for Secure Dynamic Messaging.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetFileCounters(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Indicates the mode of communication to be used while exchanging the data to PICC.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] File number for which the Counter information need to be received. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileCounters,                                                /**< [Out] The SDMReadCounter information returned by the PICC. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLen                                                        /**< [Out] Length of bytes available in FileCounters buffer. */
    );

/**
 * \brief Changes the access parameters of an existing file.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ChangeFileSettings(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Indicates the mode of communication to be used while exchanging the data to PICC.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below flags if required.
                                                                                 *          \arg #PHAL_MFDFEVX_EXCHANGE_ADD_INFO_BUFFER_COMPLETE
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] File number for which the setting need to be updated.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileOption,                                                    /**< [In] New communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ENC
                                                                                 *        \n
                                                                                 *        Ored with one of the below flags if required.
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_SDM_MIRRORING_ENABLED
                                                                                 *          \arg #PHAL_MFDFEVX_FILE_OPTION_TMCLIMIT_PRESENT
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,                                                /**< [In] The new access right to be applied for the file. Should be 2 byte. */
        VAR(uint8, ANFCRL_VAR) bAddInfoLen,                                                    /**< [In] Complete length consisting of\n
                                                                                 *          - If bOption is not having #PHAL_MFDFEVX_EXCHANGE_ADD_INFO_BUFFER_COMPLETE set\n
                                                                                 *              - Additional Access Rights if bFileOption & #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT\n
                                                                                 *              - TMC Limit                if bFileOption & #PHAL_MFDFEVX_FILE_OPTION_TMCLIMIT_PRESENT\n
                                                                                 *                  - If TMCLimit and AddARs is not available, bAddInfoLen = 0\n
                                                                                 *                  - If AddARs is not available,              bAddInfoLen = 4\n
                                                                                 *                  - If TMCLimit is not available,            bAddInfoLen = 0 - 7\n
                                                                                 *                  - If TMCLimit and AddARs is available,     bAddInfoLen = ( ( 0 - 7 ) + 4 )
                                                                                 *
                                                                                 *          - If bOption is having #PHAL_MFDFEVX_EXCHANGE_ADD_INFO_BUFFER_COMPLETE set, where N is SDM information\n
                                                                                 *              - Additional Access Rights if bFileOption & #PHAL_MFDFEVX_FILE_OPTION_ADDITIONAL_AR_PRESENT\n
                                                                                 *              - SDM Information          if bFileOption & #PHAL_MFDFEVX_FILE_OPTION_SDM_MIRRORING_ENABLED\n
                                                                                 *              - TMC Limit                if bFileOption & #PHAL_MFDFEVX_FILE_OPTION_TMCLIMIT_PRESENT\n
                                                                                 *                  - If all the 3 are not available,                 bAddInfoLen = 0
                                                                                 *                  - If AddARs is not available,                     bAddInfoLen = N + 4\n
                                                                                 *                  - If TMCLimit is not available,                   bAddInfoLen = ( ( 0 - 7 ) * 2 ) + N\n
                                                                                 *                  - If SDM is not available,                        bAddInfoLen = ( ( 0 - 7 ) * 2 ) + 4\n
                                                                                 *                  - If all the 3 are available,                     bAddInfoLen = ( ( ( 0 - 7 ) * 2 ) + N + 4)
                                                                                 *
                                                                                 *
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddInfo                                                      /**< [In] Buffer should contain the following information. \n
                                                                                 *          \c [Additional access rights] || [SDMOption || SDM AccessRights || VCUIDOffset ||
                                                                                 *             SDMReadCtrOffset || PICCDataOffset || SDMACInputOffset || SDMENCOffset ||
                                                                                 *             SDMENCLength || SDMMACOffset] || [TMCLimit]
                                                                                 */
    );

/**
 * end of group phalMfdfEVx_FileManagement Commands_FileManagement
 * @}
 */




/* MIFARE DESFire EVx Data management commands. --------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_DataManagement Commands_DataManagement
 * \brief These Components implement the MIFARE DESFire EVx Data Management related commands.
 * @{
 */

/**
* \name Chaining format to be used for DataManagement commands. 
*/
/*@{*/
#define PHAL_MFDFEVX_APPLICATION_CHAINING                               0x00U   /**< Option to represent the application chaining format.
                                                                                 *   Here AF will be available in command and response.
                                                                                 */
#define PHAL_MFDFEVX_ISO_CHAINING                                       0x01U   /**< Option to represent the ISO14443-4 chaining format.
                                                                                 *   Here AF will not be available in command and response rather
                                                                                 *   the chaining will be done using the ISO14443-4 protocol.
                                                                                 */
/*@}*/

/**
 * \brief Reads data from standard data files or backup data files
 *
 * \remarks
 * Chaining upto the size of the HAL Rx buffer is handled within this function. If more data is to be read, the user has to call
 * this function again with bOption = #PH_EXCHANGE_RXCHAINING | [one of the communication options]
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_SUCCESS_CHAINING indicating more data to be read.
 * \retval Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadData(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 *
                                                                                 *          \c #PH_EXCHANGE_RXCHAINING: To be Or'd with the above option
                                                                                 *              flag if Chaining status is returned.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_APPLICATION_CHAINING
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_CHAINING
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number from where the data to be read.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,                                                      /**< [In] The offset from where the data should be read. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 need to be offset then it will be 10 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLength,                                                      /**< [In] The number of bytes to be read. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be read then it will be 10 00 00. \n
                                                                                 *          \c If complete file need to be read then it will be 00 00 00.
                                                                                 */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata,                                                    /**< [Out] The data returned by the PICC. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen                                                   /**< [Out] Length of bytes available in RxData buffer. */
    );

/**
 * \brief Writes data to standard data files or backup data files
 *
 * \remarks
 * Implements chaining to the card.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_WriteData(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_APPLICATION_CHAINING
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_CHAINING
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the data to be written.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,                                                      /**< [In] The offset from where the data should be written. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 need to be offset then it will be 10 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,                                                      /**< [In] The data to be written to the PICC. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen                                                    /**< [In] The number of bytes to be written. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be written then it will be 10 00 00.
                                                                                 */
    );

/**
 * \brief Reads the currently stored value from value files.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetValue(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number for which the value to the retrieved.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                        /**< [Out] The value returned by the PICC. The buffer should be 4 bytes. */
    );

/**
 * \brief Increases a value stored in a Value File
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Credit(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the value should be credited.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                        /**< [Out] The value to be credited. Will be of 4 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be credited then it will be 10 00 00 00.
                                                                                 */
    );

/**
 * \brief Decreases a value stored in a Value File
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Debit(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the value should be debited.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                        /**< [Out] The value to be debited. Will be of 4 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be debited then it will be 10 00 00 00.
                                                                                 */
    );

/**
 * \brief Allows a limited increase of a value stored in a Value File without having full credit permissions to the file.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_LimitedCredit(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the value should be credited.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                        /**< [Out] The value to be credited. Will be of 4 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be credited then it will be 10 00 00 00.
                                                                                 */
    );

/**
 * \brief Reads out a set of complete records from a Cyclic or Linear Record File.
 *
 * \remarks
 * The read records command reads and stores data in the rxbuffer upto the rxbuffer size before returning
 * to the user. The rxbuffer is configured during the HAL init and this is specified by the user.
 *
 * Chaining upto the size of the HAL Rx buffer is handled within this function.
 * If more data is to be read, the user has to call this function again with
 * bCommOption = #PH_EXCHANGE_RXCHAINING | [one of the communication options]
 *
 * If TMI collection is ON, if pRecCount is zero then pRecSize is mandatory parameter.
 * If pRecSize and RecCount are zero and TMI collection is ON, then #PH_ERR_INVALID_PARAMETER error returned.
 * If TMI collection is ON; and if wrong pRecSize is provided, then wrong RecCount value will be calculated and updated for TMI collection.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_SUCCESS_CHAINING indicating more data to be read.
 * \retval Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadRecords(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 *
                                                                                 *          \c #PH_EXCHANGE_RXCHAINING: To be Or'd with the above option
                                                                                 *              flag if Chaining status is returned.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_APPLICATION_CHAINING
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_CHAINING
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number from where the data to be read.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo,                                                       /**< [In] 3 bytes LSB first. Record number of the newest record targeted, starting to count
                                                                                 *        from the latest record written.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecCount,                                                    /**< [In] 3 bytes LSB first. Number of records to be read. If 0x00 00 00, then all the records are read. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecSize,                                                     /**< [In] The number of bytes to be read. Will be of 3 bytes with LSB first. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata,                                                    /**< [Out] The data returned by the PICC. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen                                                   /**< [Out] Length of bytes available in RxData buffer. */
    );

/**
 * \brief Writes data to a record in a Cyclic or Linear Record File.
 *
 * \remarks
 * Implements chaining to the card.
 * The data provided on pData will be chained to the card by sending data upto the frame size of the DESFire PICC, at a time.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_WriteRecord(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_APPLICATION_CHAINING
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_CHAINING
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the data should be written.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,                                                      /**< [In] The offset from where the data should be written. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 need to be offset then it will be 10 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] The data to be written to the PICC. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                      /**< [In] The number of bytes to be written. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be written then it will be 10 00 00.
                                                                                 */
    );

/**
 * \brief Updates data to a record in a Cyclic or Linear Record File.
 *
 * \remarks
 * Implements chaining to the card.
 * The data provided on pData will be chained to the card by sending data upto the frame size of the DESFire PICC, at a time.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_UpdateRecord(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_APPLICATION_CHAINING
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_CHAINING
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to which the data should be written.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo,                                                       /**< [In] Record number. Records are numbered starting with the latest record written. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,                                                      /**< [In] Starting position for the update operation within the targeted record. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] The data to be written to the PICC. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen                                                      /**< [In] The number of bytes to be written. Will be of 3 bytes with LSB first.
                                                                                 *          \c If 0x10 bytes need to be written then it will be 10 00 00.
                                                                                 */
    );

/**
 * \brief Resets a Cyclic or Linear Record File.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ClearRecordFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFileNo                                                         /**< [In] The file number to be cleared.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
    );

/**
 * end of group phalMfdfEVx_DataManagement Commands_DataManagement
 * @}
 */




/* MIFARE DESFire EVx Transaction management commands. -------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_TransactionnManagement Commands_TransactionManagement
 * \brief These Components implement the MIFARE DESFire EVx Transaction Management related commands.
 * @{
 */

/**
 * \brief Validates all previous write access' on Backup Data files, value files and record files within one application.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CommitTransaction(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] One of the below options.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMIT_TXN_OPTION_NOT_EXCHANGED
                                                                                 *          \arg #PHAL_MFDFEVX_COMMIT_TXN_NO_TMC_TMV_RETURNED
                                                                                 *          \arg #PHAL_MFDFEVX_COMMIT_TXN_TMC_TMV_RETURNED
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC,                                                         /**< [Out] The increased value as stored in FileType.TransactionMAC. \n
                                                                                 *          \c 4 byte Transaction MAC counter value.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMV                                                          /**< [Out] 8 bytes Transaction MAC value. */
    );

/**
 * \brief Aborts all previous write accesses on FileType.BackupData, FileType.Value, File-Type.LinearRecord and
 * FileType.CyclicRecord files within the selected application(s). If applicable, the Transaction MAC calculation is aborted.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AbortTransaction(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Secures the transaction by committing the application to ReaderID specified
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CommitReaderID(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRI,                                                        /**< [In] 16 bytes of Transaction MAC reader ID. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI                                                      /**< [Out] 16 bytes of Encrypted Transaction MAC ReaderID of the latest successful transaction. */
    );

/**
 * end of group phalMfdfEVx_TransactionnManagement Commands_TransactionManagement
 * @}
 */




/* MIFARE DESFire EVx ISO7816-4 commands. ---------------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_ISO7816 Commands_ISO7816
 * \brief These Components implement the MIFARE DESFire EVx ISO/IEC 7816-4 Basic commands.
 * @{
 */

/**
 * \brief ISO Select. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoSelectFile(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option for return / no return of FCI.
                                                                                 *          \arg #PHAL_MFDFEVX_FCI_RETURNED
                                                                                 *          \arg #PHAL_MFDFEVX_FCI_NOT_RETURNED
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bSelector,                                                      /**< [In] The selector to be used.
                                                                                 *          \arg #PHAL_MFDFEVX_SELECTOR_0
                                                                                 *          \arg #PHAL_MFDFEVX_SELECTOR_1
                                                                                 *          \arg #PHAL_MFDFEVX_SELECTOR_2
                                                                                 *          \arg #PHAL_MFDFEVX_SELECTOR_3
                                                                                 *          \arg #PHAL_MFDFEVX_SELECTOR_4
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,                                                         /**< [In] The ISO File number to be selected. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,                                                      /**< [In] The ISO DFName to be selected. Valid only when bOption = 0x04. */
        VAR(uint8, ANFCRL_VAR) bDFnameLen,                                                     /**< [In] Length of bytes available in DF name buffer. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFCI,                                                       /**< [Out] The FCI information returned by the PICC. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen                                                     /**< [Out] Length of bytes available in FCI buffer. */
    );

/**
 * \brief ISO Read Binary. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_SUCCESS_CHAINING operation success with chaining.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoReadBinary(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PH_EXCHANGE_DEFAULT   : To exchange the initial command to the PICC.
                                                                                 *          \arg #PH_EXCHANGE_RXCHAINING: To exchange the chaining command to PICC in
                                                                                 *                                        case PICC returns AF as the status.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bOffset,                                                        /**< [In] The offset from where the data should be read. */
        VAR(uint8, ANFCRL_VAR) bSfid,                                                          /**< [In] Short ISO File Id. Bit 7 should be 1 to indicate Sfid is supplied.
                                                                                 *        Else it is treated as MSB of 2Byte offset.
                                                                                 */
        VAR(uint32, ANFCRL_VAR) dwBytesToRead,                                                 /**< [In] Number of bytes to read. If 0, then entire file to be read. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                                                  /**< [Out] The data returned by the PICC. */
        P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead                                                   /**< [Out] Length of bytes available in RxData buffer. */
    );

/**
 * \brief Iso Update Binary. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoUpdateBinary(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOffset,                                                        /**< [In] The offset from where the data should be updated. */
        VAR(uint8, ANFCRL_VAR) bSfid,                                                          /**< [In] Short ISO File Id. Bit 7 should be 1 to indicate Sfid is supplied.
                                                                                 *        Else it is treated as MSB of 2Byte offset.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Data to be updated. */
        VAR(uint32, ANFCRL_VAR) dwDataLen                                                      /**< [In] Length of bytes available in Data buffer. */
    );

/**
 * \brief Iso Read Records. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoReadRecords(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] One of the below options.
                                                                                 *          \arg #PH_EXCHANGE_DEFAULT   : To exchange the initial command to the PICC.
                                                                                 *          \arg #PH_EXCHANGE_RXCHAINING: To exchange the chaining command to PICC in
                                                                                 *                                        case PICC returns AF as the status.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bRecNo,                                                         /**< [In] Record to read / from where to read. */
        VAR(uint8, ANFCRL_VAR) bReadAllFromP1,                                                 /**< [In] Whether to read all records from P1 or just one. */
        VAR(uint8, ANFCRL_VAR) bSfid,                                                          /**< [In] Short ISO File Id. */
        VAR(uint32, ANFCRL_VAR) dwBytesToRead,                                                 /**< [In] Number of bytes to read. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                                                  /**< [Out] The data returned by the PICC. */
        P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead                                                   /**< [Out] Length of bytes available in RxData buffer. */
    );

/**
 * \brief Iso Append record. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoAppendRecord(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bSfid,                                                          /**< [In] Short ISO File Id. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Data to be appended. */
        VAR(uint32, ANFCRL_VAR) dwDataLen,                                                     /**< [In] Length of bytes available in Data buffer. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu                                                /**< [In] Flag for Extended Length APDU. */
    );

/**
 * \brief Iso Update record
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoUpdateRecord(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bIns,                                                           /**< [In] Either 0xDC or 0xDD. */
        VAR(uint8, ANFCRL_VAR) bRecNo,                                                         /**< [In] Record number. 00 indicates current record. */
        VAR(uint8, ANFCRL_VAR) bSfid,                                                          /**< [In] Short Iso File Id bits 0..4 only code this value. Either 0 or sfid. */
        VAR(uint8, ANFCRL_VAR) bRefCtrl,                                                       /**< [In] Bit 0 to bit 3 code the value based on bIns as defined in ISO 7816-4 Update Record. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,                                                        /**< [In] Data to write. */
        VAR(uint8, ANFCRL_VAR) bDataLen                                                        /**< [In] number of bytes to write. */
    );

/**
 * \brief ISOGetChallenge. This command is implemented in compliance with ISO/IEC 7816-4.
 * Returns the random number from the PICC. Size depends on the key type referred by wKeyNo and wKeyVer.
 *
 * \remarks
 * THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoGetChallenge(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number to be used form keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version to be used from key store. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        VAR(uint32, ANFCRL_VAR) dwLe,                                                          /**< [In] Length of expected challenge RPICC1. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRPICC1                                                       /**< [Out] RPICC1 returned from PICC. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Iso External Authenticate. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \remarks
 * THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoExternalAuthenticate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,                                                       /**< [In] Input data should be as mentioned below.
                                                                                 *          \c Reference to crypto algorithm - 1 Byte: 00 => context defined, 02 => 2K3DES,
                                                                                 *                                                      04 => 3k3DES, 09 => AES128 \n
                                                                                 *          \c Card master key flag - 1 Byte:  0x00 if card master key, 0x01 otherwise. \n
                                                                                 *          \c Key number on card - 1 Byte: 0x0 to 0xD \n
                                                                                 *          \c Length of random number: 1 Byte \n
                                                                                 *          \c Random number generated by PCD : 8 or 16 bytes. Not required for Sam non X mode. \n
                                                                                 *          \c Random number returned by GetChallenge command : 8 Bytes or 16 Bytes \n
                                                                                 *          \c Key number : 2 bytes \n
                                                                                 *          \c key Version: 2 bytes
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bInputLen,                                                      /**< [In] Length of bytes available in Input buffer. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,                                                     /**< [Out] Returns Rnd number PCD2 in sam non x mode. Nothing in S/W mode. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen                                                       /**< [Out] Length of data returned in pDataOut. */
    );

/**
 * \brief Iso Internal Authenticate. This command is implemented in compliance with ISO/IEC 7816-4.
 *
 * \remarks
 * THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoInternalAuthenticate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,                                                       /**< [In] Input data should be as mentioned below.
                                                                                 *          \c Reference to crypto algorithm - 1 Byte: 00 => context defined, 02 => 2K3DES,
                                                                                 *                                                      04 => 3k3DES, 09 => AES128 \n
                                                                                 *          \c Card master key flag - 1 Byte:  0x00 if card master key, 0x01 otherwise. \n
                                                                                 *          \c Key number on card - 1 Byte: 0x0 to 0xD \n
                                                                                 *          \c Length of random number: 1 Byte \n
                                                                                 *          \c Random number Rpcd2 : 8 Bytes or 16 Bytes. \n
                                                                                 *          \c Key number : 2 bytes \n
                                                                                 *          \c key Version: 2 bytes
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bInputLen,                                                      /**< [In] Length of bytes available in Input buffer. */
        VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,                                               /**< [In] Flag for Extended Length APDU. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,                                                     /**< [Out] RRPICC2 || RPCD2 after decryption in S/W mode. Nothing in Sam non x mode. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen                                                       /**< [Out] Length of data available in DataOut buffer. */
    );

/**
 * \brief Perform Iso authentication GetChallenge, External Authenticate & Internal Authenticate of a DESFire PICC
 *
 * Internally performs the three pass Iso authentication by calling
 * GetChallenge \n
 * External Authenticate \n
 * Internal Authenticate \n
 * Generates and stores the session key \n
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_IsoAuthenticate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] DESFire key number or SAM Key entry number. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] Key number on card. 0x0 to 0xD. */
        VAR(uint8, ANFCRL_VAR) bIsPICCkey                                                      /**< [In] Is it PICC Master key ? 1 = YES. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_ISO7816 Commands_ISO7816
 * @}
 */




/* MIFARE DESFire EVx Originality Check functions. ------------------------------------------------------------------------------------- */
/**
 * \defgroup phalMfdfEVx_OriginalityCheck Commands_OriginalityCheck
 * \brief These Components implement the MIFARE DESFire EVx Originality Check functions.
 * @{
 */

/**
 * \brief Performs the originality check to verify the genuineness of PICC
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ReadSign(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bAddr,                                                          /**< [In] Value is always 00. Present for forward compatibility reasons */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pSignature                                                   /**< [Out] The plain 56 bytes originality signature of the PICC. */
    );

/**
 * end of group phalMfdfEVx_OriginalityCheck Commands_OriginalityCheck
 * @}
 */




/* MIFARE DESFire EVx MIFARE Classic functions. ---------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_MFC Commands_MIFARE_ClassicSupport
 * \brief These Components implement the MIFARE DESFire EVx MIFARE Classic Support functions.
 * @{
 */

/**
 * \brief Configure a mapping between one or more MIFARE Classic blocks and a DESFire FileType.StandardData,
 * FileType.BackupData and FileType.Value file. \cond !PUBLIC To compute the MFCLicenseMAC call phalMfdfEVx_ComputeMFCLicenseMAC
 * command. \endcond
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CreateMFCMapping(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] The option to be enabled / disabled of the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_ENC
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileNo,                                                        /**< [In] The file number to be created.
                                                                                 *        ORed with #PHAL_MFDFEVX_SAI to indicate secondary application indicator.
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bFileOption,                                                    /**< [In] The option to be enabled / disabled of the file. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCBlockList,                                                /**< [In] List of block numbers of the targeted blocks. */
        VAR(uint8, ANFCRL_VAR) bMFCBlocksLen,                                                  /**< [In] Length of Bytes available in MFCBlockList buffer. */
        VAR(uint8, ANFCRL_VAR) bRestoreSource,                                                 /**< [In] File number of the allowed restore source. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense,                                                  /**< [In] MIFARE Classic License. Should be as follows
                                                                                 *          \c BlockCount || BlockNr1 || BlockOption1 [|| BlockNr2 || BlockOption2 || ...
                                                                                 *             || BlockNrN || BlockOptionN]
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bMFCLicenseLen,                                                 /**< [In] Length of Bytes available in MFCLicense buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC                                                /**< [In] The computed MFCLicenseMAC. Should be 8 bytes. */
    );

/**
 * \brief Restores the value from one FileType.Value file by transferring it into another File-Type.Value file.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_RestoreTransfer(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,                                                    /**< [In] Communication settings for the file.
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_PLAIN
                                                                                 *          \arg #PHAL_MFDFEVX_COMMUNICATION_MACD
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bTargetFileNo,                                                  /**< [In] File number of the TargetFile to be updated. */
        VAR(uint8, ANFCRL_VAR) bSourceFileNo                                                   /**< [In] File number of the SourceFile to be restored. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Configure restriction of certain update operations over the MIFARE Classic interface. To compute the MFCLicenseMAC
 * call phalMfdfEVx_ComputeMFCLicenseMAC command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_RestrictMFCUpdate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Configuration Option. Define length and content of the Data parameter. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCConfig,                                                   /**< [In] Data content depends on option values. */
        VAR(uint8, ANFCRL_VAR) bMFCConfigLen,                                                  /**< [In] Length of Bytes available in MFCConfig buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense,                                                  /**< [In] MIFARE Classic License. Should be as follows
                                                                                 *          \c BlockCount || BlockNr1 || BlockOption1 [|| BlockNr2 || BlockOption2 || ...
                                                                                 *             || BlockNrN || BlockOptionN]
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bMFCLicenseLen,                                                 /**< [In] Length of Bytes available in MFCLicense buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC                                                /**< [In] The computed MFCLicenseMAC. Should be 8 bytes. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * end of group phalMfdfEVx_MFC Commands_MIFARE_ClassicSupport
 * @}
 */




#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/* MIFARE DESFire EVx POST Delivery Configuration function. ---------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_PDC Commands_PostDeliveryConfiguration
 * \brief These Components implement the MIFARE DESFire EVx MIFARE Post Delivery configuration function.
 * @{
 */

/**
 * \brief Perform Post Delivery Authentication.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and under laying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_AuthenticatePDC(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bRfu,                                                           /**< [In] The RFU information. Its zero by default. */
        VAR(uint8, ANFCRL_VAR) bKeyNoCard,                                                     /**< [In] PICC Key number to be used for authentication. */
        VAR(uint8, ANFCRL_VAR) wKeyNo,                                                         /**< [In] Key number to used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version to used from software or hardware keystore. */
        VAR(uint8, ANFCRL_VAR) bUpgradeInfo                                                    /**< [In] The upgrade info input. */
    );

/**
 * end of group phalMfdfEVx_PDC Commands_PostDeliveryConfiguration
 * @}
 */
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Miscellaneous functions. ------------------------------------------------------------------------------------- */
/**
 * \addtogroup phalMfdfEVx_Miscellaneous Commands_Miscellaneous
 * \brief These Components implement the MIFARE DESFire EVx Miscellaneous functions. These are not part of actual DESFire EVx data sheet
 * rather its for internal purpose.
 * @{
 */

/**
 * \brief Perform a GetConfig command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GetConfig(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig,                                                       /**< [In] Configuration to read. Will be one of the below values.
                                                                                 *          \arg #PHAL_MFDFEVX_ADDITIONAL_INFO
                                                                                 *          \arg #PHAL_MFDFEVX_WRAPPED_MODE
                                                                                 *          \arg #PHAL_MFDFEVX_SHORT_LENGTH_APDU
                                                                                 */
         P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                                      /**< [Out] The value for the mentioned configuration. */
    );

/**
 * \brief Perform a SetConfig command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetConfig(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig,                                                       /**< [In] Configuration to set. Will be one of the below values.
                                                                                 *          \arg #PHAL_MFDFEVX_ADDITIONAL_INFO
                                                                                 *          \arg #PHAL_MFDFEVX_WRAPPED_MODE
                                                                                 *          \arg #PHAL_MFDFEVX_SHORT_LENGTH_APDU
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wValue                                                         /**< [In] The value for the mentioned configuration. */
    );

/**
 * \brief Reset the authentication
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ResetAuthentication(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layer's parameter structure. */
    );

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/**
 * \brief Generates Encrypted Key for Delegated application management.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c KeyNoAppDAMDefault should have AllowDumpSecretKey enabled.\n
 *  \c KeyNoDAMEnc should be off Offline_Crypto Key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMEncKey(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNoDAMEnc,                                                  /**< [In] Key number in key store of DAM Encryption key. */
        VAR(uint16, ANFCRL_VAR) wKeyVerDAMEnc,                                                 /**< [In] Key version in key store of DAM Encryption key. */
        VAR(uint16, ANFCRL_VAR) wKeyNoAppDAMDefault,                                           /**< [In] Key number in key store of DAM default key. */
        VAR(uint16, ANFCRL_VAR) wKeyVerAppDAMDefault,                                          /**< [In] Key version in key store of DAM default key. */
        VAR(uint8, ANFCRL_VAR) bAppDAMDefaultKeyVer,                                           /**< [In] DAM Default Key version. Value should be valid for AES key. Ignored for other key types. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMEncKey                                                    /**< [Out] Encrypted DAM Default key data. */
    );

/**
 * \brief Generate MAC for Delegated application management.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c KeyNoDAMMAC should be off Offline_Crypto Key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMMAC(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                        /**< [In] Option to represent the present of ISO information.
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_INFO_NOT_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_FILE_ID_AVAILABLE
                                                                                 *          \arg #PHAL_MFDFEVX_ISO_DF_NAME_AVAILABLE
                                                                                 *      \cond INTERNAL
                                                                                 *          \n
                                                                                 *        To be ored with the above ones.
                                                                                 *          \arg #PHAL_MFDFEVX_GENERATE_DAMMAC_CREATE_APPLICATION
                                                                                 *          \arg #PHAL_MFDFEVX_GENERATE_DAMMAC_DELETE_APPLICATION
                                                                                 *      \endcond
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC,                                                  /**< [In] Key number in key store of DAM MAC key. */
        VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC,                                                 /**< [In] Key version in key store of DAM MAC key. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,                                                         /**< [In] The application identifier to be used. Will be of 3 bytes with LSB first.
                                                                                 *          \c If application 01 need to be created then the Aid will be 01 00 00.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams,                                                   /**< [In] The DAM information. Should as mentioned below.\n
                                                                                 *          \c Byte0 = DAM Slot No [LSB]\n
                                                                                 *          \c Byte1 = DAM Slot No [MSB]\n
                                                                                 *          \c Byte2 = DAM Slot Version\n
                                                                                 *          \c Byte3 = Quota Limit [LSB]\n
                                                                                 *          \c Byte4 = Quota Limit [MSB]
                                                                                 */
        VAR(uint8, ANFCRL_VAR) bKeySettings1,                                                  /**< [In] Application Key settings. */
        VAR(uint8, ANFCRL_VAR) bKeySettings2,                                                  /**< [In] Additional key settings.  */
        VAR(uint8, ANFCRL_VAR) bKeySettings3,                                                  /**< [In] Additional key settings.  */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues,                                                /**< [In] The Key set values for the application. Should as mentioned below.\n
                                                                                 *          \c Byte0 = AKS ver\n
                                                                                 *          \c Byte1 = Number of Key sets\n
                                                                                 *          \c Byte2 = MaxKey size\n
                                                                                 *          \c Byte3 = Application KeySet Settings.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,                                                   /**< [In] ISO File ID to be used. Will be two bytes. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,                                                   /**< [In] ISO DF Name to be used. Will be 16 bytes and can also be NULL based on the option. */
        VAR(uint8, ANFCRL_VAR) bISODFNameLen,                                                  /**< [In] Length of bytes available in ISODFName buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK,                                                        /**< [In] Encrypted initial application key. 32 bytes long. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC                                                       /**< [Out] 8 byte DAMMAC. */
    );

/**
 * \brief Generates DAMMAC for Set Configuration with option 0x06 for Delegated Application
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_GenerateDAMMACSetConfig(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC,                                                  /**< [In] Key number in key store of DAM MAC Key */
        VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC,                                                 /**< [In] Key version in key store of DAM MAC Key*/
        VAR(uint16, ANFCRL_VAR) wOldDFNameLen,                                                 /**< [In] Length of existing DF Name */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOldISODFName,                                                /**< [In] This means already created delegated app ISO DF Name. Maximum 16 bytes */
        VAR(uint16, ANFCRL_VAR) wNewDFNameLen,                                                 /**< [In] Length of new DF Name */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewISODFName,                                                /**< [In] This means new delegated app ISO DF Name which will replace the existing one. Maximum 16 bytes */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC                                                       /**< [Out] Generated 8 bytes DAM MAC for setconfig option 0x06 */
    );

/**
 * \brief Computed the Transaction MAC input as performed on the PICC.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c KeyNoTMACKey and RamKeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CalculateTMV(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] Diversification option.
                                                                                 *          \arg #PHAL_MFDFEVX_DIVERSIFICATION_OFF
                                                                                 *          \arg #PHAL_MFDFEVX_DIVERSIFICATION_ON
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey,                                                 /**< [In] Key number to be used from software keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey,                                                /**< [In] Key version to be used from software keystore. */
        VAR(uint16, ANFCRL_VAR) wRamKeyNo,                                                     /**< [In] Key number of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wRamKeyVer,                                                    /**< [In] Key version of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input to diversify TMACKey. */
        VAR(uint8, ANFCRL_VAR) bDivInputLen,                                                   /**< [In] Length of byte available in DivInput buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC,                                                         /**< [In] 4 bytes Transaction MAC Counter. It should be 1 time subtracted from
                                                                                 *        the actual value and should be LSB first.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,                                                         /**< [In] UID of the card. */
        VAR(uint8, ANFCRL_VAR) bUidLen,                                                        /**< [In] Length of UID supplied. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMI,                                                         /**< [In] Transaction MAC Input. */
        VAR(uint32, ANFCRL_VAR) dwTMILen,                                                      /**< [In] Length of bytes available in TMI buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMV                                                          /**< [Out] The computed Transaction MAC Value. */
    );

/**
 * \brief encrypted the reader ID as performed on the PICC.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c KeyNoTMACKey and RamKeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptReaderID(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] Diversification option.
                                                                                 *          \arg #PHAL_MFDFEVX_DIVERSIFICATION_OFF
                                                                                 *          \arg #PHAL_MFDFEVX_DIVERSIFICATION_ON
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey,                                                 /**< [In] Key number to be used from software keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey,                                                /**< [In] Key version to be used from software keystore. */
        VAR(uint16, ANFCRL_VAR) wRamKeyNo,                                                     /**< [In] Key number of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wRamKeyVer,                                                    /**< [In] Key version of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input to diversify TMACKey. */
        VAR(uint8, ANFCRL_VAR) bDivInputLen,                                                   /**< [In] Length of byte available in DivInput buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC,                                                         /**< [In] 4 bytes Transaction MAC Counter. It should be 1 time subtracted from
                                                                                 *        the actual value and should be LSB first.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,                                                         /**< [In] UID of the card. */
        VAR(uint8, ANFCRL_VAR) bUidLen,                                                        /**< [In] Length of UID supplied. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI,                                                     /**< [In] Encrypted Transaction MAC ReaderID of the latest successful transaction. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRIPrev                                                     /**< [Out] encrypted Reader ID of the last successful transaction. */
    );

/**
 * \brief Compute the MFCLicenseMAC for \ref phalMfdfEVx_CreateMFCMapping and
 * \ref phalMfdfEVx_RestrictMFCUpdate command.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c MFCLicenseMACKeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ComputeMFCLicenseMAC(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                                                       /**< [In] Diversification Option.
                                                                                 *          \arg #PHAL_MFDFEVX_NO_DIVERSIFICATION
                                                                                 *          \arg #PHAL_MFDFEVX_DIV_METHOD_CMAC
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyNo,                                           /**< [In] Key number in key store for MFCLicenseMAC calculation. */
        VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyVer,                                          /**< [In] Key version in key store for MFCLicenseMAC calculation. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,                                                       /**< [In] The input for which the MAC should be computed. Input should be as follows.
                                                                                 *          \c 0x01 || MFCLicense || MFCSectorSecrets
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wInputLen,                                                     /**< [In] Length of Bytes available in MFCLicenseMACIn buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                    /**< [In] Diversification input to diversify the Key. */
        VAR(uint8, ANFCRL_VAR) bDivInputLen,                                                   /**< [In] Length of Bytes available in DivInput buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC                                                /**< [Out] The computed MFCLicense MAC. */
    );

/**
 * \brief Calculate MAC SDM
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c SDMMacKeyNo and RamKeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_CalculateMACSDM(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bSdmOption,                                                     /**< [In] SDM Option to indicate which parameters to be considered.
                                                                                 *          \arg #PHAL_MFDFEVX_VCUID_PRESENT
                                                                                 *          \arg #PHAL_MFDFEVX_RDCTR_PRESENT
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wSDMMacKeyNo,                                                  /**< [In] Key number to be used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wSDMMacKeyVer,                                                 /**< [In] Key version to be used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wRamKeyNo,                                                     /**< [In] Key number of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wRamKeyVer,                                                    /**< [In] Key version of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,                                                         /**< [In] UID of the card. */
        VAR(uint8, ANFCRL_VAR) bUidLen,                                                        /**< [In] Length of bytes available in pUid buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr,                                                   /**< [In] SDM Read Counter Input. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData,                                                      /**< [In] Data read out from PICC that is between SDMMac Input offset until SDMMACOffset. */
        VAR(uint16, ANFCRL_VAR) wInDataLen,                                                    /**< [In] Length of bytes available in InData buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRespMac                                                      /**< [Out] Computed SDM MAC. */
    );

/**
 * \brief Decrypt SDM enciphered data.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c EncKeyNo and RamKeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptSDMENCFileData(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint8, ANFCRL_VAR) bSdmOption,                                                     /**< [In] SDM Option to indicate which parameters to be considered.
                                                                                 *          \arg #PHAL_MFDFEVX_VCUID_PRESENT
                                                                                 *          \arg #PHAL_MFDFEVX_RDCTR_PRESENT
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wEncKeyNo,                                                     /**< [In] Key number to be used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wEncKeyVer,                                                    /**< [In] Key version to be used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wRamKeyNo,                                                     /**< [In] Key number of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        VAR(uint16, ANFCRL_VAR) wRamKeyVer,                                                    /**< [In] Key version of Destination Key where the computed session TMAC key will be stored.
                                                                                 *        To be used for SAM AV3 only.
                                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,                                                         /**< [In] UID of the card. */
        VAR(uint8, ANFCRL_VAR) bUidLen,                                                        /**< [In] Length of bytes available in pUid buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr,                                                  /**< [In] SDM Read Counter Input. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncdata,                                                     /**< [In] Encrypted NonASCII SDM Encrypted File data. */
        VAR(uint16, ANFCRL_VAR) wEncDataLen,                                                    /**< [In] Length of bytes available in EncData buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData                                                    /**< [Out] The encrypted SDMFile data. */
    );

/**
 * \brief Decrypt SDM PICC Data.
 * While using this command in SAM mode make sure the below points are taken care\n
 *  \c KeyNo should be off Offline_Crypto key class.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_DecryptSDMPICCData(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                        /**< [In] Key number to be used from software or hardware keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVer,                                                       /**< [In] Key version to be used from software or hardware keystore. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncdata,                                                     /**< [In] Encrypted NonASCII SDM PICC data. */
        VAR(uint16, ANFCRL_VAR) wEncDataLen,                                                    /**< [In] Length of bytes available in EncData buffer. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData                                                    /**< [Out] The encrypted SDM PICC Data. */
    );
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

/**
 * \brief This is a utility API which sets the VCA structure in Desfire EVx structure params
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_SetVCAParams(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                     /**< [In] Pointer to this layers parameter structure. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlVCADataParams                                                 /**< [In] Pointer to VCA AL parameter structure. */
    );

/**
 * end of group phalMfdfEVx_Miscellaneous Commands_Miscellaneous
 * @}
 */

/**
 * end of group phalMfdfEVx MIFARE DESFire EVx
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDFEVx */

#ifdef __cplusplus
}
#endif

#endif /* PHALMFDFEVX_H */
