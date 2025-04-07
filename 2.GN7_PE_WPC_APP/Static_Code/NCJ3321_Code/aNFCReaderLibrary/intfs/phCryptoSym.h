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
*   @file    phCryptoSym.h
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
#ifndef PHCRYPTOSYM_H
#define PHCRYPTOSYM_H

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
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCRYPTOSYM_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCryptoSym.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCRYPTOSYM_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCRYPTOSYM_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCRYPTOSYM_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCRYPTOSYM_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PH_CRYPTOSYM

/** \defgroup phCryptoSym CryptoSym
* \ingroup phcommon
* \brief This is only a wrapper layer to abstract the different CryptoSym implementations.
* With this wrapper it is possible to support more than one CryptoSym implementation
* in parallel, by adapting this wrapper.
*
* Important hints for users of this component:
* - Before use of any function, the dedicated crypto implementation has to be initialized (e.g. #phCryptoSym_Sw_Init)
* - Functions using a key store (#phCryptoSym_LoadKey and #phCryptoSym_DiversifyKey) are only available if a key store has been passed
* during component initialization
* - Before any cipher operation or MAC operation (#phCryptoSym_Encrypt, #phCryptoSym_Decrypt, #phCryptoSym_CalculateMac) can be used, a key has to be loaded using either #phCryptoSym_LoadKey or #phCryptoSym_LoadKeyDirect
* - Before any cipher operation or MAC operation (#phCryptoSym_Encrypt, #phCryptoSym_Decrypt, #phCryptoSym_CalculateMac) can be used, an appropriate IV has to be loaded by calling #phCryptoSym_LoadIv
* - Using #phCryptoSym_GetConfig, the block sizes and key lengths for the currently loaded key can be retrieved
* @{
*/

/**
* \name CryptoSym Layer Configs
*/
/*@{*/
/**
* Key Type. Read-only. Possible Values are:\n
* \li #PH_CRYPTOSYM_KEY_TYPE_AES128
* \li #PH_CRYPTOSYM_KEY_TYPE_AES192
* \li #PH_CRYPTOSYM_KEY_TYPE_AES256
* \li #PH_CRYPTOSYM_KEY_TYPE_DES
* \li #PH_CRYPTOSYM_KEY_TYPE_2K3DES
* \li #PH_CRYPTOSYM_KEY_TYPE_3K3DES
* \li #PH_CRYPTOSYM_KEY_TYPE_INVALID
* \li #PH_CRYPTOSYM_KEY_TYPE_MIFARE
*/
#define PH_CRYPTOSYM_CONFIG_KEY_TYPE    0x0000U
#define PH_CRYPTOSYM_CONFIG_KEY_SIZE    0x0001U /**< Key Size of currently loaded key. Read-only.  */
#define PH_CRYPTOSYM_CONFIG_BLOCK_SIZE  0x0002U /**< Block Size of currently loaded key. Read-only. */
/**
* Keep init vector. Either #PH_CRYPTOSYM_VALUE_KEEP_IV_OFF or #PH_CRYPTOSYM_VALUE_KEEP_IV_ON.\n
* This flag has to be used in combination with the option flag in the Encrypt/Decrypt/CalculateMac\n
* function: If either the option in the function or this flag is set, the IV will be updated before\n
* returning of the function.\n
* R/W access possible.
*/
#define PH_CRYPTOSYM_CONFIG_KEEP_IV                 0x0003U
#define PH_CRYPTOSYM_CONFIG_LRP                     0x0004U /**< Set the LRP mode on. */
#define PH_CRYPTOSYM_CONFIG_LRP_NUMKEYS_UPDATE      0x0005U /**<  Number of times the loop to generate the UpdatedKey to be generated. */
/*@}*/

/**
* \name Supported IV Updated Behaviour Modes
*/
/*@{*/
#define PH_CRYPTOSYM_VALUE_KEEP_IV_OFF  0x0000U /**< Switch off Keep-IV behaviour. */
#define PH_CRYPTOSYM_VALUE_KEEP_IV_ON   0x0001U /**< Switch on Keep-IV behaviour. */

/**
* \name Supported Padding Modes.
*/
#define PH_CRYPTOSYM_PADDING_MODE_1     0x00U /**< Pad with all zeros */
#define PH_CRYPTOSYM_PADDING_MODE_2     0x01U /**< Pad with a one followed by all zeros */
/*@}*/

/**
* \name Supported Cipher Modes
*/
/*@{*/
#define PH_CRYPTOSYM_CIPHER_MODE_ECB        0x00U   /**< ECB Cipher Mode. */
#define PH_CRYPTOSYM_CIPHER_MODE_CBC        0x01U   /**< CBC Cipher Mode. */
#define PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4    0x02U   /**< CBC Cipher Mode for DF4. */
#define PH_CRYPTOSYM_CIPHER_MODE_LRP        0x03U   /**< CBC Cipher Mode. */
/*@}*/

/**
* \name Supported Mac Modes
*/
/*@{*/
#define PH_CRYPTOSYM_MAC_MODE_CMAC              0x00U   /**< CMAC MAC Mode. */
#define PH_CRYPTOSYM_MAC_MODE_CBCMAC            0x01U   /**< CBCMAC MAC Mode. */
#define PH_CRYPTOSYM_MAC_MODE_LRP               0x02U   /**< LRP Mode. */
#define PH_CRYPTOSYM_MAC_MODE_LRP_SKM           0x03U   /**< Session Auth Master Key Generating Mode */
#define PH_CRYPTOSYM_MAC_MODE_LRP_GENPCDRESP    0x04U   /**< Generating PCD Resp */
/*@}*/

/**
* \name Supported Key Types to be used in key loading functionality.
*/
/*@{*/
#define PH_CRYPTOSYM_KEY_TYPE_AES128    0x0000U /**< AES 128 Key [16 Bytes]. */
#define PH_CRYPTOSYM_KEY_TYPE_AES192    0x0001U /**< AES 192 Key [24 Bytes]. */
#define PH_CRYPTOSYM_KEY_TYPE_AES256    0x0002U /**< AES 256 Key [32 Bytes]. */
#define PH_CRYPTOSYM_KEY_TYPE_DES       0x0003U /**< DES Single Key [8 Bytes].   */
#define PH_CRYPTOSYM_KEY_TYPE_2K3DES    0x0004U /**< 2 Key Triple Des [16 Bytes]. */
#define PH_CRYPTOSYM_KEY_TYPE_3K3DES    0x0005U /**< 3 Key Triple Des [24 Bytes]. */

#define PH_CRYPTOSYM_KEY_TYPE_INVALID   0xFFFFU /**< Invalid Key*/

#define PH_CRYPTOSYM_KEY_TYPE_MIFARE    0x0006U /**< MIFARE product Key. */
/*@}*/

/**
* \name Supported Diversification Types
*/
/*@{*/
#define PH_CRYPTOSYM_DIV_MODE_DESFIRE       0x0000U /**< MIFARE DESFire contactless IC Key Diversification. */
#define PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS   0x0001U /**< MIFARE Plus contactless IC Key Diversification. */
#define PH_CRYPTOSYM_DIV_MODE_MIFARE_ULTRALIGHT  0x0002U /**< MIFARE Ultralight contactless IC Key Diversification. */
#define PH_CRYPTOSYM_DIV_MODE_MASK          0x00FFU /**< Bitmask for diversification Mode. */
#define PH_CRYPTOSYM_DIV_OPTION_2K3DES_FULL 0x0000U /**< Option for 2K3DES full-key diversification (only with #PH_CRYPTOSYM_DIV_MODE_DESFIRE). */
#define PH_CRYPTOSYM_DIV_OPTION_2K3DES_HALF 0x8000U /**< Option for 2K3DES half-key diversification (only with #PH_CRYPTOSYM_DIV_MODE_DESFIRE). */
/*@}*/

/**
* \name General DES Defines.
*/
/*@{*/
#define PH_CRYPTOSYM_DES_BLOCK_SIZE      8U /**< Block size in DES algorithm */
#define PH_CRYPTOSYM_DES_KEY_SIZE        8U /**< Key size in DES algorithm for 56 bit key*/
#define PH_CRYPTOSYM_2K3DES_KEY_SIZE    16U /**< Key size in AES algorithm for 112 bit key*/
#define PH_CRYPTOSYM_3K3DES_KEY_SIZE    24U /**< Key size in AES algorithm for 168 bit key*/
/*@}*/

