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
*   @file    phhalHw_Ncx3321_Int.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Int - HAL API usage in common use cases.
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
#include <phhalHw.h>
#include <ph_RefDefs.h>
#include <ph_Status.h>

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
#include "phhalHw_Ncx3321_InstrMngr.h"
#include "phhalHw_Ncx3321_Wait.h"
#include "phhalHw_Ncx3321_Int.h"
#include <phhalHw_Ncx3321_Reg.h>
#include <phhalHw_Ncx3321_Instr.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INT_VENDOR_ID_C != PHHALHW_NCX3321_INT_VENDOR_ID)
    #error "phhalHw_Ncx3321_Int.c and phhalHw_Ncx3321_Int.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION_C != PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Int.c and phhalHw_Ncx3321_Int.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INT_SW_MAJOR_VERSION_C != PHHALHW_NCX3321_INT_SW_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_INT_SW_MINOR_VERSION_C != PHHALHW_NCX3321_INT_SW_MINOR_VERSION) || \
     (PHHALHW_NCX3321_INT_SW_PATCH_VERSION_C != PHHALHW_NCX3321_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Int.c and phhalHw_Ncx3321_Int.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
#define PHHAL_HW_15693_26KBPS           (0x00000000)
#define PHHAL_HW_15693_53KBPS           (0x00000020)
#define PHHAL_HW_15693_106KBPS          (0x00000040)
#define PHHAL_HW_15693_212KBPS          (0x00000060)

#define PHHAL_HW_INT_STATE_IDLE	0u
#define PHHAL_HW_INT_STATE_CMD1	1u
#define PHHAL_HW_INT_STATE_CMD2	2u
#define PHHAL_HW_INT_STATE_CMD3	3u

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Digital delay for all protocols and speeds in microseconds */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM gkphhalHw_Ncx3321_DigiDelays_Us[][4] =
{
/* PHHAL_HW_CARDTYPE_ISO14443A */
{/* 106KBaud */17, /* 212KBaud */49, /* 424KBaud */45, /* 848KBaud */42 },

/* PHHAL_HW_CARDTYPE_ISO14443B */
{/* 106KBaud */182, /* 212KBaud */91, /* 424KBaud */46, /* 848KBaud */23 },

/* PHHAL_HW_CARDTYPE_FELICA_212 */
{/* N/A */0, /* 212KBaud */322, /* 424KBaud */165, /* N/A */0 },

/* PHHAL_HW_CARDTYPE_ISO15693 */
{/* LOW */0, /* HIGH */193, /* FAST_LOW */0, /* FAST_HIGH */89 }};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bTimerStartState = PHHAL_HW_INT_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) bSetTxState = PHHAL_HW_INT_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) bSetTmoState = PHHAL_HW_INT_STATE_IDLE;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_ResetState(void)
{
    bTimerStartState = PHHAL_HW_INT_STATE_IDLE;
    bSetTxState = PHHAL_HW_INT_STATE_IDLE;
    bSetTmoState = PHHAL_HW_INT_STATE_IDLE;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetTxBuffer(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferLen,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferSize
											)
{
	/* We need to watch that we do not overwrite content below the RxStartPos though. */
	if ((&(pDataParams->pTxBuffer)[1]) == (pDataParams->pRxBuffer))
	{
		(*pTxBuffer) = &(pDataParams->pTxBuffer[pDataParams->wRxBufStartPos]);
		(*pTxBufferSize) = (pDataParams->wTxBufSize) - (pDataParams->wRxBufStartPos);
	}
	/* Else just return the actual Buffer. */
	else
	{
		*pTxBuffer = pDataParams->pTxBuffer;
		*pTxBufferSize = pDataParams->wTxBufSize;
	}

	/* Return stored length. */
	*pTxBufferLen = pDataParams->wTxBufLen;

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetRxBuffer(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferLen,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferSize
											)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bOffset = 0U;

	if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
	{
		bOffset = 1U;
	}
	/* Update out parameters */
	*pRxBuffer = &pDataParams->pRxBuffer[pDataParams->wRxBufStartPos - bOffset];
	*pRxBufferSize = pDataParams->wRxBufSize - pDataParams->wRxBufStartPos - bOffset;
	*pRxBufferLen = pDataParams->wRxBufLen;

	return PH_ERR_SUCCESS;
}

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_Reset(void)
{
	static VAR(uint8, ANFCRL_VAR) bResetState = 0U;
	static VAR(uint32, ANFCRL_VAR) bResetDelay = 0U;
	VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;

	switch (bResetState)
	{
		case 0u:
			/* Send the reset pulse to FE to reset. */
			phDriver_PinWrite(PHDRIVER_PIN_RESET, RESET_POWERDOWN_LEVEL);

			// bResetDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			bResetState = 1U;
			return PH_STATUS_INPROCESS;

		case 1u:
			phDriver_PinWrite(PHDRIVER_PIN_RESET, RESET_POWERUP_LEVEL);

			// bResetDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			bResetState = 2U;
			return PH_STATUS_INPROCESS;

		case 2u:
			/* Do Nothing */
			break;
		default:
			bResetState = 0U;
			return PH_ERR_INTERNAL_ERROR;
	}
	bResetState = 0U;
	return PH_ERR_SUCCESS;
}

#else
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_Reset(void)
{
	static VAR(uint8, ANFCRL_VAR) bResetState = 0U;
	static VAR(uint32, ANFCRL_VAR) bResetDelay = 0U;
	VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;

	switch (bResetState)
	{
		case 0u:
#ifndef AUTOSAR_VER
			/* Send the reset pulse to FE to reset. */
			phDriver_PinWrite(PHDRIVER_PIN_RESET, RESET_POWERDOWN_LEVEL);
#else
			phDriver_PinWrite(ANFCLIB_PCConfig.AnfcRL_DioChannelRST, RESET_POWERDOWN_LEVEL);
#endif

			bResetDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			bResetState = 1U;
			return PH_STATUS_INPROCESS;
			/* No break */
		case 1u:
			dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, bResetDelay);

			/* Check for timer overflow, abort if timer overflow happens */
			if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
			{
				bResetState = 0U;
				return PH_ERR_ABORTED;
			}
			else
			{
				/* Delay after power down - 5ms*/
				if (dwElapsedTime < PHHAL_HW_NCX3321_RESET_DELAY_MICRO_SECS)
				{
					return PH_STATUS_INPROCESS;
				}
				else
				{
#ifndef AUTOSAR_VER
					phDriver_PinWrite(PHDRIVER_PIN_RESET, RESET_POWERUP_LEVEL);
#else
					phDriver_PinWrite(ANFCLIB_PCConfig.AnfcRL_DioChannelRST, RESET_POWERUP_LEVEL);
#endif

					bResetDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
					bResetState = 2U;
				}
			}
			return PH_STATUS_INPROCESS;
			/* No break */
		case 2u:
			dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, bResetDelay);
			/* Check for timer overflow, abort if timer overflow happens */
			if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
			{
				bResetState = 0U;
				return PH_ERR_ABORTED;
			}
			else
			{
				/* Delay after power up - 1ms*/
				if (dwElapsedTime < PHHAL_HW_NCX3321_RESET_GUARDTIME_MICRO_SECS)
				{
					return PH_STATUS_INPROCESS;
				}
				else
				{
					/* Do nothing */
				}
			}
			break;
		default:
			bResetState = 0U;
			return PH_ERR_INTERNAL_ERROR;
			/* No break */
	}
	bResetState = 0U;
	return PH_ERR_SUCCESS;
}

