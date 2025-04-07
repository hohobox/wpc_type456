/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2021
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
*   @file    phNfcLib2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib - NFC API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
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
#ifndef PH_NFCLIB2_H
#define PH_NFCLIB2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status2.h>
#include "phNxpNfcRdLib_Config2.h"
#include "phhalHw2.h"

/* PAL Headers */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
#include "phpalI14443p3a2.h"
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
#include "phpalI14443p3b2.h"
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
#include "phpalI14443p4a2.h"
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4_SW2
#include "phpalI14443p42.h"
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

#ifdef NXPBUILD__PHPAL_FELICA_SW2
#include "phpalFelica2.h"
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
#include "phpalI14443p4mC2.h"
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
#include "phpalSli156932.h"
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

/* AL Headers */

#ifdef NXPBUILD__PHAL_FELICA_SW2
#include "phalFelica2.h"
#endif /* NXPBUILD__PHAL_FELICA_SW2 */

#ifdef NXPBUILD__PHAL_ICODE_SW2
#include "phalICode2.h"
#endif /* NXPBUILD__PHAL_ICODE_SW2 */

#ifdef NXPBUILD__PHAL_MFDF_SW2
#include "phalMfdf2.h"
#endif /* NXPBUILD__PHAL_MFDF_SW2 */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
#include "phalMfdfEVx2.h"
#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

#ifdef NXPBUILD__PH_TMIUTILS2
#include "phTMIUtils2.h"
#endif  /* NXPBUILD__PH_TMIUTILS2 */

#ifdef NXPBUILD__PHAL_VCA_SW2
#include "phalVca2.h"
#endif /* NXPBUILD__PHAL_VCA_SW2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop2.h"
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

/* HCE Header */
#ifdef NXPBUILD__PHCE_T4T_SW2
#include "phceT4T2.h"
#endif /* NXPBUILD__PHCE_T4T_SW2 */

/* Crypto Headers */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW2
#include "phCryptoSym2.h"
#endif /* NXPBUILD__PH_CRYPTOSYM_SW2 */

#ifdef NXPBUILD__PH_CRYPTORNG_SW2
#include "phCryptoRng2.h"
#endif /* NXPBUILD__PH_CRYPTORNG_SW2 */

/* Keystore Header */
#if defined (NXPBUILD__PH_KEYSTORE_SW2) || defined (NXPBUILD__PH_KEYSTORE_NCx33202)
#include "phKeyStore2.h"
#endif

#ifdef NXPBUILD__PHNFCLIB2
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHNFCLIB_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHNFCLIB_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phNfcLib2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHNFCLIB_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHNFCLIB_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHNFCLIB_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHNFCLIB_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHNFCLIB_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib2.h and CDD_AnfcRL_Cfg.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB2 */
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup grpsApi Simplified API Layer
* \brief Simplified APIs for access to NxpNfcRdLib functionality
*/

#ifdef NXPBUILD__PHNFCLIB2
/**
 * \defgroup nfc_lib_definitions NFC NXP NFC Library Definitions
 * \brief Common defines used within the API of NFC library
 * \ingroup nfc_lib
 * @{
 *
 */

#define PH_NFCLIB_TECHNOLOGY_ISO_14443_A2             0x01U
#define PH_NFCLIB_TECHNOLOGY_ISO_14443_B2             0x02U
#define PH_NFCLIB_TECHNOLOGY_FELICA2                  0x04U
#define PH_NFCLIB_TECHNOLOGY_ISO_156932               0x08U
#define PH_NFCLIB_TECHNOLOGY_ROLE_INITIATOR_SHIFT2    0x00U
#define PH_NFCLIB_TECHNOLOGY_ROLE_TARGET_SHIFT2       0x08U

/**
 * \name RF Technologies
 *
 * \anchor nfc_lib_definitions_rf_techno
 * \brief Definitions used within phNfcLib_Activate2 and struct #phNfcLib_PeerInfo_t2
 * @{
 */
#define PH_NFCLIB_TECHNOLOGY_DEFAULT2                     0x0U
#define PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_A2       ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_14443_A2    << PH_NFCLIB_TECHNOLOGY_ROLE_INITIATOR_SHIFT2) /**< ISO 14443-3A, Initiator mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_B2       ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_14443_B2    << PH_NFCLIB_TECHNOLOGY_ROLE_INITIATOR_SHIFT2) /**< ISO 14443-3B, Initiator mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_INITIATOR_FELICA2            ((uint32)PH_NFCLIB_TECHNOLOGY_FELICA2         << PH_NFCLIB_TECHNOLOGY_ROLE_INITIATOR_SHIFT2) /**< FeliCa Initiator mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_156932         ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_156932      << PH_NFCLIB_TECHNOLOGY_ROLE_INITIATOR_SHIFT2) /**< ISO 15693, Initiator mode RF technology. */

#define PH_NFCLIB_TECHNOLOGY_TARGET_ISO_14443_A2          ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_14443_A2    << PH_NFCLIB_TECHNOLOGY_ROLE_TARGET_SHIFT2)    /**< ISO 14443-3A, Target mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_TARGET_ISO_14443_B2          ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_14443_B2    << PH_NFCLIB_TECHNOLOGY_ROLE_TARGET_SHIFT2)    /**< ISO 14443-3B, Target mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_TARGET_FELICA2               ((uint32)PH_NFCLIB_TECHNOLOGY_FELICA2         << PH_NFCLIB_TECHNOLOGY_ROLE_TARGET_SHIFT2)    /**< FeliCa Target mode RF technology. */
#define PH_NFCLIB_TECHNOLOGY_TARGET_ISO_180922            ((uint32)PH_NFCLIB_TECHNOLOGY_ISO_180922      << PH_NFCLIB_TECHNOLOGY_ROLE_TARGET_SHIFT2)    /**< ISO 18092 active mode, Target mode RF technology. */
/*@}*/

/**
 * \name Configuration Defaults
 *
 * \anchor nfc_lib_definitions_configuration_default
 * \brief Definition used for default configuration mode
 * @{
 */
#define PH_NFCLIB_ACTIVATION_BLOCKINGMODE_DEFAULT2        PH_OFF2
#define PH_NFCLIB_DEACTIVATION_BLOCKINGMODE_DEFAULT2      PH_OFF2
/*@}*/

#define PH_NFCLIB_BIT_RATE_1062                       0x0U
#define PH_NFCLIB_BIT_RATE_2122                       0x1U
#define PH_NFCLIB_BIT_RATE_4242                       0x2U
#define PH_NFCLIB_BIT_RATE_8482                       0x3U
#define PH_NFCLIB_BIT_RATE_262                        0x10U
#define PH_NFCLIB_BIT_RATE_532                        0x11U

/**
 * \name Activation Priority
 *
 * \anchor nfc_lib_definitions_activation_priority
 * \brief Definitions used as values for #phNfcLib_SetConfig_Value2 and #qpHNfCLib_GeTConfig2 when using
 * configuration tag #PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO2
 *
 * @{
 */
#define PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432   0x0U /**< Priority given to ISO 14443 */
#define PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_180922   0x1U /**< Priority given to ISO 18092 */
/*@}*/

/**
 * \name Deactivation Mode
 *
 * \anchor nfc_lib_definitions_deactivation_mode
 * \brief Definitions used within phNfcLib_DeActivate for \a bDeactivateMode2 parameter.
 * @{
 */
#define PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2           0x0U /**< No target deactivation procedure is performed,
                                                          RF field is just switched off and wait for 5.1ms. */
#define PH_NFCLIB_DEACTIVATION_MODE_RELEASE2          0x1U /**< A target deactivation procedure is performed
                                                          if applicable. (Example, in case of activation
                                                          profile #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2 this means the
                                                          removal procedure is performed. In other profiles this
                                                          could imply execution of deactivation procedures like DSL_REQ.)
                                                          RF field is not switched off. phNfcLib_DeActivate should be called
                                                          with #PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2 to switch off RF field. */
/*@}*/


/**
 * \name Activation Profiles
 *
 * @{
 *
 * \anchor nfc_lib_definitions_activation_profile
 *
 * \brief Definitions used as values for #phNfcLib_SetConfig_Value2 and #qpHNfCLib_GeTConfig2 when using
 * configuration tag \ref PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2
 *
 */

/** NFC Forum Activation Loop Profile and NDEF communication channel
 *
 *
 *  \warning NFC Profile is not implemented/available in this release.
 */
#define PH_NFCLIB_ACTIVATION_PROFILE_NFC2             0x0U

/** EMVCo Activation Loop Profile and ISO14443-4 communication channel */
#define PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2           0x1U

/** Generic ISO Activation Loop Profile and block/frame oriented communication
 * channel (depending on underlying protocol)  */
#define PH_NFCLIB_ACTIVATION_PROFILE_ISO2             0x2U
/*@}*/

#define PH_NFCLIB_CHECK2(status2)         {if ((status2) != PH_NFCLIB_STATUS_SUCCESS2) {return (status2);}}
#define PH_NFCLIB_CHECK_FCT2(status2,fct2) {(status2) = (fct2); PH_NFCLIB_CHECK2(status2);}

#define PH_NFCLIB_STATUS_GROUP_GENERAL2               0x00U
#define PH_NFCLIB_STATUS_GROUP_ACTIVATION2            0x08U
#define PH_NFCLIB_STATUS_GROUP_RF_COMMUNICATION2      0x16U

/** \name Simplified API Errors
*/
/*@{*/
#define PH_NFCLIB_STATUS_SUCCESS2                     ((phNfcLib_Status_t2)0x00U)
#define PH_NFCLIB_STATUS_INVALID_STATE2               ((phNfcLib_Status_t2)0x01U << PH_NFCLIB_STATUS_GROUP_GENERAL2)
#define PH_NFCLIB_STATUS_INVALID_PARAMETER2           ((phNfcLib_Status_t2)0x02U << PH_NFCLIB_STATUS_GROUP_GENERAL2)
#define PH_NFCLIB_STATUS_BUFFER_OVERFLOW2             ((phNfcLib_Status_t2)0x04U << PH_NFCLIB_STATUS_GROUP_GENERAL2)
#define PH_NFCLIB_STATUS_ABORTED2                     ((phNfcLib_Status_t2)0x08U << PH_NFCLIB_STATUS_GROUP_GENERAL2)
#define PH_NFCLIB_STATUS_INTERNAL_ERROR2              ((phNfcLib_Status_t2)0x10U << PH_NFCLIB_STATUS_GROUP_GENERAL2)

#define PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2        ((phNfcLib_Status_t2)0x01U << PH_NFCLIB_STATUS_GROUP_ACTIVATION2)
#define PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2     ((phNfcLib_Status_t2)0x02U << PH_NFCLIB_STATUS_GROUP_ACTIVATION2)
#define PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2      ((phNfcLib_Status_t2)0x04U << PH_NFCLIB_STATUS_GROUP_ACTIVATION2)
#define PH_NFCLIB_STATUS_NO_PEER_DISCOVERED2          ((phNfcLib_Status_t2)0x08U << PH_NFCLIB_STATUS_GROUP_ACTIVATION2)
#define PH_NFCLIB_STATUS_PEER_DEACTIVATION_FAILED2    ((phNfcLib_Status_t2)0x10U << PH_NFCLIB_STATUS_GROUP_ACTIVATION2)

#define PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR2       ((phNfcLib_Status_t2)0x01U << PH_NFCLIB_STATUS_GROUP_RF_COMMUNICATION2)
#define PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR2            ((phNfcLib_Status_t2)0x02U << PH_NFCLIB_STATUS_GROUP_RF_COMMUNICATION2)
#define PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2           ((phNfcLib_Status_t2)0x04U << PH_NFCLIB_STATUS_GROUP_RF_COMMUNICATION2)
#define PH_NFCLIB_STATUS_RF_PEER_LOST2                ((phNfcLib_Status_t2)0x08U << PH_NFCLIB_STATUS_GROUP_RF_COMMUNICATION2)
/*@}*/

/**
 * end of group nfc_lib_definitions NFC NXP NFC Library Definitions
 * @}
 */

/**
 * \defgroup nfc_lib_config_tags NFC Library Configuration Tags
 * \ingroup nfc_lib
 * \brief These tags are used as \p bConfigTag2 parameter for #phNfcLib_SetConfig_Value2, #phNfcLib_SetConfig2 and #qpHNfCLib_GeTConfig2
 * @{
 */

/**
 * \name Tags Activation
 *
 * \anchor nfc_lib_config_tags_activation
 * \brief  Activation Influencing Configuration Tags
 * @{
 */
/**
 * \anchor activation_blocking
 * This configuration parameter indicates if the activation procedure (in fact #phNfcLib_Activate2) should return only on successful
 * activation or if it should return after every activation loop iteration.
 * \par Parameter Size
 * 1 Byte (\p uint8)
 * \par Allowed Values
 * \li \p #PH_OFF2 Activation procedure is not blocking, i.e. #phNfcLib_Activate2 returns after every iteration of its internal discovery loop.
 * \li \p #PH_ON Activation procedure is blocking, i.e. #phNfcLib_Activate2 only returns upon successful activation or in case of an
 *     activation related error (e.g. collision can't be resolved).
 * \par Default Value
 * \p #PH_ON
 */
#define PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING2             0x0U

/**
 * This configuration parameter specifies the time in milliseconds the activation procedure, or in fact its internal discovery loop,
 * should wait in target/listen phase or in pause phase (in case no target technology is specified.) These two phases are following
 * the initiator/poll phase, i.e. the total duration of one discovery loop iteration is this target/pause time + time required for
 * executing the polling phase.
 * \par Parameter Size
 * 2 Byte (\p uint16)
 * \par Allowed Value Range
 * \p 0 - \p 65535
 * \par Default Value
 * \p 1000
 * \par Example
 * \code
 * phNfcLib_SetConfig_Value2(PH_NFCLIB_CONFIG_ACTIVATION_TARGET_PAUSE_TIME2, 1000); /-/ 1sec
 * \endcode
 */
#define PH_NFCLIB_CONFIG_ACTIVATION_TARGET_PAUSE_TIME2    0x1U

/**
 * \anchor activation_profile
 * This configuration parameter is used to select the profile to be used when running the activation.
 * Depending on the profile the behavior of activation procedure (guard times, discovery loop execution order) is adapted.
 * \par Transmission Channel Mapping
 * This setting also defines how phNfcLib_Transmit2 and phNfcLib_Receive2 are mapped on the transmission channel:
 * \li #PH_NFCLIB_ACTIVATION_PROFILE_ISO2 establishes a raw communication channel, i.e. data is transmitted in blocks/frames as defined
 * by the corresponding standard. For ISO14443 this refers to Layer 4 block oriented half duplex protocol, for ISO18092 it refers to
 * the half duplex data exchange protocol, for all other protocols (FeliCa, ISO15693, MIFARE Ultralight contactless IC etc.) the data is
 * encapsulated in frames of the respective standard.
 * \li #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2 Here only ISO14443 layer 4 block oriented half duplex protocol is supported.
 * \li #PH_NFCLIB_ACTIVATION_PROFILE_NFC2 Here the data is sent is actually a well formatted NDEF record. The NFC library in this case performs
 * the NDEF detection procedure. If the tag is not formatted yet, it will be automatically formatted. Existing data will be replaced.
 *
 * \par Parameter Size
 * 1 Byte (uint8)
 * \par Allowed Values
 * Refer to \ref nfc_lib_definitions_activation_profile
 * \par Default Value
 * #PH_NFCLIB_ACTIVATION_PROFILE_NFC2
 * \par Example
 * \code
 * phNfcLib_SetConfig_Value2(PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2, PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2); /-/ set EMVCo Profile
 * \endcode
 */
#define PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2              0x2U

/**
 * \anchor activation_prio
 * This configuration parameter is used set the activation priority in case a peer indicate a 'merged SAK',
 * i.e. peer supports both, ISO18092 and ISO14443 Layer 4. Depending on this parameter, activation procedure then
 * activates the protocol indicated by its value.
 * \par Parameter Size
 * 1 Byte (\p uint8)
 * \par Allowed Values
 * Refer to \ref nfc_lib_definitions_activation_priority
 * \par Default Value
 * #PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432
 */
