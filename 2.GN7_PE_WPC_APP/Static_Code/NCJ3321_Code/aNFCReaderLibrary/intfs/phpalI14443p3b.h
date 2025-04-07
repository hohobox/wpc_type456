/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020 - 2021
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
*   @file    phpalI14443p3b.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3b - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3b ISO/IEC 14443-3B
*   @ingroup phpalProtocol
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

#ifndef PHPALI14443P3B_H
#define PHPALI14443P3B_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status.h>
#include "phhalHw.h"
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3B_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3b.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3B_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3b.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3B_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3b.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
/** \defgroup phpalI14443p3b_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b
* @{
*/

#define PHPAL_I14443P3B_SW_ID   0x01U    /**< ID for Software ISO14443-3B layer     */

/**
 * end of group phpalI14443p3b_Sw Component : Software
 * @}
 */
#endif /* #ifdef NXPBUILD__PHPAL_I14443P3B_SW */


#ifdef NXPBUILD__PHPAL_I14443P3B
/** \defgroup phpalI14443p3b ISO/IEC 14443-3B
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-B contactless protocol.
*
* \b Note: The "Timing before the PCD SOF" <em>(see 7.1.7, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* @{
*/

/**
* \name 14443-3B constant definitions
*/
/*@{*/
#define PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM1    0x0000U     /**< Set or get the AttribB param1 byte. */
/*@}*/

/**
* \name Configuration
*/
/*@{*/

/**
 * Configure Operation Mode for this Layer. \n
 * Possible values are\n
 *      #RD_LIB_MODE_EMVCO, \n
 *      #RD_LIB_MODE_NFC, \n
 *      #RD_LIB_MODE_ISO,\n
 * Default value is #RD_LIB_MODE_NFC.
 * */
#define PHPAL_I14443P3B_CONFIG_OPE_MODE             0x0001U

/**
 * Configure which command to be used for Type B Polling. \n
 * Possible values are\n
 *      #PHPAL_I14443P3B_USE_WUPB, \n
 *      #PHPAL_I14443P3B_USE_REQB, \n
 * Default value is #PHPAL_I14443P3B_USE_REQB.
 * */
#define PHPAL_I14443P3B_CONFIG_POLL_CMD             0x0002U

/**
 * Configure retry count for ATTRIB command.\n
 * Possible values are\n
 *      #PHPAL_I14443P3B_ATTRIB_RETRY_MIN, \n
 *      #PHPAL_I14443P3B_ATTRIB_RETRY_MAX, \n
 *
 * Default value is #PHPAL_I14443P3B_ATTRIB_RETRY_MAX.\n
 *
 * For mode #RD_LIB_MODE_EMVCO retry count should be 1.
 * */
#define PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT   0x0003U

/*@}*/

/**
* \name Poll Command
*/
/*@{*/
#define PHPAL_I14443P3B_USE_REQB            0x00U         /**< Indicate REQB command to be used for Type B Polling*/
#define PHPAL_I14443P3B_USE_WUPB            0x01U         /**< Indicate WakeupB command to be used for Type B Polling*/
/*@}*/

/**
* \name DRI/DSI Values
*/
/*@{*/
#define PHPAL_I14443P3B_DATARATE_106    0x00U   /**< DRI/DSI value for 106 kBit/s */
#define PHPAL_I14443P3B_DATARATE_212    0x01U   /**< DRI/DSI value for 212 kBit/s */
#define PHPAL_I14443P3B_DATARATE_424    0x02U   /**< DRI/DSI value for 424 kBit/s */
#define PHPAL_I14443P3B_DATARATE_848    0x03U   /**< DRI/DSI value for 848 kBit/s */
#define PHPAL_I14443P3B_DATARATE_FORCE  0x80U   /**< Flag that forces the use of the given baud rates */
/*@}*/

/**
* \name Attrib Command Retry Values
*/
/*@{*/
#define PHPAL_I14443P3B_ATTRIB_RETRY_MAX    1U   /**< Maximum retry value of ATTRIB during transmission and timeout error.*/
#define PHPAL_I14443P3B_ATTRIB_RETRY_MIN    0U   /**< Minimum retry value of ATTRIB during transmission and timeout error.*/
/*@}*/

/**
* \name Maximum allowed FSDI/FSCI Value
*/
/*@{*/
#define PHPAL_I14443P3B_FRAMESIZE_MAX       8U   /**< Maximum allowed FSDI/FSCI Value.*/
/*@}*/

/**
 * end of group phpalI14443p3b ISO/IEC 14443-3B
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3B */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW
/** \addtogroup phpalI14443p3b_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b
* @{
*/
 
/**
 * \brief State for ActivateCard
 */
typedef enum {
    PHPAL_I14443P3B_ACTCARD_START = 0,
    PHPAL_I14443P3B_ACTCARD_REQB_WKUPB,
    PHPAL_I14443P3B_ACTCARD_SLOTMAKER,
    PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP,
    PHPAL_I14443P3B_ACTCARD_ATTRIBUTE
} I14443P3B_ACTCARD_StateType_t;

/**
 * \brief State for Attribute
 */
typedef enum {
    PHPAL_I14443P3B_ATTRIB_START = 0,
    PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST,
    PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST,
    PHPAL_I14443P3B_ATTRIB_GUARDTIME,
    PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT,
    PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS,
    PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US,
    PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS,
    PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US,
    PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS,
    PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US
} I14443P3B_ATTRIB_StateType_t;

/**
 * \brief State for RequestBEx
 */
typedef enum {
    PHPAL_I14443P3B_REQUESTBEX_IDLE = 0,
    PHPAL_I14443P3B_REQUESTBEX_CONFIG,
    PHPAL_I14443P3B_REQUESTBEX_EXCHANGE,
    PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING,
    PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING,
    PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS,
    PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US
} I14443P3B_REQBEX_StateType_t;

/**
 * \brief State for Exchange
 */
typedef enum {
	PHPAL_I14443P3B_EXCHANGE_SEND = 0,
	PHPAL_I14443P3B_EXCHANGE_WAITRSP,
} I14443P3B_EXCHANGE_StateType_t;

/**
 * \brief State for SetReaderBaudRateEx
 */
typedef enum {
    PHPAL_I14443P3B_SETBAUDRATEEX_START = 0U,
    PHPAL_I14443P3B_SETBAUDRATEEX_TX,
    PHPAL_I14443P3B_SETBAUDRATEEX_RX,
} I14443P3B_SETBAUDRATEEX_StateType_t;

/**
 * end of group phpalI14443p3b_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW
/** \addtogroup phpalI14443p3b_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b
* @{
*/

/**
* \brief Software PAL-ISO14443P3B parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                       /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;             /**< Pointer to the parameter structure of the underlying layer.*/
    VAR(uint8, ANFCRL_VAR) bExtAtqb;                   /**< Stores whether last request used extended ATQB. */
    VAR(uint8, ANFCRL_VAR) pPupi[4];                   /**< Array holding the activated PUPI. */
    VAR(uint8, ANFCRL_VAR) bPupiValid;                 /**< Whether the stored Pupi is valid (\c 1) or not (\c 0). */
    VAR(uint8, ANFCRL_VAR) bCidSupported;              /**< Cid Support indicator; Unequal '0' if supported. */
    VAR(uint8, ANFCRL_VAR) bNadSupported;              /**< Nad Support indicator; Unequal '0' if supported. */
    VAR(uint8, ANFCRL_VAR) bCid;                       /**< Card Identifier; Ignored if bCidSupported is equal '0'. */
    VAR(uint8, ANFCRL_VAR) bFwi;                       /**< Frame Waiting Integer. */
    VAR(uint8, ANFCRL_VAR) bFsci;                      /**< PICC Frame Size Integer; 0-8; */
    VAR(uint8, ANFCRL_VAR) bFsdi;                      /**< (Current) PCD Frame Size Integer; 0-8; */
    VAR(uint8, ANFCRL_VAR) bDri;                       /**< (Current) Divisor Receive (PCD to PICC) Integer; 0-3; */
    VAR(uint8, ANFCRL_VAR) bDsi;                       /**< (Current) Divisor Send (PICC to PCD) Integer; 0-3; */
    VAR(uint8, ANFCRL_VAR) bAttribParam1;              /**< Param1 parameter for attrib command. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pHigherLayerInf;          /**< Pointer to higher layer information buffer. */
    VAR(uint16, ANFCRL_VAR) wTxWait;                    /**< Tx Wait Time */
    VAR(uint16, ANFCRL_VAR) wHigherLayerInfLen;       /**< Length higher layer information. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pHigherLayerResp;         /**< Pointer to higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wHigherLayerRespSize;     /**< Size of higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wHigherLayerRespLen;      /**< Length of higher layer response. */
    VAR(uint8, ANFCRL_VAR) bOpeMode;                   /**< Operation mode. One of NFC, EMVCo, ISO. */
    VAR(uint8, ANFCRL_VAR) bPollCmd;                   /**< Used to differentiate which command to send REQA or WakeUpA command for polling */
    VAR(uint8, ANFCRL_VAR) bRetryCount;                /**< Retry count for ATTRIB command as per NFC Digital Protocol Version 1.1\n
                                             For mode #RD_LIB_MODE_EMVCO retry count should be 1. */
    VAR(I14443P3B_ACTCARD_StateType_t, ANFCRL_VAR) eActCardState;  /**< Handle state of ActivateCard function of I14443P3B. */
    VAR(I14443P3B_ATTRIB_StateType_t, ANFCRL_VAR) eAttribState;    /**< Handle state of Attribute function of I14443P3B. */
    VAR(I14443P3B_REQBEX_StateType_t, ANFCRL_VAR) eReqBExState;    /**< Handle state of RequestBEx function of I14443P3B. */
    VAR(I14443P3B_EXCHANGE_StateType_t, ANFCRL_VAR) eSlotMrkState;  /**< Handle state of SlotMarker function of I14443P3B. */
    VAR(I14443P3B_EXCHANGE_StateType_t, ANFCRL_VAR) eHaltBState;    /**< Handle state of HaltB function of I14443P3B. */
    VAR(I14443P3B_SETBAUDRATEEX_StateType_t, ANFCRL_VAR) eSetBaudRateExState;    /**< Handle state of SetReaderBaudRateEx function of I14443P3B. */
    VAR(uint8, ANFCRL_VAR) eCheckATQBExState;                       /**< Handle state of phpalI14443p3b_Sw_CheckATQBEx function of I14443P3B. */
} phpalI14443p3b_Sw_DataParams_t;

