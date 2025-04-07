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
*   @file    phhalHw2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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

#include <phhalHw2.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHHAL_HW_NCx33202
#include "Ncx3320/phhalHw_Ncx33202.h"
#include <phhalHw_Ncx3320_Cmd2.h>
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
#include "Ncx3321/phhalHw_Ncx33212.h"
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw2.h header file are of the same vendor */
#if (PHHALHW_VENDOR_ID_C2 != PHHALHW_VENDOR_ID2)
    #error "phhalHw2.c and phhalHw2.h have different vendor ids"
#endif
/* Check if current file and phhalHw2.h header file are of the same Autosar version */
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw2.c and phhalHw2.h are different"
#endif
/* Check if current file and phhalHw2.h header file are of the same Software version */
#if ((PHHALHW_SW_MAJOR_VERSION_C2 != PHHALHW_SW_MAJOR_VERSION2) || \
     (PHHALHW_SW_MINOR_VERSION_C2 != PHHALHW_SW_MINOR_VERSION2) || \
     (PHHALHW_SW_PATCH_VERSION_C2 != PHHALHW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw2.c and phhalHw2.h are different"
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
#ifdef NXPBUILD__PHHAL_HW2
#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Nfc_IC_Init2(P2VAR(phhalHw_Nfc_Ic_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams2, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, VAR(uint16, ANFCRL_VAR) wTxBufSize2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2, VAR(uint16, ANFCRL_VAR) wRxBufSize2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	PH_ASSERT_NULL_PARAM2(pDataParams2, PH_COMP_HAL2);
	PH_ASSERT_NULL_PARAM2(pBalDataParams2, PH_COMP_HAL2);
	PH_ASSERT_NULL_PARAM2(pKeyStoreDataParams2, PH_COMP_HAL2);
	PH_ASSERT_NULL_PARAM2(pTxBuffer2, PH_COMP_HAL2);
	PH_ASSERT_NULL_PARAM2(pRxBuffer2, PH_COMP_HAL2);

	if (sizeof(phhalHw_Nfc_Ic_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
	}

#ifdef NXPBUILD__PHHAL_HW_NCx33202
	/* Initialize the Reader HAL (Hardware Abstraction Layer) component */
	status2 = phhalHw_Ncx3320_Init2(&pDataParams2->sHal2,
			(uint16) sizeof(phhalHw_Ncx3320_DataParams_t2), pBalDataParams2, pKeyStoreDataParams2,
			pTxBuffer2, wTxBufSize2, pRxBuffer2, wRxBufSize2);
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	/* Initialize the Reader HAL (Hardware Abstraction Layer) component */
	status2 = phhalHw_Ncx3321_Init2(
			&pDataParams2->sHal2,
			(uint16)sizeof(phhalHw_Ncx3321_DataParams_t2),
			pBalDataParams2,
			pKeyStoreDataParams2,
			pTxBuffer2,
			wTxBufSize2,
			pRxBuffer2,
			wRxBufSize2
			);
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

	PH_UNUSED_VARIABLE2(wSizeOfDataParams2);
	return status2;
}

#ifdef NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD2
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_HybridLPCD2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2(pDataParams2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHHAL_HW_NCx33202
        case PHHAL_HW_NCx3320_ID2:
        status2 = phhalHw_Ncx3320_Cmd_Hybrid_Lpcd2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
        /* NCx3321 doesn't support Hybrid LPCD */
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_HAL2);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

        default:
            status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
        break;
    }

    return status2;
}
#endif /* NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD2 */

