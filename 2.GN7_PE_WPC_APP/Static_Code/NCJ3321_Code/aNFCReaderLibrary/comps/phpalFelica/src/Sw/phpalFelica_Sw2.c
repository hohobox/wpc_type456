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
*   @file    phpalFelica_Sw2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalFelica2 Felica
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
#include <phpalFelica2.h>
#include <ph_RefDefs2.h>

#ifdef  NXPBUILD__PHPAL_FELICA_SW2
#include "phpalFelica_Sw2.h"
#include "phpalFelica_Sw_Int2.h"
#include <phTools2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_SW_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalFelica_Sw2.h header file are of the same vendor */
#if (PHPALFELICA_SW_VENDOR_ID_C2 != PHPALFELICA_SW_VENDOR_ID2)
    #error "phpalFelica_Sw2.c and phpalFelica_Sw2.h have different vendor ids"
#endif
/* Check if current file and phpalFelica_Sw2.h header file are of the same Autosar version */
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2    != PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION_C2 != PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phpalFelica_Sw2.c and phpalFelica_Sw2.h are different"
#endif
/* Check if current file and phpalFelica_Sw2.h header file are of the same Software version */
#if ((PHPALFELICA_SW_SW_MAJOR_VERSION_C2 != PHPALFELICA_SW_SW_MAJOR_VERSION2) || \
     (PHPALFELICA_SW_SW_MINOR_VERSION_C2 != PHPALFELICA_SW_SW_MINOR_VERSION2) || \
     (PHPALFELICA_SW_SW_PATCH_VERSION_C2 != PHPALFELICA_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phpalFelica_Sw2.c and phpalFelica_Sw2.h are different"
#endif
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef  NXPBUILD__PHPAL_FELICA_SW2
#define FDTF_LISTEN_SENSF_REQ2(x)    (PHPAL_FELICA_SW_T_DELAY_US2 + ((x) * PHPAL_FELICA_SW_T_TIMESLOT_US2))    /**< NFC Forum Digital Protocol Technical Specification v1.1 : 8.7.1 : FDTF,LISTEN,SENSF_REQ */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Table for 4^E evaluation (E is only 2 bits, so more values are not possible). */
static CONST(uint8, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 aFelica_E_Table2[] = {1, 4, 16, 64};

#if (defined(NXPBUILD__PH_LOG_EX2) && !defined(PH_LIB_LOG_DISABLE2))
static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) TAG2 = "  FELICA|";
#endif

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 aFelica_TR1_Value_Us2[][2] = {
    {PHPAL_FELICA_SW_TR1_48BITS_AT212_US2, PHPAL_FELICA_SW_TR1_48BITS_AT424_US2},
    {PHPAL_FELICA_SW_TR1_56BITS_AT212_US2, PHPAL_FELICA_SW_TR1_56BITS_AT424_US2},
    {PHPAL_FELICA_SW_TR1_64BITS_AT212_US2, PHPAL_FELICA_SW_TR1_64BITS_AT424_US2},
    {PHPAL_FELICA_SW_TR1_72BITS_AT212_US2, PHPAL_FELICA_SW_TR1_72BITS_AT424_US2},
};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) gCmd2[16];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint16, ANFCRL_VAR) gCurrentCmd2 = 0xffu;
static VAR(uint8, ANFCRL_VAR) gbNumTimeSlotsLast2 = 0u;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_Init2(
                               P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                               VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                               )
{
    /* parameter structure length check */
    if (sizeof(phpalFelica_Sw_DataParams_t2) != wSizeOfDataParams2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_PAL_FELICA2);
    }
    PH_ASSERT_NULL2 (pDataParams2);
    PH_ASSERT_NULL2 (pHalDataParams2);

    pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_START2;
    pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_IDLE2;

    /* init private data */
    pDataParams2->wId2            = PH_COMP_PAL_FELICA2 | PHPAL_FELICA_SW_ID2;
    pDataParams2->pHalDataParams2 = pHalDataParams2;
    pDataParams2->bIDmPMmValid2   = PHPAL_FELICA_SW_IDMPMM_INVALID2;
    pDataParams2->bLength2        = 0x00;
    pDataParams2->bRequestCode2   = 0x00;
    pDataParams2->bPreambleLen2   = PHPAL_FELICA_PREAMBLE_LEN_48BITS2;

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_ReqC2(
                P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                VAR(uint8, ANFCRL_VAR) bNumTimeSlots2,
                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
								)
{
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTimeOutUs2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCardType2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTR1ValueUs2 = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxBufferTmp2 = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLengthTmp2 = 0U;

	switch (pDataParams2->eReqCState2)
	{
		case PHPAL_FELICA_REQC_IDLE2:
			status2 = PH_ERR_SUCCESS2;
			/* reset validity of stored card IDs */
			pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_INVALID2;

			/* Reset received frame count */
			pDataParams2->bTotalFrames2 = 0;

			/* parameter check and timeout setting */
			if(!((bNumTimeSlots2 == PHPAL_FELICA_NUMSLOTS_12) ||
				(bNumTimeSlots2 == PHPAL_FELICA_NUMSLOTS_22) ||
				(bNumTimeSlots2 == PHPAL_FELICA_NUMSLOTS_42) ||
				(bNumTimeSlots2 == PHPAL_FELICA_NUMSLOTS_82) ||
				(bNumTimeSlots2 == PHPAL_FELICA_NUMSLOTS_162))
			  )
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
			}
			else
			{
				PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_GetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_CARD_TYPE2,
					&wCardType2));
				/* NFC Forum Digital Protocol Technical Specification v1.1
				 * 8.7.1.3 : wTimeOutUs2 = FDTF,LISTEN,SENSF_REQ(TSN+1U) - TR1 + (delta)TF,POLL
				 * Using TR1 value @212kbps */
				if ((wCardType2 != PHHAL_HW_CARDTYPE_FELICA_2122) && (wCardType2 != PHHAL_HW_CARDTYPE_FELICA_4242))
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_FELICA2);
				}

				if (wCardType2 == PHHAL_HW_CARDTYPE_FELICA_2122)
				{
					wTR1ValueUs2 = aFelica_TR1_Value_Us2[pDataParams2->bPreambleLen2][0];
				}
				else
				{
					wTR1ValueUs2 = aFelica_TR1_Value_Us2[pDataParams2->bPreambleLen2][1];
				}

				wTimeOutUs2 = FDTF_LISTEN_SENSF_REQ2(((uint16)bNumTimeSlots2) + 1U) - wTR1ValueUs2 + PHPAL_FELICA_SW_T_DELTA_F_POLL_US2;
			}
			pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_TIMEOUT2;
			return PH_STATUS_INPROCESS2;
			/*no break*/

		case PHPAL_FELICA_REQC_TIMEOUT2:
			/* Set ReqC timeout according to the number of slots */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
					wTimeOutUs2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_CONFIG2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_FELICA_REQC_CONFIG2:
			/* build the command frame */
			gCmd2[0] = 6;
			gCurrentCmd2 = PHPAL_FELICA_SW_CMD_REQC2;
			gCmd2[1] = PHPAL_FELICA_SW_CMD_REQC2;
			gCmd2[2] = pSystemCode2[0];
			gCmd2[3] = pSystemCode2[1];
			gCmd2[4] = pDataParams2->bRequestCode2;
			gCmd2[5] = bNumTimeSlots2;
			gbNumTimeSlotsLast2 = bNumTimeSlots2;

			if(bNumTimeSlots2 > PHPAL_FELICA_NUMSLOTS_12)
			{
				/* Set RX Multiple feature of HW */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
						pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_RXMULTIPLE2,
						PH_ON2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}

			MSG_LOG_BUF2(TAG2, ">>> PHPAL_FELICA_REQUEST_SEND:", gCmd2, 6);
			pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_EXCHANGE2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_FELICA_REQC_EXCHANGE2:
			/* Exchange command */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
					pDataParams2->pHalDataParams2,
					PH_EXCHANGE_DEFAULT2,
					gCmd2,
					6,
					&pRxBufferTmp2,
					&wRxLengthTmp2));
#ifdef NXPBUILD__PH_LOG_EX2
			if (status2 == PH_ERR_SUCCESS2)
			{
				MSG_LOG_BUF2(TAG2, "<<< PHPAL_FELICA_REQUEST_RESPONSE:", pRxBufferTmp2, (uint8 )wRxLengthTmp2);
			}
			else
			{
				MSG_LOG2(TAG2, "<<< PHPAL_FELICA_REQUEST_RESPONSE: %0X\r\n", status2);
			}
#endif
			pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_EXCHANGE_FINISH2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_FELICA_REQC_EXCHANGE_FINISH2:
			if(gbNumTimeSlotsLast2 > PHPAL_FELICA_NUMSLOTS_12)
			{
				/* Re-Set RX Multiple feature of HW */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(
						pDataParams2->pHalDataParams2,
						PHHAL_HW_CONFIG_RXMULTIPLE2,
						PH_OFF2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}
			/* Error check */
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_CHECK_LENGTH2;
			return PH_STATUS_INPROCESS2;

		case PHPAL_FELICA_REQC_CHECK_LENGTH2:
			/* Check length and update info*/
			if(gbNumTimeSlotsLast2 > PHPAL_FELICA_NUMSLOTS_12)
			{
				/* Rx Length should be multiple of response frame size */
				if(0U != (wRxLengthTmp2 % PHPAL_FELICA_SW_RESP_FRAME_SIZE2))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
					break;
				}
				/* assign and update IDm and PMm and length */
				*ppRxBuffer2 = pRxBufferTmp2;
				*pRxLength2 = wRxLengthTmp2;

				pDataParams2->bTotalFrames2 = (uint8)(wRxLengthTmp2 / PHPAL_FELICA_SW_RESP_FRAME_SIZE2);
			}
			else
			{
				if (((wRxLengthTmp2 != (PHPAL_FELICA_ATQC_LENGTH2 + 1U)) &&
					(wRxLengthTmp2 != (PHPAL_FELICA_ATQC_LENGTH2 + PHPAL_FELICA_RD_LENGTH2 + 1U))) ||
					(pRxBufferTmp2[0] != wRxLengthTmp2) ||
					(pRxBufferTmp2[1] != PHPAL_FELICA_SW_RSP_REQC2))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
					break;
				}

				/* RC = 0 and card response with RD information */
				if((wRxLengthTmp2 == (PHPAL_FELICA_ATQC_LENGTH2 + PHPAL_FELICA_RD_LENGTH2 + 1U)) && (pDataParams2->bRequestCode2 == 0U))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
					break;
				}
				/* Store IDm and PMm or RC */
				(void)memcpy(pDataParams2->aIDmPMm2, &pRxBufferTmp2[2], (((uint32)(pRxBufferTmp2[0])) - 2U));

				/* Remove LEN Byte and Response Byte from response and assign start position of ID */
				*ppRxBuffer2 = &pRxBufferTmp2[PHPAL_FELICA_SW_LEN_BYTE_SIZE2 + PHPAL_FELICA_SW_RESP_REQC_SIZE2];
				*pRxLength2 = (uint16)(((uint16)pRxBufferTmp2[0]) - (PHPAL_FELICA_SW_LEN_BYTE_SIZE2 + PHPAL_FELICA_SW_RESP_REQC_SIZE2));
			}
			pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_VALID2;
			break;
	}
	wTimeOutUs2 = 0U;
	pRxBufferTmp2 = NULL;
	wRxLengthTmp2 = 0U;
	pDataParams2->eReqCState2 = PHPAL_FELICA_REQC_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE)  phpalFelica_Sw_GetFrameInfo2(
                                        P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bFrameNum2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer2,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus2,
                                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen2
                                        )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bError2 = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bStartPos2 = 0;

    /* check frame number */
    if((bFrameNum2 > pDataParams2->bTotalFrames2) || (bFrameNum2 == 0U) || (pResponseBuffer2 == NULL))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
    }

    *pwStatus2 = PH_ERR_SUCCESS2;

    /* get start position of frame */
    bStartPos2 = (uint8)(PHPAL_FELICA_SW_RESP_FRAME_SIZE2 * (bFrameNum2 - 1U));

    /* Check length */
    if( ((pResponseBuffer2[bStartPos2 + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS2] != (PHPAL_FELICA_ATQC_LENGTH2 + PHPAL_FELICA_SW_LEN_BYTE_SIZE2)) &&
        (pResponseBuffer2[bStartPos2 + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS2] != (PHPAL_FELICA_ATQC_LENGTH2 + PHPAL_FELICA_RD_LENGTH2 + PHPAL_FELICA_SW_LEN_BYTE_SIZE2))) ||
        (pResponseBuffer2[bStartPos2 + 1U] != PHPAL_FELICA_SW_RSP_REQC2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
    }

    /* RC = 0 and card response with RD information */
    if((pResponseBuffer2[bStartPos2 + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS2] == (PHPAL_FELICA_ATQC_LENGTH2 + PHPAL_FELICA_RD_LENGTH2 + PHPAL_FELICA_SW_LEN_BYTE_SIZE2)) && (pDataParams2->bRequestCode2 == 0U))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
    }

    /* Extract error from Status byte */
    bError2 = pResponseBuffer2[(bStartPos2) + PHHAL_HW_STATUS_FRAME_ERR_BYTE_POS2 ] & PHHAL_HW_STATUS_FRAME_ERR_MASK2;

    if(bError2 != 0x00U)
    {
        /* check for contact less error */
        if(0U != (bError2 & PHHAL_HW_STATUS_FRAME_CL_ERR_POS2))
        {
            /* check for protocol error */
            if(0U != (bError2 & PHHAL_HW_STATUS_FRAME_PROT_ERR_POS2))
            {
                *pwStatus2 = PH_ERR_PROTOCOL_ERROR2;
            }
            /* check for collision error */
            else if(0U != (bError2 & PHHAL_HW_STATUS_FRAME_COLL_ERR_POS2))
            {
                *pwStatus2 = PH_ERR_COLLISION_ERROR2;
            }
            /* check for Integrity error */
            else if(0U != (bError2 & PHHAL_HW_STATUS_FRAME_DATA_ERR_POS2))
            {
                *pwStatus2 = PH_ERR_INTEGRITY_ERROR2;
            }
            else
            {
                /* If CL Error is set and no Protocol, Collision, Integrity flag is set */
                return (PH_ERR_PROTOCOL_ERROR2 | PH_COMP_PAL_FELICA2);
            }
        }
        else
        {   /* Length error */
            *pwStatus2 = PH_ERR_LENGTH_ERROR2;
        }

    }
    else
    {
      /* Remove LEN Byte and Response Byte (0x01) from response and assign start position of ID */
      *ppID2 = &pResponseBuffer2[bStartPos2 + (PHPAL_FELICA_SW_LEN_BYTE_SIZE2 + PHPAL_FELICA_SW_RESP_REQC_SIZE2)];
      *pLen2 = pResponseBuffer2[bStartPos2 + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS2] - (PHPAL_FELICA_SW_LEN_BYTE_SIZE2 + PHPAL_FELICA_SW_RESP_REQC_SIZE2);
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_SetSerialNo2(
                                      P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2
                                      )
{

    pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_VALID2;
    /* copy IDm and PMm */
    (void)memcpy(pDataParams2->aIDmPMm2, pIDmPMm2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));

    return PH_ERR_SUCCESS2;

}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_ActivateCard2(
                                       P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2,
                                       VAR(uint8, ANFCRL_VAR) bIDmPMmLength2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                                       VAR(uint8, ANFCRL_VAR) bNumTimeSlots2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
                                       )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxBuff2 = NULL;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pId2 = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRxLen2 = 0U, wFrameStatus2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bTemp2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bNumTimeSlotsTmp2 = 0U;

	switch(pDataParams2->eActCardState2)
	{
		case PHPAL_FELICA_ACTCARD_START2:
			*pRxLength2 = 0;
			*pMoreCardsAvailable2 = 0;
			bNumTimeSlotsTmp2 = bNumTimeSlots2;

			/* if serial number is given only store it */
			if (0U != (bIDmPMmLength2))
			{
				/* check if IDm length is valid. */
				if (bIDmPMmLength2 != (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2))
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
				}

				/* Store IDm/PMm */
				(void)memcpy(pDataParams2->aIDmPMm2, pIDmPMm2, bIDmPMmLength2);
				pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_VALID2;

				return PH_ERR_SUCCESS2;
			}
			pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_REQC2;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_FELICA_ACTCARD_REQC2:
			/* RequestC == ReqC command (not requesting the system code) */
			PH_CHECK_INPROCESS_FCT2(status2, phpalFelica_Sw_ReqC2(
				pDataParams2,
				pSystemCode2,
				bNumTimeSlotsTmp2,
				&pRxBuff2,
				&wRxLen2));

			statusTmp2 = status2;

			if(bNumTimeSlotsTmp2 > PHPAL_FELICA_NUMSLOTS_12)
			{
				if(pDataParams2->bTotalFrames2 > 1U)
				{
					*pMoreCardsAvailable2 = 1;
				}
				else
				{
					/* Do nothing */
				}

				/* get total number of response frame */
				bTemp2 = pDataParams2->bTotalFrames2;
				pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_GET_FRAME_INFO2;
			}
			else
			{
				if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
				{
					*pRxLength2 = PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2;
					(void)memcpy(pRxBuffer2, pRxBuff2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));
					(void)memcpy(pDataParams2->aIDmPMm2, pRxBuff2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));
					pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_VALID2;
					break;
				}
				else
				{
					pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY2;
				}
			}
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHPAL_FELICA_ACTCARD_GET_FRAME_INFO2:
			if(0U != bTemp2)
			{
				*pRxLength2 = 0x00U;
				wFrameStatus2 = 0x00U;
				/* retrieve IDmPMm one by one for all frames */
				PH_CHECK_FAILURE_FCT2(status2,phpalFelica_Sw_GetFrameInfo2(
						pDataParams2,
						bTemp2,
						pRxBuff2,
						&wFrameStatus2,
						&pId2,
						pRxLength2));
				status2 = wFrameStatus2;
				/* store only one valid response and return */
				if(wFrameStatus2 == PH_ERR_SUCCESS2)
				{
					*pRxLength2 = PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2;
					(void)memcpy(pRxBuffer2, pId2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));
					(void)memcpy(pDataParams2->aIDmPMm2, pId2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));
					pDataParams2->bIDmPMmValid2 = PHPAL_FELICA_SW_IDMPMM_VALID2;
					break;
				}
				else
				{
					bTemp2--;
					return PH_STATUS_INPROCESS2;
				}
			}
			else
			{
				pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY2;
				return PH_STATUS_INPROCESS2;
			}
			/* no break */
		case PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY2:
			/* check for availability of more card */
			if((statusTmp2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
			{
				status2 = statusTmp2;
				*pMoreCardsAvailable2 = 1;
				bNumTimeSlotsTmp2 = (bNumTimeSlotsTmp2 << 1U) + 1U;
			}
			else
			{
				status2 = statusTmp2;
				break;
			}

			if (bNumTimeSlotsTmp2 <= PHPAL_FELICA_NUMSLOTS_162)
			{
				pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_REQC2;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Do nothing */
			}
			break;
		default:
			break;
	}

	pRxBuff2 = NULL;
	bTemp2 = 0U;
	bNumTimeSlotsTmp2 = 0U;
	pDataParams2->eActCardState2 = PHPAL_FELICA_ACTCARD_START2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_Exchange2(
                                   P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                   VAR(uint16, ANFCRL_VAR) wOption2,
                                   VAR(uint16, ANFCRL_VAR) wN2,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                   VAR(uint16, ANFCRL_VAR) wTxLength2,
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                   )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 aHeader2[2] = {0U};
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTimeoutUs2 = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempTxLength2 = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempOption2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSendStatus2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMarkers2 = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTempTxBuffer2 = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTparam2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bA2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bB2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bE2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pPMm2 = NULL;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTOut2 = 0U;

	/* [len][cmd] [IDm ... 8 bytes] [cmd parameters ...] */
	switch(pDataParams2->eExchangeState2)
	{
		case PHPAL_FELICA_EXCHANGE_SEND2:
			if(0U == bMarkers2)
			{
				wTempTxLength2 = wTxLength2;
				pTempTxBuffer2 = pTxBuffer2;
			}
			wTempOption2 = wOption2;
			/* Check if we do have an IDm */
			if (pDataParams2->bIDmPMmValid2 == PHPAL_FELICA_SW_IDMPMM_INVALID2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
			}

			/* Parameter check */
			if ((wTempTxLength2 + /* */ 2U) > PHPAL_FELICA_TXLENGTH_MAX2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
			}

			/* If the PH_EXCHANGE_LEAVE_BUFFER_BIT2 is NOT set, wOption2 is:
			~ PH_EXCHANGE_DEFAULT2:      we have the command byte and eventually parameter bytes (data),
			how ever, we already have all data to exchange the complete frame.
			~ PH_EXCHANGE_BUFFER_FIRST2: we have the command byte and eventually parameter bytes (data),
			but the callee wants to transmit some more.
			pDataParams2->bLength2 < 2 -> the cmd byte was not transmitted yet
			*/
			if ((0U == ((wTempOption2 & PH_EXCHANGE_LEAVE_BUFFER_BIT2))) || (pDataParams2->bLength2 < 2U))
			{
				switch(bSendStatus2)
				{
					case 0U:
						/* If there is nothing to transmit, we are done. */
						if (wTempTxLength2 == 0U)
						{
							return PH_ERR_SUCCESS2;
						}
						/* Prepare header */
						aHeader2[0] = 0x00;          /* This is just a dummy which is updated with the correct value later on,
													when the last chunk is ready to transmit. */
						aHeader2[1] = pTxBuffer2[0];
						bSendStatus2 = 1U;
						/*no break*/
					case 1U:
						PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
							pDataParams2->pHalDataParams2,
							PH_EXCHANGE_BUFFER_FIRST2,
							aHeader2,
							2,
							ppRxBuffer2,
							pRxLength2));
						PH_BREAK_ON_FAILURE2(status2);
						MSG_LOG_BUF2(TAG2, ">>> PHPAL_FELICA_EXCHANGE_SEND2:", aHeader2, (uint8 )2U);
						/* until now, we have transmitted 2 bytes: */
						pDataParams2->bLength2 = 2;

						/* following Hw_Echange calls shall not overwrite already buffered data */
						wTempOption2 |= PH_EXCHANGE_LEAVE_BUFFER_BIT2;

						/* Check if IDm has to be send */
						gCurrentCmd2 = (uint16)pTxBuffer2[0];
						bSendStatus2 = 2U;
						/*no break*/
					case 2U:
						switch (gCurrentCmd2)
						{
							case PHPAL_FELICA_SW_CMD_REQ_RESP2:
							case PHPAL_FELICA_SW_CMD_REQ_SERVICE2:
							case PHPAL_FELICA_SW_CMD_READ2:
							case PHPAL_FELICA_SW_CMD_WRITE2:
							case PHPAL_FELICA_SW_CMD_AUTH12:
							case PHPAL_FELICA_SW_CMD_AUTH22:
							case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE2:
							case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE2:
							case PHPAL_FELICA_SW_CMD_GET_SYS_STATUS2:
							case PHPAL_FELICA_SW_CMD_REQ_SPEC_VERSION2:
							case PHPAL_FELICA_SW_CMD_RESET_MODE2:
							case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V22:
							case PHPAL_FELICA_SW_CMD_AUTH1_V22:
							case PHPAL_FELICA_SW_CMD_AUTH2_V22:
							case PHPAL_FELICA_SW_CMD_READ_SECF_V22:
							case PHPAL_FELICA_SW_CMD_WRITE_SECF_V22:
							case PHPAL_FELICA_SW_CMD_UPDATE_RAND_ID2:
								/* If there is no more parameter bytes (data) to send, we adjust pointer and length
								for the LAST Exchange, the IDm */
								if (wTempTxLength2 == 1U)
								{
								    pTempTxBuffer2 = pDataParams2->aIDmPMm2;
									wTempTxLength2 = PHPAL_FELICA_IDM_LENGTH2;
								}
								else
								{
									switch (bMarkers2)
									{
									case 0U:
										/* Set pointer and length for the LAST exchange. */
									    pTempTxBuffer2++;
										wTempTxLength2 = wTempTxLength2 - 1u;
										bMarkers2 = 1;
										/*No break*/
									case 1U:
										/* Transmit the IDm */
										PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
											pDataParams2->pHalDataParams2,
											PH_EXCHANGE_BUFFER_CONT2,
											pDataParams2->aIDmPMm2,
											PHPAL_FELICA_IDM_LENGTH2,
											ppRxBuffer2,
											pRxLength2));
										PH_BREAK_ON_FAILURE2(status2);
										MSG_LOG_BUF2(TAG2, ">>> PHPAL_FELICA_EXCHANGE_SEND2:", pDataParams2->aIDmPMm2, (uint8 )PHPAL_FELICA_IDM_LENGTH2);
										pDataParams2->bLength2 = pDataParams2->bLength2 + PHPAL_FELICA_IDM_LENGTH2;
									}
								}
								break;
							default:
								/* Set pointer and length for the LAST exchange. */
							    pTempTxBuffer2++;
								wTempTxLength2 = wTempTxLength2 - 1u;
								break;
						}
						break;
				}
				aHeader2[0] = 0;
				aHeader2[1] = 0;
				bSendStatus2 = 0;
			}

			else
			{
				/* command byte already buffered */
				PH_CHECK_SUCCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_OFFSET2, 0x01));
				PH_CHECK_SUCCESS_FCT2(status2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER2, &gCurrentCmd2));
			}

			/* Length check */
			if ((pDataParams2->bLength2 + wTempTxLength2) > PHPAL_FELICA_TXLENGTH_MAX2)
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_LENGTH_ERROR2, PH_COMP_PAL_FELICA2);
				break;
			}
			pDataParams2->eExchangeState2 = PHPAL_FELICA_EXCHANGE_PUTBUFFER2;
			return PH_STATUS_INPROCESS2;
			/*No break*/
		case PHPAL_FELICA_EXCHANGE_PUTBUFFER2:
			/* If the PH_EXCHANGE_BUFFERED_BIT2 IS set, wOption2 is:
			~ PH_EXCHANGE_BUFFER_FIRST2, or
			~ PH_EXCHANGE_BUFFER_CONT2: This means that there is data which shall be put into the
			buffer but not to be sent yet since more data will follow. */
			if (0U != (wTempOption2 & (uint16)PH_EXCHANGE_BUFFERED_BIT2))
			{
				if (wTempTxLength2 > 0U)
				{
					/* Exchange command */
					PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
						pDataParams2->pHalDataParams2,
						wTempOption2,
						pTempTxBuffer2,
						wTempTxLength2,
						ppRxBuffer2,
						pRxLength2));
					PH_BREAK_ON_FAILURE2(status2);
					MSG_LOG_BUF2(TAG2, ">>> PHPAL_FELICA_EXCHANGE_SEND2:", pTxBuffer2, (uint8 )wTempTxLength2);
					pDataParams2->bLength2 = pDataParams2->bLength2 + (uint8)wTempTxLength2;
				}
				status2 = PH_ERR_SUCCESS2;
				break;
			}

			/* If the PH_EXCHANGE_BUFFERED_BIT2 is NOT set, wOption2 is:
			~ PH_EXCHANGE_DEFAULT2, or
			~ PH_EXCHANGE_BUFFER_LAST2: This means that either this is the last (or only) chunk
			of command parameters (data), which also could be of zero bytes.

			So this is the last chunk and we should received a response,
			which we extract the IDm bytes from and also check them. */
			pDataParams2->bLength2 = pDataParams2->bLength2 + (uint8)(wTempTxLength2);

			/* Update the length byte which had been sent before */
			PH_CHECK_FAILURE_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER_OFFSET2, 0x00));
			PH_CHECK_FAILURE_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXBUFFER2, (uint16)pDataParams2->bLength2));

			/* Reset pre-cached length */
			pDataParams2->bLength2 = 0x00;

			/* Get stored PMm */
			pPMm2 = &pDataParams2->aIDmPMm2[PHPAL_FELICA_IDM_LENGTH2];

			/* Command and PMm evaluation */
			switch(gCurrentCmd2)
			{
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE2:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V22:
					bTparam2 = pPMm2[2];
					break;
				case PHPAL_FELICA_SW_CMD_REQ_RESP2:
				case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE2:
				case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE2:
					bTparam2 = pPMm2[3];
					break;
				case PHPAL_FELICA_SW_CMD_AUTH12:
				case PHPAL_FELICA_SW_CMD_AUTH22:
				case PHPAL_FELICA_SW_CMD_AUTH1_V22:
				case PHPAL_FELICA_SW_CMD_AUTH2_V22:
					bTparam2 = pPMm2[4];
					break;
				case PHPAL_FELICA_SW_CMD_READ2:
				case PHPAL_FELICA_SW_CMD_READ_SECF2:
				case PHPAL_FELICA_SW_CMD_READ_SECF_V22:
					bTparam2 = pPMm2[5];
					break;
				case PHPAL_FELICA_SW_CMD_WRITE2:
				case PHPAL_FELICA_SW_CMD_WRITE_SECF2:
				case PHPAL_FELICA_SW_CMD_WRITE_SECF_V22:
					bTparam2 = pPMm2[6];
					break;
				default:
					bTparam2 = pPMm2[7];
					break;
			}

			/* Get timing parameters */
			bA2 = bTparam2 & 0x07U;
			bB2 = (bTparam2 >> 3U) & 0x07U;
			bE2 = (bTparam2 >> 6U) & 0x03U;

			/* Timeout calculation */
			/* Response time = T x [(B + 1U) x n + (A + 1U)] x 4^E */
			dwTOut2 = ((((uint32)bB2 + 1U) * (uint32)wN2) + ((uint32)bA2 + 1U));
			dwTimeoutUs2 = (uint32)(PHPAL_FELICA_SW_TIME_T_US2 * dwTOut2 * aFelica_E_Table2[bE2]);
			pDataParams2->eExchangeState2 = PHPAL_FELICA_EXCHANGE_TIMEOUT2;
			return PH_STATUS_INPROCESS2;
			/*no break*/
		case PHPAL_FELICA_EXCHANGE_TIMEOUT2:
			if (dwTimeoutUs2 > 0xFFFFU)
			{
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
					(uint16)(dwTimeoutUs2 / 1000U)));
			}
			/* Timeout setting in Microseconds */
			else
			{
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
					(uint16)dwTimeoutUs2));
			}
			PH_BREAK_ON_FAILURE2(status2);
			/* Exchange command */
			MSG_LOG_BUF2(TAG2, ">>> PHPAL_FELICA_EXCHANGE_SEND2:", pTxBuffer2, (uint8 )wTempTxLength2);
			pDataParams2->eExchangeState2 = PHPAL_FELICA_EXCHANGE_WAITRSP2;
			return PH_STATUS_INPROCESS2;
			/*No break*/
		case PHPAL_FELICA_EXCHANGE_WAITRSP2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Exchange2(
				pDataParams2->pHalDataParams2,
				PH_EXCHANGE_BUFFER_LAST2,
				pTempTxBuffer2,
				wTempTxLength2,
				ppRxBuffer2,
				pRxLength2));

#ifdef NXPBUILD__PH_LOG_EX2
			if (status2 == PH_ERR_SUCCESS2)
			{
				MSG_LOG_BUF2(TAG2, "<<< PHPAL_FELICA_EXCHANGE_RESPONSE:", *ppRxBuffer2, (uint8 )(*pRxLength2));
			}
			else
			{
				MSG_LOG2(TAG2, "<<< PHPAL_FELICA_EXCHANGE_RESPONSE: %0X\r\n", status2);
			}
#endif
			PH_BREAK_ON_FAILURE2(status2);
			/* Check length */
			if ((*pRxLength2 < 1U) || ((*ppRxBuffer2)[0] != *pRxLength2))
			{
				*pRxLength2 = 0;
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
				break;
			}

			/* Skip length */
			--(*pRxLength2);
			++(*ppRxBuffer2);

			/* Check response code */
			if ((*pRxLength2 < 1U) || ((*ppRxBuffer2)[0] != (gCurrentCmd2 + 1U)))
			{
				status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
				break;
			}

			/* Skip response code */
			--(*pRxLength2);
			++(ppRxBuffer2[0]);

			/* Check and skip IDm if received */
			switch (gCurrentCmd2)
			{
				case PHPAL_FELICA_SW_CMD_REQ_RESP2:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE2:
				case PHPAL_FELICA_SW_CMD_READ2:
				case PHPAL_FELICA_SW_CMD_WRITE2:
				case PHPAL_FELICA_SW_CMD_AUTH12:
				case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE2:
				case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE2:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V22:
				case PHPAL_FELICA_SW_CMD_AUTH1_V22:
				case PHPAL_FELICA_SW_CMD_GET_SYS_STATUS2:
				case PHPAL_FELICA_SW_CMD_REQ_SPEC_VERSION2:
				case PHPAL_FELICA_SW_CMD_RESET_MODE2:
				case PHPAL_FELICA_SW_CMD_UPDATE_RAND_ID2:
					/* Protocol error check */
					if (*pRxLength2 < PHPAL_FELICA_IDM_LENGTH2)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
						break;
					}

					/* We can only check the IDm if we have a valid one stored */
					if (memcmp(*ppRxBuffer2, pDataParams2->aIDmPMm2, PHPAL_FELICA_IDM_LENGTH2) != 0)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_PROTOCOL_ERROR2, PH_COMP_PAL_FELICA2);
						break;
					}

					/* Skip IDm */
					*pRxLength2 = *pRxLength2 - PHPAL_FELICA_IDM_LENGTH2;
					*ppRxBuffer2 = &((*ppRxBuffer2)[PHPAL_FELICA_IDM_LENGTH2]);
					break;
				default:
					break;
			}
	}
	bMarkers2 = 0U;
	gCurrentCmd2 = 0xffu;
	wTempTxLength2 = 0;
	wTempOption2 = 0;
	dwTimeoutUs2 = 0;
	pTempTxBuffer2 = NULL;
	pDataParams2->eExchangeState2 = PHPAL_FELICA_EXCHANGE_SEND2;
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_SetConfig2(
                                    P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    VAR(uint16, ANFCRL_VAR) wConfig2,
                                    VAR(uint16, ANFCRL_VAR) wValue2
                                    )
{
    switch(wConfig2)
    {
    case PHPAL_FELICA_CONFIG_RC2:
        if(((uint8)wValue2 != 0x00U) && ((uint8)wValue2 != 0x01U))
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
        }
        pDataParams2->bRequestCode2 = (uint8)(wValue2);
        break;

    case PHPAL_FELICA_PREAMBLE_LENGTH2:
        if(!((wValue2 == PHPAL_FELICA_PREAMBLE_LEN_48BITS2) ||
            (wValue2 == PHPAL_FELICA_PREAMBLE_LEN_56BITS2) ||
            (wValue2 == PHPAL_FELICA_PREAMBLE_LEN_64BITS2) ||
            (wValue2 == PHPAL_FELICA_PREAMBLE_LEN_72BITS2))
          )
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_PAL_FELICA2);
        }
        pDataParams2->bPreambleLen2 = (uint8)(wValue2);
        break;

    default:
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_FELICA2);
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_GetConfig2(
                                    P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    VAR(uint16, ANFCRL_VAR) wConfig2,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                    )
{
    switch(wConfig2)
    {
    case PHPAL_FELICA_CONFIG_RC2:
        *pValue2 = (uint16)pDataParams2->bRequestCode2;
        break;

    case PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES2:
        *pValue2 = (uint16)pDataParams2->bTotalFrames2;
        break;
    default:
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_PAL_FELICA2);
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_GetSerialNo2(
                                      P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut2
                                      )
{
    /* Return an error if IDm and PMm are not valid */
    if (pDataParams2->bIDmPMmValid2 == PHPAL_FELICA_SW_IDMPMM_INVALID2)
    {
        *pLenIDmPMmOut2 = 0;
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_PAL_FELICA2);
    }

    /* copy the IDm and PMm */
    (void)memcpy(pIDmPMmOut2, pDataParams2->aIDmPMm2, PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2);
    *pLenIDmPMmOut2 = PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2;

    return PH_ERR_SUCCESS2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef __cplusplus
}
#endif
