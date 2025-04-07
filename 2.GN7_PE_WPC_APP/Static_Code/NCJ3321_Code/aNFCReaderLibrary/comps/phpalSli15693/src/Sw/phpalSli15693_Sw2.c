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
*   @file    phpalSli15693_Sw2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalSli156932 ISO/IEC 15693 
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
#include <phpalSli156932.h>
#include <ph_RefDefs2.h>
#include <phhalHw2.h>
#include <phTools2.h>

#ifdef  NXPBUILD__PHPAL_SLI15693_SW2
#include "phpalSli15693_Sw2.h"
#include "phpalSli15693_Sw_Int2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli15693_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_SW_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalSli15693_Sw2.h header file are of the same vendor */
#if (PHPALSLI15693_SW_VENDOR_ID_C2 != PHPALSLI15693_SW_VENDOR_ID2)
    #error "phpalSli15693_Sw2.c and phpalSli15693_Sw2.h have different vendor ids"
#endif
/* Check if current file and phpalSli15693_Sw2.h header file are of the same Autosar version */
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2    != PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION_C2 != PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalSli15693_Sw2.c and phpalSli15693_Sw2.h are different"
#endif
/* Check if current file and phpalSli15693_Sw2.h header file are of the same Software version */
#if ((PHPALSLI15693_SW_SW_MAJOR_VERSION_C2 != PHPALSLI15693_SW_SW_MAJOR_VERSION2) || \
     (PHPALSLI15693_SW_SW_MINOR_VERSION_C2 != PHPALSLI15693_SW_SW_MINOR_VERSION2) || \
     (PHPALSLI15693_SW_SW_PATCH_VERSION_C2 != PHPALSLI15693_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalSli15693_Sw2.c and phpalSli15693_Sw2.h are different"
#endif
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
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
#ifdef  NXPBUILD__PHPAL_SLI15693_SW2
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#if (defined(NXPBUILD__PH_LOG_EX2) && !defined(PH_LIB_LOG_DISABLE2))
static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) TAG2 = "SLI15693|";
#endif

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_Init2(
                 P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
								 )
{
	PH_ASSERT_NULL2 (pDataParams2);
	PH_ASSERT_NULL2 (pHalDataParams2);

	/* parameter structure length check */
	if (sizeof(phpalSli15693_Sw_DataParams_t2) != wSizeOfDataParams2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_SLI156932);
	}

	/* init private data */
	pDataParams2->wId2                       = PH_COMP_PAL_SLI156932 | PHPAL_SLI15693_SW_ID2;
	pDataParams2->pHalDataParams2            = pHalDataParams2;
	pDataParams2->wAdditionalInfo2           = 0U;
	pDataParams2->bFlags2                    = PHPAL_SLI15693_SW_FLAGS_DEFAULT2;
	pDataParams2->bUidBitLength2             = 0U;
	pDataParams2->bExplicitlyAddressed2      = 0U;
	pDataParams2->bOpeMode2                  = RD_LIB_MODE_ISO2; /* Default Mode is ISO */
	pDataParams2->bBuffering2                = 0U;
	pDataParams2->bAlICodeStateMachineState2 = 0U;

	/* reset state machine */
	pDataParams2->eSendEofState2             = PHPAL_SLI15693_SENDEOF_STATE_IDLE2;
	pDataParams2->eActCardState2		       = PHPAL_SLI15693_ACTCARD_START2;
	pDataParams2->eInventoryState2	       = PHPAL_SLI15693_INVENTORY_START2;
	pDataParams2->eStayQuietState2	       = PHPAL_SLI15693_STATE_IDLE2;
	pDataParams2->eStayQuietPersistentState2 = PHPAL_SLI15693_STATE_IDLE2;
	pDataParams2->eSelectState2              = PHPAL_SLI15693_STATE_IDLE2;
	pDataParams2->eResetToReadyState2        = PHPAL_SLI15693_STATE_IDLE2;
	pDataParams2->eExchangeState2            = PHPAL_SLI15693_STATE_IDLE2;
	pDataParams2->eSetConfigState2           = PHPAL_SLI15693_STATE_IDLE2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_Inventory2(
                    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint8, ANFCRL_VAR) bFlags2,
                    VAR(uint8, ANFCRL_VAR) bAfi2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2
									  )
{
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidLength2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLength2 = 0U;

	return phpalSli15693_Sw_InventoryEx2(
		pDataParams2,
		PHPAL_SLI15693_SW_CMD_INVENTORY2,
		bFlags2,
		bAfi2,
		pMask2,
		bMaskBitLength2,
		0U,
		0U,
		pUid2,
		&bUidLength2,
		pDsfid2,
		&wDataLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_SendEof2(
                  P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint8, ANFCRL_VAR) bOption2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusExchange2 = PH_ERR_SUCCESS2;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bStoredUidLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wAsk2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTimeout2 = 0U;

	switch(pDataParams2->eSendEofState2)
	{
		case PHPAL_SLI15693_SENDEOF_STATE_IDLE2:
			/* Check bOption2 */
			switch (bOption2)
			{
				case PHPAL_SLI15693_EOF_NEXT_SLOT2:
				case PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2:
				case PHPAL_SLI15693_EOF_WRITE_ALIKE2:
				case PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			/* Reset UID and data lengths */
			*pDsfid2 = 0U;
			*pUidLength2 = 0U;
			*pDataLength2 = 0U;
			pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_WRITE_ALIKE_WITH_WAIT2;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_WRITE_ALIKE_WITH_WAIT2:
			/* if requested, wait ~20ms upon sending EOF */
			if (bOption2 == PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2)
			{
				/* in case of write alike commands wait 20 ms. */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Wait2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_TIME_MICROSECONDS2,
					PHPAL_SLI15693_TIMEOUT_LONG_US2));
				if(statusTmp2 != PH_ERR_SUCCESS2){
					status2 = statusTmp2;
				}
				PH_BREAK_ON_FAILURE2(status2);
			}
			else
			{
				/* Do nothing */
			}
			pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_GET_TIMEOUT2;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_GET_TIMEOUT2:
			/* Get the ASK 100 Condition */
			PH_CHECK_FAILURE_FCT2(status2, phhalHw_GetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_ASK1002,
				&wAsk2));

			if(bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT2)
			{
				if(0U != (wAsk2))
				{
					if(0U != (pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_HIGH_SOF_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_LOW_SOF_US2;
					}
				}
				else
				{
					if(0U != (pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_HIGH_NRT_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_LOW_NRT_US2;
					}
				}
				pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT2;
			}
			else if(bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2)
			{
				if(0U != (wAsk2))
				{
					if(0U != (pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTHIGH_SOF_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTLOW_SOF_US2;
					}
				}
				else
				{
					if(0U != (pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTHIGH_NRT_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTLOW_NRT_US2;
					}
				}

				pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT2;
			}
			else
			{
				/* Set short timeout. */
				wTimeout2 = PHPAL_SLI15693_SW_TIMEOUT_SLOT_US2;
				pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT2;
			}
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT2:
			/* Set  timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
				wTimeout2));
			PH_BREAK_ON_FAILURE2(status2);

			pDataParams2->eSendEofState2 =  PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START12;
			return PH_STATUS_INPROCESS2;
			/* no break */

		case PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START12:
			/* Disable SOF, so only EOF is sent */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_SYMBOL_START2,
				PH_OFF2));
			PH_BREAK_ON_FAILURE2(status2);

			MSG_LOG2(TAG2, ">>> SendEof Option: %X\r\n", bOption2);
			pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_SEND2;
			return PH_STATUS_INPROCESS2;
			/*no break*/
		case PHPAL_SLI15693_SENDEOF_STATE_SEND2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				PH_EXCHANGE_DEFAULT2,
				NULL,
				0,
				&pResp2,
				&wRespLength2));
			MSG_LOG2(TAG2, "<<< SendEof status2: %X\r\n", status2);
			statusExchange2 = status2;
			pDataParams2->eSendEofState2 =  PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START22;
			return PH_STATUS_INPROCESS2;
			/* no break */

		case PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START22:
			/* Reset HAL to send SOF and EOF */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_SYMBOL_START2,
				PHHAL_HW_SYMBOL_I15693_SOF2));

			status2 = statusExchange2;
			PH_BREAK_ON_FAILURE2(status2);

			if(statusTmp2 != PH_ERR_SUCCESS2){
				status2 = statusTmp2;
			}

			/* Check Success */
			PH_BREAK_ON_FAILURE2(status2);

			/* Check RespLength */
			if (wRespLength2 == 0U)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
				break;
			}

			/* check error flag */
			if (0U != (pResp2[0] & PHPAL_SLI15693_FLAG_RESP_ERROR2))
			{
				/* check the length in case of error */
				if (wRespLength2 != 2U)
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
					break;
				}

				pDataParams2->wAdditionalInfo2 = pResp2[1];
				status2 = PH_ADD_COMPCODE_FIXED2(PHPAL_SLI15693_ERR_ISO156932, PH_COMP_PAL_SLI156932);
				break;
			}

			if (bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT2)
			{
				/* ignore flag byte */
				++pResp2;
				--wRespLength2;

				/* the UID is only returned on a next slot command. */
				if (wRespLength2 != (1u + PHPAL_SLI15693_UID_LENGTH2))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
					break;
				}

				/* Copy the DSFID to the data buffer */
				*pDsfid2 = pResp2[0];

				/* retrieve the UID */
				(void)memcpy(pDataParams2->pUid2, &pResp2[1], PHPAL_SLI15693_UID_LENGTH2);
				pDataParams2->bUidBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;

				/* return the UID */
				(void)memcpy(pUid2, &pResp2[1], PHPAL_SLI15693_UID_LENGTH2);
				*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2;

				/* set addressed flag */
				pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;
			}
			else if (bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2)
			{
				/* ignore flag byte */
				++pResp2;
				--wRespLength2;

				/* Option flag is set -> we also received (partial) UID */
				if (0U != (pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_OPTION2))
				{
					/* The response length should not be less than the remaining UID */
					bStoredUidLength2 = pDataParams2->bUidBitLength2 >> 3U;
					*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2 - bStoredUidLength2;
					if (wRespLength2 < *pUidLength2)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
						break;
					}

					if (bStoredUidLength2 < PHPAL_SLI15693_UID_LENGTH2)
					{
						/* We need to merge the contents of the mask buffer and the received data */
						if (0U != (pDataParams2->bUidBitLength2 % 8U))
						{
							if (bStoredUidLength2 < 7U)
							{
								/* copy the UID bytes we received from the card */
								(void)memcpy(&(pDataParams2->pUid2[bStoredUidLength2 + 1U]), &pResp2[1], ((uint32)(*pUidLength2)-1U));
							}

							/* merge mask-bits with received bits */
							pDataParams2->pUid2[bStoredUidLength2] |= pResp2[0];
						}
						else
						{
							/* copy the UID bytes we received from the card */
							(void)memcpy(&(pDataParams2->pUid2[bStoredUidLength2]), pResp2, *pUidLength2);
						}

						/* Return the received (partial) UID */
						(void)memcpy(pUid2, pResp2, *pUidLength2);
					}

					/* UID is now complete */
					pDataParams2->bUidBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;

					/* shift pointer and length */
					pResp2 = &pResp2[*pUidLength2];
					wRespLength2 = wRespLength2 - *pUidLength2;
				}

				/* copy the received data to the provided buffer */
				(void)memcpy(pData2, pResp2, wRespLength2);

				/* the remaining bytes of the response are the data bytes */
				*pDataLength2 = wRespLength2;

				/* set addressed flag */
				pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;
			}
			else
			{
				/* 1 byte is only returned on a eof for a write alike command. */
				if (wRespLength2 != 1U)
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
					break;
				}
			}

			pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_FINISH2;
			return PH_STATUS_INPROCESS2;
			/*no break*/

		case PHPAL_SLI15693_SENDEOF_STATE_FINISH2:
			if ((bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT2) || (bOption2 == PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2))
			{
				/* wait T2 PH_CHECK_SUCCESS_FCT2() */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Wait2(pDataParams2->pHalDataParams2, PHHAL_HW_TIME_MICROSECONDS2, PHPAL_SLI15693_SW_T2_WAITING_TIME2));
			}
			else
			{
				status2 = PH_ERR_SUCCESS2;
			}
			break;
	}

	bStoredUidLength2 = 0U;
	wAsk2 = 0U;
	wTimeout2 = 0U;
	pResp2 = NULL;
	wRespLength2 = 0U;
	pDataParams2->eSendEofState2 = PHPAL_SLI15693_SENDEOF_STATE_IDLE2;
	if(status2 != PH_ERR_SUCCESS2)
	{
		status2 = PH_ADD_COMPCODE2(status2, PH_COMP_PAL_SLI156932);
	}
	statusExchange2 = PH_ERR_SUCCESS2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_StayQuiet2(
                                      P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                      )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;

	switch (pDataParams2->eStayQuietState2)
	{
		case PHPAL_SLI15693_STATE_IDLE2:
			/* clear selected flag */
			pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED2;

			/* set addressed flag */
			pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;

			/* reset to ready command */
			aCmd2[0] = PHPAL_SLI15693_SW_CMD_STAY_QUIET2;

			pDataParams2->eStayQuietState2	= PHPAL_SLI15693_STATE_SET_TIMEOUT2;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT2:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
				PHPAL_SLI15693_TIMEOUT_SHORT_US2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eStayQuietState2	= PHPAL_SLI15693_STATE_EXCHANGE2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE2:
			/* Exchange command */
			status2 = phpalSli15693_Exchange2(pDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 1, &pResp2, &wRespLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}

			/* No response to the command allowed */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_IO_TIMEOUT2)
			{
				PH_BREAK_ON_FAILURE2(status2);
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
			}
			else
			{
				status2 = PH_ERR_SUCCESS2;
			}
			break;
		default:
			break;
	}

	aCmd2[0] = 0U;
	pDataParams2->eStayQuietState2 = PHPAL_SLI15693_STATE_IDLE2;
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_StayQuietPersistent2(
                                                P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                                )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;

	switch (pDataParams2->eStayQuietPersistentState2)
	{
		case PHPAL_SLI15693_STATE_IDLE2:
			/* clear selected flag */
			pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED2;

			/* set addressed flag */
			pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;

			/* stay quiet persistent command */
			aCmd2[0] = PHPAL_SLI15693_SW_CMD_STAY_QUIET_PERSISTENT2;

			pDataParams2->eStayQuietState2	= PHPAL_SLI15693_STATE_SET_TIMEOUT2;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT2:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
				PHPAL_SLI15693_TIMEOUT_SHORT_US2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eStayQuietPersistentState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE2:
			/* Exchange command */
			status2 = phpalSli15693_Exchange2(pDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 1, &pResp2, &wRespLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}

			/* No response to the command allowed */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_IO_TIMEOUT2)
			{
				PH_BREAK_ON_FAILURE2(status2);
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
			}
			else
			{
				status2 = PH_ERR_SUCCESS2;
			}
			break;
		default:
			break;
	}

	aCmd2[0] = 0U;
	pDataParams2->eStayQuietPersistentState2 = PHPAL_SLI15693_STATE_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_Select2(
                                   P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                   )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;

	switch (pDataParams2->eSelectState2)
	{
		case PHPAL_SLI15693_STATE_IDLE2:
			/* clear selected flag */
			pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED2;

			/* set addressed flag */
			pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;

			/* reset to ready command */
			aCmd2[0] = PHPAL_SLI15693_SW_CMD_SELECT2;

			pDataParams2->eStayQuietState2	= PHPAL_SLI15693_STATE_SET_TIMEOUT2;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT2:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
				PHPAL_SLI15693_TIMEOUT_SHORT_US2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eSelectState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE2:
			status2 = phpalSli15693_Exchange2(pDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 1, &pResp2, &wRespLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}
			/* We shall not receive any data */
			if (wRespLength2 != 0U)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
				break;
			}

			/* clear addressed flag */
			pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_ADDRESSED2;

			/* set selected flag */
			pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_SELECTED2;
			break;
		default:
			break;
	}

	aCmd2[0] = 0U;
	pDataParams2->eSelectState2 = PHPAL_SLI15693_STATE_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_ResetToReady2(
    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aCmd2[1] = {0U};
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;

	switch (pDataParams2->eResetToReadyState2)
	{
		case PHPAL_SLI15693_STATE_IDLE2:
			/* reset to ready command */
			aCmd2[0] = PHPAL_SLI15693_SW_CMD_RESET_TO_READY2;

			pDataParams2->eStayQuietState2	= PHPAL_SLI15693_STATE_SET_TIMEOUT2;
			/* no break */

		case PHPAL_SLI15693_STATE_SET_TIMEOUT2:
			/* Set short timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
				PHPAL_SLI15693_TIMEOUT_SHORT_US2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eResetToReadyState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE2:
			/* Exchange command */
			status2 = phpalSli15693_Exchange2(pDataParams2, PH_EXCHANGE_DEFAULT2, aCmd2, 1, &pResp2, &wRespLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}

			/* We shall not receive any data */
			if (wRespLength2 != 0U)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
				break;
			}

			/* clear selected flag */
			pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_SELECTED2;
			break;
		default:
			break;
	}

	aCmd2[0] = 0U;
	pDataParams2->eResetToReadyState2 = PHPAL_SLI15693_STATE_IDLE2;
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_Exchange2(
                  P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wOption2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                  VAR(uint16, ANFCRL_VAR) wTxLength2,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFirstBlock2[3] = {0U};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTransmitLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempOption2 = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempTxLength2 = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTempTxBuffer2 = NULL;

	/* the frame to exchange looks like the following:
	{optional} [one byte]
	[flags][CMD]{[MFC]}{[UID0] .. [UID3]}[CMDParam(0)] .. [CMDParam(N)] */

	/* Check for valid UID in addressed mode */
	if ((0U == ((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_INVENTORY2))) && (0U != ((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_ADDRESSED2))))
	{
		/* Return an error if UID is not valid */
		if (pDataParams2->bUidBitLength2 != PHPAL_SLI15693_SW_UID_COMPLETE2)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_SLI156932);
		}
	}

	/* Check if caller has provided valid RxBuffer */
	if (ppRxBuffer2 == NULL)
	{
		ppRxBuffer2 = &pDataParams2->pTmpRxBuff2;
	}
	if (pRxLength2 == NULL)
	{
		pRxLength2 = &pDataParams2->tmpRxLen2;
	}

	switch (pDataParams2->eExchangeState2)
	{
		case PHPAL_SLI15693_STATE_IDLE2:
			wTempOption2 = wOption2;
			wTempTxLength2 = wTxLength2;
			pTempTxBuffer2 = pTxBuffer2;
			if ((0U == ((wTempOption2 & PH_EXCHANGE_LEAVE_BUFFER_BIT2))))
			{
				pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_12;
			}
			else
			{
				if(wTempTxLength2 != 0U)
				{
					MSG_LOG_BUF2(TAG2, ">>>> Exchange: " , pTempTxBuffer2, (uint8)wTempTxLength2);
				}
				pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
			}
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_12:
			/* This is the first chunk of a command frame. Add the Flags byte and ... */
			bFirstBlock2[wTransmitLength2++] = pDataParams2->bFlags2;
			bFirstBlock2[wTransmitLength2++] = pTxBuffer2[0];

			/* add MFC byte for custom commands */
			if ((pTxBuffer2[0] > PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_BEGIN2) && (pTxBuffer2[0] < PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_END2))
			{
				/* if no serial number is valid we assume that we use only NXP tags. */
				bFirstBlock2[wTransmitLength2++] = PHPAL_SLI15693_SW_NXP_MFG_CODE2;
			}
			else
			{
				if((pTxBuffer2[0] == PHPAL_SLI15693_SW_CMD_EXTENDED_GET_SYSTEM_INFORMATION2)
				   && (wTempTxLength2 > 1U))
			   {
				   /* Handle the Frame format preparation for Extended Get System Information specifically since this takes 1
					*  UID from 3rd Byte whereas rest other commands take UID from 2nd Byte
					*  SOF + FLAGS + COMMAND CODE +  INFO FLAGS  + UID  + CRC + EOF.
					*/

				   /* Copy Info Flags */
				   bFirstBlock2[wTransmitLength2++] = pTxBuffer2[1];

				   /* First byte was the command byte */
				   ++pTempTxBuffer2;
				   --wTempTxLength2;
			   }
			}
			pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_22;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_22:
			/* Exchange command */
			/* clear buffer but do not send */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				PH_EXCHANGE_BUFFERED_BIT2,
				bFirstBlock2,
				wTransmitLength2,
				ppRxBuffer2,
				pRxLength2));
			PH_BREAK_ON_FAILURE2(status2);
			MSG_LOG_BUF2(TAG2, ">>>> Exchange: " , bFirstBlock2, (uint8)wTransmitLength2);

			/* First set of TxBuffer contains
			 *  1. command code + Info Bytes
			 *  2. command Code
			 */
			++pTempTxBuffer2;
			--wTempTxLength2;
			pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_32;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_32:
			/* If we are not waiting any more we can transmit the UID bytes, if necessary. */
			if ((0U == ((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_INVENTORY2))) && (0U != ((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_ADDRESSED2))))
			{
				if(0U == (pDataParams2->bExplicitlyAddressed2))
				{
					PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
						pDataParams2->pHalDataParams2,
						PH_EXCHANGE_BUFFER_CONT2,    /* do not clear, do not send */
						pDataParams2->pUid2,
						PHPAL_SLI15693_UID_LENGTH2,
						ppRxBuffer2,
						pRxLength2));
					PH_BREAK_ON_FAILURE2(status2);
					MSG_LOG_BUF2(TAG2, ">>>> Exchange: " , pDataParams2->pUid2, PHPAL_SLI15693_UID_LENGTH2);
				}
			}

			/* Now we need to keep our buffered contents */
			wTempOption2 |= PH_EXCHANGE_LEAVE_BUFFER_BIT2;
			if(wTempTxLength2 != 0U)
			{
				MSG_LOG_BUF2(TAG2, ">>>> Exchange: " , pTxBuffer2, (uint8)wTempTxLength2);
			}
			pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_SLI15693_STATE_EXCHANGE2:
			status2 = phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				wTempOption2,
				pTempTxBuffer2,
				wTempTxLength2,
				ppRxBuffer2,
				pRxLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}
			if(status2 == PH_ERR_SUCCESS2)
			{
				MSG_LOG_BUF2(TAG2, "<<<< Exchange: " , *ppRxBuffer2, (uint8)(*pRxLength2));
			}
			else
			{
				MSG_LOG2(TAG2, "<<< Exchange status2: %X\r\n", status2);
			}
			PH_BREAK_ON_FAILURE2(status2);
			/* If this was the last (or only) chunk, we should have received a response,
			so we extract the Flags byte and check the status2 */
			if ((0U == ((wTempOption2 & PH_EXCHANGE_BUFFERED_BIT2))))
			{
				/* First Check RespLength*/
				if (*pRxLength2 == 0U)
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
					break;
				}

				/*check error flag*/
				if (0U != ((*ppRxBuffer2[0]) & PHPAL_SLI15693_FLAG_RESP_ERROR2))
				{
					/* check the length in case of error */
					if (*pRxLength2 != 2U)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
						break;
					}

					/* Copy error code to additional info */
					pDataParams2->wAdditionalInfo2 = (*ppRxBuffer2)[1];

					/* Return empty receive buffer */
					*ppRxBuffer2 = NULL;
					*pRxLength2 = 0;

					status2 = PH_ADD_COMPCODE_FIXED2(PHPAL_SLI15693_ERR_ISO156932, PH_COMP_PAL_SLI156932);
					break;
				}

				/* Copy response flag to additional info */
				pDataParams2->wAdditionalInfo2 = (*ppRxBuffer2)[0];

				/* adjust pointer and length */
				++(*ppRxBuffer2);
				--(*pRxLength2);
			}

			status2 = PH_ERR_SUCCESS2;
			break;
		default:
			break;
	}

	bFirstBlock2[0] = 0U;
	bFirstBlock2[1] = 0U;
	bFirstBlock2[2] = 0U;
	wTransmitLength2 = 0U;
	wTempOption2 = 0U;
	wTempTxLength2 = 0U;
	pTempTxBuffer2 = NULL;
	pDataParams2->eExchangeState2 = PHPAL_SLI15693_STATE_IDLE2;
	return status2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_ActivateCard2(
    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bOption2,
    VAR(uint8, ANFCRL_VAR) bFlags2,
    VAR(uint8, ANFCRL_VAR) bAfi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
    VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
    )
{
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSlot2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTimeOutNotAllowed2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aMaskBuffer2[PHPAL_SLI15693_UID_LENGTH2] = {0U};
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMaskByteLength2 = 0U;
    static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCurrMaskBitLength2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidLengthDummy2 = 0U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bDataDummy2[1] = {0u};
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLengthDummy2 = 0U;

    switch(pDataParams2->eActCardState2)
    {
		case PHPAL_SLI15693_ACTCARD_START2:
			/* Check option byte */
			if ((bOption2 != PHPAL_SLI15693_ACTIVATE_ADDRESSED2) && (bOption2 != PHPAL_SLI15693_ACTIVATE_SELECTED2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			/* init return value */
			*pMoreCardsAvailable2 = 0;
			bCurrMaskBitLength2 = bMaskBitLength2;
			pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_INVENTORY2;
			/* no break */

		case PHPAL_SLI15693_ACTCARD_INVENTORY2:
			/* Perform inventory command */
			status2 = phpalSli15693_Sw_Inventory2(pDataParams2, bFlags2, bAfi2, pMask2, bCurrMaskBitLength2, pDsfid2, pUid2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}

			/* Check for invalid parameter */
			if ((status2 & PH_ERR_MASK2) == PH_ERR_INVALID_PARAMETER2)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
				break;
			}

			/* Retrieve mask byte length */
			bMaskByteLength2 = ((bCurrMaskBitLength2 % 8U) != 0U) ? ((bCurrMaskBitLength2 >> 3U) + 1U) : (bCurrMaskBitLength2 >> 3U);

			/* init mask buffer */
			(void)memset(aMaskBuffer2, 0, (size_t)sizeof(aMaskBuffer2));
			(void)memcpy(aMaskBuffer2, pMask2, bMaskByteLength2);
			bSlot2 = 0;
			if ((0U == ((bFlags2 & PHPAL_SLI15693_FLAG_NBSLOTS2))))
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SLOTMAKER2;
			}
			else
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_ONESLOT2;
				bTimeOutNotAllowed2 = 1;
			}
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_ACTCARD_SLOTMAKER2:
			/* if we have more than one slot, we need to send slot markers (b6 = 0) */
			/* Slot marker loop */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
			{
				switch (status2 & PH_ERR_MASK2)
				{
					/*  If a CRC error or collision error occurred --> resolve collision */
				case PH_ERR_COLLISION_ERROR2:
				case PH_ERR_INTEGRITY_ERROR2:

					*pMoreCardsAvailable2 = 1;

					/* Get bit-length of last valid byte */
					bUidLengthDummy2 = (uint8)(bCurrMaskBitLength2 % 8U);

					/* Whole byte is valid -> append slot number to next byte */
					if (bUidLengthDummy2 == 0U)
					{
						aMaskBuffer2[bCurrMaskBitLength2 >> 3U] = bSlot2;
					}
					/* Partial byte is valid */
					else
					{
						/* Fill the invalid bits of the incomplete byte with the 4 bits slot number */
						aMaskBuffer2[bCurrMaskBitLength2 >> 3U] &= (uint8)(0xFFU >> (8U - bUidLengthDummy2));
						aMaskBuffer2[bCurrMaskBitLength2 >> 3U] |= (uint8)(bSlot2 << bUidLengthDummy2);

						/* If not all 4 bits of the Slot number fit in the incomplete byte, put the rest in the next byte */
						if (bUidLengthDummy2 > 4U)
						{
							aMaskBuffer2[(bCurrMaskBitLength2 >> 3U) + 1U] = (uint8)(bSlot2 >> bUidLengthDummy2);
						}
					}

					/* Increment the bit length by the 4 bits slot number */
					bCurrMaskBitLength2 = bCurrMaskBitLength2 + 4U;

					/* Start again from Slot number 0 */
					bSlot2 = 0;
					status2 = phpalSli15693_Sw_Inventory2(pDataParams2, bFlags2, bAfi2, aMaskBuffer2, bCurrMaskBitLength2, pDsfid2, pUid2);
					pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP2;
					break;

					/* Timeout -> advance to next slot */
				case PH_ERR_IO_TIMEOUT2:
					++bSlot2;
					pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SENDEOF_LOOP2;
					return PH_STATUS_INPROCESS2;
					/* No break */

				default:
					pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_START2;
					return status2;
				}

			}
			if(pDataParams2->eActCardState2 == PHPAL_SLI15693_ACTCARD_SLOTMAKER2)
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_FINISH2;
			}
			return status2;

		case PHPAL_SLI15693_ACTCARD_SENDEOF_LOOP2:
			/* Send EOF and increment slot number */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_Sw_SendEof2(
				pDataParams2,
				PHPAL_SLI15693_EOF_NEXT_SLOT2,
				pDsfid2,
				pUid2,
				&bUidLengthDummy2,
				bDataDummy2,
				&wDataLengthDummy2));
			/* if we ran through all slots, we are done */
			if ((bSlot2 >= 15U) || (status2 == PH_ERR_SUCCESS2))
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_FINISH2;
				return PH_STATUS_INPROCESS2;
			}
			pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SLOTMAKER2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_ACTCARD_ONESLOT2:
			/* use only one slot */
			/* Do not allow a time out after the first Inventory command since then, no
			card with the specified mask is present in the field. */
			/* Bit mask loop */
			if (bCurrMaskBitLength2 < PHPAL_SLI15693_SW_UID_COMPLETE2)
			{
				switch (status2 & PH_ERR_MASK2)
				{
					/* If there was a card, the loop is done */
				case PH_ERR_SUCCESS2:
					bCurrMaskBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;
					break;

					/* In case of a timeout, no card with the actual mask is in the field, so toggle the last bit of the mask */
				case PH_ERR_IO_TIMEOUT2:
					/* Abort, if this bit was already tested */
					if (0U != (bTimeOutNotAllowed2))
					{
						pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_START2;
						return status2;
					}

					/* the bit mask is > 0U, because in the case of bitmask = 0 a timeout can not happen */
					aMaskBuffer2[(uint8)(bCurrMaskBitLength2 - 1U) >> 3U] = aMaskBuffer2[(uint8)(bCurrMaskBitLength2 - 1U) >> 3U] ^ (uint8)(0x01U << (uint8)((bCurrMaskBitLength2 - 1U) % 8U));
					bTimeOutNotAllowed2 = 1;
					break;

					/*  If a CRC error or collision error occurred add one bit to the mask. */
				case PH_ERR_COLLISION_ERROR2:
				case PH_ERR_INTEGRITY_ERROR2:
					/* Note: The value of this bit does not really matter since it will be toggled in case of a timeout */
					*pMoreCardsAvailable2 = 1;

					++bCurrMaskBitLength2;
					bTimeOutNotAllowed2 = 0;
					break;

					/* If it is an other error than Collision, Crc or Timeout Error the function should return the error */
				default:
					pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_START2;
					return status2;
				}

				/* Perform next inventory command to perform anti-collision */
				if (bCurrMaskBitLength2 < PHPAL_SLI15693_SW_UID_COMPLETE2)
				{
					status2 = phpalSli15693_Sw_Inventory2(pDataParams2, bFlags2, bAfi2, aMaskBuffer2, bCurrMaskBitLength2, pDsfid2, pUid2);
					pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP2;
					return status2;
				}
			}
			pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_FINISH2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP2:
			PH_CHECK_INPROCESS_FCT2(status2,
					phpalSli15693_Sw_Inventory2(pDataParams2, bFlags2, bAfi2, aMaskBuffer2, bCurrMaskBitLength2, pDsfid2, pUid2));
			if ((0U == ((bFlags2 & PHPAL_SLI15693_FLAG_NBSLOTS2))))
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SLOTMAKER2;
			}
			else
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_ONESLOT2;
			}
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_ACTCARD_FINISH2:
			/* no need to proceed if an error occurred. */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
			{
				/* clear option flag */
				pDataParams2->bFlags2 &= (uint8)~(uint8)PHPAL_SLI15693_FLAG_OPTION2;
				break;
			}

			/* Select the card if necessary */
			if (0U != (bOption2 & PHPAL_SLI15693_ACTIVATE_SELECTED2))
			{
				pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_ACTIVATE_SELECTED2;
				return PH_STATUS_INPROCESS2;
			}

			pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SET_TIMEOUT2;
			/* no break */

		case PHPAL_SLI15693_ACTCARD_SET_TIMEOUT2:
			/* Set long timeout. */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SetConfig2(pDataParams2, PHPAL_SLI15693_CONFIG_TIMEOUT_US2, PHPAL_SLI15693_TIMEOUT_LONG_US2));
			break;

		case PHPAL_SLI15693_ACTCARD_ACTIVATE_SELECTED2:
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_Select2(pDataParams2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_SET_TIMEOUT2;
			return PH_STATUS_INPROCESS2;

		default:
			break;
	}
    pDataParams2->eActCardState2 = PHPAL_SLI15693_ACTCARD_START2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_GetSerialNo2(
                    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2
										)
{
	/* Return an error if UID is not valid */
	if (pDataParams2->bUidBitLength2 != PHPAL_SLI15693_SW_UID_COMPLETE2)
	{
		*pUidLength2 = 0U;
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_SLI156932);
	}

	/* copy the UID */
	(void)memcpy(pUid2, pDataParams2->pUid2, PHPAL_SLI15693_UID_LENGTH2);
	*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_SetSerialNo2(
                    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                    VAR(uint8, ANFCRL_VAR) bUidLength2
										)
{
	/* Check for valid UID length */
	if(bUidLength2 != PHPAL_SLI15693_UID_LENGTH2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
	}

	/* Copy UID and UID length */
	(void)memcpy(pDataParams2->pUid2, pUid2, PHPAL_SLI15693_UID_LENGTH2);
	pDataParams2->bUidBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_SetConfig2(
                    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint16, ANFCRL_VAR) wConfig2,
                    VAR(uint16, ANFCRL_VAR) wValue2
									  )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wValueOld2 = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempValue2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bSetConfigState2 = 0U;

	switch (wConfig2)
	{
	case PHPAL_SLI15693_CONFIG_FLAGS2:

		/* Retrieve current subcarrier setting */
		PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_GetConfig2(
			pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_SUBCARRIER2,
			&wValueOld2));

		/* Set dual subcarrier if HAL is not already configured for it */
		if (0U != (wValue2 & PHPAL_SLI15693_FLAG_TWO_SUB_CARRIERS2))
		{
			/* NFC mode supports only single sub-carrier mode */
			if(pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			if (wValueOld2 != PHHAL_HW_SUBCARRIER_DUAL2)
			{
				do
				{
					statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
										PHHAL_HW_CONFIG_SUBCARRIER2,
										PHHAL_HW_SUBCARRIER_DUAL2);
				} while (statusTmp2 == PH_STATUS_INPROCESS2);
			}
		}
		/* Set single subcarrier if HAL is not already configured for it */
		else
		{
			if (wValueOld2 != PHHAL_HW_SUBCARRIER_SINGLE2)
			{
				do
				{
					statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
										PHHAL_HW_CONFIG_SUBCARRIER2,
										PHHAL_HW_SUBCARRIER_SINGLE2);
				} while (statusTmp2 == PH_STATUS_INPROCESS2);
			}
		}

		/* Retrieve current datarate setting */
		do
		{
			statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RXDATARATE_FRAMING2, &wValueOld2);
		} while (statusTmp2 == PH_STATUS_INPROCESS2);
		PH_CHECK_SUCCESS2(statusTmp2);

		/* Set low data rate if HAL is not already configured for it */
		if (0U == (wValue2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
		{
			/* NFC mode supports only HIGH Data Rate */
			if(pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			if (wValueOld2 != PHHAL_HW_RF_RX_DATARATE_LOW2)
			{
				do
				{
					statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
							PHHAL_HW_CONFIG_RXDATARATE_FRAMING2, PHHAL_HW_RF_RX_DATARATE_LOW2);
				} while (statusTmp2 == PH_STATUS_INPROCESS2);
				PH_CHECK_SUCCESS2(statusTmp2);
			}

		}
		/* Set high data rate if HAL is not already configured for it */
		else
		{
			if (wValueOld2 != PHHAL_HW_RF_RX_DATARATE_HIGH2)
			{
				do
				{
					statusTmp2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
							PHHAL_HW_CONFIG_RXDATARATE_FRAMING2, PHHAL_HW_RF_RX_DATARATE_HIGH2);
				} while (statusTmp2 == PH_STATUS_INPROCESS2);
				PH_CHECK_SUCCESS2(statusTmp2);
			}
		}

		/* retrieve flags */
		pDataParams2->bFlags2 = (uint8)wValue2;

		break;
	case PHPAL_SLI15693_CONFIG_TIMEOUT_US2:
		if(PHPAL_SLI15693_STATE_IDLE2 == pDataParams2->eSetConfigState2)
		{
			if (((uint32)wValue2 + PHPAL_SLI15693_SW_EXT_TIME_US2) > 0xFFFFU)
			{
				/* Return error */
				/* Maximum allowed value is 0xFFC3 (0xFFFF - PHPAL_SLI15693_SW_EXT_TIME_US2) */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_PARAMETER_OVERFLOW2, PH_COMP_PAL_SLI156932);
			}

			/* Extend timeout a little */
			wValue2 += PHPAL_SLI15693_SW_EXT_TIME_US2;

			/* Retrieve current timeout */
			statusTmp2 = phhalHw_GetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
				&wValueOld2);

			/* Set the new timeout */
			if ((((statusTmp2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2) && (wValue2 != wValueOld2)) ||
				((statusTmp2 & PH_ERR_MASK2) == PH_ERR_PARAMETER_OVERFLOW2))
			{
				wTempValue2 = wValue2;
				pDataParams2->eSetConfigState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Return error if the error is other than PH_ERR_PARAMETER_OVERFLOW2 */
				PH_CHECK_SUCCESS2(statusTmp2);
			}
		}
		else if(PHPAL_SLI15693_STATE_EXCHANGE2 == pDataParams2->eSetConfigState2)
		{
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
					wTempValue2));
			wTempValue2 = 0U;
			pDataParams2->eSetConfigState2 = PHPAL_SLI15693_STATE_IDLE2;
			PH_CHECK_SUCCESS2(statusTmp2);
		}
		else
		{
			/* Do nothing */
		}
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_MS2:
		if(PHPAL_SLI15693_STATE_IDLE2 == pDataParams2->eSetConfigState2)
		{
			/* Retrieve current timeout */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_GetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
				&wValueOld2));

			/* Set the new timeout */
			if (wValue2 != wValueOld2)
			{
				wTempValue2 = wValue2;
				pDataParams2->eSetConfigState2 = PHPAL_SLI15693_STATE_EXCHANGE2;
				return PH_STATUS_INPROCESS2;
			}
		}
		else if(PHPAL_SLI15693_STATE_EXCHANGE2 == pDataParams2->eSetConfigState2)
		{
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
					wValue2));
			wTempValue2 = 0U;
			pDataParams2->eSetConfigState2 = PHPAL_SLI15693_STATE_IDLE2;
			PH_CHECK_SUCCESS2(statusTmp2);
		}
		else
		{
			/* Do nothing */
		}
		break;

	case PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING2:
		pDataParams2->bBuffering2 = (uint8)wValue2;
		break;

	case PHPAL_SLI15693_CONFIG_TXDATARATE2:
		if(0U == bSetConfigState2)
		{
			if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2) && (wValue2 != PHPAL_SLI15693_26KBPS_DATARATE2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			if (wValue2 > PHPAL_SLI15693_212KBPS_DATARATE2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			switch (wValue2)
			{
				case PHPAL_SLI15693_26KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_42;
					break;
				case PHPAL_SLI15693_53KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_I15693_53KBPS_DATARATE2;
					break;
				case PHPAL_SLI15693_106KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_DATARATE_1062;
					break;
				case PHPAL_SLI15693_212KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_DATARATE_2122;
					break;
				default:
					break;
			}
			wTempValue2 = wValue2;
			bSetConfigState2 = 1U;
		}

		if(1U == bSetConfigState2)
		{
			/* Set the new TX data rate */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING2, wTempValue2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
		}
		break;

	case PHPAL_SLI15693_CONFIG_RXDATARATE2:
		if(0U == bSetConfigState2)
		{
			if((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2) && (wValue2 != PHPAL_SLI15693_26KBPS_DATARATE2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			if(wValue2 > PHPAL_SLI15693_106KBPS_DATARATE2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			switch(wValue2)
			{
				case PHPAL_SLI15693_26KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_RX_DATARATE_HIGH2;
					break;
				case PHPAL_SLI15693_53KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_RX_DATARATE_FAST_HIGH2;
					break;
				case PHPAL_SLI15693_106KBPS_DATARATE2:
					wValue2 = PHHAL_HW_RF_DATARATE_1062;
					break;
				default:
					break;
			}
			wTempValue2 = wValue2;
			bSetConfigState2 = 1U;
		}

		if(1U == bSetConfigState2)
		{
			/* Set the new RX data rate */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_RXDATARATE_FRAMING2, wTempValue2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
		}
		break;

	default:
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_SLI156932);
	}

	bSetConfigState2 = 0U;
	wTempValue2 = 0U;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_GetConfig2(
                  P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wConfig2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;

	switch (wConfig2)
	{
	case PHPAL_SLI15693_CONFIG_FLAGS2:
		*pValue2 = pDataParams2->bFlags2;
		break;

	case PHPAL_SLI15693_CONFIG_ADD_INFO2:
		*pValue2 = pDataParams2->wAdditionalInfo2;
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_US2:
		/* Get HAL timeout value */
		PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_GetConfig2(
			pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
			pValue2));

		/* Remove timeout extension */
		*pValue2 -= PHPAL_SLI15693_SW_EXT_TIME_US2;
		break;

	case PHPAL_SLI15693_CONFIG_TIMEOUT_MS2:
		/* Get HAL timeout value */
		PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_GetConfig2(
			pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
			pValue2));

		break;

	case PHPAL_SLI15693_CONFIG_TXDATARATE2:
		/* Get HAL Tx Data Rate value */
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING2, pValue2));
		PH_BREAK_ON_FAILURE2(statusTmp2);

		/* Map the HAL TX BaudRates to generic 15693 BaudRates */
		switch (*pValue2) {
		case PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_42:
			*pValue2 = PHPAL_SLI15693_26KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_I15693_53KBPS_DATARATE2:
			*pValue2 = PHPAL_SLI15693_53KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_DATARATE_1062:
			*pValue2 = PHPAL_SLI15693_106KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_DATARATE_2122:
			*pValue2 = PHPAL_SLI15693_212KBPS_DATARATE2;
			break;
		default:
			break;
		}
		break;

	case PHPAL_SLI15693_CONFIG_RXDATARATE2:
		/* Get HAL Rx Data Rate value */
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,pValue2));
		PH_BREAK_ON_FAILURE2(statusTmp2);

		/* Map the HAL RX BaudRates to generic 15693 BaudRates */
		switch(*pValue2)
		{
		case PHHAL_HW_RF_RX_DATARATE_HIGH2:
			*pValue2 = PHPAL_SLI15693_26KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_RX_DATARATE_FAST_HIGH2:
			*pValue2 = PHPAL_SLI15693_53KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_DATARATE_1062:
			*pValue2 = PHPAL_SLI15693_106KBPS_DATARATE2;
			break;
		case PHHAL_HW_RF_DATARATE_2122:
			*pValue2 = PHPAL_SLI15693_212KBPS_DATARATE2;
			break;
		default:
			break;
		}
		break;


	case PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING2:
		*pValue2 = pDataParams2->bBuffering2;
		break;

	default:
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_SLI156932);
	}

	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_InventoryRead2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bBlockNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength2
					)
{
	return phpalSli15693_Sw_InventoryEx2(
		pDataParams2,
		PHPAL_SLI15693_SW_CMD_INVENTORY_READ2,
		bFlags2,
		bAfi2,
		pMask2,
		bMaskBitLength2,
		bBlockNo2,
		wNoOfBlocks2,
		pUid2,
		bUidLength2,
		pData2,
		wLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_InventoryReadExtended2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bExtendedOptions2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,
          VAR(uint8, ANFCRL_VAR) bBlockNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength2
					)
{
	return phpalSli15693_Sw_InventoryExt2(
			pDataParams2,
			PHPAL_SLI15693_SW_CMD_INVENTORY_READ2,
			bFlags2,
			bAfi2,
			1U,
			bExtendedOptions2,
			pCID2,
			pMask2,
			bMaskBitLength2,
			bBlockNo2,
			wNoOfBlocks2,
			pCidOut2,
			pUid2,
			pUidLength2,
			pData2,
			wLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryRead2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bBlockNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
					)
{
	return phpalSli15693_Sw_InventoryEx2(
		pDataParams2,
		PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ2,
		bFlags2,
		bAfi2,
		pMask2,
		bMaskBitLength2,
		bBlockNo2,
		wNoOfBlocks2,
		pUid2,
		pUidLength2,
		pData2,
		pDataLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryReadExtended2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bExtendedOptions2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,
          VAR(uint8, ANFCRL_VAR) bBlockNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength2
					)
{
	return phpalSli15693_Sw_InventoryExt2(
			pDataParams2,
			PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ2,
			bFlags2,
			bAfi2,
			1U,
			bExtendedOptions2,
			pCID2,
			pMask2,
			bMaskBitLength2,
			bBlockNo2,
			wNoOfBlocks2,
			pCidOut2,
			pUid2,
			bUidLength2,
			pData2,
			wLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_InventoryPageRead2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bPageNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfPages2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
					)
{
	return phpalSli15693_Sw_InventoryEx2(
		pDataParams2,
		PHPAL_SLI15693_SW_CMD_INVENTORY_PAGE_READ2,
		bFlags2,
		bAfi2,
		pMask2,
		bMaskBitLength2,
		bPageNo2,
		wNoOfPages2,
		pUid2,
		pUidLength2,
		pData2,
		pDataLength2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryPageRead2(
          P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
          VAR(uint8, ANFCRL_VAR) bFlags2,
          VAR(uint8, ANFCRL_VAR) bAfi2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
          VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
          VAR(uint8, ANFCRL_VAR) bPageNo2,
          VAR(uint16, ANFCRL_VAR) wNoOfPages2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
          P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
					)
{
	return phpalSli15693_Sw_InventoryEx2(
		pDataParams2,
		PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ2,
		bFlags2,
		bAfi2,
		pMask2,
		bMaskBitLength2,
		bPageNo2,
		wNoOfPages2,
		pUid2,
		pUidLength2,
		pData2,
		pDataLength2);
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_InventoryEx2(
                    P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint8, ANFCRL_VAR) bCmd2,
                    VAR(uint8, ANFCRL_VAR) bFlags2,
                    VAR(uint8, ANFCRL_VAR) bAfi2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                    VAR(uint8, ANFCRL_VAR) bPage_Block_No2,
                    VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
										)
{
	return  phpalSli15693_Sw_InventoryExt2(
			pDataParams2,
			bCmd2,
			bFlags2,
			bAfi2,
			0U,
			0U,
			NULL,
			pMask2,
			bMaskBitLength2,
			bPage_Block_No2,
			wNoOfPages_Blocks2,
			NULL,
			pUid2,
			pUidLength2,
			pData2,
			pDataLength2
			);
}


FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_InventoryExt2(
                  P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint8, ANFCRL_VAR) bCmd2,
                  VAR(uint8, ANFCRL_VAR) bFlags2,
                  VAR(uint8, ANFCRL_VAR) bAfi2,
                  VAR(uint8, ANFCRL_VAR) bExtended2,
                  VAR(uint8, ANFCRL_VAR) bExtendedOptions2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength2,
                  VAR(uint8, ANFCRL_VAR) bPage_Block_No2,
                  VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2
									)
{
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = 0U;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCmdBuffer2[15] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCmdBufferLen2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCmdOffset2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMaskByteLength2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pResp2 = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bStoredUidLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wAsk2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTimeout2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrBlocksToRead2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrBlockNo2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wMaxNoBlocks2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bAllBlocksRead2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFirst2 = 0U;

	switch (pDataParams2->eInventoryState2)
	{
		case PHPAL_SLI15693_INVENTORY_START2:
			/* Reset UID and data length */
			pDataParams2->bUidBitLength2 = 0;

			if(((pUidLength2 == NULL) || (pUid2 == NULL)) || ((0U != ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_SKIP_DATA2))) && ((pDataLength2 == NULL) || (pData2 == NULL))))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			/* If Extended Option is looking for CID response then CID should not be null */
			if ((0U != ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_CID_COMPARE2))) && (pCID2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}
			/* If Extended Option is looking for CID response then CID should not be null */
			if((0U != ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_CID_RESPONSE2))) && (pCIDOut2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			*pUidLength2 = 0U;
			*pDataLength2 = 0U;
			bCmdBufferLen2 = 0U;
			bCmdOffset2 = 0U;
			bStoredUidLength2 = 0U;
			wAsk2 = 0U;
			wTimeout2 = 0U;
			wCurrBlocksToRead2 = 0U;
			wCurrBlockNo2 = 0U;
			wMaxNoBlocks2 = 0U;
			bAllBlocksRead2 = 0U;
			bFirst2 = 0U;
			/* first of all we check the bMaskBitLength2 according to ISO/IEC15693, 8.1, assuming
			the inventory flag to be set, bit b6 defines the number of slots
			b6 = 1: --> one slot --> mask length = [0 .. 64] bits
			b6 = 0: --> 16 slots --> mask length = [0 .. 60] bits */
			if (((0U != ((bFlags2 & PHPAL_SLI15693_FLAG_NBSLOTS2))) && (bMaskBitLength2 > 64U)) ||
				((0U == ((bFlags2 & PHPAL_SLI15693_FLAG_NBSLOTS2))) && (bMaskBitLength2 > 60U)))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
			}

			/* Number of Pages/Blocks check */
			if (bCmd2 != PHPAL_SLI15693_SW_CMD_INVENTORY2)
			{
				/* Number of Pages/Blocks can't be zero */
				if (wNoOfPages_Blocks2 == 0U)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
				}

				/* check if the block number exceeds the limit */
				if (((uint16)bPage_Block_No2 + wNoOfPages_Blocks2) >= PHPAL_SLI15693_SW_MAX_BLOCKS2)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_SLI156932);
				}
			}

			/* Add command code */
			bCmdBuffer2[bCmdBufferLen2++] = bCmd2;

			/* Apply flag settings */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phpalSli15693_SetConfig2(
				pDataParams2,
				PHPAL_SLI15693_CONFIG_FLAGS2,
				bFlags2));


			/* Overwrite datarate for fast inventory (page-)read */
            if ((bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ2) ||
                (bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ2))
            {
                if (0U != (bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
                {
                    pDataParams2->eInventoryState2 = PHHAL_SLI15693_INVENTORY_CONFIG_FAST_HIGH2;
                    return PH_STATUS_INPROCESS2;
                }
                else
                {
                    pDataParams2->eInventoryState2 = PHHAL_SLI15693_INVENTORY_CONFIG_FAST_LOW2;
                    return PH_STATUS_INPROCESS2;
                }
            }
            pDataParams2->eInventoryState2 = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHHAL_SLI15693_INVENTORY_CONFIG_FAST_HIGH2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
                                            PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,
                                            PHHAL_HW_RF_RX_DATARATE_FAST_HIGH2));
            if(statusTmp2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_START2;
                return statusTmp2;
            }
            pDataParams2->eInventoryState2 = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS2;
            return PH_STATUS_INPROCESS2;
        case PHHAL_SLI15693_INVENTORY_CONFIG_FAST_LOW2:
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
                                            PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,
                                            PHHAL_HW_RF_RX_DATARATE_FAST_LOW2));
            if(statusTmp2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_START2;
                return statusTmp2;
            }
            pDataParams2->eInventoryState2 = PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS2;
            /* no break */
        case PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS2:
            /* check if AFI shall be sent: */
            if ((0U != ((bFlags2 & PHPAL_SLI15693_FLAG_AFI2))) && (0U != ((bFlags2 & PHPAL_SLI15693_FLAG_INVENTORY2))))
			{
				bCmdBuffer2[bCmdBufferLen2++] = bAfi2;
			}

			/* Add mask length */
			/* Making the MSB of mask length byte as 1 to show extended mode */
			/* In case of extended mode add the extended option in command */
			if (0U != (bExtended2))
			{
				bCmdBuffer2[bCmdBufferLen2++] = bMaskBitLength2 | PHPAL_SLI15693_FLAG_INVENTORY_READ_EXTENSION2;
				bCmdBuffer2[bCmdBufferLen2++] = bExtendedOptions2;
				if (0U != (bExtendedOptions2 & PHPAL_SLI15693_FLAG_CID_COMPARE2))
				{
					bCmdBuffer2[bCmdBufferLen2++] = pCID2[0];
					bCmdBuffer2[bCmdBufferLen2++] = pCID2[1];
				}
			}
			else
			{
				bCmdBuffer2[bCmdBufferLen2++] = bMaskBitLength2;
			}

			/* Retrieve mask byte length */
			bMaskByteLength2 = ((bMaskBitLength2 % 8U) != 0U) ? ((bMaskBitLength2 >> 3U) + 1U) : (bMaskBitLength2 >> 3U);

			/* prepare mask in dataparams */
			(void)memcpy(pDataParams2->pUid2, pMask2, bMaskByteLength2 );
			pDataParams2->bUidBitLength2 = bMaskBitLength2;

			/* prepare mask to send */
			(void)memcpy(&bCmdBuffer2[bCmdBufferLen2], pMask2, bMaskByteLength2 );
			bCmdBufferLen2 = bCmdBufferLen2 + bMaskByteLength2;

			/* mask out invalid bits */
			if (0U != (bMaskBitLength2 & 0x07U))
			{
				bCmdBuffer2[bCmdBufferLen2 - 1U] &= (uint8)(0xFFU >> (8U - (bMaskBitLength2 & 0x07U)));
			}

            /* Get the ASK 100 Condition */
            statusTmp2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2,PHHAL_HW_CONFIG_ASK1002,&wAsk2);
            if(statusTmp2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_START2;
                return statusTmp2;
            }
			/* Calculate Timeout based on ask and baud rate */
			if(wAsk2 != 0U)
			{
				if ((bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ2) ||
					(bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ2))
				{
					if(0U != (bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTHIGH_SOF_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTLOW_SOF_US2;
					}
				}
				else
				{
					if(0U != (bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_HIGH_SOF_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_LOW_SOF_US2;
					}
				}
			}
			else
			{
				if ((bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ2) ||
					(bCmd2 == PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ2))
				{
					if(0U != (bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTHIGH_NRT_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_FASTLOW_NRT_US2;
					}
				}
				else
				{
					if(0U != (bFlags2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_HIGH_NRT_US2;
					}
					else
					{
						wTimeout2 = PHPAL_SLI15693_TIMEOUT_SHORT_US2 + PHPAL_SLI15693_SW_LOW_NRT_US2;
					}
				}
			}
            pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_TIMEOUT_US2;
            /* no break */
        case PHPAL_SLI15693_INVENTORY_TIMEOUT_US2:
            /* Set  timeout. */
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phpalSli15693_SetConfig2(pDataParams2,PHPAL_SLI15693_CONFIG_TIMEOUT_US2,
                                                                      wTimeout2));
            if(statusTmp2 != PH_ERR_SUCCESS2)
            {
                pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_START2;
                return statusTmp2;
            }
			/* Update the command offset variable. */
			bCmdOffset2 = bCmdBufferLen2;

			/* If buffering is set. */
			if((pDataParams2->bBuffering2) != 0U)
			{
				/* Update the maximum number of blocks with respect to Option flag setting. The value for the blocks is fixed to 60 and 40 to avoid multiple
				 * handling of different data in response. RD70x can respond with more amount of data but CM1 can not. So fixing the blocks count to a lower
				 * value.
				 */
				wMaxNoBlocks2 = (uint8) (((bFlags2 & PHPAL_SLI15693_FLAG_OPTION2) != 0U) ? 40U : 60U);

				/* Blocks to read. */
				wCurrBlocksToRead2 = wMaxNoBlocks2;

				/* Update the number of blocks to read if its less than the internal required one. */
				if(wNoOfPages_Blocks2 < wMaxNoBlocks2)
				{
					wCurrBlocksToRead2 = wNoOfPages_Blocks2;
					bAllBlocksRead2 = 1U;
				}
			}
			else
			{
				wCurrBlocksToRead2 = wNoOfPages_Blocks2;
				bAllBlocksRead2 = 1U;
			}


			if((((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_INVENTORY2) == 0U) && ((pDataParams2->bFlags2 & PHPAL_SLI15693_FLAG_ADDRESSED2) != 0U)))
			{
				pDataParams2->bExplicitlyAddressed2 = 1U;
			}


			/* Set First variable. This variable will be used to validate the response only once in case if chaining is enabled. */
			bFirst2 = PH_ON2;
			pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_INIT2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_INVENTORY_INIT2:
			/* Exchange the information. */
			/* Page (or block) number and count */
			if (bCmd2 != PHPAL_SLI15693_SW_CMD_INVENTORY2)
			{
			 /* Adjust number of blocks. Adjustment is made because the User or the application will pass
			 * the number of blocks starting from 1 to N. But as per Iso15693 specification the number
			 * of blocks ranges from 0 - (N - 1).
			 */
				--wCurrBlocksToRead2;

				if (!((bExtended2 != 0U) && ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_SKIP_DATA2) != 0U)))
				{
					bCmdBuffer2[bCmdOffset2++] = (uint8) ((wCurrBlockNo2 + bPage_Block_No2) & 0x00FFU);
					bCmdBuffer2[bCmdOffset2++] = (uint8) wCurrBlocksToRead2;
				}
			}
			pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_LOOP2;
			/*no break*/

		case PHPAL_SLI15693_INVENTORY_LOOP2:
			status2 = phpalSli15693_Exchange2(
				pDataParams2,
				PH_EXCHANGE_DEFAULT2,
				bCmdBuffer2,
				bCmdOffset2,
				&pResp2,
				&wRespLength2);
			if (status2 == PH_STATUS_INPROCESS2)
			{
				return status2;
			}

			/* Clear INVENTORY, AFI and NBSLOTS flag */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
			{
				pDataParams2->bFlags2 &= (uint8) ~(uint8) (PHPAL_SLI15693_FLAG_INVENTORY2
						| PHPAL_SLI15693_FLAG_AFI2 | PHPAL_SLI15693_FLAG_NBSLOTS2);
			}

			/* Verify the exchange status2. */
			PH_BREAK_ON_FAILURE2(status2);

			/* Extracting  the CID as sent by the VICC. */
			if ((bExtended2 != 0U) && ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_CID_RESPONSE2) != 0U))
			{
				phTools_memcpy2(pCIDOut2, pResp2, 2U);  /* PRQA S 3200 */

				/* Update the response pointer address and length to Skip CID. */
				pResp2 = &pResp2[2];
				wRespLength2 -= 2U;
			}

			/* Set the length (amount) of expected UID bytes. */
			if (bCmd2 == PHPAL_SLI15693_SW_CMD_INVENTORY2)
			{
				/* The response length should be exactly the complete UID */
				if (wRespLength2 != (1U + PHPAL_SLI15693_UID_LENGTH2))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
					break;
				}

				/* Copy the DSFID to the data buffer. */
				pData2[0] = pResp2[0];
				*pDataLength2 = 1U;

				/* Store the UID */
				(void)memcpy(pDataParams2->pUid2, &pResp2[1], PHPAL_SLI15693_UID_LENGTH2); /* PRQA S 3200 */
				pDataParams2->bUidBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;

				/* Return the UID */
				(void)memcpy(pUid2, pDataParams2->pUid2, PHPAL_SLI15693_UID_LENGTH2); /* PRQA S 3200 */
				*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2;
			}
			else
			{
				if ((bFlags2 & PHPAL_SLI15693_FLAG_OPTION2) != 0U)
				{
					*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2 - bStoredUidLength2;

					/* The response length should not be less than the remaining UID. */
					if(bFirst2 != 0U)
					{
						bStoredUidLength2 = pDataParams2->bUidBitLength2 >> 3U;
						*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2 - bStoredUidLength2;

						/* Update the UID length if extended. */
						if((bExtended2 != 0U) && ((bExtendedOptions2 & PHPAL_SLI15693_FLAG_UID_MODE2) != 0U))
						{
							*pUidLength2 = PHPAL_SLI15693_UID_LENGTH2;
						}
					}
					/* Validate the response length against UID length. */
					if (wRespLength2 < (*pUidLength2))
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
						break;
					}

					if (bStoredUidLength2 < PHPAL_SLI15693_UID_LENGTH2)
					{
						if ((*pUidLength2) == 0U)
						{
							status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_SLI156932);
							break;
						}
						/* Return the received (partial) UID */
						(void)memcpy(pUid2, pResp2, (size_t)(*pUidLength2)); /* PRQA S 3200 */

						/* We need to merge the contents of the mask buffer and the received data */
						if ((bMaskBitLength2 % 8U) != 0u)
						{
							if (bStoredUidLength2 < 7U)
							{
								/* copy the UID bytes we received from the card */
								(void)memcpy(&(pDataParams2->pUid2[bStoredUidLength2 + 1U]), &pResp2[1], (size_t)(*pUidLength2)-1U); /* PRQA S 3200 */
							}

							/* merge mask-bits with received bits */
							pDataParams2->pUid2[bStoredUidLength2] |= pResp2[0];
						}
						else
						{
							/* Copy the UID bytes we received from the card */
							(void)memcpy(&(pDataParams2->pUid2[bStoredUidLength2]), pResp2, *pUidLength2); /* PRQA S 3200 */
						}
					}

					/* Update UID length. */
					pDataParams2->bUidBitLength2 = PHPAL_SLI15693_SW_UID_COMPLETE2;

					/* Shift pointer and length */
					pResp2 = &pResp2[*pUidLength2];
					wRespLength2 = (uint16) (wRespLength2 - *pUidLength2);
				}
				/* Copy the received data to internal buffer. */
				phTools_memcpy2(&pData2[*pDataLength2], pResp2, wRespLength2);         /* PRQA S 3200 */
				*pDataLength2 += wRespLength2;
			}

			/* Update the variables to read the remaining data. */
			wCurrBlockNo2 += wMaxNoBlocks2;

			/* Update the Current blocks to read. */
			wCurrBlocksToRead2 = wMaxNoBlocks2;

			/* Reset the command buffer offset. */
			bCmdOffset2 = bCmdBufferLen2;

			/* Set the remaining blocks to read. */
			if((wNoOfPages_Blocks2 - wCurrBlockNo2) < wMaxNoBlocks2)
			{
				wCurrBlocksToRead2 = (uint16) (wNoOfPages_Blocks2 - wCurrBlockNo2);
			}

			/* Set the flag to finish the loop. */
			if((wNoOfPages_Blocks2 * 4U) == *pDataLength2)
			{
				bAllBlocksRead2 = 1;
			}

			/* Set First variable. This variable will be used to validate the response only once in case if chaining is enabled. */
			bFirst2 = PH_OFF2;

			if(bAllBlocksRead2 == 0U)
			{
				pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_INIT2;
			}
			else
			{
				pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_FINISH2;
			}
			return PH_STATUS_INPROCESS2;

		case PHPAL_SLI15693_INVENTORY_FINISH2:
			/* Clear INVENTORY, AFI and NBSLOTS flag */
			pDataParams2->bFlags2 &= (uint8) ~(uint8) (PHPAL_SLI15693_FLAG_INVENTORY2
					| PHPAL_SLI15693_FLAG_AFI2 | PHPAL_SLI15693_FLAG_NBSLOTS2);

			pDataParams2->bExplicitlyAddressed2 = 0;

			/* Error check */
			PH_BREAK_ON_FAILURE2(status2);

			/* set addressed flag */
			pDataParams2->bFlags2 |= PHPAL_SLI15693_FLAG_ADDRESSED2;
			break;
		default:
			break;
	}

	pDataParams2->eInventoryState2 = PHPAL_SLI15693_INVENTORY_START2;
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

#ifdef __cplusplus
}
#endif
