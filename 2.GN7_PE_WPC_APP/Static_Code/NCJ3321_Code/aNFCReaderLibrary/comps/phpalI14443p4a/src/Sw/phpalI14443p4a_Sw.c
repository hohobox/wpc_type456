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
*   @file    phpalI14443p4a_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4a_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4a ISO/IEC 14443-4A
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
#include <phpalI14443p3a.h>
#include <phpalI14443p4a.h>
#include <ph_RefDefs.h>
#include <phTools.h>
#include <phNxpNfcRdLib_Config.h>
#include <phLog.h>

#ifdef NXPBUILD__PHPAL_I14443P4A_SW

#include "phpalI14443p4a_Sw.h"
#include "phpalI14443p4a_Sw_Int.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4a_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4A_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4A_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4A_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4A_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4A_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4a_Sw.h header file are of the same vendor */
#if (PHPALI14443P4A_SW_VENDOR_ID_C != PHPALI14443P4A_SW_VENDOR_ID)
    #error "phpalI14443p4a_Sw.c and phpalI14443p4a_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4a_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4A_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4A_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4a_Sw.c and phpalI14443p4a_Sw.h are different"
#endif
/* Check if current file and phpalI14443p4a_Sw.h header file are of the same Software version */
#if ((PHPALI14443P4A_SW_SW_MAJOR_VERSION_C != PHPALI14443P4A_SW_SW_MAJOR_VERSION) || \
     (PHPALI14443P4A_SW_SW_MINOR_VERSION_C != PHPALI14443P4A_SW_SW_MINOR_VERSION) || \
     (PHPALI14443P4A_SW_SW_PATCH_VERSION_C != PHPALI14443P4A_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4a_Sw.c and phpalI14443p4a_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4A_SW
#define I14443P4A_SW_IS_INVALID_BLOCK_STATUS(bStatus)                       \
    ((                                                                      \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT) ||                     \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR) ||                \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_FRAMING_ERROR) ||                  \
    (((bStatus) & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR))                  \
    ? 1U : 0U                                                                 \
    )

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM bI14443p4a_FsTable[PHPAL_I14443P4A_FRAMESIZE_MAX+1] = {14, 22, 30, 38, 46, 62, 94, 126, 254};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/


/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_Init(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                                  )
{
	if (sizeof(phpalI14443p4a_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P4A);
	}
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pHalDataParams);

	/* reset state variables for Non-Blocking */
	pDataParams->eActCardState = PHPAL_I14443P4A_ACTCARD_IDLE;
	pDataParams->eRatsState = PHPAL_I14443P4A_RATS_IDLE;
	pDataParams->ePpsState = PHPAL_I14443P4A_PPS_IDLE;

	/* init private data */
	pDataParams->wId = PH_COMP_PAL_ISO14443P4A | PHPAL_I14443P4A_SW_ID;
	pDataParams->pHalDataParams = pHalDataParams;
	pDataParams->bCidSupported = PH_OFF;
	pDataParams->bNadSupported = PH_OFF;
	pDataParams->bCid = 0x00;
	pDataParams->bBitRateCaps = 0x00;
	pDataParams->bFwi = PHPAL_I14443P4A_SW_FWI_DEFAULT;
	pDataParams->bFsci = PHPAL_I14443P4A_SW_FSCI_DEFAULT;
	pDataParams->bFsdi = 0x00;
	pDataParams->bDri = 0x00;
	pDataParams->bDsi = 0x00;
	pDataParams->bOpeMode = RD_LIB_MODE_ISO;
	pDataParams->bRetryCount = PHPAL_I14443P4A_RATS_RETRY_MAX;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_SetConfig(
                                       P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wConfig,
                                       VAR(uint16, ANFCRL_VAR) wValue
                                     )
{
	switch (wConfig)
	{
	/* Emvco: To Define Running Mode for RdLib: Either NFC, EMVCO or ISO */
	case PHPAL_I14443P4A_CONFIG_OPE_MODE:
	{
		pDataParams->bOpeMode = (uint8) wValue;
		break;
	}

	case PHPAL_I14443P4A_CONFIG_RATS_RETRY_COUNT:
	{
		if (!(((wValue & 0xFFU) == PHPAL_I14443P4A_RATS_RETRY_MIN) || ((wValue & 0xFFU) == PHPAL_I14443P4A_RATS_RETRY_MAX)))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
		}

		pDataParams->bRetryCount = (uint8) wValue;
		break;
	}

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P4A);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_GetProtocolParams(
    P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci
    )
{
	*pCidEnabled = pDataParams->bCidSupported;
	*pCid = pDataParams->bCid;
	*pNadSupported = pDataParams->bNadSupported;
	*pFwi = pDataParams->bFwi;
	*pFsdi = pDataParams->bFsdi;
	*pFsci = pDataParams->bFsci;

	return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_ActivateCard(
        P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        VAR(uint8, ANFCRL_VAR) bFsdi,
        VAR(uint8, ANFCRL_VAR) bCid,
        VAR(uint8, ANFCRL_VAR) bDri,
        VAR(uint8, ANFCRL_VAR) bDsi,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	switch (pDataParams->eActCardState)
	{
		case PHPAL_I14443P4A_ACTCARD_IDLE:

			/* Check Dri value */
			switch (bDri)
			{
			case PHPAL_I14443P4A_DATARATE_106:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_212:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_424:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_848:
				break;
			default:
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}

			/* Check Dri value */
			switch (bDsi)
			{
			case PHPAL_I14443P4A_DATARATE_106:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_212:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_424:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_848:
				break;
			default:
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}
			I14443P4_LOG("~~~ ACTIVATION CARD START ~~~ \r\n");
			pDataParams->eActCardState = PHPAL_I14443P4A_ACTCARD_RATS;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P4A_ACTCARD_RATS:
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4a_Sw_Rats(pDataParams, bFsdi, bCid, pAts));
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				/* Perform PPS */
				if ((bDri != PHPAL_I14443P4A_DATARATE_106) || (bDsi != PHPAL_I14443P4A_DATARATE_106))
				{
					pDataParams->eActCardState = PHPAL_I14443P4A_ACTCARD_PPS;
#if 0 // CAS_KR: no break for fast card detection
					return PH_STATUS_INPROCESS;
#else
					PH_CHECK_INPROCESS_FCT(status, phpalI14443p4a_Sw_Pps(pDataParams, bDri, bDsi));
#endif
				}
			}
			break;

		case PHPAL_I14443P4A_ACTCARD_PPS:
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4a_Sw_Pps(pDataParams, bDri, bDsi));
	}
	pDataParams->eActCardState = PHPAL_I14443P4A_ACTCARD_IDLE;
	return status;
}

/**
* @brief          New function non-blocking to replace on the original function phpalI14443p4a_Sw_Rats
* @details        This function run at asynchronous mode
*
* @return         phStatus_t
*                 SUCCESS or Error indicates the activation finished, returning result
*                 IN_PROGRESS indicates it's processing the command in Non blocking mode
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_Rats(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint8, ANFCRL_VAR) bFsdi,
                                  VAR(uint8, ANFCRL_VAR) bCid,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts
                                  )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM cmd[2] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAtsIndex = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSfgi = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwSfgt = 0U;
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwFwt = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwDelay = 0U;
	static VAR(I14443P4A_RATS_StateType_t, ANFCRL_VAR) bRatsStateNext = PHPAL_I14443P4A_RATS_IDLE;
	static VAR(uint16, ANFCRL_VAR) wWaitPeriod = 0U;
	static VAR(uint8, ANFCRL_VAR) bWaitUnit = 0U;
	static VAR(phStatus_t, ANFCRL_VAR) statusbkp = 0U;

	switch (pDataParams->eRatsState)
	{
#if 1 // CAS_KR: for fast card detection
	case PHPAL_I14443P4A_RATS_WAIT:
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Wait(pDataParams->pHalDataParams, bWaitUnit, wWaitPeriod));
		PH_BREAK_ON_FAILURE(statusTmp);
		pDataParams->eRatsState = bRatsStateNext;
		return PH_STATUS_INPROCESS;
#endif
	case PHPAL_I14443P4A_RATS_IDLE:
		/* Parameter check */
		if (pDataParams->bOpeMode != RD_LIB_MODE_NFC)
		{
			if ((bFsdi > PHPAL_I14443P4A_FRAMESIZE_MAX) || (bCid > 14U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}
			if ((bFsdi < PHPAL_I14443P4A_EMVCO_FRAMESIZE_MIN)
					&& (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}
		}
		else
		{
			if ((bFsdi > PHPAL_I14443P4A_NFC_FRAMESIZE_MAX) || (bCid > 14U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}
		}

        /* Set Activation timeout */
        pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT;
        return PH_STATUS_INPROCESS;
    case PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT:
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
				PHPAL_I14443P4A_SW_FWT_ACTIVATION_US + PHPAL_I14443P4A_SW_EXT_TIME_US));
		PH_BREAK_ON_FAILURE(statusTmp);
		/* Send Rats command */
		cmd[0] = PHPAL_I14443P4A_SW_RATS;
		cmd[1] = (uint8) (((bFsdi << 4U) & 0xF0U) | (bCid & 0x0FU));
		I14443P4_LOG_BUF(">>> P4A_RATS_SEND:", cmd, 2U);
		bAtsIndex = pDataParams->bRetryCount + 1u;
		pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SEND;
#if 0 // CAS_KR: no break for fast card detection
		return PH_STATUS_INPROCESS;
#endif

#if 0 // CAS_KR: no break for fast card detection
	case PHPAL_I14443P4A_RATS_WAIT:
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Wait(pDataParams->pHalDataParams, bWaitUnit, wWaitPeriod));
		PH_BREAK_ON_FAILURE(statusTmp);
		pDataParams->eRatsState = bRatsStateNext;
		return PH_STATUS_INPROCESS;
#endif

	case PHPAL_I14443P4A_RATS_SEND:
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, cmd, 2u, &pResp, &wRespLength));
#ifdef NXPBUILD__PH_LOG_EX
		if (status != PH_ERR_SUCCESS)
		{
			I14443P4_LOG("<<< P4A_RATS_RESPONSE Status:%0X \r\n", status);
		}
		else
		{
			I14443P4_LOG_BUF("<<< P4A_RATS_RESPONSE:", pResp, (uint8 )wRespLength);
		}
#endif
		bAtsIndex--;
		if ((bAtsIndex > 0U) && (PH_ERR_SUCCESS != (status & PH_ERR_MASK)))
		{
			I14443P4_LOG("*** RESEND RATS CMD  *** \r\n");
			/* Return error other than Timeout or Noise Error */
			pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SEND;
			/* Emvco: case_id TA313, TA307_X, TA306_10-15, TA340_1 */
			return PH_STATUS_INPROCESS;
		}
		statusbkp = status;
		if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
			/* Check for protocol error */
			if (((uint8) wRespLength != pResp[0]) || (wRespLength < 1U))
			{
				I14443P4_LOG("^^^ PROTOCOL_ERROR: CHECK BUFFER ERROR \r\n");
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
				break;
			}

			/* Copy ATS buffer */
			(void) memcpy(pAts, pResp, wRespLength);

			/* Set default values */

			pDataParams->bCidSupported = PH_ON;
			pDataParams->bCid = bCid;

			pDataParams->bNadSupported = PH_OFF;
			pDataParams->bBitRateCaps = 0x00;
			pDataParams->bFwi = PHPAL_I14443P4A_SW_FWI_DEFAULT;
			pDataParams->bFsdi = bFsdi;
			pDataParams->bFsci = PHPAL_I14443P4A_SW_FSCI_DEFAULT;
			pDataParams->bDri = 0x00;
			pDataParams->bDsi = 0x00;
			bSfgi = PHPAL_I14443P4A_SW_SFGI_DEFAULT;

			/* Retrieve ATS information */
			/*  the maximum value of TL shall not exceed FSD-2 */
			if (pAts[0] > bI14443p4a_FsTable[bFsdi])
			{
				I14443P4_LOG("^^^ PROTOCOL_ERROR: CHECK BUFFER ERROR \r\n");
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
				break;
			}
			/* Start parsing with T0 byte */
			bAtsIndex = PHPAL_I14443P4A_SW_ATS_T0;

			/* Parse T0/TA/TB/TC */
			if (wRespLength > 1U)
			{
				/* Parse T0 */
				pDataParams->bFsci = pAts[bAtsIndex] & 0x0FU;
				if (pDataParams->bOpeMode != RD_LIB_MODE_NFC)
				{
					if (pDataParams->bFsci > PHPAL_I14443P4A_FRAMESIZE_MAX)
					{
						pDataParams->bFsci = PHPAL_I14443P4A_FRAMESIZE_MAX;
					}
				}
				else
				{ /* Nfc: Digital Specification Ver 1.1 Table 59 */
					if (pDataParams->bFsci > PHPAL_I14443P4A_NFC_FRAMESIZE_MAX)
					{
						pDataParams->bFsci = PHPAL_I14443P4A_NFC_FRAMESIZE_MAX;
					}
				}

				bAtsIndex++;

				/* Parse TA(1) */
				if (0U != (pAts[PHPAL_I14443P4A_SW_ATS_T0] & PHPAL_I14443P4A_SW_ATS_TA1_PRESENT))
				{
					/* Check for protocol error */
					if (wRespLength <= bAtsIndex)
					{
						statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
						break;
					}

					/* Check for RFU bit b4 (b4 shall be 0; 1 is RFU) */
					if (0U != (pAts[bAtsIndex] & 0x08U))
					{
						/* Only 106 kbps in both direction */
						pDataParams->bBitRateCaps = 0x00;
					}
					else
					{
						/* Store Bit rate capabilities */
						pDataParams->bBitRateCaps = pAts[bAtsIndex];
					}

					bAtsIndex++;
				}

				/* Parse TB(1) */
				if (0U != (pAts[PHPAL_I14443P4A_SW_ATS_T0] & PHPAL_I14443P4A_SW_ATS_TB1_PRESENT))
				{
					/* Check for protocol error */
					if (wRespLength <= bAtsIndex)
					{
						statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
						break;
					}
					else
					{
						/* Store Sfgi */
						bSfgi = pAts[bAtsIndex] & 0x0FU;
						if (bSfgi == 0x0FU)
						{
							bSfgi = PHPAL_I14443P4A_SW_SFGI_DEFAULT;
						}

						/* Store Fwi */
						pDataParams->bFwi = (pAts[bAtsIndex] >> 4U) & 0x0FU;
						if (pDataParams->bFwi == 0x0FU)
						{
							pDataParams->bFwi = PHPAL_I14443P4A_SW_FWI_DEFAULT;
						}

						bAtsIndex++;
					}
				}

				/* Parse TC(1) */
				if (0U != (pAts[PHPAL_I14443P4A_SW_ATS_T0] & PHPAL_I14443P4A_SW_ATS_TC1_PRESENT))
				{
					/* Check for protocol error */
					if (wRespLength <= bAtsIndex)
					{
						statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
						break;
					}
					else
					{
						/* NAD is supported only in ISO/IEC 14443-4 specification. */
						if (pDataParams->bOpeMode == RD_LIB_MODE_ISO)
						{
							/* Check bit 2-7 = 0 */
							if ((pAts[bAtsIndex] & 0xFCu) != 0U)
							{
								statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
								break;
							}

							/* Check NAD Support */
							if (0U != (pAts[bAtsIndex] & PHPAL_I14443P4A_SW_ATS_TC1_NAD_SUPPORT))
							{
								pDataParams->bNadSupported = PH_ON;
							}
						}

						/* Check CID Support */
						if ((pAts[bAtsIndex] & PHPAL_I14443P4A_SW_ATS_TC1_CID_SUPPORT) == 0U)
						{
							pDataParams->bCidSupported = PH_OFF;
							pDataParams->bCid = 0x00;
						}
					}
				}
			}

			/* Calculate SFGT in Microseconds */
			dwDelay = PHPAL_I14443P4A_SW_FWT_MIN_US * ((uint32) 1U << bSfgi);
			if (pDataParams->bOpeMode != RD_LIB_MODE_ISO)
			{
				dwDelay += (PHPAL_I14443P4A_DELTA_SFGT_US) * ((uint32) 1U << bSfgi);
			}
			dwSfgt = (uint32) dwDelay;

			I14443P4_LOG("*** ATS INFO - SFGi: %d -SFG time: %d \r\n", bSfgi, dwSfgt);
			/* Perform SFGT Wait */
			if (dwSfgt > 0xFFFFU)
			{
				bWaitUnit = PHHAL_HW_TIME_MILLISECONDS;
				wWaitPeriod = (uint16 )((dwSfgt / 1000U) + 1U);
				pDataParams->eRatsState = PHPAL_I14443P4A_RATS_WAIT;
			}
			else
			{
				bWaitUnit = PHHAL_HW_TIME_MICROSECONDS;
				wWaitPeriod = (uint16)dwSfgt;
				pDataParams->eRatsState = PHPAL_I14443P4A_RATS_WAIT;
			}
			bRatsStateNext = PHPAL_I14443P4A_RATS_FWTCONFIG;
		}
		/* Perform protocol error handling */
		else
		{
			if (I14443P4A_SW_IS_INVALID_BLOCK_STATUS(status) == 0U)
			{
				I14443P4_LOG("*** RATS RESP -> ERROR UNKNOW:%0X  *** \r\n", status);
				statusTmp = status;
				break;
			}
			/* Send S(DESELECT) command */
			I14443P4_LOG(">>> P4A_SDESELECT_SEND  \r\n");
			cmd[0] = PHPAL_I14443P4A_SW_S_BLOCK | PHPAL_I14443P4A_SW_S_BLOCK_RFU_BITS | PHPAL_I14443P4A_SW_PCB_DESELECT;
			/* Wait FWTmin after RATS */
			if ((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT)
			{
				bWaitUnit = PHHAL_HW_TIME_MICROSECONDS;
				wWaitPeriod = PHPAL_I14443P4A_SW_FWT_MIN_US + PHPAL_I14443P4A_SW_EXT_TIME_US;
				pDataParams->eRatsState = PHPAL_I14443P4A_RATS_WAIT;
				bRatsStateNext = PHPAL_I14443P4A_RATS_DESELSEND;
#if 1 // CAS_KR: for fast card detection
				//do "case PHPAL_I14443P4A_RATS_WAIT:"
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Wait(pDataParams->pHalDataParams, bWaitUnit, wWaitPeriod));
				PH_BREAK_ON_FAILURE(statusTmp);
				pDataParams->eRatsState = bRatsStateNext;
#endif
				return PH_STATUS_INPROCESS;
			}
			pDataParams->eRatsState = PHPAL_I14443P4A_RATS_DESELSEND;
		}
		return PH_STATUS_INPROCESS;

	case PHPAL_I14443P4A_RATS_DESELSEND:
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_DEFAULT,
				cmd,
				1u,
				&pResp,
				&wRespLength));

		I14443P4_LOG("<<< P3A_SDESELECT_RESPONSE:%0X  \r\n", statusTmp);
		/* S(DESELECT) failure */
		if (((statusTmp & PH_ERR_MASK) != PH_ERR_SUCCESS) || (wRespLength != 1U) || (pResp[0] != cmd[0]))
		{
			/* Set HLTA timeout */
			pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT;
			return PH_STATUS_INPROCESS;
		}
		else
		{
			/* S(DESELECT) success */
			/* Return error status of RATS exchange*/
			statusTmp = PH_ADD_COMPCODE(statusbkp, PH_COMP_PAL_ISO14443P4A);
		}
		break;
	case PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT:
        PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
                pDataParams->pHalDataParams,
                PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
                PHPAL_I14443P4A_SW_HALT_TIME_US));
        PH_BREAK_ON_FAILURE(statusTmp);

        /* Send HLTA */
        I14443P4_LOG(">>> P4A_HALT_SEND  \r\n");
        cmd[0] = PHPAL_I14443P4A_SW_HALT_CMD;
        cmd[1] = 0x00;

        pDataParams->eRatsState = PHPAL_I14443P4A_RATS_HALT;
        return PH_STATUS_INPROCESS;
	case PHPAL_I14443P4A_RATS_FWTCONFIG:
        /* Calculate FWT timeout */
        dwDelay = PHPAL_I14443P4A_SW_FWT_MIN_US;
        dwDelay = (dwDelay * ((uint32)1U << pDataParams->bFwi));

        if(pDataParams->bOpeMode == RD_LIB_MODE_ISO)
        {
            /* Add extension time */
            dwDelay = dwDelay + PHPAL_I14443P4A_SW_EXT_TIME_US;
        }
        else
        {
            /* As per Digital Spec V1.1 req 13.8.1.3, NFC Forum Device SHALL wait at least FWT + delta FWTT4AT for a Response */
            dwDelay = dwDelay + PHPAL_I14443P4A_SW_DELTA_FWT_US;

            if(pDataParams->bOpeMode == RD_LIB_MODE_EMVCO) {
                /* As per EMVCo, add delta Tpcd time along with delta FWT time */
                dwDelay += PHPAL_I14443P4A_SW_DELTA_TPCD_US;
            }
        }
        dwFwt = (uint32)dwDelay;

		I14443P4_LOG("*** CALCULATE & SET FWT TIMEOUT: %d *** \r\n", dwFwt);
		I14443P4_LOG("*** Fwi: %d \r\n", pDataParams->bFwi);

		/* Set FWT timeout */
		if (dwFwt > 0xFFFFU)
		{
            /* +1 is added to the timeout in millisecond to compensate the
             * fractional microseconds lost in division by 1000 */
            pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS;
		}
		else
		{
            pDataParams->eRatsState = PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US;
		}
        return PH_STATUS_INPROCESS;
	case PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS:
	    PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, (uint16 )((dwFwt / 1000U) + 1U)));
	    break;
	case PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US:
	    PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, (uint16 )dwFwt));
        break;
	case PHPAL_I14443P4A_RATS_HALT:
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_DEFAULT,
				cmd,
				2u,
				&pResp,
				&wRespLength));
		PH_BREAK_ON_FAILURE(statusTmp);
		/* Return error status of RATS exchange*/
		statusTmp = PH_ADD_COMPCODE(statusbkp, PH_COMP_PAL_ISO14443P4A);
	}
    dwFwt = 0U;
    pDataParams->eRatsState = PHPAL_I14443P4A_RATS_IDLE;
    return statusTmp;
}

