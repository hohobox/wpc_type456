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
*   @file    phCryptoRng_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR CryptoRng - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phCryptoRng CryptoRng
*   @ingroup phcommon
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
#ifndef PHCRYPTORNG_SW_INT_H
#define PHCRYPTORNG_SW_INT_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status.h>
#include <Compiler.h>
#include <phCryptoRng.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoRng_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTORNG_SW_INT_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTORNG_SW_INT_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTORNG_SW_INT_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTORNG_SW_INT_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTORNG_SW_INT_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTORNG_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTORNG_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTORNG_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTORNG_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoRng_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTORNG_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTORNG_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTORNG_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoRng_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTORNG_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTORNG_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTORNG_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoRng_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup phCryptoRng_Sw_Internals Internals
* \ingroup phCryptoRng
* \brief Software implementation of the RND Generator
*  @{
*/
/* Note: according to NIST SP800-90 for AES this is 2^48, for TDEA it would be 2^32, for storage
reasons the limit is set to 2^32 in this particular implementation. */
#define PHCRYPTORNG_SW_MAX_REQUESTS 0xFFFFFFFFU

/**
* \brief Block Length for the cipher used.
*/
#define PHCRYPTORNG_SW_OUTLEN   16U

/**
* \brief Block Length for the cipher used.
*/
#define PHCRYPTORNG_SW_KEYLEN   16U

/**
* \brief Seed length to be provided.
*/
#define PHCRYPTORNG_SW_SEEDLEN  (PHCRYPTORNG_SW_OUTLEN + PHCRYPTORNG_SW_KEYLEN)
#define PHCRYPTORNG_SW_MAX_BITS_DF_FUNCTION   512U

#define PHCRYPTORNG_SW_STATE_INIT       0x00U /* Default State */
#define PHCRYPTORNG_SW_STATE_WORKING    0x01U /* Working State */

/**
 * end of group phCryptoRng_Sw_Internals Internals
 * @}
 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTORNG_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phCryptoRng_Sw_Internals Internals
* \ingroup phCryptoRng
* \brief Software implementation of the RND Generator
*  @{
*/

/**
* \brief Implements the update function according to NIST SP800-90 section 10.2.1.2.
* Using provided data generated in one of #phCryptoRng_Sw_Instantiate, #phCryptoRng_Sw_Reseed
* and #phCryptoRng_Sw_Generate function the values of pDataParams->V and the key loaded in the
* AES module are updated.
* Provided data can be null, if this is the case, no XOR is performed. This is not for
* use during Instantiate functionality!.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_Update(
                                 P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProvidedData                    /**< [In] Provided data of length #PHCRYPTORNG_SW_SEEDLEN and
                                                                                generated using #phCryptoRng_Sw_Instantiate, #phCryptoRng_Sw_Reseed
                                                                                and #phCryptoRng_Sw_Generate function (can be NULL). */
                                 );

/**
* \brief Implements the instantiate function according to NIST SP800-90 section 10.2.1.3.2 (using derivation function).
* Note: the length of all inputs together needs to be exactly #PHCRYPTORNG_SW_SEEDLEN
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_Instantiate(
                                P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEntropyInput,                    /**< [In] Entropy input of size bEntropyInputLength. */
                                VAR(uint16, ANFCRL_VAR) wEntropyInputLength,               /**< [In] Length of the entropy input. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNonce,                           /**< [In] Nonce as specified in Section 8.6.7. of NIST SP800-90. */
                                VAR(uint8, ANFCRL_VAR) bNonceLength,                       /**< [In] Length of the nonce provided. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPersonalizationString,           /**< [In] Personalization string of size bPersonalizationString. */
                                VAR(uint8, ANFCRL_VAR) bPersonalizationString              /**< [In] Length of the Personalization string. */
                                );

/**
* \brief Implements the reseed function according to section 10.2.1.4.2 (using derivation function).
* Note: the length of all inputs together needs to be exactly #PHCRYPTORNG_SW_SEEDLEN
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_Reseed(
                                P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEntropyInput,                    /**< [In] Entropy input of size bEntropyInputLength. */
                                VAR(uint16, ANFCRL_VAR) wEntropyInputLength,               /**< [In] Length of the entropy input. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAdditionalInput,                 /**< [In] Additional Input. */
                                VAR(uint8, ANFCRL_VAR) bAdditionalInputLength              /**< [In] Length of Additional Input provided. */
                                );

/**
* \brief Implements the generate function according to section 10.2.1.5.2 (using derivation function).
* Note: the length of the additional input needs to be exactly #PHCRYPTORNG_SW_SEEDLEN.
* If an application does not support additional input, the pointer has to be set to NULL.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_Generate(
                                P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAdditionalInput,                 /**< [In] Additional Input can be NULL). */
                                VAR(uint16, ANFCRL_VAR) wNumBytesRequested,                /**< [In] Amount of bytes requested. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndBytes                         /**< [Out] Random bytes generated. */
                                );

/**
* \brief Implements the BlockCipherDf according to NIST SP800-90 section 10.4.2.
* Note: inside there are 10 encryptions performed. Although this takes quite some time, the implication on
* overall system performance is rather low as this function is only called at startup and during reseeding.
* Note: The input string needs to be exactly #PHCRYPTORNG_SW_SEEDLEN bytes.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_BlockCipherDf(
                                P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,	/**< [In] Pointer to this layers parameter structure. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIoString 							/**< [InOut] pIoString of PHCRYPTORNG_SW_SEEDLEN bytes - contains input data and later output data. */
                                );

/**
 * end of group phCryptoRng_Sw_Internals Internals
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTORNG_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /* PHCRYPTORNG_SW_INT_H */
