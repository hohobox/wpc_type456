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
*   @file    phhalHw_Ncx3321_InstMngr2.c
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
#include <ph_RefDefs2.h>
#include <ph_Status2.h>
#include <phhalHw2.h>

#ifdef NXPBUILD__PHHAL_HW_NCX33212
#include <phDriver2.h>
#ifndef AUTOSAR_VER

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection2.h>

#endif	/* NIDEC_PORTING */   /* NIDEC_PORTING */
#endif

#include <phTools2.h>
#include "phhalHw_Ncx33212.h"
#include <phhalHw_Ncx3321_Instr2.h>
#include "phhalHw_Ncx3321_Int2.h"
#include "phhalHw_Ncx3321_InstrMngr2.h"
#include "phhalHw_Ncx3321_Wait2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_InstMngr2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTMNGR_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTMNGR_VENDOR_ID_C2 != PHHALHW_NCX3321_INSTMNGR_VENDOR_ID2)
    #error "phhalHw_Ncx3321_InstMngr2.c and phhalHw_Ncx3321_InstMngr.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_InstMngr2.c and phhalHw_Ncx3321_InstMngr.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_InstMngr.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION_C2 != PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION_C2 != PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION_C2 != PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw_Ncx3321_InstMngr2.c and phhalHw_Ncx3321_InstMngr.h are different"
#endif
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX33212
/* 1 Byte Command Code + 2 Bytes of Length*/
#define CMD_HEADER_LONG2         3U

#define SEND2                    0x01U
#define QUEUE2                   0x02U
#define QUEUE_N_SEND2            0x03U

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
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static FUNC(uint8, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_CheckBuffSpace2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wCurrSpaceNeeded2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Procss_Cmds2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint16, ANFCRL_VAR) wOptions2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Exchange2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint8, ANFCRL_VAR) bExchAction2);

static FUNC(uint16, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepSnglTlv2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2,
    VAR(uint16, ANFCRL_VAR) wTxBuff_Offset2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepTlv_RFData2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, VAR(uint8, ANFCRL_VAR) bExchAction2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendSnglTlv2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wSnglTLVLenght2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendBuffdData2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Transceive2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint16, ANFCRL_VAR) wTlv_Length2);

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_HandleCmd2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint16, ANFCRL_VAR) wOptions2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrTotalTxLength2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSpaceAvailable2 = 0u;

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
#ifdef DEBUG2
			if ((pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_FIELD_OFF2) && (pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA2)
					&& (pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA2) && (pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA2)
					&& (pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_GET_DIE_ID2) && (pCmdParams2->bCmd2 != PHHAL_HW_NCX3321_INSTR_GET_VERSION2))
			{
				if (pCmdParams2->wTxDataLength2 == 0U)
				{
					return PH_ERR_INVALID_PARAMETER2;
				}
			}