#define PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO2      0x3U
/*@}*/

/**
 * \anchor De-activation_blocking
 * This configuration parameter indicates if the deactivation procedure (in fact #phNfcLib_Deactivate2) should return only on successful
 * deactivation or if it should return after every deactivation loop iteration. This configuration parameter is applicable only in case
 * of activation profile is #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2.
 * This configuration is not applicable and doesn't impact behavior of #phNfcLib_Deactivate2 API in ISO and NFC mode.
 * \par Parameter Size
 * 1 Byte (\p uint8)
 * \par Allowed Values
 * \li \p #PH_OFF2 De-activation procedure is not blocking, i.e. #phNfcLib_Deactivate2 returns after one cycle of deactivation procedure.
 *     One cycle includes sending several WUPA/B commands according to EMVCo Contactless specification, Book D. If a response is received
 *     for any one WUPA/B the function returns immediately with #PH_NFCLIB_STATUS_PEER_DEACTIVATION_FAILED2 and user needs to call
 *     #phNfcLib_Deactivate2 once again to perform deactivation procedure.
 * \li \p #PH_ON De-activation procedure is blocking, i.e. #phNfcLib_Deactivate2 only returns upon successful deactivation from discovery loop
 *     or in case of an abort.
 * \par Default Value
 * \p #PH_ON
 *
 * \pre NFC Library should not be in state RESET
 */
#define PH_NFCLIB_CONFIG_DEACTIVATION_BLOCKING2           0x4U

/**
 * \anchor Enable_LPCD
 * This configuration parameter indicates if LPCD (Low Power Card Detection) is ON during Activation procedure (in fact #phNfcLib_Activate2)
 * should perform poll only on change in RF field (except for activation profile #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2).
 * \par Parameter Size
 * 1 Byte (\p uint8)
 * \par Allowed Values
 * \li \p #PH_OFF2 LPCD procedure is OFF.
 * \li \p #PH_ON  LPCD procedure if ON.
 * \par Default Value
 * \p #PH_OFF2
 */
#define PH_NFCLIB_CONFIG_INITIATOR_ENABLE_LPCD2           0x10U

#define PH_NFCLIB_CONFIG_TARGET_TYPEA_ATQA2               0x20U
#define PH_NFCLIB_CONFIG_TARGET_TYPEA_UID2                0x21U
#define PH_NFCLIB_CONFIG_TARGET_TYPEA_SAK2                0x22U
#define PH_NFCLIB_CONFIG_TARGET_TYPEF_UID2                0x30U
/**
 * end of group nfc_lib_config_tags NFC Library Configuration Tags
 * @}
 */

/**
 * \anchor nfc_lib_mfc_uid_type
 * \name UID Type definitions for Personalize UID Command
 */
/*@{*/
#define PH_NFCLIB_MFC_UID_TYPE_UIDF02      0x00U     /**< MIFARE(R) Classic contactless IC UID type UIDF0. */
#define PH_NFCLIB_MFC_UID_TYPE_UIDF12      0x40U     /**< MIFARE(R) Classic contactless IC UID type UIDF1. */
#define PH_NFCLIB_MFC_UID_TYPE_UIDF22      0x20U     /**< MIFARE(R) Classic contactless IC UID type UIDF2. */
#define PH_NFCLIB_MFC_UID_TYPE_UIDF32      0x60U     /**< MIFARE(R) Classic contactless IC UID type UIDF3. */
/*@}*/

/**
 * \anchor nfc_lib_max_vicinity_tag
 * \name Max ISO/IEC 15693 tags that can be detected by Simplified API.
 */
/*@{*/
#define PH_NFCLIB_MAX_ISO15693_TAGS_SUPPORTED2    1u
/*@}*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * \addtogroup nfc_lib_config_tags NFC Library Configuration Tags
 * \ingroup nfc_lib
 * \brief These tags are used as \p bConfigTag2 parameter for #phNfcLib_SetConfig_Value2, #phNfcLib_SetConfig2 and #qpHNfCLib_GeTConfig2
 * @{
 */

/**
 * \brief NFC LIB ACTIVATED TYPE
 * \anchor phNfcLib_ActivatedType_t2
 */
typedef enum /*phNfcLib_ActivatedType*/
{
    E_PH_NFCLIB_UNKNOWN2            = 0,
    E_PH_NFCLIB_MIFARE_ULTRALIGHT2,                          /**< Card Type can be any one of MIFARE Ultralight, MIFARE Ultralight C contactless IC, MIFARE Ultralight EV1 contactless IC. */
    E_PH_NFCLIB_MIFARE_CLASSIC_1K2,
    E_PH_NFCLIB_MIFARE_CLASSIC_4K2,
    E_PH_NFCLIB_MIFARE_DESFIRE2,
    E_PH_NFCLIB_TYPEA_LAYER32,
    E_PH_NFCLIB_TYPEA_LAYER42,
    E_PH_NFCLIB_TYPEB_LAYER32,
    E_PH_NFCLIB_TYPEB_LAYER42,
    E_PH_NFCLIB_ISO156932,
    E_PH_NFCLIB_LAST2 = 0x7FFFFFFF
} phNfcLib_ActivatedType_t2;

/**
 * \anchor nfc_lib_mfc_commands
 * \brief Defines all the commands that can be performed on MIFARE Classic contactless IC card
 */
typedef enum /*phNfcLib_MFC_Commands*/
{
    NoCommand2 = 0,
    Read2,
    Write2,
    Increment2,
    Decrement2,
    Transfer2,
    Restore2,
    Authenticate2,                                   /**< Provides Authentication using only software keystore. */
    PersonalizeUID2
} phNfcLib_MFC_Commands_t2;

/**
 * \anchor nfc_lib_mfdf_commands
 * \brief Provides commands that can be performed on MIFARE DESFire contactless IC
 */
typedef enum /* phNfcLib_MFDF_Commands */
{
    MFDF_NoCommand2 = 0,
    MFDF_Create_Application2,
    MFDF_Select_Application2,
    MFDF_Get_Version2,
    MFDF_Create_StdDataFile2,
    MFDF_Write_Data2,
    MFDF_Iso_SelectFile2,
    MFDF_Iso_ReadBinary2,
    MFDF_Iso_UpdateBinary2
} phNfcLib_MFDF_Commands_t2;

/**
 * \anchor nfc_lib_iso15693_commands
 * \brief Provides commands that can be performed on ISO 15693 compliant card
 * Simplified API always communicates in Address Mode with ISO 15693 compliant card.
 */
typedef enum /*phNfcLib_I15693_Commands*/
{
    ISO15693_NoCommand2 = 0,
    ISO15693_ReadSingleBlock2,
    ISO15693_Extended_ReadSingleBlock2,
    ISO15693_ReadMultipleBlocks2,
    ISO15693_Extended_ReadMultipleBlocks2,
    ISO15693_GetSystemInformation2,
    ISO15693_ExtendedGetSystemInformation2,
    ISO15693_GetMultipleBlockSecurityStatus2,
    ISO15693_Extended_GetMultipleBlockSecurityStatus2,
    ISO15693_WriteSingleBlock2,
    ISO15693_Extended_WriteSingleBlock2,
    ISO15693_WriteMultipleBlocks2,
    ISO15693_Extended_WriteMultipleBlocks2,
    ISO15693_LockBlock2,
    ISO15693_Extended_LockBlock2,
    ISO15693_WriteAFI2,
    ISO15693_LockAFI2,
    ISO15693_WriteDSFID2,
    ISO15693_LockDSFID2
}phNfcLib_I15693_Commands_t2;

/**
 * end of group nfc_lib_config_tags NFC Library Configuration Tags
 * @}
 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * \addtogroup nfc_lib_config_tags NFC Library Configuration Tags
 * \ingroup nfc_lib
 * \brief These tags are used as \p bConfigTag2 parameter for #phNfcLib_SetConfig_Value2, #phNfcLib_SetConfig2 and #qpHNfCLib_GeTConfig2
 * @{
 */

/**
 * \brief NFC LIB Application Context
 * \anchor phNfcLib_AppContext
 */
typedef struct
{
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataparams2;                   /* Should point to the BAL Dataparams initialized by the application. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pRtoxCallback2;                    /* Pointer to the RTOX Callback implemented by the application. */
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
    VAR(pWtxTimerCallback_t, ANFCRL_VAR) pWtxCallback2;        /* Pointer to the WTX Callback implemented by the application. */
#endif
#ifdef NXPBUILD__PHHAL_HW_NCX33212
    VAR(phTools_PollFunc_t2, ANFCRL_VAR) pHalPollFunc2;
#endif
} phNfcLib_AppContext_t2;

/**
 * \brief Peer Information
 * \anchor peer_info
 */
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bId2;                                /* Layer ID : Not used */
    VAR(phNfcLib_ActivatedType_t2, ANFCRL_VAR) dwActivatedType2;                    /**< Activated type may be ORed value of \ref phNfcLib_ActivatedType_t. */
#if 0
    VAR(uint32, ANFCRL_VAR) dwSelectedType2;                     /**< Not used in this Beta release. User has to choose from 'dwActivatedType2'
                                                      with any one card type \ref phNfcLib_ActivatedType_t2 he is interested. */
#endif
    union {
        union {
            struct
            {
                VAR(uint16, ANFCRL_VAR) wAtqa2;                  /**< To be done. */
                VAR(uint8, ANFCRL_VAR) bUidLength2;              /**< Activated Type A tag UID length is provided. */
                VAR(uint8, ANFCRL_VAR) aUid2[10];                /**< Provides UID of activated Type A card. */
                VAR(uint8, ANFCRL_VAR) bSak2;                    /**< To be done. */
            } tIso14443_3a2;

            struct
            {
                VAR(uint8, ANFCRL_VAR) bAtqbLength2;             /**< To be done. */
                VAR(uint8, ANFCRL_VAR) aPupi2[4];                /**< To be done. */
                VAR(uint8, ANFCRL_VAR) aApplicationData2[4];     /**< To be done. */
                VAR(uint8, ANFCRL_VAR) bIsExtendedAtqb2;         /**< To be done. */
                VAR(uint8, ANFCRL_VAR) aProtocolInfo2[4];        /**< To be done. */
            } tIso14443_3b2;

            struct
            {
                struct
                {
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2;               /* Provides pointer to array of 8bytes UID of ISO 15693 tags detected. */
                }TagIndex2[PH_NFCLIB_MAX_ISO15693_TAGS_SUPPORTED2];

                VAR(uint8, ANFCRL_VAR) bTotalTagsFound2;         /* Number of ISO 15693 Tags detected. */
            } tIso156932;
        } uInitiator2;
    } uTi2;
    VAR(uint8, ANFCRL_VAR) bRfProtocolInformationLength2;
    union {
        union {
            struct
            {
                VAR(uint8, ANFCRL_VAR) bDid2;
                VAR(uint8, ANFCRL_VAR) aAts2[PH_NXPNFCRDLIB_CONFIG_ATS_BUFF_LENGTH2];
            } tIso14443_42;                       /**< To be done. */

            struct
            {
                VAR(uint8, ANFCRL_VAR) aNfcId32[10];
                VAR(uint8, ANFCRL_VAR) bDid2;
                VAR(uint8, ANFCRL_VAR) bGeneralBytesLength2;
                VAR(uint8, ANFCRL_VAR) aGeneralBytes2[48];
            } tIso180922;                         /**< To be done. */
        } uInitiator2;

    } uRi2;

} phNfcLib_PeerInfo_t2;

/**
 * \anchor nfc_lib_mfc_parameters
 * \brief Defines parameters that needs be provided by User to communicate with MIFARE Classic
 */
typedef struct /*phNfcLib_MFC*/{
    VAR(phNfcLib_MFC_Commands_t2, ANFCRL_VAR) bCommand2;               /**< [In] MIFARE Classic command needs to be provided. */
    VAR(uint8, ANFCRL_VAR) bBlockNumber2;                           /**< [In] Block number on which MIFARE Classic command to be executed. */
    VAR(uint8, ANFCRL_VAR) bKeyType2;                               /**< [In] Key Type used to Authenticate MIFARE Classic. Takes either #PHHAL_HW_MFC_KEYA or #PHHAL_HW_MFC_KEYB. */
    VAR(uint8, ANFCRL_VAR) bKeyNumber2;                             /**< [In] Key Number from Sw KeyStore to be fetched to Authenticate MIFARE Classic. */
    VAR(uint8, ANFCRL_VAR) bKeyVersion2;                            /**< [In] Key version from Sw KeyStore to be retrieved to Authenticate MIFARE Classic. */
    VAR(uint8, ANFCRL_VAR) bUidType2;                               /**< [In] UID Type used to Personalize the MFC card. Refer \ref nfc_lib_mfc_uid_type */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer2;
}phNfcLib_MFC_t2;

/**
 * \anchor nfc_lib_mfdf_parameters
 * \brief Defines parameters that needs be provided by User to communicate with MIFARE DESFire IC-based contactless card
 */
typedef struct /*phNfcLib_MFdf*/{
    VAR(phNfcLib_MFDF_Commands_t2, ANFCRL_VAR) bCommand2;              /**< [In] MIFARE DESFire command needs to be provided. */
    union{

       struct {
    VAR(uint8, ANFCRL_VAR) bOptions2;                               /**< [In] Option parameter. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pApplicationIdentifier2;                /**< [In] MIFARE DESFire AID (Application identifier), 0x000000 is reserved. */
    VAR(uint8, ANFCRL_VAR) bKeySettings12;                          /**< [In] MIFARE DESFire KeySetting 1 currently can be only set to 0x0F, as
                                                              authentication support is not yet provided by Simplified API. */
    VAR(uint8, ANFCRL_VAR) bKeySettings22;                          /**< [In] MIFARE DESFire KeySetting 2, bits 6,7 defines the key that will be used,
                                                              bit 5 indicates if application supports ISO File ID for selection,
                                                              for whole application and lower nibble defines no of Keys that can be used. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId2;                            /**< [In] Optional ISO File ID that can be used to Select application using 7816-4 command,
                                                              Valid only if bit 5 of KeySetting 2 is set to '1'. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName2;                           /**< [In] Optional ISO DF name that can be used to Select application using 7816-4 command,
                                                              Length of this parameter can be from 1 to 16bytes. */
    VAR(uint8, ANFCRL_VAR) bISODFNameLen2;                          /**< [In] ISO DF name length provided by User, can take value from 1 to 16bytes. */
        }Create_Application2;

       struct{
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pApplicationIdentifier2;                /**< [In] MIFARE DESFire AID (Application identifier) to select file. */
        }Select_Application2;

        struct{
    VAR(uint8, ANFCRL_VAR) bOption2;                                /**< [In] Option parameter. */
    VAR(uint8, ANFCRL_VAR) bFileNo2;                                /**< [In] File number in the range of 0x00 to 0x1F. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId2;                            /**< [In] Optional ISO File ID that can be used to select file using 7816-4 command. */
    VAR(uint8, ANFCRL_VAR) bCommSett2;                              /**< [In] Communication settings, currently only plain comm is supported with bit 0 set to 0. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights2;                         /**< [In] Read/Write access rights, currently only free access is supported with all nibbles set to 0xE. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize2;                             /**< [In] File size. */
        }Create_StdDataFile2;

        struct{
    VAR(uint8, ANFCRL_VAR) bCommOption2;                            /**< [In] Communication settings, currently only plain comm is supported (value 0x00). */
    VAR(uint8, ANFCRL_VAR) bFileNo2;                                /**< [In] File number in the range of 0x00 to 0x1F. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset2;                               /**< [In] Offset from which write operation to be done. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData2;                              /**< [In] Pointer to array of data to be written into File. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen2;                            /**< [In] Length of data. */
        }Write_Data2;

        struct{
    VAR(uint8, ANFCRL_VAR) bSelector2;                              /**< [In] P1 field in ISO 7816-4, can take either 0x00 or 0x02 or 0x04. */
    VAR(uint8, ANFCRL_VAR) bOption2;                                /**< [In] P2 field in ISO 7816-4, when 0x00 FCI stored in file will be returned.
                                                              when 0x0C FCI shall not be returned. Any other value is invalid. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid2;                                  /**< [In] Elementary File Identifier used to select application when P1 is
                                                              either 0x00 or 0x02. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname2;                               /**< [In] DF name that can be used to Select ISO file. */
    VAR(uint8, ANFCRL_VAR) bDFnameLen2;                             /**< [In] Length of DF name provided by User, can take value from 1 to 16bytes. */
        }Select_File2;


        struct{
    VAR(uint16, ANFCRL_VAR) wOption2;                               /**< [In] Option parameter indicating #PH_EXCHANGE_DEFAULT or #PH_EXCHANGE_RXCHAINING. */
    VAR(uint8, ANFCRL_VAR) bSfid2;                                  /**< [In] P1 field in ISO 7816-4, if bit 8 is set to zero then p1 indicates MSB of offset else
                                                              bit5 to bit1 (5bits) indicates short ISO FID. */
    VAR(uint8, ANFCRL_VAR) bOffset2;                                /**< [In] P2 field in ISO 7816-4, codes offset. */
    VAR(uint8, ANFCRL_VAR) bBytesToRead2;                           /**< [In] Le field in ISO 7816-4, number of bytes to read from file. */
        }Read_Binary2;

        struct{
    VAR(uint8, ANFCRL_VAR) bSfid2;                                  /**< [In] P1 field in ISO 7816-4, if bit 8 is set to zero then p1 indicates MSB of offset else
                                                              bit5 to bit1 (5bits) indicates short ISO FID. */
    VAR(uint8, ANFCRL_VAR) bOffset2;                                /**< [In] P2 field in ISO 7816-4, codes offset. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2;                                /**< [In] Pointer to array data to be written. */
    VAR(uint8, ANFCRL_VAR) bDataLen2;                               /**< [In] Length of data provided by application. */
        }Update_Binary2;

    }Operation2;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer2;
}phNfcLib_MFDF_t2;

