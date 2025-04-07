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
*   @file    phNfcLib2.c
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
#ifdef NXPBUILD__PHNFCLIB_PROFILES2
#include <ph_Status2.h>
#include "phNfcLib_Initialization2.h"
#include "phNfcLib_Int2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib2.h header file are of the same vendor */
#if (PHNFCLIB_VENDOR_ID_C2 != PHNFCLIB_VENDOR_ID2)
    #error "phNfcLib2.c and phNfcLib2.h have different vendor ids"
#endif
/* Check if current file and phNfcLib2.h header file are of the same Autosar version */
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2    != PHNFCLIB_AR_RELEASE_MAJOR_VERSION2) || \
     (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2    != PHNFCLIB_AR_RELEASE_MINOR_VERSION2) || \
     (PHNFCLIB_AR_RELEASE_REVISION_VERSION_C2 != PHNFCLIB_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phNfcLib2.c and phNfcLib2.h are different"
#endif
/* Check if current file and phNfcLib2.h header file are of the same Software version */
#if ((PHNFCLIB_SW_MAJOR_VERSION_C2 != PHNFCLIB_SW_MAJOR_VERSION2) || \
     (PHNFCLIB_SW_MINOR_VERSION_C2 != PHNFCLIB_SW_MINOR_VERSION2) || \
     (PHNFCLIB_SW_PATCH_VERSION_C2 != PHNFCLIB_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phNfcLib2.c and phNfcLib2.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB_PROFILES2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB_PROFILES2
typedef enum{
	PHNFCLIB_TRANSMIT_ST_IDLE2 = 0,
	PHNFCLIB_TRANSMIT_ST_EXCHANGE2,
	PHNFCLIB_TRANSMIT_ST_DONE2
} phNfclib_TransmitState_t2;

typedef enum
{
	PHNFCLIB_DEACTIVE_IDLE2 = 0,
	PHNFCLIB_DEACTIVE_DONE2,
	PHNFCLIB_DEACTIVE_FIELDOFF2,
	PHNFCLIB_DEACTIVE_WAIT2,
	PHNFCLIB_DEACTIVE_HALT2
} phNfclib_DeactivateState_t2;

typedef enum{
	PHNFCLIB_ACTIVE_ST_IDLE2 = 0,
	PHNFCLIB_ACTIVATE_ST_START2,
	PHNFCLIB_ACTIVE_ST_DONE2,
	PHNFCLIB_ACT_ISO_ST_RUN2,
	PHNFCLIB_ACT_ISO_ST_PROCESS2,
	PHNFCLIB_ACT_ISO_ST_ACTIVATING2,
	PHNFCLIB_ACT_ISO_ST_ACTIVATED2
} phNfclib_ActivateState_t2;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static CONST(pphNfcLib_Config_Profile2, AUTOMATIC) pConfigProfile2[] =
{ &phNfcLib_Config_NFC_Profile2, &phNfcLib_Config_ISO_Profile2 };

static CONST(pphNfcLib_Activate_Profile2, AUTOMATIC) pActivate2[] =
{ &phNfcLib_Activate_NFC_Profile2, &phNfcLib_Activate_ISO_Profile2 };

static CONST(pphNfcLib_Deactivate_Profile2, AUTOMATIC) pDeactivate2[] =
{ &phNfcLib_Deactivate_NFC_Profile2, &phNfcLib_Deactivate_ISO_Profile2 };

static CONST(pphNfcLib_Transmit2, AUTOMATIC) pTransmit2[] =
{ &phNfcLib_NFC_Transmit2, &phNfcLib_ISO_Transmit2 };

#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static VAR(phNfclib_TransmitState_t2, AUTOMATIC) geTransmitState2 = PHNFCLIB_TRANSMIT_ST_IDLE2;
static VAR(phNfclib_DeactivateState_t2, ANFCRL_VAR) gbDeactivateState2 =
		PHNFCLIB_DEACTIVE_IDLE2;
static VAR(phNfclib_ActivateState_t2, ANFCRL_VAR) gbActivateState2 = PHNFCLIB_ACTIVE_ST_IDLE2;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Config_NFC_Profile2(VAR(void, AUTOMATIC));
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Config_ISO_Profile2(VAR(void, AUTOMATIC));

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Activate_NFC_Profile2(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask2);
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Activate_ISO_Profile2(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask2);

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Deactivate_NFC_Profile2(VAR(void, AUTOMATIC));
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Deactivate_ISO_Profile2(VAR(void, AUTOMATIC));

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_NFC_Transmit2(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer2,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength2);
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_ISO_Transmit2(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA) pTxBuffer2,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength2);

#ifdef NXPBUILD__PH_NFCLIB_ISO2
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Configure_DiscLoop_ISO2(VAR(uint16_t, AUTOMATIC) wTechnologyMask2);
#endif /* NXPBUILD__PH_NFCLIB_ISO2*/

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Config_NFC_Profile2(VAR(void, AUTOMATIC))
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t2, AUTOMATIC) wStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;

	return wStatus2;
}
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Config_ISO_Profile2(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t2, AUTOMATIC) wStatus2 = PH_ERR_SUCCESS2;
#ifdef  NXPBUILD__PH_NFCLIB_ISO2

	/* TODO: Set the LPCD state to Zero in ISO mode. */
	gphNfcLib_State2.bLPCDState2 = 1;

	/* Enable Bail-out config in ISO mode. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_BAIL_OUT2, 0x13 ));

	/* Enable LPCD feature. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ENABLE_LPCD2, PH_OFF2 ));

	/* reset collision Pending */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2, PH_OFF2 ));

	/* whether anti-collision is supported or not. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ANTI_COLL2, PH_ON2 ));

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
	/* Passive CON_DEVICE limit. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2, 1 ));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2, 1 ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2, PH_NFCLIB_MAX_ISO15693_TAGS_SUPPORTED2 ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
	/* Passive polling Tx Guard times in micro seconds. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2, PH_NXPNFCRDLIB_CONFIG_TYPEA_GT2 ));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2, PH_NXPNFCRDLIB_CONFIG_TYPEB_GT2 ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2*/

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2, 5200 ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW2*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
	/* Configure FSDI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI2, 0x08 ));

	/* Configure CID for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID2, 0x00 ));

	/* Configure DRI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI2, 0x00 ));

	/* Configure DSI for the 14443P4A tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI2, 0x00 ));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
	/* Configure AFI for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_AFI_REQ2, 0x00 ));

	/* Configure FSDI for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_FSDI2, 0x08 ));

	/* Configure CID for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_CID2, 0x00 ));

	/* Configure DRI for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_DRI2, 0x00 ));

	/* Configure DSI for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_DSI2, 0x00 ));

	/* Configure Extended ATQB support for the type B tags */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEB_EXTATQB2, 0x00 ));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2*/

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	/* Configure ISO 15693 for high/low RX data rate */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE2, 0x000D ));
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

	/* Configure reader library mode */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_OPE_MODE2, RD_LIB_MODE_ISO2 ));

#endif /* NXPBUILD__PH_NFCLIB_ISO2*/
	return wStatus2;
}

#ifdef NXPBUILD__PH_NFCLIB_ISO2
static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_Configure_DiscLoop_ISO2(VAR(uint16_t, AUTOMATIC) wTechnologyMask2)
{
	VAR(phStatus_t2, AUTOMATIC) wStatus2 = PH_ERR_SUCCESS2;

	if ((0U != (wTechnologyMask2 & PH_NFCLIB_TECHNOLOGY_INITIATOR_FELICA2))
			|| (0U != ((wTechnologyMask2 & PH_NFCLIB_TECHNOLOGY_TARGET_FELICA2))))
	{
		return PH_ERR_INVALID_PARAMETER2;
	}

	/*  Passive Listen bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2, 0x00 ));

	/*  Active Listen bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2, 0x00 ));

	/* TODO: to be changed if technology mask bit value for active changes */
	/* Active poll bit map config. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2, (((wTechnologyMask2 & 0x0020U) != 0U) ? 0x0007U : 0x0U) ));

	/* TODO: to be changed if technology mask bit value for felica changes */
	wTechnologyMask2 = (wTechnologyMask2 & 0x0007U)
			| ((wTechnologyMask2 << 1U) & 0x0030U);

	/* Passive poll bitmap config in ISO mode. */
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2, (wTechnologyMask2 & 0x0033U) ));

	/* Poll Mode default state*/
	PH_CHECK_SUCCESS_FCT2(wStatus2,
			phacDiscLoop_SetConfig2( &gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2, (uint16_t)PHAC_DISCLOOP_POLL_STATE_DETECTION2 ));

	return wStatus2;
}
#endif /* NXPBUILD__PH_NFCLIB_ISO2*/

static FUNC(phStatus_t2,ANFCRL_API) phNfcLib_Activate_NFC_Profile2(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask2)
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
	PH_UNUSED_VARIABLE2(wTechnologyMask2);
	gbActivateState2 = PHNFCLIB_ACTIVE_ST_DONE2;
	return wStatus2;
}

