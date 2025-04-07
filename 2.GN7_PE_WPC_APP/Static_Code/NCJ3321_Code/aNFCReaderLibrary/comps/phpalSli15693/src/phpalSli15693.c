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
*   @file    phpalSli15693.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693 - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalSli15693 ISO/IEC 15693 
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

#include <phpalSli15693.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHPAL_SLI15693_SW
#include "Sw/phpalSli15693_Sw.h"
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
#ifdef NXPBUILD__PHPAL_SLI15693
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli15693.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalSli15693.h header file are of the same vendor */
#if (PHPALSLI15693_VENDOR_ID_C != PHPALSLI15693_VENDOR_ID)
    #error "phpalSli15693.c and phpalSli15693.h have different vendor ids"
#endif
/* Check if current file and phpalSli15693.h header file are of the same Autosar version */
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C    != PHPALSLI15693_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C    != PHPALSLI15693_AR_RELEASE_MINOR_VERSION) || \
     (PHPALSLI15693_AR_RELEASE_REVISION_VERSION_C != PHPALSLI15693_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalSli15693.c and phpalSli15693.h are different"
#endif
/* Check if current file and phpalSli15693.h header file are of the same Software version */
#if ((PHPALSLI15693_SW_MAJOR_VERSION_C != PHPALSLI15693_SW_MAJOR_VERSION) || \
     (PHPALSLI15693_SW_MINOR_VERSION_C != PHPALSLI15693_SW_MINOR_VERSION) || \
     (PHPALSLI15693_SW_PATCH_VERSION_C != PHPALSLI15693_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalSli15693.c and phpalSli15693.h are different"
#endif
#endif /* NXPBUILD__PHPAL_SLI15693 */
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
#ifdef NXPBUILD__PHPAL_SLI15693
#ifndef  NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Inventory(
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 VAR(uint8, ANFCRL_VAR) bFlags,
                 VAR(uint8, ANFCRL_VAR) bAfi,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                 VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	if (0U != (bMaskBitLength)) PH_ASSERT_NULL (pMask);
	PH_ASSERT_NULL (pDsfid);
	PH_ASSERT_NULL (pUid);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_Inventory(
			(phpalSli15693_Sw_DataParams_t*)pDataParams,
			bFlags,
			bAfi,
			pMask,
			bMaskBitLength,
			pDsfid,
			pUid);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_SendEof(
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 VAR(uint8, ANFCRL_VAR) bOption,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
								 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pDsfid);
	PH_ASSERT_NULL (pUid);
	PH_ASSERT_NULL (pUidLength);
	PH_ASSERT_NULL (pData);
	PH_ASSERT_NULL (pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_SendEof(
			(phpalSli15693_Sw_DataParams_t*)pDataParams,
			bOption,
			pDsfid,
			pUid,
			pUidLength,
			pData,
			pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_StayQuiet(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_StayQuiet((phpalSli15693_Sw_DataParams_t*)pDataParams);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Select(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_Select((phpalSli15693_Sw_DataParams_t*)pDataParams );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_ResetToReady(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_ResetToReady((phpalSli15693_Sw_DataParams_t*)pDataParams );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Exchange(
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
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_Exchange((phpalSli15693_Sw_DataParams_t*)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_ActivateCard(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bOption,
                    VAR(uint8, ANFCRL_VAR) bFlags,
                    VAR(uint8, ANFCRL_VAR) bAfi,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	if (0U != (bMaskBitLength)) PH_ASSERT_NULL (pMask);
	PH_ASSERT_NULL (pDsfid);
	PH_ASSERT_NULL (pUid);
	PH_ASSERT_NULL (pMoreCardsAvailable);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_ActivateCard(
			(phpalSli15693_Sw_DataParams_t*)pDataParams,
			bOption,
			bFlags,
			bAfi,
			pMask,
			bMaskBitLength,
			pDsfid,
			pUid,
			pMoreCardsAvailable);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_GetSerialNo(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pUid);
	PH_ASSERT_NULL (pUidLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_GetSerialNo((phpalSli15693_Sw_DataParams_t*)pDataParams, pUid, pUidLength );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_SetSerialNo(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                   VAR(uint8, ANFCRL_VAR) bUidLength
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pUid);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_SetSerialNo((phpalSli15693_Sw_DataParams_t*)pDataParams, pUid, bUidLength );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_SetConfig(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wConfig,
                   VAR(uint16, ANFCRL_VAR) wValue
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693)
	{
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_SetConfig((phpalSli15693_Sw_DataParams_t*)pDataParams, wConfig, wValue );
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_GetConfig(
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wConfig,
                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pValue);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_GetConfig(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, wConfig, pValue);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_InventoryRead(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     VAR(uint8, ANFCRL_VAR) bFlags,
                     VAR(uint8, ANFCRL_VAR) bAfi,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                     VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                     VAR(uint8, ANFCRL_VAR) bBlockNo,
                     VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_InventoryRead(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bBlockNo, wNoOfBlocks, pUid, pUidLength,
				pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_InventoryReadExtended(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                       VAR(uint8, ANFCRL_VAR) bFlags,
                       VAR(uint8, ANFCRL_VAR) bAfi,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                       VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                       VAR(uint8, ANFCRL_VAR) bExtendedOptions,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
                       VAR(uint8, ANFCRL_VAR) bBlockNo,
                       VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
										   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pCIDOut);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_InventoryReadExtended(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bExtendedOptions, pCID, bBlockNo,
				wNoOfBlocks, pCIDOut, pUid, pUidLength, pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_FastInventoryRead(
      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
      VAR(uint8, ANFCRL_VAR) bFlags,
      VAR(uint8, ANFCRL_VAR) bAfi,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
      VAR(uint8, ANFCRL_VAR) bMaskBitLength,
      VAR(uint8, ANFCRL_VAR) bBlockNo,
      VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
			)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_FastInventoryRead(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bBlockNo, wNoOfBlocks, pUid, pUidLength,
				pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_FastInventoryReadExtended(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layers parameter structure. */
                       VAR(uint8, ANFCRL_VAR) bFlags,            /**< [In] Request flags byte. */
                       VAR(uint8, ANFCRL_VAR) bAfi,              /**< [In] Application Family Identifier. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,           /**< [In] UID mask, holding known UID bits. */
                       VAR(uint8, ANFCRL_VAR) bMaskBitLength,    /**< [In] Number of UID bits within pMask. */
                       VAR(uint8, ANFCRL_VAR) bExtendedOptions,  /**< [In] Extended options */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,            /**< [In] Two byte CID -> if marked in extended options */
                       VAR(uint8, ANFCRL_VAR) bBlockNo,          /**< [In] Block Number from where start reading */
                       VAR(uint16, ANFCRL_VAR) wNumOfBlocks,     /**< [In] Number of blocks to read */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,        /**< [Out] Received UID. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,            /**< [Out] Received UID. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,      /**< [Out] Received UID Length. */
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,           /**< [Out] Received Data. */
                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength     /**< [Out] Received Data Length. */
										   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pCIDOut);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_FastInventoryReadExtended(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bExtendedOptions, pCID, bBlockNo,
				wNumOfBlocks, pCIDOut, pUid, pUidLength, pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_InventoryPageRead(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        VAR(uint8, ANFCRL_VAR) bFlags,
        VAR(uint8, ANFCRL_VAR) bAfi,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
        VAR(uint8, ANFCRL_VAR) bMaskBitLength,
        VAR(uint8, ANFCRL_VAR) bPageNo,
        VAR(uint16, ANFCRL_VAR) wNoOfPages,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_InventoryPageRead(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bPageNo, wNoOfPages, pUid, pUidLength,
				pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_FastInventoryPageRead(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint8, ANFCRL_VAR) bFlags,
                VAR(uint8, ANFCRL_VAR) bAfi,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                VAR(uint8, ANFCRL_VAR) bPageNo,
                VAR(uint16, ANFCRL_VAR) wNoOfPages,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);
	if (0U != (bMaskBitLength))
		PH_ASSERT_NULL(pMask);
	PH_ASSERT_NULL(pUid);
	PH_ASSERT_NULL(pUidLength);
	PH_ASSERT_NULL(pData);
	PH_ASSERT_NULL(pDataLength);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_FastInventoryPageRead(
				(phpalSli15693_Sw_DataParams_t*) pDataParams, bFlags, bAfi,
				pMask, bMaskBitLength, bPageNo, wNoOfPages, pUid, pUidLength,
				pData, pDataLength);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_StayQuietPersistent(
                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
											 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL(pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_PAL_SLI15693) {
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);

		return status;
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams)) {
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	case PHPAL_SLI15693_SW_ID:
		status = phpalSli15693_Sw_StayQuietPersistent(
				(phpalSli15693_Sw_DataParams_t*) pDataParams);
		break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS,
				PH_COMP_PAL_SLI15693);
		break;
	}

	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */
#endif /* NXPBUILD__PHPAL_SLI15693 */

#ifdef __cplusplus
}
#endif