/**
 * \anchor nfc_lib_iso15693_parameters
 * \brief Defines parameters that needs be provided by User to communicate with ISO 15693 card
 */
typedef struct /*phNfcLib_I15693*/
{
    VAR(phNfcLib_I15693_Commands_t2, ANFCRL_VAR) bCommand2;            /**< [In] ISO-IEC 15693-3 command needs to be provided. */
    VAR(uint8, ANFCRL_VAR) bOption2;                                /**< [In] Option flag shall be set in Request flags. Meaning is defined by
                                                              each command description. For more info refer ISO-IEC 15693-3 Spec. */
    VAR(uint8, ANFCRL_VAR) bAfi2;                                   /**< [In] Application family identifier. */
    VAR(uint8, ANFCRL_VAR) bDsfid2;                                 /**< [In] Data storage format identifier. */
    VAR(uint16, ANFCRL_VAR) wBlockNumber2;                          /**< [In] Block number on which ISO 15693-3 command to be executed.
                                                              Optional commands block number is single byte. Only in case of Extended
                                                              commands block number will be 2 bytes. */
    VAR(uint16, ANFCRL_VAR) wNumBlocks2;                            /**< [In] Number of blocks on which command like ReadMultiple/WriteMultiple blocks
                                                              command to be executed. */
    VAR(uint8, ANFCRL_VAR) bUid2[8];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer2;
}phNfcLib_I15693_t2;


/**
 * \anchor nfc_lib_raw_parameters
 * \brief Defines parameters that needs be provided by User to communicate with raw ISO 14443-3 or ISO 14443-4 peer.
 */
typedef struct /*phNfcLib_RawTransmit*/
{
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer2;
}phNfcLib_RawTransmit_t2;

/**
 * \anchor nfc_lib_transmit_metadata
 * \brief Defines parameters that needs be provided by User to use \ref phNfcLib_Transmit2 API in ISO mode.
 */
typedef union /*phNfcLib_Transmit2*/{
    VAR(phNfcLib_MFC_t2, ANFCRL_VAR) phNfcLib_MifareClassic2;
    VAR(phNfcLib_MFDF_t2, ANFCRL_VAR) phNfcLib_MifareDesfire2;
    VAR(phNfcLib_I15693_t2, ANFCRL_VAR) phNfcLib_ISO156932;
    VAR(phNfcLib_RawTransmit_t2, ANFCRL_VAR) phNfcLib_RawTransmit2;
} phNfcLib_Transmit_t2;

/**
 * end of group nfc_lib_config_tags NFC Library Configuration Tags
 * @}
 */

/**
 * \addtogroup nfc_lib_config_tags NFC Library Configuration Tags
 * \ingroup nfc_lib
 * \brief These tags are used as \p bConfigTag2 parameter for #phNfcLib_SetConfig_Value2, #phNfcLib_SetConfig2 and #qpHNfCLib_GeTConfig2
 * @{
 */
typedef VAR(uint32, ANFCRL_VAR) phNfcLib_Status_t2;
/**
 * end of group nfc_lib_config_tags NFC Library Configuration Tags
 * @}
 */

/**
 * \addtogroup nfc_lib_config_tags NFC Library Configuration Tags
 * \ingroup nfc_lib
 * \brief These tags are used as \p bConfigTag2 parameter for #phNfcLib_SetConfig_Value2, #phNfcLib_SetConfig2 and #qpHNfCLib_GeTConfig2
 * @{
 */

/**
 * \brief NFC Lib error call-back function type.
 *
 * This callback will be called by /ref phNfcLib_Activate2 API in case of collision/transmission/protocol errors
 * during activation procedure in EMVCo mode only.
 * \note
 * Error that are reported are #PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2, #PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR2,
 * and #PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2.
 */
 typedef void (*pphNfcLib_ErrCallbck2)(VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2);
 
/**
 * end of group nfc_lib_config_tags NFC Library Configuration Tags
 * @}
 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
/**
 * \defgroup nfc_lib NXP NFC Library Top Level API
 * \ingroup grpsApi
 * \brief NXP NFC Library Top Level API
 *
 * \par General
 * This module provides an high level abstraction of the NXP NFC Reader Library stack, focusing on simplicity while featuring the
 * mostly used functionality. It aims to write NXP NFC applications requiring as less code as possible. Still there is the
 * possibility to use the legacy NXP NFC Reader Library stack API by calling #phNfcLib_GetDataParams2 in order to retrieve the
 * dataparams structure required when calling NXP NFC Reader Library stack functions.
 *
 * \par Activation and Transmission Channel
 * One of the main concepts of the NXP NFC Library module are the transmission channels. A transmission channel is a logical
 * connection between the device running the library and a peer. Once a peer could be activated this logical channel gets
 * established and subsequent calls to phNfcLib_Transmit2 and phNfcLib_Receive2 are performing transmissions over this channel.
 * In fact this channel defines how data sent over the channel gets encapsulated. There are three different channels available:
 * \li NFC Forum Channel: This channel is used to transfer NDEF messages
 * \li EMVCo Channel: This channel is used to transfer ISO 7816 APDUs over the ISO14443-4 protocol, according to EMVCo L1 specification.
 * \li ISO Channel: General channel which performs raw data transfer on block/frame level as defined in the corresponding protocols.
 * \sa For more information refer to phNfcLib_Transmit2, phNfcLib_Receive2 and phNfcLib_Activate2.
 *
 * \par NXP Nfc Library EMVCo State Machine
 * The NXP NFC Library module implements a state machine ensuring the API functions exposed are executed in the correct order and state.
 * \dot
  digraph host {
      reset [label="RESET"];
      init [label="INITIALIZED"];
      activated [label="ACTIVATED"];
      deactivation_ongoing [label="Deactivation_Ongoing"];
      reset -> init [label="phNfcLib_Init2" URL="\ref phNfcLib_Init" fontcolor="blue"];
      init -> reset [label="phNfcLib_DeInit2" URL="\ref phNfcLib_DeInit" fontcolor="blue"];
      init -> activated [label="PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2" URL="\ref phNfcLib_Activate2" fontcolor="blue"];
      activated -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      activated -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2) success" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      activated -> deactivation_ongoing [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2) failed" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      deactivation_ongoing -> deactivation_ongoing [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2) failed" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      deactivation_ongoing -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2) success" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      deactivation_ongoing -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      init -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
  }
  \enddot
 * \par NXP Nfc Library ISO State Machine
 * The NXP NFC Library module implements a state machine ensuring the API functions exposed are executed in the correct order and state.
 * \dot
  digraph host {
      reset [label="RESET"];
      init [label="INITIALIZED"];
      activated [label="ACTIVATED"];
      reset -> init [label="phNfcLib_Init2" URL="\ref phNfcLib_Init" fontcolor="blue"];
      init -> reset [label="phNfcLib_DeInit2" URL="\ref phNfcLib_DeInit" fontcolor="blue"];
      init -> activated [label="PHNFCLIB_STATUS_PEER_ACTIVATION_DONE" URL="\ref phNfcLib_Activate2" fontcolor="blue"];
      activated -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      activated -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
      init -> init [label="phNfcLib_Deactivate2\n(PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)" URL="\ref phNfcLib_Deactivate" fontcolor="blue"];
  }
  \enddot
 * Functions in this module are only allowed to be called in specific states, otherwise PH_NFCLIB_STATUS_INVALID_STATE2 an
 * error is returned
 * The \link nfc_lib_api API function description section\endlink provides information which state is required for each function to be called.
 *
 * \par Example Code for EMVCo polling application. (Activation and one APDU data exchange)
 * \code
 * #include <ph_Status.h>
 * #include <phNfcLib2.h>
 *
 * VAR(phNfcLib_Status_t2, ANFCRL_VAR) P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCApdu, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRApduLength)
 * {
 *    VAR(uint16, ANFCRL_VAR) wRfTechnos = PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_A2 | PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_B2;
 *    VAR(phNfcLib_Status_t2, ANFCRL_VAR) status2;
 *
 *    phNfcLib_Init2();
 *    /-/ set EMVCo Profile
 *    phNfcLib_SetConfig_Value2(PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2, PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2);
 *
 *    /-/ start activation. peerInfo2 set to NULL, we don't need detailed information
 *    status2 = phNfcLib_Activate2(wRfTechnos, NULL, NULL);
 *
 *    if (status2 == PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2)
 *    {
 *       status2 = phNfcLib_Transmit2(pCApdu, wCApduLength);
 *       status2 |= phNfcLib_Receive2(pRApdu, pRApduLength, NULL);
 *       phNfcLib_Deactivate2(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2, NULL);
 *    }
 *    else
 *    {
 *       /-/ could either be PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2 or PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2.
 *       /-/ In any case, inform user about it by escalating the error to the caller
 *    }
 *    return status2;
 * }
 * \endcode
 *
 * \par Example Code for Reading an NDEF record.
 * \code
 * #include <ph_Status.h>
 * #include <phNfcLib2.h>
 *
 * VAR(phNfcLib_Status_t2, ANFCRL_VAR) P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) aNdefMessage, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNdefMessageSize)
 * {
 *    VAR(uint16, ANFCRL_VAR) wRfTechnos = (PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_A2 | PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_14443_B2 |
 *                          PH_NFCLIB_TECHNOLOGY_INITIATOR_ISO_156932);
 *    VAR(phNfcLib_Status_t2, ANFCRL_VAR) status2;
 *
 *    phNfcLib_Init2();
 *
 *    /-/ set NXP NFC Profile
 *    phNfcLib_SetConfig_Value2(PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2, PH_NFCLIB_ACTIVATION_PROFILE_NFC2);
 *
 *    /-/ start activation. peerInfo2 set to NULL, we don't need detailed information
 *    status2 = phNfcLib_Activate2(wRfTechnos, NULL, NULL);
 *    if (status2 == PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2)
 *    {
 *       /-/ activation done, call phNfcLib_Receive2 to read the NDEF
 *       status2 = phNfcLib_Receive2(aNdefMessage, pNdefMessageSize, NULL);
 *       phNfcLib_Deactivate2(PH_NFCLIB_DEACTIVATION_MODE_RELEASE2, NULL);
 *    }
 *    else
 *    {
 *       /-/ could be PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2.
 *       /-/ In any case, inform user about it by escalating the error to the caller
 *    }
 *    return status2;
 * }
 * \endcode
 */

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * \defgroup nfc_lib_api NFC Library Functions
 * \ingroup nfc_lib
 * \brief All Public Functions of the NFC Library
 * @{
 */

/**
 *  \brief Used to set the application context to NFC Library before Initialization.
 *
 *  This function should be used before calling \ref phNfcLib_Init2 API.
 *  1. Used to provide the context of BAL Dataparams for HAL initializations.
 *  2. Used to provide the WTX Callback for PAL 14443-4mC initialization.
 *  3. Used to provide the RTOX Callback for PAL 18092mT initialization.
 *
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_SetContext2(
                                      phNfcLib_AppContext_t2 * pAppContext2     /**< [In] Pointers to phNfcLib_AppContext_t2 structure which provides the context to NFCLIB by Application. */
                                      );

/**
 *  \brief Initialize the NFC Library.
 *
 *  Calling this function initializes the NFC library including all its
 *  relevant protocol and hardware abstraction layers. It also calls the
 *  initialization functions for the underlying platform. After calling this
 *  function all other functions of the phNfcLib module may be used.
 *
 * \pre NFC library must be in state RESET
 * \post All APIs are allowed to be called. NFC Library is in state INITIALIZED
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
//FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_Ncx3321_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_PAL_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_AL_Init2(void);
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_DiscLoop_Sw_Init2(void);


/**
 * \brief Deinitialize the NFC Library
 *
 * Calling this function resets all internal structures to its default values, releases all allocated resources and
 * calls DeInit of all underlying layers.
 *
 * \pre NFC Library must be in state INITIALIZED
 * \post NFC Library is in state RESET. Only #phNfcLib_Init2 is allowed to be called.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_DeInit2(void);

#ifdef NXPBUILD__PHNFCLIB_PROFILES2
/**
 * \brief Run the Activation Procedure.
 *
 * This command starts the activation procedure which in fact implements a discovery loop. This loop performs technology detection
 * (for given technologies using bit mask \p wTechnologyMask2) and, if a technology has been detected, the activation with the
 * associated peer is performed.
 *
 * The activation procedure can be configured by calling #phNfcLib_SetConfig_Value2 or #phNfcLib_SetConfig2 and appropriate configuration
 * tags (see \ref nfc_lib_config_tags_activation), for instance #PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING2.
 * These configuration parameters influence the behavior of the activation procedure. The activation procedure also establishes a logical
 * channel which depends on the configured \ref activation_profile. This channel defines how data is being
 * encapsulated when calling phNfcLib_Transmit2 or phNfcLib_Receive2, respectively.
 *
 * Once a peer has been activated and a channel could be established \p peerInfo2 is set with \ref peer_info
 * about the peer and the established link. #phNfcLib_Transmit2 and #phNfcLib_Receive2 may then be used in order to perform data exchange
 * over the established link. In order to deactivate an activated peer/connection #phNfcLib_Deactivate2 has to be called.
 *
 * \note
 * \li The activation procedure will always try to resolve collisions (except for activation profile #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2).
 * So even if there a multiple peers in proximity (except in case of ISO156936), the activation procedure will activate
 * only one peer.
 * The priority (i.e. the order in which technology detection is performed) depends on the configured \ref activation_profile
 * and additionally on the configured \ref activation_prio
 * \li When polling for multiple technologies, activation procedure always uses bail out after first technology is detected and doesn't
 * poll further for other technologies.
 * \li When multiple tags/peers are detected, activation procedure uses different mechanism for each technology to resolve and activate
 * tag/peer.
 *    Type A : Collision resolution of Type A always resolves the tag with highest UID value,
 *    Type B : The first tag to reply to the slot marker command which can be any random tag will be activated
 *    ISO 15693 : In Type V, when single tag is placed in vicinity, tag will be moved to selected state using select command
 *             (TBD : If detected tag doesn't support Select command) and in case of multiple tags in vicinity, based on
 *             discovery loop #PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2 macro value collision will be resolved and
 *             #PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2 number of tag UID's in proximity are returned to User.
 * \li In case #PH_NFCLIB_ACTIVATION_PROFILE_NFC2 is configured as \ref activation_profile and underlying
 * protocol is ISO18092 this procedure also tries to perform LLCP activation in order to be able to transmit NDEF messages over SNEP
 * when using phNfcLib_Transmit2 and phNfcLib_Receive2.
 *
 * \pre NFC Library must be in state INITIALIZED or ACTIVATED
 * \post After successful activation (PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2) NFC library is in state ACTIVATED.
 *
 * \retval PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2
 * Activation procedure could activate a peer and establish a channel.
 * \p peerInfo2 holds detailed information about the peer and the associated connection.
 * \retval PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2
 * Activation procedure detected multiple peers in RF field based on the discovery loop macro #PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2
 * for Type V and these tag identifiers are returned to user as collision need not be resolved to communicate in case of
 * \ref activation_profile is ISO.
 * Detected a collision and was not able to resolve it in case of \ref activation_profile is EMVCo.
 * \retval PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2
 * Activation procedure detected a peer/technology but was not able to properly activate it. Example: #PH_NFCLIB_ACTIVATION_PROFILE_NFC2
 * is the configure profile but peer does not support LLCP.
 * \retval PH_NFCLIB_STATUS_NO_PEER_DISCOVERED2
 * In case activation procedure is configured for \ref activation_blocking non-blocking execution and no peer has been detected
 * within one iteration, activation returns with this status2 code.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Activate2(
                 VAR(uint16, ANFCRL_VAR) wTechnologyMask2,        /**< [In] A bit mask indicating all \ref nfc_lib_definitions_rf_techno
                                                            activation procedure shall handle during its discovery loop execution.*/
                 P2VAR(phNfcLib_PeerInfo_t2, AUTOMATIC, ANFCRL_APPL_DATA) peerInfo2 , /**< [Out] Pointer to a VAR(phNfcLib_PeerInfo_t, ANFVAR(phNfcLib_PeerInfo_t, ANFCRL_VAR) structure
                                                             with detailed information. */
                 pphNfcLib_ErrCallbck2  ErrCallbck2 /**< [In] Error callback specific to #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2 to intimate
                                                            about errors during polling for EMVCo. */
                 );

/**
 * \brief Send Data to an Activated Peer.
 *
 * Once a peer has been activated this function can be used to send data to the peer. The channel over which the data is sent to
 * the peer is defined by the configured \ref activation_profile .
 *
 * \note
 * \li Depending on the \ref activation_profile this function may block until a response has actually
 * been sent back by the peer. For instance #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2 requires acknowledgment from the peer for a sent frame,
 * so phNfcLib_Transmit2 will only return once this acknowledgment has been received.
 *
 * \par Behavior in NFC PROFILE
 *
 *  Behavior in case of \ref activation_profile is #PH_NFCLIB_ACTIVATION_PROFILE_NFC2
 * \li In case underlying protocol is ISO18092 this function acts as a SNEP client,  i.e. connecting to a server in order to push the NDEF record.
 * \li In case underlying protocol is ISO14443-4 host card emulation, this function is used to read the record of the NDEF emulation.
 *
 * \par  Behavior in ISO PROFILE
 *
 * Behavior in case of \ref activation_profile is #PH_NFCLIB_ACTIVATION_PROFILE_ISO2
 * \li In case detected card is MIFARE Ultralight, MIFARE Classic or MIFARE DESFire, input to phNfcLib_Transmit2 will be pointer of type
 * \ref nfc_lib_transmit_metadata. User needs to provide correct information in metadata to communicate with tags.
 *
 * \pre NFC Library must be in state ACTIVATED
 *
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * \p wTxBufferLength2 bytes given in \p pTxBuffer2 have been successfully sent to the peer.
 * \retval PH_NFCLIB_STATUS_BUFFER_OVERFLOW2
 * Received bytes could not be stored in NFCLIB buffer. User needs to call \ref phNfcLib_Receive2 API to copy data from NFCLIB
 * buffer to application and then call phNfcLib_Transmit2 API with \p pTxBuffer2 as NULL to receive next set of data.
 * \retval PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR2
 * Sent data not acknowledged in time.
 * \retval PH_NFCLIB_STATUS_RF_PEER_LOST2
 * Peer lost during communication.
 * \retval PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2
 * General RF protocol violation.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Transmit2(
                 CONSTP2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,     /**< [In] Byte array containing the data to be sent or \link phNfcLib_Transmit2 Metadata \endlink in ISO mode. */
                 VAR(uint16, ANFCRL_VAR) wTxBufferLength2    /**< [In] Number of bytes to be sent, in fact size of byte array or Zero in case Metadata is sent. */
                 );

/**
 * \brief Receive Data from an Activated Peer.
 *
 * This function can be called in order to receive data from an activated peer, in fact after #phNfcLib_Activate2 returned with status2
 * PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2. Like #phNfcLib_Transmit2, data received using this function may get decapsulated from underlying
 * protocol headers, depending on \ref activation_profile configured. See #phNfcLib_Transmit2 for more details.
 *
 * \note
 * \li Caller is responsible for implementing correct sequence of #phNfcLib_Transmit2 and #phNfcLib_Receive2. So depending
 * on the underlying protocol the two APIs have the be called alternately, starting with either transmit or receive, depending on the
 * underlying technology (initiator vs. target).
 * \li Similar to phNfcLib_Transmit2, in case PH_NFCLIB_ACTIVATION_PROFILE_NFC2 is the active \ref activation_profile and
 * underlying protocol is ISO18092 calling
 *
 * \par Behavior in case of NFC PROFILE
 *
 * Behavior in case of \ref activation_profile is #PH_NFCLIB_ACTIVATION_PROFILE_NFC2
 * \li In case underlying protocol is ISO18092 this API waits for receiving an NDEF message via SNEP (i.e. phNfcLib_Activate2 starts a SNEP
 * server and data received via that server socket can be read by this function).
 * \li In case underlying protocol is ISO14443-4 host card emulation, this function is used to write the record of the NDEF emulation.
 * \pre NFC Library must be in state ACTIVATED
 *
 * \sa phNfcLib_Transmit2
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * \p pNumberOfBytes2 bytes read from peer and stored in \p pRxBuffer2.
 * \retval PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR2
 * Timeout waiting for data from peer.
 * \retval PH_NFCLIB_STATUS_RF_PEER_LOST2
 * Peer lost during communication (for ISO18092 target and or active communication).
 * \retval PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2
 * General RF protocol violation.
 * \retval PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR2
 * Transmission error detected, e.g. RF integrity error.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 * \retval PH_NFCLIB_STATUS_BUFFER_OVERFLOW2
 * pMoreDataAvailable2 parameter is set to NULL and pRxBuffer2 is too small to receive all data.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Receive2(
                 CONSTP2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,  /**< [Out] Allocated byte array to which the received data has to be written. */
                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumberOfBytes2,   /**< [In,Out] Maximum receive size, in fact size of \p pRxBuffer2. On function return
                                                           it contains the actual number of bytes received.*/
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreDataAvailable2 /**< [Out] Set to 1, if not all data could be stored and phNfcLib_Receive2 needs to be
                                                        called again to receive the remaining data.
                                                        If all data could be received, this parameter is set to 0. If this parameter
                                                        is set to NULL and pRxBuffer2 is too small to receive all data,
                                                        PH_NFCLIB_STATUS_BUFFER_OVERFLOW2 is returned. */
                 );


/**
 * \brief Set Configuration Parameter
 *
 * This function is used to configure the phNfcLib module. It takes the parameter indicated by \p bConfigTag2 which
 * should be one of the \link nfc_lib_config_tags available configuration tags\endlink and sets it to the value given by \p pConfigParam2.
 *
 * \note
 * \li For pure integer parameter the helper function #phNfcLib_SetConfig_Value2 can be used instead.
 * \li phNfcLib_Init2 resets all configuration parameters to its default value.
 *
 * \pre NFC Library need to be in state INITIALIZED, i.e. after calling phNfcLib_Init2, phNfcLib_Deactivate2 or as long
 * as no activation happened.
 *
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * Parameter Value successfully set.
 * \retval PH_NFCLIB_STATUS_INVALID_PARAMETER2
 * Unknown configuration tag or wrong length given (\p wConfigParamLength2)
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_SetConfig2(
                 VAR(uint8, ANFCRL_VAR) bConfigTag2,             /**< [In] \link nfc_lib_config_tags A configuration tag\endlink indicating the parameter to set. */
                 P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pConfigParam2,    /**< [In] An array holding the value to be set for the given parameter. */
                 VAR(uint16, ANFCRL_VAR) wConfigParamLength2     /**< [In] Length of the parameter value, in fact length of \p pConfigParam2 */
                 );

/**
 * \brief Set Configuration Parameter using a Value
 *
 * Like #phNfcLib_SetConfig2 this function is used to configure the phNfcLib module.
 * All \link nfc_lib_config_tags configuration tags\endlink which take an unsigned integer as value can be set
 * using this function. In fact it's a convenient short cut for the actual #phNfcLib_SetConfig2
 * function, which does not require passing in a pointer in case only an integer value needs to be set.
 *
 * \note
 * \li phNfcLib_Init2 resets all configuration parameters to its default value.
 *
 * \pre NFC Library need to be in state INITIALIZED, i.e. after calling phNfcLib_Init2, phNfcLib_Deactivate2 or as long
 * as no activation happened for Activation configurations. In case of De-activation configuration NFC Library should
 * not be in state RESET state.
 *
 * \sa phNfcLib_SetConfig2
 *
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * Parameter Value successfully set.
 * \retval PH_NFCLIB_STATUS_INVALID_PARAMETER2
 * Unknown configuration tag.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_SetConfig_Value2(
                 VAR(uint8, ANFCRL_VAR) bConfigTag2,     /**< [In] \link nfc_lib_config_tags A configuration tag\endlink indicating the parameter to set. */
                 VAR(uint32, ANFCRL_VAR) dwValue2        /**< [In] The value which has to be set for parameter indicated by \p bConfigTag2 */
                 );

/**
 * \brief Retrieve a configuration parameter value
 *
 * This is the counterpart to #phNfcLib_SetConfig2, i.e. it can be used to read out the value for a given parameter.
 *
 * \sa phNfcLib_SetConfig2
 *
 * \pre NFC Library need to be in state INITIALIZED or ACTIVATED
 * as no activation happened.
 *
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * Parameter Value successfully read out.
 * \retval PH_NFCLIB_STATUS_INVALID_PARAMETER2
 * Unknown configuration tag or provided buffer too small.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) qpHNfCLib_GeTConfig2(
                 VAR(uint8, ANFCRL_VAR) bConfigTag2,             /**< [In] \link nfc_lib_config_tags A configuration tag\endlink indicating the parameter whose value needs to be read out. */
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pConfigParam2,          /**< [Out] Allocated byte array to which the read out value will be written to. */
                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pConfigParamLength2   /**< [In,Out] Size of \p pConfigParam2. On function return, it holds the actual number of bytes read. */
                 );

/**
 * \brief Deactivate an Activated Peer.
 *
 * The deactivation procedure can be configured by calling #phNfcLib_SetConfig_Value2 with configuration tag \ref De-activation_blocking.
 * This configuration parameter influence the behavior of the deactivation procedure only in EMVCo profile.
 *
 * After a peer has been activated using #phNfcLib_Activate2 and the caller wants to release it again (e.g. after communication
 * sequences using #phNfcLib_Transmit2 and #phNfcLib_Receive2 have been finished) this API has to be called.
 * Depending on \a bDeactivateMode2 parameter the peer gets released using defined release procedure according to the
 * \ref activation_profile. This for instance could indicate if the removal procedure should
 * be performed for #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2. In ISO profile, deactivation procedures like HLTA, HLTB, DSL_REQ etc is performed and
 * allows starting a new \link phNfcLib_Activate2 activation procedure\endlink.
 * To releases all RF related resources this function should be called with \a bDeactivateMode2 parameter as #PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2.
 * If Deactivation with \a bDeactivateMode2 parameter as #PH_NFCLIB_DEACTIVATION_MODE_RELEASE2 fails due to card being removed out of proximity
 * or due to some RF irregularity the user may call Deactivation with \a bDeactivateMode2 parameter as #PH_NFCLIB_DEACTIVATION_MODE_RELEASE2 again
 * or Deactivation with \a bDeactivateMode2 parameter as #PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2 according to the scenario requirements.
 *
 * \pre NFC Library must be in state ACTIVATED
 * \post NFC Library is in state INITIALIZED
 * \retval PH_NFCLIB_STATUS_SUCCESS2
 * Peer successfully deactivated and released.
 * \retval PH_NFCLIB_STATUS_INVALID_STATE2
 * NFC Library had been in a wrong state when calling this function.
 * \retval PH_NFCLIB_STATUS_PEER_DEACTIVATION_FAILED2
 * Peer deactivation is not successful (this error code is returned only when config \ref De-activation_blocking is set to PH_OFF2).
 * Internal state move to Deactivation Ongoing State. #phNfcLib_Deactivate2 has to be called in loop to check if peer deactivation is successful.
 */
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Deactivate2(
                 VAR(uint8, ANFCRL_VAR) bDeactivateMode2,         /**< [In] Deactivation mode/behavior.
                                                    Refer to \ref nfc_lib_definitions_deactivation_mode
                                                    for more information. */
                 phNfcLib_PeerInfo_t2 * peerInfo2   /**< [In] Pointer to a phNfcLib_PeerInfo_t structure updated by /ref phNfcLib_Activate2 API. */
                 );

/**
 * \brief Used to asynchronously stop HAL waiting for RF event and exit from HAL.
 *
* Note: This function will post an 'abort' event which is used by the HAL to move into 'Idle' state and exit from polling for RF Event.
* The functions that were waiting for a HAL event will return #PH_ERR_ABORTED error code once this function is executed.
*
* This function shall be called in a task other than the task where reader library is running.
* This API can be called at any time after the phNfcLib_Init2(); and any of the NFCLIB operations like transmit and receive are in progress.
*
* \retval PH_NFCLIB_STATUS_SUCCESS2
* Operation successful.
*/
FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_AsyncAbort2(void);

#endif /* NXPBUILD__PHNFCLIB_PROFILES2 */

/**
 * \brief Retrieve the pointer to the dataparams structure of an internal NFC Reader Library component.
 *
 * The NfcLib encapsulates all relevant NFC Reader Library components. In case a caller needs to directly access one of the components
 * a pointer to the dataparams is required. This function returns the pointer to the dataparams structure of the component
 * indicated with \p wComponent2.
 * \par Example
 * \code
 * phNfcLib_Init2();
 * /-/ manually switch on the RF field
 * phhalHw_FieldOn(phNfcLib_GetDataParams2(PH_COMP_HAL2));
 * \endcode
 *
 * \return Pointer to the component's dataparams structure. NULL in case phNfcLib is not managing the component indicated by \p wComponent2
 * or NFC library is in state RESET.
 */
FUNC(void*, ANFCRL_CODE) phNfcLib_GetDataParams2(
                 VAR(uint16, ANFCRL_VAR) wComponent2     /**< [In] The component ID for which the data params pointer should be returned. For possible value refer to ph_Status.h, PH_COMP_* */
                 );

/**
 * end of group nfc_lib_api NFC Library Functions
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB2 */

#ifdef __cplusplus
}
#endif
#endif  /* PH_NFCLIB2_H */
