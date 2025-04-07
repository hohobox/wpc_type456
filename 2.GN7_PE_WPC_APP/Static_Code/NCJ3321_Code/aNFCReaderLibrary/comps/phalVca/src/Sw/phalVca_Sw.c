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
*   @file    phalVca_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca_Sw - AL API  usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalVca Virtual Card Architecture (R)
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

#include <phhalHw.h>
#include <phalVca.h>
#include <phpalMifare.h>
#ifdef NXPBUILD__PH_CRYPTOSYM
#include <phCryptoSym.h>
#endif /* NXPBUILD__PH_CRYPTOSYM */
#ifdef NXPBUILD__PH_CRYPTORNG
#include <phCryptoRng.h>
#endif /* NXPBUILD__PH_CRYPTORNG */
#include <phKeyStore.h>
#include <ph_RefDefs.h>
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
#include <phalMfdfEVx.h>
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PHAL_VCA_SW

#include "../phalVca_Int.h"
#include "phalVca_Sw_Int.h"
#include "phalVca_Sw.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalVca_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALVCA_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALVCA_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalVca_Sw.h header file are of the same vendor */
#if (PHALVCA_SW_VENDOR_ID_C != PHALVCA_SW_VENDOR_ID)
    #error "phalVca_Sw.c and phalVca_Sw.h have different vendor ids"
#endif
/* Check if current file and phalVca_Sw.h header file are of the same Autosar version */
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C    != PHALVCA_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C    != PHALVCA_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHALVCA_SW_AR_RELEASE_REVISION_VERSION_C != PHALVCA_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca_Sw.c and phalVca_Sw.h are different"
#endif
/* Check if current file and PHALVCA_SW.h header file are of the same Software version */
#if ((PHALVCA_SW_SW_MAJOR_VERSION_C != PHALVCA_SW_SW_MAJOR_VERSION) || \
     (PHALVCA_SW_SW_MINOR_VERSION_C != PHALVCA_SW_SW_MINOR_VERSION) || \
     (PHALVCA_SW_SW_PATCH_VERSION_C != PHALVCA_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca_Sw.c and phalVca_Sw.h are different"
#endif
#endif /* NXPBUILD__PHAL_VCA_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA_SW
#define PHAL_VCA_SW_STATE_IDLE	0u
#define PHAL_VCA_SW_STATE_CMD1	1u
#define PHAL_VCA_SW_STATE_CMD2	2u
#define PHAL_VCA_SW_STATE_CMD3	3u
#define PHAL_VCA_SW_STATE_CMD4	4u

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#ifdef NXPBUILD__PH_CRYPTOSYM

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Private constants */
static CONST(uint8, ANFCRL_CONST) PH_MEMLOC_CONST_ROM phalVca_Sw_FirstIv[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_CRYPTOSYM */
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
static VAR(uint8, ANFCRL_VAR) gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Init(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams, P2VAR(phalVca_Sw_IidTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pIidTableStorage, VAR(uint16, ANFCRL_VAR) wNumIidTableStorageEntries,
  P2VAR(phalVca_Sw_CardTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pCardTableStorage, VAR(uint16, ANFCRL_VAR) wNumCardTableStorageEntries)
{
	if (sizeof(phalVca_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_VCA);
	}

	PH_ASSERT_NULL_DATA_PARAM (pDataParams, PH_COMP_AL_VCA);
	PH_ASSERT_NULL_PARAM (pPalMifareDataParams, PH_COMP_AL_VCA);

#ifdef NXPBUILD__PH_CRYPTOSYM
	PH_ASSERT_NULL_PARAM (pKeyStoreDataParams, PH_COMP_AL_VCA);
	PH_ASSERT_NULL_PARAM (pCryptoDataParams, PH_COMP_AL_VCA);
	PH_ASSERT_NULL_PARAM (pCryptoRngDataParams, PH_COMP_AL_VCA);
#endif /* NXPBUILD__PH_CRYPTOSYM */

	if (0U != (wNumIidTableStorageEntries)) PH_ASSERT_NULL_PARAM (pIidTableStorage, PH_COMP_AL_VCA);
	if (0U != (wNumCardTableStorageEntries)) PH_ASSERT_NULL_PARAM (pCardTableStorage, PH_COMP_AL_VCA);

	/* init private data */
	pDataParams->wId                    = PH_COMP_AL_VCA | PHAL_VCA_SW_ID;
	pDataParams->pPalMifareDataParams   = pPalMifareDataParams;
	pDataParams->pKeyStoreDataParams    = pKeyStoreDataParams;
	pDataParams->pCryptoDataParams      = pCryptoDataParams;
	pDataParams->wCurrentCardTablePos   = 0;
	pDataParams->pCardTable             = pCardTableStorage;
	pDataParams->wNumCardTableEntries   = wNumCardTableStorageEntries;
	pDataParams->pIidTable              = pIidTableStorage;
	pDataParams->wCurrentIidTablePos    = 0;
	pDataParams->wNumIidTableEntries    = wNumIidTableStorageEntries;
	pDataParams->pCryptoRngDataParams   = pCryptoRngDataParams;
	pDataParams->wAdditionalInfo        = PH_ERR_SUCCESS;
	pDataParams->eVCState               = VC_NOT_SELECTED;
	pDataParams->ePCState               = PC_NO_PCHK_IN_PROGRESS;
	pDataParams->bWrappedMode           = 0;
	pDataParams->bExtendedLenApdu       = 0;
	pDataParams->bOption                = 1;
	pDataParams->bLowerBoundThreshold   = 0;

	gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_StartCardSelection (P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex;

	for (wIndex=0; wIndex < pDataParams->wNumCardTableEntries; ++wIndex)
	{
		pDataParams->pCardTable[wIndex].bValid = PHAL_VCA_CARD_TABLE_ENTRY_INVALID;
	}

	pDataParams->wCurrentIidIndex       = 0;
	pDataParams->wCurrentCardTablePos   = 0;
	pDataParams->wCurrentIidTablePos    = 0;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_FinalizeCardSelection (P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumValidIids)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDummyValidIids = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValidIids = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex;

	for (wIndex = 0; wIndex < pDataParams->wNumCardTableEntries; ++wIndex)
	{
		if (pDataParams->pCardTable[wIndex].bValid == PHAL_VCA_CARD_TABLE_ENTRY_INVALID)
		{
			++wDummyValidIids;
		}
		else
		{
			++wValidIids;
		}
	}

	*pNumValidIids = wValidIids;

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SelectVc(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp, status;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLength;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTxBuffer[PHAL_VCA_IID_SIZE + 1];
  static VAR(uint8, ANFCRL_VAR) bVcaSelectVcState = PHAL_VCA_SW_STATE_IDLE;

	switch(bVcaSelectVcState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* Prepare command header */
			aTxBuffer[0] = PHAL_VCA_CMD_SVC;
			aTxBuffer[1] = PHAL_VCA_CMD_SVC;
			/* Resolve Iid index */
			status = phalVca_Sw_Int_ResolveValidIndex(
				pDataParams,
				wValidIidIndex,
				&wValidIidIndex);

			/* for the case of an overflow we generate random data */
			/* Prepare MAC data */
			if ((status  & PH_ERR_MASK) == PH_ERR_INVALID_PARAMETER)
			{
				wValidIidIndex = 0;
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoRng_Rnd(pDataParams->pCryptoRngDataParams, PHAL_VCA_IID_SIZE-1U, &aTxBuffer[2]));
			}
			else
			{
				PH_CHECK_SUCCESS(status);
				(void)memcpy(&aTxBuffer[2], &pDataParams->pCardTable[wValidIidIndex].pCardData[1], PHAL_VCA_IID_SIZE-1U);
			}

			/* Get MAC Key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
				pDataParams->pKeyStoreDataParams,
				wKeyNumber,
				wKeyVersion,
				(uint8)sizeof(aKey),
				aKey,
				&wKeyType));

			/* Check key type */
			if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/* Load key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
				pDataParams->pCryptoDataParams,
				aKey,
				PH_CRYPTOSYM_KEY_TYPE_AES128));

			/* Calculate MAC */
			/* CMAC with Padding */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				&aTxBuffer[1],
				PHAL_VCA_IID_SIZE,
				&aTxBuffer[1],
				&bMacLength));

			/* Truncate MAC */
			phalVca_Sw_Int_TruncateMac(&aTxBuffer[1], &aTxBuffer[1]);
			bVcaSelectVcState = PHAL_VCA_SW_STATE_CMD1;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD1:
			/* command exchange */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_DEFAULT,
				aTxBuffer,
				1U + PHAL_VCA_TRUNCATED_MAC_SIZE,
				&pResponse,
				&wRxLength));

			bVcaSelectVcState = PHAL_VCA_SW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);
			/* check response */
			PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));

			/* check response length */
			if (wRxLength != 1U /* STATUS */)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
			}
	}

	return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_DeselectVc(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTxBuffer[1];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0u;

	/* command code */
	aTxBuffer[0] = PHAL_VCA_CMD_DVC;

	/* command exchange */
	PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
		pDataParams->pPalMifareDataParams,
		PH_EXCHANGE_DEFAULT,
		aTxBuffer,
		1,
		&pResponse,
		&wRxLength));

	PH_CHECK_SUCCESS(statusTmp);

	/* check response */
	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));

	/* check response length */
	if (wRxLength != 1U /* STATUS */)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_VcSupport(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint16, ANFCRL_VAR) wKeyEncNumber, VAR(uint16, ANFCRL_VAR) wKeyEncVersion,
  VAR(uint16, ANFCRL_VAR) wKeyMacNumber, VAR(uint16, ANFCRL_VAR) wKeyMacVersion)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTxBuffer[1];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength;
  static VAR(uint8, ANFCRL_VAR) bVcaVcSupportState = PHAL_VCA_SW_STATE_IDLE;

	switch(bVcaVcSupportState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* Check available space in key duos list */
			if (pDataParams->wCurrentIidTablePos >= pDataParams->wNumIidTableEntries )
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_VCA);
			}

			/* Add keys and iids to the iid table list */
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wIidIndex = pDataParams->wCurrentIidIndex;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyEncNumber = wKeyEncNumber;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyEncVersion = wKeyEncVersion;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyMacNumber = wKeyMacNumber;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyMacVersion = wKeyMacVersion;
			pDataParams->wCurrentIidTablePos++;
			pDataParams->wCurrentIidIndex++;

			/* command code */
			aTxBuffer[0] = PHAL_VCA_CMD_VCS;

			/* buffer the command frame */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				aTxBuffer,
				1,
				&pResponse,
				&wRxLength));
			PH_CHECK_SUCCESS(statusTmp);
			bVcaVcSupportState = PHAL_VCA_SW_STATE_CMD1;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD1:
			/* Append IID and exchange the command */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				pIid,
				PHAL_VCA_IID_SIZE,
				&pResponse,
				&wRxLength));

			bVcaVcSupportState = PHAL_VCA_SW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);

			/* check response */
			PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));

			/* check response length */
			if (wRxLength != 1U /* STATUS */)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
			}
	}

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_VcSupportLast(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint8, ANFCRL_VAR) bLenCap, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapabilities,
  VAR(uint16, ANFCRL_VAR) wKeyEncNumber, VAR(uint16, ANFCRL_VAR) wKeyEncVersion, VAR(uint16, ANFCRL_VAR) wKeyMacNumber, VAR(uint16, ANFCRL_VAR) wKeyMacVersion)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static uint8                  PH_MEMLOC_REM aTmpBuf[PH_CRYPTOSYM_AES_BLOCK_SIZE * 2U];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTxBuffer[1];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMac[PH_CRYPTOSYM_AES_BLOCK_SIZE];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLength;
  VAR(phalVca_Sw_CardTableEntry_t, ANFCRL_VAR) PH_MEMLOC_REM pDummyCardData;
  P2VAR(phalVca_Sw_CardTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pCardDataStorage = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex;
  static VAR(uint8, ANFCRL_VAR) bVcaVcSupportLastState = PHAL_VCA_SW_STATE_IDLE;

	switch(bVcaVcSupportLastState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* Copy PCD Caps */
			(void)memset(aTmpBuf, 0x00, 4);
			if (0U != (bLenCap))
			{
				if (bLenCap > 3U)
				{
					bLenCap = 3;
				}
				aTmpBuf[0] = bLenCap;
				(void)memcpy(&aTmpBuf[1], pPcdCapabilities, bLenCap);
			}

			/* Check available space in key duos list */
			if (pDataParams->wCurrentIidTablePos >= pDataParams->wNumIidTableEntries)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_VCA);
			}

			/* Check available space in card table */
			if (pDataParams->wCurrentCardTablePos >= pDataParams->wNumCardTableEntries)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_VCA);
			}

			/* Add keys and iids to the iid table list */
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wIidIndex = pDataParams->wCurrentIidIndex;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyEncNumber = wKeyEncNumber;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyEncVersion = wKeyEncVersion;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyMacNumber = wKeyMacNumber;
			pDataParams->pIidTable[pDataParams->wCurrentIidTablePos].wKeyMacVersion = wKeyMacVersion;
			pDataParams->wCurrentIidTablePos++;
			pDataParams->wCurrentIidIndex++;

			bVcaVcSupportLastState = PHAL_VCA_SW_STATE_CMD1;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD1:
			/* Generate RNDQ */
			PH_CHECK_FAILURE_FCT(statusTmp, phCryptoRng_Rnd(pDataParams->pCryptoRngDataParams, 12, &aTmpBuf[PHAL_VCA_POS_RNDQ]));

			/* Build the command frame */
			aTxBuffer[0] = PHAL_VCA_CMD_VCSL;

			/* buffer command frame */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				aTxBuffer,
				1,
				&pResponse,
				&wRxLength));
			PH_BREAK_ON_FAILURE(statusTmp);
			bVcaVcSupportLastState = PHAL_VCA_SW_STATE_CMD2;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD2:
			/* buffer installation identifier */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pIid,
				PHAL_VCA_IID_SIZE,
				&pResponse,
				&wRxLength));
			PH_BREAK_ON_FAILURE(statusTmp);
			bVcaVcSupportLastState = PHAL_VCA_SW_STATE_CMD3;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD3:
			/* buffer RNDQ identifier */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&aTmpBuf[PHAL_VCA_POS_RNDQ],
				12,
				&pResponse,
				&wRxLength));
			PH_BREAK_ON_FAILURE(statusTmp);

			bVcaVcSupportLastState = PHAL_VCA_SW_STATE_CMD4;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD4:
			/* append PCDCaps and transmit the command */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				&aTmpBuf[0],
				(uint16)(1U + (uint16)bLenCap),
				&pResponse,
				&wRxLength));

			bVcaVcSupportLastState = PHAL_VCA_SW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);

			PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));

			/* check response length */
			if (wRxLength != (1U /*Status */ + 16U /* Cryptogram */ + 8U /*MAC */))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
			}

			/* Prepare MAC data */
			aTmpBuf[0] = pResponse[0];
			(void)memcpy(&aTmpBuf[PHAL_VCA_POS_PAYLOAD], &pResponse[1], 16);

			/* Iterate over all available key pairs and try to find a match */
			for (wIndex = pDataParams->wCurrentIidTablePos; wIndex > 0U; --wIndex)
			{
				/* Retrieve MAC key */
				PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
					pDataParams->pKeyStoreDataParams,
					pDataParams->pIidTable[(wIndex-1u)].wKeyMacNumber,
					pDataParams->pIidTable[(wIndex-1u)].wKeyMacVersion,
					(uint8)sizeof(aKey),
					aKey,
					&wKeyType));

				/* Check key type */
				if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
				}

				/* Load the key */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
					pDataParams->pCryptoDataParams,
					aKey,
					PH_CRYPTOSYM_KEY_TYPE_AES128));

				/* Set the correct MAC calculation mode */
				/* CMAC with Padding */
				/* Calculate the MAC */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
					pDataParams->pCryptoDataParams,
					PH_CRYPTOSYM_MAC_MODE_CMAC,
					aTmpBuf,
					32,
					bMac,
					&bMacLength));

				/* Truncate the MAC */
				phalVca_Sw_Int_TruncateMac(bMac, bMac);

				/* Compare the MACs */
				if (memcmp(&pResponse[17], bMac, PHAL_VCA_TRUNCATED_MAC_SIZE) == 0)
				{
					pCardDataStorage = &pDataParams->pCardTable[pDataParams->wCurrentCardTablePos];
				}
				else
				{
					pCardDataStorage = &pDummyCardData;
				}

				/* In any case, we need to decrypt */
				pCardDataStorage->bValid = PHAL_VCA_CARD_TABLE_ENTRY_VALID;

				/* Retrieve ENC key */
				PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
					pDataParams->pKeyStoreDataParams,
					pDataParams->pIidTable[(wIndex-1u)].wKeyEncNumber,
					pDataParams->pIidTable[(wIndex-1u)].wKeyEncVersion,
					(uint8)sizeof(aKey),
					aKey,
					&wKeyType));

				/* Check key type */
				if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
				}

				/* Load the key */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
					pDataParams->pCryptoDataParams,
					aKey,
					PH_CRYPTOSYM_KEY_TYPE_AES128));

				/* Load first IV*/
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParams,
					phalVca_Sw_FirstIv,
					PH_CRYPTOSYM_AES_BLOCK_SIZE));

				/* Perform decryption */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
					pDataParams->pCryptoDataParams,
					PH_CRYPTOSYM_CIPHER_MODE_CBC,
					&pResponse[1],
					PHAL_VCA_IID_SIZE,
					pCardDataStorage->pCardData
					));

				/* Copy the found IID Index */
				pCardDataStorage->wIidIndex = pDataParams->pIidTable[(wIndex-1u)].wIidIndex;
			}

			pDataParams->wCurrentIidTablePos = 0;
			++pDataParams->wCurrentCardTablePos;
	}

	bVcaVcSupportLastState = PHAL_VCA_SW_STATE_IDLE;
	return statusTmp;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_GetIidInfo(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pIidIndex, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUidSize,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInfo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPdCapabilities)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_Int_ResolveValidIndex(
		pDataParams,
		wValidIidIndex,
		&wValidIidIndex));

	*pIidIndex = pDataParams->pCardTable[wValidIidIndex].wIidIndex;
	*pInfo = pDataParams->pCardTable[wValidIidIndex].pCardData[0];
	pPdCapabilities[0] = pDataParams->pCardTable[wValidIidIndex].pCardData[1];
	pPdCapabilities[1] = pDataParams->pCardTable[wValidIidIndex].pCardData[2];

	if (0U != (*pInfo & 0x80U))
	{
		*pVcUidSize = 4;
		(void)memcpy(pVcUid, &pDataParams->pCardTable[wValidIidIndex].pCardData[3], 4);
	}
	else
	{
		*pVcUidSize = 7;
		(void)memcpy(pVcUid, &pDataParams->pCardTable[wValidIidIndex].pCardData[3], 7);
	}

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_IsoSelect(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSelectionControl, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bDFnameLen,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFCI, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bData[20] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLc = 0x00U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[PHAL_VCA_CMD_SIZE] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
	static VAR(uint8, ANFCRL_VAR) bVcaIsoSelectState = PHAL_VCA_SW_STATE_IDLE;

	switch(bVcaIsoSelectState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			if ((bDFnameLen == 0U) || (bDFnameLen > 16U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}
			if ((bOption != 0x00U) || (bSelectionControl != 0x04U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/*
			 * ReSet the Error code stored in pDataParams->wAdditionalInfo to default value as
			 * PH_ERR_SUCCESS. This is to flush any error code stored as a part of previous cmd execution.
			 */
			PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_SetConfig(pDataParams,PHAL_VCA_ADDITIONAL_INFO,PH_ERR_SUCCESS));
			bVcaIsoSelectState = PHAL_VCA_SW_STATE_CMD1;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD1:
			/* Selection by DF Name */
			(void)memcpy(bData, pDFname, bDFnameLen);
			bLc = bDFnameLen;

			/* command formation */
			bCmdBuff[wCmdLen++] = 0x00;                 /* Class is always 0x00 */
			bCmdBuff[wCmdLen++] = PHAL_VCA_CMD_ISOSVC;  /* INS */
			bCmdBuff[wCmdLen++] = bSelectionControl;    /* P1 */
			bCmdBuff[wCmdLen++] = bOption;              /* P2 */

			/*
			 * As per ISO-7816 Standard(2005), section 5.1,
			 * A short Lc field consists of one byte not set to '00'.
			 * From '01' to 'FF', the byte encodes Nc from one to 255.
			 *
			 * An extended Lc field consists of three bytes: one byte
			 * set to '00' followed by two bytes not set to '0000'.From
			 * '0001' to 'FFFF', the two bytes encode Nc from one to
			 * 65535.
			 */
			if(pDataParams->bExtendedLenApdu != 0U)
			{
				/* Extended Length APDU (3 bytes as Lc to be passed) */
				bCmdBuff[wCmdLen++] = 0x00;    /* first byte will be 0x00 if Ext apdu present. Next 2 byte contains actual data */
				bCmdBuff[wCmdLen++] = 0x00;    /* As of now this field will be set to 0x00 since maximum data that can be sent is 16 bytes. In case if data to be sent exceeds 255 bytes, this byte shall be used. */
				bCmdBuff[wCmdLen++] = bLc;     /* Actual data to be sent */
			}
			else
			{
				/* Short APDU( 1 byte of Lc to be passed)  */
				bCmdBuff[wCmdLen++] = bLc;  /* IID length; In this case it is DF Name */
			}

			/*  command exchange with (CLA INS P1 P2 Lc)*/
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bVcaIsoSelectState = PHAL_VCA_SW_STATE_CMD2;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD2:
			/* Data exchange */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				bData,
				bDFnameLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);

		#ifdef NXPBUILD__PHAL_MFDFEVX_SW
			/* Reset the EV2 authentication since the PICC moves its state from card specific state to VCA state.
			 * Any card authentication maintained will be reset by card. The same has to be done at reader side
			 */
			if((pDataParams->eVCState == VC_DF_AUTH_D40) ||
			   (pDataParams->eVCState == VC_DF_AUTH_ISO) ||
			   (pDataParams->eVCState == VC_DF_AUTH_EV2) ||
			   (pDataParams->eVCState == VC_DF_AUTH_AES))
			{
				if(pDataParams->pAlDataParams != NULL)
				{
					PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_ResetAuthentication(pDataParams->pAlDataParams));
				}
			}
		#endif /* NXPBUILD__PHAL_MFDFEVX_SW */
		#ifdef NXPBUILD__PHAL_MFPEVX_SW
			/* Reset the MPFEV1 authentication since the PICC moves its state from card specific state to VCA state. Hence
			 * Any card authentication maintained will be reset by card. The same has to be done at reader side.
			 */
			if((pDataParams->eVCState == VC_MFP_AUTH_AES_SL1) ||
			   (pDataParams->eVCState == VC_MFP_AUTH_AES_SL3))
			{
				if(pDataParams->pAlDataParams != NULL)
				{
					PH_CHECK_SUCCESS_FCT(statusTmp, phalMfpEVx_ResetSecMsgState(pDataParams->pAlDataParams));
				}
			}
		#endif /* NXPBUILD__PHAL_MFPEVX_SW */

			bVcaIsoSelectState = PHAL_VCA_SW_STATE_CMD3;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD3:
			wCmdLen = 0;

			/* As per ISO/IEC:7816-4(2005), Section 5, An extended Le field consists of either three bytes
			 * (one byte set to '00' followed by two bytes with any
			 * value) if the Lc field is absent, or two bytes (with any value) if an extended Lc field is present.
			 */
			if(pDataParams->bExtendedLenApdu != 0U)
			{
				/*
				 * Extended Length APDU (2 bytes as Le to be passed since Lc is present, Refer to iso7816-4 page no 13)
				 * Hard coding the Le value to 0x00 since Spec says this command will always have Le = 0x00
				 */
				bCmdBuff[wCmdLen++] = 0x00;
				bCmdBuff[wCmdLen++] = 0x00;
			}
			else
			{
				/* Short Length APDU (1 byte as Le to be passed) */
				bCmdBuff[wCmdLen++] = 0x00;
			}

			/* NOTE: As per Ref Arch Ver 0.15, the Le is given as 1,3(mandatory) and Lc is 1,3(mandatory). This is in contrast to
			 * the ISO 7816-4 standard where it says Le can be 3 bytes when Lc is not present.
			 * But as per ref arch Lc is always present which means that extended Le shall be always 2 bytes.
			 */

			/* Command exchange with Le*/
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			bVcaIsoSelectState = PHAL_VCA_SW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);

			statusTmp = pRecv[wRxlen - 2U];
			statusTmp <<= 8;
			statusTmp |= pRecv[wRxlen - 1U];

			PH_CHECK_FAILURE_FCT(statusTmp, phalVca_Int_ComputeErrorResponse_Extended(pDataParams, statusTmp));
			if (wRxlen != 0U)
			{
				/* After receiving the response, we need to update the VCState to VC_DF_NOT_AUTH */
				pDataParams->eVCState = VC_DF_NOT_AUTH;

				if (wRxlen == 0x02U)
				{
					/* Since no MAC is returned, this indicates AuthVCMandatory flag is not set and IsoSelect is success
					 * as per the ref arch(v 15) page no 283 */
					pDataParams->eVCState = VC_PROXIMITYCHECK;
					*pwFCILen = (uint16) (wRxlen - 2U);
					statusTmp = PH_ERR_SUCCESS;
					break;
				}
				else if(wRxlen == (PHAL_VCA_AUTH_RND_LEN + 6U))
				{
					*pwFCILen = (uint16) (wRxlen - 2U) ;    /* FCI Length should be 36 bytes excluding 2 bytes of status data */
					/* As per reference architecture, Handling the two response cases:
					 * Case-1: [if TargetVC != NULL AND TargetVC.AuthVCMandatory == TRUE] and
					 * Case-2: [if TargetVC == NULL] in a single if-case since there is no way to get 'AuthVCMandatory' and 'targeted IID Supported' flag values */

					/* 4 Bytes Header + 16 Bytes RndChal + 16 Bytes Payload + 2 Bytes SW1||SW2 (Total 38 Bytes returned) */
					if ((pRecv[0]== 0x6FU) && (pRecv[1]== 0x22U) && (pRecv[2]== 0x85U) && (pRecv[3]== 0x20U))
					{
						if(memcpy(pFCI, &pRecv[0], 36) == NULL) /* Copy the entire 36 bytes of data (RndChal + Payload) */
						{
							 return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
						}
					}
					else
					{   /* Case-3: [if TargetVC != NULL AND TargetVC.AuthVCMandatory == false AND (IID is DESFire application DF name)]
						 * FCI[36] bytes shall be stored in file ID 31 of the DF */
						(void) memcpy(pFCI, &pRecv[0], 36);
					}
				}
				/* Case-3: [if TargetVC != NULL AND TargetVC.AuthVCMandatory == false AND (IID is DESFire application DF name)]
				 * FCI[1...MaxFileSize] bytes shall be stored in file ID 31 of the DF + 2 bytes SW1||SW2 */
				else
				{
					/* FCI contains contents of FileID 31 of the DF */
					(void) memcpy(pFCI, &pRecv[0], (uint8)(wRxlen-2U));
					*pwFCILen = (uint16) (wRxlen - 2U);
				}
			}
	}

	bVcaIsoSelectState = PHAL_VCA_SW_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_IsoExternalAuthenticate(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[PHAL_VCA_CMD_SIZE];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMac[PH_CRYPTOSYM_AES_BLOCK_SIZE];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLength;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIv[16];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIv_bak[PH_CRYPTOSYM_AES128_KEY_SIZE];
  P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pCryptoDataParamsTmp;
  static VAR(uint8, ANFCRL_VAR) bVcaIsoExternalAuthenticateState = PHAL_VCA_SW_STATE_IDLE;

	switch(bVcaIsoExternalAuthenticateState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/*
			 * ReSet the Error code stored in pDataParams->wAdditionalInfo to default value as
			 * PH_ERR_SUCCESS. This is to flush any error code stored as a part of previous cmd execution.
			 */
			PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_SetConfig(pDataParams, PHAL_VCA_ADDITIONAL_INFO, PH_ERR_SUCCESS));

			/* Get Iso AUTH Key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
				pDataParams->pKeyStoreDataParams,
				wKeyNumber,
				wKeyVersion,
				(uint8)sizeof(aKey),
				aKey,
				&wKeyType));

			/* Check key type */
			if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/* Load Iso AUTH Key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
				pDataParams->pCryptoDataParams,
				aKey,
				PH_CRYPTOSYM_KEY_TYPE_AES128));

			/* Set the bIv_bak buffer to 0s */
			(void)memset(bIv_bak, 0x00, PH_CRYPTOSYM_AES128_KEY_SIZE);

			/* Take the back up of existing IV here */
			pCryptoDataParamsTmp = (phCryptoSym_Sw_DataParams_t *)pDataParams->pCryptoDataParams;
		    if(strlen((char*)(pCryptoDataParamsTmp->pIV)) != 0U)
			{
				(void)memcpy(bIv_bak, pCryptoDataParamsTmp->pIV, PH_CRYPTOSYM_AES128_KEY_SIZE);
			}
			/* Reset IV for the first crypto operation */
			(void)memset(bIv, 0x00, 16);

			/* Load zero Iv.*/
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
				pDataParams->pCryptoDataParams,
				bIv,
				16));
			/* CMAC with Padding */
			/* mac calculation: CMAC(RndChal || VCData) */
			status = phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				pInData,
				PHAL_VCA_AUTH_RND_LEN,
				bMac,
				&bMacLength);
			if(status != PH_ERR_SUCCESS)
			{
				/* Load back up Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParams,
					bIv_bak,
					PH_CRYPTOSYM_AES128_KEY_SIZE));
				return status;
			}
			/* Load the original IV back */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
				pDataParams->pCryptoDataParams,
				bIv_bak,
				PH_CRYPTOSYM_AES128_KEY_SIZE));

			/* Perform MAC Truncation: [0, 2, 4, 6, 8, 10, 12, 14] of the input Mac */
			phalVca_Sw_Int_TruncateMac(bMac, bMac);
			bVcaIsoExternalAuthenticateState = PHAL_VCA_SW_STATE_CMD1;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD1:
			/* Prepare "IsoExternalAuthenticate" command */
			bCmdBuff[wCmdLen++] = 0x00;                     /* Class is always 0x00 */
			bCmdBuff[wCmdLen++] = PHAL_VCA_CMD_ISOEXT_AUTH; /* INS */
			bCmdBuff[wCmdLen++] = 0x00;                     /* P1 */
			bCmdBuff[wCmdLen++] = 0x00;                     /* P2 */

			/*
			 * As per ISO-7816 Standard(2005), section 5.1,
			 * A short Lc field consists of one byte not set to '00'.
			 * From '01' to 'FF', the byte encodes Nc from one to 255.
			 *
			 * An extended Lc field consists of three bytes: one byte
			 * set to '00' followed by two bytes not set to '0000'.From
			 * '0001' to 'FFFF', the two bytes encode Nc from one to
			 * 65535.
			 */
			if(0U != (pDataParams->bExtendedLenApdu))
			{
				/* Extended Length APDU (3 bytes as Lc to be passed) */
				bCmdBuff[wCmdLen++] = 0x00;
				bCmdBuff[wCmdLen++] = 0x00;
				bCmdBuff[wCmdLen++] = 0x08;  /* As per ref arch ver 0.15, Response to Challenge  will be 8 bytes always.*/
			}
			else
			{
				/* Short Length APDU (1 byte as Lc to be passed) */
				bCmdBuff[wCmdLen++] = 0x08;     /* As per ref arch ver 0.15, Response to Challenge  will be 8 bytes always.*/
			}

			/* command exchange CLA INS P1 P2 Lc */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bVcaIsoExternalAuthenticateState = PHAL_VCA_SW_STATE_CMD2;
			/* no break */

		case PHAL_VCA_SW_STATE_CMD2:
			/* command exchange Data(MAC) */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bMac,
				PHAL_VCA_TRUNCATED_MAC_SIZE,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];

			statusTmp = phalVca_Int_ComputeErrorResponse_Extended(pDataParams, statusTmp);

			if(statusTmp == PH_ERR_SUCCESS)
			{
				/* MAC is verified properly and is a success, so the VC State needs to be updated to proximity check */
				pDataParams->eVCState = VC_PROXIMITYCHECK;
			}
			else
			{
				/* MAC is verified properly and is not a success, so the VC State needs to be updated to proximity failed */
				pDataParams->eVCState = VC_PROXIMITYFAILED;
			}
	}

	bVcaIsoExternalAuthenticateState = PHAL_VCA_SW_STATE_IDLE;
	return statusTmp;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */


#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_ProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, VAR(uint8, ANFCRL_VAR) bPps1,
  VAR(uint8, ANFCRL_VAR) bNumSteps, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_Cmd_PrepareProximityCheck(pDataParams));

	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_Cmd_ProximityCheck(pDataParams, bGenerateRndC, pRndC, bNumSteps, pUsedRndRC));

	return (phalVca_Sw_Cmd_VerifyProximityCheck(pDataParams, pUsedRndRC, bPps1, wKeyNumber, wKeyVersion));
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_ProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
  VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_Cmd_PrepareProximityCheckNew(pDataParams, pOption, pPubRespTime, pResponse, pRespLen));

	PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Sw_Cmd_ProximityCheckNew(pDataParams, bGenerateRndC, pPrndC, bNumSteps, pPubRespTime, pCumRndRC));

	return (phalVca_Sw_Cmd_VerifyProximityCheckNew(pDataParams, *pOption, pPubRespTime, pResponse, *pRespLen, wKeyNumber, wKeyVersion, pCumRndRC));
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_PrepareProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	/* send "Prepare Proximity Check" command */
	return(phalVca_Int_PrepareProximityCheck(pDataParams->pPalMifareDataParams));
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_PrepareProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption,  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	/* Before sending the PPC command, set the PC state as PC_PPC_IN_PROGRESS */
	pDataParams->ePCState = PC_PPC_IN_PROGRESS;

	/* send "Prepare Proximity Check" command */
	PH_CHECK_INPROCESS_FCT(statusTmp, phalVca_Int_PrepareProximityCheckNew(pDataParams, pOption, pPubRespTime, pResponse, pRespLen));

	if(statusTmp == PH_ERR_SUCCESS)
	{
		/* PPC command is a success, set the PC state as PC_PCHK_PREPARED */
		pDataParams->ePCState = PC_PCHK_PREPARED;
	}
	else
	{
		/* PPC command is a failure, set the PC state back to PC_NO_PCHK_IN_PROGRESS */
		pDataParams->ePCState = PC_NO_PCHK_IN_PROGRESS;
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_ProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndC[PHAL_VCA_PC_RND_LEN];

	switch(gbVcaCmdState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* parameter checking */
			if (((bGenerateRndC == 0U) && (pRndC == NULL)) || (pUsedRndRC == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/* check whether to generate RndC or not */
			if (0U != (bGenerateRndC))
			{
				pRndC = bRndC;
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoRng_Rnd(
					pDataParams->pCryptoRngDataParams,
					PHAL_VCA_PC_RND_LEN,
					pRndC
					));
			}
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_SW_STATE_CMD1:
			/* send "Proximity Check" command */
			PH_CHECK_INPROCESS_FCT(statusTmp, phalVca_Int_ProximityCheck(
				pDataParams->pPalMifareDataParams,
				bNumSteps,
				pRndC,
				pUsedRndRC));
			gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);
			break;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_ProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndC[PHAL_VCA_PC_RND_LEN_NEW];

	switch(gbVcaCmdState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* parameter checking */
			if (((bGenerateRndC == 0U) && (pPrndC == NULL)) || (pCumRndRC == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/* check whether to generate RndC or not */
			if (0U != (bGenerateRndC))
			{
				pPrndC = bRndC;
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoRng_Rnd(
					pDataParams->pCryptoRngDataParams,
					PHAL_VCA_PC_RND_LEN_NEW,
					pPrndC
					));
			}
			/* Before sending the PC command, set the PC state as PC_PCHK_IN_PROGRESS */
			pDataParams->ePCState = PC_PCHK_IN_PROGRESS;
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_SW_STATE_CMD1:
			/* send "Proximity Check" command */
			PH_CHECK_INPROCESS_FCT(statusTmp, phalVca_Int_ProximityCheckNew(
				pDataParams,
				bNumSteps,
				pPubRespTime,
				pPrndC,
				pCumRndRC));
			gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
			if(statusTmp == PH_ERR_SUCCESS)
			{
				/* PC command is a success, set the PC state as PC_WAITING_PC_VERIFICATION */
				pDataParams->ePCState = PC_WAITING_PC_VERIFICATION;

				/* Update the state to ProximityCheck state in case of VC not authenticated. */
				if((pDataParams->eVCState != VC_DF_AUTH_EV2) && (pDataParams->eVCState != VC_DF_AUTH_AES) &&
					(pDataParams->eVCState != VC_MFP_AUTH_AES_SL1) && (pDataParams->eVCState != VC_MFP_AUTH_AES_SL3))
				{
					pDataParams->eVCState = VC_PROXIMITYCHECK;
				}
			}
			else
			{
				/* PC command is a failure, set the PC state back to PC_NO_PCHK_IN_PROGRESS */
				pDataParams->ePCState = PC_NO_PCHK_IN_PROGRESS;
				return statusTmp;
			}

			break;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC, VAR(uint8, ANFCRL_VAR) bPps1, VAR(uint16, ANFCRL_VAR) wKeyNumber,
  VAR(uint16, ANFCRL_VAR) wKeyVersion)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTmpBuf[2U + PHAL_VCA_PC_RND_LEN * 2U] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMac[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLength = 0U;

	switch(gbVcaCmdState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* prepare "Verify Proximity Check" command */
			aTmpBuf[0] = PHAL_VCA_CMD_VPC;
			aTmpBuf[1] = bPps1;
			(void)memcpy(&aTmpBuf[2], pRndRC, PHAL_VCA_PC_RND_LEN * 2U);

			/* Get Proximity Check Key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
				pDataParams->pKeyStoreDataParams,
				wKeyNumber,
				wKeyVersion,
				(uint8)(sizeof(aKey)),
				aKey,
				&wKeyType));

			/* Check key type */
			if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			/* Load Proximity Check Key */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
				pDataParams->pCryptoDataParams,
				aKey,
				PH_CRYPTOSYM_KEY_TYPE_AES128));

			/* CMAC with Padding */
			/* mac calculation: CMAC(CMD || PPS1 || (RndRC1 || ... || RndRC14)) */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				aTmpBuf,
				(2u + (PHAL_VCA_PC_RND_LEN * 2U)),
				bMac,
				&bMacLength));

			/* perform MAC truncation */
			phalVca_Sw_Int_TruncateMac(bMac, bMac);
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD1;
			/*no break*/

		case PHAL_VCA_SW_STATE_CMD1:
			/* buffer the command code */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				aTmpBuf,
				1,
				&pResponse,
				&wRxLength));
			PH_BREAK_ON_FAILURE(statusTmp);
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD2;
			/*no break*/
		case PHAL_VCA_SW_STATE_CMD2:
			/* append the MAC and exchange frame */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bMac,
				PHAL_VCA_TRUNCATED_MAC_SIZE,
				&pResponse,
				&wRxLength));
			gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
			PH_BREAK_ON_FAILURE(statusTmp);
			/* check response */
			PH_CHECK_FAILURE_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));

			/* check response length */
			if (wRxLength != (1U /* Status */ + 8U /* MAC */))
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
				break;
			}

			/* Calculate MAC */
			aTmpBuf[0] = pResponse[0];
			aTmpBuf[1] = bPps1;
			(void)memcpy(&aTmpBuf[2], pRndRC, PHAL_VCA_PC_RND_LEN * 2U);
			PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				aTmpBuf,
				(2u + (PHAL_VCA_PC_RND_LEN * 2U)),
				bMac,
				&bMacLength));

			/* perform MAC truncation */
			phalVca_Sw_Int_TruncateMac(bMac, bMac);

			/* Compare MAC */
			if (memcmp(bMac, &pResponse[1], PHAL_VCA_TRUNCATED_MAC_SIZE) != 0)
			{
				return PH_ADD_COMPCODE_FIXED(PHAL_VCA_ERR_AUTH, PH_COMP_AL_VCA);
			}
			break;
	}

	for(uint8 i = 0U; i < (2U + (PHAL_VCA_PC_RND_LEN * 2U)); i++)
	{
		aTmpBuf[i] = 0U;
	}
	gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
  VAR(uint16, ANFCRL_VAR) wRespLen, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndCmdResp)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponseTmp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd[9];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTmpBuf[15 /* Cmd / Rsp + Option + PubRspTime + PPS + ActBitRate */ + PHAL_VCA_PC_RND_LEN_NEW * 2];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTmpBufLen = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMac[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0};
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLength;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIv_bak[PH_CRYPTOSYM_AES128_KEY_SIZE];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM Key_bak[PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRespCode;
	phCryptoSym_Sw_DataParams_t PH_MEMLOC_REM *pCryptoDataParamsTmp = (phCryptoSym_Sw_DataParams_t *)pDataParams->pCryptoDataParams;

	switch(gbVcaCmdState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* prepare "Verify Proximity Check" command */
			aTmpBuf[aTmpBufLen++] = PHAL_VCA_CMD_VPC;
			aTmpBuf[aTmpBufLen++] = bOption;
			aTmpBuf[aTmpBufLen++] = pPubRespTime[0];
			aTmpBuf[aTmpBufLen++] = pPubRespTime[1];

			/* Reset the aKey buffer */
			(void)memset(aKey, 0x00, PH_CRYPTOSYM_AES128_KEY_SIZE);

			/* bPps1 is optional, present if bit[0] of bOption is set */
			if(0U != (bOption & 0x01U))
			{
				aTmpBuf[aTmpBufLen++] = *pResponse;
			}

			/* ActBitRate is optional, present if bit[1] of bOption is set */
			if((bOption & 0x02U) != 0U)
			{
				(void)memcpy(&aTmpBuf[aTmpBufLen], pResponse, wRespLen);
				aTmpBufLen += (uint8) wRespLen;
			}

			(void)memcpy(&aTmpBuf[aTmpBufLen], pRndCmdResp, PHAL_VCA_PC_RND_LEN_NEW * 2U);

			switch(pDataParams->eVCState)
			{
				/* VCState = No VC Selected or Proximity Failed, use DummyMACKey(Random AES128 Key) for MACing */
				case VC_NOT_SELECTED:
				case VC_PROXIMITYFAILED:
					/* Generating a random DummyMACKey of 16 bytes length */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoRng_Rnd(pDataParams->pCryptoRngDataParams,
						PH_CRYPTOSYM_AES128_KEY_SIZE, aKey));
					break;

				/* VCState = Proximity Check/Not Authenticated/D40 auth/ISO auth/EV1 auth without AES key,
				 * use VCProximityKey(CardKeyNo = 0x21) for MACing
				 */
				case VC_PROXIMITYCHECK:
				case VC_DF_NOT_AUTH:
				case VC_DF_AUTH_D40:
				case VC_DF_AUTH_ISO:
					/* Get VC ProximityCheckKey (CardKeyNo = 0x21) */
					PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(pDataParams->pKeyStoreDataParams,
						wKeyNumber, wKeyVersion, (uint8)sizeof(aKey), aKey, &wKeyType));

					/* Check key type */
					if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
					{
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
					}
					break;

				/* VCState = Authenticated(AES or EV2) with AES keys, use Card Type Specific SessionAuthMACKey */
				case VC_DF_AUTH_EV2:
				case VC_DF_AUTH_AES:
				case VC_MFP_AUTH_AES_SL1:
				case VC_MFP_AUTH_AES_SL3:
					(void)memcpy(aKey, pDataParams->bSessionAuthMACKey, 16);
					break;
				default:
					break;
			}

			/* backup the current key */
			(void)memcpy(Key_bak, ((phCryptoSym_Sw_DataParams_t *)pDataParams->pCryptoDataParams)->pKey, PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE);

			/* Load the Key obtained from the switch cases above */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
				pDataParams->pCryptoDataParams,
				aKey,
				PH_CRYPTOSYM_KEY_TYPE_AES128));

			/* Store the IV to be used for encryption later */
			if(strlen((char*)(pCryptoDataParamsTmp->pIV)) != 0u)
			{
				(void)memcpy(bIv_bak, pCryptoDataParamsTmp->pIV, PH_CRYPTOSYM_AES128_KEY_SIZE);
			}

			/* Reset IV for the first crypto operation */
			(void)memset(pCryptoDataParamsTmp->pIV, 0x00, PH_CRYPTOSYM_AES128_KEY_SIZE);

			/* Load Iv.*/
			status = phCryptoSym_LoadIv(
				pDataParams->pCryptoDataParams,
				pCryptoDataParamsTmp->pIV,
				PH_CRYPTOSYM_AES128_KEY_SIZE);
			if(status != PH_ERR_SUCCESS)
			{
				return status;
			}

			/* CMAC with Padding */
			/* mac calculation: CMAC(CMD || PPS1 || (RndRC1 || ... || RndRC16)) */
			status = phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				aTmpBuf,
				((uint16)aTmpBufLen + (PHAL_VCA_PC_RND_LEN_NEW * 2U)),
				bMac,
				&bMacLength);
			if(status != PH_ERR_SUCCESS)
			{
				/* Load back up Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParams,
					bIv_bak,
					PH_CRYPTOSYM_AES128_KEY_SIZE));
				return status;
			}

			/* perform MAC truncation */
			phalVca_Sw_Int_TruncateMac(bMac, bMac);

			/* Before sending the VPC command, set the PC state as PC_VPC_IN_PROGRESS */
			pDataParams->ePCState = PC_VPC_IN_PROGRESS;

			/* Framing the buffer again */
			bCmd[0] = PHAL_VCA_CMD_VPC;

			/* Append the MAC before exchanging the frame */
			(void)memcpy(&bCmd[1], bMac,PHAL_VCA_TRUNCATED_MAC_SIZE);
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_SW_STATE_CMD1:
			/* Check for ISO Wrapped Mode */
			if(0U != (pDataParams->bWrappedMode))
			{
				PH_CHECK_INPROCESS_FCT(status, phalVca_Int_SendISOWrappedCmd(
					pDataParams,
					bCmd,
					PHAL_VCA_TRUNCATED_MAC_SIZE,    /* Lc Value */
					&pResponseTmp,
					&wRxLength
					));
				gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
				if(wRxLength >= 2U)
				{
					/* Store the SW2 of response code. This is required for response MAC calculation */
					bRespCode = pResponseTmp[wRxLength - 1u];
					status = phalVca_Int_ComputeErrorResponse_Extended(pDataParams, bRespCode);
					if(status != PH_ERR_SUCCESS)
					{
						/* Load back up Iv */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
							pDataParams->pCryptoDataParams,
							bIv_bak,
							PH_CRYPTOSYM_AES128_KEY_SIZE));
						return status;
					}
				}
				else
				{
					/* Load back up Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParams,
						bIv_bak,
						PH_CRYPTOSYM_AES128_KEY_SIZE));
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
				}
			}
			else
			{
				/* exchange frame in native mode */
				PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_DEFAULT,
					bCmd,
					1U + PHAL_VCA_TRUNCATED_MAC_SIZE,
					&pResponseTmp,
					&wRxLength));
				gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
				if(status != PH_ERR_SUCCESS)
				{
					/* Load back up Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParams,
						bIv_bak,
						PH_CRYPTOSYM_AES128_KEY_SIZE));
					return status;
				}

				/* Store the response code. This is required for response MAC calculation */
				bRespCode = pResponseTmp[0];

				/* Computing the error response on SW1 */
				status = phalVca_Int_ComputeErrorResponse_Extended(pDataParams, pResponseTmp[0]);
				if(status != PH_ERR_SUCCESS)
				{
					/* Load back up Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParams,
						bIv_bak,
						PH_CRYPTOSYM_AES128_KEY_SIZE));
					return status;
				}
			}
			/* VPC command is a success or a failure, set the PC state back to PC_NO_PCHK_IN_PROGRESS */
			pDataParams->ePCState = PC_NO_PCHK_IN_PROGRESS;

			/* Reset IV for the first crypto operation */
			(void)memset(pCryptoDataParamsTmp->pIV, 0x00, PH_CRYPTOSYM_AES128_KEY_SIZE);

			 /* Load Iv.*/
			status = phCryptoSym_LoadIv(
				pDataParams->pCryptoDataParams,
				pCryptoDataParamsTmp->pIV,
				PH_CRYPTOSYM_AES128_KEY_SIZE);
			if(status != PH_ERR_SUCCESS)
			{
				return status;
			}

			/* Calculate MAC this time with status code pResponse[0] for native response to match with PICC calculations */
			aTmpBuf[0] = bRespCode;

			/* Computing the MAC again for alignment with the computation of PICC */
			(void) phCryptoSym_CalculateMac(
				pDataParams->pCryptoDataParams,
				PH_CRYPTOSYM_MAC_MODE_CMAC,
				aTmpBuf,
				((uint16)aTmpBufLen + (PHAL_VCA_PC_RND_LEN_NEW * 2U)),
				bMac,
				&bMacLength);

			/* perform MAC truncation */
			phalVca_Sw_Int_TruncateMac(bMac, bMac);

			/* Load back up Iv */
			PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
				pDataParams->pCryptoDataParams,
				bIv_bak,
				PH_CRYPTOSYM_AES128_KEY_SIZE));

			/* restore backup key */
			(void)memcpy(((phCryptoSym_Sw_DataParams_t *)pDataParams->pCryptoDataParams)->pKey, Key_bak, PH_CRYPTOSYM_SW_MAX_BLOCK_SIZE);

			/* Compare MAC */
			if (memcmp(bMac, (((pDataParams->bWrappedMode) != 0U) ? &pResponseTmp[0] : &pResponseTmp[1]), PHAL_VCA_TRUNCATED_MAC_SIZE) != 0)
			{
				return PH_ADD_COMPCODE_FIXED(PHAL_VCA_ERR_AUTH, PH_COMP_AL_VCA);
			}
			break;
	}


	return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheckUtility(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdMac, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdResp)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aTmpBuf[1];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;

	switch(gbVcaCmdState)
	{
		case PHAL_VCA_SW_STATE_IDLE:
			/* Validating the Input MAC */
			if(pCmdMac == NULL)
			{
				 return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
			}
			/* Framing the buffer(Cmd code and Input MAC) and sending to PICC */
			aTmpBuf[0] = PHAL_VCA_CMD_VPC;

			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				aTmpBuf,
				1,
				&pResponse,
				&wRxLength));
			PH_BREAK_ON_FAILURE(statusTmp);
			gbVcaCmdState = PHAL_VCA_SW_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_SW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				pCmdMac,
				8,
				&pResponse,
				&wRxLength));
			gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
			PH_BREAK_ON_FAILURE(statusTmp);
			/* check response */
			PH_CHECK_FAILURE_FCT(statusTmp, phalVca_Int_ComputeErrorResponse_Extended(pDataParams, pResponse[0]));
			/* Copy the response MAC to pCmdResp */
			if(memcpy(pCmdResp, &pResponse[1], 8) == NULL)
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
			}
			break;
	}

	gbVcaCmdState = PHAL_VCA_SW_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetConfig(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue)
{
	switch (wConfig)
	{
		case PHAL_VCA_ADDITIONAL_INFO:
			pDataParams->wAdditionalInfo = wValue;
			break;
		case PHAL_VCA_WRAPPED_MODE:
			pDataParams->bWrappedMode = (uint8)wValue;
			break;
		case PHAL_VCA_TIMING_MODE:
			pDataParams->bOption = (uint8)wValue;
			break;
		case PHAL_VCA_PC_LOWER_THRESHOLD:
			pDataParams->bLowerBoundThreshold = (uint8)wValue;
			break;
		case PHAL_VCA_PC_EXTENDED_APDU:
			pDataParams->bExtendedLenApdu = (uint8)wValue;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_VCA);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_GetConfig(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
	switch (wConfig)
	{
		case PHAL_VCA_ADDITIONAL_INFO:
			*pValue = pDataParams->wAdditionalInfo;
			break;
		case PHAL_VCA_WRAPPED_MODE:
			*pValue = pDataParams->bWrappedMode;
			break;
		case PHAL_VCA_TIMING_MODE:
			*pValue = pDataParams->bOption;
			break;
		case PHAL_VCA_PC_LOWER_THRESHOLD:
			*pValue = pDataParams->bLowerBoundThreshold;
			break;
		case PHAL_VCA_PC_EXTENDED_APDU:
			*pValue = pDataParams->bExtendedLenApdu;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_AL_VCA);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetSessionKeyUtility(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey, VAR(uint8, ANFCRL_VAR) bAuthMode)
{
	/*
	 * Handle all the cases as mentioned below before performing PC operations
	 * case-1: VCState = Authenticated, Session keys from DesfireEV2 should be used for MAC calculations
	 * case-2: VCState = Proximity Check or Not Authenticated, VC Proximity Key should be used for MAC calculations
	 * case-3: VCState = No VC Selected, DummyMACKey of type AES 128 should be used for MAC calculations.
	 */
	/* Handling Case-1. First need to get the card auth type(AES, DES, ISO, EV2) and set the VC state based on the Auth Mode */
	switch(bAuthMode)
	{
#ifdef NXPBUILD__PHAL_MFDFEVX_SW
	case PHAL_MFDFEVX_AUTHENTICATE:
		pDataParams->eVCState = VC_DF_AUTH_D40;
		break;

	case PHAL_MFDFEVX_AUTHENTICATEISO:
		pDataParams->eVCState = VC_DF_AUTH_ISO;
		break;

	case PHAL_MFDFEVX_AUTHENTICATEAES:
		pDataParams->eVCState = VC_DF_AUTH_AES;
		/* Set the session key (since session key is AES) to the VCA structure parameter */
		(void)memcpy(pDataParams->bSessionAuthMACKey, pSessionKey, sizeof(pDataParams->bSessionAuthMACKey));
		break;

	case PHAL_MFDFEVX_AUTHENTICATEEV2:
		pDataParams->eVCState = VC_DF_AUTH_EV2;
		/* Set the session key (since session key is AES) to the VCA structure parameter */
		(void)memcpy(pDataParams->bSessionAuthMACKey, pSessionKey, sizeof(pDataParams->bSessionAuthMACKey));
		break;

	case PHAL_MFDFEVX_NOT_AUTHENTICATED:
		pDataParams->eVCState = VC_DF_NOT_AUTH;
		break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */
#ifdef NXPBUILD__PHAL_MFPEVX_SW
	case PHAL_MFPEVX_SL1_MFP_AUTHENTICATED:
		pDataParams->eVCState = VC_MFP_AUTH_AES_SL1;

		/* Set the session key (since session key is AES) to the VCA structure parameter */
		(void)memcpy(pDataParams->bSessionAuthMACKey, pSessionKey, sizeof(pDataParams->bSessionAuthMACKey));
		break;

	case PHAL_MFPEVX_SL3_MFP_AUTHENTICATED:
		pDataParams->eVCState = VC_MFP_AUTH_AES_SL3;

		/* Set the session key (since session key is AES) to the VCA structure parameter */
		(void)memcpy(pDataParams->bSessionAuthMACKey, pSessionKey, sizeof(pDataParams->bSessionAuthMACKey));
		break;

	case PHAL_MFPEVX_NOTAUTHENTICATED:
	case PHAL_MFPEVX_NOT_AUTHENTICATED_L3:
	case PHAL_MFPEVX_NOT_AUTHENTICATED_L4:
		pDataParams->eVCState = VC_DF_NOT_AUTH;
		break;
#endif /* NXPBUILD__PHAL_MFPEVX_SW */
	default:
		pDataParams->eVCState = VC_NOT_SELECTED;
		break;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetApplicationType(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlDataParams)
{
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pAlDataParams);

	pDataParams->pAlDataParams = pAlDataParams;

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_DecryptResponse(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRandChal, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCData)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aKey[PH_CRYPTOSYM_AES128_KEY_SIZE];
  uint8     PH_MEMLOC_REM bInDataLen = (uint8) strlen((char*)pInData);
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIv[16];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIv_bak[PH_CRYPTOSYM_AES128_KEY_SIZE];
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;
  P2VAR(phCryptoSym_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pCryptoDataParamsTmp = NULL;

	/* Set the buffer to 0: MISRA warning */
	(void)memset(bIv_bak, 0x00, PH_CRYPTOSYM_AES128_KEY_SIZE);

	/* Check for pointer to Input data */
	if(bInDataLen != PHAL_VCA_AUTH_RND_LEN)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
	}
	/* The in out data contains 4 bytes header + 32 bytes of Data(16B challenge & 16B payload */
	/* Store 16 bytes of the Input data (Response of IsoSelect) to Random challenge(RndChal) */
	if(memcpy(pRandChal, &pInData[4], 16) == NULL)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
	}

	/* Get Select ENC Key */
	PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
		pDataParams->pKeyStoreDataParams,
		wKeyNo,
		wKeyVersion,
		(uint8)(sizeof(aKey)),
		aKey,
		&wKeyType));

	/* Check key type */
	if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
	}

	/* Load Select ENC Key */
	PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
		pDataParams->pCryptoDataParams,
		aKey,
		PH_CRYPTOSYM_KEY_TYPE_AES128));

	/* Store the IV to be used for Crypto operations later */
	pCryptoDataParamsTmp = (phCryptoSym_Sw_DataParams_t *)pDataParams->pCryptoDataParams;

    if(strlen((char*)(pCryptoDataParamsTmp->pIV)) != 0U)
	{
		(void)memcpy(bIv_bak, pCryptoDataParamsTmp->pIV, PH_CRYPTOSYM_AES128_KEY_SIZE);
	}

	/* Reset IV for the first crypto operation */
	(void)memset(bIv, 0x00, 16);

	/* Load zero Iv.*/
	PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
		pDataParams->pCryptoDataParams,
		bIv,
		16));

	/* Decryption of the response data received from IsoSelect */
	statusTmp = phCryptoSym_Decrypt(
		pDataParams->pCryptoDataParams,
		PH_CRYPTOSYM_CIPHER_MODE_CBC,
		&pInData[20],
		16,
		pVCData);
	if(statusTmp != PH_ERR_SUCCESS)
	{
		/* Load back up Iv */
		PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
			pDataParams->pCryptoDataParams,
			bIv_bak,
			PH_CRYPTOSYM_AES128_KEY_SIZE));
		return statusTmp;
	}
	/* Decrypted VCData is not plain text. It needs to be XORed with RndChal to obtain plain VCData */
	for(bIndex =0; bIndex < 16U; bIndex++)
	{
		pVCData[bIndex] = (pVCData[bIndex] ^ pRandChal[bIndex]);
	}
	/* Store the decrypted VCData to pCardData parameter of VCA structure for futher access to info, PDCap.1 and VCUID */
	if(memcpy(pDataParams->pCardTable->pCardData, pVCData, 16) == NULL)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
	}

	return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Int_ResolveValidIndex(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wIidIndex, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValidIndex)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCurrentValidIndex = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDummyValidIndex = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDummyFoundIndex = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM bFoundIndex = pDataParams->wCurrentCardTablePos;

	for (bIndex = 0; bIndex < pDataParams->wCurrentCardTablePos; ++bIndex)
	{
		if (pDataParams->pCardTable[bIndex].bValid == 0xFFU)
		{
			bDummyFoundIndex = bIndex;
			bDummyValidIndex++;
		}
		else
		{
			if (bCurrentValidIndex == wIidIndex)
			{
				bFoundIndex = bIndex;
			}
			else
			{
				bDummyFoundIndex = bIndex;
			}
			bCurrentValidIndex++;
		}
	}

	/* Check if the index is valid */
	if (bFoundIndex >= pDataParams->wCurrentCardTablePos)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
	}

	*pValidIndex = bFoundIndex;

	PH_UNUSED_VARIABLE(bDummyFoundIndex);
	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(void, ANFCRL_CODE) phalVca_Sw_Int_TruncateMac(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTruncatedMac)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;

	/* truncated MAC = [1, 3, 5, 7, 9, 11, 13, 15] of the input Mac */
	for (bIndex = 0; bIndex < PHAL_VCA_TRUNCATED_MAC_SIZE; ++bIndex)
	{
		pTruncatedMac[bIndex] = pMac[1U + (bIndex << 1U)];
	}
}

#endif /* NXPBUILD__PH_CRYPTOSYM */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_VCA_SW */

#ifdef __cplusplus
}
#endif
