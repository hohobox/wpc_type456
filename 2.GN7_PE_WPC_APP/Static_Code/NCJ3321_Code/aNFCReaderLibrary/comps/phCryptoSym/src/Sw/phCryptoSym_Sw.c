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
*   @file    phCryptoSym_Sw.c
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
#ifdef NXPBUILD__PH_KEYSTORE
#include <phKeyStore.h>
#endif /* NXPBUILD__PH_KEYSTORE */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW

#include "phCryptoSym_Sw.h"
#include "../phCryptoSym_Int.h"
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
* @file           phCryptoSym_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_SW_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_SW_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_SW_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phCryptoSym_Sw.h header file are of the same vendor */
#if (PHCRYPTOSYM_SW_VENDOR_ID_C != PHCRYPTOSYM_SW_VENDOR_ID)
    #error "phCryptoSym_Sw.c and phCryptoSym_Sw.h have different vendor ids"
#endif
/* Check if current file and phCryptoSym_Sw.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_SW_AR_RELEASE_MAJOR_VERSION_C    != PHCRYPTOSYM_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_AR_RELEASE_MINOR_VERSION_C    != PHCRYPTOSYM_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_AR_RELEASE_REVISION_VERSION_C != PHCRYPTOSYM_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym_Sw.c and phCryptoSym_Sw.h are different"
#endif
/* Check if current file and phCryptoSym_Sw.h header file are of the same Software version */
#if ((PHCRYPTOSYM_SW_SW_MAJOR_VERSION_C != PHCRYPTOSYM_SW_SW_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_SW_MINOR_VERSION_C != PHCRYPTOSYM_SW_SW_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_SW_PATCH_VERSION_C != PHCRYPTOSYM_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym_Sw.c and phCryptoSym_Sw.h are different"
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
#if ((PHCRYPTOSYM_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Init(
                               P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams
                               )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    if (sizeof(phCryptoSym_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
    }
    PH_ASSERT_NULL (pDataParams);

    /* Init. private data */
    pDataParams->wId                    = PH_COMP_CRYPTOSYM | PH_CRYPTOSYM_SW_ID;
    pDataParams->pKeyStoreDataParams    = pKeyStoreDataParams;

    /* Invalidate keys */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_InvalidateKey(pDataParams));

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_InvalidateKey(
                                        P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                        )
{
    /* Reset all the key storage */
    (void)memset(pDataParams->pKey, 0x00, (size_t)sizeof(pDataParams->pKey));
    (void)memset(pDataParams->pIV, 0x00, (size_t)sizeof(pDataParams->pIV));
    pDataParams->wKeyType = PH_CRYPTOSYM_KEY_TYPE_INVALID;
    pDataParams->wKeepIV = PH_CRYPTOSYM_VALUE_KEEP_IV_OFF;

#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    pDataParams->bCMACSubKeysInitialized = PH_OFF;
    (void)memset(pDataParams->pCMACSubKey1, 0x00, (size_t)sizeof(pDataParams->pCMACSubKey1));
    (void)memset(pDataParams->pCMACSubKey2, 0x00, (size_t)sizeof(pDataParams->pCMACSubKey2));
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Encrypt(
                                  P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wOption,
                                  P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pPlainBuffer,
                                  VAR(uint16, ANFCRL_VAR) wBufferLength,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncryptedBuffer
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint16, ANFCRL_VAR) wBlockSize;
    VAR(uint16, ANFCRL_VAR) i;
    VAR(uint8, ANFCRL_VAR) j;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv = NULL;
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pHelperBuffer[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */

    /* Get the block size of the currently loaded key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* Check that the input buffer length is a multiple of the block size; */
    if (0U != (wBufferLength % wBlockSize))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Set the IV to the iv specified in the private data params */
    pIv = pDataParams->pIV;

    /*Iterate over all blocks and perform the encryption*/
    i = 0;
    while (i < wBufferLength)
    {
        /* Is the output array the same as the input array? Else we need to re-copy the plain text upfront */
        if (pPlainBuffer != pEncryptedBuffer)
        {
            (void)memcpy(&pEncryptedBuffer[i],&pPlainBuffer[i], wBlockSize );
        }

        /* In case of CBC mode, we need to perform the XOR with the previous cipher block */
        switch((uint8)(wOption))
        {
        case PH_CRYPTOSYM_CIPHER_MODE_CBC:
        case PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4:
            for (j = 0; j < wBlockSize; j++)
            {
                pEncryptedBuffer[j + i] ^= pIv[j];
            }
            break;
        case PH_CRYPTOSYM_CIPHER_MODE_ECB:
            /* Nothing to do here */
            break;
        default:
            /* Add additional Modes of operation in here! */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
        }

#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
        (void)memcpy(pHelperBuffer, &pEncryptedBuffer[i], wBlockSize);
        if ((uint8)wOption == PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4)
        {
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_DecryptBlock(pDataParams, pHelperBuffer));
        }
        else
        {
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, pHelperBuffer));
        }

        (void)memcpy(&pEncryptedBuffer[i], pHelperBuffer, wBlockSize);
#else
        if ((uint8)wOption == PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4)
        {
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_DecryptBlock(pDataParams, &pEncryptedBuffer[i]));
        }
        else
        {
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, &pEncryptedBuffer[i]));
        }

#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */

        /* do the loop dependent post processing of the data according to the used mode of operation*/
        switch((uint8)(wOption))
        {
        case PH_CRYPTOSYM_CIPHER_MODE_CBC:
        case PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4:
            /* we should set the IV now to the old ciphertext... */
            pIv = &pEncryptedBuffer[i];
            break;
        case PH_CRYPTOSYM_CIPHER_MODE_ECB:
            /* Nothing to do here */
            break;
        }

        /* update the loop counter */
        i = wBlockSize + i;
    } /* end of loop over all data blocks */

    /* do the final update of the IV according to the keep IV setting. */
    if ((pDataParams->wKeepIV == PH_CRYPTOSYM_VALUE_KEEP_IV_ON) ||
        (0U != (wOption & PH_EXCHANGE_BUFFERED_BIT)))
    {
        (void)memcpy(pDataParams->pIV, pIv, wBlockSize);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_Decrypt(
                                  P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wOption,
                                  P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pEncryptedBuffer,
                                  VAR(uint16, ANFCRL_VAR) wBufferLength,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainBuffer
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint16, ANFCRL_VAR) wBlockSize;
    VAR(uint16, ANFCRL_VAR) i;
    VAR(uint8, ANFCRL_VAR) j;
    VAR(uint8, ANFCRL_VAR) pIv[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE]; /* AES block size is the maximum available block size */
    VAR(uint8, ANFCRL_VAR) pNextIv[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE]; /* AES block size is the maximum available block size */
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pHelperBuffer[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */

    /* Clear buffer for QAC */
    (void)memset(pNextIv, 0, PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE);

    /* Get the block size of the currently loaded key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* Get IV */
    (void)memcpy(pIv, pDataParams->pIV, wBlockSize);

    /* Check that the input buffer length is a multiple of the block size; */
    if (0U != (wBufferLength % wBlockSize))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /*Iterate over all blocks and perform the decryption*/
    i = 0;
    while( i < wBufferLength)
    {

        /* Is the output array the same as the input array? Else we need to re-copy the encrypted data into the plain text data buffer first. */
        if (pEncryptedBuffer != pPlainBuffer)
        {
            (void)memcpy(&pPlainBuffer[i],&pEncryptedBuffer[i], wBlockSize );
        }

        /* perform pre processing of the data according to the selected mode of operation. */
        switch((uint8)(wOption))
        {
        case PH_CRYPTOSYM_CIPHER_MODE_CBC:
            /* Fall through */
        case PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4:
            /* In case of CBC mode, we need to remember the previous encrypted block */
            (void)memcpy(pNextIv,&pEncryptedBuffer[i], wBlockSize );
            break;
        case PH_CRYPTOSYM_CIPHER_MODE_ECB:
            /* Nothing to do! */
            break;
        default:
            /* Add additional Modes of operation in here! */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
        }

#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
        (void)memcpy(pHelperBuffer, &pPlainBuffer[i], wBlockSize);
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_DecryptBlock(pDataParams, pHelperBuffer));
        (void)memcpy(&pPlainBuffer[i], pHelperBuffer, wBlockSize);
#else
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_DecryptBlock(pDataParams,&pPlainBuffer[i]));

#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */

        /* perform post processing of the data according to the selected mode of operation. */
        switch((uint8)(wOption))
        {
        case PH_CRYPTOSYM_CIPHER_MODE_CBC:
        case PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4:
            /* In case of CBC mode, we need to perform the XOR with the previous cipher block */
            for (j=0; j < wBlockSize; ++j)
            {
                pPlainBuffer[j + i] ^= pIv[j];
            }
            /* Get IV */
            (void)memcpy(pIv, pNextIv, wBlockSize );
            break;
        case PH_CRYPTOSYM_CIPHER_MODE_ECB:
            /* Nothing to do here */
            break;
        }

        /* update the loop counter */
        i = wBlockSize + i;
    }

    if ((pDataParams->wKeepIV == PH_CRYPTOSYM_VALUE_KEEP_IV_ON) || (0U != ((wOption & PH_EXCHANGE_BUFFERED_BIT))))
    {
        /* Update IV */
        (void)memcpy(pDataParams->pIV, pIv, wBlockSize );
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_CalculateMac(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wOption,
                                       P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pData,
                                       VAR(uint16, ANFCRL_VAR) wDataLength,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMacLength
                                       )
{


    VAR(phStatus_t, ANFCRL_VAR) statusTmp;
    VAR(uint16, ANFCRL_VAR) wBlockSize;
    VAR(uint16, ANFCRL_VAR) i;
    VAR(uint8, ANFCRL_VAR) j;
    VAR(uint8, ANFCRL_VAR) bPaddingLength;
    VAR(uint8, ANFCRL_VAR) bLastBlock[16];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv = NULL;
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
    VAR(uint8, ANFCRL_VAR) PH_CRYTOSYM_SW_FAST_RAM pHelperBuffer[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
#endif /* PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE */
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

    /* Clear the last block array */
    (void)memset(bLastBlock, 0, (size_t)sizeof(bLastBlock));

    /* Get the block size of the currently loaded key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* In case of a first block and in case of KEEP_IV is not set, the IV has to be cleared. */
    if ((0U != (wOption & PH_EXCHANGE_LEAVE_BUFFER_BIT)) ||
        (pDataParams->wKeepIV == PH_CRYPTOSYM_VALUE_KEEP_IV_ON))
    {
        /* better leave the IV */
    }else
    {
        (void)memset(pDataParams->pIV, 0x00, wBlockSize);
    }

    /* Now we may start with  MAC calculation */

    /*Let's find out whether we should complete the MAC or if this is just an intermediate MAC calculation */
    if (0U != (wOption & PH_EXCHANGE_BUFFERED_BIT))
    {
        /* This is just an intermediate MAC */

        /* In this case we do not allow incomplete blocks. */
        if (0U != (wDataLength % wBlockSize))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
    }
    else
    {
        switch((uint8)(wOption))
        {
        case PH_CRYPTOSYM_MAC_MODE_CMAC:
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
            break;
        case PH_CRYPTOSYM_MAC_MODE_CBCMAC:
            /* Nothing to do! */
            break;
        default:
            /* Add additional Modes of operation in here! */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
        }

        /* Get number of bytes in last block */
        bPaddingLength = (uint8)(wDataLength % wBlockSize);

        /* do we have incomplete blocks? */
        if ((0U != (bPaddingLength)) || (wDataLength == 0x0000U))
        {
            /* Update wDataLength, last block is in other array */
            wDataLength = wDataLength - bPaddingLength; /* PRQA S 0291 */

            if(bPaddingLength != 0U)
            {
                (void)memcpy(bLastBlock, &pData[wDataLength], bPaddingLength);
            }
            /* Apply padding byte*/
            bLastBlock[bPaddingLength] = 0x80;
            /* pad with zeros not necessary, memset done upfront*/

            if ((uint8)wOption == PH_CRYPTOSYM_MAC_MODE_CMAC)
            {

                /* XOR with K2, as we have an incomplete block */
                for (j=0;j<wBlockSize; j++)
                {
                    bLastBlock[j] ^= pSubKey2[j];
                }
            }
        }else
        {
            /* Update wDataLength, last block is in other array */
            wDataLength = wDataLength - wBlockSize;
            /* Copy whole block into bLastBlock */
            (void)memcpy(bLastBlock, &pData[wDataLength], wBlockSize);

            if ((uint8)wOption == PH_CRYPTOSYM_MAC_MODE_CMAC)
            {
                /* XOR with K1, as we have a complete block */
                for (j=0;j<wBlockSize; j++)
                {
                    bLastBlock[j] ^= pSubKey1[j];
                }
            }
        }
    }


    /* Set the IV to the iv specified in the private data params */
    pIv = pDataParams->pIV;

    /*Iterate over all blocks and perform the CBC encryption*/
    i=0;
    while(i < wDataLength)
    {
        /* perform the XOR with the previous cipher block */
        for (j = 0; j < wBlockSize; j++)
        {
            /* Note: after one round pIv == pMac */
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
            pHelperBuffer[j] = pIv[j] ^ pData[i+j];
#else
            pMac[j] = pIv[j] ^ pData[i+j];
#endif
        }

#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, pHelperBuffer));
        (void)memcpy(pMac, pHelperBuffer, wBlockSize);
#else
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, pMac));
#endif

        /* set pIv to last cipher block*/
        pIv = pMac;

        /* update the loop counter */
        i = wBlockSize + i;
    } /* end of loop over all data blocks */

    /* If we have a complete MAC, lets encrypt the last block */
    if (0U == (wOption & PH_EXCHANGE_BUFFERED_BIT))
    {
        /* Encrypt last block. */
        /* perform the XOR with the previous cipher block */
        for (j = 0; j < wBlockSize; j++)
        {
            /* Note: after one round pIv == pMac */
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
            pHelperBuffer[j] = pIv[j] ^ bLastBlock[j];
#else
            pMac[j] = pIv[j] ^ bLastBlock[j];
#endif
        }
#ifdef PH_CRYPTOSYM_SW_USE_8051_DATA_STORAGE
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, pHelperBuffer));
        (void)memcpy(pMac, pHelperBuffer, wBlockSize );
