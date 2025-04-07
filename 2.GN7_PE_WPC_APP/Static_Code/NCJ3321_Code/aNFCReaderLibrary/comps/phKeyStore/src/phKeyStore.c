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
*   @file    phKeyStore.c
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
#include <ph_RefDefs.h>
#include "phKeyStore_Int.h"

#ifdef NXPBUILD__PH_KEYSTORE_SW
#include "Sw/phKeyStore_Sw.h"
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
#include "Ncx3320/phKeyStore_Ncx3320.h"
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phKeyStore.c
* @implements     DESIGN001, DESIGN002
*/
#define PHKEYSTORE_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHKEYSTORE_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHKEYSTORE_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHKEYSTORE_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHKEYSTORE_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHKEYSTORE_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHKEYSTORE_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phKeyStore.h header file are of the same vendor */
#if (PHKEYSTORE_VENDOR_ID_C != PHKEYSTORE_VENDOR_ID)
    #error "phKeyStore.c and phKeyStore.h have different vendor ids"
#endif
/* Check if current file and phKeyStore.h header file are of the same Autosar version */
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION_C    != PHKEYSTORE_AR_RELEASE_MAJOR_VERSION) || \
     (PHKEYSTORE_AR_RELEASE_MINOR_VERSION_C    != PHKEYSTORE_AR_RELEASE_MINOR_VERSION) || \
     (PHKEYSTORE_AR_RELEASE_REVISION_VERSION_C != PHKEYSTORE_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phKeyStore.c and phKeyStore.h are different"
#endif
/* Check if current file and phKeyStore.h header file are of the same Software version */
#if ((PHKEYSTORE_SW_MAJOR_VERSION_C != PHKEYSTORE_SW_MAJOR_VERSION) || \
     (PHKEYSTORE_SW_MINOR_VERSION_C != PHKEYSTORE_SW_MINOR_VERSION) || \
     (PHKEYSTORE_SW_PATCH_VERSION_C != PHKEYSTORE_SW_PATCH_VERSION))
    #error "Software Version Numbers of phKeyStore.c and phKeyStore.h are different"
#endif
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

#ifdef NXPBUILD__PH_KEYSTORE

