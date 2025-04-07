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
*   @file    phCryptoSym.c
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
#include <phCryptoSym.h>
#include <ph_RefDefs.h>
#include "phCryptoSym_Int.h"

#ifdef NXPBUILD__PH_CRYPTOSYM_SW
#include "Sw/phCryptoSym_Sw.h"
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
#ifdef NXPBUILD__PH_CRYPTOSYM
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCryptoSym.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCRYPTOSYM_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHCRYPTOSYM_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHCRYPTOSYM_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHCRYPTOSYM_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHCRYPTOSYM_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phCryptoSym.h header file are of the same vendor */
#if (PHCRYPTOSYM_VENDOR_ID_C != PHCRYPTOSYM_VENDOR_ID)
    #error "phCryptoSym.c and phCryptoSym.h have different vendor ids"
#endif
/* Check if current file and phCryptoSym.h header file are of the same Autosar version */
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION_C    != PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION) || \
     (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION_C    != PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION) || \
     (PHCRYPTOSYM_AR_RELEASE_REVISION_VERSION_C != PHCRYPTOSYM_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCryptoSym.c and phCryptoSym.h are different"
#endif
/* Check if current file and phCryptoSym.h header file are of the same Software version */
#if ((PHCRYPTOSYM_SW_MAJOR_VERSION_C != PHCRYPTOSYM_SW_MAJOR_VERSION) || \
     (PHCRYPTOSYM_SW_MINOR_VERSION_C != PHCRYPTOSYM_SW_MINOR_VERSION) || \
     (PHCRYPTOSYM_SW_PATCH_VERSION_C != PHCRYPTOSYM_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCryptoSym.c and phCryptoSym.h are different"
#endif
#endif /* NXPBUILD__PH_CRYPTOSYM */
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
#ifdef NXPBUILD__PH_CRYPTOSYM
#define ANFCRL_START_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_InvalidateKey(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }
    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_InvalidateKey((phCryptoSym_Sw_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Encrypt(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               VAR(uint16, ANFCRL_VAR) wOption,
                               P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pPlainBuffer,
                               VAR(uint16, ANFCRL_VAR) wBufferLength,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncryptedBuffer
                               )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pPlainBuffer);
    PH_ASSERT_NULL (pEncryptedBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_Encrypt((phCryptoSym_Sw_DataParams_t *)pDataParams, wOption, pPlainBuffer,wBufferLength,pEncryptedBuffer);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_Decrypt(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               VAR(uint16, ANFCRL_VAR) wOption,
                               P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pEncryptedBuffer,
                               VAR(uint16, ANFCRL_VAR) wBufferLength,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainBuffer
                               )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pEncryptedBuffer);
    PH_ASSERT_NULL (pPlainBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_Decrypt((phCryptoSym_Sw_DataParams_t *)pDataParams,wOption,pEncryptedBuffer,wBufferLength,pPlainBuffer);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_CalculateMac(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wOption,
                                    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pData,
                                    VAR(uint16, ANFCRL_VAR) wDataLength,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMacLength
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pData);
    PH_ASSERT_NULL (pMac);
    PH_ASSERT_NULL (pMacLength);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_CalculateMac((phCryptoSym_Sw_DataParams_t *)pDataParams, wOption, pData,wDataLength,pMac,pMacLength);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadIv(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                              P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pIV,
                              VAR(uint8, ANFCRL_VAR) bIVLength
                              )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pIV);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_LoadIv((phCryptoSym_Sw_DataParams_t *)pDataParams, pIV, bIVLength);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadKey(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               VAR(uint16, ANFCRL_VAR) wKeyNo,
                               VAR(uint16, ANFCRL_VAR) wKeyVersion,
                               VAR(uint16, ANFCRL_VAR) wKeyType
                               )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_LoadKey((phCryptoSym_Sw_DataParams_t *)pDataParams,wKeyNo,wKeyVersion,wKeyType);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_LoadKeyDirect(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pKey,
                                     VAR(uint16, ANFCRL_VAR) wKeyType
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pKey);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_LoadKeyDirect((phCryptoSym_Sw_DataParams_t *)pDataParams,pKey,wKeyType);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_DiversifyKey(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wOption,
                                    VAR(uint16, ANFCRL_VAR) wKeyNo,
                                    VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
                                    VAR(uint8, ANFCRL_VAR) bLenDivInput,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    if (0U != bLenDivInput) PH_ASSERT_NULL (pDivInput);
    PH_ASSERT_NULL (pDiversifiedKey);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_DiversifyKey((phCryptoSym_Sw_DataParams_t *)pDataParams, wOption, wKeyNo, wKeyVersion, pDivInput, bLenDivInput, pDiversifiedKey);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_DiversifyDirectKey(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
    VAR(uint16, ANFCRL_VAR) wKeyType,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
    VAR(uint8, ANFCRL_VAR) bLenDivInput,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiversifiedKey
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pKey);
    if (0U != (bLenDivInput)) PH_ASSERT_NULL (pDivInput);
    PH_ASSERT_NULL (pDiversifiedKey);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_DiversifyDirectKey((phCryptoSym_Sw_DataParams_t *)pDataParams, wOption, pKey, wKeyType, pDivInput, bLenDivInput, pDiversifiedKey);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_SetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 VAR(uint16, ANFCRL_VAR) wValue
                                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_SetConfig((phCryptoSym_Sw_DataParams_t *)pDataParams,wConfig,wValue);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_GetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CRYPTOSYM)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CRYPTOSYM_SW
    case PH_CRYPTOSYM_SW_ID:
        status = phCryptoSym_Sw_GetConfig((phCryptoSym_Sw_DataParams_t *)pDataParams,wConfig,pValue);
        break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CRYPTOSYM);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_ApplyPadding(
                                    VAR(uint8, ANFCRL_VAR) bOption,
                                    P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pDataIn,
                                    VAR(uint16, ANFCRL_VAR) wDataInLength,
                                    VAR(uint8, ANFCRL_VAR) bBlockSize,
                                    VAR(uint16, ANFCRL_VAR) wDataOutBufSize,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataOutLength
                                    )
{
    VAR(uint8, ANFCRL_VAR) bPaddingLength;
    (*pDataOutLength) = 0;

    /* How many bytes we have to pad? */
    bPaddingLength = (uint8)(wDataInLength % bBlockSize);
    if ((bPaddingLength == 0x00U) &&(bOption != PH_CRYPTOSYM_PADDING_MODE_1))
    {
        bPaddingLength = (uint8)bBlockSize;
    }else
    {
        bPaddingLength = (uint8)(bBlockSize - bPaddingLength);
    }

    /* Do we have sufficient space in the output buffer? */
    if (wDataOutBufSize < (wDataInLength + bPaddingLength))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_CRYPTOSYM);
    }

    /* Re-copy the array in case pDataIn != pDataOut */
    if (pDataIn != pDataOut)
    {
        (void)memcpy(pDataOut, pDataIn, wDataInLength);
    }

    /* Add the padding constant */
    switch(bOption)
    {
    case PH_CRYPTOSYM_PADDING_MODE_1:
        pDataOut[wDataInLength++] = 0x00;
        break;
    case PH_CRYPTOSYM_PADDING_MODE_2:
        pDataOut[wDataInLength++] = 0x80;
        break;
    default:
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }
    bPaddingLength--;
    while(0U != (bPaddingLength--))
    {
        /* Add zeros */
        pDataOut[wDataInLength++] = 0x00;
    }

    (*pDataOutLength) = wDataInLength;
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phCryptoSym_RemovePadding(
                                     VAR(uint8, ANFCRL_VAR) bOption,
                                     P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pDataIn,
                                     VAR(uint16, ANFCRL_VAR) wDataInLength,
                                     VAR(uint8, ANFCRL_VAR) bBlockSize,
                                     VAR(uint16, ANFCRL_VAR) wDataOutBufSize,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataOutLength
                                     )
{
    VAR(uint8, ANFCRL_VAR) bFinished = 0;
    (*pDataOutLength) = 0;

    /* Is the data in length a multiple of the blocksize?? */
    if (0U != (wDataInLength % bBlockSize))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
    }

    /* find the padding constant */
    while((wDataInLength > 0U)&&(bFinished == 0U))
    {
        wDataInLength--;
        switch(bOption)
        {
        case PH_CRYPTOSYM_PADDING_MODE_1:
            if (pDataIn[wDataInLength] != 0x00U)
            {
                bFinished = 1;
                wDataInLength++;
                break;
            }else
            {
                /* Continue processing */
            }
            break;
        case PH_CRYPTOSYM_PADDING_MODE_2:
            if (pDataIn[wDataInLength] == 0x80U)
            {
                bFinished = 1;
                break;
            }else if (pDataIn[wDataInLength] != 0x00U)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_FRAMING_ERROR, PH_COMP_CRYPTOSYM);
            }else
            {
                continue;/* Continue processing */
            }
        default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_CRYPTOSYM);
        }
    }

    /* In case of it is not the last byte, we can set the correct new data out length, otherwise we have a out data length of 0. */
    (*pDataOutLength) = wDataInLength;

    /* do we have a buffer overflow? */
    if (wDataOutBufSize < (*pDataOutLength))
    {
        (*pDataOutLength) = 0;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_CRYPTOSYM);
    }

    /* Re-copy the array in case pDataIn != pDataOut */
    if (pDataIn != pDataOut)
    {
        if((*pDataOutLength) != 0U)
        {
            (void)memcpy(pDataOut, pDataIn, (size_t)(*pDataOutLength));
        }
    }

    return PH_ERR_SUCCESS;
}

FUNC(uint16, ANFCRL_CODE) phCryptoSym_GetKeySize(
                                VAR(uint16, ANFCRL_VAR) wKeyType
                                )
{
    switch (wKeyType)
    {
    case PH_CRYPTOSYM_KEY_TYPE_DES:
        return 8;
    case PH_CRYPTOSYM_KEY_TYPE_2K3DES:
    case PH_CRYPTOSYM_KEY_TYPE_AES128:
        return 16;
    case PH_CRYPTOSYM_KEY_TYPE_3K3DES:
    case PH_CRYPTOSYM_KEY_TYPE_AES192:
        return 24;
    case PH_CRYPTOSYM_KEY_TYPE_AES256:
        return 32;
    default:
        return 0;
    }
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCRYPTOSYM_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCRYPTOSYM_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_CRYPTOSYM */
#ifdef __cplusplus
}
#endif /* __cplusplus */
