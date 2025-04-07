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
*   @file    phCryptoSym_Sw_Aes_Int.h
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
#ifndef PHCRYPTOSYM_SW_AES_INT_H
#define PHCRYPTOSYM_SW_AES_INT_H

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
* @file           phCryptoSym_Sw_Aes_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_AES_INT_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_AES_INT_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_AES_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_AES_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_AES_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_AES_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym_Sw_Aes_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Aes_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_AES_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_AES_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Aes_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
#define PH_CRYPTOSYM_KEYSCHEDULE_ENCRYPTION 0x0FU
#define PH_CRYPTOSYM_KEYSCHEDULE_DECRYPTION 0xC0U
#define PH_CRYPTOSYM_KEYSCHEDULE_DECRYPTION_PREPARE 0x30U
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
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
#if ((PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MINOR_VERSION == 0))
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
* \brief Performs the combined SubBytes and Shift Rows step of the AES Algorithm for encryption as defined in Chap. 5.1.1, 5.1.2 of FIPS-197.
* First Row remains untouched, second row is shifted by 1 pos, third row is shifted by 2 pos, fourth row is shifted by 3 pos.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_SubBytesShiftRows(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState    /**< [InOut] 16 byte array containing the state to operate on */
    );

/**
* \brief Performs the combined SubBytes and Shift Rows step of the AES Algorithm for encryption as defined in Chap. 5.3.1, 5.3.2 of FIPS-197.
* First Row remains untouched, second row is shifted by 3 pos, third row is shifted by 2 pos, fourth row is shifted by 1 pos.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_InvSubBytesShiftRows(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState    /**< [InOut] 16 byte array containing the state to operate on */
    );

/**
* \brief Performs the MixColumn step of the AES Algorithm for encryption as defined in Chap. 5.1.3 of FIPS-197.
* The input bytes are multiplied as specified in the algorithm. The compile flag #PH_CRYPTOSYM_SW_ROM_OPTIMIZATION
* specifies whether all values to be multiplied with are taken from the lookup tables phCryptoSym_Sw_Aes_times2 and
* phCryptoSym_Sw_Aes_times3 or if phCryptoSym_Sw_Aes_times3 is calculated out of the XOR of phCryptoSym_Sw_Aes_times2 and
* the relevant value itself.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_MixColumns(
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState /**< [InOut] 16 byte array containing the state to operate on */
                                   );


/**
* \brief Performs the MixColumn step of the AES Algorithm for encryption as defined in Chap. 5.3.3 of FIPS-197.
* The input bytes are multiplied as specified in the algorithm. The compile flag #PH_CRYPTOSYM_SW_ROM_OPTIMIZATION
* specifies whether all values to be multiplied with are taken from the lookup tables phCryptoSym_Sw_Aes_times9,
* phCryptoSym_Sw_Aes_timesB, phCryptoSym_Sw_Aes_timesD and phCryptoSym_Sw_Aes_timesE or if the following simplification are used:
* phCryptoSym_Sw_Aes_timesD = phCryptoSym_Sw_Aes_timesC XOR the value itself
* phCryptoSym_Sw_Aes_timesE = phCryptoSym_Sw_Aes_timesC XOR phCryptoSym_Sw_Aes_times2
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_InvMixColumns(
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState  /**< [InOut] 16 byte array containing the state to operate on */
                                      );

/**
* \brief Performs the AddRoundKey step of the AES Algorithm for encryption and decryption as defined in Chap. 5.1.4 and 5.3.4 of FIPS-197.
* The input state is XORed with the relevant round key.
* There are two compile options that come together with AddRoundKey:
*
* #PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING is not defined:
*   In that case, the round keys have been calculated already upfront in the phCryptoSym_Sw_Aes_KeyExpansion function. The round keys are stored in
*   pDataParams->pKey using the following framing:
*   ORIGINAL KEY || RK1 || RK2 || ... || RKn
*   In total, there are a maximum of 14 Round keys + the original key = 13*16 + 32 = 240 bytes
*   Thus, the function simply picks the correct 16 byte chunk out of the round keys according to the bCnt provided.
*
* #PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING is defined:
*   In that case, the round keys are calculated online.
*   The pDataParams->pKey array has a size of 32 bytes in that case. This key is copied into a local 32 bytes buffer,
*   which then is provided to the AddRoundKey function to always update the next 16 bytes of round key according to the
*   algorithm. There are three options available for that function:
*   - PH_CRYPTOSYM_KEYSCHEDULE_ENCRYPTION: Increments pNkCurrent
*   - PH_CRYPTOSYM_KEYSCHEDULE_DECRYPTION: Decrements pNkCurrent
*   - PH_CRYPTOSYM_KEYSCHEDULE_DECRYPTION_PREPARE: Increments pNkCurrent, but does not perform a XOR operation with the state.
* \return None
*/
#ifndef PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_AddRoundKey(
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState,   /**< [InOut] 16 byte array containing the state to operate on */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_BUF pKey,           /**< [In] 240 byte array containing all round keys to be used. */
                                    VAR(uint8, ANFCRL_VAR) bCnt                            /**< [In] Current round. Used by the function to pick the correct round key*/
                                    );
#else /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Aes_AddRoundKey(
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState,   /**< [InOut] 16 byte array containing the state to operate on */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKey,     /**< [In] 32 byte array containing the current round key buffer. */
                                    /**< NOTE: always the same buffer has to be applied within one encryption.  */
                                    /**< NOTE: if this is the original key buffer, the key is overwritten!. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNkCurrent,                       /**< [In] Current Nk value. (= numCurRound*4U) */
                                    VAR(uint8, ANFCRL_VAR) bNk,                                /**< [In] Nk for the currently loaded key type. AES128: 4, AES192: 6, AES256: 8 */
                                    VAR(uint8, ANFCRL_VAR) bMode                               /**< [In] Option byte indicating whether we have encryption, decryption or key preparation. */
                                    );
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

/**
* end of group ph_Private (Private definitions)
* @}
*/
#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_AES_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_SW_AES_INT_H */
