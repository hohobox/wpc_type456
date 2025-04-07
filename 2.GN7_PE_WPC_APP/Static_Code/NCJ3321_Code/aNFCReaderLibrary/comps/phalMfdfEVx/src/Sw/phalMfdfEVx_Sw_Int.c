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
*   @file    phalMfdfEVx_Sw_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx_Sw_Int - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdfEVx MIFARE DESFire EVx
*   @ingroup phalApplication
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
#include <phpalI14443p4.h>
#include <ph_RefDefs.h>
#include <ph_TypeDefs.h>
#include <phTools.h>
#include <string.h>
#ifdef NXPBUILD__PH_CRYPTOSYM
#include <phCryptoSym.h>
#endif /* NXPBUILD__PH_CRYPTOSYM */
#include <phKeyStore.h>
#include <phTMIUtils.h>
#include <phalVca.h>

#ifdef NXPBUILD__PHAL_MFDFEVX_SW

#include "../phalMfdfEVx_Int.h"
#include "phalMfdfEVx_Sw_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx_Sw_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_SW_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_SW_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_SW_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_SW_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phalMfdfEVx_Sw_Int.h header file are of the same vendor */
#if (PHALMFDFEVX_SW_INT_VENDOR_ID_C != PHALMFDFEVX_SW_INT_VENDOR_ID)
    #error "phalMfdfEVx_Sw_Int.c and phalMfdfEVx_Sw_Int.h have different vendor ids"
#endif
/* Check if current file and phalMfdfEVx_Sw_Int.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION_C    != PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION_C    != PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHALMFDFEVX_SW_INT_AR_RELEASE_REVISION_VERSION_C != PHALMFDFEVX_SW_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdfEVx_Sw_Int.c and phalMfdfEVx_Sw_Int.h are different"
#endif
/* Check if current file and phalMfdfEVx_Sw_Int.h header file are of the same Software version */
#if ((PHALMFDFEVX_SW_INT_SW_MAJOR_VERSION_C != PHALMFDFEVX_SW_INT_SW_MAJOR_VERSION) || \
     (PHALMFDFEVX_SW_INT_SW_MINOR_VERSION_C != PHALMFDFEVX_SW_INT_SW_MINOR_VERSION) || \
     (PHALMFDFEVX_SW_INT_SW_PATCH_VERSION_C != PHALMFDFEVX_SW_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdfEVx_Sw_Int.c and phalMfdfEVx_Sw_Int.h are different"
#endif
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_MFDFEVX_SW

#define PHAL_MFDFEVX_SW_INT_STATE_IDLE  0u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD1  1u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD2  2u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD3  3u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD4  4u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD5  5u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD6  6u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD7  7u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD8  8u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD9  9u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD10  10u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD11  11u
#define PHAL_MFDFEVX_SW_INT_STATE_CMD12  12u

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
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_CardExchange(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wBufferOption, VAR(uint16, ANFCRL_VAR) wTotDataLen,
  VAR(uint8, ANFCRL_VAR) bExchangeLE, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPiccRetCode)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLc = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aLc[1] = { 0x00 };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aLe[1] = { 0x00 };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLcLen = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aISO7816Header[8] = { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00U, 0x00U, 0x00U, 0x00U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bISO7816HeaderLen = 4U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsIsoChainnedCmd = PH_OFF;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLeLen = 0U;
	static VAR(uint8, ANFCRL_VAR) bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bCardExchangeState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			/* Exchange the command in Native format. -------------------------------------------------------------------------- */
			if (0U == (pDataParams->bWrappedMode))
			{
				/* Exchange the data to the card in Native format. */
				PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					wBufferOption,
					pData,
					wDataLen,
					&pResponse,
					&wRespLen));
				PH_CHECK_SUCCESS(wStatus);

				/* Evaluate the response. */
				if ((wBufferOption == PH_EXCHANGE_BUFFER_LAST) || (wBufferOption == PH_EXCHANGE_DEFAULT))
				{
					PH_CHECK_SUCCESS_FCT(wStatus, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, pResponse[0]));

					/* Create memory for updating the response of ISO 14443 format. */
					*ppResponse = &pResponse[1];

					/* Update the response buffer length excluding SW1. */
					*pRespLen = wRespLen - 1U;

					/* Copy the second byte of response (SW2) to RxBuffer */
					*pPiccRetCode = pResponse[0];
				}
				break;
			}
			/* Exchange the command in Iso7816 wrapped format. ----------------------------------------------------------------- */
			else
			{
				if ((wBufferOption == PH_EXCHANGE_BUFFER_FIRST) || (wBufferOption == PH_EXCHANGE_DEFAULT))
				{
					/* Set the flag for data operation commands. */
					bIsIsoChainnedCmd = (uint8) (((pData[0] == PHAL_MFDFEVX_CMD_READ_DATA_ISO) || (pData[0] == PHAL_MFDFEVX_CMD_READ_RECORDS_ISO) ||
						(pData[0] == PHAL_MFDFEVX_CMD_WRITE_DATA_ISO) || (pData[0] == PHAL_MFDFEVX_CMD_WRITE_RECORD_ISO) ||
						(pData[0] == PHAL_MFDFEVX_CMD_UPDATE_RECORD_ISO)) ? PH_ON : PH_OFF);
					PH_UNUSED_VARIABLE(bIsIsoChainnedCmd);
					bLeLen = 1u;

					/* Set the LC information. */
					wLc = (uint16) (wTotDataLen - 1u /* Excluding the command code. */);

					/* Update the command code to Iso7816 header */
					aISO7816Header[1] = pData[0];

					/* Add the ISO 7816 header to layer 4 buffer. */
					PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						PH_EXCHANGE_BUFFER_FIRST,
						&aISO7816Header[0],
						bISO7816HeaderLen,
						NULL,
						NULL));
					PH_CHECK_SUCCESS(wStatus);

					/* Add Lc if available */
					if (wLc != 0U)
					{
						bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
						return PH_STATUS_INPROCESS;
					}
					else
					{
						;
					}
				}
				bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
				return PH_STATUS_INPROCESS;
			}
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			/* Update Lc bytes */
			aLc[bLcLen++] = (uint8) (wLc & 0x00FFU);

			/* Add the Lc to layer 4 buffer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&aLc[0],
				bLcLen,
				NULL,
				NULL));
			PH_BREAK_ON_FAILURE(wStatus);
			bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
			/* Add the data to layer 4 buffer. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&pData[1],  /* Exclude the command code because it is added to INS. */
				(uint16) (wDataLen) - 1u,
				NULL,
				NULL));
			PH_BREAK_ON_FAILURE(wStatus);
			bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
			if (wBufferOption == PH_EXCHANGE_BUFFER_CONT)
			{
				/* Add the data to layer 4 buffer. */
				PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT,
					pData,
					wDataLen,
					NULL,
					NULL));
			}
			PH_BREAK_ON_FAILURE(wStatus);
			bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
			if ((wBufferOption == PH_EXCHANGE_BUFFER_LAST) || (wBufferOption == PH_EXCHANGE_DEFAULT))
			{
				if (wBufferOption == PH_EXCHANGE_BUFFER_LAST)
				{
					/* Add the data to layer 4 buffer. */
					PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						PH_EXCHANGE_BUFFER_CONT,
						pData,
						wDataLen,
						NULL,
						NULL));
				}
				PH_BREAK_ON_FAILURE(wStatus);
				bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
			}
			else
			{
				bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
			}
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
			/* Add Le to L4 buffer and exchange the command. */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				&aLe[0],
				(uint8) ((bExchangeLE != 0U)? bLeLen : 0U),
				&pResponse,
				&wRespLen));

			PH_BREAK_ON_FAILURE(wStatus);

			/* Evaluate the response. */
			PH_CHECK_FAILURE_FCT(wStatus, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, pResponse[wRespLen - 1U]));

			/* Create memory for updating the response of ISO 14443 format. */
			*ppResponse = pResponse;

			/* Update the response buffer length excluding SW1SW2. */
			*pRespLen = wRespLen - 2U;

			/* Copy the second byte of response (SW2) to RxBuffer */
			*pPiccRetCode = pResponse[wRespLen - 1U];
			break;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
			if (wBufferOption == PH_EXCHANGE_RXCHAINING)
			{
				/* Exchange the command */
				PH_CHECK_INPROCESS_FCT(wStatus, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					wBufferOption,
					pData,
					wDataLen,
					&pResponse,
					&wRespLen));

				PH_BREAK_ON_FAILURE(wStatus);

				/* Evaluate the response. */
				PH_CHECK_FAILURE_FCT(wStatus, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, pResponse[wRespLen - 1u]));

				/* Create memory for updating the response of ISO 14443 format. */
				*ppResponse = pResponse;

				/* Update the response buffer length excluding SW1SW2. */
				*pRespLen = wRespLen - 2U;

				/* Copy the second byte of response (SW2) to RxBuffer */
				*pPiccRetCode = pResponse[wRespLen - 1U];
			}
			break;
		default:
			break;
	}

	wLc = 0U;
	bLeLen = 0U;
	bCardExchangeState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GetData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen)
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOption = PH_EXCHANGE_DEFAULT;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0xFF;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[10] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupByte = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNextPos = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupBytes[3] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] = { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00U };
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpByteTemp = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpByteTemp1 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBackUpLen = 0U;
	static VAR(uint16, ANFCRL_VAR) wRxlen = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
	static VAR(uint8, ANFCRL_VAR) bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bGetDataState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			/* Initialize static variable*/
			bBackupByte = 0;
			/* Status and two other bytes to be backed up before getting new frame of data */
			(void)memset(bBackupBytes, 0x00, 3);
			if (0U != (pDataParams->bWrappedMode))
			{
				if (wCmdLen > PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDFEVX);
				}

				pApdu[1] = pSendBuff[0];  /* DESFire command code. */
				/* Encode APDU Length*/
				pApdu[4] = (uint8) wCmdLen - 1u; /* Set APDU Length. */

				if (pApdu[4] != 0x00U)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
								pDataParams->pPalMifareDataParams,
								PH_EXCHANGE_BUFFER_FIRST,
								pApdu,
								PHAL_MFDFEVX_WRAP_HDR_LEN,
								&pRecv,
								&wRxlen
							));
					PH_CHECK_SUCCESS(statusTmp);
					bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
					return PH_STATUS_INPROCESS;
				}
				bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Normal mode */
				if (wCmdLen > PHAL_MFDFEVX_MAXDFAPDU_SIZE)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDFEVX);
				}

				/* Send this on L4 */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					wOption,
					pSendBuff,
					wCmdLen,
					&pRecv,
					&wRxlen
				));
				PH_CHECK_SUCCESS(statusTmp);
			}
			/* Storing the original pointer */
			pRxBuff = pRecv;
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&pSendBuff[1],
				wCmdLen - 1u,
				&pRecv,
				&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
			pApdu[1] = pSendBuff[0];  /* DESFire command code. */
			/* Encode APDU Length*/
			pApdu[4] = (uint8) wCmdLen - 1u; /* Set APDU Length. */

			if (pApdu[4] != 0x00U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					&pApdu[2],
					0x01,
					&pRecv,
					&wRxlen
				));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_DEFAULT,
					pApdu,
					PHAL_MFDFEVX_WRAP_HDR_LEN,
					&pRecv,
					&wRxlen
				));
			}
			/* To handle the case where the card returns only status 91 and returns
			AF in the next frame */
			if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				if ((((pDataParams->bWrappedMode) != 0x00U) && (wRxlen == 2U)) ||
					((((pDataParams->bWrappedMode) == 0x00U)) && (wRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}
				/* One more status byte to read from DesFire */
				bBackUpByteTemp = pRecv[0];
				bBackUpByteTemp1 = pRecv[1];
				wBackUpLen = wRxlen;
				bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			/* Storing the original pointer */
			pRxBuff = pRecv;
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				&pApdu[2],
				0x01,
				&pRecv,
				&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);

			/* Received length can be one or two Ex: 0x91 0xAF */
			if (wRxlen == 2U)
			{
				pRecv[wBackUpLen] = pRecv[0];
				pRecv[wBackUpLen + 1U] = pRecv[1];
				bStatusByte = pRecv[1];
			}
			else if (wRxlen == 1U)
			{
				bStatusByte = pRecv[0];
				pRecv[wBackUpLen] = bStatusByte;
			}
			else
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
				break;
			}

			wRxlen = wBackUpLen + wRxlen;

			/* Set back the backed up bytes */
			pRecv[0] = bBackUpByteTemp;
			pRecv[1] = bBackUpByteTemp1;

			/* Storing the original pointer */
			pRxBuff = pRecv;

			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			/* no break */
		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
			PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
				&wTmp
			));

			/* Status is 0xAF or 0x00? */
			if (wRxlen > 0x0000U)
			{
				if (0U != (pDataParams->bWrappedMode))
				{
					bStatusByte = pRxBuff[wRxlen - 1u];
				}
				else
				{
					bStatusByte = pRxBuff[wTmp];
				}
			}

			if (bStatusByte == PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
			{
				if ((((pDataParams->bWrappedMode) != 0x00U) && (wRxlen == 2U)) ||
					(((pDataParams->bWrappedMode) == 0x00U) && (wRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}

				if (0U != (pDataParams->bWrappedMode))
				{
					/* Next position will ensure overwriting on the
					SW1SW2 received from previous command */
					wNextPos = wRxlen - 2U;
					(void)memcpy(bBackupBytes, &pRxBuff[wNextPos - 3u], 3);
				}
				else
				{
					/* Backup the last byte */
					bBackupByte = pRxBuff[wRxlen - 1u];
					(void)memcpy(bBackupBytes, &pRxBuff[wRxlen - 3u], 3);
					wNextPos = wRxlen - 1U;
				}

				if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES)
				{
					bIvLen = 16U;
				}
				else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE))
				{
					bIvLen = 8U;
				}
				else
				{
					bIvLen = 0U;
				}
				/* satisfy compiler */
				PH_UNUSED_VARIABLE (bIvLen);
			}
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
			PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
				&wRxBufferSize
			));

			if (bStatusByte == PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
			{
				if ((((pDataParams->bWrappedMode) != 0x00U) && (wRxlen == 2U)) ||
					(((pDataParams->bWrappedMode) == 0x00U) && (wRxlen == 1U)))
				{
					/* AF should always be accompanied by data. Otherwise
					it is a protocol error */
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}
				if ((wNextPos + PHAL_MFDFEVX_MAX_FRAME_SIZE) >= wRxBufferSize)
				{
					/* Return 0xAF and let the caller recall the function with
					option = PH_EXCHANGE_RXCHAINING */
					/* Return the data accumulated till now and its length */
					if (0U != (pDataParams->bWrappedMode))
					{
						wRxlen -= 2u;
					}
					else
					{
						wRxlen -= 1u;
						pRxBuff++;
					}
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDFEVX);
					break;
				}
				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					wNextPos
				));

				bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
				return PH_STATUS_INPROCESS;
			}

			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD11;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
			bCmdBuff[0] = PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME;
			wCmdLen = 1U;
			if ( 0U != (pDataParams->bWrappedMode) )
			{
				/* Encode APDU Length*/
				pApdu[4] = (uint8) wCmdLen - 1u; /* Set APDU Length. */

				if (pApdu[4] != 0x00U)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						PH_EXCHANGE_BUFFER_FIRST,
						pApdu,
						PHAL_MFDFEVX_WRAP_HDR_LEN,
						&pRecv,
						pRxlen
					));
					PH_BREAK_ON_FAILURE(statusTmp);
					bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
					return PH_STATUS_INPROCESS;
				}
				bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Send this on L4 */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					wOption,
					bCmdBuff,
					wCmdLen,
					&pRecv,
					&wRxlen
				));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
			pApdu[1] = bCmdBuff[0];  /* DESFire command code. */
			/* Encode APDU Length*/
			pApdu[4] = (uint8) wCmdLen - 1u; /* Set APDU Length. */

			if (pApdu[4] != 0x00U)
			{
				bCmdBuff[0] = 0x00U; /* Le */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					bCmdBuff,
					0x01u,
					&pRecv,
					&wRxlen
				));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_DEFAULT,
					pApdu,
					PHAL_MFDFEVX_WRAP_HDR_LEN,
					&pRecv,
					&wRxlen
				));
			}
			/* To handle the case where the card returns only status 91 and returns
			AF in the next frame */
			if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				/* One or two more status bytes to read from DesFire */
				bBackUpByteTemp = pRecv[0];
				bBackUpByteTemp1 = pRecv[1];
				wBackUpLen = wRxlen;

				bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD9:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				&pApdu[2],
				0x01,
				&pRecv,
				&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);

			/* Received length can be one or two Ex: 0x91 0xAF */
			if (wRxlen == 2U)
			{
				pRecv[wBackUpLen] = pRecv[0];
				pRecv[wBackUpLen + 1U] = pRecv[1];
				bStatusByte = pRecv[1];
			}
			else if (wRxlen == 1U)
			{
				bStatusByte = pRecv[0];
				pRecv[wBackUpLen] = bStatusByte;
			}
			else
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
				break;
			}

			wRxlen = wBackUpLen + wRxlen;

			/* Set back the backed up bytes */
			pRecv[0] = bBackUpByteTemp;
			pRecv[1] = bBackUpByteTemp1;

			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD10:
			/* Update wNextPos */
			if (0U != (pDataParams->bWrappedMode))
			{
				bStatusByte = pRxBuff[wRxlen - 1u];

				/* Put back the backed up bytes */
				(void)memcpy(&pRxBuff[wNextPos - 3u], bBackupBytes, 3);

				wNextPos = wRxlen - 2U;
				(void)memcpy(bBackupBytes, &pRxBuff[wNextPos - 3u], 3);
			}
			else
			{
				bStatusByte = pRxBuff[wNextPos];

				/* Put back the previously backed up byte */
				pRxBuff[wNextPos] = bBackupByte;

				/* Put back the backed up bytes */
				(void)memcpy(&pRxBuff[wNextPos - 2u], bBackupBytes, 3);

				wNextPos = wRxlen - 1U;
				bBackupByte = pRxBuff[wNextPos];

				/* Backup 3 bytes. The next frame will overwrite these */
				(void)memcpy(bBackupBytes, &pRxBuff[wNextPos - 2u], 3);
			}
			bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD11:
			if (0U != (pDataParams->bWrappedMode))
			{
				wRxlen -= 2u;
			}
			else
			{
				wRxlen -= 1u;
				pRxBuff++;
			}

			*pRxlen = wRxlen;
			*pResponse = pRxBuff;
			statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, bStatusByte);
			break;

		default:
			break;
	}
	bGetDataState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ISOGetData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen)
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOption = PH_EXCHANGE_DEFAULT;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[10] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bApduLen = 4U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNextPos = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupBytes[3];
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[7] =
	{ PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00U, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00U,/* Extended Length APDU */ 0x00U, 0x00U };
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLe[2] = { 0x00U, 0x00U };
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bExtendedLenApdu = 0U;
	static VAR(uint16, ANFCRL_VAR) wRxlen = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuff = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSD = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSC = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
	VAR(uint16, ANFCRL_VAR) pValue = 0U;
	static VAR(uint8, ANFCRL_VAR) bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bISOGetDateState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			/* Initializing with 4 since Length of the Data(Lc) starts from 4th element of pApdu[] */
			bApduLen = 4;
			/* Status and two other bytes to be backed up before getting new frame of data */
			(void)memset(bBackupBytes, 0x00, 3);
			/*
			   0xAF is just an indication that this is a call
			   to the function to get remaining data
			*/
			if (pSendBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
			{
				if (0U != (pDataParams->bWrappedMode))
				{
					/* Check for permissible CmdBuff size */
					if (wCmdLen > PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE)
					{
						return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDFEVX);
					}

					pApdu[1] = pSendBuff[0];  /* DESFire command code. */
					switch (pApdu[1])
					{
						case PHAL_MFDFEVX_CMD_READ_DATA:
						case PHAL_MFDFEVX_CMD_READ_DATA_ISO:
						case PHAL_MFDFEVX_CMD_READ_RECORDS:
						case PHAL_MFDFEVX_CMD_READ_RECORDS_ISO:
							/* Get the format value(Whether to use short APDU or extended APDU */
							PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_GetConfig(pDataParams,
								PHAL_MFDFEVX_SHORT_LENGTH_APDU,
								&pValue));
							/* To Note: Short APDU will be used,
							 *  1. when user force the 'length' to be sent as short APDU in case of BIG ISO.
							 *  2. When the data to read is not BIG ISO(less than 256 bytes).
							 */
							if(0U != (pValue & 0x0001U))
							{
								/* Encode 'Length' in Short APDU format */
								pApdu[bApduLen++] = (uint8) wCmdLen - 1u; /* Set APDU Length. */
							}
							else
							{
								/* Encode 'Length' in extended Length format */
								bExtendedLenApdu = 0x01;
								pApdu[bApduLen++] = 0x00;
								pApdu[bApduLen++] = 0x00;
								pApdu[bApduLen++] = (uint8) wCmdLen - 1u; /* Set APDU Length. */
							}
							break;

						default:
							/* Rest other commands, retain existing implementation which is Short APDU */
							pApdu[bApduLen++] = (uint8) wCmdLen - 1u; /* Set APDU Length. */
							break;
					}

					/* Check if pApdu[4] is valid in case of Short APDU or
					 * Check if pAdpu[6] is valid in case of Extended APDU
					 */
					if ((pApdu[4] != 0x00U) || ((bExtendedLenApdu != 0x00U) && (pApdu[6] != 0x00U)))
					{
						bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
						return PH_STATUS_INPROCESS;
					}
					bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					/* Normal mode */
					if (wCmdLen > PHAL_MFDFEVX_MAXDFAPDU_SIZE)
					{
						return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDFEVX);
					}

					/* Send this on L4 */
					PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						wOption,
						pSendBuff,
						wCmdLen,
						&pRecv,
						&wRxlen
					));
					if ((status != PH_ERR_SUCCESS) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
					{
						return status;
					}

					/* Storing the original pointer */
					pRxBuff = pRecv;
				}
			}
			else
			{
				/* Send this on L4 */
				PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_RXCHAINING,
					pSendBuff,
					wCmdLen,
					&pRecv,
					&wRxlen
				));
				if ((status != PH_ERR_SUCCESS) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
				{
					return status;
				}

				/* Storing the original pointer */
				pRxBuff = pRecv;
			}
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				pApdu,
				bApduLen,
				&pRecv,
				&wRxlen
			));
			if(status != PH_ERR_SUCCESS)
			{
				bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
				return PH_STATUS_INPROCESS;
			}
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				&pSendBuff[1],
				wCmdLen - 1u,
				&pRecv,
				&wRxlen
			));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
			/* Check if pApdu[4] is valid in case of Short APDU or
			 * Check if pAdpu[6] is valid in case of Extended APDU
			 */
			if ((pApdu[4] != 0x00U) || ((bExtendedLenApdu != 0x00U) && (pApdu[6] != 0x00U)))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST,
					bLe,
					(bExtendedLenApdu != 0x00U) ? 0x02U : 0x01U,
					&pRecv,
					&wRxlen
				));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_DEFAULT,
					pApdu,
					bApduLen,
					&pRecv,
					&wRxlen
				));
			}
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			/* no break */
		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
			if ((status != PH_ERR_SUCCESS) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
				statusTmp = status;
				break;
			}

			/* Storing the original pointer */
			pRxBuff = pRecv;

			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
			/* no break */
		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				if (0U != (pDataParams->bWrappedMode))
				{
					/* Next position will ensure overwriting on the
					SW1SW2 received from previous command */
					wNextPos = wRxlen - 2U;
					(void)memcpy(bBackupBytes, &pRxBuff[wNextPos - 3u], 3);
				}
				else
				{
					/* Backup the last byte */
					(void)memcpy(bBackupBytes, &pRxBuff[wRxlen - 3u], 3);
					wNextPos = wRxlen;
				}

				statusTmp = phhalHw_GetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
					&wRxBufferSize
				);
				if (statusTmp != PH_ERR_SUCCESS)
				{
					bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
					return statusTmp;
				}
			}
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
			/* no break */
		case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				/* Get the Frame length */
				PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
					pDataParams,
					&wFSD,
					&wFSC
				));

				if (wFSD > wFSC)
				{
					if ((wNextPos + wFSC) >= wRxBufferSize)
					{
						/* Return Chaining and let the caller recall the function with
						option = PH_EXCHANGE_RXCHAINING */
						/* Return the data accumulated till now and its length */
						if (((pSendBuff[0]) != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME) && ((pDataParams->bWrappedMode) == 0x00U))
						{
							wRxlen -= 1u;
							pRxBuff++;
						}
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDFEVX);
						statusTmp = status;
						break;
					}
				}
				else
				{
					if ((wNextPos + wFSD) >= wRxBufferSize)
					{
						/* Return Chaining and let the caller recall the function with
						option = PH_EXCHANGE_RXCHAINING */
						/* Return the data accumulated till now and its length */
						if (0U != (pDataParams->bWrappedMode))
						{
							wRxlen -= 2u;
						}

						status = PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDFEVX);
						statusTmp = status;
						break;
					}
				}

				PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					wNextPos
				));
			}
			else
			{
				bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
				return PH_STATUS_INPROCESS;
			}
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
			/* Send this on L4 */
			PH_CHECK_INPROCESS_FCT(status, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_RXCHAINING,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
			));

			/* Update wNextPos */
			if (0U != (pDataParams->bWrappedMode))
			{
				/* Put back the backed up bytes */
				(void)memcpy(&pRxBuff[wNextPos - 3u], bBackupBytes, 3);

				/* Update the Buffer Position */
				wNextPos = wRxlen - 2U;
			}
			else
			{
				/* Put back the backed up bytes */
				(void)memcpy(&pRxBuff[wNextPos - 3u], bBackupBytes, 3);

				/* Update the Buffer Position */
				wNextPos = wRxlen;
			}
			/* Backup 3 bytes. The next frame will overwrite these */
			(void)memcpy(bBackupBytes, &pRxBuff[wNextPos - 3u], 3);

			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
			/* Status is 0x00? */
			if (0U != (pDataParams->bWrappedMode))
			{
				statusTmp = pRecv[wRxlen - 1u];
				wRxlen -= 2u;
			}
			else
			{
				statusTmp = phhalHw_GetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					&wTmp
				);
				if (statusTmp != PH_ERR_SUCCESS)
				{
					bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
					return statusTmp;
				}

				if (pSendBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					statusTmp = pRecv[wTmp];
					wRxlen -= 1u;
					pRxBuff++;
				}
				else
				{
					statusTmp = status;
				}
			}

			*pRxlen = wRxlen;
			*pResponse = pRxBuff;
			bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
			return phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp);

		default:
			break;
	}
	bISOGetDateState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ReadData_Plain(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
  VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen)
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWorkBuffer[32] = { 0U };
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNumBlocks = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMAC[PH_CRYPTOSYM_AES_BLOCK_SIZE] = { 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMacCard[8] = { 0U };
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTmp = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0U;
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWorkBufferLen = 0U;
	static VAR(uint8, ANFCRL_VAR) bReadDataPlainState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bReadDataPlainState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			(void)memset(bWorkBuffer, 0x00, 32);
		#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
			(void)memset(bCMAC, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);
			(void)memset(bCMacCard, 0x00, 8);
		#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

			/* Copy the bCmdBuff data to the bWorkBuff */
			(void)memcpy(bWorkBuffer, bCmdBuff, wCmdLen);
			wWorkBufferLen = wCmdLen;

		#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
			{
				bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;
			}
			else
			{
				bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;
			}

			if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
			{
				/* Check for 0xAF added above to ensure that we do not update the
				IV or calculate CMAC for cases where in the application has called
				this API with bOption = PH_EXCHANGE_RXCHAINING */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
				{
					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Calculate MAC to update the init vector */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_MAC_MODE_CMAC),
						bWorkBuffer,
						wWorkBufferLen,
						bCMAC,
						&bMacLen
					));
					/* Store the IV */
					(void)memcpy(pDataParams->bIv, bCMAC, bIvLen);
					bMacLen = 0;

					if ((bOption & PHAL_MFDFEVX_COMMUNICATION_MAC_ON_CMD) == PHAL_MFDFEVX_COMMUNICATION_MAC_ON_CMD)
					{
						/* Append MAC for ISO/AES mode- in case of AES, the 16 byte
						 * CMAC is truncated to the 8 leftmost bytes.
						 */
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCMAC[0], PH_CRYPTOSYM_DES_BLOCK_SIZE);
						wWorkBufferLen += PH_CRYPTOSYM_DES_BLOCK_SIZE;
					}
				}
				else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2) &&
					((bOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_MACD))
				{
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
					wWorkBufferLen = 0;
					bWorkBuffer[wWorkBufferLen++] = bCmdBuff[0];
					/* Add CmdCtr and TI for MAC calculation */
					bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr);
					bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr >> 8U);
					(void)memcpy(&bWorkBuffer[wWorkBufferLen], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
					wWorkBufferLen += PHAL_MFDFEVX_SIZE_TI;

					/* Assumed here that a read-like commands cannot in any case have cmd+header+data > 24 bytes */

					if (wCmdLen > 1U)
					{
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (((uint32)wCmdLen) - 1u));
						wWorkBufferLen += (wCmdLen - 1u);
					}

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsMac,
						pDataParams->bIv,
						bIvLen
					));

					/* Calculate MAC */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC),
						bWorkBuffer,
						wWorkBufferLen,
						bCMAC,
						&bMacLen
					));

					/* Truncate the MAC generated */
					phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

					/* Get the original command in the work buffer. */
					(void)memcpy(bWorkBuffer, bCmdBuff, wCmdLen);
					/* Append MAC for EV2 mode. */
					(void)memcpy(&bWorkBuffer[wCmdLen], bCMAC, PHAL_MFDFEVX_TRUNCATED_MAC_SIZE);
					wWorkBufferLen = wCmdLen + PHAL_MFDFEVX_TRUNCATED_MAC_SIZE;
				}
				else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE) &&
					((bOption & PHAL_MFDFEVX_COMMUNICATION_MAC_ON_CMD) == PHAL_MFDFEVX_COMMUNICATION_MAC_ON_CMD))
				{
					/* Load Iv */
					(void)memset(pDataParams->bIv, 0, bIvLen);

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Calculate MAC to update the init vector */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_MAC_MODE_CBCMAC),
						&bWorkBuffer[1],
						wWorkBufferLen - 1U,
						bCMAC,
						&bMacLen
					));

					/* Append MAC for D40 mode- truncated to the leftmost 4 bytes. */
					(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCMAC[0], 4);

					wWorkBufferLen += 4U;
				}
				else
				{
					/*Do Nothing. This is for PRQA compliance */
				}
			}
		#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
			bReadDataPlainState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			if (0U != (bOption & PHAL_MFDFEVX_ISO_CHAINING_MODE))
			{
				PH_CHECK_INPROCESS_FCT(status, phalMfdfEVx_Sw_Int_ISOGetData(
					pDataParams,
					bWorkBuffer,
					wWorkBufferLen,
					&pRecv,
					&wRxlen
				));
			}
			else
			{
				/* Send the command */
				PH_CHECK_INPROCESS_FCT(status, phalMfdfEVx_Sw_Int_GetData(
					pDataParams,
					bWorkBuffer,
					wWorkBufferLen,
					&pRecv,
					&wRxlen
				));
			}

			bReadDataPlainState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

			if (((status & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
				((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
		#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}
				/* Set the length pointer with valid value. Otherwise there will be an error in AL while logging. (Access violation in address 0xccccccc) */
				*pRxdataLen = wRxlen;
				*ppRxdata = pRecv;
				/* Component code is already added by GetData */
		#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
				return status;
			}

			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2) &&
				(bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
			{
				/* Increment the command counter. This increments irrespective of
				* Plain mode or MAC mode. Ensuring here that it is incremented
				* only for the case where the user has called this for the first
				* time i.e., without PH_EXCHANGE_RXCHAINING option
				*/
				pDataParams->wCmdCtr++;
			}

		#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
			/* Verify the MAC */
			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
			{
				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));
				}

				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
				{
					(void)memcpy(bCMacCard, &pRecv[wRxlen - 8u], 8);
					wRxlen -= 8u;
					pRecv[wRxlen] = (uint8) status;

					/* Calculate CMAC */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST,
						pRecv,
						wRxlen + 1U,
						bCMAC,
						&bMacLen
					));

					if (memcmp(bCMAC, bCMacCard, 8) != 0)
					{
						/* CMAC validation failed */
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}

					/* Update IV to be used for next commands */
					(void)memcpy(pDataParams->bIv, bCMAC, bIvLen);
				}
				else
				{
					/* Calculate CMAC. Here the data length should be multiple of IV size */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
						pRecv,
						wRxlen,
						bCMAC,
						&bMacLen
					));
				}
			}
			else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2) &&
				((bOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_MACD))
			{
				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsMac,
						pDataParams->bIv,
						bIvLen
					));

					pDataParams->bNoUnprocBytes = 0;
					/* Return code */
					pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = 0x00;
					/* Lower byte of CmdCtr */
					pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr);
					/* Higher byte of CmdCtr */
					pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr >> 8U);
					/* TI */
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
					pDataParams->bNoUnprocBytes += PHAL_MFDFEVX_SIZE_TI;
				}

				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
				{
					(void)memcpy(bCMacCard, &pRecv[wRxlen - 8u], 8);
					wRxlen -= 8u;

					/* If received data is not multiple of block size */
					wTmp = (PH_CRYPTOSYM_AES_BLOCK_SIZE - ((uint16)(pDataParams->bNoUnprocBytes)));
					if (wTmp >= wRxlen)
					{
						wTmp = wRxlen;
					}
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pRecv, wTmp);
					pDataParams->bNoUnprocBytes += (uint8) wTmp;

					if (wTmp == wRxlen)
					{
						/* Conclude the CMAC calculation. */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
							pDataParams->pUnprocByteBuff,
							(pDataParams->bNoUnprocBytes),
							bCMAC,
							&bMacLen
						));
					}
					else
					{
						/* First send the 16 byte block for cmac calculation */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
							pDataParams->pUnprocByteBuff,
							(pDataParams->bNoUnprocBytes),
							bCMAC,
							&bMacLen
						));

						/* Send rest of the received data */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
							&pRecv[wTmp],
							wRxlen - wTmp,
							bCMAC,
							&bMacLen
						));
					}

					/* Since end of response is reached reset the pDataParams bNoUnprocBytes member to 0 */
					pDataParams->bNoUnprocBytes = 0;

					/* Truncate the MAC generated */
					phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

					/* Compare the CMAC received and Calculated MAC */
					if (memcmp(bCMAC, bCMacCard, 8) != 0)
					{
						/* CMAC validation failed */
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}
				}
				else
				{
					/* Handling of chaining. */
					/* Include the left over data for CMAC calculation */
					wTmp = PH_CRYPTOSYM_AES_BLOCK_SIZE - ((uint16)(pDataParams->bNoUnprocBytes));
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pRecv, wTmp);
					pDataParams->bNoUnprocBytes += (uint8) wTmp;

					/* Start MAC calculation with one full block size data */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
						pDataParams->pUnprocByteBuff,
						(pDataParams->bNoUnprocBytes),
						bCMAC,
						&bMacLen
					));

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
						&pRecv[wTmp],
						((wRxlen - wTmp) / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE,
						bCMAC,
						&bMacLen
					));

					/* Remaining bytes */
					wTmp = (wRxlen - wTmp) % PH_CRYPTOSYM_AES_BLOCK_SIZE;

					/* Update the UnprocByteBuffer with bytes not used for mac calculation */
					(void)memcpy(pDataParams->pUnprocByteBuff, &pRecv[wRxlen - wTmp], wTmp);
					pDataParams->bNoUnprocBytes = (uint8) wTmp;
				}
			}
			else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE)
				&& ((bOption & 0xF3U) == (PHAL_MFDFEVX_COMMUNICATION_MACD | PHAL_MFDFEVX_COMMUNICATION_MAC_ON_RC)))
			{
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
				{
					(void)memcpy(bCMacCard, &pRecv[wRxlen - 4u], 4);
					wRxlen -= 4u;
				}

				wNumBlocks = wRxlen / bIvLen;
				pTmp = pRecv;
				while (0U != wNumBlocks)
				{
					/* Encrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC),
						pTmp,
						bIvLen,
						bWorkBuffer
					));
					pTmp = (&pTmp[bIvLen]);
					wNumBlocks--;
					(void)memcpy(pDataParams->bIv, bWorkBuffer, bIvLen);

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));
				}
				if (0U != (wRxlen % bIvLen))
				{
					/* In case data to be read is longer than the RxBuffer size,
					the data is always sent in multiples of iv sizes from the card.
					Control should never come here when data read is still not
					complete */

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));
					(void)memcpy(bWorkBuffer, &pRecv[wRxlen - (wRxlen % ((uint16)bIvLen))], ((uint32)(wRxlen)) % ((uint32)bIvLen));

					/* Apply padding */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
						PH_CRYPTOSYM_PADDING_MODE_1,
						bWorkBuffer,
						wRxlen % bIvLen,
						bIvLen,
						(uint16)(sizeof(bWorkBuffer)),
						bWorkBuffer,
						&wTmp
					));
					/* Encrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC),
						bWorkBuffer,
						wTmp,
						bWorkBuffer
					));
				}
				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
				{
					(void)memcpy(bCMAC, bWorkBuffer, 4);
					if (memcmp(bCMAC, bCMacCard, 4) != 0)
					{
						/* MAC validation failed */
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}
					/* Reset IV */
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
				}
			}
			else
			{
				/* Will come here in case data transfer is plain
				and auth mode is 0x0A */
				bIvLen = 0x00U;
			}
		#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

			*ppRxdata = pRecv;
			*pRxdataLen = wRxlen;

			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_SUCCESS_CHAINING, PH_COMP_AL_MFDFEVX);;
			}
			break;

		default:
			break;
	}

	return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ReadData_Enc(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
  VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMAC[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0};
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwIndex;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumPaddingBytes;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0u;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pCrc = NULL;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM bTmpIV[16];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWorkBuffer[32];
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWorkBufferLen = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMacCard[8];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bPiccStatus = 0u;
  static VAR(uint8, ANFCRL_VAR) bReadDataEncState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bReadDataEncState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			/* Initialize static variable*/
			bIvLen = 0U;
			/* Copy the bCmdBuff data to the bWorkBuff */
			(void)memcpy(bWorkBuffer, bCmdBuff, wCmdLen);
			wWorkBufferLen = wCmdLen;

			if (((pDataParams->bAuthMode == PHAL_MFDFEVX_NOT_AUTHENTICATED) ||
				((bOption & 0xF0U) != PHAL_MFDFEVX_COMMUNICATION_ENC)))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_MFDFEVX);
			}
			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
			{
				bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;
			}
			else
			{
				bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;
			}

			if (((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES)) &&
				(bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
			{
				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				/* Calculate MAC to update the init vector */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
					pDataParams->pCryptoDataParamsEnc,
					(PH_CRYPTOSYM_MAC_MODE_CMAC),
					bCmdBuff,
					wCmdLen,
					bCMAC,
					&bMacLen
				));
				/* Store the IV */
				(void)memcpy(pDataParams->bIv, bCMAC, bIvLen);
			}
			else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2) &&
				(bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
			{
				(void)memset(pDataParams->bIv, 0x00, bIvLen);
				wWorkBufferLen = 0;
				bWorkBuffer[wWorkBufferLen++] = bCmdBuff[0];
				/* Add CmdCtr and TI for MAC calculation */
				bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr);
				bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr >> 8U);
				(void)memcpy(&bWorkBuffer[wWorkBufferLen], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
				wWorkBufferLen += PHAL_MFDFEVX_SIZE_TI;

				if (wCmdLen > 1U)
				{
					(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (uint32)(wCmdLen) - 1u);
					wWorkBufferLen += (wCmdLen - 1u);
				}

				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsMac,
					pDataParams->bIv,
					bIvLen
				));

				/* Calculate MAC */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
					pDataParams->pCryptoDataParamsMac,
					PH_CRYPTOSYM_MAC_MODE_CMAC,
					bWorkBuffer,
					wWorkBufferLen,
					bCMAC,
					&bMacLen
				));

				/* Truncate the MAC generated */
				phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

				/* Get the original command in the work buffer. */
				(void)memcpy(bWorkBuffer, bCmdBuff, wCmdLen);
				/* Append MAC for EV2 mode. */
				(void)memcpy(&bWorkBuffer[wCmdLen], bCMAC, PHAL_MFDFEVX_TRUNCATED_MAC_SIZE);
				wWorkBufferLen = wCmdLen + PHAL_MFDFEVX_TRUNCATED_MAC_SIZE;
			}
			else
			{
				/*Do Nothing. This is for PRQA compliance */
			}

			bReadDataEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			if (0U != (bOption & PHAL_MFDFEVX_ISO_CHAINING_MODE))
			{
				/* Send the command */
				PH_CHECK_INPROCESS_FCT(status, phalMfdfEVx_Sw_Int_ISOGetData(
					pDataParams,
					bWorkBuffer,
					wWorkBufferLen,
					&pRecv,
					&wRxlen
				));
			}
			else
			{
				/* Send the command */
				PH_CHECK_INPROCESS_FCT(status, phalMfdfEVx_Sw_Int_GetData(
					pDataParams,
					bWorkBuffer,
					wWorkBufferLen,
					&pRecv,
					&wRxlen
				));
			}

			bReadDataEncState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

			if (((status & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
				((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}
				/* Set the length pointer with valid value. Otherwise there will be an error in AL while logging. (Access violation in address 0xccccccc) */
				*pRxdataLen = wRxlen;
				*ppRxdata = pRecv;
				return status;
			}

			/* Update the PICC Status as this will be used for CRC calculation. */
			bPiccStatus = (uint8) ((bCmdBuff[0] == PHAL_MFDFEVX_CMD_READ_SIG) ? 0x90 : 0x00);

			if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
			{
				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					/* Increment the command counter */
					pDataParams->wCmdCtr++;

					pDataParams->bNoUnprocBytes = 0;
					/* Return code */
					if (bCmdBuff[0] == PHAL_MFDFEVX_CMD_READ_SIG)
					{
						pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = 0x90;
					}
					else
					{
						pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = 0x00;
					}

					/* Lower byte of CmdCtr */
					pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr);
					/* Higher byte of CmdCtr */
					pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr >> 8U);
					/* TI */
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
					pDataParams->bNoUnprocBytes += PHAL_MFDFEVX_SIZE_TI;


					/* the IV is constructed by encrypting with KeyID.SesAuthENCKey according to the ECB mode
					 * As ECB encryption does not use IV during the encryption so we need not backup/ update with zero IV*/
					PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_ComputeIv(PH_ON,
						pDataParams->bTi,
						pDataParams->wCmdCtr,
						pDataParams->bIv
					));

					/* Encrypt IV */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_ECB,
						pDataParams->bIv,
						bIvLen,
						pDataParams->bIv
					));

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Handling of chaining. */

					(void)memset(pDataParams->bIv, 0x00, bIvLen);

					/* Load IV */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsMac,
						pDataParams->bIv,
						bIvLen
					));

				}
				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
				{
					(void)memcpy(bCMacCard, &pRecv[wRxlen - 8u], 8);
					wRxlen -= 8u;

					/* If received data is not multiple of block size */
					wTmp = PH_CRYPTOSYM_AES_BLOCK_SIZE - ((uint16)(pDataParams->bNoUnprocBytes));
					if (wTmp >= wRxlen)
					{
						wTmp = wRxlen;
					}
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pRecv, wTmp);
					pDataParams->bNoUnprocBytes += (uint8) wTmp;

					if (wTmp == wRxlen)
					{
						/* Conclude the CMAC calculation. */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
							pDataParams->pUnprocByteBuff,
							(pDataParams->bNoUnprocBytes),
							bCMAC,
							&bMacLen
						));
					}
					else
					{
						/* First send the 16 byte block for CMAC calculation */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
							pDataParams->pUnprocByteBuff,
							(pDataParams->bNoUnprocBytes),
							bCMAC,
							&bMacLen
						));

						/* Send rest of the received data */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
							&pRecv[wTmp],
							wRxlen - wTmp,
							bCMAC,
							&bMacLen
						));
					}

					/* Since end of response is reached reset the pDataParams bNoUnprocBytes member to 0 */
					pDataParams->bNoUnprocBytes = 0;

					/* Truncate the MAC generated */
					phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

					/* Compare the CMAC received and Calculated MAC */
					if (memcmp(bCMAC, bCMacCard, 8) != 0)
					{
						/* CMAC validation failed */
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}

					/* the IV is constructed by encrypting with KeyID.SesAuthENCKey according to the ECB mode
					 * As ECB encryption does not use IV during the encryption so we need not backup/ update with zero IV*/
					PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_ComputeIv(PH_ON,
						pDataParams->bTi,
						pDataParams->wCmdCtr,
						pDataParams->bIv
					));

					/* Encrypt IV */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_ECB,
						pDataParams->bIv,
						bIvLen,
						pDataParams->bIv
					));

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Decrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC),
						pRecv,
						wRxlen,
						pRecv
					));

					/* Remove padding */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_RemovePadding(
						PH_CRYPTOSYM_PADDING_MODE_2,
						pRecv,
						wRxlen,
						bIvLen,
						wRxlen,
						pRecv,
						&wRxlen
					));
				}
				else
				{
					/* Include the left over data for CMAC calculation */
					wTmp = (PH_CRYPTOSYM_AES_BLOCK_SIZE - ((uint16)(pDataParams->bNoUnprocBytes)));
					(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pRecv, wTmp);
					pDataParams->bNoUnprocBytes += (uint8) wTmp;

					/* Start MAC calculation with one full block size data */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
						pDataParams->pUnprocByteBuff,
						(pDataParams->bNoUnprocBytes),
						bCMAC,
						&bMacLen
					));

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
						&pRecv[wTmp],
						((wRxlen - wTmp) / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE,
						bCMAC,
						&bMacLen
					));

					/* Remaining bytes */
					wTmp = (wRxlen - wTmp) % PH_CRYPTOSYM_AES_BLOCK_SIZE;

					/* Update the UnprocByteBuffer with bytes not used for mac calculation */
					(void)memcpy(pDataParams->pUnprocByteBuff, &pRecv[wRxlen - wTmp], wTmp);
					pDataParams->bNoUnprocBytes = (uint8) wTmp;

					/* Decrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC),
						pRecv,
						wRxlen,
						pRecv
					));
				}
			}
			else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
			{
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
				{
					/* Store the IV temporarily */
					(void)memcpy(bTmpIV, &pRecv[wRxlen - (2U * ((uint16)bIvLen))], bIvLen);

					if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
					{
						(void)memcpy(pDataParams->bLastBlockBuffer, &pRecv[wRxlen - ((uint16)bIvLen)], bIvLen);
						wRxlen -= (uint16)bIvLen;
						pDataParams->bLastBlockIndex = bIvLen;
					}
					else
					{
						(void)memcpy(pRecv, pDataParams->bLastBlockBuffer, bIvLen);
						(void)memcpy(pDataParams->bLastBlockBuffer, &pRecv[wRxlen - bIvLen], bIvLen);
						wRxlen -= (uint16)bIvLen;
						pDataParams->bLastBlockIndex = bIvLen;
					}
					PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
						bIvLen
					));
				}
				else
				{
					/* Store the IV temporarily */
					(void)memcpy(bTmpIV, &pRecv[wRxlen - bIvLen], bIvLen);
					if (0U != (pDataParams->bLastBlockIndex))
					{
						(void)memcpy(pRecv, pDataParams->bLastBlockBuffer, bIvLen);
						pDataParams->bLastBlockIndex = 0;
					}
				}

				/* Decrypt */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
					pDataParams->pCryptoDataParamsEnc,
					(PH_CRYPTOSYM_CIPHER_MODE_CBC),
					pRecv,
					wRxlen,
					pRecv
				));

				/* Verify Padding and CRC */
				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
				{
					dwIndex = wRxlen;

					/* calculate pDataParams->dwPayLoadLen for GetCardUID command */
					if (bCmdBuff[0] == PHAL_MFDFEVX_CMD_GET_CARD_UID)
					{
						/* Response will be received as
						 * 1. 7 byte UID
						 * 2. [1 Byte UID Format] + [1 byte UID Length(0x04)] + 4 byte UID
						 * 3. [1 Byte UID Format] + [1 byte UID Length(0x0A)] + 10 byte UID
						 */
						if (pRecv[1] == 0x04U)
						{
							/* Indicates 4 byte UID. Set the payload length as (2 optional bytes + 4 bytes UID )*/
							pDataParams->dwPayLoadLen = 0x06u;
						}
						else if (pRecv[1] == 0x0AU)
						{
							/* Indicates 10 byte UID. Set the payload length as (2 optional bytes + 10 bytes UID ) */
							pDataParams->dwPayLoadLen = 0x0Cu;
						}
						else
						{
							/* default 7 byte UID */
							pDataParams->dwPayLoadLen = 0x07u;
						}

						/* Add the NUID length if available. */
						if (wCmdLen == 2u)
						{
							pDataParams->dwPayLoadLen = ((bCmdBuff[1] != 0U) ? (pDataParams->dwPayLoadLen + 4u) :
								pDataParams->dwPayLoadLen);
						}
					}

					/* calculate pDataParams->dwPayLoadLen for Get File Counters command */
					if (bCmdBuff[0] == PHAL_MFDFEVX_CMD_GET_FILE_COUNTERS)
					{
						/* 3Bytes of SDMReadCtr +  2bytes of Reserved */
						pDataParams->dwPayLoadLen = 0x05u;
					}

					if (pDataParams->dwPayLoadLen == 0U)
					{
						do
						{
							dwIndex--;
							if (pRecv[dwIndex] != 0x00U)
							{
								break;
							}
						} while (dwIndex != 0x00U);

						if (pRecv[dwIndex] != 0x80U)
						{
							/* Reset dwCrc to default */
							pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
						}

						/* CRC is in the 4 bytes before this */
						pCrc = &pRecv[(uint16) dwIndex - 4u];
						bNumPaddingBytes = (uint8) (wRxlen - dwIndex);
					}
					else
					{
						/* Receive length should be equal to wPayLoadLen + 4 byte crc + padding */
						if (wRxlen < (pDataParams->dwPayLoadLen + 4U))
						{
							/* Reset dwCrc to default */
							pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
							return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
						}
						/* CRC Bytes */
						pCrc = &pRecv[pDataParams->dwPayLoadLen];
						bNumPaddingBytes = (uint8) (wRxlen - pDataParams->dwPayLoadLen - 4u);

						/* Verify the padding bytes */
						dwIndex = pDataParams->dwPayLoadLen + 4U;
						for (; dwIndex < wRxlen; dwIndex++)
						{
							if (pRecv[dwIndex] != 0U)
							{
								/* Reset dwCrc to default */
								pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
							}
						}
					}

					/* Calculate CRC on data received */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						pDataParams->dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						pRecv,
						wRxlen - ((uint8)bNumPaddingBytes) - 4U,
						(P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA))&(pDataParams->dwCrc)
					));

					/* CRC to be calculated on data + status */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						pDataParams->dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						(uint8 *) &bPiccStatus,
						0x01U,
						(P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA)) &(pDataParams->dwCrc)
					));

					if (memcmp((uint8 *)(&(pDataParams->dwCrc)), pCrc, 4) != 0)
					{
						/* Reset dwCrc to default */
						pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}

					/* Return length of only the required bytes */
					wRxlen = wRxlen - bNumPaddingBytes - 4u;

					/* Reset to default */
					pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
				}
				else
				{
					/* Calculate CRC on data received */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						pDataParams->dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						pRecv,
						wRxlen,
						(P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA))&(pDataParams->dwCrc)
					));
				}
				/* Update IV to be used for next commands if no error */
				(void)memcpy(pDataParams->bIv, bTmpIV, bIvLen);

				/* Update the remaining length */
				if (pDataParams->dwPayLoadLen != 0U)
				{
					pDataParams->dwPayLoadLen -= wRxlen;
				}
			}
			else /* pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE */
			{
				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
				{
					/* Update IV to be used for next set of data decryption */
					(void)memcpy(pDataParams->bIv, &pRecv[wRxlen - (2U * ((uint16)bIvLen))], (uint32)bIvLen);

					if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
					{
						(void)memcpy(pDataParams->bLastBlockBuffer, &pRecv[wRxlen - (uint16)bIvLen], (uint32)bIvLen);
						wRxlen -= (uint16)bIvLen;
						pDataParams->bLastBlockIndex = bIvLen;
					}
					else
					{
						(void)memcpy(pRecv, pDataParams->bLastBlockBuffer, bIvLen);
						(void)memcpy(pDataParams->bLastBlockBuffer, &pRecv[wRxlen - bIvLen], bIvLen);
						wRxlen -= (uint16)bIvLen;
						pDataParams->bLastBlockIndex = bIvLen;
					}
					PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
						(uint16)bIvLen
					));
				}
				else
				{
					/* Reset the IV to 00 */
					(void)memset(pDataParams->bIv, 0x00, bIvLen);

					if(0U != (pDataParams->bLastBlockIndex))
					{
						(void)memcpy(pRecv, pDataParams->bLastBlockBuffer, bIvLen);
						pDataParams->bLastBlockIndex = 0u;
					}
				}

				/* Decrypt */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
					pDataParams->pCryptoDataParamsEnc,
					(PH_CRYPTOSYM_CIPHER_MODE_CBC),
					pRecv,
					wRxlen,
					pRecv
				));
				/* Verify Padding and CRC */
				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
				{
					dwIndex = wRxlen;
					if (bCmdBuff[0] == PHAL_MFDFEVX_CMD_GET_CARD_UID)
					{
						/* Response will be received as
						 * 1. 7 byte UID
						 * 2. [1 Byte UID Format] + [1 byte UID Length(0x04)] + 4 byte UID
						 * 3. [1 Byte UID Format] + [1 byte UID Length(0x0A)] + 10 byte UID
						 */
						if (pRecv[1] == 0x04U)
						{
							/* Indicates 4 byte UID. Set the payload length as (2 optional bytes + 4 bytes UID )*/
							pDataParams->dwPayLoadLen = 0x06;
						}
						else if (pRecv[1] == 0x0AU)
						{
							/* Indicates 10 byte UID. Set the payload length as (2 optional bytes + 10 bytes UID ) */
							pDataParams->dwPayLoadLen = 0x0C;
						}
						else
						{
							/* default 7 byte UID */
							pDataParams->dwPayLoadLen = 0x07;
						}

						/* Add the NUID length if available. */
						if (wCmdLen == 2U)
						{
							pDataParams->dwPayLoadLen = ((bCmdBuff[1] != 0U) ? (pDataParams->dwPayLoadLen + 4U) :
								pDataParams->dwPayLoadLen);
						}
					}

					if (pDataParams->dwPayLoadLen == 0U)
					{
						do
						{
							dwIndex--;
							if (pRecv[dwIndex] != 0x00U)
							{
								break;
							}
						} while (dwIndex != 0x00U);

						if (pRecv[dwIndex] != 0x80U)
						{
							/* Reset dwCrc to default */
							pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
						}

						/* CRC is in the 2 bytes before this */
						pCrc = &pRecv[(uint16) dwIndex - 2u];
						bNumPaddingBytes = (uint8) (wRxlen - dwIndex);
					}
					else
					{
						/* Receive length should be equal to wPayLoadLen + 2 byte crc + padding */
						if (wRxlen < (pDataParams->dwPayLoadLen + 2U))
						{
							/* Reset dwCrc to default */
							pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
							return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
						}
						/* CRC Bytes */
						pCrc = &pRecv[pDataParams->dwPayLoadLen];
						bNumPaddingBytes = (uint8) (wRxlen - pDataParams->dwPayLoadLen - 2u);

						/* Verify the padding bytes */
						dwIndex = pDataParams->dwPayLoadLen + 2U;
						for (; dwIndex < wRxlen; dwIndex++)
						{
							if (pRecv[dwIndex] != 0U)
							{
								/* Reset dwCrc to default */
								pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
							}
						}
					}

					/* Calculate CRC on data received */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc16(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						pDataParams->wCrc,
						PH_TOOLS_CRC16_POLY_ISO14443,
						pRecv,
						wRxlen - ((uint16)bNumPaddingBytes) - 2U,
						(P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA)) &(pDataParams->wCrc)
					));

					if (memcmp((uint8*)(&(pDataParams->wCrc)), pCrc, 2) != 0)
					{
						/* Reset wCrc to default */
						pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
					}

					/* Return length of only the required bytes */
					wRxlen = wRxlen - ((uint16)bNumPaddingBytes) - 2U;

					/* Reset crc to default */
					pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
				}
				else
				{
					/* Calculate CRC on data received */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc16(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						pDataParams->wCrc,
						PH_TOOLS_CRC16_POLY_ISO14443,
						pRecv,
						wRxlen,
						(P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA)) &(pDataParams->wCrc)
					));

					/* Update the remaining length: */
					if (pDataParams->dwPayLoadLen != 0U)
					{
						pDataParams->dwPayLoadLen -= wRxlen;
					}
				}
			}
			*ppRxdata = pRecv;
			*pRxdataLen = wRxlen;
			break;

		default:
			break;
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_Enc(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bIns,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
	VAR(uint16, ANFCRL_VAR) wCmdLen,
	VAR(uint8, ANFCRL_VAR) bPaddingOption,
	VAR(uint8, ANFCRL_VAR) bCommOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
	VAR(uint16, ANFCRL_VAR) wDataLen)
{
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvBackup[16] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWorkBuffer[32] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMacCard[8] = {0U};
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] =
	{ PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00 };
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWorkBufferLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTotalLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNumDataBlocks = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCommMode = PH_EXCHANGE_BUFFER_CONT;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSD = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSC = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wApduLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen1 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLastChunkLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLastChunk[32] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMAC[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pResp[16] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0U;
	static VAR(uint8, ANFCRL_VAR) bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch(bWriteEncState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			(void)memset(bWorkBuffer, 0x00, 20);
			(void)memset(bCMAC, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);
			(void)memset(bLastChunk, 0x00, 32);
			wDataLen1 = 0;

			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
			{
				bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;
			}
			else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE))
			{
				bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;
			}
			else
			{
				/* This function cannot be used without authentication */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_AL_MFDFEVX);
			}

			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
			{
				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				/* encrypt only Cmd data with KsesauthEnc */
				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					/* First calculate CRC on the cmd+params */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						bCmdBuff,
						wCmdLen,
						&dwCrc
					));
				}

				wNumDataBlocks = (wDataLen / bIvLen);
				if (wNumDataBlocks > 0U)
				{
					/* Calculate CRC32 for these blocks */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						pData,
						wNumDataBlocks * bIvLen,
						&dwCrc
					));
					/* Encrypt these blocks. Encrypted data put back on pData */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT),
						pData,
						wNumDataBlocks * bIvLen,
						pData
					));
					/* Update the data index */
					wDataLen1 = wNumDataBlocks * bIvLen;

					/* Update the IV */
					(void)memcpy(pDataParams->bIv, &pData[(wNumDataBlocks * bIvLen) - bIvLen], bIvLen);
				}

				if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
				{
					/* Last remaining bytes */
					if(0U != (wDataLen - wDataLen1))
					{
						/* Calculate CRC32 for the remaining data  */
						PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc32(
							PH_TOOLS_CRC_OPTION_DEFAULT,
							dwCrc,
							PH_TOOLS_CRC32_POLY_DF8,
							&pData[wDataLen1],
							wDataLen - wDataLen1,
							&dwCrc
						));
						/* Prepare the last frame of data */
						(void)memcpy(bLastChunk, &pData[wDataLen1], (uint32)(wDataLen) % (uint32)(bIvLen));
					}

					/* Add CRC */
					(void)memcpy(&bLastChunk[(wDataLen % bIvLen)], (uint8*)(&dwCrc), 4);

					/* Has a last frame */
					wLastChunkLen = wDataLen - wDataLen1 + 4U;

					/* Apply padding. If padding option is 2, we
					need to pad even if the data is already multiple
					of bIvLen */
					if (((wLastChunkLen % bIvLen) != 0U) ||
						((bPaddingOption == PH_CRYPTOSYM_PADDING_MODE_2) && ((wLastChunkLen % bIvLen) == 0U)))
					{
						/* Apply padding */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
							bPaddingOption,
							bLastChunk,
							wLastChunkLen,
							bIvLen,
							(uint16)sizeof(bLastChunk),
							bLastChunk,
							&wLastChunkLen
						));
					}
					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Encrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_LAST,
						bLastChunk,
						wLastChunkLen,
						bLastChunk
					));

					/* Reset dwCrc to default */
					/* pDataParams->dwCrc = PH_TOOLS_CRC32_PRESET_DF8; */

					/* Update the IV */
					(void)memcpy(pDataParams->bIv, &bLastChunk[wLastChunkLen - bIvLen], bIvLen);
				}
				wTotalLen = wDataLen1 + wLastChunkLen;
			}
			else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
			{
				/* Encrypt the CmdData with KsesAuthENC, If required padding needs to be done */
				/* the IV is constructed by encrypting with KeyID.SesAuthENCKey according to the ECB mode
				* As ECB encryption does not use IV during the encryption so we need not backup/ update with zero IV*/

				/* encrypt only Cmd data with KsesauthEnc */
				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_ComputeIv(PH_OFF,
						pDataParams->bTi,
						pDataParams->wCmdCtr,
						pDataParams->bIv
					));

					/* Encrypt IV */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_ECB,
						pDataParams->bIv,
						bIvLen,
						pDataParams->bIv
					));

					wCommMode = PH_EXCHANGE_BUFFER_FIRST;
				}

				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				wNumDataBlocks = (wDataLen / bIvLen);

				if (wNumDataBlocks > 0U)
				{
					/* Encrypt these blocks. Encrypted data put back on pData */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC | wCommMode),
						pData,
						wNumDataBlocks * bIvLen,
						pData
					));

					/* Update the data index this hold the data encrypted */
					wDataLen1 = wNumDataBlocks * bIvLen;

					/* Update the IV */
					(void)memcpy(pDataParams->bIv, &pData[(wNumDataBlocks * bIvLen) - bIvLen], bIvLen);
				}

				if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
				{
					/*check for remaining bytes if present*/
					if (0U != (wDataLen - wDataLen1))
					{
						/* Prepare the last frame of data */
						(void)memcpy(bLastChunk, &pData[wDataLen1], (uint32)(wDataLen) % (uint32)(bIvLen));
						/* Has a last frame */
						wLastChunkLen = wDataLen - wDataLen1;
					}

					/* Apply padding */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
						PH_CRYPTOSYM_PADDING_MODE_2,
						bLastChunk,
						wLastChunkLen,
						16U,
						(uint16)sizeof(bLastChunk),
						bLastChunk,
						&wLastChunkLen
					));

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* Encrypt the last frame*/
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC | (((wDataLen1 == 0U) && (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)) ? PH_EXCHANGE_DEFAULT : PH_EXCHANGE_BUFFER_LAST),
						bLastChunk,
						wLastChunkLen,
						bLastChunk
					));
				}

				/* size of encrypted data */
				wTotalLen = wDataLen1 + wLastChunkLen;

				if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
				{
					/* back up encryption IV */
					(void)memcpy(bIvBackup, pDataParams->bIv, bIvLen);

					/* set Iv value  for CMAC calculation*/
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
					pDataParams->bNoUnprocBytes = 0;

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsMac,
						pDataParams->bIv,
						bIvLen
					));

					/* copy original encrypted IV */
					(void)memcpy(pDataParams->bIv, bIvBackup, bIvLen);

					/* Calculate MAC on Cmd || wCmdCtr || TI || CmdHeader || CmdData */
					bWorkBuffer[wWorkBufferLen++] = bCmdBuff[0];
					bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr);
					bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr >> 8U);
					(void)memcpy(&bWorkBuffer[wWorkBufferLen], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
					wWorkBufferLen += PHAL_MFDFEVX_SIZE_TI;
				}
				else
				{
					(void)memcpy(bWorkBuffer, pDataParams->pUnprocByteBuff, pDataParams->bNoUnprocBytes);
					wWorkBufferLen = pDataParams->bNoUnprocBytes;
					pDataParams->bNoUnprocBytes = 0;
				}

				/* Check for presence of command header */
				if (wCmdLen > 1U)
				{
					/* Calculate the total length of data for MAC calculation */
					wTmp = ((wCmdLen - 1u) + (wWorkBufferLen));

					/* Since bWorkbuffer can accommodate 32 bytes, check for buffer overflow */
					if (wTmp > 32U)
					{
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (32U - ((uint32)wWorkBufferLen)));
						/* Calculate CMAC */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_FIRST,
							bWorkBuffer,
							32U,
							bCMAC,
							&bMacLen
						));

						/* Copy the remaining bCmdBuff into bWorkBuffer */
						(void)memcpy(bWorkBuffer, &bCmdBuff[(32U - wWorkBufferLen) + 1U], (uint32)(wTmp) - 32u);
						wWorkBufferLen = (wTmp - 32u);
						wCommMode = PH_EXCHANGE_BUFFER_CONT;
					}
					else
					{
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (uint32)(wCmdLen) - 1u);
						wWorkBufferLen += (wCmdLen - 1u);
					}
				}

				/* calculate the MAC value for encrypted CmdData */
				if (0U != (wDataLen1))
				{
					if ((wTmp < 32U) && ((bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)))
					{
						wCommMode = PH_EXCHANGE_BUFFER_FIRST;
					}

					/* check for remaining number of data to make multiple of IV length */
					wTmp = (PH_CRYPTOSYM_AES_BLOCK_SIZE - (wWorkBufferLen % PH_CRYPTOSYM_AES_BLOCK_SIZE));

					(void)memcpy(&bWorkBuffer[wWorkBufferLen], pData, wTmp);

					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						(PH_CRYPTOSYM_MAC_MODE_CMAC | wCommMode),
						bWorkBuffer,
						wWorkBufferLen + wTmp,
						bCMAC,
						&bMacLen
					));

					if ((wDataLen1 - wTmp) > PH_CRYPTOSYM_AES_BLOCK_SIZE)
					{
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
							&pData[wTmp],
							(((wDataLen1 - wTmp) / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE),
							bCMAC,
							&bMacLen
						));
					}

					/* copy remaining data present in pdata */
					wWorkBufferLen = ((wDataLen1 - wTmp) % PH_CRYPTOSYM_AES_BLOCK_SIZE);
					(void)memcpy(bWorkBuffer, &pData[wDataLen1 - wWorkBufferLen], wWorkBufferLen);
				}
				/* if Last packet of data is sent */
				if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
				{
					/* copy remaining data to work buffer */
					wTmp = wWorkBufferLen + wLastChunkLen;

					if (wTmp < 32U)
					{
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], &bLastChunk[0], wLastChunkLen);

						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
							bWorkBuffer,
							wTmp,
							bCMAC,
							&bMacLen
						));
					}
					else
					{
						wTmp = 32U - wWorkBufferLen;
						(void)memcpy(&bWorkBuffer[wWorkBufferLen], bLastChunk, wTmp);

						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
							bWorkBuffer,
							32,
							bCMAC,
							&bMacLen
						));

						/* this If condition is added to suppress QAC warning */
						if (wLastChunkLen > 0U)
						{
							PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
								pDataParams->pCryptoDataParamsMac,
								(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST),
								&bLastChunk[wTmp],
								wLastChunkLen - wTmp,
								bCMAC,
								&bMacLen
							));
						}
					}

					/* Truncate the MAC generated */
					phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);
					(void)memcpy(&bLastChunk[wLastChunkLen], bCMAC, 8);
					wLastChunkLen += 8U;
				}
				else
				{
					/* calculate CMAC for if data is multiple of IV */
					if (wWorkBufferLen > PH_CRYPTOSYM_AES_BLOCK_SIZE)
					{
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
							pDataParams->pCryptoDataParamsMac,
							(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
							bWorkBuffer,
							((wWorkBufferLen / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE),
							bCMAC,
							&bMacLen
						));
					}
					else
					{
						/* copy remaining data present in pdata */
						pDataParams->bNoUnprocBytes = (uint8) (wWorkBufferLen % PH_CRYPTOSYM_AES_BLOCK_SIZE);
						(void)memcpy(pDataParams->pUnprocByteBuff, bWorkBuffer, pDataParams->bNoUnprocBytes);
					}
				}
				/* Update Total Length */
				wTotalLen = wDataLen1 + wLastChunkLen;

			}
			else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE)
			{
				/* Load Iv */
				PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				wNumDataBlocks = wDataLen / bIvLen;
				if (wNumDataBlocks > 0U)
				{
					/* Calculate CRC16 for these blocks */
					PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc16(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						wCrc,
						PH_TOOLS_CRC16_POLY_ISO14443,
						pData,
						wNumDataBlocks * bIvLen,
						&wCrc
					));

					/* Decrypt these blocks. decrypted data put back on pData.*/
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4 | PH_EXCHANGE_BUFFER_CONT,
						pData,
						wNumDataBlocks * bIvLen,
						pData
					));
					/* Update the data index */
					wDataLen1 = wNumDataBlocks * bIvLen;

					/* Update the IV */
					(void)memcpy(pDataParams->bIv, &pData[(wNumDataBlocks * bIvLen) - bIvLen], bIvLen);
				}

				if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
				{
					/* Last remaining bytes */
					if (0U != (wDataLen - wDataLen1))
					{
						/* Calculate CRC16 for the remaining data  */
						PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc16(
							PH_TOOLS_CRC_OPTION_DEFAULT,
							wCrc,
							PH_TOOLS_CRC16_POLY_ISO14443,
							&pData[wDataLen1],
							wDataLen - wDataLen1,
							&wCrc
						));

						/* Prepare the last frame of data */
						(void)memcpy(bLastChunk, &pData[wDataLen1], (uint32)(wDataLen) % (uint32)(bIvLen));
					}

					/* Add CRC */
					(void)memcpy(&bLastChunk[(wDataLen % bIvLen)], (uint8*)(&wCrc), 2);

					/* Has a last frame */
					wLastChunkLen = wDataLen - wDataLen1 + 2U;

					/* Apply padding. If padding option is 2, we
					need to pad even if the data is already multiple
					of bIvLen */
					if (((wLastChunkLen % bIvLen) != 0U) ||
						((bPaddingOption == PH_CRYPTOSYM_PADDING_MODE_2) && ((wLastChunkLen % bIvLen) == 0U)))
					{
						/* Apply padding */
						PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
							bPaddingOption,
							bLastChunk,
							wLastChunkLen,
							bIvLen,
							(uint16)sizeof(bLastChunk),
							bLastChunk,
							&wLastChunkLen
						));
					}
					/* Load Iv.  Use the last IV. But will reset the IV after encryption operation*/
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen
					));

					/* DF4 Decrypt */
					PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4 | PH_EXCHANGE_BUFFER_LAST,
						bLastChunk,
						wLastChunkLen,
						bLastChunk
					));

					/* Reset dwCrc to default */
					/* pDataParams->wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A; */

					/* Set IV to 00 for DF4 mode*/
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
				}

				wTotalLen = wDataLen1 + wLastChunkLen;
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_AUTH_ERROR, PH_COMP_AL_MFDFEVX);
			}

			/* At this point have proper data to be transmitted in the
			* buffer provided by the user.
			* wTotalLength should have the total length to be transmitted
			* First Frame: Cmd+Params+Data
			* wTotalLength -= wDataLen;
			while (wTotalLength)
			{
			Break the data into chunks of max data size and transmit.
			For ISO wrapped mode, max of 55 bytes can be sent in one frame.
			For native mode, max of 60 bytes can be sent in one frame.
			}
			*/

			/* First copy the cmd+params+data(up-to 52 bytes) and transmit
			* Next put AF+up-to 59 bytes of data and transmit.
			* Continue till all data in Pdata is transferred, lastly include
			* the contents of bLastChunk also
			*/

			if (bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE)
			{
				if (0U != (pDataParams->bWrappedMode))
				{
					wFrameLen = PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE;
				}
				else
				{
					wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
				}
			}
			else
			{
				/* Get the Frame length */
				PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
					pDataParams,
					&wFSD,
					&wFSC
				));

				if (0U != (pDataParams->bWrappedMode))
				{
					wFrameLen = wFSC - 9u;
				}
				else
				{
					wFrameLen = wFSC - 4u;
				}
			}

			wTmp = wTotalLen;

			if (wTmp <= (wFrameLen - wCmdLen))
			{
				wApduLen = ((wCmdLen == 0x01U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0u : PHAL_MFDFEVX_WRAP_HDR_LEN;
				wCmdLen = ((wCmdLen == 0x01U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0u : wCmdLen;

				/* Send in one shot */
				if (0U != (pDataParams->bWrappedMode))
				{
					pApdu[1] = bCmdBuff[0]; /* DESFire cmd code in INS */
					if (wCmdLen > 0U)
					{
						pApdu[4] = (uint8) (wCmdLen + wTotalLen) - 0x01u;
					}

					bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
					return PH_STATUS_INPROCESS;
				}
			}
			else
			{
				bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
			}
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_FIRST |
					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
					pApdu,
					wApduLen,
					&pRecv,
					&wRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
			if (wCmdLen > 0U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT |
					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
					&bCmdBuff[1],
					wCmdLen - 1u,
					&pRecv,
					&wRxlen));
			}
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT |
				(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
				pData,
				wDataLen1,
				&pRecv,
				&wRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
			if (wLastChunkLen != 0x0000U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT |
					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
					bLastChunk,
					wLastChunkLen,
					&pRecv,
					&wRxlen));
			}
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST |
				(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
			if (wLastChunkLen != 0x0000U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_CONT |
					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
					pData,
					wDataLen1, /* This is the size that is multiple of IV size */
					&pRecv,
					&wRxlen));
			}
			PH_BREAK_ON_FAILURE(statusTmp);
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
			/* Send in one shot */
			if (0U != (pDataParams->bWrappedMode))
			{
				/* Le byte */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST |
					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0U),
					&pApdu[2],
					(uint16) (((pDataParams->dwPayLoadLen > 0xFEU) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0x02U : 0x01U),
					&pRecv,
					&wRxlen));
			}
			else
			{

				if (wLastChunkLen != 0x0000U)
				{

					PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						PH_EXCHANGE_BUFFER_LAST |
						(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))))? PH_EXCHANGE_TXCHAINING : 0u),
						bLastChunk,
						wLastChunkLen,
						&pRecv,
						&wRxlen));
				}
				else
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
						pDataParams->pPalMifareDataParams,
						PH_EXCHANGE_BUFFER_LAST |
						(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
						pData,
						wDataLen1, /* This is the size that is multiple of IV size */
						&pRecv,
						&wRxlen));
				}
			}

			PH_BREAK_ON_FAILURE(statusTmp);

			if (0U != (pDataParams->bWrappedMode))
			{
				status = (uint8)pRecv[wRxlen - 1u];
				wRxlen -= 2u;
			}
			else
			{
				status = (uint8) pRecv[0];
				pRecv++; /* Increment pointer to point only to data */
				wRxlen -= 1u;
			}

			if (status != PH_ERR_SUCCESS)
			{
				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}
				statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, (uint8) status);
				break;
			}

			(void)memcpy(pResp, pRecv, wRxlen);

			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
			if (wDataLen1 > 0x0200U)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_SendDataAndAddDataToPICC(
					pDataParams,
					bIns,
					bCmdBuff,
					wCmdLen,
					pData,
					wDataLen1,
					bLastChunk,
					wLastChunkLen,
					pResp,
					&wRxlen
				));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_SendDataToPICC(
					pDataParams,
					bIns,
					(bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE),
					bCmdBuff,
					wCmdLen,
					pData,
					wDataLen1,
					bLastChunk,
					wLastChunkLen,
					pResp,
					&wRxlen
				));
			}

			if ((statusTmp & PH_ERR_MASK) == PHAL_MFDFEVX_RESP_CHAINING)
			{
				break;
			}

			if (((statusTmp & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
				((statusTmp & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}
				break;
			}
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
			/* no break */

		case PHAL_MFDFEVX_SW_INT_STATE_CMD9:
			bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
			(void)memset(bCMacCard, 0x00, 8);

			/* Verify the MAC. MAC is not received if in 0x0A MAC'd mode */
			if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
				(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
			{
				if (wRxlen < 8U) /* If no CMAC received */
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}

				/* Decrypt the bWorkBuffer*/
				PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsEnc,
					pDataParams->bIv,
					bIvLen
				));

				/* copy CMAC received from card*/
				(void)memcpy(bCMacCard, &pResp[wRxlen - 8u], 8);
				wRxlen -= 8u;

				/* Copy the status byte at the end */
				pResp[wRxlen] = (uint8) status;

				/* verify the MAC */
				PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_CalculateMac(
					pDataParams->pCryptoDataParamsEnc,
					(PH_CRYPTOSYM_MAC_MODE_CMAC),
					pResp,
					wRxlen + 1U,
					bCMAC,
					&bMacLen
				));

				if (memcmp(bCMacCard, bCMAC, 8) != 0)
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
				}

				/* Update IV */
				(void)memcpy(pDataParams->bIv, bCMAC, bIvLen);
			}
			else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
			{
				/* Increment the command counter */
				pDataParams->wCmdCtr++;

				if (wRxlen < 8U) /* If no CMAC received */
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}

				(void)memset(pDataParams->bIv, 0x00, bIvLen);

				/* Load IV */
				PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_LoadIv(
					pDataParams->pCryptoDataParamsMac,
					pDataParams->bIv,
					bIvLen
				));

				/* copy CMAC received from card*/
				(void)memcpy(bCMacCard, &pResp[wRxlen - 8u], 8);
				wRxlen -= 8u;

				/*
				* Calculate MAC on RC || wCmdCtr || TI || RespData
				*/
				pDataParams->bNoUnprocBytes = 0x00;
				pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = 0x00;
				pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr);
				pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr >> 8U);
				(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
				pDataParams->bNoUnprocBytes += PHAL_MFDFEVX_SIZE_TI;

				/*Required ?*/
				(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pResp, wRxlen);
				pDataParams->bNoUnprocBytes += (uint8) wRxlen;

				/* verify the MAC */
				PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_CalculateMac(
					pDataParams->pCryptoDataParamsMac,
					(PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
					pDataParams->pUnprocByteBuff,
					pDataParams->bNoUnprocBytes,
					bCMAC,
					&bMacLen
				));

				/* Truncate the MAC generated */
				phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

				if (memcmp(bCMacCard, bCMAC, 8) != 0)
				{
					phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
				}
			}
			else
			{
				/*Do Nothing. This is for PRQA compliance */
			}
			break;

		default:
			break;
	}

	pApdu[0] = PHAL_MFDFEVX_WRAPPEDAPDU_CLA;
	pApdu[1] = 0x00U;
	pApdu[2] = PHAL_MFDFEVX_WRAPPEDAPDU_P1;
	pApdu[3] = PHAL_MFDFEVX_WRAPPEDAPDU_P2;
	pApdu[4] = 0x00U;
	wApduLen = 0U;
	bWriteEncState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_New(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen)
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResponse = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLen = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bPiccRetCode = 0;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aEncBuffer[256];
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wEncBufLen = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aMac[16];
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0;
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrc = PH_TOOLS_CRC16_PRESET_ISO14443A;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwCrc = PH_TOOLS_CRC32_PRESET_DF8;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aSMBuffer[256];
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSMBufLen = 0;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aIvBackup[16];
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
    static VAR(uint8, ANFCRL_VAR) bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
    switch(bMfdfEVxState)
    {
    	case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
			(void)memset(aEncBuffer, 0x00, sizeof(aEncBuffer));
			(void)memset(aMac, 0x00, sizeof(aMac));

			(void)memset(aSMBuffer, 0x00, sizeof(aSMBuffer));
			(void)memset(aIvBackup, 0x00, sizeof(aIvBackup));

			/* Apply Secure Messaging only if Communication Option is FULL. */
			if (bCommOption == PHAL_MFDFEVX_COMMUNICATION_ENC)
			{
				/* Apply D40 Secure Messaging. */
				if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE)
				{
					bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen));

					/* Reset SMBuffer len. */
					wSMBufLen = 0;

					/* Calculate CRC16 for these blocks */
					PH_CHECK_SUCCESS_FCT(wStatus, phTools_CalculateCrc16(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						wCrc,
						PH_TOOLS_CRC16_POLY_ISO14443,
						pData,
						wDataLen,
						&wCrc));

					/* Copy the Data information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], pData, wDataLen);
					wSMBufLen += wDataLen;

					/* Copy CRC information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], (uint8*)(&wCrc), 2);
					wSMBufLen += 2u;

					/* Apply padding. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_ApplyPadding(
						PH_CRYPTOSYM_PADDING_MODE_1,
						aSMBuffer,
						wSMBufLen,
						bIvLen,
						(uint16)sizeof(aEncBuffer),
						aEncBuffer,
						&wEncBufLen));

					/* Encrypt the data.*/
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC_DF4 | PH_EXCHANGE_DEFAULT,
						aEncBuffer,
						wEncBufLen,
						aEncBuffer));

					/* Set IV to 00 for DF4 mode. */
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
				}

				/* Apply EV1 Secure Messaging */
				else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) || (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
				{
					/* Set the IV length */
					bIvLen = (uint8) ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ? PH_CRYPTOSYM_DES_BLOCK_SIZE :
						PH_CRYPTOSYM_AES_BLOCK_SIZE);

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen));

					/* Reset SMBuffer len. */
					wSMBufLen = 0;

					/* Calculate CRC32 for Cmd || Cmd Header. */
					PH_CHECK_SUCCESS_FCT(wStatus, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						pCmdBuff,
						wCmdLen,
						&dwCrc));

					/* Calculate CRC16 for data. */
					PH_CHECK_SUCCESS_FCT(wStatus, phTools_CalculateCrc32(
						PH_TOOLS_CRC_OPTION_DEFAULT,
						dwCrc,
						PH_TOOLS_CRC32_POLY_DF8,
						pData,
						wDataLen,
						&dwCrc));

					/* Copy the Data information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], pData, wDataLen);
					wSMBufLen += wDataLen;

					/* Copy CRC information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], (uint8*)(&dwCrc), 4);
					wSMBufLen += 4u;

					/* Apply padding. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_ApplyPadding(
						PH_CRYPTOSYM_PADDING_MODE_1,
						aSMBuffer,
						wSMBufLen,
						bIvLen,
						(uint16)sizeof(aEncBuffer),
						aEncBuffer,
						&wEncBufLen));

					/* Encrypt the data.*/
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_DEFAULT,
						aEncBuffer,
						wEncBufLen,
						aEncBuffer));

					/* Update the IV. */
					(void)memcpy(pDataParams->bIv, &aEncBuffer[wEncBufLen - bIvLen], bIvLen);
				}

				/* Apply EV2 Secure Messaging. */
				else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
				{
					bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;

					/* Encrypt the CmdData with KsesAuthENC, If required padding needs to be done.
					 * The IV is constructed by encrypting with KeyID.SesAuthENCKey according to the ECB mode
					 * As ECB encryption does not use IV during the encryption so we need not backup / update
					 * with zero IV
					 */

					 /* Compute the IV. */
					PH_CHECK_SUCCESS_FCT(wStatus, phalMfdfEVx_Sw_Int_ComputeIv(PH_OFF,
						pDataParams->bTi,
						pDataParams->wCmdCtr,
						pDataParams->bIv));

					/* Encrypt IV. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						PH_CRYPTOSYM_CIPHER_MODE_ECB,
						pDataParams->bIv,
						bIvLen,
						pDataParams->bIv));

					/* Load the Encrypted Iv. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsEnc,
						pDataParams->bIv,
						bIvLen));

					/* Apply padding */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_ApplyPadding(
						PH_CRYPTOSYM_PADDING_MODE_2,
						pData,
						wDataLen,
						bIvLen,
						(uint16)sizeof(aEncBuffer),
						aEncBuffer,
						&wEncBufLen));

					/* Encrypt the Data. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_Encrypt(
						pDataParams->pCryptoDataParamsEnc,
						(PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_DEFAULT),
						aEncBuffer,
						wEncBufLen,
						aEncBuffer));

					/* Backup the current IV. */
					(void)memcpy(aIvBackup, pDataParams->bIv, bIvLen);

					/* Set Iv value for CMAC calculation. */
					(void)memset(pDataParams->bIv, 0x00, bIvLen);
					pDataParams->bNoUnprocBytes = 0;

					/* Load Iv */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_LoadIv(
						pDataParams->pCryptoDataParamsMac,
						pDataParams->bIv,
						bIvLen));

					/* Copy original encrypted IV. */
					(void)memcpy(pDataParams->bIv, aIvBackup, bIvLen);

					/* Frame the input buffer for MAC computation.
						* Cmd || wCmdCtr || TI || CmdHeader || CmdData
						*/
					aSMBuffer[wSMBufLen++] = pCmdBuff[0];
					aSMBuffer[wSMBufLen++] = (uint8) (pDataParams->wCmdCtr);
					aSMBuffer[wSMBufLen++] = (uint8) (pDataParams->wCmdCtr >> 8);
					(void)memcpy(&aSMBuffer[wSMBufLen], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
					wSMBufLen += PHAL_MFDFEVX_SIZE_TI;

					/* Copy Remaining command information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], &pCmdBuff[1], (uint32)wCmdLen - 1U);
					wSMBufLen += (uint16) (wCmdLen - 1u);

					/* Copy Encrypted MFCLicenseMAC information. */
					(void)memcpy(&aSMBuffer[wSMBufLen], aEncBuffer, wEncBufLen);
					wSMBufLen += wEncBufLen;

					/* Compute EV2 SecureMessaging MAC. */
					PH_CHECK_SUCCESS_FCT(wStatus, phCryptoSym_CalculateMac(
						pDataParams->pCryptoDataParamsMac,
						PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT,
						aSMBuffer,
						wSMBufLen,
						aMac,
						&bMacLen));

					/* Truncate the MAC. */
					phalMfdfEVx_Sw_Int_TruncateMac(aMac);
					bMacLen = 8U;
				}
				else
				{
					/* This function cannot be used without authentication */
					return PH_ADD_COMPCODE_FIXED(PH_ERR_AUTH_ERROR, PH_COMP_AL_MFDFEVX);
				}
			}
			else
			{
				/* Do nothing. */
			}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
    	    /* Buffer Command Information to PAL. */
			PH_CHECK_SUCCESS_FCT(wStatus, phalMfdfEVx_Sw_Int_CardExchange(
    	        pDataParams,
    	        PH_EXCHANGE_BUFFER_FIRST,
    	        (uint16) (wCmdLen + ((bCommOption == PHAL_MFDFEVX_COMMUNICATION_ENC) ? wEncBufLen : wDataLen) + bMacLen),
    	        PH_OFF,
    	        pCmdBuff,
    	        wCmdLen,
    	        NULL,
    	        NULL,
    	        NULL));
			/* Buffer Encrypted / Plain MFCLicenseMAC Information to PAL. */
    		PH_CHECK_SUCCESS_FCT(wStatus, phalMfdfEVx_Sw_Int_CardExchange(
				pDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				0U,
				PH_OFF,
				(bCommOption == PHAL_MFDFEVX_COMMUNICATION_ENC) ? aEncBuffer : pData,
				(uint16) ((bCommOption == PHAL_MFDFEVX_COMMUNICATION_ENC) ? wEncBufLen : wDataLen),
				NULL,
				NULL,
				NULL));
			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			/*no break*/
    	case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
    	    /* Buffer and Exchange Secure Messaging MAC to PICC. */
    		PH_CHECK_INPROCESS_FCT(wStatus, phalMfdfEVx_Sw_Int_CardExchange(
    	        pDataParams,
    	        PH_EXCHANGE_BUFFER_LAST,
    	        0,
    	        PH_ON,
    	        aMac,
    	        bMacLen,
    	        &pResponse,
    	        &wRespLen,
    	        &bPiccRetCode));

    	    /* Verify the status. */
    	    if ((wStatus & PH_ERR_MASK) != PH_ERR_SUCCESS)
    	    {
    	        /* Reset authentication status */
    	        if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
    	            (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
    	            (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
    	        {
    	            (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	        }
    	        break;
    	    }

    	#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	    /* Verify / Remove Secure Messaging only if Communication Option is FULL. */
    	    if (bCommOption == PHAL_MFDFEVX_COMMUNICATION_ENC)
    	    {
    	        /* Verify EV1 Secure Messaging. */
    	        if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) || (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
    	        {
    	            /* Load IV */
    	        	PH_CHECK_FAILURE_FCT(wStatus, phCryptoSym_LoadIv(
    	                pDataParams->pCryptoDataParamsEnc,
    	                pDataParams->bIv,
    	                bIvLen));

    	            /* Compute the Response MAC. */
    	        	PH_CHECK_FAILURE_FCT(wStatus, phCryptoSym_CalculateMac(
    	                pDataParams->pCryptoDataParamsEnc,
    	                (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
    	                &bPiccRetCode,
    	                1,
    	                aMac,
    	                &bMacLen));

    	            if (memcmp(pResponse, aMac, 8) != 0)
    	            {
    	                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	                wStatus = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
    	                break;
    	            }

    	            /* Update the IV. */
    	            (void)memcpy(pDataParams->bIv, aMac, bIvLen);
    	        }

    	        /* Verify EV2 Secure Messaging. */
    	        else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
    	        {
    	            /* Increment the command counter */
    	            pDataParams->wCmdCtr++;

    	            /* Reset the IV buffer. */
    	            (void)memset(pDataParams->bIv, 0x00, bIvLen);

    	            /* Load IV */
    	            PH_CHECK_FAILURE_FCT(wStatus, phCryptoSym_LoadIv(
    	                pDataParams->pCryptoDataParamsMac,
    	                pDataParams->bIv,
    	                bIvLen));

    	            /* Calculate MAC on RC || wCmdCtr || TI || RespData */
    	            pDataParams->bNoUnprocBytes = 0x00;
    	            pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = bPiccRetCode;
    	            pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr);
    	            pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr >> 8);
    	            (void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
    	            pDataParams->bNoUnprocBytes += PHAL_MFDFEVX_SIZE_TI;

    	            /* Copy the response.  */
    	            if (wRespLen > 8u)
    	            {
    	            	(void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pResponse, ((uint32)wRespLen - 8u));
    	            	pDataParams->bNoUnprocBytes += (uint8) (wRespLen - 8u);
    	            }


    	            /* Compute the Response MAC. */
    	            PH_CHECK_FAILURE_FCT(wStatus, phCryptoSym_CalculateMac(
    	                pDataParams->pCryptoDataParamsMac,
    	                (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
    	                pDataParams->pUnprocByteBuff,
    	                pDataParams->bNoUnprocBytes,
    	                aMac,
    	                &bMacLen));

    	            /* Truncate the MAC generated */
    	            (void)phalMfdfEVx_Sw_Int_TruncateMac(aMac);

    	            if (memcmp(&pResponse[wRespLen - 8u], aMac, 8) != 0)
    	            {
    	                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);

    	                wStatus = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
    	                break;
    	            }
    	        }
    	        else
    	        {
    	            /* Do Nothing. */
    	        }
    	    }
    	#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
    	    break;
    	default:
    		break;
    }
    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
    return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_Plain(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bIns, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, VAR(uint8, ANFCRL_VAR) bCommOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM status = 0U;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bWorkBuffer[32] = {0U};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTotalLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] =
    { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00U };
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNumDataBlocks = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMAC[PH_CRYPTOSYM_AES_BLOCK_SIZE] = {0U};
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMacCard[8] = {0U};
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWorkBufferLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSD = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSC = 0U;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wApduLen = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAppId[3] = { 0x00U, 0x00U, 0x00U };
    static VAR(uint8, ANFCRL_VAR) bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
    switch(bMfdfEVxState)
    {
    	case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
    	    bMacLen = 0u;
    	    (void)memset(bWorkBuffer, 0x00, 32);
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	    (void)memset(bCMAC, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    	    if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
    	        (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
    	    {
    	        bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;
    	    }
    	    else
    	    {
    	        bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;
    	    }
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA */

    	    if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
    	        (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
    	    {
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	        /* MAC(KsesAuth, Cmd [||CmdHeader][||CmdData]) and MAC is used as IV for next operation */
    	        /* check for first frame and load IV and copy only cmd */
    	        if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
    	        {
    	            /* Load Iv */
    	            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                pDataParams->pCryptoDataParamsEnc,
    	                pDataParams->bIv,
    	                bIvLen
    	            ));
    	            pDataParams->bNoUnprocBytes = 0;
    	            /* copy only cmd */
    	            bWorkBuffer[wWorkBufferLen++] = bCmdBuff[0];
    	        }
    	        else
    	        {
    	            /* copy the data for CMAC calculation from previous packet if present */
    	            (void)memcpy(bWorkBuffer, pDataParams->pUnprocByteBuff, pDataParams->bNoUnprocBytes);
    	            wWorkBufferLen = pDataParams->bNoUnprocBytes;
    	            pDataParams->bNoUnprocBytes = 0;
    	        }
    	        if (((wCmdLen + wDataLen) <= bIvLen) &&
    	            ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) &&
    	            (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
    	        {
    	            (void)memcpy(bWorkBuffer, bCmdBuff, wCmdLen);
    	            /* Really small amount of data. Calculate in one shot */
    	            (void)memcpy(&bWorkBuffer[wCmdLen], pData, wDataLen);

    	            /*Calculate CMAC over the cmd+params first */
    	            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                pDataParams->pCryptoDataParamsEnc,
    	                PH_CRYPTOSYM_MAC_MODE_CMAC,
    	                bWorkBuffer,
    	                wCmdLen + wDataLen,
    	                bCMAC,
    	                &bMacLen
    	            ));
    	            /* Update the IV */
    	            (void)memcpy(pDataParams->bIv, bCMAC, bMacLen);
    	        }
    	        else
    	        {
    	            /* check if cmd header id present */
    	            if (wCmdLen > 1U)
    	            {
    	                /* Calculate the total length of data for MAC calculation */
    	                wTmp = ((wCmdLen - 1u) + (wWorkBufferLen));
    	                /* Since bWorkbuffer can accommodate 32 bytes, check for buffer overflow */
    	                if (wTmp > 32U)
    	                {
    	                    (void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (32U - ((uint32)wWorkBufferLen)));

    	                    /* Calculate CMAC */
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsEnc,
    	                        PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT,
    	                        bWorkBuffer,
    	                        32u,
    	                        bCMAC,
    	                        &bMacLen
    	                    ));

    	                    /* Copy the remaining bCmdBuff into bWorkBuffer */
    	                    (void)memcpy(bWorkBuffer, &bCmdBuff[(32u - wWorkBufferLen) + 1U], ((uint32)wTmp - 32u));
    	                    wWorkBufferLen = (wTmp - 32u);
    	                }
    	                else
    	                {
    	                    /* if cmd header + previous data packet(if present ) is less the 32 byte copy it to
    	                     * bWorkBuffer and calculate CMAC with next frame */
    	                    (void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], ((uint32)wCmdLen - 1u));
    	                    wWorkBufferLen += (wCmdLen - 1u);
    	                }
    	            }
    	            /* complete the calculation if receive data is last frame or only one frame */
    	            if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
    	            {
    	                /*  complete CMAC calculation if there is no data */
    	                if (wDataLen == 0U)
    	                {
    	                    /* Calculate CMAC in one shot */
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsEnc,
    	                        (PH_CRYPTOSYM_MAC_MODE_CMAC | ((wTmp > 32U) ? PH_EXCHANGE_BUFFER_LAST : PH_EXCHANGE_DEFAULT)),
    	                        bWorkBuffer,
    	                        wWorkBufferLen,
    	                        bCMAC,
    	                        &bMacLen
    	                    ));
    	                }
    	                else
    	                {
    	                    wTmp = (bIvLen - (wWorkBufferLen % bIvLen));
    	                    if (wDataLen < wTmp)
    	                    {
    	                        wTmp = wDataLen;
    	                    }
    	                    (void)memcpy(&bWorkBuffer[wWorkBufferLen], pData, wTmp);

    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsEnc,
    	                        (PH_CRYPTOSYM_MAC_MODE_CMAC | ((wTmp == wDataLen) ? PH_EXCHANGE_BUFFER_LAST : PH_EXCHANGE_BUFFER_CONT)),
    	                        bWorkBuffer,
    	                        wWorkBufferLen + wTmp,
    	                        bCMAC,
    	                        &bMacLen
    	                    ));

    	                    if (wTmp != wDataLen)
    	                    {
    	                        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                            pDataParams->pCryptoDataParamsEnc,
    	                            PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST,
    	                            &pData[wTmp],
    	                            wDataLen - wTmp,
    	                            bCMAC,
    	                            &bMacLen
    	                        ));
    	                    }
    	                }
    	            }
    	            else
    	            {
    	                if (wDataLen == 0U)
    	                {
    	                    if(0u != (((wWorkBufferLen / bIvLen) * bIvLen)))
    	                    {
    	                        /* Calculate CMAC */
    	                        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                            pDataParams->pCryptoDataParamsEnc,
    	                            (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
    	                            bWorkBuffer,
    	                            ((wWorkBufferLen / bIvLen) * bIvLen),
    	                            bCMAC,
    	                            &bMacLen
    	                        ));
    	                    }
    	                    pDataParams->bNoUnprocBytes = (uint8) (wWorkBufferLen % bIvLen);
    	                    (void)memcpy(pDataParams->pUnprocByteBuff, &bWorkBuffer[wWorkBufferLen - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	                }
    	                else
    	                {
    	                    wTmp = (bIvLen - (wWorkBufferLen % bIvLen));
    	                    if (wDataLen < wTmp)
    	                    {
    	                        wTmp = wDataLen;
    	                        pDataParams->bNoUnprocBytes = (uint8) (wTmp % bIvLen);
    	                        (void)memcpy(pDataParams->pUnprocByteBuff, &pData[wTmp - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	                    }
    	                    (void)memcpy(&bWorkBuffer[wWorkBufferLen], pData, ((uint32)(wTmp)) - ((uint32)(pDataParams->bNoUnprocBytes)));

    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsEnc,
    	                        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
    	                        bWorkBuffer,
    	                        (wWorkBufferLen + (wTmp - ((uint16)(pDataParams->bNoUnprocBytes)))),
    	                        bCMAC,
    	                        &bMacLen
    	                    ));

    	                    if (wTmp != wDataLen)
    	                    {
    	                        PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                            pDataParams->pCryptoDataParamsEnc,
    	                            PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT,
    	                            &pData[wTmp],
    	                            (((wDataLen - wTmp) / bIvLen) * bIvLen),
    	                            bCMAC,
    	                            &bMacLen
    	                        ));

    	                        pDataParams->bNoUnprocBytes = (uint8) ((wDataLen - wTmp) % bIvLen);
    	                        (void)memcpy(pDataParams->pUnprocByteBuff, &pData[wDataLen - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	                    }
    	                }
    	            }
    	            if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
    	            {
    	                /* MAC value is used as IV for next operation. So update the IV if it last packet */
    	                (void)memcpy(pDataParams->bIv, bCMAC, bMacLen);
    	            }
    	        }
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

    	        /* If communication mode is set to plain
    	         * or bCommOption equals PHAL_MFDFEVX_MAC_DATA_INCOMPLETE, then MAC is only
    	         * calculated to update the init vector but is not sent with the data
    	         */
    	        if (((bCommOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_PLAIN) ||
    	            ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) == PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))
    	        {
    	            bMacLen = 0;
    	        }
    	        else
    	        {
    	            bMacLen = 8;
    	        }
    	    }
    	    else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2) &&
    	        ((bCommOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_MACD))
    	    {
    	        if ((bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
    	        {
    	            (void)memset(pDataParams->bIv, 0x00, bIvLen);
    	            pDataParams->bNoUnprocBytes = 0;
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	            /* Load Iv */
    	            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                pDataParams->pCryptoDataParamsMac,
    	                pDataParams->bIv,
    	                bIvLen
    	            ));
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	            /* Calculate MAC on Cmd || wCmdCtr || TI || CmdHeader || CmdData */
    	            bWorkBuffer[wWorkBufferLen++] = bCmdBuff[0];
    	            bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr);
    	            bWorkBuffer[wWorkBufferLen++] = (uint8) (pDataParams->wCmdCtr >> 8U);
    	            (void)memcpy(&bWorkBuffer[wWorkBufferLen], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
    	            wWorkBufferLen += PHAL_MFDFEVX_SIZE_TI;
    	        }
    	        else
    	        {
    	            (void)memcpy(bWorkBuffer, pDataParams->pUnprocByteBuff, pDataParams->bNoUnprocBytes);
    	            wWorkBufferLen = pDataParams->bNoUnprocBytes;
    	            pDataParams->bNoUnprocBytes = 0;
    	        }
    	        /* Check for presence of command header */
    	        if (wCmdLen > 1U)
    	        {
    	            /* Calculate the total length of data for MAC calculation */
    	            wTmp = ((wCmdLen - 1u) + (wWorkBufferLen));
    	            /* Since bWorkbuffer can accommodate 32 bytes, check for buffer overflow */
    	            if (wTmp > 32U)
    	            {
    	                (void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (32u - ((uint32)wWorkBufferLen)));
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	                /* Calculate CMAC */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                    pDataParams->pCryptoDataParamsMac,
    	                    PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT,
    	                    bWorkBuffer,
    	                    32u,
    	                    bCMAC,
    	                    &bMacLen
    	                ));
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	                /* Copy the remaining bCmdBuff into bWorkBuffer */
    	                (void)memcpy(bWorkBuffer, &bCmdBuff[(32u - wWorkBufferLen) + 1U], ((uint32)wTmp - 32u));
    	                wWorkBufferLen = (wTmp - 32u);
    	            }
    	            else
    	            {
    	                (void)memcpy(&bWorkBuffer[wWorkBufferLen], &bCmdBuff[1], (((uint32)wCmdLen) - 1u));
    	                wWorkBufferLen += (wCmdLen - 1u);
    	            }
    	        }
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	        if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
    	        {
    	            if (wDataLen == 0U)
    	            {
    	                /* Calculate CMAC in one shot */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                    pDataParams->pCryptoDataParamsMac,
    	                    (PH_CRYPTOSYM_MAC_MODE_CMAC | ((wTmp > 32U) ? PH_EXCHANGE_BUFFER_LAST : PH_EXCHANGE_DEFAULT)),
    	                    bWorkBuffer,
    	                    wWorkBufferLen,
    	                    bCMAC,
    	                    &bMacLen
    	                ));
    	            }
    	            else
    	            {
    	                wTmp = (PH_CRYPTOSYM_AES_BLOCK_SIZE - (wWorkBufferLen % PH_CRYPTOSYM_AES_BLOCK_SIZE));
    	                if (wDataLen < wTmp)
    	                {
    	                    wTmp = wDataLen;
    	                }
    	                (void)memcpy(&bWorkBuffer[wWorkBufferLen], pData, wTmp);

    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                    pDataParams->pCryptoDataParamsMac,
    	                    (PH_CRYPTOSYM_MAC_MODE_CMAC | ((wTmp == wDataLen) ? PH_EXCHANGE_BUFFER_LAST : PH_EXCHANGE_BUFFER_CONT)),
    	                    bWorkBuffer,
    	                    wWorkBufferLen + wTmp,
    	                    bCMAC,
    	                    &bMacLen
    	                ));

    	                if (wTmp != wDataLen)
    	                {
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsMac,
    	                        PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_LAST,
    	                        &pData[wTmp],
    	                        wDataLen - wTmp,
    	                        bCMAC,
    	                        &bMacLen
    	                    ));
    	                }
    	            }

    	            /* Truncate the MAC generated */
    	            (void)phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);
    	            bMacLen = 8;
    	        }
    	        else
    	        {
    	            if (wDataLen == 0U)
    	            {

    	                if(0u != (((wWorkBufferLen / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE)))
    	                {
    	                    /* Calculate CMAC */
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsMac,
    	                        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
    	                        bWorkBuffer,
    	                        ((wWorkBufferLen / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE),
    	                        bCMAC,
    	                        &bMacLen
    	                    ));
    	                }

    	                pDataParams->bNoUnprocBytes = (uint8) (wWorkBufferLen % PH_CRYPTOSYM_AES_BLOCK_SIZE);
    	                (void)memcpy(pDataParams->pUnprocByteBuff, &bWorkBuffer[wWorkBufferLen - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	            }
    	            else
    	            {
    	                wTmp = (PH_CRYPTOSYM_AES_BLOCK_SIZE - (wWorkBufferLen % PH_CRYPTOSYM_AES_BLOCK_SIZE));
    	                if (wDataLen < wTmp)
    	                {
    	                    wTmp = wDataLen;
    	                    pDataParams->bNoUnprocBytes = (uint8) (wTmp % PH_CRYPTOSYM_AES_BLOCK_SIZE);
    	                    (void)memcpy(pDataParams->pUnprocByteBuff, &pData[wTmp - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	                }
    	                (void)memcpy(&bWorkBuffer[wWorkBufferLen], pData, (((uint32)(wTmp)) - (uint32)(pDataParams->bNoUnprocBytes)));

    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                    pDataParams->pCryptoDataParamsMac,
    	                    (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT),
    	                    bWorkBuffer,
    	                    (wWorkBufferLen + (wTmp - ((uint16)(pDataParams->bNoUnprocBytes)))),
    	                    bCMAC,
    	                    &bMacLen
    	                ));

    	                if (wTmp != wDataLen)
    	                {
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsMac,
    	                        PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_BUFFER_CONT,
    	                        &pData[wTmp],
    	                        (((wDataLen - wTmp) / PH_CRYPTOSYM_AES_BLOCK_SIZE) * PH_CRYPTOSYM_AES_BLOCK_SIZE),
    	                        bCMAC,
    	                        &bMacLen
    	                    ));

    	                    pDataParams->bNoUnprocBytes = (uint8) ((wDataLen - wTmp) % PH_CRYPTOSYM_AES_BLOCK_SIZE);
    	                    (void)memcpy(pDataParams->pUnprocByteBuff, &pData[wDataLen - pDataParams->bNoUnprocBytes], pDataParams->bNoUnprocBytes);
    	                }
    	            }
    	        }
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	        if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) == PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
    	        {
    	            bMacLen = 0;
    	        }
    	    }
    	    else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE)
    	    {
    	        if ((bCommOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_MACD)
    	        {
    	            if (bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME)
    	            {
    	                pDataParams->bNoUnprocBytes = 0;
    	            }
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	            /* Load Iv */
    	            PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                pDataParams->pCryptoDataParamsEnc,
    	                pDataParams->bIv,
    	                bIvLen
    	            ));

    	            /* Encipher all the data except the last odd block */
    	            wIndex = 0;
    	            wNumDataBlocks = (wDataLen / bIvLen);

    	            /* Need to put in loop because we dont know how big the buffer is.
    	            Also we really dont need the encrypted data. Only MAC is required
    	            which is the last block of the cipher operation */
    	            while (0U != (wNumDataBlocks))
    	            {
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
    	                    pDataParams->pCryptoDataParamsEnc,
    	                    PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
    	                    &pData[wIndex],
    	                    bIvLen,
    	                    bWorkBuffer
    	                ));

    	                (void)memcpy(pDataParams->bIv, bWorkBuffer, bIvLen);

    	                /* Load Iv */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                    pDataParams->pCryptoDataParamsEnc,
    	                    pDataParams->bIv,
    	                    bIvLen
    	                ));
    	                wNumDataBlocks--;
    	                wIndex = wIndex + bIvLen;
    	            }

    	            wWorkBufferLen = wDataLen % bIvLen;

    	            /* Check and encrypt the residual bytes of data */
    	            if (0U != (wWorkBufferLen))
    	            {
    	                (void)memcpy(bWorkBuffer, &pData[wIndex], wWorkBufferLen);

    	                /* Apply padding. Always padding mode 1 is used while calculating MAC
    	                in AUTHENTICATE mode*/
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_ApplyPadding(
    	                    PH_CRYPTOSYM_PADDING_MODE_1,
    	                    bWorkBuffer,
    	                    wWorkBufferLen,
    	                    bIvLen,
    	                    (uint16)sizeof(bWorkBuffer),
    	                    bWorkBuffer,
    	                    &wTmp
    	                ));

    	                /* IV is already loaded in the while loop. Encipher the last block */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
    	                    pDataParams->pCryptoDataParamsEnc,
    	                    PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_LAST,
    	                    bWorkBuffer,
    	                    wTmp,
    	                    bWorkBuffer
    	                ));
    	            }

    	            /* If communication mode is set to plain
    	            * or bCommOption equals PHAL_MFDFEVX_MAC_DATA_INCOMPLETE, then MAC is only
    	            * calculated to update the init vector but is not sent with the data
    	            */
    	            if ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) != PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)
    	            {
    	                /* Reset the IV */
    	                (void)memset(pDataParams->bIv, 0x00, bIvLen);
    	                bMacLen = 0x04;
    	            }

    	            /*bMacLen = ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) == PHAL_MFDFEVX_MAC_DATA_INCOMPLETE) ? 0: 0x04;       */

    	            /* MAC is the MSB bytes of the last block */
    	            (void)memcpy(bCMAC, bWorkBuffer, 4);
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	        }
    	    }
    	    else
    	    {
    	        /* Else statement due to else if above. */
    	        bMacLen = 0;
    	    }

    	    if (bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE)
    	    {
    	        if (0U != (pDataParams->bWrappedMode))
    	        {
    	            wFrameLen = PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE;
    	        }
    	        else
    	        {
    	            wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
    	        }
    	    }
    	    else
    	    {
    	        /* Get the Frame length */
    	        PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
    	            pDataParams,
    	            &wFSD,
    	            &wFSC
    	        ));

    	        if (0U != (pDataParams->bWrappedMode))
    	        {
    	            wFrameLen = wFSC - 9u;
    	        }
    	        else
    	        {
    	            wFrameLen = wFSC - 4u;
    	        }
    	    }

    	    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
    	    /*no break*/
    	case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
    	    /* Update wTotalLen = datalen + CMAClen*/
    	    wTotalLen = wDataLen + bMacLen;
    	    if (wTotalLen == 0x0000U)
    	    {
    	        /* Single frame cmd without any data. Just send it */
    	    	PH_CHECK_INPROCESS_FCT(status,phalMfdfEVx_ExchangeCmd(
    	            pDataParams,
    	            pDataParams->pPalMifareDataParams,
    	            pDataParams->bWrappedMode,
    	            bCmdBuff,
    	            wCmdLen,
    	            &pRecv,
    	            &wRxlen
    	        ));
    	        if (((status & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
    	            ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
    	        {
    	            /* Reset authentication status */
    	            if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
    	                (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
    	                (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
    	            {
    	                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	            }

    	            statusTmp = PH_ADD_COMPCODE(status, PH_COMP_AL_MFDFEVX);
    	            break;
    	        }
    	        if (wRxlen > 32U)
    	        {
    	        	statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	        	break;
    	        }
    	        (void)memcpy(bWorkBuffer, pRecv, wRxlen);
    	    }
    	    else
    	    {
    	        if (bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE)
    	        {
    	            if (0U != (pDataParams->bWrappedMode))
    	            {
    	                wFrameLen = PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE;
    	            }
    	            else
    	            {
    	                wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
    	            }
    	        }
    	        else
    	        {
    	            /* Get the Frame length */
    	        	PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
    	                pDataParams,
    	                &wFSD,
    	                &wFSC
    	            ));

    	            if (0U != (pDataParams->bWrappedMode))
    	            {
    	                wFrameLen = wFSC - 9u;
    	            }
    	            else
    	            {
    	                wFrameLen = wFSC - 4u;
    	            }
    	        }

    	        wTmp = wTotalLen;

    	        if (wTmp <= (wFrameLen - wCmdLen))
    	        {
    	            wApduLen = ((wCmdLen == 0x01U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0U : PHAL_MFDFEVX_WRAP_HDR_LEN;
    	            wCmdLen = ((wCmdLen == 0x01U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0u : wCmdLen;

    	            /* Send in one shot */
    	            if (0U != (pDataParams->bWrappedMode))
    	            {
    	                pApdu[1] = bCmdBuff[0]; /* DESFire cmd code in INS */

    	                if(wCmdLen > 0U)
    	                {
    	                    pApdu[4] = (uint8) (wCmdLen + wTotalLen) - 0x01u;
    	                }

        	            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
        	            return PH_STATUS_INPROCESS;
    	            }
    	            else
    	            {
    	            	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
                        return PH_STATUS_INPROCESS;
    	            }
    	        }
    	        else
    	        {
    	        	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
    	        	return PH_STATUS_INPROCESS;
    	        }
    	    }
    	    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
    	    return PH_STATUS_INPROCESS;
    	    /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_FIRST |
                    (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                    pApdu,
                    wApduLen,
                    &pRecv,
                    &wRxlen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
            return PH_STATUS_INPROCESS;
            /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
            if (wCmdLen > 0U)
            {
                PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT |
                    (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE))) ? PH_EXCHANGE_TXCHAINING : 0u),
                    &bCmdBuff[1],
                    wCmdLen - 1u,
                    &pRecv,
                    &wRxlen));
            }
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
            return PH_STATUS_INPROCESS;
            /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
    	    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_CONT |
                (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                pData,
                wDataLen,
                &pRecv,
                &wRxlen));
    	    PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
            return PH_STATUS_INPROCESS;
            /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
            if (bMacLen != 0x00U)
            {
                PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                        pDataParams->pPalMifareDataParams,
                        PH_EXCHANGE_BUFFER_CONT |
                        (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                        bCMAC,
                        bMacLen,
                        &pRecv,
                        &wRxlen));
            }
            PH_BREAK_ON_FAILURE(statusTmp);
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
            return PH_STATUS_INPROCESS;
            /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_FIRST |
                    (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                    bCmdBuff,
                    wCmdLen,
                    &pRecv,
                    &wRxlen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
            return PH_STATUS_INPROCESS;
            /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
                if(bMacLen != 0x00U)
                {
                    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                            pDataParams->pPalMifareDataParams,
                            PH_EXCHANGE_BUFFER_CONT |
                            (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                            pData,
                            wDataLen,
                            &pRecv,
                            &wRxlen));
                }
                PH_BREAK_ON_FAILURE(statusTmp);
                bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
                return PH_STATUS_INPROCESS;
                /* no break */

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
    		if (0U != (pDataParams->bWrappedMode))
    		{
				/* Le byte */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
					pDataParams->pPalMifareDataParams,
					PH_EXCHANGE_BUFFER_LAST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0U),
					&pApdu[2],
					(uint16) ((((pDataParams->dwPayLoadLen) > 0xFEU) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0x02U : 0x01U),
					&pRecv,
					&wRxlen));
				PH_BREAK_ON_FAILURE(statusTmp);
    		}
    		else
    		{
        		if(bMacLen == 0x00U)
        		{
        			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                        pDataParams->pPalMifareDataParams,
                        PH_EXCHANGE_BUFFER_LAST |
                        (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
                        pData,
                        wDataLen,
                        &pRecv,
                        &wRxlen));
        			PH_BREAK_ON_FAILURE(statusTmp);
        		}
        		else
        		{
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
    					pDataParams->pPalMifareDataParams,
    					PH_EXCHANGE_BUFFER_LAST |
    					(((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (0U != ((bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE)))) ? PH_EXCHANGE_TXCHAINING : 0u),
    					bCMAC,
    					bMacLen,
    					&pRecv,
    					&wRxlen));
    				PH_BREAK_ON_FAILURE(statusTmp);
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
        		}
    		}
			if (0U != (pDataParams->bWrappedMode))
			{
				status = pRecv[wRxlen - 1u];
				wRxlen -= 2u;
			}
			else
			{
				status = pRecv[0];
				pRecv++; /* Increment pointer to point only to data */
				wRxlen -= 1u;
			}

			if ((status != PH_ERR_SUCCESS) &&
				((status & PH_ERR_MASK) != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
			{

				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
				{
					(void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}

				statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, (uint8) status);
				break;
			}

			(void)memcpy(bWorkBuffer, pRecv, wRxlen);

			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
			return PH_STATUS_INPROCESS;

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD9:
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
            /* Send command and data. Chain data to PICC */
            if (wDataLen > 0x0200U)
            {
        		PH_CHECK_INPROCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_SendDataAndAddDataToPICC(
                    pDataParams,
                    bIns,
                    bCmdBuff,
                    wCmdLen,
                    pData,
                    wDataLen,
                    bCMAC,
                    bMacLen,
                    bWorkBuffer,
                    &wRxlen
                ));
            }
            else
            {
        		PH_CHECK_INPROCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_SendDataToPICC(
                    pDataParams,
                    bIns,
                    (bCommOption & PHAL_MFDFEVX_MAC_DATA_INCOMPLETE),
                    bCmdBuff,
                    wCmdLen,
                    pData,
                    wDataLen,
                    bCMAC,
                    bMacLen,
                    bWorkBuffer,
                    &wRxlen
                ));
            }

            if ((statusTmp & PH_ERR_MASK) == PHAL_MFDFEVX_RESP_CHAINING)
            {
                break;
            }

            if (((statusTmp & PH_ERR_MASK) != PH_ERR_SUCCESS) &&
                ((statusTmp & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
            {
                /* Reset authentication status */
                if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
                    (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
                    (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
                {
                    (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
                }
                break;
            }
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/

            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
            /*no break*/

    	case PHAL_MFDFEVX_SW_INT_STATE_CMD10:
    		bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	    (void)memset(bCMacCard, 0x00, 8);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

    	    if ((status == PH_ERR_SUCCESS) && ((bCommOption & PHAL_MFDFEVX_AUTHENTICATE_RESET) == PHAL_MFDFEVX_AUTHENTICATE_RESET))
    	    {
    	        /* Reset authentication status */
    	        if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
    	            (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
    	            (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2))
    	        {
    	            phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	        }
    	        return PH_ERR_SUCCESS;
    	    }

    	    /* Verify the MAC. MAC is not received if in 0x0A MAC'd mode */
    	    if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
    	        (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
    	    {
    	        if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)  /* if no chaining ongoing */
    	        {
    	            /*
    	             * In case of delete app, check whether the command is called at APP level or PICC level.
    	             * 1. At APP level, the MAC is not returned.
    	             * 2. At PICC level, 8 bytes MAC is returned.
    	             * So to check whether its in APP level or PICC level. To do this, check for pDataParams->pAid. If its 0x00, then its PICC level
    	             * else its in APP level.
    	             */
    	            if (PHAL_MFDFEVX_CMD_DELETE_APPLN == bCmdBuff[0])
    	            {
    	                /* if PICC level selected */
    	                if (memcmp(pDataParams->pAid, bAppId, 3) == 0x00)
    	                {
    	                    /* If NO Mac is returned */
    	                    if (wRxlen < 8U)
    	                    {
    	                        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                    }
    	                }
    	                /* if APP level selected */
    	                else
    	                {
    	                    /* Before returning status code, reset auth and set app ID to Master APP */
    	                    phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);

    	                    if ((memset(pDataParams->pAid, 0x00, 3)) == NULL)
    	                    {
    	                        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_MFDFEVX);
    	                    }
    	                    /* return error if Mac is returned */
    	                    if (wRxlen >= 8U)
    	                    {
    	                        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                    }
    	                    else
    	                    {
    	                        return PH_ERR_SUCCESS;
    	                    }
    	                }
    	            }
    	            else
    	            {
    	                if (wRxlen < 8U) /* If no CMAC received */
    	                {
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                }
    	            }
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	            if ((bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
    	            {
    	                /* Load IV */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                    pDataParams->pCryptoDataParamsEnc,
    	                    pDataParams->bIv,
    	                    bIvLen
    	                ));
    	            }
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	            if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS)
    	            {
    	                /* copy CMAC received from card*/
    	                (void)memcpy(bCMacCard, &bWorkBuffer[wRxlen - 8u], 8);
    	                wRxlen -= 8u;
    	                /* Copy the status byte at the end */
    	                bWorkBuffer[wRxlen] = (uint8) status;
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	                /* verify the MAC */
    	                PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                    pDataParams->pCryptoDataParamsEnc,
    	                    (PH_CRYPTOSYM_MAC_MODE_CMAC),
    	                    bWorkBuffer,
    	                    wRxlen + 1U,
    	                    bCMAC,
    	                    &bMacLen
    	                ));

    	                if (memcmp(bCMacCard, bCMAC, 8) != 0)
    	                {
    	                    phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
    	                }

    	                /* Update IV */
    	                (void)memcpy(pDataParams->bIv, bCMAC, bIvLen);
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	            }
    	        }
    	    }
    	    else if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
    	    {
    	        /*
    	        * In case of delete app, check whether the command is called at APP level or PICC level.
    	        * 1. At APP level, the MAC is not returned.
    	        * 2. At PICC level, 8 bytes MAC is returned.
    	        * So to check whether its in APP level or PICC level. To do this, check for pDataParams->pAid. If its 0x00, then its PICC level
    	        * else its in APP level.
    	        */
    	        if (PHAL_MFDFEVX_CMD_DELETE_APPLN == bCmdBuff[0])
    	        {
    	            /* If PICC level is selected */
    	            if (memcmp(pDataParams->pAid, bAppId, 3) == 0x00)
    	            {
    	                /* If NO Mac is returned */
    	                if (wRxlen < 8U)
    	                {
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                }
    	            }
    	            /* if APP level selected */
    	            else
    	            {
    	                /* Before returning status code, reset auth and set app ID to Master APP */
    	                phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);

    	                if ((memset(pDataParams->pAid, 0x00, 3)) == NULL)
    	                {
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_MFDFEVX);
    	                }
    	                /* return error if Mac is returned */
    	                if (wRxlen >= 8U)
    	                {
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                }
    	                else
    	                {
    	                    /* Increment the command counter. */
    	                    pDataParams->wCmdCtr++;
    	                    return PH_ERR_SUCCESS;
    	                }
    	            }
    	        }
    	        if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)  /* if no chaining ongoing */
    	        {

    	            if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS)
    	            {
    	                /* Increment the command counter.
    	                *  This increments irrespective of Plain mode or MAC mode.
    	                */
    	                pDataParams->wCmdCtr++;
    	            }

    	            if ((bCommOption & 0xF0U) == PHAL_MFDFEVX_COMMUNICATION_MACD)
    	            {
    	                if (wRxlen < 8U) /* If no CMAC received */
    	                {
    	                    return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	                }
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    	                if ((bCmdBuff[0] != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME))
    	                {
    	                    /* Load IV */
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
    	                        pDataParams->pCryptoDataParamsMac,
    	                        pDataParams->bIv,
    	                        bIvLen
    	                    ));
    	                }

    	                if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS)
    	                {
    	                    /* copy CMAC received from card*/
    	                    (void)memcpy(bCMacCard, &bWorkBuffer[wRxlen - 8u], 8);
    	                    wRxlen -= 8u;

    	                    /*
    	                    * Calculate MAC on RC || wCmdCtr || TI || RespData
    	                    * bWorkBuffer is used as receive buffer so pDataParams->pUnprocByteBuff is used
    	                    */
    	                    pDataParams->bNoUnprocBytes = 0x00;
    	                    pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = 0x00;
    	                    pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr);
    	                    pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes++] = (uint8) (pDataParams->wCmdCtr >> 8U);
    	                    (void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], pDataParams->bTi, PHAL_MFDFEVX_SIZE_TI);
    	                    pDataParams->bNoUnprocBytes += PHAL_MFDFEVX_SIZE_TI;

    	                    /* TBD:Required */
    	                    (void)memcpy(&pDataParams->pUnprocByteBuff[pDataParams->bNoUnprocBytes], bWorkBuffer, wRxlen);
    	                    pDataParams->bNoUnprocBytes += (uint8) wRxlen;

    	                    /* verify the MAC */
    	                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
    	                        pDataParams->pCryptoDataParamsMac,
    	                        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
    	                        pDataParams->pUnprocByteBuff,
    	                        pDataParams->bNoUnprocBytes,
    	                        bCMAC,
    	                        &bMacLen
    	                    ));

    	                    /* Truncate the MAC generated */
    	                    phalMfdfEVx_Sw_Int_TruncateMac(bCMAC);

    	                    /* Compare the CMAC from card and CMAC calculated */
    	                    if (memcmp(bCMacCard, bCMAC, 8) != 0)
    	                    {
    	                        phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
    	                        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
    	                    }
    	                }
#endif /*NXPBUILD__PHAL_MFDFEVX_NDA*/
    	            }
    	        }

    	    }
    	    else
    	    {
    	        /* Should not get more bytes than the status bytes in case
    	        of no authentication */
    	        if (wRxlen > 0U)
    	        {
    	            return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
    	        }
    	    }
    	    break;
    	default:
    		break;
    }

	pApdu[0] = PHAL_MFDFEVX_WRAPPEDAPDU_CLA;
	pApdu[1] = 0x00U;
	pApdu[2] = PHAL_MFDFEVX_WRAPPEDAPDU_P1;
	pApdu[3] = PHAL_MFDFEVX_WRAPPEDAPDU_P2;
	pApdu[4] = 0x00U;
    wApduLen = 0U;
    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
    return statusTmp;
}

FUNC(void, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ResetAuthStatus(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    (void)memset(pDataParams->bSesAuthENCKey, 0x00, (size_t)sizeof(pDataParams->bSesAuthENCKey));
    (void)memset(pDataParams->bSesAuthMACKey, 0x00, (size_t)sizeof(pDataParams->bSesAuthMACKey));
    pDataParams->bKeyNo = 0xFF;
    (void)memset(pDataParams->bIv, 0x00, (size_t)sizeof(pDataParams->bIv));
    pDataParams->bAuthMode = PHAL_MFDFEVX_NOT_AUTHENTICATED;
    pDataParams->bCryptoMethod = 0xFF;
    pDataParams->wCmdCtr = 0;
    (void)memset(pDataParams->bTi, 0x00, PHAL_MFDFEVX_SIZE_TI);
    pDataParams->bNoUnprocBytes = 0;
    pDataParams->bLastBlockIndex = 0;
    (void)phTMIUtils_ActivateTMICollection((phTMIUtils_t *) pDataParams->pTMIDataParams, PH_TMIUTILS_RESET_TMI);

    pDataParams->bCmdCode = PHAL_MFDFEVX_CMD_INVALID;

    /* Update the authentication state if VCA PC feature is required by the application. */
    if (pDataParams->pVCADataParams != NULL)
    {
        (void)phalVca_SetSessionKeyUtility((phalVca_Sw_DataParams_t *) pDataParams->pVCADataParams,
            pDataParams->bSesAuthENCKey,
            pDataParams->bAuthMode);
    }

}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_SendDataToPICC(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, 
	VAR(uint8, ANFCRL_VAR) bIns, 
	VAR(uint8, ANFCRL_VAR) bCommOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmd, 
	VAR(uint16, ANFCRL_VAR) wCmdLen, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, 
	VAR(uint16, ANFCRL_VAR) wDataLen, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bLastChunk, 
	VAR(uint16, ANFCRL_VAR) wLastChunkLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
	/* Utility function to send data to PICC if more then wFrameLen*/
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndexDataLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[7] = { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00, 0x00, 0x00 };
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bExtended7816 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCommOptionTmp = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSD = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSC = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataToBeSent = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCopyDataLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmpDataLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCopyLastChunkLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmpLastChunkLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndexLastChunkLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wApduHeaderLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLeFieldLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmpCmdLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndexCmdLen = 1U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmpData = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTemLen = 0U;
	static VAR(uint8, ANFCRL_VAR) bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch (bMfdfEVxState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			wTmpCmdLen = wCmdLen;
			wIndexDataLen = 0;
			bExtended7816 = 0;
			wApduHeaderLen = 0;
		    if (bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE)
		    {
		        if (0U != (pDataParams->bWrappedMode))
		        {
		            wFrameLen = PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE;
		            wApduHeaderLen = PHAL_MFDFEVX_WRAP_HDR_LEN;
		        }
		        else
		        {
		            wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
		        }
		    }
		    else
		    {
		        /* Get the Frame length */
		        PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
		            pDataParams,
		            &wFSD,
		            &wFSC
		        ));

		        if (0U != (pDataParams->bWrappedMode))
		        {
		            bExtended7816 = (uint8)( (pDataParams->dwPayLoadLen > 0xFEU) ? 1U : 0U);
		            /* if Lc is more then 0xFF, length of Lc should be 3 bytes */
		            wApduHeaderLen = (uint16)(PHAL_MFDFEVX_WRAP_HDR_LEN) + ((bExtended7816 != 0U) ? 2U : 0U);
		        }
		        wFrameLen = wFSC - 4u;
		    }

		    /* If Ins mode and wrapped mode are enable Le is sent with the last packet. So update Le when only last packet is sent */
		    wLeFieldLen = ((bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE) && (pDataParams->bWrappedMode == 1U)) ? 1U : 0U;

		    /* Send the data to PICC */
		    wTmpDataLen = wDataLen;
		    wTmpLastChunkLen = wLastChunkLen;
		    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			/*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
	        /* In case of wrapped mode, cmd byte is added as a part of APDU Header. */
	        wIndexCmdLen = (wApduHeaderLen != 0U) ? 1u : 0u;

	        /* this If condition is added to suppress QAC warning */
	        wTemLen = wTmpCmdLen;
	        if (wTmpCmdLen > 0U)
	        {
	            wTemLen = wTmpCmdLen - wIndexCmdLen;
	        }
	        /* If Ins mode and wrapped mode are enable Le is sent with the last packet */
	        if ((pDataParams->bWrappedMode != 0x00U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && ((wTmpDataLen + wTmpLastChunkLen + wTemLen) <= wFrameLen))
	        {
	            wLeFieldLen = 1U + (uint16)bExtended7816;
	        }
	        if (wTmpDataLen > 0U)
	        {
	            wCopyDataLen = (wTmpDataLen < (wFrameLen - (wTemLen + wApduHeaderLen + wLeFieldLen))) ?
	                wTmpDataLen : (wFrameLen - (wTemLen + wApduHeaderLen + wLeFieldLen));
	        }

	        if (wTmpLastChunkLen > 0U)
	        {
	            wTmpData = wTemLen + wCopyDataLen + wApduHeaderLen + wLeFieldLen;
	            wCopyLastChunkLen = (wTmpLastChunkLen < (wFrameLen - wTmpData)) ? wTmpLastChunkLen : (wFrameLen - wTmpData);
	        }

	        /* remaining data to be sent */
	        /* this If condition is added to suppress QAC warning */
	        wDataToBeSent = (wTmpDataLen - wCopyDataLen) + (wTmpLastChunkLen - wCopyLastChunkLen);

	        wTmpCmdLen = ((wTmpCmdLen == 0x01U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE)) ? 0U : wTmpCmdLen;

	        bCommOptionTmp = (uint8) (((wDataToBeSent == 0U) && (bCommOption == 0U)) ? 0U : 1U);

	        if (0U != (pDataParams->bWrappedMode))
	        {
	            pApdu[1] = pCmd[0]; /* DESFire cmd code in INS */

	            /* in case of ISO chaining mode, total length of data should be sent with the first frame*/
	            if ((bExtended7816 != 0U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE))
	            {
	                pDataParams->dwPayLoadLen = pDataParams->dwPayLoadLen + wTemLen;
	                pApdu[4] = (uint8) ((pDataParams->dwPayLoadLen >> 16U) & 0xFFU);
	                pApdu[5] = (uint8) ((pDataParams->dwPayLoadLen >> 8U) & 0xFFU);
	                pApdu[6] = (uint8) (pDataParams->dwPayLoadLen & 0xFFU);
	            }
	            else
	            {
	                pApdu[4] =  ((uint8)wTemLen + ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) ? (uint8)(pDataParams->dwPayLoadLen) : ((uint8)wCopyDataLen + (uint8)wCopyLastChunkLen)));
	            }

	            wApduHeaderLen = ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (wTemLen == 0U)) ? 0U : wApduHeaderLen;

	            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
	            return PH_STATUS_INPROCESS;
	        }
	        else
	        {
	            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
	            return PH_STATUS_INPROCESS;
	        }
	        /*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
		    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_FIRST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                pApdu,
                wApduHeaderLen,
                &pRecv,
                pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
            /*no break*/

		case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                &pCmd[wIndexCmdLen],
                wTemLen,
                &pRecv,
                pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
            /*no break*/

		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
		    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pData[wIndexDataLen],
                    wCopyDataLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
            /*no break*/

		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
            /* send last chunk */
		    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &bLastChunk[wIndexLastChunkLen],
                    wCopyLastChunkLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);

            wLeFieldLen = ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? 0U: wLeFieldLen;

            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
            /*no break*/

        case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
            /* Le byte */
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_LAST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pApdu[2],
                    wLeFieldLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);

            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
            return PH_STATUS_INPROCESS;
            /*no break*/

		case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
            /* send cmd */
		    PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_FIRST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    pCmd,
                    wTmpCmdLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            if(0U != (wCopyDataLen))
            {
                bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
                return PH_STATUS_INPROCESS;
            }

            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
            return PH_STATUS_INPROCESS;
            /*no break*/

	    case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
            /*  send data */
	        PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pData[wIndexDataLen],
                    wCopyDataLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
            return PH_STATUS_INPROCESS;
            /*no break*/

		case PHAL_MFDFEVX_SW_INT_STATE_CMD9:
			/* send last chunk */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U)) ? PH_EXCHANGE_TXCHAINING : 0U),
				&bLastChunk[wIndexLastChunkLen],
				wCopyLastChunkLen,
				&pRecv,
				pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);

			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
			/*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD10:
	        /* copy number of data sent */
	        wIndexDataLen += wCopyDataLen;
	        wIndexLastChunkLen += wCopyLastChunkLen;

	        /* copy the remaining data to be sent */
	        /* this If condition is added to suppress QAC warning */
	        if (wTmpDataLen > 0U)
	        {
	            wTmpDataLen = wTmpDataLen - wCopyDataLen;
	        }

	        /* this If condition is added to suppress QAC warning */
	        if (wTmpLastChunkLen > 0U)
	        {
	            wTmpLastChunkLen = wTmpLastChunkLen - wCopyLastChunkLen;
	        }

	        wCopyDataLen = 0U;
	        wCopyLastChunkLen = 0U;

	        /* in case of 14443-4 chaining R-block that indicates a positive acknowledge */
	        if ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) && (bCommOptionTmp != 0U))
	        {
	            bStatusByte = (uint8) (((pRecv[0] & 0xF0U) == 0xA0U) ? PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME : ((uint8)PH_ERR_PROTOCOL_ERROR));
	        }
	        else
	        {
	            /* validate the response byte */
	            if (0U != (pDataParams->bWrappedMode))
	            {
	                if((uint32)(*pRespLen) >= 2U)
	                {
	                    if((uint32)(*pRespLen) != 2U)
	                    {
	                        (void)memcpy(pResp, pRecv, (uint32)(*pRespLen) - 2U);
	                    }
	                    bStatusByte = pRecv[(*pRespLen) - 1U];
	                    (*pRespLen) -= 2u;
	            	}
	            }
	            else
	            {
	                if((uint32)(*pRespLen) >= 1U)
	                {
	                    if((uint32)(*pRespLen) != 1U)
	                    {
	                        (void)memcpy(pResp, &pRecv[1], (uint32)(*pRespLen) - 1U);
	                    }
	                    bStatusByte = pRecv[0];
	                    (*pRespLen) -= 1u;
	                }
	            }
	        }

	        if ((bStatusByte != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME) &&
	            (bStatusByte != PH_ERR_SUCCESS))
	        {
	            /* Reset authentication status */
	            if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
	                (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
	            {
	                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
	            }

	            statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, bStatusByte);
	            break;
	        }

	        /* Success returned even before writing all data? protocol error */
	        if ((bStatusByte == PH_ERR_SUCCESS) && (bCommOptionTmp != 0U))
	        {
	            /* Reset authentication status */
	            if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
	                (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
	            {
	                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
	            }

	            statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
	            break;
	        }

	        if (bStatusByte != 0x00U)
	        {
	            pCmd[0] = PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME;
	            wTmpCmdLen = ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) ? 0U: 1U);
	            wApduHeaderLen = ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE) ? 0U : wApduHeaderLen);
	        }
	        if (0U != wDataToBeSent)
	        {
	        	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
	        	return PH_STATUS_INPROCESS;
	        }
	        statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, bStatusByte);
	        break;
		default:
			break;
	}
	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_SendDataAndAddDataToPICC(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bIns, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmd,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddData, VAR(uint16, ANFCRL_VAR) wAddDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen)
{
    /* Utility function to send encrypted data to PICC as and when it is available from SAM */
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStatusByte = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLeft = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[7] =
    { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00, 0x00, 0x00 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pLe[2] = { 0x00, 0x00 };
    static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSD = 0;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFSC = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wrappedApduHeaderLen = PHAL_MFDFEVX_WRAP_HDR_LEN;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wrappedApduTrailerLen = 1;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsExtended7816 = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wHeaderIdx = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdIdx = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wAddDataIdx = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTrailerIdx = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWrappedApduHeaderLenLeft = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWrappedApduTrailerLenLeft = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLenLeft = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wAddDataLenLeft = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wAddDataLenTotal = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLenTotal = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLenTotal = 0;
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wMoreDataToTransmit = 0;
    static VAR(uint8, ANFCRL_VAR) bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;

	switch (bMfdfEVxState)
	{
		case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
			/*Reset variables before using*/
			wIndex = 0;
			wrappedApduHeaderLen = PHAL_MFDFEVX_WRAP_HDR_LEN;
			wrappedApduTrailerLen = 1;
			wHeaderIdx = 0;
			wCmdIdx = 0;
			wAddDataIdx = 0;
			wTrailerIdx = 0;

		    if (bIns != PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED)
		    {
		            wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
		    }
		    else
		    {
		        /* Get the Frame length */
		        PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Sw_Int_GetFrameLength(
		            pDataParams,
		            &wFSD,
		            &wFSC
		        ));

		        if (0U != (pDataParams->bWrappedMode))
		        {
		            bIsExtended7816 = (((wCmdLen + wDataLen + wAddDataLen - 0x01u) > 255U) ? 1U : 0U);
		            wrappedApduHeaderLen += ((bIsExtended7816 != 0U) ? 2U : 0U);
		            wrappedApduTrailerLen += ((bIsExtended7816 != 0U) ? 1U : 0U);
		        }
		        wFrameLen = wFSC - 4u;
		    }

		    wWrappedApduHeaderLenLeft = wrappedApduHeaderLen;
		    wCmdLenTotal = (((pDataParams->bWrappedMode) != 0x00U ) ? ((wCmdLen > 0U) ? (wCmdLen - 1U) : 0U) : wCmdLen); /* subtract instruction byte */
		    wCmdLenLeft = wCmdLenTotal;
		    wDataLenTotal = wDataLen;
		    wDataLeft = wDataLen;
		    wAddDataLenTotal = wAddDataLen;
		    wAddDataLenLeft = wAddDataLenTotal;
		    wWrappedApduTrailerLenLeft = wrappedApduTrailerLen;
		    bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
			/*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD1:

	        if (0U != (pDataParams->bWrappedMode))
	        {
	            if (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED)
	            {
	                if (wWrappedApduHeaderLenLeft > 0U)
	                {
	                    wrappedApduHeaderLen = ((wFrameLen / wWrappedApduHeaderLenLeft) != 0x00U) ? wWrappedApduHeaderLenLeft : (wFrameLen % wWrappedApduHeaderLenLeft);
	                }
	                else
	                {
	                    wrappedApduHeaderLen = 0u;
	                }
	                if (wCmdLenLeft > 0U)
	                {
	                    wCmdLen = (((wFrameLen - wrappedApduHeaderLen) / wCmdLenLeft) != 0x00U) ? wCmdLenLeft : ((wFrameLen - wrappedApduHeaderLen) % wCmdLenLeft);
	                }
	                else
	                {
	                    wCmdLen = 0u;
	                }
	                if (wDataLeft > 0U)
	                {
	                    wDataLen = (((wFrameLen - wrappedApduHeaderLen - wCmdLen) / wDataLeft) != 0x00U) ? wDataLeft : ((wFrameLen - wrappedApduHeaderLen - wCmdLen) % wDataLeft);
	                }
	                else
	                {
	                    wDataLen = 0u;
	                }
	                if (wAddDataLenLeft > 0U)
	                {
	                    wAddDataLen = (((wFrameLen - wrappedApduHeaderLen - wCmdLen - wDataLen) / wAddDataLenLeft) != 0x00U)
	                    ? wAddDataLenLeft
	                    : ((wFrameLen - wrappedApduHeaderLen - wCmdLen - wDataLen) % wAddDataLenLeft);
	                }
	                else
	                {
	                    wAddDataLen = 0;
	                }
	                if (wWrappedApduTrailerLenLeft > 0U)
	                {
	                    wrappedApduTrailerLen = (0u != ((wFrameLen - wrappedApduHeaderLen - wCmdLen - wDataLen - wAddDataLen) / wWrappedApduTrailerLenLeft))
	                    ? wWrappedApduTrailerLenLeft
	                    : ((wFrameLen - wrappedApduHeaderLen - wCmdLen - wDataLen - wAddDataLen) % wWrappedApduTrailerLenLeft);
	                }
	            }
	            else
	            {
	                if (wWrappedApduHeaderLenLeft > 0U)
	                {
	                    wrappedApduHeaderLen = (0u !=(wFrameLen / wWrappedApduHeaderLenLeft)) ? wWrappedApduHeaderLenLeft : (wFrameLen % wWrappedApduHeaderLenLeft);
	                }
	                else
	                {
	                    wrappedApduHeaderLen = 0;
	                }
	                if (wWrappedApduTrailerLenLeft > 0U)
	                {
	                    wrappedApduTrailerLen = ((0u != ((wFrameLen - wrappedApduHeaderLen) / wWrappedApduTrailerLenLeft))
	                    ? wWrappedApduTrailerLenLeft
	                    : ((wFrameLen - wrappedApduHeaderLen) % wWrappedApduTrailerLenLeft));
	                }
	                else
	                {
	                    wrappedApduTrailerLen = 0;
	                }
	                if (wCmdLenLeft > 0U)
	                {
	                    wCmdLen = (0u != ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen) / wCmdLenLeft))
	                    ? wCmdLenLeft
	                    : ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen) % wCmdLenLeft);
	                }
	                else
	                {
	                    wCmdLen = 0;
	                }
	                if (wDataLeft > 0U)
	                {
	                    wDataLen = (0u != ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen - wCmdLen) / wDataLeft))
	                    ? wDataLeft
	                    : ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen - wCmdLen) % wDataLeft);
	                }
	                else
	                {
	                    wDataLen = 0;
	                }
	                if (wAddDataLenLeft > 0U)
	                {
	                    wAddDataLen = (0u != ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen - wCmdLen - wDataLen) / wAddDataLenLeft))
	                    ? wAddDataLenLeft
	                    : ((wFrameLen - wrappedApduHeaderLen - wrappedApduTrailerLen - wCmdLen - wDataLen) % wAddDataLenLeft);
	                }
	                else
	                {
	                    wAddDataLen = 0;
	                }
	            }

	            pApdu[1] = pCmd[0]; /* DESFire cmd code in INS */
	            if ((bIsExtended7816 != 0x00U) && (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED))
	            {
	                pApdu[6] = (uint8) (wCmdLenTotal + wDataLenTotal + wAddDataLenTotal);
	                pApdu[5] = (uint8) ((wCmdLenTotal + wDataLenTotal + wAddDataLenTotal) >> 8U);
	                /*pApdu[4] = 0; */
	            }
	            else
	            {
	                pApdu[4] = (uint8) (wCmdLen + ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) ? (wDataLenTotal + wAddDataLenTotal) : (wDataLen + wAddDataLen)));
	            }

	            wMoreDataToTransmit = (wWrappedApduHeaderLenLeft - wrappedApduHeaderLen) +
	                (wCmdLenLeft - wCmdLen) +
	                (wDataLeft - wDataLen) +
	                (wAddDataLenLeft - wAddDataLen) +
	                (wWrappedApduTrailerLenLeft - wrappedApduTrailerLen);
	            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
	            return PH_STATUS_INPROCESS;
	        }
	        else
	        {
	            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD6;
                return PH_STATUS_INPROCESS;
	        }
        case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_FIRST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pApdu[wHeaderIdx],
                    wrappedApduHeaderLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
            return PH_STATUS_INPROCESS;

        case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pCmd[1U + wCmdIdx],
                    wCmdLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
            return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u !=wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pData[wIndex],
                    wDataLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD5;
            return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD5:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                    &pAddData[wAddDataIdx],
                    wAddDataLen,
                    &pRecv,
                    pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD9;
            return PH_STATUS_INPROCESS;
	    case PHAL_MFDFEVX_SW_INT_STATE_CMD6:
            if (wCmdLenLeft > 0U)
            {
                wCmdLen = (((wFrameLen) / wCmdLenLeft) != 0U) ? wCmdLenLeft : ((wFrameLen) % wCmdLenLeft);
            }
            else
            {
                wCmdLen = 0U;
            }
            if (wDataLeft > 0U)
            {
                wDataLen = (((wFrameLen - wCmdLen) / wDataLeft) != 0U) ? wDataLeft : ((wFrameLen - wCmdLen) % wDataLeft);
            }
            else
            {
                wDataLen = 0;
            }
            if (wAddDataLenLeft > 0U)
            {
                wAddDataLen = (((wFrameLen - wCmdLen - wDataLen) / wAddDataLenLeft) != 0U)? wAddDataLenLeft : ((wFrameLen - wCmdLen - wDataLen) % wAddDataLenLeft);
            }
            else
            {
                wAddDataLen = 0;
            }

            wMoreDataToTransmit = (wCmdLenLeft - wCmdLen) +
                (wDataLeft - wDataLen) +
                (wAddDataLenLeft - wAddDataLen);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD7;
            return PH_STATUS_INPROCESS;

	    case PHAL_MFDFEVX_SW_INT_STATE_CMD7:
            PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_FIRST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                &pCmd[wCmdIdx],
                wCmdLen,
                &pRecv,
                pRespLen));
            PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD8;
            return PH_STATUS_INPROCESS;
	    case PHAL_MFDFEVX_SW_INT_STATE_CMD8:
	        PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_CONT | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                &pData[wIndex],
                wDataLen,
                &pRecv,
                pRespLen));
	        PH_BREAK_ON_FAILURE(statusTmp);
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD10;
	        return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_SW_INT_STATE_CMD9:
			/* Le byte */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pDataParams->pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u !=wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
				&pLe[wTrailerIdx],
				wrappedApduTrailerLen,
				&pRecv,
				pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);

			if (bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED)
			{
				wHeaderIdx += wrappedApduHeaderLen;
				wWrappedApduHeaderLenLeft -= wrappedApduHeaderLen;
				wCmdIdx += wCmdLen;
				wCmdLenLeft -= wCmdLen;
				wTrailerIdx += wrappedApduTrailerLen;
				wWrappedApduTrailerLenLeft -= wrappedApduTrailerLen;
			}

			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD11;
			return PH_STATUS_INPROCESS;
		case PHAL_MFDFEVX_SW_INT_STATE_CMD10:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                PH_EXCHANGE_BUFFER_LAST | (((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit)) ? PH_EXCHANGE_TXCHAINING : 0U),
                &pAddData[wAddDataIdx],
                wAddDataLen,
                &pRecv,
                pRespLen));
			PH_BREAK_ON_FAILURE(statusTmp);

            wCmdIdx += wCmdLen;
            wCmdLenLeft -= wCmdLen;
			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD11;
			/*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD11:
			wIndex += wDataLen;
			wDataLeft -= wDataLen;
			wAddDataIdx += wAddDataLen;
			wAddDataLenLeft -= wAddDataLen;

			/* in case of BIGISO, iso chaining is expected, and therefore R(ACK) block*/
			if ((bIns == PHAL_MFDFEVX_ISO_CHAINING_MODE_MAPPED) && (0u != wMoreDataToTransmit))
			{
				/* in case of ACK */
				if ((pRecv[0] & 0xF0U) == 0xA0U)
				{
					bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD12;
					return PH_STATUS_INPROCESS;
				}
			}

			if (0U != (pDataParams->bWrappedMode))
			{
				if ((*pRespLen) < 2U)
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}
				(void)memcpy(pResp, pRecv, (uint32)(*pRespLen) - 2U);
				bStatusByte = pRecv[(*pRespLen) - 1U];
				(*pRespLen) -= 2u;
			}
			else
			{
				if ((*pRespLen) < 1U)
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
					break;
				}
				(void)memcpy(pResp, &pRecv[1], (uint32)(*pRespLen) - 1U);
				bStatusByte = pRecv[0];
				(*pRespLen) -= 1u;
			}

			if ((bStatusByte != PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME) &&
				(bStatusByte != PH_ERR_SUCCESS))
			{

				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
				{
					(void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}

				statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, bStatusByte);
				break;
			}

			/* Success returned even before writing all data? protocol error */
			if ((bStatusByte == PH_ERR_SUCCESS) && (wDataLeft != 0U))
			{
				/* Reset authentication status */
				if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
					(pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
				{
					(void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
				}

				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_AL_MFDFEVX);
				break;
			}

			if (bStatusByte != 0x00U)
			{
				pCmd[0] = PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME;
				wCmdIdx = 0U;
				wCmdLenLeft = ((pDataParams->bWrappedMode) != 0x00U) ? 0U : 1U;
			}
			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD12;
			/*no break*/
		case PHAL_MFDFEVX_SW_INT_STATE_CMD12:
			if (0U != wMoreDataToTransmit)
			{
				bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;
			}
			statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, bStatusByte);
			break;
		default:
			break;
	}
	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_IsoRead(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead)
{
    static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxBufferSize = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM wNextPos = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
    static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackupBytes[3] = {0U};
    static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBytesRead = 0U;
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLenComputed = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMacCard[8] = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCMAC[16] = {0U};
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIvLen = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIntOption = PH_CRYPTOSYM_MAC_MODE_CMAC;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNumBlocks = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIndex = 0U;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLen = 0U;
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
  static VAR(uint8, ANFCRL_VAR) bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	switch (bMfdfEVxState)
    {
        case PHAL_MFDFEVX_SW_INT_STATE_IDLE:
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
            if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES)
            {
                bIvLen = PH_CRYPTOSYM_AES_BLOCK_SIZE;
            }
            else
            {
                bIvLen = PH_CRYPTOSYM_DES_BLOCK_SIZE;
            }

            if (wOption == PH_EXCHANGE_DEFAULT)
            {
                if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
                    (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES) ||
                    (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE))
                {
                    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
                        pDataParams->pCryptoDataParamsEnc,
                        pDataParams->bIv,
                        bIvLen
                    ));
                }
                if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEEV2)
                {
                    (void)memset(pDataParams->bIv, 0x00, bIvLen);
                }
            }
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD1;
            /*no break*/
        case PHAL_MFDFEVX_SW_INT_STATE_CMD1:
        	PH_CHECK_INPROCESS_FCT(status,phpalMifare_ExchangeL4(
                pDataParams->pPalMifareDataParams,
                (wOption & PH_EXCHANGE_MODE_MASK),
                bCmdBuff,
                wCmdLen,
                ppRxBuffer,
                &wBytesRead
            ));

            /* First put everything on the reader Rx buffer upto buffer size - 60 */
            wRxlen = wBytesRead;
            pRecv = *ppRxBuffer;

            if ((status != PH_ERR_SUCCESS) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
            {
                /* Authentication should be reset */
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
                (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
                statusTmp = status;
                break;
            }
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
            /*no break*/
        case PHAL_MFDFEVX_SW_INT_STATE_CMD2:
            if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
            {
            	PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_GetConfig(
                    pDataParams->pHalDataParams,
                    PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
                    &wRxBufferSize
                ));

                wNextPos = wBytesRead;
                (void)memcpy(bBackupBytes, &pRecv[wNextPos - 3u], 3);

                if ((wNextPos + PHAL_MFDFEVX_MAX_FRAME_SIZE) >= wRxBufferSize)
                {
                    /* Calculate practical cmac if authenticated and return PH_ERR_SUCCESS_CHAINING */
                	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
                	return PH_STATUS_INPROCESS;
                }

                PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(
                    pDataParams->pHalDataParams,
                    PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
                    (uint16) wNextPos
                ));
                bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD3;
                return PH_STATUS_INPROCESS;
            }
            bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD4;
            return PH_STATUS_INPROCESS;
        case PHAL_MFDFEVX_SW_INT_STATE_CMD3:
        	PH_CHECK_INPROCESS_FCT(status,phpalMifare_ExchangeL4(
                    pDataParams->pPalMifareDataParams,
                    PH_EXCHANGE_RXCHAINING,
                    bCmdBuff,
                    wCmdLen,
                    ppRxBuffer,
                    &wBytesRead
                ));

			/* Put back the backed up bytes */
			(void)memcpy(&pRecv[wNextPos - 3u], bBackupBytes, 3);

			if ((status != PH_ERR_SUCCESS) &&
				((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING))
			{
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
				/* Authentication should be reset */
				(void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

				statusTmp = status;
				break;
			}
			wRxlen = wBytesRead;
			bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_CMD2;
            return PH_STATUS_INPROCESS;
        case PHAL_MFDFEVX_SW_INT_STATE_CMD4:
            /* The data is now in *ppRxBuffer, length = wRxlen */
            /* satisfy compiler */
            PH_UNUSED_VARIABLE (wRxlen);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
        /* Size of MAC bytes */
            bMacLen = ((pDataParams->bAuthMode) == PHAL_MFDFEVX_AUTHENTICATE) ? 0x04U : 0x08U;
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
            if (status == PH_ERR_SUCCESS)
            {
                statusTmp = (*ppRxBuffer)[wBytesRead - 2U]; /* SW1 */
                statusTmp = statusTmp << 8U; /* Shift SW1 to MSB */
                statusTmp |= (*ppRxBuffer)[wBytesRead - 1U]; /* SW2 */

                if ((pDataParams->bAuthMode == PHAL_MFDFEVX_NOT_AUTHENTICATED) ||
                    ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE) && ((wOption & PH_EXCHANGE_CUSTOM_BITS_MASK) == PHAL_MFDFEVX_COMMUNICATION_PLAIN)))
                {
                    wBytesRead -= 2U;
                    statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp);
                    break;
                }
                statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp);

                if (statusTmp != PH_ERR_SUCCESS)
                {
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
                    /* Authentication should be reset */
                    (void)phalMfdfEVx_Sw_Int_ResetAuthStatus(pDataParams);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
                    break;
                }
#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
                (void)memset(bCMAC, 0, 16);
                /* Verify MAC. Dont consider SW1SW2 as MAC bytes */
                (void)memcpy(bCMacCard, &(*ppRxBuffer)[wBytesRead - ((uint16)bMacLen + 2U)], (uint32)bMacLen);

                /* Subtract the MAC bytes */
                wBytesRead -= ((uint16)bMacLen + 2U);

                (*ppRxBuffer)[wBytesRead] = 0x00U;

                if (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATE)
                {
                    wNumBlocks = wBytesRead / bIvLen;

                    while ((0U != wNumBlocks) && (statusTmp == PH_ERR_SUCCESS))
                    {
                        /* Encrypt */
                    	statusTmp = phCryptoSym_Encrypt(
                            pDataParams->pCryptoDataParamsEnc,
                            PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
                            &(*ppRxBuffer)[wIndex],
                            bIvLen,
                            bCMAC
                        );
                    	if(statusTmp == PH_ERR_SUCCESS)
                    	{
                            wNumBlocks--;
                            wIndex += bIvLen;

                            (void)memcpy(pDataParams->bIv, bCMAC, bIvLen);

							statusTmp = phCryptoSym_LoadIv(
							pDataParams->pCryptoDataParamsEnc,
							pDataParams->bIv,
							bIvLen
                            );
                    	}
                    }
                    PH_BREAK_ON_FAILURE(statusTmp);

                    if (0U != (wBytesRead % bIvLen))
                    {
                        /* In case data to be read is longer than the RxBuffer size,
                        the data is always sent in multiples of iv sizes from the card.
                        Control should never come here when data read is still not
                        complete */
                        (void)memcpy(bCMAC, &(*ppRxBuffer)[wIndex], ((uint32)wBytesRead % (uint32)bIvLen));

                        /* Apply padding */
                        PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_ApplyPadding(
                            PH_CRYPTOSYM_PADDING_MODE_1,
                            bCMAC,
                            (wBytesRead % bIvLen),
                            bIvLen,
                            (uint16)sizeof(bCMAC),
                            bCMAC,
                            &wDataLen
                        ));

                        /* Encrypt */
                        PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_Encrypt(
                            pDataParams->pCryptoDataParamsEnc,
                            PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_BUFFER_CONT,
                            bCMAC,
                            wDataLen,
                            bCMAC
                        ));
                    }
                }
                else if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
                        (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
                {
                    wIntOption = PH_EXCHANGE_BUFFER_LAST | PH_CRYPTOSYM_MAC_MODE_CMAC;

                    /* Calculate CMAC */
                    PH_CHECK_FAILURE_FCT(statusTmp, phCryptoSym_CalculateMac(
                        pDataParams->pCryptoDataParamsEnc,
                        wIntOption,
                        *ppRxBuffer,
                        wBytesRead + 1U,
                        bCMAC,
                        &bMacLenComputed
                    ));
                }
                else
                {
                    /* EV2 Auth mode needs to be handled */
                }

                if (memcmp(bCMAC, bCMacCard, bMacLen) != 0x00)
                {
                	statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_AL_MFDFEVX);
                	break;
                }

                if ((pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEISO) ||
                    (pDataParams->bAuthMode == PHAL_MFDFEVX_AUTHENTICATEAES))
                {
                    /* Update IV */
                    (void)memcpy(pDataParams->bIv, bCMAC, bMacLenComputed);
                }
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */
            }
            statusTmp = PH_ADD_COMPCODE((status & PH_ERR_MASK), PH_COMP_AL_MFDFEVX);
            break;
        default:
            break;
    }
	*pBytesRead = (uint32)wBytesRead;
	bMfdfEVxState = PHAL_MFDFEVX_SW_INT_STATE_IDLE;
	return statusTmp;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(void, ANFCRL_CODE) phalMfdfEVx_Sw_Int_TruncateMac(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex2 = 0u;

    for (bIndex = 1U; bIndex < 16U; bIndex += 2U)
    {
        pMac[bIndex2] = pMac[bIndex];
        bIndex2++;
    }
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeIv(
	VAR(uint8, ANFCRL_VAR) bIsResponse, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTi, 
	VAR(uint16, ANFCRL_VAR) wCmdCtr, 
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdCtrMsb = (uint8) (wCmdCtr >> 8U);
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdCtrLsb = (uint8) (wCmdCtr & 0x00ffU);

    (void)memset(pIv, 0, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* parameter checking */
    if ((pTi == NULL) || (pIv == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_AL_MFDFEVX);
    }

    if (0U != (bIsResponse))
    {
        /* Form the IV for RespData as 0x5A||0xA5||TI||CmdCtr||0x0000000000000000 */
        pIv[bIndex++] = 0x5AU;
        pIv[bIndex++] = 0xA5U;
    }
    else
    {
        /* Form the IV for CmdData as 0xA5||0x5A||TI||CmdCtr||0x0000000000000000  */
        pIv[bIndex++] = 0xA5U;
        pIv[bIndex++] = 0x5AU;
    }

    pIv[bIndex++] = pTi[0];
    pIv[bIndex++] = pTi[1];
    pIv[bIndex++] = pTi[2];
    pIv[bIndex++] = pTi[3];
    pIv[bIndex++] = bCmdCtrLsb;
    pIv[bIndex] = bCmdCtrMsb;

    return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GetFrameLength(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFSD, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFSC)
{
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTmp = 0;

    PH_CHECK_SUCCESS_FCT(statusTmp, phpalMifare_GetConfig(
        pDataParams->pPalMifareDataParams,
        PHPAL_I14443P4_CONFIG_FSI,
        &wTmp
    ));

    /* Get FSD */
    switch ((uint8) (wTmp >> 8U))
    {
        case 0:
            *pFSD = 16;
            break;
        case 1:
            *pFSD = 24;
            break;
        case 2:
            *pFSD = 32;
            break;
        case 3:
            *pFSD = 40;
            break;
        case 4:
            *pFSD = 48;
            break;
        case 5:
            *pFSD = 64;
            break;
        case 6:
            *pFSD = 96;
            break;
        case 7:
            *pFSD = 128;
            break;
        case 8:
            *pFSD = 256;
            break;
        default:
            break;
    }

    /* Get FSC */
    switch ((uint8) (wTmp))
    {
        case 0:
            *pFSC = 16;
            break;
        case 1:
            *pFSC = 24;
            break;
        case 2:
            *pFSC = 32;
            break;
        case 3:
            *pFSC = 40;
            break;
        case 4:
            *pFSC = 48;
            break;
        case 5:
            *pFSC = 64;
            break;
        case 6:
            *pFSC = 96;
            break;
        case 7:
            *pFSC = 128;
            break;
        case 8:
            *pFSC = 256;
            break;
        default:
            break;
    }

    return PH_ERR_SUCCESS;
}

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_DecryptSDMData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInputOutputData, VAR(uint16, ANFCRL_VAR) wInputDataLen)
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp = PH_ERR_SUCCESS;

    if ((pSessEncKey == NULL) || (pIv == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDFEVX);
    }

    /* Load the session ENC Key to Crypto Object */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
        pDataParams->pCryptoDataParamsEnc,
        pSessEncKey,
        PH_CRYPTOSYM_KEY_TYPE_AES128));

    /* Load IV */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsEnc,
        pIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    /* Decrypt Data */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Decrypt(
        pDataParams->pCryptoDataParamsEnc,
        PH_CRYPTOSYM_CIPHER_MODE_CBC | PH_EXCHANGE_DEFAULT,
        pInputOutputData,
        wInputDataLen,
        pInputOutputData));

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeSDMSessionVectors(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wSrcKeyNo, VAR(uint16, ANFCRL_VAR) wSrcKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType = 0x0000;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aSV[32];
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSvLen = 0;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwSDMReadCtr = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bKey[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLen = 0x00U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmpIV[16] = { 0 };

    /* Validate the Counter value. */
    if (pSDMReadCtr != NULL)
    {
        dwSDMReadCtr = (((uint32)pSDMReadCtr[0]) | (((uint32)pSDMReadCtr[1]) << 8) | (((uint32)pSDMReadCtr[2]) << 16) | (((uint32)pSDMReadCtr[3]) << 24));
        if (dwSDMReadCtr == 0xFFFFFFU)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_PARAMETER_OVERFLOW, PH_COMP_AL_MFDFEVX);
        }
    }

    /* Clear the session vector SV. */
    (void)memset(aSV, 0, sizeof(aSV));

    /* Frame the default values in session vector. */
    aSV[bSvLen++] = (uint8) ((bOption == PHAL_MFDFEVX_SESSION_ENC) ? 0xC3U : 0x3CU);
    aSV[bSvLen++] = (uint8) ((bOption == PHAL_MFDFEVX_SESSION_ENC) ? 0x3CU : 0xC3U);
    aSV[bSvLen++] = 0x00u;
    aSV[bSvLen++] = 0x01u;
    aSV[bSvLen++] = 0x00u;
    aSV[bSvLen++] = 0x80u;

    /* Append the UID */
    if (0U != (bSdmOption & PHAL_MFDFEVX_VCUID_PRESENT))
    {
        if(pUid != NULL)
        {
            (void)memcpy(&aSV[bSvLen], pUid, bUidLen);
            bSvLen += bUidLen;
        }
        else
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDFEVX);
        }
    }

    /* Append the SDM ReadCtr information. */
    if ((bSdmOption & PHAL_MFDFEVX_RDCTR_PRESENT) != 0U)
    {
        if(dwSDMReadCtr != 0U)
        {
            aSV[bSvLen++] = (uint8) (dwSDMReadCtr & 0xFFU);
            aSV[bSvLen++] = (uint8) ((dwSDMReadCtr & 0xFF00U) >> 8U);
            aSV[bSvLen++] = (uint8) ((dwSDMReadCtr & 0xFF0000U) >> 16U);
        }
    }

    /* Update the SV length */
    if(((bSdmOption & PHAL_MFDFEVX_RDCTR_PRESENT) != 0U) && (bSvLen > 16U))
    {
        bSvLen = 32U;
    }else {
        bSvLen = 16U;
    }

    /* Now Get the Keys from SW Key Store */
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
        pDataParams->pKeyStoreDataParams,
        wSrcKeyNo,
        wSrcKeyVer,
        PH_CRYPTOSYM_AES128_KEY_SIZE,
        bKey,
        &wKeyType));

    if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_KEY, PH_COMP_AL_MFDFEVX);
    }

    /* load key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
        pDataParams->pCryptoDataParamsMac,
        bKey,
        wKeyType));

    /* Create a Back up of the current IV */
    (void)memcpy(bTmpIV, pDataParams->bIv, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load zero to IV */
    (void)memset(pDataParams->bIv, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsMac,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE
    ));

    /* MAC SV1 to obtain KSesSDMFileReadEnc */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
        pDataParams->pCryptoDataParamsMac,
        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
        aSV,
        bSvLen,
        bKey,
        &bLen));

    /* Copy the session  Key */
    (void)memcpy(pSessionKey, bKey, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Reload Back up IV */
    (void)memcpy(pDataParams->bIv, bTmpIV, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsMac,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GenerateSDMSessionKeysAES(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption,
    VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCUID, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessMacKey)
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSV1[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSV2[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bKey[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdLenMac = 0u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdLenEnc = 0u;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wKeyType = 0x0000u;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmpIV[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMacLen = 0x00u;

    if ((pSDMReadCtr == NULL) || (pVCUID == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDFEVX);
    }

    /* Validate the Output Buffers */
    if ((pSessEncKey == NULL) || (pSessMacKey == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDFEVX);
    }

    /* Clear the session vector.  */
    (void)memset(bSV1, 0x00, sizeof(bSV1));
    (void)memset(bSV2, 0x00, sizeof(bSV2));

                                         /* Prepare SV1 Buffer */
    bSV1[bCmdLenEnc++] = 0xC3u;
    bSV1[bCmdLenEnc++] = 0x3Cu;

    bSV2[bCmdLenMac++] = 0x3Cu;
    bSV2[bCmdLenMac++] = 0xC3u;

    bSV1[bCmdLenEnc++] = 0x00u;
    bSV2[bCmdLenMac++] = 0x00u;
    bSV1[bCmdLenEnc++] = 0x01u;
    bSV2[bCmdLenMac++] = 0x01u;
    bSV1[bCmdLenEnc++] = 0x00u;
    bSV2[bCmdLenMac++] = 0x00u;
    bSV1[bCmdLenEnc++] = 0x80u;
    bSV2[bCmdLenMac++] = 0x80u;

    if (0U != (bSdmOption & PHAL_MFDFEVX_VCUID_PRESENT))
    {
        /* Copy UID into bSV1 */
		(void)memcpy(&bSV1[bCmdLenEnc], pVCUID, bUidLen);
		bCmdLenEnc += bUidLen;
	    /* Copy UID into bSV2 */
		(void)memcpy(&bSV2[bCmdLenMac], pVCUID, bUidLen);
		bCmdLenMac += bUidLen;
    }


    /* Copy SDMReadCtr into bSV1 */
    if (0U != (bSdmOption & PHAL_MFDFEVX_RDCTR_PRESENT))
    {
    	/* Copy SDMReadCtr into bSV1 */
		(void)memcpy(&bSV1[bCmdLenEnc], pSDMReadCtr, 0x03);
		bCmdLenEnc += 0x03u;
		 /* Copy SDMReadCtr into bSV2 */
		(void)memcpy(&bSV2[bCmdLenMac], pSDMReadCtr, 0x03);
		bCmdLenMac += 0x03u;
    }

    /* Now Get the Keys from SW Key Store */
    PH_CHECK_SUCCESS_FCT(statusTmp, phKeyStore_GetKey(
        pDataParams->pKeyStoreDataParams,
        wKeyNo,
        wKeyVer,
        PH_CRYPTOSYM_AES128_KEY_SIZE,
        bKey,
        &wKeyType));

    if (wKeyType != PH_CRYPTOSYM_KEY_TYPE_AES128)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_KEY, PH_COMP_AL_MFDFEVX);
    }

    /* load key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
        pDataParams->pCryptoDataParamsMac,
        bKey,
        wKeyType));

    /* Create a Back up of the current IV */
    (void)memcpy(bTmpIV, pDataParams->bIv, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load zero to IV */
    (void)memset(pDataParams->bIv, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsMac,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    /* MAC SV1 to obtain KSesSDMFileReadEnc */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
        pDataParams->pCryptoDataParamsMac,
        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
        bSV1,
        bCmdLenEnc,
        bKey,
        &bMacLen));

    /* Copy the session Enc Key */
    (void)memcpy(pSessEncKey, bKey, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    (void)memset(bKey, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* MAC SV2 to obtain KSesSDMFileReadMac */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_CalculateMac(
        pDataParams->pCryptoDataParamsMac,
        (PH_CRYPTOSYM_MAC_MODE_CMAC | PH_EXCHANGE_DEFAULT),
        bSV2,
        bCmdLenMac,
        bKey,
        &bMacLen));

    /* Copy session Mac Key */
    (void)memcpy(pSessMacKey, bKey, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Reload Back up IV */
    (void)memcpy(pDataParams->bIv, bTmpIV, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsMac,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeSDMIV(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIV)
{
    VAR(phStatus_t, ANFCRL_VAR) statusTmp = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmpIV[16] = { 0 };
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDataBuf[16] = { 0 };

    /* Validate the IP Parameters */
    if ((pSessEncKey == NULL) || (pSDMReadCtr == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AL_MFDFEVX);
    }
    /* Create a Back up of the current IV */
    (void)memcpy(bTmpIV, pDataParams->bIv, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load zero to IV */
    (void)memset(pDataParams->bIv, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsEnc,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    /* load key */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadKeyDirect(
        pDataParams->pCryptoDataParamsEnc,
        pSessEncKey,
        PH_CRYPTOSYM_KEY_TYPE_AES128));

    /* Clear data buffer */
    (void)memset(bDataBuf, 0x00, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Prepare Data buffer to derive IV */
    bDataBuf[0] = pSDMReadCtr[0];
    bDataBuf[1] = pSDMReadCtr[1];
    bDataBuf[2] = pSDMReadCtr[2];

    /* Now Encrypt the data Buffer to derive IV */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_Encrypt(
        pDataParams->pCryptoDataParamsEnc,
        PH_CRYPTOSYM_CIPHER_MODE_CBC,
        bDataBuf,
        PH_CRYPTOSYM_AES_BLOCK_SIZE,
        bDataBuf));

    (void)memcpy(pIV, bDataBuf, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Restore the IV */
    (void)memcpy(pDataParams->bIv, bTmpIV, PH_CRYPTOSYM_AES_BLOCK_SIZE);

    /* Load Iv */
    PH_CHECK_SUCCESS_FCT(statusTmp, phCryptoSym_LoadIv(
        pDataParams->pCryptoDataParamsEnc,
        pDataParams->bIv,
        PH_CRYPTOSYM_AES_BLOCK_SIZE));

    return PH_ERR_SUCCESS;
}

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef __cplusplus
}
#endif