#endif

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_TimerStart(
                    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bTimer,
                    VAR(uint32, ANFCRL_VAR) dwStartCond,
                    VAR(uint32, ANFCRL_VAR) dwStopCond,
                    VAR(uint32, ANFCRL_VAR) wPrescaler,
                    VAR(uint32, ANFCRL_VAR) dwLoadValue
										)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmrConfigReg = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTmrRelaodReg = 0U;
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEnableMask = 0U;
	static VAR(uint32, ANFCRL_VAR) dwStartNowMask = 0U;

	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTemp = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF wRegTypeValueSets[18] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSizeOfRegTypeValueSets = 0U;
	VAR(phTools_EventBits_t, ANFCRL_VAR) PH_MEMLOC_REM tReceivedEvents = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pEvtPayload = NULL;

	switch(bTimerStartState)
	{
		case PHHAL_HW_INT_STATE_IDLE:
			/* Populate the timer configure and reload registers */

			switch(bTimer)
			{
				case CLIF_TIMER0_CONFIG:
					bTmrConfigReg = CLIF_TIMER0_CONFIG;
					bTmrRelaodReg = CLIF_TIMER0_RELOAD;
					dwEnableMask = CLIF_TIMER0_CONFIG_T0_ENABLE_MASK;
					dwStartNowMask = CLIF_TIMER0_CONFIG_T0_START_NOW_MASK;
					break;

				case CLIF_TIMER1_CONFIG:
					bTmrConfigReg = CLIF_TIMER1_CONFIG;
					bTmrRelaodReg = CLIF_TIMER1_RELOAD;
					dwEnableMask = CLIF_TIMER1_CONFIG_T1_ENABLE_MASK;
					dwStartNowMask = CLIF_TIMER1_CONFIG_T1_START_NOW_MASK;
					break;

				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			if((dwStartCond & dwStartNowMask) == dwStartNowMask)
			{
				(void)phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE, E_PHHAL_HW_EVT_SIG, NULL);
			}

			bTimerStartState = PHHAL_HW_INT_STATE_CMD1;
			return PH_STATUS_INPROCESS;
			/* No break */

		case PHHAL_HW_INT_STATE_CMD1:

			/*write 0 to stop timer*/
			wSizeOfRegTypeValueSets = 0U;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = bTmrConfigReg;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = 0x00U;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = 0x00U;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = 0x00U;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = 0x00U;

			/*load the timer  reload value*/
			dwTemp = (dwLoadValue & TMR_RELOAD_VALUE_MASK);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = bTmrRelaodReg;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

			/* Timer MODE_SEL is defined by ePrescaler, 0x01U enables the timer */
			dwTemp = (dwStartCond | dwStopCond | wPrescaler | dwEnableMask );
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = bTmrConfigReg;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegisterMultiple( pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
			PH_BREAK_ON_FAILURE(status);
			/* If the timer is started immediately, then wait for Interrupt (Timer Event) from FW */
			if((dwStartCond & dwStartNowMask) == dwStartNowMask)
			{
				bTimerStartState = PHHAL_HW_INT_STATE_CMD2;
			}
			else
			{
				break;
			}
			return PH_STATUS_INPROCESS;
			/*no break*/
		case PHHAL_HW_INT_STATE_CMD2:
			/*Wait for Timer event*/
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_WaitForEvent(
				pDataParams,
				PH_NCX3321_EVT_TIMER,
				PHHAL_HW_MAX_DELAY,
				TRUE,
				&tReceivedEvents,
				&pEvtPayload));
			break;
	}

	/* Reset static variables */
	bTimerStartState = PHHAL_HW_INT_STATE_IDLE;
	bTmrConfigReg = 0U;
	bTmrRelaodReg = 0U;
	dwEnableMask = 0U;
	dwStartNowMask = 0U;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig_Int(
                    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    VAR(uint16, ANFCRL_VAR) wValue
										)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwValue = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF wRegTypeValueSets[30] =
  { 0 };
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSizeOfRegTypeValueSets = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTemp = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwReqAEx = 0U;
  VAR(double, ANFCRL_VAR) PH_MEMLOC_REM fTime = 0.0;	/* NIDEC_PORTING */

	switch (wConfig)
	{
		case PHHAL_HW_CONFIG_PARITY:

			/* Tx-Parity,  Rx-Parity is OFF */
			if (wValue == PH_OFF)
			{
				dwValue = (uint32) ~(uint32) CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TX_FRAME_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				dwValue = (uint32) ~(uint32) CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_RX_PROTOCOL_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				/* Turn ON Tx-Parity */
				dwValue = CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TX_FRAME_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				/* Turn ON Rx-Parity */
				dwValue = CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_RX_PROTOCOL_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}

			break;

		case PHHAL_HW_CONFIG_TXCRC:

			if (wValue == PH_OFF)
			{
				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK;

				/* Perform write */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, CLIF_CRC_TX_CONFIG, dwValue));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{

				wSizeOfRegTypeValueSets = 0U;

				/*Clear the Bits*/
				dwTemp =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;

		case PHHAL_HW_CONFIG_RXCRC:

			if (wValue == PH_OFF)
			{
				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, CLIF_CRC_RX_CONFIG, dwValue));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{

				wSizeOfRegTypeValueSets = 0U;

				/*Clear the Bits */
				dwTemp =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);

			}
			break;
		case PHHAL_HW_CONFIG_ASK100:
			/* TODO:
			 * Presently for ASK100/ASK10 is changed for ISO15693, loading will be
			 * done using the load_rf_config, But check whether can it be done to
			 * change a particular register itself to support this switching.
			 */
			if (PHHAL_HW_CARDTYPE_ISO15693 == pDataParams->bCardType)
			{
				/* switch off 100% ASK */
				do
				{
					if (wValue == PH_OFF)
					{
						statusTmp = phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK10, 0xFF);
					}
					/* switch on 100% ASK */
					else
					{
						statusTmp = phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK100, 0xFF);
					}
				}while(statusTmp == PH_STATUS_INPROCESS);
			}
			break;

		case PHHAL_HW_CONFIG_RXWAIT_US:
			/* Set Rx Wait(deaf) bits */
			dwValue = PHHAL_HW_NCX3321_TX_RX_PRESCALER;
			dwTemp = wValue;
			if (0U != dwTemp)
			{
				fTime = (double) (((double) dwTemp * 13.56) / (double) (dwValue));	/* NIDEC_PORTING */
				dwTemp = (uint32) fTime;
				dwValue |= (uint32) dwTemp << CLIF_RX_WAIT_RX_WAIT_VALUE_POS;
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_RX_WAIT, dwValue ));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_RX_WAIT, dwValue ));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US:
			if ((pDataParams->wCfgShadow[wConfig] != wValue) ||
				(pDataParams->bTimeoutUnit != PHHAL_HW_TIME_MICROSECONDS) ||
				(pDataParams->bOpeMode != RD_LIB_MODE_EMVCO))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetTmo(pDataParams, wValue, PHHAL_HW_TIME_MICROSECONDS));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
				pDataParams->bTimeoutUnit = PHHAL_HW_TIME_MICROSECONDS;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS:
			if ((pDataParams->wCfgShadow[wConfig] != wValue) ||
				(pDataParams->bTimeoutUnit != PHHAL_HW_TIME_MILLISECONDS) ||
				(pDataParams->bOpeMode != RD_LIB_MODE_EMVCO))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetTmo(pDataParams, wValue, PHHAL_HW_TIME_MILLISECONDS));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
				pDataParams->bTimeoutUnit = PHHAL_HW_TIME_MILLISECONDS;
			}
			break;
		case PHHAL_HW_CONFIG_TRXCRC:
			if (wValue == PH_OFF)
			{
				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				wSizeOfRegTypeValueSets = 0U;

				/*Clear the Bits*/
				dwTemp =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Clear the Bits */
				dwTemp =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;
		case PHHAL_HW_CONFIG_REQAEX:
			dwValue = PHHAL_HW_NCX3321_TX_RX_PRESCALER;
			dwReqAEx = 76U; /*This value is fixed and is the same as the value in state PHPAL_I14443P3A_REQAEX_CONFIG*/
			if (wValue == PH_OFF)
			{
				fTime = (double) (((double) dwReqAEx * 13.56) / (double) (dwValue));	/* NIDEC_PORTING */
				dwReqAEx = (uint32) fTime;
				dwValue |= (uint32) dwReqAEx << CLIF_RX_WAIT_RX_WAIT_VALUE_POS;

				/* Set Rx Wait(deaf) bits */
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_RX_WAIT;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				/* CRC calculator, your services are not required */
				dwValue = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				wSizeOfRegTypeValueSets = 0U;
				/*Set Rx Wait(deaf) bits*/
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_RX_WAIT;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				/*Clear the Bits*/
				dwTemp =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK);

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Clear the Bits */
				dwTemp =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Set the new value  */
				dwTemp = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK;

				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_RX_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdReg(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_INTERNAL_ERROR;

    if (pDataParams->bOpeMode != RD_LIB_MODE_FELICA)
    {
        /* Clear FeliCa EMD Control Register */
        PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, FELICA_EMD_CONTROL, (uint32)0x0U));
        PH_CHECK_SUCCESS(statusTmp);
        /* Reset shadow register */
        pDataParams->dwFelicaEmdReg = (uint32)0x0U;
    }
    else
    {
        /* Configure FeliCa EMD Control Register with default value */
    	PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, FELICA_EMD_CONTROL, PHHAL_HW_NCX3321_DEFAULT_FELICA_EMD_REGISTER));
    	PH_CHECK_SUCCESS(statusTmp);
        /* Configure shadow register with default value */
        pDataParams->dwFelicaEmdReg = PHHAL_HW_NCX3321_DEFAULT_FELICA_EMD_REGISTER;
    }

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(
	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wValue,
	VAR(uint32, ANFCRL_VAR) dwMaskValue
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;

	if ((wValue != PH_ON) && (wValue != PH_OFF))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
	}

	if(wValue != PH_OFF)
	{
		if ((pDataParams->dwFelicaEmdReg & dwMaskValue) == 0U)
		{
			/* Update FELICA_EMD_CONTROL Register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Instr_WriteRegisterOrMask(pDataParams, FELICA_EMD_CONTROL, dwMaskValue));
			PH_CHECK_SUCCESS(statusTmp);
			/* Update shadow register */
			pDataParams->dwFelicaEmdReg |= dwMaskValue;
		}
	}
	else
	{
		if ((pDataParams->dwFelicaEmdReg & dwMaskValue) != 0U)
		{
			/* Update FELICA_EMD_CONTROL Register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, FELICA_EMD_CONTROL, (uint32)~dwMaskValue));
			PH_CHECK_SUCCESS(statusTmp);
			/* Update shadow register */
			pDataParams->dwFelicaEmdReg &= (uint32)~dwMaskValue;
		}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte(
  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wValue,
  VAR(uint8, ANFCRL_VAR) bBytePos,
  VAR(uint32, ANFCRL_VAR) dwMaskValue
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_INTERNAL_ERROR;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwValue = 0U;

	if ((wValue & 0xFF00U) != 0U)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
	}

	if ((uint8)(pDataParams->dwFelicaEmdReg >> bBytePos) != (uint8)wValue)
	{
		dwValue = pDataParams->dwFelicaEmdReg;
		dwValue &= ((uint32)~dwMaskValue);
		dwValue |= ((uint32)wValue << bBytePos);
		/* Update FELICA_EMD_CONTROL Register */
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, FELICA_EMD_CONTROL, dwValue));
		PH_CHECK_SUCCESS(statusTmp);
		/* Update shadow register */
		pDataParams->dwFelicaEmdReg = dwValue;
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetCardMode(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      VAR(uint16, ANFCRL_VAR) wTxDataRate,
                      VAR(uint16, ANFCRL_VAR) wRxDataRate,
                      VAR(uint16, ANFCRL_VAR) wSubcarrier )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTxConfig = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRxConfig = 0U;

	UNUSED(wSubcarrier);
	if(pDataParams->wTargetMode == PH_OFF)
	{
		if(wTxDataRate == pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXDATARATE_FRAMING])
		{
			wTxDataRate = PHHAL_HW_RF_DATARATE_NO_CHANGE;
		}
		if(wRxDataRate == pDataParams->wCfgShadow[PHHAL_HW_CONFIG_RXDATARATE_FRAMING])
		{
			wRxDataRate = PHHAL_HW_RF_DATARATE_NO_CHANGE;
		}
	}
	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:

			switch (pDataParams->bCardType)
			{
			case PHHAL_HW_CARDTYPE_ISO14443A:

				/* Check if Target is activated and perform required change to switch BaudRate. */
				if (pDataParams->wTargetMode != PH_OFF)
				{
					if(pDataParams->bActiveMode == PH_OFF)
					{
						switch (wTxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_106:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_106_MANCH_SUBC;
								/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
								break;
							case PHHAL_HW_RF_DATARATE_212:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_212_BPSK;
								/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_424_BPSK;
								/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
								break;
							case PHHAL_HW_RF_DATARATE_848:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_848_BPSK;
								/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}

						switch (wRxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_106:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_106_MILLER;
								/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
								break;
							case PHHAL_HW_RF_DATARATE_212:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_212_MILLER;
								/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_424_MILLER;
								/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
								break;
							case PHHAL_HW_RF_DATARATE_848:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_848_MILLER;
								/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}
					}
					else
					{
						switch (wTxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_106:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_AT_106;
								break;
							case PHHAL_HW_RF_DATARATE_212:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_AT_212;
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_AT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}
						switch (wRxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_106:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_AT_106;
								break;
							case PHHAL_HW_RF_DATARATE_212:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_AT_212;
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_AT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}
					}

				}
				else
				{
					switch (wTxDataRate)
					{
						case PHHAL_HW_RF_DATARATE_106:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_106_MILLER;
							/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
							break;
						case PHHAL_HW_RF_DATARATE_212:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_212_MILLER;
							/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
							break;
						case PHHAL_HW_RF_DATARATE_424:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_424_MILLER;
							/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
							break;
						case PHHAL_HW_RF_DATARATE_848:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443A_848_MILLER;
							/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
							break;
						case PHHAL_HW_RF_DATARATE_NO_CHANGE:
							bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
							break;
						default:
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					}
					switch (wRxDataRate)
					{
						case PHHAL_HW_RF_DATARATE_106:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC;
							/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
							break;
						case PHHAL_HW_RF_DATARATE_212:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_212_BPSK;
							/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
							break;
						case PHHAL_HW_RF_DATARATE_424:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_424_BPSK;
							/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
							break;
						case PHHAL_HW_RF_DATARATE_848:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443A_848_BPSK;
							/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
							break;
						case PHHAL_HW_RF_DATARATE_NO_CHANGE:
							bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
							break;
						default:
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					}
				}
				break;

			case PHHAL_HW_CARDTYPE_ISO14443B:

				switch (wTxDataRate)
				{
					case PHHAL_HW_RF_DATARATE_106:
						bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443B_106_NRZ;
						/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_106;*/
						break;
					case PHHAL_HW_RF_DATARATE_212:
						bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443B_212_NRZ;
						/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_212;*/
						break;
					case PHHAL_HW_RF_DATARATE_424:
						bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443B_424_NRZ;
						/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_424;*/
						break;
					case PHHAL_HW_RF_DATARATE_848:
						bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO14443B_848_NRZ;
						/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_848;*/
						break;
					case PHHAL_HW_RF_DATARATE_NO_CHANGE:
						bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
						break;
					default:
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}

				switch (wRxDataRate)
				{
					case PHHAL_HW_RF_DATARATE_106:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443B_106_BPSK;
						/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_106;*/
						break;
					case PHHAL_HW_RF_DATARATE_212:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443B_212_BPSK;
						/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_212;*/
						break;
					case PHHAL_HW_RF_DATARATE_424:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443B_424_BPSK;
						/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_424;*/
						break;
					case PHHAL_HW_RF_DATARATE_848:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO14443B_848_BPSK;
						/*  pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_848;*/
						break;
					case PHHAL_HW_RF_DATARATE_NO_CHANGE:
						bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
						break;
					default:
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}
				break;

			case PHHAL_HW_CARDTYPE_FELICA_212:
			case PHHAL_HW_CARDTYPE_FELICA_424:

				if (pDataParams->wTargetMode != PH_OFF)
				{
					if(pDataParams->bActiveMode == PH_OFF)
					{
						switch (wTxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_212:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_PT_212;
								break;

							case PHHAL_HW_RF_DATARATE_424:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_PT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}

						switch (wRxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_212:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_PT_212;
								break;

							case PHHAL_HW_RF_DATARATE_424:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_PT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}
					}
					else
					{
						switch (wTxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_212:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_AT_212;
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bTxConfig = PHHAL_HW_NCX3321_RF_TX_NFC_AT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}

						switch (wRxDataRate)
						{
							case PHHAL_HW_RF_DATARATE_212:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_AT_212;
								break;
							case PHHAL_HW_RF_DATARATE_424:
								bRxConfig = PHHAL_HW_NCX3321_RF_RX_NFC_AT_424;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE:
								bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
						}
					}
				}
				else
				{
					switch (wTxDataRate)
					{
						case PHHAL_HW_RF_DATARATE_212:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_FELICA_212;
							break;

						case PHHAL_HW_RF_DATARATE_424:
							bTxConfig = PHHAL_HW_NCX3321_RF_TX_FELICA_424;
							break;

						case PHHAL_HW_RF_DATARATE_NO_CHANGE:
							bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
							break;

						default:
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					}

					switch (wRxDataRate)
					{
						case PHHAL_HW_RF_DATARATE_212:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_FELICA_212;
							break;

						case PHHAL_HW_RF_DATARATE_424:
							bRxConfig = PHHAL_HW_NCX3321_RF_RX_FELICA_424;
							break;

						case PHHAL_HW_RF_DATARATE_NO_CHANGE:
							bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
							break;

						default:
							return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					}

				}
				break;

			case PHHAL_HW_CARDTYPE_ISO15693:
				switch (wTxDataRate)
				{
					case PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4:
						bTxConfig = PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK10;
						break;

					case PHHAL_HW_RF_DATARATE_NO_CHANGE:
						bTxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
						break;

					default:
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}

				switch (wRxDataRate)
				{
					case PHHAL_HW_RF_RX_DATARATE_LOW:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO15693_6P6_SC;
						break;

					case PHHAL_HW_RF_RX_DATARATE_HIGH:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO15693_26_SC;
						break;

					case PHHAL_HW_RF_RX_DATARATE_FAST_HIGH:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO15693_53_SC;
						break;

					case PHHAL_HW_RF_DATARATE_106:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO15693_106;
						break;

					case PHHAL_HW_RF_DATARATE_212:
						bRxConfig = PHHAL_HW_NCX3321_RF_RX_ISO15693_212;
						break;

					case PHHAL_HW_RF_RX_DATARATE_FAST_LOW:
						return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);

					case PHHAL_HW_RF_DATARATE_NO_CHANGE:
						bRxConfig = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX;
						break;

					default:
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}
				break;
			default:
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			if(!((PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX != bTxConfig) || (PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX != bRxConfig)))
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Instr_LoadRfConfiguration(
				pDataParams,
				(uint8) bTxConfig,
				(uint8) bRxConfig ));
			break;
	}

	if(statusTmp == PH_ERR_SUCCESS)
	{
		/* If Datarate is changed, then Update Data-rate in shadow for parity setting */
		if(wTxDataRate != PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX)
		{
			pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXDATARATE_FRAMING] = wTxDataRate;
		}
		if(wRxDataRate != PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX)
		{
			pDataParams->wCfgShadow[PHHAL_HW_CONFIG_RXDATARATE_FRAMING] = wRxDataRate;
		}
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTxDataRateFraming(
	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wConfig,
	VAR(uint16, ANFCRL_VAR) wValue)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFraming = 0U;
  VAR(phStatus_t, ANFCRL_VAR) statusTmp = PH_ERR_SUCCESS;

	/* Update the framing, based on the Higher byte */
	wFraming = wValue & PHHAL_HW_RF_FRAMING_OPTION_MASK;
	wFraming = wFraming >> 0x08U;
	switch(bSetTxState)
	{
		case PHHAL_HW_INT_STATE_IDLE:
			if ((pDataParams->wCfgShadow[wConfig] & PHHAL_HW_RF_DATARATE_OPTION_MASK) != (wValue & PHHAL_HW_RF_DATARATE_OPTION_MASK))
			{
				if((wFraming != PHHAL_HW_CARDTYPE_CURRENT) && (wFraming != pDataParams->bCardType))
				{
					if((wValue & PHHAL_HW_RF_FRAMING_OPTION_MASK) != PHHAL_HW_RF_TYPE_ACTIVE_FRAMING)
					{
						pDataParams->bCardType = (uint8)wFraming;
					}
				}
				bSetTxState = PHHAL_HW_INT_STATE_CMD1;
			}
			else
			{
				return PH_ERR_SUCCESS;
			}
			/*no break*/

		case PHHAL_HW_INT_STATE_CMD1:

			if(pDataParams->bCardType != PHHAL_HW_CARDTYPE_ISO15693)
			{
				/* Evaluate hardware settings */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetCardMode(
					pDataParams,
					(wValue & PHHAL_HW_RF_DATARATE_OPTION_MASK),
					PHHAL_HW_RF_DATARATE_NO_CHANGE,
					pDataParams->wCfgShadow[PHHAL_HW_CONFIG_SUBCARRIER]));
				PH_BREAK_ON_FAILURE(statusTmp);
				break;
			}
			else
			{
				/* clear the 15693 datarate mask */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask( pDataParams, SYSTEM_CONFIG, ~((uint32)SYSTEM_CONFIG_15693_CHANGE_DATARATE_MASK)));
				PH_BREAK_ON_FAILURE(statusTmp);
				bSetTxState = PHHAL_HW_INT_STATE_CMD2;
			}
			return PH_STATUS_INPROCESS;
		case PHHAL_HW_INT_STATE_CMD2:
			/* Update the Baudrate based on the lower byte */
			wValue = wValue & PHHAL_HW_RF_DATARATE_OPTION_MASK;

			if(wValue == PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT(statusTmp,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask( pDataParams, SYSTEM_CONFIG, (uint32) (PHHAL_HW_15693_26KBPS)));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else if(wValue == PHHAL_HW_RF_I15693_53KBPS_DATARATE)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT(statusTmp,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask( pDataParams, SYSTEM_CONFIG, (uint32) (PHHAL_HW_15693_53KBPS)));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else if(wValue == PHHAL_HW_RF_DATARATE_106)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT(statusTmp,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask( pDataParams, SYSTEM_CONFIG, (uint32) (PHHAL_HW_15693_106KBPS)));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else if(wValue == PHHAL_HW_RF_DATARATE_212)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT(statusTmp,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask( pDataParams, SYSTEM_CONFIG, (uint32) (PHHAL_HW_15693_212KBPS)));
				PH_BREAK_ON_FAILURE(statusTmp);
			}
			else
			{
				/* To avoid the warning */
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);    /* return the invalid parameter */
			}
			break;
	}
	if(statusTmp == PH_ERR_SUCCESS){
		/* Write config data into shadow */
		pDataParams->wCfgShadow[wConfig] = (wValue | (wFraming << 0x08U)) ;
	}
	bSetTxState = PHHAL_HW_INT_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetRxDataRateFraming(
		P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint16, ANFCRL_VAR) wConfig,
		VAR(uint16, ANFCRL_VAR) wValue)
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFraming = 0U;
	VAR(phStatus_t, ANFCRL_VAR) statusTmp = PH_ERR_SUCCESS;

	if ((pDataParams->wCfgShadow[wConfig] & PHHAL_HW_RF_DATARATE_OPTION_MASK) != (wValue & PHHAL_HW_RF_DATARATE_OPTION_MASK))
	{
		/* Update the framing, based on the Higher byte */
		wFraming = wValue & PHHAL_HW_RF_FRAMING_OPTION_MASK;
		wFraming = wFraming >> 0x08U;

		if((wFraming != PHHAL_HW_CARDTYPE_CURRENT) && (wFraming != pDataParams->bCardType))
		{
			if((wValue & PHHAL_HW_RF_FRAMING_OPTION_MASK) != PHHAL_HW_RF_TYPE_ACTIVE_FRAMING)
			{
				pDataParams->bCardType = (uint8)wFraming;
			}
		}

		/* Update the Baudrate based on the lower byte */
		wValue = wValue & PHHAL_HW_RF_DATARATE_OPTION_MASK;

		/* Evaluate hardware settings */
		PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetCardMode(
			pDataParams,
			PHHAL_HW_RF_DATARATE_NO_CHANGE,
			wValue,
			pDataParams->wCfgShadow[PHHAL_HW_CONFIG_SUBCARRIER]));
		PH_CHECK_SUCCESS(statusTmp);
		/* Write config data into shadow */
		pDataParams->wCfgShadow[wConfig] = (wValue | (wFraming << 0x08U));
	}
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetMinFdt(
                    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wValue
										)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTimer = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxRate = 0U;
	static VAR(uint8, ANFCRL_VAR) bSetMinFdtState = 0U;

	switch(bSetMinFdtState)
	{
		case 0U:
			if (wValue == PH_ON)
			{
				/* Get current timeout value */
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_GetConfig(
					pDataParams,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
					&wTimer));

				/* Backup current value */
				pDataParams->dwFdtPc = wTimer;

				/* Get current data rate */
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_GetConfig(
					pDataParams,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING,
					&wTxRate));

				/* Select timeout value based on data rate */
				switch(wTxRate)
				{
					case PHHAL_HW_RF_DATARATE_106:
						wTimer = PHHAL_HW_MINFDT_106_US;
						break;

					case PHHAL_HW_RF_DATARATE_212:
						wTimer = PHHAL_HW_MINFDT_212_US;
						break;

					case PHHAL_HW_RF_DATARATE_424:
						wTimer = PHHAL_HW_MINFDT_424_US;
						break;

					case PHHAL_HW_RF_DATARATE_848:
						wTimer = PHHAL_HW_MINFDT_848_US;
						break;

					default:
						break;
				}
				bSetMinFdtState = 1U;
				return PH_STATUS_INPROCESS;
			}
			else if (wValue == PH_OFF)
			{
				bSetMinFdtState = 2U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* If option is not #PH_OFF or #PH_ON */
				statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			break;
		case 1U:
			/* Set timeout value */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(
				pDataParams,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_US,
				wTimer));
			break;
		case 2U:
			/* Restore the timeout value */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(
				pDataParams,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS,
				pDataParams->dwFdtPc));
			break;
	}

	wTimer = 0U;
	bSetMinFdtState = 0U;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetDigiDelay(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bIsTimeout, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDelayUs)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataRate = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0;
	wDataRate = pDataParams->wCfgShadow[PHHAL_HW_CONFIG_RXDATARATE_FRAMING] & PHHAL_HW_RF_DATARATE_OPTION_MASK;

	bIndex = pDataParams->bCardType - 1U;

	switch (pDataParams->bCardType)
	{
		case PHHAL_HW_CARDTYPE_ISO14443A:
		case PHHAL_HW_CARDTYPE_ISO14443B:
			*pDelayUs = gkphhalHw_Ncx3321_DigiDelays_Us[bIndex][wDataRate];
			/* In a timeout case we have to add an additional delay */
			if (bIsTimeout != PH_OFF)
			{
				*pDelayUs = *pDelayUs + PHHAL_HW_NCX3321_I14443_ADD_DELAY_US;
			}
			break;
		case PHHAL_HW_CARDTYPE_FELICA_212:
		case PHHAL_HW_CARDTYPE_FELICA_424:
			bIndex = PHHAL_HW_CARDTYPE_FELICA_212 - 1U;
			*pDelayUs = gkphhalHw_Ncx3321_DigiDelays_Us[bIndex][wDataRate];
			break;
		case PHHAL_HW_CARDTYPE_ISO15693:
			*pDelayUs = gkphhalHw_Ncx3321_DigiDelays_Us[bIndex][wDataRate
					- PHHAL_HW_RF_RX_DATARATE_LOW];
			/* In a timeout case we have to add an additional delay */
			if (bIsTimeout != PH_OFF)
			{
				if (wDataRate == PHHAL_HW_RF_RX_DATARATE_HIGH)
				{
					*pDelayUs = *pDelayUs + PHHAL_HW_NCX3321_I15693_ADD_DELAY_US;
				}
				else
				{
					*pDelayUs = *pDelayUs + (PHHAL_HW_NCX3321_I15693_ADD_DELAY_US >> 1U);
				}
			}
			break;

		case PHHAL_HW_CARDTYPE_UNKNOWN:
		{
			/*
			 * For the case when apply protocol settings is not done.
			 */
			*pDelayUs = 0;
			break;
		}
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTmo(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wTimeout,
                  VAR(uint8, ANFCRL_VAR) bUnit
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM wPrescaler = 0U;
  static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwLoadValue = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wUDigitalDelay;

  switch(bSetTmoState)
  	{
  	  case PHHAL_HW_INT_STATE_IDLE:
		  wUDigitalDelay = 0U;
			/* Parameter check */
			if ((bUnit != PHHAL_HW_TIME_MICROSECONDS) && (bUnit != PHHAL_HW_TIME_MILLISECONDS))
			{
                wPrescaler = 0U;
                dwLoadValue = 0U;
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			if (wTimeout == 0U)
			{
                wPrescaler = 0U;
                dwLoadValue = 0U;
				return PH_ERR_SUCCESS;
			}

			if (bUnit == PHHAL_HW_TIME_MICROSECONDS)
			{
				PH_CHECK_SUCCESS_FCT(statusTmp,phhalHw_Ncx3321_Int_GetDigiDelay(pDataParams,PH_ON,&wUDigitalDelay));
				/* here wTimeout will be in uS */
				wPrescaler = 0x00U;
				/*Reducing the division by 2 digits to retain the 2 digit decimal places which were getting wiped out*/
				dwLoadValue = (uint32) ( PHHAL_HW_NCX3321_MAX_FREQ / (PHHAL_HW_NCX3321_CONVERSION_US_SEC / 100U));
				/*Restoring the division done in the earlier step*/
				dwLoadValue = (uint32) ((((uint32)wTimeout + (uint32)wUDigitalDelay) * dwLoadValue) / 100U);
			}
			else
			{
				wPrescaler = 0x3CU;
				if (wTimeout <= PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS)
				{
					dwLoadValue =  (uint32)((uint32)wTimeout * ( PHHAL_HW_NCX3321_MIN_FREQ / PHHAL_HW_NCX3321_CONVERSION_MS_SEC));
				}
				else
				{
                    wPrescaler = 0U;
                    dwLoadValue = 0U;
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PARAMETER_OVERFLOW, PH_COMP_HAL);
				}
			}
			bSetTmoState = PHHAL_HW_INT_STATE_CMD1;
			/*no break*/
  	  case PHHAL_HW_INT_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_TimerStart(
							pDataParams,
							CLIF_TIMER1_CONFIG,
							CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK,
							CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK,
							wPrescaler,
							dwLoadValue));
			break;
  	}
  	bSetTmoState = PHHAL_HW_INT_STATE_IDLE;
    wPrescaler = 0U;
    dwLoadValue = 0U;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_Retrieve_Data(
                      P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
											)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint16, ANFCRL_VAR) wTmpRxBufferLen = 0U;
    static VAR(uint16, ANFCRL_VAR) wTmpRxBufferSize = 0U;
    static VAR(uint16, ANFCRL_VAR) wNumByteReceived = 0U;
    VAR(uint32, ANFCRL_VAR) dwValue = 0U;
    VAR(uint32, ANFCRL_VAR) dwColPos = 0U;
    VAR(uint32, ANFCRL_VAR) dwTemp = 0U;
    static VAR(uint32, ANFCRL_VAR) dwRx_Status = 0U;
    static VAR(uint32, ANFCRL_VAR) dwRf_Status = 0U;
    static VAR(uint8, ANFCRL_VAR) bBackup = 0U;
    static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer = NULL;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData = NULL;

    /* NULL pointer should be avoided. */
	if ((ppRxBuffer == NULL))
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
	}
	pRxData = *ppRxBuffer;

	switch(pDataParams->HwEventObj.bEventState)
	{
		case PH_TOOLS_EVENT_IDLE:
			/* Dereference of NULL pointer should be avoided. */
			if(*ppRxBuffer == NULL)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			dwRx_Status = (uint32)pRxData[0];
			dwRx_Status |= (uint32)pRxData[1] << 8U;
			dwRx_Status |= (uint32)pRxData[2] << 16U;
			dwRx_Status |= (uint32)pRxData[3] << 24U;

			dwRf_Status = (uint32)pRxData[4];
			dwRf_Status |= (uint32)pRxData[5] << 8U;
			dwRf_Status |= (uint32)pRxData[6] << 16U;
			dwRf_Status |= (uint32)pRxData[7] << 24U;

			/* Success; check data received */
			pDataParams->wRxBufLen = 0U;

			(void)phhalHw_Ncx3321_Int_GetRxBuffer(
					pDataParams,
					&pTmpRxBuffer,
					&wTmpRxBufferLen,
					&wTmpRxBufferSize);

			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				bBackup = pTmpRxBuffer[0];
			}
			if(pDataParams->bRxMultiple == PH_ON)
			{
				wNumByteReceived = (uint16)((dwRx_Status & CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_MASK) |
					(((dwRx_Status & CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_MASK) >>
							CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_POS) * 32U));
			}
			else
			{
				wNumByteReceived = (uint16)(dwRx_Status & CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_MASK);
			}

			/* Check if the buffer size is sufficient*/
			if (wTmpRxBufferSize < wNumByteReceived)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_HAL);
			}
			if(wNumByteReceived == 0U)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING:
		case PH_TOOLS_EVENT_OCCUR:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_RetrieveRFData(pDataParams, ppRxBuffer, pRxLength));
			PH_CHECK_SUCCESS(status);
            /* Dereference of NULL pointer should be avoided. */
            if (*ppRxBuffer == NULL)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
            }
			if(*pRxLength != wNumByteReceived)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
			}
			break;
	}

	/* Extract RX last bits */
	dwTemp = dwRx_Status & CLIF_RX_STATUS_RX_NUM_LAST_BITS_MASK;
	dwTemp = dwTemp >> CLIF_RX_STATUS_RX_NUM_LAST_BITS_POS;

	/* Set RX last bits */
	pDataParams->wAdditionalInfo = (uint16)dwTemp;

	if (0U != (dwRf_Status & CLIF_RX_STATUS_ERROR_RX_COLLISION_DETECTED_MASK))
	{
		if ((wNumByteReceived == 0U) && ((dwRx_Status & CLIF_RX_STATUS_RX_COLL_POS_MASK) == 0U))
		{
			/* No data received */
			status = PH_ERR_IO_TIMEOUT;
		}
		else
		{
			status = PH_ERR_COLLISION_ERROR;

			/* Retrieve collision position */
			dwColPos = dwRx_Status & CLIF_RX_STATUS_RX_COLL_POS_MASK;
			dwColPos = dwColPos >> CLIF_RX_STATUS_RX_COLL_POS_POS;

			/* Restore RX buffer size */
			wTmpRxBufferSize = wTmpRxBufferSize + wNumByteReceived;
			if (dwColPos > wTmpRxBufferSize)
			{
				wNumByteReceived = wTmpRxBufferSize;
				status = PH_ERR_BUFFER_OVERFLOW;
			}
			else
			{
				wNumByteReceived = ((uint16)dwColPos >> 3U);
			}

			/* Extracting valid bits from Collision position */
			if(dwColPos >= 8U)
			{
				dwValue = dwColPos % 8U ;
			}
			else
			{
				dwValue = dwColPos;
			}

			if (0U != (dwValue))
			{
				/* If it is non zero, some valid bits are received */
				if (wNumByteReceived == wTmpRxBufferSize)
				{
					status = PH_ERR_BUFFER_OVERFLOW;
				}
				else
				{
					++wNumByteReceived;
				}
			}

			/* Store valid bits of last byte */
			pDataParams->wAdditionalInfo = (uint16)dwValue;
		}
	}
	else if (0U != (dwRf_Status & CLIF_RX_STATUS_ERROR_RX_DATA_INTEGRITY_ERROR_MASK))
	{
		status = PH_ERR_INTEGRITY_ERROR;
	}
	else if (dwTemp != 0x00U)
	{
		/* Set incomplete byte status if applicable */
		status =  PH_ERR_SUCCESS_INCOMPLETE_BYTE;
	}
	else if (0U != (dwRf_Status & CLIF_RX_STATUS_ERROR_RX_PROTOCOL_ERROR_MASK))
	{
		status = PH_ERR_PROTOCOL_ERROR;
	}
	else
	{
		/* For QAC */
	}

	if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON) && (wNumByteReceived != 0U))
	{
		if(*ppRxBuffer[0] != 0xF0U)
		{
			return PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
		}
		pTmpRxBuffer[0] = bBackup;
		(*ppRxBuffer)++;
		wNumByteReceived--;
	}
	/* Store received data length in dataparams */
	pDataParams->wRxBufLen = pDataParams->wRxBufStartPos + wNumByteReceived;

	*ppRxBuffer = pDataParams->pRxBuffer;

	if (pRxLength != NULL)
	{
		*pRxLength = pDataParams->wRxBufLen;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_ClearNSetRegFields(
		P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint8, ANFCRL_VAR) bRegister,
		VAR(uint32, ANFCRL_VAR) dwMask,
		VAR(uint32, ANFCRL_VAR) dwPos,
		VAR(uint16, ANFCRL_VAR) wValue)
{
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF wRegTypeValueSets[12] = {0};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSizeOfRegTypeValueSets = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTemp = 0U;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	dwTemp = (uint32) ~(dwMask);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = bRegister;
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

	dwTemp = ((uint32)wValue << dwPos) & dwMask;
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = bRegister;
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
	wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

	PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams,  wRegTypeValueSets, wSizeOfRegTypeValueSets));
	PH_CHECK_SUCCESS(status);

	return PH_ERR_SUCCESS;
}

