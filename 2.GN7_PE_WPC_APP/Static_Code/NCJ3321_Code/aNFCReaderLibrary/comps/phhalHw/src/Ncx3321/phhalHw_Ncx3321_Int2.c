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
*   @file    phhalHw_Ncx3321_Int2.c
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
#include <phhalHw2.h>
#include <ph_RefDefs2.h>
#include <ph_Status2.h>

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
#include "phhalHw_Ncx3321_InstrMngr2.h"
#include "phhalHw_Ncx3321_Wait2.h"
#include "phhalHw_Ncx3321_Int2.h"
#include <phhalHw_Ncx3321_Reg2.h>
#include <phhalHw_Ncx3321_Instr2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Int2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INT_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INT_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INT_VENDOR_ID_C2 != PHHALHW_NCX3321_INT_VENDOR_ID2)
    #error "phhalHw_Ncx3321_Int2.c and phhalHw_Ncx3321_Int.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Int2.c and phhalHw_Ncx3321_Int.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321_Int.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_INT_SW_MAJOR_VERSION_C2 != PHHALHW_NCX3321_INT_SW_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_INT_SW_MINOR_VERSION_C2 != PHHALHW_NCX3321_INT_SW_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_INT_SW_PATCH_VERSION_C2 != PHHALHW_NCX3321_INT_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw_Ncx3321_Int2.c and phhalHw_Ncx3321_Int.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX33212
#define PHHAL_HW_15693_26KBPS2           (0x00000000)
#define PHHAL_HW_15693_53KBPS2           (0x00000020)
#define PHHAL_HW_15693_106KBPS2          (0x00000040)
#define PHHAL_HW_15693_212KBPS2          (0x00000060)

#define PHHAL_HW_INT_STATE_IDLE2	0u
#define PHHAL_HW_INT_STATE_CMD12	1u
#define PHHAL_HW_INT_STATE_CMD22	2u
#define PHHAL_HW_INT_STATE_CMD32	3u

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Digital delay for all protocols and speeds in microseconds */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 gkphhalHw_Ncx3321_DigiDelays_Us2[][4] =
{
/* PHHAL_HW_CARDTYPE_ISO14443A2 */
{/* 106KBaud */17, /* 212KBaud */49, /* 424KBaud */45, /* 848KBaud */42 },

/* PHHAL_HW_CARDTYPE_ISO14443B2 */
{/* 106KBaud */182, /* 212KBaud */91, /* 424KBaud */46, /* 848KBaud */23 },

/* PHHAL_HW_CARDTYPE_FELICA_2122 */
{/* N/A */0, /* 212KBaud */322, /* 424KBaud */165, /* N/A */0 },

/* PHHAL_HW_CARDTYPE_ISO156932 */
{/* LOW */0, /* HIGH */193, /* FAST_LOW */0, /* FAST_HIGH */89 }};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) bTimerStartState2 = PHHAL_HW_INT_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) bSetTxState2 = PHHAL_HW_INT_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) bSetTmoState2 = PHHAL_HW_INT_STATE_IDLE2;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_ResetState2(void) 
{
    bTimerStartState2 = PHHAL_HW_INT_STATE_IDLE2;
    bSetTxState2 = PHHAL_HW_INT_STATE_IDLE2;
    bSetTmoState2 = PHHAL_HW_INT_STATE_IDLE2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetTxBuffer2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferLen2,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferSize2
											)
{
	/* We need to watch that we do not overwrite content below the RxStartPos though. */
	if ((&(pDataParams2->pTxBuffer2)[1]) == (pDataParams2->pRxBuffer2))
	{
		(*pTxBuffer2) = &(pDataParams2->pTxBuffer2[pDataParams2->wRxBufStartPos2]);
		(*pTxBufferSize2) = (pDataParams2->wTxBufSize2) - (pDataParams2->wRxBufStartPos2);
	}
	/* Else just return the actual Buffer. */
	else
	{
		*pTxBuffer2 = pDataParams2->pTxBuffer2;
		*pTxBufferSize2 = pDataParams2->wTxBufSize2;
	}

	/* Return stored length. */
	*pTxBufferLen2 = pDataParams2->wTxBufLen2;

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetRxBuffer2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferLen2,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferSize2
											)
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bOffset2 = 0U;

	if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
	{
		bOffset2 = 1U;
	}
	/* Update out parameters */
	*pRxBuffer2 = &pDataParams2->pRxBuffer2[pDataParams2->wRxBufStartPos2 - bOffset2];
	*pRxBufferSize2 = pDataParams2->wRxBufSize2 - pDataParams2->wRxBufStartPos2 - bOffset2;
	*pRxBufferLen2 = pDataParams2->wRxBufLen2;

	return PH_ERR_SUCCESS2;
}

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_Reset2(void)
{
	static VAR(uint8, ANFCRL_VAR) bResetState2 = 0U;
	static VAR(uint32, ANFCRL_VAR) bResetDelay2 = 0U;
	VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;

	switch (bResetState2)
	{
		case 0u:
			/* Send the reset pulse to FE to reset. */
			phDriver_PinWrite2(PHDRIVER_PIN_RESET2, RESET_POWERDOWN_LEVEL2);

			// bResetDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			bResetState2 = 1U;
			return PH_STATUS_INPROCESS2;

		case 1u:
			phDriver_PinWrite2(PHDRIVER_PIN_RESET2, RESET_POWERUP_LEVEL2);

			// bResetDelay2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
			bResetState2 = 2U;
			return PH_STATUS_INPROCESS2;

		case 2u:
			/* Do Nothing */
			break;
		default:
			bResetState2 = 0U;
			return PH_ERR_INTERNAL_ERROR2;
	}
	bResetState2 = 0U;
	return PH_ERR_SUCCESS2;
}

#else
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_Reset2(void)
{
	static VAR(uint8, ANFCRL_VAR) bResetState2 = 0U;
	static VAR(uint32, ANFCRL_VAR) bResetDelay2 = 0U;
	VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;

	switch (bResetState2)
	{
		case 0u:
#ifndef AUTOSAR_VER
			/* Send the reset pulse to FE to reset. */
			phDriver_PinWrite2(PHDRIVER_PIN_RESET2, RESET_POWERDOWN_LEVEL2);
#else
			phDriver_PinWrite2(ANFCLIB_PCConfig2.AnfcRL_DioChannelRST, RESET_POWERDOWN_LEVEL2);
#endif

			bResetDelay2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
			bResetState2 = 1U;
			return PH_STATUS_INPROCESS2;
			/* No break */
		case 1u:
			dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, bResetDelay2);

			/* Check for timer overflow, abort if timer overflow happens */
			if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
			{
				bResetState2 = 0U;
				return PH_ERR_ABORTED2;
			}
			else
			{
				/* Delay after power down - 5ms*/
				if (dwElapsedTime2 < PHHAL_HW_NCX3321_RESET_DELAY_MICRO_SECS2)
				{
					return PH_STATUS_INPROCESS2;
				}
				else
				{
#ifndef AUTOSAR_VER
					phDriver_PinWrite2(PHDRIVER_PIN_RESET2, RESET_POWERUP_LEVEL2);
#else
					phDriver_PinWrite2(ANFCLIB_PCConfig2.AnfcRL_DioChannelRST, RESET_POWERUP_LEVEL2);
#endif

					bResetDelay2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
					bResetState2 = 2U;
				}
			}
			return PH_STATUS_INPROCESS2;
			/* No break */
		case 2u:
			dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, bResetDelay2);
			/* Check for timer overflow, abort if timer overflow happens */
			if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
			{
				bResetState2 = 0U;
				return PH_ERR_ABORTED2;
			}
			else
			{
				/* Delay after power up - 1ms*/
				if (dwElapsedTime2 < PHHAL_HW_NCX3321_RESET_GUARDTIME_MICRO_SECS2)
				{
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					/* Do nothing */
				}
			}
			break;
		default:
			bResetState2 = 0U;
			return PH_ERR_INTERNAL_ERROR2;
			/* No break */
	}
	bResetState2 = 0U;
	return PH_ERR_SUCCESS2;
}

#endif

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_TimerStart2(
                    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint8, ANFCRL_VAR) bTimer2,
                    VAR(uint32, ANFCRL_VAR) dwStartCond2,
                    VAR(uint32, ANFCRL_VAR) dwStopCond2,
                    VAR(uint32, ANFCRL_VAR) wPrescaler2,
                    VAR(uint32, ANFCRL_VAR) dwLoadValue2
										)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTmrConfigReg2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTmrRelaodReg2 = 0U;
	static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEnableMask2 = 0U;
	static VAR(uint32, ANFCRL_VAR) dwStartNowMask2 = 0U;

	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTemp2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 wRegTypeValueSets2[18] = {0U};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSizeOfRegTypeValueSets2 = 0U;
	VAR(phTools_EventBits_t2, ANFCRL_VAR) PH_MEMLOC_REM2 tReceivedEvents2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pEvtPayload2 = NULL;

	switch(bTimerStartState2)
	{
		case PHHAL_HW_INT_STATE_IDLE2:
			/* Populate the timer configure and reload registers */

			switch(bTimer2)
			{
				case CLIF_TIMER0_CONFIG2:
					bTmrConfigReg2 = CLIF_TIMER0_CONFIG2;
					bTmrRelaodReg2 = CLIF_TIMER0_RELOAD2;
					dwEnableMask2 = CLIF_TIMER0_CONFIG_T0_ENABLE_MASK2;
					dwStartNowMask2 = CLIF_TIMER0_CONFIG_T0_START_NOW_MASK2;
					break;

				case CLIF_TIMER1_CONFIG2:
					bTmrConfigReg2 = CLIF_TIMER1_CONFIG2;
					bTmrRelaodReg2 = CLIF_TIMER1_RELOAD2;
					dwEnableMask2 = CLIF_TIMER1_CONFIG_T1_ENABLE_MASK2;
					dwStartNowMask2 = CLIF_TIMER1_CONFIG_T1_START_NOW_MASK2;
					break;

				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			if((dwStartCond2 & dwStartNowMask2) == dwStartNowMask2)
			{
				(void)phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2, E_PHHAL_HW_EVT_SIG2, NULL);
			}

			bTimerStartState2 = PHHAL_HW_INT_STATE_CMD12;
			return PH_STATUS_INPROCESS2;
			/* No break */

		case PHHAL_HW_INT_STATE_CMD12:

			/*write 0 to stop timer*/
			wSizeOfRegTypeValueSets2 = 0U;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = bTmrConfigReg2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = 0x00U;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = 0x00U;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = 0x00U;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = 0x00U;

			/*load the timer  reload value*/
			dwTemp2 = (dwLoadValue2 & TMR_RELOAD_VALUE_MASK2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = bTmrRelaodReg2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

			/* Timer MODE_SEL is defined by ePrescaler, 0x01U enables the timer */
			dwTemp2 = (dwStartCond2 | dwStopCond2 | wPrescaler2 | dwEnableMask2 );
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = bTmrConfigReg2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2( pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
			PH_BREAK_ON_FAILURE2(status2);
			/* If the timer is started immediately, then wait for Interrupt (Timer Event) from FW */
			if((dwStartCond2 & dwStartNowMask2) == dwStartNowMask2)
			{
				bTimerStartState2 = PHHAL_HW_INT_STATE_CMD22;
			}
			else
			{
				break;
			}
			return PH_STATUS_INPROCESS2;
			/*no break*/
		case PHHAL_HW_INT_STATE_CMD22:
			/*Wait for Timer event*/
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_WaitForEvent2(
				pDataParams2,
				PH_NCX3321_EVT_TIMER2,
				PHHAL_HW_MAX_DELAY2,
				TRUE,
				&tReceivedEvents2,
				&pEvtPayload2));
			break;
	}

	/* Reset static variables */
	bTimerStartState2 = PHHAL_HW_INT_STATE_IDLE2;
	bTmrConfigReg2 = 0U;
	bTmrRelaodReg2 = 0U;
	dwEnableMask2 = 0U;
	dwStartNowMask2 = 0U;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig_Int2(
                    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint16, ANFCRL_VAR) wConfig2,
                    VAR(uint16, ANFCRL_VAR) wValue2
										)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwValue2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 wRegTypeValueSets2[30] =
  { 0 };
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSizeOfRegTypeValueSets2 = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTemp2 = 0U;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwReqAEx2 = 0U;
  VAR(double, ANFCRL_VAR) PH_MEMLOC_REM2 fTime2 = 0.0;	/* NIDEC_PORTING */

	switch (wConfig2)
	{
		case PHHAL_HW_CONFIG_PARITY2:

			/* Tx-Parity,  Rx-Parity is OFF */
			if (wValue2 == PH_OFF2)
			{
				dwValue2 = (uint32) ~(uint32) CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TX_FRAME_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				dwValue2 = (uint32) ~(uint32) CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_RX_PROTOCOL_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				/* Turn ON Tx-Parity */
				dwValue2 = CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TX_FRAME_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				/* Turn ON Rx-Parity */
				dwValue2 = CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_RX_PROTOCOL_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}

			break;

		case PHHAL_HW_CONFIG_TXCRC2:

			if (wValue2 == PH_OFF2)
			{
				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2;

				/* Perform write */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, CLIF_CRC_TX_CONFIG2, dwValue2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{

				wSizeOfRegTypeValueSets2 = 0U;

				/*Clear the Bits*/
				dwTemp2 =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;

		case PHHAL_HW_CONFIG_RXCRC2:

			if (wValue2 == PH_OFF2)
			{
				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, CLIF_CRC_RX_CONFIG2, dwValue2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{

				wSizeOfRegTypeValueSets2 = 0U;

				/*Clear the Bits */
				dwTemp2 =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);

			}
			break;
		case PHHAL_HW_CONFIG_ASK1002:
			/* TODO:
			 * Presently for ASK100/ASK10 is changed for ISO15693, loading will be
			 * done using the load_rf_config, But check whether can it be done to
			 * change a particular register itself to support this switching.
			 */
			if (PHHAL_HW_CARDTYPE_ISO156932 == pDataParams2->bCardType2)
			{
				/* switch off 100% ASK */
				do
				{
					if (wValue2 == PH_OFF2)
					{
						statusTmp2 = phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK102, 0xFF);
					}
					/* switch on 100% ASK */
					else
					{
						statusTmp2 = phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK1002, 0xFF);
					}
				}while(statusTmp2 == PH_STATUS_INPROCESS2);
			}
			break;

		case PHHAL_HW_CONFIG_RXWAIT_US2:
			/* Set Rx Wait(deaf) bits */
			dwValue2 = PHHAL_HW_NCX3321_TX_RX_PRESCALER2;
			dwTemp2 = wValue2;
			if (0U != dwTemp2)
			{
				fTime2 = (double) (((double) dwTemp2 * 13.56) / (double) (dwValue2));	/* NIDEC_PORTING */
				dwTemp2 = (uint32) fTime2;
				dwValue2 |= (uint32) dwTemp2 << CLIF_RX_WAIT_RX_WAIT_VALUE_POS2;
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_RX_WAIT2, dwValue2 ));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_RX_WAIT2, dwValue2 ));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2:
			if ((pDataParams2->wCfgShadow2[wConfig2] != wValue2) ||
				(pDataParams2->bTimeoutUnit2 != PHHAL_HW_TIME_MICROSECONDS2) ||
				(pDataParams2->bOpeMode2 != RD_LIB_MODE_EMVCO2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetTmo2(pDataParams2, wValue2, PHHAL_HW_TIME_MICROSECONDS2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
				pDataParams2->bTimeoutUnit2 = PHHAL_HW_TIME_MICROSECONDS2;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2:
			if ((pDataParams2->wCfgShadow2[wConfig2] != wValue2) ||
				(pDataParams2->bTimeoutUnit2 != PHHAL_HW_TIME_MILLISECONDS2) ||
				(pDataParams2->bOpeMode2 != RD_LIB_MODE_EMVCO2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetTmo2(pDataParams2, wValue2, PHHAL_HW_TIME_MILLISECONDS2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
				pDataParams2->bTimeoutUnit2 = PHHAL_HW_TIME_MILLISECONDS2;
			}
			break;
		case PHHAL_HW_CONFIG_TRXCRC2:
			if (wValue2 == PH_OFF2)
			{
				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				wSizeOfRegTypeValueSets2 = 0U;

				/*Clear the Bits*/
				dwTemp2 =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Clear the Bits */
				dwTemp2 =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;
		case PHHAL_HW_CONFIG_REQAEX2:
			dwValue2 = PHHAL_HW_NCX3321_TX_RX_PRESCALER2;
			dwReqAEx2 = 76U; /*This value is fixed and is the same as the value in state PHPAL_I14443P3A_REQAEX_CONFIG*/
			if (wValue2 == PH_OFF2)
			{
				fTime2 = (double) (((double) dwReqAEx2 * 13.56) / (double) (dwValue2));	/* NIDEC_PORTING */
				dwReqAEx2 = (uint32) fTime2;
				dwValue2 |= (uint32) dwReqAEx2 << CLIF_RX_WAIT_RX_WAIT_VALUE_POS2;

				/* Set Rx Wait(deaf) bits */
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_RX_WAIT2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				/* CRC calculator, your services are not required */
				dwValue2 = (uint32) ~(uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				wSizeOfRegTypeValueSets2 = 0U;
				/*Set Rx Wait(deaf) bits*/
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_RX_WAIT2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				/*Clear the Bits*/
				dwTemp2 =  ~((uint32)CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) (CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2);

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Clear the Bits */
				dwTemp2 =  ~((uint32)CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Set the new value  */
				dwTemp2 = (uint32) CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2;

				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_RX_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/*Send the array to the IC*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;

		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_HAL2);
	}

	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdReg2(
    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_INTERNAL_ERROR2;

    if (pDataParams2->bOpeMode2 != RD_LIB_MODE_FELICA2)
    {
        /* Clear FeliCa EMD Control Register */
        PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, FELICA_EMD_CONTROL2, (uint32)0x0U));
        PH_CHECK_SUCCESS2(statusTmp2);
        /* Reset shadow register */
        pDataParams2->dwFelicaEmdReg2 = (uint32)0x0U;
    }
    else
    {
        /* Configure FeliCa EMD Control Register with default value */
    	PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, FELICA_EMD_CONTROL2, PHHAL_HW_NCX3321_DEFAULT_FELICA_EMD_REGISTER2));
    	PH_CHECK_SUCCESS2(statusTmp2);
        /* Configure shadow register with default value */
        pDataParams2->dwFelicaEmdReg2 = PHHAL_HW_NCX3321_DEFAULT_FELICA_EMD_REGISTER2;
    }

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(
	P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint16, ANFCRL_VAR) wValue2,
	VAR(uint32, ANFCRL_VAR) dwMaskValue2
	)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2;

	if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	if(wValue2 != PH_OFF2)
	{
		if ((pDataParams2->dwFelicaEmdReg2 & dwMaskValue2) == 0U)
		{
			/* Update FELICA_EMD_CONTROL2 Register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Instr_WriteRegisterOrMask2(pDataParams2, FELICA_EMD_CONTROL2, dwMaskValue2));
			PH_CHECK_SUCCESS2(statusTmp2);
			/* Update shadow register */
			pDataParams2->dwFelicaEmdReg2 |= dwMaskValue2;
		}
	}
	else
	{
		if ((pDataParams2->dwFelicaEmdReg2 & dwMaskValue2) != 0U)
		{
			/* Update FELICA_EMD_CONTROL2 Register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, FELICA_EMD_CONTROL2, (uint32)~dwMaskValue2));
			PH_CHECK_SUCCESS2(statusTmp2);
			/* Update shadow register */
			pDataParams2->dwFelicaEmdReg2 &= (uint32)~dwMaskValue2;
		}
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte2(
  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
  VAR(uint16, ANFCRL_VAR) wValue2,
  VAR(uint8, ANFCRL_VAR) bBytePos2,
  VAR(uint32, ANFCRL_VAR) dwMaskValue2
	)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_INTERNAL_ERROR2;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwValue2 = 0U;

	if ((wValue2 & 0xFF00U) != 0U)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
	}

	if ((uint8)(pDataParams2->dwFelicaEmdReg2 >> bBytePos2) != (uint8)wValue2)
	{
		dwValue2 = pDataParams2->dwFelicaEmdReg2;
		dwValue2 &= ((uint32)~dwMaskValue2);
		dwValue2 |= ((uint32)wValue2 << bBytePos2);
		/* Update FELICA_EMD_CONTROL2 Register */
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, FELICA_EMD_CONTROL2, dwValue2));
		PH_CHECK_SUCCESS2(statusTmp2);
		/* Update shadow register */
		pDataParams2->dwFelicaEmdReg2 = dwValue2;
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetCardMode2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      VAR(uint16, ANFCRL_VAR) wTxDataRate2,
                      VAR(uint16, ANFCRL_VAR) wRxDataRate2,
                      VAR(uint16, ANFCRL_VAR) wSubcarrier2 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTxConfig2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRxConfig2 = 0U;

	UNUSED2(wSubcarrier2);
	if(pDataParams2->wTargetMode2 == PH_OFF2)
	{
		if(wTxDataRate2 == pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXDATARATE_FRAMING2])
		{
			wTxDataRate2 = PHHAL_HW_RF_DATARATE_NO_CHANGE2;
		}
		if(wRxDataRate2 == pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_RXDATARATE_FRAMING2])
		{
			wRxDataRate2 = PHHAL_HW_RF_DATARATE_NO_CHANGE2;
		}
	}
	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:

			switch (pDataParams2->bCardType2)
			{
			case PHHAL_HW_CARDTYPE_ISO14443A2:

				/* Check if Target is activated and perform required change to switch BaudRate. */
				if (pDataParams2->wTargetMode2 != PH_OFF2)
				{
					if(pDataParams2->bActiveMode2 == PH_OFF2)
					{
						switch (wTxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_1062:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_106_MANCH_SUBC2;
								/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
								break;
							case PHHAL_HW_RF_DATARATE_2122:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_212_BPSK2;
								/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_424_BPSK2;
								/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
								break;
							case PHHAL_HW_RF_DATARATE_8482:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_PICC_848_BPSK2;
								/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}

						switch (wRxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_1062:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_106_MILLER2;
								/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
								break;
							case PHHAL_HW_RF_DATARATE_2122:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_212_MILLER2;
								/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_424_MILLER2;
								/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
								break;
							case PHHAL_HW_RF_DATARATE_8482:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_PICC_848_MILLER2;
								/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}
					}
					else
					{
						switch (wTxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_1062:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_AT_1062;
								break;
							case PHHAL_HW_RF_DATARATE_2122:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_AT_2122;
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_AT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}
						switch (wRxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_1062:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_AT_1062;
								break;
							case PHHAL_HW_RF_DATARATE_2122:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_AT_2122;
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_AT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}
					}

				}
				else
				{
					switch (wTxDataRate2)
					{
						case PHHAL_HW_RF_DATARATE_1062:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_106_MILLER2;
							/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
							break;
						case PHHAL_HW_RF_DATARATE_2122:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_212_MILLER2;
							/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
							break;
						case PHHAL_HW_RF_DATARATE_4242:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_424_MILLER2;
							/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
							break;
						case PHHAL_HW_RF_DATARATE_8482:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443A_848_MILLER2;
							/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
							break;
						case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
							bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
							break;
						default:
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					}
					switch (wRxDataRate2)
					{
						case PHHAL_HW_RF_DATARATE_1062:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC2;
							/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_106;*/
							break;
						case PHHAL_HW_RF_DATARATE_2122:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_212_BPSK2;
							/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_212;*/
							break;
						case PHHAL_HW_RF_DATARATE_4242:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_424_BPSK2;
							/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_424;*/
							break;
						case PHHAL_HW_RF_DATARATE_8482:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443A_848_BPSK2;
							/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443A_848;*/
							break;
						case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
							bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
							break;
						default:
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					}
				}
				break;

			case PHHAL_HW_CARDTYPE_ISO14443B2:

				switch (wTxDataRate2)
				{
					case PHHAL_HW_RF_DATARATE_1062:
						bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443B_106_NRZ2;
						/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_106;*/
						break;
					case PHHAL_HW_RF_DATARATE_2122:
						bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443B_212_NRZ2;
						/* pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_212;*/
						break;
					case PHHAL_HW_RF_DATARATE_4242:
						bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443B_424_NRZ2;
						/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_424;*/
						break;
					case PHHAL_HW_RF_DATARATE_8482:
						bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO14443B_848_NRZ2;
						/*pTxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_848;*/
						break;
					case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
						bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
						break;
					default:
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}

				switch (wRxDataRate2)
				{
					case PHHAL_HW_RF_DATARATE_1062:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443B_106_BPSK2;
						/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_106;*/
						break;
					case PHHAL_HW_RF_DATARATE_2122:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443B_212_BPSK2;
						/*pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_212;*/
						break;
					case PHHAL_HW_RF_DATARATE_4242:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443B_424_BPSK2;
						/* pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_424;*/
						break;
					case PHHAL_HW_RF_DATARATE_8482:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO14443B_848_BPSK2;
						/*  pRxRegisterSet = (P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST))gkphhalHw_Ncx3321_I14443B_848;*/
						break;
					case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
						bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
						break;
					default:
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}
				break;

			case PHHAL_HW_CARDTYPE_FELICA_2122:
			case PHHAL_HW_CARDTYPE_FELICA_4242:

				if (pDataParams2->wTargetMode2 != PH_OFF2)
				{
					if(pDataParams2->bActiveMode2 == PH_OFF2)
					{
						switch (wTxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_2122:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_PT_2122;
								break;

							case PHHAL_HW_RF_DATARATE_4242:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_PT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}

						switch (wRxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_2122:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_PT_2122;
								break;

							case PHHAL_HW_RF_DATARATE_4242:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_PT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}
					}
					else
					{
						switch (wTxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_2122:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_AT_2122;
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_NFC_AT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}

						switch (wRxDataRate2)
						{
							case PHHAL_HW_RF_DATARATE_2122:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_AT_2122;
								break;
							case PHHAL_HW_RF_DATARATE_4242:
								bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_NFC_AT_4242;
								break;
							case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
								bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
								break;
							default:
								return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
						}
					}
				}
				else
				{
					switch (wTxDataRate2)
					{
						case PHHAL_HW_RF_DATARATE_2122:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_FELICA_2122;
							break;

						case PHHAL_HW_RF_DATARATE_4242:
							bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_FELICA_4242;
							break;

						case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
							bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
							break;

						default:
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					}

					switch (wRxDataRate2)
					{
						case PHHAL_HW_RF_DATARATE_2122:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_FELICA_2122;
							break;

						case PHHAL_HW_RF_DATARATE_4242:
							bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_FELICA_4242;
							break;

						case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
							bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
							break;

						default:
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					}

				}
				break;

			case PHHAL_HW_CARDTYPE_ISO156932:
				switch (wTxDataRate2)
				{
					case PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_42:
						bTxConfig2 = PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK102;
						break;

					case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
						bTxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
						break;

					default:
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}

				switch (wRxDataRate2)
				{
					case PHHAL_HW_RF_RX_DATARATE_LOW2:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO15693_6P6_SC2;
						break;

					case PHHAL_HW_RF_RX_DATARATE_HIGH2:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO15693_26_SC2;
						break;

					case PHHAL_HW_RF_RX_DATARATE_FAST_HIGH2:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO15693_53_SC2;
						break;

					case PHHAL_HW_RF_DATARATE_1062:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO15693_1062;
						break;

					case PHHAL_HW_RF_DATARATE_2122:
						bRxConfig2 = PHHAL_HW_NCX3321_RF_RX_ISO15693_2122;
						break;

					case PHHAL_HW_RF_RX_DATARATE_FAST_LOW2:
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);

					case PHHAL_HW_RF_DATARATE_NO_CHANGE2:
						bRxConfig2 = PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2;
						break;

					default:
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}
				break;
			default:
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			if(!((PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2 != bTxConfig2) || (PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2 != bRxConfig2)))
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Instr_LoadRfConfiguration2(
				pDataParams2,
				(uint8) bTxConfig2,
				(uint8) bRxConfig2 ));
			break;
	}

	if(statusTmp2 == PH_ERR_SUCCESS2)
	{
		/* If Datarate is changed, then Update Data-rate in shadow for parity setting */
		if(wTxDataRate2 != PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2)
		{
			pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXDATARATE_FRAMING2] = wTxDataRate2;
		}
		if(wRxDataRate2 != PHHAL_HW_NCX3321_CURRENT_RF_CONFIGURATION_INDEX2)
		{
			pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_RXDATARATE_FRAMING2] = wRxDataRate2;
		}
	}

	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTxDataRateFraming2(
	P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
	VAR(uint16, ANFCRL_VAR) wConfig2,
	VAR(uint16, ANFCRL_VAR) wValue2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wFraming2 = 0U;
  VAR(phStatus_t2, ANFCRL_VAR) statusTmp2 = PH_ERR_SUCCESS2;

	/* Update the framing, based on the Higher byte */
	wFraming2 = wValue2 & PHHAL_HW_RF_FRAMING_OPTION_MASK2;
	wFraming2 = wFraming2 >> 0x08U;
	switch(bSetTxState2)
	{
		case PHHAL_HW_INT_STATE_IDLE2:
			if ((pDataParams2->wCfgShadow2[wConfig2] & PHHAL_HW_RF_DATARATE_OPTION_MASK2) != (wValue2 & PHHAL_HW_RF_DATARATE_OPTION_MASK2))
			{
				if((wFraming2 != PHHAL_HW_CARDTYPE_CURRENT2) && (wFraming2 != pDataParams2->bCardType2))
				{
					if((wValue2 & PHHAL_HW_RF_FRAMING_OPTION_MASK2) != PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2)
					{
						pDataParams2->bCardType2 = (uint8)wFraming2;
					}
				}
				bSetTxState2 = PHHAL_HW_INT_STATE_CMD12;
			}
			else
			{
				return PH_ERR_SUCCESS2;
			}
			/*no break*/

		case PHHAL_HW_INT_STATE_CMD12:

			if(pDataParams2->bCardType2 != PHHAL_HW_CARDTYPE_ISO156932)
			{
				/* Evaluate hardware settings */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetCardMode2(
					pDataParams2,
					(wValue2 & PHHAL_HW_RF_DATARATE_OPTION_MASK2),
					PHHAL_HW_RF_DATARATE_NO_CHANGE2,
					pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_SUBCARRIER2]));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				break;
			}
			else
			{
				/* clear the 15693 datarate mask */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2( pDataParams2, SYSTEM_CONFIG2, ~((uint32)SYSTEM_CONFIG_15693_CHANGE_DATARATE_MASK2)));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				bSetTxState2 = PHHAL_HW_INT_STATE_CMD22;
			}
			return PH_STATUS_INPROCESS2;
		case PHHAL_HW_INT_STATE_CMD22:
			/* Update the Baudrate based on the lower byte */
			wValue2 = wValue2 & PHHAL_HW_RF_DATARATE_OPTION_MASK2;

			if(wValue2 == PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_42)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask2( pDataParams2, SYSTEM_CONFIG2, (uint32) (PHHAL_HW_15693_26KBPS2)));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}
			else if(wValue2 == PHHAL_HW_RF_I15693_53KBPS_DATARATE2)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask2( pDataParams2, SYSTEM_CONFIG2, (uint32) (PHHAL_HW_15693_53KBPS2)));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}
			else if(wValue2 == PHHAL_HW_RF_DATARATE_1062)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask2( pDataParams2, SYSTEM_CONFIG2, (uint32) (PHHAL_HW_15693_106KBPS2)));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}
			else if(wValue2 == PHHAL_HW_RF_DATARATE_2122)
			{
				/* set the value */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,  phhalHw_Ncx3321_Instr_WriteRegisterOrMask2( pDataParams2, SYSTEM_CONFIG2, (uint32) (PHHAL_HW_15693_212KBPS2)));
				PH_BREAK_ON_FAILURE2(statusTmp2);
			}
			else
			{
				/* To avoid the warning */
				statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);    /* return the invalid parameter */
			}
			break;
	}
	if(statusTmp2 == PH_ERR_SUCCESS2){
		/* Write config data into shadow */
		pDataParams2->wCfgShadow2[wConfig2] = (wValue2 | (wFraming2 << 0x08U)) ;
	}
	bSetTxState2 = PHHAL_HW_INT_STATE_IDLE2;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetRxDataRateFraming2(
		P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
		VAR(uint16, ANFCRL_VAR) wConfig2,
		VAR(uint16, ANFCRL_VAR) wValue2)
{
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wFraming2 = 0U;
	VAR(phStatus_t2, ANFCRL_VAR) statusTmp2 = PH_ERR_SUCCESS2;

	if ((pDataParams2->wCfgShadow2[wConfig2] & PHHAL_HW_RF_DATARATE_OPTION_MASK2) != (wValue2 & PHHAL_HW_RF_DATARATE_OPTION_MASK2))
	{
		/* Update the framing, based on the Higher byte */
		wFraming2 = wValue2 & PHHAL_HW_RF_FRAMING_OPTION_MASK2;
		wFraming2 = wFraming2 >> 0x08U;

		if((wFraming2 != PHHAL_HW_CARDTYPE_CURRENT2) && (wFraming2 != pDataParams2->bCardType2))
		{
			if((wValue2 & PHHAL_HW_RF_FRAMING_OPTION_MASK2) != PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2)
			{
				pDataParams2->bCardType2 = (uint8)wFraming2;
			}
		}

		/* Update the Baudrate based on the lower byte */
		wValue2 = wValue2 & PHHAL_HW_RF_DATARATE_OPTION_MASK2;

		/* Evaluate hardware settings */
		PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetCardMode2(
			pDataParams2,
			PHHAL_HW_RF_DATARATE_NO_CHANGE2,
			wValue2,
			pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_SUBCARRIER2]));
		PH_CHECK_SUCCESS2(statusTmp2);
		/* Write config data into shadow */
		pDataParams2->wCfgShadow2[wConfig2] = (wValue2 | (wFraming2 << 0x08U));
	}
	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetMinFdt2(
                    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                    VAR(uint16, ANFCRL_VAR) wValue2
										)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTimer2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTxRate2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bSetMinFdtState2 = 0U;

	switch(bSetMinFdtState2)
	{
		case 0U:
			if (wValue2 == PH_ON2)
			{
				/* Get current timeout value */
				PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_GetConfig2(
					pDataParams2,
					PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
					&wTimer2));

				/* Backup current value */
				pDataParams2->dwFdtPc2 = wTimer2;

				/* Get current data rate */
				PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_GetConfig2(
					pDataParams2,
					PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,
					&wTxRate2));

				/* Select timeout value based on data rate */
				switch(wTxRate2)
				{
					case PHHAL_HW_RF_DATARATE_1062:
						wTimer2 = PHHAL_HW_MINFDT_106_US2;
						break;

					case PHHAL_HW_RF_DATARATE_2122:
						wTimer2 = PHHAL_HW_MINFDT_212_US2;
						break;

					case PHHAL_HW_RF_DATARATE_4242:
						wTimer2 = PHHAL_HW_MINFDT_424_US2;
						break;

					case PHHAL_HW_RF_DATARATE_8482:
						wTimer2 = PHHAL_HW_MINFDT_848_US2;
						break;

					default:
						break;
				}
				bSetMinFdtState2 = 1U;
				return PH_STATUS_INPROCESS2;
			}
			else if (wValue2 == PH_OFF2)
			{
				bSetMinFdtState2 = 2U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* If option is not #PH_OFF2 or #PH_ON2 */
				statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			break;
		case 1U:
			/* Set timeout value */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(
				pDataParams2,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2,
				wTimer2));
			break;
		case 2U:
			/* Restore the timeout value */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(
				pDataParams2,
				PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2,
				pDataParams2->dwFdtPc2));
			break;
	}

	wTimer2 = 0U;
	bSetMinFdtState2 = 0U;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetDigiDelay2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bIsTimeout2, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDelayUs2)
{
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataRate2 = 0;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0;
	wDataRate2 = pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_RXDATARATE_FRAMING2] & PHHAL_HW_RF_DATARATE_OPTION_MASK2;

	bIndex2 = pDataParams2->bCardType2 - 1U;

	switch (pDataParams2->bCardType2)
	{
		case PHHAL_HW_CARDTYPE_ISO14443A2:
		case PHHAL_HW_CARDTYPE_ISO14443B2:
			*pDelayUs2 = gkphhalHw_Ncx3321_DigiDelays_Us2[bIndex2][wDataRate2];
			/* In a timeout case we have to add an additional delay */
			if (bIsTimeout2 != PH_OFF2)
			{
				*pDelayUs2 = *pDelayUs2 + PHHAL_HW_NCX3321_I14443_ADD_DELAY_US2;
			}
			break;
		case PHHAL_HW_CARDTYPE_FELICA_2122:
		case PHHAL_HW_CARDTYPE_FELICA_4242:
			bIndex2 = PHHAL_HW_CARDTYPE_FELICA_2122 - 1U;
			*pDelayUs2 = gkphhalHw_Ncx3321_DigiDelays_Us2[bIndex2][wDataRate2];
			break;
		case PHHAL_HW_CARDTYPE_ISO156932:
			*pDelayUs2 = gkphhalHw_Ncx3321_DigiDelays_Us2[bIndex2][wDataRate2
					- PHHAL_HW_RF_RX_DATARATE_LOW2];
			/* In a timeout case we have to add an additional delay */
			if (bIsTimeout2 != PH_OFF2)
			{
				if (wDataRate2 == PHHAL_HW_RF_RX_DATARATE_HIGH2)
				{
					*pDelayUs2 = *pDelayUs2 + PHHAL_HW_NCX3321_I15693_ADD_DELAY_US2;
				}
				else
				{
					*pDelayUs2 = *pDelayUs2 + (PHHAL_HW_NCX3321_I15693_ADD_DELAY_US2 >> 1U);
				}
			}
			break;

		case PHHAL_HW_CARDTYPE_UNKNOWN2:
		{
			/*
			 * For the case when apply protocol settings is not done.
			 */
			*pDelayUs2 = 0;
			break;
		}
		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_HAL2);
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTmo2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wTimeout2,
                  VAR(uint8, ANFCRL_VAR) bUnit2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 wPrescaler2 = 0U;
  static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwLoadValue2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wUDigitalDelay2;

  switch(bSetTmoState2)
  	{
  	  case PHHAL_HW_INT_STATE_IDLE2:
		  wUDigitalDelay2 = 0U;
			/* Parameter check */
			if ((bUnit2 != PHHAL_HW_TIME_MICROSECONDS2) && (bUnit2 != PHHAL_HW_TIME_MILLISECONDS2))
			{
                wPrescaler2 = 0U;
                dwLoadValue2 = 0U;
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			if (wTimeout2 == 0U)
			{
                wPrescaler2 = 0U;
                dwLoadValue2 = 0U;
				return PH_ERR_SUCCESS2;
			}

			if (bUnit2 == PHHAL_HW_TIME_MICROSECONDS2)
			{
				PH_CHECK_SUCCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Int_GetDigiDelay2(pDataParams2,PH_ON2,&wUDigitalDelay2));
				/* here wTimeout2 will be in uS */
				wPrescaler2 = 0x00U;
				/*Reducing the division by 2 digits to retain the 2 digit decimal places which were getting wiped out*/
				dwLoadValue2 = (uint32) ( PHHAL_HW_NCX3321_MAX_FREQ2 / (PHHAL_HW_NCX3321_CONVERSION_US_SEC2 / 100U));
				/*Restoring the division done in the earlier step*/
				dwLoadValue2 = (uint32) ((((uint32)wTimeout2 + (uint32)wUDigitalDelay2) * dwLoadValue2) / 100U);
			}
			else
			{
				wPrescaler2 = 0x3CU;
				if (wTimeout2 <= PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS2)
				{
					dwLoadValue2 =  (uint32)((uint32)wTimeout2 * ( PHHAL_HW_NCX3321_MIN_FREQ2 / PHHAL_HW_NCX3321_CONVERSION_MS_SEC2));
				}
				else
				{
                    wPrescaler2 = 0U;
                    dwLoadValue2 = 0U;
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_PARAMETER_OVERFLOW2, PH_COMP_HAL2);
				}
			}
			bSetTmoState2 = PHHAL_HW_INT_STATE_CMD12;
			/*no break*/
  	  case PHHAL_HW_INT_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_TimerStart2(
							pDataParams2,
							CLIF_TIMER1_CONFIG2,
							CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK2,
							CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK2,
							wPrescaler2,
							dwLoadValue2));
			break;
  	}
  	bSetTmoState2 = PHHAL_HW_INT_STATE_IDLE2;
    wPrescaler2 = 0U;
    dwLoadValue2 = 0U;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_Retrieve_Data2(
                      P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
											)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    VAR(uint16, ANFCRL_VAR) wTmpRxBufferLen2 = 0U;
    static VAR(uint16, ANFCRL_VAR) wTmpRxBufferSize2 = 0U;
    static VAR(uint16, ANFCRL_VAR) wNumByteReceived2 = 0U;
    VAR(uint32, ANFCRL_VAR) dwValue2 = 0U;
    VAR(uint32, ANFCRL_VAR) dwColPos2 = 0U;
    VAR(uint32, ANFCRL_VAR) dwTemp2 = 0U;
    static VAR(uint32, ANFCRL_VAR) dwRx_Status2 = 0U;
    static VAR(uint32, ANFCRL_VAR) dwRf_Status2 = 0U;
    static VAR(uint8, ANFCRL_VAR) bBackup2 = 0U;
    static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuffer2 = NULL;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData2 = NULL;

    /* NULL pointer should be avoided. */
	if ((ppRxBuffer2 == NULL))
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
	}
	pRxData2 = *ppRxBuffer2;

	switch(pDataParams2->HwEventObj2.bEventState2)
	{
		case PH_TOOLS_EVENT_IDLE2:
			/* Dereference of NULL pointer should be avoided. */
			if(*ppRxBuffer2 == NULL)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			dwRx_Status2 = (uint32)pRxData2[0];
			dwRx_Status2 |= (uint32)pRxData2[1] << 8U;
			dwRx_Status2 |= (uint32)pRxData2[2] << 16U;
			dwRx_Status2 |= (uint32)pRxData2[3] << 24U;

			dwRf_Status2 = (uint32)pRxData2[4];
			dwRf_Status2 |= (uint32)pRxData2[5] << 8U;
			dwRf_Status2 |= (uint32)pRxData2[6] << 16U;
			dwRf_Status2 |= (uint32)pRxData2[7] << 24U;

			/* Success; check data received */
			pDataParams2->wRxBufLen2 = 0U;

			(void)phhalHw_Ncx3321_Int_GetRxBuffer2(
					pDataParams2,
					&pTmpRxBuffer2,
					&wTmpRxBufferLen2,
					&wTmpRxBufferSize2);

			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				bBackup2 = pTmpRxBuffer2[0];
			}
			if(pDataParams2->bRxMultiple2 == PH_ON2)
			{
				wNumByteReceived2 = (uint16)((dwRx_Status2 & CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_MASK2) |
					(((dwRx_Status2 & CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_MASK2) >>
							CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_POS2) * 32U));
			}
			else
			{
				wNumByteReceived2 = (uint16)(dwRx_Status2 & CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_MASK2);
			}

			/* Check if the buffer size is sufficient*/
			if (wTmpRxBufferSize2 < wNumByteReceived2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_HAL2);
			}
			if(wNumByteReceived2 == 0U)
			{
				break;
			}
			/*no break*/
		case PH_TOOLS_EVENT_PENDING2:
		case PH_TOOLS_EVENT_OCCUR2:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_RetrieveRFData2(pDataParams2, ppRxBuffer2, pRxLength2));
			PH_CHECK_SUCCESS2(status2);
            /* Dereference of NULL pointer should be avoided. */
            if (*ppRxBuffer2 == NULL)
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
            }
			if(*pRxLength2 != wNumByteReceived2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_HAL2);
			}
			break;
	}

	/* Extract RX last bits */
	dwTemp2 = dwRx_Status2 & CLIF_RX_STATUS_RX_NUM_LAST_BITS_MASK2;
	dwTemp2 = dwTemp2 >> CLIF_RX_STATUS_RX_NUM_LAST_BITS_POS2;

	/* Set RX last bits */
	pDataParams2->wAdditionalInfo2 = (uint16)dwTemp2;

	if (0U != (dwRf_Status2 & CLIF_RX_STATUS_ERROR_RX_COLLISION_DETECTED_MASK2))
	{
		if ((wNumByteReceived2 == 0U) && ((dwRx_Status2 & CLIF_RX_STATUS_RX_COLL_POS_MASK2) == 0U))
		{
			/* No data received */
			status2 = PH_ERR_IO_TIMEOUT2;
		}
		else
		{
			status2 = PH_ERR_COLLISION_ERROR2;

			/* Retrieve collision position */
			dwColPos2 = dwRx_Status2 & CLIF_RX_STATUS_RX_COLL_POS_MASK2;
			dwColPos2 = dwColPos2 >> CLIF_RX_STATUS_RX_COLL_POS_POS2;

			/* Restore RX buffer size */
			wTmpRxBufferSize2 = wTmpRxBufferSize2 + wNumByteReceived2;
			if (dwColPos2 > wTmpRxBufferSize2)
			{
				wNumByteReceived2 = wTmpRxBufferSize2;
				status2 = PH_ERR_BUFFER_OVERFLOW2;
			}
			else
			{
				wNumByteReceived2 = ((uint16)dwColPos2 >> 3U);
			}

			/* Extracting valid bits from Collision position */
			if(dwColPos2 >= 8U)
			{
				dwValue2 = dwColPos2 % 8U ;
			}
			else
			{
				dwValue2 = dwColPos2;
			}

			if (0U != (dwValue2))
			{
				/* If it is non zero, some valid bits are received */
				if (wNumByteReceived2 == wTmpRxBufferSize2)
				{
					status2 = PH_ERR_BUFFER_OVERFLOW2;
				}
				else
				{
					++wNumByteReceived2;
				}
			}

			/* Store valid bits of last byte */
			pDataParams2->wAdditionalInfo2 = (uint16)dwValue2;
		}
	}
	else if (0U != (dwRf_Status2 & CLIF_RX_STATUS_ERROR_RX_DATA_INTEGRITY_ERROR_MASK2))
	{
		status2 = PH_ERR_INTEGRITY_ERROR2;
	}
	else if (dwTemp2 != 0x00U) 
	{
		/* Set incomplete byte status2 if applicable */
		status2 =  PH_ERR_SUCCESS_INCOMPLETE_BYTE2;
	}
	else if (0U != (dwRf_Status2 & CLIF_RX_STATUS_ERROR_RX_PROTOCOL_ERROR_MASK2))
	{
		status2 = PH_ERR_PROTOCOL_ERROR2;
	}
	else
	{
		/* For QAC */
	}

	if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2) && (wNumByteReceived2 != 0U))
	{
		if(*ppRxBuffer2[0] != 0xF0U)
		{
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_IO_TIMEOUT2, PH_COMP_HAL2);
		}
		pTmpRxBuffer2[0] = bBackup2;
		(*ppRxBuffer2)++;
		wNumByteReceived2--;
	}
	/* Store received data length in dataparams */
	pDataParams2->wRxBufLen2 = pDataParams2->wRxBufStartPos2 + wNumByteReceived2;

	*ppRxBuffer2 = pDataParams2->pRxBuffer2;

	if (pRxLength2 != NULL)
	{
		*pRxLength2 = pDataParams2->wRxBufLen2;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_ClearNSetRegFields2(
		P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
		VAR(uint8, ANFCRL_VAR) bRegister2,
		VAR(uint32, ANFCRL_VAR) dwMask2,
		VAR(uint32, ANFCRL_VAR) dwPos2,
		VAR(uint16, ANFCRL_VAR) wValue2)
{
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 wRegTypeValueSets2[12] = {0};
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSizeOfRegTypeValueSets2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTemp2 = 0U;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

	dwTemp2 = (uint32) ~(dwMask2);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = bRegister2;
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

	dwTemp2 = ((uint32)wValue2 << dwPos2) & dwMask2;
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = bRegister2;
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
	wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2,  wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
	PH_CHECK_SUCCESS2(status2);

	return PH_ERR_SUCCESS2;
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
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_ISR_Callback2(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(uint32, ANFCRL_VAR) dwEventStatusReg2 = 0x0U;
  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pNcx3321DataParams2 = NULL;
	pNcx3321DataParams2 = (phhalHw_Ncx3321_DataParams_t2 *) pDataParams2;

	if( pNcx3321DataParams2->sIrqResp2.pHandlerModeBuffPtr2[1] == PH_NCX3321_EVT_RSP2 )
	{
		dwEventStatusReg2 = (uint32) pNcx3321DataParams2->sIrqResp2.pIsrEvtBuffPtr2[4];
		dwEventStatusReg2 |= ((uint32) pNcx3321DataParams2->sIrqResp2.pIsrEvtBuffPtr2[5]) << 8U ;
		dwEventStatusReg2 |= ((uint32) pNcx3321DataParams2->sIrqResp2.pIsrEvtBuffPtr2[6]) << 16U;
		dwEventStatusReg2 |= ((uint32) pNcx3321DataParams2->sIrqResp2.pIsrEvtBuffPtr2[7]) << 24U;

		if ((dwEventStatusReg2 & (PH_NCX3321_EVT_TX_OVERCURRENT_ERROR2 | PH_NCX3321_EVT_CTS2)) == 0U)
		{
			/* Received Event can be processed by RdLib */
			(void)phTools_EventPost2(
				&((phhalHw_Ncx3321_DataParams_t2 *)(pDataParams2))->HwEventObj2,
				E_EVENT_OPT_POST_ISR2,
				E_PHHAL_HW_EVT_SIG2,
				NULL);
		}
	}
	else
	{
		/*Parse the response and accordingly send event*/
		(void)phTools_EventPost2(
			&((phhalHw_Ncx3321_DataParams_t2 *)(pDataParams2))->HwEventObj2,
			E_EVENT_OPT_POST_ISR2,
			E_EVENT_RF2,
			NULL);
	}
}

FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_GuardTimeCallBck2(void)
{
	if(xEventHandle2 != NULL)
	{
		(void)phTools_EventPost2(
			xEventHandle2,
			E_EVENT_OPT_POST_ISR2,
			E_EVENT_GT_EXP2,
			NULL);
	}
}

#ifdef PHDRIVER_SOFT_SSEL2
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_WriteSSEL2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams2,
                VAR(uint8, ANFCRL_VAR) bValue2
								)
{
	if (((phbalReg_Type_t2 *)pBalDataParams2)->bBalType2 == PHBAL_REG_TYPE_SPI2)
	{
		phDriver_PinWrite2(PHDRIVER_PIN_SSEL2, bValue2);
	}
}
#endif /* PHDRIVER_SOFT_SSEL2 */

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Int_EventWait2(
  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
  VAR(uint32, ANFCRL_VAR) dwExpectedEvents2,
  VAR(uint32, ANFCRL_VAR) dwEventTimeOut2,
  VAR(uint8, ANFCRL_VAR) bPayLoadPresent2,
  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventReceived2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pEvtPayload2 = NULL;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEvtReceived2 = 0x0U;

	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_WaitForEvent2(
		pDataParams2,
		dwExpectedEvents2,
		dwEventTimeOut2,
		bPayLoadPresent2,
		&dwEvtReceived2,
		&pEvtPayload2));
	if((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
	{
		if(pEvtPayload2 != NULL)
		{
			pDataParams2->dwEventStatus2 = (uint32) pEvtPayload2[0];
			pDataParams2->dwEventStatus2 |= ((uint32) pEvtPayload2[1]) << 8U ;
			pDataParams2->dwEventStatus2 |= ((uint32) pEvtPayload2[2]) << 16U;
			pDataParams2->dwEventStatus2 |= ((uint32) pEvtPayload2[3]) << 24U;

			if((dwEvtReceived2 & PH_NCX3321_EVT_GENERAL_ERROR2) != 0U)
			{
				pDataParams2->dwGenError2 = (uint32) pEvtPayload2[4];
				pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[5]) << 8U ;
				pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[6]) << 16U;
				pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[7]) << 24U;

				status2 = PH_ERR_INTERNAL_ERROR2;
			}
		}
	}
	else
	{
		if((status2 & PH_ERR_MASK2) == PH_EVENT_TIMEOUT2)
		{
			status2 = PH_ERR_IO_TIMEOUT2;
		}
	}

	if(dwEventReceived2 != NULL)
	{
		* dwEventReceived2 = dwEvtReceived2;
	}
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */

#ifdef __cplusplus
}
#endif
