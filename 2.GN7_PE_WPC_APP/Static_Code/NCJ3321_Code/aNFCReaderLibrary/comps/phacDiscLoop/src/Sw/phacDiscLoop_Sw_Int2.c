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
*   @file    phacDiscLoop_Sw_Int2.c
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
#include <phpalI14443p3a2.h>
#include <phpalI14443p3b2.h>

#include "phacDiscLoop_Sw_Int_A2.h"
#include "phacDiscLoop_Sw_Int_B2.h"
#include "phacDiscLoop_Sw_Int_F2.h"
#include "phacDiscLoop_Sw_Int_V2.h"

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw_Int2.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw_Int2.c header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_VENDOR_ID_C2 != PHACDISCLOOP_SW_INT_VENDOR_ID2)
    #error "phacDiscLoop_Sw_Int2.c and phacDiscLoop_Sw_Int2.c have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw_Int2.c header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int2.c and phacDiscLoop_Sw_Int2.c are different"
#endif
/* Check if current file and phacDiscLoop_Sw_Int2.c header file are of the same Software version */
#if ((PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_INT_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_INT_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_INT_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int2.c and phacDiscLoop_Sw_Int2.c are different"
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#define PHAC_DISCLOOP_HALTA_TIMOUT_US2     1100U

/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint32, ANFCRL_CONST) gPasTechTypeMapTable2[] = {
    PHHAL_HW_CARDTYPE_ISO14443A2,
    PHHAL_HW_CARDTYPE_ISO14443B2,
    PHHAL_HW_CARDTYPE_FELICA_2122,
    PHHAL_HW_CARDTYPE_FELICA_4242,
    PHHAL_HW_CARDTYPE_ISO156932
};

static CONST(pphacDiscLoop_Sw_Reslns2, ANFCRL_CONST) pfColnRelsns2[] = {
    &phacDiscLoop_Sw_Int_CollisionResolutionA2,
    &phacDiscLoop_Sw_Int_CollisionResolutionB2,
    &phacDiscLoop_Sw_Int_CollisionResolutionF2,
    &phacDiscLoop_Sw_Int_CollisionResolutionF2,
    &phacDiscLoop_Sw_Int_CollisionResolutionV2
};

static CONST(pphacDiscLoop_Sw_DetTechs2, ANFCRL_CONST) pfDetTechs2[] = {
    &phacDiscLoop_Sw_DetTechTypeA2,
    &phacDiscLoop_Sw_DetTechTypeB2,
    &phacDiscLoop_Sw_DetTechTypeF2,
    &phacDiscLoop_Sw_DetTechTypeF2,
    &phacDiscLoop_Sw_DetTechTypeV2
};

