/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2023
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
*   @file    phhalHw_Ncx33212.c
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321 - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#include <phhalHw2.h>
#include <ph_RefDefs2.h>

#ifdef NXPBUILD__PH_KEYSTORE2
#include <phKeyStore2.h>
#endif

#ifdef NXPBUILD__PHHAL_HW_NCX33212

#include <phDriver2.h>
#include <phTools2.h>
#include "phhalHw_Ncx33212.h"
#include <phhalHw_Ncx3321_Instr2.h>
#include "phhalHw_Ncx3321_InstrMngr2.h"
#include <phhalHw_Ncx3321_Reg2.h>
#include "phhalHw_Ncx3321_Int2.h"
#include "phhalHw_Ncx3321_Wait2.h"

#ifndef AUTOSAR_VER
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection2.h>

#endif	/* NIDEC_PORTING */
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx33212.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321.h header file are of the same vendor */
#if (PHHALHW_NCX3321_VENDOR_ID_C2 != PHHALHW_NCX3321_VENDOR_ID2)
    #error "phhalHw_Ncx33212.c and phhalHw_Ncx3321.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2    != PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2    != PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION_C2 != PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phhalHw_Ncx33212.c and phhalHw_Ncx3321.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_SW_MAJOR_VERSION_C2 != PHHALHW_NCX3321_SW_MAJOR_VERSION2) || \
     (PHHALHW_NCX3321_SW_MINOR_VERSION_C2 != PHHALHW_NCX3321_SW_MINOR_VERSION2) || \
     (PHHALHW_NCX3321_SW_PATCH_VERSION_C2 != PHHALHW_NCX3321_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phhalHw_Ncx33212.c and phhalHw_Ncx3321.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX33212
typedef struct
{
  P2CONST(uint16, AUTOMATIC, ANFCRL_APPL_CONST) pShadowDefault2;
  VAR(uint16, ANFCRL_VAR) wShadowCount2;
  VAR(uint16, ANFCRL_VAR) wIndex2;
  VAR(uint16, ANFCRL_VAR) wConfig2;
  VAR(uint8, ANFCRL_VAR) bUseDefaultShadow2;
}phApplyProtocolParam_t2;

typedef struct
{
  VAR(uint32, ANFCRL_VAR) dwLoadValue2;
  VAR(uint32, ANFCRL_VAR) wPrescaler2;
  VAR(uint16, ANFCRL_VAR) wBkpTimeout2;
}phWaitParam_t2;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define PH_RF_EXCH_CONF_ENABLE_RSP_RX_DATA2   0x08U
#define PH_RF_EXCH_CONF_ENABLE_EVT_STATUS2    0x04U
#define PH_RF_EXCH_CONF_ENABLE_RF_STATUS2     0x02U
#define PH_RF_EXCH_CONF_ENABLE_RX_STATUS2     0x01U

#define PH_RECEIVE_RF_ENABLE_EVT_STATUS2   0x04U
#define PH_RECEIVE_RF_ENABLE_RF_STATUS2    0x02U
#define PH_RECEIVE_RF_ENABLE_RX_STATUS2    0x01U

#define PHHAL_HW_STATE_IDLE2					0u
#define PHHAL_HW_STATE_APPLY_SETTINGS2		1u
#define PHHAL_HW_STATE_READ_HF_ATT2 			2u
#define PHHAL_HW_STATE_APPLY_HF_ATT2 		3u
#define PHHAL_HW_STATE_CMD12					4u
#define PHHAL_HW_STATE_CMD22					5u
#define PHHAL_HW_STATE_CMD32					6u
#define PHHAL_HW_STATE_CMD42					7u
#define PHHAL_HW_STATE_CMD52					8u
#define PHHAL_HW_STATE_CMD62					9u
#define PHHAL_HW_STATE_CMD72					10u
#define PHHAL_HW_STATE_CHECK_DPC2			11u
#define PHHAL_HW_STATE_DISABLE_DPC2			12u
#define PHHAL_HW_STATE_CHECK_EEPRROM2		13u
#define PHHAL_HW_STATE_FIELD_ON2				14u
#define PHHAL_HW_STATE_GET_TXLDO_VDDPA2		15u
#define PHHAL_HW_STATE_GET_ULPCD_VDDPA2		16u
#define PHHAL_HW_STATE_APPLY_ULPCD_VDDPA2	17u
#define PHHAL_HW_STATE_HF_ATT_DELAY2			18u
#define PHHAL_HW_STATE_FIELD_RESET2			19u
#define PHHAL_HW_STATE_RESET_CONFIG12		20u
#define PHHAL_HW_STATE_RESET_CONFIG22		21u

/* Wait time to stabilize RF ON before reading HF ATT value */
#define PHHAL_HW_READ_HF_ATT_WAIT_TIME2         1500U

#define SET_NCX3321_SHADOW2(USED_SHADOW2)   \
		pBackup2->pShadowDefault2 = &(USED_SHADOW2)[0][0]; \
		pBackup2->wShadowCount2 = (uint16)(sizeof((USED_SHADOW2)) / (sizeof((USED_SHADOW2)[0])))

#define EVTS_HEADER_BYTES2       3U
#define EVENT_LSB_INDEX2         1U
#define TLV_TYPE_FIELD_INDEX2    1U
#define TLV_LENGTH_MSB_INDEX2    2U
#define qTLV_LENGTH_LSB_INDEX2    3U

#define PHHAL_HW_NCX3321_MAX_LOADVALUE_MS2	((uint32)PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS2 * ( PHHAL_HW_NCX3321_MIN_FREQ2  / PHHAL_HW_NCX3321_CONVERSION_MS_SEC2))
#define PHHAL_HW_NCX3321_MAX_LOADVALUE_US2	(PHHAL_HW_NCX3321_MAX_FREQ2 / (PHHAL_HW_NCX3321_CONVERSION_US_SEC2/100U))
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Default shadow for ISO14443-3A Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 wNcx3321_DefaultShadow_I14443a2[][2] =
{
    {PHHAL_HW_CONFIG_PARITY2,                PH_ON2},
    {PHHAL_HW_CONFIG_TXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_TRXCRC2,                PH_ON2},
    {PHHAL_HW_CONFIG_RXWAIT_US2,             76U},
    {PHHAL_HW_CONFIG_TXWAIT_US2,             85U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_1062 | PHHAL_HW_RF_TYPE_A_FRAMING2},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_1062 | PHHAL_HW_RF_TYPE_A_FRAMING2},
    {PHHAL_HW_CONFIG_ASK1002,                PH_ON2}
};

/* Default shadow for ISO14443-3B Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 wNcx3321_DefaultShadow_I14443b2[][2] =
{
    {PHHAL_HW_CONFIG_PARITY2,                PH_OFF2},
    {PHHAL_HW_CONFIG_TXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXWAIT_US2,             76U},
    {PHHAL_HW_CONFIG_TXWAIT_US2,             85U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_1062 | PHHAL_HW_RF_TYPE_B_FRAMING2},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_1062 | PHHAL_HW_RF_TYPE_B_FRAMING2},
    {PHHAL_HW_CONFIG_ASK1002,                PH_OFF2}
};

/* Default shadow for FeliCa Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 wNcx3321_DefaultShadow_Felica2[][2] =
{
    {PHHAL_HW_CONFIG_PARITY2,                PH_OFF2},
    {PHHAL_HW_CONFIG_TXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXWAIT_US2,             88U},
    {PHHAL_HW_CONFIG_TXWAIT_US2,             160U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_2122 | PHHAL_HW_RF_TYPE_F_FRAMING2},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_2122 | PHHAL_HW_RF_TYPE_F_FRAMING2},
    {PHHAL_HW_CONFIG_ASK1002,                PH_OFF2}
};

/* Default shadow for FeliCa Mode at 424 baud rate */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 wNcx3321_DefaultShadow_Felica_4242[][2] =
{
    {PHHAL_HW_CONFIG_PARITY2,                PH_OFF2},
    {PHHAL_HW_CONFIG_TXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXWAIT_US2,             85U},
    {PHHAL_HW_CONFIG_TXWAIT_US2,             160U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_4242 | PHHAL_HW_RF_TYPE_F_FRAMING2},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,    PHHAL_HW_RF_DATARATE_4242 | PHHAL_HW_RF_TYPE_F_FRAMING2},
    {PHHAL_HW_CONFIG_ASK1002,                PH_OFF2}
};

/* Default shadow for ISO15693 Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM2 wNcx3321_DefaultShadow_I156932[][2] =
{
    {PHHAL_HW_CONFIG_PARITY2,                PH_OFF2},
    {PHHAL_HW_CONFIG_TXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXCRC2,                 PH_ON2},
    {PHHAL_HW_CONFIG_RXWAIT_US2,             300U},
    {PHHAL_HW_CONFIG_TXWAIT_US2,             500U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING2,    PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_42},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING2,    PHHAL_HW_RF_RX_DATARATE_HIGH2},
    {PHHAL_HW_CONFIG_SUBCARRIER2,            PHHAL_HW_SUBCARRIER_SINGLE2},
    {PHHAL_HW_CONFIG_ASK1002,                PH_ON2}
};



#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(phApplyProtocolParam_t2, ANFCRL_VAR) g_sApplyProtocolParam2;         /**< Store backup parameters for phhalHw_Ncx3321_ApplyProtocolSettings2. */
static VAR(phWaitParam_t2, ANFCRL_VAR) g_sWaitParam2;                           /**< Store backup parameters for phhalHw_Ncx3321_Wait2. */
static VAR(uint8, ANFCRL_VAR) g_aUlpcdVddpa2[2] = {0};                        /**< Store ULPCD VDDPA setting. */

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) g_bEnBootNormalModeState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bApplyProtocolState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bExchangeState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bTransmitState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bReceiveState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bAutocollState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bWaitState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bEventWaitState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bFieldOffState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bSetConfigState2 = PHHAL_HW_STATE_IDLE2;
static VAR(uint8, ANFCRL_VAR) g_bSetListenParamsState2 = PHHAL_HW_STATE_IDLE2;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) xEventHandle2;

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_EnBootNormalMode2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Init2(
              P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams2,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams2,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
              VAR(uint16, ANFCRL_VAR) wTxBufSize2,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
              VAR(uint16, ANFCRL_VAR) wRxBufSize2
							)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(phDriver_Pin_Config_t2, ANFCRL_VAR) PH_MEMLOC_REM2 pinCfg2;
  static VAR(uint8, ANFCRL_VAR) bHalInitState2 = PHHAL_HW_STATE_IDLE2;
  static VAR(uint8, ANFCRL_VAR) bStateHaltCnt2 = 0u;		/* 010A_06 */
  
	switch(bHalInitState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			if (sizeof(phhalHw_Ncx3321_DataParams_t2) != wSizeOfDataParams2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, PH_COMP_HAL2);
			}

			/* The buffers cannot be zero */
			if ((wTxBufSize2 == 0U) || (wRxBufSize2 == 0U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* Check all the pointers */
			PH_ASSERT_NULL2(pDataParams2);
			PH_ASSERT_NULL2(pBalDataParams2);
			PH_ASSERT_NULL2(pTxBuffer2);
			PH_ASSERT_NULL2(pRxBuffer2);

			/* The first bytes are reserved for the SPI commands */
			pDataParams2->pTxBuffer2                = &pTxBuffer2[1];
			pDataParams2->wTxBufSize2               = wTxBufSize2 - 1U;
			pDataParams2->pRxBuffer2                = &pRxBuffer2[2];
			pDataParams2->wRxBufSize2               = wRxBufSize2 - 2U;

			/* Initialize the private data */
			pDataParams2->wId2                      = PH_COMP_HAL2 | PHHAL_HW_NCX3321_ID2;
			pDataParams2->pBalDataParams2           = pBalDataParams2;
			pDataParams2->pKeyStoreDataParams2      = pKeyStoreDataParams2;

			pDataParams2->wRxBufLen2              = 0U;
			pDataParams2->wRxBufStartPos2         = 0U;

			pDataParams2->wTxBufLen2              = 0U;
			pDataParams2->wTxBufStartPos2         = 0U;
			pDataParams2->wTxFwDataLen2           = 0U;

			pDataParams2->bActiveMode2            = PH_OFF2;
			pDataParams2->bCardType2              = PHHAL_HW_CARDTYPE_ISO14443A2;
			pDataParams2->bTimeoutUnit2           = PHHAL_HW_TIME_MICROSECONDS2;
			pDataParams2->wFieldOffTime2          = PHHAL_HW_FIELD_OFF_DEFAULT2;
			pDataParams2->wFieldRecoveryTime2     = PHHAL_HW_FIELD_RECOVERY_DEFAULT2;
			pDataParams2->bSymbolStart2           = PH_OFF2;
			pDataParams2->bSymbolEnd2             = PH_OFF2;

			pDataParams2->bRfResetAfterTo2        = PH_OFF2;
			pDataParams2->bOpeMode2               = RD_LIB_MODE_NFC2;
			pDataParams2->dwFelicaEmdReg2         = 0U;
			pDataParams2->bRxMultiple2            = PH_OFF2;
			pDataParams2->bJewelActivated2        = PH_OFF2;
			pDataParams2->bLpcdConfig2            = 0U;
			pDataParams2->bLpcdState2             = PHHAL_HW_STATE_IDLE2;
			pDataParams2->wWakeupCounterInMs2     = 1000U;
			pDataParams2->wLPCDWakeupCounterInMs2 = 1000U;
			pDataParams2->bLpcdWakeUpCtrl2        = 0U;
			pDataParams2->bRfca2                  = PH_ON2;
			pDataParams2->wTargetMode2            = PH_OFF2;
			pDataParams2->dwTxWaitMs2             = 0U;
			pDataParams2->bMfcCryptoEnabled2      = PH_OFF2;
			pDataParams2->bCardMode2              = PH_OFF2;
			pDataParams2->bBalConnectionType2     = PHHAL_HW_BAL_CONNECTION_SPI2;
			pDataParams2->wAdditionalInfo2        = 0U;
			pDataParams2->dwExpectedEvent2         = 0U;

			pDataParams2->bSsTx1ConfigIsConfigured2 = 0U;
			pDataParams2->bSsTx2ConfigIsConfigured2 = 0U;
			pDataParams2->dwSetSsTx1ConfigValue2 = 0x00U;
			pDataParams2->dwSetSsTx2ConfigValue2 = 0x00U;
			pDataParams2->pTimerISRCallBack2      = &phhalHw_Ncx3321_Int_GuardTimeCallBck2;

			pDataParams2->bPollGuardTimeFlag2     = PH_OFF2;
			pDataParams2->sIrqResp2.bIsrBytesRead2 = 9U;
			pDataParams2->bCTSEvent2              = PH_OFF2;
			pDataParams2->bRFONEvent2             = PH_OFF2;
			pDataParams2->dwEventStatus2          = 0U;
			pDataParams2->dwEventReceived2        = 0U;
			pDataParams2->dwLpcdRefVal2           = 0U;
			pDataParams2->dwGenError2             = 0x00U;
			pDataParams2->bNfcipMode2             = PH_OFF2;
			pDataParams2->sIrqResp2.pHandlerModeBuffPtr2 = &pDataParams2->sIrqResp2.aISRReadBuf2[0];
			pDataParams2->wExchangeRfStatus2 = PH_ERR_SUCCESS2;

			/* Non-Blocking Handle parameter init */
			pDataParams2->bSendState2 = 0U;
			pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_OFF2;
			pDataParams2->bRegisterOpState2 = PHHAL_INSTR_STATE_CHECK_PARAM2;
			g_bEnBootNormalModeState2 = PHHAL_HW_STATE_IDLE2;
			g_bApplyProtocolState2 = PHHAL_HW_STATE_IDLE2;
			g_bExchangeState2 = PHHAL_HW_STATE_IDLE2;
			g_bTransmitState2 = PHHAL_HW_STATE_IDLE2;
			g_bReceiveState2 = PHHAL_HW_STATE_IDLE2;
			g_bAutocollState2 = PHHAL_HW_STATE_IDLE2;
			g_bWaitState2 = PHHAL_HW_STATE_IDLE2;
			g_bEventWaitState2 = PHHAL_HW_STATE_IDLE2;
			g_bFieldOffState2 = PHHAL_HW_STATE_IDLE2;

			(void)memset(&pDataParams2->sIrqResp2.aISRReadBuf2[0], 0, MAX_ISR_READ_BUFFER_SIZE2);

			/* Configure Reset pin as output and set to high. */
			pinCfg2.bPullSelect2 = PHDRIVER_PIN_RESET_PULL_CFG2;
			pinCfg2.bOutputLogic2 = RESET_POWERUP_LEVEL2;

			PH_CHECK_SUCCESS_FCT2(statusTmp2, phDriver_PinConfig2(
				PHDRIVER_PIN_RESET2,
				PH_DRIVER_PINFUNC_OUTPUT2,
				&pinCfg2));

		#ifdef PHDRIVER_SOFT_SSEL2
			if(((phbalReg_Type_t2 *)pBalDataParams2)->bBalType2 == PHBAL_REG_TYPE_SPI2)
			{
				/* Configure NSS (Chip Select) pin as GPIO output and set to high. */
				pinCfg2.bPullSelect2 = PHDRIVER_PIN_NSS_PULL_CFG2;
				pinCfg2.bOutputLogic2 = PH_DRIVER_SET_HIGH2;
				PH_CHECK_SUCCESS_FCT2(statusTmp2, phDriver_PinConfig2(
					PHDRIVER_PIN_SSEL2,
					PH_DRIVER_PINFUNC_OUTPUT2,
					&pinCfg2));
			}
		#endif /* PHDRIVER_SOFT_SSEL2*/

			if (((phbalReg_Type_t2 *)pBalDataParams2)->bBalType2 != PHBAL_REG_TYPE_KERNEL_SPI2)
			{
				/* Busy pin (nothing but IRQ for Triton) as input and pullup enabled.
				 * Helps during poll operation, Do Not Remove. */
				pinCfg2.bPullSelect2 = PHDRIVER_PIN_BUSY_PULL_CFG2;
				(void)phDriver_PinConfig2(PHDRIVER_PIN_BUSY2, PH_DRIVER_PINFUNC_INPUT2, &pinCfg2);
			}
			bHalInitState2 = PHHAL_HW_STATE_CMD12;
			/* no break */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
		case PHHAL_HW_STATE_CMD12:
			/* Reset Ncx3321 Front-end. */
			platformSpiWAKEUP_WriteDirect2(OFF);
			bHalInitState2 = PHHAL_HW_STATE_CMD22;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD22:
			/* Do Nothing */
			bHalInitState2 = PHHAL_HW_STATE_CMD32;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD32:
			/* Do Nothing */
			bHalInitState2 = PHHAL_HW_STATE_CMD42;
			return PH_STATUS_INPROCESS2;
/* 010A_06 */
		case PHHAL_HW_STATE_CMD42:
			/* Do Nothing */
			bHalInitState2 = PHHAL_HW_STATE_CMD52;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD52:
			/* Do Nothing */
			bHalInitState2 = PHHAL_HW_STATE_CMD62;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD62:
			/* Do Nothing */
			bHalInitState2 = PHHAL_HW_STATE_CMD72;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD72:
			/* Reset Ncx3321 Front-end. */
			platformSpiWAKEUP_WriteDirect2(ON);
			bHalInitState2 = 11u;
			return PH_STATUS_INPROCESS2;

		case 11u:
			/* Do Nothing */
			bHalInitState2 = 12u;
			return PH_STATUS_INPROCESS2;

		case 12u:
			// PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_EnBootNormalMode2(pDataParams2));
			statusTmp2 = phhalHw_Ncx3321_EnBootNormalMode2(pDataParams2);
			
			if(statusTmp2 == PH_STATUS_INPROCESS2)
			{
				if(bStateHaltCnt2++ > 20u)
				{
					// bHalInitState2 = PHHAL_HW_STATE_IDLE2;
					bStateHaltCnt2 = 0u;
					break;
				}
				else
				{
					return statusTmp2;
				}				
			}
/* 010A_06 */
			/* Switch to Normal Mode and Read Ideal Event*/
			if( PH_ERR_SUCCESS2 != (statusTmp2 & PH_ERR_MASK2 ))
			{
				break;
			}

#else
		case PHHAL_HW_STATE_CMD12:
			/* Reset Ncx3321 Front-end. */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_Reset2());
			if( PH_ERR_SUCCESS2 != (statusTmp2 & PH_ERR_MASK2 ))
			{
				break;
			}
			else
			{
				bHalInitState2 = PHHAL_HW_STATE_CMD22;
				return PH_STATUS_INPROCESS2;
			}
			/* no break */

		case PHHAL_HW_STATE_CMD22:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_EnBootNormalMode2(pDataParams2));
			/* Switch to Normal Mode and Read Ideal Event*/
			if( PH_ERR_SUCCESS2 != (statusTmp2 & PH_ERR_MASK2 ))
			{
				break;
			}

#endif
			(void)phTools_EventCreate2(&pDataParams2->HwEventObj2,pDataParams2->pHalPollFunc2, pDataParams2);
			xEventHandle2 = &(pDataParams2->HwEventObj2);

			/* This assignment has to be done after NCx3321 is confirmed to
			 * be normal mode */
			pDataParams2->pRFISRCallback2         = &phhalHw_Ncx3321_ISR_Callback2;
			break;
		default:
			statusTmp2 = PH_ERR_INTERNAL_ERROR2;
			break;

	}

	bHalInitState2 = PHHAL_HW_STATE_IDLE2;
    phhalHw_Ncx3321_Int_ResetState2();
	return statusTmp2;
}

static FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_EnBootNormalMode2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventStatusReg2 = 0x0U;
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bEvent2 = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wPktLength2 = 0x0U;

  static VAR(uint32, ANFCRL_VAR) wStartTime2 = 0U;
  VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;
	switch(g_bEnBootNormalModeState2)
	{
		case PHHAL_HW_STATE_IDLE2:
		    PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_SwitchModeBootNormal2(pDataParams2));
		    PH_CHECK_SUCCESS2(status2);
			g_bEnBootNormalModeState2 = PHHAL_HW_STATE_CMD12;
			// wStartTime2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_MSECS2);
			/* no break */

		case PHHAL_HW_STATE_CMD12:
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
			/* Wait till IDEL EVENT is been triggered by NCX3321. */
			if (phDriver_PinRead2(PHDRIVER_PIN_IRQ2, PH_DRIVER_PINFUNC_INPUT2) == 0U)
			{
				// dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_MSECS2, wStartTime2);
				return PH_STATUS_INPROCESS2;
			}

#else
			/* Wait till IDEL EVENT is been triggered by NCX3321. */
			if (phDriver_PinRead2(PHDRIVER_PIN_IRQ2, PH_DRIVER_PINFUNC_INPUT2) == 0U)

			{
				dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_MSECS2, wStartTime2);

				/* Check for timer overflow, abort if timer overflow happens */
				if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
				{
					return PH_ERR_ABORTED2;
				}
				else
				{
					if(dwElapsedTime2 < PHHAL_HW_ABORT_EVT_TIMEOUT2)
					{
						return PH_STATUS_INPROCESS2;
					}
					else
					{
						/* If IRQ not response after wait time, leave with PH_ERR_INTERNAL_ERROR2 error code. */
						return PH_ERR_INTERNAL_ERROR2;
					}
				}
			}

#endif
			g_bEnBootNormalModeState2 = PHHAL_HW_STATE_IDLE2;

			/*Doing split read because we don't know whether ERROR also occurred, accordingly
			 * the length of response will change  */
			PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Read2(
				pDataParams2,
				&pDataParams2->sIrqResp2.aISRReadBuf2[0],
				EVTS_HEADER_BYTES2 + 1U
				));

			bEvent2 = pDataParams2->sIrqResp2.aISRReadBuf2[TLV_TYPE_FIELD_INDEX2];

			wPktLength2 = pDataParams2->sIrqResp2.aISRReadBuf2[TLV_LENGTH_MSB_INDEX2];
			wPktLength2 <<=  8;
			wPktLength2 |= pDataParams2->sIrqResp2.aISRReadBuf2[qTLV_LENGTH_LSB_INDEX2];

			if (!( (wPktLength2 == 0x08U) || (wPktLength2 == 0x0CU) ))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERFACE_ERROR2, PH_COMP_HAL2);
			}

			PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Read2(
				pDataParams2,
				&pDataParams2->sIrqResp2.aISRReadBuf2[0],
				wPktLength2 + 1U
				));

			dwEventStatusReg2 = (uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2];
			dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 1U]) << 8U ;
			dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 2U]) << 16U;
			dwEventStatusReg2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 3U]) << 24U;

			pDataParams2->dwEventStatus2 = (uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 4U];
			pDataParams2->dwEventStatus2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 5U]) << 8U ;
			pDataParams2->dwEventStatus2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 6U]) << 16U;
			pDataParams2->dwEventStatus2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 7U]) << 24U;


			/* Check if NCX3321 Booted correctly*/
			if (!((bEvent2 == 0x80U) && (dwEventStatusReg2 == PH_NCX3321_EVT_BOOT2)))
			{
				if((dwEventStatusReg2 & PH_NCX3321_EVT_GENERAL_ERROR2) != 0u)
				{
					pDataParams2->dwGenError2 = (uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 8U];
					pDataParams2->dwGenError2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 9U]) << 8U ;
					pDataParams2->dwGenError2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 10U]) << 16U;
					pDataParams2->dwGenError2 |= ((uint32) pDataParams2->sIrqResp2.aISRReadBuf2[EVENT_LSB_INDEX2 + 11U]) << 24U;
				}
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERFACE_ERROR2, PH_COMP_HAL2);
			}
	}

	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_DeInit2(
                P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
								)
{
	/* De-Initialize data parameters */
	pDataParams2->wId2                    = 0U;
	pDataParams2->pBalDataParams2         = NULL;
	pDataParams2->pKeyStoreDataParams2    = NULL;
	pDataParams2->pTxBuffer2              = NULL;
	pDataParams2->wTxBufSize2             = 0U;
	pDataParams2->wTxBufLen2              = 0U;
	pDataParams2->pRxBuffer2              = NULL;
	pDataParams2->wRxBufSize2             = 0U;
	pDataParams2->wRxBufLen2              = 0U;
	pDataParams2->wRxBufStartPos2         = 0U;
	pDataParams2->wTxBufStartPos2         = 0U;
	pDataParams2->bCardType2              = PHHAL_HW_CARDTYPE_UNKNOWN2;
	pDataParams2->bTimeoutUnit2           = PHHAL_HW_TIME_MICROSECONDS2;
	pDataParams2->wFieldOffTime2          = PHHAL_HW_FIELD_OFF_DEFAULT2;
	pDataParams2->wFieldRecoveryTime2     = PHHAL_HW_FIELD_RECOVERY_DEFAULT2;
	pDataParams2->bSymbolStart2           = PH_OFF2;
	pDataParams2->bSymbolEnd2             = PH_OFF2;
	pDataParams2->wAdditionalInfo2        = 0U;
	pDataParams2->bRfResetAfterTo2        = PH_OFF2;
	pDataParams2->bRxMultiple2            = PH_OFF2;
	pDataParams2->bActiveMode2            = PH_OFF2;
	pDataParams2->bRfca2                  = PH_ON2;
	pDataParams2->wTargetMode2            = PH_OFF2;
	pDataParams2->bOpeMode2               = RD_LIB_MODE_NFC2;
	pDataParams2->dwFelicaEmdReg2         = 0U;
	pDataParams2->bJewelActivated2        = PH_OFF2;
	pDataParams2->bLpcdConfig2            = 0U;
	pDataParams2->bLpcdState2             = PHHAL_HW_STATE_IDLE2;
	pDataParams2->wWakeupCounterInMs2     = 0U;
	pDataParams2->wLPCDWakeupCounterInMs2 = 0U;
	pDataParams2->bCTSEvent2              = PH_OFF2;
	pDataParams2->bRFONEvent2             = PH_OFF2;
	pDataParams2->dwEventStatus2          = 0U;
	pDataParams2->dwEventReceived2        = 0U;
	pDataParams2->dwLpcdRefVal2           = 0U;
	pDataParams2->dwTxWaitMs2             = 0U;
	pDataParams2->bMfcCryptoEnabled2      = PH_OFF2;
	pDataParams2->bCardMode2              = PH_OFF2;
	pDataParams2->bPollGuardTimeFlag2     = PH_OFF2;
	pDataParams2->dwExpectedEvent2        = 0U;
	pDataParams2->bNfcipMode2             = PH_OFF2;
	pDataParams2->bSsTx1ConfigIsConfigured2 = 0U;
	pDataParams2->bSsTx2ConfigIsConfigured2 = 0U;
	pDataParams2->dwSetSsTx1ConfigValue2 = 0x00U;
	pDataParams2->dwSetSsTx2ConfigValue2 = 0x00U;
	pDataParams2->sIrqResp2.pHandlerModeBuffPtr2 =  NULL;

	/* Non-Blocking Handle parameter reset */
	pDataParams2->bSendState2 = 0U;
	pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_OFF2;
	g_bEnBootNormalModeState2 = PHHAL_HW_STATE_IDLE2;
	g_bApplyProtocolState2 = PHHAL_HW_STATE_IDLE2;
	g_bExchangeState2 = PHHAL_HW_STATE_IDLE2;
	g_bTransmitState2 = PHHAL_HW_STATE_IDLE2;
	g_bReceiveState2 = PHHAL_HW_STATE_IDLE2;
	g_bAutocollState2 = PHHAL_HW_STATE_IDLE2;
	g_bWaitState2 = PHHAL_HW_STATE_IDLE2;
	g_bEventWaitState2 = PHHAL_HW_STATE_IDLE2;
	g_bFieldOffState2 = PHHAL_HW_STATE_IDLE2;

    phhalHw_Ncx3321_Int_ResetState2();
	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_AsyncAbort2(
                   P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
									 )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;

	/* Post Abort Event. */
	PH_CHECK_SUCCESS_FCT2(status2, phTools_EventPost2(
		&pDataParams2->HwEventObj2,
		E_EVENT_OPT_NONE2,
		E_EVENT_ABORT2,
		NULL));
	return PH_ERR_SUCCESS2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_FieldOn2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
								  )
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRFONconfig2 = 0U;

	if(pDataParams2->bRfca2 == PH_OFF2)
	{
		bRFONconfig2 |= 0x01U;
	}

	if(pDataParams2->bActiveMode2 == PH_ON2)
	{
		bRFONconfig2 |= 0x02U;
	}
	PH_CHECK_INPROCESS_FCT2(statusTmp2,
			phhalHw_Ncx3321_Instr_RfOn2(pDataParams2, bRFONconfig2));

	if ((statusTmp2 & PH_ERR_MASK2) == PH_ERR_NCX3321_EXTERNAL_FIELD_ERROR2)
	{
		statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_RF_ERROR2, PH_COMP_HAL2);
	}
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_FieldOff2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	switch(g_bFieldOffState2)
	{
		case PHHAL_HW_STATE_IDLE2: /* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_SET_EMD2, PH_OFF2));
			PH_CHECK_SUCCESS2(statusTmp2);
			g_bFieldOffState2 = PHHAL_HW_STATE_CMD12;
			/*No break*/
		case PHHAL_HW_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_RfOff2(pDataParams2));
			g_bFieldOffState2 = PHHAL_HW_STATE_IDLE2;
			/*No break*/
	}
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_FieldReset2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
    switch(pDataParams2->bFieldResetState2)
    {
        case PHHAL_FIELD_RESET_STATE_FIELD_OFF2:
            /* Switch off the field */
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_FieldOff2(pDataParams2));
            if(statusTmp2 == PH_ERR_SUCCESS2)
            {
                pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_OFF_WAIT2;
                return PH_STATUS_INPROCESS2;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_OFF_WAIT2:
            /* Check for field-off timeout */
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Wait2(pDataParams2,PHHAL_HW_TIME_MILLISECONDS2, pDataParams2->wFieldOffTime2));
            if(statusTmp2 == PH_ERR_SUCCESS2)
            {
                pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_ON2;
                return PH_STATUS_INPROCESS2;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_ON2:
            /* Switch on the field again */
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_FieldOn2(pDataParams2));
            if(statusTmp2 == PH_ERR_SUCCESS2)
            {
                pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_ON_WAIT2;
                return PH_STATUS_INPROCESS2;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_ON_WAIT2:
            /* Check for field-recovery timeout */
            PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Wait2(pDataParams2,PHHAL_HW_TIME_MILLISECONDS2, pDataParams2->wFieldRecoveryTime2));
            break;
    }
    pDataParams2->bFieldResetState2 = PHHAL_FIELD_RESET_STATE_FIELD_OFF2;
    return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_ApplyProtocolSettings2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        VAR(uint8, ANFCRL_VAR) bCardType2
												)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwRegisterValue2 = 0x00U;
	P2VAR(phApplyProtocolParam_t2, AUTOMATIC, ANFCRL_APPL_DATA) pBackup2 = &g_sApplyProtocolParam2;

	switch (g_bApplyProtocolState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			/* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_SET_EMD2, PH_OFF2));
			PH_CHECK_SUCCESS2(statusTmp2);
			pBackup2->pShadowDefault2 = NULL;
			/* Store new card type */
			if (bCardType2 != PHHAL_HW_CARDTYPE_CURRENT2)
			{
				pDataParams2->bCardType2 = bCardType2;
				pDataParams2->bTimeoutUnit2 = PHHAL_HW_TIME_MICROSECONDS2;
				pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2] = 0;
				pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2] = 0;
				pBackup2->bUseDefaultShadow2 = 1U;
			}
			else
			{
				pBackup2->bUseDefaultShadow2 = 0U;
			}

			pDataParams2->bActiveMode2 = PH_OFF2;
			pDataParams2->wTargetMode2 = PH_OFF2;
			pDataParams2->bJewelActivated2 = PH_OFF2;
			pDataParams2->bNfcipMode2 = PH_OFF2;

			g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD12;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHHAL_HW_STATE_CMD12:
			/* Configure reader IC for current card */
			switch (pDataParams2->bCardType2)
			{
				/* configure hardware for ISO 14443A */
				case PHHAL_HW_CARDTYPE_ISO14443A2:
					/* Use 14443a default shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_ISO14443A_106_MILLER2,
									PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC2));
					if (statusTmp2 == PH_ERR_SUCCESS2)
					{
						SET_NCX3321_SHADOW2(wNcx3321_DefaultShadow_I14443a2);
					}
					break;

				case PHHAL_HW_CARDTYPE_ISO14443B2:
					/* Use 14443b shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_ISO14443B_106_NRZ2,
									PHHAL_HW_NCX3321_RF_RX_ISO14443B_106_BPSK2));
					if (statusTmp2 == PH_ERR_SUCCESS2)
					{
						SET_NCX3321_SHADOW2(wNcx3321_DefaultShadow_I14443b2);
					}
					break;

				case PHHAL_HW_CARDTYPE_FELICA_2122:
					/* Use Felica shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_FELICA_2122, PHHAL_HW_NCX3321_RF_RX_FELICA_2122));
					if (statusTmp2 == PH_ERR_SUCCESS2)
					{
						SET_NCX3321_SHADOW2(wNcx3321_DefaultShadow_Felica2);
					}
					break;

				case PHHAL_HW_CARDTYPE_FELICA_4242:
					/* Use Felica shadow for 424*/
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_FELICA_4242, PHHAL_HW_NCX3321_RF_RX_FELICA_4242));
					if (statusTmp2 == PH_ERR_SUCCESS2)
					{
						SET_NCX3321_SHADOW2(wNcx3321_DefaultShadow_Felica_4242);
					}
					break;

				case PHHAL_HW_CARDTYPE_ISO156932:
					/* Use 15693 shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration2(pDataParams2, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK1002,
									PHHAL_HW_NCX3321_RF_RX_ISO15693_26_SC2));
					if (statusTmp2 == PH_ERR_SUCCESS2)
					{
						SET_NCX3321_SHADOW2(wNcx3321_DefaultShadow_I156932);
					}
					break;

				default:
					statusTmp2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					break;
			}
			PH_BREAK_ON_FAILURE2(statusTmp2);
			/* Copy over default shadow contents into current shadow. */
			if (0U != pBackup2->bUseDefaultShadow2)
			{
				/* Initialize config shadow */
				(void) memset(pDataParams2->wCfgShadow2, 0x00, (sizeof(uint16) * PHHAL_HW_NCX3321_SHADOW_COUNT2));
				pBackup2->wIndex2 = 0U;
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD22;
			}
			else
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD32;
			}
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHHAL_HW_STATE_CMD22:
			if (pBackup2->wIndex2 < (pBackup2->wShadowCount2))
			{
				pBackup2->wConfig2 = pBackup2->pShadowDefault2[(pBackup2->wIndex2) << 1U];

				/* Updated TxCRC and RxCRC in shadow due to LoadRFConfig */
				if ((pBackup2->wConfig2 == PHHAL_HW_CONFIG_TXCRC2) || (pBackup2->wConfig2 == PHHAL_HW_CONFIG_RXCRC2) || (pBackup2->wConfig2 == PHHAL_HW_CONFIG_TRXCRC2))
				{
					if (pDataParams2->bCardType2 == PHHAL_HW_CARDTYPE_ISO14443B2)
					{
						PH_CHECK_INPROCESS_FCT2(statusTmp2,
								phhalHw_Ncx3321_SetConfig2(pDataParams2, pBackup2->wConfig2, pBackup2->pShadowDefault2[((pBackup2->wIndex2) << 1U) + 1U]));
					}
					else
					{
						/* Write config data into shadow */
						pDataParams2->wCfgShadow2[pBackup2->wConfig2] = pBackup2->pShadowDefault2[((pBackup2->wIndex2) << 1U) + 1U];
					}
				}

				/* Configure the RxWait using Shadow values */
				if (pBackup2->wConfig2 == PHHAL_HW_CONFIG_RXWAIT_US2)
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2,
							phhalHw_Ncx3321_SetConfig2(pDataParams2, pBackup2->wConfig2, pBackup2->pShadowDefault2[((pBackup2->wIndex2) << 1U) + 1U]));
				}

				/* Configure the TxWait using Shadow values */
				if (pBackup2->wConfig2 == PHHAL_HW_CONFIG_TXWAIT_US2)
				{
					if (((pDataParams2->bCardType2 == PHHAL_HW_CARDTYPE_ISO14443A2) || (pDataParams2->bCardType2 == PHHAL_HW_CARDTYPE_ISO14443B2))
							&& (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2))
					{
						/* Configure TxWait of 500 micro seconds in EMVCo mode. */
						PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig2(pDataParams2, pBackup2->wConfig2, 500U));
					}
					else
					{
						PH_CHECK_INPROCESS_FCT2(statusTmp2,
								phhalHw_Ncx3321_SetConfig2(pDataParams2, pBackup2->wConfig2, pBackup2->pShadowDefault2[((pBackup2->wIndex2) << 1U) + 1U]));
					}
				}
				if (statusTmp2 == PH_ERR_SUCCESS2)
				{
					pDataParams2->wCfgShadow2[pBackup2->wConfig2] = pBackup2->pShadowDefault2[((pBackup2->wIndex2) << 1U) + 1U];
					++(pBackup2->wIndex2);
				}
				else
				{
					/*if any error return*/
					break;
				}
				return PH_STATUS_INPROCESS2;
			}
			g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD32;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHHAL_HW_STATE_CMD32:
			/* MIFARE Crypto1 state is disabled by default */
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO12, PH_ON2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			/* Configure value of the CLIF_SS_TX1_RMCFG2 and CLIF_SS_TX2_RMCFG2 registers in case it is reset after LPCD */
			if(0U != pDataParams2->bSsTx1ConfigIsConfigured2)
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD42;
			}
			else
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD62;
			}
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHHAL_HW_STATE_CMD42:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, CLIF_SS_TX1_RMCFG2, &dwRegisterValue2));
			if(pDataParams2->dwSetSsTx1ConfigValue2 != dwRegisterValue2)
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD52;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Do nothing */
			}
			g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD62;
			return PH_STATUS_INPROCESS2;
			/* no break */
		case PHHAL_HW_STATE_CMD52:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_SS_TX1_RMCFG2, pDataParams2->dwSetSsTx1ConfigValue2));
			PH_BREAK_ON_FAILURE2(statusTmp2);
			if(0U != pDataParams2->bSsTx2ConfigIsConfigured2)
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD62;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Do nothing */
			}
			break;
		case PHHAL_HW_STATE_CMD62:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, CLIF_SS_TX2_RMCFG2, &dwRegisterValue2));
			if(pDataParams2->dwSetSsTx2ConfigValue2 != dwRegisterValue2)
			{
				g_bApplyProtocolState2 = PHHAL_HW_STATE_CMD72;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				/* Do nothing */
			}
			break;
		case PHHAL_HW_STATE_CMD72:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_SS_TX2_RMCFG2, pDataParams2->dwSetSsTx2ConfigValue2));
			break;
		default:
			statusTmp2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}

	g_bApplyProtocolState2 = PHHAL_HW_STATE_IDLE2;
	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wConfig2,
                  VAR(uint16, ANFCRL_VAR) wValue2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSizeOfRegTypeValueSets2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwRegister2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTemp2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwValue2 = 0U;
	VAR(double, ANFCRL_VAR) PH_MEMLOC_REM2 fTime2 = 0.0;	/* NIDEC_PORTING */
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 wRegTypeValueSets2[12] = {0U};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pBuffer2 = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferSize2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferLen2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSetConfigState2 = 0U;

	/* Check if Apply Protocol is already done. */
	if (pDataParams2->bCardType2 == PHHAL_HW_CARDTYPE_UNKNOWN2)
	{
		return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
	}

	switch(wConfig2)
	{
		case PHHAL_HW_CONFIG_TXBUFFER_OFFSET2:
			/* Update TX buffer offset based on the command used to buffer the data in HAL. */
			if(*pDataParams2->pTxBuffer2 == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA2)
			{
				pDataParams2->wAdditionalInfo2 = wValue2 + PHHAL_HW_NCX3321_EXCHANGE_HEADER_SIZE2;
			}
			else
			{
				pDataParams2->wAdditionalInfo2 = wValue2 + PHHAL_HW_NCX3321_TRANSMIT_HEADER_SIZE2;
			}
			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				 pDataParams2->wAdditionalInfo2 += 1U;
			}
			break;

		case PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2:
			/* Retrieve RxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetRxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Boundary check */
			if (wValue2 >= pDataParams2->wRxBufSize2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_HAL2);
			}

			/* Set start position */
			pDataParams2->wRxBufStartPos2 = wValue2;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_LENGTH2:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Check parameter, must not exceed TxBufferSize */
			if (wValue2 > pDataParams2->wTxBufSize2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_HAL2);
			}
			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				wValue2++;
			}
			/* set buffer length */
			pDataParams2->wTxBufLen2 = wValue2;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER2:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Check parameter, must not exceed TxBufferSize */
			if (pDataParams2->wAdditionalInfo2 >= pDataParams2->wTxBufSize2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_HAL2);
			}

			pBuffer2[pDataParams2->wAdditionalInfo2] = (uint8)wValue2;

			break;

		case PHHAL_HW_CONFIG_TXDATARATE_FRAMING2:

			PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Int_SetTxDataRateFraming2(pDataParams2,wConfig2,wValue2));
			break;

		case PHHAL_HW_CONFIG_RXDATARATE_FRAMING2:

			if(0U == bSetConfigState2)
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Int_SetRxDataRateFraming2(pDataParams2,wConfig2,wValue2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				bSetConfigState2 = 1U;
			}

			if(1U == bSetConfigState2)
			{
				if (((pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXDATARATE_FRAMING2] & PHHAL_HW_RF_DATARATE_OPTION_MASK2) != PHHAL_HW_RF_DATARATE_1062)
					&& ((pDataParams2->wCfgShadow2[wConfig2] & PHHAL_HW_RF_DATARATE_OPTION_MASK2) == PHHAL_HW_RF_DATARATE_1062))
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(pDataParams2, PHHAL_HW_CONFIG_RXWAIT_US2, 70U));
					PH_BREAK_ON_FAILURE2(statusTmp2);
					bSetConfigState2 = 0U;
				}
			}
			break;

		case PHHAL_HW_CONFIG_RFCA2:

			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			pDataParams2->bRfca2 = (uint8) wValue2;
			break;


		case PHHAL_HW_CONFIG_SUBCARRIER2:

			if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
			{
				switch(g_bSetConfigState2)
				{
					case PHHAL_HW_STATE_IDLE2:
						/* Parameter check */
						if (pDataParams2->bCardType2 != PHHAL_HW_CARDTYPE_ISO156932)
						{
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
						}

						/* Only single subcarrier to be used while reception by ISO15693 */
						if ((pDataParams2->bCardType2 == PHHAL_HW_CARDTYPE_ISO156932) && (wValue2 != PHHAL_HW_SUBCARRIER_SINGLE2))
						{
							return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
						}
						g_bSetConfigState2 = PHHAL_HW_STATE_CMD12;
						/* no break */
					case PHHAL_HW_STATE_CMD12:
						/* Evaluate hardware settings */
						PH_CHECK_INPROCESS_FCT2(statusTmp2,phhalHw_Ncx3321_Int_SetCardMode2(
								pDataParams2,
								pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXDATARATE_FRAMING2],
								pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_RXDATARATE_FRAMING2],
								wValue2));
						PH_BREAK_ON_FAILURE2(statusTmp2);
						/* Update Subcarrier setting */
						pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_SUBCARRIER2] = wValue2;
						break;
					default:
						break;
				}
				g_bSetConfigState2 = PHHAL_HW_STATE_IDLE2;
			}

			break;

		case PHHAL_HW_CONFIG_POLL_GUARD_TIME_US2:
			if ((wValue2 == 0x00U) || (pDataParams2->bPollGuardTimeFlag2 == PH_ON2))
			{
				return PH_ERR_SUCCESS2;
			}

			pDataParams2->bPollGuardTimeFlag2 = PH_ON2;
			(void)phTools_EventClear2(
				&pDataParams2->HwEventObj2,
				E_EVENT_OPT_NONE2,
				E_EVENT_GT_EXP2,
				NULL);

			pDataParams2->wGuardTimeStart2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
			pDataParams2->wGuardTimePeriod2 = wValue2;
			break;

		case PHHAL_HW_CONFIG_OPE_MODE2:
			pDataParams2->bOpeMode2 = (uint8) wValue2;
			break;

		case PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT2:

			if (wValue2 == PH_OFF2)
			{
				pDataParams2->bRfResetAfterTo2 = PH_OFF2;
			}
			else
			{
				pDataParams2->bRfResetAfterTo2 = PH_ON2;
			}

			break;

		case PHHAL_HW_CONFIG_PARITY2:
		case PHHAL_HW_CONFIG_ASK1002:
		case PHHAL_HW_CONFIG_RXWAIT_US2:
			if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
			{
				/* Use internal set config */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(pDataParams2, wConfig2, wValue2));
				PH_CHECK_SUCCESS2(statusTmp2);

				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
			}
			break;

		case PHHAL_HW_CONFIG_TXCRC2:
		case PHHAL_HW_CONFIG_RXCRC2:
		case PHHAL_HW_CONFIG_TRXCRC2:
			/* Check shadow while performing configuration in EMVCo mode, to have good timing performance.
			 * As in EMVCo mode ApplyProtocolSettings shall always be followed by FieldOn function. */
			if (pDataParams2->bOpeMode2 == RD_LIB_MODE_EMVCO2)
			{
				if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
				{
					/* Use internal set config */
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(pDataParams2, wConfig2, wValue2));
					PH_CHECK_SUCCESS2(statusTmp2);
				}
			}
			else
			{
				/* NOTE : Do not perform shadow check, as FieldOn function of NCX3321 FW performs
				 * LoadRFConfiguration of previously applied Protocol configuration and the shadow
				 * value of HAL for Tx and Rx CRC doesn't have the value that is configured on CLIF. */

				/* Use internal set config */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(pDataParams2, wConfig2, wValue2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}

			/* Write config data into shadow */
			pDataParams2->wCfgShadow2[wConfig2] = wValue2;
			break;

		case PHHAL_HW_CONFIG_TXLASTBITS2:

			if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
			{
				/* Check parameter */
				if (wValue2 > MASK_TX_LASTBITS2)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}

				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
			}
			break;

		case PHHAL_HW_CONFIG_RXALIGN2:

			if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
			{
				/* Check the parameter */
				if (wValue2 >  MASK_RX_LASTBITS2)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_ClearNSetRegFields2(pDataParams2,
							CLIF_RX_PROTOCOL_CONFIG2, CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_MASK2,
							CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_POS2, wValue2));
				PH_CHECK_SUCCESS2(statusTmp2);
				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
			}
			break;

		case PHHAL_HW_CONFIG_TXWAIT_US2:

			if (pDataParams2->wCfgShadow2[wConfig2] != wValue2)
			{
				/* Set TxWait */
				dwValue2 = PHHAL_HW_NCX3321_TX_RX_PRESCALER2;
				dwTemp2 = wValue2;

				if(0U != dwTemp2)
				{
					fTime2 = (double)(((double)dwTemp2 * 13.56) / (double)(dwValue2));	/* NIDEC_PORTING */
					dwTemp2 = (uint32)fTime2;
					dwValue2 |= (uint32)((dwTemp2 ) << CLIF_TX_WAIT_TX_WAIT_VALUE_POS2);
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_TX_WAIT2, dwValue2));
					PH_CHECK_SUCCESS2(statusTmp2);
				}
				else
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_TX_WAIT2, dwValue2));
					PH_CHECK_SUCCESS2(statusTmp2);
				}

				/* Write configuration data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
			}
			break;

		case PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO12:
			/* Disable crypto, enabling is not supported */
			if ((wValue2 != PH_OFF2) && ( pDataParams2->bMfcCryptoEnabled2 == PH_ON2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, SYSTEM_CONFIG2, (~((uint32)SYSTEM_CONFIG_MFC_CRYPTO_ON_MASK2))));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				pDataParams2->bMfcCryptoEnabled2 = PH_OFF2;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2:
			if ((pDataParams2->wCfgShadow2[wConfig2] != wValue2) ||
				(pDataParams2->bTimeoutUnit2 != PHHAL_HW_TIME_MICROSECONDS2) ||
				(pDataParams2->bOpeMode2 != RD_LIB_MODE_EMVCO2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetTmo2(pDataParams2, wValue2, PHHAL_HW_TIME_MICROSECONDS2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
				pDataParams2->bTimeoutUnit2 = PHHAL_HW_TIME_MICROSECONDS2;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2:
			if ((pDataParams2->wCfgShadow2[wConfig2] != wValue2) ||
				(pDataParams2->bTimeoutUnit2 != PHHAL_HW_TIME_MILLISECONDS2) ||
				(pDataParams2->bOpeMode2 != RD_LIB_MODE_EMVCO2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetTmo2(pDataParams2, wValue2, PHHAL_HW_TIME_MILLISECONDS2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				/* Write config data into shadow */
				pDataParams2->wCfgShadow2[wConfig2] = wValue2;
				pDataParams2->bTimeoutUnit2 = PHHAL_HW_TIME_MILLISECONDS2;
			}
			break;

		case PHHAL_HW_CONFIG_NFCIP_STARTBYTE2:
			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			pDataParams2->bNfcipMode2 = (uint8) wValue2;
			break;

		case PHHAL_HW_CONFIG_JEWEL_MODE2:

			if (wValue2 == PH_ON2)
			{
				pDataParams2->bJewelActivated2 = (uint8) wValue2;
				/* Enable FrameStep in Transceiver Control Register. */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterOrMask2( pDataParams2, CLIF_TRANSCEIVE_CONTROL2, CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else if (wValue2 == PH_OFF2)
			{
				pDataParams2->bJewelActivated2 = (uint8) wValue2;
				/* Disable FrameStep in Transceiver Control Register. */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2( pDataParams2, CLIF_TRANSCEIVE_CONTROL2, ~((uint32)CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_MASK2)));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			break;

		case PHHAL_HW_CONFIG_SET_EMD2:
			if (pDataParams2->bEmdFlag2 != wValue2)
			{
				if(0U == bSetConfigState2)
				{
					pDataParams2->bEmdFlag2 = (uint8) wValue2;
					if (wValue2 == 0x1U)
					{
						dwRegister2 = 0U;
						if (pDataParams2->bCardType2 != PHHAL_HW_CARDTYPE_ISO14443A2)
						{
							/* Read the EMD CONTROL Register to get RM EMD SENSITIVITY field */
							PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, EMD_CONTROL2, &dwRegister2));
							PH_CHECK_SUCCESS2(statusTmp2);
							/* Retain only the RM EMD SENSITIVITY value field.
							 * In case of Type A this value needs to be zero. */
							dwRegister2 &= (uint32)(EMD_CONTROL_EMD_RM_EMD_SENSITIVITY_MASK2);
						}

						if(pDataParams2->bOpeMode2 != RD_LIB_MODE_ISO2)
						{
							dwRegister2 |= PHHAL_HW_NCX3321_EMD_3P02;
						}
						else
						{
							dwRegister2 |= PHHAL_HW_NCX3321_ISO_EMD2;
						}
						bSetConfigState2 = 1U;
					}
					else
					{
						bSetConfigState2 = 2U;
					}
				}

				if(1U == bSetConfigState2)
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, EMD_CONTROL2, dwRegister2));
				}

				if(2U == bSetConfigState2)
				{
					/* Clear EMD Enable bit in EMD Control Register */
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, EMD_CONTROL2, (~(uint32)EMD_CONTROL_EMD_ENABLE_MASK2)));
				}

				bSetConfigState2 = 0U;
			}
			break;

		case PHHAL_HW_CONFIG_RXMULTIPLE2:

			if (wValue2 == PH_ON2)
			{
				pDataParams2->bRxMultiple2 = PH_ON2;

				/* Enable Rx Multiple in Transceiver Control Register. */
				dwTemp2 = CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TRANSCEIVE_CONTROL2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/* Reset Timer1 (FDT Timer) stop condition. */
				dwTemp2 = (uint32) ~(CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				pDataParams2->bRxMultiple2 = PH_OFF2;

				/* Disable Rx Multiple in Transceiver Control Register. */
				dwTemp2 = ~((uint32 )CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TRANSCEIVE_CONTROL2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				/* Set Timer1 (FDT Timer) stop condition to Stop on RX Start condition. */
				dwTemp2 = CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;

		case PHHAL_HW_CONFIG_MFHALTED2:
			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			if (wValue2 == PH_ON2)
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterOrMask2(pDataParams2, SYSTEM_CONFIG2, SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
				pDataParams2->bCardMode2 = PH_ON2;
			}
			else
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, SYSTEM_CONFIG2, ~((uint32)SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK2)));
				PH_CHECK_SUCCESS2(statusTmp2);
				pDataParams2->bCardMode2 = PH_OFF2;
			}
			break;

		case PHHAL_HW_CONFIG_FIELD_OFF_TIME2:
			/* Off time shall not be zero. */
			if (wValue2 == 0U)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* Store off time. */
			pDataParams2->wFieldOffTime2 = wValue2;
			break;

		case PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME2:
			/* Store recovery time. */
			pDataParams2->wFieldRecoveryTime2 = wValue2;
			break;

		case PHHAL_HW_CONFIG_SET_SYMBOL_SEND2:

			/* check parameter */
			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* PH_ON2 implies Clearing Bit-3 (DataEn Bit in TxDataNum). */
			if (wValue2 == PH_ON2)
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, CLIF_TX_FRAME_CONFIG2, ~(uint32)CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			/* PH_OFF2 implies Setting Bit-3 (DataEn Bit in TxDataNum). */
			else
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterOrMask2(pDataParams2, CLIF_TX_FRAME_CONFIG2, CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			break;


		case PHHAL_HW_CONFIG_SYMBOL_START2:

			/* Parameter check */
			if (pDataParams2->bCardType2 != PHHAL_HW_CARDTYPE_ISO156932)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
			}

			/* Parameter check #2 */
			switch (wValue2)
			{
				case PHHAL_HW_SYMBOL_I15693_SOF2:
					if (pDataParams2->bCardType2 != PHHAL_HW_CARDTYPE_ISO156932)
					{
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
					}
					break;
				case PH_OFF2:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
			}

			wSizeOfRegTypeValueSets2 = 0U;

			/*Clear the Bits of TX_CONFIG_TX_START_SYMBOL_MASK & DATA_ENABLE*/
			if (wValue2 == PH_OFF2)
			{
				dwTemp2 = (uint32) ~(CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK2 | CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK2);
			}
			else
			{
				dwTemp2 =  ~((uint32)CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK2);
			}

			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TX_FRAME_CONFIG2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

			dwValue2 = 0U;

			/* Set new symbol */
			switch (wValue2)
			{
				case PHHAL_HW_SYMBOL_I15693_SOF2:
					dwValue2 = 0x3U;
					break;
				default:
					break;
			}

			/*Set the new value  */
			dwTemp2 = (uint32) ((dwValue2 << CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_POS2) & CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK2);
			dwTemp2 |= (uint32) ((dwValue2 << CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_POS2) & CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TX_FRAME_CONFIG2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwTemp2 >> 24U);

			/*Send the array to the IC*/
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_CRCTYPE2:

			if(0U == (wValue2 & (PHHAL_HW_CRCTYPE_CRC52 | PHHAL_HW_CRCTYPE_CRC162 | PHHAL_HW_CRCOPTION_INVERTED2)))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			dwValue2 = 0U;
			/*dwRegister2 will contain all the bits that need to be zeroed out*/
			dwRegister2 = 0U;

			if(0U != (wValue2 & PHHAL_HW_CRCTYPE_CRC162))
			{
				dwRegister2 |= CLIF_CRC_TX_CONFIG_TX_CRC_TYPE_MASK2;
			}
			else
			{
				/* QAC */
			}

			if(0U != (wValue2 & PHHAL_HW_CRCOPTION_INVERTED2))
			{
				dwValue2 |= CLIF_CRC_TX_CONFIG_TX_CRC_INV_MASK2;
			}
			else
			{
				dwRegister2 |= CLIF_CRC_TX_CONFIG_TX_CRC_INV_MASK2;
			}

			if (0U != ((wValue2 & PHHAL_HW_CRCTYPE_CRC162)))
			{
				dwRegister2 |= CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_MASK2;
				dwValue2 |= (0x3U << CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_POS2);
			}


			wSizeOfRegTypeValueSets2 = 0U;

			/*Clear the Bits */
			dwTemp2 = (uint32) ~( dwRegister2 );
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

			/*Set the new value  */
			dwTemp2 = dwValue2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_CRC_TX_CONFIG2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>8U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>16U);
			wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8)(dwTemp2>>24U);

			/*Send the array to the IC*/
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2,  wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
			PH_CHECK_SUCCESS2(statusTmp2);

			break;

		case PHHAL_HW_CONFIG_TXWAIT_MS2:
			/* Parameter checking */
			if (wValue2 > 650U) /* To set Max value for wValue2 in uS i.e, 0xFFFFU )*/
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			/* Store the value in terms of uS in shadow table*/
			pDataParams2->dwTxWaitMs2 =  wValue2;

			/* Set TxWait */
			dwValue2 = PHHAL_HW_NCX3321_TX_RX_PRESCALER2;
			dwTemp2 = (uint32)wValue2*1000U;
			if(0U != dwTemp2)
			{
				fTime2 = (double)(((double)dwTemp2 * 13.56) / (double)(dwValue2));	/* NIDEC_PORTING */
				dwTemp2 = (uint32)fTime2;
				dwValue2 |= (uint32)((dwTemp2 ) << CLIF_TX_WAIT_TX_WAIT_VALUE_POS2);
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_TX_WAIT2, dwValue2));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, CLIF_TX_WAIT2, dwValue2));
			}
			break;

		case PHHAL_HW_CONFIG_SETMINFDT2:

			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_SetMinFdt2(pDataParams2, wValue2));
			break;

		case PHHAL_HW_CONFIG_RFON_INTERRUPT2:
			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			if (wValue2 == PH_ON2)
			{
				/* This will Enable RF-ON Interrupt in NCX3321. NCX3321 will send PH_NCX3321_EVT_RFON_DETECT2
				 * after RF-ON interrupt*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, EVENT_ENABLE2, EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK2));
				PH_BREAK_ON_FAILURE2(statusTmp2);
				pDataParams2->dwExpectedEvent2 = PH_NCX3321_EVT_RFON_DETECT2;
			}
			else
			{
				/* Disable RF-ON Interrupt*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, EVENT_ENABLE2, ~(uint32)EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK2));
			}
			break;

		case PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_STATUS2:
			/* check parameter */
			if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			pDataParams2->bCTSEvent2 = (uint8)wValue2;
			break;

		case PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_ENABLE2:
			if (wValue2 == PH_ON2)
			{
				/* Enable CTS Event Interrupt*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, EVENT_ENABLE2, EVENT_ENABLE_CTS_EVENT_ENABLE_MASK2));
			}
			else if (wValue2 == PH_OFF2)
			{
				/* Disable CTS Event Interrupt*/
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, EVENT_ENABLE2, ~(uint32)EVENT_ENABLE_CTS_EVENT_ENABLE_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else /* check parameter */
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			break;

		case PHHAL_HW_NCX3321_CONFIG_LPCD_EVENT_ENABLE2:
			if (wValue2 == PH_ON2)
			{
				/* Enable LPCD Event */
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterOrMask2(pDataParams2, EVENT_ENABLE2, EVENT_ENABLE_LPCD_EVENT_ENABLE_MASK2));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else if (wValue2 == PH_OFF2)
			{
				/* Disable LPCD Event */
				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2, EVENT_ENABLE2, ~((uint32)EVENT_ENABLE_LPCD_EVENT_ENABLE_MASK2)));
				PH_CHECK_SUCCESS2(statusTmp2);
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			break;
		case PHHAL_HW_NCX3321_CONFIG_EXPECTED_EVENT2:
			if ((wValue2 < PH_NCX3321_EVT_BOOT2) || (wValue2 >= PH_NCX3321_EVT_RFU2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			pDataParams2->dwExpectedEvent2 = (uint32) wValue2;
			break;

        case PHHAL_HW_NCX3321_CONFIG_RF_ON_EVENT_STATUS2:
            /* check parameter */
            if ((wValue2 != PH_ON2) && (wValue2 != PH_OFF2))
            {
                return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
            }

            pDataParams2->bRFONEvent2 = (uint8)wValue2;
            break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD2:
			if ((wValue2 == PH_ON2) && (pDataParams2->bOpeMode2 != RD_LIB_MODE_FELICA2))
			{
				/* Before Setting FELICA_EMD bit, OpeMode need to be configured to RD_LIB_MODE_FELICA2 */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
			}

			/* Configure FeliCa EMD enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(pDataParams2, wValue2, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_ENABLE_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_CHECK2:
			/* Configure EMD length byte check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(pDataParams2, wValue2, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_LEN_CHECK_ENABLE_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_CHECK2:
			/* Configure RC byte check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(pDataParams2, wValue2, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_RC_CHECK_ENABLE_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_PROTOCOL_ERR_CHECK2:
			/* Configure Protocol error check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(pDataParams2, wValue2, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_PROTOCOL_ERR_CHECK_ENABLE_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_INTEGRITY_ERR_CHECK2:
			/* Configure Integrity error check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit2(pDataParams2, wValue2, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_INTEGRITY_ERR_CHECK_ENABLE_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MIN2:
			/* Configure min length byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte2(
					pDataParams2,
					wValue2,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_POS2,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_MASK2));
			PH_CHECK_SUCCESS2(statusTmp2);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MAX2:
			/* Configure max length byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_SUCCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte2(
					pDataParams2,
					wValue2,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_POS2,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_MASK2));
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_BYTE_VAL2:
			/* Configure RC byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_SUCCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte2(
					pDataParams2,
					wValue2,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_POS2,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_MASK2));
			break;
		case PHHAL_HW_CONFIG_REQAEX2:
			/*This state is a combination of 3 states:
			 * PHHAL_HW_CONFIG_RXWAIT_US2,
			 * PHHAL_HW_CONFIG_TXCRC2,
			 * PHHAL_HW_CONFIG_RXCRC2
			 * */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig_Int2(pDataParams2, wConfig2, wValue2));

			break;
		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
	}

	bSetConfigState2 = 0U;
	return statusTmp2;
}


FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_GetConfig2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wConfig2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
									)
{
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferLen2;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wBufferSize2;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwRegister2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pBuffer2;

	switch(wConfig2)
	{
		case PHHAL_HW_CONFIG_OPE_MODE2:
			*pValue2 = pDataParams2->bOpeMode2;
			break;

		case PHHAL_HW_CONFIG_SET_EMD2:
			*pValue2 = pDataParams2->bEmdFlag2;
			break;
		case PHHAL_HW_CONFIG_PARITY2:
		case PHHAL_HW_CONFIG_TXCRC2:
		case PHHAL_HW_CONFIG_RXCRC2:
		case PHHAL_HW_CONFIG_TXLASTBITS2:
		case PHHAL_HW_CONFIG_TXDATARATE_FRAMING2:
		case PHHAL_HW_CONFIG_RXDATARATE_FRAMING2:
		case PHHAL_HW_CONFIG_ASK1002:
		case PHHAL_HW_CONFIG_SUBCARRIER2:
		case PHHAL_HW_CONFIG_TXWAIT_US2:
		case PHHAL_HW_CONFIG_RXWAIT_US2:

		  /* Read config from shadow */
		  *pValue2 = pDataParams2->wCfgShadow2[wConfig2];
		  break;

		case PHHAL_HW_CONFIG_TXBUFFER_OFFSET2:
		case PHHAL_HW_CONFIG_RXLASTBITS2:

			*pValue2 = pDataParams2->wAdditionalInfo2;
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2:

			if (pDataParams2->bTimeoutUnit2 == PHHAL_HW_TIME_MICROSECONDS2)
			{
				*pValue2 = pDataParams2->wCfgShadow2[wConfig2];
			}
			else
			{
				if (pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2] > (0xFFFFU / 1000U))
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_PARAMETER_OVERFLOW2, PH_COMP_HAL2);
				}
				*pValue2 = pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2] * 1000U;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS2:

			if (pDataParams2->bTimeoutUnit2 == PHHAL_HW_TIME_MILLISECONDS2)
			{
				*pValue2 = pDataParams2->wCfgShadow2[wConfig2];
			}
			else
			{
				*pValue2 = pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TIMEOUT_VALUE_US2] / 1000U;
			}
			break;

		case PHHAL_HW_CONFIG_FIELD_OFF_TIME2:

			*pValue2 = pDataParams2->wFieldOffTime2;
			break;

		case PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME2:

			*pValue2 = pDataParams2->wFieldRecoveryTime2;
			break;

		case PHHAL_HW_CONFIG_JEWEL_MODE2:

			/* Write configuration data into shadow */
			*pValue2 = pDataParams2->bJewelActivated2;
			break;

		case PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT2:

			*pValue2 = pDataParams2->bRfResetAfterTo2;
			break;

		case PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO12:

			/* Check Crypto1On Status */
			if ( pDataParams2->bMfcCryptoEnabled2 == PH_ON2)
			{
				*pValue2 = PH_OFF2; /* OFF in this case means "Crypto1 not disabled --> enabled" */
			}
			else
			{
				*pValue2 = PH_ON2; /* ON in this case means "Crypto1 is disabled" */
			}
			break;


		case PHHAL_HW_CONFIG_RXBUFFER_STARTPOS2:

			/* Return parameter */
			*pValue2 = pDataParams2->wRxBufStartPos2;
			break;

		case PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE2:

			/* Retrieve RxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetRxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Return parameter */
			*pValue2 = wBufferSize2;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE2:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Return parameter */
			*pValue2 = wBufferSize2;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_LENGTH2:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));
			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				if (wBufferLen2 != 0U)
				{
					wBufferLen2--;
				}
			}
			/* Return parameter */
			*pValue2 = wBufferLen2;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER2:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Int_GetTxBuffer2(pDataParams2, &pBuffer2, &wBufferLen2, &wBufferSize2));

			/* Check additional info parameter */
			if (pDataParams2->wAdditionalInfo2 >= pDataParams2->wTxBufSize2)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_BUFFER_OVERFLOW2, PH_COMP_HAL2);
			}

			/* Retrieve TxBuffer byte */
			*pValue2 = (uint16)pBuffer2[pDataParams2->wAdditionalInfo2];
			break;

		case PHHAL_HW_CONFIG_RXMULTIPLE2:
			*pValue2 =  pDataParams2->bRxMultiple2;
			break;

		case PHHAL_HW_CONFIG_NFCIP_STARTBYTE2:
			*pValue2 = pDataParams2->bNfcipMode2;
			break;

		case PHHAL_HW_CONFIG_TARGET_DATARATE_FRAMING2:
			*pValue2 = pDataParams2->wTargetMode2;
			break;

		case PHHAL_HW_CONFIG_ACTIVEMODE2:
			/* Return parameter */
			*pValue2 = (uint16)pDataParams2->bActiveMode2;
			break;

		case PHHAL_HW_CONFIG_CARD_TYPE2:
			*pValue2 = pDataParams2->bCardType2;
			break;

		case PHHAL_HW_CONFIG_MFHALTED2:
			PH_CHECK_INPROCESS_FCT2(statusTmp2,
				phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, SYSTEM_CONFIG2, &dwRegister2));
			PH_CHECK_SUCCESS2(statusTmp2);
			if(0U != (dwRegister2 & SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK2))
			{
				*pValue2 = PH_ON2;
			}
			else
			{
				*pValue2 = PH_OFF2;
			}
			break;

		case PHHAL_HW_CONFIG_INT_RF_ON2:

			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, CLIF_STATUS2, &dwRegister2));
			PH_CHECK_SUCCESS2(statusTmp2);
			if((dwRegister2 & CLIF_STATUS_TX_RF_STATUS_MASK2 ) == CLIF_STATUS_TX_RF_STATUS_MASK2)
			{
				*pValue2 = PH_ON2;
			}
			else
			{
				*pValue2 = PH_OFF2;
			}
			break;

		default:
			return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
	}

	return statusTmp2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_SetListenParameters2(
                        P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSensRes2,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNfcId12,
                        VAR(uint8, ANFCRL_VAR) bSelRes2,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPollingResp2,
                        VAR(uint8, ANFCRL_VAR) bNfcId32
											  )
{
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 aCmd2[PHHAL_HW_NCX3321_SET_LISTEN_LEN2];
	UNUSED2(bNfcId32);
	VAR(phStatus_t2, ANFCRL_VAR) status2 = PH_ERR_SUCCESS2;

	switch(g_bSetListenParamsState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			(void)memcpy(&aCmd2[0], pSensRes2, PHHAL_HW_NCX3321_SET_LISTEN_SENRES_LEN2);
			(void)memcpy(&aCmd2[2], pNfcId12, PHHAL_HW_NCX3321_SET_LISTEN_NFCID1_LEN2);
			(void)memcpy(&aCmd2[5], &bSelRes2, PHHAL_HW_NCX3321_SET_LISTEN_SELRES_LEN2);
			(void)memcpy(&aCmd2[6], pPollingResp2, PHHAL_HW_NCX3321_SET_LISTEN_POLLRES_LEN2);
			g_bSetListenParamsState2 = PHHAL_HW_STATE_CMD12;
			/* no break */
		case PHHAL_HW_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteE2Prom2(pDataParams2, PHHAL_HW_NCX3321_SET_LISTEN_EEPROM_ADDR2, aCmd2, PHHAL_HW_NCX3321_SET_LISTEN_LEN2));
			break;
	}

	g_bSetListenParamsState2 = PHHAL_HW_STATE_IDLE2;
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Exchange2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wOption2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                  VAR(uint16, ANFCRL_VAR) wTxLength2,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSyncByte2 = 0xf0U;
	static VAR(phStatus_t2, ANFCRL_VAR) statusBackup2 = PH_ERR_SUCCESS2;
	static VAR(uint16, ANFCRL_VAR) wBkpOpt2 = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2;
	static VAR(uint16, ANFCRL_VAR) wRxLength2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bTxLastBits2 = 0U;
	static VAR(uint8, ANFCRL_VAR) bRespConfig2 = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwValue2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF2 wRegTypeValueSets2[12] = { 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wSizeOfRegTypeValueSets2 = 0U;

	switch (g_bExchangeState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			if (pDataParams2->wTargetMode2 != PH_OFF2)
			{
				/* If wTargetMode2 is changed then Target is activated and Exchange should not be used to perform Tx Operation. */
				return (PH_ERR_USE_CONDITION2 | PH_COMP_HAL2);
			}
			/* Check options */
			if (0U != (wOption2 & (uint16)~(uint16)(PH_EXCHANGE_BUFFERED_BIT2 | PH_EXCHANGE_LEAVE_BUFFER_BIT2)))
			{
				return (PH_ERR_INVALID_PARAMETER2 | PH_COMP_HAL2);
			}

			if (pDataParams2->bJewelActivated2 == PH_OFF2)
			{
				bTxLastBits2 = (uint8)pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXLASTBITS2];
			}
			else
			{
				bTxLastBits2 = 0x07U;

				/* Set Timer1 (FDT Timer) start condition to Tx Frame Step detected instead of Tx Ended. */
				dwValue2 = ~((uint32)CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				dwValue2 = CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				PH_CHECK_SUCCESS2(statusTmp2);
				/* Reset for next register write */
				wSizeOfRegTypeValueSets2 = 0U;
			}
			bRespConfig2 = PH_RF_EXCH_CONF_ENABLE_RF_STATUS2 | PH_RF_EXCH_CONF_ENABLE_RX_STATUS2 | PH_RF_EXCH_CONF_ENABLE_EVT_STATUS2;
			g_bExchangeState2 = PHHAL_HW_STATE_CMD12;
			/* No break */
		case PHHAL_HW_STATE_CMD12:
			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				if((wOption2 == PH_EXCHANGE_BUFFER_FIRST2) || (wOption2 == PH_EXCHANGE_DEFAULT2))
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_ExchangeRFData2(
						pDataParams2,
						PH_EXCHANGE_BUFFER_FIRST2,
						0,
						bRespConfig2,
						&bSyncByte2,
						1,
						NULL,
						NULL));
					status2 = statusTmp2;
					PH_BREAK_ON_FAILURE2(status2);
					if(wOption2 == PH_EXCHANGE_BUFFER_FIRST2)
					{
						wOption2 = PH_EXCHANGE_BUFFER_CONT2;
					}
					else
					{
						wOption2 = PH_EXCHANGE_BUFFER_LAST2;
					}
				}
			}
			wBkpOpt2 = wOption2;
			g_bExchangeState2 = PHHAL_HW_STATE_CMD22;
			/*no break*/
		case PHHAL_HW_STATE_CMD22:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ExchangeRFData2(pDataParams2, wBkpOpt2, bTxLastBits2, bRespConfig2,
					pTxBuffer2,wTxLength2,&pRxBuffer2,&wRxLength2));
			if (((status2) & PH_ERR_MASK2) == PH_ERR_ABORTED2)
			{
				break;
			}
			/* Save status2 code value before returning */
			statusBackup2 = status2;
			g_bExchangeState2 = PHHAL_HW_STATE_CMD32;
			/*no break*/

		case PHHAL_HW_STATE_CMD32:
			/* Get status2 value from previous state */
			status2 = statusBackup2;
			if ((status2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2)
			{
				/* Reset after timeout behavior */
				if (pDataParams2->bRfResetAfterTo2 != PH_OFF2)
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_FieldReset2(pDataParams2));
					PH_BREAK_ON_FAILURE2(statusTmp2);
				}
			}

			/* When buffering is enabled, return*/
			if ( ( status2 == PH_ERR_SUCCESS2 ) &&
				( 0U != ( wBkpOpt2 & PH_EXCHANGE_BUFFERED_BIT2 ) ) )
			{
				status2 = PH_ERR_SUCCESS2;
				break;
			}

			/* Reset TxLastBits */
			if (pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXLASTBITS2] != 0U)
			{
				statusTmp2 = phhalHw_Ncx3321_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_TXLASTBITS2, 0x00U);
				if (statusTmp2 != PH_ERR_SUCCESS2)
				{
					status2 = statusTmp2;
					break;
				}
			}

			if (status2 == PH_ERR_SUCCESS2)
			{
				g_bExchangeState2 = PHHAL_HW_STATE_CMD42;
			}
			else
			{
				/*Jump over Retrieve Data state*/
				g_bExchangeState2 = PHHAL_HW_STATE_CMD52;
				return PH_STATUS_INPROCESS2;
			}
			/* Save status2 code value before returning */
			statusBackup2 = status2;
			/*no break*/
		case PHHAL_HW_STATE_CMD42:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Int_Retrieve_Data2(pDataParams2,&pRxBuffer2,&wRxLength2));
			if (ppRxBuffer2 != NULL)
			{
				*ppRxBuffer2 = pRxBuffer2;
			}
			if (pRxLength2 != NULL)
			{
				*pRxLength2 = wRxLength2;
			}
			if (((status2) & PH_ERR_MASK2) == PH_ERR_ABORTED2)
			{
				break;
			}
			/* Save status2 code value before returning */
			statusBackup2 = status2;
			g_bExchangeState2 = PHHAL_HW_STATE_CMD52;
			/*no break*/
		case PHHAL_HW_STATE_CMD52:
			/* Get status2 value from previous state */
			status2 = statusBackup2;
			if (pDataParams2->bJewelActivated2 == PH_ON2)
			{
				/* Reset Timer1 (FDT Timer) start condition to Tx Ended instead of Tx Frame Step detected. */
				dwValue2 = ~((uint32)CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_MASK2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				dwValue2 = CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = CLIF_TIMER1_CONFIG2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK2;
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 8U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 16U);
				wRegTypeValueSets2[wSizeOfRegTypeValueSets2++] = (uint8) (dwValue2 >> 24U);

				PH_CHECK_INPROCESS_FCT2(statusTmp2,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple2(pDataParams2, wRegTypeValueSets2, wSizeOfRegTypeValueSets2));
				if(statusTmp2 != PH_ERR_SUCCESS2)
				{
					status2 = statusTmp2;
					PH_BREAK_ON_FAILURE2(status2);
				}
			}
			if (((status2 & PH_ERR_MASK2) == PH_ERR_NCX3321_RX_TIMEOUT_ERROR2) ||
				((status2 & PH_ERR_MASK2 ) == PH_ERR_NCX3321_TX_FAILURE2))
			{
				/* Map equivalent NCX3321 error codes to HAL Generic error code. */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_IO_TIMEOUT2, PH_COMP_HAL2);
			}
			break;
		default:
			status2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}

	/* Reset variables */
	g_bExchangeState2 = PHHAL_HW_STATE_IDLE2;
	statusBackup2 = PH_ERR_SUCCESS2;
	wBkpOpt2 = 0U;
	wRxLength2 = 0U;
	bTxLastBits2 = 0U;
	bRespConfig2 = 0U;

	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Transmit2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wOption2,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                  VAR(uint16, ANFCRL_VAR) wTxLength2
									)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bNumberOfValidBits2 = 0U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wOptionBkp2;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bSyncByte2 = 0xf0;

	switch (g_bTransmitState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			wOptionBkp2 = wOption2;
			/* Check options */
			if ((wOption2 & (uint16) ~(uint16) (PH_TRANSMIT_BUFFERED_BIT2 | PH_TRANSMIT_LEAVE_BUFFER_BIT2 | PH_TRANSMIT_PREV_FRAME2)) != 0U)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* Re-send option should not be combined with buffer options. */
			if (((wOption2 & PH_TRANSMIT_PREV_FRAME2) != 0U) && ((wOption2 & (uint16)~(uint16)(PH_TRANSMIT_PREV_FRAME2)) != 0U))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* In Target Mode it's not allowed to have same buffers for transmission and reception
			*  since the data to transmit would get overwritten by received data. */
			if ((pDataParams2->wTargetMode2 != PH_OFF2) &&
				(pDataParams2->pTxBuffer2 == pDataParams2->pRxBuffer2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
			}

			if ((PH_TRANSMIT_PREV_FRAME2 & wOption2) == 0U)
			{
				bNumberOfValidBits2 = (uint8)pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXLASTBITS2];
			}
			else
			{
				if(wTxLength2 == 0x00U)
				{
					return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
				}
				pDataParams2->wTxBufLen2 = wTxLength2;


				if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
				{
					pDataParams2->wTxBufLen2 += 1U;
				}
			}

			if ((pDataParams2->bActiveMode2 != PH_ON2) && (pDataParams2->bNfcipMode2 == PH_ON2))
			{
				if((wOption2 == PH_TRANSMIT_BUFFER_FIRST2) || (wOption2 == PH_TRANSMIT_DEFAULT2))
				{
					PH_CHECK_SUCCESS_FCT2(status2, phhalHw_Ncx3321_Instr_TransmitRFData2(
						pDataParams2,
						PH_TRANSMIT_BUFFER_FIRST2,
						bNumberOfValidBits2,
						&bSyncByte2,
						1));

					if(wOption2 == PH_TRANSMIT_BUFFER_FIRST2)
					{
						wOptionBkp2 = PH_TRANSMIT_BUFFER_CONT2;
					}
					else
					{
						wOptionBkp2 = PH_TRANSMIT_BUFFER_LAST2;
					}
				}
			}
			g_bTransmitState2 = PHHAL_HW_STATE_CMD12;
			/* no break*/
		case PHHAL_HW_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_TransmitRFData2(pDataParams2, wOptionBkp2,
					bNumberOfValidBits2, pTxBuffer2, wTxLength2));
			g_bTransmitState2 = PHHAL_HW_STATE_IDLE2;
			PH_CHECK_ABORT2(status2);
			/* Reset TxLastBits */
			if (pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXLASTBITS2] != 0U)
			{
				PH_CHECK_SUCCESS_FCT2(statusTmp2, phhalHw_Ncx3321_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_TXLASTBITS2, 0x00));
			}
			if ((status2 & PH_ERR_MASK2 ) == PH_ERR_NCX3321_TX_FAILURE2)
			{
				/* Map equivalent NCX3321 error codes to HAL Generic error code. */
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INTERNAL_ERROR2, PH_COMP_HAL2);
			}
			break;
	}
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Receive2(P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint16, ANFCRL_VAR) wOption2, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2) {
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_UNSUPPORTED_COMMAND2;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRespControl2 = 0;

	switch (g_bReceiveState2) {
		case PHHAL_HW_STATE_IDLE2:
			/* Validate input parameters. */
			if ((wOption2 != 0U) || (ppRxBuffer2 == NULL) || (pRxLength2 == NULL))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}
			bRespControl2 = PH_RECEIVE_RF_ENABLE_EVT_STATUS2 |
			PH_RECEIVE_RF_ENABLE_RF_STATUS2 | PH_RECEIVE_RF_ENABLE_RX_STATUS2;

			/* Wait for the Data to be received */
			PH_CHECK_INPROCESS_FCT2(status2,
					phhalHw_Ncx3321_Instr_ReceiveRFData2(pDataParams2, bRespControl2,
							ppRxBuffer2, pRxLength2));
			if (status2 != PH_ERR_SUCCESS2) {
				if ((status2 & PH_ERR_MASK2) == PH_ERR_NCX3321_RX_TIMEOUT_ERROR2)
				{
					/* Map equivalent NCX3321 error codes to HAL Generic error code. */
					status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_IO_TIMEOUT2, PH_COMP_HAL2);
				}
				else
				{
					/* Do nothing */
				}
				break;
			}
			g_bReceiveState2 = PHHAL_HW_STATE_CMD12;
			/*no break*/
		case PHHAL_HW_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(status2,
					phhalHw_Ncx3321_Int_Retrieve_Data2(pDataParams2, ppRxBuffer2,
							pRxLength2));
			g_bReceiveState2 = PHHAL_HW_STATE_IDLE2;
			break;
	}

	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Autocoll2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint16, ANFCRL_VAR) wMode2,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams2
									)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwRegister2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 offsetPos2 = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 offsetLen2 = 0U;

	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pEvtPayload2 = NULL;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventReceived2 = 0x0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bRfTechnology2 = 0U;

	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTypeA_CRC2 = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 bTypeF_CRC2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCrcIn2 = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 wCrcCalc2 = 0U;

	static VAR(uint16, ANFCRL_VAR) wProtParams2 = 0U;

	switch (g_bAutocollState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			bTypeA_CRC2 = 0U;
			bTypeF_CRC2 = 0U;
			wProtParams2 = 0U;
			/* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_SetConfig2(pDataParams2, PHHAL_HW_CONFIG_SET_EMD2,
					PH_OFF2));
			PH_BREAK_ON_FAILURE2(status2);

			if (pDataParams2->bCardMode2 == PH_ON2)
			{
				bRfTechnology2 = PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A2;
			}
			else
			{
				/*RFTech A*/
				if ((wMode2 & A_MODE2) == A_MODE2)
				{
					bRfTechnology2 |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A2;
				}
				/*RFTech F*/
				if ((wMode2 & F_MODE2) == F_MODE2)
				{
					bRfTechnology2 |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F2;
				}
				/*RFTech Active A*/
				if ((wMode2 & ACTIVE_A_MODE2) == ACTIVE_A_MODE2)
				{
					bRfTechnology2 |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A_ACTIVE2;
				}
				/*RFTech Active F*/
				if ((wMode2 & ACTIVE_F_MODE2) == ACTIVE_F_MODE2)
				{
					bRfTechnology2 |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F_ACTIVE2;
				}
				/*RFTech B and Active B*/
				if (((wMode2 & B_MODE2) == B_MODE2) || ((wMode2 & ACTIVE_B_MODE2) == ACTIVE_B_MODE2))
				{
					/* Do nothing, ignore -- NFCP576 -- as the NFC forum DTA application expects success for Listen B */
					bRfTechnology2 = 0U;
					return PH_ERR_SUCCESS2;
				}
			}
			/* set the receive length */
			*pRxLength2 = 0U;

			pDataParams2->wRxBufLen2 = 0U;

			/* Reset the Flag used to indicate if Passive Target is activated by ISO/IEC 18092 Frame */
			pDataParams2->wTargetMode2 = PH_OFF2;
			pDataParams2->bActiveMode2 = PH_OFF2;
			pDataParams2->bNfcipMode2 = PH_OFF2;
			g_bAutocollState2 = PHHAL_HW_STATE_CMD12;
			return PH_STATUS_INPROCESS2;

		case PHHAL_HW_STATE_CMD12:
			PH_CHECK_INPROCESS_FCT2(status2,
						phhalHw_Ncx3321_Instr_SwitchModeAutocoll2(pDataParams2,bRfTechnology2,
					PHHAL_HW_NCX3321_AUTOCOLL_MODE_TERMINATE_ON_RF_OFF2));
			if (status2 == PH_ERR_SUCCESS2)
			{
				g_bAutocollState2 = PHHAL_HW_STATE_CMD22;
				return PH_STATUS_INPROCESS2;
			}
			break;

		case PHHAL_HW_STATE_CMD22:
			/*Wait for event*/
			PH_CHECK_INPROCESS_FCT2(status2,
					phhalHw_Ncx3321_WaitForEvent2( pDataParams2, PH_NCX3321_EVT_AUTOCOLL2 | PH_NCX3321_EVT_GENERAL_ERROR2, PHHAL_HW_MAX_DELAY2,
							TRUE, &dwEventReceived2, &pEvtPayload2));
			if (status2 == PH_ERR_SUCCESS2)
			{
				if (dwEventReceived2 == PH_NCX3321_EVT_AUTOCOLL2)
				{
					if (pEvtPayload2[PHHAL_HW_NCX3321_AUTOCOLL_STATUS_INDEX2] == PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATED2)
					{
						g_bAutocollState2 = PHHAL_HW_STATE_CMD32;
						return PH_STATUS_INPROCESS2;
					}
					else if (pEvtPayload2[PHHAL_HW_NCX3321_AUTOCOLL_STATUS_INDEX2] == PHHAL_HW_NCX3321_AUTOCOLL_EXTRF_OFF2)
					{
						status2 = PH_ERR_EXT_RF_ERROR2;
					}
					else
					{
						/* Unexpected status2 return from FE */
						status2 = PH_ERR_INTERNAL_ERROR2;
					}
				}
				if ((dwEventReceived2 & PH_NCX3321_EVT_GENERAL_ERROR2) != 0U)
				{
					pDataParams2->dwGenError2 = (uint32) pEvtPayload2[4];
					pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[5]) << 8U;
					pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[6]) << 16U;
					pDataParams2->dwGenError2 |= ((uint32) pEvtPayload2[7]) << 24U;

					status2 = PH_ERR_INTERNAL_ERROR2;
				}
			}
			break;

		case PHHAL_HW_STATE_CMD32:
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, CLIF_RX_STATUS_ERROR2, &dwRegister2));
			PH_BREAK_ON_FAILURE2(status2)
			if ((dwRegister2 & CLIF_RX_STATUS_ERROR_RX_CL_ERROR_MASK2) == 0U)
			{
				switch (pEvtPayload2[PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACT_INDEX2])
				{
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_A_1062:
						wProtParams2 = PHHAL_HW_RF_TYPE_A_FRAMING2 | PHHAL_HW_RF_DATARATE_1062;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_2122:
						wProtParams2 = PHHAL_HW_RF_TYPE_F_FRAMING2 | PHHAL_HW_RF_DATARATE_2122;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_4242:
						wProtParams2 = PHHAL_HW_RF_TYPE_F_FRAMING2 | PHHAL_HW_RF_DATARATE_4242;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_1062:
						wProtParams2 = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2 | PHHAL_HW_RF_DATARATE_1062;
						bTypeA_CRC2 = 1u;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_2122:
						wProtParams2 = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2 | PHHAL_HW_RF_DATARATE_2122;
						bTypeF_CRC2 = 1u;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_4242:
						wProtParams2 = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2 | PHHAL_HW_RF_DATARATE_4242;
						bTypeF_CRC2 = 1u;
						break;
					default:
						g_bAutocollState2 = PHHAL_HW_STATE_IDLE2;
						bRfTechnology2 = 0U;
						/* Invalid Framing as NCX3321 will not emulate other than Type-A, Type-F and Active Frame */
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_FRAMING_ERROR2, PH_COMP_HAL2);
				}

				if ((pEvtPayload2[PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACT_INDEX2] & PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_MODE_MASK2)
						== PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_PASSIVE_MODE2)
				/* Disable active mode */
				{
					if (pEvtPayload2[PHHAL_HW_NCX3321_AUTOCOLL_TECH_STATUS_INDEX2] == 0U)
					{
						status2 = PH_ERR_PROTOCOL_ERROR2;
						break;
					}
				}
				g_bAutocollState2 = PHHAL_HW_STATE_CMD42;
				return PH_STATUS_INPROCESS2;
			}
			else
			{
				status2 = PH_ERR_INTEGRITY_ERROR2;
				break;
			}
		case PHHAL_HW_STATE_CMD42:
			/* Read the RF Rx Buffer contents. */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_RetrieveRFData2(pDataParams2, ppRxBuffer2, pRxLength2));
			if (pProtParams2 != NULL)
			{
				*pProtParams2 = wProtParams2;
			}
			/* Disable active mode */

			if ((wProtParams2 & PHHAL_HW_RF_FRAMING_OPTION_MASK2) == PHHAL_HW_RF_TYPE_ACTIVE_FRAMING2)
			{
				pDataParams2->bActiveMode2 = PH_ON2;
			}

			/* At-least a byte data + 2 bytes of crc.  */
			if (*pRxLength2 >= 3U)
			{
				if ((bTypeA_CRC2 == 0x1U) || (bTypeF_CRC2 == 0x1U))
				{
					if (bTypeA_CRC2 == 0x1U)
					{
						/* Retrieve CRC */
						wCrcIn2 = (uint16)(((uint16)(*ppRxBuffer2)[(*pRxLength2) - 1U]) << 8U);
						wCrcIn2 |= (uint16)((*ppRxBuffer2)[(*pRxLength2) - 2U]);

						/* Remove CRC from input data */
						*pRxLength2 -= 2U;

						/* Calculate CRC */
						PH_CHECK_FAILURE_FCT2(status2, phTools_CalculateCrc162(
								PH_TOOLS_CRC_OPTION_DEFAULT2,
								PH_TOOLS_CRC16_PRESET_ISO14443A2,
								PH_TOOLS_CRC16_POLY_ISO144432,
								*ppRxBuffer2,
								*pRxLength2,
								&wCrcCalc2));
					}
					else
					{
						/* Retrieve CRC */
						wCrcIn2 = (uint16)((*ppRxBuffer2)[(*pRxLength2) - 1U]);
						wCrcIn2 |= (uint16)(((uint16)(*ppRxBuffer2)[(*pRxLength2) - 2U]) << 8U);

						/* Remove CRC from input data */
						*pRxLength2 -= 2U;

						/* Calculate CRC */
						PH_CHECK_FAILURE_FCT2(status2, phTools_CalculateCrc162(
								PH_TOOLS_CRC_OPTION_MSB_FIRST2,
								PH_TOOLS_CRC16_PRESET_FELICA2,
								PH_TOOLS_CRC16_POLY_FELICA2,
								*ppRxBuffer2,
								*pRxLength2,
								&wCrcCalc2));
					}
					/* CRC Check -> Compare input and calculated crc */
					if (wCrcIn2 == wCrcCalc2)
					{
						status2 = PH_ERR_SUCCESS2;
					}
					else
					{
						status2 = PH_ADD_COMPCODE_FIXED2(PH_ERR_INTEGRITY_ERROR2, PH_COMP_HAL2);
						break;
					}

				}
				else
				{
					/* Remove CRC from input data */
					*pRxLength2 -= 2U;
				}

				/* Store received data length in dataparams */
				pDataParams2->wRxBufLen2 = *pRxLength2;

				/* Return RxBuffer pointer */
				/* Offset "F0" in case of Active communication */
				*ppRxBuffer2 = &(pDataParams2->pRxBuffer2[offsetPos2]);

				/* Return RxBuffer length */
				/* Offset "F0" + CRC in case of Active communication */
				*pRxLength2 = pDataParams2->wRxBufLen2 - offsetLen2;

				pDataParams2->wTargetMode2 = wProtParams2;

				pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_RXDATARATE_FRAMING2] = wProtParams2;
				pDataParams2->wCfgShadow2[PHHAL_HW_CONFIG_TXDATARATE_FRAMING2] = wProtParams2;

			}
			else
			{
				status2 = PH_ERR_INTEGRITY_ERROR2;
				break;
			}
			break;
	}
	g_bAutocollState2 = PHHAL_HW_STATE_IDLE2;
	bRfTechnology2 = 0U;
	pEvtPayload2 = NULL;
	bTypeA_CRC2 = 0U;
	bTypeF_CRC2 = 0U;
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Wait2(
                P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                VAR(uint8, ANFCRL_VAR) bUnit2,
                VAR(uint16, ANFCRL_VAR) wTimeout2
								)
{
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 wStatus2 = PH_ERR_SUCCESS2;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
	P2VAR(phWaitParam_t2, AUTOMATIC, ANFCRL_APPL_DATA) pWaitParam2 = &g_sWaitParam2;

	switch (g_bWaitState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			/* Parameter check */
			if ((bUnit2 != PHHAL_HW_TIME_MICROSECONDS2) && (bUnit2 != PHHAL_HW_TIME_MILLISECONDS2))
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
			}

			/* If time-out value is zero, there is no wait needed */
			if (wTimeout2 == 0U)
			{
				return PH_ERR_SUCCESS2;
			}
			pWaitParam2->wBkpTimeout2 = wTimeout2;
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(
				pDataParams2,
				EVENT_ENABLE2,
				EVENT_ENABLE_TIMER0_EVENT_ENABLE_MASK2));
			wStatus2 = statusTmp2;
			PH_BREAK_ON_FAILURE2(wStatus2);
			g_bWaitState2 = PHHAL_HW_STATE_CMD12;
			return PH_STATUS_INPROCESS2;
			/*no break*/

		case PHHAL_HW_STATE_CMD12:
			/* Setting the Prescaler frequency according to wTimeout2 */
			if (bUnit2 == PHHAL_HW_TIME_MILLISECONDS2)
			{
				pWaitParam2->wPrescaler2 = 0x3CU;
				if(pWaitParam2->wBkpTimeout2 > PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS2)
				{
					/* Calculating the load value */
					pWaitParam2->dwLoadValue2 = (uint32)PHHAL_HW_NCX3321_MAX_LOADVALUE_MS2;
				}
				else
				{
					pWaitParam2->dwLoadValue2 = (uint32)pWaitParam2->wBkpTimeout2 * ( PHHAL_HW_NCX3321_MIN_FREQ2  / PHHAL_HW_NCX3321_CONVERSION_MS_SEC2);
				}
			}
			else
			{
				/* here wTimeout2 will be in uS and not be Zero */
				pWaitParam2->wPrescaler2 = 0x00U;
				/*Reducing the division by 2 digits to retain the 2 digit decimal places which were getting wiped out*/
				pWaitParam2->dwLoadValue2 =(uint32) PHHAL_HW_NCX3321_MAX_LOADVALUE_US2;
				/*Restoring the division done in the earlier step*/
				pWaitParam2->dwLoadValue2 =(uint32) ((pWaitParam2->wBkpTimeout2 * (pWaitParam2->dwLoadValue2))/100U);
			}
			g_bWaitState2 = PHHAL_HW_STATE_CMD22;
			/*no break*/

		case PHHAL_HW_STATE_CMD22:
			PH_CHECK_INPROCESS_FCT2(wStatus2, phhalHw_Ncx3321_Int_TimerStart2(
				pDataParams2,
				CLIF_TIMER0_CONFIG2,
				CLIF_TIMER0_CONFIG_T0_START_NOW_MASK2,
				CLIF_TIMER0_CONFIG_T0_ONE_SHOT_MODE_MASK2,
				pWaitParam2->wPrescaler2,
				pWaitParam2->dwLoadValue2));
			if(wStatus2 == PH_ERR_ABORTED2)
			{
				g_bWaitState2 = PHHAL_HW_STATE_IDLE2;
				return wStatus2;
			}
			if (bUnit2 == PHHAL_HW_TIME_MILLISECONDS2)
			{
				if(pWaitParam2->wBkpTimeout2 > PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS2)
				{
					pWaitParam2->wBkpTimeout2 -= PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS2;
					g_bWaitState2 = PHHAL_HW_STATE_CMD12;
					return PH_STATUS_INPROCESS2;
				}
			}
			g_bWaitState2 = PHHAL_HW_STATE_CMD32;
			/* No break */
		case PHHAL_HW_STATE_CMD32:
			PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(
				pDataParams2,
				EVENT_ENABLE2,
				~(uint32) EVENT_ENABLE_TIMER0_EVENT_ENABLE_MASK2));
			g_bWaitState2 = PHHAL_HW_STATE_IDLE2;
			PH_CHECK_SUCCESS2(statusTmp2);
			break;
		default:
			wStatus2 = PH_ERR_INTERNAL_ERROR2;
			break;
	}
	g_bWaitState2 = PHHAL_HW_STATE_IDLE2;

	return PH_ADD_COMPCODE2(wStatus2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Stop_Lpcd2 (
    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    )
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
    if ((pDataParams2->bLpcdConfig2 == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB2) ||
        (pDataParams2->bLpcdConfig2 == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD2))
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_PARAMETER2, PH_COMP_HAL2);
    }
    else
    {
        /* Call SWITCH_MODE_BOOT_NORMAL Command to stop LPCD. */
        status2 = phhalHw_Ncx3321_Instr_SwitchModeBootNormal2(pDataParams2);
    }
    return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_Lpcd2(
                P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
								)
{
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_USE_CONDITION2;
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2 = PH_ERR_SUCCESS2;
    static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusBackUp2 = PH_ERR_SUCCESS2;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventReceived2 = 0x00U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventToWait2 = 0x00U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwRxCtrlRegVal2 = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwDpcConfigReg2 = 0x00U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM2 dwDpcConfigEeprom2 = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwTxLdoVddpa2 = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwUlpcdVddpa2 = 0x00U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUlpcdVddpa2 = g_aUlpcdVddpa2;
    static VAR(uint32, ANFCRL_VAR) dwDelay2 = 0U;
    VAR(uint32, ANFCRL_VAR) dwElapsedTime2 = 0U;

	if((pDataParams2->bLpcdMode2 == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT2) ||
			(pDataParams2->bLpcdMode2 == PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN2))
	{
		switch (pDataParams2->bLpcdState2)
		{
			case PHHAL_HW_STATE_IDLE2:
			    dwDpcConfigReg2 = 0x00U;
                dwUlpcdVddpa2 = 0x00U;
                dwTxLdoVddpa2 = 0x00U;
				if (pDataParams2->bLpcdMode2 == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT2)
				{
					if (pDataParams2->bLpcdConfig2 == PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_LPCD2)
					{
						return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
					}

					/* Reset the reference value. */
					pDataParams2->dwLpcdRefVal2 = 0U;
				}
				if (pDataParams2->bLpcdConfig2 == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB2)
				{
					pDataParams2->bLpcdState2 = PHHAL_HW_STATE_APPLY_SETTINGS2;
				}
				else if (pDataParams2->bLpcdConfig2 == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD2)
				{
					pDataParams2->bLpcdState2 = PHHAL_HW_STATE_APPLY_HF_ATT2;
				}
				else
				{
					pDataParams2->bLpcdState2 = PHHAL_HW_STATE_CMD12;
				}
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_APPLY_SETTINGS2:
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_ApplyProtocolSettings2(pDataParams2, PHHAL_HW_CARDTYPE_ISO14443A2));
				PH_BREAK_ON_FAILURE2(status2);

				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_CHECK_DPC2;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_CHECK_DPC2:
				/* Disable DPC in case it is enabled (FW 2.5 required to access this register) */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, REG_DPC_CONFIG2, &dwDpcConfigReg2));
				if((status2 & PH_ERR_MASK2) != PH_ERR_SUCCESS2)
				{
					/* If DPC register not available (old FW), check EEPRROM setting */
					if ((status2 & PH_ERR_MASK2) == PH_ERR_NCX3321_INSTR_ERROR2)
					{
						pDataParams2->bLpcdState2 = PHHAL_HW_STATE_CHECK_EEPRROM2;
						return PH_STATUS_INPROCESS2;
					}
					else
					{
						PH_BREAK_ON_FAILURE2(status2);
					}
				}

				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_DISABLE_DPC2;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_DISABLE_DPC2:
				/* Bit 31 DPC_REG_ACCESS must to be set to enable DPC modification via register
				 * and DPC needs to be disabled before field on. */
				if(((dwDpcConfigReg2 & REG_DPC_ENABLE_MASK2) == PH_ON2) || ((dwDpcConfigReg2 & REG_DPC_CONFIG_ACCESS_MASK2) == PH_OFF2))
				{
					PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegister2(
							pDataParams2,
							REG_DPC_CONFIG2,
							((dwDpcConfigReg2 | REG_DPC_CONFIG_ACCESS_MASK2) & (~REG_DPC_ENABLE_MASK2))));
					PH_BREAK_ON_FAILURE2(status2);
				}
				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_FIELD_ON2;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_CHECK_EEPRROM2:
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadE2Prom2(pDataParams2, DPC_CONFIG_EEPROM2, &dwDpcConfigEeprom2, 0x01U));
                if(PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2))
                {
                    break;
                }
                else
                {
                    /* DPC must not be enabled in EEPROM */
                    if((dwDpcConfigEeprom2 & PH_ON2) == PH_ON2)
                    {
                        status2 = PH_ERR_INTERNAL_ERROR2;
                        break;
                    }
                    else
                    {
                        dwDpcConfigReg2 = PH_OFF2;
                    }
                }
                pDataParams2->bLpcdState2 = PHHAL_HW_STATE_FIELD_ON2;
                return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_FIELD_ON2:
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOn2(pDataParams2));
                PH_BREAK_ON_FAILURE2(status2);
                pDataParams2->bLpcdState2 = PHHAL_HW_STATE_GET_TXLDO_VDDPA2;
                return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_GET_TXLDO_VDDPA2:
                /* Get current TXLDO_VDDPA setting */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, TXLDO_VDDPA_CONFIG2, &dwTxLdoVddpa2));
				PH_BREAK_ON_FAILURE2(status2);
                pDataParams2->bLpcdState2 = PHHAL_HW_STATE_GET_ULPCD_VDDPA2;
                return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_GET_ULPCD_VDDPA2:
                /* Get ULPCD VDDPA setting (must be done after FieldOn) */
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadE2Prom2(pDataParams2,
                        ULPCD_VDDPA_CTRL_EEPROM2, pUlpcdVddpa2, 0x02U));
                if(PH_ERR_SUCCESS2 != (status2 & PH_ERR_MASK2))
                {
                    break;
                }
                else
                {
                    dwUlpcdVddpa2 = (((uint32)(pUlpcdVddpa2[1]) & 0x01U) << 5U) + ((uint32)(pUlpcdVddpa2[0]) >> 3U);
                    /* In case values are different apply ULPCD_VDDPA for ULPCD */
                    if(dwTxLdoVddpa2 != dwUlpcdVddpa2)
                    {
                    	pDataParams2->bLpcdState2 = PHHAL_HW_STATE_APPLY_ULPCD_VDDPA2;
                    }
                    else
                    {
                        pDataParams2->bLpcdState2 = PHHAL_HW_STATE_READ_HF_ATT2;
                    }
                }
                return PH_STATUS_INPROCESS2;

            case PHHAL_HW_STATE_APPLY_ULPCD_VDDPA2:
                PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, TXLDO_VDDPA_CONFIG2, dwUlpcdVddpa2));
                PH_BREAK_ON_FAILURE2(status2);
                dwDelay2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
                pDataParams2->bLpcdState2 = PHHAL_HW_STATE_HF_ATT_DELAY2;
                return PH_STATUS_INPROCESS2;

            case PHHAL_HW_STATE_HF_ATT_DELAY2:
                dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, dwDelay2);
                /* Check for timer overflow, abort if timer overflow happens */
                if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
                {
                    return PH_ERR_ABORTED2;
                }
                else
                {
                    if (dwElapsedTime2 < PHHAL_HW_READ_HF_ATT_WAIT_TIME2)
                    {
                        return PH_STATUS_INPROCESS2;
                    }
                    else
                    {
                        pDataParams2->bLpcdState2 = PHHAL_HW_STATE_READ_HF_ATT2;
                    }
                }
                return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_READ_HF_ATT2:
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_ReadRegister2(pDataParams2, CLIF_RXCTRL_STATUS2, &dwRxCtrlRegVal2));
				PH_BREAK_ON_FAILURE2(status2);
				pDataParams2->bHFATTVal2 = (uint8)((dwRxCtrlRegVal2 & CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_MASK2) >> CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_POS2);

				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_APPLY_HF_ATT2;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_APPLY_HF_ATT2:
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_FieldOff2(pDataParams2));
				PH_BREAK_ON_FAILURE2(status2);

				/* Use the HF ATT reference value provided by User. */
				pDataParams2->dwLpcdRefVal2 |= (uint32)pDataParams2->bHFATTVal2 << 16U;

				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_CMD12;
				/*no break*/

			case PHHAL_HW_STATE_CMD12:
				/* Call LPCD Command to exchange LPCD TLV. */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Instr_SwitchModeLpcd2(pDataParams2, pDataParams2->bLpcdConfig2, pDataParams2->bLpcdWakeUpCtrl2,
						pDataParams2->dwLpcdRefVal2,pDataParams2->wLPCDWakeupCounterInMs2));

				PH_BREAK_ON_FAILURE2(status2);
				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_CMD22;
				/*no break*/

			case PHHAL_HW_STATE_CMD22:
				if (pDataParams2->bLpcdMode2 == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT2 )
				{
					dwEventToWait2 = PH_NCX3321_EVT_LP_CALIB2 | PH_NCX3321_EVT_GENERAL_ERROR2;
				}
				else
				{
					dwEventToWait2 = PH_NCX3321_EVT_LPCD2 | PH_NCX3321_EVT_GENERAL_ERROR2;
				}
				/* Once LPCD Command exchange is successful, wait for LPCD Event from NCx3321. */
				PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Int_EventWait2(
					pDataParams2,
					dwEventToWait2,
					PHHAL_HW_MAX_DELAY2,
					TRUE,
					&dwEventReceived2));
				if(status2 == PH_ERR_SUCCESS2)
				{
					if (dwEventReceived2 == PH_NCX3321_EVT_LPCD2)
					{
						if ((pDataParams2->dwEventStatus2 == PHHAL_HW_LPCD_EVT_STATUS_CARD_DETECTED2)||
							(pDataParams2->dwEventStatus2 == PHHAL_HW_LPCD_EVT_STATUS_EXTERNALRF_FIELD2))
						{
							/* Received LPCD event with card detection event bit set. */
							status2 = PH_ERR_SUCCESS2;
						}
						else
						{
							/* Received LPCD event and but other than card detection event bit set. */
							status2 = PH_ERR_LPCD_ABORTED2;
						}
					}
					else if(dwEventReceived2 == PH_NCX3321_EVT_LP_CALIB2)
					{
						/* Store the LPCD Calibration data, which should be used during card detection phase. */
						pDataParams2->dwLpcdRefVal2 = pDataParams2->dwEventStatus2;
						status2 = PH_ERR_SUCCESS2;
					}
					else
					{
						status2 = PH_ERR_INTERNAL_ERROR2;
					}
				}
				statusBackUp2 = status2;
				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_RESET_CONFIG12;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_RESET_CONFIG12:
				/* Reset to previous DPC configuration */
				if((dwDpcConfigReg2 & PH_ON2) == PH_ON2)
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, REG_DPC_CONFIG2, dwDpcConfigReg2));
					PH_BREAK_ON_FAILURE2(statusTmp2);
				}
				else
				{
					/* Do nothing */
				}
				pDataParams2->bLpcdState2 = PHHAL_HW_STATE_RESET_CONFIG22;
				return PH_STATUS_INPROCESS2;

			case PHHAL_HW_STATE_RESET_CONFIG22:
				/* Reset previous TxLDO VDDPA setting */
				if(dwTxLdoVddpa2 != dwUlpcdVddpa2)
				{
					PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegister2(pDataParams2, TXLDO_VDDPA_CONFIG2, dwTxLdoVddpa2));
					PH_BREAK_ON_FAILURE2(statusTmp2);
				}
				else
				{
					/* Do nothing */
				}
				/* Load status2 value from state PHHAL_HW_STATE_CMD22 */
				status2 = statusBackUp2;
				break;
			default:
				status2 = PH_ERR_INTERNAL_ERROR2;
				break;
		}
	}

	dwDpcConfigReg2 = 0x00U;
	dwTxLdoVddpa2 = 0x00U;
	dwUlpcdVddpa2 = 0x00U;
	dwDelay2 = 0U;
	statusBackUp2 = PH_ERR_SUCCESS2;
	pDataParams2->bLpcdState2 = PHHAL_HW_STATE_IDLE2;
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

#ifdef NXPBUILD__PHPAL_MIFARE_SW
FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticateKeyNo2(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                               VAR(uint8, ANFCRL_VAR) bBlockNo2,
                                               VAR(uint8, ANFCRL_VAR) bKeyType2,
                                               VAR(uint16, ANFCRL_VAR) wKeyNo2,
                                               VAR(uint16, ANFCRL_VAR) wKeyVersion2,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2
                                               )
{
#if defined(NXPBUILD__PH_KEYSTORE2)
    VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
    uint8    PH_MEMLOC_BUF2 aKey2[PHHAL_HW_MFC_KEY_LENGTH2 * 2];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM2 pKey2;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM2 bKeystoreKeyType2 = 0U;

    /* Bail out if we haven't got a key-store */
    if (pDataParams2->pKeyStoreDataParams2 == NULL)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
    }

    /* Retrieve KeyA & KeyB from key-store */
    status2 = phKeyStore_GetKey2(
        pDataParams2->pKeyStoreDataParams2,
        wKeyNo2,
        wKeyVersion2,
        (uint8)sizeof(aKey2),
        aKey2,
        &bKeystoreKeyType2);

    /* Change component code for invalid parameter */
    if ((status2 & PH_ERR_MASK2) == PH_ERR_INVALID_PARAMETER2)
    {
        return PH_ADD_COMPCODE2((status2 & PH_ERR_MASK2), PH_COMP_HAL2);
    }
    else
    {
        PH_CHECK_SUCCESS2(status2);
    }

    /* Check key type */
    if (bKeystoreKeyType2 != PH_KEYSTORE_KEY_TYPE_MIFARE2)
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    /* Evaluate which key to use */
    if (bKeyType2 == PHHAL_HW_MFC_KEYA2)
    {
        /* Use KeyA */
        pKey2 = aKey2;
    }
    else if (bKeyType2 == PHHAL_HW_MFC_KEYB2)
    {
        /* Use KeyB */
        pKey2 = &aKey2[PHHAL_HW_MFC_KEY_LENGTH2];
    }
    else
    {
        return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, PH_COMP_HAL2);
    }

    /* Call the authentication function using the key */
    return phhalHw_Ncx3321_MfcAuthenticate2(
        pDataParams2,
        bBlockNo2,
        bKeyType2,
        pKey2,
        pUid2);
#else /* NXPBUILD__PH_KEYSTORE2 */
    PH_UNUSED_VARIABLE2(pDataParams2);
    PH_UNUSED_VARIABLE2(bBlockNo2);
    PH_UNUSED_VARIABLE2(bKeyType2);
    PH_UNUSED_VARIABLE2(wKeyNo2);
    PH_UNUSED_VARIABLE2(wKeyVersion2);
    PH_UNUSED_VARIABLE2(pUid2);
    return PH_ADD_COMPCODE_FIXED2(PH_ERR_UNSUPPORTED_COMMAND2, PH_COMP_HAL2);
#endif /* NXPBUILD__PH_KEYSTORE2 */
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticate2(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                          VAR(uint8, ANFCRL_VAR) bBlockNo2,
                                          VAR(uint8, ANFCRL_VAR) bKeyType2,
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey2,
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2
                                          )
{
    return phhalHw_Ncx3321_Instr_MifareAuthenticate2(
        pDataParams2,
        pKey2,
        bKeyType2,
        bBlockNo2,
        pUid2);
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_EventWait2(
                  P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                  VAR(uint32, ANFCRL_VAR) dwEventTimeout2
									)
{
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwEventReceived2 = 0x0U;
	VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 statusTmp2;
	static VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2 = PH_ERR_SUCCESS2;
	static VAR(uint32, ANFCRL_VAR) bThreadStartTimer2 = 0u;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM2 dwElapsedTime2 = 0U;

	switch (g_bEventWaitState2)
	{
		case PHHAL_HW_STATE_IDLE2:
			if (pDataParams2->dwExpectedEvent2 == 0U)
			{
				return PH_ADD_COMPCODE_FIXED2(PH_ERR_USE_CONDITION2, PH_COMP_HAL2);
			}

			pDataParams2->dwEventReceived2 = 0U;

			if (pDataParams2->dwExpectedEvent2 == PH_NCX3321_EVT_RFON_DETECT2)
			{
				status2 = PH_ERR_IO_TIMEOUT2;
				bThreadStartTimer2 = phDriver_GetTimeCurrent2(PH_DRIVER_TIMER_USECS2);
				g_bEventWaitState2 = PHHAL_HW_STATE_CMD12;
			}
			else
			{
				g_bEventWaitState2 = PHHAL_HW_STATE_CMD22;
			}
			return PH_STATUS_INPROCESS2;
		case PHHAL_HW_STATE_CMD12:
			if (pDataParams2->bRFONEvent2 != 0x01U)
			{
				dwElapsedTime2 = phDriver_GetTimeElapsed2(PH_DRIVER_TIMER_USECS2, bThreadStartTimer2);

				/* Check for timer overflow, abort if timer overflow happens */
				if (S32K_TIMER_MAX_32BIT2 == dwElapsedTime2)
				{
					status2 = PH_ERR_ABORTED2;
					break;
				}
				else
				{
					if (dwElapsedTime2 < dwEventTimeout2)
					{
						return PH_STATUS_INPROCESS2;
					}
					else
					{
						/* Do nothing */
					}
				}
			}

			if (pDataParams2->bRFONEvent2 == 0x01U)
			{
				pDataParams2->dwEventReceived2 = PH_NCX3321_EVT_RFON_DETECT2;
				pDataParams2->bRFONEvent2 = 0x0U;
				status2 = PH_ERR_SUCCESS2;
			}
			g_bEventWaitState2 = PHHAL_HW_STATE_CMD32;
			return PH_STATUS_INPROCESS2;
		case PHHAL_HW_STATE_CMD22:
			/* Wait for event, configured by HOST using Setconfig of PHHAL_HW_NCX3321_CONFIG_EXPECTED_EVENT2. */
			PH_CHECK_INPROCESS_FCT2(status2, phhalHw_Ncx3321_Int_EventWait2(
				pDataParams2,
				pDataParams2->dwExpectedEvent2,
				dwEventTimeout2,
				TRUE,
				&dwEventReceived2));

			pDataParams2->dwEventReceived2 = dwEventReceived2;
			g_bEventWaitState2 = PHHAL_HW_STATE_CMD32;
			return PH_STATUS_INPROCESS2;
		case PHHAL_HW_STATE_CMD32:
			/* Only on successful External RF ON event, FW shall clear EVENT ENABLE Register.
			 * But in case of Timeout, EVENT_ENABLE2 bit for RFON_DET_EVENT needs to be reset by HOST. */
			if ((pDataParams2->dwExpectedEvent2 == PH_NCX3321_EVT_RFON_DETECT2) && ((status2 & PH_ERR_MASK2) == PH_ERR_IO_TIMEOUT2))
			{
				PH_CHECK_INPROCESS_FCT2(statusTmp2, phhalHw_Ncx3321_Instr_WriteRegisterAndMask2(pDataParams2,
						EVENT_ENABLE2, ~(uint32)EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK2));
				if (statusTmp2 != PH_ERR_SUCCESS2)
				{
					status2 = statusTmp2;
					break;
				}
			}

			if (((status2 & PH_ERR_MASK2) != PH_ERR_IO_TIMEOUT2) && ((status2 & PH_ERR_MASK2) != PH_ERR_ABORTED2))
			{
				if ((pDataParams2->dwExpectedEvent2 & pDataParams2->dwEventReceived2) == 0U)
				{
					status2 = PH_ERR_NCX3321_UNEXPECTED_EVT2;
				}
			}

			pDataParams2->dwExpectedEvent2 = 0;
	}

    g_bEventWaitState2 = PHHAL_HW_STATE_IDLE2;
	return PH_ADD_COMPCODE2(status2, PH_COMP_HAL2);
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Ncx3321_EventConsume2(
    P2VAR(phhalHw_Ncx3321_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2) {
  VAR(phStatus_t2, ANFCRL_VAR) PH_MEMLOC_REM2 status2;
	status2 = phTools_EventClear2(&pDataParams2->HwEventObj2, E_EVENT_OPT_NONE2,
			(E_EVENT_RF2 | E_EVENT_ABORT2),
			NULL);
	return status2;
}

FUNC(phStatus_t2, ANFCRL_CODE) phhalHw_Exchange_GetStatus2(void){
	if(g_bExchangeState2 == PHHAL_HW_STATE_IDLE2)
	{
		return PH_ERR_SUCCESS2;
	}
	else
	{
		return PH_STATUS_INPROCESS2;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX33212 */

#ifdef __cplusplus
}
#endif