#else
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_EncryptBlock(pDataParams, pMac));
#endif

    }

    /* do the final update of the IV according to the settings */
    if ((pDataParams->wKeepIV == PH_CRYPTOSYM_VALUE_KEEP_IV_ON) ||
        (0U != (wOption & PH_EXCHANGE_BUFFERED_BIT)))
    {
        (void)memcpy(pDataParams->pIV, pMac, wBlockSize );
    }else
    {
        /* Clear the IV for security reasons */
        (void)memset(pDataParams->pIV, 0, wBlockSize );
    }

#ifdef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    /* Clear key arrays */
    (void)memset(pSubKey1, 0x00, (size_t)sizeof(pSubKey1));
    (void)memset(pSubKey2, 0x00, (size_t)sizeof(pSubKey2));
#endif

    *pMacLength = (uint8) wBlockSize;
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_LoadIv(
                                 P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pIV,
                                 VAR(uint8, ANFCRL_VAR) bIVLength
                                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBlockSize;

    /* Get the block size of the currently loaded key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_GetConfig(pDataParams, PH_CRYPTOSYM_CONFIG_BLOCK_SIZE, &wBlockSize));

    /* Check block-size */
    if (bIVLength != wBlockSize)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Update IV */
    (void)memcpy(pDataParams->pIV, pIV,wBlockSize);

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_LoadKey(
                                  P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wKeyNo,
                                  VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                  VAR(uint16, ANFCRL_VAR) wKeyType
                                  )
{
#ifdef NXPBUILD__PH_KEYSTORE
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aKey[PH_CRYPTOSYM_AES256_KEY_SIZE];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyTypeStorage;

    /* Not possible without keystore */
    if (pDataParams->pKeyStoreDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_CRYPTOSYM);
    }

    /* Retrieve key settings */
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
        pDataParams->pKeyStoreDataParams,
        wKeyNo,
        wKeyVersion,
        (uint8)(sizeof(aKey)),
        aKey,
        &wKeyTypeStorage));

    /* KeyType should match */
    if (wKeyType != wKeyTypeStorage)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Finally load the key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_LoadKeyDirect(pDataParams, aKey, wKeyType));

    /* For security reasons */
    (void)memset(aKey, 0x00, (size_t)sizeof(aKey));

    return PH_ERR_SUCCESS;
#else
    UNUSED(pDataParams); UNUSED(wKeyNo); UNUSED(wKeyVersion); UNUSED(wKeyType);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_CRYPTOSYM);
#endif /* NXPBUILD__PH_KEYSTORE */
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_LoadKeyDirect(
                                        P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,
                                        VAR(uint16, ANFCRL_VAR) wKeyType
                                        )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

    /* Clear existing key */
    (void)memset(pDataParams->pKey, 0x00, (size_t)sizeof(pDataParams->pKey));

#ifndef PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION
    /* Disable the CMAC calculated Flag */
    pDataParams->bCMACSubKeysInitialized = PH_OFF;
#endif /* PH_CRYPTOSYM_SW_ONLINE_CMAC_SUBKEY_CALCULATION */

    switch(wKeyType)
    {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_KeyExpansion(
            pDataParams,
            pKey,
            PH_CRYPTOSYM_AES128_KEY_SIZE >> 2U,
            (PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_128 + 1U) << 2U));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_KeyExpansion(
            pDataParams,
            pKey,
            PH_CRYPTOSYM_AES192_KEY_SIZE >> 2U,
            (PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_192 + 1U) << 2U));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Aes_KeyExpansion(
            pDataParams,
            pKey,
            PH_CRYPTOSYM_AES256_KEY_SIZE >> 2U,
            (PH_CRYPTOSYM_SW_NUM_AES_ROUNDS_256 + 1U) << 2U));
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_KeyInit(pDataParams, pKey, 1));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_KeyInit(pDataParams, pKey, 2));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_KeyInit(pDataParams, pKey, 3));
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Update global KeyType */
    pDataParams->wKeyType = wKeyType;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_DiversifyKey(
                                       P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wOption,
                                       VAR(uint16, ANFCRL_VAR) wKeyNo,
                                       VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
                                       VAR(uint8, ANFCRL_VAR) bLenDivInput,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey
                                       )
{
#ifdef NXPBUILD__PH_KEYSTORE
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES256_KEY_SIZE];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;

    /* Not possible without keystore */
    if (pDataParams->pKeyStoreDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_CRYPTOSYM);
    }

    /* Parameter check */
    if (((wOption & PH_CRYPTOSYM_DIV_MODE_MASK) != PH_CRYPTOSYM_DIV_MODE_DESFIRE) &&
        ((wOption & PH_CRYPTOSYM_DIV_MODE_MASK) != PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* Retrieve key from keystore */
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
        pDataParams->pKeyStoreDataParams,
        wKeyNo,
        wKeyVersion,
        (uint8)sizeof(aKey),
        aKey,
        &wKeyType));

    /* Perform diversification */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_DiversifyDirectKey(
        pDataParams,
        wOption,
        aKey,
        wKeyType,
        pDivInput,
        bLenDivInput,
        pDiversifiedKey));

    /* For security reasons */
    (void)memset(aKey, 0x00, (size_t)sizeof(aKey));

    return PH_ERR_SUCCESS;
#else
    UNUSED(pDataParams); UNUSED(wKeyNo); UNUSED(wKeyVersion); UNUSED(pDiversifiedKey); UNUSED(bLenDivInput); UNUSED(pDivInput); UNUSED(wOption);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_CRYPTOSYM);
#endif  /* NXPBUILD__PH_KEYSTORE */
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_DiversifyDirectKey(
    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
    VAR(uint16, ANFCRL_VAR) wKeyType,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
    VAR(uint8, ANFCRL_VAR) bLenDivInput,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF abDivData[PH_CRYPTOSYM_SW_KDIV_MFP_DIVLENGTH_AES_MAX + 1U];
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF abMac[16];
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmpLength;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyVersion;

    /* Load the Key to diversify */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_LoadKeyDirect(pDataParams, pKey, wKeyType));

    /* Check diversification method */
    switch (wOption & PH_CRYPTOSYM_DIV_MODE_MASK)
    {
    case PH_CRYPTOSYM_DIV_MODE_DESFIRE:
        switch (wKeyType)
        {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
            /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        /* Parameter check */
        if (bLenDivInput != PH_CRYPTOSYM_AES128_KEY_SIZE)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }

        /* Use the DivData as IV */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_LoadIv(pDataParams, pDivInput, bLenDivInput));

        /* Retrieve KeySize */
        bLenDivInput = (uint8)phCryptoSym_GetKeySize(wKeyType);

        /* Copy Key to temporary diversification data */
        (void)memcpy(abDivData, pKey, bLenDivInput);

        /* Apply padding if necessary */
        if ((bLenDivInput % PH_CRYPTOSYM_AES_BLOCK_SIZE) != 0U)
        {
            (void)memset(&abDivData[PH_CRYPTOSYM_AES192_KEY_SIZE], 0x00, 8);
            bTmpLength = PH_CRYPTOSYM_AES192_KEY_SIZE + 8U;
        }
        else
        {
            bTmpLength = bLenDivInput;
        }

        /* Perform Encryption */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Encrypt(
            pDataParams,
            PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
            abDivData,
            (uint16)bTmpLength,
            abDivData));

        /* Copy diversified Key to output buffer */
        (void)memcpy(pDiversifiedKey, abDivData, bLenDivInput);
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        /* Parameter check */
        if (bLenDivInput != PH_CRYPTOSYM_DES_KEY_SIZE)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }

        /* Use the DivData as IV */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_LoadIv(pDataParams, pDivInput, bLenDivInput));

        /* Retrieve KeyVersion */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecodeVersion(pKey, &wKeyVersion));

        /* Half-Key Diversification */
        if (0U != (wOption & PH_CRYPTOSYM_DIV_OPTION_2K3DES_HALF))
        {
            /* Perform Encryption */
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Encrypt(
                pDataParams,
                PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
                pKey,
                PH_CRYPTOSYM_DES_KEY_SIZE,
                pDiversifiedKey));

            /* half key diversification -> copy first part to second part */
            (void)memcpy(&pDiversifiedKey[PH_CRYPTOSYM_DES_KEY_SIZE], &pDiversifiedKey[0], PH_CRYPTOSYM_DES_KEY_SIZE);
        }
        /* Full-Key Diversification */
        else
        {
            /* Perform Encryption */
            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Encrypt(
                pDataParams,
                PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
                pKey,
                PH_CRYPTOSYM_2K3DES_KEY_SIZE,
                pDiversifiedKey));
        }

        /* Re-Encode KeyVersion */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncodeVersion(pDiversifiedKey, wKeyVersion, wKeyType, pDiversifiedKey));

        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        /* Parameter check */
        if (bLenDivInput != PH_CRYPTOSYM_DES_KEY_SIZE)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }

        /* Use the DivData as IV */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_LoadIv(pDataParams, pDivInput, bLenDivInput));

        /* Retrieve KeyVersion */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_DecodeVersion(pKey, &wKeyVersion));

        /* Perform Encryption */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Encrypt(
            pDataParams,
            PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
            pKey,
            PH_CRYPTOSYM_3K3DES_KEY_SIZE,
            pDiversifiedKey));

        /* Re-Encode KeyVersion */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Des_EncodeVersion(pDiversifiedKey, wKeyVersion, wKeyType, pDiversifiedKey));

        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
        break;
    case PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS:
        /* Parameter check */
        if (bLenDivInput > PH_CRYPTOSYM_SW_KDIV_MFP_DIVLENGTH_AES_MAX)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }

        /* Copy div. input */
        (void)memcpy(&abDivData[1], pDivInput, bLenDivInput);

        /* Increment div. input length */
        ++bLenDivInput;

        switch (wKeyType)
        {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        /* Set div. header */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_AES128_CONST;

        /* Perform MAC calculation */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            pDiversifiedKey,
            &bTmpLength));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        /* Set div. header for DiversifiedKeyA */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_AES192_CONST_1;

        /* Perform MAC calculation (KeyA) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            pDiversifiedKey,
            &bTmpLength));

        /* Set div. header for DiversifiedKeyB */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_AES192_CONST_2;

        /* Perform MAC calculation (KeyB) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            abMac,
            &bTmpLength));

        /* perform DiversifiedKeyA[8-15] ^ DiversifiedKeyB[0-7] */
        for (bTmpLength = 0; bTmpLength < 8U; ++bTmpLength)
        {
            pDiversifiedKey[8U + bTmpLength] ^= abMac[bTmpLength];
        }

        /* copy DiversifiedKeyB[8-15] to DiversifiedKey[16-23] */
        (void)memcpy(&pDiversifiedKey[16], &abMac[8], 8);
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        /* Set div. header for DiversifiedKeyA */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_3DES_CONST_1;

        /* Perform MAC calculation (KeyA) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            &pDiversifiedKey[0],
            &bTmpLength));

        /* Set div. header for DiversifiedKeyB */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_3DES_CONST_2;

        /* Perform MAC calculation (KeyB) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            &pDiversifiedKey[8],
            &bTmpLength));
        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        /* Set div. header for DiversifiedKeyA */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_1;

        /* Perform MAC calculation (KeyA) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            &pDiversifiedKey[0],
            &bTmpLength));

        /* Set div. header for DiversifiedKeyB */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_2;

        /* Perform MAC calculation (KeyB) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            &pDiversifiedKey[8],
            &bTmpLength));

        /* Set div. header for DiversifiedKeyC */
        abDivData[0] = PH_CRYPTOSYM_SW_KDIV_MFP_3KEY3DES_CONST_3;

        /* Perform MAC calculation (KeyC) */
        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Sw_Diversify_CMAC(
            pDataParams,
            abDivData,
            (uint16)bLenDivInput,
            &pDiversifiedKey[16],
            &bTmpLength));
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_SetConfig(
                                    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wConfig,
                                    VAR(uint16, ANFCRL_VAR) wValue
                                    )
{
    switch (wConfig)
    {
    case PH_CRYPTOSYM_CONFIG_KEEP_IV:
        /* parameter check */
        if ((wValue != PH_CRYPTOSYM_VALUE_KEEP_IV_OFF) &&
            (wValue != PH_CRYPTOSYM_VALUE_KEEP_IV_ON))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
        pDataParams->wKeepIV = wValue;
        break;

    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Sw_GetConfig(
                                    P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wConfig,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                    )
{
    switch(wConfig)
    {
    case PH_CRYPTOSYM_CONFIG_KEY_SIZE:
        switch(pDataParams->wKeyType)
        {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        *pValue = PH_CRYPTOSYM_AES128_KEY_SIZE;
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        *pValue = PH_CRYPTOSYM_AES192_KEY_SIZE;
        break;
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        *pValue = PH_CRYPTOSYM_AES256_KEY_SIZE;
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        *pValue = PH_CRYPTOSYM_DES_KEY_SIZE;
        break;
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        *pValue = PH_CRYPTOSYM_2K3DES_KEY_SIZE;
        break;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        *pValue = PH_CRYPTOSYM_3K3DES_KEY_SIZE;
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
        break;
    case PH_CRYPTOSYM_CONFIG_BLOCK_SIZE:
        switch(pDataParams->wKeyType)
        {
#ifdef PH_CRYPTOSYM_SW_AES
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        *pValue = PH_CRYPTOSYM_AES_BLOCK_SIZE;
        break;
#endif /* PH_CRYPTOSYM_SW_AES */
#ifdef PH_CRYPTOSYM_SW_DES
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
        /* Fall through */
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
        *pValue = PH_CRYPTOSYM_DES_BLOCK_SIZE;
        break;
#endif /* PH_CRYPTOSYM_SW_DES */
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
        break;
    case PH_CRYPTOSYM_CONFIG_KEY_TYPE:
        *pValue = pDataParams->wKeyType;
        break;
    case PH_CRYPTOSYM_CONFIG_KEEP_IV:
        *pValue = pDataParams->wKeepIV;
        break;
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
#ifdef __cplusplus
}
#endif /* __cplusplus */