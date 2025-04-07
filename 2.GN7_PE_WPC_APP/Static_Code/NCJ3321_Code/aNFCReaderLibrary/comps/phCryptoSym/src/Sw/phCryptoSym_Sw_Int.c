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
*   @file    phCryptoSym_Sw_Int.c
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

#ifdef NXPBUILD__PH_CRYPTOSYM_SW

#include "phCryptoSym_Sw.h"
#ifdef PH_CRYPTOSYM_SW_AES
#include "phCryptoSym_Sw_Aes.h"
#endif
#ifdef PH_CRYPTOSYM_SW_DES
#include "phCryptoSym_Sw_Des.h"
#endif
#include "phCryptoSym_Sw_Int.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym_Sw_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_INT_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_INT_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_INT_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_INT_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phCryptoSym_Sw_Int.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_INT_VENDOR_ID_C != PHCRYPTOSYM_SW_INT_VENDOR_ID)
    #error "phCryptoSym_Sw_Int.c and phCryptoSym_Sw_Int.h have different vendor ids"
#endif
/* Check if current file and phCryptoSym_Sw_Int.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION_C    != PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION_C    != PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_INT_AR_RELEASE_REVISION_VERSION_C != PHCRYPTOSYM_SW_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw_Int.c and phCryptoSym_Sw_Int.h are different"
#endif
/* Check if current file and phCryptoSym_Sw_Int.h header file are of the same Software version */
#if ((PHCRYPTOSYM_SW_INT_SW_MAJOR_VERSION_C != PHCRYPTOSYM_SW_INT_SW_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_INT_SW_MINOR_VERSION_C != PHCRYPTOSYM_SW_INT_SW_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_INT_SW_PATCH_VERSION_C != PHCRYPTOSYM_SW_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw_Int.c and phCryptoSym_Sw_Int.h are different"
#endif
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
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
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_CMAC_GenerateK1K2(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey1,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey2
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM aBuffer[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBlockSize;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bR_b;

    (void)memset(aBuffer, 0x00, (size_t)sizeof(aBuffer));

    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* Calculate xor value according to Seq. 5.3 of SP_800-38B */
    /* R128 = 0exp(120) || 10000111, and R64 = 0exp(59) || 11011. */
    switch (wBlockSize)
    {
    case PH_CRYPTOSYM_AES_BLOCK_SIZE:
        bR_b = 0x87U;
        break;
    case PH_CRYPTOSYM_DES_BLOCK_SIZE:
        bR_b = 0x1BU;
        break;
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_CRYPTOSYM);
    }

    /* Encrypt zero block*/
    /* 1. Let L = CIPHK(0 exp b). */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, aBuffer));

    /* Shift the pSubKey array according to NIST SP_800-38B */
    /* 2. If MSB1(L) = 0, then K1 = L << 1U; */
    /* Else K1 = (L << 1U) xor Rb; see Sec. 5.3 for the definition of Rb. */
    phCryptoSym_Sw_CMAC_LeftShift(aBuffer, (uint8)wBlockSize, pSubKey1);
    if (0U != (aBuffer[0] & 0x80U))
    {
        /* We need to perform the XOR operation with the R_b array */
        pSubKey1[wBlockSize - 1U ]  ^= bR_b;
    }
    else
    {
        /* We are done with key1 generation */
    }

    /* Now let's continue with Key 2 */
    /* Shift the pSubKey array according to NIST SP_800-38B*/
    /* 3. If MSB1(K1) = 0, then K2 = K1 << 1U; */
    /* Else K2 = (K1 << 1U) xor Rb. */
    phCryptoSym_Sw_CMAC_LeftShift(pSubKey1, (uint8)wBlockSize, pSubKey2);

    if (0U != (pSubKey1[0] & 0x80U))
    {
        /* We need to perform the XOR operation with the R_b array */
        pSubKey2[wBlockSize - 1U ]  ^= bR_b;
    }
    else
    {
        /* We are done with key2 generation */
    }

#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    pDataParams->bCMACSubKeysInitialized    = PH_ON;
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */

    /* Clear buffer for security reasons */
    (void)memset(aBuffer, 0x00, (size_t)sizeof(aBuffer));

    return PH_ERR_SUCCESS;
}

FUNC(void, ANFCRL_CODE) phCryptoSym_Sw_CMAC_LeftShift(
                                   P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pInBuffer,
                                   VAR(uint8, ANFCRL_VAR) bInputLen,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer
                                   )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bOverflow = 0;

    do
    {
        bInputLen--;
        pOutBuffer[bInputLen] = pInBuffer[bInputLen] << 1U;
        pOutBuffer[bInputLen] |= bOverflow;
        bOverflow = (uint8) (((pInBuffer[bInputLen] & 0x80U) != 0U) ? 0x01U : 0x00U);
    }
    while(0U != bInputLen);
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_EncryptBlock(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

    switch (pDataParams->wKeyType)
    {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_EncryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_128));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_EncryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_192));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_EncryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_256));
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            0));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            0));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            1));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            0));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            0));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            1));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            2));
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_DecryptBlock(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_CRYTOSYM_SW_FAST_RAM pBlock
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

    switch (pDataParams->wKeyType)
    {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_DecryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_128));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_DecryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_192));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_DecryptBlock(
            pDataParams,
            pBlock,
            PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_256));
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            0));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            0));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            1));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            0));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            2));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncryptBlock(
            pDataParams,
            pBlock,
            1));
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecryptBlock(
            pDataParams,
            pBlock,
            0));
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Diversify_CMAC(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pData,
    VAR(uint16, ANFCRL_VAR) wDataLength,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMacLength
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBlockSize;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex;
    uint8     PH_MEMLOC_REM aTmpData[PH_CRYPTOSYM_AES_BLOCK_SIZE * 2U];
#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey1 = pDataParams->pCMACSubKey1;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSubKey2 = pDataParams->pCMACSubKey2;
#else
    VAR(uint8, ANFCRL_VAR) pSubKey1[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
    VAR(uint8, ANFCRL_VAR) pSubKey2[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];

    (void)memset(pSubKey1, 0x00, (size_t)sizeof(pSubKey1));
    (void)memset(pSubKey2, 0x00, (size_t)sizeof(pSubKey2));
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */

    /* Clear MAC length */
    *pMacLength = 0;

    /* Get the block size of the currently loaded key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* Check input length */
    if (wDataLength > (wBlockSize << 1U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_LENGTH_ERROR, PH_COMP_CRYPTOSYM);
    }

    /* Clear IV */
    (void)memset(pDataParams->pIV, 0x00, wBlockSize);

    /* Now we may start with  MAC calculation */

#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    /* Do we need to compute the sub keys? */
    if (pDataParams->bCMACSubKeysInitialized == 0x00U)
    {
        /* start with sub key generation */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_CMAC_GenerateK1K2(pDataParams, pSubKey1, pSubKey2));
    }
#else
    /* Always perform with sub key generation */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_CMAC_GenerateK1K2(pDataParams, pSubKey1, pSubKey2));
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */

    /* Copy data to temporary buffer */
    (void)memcpy(aTmpData, pData, wDataLength);

    /* Two full blocks -> NO PADDING, K1 */
    if (wDataLength == (wBlockSize << 1U))
    {
        /* XOR with K1 */
        for (wIndex = 0; wIndex < wBlockSize; ++wIndex)
        {
            aTmpData[wBlockSize + wIndex] ^= pSubKey1[wIndex];
        }
    }
    /* Otherwise APPLY PADDING, K2 */
    else
    {
        /* Apply padding */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
            PH_CRYPTOSYM_PADDING_MODE_2,
            aTmpData,
            wDataLength,
            (uint8)(wBlockSize << 1U),
            (uint16)(sizeof(aTmpData)),
            aTmpData,
            &wDataLength));

        /* XOR with K2 */
        for (wIndex = 0; wIndex < wBlockSize; ++wIndex)
        {
            aTmpData[wBlockSize + wIndex] ^= pSubKey2[wIndex];
        }
    }

    /* Perform encryption */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Encrypt(
        pDataParams,
        PH_CRYPTOSYM_CIPHER_MODE_CBC,
        aTmpData,
        (PH_CRYPTOSYM_AES_BLOCK_SIZE * 2U),
        aTmpData));

    /* Return MAC */
    (void)memcpy(pMac, &aTmpData[wBlockSize], wBlockSize);
    *pMacLength = (uint8)wBlockSize;

    /* Clear the IV for security reasons */
    (void)memset(pDataParams->pIV, 0, wBlockSize);

#ifdef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    /* Clear key arrays */
    (void)memset(pSubKey1, 0x00, (size_t)sizeof(pSubKey1));
    (void)memset(pSubKey2, 0x00, (size_t)sizeof(pSubKey2));
#endif

    return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
#ifdef __cplusplus
}
#endif /* __cplusplus */