/**
 * end of group phpalI14443p3b_Sw Component : Software
 * @}
 */
#endif /* #ifdef NXPBUILD__PHPAL_I14443P3B_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phpalI14443p3b_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_Init(
                                  P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                   /**< [In] Specifies the size of the data parameter structure. */
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                         /**< [In] Pointer to the parameter structure of the underlying layer.*/
                                  );

/**
 * end of group phpalI14443p3b_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3B_SW */


#ifdef NXPBUILD__PHPAL_I14443P3B

/** \addtogroup phpalI14443p3b ISO/IEC 14443-3B
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-B contactless protocol.
*
* \b Note: The "Timing before the PCD SOF" <em>(see 7.1.7, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalI14443p3b/src/Sw/phpalI14443p3b_Sw.h"

#define phpalI14443p3b_SetConfig( pDataParams,  wConfig,  wValue) \
        phpalI14443p3b_Sw_SetConfig((phpalI14443p3b_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#define phpalI14443p3b_GetConfig( pDataParams,   wConfig,  pValue ) \
        phpalI14443p3b_Sw_GetConfig((phpalI14443p3b_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#define phpalI14443p3b_RequestB(  pDataParams, bNumSlots, bAfi, bExtAtqb,  pAtqb, pAtqbLen) \
        phpalI14443p3b_Sw_RequestB((phpalI14443p3b_Sw_DataParams_t *)pDataParams, bNumSlots, bAfi, bExtAtqb, pAtqb, pAtqbLen)

#define phpalI14443p3b_WakeUpB( pDataParams, bNumSlots, bAfi, bExtAtqb, pAtqb, pAtqbLen) \
        phpalI14443p3b_Sw_WakeUpB((phpalI14443p3b_Sw_DataParams_t *)pDataParams, bNumSlots, bAfi, bExtAtqb, pAtqb, pAtqbLen)

#define phpalI14443p3b_SlotMarker( pDataParams, bSlotNumber, pAtqb, pAtqbLen) \
        phpalI14443p3b_Sw_SlotMarker((phpalI14443p3b_Sw_DataParams_t *)pDataParams, bSlotNumber, pAtqb, pAtqbLen)

#define phpalI14443p3b_HaltB( pDataParams) \
        phpalI14443p3b_Sw_HaltB((phpalI14443p3b_Sw_DataParams_t *)pDataParams)

#define phpalI14443p3b_Attrib( pDataParams, pAtqb, bAtqbLen, bFsdi, bCid, bDri, bDsi, pMbli) \
        phpalI14443p3b_Sw_Attrib((phpalI14443p3b_Sw_DataParams_t *)pDataParams, pAtqb, bAtqbLen, bFsdi, bCid, bDri, bDsi, pMbli)

#define phpalI14443p3b_ActivateCard( pDataParams, pPupi, bPupiLength, bNumSlots, bAfi, \
                                     bExtAtqb, bFsdi, bCid, bDri, bDsi, pAtqb,  pAtqbLen, pMbli, pMoreCardsAvailable) \
        phpalI14443p3b_Sw_ActivateCard((phpalI14443p3b_Sw_DataParams_t *)pDataParams,pPupi, bPupiLength, bNumSlots,  bAfi, bExtAtqb, \
            bFsdi, bCid,  bDri,  bDsi, pAtqb, pAtqbLen,pMbli, pMoreCardsAvailable)

#define phpalI14443p3b_Exchange( pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength) \
        phpalI14443p3b_Sw_Exchange((phpalI14443p3b_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phpalI14443p3b_GetSerialNo( pDataParams, pPupi) \
        phpalI14443p3b_Sw_GetSerialNo((phpalI14443p3b_Sw_DataParams_t *)pDataParams, pPupi)

#define phpalI14443p3b_SetSerialNo( pDataParams, pPupi) \
        phpalI14443p3b_Sw_SetSerialNo((phpalI14443p3b_Sw_DataParams_t *)pDataParams, pPupi)

#define phpalI14443p3b_SetHigherLayerInf( pDataParams, pTxBuffer,  wTxLength, pRxBuffer, wRxBufSize) \
        phpalI14443p3b_Sw_SetHigherLayerInf((phpalI14443p3b_Sw_DataParams_t *)pDataParams, pTxBuffer, wTxLength, pRxBuffer, wRxBufSize)

#define phpalI14443p3b_GetHigherLayerResp( pDataParams, ppRxBuffer, pRxLength) \
        phpalI14443p3b_Sw_GetHigherLayerResp((phpalI14443p3b_Sw_DataParams_t *)pDataParams, ppRxBuffer, pRxLength)

#define phpalI14443p3b_GetProtocolParams( pDataParams, pCidEnabled, pCid, pNadSupported, pFwi, pFsdi, pFsci) \
        phpalI14443p3b_Sw_GetProtocolParams((phpalI14443p3b_Sw_DataParams_t *)pDataParams, pCidEnabled, pCid, pNadSupported, pFwi, pFsdi, pFsci)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/**
* \brief Set configuration value.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_SetConfig(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig,   /**< [In] Configuration Identifier. */
                                    VAR(uint16, ANFCRL_VAR) wValue     /**< [In] Configuration Value. */
                                    );

/**
* \brief Get configuration value.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_GetConfig(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig,   /**< [In] Configuration Identifier. */
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue    /**< [Out] Configuration Value. */
                                    );

/**
* \brief Perform a ISO14443-3B Request command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_RequestB(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                                   VAR(uint8, ANFCRL_VAR) bNumSlots,   /**< [In] Number of slots. */
                                   VAR(uint8, ANFCRL_VAR) bAfi,        /**< [In] AFI; Application Family Identifier. */
                                   VAR(uint8, ANFCRL_VAR) bExtAtqb,    /**< [In] Enable Extended AtqB. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,     /**< [Out] AtqB; uint8[13]. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen     /**< [Out] length of ATQB (12/13 bytes). */
                                   );

/**
* \brief Perform a ISO14443-3B Wakeup command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_WakeUpB(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                  VAR(uint8, ANFCRL_VAR) bNumSlots,    /**< [In] Number of slots. */
                                  VAR(uint8, ANFCRL_VAR) bAfi,         /**< [In] AFI; Application Family Identifier. */
                                  VAR(uint8, ANFCRL_VAR) bExtAtqb,     /**< [In] Enable Extended AtqB. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,      /**< [Out] AtqB; uint8[12/13]. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen    /**< [Out] length of ATQB (12/13 bytes). */
                                  );

/**
* \brief Perform a ISO14443-3B Slot-MARKER command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_SlotMarker(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bSlotNumber,   /**< [In] Slot Number. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,       /**< [Out] AtqB; uint8[12/13]. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen     /**< [Out] length of ATQB (12/13 bytes). */
                                     );

/**
* \brief Perform a ISO14443-3B Halt command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_HaltB(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams  /**< [In] Pointer to this layers parameter structure. */
                                );

