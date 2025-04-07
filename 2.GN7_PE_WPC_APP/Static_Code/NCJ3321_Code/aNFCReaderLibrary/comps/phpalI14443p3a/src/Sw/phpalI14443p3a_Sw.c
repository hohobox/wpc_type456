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
*   @file    phpalI14443p3a.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3a - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p3a ISO/IEC 14443-3A
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
#include <phTools.h>
#include <phhalHw.h>
#include <phpalI14443p3a.h>
#include <ph_RefDefs.h>
#include <phNxpNfcRdLib_Config.h>
#include <phLog.h>

#ifdef NXPBUILD__PHPAL_I14443P3A_SW

#include "phpalI14443p3a_Sw.h"
#include "phpalI14443p3a_Sw_Int.h"

#include <Nfcrdlib.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p3a_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3A_SW_VENDOR_ID_C                      43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C       4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C       3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION_C    1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3A_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3A_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3A_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p3a_Sw.h header file are of the same vendor */
#if (PHPALI14443P3A_SW_VENDOR_ID_C != PHPALI14443P3A_SW_VENDOR_ID)
    #error "phpalI14443p3a_Sw.c and phpalI14443p3a_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p3a_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3a_Sw.c and phpalI14443p3a_Sw.h are different"
#endif
/* Check if current file and phpalI14443p3a_Sw.h header file are of the same Software version */
#if ((PHPALI14443P3A_SW_SW_MAJOR_VERSION_C != PHPALI14443P3A_SW_SW_MAJOR_VERSION) || \
     (PHPALI14443P3A_SW_SW_MINOR_VERSION_C != PHPALI14443P3A_SW_SW_MINOR_VERSION) || \
     (PHPALI14443P3A_SW_SW_PATCH_VERSION_C != PHPALI14443P3A_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3a_Sw.c and phpalI14443p3a_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */
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
#ifdef NXPBUILD__PHPAL_I14443P3A_SW
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_Init(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams)
{
	if (sizeof(phpalI14443p3a_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P3A);
	}
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pHalDataParams);

	/* reset state machine */
	pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_IDLE;
	pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_IDLE;
	pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_IDLE;
	pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_IDLE;
	pDataParams->eVASUpAState = PHPAL_I14443P3A_VASUPA_IDLE;
	/* init private data */
	pDataParams->wId = PH_COMP_PAL_ISO14443P3A | PHPAL_I14443P3A_SW_ID;
	pDataParams->pHalDataParams = pHalDataParams;
	pDataParams->bUidLength = 0;
	pDataParams->bUidComplete = 0;
	pDataParams->bOpeMode = RD_LIB_MODE_ISO;
	// pDataParams->bPollCmd = PHPAL_I14443P3A_USE_REQA;
	pDataParams->bPollCmd = PHPAL_I14443P3A_USE_WUPA;

	return PH_ERR_SUCCESS;
}

/* Emvco: Added for EMVCO This function is used to config parameter for phpalI14443p3a */
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_SetConfig(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig,
    VAR(uint16, ANFCRL_VAR) wValue)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	switch (wConfig)
	{
		/* Emvco: To Define Running Mode for RdLib: Either Nfc, EMVCO, ISO */
		case PHPAL_I14443P3A_CONFIG_OPE_MODE:
		{
			pDataParams->bOpeMode = (uint8) wValue;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_POLL_CMD:
		{
			pDataParams->bPollCmd = (uint8) wValue;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US:
		{
			PH_CHECK_SUCCESS_FCT(statusTmp,
					phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, wValue));
			break;
		}

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P3A);
	}

	return PH_ERR_SUCCESS;
}

/* Emvco: Added for EMVCO This function is used to config parameter for phpalI14443p3a */
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_GetConfig(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wConfig,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	switch (wConfig)
	{
		/* Emvco: To Define Running Mode for RdLib: Either Nfc, EMVCO, ISO */
		case PHPAL_I14443P3A_CONFIG_OPE_MODE:
		{
			*pValue = (uint16) pDataParams->bOpeMode;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_POLL_CMD:
		{
			*pValue = (uint16) pDataParams->bPollCmd;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US:
		{
			PH_CHECK_SUCCESS_FCT(statusTmp,
					phhalHw_GetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, pValue));
			break;
		}

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P3A);
	}

	return PH_ERR_SUCCESS;

}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_RequestA(P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa)
{
	return phpalI14443p3a_Sw_RequestAEx(pDataParams,
	PHPAL_I14443P3A_REQUEST_CMD, pAtqa);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_WakeUpA(P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa)
{
	return phpalI14443p3a_Sw_RequestAEx(pDataParams, PHPAL_I14443P3A_WAKEUP_CMD, pAtqa);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_HaltA(P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM cmd[2];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	switch (pDataParams->eHaltAState)
	{
		case PHPAL_I14443P3A_HALTA_IDLE:
			I14443P3_LOG(">>> P3A_HALT_SEND  \r\n");
			pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_TIMEOUT;
			/*No break*/
		case PHPAL_I14443P3A_HALTA_TIMEOUT:
			/* Set halt timeout */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
			PHPAL_I14443P3A_HALT_TIME_US + PHPAL_I14443P3A_EXT_TIME_US));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_CONFIG;
			return PH_STATUS_INPROCESS;
		case PHPAL_I14443P3A_HALTA_CONFIG:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TRXCRC, PH_ON));
			PH_BREAK_ON_FAILURE(status);
			/* Send HaltA command */
			cmd[0] = PHPAL_I14443P3A_HALT_CMD;
			cmd[1] = 0x00U;
			pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_SENDCMD;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_HALTA_SENDCMD:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams,
					PH_EXCHANGE_DEFAULT, cmd, 2U, &pResp, &wRespLength));
			pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_IDLE;

			I14443P3_LOG("<<< P3A_HALT_RESPONSE: %0X  \r\n", status);
			switch (status & PH_ERR_MASK)
			{
				/* HaltA command should timeout -> success */
				case PH_ERR_IO_TIMEOUT:
					status = PH_ERR_SUCCESS;
					break;
				/* Return protocol error */
				case PH_ERR_SUCCESS:
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
			}
	}
	pDataParams->eHaltAState = PHPAL_I14443P3A_HALTA_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_Anticollision(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bCascadeLevel,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,
    VAR(uint8, ANFCRL_VAR) bNvbUidIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNvbUidOut)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusExchange = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsSelect = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuffer[10] = {0U};
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRcvBuffer = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSndBytes = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRcvBytes = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRcvBits = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidStartIndex = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBitCount = 0U;

	switch (pDataParams->eAntiCollState)
	{
		case PHPAL_I14443P3A_ANTICOLL_IDLE:
			/* Check for invalid bNvbUidIn parameter */
			if ((bNvbUidIn > 0x40U) || ((bNvbUidIn & 0x0FU) > 0x07U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3A);
			}

			/* Check for invalid bCascadeIndex parameter */
			switch (bCascadeLevel)
			{
				case PHPAL_I14443P3A_CASCADE_LEVEL_1:
					/* Reset UID length */
					pDataParams->bUidLength = 0u;
					break;
				case PHPAL_I14443P3A_CASCADE_LEVEL_2:
				case PHPAL_I14443P3A_CASCADE_LEVEL_3:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3A);
			}

			/* Reset UID complete flag */
			pDataParams->bUidComplete = 0u;
			pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_CONFIG1;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG1:

			/* ANTICOLLISION: Disable CRC */
			if (bNvbUidIn != 0x40U)
			{
				bIsSelect = 0u;
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_TRXCRC, PH_OFF));
				PH_BREAK_ON_FAILURE(status);
			}
			/* SELECT: Enable CRC */
			else
			{
				bIsSelect = 1u;
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_TRXCRC, PH_ON));
				PH_BREAK_ON_FAILURE(status);
			}

			pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_CONFIG2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG2:
			/* Init. command buffer */
			bCmdBuffer[0] = bCascadeLevel;
			(void) memset(&bCmdBuffer[2], 0x00, 5);

			/* Copy valid UID bits */
			wSndBytes = (uint16) (((((uint16) bNvbUidIn) & 0xF0U) >> 4U)
					+ (((bNvbUidIn & 0x0FU) != 0U) ? 1U : 0U));
			(void) phTools_memcpy(&bCmdBuffer[2], pUidIn, (size_t) wSndBytes);
			wSndBytes += 2U;

			/* SELECT: Add BCC */
			if (0U != bIsSelect)
			{
				bNvbUidIn = 0x50;
				bCmdBuffer[6] = pUidIn[0] ^ pUidIn[1] ^ pUidIn[2] ^ pUidIn[3];
				++wSndBytes;
			}

			/* Encode NVB */
			bCmdBuffer[1] = bNvbUidIn + 0x20U;

			pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_CONFIG3;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG3:
			/* Adjust Rx-Align */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXALIGN, (((uint16) bNvbUidIn) & 0x07U)));
			PH_BREAK_ON_FAILURE(status);

			/* Adjust TxBits */
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_TXLASTBITS, (((uint16) bNvbUidIn) & 0x07U)));
			I14443P3_LOG_BUF(">>> P3A_ANTICOLLISION_SEND:", bCmdBuffer,
					(uint8)wSndBytes);

			pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_SENDCMD;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ANTICOLL_SENDCMD:
			PH_CHECK_INPROCESS_FCT(statusExchange, phhalHw_Exchange(pDataParams->pHalDataParams,
					PH_EXCHANGE_DEFAULT, bCmdBuffer, wSndBytes, &pRcvBuffer, &wRcvBytes));
			pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH:
			/* Reset RxAlignment */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXALIGN, 0));
			PH_BREAK_ON_FAILURE(status);
			statusTmp = statusExchange;
