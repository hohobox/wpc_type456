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
*   @file    phalFelica.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlFelica - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalFelica Felica
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

#include <phalFelica.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHAL_FELICA_SW
#include "Sw/phalFelica_Sw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalFelica.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALFELICA_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALFELICA_AR_RELEASE_MAJOR_VERSION_C       4         /**< @brief AUTOSAR release major version*/
#define PHALFELICA_AR_RELEASE_MINOR_VERSION_C       3         /**< @brief AUTOSAR release minor version*/
#define PHALFELICA_AR_RELEASE_REVISION_VERSION_C    1         /**< @brief AUTOSAR release revision*/
#define PHALFELICA_SW_MAJOR_VERSION_C               1              /**< @brief The major version of the SW module*/
#define PHALFELICA_SW_MINOR_VERSION_C               0              /**< @brief The minor version of the SW module*/
#define PHALFELICA_SW_PATCH_VERSION_C               0              /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalFelica.h header file are of the same vendor */
#if (PHALFELICA_VENDOR_ID_C != PHALFELICA_VENDOR_ID)
    #error "phalFelica.c and phalFelica.h have different vendor ids"
#endif
/* Check if current file and phalFelica.h header file are of the same Autosar version */
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION_C    != PHALFELICA_AR_RELEASE_MAJOR_VERSION) || \
     (PHALFELICA_AR_RELEASE_MINOR_VERSION_C    != PHALFELICA_AR_RELEASE_MINOR_VERSION) || \
     (PHALFELICA_AR_RELEASE_REVISION_VERSION_C != PHALFELICA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalFelica.c and phalFelica.h are different"
#endif
/* Check if current file and phalFelica.h header file are of the same Software version */
#if ((PHALFELICA_SW_MAJOR_VERSION_C != PHALFELICA_SW_MAJOR_VERSION) || \
     (PHALFELICA_SW_MINOR_VERSION_C != PHALFELICA_SW_MINOR_VERSION) || \
     (PHALFELICA_SW_PATCH_VERSION_C != PHALFELICA_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalFelica.c and phalFelica.h are different"
#endif
#endif /* NXPBUILD__PHAL_FELICA_SW */
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
#ifdef NXPBUILD__PHAL_FELICA

#ifndef NXPRDLIB_REM_GEN_INTFS
#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestResponse(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMode
                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pMode);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_RequestResponse((phalFelica_Sw_DataParams_t *)pDataParams, pMode);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestService(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bTxNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxServiceList,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceList
                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pTxServiceList);
    PH_ASSERT_NULL (pRxNumServices);
    PH_ASSERT_NULL (pRxServiceList);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_RequestService((phalFelica_Sw_DataParams_t *)pDataParams, bTxNumServices, pTxServiceList, pRxNumServices, pRxServiceList);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Read(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,
                    VAR(uint8, ANFCRL_VAR) bTxNumBlocks,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,
                    VAR(uint8, ANFCRL_VAR) bBlockListLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumBlocks,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData
                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pServiceList);
    PH_ASSERT_NULL (pBlockList);
    PH_ASSERT_NULL (pRxNumBlocks);
    PH_ASSERT_NULL (pBlockData);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_Read((phalFelica_Sw_DataParams_t *)pDataParams, bNumServices, pServiceList, bTxNumBlocks, pBlockList, bBlockListLength, pRxNumBlocks, pBlockData);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Write(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bNumServices,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,
                    VAR(uint8, ANFCRL_VAR) bNumBlocks,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,
                    VAR(uint8, ANFCRL_VAR) bBlockListLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData
                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pServiceList);
    PH_ASSERT_NULL (pBlockList);
    PH_ASSERT_NULL (pBlockData);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_Write((phalFelica_Sw_DataParams_t *)pDataParams,  bNumServices, pServiceList, bNumBlocks, pBlockList, bBlockListLength, pBlockData);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_GetConfig(
                                   void* pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wConfig,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_GetConfig((phalFelica_Sw_DataParams_t *)pDataParams, wConfig, pValue );
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ActivateCard(
                                    void* pDataParams,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                                    VAR(uint8, ANFCRL_VAR) bTimeSlot,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pSystemCode);
    PH_ASSERT_NULL (pRxBuffer);
    PH_ASSERT_NULL (pRxLength);
    PH_ASSERT_NULL (pMoreCardsAvailable);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
        status = phalFelica_Sw_ActivateCard( (phalFelica_Sw_DataParams_t *)pDataParams, pSystemCode, bTimeSlot, pRxBuffer, pRxLength, pMoreCardsAvailable);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_SearchService(
                                       void* pDataParams,
                                       VAR(uint16, ANFCRL_VAR) serviceIndex,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCode,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCount
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pRxServiceCode);
    PH_ASSERT_NULL (pRxServiceCount);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
    	status = phalFelica_Sw_SearchService(pDataParams, serviceIndex, pRxServiceCode, pRxServiceCount);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestSystemCodes(
                                       void* pDataParams,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCodes,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCount
                                       )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pRxSystemCodes);
    PH_ASSERT_NULL (pRxSystemCount);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_AL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHAL_FELICA_SW
    case PHAL_FELICA_SW_ID:
    	status = phalFelica_Sw_RequestSystemCodes(pDataParams, pRxSystemCodes, pRxSystemCount);
        break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_FELICA);
        break;
    }

    return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHAL_FELICA */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */