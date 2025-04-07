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
*   @file    phhalHw_Ncx3321_InstMngr.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_InstMngr - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#include <ph_RefDefs.h>
#include <ph_Status.h>
#include <phhalHw.h>

#ifdef NXPBUILD__PHHAL_HW_NCX3321
#include <phDriver.h>
#ifndef AUTOSAR_VER

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection.h>

#endif	/* NIDEC_PORTING */   /* NIDEC_PORTING */
#endif

#include <phTools.h>
#include "phhalHw_Ncx3321.h"
#include <phhalHw_Ncx3321_Instr.h>
#include "phhalHw_Ncx3321_Int.h"
#include "phhalHw_Ncx3321_InstrMngr.h"
#include "phhalHw_Ncx3321_Wait.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_InstMngr.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTMNGR_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTMNGR_VENDOR_ID_C != PHHALHW_NCX3321_INSTMNGR_VENDOR_ID)
    #error "phhalHw_Ncx3321_InstMngr.c and phhalHw_Ncx3321_InstMngr.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION_C != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_InstMngr.c and phhalHw_Ncx3321_InstMngr.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION_C != PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION_C != PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION_C != PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_InstMngr.c and phhalHw_Ncx3321_InstMngr.h are different"
#endif
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
/* 1 Byte Command Code + 2 Bytes of Length*/
#define CMD_HEADER_LONG         3U

#define SEND                    0x01U
#define QUEUE                   0x02U
#define QUEUE_N_SEND            0x03U

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

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static FUNC(uint8, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_CheckBuffSpace(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wCurrSpaceNeeded);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Procss_Cmds(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint16, ANFCRL_VAR) wOptions);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Exchange(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint8, ANFCRL_VAR) bExchAction);

static FUNC(uint16, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepSnglTlv(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams,
    VAR(uint16, ANFCRL_VAR) wTxBuff_Offset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepTlv_RFData(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, VAR(uint8, ANFCRL_VAR) bExchAction);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendSnglTlv(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wSnglTLVLenght);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendBuffdData(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Transceive(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint16, ANFCRL_VAR) wTlv_Length);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_HandleCmd(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint16, ANFCRL_VAR) wOptions)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrTotalTxLength = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSpaceAvailable = 0u;

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
#ifdef DEBUG
			if ((pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_FIELD_OFF) && (pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA)
					&& (pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA) && (pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA)
					&& (pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_GET_DIE_ID) && (pCmdParams->bCmd != PHHAL_HW_NCX3321_INSTR_GET_VERSION))
			{
				if (pCmdParams->wTxDataLength == 0U)
				{
					return PH_ERR_INVALID_PARAMETER;
				}
			}
#endif

			wCurrTotalTxLength = pCmdParams->wTxDataLength + pCmdParams->wAddnDataLen + CMD_HEADER_LONG + 1U;

			bSpaceAvailable = phhalHw_Ncx3321_InstMngr_CheckBuffSpace(pDataParams, wCurrTotalTxLength);

			if (bSpaceAvailable == 0u)
			{
				pDataParams->wTxBufLen = 0U;
				pDataParams->wTxBufStartPos = 0U;

				status = PH_ERR_BUFFER_OVERFLOW;
				break;
			}
			/*If the buffer has enough space go to next state*/
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_Procss_Cmds(pDataParams, pCmdParams, wOptions));
			break;
	}

	return status;
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Procss_Cmds(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint16, ANFCRL_VAR) wOptions)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			pDataParams->bExchAction = QUEUE_N_SEND;
			if ((pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA) || (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA) ||
				(pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_RECEIVE_RF_DATA) || (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA))
			{
				pDataParams->bNonRF_Cmd = 0U;

				if ((wOptions & PH_EXCHANGE_BUFFERED_BIT) != 0U)
				{
					pDataParams->bExchAction = QUEUE;
				}
			}
			else
			{
				pDataParams->bNonRF_Cmd = 1U;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_Exchange(pDataParams, pCmdParams, pDataParams->bExchAction));
			break;
	}

	return status;
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Exchange(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint8, ANFCRL_VAR) bExchAction)
{

  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM dwEventFlags = 0U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSnglTLVLenght = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBufferLen = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBufferSize = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTxBuffer = NULL;

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			if ((bExchAction & QUEUE) != 0x00U)
			{
				if (pDataParams->bNonRF_Cmd != 0U)
				{
					/*RF_Exchange is in Progress, prep TLV in different Buff */
					wSnglTLVLenght = phhalHw_Ncx3321_InstMngr_PrepSnglTlv(pDataParams, pCmdParams, 0, &pDataParams->pInstrBuffer[1]);
				}
				else
				{
					(void)phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pTxBuffer, &wTxBufferLen, &wTxBufferSize);

					(void)phhalHw_Ncx3321_InstMngr_PrepTlv_RFData(pDataParams, pCmdParams, pTxBuffer, bExchAction);
				}
			}

			if ((bExchAction & SEND) == 0u)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			if ((pDataParams->bPollGuardTimeFlag == PH_ON) && (pDataParams->bNonRF_Cmd == 0U))
			{
				/* Wait infinitely for the Poll Guard Time to expire. */
				PH_CHECK_INPROCESS_FCT(status, phTools_EventPend(&pDataParams->HwEventObj, E_EVENT_OPT_PEND_SET_ANY | E_EVENT_OPT_PEND_CLEAR_ON_EXIT,
						PHHAL_HW_MAX_DELAY, E_EVENT_GT_EXP | E_EVENT_ABORT, &dwEventFlags));
				pDataParams->bPollGuardTimeFlag = PH_OFF;
				if(0U != (dwEventFlags & E_EVENT_ABORT))
				{
				    (void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_EVENT_ABORT, NULL);
					status = PH_ERR_ABORTED;
					break;
				}
				(void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_EVENT_RF, NULL);
			}
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_Transceive(pDataParams, pCmdParams, wSnglTLVLenght));
			break;
	}

	return status;
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepTlv_RFData(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, VAR(uint8, ANFCRL_VAR) bExchAction)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTxBuffOffset = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCmd = pCmdParams->bCmd;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pData = pCmdParams->pTxDataBuff;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLength = pCmdParams->wTxDataLength;

	if (pDataParams->wTxBufStartPos == 0U)
	{
		pTxBuffer[pDataParams->wTxBufStartPos++] = bCmd; /* Reserved 0th Location of buffer for Command code */
	}
	else
	{
		pDataParams->pTxBuffer[0] = bCmd;
	}

	bTxBuffOffset = 2;

	/* Copy Additional data required by the TLV Command that needs to be sent to NCX3321. */
	if (pCmdParams->wAddnDataLen != 0x00U)
	{
		(void) memcpy(&pTxBuffer[pDataParams->wTxBufStartPos + bTxBuffOffset], pCmdParams->pAddnData, pCmdParams->wAddnDataLen);

		pDataParams->wTxFwDataLen = (uint8)pCmdParams->wAddnDataLen;
	}

	if (pCmdParams->pTxDataBuff != NULL)
	{
		(void) memcpy(&pTxBuffer[pDataParams->wTxBufStartPos + pDataParams->wTxBufLen + pDataParams->wTxFwDataLen + bTxBuffOffset], pData, wDataLength);

		pDataParams->wTxBufLen += wDataLength;
	}

	if ((SEND & bExchAction) != 0x00U)
	{
		pDataParams->wTxBufLen += pDataParams->wTxFwDataLen;
		/*In the last we are updating the length*/
		pTxBuffer[pDataParams->wTxBufStartPos++] = (uint8)((pDataParams->wTxBufLen & 0xff00U) >> 8);

		pTxBuffer[pDataParams->wTxBufStartPos++] = (uint8)(pDataParams->wTxBufLen & 0x00ffU);

		/* this is the last packet to add for the RF_EXchange the*/
		pDataParams->wTxBufLen += pDataParams->wTxBufStartPos;

		pDataParams->wTxFwDataLen = 0;
	}

	return PH_ERR_SUCCESS;
}

static FUNC(uint16, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepSnglTlv(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams,
    VAR(uint16, ANFCRL_VAR) wTxBuff_Offset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxIndex = wTxBuff_Offset;
	PH_UNUSED_VARIABLE(pDataParams);
	pTxBuffer[wTxIndex++] = pCmdParams->bCmd;

	/*2-Bytes for length*/
	wTxIndex++;
	wTxIndex++;

	if (pCmdParams->pTxDataBuff != NULL)
	{
		/* Copy additional data passed from Instruction Layer. */
		if (pCmdParams->wAddnDataLen != 0x00U)
		{
			(void) memcpy(&pTxBuffer[wTxIndex], pCmdParams->pAddnData, pCmdParams->wAddnDataLen);

			wTxIndex += pCmdParams->wAddnDataLen;
			wDataLength += pCmdParams->wAddnDataLen;
		}
		(void) memcpy(&pTxBuffer[wTxIndex], pCmdParams->pTxDataBuff, pCmdParams->wTxDataLength);
	}
	wTxIndex += pCmdParams->wTxDataLength;
	wDataLength += pCmdParams->wTxDataLength;

	pTxBuffer[wTxBuff_Offset + 1U] = (uint8) ((wDataLength & 0xff00U) >> 8U);

	pTxBuffer[wTxBuff_Offset + 2U] = (uint8) (wDataLength & 0x00ffU);

	return wTxIndex;
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Transceive(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams, VAR(uint16, ANFCRL_VAR) wTlv_Length)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM dwReceivedEvents = 0u;

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			if (pDataParams->bNonRF_Cmd != 0x00U)
			{
			    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_SendSnglTlv(pDataParams, wTlv_Length));
			}
			else
			{
			    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_InstMngr_SendBuffdData(pDataParams));

				/*Reset the TxBuffer*/
				pDataParams->wTxBufLen = 0U;
				pDataParams->wTxBufStartPos = 0U;
			}

			if (status != PH_ERR_SUCCESS)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
			/*no break*/
		case PH_TOOLS_EVENT_OCCUR:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_WaitIrq(pDataParams, &dwReceivedEvents));
			if (((status & PH_ERR_MASK) == PH_ERR_ABORTED) || ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT))
			{
				return PH_ERR_ABORTED;
			}
			else
			{
				PH_CHECK_SUCCESS(status);
				(void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_EVENT_RF, NULL);
				status = phhalHw_Ncx3321_InstMngr_ReadRsp(pDataParams, pCmdParams);
			}
			break;
	}

	return status;
}

/*
 * phhalHw_Ncx3321_InstMngr_SendBuffdData is helper function to transmits the
 * buffered data from Tx_Buffer using BAL interface.
 */
static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendBuffdData(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBuffrdDataLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferSize = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTxBuffer = NULL;

	(void)phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pTxBuffer, &wBuffrdDataLength, &wBufferSize);

	pTxBuffer--;
	*pTxBuffer = PHHAL_HW_NCX3321_INT_SPI_WRITE;

	return phhalHw_Ncx3321_Send(pDataParams, pTxBuffer, (wBuffrdDataLength + 1U), PH_ON);
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendSnglTlv(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wSnglTLVLenght)
{
	pDataParams->pInstrBuffer[0] = PHHAL_HW_NCX3321_INT_SPI_WRITE;

	return phhalHw_Ncx3321_Send(pDataParams, &pDataParams->pInstrBuffer[0], wSnglTLVLenght + 1U, PH_ON);
}

/*
 *  phhalHw_Ncx3321_InstMngr_ReadRsp processes the data read by HAL IsrCallback.
 *  if response is not complete, it reads remaining number of byte from the Front End.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_ReadRsp(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRespLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRemRespLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCopyRespLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsrBytesLenToRead = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTmpRxBuffer = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bHeaderLen = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUp = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pIsrBuffPtr = NULL;

	/*
	 * TLV Definition:
	 * 0th location - FF (Direction Byte)
	 * 1th location - Type Field
	 * 2th location - RspLength MSB
	 * 3nd location - RspLength LSB
	 * 4th location - RspStatus (Value 0)
	 * 5th location - Value 1 */
	bIndex = 2;
	pIsrBuffPtr = pDataParams->sIrqResp.pIsrBuffPtr;

	/*Response length is of 2 byte @bIndex  1 and 2 */
	wRespLength = pIsrBuffPtr[bIndex++];
	wRespLength <<= 8U;
	wRespLength |= pIsrBuffPtr[bIndex++];

	/* Calculate the no of bytes to be read */
	bHeaderLen = PHHAL_HW_NCX3321_TYPE_FIELD_LEN + PHHAL_HW_NCX3321_LENGTH_FIELD_LEN + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN;
	wIsrBytesLenToRead = (uint16)pDataParams->sIrqResp.bIsrBytesRead - (uint16)bHeaderLen;

	/* Get Response Status byte. */
	status = (uint16)pIsrBuffPtr[bIndex++];

	if (wRespLength > PHHAL_HW_NCX3321_STATUS_FIELD_LEN)
	{
		do
		{
            /*
             *  NULL pointers should be avoided.
             */
            if ((pCmdParams == NULL) || ((pCmdParams->ppRxBuffer) == NULL) || ((pCmdParams->pRxLength) == NULL))
            {
                status = PH_ERR_INTERNAL_ERROR;
                break;
            }

			wRemRespLength = (wRespLength > wIsrBytesLenToRead) ? (wRespLength - wIsrBytesLenToRead) : 0x00U;
			wCopyRespLength = (((wRespLength > wIsrBytesLenToRead) ? wIsrBytesLenToRead : wRespLength) - PHHAL_HW_NCX3321_STATUS_FIELD_LEN);

			if ((pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA) || (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_CTS_RETRIEVE_LOG)
					|| (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_READ_E2PROM) || (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_GET_DIE_ID)
					|| (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_GET_VERSION)|| (pCmdParams->bCmd == PHHAL_HW_NCX3321_INSTR_GET_RF_CONFIGURATION))
			{
				pTmpRxBuffer = *(pCmdParams->ppRxBuffer);

				if (wCopyRespLength != 0U)
				{
					(void)memcpy(pTmpRxBuffer, &pIsrBuffPtr[bIndex], wCopyRespLength);
					pTmpRxBuffer = &(pTmpRxBuffer[wCopyRespLength]);
				}

				if (wRemRespLength != 0U)
				{
					--pTmpRxBuffer;
					bBackUp = *pTmpRxBuffer;

					PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Read(pDataParams,
							pTmpRxBuffer, (wRemRespLength + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN)));

					*pTmpRxBuffer = bBackUp;
				}

				pTmpRxBuffer = *(pCmdParams->ppRxBuffer);
				--pTmpRxBuffer;
			}
			else
			{
				pTmpRxBuffer = pIsrBuffPtr;

				if (wRemRespLength != 0U)
				{
					--pTmpRxBuffer;
					bBackUp = *(&pTmpRxBuffer[pDataParams->sIrqResp.bIsrBytesRead]);

					PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Read(pDataParams,
						&pTmpRxBuffer[pDataParams->sIrqResp.bIsrBytesRead], wRemRespLength + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN));

					*(&pTmpRxBuffer[pDataParams->sIrqResp.bIsrBytesRead]) = bBackUp;
				}
				pTmpRxBuffer = &pIsrBuffPtr[bHeaderLen];
			}
            /* pre-increment the Buffer pointer to remove the SPI read header */
            *pCmdParams->ppRxBuffer = ++pTmpRxBuffer;
            *pCmdParams->pRxLength = wRespLength - PHHAL_HW_NCX3321_STATUS_FIELD_LEN;

		} while (FALSE);
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Send(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, VAR(uint16, ANFCRL_VAR) wTxLength, VAR(uint8, ANFCRL_VAR) bCheckIRQ)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wResponseLen = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM wStartTime = 0U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwElapsedTime = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	/* Send current queue */
	status = phbalReg_Exchange(pDataParams->pBalDataParams,
	PH_EXCHANGE_DEFAULT, pTxBuffer, wTxLength, 0U, NULL, &wResponseLen);

