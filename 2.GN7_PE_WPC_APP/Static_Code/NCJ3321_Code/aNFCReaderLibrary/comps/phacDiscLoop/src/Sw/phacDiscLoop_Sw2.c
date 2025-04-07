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
*   @file    phacDiscLoop_Sw2.c
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


#include <ph_Status2.h>
#include <ph_RefDefs2.h>
#include <phacDiscLoop2.h>
#include <phhalHw2.h>

#include <phpalI14443p3a2.h>
#include <phpalI14443p3b2.h>
#include <phpalI14443p4a2.h>
#include <phpalI14443p42.h>
#include <phpalFelica2.h>
#include <phpalSli156932.h>

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#include "phacDiscLoop_Sw2.h"
#include "phacDiscLoop_Sw_Int2.h"


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phacDiscLoop_Sw.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_VENDOR_ID_C2 != PHACDISCLOOP_SW_VENDOR_ID2)
    #error "phacDiscLoop_Sw2.c and phacDiscLoop_Sw.h have different vendor ids"
#endif
/* Check if current file and phacDiscLoop_Sw.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2    != PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2    != PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION_C2 != PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw2.c and phacDiscLoop_Sw.h are different"
#endif
/* Check if current file and phacDiscLoop_Sw.h header file are of the same Software version */
#if ((PHACDISCLOOP_SW_SW_MAJOR_VERSION_C2 != PHACDISCLOOP_SW_SW_MAJOR_VERSION2) || \
     (PHACDISCLOOP_SW_SW_MINOR_VERSION_C2 != PHACDISCLOOP_SW_SW_MINOR_VERSION2) || \
     (PHACDISCLOOP_SW_SW_PATCH_VERSION_C2 != PHACDISCLOOP_SW_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phacDiscLoop_Sw2.c and phacDiscLoop_Sw.h are different"
#endif
#endif  /* NXPBUILD__PHAC_DISCLOOP_SW2 */
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
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static CONST(uint8, ANFCRL_CONST) gPasTechPollSeqMapTable2[] = {
	(uint8)PHAC_DISCLOOP_TECH_TYPE_A2,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_B2,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_F2122,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_F4242,
	(uint8)PHAC_DISCLOOP_TECH_TYPE_V2,
};

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Init2(
                                P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                                )
{
    if (sizeof(phacDiscLoop_Sw_DataParams_t2) != wSizeOfDataParams2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_AC_DISCLOOP2);
    }

    PH_ASSERT_NULL2(pDataParams2);

    /* Initialize the private data */
    pDataParams2->wId2                      = PH_COMP_AC_DISCLOOP2 | PHAC_DISCLOOP_SW_ID2;
    pDataParams2->pHalDataParams2           = pHalDataParams2;
    pDataParams2->pPal1443p3aDataParams2    = NULL;
    pDataParams2->pPal1443p3bDataParams2    = NULL;
    pDataParams2->pPal14443p4DataParams2    = NULL;
    pDataParams2->pPalFelicaDataParams2     = NULL;
    pDataParams2->pPal1443p4aDataParams2    = NULL;
    pDataParams2->pPalSli15693DataParams2   = NULL;

    /* Default Operation Mode is NFC */
    pDataParams2->bOpeMode2                 = RD_LIB_MODE_NFC2;
    pDataParams2->bNfcActivityVersion2      = PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12;

    /* Default listen and poll mode technologies */
    pDataParams2->bPollState2               = PHAC_DISCLOOP_POLL_STATE_DETECTION2;
    pDataParams2->bPasPollTechCfg2          = 0x00;
    pDataParams2->bPasLisTechCfg2           = 0x00;
    pDataParams2->bActPollTechCfg2          = 0x00;
    pDataParams2->bActLisTechCfg2           = 0x00;

    pDataParams2->pPasTechPollSeq2          = (uint8 *)&gPasTechPollSeqMapTable2;

    pDataParams2->bUseAntiColl2             = PH_ON2;
    pDataParams2->bLpcdEnabled2             = PH_OFF2;

    pDataParams2->bNumOfCards2              = 0x00;
    pDataParams2->bDetectedTechs2           = 0x00;
    pDataParams2->bCollPend2                = 0x00;
    pDataParams2->wActPollGTimeUs2          = PH_NXPNFCRDLIB_CONFIG_TYPEA_GT2;

    pDataParams2->bPasPollBailOut2          = 0x00;

    /* Reset internal state */
    pDataParams2->bDiscLoopRunState2 = 0x00;
    pDataParams2->bDiscLoopColsnReslnActivityState2 = 0x00;
    pDataParams2->bDiscLoopTechDetectActivityState2 = 0x00;
    pDataParams2->bDiscLoopPollModeState2 = 0x00;
    pDataParams2->bDiscLoopSwIntFieldOnState2 = 0x00;
    pDataParams2->bDiscLoopSwIntRfcaOffFieldOnState2 = 0x00;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
    /* Poll device limits */
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2]           = PHAC_DISCLOOP_TYPEA_DEFAULT_DEVICE_LIMIT2;
    /* Guard times */
    pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_A2]         = PH_NXPNFCRDLIB_CONFIG_TYPEA_GT2;
    pDataParams2->bPasPollTechCfg2                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_A2);
    pDataParams2->bDiscLoopActivateAState2                             = 0x00;
    pDataParams2->bDiscLoopDetTechTypeAState2                          = 0x00;
    pDataParams2->bDiscLoopCollisionResolutionAState2                  = CollisionResolutionA_Start2;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE2
    pDataParams2->bPasLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE2
    pDataParams2->bActLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_A2;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    /* Poll device limits */
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_B2]           = PHAC_DISCLOOP_TYPEB_DEFAULT_DEVICE_LIMIT2;
    /* Guard times */
    pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_B2]         = PH_NXPNFCRDLIB_CONFIG_TYPEB_GT2;
    pDataParams2->bPasPollTechCfg2                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_B2);
    pDataParams2->bCollResBState2                                      = ColResolB_Start2;
    pDataParams2->bDiscLoopActivateBState2                             = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
    /* Poll device limits */
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122]        = PHAC_DISCLOOP_TYPEF_DEFAULT_DEVICE_LIMIT2;
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F4242]        = PHAC_DISCLOOP_TYPEF_DEFAULT_DEVICE_LIMIT2;
    /* Guard time GTFB */
    pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F2122]      = PH_NXPNFCRDLIB_CONFIG_TYPEF_GT2;
    /* Guard time GTBF */
    pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F4242]      = PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT2;
    pDataParams2->bPasPollTechCfg2                                     |= (PHAC_DISCLOOP_POS_BIT_MASK_F2122 | PHAC_DISCLOOP_POS_BIT_MASK_F4242);
    pDataParams2->bDiscLoopCollisionResolutionFState2                  = 0x00;
    pDataParams2->bDiscLoopActivateFState2                             = 0x00;
    pDataParams2->bDiscLoopSendSensFReq2                               = 0x00;
    pDataParams2->bDiscLoopDetTechTypeF2                               = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE2
    pDataParams2->bPasLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F2122;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE2
    pDataParams2->bPasLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F4242;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE2
    pDataParams2->bActLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F2122;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE2
    pDataParams2->bActLisTechCfg2                                      |= PHAC_DISCLOOP_POS_BIT_MASK_F4242;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    /* Poll device limits */
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2]      = PHAC_DISCLOOP_TYPEV_DEFAULT_DEVICE_LIMIT2;
    /* Guard times */
    pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_V2]    = PH_NXPNFCRDLIB_CONFIG_TYPEV_GT2;
    pDataParams2->bPasPollTechCfg2                                |= (PHAC_DISCLOOP_POS_BIT_MASK_V2);
	pDataParams2->bDiscLoopCollisionResolutionVState2             = 0x00;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2)
    pDataParams2->sTypeATargetInfo2.bTotalTagsFound2   = 0;

    #ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bFsdi2  = PHPAL_I14443P4A_NFC_FRAMESIZE_MAX2;
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bCid2   = 0x00;
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bNad2   = 0x00;
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDri2   = 0x00;
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDsi2   = 0x00;
    #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2   = 0x00;
    pDataParams2->sTypeBTargetInfo2.bAfiReq2           = 0x00;
    pDataParams2->sTypeBTargetInfo2.bFsdi2             = 0x08;
    pDataParams2->sTypeBTargetInfo2.bCid2              = 0x00;
    pDataParams2->sTypeBTargetInfo2.bNad2              = 0x00;
    pDataParams2->sTypeBTargetInfo2.bDri2              = 0x00;
    pDataParams2->sTypeBTargetInfo2.bDsi2              = 0x00;
    pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2  = 0x00;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
    pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2  = 0x00;
    pDataParams2->sTypeFTargetInfo2.aSystemCode2[0]   = 0xFF;
    pDataParams2->sTypeFTargetInfo2.aSystemCode2[1]   = 0xFF;
    pDataParams2->sTypeFTargetInfo2.bTimeSlot2        = PHPAL_FELICA_NUMSLOTS_42;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */


#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2  = 0x00;
    pDataParams2->sTypeVTargetInfo2.bFlag2            = PHPAL_SLI15693_FLAG_DATA_RATE2;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET2
    pDataParams2->sTargetParams2.bRetryCount2 = 0;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */

    return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Run2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(phacDiscLoop_Sw_EntryPoints_t2, ANFCRL_VAR) bEntryPoint2
	)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wDiscloopStatus2;

	if (pDataParams2->bDiscLoopRunState2 == 0U)
	{
		/* Disable Emd Check */
		PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_SET_EMD2, PH_OFF2));
		PH_CHECK_SUCCESS2(wDiscloopStatus2);
		pDataParams2->bDiscLoopRunState2 = 1U;
		return PH_STATUS_INPROCESS2;
	}
	switch (bEntryPoint2)
	{
	case PHAC_DISCLOOP_ENTRY_POINT_POLL2:

#ifdef NXPBUILD__PHAC_DISCLOOP_LPCD2
		/* Perform LPCD if Enabled. */
		if ((pDataParams2->bDiscLoopRunState2 == 1U) && (0U != (pDataParams2->bLpcdEnabled2)) && (pDataParams2->bPollState2 == PHAC_DISCLOOP_POLL_STATE_DETECTION2))
		{
	#ifdef NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD2
			PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phhalHw_HybridLPCD2(pDataParams2->pHalDataParams2));
	#else
			PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phhalHw_Lpcd2(pDataParams2->pHalDataParams2));
	#endif /*NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD2*/

			if ((wDiscloopStatus2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
			{
				pDataParams2->bDiscLoopRunState2 = 0U;
				if ((wDiscloopStatus2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
				{
					return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2); /* No card presence. */
				}

				return wDiscloopStatus2; /* Other error. */
			}
		}
#endif /* NXPBUILD__PHAC_DISCLOOP_LPCD2 */
    	if (pDataParams2->bDiscLoopRunState2 == 1U)
    	{
    		pDataParams2->bDiscLoopRunState2 = 2U;
    	}
		/* Check for active poll configuration */
		if ((pDataParams2->bDiscLoopRunState2 == 2U) && (0U != (pDataParams2->bActPollTechCfg2)) && (pDataParams2->bPollState2 == PHAC_DISCLOOP_POLL_STATE_DETECTION2))
		{
			PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phacDiscLoop_Sw_Int_ActivePollMode2(pDataParams2));
			/* Continue with passive polling, if no peer detected */
			if ((wDiscloopStatus2 & PH_ERR_MASK2) != PHAC_DISCLOOP_NO_TECH_DETECTED2)
			{
				pDataParams2->bDiscLoopRunState2 = 0U;
				if (((wDiscloopStatus2 & PH_ERR_MASK2) != PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED2)
						&& ((wDiscloopStatus2 & PH_ERR_MASK2) != PHAC_DISCLOOP_EXTERNAL_RFON2))
				{
					pDataParams2->wErrorCode2 = wDiscloopStatus2;
					return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_FAILURE2, PH_COMP_AC_DISCLOOP2);
				}
				return wDiscloopStatus2;
			}
			/* Field OFF after Active polling and wait for recovery time. */
			PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phhalHw_FieldOff2(pDataParams2->pHalDataParams2));
			if (wDiscloopStatus2 != PH_ERR_SUCCESS2)
			{
				pDataParams2->bDiscLoopRunState2 = 0U;
				return wDiscloopStatus2;
			}
			wDiscloopStatus2 = phhalHw_Wait2(pDataParams2->pHalDataParams2, PHHAL_HW_TIME_MICROSECONDS2, pDataParams2->wActPollGTimeUs2);
			if (wDiscloopStatus2 != PH_ERR_SUCCESS2)
			{
				pDataParams2->bDiscLoopRunState2 = 0U;
				return wDiscloopStatus2;
			}
			pDataParams2->bDiscLoopRunState2 = 3U;
		}

		/* Check for passive poll configuration */
		if (0U != (pDataParams2->bPasPollTechCfg2))
		{
			/* Perform the Poll operation and store the Status code. */
			PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phacDiscLoop_Sw_Int_PollMode2(pDataParams2));

			pDataParams2->bDiscLoopRunState2 = 0U;
			/* If error is from below layer, store it and return failure */
			if ((wDiscloopStatus2 & PH_COMP_MASK2) != PH_COMP_AC_DISCLOOP2)
			{
				pDataParams2->wErrorCode2 = wDiscloopStatus2;
				return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_FAILURE2, PH_COMP_AC_DISCLOOP2);
			}
			return wDiscloopStatus2;
		}
		else
		{
			pDataParams2->bDetectedTechs2 = 0x00;
			pDataParams2->bNumOfCards2 = 0x00;
			pDataParams2->bDiscLoopRunState2 = 0U;
			return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_NO_TECH_DETECTED2, PH_COMP_AC_DISCLOOP2);
		}

    case PHAC_DISCLOOP_ENTRY_POINT_LISTEN2:
        /* Check for listen configurations */
        if ((0U != (pDataParams2->bPasLisTechCfg2)) || (0U != (pDataParams2->bActLisTechCfg2)))
        {
        	if (pDataParams2->bDiscLoopRunState2 == 1U)
        	{
				/* Turn OFF RF field if already on. */
        		PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phhalHw_FieldOff2(pDataParams2->pHalDataParams2));
				if (wDiscloopStatus2 != PH_ERR_SUCCESS2)
				{
					pDataParams2->bDiscLoopRunState2 = 0U;
					return wDiscloopStatus2;
				}
				pDataParams2->bDiscLoopRunState2 = 2U;
        	}
            /* Perform listen operation and store the Status code. */
        	PH_CHECK_INPROCESS_FCT2(wDiscloopStatus2, phacDiscLoop_Sw_Int_ListenMode2(pDataParams2));

			pDataParams2->bDiscLoopRunState2 = 0U;
            /* If error is from below layer, store it and return failure */
            if((wDiscloopStatus2 & PH_COMP_MASK2) != PH_COMP_AC_DISCLOOP2)
            {
                pDataParams2->wErrorCode2 = wDiscloopStatus2;
                return PH_ADD_COMPCODE_FIXED2(PHAC_DISCLOOP_FAILURE2, PH_COMP_AC_DISCLOOP2);
            }
            return wDiscloopStatus2;
        }
        else
        {
			pDataParams2->bDiscLoopRunState2 = 0U;
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }

    default:
		pDataParams2->bDiscLoopRunState2 = 0U;
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
    }
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_SetConfig2(
                                     P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint16, ANFCRL_VAR) wConfig2,
                                     VAR(uint16, ANFCRL_VAR) wValue2
                                     )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

    switch(wConfig2)
    {
    case PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2:
        pDataParams2->bActLisTechCfg2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2:
        pDataParams2->bActPollTechCfg2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2:
        pDataParams2->bPasLisTechCfg2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2:
        pDataParams2->bCollPend2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2:
        if(!(((wValue2 & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_DETECTION2) ||
            ((wValue2 & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2) ||
            ((wValue2 & 0x00FFU) == PHAC_DISCLOOP_POLL_STATE_REMOVAL2)))
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->bPollState2 = (wValue2 & 0x00FFU);
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2:
        pDataParams2->bPasPollTechCfg2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE2:
        pDataParams2->bCfgVasPolling2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_ANTI_COLL2:
        pDataParams2->bUseAntiColl2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2:
            pDataParams2->bVASUpFormat2 = (uint8)wValue2;
            break;

    case PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2:
        if((wValue2 != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02)
           && (wValue2 != PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12))
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->bNfcActivityVersion2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2:
        pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_A2] = wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2:
        pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_B2] = wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US2:
        if(wValue2 < PH_NXPNFCRDLIB_CONFIG_TYPEF_GT2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F2122] = wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US2:
        if(wValue2 < PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F4242] = wValue2;
        break;

	case PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2:
		pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_V2] = wValue2;
		break;

	case PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US2:
		pDataParams2->wActPollGTimeUs2 = wValue2;
		break;

    case PHAC_DISCLOOP_CONFIG_BAIL_OUT2:
        if (0u != (wValue2 & ~(PHAC_DISCLOOP_POS_BIT_MASK_A2 |  PHAC_DISCLOOP_POS_BIT_MASK_B2
            | PHAC_DISCLOOP_POS_BIT_MASK_F4242 | PHAC_DISCLOOP_POS_BIT_MASK_F2122
            | PHAC_DISCLOOP_POS_BIT_MASK_V2)))
        {
            /* Invalid bail out option set */
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }

        pDataParams2->bPasPollBailOut2 = (uint8) wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_OPE_MODE2:
        if(!((wValue2 == RD_LIB_MODE_NFC2) ||
            (wValue2 == RD_LIB_MODE_EMVCO2) ||
            (wValue2 == RD_LIB_MODE_ISO2)))
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->bOpeMode2 = (uint8)wValue2;
        PH_CHECK_SUCCESS_FCT2(status2, phhalHw_SetConfig2(pDataParams2->pHalDataParams2, PHHAL_HW_CONFIG_OPE_MODE2, wValue2));
#ifdef NXPBUILD__PHPAL_I14443P4_SW2
        PH_CHECK_SUCCESS_FCT2(status2, phpalI14443p4_SetConfig2(pDataParams2->pPal14443p4DataParams2, PHPAL_I14443P4_CONFIG_OPE_MODE2, wValue2));
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
        PH_CHECK_SUCCESS_FCT2(status2, phpalI14443p3b_SetConfig2(pDataParams2->pPal1443p3bDataParams2, PHPAL_I14443P3B_CONFIG_OPE_MODE2, wValue2));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
        PH_CHECK_SUCCESS_FCT2(status2, phpalI14443p3a_SetConfig2(pDataParams2->pPal1443p3aDataParams2, PHPAL_I14443P3A_CONFIG_OPE_MODE2, wValue2));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
        PH_CHECK_SUCCESS_FCT2(status2, phpalI14443p4a_SetConfig2(pDataParams2->pPal1443p4aDataParams2, PHPAL_I14443P4A_CONFIG_OPE_MODE2, wValue2));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */
        break;

    case PHAC_DISCLOOP_CONFIG_ENABLE_LPCD2:
        pDataParams2->bLpcdEnabled2 = (uint8)wValue2;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2:
        if((wValue2 & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2] = (uint8)wValue2;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI2:
            if (wValue2 > PHPAL_I14443P4_FRAMESIZE_MAX2)
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
            }
            pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bFsdi2 = (uint8)wValue2;
            break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID2:
        if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_CID2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bCid2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_NAD2:
        /* Valid NAD complaint with ISO/IEC 7816-3 shall be set by application. */
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bNad2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI2:
        if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_DRI2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDri2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI2:
        if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_DSI2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDsi2 = (uint8)wValue2;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2:
    if((wValue2 & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
    }
    pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_B2] = (uint8)wValue2;
    break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_AFI_REQ2:
      pDataParams2->sTypeBTargetInfo2.bAfiReq2 = (uint8)wValue2;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_EXTATQB2:
      if (wValue2 == 0U)
      {
          pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2 = 0;
      }
      else
      {
          pDataParams2->sTypeBTargetInfo2.bExtendedAtqBbit2 = 1;
      }
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_FSDI2:
      if (wValue2 > PHPAL_I14443P3B_FRAMESIZE_MAX2)
      {
          return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
      }
      pDataParams2->sTypeBTargetInfo2.bFsdi2 = (uint8)wValue2;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_CID2:
      if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_CID2)
      {
          return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
      }
      pDataParams2->sTypeBTargetInfo2.bCid2 = (uint8)wValue2;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_NAD2:
        /* Valid NAD complaint with ISO/IEC 7816-3 shall be set by application. */
        pDataParams2->sTypeBTargetInfo2.bNad2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_DRI2:
      if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_DRI2)
      {
          return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
      }
      pDataParams2->sTypeBTargetInfo2.bDri2 = (uint8)wValue2;
      break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_DSI2:
      if (wValue2 > PHAC_DISCLOOP_SW_I3P4_MAX_DSI2)
      {
          return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
      }
      pDataParams2->sTypeBTargetInfo2.bDsi2 = (uint8)wValue2;
      break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2:
        pDataParams2->bFelicaBaud2 = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT2:
        if((wValue2 & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122] = (uint8)wValue2;
        break;

#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2:
        if((wValue2 & 0xFFU) > PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2] = (uint8)wValue2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE2:
        if((wValue2 != PHHAL_HW_RF_RX_DATARATE_HIGH2)
           && (wValue2 != PHHAL_HW_RF_RX_DATARATE_LOW2))
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }

        /* Set request flag to indicate high data rate */
        if(wValue2 == PHHAL_HW_RF_RX_DATARATE_HIGH2)
        {
            pDataParams2->sTypeVTargetInfo2.bFlag2 |= PHPAL_SLI15693_FLAG_DATA_RATE2;
        }
        else
        {
            pDataParams2->sTypeVTargetInfo2.bFlag2 &= ~((uint8)PHPAL_SLI15693_FLAG_DATA_RATE2);
        }
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET2
    case PHAC_DISCLOOP_CONFIG_TARGET_RETRY_COUNT2:
        if (wValue2 > 255U)
        {
            return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
        }
        pDataParams2->sTargetParams2.bRetryCount2 = (uint8)wValue2;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_GetConfig2(
                                     P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint16, ANFCRL_VAR) wConfig2,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                     )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

    switch(wConfig2)
    {
    case PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2:
        *pValue2 = pDataParams2->bPasLisTechCfg2;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2:
        *pValue2 = pDataParams2->bActLisTechCfg2;
        break;

    case PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2:
        *pValue2 = pDataParams2->bActPollTechCfg2;
        break;

    case PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2:
        *pValue2 = pDataParams2->bCollPend2;
        break;

    case PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2:
        *pValue2 = (uint8)pDataParams2->bPollState2;
        break;

    case PHAC_DISCLOOP_CONFIG_ANTI_COLL2:
        *pValue2 = pDataParams2->bUseAntiColl2;
        break;

    case PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2:
        *pValue2 = pDataParams2->bVASUpFormat2;
        break;

    case PHAC_DISCLOOP_CONFIG_TECH_DETECTED2:
        *pValue2 = pDataParams2->bDetectedTechs2;
        break;

    case PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND2:
        *pValue2 = pDataParams2->bNumOfCards2;
         break;

    case PHAC_DISCLOOP_CONFIG_BAIL_OUT2:
        *pValue2 = pDataParams2->bPasPollBailOut2;
        break;

    case PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2:
        *pValue2 = pDataParams2->bPasPollTechCfg2;
        break;

    case PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE2:
    	*pValue2 = pDataParams2->bCfgVasPolling2;
        break;

    case PHAC_DISCLOOP_CONFIG_ENABLE_LPCD2:
        *pValue2 = pDataParams2->bLpcdEnabled2;
        break;

    case PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2:
        *pValue2 = pDataParams2->bNfcActivityVersion2;
        break;

    case PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2:
        *pValue2 = pDataParams2->wErrorCode2;
        break;

    case PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US2:
        *pValue2 = pDataParams2->wActPollGTimeUs2;
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
    case PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2:
        *pValue2 = pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_A2];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_TAGS_FOUND2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.bTotalTagsFound2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2:
        *pValue2 = pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_A2];
        break;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bFsdi2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bCid2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_NAD2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bNad2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDsi2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI2:
        *pValue2 = pDataParams2->sTypeATargetInfo2.sTypeA_I3P42.bDri2;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    case PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2:
        *pValue2 = pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_B2];
        break;

     case PHAC_DISCLOOP_CONFIG_TYPEB_TAGS_FOUND2:
        *pValue2 = pDataParams2->sTypeBTargetInfo2.bTotalTagsFound2;
        break;

     case PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2:
        *pValue2 = pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_B2];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEB_SUPPORT_TYPE4B2:
        *pValue2 = pDataParams2->sTypeBTargetInfo2.aTypeB_I3P32[0].bSupportType4B2;
        break;
 #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
     case PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US2:
         *pValue2 = pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F2122];
         break;

     case PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US2:
         *pValue2 = pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_F4242];
         break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_TAGS_FOUND2:
        *pValue2 = pDataParams2->sTypeFTargetInfo2.bTotalTagsFound2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT2:
        *pValue2 = pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_F2122];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2:
         *pValue2 = pDataParams2->bFelicaBaud2;
         break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    case PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2:
        *pValue2 = pDataParams2->waPasPollGTimeUs2[PHAC_DISCLOOP_TECH_TYPE_V2];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2:
        *pValue2 = pDataParams2->baPasConDevLim2[PHAC_DISCLOOP_TECH_TYPE_V2];
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_TAGS_FOUND2:
        *pValue2 = pDataParams2->sTypeVTargetInfo2.bTotalTagsFound2;
        break;

    case PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE2:
        if(0U != (pDataParams2->sTypeVTargetInfo2.bFlag2 & PHPAL_SLI15693_FLAG_DATA_RATE2))
        {
            *pValue2 = PHHAL_HW_RF_RX_DATARATE_HIGH2;
        }
        else
        {
            *pValue2 = PHHAL_HW_RF_RX_DATARATE_LOW2;
        }
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET2
    case PHAC_DISCLOOP_CONFIG_TARGET_RETRY_COUNT2:
        *pValue2 = pDataParams2->sTargetParams2.bRetryCount2;
        break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */

    default:
        status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
    }

    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_ActivateCard2(
                                        P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bTechType2,
                                        VAR(uint8, ANFCRL_VAR) bTagIndex2
                                        )
{
    return phacDiscLoop_Sw_Int_ActivateDevice2(pDataParams2, bTechType2, bTagIndex2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_CfgPollSeq2(
                                      P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiscloopCfgPollSeq2
                                      )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bIndex2 = 0u;

    for (bIndex2 = 0u; bIndex2 < PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2; bIndex2++)
    {
        if (pDiscloopCfgPollSeq2[bIndex2] >= PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2)
        {
            status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_AC_DISCLOOP2);
            break;
        }
    }

    if (bIndex2 == PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2)
    {
        pDataParams2->pPasTechPollSeq2 = pDiscloopCfgPollSeq2;
    }

	return status2;
}
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif

