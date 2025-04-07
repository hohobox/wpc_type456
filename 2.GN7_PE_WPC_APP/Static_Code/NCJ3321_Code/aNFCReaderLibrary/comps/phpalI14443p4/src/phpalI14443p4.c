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
*   @file    phpalI14443p4.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4 - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4 ISO/IEC 14443-4
*   @ingroup phpalProtocol
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
#include <phpalI14443p4.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHPAL_I14443P4_SW
#include "Sw/phpalI14443p4_Sw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4.h header file are of the same vendor */
#if (PHPALI14443P4_VENDOR_ID_C != PHPALI14443P4_VENDOR_ID)
    #error "phpalI14443p4.c and phpalI14443p4.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4.h header file are of the same Autosar version */
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4.c and phpalI14443p4.h are different"
#endif
/* Check if current file and phpalI14443p4.h header file are of the same Software version */
#if ((PHPALI14443P4_SW_MAJOR_VERSION_C != PHPALI14443P4_SW_MAJOR_VERSION) || \
     (PHPALI14443P4_SW_MINOR_VERSION_C != PHPALI14443P4_SW_MINOR_VERSION) || \
     (PHPALI14443P4_SW_PATCH_VERSION_C != PHPALI14443P4_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4.c and phpalI14443p4.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
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
#ifdef NXPBUILD__PHPAL_I14443P4
#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_SetProtocol(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint8, ANFCRL_VAR) bCidEnable,
                                     VAR(uint8, ANFCRL_VAR) bCid,
                                     VAR(uint8, ANFCRL_VAR) bNadEnable,
                                     VAR(uint8, ANFCRL_VAR) bNad,
                                     VAR(uint8, ANFCRL_VAR) bFwi,
                                     VAR(uint8, ANFCRL_VAR) bFsdi,
                                     VAR(uint8, ANFCRL_VAR) bFsci
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_SetProtocol(
            (phpalI14443p4_Sw_DataParams_t *)pDataParams,
            bCidEnable,
            bCid,
            bNadEnable,
            bNad,
            bFwi,
            bFsdi,
            bFsci);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_ResetProtocol(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_ResetProtocol((phpalI14443p4_Sw_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Deselect(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_Deselect((phpalI14443p4_Sw_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_PresCheck(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_PresCheck((phpalI14443p4_Sw_DataParams_t *)pDataParams);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Exchange(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wOption,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                  VAR(uint16, ANFCRL_VAR) wTxLength,
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                  )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    if (0U != (wTxLength)) PH_ASSERT_NULL (pTxBuffer);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_Exchange((phpalI14443p4_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_SetConfig(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   VAR(uint16, ANFCRL_VAR) wValue
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_SetConfig((phpalI14443p4_Sw_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_GetConfig(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_ISO14443P4)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_I14443P4_SW
    case PHPAL_I14443P4_SW_ID:
        status = phpalI14443p4_Sw_GetConfig((phpalI14443p4_Sw_DataParams_t *)pDataParams, wConfig, pValue);
        break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4);
        break;
    }

    return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */
#endif /* NXPBUILD__PHPAL_I14443P4 */

#ifdef __cplusplus
}
#endif