#define ANFCRL_START_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifndef NXPRDLIB_REM_GEN_INTFS

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_FormatKeyEntry(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,            /**< [In] Pointer to this layer's parameter structure. */
                                     VAR(uint16, ANFCRL_VAR) wKeyNo,               /**< [In] KeyEntry number to be Formatted (0x00 to F0). */
                                     VAR(uint16, ANFCRL_VAR) wNewKeyType            /**< [In] New Key type of the KeyEntry (predefined type of KeyType).*/
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_FormatKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams,wKeyNo,wNewKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_FormatKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wKeyNo,wNewKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKey(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                             VAR(uint16, ANFCRL_VAR) wKeyNo,
                             VAR(uint16, ANFCRL_VAR) wKeyVersion,
                             VAR(uint16, ANFCRL_VAR) wKeyType,
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                             VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                             )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pNewKey);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetKey((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetKey((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, wKeyType, pNewKey, wNewKeyVersion);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;

}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKeyAtPos(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wKeyNo,
                                  VAR(uint16, ANFCRL_VAR) wPos,
                                  VAR(uint16, ANFCRL_VAR) wKeyType,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                  VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pNewKey);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetKeyAtPos((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetKeyAtPos((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wPos, wKeyType, pNewKey, wNewKeyVersion);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetKUC(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                   VAR(uint16, ANFCRL_VAR) wRefNoKUC
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wRefNoKUC);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wRefNoKUC);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;

}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetFullKeyEntry(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wNoOfKeys,
                                      VAR(uint16, ANFCRL_VAR) wKeyNo,
                                      VAR(uint16, ANFCRL_VAR) wNewRefNoKUC,
                                      VAR(uint16, ANFCRL_VAR) wNewKeyType,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeys,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeyVersionList
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pNewKeys);
    PH_ASSERT_NULL (pNewKeyVersionList);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetFullKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetFullKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wNoOfKeys, wKeyNo, wNewRefNoKUC, wNewKeyType, pNewKeys, pNewKeyVersionList);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKeyEntry(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wKeyNo,
                                    VAR(uint16, ANFCRL_VAR) wKeyVersionBufSize,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersion,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersionLength,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (wKeyVersion);
    PH_ASSERT_NULL (wKeyVersionLength);
    PH_ASSERT_NULL (pKeyType);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_GetKeyEntry((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_GetKeyEntry((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersionBufSize, wKeyVersion, wKeyVersionLength, pKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKey(
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                            VAR(uint16, ANFCRL_VAR) wKeyNo,
                            VAR(uint16, ANFCRL_VAR) wKeyVersion,
                            VAR(uint8, ANFCRL_VAR) bKeyBufSize,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                             )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pKey);
    PH_ASSERT_NULL (pKeyType);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_GetKey((phKeyStore_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_GetKey((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wKeyNo, wKeyVersion, bKeyBufSize, pKey, pKeyType);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetConfig(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                VAR(uint16, ANFCRL_VAR) wValue
                                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetConfig((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,wValue);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetConfig((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,wValue);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_SetConfigStr(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer,
                                   VAR(uint16, ANFCRL_VAR) wBufferLength
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_SetConfigStr((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,pBuffer,wBufferLength);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_SetConfigStr((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,pBuffer,wBufferLength);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetConfig(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_GetConfig((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,pValue);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_GetConfig((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,pValue);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetConfigStr(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppBuffer,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLength
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (ppBuffer);
    PH_ASSERT_NULL (pBufferLength);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_GetConfigStr((phKeyStore_Sw_DataParams_t *)pDataParams,wConfig,ppBuffer,pBufferLength);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_GetConfigStr((phKeyStore_Ncx3320_DataParams_t *)pDataParams,wConfig,ppBuffer,pBufferLength);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}




FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_ChangeKUC(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wRefNoKUC,
    VAR(uint32, ANFCRL_VAR) dwLimit
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_ChangeKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wRefNoKUC, dwLimit);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_ChangeKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wRefNoKUC, dwLimit);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_GetKUC(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wRefNoKUC,
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwLimit,
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwCurVal
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pdwLimit);
    PH_ASSERT_NULL (pdwCurVal);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_KEYSTORE)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_KEYSTORE_SW
    case PH_KEYSTORE_SW_ID:
        status = phKeyStore_Sw_GetKUC((phKeyStore_Sw_DataParams_t *)pDataParams, wRefNoKUC, pdwLimit, pdwCurVal);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_SW */



#ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    case PH_KEYSTORE_NCx3320_ID:
        status = phKeyStore_Ncx3320_GetKUC((phKeyStore_Ncx3320_DataParams_t *)pDataParams, wRefNoKUC, pdwLimit, pdwCurVal);
        break;
#endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_KEYSTORE);
        break;
    }

    return status;
}

#endif /* NXPRDLIB_REM_GEN_INTFS  */

FUNC(uint16, ANFCRL_CODE) phKeyStore_GetKeySize(VAR(uint16, ANFCRL_VAR) wKeyType)
{
    switch (wKeyType)
    {
        case PH_KEYSTORE_KEY_TYPE_MIFARE:
            /* 6 bytes for key A + 6 bytes for key B */
            return 12;

        case PH_KEYSTORE_KEY_TYPE_DES:
            return 8;

        case PH_KEYSTORE_KEY_TYPE_2K3DES:
        case PH_KEYSTORE_KEY_TYPE_AES128:
            return 16;

        case PH_KEYSTORE_KEY_TYPE_3K3DES:
        case PH_KEYSTORE_KEY_TYPE_AES192:
            return 24;

        case PH_KEYSTORE_KEY_TYPE_AES256:
            return 32;

        default:
            return 0;
    }
}


#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHKEYSTORE_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_KEYSTORE */

#ifdef __cplusplus
}
#endif