/**
* @brief          New function non-blocking to replace on the original function phpalI14443p4a_Sw_Pps
* @details        This function run at asynchronous mode
*
* @return         phStatus_t
*                 SUCCESS or Error indicates the activation finished, returning result
*                 IN_PROGRESS indicates it's processing the command in Non blocking mode
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_Pps(
                 P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 VAR(uint8, ANFCRL_VAR) bDri,
                 VAR(uint8, ANFCRL_VAR) bDsi
								 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM cmd[3];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxDataRate;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxDataRate;

	switch (pDataParams->ePpsState)
	{
		case PHPAL_I14443P4A_PPS_IDLE:
			/* Check and convert Dri value */
			switch (bDri)
			{
				case PHPAL_I14443P4A_DATARATE_106:
					wTxDataRate = PHHAL_HW_RF_DATARATE_106;
					break;
				case PHPAL_I14443P4A_DATARATE_212:
					wTxDataRate = PHHAL_HW_RF_DATARATE_212;
					break;
				case PHPAL_I14443P4A_DATARATE_424:
					wTxDataRate = PHHAL_HW_RF_DATARATE_424;
					break;
				case PHPAL_I14443P4A_DATARATE_848:
					wTxDataRate = PHHAL_HW_RF_DATARATE_848;
					break;
				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}

			/* Check and convert Dsi value */
			switch (bDsi)
			{
				case PHPAL_I14443P4A_DATARATE_106:
					wRxDataRate = PHHAL_HW_RF_DATARATE_106;
					break;
				case PHPAL_I14443P4A_DATARATE_212:
					wRxDataRate = PHHAL_HW_RF_DATARATE_212;
					break;
				case PHPAL_I14443P4A_DATARATE_424:
					wRxDataRate = PHHAL_HW_RF_DATARATE_424;
					break;
				case PHPAL_I14443P4A_DATARATE_848:
					wRxDataRate = PHHAL_HW_RF_DATARATE_848;
					break;
				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P4A);
			}

			/* Send Pps command */
			cmd[0] = PHPAL_I14443P4A_SW_PPSS | pDataParams->bCid;
			cmd[1] = PHPAL_I14443P4A_SW_PPS0;
			cmd[2] = ((bDsi << 2U) & 0x0CU) | (bDri & 0x03U);
			I14443P4_LOG_BUF(">>> P4A_PPS_SEND:", cmd, 3U);
            pDataParams->ePpsState = PHPAL_I14443P4A_PPS_EXCHANGE;
			/*no break*/
		case PHPAL_I14443P4A_PPS_EXCHANGE:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, cmd, 3, &pResp, &wRespLength));