static CONST(pphacDiscLoop_Sw_DeviceActivate2, ANFCRL_CONST) pfDeviceActivate2[] = {
    &phacDiscLoop_Sw_Int_ActivateA2,
    &phacDiscLoop_Sw_Int_ActivateB2,
    &phacDiscLoop_Sw_Int_ActivateF2,
    &phacDiscLoop_Sw_Int_ActivateF2,
    &phacDiscLoop_Sw_Int_ActivateV2
};
#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ListenMode2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET2
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INTERNAL_ERROR2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRetryCount2 = 0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wTempMode2 = 0x00u;

	/* get active listen cfg except F424 */
	wTempMode2 = (uint16)pDataParams2->bActLisTechCfg2 & 0x0007U;

	/* Map Active F424 configuration with Type F bit in Autocoll */
	if(0U != (pDataParams2->bActLisTechCfg2 & PHAC_DISCLOOP_POS_BIT_MASK_F4242))
	{
		wTempMode2 = wTempMode2 | PHAC_DISCLOOP_POS_BIT_MASK_F2122;
	}

	wTempMode2 = (uint16) (wTempMode2 << 8U);

	/* get passive listen cfg except F424 */
	wTempMode2 = wTempMode2 | ((uint16)pDataParams2->bPasLisTechCfg2 & 0x0007u);

	/* Map Passive F424 configuration with Type F bit in Autocoll */
	if(0U != (pDataParams2->bPasLisTechCfg2 & PHAC_DISCLOOP_POS_BIT_MASK_F4242))
	{
		wTempMode2 = wTempMode2 | PHAC_DISCLOOP_POS_BIT_MASK_F2122;
	}

	/* AUTOCOLL retry loop */

	PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Autocoll2(
		pDataParams2->pHalDataParams2,
		wTempMode2,
		&pDataParams2->sTargetParams2.pRxBuffer2,
		&pDataParams2->sTargetParams2.wRxBufferLen2,
		&pDataParams2->sTargetParams2.wProtParams2));
	if(((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2) && ((pDataParams2->sTargetParams2.bRetryCount2 - bRetryCount2) != 0u))
	{
		bRetryCount2++;
		return PH_STATUS_INPROCESS2;
	}
	bRetryCount2 = 0U;
	/* Return RF OFF error, if external RF is OFF */
	if((status2 & PH_ERR_MASK2) == PH_ERR_EXT_RF_ERROR2)
	{
		return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_EXTERNAL_RFOFF2, PH_COMP_AC_DISCLOOP2);
	}
	else
	{
		/* Return, if error */
		PH_CHECK_SUCCESS2(status2);
	}

	return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_ACTIVATED_BY_PEER2, PH_COMP_AC_DISCLOOP2);
