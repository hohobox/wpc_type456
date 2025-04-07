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
*   @file    phalVca_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca_Int - AL API usage in common use cases.
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

#include <ph_Status.h>
#include <phpalMifare.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHAL_VCA
#include <phalVca.h>
#include "phalVca_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalVca_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALVCA_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALVCA_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and PHALVCA_INT.h header file are of the same vendor */
#if (PHALVCA_INT_VENDOR_ID_C != PHALVCA_INT_VENDOR_ID)
    #error "phalVca_Int.c and phalVca_Int.h have different vendor ids"
#endif
/* Check if current file and PHALVCA_INT.h header file are of the same Autosar version */
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION_C    != PHALVCA_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHALVCA_INT_AR_RELEASE_MINOR_VERSION_C    != PHALVCA_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHALVCA_INT_AR_RELEASE_REVISION_VERSION_C != PHALVCA_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca_Int.c and phalVca_Int.h are different"
#endif
/* Check if current file and PHALVCA_INT.h header file are of the same Software version */
#if ((PHALVCA_INT_SW_MAJOR_VERSION_C != PHALVCA_INT_SW_MAJOR_VERSION) || \
     (PHALVCA_INT_SW_MINOR_VERSION_C != PHALVCA_INT_SW_MINOR_VERSION) || \
     (PHALVCA_INT_SW_PATCH_VERSION_C != PHALVCA_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca_Int.c and phalVca_Int.h are different"
#endif
#endif /* NXPBUILD__PHAL_VCA */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA
#define PHAL_VCA_STATE_IDLE		(0u)
#define PHAL_VCA_STATE_CMD1		(1u)
#define PHAL_VCA_STATE_CMD2		(2u)
#define PHAL_VCA_STATE_CMD3		(3u)
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
#define ANFCRL_START_SEC_CODE
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ComputeErrorResponse(
	VAR(uint16, ANFCRL_VAR) wNumBytesReceived, 
	VAR(uint8, ANFCRL_VAR) bStatus)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* validate received response */
	if (wNumBytesReceived > 1U)
	{
		if (bStatus != PHAL_VCA_RESP_ACK_ISO4)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
		}

		/* proper error response */
		return PH_ERR_SUCCESS;
	}
	else if (wNumBytesReceived == 1U)
	{
		switch (bStatus)
		{
			case PHAL_VCA_RESP_ACK_ISO4:

				status = PH_ERR_SUCCESS;
				break;

			case PHAL_VCA_RESP_ERR_CMD_INVALID:

				status = PHAL_VCA_ERR_CMD_INVALID;
				break;

			case PHAL_VCA_RESP_ERR_FORMAT:

				status = PHAL_VCA_ERR_FORMAT;
				break;

			case PHAL_VCA_RESP_ERR_GEN:

				status = PHAL_VCA_ERR_GEN;
				break;

			case PHAL_VCA_RESP_ERR_CMD_OVERFLOW:

				status = PHAL_VCA_ERR_CMD_OVERFLOW;
				break;
			default:

				status = PH_ERR_PROTOCOL_ERROR;
				break;
		}

		return PH_ADD_COMPCODE(status, PH_COMP_AL_VCA);
	}
	/* Invalid error response */
	else
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
	}
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ComputeErrorResponse_Extended(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wStatus)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
	switch (wStatus)
	{
		case PHAL_VCA_RESP_ACK_ISO4:
		case PHAL_VCA_ISO7816_SUCCESS:
		case PHAL_VCA_ISO7816_PC_SUCCESS:
			status = PH_ERR_SUCCESS;
			break;
		case PHAL_VCA_RESP_ERR_CMD_INVALID:
			status = PHAL_VCA_ERR_CMD_INVALID;
			break;
		case PHAL_VCA_RESP_ERR_FORMAT:
			status = PHAL_VCA_ERR_FORMAT;
			break;
		case PHAL_VCA_RESP_ERR_GEN:
			status = PHAL_VCA_ERR_GEN;
			break;
		case PHAL_VCA_RESP_ERR_CMD_OVERFLOW:
			status = PHAL_VCA_ERR_CMD_OVERFLOW;
			break;
		case PHAL_VCA_RESP_ERR_COMMAND_ABORTED:
			status = PHAL_VCA_ERR_COMMAND_ABORTED;
			break;
		case PHAL_VCA_ISO7816_ERR_WRONG_LENGTH:
		case PHAL_VCA_ISO7816_ERR_WRONG_LE:
		case PHAL_VCA_ISO7816_ERR_FILE_NOT_FOUND:
		case PHAL_VCA_ISO7816_ERR_WRONG_PARAMS:
		case PHAL_VCA_ISO7816_ERR_WRONG_LC:
		case PHAL_VCA_ISO7816_ERR_NO_PRECISE_DIAGNOSTICS:
		case PHAL_VCA_ISO7816_ERR_EOF_REACHED:
		case PHAL_VCA_ISO7816_ERR_FILE_ACCESS:
		case PHAL_VCA_ISO7816_ERR_FILE_EMPTY:
		case PHAL_VCA_ISO7816_ERR_MEMORY_FAILURE:
		case PHAL_VCA_ISO7816_ERR_INCORRECT_PARAMS:
		case PHAL_VCA_ISO7816_ERR_WRONG_CLA:
		case PHAL_VCA_ISO7816_ERR_UNSUPPORTED_INS:
			status = PHAL_VCA_ERR_7816_GEN_ERROR;
			/* Set the error code to VC param structure*/
			PH_CHECK_SUCCESS_FCT(statusTmp,
					phalVca_SetConfig( pDataParams, PHAL_VCA_ADDITIONAL_INFO, wStatus));
			break;
		default:
			status = PH_ERR_PROTOCOL_ERROR;
			break;
	}
	return PH_ADD_COMPCODE(status, PH_COMP_AL_VCA);
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_PrepareProximityCheck(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd[1];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;

	/* command code */
	bCmd[0] = PHAL_VCA_CMD_PPC;

	/* command exchange */
	PH_CHECK_INPROCESS_FCT(statusTmp,
			phpalMifare_ExchangeL4( pPalMifareDataParams, PH_EXCHANGE_DEFAULT, bCmd, 1, &pResponse, &wRxLength));
	PH_CHECK_SUCCESS(statusTmp);
	/* check response */
	if (wRxLength == 1U)
	{
		PH_CHECK_SUCCESS_FCT(statusTmp, phalVca_Int_ComputeErrorResponse(wRxLength, pResponse[0]));
	}
	else
	{
		statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFP);
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_PrepareProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponseTmp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd[1] =
	{ PHAL_VCA_CMD_PPC };
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bOffset = 0U;
  static VAR(uint8, ANFCRL_VAR) bProximityCheckNewState = PHAL_VCA_STATE_IDLE;
	switch (bProximityCheckNewState)
	{
		case PHAL_VCA_STATE_IDLE:
			/* Check for ISO Wrapped Mode */
			if (pDataParams->bWrappedMode != 0U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phalVca_Int_SendISOWrappedCmd(pDataParams, bCmd, 0x00, /* Lc Value */
						&pResponseTmp, &wRxLength));
				PH_BREAK_ON_FAILURE(statusTmp);

				if (wRxLength >= 2U)
				{
					PH_CHECK_SUCCESS_FCT(statusTmp,
							phalVca_Int_ComputeErrorResponse_Extended(pDataParams,
									pResponseTmp[wRxLength - 1U]));
				}
				else
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
				}
				/* Adjusting the response length i.e. removing the consideration of response data */
				wRxLength -= 2U;
			}
			else
			{
				bProximityCheckNewState = PHAL_VCA_STATE_CMD1;
			}
			/* no break*/
		case PHAL_VCA_STATE_CMD1:
			if (pDataParams->bWrappedMode == 0u)
			{
				/* Command exchange */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phpalMifare_ExchangeL4( pDataParams->pPalMifareDataParams, PH_EXCHANGE_DEFAULT, bCmd, 1, &pResponseTmp, &wRxLength));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* Computing the error response on SW1 */
				PH_CHECK_FAILURE_FCT(statusTmp,
						phalVca_Int_ComputeErrorResponse_Extended(pDataParams, pResponseTmp[0]));

				/* Increment the Index to point the response data */
				pResponseTmp++;

				/* Adjusting the response length i.e. removing the consideration of response data */
				wRxLength--;
			}

			/* Check and save the contents of response data */
			if (wRxLength > 2U)
			{
				/* Save Option from response data */
				*pOption = pResponseTmp[bOffset++];

				/* Save Published Response Time from response data */
				pPubRespTime[0] = pResponseTmp[bOffset++];
				pPubRespTime[1] = pResponseTmp[bOffset++];

				/* Save PPS from response data */
				if ((*pOption & 0x01U) != 0U)
				{
					*pResponse = pResponseTmp[bOffset];
					*pRespLen = 1;
				}

				/* Save ActBitRate from response data */
				if ((*pOption & 0x02U) != 0U)
				{
					(void) memcpy(pResponse, &pResponseTmp[bOffset], ((uint32)wRxLength - (uint32)bOffset));
					*pRespLen = wRxLength - (uint16)bOffset;
				}
			}
			else
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
			}
			break;
		default:
			break;

	}
	/* reset state */
	bProximityCheckNewState = PHAL_VCA_STATE_IDLE;

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ProximityCheck(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bNumSteps,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd[1 /* command code */+ 1 /* length */+ 7 /* max RndC length */];
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bPayloadLen = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndCLen = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndRCLen = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM sbNumSteps = 0;
  static VAR(uint8, ANFCRL_VAR) bProximityCheck = PHAL_VCA_STATE_IDLE;

	switch (bProximityCheck)
	{
		case PHAL_VCA_STATE_IDLE:
			sbNumSteps = bNumSteps;
			/* parameter checking */
			if ((sbNumSteps == 0U) || (sbNumSteps > PHAL_VCA_PC_RND_LEN) || (pRndC == NULL)
					|| (pRndRC == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFP);
			}
			bProximityCheck = PHAL_VCA_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_STATE_CMD1:
			/* command code */
			bCmd[0] = PHAL_VCA_CMD_PC;
			if (0U != sbNumSteps)
			{
				/* RndC length */
				if (0U != (sbNumSteps - 1U))
				{
					bPayloadLen = 1;
				}
				else
				{
					bPayloadLen = PHAL_VCA_PC_RND_LEN - bRndCLen;
				}

				/* Length */
				bCmd[1] = bPayloadLen;

				/* RndC */
				(void) memcpy(&bCmd[2], &pRndC[bRndCLen], bPayloadLen);

				/* command exchange */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phpalMifare_ExchangePc( pPalMifareDataParams, PH_EXCHANGE_DEFAULT, bCmd, (uint16)(2U + ((uint16)bPayloadLen)), &pResponse, &wRxLength));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* check response */
				if (wRxLength == (uint16) bPayloadLen)
				{
					/* copy RndR */
					(void) memcpy(&pRndRC[bRndRCLen], pResponse, wRxLength);
					bRndRCLen = bRndRCLen + (uint8) wRxLength;

					/* copy RndC */
					(void) memcpy(&pRndRC[bRndRCLen], &pRndC[bRndCLen], wRxLength);
					bRndRCLen = bRndRCLen + (uint8) wRxLength;
					bRndCLen = bRndCLen + (uint8) wRxLength;
				}
				sbNumSteps--;
				return PH_STATUS_INPROCESS;
			}

			/* We expect to have exactly 7 bytes RndR + 7 bytes RndC */
			if (bRndRCLen != (PHAL_VCA_PC_RND_LEN * 2U))
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFP);
			}
			break;
		default:
			break;
	}
	/* Reset state*/
	bProximityCheck = PHAL_VCA_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bNumSteps,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd[1 /* command code */+ 1 /* length */+ 8 /* max RndC length */];
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bPayloadLen;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndCLen = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRndRCLen = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM sbNumSteps = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValue;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wThresholdTimeUpperLimit;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wThresholdTimeLowerLimit;
  static P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pPalDataParamsTmp = NULL;

  static VAR(uint8, ANFCRL_VAR) bProximityCheck = PHAL_VCA_STATE_IDLE;
	switch (bProximityCheck)
	{
		case PHAL_VCA_STATE_IDLE:
			sbNumSteps = bNumSteps;
			pPalDataParamsTmp = (phpalMifare_Sw_DataParams_t *) pDataParams->pPalMifareDataParams;
			/* parameter checking */
			if ((sbNumSteps == 0U) || (sbNumSteps > PHAL_VCA_PC_RND_LEN_NEW) || (pRndC == NULL)
					|| (pRndRC == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_VCA);
			}

			bProximityCheck = PHAL_VCA_STATE_CMD1;
			/* no break*/
		case PHAL_VCA_STATE_CMD1:
			/* Proximity Check loop */
			if (0U != sbNumSteps)
			{
				/* RndC length */
				if (0U != (sbNumSteps - 1U))
				{
					bPayloadLen = 1;
				}
				else
				{
					bPayloadLen = PHAL_VCA_PC_RND_LEN_NEW - bRndCLen;
				}

				/* Get the bOption value for the checking the timing measurement ON/OFF */
				PH_CHECK_FAILURE_FCT(statusTmp,
						phalVca_GetConfig(pDataParams, PHAL_VCA_TIMING_MODE, &wValue));
				if (0U != (wValue & 0x01U))
				{
					/* Start collecting the RC timeout */
					PH_CHECK_FAILURE_FCT(statusTmp,
							phhalHw_SetConfig(pPalDataParamsTmp->pHalDataParams, PHHAL_HW_CONFIG_TIMING_MODE, PHHAL_HW_TIMING_MODE_FDT));
				}
				bProximityCheck = PHAL_VCA_STATE_CMD2;
				return PH_STATUS_INPROCESS;
			}
			bProximityCheck = PHAL_VCA_STATE_CMD3;
			break;
		case PHAL_VCA_STATE_CMD2:
			/* command code */
			bCmd[0] = PHAL_VCA_CMD_PC;
			/* Length */
			bCmd[1] = bPayloadLen;

			/* RndC */
			(void) memcpy(&bCmd[2], &pRndC[bRndCLen], bPayloadLen);
			/* Check for ISO Wrapped Mode */
			if (0U != (pDataParams->bWrappedMode))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phalVca_Int_SendISOWrappedCmd(pDataParams, bCmd,
								(uint8 )(1U + bPayloadLen), /* bPayloadLen + RndC */
								&pResponse, &wRxLength));
				PH_BREAK_ON_FAILURE(statusTmp);
				if (wRxLength >= 2U)
				{
					PH_CHECK_FAILURE_FCT(statusTmp,
							phalVca_Int_ComputeErrorResponse_Extended(pDataParams,
									pResponse[wRxLength - 1u]));
				}
				else
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
					break;
				}
				/* Decrement wRxLength by 2 i.e. removing status word from pResponse */
				wRxLength -= 2u;
			}
			else
			{
				/* command exchange */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phpalMifare_ExchangeL4( pDataParams->pPalMifareDataParams, PH_EXCHANGE_DEFAULT, bCmd, (uint16)(2U + ((uint16)bPayloadLen)), /* (INS + bPayloadLen) + RndC */
						&pResponse, &wRxLength));
				PH_BREAK_ON_FAILURE(statusTmp);

				/*
				 * Response validation should not be performed in case if the length is
				 *      1 byte  : One byte can be either a valid response or a error code which is difficult to identify
				 *      0 byte  : If there is response, the passed value will be any number from the pointer which will
				 *                result in false errors.
				 */
				if ((wRxLength != bPayloadLen) && (bPayloadLen != 0U) && (bPayloadLen != 1U))
				{
					PH_CHECK_FAILURE_FCT(statusTmp,
							phalVca_Int_ComputeErrorResponse_Extended(pDataParams,
									pResponse[wRxLength - 1U]));
				}
			}

			/* check response */
			if (wRxLength == (uint16) bPayloadLen)
			{
				/* copy RndR */
				(void) memcpy(&pRndRC[bRndRCLen], pResponse, wRxLength);
				bRndRCLen = bRndRCLen + (uint8) wRxLength;

				/* copy RndC */
				(void) memcpy(&pRndRC[bRndRCLen], &pRndC[bRndCLen], wRxLength);
				bRndRCLen = bRndRCLen + (uint8) wRxLength;
				bRndCLen = bRndCLen + (uint8) wRxLength;
			}

			/* Get the bOption value for the checking the timing measurement ON/OFF */
			PH_CHECK_FAILURE_FCT(statusTmp,
					phalVca_GetConfig(pDataParams, PHAL_VCA_TIMING_MODE, &wValue))
			;
			if (0U != (wValue & 0x01U))
			{
				/* Compute threshold time from PubRespTime. Threshold time = pubRespTime + 10% of pubRespTime */
				wThresholdTimeUpperLimit = pPubRespTime[0U];
				wThresholdTimeUpperLimit <<= 8U;
				wThresholdTimeUpperLimit |= pPubRespTime[1U];

				/* As per the ref arch V0.17, the threshold time should not be 20% beyond the Lower bound of PubResp Time. */
				wThresholdTimeLowerLimit = (wThresholdTimeUpperLimit * 80U) / 100U;

				/* Get the last command execution time */
				PH_CHECK_FAILURE_FCT(statusTmp,
						phhalHw_GetConfig(pPalDataParamsTmp->pHalDataParams, PHHAL_HW_CONFIG_TIMING_US, &wValue));

				/* If the response is not received within the threshold time, return internal error */
				if ((wValue > wThresholdTimeUpperLimit) || (wValue < wThresholdTimeLowerLimit))
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_VCA);
					break;
				}
			}
			sbNumSteps--;
			bProximityCheck = PHAL_VCA_STATE_CMD1;
			return PH_STATUS_INPROCESS;
		case PHAL_VCA_STATE_CMD3:
			/* We expect to have exactly 8 bytes RndR + 8 bytes RndC */
			if (bRndRCLen != (PHAL_VCA_PC_RND_LEN_NEW * 2U))
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_VCA);
			}
			break;
	}
	/* Reset state */
	bProximityCheck = PHAL_VCA_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_SendISOWrappedCmd(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff,
    VAR(uint8, ANFCRL_VAR) bLc, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bApduLen = 4U; /* Initializing with 4 since Length of the Data(Lc) starts from 4th element of pApdu[] */
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[8] =
	{ 0x90 /* CLS */, 0x00, 0x00, 0x00, 0x00 /* Lc */, 0x00, 0x00 /*  Lc for Extended Length */,
			0x00 /* Le */};

  static VAR(uint8, ANFCRL_VAR) bProximityCheck = PHAL_VCA_STATE_IDLE;

	switch (bProximityCheck)
	{
		case PHAL_VCA_STATE_IDLE:
			/* Check for permissible CmdBuff size */
			if (bLc > PHAL_VCA_MAXWRAPPEDAPDU_SIZE)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_VCA);
			}
			bProximityCheck = PHAL_VCA_STATE_CMD1;
			/*no break*/
		case PHAL_VCA_STATE_CMD1:
			pApdu[1] = pSendBuff[0]; /* Proximity Check Command Code. */
			switch (pApdu[1])
			{
				case PHAL_VCA_CMD_PPC:
					pApdu[4] = 0x00; /* These bytes will be treated as Le */
					pApdu[5] = 0x00; /* For extended length APDU support */
					/* Transmit CLS INS P1 P2 Lc(not Lc for PPC) as buffer first */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phpalMifare_ExchangeL4( pDataParams->pPalMifareDataParams, PH_EXCHANGE_DEFAULT, pApdu, (uint16)((pDataParams->bExtendedLenApdu != 0U) ? 7U : 5U), /* 2 bytes Le should be passed in case of Extended Length APDU since Lc field is not present */
							pResponse, pRxlen ));
					PH_BREAK_ON_FAILURE(statusTmp);
					break;
				case PHAL_VCA_CMD_PC:
				case PHAL_VCA_CMD_VPC:

					/* To Note: Extended APDU will be used,
					 *  When user forces the 'length' to be sent as Extended length APDU. */
					if (pDataParams->bExtendedLenApdu == 0U)
					{
						/* Encode 'Length' in Short APDU format */
						pApdu[bApduLen++] = (uint8) bLc; /* Set Data Length. */
					}
					else
					{
						/* Encode 'Length' in extended Length format */
						pApdu[bApduLen++] = 0x00;
						pApdu[bApduLen++] = 0x00;
						pApdu[bApduLen++] = (uint8) bLc; /* Set Data Length. */
					}
					/* Transmit CLS INS P1 P2 Lc as buffer first */
					PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
							pDataParams->pPalMifareDataParams,
							PH_EXCHANGE_BUFFER_FIRST,
							pApdu,
							bApduLen,
							pResponse,
							pRxlen ));
					PH_BREAK_ON_FAILURE(statusTmp);
					/* Check for Lc value */
					if (bLc > 0U)
					{
						bProximityCheck = PHAL_VCA_STATE_CMD2;
						return PH_STATUS_INPROCESS;
					}
					bProximityCheck = PHAL_VCA_STATE_CMD3;
					return PH_STATUS_INPROCESS;
				default:
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AL_VCA);
					break;
			}
			break;
		case PHAL_VCA_STATE_CMD2:
			/* Transmit data as continued buffer */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT,
					&pSendBuff[1],
					bLc,
					pResponse,
					pRxlen ));
			PH_BREAK_ON_FAILURE(statusTmp);
			bProximityCheck = PHAL_VCA_STATE_CMD3;
			/* no break */
		case PHAL_VCA_STATE_CMD3:
			/* Resetting bApduLen for further use in case of Le */
			bApduLen = 0;
			if (pDataParams->bExtendedLenApdu == 0U)
			{
				/* Encode 'Length' in Short APDU format */
				pApdu[bApduLen++] = 0x00; /* Set the expected data length as full. */
			}
			else
			{
				/* Encode 'Length' in extended Length format */
				pApdu[bApduLen++] = 0x00;
				pApdu[bApduLen++] = 0x00; /* Set the expected data length as full. */
			}
			/* Transmit Le as buffer Last */
			PH_CHECK_INPROCESS_FCT(statusTmp,
					phpalMifare_ExchangeL4( pDataParams->pPalMifareDataParams, PH_EXCHANGE_BUFFER_LAST, pApdu, bApduLen, pResponse, pRxlen ));
			PH_BREAK_ON_FAILURE(statusTmp);
			break;
		default:
			break;
	}

	/*reset state */
	bProximityCheck = PHAL_VCA_STATE_IDLE;

	return statusTmp;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHALVCA_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_VCA */
#ifdef __cplusplus
}
#endif