#ifdef NXPBUILD__PH_LOG_EX
			if (status != PH_ERR_SUCCESS)
			{
				I14443P4_LOG("<<< P4A_PPS_RESPONSE Status:%0X \r\n", status);
			}
			else
			{
				I14443P4_LOG_BUF("<<< P4A_PPS_RESPONSE:", pResp, (uint8 )wRespLength);
			}
#endif
			/* NAK means protocol error */
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
				break;
			}

			/* Success check */
			PH_BREAK_ON_FAILURE(status);

			/* Check length and start byte of PPS */
			if ((wRespLength != 1U) || (pResp[0] != (PHPAL_I14443P4A_SW_PPSS | pDataParams->bCid)))
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P4A);
				break;
			}
			/* Store data rates */
			pDataParams->bDri = bDri;
			pDataParams->bDsi = bDsi;
			pDataParams->ePpsState = PHPAL_I14443P4A_PPS_TXDATARATE;
			return  PH_STATUS_INPROCESS;

		case PHPAL_I14443P4A_PPS_TXDATARATE:
			/* Apply new data rates to Pcd */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING,
					wTxDataRate));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->ePpsState = PHPAL_I14443P4A_PPS_RXDATARATE;
			return PH_STATUS_INPROCESS;

		case PHPAL_I14443P4A_PPS_RXDATARATE:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXDATARATE_FRAMING,
					wRxDataRate));
	}
	pDataParams->ePpsState = PHPAL_I14443P4A_PPS_IDLE;
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

#ifdef __cplusplus
}
#endif