/**
* \brief Perform a ISO14443-3B Attrib command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Attrib(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers parameter structure. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,       /**< [In] Atqb from ReqB/WupB; uint8[12/13]. */
                                 VAR(uint8, ANFCRL_VAR) bAtqbLen,      /**< [In] Length of Atqb. */
                                 VAR(uint8, ANFCRL_VAR) bFsdi,         /**< [In] Frame Size Integer; 0-8. */
                                 VAR(uint8, ANFCRL_VAR) bCid,          /**< [In] Card Identifier; 0-14. */
                                 VAR(uint8, ANFCRL_VAR) bDri,          /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                 VAR(uint8, ANFCRL_VAR) bDsi,          /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli        /**< [Out] MBLI byte; uint8. */
                                 );

/**
* \brief Perform ISO14443-3B ReqB or WupB and Anticollision/Select commands for all cascade levels.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* If bLenUidIn is '0' --> CardUid not given, a ReqB is performed.
* If CardUid is given, a WupB is performed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_ActivateCard(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,              /**< [In] Pointer to this layers parameter structure. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi,                 /**< [In] Pointer to the known PUPI; uint8[4]. */
                                       VAR(uint8, ANFCRL_VAR) bPupiLength,             /**< [In] Length of given PUPI, only a value of 0 or 4 is allowed. */
                                       VAR(uint8, ANFCRL_VAR) bNumSlots,               /**< [In] Number of slots. */
                                       VAR(uint8, ANFCRL_VAR) bAfi,                    /**< [In] AFI; Application Family Identifier. */
                                       VAR(uint8, ANFCRL_VAR) bExtAtqb,                /**< [In] Enable Extended AtqB. */
                                       VAR(uint8, ANFCRL_VAR) bFsdi,                   /**< [In] Frame Size Integer; 0-8. */
                                       VAR(uint8, ANFCRL_VAR) bCid,                    /**< [In] Card Identifier; 0-14. */
                                       VAR(uint8, ANFCRL_VAR) bDri,                    /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                       VAR(uint8, ANFCRL_VAR) bDsi,                    /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,                 /**< [Out] AtqB; uint8[13]. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen,              /**< [Out] length of ATQB (12/13 bytes). */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli,                 /**< [Out] MBLI byte; uint8. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable    /**< [Out] Whether there are more cards in the field or not; uint8. */
                                       );

/**
* \brief Perform ISO14443-3B Data Exchange with Picc.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b wOption can be one of:\n
* \li #PH_EXCHANGE_DEFAULT
* \li #PH_EXCHANGE_BUFFER_FIRST
* \li #PH_EXCHANGE_BUFFER_CONT
* \li #PH_EXCHANGE_BUFFER_LAST
*
* Alternatively, the following bits can be combined:\n
* \li #PH_EXCHANGE_BUFFERED_BIT
* \li #PH_EXCHANGE_LEAVE_BUFFER_BIT
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Exchange(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layers parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wOption,        /**< [In] Option parameter. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,     /**< [In] Data to transmit. */
                                   VAR(uint16, ANFCRL_VAR) wTxLength,      /**< [In] Length of data to transmit. */
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,   /**< [Out] Pointer to received data. */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength     /**< [Out] number of received data bytes. */
                                   );

/**
* \brief Retrieve the serial number.
* This function will provide 4 byte PUPI.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION No PUPI available.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_GetSerialNo(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi       /**< [Out] Most recent PUPI. */
                                      );

/**
* \brief This function will update PUPI in this layer's parameter structure.
* This function must be called with valid PUPI.
* Once set the subsequent type B commands use this PUPI.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_SetSerialNo(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi       /**< [In] 4 byte PUPI. */
                                      );

/**
* \brief Set higher layer information.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION Feature not available.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_SetHigherLayerInf(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,    /**< [In] Higher layer Information; Can be NULL if /c wTxLength is 0. */
    VAR(uint16, ANFCRL_VAR) wTxLength,    /**< [In] Length of the Higher layer Information. Can be 0. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,    /**< [In] Higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wRxBufSize     /**< [In] Size of Higher layer response buffer. */
    );

/**
* \brief Get higher layer response.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION Feature not available.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_GetHigherLayerResp(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,  /**< [Out] Higher layer response. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength    /**< [Out] Length of Higher layer response. */
    );

/**
* \brief Retrieve the ISO14443-3B protocol parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_GetProtocolParams(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled,      /**< [Out] Unequal '0' if Card Identifier is enabled. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid,             /**< [Out] Card Identifier. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported,    /**< [Out] Node Address Support; Unequal '0' if supported. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi,             /**< [Out] Frame Waiting Integer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi,            /**< [Out] PCD Frame Size Integer; 0-8. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci             /**< [Out] PICC Frame Size Integer; 0-8. */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalI14443p3b ISO/IEC 14443-3B
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P3B */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3B_H */
