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
*   @file    phCidManager.c
*   @version 1.0.0
*
*   @brief   AUTOSAR CidManager - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phCidManager Cid Manager
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
#include <phCidManager.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PH_CIDMANAGER_SW
#include "Sw/phCidManager_Sw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCidManager.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCIDMANAGER_VENDOR_ID_C                      43         /**< @brief AUTOSAR vendor ID*/
#define PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION_C       4       /**< @brief AUTOSAR release major version*/
#define PHCIDMANAGER_AR_RELEASE_MINOR_VERSION_C       3       /**< @brief AUTOSAR release minor version*/
#define PHCIDMANAGER_AR_RELEASE_REVISION_VERSION_C    1       /**< @brief AUTOSAR release revision*/
#define PHCIDMANAGER_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHCIDMANAGER_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHCIDMANAGER_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phCidManager.h header file are of the same vendor */
#if (PHCIDMANAGER_VENDOR_ID_C != PHCIDMANAGER_VENDOR_ID)
    #error "phCidManager.c and phCidManager.h have different vendor ids"
#endif
/* Check if current file and phCidManager.h header file are of the same Autosar version */
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION_C    != PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION) || \
     (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION_C    != PHCIDMANAGER_AR_RELEASE_MINOR_VERSION) || \
     (PHCIDMANAGER_AR_RELEASE_REVISION_VERSION_C != PHCIDMANAGER_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCidManager.c and phCidManager.h are different"
#endif
/* Check if current file and phCidManager.h header file are of the same Software version */
#if ((PHCIDMANAGER_SW_MAJOR_VERSION_C != PHCIDMANAGER_SW_MAJOR_VERSION) || \
     (PHCIDMANAGER_SW_MINOR_VERSION_C != PHCIDMANAGER_SW_MINOR_VERSION) || \
     (PHCIDMANAGER_SW_PATCH_VERSION_C != PHCIDMANAGER_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCidManager.c and phCidManager.h are different"
#endif
#endif /* NXPBUILD__PH_CIDMANAGER_SW */
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
#ifdef NXPBUILD__PH_CIDMANAGER_SW

#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */


FUNC(phStatus_t, ANFCRL_CODE) phCidManager_GetFreeCid(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid
                                   )
{
   VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pCid);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CIDMANAGER)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CIDMANAGER);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CIDMANAGER_SW
    case PH_CIDMANAGER_SW_ID:
        status = phCidManager_Sw_GetFreeCid((phCidManager_Sw_DataParams_t *)pDataParams, pCid);
        break;
#endif /* NXPBUILD__PH_CIDMANAGER_SW */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CIDMANAGER);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phCidManager_FreeCid(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint8, ANFCRL_VAR) bCid
                                )
{
   VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CIDMANAGER)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CIDMANAGER);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PH_CIDMANAGER_SW
    case PH_CIDMANAGER_SW_ID:
        status = phCidManager_Sw_FreeCid((phCidManager_Sw_DataParams_t *)pDataParams, bCid);
        break;
#endif /* NXPBUILD__PH_CIDMANAGER_SW */


    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CIDMANAGER);
        break;
    }

    return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PH_CIDMANAGER_SW */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */
