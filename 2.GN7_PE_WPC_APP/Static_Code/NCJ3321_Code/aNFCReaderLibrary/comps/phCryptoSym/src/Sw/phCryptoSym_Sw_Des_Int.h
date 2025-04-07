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
*   @file    phCryptoSym_Sw_Des_Int.h
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
#ifndef PHCRYPTOSYM_SW_DES_INT_H
#define PHCRYPTOSYM_SW_DES_INT_H

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
* @file           phCryptoSym_Sw_Des_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_DES_INT_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_DES_INT_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_DES_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_DES_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_DES_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_DES_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym_Sw_Des_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Des_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_DES_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_DES_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Des_Int.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MINOR_VERSION == 0))
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
* \brief Compute a permutation as defined in table IP in section Enciphering of FIPS46.3.
* The implementation is chosen such that the trade off between ROM usage and execution
* performance is optimum for (small) uC architectures. For implementation details refer to
* the detailed documentation inside of the function body.
* \return None
*/
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_Permutate_IP(
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateIn, /**< [In] State pointer containing the initial state. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateOut /**< [Out] State pointer containing the permutate state. */
                                      );

/**
* \brief Compute a permutation as defined in table IP-1 (inverse IP) in section Enciphering of FIPS46.3.
* The implementation is chosen such that the trade off between ROM usage and execution
* performance is optimum for (small) uC architectures. For implementation details refer to
* the detailed documentation inside of the function body.
* \return None
*/
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_Permutate_IP_Inv(
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateIn, /**< [In] State pointer containing the computed state. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pStateOut /**< [Out] State pointer containing the final state. */
    );

/**
* \brief Compute a permutation as defined in table PC1 of Appendix 1 of FIPS46.3.
* The implementation is chosen such that the trade off between ROM usage and execution
* performance is optimum for (small) uC architectures. For implementation details refer to
* the detailed documentation inside of the function body.
* \return None
*/
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_PC1_Permutation(
    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKeyIn,                 /**< [In] key pointer containing the original key. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKeyOut  /**< [Out] key  pointer containing the permutate key. */
    );

/**
* \brief Compute a permutation as defined in table PC2 of Appendix 1 of FIPS46.3.
* The implementation is chosen such that the trade off between ROM usage and execution
* performance is optimum for (small) uC architectures. For implementation details refer to
* the detailed documentation inside of the function body.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_PC2_Permutation(
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pKeyIn,  /**< [In] round key pointer containing the input. */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeyOut                       /**< [Out] round key  pointer containing the output. */
                                        );

/**
* \brief Rotates (bitwise) a four byte array to the left by bNumPos positions.
* Note: Only the first 28 bits are rotated through, in other words, bits 4-7 of byte 3 are untouched
* \return None
*/
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_RotateLeft28(
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pArray,  /**< [InOut] 4 Byte array to be rotated. */
                                      VAR(uint8, ANFCRL_VAR) bNumPos                         /**< [In] Amount of positions (bits) to rotate through. */
                                      );
#ifdef PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
/**
* \brief Rotates (bitwise) a four byte array to the right by bNumPos positions.
* Note: Only the first 28 bits are rotated through, in other words, bits 4-7 of byte 3 are untouched
* \return None
*/
FUNC(void, ANFCRL_CODE)  phCryptoSym_Sw_Des_RotateRight28(
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pArray,  /**< [InOut] 4 Byte array to be rotated. */
                                       VAR(uint8, ANFCRL_VAR) bNumPos                         /**< [In] Amount of positions (bits) to rotate through. */
                                       );
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */
/**
* \brief Performs the cipher function F as described in chapter "The Cipher Function f" of FIPS46.3.
* The 32 bit input pR is expanded, XORed with the key, looked up using the SBOX and finally permutate according to
* the standard of the DES algorithm
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_F(
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pR,  /**< [InOut] 4 Byte array to be ciphered. */
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRoundKey                 /**< [In] 8 bytes (containing 48 bits) round key used for XORing. */
                          );

/**
* \brief Performs a round as described in Figure 1. Enciphering computation. of FIPS46.3.
* The 8 byte input is first split into two parts, namely L and R. On R, the function F is executed,
* and then finally the result is xored to L.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_ComputeRound(
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pState,  /**< [InOut] 8 bytes state to compute the round on. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRoundKey                     /**< [In] 8 bytes (containing 48 bits) round key used for XORing. */
                                     );
/**
* \brief Expands the 32 bit input to generate a 48 bit output according to E-Selection Table. of FIPS46.3.
* The 4 byte input is expanded to create a 8 byte output containing 6 bits of expanded data in the individual bytes.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_Expand(
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pR,   /**< [In] 4 Bytes of input Data. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pRexp /**< [Out] 8 bytes (containing 48 bits) of expanded data. */
                               );

/**
* \brief Take an array of length 8, put bState[0:3] to bState[4:7] and vice versa.
* \return None
*/
FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_Des_Swap(
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM bState /**< [InOut] State to be swapped. */
                             );
/**
* end of group ph_Private (Private definitions)
* @}
*/
#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_SW_DES_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_SW_DES_INT_H */