/**
* \name General AES Defines.
*/
/*@{*/
#define PH_CRYPTOSYM_AES_BLOCK_SIZE     16U /**< Block size in AES algorithm */
#define PH_CRYPTOSYM_AES128_KEY_SIZE    16U /**< Key size in AES algorithm for 128 bit key*/
#define PH_CRYPTOSYM_AES192_KEY_SIZE    24U /**< Key size in AES algorithm for 192 bit key*/
#define PH_CRYPTOSYM_AES256_KEY_SIZE    32U /**< Key size in AES algorithm for 256 bit key*/
/*@}*/

/**
 * end of group phCryptoSym CryptoSym
 * @}
 */
#endif /* NXPBUILD__PH_CRYPTOSYM */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW

/** \defgroup phCryptoSym_Sw Component : Software
* \ingroup phCryptoSym
* \brief Software implementation of the Symmetric Cryptography interface.
*
* This implementation was designed to optimize the footprint of crypto libraries used in
* embedded systems.
* The following standards are implemented:
* - Federal Information Processing Standards Publication 197: AES 128, 192 and 256
* - Federal Information Processing Standards Publication 46-3: DES
* - NIST Special Publication 800-67 Recommendation for the Triple Data Encryption Algorithm (TDEA) Block Cipher
* - NIST Special Publication 800-38B: CMAC
* - NIST Special Publication 800-38A: CBC and ECB mode
* - NIST Special Publication 800-38A: CMC-MAC
*
* Hints for compiling the library:
* - Carefully read the section on compile switches in order to find the optimum balance between speed and memory utilization.
* - Using the appropriate compile switches either AES or DES can be removed from the built completely.
*
* Architecture of the phCryptoSym_Sw Component:
* - The DES algorithm is implemented in the phCryptoSym_Sw_Des block
* - The AES algorithm is implemented in the phCryptoSym_Sw_Aes block
* - The phCryptoSym_Int block implements generic encrypt and decrypt functions. This offers the possibility to implement modes
* of operations without consideration of currently selected key type or key size.
* - The phCryptoSym_Int block in addition implements helper functions for CMAC calculations.
* @{
*/

#define PH_CRYPTOSYM_SW_ID             0x01U    /**< ID for Software crypto component. */

/**
* \name Compile Switches.
*
* \brief Compile switches used to find the optimum trade-off between performance, memory footprint and supported features.
*/
/*@{*/

/**
* \brief Enables DES support.
*
* Defines that the DES algorithm is supported. The defines for general DES capabilities like block sizes etc. are not affected
* as they do not add to the memory footprint.
*/
#define PH_CRYPTOSYM_SW_DES
/**
* \brief Enables AES support.
*
* Defines that the AES algorithm is supported. The defines for general AES capabilities like block sizes etc. are not affected
* as they do not add to the memory footprint.
*/
#define PH_CRYPTOSYM_SW_AES

/**
* \brief Enables online key scheduling.
*
* This define enables for both AES and DES the online key scheduling. This means, that the round keys are not pre-calculated
* at key loading, but they are always calculated when a new block is going to be encrypted or decrypted.
*
* The following advantages come out of enabling online key scheduling:
* - The pKey entry of the private data param structure decreases significantly from 384(DES enabled)/256(DES disabled) to 32 bytes.
* - As the private data structure has to be created for each instance, the above mentioned savings count for each instance.
* - Key loading is very fast (as there is almost nothing performed any more.
* - On 8051 the keys can be located in fast RAM which counters some of the performance decrease compared to disabling that feature.
*
* The following disadvantages come out of enabling online key scheduling:
* - Encryption gets slower as in addition to the ciphering also the round key generation has to be performed.
* - For decryption in AES the situation is even worse, as the key scheduling is executed twice for each decryption.
* - On small platforms like 8051 big key buffers can never reside in fast RAM as they exceed the memory size of data and idata.
*
* On 8051 platforms in combination with the PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE enabling online key scheduling even gives better results
* on execution time if only 1 or 2 blocks are encrypted with a given key. In case of keys are used longer (which is most likely the standard case),
* it is faster to disable that feature.
* Also note, that e.g. for a MIFARE Plus (R) instance of the library, two crypto instances are required, and as a consequence online key
* scheduling can save 704(DES enabled)/(DES disabled)448 bytes of RAM.
*/
#define PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING

/**
* \brief Enables online CMAC sub-key calculation.
*
* This define enables for both AES and DES the online CMAC sub-key calculation. This means, that the CMAC sub-keys are not stored in the
* context of the individual instance of the crypto lib, but they are newly calculated for each MAC.
*
* The following advantages come out of enabling online CMAC sub-key calculation:
* - 32 bytes of RAM can be saved in the private data params (so they are saved on each instance of the crypto library).
*
* The following disadvantages come out of online CMAC sub-key calculation:
* - Each CMAC calculation needs 1 additional encryption and 2 additional shift operations, so the execution speed decreases.
*/
#define PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION

/**
* \brief Enables ROM optimizations in the AES algorithm.
*
* This define removes some of the lookup tables in the AES implementation to save ROM space.
*
* The following advantages come out of enabling ROM optimizations:
* - 3 lookup tables of 256 bytes can be saved (some additional code is needed, so in fact only ~600 bytes are saved).
*
* The following disadvantages come out of enabling ROM optimizations:
* - The MixColumn and MixColumnInv implementation of the AES are getting slower.
*/
#define PH_CRYPTOSYM_SW_ROM_OPTIMIZATION

/**
* \brief Enables 8051 data storage specifier.
*
* This define allows to specify any value for #PH_CRYTOSYM_SW_FAST_RAM. It takes care, that the buffers are re-copied correctly,
* and that most of the time consuming calculations are done on this fast memory. In case of #PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
* is set, even the key scheduling can be performed on this fast memory.
*/
/*
#define PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
*/
/*@}*/

#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
#define PH_CRYTOSYM_SW_FAST_RAM data    /**< Fast RAM specifier, only useful in combination with #PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#define PH_CRYPTOSYM_SW_CONST_ROM       /**< Constant code specifier, only useful in combination with #PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
#else
#define PH_CRYTOSYM_SW_FAST_RAM     /**< Fast RAM specifier - not set per default */
#define PH_CRYPTOSYM_SW_CONST_ROM   /**< ROM specifier - not set per default */
#endif

#ifndef PH_CRYPTOSYM_SW_AES
#ifdef PH_CRYPTOSYM_SW_DES
#define PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE  PH_CRYPTOSYM_DES_BLOCK_SIZE /**< Maximum Block Size of the currently supported ciphers*/
#else
#error "No symmetric cipher available"
#endif /* PH_CRYPTOSYM_SW_DES */
#else
#define PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE  PH_CRYPTOSYM_AES_BLOCK_SIZE /**< Maximum Block Size of the currently supported ciphers*/
#endif /* PH_CRYPTOSYM_SW_AES */

/* Key buffer size is calculated as follows: */
/* DES offline key scheduling: 3 #numKeys * 16 #numRounds * 8 #KeySize = 384 Bytes */
/* DES online key scheduling: 3 #numKeys * 2 #temporaryKey+originalKey * 8 #KeySize + 8 #intermediate result = 56 Bytes  */
/* AES offline key scheduling: (13u + 2U) (#numRounds + #original) * 16 #KeySize = 240 Bytes */
/* AES online key scheduling: (1u + 1U) (#temporary + #original) * 32 #KeySize = 64 Bytes */

#ifdef PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING
#define PH_CRYPTOSYM_SW_KEY_BUFFER_SIZE    32U
#else
#ifdef PH_CRYPTOSYM_SW_DES
#define PH_CRYPTOSYM_SW_KEY_BUFFER_SIZE    384U
#else
#define PH_CRYPTOSYM_SW_KEY_BUFFER_SIZE    240U
#endif /* PH_CRYPTOSYM_SW_DES */
#endif /* PH_CRYPTOSYM_SW_ONLINE_KEYSCHEDULING */

/**
 * end of group phCryptoSym_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PH_CRYPTOSYM_SW
/** \addtogroup phCryptoSym_Sw Component : Software
 * \ingroup phCryptoSym
 * @{
 */

/**
* \brief Software parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                   /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                     /**< Pointer to Key Store object - can be NULL. */
#ifndef NXPBUILD__PH_CRYPTOSYM_LRP
    VAR(uint8, ANFCRL_VAR) pKey[PH_CRYPTOSYM_SW_KEY_BUFFER_SIZE];  /**< Internal key storage array */
#else
    uint8 pKey[PH_CRYPTOSYM_SW_KEY_BUFFER_SIZE * 16];  /**< Internal key storage array */
#endif /* NXPBUILD__PH_CRYPTOSYM_LRP */
    VAR(uint8, ANFCRL_VAR) pIV[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];    /**< Internal IV storage array */
#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    VAR(uint8, ANFCRL_VAR) pCMACSubKey1[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];   /**< Internal Key1 storage for MAC calculation. */
    VAR(uint8, ANFCRL_VAR) pCMACSubKey2[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];   /**< Internal Key2 storage for MAC calculation. */
    VAR(uint8, ANFCRL_VAR) bCMACSubKeysInitialized;                        /**< Indicates whether the sub keys have been calculated. */
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */
    VAR(uint16, ANFCRL_VAR) wKeyType;  /**< Key Type. */
    VAR(uint16, ANFCRL_VAR) wKeepIV;   /**< Indicates if the init vector of a previous crypto operation shall be used for the next operation. */
} phCryptoSym_Sw_DataParams_t;

/**
 * end of group phCryptoSym_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTOSYM

#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phCryptoSym CryptoSym
 * \ingroup phcommon
 *  @{
 */
 
/**
* \brief Invalidate the currently loaded key.
*
* Resets the key, the IV, the keep IV flag and the key Type.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_InvalidateKey(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure */
                                     );

/**
* \brief Perform Encryption with one of the supported crypto modes
*
* The option word specifies the operation mode to use and the update behavior of the IV.
* All modes of operation are coded in the LSB, the flags in the MSB.
* The following Cipher modes are supported:
* - #PH_CRYPTOSYM_CIPHER_MODE_ECB
* - #PH_CRYPTOSYM_CIPHER_MODE_CBC
* - #PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4
*
* The following Flags are supported:
* - #PH_EXCHANGE_DEFAULT
* - #PH_EXCHANGE_BUFFER_FIRST
* - #PH_EXCHANGE_BUFFER_CONT
* - #PH_EXCHANGE_BUFFER_LAST
*
* Note:  The input data length needs to be a multiple of the current block size
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER wPlainBufferLength is not a multiple of the current block size.
* \retval #PH_ERR_INVALID_PARAMETER An unsupported key is loaded (or no key is loaded).
* \retval #PH_ERR_UNSUPPORTED_PARAMETER An unknown cipher option wOption is specified.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Encrypt(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint16, ANFCRL_VAR) wOption,                /**< [In] Option byte specifying the cipher mode and the update behavior of the IV */
                               P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pPlainBuffer,    /**< [In] plain data buffer */
                               VAR(uint16, ANFCRL_VAR) wBufferLength,         /**< [In] length of plain and encrypted data buffer - needs to be a multiple of the current block size */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncryptedBuffer       /**< [Out] encrypted data buffer */
                               );

/**
* \brief Perform Decryption with one of the supported crypto modes
*
* The option word specifies the operation mode to use and the update behavior of the IV.
* All modes of operation are coded in the LSB, the flags in the MSB.
* The following Cipher modes are supported:
* - #PH_CRYPTOSYM_CIPHER_MODE_ECB
* - #PH_CRYPTOSYM_CIPHER_MODE_CBC
* - #PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4
*
* The following Flags are supported:
* - #PH_EXCHANGE_DEFAULT
* - #PH_EXCHANGE_BUFFER_FIRST
* - #PH_EXCHANGE_BUFFER_CONT
* - #PH_EXCHANGE_BUFFER_LAST
*
* Note:  The input data length needs to be a multiple of the current block size
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER wPlainBufferLength is not a multiple of the current block size.
* \retval #PH_ERR_INVALID_PARAMETER An unsupported key is loaded (or no key is loaded).
* \retval #PH_ERR_UNSUPPORTED_PARAMETER An unknown cipher option wOption is specified.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Decrypt(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                  /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint16, ANFCRL_VAR) wOption,                    /**< [In] Option byte specifying the cipher mode and the update behavior of the IV */
                               P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pEncryptedBuffer,    /**< [In] encrypted data buffer */
                               VAR(uint16, ANFCRL_VAR) wBufferLength,             /**< [In] length of plain and encrypted data buffer - needs to be a multiple of the current block size */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainBuffer               /**< [Out] plain data buffer */
                               );

/**
* \brief Calculate MAC with one of the supported MAC modes
*
* The option word specifies the MAC mode to use and the update behavior of the IV as well as the completion behavior.
* All modes of operation are coded in the LSB, the flags in the MSB.
* The following Cipher modes are supported:
* - #PH_CRYPTOSYM_MAC_MODE_CMAC
* - #PH_CRYPTOSYM_MAC_MODE_CBCMAC
*
* The following Flags are supported:
* - #PH_EXCHANGE_DEFAULT
* - #PH_EXCHANGE_BUFFER_FIRST
* - #PH_EXCHANGE_BUFFER_CONT
* - #PH_EXCHANGE_BUFFER_LAST
*
* Note: If #PH_EXCHANGE_BUFFERED_BIT is set, the input length needs to be a multiple of the block length!
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER wDataLength is not a multiple of the current block size and the option #PH_EXCHANGE_BUFFERED_BIT is set.
* \retval #PH_ERR_INVALID_PARAMETER An unsupported key is loaded (or no key is loaded).
* \retval #PH_ERR_UNSUPPORTED_PARAMETER An unknown mac option wOption is specified.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_CalculateMac(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wOption,       /**< [In] Option byte specifying the MAC mode and the update behavior of the IV and the completion flag.*/
                                    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pData,  /**< [In] input block; uint8[wDataLength] */
                                    VAR(uint16, ANFCRL_VAR) wDataLength,  /**< [In] number of input data bytes */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac,         /**< [Out] output MAC block; uint8[16] */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMacLength    /**< [Out] Length of MAC */
                                    );

/**
* \brief Load IV
*
* Note: Before loading of an IV can be performed, a key has to be loaded upfront.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER bIVLength does not match the current block size.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadIv(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                              P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pIV,  /**< [In] IV[bIVLength]. */
                              VAR(uint8, ANFCRL_VAR) bIVLength     /**< [In] Length of IV. */
                              );

/**
* \brief Load Key
*
* This function uses the key storage provided at component initialization to retrieve the key identified by wKeyNo and wKeyVersion.
* After retrieving the key is loaded into the internal key storage array to be prepared for subsequent cipher operations.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_DATA_PARAMS No keystore specified at Init.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Key Type not supported.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadKey(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint16, ANFCRL_VAR) wKeyNo,         /**< [In] Number of the Key */
                               VAR(uint16, ANFCRL_VAR) wKeyVersion,    /**< [In] Version of the key */
                               VAR(uint16, ANFCRL_VAR) wKeyType        /**< [In] Type of Key */
                               );

/**
* \brief Direct Load Key
*
** The key provided in the pKey parameter is loaded into the internal key storage array to be prepared for subsequent cipher operations.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Key Type not supported.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadKeyDirect(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                     P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,   /**< [In] key pointer to the key */
                                     VAR(uint16, ANFCRL_VAR) wKeyType      /**< [In] ID of the Key type */
                                     );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Invalid (Unsupported) wConfig.
* \retval #PH_ERR_INVALID_PARAMETER Valid wConfig but invalid wValue for that config.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_SetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wConfig,      /**< [In] Configuration Identifier */
                                 VAR(uint16, ANFCRL_VAR) wValue        /**< [In] Configuration Value */
                                 );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Invalid (Unsupported) wConfig.
* \retval #PH_ERR_INVALID_PARAMETER Value behind wConfig not valid at the moment.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_GetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wConfig,      /**< [In] Configuration Identifier */
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue      /**< [Out] Configuration Value */
                                 );

/**
* \brief Diversify Key - Note: This function invalidates the currently loaded key.
*
* Using the key stored in the keystore passed at initialization of the component and identified by wKeyNo and wKeyVersion
* this function calculates a diversified key according to the wOption specified that can be used in different applications.
* The following key diversification methods are supported:
* - #PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_DATA_PARAMS No keystore specified at Init.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Key Type not supported (for key diversification).
* \retval #PH_ERR_LENGTH_ERROR Length of diversification input is wrong.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_DiversifyKey(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wOption,           /**< [In] Option to specify the diversification method */
                                    VAR(uint16, ANFCRL_VAR) wKeyNo,            /**< [In] Number of the Key */
                                    VAR(uint16, ANFCRL_VAR) wKeyVersion,       /**< [In] Version of the key */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,        /**< [In] Diversification Input used to diversify the key. */
                                    VAR(uint8, ANFCRL_VAR) bLenDivInput,      /**< [In] Length of diversification input used to diversify the key. If 0, no diversification is performed. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey   /**< [Out] Diversified key */
                                    );

/**
* \brief Diversify Direct Key - Note: This function invalidates the currently loaded key.
*
* Using the key passed in the pKey parameter this function calculates a diversified key according to the wOption
* specified that can be used in different applications.
* The following key diversification methods are supported:
* - #PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Key Type not supported (for key diversification).
* \retval #PH_ERR_LENGTH_ERROR Length of diversification input is wrong.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_DiversifyDirectKey(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,           /**< [In] Option to specify the diversification method */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,             /**< [In] Key to be diversified */
    VAR(uint16, ANFCRL_VAR) wKeyType,          /**< [In] Type of the key  */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,        /**< [In] Diversification Input used to diversify the key. */
    VAR(uint8, ANFCRL_VAR) bLenDivInput,       /**< [In] Length of diversification input used to diversify the key. If 0, no diversification is performed. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey   /**< [Out] Diversified key */
    );

/**
* \brief Apply Padding to a given data buffer
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_BUFFER_OVERFLOW wDataOutBufSize is too small.
* \retval #PH_ERR_INVALID_PARAMETER Unsupported bOption.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_ApplyPadding(
                                    VAR(uint8, ANFCRL_VAR) bOption,            /**< [In] Specifies padding mode (1 or 2) */
                                    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pDataIn,   /**< [In] Pointer to input data array */
                                    VAR(uint16, ANFCRL_VAR) wDataInLength,     /**< [In] Length of input data */
                                    VAR(uint8, ANFCRL_VAR) bBlockSize,         /**< [In] Block size to be used for padding */
                                    VAR(uint16, ANFCRL_VAR) wDataOutBufSize,   /**< [In] Size of data array */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,         /**< [Out] Pointer to output data array */
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataOutLength   /**< [Out] Length of output data */
                                    );

/**
* \brief Remove Padding to a given data buffer
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER wDataInLength is not a multiple of the bBlockSize parameter.
* \retval #PH_ERR_INVALID_PARAMETER Unsupported bOption.
* \retval #PH_ERR_FRAMING_ERROR Padding byte wrong.

*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_RemovePadding(
                                     VAR(uint8, ANFCRL_VAR) bOption,           /**< [In] Specifies padding mode (1 or 2) */
                                     P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pDataIn,   /**< [In] Pointer to input data array */
                                     VAR(uint16, ANFCRL_VAR) wDataInLength,    /**< [In] Length of input data */
                                     VAR(uint8, ANFCRL_VAR) bBlockSize,        /**< [In] Block size to be used for padding */
                                     VAR(uint16, ANFCRL_VAR) wDataOutBufSize,  /**< [In] Size of data array */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,        /**< [Out] Pointer to output data array */
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataOutLength  /**< [Out] Length of output data */
                                     );

/**
 * end of group phCryptoSym CryptoSym
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_CRYPTOSYM */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW

#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phCryptoSym_Sw Component : Software
 * \ingroup phCryptoSym
 *  @{
 */

/**
* \brief Initialize the CryptoSym component.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Init(
                               P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                  /**< [In] Specifies the size of the data parameter structure. */
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams                   /**< [In] Pointer to a key store structure (can be null).*/
                               );

/**
 * end of group phCryptoSym_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif


#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* PHCRYPTOSYM_H */
