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
*   @file    phhalHw_Ncx3321_Wait.c
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
#include <ph_Status.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PHHAL_HW_NCX3321

#include <phDriver.h>
#include <phNxpNfcRdLib_Config.h>
#include <phhalHw.h>
#include <phhalHw_Ncx3321_Instr.h>
#include "phhalHw_Ncx3321_Int.h"
#include "phhalHw_Ncx3321_InstrMngr.h"
#include "phhalHw_Ncx3321_Wait.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Wait.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_WAIT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same vendor */
#if (PHHALHW_NCX3321_WAIT_VENDOR_ID_C != PHHALHW_NCX3321_WAIT_VENDOR_ID)
    #error "phhalHw_Ncx3321_Wait.c and phhalHw_Ncx3321_Wait.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION_C != PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Wait.c and phhalHw_Ncx3321_Wait.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Wait.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION_C != PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION_C != PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION) || \
     (PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION_C != PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Wait.c and phhalHw_Ncx3321_Wait.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */
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
#ifdef NXPBUILD__PHHAL_HW_NCX3321

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_WaitIrq(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pReceivedEvents)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBuffrdDataLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferSize = 0U;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pTxBuffer = NULL;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTagType = 0;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTimeout;

	if (pDataParams->bNonRF_Cmd == 0x00U)
	{
		(void)phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pTxBuffer, &wBuffrdDataLength, &wBufferSize);
		bTagType = *(&pTxBuffer[0]);

		if (bTagType == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA)
		{
			dwTimeout = PHHAL_HW_NCX3321_EXCHANGE_CMD_TIMEOUT;
		}
		else
		{
			dwTimeout = PHHAL_HW_MAX_DELAY;
		}
	}
	else
	{
		dwTimeout = PHHAL_HW_ABORT_EVT_TIMEOUT;
	}

	/* Wait for event */
	PH_CHECK_INPROCESS_FCT(status,
			phTools_EventPend( &pDataParams->HwEventObj, E_EVENT_OPT_PEND_SET_ANY | E_EVENT_OPT_NONE, dwTimeout,
					(E_EVENT_RF | E_EVENT_ABORT), pReceivedEvents));
	PH_CHECK_SUCCESS(status);
	if ((E_EVENT_ABORT & *pReceivedEvents) != 0u)
	{
		(void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_EVENT_ABORT, NULL);
		return PH_ADD_COMPCODE_FIXED(PH_ERR_ABORTED, PH_COMP_HAL);
	}
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_WaitForEvent(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint32, ANFCRL_VAR) dwEvtsWaitFor,
    VAR(uint32, ANFCRL_VAR) dwEvtsTimeOut,
    VAR(uint8, ANFCRL_VAR) bPayloadPresnt,
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventsReceived,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEvtPayLoad
)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_NCX3321_UNEXPECTED_EVT;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statustmp;
  VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM tReceivedEvents = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wEventLength = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRemEventLength = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIsrBytesLenToRead = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventStatusReg = 0x0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackup = 0x0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bHeaderLen = 0U;

	/* Wait for event */
	PH_CHECK_INPROCESS_FCT(statustmp, phTools_EventPend(
				&pDataParams->HwEventObj,
				E_EVENT_OPT_PEND_SET_ANY | E_EVENT_OPT_PEND_CLEAR_ON_EXIT,
				dwEvtsTimeOut,
				(E_PHHAL_HW_EVT_SIG | E_EVENT_ABORT),
				&tReceivedEvents));
	PH_CHECK_SUCCESS(statustmp);
	if ((E_PHHAL_HW_EVT_SIG & tReceivedEvents) != 0u)
	{
		/* Reading length form the ISR buffer, in which we have read first part of response */
		wEventLength = pDataParams->sIrqResp.pIsrEvtBuffPtr[2];
		wEventLength <<= 8;
		wEventLength |= pDataParams->sIrqResp.pIsrEvtBuffPtr[3];

		/* Calculate the no of bytes to be read */
		bHeaderLen = PHHAL_HW_NCX3321_TYPE_FIELD_LEN + PHHAL_HW_NCX3321_LENGTH_FIELD_LEN + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN;
		wIsrBytesLenToRead = (uint16)pDataParams->sIrqResp.bIsrBytesRead - (uint16)bHeaderLen;

		wRemEventLength = (wEventLength > wIsrBytesLenToRead) ? (wEventLength - wIsrBytesLenToRead) : 0x00U;

		if (wRemEventLength != 0U)
		{
			bBackup = pDataParams->sIrqResp.pIsrEvtBuffPtr[pDataParams->sIrqResp.bIsrBytesRead - 1u];
			/* By using wRemLen, We are reading One byte extra, for spi header. Actually
			 * we should have deducted one byte from it.
			 */
			PH_CHECK_SUCCESS_FCT(statustmp,phhalHw_Ncx3321_Read( pDataParams,
					&pDataParams->sIrqResp.pIsrEvtBuffPtr[pDataParams->sIrqResp.bIsrBytesRead - 1u],
					(wRemEventLength + PHHAL_HW_NCX3321_DIRECTION_BYTE_LEN)));

			pDataParams->sIrqResp.pIsrEvtBuffPtr[pDataParams->sIrqResp.bIsrBytesRead - 1u] = bBackup;
		}

		dwEventStatusReg = (uint32) pDataParams->sIrqResp.pIsrEvtBuffPtr[4];
		dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.pIsrEvtBuffPtr[5]) << 8U;
		dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.pIsrEvtBuffPtr[6]) << 16U;
		dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.pIsrEvtBuffPtr[7]) << 24U;
	}

	if ((E_EVENT_ABORT & tReceivedEvents) != 0U)
	{
		(void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_EVENT_ABORT, NULL);
		return PH_ADD_COMPCODE_FIXED(PH_ERR_ABORTED, PH_COMP_HAL);
	}

	if(dwEventsReceived != NULL)
	{
		*dwEventsReceived = dwEventStatusReg;
	}

	if (dwEventStatusReg != PH_NCX3321_EVT_CTS)
	{
		if(bPayloadPresnt != 0u)
		{
			*ppEvtPayLoad = &pDataParams->sIrqResp.pIsrEvtBuffPtr[ 4U + sizeof(dwEventStatusReg)];
		}
		else
		{
			if (*ppEvtPayLoad != NULL)
			{
				*ppEvtPayLoad = NULL;
			}
		}
	}

	if ((dwEventStatusReg & dwEvtsWaitFor) != 0U)
	{
		status = PH_ERR_SUCCESS;
	}
	return status;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