#ifdef NXPBUILD__PH_LOG_EX
			if (statusTmp == PH_ERR_SUCCESS)
			{
				if (bIsSelect != 0U)
				{
					I14443P3_LOG_BUF("<<< P3A_SELECT_RESPONSE:", pRcvBuffer,
							(uint8 )wRcvBytes);
				}
				else
				{
					I14443P3_LOG_BUF("<<< P3A_ANTICOLLISION_RESPONSE:", pRcvBuffer,
							(uint8 )wRcvBytes);
				}
			}
			else
			{
				if (bIsSelect != 0U)
				{
					I14443P3_LOG("<<< P3A_SELECT_RESPONSE: %0X \r\n", statusTmp);
				}
				else
				{
					I14443P3_LOG(
							"<<< P3A_ANTICOLLISION_RESPONSE: %0X wRcvBytes: %d \r\n",
							statusTmp, wRcvBytes);
				}
			}
#endif

			/* Check status, Collision is allowed for anti-collision command. */
			if ((bIsSelect == 0U) && ((statusTmp & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR))
			{
				/* Retrieve number of valid bits of last byte */
				PH_CHECK_FAILURE_FCT(status, phhalHw_GetConfig(pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXLASTBITS, &wRcvBits));
				status = statusTmp;
			}
			else
			{
				/* Check for protocol error */
				if ((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS_INCOMPLETE_BYTE)
				{
					I14443P3_LOG("--- PROTOCOL_ERROR INCOMPLETE BYTE \r\n");
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
					break;
				}
				/* Return on other errors */
				else
				{
					PH_CHECK_FAILURE_FCT(status, statusTmp);
				}

				/* whole byte valid */
				wRcvBits = 0U;
			}

			/* Add received data to UID */
			if (bIsSelect == 0U)
			{
				/* Retrieve byte-starting-index of received Uid */
				bUidStartIndex = (uint8) ((bNvbUidIn & 0xF0U) >> 4U);

				/* Add new bitcount */
				bBitCount = (uint8) (((((uint16) bNvbUidIn) >> 4U) << 3U) + (wRcvBytes << 3U)
						+ wRcvBits);

				/* Last incomplete byte is added to wRcvBytes, so remove that again */
				if (wRcvBits > 0U)
				{
					bBitCount -= 8U;
				}

				/* Convert bitcount to NVB format */
				*pNvbUidOut = (uint8) (((bBitCount >> 3U) << 4U) + (bBitCount & 0x07U));

				/* We do not tolerate more than (5u * 8 =)40 bits because it would lead to buffer overflows */
				if (*pNvbUidOut > 0x50U)
				{
					I14443P3_LOG("^^^ PROTOCOL_ERROR MORE THAN (5u * 8 =)40 bits \r\n");
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
					break;
				}

				/* After successful reception, the UID must be exact 40 bits */
				if (((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS) && (*pNvbUidOut != 0x50U))
				{
					I14443P3_LOG(
							"^^^ PROTOCOL_ERROR: the UID must be exact 40 bits pNvbUidOut: %0X \r\n",
							*pNvbUidOut);
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
					break;
				}

				/* Copy received bytes to uid */
				if (wRcvBytes > 0U)
				{
					/* Incomplete byte sent: Merge Rx-Aligned first byte */
					if (0U != (bNvbUidIn & 0x07U))
					{
						bCmdBuffer[2U + bUidStartIndex] = (bCmdBuffer[2U + bUidStartIndex]
								& (uint8) ((1U << (bNvbUidIn & 0x07U)) - 1U))
								| (pRcvBuffer[0] & (uint8) (0xFFU << (bNvbUidIn & 0x07U)));
					}
					/* Else just copy the first byte */
					else
					{
						bCmdBuffer[2U + bUidStartIndex] = pRcvBuffer[0];
					}

					/* Add the rest of the uid bytes */
					(void) phTools_memcpy(&bCmdBuffer[2U + bUidStartIndex + 1U], &pRcvBuffer[1],
							(size_t) (((uint32) wRcvBytes) - 1u));
				}

				/* Anti-collision finished */
				if (*pNvbUidOut > 0x40U)
				{
					/* Collision in BCC byte can never happen */
					if (*pNvbUidOut < 0x50U)
					{
						I14443P3_LOG("^^^ PROTOCOL_ERROR BCC Length Error \r\n");
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_FRAMING_ERROR, PH_COMP_PAL_ISO14443P3A);
						break;
					}

					/* Remove BCC from NvbUidOut */
					*pNvbUidOut = 0x40;
					--wRcvBytes;

					/* BCC Check */
					if ((bCmdBuffer[2] ^ bCmdBuffer[3] ^ bCmdBuffer[4] ^ bCmdBuffer[5])
							!= bCmdBuffer[6])
					{
						I14443P3_LOG("^^^ PROTOCOL_ERROR BCC Checksum Error \r\n");
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_FRAMING_ERROR, PH_COMP_PAL_ISO14443P3A);
						break;
					}
				}

				/* Copy UID */
				(void) phTools_memcpy(pUidOut, &bCmdBuffer[2],
						(size_t) (bUidStartIndex + ((uint32) wRcvBytes)));
			}
			/* Return SAK instead of the UID */
			else
			{
				/* only one byte allowed */
				if (wRcvBytes != 1U)
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
					break;
				}

				/* Cascade Bit is set */
				if (0U != (pRcvBuffer[0] & 0x04U))
				{
					/* If additional cascade levels are impossible -> protocol error */
					if (bCascadeLevel == PHPAL_I14443P3A_CASCADE_LEVEL_3)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
						break;
					}

					/* Cascade tag does not match -> protocol error */
					if (pUidIn[0] != PHPAL_I14443P3A_CASCADE_TAG)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
						break;
					}

					/* Ignore Cascade Tag */
					(void) phTools_memcpy(&pDataParams->abUid[pDataParams->bUidLength], &pUidIn[1],
							3);

					/* Increment Uid length */
					pDataParams->bUidLength += 3U;
				}
				/* Cascade Bit is cleared -> no further cascade levels */
				else
				{
					/* Cascade tag does not match -> protocol error */
					if (pUidIn[0] == PHPAL_I14443P3A_CASCADE_TAG)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
						break;
					}

					/* Copy all uid bytes except BCC */
					(void) phTools_memcpy(&pDataParams->abUid[pDataParams->bUidLength], &pUidIn[0],
							4);

					/* Increment Uid length */
					pDataParams->bUidLength += 4U;

					/* Set UID complete flag */
					pDataParams->bUidComplete = 1;

					/* set default card timeout */
                    pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT;
                    return PH_STATUS_INPROCESS;
				}

				/* Copy SAK */
				pUidOut[0] = pRcvBuffer[0];
			}
            break;
        case PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
            PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
            PHPAL_I14443P3A_TIMEOUT_DEFAULT_MS));
            PH_BREAK_ON_FAILURE(status);
            status = statusTmp;
            /* Copy SAK */
            pUidOut[0] = pRcvBuffer[0];
	}

	/* Reset static variables */
	pDataParams->eAntiCollState = PHPAL_I14443P3A_ANTICOLL_IDLE;
	statusExchange = PH_ERR_SUCCESS;
	bIsSelect = 0U;
	for(uint8 i = 0; i < 10U; i++)
	{
		bCmdBuffer[i] = 0U;
	}
	pRcvBuffer = NULL;
	wSndBytes = 0U;
	wRcvBytes = 0U;
	wRcvBits = 0U;
	bUidStartIndex = 0U;
	bBitCount = 0U;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_Select(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bCascadeLevel,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDummy;
	return phpalI14443p3a_Sw_Anticollision(pDataParams, bCascadeLevel, pUidIn, 0x40, pSak, &bDummy);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_ActivateCard(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,
    VAR(uint8, ANFCRL_VAR) bLenUidIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCascadeLevel = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bCascadeIndex;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidIndex = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNvbUid;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAtqa[2] =
	{ 0 };
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUid[4];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCollDetected = PH_OFF;

	switch (pDataParams->eActCardState)
	{
		case PHPAL_I14443P3A_ACTCARD_IDLE:
			/* Parameter check */
			if ((bLenUidIn != 0U) && (bLenUidIn != 4U) && (bLenUidIn != 7U)
					&& (bLenUidIn != 10U)
					&& (pDataParams->bPollCmd != PHPAL_I14443P3A_USE_WUPA))
			{
				/* Given UID length is invalid, return error */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3A);
			}
			/* initialize to zero, for VS studio warning */
			bCascadeLevel = 0;
			/* Clear Uid */
			(void) memset(bUid, 0x00, 4);

			/* Clear Uid lengths */
			bUidIndex = 0;
			*pLenUidOut = 0;

			/* Clear the more cards available flag */
			*pMoreCardsAvailable = PH_OFF;
			bCollDetected = PH_OFF;
			bAtqa[0] = 0;
			pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_REQA;
			/*no break*/
		case PHPAL_I14443P3A_ACTCARD_REQA:
			// if ((pDataParams->bOpeMode == RD_LIB_MODE_ISO)
			// 		&& (pDataParams->bPollCmd == PHPAL_I14443P3A_USE_WUPA))
			// {
			// 	status = phpalI14443p3a_Sw_WakeUpA(pDataParams, bAtqa);
			// }
			// else
			// {
			// 	if (bLenUidIn == 0U)
			// 	{
			// 		status = phpalI14443p3a_Sw_RequestA(pDataParams, bAtqa);
			// 	}
			// 	/* UidIn is given -> WupA */
			// 	else
			// 	{
			// 		status = phpalI14443p3a_Sw_WakeUpA(pDataParams, bAtqa);
			// 	}
			// }
			status = phpalI14443p3a_Sw_WakeUpA(pDataParams, bAtqa);	// 항상 WUPA로 선택되도록

			if (status == PH_STATUS_INPROCESS)
			{
				return PH_STATUS_INPROCESS;
			}
			I14443P3_LOG("--- START REQA: %0X \r\n", status);

			/* Collision error may happen */
			if ((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
			{
				bCollDetected = PH_ON;
				/* Set the more cards available flag */
				*pMoreCardsAvailable = PH_ON;
			}
			/* Status check */
			else
			{
				PH_BREAK_ON_FAILURE(status);
			}
			pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT;
			bCascadeIndex = 0;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif

		case PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT:
		case PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP:
			if (pDataParams->eActCardState == PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT)
			{
				/* Go through all cascade levels 0->2 */
				/* Set cascade level tags */
				switch (bCascadeIndex)
				{
					case 0:
						bCascadeLevel = PHPAL_I14443P3A_CASCADE_LEVEL_1;
						break;
					case 1:
						bCascadeLevel = PHPAL_I14443P3A_CASCADE_LEVEL_2;
						break;
					case 2:
						bCascadeLevel = PHPAL_I14443P3A_CASCADE_LEVEL_3;
						break;
						/* Default Case is not required as it will be a Dead Code due to the condition in for() loop statement. */
				} /* PRQA S 2002 */

				/* Copy know Uid part if necessary */
				if ((bLenUidIn == (bUidIndex + 4U)) && (pUidIn != NULL))
				{
					/* Copy whole Uid if this is the only cascade level */
					(void) phTools_memcpy(&bUid[0], &pUidIn[bUidIndex], 4);

					/* [Increment Uid index would have no effect] */

					/* All bits except BCC are valid */
					bNvbUid = 0x40;
				}
				else if ((bLenUidIn > (bUidIndex + 4U)) && (pUidIn != NULL))
				{
					/* Prepend cascade tag if we expect more cascade levels*/
					bUid[0] = PHPAL_I14443P3A_CASCADE_TAG;

					/* Only three more uid bytes are valid for this level */
					(void) phTools_memcpy(&bUid[1], &pUidIn[bUidIndex], 3);

					/* Increment Uid index */
					bUidIndex += 3U;

					/* All bits except BCC are valid */
					bNvbUid = 0x40;
				}
				else
				{
					/* No Uid given */
					bNvbUid = 0;
				}
				pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP;
			}
			/* Anti-collision Loop */
			if (bNvbUid != 0x40U)
			{
				/* Perform single anti-collision command */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_Sw_Anticollision(pDataParams, bCascadeLevel, bUid, bNvbUid,
						bUid, &bNvbUid));

				/* Collision error occurred, add one (zero-)bit to Uid */
				if ((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
				{
					/* Set the more cards available flag */
					*pMoreCardsAvailable = PH_ON;

					/* Increment NvbUid by one bit */
					if ((bNvbUid & 0x07U) < 7U)
					{
						bNvbUid++;
					}
					/* This is more difficult if we have to increment the byte count */
					else
					{
						bNvbUid = (uint8) ((((bNvbUid & 0xF0U) >> 4U) + 1U) << 4U);
					}
				}
				else
				{
					/* Check success */
					PH_BREAK_ON_FAILURE(status);
				}
				if (bCollDetected == PH_OFF)
				{
					/* Emvco: case_id 302_10 */
					/*
					 * Digital Proto: Article 4.7.2 and 4.7.2.4
					 * ISO14443-3 Article 6.5.2.1
					 * EMVCo article 5.4.2
					 * So For Single UID Size The NFC Forum Device MUST set nfcid10 of a single-size NFCID1 and nfcid13
					 * of a double-size NFCID1 to a value different from 88h.
					 */
					if ((bAtqa[0] != 0U)
							&& ((((bAtqa[0] & 0xC0U) == 0x00U)
									&& (bCascadeLevel == PHPAL_I14443P3A_CASCADE_LEVEL_1))
									|| (((bAtqa[0] & 0xC0U) == 0x40U)
											&& (bCascadeLevel == PHPAL_I14443P3A_CASCADE_LEVEL_2)))
							&& (bUid[0] == PHPAL_I14443P3A_CASCADE_TAG))
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR,
								PH_COMP_PAL_ISO14443P3A);
						break;
					}
				}
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p3a_Sw_Select(pDataParams, bCascadeLevel, bUid, pSak));
				PH_BREAK_ON_FAILURE(status);

				/* Cascade Bit is cleared -> no further cascade levels */
				if ((pSak[0] & 0x04U) == 0U)
				{
					I14443P3_LOG("~~~ END ANTICOLLISION LOOP ~~~\r\n");
					break;
				}
				bCascadeIndex++;
				if (bCascadeIndex >= 3U)
				{
					break;
				}
				pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT;
				I14443P3_LOG("--- INCREASE LEVEL CASCADE ---\r\n");
			}
			return PH_STATUS_INPROCESS;
	}
	if(status == PH_ERR_SUCCESS)
	{
		/* Return UID */
		(void) phTools_memcpy(pUidOut, pDataParams->abUid, pDataParams->bUidLength);
		*pLenUidOut = pDataParams->bUidLength;
	}
	pDataParams->eActCardState = PHPAL_I14443P3A_ACTCARD_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_Exchange(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
    VAR(uint16, ANFCRL_VAR) wTxLength,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength)
{
	return phhalHw_Exchange(pDataParams->pHalDataParams, wOption, pTxBuffer, wTxLength,
			ppRxBuffer, pRxLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_RequestAEx(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bReqCode,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusExchange = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM cmd[1];
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRegister = 0U;

	switch (pDataParams->eReqAExState)
	{
		case PHPAL_I14443P3A_REQAEX_IDLE:
			/* Disable MIFARE Classic contactless IC Crypto1 */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO1, PH_ON));
			PH_BREAK_ON_FAILURE(statusTmp);
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_TXRATE;
			/* Send ReqA command */
			cmd[0] = bReqCode;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_TXRATE:
			/* Reset default data rates */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING, PHHAL_HW_RF_DATARATE_106));
			PH_BREAK_ON_FAILURE(statusTmp);
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_RXRATE;
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_RXRATE:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXDATARATE_FRAMING, PHHAL_HW_RF_DATARATE_106));
			PH_BREAK_ON_FAILURE(statusTmp);
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_TIMEOUT;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_TIMEOUT:
			/* Set selection timeout */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
			PHPAL_I14443P3A_SELECTION_TIME_US + PHPAL_I14443P3A_EXT_TIME_US));
			PH_BREAK_ON_FAILURE(statusTmp);
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_GET_CONFIG;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_GET_CONFIG:
			/* Retrieve RxWaitTime */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXWAIT_US, &wRegister));
			PH_BREAK_ON_FAILURE(statusTmp);
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_SET_CONFIG;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_SET_CONFIG:
			/*Set all configuration needed for ReqA command*/
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_REQAEX, PH_OFF));
			PH_BREAK_ON_FAILURE(statusTmp);

			/*Only 7 bits are valid*/
			PH_CHECK_FAILURE_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_TXLASTBITS, 7));

#ifdef NXPBUILD__PH_LOG_EX
			if (bReqCode == 0x26U)
			{
				I14443P3_LOG_BUF(">>> P3A_REQUEST_SEND:", cmd, 1);
			}
			else if (bReqCode == 0x52U)
			{
				I14443P3_LOG_BUF(">>> P3A_WAKEUP_SEND:", cmd, 1);
			}
			else
			{
				; /* No action here */
			}
#endif
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_SENDCMD;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_SENDCMD:
			PH_CHECK_INPROCESS_FCT(statusExchange, phhalHw_Exchange(pDataParams->pHalDataParams,
					PH_EXCHANGE_DEFAULT, cmd, 1, &pResp, &wRespLength));

#ifdef NXPBUILD__PH_LOG_EX
			if (bReqCode == 0x26U)
			{
				I14443P3_LOG("<<< P3A_REQUEST_RESPONSE: %0X \r\n", statusTmp);
			}
			else if (bReqCode == 0x52U)
			{
				I14443P3_LOG("<<< P3A_WAKEUP_RESPONSE: %0X \r\n", statusTmp);
			}
			else
			{
				; /* No action here */
			}
#endif
			pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME:
			/* Restore previous RxWaitTime */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXWAIT_US, wRegister));
			PH_BREAK_ON_FAILURE(statusTmp);

			if (statusExchange != PH_ERR_SUCCESS)
			{
				statusTmp = statusExchange;
				PH_BREAK_ON_FAILURE(statusTmp);
			}

			/* Check and copy ATQA */
			if (wRespLength == PHPAL_I14443P3A_ATQA_LENGTH)
			{
				(void) phTools_memcpy(pAtqa, pResp,
				PHPAL_I14443P3A_ATQA_LENGTH);

				/* NFCForum-TS-DigitalProtocol-1.0, Requirement 18, Section 4.6.3.3 */
				if ((((pAtqa[0] & 0x1FU) == 0x00U) && ((pAtqa[1] & 0x0FU) != 0x0CU))
						|| (((pAtqa[1] & 0x0FU) == 0x0CU) && ((pAtqa[0] & 0x1FU) != 0x00U)))
				{
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR,
							PH_COMP_PAL_ISO14443P3A);
				}
			}
			else
			{
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3A);
			}
			break;
	}
	pDataParams->eReqAExState = PHPAL_I14443P3A_REQAEX_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_GetSerialNo(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut)
{
	/* Return an error if UID is not complete */
	if (0U == (pDataParams->bUidComplete))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_ISO14443P3A);
	}

	/* Copy UID */
	(void) phTools_memcpy(pUidOut, pDataParams->abUid, pDataParams->bUidLength);
	*pLenUidOut = pDataParams->bUidLength;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_VASUpA(
    P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bFormatByte,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes,
    VAR(uint8, ANFCRL_VAR) bLenCmdBytes,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_STATUS_INPROCESS;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRegister = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM cmd[255] = {0U};
	UNUSED(pAtqa);

	/*Check for invalid size configuration of the VASUP-A command frame.*/
	if( ( (bFormatByte == PHPAL_I14443P3A_VASUP_VERSION_01) &&
			( (bLenCmdBytes > PHPAL_I14443P3A_VASUP_VERSION_01_MAX_SIZE) ||
			(bLenCmdBytes < PHPAL_I14443P3A_VASUP_VERSION_01_MIN_SIZE) ) ) ||
			( (bFormatByte == PHPAL_I14443P3A_VASUP_VERSION_02) &&
			( (bLenCmdBytes > PHPAL_I14443P3A_VASUP_VERSION_02_MAX_SIZE) ||
			(bLenCmdBytes < PHPAL_I14443P3A_VASUP_VERSION_02_MIN_SIZE) ) ) )
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3A);
	}

	switch (pDataParams->eVASUpAState)
	{
		case PHPAL_I14443P3A_VASUPA_IDLE:
			PH_CHECK_SUCCESS_FCT(status, phpalI14443p3a_Sw_GetConfig(pDataParams,
					PHPAL_I14443P3A_CONFIG_OPE_MODE, &wRegister));
			/*VAS polling is available when the discovery loop is configured either in EMVCo mode or NFC mode*/
			if (wRegister == RD_LIB_MODE_ISO)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_PAL_ISO14443P3A);
			}
			else
			{
				pDataParams->eVASUpAState = PHPAL_I14443P3A_VASUPA_CONFIG;
			}
			/* No break */
		case PHPAL_I14443P3A_VASUPA_CONFIG:
#if 1 // CAS_KR: for fast card detection
			do
			{
				status =  phhalHw_SetConfig(pDataParams->pHalDataParams,PHHAL_HW_CONFIG_TXCRC, PH_ON);
			} while (status == PH_STATUS_INPROCESS);
#else
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXCRC, PH_ON));
#endif
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eVASUpAState = PHPAL_I14443P3A_VASUPA_SENDCMD;
			/* No break */
		case PHPAL_I14443P3A_VASUPA_SENDCMD:
			phTools_memcpy(&cmd[0], pCmdBytes, bLenCmdBytes);
			/* Send VASUP-A command */
#if 1 // CAS_KR: for fast card detection
			do
			{
				status =  phhalHw_Exchange(pDataParams->pHalDataParams,
							PH_EXCHANGE_DEFAULT, cmd, ((bFormatByte == 0x01U) ? 5U : ((uint16)bLenCmdBytes)),
							&pResp, &wRespLength);
			} while (status == PH_STATUS_INPROCESS);
#else
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams,
				PH_EXCHANGE_DEFAULT, cmd, ((bFormatByte == 0x01U) ? 5U : ((uint16)bLenCmdBytes)),
				&pResp, &wRespLength));
#endif
#ifdef NXPBUILD__PH_LOG_EX
			I14443P3_LOG_BUF(">>> PHPAL_I14443P3A_VASUP_SEND:", pCmdBytes, bLenCmdBytes);
			I14443P3_LOG("<<< PHPAL_I14443P3A_VASUP_RESPONSE: %0X \r\n", status);
#endif
			break;
	}

	pDataParams->eVASUpAState = PHPAL_I14443P3A_VASUPA_IDLE;
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef __cplusplus
}
#endif /*__cplusplus */
