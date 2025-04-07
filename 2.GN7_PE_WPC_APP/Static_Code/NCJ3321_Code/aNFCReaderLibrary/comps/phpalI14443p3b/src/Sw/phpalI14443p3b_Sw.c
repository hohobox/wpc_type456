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
*   @file    phpalI14443p3b_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3b - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3b ISO/IEC 14443-3B
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
#include <phTools.h>
#include <phpalI14443p3b.h>
#include <ph_RefDefs.h>
#include <phNxpNfcRdLib_Config.h>

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
#include "phpalI14443p3b_Sw.h"
#include "phpalI14443p3b_Sw_Int.h"
#include <phLog.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_SW_VENDOR_ID_C                      43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C       4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C       3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION_C    1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p3b_Sw.h header file are of the same vendor */
#if (PHPALI14443P3B_SW_VENDOR_ID_C != PHPALI14443P3B_SW_VENDOR_ID)
    #error "phpalI14443p3b_Sw.c and phpalI14443p3b_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p3b_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3b_Sw.c and phpalI14443p3b_Sw.h are different"
#endif
/* Check if current file and phpalI14443p3b_Sw.h header file are of the same Software version */
#if ((PHPALI14443P3B_SW_SW_MAJOR_VERSION_C != PHPALI14443P3B_SW_SW_MAJOR_VERSION) || \
     (PHPALI14443P3B_SW_SW_MINOR_VERSION_C != PHPALI14443P3B_SW_SW_MINOR_VERSION) || \
     (PHPALI14443P3B_SW_SW_PATCH_VERSION_C != PHPALI14443P3B_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3b_Sw.c and phpalI14443p3b_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */
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
#ifdef NXPBUILD__PHPAL_I14443P3B_SW
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_Init(
                                  P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                                  )
{
	if (sizeof(phpalI14443p3b_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_ISO14443P3B);
	}
	PH_ASSERT_NULL(pDataParams);
	PH_ASSERT_NULL(pHalDataParams);

	pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_START;
	pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_IDLE;
	pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_START;
	pDataParams->eSlotMrkState = PHPAL_I14443P3B_EXCHANGE_SEND;
	pDataParams->eHaltBState = PHPAL_I14443P3B_EXCHANGE_SEND;
    pDataParams->eSetBaudRateExState = PHPAL_I14443P3B_SETBAUDRATEEX_START;
    pDataParams->eCheckATQBExState = 0U;
	/* init private data */
	pDataParams->wId = PH_COMP_PAL_ISO14443P3B | PHPAL_I14443P3B_SW_ID;
	pDataParams->pHalDataParams = pHalDataParams;
	pDataParams->bExtAtqb = PH_OFF;
	pDataParams->bPupiValid = PH_OFF;
	pDataParams->bCidSupported = 0;
	pDataParams->bNadSupported = 0;
	pDataParams->bCid = 0;
	pDataParams->bFwi = PHPAL_I14443P3B_SW_FWI_DEFAULT;
	pDataParams->bFsci = PHPAL_I14443P3B_SW_FSCI_DEFAULT;
	pDataParams->bFsdi = 0;
	pDataParams->bDri = 0;
	pDataParams->bDsi = 0;
	pDataParams->bAttribParam1 = PHPAL_I14443P3B_SW_ATTRIB_PARAM1_DEFAULT;
	pDataParams->pHigherLayerInf = NULL;
	pDataParams->wTxWait = PHPAL_I14443P3B_SW_TXWAIT_US_DEFAULT;
	pDataParams->wHigherLayerInfLen = 0;
	pDataParams->pHigherLayerResp = NULL;
	pDataParams->wHigherLayerRespSize = 0;
	pDataParams->wHigherLayerRespLen = 0;
	pDataParams->bOpeMode = RD_LIB_MODE_NFC;
	pDataParams->bPollCmd = PHPAL_I14443P3B_USE_REQB;
	pDataParams->bRetryCount = PHPAL_I14443P3B_ATTRIB_RETRY_MAX;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SetConfig(
                                       P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wConfig,
                                       VAR(uint16, ANFCRL_VAR) wValue
                                       )
{
	switch (wConfig)
	{
		case PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM1:
			pDataParams->bAttribParam1 = (uint8) wValue;
			break;

			/* Emvco: To Define Running Mode for RdLib: Either Normal, EMVCO, ISO */
		case PHPAL_I14443P3B_CONFIG_OPE_MODE:
		{
			pDataParams->bOpeMode = (uint8) wValue;
			break;
		}

		case PHPAL_I14443P3B_CONFIG_POLL_CMD:
		{
			pDataParams->bPollCmd = (uint8) wValue;
			break;
		}

		case PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT:
		{
			if (!(((wValue & 0xFFU) == PHPAL_I14443P3B_ATTRIB_RETRY_MIN) || ((wValue & 0xFFU) == PHPAL_I14443P3B_ATTRIB_RETRY_MAX)))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
			}

			pDataParams->bRetryCount = (uint8) wValue;
			break;
		}
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P3B);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_GetConfig(
                                       P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wConfig,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                       )
{
	switch (wConfig)
	{
		case PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM1:
			*pValue = pDataParams->bAttribParam1;
			break;

		case PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT:
			*pValue = pDataParams->bRetryCount;
			break;

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_ISO14443P3B);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_GetSerialNo(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi
    )
{
	/* Return an error if PUPI is not valid */
	if (pDataParams->bPupiValid == PH_OFF)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_ISO14443P3B);
	}

	/* Copy PUPI */
	phTools_memcpy(pPupi, pDataParams->pPupi, (uint32) (sizeof(pDataParams->pPupi)));

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SetHigherLayerInf(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
    VAR(uint16, ANFCRL_VAR) wTxLength,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    VAR(uint16, ANFCRL_VAR) wRxBufSize
    )
{
	pDataParams->pHigherLayerInf = pTxBuffer;
	pDataParams->wHigherLayerInfLen = wTxLength;
	pDataParams->pHigherLayerResp = pRxBuffer;
	pDataParams->wHigherLayerRespSize = wRxBufSize;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_GetHigherLayerResp(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
    )
{
	*pRxBuffer = pDataParams->pHigherLayerResp;
	*pRxLength = pDataParams->wHigherLayerRespLen;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_GetProtocolParams(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
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

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_CheckATQBEx(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
    VAR(uint16, ANFCRL_VAR) wRespLength,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen
    )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTR2 = 0U;

	switch (pDataParams->eCheckATQBExState)
	{
		case 0U:
			/* Response check */
			/* Digital Protocol Requirement 49, Section 5.6.1.5 */
			if ((wRespLength != 12U) && (wRespLength != 13U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
			}

			/* The ATQB should look like the following (see ISO14443-3 7.9.1): */
			/* [0x50][PUPI0][PUPI1][PUPI2][PUPI3][PInfo0][PInfo1][PInfo2]([PInfo3])[CRC][CRC] */

			if (pResp[0] != 0x50U) /* ATQB byte */
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
			}

			/* Copy received AtqB */
			phTools_memcpy(pAtqb, pResp, wRespLength);
			*pAtqbLen = (uint8) wRespLength;

			if (pDataParams->bOpeMode != RD_LIB_MODE_NFC)
			{
				/* Max allowed frame size integer for ISO and EMVCo(v3.0) mode is less than or equals to 0x0C (4096 bytes) */
				if ((uint8) (pAtqb[10] & 0xF0U) > 0xC0U)
				{
					pAtqb[10] = (pAtqb[10] & 0x0FU) | 0xC0U;
				}
			}
			else
			{
				/* Max allowed frame size integer for NFC(DP 1.1, Requirements 64) mode is less than or equals to 0x08 (256 bytes) */
				if ((uint8) (pAtqb[10] & 0xF0U) > 0x80U)
				{
					pAtqb[10] = (pAtqb[10] & 0x0FU) | 0x80U;
				}
			}

			if (pDataParams->bOpeMode == RD_LIB_MODE_ISO)
			{
				/* Check TR2 value received in Atqb and set relevant TxWait as per ISO-IEC 14443-3. */
				bTR2 = (uint8) ((pAtqb[10] & PHPAL_I14443P3B_SW_MINIMUM_TR2_MASK) >> PHPAL_I14443P3B_SW_MINIMUM_TR2_POS);
				switch (bTR2)
				{
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_0:
						pDataParams->wTxWait = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_0;
						break;
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_1:
						pDataParams->wTxWait = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_1;
						break;
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_2:
						pDataParams->wTxWait = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_2;
						break;
					default:
						pDataParams->wTxWait = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_3;
						break;
				}
				pDataParams->eCheckATQBExState = 1U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* If the TR2 value is (11)b then the default TxWait of 500us (6780/fc) has to changed to 699us (9472/fc). */
				if ((uint8) ((pAtqb[10] & PHPAL_I14443P3B_SW_MINIMUM_TR2_MASK) >> PHPAL_I14443P3B_SW_MINIMUM_TR2_POS) == PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_3)
				{
					pDataParams->wTxWait = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_3;
					pDataParams->eCheckATQBExState = 2U;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					pDataParams->wTxWait = PHPAL_I14443P3B_SW_TXWAIT_US_DEFAULT;
				}
			}
			break;
		case 1U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, pDataParams->wTxWait));
			break;
		case 2U:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, PHPAL_I14443P3B_SW_TXWAIT_US_TR2_3));
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	/* and also copy the PUPI into the protocol params structure to be available
	 for a possible following HaltB command */
	phTools_memcpy(pDataParams->pPupi, &pAtqb[1], (uint32) (sizeof(pDataParams->pPupi)));
	pDataParams->bPupiValid = PH_ON;
	pDataParams->eCheckATQBExState = 0u;

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SetReaderBaudRateEx( P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxDataRate = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxDataRate = 0;

    switch (pDataParams->eSetBaudRateExState)
    {
        case PHPAL_I14443P3B_SETBAUDRATEEX_START:
            /* Check and convert Dri value */
            switch (pDataParams->bDri)
            {
                case PHPAL_I14443P3B_DATARATE_106:
                    wTxDataRate = PHHAL_HW_RF_DATARATE_106;
                    break;
                case PHPAL_I14443P3B_DATARATE_212:
                    wTxDataRate = PHHAL_HW_RF_DATARATE_212;
                    break;
                case PHPAL_I14443P3B_DATARATE_424:
                    wTxDataRate = PHHAL_HW_RF_DATARATE_424;
                    break;
                case PHPAL_I14443P3B_DATARATE_848:
                    wTxDataRate = PHHAL_HW_RF_DATARATE_848;
                    break;
                default:
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
            }

            /* Check and convert Dsi value */
            switch (pDataParams->bDsi)
            {
                case PHPAL_I14443P3B_DATARATE_106:
                    wRxDataRate = PHHAL_HW_RF_DATARATE_106;
                    break;
                case PHPAL_I14443P3B_DATARATE_212:
                    wRxDataRate = PHHAL_HW_RF_DATARATE_212;
                    break;
                case PHPAL_I14443P3B_DATARATE_424:
                    wRxDataRate = PHHAL_HW_RF_DATARATE_424;
                    break;
                case PHPAL_I14443P3B_DATARATE_848:
                    wRxDataRate = PHHAL_HW_RF_DATARATE_848;
                    break;
                default:
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
            }
            pDataParams->eSetBaudRateExState = PHPAL_I14443P3B_SETBAUDRATEEX_TX;
            /* no break */

        case PHPAL_I14443P3B_SETBAUDRATEEX_TX:
            /* Apply new data rates to Pcd */
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
                    pDataParams->pHalDataParams,
                    PHHAL_HW_CONFIG_TXDATARATE_FRAMING,
                    wTxDataRate));
            PH_BREAK_ON_FAILURE(statusTmp);
            pDataParams->eSetBaudRateExState = PHPAL_I14443P3B_SETBAUDRATEEX_RX;
            /* no break */

        case PHPAL_I14443P3B_SETBAUDRATEEX_RX:
            /* Apply new data rates to Pcd */
            PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
                    pDataParams->pHalDataParams,
                    PHHAL_HW_CONFIG_RXDATARATE_FRAMING,
                    wRxDataRate));
            PH_BREAK_ON_FAILURE(statusTmp);
            break;
    }

    pDataParams->eSetBaudRateExState = PHPAL_I14443P3B_SETBAUDRATEEX_START;
    return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_DecideBaudRateEx( VAR(uint8, ANFCRL_VAR) bBitRateCapability, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDri, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDsi )
{
  VAR(uint8, ANFCRL_VAR) bMaxSymBitRate = 0;

	/* Use the given values for Dri and Dsi, if the caller wants so, or
	 calculate Dsi and Dri depending on the given parameters and what the PICC is supporting,
	 assuming that the reader supports all data rates in both directions. */

	/* Check if only symmetric bit rates are supported, check also if b4 is set.
	 If the caller forces one of the data rates, it is not possible to make a decision */

	if ((0U == ((*pbDsi & PHPAL_I14443P3B_DATARATE_FORCE))) && (0U == ((*pbDri & PHPAL_I14443P3B_DATARATE_FORCE))))
	{
		/* ISO/IEC14443-3 p41: If b4=(1)b should interpret the Bit_Rate_Capability byte as if 0x00 */
		if (0U != (bBitRateCapability & 0x08U))
		{
			*pbDsi = 0;
			*pbDri = 0;
			return PH_ERR_SUCCESS;
		}

		/* Symmetric baud rates */
		if ((0U != ((bBitRateCapability & 0x80U))) && (*pbDsi != *pbDri))
		{
			/* Start with the lower one of these both */
			if (*pbDsi > *pbDri)
			{
				bMaxSymBitRate = *pbDri;
			}
			else
			{
				bMaxSymBitRate = *pbDsi;
			}

			/* Start with the desired bit rate and break, as soon as a supported one is found. */
			switch (bMaxSymBitRate)
			{
			case PHPAL_I14443P3B_DATARATE_848:
				if (0x44U == (bBitRateCapability & 0x44U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_424:
				bMaxSymBitRate = PHPAL_I14443P3B_DATARATE_424;
				if (0x22U == (bBitRateCapability & 0x22U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_212:
				bMaxSymBitRate = PHPAL_I14443P3B_DATARATE_212;
				if (0x11U == (bBitRateCapability & 0x11U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_106: /* is supported anyway */
				bMaxSymBitRate = PHPAL_I14443P3B_DATARATE_106;
				break;
			default:
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P3B);
			}

			*pbDri = bMaxSymBitRate;
			*pbDsi = *pbDri;
			return PH_ERR_SUCCESS;
		}
	}

	if (0U != (*pbDsi & PHPAL_I14443P3B_DATARATE_FORCE))
	{
		*pbDsi = *pbDsi & 0x0FU;
	}
	else
	{
		/* Start with the desired bit rate and break, as soon as a supported one is found. */
		switch (*pbDsi)
		{
		case PHPAL_I14443P3B_DATARATE_848:
			if (0U != (bBitRateCapability & 0x40U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_424:
			*pbDsi = PHPAL_I14443P3B_DATARATE_424;
			if (0U != (bBitRateCapability & 0x20U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_212:
			*pbDsi = PHPAL_I14443P3B_DATARATE_212;
			if (0U != (bBitRateCapability & 0x10U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_106: /* is supported anyway */
			*pbDsi = PHPAL_I14443P3B_DATARATE_106;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P3B);
		}
	}
	if (0U != (*pbDri & PHPAL_I14443P3B_DATARATE_FORCE))
	{
		*pbDri = *pbDri & 0x0FU;
	}
	else
	{
		/* Start with the desired bit rate and break, as soon as a supported one is found. */
		switch (*pbDri)
		{
		case PHPAL_I14443P3B_DATARATE_848:
			if (0U != (bBitRateCapability & 0x04U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_424:
			*pbDri = PHPAL_I14443P3B_DATARATE_424;
			if (0U != (bBitRateCapability & 0x02U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_212:
			*pbDri = PHPAL_I14443P3B_DATARATE_212;
			if (0U != (bBitRateCapability & 0x01U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_106: /* is supported anyway */
			*pbDri = PHPAL_I14443P3B_DATARATE_106;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_PAL_ISO14443P3B);
		}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SetSerialNo(P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi)
{
	phTools_memcpy(pDataParams->pPupi, pPupi, (uint32) (sizeof(pDataParams->pPupi)));
	pDataParams->bPupiValid = PH_ON;

	return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_RequestB(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint8, ANFCRL_VAR) bNumSlots,
                                      VAR(uint8, ANFCRL_VAR) bAfi,
                                      VAR(uint8, ANFCRL_VAR) bExtAtqb,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen
                                      )
{
	return phpalI14443p3b_Sw_RequestBEx(pDataParams, 0, bNumSlots, bAfi, bExtAtqb, pAtqb, pAtqbLen);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_WakeUpB(
                                     P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint8, ANFCRL_VAR) bNumSlots,
                                     VAR(uint8, ANFCRL_VAR) bAfi,
                                     VAR(uint8, ANFCRL_VAR) bExtAtqb,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen
                                     )
{
	return phpalI14443p3b_Sw_RequestBEx(pDataParams, 1, bNumSlots, bAfi, bExtAtqb, pAtqb, pAtqbLen);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SlotMarker(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint8, ANFCRL_VAR) bSlotNumber,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen
                                        )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] =
	{ 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0;

	switch (pDataParams->eSlotMrkState)
	{
	case PHPAL_I14443P3B_EXCHANGE_SEND:
		/* Parameter check */
		if ((bSlotNumber < 2U) || (bSlotNumber > 16U))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
		}

		/* Note: No need to set time out and RxDeafTime since this is done in RequestB,
		 which must be the previous command. */

		/* SlotNumber 2-16 */
		/* Build the command */
		aCmd[0] = (uint8) (((uint8) (bSlotNumber - 1U) & 0x0FU) << 4U) | 0x05U;
		I14443P3_LOG(">>> P3B_SLOTMAKER_SEND SlotIndex:%d  *** \r\n", bSlotNumber);
		pDataParams->eSlotMrkState = PHPAL_I14443P3B_EXCHANGE_WAITRSP;
		/* no break */
	case PHPAL_I14443P3B_EXCHANGE_WAITRSP:
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, aCmd, 1, &pResp, &wRespLength));
		I14443P3_LOG("<<< P3B_SLOTMAKER_WAITRSP Status: %0X \r\n", status);
		PH_BREAK_ON_FAILURE(status);
		status = phpalI14443p3b_Sw_CheckATQBEx(pDataParams, pResp, wRespLength, pAtqb, pAtqbLen);
	}
	pDataParams->eSlotMrkState = PHPAL_I14443P3B_EXCHANGE_SEND;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_HaltB(
                                   P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[5] =
	{ 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0;

	switch (pDataParams->eHaltBState)
	{
	case PHPAL_I14443P3B_EXCHANGE_SEND:
        PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, PHPAL_I14443P3B_SW_ATTRIB_TIME_US + PHPAL_I14443P3B_SW_EXT_TIME_US));
        PH_BREAK_ON_FAILURE(status);
        I14443P3_LOG(">>> P3B_HALTB_SEND  \r\n");

        /* Build the command */
        aCmd[0] = PHPAL_I14443P3B_SW_HALT_CMD;
        (void) phTools_memcpy(&aCmd[1], pDataParams->pPupi, (uint32) (sizeof(pDataParams->pPupi)));

        pDataParams->eHaltBState = PHPAL_I14443P3B_EXCHANGE_WAITRSP;
		/* no break */
	case PHPAL_I14443P3B_EXCHANGE_WAITRSP:
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, aCmd, 5, &pResp, &wRespLength));

		I14443P3_LOG("<<< P3B_HALTB_WAITRSP Status: %0X \r\n", status);
		PH_BREAK_ON_FAILURE(status);

		/* Response check */
		if ((wRespLength != 1U) || (pResp[0] != PHPAL_I14443P3B_SW_HALT_RESP))
		{
			status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
			break;
		}
		/* PUPI is invalid */
		pDataParams->bPupiValid = PH_OFF;
	}
	pDataParams->eHaltBState = PHPAL_I14443P3B_EXCHANGE_SEND;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_Attrib(
                                    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
                                    VAR(uint8, ANFCRL_VAR) bAtqbLen,
                                    VAR(uint8, ANFCRL_VAR) bFsdi,
                                    VAR(uint8, ANFCRL_VAR) bCid,
                                    VAR(uint8, ANFCRL_VAR) bDri,
                                    VAR(uint8, ANFCRL_VAR) bDsi,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli
                                    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[9];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTemp = 0U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwSfgt = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwFwt = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSetBaudRateFlag = 0U;

	switch (pDataParams->eAttribState)
	{
        case PHPAL_I14443P3B_ATTRIB_START:
            bSetBaudRateFlag = 0U;
            /* parameter check */
            /* ATQB length */
            if ((bAtqbLen != 12U) && (bAtqbLen != 13U))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
            }

            /* check given DSI, DRI, FSDI */
            if ((bFsdi > PHPAL_I14443P3B_FRAMESIZE_MAX) || (bDri > 0x03U) || (bDsi > 0x03U))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
            }

            /* build the command frame */
            aCmd[0] = PHPAL_I14443P3B_SW_ATTRIB_CMD;

            /* copy PUPI to command frame */
            phTools_memcpy(&aCmd[1], &pAtqb[1], 4);

            /* Param1: TR0, TR1, SOF/EOF suppression */
            aCmd[5] = pDataParams->bAttribParam1;

            (void)phpalI14443p3b_Sw_DecideBaudRateEx(pAtqb[9], &bDri, &bDsi);
            /* Param2: Dsi, Dri, FSDI */
            aCmd[6] = (bDsi << 6U) | (bDri << 4U) | bFsdi;

            /* Param3: confirmation of protocol info byte 2 (protocol type and minimum TR2) */
            aCmd[7] = pAtqb[10] & 0x07U;

            /* Param4: Cid */
            /* check if supported by PICC, check given value for < 0x0F */
            if (0U != (pAtqb[11] & 0x01U))
            {
                if (bCid > 0x0EU)
                {
                    return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
                }
            }
            else
            {
                bCid = 0x00;
            }
            aCmd[8] = bCid;

            /* Calculate FWT timeout */
            /* get the Fwt, because we need it for the timeout. */
            pDataParams->bFwi = (uint8) (pAtqb[11] >> 4U);
            if (pDataParams->bFwi == 0x0FU)
            {
                pDataParams->bFwi = PHPAL_I14443P3B_SW_FWI_DEFAULT;
            }

            /* Calculate FWT timeout */
            dwFwt = (PHPAL_I14443P3B_SW_FWT_MIN_US * ((uint32) 1U << pDataParams->bFwi));
            if (pDataParams->bOpeMode == RD_LIB_MODE_ISO)
            {
                /* Add extension time */
                dwFwt += PHPAL_I14443P3B_SW_EXT_TIME_US;
            }
            else
            {
                /* As per Digital Spec V1.1 req 7.9.1.3, NFC Forum Device SHALL wait at least FWT + delta FWTB for a Response */
                dwFwt += PHPAL_I14443P3B_SW_DELTA_FWT_US;
                if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
                {
                    /* As per EMVCo, add delta Tpcd time along with delta FWT time */
                    dwFwt += PHPAL_I14443P3B_SW_DELTA_TPCD_US;
                }
            }

            /* Set Attrib timeout */
            /* ISO IEC 14443-3, 7.9.4.3 FWI:
             In case of extended ATQB ...
             ... FWT applies after the Answer to ATTRIB and
             ... the waiting time for the Answer to ATTRIB is fixed to ~4,8 ms */

            if (bAtqbLen == 13U)
            {
                pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT;
            }
            else
            {
                I14443P3_LOG("*** SET FWT dwFwt:%d \r\n", dwFwt);
                /* Set FWT timeout */
                if (dwFwt > 0xFFFFU)
                {
                    /* +1 is added to the timeout in millisecond to compensate the
                     * fractional microseconds lost in division by 1000 */
                    pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS;
                }
                else
                {
                    pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US;
                }
            }
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
                                                           PHPAL_I14443P3B_SW_ATTRIB_TIME_US + PHPAL_I14443P3B_SW_EXT_TIME_US));
            PH_BREAK_ON_FAILURE(status);
            bTemp = pDataParams->bRetryCount + 1u;
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, (uint16)((dwFwt / 1000U) + 1U)));
            PH_BREAK_ON_FAILURE(status);
            bTemp = pDataParams->bRetryCount + 1u;
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, (uint16)dwFwt));
            PH_BREAK_ON_FAILURE(status);
            bTemp = pDataParams->bRetryCount + 1u;
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST:
            /* Exchange command */
            wRespLength = 0;
            PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange( pDataParams->pHalDataParams, PH_EXCHANGE_BUFFER_FIRST, aCmd, 9, &pResp, &wRespLength));
            PH_BREAK_ON_FAILURE(status);
            I14443P3_LOG_BUF(">>> P3B_ATTRIB_SEND:", aCmd, 9U);
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST;
            return PH_STATUS_INPROCESS;

        case PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST:
            if(0U == bSetBaudRateFlag)
            {
                /* the remaining part of the ATTRIB command frame holds the Higher Layer INF */
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_BUFFER_LAST, pDataParams->pHigherLayerInf, pDataParams->wHigherLayerInfLen, &pResp, &wRespLength));

#ifdef NXPBUILD__PH_LOG_EX
                if (status == PH_ERR_SUCCESS)
                {
                    I14443P3_LOG_BUF("<<< P3B_ATTRIB_WAITRSP:", pResp, (uint8 )wRespLength);
                }
                else
                {
                    I14443P3_LOG("<<< P3B_ATTRIB_WAITRSP: %0X \r\n", status);
                }
#endif
                bTemp--;
                /* check and perform re-transmission of ATTRIB in case of Transmission or Timeout error
                 * Nfc Digital Specification ver 1.1, Req 14.7.1.1
                 */
                if ((bTemp > 0U) && (PH_ERR_SUCCESS != (status & PH_ERR_MASK)))
                {
                    pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST;
                    return PH_STATUS_INPROCESS;
                }

                PH_BREAK_ON_FAILURE(status);

                /* we hopefully received at least one byte */
                if (wRespLength < 1U)
                {
                    status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
                    break;
                }

                /* we receive MBLI and CID in the first byte: */
                /* check the received cid: */
                if (((pAtqb[11] & 0x01U) != 0U) && ((pResp[0] & 0x0FU) != bCid))
                {
                    status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
                    break;
                }

                /* If the CID is not supported, PICC SHALL set the CID to 0 */
                /* PCD SHALL treat a CID field with a different value as Protocol Error */
                /* Digital Protocol 1.1, Requirements 166 and EMVCo 2.6, Requirements 6.24, 6.4.1.10 */
                if ((pDataParams->bOpeMode != RD_LIB_MODE_ISO)
                        && (((pAtqb[11] & 0x01U) == 0U) && ((pResp[0] & 0x0FU) != 0x0U)))
                {
                    status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
                    break;
                }

                /* Note: ISO14443-3 7.11: The MBLI (maximum buffer size) gives information about
                 the PICCs internal buffer */
                *pMbli = (uint8) (pResp[0] >> 4U);

                if (1U < wRespLength)
                {
                    /* we received some Higher Layer INF bytes:
                     ISO14443-3 TypeB, 7.11 Higher Response (optional 0 or "more" bytes) --> see page 46. */
                    pDataParams->wHigherLayerRespLen = wRespLength - 1u;

                    /* should we have received it? */
                    if (pDataParams->wHigherLayerInfLen == 0U)
                    {
                        pDataParams->wHigherLayerRespLen = 0;
                        status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_ISO14443P3B);
                        break;
                    }

                    if (pDataParams->wHigherLayerRespLen > pDataParams->wHigherLayerRespSize)
                    {
                        pDataParams->wHigherLayerRespLen = 0;
                        status = PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_PAL_ISO14443P3B);
                        break;
                    }
                    (void) phTools_memcpy(pDataParams->pHigherLayerResp, &pResp[1], pDataParams->wHigherLayerRespLen);
                }

                /* Now, that the PICC accepted our protocol settings, we can store them in the structure */
                pDataParams->bCidSupported = pAtqb[11] & 0x01U;
                pDataParams->bNadSupported = (pAtqb[11] & 0x02U) >> 1U;
                pDataParams->bCid = pResp[0] & 0x0FU;
                pDataParams->bFsci = (uint8) (pAtqb[10] >> 4U);
                pDataParams->bFsdi = bFsdi;
                pDataParams->bDri = bDri;
                pDataParams->bDsi = bDsi;

                bTemp = 0;
                /* If we had an extended ATQB, the timeout was set for the reception
                 of the ATTRIB command (see line 280). */
                if (bAtqbLen == 13U)
                {
                    /* Set FWT timeout */
                    if (dwFwt > 0xFFFFU)
                    {
                        pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS;
                        return PH_STATUS_INPROCESS;
                    }
                    else
                    {
                        pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US;
                        return PH_STATUS_INPROCESS;
                    }
                }
                bSetBaudRateFlag = 1U;
            }
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, (uint16)(dwFwt / 1000U)));
            PH_BREAK_ON_FAILURE(status);
            bSetBaudRateFlag = 1U;
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US:
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US, (uint16)dwFwt));
            PH_BREAK_ON_FAILURE(status);
            bSetBaudRateFlag = 1U;
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS:
            if(1U == bSetBaudRateFlag)
            {
                /* Set baud rate on Pcd */
                PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_Sw_SetReaderBaudRateEx(pDataParams));
                bSetBaudRateFlag = 0U;
                PH_BREAK_ON_FAILURE(status);
            }
            pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US;
            return PH_STATUS_INPROCESS;
        case PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US:
            /* Applying Tx Wait saved according to the TR value of ATQb as setreaderbaudrateEx restores default */
            PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, pDataParams->wTxWait));
            PH_BREAK_ON_FAILURE(status);

            /* If we have had received an extended ATQB with an SFGT (startup frame guard time)
             we need to wait this time here. */
            if (bAtqbLen == 13U)
            {
                /* fetch sfgi value from response */
                bTemp = (uint8) (pAtqb[12] >> 4U);

                if (bTemp == 0x0FU)
                {
                    bTemp = PHPAL_I14443P3B_SW_SFGI_DEFAULT;
                }

                pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_GUARDTIME;
                return PH_STATUS_INPROCESS;
            }
            break;
        case PHPAL_I14443P3B_ATTRIB_GUARDTIME:
            /* Calculate SFGT in Microseconds */
            dwSfgt = (PHPAL_I14443P3B_SW_FWT_MIN_US * ((uint32) 1U << bTemp)) + PHPAL_I14443P3B_SW_EXT_TIME_US;
            /* Perform SFGT Wait */
            if (dwSfgt > 0xFFFFU)
            {
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pDataParams->pHalDataParams, PHHAL_HW_TIME_MILLISECONDS, (uint16 )(dwSfgt / 1000U)));
            }
            else
            {
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pDataParams->pHalDataParams, PHHAL_HW_TIME_MICROSECONDS, (uint16 )dwSfgt));
            }
        }
        bSetBaudRateFlag = 0U;
        pDataParams->eAttribState = PHPAL_I14443P3B_ATTRIB_START;
        return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_ActivateCard(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi,
    VAR(uint8, ANFCRL_VAR) bPupiLength,
    VAR(uint8, ANFCRL_VAR) bNumSlotIndex,
    VAR(uint8, ANFCRL_VAR) bAfi,
    VAR(uint8, ANFCRL_VAR) bExtAtqb,
    VAR(uint8, ANFCRL_VAR) bFsdi,
    VAR(uint8, ANFCRL_VAR) bCid,
    VAR(uint8, ANFCRL_VAR) bDri,
    VAR(uint8, ANFCRL_VAR) bDsi,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
    )
{
  static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusFirstError = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSlot;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumSlots = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bPICCsFound;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM pLocalAtqb[13];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bLocalAtqbLen;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pLocalPupi = NULL;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBreakfromloop;

	switch (pDataParams->eActCardState)
	{
	case PHPAL_I14443P3B_ACTCARD_START:
		bPICCsFound = 0u;
		bLocalAtqbLen = 0x00u;
		pLocalPupi = &pLocalAtqb[1];
		*pMoreCardsAvailable = 0x00u;
		bBreakfromloop = 0u;
		bNumSlots = 0u;

		/* initialize the statusFirstError with timeout, which is the trigger */
		statusFirstError = PH_ERR_IO_TIMEOUT;

		/* Parameter check */
		/* number of slots and length of PUPI */
		if ((bNumSlotIndex > 4U) || ((bPupiLength > 0U) && (bPupiLength != 4U) && (pDataParams->bPollCmd != PHPAL_I14443P3B_USE_WUPB)))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
		}

		/* check given DSI, DRI, FSDI */
		if ((bFsdi > PHPAL_I14443P3B_FRAMESIZE_MAX) || ((bDri & ~PHPAL_I14443P3B_DATARATE_FORCE) > 3U) || ((bDsi & ~PHPAL_I14443P3B_DATARATE_FORCE) > 3U))
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
		}

		/* Cid */
		if (bCid > 14U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
		}

		pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_REQB_WKUPB;
		/* no break */
	case PHPAL_I14443P3B_ACTCARD_REQB_WKUPB:
		/* Do Anti-collision loop */

		if (bPupiLength != 0U)
		{
			status = phpalI14443p3b_WakeUpB(pDataParams, bNumSlotIndex, bAfi, bExtAtqb, pLocalAtqb, &bLocalAtqbLen);
		}
		else
		{
			status = phpalI14443p3b_RequestB(pDataParams, bNumSlotIndex, bAfi, bExtAtqb, pLocalAtqb, &bLocalAtqbLen);
		}
		if (status == PH_STATUS_INPROCESS)
		{
			return PH_STATUS_INPROCESS;
		}

		/* SlotMarkers */
		/* If the bNumSlots == 0U, we do not send any SlotMarker commands (the following for loop). */
		if (bNumSlotIndex != 0U)
		{
			/* calculate the number of slots reusing bNumSlots */
			bNumSlots = (uint8) (1U << bNumSlotIndex);
		}
		bSlot = 2U;
		pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_SLOTMAKER;
		return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_ACTCARD_SLOTMAKER:
		if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
			/* if the caller provided a PUPI, we try to find and activate only the according PICC */
			if (bPupiLength != 0U)
			{
				/* compare PUPIs */
				if (memcmp(pPupi, pLocalPupi, 4U) == 0)
				{
					++bPICCsFound;
					bBreakfromloop = 1U;
				}
			}
			/* no PUPI provided by caller */
			else
			{
				++bPICCsFound;
				bBreakfromloop = 1U;
			}
		}
		/* Integrity Error means collision */
		else
		{
			if ((status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR)
			{
				*pMoreCardsAvailable = 0x01;
			}
		}

		/* Update first error */
		if ((statusFirstError & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
		{
			statusFirstError = status;
		}
		if (bSlot > bNumSlots)
		{
			bBreakfromloop = 1U;
		}
		if (bBreakfromloop == 1U)
		{
			/* check if we found no PICC */
			if (0U == (bPICCsFound))
			{
				status = PH_ADD_COMPCODE_FIXED(statusFirstError, PH_COMP_HAL);
				break;
			}
			if (bLocalAtqbLen != 0U)
			{
				(void) phTools_memcpy(pAtqb, pLocalAtqb, bLocalAtqbLen);
			}
			*pAtqbLen = bLocalAtqbLen;
			I14443P3_LOG_BUF("*** ATQB:", pAtqb, bLocalAtqbLen);
			/* Find the baud rates which shall be used. pAtqb[9] holds the VICCs bit rate capabilities. */
			PH_CHECK_FAILURE_FCT(status, phpalI14443p3b_Sw_DecideBaudRateEx(pAtqb[9], &bDri, &bDsi));
			pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_ATTRIBUTE;
			return PH_STATUS_INPROCESS;
		}
		pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP;
		return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP:
		PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_SlotMarker(pDataParams, bSlot, pLocalAtqb, &bLocalAtqbLen));

		pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_SLOTMAKER;
		bSlot++;
		return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_ACTCARD_ATTRIBUTE:
		/* AttribB: activate the first PICC found */
		PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_Attrib(pDataParams, pAtqb, *pAtqbLen, bFsdi, bCid, bDri, bDsi, pMbli));

		if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
		{
			/* PUPI is invalid */
			pDataParams->bPupiValid = PH_OFF;
		}
	}
	pDataParams->eActCardState = PHPAL_I14443P3B_ACTCARD_START;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_Exchange(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wOption,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                      VAR(uint16, ANFCRL_VAR) wTxLength,
                                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                      )
{
	/* direct mapping of hal exchange function */
	return phhalHw_Exchange(pDataParams->pHalDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_RequestBEx(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint8, ANFCRL_VAR) bIsWakeUp,
                                        VAR(uint8, ANFCRL_VAR) bNumSlots,
                                        VAR(uint8, ANFCRL_VAR) bAfi,
                                        VAR(uint8, ANFCRL_VAR) bExtAtqb,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen
                                        )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[3];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0;

	switch (pDataParams->eReqBExState)
	{
	case PHPAL_I14443P3B_REQUESTBEX_IDLE:
		/* parameter check */
		if (bNumSlots > 4U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_ISO14443P3B);
		}

		/* AFi|isWakeUp|NumSlots|extAtqB */
		/* Build the command */
		aCmd[0] = PHPAL_I14443P3B_SW_APF;
		aCmd[1] = bAfi;
		aCmd[2] = bNumSlots; /* N = 2^bNumSlots*/

		/* Set wakeup bit if necessary */
		if (0U != (bIsWakeUp))
		{
			aCmd[2] |= PHPAL_I14443P3B_SW_PARAM_WUP_BIT;
		}

		/* Enable Extended ATQB if necessary */
		if (bExtAtqb != PH_OFF)
		{
			aCmd[2] |= PHPAL_I14443P3B_SW_PARAM_EXTATQB_BIT;
		}

		/* Store usage of Extended ATQB */
		pDataParams->bExtAtqb = bExtAtqb;

		/* PUPI is invalid */
		pDataParams->bPupiValid = PH_OFF;
#ifdef NXPBUILD__PH_LOG_EX
		if (0U == bIsWakeUp)
		{
			I14443P3_LOG_BUF(">>> P3B_REQB_SEND:", aCmd, 3U);
		}
		else
		{
			I14443P3_LOG_BUF(">>> P3B_WAKEUPB_SEND:", aCmd, 3U);
		}
#endif
        pDataParams->eReqBExState = PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING;
        /* no break */
    case PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING:
        /* Reset default data rates */
        PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
                    PHHAL_HW_CONFIG_TXDATARATE_FRAMING, PHHAL_HW_RF_DATARATE_106));
        PH_BREAK_ON_FAILURE(status);
        pDataParams->eReqBExState = PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING;
        /* no break */
    case PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING:
        PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
                PHHAL_HW_CONFIG_TXDATARATE_FRAMING, PHHAL_HW_RF_DATARATE_106));
        PH_BREAK_ON_FAILURE(status);
        pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_CONFIG;
        return PH_STATUS_INPROCESS;

	case PHPAL_I14443P3B_REQUESTBEX_CONFIG:
		/* Set RequestB timeout */
		if (pDataParams->bOpeMode == RD_LIB_MODE_ISO)
		{
		    pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US;
		}
		else
		{
			/* As per Digital Protocol Ver1.1 Article 7.9.1.5
			 * PCD should wait ~17ms (FWT(B,SENSB) + T(B,POLL)) * (566us + 16.4ms = ~17ms)
			 */
            pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS;
		}
        return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US:
        /* Set RequestB timeout */
	    PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
	                                                             PHPAL_I14443P3B_SW_ATQB_TIME_US + PHPAL_I14443P3B_SW_EXT_TIME_US));
	    PH_BREAK_ON_FAILURE(status);
        pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_EXCHANGE;
        return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS:
        /* As per Digital Protocol Ver1.1 Article 7.9.1.5
         * PCD should wait ~17ms (FWT(B,SENSB) + T(B,POLL)) * (566us + 16.4ms = ~17ms)
         */
	    PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS, PHPAL_I14443P3B_SW_DELTA_POLL));
        PH_BREAK_ON_FAILURE(status);
        pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_EXCHANGE;
        return PH_STATUS_INPROCESS;
	case PHPAL_I14443P3B_REQUESTBEX_EXCHANGE:
		PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(pDataParams->pHalDataParams, PH_EXCHANGE_DEFAULT, aCmd, 3, &pResp, &wRespLength));
		I14443P3_LOG("<<< P3B_ATQB_WAITRSP Status: %0X \r\n", status);
		PH_BREAK_ON_FAILURE(status);
		I14443P3_LOG_BUF("<<< P3B_ATQB_RESP:", pResp, (uint8)wRespLength);

		status = phpalI14443p3b_Sw_CheckATQBEx(pDataParams, pResp, wRespLength, pAtqb, pAtqbLen);
	}
	pDataParams->eReqBExState = PHPAL_I14443P3B_REQUESTBEX_IDLE;
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3B_SW */

#ifdef __cplusplus
}
#endif /*__cplusplus */
