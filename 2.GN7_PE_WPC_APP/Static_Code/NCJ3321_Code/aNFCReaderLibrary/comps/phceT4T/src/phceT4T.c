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
*   @file    phceT4T.c
*   @version 1.0.0
*
*   @brief   AUTOSAR CeT4T - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phceT4T NFC Forum Type 4A Card Emulation
*   @ingroup phce
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
#include <phceT4T.h>
#include <ph_RefDefs.h>
#ifdef NXPBUILD__PHCE_T4T_SW
#include "Sw/phceT4T_Sw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phceT4T.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCET4T_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCET4T_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHCET4T_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHCET4T_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHCET4T_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHCET4T_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHCET4T_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phceT4T.h header file are of the same vendor */
#if (PHCET4T_VENDOR_ID_C != PHCET4T_VENDOR_ID)
    #error "phceT4T.c and phceT4T.h have different vendor ids"
#endif
/* Check if current file and PHCET4T.h header file are of the same Autosar version */
#if ((PHCET4T_AR_RELEASE_MAJOR_VERSION_C    != PHCET4T_AR_RELEASE_MAJOR_VERSION) || \
     (PHCET4T_AR_RELEASE_MINOR_VERSION_C    != PHCET4T_AR_RELEASE_MINOR_VERSION) || \
     (PHCET4T_AR_RELEASE_REVISION_VERSION_C != PHCET4T_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phceT4T.c and phceT4T.h are different"
#endif
/* Check if current file and PHCET4T.h header file are of the same Software version */
#if ((PHCET4T_SW_MAJOR_VERSION_C != PHCET4T_SW_MAJOR_VERSION) || \
     (PHCET4T_SW_MINOR_VERSION_C != PHCET4T_SW_MINOR_VERSION) || \
     (PHCET4T_SW_PATCH_VERSION_C != PHCET4T_SW_PATCH_VERSION))
    #error "Software Version Numbers of phceT4T.c and phceT4T.h are different"
#endif
#endif /* NXPBUILD__PHCE_T4T_SW */
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
#ifdef NXPBUILD__PHCE_T4T

#ifndef NXPRDLIB_REM_GEN_INTFS

#define ANFCRL_START_SEC_CODE
#if ((PHCET4T_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_SetElementaryFile(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFileType,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFile,
                  VAR(uint16, ANFCRL_VAR) wFileId,
                  VAR(uint32, ANFCRL_VAR) dwFileSize,
                  VAR(uint32, ANFCRL_VAR) dwContentLen
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_SetElementaryFile(
			(phceT4T_Sw_DataParams_t *) pDataParams,
			bFileType,
			pFile,
			wFileId,
			dwFileSize,
			dwContentLen);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_ProcessCmd(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wOption,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
              VAR(uint16, ANFCRL_VAR) wRxDataLen,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
              P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_ProcessCmd(
			(phceT4T_Sw_DataParams_t *)pDataParams,
			wOption,
			pRxData,
			wRxDataLen,
			pStatusWord,
			ppTxData,
			pTxDataLen);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Activate(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_Activate((phceT4T_Sw_DataParams_t *)pDataParams);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_AppProcessCmd(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(phceT4T_AppCallback_t, ANFCRL_VAR) pAppCallback
								)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_AppProcessCmd(
			(phceT4T_Sw_DataParams_t *)pDataParams,
			pAppCallback);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_GetSelectedFileInfo(
                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFileId,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFile,
                      P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize,
                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pWriteAccess,
                      P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pFileOffset
									    )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_GetSelectedFileInfo(
			(phceT4T_Sw_DataParams_t *)pDataParams,
			pFileId,
			ppFile,
			pFileSize,
			pWriteAccess,
			pFileOffset);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Reset(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
						)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_Reset((phceT4T_Sw_DataParams_t *)pDataParams);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_SetConfig(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wConfig,
              VAR(uint16, ANFCRL_VAR) wValue
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	PH_ASSERT_NULL (pDataParams);

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_SetConfig(
			(phceT4T_Sw_DataParams_t *)pDataParams,
			wConfig,
			wValue);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_GetConfig(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wConfig,
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Check data parameters */
	if (PH_GET_COMPCODE(pDataParams) != PH_COMP_CE_T4T)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
	}

	/* perform operation on active layer */
	switch (PH_GET_COMPID(pDataParams))
	{
#ifdef NXPBUILD__PHCE_T4T_SW
	case PHCE_T4T_SW_ID:
		status = phceT4T_Sw_GetConfig(
			(phceT4T_Sw_DataParams_t *)pDataParams,
			wConfig,
			pValue);
		break;
#endif /* NXPBUILD__PHCE_T4T_SW */

	default:
		status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_CE_T4T);
		break;
	}

	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCET4T_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

#endif /* NXPBUILD__PHCE_T4T */

#ifdef __cplusplus
}
#endif
