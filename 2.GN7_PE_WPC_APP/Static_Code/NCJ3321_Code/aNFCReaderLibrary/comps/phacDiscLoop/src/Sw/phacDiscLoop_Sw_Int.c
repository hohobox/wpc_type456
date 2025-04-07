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
*   @file    phacDiscLoop_Sw_Int.c
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
#include <phpalI14443p3a.h>
#include <phpalI14443p3b.h>

#include "phacDiscLoop_Sw_Int_A.h"
#include "phacDiscLoop_Sw_Int_B.h"
#include "phacDiscLoop_Sw_Int_F.h"
#include "phacDiscLoop_Sw_Int_V.h"

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw_Int.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_VENDOR_ID_C != PHACDISCLOOP_SW_INT_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int.c and phacDiscLoop_Sw_Int.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int.c and phacDiscLoop_Sw_Int.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_INT_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_INT_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_INT_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int.c and phacDiscLoop_Sw_Int.h are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#define PHAC_DISCLOOP_HALTA_TIMOUT_US     1100U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint32, ANFCRL_CONST) gPasTechTypeMapTable[] = {
    PHHAL_HW_CARDTYPE_ISO14443A,
    PHHAL_HW_CARDTYPE_ISO14443B,
    PHHAL_HW_CARDTYPE_FELICA_212,
    PHHAL_HW_CARDTYPE_FELICA_424,
    PHHAL_HW_CARDTYPE_ISO15693
};

static CONST(pphacDiscLoop_Sw_Reslns, ANFCRL_CONST) pfColnRelsns[] = {
    &phacDiscLoop_Sw_Int_CollisionResolutionA,
    &phacDiscLoop_Sw_Int_CollisionResolutionB,
    &phacDiscLoop_Sw_Int_CollisionResolutionF,
    &phacDiscLoop_Sw_Int_CollisionResolutionF,
    &phacDiscLoop_Sw_Int_CollisionResolutionV
};

static CONST(pphacDiscLoop_Sw_DetTechs, ANFCRL_CONST) pfDetTechs[] = {
    &phacDiscLoop_Sw_DetTechTypeA,
    &phacDiscLoop_Sw_DetTechTypeB,
    &phacDiscLoop_Sw_DetTechTypeF,
    &phacDiscLoop_Sw_DetTechTypeF,
    &phacDiscLoop_Sw_DetTechTypeV
};

static CONST(pphacDiscLoop_Sw_DeviceActivate, ANFCRL_CONST) pfDeviceActivate[] = {
    &phacDiscLoop_Sw_Int_ActivateA,
    &phacDiscLoop_Sw_Int_ActivateB,
    &phacDiscLoop_Sw_Int_ActivateF,
    &phacDiscLoop_Sw_Int_ActivateF,
    &phacDiscLoop_Sw_Int_ActivateV
};
#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ListenMode(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INTERNAL_ERROR;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRetryCount = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wTempMode = 0x00u;

	/* get active listen cfg except F424 */
	wTempMode = (uint16)pDataParams->bActLisTechCfg & 0x0007U;

	/* Map Active F424 configuration with Type F bit in Autocoll */
	if(0U != (pDataParams->bActLisTechCfg & PHAC_DISCLOOP_POS_BIT_MASK_F424))
	{
		wTempMode = wTempMode | PHAC_DISCLOOP_POS_BIT_MASK_F212;
	}

	wTempMode = (uint16) (wTempMode << 8U);

	/* get passive listen cfg except F424 */
	wTempMode = wTempMode | ((uint16)pDataParams->bPasLisTechCfg & 0x0007u);

	/* Map Passive F424 configuration with Type F bit in Autocoll */
	if(0U != (pDataParams->bPasLisTechCfg & PHAC_DISCLOOP_POS_BIT_MASK_F424))
	{
		wTempMode = wTempMode | PHAC_DISCLOOP_POS_BIT_MASK_F212;
	}

	/* AUTOCOLL retry loop */

	PH_CHECK_INPROCESS_FCT(status, phhalHw_Autocoll(
		pDataParams->pHalDataParams,
		wTempMode,
		&pDataParams->sTargetParams.pRxBuffer,
		&pDataParams->sTargetParams.wRxBufferLen,
		&pDataParams->sTargetParams.wProtParams));
	if(((status & PH_ERR_MASK) != PH_ERR_SUCCESS) && ((pDataParams->sTargetParams.bRetryCount - bRetryCount) != 0u))
	{
		bRetryCount++;
		return PH_STATUS_INPROCESS;
	}
	bRetryCount = 0U;
	/* Return RF OFF error, if external RF is OFF */
	if((status & PH_ERR_MASK) == PH_ERR_EXT_RF_ERROR)
	{
		return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_EXTERNAL_RFOFF, PH_COMP_AC_DISCLOOP);
	}
	else
	{
		/* Return, if error */
		PH_CHECK_SUCCESS(status);
	}

	return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_ACTIVATED_BY_PEER, PH_COMP_AC_DISCLOOP);
#else /* NXPBUILD__PHAC_DISCLOOP_TARGET */
	PH_UNUSED_VARIABLE(pDataParams);
	return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_AC_DISCLOOP);
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET */
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_Stop(
                                    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                    )
{
    /* RFU */
    UNUSED(pDataParams);
    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivePollMode(
                                              P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                              )
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bIndex;
	/* Reset detected technologies */
	pDataParams->bDetectedTechs = 0x00;

	/* Loop through all the supported active technologies */
	for (bIndex = 0; bIndex < PHAC_DISCLOOP_ACT_POLL_MAX_TECHS_SUPPORTED; bIndex++)
	{
		switch (pDataParams->bActPollTechCfg & (PH_ON << bIndex))
		{
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_106:
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_212:
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_424:
				break;

			default:
				break;
		}
	}
	/* No Target present. */
    return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_PollMode(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_INVALID_PARAMETER;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bResolveTech = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTechType = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumOfTechsFound = 0U;

	if (pDataParams->bPollState == PHAC_DISCLOOP_POLL_STATE_DETECTION)
	{
		if ((pDataParams->bOpeMode == RD_LIB_MODE_NFC) || (pDataParams->bOpeMode == RD_LIB_MODE_ISO))
		{
			/* Perform Technology detection Activity */
			PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_TechDetectActivity(pDataParams,
					pDataParams->bPasPollBailOut, pDataParams->bPasPollTechCfg, &bNumOfTechsFound));
			pDataParams->bDiscLoopPollModeState = 0U;
			/* Return if status is aborted. */
			PH_CHECK_ABORT(status);
		}
		else
		{
			;/* Do Nothing */
		}

		if ((0U != (pDataParams->bLpcdEnabled)) && (0U != (pDataParams->bPasPollTechCfg))
				&& ((status & PH_ERR_MASK) == PHAC_DISCLOOP_NO_TECH_DETECTED))
		{
			/* LPCD is success but card presence does not exist/errors */
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
		}

		if ((status & PH_ERR_MASK) == PHAC_DISCLOOP_TECH_DETECTED)
		{
			pDataParams->bPollState = PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION;
		}
	}

	/* Go for collision resolution if single tech found */
	if (pDataParams->bPollState == PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION)
	{
		/* Get Technology to be resolved */
		if (pDataParams->bDiscLoopPollModeState == 0U)
		{
			bResolveTech = pDataParams->bDetectedTechs & pDataParams->bPasPollTechCfg;
			if (0U != (bResolveTech))
			{
				if (0U != (bResolveTech & (uint8) (bResolveTech - 1U)))
				{
					pDataParams->bPollState = PHAC_DISCLOOP_POLL_STATE_DETECTION;
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
				}
			}
			else
			{
				pDataParams->bPollState = PHAC_DISCLOOP_POLL_STATE_DETECTION;
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
			}
			PHAC_DISCLOOP_GET_BIT_POS(bResolveTech, bTechType);
			pDataParams->bDiscLoopPollModeState = 1U;
		}

		if (pDataParams->bDiscLoopPollModeState == 1U)
		{
			PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_ColsnReslnActivity(pDataParams, (bTechType - (uint8) 1U)));
			pDataParams->bDiscLoopPollModeState = 0U;
			if ((status & PH_ERR_MASK) == PHAC_DISCLOOP_DEVICE_RESOLVED)
			{
				/* Activation */
				pDataParams->bDiscLoopPollModeState = 2U;
			}
		}

		if (pDataParams->bDiscLoopPollModeState == 2U)
		{
			PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_ActivateDevice(pDataParams, (bTechType - (uint8) 1U), (uint8) 0x00U));
			pDataParams->bDiscLoopPollModeState = 0U;
		}
		pDataParams->bPollState = PHAC_DISCLOOP_POLL_STATE_DETECTION;
		/* Return if status is aborted. */
		PH_CHECK_ABORT(status);
	}
	return PH_ADD_COMPCODE(status, PH_COMP_AC_DISCLOOP);
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_TechDetectActivity(
                                                  P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                  VAR(uint8, ANFCRL_VAR) bPasPollBailOut,
                                                  VAR(uint8, ANFCRL_VAR) bDetectConfig,
                                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumOfTechsDetect
                                                  )
{
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PHAC_DISCLOOP_NO_TECH_DETECTED;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT bTechIndex = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumOfTechsFound = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTechTypeF_Detected = PH_OFF;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wIntFieldStatus = 0U;
	VAR(uint16, ANFCRL_VAR) wEmdMode = 0U;
	static VAR(uint8, ANFCRL_VAR) bVasFlag = 0U;
	static VAR(uint8, ANFCRL_VAR) bQuitFlag = 0U;

	if (pDataParams->bDiscLoopTechDetectActivityState == 0U)
	{
		pDataParams->bDetectedTechs = 0x00;
		pDataParams->bNumOfCards = 0x00;
		bTechIndex = 0U;
		bNumOfTechsFound = 0U;
		bTechTypeF_Detected = PH_OFF;
		wIntFieldStatus = 0U;
		bQuitFlag = 0U;
		bVasFlag = 0U;
		status = PHAC_DISCLOOP_NO_TECH_DETECTED;
		pDataParams->bDiscLoopTechDetectActivityState = 1U;
	}
	/* Poll for requested NFC-Tech Type presence. */
	while ((bTechIndex < PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED) && (bQuitFlag == 0U))
	{
		if (pDataParams->bDiscLoopTechDetectActivityState == 1U)
		{
			/* In NFC mode, poll proprietary technologies only if NFC technologies are not detected */
			if ((pDataParams->bOpeMode == RD_LIB_MODE_NFC) && (0U != bNumOfTechsFound)
					&& (bTechIndex == PHAC_DISCLOOP_POLL_MAX_NFC_TECHS_SUPPORTED))
			{
				break;
			}

			if (((bTechIndex == (uint8)PHAC_DISCLOOP_TECH_TYPE_F212) || (bTechIndex == (uint8)PHAC_DISCLOOP_TECH_TYPE_F424))
				&& (bTechTypeF_Detected == PH_ON))
			{
				bTechIndex++;
				continue;
			}
			pDataParams->bDiscLoopTechDetectActivityState = 2U;
		}
		if (0U != (bDetectConfig & (PH_ON << bTechIndex)))
		{
			if (pDataParams->bDiscLoopTechDetectActivityState == 2U)
			{
				/* Get Config to check the internal Field On. */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_INT_RF_ON, &wIntFieldStatus));
				if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
				{
					pDataParams->bDiscLoopTechDetectActivityState = 0U;
					return status;
				}

				if (wIntFieldStatus == PH_ON)
				{
					if (((uint8) PHAC_DISCLOOP_TECH_TYPE_F212 == bTechIndex)
							|| ((uint8) PHAC_DISCLOOP_TECH_TYPE_F424 == bTechIndex))
					{
	#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
						status = phacDiscLoop_Sw_Int_Config_GTF(pDataParams, bTechIndex);
						if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
						{
							pDataParams->bDiscLoopTechDetectActivityState = 0U;
							return status;
						}
	#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
					}
					else
					{
						/* Apply Guard time. */
						status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US, pDataParams->waPasPollGTimeUs[bTechIndex]);
						if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
						{
							pDataParams->bDiscLoopTechDetectActivityState = 0U;
							return status;
						}
					}
				}
				pDataParams->bDiscLoopTechDetectActivityState = 3U;
			}

			if (pDataParams->bDiscLoopTechDetectActivityState == 3U)
			{
				PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(pDataParams->pHalDataParams,	(uint8 )(gPasTechTypeMapTable[bTechIndex] & 0xFFU)));
				if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
				{
					pDataParams->bDiscLoopTechDetectActivityState = 0U;
					return status;
				}
				pDataParams->bDiscLoopTechDetectActivityState = 4U;
			}

			if (pDataParams->bDiscLoopTechDetectActivityState == 4U)
			{
				/* Perform I-RFCA and Switch on RF Field after Apply protocol settings, if in NFC and ISO mode. */
				PH_CHECK_INPROCESS_FCT(status, phacDiscLoop_Sw_Int_FieldOn(pDataParams));
				if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
				{
					pDataParams->bDiscLoopTechDetectActivityState = 0U;
					return status;
				}
				pDataParams->bDiscLoopTechDetectActivityState = 5U;
			}

			if (pDataParams->bDiscLoopTechDetectActivityState == 5U)
			{
				status = phhalHw_GetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_EMD_MODE, &wEmdMode);
				if ((status == PH_ERR_SUCCESS) && (wEmdMode != PHHAL_HW_EMD_MODE_OFF))
				{
					pDataParams->bDiscLoopTechDetectActivityState = 6U;
				}
				else
				{
					pDataParams->bDiscLoopTechDetectActivityState = 7U;
				}
			}

			if (pDataParams->bDiscLoopTechDetectActivityState == 6U)
			{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
				PH_CHECK_INPROCESS_FCT(status, phhalHw_DetectEMD(pDataParams->pHalDataParams));
#endif
				pDataParams->bDiscLoopTechDetectActivityState = 7U;
			}
			if (pDataParams->bDiscLoopTechDetectActivityState == 7U)
			{
				if (wIntFieldStatus == PH_OFF)
				{
					if (((uint8) PHAC_DISCLOOP_TECH_TYPE_F212 == bTechIndex)
							|| ((uint8) PHAC_DISCLOOP_TECH_TYPE_F424 == bTechIndex))
					{
	#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
						status = phacDiscLoop_Sw_Int_Config_GTF(pDataParams, bTechIndex);
						if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
						{
							pDataParams->bDiscLoopTechDetectActivityState = 0U;
							return status;
						}
	#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */
					}
					else
					{
						/* Apply Guard time. */
						status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US, pDataParams->waPasPollGTimeUs[bTechIndex]);
						if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
						{
							pDataParams->bDiscLoopTechDetectActivityState = 0U;
							return status;
						}
					}
				}
				pDataParams->bDiscLoopTechDetectActivityState = 8U;
			}

#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
			if (bVasFlag == 1U)
			{
				PH_CHECK_INPROCESS_FCT(status,
				phpalI14443p3a_VASUpA(pDataParams->pPal1443p3aDataParams, pDataParams->bVASUpFormat,
						pDataParams->sVASTargetInfo.pCmdBytes,
						pDataParams->sVASTargetInfo.bLenCmdBytes,
						pDataParams->sTypeATargetInfo.aTypeA_I3P3[0].aAtqa));
				status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
				pDataParams->bDiscLoopTechDetectActivityState = 0U;
				return status;
			}
			else
			{
#endif
				/* Perform Tech detection. */
				PH_CHECK_INPROCESS_FCT(status, pfDetTechs[bTechIndex](pDataParams));
#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
			}
#endif

			if ((status & PH_ERR_MASK) == PHAC_DISCLOOP_TECH_DETECTED)
			{
				/*Set the corresponding detected bit. */
				pDataParams->bDetectedTechs |= PH_ON << bTechIndex;
				bNumOfTechsFound++;
				/* Since Device detected at 212 Baud, Skip polling at 424 */
				if ((0U != ((pDataParams->bDetectedTechs & PHAC_DISCLOOP_POS_BIT_MASK_F212)))
						|| (0U != ((pDataParams->bDetectedTechs & PHAC_DISCLOOP_POS_BIT_MASK_F424))))
				{
					*pNumOfTechsDetect = bNumOfTechsFound;
					bTechTypeF_Detected = PH_ON;
				}
			}
			else
			{
				if((status & PH_ERR_MASK) == PH_ERR_ABORTED)
				{
					pDataParams->bDiscLoopTechDetectActivityState = 0U;
					return status;
				}
			}

			if ((0U != (bPasPollBailOut & (PH_ON << bTechIndex))) && (0U != bNumOfTechsFound))
			{
				/* Bail out set, Returning to application */
				*pNumOfTechsDetect = bNumOfTechsFound;
				bQuitFlag = 1U;
			}
		}
		bTechIndex++;
		pDataParams->bDiscLoopTechDetectActivityState = 1U;
		return PH_STATUS_INPROCESS;
	}

	if (bNumOfTechsFound == 1U)
	{
		*pNumOfTechsDetect = bNumOfTechsFound;
		status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
	}
	else if (bNumOfTechsFound > 1U)
	{
		*pNumOfTechsDetect = bNumOfTechsFound;
		status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_MULTI_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
	}
	else if (PH_ERR_IO_TIMEOUT == (status & PH_ERR_MASK))
	{
		/*Check VAS support*/
		if ((0u != ((pDataParams->bPasPollTechCfg) & PHAC_DISCLOOP_POS_BIT_MASK_VAS))
		&& (pDataParams->bOpeMode == RD_LIB_MODE_NFC)
		&& (0u != ((pDataParams->bCfgVasPolling) & PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING))
		&& (bVasFlag == 0U))
		{
			bTechIndex = 0U;
			bQuitFlag = 0U;
			pDataParams->bDiscLoopTechDetectActivityState = 3U;
			bVasFlag = 1U;
			return PH_STATUS_INPROCESS;
		}
		else
		{
			/* Do nothing */
		}
		status = PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
	}
	else
	{
		/* Other Failure, do nothing */
	}

	pDataParams->bDiscLoopTechDetectActivityState = 0U;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ColsnReslnActivity(
                                                  P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                                  VAR(uint8, ANFCRL_VAR) bTechType
                                                  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus;

	if (pDataParams->bDiscLoopColsnReslnActivityState == 0U)
	{
		/* Since we are interested in one Technology, Reset DetectedTechs information */
		pDataParams->bDetectedTechs = 0x00;
		/*Re-set number of card*/
		pDataParams->bNumOfCards = 0x00;
		pDataParams->bDiscLoopColsnReslnActivityState = 1U;
	}
	/* Call the selected collision resolution function */
	PH_CHECK_INPROCESS_FCT(wStatus, pfColnRelsns[bTechType](pDataParams));
	pDataParams->bDiscLoopColsnReslnActivityState = 0U;
	if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
	{
		/* Collision Resolution activity is successful, update Detected Technology */
		pDataParams->bDetectedTechs = (PH_ON << bTechType);

		if (pDataParams->bNumOfCards > 1U)
		{
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED, PH_COMP_AC_DISCLOOP);
		}
		else
		{
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
		}
	}

	if ((wStatus & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
	{
		return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_DEVICE_RESOLVED, PH_COMP_AC_DISCLOOP);
	}

	return wStatus;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateDevice(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bTechType,
    VAR(uint8, ANFCRL_VAR) bTagIndex)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;

	/* Since we are interested in one Technology, Reset DetectedTechs information */
	pDataParams->bDetectedTechs = 0x00;

	/* Activate selected tag */
	PH_CHECK_INPROCESS_FCT(status, pfDeviceActivate[bTechType](pDataParams, bTagIndex));
	if ((status & PH_ERR_MASK) == PH_ERR_SUCCESS) {
		/* Set Corresponding Tech Bit Position */
		pDataParams->bDetectedTechs = PH_ON << bTechType;
		return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_DEVICE_ACTIVATED, PH_COMP_AC_DISCLOOP);
	} else if (((status & PH_ERR_MASK) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND)
			|| ((status & PH_ERR_MASK) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED)) {
		/* Set Corresponding Tech Bit Position */
		pDataParams->bDetectedTechs = PH_ON << bTechType;
	}
	else
	{
		return status;
	}
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_RfcaOff_FieldOn(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	if(pDataParams->bDiscLoopSwIntRfcaOffFieldOnState == 0U)
	{
		/* Disable RFCA (if supported) */
		status = phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_RFCA, PH_OFF);
		if (((status & PH_ERR_MASK) != PH_ERR_UNSUPPORTED_PARAMETER) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS))
		{
			return status;
		}
		pDataParams->bDiscLoopSwIntRfcaOffFieldOnState = 1U;
	}


	if(pDataParams->bDiscLoopSwIntRfcaOffFieldOnState == 1U)
	{
		/* Switch on RF without performing I-RFCA. */
		PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOn(pDataParams->pHalDataParams));
		pDataParams->bDiscLoopSwIntFieldOnState = 0U;
	}

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Int_FieldOn(P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	if(pDataParams->bDiscLoopSwIntFieldOnState == 0U)
	{
		/* Enable RFCA (if supported) */
		status = phhalHw_SetConfig(pDataParams->pHalDataParams,
		PHHAL_HW_CONFIG_RFCA, PH_ON);
		if (((status & PH_ERR_MASK) != PH_ERR_UNSUPPORTED_PARAMETER) && ((status & PH_ERR_MASK) != PH_ERR_SUCCESS))
		{
			return status;
		}
		pDataParams->bDiscLoopSwIntFieldOnState = 1U;
	}

	if(pDataParams->bDiscLoopSwIntFieldOnState == 1U)
	{
		/* Perform I-RFCA and Switch on RF Field. */
		PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOn(pDataParams->pHalDataParams));
		pDataParams->bDiscLoopSwIntFieldOnState = 0U;
		if ((status & PH_ERR_MASK) == PH_ERR_RF_ERROR)
		{
			/* External RF is ON */
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_EXTERNAL_RFON, PH_COMP_AC_DISCLOOP);
		}
		else
		{
			return PH_ADD_COMPCODE(status, PH_COMP_AC_DISCLOOP);
		}
	}

	return status;
}

FUNC(uint8, ANFCRL_CODE) phacDiscLoop_Sw_Int_IsValidPollStatus(
                                              VAR(phStatus_t, ANFCRL_VAR) wStatus
                                              )
{
	if((((wStatus) & PH_ERR_MASK) == PH_ERR_SUCCESS)         ||
		(((wStatus) & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR) ||
		(((wStatus) & PH_ERR_MASK) == PH_ERR_FRAMING_ERROR)   ||
		(((wStatus) & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR) ||
		(((wStatus) & PH_ERR_MASK) == PH_ERR_PROTOCOL_ERROR)
		)
	{
		return PH_ON;
	}
	else
	{
		return PH_OFF;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif
