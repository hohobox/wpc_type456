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
*   @file    phalMfdfEVx_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx_Int - AL API usage in common use cases.
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

#ifdef NXPBUILD__PHAL_MFDFEVX

#include <string.h>
#include <phpalMifare.h>
#include <phalMfdfEVx.h>
#include "phalMfdfEVx_Int.h"
#include <ph_RefDefs.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and PHALMFDFEVX_INT.h header file are of the same vendor */
#if (PHALMFDFEVX_INT_VENDOR_ID_C != PHALMFDFEVX_INT_VENDOR_ID)
    #error "phalMfdfEVx_Int.c and phalMfdfEVx_Int.h have different vendor ids"
#endif
/* Check if current file and PHALMFDFEVX_INT.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_INT_AR_RELEASE_MAJOR_VERSION_C    != PHALMFDFEVX_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHALMFDFEVX_INT_AR_RELEASE_MINOR_VERSION_C    != PHALMFDFEVX_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHALMFDFEVX_INT_AR_RELEASE_REVISION_VERSION_C != PHALMFDFEVX_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdfEVx_Int.c and phalMfdfEVx_Int.h are different"
#endif
/* Check if current file and PHALMFDFEVX_INT.h header file are of the same Software version */
#if ((PHALMFDFEVX_INT_SW_MAJOR_VERSION_C != PHALMFDFEVX_INT_SW_MAJOR_VERSION) || \
     (PHALMFDFEVX_INT_SW_MINOR_VERSION_C != PHALMFDFEVX_INT_SW_MINOR_VERSION) || \
     (PHALMFDFEVX_INT_SW_PATCH_VERSION_C != PHALMFDFEVX_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdfEVx_Int.c and phalMfdfEVx_Int.h are different"
#endif
#endif /* NXPBUILD__PHAL_MFDFEVX */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_MFDFEVX

#define PHAL_MFDFEVX_INT_STATE_IDLE	0U
#define PHAL_MFDFEVX_INT_STATE_CMD1	1U
#define PHAL_MFDFEVX_INT_STATE_CMD2	2U
#define PHAL_MFDFEVX_INT_STATE_CMD3	3U
#define PHAL_MFDFEVX_INT_STATE_CMD4	4U
#define PHAL_MFDFEVX_INT_STATE_CMD5	5U
#define PHAL_MFDFEVX_INT_STATE_CMD6	6U

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
#if ((PHALMFDFEVX_INT_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ComputeErrorResponse(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wStatus)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdCode = 0U;

	PH_CHECK_SUCCESS_FCT(status, phalMfdfEVx_Int_GetCmdCode(pDataParams, &bCmdCode));

	switch (wStatus)
	{
		case PHAL_MFDFEVX_RESP_OPERATION_OK:
		case PHAL_MFDFEVX_ISO7816_SUCCESS:
		case PHAL_MFDFEVX_RESP_OK:
			status = PH_ERR_SUCCESS;
			break;

		case PHAL_MFDFEVX_RESP_ERR_CMD_INVALID:
			status = PHAL_MFDFEVX_ERR_CMD_INVALID;
			break;

		case PHAL_MFDFEVX_RESP_NO_CHANGES:
			if(bCmdCode == PHAL_MFDFEVX_CMD_AUTH_PDC)
			{
				status = PHAL_MFDFEVX_ERR_FORMAT;
			}else
			{
				status = PHAL_MFDFEVX_NO_CHANGES;
			}
			break;

		case PHAL_MFDFEVX_RESP_ERR_NOT_SUP:
			status = PHAL_MFDFEVX_ERR_NOT_SUPPORTED;
			break;

		case PHAL_MFDFEVX_RESP_ERR_OUT_OF_EEPROM_ERROR:
			status = PHAL_MFDFEVX_ERR_OUT_OF_EEPROM_ERROR;
			break;

		case PHAL_MFDFEVX_RESP_ERR_INTEGRITY_ERROR:
			status = PHAL_MFDFEVX_ERR_PICC_CRYPTO;
			break;

		case PHAL_MFDFEVX_RESP_ERR_PARAMETER_ERROR:
			status = PHAL_MFDFEVX_ERR_PARAMETER_ERROR;
			break;

		case PHAL_MFDFEVX_RESP_NO_SUCH_KEY:
			status = PHAL_MFDFEVX_ERR_NO_SUCH_KEY;
			break;

		case PHAL_MFDFEVX_RESP_ERR_LENGTH_ERROR:
			status = PH_ERR_LENGTH_ERROR;
			break;

		case PHAL_MFDFEVX_RESP_PERMISSION_DENIED:
			status = PHAL_MFDFEVX_ERR_PERMISSION_DENIED;
			break;

		case PHAL_MFDFEVX_RESP_APPLICATION_NOT_FOUND:
			status = PHAL_MFDFEVX_ERR_APPLICATION_NOT_FOUND;
			break;

		case PHAL_MFDFEVX_RESP_ERR_AUTHENTICATION_ERROR:
		case PHAL_MFDFEVX_RESP_ERR_AUTH_ERROR:
			status = PH_ERR_AUTH_ERROR;
			break;

		case PHAL_MFDFEVX_RESP_ADDITIONAL_FRAME:
			status = PH_ERR_SUCCESS_CHAINING;
			break;

		case PHAL_MFDFEVX_RESP_ERR_BOUNDARY_ERROR:
			status = PHAL_MFDFEVX_ERR_BOUNDARY_ERROR;
			break;

		case PHAL_MFDFEVX_RESP_ERR_COMMAND_ABORTED:
			status = PHAL_MFDFEVX_ERR_COMMAND_ABORTED;
			break;

		case PHAL_MFDFEVX_RESP_ERR_COUNT:
			status = PHAL_MFDFEVX_ERR_COUNT;
			break;

		case PHAL_MFDFEVX_RESP_ERR_DUPLICATE:
			status = PHAL_MFDFEVX_ERR_DUPLICATE;
			break;

		case PHAL_MFDFEVX_RESP_ERR_FILE_NOT_FOUND:
			status = PHAL_MFDFEVX_ERR_FILE_NOT_FOUND;
			break;

		case PHAL_MFDFEVX_RESP_ERR_APPL_INTEGRITY_ERROR:
		case PHAL_MFDFEVX_RESP_ERR_PICC_INTEGRITY:
		case PHAL_MFDFEVX_RESP_ERR_EEPROM:
		case PHAL_MFDFEVX_RESP_ERR_FILE_INTEGRITY:
		case PHAL_MFDFEVX_RESP_ERR_PIC_DISABLED:
		case PHAL_MFDFEVX_RESP_ILLEGAL_COMMAND_CODE:
			status = PHAL_MFDFEVX_ERR_DF_GEN_ERROR;
			PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_SetConfig(
				pDataParams,
				PHAL_MFDFEVX_ADDITIONAL_INFO,
				wStatus));
			break;

		case PHAL_MFDFEVX_ISO7816_ERR_WRONG_LENGTH:
		case PHAL_MFDFEVX_ISO7816_ERR_WRONG_LE:
		case PHAL_MFDFEVX_ISO7816_ERR_FILE_NOT_FOUND:
		case PHAL_MFDFEVX_ISO7816_ERR_WRONG_PARAMS:
		case PHAL_MFDFEVX_ISO7816_ERR_WRONG_LC:
		case PHAL_MFDFEVX_ISO7816_ERR_NO_PRECISE_DIAGNOSTICS:
		case PHAL_MFDFEVX_ISO7816_ERR_EOF_REACHED:
		case PHAL_MFDFEVX_ISO7816_ERR_FILE_ACCESS:
		case PHAL_MFDFEVX_ISO7816_ERR_FILE_EMPTY:
		case PHAL_MFDFEVX_ISO7816_ERR_MEMORY_FAILURE:
		case PHAL_MFDFEVX_ISO7816_ERR_INCORRECT_PARAMS:
		case PHAL_MFDFEVX_ISO7816_ERR_WRONG_CLA:
		case PHAL_MFDFEVX_ISO7816_ERR_UNSUPPORTED_INS:
		case PHAL_MFDFEVX_ISO7816_ERR_LIMITED_FUNCTIONALITY_INS:
			status = PHAL_MFDFEVX_ERR_DF_7816_GEN_ERROR;
			PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_SetConfig(
				pDataParams,
				PHAL_MFDFEVX_ADDITIONAL_INFO,
				wStatus));
			break;

		case PHAL_MFDFEVX_RESP_CHAINING:
			status = PH_ERR_SUCCESS_CHAINING;
			break;

		case PHAL_MFDFEVX_RESP_OPERATION_OK_LIM:
			status = PHAL_MFDFEVX_ERR_OPERATION_OK_LIM;
			break;

		case PHAL_MFDFEVX_RESP_ERR_CMD_OVERFLOW:
			status = PHAL_MFDFEVX_ERR_CMD_OVERFLOW;
			break;

		case PHAL_MFDFEVX_RESP_ERR_CMD_GEN_FAILURE:
			status = PHAL_MFDFEVX_ERR_GEN_FAILURE;
			break;

		case PHAL_MFDFEVX_RESP_ERR_BNR:
			status = PHAL_MFDFEVX_ERR_BNR;
			break;

		default:
			status = PH_ERR_PROTOCOL_ERROR;
	}
	return PH_ADD_COMPCODE(status, PH_COMP_AL_MFDFEVX);
}

/* Should take care of wrapping and unwrapping if ISO 7816 Wrapped mode
 * Does not handle any chaining or CMAC generation/verification or encryption/decryption
 */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_ExchangeCmd(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bWrappedMode, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameLen = 0;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wStatusWord;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pApdu[5] = { PHAL_MFDFEVX_WRAPPEDAPDU_CLA, 0x00, PHAL_MFDFEVX_WRAPPEDAPDU_P1, PHAL_MFDFEVX_WRAPPEDAPDU_P2, 0x00 };
  static VAR(uint8, ANFCRL_VAR) bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bExchangeCmdState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			if (0U != (bWrappedMode))
			{
				wFrameLen = PHAL_MFDFEVX_MAXWRAPPEDAPDU_SIZE;
				bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD2;
			}
			else
			{
				wFrameLen = PHAL_MFDFEVX_MAXDFAPDU_SIZE;
				bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD1;
			}

			if (wCmdLen > wFrameLen)
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_AL_MFDFEVX);
				break;
			}
			return PH_STATUS_INPROCESS;

		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
						pPalMifareDataParams,
						PH_EXCHANGE_DEFAULT,
						pSendBuff,
						wCmdLen,
						&pRecv,
						pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);

			*ppResponse = &(pRecv[1]);
			wStatusWord = pRecv[0];
			(*pRxlen) -= 1u;
			statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, (uint8) wStatusWord);
			break;

		case PHAL_MFDFEVX_INT_STATE_CMD2:
			pApdu[1] = pSendBuff[0]; /* DESFire cmd code in INS */
			pApdu[4] = (uint8)(wCmdLen) - 0x01u;

			if (pApdu[4] != 0x00U)
			{
				bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD3;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD5;
				return PH_STATUS_INPROCESS;
			}
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
								pPalMifareDataParams,
								PH_EXCHANGE_BUFFER_FIRST,
								pApdu,
								PHAL_MFDFEVX_WRAP_HDR_LEN,
								&pRecv,
								pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD4;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD4:
			PH_CHECK_INPROCESS_FCT(statusTmp,  phpalMifare_ExchangeL4(
								pPalMifareDataParams,
								PH_EXCHANGE_BUFFER_CONT,
								&pSendBuff[1],
								wCmdLen - 1u,
								&pRecv,
								pRxlen));
			PH_BREAK_ON_FAILURE(statusTmp);
			bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_CMD5;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD5:
			if (pApdu[4] != 0x00U)
			{
				/* Le byte */
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
								pPalMifareDataParams,
								PH_EXCHANGE_BUFFER_LAST,
								&pApdu[2], /* Le is always zero in wrapped mode. */
								0x01,
								&pRecv,
								pRxlen));
			}

			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
								pPalMifareDataParams,
								PH_EXCHANGE_DEFAULT,
								pApdu,
								PHAL_MFDFEVX_WRAP_HDR_LEN,
								&pRecv,
								pRxlen));
			}
			PH_BREAK_ON_FAILURE(statusTmp);

			*ppResponse = pRecv;
			wStatusWord = pRecv[(*pRxlen) - 2U];
			wStatusWord <<= 8U;
			wStatusWord |= pRecv[(*pRxlen) - 1U];
			(*pRxlen) -= 2u;
			if((pRecv[(*pRxlen)]) == 0x91U)
			{

				statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, (uint8)wStatusWord);
			}
			else
			{
				statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, wStatusWord);
			}
	}

	bExchangeCmdState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_Send7816Apdu(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bP1, VAR(uint8, ANFCRL_VAR) bP2,
  VAR(uint32, ANFCRL_VAR) bLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, VAR(uint32, ANFCRL_VAR) bLe, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuff[20];
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCmdLen = 0;
  static VAR(uint8, ANFCRL_VAR) bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOSelectFileState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			PH_CHECK_SUCCESS_FCT(statusTmp, phalMfdfEVx_Int_SetCmdCode(pDataParams, bIns));
			bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_CMD1;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD1:
			bCmdBuff[wCmdLen++] = 0x00; /* Class is always 0x00 */
			bCmdBuff[wCmdLen++] = bIns;
			bCmdBuff[wCmdLen++] = bP1;
			bCmdBuff[wCmdLen++] = bP2;

			switch(bIns)
			{
				case PHAL_MFDFEVX_CMD_ISO7816_SELECT_FILE:
					/* Both Lc and Le are required */
					statusTmp = phalMfdfEVx_Int_ISOSelectFile(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						(uint8)bLc, bExtendedLenApdu, pDataIn, (uint8)bLe, ppDataOut, pDataLen);
					break;

				case PHAL_MFDFEVX_CMD_ISO7816_UPDATE_BINARY:
					statusTmp = phalMfdfEVx_Int_ISOUpdateBinary(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						bLc, bExtendedLenApdu, pDataIn, ppDataOut, pDataLen);
					break;

				case PHAL_MFDFEVX_CMD_ISO7816_APPEND_RECORD:
					/* Le is not required since no response data expected */
					statusTmp = phalMfdfEVx_Int_ISOAppendRecord(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						bLc, bExtendedLenApdu, pDataIn, ppDataOut, pDataLen);
					break;

				case PHAL_MFDFEVX_CMD_ISO7816_GET_CHALLENGE:
					statusTmp = phalMfdfEVx_Int_ISOGetChallenge(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						(uint8)bLe, bExtendedLenApdu, ppDataOut, pDataLen);
					break;

				case PHAL_MFDFEVX_CMD_ISO7816_EXT_AUTHENTICATE:
					/* Le is not required since no response data expected. bLc however will be 1 byte since it is framed as a part of
					 * input buffer and sent it from AL. All other commands are sent as type uint32 from AL, but here bLc is sent in uint8
					 */
					statusTmp = phalMfdfEVx_Int_ISOExternalAuthenticate(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						(uint8)bLc, bExtendedLenApdu, pDataIn, ppDataOut, pDataLen);
					break;

				case PHAL_MFDFEVX_CMD_ISO7816_INT_AUTHENTICATE:
					statusTmp = phalMfdfEVx_Int_ISOInternalAuthenticate(pDataParams, pPalMifareDataParams, bOption, bCmdBuff, wCmdLen,
						(uint8)bLc, bExtendedLenApdu, pDataIn, bLe, ppDataOut, pDataLen);
					break;

				default:
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AL_MFDFEVX);
			}
			if (statusTmp == PH_STATUS_INPROCESS)
			{
				return PH_STATUS_INPROCESS;
			}
	}
	bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOSelectFile(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint8, ANFCRL_VAR) bLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, VAR(uint8, ANFCRL_VAR) bLe, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp1 = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  VAR(uint16, ANFCRL_VAR) wVal = 0U;
  static VAR(uint8, ANFCRL_VAR) bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOSelectFileState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			/* Check whether Lc is passed */
			if (0U != (bOption & 0x01U))
			{
				/* Check whether Length Lc is represented in short APDU or extended APDU */
				if(bExtendedLenApdu == 0x01U)
				{
					/* Extended APDU */
					bCmdBuff[wCmdLen++] = 0x00; /* first byte will be 0x00 if Ext APDU present. Next 2 byte contains actual data */
					bCmdBuff[wCmdLen++] = 0x00; /* As of now this field will be set to 0x00 since maximum data that can be sent is 16 bytes. In case if data to be sent exceeds 255 bytes, this byte shall be used  */
					bCmdBuff[wCmdLen++] = bLc;  /* Actual data to be sent */
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = bLc;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			if ((0U != ((bOption & 0x01U))) && (bLc > 0U))
			{
				bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;
			}

			bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pDataIn,
				bLc,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD2:
			wCmdLen = 0;

			 /* As per ISO/IEC:7816-4(2005), Section 5, An extended Le field consists of either three bytes
			 * (one byte set to '00' followed by two bytes with any
			 * value) if the Lc field is absent, or two bytes (with any value) if an extended Lc field is present.
			 */
			if (0U != (bOption & 0x02U))
			{
				/* Check whether Length is represented in extended APDU format and Lc is present.
				 * If true, then Le should represented in 2 bytes else Le should be represented in 3 bytes
				 */
				if(bExtendedLenApdu == 0x01U)
				{
					/* Extended APDU */
					if(0U != (bOption & 0x01U))
					{
						bCmdBuff[wCmdLen++] = 0x00;
						bCmdBuff[wCmdLen++] = bLe;
					}
					else
					{
						bCmdBuff[wCmdLen++] = 0x00;
						bCmdBuff[wCmdLen++] = 0x00;
						bCmdBuff[wCmdLen++] = bLe;
					}
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = bLe;
				}
			}

			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			bISOSelectFileState = PHAL_MFDFEVX_INT_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];

			statusTmp = phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp);

			if((statusTmp & PH_ERR_MASK) == PHAL_MFDFEVX_ERR_DF_7816_GEN_ERROR)
			{
				PH_CHECK_SUCCESS_FCT( statusTmp1, phalMfdfEVx_GetConfig(pDataParams, PHAL_MFDFEVX_ADDITIONAL_INFO, &wVal));
			}

			/*  Check for Success and for LIMITED FUNCTIONALITY error. In both cases, FCI would be returned */
			if((statusTmp == PH_ERR_SUCCESS) || (wVal == PHAL_MFDFEVX_ISO7816_ERR_LIMITED_FUNCTIONALITY_INS))
			{
				if (pDataLen != NULL)
				{
					*pDataLen = wRxlen -2u;
				}
				if (ppDataOut != NULL)
				{
					*ppDataOut = pRecv;
				}
			}
			else
			{
				return statusTmp;
			}
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOUpdateBinary(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint32, ANFCRL_VAR) dwLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen= 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM bDataLenPtr = NULL;
  static VAR(uint8, ANFCRL_VAR) bISOUpdateBinaryState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOUpdateBinaryState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			/* Initialize LcPtr */
			bDataLenPtr = (uint8 *)&dwLc;
			/* Check whether Lc has to be passed */
			if (0U != (bOption & 0x01U))
			{
				/* Check whether Length Lc is represented in short APDU or extended APDU */
				if(bExtendedLenApdu == 0x01U)
				{
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
					bCmdBuff[wCmdLen++] = 0x00;
					bCmdBuff[wCmdLen++] = bDataLenPtr[1];
					bCmdBuff[wCmdLen++] = bDataLenPtr[0];
					/* Note: Need to handle the case where data to write is more than 0xFFFF(i.e 65535 bytes).
					*/
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = *bDataLenPtr;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			if ((0U != ((bOption & 0x01U))) && (dwLc > 0U))
			{
				bISOUpdateBinaryState = PHAL_MFDFEVX_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;
			}

			bISOUpdateBinaryState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pDataIn,
				(uint16)dwLc,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOUpdateBinaryState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD2:
			wCmdLen = 0;
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];
			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp));
			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}
			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
	}

	bISOUpdateBinaryState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOAppendRecord(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint32, ANFCRL_VAR) dwLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM bDataLenPtr = NULL;
	static VAR(uint8, ANFCRL_VAR) bISOAppendRecordState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOAppendRecordState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			/* Initialize LcPtr */
			bDataLenPtr = (uint8 *)&dwLc;
			if (0U != (bOption & 0x01U))
			{
				/* Check whether Length Lc is represented in short APDU or extended APDU */
				if(bExtendedLenApdu == 0x01U)
				{
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
					bCmdBuff[wCmdLen++] = 0x00;
					bCmdBuff[wCmdLen++] = bDataLenPtr[1];
					bCmdBuff[wCmdLen++] = bDataLenPtr[0];
					/* Note: Need to handle the case where data to write is more than 0xFFFF(i.e 65535 bytes).*/
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = *bDataLenPtr;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);

			if ((0U != ((bOption & 0x01U))) && (dwLc > 0U))
			{
				bISOAppendRecordState = PHAL_MFDFEVX_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;

			}

			bISOAppendRecordState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pDataIn,
				(uint16)dwLc,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOAppendRecordState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD2:
			wCmdLen = 0;
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];
			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp));
			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}
			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
	}

	bISOAppendRecordState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOGetChallenge(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint8, ANFCRL_VAR) bLe, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  static VAR(uint8, ANFCRL_VAR) bISOGetChallengeState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOGetChallengeState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOGetChallengeState = PHAL_MFDFEVX_INT_STATE_CMD1;
			/* no break */

		case PHAL_MFDFEVX_INT_STATE_CMD1:
			wCmdLen = 0;
			if (0U != (bOption & 0x02U))
			{
				/* Check whether Length Le is represented in short APDU(1B) or extended APDU(3B) */
				if(bExtendedLenApdu == 0x01U)
				{
					/*
					 * An extended Le field consists of either three bytes (one * byte set to '00' followed by two bytes with any
					 * value) if the Lc field is absent, or two bytes (with any * value) if an extended Lc field is present.
					 * From '0001' to 'FFFF', the two bytes encode Ne from one
					 * to 65 535.
					 * If the two bytes are set to '0000', then Ne is 65 536.
					 */
					 bCmdBuff[wCmdLen++] = 0x00;
					 bCmdBuff[wCmdLen++] = 0x00; /* This byte is set to 0x00 since maximum bytes received will be either 0x08 or 0x10 as per ref arch ver 0.14*/
					 bCmdBuff[wCmdLen++] = bLe;

				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = bLe;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];
			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp));
			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}
			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
	}

	bISOGetChallengeState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOExternalAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint8, ANFCRL_VAR) bLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  static VAR(uint8, ANFCRL_VAR) bISOExternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOExternalAuthenticateState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:
			/* Check if Lc is passed */
			if (0U != (bOption & 0x01U))
			{
				/* Check whether Length Lc is represented in short APDU or extended APDU */
				if(bExtendedLenApdu == 0x01U)
				{
					/* Extended APDU */
					bCmdBuff[wCmdLen++] = 0x00; /* first byte will be 0x00 if Ext APDU present. Next 2 byte contains actual data */
					bCmdBuff[wCmdLen++] = 0x00; /* As of now this field will be set to 0x00 since maximum data that can be sent is 16 bytes or 32 bytes. In case if data to be sent exceeds 255 bytes, this byte shall be used  */
					bCmdBuff[wCmdLen++] = bLc;  /* Actual data to be sent */
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = bLc;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			if ((0U != ((bOption & 0x01U))) && (bLc > 0U))
			{
				bISOExternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;
			}

			bISOExternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pDataIn,
				(uint16)bLc,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOExternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD2:
			wCmdLen = 0;
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];
			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp));
			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}
			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
	}

	bISOExternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_ISOInternalAuthenticate(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
  VAR(uint8, ANFCRL_VAR) bLc, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn, VAR(uint32, ANFCRL_VAR) dwLe, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxlen = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRecv = NULL;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM bLePtr = NULL;
  static VAR(uint8, ANFCRL_VAR) bISOInternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_IDLE;

	switch(bISOInternalAuthenticateState)
	{
		case PHAL_MFDFEVX_INT_STATE_IDLE:

			/* Handle for 3 bytes Lc */
			if (0U != (bOption & 0x01U))
			{
				/* Check whether Length Lc is represented in short APDU or extended APDU */
				if(bExtendedLenApdu == 0x01U)
				{
					bCmdBuff[wCmdLen++] = 0x00; /* first byte will be 0x00 if Ext APDU present. Next 2 byte contains actual data */
					bCmdBuff[wCmdLen++] = 0x00; /* As of now this field will be set to 0x00 since maximum data that can be sent is 8 bytes or 16 bytes. In case if data to be sent exceeds 255 bytes, this byte shall be used  */
					bCmdBuff[wCmdLen++] = bLc;  /* Actual data to be sent */
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = bLc;
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			if ((0U != ((bOption & 0x01U))) && (bLc > 0U))
			{
				bISOInternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD1;
				return PH_STATUS_INPROCESS;
			}

			bISOInternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_CONT,
				pDataIn,
				(uint16)bLc,
				&pRecv,
				&wRxlen
				));
			PH_BREAK_ON_FAILURE(statusTmp);
			bISOInternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHAL_MFDFEVX_INT_STATE_CMD2:
			/* Initialize LcPtr and LePtr */
			bLePtr = (uint8 *)(&dwLe);
			wCmdLen = 0u;
			/* As per ISO/IEC:7816-4(2005), Section 5, An extended Le field consists of either three bytes
			 * (one byte set to '00' followed by two bytes with any
			 * value) if the Lc field is absent, or two bytes (with any value) if an extended Lc field is present.
			 */
			if (0U != (bOption & 0x02U))
			{
				/* Check whether Length is represented in extended APDU format and Lc is present.
				 * If true, then Le should represented in 2 bytes else Le should be represented in 3 bytes
				 */
				 if(bExtendedLenApdu == 0x01U)
				{
					/* Check if Lc is present */
					if(0U != (bOption & 0x01U))
					{
						bCmdBuff[wCmdLen++] = bLePtr[1];
						bCmdBuff[wCmdLen++] = bLePtr[0];
					}
					else
					{
						bCmdBuff[wCmdLen++] = 0x00U;
						bCmdBuff[wCmdLen++] = bLePtr[1];
						bCmdBuff[wCmdLen++] = bLePtr[0];
					}
				}
				else
				{
					/* Short APDU */
					bCmdBuff[wCmdLen++] = *(bLePtr);
				}
			}
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalMifare_ExchangeL4(
				pPalMifareDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				bCmdBuff,
				wCmdLen,
				&pRecv,
				&wRxlen
				));

			PH_BREAK_ON_FAILURE(statusTmp);

			statusTmp = pRecv[wRxlen - 2u];
			statusTmp <<= 8U;
			statusTmp |= pRecv[wRxlen - 1u];
			PH_CHECK_FAILURE_FCT(statusTmp, phalMfdfEVx_Int_ComputeErrorResponse(pDataParams, statusTmp));
			if (pDataLen != NULL)
			{
				*pDataLen = wRxlen -2u;
			}
			if (ppDataOut != NULL)
			{
				*ppDataOut = pRecv;
			}
			break;
		default:
			break;
	}

	bISOInternalAuthenticateState = PHAL_MFDFEVX_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_GetCmdCode(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdCode)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;

	switch(PH_GET_COMPID(pDataParams))
	{
		case PHAL_MFDFEVX_SW_ID:
			*pCmdCode = ((phalMfdfEVx_Sw_DataParams_t *)pDataParams)->bCmdCode;
			break;

		default:
			wStatus = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
			break;
	}

	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Int_SetCmdCode(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCmdCode)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;

	switch(PH_GET_COMPID(pDataParams))
	{
		case PHAL_MFDFEVX_SW_ID:
			((phalMfdfEVx_Sw_DataParams_t *)pDataParams)->bCmdCode = bCmdCode;
			break;

		default:
			wStatus = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AL_MFDFEVX);
			break;
	}

	return wStatus;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_INT_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHALMFDFEVX_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDFEVX */

#ifdef __cplusplus
}
#endif
