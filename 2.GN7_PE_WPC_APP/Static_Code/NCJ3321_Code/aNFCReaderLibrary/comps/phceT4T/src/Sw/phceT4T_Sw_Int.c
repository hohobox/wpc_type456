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
*   @file    phceT4T_Sw_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR CeT4T_Sw_Int - API usage in common use cases.
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

#include <ph_RefDefs.h>
#include <ph_Status.h>
#include <phDriver.h>
#include <phpalI14443p4mC.h>
#include <phTools.h>

#ifdef NXPBUILD__PHCE_T4T_SW
#include "phceT4T_Sw.h"
#include "phceT4T_Sw_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phceT4T_Sw_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHCET4T_SW_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHCET4T_SW_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHCET4T_SW_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHCET4T_SW_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHCET4T_SW_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phceT4T_Sw_Int.h header file are of the same vendor */
#if (PHCET4T_SW_INT_VENDOR_ID_C != PHCET4T_SW_INT_VENDOR_ID)
    #error "phceT4T_Sw_Int.c and phceT4T_Sw_Int.h have different vendor ids"
#endif
/* Check if current file and phceT4T_Sw_Int.h header file are of the same Autosar version */
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION_C    != PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION_C    != PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHCET4T_SW_INT_AR_RELEASE_REVISION_VERSION_C != PHCET4T_SW_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phceT4T_Sw_Int.c and phceT4T_Sw_Int.h are different"
#endif
/* Check if current file and phceT4T_Sw_Int.h header file are of the same Software version */
#if ((PHCET4T_SW_INT_SW_MAJOR_VERSION_C != PHCET4T_SW_INT_SW_MAJOR_VERSION) || \
     (PHCET4T_SW_INT_SW_MINOR_VERSION_C != PHCET4T_SW_INT_SW_MINOR_VERSION) || \
     (PHCET4T_SW_INT_SW_PATCH_VERSION_C != PHCET4T_SW_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phceT4T_Sw_Int.c and phceT4T_Sw_Int.h are different"
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
#ifdef NXPBUILD__PHCE_T4T_SW

#define ANFCRL_START_SEC_CODE
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetCcFile(
                  P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCcFile,
                  VAR(uint16, ANFCRL_VAR) wCcFileId,
                  VAR(uint16, ANFCRL_VAR) wCcFileSize,
                  VAR(uint16, ANFCRL_VAR) wCcContentLen
									)
{
#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT wIndex;
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

	/* Check current state */
	if(pDataParams->bTagState != PHCE_T4T_STATE_NONE)
	{
		return (PH_ERR_USE_CONDITION | PH_COMP_CE_T4T);
	}

	/* Check for CC file size */
	if((wCcFileSize < 15U) || (wCcFileSize == 0xFFFFU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Content length shall not be more than file size */
	if(wCcFileSize < wCcContentLen)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Validate file ID */
	if(wCcFileId != PHCE_T4T_CC_FILE_ID)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Validate content length */
	if((wCcContentLen > 0U) && (wCcContentLen < 15U))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Initialize CC file with default values, if content length is '0' */
	if(wCcContentLen == 0U)
	{
		/* CC Length */
		pCcFile[0] = 0x00u;
		pCcFile[1] = 0x0Fu;

		/* Mapping Version */
		pCcFile[2] = 0x20u;

		/* MLe */
		pCcFile[3] = 0x00u;
		pCcFile[4] = 0xFFu;

		/* MLc */
		pCcFile[5] = 0x00u;
		pCcFile[6] = 0xFFu;

		/* Tag (T) of Default NDEF TLV */
		pCcFile[7]  = 0x04u;

		/* Length (L) of Default NDEF TLV */
		pCcFile[8]  = 0x06u;

		/* NDEF File ID */
		pCcFile[9]  = 0xE1u;
		pCcFile[10] = 0x04u;

		/* NDEF File Size */
		pCcFile[11] = 0x00u;
		pCcFile[12] = 0x00u;

		/* Read access */
		pCcFile[13] = 0x00u;

		/* Write access */
		pCcFile[14] = 0x00u;

		/* Update content length */
		wCcContentLen = 15u;
	}
	else
	{
		/* Validate content of CCLEN field with provided CC content length */
		if((((uint16)pCcFile[0] << 8U ) | pCcFile[1]) != wCcContentLen)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate supported version numbers */
		if((pCcFile[2] != 0x30U) && (pCcFile[2] != 0x20U))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate content length and version number */
		if((pCcFile[2] == 0x30U) && (wCcContentLen < 17U))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Check for minimum MLe */
		if(((((uint16)pCcFile[3] << 8U) & 0xFF00U) | pCcFile[4]) < 0x0FU)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Check for minimum MLc */
		if(((((uint16)pCcFile[5] << 8U) & 0xFF00U) | pCcFile[6]) < 0x01U)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate NDEF file ID */
		if((((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10])) == 0x0000U)
			|| (((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10])) == 0xE102U)
			|| (((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10])) == 0xE103U)
			|| (((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10]))== 0x3F00U)
			|| (((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10])) == 0x3FFFU)
			|| (((((uint16)pCcFile[9] << 8U) & 0xFF00U) | (pCcFile[10])) == 0xFFFFU))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate NDEF TLV and NDEF file size (5 - 0xFFFE) */
		if((pCcFile[2] == 0x20U) && ((pCcFile[7] != 0x04U) || (pCcFile[8] != 0x06U)
		   || ((((((uint16)pCcFile[11]) << 8U) & 0xFF00U) | pCcFile[12]) < 0x05U)
		   || ((((((uint16)pCcFile[11]) << 8U) & 0xFF00U) | pCcFile[12]) == 0xFFFFU)))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
		/* Validate Extended NDEF TLV and NDEF file size (0xFFFF - 0xFFFFFFFE) */
		if((pCcFile[2] == 0x30U) && ((pCcFile[7] != 0x06U) || (pCcFile[8] != 0x08U)
		   || (((((uint32)pCcFile[11] << 24U) & 0xFF000000U)
			  | (((uint32)pCcFile[12] << 16U) & 0xFF0000U)
			  | (((uint32)pCcFile[13] << 8U) & 0xFF00U) | pCcFile[14]) < 0xFFFFU)
		   || (((((uint32)pCcFile[11] << 24U) & 0xFF000000U)
			  | (((uint32)pCcFile[12] << 16U) & 0xFF0000U)
			  | (((uint32)pCcFile[13] << 8U) & 0xFF00U) | pCcFile[14]) == 0xFFFFFFFFU)))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */
		/* Validate NDEF read access */
		if(((pCcFile[2] == 0x20U) && (pCcFile[13] != 0x00U))
		   || ((pCcFile[2] == 0x30U) && (pCcFile[15] != 0x00U)))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate NDEF write access */
		if(((pCcFile[2] == 0x20U) && (pCcFile[14] != 0x00U) && (pCcFile[14] != 0xFFU))
		   || ((pCcFile[2] == 0x30U) && (pCcFile[16] != 0x00U) && (pCcFile[16] != 0xFFU)))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
	}

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
	/* Check NDEF type to get content length till NDEF TLV end */
	if(pCcFile[2] == 0x20U)
	{
		wIndex = 15;
	}
	else
	{
		wIndex = 17;
	}

	/* Validate Proprietary TLVs length */
	if(((wCcContentLen - wIndex) % 8U) != 0U)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Validate Proprietary TLV content */
	while(wCcContentLen > wIndex)
	{
		/* Validate T and L field of proprietary TLV */
		if((pCcFile[wIndex] != 0x05U) || (pCcFile[wIndex + 1U] != 0x06U))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate file ID */
		if((((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U])) == 0x0000U)
			|| (((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U])) == 0xE102U)
			|| (((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U])) == 0xE103U)
			|| (((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U]))== 0x3F00U)
			|| (((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U])) == 0x3FFFU)
			|| (((((uint16)pCcFile[wIndex + 2U] << 8U) & 0xFF00U) | (pCcFile[wIndex + 3U])) == 0xFFFFU))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate minimum file size */
		if((((((uint16)pCcFile[wIndex + 4U]) << 8U) & 0xFF00U) | pCcFile[wIndex + 5U]) < 0x03U)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate read access */
		if(pCcFile[wIndex + 6U] != 0x00U)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Validate write access */
		if((pCcFile[wIndex + 7U] != 0x00U) && (pCcFile[wIndex + 7U] != 0xFFU))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Increment Index */
		wIndex += 8U;
	}
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */
#if !defined(NXPBUILD__PHCE_T4T_PROPRIETARY)
	/* If only NDEF TLV is present, content length shall be 15 or 17 */
	if((wCcContentLen != 15U) && (wCcContentLen != 17U))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

	pDataParams->pCcFile = pCcFile;
	pDataParams->wCcFileSize = wCcFileSize;
	pDataParams->wCcContentLen = wCcContentLen;

	/* Set '0' for remaining file content */
	(void)memset(&pCcFile[wCcContentLen], 0, ((uint32)wCcFileSize - (uint32)wCcContentLen));

	/* Update state */
	pDataParams->bTagState = PHCE_T4T_STATE_CC_FILE_CREATED;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetNdefFile(
                  P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNdefFile,
                  VAR(uint16, ANFCRL_VAR) wNdefFileId,
                  VAR(uint32, ANFCRL_VAR) dwNdefFileSize,
                  VAR(uint32, ANFCRL_VAR) dwNdefContentLen
									)
{
	/* Check current state */
	if(pDataParams->bTagState != PHCE_T4T_STATE_CC_FILE_CREATED)
	{
		return (PH_ERR_USE_CONDITION | PH_COMP_CE_T4T);
	}

	/* Check for NDEF file size */
	if((dwNdefFileSize < 5U) || (dwNdefFileSize == 0xFFFFFFFFU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Content length shall not be more than file size */
	if(dwNdefFileSize < dwNdefContentLen)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Validate file ID */
	if((wNdefFileId == 0x0000U) || (wNdefFileId == 0xE102U) || (wNdefFileId == 0xE103U)
	   || (wNdefFileId == 0x3F00U) || (wNdefFileId == 0x3FFFU) || (wNdefFileId == 0xFFFFU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Set NDEF file TLV in CC file */
	if(dwNdefFileSize < 0xFFFEU)
	{

		/* Reset CC content if Set CC file content and SetNdefFile content are not
		 * matching in NDEF TLV type / T4T version */
		if(pDataParams->pCcFile[2] != 0x20U)
		{
			/* CC Length */
			pDataParams->pCcFile[0] = 0x00u;
			pDataParams->pCcFile[1] = 0x0Fu;

			/* Mapping Version */
			pDataParams->pCcFile[2] = 0x20u;

			/* Tag field of TLV */
			pDataParams->pCcFile[7]  = 0x04u;
			/* Length field of TLV */
			pDataParams->pCcFile[8]  = 0x06u;

			/* Read access */
			pDataParams->pCcFile[13] = 0x00u;
			/* Write access */
			pDataParams->pCcFile[14] = 0x00u;
		}

		/* NDEF File Size */
		pDataParams->pCcFile[11] = (uint8)((dwNdefFileSize & 0xFF00U) >> 8U);
		pDataParams->pCcFile[12] = (uint8)(dwNdefFileSize & 0xFFU);

	}
#ifdef NXPBUILD__PHCE_T4T_EXT_NDEF
	else
	{
		if(pDataParams->wCcFileSize < 17U)
		{
			/* Extended NDEF TLV not supported with current CC file size */
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}

		/* Reset CC content if Set CC file content and SetNdefFile content are not
		 * matching in NDEF TLV type / T4T version */
		if(pDataParams->pCcFile[2] != 0x30U)
		{
			/* CC Length */
			pDataParams->pCcFile[0] = 0x00u;
			pDataParams->pCcFile[1] = 0x11u;

			/* Mapping Version */
			pDataParams->pCcFile[2] = 0x30u;

			/* Tag field of TLV */
			pDataParams->pCcFile[7]  = 0x06u;
			/* Length field of TLV */
			pDataParams->pCcFile[8]  = 0x08u;

			/* Read access */
			pDataParams->pCcFile[15] = 0x00u;
			/* Write access */
			pDataParams->pCcFile[16] = 0x00u;
		}

		/* NDEF File Size */
		pDataParams->pCcFile[11] = (uint8)((dwNdefFileSize & 0xFF000000U) >> 24U);
		pDataParams->pCcFile[12] = (uint8)((dwNdefFileSize & 0xFF0000U) >> 16U);
		pDataParams->pCcFile[13] = (uint8)((dwNdefFileSize & 0xFF00U) >> 8U);
		pDataParams->pCcFile[14] = (uint8)(dwNdefFileSize & 0xFFU);
	}
#endif /* NXPBUILD__PHCE_T4T_EXT_NDEF */

	/* Update file ID in CC */
	pDataParams->pCcFile[9]  = (uint8)((wNdefFileId & 0xFF00U) >> 8U);
	pDataParams->pCcFile[10] = (uint8)(wNdefFileId & 0xFFU);

	pDataParams->pNdefFile = pNdefFile;
	pDataParams->dwNdefFileSize = dwNdefFileSize;

	/* Set '0' for remaining file content */
	(void)memset(&pNdefFile[dwNdefContentLen], 0, (dwNdefFileSize - dwNdefContentLen));

	/* Update state */
	pDataParams->bTagState = PHCE_T4T_STATE_NDEF_FILE_CREATED;

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetProprietaryFile(
                       P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFile,
                       VAR(uint16, ANFCRL_VAR) wFileId,
                       VAR(uint16, ANFCRL_VAR) wFileSize,
                       VAR(uint16, ANFCRL_VAR) wContentLen
											 )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT wIndex;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bCount;

	/* Check current state */
	if(pDataParams->bTagState != PHCE_T4T_STATE_NDEF_FILE_CREATED)
	{
		return (PH_ERR_USE_CONDITION | PH_COMP_CE_T4T);
	}

	/* Check for file size */
	if((wFileSize < 3U) || (wFileSize == 0xFFFFU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Content length shall not be more than file size */
	if(wFileSize < wContentLen)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Check proprietary file count */
	if(pDataParams->bProprietaryFileCount == PHCE_T4T_MAX_PROPRIETARY_FILE)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Validate with reserved file ID */
	if((wFileId == 0x0000U) || (wFileId == 0xE102U) || (wFileId == 0xE103U)
	   || (wFileId == 0x3F00U) || (wFileId == 0x3FFFU) || (wFileId == 0xFFFFU))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Check with the NDEF file ID */
	if((((((uint16)pDataParams->pCcFile[9] << 8U) & 0xFF00U)
	   | (pDataParams->pCcFile[10])) == wFileId))
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Check NDEF version to get CC content length till NDEF TLV end */
	if(pDataParams->pCcFile[2] == 0x20U)
	{
		wIndex = 15;
	}
	else
	{
		wIndex = 17;
	}

	/* Check file ID with already created proprietary file IDs */
	for(bCount = 0; bCount < pDataParams->bProprietaryFileCount; bCount++)
	{
		if(((((uint16)pDataParams->pCcFile[wIndex + (bCount * 8U) + 2U] << 8U) & 0xFF00U)
		   | (pDataParams->pCcFile[wIndex + (bCount * 8U) + 3U])) == wFileId)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
		}
	}

	/* Increment CC index based on current proprietary file count */
	wIndex += pDataParams->bProprietaryFileCount * 8U;

	/* Check if CC file can hold one more TLV */
	if((wIndex + 8U) > pDataParams->wCcFileSize)
	{
		return (PH_ERR_INVALID_PARAMETER | PH_COMP_CE_T4T);
	}

	/* Check if this file was specified in CC */
	if((pDataParams->wCcContentLen <= wIndex)
	   || (pDataParams->pCcFile[wIndex + 2U] != (uint8)((wFileId & 0xFF00U) >> 8U))
	   || (pDataParams->pCcFile[wIndex + 3U] != (uint8)(wFileId & 0xFFU)))
	{
		/* Tag */
		pDataParams->pCcFile[wIndex] = 0x05;
		/* Length */
		pDataParams->pCcFile[wIndex + 1U] = 0x06;

		/* File ID */
		pDataParams->pCcFile[wIndex + 2U] = (uint8)((wFileId & 0xFF00U) >> 8U);
		pDataParams->pCcFile[wIndex + 3U] = (uint8)(wFileId & 0xFFU);

		/* Read access */
		pDataParams->pCcFile[wIndex + 6U] = 0x00;
		/* Write access */
		pDataParams->pCcFile[wIndex + 7U] = 0x00;
	}

	/* File size */
	pDataParams->pCcFile[wIndex + 4U] = (uint8)((wFileSize & 0xFF00U) >> 8U);
	pDataParams->pCcFile[wIndex + 5U] = (uint8)(wFileSize & 0xFFU);

	/* Update index */
	wIndex += 8U;

	/* Update CC Length to indicate content length till this TLV */
	pDataParams->pCcFile[0] = (uint8)((wIndex & 0xFF00U) >> 8U);
	pDataParams->pCcFile[1] = (uint8)(wIndex & 0xFFU);

	/* Update proprietary file parameters */
	pDataParams->asProprietaryFile[pDataParams->bProprietaryFileCount].pFile = pFile;
	pDataParams->asProprietaryFile[pDataParams->bProprietaryFileCount].wFileSize = wFileSize;
	pDataParams->asProprietaryFile[pDataParams->bProprietaryFileCount].wContentenLen = wContentLen;

	/* Set '0' for remaining file content */
	(void)memset(&pFile[wContentLen], 0, (wFileSize - wContentLen));

	/* Increment file count */
	pDataParams->bProprietaryFileCount++;

	return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_Select(
                 P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                 VAR(uint16, ANFCRL_VAR) wRxDataLen,
                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord
								 )
{
#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_COUNT wIndex;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bCount;
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFileId;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF bNdefAppName[7] = {0xD2, 0x76, 0x00, 0x00, 0x85, 0x01, 0x01};

	/* Select file/application by name */
	if((pRxData[2] == 0x04U) && (pRxData[3] == 0x00U))
	{
		/* Check the command length and Lc for NDEF APP Select */
		if((wRxDataLen < 0x0DU) || (pRxData[4] != 0x07U))
		{
			/* Length of the command is invalid */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* Validate NDEF Tag application name. */
		if(memcmp(&pRxData[5], bNdefAppName, 7) != 0)
		{
			/* Application name mismatch */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_FILE_NOT_FOUND;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}
		else
		{
			/* NDEF Tag application Selected */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
			*pStatusWord = pDataParams->wStatusWord;
			pDataParams->bTagState = PHCE_T4T_STATE_NDEF_APP_SELECTED;

			return (PH_CE_T4T_SELECT | PH_COMP_CE_T4T);
		}
	}
	/* Select file by ID */
	else if((pRxData[2] == 0x00U) && (pRxData[3] == 0x0CU))
	{
		if (pDataParams->bTagState < PHCE_T4T_STATE_NDEF_APP_SELECTED)
		{
			/* Files are present only in NDEF APP. */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_FILE_NOT_FOUND;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* Check the length of select command and the Lc byte is 0x02. */
		if ((wRxDataLen > 0x07U) || ((pRxData[4] != 0x02U)))
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_FILE_NOT_FOUND;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* File ID to be selected */
		wFileId = (uint16)((((uint16)(pRxData[5])) << 8U) & 0xFF00U) | ((uint16)(pRxData[6]));

		if(wFileId == PHCE_T4T_CC_FILE_ID)
		{
			pDataParams->wSelectedFileId = wFileId;
			pDataParams->pSelectedFile = pDataParams->pCcFile;
			pDataParams->dwFileSize = pDataParams->wCcFileSize;
			pDataParams->bFileWriteAccess = 0xFF;
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
			pDataParams->bTagState = PHCE_T4T_STATE_FILE_SELECTED;

			return (PH_CE_T4T_SELECT | PH_COMP_CE_T4T);
		}
		else if(wFileId == (((((uint16)(pDataParams->pCcFile[9])) << 8U) & 0xFF00U)
				| (((uint16)(pDataParams->pCcFile[10])))))
		{
			pDataParams->wSelectedFileId = wFileId;
			pDataParams->pSelectedFile = pDataParams->pNdefFile;
			pDataParams->dwFileSize = pDataParams->dwNdefFileSize;

			if(pDataParams->pCcFile[2] == 0x20U)
			{
				/* NDEF File Write access */
				pDataParams->bFileWriteAccess = pDataParams->pCcFile[14];
			}
			else
			{
				/* Extended NDEF Writ access */
				pDataParams->bFileWriteAccess = pDataParams->pCcFile[16];
			}

			pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
			pDataParams->bTagState = PHCE_T4T_STATE_FILE_SELECTED;

			/* File selected */
			return (PH_CE_T4T_SELECT | PH_COMP_CE_T4T);
		}

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
		else if(0U != (pDataParams->bProprietaryFileCount))
		{
			if(pDataParams->pCcFile[2] == 0x20U)
			{
				/* Index of the first Proprietary TLV in version 2.0 */
				wIndex = 17;
			}
			else
			{
				/* Index of the first Proprietary TLV in version 3 .0 */
				wIndex = 19;
			}

			/* Check file ID exists in the application */
			for(bCount = 0; bCount < pDataParams->bProprietaryFileCount; bCount++)
			{
				if((((((uint16)pDataParams->pCcFile[wIndex + (bCount * 8U)]) << 8U) & 0xFF00U)
						| (pDataParams->pCcFile[wIndex + (bCount * 8U) + 1U])) == wFileId)
				{
					/* Proprietary file Selected */
					pDataParams->wSelectedFileId = wFileId;
					pDataParams->pSelectedFile = pDataParams->asProprietaryFile[bCount].pFile;
					pDataParams->dwFileSize = pDataParams->asProprietaryFile[bCount].wFileSize;
					pDataParams->bFileWriteAccess = (pDataParams->pCcFile[wIndex + (bCount * 8U) + 5U]);
					pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
					pDataParams->bTagState = PHCE_T4T_STATE_FILE_SELECTED;

					/* File selected */
					return (PH_CE_T4T_SELECT | PH_COMP_CE_T4T);
				}
			}

			/* File ID to be selected does not exist among proprietary files */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_FILE_NOT_FOUND;
			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */
		else
		{
			/* Requested fileID to be selected does not exist */
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_FILE_NOT_FOUND;
			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}
	}
	else
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_PARAMETER;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_ReadBinary(
                  P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                  VAR(uint16, ANFCRL_VAR) wRxDataLen,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
									)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOffset;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLe;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCommandType;

	/* Check if the File is selected */
	if(pDataParams->pSelectedFile == NULL)
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_FUNC;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	/* Set the Offset value */
	wOffset = (uint16)((((uint16)pRxData[2] << 8U) & 0xFF00U) | pRxData[3]);

	/* Check for valid offset value */
	if(wOffset > 0x7FFFU)
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_PARAMETER;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	/* Check the Length of C-APDU (ISO 7816-4 IS-2005 section 5.1) */
	if(wRxDataLen == 0x07U)
	{
		bCommandType = PHCE_T4T_EXT_LEN_CMD;

		if(pRxData[4] != 0x00U)
		{
			pDataParams->wStatusWord =  PHCE_T4T_ISO7816_ERR_LENGTH;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}

		/* Set the Expected Length */
		wLe = (uint16)((((uint16)pRxData[wRxDataLen-2u] << 8U) & 0xFF00U) | pRxData[wRxDataLen - 1u]);

		/* Check for MLe and expected Length */
		if(((((uint16)pDataParams->pCcFile[3] << 8U) & 0xFF00U) | pDataParams->pCcFile[4]) < wLe)
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}
	}
	else if(wRxDataLen == 0x05U)
	{
		bCommandType = PHCE_T4T_SHORT_LEN_CMD;

		/* Set the Expected Length */
		wLe = pRxData[wRxDataLen - 1u];

		/* Check for MLe and Expected Length */
		if(((((uint16) pDataParams->pCcFile[3] << 8U) & 0xFF00U) | pDataParams->pCcFile[4]) < wLe)
		{
			pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
			*pStatusWord = pDataParams->wStatusWord;

			return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
		}
	}
	else
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	if((((pDataParams->dwFileSize) - wOffset) < wLe) && (wLe != 0x0000U))
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	/* Assign the the data pointer and the data length to be executed */
	*ppTxData = &(pDataParams->pSelectedFile[wOffset]);

	if(wLe != 0x0000U)
	{
		*pTxDataLen = wLe;
	}
	else
	{
		if(bCommandType == PHCE_T4T_SHORT_LEN_CMD)
		{
			*pTxDataLen = (uint16)(((pDataParams->dwFileSize - wOffset) > 0x0100U)?
					0x0100u : (pDataParams->dwFileSize - wOffset));
		}
		else
		{
			*pTxDataLen = (uint16)(((pDataParams->dwFileSize - wOffset) > 0xFFFFU)?
					0xFFFFu : (pDataParams->dwFileSize - wOffset));
		}
	}

	pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
	*pStatusWord = pDataParams->wStatusWord;
	pDataParams->bTagState = PHCE_T4T_STATE_FILE_READ;

	return (PH_CE_T4T_READ_BINARY | PH_COMP_CE_T4T);
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_UpdateBinary(
                     P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     VAR(uint16, ANFCRL_VAR) wOption,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                     VAR(uint16, ANFCRL_VAR) wRxDataLen,
                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
									   )
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOffset;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCommandType;

	if((pDataParams->bTagState < PHCE_T4T_STATE_FILE_SELECTED) || (pDataParams->pSelectedFile == NULL))
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_FUNC;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	if(pDataParams->bFileWriteAccess != 0x00U)
	{
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_UNSUPPORTED_FUNC;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE  | PH_COMP_CE_T4T);
	}

	/* Set the offset from the Parameter bytes */
	wOffset = (uint16)((((uint16)pRxData[2] << 8U) & 0xFF00U) | pRxData[3]);

	/* Update the file offset in data parameter */
	pDataParams->dwFileOffset = wOffset;

	if(wOption == PHCE_T4T_RXDEFAULT)
	{
		/* Set the wLc bytes */
		if(pRxData[4] != 0x00U)
		{
			bCommandType = PHCE_T4T_SHORT_LEN_CMD;
			pDataParams->wLc = pRxData[4];
			if((wRxDataLen - 5u) != pDataParams->wLc)
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;

				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}
		}
		else
		{
			bCommandType = PHCE_T4T_EXT_LEN_CMD;
			pDataParams->wLc = (uint16)((((uint16)pRxData[5] << 8U) & 0xFF00U) | pRxData[6]);

			if((wRxDataLen - 7u) != pDataParams->wLc)
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;

				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}
		}
	}
	else
	{
		/* Set the wLc bytes */
		if(pRxData[4] != 0x00U)
		{
			bCommandType = PHCE_T4T_SHORT_LEN_CMD;
			pDataParams->wLc = pRxData[4];

			if(!((wRxDataLen - 5u) <= pDataParams->wLc))
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;

				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}
		}
		else
		{
			bCommandType = PHCE_T4T_EXT_LEN_CMD;
			pDataParams->wLc = (uint16)((((uint16)pRxData[5] << 8U) & 0xFF00U) | pRxData[6]);

			if(!((wRxDataLen - 7u) <= pDataParams->wLc))
			{
				/* Change error code to length error */
				pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;

				return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
			}
		}
	}

	/* Check for Max File size and the data to be written */
	if(pDataParams->dwFileSize < ((uint32)wOffset + (uint32)pDataParams->wLc))
	{
		/* Change error code to length error */
		pDataParams->wStatusWord = PHCE_T4T_ISO7816_ERR_LENGTH;
		*pStatusWord = pDataParams->wStatusWord;

		return (PH_CE_T4T_FAILURE | PH_COMP_CE_T4T);
	}

	/* Assign the default out parameters */
	if(bCommandType == PHCE_T4T_SHORT_LEN_CMD)
	{
		*ppTxData = &pRxData[5];
		*pTxDataLen = (wRxDataLen - 5u);
		pDataParams->wLc = pDataParams->wLc - (wRxDataLen - 5u);
	}
	else
	{
		*ppTxData = &pRxData[7];
		*pTxDataLen = (wRxDataLen - 7u);
		pDataParams->wLc = pDataParams->wLc - (wRxDataLen - 7u);
	}

	/* Update file if configured to */
	if(pDataParams->bHandleUpdateCmd == PH_ON)
	{
		phceT4T_Sw_Int_UpdateFile(
			pDataParams,
			*ppTxData,
			*pTxDataLen);

		/* Set TX data to 0 */
		*ppTxData = NULL;
		*pTxDataLen = 0u;
	}

	pDataParams->wStatusWord = PHCE_T4T_ISO7816_SUCCESS;
	*pStatusWord = pDataParams->wStatusWord;
	pDataParams->bTagState = PHCE_T4T_STATE_FILE_UPDATE;

	return (PH_CE_T4T_UPDATE_BINARY | PH_COMP_CE_T4T);
}

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_Activate(
                  P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									)
{
  VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM events = 0u;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0u;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_BUF pRxData = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxDataLen = 0u;

  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wStatusWord;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFsd;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCidPresence;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNadPresence;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aSw[2];

  P2VAR(phceT4T_ActiveParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pActParams = pDataParams->pceT4TActParams;

	/* Be in HCE state till DESELECTED or receive error */
	switch(pActParams->bActiveState)
	{
		case PHCET4T_INT_ACTIVE_IDLE:
			/* Reset RX option */
			pDataParams->bRxOption = PH_RECEIVE_DEFAULT;
			pActParams->wOption = PH_RECEIVE_DEFAULT;
			pActParams->pTxData = NULL;
			pActParams->wTxDataLen = 0u;
			pActParams->wTxChainingLen = 0u;
			/*no break*/
		case PHCET4T_INT_ACTIVE_RECV:
			/* Receive loop for RX chaining */

			/* Receive Data */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Receive(
				pDataParams->pPalI14443p4mCDataParams,
				pActParams->wOption,
				&pRxData,
				&wRxDataLen));

			pActParams->bActiveState = PHCET4T_INT_ACTIVE_IDLE;

			if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				if(pActParams->wOption == PH_RECEIVE_DEFAULT)
				{
					/* Default processing option */
					pDataParams->bRxOption = PHCE_T4T_RXDEFAULT;
				}
				else
				{
					/* Last buffer of RX chaining */
					pDataParams->bRxOption = PHCE_T4T_RXCHAINING_BUFFER_LAST;
				}
				/* Set to default receive option */
				pActParams->wOption = PH_RECEIVE_DEFAULT;
			}
			else if((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				if(pActParams->wOption == PH_RECEIVE_DEFAULT)
				{
					/* First buffer of RX chaining */
					pDataParams->bRxOption = PHCE_T4T_RXCHAINING_BUFFER_FIRST;
				}
				else
				{
					/* Subsequent buffer of RX chaining */
					pDataParams->bRxOption = PHCE_T4T_RXCHAINING_BUFFER_CONT;
				}
				/* Set chaining receive option */
				pActParams->wOption = PH_RECEIVE_CHAINING;
			}
			else if((status & PH_ERR_MASK) == PH_ERR_SUCCESS_DESELECTED)
			{
				/* DESELECTED */
				status = (PH_ERR_SUCCESS_DESELECTED | PH_COMP_CE_T4T);

				/* Exit */
				break;
			}
			else if((status & PH_ERR_MASK) == PH_ERR_EXT_RF_ERROR)
			{
				/* External RF off */
				status = (PH_ERR_EXT_RF_ERROR | PH_COMP_CE_T4T);

				/* Exit */
				break;
			}
			else
			{
				/* Exit */
				break;
			}

			/* Process the received command */
			status = phceT4T_Sw_ProcessCmd(
				pDataParams,
				pDataParams->bRxOption,
				pRxData,
				wRxDataLen,
				&wStatusWord,
				&pActParams->pTxData,
				&pActParams->wTxDataLen);

			switch(status & PH_ERR_MASK)
			{
			case PH_CE_T4T_UPDATE_BINARY:
			case PH_CE_T4T_PROPRIETARY:
				/* If UPDATE BINARY is handled by ProcessCmd, send Status Word. */
				if(((status & PH_ERR_MASK) == PH_CE_T4T_UPDATE_BINARY)
					&& (pDataParams->bHandleUpdateCmd == PH_ON))
				{
					/* Update TX data */
					pActParams->pTxData = NULL;
					pActParams->wTxDataLen = 0u;

					/* Set data to be send flag */
					pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX0;
					break;
				}

				/* If proprietary command handling is disabled, send the Status
				 * Word (indicating unsupported command). */
				if(((status & PH_ERR_MASK) == PH_CE_T4T_PROPRIETARY)
					&& (pDataParams->bSupportProprietaryCmd == PH_OFF))
				{
					/* Update TX data */
					pActParams->pTxData = NULL;
					pActParams->wTxDataLen = 0u;

					/* Set data to be send flag */
					pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX0;
					break;
				}

				/* Copy data to application buffer */
				if(pDataParams->wAppBufferSize < wRxDataLen)
				{
					/* Return buffer overflow error */
					status = (PH_ERR_BUFFER_OVERFLOW | PH_COMP_CE_T4T);
					break;
				}
				else
				{
					phTools_memcpy(pDataParams->pAppBuffer, pRxData, wRxDataLen);

					/* Update data to be shared with AppProcessCmd */
					pDataParams->pSharedData = pDataParams->pAppBuffer;
					pDataParams->wSharedDataLen = wRxDataLen;
				}

				/* Set RX Data available event */
				PH_CHECK_FAILURE_FCT(status,
					phTools_EventPost(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_RXDATA_AVAILABLE, NULL));
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_WAITWTX;
				return PH_STATUS_INPROCESS;

			case PH_CE_T4T_SELECT:
			case PH_CE_T4T_FAILURE:
			case PH_CE_T4T_READ_BINARY:
				/* For select and failure, only status word is send */
				if (((status & PH_ERR_MASK) == PH_CE_T4T_FAILURE) || ((status & PH_ERR_MASK) == PH_CE_T4T_SELECT))
				{
					pActParams->pTxData = NULL;
					pActParams->wTxDataLen = 0u;
				}

				/* Enable transmission of response */
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX0;
				break;

			default:
				/* Control will never come here */
				break;
			}
			if(pActParams->wOption == PH_RECEIVE_CHAINING)
			{
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_RECV;
			}
			if(pActParams->bActiveState != PHCET4T_INT_ACTIVE_IDLE)
			{
				return PH_STATUS_INPROCESS;
			}
			/*Exit to return, */
			break;

		case PHCET4T_INT_ACTIVE_SENDWTX:
			/* Send WTX */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Wtx(
				pDataParams->pPalI14443p4mCDataParams));
			PH_BREAK_ON_FAILURE(status);
			/* Back to wait TX data or WTX */
			pActParams->bActiveState = PHCET4T_INT_ACTIVE_WAITWTX;
			/*no break*/
		case PHCET4T_INT_ACTIVE_WAITWTX:
			/* Loop till TX data is received from AppProcessCmd */
			/* Wait for TX Data or WTX */
			PH_CHECK_INPROCESS_FCT(status, phTools_EventPend(&pDataParams->T4TEventObj, E_EVENT_OPT_PEND_SET_ANY, 0xFFFFFFFFU,
					(E_EVT_TXDATA_AVAILABLE | E_EVT_RTO_TIMEOUT | E_EVENT_ABORT), &events));
			PH_BREAK_ON_FAILURE(status);

			if((events & E_EVT_RTO_TIMEOUT) == E_EVT_RTO_TIMEOUT)
			{
				/* Clear event */
				PH_CHECK_FAILURE_FCT(status,
					phTools_EventClear(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_RTO_TIMEOUT, NULL));
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDWTX;
				return PH_STATUS_INPROCESS;
			}
			else if((events & E_EVT_TXDATA_AVAILABLE) == E_EVT_TXDATA_AVAILABLE)
			{
				/* Clear event */
				PH_CHECK_FAILURE_FCT(status,
					phTools_EventClear(&pDataParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVT_TXDATA_AVAILABLE, NULL));

				/* Update TX Data */
				pActParams->pTxData = pDataParams->pSharedData;
				pActParams->wTxDataLen = pDataParams->wSharedDataLen;

				/* Set data to be send flag */
				/* Data received, exit and transmit the data */
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX0;
			}
			else
			{
				/* Aborted */
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_IDLE;
				return (PH_ERR_ABORTED | PH_COMP_CE_T4T);
			}
			if(pActParams->wOption == PH_RECEIVE_CHAINING)
			{
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_RECV;
				return PH_STATUS_INPROCESS;
			}
			/*Exit to return*/
			break;

		case PHCET4T_INT_ACTIVE_SENDTX0:
			/* Reset data length used for TX chaining */
			pActParams->wTxChainingLen = 0;
			pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX3;
			if(0U != (pActParams->wTxDataLen))
			{
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX2;
				/* Get FSD from PAL */
				PH_CHECK_FAILURE_FCT(status, phpalI14443p4mC_GetConfig(
					pDataParams->pPalI14443p4mCDataParams,
					PHPAL_I14443P4MC_CONFIG_FSD,
					&wFsd));

				/* Decrement PCB length (1 byte) from frame size */
				wFsd--;

				/* Check if CID is present */
				PH_CHECK_FAILURE_FCT(status, phpalI14443p4mC_GetConfig(
					pDataParams->pPalI14443p4mCDataParams,
					PHPAL_I14443P4MC_CONFIG_CID_PRESENCE,
					&wCidPresence));

				/* Decrement CID length (1 byte) from frame size if present */
				if(0U != (wCidPresence))
				{
					wFsd--;
				}

				/* Check if NAD is present */
				PH_CHECK_FAILURE_FCT(status, phpalI14443p4mC_GetConfig(
					pDataParams->pPalI14443p4mCDataParams,
					PHPAL_I14443P4MC_CONFIG_NAD_PRESENCE,
					&wNadPresence));

				/* Calculate Data length to be send with TXCHAINING option */
				pActParams->wTxChainingLen = (wFsd * (((((pActParams->wTxDataLen + 2U + wNadPresence) % wFsd) == 0U)?
					(((pActParams->wTxDataLen + 2U + wNadPresence) / wFsd) - 1u)
					: ((pActParams->wTxDataLen + 2U +  wNadPresence) / wFsd)))) - wNadPresence;
				/* Transmit first part of chain data */
				if(0U != (pActParams->wTxChainingLen))
				{
					if(pActParams->wTxChainingLen > pActParams->wTxDataLen){
						--(pActParams->wTxChainingLen);
					}
					pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX1;
				}
			}
			/*no break*/
		case PHCET4T_INT_ACTIVE_SENDTX1:
		case PHCET4T_INT_ACTIVE_SENDTX2:
			if(pActParams->bActiveState == PHCET4T_INT_ACTIVE_SENDTX1)
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Transmit(
					pDataParams->pPalI14443p4mCDataParams,
					PH_TRANSMIT_TXCHAINING,
					pActParams->pTxData,
					pActParams->wTxChainingLen));
				PH_BREAK_ON_FAILURE(status);
				pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX2;
			}
			if(pActParams->bActiveState == PHCET4T_INT_ACTIVE_SENDTX2)
			{
				/* Buffer balance TX data */
				if(pActParams->wTxDataLen > pActParams->wTxChainingLen)
				{
					PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Transmit(
						pDataParams->pPalI14443p4mCDataParams,
						PH_TRANSMIT_BUFFER_FIRST,
						&pActParams->pTxData[pActParams->wTxChainingLen],
						(pActParams->wTxDataLen - pActParams->wTxChainingLen)));
					PH_BREAK_ON_FAILURE(status);
				}
			}
			pActParams->bActiveState = PHCET4T_INT_ACTIVE_SENDTX3;
			/*no break*/
		case PHCET4T_INT_ACTIVE_SENDTX3:
			/* Copy Status word from data parameter for transmitting */
			aSw[0] = (uint8)((pDataParams->wStatusWord & 0xFF00U) >> 8U);
			aSw[1] = (uint8)(pDataParams->wStatusWord & 0xFFU);
			/* Send status word */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Transmit(
				pDataParams->pPalI14443p4mCDataParams,
				PH_TRANSMIT_BUFFER_LAST,
				aSw,
				2u));
			PH_BREAK_ON_FAILURE(status);
			pActParams->bActiveState = PHCET4T_INT_ACTIVE_RECV;
			return PH_STATUS_INPROCESS;

		default:
			break;
	}

	pActParams->bActiveState = PHCET4T_INT_ACTIVE_IDLE;
	return status;
}

FUNC(void, ANFCRL_CODE) phceT4T_Sw_Int_UpdateFile(
                P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                VAR(uint32, ANFCRL_VAR) dwDataLen
								)
{
	/* Update File */
	(void)memcpy(
		&pDataParams->pSelectedFile[pDataParams->dwFileOffset],
		pData,
		dwDataLen);

	/* Update file offset */
	pDataParams->dwFileOffset += dwDataLen;
}

FUNC(void, ANFCRL_CODE) phceT4T_Sw_Int_EventPoll(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	phceT4T_Sw_DataParams_t * pCeT4TParams = (phceT4T_Sw_DataParams_t *)pDataParams;
	phpalI14443p4mC_Sw_DataParams_t * pI14443Params = (phpalI14443p4mC_Sw_DataParams_t *)(pCeT4TParams->pPalI14443p4mCDataParams);
	VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;

	if(pI14443Params->bWtxTimerSts == PHPAL_I14443P4MC_WTX_TIMER_PENDING)
	{
		dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, pI14443Params->dwWtxStart);

		/* Check for timer overflow, abort if timer overflow happens */
		if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
		{
			(void)phTools_EventPost(&pCeT4TParams->T4TEventObj, E_EVENT_OPT_NONE, E_EVENT_ABORT, NULL);
			pI14443Params->bWtxTimerSts = PHPAL_I14443P4MC_WTX_TIMER_IDLE;
		}
		else
		{
			if(pI14443Params->dwWtxPeriod < dwElapsedTime)
			{
				 (void)phTools_EventPost(&pCeT4TParams->T4TEventObj, E_EVENT_OPT_POST_ISR, E_EVT_RTO_TIMEOUT, NULL);
				 pI14443Params->bWtxTimerSts = PHPAL_I14443P4MC_WTX_TIMER_IDLE;
			}
			else
			{
				/* Do nothing */
			}
		}
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHCE_T4T_SW */

#ifdef __cplusplus
}
#endif

