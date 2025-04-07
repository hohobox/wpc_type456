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
*   @file    phCryptoSym_Sw_Des.h
*   @version 1.0.0
*
*   @brief   AUTOSAR CryptoSym - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phCryptoSym CryptoSym
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
#ifndef PHCRYPTOSYM_SW_DES_H
#define PHCRYPTOSYM_SW_DES_H

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
#include <ph_RefDefs.h>
#include <phCryptoSym.h>
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym_Sw_Des.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_DES_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_DES_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_DES_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_DES_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_DES_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_DES_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_DES_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym_Sw_Des.h and AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Des.h and AnfcRL_Cfg.h are different"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_DES_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Des.h and AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/


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
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* \brief Software implementation of the DES algorithm
* @{
*/

/**
* \brief Performs a decryption of a DES Block (8 byte) using a DES Key.
* The key needs to be provided in the pDataParams structure. By specifying the bKeyNumber, either the
* first, the second or the third key is used.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_DecryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,   /**< [InOut] Block to be enciphered in place. */
    VAR(uint8, ANFCRL_VAR) bKeyNumber                          /**< [In] Number of the key to be used (0, 1 or 2) */
    );

/**
* \brief Performs an encryption of a DES Block (8 byte) using a DES Key.
* The key needs to be provided in the pDataParams structure. By specifying the bKeyNumber, either the
* first, the second or the third key is used.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_EncryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,   /**< [InOut] Block to be enciphered in place. */
    VAR(uint8, ANFCRL_VAR) bKeyNumber                          /**< [In] Number of the key to be used (0, 1 or 2) */
    );

/**
* \brief Performs the key Expansion of the DES key(s)
* According to the number of keys specified, the pDataParams key array is filled up in the following sequence:
* Expanded KEY1 [128] || Expanded KEY2 [128] || Expanded KEY3 [128]
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_KeyInit(
                                      P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers parameter structure. */
                                      P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,                         /**< [In] Key array to be loaded into the DES engine. */
                                      VAR(uint8, ANFCRL_VAR) bNumKeys                              /**< [In] Amount of keys provided (1, 2 or 3) */
                                      );

/**
* \brief Decode the KeyVersion of a DES key.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_DecodeVersion(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,         /**< [In] Key to decode. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion  /**< [Out] Version of the key. */
    );

/**
* \brief Encode the KeyVersion in a DES key.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Operation aborted.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Des_EncodeVersion(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,         /**< [In] Key to encode. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion,   /**< [In] Version of the key. */
    VAR(uint16, ANFCRL_VAR) wKeyType,      /**< [In] Type of Key. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncodedKey   /**< [Out] Encoded key. */
    );
/**
* end of group ph_Private (Private definitions)
* @}
*/
#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_DES_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_DES_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_SW_DES_H */
