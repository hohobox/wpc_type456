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
*   @file    phNfcLib.c
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
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
#ifdef NXPBUILD__PHNFCLIB_PROFILES
#include <ph_Status.h>
#include "phNfcLib_Initialization.h"
#include "phNfcLib_Int.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib.h header file are of the same vendor */
#if (PHNFCLIB_VENDOR_ID_C != PHNFCLIB_VENDOR_ID)
    #error "phNfcLib.c and phNfcLib.h have different vendor ids"
#endif
/* Check if current file and phNfcLib.h header file are of the same Autosar version */
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C    != PHNFCLIB_AR_RELEASE_MAJOR_VERSION) || \
     (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C    != PHNFCLIB_AR_RELEASE_MINOR_VERSION) || \
     (PHNFCLIB_AR_RELEASE_REVISION_VERSION_C != PHNFCLIB_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib.c and phNfcLib.h are different"
#endif
/* Check if current file and phNfcLib.h header file are of the same Software version */
#if ((PHNFCLIB_SW_MAJOR_VERSION_C != PHNFCLIB_SW_MAJOR_VERSION) || \
     (PHNFCLIB_SW_MINOR_VERSION_C != PHNFCLIB_SW_MINOR_VERSION) || \
     (PHNFCLIB_SW_PATCH_VERSION_C != PHNFCLIB_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib.c and phNfcLib.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB_PROFILES */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB_PROFILES
typedef enum{
	PHNFCLIB_TRANSMIT_ST_IDLE = 0,
	PHNFCLIB_TRANSMIT_ST_EXCHANGE,
	PHNFCLIB_TRANSMIT_ST_DONE
} phNfclib_TransmitState_t;

typedef enum
{
	PHNFCLIB_DEACTIVE_IDLE = 0,
	PHNFCLIB_DEACTIVE_DONE,
	PHNFCLIB_DEACTIVE_FIELDOFF,
	PHNFCLIB_DEACTIVE_WAIT,
	PHNFCLIB_DEACTIVE_HALT
} phNfclib_DeactivateState_t;

typedef enum{
	PHNFCLIB_ACTIVE_ST_IDLE = 0,
	PHNFCLIB_ACTIVATE_ST_START,
	PHNFCLIB_ACTIVE_ST_DONE,
	PHNFCLIB_ACT_ISO_ST_RUN,
	PHNFCLIB_ACT_ISO_ST_PROCESS,
	PHNFCLIB_ACT_ISO_ST_ACTIVATING,
	PHNFCLIB_ACT_ISO_ST_ACTIVATED
} phNfclib_ActivateState_t;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static CONST(pphNfcLib_Config_Profile, AUTOMATIC) pConfigProfile[] =
{ &phNfcLib_Config_NFC_Profile, &phNfcLib_Config_ISO_Profile };

static CONST(pphNfcLib_Activate_Profile, AUTOMATIC) pActivate[] =
{ &phNfcLib_Activate_NFC_Profile, &phNfcLib_Activate_ISO_Profile };

static CONST(pphNfcLib_Deactivate_Profile, AUTOMATIC) pDeactivate[] =
{ &phNfcLib_Deactivate_NFC_Profile, &phNfcLib_Deactivate_ISO_Profile };

static CONST(pphNfcLib_Transmit, AUTOMATIC) pTransmit[] =
{ &phNfcLib_NFC_Transmit, &phNfcLib_ISO_Transmit };

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static VAR(phNfclib_TransmitState_t, AUTOMATIC) geTransmitState = PHNFCLIB_TRANSMIT_ST_IDLE;
static VAR(phNfclib_DeactivateState_t, ANFCRL_VAR) gbDeactivateState =
		PHNFCLIB_DEACTIVE_IDLE;
static VAR(phNfclib_ActivateState_t, ANFCRL_VAR) gbActivateState = PHNFCLIB_ACTIVE_ST_IDLE;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Config_NFC_Profile(VAR(void, AUTOMATIC));
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Config_ISO_Profile(VAR(void, AUTOMATIC));

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Activate_NFC_Profile(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask);
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Activate_ISO_Profile(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask);

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Deactivate_NFC_Profile(VAR(void, AUTOMATIC));
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Deactivate_ISO_Profile(VAR(void, AUTOMATIC));

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_NFC_Transmit(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength);
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_ISO_Transmit(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength);

#ifdef NXPBUILD__PH_NFCLIB_ISO
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Configure_DiscLoop_ISO(VAR(uint16_t, AUTOMATIC) wTechnologyMask);
#endif /* NXPBUILD__PH_NFCLIB_ISO*/

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Config_NFC_Profile(VAR(void, AUTOMATIC))
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t, AUTOMATIC) wStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;

	return wStatus;
}
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Config_ISO_Profile(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t, AUTOMATIC) wStatus = PH_ERR_SUCCESS;
#ifdef  NXPBUILD__PH_NFCLIB_ISO

	/* TODO: Set the LPCD state to Zero in ISO mode. */
	gphNfcLib_State.bLPCDState = 1;

	/* Enable Bail-out config in ISO mode. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_BAIL_OUT, 0x13 ));

	/* Enable LPCD feature. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ENABLE_LPCD, PH_OFF ));

	/* reset collision Pending */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_COLLISION_PENDING, PH_OFF ));

	/* whether anti-collision is supported or not. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ANTI_COLL, PH_ON ));

#ifdef NXPBUILD__PHPAL_I14443P3A_SW
	/* Passive CON_DEVICE limit. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT, 1 ));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT, 1 ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */

#ifdef NXPBUILD__PHPAL_SLI15693_SW
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT, PH_NFCLIB_MAX_ISO15693_TAGS_SUPPORTED ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW
	/* Passive polling Tx Guard times in micro seconds. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_GTA_VALUE_US, PH_NXPNFCRDLIB_CONFIG_TYPEA_GT ));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_GTB_VALUE_US, PH_NXPNFCRDLIB_CONFIG_TYPEB_GT ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW*/

#ifdef NXPBUILD__PHPAL_SLI15693_SW
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_GTV_VALUE_US, 5200 ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
	/* Configure FSDI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI, 0x08 ));

	/* Configure CID for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID, 0x00 ));

	/* Configure DRI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI, 0x00 ));

	/* Configure DSI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI, 0x00 ));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
	/* Configure AFI for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_AFI_REQ, 0x00 ));

	/* Configure FSDI for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_FSDI, 0x08 ));

	/* Configure CID for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_CID, 0x00 ));

	/* Configure DRI for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_DRI, 0x00 ));

	/* Configure DSI for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_DSI, 0x00 ));

	/* Configure Extended ATQB support for the type B tags */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEB_EXTATQB, 0x00 ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW*/

#ifdef NXPBUILD__PHPAL_SLI15693_SW
	/* Configure ISO 15693 for high/low RX data rate */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE, 0x000D ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW */

	/* Configure reader library mode */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_OPE_MODE, RD_LIB_MODE_ISO ));

#endif /* NXPBUILD__PH_NFCLIB_ISO*/
	return wStatus;
}

#ifdef NXPBUILD__PH_NFCLIB_ISO
static FUNC(phStatus_t, ANFCRL_API) phNfcLib_Configure_DiscLoop_ISO(VAR(uint16_t, AUTOMATIC) wTechnologyMask)
{
	VAR(phStatus_t, AUTOMATIC) wStatus = PH_ERR_SUCCESS;

	if ((0U != (wTechnologyMask & PH_NFCLIB_TECHNOLOGY_INITIATOR_FELICA))
			|| (0U != ((wTechnologyMask & PH_NFCLIB_TECHNOLOGY_TARGET_FELICA))))
	{
		return PH_ERR_INVALID_PARAMETER;
	}

	/*  Passive Listen bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG, 0x00 ));

	/*  Active Listen bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG, 0x00 ));

	/* TODO: to be changed if technology mask bit value for active changes */
	/* Active poll bit map config. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG, (((wTechnologyMask & 0x0020U) != 0U) ? 0x0007U : 0x0U) ));

	/* TODO: to be changed if technology mask bit value for felica changes */
	wTechnologyMask = (wTechnologyMask & 0x0007U)
			| ((wTechnologyMask << 1U) & 0x0030U);

	/* Passive poll bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG, (wTechnologyMask & 0x0033U) ));

	/* Poll Mode default state*/
	PH_CHECK_SUCCESS_FCT(wStatus,
			phacDiscLoop_SetConfig( &gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE, (uint16_t)PHAC_DISCLOOP_POLL_STATE_DETECTION ));

	return wStatus;
}
#endif /* NXPBUILD__PH_NFCLIB_ISO*/

static FUNC(phStatus_t,ANFCRL_API) phNfcLib_Activate_NFC_Profile(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask)
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
	PH_UNUSED_VARIABLE(wTechnologyMask);
	gbActivateState = PHNFCLIB_ACTIVE_ST_DONE;
	return wStatus;
}

static FUNC(phStatus_t,ANFCRL_API) phNfcLib_Activate_ISO_Profile(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask)
{
	VAR(phStatus_t, ANFCRL_VAR) wtmpStatus = PH_ERR_INTERNAL_ERROR;
#ifdef NXPBUILD__PH_NFCLIB_ISO
	VAR(phStatus_t, ANFCRL_VAR) wStatus    = PH_ERR_SUCCESS;
	VAR(uint16_t, ANFCRL_VAR)   wValue;
	VAR(uint16_t, ANFCRL_VAR) wTagsDetected = 0;
	VAR(uint16_t, ANFCRL_VAR) wGtLength = 0;
#if defined(NXPBUILD__PHPAL_I14443P4A_SW) && defined(NXPBUILD__PHPAL_I14443P4_SW)
	VAR(uint8_t, ANFCRL_VAR) bCidEnabled = 0;
	VAR(uint8_t, ANFCRL_VAR) bCid = 0;
	VAR(uint8_t, ANFCRL_VAR) bNadSupported = 0;
	VAR(uint8_t, ANFCRL_VAR) bFwi = 0;
	VAR(uint8_t, ANFCRL_VAR) bFsdi = 0;
	VAR(uint8_t, ANFCRL_VAR) bFsci = 0;
#endif
#if defined(NXPBUILD__PH_NFCLIB_ISO_15693)
	VAR(uint8_t, ANFCRL_VAR) bIndex = 0;
#endif
	VAR(uint32_t, ANFCRL_VAR) sak_atqa = 0;

	switch(gbActivateState)
	{
		case PHNFCLIB_ACTIVE_ST_IDLE:
		case PHNFCLIB_ACTIVE_ST_DONE:
			break;
		case PHNFCLIB_ACTIVATE_ST_START:
			/* Set the LPCD state to one in ISO  mode. */
			gphNfcLib_State.bLPCDState = 1;

			wStatus = phNfcLib_Configure_DiscLoop_ISO(wTechnologyMask);
			if(wStatus != PH_ERR_SUCCESS)
			{
				wtmpStatus = wStatus;
				break;
			}

			/* For ISO mode the starting mode is poll */
			/* TODO if technology mask says no poll then entry point has to be only listen and vice versa */
			gphNfcLib_State.bEntryPoint = (uint8_t)PHAC_DISCLOOP_ENTRY_POINT_POLL;

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
			/* Assign ATS buffer for Type A */
			gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.pAts = gphNfcLib_State.pPeerInfo->uRi.uInitiator.tIso14443_4.aAts;
#endif /* NXPBUILD__PHPAL_I14443P4A_SW*/
			gbActivateState = PHNFCLIB_ACT_ISO_ST_RUN;
			return PH_STATUS_INPROCESS;

		case PHNFCLIB_ACT_ISO_ST_RUN:
		case PHNFCLIB_ACT_ISO_ST_ACTIVATING:
			return PH_STATUS_INPROCESS;

		case PHNFCLIB_ACT_ISO_ST_PROCESS:
			/*restore status of Discovery Loop Run*/
			wtmpStatus = gphNfcLib_State.wBkpStatus;
			/* Reset Activated tag/peer type. */
			gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_UNKNOWN;

			if (((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_TECH_DETECTED) ||
				((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED) ||
				((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_EXTERNAL_RFON))
			{
				/* In ISO mode, Target mode is not supported. */
			}
			else if(((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED)
				||((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED)
				||((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND))
			{
				if ((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND)
				{
					if(gphNfcLib_State.bMergedSakPrio == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_14443)
					{
	#if defined(NXPBUILD__PHPAL_I14443P4A_SW) && defined(NXPBUILD__PHPAL_I14443P4_SW)
						gbActivateState = PHNFCLIB_ACT_ISO_ST_ACTIVATING;
						return PH_STATUS_INPROCESS;
	#endif
					}
					else
					{
					}
				}
				else
				{
					/* Get detected technology type */
					wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
					if(wStatus != PH_ERR_SUCCESS)
					{
						wtmpStatus = wStatus;
						break;
					}
					else
					{
						/*TODO: nothing */
					}
				}
			}
			else if((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_DEVICE_ACTIVATED)
			{
				/* Get detected technology type */
				wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
				if(wStatus != PH_ERR_SUCCESS)
				{
					wtmpStatus = wStatus;
					break;
				}
	#ifdef NXPBUILD__PHPAL_I14443P3A_SW
				if(PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_A))
				{
					gphNfcLib_State.pPeerInfo->uTi.uInitiator.tIso14443_3a.bUidLength = gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].bUidSize;
					(void)memcpy(&gphNfcLib_State.pPeerInfo->uTi.uInitiator.tIso14443_3a.aUid[0], &gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].aUid[0] ,gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].bUidSize);

					sak_atqa = (uint32_t)((((uint32_t)(gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].aSak)) << 16U) |
						(gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].aAtqa[0] << 8U) |
						(gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].aAtqa[1]));

					switch (sak_atqa & 0x00FF0FFFU)
					{
					case PH_NFCLIB_SAK_MFC_1K << 16U | PH_NFCLIB_ATQA_MFP_S:
						gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_MIFARE_CLASSIC_1K;
						break;
					case PH_NFCLIB_SAK_MFC_4K << 16U | PH_NFCLIB_ATQA_MFC:
						gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_MIFARE_CLASSIC_4K;
						break;
					default:
						break;
					}

					if ((gphNfcLib_State.pPeerInfo->dwActivatedType) == E_PH_NFCLIB_UNKNOWN)
					{
						switch (sak_atqa)
						{
						case PH_NFCLIB_SAK_UL << 16U | PH_NFCLIB_ATQA_UL:
							gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_MIFARE_ULTRALIGHT;
							break;
						case PH_NFCLIB_SAK_LAYER4 << 16U | PH_NFCLIB_ATQA_DESFIRE:
							gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_MIFARE_DESFIRE;
							break;
						case PH_NFCLIB_SAK_LAYER4 << 16U | PH_NFCLIB_ATQA_DESFIRE1:
							gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_MIFARE_DESFIRE;
							break;
						default:
							break;
						}
					}
					if (gphNfcLib_State.pPeerInfo->dwActivatedType == E_PH_NFCLIB_UNKNOWN)
					{
						if(gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.aTypeA_I3P3[0].aSak == PH_NFCLIB_SAK_LAYER4)
						{
							gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_TYPEA_LAYER4;
						}
						else
						{
							gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_TYPEA_LAYER3;
						}
					}
					break;

				}
	#endif /* NXPBUILD__PHPAL_I14443P3A_SW */
	#ifdef NXPBUILD__PHPAL_I14443P3B_SW
				if(PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_B))
				{
					wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop,
						PHAC_DISCLOOP_CONFIG_TYPEB_SUPPORT_TYPE4B,
						&wValue);
					if(wStatus != PH_ERR_SUCCESS)
					{
						wtmpStatus = wStatus;
						break;
					}
					if (wValue == PH_OFF)
					{
						gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_TYPEB_LAYER3;
					}
					else
					{
						gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_TYPEB_LAYER4;
					}
					break;
				}
	#endif /* NXPBUILD__PHPAL_I14443P3B_SW */
	#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
				if(PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_V))
				{
					gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_ISO15693;
					gphNfcLib_State.pPeerInfo->uTi.uInitiator.tIso15693.TagIndex[0].pUid = &gphNfcLib_Params.sDiscLoop.sTypeVTargetInfo.aTypeV[0].aUid[0];
					gphNfcLib_State.pActivatedUid = &gphNfcLib_Params.sDiscLoop.sTypeVTargetInfo.aTypeV[0].aUid[0];
					gphNfcLib_State.wActivatedUIDLength = 8;
					break;
				}
	#endif /* NXPBUILD__PH_NFCLIB_ISO_15693 */

			}

			else if((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED)
			{
				/* Get detected technology type */
				wStatus =  phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_TECH_DETECTED, &wTagsDetected);
				if(wStatus != PH_ERR_SUCCESS)
				{
					wtmpStatus = wStatus;
					break;
				}
	#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
				if(PHAC_DISCLOOP_CHECK_ANDMASK(wTagsDetected, PHAC_DISCLOOP_POS_BIT_MASK_V))
				{
					gphNfcLib_State.pPeerInfo->uTi.uInitiator.tIso15693.bTotalTagsFound = gphNfcLib_Params.sDiscLoop.sTypeVTargetInfo.bTotalTagsFound;
					for(bIndex =0; bIndex < gphNfcLib_Params.sDiscLoop.sTypeVTargetInfo.bTotalTagsFound; bIndex++)
					{
						gphNfcLib_State.pPeerInfo->uTi.uInitiator.tIso15693.TagIndex[bIndex].pUid = &gphNfcLib_Params.sDiscLoop.sTypeVTargetInfo.aTypeV[bIndex].aUid[0];
					}
					gphNfcLib_State.pPeerInfo->dwActivatedType = E_PH_NFCLIB_ISO15693;
					break;
				}
	#endif /* NXPBUILD__PH_NFCLIB_ISO_15693 */

			}
			else
			{
				if((wtmpStatus & PH_ERR_MASK) != PHAC_DISCLOOP_NO_TECH_DETECTED)
				{
					if ((wtmpStatus & PH_ERR_MASK) == PHAC_DISCLOOP_FAILURE)
					{
						wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO, &wValue);
						if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
						{
							if ((wValue & PH_ERR_MASK) == PH_ERR_ABORTED)
							{
								break;
							}
						}
					}
				}
			}
			break;

		case PHNFCLIB_ACT_ISO_ST_ACTIVATED:
			if(gphNfcLib_State.bMergedSakPrio == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_14443)
			{
				 /* Retrieve 14443-4A protocol parameter */
				wtmpStatus = phpalI14443p4a_GetProtocolParams(
					gphNfcLib_Params.sDiscLoop.pPal1443p4aDataParams,
					&bCidEnabled,
					&bCid,
					&bNadSupported,
					&bFwi,
					&bFsdi,
					&bFsci);
				PH_BREAK_ON_FAILURE(wtmpStatus);

				/* Set 14443-4 protocol parameter */
				wtmpStatus = phpalI14443p4_SetProtocol(
					gphNfcLib_Params.sDiscLoop.pPal14443p4DataParams,
					bCidEnabled,
					bCid,
					bNadSupported,
					gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.bNad,
					bFwi,
					bFsdi,
					bFsci);
				PH_BREAK_ON_FAILURE(wtmpStatus);
				wtmpStatus = PHAC_DISCLOOP_DEVICE_ACTIVATED;
			}
			else
			{
				wtmpStatus = PHAC_DISCLOOP_DEVICE_ACTIVATED;
			}
			break;
	}

#endif /* NXPBUILD__PH_NFCLIB_ISO*/
	gbActivateState =   PHNFCLIB_ACTIVE_ST_DONE;
	return wtmpStatus;
}

static FUNC(phStatus_t,ANFCRL_API) phNfcLib_Deactivate_NFC_Profile(VAR(void, AUTOMATIC))
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;

	return wStatus;
}

static FUNC(phStatus_t,ANFCRL_API) phNfcLib_Deactivate_ISO_Profile(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_NFCLIB_STATUS_INTERNAL_ERROR;
#ifdef NXPBUILD__PH_NFCLIB_ISO
	/* build command frame */
	switch (gphNfcLib_State.pPeerInfo->dwActivatedType)
	{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS
	case E_PH_NFCLIB_TYPEA_LAYER3:
		wStatus = phpalI14443p3a_HaltA(&gphNfcLib_Params.spalI14443p3a);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS
	case E_PH_NFCLIB_TYPEB_LAYER3:
		wStatus = phpalI14443p3b_HaltB(&gphNfcLib_Params.spalI14443p3b);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS*/
#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS)
	case E_PH_NFCLIB_TYPEA_LAYER4:
	case E_PH_NFCLIB_TYPEB_LAYER4:
		wStatus = phpalI14443p4_Deselect(
				gphNfcLib_Params.sDiscLoop.pPal14443p4DataParams);
		break;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_FELICA_TAGS
	case E_PH_NFCLIB_FELICA:
		break;
#endif
#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
	case E_PH_NFCLIB_ISO15693:
		wStatus = phpalSli15693_StayQuiet(
				gphNfcLib_Params.sDiscLoop.pPalSli15693DataParams);
		break;
#endif /* NXPBUILD__PH_NFCLIB_ISO_15693*/
	default:
		break;
	}

#endif /* NXPBUILD__PH_NFCLIB_ISO */
	return wStatus;
}

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_NFC_Transmit(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength)
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t, AUTOMATIC) wStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
	PH_UNUSED_VARIABLE(pTxBuffer);
	PH_UNUSED_VARIABLE(wTxBufferLength);
	return wStatus;
}

static FUNC(phStatus_t, ANFCRL_API) phNfcLib_ISO_Transmit(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength)
{
	VAR(phStatus_t, AUTOMATIC) wStatus = PH_NFCLIB_STATUS_INTERNAL_ERROR;
#ifdef NXPBUILD__PH_NFCLIB_ISO
	/* build command frame */
	switch (gphNfcLib_State.pPeerInfo->dwActivatedType)
	{
#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS)
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS
	case E_PH_NFCLIB_TYPEA_LAYER3:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS
	case E_PH_NFCLIB_TYPEB_LAYER3:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS */
		/* Perform raw 14443-3 exchange. Application should provide the frame supported by the card/peer. */
		wStatus = phhalHw_Exchange(gphNfcLib_Params.sDiscLoop.pHalDataParams,
				PH_EXCHANGE_DEFAULT, (uint8_t * )pTxBuffer, wTxBufferLength,
				&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
		break;
#endif

#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS)
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS
	case E_PH_NFCLIB_TYPEA_LAYER4:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS
	case E_PH_NFCLIB_TYPEB_LAYER4:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS*/
		/* Perform raw 14443-4 exchange. Application should frame 7816-4 frames when using Simplified API. */
		wStatus = phpalI14443p4_Exchange(&gphNfcLib_Params.spalI14443p4,
				PH_EXCHANGE_DEFAULT, (uint8_t * )pTxBuffer, wTxBufferLength,
				&gphNfcLib_State.pRxBuffer, &gphNfcLib_State.wRxLength);
		break;
#endif

#ifdef NXPBUILD__PH_NFCLIB_FELICA
		/* Identified cards support Felica Technology */
	case E_PH_NFCLIB_FELICA:
		wStatus =  phNfcLib_Felica_Transmit(pTxBuffer, wTxBufferLength);
		break;
#endif /* NXPBUILD__PH_NFCLIB_FELICA */

#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
		/* Identified cards support ISO 15693 Technology */
	case E_PH_NFCLIB_ISO15693:
		wStatus = phNfcLib_ISO15693_Transmit(pTxBuffer, wTxBufferLength);
		break;
#endif /* NXPBUILD__PH_NFCLIB_ISO_15693 */

	default:
		break;
	}
#endif /* NXPBUILD__PH_NFCLIB_ISO*/
	return wStatus;
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_SetConfig_Value(VAR(uint8_t, AUTOMATIC) bConfigTag, VAR(uint32_t, AUTOMATIC) dwValue)
{
	VAR(phStatus_t, AUTOMATIC) wStatus;
	VAR(phNfcLib_Status_t, AUTOMATIC) dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;

	switch (bConfigTag)
	{
	case PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING:
		if (gphNfcLib_State.bNfcLibState == eNfcLib_InitializedState)
		{
			if ((dwValue == PH_ON) || (dwValue == PH_OFF))
			{
				gphNfcLib_State.bActivateBlocking = (uint8_t) dwValue;
				dwStatus = PH_NFCLIB_STATUS_SUCCESS;
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_ACTIVATION_PROFILE:
		if (gphNfcLib_State.bNfcLibState == eNfcLib_InitializedState)
		{
			if (dwValue <= PH_NFCLIB_ACTIVATION_PROFILE_ISO)
			{
				PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, pConfigProfile[dwValue]());
				gphNfcLib_State.bProfileSelected = (uint8_t) dwValue;
				dwStatus = PH_NFCLIB_STATUS_SUCCESS;
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO:
		if (gphNfcLib_State.bNfcLibState == eNfcLib_InitializedState)
		{
			/* The decision to activate needs to be taken in setconfig also or only at the run time */
			if ((dwValue == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_14443)
					|| (dwValue == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_18092))
			{
				if ((gphNfcLib_State.bProfileSelected
						== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO)
						&& (dwValue
								== PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_18092))
				{
					dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
				}
				else
				{
					gphNfcLib_State.bMergedSakPrio = (uint8_t) dwValue;
					dwStatus = PH_NFCLIB_STATUS_SUCCESS;
				}
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_INITIATOR_ENABLE_LPCD:
		if (gphNfcLib_State.bNfcLibState == eNfcLib_InitializedState)
		{
			if ((dwValue == PH_ON) || (dwValue == PH_OFF))
			{
				if ((gphNfcLib_State.bProfileSelected
						== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO)
						&& (dwValue == PH_ON))
				{
					dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
				}
				else
				{
					gphNfcLib_State.bLPCDState = (uint8_t) dwValue;
					dwStatus = PH_NFCLIB_STATUS_SUCCESS;
				}
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_DEACTIVATION_BLOCKING:
		if (gphNfcLib_State.bNfcLibState != eNfcLib_ResetState)
		{
			if ((dwValue == PH_ON) || (dwValue == PH_OFF))
			{
				gphNfcLib_State.bDeactBlocking = (uint8_t) dwValue;
				dwStatus = PH_NFCLIB_STATUS_SUCCESS;
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}
		}
		break;

	default:
		dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
		break;
	}

	return dwStatus;
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_SetConfig(VAR(uint8_t, AUTOMATIC) bConfigTag,
		P2CONST(uint8_t, AUTOMATIC, ANFCRL_DATA) pConfigParam, VAR(uint16_t, AUTOMATIC) wConfigParamLength)
{
	VAR(phNfcLib_Status_t, AUTOMATIC) dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
	PH_UNUSED_VARIABLE(bConfigTag);
	PH_UNUSED_VARIABLE(pConfigParam);
	PH_UNUSED_VARIABLE(wConfigParamLength);
	return dwStatus;
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_GetConfig(VAR(uint8_t, AUTOMATIC) bConfigTag, P2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pConfigParam,
		P2VAR(uint16_t, AUTOMATIC, ANFCRL_DATA) pConfigParamLength)
{
	VAR(phNfcLib_Status_t, AUTOMATIC) dwStatus = PH_NFCLIB_STATUS_SUCCESS;

	if (gphNfcLib_State.bNfcLibState != eNfcLib_ResetState)
	{
		if ((pConfigParam == NULL) || (pConfigParamLength == NULL))
		{
			return PH_NFCLIB_STATUS_INVALID_PARAMETER;
		}

		switch (bConfigTag)
		{
		case PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING:
			*pConfigParam = gphNfcLib_State.bActivateBlocking;
			*pConfigParamLength = 1;
			break;

		case PH_NFCLIB_CONFIG_ACTIVATION_PROFILE:
			*pConfigParam = gphNfcLib_State.bProfileSelected;
			*pConfigParamLength = 1;
			break;

		case PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO:
			*pConfigParam = gphNfcLib_State.bMergedSakPrio;
			*pConfigParamLength = 1;
			break;

		case PH_NFCLIB_CONFIG_INITIATOR_ENABLE_LPCD:
			*pConfigParam = gphNfcLib_State.bLPCDState;
			*pConfigParamLength = 1;
			break;

		case PH_NFCLIB_CONFIG_DEACTIVATION_BLOCKING:
			*pConfigParam = gphNfcLib_State.bDeactBlocking;
			*pConfigParamLength = 1;
			break;

		default:
			dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			break;
		}
	}
	else
	{
		dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;
	}

	return dwStatus;
}

FUNC(void, ANFCRL_API) phNfcLib_Activate_MainFunction(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;
	switch(gbActivateState)
	{
		case PHNFCLIB_ACTIVE_ST_IDLE:
		case PHNFCLIB_ACTIVE_ST_DONE:
			break;
		case PHNFCLIB_ACTIVATE_ST_START:
		case PHNFCLIB_ACT_ISO_ST_PROCESS:
		case PHNFCLIB_ACT_ISO_ST_ACTIVATED:
			wStatus = pActivate[gphNfcLib_State.bProfileSelected](gphNfcLib_State.wTechnologyMask);
			if(wStatus != PH_STATUS_INPROCESS)
			{
				gbActivateState = PHNFCLIB_ACTIVE_ST_DONE;
				gphNfcLib_State.wBkpStatus = wStatus;
			}
			break;
		case PHNFCLIB_ACT_ISO_ST_RUN:
			/* Start Polling, Function will return once card is activated or any other error has occurred */
			wStatus = phacDiscLoop_Run(&gphNfcLib_Params.sDiscLoop, gphNfcLib_State.bEntryPoint);
			if(wStatus != PH_STATUS_INPROCESS)
			{
				gbActivateState = PHNFCLIB_ACT_ISO_ST_PROCESS;
				gphNfcLib_State.wBkpStatus = wStatus;
			}
			break;
		case PHNFCLIB_ACT_ISO_ST_ACTIVATING:
#if defined(NXPBUILD__PHPAL_I14443P4A_SW) && defined(NXPBUILD__PHPAL_I14443P4_SW)
			wStatus = phpalI14443p4a_ActivateCard(
				gphNfcLib_Params.sDiscLoop.pPal1443p4aDataParams,
				gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.bFsdi,
				gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.bCid,
				gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.bDri,
				gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.bDsi,
				gphNfcLib_Params.sDiscLoop.sTypeATargetInfo.sTypeA_I3P4.pAts);
#endif
			if(wStatus != PH_STATUS_INPROCESS)
			{
#if defined(NXPBUILD__PHPAL_I14443P4A_SW) && defined(NXPBUILD__PHPAL_I14443P4_SW)
				gphNfcLib_State.wBkpStatus = wStatus;
				if(wStatus != PH_ERR_SUCCESS)
				{
					gbActivateState = PHNFCLIB_ACTIVE_ST_DONE;
					break;
				}
#endif
				gbActivateState = PHNFCLIB_ACT_ISO_ST_ACTIVATED;
			}
			break;
	}
}

FUNC (phNfcLib_Status_t, ANFCRL_API) phNfcLib_Activate(
									VAR(uint16_t, ANFCRL_VAR) wTechnologyMask,
									P2VAR(phNfcLib_PeerInfo_t, AUTOMATIC, ANFCRL_VAR) peerInfo,
									VAR(pphNfcLib_ErrCallbck, ANFCRL_VAR)  ErrCallbck
									)
{
	VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;
	VAR(phStatus_t, ANFCRL_VAR)        wStatus  = PH_ERR_SUCCESS;
	VAR(uint16_t, ANFCRL_VAR)          wValue;

switch(gbActivateState)
{
	case PHNFCLIB_ACTIVE_ST_IDLE:
		if (gphNfcLib_State.bNfcLibState == eNfcLib_InitializedState)
		{
			if (peerInfo == NULL)
			{
				return PH_NFCLIB_STATUS_INVALID_PARAMETER;
			}

			/* Assign application callback. */
			gphNfcLib_Params.pNfcLib_ErrCallbck = ErrCallbck;
			gphNfcLib_State.pPeerInfo           = peerInfo;
			gphNfcLib_State.bTxState            = PH_NFCLIB_INT_TRANSMIT_OFF;
			gphNfcLib_State.wTechnologyMask     = wTechnologyMask;
			gbActivateState = PHNFCLIB_ACTIVATE_ST_START;
			return PH_STATUS_INPROCESS;
		}
		break;
	case PHNFCLIB_ACTIVATE_ST_START:
	case PHNFCLIB_ACT_ISO_ST_ACTIVATING:
	case PHNFCLIB_ACT_ISO_ST_ACTIVATED:
	case PHNFCLIB_ACT_ISO_ST_RUN:
	case PHNFCLIB_ACT_ISO_ST_PROCESS:
		break;
	case PHNFCLIB_ACTIVE_ST_DONE:
		wStatus = gphNfcLib_State.wBkpStatus;
		gbActivateState = PHNFCLIB_ACTIVE_ST_IDLE;
		if ((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_DEVICE_ACTIVATED)
		{
			dwStatus = PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE;

			gphNfcLib_State.bNfcLibState = eNfcLib_ActivatedState;
			gphNfcLib_State.wConfiguredRFTech = wTechnologyMask;
		}
		else if (((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_TECH_DETECTED) ||
			((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED))
		{
			dwStatus = PH_NFCLIB_STATUS_NO_PEER_DISCOVERED;
		}
		else if (((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MULTI_TECH_DETECTED) ||
			((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED) ||
			((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_COLLISION_PENDING))
		{
			dwStatus = PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED;

			if (gphNfcLib_State.bProfileSelected == PH_NFCLIB_ACTIVATION_PROFILE_ISO)
			{
				gphNfcLib_State.bNfcLibState = eNfcLib_ActivatedState;
				gphNfcLib_State.wConfiguredRFTech = wTechnologyMask;
			}
		}
		else if ((wStatus & PH_ERR_MASK) == PH_ERR_ABORTED)
		{
			dwStatus = PH_NFCLIB_STATUS_ABORTED;
		}
		else if ((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_FAILURE)
		{
			wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO, &wValue);
			if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
			{
				if ((wValue & PH_ERR_MASK) == PH_ERR_ABORTED)
				{
					dwStatus = PH_NFCLIB_STATUS_ABORTED;
				}
				else if ((wValue & PH_ERR_MASK) == PH_ERR_PROTOCOL_ERROR)
				{
					dwStatus = PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR;
				}
				else if ((wValue & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR)
				{
					dwStatus = PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR;
				}
				else if ((wValue & PH_ERR_MASK) == PH_ERR_COLLISION_ERROR)
				{
					dwStatus = PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED;
				}
				else if ((wStatus & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
				{
					dwStatus = PH_NFCLIB_STATUS_NO_PEER_DISCOVERED;
				}
				else
				{
					dwStatus = PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED;
				}
			}
		}
		else if (wStatus == PH_NFCLIB_STATUS_INVALID_PARAMETER)
		{
			/* TODO: Remove after NFC and ISO profile is implemented. */
			dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
		}
		else if (wStatus == PH_ERR_INVALID_PARAMETER)
		{
			dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
		}
		else
		{
			dwStatus = PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED;
		}
		break;
}

	return dwStatus;
}

FUNC(void, ANFCRL_API) phNfcLib_Transmit_MainFunction(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t, AUTOMATIC) wStatus  = PH_ERR_SUCCESS;

	switch(geTransmitState)
	{
	case PHNFCLIB_TRANSMIT_ST_IDLE:
	case PHNFCLIB_TRANSMIT_ST_DONE:
		break;
	case PHNFCLIB_TRANSMIT_ST_EXCHANGE:
		wStatus = pTransmit[gphNfcLib_State.bProfileSelected](gphNfcLib_State.pTxBuffer, gphNfcLib_State.wTxLength);

		if(wStatus != PH_STATUS_INPROCESS)
		{
			geTransmitState = PHNFCLIB_TRANSMIT_ST_DONE;
			gphNfcLib_State.wBkpStatus = wStatus;
		}
		break;
	}
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_Transmit(
									CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
									VAR(uint16_t, AUTOMATIC) wTxBufferLength
									)
{
	VAR(phNfcLib_Status_t, AUTOMATIC) dwStatus = PH_STATUS_INPROCESS;
	VAR(phStatus_t, AUTOMATIC) wStatus  = PH_ERR_SUCCESS;

	switch(geTransmitState)
	{
	case PHNFCLIB_TRANSMIT_ST_IDLE:
		if ((pTxBuffer == NULL) && (gphNfcLib_State.bTxState != PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING))
		{
			return PH_NFCLIB_STATUS_INVALID_PARAMETER;
		}
		gphNfcLib_State.pRxBuffer   = NULL;
		gphNfcLib_State.wRxLength   = 0x00u;
		gphNfcLib_State.wRxDataPoin = 0x00u;

		if (gphNfcLib_State.bNfcLibState == eNfcLib_ActivatedState)
		{
			gphNfcLib_State.pTxBuffer = pTxBuffer;
			gphNfcLib_State.wTxLength = wTxBufferLength;
			geTransmitState = PHNFCLIB_TRANSMIT_ST_EXCHANGE;
			return PH_STATUS_INPROCESS;
		}
		dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;
		break;

	case PHNFCLIB_TRANSMIT_ST_EXCHANGE:
		break;
	case PHNFCLIB_TRANSMIT_ST_DONE:
		gphNfcLib_State.pTxBuffer = NULL;
		gphNfcLib_State.wTxLength = 0u;
		wStatus = gphNfcLib_State.wBkpStatus;

		if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
		{
			/* Updated the state of Transmit. */
			gphNfcLib_State.bTxState = PH_NFCLIB_INT_TRANSMIT_ON;

			dwStatus = PH_NFCLIB_STATUS_SUCCESS;
		}
		else if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS_CHAINING)
		{
			/* Updated the state of Transmit. */
			gphNfcLib_State.bTxState = PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING;

			/* Return Buffer overflow to user so that Receive has to be called to clear NFCLIB
			 * Rx buffer and the perform Transmit with pTxBuffer parameter as NULL. */
			dwStatus = PH_NFCLIB_STATUS_BUFFER_OVERFLOW;
		}
		else if ((wStatus & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
		{
			dwStatus = PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		else if (((wStatus & PH_ERR_MASK) == PH_ERR_PROTOCOL_ERROR) ||
			((wStatus & PH_ERR_MASK) == PH_ERR_AUTH_ERROR))
		{
			dwStatus = PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		else if ((wStatus & PH_ERR_MASK) == PH_ERR_INTEGRITY_ERROR)
		{
			dwStatus = PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		else if (wStatus == PH_ERR_INVALID_PARAMETER)
		{
			/* TODO: Remove after NFC profile is implemented. */
			dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		else if ((wStatus & PH_ERR_MASK) >= PH_ERR_INTERNAL_ERROR)
		{
			dwStatus = PH_NFCLIB_STATUS_INTERNAL_ERROR;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		else
		{
			dwStatus = PH_NFCLIB_STATUS_RF_PEER_LOST;
			gphNfcLib_State.bTxState    = PH_NFCLIB_INT_TRANSMIT_OFF;
		}
		break;
	}

	geTransmitState = PHNFCLIB_TRANSMIT_ST_IDLE;
	return dwStatus;
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_Receive(CONSTP2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pRxBuffer,
		P2VAR(uint16_t, AUTOMATIC, ANFCRL_DATA) pNumberOfBytes, P2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pMoreDataAvailable)
{
	VAR(phNfcLib_Status_t, AUTOMATIC) dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;

	if ((pRxBuffer == NULL) || (pNumberOfBytes == NULL)
			|| (*pNumberOfBytes == 0U))
	{
		return PH_NFCLIB_STATUS_INVALID_PARAMETER;
	}

	if (gphNfcLib_State.bNfcLibState == eNfcLib_ActivatedState)
	{
		if ((gphNfcLib_State.bProfileSelected
				== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO)
				|| (gphNfcLib_State.bProfileSelected
						== PH_NFCLIB_ACTIVATION_PROFILE_ISO))
		{
			if (gphNfcLib_State.bTxState == PH_NFCLIB_INT_TRANSMIT_OFF)
			{
				return dwStatus;
			}

			if ((gphNfcLib_State.pRxBuffer != NULL)
					&& (gphNfcLib_State.wRxLength > 0U))
			{
				if (gphNfcLib_State.wRxLength <= *pNumberOfBytes)
				{
					if (pMoreDataAvailable != NULL)
					{
						*pMoreDataAvailable = 0;
					}
					*pNumberOfBytes = gphNfcLib_State.wRxLength;
					(void) memcpy((uint8_t*) pRxBuffer,
							&gphNfcLib_State.pRxBuffer[gphNfcLib_State.wRxDataPoin],
							*pNumberOfBytes);
					gphNfcLib_State.wRxDataPoin = 0;
					gphNfcLib_State.wRxLength = 0;

					/* Do not reset the TxState if previous Tx is chaining as this status is checked in Transmit API. */
					if (gphNfcLib_State.bTxState
							!= PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING)
					{
						gphNfcLib_State.bTxState = PH_NFCLIB_INT_TRANSMIT_OFF;
					}
					dwStatus = PH_NFCLIB_STATUS_SUCCESS;
				}
				else
				{
					if (pMoreDataAvailable != NULL)
					{
						*pMoreDataAvailable = 1;
						(void) memcpy((uint8_t*) pRxBuffer,
								&gphNfcLib_State.pRxBuffer[gphNfcLib_State.wRxDataPoin],
								*pNumberOfBytes);
						gphNfcLib_State.wRxDataPoin = *pNumberOfBytes;
						gphNfcLib_State.wRxLength -= *pNumberOfBytes;
						dwStatus = PH_NFCLIB_STATUS_SUCCESS;
					}
					else
					{
						dwStatus = PH_NFCLIB_STATUS_BUFFER_OVERFLOW;
					}
				}
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR;
				if (gphNfcLib_State.bProfileSelected
						== PH_NFCLIB_ACTIVATION_PROFILE_ISO)
				{
					*pNumberOfBytes = gphNfcLib_State.wRxLength;
					dwStatus = PH_NFCLIB_STATUS_SUCCESS;
				}
			}
		}
		else
		{
			/* TODO: Remove after NFC profile is implemented. */
		}
	}
	return dwStatus;
}

FUNC(void, ANFCRL_API) phNfcLib_Deactivate_Mainfunction(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus;

	switch (gbDeactivateState)
	{
	case PHNFCLIB_DEACTIVE_IDLE:
	case PHNFCLIB_DEACTIVE_DONE:
		break;
	case PHNFCLIB_DEACTIVE_FIELDOFF:
		wStatus = phhalHw_FieldOff(&gphNfcLib_Params.sHal);
		if (wStatus == PH_STATUS_INPROCESS)
		{
			break;
		}
		else
		{
			gphNfcLib_State.bNfcLibState = eNfcLib_InitializedState;
			gbDeactivateState = PHNFCLIB_DEACTIVE_WAIT;
		}
		break;
	case PHNFCLIB_DEACTIVE_WAIT:
		wStatus = phhalHw_Wait(&gphNfcLib_Params.sHal,
				PHHAL_HW_TIME_MICROSECONDS, 5100);
		if (wStatus == PH_STATUS_INPROCESS)
		{
			break;
		}
		gbDeactivateState = PHNFCLIB_DEACTIVE_DONE;
		break;
	case PHNFCLIB_DEACTIVE_HALT:
		wStatus = pDeactivate[gphNfcLib_State.bProfileSelected]();
		if (wStatus == PH_STATUS_INPROCESS)
		{
			break;
		}
		gphNfcLib_State.wBkpStatus = wStatus;
		gbDeactivateState = PHNFCLIB_DEACTIVE_DONE;
		break;
	}
}

FUNC(phNfcLib_Status_t, ANFCRL_API) phNfcLib_Deactivate(
	VAR(uint8_t, ANFCRL_VAR) bDeactivateMode,
	P2VAR(phNfcLib_PeerInfo_t, AUTOMATIC, ANFCRL_VAR) peerInfo
	)
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus;
	VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;
	VAR(uint16_t, ANFCRL_VAR) wValue;

	switch(gbDeactivateState)
	{
		case PHNFCLIB_DEACTIVE_IDLE:
			if (bDeactivateMode == PH_NFCLIB_DEACTIVATION_MODE_RF_OFF)
			{
				if (gphNfcLib_State.bNfcLibState != eNfcLib_ResetState)
				{
					gbDeactivateState = PHNFCLIB_DEACTIVE_FIELDOFF;
					return PH_STATUS_INPROCESS;
				}
			}
			else if (bDeactivateMode == PH_NFCLIB_DEACTIVATION_MODE_RELEASE)
			{
				if (gphNfcLib_State.bNfcLibState == eNfcLib_ActivatedState)
				{
					gbDeactivateState = PHNFCLIB_DEACTIVE_HALT;
					return PH_STATUS_INPROCESS;
				}
				else
				{
					return PH_NFCLIB_STATUS_INVALID_STATE;
				}
			}
			else
			{
				dwStatus = PH_NFCLIB_STATUS_INVALID_PARAMETER;
				break;
			}
			/*no break*/
		case PHNFCLIB_DEACTIVE_DONE:
			wStatus = gphNfcLib_State.wBkpStatus;
			if (bDeactivateMode == PH_NFCLIB_DEACTIVATION_MODE_RELEASE)
			{
				if (gphNfcLib_State.bNfcLibState == eNfcLib_ActivatedState)
				{
					if (wStatus == PH_ERR_SUCCESS)
					{
						dwStatus = PH_NFCLIB_STATUS_SUCCESS;

						gphNfcLib_State.bNfcLibState = eNfcLib_InitializedState;
						gphNfcLib_State.wConfiguredRFTech = 0x00;
						gphNfcLib_Params.pNfcLib_ErrCallbck = NULL;
					}
					else if ((wStatus & PH_ERR_MASK) == PHAC_DISCLOOP_FAILURE)
					{
						wStatus = phacDiscLoop_GetConfig(&gphNfcLib_Params.sDiscLoop, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO, &wValue);
						if ((wStatus & PH_ERR_MASK) == PH_ERR_SUCCESS)
						{
							if ((wValue & PH_ERR_MASK) == PH_ERR_ABORTED)
							{
								dwStatus = PH_NFCLIB_STATUS_ABORTED;
							}
							else if ((wValue & PH_ERR_MASK) == PH_ERR_SUCCESS)
							{
								dwStatus = PH_NFCLIB_STATUS_SUCCESS;

								gphNfcLib_State.bNfcLibState = eNfcLib_InitializedState;
								gphNfcLib_State.wConfiguredRFTech = 0x00;
								gphNfcLib_Params.pNfcLib_ErrCallbck = NULL;
							}
							else
							{
								/* Do Nothing */
							}
						}
					}
					else if ((wStatus & PH_ERR_MASK) == PH_ERR_ABORTED)
					{
						dwStatus = PH_NFCLIB_STATUS_ABORTED;
					}
					else
					{
						dwStatus = PH_NFCLIB_STATUS_PEER_DEACTIVATION_FAILED;
					}
		#ifdef NXPBUILD__PHPAL_I14443P4_SW
					/* Irrespective of Profile selected, PAL 14443-4 layer needs to be reset. */
					(void)phpalI14443p4_ResetProtocol(&gphNfcLib_Params.spalI14443p4);
		#endif /* NXPBUILD__PHPAL_I14443P4_SW*/
					break;
				}
			}
			dwStatus = PH_NFCLIB_STATUS_SUCCESS;
			break;

		case PHNFCLIB_DEACTIVE_FIELDOFF:
		case PHNFCLIB_DEACTIVE_WAIT:
		case PHNFCLIB_DEACTIVE_HALT:
			return PH_STATUS_INPROCESS;
	}
	gbDeactivateState = PHNFCLIB_DEACTIVE_IDLE;
	PH_UNUSED_VARIABLE(peerInfo);
	return dwStatus;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB_PROFILES */

#ifdef __cplusplus
}
#endif
