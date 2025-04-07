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
*   @file    phacDiscLoop_Sw.c
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


#include <ph_Status.h>
#include <ph_RefDefs.h>
#include <phacDiscLoop.h>
#include <phhalHw.h>

#include <phpalI14443p3a.h>
#include <phpalI14443p3b.h>
#include <phpalI14443p4a.h>
#include <phpalI14443p4.h>
#include <phpalFelica.h>
#include <phpalSli15693.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#include "phacDiscLoop_Sw.h"
#include "phacDiscLoop_Sw_Int.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_VENDOR_ID_C != PHACDISCLOOP_SW_VENDOR_ID)
    #error "phacDiscLoop_Sw.c and phacDiscLoop_Sw.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C    != PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C    != PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION_C != PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw.c and phacDiscLoop_Sw.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_SW_MAJOR_VERSION_C != PHACDISCLOOP_SW_SW_MAJOR_VERSION) || \
     (PHACDISCLOOP_SW_SW_MINOR_VERSION_C != PHACDISCLOOP_SW_SW_MINOR_VERSION) || \
     (PHACDISCLOOP_SW_SW_PATCH_VERSION_C != PHACDISCLOOP_SW_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw.c and phacDiscLoop_Sw.h are different"
#endif
#endif  /* NXPBUILD__PHAC_DISCLOOP_SW */
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
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint8, ANFCRL_CONST) gPasTechPollSeqMapTable[] = {
	(uint8)PHAC_DISCLOOP_TECH_TYPE_A,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_B,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_F212,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_F424,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_V,
};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Init(
                                P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams
                                )
{
    if (sizeof(phacDiscLoop_Sw_DataParams_t) != wSizeOfDataParams)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_AC_DISCLOOP);
    }

    PH_ASSERT_NULL(pDataParams);

    /* Initialize the private data */
    pDataParams->wId                      = PH_COMP_AC_DISCLOOP | PHAC_DISCLOOP_SW_ID;
    pDataParams->pHalDataParams           = pHalDataParams;
    pDataParams->pPal1443p3aDataParams    = NULL;
    pDataParams->pPal1443p3bDataParams    = NULL;
    pDataParams->pPal14443p4DataParams    = NULL;
    pDataParams->pPalFelicaDataParams     = NULL;
    pDataParams->pPal1443p4aDataParams    = NULL;
    pDataParams->pPalSli15693DataParams   = NULL;

    /* Default Operation Mode is NFC */
    pDataParams->bOpeMode                 = RD_LIB_MODE_NFC;
    pDataParams->bNfcActivityVersion      = PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1;

    /* Default listen and poll mode technologies */
    pDataParams->bPollState               = PHAC_DISCLOOP_POLL_STATE_DETECTION;
    pDataParams->bPasPollTechCfg          = 0x00;
    pDataParams->bPasLisTechCfg           = 0x00;
    pDataParams->bActPollTechCfg          = 0x00;
    pDataParams->bActLisTechCfg           = 0x00;

    pDataParams->pPasTechPollSeq          = (uint8 *)&gPasTechPollSeqMapTable;

    pDataParams->bUseAntiColl             = PH_ON;
    pDataParams->bLpcdEnabled             = PH_OFF;

    pDataParams->bNumOfCards              = 0x00;
    pDataParams->bDetectedTechs           = 0x00;
    pDataParams->bCollPend                = 0x00;
    pDataParams->wActPollGTimeUs          = PH_NXPNFCRDLIB_CONFIG_TYPEA_GT;

    pDataParams->bPasPollBailOut          = 0x00;

    /* Reset internal state */
    pDataParams->bDiscLoopRunState = 0x00;
    pDataParams->bDiscLoopColsnReslnActivityState = 0x00;
    pDataParams->bDiscLoopTechDetectActivityState = 0x00;
    pDataParams->bDiscLoopPollModeState = 0x00;
    pDataParams->bDiscLoopSwIntFieldOnState = 0x00;
    pDataParams->bDiscLoopSwIntRfcaOffFieldOnState = 0x00;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
    /* Poll device limits */
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A]           = PHAC_DISCLOOP_TYPEA_DEFAULT_DEVICE_LIMIT;
    /* Guard times */
    pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_A]         = PH_NXPNFCRDLIB_CONFIG_TYPEA_GT;
    pDataParams->bPasPollTechCfg                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_A);
    pDataParams->bDiscLoopActivateAState                             = 0x00;
    pDataParams->bDiscLoopDetTechTypeAState                          = 0x00;
    pDataParams->bDiscLoopCollisionResolutionAState                  = CollisionResolutionA_Start;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE
    pDataParams->bPasLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_A;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE
    pDataParams->bActLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_A;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    /* Poll device limits */
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_B]           = PHAC_DISCLOOP_TYPEB_DEFAULT_DEVICE_LIMIT;
    /* Guard times */
    pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_B]         = PH_NXPNFCRDLIB_CONFIG_TYPEB_GT;
    pDataParams->bPasPollTechCfg                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_B);
    pDataParams->bCollResBState                                      = ColResolB_Start;
    pDataParams->bDiscLoopActivateBState                             = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    /* Poll device limits */
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212]        = PHAC_DISCLOOP_TYPEF_DEFAULT_DEVICE_LIMIT;
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F424]        = PHAC_DISCLOOP_TYPEF_DEFAULT_DEVICE_LIMIT;
    /* Guard time GTFB */
    pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F212]      = PH_NXPNFCRDLIB_CONFIG_TYPEF_GT;
    /* Guard time GTBF */
    pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F424]      = PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT;
    pDataParams->bPasPollTechCfg                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_F212 | PHAC_DISCLOOP_POS_BIT_MASK_F424);
    pDataParams->bDiscLoopCollisionResolutionFState                  = 0x00;
    pDataParams->bDiscLoopActivateFState                             = 0x00;
    pDataParams->bDiscLoopSendSensFReq                               = 0x00;
    pDataParams->bDiscLoopDetTechTypeF                               = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE
    pDataParams->bPasLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F212;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE
    pDataParams->bPasLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F424;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE
    pDataParams->bActLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F212;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE
    pDataParams->bActLisTechCfg                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F424;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    /* Poll device limits */
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V]      = PHAC_DISCLOOP_TYPEV_DEFAULT_DEVICE_LIMIT;
    /* Guard times */
    pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_V]    = PH_NXPNFCRDLIB_CONFIG_TYPEV_GT;
    pDataParams->bPasPollTechCfg                                |= (PHAC_DISCLOOP_POS_BIT_MASK_V);
	pDataParams->bDiscLoopCollisionResolutionVState             = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS)
    pDataParams->sTypeATargetInfo.bTotalTagsFound   = 0;

    #ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bFsdi  = PHPAL_I14443P4A_NFC_FRAMESIZE_MAX;
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bCid   = 0x00;
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bNad   = 0x00;
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDri   = 0x00;
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDsi   = 0x00;
    #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    pDataParams->sTypeBTargetInfo.bTotalTagsFound   = 0x00;
    pDataParams->sTypeBTargetInfo.bAfiReq           = 0x00;
    pDataParams->sTypeBTargetInfo.bFsdi             = 0x08;
    pDataParams->sTypeBTargetInfo.bCid              = 0x00;
    pDataParams->sTypeBTargetInfo.bNad              = 0x00;
    pDataParams->sTypeBTargetInfo.bDri              = 0x00;
    pDataParams->sTypeBTargetInfo.bDsi              = 0x00;
    pDataParams->sTypeBTargetInfo.bExtendedAtqBbit  = 0x00;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    pDataParams->sTypeFTargetInfo.bTotalTagsFound  = 0x00;
    pDataParams->sTypeFTargetInfo.aSystemCode[0]   = 0xFF;
    pDataParams->sTypeFTargetInfo.aSystemCode[1]   = 0xFF;
    pDataParams->sTypeFTargetInfo.bTimeSlot        = PHPAL_FELICA_NUMSLOTS_4;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */


#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    pDataParams->sTypeVTargetInfo.bTotalTagsFound  = 0x00;
    pDataParams->sTypeVTargetInfo.bFlag            = PHPAL_SLI15693_FLAG_DATA_RATE;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET
    pDataParams->sTargetParams.bRetryCount = 0;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET */

    return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_Run(
    P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(phacDiscLoop_Sw_EntryPoints_t, ANFCRL_VAR) bEntryPoint
	)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wDiscloopStatus;

	if (pDataParams->bDiscLoopRunState == 0U)
	{
		/* Disable Emd Check */
		PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_SET_EMD, PH_OFF));
		PH_CHECK_SUCCESS(wDiscloopStatus);
		pDataParams->bDiscLoopRunState = 1U;
		return PH_STATUS_INPROCESS;
	}
	switch (bEntryPoint)
	{
	case PHAC_DISCLOOP_ENTRY_POINT_POLL:

#ifdef NXPBUILD__PHAC_DISCLOOP_LPCD
		/* Perform LPCD if Enabled. */
		if ((pDataParams->bDiscLoopRunState == 1U) && (0U != (pDataParams->bLpcdEnabled)) && (pDataParams->bPollState == PHAC_DISCLOOP_POLL_STATE_DETECTION))
		{
	#ifdef NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD
			PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phhalHw_HybridLPCD(pDataParams->pHalDataParams));
	#else
			PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phhalHw_Lpcd(pDataParams->pHalDataParams));
	#endif /*NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD*/

			if ((wDiscloopStatus & PH_ERR_MASK) != PH_ERR_SUCCESS)
			{
				pDataParams->bDiscLoopRunState = 0U;
				if ((wDiscloopStatus & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
				{
					return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP); /* No card presence. */
				}

				return wDiscloopStatus; /* Other error. */
			}
		}
#endif /* NXPBUILD__PHAC_DISCLOOP_LPCD */
    	if (pDataParams->bDiscLoopRunState == 1U)
    	{
    		pDataParams->bDiscLoopRunState = 2U;
    	}
		/* Check for active poll configuration */
		if ((pDataParams->bDiscLoopRunState == 2U) && (0U != (pDataParams->bActPollTechCfg)) && (pDataParams->bPollState == PHAC_DISCLOOP_POLL_STATE_DETECTION))
		{
			PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phacDiscLoop_Sw_Int_ActivePollMode(pDataParams));
			/* Continue with passive polling, if no peer detected */
			if ((wDiscloopStatus & PH_ERR_MASK) != PHAC_DISCLOOP_NO_TECH_DETECTED)
			{
				pDataParams->bDiscLoopRunState = 0U;
				if (((wDiscloopStatus & PH_ERR_MASK) != PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED)
						&& ((wDiscloopStatus & PH_ERR_MASK) != PHAC_DISCLOOP_EXTERNAL_RFON))
				{
					pDataParams->wErrorCode = wDiscloopStatus;
					return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_FAILURE, PH_COMP_AC_DISCLOOP);
				}
				return wDiscloopStatus;
			}
			/* Field OFF after Active polling and wait for recovery time. */
			PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phhalHw_FieldOff(pDataParams->pHalDataParams));
			if (wDiscloopStatus != PH_ERR_SUCCESS)
			{
				pDataParams->bDiscLoopRunState = 0U;
				return wDiscloopStatus;
			}
			wDiscloopStatus = phhalHw_Wait(pDataParams->pHalDataParams, PHHAL_HW_TIME_MICROSECONDS, pDataParams->wActPollGTimeUs);
			if (wDiscloopStatus != PH_ERR_SUCCESS)
			{
				pDataParams->bDiscLoopRunState = 0U;
				return wDiscloopStatus;
			}
			pDataParams->bDiscLoopRunState = 3U;
		}

		/* Check for passive poll configuration */
		if (0U != (pDataParams->bPasPollTechCfg))
		{
			/* Perform the Poll operation and store the Status code. */
			PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phacDiscLoop_Sw_Int_PollMode(pDataParams));

			pDataParams->bDiscLoopRunState = 0U;
			/* If error is from below layer, store it and return failure */
			if ((wDiscloopStatus & PH_COMP_MASK) != PH_COMP_AC_DISCLOOP)
			{
				pDataParams->wErrorCode = wDiscloopStatus;
				return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_FAILURE, PH_COMP_AC_DISCLOOP);
			}
			return wDiscloopStatus;
		}
		else
		{
			pDataParams->bDetectedTechs = 0x00;
			pDataParams->bNumOfCards = 0x00;
			pDataParams->bDiscLoopRunState = 0U;
			return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_NO_TECH_DETECTED, PH_COMP_AC_DISCLOOP);
		}

    case PHAC_DISCLOOP_ENTRY_POINT_LISTEN:
        /* Check for listen configurations */
        if ((0U != (pDataParams->bPasLisTechCfg)) || (0U != (pDataParams->bActLisTechCfg)))
        {
        	if (pDataParams->bDiscLoopRunState == 1U)
        	{
				/* Turn OFF RF field if already on. */
        		PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phhalHw_FieldOff(pDataParams->pHalDataParams));
				if (wDiscloopStatus != PH_ERR_SUCCESS)
				{
					pDataParams->bDiscLoopRunState = 0U;
					return wDiscloopStatus;
				}
				pDataParams->bDiscLoopRunState = 2U;
        	}
            /* Perform listen operation and store the Status code. */
        	PH_CHECK_INPROCESS_FCT(wDiscloopStatus, phacDiscLoop_Sw_Int_ListenMode(pDataParams));

			pDataParams->bDiscLoopRunState = 0U;
            /* If error is from below layer, store it and return failure */
            if((wDiscloopStatus & PH_COMP_MASK) != PH_COMP_AC_DISCLOOP)
            {
                pDataParams->wErrorCode = wDiscloopStatus;
                return PH_ADD_COMPCODE_FIXED(PHAC_DISCLOOP_FAILURE, PH_COMP_AC_DISCLOOP);
            }
            return wDiscloopStatus;
        }
        else
        {
			pDataParams->bDiscLoopRunState = 0U;
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }

    default:
		pDataParams->bDiscLoopRunState = 0U;
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
    }
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_SetConfig(
                                     P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wConfig,
                                     VAR(uint16, ANFCRL_VAR) wValue
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

    switch(wConfig)
    {
    case PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG:
        pDataParams->bActLisTechCfg = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG:
        pDataParams->bActPollTechCfg = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG:
        pDataParams->bPasLisTechCfg = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_COLLISION_PENDING:
        pDataParams->bCollPend = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE:
        if(!(((wValue & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_DETECTION) ||
            ((wValue & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION) ||
            ((wValue & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_REMOVAL)))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->bPollState = (wValue & 0x00FFU);
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG:
        pDataParams->bPasPollTechCfg = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE:
        pDataParams->bCfgVasPolling = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_ANTI_COLL:
        pDataParams->bUseAntiColl = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE:
            pDataParams->bVASUpFormat = (uint8)wValue;
            break;

    case PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION:
        if((wValue != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_0)
           && (wValue != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_1))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->bNfcActivityVersion = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_GTA_VALUE_US:
        pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_A] = wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_GTB_VALUE_US:
        pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_B] = wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US:
        if(wValue < PH_NXPNFCRDLIB_CONFIG_TYPEF_GT)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F212] = wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US:
        if(wValue < PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F424] = wValue;
        break;

	case PHAC_DISCLOOP_CONFIG_GTV_VALUE_US:
		pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_V] = wValue;
		break;

	case PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US:
		pDataParams->wActPollGTimeUs = wValue;
		break;

    case PHAC_DISCLOOP_CONFIG_BAIL_OUT:
        if (0u != (wValue & ~(PHAC_DISCLOOP_POS_BIT_MASK_A |  PHAC_DISCLOOP_POS_BIT_MASK_B
            | PHAC_DISCLOOP_POS_BIT_MASK_F424 | PHAC_DISCLOOP_POS_BIT_MASK_F212
            | PHAC_DISCLOOP_POS_BIT_MASK_V)))
        {
            /* Invalid bail out option set */
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }

        pDataParams->bPasPollBailOut = (uint8) wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_OPE_MODE:
        if(!((wValue == RD_LIB_MODE_NFC) ||
            (wValue == RD_LIB_MODE_EMVCO) ||
            (wValue == RD_LIB_MODE_ISO)))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->bOpeMode = (uint8)wValue;
        PH_CHECK_SUCCESS_FCT(status, phhalHw_SetConfig(pDataParams->pHalDataParams, PHHAL_HW_CONFIG_OPE_MODE, wValue));
#ifdef NXPBUILD__PHPAL_I14443P4_SW
        PH_CHECK_SUCCESS_FCT(status, phpalI14443p4_SetConfig(pDataParams->pPal14443p4DataParams, PHPAL_I14443P4_CONFIG_OPE_MODE, wValue));
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
        PH_CHECK_SUCCESS_FCT(status, phpalI14443p3b_SetConfig(pDataParams->pPal1443p3bDataParams, PHPAL_I14443P3B_CONFIG_OPE_MODE, wValue));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW
        PH_CHECK_SUCCESS_FCT(status, phpalI14443p3a_SetConfig(pDataParams->pPal1443p3aDataParams, PHPAL_I14443P3A_CONFIG_OPE_MODE, wValue));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
        PH_CHECK_SUCCESS_FCT(status, phpalI14443p4a_SetConfig(pDataParams->pPal1443p4aDataParams, PHPAL_I14443P4A_CONFIG_OPE_MODE, wValue));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */
        break;

    case PHAC_DISCLOOP_CONFIG_ENABLE_LPCD:
        pDataParams->bLpcdEnabled = (uint8)wValue;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT:
        if((wValue & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A] = (uint8)wValue;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI:
            if (wValue > PHPAL_I14443P4_FRAMESIZE_MAX)
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
            }
            pDataParams->sTypeATargetInfo.sTypeA_I3P4.bFsdi = (uint8)wValue;
            break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID:
        if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_CID)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bCid = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_NAD:
        /* Valid NAD complaint with ISO/IEC 7816-3 shall be set by application. */
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bNad = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI:
        if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_DRI)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDri = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI:
        if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_DSI)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDsi = (uint8)wValue;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT:
    if((wValue & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
    }
    pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_B] = (uint8)wValue;
    break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_AFI_REQ:
      pDataParams->sTypeBTargetInfo.bAfiReq = (uint8)wValue;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_EXTATQB:
      if (wValue == 0U)
      {
          pDataParams->sTypeBTargetInfo.bExtendedAtqBbit = 0;
      }
      else
      {
          pDataParams->sTypeBTargetInfo.bExtendedAtqBbit = 1;
      }
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_FSDI:
      if (wValue > PHPAL_I14443P3B_FRAMESIZE_MAX)
      {
          return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
      }
      pDataParams->sTypeBTargetInfo.bFsdi = (uint8)wValue;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_CID:
      if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_CID)
      {
          return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
      }
      pDataParams->sTypeBTargetInfo.bCid = (uint8)wValue;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_NAD:
        /* Valid NAD complaint with ISO/IEC 7816-3 shall be set by application. */
        pDataParams->sTypeBTargetInfo.bNad = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_DRI:
      if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_DRI)
      {
          return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
      }
      pDataParams->sTypeBTargetInfo.bDri = (uint8)wValue;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_DSI:
      if (wValue > PHAC_DISCLOOP_SW_I3P4_MAX_DSI)
      {
          return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
      }
      pDataParams->sTypeBTargetInfo.bDsi = (uint8)wValue;
      break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD:
        pDataParams->bFelicaBaud = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT:
        if((wValue & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212] = (uint8)wValue;
        break;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT:
        if((wValue & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V] = (uint8)wValue;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE:
        if((wValue != PHHAL_HW_RF_RX_DATARATE_HIGH)
           && (wValue != PHHAL_HW_RF_RX_DATARATE_LOW))
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }

        /* Set request flag to indicate high data rate */
        if(wValue == PHHAL_HW_RF_RX_DATARATE_HIGH)
        {
            pDataParams->sTypeVTargetInfo.bFlag |= PHPAL_SLI15693_FLAG_DATA_RATE;
        }
        else
        {
            pDataParams->sTypeVTargetInfo.bFlag &= ~((uint8)PHPAL_SLI15693_FLAG_DATA_RATE);
        }
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET
    case PHAC_DISCLOOP_CONFIG_TARGET_RETRY_COUNT:
        if (wValue > 255U)
        {
            return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
        }
        pDataParams->sTargetParams.bRetryCount = (uint8)wValue;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_GetConfig(
                                     P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wConfig,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                     )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

    switch(wConfig)
    {
    case PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG:
        *pValue = pDataParams->bPasLisTechCfg;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG:
        *pValue = pDataParams->bActLisTechCfg;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG:
        *pValue = pDataParams->bActPollTechCfg;
        break;

    case PHAC_DISCLOOP_CONFIG_COLLISION_PENDING:
        *pValue = pDataParams->bCollPend;
        break;

    case PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE:
        *pValue = (uint8)pDataParams->bPollState;
        break;

    case PHAC_DISCLOOP_CONFIG_ANTI_COLL:
        *pValue = pDataParams->bUseAntiColl;
        break;

    case PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE:
        *pValue = pDataParams->bVASUpFormat;
        break;

    case PHAC_DISCLOOP_CONFIG_TECH_DETECTED:
        *pValue = pDataParams->bDetectedTechs;
        break;

    case PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND:
        *pValue = pDataParams->bNumOfCards;
         break;

    case PHAC_DISCLOOP_CONFIG_BAIL_OUT:
        *pValue = pDataParams->bPasPollBailOut;
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG:
        *pValue = pDataParams->bPasPollTechCfg;
        break;

    case PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE:
    	*pValue = pDataParams->bCfgVasPolling;
        break;

    case PHAC_DISCLOOP_CONFIG_ENABLE_LPCD:
        *pValue = pDataParams->bLpcdEnabled;
        break;

    case PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION:
        *pValue = pDataParams->bNfcActivityVersion;
        break;

    case PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO:
        *pValue = pDataParams->wErrorCode;
        break;

    case PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US:
        *pValue = pDataParams->wActPollGTimeUs;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS
    case PHAC_DISCLOOP_CONFIG_GTA_VALUE_US:
        *pValue = pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_A];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_TAGS_FOUND:
        *pValue = pDataParams->sTypeATargetInfo.bTotalTagsFound;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT:
        *pValue = pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_A];
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI:
        *pValue = pDataParams->sTypeATargetInfo.sTypeA_I3P4.bFsdi;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID:
        *pValue = pDataParams->sTypeATargetInfo.sTypeA_I3P4.bCid;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_NAD:
        *pValue = pDataParams->sTypeATargetInfo.sTypeA_I3P4.bNad;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI:
        *pValue = pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDsi;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI:
        *pValue = pDataParams->sTypeATargetInfo.sTypeA_I3P4.bDri;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS
    case PHAC_DISCLOOP_CONFIG_GTB_VALUE_US:
        *pValue = pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_B];
        break;

     case PHAC_DISCLOOP_CONFIG_TYPEB_TAGS_FOUND:
        *pValue = pDataParams->sTypeBTargetInfo.bTotalTagsFound;
        break;

     case PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT:
        *pValue = pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_B];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_SUPPORT_TYPE4B:
        *pValue = pDataParams->sTypeBTargetInfo.aTypeB_I3P3[0].bSupportType4B;
        break;
 #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS
     case PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US:
         *pValue = pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F212];
         break;

     case PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US:
         *pValue = pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_F424];
         break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_TAGS_FOUND:
        *pValue = pDataParams->sTypeFTargetInfo.bTotalTagsFound;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT:
        *pValue = pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_F212];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD:
         *pValue = pDataParams->bFelicaBaud;
         break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS
    case PHAC_DISCLOOP_CONFIG_GTV_VALUE_US:
        *pValue = pDataParams->waPasPollGTimeUs[PHAC_DISCLOOP_TECH_TYPE_V];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT:
        *pValue = pDataParams->baPasConDevLim[PHAC_DISCLOOP_TECH_TYPE_V];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_TAGS_FOUND:
        *pValue = pDataParams->sTypeVTargetInfo.bTotalTagsFound;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE:
        if(0U != (pDataParams->sTypeVTargetInfo.bFlag & PHPAL_SLI15693_FLAG_DATA_RATE))
        {
            *pValue = PHHAL_HW_RF_RX_DATARATE_HIGH;
        }
        else
        {
            *pValue = PHHAL_HW_RF_RX_DATARATE_LOW;
        }
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET
    case PHAC_DISCLOOP_CONFIG_TARGET_RETRY_COUNT:
        *pValue = pDataParams->sTargetParams.bRetryCount;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET */

    default:
        status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
    }

    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_ActivateCard(
                                        P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint8, ANFCRL_VAR) bTechType,
                                        VAR(uint8, ANFCRL_VAR) bTagIndex
                                        )
{
    return phacDiscLoop_Sw_Int_ActivateDevice(pDataParams, bTechType, bTagIndex);
}

FUNC(phStatus_t, ANFCRL_CODE) phacDiscLoop_Sw_CfgPollSeq(
                                      P2VAR(phacDiscLoop_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiscloopCfgPollSeq
                                      )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bIndex = 0u;

    for (bIndex = 0u; bIndex < PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED; bIndex++)
    {
        if (pDiscloopCfgPollSeq[bIndex] >= PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED)
        {
            status = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_AC_DISCLOOP);
            break;
        }
    }

    if (bIndex == PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED)
    {
        pDataParams->pPasTechPollSeq = pDiscloopCfgPollSeq;
    }

	return status;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef __cplusplus
}
#endif

