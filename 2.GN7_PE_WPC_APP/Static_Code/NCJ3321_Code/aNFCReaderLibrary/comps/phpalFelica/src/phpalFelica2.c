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
*   @file    phpalFelica2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalFelica2 Felica
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
#include <ph_Status2.h>
#include <phpalFelica2.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHPAL_FELICA_SW2
#include "Sw/phpalFelica_Sw2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalFelica2.h header file are of the same vendor */
#if (PHPALFELICA_VENDOR_ID_C2 != PHPALFELICA_VENDOR_ID2)
    #error "phpalFelica2.c and phpalFelica2.h have different vendor ids"
#endif
/* Check if current file and phpalFelica2.h header file are of the same Autosar version */
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C2    != PHPALFELICA_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C2    != PHPALFELICA_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALFELICA_AR_RELEASE_REVISION_VERSION_C2 != PHPALFELICA_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalFelica2.c and phpalFelica2.h are different"
#endif
/* Check if current file and phpalFelica2.h header file are of the same Software version */
#if ((PHPALFELICA_SW_MAJOR_VERSION_C2 != PHPALFELICA_SW_MAJOR_VERSION2) || \
     (PHPALFELICA_SW_MINOR_VERSION_C2 != PHPALFELICA_SW_MINOR_VERSION2) || \
     (PHPALFELICA_SW_PATCH_VERSION_C2 != PHPALFELICA_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalFelica2.c and phpalFelica2.h are different"
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

#ifdef NXPBUILD__PHPAL_FELICA2

#ifndef NXPRDLIB_REM_GEN_INTFS2

#define ANFCRL_START_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_ReqC2(
                            void* pDataParams2,
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                            VAR(uint8, ANFCRL_VAR) bTimeSlot2,
                            P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                            )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pSystemCode2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_ReqC2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, pSystemCode2, bTimeSlot2, ppRxBuffer2, pRxLength2);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_ActivateCard2(
                                    void* pDataParams2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2,
                                    VAR(uint8, ANFCRL_VAR) bIDmPMmLength2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                                    VAR(uint8, ANFCRL_VAR) bTimeSlot2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
                                    )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

    PH_ASSERT_NULL2 (pDataParams2);
    if (0U != (bIDmPMmLength2)) PH_ASSERT_NULL2 (pIDmPMm2);
    PH_ASSERT_NULL2 (pSystemCode2);
    PH_ASSERT_NULL2 (pRxBuffer2);
    PH_ASSERT_NULL2 (pRxLength2);
    PH_ASSERT_NULL2 (pMoreCardsAvailable2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_ActivateCard2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMm2, bIDmPMmLength2, pSystemCode2, bTimeSlot2, pRxBuffer2, pRxLength2, pMoreCardsAvailable2 );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

/* PAL as DUT*/
    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Exchange2(
                                void* pDataParams2,
                                VAR(uint16, ANFCRL_VAR) wOption2,
                                VAR(uint16, ANFCRL_VAR) wN2,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                VAR(uint16, ANFCRL_VAR) wTxLength2,
                                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    if (0U != (wTxLength2)) PH_ASSERT_NULL2 (pTxBuffer2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);

        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_Exchange2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, wOption2, wN2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2 );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

/* PAL as DUT*/
    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_SetConfig2(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint16, ANFCRL_VAR) wConfig2,
                                 VAR(uint16, ANFCRL_VAR) wValue2
                                 )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_SetConfig2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, wConfig2, wValue2);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_GetConfig2(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint16, ANFCRL_VAR) wConfig2,
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                 )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pValue2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_GetConfig2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_GetSerialNo2(
                                   void* pDataParams2,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut2,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pIDmPMmOut2);
    PH_ASSERT_NULL2 (pLenIDmPMmOut2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_GetSerialNo2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMmOut2, pLenIDmPMmOut2 );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

/*PAL as DUT*/
    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_SetSerialNo2(
                                   void* pDataParams2,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pIDmPMm2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_SetSerialNo2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMm2 );
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE)  phpalFelica_GetFrameInfo2(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint8, ANFCRL_VAR) bFrameNum2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer2,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus2,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen2
                                     )

{

    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pResponseBuffer2);
    PH_ASSERT_NULL2 (pwStatus2);
    PH_ASSERT_NULL2 (ppID2);
    PH_ASSERT_NULL2 (pLen2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_FELICA2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_FELICA_SW2
    case PHPAL_FELICA_SW_ID2:
        status2 = phpalFelica_Sw_GetFrameInfo2((phpalFelica_Sw_DataParams_t2*) pDataParams2, bFrameNum2, pResponseBuffer2, pwStatus2, ppID2, pLen2);
        break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
        break;
    }
    return status2;

}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

#endif /* NXPBUILD__PHPAL_FELICA2 */

#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef __cplusplus
}
#endif
