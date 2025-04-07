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
*   @file    phpalFelica_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalFelica Felica
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
#include <phpalFelica.h>
#include <ph_RefDefs.h>

#ifdef  NXPBUILD__PHPAL_FELICA_SW
#include "phpalFelica_Sw.h"
#include "phpalFelica_Sw_Int.h"
#include <phTools.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalFelica_Sw.h header file are of the same vendor */
#if (PHPALFELICA_SW_VENDOR_ID_C != PHPALFELICA_SW_VENDOR_ID)
    #error "phpalFelica_Sw.c and phpalFelica_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalFelica_Sw.h header file are of the same Autosar version */
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION_C != PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalFelica_Sw.c and phpalFelica_Sw.h are different"
#endif
/* Check if current file and phpalFelica_Sw.h header file are of the same Software version */
#if ((PHPALFELICA_SW_SW_MAJOR_VERSION_C != PHPALFELICA_SW_SW_MAJOR_VERSION) || \
     (PHPALFELICA_SW_SW_MINOR_VERSION_C != PHPALFELICA_SW_SW_MINOR_VERSION) || \
     (PHPALFELICA_SW_SW_PATCH_VERSION_C != PHPALFELICA_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalFelica_Sw.c and phpalFelica_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_FELICA_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef  NXPBUILD__PHPAL_FELICA_SW
#define FDTF_LISTEN_SENSF_REQ(x)    (PHPAL_FELICA_SW_T_DELAY_US + ((x) * PHPAL_FELICA_SW_T_TIMESLOT_US))    /**< NFC Forum Digital Protocol Technical Specification v1.1 : 8.7.1 : FDTF,LISTEN,SENSF_REQ */

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Table for 4^E evaluation (E is only 2 bits, so more values are not possible). */
static CONST(uint8, ANFCRL_CONST) PH_MEMLOC_CONST_ROM aFelica_E_Table[] = {1, 4, 16, 64};

#if (defined(NXPBUILD__PH_LOG_EX) && !defined(PH_LIB_LOG_DISABLE))
static P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) TAG = "  FELICA|";
#endif

