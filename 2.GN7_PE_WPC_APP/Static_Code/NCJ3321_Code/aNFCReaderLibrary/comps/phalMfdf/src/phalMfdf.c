/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2023
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
*   @file    phalMfdf.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdf - AL API usage in common use cases.
*   @brief 	 Generic MIFARE DESFire EV1 Application Component of Reader Library Framework.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdf MIFARE DESFire (R)
*   @ingroup phalApplication
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

#include <phalMfdf.h>
#include <ph_Status.h>
#include <ph_TypeDefs.h>

#ifdef NXPBUILD__PHAL_MFDF_SW
#include "Sw/phalMfdf_Sw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdf.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDF_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDF_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALMFDF_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDF_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALMFDF_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALMFDF_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALMFDF_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalMfdf.h header file are of the same vendor */
#if (PHALMFDF_VENDOR_ID_C != PHALMFDF_VENDOR_ID)
    #error "phalMfdf.c and phalMfdf.h have different vendor ids"
#endif
/* Check if current file and phalMfdf.h header file are of the same Autosar version */
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION_C    != PHALMFDF_AR_RELEASE_MAJOR_VERSION) || \
     (PHALMFDF_AR_RELEASE_MINOR_VERSION_C    != PHALMFDF_AR_RELEASE_MINOR_VERSION) || \
     (PHALMFDF_AR_RELEASE_REVISION_VERSION_C != PHALMFDF_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdf.c and phalMfdf.h are different"
#endif
/* Check if current file and phalMfdf.h header file are of the same Software version */
#if ((PHALMFDF_SW_MAJOR_VERSION_C != PHALMFDF_SW_MAJOR_VERSION) || \
     (PHALMFDF_SW_MINOR_VERSION_C != PHALMFDF_SW_MINOR_VERSION) || \
     (PHALMFDF_SW_PATCH_VERSION_C != PHALMFDF_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdf.c and phalMfdf.h are different"
#endif
#endif /* NXPBUILD__PHAL_MFDF_SW */
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
#ifdef NXPBUILD__PHAL_MFDF

#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/*
* PICC level commands
*/

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateApplication(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint8, ANFCRL_VAR) bOption,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,
                                      VAR(uint8, ANFCRL_VAR) bKeySettings1,
                                      VAR(uint8, ANFCRL_VAR) bKeySettings2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,
                                      VAR(uint8, ANFCRL_VAR) bISODFNameLen
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    if (0U != (bOption & 0x01U)) PH_ASSERT_NULL (pISOFileId);
    if (bISODFNameLen > 0U) PH_ASSERT_NULL (pISODFName);
    PH_ASSERT_NULL (pAid);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_CreateApplication((phalMfdf_Sw_DataParams_t *)pDataParams,
            bOption,
            pAid,
            bKeySettings1,
            bKeySettings2,
            pISOFileId,
            pISODFName,
            bISODFNameLen);
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_SelectApplication(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppId
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pAppId);

    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }
    switch (PH_GET_COMPID(pDataParams))
    {

#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_SelectApplication((phalMfdf_Sw_DataParams_t *)pDataParams, pAppId);
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetVersion(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVerInfo
                               )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pVerInfo);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_GetVersion((phalMfdf_Sw_DataParams_t *)pDataParams, pVerInfo);
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateStdDataFile(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint8, ANFCRL_VAR) bOption,
                                      VAR(uint8, ANFCRL_VAR) bFileNo,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
                                      VAR(uint8, ANFCRL_VAR) bCommSett,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    if (bOption == 0x01U) PH_ASSERT_NULL (pISOFileId);
    PH_ASSERT_NULL (pAccessRights);
    PH_ASSERT_NULL (pFileSize);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_CreateStdDataFile((phalMfdf_Sw_DataParams_t *)pDataParams,
            bOption,
            bFileNo,
            pISOFileId,
            bCommSett,
            pAccessRights,
            pFileSize
            );
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_WriteData(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                              VAR(uint8, ANFCRL_VAR) bCommOption,
                              VAR(uint8, ANFCRL_VAR) bFileNo,
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
                              )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pOffset);
    PH_ASSERT_NULL (pTxData);
    PH_ASSERT_NULL (pTxDataLen);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_WriteData((phalMfdf_Sw_DataParams_t *)pDataParams,
            bCommOption,
            bFileNo,
            pOffset,
            pTxData,
            pTxDataLen
            );
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoSelectFile(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint8, ANFCRL_VAR) bOption,
                                  VAR(uint8, ANFCRL_VAR) bSelector,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,
                                  VAR(uint8, ANFCRL_VAR) bDFnameLen,
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFCI,
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_IsoSelectFile((phalMfdf_Sw_DataParams_t *)pDataParams,
            bOption,
            bSelector,
            pFid,
            pDFname,
            bDFnameLen,
            ppFCI,
            pwFCILen
            );
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoReadBinary(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wOption,
                                  VAR(uint8, ANFCRL_VAR) bOffset,
                                  VAR(uint8, ANFCRL_VAR) bSfid,
                                  VAR(uint8, ANFCRL_VAR) bBytesToRead,
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (ppRxBuffer);
    PH_ASSERT_NULL (pBytesRead);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_IsoReadBinary((phalMfdf_Sw_DataParams_t *)pDataParams,
            wOption,
            bOffset,
            bSfid,
            bBytesToRead,
            ppRxBuffer,
            pBytesRead
            );
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoUpdateBinary(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint8, ANFCRL_VAR) bOffset,
                                    VAR(uint8, ANFCRL_VAR) bSfid,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                                    VAR(uint8, ANFCRL_VAR) bDataLen
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pData);

    /* parameter validation */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_IsoUpdateBinary((phalMfdf_Sw_DataParams_t *)pDataParams,
            bOffset,
            bSfid,
            pData,
            bDataLen
            );
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetConfig(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                              VAR(uint16, ANFCRL_VAR) wConfig,
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                              )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_GetConfig((phalMfdf_Sw_DataParams_t *)pDataParams, wConfig, pValue);
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_SetConfig(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                              VAR(uint16, ANFCRL_VAR) wConfig,
                              VAR(uint16, ANFCRL_VAR) wValue
                              )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_MFDF)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_MFDF_SW
    case PHAL_MFDF_SW_ID:
        status = phalMfdf_Sw_SetConfig((phalMfdf_Sw_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHAL_MFDF_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDF);
        break;
    }

    return status;
}

#define ANFCRL_STOP_SEC_CODE

#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHAL_MFDF */

#ifdef __cplusplus
}
#endif
