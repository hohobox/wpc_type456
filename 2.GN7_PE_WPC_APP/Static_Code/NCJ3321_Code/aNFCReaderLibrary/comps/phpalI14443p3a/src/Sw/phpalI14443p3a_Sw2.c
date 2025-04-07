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
*   @file    phpalI14443p3a_Sw2.c
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

#include <ph_Status2.h>
#include <phTools2.h>
#include <phhalHw2.h>
#include <phpalI14443p3a2.h>
#include <ph_RefDefs2.h>
#include <phNxpNfcRdLib_Config2.h>
#include <phLog2.h>

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2

#include "phpalI14443p3a_Sw2.h"
#include "phpalI14443p3a_Sw_Int2.h"

#include <Nfcrdlib2.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p3a_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3A_SW_VENDOR_ID_C2                      43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C2       4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C2       3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION_C2    1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3A_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3A_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3A_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p3a_Sw.h header file are of the same vendor */
#if (PHPALI14443P3A_SW_VENDOR_ID_C2 != PHPALI14443P3A_SW_VENDOR_ID2)
    #error "phpalI14443p3a_Sw2.c and phpalI14443p3a_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p3a_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C2    != PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION_C2 != PHPALI14443P3A_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalI14443p3a_Sw2.c and phpalI14443p3a_Sw.h are different"
#endif
/* Check if current file and phpalI14443p3a_Sw.h header file are of the same Software version */
#if ((PHPALI14443P3A_SW_SW_MAJOR_VERSION_C2 != PHPALI14443P3A_SW_SW_MAJOR_VERSION2) || \
     (PHPALI14443P3A_SW_SW_MINOR_VERSION_C2 != PHPALI14443P3A_SW_SW_MINOR_VERSION2) || \
     (PHPALI14443P3A_SW_SW_PATCH_VERSION_C2 != PHPALI14443P3A_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalI14443p3a_Sw2.c and phpalI14443p3a_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */
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
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_Init2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2)
{
	if (sizeof(phpalI14443p3a_Sw_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3A2);
	}
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pHalDataParams2);

	/* reset state machine */
	pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_IDLE2;
	pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_IDLE2;
	pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_IDLE2;
	pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_IDLE2;
	pDataParams2->eVASUpAState2 = PHPAL_I14443P3A_VASUPA_IDLE2;
	/* init private data */
	pDataParams2->wId2 = PH_COMP_PAL_ISO14443P3A2 | PHPAL_I14443P3A_SW_ID2;
	pDataParams2->pHalDataParams2 = pHalDataParams2;
	pDataParams2->bUidLength2 = 0;
	pDataParams2->bUidComplete2 = 0;
	pDataParams2->bOpeMode2 = RD_LIB_MODE_ISO2;
	// pDataParams2->bPollCmd2 = PHPAL_I14443P3A_USE_REQA2;
	pDataParams2->bPollCmd2 = PHPAL_I14443P3A_USE_WUPA2;

	return PH_ERR_SUCCESS2;
}

/* Emvco: Added for EMVCO This function is used to config parameter for phpalI14443p3a */
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_SetConfig2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wConfig2,
    VAR(uint16, ANFCRL_VAR) wValue2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2;

	switch (wConfig2)
	{
		/* Emvco: To Define Running Mode for RdLib: Either Nfc, EMVCO, ISO */
		case PHPAL_I14443P3A_CONFIG_OPE_MODE2:
		{
			pDataParams2->bOpeMode2 = (uint8) wValue2;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_POLL_CMD2:
		{
			pDataParams2->bPollCmd2 = (uint8) wValue2;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US2:
		{
			PH_CHECK_SUCCESS_FCT2(statusTmp2,
					phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, wValue2));
			break;
		}

		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
	}

	return PH_ERR_SUCCESS2;
}

/* Emvco: Added for EMVCO This function is used to config parameter for phpalI14443p3a */
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_GetConfig2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wConfig2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2;

	switch (wConfig2)
	{
		/* Emvco: To Define Running Mode for RdLib: Either Nfc, EMVCO, ISO */
		case PHPAL_I14443P3A_CONFIG_OPE_MODE2:
		{
			*pValue2 = (uint16) pDataParams2->bOpeMode2;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_POLL_CMD2:
		{
			*pValue2 = (uint16) pDataParams2->bPollCmd2;
			break;
		}

		case PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US2:
		{
			PH_CHECK_SUCCESS_FCT2(statusTmp2,
					phhalHw_GetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, pValue2));
			break;
		}

		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
	}

	return PH_ERR_SUCCESS2;

}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_RequestA2(P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2)
{
	return phpalI14443p3a_Sw_RequestAEx2(pDataParams2,
	PHPAL_I14443P3A_REQUEST_CMD2, pAtqa2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_WakeUpA2(P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2)
{
	return phpalI14443p3a_Sw_RequestAEx2(pDataParams2, PHPAL_I14443P3A_WAKEUP_CMD2, pAtqa2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_HaltA2(P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 cmd2[2];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;

	switch (pDataParams2->eHaltAState2)
	{
		case PHPAL_I14443P3A_HALTA_IDLE2:
			I14443P3_LOG2(">>> P3A_HALT_SEND  \r\n");
			pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_TIMEOUT2;
			/*No break*/
		case PHPAL_I14443P3A_HALTA_TIMEOUT2:
			/* Set halt timeout */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
			PHPAL_I14443P3A_HALT_TIME_US2 + PHPAL_I14443P3A_EXT_TIME_US2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_CONFIG2;
			return PH_STATUS_INPROCESS2;
		case PHPAL_I14443P3A_HALTA_CONFIG2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TRXCRC2, PH_ON2));
			PH_BREAK_ON_FAILURE2(status2);
			/* Send HaltA command */
			cmd2[0] = PHPAL_I14443P3A_HALT_CMD2;
			cmd2[1] = 0x00U;
			pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_SENDCMD2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_HALTA_SENDCMD2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2,
					PH_EXCHANGE_DEFAULT2, cmd2, 2U, &pResp2, &wRespLength2));
			pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_IDLE2;

			I14443P3_LOG2("<<< P3A_HALT_RESPONSE: %0X  \r\n", status2);
			switch (status2 & PH_ERR_MASK2)
			{
				/* HaltA command should timeout -> success */
				case PH_ERR_IO_TIMEOUT2:
					status2 = PH_ERR_SUCCESS2;
					break;
				/* Return protocol error */
				case PH_ERR_SUCCESS2:
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
			}
	}
	pDataParams2->eHaltAState2 = PHPAL_I14443P3A_HALTA_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_Anticollision2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bCascadeLevel2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
    VAR(uint8, ANFCRL_VAR) bNvbUidIn2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNvbUidOut2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusExchange2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsSelect2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCmdBuffer2[10] = {0U};
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRcvBuffer2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSndBytes2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRcvBytes2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRcvBits2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidStartIndex2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBitCount2 = 0U;

	switch (pDataParams2->eAntiCollState2)
	{
		case PHPAL_I14443P3A_ANTICOLL_IDLE2:
			/* Check for invalid bNvbUidIn2 parameter */
			if ((bNvbUidIn2 > 0x40U) || ((bNvbUidIn2 & 0x0FU) > 0x07U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
			}

			/* Check for invalid bCascadeIndex2 parameter */
			switch (bCascadeLevel2)
			{
				case PHPAL_I14443P3A_CASCADE_LEVEL_12:
					/* Reset UID length */
					pDataParams2->bUidLength2 = 0u;
					break;
				case PHPAL_I14443P3A_CASCADE_LEVEL_22:
				case PHPAL_I14443P3A_CASCADE_LEVEL_32:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
			}

			/* Reset UID complete flag */
			pDataParams2->bUidComplete2 = 0u;
			pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_CONFIG12;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG12:

			/* ANTICOLLISION: Disable CRC */
			if (bNvbUidIn2 != 0x40U)
			{
				bIsSelect2 = 0u;
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_TRXCRC2, PH_OFF2));
				PH_BREAK_ON_FAILURE2(status2);
			}
			/* SELECT: Enable CRC */
			else
			{
				bIsSelect2 = 1u;
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_TRXCRC2, PH_ON2));
				PH_BREAK_ON_FAILURE2(status2);
			}

			pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_CONFIG22;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG22:
			/* Init. command buffer */
			bCmdBuffer2[0] = bCascadeLevel2;
			(void) memset(&bCmdBuffer2[2], 0x00, 5);

			/* Copy valid UID bits */
			wSndBytes2 = (uint16) (((((uint16) bNvbUidIn2) & 0xF0U) >> 4U)
					+ (((bNvbUidIn2 & 0x0FU) != 0U) ? 1U : 0U));
			(void) phTools_memcpy2(&bCmdBuffer2[2], pUidIn2, (size_t) wSndBytes2);
			wSndBytes2 += 2U;

			/* SELECT: Add BCC */
			if (0U != bIsSelect2)
			{
				bNvbUidIn2 = 0x50;
				bCmdBuffer2[6] = pUidIn2[0] ^ pUidIn2[1] ^ pUidIn2[2] ^ pUidIn2[3];
				++wSndBytes2;
			}

			/* Encode NVB */
			bCmdBuffer2[1] = bNvbUidIn2 + 0x20U;

			pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_CONFIG32;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ANTICOLL_CONFIG32:
			/* Adjust Rx-Align */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXALIGN2, (((uint16) bNvbUidIn2) & 0x07U)));
			PH_BREAK_ON_FAILURE2(status2);

			/* Adjust TxBits */
			PH_CHECK_FAILURE_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_TXLASTBITS2, (((uint16) bNvbUidIn2) & 0x07U)));
			I14443P3_LOG_BUF2(">>> P3A_ANTICOLLISION_SEND:", bCmdBuffer2,
					(uint8)wSndBytes2);

			pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_SENDCMD2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ANTICOLL_SENDCMD2:
			PH_CHECK_INPROCESS_FCT2(statusExchange2, phhalHw_Exchange2(pDataParams2->pHalDataParams2,
					PH_EXCHANGE_DEFAULT2, bCmdBuffer2, wSndBytes2, &pRcvBuffer2, &wRcvBytes2));
			pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH2:
			/* Reset RxAlignment */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXALIGN2, 0));
			PH_BREAK_ON_FAILURE2(status2);
			statusTmp2 = statusExchange2;
