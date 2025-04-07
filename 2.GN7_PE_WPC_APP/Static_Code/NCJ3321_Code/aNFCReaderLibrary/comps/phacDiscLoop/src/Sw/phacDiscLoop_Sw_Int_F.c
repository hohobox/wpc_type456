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
*   @file    phacDiscLoop_Sw_Int_F.c
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
#include <phpalFelica.h>
#include "phacDiscLoop_Sw.h"
#include <phTools.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw_Int.h"
#include "phacDiscLoop_Sw_Int_F.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int_F.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_F_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int_F.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_F_VENDOR_ID_C != PHACDISCLOOP_SW_INT_F_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int_F.c and phacDiscLoop_Sw_Int_F.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_F.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_INT_F_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int_F.c and phacDiscLoop_Sw_Int_F.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int_F.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_INT_F_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_INT_F_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_INT_F_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int_F.c and phacDiscLoop_Sw_Int_F.h are different"
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
#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS

/* Perform check whether same TypeF tag/device already detected with higher baud rate */
static FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_CheckForDuplication(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pID,  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsDuplicate)
{
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bIndex = 0x00;

    *pIsDuplicate = PH_OFF;

    for(bIndex = 0; bIndex < pDataParams->sTypeFTargetInfo.bTotalTagsFound; bIndex++)
    {   /* Skip Identical Entry */
        if((memcmp(pID, pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm, PHAC_DISCLOOP_FELICA_IDM_LENGTH + PHAC_DISCLOOP_FELICA_PMM_LENGTH )) == 0)
        {
            *pIsDuplicate = PH_ON;
            /* Update baud rate if device is detected with higher baud rate */
            break;
        }
    }
    return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS

/* Parse and update greedy collection with Responses */
static FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_UpdateSensFResp(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pID,
    VAR(uint8, ANFCRL_VAR) bIdLen, VAR(uint16, ANFCRL_VAR) wCurrentBaudBitPos)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsDuplicate;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTotalTagsFound = 0x00;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wRequestCode;

	PH_CHECK_SUCCESS_FCT(wStatus, phacDiscLoop_Sw_Int_CheckForDuplication(pDataParams, &pID[0x00], &bIsDuplicate));
	if(0U == (bIsDuplicate))
	{
		/* get Request code is enable */
		PH_CHECK_SUCCESS_FCT(wStatus, phpalFelica_GetConfig(pDataParams->pPalFelicaDataParams, PHPAL_FELICA_CONFIG_RC, &wRequestCode));

		/* Copy ReqCode */
		if((wRequestCode != PH_OFF) && (bIdLen > (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH)))
		{
			(void)phTools_memcpy((uint8 *)&(pDataParams->sTypeFTargetInfo.aTypeFTag[pDataParams->sTypeFTargetInfo.bTotalTagsFound + bTotalTagsFound].aRD), &pID[PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH], PHPAL_FELICA_RD_LENGTH);
		}
		/* Copy IDMmPMm */
		(void)phTools_memcpy( (uint8 *)&(pDataParams->sTypeFTargetInfo.aTypeFTag[pDataParams->sTypeFTargetInfo.bTotalTagsFound + bTotalTagsFound].aIDmPMm), pID, (PHPAL_FELICA_IDM_LENGTH + PHPAL_FELICA_PMM_LENGTH));
		pDataParams->sTypeFTargetInfo.aTypeFTag[pDataParams->sTypeFTargetInfo.bTotalTagsFound + bTotalTagsFound].bBaud = (uint8)(wCurrentBaudBitPos & 0xFFU);

		/* Increment Tag count */
		bTotalTagsFound++;
	}

	pDataParams->sTypeFTargetInfo.bTotalTagsFound += bTotalTagsFound;

	return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS

/* Send SENSF_REQ command and process received response */
static FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_SendSensFReq(
                                                      P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                      VAR(uint8, ANFCRL_VAR) bNumTimeSlots,
                                                      VAR(uint16, ANFCRL_VAR) wCurrentBaudBitPos
                                                      )
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_INTERNAL_ERROR;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF baSystemCode[2] = {PHPAL_FELICA_SYSTEM_CODE_BYTE_0,
												PHPAL_FELICA_SYSTEM_CODE_BYTE_1};
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTemp = 0U;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pId = NULL;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuff = NULL;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIdLen = 0U;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wFrameStatus = PH_ERR_INTERNAL_ERROR;

	switch(pDataParams->bDiscLoopSendSensFReq)
	{
		case 0U:
			/* send ReqC command */
			PH_CHECK_INPROCESS_FCT(wStatus, phpalFelica_ReqC(pDataParams->pPalFelicaDataParams, baSystemCode, bNumTimeSlots, &pRxBuff, &wTemp));
			if((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				pDataParams->bDiscLoopSendSensFReq = 1U;
			}
			else
			{
				return wStatus;
			}
			/*no break*/
		case 1U:
			if(bNumTimeSlots > PHPAL_FELICA_NUMSLOTS_1)
			{
				/* get total number of response frame */
				PH_CHECK_FAILURE_FCT(wStatus, phpalFelica_GetConfig(pDataParams->pPalFelicaDataParams, PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES, &wTemp));
				pDataParams->bDiscLoopSendSensFReq = 2U;
			}
			else
			{
				/* store received IDmPMm */
				PH_CHECK_FAILURE_FCT(wStatus, phacDiscLoop_Sw_Int_UpdateSensFResp(pDataParams, pRxBuff, (uint8)wTemp, wCurrentBaudBitPos));
				pDataParams->bDiscLoopSendSensFReq = 3U;
			}
			return PH_STATUS_INPROCESS;
			/*no break*/
		case 2U:
			if(0U != wTemp)
			{
				bIdLen = 0x00U;
				wFrameStatus = 0x00U;
				/* retrieve IDmPMm one by one for all frames */
				PH_CHECK_FAILURE_FCT(wStatus, phpalFelica_GetFrameInfo(
						pDataParams->pPalFelicaDataParams,
						(uint8)wTemp,
						pRxBuff,
						&wFrameStatus,
						&pId,
						&bIdLen));

				if(wFrameStatus == PH_ERR_SUCCESS)
				{
					/* store received IDmPMm */
					PH_CHECK_FAILURE_FCT(wStatus, phacDiscLoop_Sw_Int_UpdateSensFResp(pDataParams, pId, bIdLen, wCurrentBaudBitPos));
				}
				wTemp--;

				/* Check for device limit */
				if(pDataParams->sTypeFTargetInfo.bTotalTagsFound >= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212])
				{
					pDataParams->bDiscLoopSendSensFReq = 3U;
				}
				else
				{
					return PH_STATUS_INPROCESS;
				}
			}
			else
			{
				pDataParams->bDiscLoopSendSensFReq = 3U;
			}
			/*no break*/
		case 3U:
			wTemp = 0U;
			pDataParams->bDiscLoopSendSensFReq = 0U;
			/*Response is success but no device found*/
			if (pDataParams->sTypeFTargetInfo.bTotalTagsFound == 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR,	PH_COMP_AC_DISCLOOP);
			}
			else
			{
				return PH_ERR_SUCCESS;
			}
			/*no break*/
		default:
			wStatus = PH_ERR_INTERNAL_ERROR;
			break;
	}

	pRxBuff = NULL;
	wTemp = 0U;
	pDataParams->bDiscLoopSendSensFReq = 0U;
	return wStatus;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_DetTechTypeF(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrentBaudBitPos = 0u;

	switch(pDataParams->bDiscLoopDetTechTypeF)
	{
		case 0U:
			PH_CHECK_SUCCESS_FCT(wStatus,
			phpalFelica_SetConfig(pDataParams->pPalFelicaDataParams, PHPAL_FELICA_CONFIG_RC, PH_OFF));

			/* get current felica baud rate */
			PH_CHECK_SUCCESS_FCT(wStatus, phacDiscLoop_GetConfig(pDataParams, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD, &wCurrentBaudBitPos));

			/* if any tag has detected, do not reset the tag count */
			if (0U
					== (pDataParams->bDetectedTechs
							& (PHAC_DISCLOOP_POS_BIT_MASK_F424 | PHAC_DISCLOOP_POS_BIT_MASK_F212)))
			{
				pDataParams->sTypeFTargetInfo.bTotalTagsFound = 0;
			}

			/* re-set Collision Pending bit */
			pDataParams->bCollPend &= (uint8) ~(uint8) (wCurrentBaudBitPos & 0xFFU);
			pDataParams->bDiscLoopDetTechTypeF = 1U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 1U:
			PH_CHECK_INPROCESS_FCT(wStatus, phacDiscLoop_Sw_Int_SendSensFReq(pDataParams, PHPAL_FELICA_NUMSLOTS_4, wCurrentBaudBitPos));
			if (0u != (phacDiscLoop_Sw_Int_IsValidPollStatus(wStatus)))
			{
				if ((wStatus & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
				{
					/* set Collision Pending bit */
					pDataParams->bCollPend |= (uint8) (wCurrentBaudBitPos & 0xFFU);
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
			wStatus = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
			break;
		default:
			break;
	}

	pDataParams->bDiscLoopDetTechTypeF = 0U;
	wCurrentBaudBitPos = 0U;
	return wStatus;
#else
	PH_UNUSED_VARIABLE(pDataParams);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_CollisionResolutionF (P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCurrentBaudBitPos = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bIndex = 0U;

	if (pDataParams->bDiscLoopCollisionResolutionFState == 0U)
    {
		PH_CHECK_SUCCESS_FCT(status, phacDiscLoop_GetConfig(pDataParams, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD, &wCurrentBaudBitPos));

		/* Collision_Pending = 1 and Device limit  = 0 */
		if((0U != ((pDataParams->bCollPend & wCurrentBaudBitPos))) && ((pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212] == 0x00U)))
		{
			pDataParams->sTypeFTargetInfo.bTotalTagsFound = 0;
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
		}

		/* Symbol 1 */
		/* Symbol 2*/
		/* Device limit for F424 and F212 is same */
		if(pDataParams->sTypeFTargetInfo.bTotalTagsFound >= pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212])
		{
			if (wCurrentBaudBitPos == PHAC_DISCLOOP_CON_BITR_212)
			{
				/* Configure HW for the TypeF technology */
				PH_CHECK_SUCCESS_FCT(status, phhalHw_ApplyProtocolSettings(
					pDataParams->pHalDataParams,
					PHHAL_HW_CARDTYPE_FELICA_212));
			}
			else
			{
				/* Configure HW for the TypeF technology */
				PH_CHECK_SUCCESS_FCT(status, phhalHw_ApplyProtocolSettings(
					pDataParams->pHalDataParams,
					PHHAL_HW_CARDTYPE_FELICA_424));
			}

			/* Symbol 8 */
			pDataParams->bNumOfCards = pDataParams->sTypeFTargetInfo.bTotalTagsFound;
			return PH_ERR_SUCCESS;
		}

		/* Re-set Collision Pending bit */
		pDataParams->bCollPend &= (uint8)~(uint8)(wCurrentBaudBitPos & 0xFFU);

		/* Symbol 3 */
		/* SENSF_REQ with TSN := 0Fh, RC := 00h, SC := FFFFh */
		status = phpalFelica_SetConfig(pDataParams->pPalFelicaDataParams, PHPAL_FELICA_CONFIG_RC, 0);
		PH_CHECK_SUCCESS(status);

		/* Apply Guard time.(GTFB) */
		PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(
			pDataParams->pHalDataParams,
			PHHAL_HW_CONFIG_POLL_GUARD_TIME_US,
			pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F212]));

		if (wCurrentBaudBitPos == PHAC_DISCLOOP_CON_BITR_212)
		{
			/* Configure HW for the TypeF technology */
			PH_CHECK_SUCCESS_FCT(status, phhalHw_ApplyProtocolSettings(
				pDataParams->pHalDataParams,
				PHHAL_HW_CARDTYPE_FELICA_212));
		}
		else
		{
			/* Configure HW for the TypeF technology */
			PH_CHECK_SUCCESS_FCT(status, phhalHw_ApplyProtocolSettings(
				pDataParams->pHalDataParams,
				PHHAL_HW_CARDTYPE_FELICA_424));
		}
		pDataParams->bDiscLoopCollisionResolutionFState = 1U;
    }

	if (pDataParams->bDiscLoopCollisionResolutionFState == 1U)
	{
   		PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_SendSensFReq(pDataParams, PHPAL_FELICA_NUMSLOTS_16, wCurrentBaudBitPos));
		if (status != PH_ERR_SUCCESS)
		{
			pDataParams->bDiscLoopCollisionResolutionFState = 0U;
			return status;
		}
		pDataParams->bDiscLoopCollisionResolutionFState = 2U;
		/* Symbol 5 */
		/* Check for NFC-DEP Protocol presence within all received responses */
		bIndex = 0x00U;
	}

	if (pDataParams->bDiscLoopCollisionResolutionFState == 2U)
	{
		while(bIndex < pDataParams->sTypeFTargetInfo.bTotalTagsFound)
		{
			if ((pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm[0] == 0x01U) &&
				(pDataParams->sTypeFTargetInfo.aTypeFTag[bIndex].aIDmPMm[1] == 0xFEU))
			{
				break;
			}
			bIndex++;
		} /* while(bIndex < pDataParams->sTypeFTargetInfo.bTotalTagsFound) */
		if (bIndex < pDataParams->sTypeFTargetInfo.bTotalTagsFound)
		{
			/* Symbol 6 */
			/* SENSF_REQ with TSN := 0Fh, RC := 01h, SC := FFFFh */
			status = phpalFelica_SetConfig(pDataParams->pPalFelicaDataParams, PHPAL_FELICA_CONFIG_RC, 0x01);
			if (status != PH_ERR_SUCCESS)
			{
				pDataParams->bDiscLoopCollisionResolutionFState = 0U;
				return status;
			}
			pDataParams->bDiscLoopCollisionResolutionFState = 3U;
		}
		else
		{
			pDataParams->bDiscLoopCollisionResolutionFState = 0U;
			pDataParams->bNumOfCards = pDataParams->sTypeFTargetInfo.bTotalTagsFound;
			return PH_ERR_SUCCESS;
		}
    }

	if (pDataParams->bDiscLoopCollisionResolutionFState == 3U)
	{
		PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_SendSensFReq(pDataParams, PHPAL_FELICA_NUMSLOTS_16, wCurrentBaudBitPos));
		if (status != PH_ERR_SUCCESS)
		{
			pDataParams->bDiscLoopCollisionResolutionFState = 0U;
			return status;
		}
		bIndex++;
		if (bIndex < pDataParams->sTypeFTargetInfo.bTotalTagsFound)
		{
			/* continue while loop*/
			pDataParams->bDiscLoopCollisionResolutionFState = 2U;
			return PH_STATUS_INPROCESS;
		}
		pDataParams->bNumOfCards = pDataParams->sTypeFTargetInfo.bTotalTagsFound;
		pDataParams->bDiscLoopCollisionResolutionFState = 0U;
		return PH_ERR_SUCCESS;
	}
    return PH_STATUS_INPROCESS;
#else
    PH_UNUSED_VARIABLE(pDataParams);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateF(
                                         P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                         VAR(uint8, ANFCRL_VAR) bTypeFTagIdx
                                         )
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIsDuplicate = 0x00U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF baSystemCode[2] = {PHPAL_FELICA_SYSTEM_CODE_BYTE_0,
												PHPAL_FELICA_SYSTEM_CODE_BYTE_1};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pRxBuff = NULL;
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pId = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wLen = 0U;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrames = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM IdLen = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wFrameStatus = PH_ERR_SUCCESS;

	switch(pDataParams->bDiscLoopActivateFState)
	{
		case 0U:
			if (bTypeFTagIdx > pDataParams->sTypeFTargetInfo.bTotalTagsFound)
			{
				/* Out of range or no such card found yet */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
			}

			/* set given card ID to felica data param */
			PH_CHECK_SUCCESS_FCT(status,
					phpalFelica_SetSerialNo(pDataParams->pPalFelicaDataParams,
					pDataParams->sTypeFTargetInfo.aTypeFTag[bTypeFTagIdx].aIDmPMm));
			/* Symbol 0 */
			if ((pDataParams->sTypeFTargetInfo.aTypeFTag[bTypeFTagIdx].aIDmPMm[0] == 0x01U) &&
				(pDataParams->sTypeFTargetInfo.aTypeFTag[bTypeFTagIdx].aIDmPMm[1] == 0xFEU))
			{
				/* Single device is detected. Activation is already done during collision resolution */
				/* Symbol 1 */
				if(pDataParams->sTypeFTargetInfo.bTotalTagsFound != 1U)
				{
					/* Symbol 2 */
					/* SENSF_REQ with TSN := 0Fh, RC := 00h, SC := FFFFh */
					status = phpalFelica_SetConfig(pDataParams->pPalFelicaDataParams, PHPAL_FELICA_CONFIG_RC, 0);
					PH_CHECK_SUCCESS(status);
					pDataParams->bDiscLoopActivateFState = 1U;
				}
				return PH_STATUS_INPROCESS;
			}
			else
			{
				return PH_ERR_SUCCESS;
			}
			/* no break */
		case 1U:
			PH_CHECK_INPROCESS_FCT(status, phpalFelica_ReqC(pDataParams->pPalFelicaDataParams, baSystemCode, PHPAL_FELICA_NUMSLOTS_16, &pRxBuff, &wLen));
			PH_BREAK_ON_FAILURE(status);
			PH_CHECK_FAILURE_FCT(status, phpalFelica_GetConfig(pDataParams->pPalFelicaDataParams, PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES, &wFrames));
			pDataParams->bDiscLoopActivateFState = 2U;
			return PH_STATUS_INPROCESS;
			/* no break */
		case 2U:
			if((0U != wFrames) && (0U == bIsDuplicate))
			{
				IdLen = 0x00;
				wFrameStatus = 0x00;

				PH_CHECK_FAILURE_FCT(status, phpalFelica_GetFrameInfo(
					pDataParams->pPalFelicaDataParams,
					(uint8)wFrames,
					pRxBuff,
					&wFrameStatus,
					&pId,
					&IdLen));

				/* Check Device ID into greedy collection  */
				/* Check Same response already present or not */
				PH_CHECK_FAILURE_FCT(status, phacDiscLoop_Sw_Int_CheckForDuplication(
					pDataParams,
					pId,
					&bIsDuplicate));

				wFrames--;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* If same response is not present means Device not present
				 * or some other error has occurred
				 * Report DiscLoop Failure in this case */
				if(0U == (bIsDuplicate))
				{
					status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_FAILURE, PH_COMP_AC_DISCLOOP);
					PH_BREAK_ON_FAILURE(status);
				}
			}
			break;
		default:
			break;
	}

	pDataParams->bDiscLoopActivateFState = 0U;
	bIsDuplicate = 0x00U;
	wFrames = 0U;
	return status;