static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM aFelica_TR1_Value_Us[][2] = {
    {PHPAL_FELICA_SW_TR1_48BITS_AT212_US, PHPAL_FELICA_SW_TR1_48BITS_AT424_US},
    {PHPAL_FELICA_SW_TR1_56BITS_AT212_US, PHPAL_FELICA_SW_TR1_56BITS_AT424_US},
    {PHPAL_FELICA_SW_TR1_64BITS_AT212_US, PHPAL_FELICA_SW_TR1_64BITS_AT424_US},
    {PHPAL_FELICA_SW_TR1_72BITS_AT212_US, PHPAL_FELICA_SW_TR1_72BITS_AT424_US},
};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) gCmd[16];

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint16, ANFCRL_VAR) gCurrentCmd = 0xffu;
static VAR(uint8, ANFCRL_VAR) gbNumTimeSlotsLast = 0u;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_Init(
                               P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                               )
{
    /* parameter structure length check */
    if (sizeof(phpalFelica_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_PAL_FELICA);
    }
    PH_ASSERT_NULL (pDataParams);
    PH_ASSERT_NULL (pHalDataParams);

    pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_START;
    pDataParams->eReqCState = PHPAL_FELICA_REQC_IDLE;

    /* init private data */
    pDataParams->wId            = PH_COMP_PAL_FELICA | PHPAL_FELICA_SW_ID;
    pDataParams->pHalDataParams = pHalDataParams;
    pDataParams->bIDmPMmValid   = PHPAL_FELICA_SW_IDMPMM_INVALID;
    pDataParams->bLength        = 0x00;
    pDataParams->bRequestCode   = 0x00;
    pDataParams->bPreambleLen   = PHPAL_FELICA_PREAMBLE_LEN_48BITS;

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_ReqC(
                P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                VAR(uint8, ANFCRL_VAR) bNumTimeSlots,
                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
								)
{
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTimeOutUs = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCardType = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTR1ValueUs = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBufferTmp = NULL;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLengthTmp = 0U;

	switch (pDataParams->eReqCState)
	{
		case PHPAL_FELICA_REQC_IDLE:
			status = PH_ERR_SUCCESS;
			/* reset validity of stored card IDs */
			pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_INVALID;

			/* Reset received frame count */
			pDataParams->bTotalFrames = 0;

			/* parameter check and timeout setting */
			if(!((bNumTimeSlots == PHPAL_FELICA_NUMSLOTS_1) ||
				(bNumTimeSlots == PHPAL_FELICA_NUMSLOTS_2) ||
				(bNumTimeSlots == PHPAL_FELICA_NUMSLOTS_4) ||
				(bNumTimeSlots == PHPAL_FELICA_NUMSLOTS_8) ||
				(bNumTimeSlots == PHPAL_FELICA_NUMSLOTS_16))
			  )
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
			}
			else
			{
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_GetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_CARD_TYPE,
					&wCardType));
				/* NFC Forum Digital Protocol Technical Specification v1.1
				 * 8.7.1.3 : wTimeOutUs = FDTF,LISTEN,SENSF_REQ(TSN+1U) - TR1 + (delta)TF,POLL
				 * Using TR1 value @212kbps */
				if ((wCardType != PHHAL_HW_CARDTYPE_FELICA_212) && (wCardType != PHHAL_HW_CARDTYPE_FELICA_424))
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_FELICA);
				}

				if (wCardType == PHHAL_HW_CARDTYPE_FELICA_212)
				{
					wTR1ValueUs = aFelica_TR1_Value_Us[pDataParams->bPreambleLen][0];
				}
				else
				{
					wTR1ValueUs = aFelica_TR1_Value_Us[pDataParams->bPreambleLen][1];
				}

				wTimeOutUs = FDTF_LISTEN_SENSF_REQ(((uint16)bNumTimeSlots) + 1U) - wTR1ValueUs + PHPAL_FELICA_SW_T_DELTA_F_POLL_US;
			}
			pDataParams->eReqCState = PHPAL_FELICA_REQC_TIMEOUT;
			return PH_STATUS_INPROCESS;
			/*no break*/

		case PHPAL_FELICA_REQC_TIMEOUT:
			/* Set ReqC timeout according to the number of slots */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
					wTimeOutUs));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eReqCState = PHPAL_FELICA_REQC_CONFIG;
			return PH_STATUS_INPROCESS;

		case PHPAL_FELICA_REQC_CONFIG:
			/* build the command frame */
			gCmd[0] = 6;
			gCurrentCmd = PHPAL_FELICA_SW_CMD_REQC;
			gCmd[1] = PHPAL_FELICA_SW_CMD_REQC;
			gCmd[2] = pSystemCode[0];
			gCmd[3] = pSystemCode[1];
			gCmd[4] = pDataParams->bRequestCode;
			gCmd[5] = bNumTimeSlots;
			gbNumTimeSlotsLast = bNumTimeSlots;

			if(bNumTimeSlots > PHPAL_FELICA_NUMSLOTS_1)
			{
				/* Set RX Multiple feature of HW */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXMULTIPLE,
						PH_ON));
				PH_BREAK_ON_FAILURE(statusTmp);
			}

			MSG_LOG_BUF(TAG, ">>> PHPAL_FELICA_REQUEST_SEND:", gCmd, 6);
			pDataParams->eReqCState = PHPAL_FELICA_REQC_EXCHANGE;
			return PH_STATUS_INPROCESS;

		case PHPAL_FELICA_REQC_EXCHANGE:
			/* Exchange command */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
					pDataParams->pHalDataParams,
					PH_EXCHANGE_DEFAULT,
					gCmd,
					6,
					&pRxBufferTmp,
					&wRxLengthTmp));
#ifdef NXPBUILD__PH_LOG_EX
			if (status == PH_ERR_SUCCESS)
			{
				MSG_LOG_BUF(TAG, "<<< PHPAL_FELICA_REQUEST_RESPONSE:", pRxBufferTmp, (uint8 )wRxLengthTmp);
			}
			else
			{
				MSG_LOG(TAG, "<<< PHPAL_FELICA_REQUEST_RESPONSE: %0X\r\n", status);
			}
#endif
			pDataParams->eReqCState = PHPAL_FELICA_REQC_EXCHANGE_FINISH;
			return PH_STATUS_INPROCESS;

		case PHPAL_FELICA_REQC_EXCHANGE_FINISH:
			if(gbNumTimeSlotsLast > PHPAL_FELICA_NUMSLOTS_1)
			{
				/* Re-Set RX Multiple feature of HW */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXMULTIPLE,
						PH_OFF));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			/* Error check */
			PH_BREAK_ON_FAILURE(status);
			pDataParams->eReqCState = PHPAL_FELICA_REQC_CHECK_LENGTH;
			return PH_STATUS_INPROCESS;

		case PHPAL_FELICA_REQC_CHECK_LENGTH:
			/* Check length and update info*/
			if(gbNumTimeSlotsLast > PHPAL_FELICA_NUMSLOTS_1)
			{
				/* Rx Length should be multiple of response frame size */
				if(0U != (wRxLengthTmp % PHPAL_FELICA_SW_RESP_FRAME_SIZE))
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
					break;
				}
				/* assign and update IDm and PMm and length */
				*ppRxBuffer = pRxBufferTmp;
				*pRxLength = wRxLengthTmp;

				pDataParams->bTotalFrames = (uint8)(wRxLengthTmp / PHPAL_FELICA_SW_RESP_FRAME_SIZE);
			}
			else
			{
				if (((wRxLengthTmp != (PHPAL_FELICA_ATQC_LENGTH + 1U)) &&
					(wRxLengthTmp != (PHPAL_FELICA_ATQC_LENGTH + PHPAL_FELICA_RD_LENGTH + 1U))) ||
					(pRxBufferTmp[0] != wRxLengthTmp) ||
					(pRxBufferTmp[1] != PHPAL_FELICA_SW_RSP_REQC))
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
					break;
				}

				/* RC = 0 and card response with RD information */
				if((wRxLengthTmp == (PHPAL_FELICA_ATQC_LENGTH + PHPAL_FELICA_RD_LENGTH + 1U)) && (pDataParams->bRequestCode == 0U))
				{
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
					break;
				}
				/* Store IDm and PMm or RC */
				(void)memcpy(pDataParams->aIDmPMm, &pRxBufferTmp[2], (((uint32)(pRxBufferTmp[0])) - 2U));

				/* Remove LEN Byte and Response Byte from response and assign start position of ID */
				*ppRxBuffer = &pRxBufferTmp[PHPAL_FELICA_SW_LEN_BYTE_SIZE + PHPAL_FELICA_SW_RESP_REQC_SIZE];
				*pRxLength = (uint16)(((uint16)pRxBufferTmp[0]) - (PHPAL_FELICA_SW_LEN_BYTE_SIZE + PHPAL_FELICA_SW_RESP_REQC_SIZE));
			}
			pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_VALID;
			break;
	}
	wTimeOutUs = 0U;
	pRxBufferTmp = NULL;
	wRxLengthTmp = 0U;
	pDataParams->eReqCState = PHPAL_FELICA_REQC_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE)  phpalFelica_Sw_GetFrameInfo(
                                        P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint8, ANFCRL_VAR) bFrameNum,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus,
                                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen
                                        )
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bError = 0;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bStartPos = 0;

    /* check frame number */
    if((bFrameNum > pDataParams->bTotalFrames) || (bFrameNum == 0U) || (pResponseBuffer == NULL))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
    }

    *pwStatus = PH_ERR_SUCCESS;

    /* get start position of frame */
    bStartPos = (uint8)(PHPAL_FELICA_SW_RESP_FRAME_SIZE * (bFrameNum - 1U));

    /* Check length */
    if( ((pResponseBuffer[bStartPos + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS] != (PHPAL_FELICA_ATQC_LENGTH + PHPAL_FELICA_SW_LEN_BYTE_SIZE)) &&
        (pResponseBuffer[bStartPos + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS] != (PHPAL_FELICA_ATQC_LENGTH + PHPAL_FELICA_RD_LENGTH + PHPAL_FELICA_SW_LEN_BYTE_SIZE))) ||
        (pResponseBuffer[bStartPos + 1U] != PHPAL_FELICA_SW_RSP_REQC))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
    }

    /* RC = 0 and card response with RD information */
    if((pResponseBuffer[bStartPos + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS] == (PHPAL_FELICA_ATQC_LENGTH + PHPAL_FELICA_RD_LENGTH + PHPAL_FELICA_SW_LEN_BYTE_SIZE)) && (pDataParams->bRequestCode == 0U))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
    }

    /* Extract error from Status byte */
    bError = pResponseBuffer[(bStartPos) + PHHAL_HW_STATUS_FRAME_ERR_BYTE_POS ] & PHHAL_HW_STATUS_FRAME_ERR_MASK;

    if(bError != 0x00U)
    {
        /* check for contact less error */
        if(0U != (bError & PHHAL_HW_STATUS_FRAME_CL_ERR_POS))
        {
            /* check for protocol error */
            if(0U != (bError & PHHAL_HW_STATUS_FRAME_PROT_ERR_POS))
            {
                *pwStatus = PH_ERR_PROTOCOL_ERROR;
            }
            /* check for collision error */
            else if(0U != (bError & PHHAL_HW_STATUS_FRAME_COLL_ERR_POS))
            {
                *pwStatus = PH_ERR_COLLISION_ERROR;
            }
            /* check for Integrity error */
            else if(0U != (bError & PHHAL_HW_STATUS_FRAME_DATA_ERR_POS))
            {
                *pwStatus = PH_ERR_INTEGRITY_ERROR;
            }
            else
            {
                /* If CL Error is set and no Protocol, Collision, Integrity flag is set */
                return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_FELICA);
            }
        }
        else
        {   /* Length error */
            *pwStatus = PH_ERR_LENGTH_ERROR;
        }

    }
    else
    {
      /* Remove LEN Byte and Response Byte (0x01) from response and assign start position of ID */
      *ppID = &pResponseBuffer[bStartPos + (PHPAL_FELICA_SW_LEN_BYTE_SIZE + PHPAL_FELICA_SW_RESP_REQC_SIZE)];
      *pLen = pResponseBuffer[bStartPos + PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS] - (PHPAL_FELICA_SW_LEN_BYTE_SIZE + PHPAL_FELICA_SW_RESP_REQC_SIZE);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_SetSerialNo(
                                      P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm
                                      )
{

    pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_VALID;
    /* copy IDm and PMm */
    (void)memcpy(pDataParams->aIDmPMm, pIDmPMm, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));

    return PH_ERR_SUCCESS;

}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_ActivateCard(
                                       P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm,
                                       VAR(uint8, ANFCRL_VAR) bIDmPMmLength,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,
                                       VAR(uint8, ANFCRL_VAR) bNumTimeSlots,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
                                       )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuff = NULL;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pId = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLen = 0U, wFrameStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) bTemp = 0U;
	static VAR(uint8, ANFCRL_VAR) bNumTimeSlotsTmp = 0U;

	switch(pDataParams->eActCardState)
	{
		case PHPAL_FELICA_ACTCARD_START:
			*pRxLength = 0;
			*pMoreCardsAvailable = 0;
			bNumTimeSlotsTmp = bNumTimeSlots;

			/* if serial number is given only store it */
			if (0U != (bIDmPMmLength))
			{
				/* check if IDm length is valid. */
				if (bIDmPMmLength != (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH))
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
				}

				/* Store IDm/PMm */
				(void)memcpy(pDataParams->aIDmPMm, pIDmPMm, bIDmPMmLength);
				pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_VALID;

				return PH_ERR_SUCCESS;
			}
			pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_REQC;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_FELICA_ACTCARD_REQC:
			/* RequestC == ReqC command (not requesting the system code) */
			PH_CHECK_INPROCESS_FCT(status, phpalFelica_Sw_ReqC(
				pDataParams,
				pSystemCode,
				bNumTimeSlotsTmp,
				&pRxBuff,
				&wRxLen));

			statusTmp = status;

			if(bNumTimeSlotsTmp > PHPAL_FELICA_NUMSLOTS_1)
			{
				if(pDataParams->bTotalFrames > 1U)
				{
					*pMoreCardsAvailable = 1;
				}
				else
				{
					/* Do nothing */
				}

				/* get total number of response frame */
				bTemp = pDataParams->bTotalFrames;
				pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_GET_FRAME_INFO;
			}
			else
			{
				if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
				{
					*pRxLength = PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH;
					(void)memcpy(pRxBuffer, pRxBuff, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));
					(void)memcpy(pDataParams->aIDmPMm, pRxBuff, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));
					pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_VALID;
					break;
				}
				else
				{
					pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY;
				}
			}
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHPAL_FELICA_ACTCARD_GET_FRAME_INFO:
			if(0U != bTemp)
			{
				*pRxLength = 0x00U;
				wFrameStatus = 0x00U;
				/* retrieve IDmPMm one by one for all frames */
				PH_CHECK_FAILURE_FCT(status,phpalFelica_Sw_GetFrameInfo(
						pDataParams,
						bTemp,
						pRxBuff,
						&wFrameStatus,
						&pId,
						pRxLength));
				status = wFrameStatus;
				/* store only one valid response and return */
				if(wFrameStatus == PH_ERR_SUCCESS)
				{
					*pRxLength = PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH;
					(void)memcpy(pRxBuffer, pId, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));
					(void)memcpy(pDataParams->aIDmPMm, pId, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));
					pDataParams->bIDmPMmValid = PHPAL_FELICA_SW_IDMPMM_VALID;
					break;
				}
				else
				{
					bTemp--;
					return PH_STATUS_INPROCESS;
				}
			}
			else
			{
				pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY:
			/* check for availability of more card */
			if((statusTmp & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
			{
				status = statusTmp;
				*pMoreCardsAvailable = 1;
				bNumTimeSlotsTmp = (bNumTimeSlotsTmp << 1U) + 1U;
			}
			else
			{
				status = statusTmp;
				break;
			}

			if (bNumTimeSlotsTmp <= PHPAL_FELICA_NUMSLOTS_16)
			{
				pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_REQC;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Do nothing */
			}
			break;
		default:
			break;
	}

	pRxBuff = NULL;
	bTemp = 0U;
	bNumTimeSlotsTmp = 0U;
	pDataParams->eActCardState = PHPAL_FELICA_ACTCARD_START;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_Exchange(
                                   P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                   VAR(uint16, ANFCRL_VAR) wOption,
                                   VAR(uint16, ANFCRL_VAR) wN,
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                   VAR(uint16, ANFCRL_VAR) wTxLength,
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                   )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aHeader[2] = {0U};
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTimeoutUs = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempTxLength = 0U;
	static VAR(uint16, ANFCRL_VAR) wTempOption = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSendStatus = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMarkers = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTempTxBuffer = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTparam = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bA = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bB = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bE = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pPMm = NULL;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTOut = 0U;

	/* [len][cmd] [IDm ... 8 bytes] [cmd parameters ...] */
	switch(pDataParams->eExchangeState)
	{
		case PHPAL_FELICA_EXCHANGE_SEND:
			if(0U == bMarkers)
			{
				wTempTxLength = wTxLength;
				pTempTxBuffer = pTxBuffer;
			}
			wTempOption = wOption;
			/* Check if we do have an IDm */
			if (pDataParams->bIDmPMmValid == PHPAL_FELICA_SW_IDMPMM_INVALID)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
			}

			/* Parameter check */
			if ((wTempTxLength + /* */ 2U) > PHPAL_FELICA_TXLENGTH_MAX)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
			}

			/* If the PH_EXCHANGE_LEAVE_BUFFER_BIT is NOT set, wOption is:
			~ PH_EXCHANGE_DEFAULT:      we have the command byte and eventually parameter bytes (data),
			how ever, we already have all data to exchange the complete frame.
			~ PH_EXCHANGE_BUFFER_FIRST: we have the command byte and eventually parameter bytes (data),
			but the callee wants to transmit some more.
			pDataParams->bLength < 2 -> the cmd byte was not transmitted yet
			*/
			if ((0U == ((wTempOption & PH_EXCHANGE_LEAVE_BUFFER_BIT))) || (pDataParams->bLength < 2U))
			{
				switch(bSendStatus)
				{
					case 0U:
						/* If there is nothing to transmit, we are done. */
						if (wTempTxLength == 0U)
						{
							return PH_ERR_SUCCESS;
						}
						/* Prepare header */
						aHeader[0] = 0x00;          /* This is just a dummy which is updated with the correct value later on,
													when the last chunk is ready to transmit. */
						aHeader[1] = pTxBuffer[0];
						bSendStatus = 1U;
						/*no break*/
					case 1U:
						PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
							pDataParams->pHalDataParams,
							PH_EXCHANGE_BUFFER_FIRST,
							aHeader,
							2,
							ppRxBuffer,
							pRxLength));
						PH_BREAK_ON_FAILURE(status);
						MSG_LOG_BUF(TAG, ">>> PHPAL_FELICA_EXCHANGE_SEND:", aHeader, (uint8 )2U);
						/* until now, we have transmitted 2 bytes: */
						pDataParams->bLength = 2;

						/* following Hw_Echange calls shall not overwrite already buffered data */
						wTempOption |= PH_EXCHANGE_LEAVE_BUFFER_BIT;

						/* Check if IDm has to be send */
						gCurrentCmd = (uint16)pTxBuffer[0];
						bSendStatus = 2U;
						/*no break*/
					case 2U:
						switch (gCurrentCmd)
						{
							case PHPAL_FELICA_SW_CMD_REQ_RESP:
							case PHPAL_FELICA_SW_CMD_REQ_SERVICE:
							case PHPAL_FELICA_SW_CMD_READ:
							case PHPAL_FELICA_SW_CMD_WRITE:
							case PHPAL_FELICA_SW_CMD_AUTH1:
							case PHPAL_FELICA_SW_CMD_AUTH2:
							case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE:
							case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE:
							case PHPAL_FELICA_SW_CMD_GET_SYS_STATUS:
							case PHPAL_FELICA_SW_CMD_REQ_SPEC_VERSION:
							case PHPAL_FELICA_SW_CMD_RESET_MODE:
							case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V2:
							case PHPAL_FELICA_SW_CMD_AUTH1_V2:
							case PHPAL_FELICA_SW_CMD_AUTH2_V2:
							case PHPAL_FELICA_SW_CMD_READ_SECF_V2:
							case PHPAL_FELICA_SW_CMD_WRITE_SECF_V2:
							case PHPAL_FELICA_SW_CMD_UPDATE_RAND_ID:
								/* If there is no more parameter bytes (data) to send, we adjust pointer and length
								for the LAST Exchange, the IDm */
								if (wTempTxLength == 1U)
								{
								    pTempTxBuffer = pDataParams->aIDmPMm;
									wTempTxLength = PHPAL_FELICA_IDM_LENGTH;
								}
								else
								{
									switch (bMarkers)
									{
									case 0U:
										/* Set pointer and length for the LAST exchange. */
									    pTempTxBuffer++;
										wTempTxLength = wTempTxLength - 1u;
										bMarkers = 1;
										/*No break*/
									case 1U:
										/* Transmit the IDm */
										PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
											pDataParams->pHalDataParams,
											PH_EXCHANGE_BUFFER_CONT,
											pDataParams->aIDmPMm,
											PHPAL_FELICA_IDM_LENGTH,
											ppRxBuffer,
											pRxLength));
										PH_BREAK_ON_FAILURE(status);
										MSG_LOG_BUF(TAG, ">>> PHPAL_FELICA_EXCHANGE_SEND:", pDataParams->aIDmPMm, (uint8 )PHPAL_FELICA_IDM_LENGTH);
										pDataParams->bLength = pDataParams->bLength + PHPAL_FELICA_IDM_LENGTH;
									}
								}
								break;
							default:
								/* Set pointer and length for the LAST exchange. */
							    pTempTxBuffer++;
								wTempTxLength = wTempTxLength - 1u;
								break;
						}
						break;
				}
				aHeader[0] = 0;
				aHeader[1] = 0;
				bSendStatus = 0;
			}

			else
			{
				/* command byte already buffered */
				PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, 0x01));
				PH_CHECK_SUCCESS_FCT(status, phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, &gCurrentCmd));
			}

			/* Length check */
			if ((pDataParams->bLength + wTempTxLength) > PHPAL_FELICA_TXLENGTH_MAX)
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_LENGTH_ERROR, PH_COMP_PAL_FELICA);
				break;
			}
			pDataParams->eExchangeState = PHPAL_FELICA_EXCHANGE_PUTBUFFER;
			return PH_STATUS_INPROCESS;
			/*No break*/
		case PHPAL_FELICA_EXCHANGE_PUTBUFFER:
			/* If the PH_EXCHANGE_BUFFERED_BIT IS set, wOption is:
			~ PH_EXCHANGE_BUFFER_FIRST, or
			~ PH_EXCHANGE_BUFFER_CONT: This means that there is data which shall be put into the
			buffer but not to be sent yet since more data will follow. */
			if (0U != (wTempOption & (uint16)PH_EXCHANGE_BUFFERED_BIT))
			{
				if (wTempTxLength > 0U)
				{
					/* Exchange command */
					PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
						pDataParams->pHalDataParams,
						wTempOption,
						pTempTxBuffer,
						wTempTxLength,
						ppRxBuffer,
						pRxLength));
					PH_BREAK_ON_FAILURE(status);
					MSG_LOG_BUF(TAG, ">>> PHPAL_FELICA_EXCHANGE_SEND:", pTxBuffer, (uint8 )wTempTxLength);
					pDataParams->bLength = pDataParams->bLength + (uint8)wTempTxLength;
				}
				status = PH_ERR_SUCCESS;
				break;
			}

			/* If the PH_EXCHANGE_BUFFERED_BIT is NOT set, wOption is:
			~ PH_EXCHANGE_DEFAULT, or
			~ PH_EXCHANGE_BUFFER_LAST: This means that either this is the last (or only) chunk
			of command parameters (data), which also could be of zero bytes.

			So this is the last chunk and we should received a response,
			which we extract the IDm bytes from and also check them. */
			pDataParams->bLength = pDataParams->bLength + (uint8)(wTempTxLength);

			/* Update the length byte which had been sent before */
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, 0x00));
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, (uint16)pDataParams->bLength));

			/* Reset pre-cached length */
			pDataParams->bLength = 0x00;

			/* Get stored PMm */
			pPMm = &pDataParams->aIDmPMm[PHPAL_FELICA_IDM_LENGTH];

			/* Command and PMm evaluation */
			switch(gCurrentCmd)
			{
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V2:
					bTparam = pPMm[2];
					break;
				case PHPAL_FELICA_SW_CMD_REQ_RESP:
				case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE:
				case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE:
					bTparam = pPMm[3];
					break;
				case PHPAL_FELICA_SW_CMD_AUTH1:
				case PHPAL_FELICA_SW_CMD_AUTH2:
				case PHPAL_FELICA_SW_CMD_AUTH1_V2:
				case PHPAL_FELICA_SW_CMD_AUTH2_V2:
					bTparam = pPMm[4];
					break;
				case PHPAL_FELICA_SW_CMD_READ:
				case PHPAL_FELICA_SW_CMD_READ_SECF:
				case PHPAL_FELICA_SW_CMD_READ_SECF_V2:
					bTparam = pPMm[5];
					break;
				case PHPAL_FELICA_SW_CMD_WRITE:
				case PHPAL_FELICA_SW_CMD_WRITE_SECF:
				case PHPAL_FELICA_SW_CMD_WRITE_SECF_V2:
					bTparam = pPMm[6];
					break;
				default:
					bTparam = pPMm[7];
					break;
			}

			/* Get timing parameters */
			bA = bTparam & 0x07U;
			bB = (bTparam >> 3U) & 0x07U;
			bE = (bTparam >> 6U) & 0x03U;

			/* Timeout calculation */
			/* Response time = T x [(B + 1U) x n + (A + 1U)] x 4^E */
			dwTOut = ((((uint32)bB + 1U) * (uint32)wN) + ((uint32)bA + 1U));
			dwTimeoutUs = (uint32)(PHPAL_FELICA_SW_TIME_T_US * dwTOut * aFelica_E_Table[bE]);
			pDataParams->eExchangeState = PHPAL_FELICA_EXCHANGE_TIMEOUT;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHPAL_FELICA_EXCHANGE_TIMEOUT:
			if (dwTimeoutUs > 0xFFFFU)
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
					(uint16)(dwTimeoutUs / 1000U)));
			}
			/* Timeout setting in Microseconds */
			else
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
					(uint16)dwTimeoutUs));
			}
			PH_BREAK_ON_FAILURE(status);
			/* Exchange command */
			MSG_LOG_BUF(TAG, ">>> PHPAL_FELICA_EXCHANGE_SEND:", pTxBuffer, (uint8 )wTempTxLength);
			pDataParams->eExchangeState = PHPAL_FELICA_EXCHANGE_WAITRSP;
			return PH_STATUS_INPROCESS;
			/*No break*/
		case PHPAL_FELICA_EXCHANGE_WAITRSP:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Exchange(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_BUFFER_LAST,
				pTempTxBuffer,
				wTempTxLength,
				ppRxBuffer,
				pRxLength));

#ifdef NXPBUILD__PH_LOG_EX
			if (status == PH_ERR_SUCCESS)
			{
				MSG_LOG_BUF(TAG, "<<< PHPAL_FELICA_EXCHANGE_RESPONSE:", *ppRxBuffer, (uint8 )(*pRxLength));
			}
			else
			{
				MSG_LOG(TAG, "<<< PHPAL_FELICA_EXCHANGE_RESPONSE: %0X\r\n", status);
			}
#endif
			PH_BREAK_ON_FAILURE(status);
			/* Check length */
			if ((*pRxLength < 1U) || ((*ppRxBuffer)[0] != *pRxLength))
			{
				*pRxLength = 0;
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
				break;
			}

			/* Skip length */
			--(*pRxLength);
			++(*ppRxBuffer);

			/* Check response code */
			if ((*pRxLength < 1U) || ((*ppRxBuffer)[0] != (gCurrentCmd + 1U)))
			{
				status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
				break;
			}

			/* Skip response code */
			--(*pRxLength);
			++(ppRxBuffer[0]);

			/* Check and skip IDm if received */
			switch (gCurrentCmd)
			{
				case PHPAL_FELICA_SW_CMD_REQ_RESP:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE:
				case PHPAL_FELICA_SW_CMD_READ:
				case PHPAL_FELICA_SW_CMD_WRITE:
				case PHPAL_FELICA_SW_CMD_AUTH1:
				case PHPAL_FELICA_SW_CMD_SEARCH_SERVICE:
				case PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE:
				case PHPAL_FELICA_SW_CMD_REQ_SERVICE_V2:
				case PHPAL_FELICA_SW_CMD_AUTH1_V2:
				case PHPAL_FELICA_SW_CMD_GET_SYS_STATUS:
				case PHPAL_FELICA_SW_CMD_REQ_SPEC_VERSION:
				case PHPAL_FELICA_SW_CMD_RESET_MODE:
				case PHPAL_FELICA_SW_CMD_UPDATE_RAND_ID:
					/* Protocol error check */
					if (*pRxLength < PHPAL_FELICA_IDM_LENGTH)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
						break;
					}

					/* We can only check the IDm if we have a valid one stored */
					if (memcmp(*ppRxBuffer, pDataParams->aIDmPMm, PHPAL_FELICA_IDM_LENGTH) != 0)
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_PROTOCOL_ERROR, PH_COMP_PAL_FELICA);
						break;
					}

					/* Skip IDm */
					*pRxLength = *pRxLength - PHPAL_FELICA_IDM_LENGTH;
					*ppRxBuffer = &((*ppRxBuffer)[PHPAL_FELICA_IDM_LENGTH]);
					break;
				default:
					break;
			}
	}
	bMarkers = 0U;
	gCurrentCmd = 0xffu;
	wTempTxLength = 0;
	wTempOption = 0;
	dwTimeoutUs = 0;
	pTempTxBuffer = NULL;
	pDataParams->eExchangeState = PHPAL_FELICA_EXCHANGE_SEND;
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_SetConfig(
                                    P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wConfig,
                                    VAR(uint16, ANFCRL_VAR) wValue
                                    )
{
    switch(wConfig)
    {
    case PHPAL_FELICA_CONFIG_RC:
        if(((uint8)wValue != 0x00U) && ((uint8)wValue != 0x01U))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
        }
        pDataParams->bRequestCode = (uint8)(wValue);
        break;

    case PHPAL_FELICA_PREAMBLE_LENGTH:
        if(!((wValue == PHPAL_FELICA_PREAMBLE_LEN_48BITS) ||
            (wValue == PHPAL_FELICA_PREAMBLE_LEN_56BITS) ||
            (wValue == PHPAL_FELICA_PREAMBLE_LEN_64BITS) ||
            (wValue == PHPAL_FELICA_PREAMBLE_LEN_72BITS))
          )
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_PAL_FELICA);
        }
        pDataParams->bPreambleLen = (uint8)(wValue);
        break;

    default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_FELICA);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_GetConfig(
                                    P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    VAR(uint16, ANFCRL_VAR) wConfig,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                    )
{
    switch(wConfig)
    {
    case PHPAL_FELICA_CONFIG_RC:
        *pValue = (uint16)pDataParams->bRequestCode;
        break;

    case PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES:
        *pValue = (uint16)pDataParams->bTotalFrames;
        break;
    default:
            return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_PAL_FELICA);
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalFelica_Sw_GetSerialNo(
                                      P2VAR(phpalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut
                                      )
{
    /* Return an error if IDm and PMm are not valid */
    if (pDataParams->bIDmPMmValid == PHPAL_FELICA_SW_IDMPMM_INVALID)
    {
        *pLenIDmPMmOut = 0;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_PAL_FELICA);
    }

    /* copy the IDm and PMm */
    (void)memcpy(pIDmPMmOut, pDataParams->aIDmPMm, PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH);
    *pLenIDmPMmOut = PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH;

    return PH_ERR_SUCCESS;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_FELICA_SW */

#ifdef __cplusplus
}
#endif