#ifdef NXPBUILD__PH_LOG_EX2
			if (statusTmp2 == PH_ERR_SUCCESS2)
			{
				if (bIsSelect2 != 0U)
				{
					I14443P3_LOG_BUF2("<<< P3A_SELECT_RESPONSE:", pRcvBuffer2,
							(uint8 )wRcvBytes2);
				}
				else
				{
					I14443P3_LOG_BUF2("<<< P3A_ANTICOLLISION_RESPONSE:", pRcvBuffer2,
							(uint8 )wRcvBytes2);
				}
			}
			else
			{
				if (bIsSelect2 != 0U)
				{
					I14443P3_LOG2("<<< P3A_SELECT_RESPONSE: %0X \r\n", statusTmp2);
				}
				else
				{
					I14443P3_LOG2(
							"<<< P3A_ANTICOLLISION_RESPONSE: %0X wRcvBytes2: %d \r\n",
							statusTmp2, wRcvBytes2);
				}
			}
#endif

			/* Check status2, Collision is allowed for anti-collision command. */
			if ((bIsSelect2 == 0U) && ((statusTmp2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2))
			{
				/* Retrieve number of valid bits of last byte */
				PH_CHECK_FAILURE_FCT2(status2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_RXLASTBITS2, &wRcvBits2));
				status2 = statusTmp2;
			}
			else
			{
				/* Check for protocol error */
				if ((statusTmp2 & PH_ERR_MASK2) == PH_ERR_SUCCESS_INCOMPLETE_BYTE2)
				{
					I14443P3_LOG2("--- PROTOCOL_ERROR INCOMPLETE BYTE \r\n");
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
					break;
				}
				/* Return on other errors */
				else
				{
					PH_CHECK_FAILURE_FCT2(status2, statusTmp2);
				}

				/* whole byte valid */
				wRcvBits2 = 0U;
			}

			/* Add received data to UID */
			if (bIsSelect2 == 0U)
			{
				/* Retrieve byte-starting-index of received Uid */
				bUidStartIndex2 = (uint8) ((bNvbUidIn2 & 0xF0U) >> 4U);

				/* Add new bitcount */
				bBitCount2 = (uint8) (((((uint16) bNvbUidIn2) >> 4U) << 3U) + (wRcvBytes2 << 3U)
						+ wRcvBits2);

				/* Last incomplete byte is added to wRcvBytes2, so remove that again */
				if (wRcvBits2 > 0U)
				{
					bBitCount2 -= 8U;
				}

				/* Convert bitcount to NVB format */
				*pNvbUidOut2 = (uint8) (((bBitCount2 >> 3U) << 4U) + (bBitCount2 & 0x07U));

				/* We do not tolerate more than (5u * 8 =)40 bits because it would lead to buffer overflows */
				if (*pNvbUidOut2 > 0x50U)
				{
					I14443P3_LOG2("^^^ PROTOCOL_ERROR MORE THAN (5u * 8 =)40 bits \r\n");
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
					break;
				}

				/* After successful reception, the UID must be exact 40 bits */
				if (((statusTmp2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2) && (*pNvbUidOut2 != 0x50U))
				{
					I14443P3_LOG2(
							"^^^ PROTOCOL_ERROR: the UID must be exact 40 bits pNvbUidOut2: %0X \r\n",
							*pNvbUidOut2);
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
					break;
				}

				/* Copy received bytes to uid */
				if (wRcvBytes2 > 0U)
				{
					/* Incomplete byte sent: Merge Rx-Aligned first byte */
					if (0U != (bNvbUidIn2 & 0x07U))
					{
						bCmdBuffer2[2U + bUidStartIndex2] = (bCmdBuffer2[2U + bUidStartIndex2]
								& (uint8) ((1U << (bNvbUidIn2 & 0x07U)) - 1U))
								| (pRcvBuffer2[0] & (uint8) (0xFFU << (bNvbUidIn2 & 0x07U)));
					}
					/* Else just copy the first byte */
					else
					{
						bCmdBuffer2[2U + bUidStartIndex2] = pRcvBuffer2[0];
					}

					/* Add the rest of the uid bytes */
					(void) phTools_memcpy2(&bCmdBuffer2[2U + bUidStartIndex2 + 1U], &pRcvBuffer2[1],
							(size_t) (((uint32) wRcvBytes2) - 1u));
				}

				/* Anti-collision finished */
				if (*pNvbUidOut2 > 0x40U)
				{
					/* Collision in BCC byte can never happen */
					if (*pNvbUidOut2 < 0x50U)
					{
						I14443P3_LOG2("^^^ PROTOCOL_ERROR BCC Length Error \r\n");
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_FRAMING_ERROR2, PH_COMP_PAL_ISO14443P3A2);
						break;
					}

					/* Remove BCC from NvbUidOut */
					*pNvbUidOut2 = 0x40;
					--wRcvBytes2;

					/* BCC Check */
					if ((bCmdBuffer2[2] ^ bCmdBuffer2[3] ^ bCmdBuffer2[4] ^ bCmdBuffer2[5])
							!= bCmdBuffer2[6])
					{
						I14443P3_LOG2("^^^ PROTOCOL_ERROR BCC Checksum Error \r\n");
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_FRAMING_ERROR2, PH_COMP_PAL_ISO14443P3A2);
						break;
					}
				}

				/* Copy UID */
				(void) phTools_memcpy2(pUidOut2, &bCmdBuffer2[2],
						(size_t) (bUidStartIndex2 + ((uint32) wRcvBytes2)));
			}
			/* Return SAK instead of the UID */
			else
			{
				/* only one byte allowed */
				if (wRcvBytes2 != 1U)
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
					break;
				}

				/* Cascade Bit is set */
				if (0U != (pRcvBuffer2[0] & 0x04U))
				{
					/* If additional cascade levels are impossible -> protocol error */
					if (bCascadeLevel2 == PHPAL_I14443P3A_CASCADE_LEVEL_32)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
						break;
					}

					/* Cascade tag does not match -> protocol error */
					if (pUidIn2[0] != PHPAL_I14443P3A_CASCADE_TAG2)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
						break;
					}

					/* Ignore Cascade Tag */
					(void) phTools_memcpy2(&pDataParams2->abUid2[pDataParams2->bUidLength2], &pUidIn2[1],
							3);

					/* Increment Uid length */
					pDataParams2->bUidLength2 += 3U;
				}
				/* Cascade Bit is cleared -> no further cascade levels */
				else
				{
					/* Cascade tag does not match -> protocol error */
					if (pUidIn2[0] == PHPAL_I14443P3A_CASCADE_TAG2)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
						break;
					}

					/* Copy all uid bytes except BCC */
					(void) phTools_memcpy2(&pDataParams2->abUid2[pDataParams2->bUidLength2], &pUidIn2[0],
							4);

					/* Increment Uid length */
					pDataParams2->bUidLength2 += 4U;

					/* Set UID complete flag */
					pDataParams2->bUidComplete2 = 1;

					/* set default card timeout */
                    pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT2;
                    return PH_STATUS_INPROCESS2;
				}

				/* Copy SAK */
				pUidOut2[0] = pRcvBuffer2[0];
			}
            break;
        case PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
            PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
            PHPAL_I14443P3A_TIMEOUT_DEFAULT_MS2));
            PH_BREAK_ON_FAILURE2(status2);
            status2 = statusTmp2;
            /* Copy SAK */
            pUidOut2[0] = pRcvBuffer2[0];
	}

	/* Reset static variables */
	pDataParams2->eAntiCollState2 = PHPAL_I14443P3A_ANTICOLL_IDLE2;
	statusExchange2 = PH_ERR_SUCCESS2;
	bIsSelect2 = 0U;
	for(uint8 i2 = 0; i2 < 10U; i2++)
	{
		bCmdBuffer2[i2] = 0U;
	}
	pRcvBuffer2 = NULL;
	wSndBytes2 = 0U;
	wRcvBytes2 = 0U;
	wRcvBits2 = 0U;
	bUidStartIndex2 = 0U;
	bBitCount2 = 0U;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_Select2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bCascadeLevel2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bDummy2;
	return phpalI14443p3a_Sw_Anticollision2(pDataParams2, bCascadeLevel2, pUidIn2, 0x40, pSak2, &bDummy2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_ActivateCard2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,
    VAR(uint8, ANFCRL_VAR) bLenUidIn2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCascadeLevel2 = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bCascadeIndex2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidIndex2 = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNvbUid2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bAtqa2[2] =
	{ 0 };
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUid2[4];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCollDetected2 = PH_OFF2;

	switch (pDataParams2->eActCardState2)
	{
		case PHPAL_I14443P3A_ACTCARD_IDLE2:
			/* Parameter check */
			if ((bLenUidIn2 != 0U) && (bLenUidIn2 != 4U) && (bLenUidIn2 != 7U)
					&& (bLenUidIn2 != 10U)
					&& (pDataParams2->bPollCmd2 != PHPAL_I14443P3A_USE_WUPA2))
			{
				/* Given UID length is invalid, return error */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
			}
			/* initialize to zero, for VS studio warning */
			bCascadeLevel2 = 0;
			/* Clear Uid */
			(void) memset(bUid2, 0x00, 4);

			/* Clear Uid lengths */
			bUidIndex2 = 0;
			*pLenUidOut2 = 0;

			/* Clear the more cards available flag */
			*pMoreCardsAvailable2 = PH_OFF2;
			bCollDetected2 = PH_OFF2;
			bAtqa2[0] = 0;
			pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_REQA2;
			/*no break*/
		case PHPAL_I14443P3A_ACTCARD_REQA2:
			// if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
			// 		&& (pDataParams2->bPollCmd2 == PHPAL_I14443P3A_USE_WUPA2))
			// {
			// 	status2 = phpalI14443p3a_Sw_WakeUpA2(pDataParams2, bAtqa2);
			// }
			// else
			// {
			// 	if (bLenUidIn2 == 0U)
			// 	{
			// 		status2 = phpalI14443p3a_Sw_RequestA2(pDataParams2, bAtqa2);
			// 	}
			// 	/* UidIn is given -> WupA */
			// 	else
			// 	{
			// 		status2 = phpalI14443p3a_Sw_WakeUpA2(pDataParams2, bAtqa2);
			// 	}
			// }
			status2 = phpalI14443p3a_Sw_WakeUpA2(pDataParams2, bAtqa2);

			if (status2 == PH_STATUS_INPROCESS2)
			{
				return PH_STATUS_INPROCESS2;
			}
			I14443P3_LOG2("--- START REQA: %0X \r\n", status2);

			/* Collision error may happen */
			if ((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
			{
				bCollDetected2 = PH_ON2;
				/* Set the more cards available flag */
				*pMoreCardsAvailable2 = PH_ON2;
			}
			/* Status check */
			else
			{
				PH_BREAK_ON_FAILURE2(status2);
			}
			pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT2;
			bCascadeIndex2 = 0;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT2:
		case PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP2:
			if (pDataParams2->eActCardState2 == PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT2)
			{
				/* Go through all cascade levels 0->2 */
				/* Set cascade level tags */
				switch (bCascadeIndex2)
				{
					case 0:
						bCascadeLevel2 = PHPAL_I14443P3A_CASCADE_LEVEL_12;
						break;
					case 1:
						bCascadeLevel2 = PHPAL_I14443P3A_CASCADE_LEVEL_22;
						break;
					case 2:
						bCascadeLevel2 = PHPAL_I14443P3A_CASCADE_LEVEL_32;
						break;
						/* Default Case is not required as it will be a Dead Code due to the condition in for() loop statement. */
				} /* PRQA S 2002 */

				/* Copy know Uid part if necessary */
				if ((bLenUidIn2 == (bUidIndex2 + 4U)) && (pUidIn2 != NULL))
				{
					/* Copy whole Uid if this is the only cascade level */
					(void) phTools_memcpy2(&bUid2[0], &pUidIn2[bUidIndex2], 4);

					/* [Increment Uid index would have no effect] */

					/* All bits except BCC are valid */
					bNvbUid2 = 0x40;
				}
				else if ((bLenUidIn2 > (bUidIndex2 + 4U)) && (pUidIn2 != NULL))
				{
					/* Prepend cascade tag if we expect more cascade levels*/
					bUid2[0] = PHPAL_I14443P3A_CASCADE_TAG2;

					/* Only three more uid bytes are valid for this level */
					(void) phTools_memcpy2(&bUid2[1], &pUidIn2[bUidIndex2], 3);

					/* Increment Uid index */
					bUidIndex2 += 3U;

					/* All bits except BCC are valid */
					bNvbUid2 = 0x40;
				}
				else
				{
					/* No Uid given */
					bNvbUid2 = 0;
				}
				pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP2;
			}
			/* Anti-collision Loop */
			if (bNvbUid2 != 0x40U)
			{
				/* Perform single anti-collision command */
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_Sw_Anticollision2(pDataParams2, bCascadeLevel2, bUid2, bNvbUid2,
						bUid2, &bNvbUid2));

				/* Collision error occurred, add one (zero-)bit to Uid */
				if ((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
				{
					/* Set the more cards available flag */
					*pMoreCardsAvailable2 = PH_ON2;

					/* Increment NvbUid by one bit */
					if ((bNvbUid2 & 0x07U) < 7U)
					{
						bNvbUid2++;
					}
					/* This is more difficult if we have to increment the byte count */
					else
					{
						bNvbUid2 = (uint8) ((((bNvbUid2 & 0xF0U) >> 4U) + 1U) << 4U);
					}
				}
				else
				{
					/* Check success */
					PH_BREAK_ON_FAILURE2(status2);
				}
				if (bCollDetected2 == PH_OFF2)
				{
					/* Emvco: case_id 302_10 */
					/*
					 * Digital Proto: Article 4.7.2 and 4.7.2.4
					 * ISO14443-3 Article 6.5.2.1
					 * EMVCo article 5.4.2
					 * So For Single UID Size The NFC Forum Device MUST set nfcid10 of a single-size NFCID1 and nfcid13
					 * of a double-size NFCID1 to a value different from 88h.
					 */
					if ((bAtqa2[0] != 0U)
							&& ((((bAtqa2[0] & 0xC0U) == 0x00U)
									&& (bCascadeLevel2 == PHPAL_I14443P3A_CASCADE_LEVEL_12))
									|| (((bAtqa2[0] & 0xC0U) == 0x40U)
											&& (bCascadeLevel2 == PHPAL_I14443P3A_CASCADE_LEVEL_22)))
							&& (bUid2[0] == PHPAL_I14443P3A_CASCADE_TAG2))
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2,
								PH_COMP_PAL_ISO14443P3A2);
						break;
					}
				}
			}
			else
			{
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3a_Sw_Select2(pDataParams2, bCascadeLevel2, bUid2, pSak2));
				PH_BREAK_ON_FAILURE2(status2);

				/* Cascade Bit is cleared -> no further cascade levels */
				if ((pSak2[0] & 0x04U) == 0U)
				{
					I14443P3_LOG2("~~~ END ANTICOLLISION LOOP ~~~\r\n");
					break;
				}
				bCascadeIndex2++;
				if (bCascadeIndex2 >= 3U)
				{
					break;
				}
				pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT2;
				I14443P3_LOG2("--- INCREASE LEVEL CASCADE ---\r\n");
			}
			return PH_STATUS_INPROCESS2;
	}
	if(status2 == PH_ERR_SUCCESS2)
	{
		/* Return UID */
		(void) phTools_memcpy2(pUidOut2, pDataParams2->abUid2, pDataParams2->bUidLength2);
		*pLenUidOut2 = pDataParams2->bUidLength2;
	}
	pDataParams2->eActCardState2 = PHPAL_I14443P3A_ACTCARD_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_Exchange2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wOption2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
    VAR(uint16, ANFCRL_VAR) wTxLength2,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2)
{
	return phhalHw_Exchange2(pDataParams2->pHalDataParams2, wOption2, pTxBuffer2, wTxLength2,
			ppRxBuffer2, pRxLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_RequestAEx2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bReqCode2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusExchange2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 cmd2[1];
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRegister2 = 0U;

	switch (pDataParams2->eReqAExState2)
	{
		case PHPAL_I14443P3A_REQAEX_IDLE2:
			/* Disable MIFARE Classic contactless IC Crypto1 */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO12, PH_ON2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_TXRATE2;
			/* Send ReqA command */
			cmd2[0] = bReqCode2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_TXRATE2:
			/* Reset default data rates */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING2, PHHAL_HW_RF_DATARATE_1062));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_RXRATE2;
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_RXRATE2:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_RXDATARATE_FRAMING2, PHHAL_HW_RF_DATARATE_1062));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_TIMEOUT2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_TIMEOUT2:
			/* Set selection timeout */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
			PHPAL_I14443P3A_SELECTION_TIME_US2 + PHPAL_I14443P3A_EXT_TIME_US2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_GET_CONFIG2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_GET_CONFIG2:
			/* Retrieve RxWaitTime */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXWAIT_US2, &wRegister2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_SET_CONFIG2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_SET_CONFIG2:
			/*Set all configuration needed for ReqA command*/
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_REQAEX2, PH_OFF2));
			PH_BREAK_ON_FAILURE2(statusTmp2);

			/*Only 7 bits are valid*/
			PH_CHECK_FAILURE_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_TXLASTBITS2, 7));

#ifdef NXPBUILD__PH_LOG_EX2
			if (bReqCode2 == 0x26U)
			{
				I14443P3_LOG_BUF2(">>> P3A_REQUEST_SEND:", cmd2, 1);
			}
			else if (bReqCode2 == 0x52U)
			{
				I14443P3_LOG_BUF2(">>> P3A_WAKEUP_SEND:", cmd2, 1);
			}
			else
			{
				; /* No action here */
			}
#endif
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_SENDCMD2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_SENDCMD2:
			PH_CHECK_INPROCESS_FCT2(statusExchange2, phhalHw_Exchange2(pDataParams2->pHalDataParams2,
					PH_EXCHANGE_DEFAULT2, cmd2, 1, &pResp2, &wRespLength2));

#ifdef NXPBUILD__PH_LOG_EX2
			if (bReqCode2 == 0x26U)
			{
				I14443P3_LOG2("<<< P3A_REQUEST_RESPONSE: %0X \r\n", statusTmp2);
			}
			else if (bReqCode2 == 0x52U)
			{
				I14443P3_LOG2("<<< P3A_WAKEUP_RESPONSE: %0X \r\n", statusTmp2);
			}
			else
			{
				; /* No action here */
			}
#endif
			pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif
			/*no break*/
		case PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME2:
			/* Restore previous RxWaitTime */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXWAIT_US2, wRegister2));
			PH_BREAK_ON_FAILURE2(statusTmp2);

			if (statusExchange2 != PH_ERR_SUCCESS2)
			{
				statusTmp2 = statusExchange2;
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}

			/* Check and copy ATQA */
			if (wRespLength2 == PHPAL_I14443P3A_ATQA_LENGTH2)
			{
				(void) phTools_memcpy2(pAtqa2, pResp2,
				PHPAL_I14443P3A_ATQA_LENGTH2);

				/* NFCForum-TS-DigitalProtocol-1.0, Requirement 18, Section 4.6.3.3 */
				if ((((pAtqa2[0] & 0x1FU) == 0x00U) && ((pAtqa2[1] & 0x0FU) != 0x0CU))
						|| (((pAtqa2[1] & 0x0FU) == 0x0CU) && ((pAtqa2[0] & 0x1FU) != 0x00U)))
				{
					statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2,
							PH_COMP_PAL_ISO14443P3A2);
				}
			}
			else
			{
				statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3A2);
			}
			break;
	}
	pDataParams2->eReqAExState2 = PHPAL_I14443P3A_REQAEX_IDLE2;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_GetSerialNo2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2)
{
	/* Return an error if UID is not complete */
	if (0U == (pDataParams2->bUidComplete2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_ISO14443P3A2);
	}

	/* Copy UID */
	(void) phTools_memcpy2(pUidOut2, pDataParams2->abUid2, pDataParams2->bUidLength2);
	*pLenUidOut2 = pDataParams2->bUidLength2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_VASUpA2(
    P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bFormatByte2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes2,
    VAR(uint8, ANFCRL_VAR) bLenCmdBytes2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_STATUS_INPROCESS2;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRegister2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 cmd2[255] = {0U};
	UNUSED2(pAtqa2);

	/*Check for invalid size configuration of the VASUP-A command frame.*/
	if( ( (bFormatByte2 == PHPAL_I14443P3A_VASUP_VERSION_012) &&
			( (bLenCmdBytes2 > PHPAL_I14443P3A_VASUP_VERSION_01_MAX_SIZE2) ||
			(bLenCmdBytes2 < PHPAL_I14443P3A_VASUP_VERSION_01_MIN_SIZE2) ) ) ||
			( (bFormatByte2 == PHPAL_I14443P3A_VASUP_VERSION_022) &&
			( (bLenCmdBytes2 > PHPAL_I14443P3A_VASUP_VERSION_02_MAX_SIZE2) ||
			(bLenCmdBytes2 < PHPAL_I14443P3A_VASUP_VERSION_02_MIN_SIZE2) ) ) )
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3A2);
	}

	switch (pDataParams2->eVASUpAState2)
	{
		case PHPAL_I14443P3A_VASUPA_IDLE2:
			PH_CHECK_SUCCESS_FCT2(status2, phpalI14443p3a_Sw_GetConfig2(pDataParams2,
					PHPAL_I14443P3A_CONFIG_OPE_MODE2, &wRegister2));
			/*VAS polling is available when the discovery loop is configured either in EMVCo mode or NFC mode*/
			if (wRegister2 == RD_LIB_MODE_ISO2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_PAL_ISO14443P3A2);
			}
			else
			{
				pDataParams2->eVASUpAState2 = PHPAL_I14443P3A_VASUPA_CONFIG2;
			}
			/* No break */
		case PHPAL_I14443P3A_VASUPA_CONFIG2:
#if 1 // CAS_KR: for fast card detection
			do
			{
				status2 =  phhalHw_SetConfig2(pDataParams2->pHalDataParams2,PHHAL_HW_CONFIG_TXCRC2, PH_ON2);
			} while (status2 == PH_STATUS_INPROCESS2);
#else
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXCRC2, PH_ON2));
#endif
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eVASUpAState2 = PHPAL_I14443P3A_VASUPA_SENDCMD2;
			/* No break */
		case PHPAL_I14443P3A_VASUPA_SENDCMD2:
			phTools_memcpy2(&cmd2[0], pCmdBytes2, bLenCmdBytes2);
			/* Send VASUP-A command */
#if 1 // CAS_KR: for fast card detection
			do
			{
				status2 =  phhalHw_Exchange2(pDataParams2->pHalDataParams2,
							PH_EXCHANGE_DEFAULT2, cmd2, ((bFormatByte2 == 0x01U) ? 5U : ((uint16)bLenCmdBytes2)),
							&pResp2, &wRespLength2);
			} while (status2 == PH_STATUS_INPROCESS2);
#else
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2,
				PH_EXCHANGE_DEFAULT2, cmd2, ((bFormatByte2 == 0x01U) ? 5U : ((uint16)bLenCmdBytes2)),
				&pResp2, &wRespLength2));
#endif
#ifdef NXPBUILD__PH_LOG_EX2
			I14443P3_LOG_BUF2(">>> PHPAL_I14443P3A_VASUP_SEND:", pCmdBytes2, bLenCmdBytes2);
			I14443P3_LOG2("<<< PHPAL_I14443P3A_VASUP_RESPONSE: %0X \r\n", status2);
#endif
			break;
	}

	pDataParams2->eVASUpAState2 = PHPAL_I14443P3A_VASUPA_IDLE2;
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3A_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef __cplusplus
}
#endif /*__cplusplus */
