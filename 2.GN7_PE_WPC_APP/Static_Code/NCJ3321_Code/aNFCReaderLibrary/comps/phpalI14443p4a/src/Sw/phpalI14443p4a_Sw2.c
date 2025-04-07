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
*   @file    phpalI14443p4a_Sw2.c
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

#include <ph_Status2.h>
#include <phhalHw2.h>
#include <phpalI14443p3a2.h>
#include <phpalI14443p4a2.h>
#include <ph_RefDefs2.h>
#include <phTools2.h>
#include <phNxpNfcRdLib_Config2.h>
#include <phLog2.h>

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2

#include "phpalI14443p4a_Sw2.h"
#include "phpalI14443p4a_Sw_Int2.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4a_Sw2.c
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

/* Check if current file and phpalI14443p4a_Sw2.h header file are of the same vendor */
#if (PHPALI14443P4A_SW_VENDOR_ID_C != PHPALI14443P4A_SW_VENDOR_ID2)
    #error "phpalI14443p4a_Sw2.c and phpalI14443p4a_Sw2.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4a_Sw2.h header file are of the same Autosar version */
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALI14443P4A_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4A_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalI14443p4a_Sw2.c and phpalI14443p4a_Sw2.h are different"
#endif
/* Check if current file and phpalI14443p4a_Sw2.h header file are of the same Software version */
#if ((PHPALI14443P4A_SW_SW_MAJOR_VERSION_C != PHPALI14443P4A_SW_SW_MAJOR_VERSION2) || \
     (PHPALI14443P4A_SW_SW_MINOR_VERSION_C != PHPALI14443P4A_SW_SW_MINOR_VERSION2) || \
     (PHPALI14443P4A_SW_SW_PATCH_VERSION_C != PHPALI14443P4A_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalI14443p4a_Sw2.c and phpalI14443p4a_Sw2.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
#define I14443P4A_SW_IS_INVALID_BLOCK_STATUS2(bStatus2)                       \
    ((                                                                      \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2) ||                     \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2) ||                \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_FRAMING_ERROR2) ||                  \
    (((bStatus2) & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2))                  \
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

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 bI14443p4a_FsTable2[PHPAL_I14443P4A_FRAMESIZE_MAX2+1] = {14, 22, 30, 38, 46, 62, 94, 126, 254};

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

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_Init2(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                                  )
{
	if (sizeof(phpalI14443p4a_Sw_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_ISO14443P4A2);
	}
	PH_ASSERT_NULL2(pDataParams2);
	PH_ASSERT_NULL2(pHalDataParams2);

	/* reset state variables for Non-Blocking */
	pDataParams2->eActCardState2 = PHPAL_I14443P4A_ACTCARD_IDLE2;
	pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_IDLE2;
	pDataParams2->ePpsState2 = PHPAL_I14443P4A_PPS_IDLE2;

	/* init private data */
	pDataParams2->wId2 = PH_COMP_PAL_ISO14443P4A2 | PHPAL_I14443P4A_SW_ID2;
	pDataParams2->pHalDataParams2 = pHalDataParams2;
	pDataParams2->bCidSupported2 = PH_OFF2;
	pDataParams2->bNadSupported2 = PH_OFF2;
	pDataParams2->bCid2 = 0x00;
	pDataParams2->bBitRateCaps2 = 0x00;
	pDataParams2->bFwi2 = PHPAL_I14443P4A_SW_FWI_DEFAULT2;
	pDataParams2->bFsci2 = PHPAL_I14443P4A_SW_FSCI_DEFAULT2;
	pDataParams2->bFsdi2 = 0x00;
	pDataParams2->bDri2 = 0x00;
	pDataParams2->bDsi2 = 0x00;
	pDataParams2->bOpeMode2 = RD_LIB_MODE_ISO2;
	pDataParams2->bRetryCount2 = PHPAL_I14443P4A_RATS_RETRY_MAX2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_SetConfig2(
                                       P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       VAR(uint16, ANFCRL_VAR) wConfig2,
                                       VAR(uint16, ANFCRL_VAR) wValue2
                                     )
{
	switch (wConfig2)
	{
	/* Emvco: To Define Running Mode for RdLib: Either NFC, EMVCO or ISO */
	case PHPAL_I14443P4A_CONFIG_OPE_MODE2:
	{
		pDataParams2->bOpeMode2 = (uint8) wValue2;
		break;
	}

	case PHPAL_I14443P4A_CONFIG_RATS_RETRY_COUNT2:
	{
		if (!(((wValue2 & 0xFFU) == PHPAL_I14443P4A_RATS_RETRY_MIN2) || ((wValue2 & 0xFFU) == PHPAL_I14443P4A_RATS_RETRY_MAX2)))
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
		}

		pDataParams2->bRetryCount2 = (uint8) wValue2;
		break;
	}

	default:
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_GetProtocolParams2(
    P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
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


FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_ActivateCard2(
        P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
        VAR(uint8, ANFCRL_VAR) bFsdi2,
        VAR(uint8, ANFCRL_VAR) bCid2,
        VAR(uint8, ANFCRL_VAR) bDri2,
        VAR(uint8, ANFCRL_VAR) bDsi2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	switch (pDataParams2->eActCardState2)
	{
		case PHPAL_I14443P4A_ACTCARD_IDLE2:

			/* Check Dri value */
			switch (bDri2)
			{
			case PHPAL_I14443P4A_DATARATE_1062:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_2122:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_4242:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_8482:
				break;
			default:
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}

			/* Check Dri value */
			switch (bDsi2)
			{
			case PHPAL_I14443P4A_DATARATE_1062:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_2122:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_4242:
				/* fall through */
			case PHPAL_I14443P4A_DATARATE_8482:
				break;
			default:
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}
			I14443P4_LOG2("~~~ ACTIVATION CARD START ~~~ \r\n");
			pDataParams2->eActCardState2 = PHPAL_I14443P4A_ACTCARD_RATS2;
#if 0 // CAS_KR: no break for fast card detection
			return PH_STATUS_INPROCESS2;
#endif

		case PHPAL_I14443P4A_ACTCARD_RATS2:
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4a_Sw_Rats2(pDataParams2, bFsdi2, bCid2, pAts2));
			if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
			{
				/* Perform PPS */
				if ((bDri2 != PHPAL_I14443P4A_DATARATE_1062) || (bDsi2 != PHPAL_I14443P4A_DATARATE_1062))
				{
					pDataParams2->eActCardState2 = PHPAL_I14443P4A_ACTCARD_PPS2;
#if 0 // CAS_KR: no break for fast card detection
					return PH_STATUS_INPROCESS2;
#else
					PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4a_Sw_Pps2(pDataParams2, bDri2, bDsi2));
#endif
				}
			}
			break;

		case PHPAL_I14443P4A_ACTCARD_PPS2:
			PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p4a_Sw_Pps2(pDataParams2, bDri2, bDsi2));
	}
	pDataParams2->eActCardState2 = PHPAL_I14443P4A_ACTCARD_IDLE2;
	return status2;
}

/**
* @brief          New function non-blocking to replace on the original function phpalI14443p4a_Sw_Rats2
* @details        This function run at asynchronous mode
*
* @return         phStatus_t2
*                 SUCCESS or Error indicates the activation finished, returning result
*                 IN_PROGRESS indicates it's processing the command in Non blocking mode
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_Rats2(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                  VAR(uint8, ANFCRL_VAR) bFsdi2,
                                  VAR(uint8, ANFCRL_VAR) bCid2,
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts2
                                  )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 cmd2[2] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bAtsIndex2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSfgi2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwSfgt2 = 0U;
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwFwt2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwDelay2 = 0U;
	static VAR(I14443P4A_RATS_StateType_t2, ANFCRL_VAR) bRatsStateNext2 = PHPAL_I14443P4A_RATS_IDLE2;
	static VAR(uint16, ANFCRL_VAR) wWaitPeriod2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bWaitUnit2 = 0U;
	static VAR(phStatus_t2, ANFCRL_VAR) statusbkp2 = 0U;

	switch (pDataParams2->eRatsState2)
	{
#if 1 // CAS_KR: for fast card detection
	case PHPAL_I14443P4A_RATS_WAIT2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Wait2(pDataParams2->pHalDataParams2, bWaitUnit2, wWaitPeriod2));
		PH_BREAK_ON_FAILURE2(statusTmp2);
		pDataParams2->eRatsState2 = bRatsStateNext2;
		return PH_STATUS_INPROCESS2;
#endif
	case PHPAL_I14443P4A_RATS_IDLE2:
		/* Parameter check */
		if (pDataParams2->bOpeMode2 != RD_LIB_MODE_NFC2)
		{
			if ((bFsdi2 > PHPAL_I14443P4A_FRAMESIZE_MAX2) || (bCid2 > 14U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}
			if ((bFsdi2 < PHPAL_I14443P4A_EMVCO_FRAMESIZE_MIN2)
					&& (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}
		}
		else
		{
			if ((bFsdi2 > PHPAL_I14443P4A_NFC_FRAMESIZE_MAX2) || (bCid2 > 14U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}
		}

        /* Set Activation timeout */
        pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT2;
        return PH_STATUS_INPROCESS2;
    case PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
				PHPAL_I14443P4A_SW_FWT_ACTIVATION_US2 + PHPAL_I14443P4A_SW_EXT_TIME_US2));
		PH_BREAK_ON_FAILURE2(statusTmp2);
		/* Send Rats command */
		cmd2[0] = PHPAL_I14443P4A_SW_RATS2;
		cmd2[1] = (uint8) (((bFsdi2 << 4U) & 0xF0U) | (bCid2 & 0x0FU));
		I14443P4_LOG_BUF2(">>> P4A_RATS_SEND:", cmd2, 2U);
		bAtsIndex2 = pDataParams2->bRetryCount2 + 1u;
		pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SEND2;
#if 0 // CAS_KR: no break for fast card detection
		return PH_STATUS_INPROCESS2;
#endif

#if 0 // CAS_KR: no break for fast card detection
	case PHPAL_I14443P4A_RATS_WAIT2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Wait2(pDataParams2->pHalDataParams2, bWaitUnit2, wWaitPeriod2));
		PH_BREAK_ON_FAILURE2(statusTmp2);
		pDataParams2->eRatsState2 = bRatsStateNext2;
		return PH_STATUS_INPROCESS2;
#endif

	case PHPAL_I14443P4A_RATS_SEND2:
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, cmd2, 2u, &pResp2, &wRespLength2));
#ifdef NXPBUILD__PH_LOG_EX2
		if (status2 != PH_ERR_SUCCESS2)
		{
			I14443P4_LOG2("<<< P4A_RATS_RESPONSE Status:%0X \r\n", status2);
		}
		else
		{
			I14443P4_LOG_BUF2("<<< P4A_RATS_RESPONSE:", pResp2, (uint8 )wRespLength2);
		}
#endif
		bAtsIndex2--;
		if ((bAtsIndex2 > 0U) && (PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2)))
		{
			I14443P4_LOG2("*** RESEND RATS CMD  *** \r\n");
			/* Return error other than Timeout or Noise Error */
			pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SEND2;
			/* Emvco: case_id TA313, TA307_X, TA306_10-15, TA340_1 */
			return PH_STATUS_INPROCESS2;
		}
		statusbkp2 = status2;
		if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
		{
			/* Check for protocol error */
			if (((uint8) wRespLength2 != pResp2[0]) || (wRespLength2 < 1U))
			{
				I14443P4_LOG2("^^^ PROTOCOL_ERROR: CHECK BUFFER ERROR \r\n");
				statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
				break;
			}

			/* Copy ATS buffer */
			(void) memcpy(pAts2, pResp2, wRespLength2);

			/* Set default values */

			pDataParams2->bCidSupported2 = PH_ON2;
			pDataParams2->bCid2 = bCid2;

			pDataParams2->bNadSupported2 = PH_OFF2;
			pDataParams2->bBitRateCaps2 = 0x00;
			pDataParams2->bFwi2 = PHPAL_I14443P4A_SW_FWI_DEFAULT2;
			pDataParams2->bFsdi2 = bFsdi2;
			pDataParams2->bFsci2 = PHPAL_I14443P4A_SW_FSCI_DEFAULT2;
			pDataParams2->bDri2 = 0x00;
			pDataParams2->bDsi2 = 0x00;
			bSfgi2 = PHPAL_I14443P4A_SW_SFGI_DEFAULT2;

			/* Retrieve ATS information */
			/*  the maximum value of TL shall not exceed FSD-2 */
			if (pAts2[0] > bI14443p4a_FsTable2[bFsdi2])
			{
				I14443P4_LOG2("^^^ PROTOCOL_ERROR: CHECK BUFFER ERROR \r\n");
				statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
				break;
			}
			/* Start parsing with T0 byte */
			bAtsIndex2 = PHPAL_I14443P4A_SW_ATS_T02;

			/* Parse T0/TA/TB/TC */
			if (wRespLength2 > 1U)
			{
				/* Parse T0 */
				pDataParams2->bFsci2 = pAts2[bAtsIndex2] & 0x0FU;
				if (pDataParams2->bOpeMode2 != RD_LIB_MODE_NFC2)
				{
					if (pDataParams2->bFsci2 > PHPAL_I14443P4A_FRAMESIZE_MAX2)
					{
						pDataParams2->bFsci2 = PHPAL_I14443P4A_FRAMESIZE_MAX2;
					}
				}
				else
				{ /* Nfc: Digital Specification Ver 1.1 Table 59 */
					if (pDataParams2->bFsci2 > PHPAL_I14443P4A_NFC_FRAMESIZE_MAX2)
					{
						pDataParams2->bFsci2 = PHPAL_I14443P4A_NFC_FRAMESIZE_MAX2;
					}
				}

				bAtsIndex2++;

				/* Parse TA(1) */
				if (0U != (pAts2[PHPAL_I14443P4A_SW_ATS_T02] & PHPAL_I14443P4A_SW_ATS_TA1_PRESENT2))
				{
					/* Check for protocol error */
					if (wRespLength2 <= bAtsIndex2)
					{
						statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
						break;
					}

					/* Check for RFU bit b4 (b4 shall be 0; 1 is RFU) */
					if (0U != (pAts2[bAtsIndex2] & 0x08U))
					{
						/* Only 106 kbps in both direction */
						pDataParams2->bBitRateCaps2 = 0x00;
					}
					else
					{
						/* Store Bit rate capabilities */
						pDataParams2->bBitRateCaps2 = pAts2[bAtsIndex2];
					}

					bAtsIndex2++;
				}

				/* Parse TB(1) */
				if (0U != (pAts2[PHPAL_I14443P4A_SW_ATS_T02] & PHPAL_I14443P4A_SW_ATS_TB1_PRESENT2))
				{
					/* Check for protocol error */
					if (wRespLength2 <= bAtsIndex2)
					{
						statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
						break;
					}
					else
					{
						/* Store Sfgi */
						bSfgi2 = pAts2[bAtsIndex2] & 0x0FU;
						if (bSfgi2 == 0x0FU)
						{
							bSfgi2 = PHPAL_I14443P4A_SW_SFGI_DEFAULT2;
						}

						/* Store Fwi */
						pDataParams2->bFwi2 = (pAts2[bAtsIndex2] >> 4U) & 0x0FU;
						if (pDataParams2->bFwi2 == 0x0FU)
						{
							pDataParams2->bFwi2 = PHPAL_I14443P4A_SW_FWI_DEFAULT2;
						}

						bAtsIndex2++;
					}
				}

				/* Parse TC(1) */
				if (0U != (pAts2[PHPAL_I14443P4A_SW_ATS_T02] & PHPAL_I14443P4A_SW_ATS_TC1_PRESENT2))
				{
					/* Check for protocol error */
					if (wRespLength2 <= bAtsIndex2)
					{
						statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
						break;
					}
					else
					{
						/* NAD is supported only in ISO/IEC 14443-4 specification. */
						if (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
						{
							/* Check bit 2-7 = 0 */
							if ((pAts2[bAtsIndex2] & 0xFCu) != 0U)
							{
								statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
								break;
							}

							/* Check NAD Support */
							if (0U != (pAts2[bAtsIndex2] & PHPAL_I14443P4A_SW_ATS_TC1_NAD_SUPPORT2))
							{
								pDataParams2->bNadSupported2 = PH_ON2;
							}
						}

						/* Check CID Support */
						if ((pAts2[bAtsIndex2] & PHPAL_I14443P4A_SW_ATS_TC1_CID_SUPPORT2) == 0U)
						{
							pDataParams2->bCidSupported2 = PH_OFF2;
							pDataParams2->bCid2 = 0x00;
						}
					}
				}
			}

			/* Calculate SFGT in Microseconds */
			dwDelay2 = PHPAL_I14443P4A_SW_FWT_MIN_US2 * ((uint32) 1U << bSfgi2);
			if (pDataParams2->bOpeMode2 != RD_LIB_MODE_ISO2)
			{
				dwDelay2 += (PHPAL_I14443P4A_DELTA_SFGT_US2) * ((uint32) 1U << bSfgi2);
			}
			dwSfgt2 = (uint32) dwDelay2;

			I14443P4_LOG2("*** ATS INFO - SFGi: %d -SFG time: %d \r\n", bSfgi2, dwSfgt2);
			/* Perform SFGT Wait */
			if (dwSfgt2 > 0xFFFFU)
			{
				bWaitUnit2 = PHHAL_HW_TIME_MILLISECONDS2;
				wWaitPeriod2 = (uint16 )((dwSfgt2 / 1000U) + 1U);
				pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_WAIT2;
			}
			else
			{
				bWaitUnit2 = PHHAL_HW_TIME_MICROSECONDS2;
				wWaitPeriod2 = (uint16)dwSfgt2;
				pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_WAIT2;
			}
			bRatsStateNext2 = PHPAL_I14443P4A_RATS_FWTCONFIG2;
		}
		/* Perform protocol error handling */
		else
		{
			if (I14443P4A_SW_IS_INVALID_BLOCK_STATUS2(status2) == 0U)
			{
				I14443P4_LOG2("*** RATS RESP -> ERROR UNKNOW:%0X  *** \r\n", status2);
				statusTmp2 = status2;
				break;
			}
			/* Send S(DESELECT) command */
			I14443P4_LOG2(">>> P4A_SDESELECT_SEND  \r\n");
			cmd2[0] = PHPAL_I14443P4A_SW_S_BLOCK2 | PHPAL_I14443P4A_SW_S_BLOCK_RFU_BITS2 | PHPAL_I14443P4A_SW_PCB_DESELECT2;
			/* Wait FWTmin after RATS */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_IO_TIMEOUT2)
			{
				bWaitUnit2 = PHHAL_HW_TIME_MICROSECONDS2;
				wWaitPeriod2 = PHPAL_I14443P4A_SW_FWT_MIN_US2 + PHPAL_I14443P4A_SW_EXT_TIME_US2;
				pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_WAIT2;
				bRatsStateNext2 = PHPAL_I14443P4A_RATS_DESELSEND2;
#if 1 // CAS_KR: for fast card detection
				//do "case PHPAL_I14443P4A_RATS_WAIT2:"
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Wait2(pDataParams2->pHalDataParams2, bWaitUnit2, wWaitPeriod2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				pDataParams2->eRatsState2 = bRatsStateNext2;
#endif
				return PH_STATUS_INPROCESS2;
			}
			pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_DESELSEND2;
		}
		return PH_STATUS_INPROCESS2;

	case PHPAL_I14443P4A_RATS_DESELSEND2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				PH_EXCHANGE_DEFAULT2,
				cmd2,
				1u,
				&pResp2,
				&wRespLength2));

		I14443P4_LOG2("<<< P3A_SDESELECT_RESPONSE:%0X  \r\n", statusTmp2);
		/* S(DESELECT) failure */
		if (((statusTmp2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2) || (wRespLength2 != 1U) || (pResp2[0] != cmd2[0]))
		{
			/* Set HLTA timeout */
			pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT2;
			return PH_STATUS_INPROCESS2;
		}
		else
		{
			/* S(DESELECT) success */
			/* Return error status2 of RATS exchange*/
			statusTmp2 = PH_ADD_COMPCODE2(statusbkp2, PH_COMP_PAL_ISO14443P4A2);
		}
		break;
	case PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT2:
        PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
                pDataParams2->pHalDataParams2,
                PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
                PHPAL_I14443P4A_SW_HALT_TIME_US2));
        PH_BREAK_ON_FAILURE2(statusTmp2);

        /* Send HLTA */
        I14443P4_LOG2(">>> P4A_HALT_SEND  \r\n");
        cmd2[0] = PHPAL_I14443P4A_SW_HALT_CMD2;
        cmd2[1] = 0x00;

        pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_HALT2;
        return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P4A_RATS_FWTCONFIG2:
        /* Calculate FWT timeout */
        dwDelay2 = PHPAL_I14443P4A_SW_FWT_MIN_US2;
        dwDelay2 = (dwDelay2 * ((uint32)1U << pDataParams2->bFwi2));

        if(pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
        {
            /* Add extension time */
            dwDelay2 = dwDelay2 + PHPAL_I14443P4A_SW_EXT_TIME_US2;
        }
        else
        {
            /* As per Digital Spec V1.1 req 13.8.1.3, NFC Forum Device SHALL wait at least FWT + delta FWTT4AT for a Response */
            dwDelay2 = dwDelay2 + PHPAL_I14443P4A_SW_DELTA_FWT_US2;

            if(pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2) {
                /* As per EMVCo, add delta Tpcd time along with delta FWT time */
                dwDelay2 += PHPAL_I14443P4A_SW_DELTA_TPCD_US2;
            }
        }
        dwFwt2 = (uint32)dwDelay2;

		I14443P4_LOG2("*** CALCULATE & SET FWT TIMEOUT: %d *** \r\n", dwFwt2);
		I14443P4_LOG2("*** Fwi: %d \r\n", pDataParams2->bFwi2);

		/* Set FWT timeout */
		if (dwFwt2 > 0xFFFFU)
		{
            /* +1 is added to the timeout in millisecond to compensate the
             * fractional microseconds lost in division by 1000 */
            pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS2;
		}
		else
		{
            pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US2;
		}
        return PH_STATUS_INPROCESS2;
	case PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS2:
	    PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2, (uint16 )((dwFwt2 / 1000U) + 1U)));
	    break;
	case PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US2:
	    PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2, (uint16 )dwFwt2));
        break;
	case PHPAL_I14443P4A_RATS_HALT2:
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				PH_EXCHANGE_DEFAULT2,
				cmd2,
				2u,
				&pResp2,
				&wRespLength2));
		PH_BREAK_ON_FAILURE2(statusTmp2);
		/* Return error status2 of RATS exchange*/
		statusTmp2 = PH_ADD_COMPCODE2(statusbkp2, PH_COMP_PAL_ISO14443P4A2);
	}
    dwFwt2 = 0U;
    pDataParams2->eRatsState2 = PHPAL_I14443P4A_RATS_IDLE2;
    return statusTmp2;
}

/**
* @brief          New function non-blocking to replace on the original function phpalI14443p4a_Sw_Pps2
* @details        This function run at asynchronous mode
*
* @return         phStatus_t2
*                 SUCCESS or Error indicates the activation finished, returning result
*                 IN_PROGRESS indicates it's processing the command in Non blocking mode
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_Pps2(
                 P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                 VAR(uint8, ANFCRL_VAR) bDri2,
                 VAR(uint8, ANFCRL_VAR) bDsi2
								 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 cmd2[3];
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxDataRate2;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxDataRate2;

	switch (pDataParams2->ePpsState2)
	{
		case PHPAL_I14443P4A_PPS_IDLE2:
			/* Check and convert Dri value */
			switch (bDri2)
			{
				case PHPAL_I14443P4A_DATARATE_1062:
					wTxDataRate2 = PHHAL_HW_RF_DATARATE_1062;
					break;
				case PHPAL_I14443P4A_DATARATE_2122:
					wTxDataRate2 = PHHAL_HW_RF_DATARATE_2122;
					break;
				case PHPAL_I14443P4A_DATARATE_4242:
					wTxDataRate2 = PHHAL_HW_RF_DATARATE_4242;
					break;
				case PHPAL_I14443P4A_DATARATE_8482:
					wTxDataRate2 = PHHAL_HW_RF_DATARATE_8482;
					break;
				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}

			/* Check and convert Dsi value */
			switch (bDsi2)
			{
				case PHPAL_I14443P4A_DATARATE_1062:
					wRxDataRate2 = PHHAL_HW_RF_DATARATE_1062;
					break;
				case PHPAL_I14443P4A_DATARATE_2122:
					wRxDataRate2 = PHHAL_HW_RF_DATARATE_2122;
					break;
				case PHPAL_I14443P4A_DATARATE_4242:
					wRxDataRate2 = PHHAL_HW_RF_DATARATE_4242;
					break;
				case PHPAL_I14443P4A_DATARATE_8482:
					wRxDataRate2 = PHHAL_HW_RF_DATARATE_8482;
					break;
				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_ISO14443P4A2);
			}

			/* Send Pps command */
			cmd2[0] = PHPAL_I14443P4A_SW_PPSS2 | pDataParams2->bCid2;
			cmd2[1] = PHPAL_I14443P4A_SW_PPS02;
			cmd2[2] = ((bDsi2 << 2U) & 0x0CU) | (bDri2 & 0x03U);
			I14443P4_LOG_BUF2(">>> P4A_PPS_SEND:", cmd2, 3U);
            pDataParams2->ePpsState2 = PHPAL_I14443P4A_PPS_EXCHANGE2;
			/*no break*/
		case PHPAL_I14443P4A_PPS_EXCHANGE2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(pDataParams2->pHalDataParams2, PH_EXCHANGE_DEFAULT2, cmd2, 3, &pResp2, &wRespLength2));
#ifdef NXPBUILD__PH_LOG_EX2
			if (status2 != PH_ERR_SUCCESS2)
			{
				I14443P4_LOG2("<<< P4A_PPS_RESPONSE Status:%0X \r\n", status2);
			}
			else
			{
				I14443P4_LOG_BUF2("<<< P4A_PPS_RESPONSE:", pResp2, (uint8 )wRespLength2);
			}
#endif
			/* NAK means protocol error */
			if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS_INCOMPLETE_BYTE2)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
				break;
			}

			/* Success check */
			PH_BREAK_ON_FAILURE2(status2);

			/* Check length and start byte of PPS */
			if ((wRespLength2 != 1U) || (pResp2[0] != (PHPAL_I14443P4A_SW_PPSS2 | pDataParams2->bCid2)))
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_ISO14443P4A2);
				break;
			}
			/* Store data rates */
			pDataParams2->bDri2 = bDri2;
			pDataParams2->bDsi2 = bDsi2;
			pDataParams2->ePpsState2 = PHPAL_I14443P4A_PPS_TXDATARATE2;
			return  PH_STATUS_INPROCESS2;

		case PHPAL_I14443P4A_PPS_TXDATARATE2:
			/* Apply new data rates to Pcd */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,
					wTxDataRate2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->ePpsState2 = PHPAL_I14443P4A_PPS_RXDATARATE2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_I14443P4A_PPS_RXDATARATE2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,
					wRxDataRate2));
	}
	pDataParams2->ePpsState2 = PHPAL_I14443P4A_PPS_IDLE2;
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_SW_AR_RELEASE_MAJOR_VERSION_C== 4) && (PHPALI14443P4A_SW_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#ifdef __cplusplus
}
#endif
