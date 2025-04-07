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
*   @file    phacDiscLoop_Sw_Int_B2.c
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
#include <ph_RefDefs2.h>
#include <phacDiscLoop2.h>
#include <phpalI14443p3b2.h>
#include <phpalI14443p42.h>
#include <phTools2.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw_Int2.h"
#include "phacDiscLoop_Sw_Int_B2.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_B2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_B_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_B2.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_B_VENDOR_ID_C2 != PHACDISCLOOP_SW_INT_B_VENDOR_ID2)
    #error "phacDiscLoop_Sw_Int_B2.c and phacDiscLoop_Sw_Int_B2.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_B2.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_INT_B_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_B2.c and phacDiscLoop_Sw_Int_B2.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_B2.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_INT_B_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_INT_B_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_INT_B_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_B2.c and phacDiscLoop_Sw_Int_B2.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
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
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeB2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2;

	wStatus2 = phhalHw_Exchange_GetStatus2();
	if ((wStatus2 == PH_ERR_IO_TIMEOUT2) || (wStatus2 == PH_ERR_SUCCESS2)) {
		pDataParams2->sTypeBTargetInfo2.bAfiReq2 = 0x00;
		pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 = 0;
		pDataParams2->bCollPend2 &=
				(uint8) ~(uint8) PHAC_DISCLOOP_POS_BIT_MASK_B2;
	}
	/* WakeupB with number of slot as 0 */
	PH_CHECK_INPROCESS_FCT2(wStatus2,
			phpalI14443p3b_WakeUpB2(pDataParams2->pPal1443p3bDataParams2, 0,
					pDataParams2->sTypeBTargetInfo2.bAfiReq2,
					pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2,
					pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].aAtqB2,
					&pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].bAtqBLength2));

	if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus2(wStatus2))) {
		if ((wStatus2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2) {
			pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_B2;
		}
		pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2++;
	}
	else
	{
		return wStatus2;
	}

	return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_TECH_DETECTED2,
			PH_COMP_AC_DISCLOOP2);
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionB2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
  static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCurrentSlotNum2 = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCurrentDeviceCount2 = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bNumOfSlots2 = 0U;

	switch(pDataParams2->bCollResBState2){
		case ColResolB_Start2:
			/* Collision_Pending = 1 and Device limit  = 0 */
			if ((0U != ((pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_B2)))
					&& ((pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_B2]
							== 0x00U))) {
				pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 = 0;
				return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2,
						PH_COMP_AC_DISCLOOP2);
			}

			/* Symbol 0 */
			bNumOfSlots2 = 0;

			/* Send WUPB if we support NFC Activity 1.1 or EMVCo mode */
			if ((pDataParams2->bOpeMode2 != RD_LIB_MODE_NFC2) || (pDataParams2->bNfcActivityVersion2 != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02))
			{
				/* Apply Guard time. */
				PH_CHECK_SUCCESS_FCT2(status2,
						phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2, pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_B2]));
			}
			pDataParams2->bCollResBState2 = ColResolB_AppProtocol2;
			/*no break*/
		case ColResolB_AppProtocol2:
			/* Configure HW for the TypeB technology */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2( pDataParams2->pHalDataParams2, PHHAL_HW_CARDTYPE_ISO14443B2));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->bCollResBState2 = ColResolB_Symbol12;
			/*no break*/
		case ColResolB_Symbol12:
			/* If supporting Activity 1.0, update status2 based on detection phase */
			if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2)
					&& (pDataParams2->bNfcActivityVersion2
							== PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02)) {
				/* Applying Tx Wait saved according to the TR value of ATQb as apply protocol restores default */
				PH_CHECK_INPROCESS_FCT2(status2,
						phhalHw_SetConfig2( pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_TXWAIT_US2, ((phpalI14443p3b_Sw_DataParams_t2*)(pDataParams2->pPal1443p3bDataParams2))->wTxWait2));
				PH_BREAK_ON_FAILURE2(status2);
				if (0U != (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2)) {
					status2 = PH_ERR_SUCCESS2;
				}

				if (0U != (pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_B2)) {
					status2 = PH_ERR_COLLISION_ERROR2;
				}
			}
			/* Send WUPB if we support NFC Activity 1.1 or EMVCo mode */
			else {
				/* WakeupB with number of slot as 0 */
				PH_CHECK_INPROCESS_FCT2(status2,
						phpalI14443p3b_WakeUpB2(pDataParams2->pPal1443p3bDataParams2,
								bNumOfSlots2, pDataParams2->sTypeBTargetInfo2.bAfiReq2,
								pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2,
								pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].aAtqB2,
								&pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].bAtqBLength2));

			}
			/* Symbol 3 */
			if(PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2))
			{
				/* Symbol 2 */
				/* No Response */
				if((status2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
				{
					break;	/*branch "No" of symbol 2*/
				}
				else
				{ /* Symbol 4 */
					if((pDataParams2->baPasConDevLim2[1] == 0x00U))
					{
						pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 = 0;
						/* Symbol 24 */
						pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_B2;
						break;
					}
				}
			}

			pDataParams2->bCollResBState2 = ColResolB_Symbol52;
			return PH_STATUS_INPROCESS2;
			/*no break*/
		case ColResolB_Symbol52:
			/* Symbol 5 */
			bCurrentSlotNum2 = 0;
			bCurrentDeviceCount2 = 0;
			pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 = 0;
			pDataParams2->bCollPend2 &= (uint8)~(uint8)PHAC_DISCLOOP_POS_BIT_MASK_B2;
			pDataParams2->bCollResBState2 = ColResolB_Symbol62;
			/*no break*/
		case ColResolB_Symbol62:
			/* Symbol 6: Slot is Empty */
			if ((status2 & PH_ERR_MASK2) != PH_ERR_IO_TIMEOUT2) {
				/* Symbol 7: Validate SENSB_RES */
				if (status2 == PH_ERR_SUCCESS2) {
					/* Symbol 9 */
					if ((pDataParams2->bNfcActivityVersion2
							== PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12)
							&& (bCurrentDeviceCount2 > 0U)) {
						/* Symbol 10 */
						status2 = phpalI14443p3b_SetSerialNo2(pDataParams2->pPal1443p3bDataParams2,
								pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 - (uint8) 1U].aPupi2);
					}
					pDataParams2->bCollResBState2 = ColResolB_Symbol102;
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					/* Symbol 8 CollisionPend: 1*/
					pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_B2;
				}
			}
			pDataParams2->bCollResBState2 = ColResolB_Symbol142; /*Jump to state Symbol14*/
			return PH_STATUS_INPROCESS2;

		case ColResolB_Symbol102:
			/* Symbol 10 */
			if ((pDataParams2->bNfcActivityVersion2 == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12) && (bCurrentDeviceCount2 > 0U))
			{
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_HaltB2(pDataParams2->pPal1443p3bDataParams2));
				if (status2 == PH_ERR_ABORTED2) {
					break; /*Finish, return ABORTED*/
				}
			}
			/* Symbol 12 */
			(void)memcpy(pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].aPupi2,
				&pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].aAtqB2[1],
				PHAC_DISCLOOP_I3P3B_PUPI_LENGTH2);

			/* Symbol 11 */
			pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2++;
			bCurrentDeviceCount2++;

			/* Symbol 13 */
			if (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 >= pDataParams2->baPasConDevLim2[1])
			{
				pDataParams2->bNumOfCards2 = pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2;

				status2 = PH_ERR_SUCCESS2; /*Finish, return PH_ERR_SUCCESS2*/
				break;
			}
			pDataParams2->bCollResBState2 = ColResolB_Symbol10A2;
			/*no break*/
		case ColResolB_Symbol10A2:
			if(pDataParams2->bNfcActivityVersion2 == PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02)
			{
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_HaltB2(pDataParams2->pPal1443p3bDataParams2));
				if (status2 == PH_ERR_ABORTED2) {
					break; /*Finish, return ABORTED*/
				}
			}
			pDataParams2->bCollResBState2 = ColResolB_Symbol142;
			/*no break*/
		case ColResolB_Symbol142:
			/* Symbol 14 */
			bCurrentSlotNum2++;
			/* Symbol 15 */
			if (bCurrentSlotNum2 < ((uint8) 1U << bNumOfSlots2)) {
				pDataParams2->bCollResBState2 = ColResolB_Symbol252; /*Jump to state Symbol25*/
			}
			else
			{
				/* Symbol 16 */
				if (0U != (pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_B2))
				{
					/* Symbol 17 */
					if (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 > 0U)
					{
						/* Symbol 20 */
						if ((pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 >= pDataParams2->baPasConDevLim2[1])
								|| (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 >= PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2))
						{
							pDataParams2->bNumOfCards2 = pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2;
							status2 = PH_ERR_SUCCESS2;
							break;
						}
					}
					else
					{
						/* Symbol 18 */
						if (bNumOfSlots2 == PHAC_DISCLOOP_TYPEB_MAX_SLOT_NUM2)
						{
							pDataParams2->bNumOfCards2 = pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2;
							if (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 == 0U)
							{
								status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
							}
							else
							{
								status2 = PH_ERR_SUCCESS2;
							}
							break;
						}
						/* Symbol 19 */
						bNumOfSlots2++;
					}
					pDataParams2->bCollResBState2 = ColResolB_Symbol212;
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					/*Finish and return status2*/
					pDataParams2->bNumOfCards2 = pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2;
					if (pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2 == 0U)
					{
						status2 = (PHAC_DISCLOOP_NO_DEVICE_RESOLVED2 | PH_COMP_AC_DISCLOOP2);
					}
					else
					{
						status2 = PH_ERR_SUCCESS2;
					}
					break;
				}
			}
			/*no break*/
		case ColResolB_Symbol252:
			/* Symbol 25 */
			PH_CHECK_INPROCESS_FCT2(status2,
					phpalI14443p3b_SlotMarker2(
							pDataParams2->pPal1443p3bDataParams2,
							(bCurrentSlotNum2 + 1U),
							pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].aAtqB2,
							&pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].bAtqBLength2));
			if (status2 == PH_ERR_ABORTED2) {
				break;
			}
			pDataParams2->bCollResBState2 = ColResolB_Symbol62; /*Jump to state Symbol6*/
			return PH_STATUS_INPROCESS2;

		case ColResolB_Symbol212:
			/* Symbol 21 */
			if (bCurrentDeviceCount2 > 0U)
			{
				/* Symbol 22 */
				PH_CHECK_INPROCESS_FCT2(status2, phpalI14443p3b_HaltB2(pDataParams2->pPal1443p3bDataParams2));
				if (status2 == PH_ERR_ABORTED2)
				{
					break;
				}
			}
			/* Symbol 23 */
			pDataParams2->bCollResBState2 = ColResolB_Symbol232;
			/*no break*/
		case ColResolB_Symbol232:
			/* Symbol 23 */
			PH_CHECK_INPROCESS_FCT2(status2,
					phpalI14443p3b_RequestB2(pDataParams2->pPal1443p3bDataParams2, bNumOfSlots2, pDataParams2->sTypeBTargetInfo2.bAfiReq2,
							pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2,
							pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].aAtqB2,
							&pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2].bAtqBLength2));
			if (status2 == PH_ERR_ABORTED2)
			{
				break;
			}
			pDataParams2->bCollResBState2 = ColResolB_Symbol52;
			return PH_STATUS_INPROCESS2;
	}
	pDataParams2->bCollResBState2 = ColResolB_Start2;
	return PH_ADD_COMPCODE2(status2, PH_COMP_AC_DISCLOOP2);
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateB2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint8, ANFCRL_VAR) bTypeBTagIdx2) {
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bAtqbLen2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aAtqb2[13] = {0U};
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCidEnabled2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCid2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNadSupported2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFwi2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFsdi2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bFsci2 = 0U;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2 */

	/* Only deviation form Device Activation Activity is
	 * Device sleep state is not been check and always send WakeUpB Command
	 */
	if (bTypeBTagIdx2 >= pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2) {
		/* Out of range or no such card found yet */
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2,
				PH_COMP_AC_DISCLOOP2);
	}

	/* Send WUPB for tags in sleep state (except the last detected tag all are in sleep state) */
	if (pDataParams2->bDiscLoopActivateBState2 == 0U) {
		PH_CHECK_INPROCESS_FCT2(status2,
				phpalI14443p3b_WakeUpB2(pDataParams2->pPal1443p3bDataParams2, 0x00,
						pDataParams2->sTypeBTargetInfo2.bAfiReq2,
						pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2, aAtqb2,
						&bAtqbLen2));
		if (status2 == PH_ERR_ABORTED2) {
			return status2;
		}
		pDataParams2->bDiscLoopActivateBState2 = 1U;
	}
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2
	/* AttribB: activate PICC */
	if (pDataParams2->bDiscLoopActivateBState2 == 1U) {
		/* Enable Emd check in Emvco. */
		if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2) {
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
					PHHAL_HW_CONFIG_SET_EMD2, PH_ON2));
			if (status2 != PH_ERR_SUCCESS2) {
				pDataParams2->bDiscLoopActivateBState2 = 0U;
				return status2;
			}
		}

		pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].bSupportType4B2 =
				PH_OFF2;
		if (0u
				!= ((pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].aAtqB2[PHAC_DISCLOOP_TYPEB_PROTOCOL_TYPE_OFFSET2]
						& PHAC_DISCLOOP_TYPEB_MASK_PROTOCOL_TYPE2))) {
			pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].bSupportType4B2 =
					PH_ON2;
		}

		if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2)
				&& (pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].bSupportType4B2
						== PH_OFF2)) {
			pDataParams2->bDiscLoopActivateBState2 = 0U;
			return PH_ERR_SUCCESS2;
		}
		pDataParams2->bDiscLoopActivateBState2 = 2U;
		return PH_STATUS_INPROCESS2;
	}

	if (pDataParams2->bDiscLoopActivateBState2 == 2U) {
		PH_CHECK_INPROCESS_FCT2(status2,
				phpalI14443p3b_Attrib2(pDataParams2->pPal1443p3bDataParams2,
						pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].aAtqB2,
						pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[bTypeBTagIdx2].bAtqBLength2,
						pDataParams2->sTypeBTargetInfo2.bFsdi2,
						pDataParams2->sTypeBTargetInfo2.bCid2,
						pDataParams2->sTypeBTargetInfo2.bDri2,
						pDataParams2->sTypeBTargetInfo2.bDsi2,
						&pDataParams2->sTypeBTargetInfo2.sTypeB_I3P42.bMbli2));
		pDataParams2->bDiscLoopActivateBState2 = 0U;
		if (status2 != PH_ERR_SUCCESS2) {
			return status2;
		}

		/* Retrieve 14443-3b protocol parameter */
		status2 = phpalI14443p3b_GetProtocolParams2(
				pDataParams2->pPal1443p3bDataParams2, &bCidEnabled2, &bCid2,
				&bNadSupported2, &bFwi2, &bFsdi2, &bFsci2);
		if (status2 != PH_ERR_SUCCESS2) {
			return status2;
		}

		/* Set 14443-4 protocol parameter */
		status2 = phpalI14443p4_SetProtocol2(pDataParams2->pPal14443p4DataParams2,
				bCidEnabled2, bCid2, bNadSupported2,
				pDataParams2->sTypeBTargetInfo2.bNad2, bFwi2, bFsdi2, bFsci2);
	}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2 */
	return status2;
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	PH_UNUSED_VARIABLE2(bTypeBTagIdx2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_B_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_B_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif
