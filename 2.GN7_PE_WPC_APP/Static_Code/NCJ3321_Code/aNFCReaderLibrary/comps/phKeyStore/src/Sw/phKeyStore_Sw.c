/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2023
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
*   @file    phKeyStore_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR KeyStore_Sw - API usage in common use cases.
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
#include <phKeyStore.h>
#include <phTools.h>

#ifdef NXPBUILD__PH_KEYSTORE_SW
#include "phKeyStore_Sw.h"
#include "phKeyStore_Sw_Int.h"
#include "../phKeyStore_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phKeyStore_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHKEYSTORE_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHKEYSTORE_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHKEYSTORE_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHKEYSTORE_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHKEYSTORE_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phKeyStore_Sw.h header file are of the same vendor */
#if (PHKEYSTORE_SW_VENDOR_ID_C != PHKEYSTORE_SW_VENDOR_ID)
    #error "phKeyStore_Sw.c and phKeyStore_Sw.h have different vendor ids"
#endif
/* Check if current file and phKeyStore_Sw.h header file are of the same Autosar version */
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION_C    != PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION_C    != PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHKEYSTORE_SW_AR_RELEASE_REVISION_VERSION_C != PHKEYSTORE_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phKeyStore_Sw.c and phKeyStore_Sw.h are different"
#endif
/* Check if current file and phKeyStore_Sw.h header file are of the same Software version */
#if ((PHKEYSTORE_SW_SW_MAJOR_VERSION_C != PHKEYSTORE_SW_SW_MAJOR_VERSION) || \
     (PHKEYSTORE_SW_SW_MINOR_VERSION_C != PHKEYSTORE_SW_SW_MINOR_VERSION) || \
     (PHKEYSTORE_SW_SW_PATCH_VERSION_C != PHKEYSTORE_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phKeyStore_Sw.c and phKeyStore_Sw.h are different"
#endif
#endif /* NXPBUILD__PH_KEYSTORE_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_KEYSTORE_SW
#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_Init(
                              P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                              P2VAR(phKeyStore_Sw_KeyEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyEntries,
                              VAR(uint16, ANFCRL_VAR) wNoOfKeyEntries,
                              P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersionPairs,
                              VAR(uint16, ANFCRL_VAR) wNoOfVersionPairs,
                              P2VAR(phKeyStore_Sw_KUCEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pKUCEntries,
                              VAR(uint16, ANFCRL_VAR) wNoOfKUCEntries
                              )
{
    VAR(uint16, ANFCRL_VAR) i;
    VAR(uint16, ANFCRL_VAR) j;
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;

    if (sizeof(phKeyStore_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
    }
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pKeyEntries);
    PH_ASSERT_NULL (pKeyVersionPairs);
    PH_ASSERT_NULL (pKUCEntries);

    /* Init private data */
    pDataParams->wId = PH_COMP_KEYSTORE | PH_KEYSTORE_SW_ID;
    pDataParams->pKeyEntries = pKeyEntries;
    pDataParams->pKeyVersionPairs = pKeyVersionPairs;
    pDataParams->wNoOfKeyEntries = wNoOfKeyEntries;
    pDataParams->wNoOfVersions = wNoOfVersionPairs;
    pDataParams->pKUCEntries = pKUCEntries;
    pDataParams->wNoOfKUCEntries = wNoOfKUCEntries;

    for (i = 0; i < pDataParams->wNoOfKeyEntries; i++)
    {
        pDataParams->pKeyEntries[i].wKeyType = PH_KEYSTORE_INVALID_ID;
        pDataParams->pKeyEntries[i].wRefNoKUC = PH_KEYSTORE_INVALID_ID;

        for (j = 0; j < pDataParams->wNoOfVersions; j++)
        {
            PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrPos(pDataParams, i, j, &pKeyVersion));
            pKeyVersion->wVersion = PH_KEYSTORE_DEFAULT_ID;
        }
    }

    for (i = 0; i < pDataParams->wNoOfKUCEntries; i++)
    {
        pDataParams->pKUCEntries[i].dwLimit = 0xFFFFFFFFU;
        pDataParams->pKUCEntries[i].dwCurVal = 0;
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_FormatKeyEntry(
                                        P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                /**< [In] Pointer to this layer's parameter structure. */
                                        VAR(uint16, ANFCRL_VAR) wKeyNo,                /**< [In] KeyEntry number to be Formatted (0x00 to F0). */
                                        VAR(uint16, ANFCRL_VAR) wNewKeyType            /**< [In] New Key type of the KeyEntry (predefined type of KeyType).*/
                                        )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint8, ANFCRL_VAR) i;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;
    /* Overflow checks */
    if (wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    switch(wNewKeyType)
    {
    case PH_KEYSTORE_KEY_TYPE_AES128:
    case PH_KEYSTORE_KEY_TYPE_DES:
    case PH_KEYSTORE_KEY_TYPE_2K3DES:
    case PH_KEYSTORE_KEY_TYPE_MIFARE:
    case PH_KEYSTORE_KEY_TYPE_AES192:
    case PH_KEYSTORE_KEY_TYPE_3K3DES:
    case PH_KEYSTORE_KEY_TYPE_AES256:
        break;
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    pDataParams->pKeyEntries[wKeyNo].wKeyType = wNewKeyType;

    /* Reset CEK to master Key */
    pDataParams->pKeyEntries[wKeyNo].wRefNoKUC = PH_KEYSTORE_INVALID_ID;

    /* Reset all keys to 0x00*/
    for (i = 0; i < pDataParams->wNoOfVersions; ++i)
    {
        PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrPos(pDataParams,wKeyNo,i,&pKeyVersion));
        pKeyVersion->wVersion = 0;
        (void)memset(pKeyVersion->pKey, 0x00, PH_KEYSTORE_SW_MAX_KEY_SIZE);
    }

    return PH_ERR_SUCCESS;

}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKey(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                VAR(uint16, ANFCRL_VAR) wKeyType,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrVersion(pDataParams,wKeyNo,wKeyVersion,&pKeyVersion));

    /* Check that Key type matches with current Key Type format */
    if (pDataParams->pKeyEntries[wKeyNo].wKeyType != wKeyType)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* copy the key and version */
    phTools_memcpy(pKeyVersion->pKey, pNewKey, phKeyStore_GetKeySize(wKeyType));
    pKeyVersion->wVersion = wNewKeyVersion;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKeyAtPos(
                                     P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wKeyNo,
                                     VAR(uint16, ANFCRL_VAR) wPos,
                                     VAR(uint16, ANFCRL_VAR) wKeyType,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                     VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                     )
{

    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrPos(pDataParams,wKeyNo,wPos,&pKeyVersion));

    /* Check that Key type matches with current Key Type format */
    if (pDataParams->pKeyEntries[wKeyNo].wKeyType != wKeyType)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* copy the key and version */
    phTools_memcpy(pKeyVersion->pKey, pNewKey, phKeyStore_GetKeySize(wKeyType));
    pKeyVersion->wVersion = wNewKeyVersion;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKUC(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC
                                )
{
    /* Overflow checks */
    if (wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    /* Check for a valid KUC entry */
    if (wRefNoKUC >= pDataParams->wNoOfKUCEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    pDataParams->pKeyEntries[wKeyNo].wRefNoKUC = wRefNoKUC;

    return PH_ERR_SUCCESS;

}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetFullKeyEntry(
    P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wNoOfKeys,
    VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wNewRefNoKUC,
    VAR(uint16, ANFCRL_VAR) wNewKeyType,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeys,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeyVersionList
    )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint8, ANFCRL_VAR) i;
    VAR(uint8, ANFCRL_VAR) bKeyLength;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;

    /* Overflow checks */
    if (wKeyNo >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    /* Check for a valid KUC entry */
    if (wNewRefNoKUC >= pDataParams->wNoOfKUCEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    /* Overflow checks */
    if (wNoOfKeys > pDataParams->wNoOfVersions)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    switch(wNewKeyType)
    {
        case PH_KEYSTORE_KEY_TYPE_AES128:
        case PH_KEYSTORE_KEY_TYPE_2K3DES:
        case PH_KEYSTORE_KEY_TYPE_AES192:
        case PH_KEYSTORE_KEY_TYPE_3K3DES:
        case PH_KEYSTORE_KEY_TYPE_AES256:
        case PH_KEYSTORE_KEY_TYPE_DES:
        case PH_KEYSTORE_KEY_TYPE_MIFARE:
            bKeyLength = (uint8)phKeyStore_GetKeySize(wNewKeyType);
            break;

        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    pDataParams->pKeyEntries[wKeyNo].wKeyType = wNewKeyType;

    /* Reset KUC to master Key */
    pDataParams->pKeyEntries[wKeyNo].wRefNoKUC = wNewRefNoKUC;

    /* Reset all keys to 0x00*/
    for (i=0; i < wNoOfKeys ; i++)
    {
        PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrPos(pDataParams,wKeyNo,i,&pKeyVersion));
        pKeyVersion->wVersion = pNewKeyVersionList[i];
        phTools_memcpy(pKeyVersion->pKey, &pNewKeys[(i*bKeyLength)], bKeyLength);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKeyEntry(
                                     P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wKeyNo,
                                     VAR(uint16, ANFCRL_VAR) wKeyVersionBufSize,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersion,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersionLength,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint16, ANFCRL_VAR) i;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;

    /* Check for overflow */
    if (wKeyVersionBufSize < (sizeof(uint16) * pDataParams->wNoOfVersions))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_KEYSTORE);
    }

    for (i = 0; i < pDataParams->wNoOfVersions; i++)
    {
        PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrPos(pDataParams,wKeyNo,i,&pKeyVersion));
        wKeyVersion[i] = pKeyVersion->wVersion;
    }
    *wKeyVersionLength = pDataParams->wNoOfVersions;
    *pKeyType = pDataParams->pKeyEntries[wKeyNo].wKeyType;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKey(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                VAR(uint8, ANFCRL_VAR) bKeyBufSize,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint16, ANFCRL_VAR) wKeySize;
    P2VAR(phKeyStore_Sw_KeyVersionPair_t, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion = NULL;
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_GetKeyValuePtrVersion(pDataParams,wKeyNo,wKeyVersion,&pKeyVersion));

    /* Check for Counter overflow */
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_Sw_CheckUpdateKUC(pDataParams,pDataParams->pKeyEntries[wKeyNo].wRefNoKUC));

    /* check buffer size */
    wKeySize = phKeyStore_GetKeySize(pDataParams->pKeyEntries[wKeyNo].wKeyType);
    if (bKeyBufSize < wKeySize)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_KEYSTORE);
    }
    /* copy the key */
    phTools_memcpy(pKey, pKeyVersion->pKey, wKeySize);

    *pKeyType = pDataParams->pKeyEntries[wKeyNo].wKeyType;
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetConfig(
                                   P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   VAR(uint16, ANFCRL_VAR) wValue
                                   )
{
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(wConfig);
    PH_UNUSED_VARIABLE(wValue);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetConfigStr(
                                      P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer,
                                      VAR(uint16, ANFCRL_VAR) wBufferLength
                                      )
{
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(wConfig);
    PH_UNUSED_VARIABLE(pBuffer);
    PH_UNUSED_VARIABLE(wBufferLength);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetConfig(
                                   P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                   )
{
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(wConfig);
    PH_UNUSED_VARIABLE(pValue);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetConfigStr(
                                      P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppBuffer,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLength
                                      )
{
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(wConfig);
    PH_UNUSED_VARIABLE(ppBuffer);
    PH_UNUSED_VARIABLE(pBufferLength);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_KEYSTORE);
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKeyValuePtrPos(
    P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wKeyNumber,
    VAR(uint16, ANFCRL_VAR) wPos,
    P2VAR(phKeyStore_Sw_KeyVersionPair_t*, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion
    )
{
    *pKeyVersion = NULL;
    /* Overflow checks */
    if (wKeyNumber >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    /* Overflow checks */
    if (wPos >= pDataParams->wNoOfVersions)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    *pKeyVersion = &pDataParams->pKeyVersionPairs[(wKeyNumber * pDataParams->wNoOfVersions) + wPos];

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKeyValuePtrVersion(
    P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wKeyNumber,
    VAR(uint16, ANFCRL_VAR) wKeyVersion,
    P2VAR(phKeyStore_Sw_KeyVersionPair_t*, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion
    )
{
    VAR(uint16, ANFCRL_VAR) i;
    *pKeyVersion = NULL;
    /* Overflow checks */
    if (wKeyNumber >= pDataParams->wNoOfKeyEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    for (i=0;i<pDataParams->wNoOfVersions; i++)
    {
        *pKeyVersion = &pDataParams->pKeyVersionPairs[(wKeyNumber * pDataParams->wNoOfVersions) + i];
        if ((*pKeyVersion)->wVersion == wKeyVersion)
        {
            break;
        }
    }
    /* No entry found */
    if (i == pDataParams->wNoOfVersions)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_CheckUpdateKUC(
                                        P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint16, ANFCRL_VAR) wKeyUsageCtrNumber
                                        )
{
    if (wKeyUsageCtrNumber != PH_KEYSTORE_INVALID_ID)
    {
        /* Check for a valid KUC entry */
        if (wKeyUsageCtrNumber >= pDataParams->wNoOfKUCEntries)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
        }

        /* Now let's check the limit*/
        if (pDataParams->pKUCEntries[wKeyUsageCtrNumber].dwCurVal >= pDataParams->pKUCEntries[wKeyUsageCtrNumber].dwLimit)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_KEY, PH_COMP_KEYSTORE);
        }
        pDataParams->pKUCEntries[wKeyUsageCtrNumber].dwCurVal++;
    }
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_ChangeKUC(
                                   P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                   VAR(uint32, ANFCRL_VAR) dwLimit
                                   )
{
    /* Overflow checks */
    if (wRefNoKUC >= pDataParams->wNoOfKUCEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }
    pDataParams->pKUCEntries[wRefNoKUC].dwLimit = dwLimit;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKUC(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwLimit,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwCurVal
                                )
{
    /* Overflow checks */
    if (wRefNoKUC >= pDataParams->wNoOfKUCEntries)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_KEYSTORE);
    }

    *pdwLimit = pDataParams->pKUCEntries[wRefNoKUC].dwLimit;
    *pdwCurVal = pDataParams->pKUCEntries[wRefNoKUC].dwCurVal;

    return PH_ERR_SUCCESS;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef __cplusplus
}
#endif

