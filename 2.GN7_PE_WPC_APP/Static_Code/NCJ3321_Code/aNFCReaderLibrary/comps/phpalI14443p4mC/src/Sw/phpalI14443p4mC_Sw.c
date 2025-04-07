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
*   @file    phpalI14443p4mC_Sw.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC_Sw - PAL API usage in common use cases.
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
#include "phpalI14443p4mC_Sw.h"
#include "phpalI14443p4mC_Sw_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4mC_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phpalI14443p4mC_Sw.h header file are of the same vendor */
#if (PHPALI14443P4MC_SW_VENDOR_ID_C != PHPALI14443P4MC_SW_VENDOR_ID)
    #error "phpalI14443p4mC_Sw.c and phpalI14443p4mC_Sw.h have different vendor ids"
#endif
/* Check if current file and phpalI14443p4mC_Sw.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C    != PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C    != PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHPALI14443P4MC_SW_AR_RELEASE_REVISION_VERSION_C != PHPALI14443P4MC_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC_Sw.c and phpalI14443p4mC_Sw.h are different"
#endif
/* Check if current file and phpalI14443p4mC_Sw.h header file are of the same Software version */
#if ((PHPALI14443P4MC_SW_SW_MAJOR_VERSION_C != PHPALI14443P4MC_SW_SW_MAJOR_VERSION) || \
     (PHPALI14443P4MC_SW_SW_MINOR_VERSION_C != PHPALI14443P4MC_SW_SW_MINOR_VERSION) || \
     (PHPALI14443P4MC_SW_SW_PATCH_VERSION_C != PHPALI14443P4MC_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC_Sw.c and phpalI14443p4mC_Sw.h are different"
#endif
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
/* Enumeration State */
typedef enum {
	PH_I14443P4MC_STATE_1,
	PH_I14443P4MC_STATE_2,
	PH_I14443P4MC_STATE_3,
	PH_I14443P4MC_STATE_4,
	PH_I14443P4MC_STATE_5,
	PH_I14443P4MC_STATE_6,
	PH_I14443P4MC_STATE_7,
	PH_I14443P4MC_STATE_8,
	PH_I14443P4MC_STATE_9
} phI1443P4mCState_t;

typedef enum {
	PH_I14443P4MC_STATE_BACKUP,
	PH_I14443P4MC_STATE_SEND
} phI1443P4mCState_TxR_t;


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/

#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Frame size table */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM aI14443p4mC_FsTable[PHPALI14443P4MC_FS_INDEX] = {14, 22, 30, 38, 46, 62, 94, 126, 254, 510, 1022, 2046, 4094};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/* State variables for Non-Blocking     */
static VAR(phI1443P4mCState_t, ANFCRL_VAR) gbP4mCWtxState  = PH_I14443P4MC_STATE_1;
static VAR(phI1443P4mCState_t, ANFCRL_VAR) gbP4mCActState  = PH_I14443P4MC_STATE_1;
static VAR(phI1443P4mCState_t, ANFCRL_VAR) gbP4mCReceiveState  = PH_I14443P4MC_STATE_1;
static VAR(phI1443P4mCState_t, ANFCRL_VAR) gbP4mCTransmitState  = PH_I14443P4MC_STATE_1;
static VAR(phI1443P4mCState_TxR_t, ANFCRL_VAR) gbP4mCStateTxR = PH_I14443P4MC_STATE_BACKUP;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Init(
                   P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams,
                   VAR(pWtxTimerCallback_t, ANFCRL_VAR) pWtxCallback
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	if (sizeof(phpalI14443p4mC_Sw_DataParams_t) != wSizeOfDataParams)
	{
		return (PH_ERR_INVALID_DATA_PARAMS | PH_COMP_PAL_I14443P4MC);
	}
	PH_ASSERT_NULL (pDataParams);
	PH_ASSERT_NULL (pHalDataParams);

	/* Initialize data parameters */
	pDataParams->wId                = PH_COMP_PAL_I14443P4MC | PHPAL_I14443P4MC_SW_ID;
	pDataParams->pHalDataParams     = pHalDataParams;
    pDataParams->pWtxTimerCallback  = pWtxCallback;

	pDataParams->bWtx               = PHPAL_I14443P4MC_SW_MIN_WTX_VALUE;
	pDataParams->bDisableWtx        = PH_OFF;
	/* Default operating mode is NFC */
	pDataParams->bOpMode            = RD_LIB_MODE_NFC;
	/* By default delta time to be subtracted from WTX timer time is set to 0 */
	pDataParams->wWtDelta           = 0;
	/* Default percentage of actual time to be used in WTX timer is set to 75% */
	pDataParams->bWtPercentage      = 75;

	/* Reset protocol to defaults */
	(void)phpalI14443p4mC_Sw_ResetProtocol(pDataParams);

	pDataParams->bWtxTimerSts = PHPAL_I14443P4MC_WTX_TIMER_IDLE;
	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_DeInit(
                   P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								   )
{
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	PH_ASSERT_NULL (pDataParams);

	/* Reset protocol to defaults */
	(void)phpalI14443p4mC_Sw_ResetProtocol(pDataParams);

	/* Initialize data parameters */
	pDataParams->wId                = 0;
	pDataParams->pHalDataParams     = NULL;

	pDataParams->bWtx               = 0;
	pDataParams->bDisableWtx        = PH_OFF;
	/* Default operating mode is NFC */
	pDataParams->bOpMode            = RD_LIB_MODE_NFC;
	/* By default delta time to be subtracted from WTX timer time is set to 0 */
	pDataParams->wWtDelta           = 0;
	/* Default percentage of actual time to be used in WTX timer is set to 75% */
	pDataParams->bWtPercentage      = 0;

	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_ResetProtocol(
                      P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
											)
{
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;
	pDataParams->bStateNow        = PHPAL_I14443P4MC_STATE_NONE;
	/* Default block number is 1. ISO14443-4 7.5.3.2. Rule C */
	pDataParams->bBlockNr         = 1;
	pDataParams->bFsdi            = 0;
	/* Default FSCI value is 2 */
	pDataParams->bFsci            = PHPALI14443P4MC_FSCI_DEFAULT;
	pDataParams->bDr              = PHPAL_I14443P4MC_106;
	pDataParams->bDs              = PHPAL_I14443P4MC_106;
	pDataParams->bUnequalDrDs     = 0;
	pDataParams->bFwi             = PHPALI14443P4MC_FWI_DEFAULT;
	pDataParams->bSfgi            = PHPALI14443P4MC_SFGI_DEFAULT;
	pDataParams->bCid             = 0;
	pDataParams->bNad             = 0;
	pDataParams->bChainingRx      = 0;
	pDataParams->bChainingTx      = 0;
	/* Default CID supported ISO14443-4 5.2.6 */
	pDataParams->bCidEnable       = PH_ON;
	/* Default NAD not supported ISO14443-4 5.2.6 */
	pDataParams->bNadEnable       = PH_OFF;
	pDataParams->bCidPresence     = PH_OFF;
	pDataParams->bNadPresence     = PH_OFF;

	/* Reset the position in case the PICC stopped abruptly due to RF OFF during chaining */
	(void)phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0);

	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Activate(
                     P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRats,
                     VAR(uint8, ANFCRL_VAR) bRatsLength,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts,
                     VAR(uint16, ANFCRL_VAR) wAtsLength
									   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex;

	switch (gbP4mCActState)
	{
		case PH_I14443P4MC_STATE_1:
			/* Check for valid state */
			if(pDataParams->bStateNow != PHPAL_I14443P4MC_STATE_NONE)
			{
				return (PH_ERR_USE_CONDITION | PH_COMP_PAL_I14443P4MC);
			}

			/* Validate RATS */
			if((bRatsLength != PHPALI14443P4MC_RATS_LEN) || (pRats[0] != PHPALI14443P4MC_RATS_CMD))
			{
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}

			/* FSDI RFU value check and update FSDI */
			if(pDataParams->bOpMode == RD_LIB_MODE_NFC)
			{
				if(((pRats[1] & 0xF0U) >> 0x04U) > 0x08U)
				{
					pDataParams->bFsdi = 0x08;
				}
				else
				{
					pDataParams->bFsdi = (uint8)((uint8)(pRats[1] & 0xF0U) >> 0x04U);
				}
			}
			else
			{
				if(((pRats[1] & 0xF0U) >> 0x04U) > 0x0CU)
				{
					pDataParams->bFsdi = 0x0C;
				}
				else
				{
					pDataParams->bFsdi = (uint8)((uint8)(pRats[1] & 0xF0U) >> 0x04U);
				}
			}

			/* Validate and update CID */
			if((pRats[1] & 0x0FU) > 0x0EU)
			{
				/* Device shall be put to HALT or IDLE state (i.e. application shall
				 * restart listen mode) */
				return (PH_ERR_PROTOCOL_ERROR | PH_COMP_PAL_I14443P4MC);
			}
			else
			{
				pDataParams->bCid = (pRats[1] & 0x0FU);
			}

			/* Validation of ATS length */
			if((wAtsLength == 0u) || (wAtsLength !=  pAts[PHPALI14443P4MC_TL_IDX]))
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
			}

			/* Validate ATS length */
			if(wAtsLength > aI14443p4mC_FsTable[pDataParams->bFsdi])
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
			}
			if(pDataParams->bOpMode == RD_LIB_MODE_NFC)
			{
				if((wAtsLength < PHPALI14443P4MC_NFC_MIN_ATS_LEN)
					|| (wAtsLength > PHPALI14443P4MC_NFC_MAX_ATS_LEN))
				{
					return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
				}
			}

			/* Update the length of ATS validated till now */
			bIndex = 1;

			/* Check and validate (T0), TA(1), TB(1) and TC(1) */
			if(wAtsLength > 1U)
			{
				/* Increment length/index */
				bIndex++;

				/* Check if RFU bit of T0 is set */
				if(0U != (pAts[1] & 0x80U))
				{
					return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
				}

				/* FSCI RFU value check and update FSCI */
				if(pDataParams->bOpMode == RD_LIB_MODE_NFC)
				{
					/* Check for FSC maximum */
					if((pAts[1] & 0x0FU) > PHPALI14443P4MC_FSC_MAX_NFC_FORUM)
					{
						pDataParams->bFsci = PHPALI14443P4MC_FSC_MAX_NFC_FORUM;
					}
					else
					{
						pDataParams->bFsci = (pAts[1] & 0x0FU);
						/* Check if FSC (FSCT4AT,MIN) criteria is met and assign FSCT4AT,MIN if not.  */
						if (pDataParams->bFsci < PHPALI14443P4MC_FSC_MIN_NFC_FORUM)
						{
							pDataParams->bFsci = PHPALI14443P4MC_FSC_MIN_NFC_FORUM;
						}
					}
				}
				else
				{
					if((pAts[1] & 0x0FU) > 0x0CU)
					{
						pDataParams->bFsci = 0x0Cu;
					}
					else
					{
						pDataParams->bFsci = (pAts[1] & 0x0FU);
					}
				}

				/* Check TA(1) */
				if(0U != (pAts[PHPALI14443P4MC_T0_IDX] & 0x10U))
				{
					/* Increment length/index */
					bIndex++;

					/* Validate length */
					if(wAtsLength < bIndex)
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* Check if RFU bit is set */
					if(0U != (pAts[bIndex - 1u] & 0x08U))
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* For NFC mode, DR and DS shall be zero */
					if((pDataParams->bOpMode == RD_LIB_MODE_NFC) && (((pAts[bIndex - 1u]) & 0x77U) != 0u))
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* Update DR and DS */
					pDataParams->bDr = pAts[bIndex - 1u] & 0x07U;
					pDataParams->bDs = (pAts[bIndex - 1u] & 0x70U) >> 4U;

					/* Check if DR and DS are same  */
					if(pDataParams->bDr != pDataParams->bDs)
					{
						pDataParams->bUnequalDrDs = 1u;
					}
					else
					{
						pDataParams->bUnequalDrDs = 0u;
					}
				}

				/* Check TB(1) */
				if(0U != (pAts[PHPALI14443P4MC_T0_IDX] & 0x20U))
				{
					/* Increment length/index */
					bIndex++;

					/* Validate length */
					if(wAtsLength < bIndex)
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* Validate SFGI and FWI */
					if(pDataParams->bOpMode == RD_LIB_MODE_NFC)
					{
						/* For NFC, maximum SFGI shall be 8 */
						if(((pAts[bIndex - 1u] & 0x0FU) > 0x08U) || (((pAts[bIndex - 1u] & 0xF0U) >> 0x04U) > 0x08U))
						{
							return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
						}
					}
					else
					{
						/* SFGI shall be from 0 - 14 */
						if(((pAts[bIndex - 1u] & 0x0FU) > 0x0EU) || (((pAts[bIndex - 1u] & 0xF0U) >> 0x04U) > 0x0EU))
						{
							return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
						}
					}

					/* Update SFGI and FWI */
					pDataParams->bSfgi = (uint8)((uint8)pAts[bIndex - 1u] & 0x0FU);
					pDataParams->bFwi  = (uint8)(((uint8)(pAts[bIndex - 1u] & 0xF0U)) >> 0x04U);
				}

				/* Check TC(1) */
				if(0U != (pAts[PHPALI14443P4MC_T0_IDX] & 0x40U))
				{
					/* Increment length/index */
					bIndex++;

					/* Validate length */
					if(wAtsLength < bIndex)
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* Check RFU bits */
					if(0U != (pAts[bIndex - 1u] & 0xFCU))
					{
						return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
					}

					/* Check CID/DID support */
					if(0U != (pAts[bIndex - 1u] & 0x02U))
					{
						pDataParams->bCidEnable = 1u;
					}
					else
					{
						pDataParams->bCidEnable = 0u;
					}

					/* Check NAD support */
					if(0U != (pAts[bIndex - 1u] & 0x01U))
					{
						if(pDataParams->bOpMode == RD_LIB_MODE_NFC)
						{
							/* NAD is not supported by NFC */
							return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
						}
						pDataParams->bNadEnable = 1u;
					}
					else
					{
						pDataParams->bNadEnable = 0u;
					}
				}
			}

			/* Maximum supported historical bytes length is 15 for NFC */
			if(((pDataParams->bOpMode) == RD_LIB_MODE_NFC) && ((wAtsLength - bIndex) > 15U))
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
			}
			gbP4mCActState = PH_I14443P4MC_STATE_2;
			/* no break*/
		case PH_I14443P4MC_STATE_2:
			/* Send ATS */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
				pDataParams->pHalDataParams,
				PH_TRANSMIT_BUFFER_LAST,
				pAts,
				wAtsLength));
			gbP4mCActState = PH_I14443P4MC_STATE_1;
			PH_CHECK_SUCCESS(status);

			/* Set internal state */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_ATS;
			break;
		default:
			break;
	}
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Receive(
                    P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wOption,
                    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
									  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wConfig = 0u;
	static bool    PH_MEMLOC_REM bRxLoop = FALSE;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0u;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBackUpTxBuff[2] = {0u};
	static bool    PH_MEMLOC_REM bGetLen = TRUE;

	/* Used for Reception */
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPayloadLength = 0u;
  static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pPayloadResponse = NULL;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wHeaderLength = 0u;

	switch (gbP4mCReceiveState)
	{
		case PH_I14443P4MC_STATE_1:
			bRxLoop = FALSE;
			bGetLen = TRUE;
			wPayloadLength = 0u;
			pPayloadResponse = NULL;
			wHeaderLength = 0u;
			/* Validate receive option */
			if((wOption & (~((uint16)PH_RECEIVE_DEFAULT | (uint16)PH_RECEIVE_CHAINING
			   | (uint16)PH_RECEIVE_CHAINING_BUFSIZE))) != 0u)
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
			}

			/* If in chaining, sent ACK first */
			if(wOption == PH_RECEIVE_CHAINING)
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_Ack(pDataParams));
				PH_CHECK_SUCCESS(status);
			}
			else
			{
				/* Reset CID and NAD presence for current block to be received */
				pDataParams->bCidPresence = 0u;
				pDataParams->bNadPresence = 0u;
			}
			gbP4mCReceiveState = PH_I14443P4MC_STATE_2;
			/*no break*/

		case PH_I14443P4MC_STATE_2:
			/* Set receive loop condition */
			bRxLoop = TRUE;

			/* Be in receive mode, till successful receive */
			/* Start the first receive action */
			PH_CHECK_INPROCESS_FCT(status,
					phhalHw_Receive( pDataParams->pHalDataParams, PH_RECEIVE_DEFAULT, ppRxBuffer, pRxLength));

			/* Validate received frame and update state */
			if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS) {
				status = phpalI14443p4mC_Sw_Int_ValidateFrame(pDataParams,
						*ppRxBuffer, *pRxLength, &pPayloadResponse,
						&wPayloadLength);
			}

			/* After first receive change state from ATS to Receive to disable
			 * further PPS requests */
			if (pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_ATS)
			{
				pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_RX;
			}

			/* Exit on external RF off or buffer overflow */
			if (((status & PH_ERR_MASK) == PH_ERR_EXT_RF_ERROR)
					|| ((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW)) {
				/* Reset the position in case the PICC stopped abruptly due to RF OFF during chaining */
				(void) phhalHw_SetConfig(pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0);

				/* Application may reset HW and data parameters of all layers
				 * and may restart listen on RF off error */
				break;
			}

			if ((status & PH_ERR_MASK) != PH_ERR_SUCCESS) {
				return PH_STATUS_INPROCESS;
			}
			gbP4mCReceiveState = PH_I14443P4MC_STATE_3;
			/*no break*/
		case PH_I14443P4MC_STATE_3:
			/* Check what action to take based on state */
			switch(pDataParams->bStateNow)
			{
			case PHPAL_I14443P4MC_STATE_PPS:
				/* Validate PPS request and send PPS response */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_PpsRes(
					pDataParams,
					*ppRxBuffer,
					(uint8)*pRxLength));
				break;

			case PHPAL_I14443P4MC_STATE_RXCHAINING:
				/* Calculate header length */
				if (bGetLen == TRUE)
				{
					wHeaderLength = *pRxLength - wPayloadLength;
					bGetLen = FALSE;
				}

				/* Receive all the chained blocks */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_HandleRxChaining(
					pDataParams,
					wOption,
					ppRxBuffer,
					pRxLength));

				bGetLen = TRUE;
				/* Return error, if chaining is not success */
				if(((status & PH_ERR_MASK) != PH_ERR_SUCCESS_CHAINING)
					 && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS))
				{
					/* Reset the position in case the PICC stopped abruptly due to RF OFF during chaining */
					(void)phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RXBUFFER_STARTPOS, 0);
					break;
				}

				/* Update pay-load length */
				wPayloadLength = *pRxLength - wHeaderLength;

				/* Exit loop */
				bRxLoop = FALSE;
				break;

			case PHPAL_I14443P4MC_STATE_RESEND:
				/* Use the length of last block send as Tx buffer length.
				* Re-send last I block */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
					pDataParams->pHalDataParams,
					PH_TRANSMIT_PREV_FRAME,
					NULL,
					pDataParams->wLastTxLen));
				break;

			case PHPAL_I14443P4MC_STATE_TX_R:
				switch (gbP4mCStateTxR)
				{
					case PH_I14443P4MC_STATE_BACKUP:
						/*RAck is of 2-Bytes, Backup the contents of TxBuffer before sending ack*/
						for(bIndex = 0u; bIndex < 2u; bIndex ++)
						{
							status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, (uint16)bIndex);
							if(status == PH_ERR_SUCCESS)
							{
								/* Backup header byte  */
								status = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, &wConfig);
								if(status == PH_ERR_SUCCESS)
								{
									bBackUpTxBuff[bIndex] = (uint8) wConfig;
								}
							}
							PH_BREAK_ON_FAILURE(status);
						}
						gbP4mCStateTxR = PH_I14443P4MC_STATE_SEND;
						/*no break*/
					case PH_I14443P4MC_STATE_SEND:
						/* Send ACK and continue with receive */
						PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_Ack(pDataParams));
						PH_BREAK_ON_FAILURE(status);
						/*Restore the TxBuffer*/
						for(bIndex = 0u; bIndex < 2u ; bIndex ++)
						{
							/* Prepare access to byte position */
							status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER_OFFSET, (uint16)bIndex);
							if(status == PH_ERR_SUCCESS)
							{
								/* Restore the TxBuffer  */
								status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXBUFFER, (uint16) bBackUpTxBuff[bIndex]);
							}
							PH_BREAK_ON_FAILURE(status);
						}
						break;
				}
				gbP4mCStateTxR = PH_I14443P4MC_STATE_BACKUP;
				break;

			case PHPAL_I14443P4MC_STATE_DESELECT:
				/* Send S-Block DESELECT and exit */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_DslRes(pDataParams));
				/* Exit loop */
				bRxLoop = FALSE;
				break;

			case PHPAL_I14443P4MC_STATE_TX_I:
				/* Exit loop */
				bRxLoop = FALSE;
				 break;

			default:
				/* Exit loop */
				bRxLoop = FALSE;
				break;
			}
			PH_BREAK_ON_FAILURE(status);
			if (bRxLoop == TRUE)
			{
				gbP4mCReceiveState = PH_I14443P4MC_STATE_2;
				return PH_STATUS_INPROCESS;
			}

			/* Return DESELECTED if state is NONE. State will be NONE after DESELECT */
			if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_NONE)
			{
				status = PH_ERR_SUCCESS_DESELECTED | PH_COMP_PAL_I14443P4MC;
				break;
			}


			/* Start WTX timer, if I-Block */
			if(((pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_TX_I)
				|| (pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_RXCHAINING))
				&& (pDataParams->bDisableWtx == 0x00u))
			{
				PH_CHECK_FAILURE_FCT(status, phpalI14443p4mC_Sw_Int_StartWtxTimer(pDataParams));
			}


			/* Update pay-load, if reception is success */
			*ppRxBuffer = pPayloadResponse;
			*pRxLength  = wPayloadLength;

			/* Return success chaining, if returning in between chaining */
			if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_RXCHAINING)
			{
				status = PH_ERR_SUCCESS_CHAINING | PH_COMP_PAL_I14443P4MC;
			}
			break;
		default:
			break;
	}
	gbP4mCReceiveState = PH_I14443P4MC_STATE_1;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Transmit(
                     P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                     VAR(uint16, ANFCRL_VAR) wOption,
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                     VAR(uint16, ANFCRL_VAR) wTxLength
									   )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	/* Used for exchange */
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxSent = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bForceSend;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aSoD[3] = {0};
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSoDLen = 1U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxCopyBytes;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxFrameBytes;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBuffBytes;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTransmit = 0U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTxBufferSize;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPrologueField;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNadInclude;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bBytePos;

	/* Used for exchange */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuffer = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRxLength = 0U;

	switch (gbP4mCTransmitState)
	{
		case PH_I14443P4MC_STATE_1:
			wTxSent = 0U;
			wSoDLen = 1U;
			bTransmit = 0U;
			/* Validate transmit option */
			if ((wOption &  (uint16)~(uint16)(PH_TRANSMIT_BUFFERED_BIT
				| PH_TRANSMIT_LEAVE_BUFFER_BIT | PH_TRANSMIT_TXCHAINING)) != 0u)
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
			}

			/* Retrieve HAL TX buffer size */
			PH_CHECK_SUCCESS_FCT(status, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE,
				&wTxBufferSize));
			gbP4mCTransmitState = PH_I14443P4MC_STATE_2;
			/*no break*/
		case PH_I14443P4MC_STATE_2:
			   /* Stop WTX Timer */
				if(0U == (pDataParams->bDisableWtx))
				{
					/*PH_CHECK_FAILURE_FCT(status, phDriver_TimerStop());*/
					pDataParams->bWtxTimerSts = PHPAL_I14443P4MC_WTX_TIMER_IDLE;
				}

				if (0U != (wOption & PH_EXCHANGE_LEAVE_BUFFER_BIT))
				{
					/* See if there is anything cached already in the buffer */
					PH_CHECK_FAILURE_FCT(status, phhalHw_GetConfig(
						pDataParams->pHalDataParams,
						PHHAL_HW_CONFIG_TXBUFFER_LENGTH,
						&wTxBuffBytes));
				}
				else
				{
					wTxBuffBytes = 0;
				}

				/* If zero, we have new frame */
				if (wTxBuffBytes == 0U)
				{
					/* In case of chaining, NAD shall be present only in first block */
					bNadInclude = (uint8)((wTxSent == 0U)? PH_ON : PH_OFF);

					/* Get header length */
					PH_CHECK_FAILURE_FCT(status, phpalI14443p4mC_Sw_Int_GetPduHeaderLength(
						pDataParams,
						bNadInclude,
						(uint8 *)&wSoDLen));
				}
				gbP4mCTransmitState = PH_I14443P4MC_STATE_3;
				/* no break */

		case PH_I14443P4MC_STATE_3:
			/* If zero, we have new frame */
			if (wTxBuffBytes == 0U)
			{
				/* Put the new SoD into TX buffer */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
					pDataParams->pHalDataParams,
					PH_TRANSMIT_BUFFER_FIRST,
					aSoD,
					wSoDLen));
				PH_BREAK_ON_FAILURE(status);
			}
			/* Find the biggest possible frame size before chaining is needed. */
			wTxFrameBytes = (wTxBufferSize < (aI14443p4mC_FsTable[pDataParams->bFsdi] - wSoDLen)) ?
				wTxBufferSize : (aI14443p4mC_FsTable[pDataParams->bFsdi] - wSoDLen);

			/* Calculate how much space we have left */
			wTxFrameBytes = wTxFrameBytes - wTxBuffBytes;

			/* Check if must force send and/or chaining */
			bForceSend = 0u;

			if((wTxLength - wTxSent) > wTxFrameBytes)
			{
				wTxCopyBytes = wTxFrameBytes;

				bForceSend = 1u;
				pDataParams->bChainingTx = 1u;
				pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TXCHAINING;
			}
			else
			{
				wTxCopyBytes = (wTxLength - wTxSent);
				bTransmit = 0u;
				if(0U != (wOption & PH_TRANSMIT_TXCHAINING))
				{
					bForceSend = 1u;
					pDataParams->bChainingTx = 1u;
					pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TXCHAINING;
				}
				else
				{
					pDataParams->bChainingTx = 0u;
					pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TX_I;
				}
			}
			/* Buffer if requested and not filling up the max frame */
			if ((bForceSend == 0x00u) && (0U != ((wOption & PH_EXCHANGE_BUFFERED_BIT))))
			{
				gbP4mCTransmitState = PH_I14443P4MC_STATE_4;
			}
			else
			{
				gbP4mCTransmitState = PH_I14443P4MC_STATE_5;
				return PH_STATUS_INPROCESS;
			}
			/*no break*/
		case PH_I14443P4MC_STATE_4:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
								pDataParams->pHalDataParams,
								PH_TRANSMIT_BUFFER_CONT,
								&pTxBuffer[wTxSent],
								wTxCopyBytes));
			break;
		case PH_I14443P4MC_STATE_5:
			/* Build I block SoD */
			aSoD[0] = PHPALI14443P4MC_BLOCK_I | pDataParams->bBlockNr;

			/* Are we chaining */
			if (0U != (pDataParams->bChainingTx))
			{
				aSoD[0] = aSoD[0] | PHPALI14443P4MC_BLOCK_IS_CHAIN;
			}

			/* Add CID */
			if(0U != (pDataParams->bCidPresence))
			{
				/* Set CID following bit in PCB */
				aSoD[0] = aSoD[0] | PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING;

				/* Set CID byte */
				aSoD[1] = pDataParams->bCid;

				/* Put CID to correct place */
				PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXBUFFER_OFFSET,
					0x01));
				PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXBUFFER,
					(uint16)aSoD[1]));
			}

			/* Add NAD (if chaining, add only for first block of chaining) */
			if((pDataParams->bNadPresence != 0x00u) && (wTxSent == 0U))
			{
				/* Set NAD following bit in PCB */
				aSoD[0] = aSoD[0] | PHPAL_I14443P4MC_SW_PCB_NAD_FOLLOWING;

				/* Get NAD position in header */
				bBytePos = (pDataParams->bCidPresence == 1u)? 2u: 1u;

				/* Set NAD byte */
				aSoD[bBytePos] = pDataParams->bNad;

				/* Put NAD to correct place */
				PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXBUFFER_OFFSET,
					bBytePos));
				PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
					pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_TXBUFFER,
					(uint16)aSoD[bBytePos]));
			}

			/* Put PCB to correct place */
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TXBUFFER_OFFSET,
				0x00));

			/* Set PCB value in TX buffer */
			PH_CHECK_FAILURE_FCT(status, phhalHw_SetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TXBUFFER,
				(uint16)aSoD[0]));

			/* Get header length */
			PH_CHECK_FAILURE_FCT(status, phhalHw_GetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_TXBUFFER_LENGTH,
				&wPrologueField));

			/* Backup total TX length (needed in case of error, to re-send) */
			pDataParams->wLastTxLen = wTxCopyBytes + wPrologueField;

			gbP4mCTransmitState = PH_I14443P4MC_STATE_6;
			/*no break*/

		case PH_I14443P4MC_STATE_6:
			/* Transmit data */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
				pDataParams->pHalDataParams,
				PH_TRANSMIT_BUFFER_LAST,
				&pTxBuffer[wTxSent],
				wTxCopyBytes));
			PH_BREAK_ON_FAILURE(status);
			/* Perform the exchange, in case of chaining */
			if (0U != (pDataParams->bChainingTx))
			{
				gbP4mCTransmitState = PH_I14443P4MC_STATE_7;
			}
			else
			{
				/* Exit the loop */
				bTransmit = 0;
				break;
			}
			/*no break*/

		case PH_I14443P4MC_STATE_7:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Receive(
				 pDataParams->pHalDataParams,
				 PH_RECEIVE_DEFAULT,
				 &pRxBuffer,
				 &wRxLength));

			 if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
			 {
				 /* Validate frame */
				 status = phpalI14443p4mC_Sw_Int_ValidateFrame(
					 pDataParams,
					 pRxBuffer,
					 wRxLength,
					 NULL,
					 NULL);

				 if(((status & PH_ERR_MASK) == PH_ERR_SUCCESS) &&
					 (pDataParams->bStateNow != PHPAL_I14443P4MC_STATE_RESEND))
				 {
				  if (pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_TX_R)
				   {
					  gbP4mCTransmitState = PH_I14443P4MC_STATE_9;
					  return PH_STATUS_INPROCESS;
					}
				   else
					{
					  /* Update the number of bytes send */
					   wTxSent = wTxSent + wTxCopyBytes;
					}

					/* Set Exit option */
					if((wTxSent == wTxLength) && (0U != ((wOption & PH_TRANSMIT_TXCHAINING))))
					{
					 /* Exit the loop */
					 bTransmit = 0;
					}
					else
					{
					 /* Continue TX chaining */
					 bTransmit = 1;
					}
				 }
				 gbP4mCTransmitState = PH_I14443P4MC_STATE_8;
			 }
			 else if(((status & PH_ERR_MASK) == PH_ERR_EXT_RF_ERROR)
				  || ((status & PH_ERR_MASK) == PH_ERR_BUFFER_OVERFLOW))
			 {
				 /* Application may reset HW and data parameters of all layers
				  * and may restart listen on RF off error */
				 break;
			 }
			 else
			 {
				 /* Continue in receive mode */
			 }
			 return PH_STATUS_INPROCESS;
		case PH_I14443P4MC_STATE_8:
			/* Re-send last I-Block */
			if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_RESEND)
			{
				 /* Use the length of last block send as Tx buffer length
				 * Re-send last I block */
				 PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
					 pDataParams->pHalDataParams,
					 PH_TRANSMIT_PREV_FRAME,
					 NULL,
					 pDataParams->wLastTxLen));
				 PH_BREAK_ON_FAILURE(status);
			}
			if (pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_RESEND)
			{
				gbP4mCTransmitState = PH_I14443P4MC_STATE_7;
			}
			else if (0U != bTransmit)
			{
				gbP4mCTransmitState = PH_I14443P4MC_STATE_2;
			}
			else
			{
				break;
			}
			return PH_STATUS_INPROCESS;
		case PH_I14443P4MC_STATE_9:
			/* Send ACK and continue with receive */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Int_Ack(pDataParams));
			PH_BREAK_ON_FAILURE(status);
			/* Set the next state to TxChaining to have correct checks in phpalI14443p4mC_Sw_Int_ValidateFrame. */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_TXCHAINING;
			/* Enter into Receive by corrupting status. */
			gbP4mCTransmitState = PH_I14443P4MC_STATE_7;
			return PH_STATUS_INPROCESS;

	}

	gbP4mCTransmitState = PH_I14443P4MC_STATE_1;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Wtx(
                  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM aCmd[3];
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWtxReqLength = 2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pWtxResp = NULL;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wWtxRespLength = 0;

	switch (gbP4mCWtxState)
	{
		case PH_I14443P4MC_STATE_1:
			aCmd[0] = PHPAL_I14443P4MC_SW_S_BLOCK_WTX_FRAME;
			wWtxReqLength = 2U;
			/* Add CID if enabled */
			if (0U != (pDataParams->bCidPresence))
			{
				aCmd[0] |= PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING;
				aCmd[1] = pDataParams->bCid;
				wWtxReqLength++;
			}
			aCmd[wWtxReqLength - 1u] = pDataParams->bWtx;

			/* Backup TX length (needed in case of error, to re-send) */
			pDataParams->wLastTxLen = wWtxReqLength;
			gbP4mCWtxState = PH_I14443P4MC_STATE_2;
			/* no break */
		case PH_I14443P4MC_STATE_2:
			/* Send WTX request */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Transmit(
				pDataParams->pHalDataParams,
				PH_TRANSMIT_LEAVE_BUFFER_BIT,
				&aCmd[0],
				wWtxReqLength));
			PH_BREAK_ON_FAILURE(status);
			/* Update state */
			pDataParams->bStateNow = PHPAL_I14443P4MC_STATE_WTX;
			gbP4mCWtxState = PH_I14443P4MC_STATE_3;
			return PH_STATUS_INPROCESS;
		case PH_I14443P4MC_STATE_3:
			/* Receive WTX response */
			PH_CHECK_INPROCESS_FCT(status, phpalI14443p4mC_Sw_Receive(
				pDataParams,
				PH_RECEIVE_DEFAULT,
				&pWtxResp,
				&wWtxRespLength));
			break;
		default:
			break;
	}
	gbP4mCWtxState = PH_I14443P4MC_STATE_1;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_SetConfig(
                    P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    VAR(uint16, ANFCRL_VAR) wValue
										)
{
	switch(wConfig)
	{
	case PHPAL_I14443P4MC_CONFIG_WTX:
		if((wValue != PH_ON) && (wValue != PH_OFF))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
		}
		pDataParams->bDisableWtx = (uint8)(wValue ^ 0x0001U);
		break;

	case PHPAL_I14443P4MC_CONFIG_WTX_VALUE:
		if((wValue < PHPAL_I14443P4MC_SW_MIN_WTX_VALUE) || (wValue > PHPAL_I14443P4MC_SW_MAX_WTX_VALUE))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
		}
		pDataParams->bWtx = (uint8)(wValue);
		break;

	case PHPAL_I14443P4MC_CONFIG_MODE:
		if((wValue !=  RD_LIB_MODE_ISO) && (wValue != RD_LIB_MODE_NFC))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
		}
		pDataParams->bOpMode = (uint8)(wValue);
		break;

	case PHPAL_I14443P4MC_CONFIG_WT_PERCENTAGE:
		if((wValue > 100U) || (wValue < 10U))
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
		}
		pDataParams->bWtPercentage = (uint8)(wValue);
		break;

	case PHPAL_I14443P4MC_CONFIG_WT_DELTA:
		if(pDataParams->bStateNow == PHPAL_I14443P4MC_STATE_NONE)
		{
			return (PH_ERR_USE_CONDITION | PH_COMP_PAL_I14443P4MC);
		}

		if((((PHPAL_I14443P4MC_SW_CALCULATE_FWT_US(pDataParams->bFwi))
		   * pDataParams->bWtPercentage
		   * pDataParams->bWtx) / 100u) <  wValue)
		{
			return (PH_ERR_INVALID_PARAMETER | PH_COMP_PAL_I14443P4MC);
		}
		pDataParams->wWtDelta = wValue;
		break;

	default:
		return (PH_ERR_UNSUPPORTED_PARAMETER | PH_COMP_PAL_I14443P4MC);
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_GetConfig(
                    P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
										)
{
	switch(wConfig)
	{
	case PHPAL_I14443P4MC_CONFIG_WTX:
		*pValue = (uint16)pDataParams->bDisableWtx ^ 0x0001U;
		break;

	case PHPAL_I14443P4MC_CONFIG_BLOCKNO:
		*pValue = (uint16)(pDataParams->bBlockNr);
		break;

	case PHPAL_I14443P4MC_CONFIG_FSDI:
		*pValue = (uint16)(pDataParams->bFsdi);
		break;

	case PHPAL_I14443P4MC_CONFIG_FSD:
		*pValue = (uint16)aI14443p4mC_FsTable[pDataParams->bFsdi];
		break;

	case PHPAL_I14443P4MC_CONFIG_MODE:
		*pValue = (uint16)(pDataParams->bOpMode);
		break;

	case PHPAL_I14443P4MC_CONFIG_WT_PERCENTAGE:
		*pValue = (uint16)(pDataParams->bWtPercentage);
		break;

	case PHPAL_I14443P4MC_CONFIG_WT_DELTA:
		*pValue = (uint16)(pDataParams->wWtDelta);
		break;

	case PHPAL_I14443P4MC_CONFIG_CID_PRESENCE:
		*pValue = (uint16)(pDataParams->bCidPresence);
		break;

	case PHPAL_I14443P4MC_CONFIG_NAD_PRESENCE:
		*pValue = (uint16)(pDataParams->bNadPresence);
		break;

	default:
		return (PH_ERR_UNSUPPORTED_PARAMETER | PH_COMP_PAL_I14443P4MC);
	}

	return PH_ERR_SUCCESS;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

#ifdef __cplusplus
}
#endif