static FUNC(phStatus_t2,ANFCRL_API) phNfcLib_Activate_ISO_Profile2(VAR(uint16_t, ANFCRL_VAR) wTechnologyMask2)
{
	VAR(phStatus_t2, ANFCRL_VAR) wtmpStatus2 = PH_ERR_INTERNAL_ERROR2;
#ifdef NXPBUILD__PH_NFCLIB_ISO2
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2    = PH_ERR_SUCCESS2;
	VAR(uint16_t, ANFCRL_VAR)   wValue2;
	VAR(uint16_t, ANFCRL_VAR) wTagsDetected2 = 0;
	VAR(uint16_t, ANFCRL_VAR) wGtLength2 = 0;
#if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
	VAR(uint8_t, ANFCRL_VAR) bCidEnabled2 = 0;
	VAR(uint8_t, ANFCRL_VAR) bCid2 = 0;
	VAR(uint8_t, ANFCRL_VAR) bNadSupported2 = 0;
	VAR(uint8_t, ANFCRL_VAR) bFwi2 = 0;
	VAR(uint8_t, ANFCRL_VAR) bFsdi2 = 0;
	VAR(uint8_t, ANFCRL_VAR) bFsci2 = 0;
#endif
#if defined(NXPBUILD__PH_NFCLIB_ISO_156932)
	VAR(uint8_t, ANFCRL_VAR) bIndex2 = 0;
#endif
	VAR(uint32_t, ANFCRL_VAR) sak_atqa2 = 0;

	switch(gbActivateState2)
	{
		case PHNFCLIB_ACTIVE_ST_IDLE2:
		case PHNFCLIB_ACTIVE_ST_DONE2:
			break;
		case PHNFCLIB_ACTIVATE_ST_START2:
			/* Set the LPCD state to one in ISO  mode. */
			gphNfcLib_State2.bLPCDState2 = 1;

			wStatus2 = phNfcLib_Configure_DiscLoop_ISO2(wTechnologyMask2);
			if(wStatus2 != PH_ERR_SUCCESS2)
			{
				wtmpStatus2 = wStatus2;
				break;
			}

			/* For ISO mode the starting mode is poll */
			/* TODO if technology mask says no poll then entry point has to be only listen and vice versa */
			gphNfcLib_State2.bEntryPoint2 = (uint8_t)PHAC_DISCLOOP_ENTRY_POINT_POLL2;

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
			/* Assign ATS buffer for Type A */
			gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.pAts2 = gphNfcLib_State2.pPeerInfo2->uRi2.uInitiator2.tIso14443_42.aAts2;
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2*/
			gbActivateState2 = PHNFCLIB_ACT_ISO_ST_RUN2;
			return PH_STATUS_INPROCESS2;

		case PHNFCLIB_ACT_ISO_ST_RUN2:
		case PHNFCLIB_ACT_ISO_ST_ACTIVATING2:
			return PH_STATUS_INPROCESS2;

		case PHNFCLIB_ACT_ISO_ST_PROCESS2:
			/*restore status of Discovery Loop Run*/
			wtmpStatus2 = gphNfcLib_State2.wBkpStatus2;
			/* Reset Activated tag/peer type. */
			gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_UNKNOWN2;

			if (((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_TECH_DETECTED2) ||
				((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED2) ||
				((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_EXTERNAL_RFON2))
			{
				/* In ISO mode, Target mode is not supported. */
			}
			else if(((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2)
				||((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED2)
				||((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2))
			{
				if ((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2)
				{
					if(gphNfcLib_State2.bMergedSakPrio2 == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432)
					{
	#if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
						gbActivateState2 = PHNFCLIB_ACT_ISO_ST_ACTIVATING2;
						return PH_STATUS_INPROCESS2;
	#endif
					}
					else
					{
					}
				}
				else
				{
					/* Get detected technology type */
					wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
					if(wStatus2 != PH_ERR_SUCCESS2)
					{
						wtmpStatus2 = wStatus2;
						break;
					}
					else
					{
						/*TODO: nothing */
					}
				}
			}
			else if((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_DEVICE_ACTIVATED2)
			{
				/* Get detected technology type */
				wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
				if(wStatus2 != PH_ERR_SUCCESS2)
				{
					wtmpStatus2 = wStatus2;
					break;
				}
	#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
				if(PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_A2))
				{
					gphNfcLib_State2.pPeerInfo2->uTi2.uInitiator2.tIso14443_3a2.bUidLength2 = gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].bUidSize2;
					(void)memcpy(&gphNfcLib_State2.pPeerInfo2->uTi2.uInitiator2.tIso14443_3a2.aUid2[0], &gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].aUid2[0] ,gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].bUidSize2);

					sak_atqa2 = (uint32_t)((((uint32_t)(gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].aSak2)) << 16U) |
						(gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].aAtqa2[0] << 8U) |
						(gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].aAtqa2[1]));

					switch (sak_atqa2 & 0x00FF0FFFU)
					{
					case PH_NFCLIB_SAK_MFC_1K2 << 16U | PH_NFCLIB_ATQA_MFP_S2:
						gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_MIFARE_CLASSIC_1K2;
						break;
					case PH_NFCLIB_SAK_MFC_4K2 << 16U | PH_NFCLIB_ATQA_MFC2:
						gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_MIFARE_CLASSIC_4K2;
						break;
					default:
						break;
					}

					if ((gphNfcLib_State2.pPeerInfo2->dwActivatedType2) == E_PH_NFCLIB_UNKNOWN2)
					{
						switch (sak_atqa2)
						{
						case PH_NFCLIB_SAK_UL2 << 16U | PH_NFCLIB_ATQA_UL2:
							gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_MIFARE_ULTRALIGHT2;
							break;
						case PH_NFCLIB_SAK_LAYER42 << 16U | PH_NFCLIB_ATQA_DESFIRE2:
							gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_MIFARE_DESFIRE2;
							break;
						case PH_NFCLIB_SAK_LAYER42 << 16U | PH_NFCLIB_ATQA_DESFIRE12:
							gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_MIFARE_DESFIRE2;
							break;
						default:
							break;
						}
					}
					if (gphNfcLib_State2.pPeerInfo2->dwActivatedType2 == E_PH_NFCLIB_UNKNOWN2)
					{
						if(gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.aTypeA_I3P32[0].aSak2 == PH_NFCLIB_SAK_LAYER42)
						{
							gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_TYPEA_LAYER42;
						}
						else
						{
							gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_TYPEA_LAYER32;
						}
					}
					break;

				}
	#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */
	#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
				if(PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_B2))
				{
					wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2,
						PHAC_DISCLOOP_CONFIG_TYPEB_SUPPORT_TYPE4B2,
						&wValue2);
					if(wStatus2 != PH_ERR_SUCCESS2)
					{
						wtmpStatus2 = wStatus2;
						break;
					}
					if (wValue2 == PH_OFF2)
					{
						gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_TYPEB_LAYER32;
					}
					else
					{
						gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_TYPEB_LAYER42;
					}
					break;
				}
	#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */
	#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
				if(PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_V2))
				{
					gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_ISO156932;
					gphNfcLib_State2.pPeerInfo2->uTi2.uInitiator2.tIso156932.TagIndex2[0].pUid2 = &gphNfcLib_Params2.sDiscLoop2.sTypeVTargetInfo2.aTypeV2[0].aUid2[0];
					gphNfcLib_State2.pActivatedUid2 = &gphNfcLib_Params2.sDiscLoop2.sTypeVTargetInfo2.aTypeV2[0].aUid2[0];
					gphNfcLib_State2.wActivatedUIDLength2 = 8;
					break;
				}
	#endif /* NXPBUILD__PH_NFCLIB_ISO_156932 */

			}

			else if((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2)
			{
				/* Get detected technology type */
				wStatus2 =  phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);
				if(wStatus2 != PH_ERR_SUCCESS2)
				{
					wtmpStatus2 = wStatus2;
					break;
				}
	#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
				if(PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, PHAC_DISCLOOP_POS_BIT_MASK_V2))
				{
					gphNfcLib_State2.pPeerInfo2->uTi2.uInitiator2.tIso156932.bTotalTagsFound2 = gphNfcLib_Params2.sDiscLoop2.sTypeVTargetInfo2.bTotalTagsFound2;
					for(bIndex2 =0; bIndex2 < gphNfcLib_Params2.sDiscLoop2.sTypeVTargetInfo2.bTotalTagsFound2; bIndex2++)
					{
						gphNfcLib_State2.pPeerInfo2->uTi2.uInitiator2.tIso156932.TagIndex2[bIndex2].pUid2 = &gphNfcLib_Params2.sDiscLoop2.sTypeVTargetInfo2.aTypeV2[bIndex2].aUid2[0];
					}
					gphNfcLib_State2.pPeerInfo2->dwActivatedType2 = E_PH_NFCLIB_ISO156932;
					break;
				}
	#endif /* NXPBUILD__PH_NFCLIB_ISO_156932 */

			}
			else
			{
				if((wtmpStatus2 & PH_ERR_MASK2) != PHAC_DISCLOOP_NO_TECH_DETECTED2)
				{
					if ((wtmpStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_FAILURE2)
					{
						wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2, &wValue2);
						if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
						{
							if ((wValue2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
							{
								break;
							}
						}
					}
				}
			}
			break;

		case PHNFCLIB_ACT_ISO_ST_ACTIVATED2:
			if(gphNfcLib_State2.bMergedSakPrio2 == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432)
			{
				 /* Retrieve 14443-4A protocol parameter */
				wtmpStatus2 = phpalI14443p4a_GetProtocolParams2(
					gphNfcLib_Params2.sDiscLoop2.pPal1443p4aDataParams2,
					&bCidEnabled2,
					&bCid2,
					&bNadSupported2,
					&bFwi2,
					&bFsdi2,
					&bFsci2);
				PH_BREAK_ON_FAILURE2(wtmpStatus2);

				/* Set 14443-4 protocol parameter */
				wtmpStatus2 = phpalI14443p4_SetProtocol2(
					gphNfcLib_Params2.sDiscLoop2.pPal14443p4DataParams2,
					bCidEnabled2,
					bCid2,
					bNadSupported2,
					gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.bNad2,
					bFwi2,
					bFsdi2,
					bFsci2);
				PH_BREAK_ON_FAILURE2(wtmpStatus2);
				wtmpStatus2 = PHAC_DISCLOOP_DEVICE_ACTIVATED2;
			}
			else
			{
				wtmpStatus2 = PHAC_DISCLOOP_DEVICE_ACTIVATED2;
			}
			break;
	}

#endif /* NXPBUILD__PH_NFCLIB_ISO2*/
	gbActivateState2 =   PHNFCLIB_ACTIVE_ST_DONE2;
	return wtmpStatus2;
}

static FUNC(phStatus_t2,ANFCRL_API) phNfcLib_Deactivate_NFC_Profile2(VAR(void, AUTOMATIC))
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;

	return wStatus2;
}

static FUNC(phStatus_t2,ANFCRL_API) phNfcLib_Deactivate_ISO_Profile2(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_NFCLIB_STATUS_INTERNAL_ERROR2;
#ifdef NXPBUILD__PH_NFCLIB_ISO2
	/* build command frame */
	switch (gphNfcLib_State2.pPeerInfo2->dwActivatedType2)
	{
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2
	case E_PH_NFCLIB_TYPEA_LAYER32:
		wStatus2 = phpalI14443p3a_HaltA2(&gphNfcLib_Params2.spalI14443p3a2);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2 */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2
	case E_PH_NFCLIB_TYPEB_LAYER32:
		wStatus2 = phpalI14443p3b_HaltB2(&gphNfcLib_Params2.spalI14443p3b2);
		break;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2*/
#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2)
	case E_PH_NFCLIB_TYPEA_LAYER42:
	case E_PH_NFCLIB_TYPEB_LAYER42:
		wStatus2 = phpalI14443p4_Deselect2(
				gphNfcLib_Params2.sDiscLoop2.pPal14443p4DataParams2);
		break;
#endif
#ifdef NXPBUILD__PHAC_DISCLOOP_FELICA_TAGS2
	case E_PH_NFCLIB_FELICA2:
		break;
#endif
#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
	case E_PH_NFCLIB_ISO156932:
		wStatus2 = phpalSli15693_StayQuiet2(
				gphNfcLib_Params2.sDiscLoop2.pPalSli15693DataParams2);
		break;
#endif /* NXPBUILD__PH_NFCLIB_ISO_156932*/
	default:
		break;
	}

#endif /* NXPBUILD__PH_NFCLIB_ISO2 */
	return wStatus2;
}

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_NFC_Transmit2(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer2,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength2)
{
	/* TODO : NFC Profile coding is yet to be done. */
	VAR(phStatus_t2, AUTOMATIC) wStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
	PH_UNUSED_VARIABLE2(pTxBuffer2);
	PH_UNUSED_VARIABLE2(wTxBufferLength2);
	return wStatus2;
}

static FUNC(phStatus_t2, ANFCRL_API) phNfcLib_ISO_Transmit2(CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer2,
		VAR(uint16_t, AUTOMATIC) wTxBufferLength2)
{
	VAR(phStatus_t2, AUTOMATIC) wStatus2 = PH_NFCLIB_STATUS_INTERNAL_ERROR2;
#ifdef NXPBUILD__PH_NFCLIB_ISO2
	/* build command frame */
	switch (gphNfcLib_State2.pPeerInfo2->dwActivatedType2)
	{
#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2 || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2)
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2
	case E_PH_NFCLIB_TYPEA_LAYER32:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2 */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2
	case E_PH_NFCLIB_TYPEB_LAYER32:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2 */
		/* Perform raw 14443-3 exchange. Application should provide the frame supported by the card/peer. */
		wStatus2 = phhalHw_Exchange(gphNfcLib_Params2.sDiscLoop2.pHalDataParams2,
				PH_EXCHANGE_DEFAULT2, (uint8_t * )pTxBuffer2, wTxBufferLength2,
				&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
		break;
#endif

#if (defined NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 || defined NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2)
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
	case E_PH_NFCLIB_TYPEA_LAYER42:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2
	case E_PH_NFCLIB_TYPEB_LAYER42:
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2*/
		/* Perform raw 14443-4 exchange. Application should frame 7816-4 frames when using Simplified API. */
		wStatus2 = phpalI14443p4_Exchange2(&gphNfcLib_Params2.spalI14443p42,
				PH_EXCHANGE_DEFAULT2, (uint8_t * )pTxBuffer2, wTxBufferLength2,
				&gphNfcLib_State2.pRxBuffer2, &gphNfcLib_State2.wRxLength2);
		break;
#endif

#ifdef NXPBUILD__PH_NFCLIB_FELICA2
		/* Identified cards support Felica Technology */
	case E_PH_NFCLIB_FELICA2:
		wStatus2 =  phNfcLib_Felica_Transmit2(pTxBuffer2, wTxBufferLength2);
		break;
#endif /* NXPBUILD__PH_NFCLIB_FELICA2 */

#ifdef NXPBUILD__PH_NFCLIB_ISO_156932
		/* Identified cards support ISO 15693 Technology */
	case E_PH_NFCLIB_ISO156932:
		wStatus2 = phNfcLib_ISO15693_Transmit2(pTxBuffer2, wTxBufferLength2);
		break;
#endif /* NXPBUILD__PH_NFCLIB_ISO_156932 */

	default:
		break;
	}
#endif /* NXPBUILD__PH_NFCLIB_ISO2*/
	return wStatus2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_SetConfig_Value2(VAR(uint8_t, AUTOMATIC) bConfigTag2, VAR(uint32_t, AUTOMATIC) dwValue2)
{
	VAR(phStatus_t2, AUTOMATIC) wStatus2;
	VAR(phNfcLib_Status_t2, AUTOMATIC) dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;

	switch (bConfigTag2)
	{
	case PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING2:
		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_InitializedState2)
		{
			if ((dwValue2 == PH_ON2) || (dwValue2 == PH_OFF2))
			{
				gphNfcLib_State2.bActivateBlocking2 = (uint8_t) dwValue2;
				dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2:
		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_InitializedState2)
		{
			if (dwValue2 <= PH_NFCLIB_ACTIVATION_PROFILE_ISO2)
			{
				PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, pConfigProfile2[dwValue2]());
				gphNfcLib_State2.bProfileSelected2 = (uint8_t) dwValue2;
				dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO2:
		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_InitializedState2)
		{
			/* The decision to activate needs to be taken in setconfig also or only at the run time */
			if ((dwValue2 == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432)
					|| (dwValue2 == PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_180922))
			{
				if ((gphNfcLib_State2.bProfileSelected2
						== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2)
						&& (dwValue2
								== PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_180922))
				{
					dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
				}
				else
				{
					gphNfcLib_State2.bMergedSakPrio2 = (uint8_t) dwValue2;
					dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
				}
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_INITIATOR_ENABLE_LPCD2:
		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_InitializedState2)
		{
			if ((dwValue2 == PH_ON2) || (dwValue2 == PH_OFF2))
			{
				if ((gphNfcLib_State2.bProfileSelected2
						== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2)
						&& (dwValue2 == PH_ON2))
				{
					dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
				}
				else
				{
					gphNfcLib_State2.bLPCDState2 = (uint8_t) dwValue2;
					dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
				}
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}
		}
		break;

	case PH_NFCLIB_CONFIG_DEACTIVATION_BLOCKING2:
		if (gphNfcLib_State2.bNfcLibState2 != eNfcLib_ResetState2)
		{
			if ((dwValue2 == PH_ON2) || (dwValue2 == PH_OFF2))
			{
				gphNfcLib_State2.bDeactBlocking2 = (uint8_t) dwValue2;
				dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}
		}
		break;

	default:
		dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
		break;
	}

	return dwStatus2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_SetConfig2(VAR(uint8_t, AUTOMATIC) bConfigTag2,
		P2CONST(uint8_t, AUTOMATIC, ANFCRL_DATA) pConfigParam2, VAR(uint16_t, AUTOMATIC) wConfigParamLength2)
{
	VAR(phNfcLib_Status_t2, AUTOMATIC) dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
	PH_UNUSED_VARIABLE2(bConfigTag2);
	PH_UNUSED_VARIABLE2(pConfigParam2);
	PH_UNUSED_VARIABLE2(wConfigParamLength2);
	return dwStatus2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_GetConfig2(VAR(uint8_t, AUTOMATIC) bConfigTag2, P2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pConfigParam2,
		P2VAR(uint16_t, AUTOMATIC, ANFCRL_DATA) pConfigParamLength2)
{
	VAR(phNfcLib_Status_t2, AUTOMATIC) dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;

	if (gphNfcLib_State2.bNfcLibState2 != eNfcLib_ResetState2)
	{
		if ((pConfigParam2 == NULL) || (pConfigParamLength2 == NULL))
		{
			return PH_NFCLIB_STATUS_INVALID_PARAMETER2;
		}

		switch (bConfigTag2)
		{
		case PH_NFCLIB_CONFIG_ACTIVATION_BLOCKING2:
			*pConfigParam2 = gphNfcLib_State2.bActivateBlocking2;
			*pConfigParamLength2 = 1;
			break;

		case PH_NFCLIB_CONFIG_ACTIVATION_PROFILE2:
			*pConfigParam2 = gphNfcLib_State2.bProfileSelected2;
			*pConfigParamLength2 = 1;
			break;

		case PH_NFCLIB_CONFIG_ACTIVATION_MERGED_SAK_PRIO2:
			*pConfigParam2 = gphNfcLib_State2.bMergedSakPrio2;
			*pConfigParamLength2 = 1;
			break;

		case PH_NFCLIB_CONFIG_INITIATOR_ENABLE_LPCD2:
			*pConfigParam2 = gphNfcLib_State2.bLPCDState2;
			*pConfigParamLength2 = 1;
			break;

		case PH_NFCLIB_CONFIG_DEACTIVATION_BLOCKING2:
			*pConfigParam2 = gphNfcLib_State2.bDeactBlocking2;
			*pConfigParamLength2 = 1;
			break;

		default:
			dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			break;
		}
	}
	else
	{
		dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;
	}

	return dwStatus2;
}

FUNC(void, ANFCRL_API) phNfcLib_Activate_MainFunction2(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;
	switch(gbActivateState2)
	{
		case PHNFCLIB_ACTIVE_ST_IDLE2:
		case PHNFCLIB_ACTIVE_ST_DONE2:
			break;
		case PHNFCLIB_ACTIVATE_ST_START2:
		case PHNFCLIB_ACT_ISO_ST_PROCESS2:
		case PHNFCLIB_ACT_ISO_ST_ACTIVATED2:
			wStatus2 = pActivate2[gphNfcLib_State2.bProfileSelected2](gphNfcLib_State2.wTechnologyMask2);
			if(wStatus2 != PH_STATUS_INPROCESS2)
			{
				gbActivateState2 = PHNFCLIB_ACTIVE_ST_DONE2;
				gphNfcLib_State2.wBkpStatus2 = wStatus2;
			}
			break;
		case PHNFCLIB_ACT_ISO_ST_RUN2:
			/* Start Polling, Function will return once card is activated or any other error has occurred */
			wStatus2 = phacDiscLoop_Run2(&gphNfcLib_Params2.sDiscLoop2, gphNfcLib_State2.bEntryPoint2);
			if(wStatus2 != PH_STATUS_INPROCESS2)
			{
				gbActivateState2 = PHNFCLIB_ACT_ISO_ST_PROCESS2;
				gphNfcLib_State2.wBkpStatus2 = wStatus2;
			}
			break;
		case PHNFCLIB_ACT_ISO_ST_ACTIVATING2:
#if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
			wStatus2 = phpalI14443p4a_ActivateCard(
				gphNfcLib_Params2.sDiscLoop2.pPal1443p4aDataParams2,
				gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.bFsdi2,
				gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.bCid2,
				gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.bDri2,
				gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.bDsi2,
				gphNfcLib_Params2.sDiscLoop2.sTypeATargetInfo2.sTypeA_I3P42.pAts2);
#endif
			if(wStatus2 != PH_STATUS_INPROCESS2)
			{
#if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
				gphNfcLib_State2.wBkpStatus2 = wStatus2;
				if(wStatus2 != PH_ERR_SUCCESS2)
				{
					gbActivateState2 = PHNFCLIB_ACTIVE_ST_DONE2;
					break;
				}
#endif
				gbActivateState2 = PHNFCLIB_ACT_ISO_ST_ACTIVATED2;
			}
			break;
	}
}

FUNC (phNfcLib_Status_t2, ANFCRL_API) phNfcLib_Activate2(
									VAR(uint16_t, ANFCRL_VAR) wTechnologyMask2,
									P2VAR(phNfcLib_PeerInfo_t, AUTOMATIC, ANFCRL_VAR) peerInfo2,
									VAR(pphNfcLib_ErrCallbck, ANFCRL_VAR)  ErrCallbck2
									)
{
	VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;
	VAR(phStatus_t2, ANFCRL_VAR)        wStatus2  = PH_ERR_SUCCESS2;
	VAR(uint16_t, ANFCRL_VAR)          wValue2;

switch(gbActivateState2)
{
	case PHNFCLIB_ACTIVE_ST_IDLE2:
		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_InitializedState2)
		{
			if (peerInfo2 == NULL)
			{
				return PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			}

			/* Assign application callback. */
			gphNfcLib_Params2.pNfcLib_ErrCallbck2 = ErrCallbck2;
			gphNfcLib_State2.pPeerInfo2           = peerInfo2;
			gphNfcLib_State2.bTxState2            = PH_NFCLIB_INT_TRANSMIT_OFF2;
			gphNfcLib_State2.wTechnologyMask2     = wTechnologyMask2;
			gbActivateState2 = PHNFCLIB_ACTIVATE_ST_START2;
			return PH_STATUS_INPROCESS2;
		}
		break;
	case PHNFCLIB_ACTIVATE_ST_START2:
	case PHNFCLIB_ACT_ISO_ST_ACTIVATING2:
	case PHNFCLIB_ACT_ISO_ST_ACTIVATED2:
	case PHNFCLIB_ACT_ISO_ST_RUN2:
	case PHNFCLIB_ACT_ISO_ST_PROCESS2:
		break;
	case PHNFCLIB_ACTIVE_ST_DONE2:
		wStatus2 = gphNfcLib_State2.wBkpStatus2;
		gbActivateState2 = PHNFCLIB_ACTIVE_ST_IDLE2;
		if ((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_DEVICE_ACTIVATED2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_PEER_ACTIVATION_DONE2;

			gphNfcLib_State2.bNfcLibState2 = eNfcLib_ActivatedState2;
			gphNfcLib_State2.wConfiguredRFTech2 = wTechnologyMask2;
		}
		else if (((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_TECH_DETECTED2) ||
			((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_NO_DEVICE_RESOLVED2))
		{
			dwStatus2 = PH_NFCLIB_STATUS_NO_PEER_DISCOVERED2;
		}
		else if (((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MULTI_TECH_DETECTED2) ||
			((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2) ||
			((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_COLLISION_PENDING2))
		{
			dwStatus2 = PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2;

			if (gphNfcLib_State2.bProfileSelected2 == PH_NFCLIB_ACTIVATION_PROFILE_ISO2)
			{
				gphNfcLib_State2.bNfcLibState2 = eNfcLib_ActivatedState2;
				gphNfcLib_State2.wConfiguredRFTech2 = wTechnologyMask2;
			}
		}
		else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_ABORTED2;
		}
		else if ((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_FAILURE2)
		{
			wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2, &wValue2);
			if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
			{
				if ((wValue2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
				{
					dwStatus2 = PH_NFCLIB_STATUS_ABORTED2;
				}
				else if ((wValue2 & PH_ERR_MASK2) == PH_ERR_PROTOCOL_ERROR2)
				{
					dwStatus2 = PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2;
				}
				else if ((wValue2 & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2)
				{
					dwStatus2 = PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR2;
				}
				else if ((wValue2 & PH_ERR_MASK2) == PH_ERR_COLLISION_ERROR2)
				{
					dwStatus2 = PH_NFCLIB_STATUS_MULTIPLE_PEERS_DETECTED2;
				}
				else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
				{
					dwStatus2 = PH_NFCLIB_STATUS_NO_PEER_DISCOVERED2;
				}
				else
				{
					dwStatus2 = PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2;
				}
			}
		}
		else if (wStatus2 == PH_NFCLIB_STATUS_INVALID_PARAMETER2)
		{
			/* TODO: Remove after NFC and ISO profile is implemented. */
			dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
		}
		else if (wStatus2 == PH_ERR_INVALID_PARAMETER2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
		}
		else
		{
			dwStatus2 = PH_NFCLIB_STATUS_PEER_ACTIVATION_FAILED2;
		}
		break;
}

	return dwStatus2;
}

FUNC(void, ANFCRL_API) phNfcLib_Transmit_MainFunction2(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t2, AUTOMATIC) wStatus2  = PH_ERR_SUCCESS2;

	switch(geTransmitState2)
	{
	case PHNFCLIB_TRANSMIT_ST_IDLE2:
	case PHNFCLIB_TRANSMIT_ST_DONE2:
		break;
	case PHNFCLIB_TRANSMIT_ST_EXCHANGE2:
		wStatus2 = pTransmit2[gphNfcLib_State2.bProfileSelected2](gphNfcLib_State2.pTxBuffer2, gphNfcLib_State2.wTxLength2);

		if(wStatus2 != PH_STATUS_INPROCESS2)
		{
			geTransmitState2 = PHNFCLIB_TRANSMIT_ST_DONE2;
			gphNfcLib_State2.wBkpStatus2 = wStatus2;
		}
		break;
	}
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_Transmit2(
									CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer2,
									VAR(uint16_t, AUTOMATIC) wTxBufferLength2
									)
{
	VAR(phNfcLib_Status_t2, AUTOMATIC) dwStatus2 = PH_STATUS_INPROCESS2;
	VAR(phStatus_t2, AUTOMATIC) wStatus2  = PH_ERR_SUCCESS2;

	switch(geTransmitState2)
	{
	case PHNFCLIB_TRANSMIT_ST_IDLE2:
		if ((pTxBuffer2 == NULL) && (gphNfcLib_State2.bTxState2 != PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING2))
		{
			return PH_NFCLIB_STATUS_INVALID_PARAMETER2;
		}
		gphNfcLib_State2.pRxBuffer2   = NULL;
		gphNfcLib_State2.wRxLength2   = 0x00u;
		gphNfcLib_State2.wRxDataPoin2 = 0x00u;

		if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_ActivatedState2)
		{
			gphNfcLib_State2.pTxBuffer2 = pTxBuffer2;
			gphNfcLib_State2.wTxLength2 = wTxBufferLength2;
			geTransmitState2 = PHNFCLIB_TRANSMIT_ST_EXCHANGE2;
			return PH_STATUS_INPROCESS2;
		}
		dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;
		break;

	case PHNFCLIB_TRANSMIT_ST_EXCHANGE2:
		break;
	case PHNFCLIB_TRANSMIT_ST_DONE2:
		gphNfcLib_State2.pTxBuffer2 = NULL;
		gphNfcLib_State2.wTxLength2 = 0u;
		wStatus2 = gphNfcLib_State2.wBkpStatus2;

		if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
		{
			/* Updated the state of Transmit. */
			gphNfcLib_State2.bTxState2 = PH_NFCLIB_INT_TRANSMIT_ON2;

			dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
		}
		else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS_CHAINING2)
		{
			/* Updated the state of Transmit. */
			gphNfcLib_State2.bTxState2 = PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING2;

			/* Return Buffer overflow to user so that Receive has to be called to clear NFCLIB
			 * Rx buffer and the perform Transmit with pTxBuffer2 parameter as NULL. */
			dwStatus2 = PH_NFCLIB_STATUS_BUFFER_OVERFLOW2;
		}
		else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		else if (((wStatus2 & PH_ERR_MASK2) == PH_ERR_PROTOCOL_ERROR2) ||
			((wStatus2 & PH_ERR_MASK2) == PH_ERR_AUTH_ERROR2))
		{
			dwStatus2 = PH_NFCLIB_STATUS_RF_PROTOCOL_ERROR2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_INTEGRITY_ERROR2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_RF_TRANSMISSION_ERROR2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		else if (wStatus2 == PH_ERR_INVALID_PARAMETER2)
		{
			/* TODO: Remove after NFC profile is implemented. */
			dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		else if ((wStatus2 & PH_ERR_MASK2) >= PH_ERR_INTERNAL_ERROR2)
		{
			dwStatus2 = PH_NFCLIB_STATUS_INTERNAL_ERROR2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		else
		{
			dwStatus2 = PH_NFCLIB_STATUS_RF_PEER_LOST2;
			gphNfcLib_State2.bTxState2    = PH_NFCLIB_INT_TRANSMIT_OFF2;
		}
		break;
	}

	geTransmitState2 = PHNFCLIB_TRANSMIT_ST_IDLE2;
	return dwStatus2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_Receive2(CONSTP2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pRxBuffer2,
		P2VAR(uint16_t, AUTOMATIC, ANFCRL_DATA) pNumberOfBytes2, P2VAR(uint8_t, AUTOMATIC, ANFCRL_DATA) pMoreDataAvailable2)
{
	VAR(phNfcLib_Status_t2, AUTOMATIC) dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;

	if ((pRxBuffer2 == NULL) || (pNumberOfBytes2 == NULL)
			|| (*pNumberOfBytes2 == 0U))
	{
		return PH_NFCLIB_STATUS_INVALID_PARAMETER2;
	}

	if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_ActivatedState2)
	{
		if ((gphNfcLib_State2.bProfileSelected2
				== PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2)
				|| (gphNfcLib_State2.bProfileSelected2
						== PH_NFCLIB_ACTIVATION_PROFILE_ISO2))
		{
			if (gphNfcLib_State2.bTxState2 == PH_NFCLIB_INT_TRANSMIT_OFF2)
			{
				return dwStatus2;
			}

			if ((gphNfcLib_State2.pRxBuffer2 != NULL)
					&& (gphNfcLib_State2.wRxLength2 > 0U))
			{
				if (gphNfcLib_State2.wRxLength2 <= *pNumberOfBytes2)
				{
					if (pMoreDataAvailable2 != NULL)
					{
						*pMoreDataAvailable2 = 0;
					}
					*pNumberOfBytes2 = gphNfcLib_State2.wRxLength2;
					(void) memcpy((uint8_t*) pRxBuffer2,
							&gphNfcLib_State2.pRxBuffer2[gphNfcLib_State2.wRxDataPoin2],
							*pNumberOfBytes2);
					gphNfcLib_State2.wRxDataPoin2 = 0;
					gphNfcLib_State2.wRxLength2 = 0;

					/* Do not reset the TxState if previous Tx is chaining as this status is checked in Transmit API. */
					if (gphNfcLib_State2.bTxState2
							!= PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING2)
					{
						gphNfcLib_State2.bTxState2 = PH_NFCLIB_INT_TRANSMIT_OFF2;
					}
					dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
				}
				else
				{
					if (pMoreDataAvailable2 != NULL)
					{
						*pMoreDataAvailable2 = 1;
						(void) memcpy((uint8_t*) pRxBuffer2,
								&gphNfcLib_State2.pRxBuffer2[gphNfcLib_State2.wRxDataPoin2],
								*pNumberOfBytes2);
						gphNfcLib_State2.wRxDataPoin2 = *pNumberOfBytes2;
						gphNfcLib_State2.wRxLength2 -= *pNumberOfBytes2;
						dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
					}
					else
					{
						dwStatus2 = PH_NFCLIB_STATUS_BUFFER_OVERFLOW2;
					}
				}
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_RF_TIMEOUT_ERROR2;
				if (gphNfcLib_State2.bProfileSelected2
						== PH_NFCLIB_ACTIVATION_PROFILE_ISO2)
				{
					*pNumberOfBytes2 = gphNfcLib_State2.wRxLength2;
					dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
				}
			}
		}
		else
		{
			/* TODO: Remove after NFC profile is implemented. */
		}
	}
	return dwStatus2;
}

FUNC(void, ANFCRL_API) phNfcLib_Deactivate_Mainfunction2(VAR(void, AUTOMATIC))
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2;

	switch (gbDeactivateState2)
	{
	case PHNFCLIB_DEACTIVE_IDLE2:
	case PHNFCLIB_DEACTIVE_DONE2:
		break;
	case PHNFCLIB_DEACTIVE_FIELDOFF2:
		wStatus2 = phhalHw_FieldOff2(&gphNfcLib_Params2.sHal2);
		if (wStatus2 == PH_STATUS_INPROCESS2)
		{
			break;
		}
		else
		{
			gphNfcLib_State2.bNfcLibState2 = eNfcLib_InitializedState2;
			gbDeactivateState2 = PHNFCLIB_DEACTIVE_WAIT2;
		}
		break;
	case PHNFCLIB_DEACTIVE_WAIT2:
		wStatus2 = phhalHw_Wait2(&gphNfcLib_Params2.sHal2,
				PHHAL_HW_TIME_MICROSECONDS2, 5100);
		if (wStatus2 == PH_STATUS_INPROCESS2)
		{
			break;
		}
		gbDeactivateState2 = PHNFCLIB_DEACTIVE_DONE2;
		break;
	case PHNFCLIB_DEACTIVE_HALT2:
		wStatus2 = pDeactivate2[gphNfcLib_State2.bProfileSelected2]();
		if (wStatus2 == PH_STATUS_INPROCESS2)
		{
			break;
		}
		gphNfcLib_State2.wBkpStatus2 = wStatus2;
		gbDeactivateState2 = PHNFCLIB_DEACTIVE_DONE2;
		break;
	}
}

FUNC(phNfcLib_Status_t2, ANFCRL_API) phNfcLib_Deactivate2(
	VAR(uint8_t, ANFCRL_VAR) bDeactivateMode2,
	P2VAR(phNfcLib_PeerInfo_t, AUTOMATIC, ANFCRL_VAR) peerInfo2
	)
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2;
	VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;
	VAR(uint16_t, ANFCRL_VAR) wValue2;

	switch(gbDeactivateState2)
	{
		case PHNFCLIB_DEACTIVE_IDLE2:
			if (bDeactivateMode2 == PH_NFCLIB_DEACTIVATION_MODE_RF_OFF2)
			{
				if (gphNfcLib_State2.bNfcLibState2 != eNfcLib_ResetState2)
				{
					gbDeactivateState2 = PHNFCLIB_DEACTIVE_FIELDOFF2;
					return PH_STATUS_INPROCESS2;
				}
			}
			else if (bDeactivateMode2 == PH_NFCLIB_DEACTIVATION_MODE_RELEASE2)
			{
				if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_ActivatedState2)
				{
					gbDeactivateState2 = PHNFCLIB_DEACTIVE_HALT2;
					return PH_STATUS_INPROCESS2;
				}
				else
				{
					return PH_NFCLIB_STATUS_INVALID_STATE2;
				}
			}
			else
			{
				dwStatus2 = PH_NFCLIB_STATUS_INVALID_PARAMETER2;
				break;
			}
			/*no break*/
		case PHNFCLIB_DEACTIVE_DONE2:
			wStatus2 = gphNfcLib_State2.wBkpStatus2;
			if (bDeactivateMode2 == PH_NFCLIB_DEACTIVATION_MODE_RELEASE2)
			{
				if (gphNfcLib_State2.bNfcLibState2 == eNfcLib_ActivatedState2)
				{
					if (wStatus2 == PH_ERR_SUCCESS2)
					{
						dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;

						gphNfcLib_State2.bNfcLibState2 = eNfcLib_InitializedState2;
						gphNfcLib_State2.wConfiguredRFTech2 = 0x00;
						gphNfcLib_Params2.pNfcLib_ErrCallbck2 = NULL;
					}
					else if ((wStatus2 & PH_ERR_MASK2) == PHAC_DISCLOOP_FAILURE2)
					{
						wStatus2 = phacDiscLoop_GetConfig2(&gphNfcLib_Params2.sDiscLoop2, PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2, &wValue2);
						if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
						{
							if ((wValue2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
							{
								dwStatus2 = PH_NFCLIB_STATUS_ABORTED2;
							}
							else if ((wValue2 & PH_ERR_MASK2) == PH_ERR_SUCCESS2)
							{
								dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;

								gphNfcLib_State2.bNfcLibState2 = eNfcLib_InitializedState2;
								gphNfcLib_State2.wConfiguredRFTech2 = 0x00;
								gphNfcLib_Params2.pNfcLib_ErrCallbck2 = NULL;
							}
							else
							{
								/* Do Nothing */
							}
						}
					}
					else if ((wStatus2 & PH_ERR_MASK2) == PH_ERR_ABORTED2)
					{
						dwStatus2 = PH_NFCLIB_STATUS_ABORTED2;
					}
					else
					{
						dwStatus2 = PH_NFCLIB_STATUS_PEER_DEACTIVATION_FAILED2;
					}
		#ifdef NXPBUILD__PHPAL_I14443P4_SW2
					/* Irrespective of Profile selected, PAL 14443-4 layer needs to be reset. */
					(void)phpalI14443p4_ResetProtocol2(&gphNfcLib_Params2.spalI14443p42);
		#endif /* NXPBUILD__PHPAL_I14443P4_SW2*/
					break;
				}
			}
			dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
			break;

		case PHNFCLIB_DEACTIVE_FIELDOFF2:
		case PHNFCLIB_DEACTIVE_WAIT2:
		case PHNFCLIB_DEACTIVE_HALT2:
			return PH_STATUS_INPROCESS2;
	}
	gbDeactivateState2 = PHNFCLIB_DEACTIVE_IDLE2;
	PH_UNUSED_VARIABLE2(peerInfo2);
	return dwStatus2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_AR_RELEASE_MINOR_VERSION_C2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB_PROFILES2 */

#ifdef __cplusplus
}
#endif
