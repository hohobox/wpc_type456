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
*   @file    phacDiscLoop_Sw_Int_F2.c
*   @version 1.0.0
*
*   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
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
#include <phpalFelica2.h>
#include "phacDiscLoop_Sw2.h"
#include <phTools2.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw_Int2.h"
#include "phacDiscLoop_Sw_Int_F2.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_F2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_F_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_F2.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_F_VENDOR_ID_C2 != PHACDISCLOOP_SW_INT_F_VENDOR_ID2)
    #error "phacDiscLoop_Sw_Int_F2.c and phacDiscLoop_Sw_Int_F2.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_F2.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_F2.c and phacDiscLoop_Sw_Int_F2.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_F2.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_F2.c and phacDiscLoop_Sw_Int_F2.h are different"
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
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2

/* Perform check whether same TypeF tag/device already detected with higher baud rate */
static FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_CheckForDuplication2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pID2,  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsDuplicate2)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bIndex2 = 0x00;

    *pIsDuplicate2 = PH_OFF2;

    for(bIndex2 = 0; bIndex2 < pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2; bIndex2++)
    {   /* Skip Identical Entry */
        if((memcmp(pID2, pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bIndex2].aIDmPMm2, PHAC_DISCLOOP_FELICA_IDM_LENGTH2 + PHAC_DISCLOOP_FELICA_PMM_LENGTH2 )) == 0)
        {
            *pIsDuplicate2 = PH_ON2;
            /* Update baud rate if device is detected with higher baud rate */
            break;
        }
    }
    return PH_ERR_SUCCESS2;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2

/* Parse and update greedy collection with Responses */
static FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_UpdateSensFResp2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pID2,
    VAR(uint8, ANFCRL_VAR) bIdLen2, VAR(uint16, ANFCRL_VAR) wCurrentBaudBitPos2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_SUCCESS2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsDuplicate2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTotalTagsFound2 = 0x00;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wRequestCode2;

	PH_CHECK_SUCCESS_FCT2(wStatus2, phacDiscLoop_Sw_Int_CheckForDuplication2(pDataParams2, &pID2[0x00], &bIsDuplicate2));
	if(0U == (bIsDuplicate2))
	{
		/* get Request code is enable */
		PH_CHECK_SUCCESS_FCT2(wStatus2, phpalFelica_GetConfig2(pDataParams2->pPalFelicaDataParams2, PHPAL_FELICA_CONFIG_RC2, &wRequestCode2));

		/* Copy ReqCode */
		if((wRequestCode2 != PH_OFF2) && (bIdLen2 > (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2)))
		{
			(void)phTools_memcpy2((uint8 *)&(pDataParams2->sTypeFTargetInfo2.aTypeFTag2[pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 + bTotalTagsFound2].aRD2), &pID2[PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2], PHPAL_FELICA_RD_LENGTH2);
		}
		/* Copy IDMmPMm */
		(void)phTools_memcpy2( (uint8 *)&(pDataParams2->sTypeFTargetInfo2.aTypeFTag2[pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 + bTotalTagsFound2].aIDmPMm2), pID2, (PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2));
		pDataParams2->sTypeFTargetInfo2.aTypeFTag2[pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 + bTotalTagsFound2].bBaud2 = (uint8)(wCurrentBaudBitPos2 & 0xFFU);

		/* Increment Tag count */
		bTotalTagsFound2++;
	}

	pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 += bTotalTagsFound2;

	return PH_ERR_SUCCESS2;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2

/* Send SENSF_REQ command and process received response */
static FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_SendSensFReq2(
                                                      P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                      VAR(uint8, ANFCRL_VAR) bNumTimeSlots2,
                                                      VAR(uint16, ANFCRL_VAR) wCurrentBaudBitPos2
                                                      )
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_INTERNAL_ERROR2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 baSystemCode2[2] = {PHPAL_FELICA_SYSTEM_CODE_BYTE_02,
												PHPAL_FELICA_SYSTEM_CODE_BYTE_12};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTemp2 = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pId2 = NULL;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxBuff2 = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIdLen2 = 0U;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wFrameStatus2 = PH_ERR_INTERNAL_ERROR2;

	switch(pDataParams2->bDiscLoopSendSensFReq2)
	{
		case 0U:
			/* send ReqC command */
			PH_CHECK_INPROCESS_FCT2(wStatus2, phpalFelica_ReqC2(pDataParams2->pPalFelicaDataParams2, baSystemCode2, bNumTimeSlots2, &pRxBuff2, &wTemp2));
			if((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
			{
				pDataParams2->bDiscLoopSendSensFReq2 = 1U;
			}
			else
			{
				return wStatus2;
			}
			/*no break*/
		case 1U:
			if(bNumTimeSlots2 > PHPAL_FELICA_NUMSLOTS_12)
			{
				/* get total number of response frame */
				PH_CHECK_FAILURE_FCT2(wStatus2, phpalFelica_GetConfig2(pDataParams2->pPalFelicaDataParams2, PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES2, &wTemp2));
				pDataParams2->bDiscLoopSendSensFReq2 = 2U;
			}
			else
			{
				/* store received IDmPMm */
				PH_CHECK_FAILURE_FCT2(wStatus2, phacDiscLoop_Sw_Int_UpdateSensFResp2(pDataParams2, pRxBuff2, (uint8)wTemp2, wCurrentBaudBitPos2));
				pDataParams2->bDiscLoopSendSensFReq2 = 3U;
			}
			return PH_STATUS_INPROCESS2;
			/*no break*/
		case 2U:
			if(0U != wTemp2)
			{
				bIdLen2 = 0x00U;
				wFrameStatus2 = 0x00U;
				/* retrieve IDmPMm one by one for all frames */
				PH_CHECK_FAILURE_FCT2(wStatus2, phpalFelica_GetFrameInfo2(
						pDataParams2->pPalFelicaDataParams2,
						(uint8)wTemp2,
						pRxBuff2,
						&wFrameStatus2,
						&pId2,
						&bIdLen2));

				if(wFrameStatus2 == PH_ERR_SUCCESS2)
				{
					/* store received IDmPMm */
					PH_CHECK_FAILURE_FCT2(wStatus2, phacDiscLoop_Sw_Int_UpdateSensFResp2(pDataParams2, pId2, bIdLen2, wCurrentBaudBitPos2));
				}
				wTemp2--;

				/* Check for device limit */
				if(pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 >= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122])
				{
					pDataParams2->bDiscLoopSendSensFReq2 = 3U;
				}
				else
				{
					return PH_STATUS_INPROCESS2;
				}
			}
			else
			{
				pDataParams2->bDiscLoopSendSensFReq2 = 3U;
			}
			/*no break*/
		case 3U:
			wTemp2 = 0U;
			pDataParams2->bDiscLoopSendSensFReq2 = 0U;
			/*Response is success but no device found*/
			if (pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 == 0U)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2,	PH_COMP_AC_DISCLOOP2);
			}
			else
			{
				return PH_ERR_SUCCESS2;
			}
			/*no break*/
		default:
			wStatus2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}

	pRxBuff2 = NULL;
	wTemp2 = 0U;
	pDataParams2->bDiscLoopSendSensFReq2 = 0U;
	return wStatus2;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeF2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_SUCCESS2;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrentBaudBitPos2 = 0u;

	switch(pDataParams2->bDiscLoopDetTechTypeF2)
	{
		case 0U:
			PH_CHECK_SUCCESS_FCT2(wStatus2,
			phpalFelica_SetConfig2(pDataParams2->pPalFelicaDataParams2, PHPAL_FELICA_CONFIG_RC2, PH_OFF2));

			/* get current felica baud rate */
			PH_CHECK_SUCCESS_FCT2(wStatus2, phacDiscLoop_GetConfig2(pDataParams2, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2, &wCurrentBaudBitPos2));

			/* if any tag has detected, do not reset the tag count */
			if (0U
					== (pDataParams2->bDetectedTechs2
							& (PHAC_DISCLOOP_POS_BIT_MASK_F4242 | PHAC_DISCLOOP_POS_BIT_MASK_F2122)))
			{
				pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 = 0;
			}

			/* re-set Collision Pending bit */
			pDataParams2->bCollPend2 &= (uint8) ~(uint8) (wCurrentBaudBitPos2 & 0xFFU);
			pDataParams2->bDiscLoopDetTechTypeF2 = 1U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 1U:
			PH_CHECK_INPROCESS_FCT2(wStatus2, phacDiscLoop_Sw_Int_SendSensFReq2(pDataParams2, PHPAL_FELICA_NUMSLOTS_42, wCurrentBaudBitPos2));
			if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus2(wStatus2)))
			{
				if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
				{
					/* set Collision Pending bit */
					pDataParams2->bCollPend2 |= (uint8) (wCurrentBaudBitPos2 & 0xFFU);
				}
				else
				{
					/* Do nothing */
				}
			}
			else
			{
				break;
			}
			wStatus2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
			break;
		default:
			break;
	}

	pDataParams2->bDiscLoopDetTechTypeF2 = 0U;
	wCurrentBaudBitPos2 = 0U;
	return wStatus2;
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionF2 (P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCurrentBaudBitPos2 = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bIndex2 = 0U;

	if (pDataParams2->bDiscLoopCollisionResolutionFState2 == 0U)
    {
		PH_CHECK_SUCCESS_FCT2(status2, phacDiscLoop_GetConfig2(pDataParams2, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2, &wCurrentBaudBitPos2));

		/* Collision_Pending = 1 and Device limit  = 0 */
		if((0U != ((pDataParams2->bCollPend2 & wCurrentBaudBitPos2))) && ((pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122] == 0x00U)))
		{
			pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 = 0;
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
		}

		/* Symbol 1 */
		/* Symbol 2*/
		/* Device limit for F424 and F212 is same */
		if(pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 >= pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122])
		{
			if (wCurrentBaudBitPos2 == PHAC_DISCLOOP_CON_BITR_2122)
			{
				/* Configure HW for the TypeF technology */
				PH_CHECK_SUCCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CARDTYPE_FELICA_2122));
			}
			else
			{
				/* Configure HW for the TypeF technology */
				PH_CHECK_SUCCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
					pDataParams2->pHalDataParams2,
					PHHAL_HW_CARDTYPE_FELICA_4242));
			}

			/* Symbol 8 */
			pDataParams2->bNumOfCards2 = pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2;
			return PH_ERR_SUCCESS2;
		}

		/* Re-set Collision Pending bit */
		pDataParams2->bCollPend2 &= (uint8)~(uint8)(wCurrentBaudBitPos2 & 0xFFU);

		/* Symbol 3 */
		/* SENSF_REQ with TSN := 0Fh, RC := 00h, SC := FFFFh */
		status2 = phpalFelica_SetConfig2(pDataParams2->pPalFelicaDataParams2, PHPAL_FELICA_CONFIG_RC2, 0);
		PH_CHECK_SUCCESS2(status2);

		/* Apply Guard time.(GTFB) */
		PH_CHECK_SUCCESS_FCT2(status2, phhalHw_SetConfig2(
			pDataParams2->pHalDataParams2,
			PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2,
			pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F2122]));

		if (wCurrentBaudBitPos2 == PHAC_DISCLOOP_CON_BITR_2122)
		{
			/* Configure HW for the TypeF technology */
			PH_CHECK_SUCCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CARDTYPE_FELICA_2122));
		}
		else
		{
			/* Configure HW for the TypeF technology */
			PH_CHECK_SUCCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(
				pDataParams2->pHalDataParams2,
				PHHAL_HW_CARDTYPE_FELICA_4242));
		}
		pDataParams2->bDiscLoopCollisionResolutionFState2 = 1U;
    }

	if (pDataParams2->bDiscLoopCollisionResolutionFState2 == 1U)
	{
   		PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_SendSensFReq2(pDataParams2, PHPAL_FELICA_NUMSLOTS_162, wCurrentBaudBitPos2));
		if (status2 != PH_ERR_SUCCESS2)
		{
			pDataParams2->bDiscLoopCollisionResolutionFState2 = 0U;
			return status2;
		}
		pDataParams2->bDiscLoopCollisionResolutionFState2 = 2U;
		/* Symbol 5 */
		/* Check for NFC-DEP Protocol presence within all received responses */
		bIndex2 = 0x00U;
	}

	if (pDataParams2->bDiscLoopCollisionResolutionFState2 == 2U)
	{
		while(bIndex2 < pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2)
		{
			if ((pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bIndex2].aIDmPMm2[0] == 0x01U) &&
				(pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bIndex2].aIDmPMm2[1] == 0xFEU))
			{
				break;
			}
			bIndex2++;
		} /* while(bIndex2 < pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2) */
		if (bIndex2 < pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2)
		{
			/* Symbol 6 */
			/* SENSF_REQ with TSN := 0Fh, RC := 01h, SC := FFFFh */
			status2 = phpalFelica_SetConfig2(pDataParams2->pPalFelicaDataParams2, PHPAL_FELICA_CONFIG_RC2, 0x01);
			if (status2 != PH_ERR_SUCCESS2)
			{
				pDataParams2->bDiscLoopCollisionResolutionFState2 = 0U;
				return status2;
			}
			pDataParams2->bDiscLoopCollisionResolutionFState2 = 3U;
		}
		else
		{
			pDataParams2->bDiscLoopCollisionResolutionFState2 = 0U;
			pDataParams2->bNumOfCards2 = pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2;
			return PH_ERR_SUCCESS2;
		}
    }

	if (pDataParams2->bDiscLoopCollisionResolutionFState2 == 3U)
	{
		PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_SendSensFReq2(pDataParams2, PHPAL_FELICA_NUMSLOTS_162, wCurrentBaudBitPos2));
		if (status2 != PH_ERR_SUCCESS2)
		{
			pDataParams2->bDiscLoopCollisionResolutionFState2 = 0U;
			return status2;
		}
		bIndex2++;
		if (bIndex2 < pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2)
		{
			/* continue while loop*/
			pDataParams2->bDiscLoopCollisionResolutionFState2 = 2U;
			return PH_STATUS_INPROCESS2;
		}
		pDataParams2->bNumOfCards2 = pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2;
		pDataParams2->bDiscLoopCollisionResolutionFState2 = 0U;
		return PH_ERR_SUCCESS2;
	}
    return PH_STATUS_INPROCESS2;