#endif

			wCurrTotalTxLength2 = pCmdParams2->wTxDataLength2 + pCmdParams2->wAddnDataLen2 + CMD_HEADER_LONG2 + 1U;

			bSpaceAvailable2 = phhalHw_Ncx3321_InstMngr_CheckBuffSpace2(pDataParams2, wCurrTotalTxLength2);

			if (bSpaceAvailable2 == 0u)
			{
				pDataParams2->wTxBufLen2 = 0U;
				pDataParams2->wTxBufStartPos2 = 0U;

				status2 = PH_ERR_BUFFER_OVERFLOW2;
				break;
			}
			/*If the buffer has enough space go to next state*/
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_Procss_Cmds2(pDataParams2, pCmdParams2, wOptions2));
			break;
	}

	return status2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Procss_Cmds2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint16, ANFCRL_VAR) wOptions2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			pDataParams2->bExchAction2 = QUEUE_N_SEND2;
			if ((pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA2) || (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_TRANSMIT_RF_DATA2) ||
				(pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_RECEIVE_RF_DATA2) || (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA2))
			{
				pDataParams2->bNonRF_Cmd2 = 0U;

				if ((wOptions2 & PH_EXCHANGE_BUFFERED_BIT2) != 0U)
				{
					pDataParams2->bExchAction2 = QUEUE2;
				}
			}
			else
			{
				pDataParams2->bNonRF_Cmd2 = 1U;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_Exchange2(pDataParams2, pCmdParams2, pDataParams2->bExchAction2));
			break;
	}

	return status2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Exchange2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint8, ANFCRL_VAR) bExchAction2)
{

  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(phTools_EventBits_t2, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventFlags2 = 0U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSnglTLVLenght2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxBufferLen2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxBufferSize2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pTxBuffer2 = NULL;

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			if ((bExchAction2 & QUEUE2) != 0x00U)
			{
				if (pDataParams2->bNonRF_Cmd2 != 0U)
				{
					/*RF_Exchange is in Progress, prep TLV in different Buff */
					wSnglTLVLenght2 = phhalHw_Ncx3321_InstMngr_PrepSnglTlv2(pDataParams2, pCmdParams2, 0, &pDataParams2->pInstrBuffer2[1]);
				}
				else
				{
					(void)phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pTxBuffer2, &wTxBufferLen2, &wTxBufferSize2);

					(void)phhalHw_Ncx3321_InstMngr_PrepTlv_RFData2(pDataParams2, pCmdParams2, pTxBuffer2, bExchAction2);
				}
			}

			if ((bExchAction2 & SEND2) == 0u)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			if ((pDataParams2->bPollGuardTimeFlag2 == PH_ON2) && (pDataParams2->bNonRF_Cmd2 == 0U))
			{
				/* Wait infinitely for the Poll Guard Time to expire. */
				PH_CHECK_INPROCESS_FCT2(status2, phTools_EventPend2(&pDataParams2->HwEventObj2, E_EVENT_OPT_PEND_SET_ANY2 | E_EVENT_OPT_PEND_CLEAR_ON_EXIT2,
						PHHAL_HW_MAX_DELAY2, E_EVENT_GT_EXP2 | E_EVENT_ABORT2, &dwEventFlags2));
				pDataParams2->bPollGuardTimeFlag2 = PH_OFF2;
				if(0U != (dwEventFlags2 & E_EVENT_ABORT2))
				{
				    (void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_EVENT_ABORT2, NULL);
					status2 = PH_ERR_ABORTED2;
					break;
				}
				(void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_EVENT_RF2, NULL);
			}
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_Transceive2(pDataParams2, pCmdParams2, wSnglTLVLenght2));
			break;
	}

	return status2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepTlv_RFData2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, VAR(uint8, ANFCRL_VAR) bExchAction2)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTxBuffOffset2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCmd2 = pCmdParams2->bCmd2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pData2 = pCmdParams2->pTxDataBuff2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLength2 = pCmdParams2->wTxDataLength2;

	if (pDataParams2->wTxBufStartPos2 == 0U)
	{
		pTxBuffer2[pDataParams2->wTxBufStartPos2++] = bCmd2; /* Reserved 0th Location of buffer for Command code */
	}
	else
	{
		pDataParams2->pTxBuffer2[0] = bCmd2;
	}

	bTxBuffOffset2 = 2;

	/* Copy Additional data required by the TLV Command that needs to be sent to NCX3321. */
	if (pCmdParams2->wAddnDataLen2 != 0x00U)
	{
		(void) memcpy(&pTxBuffer2[pDataParams2->wTxBufStartPos2 + bTxBuffOffset2], pCmdParams2->pAddnData2, pCmdParams2->wAddnDataLen2);

		pDataParams2->wTxFwDataLen2 = (uint8)pCmdParams2->wAddnDataLen2;
	}

	if (pCmdParams2->pTxDataBuff2 != NULL)
	{
		(void) memcpy(&pTxBuffer2[pDataParams2->wTxBufStartPos2 + pDataParams2->wTxBufLen2 + pDataParams2->wTxFwDataLen2 + bTxBuffOffset2], pData2, wDataLength2);

		pDataParams2->wTxBufLen2 += wDataLength2;
	}

	if ((SEND2 & bExchAction2) != 0x00U)
	{
		pDataParams2->wTxBufLen2 += pDataParams2->wTxFwDataLen2;
		/*In the last we are updating the length*/
		pTxBuffer2[pDataParams2->wTxBufStartPos2++] = (uint8)((pDataParams2->wTxBufLen2 & 0xff00U) >> 8);

		pTxBuffer2[pDataParams2->wTxBufStartPos2++] = (uint8)(pDataParams2->wTxBufLen2 & 0x00ffU);

		/* this is the last packet to add for the RF_EXchange the*/
		pDataParams2->wTxBufLen2 += pDataParams2->wTxBufStartPos2;

		pDataParams2->wTxFwDataLen2 = 0;
	}

	return PH_ERR_SUCCESS2;
}

static FUNC(uint16, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_PrepSnglTlv2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2,
    VAR(uint16, ANFCRL_VAR) wTxBuff_Offset2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxIndex2 = wTxBuff_Offset2;
	PH_UNUSED_VARIABLE2(pDataParams2);
	pTxBuffer2[wTxIndex2++] = pCmdParams2->bCmd2;

	/*2-Bytes for length*/
	wTxIndex2++;
	wTxIndex2++;

	if (pCmdParams2->pTxDataBuff2 != NULL)
	{
		/* Copy additional data passed from Instruction Layer. */
		if (pCmdParams2->wAddnDataLen2 != 0x00U)
		{
			(void) memcpy(&pTxBuffer2[wTxIndex2], pCmdParams2->pAddnData2, pCmdParams2->wAddnDataLen2);

			wTxIndex2 += pCmdParams2->wAddnDataLen2;
			wDataLength2 += pCmdParams2->wAddnDataLen2;
		}
		(void) memcpy(&pTxBuffer2[wTxIndex2], pCmdParams2->pTxDataBuff2, pCmdParams2->wTxDataLength2);
	}
	wTxIndex2 += pCmdParams2->wTxDataLength2;
	wDataLength2 += pCmdParams2->wTxDataLength2;

	pTxBuffer2[wTxBuff_Offset2 + 1U] = (uint8) ((wDataLength2 & 0xff00U) >> 8U);

	pTxBuffer2[wTxBuff_Offset2 + 2U] = (uint8) (wDataLength2 & 0x00ffU);

	return wTxIndex2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_Transceive2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2, VAR(uint16, ANFCRL_VAR) wTlv_Length2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(phTools_EventBits_t2, ANFCRL_VAR) PH_MEMLOC_REM2 dwReceivedEvents2 = 0u;

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			if (pDataParams2->bNonRF_Cmd2 != 0x00U)
			{
			    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_SendSnglTlv2(pDataParams2, wTlv_Length2));
			}
			else
			{
			    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_InstMngr_SendBuffdData2(pDataParams2));

				/*Reset the TxBuffer*/
				pDataParams2->wTxBufLen2 = 0U;
				pDataParams2->wTxBufStartPos2 = 0U;
			}

			if (status2 != PH_ERR_SUCCESS2)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
			/*no break*/
		case PH_TOOLS_EVENT_OCCUR2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_WaitIrq2(pDataParams2, &dwReceivedEvents2));
			if (((status2 & PH_ERR_MASK2) == PH_ERR_ABORTED2) || ((status2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2))
			{
				return PH_ERR_ABORTED2;
			}
			else
			{
				PH_CHECK_SUCCESS2(status2);
				(void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_EVENT_RF2, NULL);
				status2 = phhalHw_Ncx3321_InstMngr_ReadRsp2(pDataParams2, pCmdParams2);
			}
			break;
	}

	return status2;
}

/*
 * phhalHw_Ncx3321_InstMngr_SendBuffdData2 is helper function to transmits the
 * buffered data from Tx_Buffer using BAL interface.
 */
static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendBuffdData2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBuffrdDataLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferSize2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pTxBuffer2 = NULL;

	(void)phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pTxBuffer2, &wBuffrdDataLength2, &wBufferSize2);

	pTxBuffer2--;
	*pTxBuffer2 = PHHAL_HW_NCX3321_INT_SPI_WRITE2;

	return phhalHw_Ncx3321_Send2(pDataParams2, pTxBuffer2, (wBuffrdDataLength2 + 1U), PH_ON2);
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_SendSnglTlv2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wSnglTLVLenght2)
{
	pDataParams2->pInstrBuffer2[0] = PHHAL_HW_NCX3321_INT_SPI_WRITE2;

	return phhalHw_Ncx3321_Send2(pDataParams2, &pDataParams2->pInstrBuffer2[0], wSnglTLVLenght2 + 1U, PH_ON2);
}

/*
 *  phhalHw_Ncx3321_InstMngr_ReadRsp2 processes the data read by HAL IsrCallback.
 *  if response is not complete, it reads remaining number of byte from the Front End.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_ReadRsp2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(phhalHw_InstMngr_CmdParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRespLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRemRespLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCopyRespLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIsrBytesLenToRead2 = 0u;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pTmpRxBuffer2 = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bHeaderLen2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBackUp2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pIsrBuffPtr2 = NULL;

	/*
	 * TLV Definition:
	 * 0th location - FF (Direction Byte)
	 * 1th location - Type Field
	 * 2th location - RspLength MSB
	 * 3nd location - RspLength LSB
	 * 4th location - RspStatus (Value 0)
	 * 5th location - Value 1 */
	bIndex2 = 2;
	pIsrBuffPtr2 = pDataParams2->sIrqResp2.pIsrBuffPtr2;

	/*Response length is of 2 byte @bIndex2  1 and 2 */
	wRespLength2 = pIsrBuffPtr2[bIndex2++];
	wRespLength2 <<= 8U;
	wRespLength2 |= pIsrBuffPtr2[bIndex2++];

	/* Calculate the no of bytes to be read */
	bHeaderLen2 = PHHAL_HW_NCX3321_TYPE_FIELD_LEN2 + PHHAL_HW_NCX3321_LENGTH_FIELD_LEN2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2;
	wIsrBytesLenToRead2 = (uint16)pDataParams2->sIrqResp2.bIsrBytesRead2 - (uint16)bHeaderLen2;

	/* Get Response Status byte. */
	status2 = (uint16)pIsrBuffPtr2[bIndex2++];

	if (wRespLength2 > PHHAL_HW_NCX3321_STATUS_FIELD_LEN2)
	{
		do
		{
            /*
             *  NULL pointers should be avoided.
             */
            if ((pCmdParams2 == NULL) || ((pCmdParams2->ppRxBuffer2) == NULL) || ((pCmdParams2->pRxLength2) == NULL))
            {
                status2 = PH_ERR_INTERNAL_ERROR2;
                break;
            }

			wRemRespLength2 = (wRespLength2 > wIsrBytesLenToRead2) ? (wRespLength2 - wIsrBytesLenToRead2) : 0x00U;
			wCopyRespLength2 = (((wRespLength2 > wIsrBytesLenToRead2) ? wIsrBytesLenToRead2 : wRespLength2) - PHHAL_HW_NCX3321_STATUS_FIELD_LEN2);

			if ((pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_RETRIEVE_RF_DATA2) || (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_CTS_RETRIEVE_LOG2)
					|| (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_READ_E2PROM2) || (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_GET_DIE_ID2)
					|| (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_GET_VERSION2)|| (pCmdParams2->bCmd2 == PHHAL_HW_NCX3321_INSTR_GET_RF_CONFIGURATION2))
			{
				pTmpRxBuffer2 = *(pCmdParams2->ppRxBuffer2);

				if (wCopyRespLength2 != 0U)
				{
					(void)memcpy(pTmpRxBuffer2, &pIsrBuffPtr2[bIndex2], wCopyRespLength2);
					pTmpRxBuffer2 = &(pTmpRxBuffer2[wCopyRespLength2]);
				}

				if (wRemRespLength2 != 0U)
				{
					--pTmpRxBuffer2;
					bBackUp2 = *pTmpRxBuffer2;

					PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Read2(pDataParams2,
							pTmpRxBuffer2, (wRemRespLength2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2)));

					*pTmpRxBuffer2 = bBackUp2;
				}

				pTmpRxBuffer2 = *(pCmdParams2->ppRxBuffer2);
				--pTmpRxBuffer2;
			}
			else
			{
				pTmpRxBuffer2 = pIsrBuffPtr2;

				if (wRemRespLength2 != 0U)
				{
					--pTmpRxBuffer2;
					bBackUp2 = *(&pTmpRxBuffer2[pDataParams2->sIrqResp2.bIsrBytesRead2]);

					PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Read2(pDataParams2,
						&pTmpRxBuffer2[pDataParams2->sIrqResp2.bIsrBytesRead2], wRemRespLength2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2));

					*(&pTmpRxBuffer2[pDataParams2->sIrqResp2.bIsrBytesRead2]) = bBackUp2;
				}
				pTmpRxBuffer2 = &pIsrBuffPtr2[bHeaderLen2];
			}
            /* pre-increment the Buffer pointer to remove the SPI read header */
            *pCmdParams2->ppRxBuffer2 = ++pTmpRxBuffer2;
            *pCmdParams2->pRxLength2 = wRespLength2 - PHHAL_HW_NCX3321_STATUS_FIELD_LEN2;

		} while (FALSE);
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Send2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, VAR(uint16, ANFCRL_VAR) wTxLength2, VAR(uint8, ANFCRL_VAR) bCheckIRQ2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wResponseLen2 = 0U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 wStartTime2 = 0U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwElapsedTime2 = 0U;

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
	/* Send current queue */
	status2 = phbalReg_Exchange2(pDataParams2->pBalDataParams2,
	PH_EXCHANGE_DEFAULT2, pTxBuffer2, wTxLength2, 0U, NULL, &wResponseLen2);

#else
    switch(pDataParams2->bSendState2)
    {
        case 0U:
            wStartTime2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
            pDataParams2->bSendState2 = 1U;
            /* no break */
        case 1U:
            if (bCheckIRQ2 == PH_ON2)
            {
#ifndef AUTOSAR_VER
                if(phDriver_PinRead2(PHDRIVER_PIN_IRQ2, PH_DRIVER_PINFUNC_INPUT2) != 0U)
#else
                if(phDriver_PinRead2(ANFCLIB_PCConfig2.AnfcRL_DioChannelIRQ, PH_DRIVER_PINFUNC_INPUT2) != 0U)
#endif
                {
                    dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, wStartTime2);

                    /* Check for timer overflow, abort if timer overflow happens */
                    if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
                    {
                        status2 = PH_ERR_ABORTED2;
                        break;
                    }
                    else
                    {
                        /* Wait for the IRQ to be Low to De-assert the NSS. */
                        if(dwElapsedTime2 < PHHAL_HW_WAIT_IRQ_LOW_TIMEOUT2)
                        {
                            return PH_STATUS_INPROCESS2;
                        }
                        else
                        {
                            /* In normal working condition, when NxpNfcRdLib is about to send command, */
                            /* IRQ should not be high. If this still happens after wait time, leave with PH_ERR_ABORTED2 error code. */
                            status2 = PH_ERR_ABORTED2;
                            break;
                        }
                    }
                }
            }
            pDataParams2->bSendState2 = 2U;
            /* no break */
        case 2U:
#ifdef PHDRIVER_SOFT_SSEL2
            /* Enable chip select connected to reader IC (NSS low). */
            phhalHw_Ncx3321_Int_WriteSSEL2(pDataParams2->pBalDataParams2, PH_DRIVER_SET_LOW2);
#endif
            /* Send current queue */
            status2 = phbalReg_Exchange2(pDataParams2->pBalDataParams2,
            PH_EXCHANGE_DEFAULT2, pTxBuffer2, wTxLength2, 0U, NULL, &wResponseLen2);
#ifdef PHDRIVER_SOFT_SSEL2
            /* Disable chip select connected to reader IC (NSS high). */
            phhalHw_Ncx3321_Int_WriteSSEL2(pDataParams2->pBalDataParams2, PH_DRIVER_SET_HIGH2);
#endif
            break;
    }

#endif

    pDataParams2->bSendState2 = 0U;
	return status2;
}

/**
 * phhalHw_Ncx3321_InstMngr_Read API does the actual reading of data from Front End using BAL
 */
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Read2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2, VAR(uint16, ANFCRL_VAR) wRxLength2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wResponseLen2 = 0U;
#ifdef PHDRIVER_SOFT_SSEL2
	/* Enable chip select connected to reader IC (NSS low). */
	phhalHw_Ncx3321_Int_WriteSSEL2(pDataParams2->pBalDataParams2,
	PH_DRIVER_SET_LOW2);
#endif
	/* Read back response */
	status2 = phbalReg_Exchange2(pDataParams2->pBalDataParams2,
	PH_EXCHANGE_DEFAULT2,
	NULL, 0U, wRxLength2, pRxBuffer2, &wResponseLen2);
#ifdef PHDRIVER_SOFT_SSEL2
	/* Disable chip select connected to reader IC (NSS high). */
	phhalHw_Ncx3321_Int_WriteSSEL2(pDataParams2->pBalDataParams2,
	PH_DRIVER_SET_HIGH2);
#endif

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
// phbalReg_Exchange() 함수에서 wResponseLen를 받아가지만
// 내부를 수정하면서 platformSpiExchange() 함수에서 wResponseLen를 return 하지 않음
// 따라서 일단 막아서 사용하고 추가해야 한다고 하면
// platformSpiExchange() 함수에서 wResponseLen를 return 하도록 수정
// WT : wRxLength 로 전달된 Byte수 만큼 Read되는 것이 보장된다면 반드시 적용이 필요하진 않지만
// WT : Read해야하는 갯수만큼 읽었는지 check하는 부분이므로 가능하다면 추가하는 것으로 추천 드립니다.

#else
	if (wResponseLen2 != wRxLength2)
	{
		status2 = PH_ERR_INTERNAL_ERROR2;
	}

#endif	/* NIDEC_PORTING */

	return status2;
}

static FUNC(uint8, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_CheckBuffSpace2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint16, ANFCRL_VAR) wCurrSpaceNeeded2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wPrevBuffrdDataLen2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrBufferSize2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 ppTmpBuffer2 = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSpaceAvailable2 = 0U;

	/*Check if sufficient space is there in the Buffer*/
	(void)phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &ppTmpBuffer2, &wPrevBuffrdDataLen2, &wCurrBufferSize2);

	if (wCurrBufferSize2 < (wCurrSpaceNeeded2 + wPrevBuffrdDataLen2 + pDataParams2->wTxBufStartPos2))
	{
		bSpaceAvailable2 = 0u;
	}
	else
	{
		bSpaceAvailable2 = 1u;
	}
	return bSpaceAvailable2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

#ifdef __cplusplus
}
#endif
