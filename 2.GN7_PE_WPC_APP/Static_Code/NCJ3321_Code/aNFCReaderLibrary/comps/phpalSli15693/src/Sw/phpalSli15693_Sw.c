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
*   @file    phpalSli15693_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalSli15693 ISO/IEC 15693 
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
#include <phpalSli15693.h>
#include <ph_RefDefs.h>
#include <phhalHw.h>
#include <phTools.h>

#ifdef  NXPBUILD__PHPAL_SLI15693_SW
#include "phpalSli15693_Sw.h"
#include "phpalSli15693_Sw_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli15693_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalSli15693_Sw.h header file are of the same vendor */
#if (PHPALSLI15693_SW_VENDOR_ID_C != PHPALSLI15693_SW_VENDOR_ID)
    #error "phpalSli15693_Sw.c and phpalSli15693_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalSli15693_Sw.h header file are of the same Autosar version */
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION_C != PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalSli15693_Sw.c and phpalSli15693_Sw.h are different"
#endif
/* Check if current file and phpalSli15693_Sw.h header file are of the same Software version */
#if ((PHPALSLI15693_SW_SW_MAJOR_VERSION_C != PHPALSLI15693_SW_SW_MAJOR_VERSION) || \
     (PHPALSLI15693_SW_SW_MINOR_VERSION_C != PHPALSLI15693_SW_SW_MINOR_VERSION) || \
     (PHPALSLI15693_SW_SW_PATCH_VERSION_C != PHPALSLI15693_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalSli15693_Sw.c and phpalSli15693_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_SLI15693_SW */
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
#ifdef  NXPBUILD__PHPAL_SLI15693_SW
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#if (defined(NXPBUILD__PH_LOG_EX) && !defined(PH_LIB_LOG_DISABLE))
static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) TAG = "SLI15693|";
#endif

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
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
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Init(
                 P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
								 )
{
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pHalDataParams);

	/* parameter structure length check */
	if (sizeof(phpalSli15693_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_SLI15693);
	}

	/* init private data */
	pDataParams->wId                       = PH_COMP_PAL_SLI15693 | PHPAL_SLI15693_SW_ID;
	pDataParams->pHalDataParams            = pHalDataParams;
	pDataParams->wAdditionalInfo           = 0U;
	pDataParams->bFlags                    = PHPAL_SLI15693_SW_FLAGS_DEFAULT;
	pDataParams->bUidBitLength             = 0U;
	pDataParams->bExplicitlyAddressed      = 0U;
	pDataParams->bOpeMode                  = RD_LIB_MODE_ISO; /* Default Mode is ISO */
	pDataParams->bBuffering                = 0U;
	pDataParams->bAlICodeStateMachineState = 0U;

	/* reset state machine */
	pDataParams->eSendEofState             = PHPAL_SLI15693_SENDEOF_STATE_IDLE;
	pDataParams->eActCardState		       = PHPAL_SLI15693_ACTCARD_START;
	pDataParams->eInventoryState	       = PHPAL_SLI15693_INVENTORY_START;
	pDataParams->eStayQuietState	       = PHPAL_SLI15693_STATE_IDLE;
	pDataParams->eStayQuietPersistentState = PHPAL_SLI15693_STATE_IDLE;
	pDataParams->eSelectState              = PHPAL_SLI15693_STATE_IDLE;
	pDataParams->eResetToReadyState        = PHPAL_SLI15693_STATE_IDLE;
	pDataParams->eExchangeState            = PHPAL_SLI15693_STATE_IDLE;
	pDataParams->eSetConfigState           = PHPAL_SLI15693_STATE_IDLE;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Inventory(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bFlags,
                    VAR(uint8, ANFCRL_VAR) bAfi,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
									  )
{
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLength = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLength = 0U;

	return phpalSli15693_Sw_InventoryEx(
		pDataParams,
		PHPAL_SLI15693_SW_CMD_INVENTORY,
		bFlags,
		bAfi,
		pMask,
		bMaskBitLength,
		0U,
		0U,
		pUid,
		&bUidLength,
		pDsfid,
		&wDataLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SendEof(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusExchange = PH_ERR_SUCCESS;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStoredUidLength = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wAsk = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTimeout = 0U;

	switch(pDataParams->eSendEofState)
	{
		case PHPAL_SLI15693_SENDEOF_STATE_IDLE:
			/* Check bOption */
			switch (bOption)
			{
				case PHPAL_SLI15693_EOF_NEXT_SLOT:
				case PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ:
				case PHPAL_SLI15693_EOF_WRITE_ALIKE:
				case PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			/* Reset UID and data lengths */
			*pDsfid = 0U;
			*pUidLength = 0U;
			*pDataLength = 0U;
			pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_WRITE_ALIKE_WITH_WAIT;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_WRITE_ALIKE_WITH_WAIT:
			/* if requested, wait ~20ms upon sending EOF */
			if (bOption == PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT)
			{
				/* in case of write alike commands wait 20 ms. */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Wait(
					pDataParams->pHalDataParams,
					PHHAL_HW_TIME_MICROSECONDS,
					PHPAL_SLI15693_TIMEOUT_LONG_US));
				if(statusTmp != PH_ERR_SUCCESS){
					status = statusTmp;
				}
				PH_BREAK_ON_FAILURE(status);
			}
			else
			{
				/* Do nothing */
			}
			pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_GET_TIMEOUT;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_GET_TIMEOUT:
			/* Get the ASK 100 Condition */
			PH_CHECK_FAILURE_FCT(status, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_ASK100,
				&wAsk));

			if(bOption == PHPAL_SLI15693_EOF_NEXT_SLOT)
			{
				if(0U != (wAsk))
				{
					if(0U != (pDataParams->bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_HIGH_SOF_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_LOW_SOF_US;
					}
				}
				else
				{
					if(0U != (pDataParams->bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_HIGH_NRT_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_LOW_NRT_US;
					}
				}
				pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT;
			}
			else if(bOption == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ)
			{
				if(0U != (wAsk))
				{
					if(0U != (pDataParams->bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTHIGH_SOF_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTLOW_SOF_US;
					}
				}
				else
				{
					if(0U != (pDataParams->bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTHIGH_NRT_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTLOW_NRT_US;
					}
				}

				pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT;
			}
			else
			{
				/* Set short timeout. */
				wTimeout = PHPAL_SLI15693_SW_TIMEOUT_SLOT_US;
				pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT;
			}
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT:
			/* Set  timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US,
				wTimeout));
			PH_BREAK_ON_FAILURE(status);

			pDataParams->eSendEofState =  PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START1;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START1:
			/* Disable SOF, so only EOF is sent */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_SYMBOL_START,
				PH_OFF));
			PH_BREAK_ON_FAILURE(status);

			MSG_LOG(TAG, ">>> SendEof Option: %X\r\n", bOption);
			pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_SEND;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHPAL_SLI15693_SENDEOF_STATE_SEND:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_DEFAULT,
				NULL,
				0,
				&pResp,
				&wRespLength));
			MSG_LOG(TAG, "<<< SendEof status: %X\r\n", status);
			statusExchange = status;
			pDataParams->eSendEofState =  PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START2;
			return PH_STATUS_INPROCESS;
			/* no break */

		case PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START2:
			/* Reset HAL to send SOF and EOF */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_SYMBOL_START,
				PHHAL_HW_SYMBOL_I15693_SOF));

			status = statusExchange;
			PH_BREAK_ON_FAILURE(status);

			if(statusTmp != PH_ERR_SUCCESS){
				status = statusTmp;
			}

			/* Check Success */
			PH_BREAK_ON_FAILURE(status);

			/* Check RespLength */
			if (wRespLength == 0U)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
				break;
			}

			/* check error flag */
			if (0U != (pResp[0] & PHPAL_SLI15693_FLAG_RESP_ERROR))
			{
				/* check the length in case of error */
				if (wRespLength != 2U)
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
					break;
				}

				pDataParams->wAdditionalInfo = pResp[1];
				status = PH_ADD_COMPCODE_FIXED(PHPAL_SLI15693_ERR_ISO15693, PH_COMP_PAL_SLI15693);
				break;
			}

			if (bOption == PHPAL_SLI15693_EOF_NEXT_SLOT)
			{
				/* ignore flag byte */
				++pResp;
				--wRespLength;

				/* the UID is only returned on a next slot command. */
				if (wRespLength != (1u + PHPAL_SLI15693_UID_LENGTH))
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
					break;
				}

				/* Copy the DSFID to the data buffer */
				*pDsfid = pResp[0];

				/* retrieve the UID */
				(void)memcpy(pDataParams->pUid, &pResp[1], PHPAL_SLI15693_UID_LENGTH);
				pDataParams->bUidBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;

				/* return the UID */
				(void)memcpy(pUid, &pResp[1], PHPAL_SLI15693_UID_LENGTH);
				*pUidLength = PHPAL_SLI15693_UID_LENGTH;

				/* set addressed flag */
				pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;
			}
			else if (bOption == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ)
			{
				/* ignore flag byte */
				++pResp;
				--wRespLength;

				/* Option flag is set -> we also received (partial) UID */
				if (0U != (pDataParams->bFlags & PHPAL_SLI15693_FLAG_OPTION))
				{
					/* The response length should not be less than the remaining UID */
					bStoredUidLength = pDataParams->bUidBitLength >> 3U;
					*pUidLength = PHPAL_SLI15693_UID_LENGTH - bStoredUidLength;
					if (wRespLength < *pUidLength)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
						break;
					}

					if (bStoredUidLength < PHPAL_SLI15693_UID_LENGTH)
					{
						/* We need to merge the contents of the mask buffer and the received data */
						if (0U != (pDataParams->bUidBitLength % 8U))
						{
							if (bStoredUidLength < 7U)
							{
								/* copy the UID bytes we received from the card */
								(void)memcpy(&(pDataParams->pUid[bStoredUidLength + 1U]), &pResp[1], ((uint32)(*pUidLength)-1U));
							}

							/* merge mask-bits with received bits */
							pDataParams->pUid[bStoredUidLength] |= pResp[0];
						}
						else
						{
							/* copy the UID bytes we received from the card */
							(void)memcpy(&(pDataParams->pUid[bStoredUidLength]), pResp, *pUidLength);
						}

						/* Return the received (partial) UID */
						(void)memcpy(pUid, pResp, *pUidLength);
					}

					/* UID is now complete */
					pDataParams->bUidBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;

					/* shift pointer and length */
					pResp = &pResp[*pUidLength];
					wRespLength = wRespLength - *pUidLength;
				}

				/* copy the received data to the provided buffer */
				(void)memcpy(pData, pResp, wRespLength);

				/* the remaining bytes of the response are the data bytes */
				*pDataLength = wRespLength;

				/* set addressed flag */
				pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;
			}
			else
			{
				/* 1 byte is only returned on a eof for a write alike command. */
				if (wRespLength != 1U)
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
					break;
				}
			}

			pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_FINISH;
			return PH_STATUS_INPROCESS;
			/*no break*/

		case PHPAL_SLI15693_SENDEOF_STATE_FINISH:
			if ((bOption == PHPAL_SLI15693_EOF_NEXT_SLOT) || (bOption == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ))
			{
				/* wait T2 PH_CHECK_SUCCESS_FCT() */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Wait(pDataParams->pHalDataParams, PHHAL_HW_TIME_MICROSECONDS, PHPAL_SLI15693_SW_T2_WAITING_TIME));
			}
			else
			{
				status = PH_ERR_SUCCESS;
			}
			break;
	}

	bStoredUidLength = 0U;
	wAsk = 0U;
	wTimeout = 0U;
	pResp = NULL;
	wRespLength = 0U;
	pDataParams->eSendEofState = PHPAL_SLI15693_SENDEOF_STATE_IDLE;
	if(status != PH_ERR_SUCCESS)
	{
		status = PH_ADD_COMPCODE(status, PH_COMP_PAL_SLI15693);
	}
	statusExchange = PH_ERR_SUCCESS;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_StayQuiet(
                                      P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	switch (pDataParams->eStayQuietState)
	{
		case PHPAL_SLI15693_STATE_IDLE:
			/* clear selected flag */
			pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED;

			/* set addressed flag */
			pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;

			/* reset to ready command */
			aCmd[0] = PHPAL_SLI15693_SW_CMD_STAY_QUIET;

			pDataParams->eStayQuietState	= PHPAL_SLI15693_STATE_SET_TIMEOUT;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US,
				PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eStayQuietState	= PHPAL_SLI15693_STATE_EXCHANGE;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE:
			/* Exchange command */
			status = phpalSli15693_Exchange(pDataParams, PH_EXCHANGE_DEFAULT, aCmd, 1, &pResp, &wRespLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}

			/* No response to the command allowed */
			if ((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT)
			{
				PH_BREAK_ON_FAILURE(status);
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
			}
			else
			{
				status = PH_ERR_SUCCESS;
			}
			break;
		default:
			break;
	}

	aCmd[0] = 0U;
	pDataParams->eStayQuietState = PHPAL_SLI15693_STATE_IDLE;
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_StayQuietPersistent(
                                                P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                                )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	switch (pDataParams->eStayQuietPersistentState)
	{
		case PHPAL_SLI15693_STATE_IDLE:
			/* clear selected flag */
			pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED;

			/* set addressed flag */
			pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;

			/* stay quiet persistent command */
			aCmd[0] = PHPAL_SLI15693_SW_CMD_STAY_QUIET_PERSISTENT;

			pDataParams->eStayQuietState	= PHPAL_SLI15693_STATE_SET_TIMEOUT;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US,
				PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eStayQuietPersistentState = PHPAL_SLI15693_STATE_EXCHANGE;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE:
			/* Exchange command */
			status = phpalSli15693_Exchange(pDataParams, PH_EXCHANGE_DEFAULT, aCmd, 1, &pResp, &wRespLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}

			/* No response to the command allowed */
			if ((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT)
			{
				PH_BREAK_ON_FAILURE(status);
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
			}
			else
			{
				status = PH_ERR_SUCCESS;
			}
			break;
		default:
			break;
	}

	aCmd[0] = 0U;
	pDataParams->eStayQuietPersistentState = PHPAL_SLI15693_STATE_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Select(
                                   P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                   )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	switch (pDataParams->eSelectState)
	{
		case PHPAL_SLI15693_STATE_IDLE:
			/* clear selected flag */
			pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED;

			/* set addressed flag */
			pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;

			/* reset to ready command */
			aCmd[0] = PHPAL_SLI15693_SW_CMD_SELECT;

			pDataParams->eStayQuietState	= PHPAL_SLI15693_STATE_SET_TIMEOUT;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US,
				PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eSelectState = PHPAL_SLI15693_STATE_EXCHANGE;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE:
			status = phpalSli15693_Exchange(pDataParams, PH_EXCHANGE_DEFAULT, aCmd, 1, &pResp, &wRespLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}
			/* We shall not receive any data */
			if (wRespLength != 0U)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
				break;
			}

			/* clear addressed flag */
			pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_ADDRESSED;

			/* set selected flag */
			pDataParams->bFlags |= PHPAL_SLI15693_FLAG_SELECTED;
			break;
		default:
			break;
	}

	aCmd[0] = 0U;
	pDataParams->eSelectState = PHPAL_SLI15693_STATE_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_ResetToReady(
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;

	switch (pDataParams->eResetToReadyState)
	{
		case PHPAL_SLI15693_STATE_IDLE:
			/* reset to ready command */
			aCmd[0] = PHPAL_SLI15693_SW_CMD_RESET_TO_READY;

			pDataParams->eStayQuietState	= PHPAL_SLI15693_STATE_SET_TIMEOUT;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US,
				PHPAL_SLI15693_TIMEOUT_SHORT_US));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eResetToReadyState = PHPAL_SLI15693_STATE_EXCHANGE;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE:
			/* Exchange command */
			status = phpalSli15693_Exchange(pDataParams, PH_EXCHANGE_DEFAULT, aCmd, 1, &pResp, &wRespLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}

			/* We shall not receive any data */
			if (wRespLength != 0U)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
				break;
			}

			/* clear selected flag */
			pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED;
			break;
		default:
			break;
	}

	aCmd[0] = 0U;
	pDataParams->eResetToReadyState = PHPAL_SLI15693_STATE_IDLE;
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Exchange(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                  VAR(uint16, ANFCRL_VAR) wTxLength,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFirstBlock[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTransmitLength = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempOption = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempTxLength = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTempTxBuffer = NULL;

	/* the frame to exchange looks like the following:
	{optional} [one byte]
	[flags][CMD]{[MFC]}{[UID0] .. [UID3]}[CMDParam(0)] .. [CMDParam(N)] */

	/* Check for valid UID in addressed mode */
	if ((0U == ((pDataParams->bFlags & PHPAL_SLI15693_FLAG_INVENTORY))) && (0U != ((pDataParams->bFlags & PHPAL_SLI15693_FLAG_ADDRESSED))))
	{
		/* Return an error if UID is not valid */
		if (pDataParams->bUidBitLength != PHPAL_SLI15693_SW_UID_COMPLETE)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_SLI15693);
		}
	}

	/* Check if caller has provided valid RxBuffer */
	if (ppRxBuffer == NULL)
	{
		ppRxBuffer = &pDataParams->pTmpRxBuff;
	}
	if (pRxLength == NULL)
	{
		pRxLength = &pDataParams->tmpRxLen;
	}

	switch (pDataParams->eExchangeState)
	{
		case PHPAL_SLI15693_STATE_IDLE:
			wTempOption = wOption;
			wTempTxLength = wTxLength;
			pTempTxBuffer = pTxBuffer;
			if ((0U == ((wTempOption & PH_EXCHANGE_LEAVE_BUFFER_BIT))))
			{
				pDataParams->eExchangeState = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_1;
			}
			else
			{
				if(wTempTxLength != 0U)
				{
					MSG_LOG_BUF(TAG, ">>>> Exchange: " , pTempTxBuffer, (uint8)wTempTxLength);
				}
				pDataParams->eExchangeState = PHPAL_SLI15693_STATE_EXCHANGE;
			}
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_1:
			/* This is the first chunk of a command frame. Add the Flags byte and ... */
			bFirstBlock[wTransmitLength++] = pDataParams->bFlags;
			bFirstBlock[wTransmitLength++] = pTxBuffer[0];

			/* add MFC byte for custom commands */
			if ((pTxBuffer[0] > PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_BEGIN) && (pTxBuffer[0] < PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_END))
			{
				/* if no serial number is valid we assume that we use only NXP tags. */
				bFirstBlock[wTransmitLength++] = PHPAL_SLI15693_SW_NXP_MFG_CODE;
			}
			else
			{
				if((pTxBuffer[0] == PHPAL_SLI15693_SW_CMD_EXTENDED_GET_SYSTEM_INFORMATION)
				   && (wTempTxLength > 1U))
			   {
				   /* Handle the Frame format preparation for Extended Get System Information specifically since this takes 1
					*  UID from 3rd Byte whereas rest other commands take UID from 2nd Byte
					*  SOF + FLAGS + COMMAND CODE +  INFO FLAGS  + UID  + CRC + EOF.
					*/

				   /* Copy Info Flags */
				   bFirstBlock[wTransmitLength++] = pTxBuffer[1];

				   /* First byte was the command byte */
				   ++pTempTxBuffer;
				   --wTempTxLength;
			   }
			}
			pDataParams->eExchangeState = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_2;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_2:
			/* Exchange command */
			/* clear buffer but do not send */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_BUFFERED_BIT,
				bFirstBlock,
				wTransmitLength,
				ppRxBuffer,
				pRxLength));
			PH_BREAK_ON_FAILURE(status);
			MSG_LOG_BUF(TAG, ">>>> Exchange: " , bFirstBlock, (uint8)wTransmitLength);

			/* First set of TxBuffer contains
			 *  1. command code + Info Bytes
			 *  2. command Code
			 */
			++pTempTxBuffer;
			--wTempTxLength;
			pDataParams->eExchangeState = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_3;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_3:
			/* If we are not waiting any more we can transmit the UID bytes, if necessary. */
			if ((0U == ((pDataParams->bFlags & PHPAL_SLI15693_FLAG_INVENTORY))) && (0U != ((pDataParams->bFlags & PHPAL_SLI15693_FLAG_ADDRESSED))))
			{
				if(0U == (pDataParams->bExplicitlyAddressed))
				{
					PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
						pDataParams->pHalDataParams,
						PH_EXCHANGE_BUFFER_CONT,    /* do not clear, do not send */
						pDataParams->pUid,
						PHPAL_SLI15693_UID_LENGTH,
						ppRxBuffer,
						pRxLength));
					PH_BREAK_ON_FAILURE(status);
					MSG_LOG_BUF(TAG, ">>>> Exchange: " , pDataParams->pUid, PHPAL_SLI15693_UID_LENGTH);
				}
			}

			/* Now we need to keep our buffered contents */
			wTempOption |= PH_EXCHANGE_LEAVE_BUFFER_BIT;
			if(wTempTxLength != 0U)
			{
				MSG_LOG_BUF(TAG, ">>>> Exchange: " , pTxBuffer, (uint8)wTempTxLength);
			}
			pDataParams->eExchangeState = PHPAL_SLI15693_STATE_EXCHANGE;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE:
			status = phhalHw_Exchange(
				pDataParams->pHalDataParams,
				wTempOption,
				pTempTxBuffer,
				wTempTxLength,
				ppRxBuffer,
				pRxLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}
			if(status == PH_ERR_SUCCESS)
			{
				MSG_LOG_BUF(TAG, "<<<< Exchange: " , *ppRxBuffer, (uint8)(*pRxLength));
			}
			else
			{
				MSG_LOG(TAG, "<<< Exchange status: %X\r\n", status);
			}
			PH_BREAK_ON_FAILURE(status);
			/* If this was the last (or only) chunk, we should have received a response,
			so we extract the Flags byte and check the status */
			if ((0U == ((wTempOption & PH_EXCHANGE_BUFFERED_BIT))))
			{
				/* First Check RespLength*/
				if (*pRxLength == 0U)
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
					break;
				}

				/*check error flag*/
				if (0U != ((*ppRxBuffer[0]) & PHPAL_SLI15693_FLAG_RESP_ERROR))
				{
					/* check the length in case of error */
					if (*pRxLength != 2U)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
						break;
					}

					/* Copy error code to additional info */
					pDataParams->wAdditionalInfo = (*ppRxBuffer)[1];

					/* Return empty receive buffer */
					*ppRxBuffer = NULL;
					*pRxLength = 0;

					status = PH_ADD_COMPCODE_FIXED(PHPAL_SLI15693_ERR_ISO15693, PH_COMP_PAL_SLI15693);
					break;
				}

				/* Copy response flag to additional info */
				pDataParams->wAdditionalInfo = (*ppRxBuffer)[0];

				/* adjust pointer and length */
				++(*ppRxBuffer);
				--(*pRxLength);
			}

			status = PH_ERR_SUCCESS;
			break;
		default:
			break;
	}

	bFirstBlock[0] = 0U;
	bFirstBlock[1] = 0U;
	bFirstBlock[2] = 0U;
	wTransmitLength = 0U;
	wTempOption = 0U;
	wTempTxLength = 0U;
	pTempTxBuffer = NULL;
	pDataParams->eExchangeState = PHPAL_SLI15693_STATE_IDLE;
	return status;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_ActivateCard(
    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bFlags,
    VAR(uint8, ANFCRL_VAR) bAfi,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
    VAR(uint8, ANFCRL_VAR) bMaskBitLength,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
    )
{
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSlot = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTimeOutNotAllowed = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aMaskBuffer[PHPAL_SLI15693_UID_LENGTH] = {0U};
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMaskByteLength = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCurrMaskBitLength = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLengthDummy = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDataDummy[1] = {0u};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLengthDummy = 0U;

    switch(pDataParams->eActCardState)
    {
		case PHPAL_SLI15693_ACTCARD_START:
			/* Check option byte */
			if ((bOption != PHPAL_SLI15693_ACTIVATE_ADDRESSED) && (bOption != PHPAL_SLI15693_ACTIVATE_SELECTED))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			/* init return value */
			*pMoreCardsAvailable = 0;
			bCurrMaskBitLength = bMaskBitLength;
			pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_INVENTORY;
			/* no break */

		case PHPAL_SLI15693_ACTCARD_INVENTORY:
			/* Perform inventory command */
			status = phpalSli15693_Sw_Inventory(pDataParams, bFlags, bAfi, pMask, bCurrMaskBitLength, pDsfid, pUid);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}

			/* Check for invalid parameter */
			if ((status & PH_ERR_MASK) == PH_ERR_INVALID_PARAMETER)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
				break;
			}

			/* Retrieve mask byte length */
			bMaskByteLength = ((bCurrMaskBitLength % 8U) != 0U) ? ((bCurrMaskBitLength >> 3U) + 1U) : (bCurrMaskBitLength >> 3U);

			/* init mask buffer */
			(void)memset(aMaskBuffer, 0, (size_t)sizeof(aMaskBuffer));
			(void)memcpy(aMaskBuffer, pMask, bMaskByteLength);
			bSlot = 0;
			if ((0U == ((bFlags & PHPAL_SLI15693_FLAG_NBSLOTS))))
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SLOTMAKER;
			}
			else
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_ONESLOT;
				bTimeOutNotAllowed = 1;
			}
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_ACTCARD_SLOTMAKER:
			/* if we have more than one slot, we need to send slot markers (b6 = 0) */
			/* Slot marker loop */
			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				switch (status & PH_ERR_MASK)
				{
					/*  If a CRC error or collision error occurred --> resolve collision */
				case PH_ERR_COLLISION_ERROR:
				case PH_ERR_INTEGRITY_ERROR:

					*pMoreCardsAvailable = 1;

					/* Get bit-length of last valid byte */
					bUidLengthDummy = (uint8)(bCurrMaskBitLength % 8U);

					/* Whole byte is valid -> append slot number to next byte */
					if (bUidLengthDummy == 0U)
					{
						aMaskBuffer[bCurrMaskBitLength >> 3U] = bSlot;
					}
					/* Partial byte is valid */
					else
					{
						/* Fill the invalid bits of the incomplete byte with the 4 bits slot number */
						aMaskBuffer[bCurrMaskBitLength >> 3U] &= (uint8)(0xFFU >> (8U - bUidLengthDummy));
						aMaskBuffer[bCurrMaskBitLength >> 3U] |= (uint8)(bSlot << bUidLengthDummy);

						/* If not all 4 bits of the Slot number fit in the incomplete byte, put the rest in the next byte */
						if (bUidLengthDummy > 4U)
						{
							aMaskBuffer[(bCurrMaskBitLength >> 3U) + 1U] = (uint8)(bSlot >> bUidLengthDummy);
						}
					}

					/* Increment the bit length by the 4 bits slot number */
					bCurrMaskBitLength = bCurrMaskBitLength + 4U;

					/* Start again from Slot number 0 */
					bSlot = 0;
					status = phpalSli15693_Sw_Inventory(pDataParams, bFlags, bAfi, aMaskBuffer, bCurrMaskBitLength, pDsfid, pUid);
					pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP;
					break;

					/* Timeout -> advance to next slot */
				case PH_ERR_IO_TIMEOUT:
					++bSlot;
					pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SENDEOF_LOOP;
					return PH_STATUS_INPROCESS;
					/* No break */

				default:
					pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_START;
					return status;
				}

			}
			if(pDataParams->eActCardState == PHPAL_SLI15693_ACTCARD_SLOTMAKER)
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_FINISH;
			}
			return status;

		case PHPAL_SLI15693_ACTCARD_SENDEOF_LOOP:
			/* Send EOF and increment slot number */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_Sw_SendEof(
				pDataParams,
				PHPAL_SLI15693_EOF_NEXT_SLOT,
				pDsfid,
				pUid,
				&bUidLengthDummy,
				bDataDummy,
				&wDataLengthDummy));
			/* if we ran through all slots, we are done */
			if ((bSlot >= 15U) || (status == PH_ERR_SUCCESS))
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_FINISH;
				return PH_STATUS_INPROCESS;
			}
			pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SLOTMAKER;
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_ACTCARD_ONESLOT:
			/* use only one slot */
			/* Do not allow a time out after the first Inventory command since then, no
			card with the specified mask is present in the field. */
			/* Bit mask loop */
			if (bCurrMaskBitLength < PHPAL_SLI15693_SW_UID_COMPLETE)
			{
				switch (status & PH_ERR_MASK)
				{
					/* If there was a card, the loop is done */
				case PH_ERR_SUCCESS:
					bCurrMaskBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;
					break;

					/* In case of a timeout, no card with the actual mask is in the field, so toggle the last bit of the mask */
				case PH_ERR_IO_TIMEOUT:
					/* Abort, if this bit was already tested */
					if (0U != (bTimeOutNotAllowed))
					{
						pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_START;
						return status;
					}

					/* the bit mask is > 0U, because in the case of bitmask = 0 a timeout can not happen */
					aMaskBuffer[(uint8)(bCurrMaskBitLength - 1U) >> 3U] = aMaskBuffer[(uint8)(bCurrMaskBitLength - 1U) >> 3U] ^ (uint8)(0x01U << (uint8)((bCurrMaskBitLength - 1U) % 8U));
					bTimeOutNotAllowed = 1;
					break;

					/*  If a CRC error or collision error occurred add one bit to the mask. */
				case PH_ERR_COLLISION_ERROR:
				case PH_ERR_INTEGRITY_ERROR:
					/* Note: The value of this bit does not really matter since it will be toggled in case of a timeout */
					*pMoreCardsAvailable = 1;

					++bCurrMaskBitLength;
					bTimeOutNotAllowed = 0;
					break;

					/* If it is an other error than Collision, Crc or Timeout Error the function should return the error */
				default:
					pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_START;
					return status;
				}

				/* Perform next inventory command to perform anti-collision */
				if (bCurrMaskBitLength < PHPAL_SLI15693_SW_UID_COMPLETE)
				{
					status = phpalSli15693_Sw_Inventory(pDataParams, bFlags, bAfi, aMaskBuffer, bCurrMaskBitLength, pDsfid, pUid);
					pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP;
					return status;
				}
			}
			pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_FINISH;
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP:
			PH_CHECK_INPROCESS_FCT(status,
					phpalSli15693_Sw_Inventory(pDataParams, bFlags, bAfi, aMaskBuffer, bCurrMaskBitLength, pDsfid, pUid));
			if ((0U == ((bFlags & PHPAL_SLI15693_FLAG_NBSLOTS))))
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SLOTMAKER;
			}
			else
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_ONESLOT;
			}
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_ACTCARD_FINISH:
			/* no need to proceed if an error occurred. */
			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				/* clear option flag */
				pDataParams->bFlags &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_OPTION;
				break;
			}

			/* Select the card if necessary */
			if (0U != (bOption & PHPAL_SLI15693_ACTIVATE_SELECTED))
			{
				pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_ACTIVATE_SELECTED;
				return PH_STATUS_INPROCESS;
			}

			pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SET_TIMEOUT;
			/* no break */

		case PHPAL_SLI15693_ACTCARD_SET_TIMEOUT:
			/* Set long timeout. */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SetConfig(pDataParams, PHPAL_SLI15693_CONFIG_TIMEOUT_US, PHPAL_SLI15693_TIMEOUT_LONG_US));
			break;

		case PHPAL_SLI15693_ACTCARD_ACTIVATE_SELECTED:
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_Select(pDataParams));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_SET_TIMEOUT;
			return PH_STATUS_INPROCESS;

		default:
			break;
	}
    pDataParams->eActCardState = PHPAL_SLI15693_ACTCARD_START;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_GetSerialNo(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength
										)
{
	/* Return an error if UID is not valid */
	if (pDataParams->bUidBitLength != PHPAL_SLI15693_SW_UID_COMPLETE)
	{
		*pUidLength = 0U;
		return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_SLI15693);
	}

	/* copy the UID */
	(void)memcpy(pUid, pDataParams->pUid, PHPAL_SLI15693_UID_LENGTH);
	*pUidLength = PHPAL_SLI15693_UID_LENGTH;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SetSerialNo(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                    VAR(uint8, ANFCRL_VAR) bUidLength
										)
{
	/* Check for valid UID length */
	if(bUidLength != PHPAL_SLI15693_UID_LENGTH)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
	}

	/* Copy UID and UID length */
	(void)memcpy(pDataParams->pUid, pUid, PHPAL_SLI15693_UID_LENGTH);
	pDataParams->bUidBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SetConfig(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    VAR(uint16, ANFCRL_VAR) wValue
									  )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wValueOld = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempValue = 0U;
	static VAR(uint8, ANFCRL_VAR) bSetConfigState = 0U;

	switch (wConfig)
	{
	case PHPAL_SLI15693_CONFIG_FLAGS:

		/* Retrieve current subcarrier setting */
		PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(
			pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_SUBCARRIER,
			&wValueOld));

		/* Set dual subcarrier if HAL is not already configured for it */
		if (0U != (wValue & PHPAL_SLI15693_FLAG_TWO_SUB_CARRIERS))
		{
			/* NFC mode supports only single sub-carrier mode */
			if(pDataParams->bOpeMode == RD_LIB_MODE_NFC)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			if (wValueOld != PHHAL_HW_SUBCARRIER_DUAL)
			{
				do
				{
					statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams,
										PHHAL_HW_CONFIG_SUBCARRIER,
										PHHAL_HW_SUBCARRIER_DUAL);
				} while (statusTmp == PH_STATUS_INPROCESS);
			}
		}
		/* Set single subcarrier if HAL is not already configured for it */
		else
		{
			if (wValueOld != PHHAL_HW_SUBCARRIER_SINGLE)
			{
				do
				{
					statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams,
										PHHAL_HW_CONFIG_SUBCARRIER,
										PHHAL_HW_SUBCARRIER_SINGLE);
				} while (statusTmp == PH_STATUS_INPROCESS);
			}
		}

		/* Retrieve current datarate setting */
		do
		{
			statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXDATARATE_FRAMING, &wValueOld);
		} while (statusTmp == PH_STATUS_INPROCESS);
		PH_CHECK_SUCCESS(statusTmp);

		/* Set low data rate if HAL is not already configured for it */
		if (0U == (wValue & PHPAL_SLI15693_FLAG_DATA_RATE))
		{
			/* NFC mode supports only HIGH Data Rate */
			if(pDataParams->bOpeMode == RD_LIB_MODE_NFC)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			if (wValueOld != PHHAL_HW_RF_RX_DATARATE_LOW)
			{
				do
				{
					statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams,
							PHHAL_HW_CONFIG_RXDATARATE_FRAMING, PHHAL_HW_RF_RX_DATARATE_LOW);
				} while (statusTmp == PH_STATUS_INPROCESS);
				PH_CHECK_SUCCESS(statusTmp);
			}

		}
		/* Set high data rate if HAL is not already configured for it */
		else
		{
			if (wValueOld != PHHAL_HW_RF_RX_DATARATE_HIGH)
			{
				do
				{
					statusTmp = phhalHw_SetConfig(pDataParams->pHalDataParams,
							PHHAL_HW_CONFIG_RXDATARATE_FRAMING, PHHAL_HW_RF_RX_DATARATE_HIGH);
				} while (statusTmp == PH_STATUS_INPROCESS);
				PH_CHECK_SUCCESS(statusTmp);
			}
		}

		/* retrieve flags */
		pDataParams->bFlags = (uint8)wValue;

		break;
	case PHPAL_SLI15693_CONFIG_TIMEOUT_US:
		if(PHPAL_SLI15693_STATE_IDLE == pDataParams->eSetConfigState)
		{
			if (((uint32)wValue + PHPAL_SLI15693_SW_EXT_TIME_US) > 0xFFFFU)
			{
				/* Return error */
				/* Maximum allowed value is 0xFFC3 (0xFFFF - PHPAL_SLI15693_SW_EXT_TIME_US) */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PARAMETER_OVERFLOW, PH_COMP_PAL_SLI15693);
			}

			/* Extend timeout a little */
			wValue += PHPAL_SLI15693_SW_EXT_TIME_US;

			/* Retrieve current timeout */
			statusTmp = phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
				&wValueOld);

			/* Set the new timeout */
			if ((((statusTmp & PH_ERR_MASK) == PH_ERR_SUCCESS) && (wValue != wValueOld)) ||
				((statusTmp & PH_ERR_MASK) == PH_ERR_PARAMETER_OVERFLOW))
			{
				wTempValue = wValue;
				pDataParams->eSetConfigState = PHPAL_SLI15693_STATE_EXCHANGE;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Return error if the error is other than PH_ERR_PARAMETER_OVERFLOW */
				PH_CHECK_SUCCESS(statusTmp);
			}
		}
		else if(PHPAL_SLI15693_STATE_EXCHANGE == pDataParams->eSetConfigState)
		{
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
					wTempValue));
			wTempValue = 0U;
			pDataParams->eSetConfigState = PHPAL_SLI15693_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);
		}
		else
		{
			/* Do nothing */
		}
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_MS:
		if(PHPAL_SLI15693_STATE_IDLE == pDataParams->eSetConfigState)
		{
			/* Retrieve current timeout */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
				&wValueOld));

			/* Set the new timeout */
			if (wValue != wValueOld)
			{
				wTempValue = wValue;
				pDataParams->eSetConfigState = PHPAL_SLI15693_STATE_EXCHANGE;
				return PH_STATUS_INPROCESS;
			}
		}
		else if(PHPAL_SLI15693_STATE_EXCHANGE == pDataParams->eSetConfigState)
		{
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
					wValue));
			wTempValue = 0U;
			pDataParams->eSetConfigState = PHPAL_SLI15693_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);
		}
		else
		{
			/* Do nothing */
		}
		break;

	case PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING:
		pDataParams->bBuffering = (uint8)wValue;
		break;

	case PHPAL_SLI15693_CONFIG_TXDATARATE:
		if(0U == bSetConfigState)
		{
			if ((pDataParams->bOpeMode == RD_LIB_MODE_NFC) && (wValue != PHPAL_SLI15693_26KBPS_DATARATE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			if (wValue > PHPAL_SLI15693_212KBPS_DATARATE)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			switch (wValue)
			{
				case PHPAL_SLI15693_26KBPS_DATARATE:
					wValue = PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4;
					break;
				case PHPAL_SLI15693_53KBPS_DATARATE:
					wValue = PHHAL_HW_RF_I15693_53KBPS_DATARATE;
					break;
				case PHPAL_SLI15693_106KBPS_DATARATE:
					wValue = PHHAL_HW_RF_DATARATE_106;
					break;
				case PHPAL_SLI15693_212KBPS_DATARATE:
					wValue = PHHAL_HW_RF_DATARATE_212;
					break;
				default:
					break;
			}
			wTempValue = wValue;
			bSetConfigState = 1U;
		}

		if(1U == bSetConfigState)
		{
			/* Set the new TX data rate */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING, wTempValue));
			PH_BREAK_ON_FAILURE(statusTmp);
		}
		break;

	case PHPAL_SLI15693_CONFIG_RXDATARATE:
		if(0U == bSetConfigState)
		{
			if((pDataParams->bOpeMode == RD_LIB_MODE_NFC) && (wValue != PHPAL_SLI15693_26KBPS_DATARATE))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			if(wValue > PHPAL_SLI15693_106KBPS_DATARATE)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			switch(wValue)
			{
				case PHPAL_SLI15693_26KBPS_DATARATE:
					wValue = PHHAL_HW_RF_RX_DATARATE_HIGH;
					break;
				case PHPAL_SLI15693_53KBPS_DATARATE:
					wValue = PHHAL_HW_RF_RX_DATARATE_FAST_HIGH;
					break;
				case PHPAL_SLI15693_106KBPS_DATARATE:
					wValue = PHHAL_HW_RF_DATARATE_106;
					break;
				default:
					break;
			}
			wTempValue = wValue;
			bSetConfigState = 1U;
		}

		if(1U == bSetConfigState)
		{
			/* Set the new RX data rate */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXDATARATE_FRAMING, wTempValue));
			PH_BREAK_ON_FAILURE(statusTmp);
		}
		break;

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_SLI15693);
	}

	bSetConfigState = 0U;
	wTempValue = 0U;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_GetConfig(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wConfig,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;

	switch (wConfig)
	{
	case PHPAL_SLI15693_CONFIG_FLAGS:
		*pValue = pDataParams->bFlags;
		break;

	case PHPAL_SLI15693_CONFIG_ADD_INFO:
		*pValue = pDataParams->wAdditionalInfo;
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_US:
		/* Get HAL timeout value */
		PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(
			pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
			pValue));

		/* Remove timeout extension */
		*pValue -= PHPAL_SLI15693_SW_EXT_TIME_US;
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_MS:
		/* Get HAL timeout value */
		PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(
			pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
			pValue));

		break;

	case PHPAL_SLI15693_CONFIG_TXDATARATE:
		/* Get HAL Tx Data Rate value */
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING, pValue));
		PH_BREAK_ON_FAILURE(statusTmp);

		/* Map the HAL TX BaudRates to generic 15693 BaudRates */
		switch (*pValue) {
		case PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4:
			*pValue = PHPAL_SLI15693_26KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_I15693_53KBPS_DATARATE:
			*pValue = PHPAL_SLI15693_53KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_DATARATE_106:
			*pValue = PHPAL_SLI15693_106KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_DATARATE_212:
			*pValue = PHPAL_SLI15693_212KBPS_DATARATE;
			break;
		default:
			break;
		}
		break;

	case PHPAL_SLI15693_CONFIG_RXDATARATE:
		/* Get HAL Rx Data Rate value */
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_GetConfig(pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXDATARATE_FRAMING,pValue));
		PH_BREAK_ON_FAILURE(statusTmp);

		/* Map the HAL RX BaudRates to generic 15693 BaudRates */
		switch(*pValue)
		{
		case PHHAL_HW_RF_RX_DATARATE_HIGH:
			*pValue = PHPAL_SLI15693_26KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_RX_DATARATE_FAST_HIGH:
			*pValue = PHPAL_SLI15693_53KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_DATARATE_106:
			*pValue = PHPAL_SLI15693_106KBPS_DATARATE;
			break;
		case PHHAL_HW_RF_DATARATE_212:
			*pValue = PHPAL_SLI15693_212KBPS_DATARATE;
			break;
		default:
			break;
		}
		break;


	case PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING:
		*pValue = pDataParams->bBuffering;
		break;

	default:
		return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_SLI15693);
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryRead(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bBlockNo,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
					)
{
	return phpalSli15693_Sw_InventoryEx(
		pDataParams,
		PHPAL_SLI15693_SW_CMD_INVENTORY_READ,
		bFlags,
		bAfi,
		pMask,
		bMaskBitLength,
		bBlockNo,
		wNoOfBlocks,
		pUid,
		bUidLength,
		pData,
		wLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryReadExtended(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bExtendedOptions,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
          VAR(uint8, ANFCRL_VAR) bBlockNo,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
					)
{
	return phpalSli15693_Sw_InventoryExt(
			pDataParams,
			PHPAL_SLI15693_SW_CMD_INVENTORY_READ,
			bFlags,
			bAfi,
			1U,
			bExtendedOptions,
			pCID,
			pMask,
			bMaskBitLength,
			bBlockNo,
			wNoOfBlocks,
			pCidOut,
			pUid,
			pUidLength,
			pData,
			wLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryRead(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bBlockNo,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
					)
{
	return phpalSli15693_Sw_InventoryEx(
		pDataParams,
		PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ,
		bFlags,
		bAfi,
		pMask,
		bMaskBitLength,
		bBlockNo,
		wNoOfBlocks,
		pUid,
		pUidLength,
		pData,
		pDataLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryReadExtended(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bExtendedOptions,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
          VAR(uint8, ANFCRL_VAR) bBlockNo,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
					)
{
	return phpalSli15693_Sw_InventoryExt(
			pDataParams,
			PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ,
			bFlags,
			bAfi,
			1U,
			bExtendedOptions,
			pCID,
			pMask,
			bMaskBitLength,
			bBlockNo,
			wNoOfBlocks,
			pCidOut,
			pUid,
			bUidLength,
			pData,
			wLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryPageRead(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bPageNo,
          VAR(uint16, ANFCRL_VAR) wNoOfPages,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
					)
{
	return phpalSli15693_Sw_InventoryEx(
		pDataParams,
		PHPAL_SLI15693_SW_CMD_INVENTORY_PAGE_READ,
		bFlags,
		bAfi,
		pMask,
		bMaskBitLength,
		bPageNo,
		wNoOfPages,
		pUid,
		pUidLength,
		pData,
		pDataLength);
}

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryPageRead(
          P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
          VAR(uint8, ANFCRL_VAR) bFlags,
          VAR(uint8, ANFCRL_VAR) bAfi,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength,
          VAR(uint8, ANFCRL_VAR) bPageNo,
          VAR(uint16, ANFCRL_VAR) wNoOfPages,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
					)
{
	return phpalSli15693_Sw_InventoryEx(
		pDataParams,
		PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ,
		bFlags,
		bAfi,
		pMask,
		bMaskBitLength,
		bPageNo,
		wNoOfPages,
		pUid,
		pUidLength,
		pData,
		pDataLength);
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryEx(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bCmd,
                    VAR(uint8, ANFCRL_VAR) bFlags,
                    VAR(uint8, ANFCRL_VAR) bAfi,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                    VAR(uint8, ANFCRL_VAR) bPage_Block_No,
                    VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
										)
{
	return  phpalSli15693_Sw_InventoryExt(
			pDataParams,
			bCmd,
			bFlags,
			bAfi,
			0U,
			0U,
			NULL,
			pMask,
			bMaskBitLength,
			bPage_Block_No,
			wNoOfPages_Blocks,
			NULL,
			pUid,
			pUidLength,
			pData,
			pDataLength
			);
}


FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryExt(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bCmd,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  VAR(uint8, ANFCRL_VAR) bExtended,
                  VAR(uint8, ANFCRL_VAR) bExtendedOptions,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bPage_Block_No,
                  VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									)
{
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = 0U;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBuffer[15] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdBufferLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmdOffset = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMaskByteLength = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pResp = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStoredUidLength = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wAsk = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTimeout = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrBlocksToRead = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrBlockNo = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wMaxNoBlocks = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAllBlocksRead = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFirst = 0U;

	switch (pDataParams->eInventoryState)
	{
		case PHPAL_SLI15693_INVENTORY_START:
			/* Reset UID and data length */
			pDataParams->bUidBitLength = 0;

			if(((pUidLength == NULL) || (pUid == NULL)) || ((0U != ((bExtendedOptions & PHPAL_SLI15693_FLAG_SKIP_DATA))) && ((pDataLength == NULL) || (pData == NULL))))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			/* If Extended Option is looking for CID response then CID should not be null */
			if ((0U != ((bExtendedOptions & PHPAL_SLI15693_FLAG_CID_COMPARE))) && (pCID == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}
			/* If Extended Option is looking for CID response then CID should not be null */
			if((0U != ((bExtendedOptions & PHPAL_SLI15693_FLAG_CID_RESPONSE))) && (pCIDOut == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			*pUidLength = 0U;
			*pDataLength = 0U;
			bCmdBufferLen = 0U;
			bCmdOffset = 0U;
			bStoredUidLength = 0U;
			wAsk = 0U;
			wTimeout = 0U;
			wCurrBlocksToRead = 0U;
			wCurrBlockNo = 0U;
			wMaxNoBlocks = 0U;
			bAllBlocksRead = 0U;
			bFirst = 0U;
			/* first of all we check the bMaskBitLength according to ISO/IEC15693, 8.1, assuming
			the inventory flag to be set, bit b6 defines the number of slots
			b6 = 1: --> one slot --> mask length = [0 .. 64] bits
			b6 = 0: --> 16 slots --> mask length = [0 .. 60] bits */
			if (((0U != ((bFlags & PHPAL_SLI15693_FLAG_NBSLOTS))) && (bMaskBitLength > 64U)) ||
				((0U == ((bFlags & PHPAL_SLI15693_FLAG_NBSLOTS))) && (bMaskBitLength > 60U)))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
			}

			/* Number of Pages/Blocks check */
			if (bCmd != PHPAL_SLI15693_SW_CMD_INVENTORY)
			{
				/* Number of Pages/Blocks can't be zero */
				if (wNoOfPages_Blocks == 0U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
				}

				/* check if the block number exceeds the limit */
				if (((uint16)bPage_Block_No + wNoOfPages_Blocks) >= PHPAL_SLI15693_SW_MAX_BLOCKS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_SLI15693);
				}
			}

			/* Add command code */
			bCmdBuffer[bCmdBufferLen++] = bCmd;

			/* Apply flag settings */
			PH_CHECK_SUCCESS_FCT(statusTmp, phpalSli15693_SetConfig(
				pDataParams,
				PHPAL_SLI15693_CONFIG_FLAGS,
				bFlags));


			/* Overwrite datarate for fast inventory (page-)read */
            if ((bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ) ||
                (bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ))
            {
                if (0U != (bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
                {
                    pDataParams->eInventoryState = PHHAL_SLI15693_INVENTORY_CONFIG_FAST_HIGH;
                    return PH_STATUS_INPROCESS;
                }
                else
                {
                    pDataParams->eInventoryState = PHHAL_SLI15693_INVENTORY_CONFIG_FAST_LOW;
                    return PH_STATUS_INPROCESS;
                }
            }
            pDataParams->eInventoryState = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHHAL_SLI15693_INVENTORY_CONFIG_FAST_HIGH:
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_SetConfig(pDataParams->pHalDataParams,
                                            PHHAL_HW_CONFIG_RXDATARATE_FRAMING,
                                            PHHAL_HW_RF_RX_DATARATE_FAST_HIGH));
            if(statusTmp != PH_ERR_SUCCESS)
            {
                pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_START;
                return statusTmp;
            }
            pDataParams->eInventoryState = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS;
            return PH_STATUS_INPROCESS;
        case PHHAL_SLI15693_INVENTORY_CONFIG_FAST_LOW:
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_SetConfig(pDataParams->pHalDataParams,
                                            PHHAL_HW_CONFIG_RXDATARATE_FRAMING,
                                            PHHAL_HW_RF_RX_DATARATE_FAST_LOW));
            if(statusTmp != PH_ERR_SUCCESS)
            {
                pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_START;
                return statusTmp;
            }
            pDataParams->eInventoryState = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS;
            /* no break */
        case PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS:
            /* check if AFI shall be sent: */
            if ((0U != ((bFlags & PHPAL_SLI15693_FLAG_AFI))) && (0U != ((bFlags & PHPAL_SLI15693_FLAG_INVENTORY))))
			{
				bCmdBuffer[bCmdBufferLen++] = bAfi;
			}

			/* Add mask length */
			/* Making the MSB of mask length byte as 1 to show extended mode */
			/* In case of extended mode add the extended option in command */
			if (0U != (bExtended))
			{
				bCmdBuffer[bCmdBufferLen++] = bMaskBitLength | PHPAL_SLI15693_FLAG_INVENTORY_READ_EXTENSION;
				bCmdBuffer[bCmdBufferLen++] = bExtendedOptions;
				if (0U != (bExtendedOptions & PHPAL_SLI15693_FLAG_CID_COMPARE))
				{
					bCmdBuffer[bCmdBufferLen++] = pCID[0];
					bCmdBuffer[bCmdBufferLen++] = pCID[1];
				}
			}
			else
			{
				bCmdBuffer[bCmdBufferLen++] = bMaskBitLength;
			}

			/* Retrieve mask byte length */
			bMaskByteLength = ((bMaskBitLength % 8U) != 0U) ? ((bMaskBitLength >> 3U) + 1U) : (bMaskBitLength >> 3U);

			/* prepare mask in dataparams */
			(void)memcpy(pDataParams->pUid, pMask, bMaskByteLength );
			pDataParams->bUidBitLength = bMaskBitLength;

			/* prepare mask to send */
			(void)memcpy(&bCmdBuffer[bCmdBufferLen], pMask, bMaskByteLength );
			bCmdBufferLen = bCmdBufferLen + bMaskByteLength;

			/* mask out invalid bits */
			if (0U != (bMaskBitLength & 0x07U))
			{
				bCmdBuffer[bCmdBufferLen - 1U] &= (uint8)(0xFFU >> (8U - (bMaskBitLength & 0x07U)));
			}

            /* Get the ASK 100 Condition */
            statusTmp = phhalHw_GetConfig(pDataParams->pHalDataParams,PHHAL_HW_CONFIG_ASK100,&wAsk);
            if(statusTmp != PH_ERR_SUCCESS)
            {
                pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_START;
                return statusTmp;
            }
			/* Calculate Timeout based on ask and baud rate */
			if(wAsk != 0U)
			{
				if ((bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ) ||
					(bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ))
				{
					if(0U != (bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTHIGH_SOF_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTLOW_SOF_US;
					}
				}
				else
				{
					if(0U != (bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_HIGH_SOF_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_LOW_SOF_US;
					}
				}
			}
			else
			{
				if ((bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ) ||
					(bCmd == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ))
				{
					if(0U != (bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTHIGH_NRT_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_FASTLOW_NRT_US;
					}
				}
				else
				{
					if(0U != (bFlags & PHPAL_SLI15693_FLAG_DATA_RATE))
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_HIGH_NRT_US;
					}
					else
					{
						wTimeout = PHPAL_SLI15693_TIMEOUT_SHORT_US + PHPAL_SLI15693_SW_LOW_NRT_US;
					}
				}
			}
            pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_TIMEOUT_US;
            /* no break */
        case PHPAL_SLI15693_INVENTORY_TIMEOUT_US:
            /* Set  timeout. */
            PH_CHECK_INPROCESS_FCT(statusTmp,phpalSli15693_SetConfig(pDataParams,PHPAL_SLI15693_CONFIG_TIMEOUT_US,
                                                                      wTimeout));
            if(statusTmp != PH_ERR_SUCCESS)
            {
                pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_START;
                return statusTmp;
            }
			/* Update the command offset variable. */
			bCmdOffset = bCmdBufferLen;

			/* If buffering is set. */
			if((pDataParams->bBuffering) != 0U)
			{
				/* Update the maximum number of blocks with respect to Option flag setting. The value for the blocks is fixed to 60 and 40 to avoid multiple
				 * handling of different data in response. RD70x can respond with more amount of data but CM1 can not. So fixing the blocks count to a lower
				 * value.
				 */
				wMaxNoBlocks = (uint8) (((bFlags & PHPAL_SLI15693_FLAG_OPTION) != 0U) ? 40U : 60U);

				/* Blocks to read. */
				wCurrBlocksToRead = wMaxNoBlocks;

				/* Update the number of blocks to read if its less than the internal required one. */
				if(wNoOfPages_Blocks < wMaxNoBlocks)
				{
					wCurrBlocksToRead = wNoOfPages_Blocks;
					bAllBlocksRead = 1U;
				}
			}
			else
			{
				wCurrBlocksToRead = wNoOfPages_Blocks;
				bAllBlocksRead = 1U;
			}


			if((((pDataParams->bFlags & PHPAL_SLI15693_FLAG_INVENTORY) == 0U) && ((pDataParams->bFlags & PHPAL_SLI15693_FLAG_ADDRESSED) != 0U)))
			{
				pDataParams->bExplicitlyAddressed = 1U;
			}


			/* Set First variable. This variable will be used to validate the response only once in case if chaining is enabled. */
			bFirst = PH_ON;
			pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_INIT;
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_INVENTORY_INIT:
			/* Exchange the information. */
			/* Page (or block) number and count */
			if (bCmd != PHPAL_SLI15693_SW_CMD_INVENTORY)
			{
			 /* Adjust number of blocks. Adjustment is made because the User or the application will pass
			 * the number of blocks starting from 1 to N. But as per Iso15693 specification the number
			 * of blocks ranges from 0 - (N - 1).
			 */
				--wCurrBlocksToRead;

				if (!((bExtended != 0U) && ((bExtendedOptions & PHPAL_SLI15693_FLAG_SKIP_DATA) != 0U)))
				{
					bCmdBuffer[bCmdOffset++] = (uint8) ((wCurrBlockNo + bPage_Block_No) & 0x00FFU);
					bCmdBuffer[bCmdOffset++] = (uint8) wCurrBlocksToRead;
				}
			}
			pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_LOOP;
			/*no break*/

		case PHPAL_SLI15693_INVENTORY_LOOP:
			status = phpalSli15693_Exchange(
				pDataParams,
				PH_EXCHANGE_DEFAULT,
				bCmdBuffer,
				bCmdOffset,
				&pResp,
				&wRespLength);
			if (status == PH_STATUS_INPROCESS)
			{
				return status;
			}

			/* Clear INVENTORY, AFI and NBSLOTS flag */
			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				pDataParams->bFlags &= (uint8) ~(uint8) (PHPAL_SLI15693_FLAG_INVENTORY
						| PHPAL_SLI15693_FLAG_AFI | PHPAL_SLI15693_FLAG_NBSLOTS);
			}

			/* Verify the exchange status. */
			PH_BREAK_ON_FAILURE(status);

			/* Extracting  the CID as sent by the VICC. */
			if ((bExtended != 0U) && ((bExtendedOptions & PHPAL_SLI15693_FLAG_CID_RESPONSE) != 0U))
			{
				phTools_memcpy(pCIDOut, pResp, 2U);  /* PRQA S 3200 */

				/* Update the response pointer address and length to Skip CID. */
				pResp = &pResp[2];
				wRespLength -= 2U;
			}

			/* Set the length (amount) of expected UID bytes. */
			if (bCmd == PHPAL_SLI15693_SW_CMD_INVENTORY)
			{
				/* The response length should be exactly the complete UID */
				if (wRespLength != (1U + PHPAL_SLI15693_UID_LENGTH))
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
					break;
				}

				/* Copy the DSFID to the data buffer. */
				pData[0] = pResp[0];
				*pDataLength = 1U;

				/* Store the UID */
				(void)memcpy(pDataParams->pUid, &pResp[1], PHPAL_SLI15693_UID_LENGTH); /* PRQA S 3200 */
				pDataParams->bUidBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;

				/* Return the UID */
				(void)memcpy(pUid, pDataParams->pUid, PHPAL_SLI15693_UID_LENGTH); /* PRQA S 3200 */
				*pUidLength = PHPAL_SLI15693_UID_LENGTH;
			}
			else
			{
				if ((bFlags & PHPAL_SLI15693_FLAG_OPTION) != 0U)
				{
					*pUidLength = PHPAL_SLI15693_UID_LENGTH - bStoredUidLength;

					/* The response length should not be less than the remaining UID. */
					if(bFirst != 0U)
					{
						bStoredUidLength = pDataParams->bUidBitLength >> 3U;
						*pUidLength = PHPAL_SLI15693_UID_LENGTH - bStoredUidLength;

						/* Update the UID length if extended. */
						if((bExtended != 0U) && ((bExtendedOptions & PHPAL_SLI15693_FLAG_UID_MODE) != 0U))
						{
							*pUidLength = PHPAL_SLI15693_UID_LENGTH;
						}
					}
					/* Validate the response length against UID length. */
					if (wRespLength < (*pUidLength))
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
						break;
					}

					if (bStoredUidLength < PHPAL_SLI15693_UID_LENGTH)
					{
						if ((*pUidLength) == 0U)
						{
							status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_SLI15693);
							break;
						}
						/* Return the received (partial) UID */
						(void)memcpy(pUid, pResp, (size_t)(*pUidLength)); /* PRQA S 3200 */

						/* We need to merge the contents of the mask buffer and the received data */
						if ((bMaskBitLength % 8U) != 0u)
						{
							if (bStoredUidLength < 7U)
							{
								/* copy the UID bytes we received from the card */
								(void)memcpy(&(pDataParams->pUid[bStoredUidLength + 1U]), &pResp[1], (size_t)(*pUidLength)-1U); /* PRQA S 3200 */
							}

							/* merge mask-bits with received bits */
							pDataParams->pUid[bStoredUidLength] |= pResp[0];
						}
						else
						{
							/* Copy the UID bytes we received from the card */
							(void)memcpy(&(pDataParams->pUid[bStoredUidLength]), pResp, *pUidLength); /* PRQA S 3200 */
						}
					}

					/* Update UID length. */
					pDataParams->bUidBitLength = PHPAL_SLI15693_SW_UID_COMPLETE;

					/* Shift pointer and length */
					pResp = &pResp[*pUidLength];
					wRespLength = (uint16) (wRespLength - *pUidLength);
				}
				/* Copy the received data to internal buffer. */
				phTools_memcpy(&pData[*pDataLength], pResp, wRespLength);         /* PRQA S 3200 */
				*pDataLength += wRespLength;
			}

			/* Update the variables to read the remaining data. */
			wCurrBlockNo += wMaxNoBlocks;

			/* Update the Current blocks to read. */
			wCurrBlocksToRead = wMaxNoBlocks;

			/* Reset the command buffer offset. */
			bCmdOffset = bCmdBufferLen;

			/* Set the remaining blocks to read. */
			if((wNoOfPages_Blocks - wCurrBlockNo) < wMaxNoBlocks)
			{
				wCurrBlocksToRead = (uint16) (wNoOfPages_Blocks - wCurrBlockNo);
			}

			/* Set the flag to finish the loop. */
			if((wNoOfPages_Blocks * 4U) == *pDataLength)
			{
				bAllBlocksRead = 1;
			}

			/* Set First variable. This variable will be used to validate the response only once in case if chaining is enabled. */
			bFirst = PH_OFF;

			if(bAllBlocksRead == 0U)
			{
				pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_INIT;
			}
			else
			{
				pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_FINISH;
			}
			return PH_STATUS_INPROCESS;

		case PHPAL_SLI15693_INVENTORY_FINISH:
			/* Clear INVENTORY, AFI and NBSLOTS flag */
			pDataParams->bFlags &= (uint8) ~(uint8) (PHPAL_SLI15693_FLAG_INVENTORY
					| PHPAL_SLI15693_FLAG_AFI | PHPAL_SLI15693_FLAG_NBSLOTS);

			pDataParams->bExplicitlyAddressed = 0;

			/* Error check */
			PH_BREAK_ON_FAILURE(status);

			/* set addressed flag */
			pDataParams->bFlags |= PHPAL_SLI15693_FLAG_ADDRESSED;
			break;
		default:
			break;
	}

	pDataParams->eInventoryState = PHPAL_SLI15693_INVENTORY_START;
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_SLI15693_SW */

#ifdef __cplusplus
}
#endif