#else
	PH_UNUSED_VARIABLE(pDataParams);
	PH_UNUSED_VARIABLE(bTypeFTagIdx);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
}

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_Config_GTF(
                                          P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                          VAR(uint8, ANFCRL_VAR) bTechIndex
                                          )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_INTERNAL_ERROR;

    /*
     * If either one of Felica 212 or Felica 424 is polled after Type B polling,
     * then GTbf is applied. Default value is 15.3 ms (PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT).
     * In this case Type B poll is followed by Felica poll.
     */
    if((0U != ((pDataParams->bPasPollTechCfg & PHAC_DISCLOOP_POS_BIT_MASK_B))) &&
        ((pDataParams->bFelicaBaud == PHAC_DISCLOOP_CON_BITR_212) ||
        ((pDataParams->bFelicaBaud == PHAC_DISCLOOP_CON_BITR_424) &&
        (0U == ((pDataParams->bPasPollTechCfg & PHAC_DISCLOOP_POS_BIT_MASK_F212))))))
    {
        /* apply guard time GTBF */
        PH_CHECK_SUCCESS_FCT(wStatus, phhalHw_SetConfig(
            pDataParams->pHalDataParams,
            PHHAL_HW_CONFIG_POLL_GUARD_TIME_US,
            pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F424]));
    }
    else
    {
        /*
         * If Type F polling is not preceded by a Type B poll apply guard time GTFB
         * Default value of GTFB is 20.4ms (PH_NXPNFCRDLIB_CONFIG_TYPEF_GT).
         *
         */
        PH_CHECK_SUCCESS_FCT(wStatus, phhalHw_SetConfig(
            pDataParams->pHalDataParams,
            PHHAL_HW_CONFIG_POLL_GUARD_TIME_US,
            pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F212]));
    }

    if ((uint8)PHAC_DISCLOOP_TECH_TYPE_F424 == bTechIndex)
    {
        PH_CHECK_SUCCESS_FCT(wStatus, phacDiscLoop_SetConfig(pDataParams, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD, PHAC_DISCLOOP_CON_BITR_424));
    }
    else
    {
        PH_CHECK_SUCCESS_FCT(wStatus, phacDiscLoop_SetConfig(pDataParams, PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD, PHAC_DISCLOOP_CON_BITR_212));
    }

    return PH_ERR_SUCCESS;
}
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_F_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_F_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif
