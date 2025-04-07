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
*   @file    phpalMifare_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palMifare_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalMifare MIFARE(R)
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

#include <ph_Status.h>
#include <phhalHw.h>
#include <phpalMifare.h>
#ifdef NXPBUILD__PHPAL_I14443P4
#include <phpalI14443p4.h>
#endif
#include <ph_RefDefs.h>
#include <phTools.h>

#ifdef NXPBUILD__PHPAL_MIFARE_SW
#include "phpalMifare_Sw.h"
#include "../phpalMifare_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalMifare_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALMIFARE_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALMIFARE_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALMIFARE_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALMIFARE_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALMIFARE_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalMifare_Sw.h header file are of the same vendor */
#if (PHPALMIFARE_SW_VENDOR_ID_C != PHPALMIFARE_SW_VENDOR_ID)
    #error "phpalMifare_Sw.c and phpalMifare_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalMifare_Sw.h header file are of the same Autosar version */
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALMIFARE_SW_AR_RELEASE_REVISION_VERSION_C != PHPALMIFARE_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalMifare_Sw.c and phpalMifare_Sw.h are different"
#endif
/* Check if current file and phpalMifare_Sw.h header file are of the same Software version */
#if ((PHPALMIFARE_SW_SW_MAJOR_VERSION_C != PHPALMIFARE_SW_SW_MAJOR_VERSION) || \
     (PHPALMIFARE_SW_SW_MINOR_VERSION_C != PHPALMIFARE_SW_SW_MINOR_VERSION) || \
     (PHPALMIFARE_SW_SW_PATCH_VERSION_C != PHPALMIFARE_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalMifare_Sw.c and phpalMifare_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_MIFARE_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_MIFARE_SW
#define PHPAL_MIFARE_STATE_INIT 			0U
#define PHPAL_MIFARE_STATE_CMD1				1U
#define PHPAL_MIFARE_STATE_CMD2				2U
#define PHPAL_MIFARE_STATE_CMD3				3U
#define PHPAL_MIFARE_STATE_CMD4				4U
#define PHPAL_MIFARE_STATE_CMD5				5U
#define PHPAL_MIFARE_STATE_CMD6				6U
#define PHPAL_MIFARE_STATE_DISABLE_PARITY	7U
#define PHPAL_MIFARE_STATE_RESTORE_PARITY	8U
#define PHPAL_MIFARE_STATE_DISABLE_TXCRC	9U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bPalMifareState = PHPAL_MIFARE_STATE_INIT;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_Init(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams,
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalI14443p4DataParams
	)
{
	if (sizeof(phpalMifare_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_MIFARE);
	}
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pHalDataParams);

	/* init private data */
	pDataParams->wId                    = PH_COMP_PAL_MIFARE | PHPAL_MIFARE_SW_ID;
	pDataParams->pHalDataParams         = pHalDataParams;
	pDataParams->pPalI14443p4DataParams = pPalI14443p4DataParams;
	bPalMifareState = PHPAL_MIFARE_STATE_INIT;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeL3(
	P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
	VAR(uint16, ANFCRL_VAR) wTxLength,
	P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValidBits = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcIn = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcCalc = 0U;

	switch(bPalMifareState)
	{
		case PHPAL_MIFARE_STATE_INIT:
			/* Switch CRC modes in case of first part of exchange. */
			if ((0U == ((wOption & PH_EXCHANGE_BUFFERED_BIT))))
			{
				/* Enable TxCrc */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXCRC, PH_ON));
				PH_CHECK_SUCCESS(statusTmp);

				bPalMifareState = PHPAL_MIFARE_STATE_CMD1;
			}
			else
			{
				bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
				return PH_STATUS_INPROCESS;
			}
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD1:
			/* Disable RxCrc */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXCRC, PH_OFF));
			status = statusTmp;
			PH_BREAK_ON_FAILURE(status);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD2:
			/* Check if caller has provided valid RxBuffer */
			if (ppRxBuffer == NULL)
			{
				ppRxBuffer = &pDataParams->pRxBuffer;
			}
			if (pRxLength == NULL)
			{
				pRxLength = &pDataParams->wRxLength;
			}
			/* Perform Exchange */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				wOption,
				pTxBuffer,
				wTxLength,
				ppRxBuffer,
				pRxLength));

			bPalMifareState = PHPAL_MIFARE_STATE_INIT;

			/* Return if no real exchange is done */
			if (0U != (wOption & PH_EXCHANGE_BUFFERED_BIT))
			{
				return status;
			}

			/* ACK/NAK Handling */
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)
			{
				/* Check for protocol error */
				if (*pRxLength != 1U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_MIFARE);
				}

				/* Retrieve bitcount */
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXLASTBITS, &wValidBits));

				/* Check for protocol error */
				if (wValidBits != 4U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_MIFARE);
				}

				/* ACK/NAK Mapping */
				switch ((*ppRxBuffer)[0])
				{
					/* ACK -> everything OK */
				case PHPAL_MIFARE_RESP_ACK:
					status = PH_ERR_SUCCESS;
					break;
					/* Mapping of NAK codes: */
				case PHPAL_MIFARE_RESP_NAK0:
					status = PHPAL_MIFARE_ERR_NAK0;
					break;
				case PHPAL_MIFARE_RESP_NAK1:
					status = PHPAL_MIFARE_ERR_NAK1;
					break;
				case PHPAL_MIFARE_RESP_NAK4:
					status = PHPAL_MIFARE_ERR_NAK4;
					break;
				case PHPAL_MIFARE_RESP_NAK5:
					status = PHPAL_MIFARE_ERR_NAK5;
					break;
				case PHPAL_MIFARE_RESP_NAK6:
					status = PHPAL_MIFARE_ERR_NAK6;
					break;
				case PHPAL_MIFARE_RESP_NAK7:
					status = PHPAL_MIFARE_ERR_NAK7;
					break;
				case PHPAL_MIFARE_RESP_NAK9:
					status = PHPAL_MIFARE_ERR_NAK9;
					break;
				default:
					status = PH_ERR_PROTOCOL_ERROR;
					break;
				}
			}
			/* Normal data stream with CRC */
			else
			{
				/* Check status */
				PH_CHECK_SUCCESS(status);

				/* Check length (min. 1 byte + 2 byte CRC) */
				if (*pRxLength < 3U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_MIFARE);
				}

				/* Retrieve CRC */
				wCrcIn  = (uint16)(((uint16)(*ppRxBuffer)[(*pRxLength) - 1U]) << 8U);
				wCrcIn |= (uint16)((*ppRxBuffer)[(*pRxLength) - 2U]);

				/* Remove CRC from input data */
				*pRxLength -= 2U;

				/* Calculate CRC */
				PH_CHECK_SUCCESS_FCT(statusTmp, phTools_CalculateCrc16(
					PH_TOOLS_CRC_OPTION_DEFAULT,
					PH_TOOLS_CRC16_PRESET_ISO14443A,
					PH_TOOLS_CRC16_POLY_ISO14443,
					*ppRxBuffer,
					*pRxLength,
					&wCrcCalc));

				/* CRC Check -> Compare input and calculated crc */
				if (wCrcIn == wCrcCalc)
				{
					status = PH_ERR_SUCCESS;
				}
				else
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_PAL_MIFARE);
				}
			}
			break;
	}

	bPalMifareState = PHPAL_MIFARE_STATE_INIT;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeL4(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	)
{
#ifdef NXPBUILD__PHPAL_I14443P4
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;

	switch(bPalMifareState)
	{
		case PHPAL_MIFARE_STATE_INIT:
			/* Not available if no Layer4 has been set */
			if (pDataParams->pPalI14443p4DataParams == NULL)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_MIFARE);
			}
			/* Enable TxCrc */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXCRC, PH_ON));
			PH_CHECK_SUCCESS(statusTmp);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD1;
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD1:
			/* Enable RxCrc */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXCRC, PH_ON));
			PH_BREAK_ON_FAILURE(statusTmp);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD2:
			/* Perform Exchange */
			PH_CHECK_INPROCESS_FCT(statusTmp, phpalI14443p4_Exchange(
				pDataParams->pPalI14443p4DataParams,
				wOption,
				pTxBuffer,
				wTxLength,
				ppRxBuffer,
				pRxLength));
			break;
	}

	bPalMifareState = PHPAL_MIFARE_STATE_INIT;
	return statusTmp;
#else
	/* satisfy compiler */
	if (pDataParams || wOption || pTxBuffer || wTxLength || ppRxBuffer || pRxLength);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_MIFARE);
#endif
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangePc(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	)
{
#ifdef NXPBUILD__PHPAL_I14443P4
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0U;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusExchange = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsoFrame[3] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsoFrameLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCidConfig = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wNadConfig = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcIn = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBlockNo = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcCalc = 0U;

	/* satisfy compiler warning*/
	PH_UNUSED_VARIABLE(wOption);

	switch(bPalMifareState)
	{
		case PHPAL_MIFARE_STATE_INIT:
			/* Not available if no Layer4 has been set */
			if (pDataParams->pPalI14443p4DataParams == NULL)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_MIFARE);
			}
			/* Retrieve ISO 14443-4 Protocol Parameters */
			PH_CHECK_SUCCESS_FCT(status, phpalI14443p4_GetConfig(pDataParams->pPalI14443p4DataParams, PHPAL_I14443P4_CONFIG_BLOCKNO, &wBlockNo));
			PH_CHECK_SUCCESS_FCT(status, phpalI14443p4_GetConfig(pDataParams->pPalI14443p4DataParams, PHPAL_I14443P4_CONFIG_CID, &wCidConfig));
			PH_CHECK_SUCCESS_FCT(status, phpalI14443p4_GetConfig(pDataParams->pPalI14443p4DataParams, PHPAL_I14443P4_CONFIG_NAD, &wNadConfig));

			/* Build ISO 14443-4 I-Block Frame */
			bIsoFrame[0] = (uint8)(0x02U | wBlockNo);
			wIsoFrameLen = 1U;

			/* Append CID if needed */
			if (0U != (wCidConfig & 0xFF00U))
			{
				bIsoFrame[0] |= 0x08U;
				bIsoFrame[wIsoFrameLen++] = (uint8)(wCidConfig & 0x00FFU);
			}

			/* Append NAD if needed */
			if (0U != (wNadConfig & 0xFF00U))
			{
				bIsoFrame[0] |= 0x04U;
				bIsoFrame[wIsoFrameLen++] = (uint8)(wNadConfig & 0x00FFU);
			}

			/* Calculate CRC over the frame */
			PH_CHECK_SUCCESS_FCT(status, phTools_CalculateCrc16(
				PH_TOOLS_CRC_OPTION_DEFAULT,
				PH_TOOLS_CRC16_PRESET_ISO14443A,
				PH_TOOLS_CRC16_POLY_ISO14443,
				bIsoFrame,
				wIsoFrameLen,
				&wCrcCalc));

			/* Calculate CRC over the data to send */
			PH_CHECK_SUCCESS_FCT(status, phTools_CalculateCrc16(
				PH_TOOLS_CRC_OPTION_DEFAULT,
				wCrcCalc,
				PH_TOOLS_CRC16_POLY_ISO14443,
				pTxBuffer,
				wTxLength,
				&wCrcCalc));

			bPalMifareState = PHPAL_MIFARE_STATE_CMD1;
			/* No break */

		case PHPAL_MIFARE_STATE_CMD1:
			/* Preload the frame */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_BUFFER_FIRST,
				bIsoFrame,
				wIsoFrameLen,
				NULL,
				NULL));
			PH_BREAK_ON_FAILURE(status);

			bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
			/* No break */

		case PHPAL_MIFARE_STATE_CMD2:
			/* Disable Tx-/RxCRC */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXCRC, PH_OFF));
			PH_BREAK_ON_FAILURE(status);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD3;
			/*no break*/

		case PHPAL_MIFARE_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXCRC, PH_OFF));
			PH_BREAK_ON_FAILURE(status);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD4;
			/*no break*/

		case PHPAL_MIFARE_STATE_CMD4:
			/* Ignore wOption byte */
			/*wOption = PH_EXCHANGE_DEFAULT; */

			/* Check if caller has provided valid RxBuffer */
			if (ppRxBuffer == NULL)
			{
				ppRxBuffer = &pDataParams->pRxBuffer;
			}
			if (pRxLength == NULL)
			{
				pRxLength = &pDataParams->wRxLength;
			}

			/* Perform Exchange */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				pTxBuffer,
				wTxLength,
				ppRxBuffer,
				pRxLength));

			statusExchange = status;
			bPalMifareState = PHPAL_MIFARE_STATE_CMD5;
			/*no break*/

		case PHPAL_MIFARE_STATE_CMD5:
			/* Enable Tx-/RxCRC again */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXCRC, PH_ON));
			PH_BREAK_ON_FAILURE(status);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD6;
			/*no break*/

		case PHPAL_MIFARE_STATE_CMD6:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXCRC, PH_ON));
			PH_BREAK_ON_FAILURE(status);

			/* Check for Exchange Error */
			status = statusExchange;
			PH_BREAK_ON_FAILURE(status);

			/* Response length check */
			if (*pRxLength < 2U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_MIFARE);
			}

			/* Retrieve CRC */
			wCrcIn  = (uint16)(((uint16)(*ppRxBuffer)[(*pRxLength) - 1U]) << 8U);
			wCrcIn |= (uint16)((*ppRxBuffer)[(*pRxLength) - 2U]);

			/* Remove CRC from input data */
			*pRxLength -= 2U;

			/* Calculate CRC over the received data */
			PH_CHECK_FAILURE_FCT(status, phTools_CalculateCrc16(
				PH_TOOLS_CRC_OPTION_DEFAULT,
				wCrcCalc,
				PH_TOOLS_CRC16_POLY_ISO14443,
				*ppRxBuffer,
				*pRxLength,
				&wCrcCalc));

			/* CRC Check -> Compare input and calculated crc */
			if (wCrcIn != wCrcCalc)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_PAL_MIFARE);
				PH_BREAK_ON_FAILURE(status);
			}

			/* Update ISO14443-4 Block Number */
			PH_CHECK_FAILURE_FCT(status, phpalI14443p4_SetConfig(pDataParams->pPalI14443p4DataParams, PHPAL_I14443P4_CONFIG_BLOCKNO, (uint16)(wBlockNo ^ 0x01U)));
			break;
	}

	statusExchange = 0U;
	bPalMifareState = PHPAL_MIFARE_STATE_INIT;
	return status;
#else
	/* satisfy compiler */
	if (pDataParams || wOption || pTxBuffer || wTxLength || ppRxBuffer || pRxLength);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_MIFARE);
#endif
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeRaw(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  VAR(uint8, ANFCRL_VAR) bTxLastBits,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLastBits
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusExchange = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValue = 0U;

	switch(bPalMifareState)
	{
		case PHPAL_MIFARE_STATE_INIT:
			/* Do not switch Parity / CRC modes if no real exchange is done */
			if ((0U == ((wOption & PH_EXCHANGE_BUFFERED_BIT))))
			{
				/* TxLastBits > 7 is invalid  */
				if (bTxLastBits > 7U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_MIFARE);
				}

				/* Retrieve Parity-setting */
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_PARITY, &wValue));

				bPalMifareState = PHPAL_MIFARE_STATE_DISABLE_PARITY;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* TxLastBits != 0 is invalid for buffered operation */
				if (bTxLastBits != 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_MIFARE);
				}
			}
			bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHPAL_MIFARE_STATE_DISABLE_PARITY:
			/* Disable Parity */
			if (wValue == PH_ON)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_PARITY, PH_OFF));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			bPalMifareState = PHPAL_MIFARE_STATE_DISABLE_TXCRC;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHPAL_MIFARE_STATE_DISABLE_TXCRC:
			/* Disable TxCrc */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXCRC, PH_OFF));
			PH_BREAK_ON_FAILURE(statusTmp);
			bPalMifareState = PHPAL_MIFARE_STATE_CMD1;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD1:
			/* Disable RxCrc */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXCRC, PH_OFF));
			PH_BREAK_ON_FAILURE(status);
			/* Set TxLastBits */
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXLASTBITS, bTxLastBits));
			bPalMifareState = PHPAL_MIFARE_STATE_CMD2;
			/*no break*/
		case PHPAL_MIFARE_STATE_CMD2:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				wOption,
				pTxBuffer,
				wTxLength,
				ppRxBuffer,
				pRxLength));
			bPalMifareState = PHPAL_MIFARE_STATE_INIT;
			/* Return if no real exchange is done */
			if (0U != (wOption & PH_EXCHANGE_BUFFERED_BIT))
			{
				return status;
			}

			statusExchange = status;
			bPalMifareState = PHPAL_MIFARE_STATE_RESTORE_PARITY;
			return PH_STATUS_INPROCESS;
			/* No break */

		case PHPAL_MIFARE_STATE_RESTORE_PARITY:
			/* Restore Parity-setting again since many PAL layers expect it */
			if (wValue == PH_ON)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_PARITY, wValue));
				PH_BREAK_ON_FAILURE(statusTmp);
			}

			status = statusExchange;
			/* Retrieve RxLastBits */
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)
			{
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXLASTBITS, &wValue));
				*pRxLastBits = (uint8)wValue;
			}
			break;
	}

	statusExchange = PH_ERR_SUCCESS;
	wValue = 0U;
	bPalMifareState = PHPAL_MIFARE_STATE_INIT;
	PH_CHECK_SUCCESS(statusTmp);
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_MfcAuthenticateKeyNo(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint8, ANFCRL_VAR) bBlockNo,
  VAR(uint8, ANFCRL_VAR) bKeyType,
  VAR(uint16, ANFCRL_VAR) wKeyNo,
  VAR(uint16, ANFCRL_VAR) wKeyVersion,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
	)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	/* Execute HAL authenticate function */
	PH_CHECK_INPROCESS_FCT(status, phhalHw_MfcAuthenticateKeyNo(
		pDataParams->pHalDataParams,
		bBlockNo,
		bKeyType,
		wKeyNo,
		wKeyVersion,
		pUid));

	/* Change component code for AUTH error and invalid parameter */
	if (((status & PH_ERR_MASK) == PH_ERR_AUTH_ERROR) ||
		((status & PH_ERR_MASK) == PH_ERR_INVALID_PARAMETER))
	{
		status = PH_ADD_COMPCODE((status & PH_ERR_MASK), PH_COMP_PAL_MIFARE);
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_MfcAuthenticate(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint8, ANFCRL_VAR) bBlockNo,
  VAR(uint8, ANFCRL_VAR) bKeyType,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
	)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Execute HAL authenticate function */
	PH_CHECK_INPROCESS_FCT(status, phhalHw_MfcAuthenticate(
		pDataParams->pHalDataParams,
		bBlockNo,
		bKeyType,
		pKey,
		pUid));

	/* Change component code for AUTH error and invalid parameter */
	if (((status & PH_ERR_MASK) == PH_ERR_AUTH_ERROR) ||
		((status & PH_ERR_MASK) == PH_ERR_INVALID_PARAMETER))
	{
		status = PH_ADD_COMPCODE((status & PH_ERR_MASK), PH_COMP_PAL_MIFARE);
	}

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_SetMinFdtPc(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wValue
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Execute HAL Setconfig function */
	PH_CHECK_INPROCESS_FCT( status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_SETMINFDT, wValue));
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_GetConfig(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wConfig,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
	)
{
#ifdef NXPBUILD__PHPAL_I14443P4
	return phpalI14443p4_GetConfig(
		pDataParams->pPalI14443p4DataParams,
		wConfig,
		pValue);
#else
	/* satisfy compiler */
	PH_UNUSED_VARIABLE (wConfig);
	PH_UNUSED_VARIABLE (pValue);

	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_MIFARE);
#endif /* NXPBUILD__PHPAL_I14443P4 */
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_MIFARE_SW */

#ifdef __cplusplus
}
#endif
