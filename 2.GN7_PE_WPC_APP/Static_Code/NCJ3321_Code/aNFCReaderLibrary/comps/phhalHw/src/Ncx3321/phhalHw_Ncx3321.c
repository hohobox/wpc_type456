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
*   @file    phhalHw_Ncx3321.c
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
#include <ph_Status.h>
#include <phhalHw.h>
#include <ph_RefDefs.h>

#ifdef NXPBUILD__PH_KEYSTORE
#include <phKeyStore.h>
#endif

#ifdef NXPBUILD__PHHAL_HW_NCX3321

#include <phDriver.h>
#include <phTools.h>
#include "phhalHw_Ncx3321.h"
#include <phhalHw_Ncx3321_Instr.h>
#include "phhalHw_Ncx3321_InstrMngr.h"
#include <phhalHw_Ncx3321_Reg.h>
#include "phhalHw_Ncx3321_Int.h"
#include "phhalHw_Ncx3321_Wait.h"

#ifndef AUTOSAR_VER
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
#include "App_NFC.h"

#else
#include <BoardSelection.h>

#endif	/* NIDEC_PORTING */
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321.c
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phhalHw_Ncx3321.h header file are of the same vendor */
#if (PHHALHW_NCX3321_VENDOR_ID_C != PHHALHW_NCX3321_VENDOR_ID)
    #error "phhalHw_Ncx3321.c and phhalHw_Ncx3321.h have different vendor ids"
#endif
/* Check if current file and phhalHw_Ncx3321.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C    != PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C    != PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION) || \
     (PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION_C != PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321.c and phhalHw_Ncx3321.h are different"
#endif
/* Check if current file and phhalHw_Ncx3321.h header file are of the same Software version */
#if ((PHHALHW_NCX3321_SW_MAJOR_VERSION_C != PHHALHW_NCX3321_SW_MAJOR_VERSION) || \
     (PHHALHW_NCX3321_SW_MINOR_VERSION_C != PHHALHW_NCX3321_SW_MINOR_VERSION) || \
     (PHHALHW_NCX3321_SW_PATCH_VERSION_C != PHHALHW_NCX3321_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321.c and phhalHw_Ncx3321.h are different"
#endif
#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
typedef struct
{
  P2CONST(uint16, AUTOMATIC, ANFCRL_APPL_CONST) pShadowDefault;
  VAR(uint16, ANFCRL_VAR) wShadowCount;
  VAR(uint16, ANFCRL_VAR) wIndex;
  VAR(uint16, ANFCRL_VAR) wConfig;
  VAR(uint8, ANFCRL_VAR) bUseDefaultShadow;
}phApplyProtocolParam_t;

typedef struct
{
  VAR(uint32, ANFCRL_VAR) dwLoadValue;
  VAR(uint32, ANFCRL_VAR) wPrescaler;
  VAR(uint16, ANFCRL_VAR) wBkpTimeout;
}phWaitParam_t;

/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#define PH_RF_EXCH_CONF_ENABLE_RSP_RX_DATA   0x08U
#define PH_RF_EXCH_CONF_ENABLE_EVT_STATUS    0x04U
#define PH_RF_EXCH_CONF_ENABLE_RF_STATUS     0x02U
#define PH_RF_EXCH_CONF_ENABLE_RX_STATUS     0x01U

#define PH_RECEIVE_RF_ENABLE_EVT_STATUS   0x04U
#define PH_RECEIVE_RF_ENABLE_RF_STATUS    0x02U
#define PH_RECEIVE_RF_ENABLE_RX_STATUS    0x01U

#define PHHAL_HW_STATE_IDLE					0u
#define PHHAL_HW_STATE_APPLY_SETTINGS		1u
#define PHHAL_HW_STATE_READ_HF_ATT 			2u
#define PHHAL_HW_STATE_APPLY_HF_ATT 		3u
#define PHHAL_HW_STATE_CMD1					4u
#define PHHAL_HW_STATE_CMD2					5u
#define PHHAL_HW_STATE_CMD3					6u
#define PHHAL_HW_STATE_CMD4					7u
#define PHHAL_HW_STATE_CMD5					8u
#define PHHAL_HW_STATE_CMD6					9u
#define PHHAL_HW_STATE_CMD7					10u
#define PHHAL_HW_STATE_CHECK_DPC			11u
#define PHHAL_HW_STATE_DISABLE_DPC			12u
#define PHHAL_HW_STATE_CHECK_EEPRROM		13u
#define PHHAL_HW_STATE_FIELD_ON				14u
#define PHHAL_HW_STATE_GET_TXLDO_VDDPA		15u
#define PHHAL_HW_STATE_GET_ULPCD_VDDPA		16u
#define PHHAL_HW_STATE_APPLY_ULPCD_VDDPA	17u
#define PHHAL_HW_STATE_HF_ATT_DELAY			18u
#define PHHAL_HW_STATE_FIELD_RESET			19u
#define PHHAL_HW_STATE_RESET_CONFIG1		20u
#define PHHAL_HW_STATE_RESET_CONFIG2		21u

/* Wait time to stabilize RF ON before reading HF ATT value */
#define PHHAL_HW_READ_HF_ATT_WAIT_TIME         1500U

#define SET_NCX3321_SHADOW(USED_SHADOW)   \
		pBackup->pShadowDefault = &(USED_SHADOW)[0][0]; \
		pBackup->wShadowCount = (uint16)(sizeof((USED_SHADOW)) / (sizeof((USED_SHADOW)[0])))

#define EVTS_HEADER_BYTES       3U
#define EVENT_LSB_INDEX         1U
#define TLV_TYPE_FIELD_INDEX    1U
#define TLV_LENGTH_MSB_INDEX    2U
#define TLV_LENGTH_LSB_INDEX    3U

#define PHHAL_HW_NCX3321_MAX_LOADVALUE_MS	((uint32)PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS * ( PHHAL_HW_NCX3321_MIN_FREQ  / PHHAL_HW_NCX3321_CONVERSION_MS_SEC))
#define PHHAL_HW_NCX3321_MAX_LOADVALUE_US	(PHHAL_HW_NCX3321_MAX_FREQ / (PHHAL_HW_NCX3321_CONVERSION_US_SEC/100U))
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/
#define ANFCRL_START_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/* Default shadow for ISO14443-3A Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM wNcx3321_DefaultShadow_I14443a[][2] =
{
    {PHHAL_HW_CONFIG_PARITY,                PH_ON},
    {PHHAL_HW_CONFIG_TXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_TRXCRC,                PH_ON},
    {PHHAL_HW_CONFIG_RXWAIT_US,             76U},
    {PHHAL_HW_CONFIG_TXWAIT_US,             85U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_106 | PHHAL_HW_RF_TYPE_A_FRAMING},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_106 | PHHAL_HW_RF_TYPE_A_FRAMING},
    {PHHAL_HW_CONFIG_ASK100,                PH_ON}
};

/* Default shadow for ISO14443-3B Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM wNcx3321_DefaultShadow_I14443b[][2] =
{
    {PHHAL_HW_CONFIG_PARITY,                PH_OFF},
    {PHHAL_HW_CONFIG_TXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXWAIT_US,             76U},
    {PHHAL_HW_CONFIG_TXWAIT_US,             85U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_106 | PHHAL_HW_RF_TYPE_B_FRAMING},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_106 | PHHAL_HW_RF_TYPE_B_FRAMING},
    {PHHAL_HW_CONFIG_ASK100,                PH_OFF}
};

/* Default shadow for FeliCa Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM wNcx3321_DefaultShadow_Felica[][2] =
{
    {PHHAL_HW_CONFIG_PARITY,                PH_OFF},
    {PHHAL_HW_CONFIG_TXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXWAIT_US,             88U},
    {PHHAL_HW_CONFIG_TXWAIT_US,             160U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_212 | PHHAL_HW_RF_TYPE_F_FRAMING},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_212 | PHHAL_HW_RF_TYPE_F_FRAMING},
    {PHHAL_HW_CONFIG_ASK100,                PH_OFF}
};

/* Default shadow for FeliCa Mode at 424 baud rate */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM wNcx3321_DefaultShadow_Felica_424[][2] =
{
    {PHHAL_HW_CONFIG_PARITY,                PH_OFF},
    {PHHAL_HW_CONFIG_TXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXWAIT_US,             85U},
    {PHHAL_HW_CONFIG_TXWAIT_US,             160U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_424 | PHHAL_HW_RF_TYPE_F_FRAMING},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING,    PHHAL_HW_RF_DATARATE_424 | PHHAL_HW_RF_TYPE_F_FRAMING},
    {PHHAL_HW_CONFIG_ASK100,                PH_OFF}
};

/* Default shadow for ISO15693 Mode */
static CONST(uint16, ANFCRL_CONST) PH_MEMLOC_CONST_ROM wNcx3321_DefaultShadow_I15693[][2] =
{
    {PHHAL_HW_CONFIG_PARITY,                PH_OFF},
    {PHHAL_HW_CONFIG_TXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXCRC,                 PH_ON},
    {PHHAL_HW_CONFIG_RXWAIT_US,             300U},
    {PHHAL_HW_CONFIG_TXWAIT_US,             500U},
    {PHHAL_HW_CONFIG_TXDATARATE_FRAMING,    PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4},
    {PHHAL_HW_CONFIG_RXDATARATE_FRAMING,    PHHAL_HW_RF_RX_DATARATE_HIGH},
    {PHHAL_HW_CONFIG_SUBCARRIER,            PHHAL_HW_SUBCARRIER_SINGLE},
    {PHHAL_HW_CONFIG_ASK100,                PH_ON}
};



#define ANFCRL_STOP_SEC_CONST_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(phApplyProtocolParam_t, ANFCRL_VAR) g_sApplyProtocolParam;         /**< Store backup parameters for phhalHw_Ncx3321_ApplyProtocolSettings. */
static VAR(phWaitParam_t, ANFCRL_VAR) g_sWaitParam;                           /**< Store backup parameters for phhalHw_Ncx3321_Wait. */
static VAR(uint8, ANFCRL_VAR) g_aUlpcdVddpa[2] = {0};                        /**< Store ULPCD VDDPA setting. */

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static VAR(uint8, ANFCRL_VAR) g_bEnBootNormalModeState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bApplyProtocolState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bExchangeState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bTransmitState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bReceiveState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bAutocollState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bWaitState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bEventWaitState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bFieldOffState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bSetConfigState = PHHAL_HW_STATE_IDLE;
static VAR(uint8, ANFCRL_VAR) g_bSetListenParamsState = PHHAL_HW_STATE_IDLE;

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
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
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) xEventHandle;

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EnBootNormalMode(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Init(
              P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams,
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
              VAR(uint16, ANFCRL_VAR) wTxBufSize,
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,
              VAR(uint16, ANFCRL_VAR) wRxBufSize
							)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(phDriver_Pin_Config_t, ANFCRL_VAR) PH_MEMLOC_REM pinCfg;
  static VAR(uint8, ANFCRL_VAR) bHalInitState = PHHAL_HW_STATE_IDLE;
  static VAR(uint8, ANFCRL_VAR) bStateHaltCnt = 0u;		/* 010A_06 */
  
	switch(bHalInitState)
	{
		case PHHAL_HW_STATE_IDLE:
			if (sizeof(phhalHw_Ncx3321_DataParams_t) != wSizeOfDataParams)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_DATA_PARAMS, PH_COMP_HAL);
			}

			/* The buffers cannot be zero */
			if ((wTxBufSize == 0U) || (wRxBufSize == 0U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* Check all the pointers */
			PH_ASSERT_NULL(pDataParams);
			PH_ASSERT_NULL(pBalDataParams);
			PH_ASSERT_NULL(pTxBuffer);
			PH_ASSERT_NULL(pRxBuffer);

			/* The first bytes are reserved for the SPI commands */
			pDataParams->pTxBuffer                = &pTxBuffer[1];
			pDataParams->wTxBufSize               = wTxBufSize - 1U;
			pDataParams->pRxBuffer                = &pRxBuffer[2];
			pDataParams->wRxBufSize               = wRxBufSize - 2U;

			/* Initialize the private data */
			pDataParams->wId                      = PH_COMP_HAL | PHHAL_HW_NCX3321_ID;
			pDataParams->pBalDataParams           = pBalDataParams;
			pDataParams->pKeyStoreDataParams      = pKeyStoreDataParams;

			pDataParams->wRxBufLen              = 0U;
			pDataParams->wRxBufStartPos         = 0U;

			pDataParams->wTxBufLen              = 0U;
			pDataParams->wTxBufStartPos         = 0U;
			pDataParams->wTxFwDataLen           = 0U;

			pDataParams->bActiveMode            = PH_OFF;
			pDataParams->bCardType              = PHHAL_HW_CARDTYPE_ISO14443A;
			pDataParams->bTimeoutUnit           = PHHAL_HW_TIME_MICROSECONDS;
			pDataParams->wFieldOffTime          = PHHAL_HW_FIELD_OFF_DEFAULT;
			pDataParams->wFieldRecoveryTime     = PHHAL_HW_FIELD_RECOVERY_DEFAULT;
			pDataParams->bSymbolStart           = PH_OFF;
			pDataParams->bSymbolEnd             = PH_OFF;

			pDataParams->bRfResetAfterTo        = PH_OFF;
			pDataParams->bOpeMode               = RD_LIB_MODE_NFC;
			pDataParams->dwFelicaEmdReg         = 0U;
			pDataParams->bRxMultiple            = PH_OFF;
			pDataParams->bJewelActivated        = PH_OFF;
			pDataParams->bLpcdConfig            = 0U;
			pDataParams->bLpcdState             = PHHAL_HW_STATE_IDLE;
			pDataParams->wWakeupCounterInMs     = 1000U;
			pDataParams->wLPCDWakeupCounterInMs = 1000U;
			pDataParams->bLpcdWakeUpCtrl        = 0U;
			pDataParams->bRfca                  = PH_ON;
			pDataParams->wTargetMode            = PH_OFF;
			pDataParams->dwTxWaitMs             = 0U;
			pDataParams->bMfcCryptoEnabled      = PH_OFF;
			pDataParams->bCardMode              = PH_OFF;
			pDataParams->bBalConnectionType     = PHHAL_HW_BAL_CONNECTION_SPI;
			pDataParams->wAdditionalInfo        = 0U;
			pDataParams->dwExpectedEvent         = 0U;

			pDataParams->bSsTx1ConfigIsConfigured = 0U;
			pDataParams->bSsTx2ConfigIsConfigured = 0U;
			pDataParams->dwSetSsTx1ConfigValue = 0x00U;
			pDataParams->dwSetSsTx2ConfigValue = 0x00U;
			pDataParams->pTimerISRCallBack      = &phhalHw_Ncx3321_Int_GuardTimeCallBck;

			pDataParams->bPollGuardTimeFlag     = PH_OFF;
			pDataParams->sIrqResp.bIsrBytesRead = 9U;
			pDataParams->bCTSEvent              = PH_OFF;
			pDataParams->bRFONEvent             = PH_OFF;
			pDataParams->dwEventStatus          = 0U;
			pDataParams->dwEventReceived        = 0U;
			pDataParams->dwLpcdRefVal           = 0U;
			pDataParams->dwGenError             = 0x00U;
			pDataParams->bNfcipMode             = PH_OFF;
			pDataParams->sIrqResp.pHandlerModeBuffPtr = &pDataParams->sIrqResp.aISRReadBuf[0];
			pDataParams->wExchangeRfStatus = PH_ERR_SUCCESS;

			/* Non-Blocking Handle parameter init */
			pDataParams->bSendState = 0U;
			pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_OFF;
			pDataParams->bRegisterOpState = PHHAL_INSTR_STATE_CHECK_PARAM;
			g_bEnBootNormalModeState = PHHAL_HW_STATE_IDLE;
			g_bApplyProtocolState = PHHAL_HW_STATE_IDLE;
			g_bExchangeState = PHHAL_HW_STATE_IDLE;
			g_bTransmitState = PHHAL_HW_STATE_IDLE;
			g_bReceiveState = PHHAL_HW_STATE_IDLE;
			g_bAutocollState = PHHAL_HW_STATE_IDLE;
			g_bWaitState = PHHAL_HW_STATE_IDLE;
			g_bEventWaitState = PHHAL_HW_STATE_IDLE;
			g_bFieldOffState = PHHAL_HW_STATE_IDLE;

			(void)memset(&pDataParams->sIrqResp.aISRReadBuf[0], 0, MAX_ISR_READ_BUFFER_SIZE);

			/* Configure Reset pin as output and set to high. */
			pinCfg.bPullSelect = PHDRIVER_PIN_RESET_PULL_CFG;
			pinCfg.bOutputLogic = RESET_POWERUP_LEVEL;

			PH_CHECK_SUCCESS_FCT(statusTmp, phDriver_PinConfig(
				PHDRIVER_PIN_RESET,
				PH_DRIVER_PINFUNC_OUTPUT,
				&pinCfg));

		#ifdef PHDRIVER_SOFT_SSEL
			if(((phbalReg_Type_t *)pBalDataParams)->bBalType == PHBAL_REG_TYPE_SPI)
			{
				/* Configure NSS (Chip Select) pin as GPIO output and set to high. */
				pinCfg.bPullSelect = PHDRIVER_PIN_NSS_PULL_CFG;
				pinCfg.bOutputLogic = PH_DRIVER_SET_HIGH;
				PH_CHECK_SUCCESS_FCT(statusTmp, phDriver_PinConfig(
					PHDRIVER_PIN_SSEL,
					PH_DRIVER_PINFUNC_OUTPUT,
					&pinCfg));
			}
		#endif /* PHDRIVER_SOFT_SSEL*/

			if (((phbalReg_Type_t *)pBalDataParams)->bBalType != PHBAL_REG_TYPE_KERNEL_SPI)
			{
				/* Busy pin (nothing but IRQ for Triton) as input and pullup enabled.
				 * Helps during poll operation, Do Not Remove. */
				pinCfg.bPullSelect = PHDRIVER_PIN_BUSY_PULL_CFG;
				(void)phDriver_PinConfig(PHDRIVER_PIN_BUSY, PH_DRIVER_PINFUNC_INPUT, &pinCfg);
			}
			bHalInitState = PHHAL_HW_STATE_CMD1;
			/* no break */

#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
		case PHHAL_HW_STATE_CMD1:
			/* Reset Ncx3321 Front-end. */
			platformSpiWAKEUP_WriteDirect(OFF);
			bHalInitState = PHHAL_HW_STATE_CMD2;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD2:
			/* Do Nothing */
			bHalInitState = PHHAL_HW_STATE_CMD3;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD3:
			/* Do Nothing */
			bHalInitState = PHHAL_HW_STATE_CMD4;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD4:
			/* Do Nothing */
			bHalInitState = PHHAL_HW_STATE_CMD5;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD5:
			/* Do Nothing */
			bHalInitState = PHHAL_HW_STATE_CMD6;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD6:
			/* Do Nothing */
			bHalInitState = PHHAL_HW_STATE_CMD7;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD7:
			/* Reset Ncx3321 Front-end. */
			platformSpiWAKEUP_WriteDirect(ON);
			bHalInitState = 11u;
			return PH_STATUS_INPROCESS;

		case 11u:
			/* Do Nothing */
			bHalInitState = 12u;
			return PH_STATUS_INPROCESS;

		case 12u:
/* 010A_06 */
			// PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_EnBootNormalMode(pDataParams));
			statusTmp = phhalHw_Ncx3321_EnBootNormalMode(pDataParams);
			
			if(statusTmp == PH_STATUS_INPROCESS)
			{
				if(bStateHaltCnt++ > 20u)
				{
					// bHalInitState = PHHAL_HW_STATE_IDLE2;
					bStateHaltCnt = 0u;
					break;
				}
				else
				{
					return statusTmp;
				}				
			}
/* 010A_06 */

			/* Switch to Normal Mode and Read Ideal Event*/
			if( PH_ERR_SUCCESS != (statusTmp & PH_ERR_MASK ))
			{
				break;
			}

#else
		case PHHAL_HW_STATE_CMD1:
			/* Reset Ncx3321 Front-end. */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_Reset());
			if( PH_ERR_SUCCESS != (statusTmp & PH_ERR_MASK ))
			{
				break;
			}
			else
			{
				bHalInitState = PHHAL_HW_STATE_CMD2;
				return PH_STATUS_INPROCESS;
			}
			/* no break */

		case PHHAL_HW_STATE_CMD2:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_EnBootNormalMode(pDataParams));
			/* Switch to Normal Mode and Read Ideal Event*/
			if( PH_ERR_SUCCESS != (statusTmp & PH_ERR_MASK ))
			{
				break;
			}

#endif
			(void)phTools_EventCreate(&pDataParams->HwEventObj,pDataParams->pHalPollFunc, pDataParams);
			xEventHandle = &(pDataParams->HwEventObj);

			/* This assignment has to be done after NCx3321 is confirmed to
			 * be normal mode */
			pDataParams->pRFISRCallback         = &phhalHw_Ncx3321_ISR_Callback;
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;

	}

	bHalInitState = PHHAL_HW_STATE_IDLE;
    phhalHw_Ncx3321_Int_ResetState();
	return statusTmp;
}

static FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EnBootNormalMode(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventStatusReg = 0x0U;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bEvent = 0x0U;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wPktLength = 0x0U;

  static VAR(uint32, ANFCRL_VAR) wStartTime = 0U;
  VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;
	switch(g_bEnBootNormalModeState)
	{
		case PHHAL_HW_STATE_IDLE:
		    PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_SwitchModeBootNormal(pDataParams));
		    PH_CHECK_SUCCESS(status);
			g_bEnBootNormalModeState = PHHAL_HW_STATE_CMD1;
			// wStartTime = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_MSECS);
			/* no break */

		case PHHAL_HW_STATE_CMD1:
#if defined (PHDRIVER_CYT2B9)	/* NIDEC_PORTING */
			/* Wait till IDEL EVENT is been triggered by NCX3321. */
			if (phDriver_PinRead(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INPUT) == 0U)
			{
				// dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_MSECS, wStartTime);
				return PH_STATUS_INPROCESS;
			}

#else
			/* Wait till IDEL EVENT is been triggered by NCX3321. */
			if (phDriver_PinRead(PHDRIVER_PIN_IRQ, PH_DRIVER_PINFUNC_INPUT) == 0U)

			{
				dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_MSECS, wStartTime);

				/* Check for timer overflow, abort if timer overflow happens */
				if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
				{
					return PH_ERR_ABORTED;
				}
				else
				{
					if(dwElapsedTime < PHHAL_HW_ABORT_EVT_TIMEOUT)
					{
						return PH_STATUS_INPROCESS;
					}
					else
					{
						/* If IRQ not response after wait time, leave with PH_ERR_INTERNAL_ERROR error code. */
						return PH_ERR_INTERNAL_ERROR;
					}
				}
			}

#endif
			g_bEnBootNormalModeState = PHHAL_HW_STATE_IDLE;

			/*Doing split read because we don't know whether ERROR also occurred, accordingly
			 * the length of response will change  */
			PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Read(
				pDataParams,
				&pDataParams->sIrqResp.aISRReadBuf[0],
				EVTS_HEADER_BYTES + 1U
				));

			bEvent = pDataParams->sIrqResp.aISRReadBuf[TLV_TYPE_FIELD_INDEX];

			wPktLength = pDataParams->sIrqResp.aISRReadBuf[TLV_LENGTH_MSB_INDEX];
			wPktLength <<=  8;
			wPktLength |= pDataParams->sIrqResp.aISRReadBuf[TLV_LENGTH_LSB_INDEX];

			if (!( (wPktLength == 0x08U) || (wPktLength == 0x0CU) ))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
			}

			PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Read(
				pDataParams,
				&pDataParams->sIrqResp.aISRReadBuf[0],
				wPktLength + 1U
				));

			dwEventStatusReg = (uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX];
			dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 1U]) << 8U ;
			dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 2U]) << 16U;
			dwEventStatusReg |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 3U]) << 24U;

			pDataParams->dwEventStatus = (uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 4U];
			pDataParams->dwEventStatus |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 5U]) << 8U ;
			pDataParams->dwEventStatus |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 6U]) << 16U;
			pDataParams->dwEventStatus |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 7U]) << 24U;


			/* Check if NCX3321 Booted correctly*/
			if (!((bEvent == 0x80U) && (dwEventStatusReg == PH_NCX3321_EVT_BOOT)))
			{
				if((dwEventStatusReg & PH_NCX3321_EVT_GENERAL_ERROR) != 0u)
				{
					pDataParams->dwGenError = (uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 8U];
					pDataParams->dwGenError |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 9U]) << 8U ;
					pDataParams->dwGenError |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 10U]) << 16U;
					pDataParams->dwGenError |= ((uint32) pDataParams->sIrqResp.aISRReadBuf[EVENT_LSB_INDEX + 11U]) << 24U;
				}
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERFACE_ERROR, PH_COMP_HAL);
			}
	}

	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_DeInit(
                P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								)
{
	/* De-Initialize data parameters */
	pDataParams->wId                    = 0U;
	pDataParams->pBalDataParams         = NULL;
	pDataParams->pKeyStoreDataParams    = NULL;
	pDataParams->pTxBuffer              = NULL;
	pDataParams->wTxBufSize             = 0U;
	pDataParams->wTxBufLen              = 0U;
	pDataParams->pRxBuffer              = NULL;
	pDataParams->wRxBufSize             = 0U;
	pDataParams->wRxBufLen              = 0U;
	pDataParams->wRxBufStartPos         = 0U;
	pDataParams->wTxBufStartPos         = 0U;
	pDataParams->bCardType              = PHHAL_HW_CARDTYPE_UNKNOWN;
	pDataParams->bTimeoutUnit           = PHHAL_HW_TIME_MICROSECONDS;
	pDataParams->wFieldOffTime          = PHHAL_HW_FIELD_OFF_DEFAULT;
	pDataParams->wFieldRecoveryTime     = PHHAL_HW_FIELD_RECOVERY_DEFAULT;
	pDataParams->bSymbolStart           = PH_OFF;
	pDataParams->bSymbolEnd             = PH_OFF;
	pDataParams->wAdditionalInfo        = 0U;
	pDataParams->bRfResetAfterTo        = PH_OFF;
	pDataParams->bRxMultiple            = PH_OFF;
	pDataParams->bActiveMode            = PH_OFF;
	pDataParams->bRfca                  = PH_ON;
	pDataParams->wTargetMode            = PH_OFF;
	pDataParams->bOpeMode               = RD_LIB_MODE_NFC;
	pDataParams->dwFelicaEmdReg         = 0U;
	pDataParams->bJewelActivated        = PH_OFF;
	pDataParams->bLpcdConfig            = 0U;
	pDataParams->bLpcdState             = PHHAL_HW_STATE_IDLE;
	pDataParams->wWakeupCounterInMs     = 0U;
	pDataParams->wLPCDWakeupCounterInMs = 0U;
	pDataParams->bCTSEvent              = PH_OFF;
	pDataParams->bRFONEvent             = PH_OFF;
	pDataParams->dwEventStatus          = 0U;
	pDataParams->dwEventReceived        = 0U;
	pDataParams->dwLpcdRefVal           = 0U;
	pDataParams->dwTxWaitMs             = 0U;
	pDataParams->bMfcCryptoEnabled      = PH_OFF;
	pDataParams->bCardMode              = PH_OFF;
	pDataParams->bPollGuardTimeFlag     = PH_OFF;
	pDataParams->dwExpectedEvent        = 0U;
	pDataParams->bNfcipMode             = PH_OFF;
	pDataParams->bSsTx1ConfigIsConfigured = 0U;
	pDataParams->bSsTx2ConfigIsConfigured = 0U;
	pDataParams->dwSetSsTx1ConfigValue = 0x00U;
	pDataParams->dwSetSsTx2ConfigValue = 0x00U;
	pDataParams->sIrqResp.pHandlerModeBuffPtr =  NULL;

	/* Non-Blocking Handle parameter reset */
	pDataParams->bSendState = 0U;
	pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_OFF;
	g_bEnBootNormalModeState = PHHAL_HW_STATE_IDLE;
	g_bApplyProtocolState = PHHAL_HW_STATE_IDLE;
	g_bExchangeState = PHHAL_HW_STATE_IDLE;
	g_bTransmitState = PHHAL_HW_STATE_IDLE;
	g_bReceiveState = PHHAL_HW_STATE_IDLE;
	g_bAutocollState = PHHAL_HW_STATE_IDLE;
	g_bWaitState = PHHAL_HW_STATE_IDLE;
	g_bEventWaitState = PHHAL_HW_STATE_IDLE;
	g_bFieldOffState = PHHAL_HW_STATE_IDLE;

    phhalHw_Ncx3321_Int_ResetState();
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_AsyncAbort(
                   P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									 )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;

	/* Post Abort Event. */
	PH_CHECK_SUCCESS_FCT(status, phTools_EventPost(
		&pDataParams->HwEventObj,
		E_EVENT_OPT_NONE,
		E_EVENT_ABORT,
		NULL));
	return PH_ERR_SUCCESS;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldOn(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								  )
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRFONconfig = 0U;

	if(pDataParams->bRfca == PH_OFF)
	{
		bRFONconfig |= 0x01U;
	}

	if(pDataParams->bActiveMode == PH_ON)
	{
		bRFONconfig |= 0x02U;
	}
	PH_CHECK_INPROCESS_FCT(statusTmp,
			phhalHw_Ncx3321_Instr_RfOn(pDataParams, bRFONconfig));

	if ((statusTmp & PH_ERR_MASK) == PH_ERR_NCX3321_EXTERNAL_FIELD_ERROR)
	{
		statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_RF_ERROR, PH_COMP_HAL);
	}
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldOff(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	switch(g_bFieldOffState)
	{
		case PHHAL_HW_STATE_IDLE: /* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig(pDataParams, PHHAL_HW_CONFIG_SET_EMD, PH_OFF));
			PH_CHECK_SUCCESS(statusTmp);
			g_bFieldOffState = PHHAL_HW_STATE_CMD1;
			/*No break*/
		case PHHAL_HW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_RfOff(pDataParams));
			g_bFieldOffState = PHHAL_HW_STATE_IDLE;
			/*No break*/
	}
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldReset(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    switch(pDataParams->bFieldResetState)
    {
        case PHHAL_FIELD_RESET_STATE_FIELD_OFF:
            /* Switch off the field */
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_FieldOff(pDataParams));
            if(statusTmp == PH_ERR_SUCCESS)
            {
                pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_OFF_WAIT;
                return PH_STATUS_INPROCESS;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_OFF_WAIT:
            /* Check for field-off timeout */
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_Wait(pDataParams,PHHAL_HW_TIME_MILLISECONDS, pDataParams->wFieldOffTime));
            if(statusTmp == PH_ERR_SUCCESS)
            {
                pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_ON;
                return PH_STATUS_INPROCESS;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_ON:
            /* Switch on the field again */
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_FieldOn(pDataParams));
            if(statusTmp == PH_ERR_SUCCESS)
            {
                pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_ON_WAIT;
                return PH_STATUS_INPROCESS;
            }
            else
            {
                break;
            }
        case PHHAL_FIELD_RESET_STATE_FIELD_ON_WAIT:
            /* Check for field-recovery timeout */
            PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_Wait(pDataParams,PHHAL_HW_TIME_MILLISECONDS, pDataParams->wFieldRecoveryTime));
            break;
    }
    pDataParams->bFieldResetState = PHHAL_FIELD_RESET_STATE_FIELD_OFF;
    return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_ApplyProtocolSettings(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        VAR(uint8, ANFCRL_VAR) bCardType
												)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwRegisterValue = 0x00U;
	P2VAR(phApplyProtocolParam_t, AUTOMATIC, ANFCRL_APPL_DATA) pBackup = &g_sApplyProtocolParam;

	switch (g_bApplyProtocolState)
	{
		case PHHAL_HW_STATE_IDLE:
			/* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig(pDataParams, PHHAL_HW_CONFIG_SET_EMD, PH_OFF));
			PH_CHECK_SUCCESS(statusTmp);
			pBackup->pShadowDefault = NULL;
			/* Store new card type */
			if (bCardType != PHHAL_HW_CARDTYPE_CURRENT)
			{
				pDataParams->bCardType = bCardType;
				pDataParams->bTimeoutUnit = PHHAL_HW_TIME_MICROSECONDS;
				pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TIMEOUT_VALUE_US] = 0;
				pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS] = 0;
				pBackup->bUseDefaultShadow = 1U;
			}
			else
			{
				pBackup->bUseDefaultShadow = 0U;
			}

			pDataParams->bActiveMode = PH_OFF;
			pDataParams->wTargetMode = PH_OFF;
			pDataParams->bJewelActivated = PH_OFF;
			pDataParams->bNfcipMode = PH_OFF;

			g_bApplyProtocolState = PHHAL_HW_STATE_CMD1;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHHAL_HW_STATE_CMD1:
			/* Configure reader IC for current card */
			switch (pDataParams->bCardType)
			{
				/* configure hardware for ISO 14443A */
				case PHHAL_HW_CARDTYPE_ISO14443A:
					/* Use 14443a default shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_ISO14443A_106_MILLER,
									PHHAL_HW_NCX3321_RF_RX_ISO14443A_106_MANCH_SUBC));
					if (statusTmp == PH_ERR_SUCCESS)
					{
						SET_NCX3321_SHADOW(wNcx3321_DefaultShadow_I14443a);
					}
					break;

				case PHHAL_HW_CARDTYPE_ISO14443B:
					/* Use 14443b shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_ISO14443B_106_NRZ,
									PHHAL_HW_NCX3321_RF_RX_ISO14443B_106_BPSK));
					if (statusTmp == PH_ERR_SUCCESS)
					{
						SET_NCX3321_SHADOW(wNcx3321_DefaultShadow_I14443b);
					}
					break;

				case PHHAL_HW_CARDTYPE_FELICA_212:
					/* Use Felica shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_FELICA_212, PHHAL_HW_NCX3321_RF_RX_FELICA_212));
					if (statusTmp == PH_ERR_SUCCESS)
					{
						SET_NCX3321_SHADOW(wNcx3321_DefaultShadow_Felica);
					}
					break;

				case PHHAL_HW_CARDTYPE_FELICA_424:
					/* Use Felica shadow for 424*/
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_FELICA_424, PHHAL_HW_NCX3321_RF_RX_FELICA_424));
					if (statusTmp == PH_ERR_SUCCESS)
					{
						SET_NCX3321_SHADOW(wNcx3321_DefaultShadow_Felica_424);
					}
					break;

				case PHHAL_HW_CARDTYPE_ISO15693:
					/* Use 15693 shadow */
					/* Masking RxDataRate with Minimum Configuration Index */
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_Instr_LoadRfConfiguration(pDataParams, PHHAL_HW_NCX3321_RF_TX_ISO15693_26_1OF4_ASK100,
									PHHAL_HW_NCX3321_RF_RX_ISO15693_26_SC));
					if (statusTmp == PH_ERR_SUCCESS)
					{
						SET_NCX3321_SHADOW(wNcx3321_DefaultShadow_I15693);
					}
					break;

				default:
					statusTmp = PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					break;
			}
			PH_BREAK_ON_FAILURE(statusTmp);
			/* Copy over default shadow contents into current shadow. */
			if (0U != pBackup->bUseDefaultShadow)
			{
				/* Initialize config shadow */
				(void) memset(pDataParams->wCfgShadow, 0x00, (sizeof(uint16) * PHHAL_HW_NCX3321_SHADOW_COUNT));
				pBackup->wIndex = 0U;
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD2;
			}
			else
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD3;
			}
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHHAL_HW_STATE_CMD2:
			if (pBackup->wIndex < (pBackup->wShadowCount))
			{
				pBackup->wConfig = pBackup->pShadowDefault[(pBackup->wIndex) << 1U];

				/* Updated TxCRC and RxCRC in shadow due to LoadRFConfig */
				if ((pBackup->wConfig == PHHAL_HW_CONFIG_TXCRC) || (pBackup->wConfig == PHHAL_HW_CONFIG_RXCRC) || (pBackup->wConfig == PHHAL_HW_CONFIG_TRXCRC))
				{
					if (pDataParams->bCardType == PHHAL_HW_CARDTYPE_ISO14443B)
					{
						PH_CHECK_INPROCESS_FCT(statusTmp,
								phhalHw_Ncx3321_SetConfig(pDataParams, pBackup->wConfig, pBackup->pShadowDefault[((pBackup->wIndex) << 1U) + 1U]));
					}
					else
					{
						/* Write config data into shadow */
						pDataParams->wCfgShadow[pBackup->wConfig] = pBackup->pShadowDefault[((pBackup->wIndex) << 1U) + 1U];
					}
				}

				/* Configure the RxWait using Shadow values */
				if (pBackup->wConfig == PHHAL_HW_CONFIG_RXWAIT_US)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp,
							phhalHw_Ncx3321_SetConfig(pDataParams, pBackup->wConfig, pBackup->pShadowDefault[((pBackup->wIndex) << 1U) + 1U]));
				}

				/* Configure the TxWait using Shadow values */
				if (pBackup->wConfig == PHHAL_HW_CONFIG_TXWAIT_US)
				{
					if (((pDataParams->bCardType == PHHAL_HW_CARDTYPE_ISO14443A) || (pDataParams->bCardType == PHHAL_HW_CARDTYPE_ISO14443B))
							&& (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO))
					{
						/* Configure TxWait of 500 micro seconds in EMVCo mode. */
						PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig(pDataParams, pBackup->wConfig, 500U));
					}
					else
					{
						PH_CHECK_INPROCESS_FCT(statusTmp,
								phhalHw_Ncx3321_SetConfig(pDataParams, pBackup->wConfig, pBackup->pShadowDefault[((pBackup->wIndex) << 1U) + 1U]));
					}
				}
				if (statusTmp == PH_ERR_SUCCESS)
				{
					pDataParams->wCfgShadow[pBackup->wConfig] = pBackup->pShadowDefault[((pBackup->wIndex) << 1U) + 1U];
					++(pBackup->wIndex);
				}
				else
				{
					/*if any error return*/
					break;
				}
				return PH_STATUS_INPROCESS;
			}
			g_bApplyProtocolState = PHHAL_HW_STATE_CMD3;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHHAL_HW_STATE_CMD3:
			/* MIFARE Crypto1 state is disabled by default */
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_SetConfig(pDataParams, PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO1, PH_ON));
			PH_BREAK_ON_FAILURE(statusTmp);
			/* Configure value of the CLIF_SS_TX1_RMCFG and CLIF_SS_TX2_RMCFG registers in case it is reset after LPCD */
			if(0U != pDataParams->bSsTx1ConfigIsConfigured)
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD4;
			}
			else
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD6;
			}
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHHAL_HW_STATE_CMD4:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, CLIF_SS_TX1_RMCFG, &dwRegisterValue));
			if(pDataParams->dwSetSsTx1ConfigValue != dwRegisterValue)
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD5;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Do nothing */
			}
			g_bApplyProtocolState = PHHAL_HW_STATE_CMD6;
			return PH_STATUS_INPROCESS;
			/* no break */
		case PHHAL_HW_STATE_CMD5:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_SS_TX1_RMCFG, pDataParams->dwSetSsTx1ConfigValue));
			PH_BREAK_ON_FAILURE(statusTmp);
			if(0U != pDataParams->bSsTx2ConfigIsConfigured)
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD6;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Do nothing */
			}
			break;
		case PHHAL_HW_STATE_CMD6:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, CLIF_SS_TX2_RMCFG, &dwRegisterValue));
			if(pDataParams->dwSetSsTx2ConfigValue != dwRegisterValue)
			{
				g_bApplyProtocolState = PHHAL_HW_STATE_CMD7;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				/* Do nothing */
			}
			break;
		case PHHAL_HW_STATE_CMD7:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_SS_TX2_RMCFG, pDataParams->dwSetSsTx2ConfigValue));
			break;
		default:
			statusTmp = PH_ERR_INTERNAL_ERROR;
			break;
	}

	g_bApplyProtocolState = PHHAL_HW_STATE_IDLE;
	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wConfig,
                  VAR(uint16, ANFCRL_VAR) wValue
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSizeOfRegTypeValueSets = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwRegister = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTemp = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwValue = 0U;
	VAR(double, ANFCRL_VAR) PH_MEMLOC_REM fTime = 0.0;	/* NIDEC_PORTING */
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF wRegTypeValueSets[12] = {0U};
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pBuffer = NULL;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferSize = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferLen = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSetConfigState = 0U;

	/* Check if Apply Protocol is already done. */
	if (pDataParams->bCardType == PHHAL_HW_CARDTYPE_UNKNOWN)
	{
		return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
	}

	switch(wConfig)
	{
		case PHHAL_HW_CONFIG_TXBUFFER_OFFSET:
			/* Update TX buffer offset based on the command used to buffer the data in HAL. */
			if(*pDataParams->pTxBuffer == PHHAL_HW_NCX3321_INSTR_EXCHANGE_RF_DATA)
			{
				pDataParams->wAdditionalInfo = wValue + PHHAL_HW_NCX3321_EXCHANGE_HEADER_SIZE;
			}
			else
			{
				pDataParams->wAdditionalInfo = wValue + PHHAL_HW_NCX3321_TRANSMIT_HEADER_SIZE;
			}
			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				 pDataParams->wAdditionalInfo += 1U;
			}
			break;

		case PHHAL_HW_CONFIG_RXBUFFER_STARTPOS:
			/* Retrieve RxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetRxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Boundary check */
			if (wValue >= pDataParams->wRxBufSize)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_HAL);
			}

			/* Set start position */
			pDataParams->wRxBufStartPos = wValue;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_LENGTH:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Check parameter, must not exceed TxBufferSize */
			if (wValue > pDataParams->wTxBufSize)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_HAL);
			}
			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				wValue++;
			}
			/* set buffer length */
			pDataParams->wTxBufLen = wValue;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Check parameter, must not exceed TxBufferSize */
			if (pDataParams->wAdditionalInfo >= pDataParams->wTxBufSize)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_HAL);
			}

			pBuffer[pDataParams->wAdditionalInfo] = (uint8)wValue;

			break;

		case PHHAL_HW_CONFIG_TXDATARATE_FRAMING:

			PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_Int_SetTxDataRateFraming(pDataParams,wConfig,wValue));
			break;

		case PHHAL_HW_CONFIG_RXDATARATE_FRAMING:

			if(0U == bSetConfigState)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_Int_SetRxDataRateFraming(pDataParams,wConfig,wValue));
				PH_BREAK_ON_FAILURE(statusTmp);
				bSetConfigState = 1U;
			}

			if(1U == bSetConfigState)
			{
				if (((pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXDATARATE_FRAMING] & PHHAL_HW_RF_DATARATE_OPTION_MASK) != PHHAL_HW_RF_DATARATE_106)
					&& ((pDataParams->wCfgShadow[wConfig] & PHHAL_HW_RF_DATARATE_OPTION_MASK) == PHHAL_HW_RF_DATARATE_106))
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(pDataParams, PHHAL_HW_CONFIG_RXWAIT_US, 70U));
					PH_BREAK_ON_FAILURE(statusTmp);
					bSetConfigState = 0U;
				}
			}
			break;

		case PHHAL_HW_CONFIG_RFCA:

			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			pDataParams->bRfca = (uint8) wValue;
			break;


		case PHHAL_HW_CONFIG_SUBCARRIER:

			if (pDataParams->wCfgShadow[wConfig] != wValue)
			{
				switch(g_bSetConfigState)
				{
					case PHHAL_HW_STATE_IDLE:
						/* Parameter check */
						if (pDataParams->bCardType != PHHAL_HW_CARDTYPE_ISO15693)
						{
							return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
						}

						/* Only single subcarrier to be used while reception by ISO15693 */
						if ((pDataParams->bCardType == PHHAL_HW_CARDTYPE_ISO15693) && (wValue != PHHAL_HW_SUBCARRIER_SINGLE))
						{
							return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
						}
						g_bSetConfigState = PHHAL_HW_STATE_CMD1;
						/* no break */
					case PHHAL_HW_STATE_CMD1:
						/* Evaluate hardware settings */
						PH_CHECK_INPROCESS_FCT(statusTmp,phhalHw_Ncx3321_Int_SetCardMode(
								pDataParams,
								pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXDATARATE_FRAMING],
								pDataParams->wCfgShadow[PHHAL_HW_CONFIG_RXDATARATE_FRAMING],
								wValue));
						PH_BREAK_ON_FAILURE(statusTmp);
						/* Update Subcarrier setting */
						pDataParams->wCfgShadow[PHHAL_HW_CONFIG_SUBCARRIER] = wValue;
						break;
					default:
						break;
				}
				g_bSetConfigState = PHHAL_HW_STATE_IDLE;
			}

			break;

		case PHHAL_HW_CONFIG_POLL_GUARD_TIME_US:
			if ((wValue == 0x00U) || (pDataParams->bPollGuardTimeFlag == PH_ON))
			{
				return PH_ERR_SUCCESS;
			}

			pDataParams->bPollGuardTimeFlag = PH_ON;
			(void)phTools_EventClear(
				&pDataParams->HwEventObj,
				E_EVENT_OPT_NONE,
				E_EVENT_GT_EXP,
				NULL);

			pDataParams->wGuardTimeStart = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
			pDataParams->wGuardTimePeriod = wValue;
			break;

		case PHHAL_HW_CONFIG_OPE_MODE:
			pDataParams->bOpeMode = (uint8) wValue;
			break;

		case PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT:

			if (wValue == PH_OFF)
			{
				pDataParams->bRfResetAfterTo = PH_OFF;
			}
			else
			{
				pDataParams->bRfResetAfterTo = PH_ON;
			}

			break;

		case PHHAL_HW_CONFIG_PARITY:
		case PHHAL_HW_CONFIG_ASK100:
		case PHHAL_HW_CONFIG_RXWAIT_US:
			if (pDataParams->wCfgShadow[wConfig] != wValue)
			{
				/* Use internal set config */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(pDataParams, wConfig, wValue));
				PH_CHECK_SUCCESS(statusTmp);

				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
			}
			break;

		case PHHAL_HW_CONFIG_TXCRC:
		case PHHAL_HW_CONFIG_RXCRC:
		case PHHAL_HW_CONFIG_TRXCRC:
			/* Check shadow while performing configuration in EMVCo mode, to have good timing performance.
			 * As in EMVCo mode ApplyProtocolSettings shall always be followed by FieldOn function. */
			if (pDataParams->bOpeMode == RD_LIB_MODE_EMVCO)
			{
				if (pDataParams->wCfgShadow[wConfig] != wValue)
				{
					/* Use internal set config */
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(pDataParams, wConfig, wValue));
					PH_CHECK_SUCCESS(statusTmp);
				}
			}
			else
			{
				/* NOTE : Do not perform shadow check, as FieldOn function of NCX3321 FW performs
				 * LoadRFConfiguration of previously applied Protocol configuration and the shadow
				 * value of HAL for Tx and Rx CRC doesn't have the value that is configured on CLIF. */

				/* Use internal set config */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(pDataParams, wConfig, wValue));
				PH_CHECK_SUCCESS(statusTmp);
			}

			/* Write config data into shadow */
			pDataParams->wCfgShadow[wConfig] = wValue;
			break;

		case PHHAL_HW_CONFIG_TXLASTBITS:

			if (pDataParams->wCfgShadow[wConfig] != wValue)
			{
				/* Check parameter */
				if (wValue > MASK_TX_LASTBITS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}

				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
			}
			break;

		case PHHAL_HW_CONFIG_RXALIGN:

			if (pDataParams->wCfgShadow[wConfig] != wValue)
			{
				/* Check the parameter */
				if (wValue >  MASK_RX_LASTBITS)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_ClearNSetRegFields(pDataParams,
							CLIF_RX_PROTOCOL_CONFIG, CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_MASK,
							CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_POS, wValue));
				PH_CHECK_SUCCESS(statusTmp);
				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
			}
			break;

		case PHHAL_HW_CONFIG_TXWAIT_US:

			if (pDataParams->wCfgShadow[wConfig] != wValue)
			{
				/* Set TxWait */
				dwValue = PHHAL_HW_NCX3321_TX_RX_PRESCALER;
				dwTemp = wValue;

				if(0U != dwTemp)
				{
					fTime = (double)(((double)dwTemp * 13.56) / (double)(dwValue));	/* NIDEC_PORTING */
					dwTemp = (uint32)fTime;
					dwValue |= (uint32)((dwTemp ) << CLIF_TX_WAIT_TX_WAIT_VALUE_POS);
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_TX_WAIT, dwValue));
					PH_CHECK_SUCCESS(statusTmp);
				}
				else
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_TX_WAIT, dwValue));
					PH_CHECK_SUCCESS(statusTmp);
				}

				/* Write configuration data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
			}
			break;

		case PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO1:
			/* Disable crypto, enabling is not supported */
			if ((wValue != PH_OFF) && ( pDataParams->bMfcCryptoEnabled == PH_ON))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, SYSTEM_CONFIG, (~((uint32)SYSTEM_CONFIG_MFC_CRYPTO_ON_MASK))));
				PH_BREAK_ON_FAILURE(statusTmp);
				pDataParams->bMfcCryptoEnabled = PH_OFF;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US:
			if ((pDataParams->wCfgShadow[wConfig] != wValue) ||
				(pDataParams->bTimeoutUnit != PHHAL_HW_TIME_MICROSECONDS) ||
				(pDataParams->bOpeMode != RD_LIB_MODE_EMVCO))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetTmo(pDataParams, wValue, PHHAL_HW_TIME_MICROSECONDS));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
				pDataParams->bTimeoutUnit = PHHAL_HW_TIME_MICROSECONDS;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS:
			if ((pDataParams->wCfgShadow[wConfig] != wValue) ||
				(pDataParams->bTimeoutUnit != PHHAL_HW_TIME_MILLISECONDS) ||
				(pDataParams->bOpeMode != RD_LIB_MODE_EMVCO))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetTmo(pDataParams, wValue, PHHAL_HW_TIME_MILLISECONDS));
				PH_BREAK_ON_FAILURE(statusTmp);
				/* Write config data into shadow */
				pDataParams->wCfgShadow[wConfig] = wValue;
				pDataParams->bTimeoutUnit = PHHAL_HW_TIME_MILLISECONDS;
			}
			break;

		case PHHAL_HW_CONFIG_NFCIP_STARTBYTE:
			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			pDataParams->bNfcipMode = (uint8) wValue;
			break;

		case PHHAL_HW_CONFIG_JEWEL_MODE:

			if (wValue == PH_ON)
			{
				pDataParams->bJewelActivated = (uint8) wValue;
				/* Enable FrameStep in Transceiver Control Register. */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterOrMask( pDataParams, CLIF_TRANSCEIVE_CONTROL, CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_MASK));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else if (wValue == PH_OFF)
			{
				pDataParams->bJewelActivated = (uint8) wValue;
				/* Disable FrameStep in Transceiver Control Register. */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask( pDataParams, CLIF_TRANSCEIVE_CONTROL, ~((uint32)CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_MASK)));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			break;

		case PHHAL_HW_CONFIG_SET_EMD:
			if (pDataParams->bEmdFlag != wValue)
			{
				if(0U == bSetConfigState)
				{
					pDataParams->bEmdFlag = (uint8) wValue;
					if (wValue == 0x1U)
					{
						dwRegister = 0U;
						if (pDataParams->bCardType != PHHAL_HW_CARDTYPE_ISO14443A)
						{
							/* Read the EMD CONTROL Register to get RM EMD SENSITIVITY field */
							PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, EMD_CONTROL, &dwRegister));
							PH_CHECK_SUCCESS(statusTmp);
							/* Retain only the RM EMD SENSITIVITY value field.
							 * In case of Type A this value needs to be zero. */
							dwRegister &= (uint32)(EMD_CONTROL_EMD_RM_EMD_SENSITIVITY_MASK);
						}

						if(pDataParams->bOpeMode != RD_LIB_MODE_ISO)
						{
							dwRegister |= PHHAL_HW_NCX3321_EMD_3P0;
						}
						else
						{
							dwRegister |= PHHAL_HW_NCX3321_ISO_EMD;
						}
						bSetConfigState = 1U;
					}
					else
					{
						bSetConfigState = 2U;
					}
				}

				if(1U == bSetConfigState)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, EMD_CONTROL, dwRegister));
				}

				if(2U == bSetConfigState)
				{
					/* Clear EMD Enable bit in EMD Control Register */
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, EMD_CONTROL, (~(uint32)EMD_CONTROL_EMD_ENABLE_MASK)));
				}

				bSetConfigState = 0U;
			}
			break;

		case PHHAL_HW_CONFIG_RXMULTIPLE:

			if (wValue == PH_ON)
			{
				pDataParams->bRxMultiple = PH_ON;

				/* Enable Rx Multiple in Transceiver Control Register. */
				dwTemp = CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TRANSCEIVE_CONTROL;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/* Reset Timer1 (FDT Timer) stop condition. */
				dwTemp = (uint32) ~(CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				pDataParams->bRxMultiple = PH_OFF;

				/* Disable Rx Multiple in Transceiver Control Register. */
				dwTemp = ~((uint32 )CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TRANSCEIVE_CONTROL;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				/* Set Timer1 (FDT Timer) stop condition to Stop on RX Start condition. */
				dwTemp = CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;

		case PHHAL_HW_CONFIG_MFHALTED:
			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			if (wValue == PH_ON)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterOrMask(pDataParams, SYSTEM_CONFIG, SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK));
				PH_CHECK_SUCCESS(statusTmp);
				pDataParams->bCardMode = PH_ON;
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, SYSTEM_CONFIG, ~((uint32)SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK)));
				PH_CHECK_SUCCESS(statusTmp);
				pDataParams->bCardMode = PH_OFF;
			}
			break;

		case PHHAL_HW_CONFIG_FIELD_OFF_TIME:
			/* Off time shall not be zero. */
			if (wValue == 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* Store off time. */
			pDataParams->wFieldOffTime = wValue;
			break;

		case PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME:
			/* Store recovery time. */
			pDataParams->wFieldRecoveryTime = wValue;
			break;

		case PHHAL_HW_CONFIG_SET_SYMBOL_SEND:

			/* check parameter */
			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* PH_ON implies Clearing Bit-3 (DataEn Bit in TxDataNum). */
			if (wValue == PH_ON)
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, CLIF_TX_FRAME_CONFIG, ~(uint32)CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK));
				PH_CHECK_SUCCESS(statusTmp);
			}
			/* PH_OFF implies Setting Bit-3 (DataEn Bit in TxDataNum). */
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterOrMask(pDataParams, CLIF_TX_FRAME_CONFIG, CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK));
				PH_CHECK_SUCCESS(statusTmp);
			}
			break;


		case PHHAL_HW_CONFIG_SYMBOL_START:

			/* Parameter check */
			if (pDataParams->bCardType != PHHAL_HW_CARDTYPE_ISO15693)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
			}

			/* Parameter check #2 */
			switch (wValue)
			{
				case PHHAL_HW_SYMBOL_I15693_SOF:
					if (pDataParams->bCardType != PHHAL_HW_CARDTYPE_ISO15693)
					{
						return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
					}
					break;
				case PH_OFF:
					break;
				default:
					return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
			}

			wSizeOfRegTypeValueSets = 0U;

			/*Clear the Bits of TX_CONFIG_TX_START_SYMBOL_MASK & DATA_ENABLE*/
			if (wValue == PH_OFF)
			{
				dwTemp = (uint32) ~(CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK | CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK);
			}
			else
			{
				dwTemp =  ~((uint32)CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK);
			}

			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TX_FRAME_CONFIG;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

			dwValue = 0U;

			/* Set new symbol */
			switch (wValue)
			{
				case PHHAL_HW_SYMBOL_I15693_SOF:
					dwValue = 0x3U;
					break;
				default:
					break;
			}

			/*Set the new value  */
			dwTemp = (uint32) ((dwValue << CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_POS) & CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK);
			dwTemp |= (uint32) ((dwValue << CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_POS) & CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TX_FRAME_CONFIG;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwTemp >> 24U);

			/*Send the array to the IC*/
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_CRCTYPE:

			if(0U == (wValue & (PHHAL_HW_CRCTYPE_CRC5 | PHHAL_HW_CRCTYPE_CRC16 | PHHAL_HW_CRCOPTION_INVERTED)))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			dwValue = 0U;
			/*dwRegister will contain all the bits that need to be zeroed out*/
			dwRegister = 0U;

			if(0U != (wValue & PHHAL_HW_CRCTYPE_CRC16))
			{
				dwRegister |= CLIF_CRC_TX_CONFIG_TX_CRC_TYPE_MASK;
			}
			else
			{
				/* QAC */
			}

			if(0U != (wValue & PHHAL_HW_CRCOPTION_INVERTED))
			{
				dwValue |= CLIF_CRC_TX_CONFIG_TX_CRC_INV_MASK;
			}
			else
			{
				dwRegister |= CLIF_CRC_TX_CONFIG_TX_CRC_INV_MASK;
			}

			if (0U != ((wValue & PHHAL_HW_CRCTYPE_CRC16)))
			{
				dwRegister |= CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_MASK;
				dwValue |= (0x3U << CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_POS);
			}


			wSizeOfRegTypeValueSets = 0U;

			/*Clear the Bits */
			dwTemp = (uint32) ~( dwRegister );
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

			/*Set the new value  */
			dwTemp = dwValue;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_CRC_TX_CONFIG;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>8U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>16U);
			wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8)(dwTemp>>24U);

			/*Send the array to the IC*/
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams,  wRegTypeValueSets, wSizeOfRegTypeValueSets));
			PH_CHECK_SUCCESS(statusTmp);

			break;

		case PHHAL_HW_CONFIG_TXWAIT_MS:
			/* Parameter checking */
			if (wValue > 650U) /* To set Max value for wValue in uS i.e, 0xFFFFU )*/
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			/* Store the value in terms of uS in shadow table*/
			pDataParams->dwTxWaitMs =  wValue;

			/* Set TxWait */
			dwValue = PHHAL_HW_NCX3321_TX_RX_PRESCALER;
			dwTemp = (uint32)wValue*1000U;
			if(0U != dwTemp)
			{
				fTime = (double)(((double)dwTemp * 13.56) / (double)(dwValue));	/* NIDEC_PORTING */
				dwTemp = (uint32)fTime;
				dwValue |= (uint32)((dwTemp ) << CLIF_TX_WAIT_TX_WAIT_VALUE_POS);
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_TX_WAIT, dwValue));
			}
			else
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, CLIF_TX_WAIT, dwValue));
			}
			break;

		case PHHAL_HW_CONFIG_SETMINFDT:

			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_SetMinFdt(pDataParams, wValue));
			break;

		case PHHAL_HW_CONFIG_RFON_INTERRUPT:
			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			if (wValue == PH_ON)
			{
				/* This will Enable RF-ON Interrupt in NCX3321. NCX3321 will send PH_NCX3321_EVT_RFON_DETECT
				 * after RF-ON interrupt*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, EVENT_ENABLE, EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK));
				PH_BREAK_ON_FAILURE(statusTmp);
				pDataParams->dwExpectedEvent = PH_NCX3321_EVT_RFON_DETECT;
			}
			else
			{
				/* Disable RF-ON Interrupt*/
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, EVENT_ENABLE, ~(uint32)EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK));
			}
			break;

		case PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_STATUS:
			/* check parameter */
			if ((wValue != PH_ON) && (wValue != PH_OFF))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			pDataParams->bCTSEvent = (uint8)wValue;
			break;

		case PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_ENABLE:
			if (wValue == PH_ON)
			{
				/* Enable CTS Event Interrupt*/
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, EVENT_ENABLE, EVENT_ENABLE_CTS_EVENT_ENABLE_MASK));
			}
			else if (wValue == PH_OFF)
			{
				/* Disable CTS Event Interrupt*/
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, EVENT_ENABLE, ~(uint32)EVENT_ENABLE_CTS_EVENT_ENABLE_MASK));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else /* check parameter */
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			break;

		case PHHAL_HW_NCX3321_CONFIG_LPCD_EVENT_ENABLE:
			if (wValue == PH_ON)
			{
				/* Enable LPCD Event */
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterOrMask(pDataParams, EVENT_ENABLE, EVENT_ENABLE_LPCD_EVENT_ENABLE_MASK));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else if (wValue == PH_OFF)
			{
				/* Disable LPCD Event */
				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams, EVENT_ENABLE, ~((uint32)EVENT_ENABLE_LPCD_EVENT_ENABLE_MASK)));
				PH_CHECK_SUCCESS(statusTmp);
			}
			else
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			break;
		case PHHAL_HW_NCX3321_CONFIG_EXPECTED_EVENT:
			if ((wValue < PH_NCX3321_EVT_BOOT) || (wValue >= PH_NCX3321_EVT_RFU))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			pDataParams->dwExpectedEvent = (uint32) wValue;
			break;

        case PHHAL_HW_NCX3321_CONFIG_RF_ON_EVENT_STATUS:
            /* check parameter */
            if ((wValue != PH_ON) && (wValue != PH_OFF))
            {
                return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
            }

            pDataParams->bRFONEvent = (uint8)wValue;
            break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD:
			if ((wValue == PH_ON) && (pDataParams->bOpeMode != RD_LIB_MODE_FELICA))
			{
				/* Before Setting FELICA_EMD bit, OpeMode need to be configured to RD_LIB_MODE_FELICA */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
			}

			/* Configure FeliCa EMD enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(pDataParams, wValue, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_ENABLE_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_CHECK:
			/* Configure EMD length byte check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(pDataParams, wValue, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_LEN_CHECK_ENABLE_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_CHECK:
			/* Configure RC byte check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(pDataParams, wValue, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_RC_CHECK_ENABLE_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_PROTOCOL_ERR_CHECK:
			/* Configure Protocol error check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(pDataParams, wValue, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_PROTOCOL_ERR_CHECK_ENABLE_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_INTEGRITY_ERR_CHECK:
			/* Configure Integrity error check enable bit in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(pDataParams, wValue, (uint32)FELICA_EMD_CONTROL_FELICA_EMD_INTEGRITY_ERR_CHECK_ENABLE_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MIN:
			/* Configure min length byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte(
					pDataParams,
					wValue,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_POS,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_MASK));
			PH_CHECK_SUCCESS(statusTmp);
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MAX:
			/* Configure max length byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_SUCCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte(
					pDataParams,
					wValue,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_POS,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_MASK));
			break;

		case PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_BYTE_VAL:
			/* Configure RC byte value in FELICA_EMD_CONTROL Register and shadow register */
			PH_CHECK_SUCCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte(
					pDataParams,
					wValue,
					(uint8)FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_POS,
					(uint32)FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_MASK));
			break;
		case PHHAL_HW_CONFIG_REQAEX:
			/*This state is a combination of 3 states:
			 * PHHAL_HW_CONFIG_RXWAIT_US,
			 * PHHAL_HW_CONFIG_TXCRC,
			 * PHHAL_HW_CONFIG_RXCRC
			 * */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig_Int(pDataParams, wConfig, wValue));

			break;
		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
	}

	bSetConfigState = 0U;
	return statusTmp;
}


FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_GetConfig(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wConfig,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
									)
{
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferLen;
  VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wBufferSize;
  VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwRegister;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pBuffer;

	switch(wConfig)
	{
		case PHHAL_HW_CONFIG_OPE_MODE:
			*pValue = pDataParams->bOpeMode;
			break;

		case PHHAL_HW_CONFIG_SET_EMD:
			*pValue = pDataParams->bEmdFlag;
			break;
		case PHHAL_HW_CONFIG_PARITY:
		case PHHAL_HW_CONFIG_TXCRC:
		case PHHAL_HW_CONFIG_RXCRC:
		case PHHAL_HW_CONFIG_TXLASTBITS:
		case PHHAL_HW_CONFIG_TXDATARATE_FRAMING:
		case PHHAL_HW_CONFIG_RXDATARATE_FRAMING:
		case PHHAL_HW_CONFIG_ASK100:
		case PHHAL_HW_CONFIG_SUBCARRIER:
		case PHHAL_HW_CONFIG_TXWAIT_US:
		case PHHAL_HW_CONFIG_RXWAIT_US:

		  /* Read config from shadow */
		  *pValue = pDataParams->wCfgShadow[wConfig];
		  break;

		case PHHAL_HW_CONFIG_TXBUFFER_OFFSET:
		case PHHAL_HW_CONFIG_RXLASTBITS:

			*pValue = pDataParams->wAdditionalInfo;
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_US:

			if (pDataParams->bTimeoutUnit == PHHAL_HW_TIME_MICROSECONDS)
			{
				*pValue = pDataParams->wCfgShadow[wConfig];
			}
			else
			{
				if (pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS] > (0xFFFFU / 1000U))
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_PARAMETER_OVERFLOW, PH_COMP_HAL);
				}
				*pValue = pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS] * 1000U;
			}
			break;

		case PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS:

			if (pDataParams->bTimeoutUnit == PHHAL_HW_TIME_MILLISECONDS)
			{
				*pValue = pDataParams->wCfgShadow[wConfig];
			}
			else
			{
				*pValue = pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TIMEOUT_VALUE_US] / 1000U;
			}
			break;

		case PHHAL_HW_CONFIG_FIELD_OFF_TIME:

			*pValue = pDataParams->wFieldOffTime;
			break;

		case PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME:

			*pValue = pDataParams->wFieldRecoveryTime;
			break;

		case PHHAL_HW_CONFIG_JEWEL_MODE:

			/* Write configuration data into shadow */
			*pValue = pDataParams->bJewelActivated;
			break;

		case PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT:

			*pValue = pDataParams->bRfResetAfterTo;
			break;

		case PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO1:

			/* Check Crypto1On Status */
			if ( pDataParams->bMfcCryptoEnabled == PH_ON)
			{
				*pValue = PH_OFF; /* OFF in this case means "Crypto1 not disabled --> enabled" */
			}
			else
			{
				*pValue = PH_ON; /* ON in this case means "Crypto1 is disabled" */
			}
			break;


		case PHHAL_HW_CONFIG_RXBUFFER_STARTPOS:

			/* Return parameter */
			*pValue = pDataParams->wRxBufStartPos;
			break;

		case PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE:

			/* Retrieve RxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetRxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Return parameter */
			*pValue = wBufferSize;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Return parameter */
			*pValue = wBufferSize;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER_LENGTH:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));
			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				if (wBufferLen != 0U)
				{
					wBufferLen--;
				}
			}
			/* Return parameter */
			*pValue = wBufferLen;
			break;

		case PHHAL_HW_CONFIG_TXBUFFER:

			/* Retrieve TxBuffer parameters */
			PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_Int_GetTxBuffer(pDataParams, &pBuffer, &wBufferLen, &wBufferSize));

			/* Check additional info parameter */
			if (pDataParams->wAdditionalInfo >= pDataParams->wTxBufSize)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_BUFFER_OVERFLOW, PH_COMP_HAL);
			}

			/* Retrieve TxBuffer byte */
			*pValue = (uint16)pBuffer[pDataParams->wAdditionalInfo];
			break;

		case PHHAL_HW_CONFIG_RXMULTIPLE:
			*pValue =  pDataParams->bRxMultiple;
			break;

		case PHHAL_HW_CONFIG_NFCIP_STARTBYTE:
			*pValue = pDataParams->bNfcipMode;
			break;

		case PHHAL_HW_CONFIG_TARGET_DATARATE_FRAMING:
			*pValue = pDataParams->wTargetMode;
			break;

		case PHHAL_HW_CONFIG_ACTIVEMODE:
			/* Return parameter */
			*pValue = (uint16)pDataParams->bActiveMode;
			break;

		case PHHAL_HW_CONFIG_CARD_TYPE:
			*pValue = pDataParams->bCardType;
			break;

		case PHHAL_HW_CONFIG_MFHALTED:
			PH_CHECK_INPROCESS_FCT(statusTmp,
				phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, SYSTEM_CONFIG, &dwRegister));
			PH_CHECK_SUCCESS(statusTmp);
			if(0U != (dwRegister & SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK))
			{
				*pValue = PH_ON;
			}
			else
			{
				*pValue = PH_OFF;
			}
			break;

		case PHHAL_HW_CONFIG_INT_RF_ON:

			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, CLIF_STATUS, &dwRegister));
			PH_CHECK_SUCCESS(statusTmp);
			if((dwRegister & CLIF_STATUS_TX_RF_STATUS_MASK ) == CLIF_STATUS_TX_RF_STATUS_MASK)
			{
				*pValue = PH_ON;
			}
			else
			{
				*pValue = PH_OFF;
			}
			break;

		default:
			return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
	}

	return statusTmp;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetListenParameters(
                        P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSensRes,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNfcId1,
                        VAR(uint8, ANFCRL_VAR) bSelRes,
                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPollingResp,
                        VAR(uint8, ANFCRL_VAR) bNfcId3
											  )
{
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF aCmd[PHHAL_HW_NCX3321_SET_LISTEN_LEN];
	UNUSED(bNfcId3);
	VAR(phStatus_t, ANFCRL_VAR) status = PH_ERR_SUCCESS;

	switch(g_bSetListenParamsState)
	{
		case PHHAL_HW_STATE_IDLE:
			(void)memcpy(&aCmd[0], pSensRes, PHHAL_HW_NCX3321_SET_LISTEN_SENRES_LEN);
			(void)memcpy(&aCmd[2], pNfcId1, PHHAL_HW_NCX3321_SET_LISTEN_NFCID1_LEN);
			(void)memcpy(&aCmd[5], &bSelRes, PHHAL_HW_NCX3321_SET_LISTEN_SELRES_LEN);
			(void)memcpy(&aCmd[6], pPollingResp, PHHAL_HW_NCX3321_SET_LISTEN_POLLRES_LEN);
			g_bSetListenParamsState = PHHAL_HW_STATE_CMD1;
			/* no break */
		case PHHAL_HW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteE2Prom(pDataParams, PHHAL_HW_NCX3321_SET_LISTEN_EEPROM_ADDR, aCmd, PHHAL_HW_NCX3321_SET_LISTEN_LEN));
			break;
	}

	g_bSetListenParamsState = PHHAL_HW_STATE_IDLE;
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Exchange(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                  VAR(uint16, ANFCRL_VAR) wTxLength,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSyncByte = 0xf0U;
	static VAR(phStatus_t, ANFCRL_VAR) statusBackup = PH_ERR_SUCCESS;
	static VAR(uint16, ANFCRL_VAR) wBkpOpt = 0U;
	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer;
	static VAR(uint16, ANFCRL_VAR) wRxLength = 0U;
	static VAR(uint8, ANFCRL_VAR) bTxLastBits = 0U;
	static VAR(uint8, ANFCRL_VAR) bRespConfig = 0U;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwValue = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_BUF wRegTypeValueSets[12] = { 0U };
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wSizeOfRegTypeValueSets = 0U;

	switch (g_bExchangeState)
	{
		case PHHAL_HW_STATE_IDLE:
			if (pDataParams->wTargetMode != PH_OFF)
			{
				/* If wTargetMode is changed then Target is activated and Exchange should not be used to perform Tx Operation. */
				return (PH_ERR_USE_CONDITION | PH_COMP_HAL);
			}
			/* Check options */
			if (0U != (wOption & (uint16)~(uint16)(PH_EXCHANGE_BUFFERED_BIT | PH_EXCHANGE_LEAVE_BUFFER_BIT)))
			{
				return (PH_ERR_INVALID_PARAMETER | PH_COMP_HAL);
			}

			if (pDataParams->bJewelActivated == PH_OFF)
			{
				bTxLastBits = (uint8)pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXLASTBITS];
			}
			else
			{
				bTxLastBits = 0x07U;

				/* Set Timer1 (FDT Timer) start condition to Tx Frame Step detected instead of Tx Ended. */
				dwValue = ~((uint32)CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				dwValue = CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				PH_CHECK_SUCCESS(statusTmp);
				/* Reset for next register write */
				wSizeOfRegTypeValueSets = 0U;
			}
			bRespConfig = PH_RF_EXCH_CONF_ENABLE_RF_STATUS | PH_RF_EXCH_CONF_ENABLE_RX_STATUS | PH_RF_EXCH_CONF_ENABLE_EVT_STATUS;
			g_bExchangeState = PHHAL_HW_STATE_CMD1;
			/* No break */
		case PHHAL_HW_STATE_CMD1:
			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				if((wOption == PH_EXCHANGE_BUFFER_FIRST) || (wOption == PH_EXCHANGE_DEFAULT))
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_ExchangeRFData(
						pDataParams,
						PH_EXCHANGE_BUFFER_FIRST,
						0,
						bRespConfig,
						&bSyncByte,
						1,
						NULL,
						NULL));
					status = statusTmp;
					PH_BREAK_ON_FAILURE(status);
					if(wOption == PH_EXCHANGE_BUFFER_FIRST)
					{
						wOption = PH_EXCHANGE_BUFFER_CONT;
					}
					else
					{
						wOption = PH_EXCHANGE_BUFFER_LAST;
					}
				}
			}
			wBkpOpt = wOption;
			g_bExchangeState = PHHAL_HW_STATE_CMD2;
			/*no break*/
		case PHHAL_HW_STATE_CMD2:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ExchangeRFData(pDataParams, wBkpOpt, bTxLastBits, bRespConfig,
					pTxBuffer,wTxLength,&pRxBuffer,&wRxLength));
			if (((status) & PH_ERR_MASK) == PH_ERR_ABORTED)
			{
				break;
			}
			/* Save status code value before returning */
			statusBackup = status;
			g_bExchangeState = PHHAL_HW_STATE_CMD3;
			/*no break*/

		case PHHAL_HW_STATE_CMD3:
			/* Get status value from previous state */
			status = statusBackup;
			if ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT)
			{
				/* Reset after timeout behavior */
				if (pDataParams->bRfResetAfterTo != PH_OFF)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_FieldReset(pDataParams));
					PH_BREAK_ON_FAILURE(statusTmp);
				}
			}

			/* When buffering is enabled, return*/
			if ( ( status == PH_ERR_SUCCESS ) &&
				( 0U != ( wBkpOpt & PH_EXCHANGE_BUFFERED_BIT ) ) )
			{
				status = PH_ERR_SUCCESS;
				break;
			}

			/* Reset TxLastBits */
			if (pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXLASTBITS] != 0U)
			{
				statusTmp = phhalHw_Ncx3321_SetConfig(pDataParams, PHHAL_HW_CONFIG_TXLASTBITS, 0x00U);
				if (statusTmp != PH_ERR_SUCCESS)
				{
					status = statusTmp;
					break;
				}
			}

			if (status == PH_ERR_SUCCESS)
			{
				g_bExchangeState = PHHAL_HW_STATE_CMD4;
			}
			else
			{
				/*Jump over Retrieve Data state*/
				g_bExchangeState = PHHAL_HW_STATE_CMD5;
				return PH_STATUS_INPROCESS;
			}
			/* Save status code value before returning */
			statusBackup = status;
			/*no break*/
		case PHHAL_HW_STATE_CMD4:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Int_Retrieve_Data(pDataParams,&pRxBuffer,&wRxLength));
			if (ppRxBuffer != NULL)
			{
				*ppRxBuffer = pRxBuffer;
			}
			if (pRxLength != NULL)
			{
				*pRxLength = wRxLength;
			}
			if (((status) & PH_ERR_MASK) == PH_ERR_ABORTED)
			{
				break;
			}
			/* Save status code value before returning */
			statusBackup = status;
			g_bExchangeState = PHHAL_HW_STATE_CMD5;
			/*no break*/
		case PHHAL_HW_STATE_CMD5:
			/* Get status value from previous state */
			status = statusBackup;
			if (pDataParams->bJewelActivated == PH_ON)
			{
				/* Reset Timer1 (FDT Timer) start condition to Tx Ended instead of Tx Frame Step detected. */
				dwValue = ~((uint32)CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_MASK);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_AND_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				dwValue = CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = CLIF_TIMER1_CONFIG;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = PHHAL_HW_NCX3321_WRITE_MULTIPLE_TYPE_WRITE_OR_MASK;
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 8U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 16U);
				wRegTypeValueSets[wSizeOfRegTypeValueSets++] = (uint8) (dwValue >> 24U);

				PH_CHECK_INPROCESS_FCT(statusTmp,
						phhalHw_Ncx3321_Instr_WriteRegisterMultiple(pDataParams, wRegTypeValueSets, wSizeOfRegTypeValueSets));
				if(statusTmp != PH_ERR_SUCCESS)
				{
					status = statusTmp;
					PH_BREAK_ON_FAILURE(status);
				}
			}
			if (((status & PH_ERR_MASK) == PH_ERR_NCX3321_RX_TIMEOUT_ERROR) ||
				((status & PH_ERR_MASK ) == PH_ERR_NCX3321_TX_FAILURE))
			{
				/* Map equivalent NCX3321 error codes to HAL Generic error code. */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
			}
			break;
		default:
			status = PH_ERR_INTERNAL_ERROR;
			break;
	}

	/* Reset variables */
	g_bExchangeState = PHHAL_HW_STATE_IDLE;
	statusBackup = PH_ERR_SUCCESS;
	wBkpOpt = 0U;
	wRxLength = 0U;
	bTxLastBits = 0U;
	bRespConfig = 0U;

	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Transmit(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                  VAR(uint16, ANFCRL_VAR) wTxLength
									)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bNumberOfValidBits = 0U;
  static VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wOptionBkp;
  static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bSyncByte = 0xf0;

	switch (g_bTransmitState)
	{
		case PHHAL_HW_STATE_IDLE:
			wOptionBkp = wOption;
			/* Check options */
			if ((wOption & (uint16) ~(uint16) (PH_TRANSMIT_BUFFERED_BIT | PH_TRANSMIT_LEAVE_BUFFER_BIT | PH_TRANSMIT_PREV_FRAME)) != 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* Re-send option should not be combined with buffer options. */
			if (((wOption & PH_TRANSMIT_PREV_FRAME) != 0U) && ((wOption & (uint16)~(uint16)(PH_TRANSMIT_PREV_FRAME)) != 0U))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* In Target Mode it's not allowed to have same buffers for transmission and reception
			*  since the data to transmit would get overwritten by received data. */
			if ((pDataParams->wTargetMode != PH_OFF) &&
				(pDataParams->pTxBuffer == pDataParams->pRxBuffer))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
			}

			if ((PH_TRANSMIT_PREV_FRAME & wOption) == 0U)
			{
				bNumberOfValidBits = (uint8)pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXLASTBITS];
			}
			else
			{
				if(wTxLength == 0x00U)
				{
					return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
				}
				pDataParams->wTxBufLen = wTxLength;


				if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
				{
					pDataParams->wTxBufLen += 1U;
				}
			}

			if ((pDataParams->bActiveMode != PH_ON) && (pDataParams->bNfcipMode == PH_ON))
			{
				if((wOption == PH_TRANSMIT_BUFFER_FIRST) || (wOption == PH_TRANSMIT_DEFAULT))
				{
					PH_CHECK_SUCCESS_FCT(status, phhalHw_Ncx3321_Instr_TransmitRFData(
						pDataParams,
						PH_TRANSMIT_BUFFER_FIRST,
						bNumberOfValidBits,
						&bSyncByte,
						1));

					if(wOption == PH_TRANSMIT_BUFFER_FIRST)
					{
						wOptionBkp = PH_TRANSMIT_BUFFER_CONT;
					}
					else
					{
						wOptionBkp = PH_TRANSMIT_BUFFER_LAST;
					}
				}
			}
			g_bTransmitState = PHHAL_HW_STATE_CMD1;
			/* no break*/
		case PHHAL_HW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_TransmitRFData(pDataParams, wOptionBkp,
					bNumberOfValidBits, pTxBuffer, wTxLength));
			g_bTransmitState = PHHAL_HW_STATE_IDLE;
			PH_CHECK_ABORT(status);
			/* Reset TxLastBits */
			if (pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXLASTBITS] != 0U)
			{
				PH_CHECK_SUCCESS_FCT(statusTmp, phhalHw_Ncx3321_SetConfig(pDataParams, PHHAL_HW_CONFIG_TXLASTBITS, 0x00));
			}
			if ((status & PH_ERR_MASK ) == PH_ERR_NCX3321_TX_FAILURE)
			{
				/* Map equivalent NCX3321 error codes to HAL Generic error code. */
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INTERNAL_ERROR, PH_COMP_HAL);
			}
			break;
	}
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Receive(P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wOption, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_UNSUPPORTED_COMMAND;
  VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRespControl = 0;

	switch (g_bReceiveState) {
		case PHHAL_HW_STATE_IDLE:
			/* Validate input parameters. */
			if ((wOption != 0U) || (ppRxBuffer == NULL) || (pRxLength == NULL))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}
			bRespControl = PH_RECEIVE_RF_ENABLE_EVT_STATUS |
			PH_RECEIVE_RF_ENABLE_RF_STATUS | PH_RECEIVE_RF_ENABLE_RX_STATUS;

			/* Wait for the Data to be received */
			PH_CHECK_INPROCESS_FCT(status,
					phhalHw_Ncx3321_Instr_ReceiveRFData(pDataParams, bRespControl,
							ppRxBuffer, pRxLength));
			if (status != PH_ERR_SUCCESS) {
				if ((status & PH_ERR_MASK) == PH_ERR_NCX3321_RX_TIMEOUT_ERROR)
				{
					/* Map equivalent NCX3321 error codes to HAL Generic error code. */
					status = PH_ADD_COMPCODE_FIXED(PH_ERR_IO_TIMEOUT, PH_COMP_HAL);
				}
				else
				{
					/* Do nothing */
				}
				break;
			}
			g_bReceiveState = PHHAL_HW_STATE_CMD1;
			/*no break*/
		case PHHAL_HW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(status,
					phhalHw_Ncx3321_Int_Retrieve_Data(pDataParams, ppRxBuffer,
							pRxLength));
			g_bReceiveState = PHHAL_HW_STATE_IDLE;
			break;
	}

	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Autocoll(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint16, ANFCRL_VAR) wMode,
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams
									)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwRegister = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM offsetPos = 0U;
	VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM offsetLen = 0U;

	static P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pEvtPayload = NULL;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventReceived = 0x0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bRfTechnology = 0U;

	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTypeA_CRC = 0U;
	static VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM bTypeF_CRC = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcIn = 0U;
	VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM wCrcCalc = 0U;

	static VAR(uint16, ANFCRL_VAR) wProtParams = 0U;

	switch (g_bAutocollState)
	{
		case PHHAL_HW_STATE_IDLE:
			bTypeA_CRC = 0U;
			bTypeF_CRC = 0U;
			wProtParams = 0U;
			/* Disable the EMD. */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_SetConfig(pDataParams, PHHAL_HW_CONFIG_SET_EMD,
					PH_OFF));
			PH_BREAK_ON_FAILURE(status);

			if (pDataParams->bCardMode == PH_ON)
			{
				bRfTechnology = PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A;
			}
			else
			{
				/*RFTech A*/
				if ((wMode & A_MODE) == A_MODE)
				{
					bRfTechnology |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A;
				}
				/*RFTech F*/
				if ((wMode & F_MODE) == F_MODE)
				{
					bRfTechnology |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F;
				}
				/*RFTech Active A*/
				if ((wMode & ACTIVE_A_MODE) == ACTIVE_A_MODE)
				{
					bRfTechnology |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_A_ACTIVE;
				}
				/*RFTech Active F*/
				if ((wMode & ACTIVE_F_MODE) == ACTIVE_F_MODE)
				{
					bRfTechnology |= PHHAL_HW_NCX3321_AUTOCOLL_RF_TECHNOLOGY_MASK_NFC_F_ACTIVE;
				}
				/*RFTech B and Active B*/
				if (((wMode & B_MODE) == B_MODE) || ((wMode & ACTIVE_B_MODE) == ACTIVE_B_MODE))
				{
					/* Do nothing, ignore -- NFCP576 -- as the NFC forum DTA application expects success for Listen B */
					bRfTechnology = 0U;
					return PH_ERR_SUCCESS;
				}
			}
			/* set the receive length */
			*pRxLength = 0U;

			pDataParams->wRxBufLen = 0U;

			/* Reset the Flag used to indicate if Passive Target is activated by ISO/IEC 18092 Frame */
			pDataParams->wTargetMode = PH_OFF;
			pDataParams->bActiveMode = PH_OFF;
			pDataParams->bNfcipMode = PH_OFF;
			g_bAutocollState = PHHAL_HW_STATE_CMD1;
			return PH_STATUS_INPROCESS;

		case PHHAL_HW_STATE_CMD1:
			PH_CHECK_INPROCESS_FCT(status,
						phhalHw_Ncx3321_Instr_SwitchModeAutocoll(pDataParams,bRfTechnology,
					PHHAL_HW_NCX3321_AUTOCOLL_MODE_TERMINATE_ON_RF_OFF));
			if (status == PH_ERR_SUCCESS)
			{
				g_bAutocollState = PHHAL_HW_STATE_CMD2;
				return PH_STATUS_INPROCESS;
			}
			break;

		case PHHAL_HW_STATE_CMD2:
			/*Wait for event*/
			PH_CHECK_INPROCESS_FCT(status,
					phhalHw_Ncx3321_WaitForEvent( pDataParams, PH_NCX3321_EVT_AUTOCOLL | PH_NCX3321_EVT_GENERAL_ERROR, PHHAL_HW_MAX_DELAY,
							TRUE, &dwEventReceived, &pEvtPayload));
			if (status == PH_ERR_SUCCESS)
			{
				if (dwEventReceived == PH_NCX3321_EVT_AUTOCOLL)
				{
					if (pEvtPayload[PHHAL_HW_NCX3321_AUTOCOLL_STATUS_INDEX] == PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATED)
					{
						g_bAutocollState = PHHAL_HW_STATE_CMD3;
						return PH_STATUS_INPROCESS;
					}
					else if (pEvtPayload[PHHAL_HW_NCX3321_AUTOCOLL_STATUS_INDEX] == PHHAL_HW_NCX3321_AUTOCOLL_EXTRF_OFF)
					{
						status = PH_ERR_EXT_RF_ERROR;
					}
					else
					{
						/* Unexpected status return from FE */
						status = PH_ERR_INTERNAL_ERROR;
					}
				}
				if ((dwEventReceived & PH_NCX3321_EVT_GENERAL_ERROR) != 0U)
				{
					pDataParams->dwGenError = (uint32) pEvtPayload[4];
					pDataParams->dwGenError |= ((uint32) pEvtPayload[5]) << 8U;
					pDataParams->dwGenError |= ((uint32) pEvtPayload[6]) << 16U;
					pDataParams->dwGenError |= ((uint32) pEvtPayload[7]) << 24U;

					status = PH_ERR_INTERNAL_ERROR;
				}
			}
			break;

		case PHHAL_HW_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, CLIF_RX_STATUS_ERROR, &dwRegister));
			PH_BREAK_ON_FAILURE(status)
			if ((dwRegister & CLIF_RX_STATUS_ERROR_RX_CL_ERROR_MASK) == 0U)
			{
				switch (pEvtPayload[PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACT_INDEX])
				{
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_A_106:
						wProtParams = PHHAL_HW_RF_TYPE_A_FRAMING | PHHAL_HW_RF_DATARATE_106;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_212:
						wProtParams = PHHAL_HW_RF_TYPE_F_FRAMING | PHHAL_HW_RF_DATARATE_212;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_PASSIVE_F_424:
						wProtParams = PHHAL_HW_RF_TYPE_F_FRAMING | PHHAL_HW_RF_DATARATE_424;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_106:
						wProtParams = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING | PHHAL_HW_RF_DATARATE_106;
						bTypeA_CRC = 1u;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_212:
						wProtParams = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING | PHHAL_HW_RF_DATARATE_212;
						bTypeF_CRC = 1u;
						break;
					case PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACTIVE_424:
						wProtParams = PHHAL_HW_RF_TYPE_ACTIVE_FRAMING | PHHAL_HW_RF_DATARATE_424;
						bTypeF_CRC = 1u;
						break;
					default:
						g_bAutocollState = PHHAL_HW_STATE_IDLE;
						bRfTechnology = 0U;
						/* Invalid Framing as NCX3321 will not emulate other than Type-A, Type-F and Active Frame */
						return PH_ADD_COMPCODE_FIXED(PH_ERR_FRAMING_ERROR, PH_COMP_HAL);
				}

				if ((pEvtPayload[PHHAL_HW_NCX3321_AUTOCOLL_TECH_ACT_INDEX] & PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_MODE_MASK)
						== PHHAL_HW_NCX3321_AUTOCOLL_ACTIVATION_PASSIVE_MODE)
				/* Disable active mode */
				{
					if (pEvtPayload[PHHAL_HW_NCX3321_AUTOCOLL_TECH_STATUS_INDEX] == 0U)
					{
						status = PH_ERR_PROTOCOL_ERROR;
						break;
					}
				}
				g_bAutocollState = PHHAL_HW_STATE_CMD4;
				return PH_STATUS_INPROCESS;
			}
			else
			{
				status = PH_ERR_INTEGRITY_ERROR;
				break;
			}
		case PHHAL_HW_STATE_CMD4:
			/* Read the RF Rx Buffer contents. */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_RetrieveRFData(pDataParams, ppRxBuffer, pRxLength));
			if (pProtParams != NULL)
			{
				*pProtParams = wProtParams;
			}
			/* Disable active mode */

			if ((wProtParams & PHHAL_HW_RF_FRAMING_OPTION_MASK) == PHHAL_HW_RF_TYPE_ACTIVE_FRAMING)
			{
				pDataParams->bActiveMode = PH_ON;
			}

			/* At-least a byte data + 2 bytes of crc.  */
			if (*pRxLength >= 3U)
			{
				if ((bTypeA_CRC == 0x1U) || (bTypeF_CRC == 0x1U))
				{
					if (bTypeA_CRC == 0x1U)
					{
						/* Retrieve CRC */
						wCrcIn = (uint16)(((uint16)(*ppRxBuffer)[(*pRxLength) - 1U]) << 8U);
						wCrcIn |= (uint16)((*ppRxBuffer)[(*pRxLength) - 2U]);

						/* Remove CRC from input data */
						*pRxLength -= 2U;

						/* Calculate CRC */
						PH_CHECK_FAILURE_FCT(status, phTools_CalculateCrc16(
								PH_TOOLS_CRC_OPTION_DEFAULT,
								PH_TOOLS_CRC16_PRESET_ISO14443A,
								PH_TOOLS_CRC16_POLY_ISO14443,
								*ppRxBuffer,
								*pRxLength,
								&wCrcCalc));
					}
					else
					{
						/* Retrieve CRC */
						wCrcIn = (uint16)((*ppRxBuffer)[(*pRxLength) - 1U]);
						wCrcIn |= (uint16)(((uint16)(*ppRxBuffer)[(*pRxLength) - 2U]) << 8U);

						/* Remove CRC from input data */
						*pRxLength -= 2U;

						/* Calculate CRC */
						PH_CHECK_FAILURE_FCT(status, phTools_CalculateCrc16(
								PH_TOOLS_CRC_OPTION_MSB_FIRST,
								PH_TOOLS_CRC16_PRESET_FELICA,
								PH_TOOLS_CRC16_POLY_FELICA,
								*ppRxBuffer,
								*pRxLength,
								&wCrcCalc));
					}
					/* CRC Check -> Compare input and calculated crc */
					if (wCrcIn == wCrcCalc)
					{
						status = PH_ERR_SUCCESS;
					}
					else
					{
						status = PH_ADD_COMPCODE_FIXED(PH_ERR_INTEGRITY_ERROR, PH_COMP_HAL);
						break;
					}

				}
				else
				{
					/* Remove CRC from input data */
					*pRxLength -= 2U;
				}

				/* Store received data length in dataparams */
				pDataParams->wRxBufLen = *pRxLength;

				/* Return RxBuffer pointer */
				/* Offset "F0" in case of Active communication */
				*ppRxBuffer = &(pDataParams->pRxBuffer[offsetPos]);

				/* Return RxBuffer length */
				/* Offset "F0" + CRC in case of Active communication */
				*pRxLength = pDataParams->wRxBufLen - offsetLen;

				pDataParams->wTargetMode = wProtParams;

				pDataParams->wCfgShadow[PHHAL_HW_CONFIG_RXDATARATE_FRAMING] = wProtParams;
				pDataParams->wCfgShadow[PHHAL_HW_CONFIG_TXDATARATE_FRAMING] = wProtParams;

			}
			else
			{
				status = PH_ERR_INTEGRITY_ERROR;
				break;
			}
			break;
	}
	g_bAutocollState = PHHAL_HW_STATE_IDLE;
	bRfTechnology = 0U;
	pEvtPayload = NULL;
	bTypeA_CRC = 0U;
	bTypeF_CRC = 0U;
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Wait(
                P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint8, ANFCRL_VAR) bUnit,
                VAR(uint16, ANFCRL_VAR) wTimeout
								)
{
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM wStatus = PH_ERR_SUCCESS;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
	P2VAR(phWaitParam_t, AUTOMATIC, ANFCRL_APPL_DATA) pWaitParam = &g_sWaitParam;

	switch (g_bWaitState)
	{
		case PHHAL_HW_STATE_IDLE:
			/* Parameter check */
			if ((bUnit != PHHAL_HW_TIME_MICROSECONDS) && (bUnit != PHHAL_HW_TIME_MILLISECONDS))
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
			}

			/* If time-out value is zero, there is no wait needed */
			if (wTimeout == 0U)
			{
				return PH_ERR_SUCCESS;
			}
			pWaitParam->wBkpTimeout = wTimeout;
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(
				pDataParams,
				EVENT_ENABLE,
				EVENT_ENABLE_TIMER0_EVENT_ENABLE_MASK));
			wStatus = statusTmp;
			PH_BREAK_ON_FAILURE(wStatus);
			g_bWaitState = PHHAL_HW_STATE_CMD1;
			return PH_STATUS_INPROCESS;
			/*no break*/

		case PHHAL_HW_STATE_CMD1:
			/* Setting the Prescaler frequency according to wTimeout */
			if (bUnit == PHHAL_HW_TIME_MILLISECONDS)
			{
				pWaitParam->wPrescaler = 0x3CU;
				if(pWaitParam->wBkpTimeout > PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS)
				{
					/* Calculating the load value */
					pWaitParam->dwLoadValue = (uint32)PHHAL_HW_NCX3321_MAX_LOADVALUE_MS;
				}
				else
				{
					pWaitParam->dwLoadValue = (uint32)pWaitParam->wBkpTimeout * ( PHHAL_HW_NCX3321_MIN_FREQ  / PHHAL_HW_NCX3321_CONVERSION_MS_SEC);
				}
			}
			else
			{
				/* here wTimeout will be in uS and not be Zero */
				pWaitParam->wPrescaler = 0x00U;
				/*Reducing the division by 2 digits to retain the 2 digit decimal places which were getting wiped out*/
				pWaitParam->dwLoadValue =(uint32) PHHAL_HW_NCX3321_MAX_LOADVALUE_US;
				/*Restoring the division done in the earlier step*/
				pWaitParam->dwLoadValue =(uint32) ((pWaitParam->wBkpTimeout * (pWaitParam->dwLoadValue))/100U);
			}
			g_bWaitState = PHHAL_HW_STATE_CMD2;
			/*no break*/

		case PHHAL_HW_STATE_CMD2:
			PH_CHECK_INPROCESS_FCT(wStatus, phhalHw_Ncx3321_Int_TimerStart(
				pDataParams,
				CLIF_TIMER0_CONFIG,
				CLIF_TIMER0_CONFIG_T0_START_NOW_MASK,
				CLIF_TIMER0_CONFIG_T0_ONE_SHOT_MODE_MASK,
				pWaitParam->wPrescaler,
				pWaitParam->dwLoadValue));
			if(wStatus == PH_ERR_ABORTED)
			{
				g_bWaitState = PHHAL_HW_STATE_IDLE;
				return wStatus;
			}
			if (bUnit == PHHAL_HW_TIME_MILLISECONDS)
			{
				if(pWaitParam->wBkpTimeout > PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS)
				{
					pWaitParam->wBkpTimeout -= PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS;
					g_bWaitState = PHHAL_HW_STATE_CMD1;
					return PH_STATUS_INPROCESS;
				}
			}
			g_bWaitState = PHHAL_HW_STATE_CMD3;
			/* No break */
		case PHHAL_HW_STATE_CMD3:
			PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(
				pDataParams,
				EVENT_ENABLE,
				~(uint32) EVENT_ENABLE_TIMER0_EVENT_ENABLE_MASK));
			g_bWaitState = PHHAL_HW_STATE_IDLE;
			PH_CHECK_SUCCESS(statusTmp);
			break;
		default:
			wStatus = PH_ERR_INTERNAL_ERROR;
			break;
	}
	g_bWaitState = PHHAL_HW_STATE_IDLE;

	return PH_ADD_COMPCODE(wStatus, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Stop_Lpcd (
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    )
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
    if ((pDataParams->bLpcdConfig == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB) ||
        (pDataParams->bLpcdConfig == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD))
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_PARAMETER, PH_COMP_HAL);
    }
    else
    {
        /* Call SWITCH_MODE_BOOT_NORMAL Command to stop LPCD. */
        status = phhalHw_Ncx3321_Instr_SwitchModeBootNormal(pDataParams);
    }
    return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Lpcd(
                P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								)
{
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_USE_CONDITION;
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp = PH_ERR_SUCCESS;
    static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusBackUp = PH_ERR_SUCCESS;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventReceived = 0x00U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventToWait = 0x00U;
    VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwRxCtrlRegVal = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwDpcConfigReg = 0x00U;
    VAR(uint8, ANFCRL_VAR) PH_MEMLOC_REM dwDpcConfigEeprom = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwTxLdoVddpa = 0x00U;
    static VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwUlpcdVddpa = 0x00U;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUlpcdVddpa = g_aUlpcdVddpa;
    static VAR(uint32, ANFCRL_VAR) dwDelay = 0U;
    VAR(uint32, ANFCRL_VAR) dwElapsedTime = 0U;

	if((pDataParams->bLpcdMode == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT) ||
			(pDataParams->bLpcdMode == PHHAL_HW_NCX3321_LPCD_MODE_POWERDOWN))
	{
		switch (pDataParams->bLpcdState)
		{
			case PHHAL_HW_STATE_IDLE:
			    dwDpcConfigReg = 0x00U;
                dwUlpcdVddpa = 0x00U;
                dwTxLdoVddpa = 0x00U;
				if (pDataParams->bLpcdMode == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT)
				{
					if (pDataParams->bLpcdConfig == PHHAL_HW_NCX3321_LPCD_CTRL_SINGLEMODE_LPCD)
					{
						return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
					}

					/* Reset the reference value. */
					pDataParams->dwLpcdRefVal = 0U;
				}
				if (pDataParams->bLpcdConfig == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD_CALIB)
				{
					pDataParams->bLpcdState = PHHAL_HW_STATE_APPLY_SETTINGS;
				}
				else if (pDataParams->bLpcdConfig == PHHAL_HW_NCX3321_LPCD_CTRL_ULPCD)
				{
					pDataParams->bLpcdState = PHHAL_HW_STATE_APPLY_HF_ATT;
				}
				else
				{
					pDataParams->bLpcdState = PHHAL_HW_STATE_CMD1;
				}
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_APPLY_SETTINGS:
				PH_CHECK_INPROCESS_FCT(status, phhalHw_ApplyProtocolSettings(pDataParams, PHHAL_HW_CARDTYPE_ISO14443A));
				PH_BREAK_ON_FAILURE(status);

				pDataParams->bLpcdState = PHHAL_HW_STATE_CHECK_DPC;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_CHECK_DPC:
				/* Disable DPC in case it is enabled (FW 2.5 required to access this register) */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, REG_DPC_CONFIG, &dwDpcConfigReg));
				if((status & PH_ERR_MASK) != PH_ERR_SUCCESS)
				{
					/* If DPC register not available (old FW), check EEPRROM setting */
					if ((status & PH_ERR_MASK) == PH_ERR_NCX3321_INSTR_ERROR)
					{
						pDataParams->bLpcdState = PHHAL_HW_STATE_CHECK_EEPRROM;
						return PH_STATUS_INPROCESS;
					}
					else
					{
						PH_BREAK_ON_FAILURE(status);
					}
				}

				pDataParams->bLpcdState = PHHAL_HW_STATE_DISABLE_DPC;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_DISABLE_DPC:
				/* Bit 31 DPC_REG_ACCESS must to be set to enable DPC modification via register
				 * and DPC needs to be disabled before field on. */
				if(((dwDpcConfigReg & REG_DPC_ENABLE_MASK) == PH_ON) || ((dwDpcConfigReg & REG_DPC_CONFIG_ACCESS_MASK) == PH_OFF))
				{
					PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegister(
							pDataParams,
							REG_DPC_CONFIG,
							((dwDpcConfigReg | REG_DPC_CONFIG_ACCESS_MASK) & (~REG_DPC_ENABLE_MASK))));
					PH_BREAK_ON_FAILURE(status);
				}
				pDataParams->bLpcdState = PHHAL_HW_STATE_FIELD_ON;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_CHECK_EEPRROM:
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadE2Prom(pDataParams, DPC_CONFIG_EEPROM, &dwDpcConfigEeprom, 0x01U));
                if(PH_ERR_SUCCESS != (status & PH_ERR_MASK))
                {
                    break;
                }
                else
                {
                    /* DPC must not be enabled in EEPROM */
                    if((dwDpcConfigEeprom & PH_ON) == PH_ON)
                    {
                        status = PH_ERR_INTERNAL_ERROR;
                        break;
                    }
                    else
                    {
                        dwDpcConfigReg = PH_OFF;
                    }
                }
                pDataParams->bLpcdState = PHHAL_HW_STATE_FIELD_ON;
                return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_FIELD_ON:
                PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOn(pDataParams));
                PH_BREAK_ON_FAILURE(status);
                pDataParams->bLpcdState = PHHAL_HW_STATE_GET_TXLDO_VDDPA;
                return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_GET_TXLDO_VDDPA:
                /* Get current TXLDO_VDDPA setting */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, TXLDO_VDDPA_CONFIG, &dwTxLdoVddpa));
				PH_BREAK_ON_FAILURE(status);
                pDataParams->bLpcdState = PHHAL_HW_STATE_GET_ULPCD_VDDPA;
                return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_GET_ULPCD_VDDPA:
                /* Get ULPCD VDDPA setting (must be done after FieldOn) */
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadE2Prom(pDataParams,
                        ULPCD_VDDPA_CTRL_EEPROM, pUlpcdVddpa, 0x02U));
                if(PH_ERR_SUCCESS != (status & PH_ERR_MASK))
                {
                    break;
                }
                else
                {
                    dwUlpcdVddpa = (((uint32)(pUlpcdVddpa[1]) & 0x01U) << 5U) + ((uint32)(pUlpcdVddpa[0]) >> 3U);
                    /* In case values are different apply ULPCD_VDDPA for ULPCD */
                    if(dwTxLdoVddpa != dwUlpcdVddpa)
                    {
                    	pDataParams->bLpcdState = PHHAL_HW_STATE_APPLY_ULPCD_VDDPA;
                    }
                    else
                    {
                        pDataParams->bLpcdState = PHHAL_HW_STATE_READ_HF_ATT;
                    }
                }
                return PH_STATUS_INPROCESS;

            case PHHAL_HW_STATE_APPLY_ULPCD_VDDPA:
                PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, TXLDO_VDDPA_CONFIG, dwUlpcdVddpa));
                PH_BREAK_ON_FAILURE(status);
                dwDelay = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
                pDataParams->bLpcdState = PHHAL_HW_STATE_HF_ATT_DELAY;
                return PH_STATUS_INPROCESS;

            case PHHAL_HW_STATE_HF_ATT_DELAY:
                dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, dwDelay);
                /* Check for timer overflow, abort if timer overflow happens */
                if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
                {
                    return PH_ERR_ABORTED;
                }
                else
                {
                    if (dwElapsedTime < PHHAL_HW_READ_HF_ATT_WAIT_TIME)
                    {
                        return PH_STATUS_INPROCESS;
                    }
                    else
                    {
                        pDataParams->bLpcdState = PHHAL_HW_STATE_READ_HF_ATT;
                    }
                }
                return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_READ_HF_ATT:
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_ReadRegister(pDataParams, CLIF_RXCTRL_STATUS, &dwRxCtrlRegVal));
				PH_BREAK_ON_FAILURE(status);
				pDataParams->bHFATTVal = (uint8)((dwRxCtrlRegVal & CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_MASK) >> CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_POS);

				pDataParams->bLpcdState = PHHAL_HW_STATE_APPLY_HF_ATT;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_APPLY_HF_ATT:
				PH_CHECK_INPROCESS_FCT(status, phhalHw_FieldOff(pDataParams));
				PH_BREAK_ON_FAILURE(status);

				/* Use the HF ATT reference value provided by User. */
				pDataParams->dwLpcdRefVal |= (uint32)pDataParams->bHFATTVal << 16U;

				pDataParams->bLpcdState = PHHAL_HW_STATE_CMD1;
				/*no break*/

			case PHHAL_HW_STATE_CMD1:
				/* Call LPCD Command to exchange LPCD TLV. */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Instr_SwitchModeLpcd(pDataParams, pDataParams->bLpcdConfig, pDataParams->bLpcdWakeUpCtrl,
						pDataParams->dwLpcdRefVal,pDataParams->wLPCDWakeupCounterInMs));

				PH_BREAK_ON_FAILURE(status);
				pDataParams->bLpcdState = PHHAL_HW_STATE_CMD2;
				/*no break*/

			case PHHAL_HW_STATE_CMD2:
				if (pDataParams->bLpcdMode == PHHAL_HW_NCX3321_LPCD_MODE_DEFAULT )
				{
					dwEventToWait = PH_NCX3321_EVT_LP_CALIB | PH_NCX3321_EVT_GENERAL_ERROR;
				}
				else
				{
					dwEventToWait = PH_NCX3321_EVT_LPCD | PH_NCX3321_EVT_GENERAL_ERROR;
				}
				/* Once LPCD Command exchange is successful, wait for LPCD Event from NCx3321. */
				PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Int_EventWait(
					pDataParams,
					dwEventToWait,
					PHHAL_HW_MAX_DELAY,
					TRUE,
					&dwEventReceived));
				if(status == PH_ERR_SUCCESS)
				{
					if (dwEventReceived == PH_NCX3321_EVT_LPCD)
					{
						if ((pDataParams->dwEventStatus == PHHAL_HW_LPCD_EVT_STATUS_CARD_DETECTED)||
							(pDataParams->dwEventStatus == PHHAL_HW_LPCD_EVT_STATUS_EXTERNALRF_FIELD))
						{
							/* Received LPCD event with card detection event bit set. */
							status = PH_ERR_SUCCESS;
						}
						else
						{
							/* Received LPCD event and but other than card detection event bit set. */
							status = PH_ERR_LPCD_ABORTED;
						}
					}
					else if(dwEventReceived == PH_NCX3321_EVT_LP_CALIB)
					{
						/* Store the LPCD Calibration data, which should be used during card detection phase. */
						pDataParams->dwLpcdRefVal = pDataParams->dwEventStatus;
						status = PH_ERR_SUCCESS;
					}
					else
					{
						status = PH_ERR_INTERNAL_ERROR;
					}
				}
				statusBackUp = status;
				pDataParams->bLpcdState = PHHAL_HW_STATE_RESET_CONFIG1;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_RESET_CONFIG1:
				/* Reset to previous DPC configuration */
				if((dwDpcConfigReg & PH_ON) == PH_ON)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, REG_DPC_CONFIG, dwDpcConfigReg));
					PH_BREAK_ON_FAILURE(statusTmp);
				}
				else
				{
					/* Do nothing */
				}
				pDataParams->bLpcdState = PHHAL_HW_STATE_RESET_CONFIG2;
				return PH_STATUS_INPROCESS;

			case PHHAL_HW_STATE_RESET_CONFIG2:
				/* Reset previous TxLDO VDDPA setting */
				if(dwTxLdoVddpa != dwUlpcdVddpa)
				{
					PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegister(pDataParams, TXLDO_VDDPA_CONFIG, dwTxLdoVddpa));
					PH_BREAK_ON_FAILURE(statusTmp);
				}
				else
				{
					/* Do nothing */
				}
				/* Load status value from state PHHAL_HW_STATE_CMD2 */
				status = statusBackUp;
				break;
			default:
				status = PH_ERR_INTERNAL_ERROR;
				break;
		}
	}

	dwDpcConfigReg = 0x00U;
	dwTxLdoVddpa = 0x00U;
	dwUlpcdVddpa = 0x00U;
	dwDelay = 0U;
	statusBackUp = PH_ERR_SUCCESS;
	pDataParams->bLpcdState = PHHAL_HW_STATE_IDLE;
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

#ifdef NXPBUILD__PHPAL_MIFARE_SW
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticateKeyNo(
                                               P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                               VAR(uint8, ANFCRL_VAR) bBlockNo,
                                               VAR(uint8, ANFCRL_VAR) bKeyType,
                                               VAR(uint16, ANFCRL_VAR) wKeyNo,
                                               VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
                                               )
{
#if defined(NXPBUILD__PH_KEYSTORE)
    VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
    uint8    PH_MEMLOC_BUF aKey[PHHAL_HW_MFC_KEY_LENGTH * 2];
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) PH_MEMLOC_REM pKey;
    VAR(uint16, ANFCRL_VAR) PH_MEMLOC_REM bKeystoreKeyType = 0U;

    /* Bail out if we haven't got a key-store */
    if (pDataParams->pKeyStoreDataParams == NULL)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
    }

    /* Retrieve KeyA & KeyB from key-store */
    status = phKeyStore_GetKey(
        pDataParams->pKeyStoreDataParams,
        wKeyNo,
        wKeyVersion,
        (uint8)sizeof(aKey),
        aKey,
        &bKeystoreKeyType);

    /* Change component code for invalid parameter */
    if ((status & PH_ERR_MASK) == PH_ERR_INVALID_PARAMETER)
    {
        return PH_ADD_COMPCODE((status & PH_ERR_MASK), PH_COMP_HAL);
    }
    else
    {
        PH_CHECK_SUCCESS(status);
    }

    /* Check key type */
    if (bKeystoreKeyType != PH_KEYSTORE_KEY_TYPE_MIFARE)
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Evaluate which key to use */
    if (bKeyType == PHHAL_HW_MFC_KEYA)
    {
        /* Use KeyA */
        pKey = aKey;
    }
    else if (bKeyType == PHHAL_HW_MFC_KEYB)
    {
        /* Use KeyB */
        pKey = &aKey[PHHAL_HW_MFC_KEY_LENGTH];
    }
    else
    {
        return PH_ADD_COMPCODE_FIXED(PH_ERR_INVALID_PARAMETER, PH_COMP_HAL);
    }

    /* Call the authentication function using the key */
    return phhalHw_Ncx3321_MfcAuthenticate(
        pDataParams,
        bBlockNo,
        bKeyType,
        pKey,
        pUid);
#else /* NXPBUILD__PH_KEYSTORE */
    PH_UNUSED_VARIABLE(pDataParams);
    PH_UNUSED_VARIABLE(bBlockNo);
    PH_UNUSED_VARIABLE(bKeyType);
    PH_UNUSED_VARIABLE(wKeyNo);
    PH_UNUSED_VARIABLE(wKeyVersion);
    PH_UNUSED_VARIABLE(pUid);
    return PH_ADD_COMPCODE_FIXED(PH_ERR_UNSUPPORTED_COMMAND, PH_COMP_HAL);
#endif /* NXPBUILD__PH_KEYSTORE */
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticate(
                                          P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                          VAR(uint8, ANFCRL_VAR) bBlockNo,
                                          VAR(uint8, ANFCRL_VAR) bKeyType,
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
                                          )
{
    return phhalHw_Ncx3321_Instr_MifareAuthenticate(
        pDataParams,
        pKey,
        bKeyType,
        bBlockNo,
        pUid);
}
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EventWait(
                  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint32, ANFCRL_VAR) dwEventTimeout
									)
{
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwEventReceived = 0x0U;
	VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM statusTmp;
	static VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status = PH_ERR_SUCCESS;
	static VAR(uint32, ANFCRL_VAR) bThreadStartTimer = 0u;
	VAR(uint32, ANFCRL_VAR) PH_MEMLOC_REM dwElapsedTime = 0U;

	switch (g_bEventWaitState)
	{
		case PHHAL_HW_STATE_IDLE:
			if (pDataParams->dwExpectedEvent == 0U)
			{
				return PH_ADD_COMPCODE_FIXED(PH_ERR_USE_CONDITION, PH_COMP_HAL);
			}

			pDataParams->dwEventReceived = 0U;

			if (pDataParams->dwExpectedEvent == PH_NCX3321_EVT_RFON_DETECT)
			{
				status = PH_ERR_IO_TIMEOUT;
				bThreadStartTimer = phDriver_GetTimeCurrent(PH_DRIVER_TIMER_USECS);
				g_bEventWaitState = PHHAL_HW_STATE_CMD1;
			}
			else
			{
				g_bEventWaitState = PHHAL_HW_STATE_CMD2;
			}
			return PH_STATUS_INPROCESS;
		case PHHAL_HW_STATE_CMD1:
			if (pDataParams->bRFONEvent != 0x01U)
			{
				dwElapsedTime = phDriver_GetTimeElapsed(PH_DRIVER_TIMER_USECS, bThreadStartTimer);

				/* Check for timer overflow, abort if timer overflow happens */
				if (S32K_TIMER_MAX_32BIT == dwElapsedTime)
				{
					status = PH_ERR_ABORTED;
					break;
				}
				else
				{
					if (dwElapsedTime < dwEventTimeout)
					{
						return PH_STATUS_INPROCESS;
					}
					else
					{
						/* Do nothing */
					}
				}
			}

			if (pDataParams->bRFONEvent == 0x01U)
			{
				pDataParams->dwEventReceived = PH_NCX3321_EVT_RFON_DETECT;
				pDataParams->bRFONEvent = 0x0U;
				status = PH_ERR_SUCCESS;
			}
			g_bEventWaitState = PHHAL_HW_STATE_CMD3;
			return PH_STATUS_INPROCESS;
		case PHHAL_HW_STATE_CMD2:
			/* Wait for event, configured by HOST using Setconfig of PHHAL_HW_NCX3321_CONFIG_EXPECTED_EVENT. */
			PH_CHECK_INPROCESS_FCT(status, phhalHw_Ncx3321_Int_EventWait(
				pDataParams,
				pDataParams->dwExpectedEvent,
				dwEventTimeout,
				TRUE,
				&dwEventReceived));

			pDataParams->dwEventReceived = dwEventReceived;
			g_bEventWaitState = PHHAL_HW_STATE_CMD3;
			return PH_STATUS_INPROCESS;
		case PHHAL_HW_STATE_CMD3:
			/* Only on successful External RF ON event, FW shall clear EVENT ENABLE Register.
			 * But in case of Timeout, EVENT_ENABLE bit for RFON_DET_EVENT needs to be reset by HOST. */
			if ((pDataParams->dwExpectedEvent == PH_NCX3321_EVT_RFON_DETECT) && ((status & PH_ERR_MASK) == PH_ERR_IO_TIMEOUT))
			{
				PH_CHECK_INPROCESS_FCT(statusTmp, phhalHw_Ncx3321_Instr_WriteRegisterAndMask(pDataParams,
						EVENT_ENABLE, ~(uint32)EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK));
				if (statusTmp != PH_ERR_SUCCESS)
				{
					status = statusTmp;
					break;
				}
			}

			if (((status & PH_ERR_MASK) != PH_ERR_IO_TIMEOUT) && ((status & PH_ERR_MASK) != PH_ERR_ABORTED))
			{
				if ((pDataParams->dwExpectedEvent & pDataParams->dwEventReceived) == 0U)
				{
					status = PH_ERR_NCX3321_UNEXPECTED_EVT;
				}
			}

			pDataParams->dwExpectedEvent = 0;
	}

    g_bEventWaitState = PHHAL_HW_STATE_IDLE;
	return PH_ADD_COMPCODE(status, PH_COMP_HAL);
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EventConsume(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams) {
  VAR(phStatus_t, ANFCRL_VAR) PH_MEMLOC_REM status;
	status = phTools_EventClear(&pDataParams->HwEventObj, E_EVENT_OPT_NONE,
			(E_EVENT_RF | E_EVENT_ABORT),
			NULL);
	return status;
}

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Exchange_GetStatus(void){
	if(g_bExchangeState == PHHAL_HW_STATE_IDLE)
	{
		return PH_ERR_SUCCESS;
	}
	else
	{
		return PH_STATUS_INPROCESS;
	}
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef __cplusplus
}
#endif