#ifndef NXPRDLIB_REM_GEN_INTFS2

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_ApplyProtocolSettings2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint8, ANFCRL_VAR) bMode2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL_PARAM2(pDataParams2, PH_COMP_HAL2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_ApplyProtocolSettings2(
				(phhalHw_Ncx3320_DataParams_t2 *) pDataParams2, bMode2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	case PHHAL_HW_NCX3321_ID2:
		status2 = phhalHw_Ncx3321_ApplyProtocolSettings2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2, bMode2);
		break;
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_SetConfigMultiple2(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
		VAR(uint16, ANFCRL_VAR) wNumOfConfigs2,
		uint16 (*arr2dConfig2)[PHHAL_HW_ARRY_COLUMNS_SIZE2])
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_UNUSED_VARIABLE2(wNumOfConfigs2);
	PH_UNUSED_VARIABLE2(arr2dConfig2);
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(arr2dConfig2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_SetConfigMultiple2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2,
				wNumOfConfigs2, arr2dConfig2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_SetConfig2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wConfig2, VAR(uint16, ANFCRL_VAR) wValue2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_SetConfig2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2,
				wConfig2, wValue2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_SetConfig2((phhalHw_Ncx3321_DataParams_t2*)pDataParams2, wConfig2, wValue2);
			break;
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_GetConfig2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wConfig2, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pValue2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_GetConfig2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2,
				wConfig2, pValue2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_GetConfig2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2, wConfig2, pValue2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_FieldOn2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_FieldOn2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_FieldOn2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_AsyncAbort2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    PH_ASSERT_NULL2(pDataParams2);

    /* Check data parameters */
    if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
    {
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
        return status2;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID2(pDataParams2))
    {
#ifdef NXPBUILD__PHHAL_HW_NCx33202
        case PHHAL_HW_NCx3320_ID2:
        /* AsyncAbort is not available on NCx3320 */
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_HAL2);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
        case PHHAL_HW_NCX3321_ID2:
            status2 = phhalHw_Ncx3321_AsyncAbort2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
            break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
        default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
        break;
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_FieldOff2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_FieldOff2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_FieldOff2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_FieldReset2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_FieldReset2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_FieldReset2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Wait2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint8, ANFCRL_VAR) bUnit2, VAR(uint16, ANFCRL_VAR) wTimeout2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_Wait2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2, bUnit2,
				wTimeout2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_Wait2((phhalHw_Ncx3321_DataParams_t2 *) pDataParams2, bUnit2, wTimeout2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Transmit2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
              VAR(uint16, ANFCRL_VAR) wOption2,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
              VAR(uint16, ANFCRL_VAR) wTxLength2
							)
{

  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);
#ifdef NXPBUILD__PHHAL_HW_NCx33202
	UNUSED2(wOption2);
	UNUSED2(pTxBuffer2);
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

	if (0U != (wTxLength2)) PH_ASSERT_NULL2 (pTxBuffer2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
	case PHHAL_HW_NCx3320_ID2:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_HAL2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	case PHHAL_HW_NCX3321_ID2:
		status2 = phhalHw_Ncx3321_Transmit2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2, wOption2, pTxBuffer2, wTxLength2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Receive2(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
            VAR(uint16, ANFCRL_VAR) wOption2,
            P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
						)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
	case PHHAL_HW_NCx3320_ID2:
	status2 = phhalHw_Ncx3320_Receive2((phhalHw_Ncx3320_DataParams_t2 *)pDataParams2, wOption2, ppRxBuffer2, pRxLength2);
	break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	case PHHAL_HW_NCX3321_ID2:
		status2 = phhalHw_Ncx3321_Receive2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2, wOption2, ppRxBuffer2, pRxLength2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Autocoll2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
              VAR(uint16, ANFCRL_VAR) wMode2,
              P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams2
							)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2 (pDataParams2);

#ifdef NXPBUILD__PHHAL_HW_NCx33202
	UNUSED2(wMode2);
	UNUSED2(ppRxBuffer2);
	UNUSED2(pRxLength2);
	UNUSED2(pProtParams2);
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
	case PHHAL_HW_NCx3320_ID2:
		/* NCx3320 doesn't support Target Mode */
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_HAL2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	case PHHAL_HW_NCX3321_ID2:
		status2 = phhalHw_Ncx3321_Autocoll2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2, wMode2, ppRxBuffer2, pRxLength2, pProtParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Stop_Lpcd2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_Cmd_Stop_Lpcd2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_Stop_Lpcd2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Lpcd2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_Cmd_Lpcd2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_Lpcd2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_DeInit2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_DeInit2((phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_DeInit2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Exchange2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption2, /**< [In] Option parameter, only value PH_EXCHANGE_DEFAULT accepted. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, /**< [In] Data to transmit. */
    VAR(uint16, ANFCRL_VAR) wTxLength2, /**< [In] Number of bytes to transmit. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2, /**< [Out] Pointer to received data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2 /**< [Out] Number of received data bytes. */
)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	PH_ASSERT_NULL2 (pDataParams2);
	if (0U != (wTxLength2)) PH_ASSERT_NULL2 (pTxBuffer2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_Exchange2(
				(phhalHw_Ncx3320_DataParams_t2 *) pDataParams2, wOption2, pTxBuffer2, wTxLength2,
				ppRxBuffer2, pRxLength2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_Exchange2((phhalHw_Ncx3321_DataParams_t2*)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2);
			break;
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */
		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}
#ifdef NXPBUILD__PHPAL_MIFARE_SW2
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_MfcAuthenticateKeyNo2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo2, /**< [In] Authenticate for block number. */
    VAR(uint8, ANFCRL_VAR) bKeyType2, /**< [In] PHHAL_HW_MFC_KEYA or PHHAL_HW_MFC_KEYB. */
    VAR(uint16, ANFCRL_VAR) wKeyNo2, /**< [In] Key index in KeyStore. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion2, /**< [In] KeyVersion = 0. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2 /**< [In] PICC UID. */
)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_MfcAuthenticateKeyNo2(
				(phhalHw_Ncx3320_DataParams_t2 *) pDataParams2, bBlockNo2, bKeyType2, wKeyNo2, wKeyVersion2, pUid2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
		status2 = phhalHw_Ncx3321_MfcAuthenticateKeyNo2(
			(phhalHw_Ncx3321_DataParams_t2 *)pDataParams2,
			bBlockNo2,
			bKeyType2,
			wKeyNo2,
			wKeyVersion2,
			pUid2);
		 break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_MfcAuthenticate2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo2, /**< [In] Authenticate for block number. */
    VAR(uint8, ANFCRL_VAR) bKeyType2, /**< [In] PHHAL_HW_MFC_KEYA or PHHAL_HW_MFC_KEYB. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey2, /**< [In] array bytes of key, size = 6. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2 /**< [In] PICC UID. */
)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
		case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_MfcAuthenticate2(
				(phhalHw_Ncx3320_DataParams_t2 *) pDataParams2, bBlockNo2, bKeyType2, pKey2, pUid2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
		case PHHAL_HW_NCX3321_ID2:
			status2 = phhalHw_Ncx3321_MfcAuthenticate2((phhalHw_Ncx3321_DataParams_t2 *)pDataParams2,
					bBlockNo2, bKeyType2, pKey2, pUid2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

		default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW2*/

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_DetectEMD2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	PH_ASSERT_NULL2(pDataParams2);

	/* Check data parameters */
	if (PH_GET_COMPCODE2(pDataParams2) != PH_COMP_HAL2)
	{
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		return status2;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID2(pDataParams2)) {
#ifdef NXPBUILD__PHHAL_HW_NCx33202
	case PHHAL_HW_NCx3320_ID2:
		status2 = phhalHw_Ncx3320_DetectEMD2(
				(phhalHw_Ncx3320_DataParams_t2 *) pDataParams2);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

	default:
		status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
		break;
	}

	return status2;
}

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW2 */

#ifdef __cplusplus
}
#endif