#else
    switch(pDataParams->bSendState)
    {
        case 0U:
            wStartTime = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
            pDataParams->bSendState = 1U;
            /* no break */
        case 1U:
            if (bCheckIRQ == PH_ON)
            {
#ifndef AUTOSAR_VER
                if(phDriver_PinRead(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INPUT) != 0U)
#else
                if(phDriver_PinRead(ANFCLIB_PCConfig.AnfcRL_DioChannelIRQ, PH_DRIVER_PINFUNC_INPUT) != 0U)
#endif
                {
                    dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, wStartTime);

                    /* Check for timer overflow, abort if timer overflow happens */
                    if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
                    {
                        status = PH_ERR_ABORTED;
                        break;
                    }
                    else
                    {
                        /* Wait for the IRQ to be Low to De-assert the NSS. */
                        if(dwElapsedTime < PHHAL_HW_WAIT_IRQ_LOW_TIMEOUT)
                        {
                            return PH_STATUS_INPROCESS;
                        }
                        else
                        {
                            /* In normal working condition, when NxpNfcRdLib is about to send command, */
                            /* IRQ should not be high. If this still happens after wait time, leave with PH_ERR_ABORTED error code. */
                            status = PH_ERR_ABORTED;
                            break;
                        }
                    }
                }
            }
            pDataParams->bSendState = 2U;
            /* no break */
        case 2U:
#ifdef PHDRIVER_SOFT_SSEL
            /* Enable chip select connected to reader IC (NSS low). */
            phhalHw_Ncx3321_Int_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_LOW);
#endif
            /* Send current queue */
            status = phbalReg_Exchange(pDataParams->pBalDataParams,
            PH_EXCHANGE_DEFAULT, pTxBuffer, wTxLength, 0U, NULL, &wResponseLen);
#ifdef PHDRIVER_SOFT_SSEL
            /* Disable chip select connected to reader IC (NSS high). */
            phhalHw_Ncx3321_Int_WriteSSEL(pDataParams->pBalDataParams, PH_DRIVER_SET_HIGH);
#endif
            break;
    }

#endif

    pDataParams->bSendState = 0U;
	return status;
}

/**
 * phhalHw_Ncx3321_InstMngr_Read API does the actual reading of data from Front End using BAL
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Read(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, VAR(uint16, ANFCRL_VAR) wRxLength)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wResponseLen = 0U;
#ifdef PHDRIVER_SOFT_SSEL
	/* Enable chip select connected to reader IC (NSS low). */
	phhalHw_Ncx3321_Int_WriteSSEL(pDataParams->pBalDataParams,
	PH_DRIVER_SET_LOW);
#endif
	/* Read back response */
	status = phbalReg_Exchange(pDataParams->pBalDataParams,
	PH_EXCHANGE_DEFAULT,
	NULL, 0U, wRxLength, pRxBuffer, &wResponseLen);
#ifdef PHDRIVER_SOFT_SSEL
	/* Disable chip select connected to reader IC (NSS high). */
	phhalHw_Ncx3321_Int_WriteSSEL(pDataParams->pBalDataParams,
	PH_DRIVER_SET_HIGH);
#endif

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
// phbalReg_Exchange() 함수에서 wResponseLen를 받아가지만
// 내부를 수정하면서 platformSpiExchange() 함수에서 wResponseLen를 return 하지 않음
// 따라서 일단 막아서 사용하고 추가해야 한다고 하면
// platformSpiExchange() 함수에서 wResponseLen를 return 하도록 수정
// WT : wRxLength 로 전달된 Byte수 만큼 Read되는 것이 보장된다면 반드시 적용이 필요하진 않지만
// WT : Read해야하는 갯수만큼 읽었는지 check하는 부분이므로 가능하다면 추가하는 것으로 추천 드립니다.

#else
	if (wResponseLen != wRxLength)
	{
		status = PH_ERR_INTERNAL_ERROR;
	}

#endif	/* NIDEC_PORTING */

	return status;
}

static FUNC(uint8, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_CheckBuffSpace(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wCurrSpaceNeeded)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPrevBuffrdDataLen = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrBufferSize = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM ppTmpBuffer = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSpaceAvailable = 0U;

	/*Check if sufficient space is there in the Buffer*/
	(void)phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &ppTmpBuffer, &wPrevBuffrdDataLen, &wCurrBufferSize);

	if (wCurrBufferSize < (wCurrSpaceNeeded + wPrevBuffrdDataLen + pDataParams->wTxBufStartPos))
	{
		bSpaceAvailable = 0u;
	}
	else
	{
		bSpaceAvailable = 1u;
	}
	return bSpaceAvailable;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
