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
*   @file    phKeyStore.h
*   @version 1.0.0
*
*   @brief   AUTOSAR KeyStore - API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phKeyStore KeyStore
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


#ifndef PHKEYSTORE_H
#define PHKEYSTORE_H

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

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320

#include "phhalHw.h"

#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phKeyStore.h
* @implements     DESIGN001, DESIGN002
*/
#define PHKEYSTORE_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHKEYSTORE_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHKEYSTORE_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHKEYSTORE_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHKEYSTORE_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHKEYSTORE_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHKEYSTORE_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHKEYSTORE_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHKEYSTORE_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phKeyStore.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHKEYSTORE_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHKEYSTORE_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phKeyStore.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHKEYSTORE_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHKEYSTORE_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHKEYSTORE_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phKeyStore.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_KEYSTORE_SW
/** \defgroup phKeyStore_Sw Component : Software
* \ingroup phKeyStore
* \brief Keystore implementation in Software.
* @{
*/

#define PH_KEYSTORE_SW_ID               0x01U    /**< ID for Software KeyStore component. */
#define PH_KEYSTORE_SW_MAX_KEY_SIZE     32U     /**< Maximum size of a Key. */

/**
 * end of group phKeyStore_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
/** \defgroup phKeyStore_Ncx3320 Component : Ncx3320
* \ingroup phKeyStore
* \brief Ncx3320 KeyStore component
* @{
*/

#define PH_KEYSTORE_NCx3320_ID            0x02U    /**< ID for Ncx3320 KeyStore component. */
#define PH_KEYSTORE_NCx3320_NUM_KEYS      0x80U   /**< Maximum number of keys can be stored in Ncx3320. */
#define PH_KEYSTORE_NCx3320_NUM_VERSIONS  0x01U     /**< Amount of versions for each key entry in the key store. */

/**
 * end of group phKeyStore_Ncx3320 Component : Ncx3320
 * @}
 */
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

#ifdef NXPBUILD__PH_KEYSTORE
/** \defgroup phKeyStore KeyStore
* \ingroup phcommon
*
* \brief This is only a wrapper layer to abstract the different KeyStore implementations.
* @{
*/

#define PH_KEYSTORE_INVALID_ID      0xFFFFU  /**< ID used for various parameters as a invalid default **/
#define PH_KEYSTORE_DEFAULT_ID      0x0000U   /**< ID used for various parameters as a default **/

/**
* \name Key Types
*/
/*@{*/
#define PH_KEYSTORE_KEY_TYPE_AES128         0x00U   /**< AES 128 Key [16]. */
#define PH_KEYSTORE_KEY_TYPE_AES192         0x01U   /**< AES 192 Key [24]. */
#define PH_KEYSTORE_KEY_TYPE_AES256         0x02U   /**< AES 256 Key [32]. */
#define PH_KEYSTORE_KEY_TYPE_DES            0x03U   /**< DES Single Key.   */
#define PH_KEYSTORE_KEY_TYPE_2K3DES         0x04U   /**< 2 Key Triple Des. */
#define PH_KEYSTORE_KEY_TYPE_3K3DES         0x05U   /**< 3 Key Triple Des. */
#define PH_KEYSTORE_KEY_TYPE_MIFARE         0x06U   /**< MIFARE (R) Key. */

#define PH_KEYSTORE_KEY_TYPE_MIFARE_SIZE    0x0CU   /**< Size of an MIFARE Key. */
#define PH_KEYSTORE_KEY_TYPE_AES128_SIZE    0x10U   /**< Size of an AES128 Key. */
/*@}*/

/**
* \name KeyStoreConfigs
*/
/*@{*/
#define PH_KEYSTORE_CONFIG_SET_DEFAULT                    0xFFFFU     /**< Reset all bit of SET param. */
/*@}*/

/**
 * end of group phKeyStore KeyStore
 * @}
 */
#endif /* NXPBUILD__PH_KEYSTORE */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PH_KEYSTORE_SW
/** \addtogroup phKeyStore_Sw Component : Software
* \ingroup phKeyStore
* \brief Keystore implementation in Software.
* @{
*/

/**
* \brief Sw KeyVersionPair structure
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) pKey[PH_KEYSTORE_SW_MAX_KEY_SIZE];  /**< Array containing a Key  */
    VAR(uint16, ANFCRL_VAR) wVersion;                          /**< Versions related to  the Key*/
} phKeyStore_Sw_KeyVersionPair_t;

/**
* \brief Sw KeyEntry structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wKeyType;      /**< Type of the keys in pKeys. */
    VAR(uint16, ANFCRL_VAR) wRefNoKUC;     /**< Key usage counter number of the keys in pKeys. */
} phKeyStore_Sw_KeyEntry_t;

/**
* \brief Sw KeyUsageCounter structure
*/
typedef struct
{
    VAR(uint32, ANFCRL_VAR) dwLimit;   /**< Limit of the Key Usage Counter. */
    VAR(uint32, ANFCRL_VAR) dwCurVal;  /**< Current Value of the KUC. */
} phKeyStore_Sw_KUCEntry_t;

/**
* \brief Sw parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                      /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(phKeyStore_Sw_KeyEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyEntries;             /**< Key entry storage, size = sizeof(#phKeyStore_Sw_KeyEntry_t) * wNumKeyEntries. */
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersionPairs;  /**< Key version pairs, size = sizeof(#phKeyStore_Sw_KeyVersionPair_t)* wNumKeyEntries * wNumVersions. */
    VAR(uint16, ANFCRL_VAR) wNoOfKeyEntries;                           /**< Number of key entries in that storage. */
    VAR(uint16, ANFCRL_VAR) wNoOfVersions;                             /**< Number of versions in each key entry. */
    P2VAR(phKeyStore_Sw_KUCEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKUCEntries;             /**< Key usage counter entry storage, size = sizeof(#phKeyStore_Sw_KUCEntry_t) * wNumKUCEntries. */
    VAR(uint16, ANFCRL_VAR) wNoOfKUCEntries;                           /**< Number of Key usage counter entries. */
} phKeyStore_Sw_DataParams_t;
/**
 * end of group phKeyStore_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
/** \addtogroup phKeyStore_Ncx3320 Component : Ncx3320
* \ingroup phKeyStore
* \brief Ncx3320 KeyStore component 
* @{
*/

/**
* \brief Ncx3320 parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;          /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;  /**< Pointer to the parameter structure of the underlying layer.*/
} phKeyStore_Ncx3320_DataParams_t;
/**
 * end of group phKeyStore_Ncx3320 Component : Ncx3320
 * @}
 */
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_KEYSTORE_SW

#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phKeyStore_Sw Component : Software
* \ingroup phKeyStore
* \brief Keystore implementation in Software.
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_Init(
                              P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,             /**< [In] Pointer to this layer's parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                           /**< [In] Specifies the size of the data parameter structure. */
                              P2VAR(phKeyStore_Sw_KeyEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyEntries,             /**< [In] Pointer to a storage containing the key entries. */
                              VAR(uint16, ANFCRL_VAR) wNoOfKeyEntries,                             /**< [In] size of pKeyEntries. */
                              P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersionPairs,    /**< [In] Pointer to a storage containing the key version pairs. */
                              VAR(uint16, ANFCRL_VAR) wNoOfVersionPairs,                           /**< [In] amount of key versions available in each key entry. */
                              P2VAR(phKeyStore_Sw_KUCEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKUCEntries,               /**< [In] Key usage counter entry storage, size = sizeof(phKeyStore_Sw_KUCEntry_t) * wNumKUCEntries */
                              VAR(uint16, ANFCRL_VAR) wNoOfKUCEntries                              /**< [In] Number of Key usage counter entries. */
                              );

/**
 * end of group phKeyStore_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320

#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phKeyStore_Ncx3320 Component : Ncx3320
* \ingroup phKeyStore
* \brief Ncx3320 KeyStore component 
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Ncx3320_Init(
                                 P2VAR(phKeyStore_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                    /**< [In] Specifies the size of the data parameter structure. */
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                          /**< [In] Pointer to a HAL based on NXP NCx3320 IC. */
                                 );

/**
 * end of group phKeyStore_Ncx3320 Component : Ncx3320
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

#ifdef NXPBUILD__PH_KEYSTORE

/** \addtogroup phKeyStore KeyStore
* \ingroup phcommon
*
* \brief This is only a wrapper layer to abstract the different KeyStore implementations.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS

#if defined(NXPBUILD__PH_KEYSTORE_SW)
#include "../comps/phKeyStore/src/Sw/phKeyStore_Sw.h"

#define phKeyStore_FormatKeyEntry(pDataParams,wKeyNo,wNewKeyType) \
        phKeyStore_Sw_FormatKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams,wKeyNo,wNewKeyType)

#define phKeyStore_SetKey(pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion) \
        phKeyStore_Sw_SetKey((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion)

#define phKeyStore_SetKeyAtPos(pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion) \
        phKeyStore_Sw_SetKeyAtPos((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion)

#define phKeyStore_SetKUC(pDataParams, wKeyNo, wRefNoKUC) \
        phKeyStore_Sw_SetKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wRefNoKUC)

#define phKeyStore_SetFullKeyEntry(pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList) \
        phKeyStore_Sw_SetFullKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList)

#define phKeyStore_GetKeyEntry(pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType) \
        phKeyStore_Sw_GetKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType)

#define  phKeyStore_GetKey(pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType) \
         phKeyStore_Sw_GetKey((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType)

#define phKeyStore_SetConfig(pDataParams,wConfig,wValue) \
        phKeyStore_Sw_SetConfig((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,wValue)

#define phKeyStore_SetConfigStr(pDataParams,wConfig,pBuffer,wBufferLength) \
        phKeyStore_Sw_SetConfigStr((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,pBuffer,wBufferLength)

#define phKeyStore_GetConfig(pDataParams,wConfig,pValue) \
        phKeyStore_Sw_GetConfig((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,pValue)

#define phKeyStore_GetConfigStr(pDataParams,wConfig,ppBuffer,pBufferLength) \
        phKeyStore_Sw_GetConfigStr((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,ppBuffer,pBufferLength)

#define phKeyStore_ChangeKUC(pDataParams, wRefNoKUC, dwLimit) \
        phKeyStore_Sw_ChangeKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wRefNoKUC, dwLimit)

#define phKeyStore_GetKUC(pDataParams, wRefNoKUC, pdwLimit, pdwCurVal) \
        phKeyStore_Sw_GetKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wRefNoKUC, pdwLimit, pdwCurVal)

#	elif defined(NXPBUILD__PH_KEYSTORE_NCx3320)
#include "../comps/phKeyStore/src/Ncx3320/phKeyStore_Ncx3320.h"

#define phKeyStore_FormatKeyEntry(pDataParams,wKeyNo,wNewKeyType) \
        phKeyStore_Ncx3320_FormatKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wKeyNo,wNewKeyType)

#define phKeyStore_SetKey(pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion) \
        phKeyStore_Ncx3320_SetKey((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion)

#define phKeyStore_SetKeyAtPos(pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion) \
        phKeyStore_Ncx3320_SetKeyAtPos((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion)

#define phKeyStore_SetKUC(pDataParams, wKeyNo, wRefNoKUC) \
        phKeyStore_Ncx3320_SetKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wRefNoKUC)

#define phKeyStore_SetFullKeyEntry(pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList) \
        phKeyStore_Ncx3320_SetFullKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList)

#define phKeyStore_GetKeyEntry(pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType) \
        phKeyStore_Ncx3320_GetKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType)

#define  phKeyStore_GetKey(pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType) \
         phKeyStore_Ncx3320_GetKey((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType)

#define phKeyStore_SetConfig(pDataParams,wConfig,wValue) \
        phKeyStore_Ncx3320_SetConfig((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,wValue)

#define phKeyStore_SetConfigStr(pDataParams,wConfig,pBuffer,wBufferLength) \
        phKeyStore_Ncx3320_SetConfigStr((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,pBuffer,wBufferLength)

#define phKeyStore_GetConfig(pDataParams,wConfig,pValue) \
        phKeyStore_Ncx3320_GetConfig((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,pValue)

#define phKeyStore_GetConfigStr(pDataParams,wConfig,ppBuffer,pBufferLength) \
        phKeyStore_Ncx3320_GetConfigStr((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,ppBuffer,pBufferLength)

#define phKeyStore_ChangeKUC(pDataParams, wRefNoKUC, dwLimit) \
        phKeyStore_Ncx3320_ChangeKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wRefNoKUC, dwLimit)

#define phKeyStore_GetKUC(pDataParams, wRefNoKUC, pdwLimit, pdwCurVal) \
        phKeyStore_Ncx3320_GetKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wRefNoKUC, pdwLimit, pdwCurVal)


#endif /* NXPBUILD__PH_KEYSTORE_SW */

#else /* NXPRDLIB_REM_GEN_INTFS */

#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Format a key entry to a new KeyType.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_FormatKeyEntry(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                                     VAR(uint16, ANFCRL_VAR) wKeyNo,       /**< [In] KeyEntry number to be Formatted. */
                                     VAR(uint16, ANFCRL_VAR) wNewKeyType   /**< [In] New Key type of the KeyEntry (predefined type of KeyType).*/
                                     );

/**
* \brief Change a key entry at a given version.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKey(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
                             VAR(uint16, ANFCRL_VAR) wKeyNo,           /**< [In] Key number of the key to be loaded. */
                             VAR(uint16, ANFCRL_VAR) wKeyVersion,      /**< [In] Key version of the key to be loaded. */
                             VAR(uint16, ANFCRL_VAR) wKeyType,         /**< [In] Key type of the key to be loaded.*/
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,         /**< [In] Pointer to the key itself.*/
                             VAR(uint16, ANFCRL_VAR) wNewKeyVersion    /**< [In] New Key version of the key to be updated. */
                             );

/**
* \brief Change a key entry at the specified position.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKeyAtPos(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wKeyNo,          /**< [In] Key number of the key to be loaded. */
                                  VAR(uint16, ANFCRL_VAR) wPos,            /**< [In] Key position to be updated. */
                                  VAR(uint16, ANFCRL_VAR) wKeyType,        /**< [In] Key type of the key to be loaded.*/
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,        /**< [In] Pointer to the key itself.*/
                                  VAR(uint16, ANFCRL_VAR) wNewKeyVersion   /**< [In] New Key version of the key to be updated. */
                                  );

/**
* \brief Change the KUC of a key entry.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKUC(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                             VAR(uint16, ANFCRL_VAR) wKeyNo,       /**< [In] KeyEntry number. */
                             VAR(uint16, ANFCRL_VAR) wRefNoKUC     /**< [In] Reference Number of the key usage counter used together with that key.*/
                             );

/**
* \brief Change a full key entry.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetFullKeyEntry(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
                                      VAR(uint16, ANFCRL_VAR) wNoOfKeys,           /**< [In] Number of keys in pNewKeys. */
                                      VAR(uint16, ANFCRL_VAR) wKeyNo,              /**< [In] Key number of the key to be loaded. */
                                      VAR(uint16, ANFCRL_VAR) wNewRefNoKUC,        /**< [In] Number of the key usage counter used together with that key. */
                                      VAR(uint16, ANFCRL_VAR) wNewKeyType,         /**< [In] Key type of the key (if the current keyType of KeyEntry is different, error). */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeys,           /**< [In] Array of Keys to load. */
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeyVersionList /**< [In] KeyVersionList of the key to be loaded . */
                                      );

/**
* \brief Get a key entry information block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKeyEntry(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,               /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wKeyNo,                  /**< [In] Key number of the key entry of interest. */
                                  VAR(uint16, ANFCRL_VAR) wKeyVersionBufSize,      /**< [In] Buffer Size of wKeyVersion in Bytes. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersion,           /**< [Out] Array for version information. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersionLength,     /**< [Out] Length of valid data in wKeyVersion. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType               /**< [Out] Type of the key. */
                                  );

/**
* \brief Get a key.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKey(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                             VAR(uint16, ANFCRL_VAR) wKeyNo,       /**< [In] Key number of the key to be retrieved. */
                             VAR(uint16, ANFCRL_VAR) wKeyVersion,  /**< [In] Key version of the key to be retrieved. */
                             VAR(uint8, ANFCRL_VAR) bKeyBufSize,   /**< [In] Size of the key buffer. */
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,        /**< [Out] Pointer to the key itself. */
                             P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType    /**< [Out] Type of the key. */
                             );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetConfig(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig,       /**< [In] Configuration Identifier */
                                VAR(uint16, ANFCRL_VAR) wValue         /**< [In] Configuration Value */
                                );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetConfigStr(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig,       /**< [In] Configuration Identifier. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer,       /**< [In] Buffer containing the configuration string. */
                                   VAR(uint16, ANFCRL_VAR) wBufferLength  /**< [In] Length of configuration string. */
                                   );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetConfig(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig,       /**< [In] Configuration Identifier */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue       /**< [Out] Configuration Value */
                                );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetConfigStr(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig,        /**< [In] Configuration Identifier */
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppBuffer,     /**< [Out] Pointer to the buffer containing the configuration string. */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLength /**< [Out] Amount of valid bytes in the configuration string buffer. */
                                   );

/**
* \brief Change a key usage counter entry.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_ChangeKUC(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC,     /**< [In] Number of key entry.*/
                                VAR(uint32, ANFCRL_VAR) dwLimit        /**< [In] Limit of the Key Usage Counter*/
                                );

/**
* \brief Obtain a key usage counter entry.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKUC(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                             VAR(uint16, ANFCRL_VAR) wRefNoKUC,    /**< [In] number of the key usage counter to be looked at (00h to 0Fh)*/
                             P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwLimit,   /**< [Out] Currently Set Limit in the KUC */
                             P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwCurVal   /**< [Out] Currently set value in the KUC */
                             );

#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phKeyStore KeyStore
 * @}
 */

#endif /* NXPBUILD__PH_KEYSTORE */

#ifdef __cplusplus
}
#endif
#endif /* PHKEYSTORE_H */
