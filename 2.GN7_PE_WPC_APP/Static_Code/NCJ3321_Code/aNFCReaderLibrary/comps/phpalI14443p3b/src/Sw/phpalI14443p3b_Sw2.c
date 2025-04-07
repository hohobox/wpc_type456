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
*   @file    phpalI14443p3b_Sw2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3b - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3b2 ISO/IEC 14443-3B
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
#include <phhalHw2.h>
#include <phTools2.h>
#include <phpalI14443p3b2.h>
#include <ph_RefDefs2.h>
#include <phNxpNfcRdLib_Config2.h>

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
#include "phpalI14443p3b_Sw2.h"
#include "phpalI14443p3b_Sw_Int2.h"
#include <phLog2.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_SW_VENDOR_ID_C2                      43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C2       4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C2       3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION_C2    1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p3b_Sw2.h header file are of the same vendor */
#if (PHPALI14443P3B_SW_VENDOR_ID_C2 != PHPALI14443P3B_SW_VENDOR_ID2)
    #error "phpalI14443p3b_Sw2.c and phpalI14443p3b_Sw2.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p3b_Sw2.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C2    != PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION_C2 != PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalI14443p3b_Sw2.c and phpalI14443p3b_Sw2.h are different"
#endif
/* Check if current file and phpalI14443p3b_Sw2.h header file are of the same Software version */
#if ((PHPALI14443P3B_SW_SW_MAJOR_VERSION_C2 != PHPALI14443P3B_SW_SW_MAJOR_VERSION2) || \
     (PHPALI14443P3B_SW_SW_MINOR_VERSION_C2 != PHPALI14443P3B_SW_SW_MINOR_VERSION2) || \
     (PHPALI14443P3B_SW_SW_PATCH_VERSION_C2 != PHPALI14443P3B_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalI14443p3b_Sw2.c and phpalI14443p3b_Sw2.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */
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
#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Init2(
                                  P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                                  )
{
	if (sizeof(phpalI14443p3b_Sw_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P3B2);
	}
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pHalDataParams2);

	pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_START2;
	pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_IDLE2;
	pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_START2;
	pDataParams2->eSlotMrkState2 = PHPAL_I14443P3B_EXCHANGE_SEND2;
	pDataParams2->eHaltBState2 = PHPAL_I14443P3B_EXCHANGE_SEND2;
    pDataParams2->eSetBaudRateExState2 = PHPAL_I14443P3B_SETBAUDRATEEX_START2;
    pDataParams2->eCheckATQBExState2 = 0U;
	/* init private data */
	pDataParams2->wId2 = PH_COMP_PAL_ISO14443P3B2 | PHPAL_I14443P3B_SW_ID2;
	pDataParams2->pHalDataParams2 = pHalDataParams2;
	pDataParams2->bExtAtqb2 = PH_OFF2;
	pDataParams2->bPupiValid2 = PH_OFF2;
	pDataParams2->bCidSupported2 = 0;
	pDataParams2->bNadSupported2 = 0;
	pDataParams2->bCid2 = 0;
	pDataParams2->bFwi2 = PHPAL_I14443P3B_SW_FWI_DEFAULT2;
	pDataParams2->bFsci2 = PHPAL_I14443P3B_SW_FSCI_DEFAULT2;
	pDataParams2->bFsdi2 = 0;
	pDataParams2->bDri2 = 0;
	pDataParams2->bDsi2 = 0;
	pDataParams2->bAttribParam12 = PHPAL_I14443P3B_SW_ATTRIB_PARAM1_DEFAULT2;
	pDataParams2->pHigherLayerInf2 = NULL;
	pDataParams2->wTxWait2 = PHPAL_I14443P3B_SW_TXWAIT_US_DEFAULT2;
	pDataParams2->wHigherLayerInfLen2 = 0;
	pDataParams2->pHigherLayerResp2 = NULL;
	pDataParams2->wHigherLayerRespSize2 = 0;
	pDataParams2->wHigherLayerRespLen2 = 0;
	pDataParams2->bOpeMode2 = RD_LIB_MODE_NFC2;
	pDataParams2->bPollCmd2 = PHPAL_I14443P3B_USE_REQB2;
	pDataParams2->bRetryCount2 = PHPAL_I14443P3B_ATTRIB_RETRY_MAX2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetConfig2(
                                       P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       VAR(uint16, ANFCRL_VAR) wConfig2,
                                       VAR(uint16, ANFCRL_VAR) wValue2
                                       )
{
	switch (wConfig2)
	{
		case PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM12:
			pDataParams2->bAttribParam12 = (uint8) wValue2;
			break;

			/* Emvco: To Define Running Mode for RdLib: Either Normal, EMVCO, ISO */
		case PHPAL_I14443P3B_CONFIG_OPE_MODE2:
		{
			pDataParams2->bOpeMode2 = (uint8) wValue2;
			break;
		}

		case PHPAL_I14443P3B_CONFIG_POLL_CMD2:
		{
			pDataParams2->bPollCmd2 = (uint8) wValue2;
			break;
		}

		case PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT2:
		{
			if (!(((wValue2 & 0xFFU) == PHPAL_I14443P3B_ATTRIB_RETRY_MIN2) || ((wValue2 & 0xFFU) == PHPAL_I14443P3B_ATTRIB_RETRY_MAX2)))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
			}

			pDataParams2->bRetryCount2 = (uint8) wValue2;
			break;
		}
		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetConfig2(
                                       P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       VAR(uint16, ANFCRL_VAR) wConfig2,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                       )
{
	switch (wConfig2)
	{
		case PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM12:
			*pValue2 = pDataParams2->bAttribParam12;
			break;

		case PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT2:
			*pValue2 = pDataParams2->bRetryCount2;
			break;

		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetSerialNo2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2
    )
{
	/* Return an error if PUPI is not valid */
	if (pDataParams2->bPupiValid2 == PH_OFF2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_ISO14443P3B2);
	}

	/* Copy PUPI */
	phTools_memcpy2(pPupi2, pDataParams2->pPupi2, (uint32) (sizeof(pDataParams2->pPupi2)));

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetHigherLayerInf2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
    VAR(uint16, ANFCRL_VAR) wTxLength2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxBufSize2
    )
{
	pDataParams2->pHigherLayerInf2 = pTxBuffer2;
	pDataParams2->wHigherLayerInfLen2 = wTxLength2;
	pDataParams2->pHigherLayerResp2 = pRxBuffer2;
	pDataParams2->wHigherLayerRespSize2 = wRxBufSize2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetHigherLayerResp2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
    )
{
	*pRxBuffer2 = pDataParams2->pHigherLayerResp2;
	*pRxLength2 = pDataParams2->wHigherLayerRespLen2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetProtocolParams2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci2
    )
{
	*pCidEnabled2 = pDataParams2->bCidSupported2;
	*pCid2 = pDataParams2->bCid2;
	*pNadSupported2 = pDataParams2->bNadSupported2;
	*pFwi2 = pDataParams2->bFwi2;
	*pFsdi2 = pDataParams2->bFsdi2;
	*pFsci2 = pDataParams2->bFsci2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_CheckATQBEx2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp2,
    VAR(uint16, ANFCRL_VAR) wRespLength2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
    )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTR22 = 0U;

	switch (pDataParams2->eCheckATQBExState2)
	{
		case 0U:
			/* Response check */
			/* Digital Protocol Requirement 49, Section 5.6.1.5 */
			if ((wRespLength2 != 12U) && (wRespLength2 != 13U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
			}

			/* The ATQB should look like the following (see ISO14443-3 7.9.1): */
			/* [0x50][PUPI0][PUPI1][PUPI2][PUPI3][PInfo0][PInfo1][PInfo2]([PInfo3])[CRC][CRC] */

			if (pResp2[0] != 0x50U) /* ATQB byte */
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
			}

			/* Copy received AtqB */
			phTools_memcpy2(pAtqb2, pResp2, wRespLength2);
			*pAtqbLen2 = (uint8) wRespLength2;

			if (pDataParams2->bOpeMode2 != RD_LIB_MODE_NFC2)
			{
				/* Max allowed frame size integer for ISO and EMVCo(v3.0) mode is less than or equals to 0x0C (4096 bytes) */
				if ((uint8) (pAtqb2[10] & 0xF0U) > 0xC0U)
				{
					pAtqb2[10] = (pAtqb2[10] & 0x0FU) | 0xC0U;
				}
			}
			else
			{
				/* Max allowed frame size integer for NFC(DP 1.1, Requirements 64) mode is less than or equals to 0x08 (256 bytes) */
				if ((uint8) (pAtqb2[10] & 0xF0U) > 0x80U)
				{
					pAtqb2[10] = (pAtqb2[10] & 0x0FU) | 0x80U;
				}
			}

			if (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
			{
				/* Check TR2 value received in Atqb and set relevant TxWait as per ISO-IEC 14443-3. */
				bTR22 = (uint8) ((pAtqb2[10] & PHPAL_I14443P3B_SW_MINIMUM_TR2_MASK2) >> PHPAL_I14443P3B_SW_MINIMUM_TR2_POS2);
				switch (bTR22)
				{
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_02:
						pDataParams2->wTxWait2 = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_02;
						break;
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_12:
						pDataParams2->wTxWait2 = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_12;
						break;
					case PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_22:
						pDataParams2->wTxWait2 = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_22;
						break;
					default:
						pDataParams2->wTxWait2 = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_32;
						break;
				}
				pDataParams2->eCheckATQBExState2 = 1U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* If the TR2 value is (11)b then the default TxWait of 500us (6780/fc) has to changed to 699us (9472/fc). */
				if ((uint8) ((pAtqb2[10] & PHPAL_I14443P3B_SW_MINIMUM_TR2_MASK2) >> PHPAL_I14443P3B_SW_MINIMUM_TR2_POS2) == PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_32)
				{
					pDataParams2->wTxWait2 = (uint16) PHPAL_I14443P3B_SW_TXWAIT_US_TR2_32;
					pDataParams2->eCheckATQBExState2 = 2U;
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					pDataParams2->wTxWait2 = PHPAL_I14443P3B_SW_TXWAIT_US_DEFAULT2;
				}
			}
			break;
		case 1U:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, pDataParams2->wTxWait2));
			break;
		case 2U:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, PHPAL_I14443P3B_SW_TXWAIT_US_TR2_32));
			break;
		default:
			statusTmp2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}

	/* and also copy the PUPI into the protocol params structure to be available
	 for a possible following HaltB command */
	phTools_memcpy2(pDataParams2->pPupi2, &pAtqb2[1], (uint32) (sizeof(pDataParams2->pPupi2)));
	pDataParams2->bPupiValid2 = PH_ON2;
	pDataParams2->eCheckATQBExState2 = 0u;

	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetReaderBaudRateEx2( P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxDataRate2 = 0;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxDataRate2 = 0;

    switch (pDataParams2->eSetBaudRateExState2)
    {
        case PHPAL_I14443P3B_SETBAUDRATEEX_START2:
            /* Check and convert Dri value */
            switch (pDataParams2->bDri2)
            {
                case PHPAL_I14443P3B_DATARATE_1062:
                    wTxDataRate2 = PHHAL_HW_RF_DATARATE_1062;
                    break;
                case PHPAL_I14443P3B_DATARATE_2122:
                    wTxDataRate2 = PHHAL_HW_RF_DATARATE_2122;
                    break;
                case PHPAL_I14443P3B_DATARATE_4242:
                    wTxDataRate2 = PHHAL_HW_RF_DATARATE_4242;
                    break;
                case PHPAL_I14443P3B_DATARATE_8482:
                    wTxDataRate2 = PHHAL_HW_RF_DATARATE_8482;
                    break;
                default:
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
            }

            /* Check and convert Dsi value */
            switch (pDataParams2->bDsi2)
            {
                case PHPAL_I14443P3B_DATARATE_1062:
                    wRxDataRate2 = PHHAL_HW_RF_DATARATE_1062;
                    break;
                case PHPAL_I14443P3B_DATARATE_2122:
                    wRxDataRate2 = PHHAL_HW_RF_DATARATE_2122;
                    break;
                case PHPAL_I14443P3B_DATARATE_4242:
                    wRxDataRate2 = PHHAL_HW_RF_DATARATE_4242;
                    break;
                case PHPAL_I14443P3B_DATARATE_8482:
                    wRxDataRate2 = PHHAL_HW_RF_DATARATE_8482;
                    break;
                default:
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
            }
            pDataParams2->eSetBaudRateExState2 = PHPAL_I14443P3B_SETBAUDRATEEX_TX2;
            /* no break */

        case PHPAL_I14443P3B_SETBAUDRATEEX_TX2:
            /* Apply new data rates to Pcd */
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
                    pDataParams2->pHalDataParams2,
                    PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,
                    wTxDataRate2));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            pDataParams2->eSetBaudRateExState2 = PHPAL_I14443P3B_SETBAUDRATEEX_RX2;
            /* no break */

        case PHPAL_I14443P3B_SETBAUDRATEEX_RX2:
            /* Apply new data rates to Pcd */
            PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
                    pDataParams2->pHalDataParams2,
                    PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,
                    wRxDataRate2));
            PH_BREAK_ON_FAILURE2(statusTmp2);
            break;
    }

    pDataParams2->eSetBaudRateExState2 = PHPAL_I14443P3B_SETBAUDRATEEX_START2;
    return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_DecideBaudRateEx2( VAR(uint8, ANFCRL_VAR) bBitRateCapability2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDri2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDsi2 )
{
  VAR(uint8, ANFCRL_VAR) bMaxSymBitRate2 = 0;

	/* Use the given values for Dri and Dsi, if the caller wants so, or
	 calculate Dsi and Dri depending on the given parameters and what the PICC is supporting,
	 assuming that the reader supports all data rates in both directions. */

	/* Check if only symmetric bit rates are supported, check also if b4 is set.
	 If the caller forces one of the data rates, it is not possible to make a decision */

	if ((0U == ((*pbDsi2 & PHPAL_I14443P3B_DATARATE_FORCE2))) && (0U == ((*pbDri2 & PHPAL_I14443P3B_DATARATE_FORCE2))))
	{
		/* ISO/IEC14443-3 p41: If b4=(1)b should interpret the Bit_Rate_Capability byte as if 0x00 */
		if (0U != (bBitRateCapability2 & 0x08U))
		{
			*pbDsi2 = 0;
			*pbDri2 = 0;
			return PH_ERR_SUCCESS2;
		}

		/* Symmetric baud rates */
		if ((0U != ((bBitRateCapability2 & 0x80U))) && (*pbDsi2 != *pbDri2))
		{
			/* Start with the lower one of these both */
			if (*pbDsi2 > *pbDri2)
			{
				bMaxSymBitRate2 = *pbDri2;
			}
			else
			{
				bMaxSymBitRate2 = *pbDsi2;
			}

			/* Start with the desired bit rate and break, as soon as a supported one is found. */
			switch (bMaxSymBitRate2)
			{
			case PHPAL_I14443P3B_DATARATE_8482:
				if (0x44U == (bBitRateCapability2 & 0x44U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_4242:
				bMaxSymBitRate2 = PHPAL_I14443P3B_DATARATE_4242;
				if (0x22U == (bBitRateCapability2 & 0x22U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_2122:
				bMaxSymBitRate2 = PHPAL_I14443P3B_DATARATE_2122;
				if (0x11U == (bBitRateCapability2 & 0x11U))
				{
					break;
				}
				/* no break */
			case PHPAL_I14443P3B_DATARATE_1062: /* is supported anyway */
				bMaxSymBitRate2 = PHPAL_I14443P3B_DATARATE_1062;
				break;
			default:
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
			}

			*pbDri2 = bMaxSymBitRate2;
			*pbDsi2 = *pbDri2;
			return PH_ERR_SUCCESS2;
		}
	}

	if (0U != (*pbDsi2 & PHPAL_I14443P3B_DATARATE_FORCE2))
	{
		*pbDsi2 = *pbDsi2 & 0x0FU;
	}
	else
	{
		/* Start with the desired bit rate and break, as soon as a supported one is found. */
		switch (*pbDsi2)
		{
		case PHPAL_I14443P3B_DATARATE_8482:
			if (0U != (bBitRateCapability2 & 0x40U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_4242:
			*pbDsi2 = PHPAL_I14443P3B_DATARATE_4242;
			if (0U != (bBitRateCapability2 & 0x20U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_2122:
			*pbDsi2 = PHPAL_I14443P3B_DATARATE_2122;
			if (0U != (bBitRateCapability2 & 0x10U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_1062: /* is supported anyway */
			*pbDsi2 = PHPAL_I14443P3B_DATARATE_1062;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
		}
	}
	if (0U != (*pbDri2 & PHPAL_I14443P3B_DATARATE_FORCE2))
	{
		*pbDri2 = *pbDri2 & 0x0FU;
	}
	else
	{
		/* Start with the desired bit rate and break, as soon as a supported one is found. */
		switch (*pbDri2)
		{
		case PHPAL_I14443P3B_DATARATE_8482:
			if (0U != (bBitRateCapability2 & 0x04U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_4242:
			*pbDri2 = PHPAL_I14443P3B_DATARATE_4242;
			if (0U != (bBitRateCapability2 & 0x02U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_2122:
			*pbDri2 = PHPAL_I14443P3B_DATARATE_2122;
			if (0U != (bBitRateCapability2 & 0x01U))
			{
				break;
			}
			/* no break */
		case PHPAL_I14443P3B_DATARATE_1062: /* is supported anyway */
			*pbDri2 = PHPAL_I14443P3B_DATARATE_1062;
			break;
		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
		}
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetSerialNo2(P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2)
{
	phTools_memcpy2(pDataParams2->pPupi2, pPupi2, (uint32) (sizeof(pDataParams2->pPupi2)));
	pDataParams2->bPupiValid2 = PH_ON2;

	return PH_ERR_SUCCESS2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_RequestB2(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      VAR(uint8, ANFCRL_VAR) bNumSlots2,
                                      VAR(uint8, ANFCRL_VAR) bAfi2,
                                      VAR(uint8, ANFCRL_VAR) bExtAtqb2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                      )
{
	return phpalI14443p3b_Sw_RequestBEx2(pDataParams2, 0, bNumSlots2, bAfi2, bExtAtqb2, pAtqb2, pAtqbLen2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_WakeUpB2(
                                     P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint8, ANFCRL_VAR) bNumSlots2,
                                     VAR(uint8, ANFCRL_VAR) bAfi2,
                                     VAR(uint8, ANFCRL_VAR) bExtAtqb2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                     )
{
	return phpalI14443p3b_Sw_RequestBEx2(pDataParams2, 1, bNumSlots2, bAfi2, bExtAtqb2, pAtqb2, pAtqbLen2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SlotMarker2(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bSlotNumber2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                        )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[1] =
	{ 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0;

	switch (pDataParams2->eSlotMrkState2)
	{
	case PHPAL_I14443P3B_EXCHANGE_SEND2:
		/* Parameter check */
		if ((bSlotNumber2 < 2U) || (bSlotNumber2 > 16U))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
		}

		/* Note: No need to set time out and RxDeafTime since this is done in RequestB,
		 which must be the previous command. */

		/* SlotNumber 2-16 */
		/* Build the command */
		aCmd2[0] = (uint8) (((uint8) (bSlotNumber2 - 1U) & 0x0FU) << 4U) | 0x05U;
		I14443P3_LOG2(">>> P3B_SLOTMAKER_SEND SlotIndex:%d  *** \r\n", bSlotNumber2);
		pDataParams2->eSlotMrkState2 = PHPAL_I14443P3B_EXCHANGE_WAITRSP2;
		/* no break */
	case PHPAL_I14443P3B_EXCHANGE_WAITRSP2:
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 1, &pResp2, &wRespLength2));
		I14443P3_LOG2("<<< P3B_SLOTMAKER_WAITRSP Status: %0X \r\n", status2);
		PH_BREAK_ON_FAILURE2(status2);
		status2 = phpalI14443p3b_Sw_CheckATQBEx2(pDataParams2, pResp2, wRespLength2, pAtqb2, pAtqbLen2);
	}
	pDataParams2->eSlotMrkState2 = PHPAL_I14443P3B_EXCHANGE_SEND2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_HaltB2(
                                   P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                   )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[5] =
	{ 0 };
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0;

	switch (pDataParams2->eHaltBState2)
	{
	case PHPAL_I14443P3B_EXCHANGE_SEND2:
        PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, PHPAL_I14443P3B_SW_ATTRIB_TIME_US2 + PHPAL_I14443P3B_SW_EXT_TIME_US2));
        PH_BREAK_ON_FAILURE2(status2);
        I14443P3_LOG2(">>> P3B_HALTB_SEND  \r\n");

        /* Build the command */
        aCmd2[0] = PHPAL_I14443P3B_SW_HALT_CMD2;
        (void) phTools_memcpy2(&aCmd2[1], pDataParams2->pPupi2, (uint32) (sizeof(pDataParams2->pPupi2)));

        pDataParams2->eHaltBState2 = PHPAL_I14443P3B_EXCHANGE_WAITRSP2;
		/* no break */
	case PHPAL_I14443P3B_EXCHANGE_WAITRSP2:
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 5, &pResp2, &wRespLength2));

		I14443P3_LOG2("<<< P3B_HALTB_WAITRSP Status: %0X \r\n", status2);
		PH_BREAK_ON_FAILURE2(status2);

		/* Response check */
		if ((wRespLength2 != 1U) || (pResp2[0] != PHPAL_I14443P3B_SW_HALT_RESP2))
		{
			status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
			break;
		}
		/* PUPI is invalid */
		pDataParams2->bPupiValid2 = PH_OFF2;
	}
	pDataParams2->eHaltBState2 = PHPAL_I14443P3B_EXCHANGE_SEND2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Attrib2(
                                    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                    VAR(uint8, ANFCRL_VAR) bAtqbLen2,
                                    VAR(uint8, ANFCRL_VAR) bFsdi2,
                                    VAR(uint8, ANFCRL_VAR) bCid2,
                                    VAR(uint8, ANFCRL_VAR) bDri2,
                                    VAR(uint8, ANFCRL_VAR) bDsi2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2
                                    )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[9];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTemp2 = 0U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwSfgt2 = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwFwt2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSetBaudRateFlag2 = 0U;

	switch (pDataParams2->eAttribState2)
	{
        case PHPAL_I14443P3B_ATTRIB_START2:
            bSetBaudRateFlag2 = 0U;
            /* parameter check */
            /* ATQB length */
            if ((bAtqbLen2 != 12U) && (bAtqbLen2 != 13U))
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
            }

            /* check given DSI, DRI, FSDI */
            if ((bFsdi2 > PHPAL_I14443P3B_FRAMESIZE_MAX2) || (bDri2 > 0x03U) || (bDsi2 > 0x03U))
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
            }

            /* build the command frame */
            aCmd2[0] = PHPAL_I14443P3B_SW_ATTRIB_CMD2;

            /* copy PUPI to command frame */
            phTools_memcpy2(&aCmd2[1], &pAtqb2[1], 4);

            /* Param1: TR0, TR1, SOF/EOF suppression */
            aCmd2[5] = pDataParams2->bAttribParam12;

            (void)phpalI14443p3b_Sw_DecideBaudRateEx2(pAtqb2[9], &bDri2, &bDsi2);
            /* Param2: Dsi, Dri, FSDI */
            aCmd2[6] = (bDsi2 << 6U) | (bDri2 << 4U) | bFsdi2;

            /* Param3: confirmation of protocol info byte 2 (protocol type and minimum TR2) */
            aCmd2[7] = pAtqb2[10] & 0x07U;

            /* Param4: Cid */
            /* check if supported by PICC, check given value for < 0x0F */
            if (0U != (pAtqb2[11] & 0x01U))
            {
                if (bCid2 > 0x0EU)
                {
                    return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
                }
            }
            else
            {
                bCid2 = 0x00;
            }
            aCmd2[8] = bCid2;

            /* Calculate FWT timeout */
            /* get the Fwt, because we need it for the timeout. */
            pDataParams2->bFwi2 = (uint8) (pAtqb2[11] >> 4U);
            if (pDataParams2->bFwi2 == 0x0FU)
            {
                pDataParams2->bFwi2 = PHPAL_I14443P3B_SW_FWI_DEFAULT2;
            }

            /* Calculate FWT timeout */
            dwFwt2 = (PHPAL_I14443P3B_SW_FWT_MIN_US2 * ((uint32) 1U << pDataParams2->bFwi2));
            if (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
            {
                /* Add extension time */
                dwFwt2 += PHPAL_I14443P3B_SW_EXT_TIME_US2;
            }
            else
            {
                /* As per Digital Spec V1.1 req 7.9.1.3, NFC Forum Device SHALL wait at least FWT + delta FWTB for a Response */
                dwFwt2 += PHPAL_I14443P3B_SW_DELTA_FWT_US2;
                if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
                {
                    /* As per EMVCo, add delta Tpcd time along with delta FWT time */
                    dwFwt2 += PHPAL_I14443P3B_SW_DELTA_TPCD_US2;
                }
            }

            /* Set Attrib timeout */
            /* ISO IEC 14443-3, 7.9.4.3 FWI:
             In case of extended ATQB ...
             ... FWT applies after the Answer to ATTRIB and
             ... the waiting time for the Answer to ATTRIB is fixed to ~4,8 ms */

            if (bAtqbLen2 == 13U)
            {
                pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT2;
            }
            else
            {
                I14443P3_LOG2("*** SET FWT dwFwt2:%d \r\n", dwFwt2);
                /* Set FWT timeout */
                if (dwFwt2 > 0xFFFFU)
                {
                    /* +1 is added to the timeout in millisecond to compensate the
                     * fractional microseconds lost in division by 1000 */
                    pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS2;
                }
                else
                {
                    pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US2;
                }
            }
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
                                                           PHPAL_I14443P3B_SW_ATTRIB_TIME_US2 + PHPAL_I14443P3B_SW_EXT_TIME_US2));
            PH_BREAK_ON_FAILURE2(status2);
            bTemp2 = pDataParams2->bRetryCount2 + 1u;
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, (uint16)((dwFwt2 / 1000U) + 1U)));
            PH_BREAK_ON_FAILURE2(status2);
            bTemp2 = pDataParams2->bRetryCount2 + 1u;
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, (uint16)dwFwt2));
            PH_BREAK_ON_FAILURE2(status2);
            bTemp2 = pDataParams2->bRetryCount2 + 1u;
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2:
            /* Exchange command */
            wRespLength2 = 0;
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2( pDataParams2->pHalDataParams2, PH_EXCHANGE_BUFFER_FIRST2, aCmd2, 9, &pResp2, &wRespLength2));
            PH_BREAK_ON_FAILURE2(status2);
            I14443P3_LOG_BUF2(">>> P3B_ATTRIB_SEND:", aCmd2, 9U);
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST2;
            return PH_STATUS_INPROCESS2;

        case PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST2:
            if(0U == bSetBaudRateFlag2)
            {
                /* the remaining part of the ATTRIB command frame holds the Higher Layer INF */
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_BUFFER_LAST2, pDataParams2->pHigherLayerInf2, pDataParams2->wHigherLayerInfLen2, &pResp2, &wRespLength2));

#ifdef NXPBUILD__PH_LOG_EX2
                if (status2 == PH_ERR_SUCCESS2)
                {
                    I14443P3_LOG_BUF2("<<< P3B_ATTRIB_WAITRSP:", pResp2, (uint8 )wRespLength2);
                }
                else
                {
                    I14443P3_LOG2("<<< P3B_ATTRIB_WAITRSP: %0X \r\n", status2);
                }
#endif
                bTemp2--;
                /* check and perform re-transmission of ATTRIB in case of Transmission or Timeout error
                 * Nfc Digital Specification ver 1.1, Req 14.7.1.1
                 */
                if ((bTemp2 > 0U) && (PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2)))
                {
                    pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2;
                    return PH_STATUS_INPROCESS2;
                }

                PH_BREAK_ON_FAILURE2(status2);

                /* we hopefully received at least one byte */
                if (wRespLength2 < 1U)
                {
                    status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
                    break;
                }

                /* we receive MBLI and CID in the first byte: */
                /* check the received cid: */
                if (((pAtqb2[11] & 0x01U) != 0U) && ((pResp2[0] & 0x0FU) != bCid2))
                {
                    status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
                    break;
                }

                /* If the CID is not supported, PICC SHALL set the CID to 0 */
                /* PCD SHALL treat a CID field with a different value as Protocol Error */
                /* Digital Protocol 1.1, Requirements 166 and EMVCo 2.6, Requirements 6.24, 6.4.1.10 */
                if ((pDataParams2->bOpeMode2 != RD_LIB_MODE_ISO2)
                        && (((pAtqb2[11] & 0x01U) == 0U) && ((pResp2[0] & 0x0FU) != 0x0U)))
                {
                    status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
                    break;
                }

                /* Note: ISO14443-3 7.11: The MBLI (maximum buffer size) gives information about
                 the PICCs internal buffer */
                *pMbli2 = (uint8) (pResp2[0] >> 4U);

                if (1U < wRespLength2)
                {
                    /* we received some Higher Layer INF bytes:
                     ISO14443-3 TypeB, 7.11 Higher Response (optional 0 or "more" bytes) --> see page 46. */
                    pDataParams2->wHigherLayerRespLen2 = wRespLength2 - 1u;

                    /* should we have received it? */
                    if (pDataParams2->wHigherLayerInfLen2 == 0U)
                    {
                        pDataParams2->wHigherLayerRespLen2 = 0;
                        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P3B2);
                        break;
                    }

                    if (pDataParams2->wHigherLayerRespLen2 > pDataParams2->wHigherLayerRespSize2)
                    {
                        pDataParams2->wHigherLayerRespLen2 = 0;
                        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_PAL_ISO14443P3B2);
                        break;
                    }
                    (void) phTools_memcpy2(pDataParams2->pHigherLayerResp2, &pResp2[1], pDataParams2->wHigherLayerRespLen2);
                }

                /* Now, that the PICC accepted our protocol settings, we can store them in the structure */
                pDataParams2->bCidSupported2 = pAtqb2[11] & 0x01U;
                pDataParams2->bNadSupported2 = (pAtqb2[11] & 0x02U) >> 1U;
                pDataParams2->bCid2 = pResp2[0] & 0x0FU;
                pDataParams2->bFsci2 = (uint8) (pAtqb2[10] >> 4U);
                pDataParams2->bFsdi2 = bFsdi2;
                pDataParams2->bDri2 = bDri2;
                pDataParams2->bDsi2 = bDsi2;

                bTemp2 = 0;
                /* If we had an extended ATQB, the timeout was set for the reception
                 of the ATTRIB command (see line 280). */
                if (bAtqbLen2 == 13U)
                {
                    /* Set FWT timeout */
                    if (dwFwt2 > 0xFFFFU)
                    {
                        pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS2;
                        return PH_STATUS_INPROCESS2;
                    }
                    else
                    {
                        pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US2;
                        return PH_STATUS_INPROCESS2;
                    }
                }
                bSetBaudRateFlag2 = 1U;
            }
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, (uint16)(dwFwt2 / 1000U)));
            PH_BREAK_ON_FAILURE2(status2);
            bSetBaudRateFlag2 = 1U;
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US2:
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, (uint16)dwFwt2));
            PH_BREAK_ON_FAILURE2(status2);
            bSetBaudRateFlag2 = 1U;
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS2:
            if(1U == bSetBaudRateFlag2)
            {
                /* Set baud rate on Pcd */
                PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_Sw_SetReaderBaudRateEx2(pDataParams2));
                bSetBaudRateFlag2 = 0U;
                PH_BREAK_ON_FAILURE2(status2);
            }
            pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US2;
            return PH_STATUS_INPROCESS2;
        case PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US2:
            /* Applying Tx Wait saved according to the TR value of ATQb as setreaderbaudrateEx restores default */
            PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, pDataParams2->wTxWait2));
            PH_BREAK_ON_FAILURE2(status2);

            /* If we have had received an extended ATQB with an SFGT (startup frame guard time)
             we need to wait this time here. */
            if (bAtqbLen2 == 13U)
            {
                /* fetch sfgi value from response */
                bTemp2 = (uint8) (pAtqb2[12] >> 4U);

                if (bTemp2 == 0x0FU)
                {
                    bTemp2 = PHPAL_I14443P3B_SW_SFGI_DEFAULT2;
                }

                pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_GUARDTIME2;
                return PH_STATUS_INPROCESS2;
            }
            break;
        case PHPAL_I14443P3B_ATTRIB_GUARDTIME2:
            /* Calculate SFGT in Microseconds */
            dwSfgt2 = (PHPAL_I14443P3B_SW_FWT_MIN_US2 * ((uint32) 1U << bTemp2)) + PHPAL_I14443P3B_SW_EXT_TIME_US2;
            /* Perform SFGT Wait */
            if (dwSfgt2 > 0xFFFFU)
            {
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pDataParams2->pHalDataParams2, PHHAL_HW_TIME_MILLISECONDS2, (uint16 )(dwSfgt2 / 1000U)));
            }
            else
            {
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pDataParams2->pHalDataParams2, PHHAL_HW_TIME_MICROSECONDS2, (uint16 )dwSfgt2));
            }
        }
        bSetBaudRateFlag2 = 0U;
        pDataParams2->eAttribState2 = PHPAL_I14443P3B_ATTRIB_START2;
        return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_ActivateCard2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2,
    VAR(uint8, ANFCRL_VAR) bPupiLength2,
    VAR(uint8, ANFCRL_VAR) bNumSlotIndex2,
    VAR(uint8, ANFCRL_VAR) bAfi2,
    VAR(uint8, ANFCRL_VAR) bExtAtqb2,
    VAR(uint8, ANFCRL_VAR) bFsdi2,
    VAR(uint8, ANFCRL_VAR) bCid2,
    VAR(uint8, ANFCRL_VAR) bDri2,
    VAR(uint8, ANFCRL_VAR) bDsi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
    )
{
  static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusFirstError2 = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSlot2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNumSlots2 = 0;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bPICCsFound2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 pLocalAtqb2[13];
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bLocalAtqbLen2;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pLocalPupi2 = NULL;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBreakfromloop2;

	switch (pDataParams2->eActCardState2)
	{
	case PHPAL_I14443P3B_ACTCARD_START2:
		bPICCsFound2 = 0u;
		bLocalAtqbLen2 = 0x00u;
		pLocalPupi2 = &pLocalAtqb2[1];
		*pMoreCardsAvailable2 = 0x00u;
		bBreakfromloop2 = 0u;
		bNumSlots2 = 0u;

		/* initialize the statusFirstError2 with timeout, which is the trigger */
		statusFirstError2 = PH_ERR_IO_TIMEOUT2;

		/* Parameter check */
		/* number of slots and length of PUPI */
		if ((bNumSlotIndex2 > 4U) || ((bPupiLength2 > 0U) && (bPupiLength2 != 4U) && (pDataParams2->bPollCmd2 != PHPAL_I14443P3B_USE_WUPB2)))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
		}

		/* check given DSI, DRI, FSDI */
		if ((bFsdi2 > PHPAL_I14443P3B_FRAMESIZE_MAX2) || ((bDri2 & ~PHPAL_I14443P3B_DATARATE_FORCE2) > 3U) || ((bDsi2 & ~PHPAL_I14443P3B_DATARATE_FORCE2) > 3U))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
		}

		/* Cid */
		if (bCid2 > 14U)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
		}

		pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_REQB_WKUPB2;
		/* no break */
	case PHPAL_I14443P3B_ACTCARD_REQB_WKUPB2:
		/* Do Anti-collision loop */

		if (bPupiLength2 != 0U)
		{
			status2 = phpalI14443p3b_WakeUpB2(pDataParams2, bNumSlotIndex2, bAfi2, bExtAtqb2, pLocalAtqb2, &bLocalAtqbLen2);
		}
		else
		{
			status2 = phpalI14443p3b_RequestB2(pDataParams2, bNumSlotIndex2, bAfi2, bExtAtqb2, pLocalAtqb2, &bLocalAtqbLen2);
		}
		if (status2 == PH_STATUS_INPROCESS2)
		{
			return PH_STATUS_INPROCESS2;
		}

		/* SlotMarkers */
		/* If the bNumSlots2 == 0U, we do not send any SlotMarker commands (the following for loop). */
		if (bNumSlotIndex2 != 0U)
		{
			/* calculate the number of slots reusing bNumSlots2 */
			bNumSlots2 = (uint8) (1U << bNumSlotIndex2);
		}
		bSlot2 = 2U;
		pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_SLOTMAKER2;
		return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_ACTCARD_SLOTMAKER2:
		if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
		{
			/* if the caller provided a PUPI, we try to find and activate only the according PICC */
			if (bPupiLength2 != 0U)
			{
				/* compare PUPIs */
				if (memcmp(pPupi2, pLocalPupi2, 4U) == 0)
				{
					++bPICCsFound2;
					bBreakfromloop2 = 1U;
				}
			}
			/* no PUPI provided by caller */
			else
			{
				++bPICCsFound2;
				bBreakfromloop2 = 1U;
			}
		}
		/* Integrity Error means collision */
		else
		{
			if ((status2 & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2)
			{
				*pMoreCardsAvailable2 = 0x01;
			}
		}

		/* Update first error */
		if ((statusFirstError2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
		{
			statusFirstError2 = status2;
		}
		if (bSlot2 > bNumSlots2)
		{
			bBreakfromloop2 = 1U;
		}
		if (bBreakfromloop2 == 1U)
		{
			/* check if we found no PICC */
			if (0U == (bPICCsFound2))
			{
				status2 = PH_ADD_COMPCODE_FIXED2(statusFirstError2, PH_COMP_HAL2);
				break;
			}
			if (bLocalAtqbLen2 != 0U)
			{
				(void) phTools_memcpy2(pAtqb2, pLocalAtqb2, bLocalAtqbLen2);
			}
			*pAtqbLen2 = bLocalAtqbLen2;
			I14443P3_LOG_BUF2("*** ATQB:", pAtqb2, bLocalAtqbLen2);
			/* Find the baud rates which shall be used. pAtqb2[9] holds the VICCs bit rate capabilities. */
			PH_CHECK_FAILURE_FCT2(status2, phpalI14443p3b_Sw_DecideBaudRateEx2(pAtqb2[9], &bDri2, &bDsi2));
			pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_ATTRIBUTE2;
			return PH_STATUS_INPROCESS2;
		}
		pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP2;
		return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP2:
		PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_SlotMarker2(pDataParams2, bSlot2, pLocalAtqb2, &bLocalAtqbLen2));

		pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_SLOTMAKER2;
		bSlot2++;
		return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_ACTCARD_ATTRIBUTE2:
		/* AttribB: activate the first PICC found */
		PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_Attrib2(pDataParams2, pAtqb2, *pAtqbLen2, bFsdi2, bCid2, bDri2, bDsi2, pMbli2));

		if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
		{
			/* PUPI is invalid */
			pDataParams2->bPupiValid2 = PH_OFF2;
		}
	}
	pDataParams2->eActCardState2 = PHPAL_I14443P3B_ACTCARD_START2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Exchange2(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      VAR(uint16, ANFCRL_VAR) wOption2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                      VAR(uint16, ANFCRL_VAR) wTxLength2,
                                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                      )
{
	/* direct mapping of hal exchange function */
	return phhalHw_Exchange2(pDataParams2->pHalDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_RequestBEx2(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bIsWakeUp2,
                                        VAR(uint8, ANFCRL_VAR) bNumSlots2,
                                        VAR(uint8, ANFCRL_VAR) bAfi2,
                                        VAR(uint8, ANFCRL_VAR) bExtAtqb2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                        )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[3];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0;

	switch (pDataParams2->eReqBExState2)
	{
	case PHPAL_I14443P3B_REQUESTBEX_IDLE2:
		/* parameter check */
		if (bNumSlots2 > 4U)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P3B2);
		}

		/* AFi|isWakeUp|NumSlots|extAtqB */
		/* Build the command */
		aCmd2[0] = PHPAL_I14443P3B_SW_APF2;
		aCmd2[1] = bAfi2;
		aCmd2[2] = bNumSlots2; /* N = 2^bNumSlots2*/

		/* Set wakeup bit if necessary */
		if (0U != (bIsWakeUp2))
		{
			aCmd2[2] |= PHPAL_I14443P3B_SW_PARAM_WUP_BIT2;
		}

		/* Enable Extended ATQB if necessary */
		if (bExtAtqb2 != PH_OFF2)
		{
			aCmd2[2] |= PHPAL_I14443P3B_SW_PARAM_EXTATQB_BIT2;
		}

		/* Store usage of Extended ATQB */
		pDataParams2->bExtAtqb2 = bExtAtqb2;

		/* PUPI is invalid */
		pDataParams2->bPupiValid2 = PH_OFF2;
#ifdef NXPBUILD__PH_LOG_EX2
		if (0U == bIsWakeUp2)
		{
			I14443P3_LOG_BUF2(">>> P3B_REQB_SEND:", aCmd2, 3U);
		}
		else
		{
			I14443P3_LOG_BUF2(">>> P3B_WAKEUPB_SEND:", aCmd2, 3U);
		}
#endif
        pDataParams2->eReqBExState2 = PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING2;
        /* no break */
    case PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING2:
        /* Reset default data rates */
        PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
                    PHHAL_HW_CONFIG_TXDATARATE_FRAMING2, PHHAL_HW_RF_DATARATE_1062));
        PH_BREAK_ON_FAILURE2(status2);
        pDataParams2->eReqBExState2 = PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING2;
        /* no break */
    case PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING2:
        PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
                PHHAL_HW_CONFIG_TXDATARATE_FRAMING2, PHHAL_HW_RF_DATARATE_1062));
        PH_BREAK_ON_FAILURE2(status2);
        pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_CONFIG2;
        return PH_STATUS_INPROCESS2;

	case PHPAL_I14443P3B_REQUESTBEX_CONFIG2:
		/* Set RequestB timeout */
		if (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
		{
		    pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US2;
		}
		else
		{
			/* As per Digital Protocol Ver1.1 Article 7.9.1.5
			 * PCD should wait ~17ms (FWT(B,SENSB) + T(B,POLL)) * (566us + 16.4ms = ~17ms)
			 */
            pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS2;
		}
        return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US2:
        /* Set RequestB timeout */
	    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
	                                                             PHPAL_I14443P3B_SW_ATQB_TIME_US2 + PHPAL_I14443P3B_SW_EXT_TIME_US2));
	    PH_BREAK_ON_FAILURE2(status2);
        pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_EXCHANGE2;
        return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS2:
        /* As per Digital Protocol Ver1.1 Article 7.9.1.5
         * PCD should wait ~17ms (FWT(B,SENSB) + T(B,POLL)) * (566us + 16.4ms = ~17ms)
         */
	    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, PHPAL_I14443P3B_SW_DELTA_POLL2));
        PH_BREAK_ON_FAILURE2(status2);
        pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_EXCHANGE2;
        return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P3B_REQUESTBEX_EXCHANGE2:
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 3, &pResp2, &wRespLength2));
		I14443P3_LOG2("<<< P3B_ATQB_WAITRSP Status: %0X \r\n", status2);
		PH_BREAK_ON_FAILURE2(status2);
		I14443P3_LOG_BUF2("<<< P3B_ATQB_RESP:", pResp2, (uint8)wRespLength2);

		status2 = phpalI14443p3b_Sw_CheckATQBEx2(pDataParams2, pResp2, wRespLength2, pAtqb2, pAtqbLen2);
	}
	pDataParams2->eReqBExState2 = PHPAL_I14443P3B_REQUESTBEX_IDLE2;
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#ifdef __cplusplus
}
#endif /*__cplusplus */
