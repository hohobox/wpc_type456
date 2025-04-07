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
*   @file    phCryptoSym_Sw_Int.h
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
#ifndef PHCRYPTOSYM_SW_INT_H
#define PHCRYPTOSYM_SW_INT_H

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
#include <phCryptoSym.h>
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_INT_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_INT_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/* CMAC Key diversification method defines */
#define PH_CRYPTOSYM_SW_KDIV_MFP_AES128_CONST       0x01U
#define PH_CRYPTOSYM_SW_KDIV_MFP_AES192_CONST_1     0x11U
#define PH_CRYPTOSYM_SW_KDIV_MFP_AES192_CONST_2     0x12U
#define PH_CRYPTOSYM_SW_KDIV_MFP_3DES_CONST_1       0x21U
#define PH_CRYPTOSYM_SW_KDIV_MFP_3DES_CONST_2       0x22U
#define PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_1   0x31U
#define PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_2   0x32U
#define PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_3   0x33U
#define PH_CRYPTOSYM_SW_KDIV_MFP_DIVLENGTH_AES_MAX  31U
#define PH_CRYPTOSYM_SW_KDIV_MFP_DIVLENGTH_DES_MAX  15U

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
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* \brief Internal Functions of the Symmetric Cryptography component.
* @{
*/

/**
* \brief Generic interface function for encryption of a single AES/DES data block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Unknown key type currently loaded.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_EncryptBlock(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock     /**< [InOut] IO buffer for the data block to perform the encryption on. */
                                       );

/**
* \brief Generic interface function for decryption of a single AES/DES data block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Unknown key type currently loaded.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_DecryptBlock(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock     /**< [InOut] IO buffer for the data block to perform the decryption on. */
                                       );

/**
* \brief Implements the left shift according to CMAC standard.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_CMAC_LeftShift(
                                   P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pInBuffer,   /**< [In] Array containing the input buffer to be shifted. */
                                   VAR(uint8, ANFCRL_VAR) bInputLen,           /**< [In] Length of the input buffer. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer         /**< [Out] Array containing the output buffer where the shifted value is stored. */
                                   );
/**
* \brief Implements sub key generation according to CMAC standard.
* Implementation according to SUBK(K) section 6 of NIST SP_800-38B
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INTERNAL_ERROR Unsupported block length.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_CMAC_GenerateK1K2(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey1,                         /**< [Out] Destination pointer for CMAC subkey 1 */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey2                          /**< [Out] Destination pointer for CMAC subkey 2 */
    );

/**
* \brief Calculate CMAC for Key diversification
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER wDataLength is larger than double the current block size.
* \retval #PH_ERR_INVALID_PARAMETER An unsupported key is loaded (or no key is loaded).
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Diversify_CMAC(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pData,                      /**< [In] Input data; uint8[wDataLength]. */
    VAR(uint16, ANFCRL_VAR) wDataLength,                      /**< [In] Number of input data bytes. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac,                             /**< [Out] Output MAC block; uint8[16]. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMacLength                        /**< [Out] Length of MAC. */
    );
/**
* end of group ph_Private (Private definitions)
* @}
*/

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_SW_INT_H */
