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
*   @file    phalVca.c
* Generic MIFARE(R) Component of Reader Library Framework.
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalVca Virtual Card Architecture (R)
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
#include <phalVca.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHAL_VCA_SW
#include "Sw/phalVca_Sw.h"
#endif /* NXPBUILD__PHAL_VCA_SW */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalVca.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALVCA_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALVCA_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and PHAL_VCA.h header file are of the same vendor */
#if (PHALVCA_VENDOR_ID_C != PHALVCA_VENDOR_ID)
    #error "phalVca.c and phalVca.h have different vendor ids"
#endif
/* Check if current file and PHAL_VCA.h header file are of the same Autosar version */
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION_C    != PHALVCA_AR_RELEASE_MAJOR_VERSION) || \
     (PHALVCA_AR_RELEASE_MINOR_VERSION_C    != PHALVCA_AR_RELEASE_MINOR_VERSION) || \
     (PHALVCA_AR_RELEASE_REVISION_VERSION_C != PHALVCA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca.c and phalVca.h are different"
#endif
/* Check if current file and PHAL_VCA.h header file are of the same Software version */
#if ((PHALVCA_SW_MAJOR_VERSION_C != PHALVCA_SW_MAJOR_VERSION) || \
     (PHALVCA_SW_MINOR_VERSION_C != PHALVCA_SW_MINOR_VERSION) || \
     (PHALVCA_SW_PATCH_VERSION_C != PHALVCA_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca.c and phalVca.h are different"
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
#ifdef NXPBUILD__PHAL_VCA

#define ANFCRL_START_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalVca_StartCardSelection(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_StartCardSelection((phalVca_Sw_DataParams_t *) pDataParams);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_FinalizeCardSelection(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumValidIids)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pNumValidIids, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_FinalizeCardSelection((phalVca_Sw_DataParams_t *) pDataParams, pNumValidIids);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_SelectVc(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_SelectVc((phalVca_Sw_DataParams_t *) pDataParams, wValidIidIndex, wKeyNumber, wKeyVersion);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_DeselectVc(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_DeselectVc((phalVca_Sw_DataParams_t *) pDataParams);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_VcSupport(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint16, ANFCRL_VAR) wKeyEncNumber, VAR(uint16, ANFCRL_VAR) wKeyEncVersion, VAR(uint16, ANFCRL_VAR) wKeyMacNumber,
    VAR(uint16, ANFCRL_VAR) wKeyMacVersion)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pIid, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_VcSupport((phalVca_Sw_DataParams_t *) pDataParams, pIid, wKeyEncNumber, wKeyEncVersion, wKeyMacNumber, wKeyMacVersion);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_VcSupportLast(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint8, ANFCRL_VAR) bLenCap, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapabilities, VAR(uint16, ANFCRL_VAR) wKeyEncNumber,
    VAR(uint16, ANFCRL_VAR) wKeyEncVersion, VAR(uint16, ANFCRL_VAR) wKeyMacNumber, VAR(uint16, ANFCRL_VAR) wKeyMacVersion)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pIid, PH_COMP_AL_VCA);
    if(bLenCap > 0U)
    {
        PH_ASSERT_NULL_PARAM(pPcdCapabilities, PH_COMP_AL_VCA);
    }

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_VcSupportLast((phalVca_Sw_DataParams_t *) pDataParams, pIid, bLenCap, pPcdCapabilities,
                wKeyEncNumber, wKeyEncVersion, wKeyMacNumber, wKeyMacVersion);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_GetIidInfo(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pIidIndex, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUidSize, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInfo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPdCapabilities)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pIidIndex, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pVcUidSize, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pVcUid, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pInfo, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pPdCapabilities, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_GetIidInfo((phalVca_Sw_DataParams_t *) pDataParams, wValidIidIndex, pIidIndex, pVcUidSize,
                pVcUid, pInfo, pPdCapabilities);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_IsoSelect(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSelectionControl, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bDFnameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, VAR(uint8, ANFCRL_VAR) bEncKeyNo, VAR(uint8, ANFCRL_VAR) bEncKeyVer, VAR(uint8, ANFCRL_VAR) bMacKeyNo, VAR(uint8, ANFCRL_VAR) bMacKeyVer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(pDivInput);
    PH_UNUSED_VARIABLE(bDivInputLen);
    PH_UNUSED_VARIABLE(bEncKeyNo);
    PH_UNUSED_VARIABLE(bEncKeyVer);
    PH_UNUSED_VARIABLE(bMacKeyNo);
    PH_UNUSED_VARIABLE(bMacKeyVer);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pDFname, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pResponse, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pRespLen, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_IsoSelect((phalVca_Sw_DataParams_t *) pDataParams, bSelectionControl, bOption, bDFnameLen,
                pDFname, pResponse, pRespLen);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_IsoExternalAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pInData, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_IsoExternalAuthenticate((phalVca_Sw_DataParams_t *) pDataParams, pInData, wKeyNumber, wKeyVersion);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */




#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_ProximityCheck(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, VAR(uint8, ANFCRL_VAR) bPps1, VAR(uint8, ANFCRL_VAR) bNumSteps,
    VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    if(bGenerateRndC == 0U)
    {
        PH_ASSERT_NULL_PARAM(pRndC, PH_COMP_AL_VCA);
    }
    PH_ASSERT_NULL_PARAM(pUsedRndC, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_ProximityCheck((phalVca_Sw_DataParams_t *) pDataParams, bGenerateRndC, pRndC, bPps1, bNumSteps, wKeyNumber,
                wKeyVersion, pUsedRndC);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_ProximityCheckNew(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_UNUSED_VARIABLE(pDivInput);
    PH_UNUSED_VARIABLE(bDivInputLen);

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pResponse, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pRespLen, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pCumRndRC, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            /* Validate the parameters. */
            if(bOption == 0U)
            {
                PH_ASSERT_NULL_PARAM(pPrndC, PH_COMP_AL_VCA);
            }

            status = phalVca_Sw_ProximityCheckNew((phalVca_Sw_DataParams_t *) pDataParams, bOption, pPrndC, bNumSteps, wKeyNumber, wKeyVersion,
                pOption, pPubRespTime, pResponse, pRespLen, pCumRndRC);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_PrepareProximityCheckNew(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
    case PHAL_VCA_SW_ID:
        status = phalVca_Sw_Cmd_PrepareProximityCheckNew((phalVca_Sw_DataParams_t *)pDataParams, pOption, pPubRespTime, pResponse, pRespLen);
        break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_ExecuteProximityCheckNew(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    if(bGenerateRndC == 0U)
    {
        PH_ASSERT_NULL_PARAM(pPrndC, PH_COMP_AL_VCA);
    }
    PH_ASSERT_NULL_PARAM(pCumRndRC, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_Cmd_ProximityCheckNew((phalVca_Sw_DataParams_t *) pDataParams, bGenerateRndC, pPrndC, bNumSteps,
                pPubRespTime, pCumRndRC);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_VerifyProximityCheckNew(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, VAR(uint16, ANFCRL_VAR) wRespLen,
    VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndCmdResp)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
        status = phalVca_Sw_Cmd_VerifyProximityCheckNew((phalVca_Sw_DataParams_t *)pDataParams, bOption, pPubRespTime, pResponse, wRespLen,
                wKeyNumber, wKeyVersion, pRndCmdResp);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_VerifyProximityCheckUtility(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdMac, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdResp)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pCmdMac, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pCmdResp, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_Cmd_VerifyProximityCheckUtility((phalVca_Sw_DataParams_t *) pDataParams, pCmdMac, pCmdResp);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}




FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_SetConfig((phalVca_Sw_DataParams_t *) pDataParams, wConfig, wValue);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_GetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pValue, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_GetConfig((phalVca_Sw_DataParams_t *) pDataParams, wConfig, pValue);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetSessionKeyUtility(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey, VAR(uint8, ANFCRL_VAR) bAuthMode)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pSessionKey, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_SetSessionKeyUtility((phalVca_Sw_DataParams_t *) pDataParams, pSessionKey, bAuthMode);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetApplicationType(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    /* Validate the parameters */
    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pAlDataParams, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_SetApplicationType((phalVca_Sw_DataParams_t *) pDataParams, pAlDataParams);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_DecryptResponse(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRandChal,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCData)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL_DATA_PARAM(pDataParams, PH_COMP_AL_VCA);
    PH_ASSERT_NULL_PARAM(pInData, PH_COMP_AL_VCA);

    /* Check data parameters */
    if(PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_VCA)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
    }

    /* Perform operation on active layer */
    switch(PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_VCA_SW
        case PHAL_VCA_SW_ID:
            status = phalVca_Sw_DecryptResponse((phalVca_Sw_DataParams_t *) pDataParams, wKeyNo, wKeyVersion, pInData, pRandChal, pVCData);
            break;
#endif /* NXPBUILD__PHAL_VCA_SW */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
            break;
    }

    return status;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_VCA */

#ifdef __cplusplus
}
#endif
