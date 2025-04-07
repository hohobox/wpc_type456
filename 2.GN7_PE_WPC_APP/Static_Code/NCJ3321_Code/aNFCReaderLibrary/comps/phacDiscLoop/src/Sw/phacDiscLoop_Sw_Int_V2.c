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
*   @file    phacDiscLoop_Sw_Int_V2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR phacDiscLoop2 - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop2 Discovery Loop
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
#include <phpalSli156932.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw_Int2.h"
#include "phacDiscLoop_Sw_Int_V2.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_V2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_V_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_V2.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_V_VENDOR_ID_C2 != PHACDISCLOOP_SW_INT_V_VENDOR_ID2)
    #error "phacDiscLoop_Sw_Int_V2.c and phacDiscLoop_Sw_Int_V2.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_V2.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_V2.c and phacDiscLoop_Sw_Int_V2.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_V2.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_V2.c and phacDiscLoop_Sw_Int_V2.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
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
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/* *****************************************************************************************************************
 * Private Functions
 * ***************************************************************************************************************** */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeV2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;

	/* Inventory request with one slot */
	PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_Inventory2(
			pDataParams2->pPalSli15693DataParams2,
			pDataParams2->sTypeVTargetInfo2.bFlag2 | PHPAL_SLI15693_FLAG_NBSLOTS2 | PHPAL_SLI15693_FLAG_INVENTORY2,
			0,
			NULL,
			0,
			&pDataParams2->sTypeVTargetInfo2.aTypeV2[0].bDsfid2,
			pDataParams2->sTypeVTargetInfo2.aTypeV2[0].aUid2
	));

	if(0u != (phacDiscLoop_Sw_Int_IsValidPollStatus2(status2)))
	{
		return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
	}
	else
	{
		return status2;
	}
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionV2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aMaskBuffer2[PHPAL_SLI15693_UID_LENGTH2] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bMaskBitLength2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bUidLengthDummy2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bDataDummy2[1] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNextSlot2 = 1U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wDataLengthDummy2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bSlot2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSlotCount2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bLevel2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bEnd2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRepeat2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bCount2[16] = {0};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCollisionLogReg2[16] = {0};

	switch(pDataParams2->bDiscLoopCollisionResolutionVState2)
	{
		case 0U:
			/* Symbol 0 */
			pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2 = 0U;
			pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
			/* Apply Guard time. */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_SetConfig2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2,
				pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_V2]));
			PH_CHECK_SUCCESS2(status2);
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 1U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 1U:
			/* Configure HW for the TypeV technology */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CARDTYPE_ISO156932));
			PH_BREAK_ON_FAILURE2(status2);
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 2U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 2U:
			/* Symbol 0 */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_Inventory2(
				pDataParams2->pPalSli15693DataParams2,
				pDataParams2->sTypeVTargetInfo2.bFlag2 | PHPAL_SLI15693_FLAG_NBSLOTS2 | PHPAL_SLI15693_FLAG_INVENTORY2,
				0U,
				aMaskBuffer2,
				bMaskBitLength2,
				&pDataParams2->sTypeVTargetInfo2.aTypeV2[0].bDsfid2,
				pDataParams2->sTypeVTargetInfo2.aTypeV2[0].aUid2));

			/* Symbol 1 */
			if(PH_ERR_IO_TIMEOUT2 == (status2 & PH_ERR_MASK2))
			{
				break;
			}
			else
			{
				/* Symbol 2 */
				if((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
				{
					/* Symbol 18 */
					pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2++;
					pDataParams2->bNumOfCards2++;
					status2 = PH_ERR_SUCCESS2;
					break;
				}
				else if(((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
						|| ((status2 & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2))
				{
					/* Symbol 3 */
					pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_V2;

					/* Symbol 4 */
					if(pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2] == 0x00U)
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_COLLISION_PENDING2, PH_COMP_AC_DISCLOOP2);
						break;
					}
					pDataParams2->bDiscLoopCollisionResolutionVState2 = 3U;
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					/* For all other error types, return error */
					break;
				}
			}
			/* no break */
		case 3U:
			if(pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2 < pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2])
			{
				/* Symbol 6 */
				bSlot2 = 0;

				/* Symbol 7 */
				pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 4U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 10U;
				return PH_STATUS_INPROCESS2;
			}
			/* no break */
		case 4U:
			/* Symbol 8 */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_Inventory2(
					pDataParams2->pPalSli15693DataParams2,
					pDataParams2->sTypeVTargetInfo2.bFlag2 | PHPAL_SLI15693_FLAG_INVENTORY2,
					0U,
					aMaskBuffer2,
					bMaskBitLength2,
					&pDataParams2->sTypeVTargetInfo2.aTypeV2[pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2].bDsfid2,
					pDataParams2->sTypeVTargetInfo2.aTypeV2[pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2].aUid2));
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 5U;
			return PH_STATUS_INPROCESS2;
		case 5U:
			/* Loop till 16 slots or collision error */
			/* Symbol 9 */
			/* Protocol error scenario is not described in Activity Spec v2.2,
			 * but based on DTA Test case treating Protocol error similar to Timeout.
			 * */
			if(((status2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
				|| ((status2 & PH_ERR_MASK2) == PH_ERR_PROTOCOL_ERROR2))
			{
				/* Continue with next slot */
			}
			/* Symbol 10 */
			else if(((status2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
					|| ((status2 & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2))
			{
				/* Symbol 16 */
				pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_V2;
				wCollisionLogReg2[bLevel2] |= ((uint16_t) 1U )<< bSlot2;
			}
			else if((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
			{
				/* Symbol 11 */
				pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2++;
				pDataParams2->bNumOfCards2++;

				/* Symbol 12 */
				if(pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2 >= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2])
				{
					status2 = PH_ERR_SUCCESS2;
					break;
				}
			}
			else
			{
				/* For all other error types, return error */
				break;
			}

			/* Symbol 13, 14U */
			if(++bSlot2 == 16U)
			{
				bNextSlot2 = 0;
			}

			if(0U != (bNextSlot2))
			{
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 6U;
				return PH_STATUS_INPROCESS2;
			}

			pDataParams2->bDiscLoopCollisionResolutionVState2 = 7U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 6U:
			/* Symbol 15 */
			PH_CHECK_INPROCESS_FCT2(status2, phpalSli15693_SendEof2(
				pDataParams2->pPalSli15693DataParams2,
				PHPAL_SLI15693_EOF_NEXT_SLOT2,
				&pDataParams2->sTypeVTargetInfo2.aTypeV2[pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2].bDsfid2,
				pDataParams2->sTypeVTargetInfo2.aTypeV2[pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2].aUid2,
				&bUidLengthDummy2,
				bDataDummy2,
				&wDataLengthDummy2));
			/* Return if status2 is aborted. */
			if (PH_ERR_ABORTED2 == status2)
			{
				break;
			}
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 7U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 7U:
			if(0U != bNextSlot2)
			{
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 5U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				bNextSlot2 = 1;
				status2 = PH_ERR_SUCCESS2;
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 8U;
				return PH_STATUS_INPROCESS2;
			}
			/* no break */
		case 8U:
			bRepeat2 = 0U;
			if (0U != (wCollisionLogReg2[bLevel2]))
			{
				for (bSlotCount2 = bCount2[bLevel2]; bSlotCount2 < 16U; bSlotCount2++)
				{
					if (0U != (wCollisionLogReg2[bLevel2] & ((uint16_t)1U << bSlotCount2)))
					{
						/* Get bit-length of last valid byte */
						bUidLengthDummy2 = bMaskBitLength2 % (uint8_t)8U;

						/* Whole byte is valid -> append slot number to next byte */
						if (bUidLengthDummy2 == 0U)
						{
							aMaskBuffer2[bMaskBitLength2 >> 3U] = bSlotCount2;
						}
						/* Partial byte is valid */
						else
						{
							/* Fill the invalid bits of the incomplete byte with the 4 bits slot number */
							aMaskBuffer2[bMaskBitLength2 >> (uint8_t)3U] &= (uint8_t)((uint8_t)0xFF >> ((uint8_t)8U  - bUidLengthDummy2));
							aMaskBuffer2[bMaskBitLength2 >> (uint8_t)3U] |= (uint8_t)(bSlotCount2 << bUidLengthDummy2);

							/* If not all 4 bits of the Slot number fit in the incomplete byte, put the rest in the next byte */
							if (bUidLengthDummy2 > 4U)
							{
								aMaskBuffer2[(bMaskBitLength2 >> 3U) + 1U] = (uint8_t)(bSlotCount2 >> bUidLengthDummy2);
							}
						}

						/* Increment the bit length by the 4 bits slot number */
						bMaskBitLength2 = bMaskBitLength2 + 4U;
						pDataParams2->bCollPend2 |= PHAC_DISCLOOP_POS_BIT_MASK_V2;
						wCollisionLogReg2[bLevel2] =  wCollisionLogReg2[bLevel2] & ~((uint16_t)1U  << bSlotCount2);

						if(bSlotCount2 == 0x0FU)
						{
							bCount2[bLevel2] = 0U;
							wCollisionLogReg2[bLevel2] = 0U;
							if(bLevel2 == 0U)
							{
								bEnd2 = 1;
							}
							else
							{
								bCount2[bLevel2] = bSlotCount2;
								bLevel2++;
							}
						}
						else
						{
							bCount2[bLevel2] = bSlotCount2;
							bCount2[bLevel2]++;
							bLevel2++;
						}
						break;
					}
					else
					{
						if(bSlotCount2 == 0x0FU)
						{
							if(bLevel2 == 0U)
							{
								bEnd2 = 1;
								pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
							}
							else
							{
								/* Decrement the bit length by the 4 bits slot number */
								pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
								bMaskBitLength2 = bMaskBitLength2 - 4u;
								wCollisionLogReg2[bLevel2] = 0;
								bCount2[bLevel2] = 0;
								bLevel2--;
							}
						}
					}
				}
			}
			else
			{
				if(bLevel2 == 0U)
				{
					pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
					bEnd2 = 1;
				}
				else
				{
					/* Decrement the bit length by the 4 bits slot number */
					pDataParams2->bCollPend2 &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V2);
					bMaskBitLength2 = bMaskBitLength2 - 4u;
					wCollisionLogReg2[bLevel2] = 0U;
					bCount2[bLevel2] = 0U;
					bLevel2--;
					bRepeat2 = 1U;
				}
			}
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 9U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 9U:
			if(0U != bRepeat2)
			{
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 8U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Symbol 17 */
				if((0U == ((pDataParams2->bCollPend2 & PHAC_DISCLOOP_POS_BIT_MASK_V2))))
				{
					break;
				}
			}
			pDataParams2->bDiscLoopCollisionResolutionVState2 = 10U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 10U:
			if(0U == bEnd2)
			{
				pDataParams2->bDiscLoopCollisionResolutionVState2 = 3U;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				break;
			}
			/* no break */
		default:
			status2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}

	/* Reset parameters values */
	pDataParams2->bDiscLoopCollisionResolutionVState2 = 0;
	bNextSlot2 = 1U;
	bSlot2 = 0U;
	bLevel2 = 0U;
	bRepeat2 = 0U;
	bEnd2 = 0U;
	bMaskBitLength2 = 0U;
	for(uint8 i2 = 0U; i2 < 16U; i2++)
	{
		wCollisionLogReg2[i2] = 0U;
		bCount2[i2] = 0U;
	}
	for(uint8 i2 = 0U; i2 < (uint8)PHPAL_SLI15693_UID_LENGTH2; i2++)
	{
		aMaskBuffer2[i2] = 0U;
	}

	if(PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2))
	{
		return status2;
	}

	status2 = PH_ERR_INTERNAL_ERROR2;
	if(0U != (pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2))
	{
		return PH_ERR_SUCCESS2;
	}

	return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateV2(
        P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
        VAR(uint8, ANFCRL_VAR) bTypeVTagIdx2
)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

    if (bTypeVTagIdx2 >= pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2)
    {
        /* Out of range */
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
    }

    status2 = phhalHw_Exchange_GetStatus2();
    if ((status2 == PH_ERR_IO_TIMEOUT2) || (status2 == PH_ERR_SUCCESS2))
    {
		/* Set the UID to be selected and the UID length into PAL */
		PH_CHECK_SUCCESS_FCT2(status2, phpalSli15693_SetSerialNo2(
				pDataParams2->pPalSli15693DataParams2,
				pDataParams2->sTypeVTargetInfo2.aTypeV2[bTypeVTagIdx2].aUid2,
				PHPAL_SLI15693_UID_LENGTH2));
    }
    /* Move the tag to selected state */
    PH_CHECK_SUCCESS_FCT2(status2, phpalSli15693_Select2(pDataParams2->pPalSli15693DataParams2));

    return PH_ERR_SUCCESS2;
#else
    PH_UNUSED_VARIABLE2(pDataParams2);
    PH_UNUSED_VARIABLE2(bTypeVTagIdx2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif
