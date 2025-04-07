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
*   @file    phhalHw.c
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

#include <phhalHw.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHHAL_HW_NCx3320
#include "Ncx3320/phhalHw_Ncx3320.h"
#include <phhalHw_Ncx3320_Cmd.h>
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
#include "Ncx3321/phhalHw_Ncx3321.h"
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw.h header file are of the same vendor */
#if (PHHALHW_VENDOR_ID_C != PHHALHW_VENDOR_ID)
    #error "phhalHw.c and phhalHw.h have different vendor ids"
#endif
/* Check if current file and phhalHw.h header file are of the same Autosar version */
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_AR_RELEASE_REVISION_VERSION_C != PHHALHW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw.c and phhalHw.h are different"
#endif
/* Check if current file and phhalHw.h header file are of the same Software version */
#if ((PHHALHW_SW_MAJOR_VERSION_C != PHHALHW_SW_MAJOR_VERSION) || \
     (PHHALHW_SW_MINOR_VERSION_C != PHHALHW_SW_MINOR_VERSION) || \
     (PHHALHW_SW_PATCH_VERSION_C != PHHALHW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw.c and phhalHw.h are different"
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
#ifdef NXPBUILD__PHHAL_HW
#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Nfc_IC_Init(P2VAR(phhalHw_Nfc_Ic_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, VAR(uint16, ANFCRL_VAR) wTxBufSize, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, VAR(uint16, ANFCRL_VAR) wRxBufSize)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	PH_ASSERT_NULL_PARAM(pDataParams, PH_COMP_HAL);
	PH_ASSERT_NULL_PARAM(pBalDataParams, PH_COMP_HAL);
	PH_ASSERT_NULL_PARAM(pKeyStoreDataParams, PH_COMP_HAL);
	PH_ASSERT_NULL_PARAM(pTxBuffer, PH_COMP_HAL);
	PH_ASSERT_NULL_PARAM(pRxBuffer, PH_COMP_HAL);

	if (sizeof(phhalHw_Nfc_Ic_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
	}

#ifdef NXPBUILD__PHHAL_HW_NCx3320
	/* Initialize the Reader HAL (Hardware Abstraction Layer) component */
	status = phhalHw_Ncx3320_Init(&pDataParams->sHal,
			(uint16) sizeof(phhalHw_Ncx3320_DataParams_t), pBalDataParams, pKeyStoreDataParams,
			pTxBuffer, wTxBufSize, pRxBuffer, wRxBufSize);
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	/* Initialize the Reader HAL (Hardware Abstraction Layer) component */
	status = phhalHw_Ncx3321_Init(
			&pDataParams->sHal,
			(uint16)sizeof(phhalHw_Ncx3321_DataParams_t),
			pBalDataParams,
			pKeyStoreDataParams,
			pTxBuffer,
			wTxBufSize,
			pRxBuffer,
			wRxBufSize
			);
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

	PH_UNUSED_VARIABLE(wSizeOfDataParams);
	return status;
}

#ifdef NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_HybridLPCD(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL(pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_NCx3320
        case PHHAL_HW_NCx3320_ID:
        status = phhalHw_Ncx3320_Cmd_Hybrid_Lpcd((phhalHw_Ncx3320_DataParams_t *) pDataParams);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
        /* NCx3321 doesn't support Hybrid LPCD */
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

        default:
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    return status;
}
#endif /* NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD */

#ifndef NXPRDLIB_REM_GEN_INTFS

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_ApplyProtocolSettings(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bMode)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL_PARAM(pDataParams, PH_COMP_HAL);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_ApplyProtocolSettings(
				(phhalHw_Ncx3320_DataParams_t *) pDataParams, bMode);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	case PHHAL_HW_NCX3321_ID:
		status = phhalHw_Ncx3321_ApplyProtocolSettings((phhalHw_Ncx3321_DataParams_t *)pDataParams, bMode);
		break;
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_SetConfigMultiple(
		P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint16, ANFCRL_VAR) wNumOfConfigs,
		uint16 (*arr2dConfig)[PHHAL_HW_ARRY_COLUMNS_SIZE])
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_UNUSED_VARIABLE(wNumOfConfigs);
	PH_UNUSED_VARIABLE(arr2dConfig);
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(arr2dConfig);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_SetConfigMultiple((phhalHw_Ncx3320_DataParams_t *) pDataParams,
				wNumOfConfigs, arr2dConfig);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_SetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_SetConfig((phhalHw_Ncx3320_DataParams_t *) pDataParams,
				wConfig, wValue);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_SetConfig((phhalHw_Ncx3321_DataParams_t*)pDataParams, wConfig, wValue);
			break;
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_GetConfig(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pValue);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_GetConfig((phhalHw_Ncx3320_DataParams_t *) pDataParams,
				wConfig, pValue);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_GetConfig((phhalHw_Ncx3321_DataParams_t *)pDataParams, wConfig, pValue);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldOn(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_FieldOn((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_FieldOn((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_AsyncAbort(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    PH_ASSERT_NULL(pDataParams);

    /* Check data parameters */
    if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
    {
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        return status;
    }

    /* perform operation on active layer */
    switch (PH_GET_COMPID(pDataParams))
    {
#ifdef NXPBUILD__PHHAL_HW_NCx3320
        case PHHAL_HW_NCx3320_ID:
        /* AsyncAbort is not available on NCx3320 */
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
        break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
        case PHHAL_HW_NCX3321_ID:
            status = phhalHw_Ncx3321_AsyncAbort((phhalHw_Ncx3321_DataParams_t *)pDataParams);
            break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
        default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
        break;
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldOff(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_FieldOff((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_FieldOff((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldReset(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_FieldReset((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_FieldReset((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Wait(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bUnit, VAR(uint16, ANFCRL_VAR) wTimeout)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_Wait((phhalHw_Ncx3320_DataParams_t *) pDataParams, bUnit,
				wTimeout);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_Wait((phhalHw_Ncx3321_DataParams_t *) pDataParams, bUnit, wTimeout);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Transmit(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wOption,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
              VAR(uint16, ANFCRL_VAR) wTxLength
							)
{

  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
#ifdef NXPBUILD__PHHAL_HW_NCx3320
	UNUSED(wOption);
	UNUSED(pTxBuffer);
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

	if (0U != (wTxLength)) PH_ASSERT_NULL (pTxBuffer);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
	case PHHAL_HW_NCx3320_ID:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	case PHHAL_HW_NCX3321_ID:
		status = phhalHw_Ncx3321_Transmit((phhalHw_Ncx3321_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Receive(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
            VAR(uint16, ANFCRL_VAR) wOption,
            P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
						)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
	case PHHAL_HW_NCx3320_ID:
	status = phhalHw_Ncx3320_Receive((phhalHw_Ncx3320_DataParams_t *)pDataParams, wOption, ppRxBuffer, pRxLength);
	break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	case PHHAL_HW_NCX3321_ID:
		status = phhalHw_Ncx3321_Receive((phhalHw_Ncx3321_DataParams_t *)pDataParams, wOption, ppRxBuffer, pRxLength);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Autocoll(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wMode,
              P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

#ifdef NXPBUILD__PHHAL_HW_NCx3320
	UNUSED(wMode);
	UNUSED(ppRxBuffer);
	UNUSED(pRxLength);
	UNUSED(pProtParams);
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
	case PHHAL_HW_NCx3320_ID:
		/* NCx3320 doesn't support Target Mode */
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	case PHHAL_HW_NCX3321_ID:
		status = phhalHw_Ncx3321_Autocoll((phhalHw_Ncx3321_DataParams_t *)pDataParams, wMode, ppRxBuffer, pRxLength, pProtParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Stop_Lpcd(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_Cmd_Stop_Lpcd((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_Stop_Lpcd((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Lpcd(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_Cmd_Lpcd((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_Lpcd((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_DeInit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_DeInit((phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_DeInit((phhalHw_Ncx3321_DataParams_t *)pDataParams);
			break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Exchange(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption, /**< [In] Option parameter, only value PH_EXCHANGE_DEFAULT accepted. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, /**< [In] Data to transmit. */
    VAR(uint16, ANFCRL_VAR) wTxLength, /**< [In] Number of bytes to transmit. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, /**< [Out] Pointer to received data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength /**< [Out] Number of received data bytes. */
)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);
	if (0U != (wTxLength)) PH_ASSERT_NULL (pTxBuffer);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_Exchange(
				(phhalHw_Ncx3320_DataParams_t *) pDataParams, wOption, pTxBuffer, wTxLength,
				ppRxBuffer, pRxLength);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_Exchange((phhalHw_Ncx3321_DataParams_t*)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
			break;
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */
		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}
#ifdef NXPBUILD__PHPAL_MIFARE_SW
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_MfcAuthenticateKeyNo(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo, /**< [In] Authenticate for block number. */
    VAR(uint8, ANFCRL_VAR) bKeyType, /**< [In] PHHAL_HW_MFC_KEYA or PHHAL_HW_MFC_KEYB. */
    VAR(uint16, ANFCRL_VAR) wKeyNo, /**< [In] Key index in KeyStore. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion, /**< [In] KeyVersion = 0. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid /**< [In] PICC UID. */
)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_MfcAuthenticateKeyNo(
				(phhalHw_Ncx3320_DataParams_t *) pDataParams, bBlockNo, bKeyType, wKeyNo, wKeyVersion, pUid);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
		status = phhalHw_Ncx3321_MfcAuthenticateKeyNo(
			(phhalHw_Ncx3321_DataParams_t *)pDataParams,
			bBlockNo,
			bKeyType,
			wKeyNo,
			wKeyVersion,
			pUid);
		 break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_MfcAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo, /**< [In] Authenticate for block number. */
    VAR(uint8, ANFCRL_VAR) bKeyType, /**< [In] PHHAL_HW_MFC_KEYA or PHHAL_HW_MFC_KEYB. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey, /**< [In] array bytes of key, size = 6. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid /**< [In] PICC UID. */
)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
		case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_MfcAuthenticate(
				(phhalHw_Ncx3320_DataParams_t *) pDataParams, bBlockNo, bKeyType, pKey, pUid);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
		case PHHAL_HW_NCX3321_ID:
			status = phhalHw_Ncx3321_MfcAuthenticate((phhalHw_Ncx3321_DataParams_t *)pDataParams,
					bBlockNo, bKeyType, pKey, pUid);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

		default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_DetectEMD(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_HAL)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHHAL_HW_NCx3320
	case PHHAL_HW_NCx3320_ID:
		status = phhalHw_Ncx3320_DetectEMD(
				(phhalHw_Ncx3320_DataParams_t *) pDataParams);
		break;
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
		break;
	}

	return status;
}

#endif /* NXPRDLIB_REM_GEN_INTFS */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW */

#ifdef __cplusplus
}
#endif
