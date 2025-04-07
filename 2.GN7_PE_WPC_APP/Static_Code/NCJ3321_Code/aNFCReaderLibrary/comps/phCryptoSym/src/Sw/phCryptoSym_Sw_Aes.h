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
*   @file    phCryptoSym_Sw_Aes.h
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
#ifndef PHCRYPTOSYM_SW_AES_H
#define PHCRYPTOSYM_SW_AES_H

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
* @file           phCryptoSym_Sw_Aes.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_AES_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_AES_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_SW_AES_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_AES_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_AES_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_AES_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_AES_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_AES_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_AES_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym_Sw_Aes.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_AES_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Aes.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_AES_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Aes.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHCRYPTOSYM_SW_AES_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_AES_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* \brief Software implementation of the AES algorithm
* @{
*/

/**
* \brief Performs the key Expansion of the AES key (128, 192, 256 bits).
* According to the size of the key specified, the pDataParams key array is filled up in the following sequence:
* pKey || pRk1 ..... ||pRkN
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Aes_KeyExpansion(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,                       /**< [In] Key array to be loaded into the AES engine. */
    VAR(uint8, ANFCRL_VAR) bNkCurrent,                         /**< [In] Size of the key provided (in 32 bit granularity). */
    VAR(uint8, ANFCRL_VAR) bNkMax                              /**< [In] Total amount of 32 bit Values to be loaded. */
    );

/**
* \brief Performs a encryption of an AES Block (16 byte) using an AES Key.
* The key needs to be provided in the pDataParams structure. By specifying the bNumRounds, the amount of AES rounds to be executed is defined.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Aes_EncryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,   /**< [InOut] Block to be enciphered in place. */
    VAR(uint8, ANFCRL_VAR) bNumRounds                          /**< [In] Number of rounds according to AES algorithm. */
    );

/**
* \brief Performs a decryption of an AES Block (16 byte) using an AES Key.
* The key needs to be provided in the pDataParams structure. By specifying the bNumRounds, the amount of AES rounds to be executed is defined.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Aes_DecryptBlock(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock,   /**< [InOut] Block to be deciphered in place. */
    VAR(uint8, ANFCRL_VAR) bNumRounds                          /**< [In] Number of rounds according to AES algorithm. */
    );
/**
* end of group ph_Private (Private definitions)
* @}
*/

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_AES_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_AES_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_SW_AES_H */