#else
    PH_UNUSED_VARIABLE2(pDataParams2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateF2(
                                         P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                         VAR(uint8, ANFCRL_VAR) bTypeFTagIdx2
                                         )
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIsDuplicate2 = 0x00U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 baSystemCode2[2] = {PHPAL_FELICA_SYSTEM_CODE_BYTE_02,
												PHPAL_FELICA_SYSTEM_CODE_BYTE_12};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pRxBuff2 = NULL;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pId2 = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wLen2 = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wFrames2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 IdLen2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wFrameStatus2 = PH_ERR_SUCCESS2;

	switch(pDataParams2->bDiscLoopActivateFState2)
	{
		case 0U:
			if (bTypeFTagIdx2 > pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2)
			{
				/* Out of range or no such card found yet */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
			}

			/* set given card ID to felica data param */
			PH_CHECK_SUCCESS_FCT2(status2,
					phpalFelica_SetSerialNo2(pDataParams2->pPalFelicaDataParams2,
					pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bTypeFTagIdx2].aIDmPMm2));
			/* Symbol 0 */
			if ((pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bTypeFTagIdx2].aIDmPMm2[0] == 0x01U) &&
				(pDataParams2->sTypeFTargetInfo2.aTypeFTag2[bTypeFTagIdx2].aIDmPMm2[1] == 0xFEU))
			{
				/* Single device is detected. Activation is already done during collision resolution */
				/* Symbol 1 */
				if(pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2 != 1U)
				{
					/* Symbol 2 */
					/* SENSF_REQ with TSN := 0Fh, RC := 00h, SC := FFFFh */
					status2 = phpalFelica_SetConfig2(pDataParams2->pPalFelicaDataParams2, PHPAL_FELICA_CONFIG_RC2, 0);
					PH_CHECK_SUCCESS2(status2);
					pDataParams2->bDiscLoopActivateFState2 = 1U;
				}
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				return PH_ERR_SUCCESS2;
			}
			/* no break */
		case 1U:
			PH_CHECK_INPROCESS_FCT2(status2, phpalFelica_ReqC2(pDataParams2->pPalFelicaDataParams2, baSystemCode2, PHPAL_FELICA_NUMSLOTS_162, &pRxBuff2, &wLen2));
			PH_BREAK_ON_FAILURE2(status2);
			PH_CHECK_FAILURE_FCT2(status2, phpalFelica_GetConfig2(pDataParams2->pPalFelicaDataParams2, PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES2, &wFrames2));
			pDataParams2->bDiscLoopActivateFState2 = 2U;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case 2U:
			if((0U != wFrames2) && (0U == bIsDuplicate2))
			{
				IdLen2 = 0x00;
				wFrameStatus2 = 0x00;

				PH_CHECK_FAILURE_FCT2(status2, phpalFelica_GetFrameInfo2(
					pDataParams2->pPalFelicaDataParams2,
					(uint8)wFrames2,
					pRxBuff2,
					&wFrameStatus2,
					&pId2,
					&IdLen2));

				/* Check Device ID into greedy collection  */
				/* Check Same response already present or not */
				PH_CHECK_FAILURE_FCT2(status2, phacDiscLoop_Sw_Int_CheckForDuplication2(
					pDataParams2,
					pId2,
					&bIsDuplicate2));

				wFrames2--;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* If same response is not present means Device not present
				 * or some other error has occurred
				 * Report DiscLoop Failure in this case */
				if(0U == (bIsDuplicate2))
				{
					status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_FAILURE2, PH_COMP_AC_DISCLOOP2);
					PH_BREAK_ON_FAILURE2(status2);
				}
			}
			break;
		default:
			break;
	}

	pDataParams2->bDiscLoopActivateFState2 = 0U;
	bIsDuplicate2 = 0x00U;
	wFrames2 = 0U;
	return status2;
