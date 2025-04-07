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
*   @file    phhalHw_Ncx3321_Wait2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Wait - HAL API usage in common use cases.
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
#include <ph_Status2.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PHHAL_HW_NCX33212

#include <phDriver2.h>
#include <phNxpNfcRdLib_Config2.h>
#include <phhalHw2.h>
#include <phhalHw_Ncx3321_Instr2.h>
#include "phhalHw_Ncx3321_Int2.h"
#include "phhalHw_Ncx3321_InstrMngr2.h"
#include "phhalHw_Ncx3321_Wait2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Wait2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_WAIT_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same vendor */
#if (PHHALHW_NCX3321_WAIT_VENDOR_ID_C2 != PHHALHW_NCX3321_WAIT_VENDOR_ID2)
    #error "phhalHw_Ncx3321_Wait2.c and phhalHw_Ncx3321_Wait.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Wait2.c and phhalHw_Ncx3321_Wait.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION_C2 != PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION_C2 != PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION_C2 != PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw_Ncx3321_Wait2.c and phhalHw_Ncx3321_Wait.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */
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
#ifdef NXPBUILD__PHHAL_HW_NCX33212

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_WaitIrq2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pReceivedEvents2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBuffrdDataLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferSize2 = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pTxBuffer2 = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTagType2 = 0;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTimeout2;

	if (pDataParams2->bNonRF_Cmd2 == 0x00U)
	{
		(void)phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pTxBuffer2, &wBuffrdDataLength2, &wBufferSize2);
		bTagType2 = *(&pTxBuffer2[0]);

		if (bTagType2 == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA2)
		{
			dwTimeout2 = PHHAL_HW_NCX3321_EXCHANGE_CMD_TIMEOUT2;
		}
		else
		{
			dwTimeout2 = PHHAL_HW_MAX_DELAY2;
		}
	}
	else
	{
		dwTimeout2 = PHHAL_HW_ABORT_EVT_TIMEOUT2;
	}

	/* Wait for event */
	PH_CHECK_INPROCESS_FCT2(status2,
			phTools_EventPend2( &pDataParams2->HwEventObj2, E_EVENT_OPT_PEND_SET_ANY2 | E_EVENT_OPT_NONE2, dwTimeout2,
					(E_EVENT_RF2 | E_EVENT_ABORT2), pReceivedEvents2));
	PH_CHECK_SUCCESS2(status2);
	if ((E_EVENT_ABORT2 & *pReceivedEvents2) != 0u)
	{
		(void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_EVENT_ABORT2, NULL);
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_ABORTED2, PH_COMP_HAL2);
	}
	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_WaitForEvent2(
    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint32, ANFCRL_VAR) dwEvtsWaitFor2,
    VAR(uint32, ANFCRL_VAR) dwEvtsTimeOut2,
    VAR(uint8, ANFCRL_VAR) bPayloadPresnt2,
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventsReceived2,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEvtPayLoad2
)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_NCX3321_UNEXPECTED_EVT2;
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statustmp2;
  VAR(phTools_EventBits_t2, ANFCRL_VAR) PH_MEMLOC_REM2 tReceivedEvents2 = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wEventLength2 = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRemEventLength2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIsrBytesLenToRead2 = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventStatusReg2 = 0x0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bBackup2 = 0x0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bHeaderLen2 = 0U;

	/* Wait for event */
	PH_CHECK_INPROCESS_FCT2(statustmp2, phTools_EventPend2(
				&pDataParams2->HwEventObj2,
				E_EVENT_OPT_PEND_SET_ANY2 | E_EVENT_OPT_PEND_CLEAR_ON_EXIT2,
				dwEvtsTimeOut2,
				(E_PHHAL_HW_EVT_SIG2 | E_EVENT_ABORT2),
				&tReceivedEvents2));
	PH_CHECK_SUCCESS2(statustmp2);
	if ((E_PHHAL_HW_EVT_SIG2 & tReceivedEvents2) != 0u)
	{
		/* Reading length form the ISR buffer, in which we have read first part of response */
		wEventLength2 = pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[2];
		wEventLength2 <<= 8;
		wEventLength2 |= pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[3];

		/* Calculate the no of bytes to be read */
		bHeaderLen2 = PHHAL_HW_NCX3321_TYPE_FIELD_LEN2 + PHHAL_HW_NCX3321_LENGTH_FIELD_LEN2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2;
		wIsrBytesLenToRead2 = (uint16)pDataParams2->sIrqResp2.bIsrBytesRead2 - (uint16)bHeaderLen2;

		wRemEventLength2 = (wEventLength2 > wIsrBytesLenToRead2) ? (wEventLength2 - wIsrBytesLenToRead2) : 0x00U;

		if (wRemEventLength2 != 0U)
		{
			bBackup2 = pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[pDataParams2->sIrqResp2.bIsrBytesRead2 - 1u];
			/* By using wRemLen, We are reading One byte extra, for spi header. Actually
			 * we should have deducted one byte from it.
			 */
			PH_CHECK_SUCCESS_FCT2(statustmp2,phhalHw_Ncx3321_Read2( pDataParams2,
					&pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[pDataParams2->sIrqResp2.bIsrBytesRead2 - 1u],
					(wRemEventLength2 + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN2)));

			pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[pDataParams2->sIrqResp2.bIsrBytesRead2 - 1u] = bBackup2;
		}

		dwEventStatusReg2 = (uint32) pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[4];
		dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[5]) << 8U;
		dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[6]) << 16U;
		dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[7]) << 24U;
	}

	if ((E_EVENT_ABORT2 & tReceivedEvents2) != 0U)
	{
		(void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_EVENT_ABORT2, NULL);
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_ABORTED2, PH_COMP_HAL2);
	}

	if(dwEventsReceived2 != NULL)
	{
		*dwEventsReceived2 = dwEventStatusReg2;
	}

	if (dwEventStatusReg2 != PH_NCX3321_EVT_CTS2)
	{
		if(bPayloadPresnt2 != 0u)
		{
			*ppEvtPayLoad2 = &pDataParams2->sIrqResp2.pIsrEvtBuffPtr2[ 4U + sizeof(dwEventStatusReg2)];
		}
		else
		{
			if (*ppEvtPayLoad2 != NULL)
			{
				*ppEvtPayLoad2 = NULL;
			}
		}
	}

	if ((dwEventStatusReg2 & dwEvtsWaitFor2) != 0U)
	{
		status2 = PH_ERR_SUCCESS2;
	}
	return status2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */

#ifdef __cplusplus
}
#endif