#else /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */
	PH_UNUSED_VARIABLE2(pDataParams2);
	return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_AC_DISCLOOP2);
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_Stop2(
                                    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                    )
{
    /* RFU */
    UNUSED2(pDataParams2);
    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivePollMode2(
                                              P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                              )
{
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bIndex2;
	/* Reset detected technologies */
	pDataParams2->bDetectedTechs2 = 0x00;

	/* Loop through all the supported active technologies */
	for (bIndex2 = 0; bIndex2 < PHAC_DISCLOOP_ACT_POLL_MAX_TECHS_SUPPORTED2; bIndex2++)
	{
		switch (pDataParams2->bActPollTechCfg2 & (PH_ON2 << bIndex2))
		{
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062:
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122:
			case PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242:
				break;

			default:
				break;
		}
	}
	/* No Target present. */
    return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_PollMode2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_INVALID_PARAMETER2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bResolveTech2 = 0U;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTechType2 = 0U;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNumOfTechsFound2 = 0U;

	if (pDataParams2->bPollState2 == PHAC_DISCLOOP_POLL_STATE_DETECTION2)
	{
		if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2) || (pDataParams2->bOpeMode2 == RD_LIB_MODE_ISO2))
		{
			/* Perform Technology detection Activity */
			PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_TechDetectActivity2(pDataParams2,
					pDataParams2->bPasPollBailOut2, pDataParams2->bPasPollTechCfg2, &bNumOfTechsFound2));
			pDataParams2->bDiscLoopPollModeState2 = 0U;
			/* Return if status2 is aborted. */
			PH_CHECK_ABORT2(status2);
		}
		else
		{
			;/* Do Nothing */
		}

		if ((0U != (pDataParams2->bLpcdEnabled2)) && (0U != (pDataParams2->bPasPollTechCfg2))
				&& ((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_TECH_DETECTED2))
		{
			/* LPCD is success but card presence does not exist/errors */
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
		}

		if ((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_TECH_DETECTED2)
		{
			pDataParams2->bPollState2 = PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2;
		}
	}

	/* Go for collision resolution if single tech found */
	if (pDataParams2->bPollState2 == PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2)
	{
		/* Get Technology to be resolved */
		if (pDataParams2->bDiscLoopPollModeState2 == 0U)
		{
			bResolveTech2 = pDataParams2->bDetectedTechs2 & pDataParams2->bPasPollTechCfg2;
			if (0U != (bResolveTech2))
			{
				if (0U != (bResolveTech2 & (uint8) (bResolveTech2 - 1U)))
				{
					pDataParams2->bPollState2 = PHAC_DISCLOOP_POLL_STATE_DETECTION2;
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
				}
			}
			else
			{
				pDataParams2->bPollState2 = PHAC_DISCLOOP_POLL_STATE_DETECTION2;
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
			}
			PHAC_DISCLOOP_GET_BIT_POS2(bResolveTech2, bTechType2);
			pDataParams2->bDiscLoopPollModeState2 = 1U;
		}

		if (pDataParams2->bDiscLoopPollModeState2 == 1U)
		{
			PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_ColsnReslnActivity2(pDataParams2, (bTechType2 - (uint8) 1U)));
			pDataParams2->bDiscLoopPollModeState2 = 0U;
			if ((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_DEVICE_RESOLVED2)
			{
				/* Activation */
				pDataParams2->bDiscLoopPollModeState2 = 2U;
			}
		}

		if (pDataParams2->bDiscLoopPollModeState2 == 2U)
		{
			PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_ActivateDevice2(pDataParams2, (bTechType2 - (uint8) 1U), (uint8) 0x00U));
			pDataParams2->bDiscLoopPollModeState2 = 0U;
		}
		pDataParams2->bPollState2 = PHAC_DISCLOOP_POLL_STATE_DETECTION2;
		/* Return if status2 is aborted. */
		PH_CHECK_ABORT2(status2);
	}
	return PH_ADD_COMPCODE2(status2, PH_COMP_AC_DISCLOOP2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_TechDetectActivity2(
                                                  P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                  VAR(uint8, ANFCRL_VAR) bPasPollBailOut2,
                                                  VAR(uint8, ANFCRL_VAR) bDetectConfig2,
                                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumOfTechsDetect2
                                                  )
{
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PHAC_DISCLOOP_NO_TECH_DETECTED2;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_COUNT2 bTechIndex2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNumOfTechsFound2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTechTypeF_Detected2 = PH_OFF2;
	static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wIntFieldStatus2 = 0U;
	VAR(uint16, ANFCRL_VAR) wEmdMode2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bVasFlag2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bQuitFlag2 = 0U;

	if (pDataParams2->bDiscLoopTechDetectActivityState2 == 0U)
	{
		pDataParams2->bDetectedTechs2 = 0x00;
		pDataParams2->bNumOfCards2 = 0x00;
		bTechIndex2 = 0U;
		bNumOfTechsFound2 = 0U;
		bTechTypeF_Detected2 = PH_OFF2;
		wIntFieldStatus2 = 0U;
		bQuitFlag2 = 0U;
		bVasFlag2 = 0U;
		status2 = PHAC_DISCLOOP_NO_TECH_DETECTED2;
		pDataParams2->bDiscLoopTechDetectActivityState2 = 1U;
	}
	/* Poll for requested NFC-Tech Type presence. */
	while ((bTechIndex2 < PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2) && (bQuitFlag2 == 0U))
	{
		if (pDataParams2->bDiscLoopTechDetectActivityState2 == 1U)
		{
			/* In NFC mode, poll proprietary technologies only if NFC technologies are not detected */
			if ((pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2) && (0U != bNumOfTechsFound2)
					&& (bTechIndex2 == PHAC_DISCLOOP_POLL_MAX_NFC_TECHS_SUPPORTED2))
			{
				break;
			}

			if (((bTechIndex2 == (uint8)PHAC_DISCLOOP_TECH_TYPE_F2122) || (bTechIndex2 == (uint8)PHAC_DISCLOOP_TECH_TYPE_F4242))
				&& (bTechTypeF_Detected2 == PH_ON2))
			{
				bTechIndex2++;
				continue;
			}
			pDataParams2->bDiscLoopTechDetectActivityState2 = 2U;
		}
		if (0U != (bDetectConfig2 & (PH_ON2 << bTechIndex2)))
		{
			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 2U)
			{
				/* Get Config to check the internal Field On. */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_INT_RF_ON2, &wIntFieldStatus2));
				if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
					return status2;
				}

				if (wIntFieldStatus2 == PH_ON2)
				{
					if (((uint8) PHAC_DISCLOOP_TECH_TYPE_F2122 == bTechIndex2)
							|| ((uint8) PHAC_DISCLOOP_TECH_TYPE_F4242 == bTechIndex2))
					{
	#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
						status2 = phacDiscLoop_Sw_Int_Config_GTF2(pDataParams2, bTechIndex2);
						if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
						{
							pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
							return status2;
						}
	#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
					}
					else
					{
						/* Apply Guard time. */
						status2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2, pDataParams2->waPasPollGTimeUs2[bTechIndex2]);
						if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
						{
							pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
							return status2;
						}
					}
				}
				pDataParams2->bDiscLoopTechDetectActivityState2 = 3U;
			}

			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 3U)
			{
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(pDataParams2->pHalDataParams2,	(uint8 )(gPasTechTypeMapTable2[bTechIndex2] & 0xFFU)));
				if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
					return status2;
				}
				pDataParams2->bDiscLoopTechDetectActivityState2 = 4U;
			}

			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 4U)
			{
				/* Perform I-RFCA and Switch on RF Field after Apply protocol settings, if in NFC and ISO mode. */
				PH_CHECK_INPROCESS_FCT2(status2, phacDiscLoop_Sw_Int_FieldOn2(pDataParams2));
				if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
					return status2;
				}
				pDataParams2->bDiscLoopTechDetectActivityState2 = 5U;
			}

			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 5U)
			{
				status2 = phhalHw_GetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_EMD_MODE2, &wEmdMode2);
				if ((status2 == PH_ERR_SUCCESS2) && (wEmdMode2 != PHHAL_HW_EMD_MODE_OFF2))
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 6U;
				}
				else
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 7U;
				}
			}

			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 6U)
			{
#ifdef NXPBUILD__PHHAL_HW_NCx33202
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_DetectEMD2(pDataParams2->pHalDataParams2));
#endif
				pDataParams2->bDiscLoopTechDetectActivityState2 = 7U;
			}
			if (pDataParams2->bDiscLoopTechDetectActivityState2 == 7U)
			{
				if (wIntFieldStatus2 == PH_OFF2)
				{
					if (((uint8) PHAC_DISCLOOP_TECH_TYPE_F2122 == bTechIndex2)
							|| ((uint8) PHAC_DISCLOOP_TECH_TYPE_F4242 == bTechIndex2))
					{
	#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
						status2 = phacDiscLoop_Sw_Int_Config_GTF2(pDataParams2, bTechIndex2);
						if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
						{
							pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
							return status2;
						}
	#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */
					}
					else
					{
						/* Apply Guard time. */
						status2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2, pDataParams2->waPasPollGTimeUs2[bTechIndex2]);
						if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
						{
							pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
							return status2;
						}
					}
				}
				pDataParams2->bDiscLoopTechDetectActivityState2 = 8U;
			}

#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
			if (bVasFlag2 == 1U)
			{
				PH_CHECK_INPROCESS_FCT2(status2,
				phpalI14443p3a_VASUpA2(pDataParams2->pPal1443p3aDataParams2, pDataParams2->bVASUpFormat2,
						pDataParams2->sVASTargetInfo2.pCmdBytes2,
						pDataParams2->sVASTargetInfo2.bLenCmdBytes2,
						pDataParams2->sTypeATargetInfo2.aTypeA_I3P32[0].aAtqa2));
				status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
				pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
				return status2;
			}
			else
			{
#endif
				/* Perform Tech detection. */
				PH_CHECK_INPROCESS_FCT2(status2, pfDetTechs2[bTechIndex2](pDataParams2));
#ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
			}
#endif

			if ((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_TECH_DETECTED2)
			{
				/*Set the corresponding detected bit. */
				pDataParams2->bDetectedTechs2 |= PH_ON2 << bTechIndex2;
				bNumOfTechsFound2++;
				/* Since Device detected at 212 Baud, Skip polling at 424 */
				if ((0U != ((pDataParams2->bDetectedTechs2 & PHAC_DISCLOOP_POS_BIT_MASK_F2122)))
						|| (0U != ((pDataParams2->bDetectedTechs2 & PHAC_DISCLOOP_POS_BIT_MASK_F4242))))
				{
					*pNumOfTechsDetect2 = bNumOfTechsFound2;
					bTechTypeF_Detected2 = PH_ON2;
				}
			}
			else
			{
				if((status2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
				{
					pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
					return status2;
				}
			}

			if ((0U != (bPasPollBailOut2 & (PH_ON2 << bTechIndex2))) && (0U != bNumOfTechsFound2))
			{
				/* Bail out set, Returning to application */
				*pNumOfTechsDetect2 = bNumOfTechsFound2;
				bQuitFlag2 = 1U;
			}
		}
		bTechIndex2++;
		pDataParams2->bDiscLoopTechDetectActivityState2 = 1U;
		return PH_STATUS_INPROCESS2;
	}

	if (bNumOfTechsFound2 == 1U)
	{
		*pNumOfTechsDetect2 = bNumOfTechsFound2;
		status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
	}
	else if (bNumOfTechsFound2 > 1U)
	{
		*pNumOfTechsDetect2 = bNumOfTechsFound2;
		status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_MULTI_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
	}
	else if (PH_ERR_IO_TIMEOUT2 == (status2 & PH_ERR_MASK2))
	{
		/*Check VAS support*/
		if ((0u != ((pDataParams2->bPasPollTechCfg2) & PHAC_DISCLOOP_POS_BIT_MASK_VAS2))
		&& (pDataParams2->bOpeMode2 == RD_LIB_MODE_NFC2)
		&& (0u != ((pDataParams2->bCfgVasPolling2) & PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING2))
		&& (bVasFlag2 == 0U))
		{
			bTechIndex2 = 0U;
			bQuitFlag2 = 0U;
			pDataParams2->bDiscLoopTechDetectActivityState2 = 3U;
			bVasFlag2 = 1U;
			return PH_STATUS_INPROCESS2;
		}
		else
		{
			/* Do nothing */
		}
		status2 = PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
	}
	else
	{
		/* Other Failure, do nothing */
	}

	pDataParams2->bDiscLoopTechDetectActivityState2 = 0U;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ColsnReslnActivity2(
                                                  P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                                  VAR(uint8, ANFCRL_VAR) bTechType2
                                                  )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2;

	if (pDataParams2->bDiscLoopColsnReslnActivityState2 == 0U)
	{
		/* Since we are interested in one Technology, Reset DetectedTechs information */
		pDataParams2->bDetectedTechs2 = 0x00;
		/*Re-set number of card*/
		pDataParams2->bNumOfCards2 = 0x00;
		pDataParams2->bDiscLoopColsnReslnActivityState2 = 1U;
	}
	/* Call the selected collision resolution function */
	PH_CHECK_INPROCESS_FCT2(wStatus2, pfColnRelsns2[bTechType2](pDataParams2));
	pDataParams2->bDiscLoopColsnReslnActivityState2 = 0U;
	if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
	{
		/* Collision Resolution activity is successful, update Detected Technology */
		pDataParams2->bDetectedTechs2 = (PH_ON2 << bTechType2);

		if (pDataParams2->bNumOfCards2 > 1U)
		{
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2, PH_COMP_AC_DISCLOOP2);
		}
		else
		{
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
		}
	}

	if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
	{
		return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_DEVICE_RESOLVED2, PH_COMP_AC_DISCLOOP2);
	}

	return wStatus2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateDevice2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bTechType2,
    VAR(uint8, ANFCRL_VAR) bTagIndex2)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;

	/* Since we are interested in one Technology, Reset DetectedTechs information */
	pDataParams2->bDetectedTechs2 = 0x00;

	/* Activate selected tag */
	PH_CHECK_INPROCESS_FCT2(status2, pfDeviceActivate2[bTechType2](pDataParams2, bTagIndex2));
	if ((status2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2) {
		/* Set Corresponding Tech Bit Position */
		pDataParams2->bDetectedTechs2 = PH_ON2 << bTechType2;
		return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_DEVICE_ACTIVATED2, PH_COMP_AC_DISCLOOP2);
	} else if (((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2)
			|| ((status2 & PH_ERR_MASK2) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2)) {
		/* Set Corresponding Tech Bit Position */
		pDataParams2->bDetectedTechs2 = PH_ON2 << bTechType2;
	}
	else
	{
		return status2;
	}
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_RfcaOff_FieldOn2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

	if(pDataParams2->bDiscLoopSwIntRfcaOffFieldOnState2 == 0U)
	{
		/* Disable RFCA (if supported) */
		status2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_RFCA2, PH_OFF2);
		if (((status2 & PH_ERR_MASK2) != PH_ERR_UNSUPPORTED_PARAMETER2) && ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2))
		{
			return status2;
		}
		pDataParams2->bDiscLoopSwIntRfcaOffFieldOnState2 = 1U;
	}


	if(pDataParams2->bDiscLoopSwIntRfcaOffFieldOnState2 == 1U)
	{
		/* Switch on RF without performing I-RFCA. */
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOn2(pDataParams2->pHalDataParams2));
		pDataParams2->bDiscLoopSwIntFieldOnState2 = 0U;
	}

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_FieldOn2(P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

	if(pDataParams2->bDiscLoopSwIntFieldOnState2 == 0U)
	{
		/* Enable RFCA (if supported) */
		status2 = phhalHw_SetConfig2(pDataParams2->pHalDataParams2,
		PHHAL_HW_CONFIG_RFCA2, PH_ON2);
		if (((status2 & PH_ERR_MASK2) != PH_ERR_UNSUPPORTED_PARAMETER2) && ((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2))
		{
			return status2;
		}
		pDataParams2->bDiscLoopSwIntFieldOnState2 = 1U;
	}

	if(pDataParams2->bDiscLoopSwIntFieldOnState2 == 1U)
	{
		/* Perform I-RFCA and Switch on RF Field. */
		PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOn2(pDataParams2->pHalDataParams2));
		pDataParams2->bDiscLoopSwIntFieldOnState2 = 0U;
		if ((status2 & PH_ERR_MASK2) == PH_ERR_RF_ERROR2)
		{
			/* External RF is ON */
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_EXTERNAL_RFON2, PH_COMP_AC_DISCLOOP2);
		}
		else
		{
			return PH_ADD_COMPCODE2(status2, PH_COMP_AC_DISCLOOP2);
		}
	}

	return status2;
}

FUNC(uint8, ANFCRL_CODE) phacDiscLoop_Sw_Int_IsValidPollStatus2(
                                              VAR(phStatus_t2, ANFCRL_VAR) wStatus2
                                              )
{
	if((((wStatus2) & PH_ERR_MASK2) == PH_ERR_SUCCESS2)         ||
		(((wStatus2) & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2) ||
		(((wStatus2) & PH_ERR_MASK2) == PH_ERR_FRAMING_ERROR2)   ||
		(((wStatus2) & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2) ||
		(((wStatus2) & PH_ERR_MASK2) == PH_ERR_PROTOCOL_ERROR2)
		)
	{
		return PH_ON2;
	}
	else
	{
		return PH_OFF2;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION_C2== 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif
