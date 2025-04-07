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
*   @file    phpalFelica.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalFelica Felica
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
#include <phpalFelica.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHPAL_FELICA_SW
#include "Sw/phpalFelica_Sw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalFelica.h header file are of the same vendor */
#if (PHPALFELICA_VENDOR_ID_C != PHPALFELICA_VENDOR_ID)
    #error "phpalFelica.c and phpalFelica.h have different vendor ids"
#endif
/* Check if current file and phpalFelica.h header file are of the same Autosar version */
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C    != PHPALFELICA_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C    != PHPALFELICA_AR_RELEASE_MINOR_VERSION) || \
     (PHPALFELICA_AR_RELEASE_REVISION_VERSION_C != PHPALFELICA_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalFelica.c and phpalFelica.h are different"
#endif
/* Check if current file and phpalFelica.h header file are of the same Software version */
#if ((PHPALFELICA_SW_MAJOR_VERSION_C != PHPALFELICA_SW_MAJOR_VERSION) || \
     (PHPALFELICA_SW_MINOR_VERSION_C != PHPALFELICA_SW_MINOR_VERSION) || \
     (PHPALFELICA_SW_PATCH_VERSION_C != PHPALFELICA_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalFelica.c and phpalFelica.h are different"
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

#ifdef NXPBUILD__PHPAL_FELICA

#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_ReqC(
                            void* pDataParams,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                            VAR(uint8, ANFCRL_VAR) bTimeSlot,
                            P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                            )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pSystemCode);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_ReqC((phpalFelica_Sw_DataParams_t *)pDataParams, pSystemCode, bTimeSlot, ppRxBuffer, pRxLength);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_ActivateCard(
                                    void* pDataParams,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm,
                                    VAR(uint8, ANFCRL_VAR) bIDmPMmLength,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                                    VAR(uint8, ANFCRL_VAR) bTimeSlot,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

    PH_ASSERT_NULL (pDataParams);
    if (0U != (bIDmPMmLength)) PH_ASSERT_NULL (pIDmPMm);
    PH_ASSERT_NULL (pSystemCode);
    PH_ASSERT_NULL (pRxBuffer);
    PH_ASSERT_NULL (pRxLength);
    PH_ASSERT_NULL (pMoreCardsAvailable);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_ActivateCard( (phpalFelica_Sw_DataParams_t *)pDataParams, pIDmPMm, bIDmPMmLength, pSystemCode, bTimeSlot, pRxBuffer, pRxLength, pMoreCardsAvailable );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

/* PAL as DUT*/
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Exchange(
                                void* pDataParams,
                                VAR(uint16, ANFCRL_VAR) wOption,
                                VAR(uint16, ANFCRL_VAR) wN,
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
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);

        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_Exchange( (phpalFelica_Sw_DataParams_t *)pDataParams, wOption, wN, pTxBuffer, wTxLength, ppRxBuffer, pRxLength );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

/* PAL as DUT*/
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_SetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 VAR(uint16, ANFCRL_VAR) wValue
                                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_SetConfig((phpalFelica_Sw_DataParams_t *)pDataParams, wConfig, wValue);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_GetConfig(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 VAR(uint16, ANFCRL_VAR) wConfig,
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                 )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pValue);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_GetConfig((phpalFelica_Sw_DataParams_t *)pDataParams, wConfig, pValue);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_GetSerialNo(
                                   void* pDataParams,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pIDmPMmOut);
    PH_ASSERT_NULL (pLenIDmPMmOut);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_GetSerialNo( (phpalFelica_Sw_DataParams_t *)pDataParams, pIDmPMmOut, pLenIDmPMmOut );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

/*PAL as DUT*/
    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_SetSerialNo(
                                   void* pDataParams,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pIDmPMm);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_SetSerialNo( (phpalFelica_Sw_DataParams_t *)pDataParams, pIDmPMm );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE)  phpalFelica_GetFrameInfo(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint8, ANFCRL_VAR) bFrameNum,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen
                                     )

{

    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pResponseBuffer);
    PH_ASSERT_NULL (pwStatus);
    PH_ASSERT_NULL (ppID);
    PH_ASSERT_NULL (pLen);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_FELICA)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW
    case PHPAL_FELICA_SW_ID:
        status = phpalFelica_Sw_GetFrameInfo((phpalFelica_Sw_DataParams_t*) pDataParams, bFrameNum, pResponseBuffer, pwStatus, ppID, pLen);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
        break;
    }
    return status;

}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHPAL_FELICA */

#endif /* NXPBUILD__PHPAL_FELICA_SW */

#ifdef __cplusplus
}
#endif
