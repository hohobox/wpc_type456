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
*   @file    phpalI14443p4mC_Sw_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC_Sw_Int - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p4mC ISO/IEC 14443-4mC
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
#include <phpalI14443p4mC.h>
#include <ph_RefDefs.h>
#include <phDriver.h>


#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
#include "phpalI14443p4mC_Sw_Int.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4mC_Sw_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_SW_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4mC_Sw_Int.h header file are of the same vendor */
#if (PHPALI14443P4MC_SW_INT_VENDOR_ID_C != PHPALI14443P4MC_SW_INT_VENDOR_ID)
    #error "phpalI14443p4mC_Sw_Int.c and phpalI14443p4mC_Sw_Int.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4mC_Sw_Int.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4MC_SW_INT_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4MC_SW_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC_Sw_Int.c and phpalI14443p4mC_Sw_Int.h are different"
#endif
/* Check if current file and phpalI14443p4mC_Sw_Int.h header file are of the same Software version */
#if ((PHPALI14443P4MC_SW_INT_SW_MAJOR_VERSION_C != PHPALI14443P4MC_SW_INT_SW_MAJOR_VERSION) || \
     (PHPALI14443P4MC_SW_INT_SW_MINOR_VERSION_C != PHPALI14443P4MC_SW_INT_SW_MINOR_VERSION) || \
     (PHPALI14443P4MC_SW_INT_SW_PATCH_VERSION_C != PHPALI14443P4MC_SW_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC_Sw_Int.c and phpalI14443p4mC_Sw_Int.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
/* PPS Response State */
#define PH_I14443P4MC_PPSRES_IDLE		0u
#define PH_I14443P4MC_PPSRES_TRANSMIT	1u
#define PH_I14443P4MC_PPSRES_TXRATE		2u
#define PH_I14443P4MC_PPSRES_RXRATE		3u

/* Handle Rx Chaining state */
#define	PHPAL_I14443P4MC_HRxC_IDLE							0u
#define	PHPAL_I14443P4MC_HRxC_RECEPTION_START				1u
#define	PHPAL_I14443P4MC_HRxC_RECEPTION_SENDACK				2u
#define	PHPAL_I14443P4MC_HRxC_RECEPTION_RECEIVE				3u
#define PHPAL_I14443P4MC_HRxC_RECEPTION_DESELRES			4u
#define PHPAL_I14443P4MC_HRxC_END							5u

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Frame size table */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM aI14443p4mC_FsTableVar[PHPALI14443P4MC_FS_INDEX] = {14, 22, 30, 38, 46, 62, 94, 126, 254, 510, 1022, 2046, 4094};
/* Data rate table */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM aI14443p4mC_DrTableVar[PHPALI14443P4MC_DR_INDEX] = {PHHAL_HW_RF_DATARATE_106, PHHAL_HW_RF_DATARATE_212, PHHAL_HW_RF_DATARATE_424, PHHAL_HW_RF_DATARATE_848};


#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* State variables for Non-Blocking     */
static VAR(uint8, ANFCRL_VAR) gbP4mCPpsResState  = PH_I14443P4MC_PPSRES_IDLE;
static VAR(uint8, ANFCRL_VAR) gbP4mCHandleRxChainingState  = PHPAL_I14443P4MC_HRxC_IDLE;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_PpsRes(
                     P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPps,
                     VAR(uint8, ANFCRL_VAR) bPpsLength
										 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	switch (gbP4mCPpsResState)
	{
		case PH_I14443P4MC_PPSRES_IDLE:
			/* Validate PPS length */
			if((bPpsLength > 3U) || (bPpsLength < 2U))
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Validate PPS in start byte */
			if((uint8)(pPps[0] & 0xF0U) != PHPALI14443P4MC_PPS_CMD)
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Validate CID */
			if(0U != (pDataParams->bCidEnable))
			{
				if((pDataParams->bCid != (pPps[0] & 0x0FU)))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}
			}
			else
			{
				if(0U != (pPps[0] & 0x0FU))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}
			}

			/* Check for RFU values of PPS0 */
			if((pPps[1] & PHPALI14443P4MC_VALID_PPS0_MASK) != 0x01U)
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Check for PPS1 presence in PPS0 */
			if((pPps[1] & (~PHPALI14443P4MC_VALID_PPS0_MASK)) != 0u)
			{
				/* Validate Length */
				if(bPpsLength != 3U)
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				/* Check for RFU values of PPS1 */
				if(0U != (pPps[2] & PHPALI14443P4MC_PPS_PPS2_MASK))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				/* Check DR and DS */
				if((pDataParams->bUnequalDrDs == 0u) && ((pPps[2] & 0x03U) != ((pPps[2] & 0x0CU) >> 2U)))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				/* Check if this DR support was specified during ATS */
				if(0U != (pPps[2] & 0x03U))
				{
					if ((pDataParams->bDr & (uint8)(1U << (uint8)((pPps[2] & 0x03U) - 1u))) != 0u)
					{
						pDataParams->bDr = pPps[2] & 0x03U;
					}
					else
					{
						return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
					}
				}
				else
				{
					pDataParams->bDr = 0u;
				}

				/* Check if this DS support was specified during ATS */
				if(((pPps[2] & 0x0CU) >> 2U) != 0u)
				{
					if( 0u != (pDataParams->bDs & (uint8)(1U << (uint8)((uint8)((pPps[2] & 0x0CU) >> 2U) - 1u))))
					{
						pDataParams->bDs = ((pPps[2] & 0x0CU) >> 2U);
					}
					else
					{
						return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
					}
				}
				else
				{
					pDataParams->bDs = 0u;
				}
			}
			else
			{
				pDataParams->bDs = 0u;
				pDataParams->bDr = 0u;
			}
			gbP4mCPpsResState = PH_I14443P4MC_PPSRES_TRANSMIT;
			/* no break */
		case PH_I14443P4MC_PPSRES_TRANSMIT:
			/* Send PPS response */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
				pDataParams->pHalDataParams,
				PH_EXCHANGE_DEFAULT,
				pPps,
				PHPALI14443P4MC_PPS_LEN));
			PH_BREAK_ON_FAILURE(status);
			gbP4mCPpsResState = PH_I14443P4MC_PPSRES_TXRATE;
			return PH_STATUS_INPROCESS;
		case PH_I14443P4MC_PPSRES_TXRATE:
			/* Set DS data rate */
			if(0U != (pDataParams->bDs))
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING,
					aI14443p4mC_DrTableVar[pDataParams->bDs] | PHHAL_HW_RF_TYPE_A_FRAMING));
			}
			PH_BREAK_ON_FAILURE(status);
			gbP4mCPpsResState = PH_I14443P4MC_PPSRES_RXRATE;
			return PH_STATUS_INPROCESS;
		case PH_I14443P4MC_PPSRES_RXRATE:
			/* Set DR data rate */
			if(0U != (pDataParams->bDr))
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXDATARATE_FRAMING,
					aI14443p4mC_DrTableVar[pDataParams->bDr] | PHHAL_HW_RF_TYPE_A_FRAMING));
			}
			PH_BREAK_ON_FAILURE(status);
			/* Set internal state */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RX;
	}

	gbP4mCPpsResState = PH_I14443P4MC_PPSRES_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_DslRes(
                     P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
										 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDeSel[2] = {0xC2, 0x00};
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDeSelLen = 1;

	/* Build S frame, add CID if enabled */
	if(0U != (pDataParams->bCidPresence))
	{
		bDeSel[0] = (bDeSel[0] | PHPALI14443P4MC_BLOCK_HAS_CID);
		bDeSel[1] = pDataParams->bCid;
		wDeSelLen = 2;
	}

	/* Send DSL response */
	PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
		pDataParams->pHalDataParams,
		PH_TRANSMIT_DEFAULT,
		bDeSel,
		wDeSelLen));

	PH_CHECK_SUCCESS(status);

	/* Set state to NONE / initial state */
	pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_NONE;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_Ack(
                    P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRAck[2] = {PHPALI14443P4MC_BLOCK_R_PCB_ACK, 0x00};
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRAckLen = 1;

	/* prepare new R frame */
	bRAck[0] = (bRAck[0] | pDataParams->bBlockNr);

	/* add CID, if required */
	if (0U != (pDataParams->bCidPresence))
	{
		bRAck[0] = (bRAck[0] | PHPALI14443P4MC_BLOCK_HAS_CID);
		bRAck[1] = pDataParams->bCid;
		wRAckLen = 2;
	}

	/* Transmit data with PCD */
	status = phhalHw_Transmit(
		pDataParams->pHalDataParams,
		PH_TRANSMIT_DEFAULT,
		bRAck,
		wRAckLen);

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_StartWtxTimer(
                        P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
												)
{

	pDataParams->dwWtxPeriod = (uint32) (((pDataParams->bWtPercentage * (PHPAL_I14443P4MC_SW_CALCULATE_FWT_US(pDataParams->bFwi)) * pDataParams->bWtx) / 100u)
			- pDataParams->wWtDelta);
	pDataParams->dwWtxStart = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
	pDataParams->bWtxTimerSts = PHPAL_I14443P4MC_WTX_TIMER_PENDING;

	return PH_ERR_SUCCESS;
}


FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_HandleRxChaining(
                           P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           VAR(uint16, ANFCRL_VAR) wOption,
                           P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                           P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
												   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wHalRxBufferSize = 0u;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bHeaderLength = 0u;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aRxOverlapped[4] = { 0u };
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxOverlappedStartPos = 0u;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBufferOverflow = 0u;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRawResponse = NULL;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRawResponseLength = 0u;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pPayloadResponse = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPayloadLength = 0u;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRestartReceive = 0u;

	switch (gbP4mCHandleRxChainingState)
	{
		case PHPAL_I14443P4MC_HRxC_IDLE:
			wHalRxBufferSize = 0u;
			bHeaderLength = 0u;
			wRxOverlappedStartPos = 0u;
			bBufferOverflow = 0u;
			pRawResponse = NULL;
			wRawResponseLength = 0u;
			bRestartReceive = 0u;
			/* Get HAL RX buffer size */
			PH_CHECK_SUCCESS_FCT(status, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE,
				&wHalRxBufferSize));

			/* Forecast header length */
			PH_CHECK_SUCCESS_FCT(status, phpalI14443p4mC_Sw_Int_GetPduHeaderLength(
				pDataParams,
				PH_OFF,
				&bHeaderLength));

			wRawResponseLength = *pRxLength;
			pRawResponse = *ppRxBuffer;
			gbP4mCHandleRxChainingState = PHPAL_I14443P4MC_HRxC_RECEPTION_START;
			return PH_STATUS_INPROCESS;
		case PHPAL_I14443P4MC_HRxC_RECEPTION_START:
			if((bBufferOverflow == 0u) && (bRestartReceive == 0u))
			{
				/* Return with chaining status if the next chain may not fit into our buffer */
				if((wOption & PH_EXCHANGE_MODE_MASK) != PH_RECEIVE_CHAINING_BUFSIZE)
				{
					if((*pRxLength + aI14443p4mC_FsTableVar[pDataParams->bFsci]) > wHalRxBufferSize)
					{
						/* Reset RxBuffer Start Position */
						status = phhalHw_SetConfig(
								pDataParams->pHalDataParams,
								PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
								0);
						if (status == PH_ERR_SUCCESS) {
							status = PH_ERR_SUCCESS_CHAINING | PH_COMP_PAL_I14443P4MC;
						}
						break;
					}
				}

				/* Calculate start-position for overlapping */
				wRxOverlappedStartPos = wRawResponseLength - (uint16)bHeaderLength;

				/* Backup overlapped bytes */
				(void)memcpy(aRxOverlapped, &pRawResponse[wRxOverlappedStartPos], bHeaderLength);

				/* Adjust RX buffer start position. */
				status = phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					wRxOverlappedStartPos);
				PH_BREAK_ON_FAILURE(status);
			}
			gbP4mCHandleRxChainingState = PHPAL_I14443P4MC_HRxC_RECEPTION_SENDACK;
			return PH_STATUS_INPROCESS;
		case PHPAL_I14443P4MC_HRxC_RECEPTION_SENDACK:
			/* Send ACK */
			if(0U == (bRestartReceive))
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_Ack(pDataParams));
			}

			if(0U == (bBufferOverflow))
			{
				/* Adjust RX buffer start position. */
				status = phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					wRxOverlappedStartPos);
				PH_BREAK_ON_FAILURE(status);
			}
			gbP4mCHandleRxChainingState = PHPAL_I14443P4MC_HRxC_RECEPTION_RECEIVE;
			return PH_STATUS_INPROCESS;
		case PHPAL_I14443P4MC_HRxC_RECEPTION_RECEIVE:
			/* Receive chained data */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Receive(
				 pDataParams->pHalDataParams,
				 PH_RECEIVE_DEFAULT,
				 &pRawResponse,
				 &wRawResponseLength));

			/* Reset RX restart flag */
			bRestartReceive = 0;

			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				/* Validate received frame */
				status = phpalI14443p4mC_Sw_Int_ValidateFrame(
					pDataParams,
					&pRawResponse[wRxOverlappedStartPos],
					(wRawResponseLength - wRxOverlappedStartPos),
					&pPayloadResponse,
					&wPayloadLength);
			}

			if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_DESELECT)
			{
				status = phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					0);
				PH_BREAK_ON_FAILURE(status);

				/* Send S-Block DESELECT and exit */
				gbP4mCHandleRxChainingState = PHPAL_I14443P4MC_HRxC_RECEPTION_DESELRES;
				return PH_STATUS_INPROCESS;
			}

			/* Exit on EXT RF off */
			if((status & PH_ERR_MASK) == PH_ERR_EXT_RF_ERROR)
			{
				/* Application shall reset data parameters of all layers and
				 * shall restart listen/discovery loop on RF error */
				status = PH_ERR_EXT_RF_ERROR | PH_COMP_PAL_I14443P4MC;
				break;
			}
			else if ((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW)
			{
				/* Complete chaining even if buffer is full */
				if((wOption & PH_EXCHANGE_MODE_MASK) == PH_RECEIVE_CHAINING_BUFSIZE)
				{
					/* Reset wRxStartPos */
					status = phhalHw_SetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
						0);
					PH_BREAK_ON_FAILURE(status);

					/* Indicate Buffer Overflow */
					bBufferOverflow = 1;
				}
				else
				{
					break;
				}
			}

			else
			{
				/* On all other errors, restart receive and back to receive mode */
				if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
				{
					bRestartReceive = 1;
				}

				/* Next chunk of PDU has been received */
				if ((bBufferOverflow == 0u) && (bRestartReceive == 0u))
				{
					/* Restore overlapped bytes */
					(void)memcpy(&pRawResponse[wRxOverlappedStartPos], aRxOverlapped, bHeaderLength);  /* PRQA S 3200 */ /* PRQA S 3354 */

					/* Increment length */
					*pRxLength = *pRxLength + wPayloadLength;
				}
			}
			if(((pDataParams->bStateNow) == PHPAL_I14443P4MC_STATE_RXCHAINING) ||
					   ((pDataParams->bStateNow) == PHPAL_I14443P4MC_STATE_TX_R))
			{
				gbP4mCHandleRxChainingState	= PHPAL_I14443P4MC_HRxC_RECEPTION_START;
				return PH_STATUS_INPROCESS;
			}
			gbP4mCHandleRxChainingState = PHPAL_I14443P4MC_HRxC_END;
			return PH_STATUS_INPROCESS;
		case PHPAL_I14443P4MC_HRxC_RECEPTION_DESELRES:
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_DslRes(pDataParams));

			if (status == PH_ERR_SUCCESS) {
				status = PH_ERR_SUCCESS_DESELECTED | PH_COMP_PAL_I14443P4MC;
			}
			break;

		case PHPAL_I14443P4MC_HRxC_END:
			/* Reset RxBuffer Start Position */
			if (wRxOverlappedStartPos != 0U)
			{
				status = phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_RXBUFFER_STARTPOS,
					0);
				PH_BREAK_ON_FAILURE(status);
			}

			/* Return data */
			if (0U != (bBufferOverflow))
			{
				*pRxLength = 0;
				status = PH_ERR_BUFFER_OVERFLOW | PH_COMP_PAL_I14443P4MC;
			}
	}
	gbP4mCHandleRxChainingState	= PHPAL_I14443P4MC_HRxC_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_GetPduHeaderLength(
                           P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                           VAR(uint8, ANFCRL_VAR) bNadInclude,
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProtLength
													 )
{
	/* PCB length */
	*pProtLength = 1;

	/* Add CID if enabled */
	if(0U != (pDataParams->bCidPresence))
	{
		++(*pProtLength);
	}

	/* Add NAD if enabled and chaining is not used. */
	if ((pDataParams->bNadPresence != 0x00u) && (bNadInclude != 0x00u))
	{
		++(*pProtLength);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_ValidateFrame(
                        P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                        VAR(uint16, ANFCRL_VAR) wRxLength,
                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppPayload,
                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPayloadLength
												)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCheckNad;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBytePos;
   VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wHeaderLength = 1; /* PCB (1 byte) */

	/* Check for empty frame */
	if((0U == wRxLength) || (NULL == pRxBuffer))
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Check for PPS Request */
	if(PHPALI14443P4MC_PPS_CMD == (uint8)(pRxBuffer[0] & 0xF0U))
	{
		if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_ATS)
		{
			/* Change the State to PPS */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_PPS;
			return PH_ERR_SUCCESS;
		}
		else
		{
			/* Protocol error, as we have not received PPS after RATS */
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
	}

	/* Check for WTX */
	if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_WTX)
	{
		/* Return protocol error for frames other than WTX and NAK */
		if(((pRxBuffer[0] & 0xF0U) != 0xF0U) && ((pRxBuffer[0] & 0xF0U) != 0xB0U))
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
	}

	/* Check for TX chaining */
	if((pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_TXCHAINING)
	   && ((pRxBuffer[0] & PHPALI14443P4MC_BLOCK_MASK)
		   != (PHPALI14443P4MC_BLOCK_R & PHPALI14443P4MC_BLOCK_MASK)))
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Check if CID is present */
	switch (pRxBuffer[0] & PHPALI14443P4MC_BLOCK_MASK)
	{
	case (PHPALI14443P4MC_BLOCK_I & PHPALI14443P4MC_BLOCK_MASK):
	case (PHPALI14443P4MC_BLOCK_R & PHPALI14443P4MC_BLOCK_MASK):
	case (PHPALI14443P4MC_BLOCK_S & PHPALI14443P4MC_BLOCK_MASK):
		if (0U != (pRxBuffer[0] & PHPALI14443P4MC_BLOCK_HAS_CID))
		{
			/* Check if CID is supported */
			if(pDataParams->bCidEnable == PH_OFF)
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Check received block length */
			if (wRxLength < 2U)
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Check if CID value is correct */
			if ((pRxBuffer[1] & PHPALI14443P4MC_CID_MASK) != pDataParams->bCid)
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Update CID presence in command */
			pDataParams->bCidPresence = 1u;
		}
		else
		{
			if((pDataParams->bCidEnable != 0u) && (pDataParams->bCid != 0U))
			{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* Update CID absence in command */
			pDataParams->bCidPresence = 0u;
		}

		/* Validate received length */
		if(wRxLength > aI14443p4mC_FsTableVar[pDataParams->bFsci])
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
		break;

	default:
		/* Unknown block format */
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	switch (pRxBuffer[0] & PHPALI14443P4MC_BLOCK_MASK)
	{
		/* Process I frame */
	case (PHPALI14443P4MC_BLOCK_I & PHPALI14443P4MC_BLOCK_MASK):
		if (0U != (pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_NAD_FOLLOWING))
		{
			/* NAD present only in normal I-Block and first Block of chaining */
			if((pDataParams->bNadEnable != 0u) && (pDataParams->bChainingRx == 0u))
			{
				bBytePos = (pDataParams->bCidPresence == 1u)? 2u: 1u;

				/* Validate received block length */
				if(wRxLength < ((uint16)bBytePos + 1U))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				/* Validate NAD RFU bits b4 and b8 */
				if((pRxBuffer[bBytePos] & 0x88U) != 0x00U)
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				/* Validate SAD and DAD */
				if(((pRxBuffer[bBytePos] & 0x07U) == ((pRxBuffer[bBytePos] & 0x70U) >> 4U))
				   && (pRxBuffer[bBytePos] != 0x00U))
				{
					return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
				}

				bCheckNad = 1;
				pDataParams->bNad = pRxBuffer[bBytePos];
				pDataParams->bNadPresence = 1u;
			}
			else
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}
		}
		else
		{
			bCheckNad = 0;

			/* If NAD bit is not set in PCB and not in RX chaining, reset NAD presence. */
			if(pDataParams->bChainingRx == 0u)
			{
				pDataParams->bNadPresence = 0u;
			}
		}

		/* Check if I-Block is valid */
		PH_CHECK_SUCCESS_FCT(status, phpalI14443p4mC_Sw_Int_IsValidIBlock(
			pDataParams->bOpMode,
			pDataParams->bCidPresence,
			pDataParams->bCid,
			bCheckNad,
			pDataParams->bNad,
			pRxBuffer,
			wRxLength));

		/* ISO14443-4 7.5.3.2 Rule D */
		pDataParams->bBlockNr = (pDataParams->bBlockNr == 0u)?1u:0u;

		if (0U != (pRxBuffer[0] & PHPALI14443P4MC_BLOCK_IS_CHAIN))
		{
			/* if PCD is chaining return data and set next state to R frame send */
			pDataParams->bChainingRx = 1;
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RXCHAINING;
		}
		else
		{
			/* normal frame received, next state is send I frame */
			pDataParams->bChainingRx = 0;
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_I;
		}

		/* Calculate header length */
		if ((pDataParams->bNadPresence != 0u) && (bCheckNad == 1U))
		{
			wHeaderLength++;
		}
		break;

	case (PHPALI14443P4MC_BLOCK_R & PHPALI14443P4MC_BLOCK_MASK):
		/* Check if R-Block is valid */
		PH_CHECK_SUCCESS_FCT(status, phpalI14443p4mC_Sw_Int_IsValidRBlock(
			pDataParams->bOpMode,
			pDataParams->bCidPresence,
			pDataParams->bCid,
			pRxBuffer,
			wRxLength));

		if (0U != (pDataParams->bChainingTx))
		{
			/* PICC is chaining data, check if PCD received data.
			 * ISO14443-4 7.5.4.3 Rule 12 and 13. */
			if ((((pRxBuffer[0]) & PHPALI14443P4MC_R_NAK_MASK) == 0U) &&
				(((pRxBuffer[0]) & PHPALI14443P4MC_BLOCKNUMBER_MASK) != (pDataParams->bBlockNr)))
			{
				pDataParams->bBlockNr = (pDataParams->bBlockNr == 0u)?1u:0u;
				pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_I;
			}
			else if ((((pRxBuffer[0]) & PHPALI14443P4MC_R_NAK_MASK) != 0U) &&
				(((pRxBuffer[0]) & PHPALI14443P4MC_BLOCKNUMBER_MASK) != (pDataParams->bBlockNr)))
			{
				/* As per rule 7.5.4.3, Rule 12
				/ * Received R(NAK) with block number not equal to the PICC's current block number*/
				/* Send R(ACK) Block without toggling block number as per Sec 7.5.4.2 NOTE 2. */
				pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_R;
			}
			else
			{
				/* Something is wrong, re-send current frame.
				 * ISO14443-4 7.5.4.3 Rule 11. */
				pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RESEND;
			}
		}
		else if (0U != (pDataParams->bChainingRx))
		{
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_R;
		}
		else if ((pRxBuffer[0] & PHPALI14443P4MC_BLOCKNUMBER_MASK) == (pDataParams->bBlockNr))
		{
			/* Something is wrong, re-send current frame.
			 * ISO14443-4 7.5.4.3 Rule 11. */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RESEND;
		}
		else if ((((pRxBuffer[0]) & PHPALI14443P4MC_R_NAK_MASK) != 0u)
				 && ((pRxBuffer[0] & PHPALI14443P4MC_BLOCKNUMBER_MASK) != (pDataParams->bBlockNr)))
		{
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_R;
		}
		else
		{
			/* Do Nothing */
		}
		break;

	case (PHPALI14443P4MC_BLOCK_S & PHPALI14443P4MC_BLOCK_MASK):
		/* Check if S-Block is valid */
		PH_CHECK_SUCCESS_FCT(status, phpalI14443p4mC_Sw_Int_IsValidSBlock(
			pDataParams->bOpMode,
			pDataParams->bCidPresence,
			pDataParams->bCid,
			pDataParams->bWtx,
			pRxBuffer,
			wRxLength));

		if((pRxBuffer[0] & PHPALI14443P4MC_BLOCK_S_MASK) == PHPALI14443P4MC_BLOCK_S_DESELECT)
		{
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_DESELECT;
		}
		else if((pRxBuffer[0] & PHPALI14443P4MC_BLOCK_S_MASK) == PHPALI14443P4MC_BLOCK_S_WTX)
		{
			/* Check if WTX response is received after a valid WTX request */
			if((pDataParams->bStateNow != PHPAL_I14443P4MC_STATE_WTX)
			   && (pDataParams->bStateNow != PHPAL_I14443P4MC_STATE_RESEND))
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}
			else
			{
				/* Restore previous state (state before WTX) */
				if(0U != (pDataParams->bChainingRx))
				{
					pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RXCHAINING;
				}
				else
				{
					pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_I;
				}
			}
		}
		else
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
		break;

	default:
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Calculate header length */
	if (0U != (pDataParams->bCidPresence))
	{
		wHeaderLength++;
	}

	/* Update pay-load */
	if((ppPayload != NULL) && (pPayloadLength != NULL))
	{
		*ppPayload = &pRxBuffer[wHeaderLength];

		if(wRxLength >= wHeaderLength)
		{
			*pPayloadLength = (uint16) (wRxLength - wHeaderLength);
		}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidIBlock(
                        VAR(uint8, ANFCRL_VAR) bOpMode,
                        VAR(uint8, ANFCRL_VAR) bCheckCid,
                        VAR(uint8, ANFCRL_VAR) bCid,
                        VAR(uint8, ANFCRL_VAR) bCheckNad,
                        VAR(uint8, ANFCRL_VAR) bNad,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                        VAR(uint16, ANFCRL_VAR) wRxLength
												)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0;

	/* Check constant bit b2 of PCB is set to '1' */
	if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x02U) != 0x02U)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Check RFU bits only for ISO mode */
	if(bOpMode == RD_LIB_MODE_ISO)
	{
		/* Check RFU bit b6 of PCB is set to '0' */
		if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x20U) != 0x00U)
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1;

	/* Enable CID checking if necessary */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* Enable NAD checking if necessary */
	if (0U != (bCheckNad))
	{
		wExpRxLength++;
	}

	/* The frame should have the minimum frame length */
	if (wRxLength < wExpRxLength)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* CID presence check */
	if ((0u != bCheckCid) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) != 0x00u) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS+1U] & PHPALI14443P4MC_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) == 0x00u))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* NAD presence check */
	if ((bCheckNad != 0x00u) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_NAD_FOLLOWING) != 0x00u) &&
		((pRxBuffer[wExpRxLength-1u] & PHPALI14443P4MC_NAD_MASK) == bNad))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD absence check */
	else if ((0u == bCheckNad) && ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_NAD_FOLLOWING) == 0x00u))
	{
		/* CHECK SUCCEEDED */
	}
	/* NAD protocol error */
	else
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidRBlock(
                        VAR(uint8, ANFCRL_VAR) bOpMode,
                        VAR(uint8, ANFCRL_VAR) bCheckCid,
                        VAR(uint8, ANFCRL_VAR) bCid,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                        VAR(uint16, ANFCRL_VAR) wRxLength
												)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0;

	/* Check constant bits of PCB - b6 is set to '1' and b3 to '0' */
	if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x24U) != 0x20U)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Check RFU bits only for ISO mode */
	if(bOpMode == RD_LIB_MODE_ISO)
	{
		/* Check RFU bit b2 of PCB is set to '1' */
		if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x02U) != 0x02U)
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength != wExpRxLength)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* CID presence check */
	if ((0u != bCheckCid) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) != 0x00u) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS+1U] & PHPALI14443P4MC_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) == 0u))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidSBlock(
                        VAR(uint8, ANFCRL_VAR) bOpMode,
                        VAR(uint8, ANFCRL_VAR) bCheckCid,
                        VAR(uint8, ANFCRL_VAR) bCid,
                        VAR(uint8, ANFCRL_VAR) bWtx,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                        VAR(uint16, ANFCRL_VAR) wRxLength
												)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wExpRxLength = 0;

	/* Check constant bit b3 of PCB is set to '0' */
	if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x04U) != 0x00U)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* Check RFU bits only for ISO mode */
	if(bOpMode == RD_LIB_MODE_ISO)
	{
		/* Check RFU bits of PCB - b2 is set to '1' and b1 is set to 0 */
		if ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & 0x03U) != 0x02U)
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
	}

	/* We always expect the PCB byte to be present */
	wExpRxLength = 1;

	/* If CID is enabled, we always expect it */
	if (0U != (bCheckCid))
	{
		wExpRxLength++;
	}

	/* If this is a WTX request, we expect an additional INF byte */
	if (PHPAL_I14443P4MC_SW_IS_WTX(pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS]) != 0u)
	{
		if (((pRxBuffer[wExpRxLength] & PHPAL_I14443P4MC_SW_WTX_VALUE_MASK) != bWtx) ||
				((pRxBuffer[wExpRxLength] & PHPAL_I14443P4MC_SW_WTX_RFU_MASK) != 0U))
		{
			return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
		}
		wExpRxLength++;
	}

	/* The frame should have the exact frame length */
	if (wRxLength != wExpRxLength)
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	/* CID presence check */
	if ((0u != bCheckCid) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) != 0u) &&
		((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS+1U] & PHPALI14443P4MC_CID_MASK) == bCid))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID absence check */
	else if ((0u == bCheckCid) && ((pRxBuffer[PHPAL_I14443P4MC_SW_PCB_POS] & PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING) == 0u))
	{
		/* CHECK SUCCEEDED */
	}
	/* CID protocol error */
	else
	{
		return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
	}

	return PH_ERR_SUCCESS;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

#ifdef __cplusplus
}
#endif