#else
	PH_UNUSED_VARIABLE2(pDataParams2);
	PH_UNUSED_VARIABLE2(bTypeFTagIdx2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
}

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_Config_GTF2(
                                          P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                          VAR(uint8, ANFCRL_VAR) bTechIndex2
                                          )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_INTERNAL_ERROR2;

    /*
     * If either one of Felica 212 or Felica 424 is polled after Type B polling,
     * then GTbf is applied. Default value is 15.3 ms (PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT).
     * In this case Type B poll is followed by Felica poll.
     */
    if((0U != ((pDataParams2->bPasPollTechCfg2 & PHAC_DISCLOOP_POS_BIT_MASK_B2))) &&
        ((pDataParams2->bFelicaBaud2 == PHAC_DISCLOOP_CON_BITR_2122) ||
        ((pDataParams2->bFelicaBaud2 == PHAC_DISCLOOP_CON_BITR_4242) &&
        (0U == ((pDataParams2->bPasPollTechCfg2 & PHAC_DISCLOOP_POS_BIT_MASK_F2122))))))
    {
        /* apply guard time GTBF */
        PH_CHECK_SUCCESS_FCT2(wStatus2, phhalHw_SetConfig2(
            pDataParams2->pHalDataParams2,
            PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2,
            pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F4242]));
    }
    else
    {
        /*
         * If Type F polling is not preceded by a Type B poll apply guard time GTFB
         * Default value of GTFB is 20.4ms (PH_NXPNFCRDLIB_CONFIG_TYPEF_GT).
         *
         */
        PH_CHECK_SUCCESS_FCT2(wStatus2, phhalHw_SetConfig2(
            pDataParams2->pHalDataParams2,
            PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2,
            pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F2122]));
    }

    if ((uint8)PHAC_DISCLOOP_TECH_TYPE_F4242 == bTechIndex2)
    {
        PH_CHECK_SUCCESS_FCT2(wStatus2, phacDiscLoop_SetConfig2(pDataParams2, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2, PHAC_DISCLOOP_CON_BITR_4242));
    }
    else
    {
        PH_CHECK_SUCCESS_FCT2(wStatus2, phacDiscLoop_SetConfig2(pDataParams2, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2, PHAC_DISCLOOP_CON_BITR_2122));
    }

    return PH_ERR_SUCCESS2;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif
