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
*   @file    phacDiscLoop_Sw_Int_V.c
*   @version 1.0.0
*
*   @brief   AUTOSAR phacDiscLoop - API usage in common use cases.
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
#include <phpalSli15693.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw_Int.h"
#include "phacDiscLoop_Sw_Int_V.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_V.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_V_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_V.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_V_VENDOR_ID_C != PHACDISCLOOP_SW_INT_V_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int_V.c and phacDiscLoop_Sw_Int_V.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_V.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_INT_V_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_V.c and phacDiscLoop_Sw_Int_V.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_V.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_INT_V_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_INT_V_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_INT_V_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_V.c and phacDiscLoop_Sw_Int_V.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
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
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/* *****************************************************************************************************************
 * Private Functions
 * ***************************************************************************************************************** */
FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeV(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;

	/* Inventory request with one slot */
	PH_CHECK_INPROCESS_FCT(status, phpalSli15693_Inventory(
			pDataParams->pPalSli15693DataParams,
			pDataParams->sTypeVTargetInfo.bFlag | PHPAL_SLI15693_FLAG_NBSLOTS | PHPAL_SLI15693_FLAG_INVENTORY,
			0,
			NULL,
			0,
			&pDataParams->sTypeVTargetInfo.aTypeV[0].bDsfid,
			pDataParams->sTypeVTargetInfo.aTypeV[0].aUid
	));

	if(0u != (phacDiscLoop_Sw_Int_IsValidPollStatus(status)))
	{
		return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
	}
	else
	{
		return status;
	}
#else
	PH_UNUSED_VARIABLE(pDataParams);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionV(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aMaskBuffer[PHPAL_SLI15693_UID_LENGTH] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bMaskBitLength = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bUidLengthDummy = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bDataDummy[1] = {0U};
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNextSlot = 1U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wDataLengthDummy = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bSlot = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSlotCount = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bLevel = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bEnd = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRepeat = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bCount[16] = {0};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCollisionLogReg[16] = {0};

	switch(pDataParams->bDiscLoopCollisionResolutionVState)
	{
		case 0U:
			/* Symbol 0 */
			pDataParams->sTypeVTargetInfo.bTotalTagsFound = 0U;
			pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
			/* Apply Guard time. */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_SetConfig(
				pDataParams->pHalDataParams,
				PHHAL_HW_CONFIG_POLL_GUARD_TIME_US,
				pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_V]));
			PH_CHECK_SUCCESS(status);
			pDataParams->bDiscLoopCollisionResolutionVState = 1U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 1U:
			/* Configure HW for the TypeV technology */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(
				pDataParams->pHalDataParams,
				PHHAL_HW_CARDTYPE_ISO15693));
			PH_BREAK_ON_FAILURE(status);
			pDataParams->bDiscLoopCollisionResolutionVState = 2U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 2U:
			/* Symbol 0 */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_Inventory(
				pDataParams->pPalSli15693DataParams,
				pDataParams->sTypeVTargetInfo.bFlag | PHPAL_SLI15693_FLAG_NBSLOTS | PHPAL_SLI15693_FLAG_INVENTORY,
				0U,
				aMaskBuffer,
				bMaskBitLength,
				&pDataParams->sTypeVTargetInfo.aTypeV[0].bDsfid,
				pDataParams->sTypeVTargetInfo.aTypeV[0].aUid));

			/* Symbol 1 */
			if(PH_ERR_IO_TIMEOUT == (status & PH_ERR_MASK))
			{
				break;
			}
			else
			{
				/* Symbol 2 */
				if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
				{
					/* Symbol 18 */
					pDataParams->sTypeVTargetInfo.bTotalTagsFound++;
					pDataParams->bNumOfCards++;
					status = PH_ERR_SUCCESS;
					break;
				}
				else if(((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
						|| ((status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR))
				{
					/* Symbol 3 */
					pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_V;

					/* Symbol 4 */
					if(pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V] == 0x00U)
					{
						status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_COLLISION_PENDING, PH_COMP_AC_DISCLOOP);
						break;
					}
					pDataParams->bDiscLoopCollisionResolutionVState = 3U;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					/* For all other error types, return error */
					break;
				}
			}
			/* no break */
		case 3U:
			if(pDataParams->sTypeVTargetInfo.bTotalTagsFound < pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V])
			{
				/* Symbol 6 */
				bSlot = 0;

				/* Symbol 7 */
				pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
				pDataParams->bDiscLoopCollisionResolutionVState = 4U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				pDataParams->bDiscLoopCollisionResolutionVState = 10U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 4U:
			/* Symbol 8 */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_Inventory(
					pDataParams->pPalSli15693DataParams,
					pDataParams->sTypeVTargetInfo.bFlag | PHPAL_SLI15693_FLAG_INVENTORY,
					0U,
					aMaskBuffer,
					bMaskBitLength,
					&pDataParams->sTypeVTargetInfo.aTypeV[pDataParams->sTypeVTargetInfo.bTotalTagsFound].bDsfid,
					pDataParams->sTypeVTargetInfo.aTypeV[pDataParams->sTypeVTargetInfo.bTotalTagsFound].aUid));
			pDataParams->bDiscLoopCollisionResolutionVState = 5U;
			return PH_STATUS_INPROCESS;
		case 5U:
			/* Loop till 16 slots or collision error */
			/* Symbol 9 */
			/* Protocol error scenario is not described in Activity Spec v2.2,
			 * but based on DTA Test case treating Protocol error similar to Timeout.
			 * */
			if(((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
				|| ((status & PH_ERR_MASK) == PH_ERR_PROTOCOL_ERROR))
			{
				/* Continue with next slot */
			}
			/* Symbol 10 */
			else if(((status & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
					|| ((status & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR))
			{
				/* Symbol 16 */
				pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_V;
				wCollisionLogReg[bLevel] |= ((uint16_t) 1U )<< bSlot;
			}
			else if((status & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				/* Symbol 11 */
				pDataParams->sTypeVTargetInfo.bTotalTagsFound++;
				pDataParams->bNumOfCards++;

				/* Symbol 12 */
				if(pDataParams->sTypeVTargetInfo.bTotalTagsFound >= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V])
				{
					status = PH_ERR_SUCCESS;
					break;
				}
			}
			else
			{
				/* For all other error types, return error */
				break;
			}

			/* Symbol 13, 14U */
			if(++bSlot == 16U)
			{
				bNextSlot = 0;
			}

			if(0U != (bNextSlot))
			{
				pDataParams->bDiscLoopCollisionResolutionVState = 6U;
				return PH_STATUS_INPROCESS;
			}

			pDataParams->bDiscLoopCollisionResolutionVState = 7U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 6U:
			/* Symbol 15 */
			PH_CHECK_INPROCESS_FCT(status, phpalSli15693_SendEof(
				pDataParams->pPalSli15693DataParams,
				PHPAL_SLI15693_EOF_NEXT_SLOT,
				&pDataParams->sTypeVTargetInfo.aTypeV[pDataParams->sTypeVTargetInfo.bTotalTagsFound].bDsfid,
				pDataParams->sTypeVTargetInfo.aTypeV[pDataParams->sTypeVTargetInfo.bTotalTagsFound].aUid,
				&bUidLengthDummy,
				bDataDummy,
				&wDataLengthDummy));
			/* Return if status is aborted. */
			if (PH_ERR_ABORTED == status)
			{
				break;
			}
			pDataParams->bDiscLoopCollisionResolutionVState = 7U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 7U:
			if(0U != bNextSlot)
			{
				pDataParams->bDiscLoopCollisionResolutionVState = 5U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				bNextSlot = 1;
				status = PH_ERR_SUCCESS;
				pDataParams->bDiscLoopCollisionResolutionVState = 8U;
				return PH_STATUS_INPROCESS;
			}
			/* no break */
		case 8U:
			bRepeat = 0U;
			if (0U != (wCollisionLogReg[bLevel]))
			{
				for (bSlotCount = bCount[bLevel]; bSlotCount < 16U; bSlotCount++)
				{
					if (0U != (wCollisionLogReg[bLevel] & ((uint16_t)1U << bSlotCount)))
					{
						/* Get bit-length of last valid byte */
						bUidLengthDummy = bMaskBitLength % (uint8_t)8U;

						/* Whole byte is valid -> append slot number to next byte */
						if (bUidLengthDummy == 0U)
						{
							aMaskBuffer[bMaskBitLength >> 3U] = bSlotCount;
						}
						/* Partial byte is valid */
						else
						{
							/* Fill the invalid bits of the incomplete byte with the 4 bits slot number */
							aMaskBuffer[bMaskBitLength >> (uint8_t)3U] &= (uint8_t)((uint8_t)0xFF >> ((uint8_t)8U  - bUidLengthDummy));
							aMaskBuffer[bMaskBitLength >> (uint8_t)3U] |= (uint8_t)(bSlotCount << bUidLengthDummy);

							/* If not all 4 bits of the Slot number fit in the incomplete byte, put the rest in the next byte */
							if (bUidLengthDummy > 4U)
							{
								aMaskBuffer[(bMaskBitLength >> 3U) + 1U] = (uint8_t)(bSlotCount >> bUidLengthDummy);
							}
						}

						/* Increment the bit length by the 4 bits slot number */
						bMaskBitLength = bMaskBitLength + 4U;
						pDataParams->bCollPend |= PHAC_DISCLOOP_POS_BIT_MASK_V;
						wCollisionLogReg[bLevel] =  wCollisionLogReg[bLevel] & ~((uint16_t)1U  << bSlotCount);

						if(bSlotCount == 0x0FU)
						{
							bCount[bLevel] = 0U;
							wCollisionLogReg[bLevel] = 0U;
							if(bLevel == 0U)
							{
								bEnd = 1;
							}
							else
							{
								bCount[bLevel] = bSlotCount;
								bLevel++;
							}
						}
						else
						{
							bCount[bLevel] = bSlotCount;
							bCount[bLevel]++;
							bLevel++;
						}
						break;
					}
					else
					{
						if(bSlotCount == 0x0FU)
						{
							if(bLevel == 0U)
							{
								bEnd = 1;
								pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
							}
							else
							{
								/* Decrement the bit length by the 4 bits slot number */
								pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
								bMaskBitLength = bMaskBitLength - 4u;
								wCollisionLogReg[bLevel] = 0;
								bCount[bLevel] = 0;
								bLevel--;
							}
						}
					}
				}
			}
			else
			{
				if(bLevel == 0U)
				{
					pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
					bEnd = 1;
				}
				else
				{
					/* Decrement the bit length by the 4 bits slot number */
					pDataParams->bCollPend &= (uint8_t)~(uint8_t)(PHAC_DISCLOOP_POS_BIT_MASK_V);
					bMaskBitLength = bMaskBitLength - 4u;
					wCollisionLogReg[bLevel] = 0U;
					bCount[bLevel] = 0U;
					bLevel--;
					bRepeat = 1U;
				}
			}
			pDataParams->bDiscLoopCollisionResolutionVState = 9U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 9U:
			if(0U != bRepeat)
			{
				pDataParams->bDiscLoopCollisionResolutionVState = 8U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Symbol 17 */
				if((0U == ((pDataParams->bCollPend & PHAC_DISCLOOP_POS_BIT_MASK_V))))
				{
					break;
				}
			}
			pDataParams->bDiscLoopCollisionResolutionVState = 10U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 10U:
			if(0U == bEnd)
			{
				pDataParams->bDiscLoopCollisionResolutionVState = 3U;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				break;
			}
			/* no break */
		default:
			status = PH_ERR_INTERNAL_ERROR;
			break;
	}

	/* Reset parameters values */
	pDataParams->bDiscLoopCollisionResolutionVState = 0;
	bNextSlot = 1U;
	bSlot = 0U;
	bLevel = 0U;
	bRepeat = 0U;
	bEnd = 0U;
	bMaskBitLength = 0U;
	for(uint8 i = 0U; i < 16U; i++)
	{
		wCollisionLogReg[i] = 0U;
		bCount[i] = 0U;
	}
	for(uint8 i = 0U; i < (uint8)PHPAL_SLI15693_UID_LENGTH; i++)
	{
		aMaskBuffer[i] = 0U;
	}

	if(PH_ERR_SUCCESS != (status & PH_ERR_MASK))
	{
		return status;
	}

	status = PH_ERR_INTERNAL_ERROR;
	if(0U != (pDataParams->sTypeVTargetInfo.bTotalTagsFound))
	{
		return PH_ERR_SUCCESS;
	}

	return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
#else
	PH_UNUSED_VARIABLE(pDataParams);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateV(
        P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        VAR(uint8, ANFCRL_VAR) bTypeVTagIdx
)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

    if (bTypeVTagIdx >= pDataParams->sTypeVTargetInfo.bTotalTagsFound)
    {
        /* Out of range */
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
    }

    status = phhalHw_Exchange_GetStatus();
    if ((status == PH_ERR_IO_TIMEOUT) || (status == PH_ERR_SUCCESS))
    {
		/* Set the UID to be selected and the UID length into PAL */
		PH_CHECK_SUCCESS_FCT(status, phpalSli15693_SetSerialNo(
				pDataParams->pPalSli15693DataParams,
				pDataParams->sTypeVTargetInfo.aTypeV[bTypeVTagIdx].aUid,
				PHPAL_SLI15693_UID_LENGTH));
    }
    /* Move the tag to selected state */
    PH_CHECK_SUCCESS_FCT(status, phpalSli15693_Select(pDataParams->pPalSli15693DataParams));

    return PH_ERR_SUCCESS;
#else
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(bTypeVTagIdx);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_V_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_V_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif
