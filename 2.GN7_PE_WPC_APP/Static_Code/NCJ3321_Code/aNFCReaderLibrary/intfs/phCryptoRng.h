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
*   @file    phCryptoRng.h
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

#ifndef PHCRYPTORNG_H
#define PHCRYPTORNG_H

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
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoRng.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTORNG_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTORNG_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTORNG_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTORNG_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTORNG_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTORNG_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTORNG_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTORNG_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoRng.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTORNG_AR_RELEASE_MINOR_VERSION     != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTORNG_AR_RELEASE_REVISION_VERSION  != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoRng.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTORNG_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTORNG_SW_MINOR_VERSION  != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTORNG_SW_PATCH_VERSION  != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoRng.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @}*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTORNG_SW
/** \defgroup phCryptoRng_Sw Component : Software
* \ingroup phCryptoRng
* \brief Software implementation of the phCryptoRng interface
*
* The following standard is implemented:
* - NIST Special Publication 800-90: CTR_DRBG
*
* Architecture overview of the phCryptoRng_Sw Component
* - The AES 128 implementation of the phCryptoSym component is used to generate random numbers.
* - This phCryptoSym instance has to be properly instantiated before generation of random numbers is possible.
* - The phCryptoRng_Sw_Int block implements all functions required by the NIST standard.
* - According to the state of the library component, the seed function choses whether to use phCryptoRng_Sw_Instantiate or phCryptoRng_Sw_Reseed.
* - phCryptoRng_Sw_Update is automatically called when random numbers are generated in order to be ready for retrieving the next chunk of
* random bytes.
* - phCryptoRng_Sw_BlockCipherDf is used to derive the key and V-value for a given seed.
* @{
*/

#define PH_CRYPTORNG_SW_ID             0x01U    /**< ID for Software crypto rng component. */

/**
 * end of group phCryptoRng_Sw Component : Software
 * @}
 */
#endif /*NXPBUILD__PH_CRYPTORNG_SW*/
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTORNG_SW
/** \addtogroup phCryptoRng_Sw Component : Software
* \ingroup phCryptoRng
* \brief Software implementation of the phCryptoRng interface
*
* The following standard is implemented:
* - NIST Special Publication 800-90: CTR_DRBG
*
* Architecture overview of the phCryptoRng_Sw Component
* - The AES 128 implementation of the phCryptoSym component is used to generate random numbers.
* - This phCryptoSym instance has to be properly instantiated before generation of random numbers is possible.
* - The phCryptoRng_Sw_Int block implements all functions required by the NIST standard.
* - According to the state of the library component, the seed function choses whether to use phCryptoRng_Sw_Instantiate or phCryptoRng_Sw_Reseed.
* - phCryptoRng_Sw_Update is automatically called when random numbers are generated in order to be ready for retrieving the next chunk of
* random bytes.
* - phCryptoRng_Sw_BlockCipherDf is used to derive the key and V-value for a given seed.
* @{
*/
 
/**
* \brief Software parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                   /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams;       /**< Data parameter structure for the AES engine */
    VAR(uint8, ANFCRL_VAR) V[16];
    VAR(uint32, ANFCRL_VAR) dwRequestCounter;      /**< Counts the amount of requests between two seeding procedures.
                                    Note: according to NIST SP800-90 for AES this is 2^48, for storage
                                    reasons the limit is set to 2^32 in this particular implementation. */
    VAR(uint8, ANFCRL_VAR) bState;
} phCryptoRng_Sw_DataParams_t;

/**
 * end of group phCryptoRng_Sw Component : Software
 * @}
 */
#endif /*NXPBUILD__PH_CRYPTORNG_SW*/
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTORNG_SW

#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phCryptoRng_Sw Component : Software
* \ingroup phCryptoRng
* \brief Software implementation of the phCryptoRng interface
*
* The following standard is implemented:
* - NIST Special Publication 800-90: CTR_DRBG
*
* Architecture overview of the phCryptoRng_Sw Component
* - The AES 128 implementation of the phCryptoSym component is used to generate random numbers.
* - This phCryptoSym instance has to be properly instantiated before generation of random numbers is possible.
* - The phCryptoRng_Sw_Int block implements all functions required by the NIST standard.
* - According to the state of the library component, the seed function choses whether to use phCryptoRng_Sw_Instantiate or phCryptoRng_Sw_Reseed.
* - phCryptoRng_Sw_Update is automatically called when random numbers are generated in order to be ready for retrieving the next chunk of
* random bytes.
* - phCryptoRng_Sw_BlockCipherDf is used to derive the key and V-value for a given seed.
* @{
*/

/**
* \brief Initialize the CryptoRng component.
*
* For seeding, the following considerations have to be taken:
* - Take a seed of at 32 bytes, which consists of
*   - entropy input
*   - nonce
*   - personalization string.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Sw_Init(
                            P2VAR(phCryptoRng_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                            VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                /**< [In] Specifies the size of the data parameter structure. */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams                   /**< [In] Pointer to the parameter structure of the symmetric crypto layer. */
                            );

/**
 * end of group phCryptoRng_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif 

#endif /* NXPBUILD__PH_CRYPTORNG_SW */


#ifdef NXPBUILD__PH_CRYPTORNG

#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \defgroup phCryptoRng CryptoRng
* \ingroup phcommon
* \brief This is only a wrapper layer to abstract the different crypto random number generator implementations.
* With this wrapper it is possible to support more than one crypto random number generator implementation
* in parallel, by adapting this wrapper.
*
* Important hints for users of this component:
* - Before use of any function, the dedicated rng implementation has to be initialized (e.g. #phCryptoRng_Sw_Init)
* - Before random numbers can be generated, the #phCryptoRng_Seed function has to be called
* @{
*/

/**
* \brief Seeds the random number generator with the given seed.
*
* The seed length is dependent on the underlying implementation. Further details can be found in the detailed description
* of the underlying layers.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Seed(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSeed,             /**< [In] Seed */
                               VAR(uint8, ANFCRL_VAR) bSeedLength          /**< [In] Size of the seed. */
                               );

/**
* \brief Obtains random bytes from the random source.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoRng_Rnd(
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,             /**< [In] Pointer to this layer's parameter structure. */
                            VAR(uint16, ANFCRL_VAR) wNoOfRndBytes,        /**< [In] number of random bytes to generate */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRnd                  /**< [Out] generated bytes; uint8[dwNumBytes] */
                            );
/**
 * end of group phCryptoRng CryptoRng
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTORNG_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTORNG_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PH_CRYPTORNG */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /* PHCRYPTORNG_H */