/**
 * For NCX3321, In ISR read part of response and post
 * appropriate Event depending upon the response
 *
 *  aISRReadBuf[0] = SPI header
 *  aISRReadBuf[1] = Type
 *  aISRReadBuf[2] = Length MSB
 *  aISRReadBuf[3] = Length
 *  aISRReadBuf[4] = Value[0]
 */
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_ISR_Callback(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(uint32, ANFCRL_VAR) dwEventStatusReg = 0x0U;
  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pNcx3321DataParams = NULL;
	pNcx3321DataParams = (phhalHw_Ncx3321_DataParams_t *) pDataParams;

	if( pNcx3321DataParams->sIrqResp.pHandlerModeBuffPtr[1] == PH_NCX3321_EVT_RSP )
	{
		dwEventStatusReg = (uint32) pNcx3321DataParams->sIrqResp.pIsrEvtBuffPtr[4];
		dwEventStatusReg |= ((uint32) pNcx3321DataParams->sIrqResp.pIsrEvtBuffPtr[5]) << 8U ;
		dwEventStatusReg |= ((uint32) pNcx3321DataParams->sIrqResp.pIsrEvtBuffPtr[6]) << 16U;
		dwEventStatusReg |= ((uint32) pNcx3321DataParams->sIrqResp.pIsrEvtBuffPtr[7]) << 24U;

		if ((dwEventStatusReg & (PH_NCX3321_EVT_TX_OVERCURRENT_ERROR | PH_NCX3321_EVT_CTS)) == 0U)
		{
			/* Received Event can be processed by RdLib */
			(void)phTools_EventPost(
				&((phhalHw_Ncx3321_DataParams_t *)(pDataParams))->HwEventObj,
				E_EVENT_OPT_POST_ISR,
				E_PHHAL_HW_EVT_SIG,
				NULL);
		}
	}
	else
	{
		/*Parse the response and accordingly send event*/
		(void)phTools_EventPost(
			&((phhalHw_Ncx3321_DataParams_t *)(pDataParams))->HwEventObj,
			E_EVENT_OPT_POST_ISR,
			E_EVENT_RF,
			NULL);
	}
}

FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_GuardTimeCallBck(void)
{
	if(xEventHandle != NULL)
	{
		(void)phTools_EventPost(
			xEventHandle,
			E_EVENT_OPT_POST_ISR,
			E_EVENT_GT_EXP,
			NULL);
	}
}

#ifdef PHDRIVER_SOFT_SSEL
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_WriteSSEL(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams,
                VAR(uint8, ANFCRL_VAR) bValue
								)
{
	if (((phbalReg_Type_t *)pBalDataParams)->bBalType == PHBAL_REG_TYPE_SPI)
	{
		phDriver_PinWrite(PHDRIVER_PIN_SSEL, bValue);
	}
}
#endif /* PHDRIVER_SOFT_SSEL */

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_EventWait(
  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint32, ANFCRL_VAR) dwExpectedEvents,
  VAR(uint32, ANFCRL_VAR) dwEventTimeOut,
  VAR(uint8, ANFCRL_VAR) bPayLoadPresent,
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventReceived)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pEvtPayload = NULL;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEvtReceived = 0x0U;

	PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_WaitForEvent(
		pDataParams,
		dwExpectedEvents,
		dwEventTimeOut,
		bPayLoadPresent,
		&dwEvtReceived,
		&pEvtPayload));
	if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
	{
		if(pEvtPayload != NULL)
		{
			pDataParams->dwEventStatus = (uint32) pEvtPayload[0];
			pDataParams->dwEventStatus |= ((uint32) pEvtPayload[1]) << 8U ;
			pDataParams->dwEventStatus |= ((uint32) pEvtPayload[2]) << 16U;
			pDataParams->dwEventStatus |= ((uint32) pEvtPayload[3]) << 24U;

			if((dwEvtReceived & PH_NCX3321_EVT_GENERAL_ERROR) != 0U)
			{
				pDataParams->dwGenError = (uint32) pEvtPayload[4];
				pDataParams->dwGenError |= ((uint32) pEvtPayload[5]) << 8U ;
				pDataParams->dwGenError |= ((uint32) pEvtPayload[6]) << 16U;
				pDataParams->dwGenError |= ((uint32) pEvtPayload[7]) << 24U;

				status = PH_ERR_INTERNAL_ERROR;
			}
		}
	}
	else
	{
		if((status & PH_ERR_MASK) == PH_EVENT_TIMEOUT)
		{
			status = PH_ERR_IO_TIMEOUT;
		}
	}

	if(dwEventReceived != NULL)
	{
		* dwEventReceived = dwEvtReceived;
	}
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
