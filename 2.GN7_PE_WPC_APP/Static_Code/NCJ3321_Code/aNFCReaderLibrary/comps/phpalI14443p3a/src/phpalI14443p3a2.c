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
*   @file    phpalI14443p3a2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3a - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3a ISO/IEC 14443-3A
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
#include <phpalI14443p3a2.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
#include "Sw/phpalI14443p3a_Sw2.h"
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3a2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3A_VENDOR_ID_C2                      43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION_C2       4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3A_AR_RELEASE_MINOR_VERSION_C2       3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3A_AR_RELEASE_REVISION_VERSION_C2    1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3A_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3A_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3A_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p3a.h header file are of the same vendor */
#if (PHPALI14443P3A_VENDOR_ID_C2 != PHPALI14443P3A_VENDOR_ID2)
    #error "phpalI14443p3a2.c and phpalI14443p3a2.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p3a.h header file are of the same Autosar version */
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION_C2    != PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION_C2    != PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALI14443P3A_AR_RELEASE_REVISION_VERSION_C2 != PHPALI14443P3A_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalI14443p3a2.c and phpalI14443p3a2.h are different"
#endif
/* Check if current file and phpalI14443p3a.h header file are of the same Software version */
#if ((PHPALI14443P3A_SW_MAJOR_VERSION_C2 != PHPALI14443P3A_SW_MAJOR_VERSION2) || \
     (PHPALI14443P3A_SW_MINOR_VERSION_C2 != PHPALI14443P3A_SW_MINOR_VERSION2) || \
     (PHPALI14443P3A_SW_PATCH_VERSION_C2 != PHPALI14443P3A_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalI14443p3a2.c and phpalI14443p3a2.h are different"
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
#ifdef NXPBUILD__PHPAL_I14443P3A2
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

#ifndef NXPRDLIB_REM_GEN_INTFS2

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_SetConfig2(
                                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint16, ANFCRL_VAR) wConfig2,
                                        VAR(uint16, ANFCRL_VAR) wValue2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_SetConfig2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, wConfig2,wValue2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_GetConfig2(
                                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint16, ANFCRL_VAR) wConfig2,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_GetConfig2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_RequestA2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pAtqa2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);

        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_RequestA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pAtqa2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */






    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_WakeUpA2(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2
                                  )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pAtqa2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_WakeUpA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pAtqa2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */




    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_HaltA2(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_HaltA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Anticollision2(
                                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bCascadeLevel2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
                                        VAR(uint8, ANFCRL_VAR) bNvbUidIn2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNvbUidOut2
                                        )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    if (0U != (bNvbUidIn2)) PH_ASSERT_NULL2 (pUidIn2);
    PH_ASSERT_NULL2 (pUidOut2);
    PH_ASSERT_NULL2 (pNvbUidOut2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_Anticollision2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bCascadeLevel2, pUidIn2, bNvbUidIn2, pUidOut2, pNvbUidOut2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Select2(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint8, ANFCRL_VAR) bCascadeLevel2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2
                                 )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pUidIn2);
    PH_ASSERT_NULL2 (pSak2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_Select2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bCascadeLevel2, pUidIn2, pSak2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_ActivateCard2(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
                                       VAR(uint8, ANFCRL_VAR) bLenUidIn2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
                                       )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    if (0U != (bLenUidIn2)) PH_ASSERT_NULL2 (pUidIn2);
    PH_ASSERT_NULL2 (pUidOut2);
    PH_ASSERT_NULL2 (pLenUidOut2);
    PH_ASSERT_NULL2 (pSak2);
    PH_ASSERT_NULL2 (pMoreCardsAvailable2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_ActivateCard2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pUidIn2, bLenUidIn2, pUidOut2, pLenUidOut2, pSak2, pMoreCardsAvailable2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Exchange2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                   VAR(uint16, ANFCRL_VAR) wOption2,
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
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_Exchange2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_GetSerialNo2(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2
                                      )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pUidOut2);
    PH_ASSERT_NULL2 (pLenUidOut2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    case PHPAL_I14443P3A_SW_ID2:
        status2 = phpalI14443p3a_Sw_GetSerialNo2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pUidOut2, pLenUidOut2);
        break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */





    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_VASUpA2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                VAR(uint8, ANFCRL_VAR) bFormatByte2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes2,
                VAR(uint8, ANFCRL_VAR) bLenCmdBytes2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2
								)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pCmdBytes2);
	PH_ASSERT_NULL2 (pAtqa2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_PAL_ISO14443P3A2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
	case PHPAL_I14443P3A_SW_ID2:
		status2 = phpalI14443p3a_Sw_VASUpA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bFormatByte2,pCmdBytes2,bLenCmdBytes2,pAtqa2);
		break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */



	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
		break;
	}

    return status2;
}

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3A2 */

#ifdef __cplusplus
}
#endif /*__cplusplus */