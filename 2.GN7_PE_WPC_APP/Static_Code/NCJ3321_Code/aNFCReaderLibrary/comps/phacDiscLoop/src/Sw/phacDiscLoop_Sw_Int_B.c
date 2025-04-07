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
*   @file    phacDiscLoop_Sw_Int_B.c
*   @version 1.0.0
*
*   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop Discovery Loop
*   @ingroup phac
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
#include <phacDiscLoop.h>
#include <phpalI14443p3b.h>
#include <phpalI14443p4.h>
#include <phTools.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw_Int.h"
#include "phacDiscLoop_Sw_Int_B.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_B.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_B_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_B.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_B_VENDOR_ID_C != PHACDISCLOOP_SW_INT_B_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int_B.c and phacDiscLoop_Sw_Int_B.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_B.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_B.c and phacDiscLoop_Sw_Int_B.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_B.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_B.c and phacDiscLoop_Sw_Int_B.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeB(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus;

	wStatus = phhalHw_Exchange_GetStatus();
	if ((wStatus == PH_ERR_IO_TIMEOUT) || (wStatus == PH_ERR_SUCCESS)) {
		pDataParams->sTypeBTargetInfo.bAfiReq = 0x00;
		pDataParams->sTypeBTargetInfo.bTotalTagsFound = 0;
		pDataParams->bCollPend &=
				(uint8) ~(uint8) PHAC_DISCLOOP_POS_BIT_MASK_B;
	}
	/* WakeupB with number of slot as 0 */
	PH_CHECK_INPROCESS_FCT(wStatus,
			phpalI14443p3b_WakeUpB(pDataParams->pPal1443p3bDataParams, 0,
					pDataParams->sTypeBTargetInfo.bAfiReq,
					pDataParams->sTypeBTargetInfo.bExtendedAtqBbit,
					pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].aAtqB,
					&pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].bAtqBLength));

	if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus(wStatus))) {
		if ((wStatus & PH_ERR_MASK) != PH_ERR_SUCCESS) {
			pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_B;
		}
		pDataParams->sTypeBTargetInfo.bTotalTagsFound++;
	}
	else
	{
		return wStatus;
	}

	return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_TECH_DETECTED,
			PH_COMP_AC_DISCLOOP);
#else
	PH_UNUSED_VARIABLE(pDataParams);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionB(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
  static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCurrentSlotNum = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCurrentDeviceCount = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bNumOfSlots = 0U;

	switch(pDataParams->bCollResBState){
		case ColResolB_Start:
			/* Collision_Pending = 1 and Device limit  = 0 */
			if ((0U != ((pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_B)))
					&& ((pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_B]
							== 0x00U))) {
				pDataParams->sTypeBTargetInfo.bTotalTagsFound = 0;
				return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED,
						PH_COMP_AC_DISCLOOP);
			}

			/* Symbol 0 */
			bNumOfSlots = 0;

			/* Send WUPB if we support NFC Activity 1.1 or EMVCo mode */
			if ((pDataParams->bOpeMode != RD_LIB_MODE_NFC) || (pDataParams->bNfcActivityVersion != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_0))
			{
				/* Apply Guard time. */
				PH_CHECK_SUCCESS_FCT(status,
						phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US, pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_B]));
			}
			pDataParams->bCollResBState = ColResolB_AppProtocol;
			/*no break*/
		case ColResolB_AppProtocol:
			/* Configure HW for the TypeB technology */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings( pDataParams->pHalDataParams, PHHAL_HW_CARDTYPE_ISO14443B));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->bCollResBState = ColResolB_Symbol1;
			/*no break*/
		case ColResolB_Symbol1:
			/* If supporting Activity 1.0, update status based on detection phase */
			if ((pDataParams->bOpeMode == RD_LIB_MODE_NFC)
					&& (pDataParams->bNfcActivityVersion
							== PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_0)) {
				/* Applying Tx Wait saved according to the TR value of ATQb as apply protocol restores default */
				PH_CHECK_INPROCESS_FCT(status,
						phhalHw_SetConfig( pDataParams->pHalDataParams, PHHAL_HW_CONFIG_TXWAIT_US, ((phpalI14443p3b_Sw_DataParams_t*)(pDataParams->pPal1443p3bDataParams))->wTxWait));
				PH_BREAK_ON_FAILURE(status);
				if (0U != (pDataParams->sTypeBTargetInfo.bTotalTagsFound)) {
					status = PH_ERR_SUCCESS;
				}

				if (0U != (pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_B)) {
					status = PH_ERR_COLLISION_ERROR;
				}
			}
			/* Send WUPB if we support NFC Activity 1.1 or EMVCo mode */
			else {
				/* WakeupB with number of slot as 0 */
				PH_CHECK_INPROCESS_FCT(status,
						phpalI14443p3b_WakeUpB(pDataParams->pPal1443p3bDataParams,
								bNumOfSlots, pDataParams->sTypeBTargetInfo.bAfiReq,
								pDataParams->sTypeBTargetInfo.bExtendedAtqBbit,
								pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].aAtqB,
								&pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].bAtqBLength));

			}
			/* Symbol 3 */
			if(PH_ERR_SUCCESS != (status & PH_ERR_MASK))
			{
				/* Symbol 2 */
				/* No Response */
				if((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
				{
					break;	/*branch "No" of symbol 2*/
				}
				else
				{ /* Symbol 4 */
					if((pDataParams->baPasConDevLim[1] == 0x00U))
					{
						pDataParams->sTypeBTargetInfo.bTotalTagsFound = 0;
						/* Symbol 24 */
						pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_B;
						break;
					}
				}
			}

			pDataParams->bCollResBState = ColResolB_Symbol5;
			return PH_STATUS_INPROCESS;
			/*no break*/
		case ColResolB_Symbol5:
			/* Symbol 5 */
			bCurrentSlotNum = 0;
			bCurrentDeviceCount = 0;
			pDataParams->sTypeBTargetInfo.bTotalTagsFound = 0;
			pDataParams->bCollPend &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_B;
			pDataParams->bCollResBState = ColResolB_Symbol6;
			/*no break*/
		case ColResolB_Symbol6:
			/* Symbol 6: Slot is Empty */
			if ((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT) {
				/* Symbol 7: Validate SENSB_RES */
				if (status == PH_ERR_SUCCESS) {
					/* Symbol 9 */
					if ((pDataParams->bNfcActivityVersion
							== PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1)
							&& (bCurrentDeviceCount > 0U)) {
						/* Symbol 10 */
						status = phpalI14443p3b_SetSerialNo(pDataParams->pPal1443p3bDataParams,
								pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound - (uint8) 1U].aPupi);
					}
					pDataParams->bCollResBState = ColResolB_Symbol10;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					/* Symbol 8 CollisionPend: 1*/
					pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_B;
				}
			}
			pDataParams->bCollResBState = ColResolB_Symbol14; /*Jump to state Symbol14*/
			return PH_STATUS_INPROCESS;

		case ColResolB_Symbol10:
			/* Symbol 10 */
			if ((pDataParams->bNfcActivityVersion == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1) && (bCurrentDeviceCount > 0U))
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_HaltB(pDataParams->pPal1443p3bDataParams));
				if (status == PH_ERR_ABORTED) {
					break; /*Finish, return ABORTED*/
				}
			}
			/* Symbol 12 */
			(void)memcpy(pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].aPupi,
				&pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].aAtqB[1],
				PHAC_DISCLOOP_I3P3B_PUPI_LENGTH);

			/* Symbol 11 */
			pDataParams->sTypeBTargetInfo.bTotalTagsFound++;
			bCurrentDeviceCount++;

			/* Symbol 13 */
			if (pDataParams->sTypeBTargetInfo.bTotalTagsFound >= pDataParams->baPasConDevLim[1])
			{
				pDataParams->bNumOfCards = pDataParams->sTypeBTargetInfo.bTotalTagsFound;

				status = PH_ERR_SUCCESS; /*Finish, return PH_ERR_SUCCESS*/
				break;
			}
			pDataParams->bCollResBState = ColResolB_Symbol10A;
			/*no break*/
		case ColResolB_Symbol10A:
			if(pDataParams->bNfcActivityVersion == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_0)
			{
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_HaltB(pDataParams->pPal1443p3bDataParams));
				if (status == PH_ERR_ABORTED) {
					break; /*Finish, return ABORTED*/
				}
			}
			pDataParams->bCollResBState = ColResolB_Symbol14;
			/*no break*/
		case ColResolB_Symbol14:
			/* Symbol 14 */
			bCurrentSlotNum++;
			/* Symbol 15 */
			if (bCurrentSlotNum < ((uint8) 1U << bNumOfSlots)) {
				pDataParams->bCollResBState = ColResolB_Symbol25; /*Jump to state Symbol25*/
			}
			else
			{
				/* Symbol 16 */
				if (0U != (pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_B))
				{
					/* Symbol 17 */
					if (pDataParams->sTypeBTargetInfo.bTotalTagsFound > 0U)
					{
						/* Symbol 20 */
						if ((pDataParams->sTypeBTargetInfo.bTotalTagsFound >= pDataParams->baPasConDevLim[1])
								|| (pDataParams->sTypeBTargetInfo.bTotalTagsFound >= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED))
						{
							pDataParams->bNumOfCards = pDataParams->sTypeBTargetInfo.bTotalTagsFound;
							status = PH_ERR_SUCCESS;
							break;
						}
					}
					else
					{
						/* Symbol 18 */
						if (bNumOfSlots == PHAC_DISCLOOP_TYPEB_MAX_SLOT_NUM)
						{
							pDataParams->bNumOfCards = pDataParams->sTypeBTargetInfo.bTotalTagsFound;
							if (pDataParams->sTypeBTargetInfo.bTotalTagsFound == 0U)
							{
								status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
							}
							else
							{
								status = PH_ERR_SUCCESS;
							}
							break;
						}
						/* Symbol 19 */
						bNumOfSlots++;
					}
					pDataParams->bCollResBState = ColResolB_Symbol21;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					/*Finish and return status*/
					pDataParams->bNumOfCards = pDataParams->sTypeBTargetInfo.bTotalTagsFound;
					if (pDataParams->sTypeBTargetInfo.bTotalTagsFound == 0U)
					{
						status = (PHAC_DISCLOOP_NO_DEVICE_RESOLVED | PH_COMP_AC_DISCLOOP);
					}
					else
					{
						status = PH_ERR_SUCCESS;
					}
					break;
				}
			}
			/*no break*/
		case ColResolB_Symbol25:
			/* Symbol 25 */
			PH_CHECK_INPROCESS_FCT(status,
					phpalI14443p3b_SlotMarker(
							pDataParams->pPal1443p3bDataParams,
							(bCurrentSlotNum + 1U),
							pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].aAtqB,
							&pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].bAtqBLength));
			if (status == PH_ERR_ABORTED) {
				break;
			}
			pDataParams->bCollResBState = ColResolB_Symbol6; /*Jump to state Symbol6*/
			return PH_STATUS_INPROCESS;

		case ColResolB_Symbol21:
			/* Symbol 21 */
			if (bCurrentDeviceCount > 0U)
			{
				/* Symbol 22 */
				PH_CHECK_INPROCESS_FCT(status, phpalI14443p3b_HaltB(pDataParams->pPal1443p3bDataParams));
				if (status == PH_ERR_ABORTED)
				{
					break;
				}
			}
			/* Symbol 23 */
			pDataParams->bCollResBState = ColResolB_Symbol23;
			/*no break*/
		case ColResolB_Symbol23:
			/* Symbol 23 */
			PH_CHECK_INPROCESS_FCT(status,
					phpalI14443p3b_RequestB(pDataParams->pPal1443p3bDataParams, bNumOfSlots, pDataParams->sTypeBTargetInfo.bAfiReq,
							pDataParams->sTypeBTargetInfo.bExtendedAtqBbit,
							pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].aAtqB,
							&pDataParams->sTypeBTargetInfo.aTypeB_I3P3[pDataParams->sTypeBTargetInfo.bTotalTagsFound].bAtqBLength));
			if (status == PH_ERR_ABORTED)
			{
				break;
			}
			pDataParams->bCollResBState = ColResolB_Symbol5;
			return PH_STATUS_INPROCESS;
	}
	pDataParams->bCollResBState = ColResolB_Start;
	return PH_ADD_COMPCODE(status, PH_COMP_AC_DISCLOOP);
#else
	PH_UNUSED_VARIABLE(pDataParams);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateB(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bTypeBTagIdx) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bAtqbLen = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aAtqb[13] = {0U};
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCidEnabled = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCid = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNadSupported = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFwi = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFsdi = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bFsci = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS */

	/* Only deviation form Device Activation Activity is
	 * Device sleep state is not been check and always send WakeUpB Command
	 */
	if (bTypeBTagIdx >= pDataParams->sTypeBTargetInfo.bTotalTagsFound) {
		/* Out of range or no such card found yet */
		return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER,
				PH_COMP_AC_DISCLOOP);
	}

	/* Send WUPB for tags in sleep state (except the last detected tag all are in sleep state) */
	if (pDataParams->bDiscLoopActivateBState == 0U) {
		PH_CHECK_INPROCESS_FCT(status,
				phpalI14443p3b_WakeUpB(pDataParams->pPal1443p3bDataParams, 0x00,
						pDataParams->sTypeBTargetInfo.bAfiReq,
						pDataParams->sTypeBTargetInfo.bExtendedAtqBbit, aAtqb,
						&bAtqbLen));
		if (status == PH_ERR_ABORTED) {
			return status;
		}
		pDataParams->bDiscLoopActivateBState = 1U;
	}
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS
	/* AttribB: activate PICC */
	if (pDataParams->bDiscLoopActivateBState == 1U) {
		/* Enable Emd check in Emvco. */
		if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO) {
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams,
					PHHAL_HW_CONFIG_SET_EMD, PH_ON));
			if (status != PH_ERR_SUCCESS) {
				pDataParams->bDiscLoopActivateBState = 0U;
				return status;
			}
		}

		pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].bSupportType4B =
				PH_OFF;
		if (0u
				!= ((pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].aAtqB[PHAC_DISCLOOP_TYPEB_PROTOCOL_TYPE_OFFSET]
						& PHAC_DISCLOOP_TYPEB_MASK_PROTOCOL_TYPE))) {
			pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].bSupportType4B =
					PH_ON;
		}

		if ((pDataParams->bOpeMode == RD_LIB_MODE_ISO)
				&& (pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].bSupportType4B
						== PH_OFF)) {
			pDataParams->bDiscLoopActivateBState = 0U;
			return PH_ERR_SUCCESS;
		}
		pDataParams->bDiscLoopActivateBState = 2U;
		return PH_STATUS_INPROCESS;
	}

	if (pDataParams->bDiscLoopActivateBState == 2U) {
		PH_CHECK_INPROCESS_FCT(status,
				phpalI14443p3b_Attrib(pDataParams->pPal1443p3bDataParams,
						pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].aAtqB,
						pDataParams->sTypeBTargetInfo.aTypeB_I3P3[bTypeBTagIdx].bAtqBLength,
						pDataParams->sTypeBTargetInfo.bFsdi,
						pDataParams->sTypeBTargetInfo.bCid,
						pDataParams->sTypeBTargetInfo.bDri,
						pDataParams->sTypeBTargetInfo.bDsi,
						&pDataParams->sTypeBTargetInfo.sTypeB_I3P4.bMbli));
		pDataParams->bDiscLoopActivateBState = 0U;
		if (status != PH_ERR_SUCCESS) {
			return status;
		}

		/* Retrieve 14443-3b protocol parameter */
		status = phpalI14443p3b_GetProtocolParams(
				pDataParams->pPal1443p3bDataParams, &bCidEnabled, &bCid,
				&bNadSupported, &bFwi, &bFsdi, &bFsci);
		if (status != PH_ERR_SUCCESS) {
			return status;
		}

		/* Set 14443-4 protocol parameter */
		status = phpalI14443p4_SetProtocol(pDataParams->pPal14443p4DataParams,
				bCidEnabled, bCid, bNadSupported,
				pDataParams->sTypeBTargetInfo.bNad, bFwi, bFsdi, bFsci);
	}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS */
	return status;
#else
	PH_UNUSED_VARIABLE(pDataParams);
	PH_UNUSED_VARIABLE(bTypeBTagIdx);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif
