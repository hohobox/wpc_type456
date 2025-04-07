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
*   @file    phpalI14443p3b2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3b - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3b2 ISO/IEC 14443-3B
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

#ifndef PHPALI14443P3B2_H
#define PHPALI14443P3B2_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status2.h>
#include "phhalHw2.h"
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_VENDOR_ID2                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_MODULE_ID2                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_AR_RELEASE_REVISION_VERSION2  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3B_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3b2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3B_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3b2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3B_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3b2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
/** \defgroup phpalI14443p3b_Sw2 Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b2
* @{
*/

#define PHPAL_I14443P3B_SW_ID2   0x01U    /**< ID for Software ISO14443-3B layer     */

/**
 * end of group phpalI14443p3b_Sw2 Component : Software
 * @}
 */
#endif /* #ifdef NXPBUILD__PHPAL_I14443P3B_SW2 */


#ifdef NXPBUILD__PHPAL_I14443P3B2
/** \defgroup phpalI14443p3b2 ISO/IEC 14443-3B
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-B contactless protocol.
*
* \b Note: The "Timing before the PCD SOF" <em>(see 7.1.7, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw2 layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* @{
*/

/**
* \name 14443-3B constant definitions
*/
/*@{*/
#define PHPAL_I14443P3B_CONFIG_ATTRIB_PARAM12    0x0000U     /**< Set or get the AttribB param1 byte. */
/*@}*/

/**
* \name Configuration
*/
/*@{*/

/**
 * Configure Operation Mode for this Layer. \n
 * Possible values are\n
 *      #RD_LIB_MODE_EMVCO2, \n
 *      #RD_LIB_MODE_NFC2, \n
 *      #RD_LIB_MODE_ISO2,\n
 * Default value is #RD_LIB_MODE_NFC2.
 * */
#define PHPAL_I14443P3B_CONFIG_OPE_MODE2             0x0001U

/**
 * Configure which command to be used for Type B Polling. \n
 * Possible values are\n
 *      #PHPAL_I14443P3B_USE_WUPB2, \n
 *      #PHPAL_I14443P3B_USE_REQB2, \n
 * Default value is #PHPAL_I14443P3B_USE_REQB2.
 * */
#define PHPAL_I14443P3B_CONFIG_POLL_CMD2             0x0002U

/**
 * Configure retry count for ATTRIB command.\n
 * Possible values are\n
 *      #PHPAL_I14443P3B_ATTRIB_RETRY_MIN2, \n
 *      #PHPAL_I14443P3B_ATTRIB_RETRY_MAX2, \n
 *
 * Default value is #PHPAL_I14443P3B_ATTRIB_RETRY_MAX2.\n
 *
 * For mode #RD_LIB_MODE_EMVCO2 retry count should be 1.
 * */
#define PHPAL_I14443P3B_CONFIG_ATTRIB_RETRY_COUNT2   0x0003U

/*@}*/

/**
* \name Poll Command
*/
/*@{*/
#define PHPAL_I14443P3B_USE_REQB2            0x00U         /**< Indicate REQB command to be used for Type B Polling*/
#define PHPAL_I14443P3B_USE_WUPB2            0x01U         /**< Indicate WakeupB command to be used for Type B Polling*/
/*@}*/

/**
* \name DRI/DSI Values
*/
/*@{*/
#define PHPAL_I14443P3B_DATARATE_1062    0x00U   /**< DRI/DSI value for 106 kBit/s */
#define PHPAL_I14443P3B_DATARATE_2122    0x01U   /**< DRI/DSI value for 212 kBit/s */
#define PHPAL_I14443P3B_DATARATE_4242    0x02U   /**< DRI/DSI value for 424 kBit/s */
#define PHPAL_I14443P3B_DATARATE_8482    0x03U   /**< DRI/DSI value for 848 kBit/s */
#define PHPAL_I14443P3B_DATARATE_FORCE2  0x80U   /**< Flag that forces the use of the given baud rates */
/*@}*/

/**
* \name Attrib Command Retry Values
*/
/*@{*/
#define PHPAL_I14443P3B_ATTRIB_RETRY_MAX2    1U   /**< Maximum retry value of ATTRIB during transmission and timeout error.*/
#define PHPAL_I14443P3B_ATTRIB_RETRY_MIN2    0U   /**< Minimum retry value of ATTRIB during transmission and timeout error.*/
/*@}*/

/**
* \name Maximum allowed FSDI/FSCI Value
*/
/*@{*/
#define PHPAL_I14443P3B_FRAMESIZE_MAX2       8U   /**< Maximum allowed FSDI/FSCI Value.*/
/*@}*/

/**
 * end of group phpalI14443p3b2 ISO/IEC 14443-3B
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3B2 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
/** \addtogroup phpalI14443p3b_Sw2 Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b2
* @{
*/
 
/**
 * \brief State for ActivateCard
 */
typedef enum {
    PHPAL_I14443P3B_ACTCARD_START2 = 0,
    PHPAL_I14443P3B_ACTCARD_REQB_WKUPB2,
    PHPAL_I14443P3B_ACTCARD_SLOTMAKER2,
    PHPAL_I14443P3B_ACTCARD_SLOTMAKER_LOOP2,
    PHPAL_I14443P3B_ACTCARD_ATTRIBUTE2
} I14443P3B_ACTCARD_StateType_t2;

/**
 * \brief State for Attribute
 */
typedef enum {
    PHPAL_I14443P3B_ATTRIB_START2 = 0,
    PHPAL_I14443P3B_ATTRIB_EX_BUFF_FIRST2,
    PHPAL_I14443P3B_ATTRIB_EX_BUFF_LAST2,
    PHPAL_I14443P3B_ATTRIB_GUARDTIME2,
    PHPAL_I14443P3B_ATTRIB_SET_TIMEOUT2,
    PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_MS2,
    PHPAL_I14443P3B_ATTRIB_SET_FWT_TIMEOUT_VALUE_US2,
    PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_MS2,
    PHPAL_I14443P3B_ATTRIB_SET_EXTENSION_TIMEOUT_VALUE_US2,
    PHPAL_I14443P3B_ATTRIB_CHECK_BAURATE_FLAG_SUCCESS2,
    PHPAL_I14443P3B_ATTRIB_CONFIG_TXWAIT_US2
} I14443P3B_ATTRIB_StateType_t2;

/**
 * \brief State for RequestBEx
 */
typedef enum {
    PHPAL_I14443P3B_REQUESTBEX_IDLE2 = 0,
    PHPAL_I14443P3B_REQUESTBEX_CONFIG2,
    PHPAL_I14443P3B_REQUESTBEX_EXCHANGE2,
    PHHAL_I14443P3B_CONFIG_TXDATARATE_FRAMING2,
    PHHAL_I14443P3B_CONFIG_RXDATARATE_FRAMING2,
    PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_MS2,
    PHPAL_I14443P3B_REQUESTBEX_SET_TIMEOUT_VALUE_US2
} I14443P3B_REQBEX_StateType_t2;

/**
 * \brief State for Exchange
 */
typedef enum {
	PHPAL_I14443P3B_EXCHANGE_SEND2 = 0,
	PHPAL_I14443P3B_EXCHANGE_WAITRSP2,
} I14443P3B_EXCHANGE_StateType_t2;

/**
 * \brief State for SetReaderBaudRateEx
 */
typedef enum {
    PHPAL_I14443P3B_SETBAUDRATEEX_START2 = 0U,
    PHPAL_I14443P3B_SETBAUDRATEEX_TX2,
    PHPAL_I14443P3B_SETBAUDRATEEX_RX2,
} I14443P3B_SETBAUDRATEEX_StateType_t2;

/**
 * end of group phpalI14443p3b_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
/** \addtogroup phpalI14443p3b_Sw2 Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b2
* @{
*/

/**
* \brief Software PAL-ISO14443P3B parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId2;                       /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2;             /**< Pointer to the parameter structure of the underlying layer.*/
    VAR(uint8, ANFCRL_VAR) bExtAtqb2;                   /**< Stores whether last request used extended ATQB. */
    VAR(uint8, ANFCRL_VAR) pPupi2[4];                   /**< Array holding the activated PUPI. */
    VAR(uint8, ANFCRL_VAR) bPupiValid2;                 /**< Whether the stored Pupi is valid (\c 1) or not (\c 0). */
    VAR(uint8, ANFCRL_VAR) bCidSupported2;              /**< Cid Support indicator; Unequal '0' if supported. */
    VAR(uint8, ANFCRL_VAR) bNadSupported2;              /**< Nad Support indicator; Unequal '0' if supported. */
    VAR(uint8, ANFCRL_VAR) bCid2;                       /**< Card Identifier; Ignored if bCidSupported2 is equal '0'. */
    VAR(uint8, ANFCRL_VAR) bFwi2;                       /**< Frame Waiting Integer. */
    VAR(uint8, ANFCRL_VAR) bFsci2;                      /**< PICC Frame Size Integer; 0-8; */
    VAR(uint8, ANFCRL_VAR) bFsdi2;                      /**< (Current) PCD Frame Size Integer; 0-8; */
    VAR(uint8, ANFCRL_VAR) bDri2;                       /**< (Current) Divisor Receive (PCD to PICC) Integer; 0-3; */
    VAR(uint8, ANFCRL_VAR) bDsi2;                       /**< (Current) Divisor Send (PICC to PCD) Integer; 0-3; */
    VAR(uint8, ANFCRL_VAR) bAttribParam12;              /**< Param1 parameter for attrib command. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pHigherLayerInf2;          /**< Pointer to higher layer information buffer. */
    VAR(uint16, ANFCRL_VAR) wTxWait2;                    /**< Tx Wait Time */
    VAR(uint16, ANFCRL_VAR) wHigherLayerInfLen2;       /**< Length higher layer information. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pHigherLayerResp2;         /**< Pointer to higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wHigherLayerRespSize2;     /**< Size of higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wHigherLayerRespLen2;      /**< Length of higher layer response. */
    VAR(uint8, ANFCRL_VAR) bOpeMode2;                   /**< Operation mode. One of NFC, EMVCo, ISO. */
    VAR(uint8, ANFCRL_VAR) bPollCmd2;                   /**< Used to differentiate which command to send REQA or WakeUpA command for polling */
    VAR(uint8, ANFCRL_VAR) bRetryCount2;                /**< Retry count for ATTRIB command as per NFC Digital Protocol Version 1.1\n
                                             For mode #RD_LIB_MODE_EMVCO2 retry count should be 1. */
    VAR(I14443P3B_ACTCARD_StateType_t2, ANFCRL_VAR) eActCardState2;  /**< Handle state of ActivateCard function of I14443P3B. */
    VAR(I14443P3B_ATTRIB_StateType_t2, ANFCRL_VAR) eAttribState2;    /**< Handle state of Attribute function of I14443P3B. */
    VAR(I14443P3B_REQBEX_StateType_t2, ANFCRL_VAR) eReqBExState2;    /**< Handle state of RequestBEx function of I14443P3B. */
    VAR(I14443P3B_EXCHANGE_StateType_t2, ANFCRL_VAR) eSlotMrkState2;  /**< Handle state of SlotMarker function of I14443P3B. */
    VAR(I14443P3B_EXCHANGE_StateType_t2, ANFCRL_VAR) eHaltBState2;    /**< Handle state of HaltB function of I14443P3B. */
    VAR(I14443P3B_SETBAUDRATEEX_StateType_t2, ANFCRL_VAR) eSetBaudRateExState2;    /**< Handle state of SetReaderBaudRateEx function of I14443P3B. */
    VAR(uint8, ANFCRL_VAR) eCheckATQBExState2;                       /**< Handle state of phpalI14443p3b_Sw_CheckATQBEx function of I14443P3B. */
} phpalI14443p3b_Sw_DataParams_t2;

/**
 * end of group phpalI14443p3b_Sw2 Component : Software
 * @}
 */
#endif /* #ifdef NXPBUILD__PHPAL_I14443P3B_SW2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3B_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phpalI14443p3b_Sw2 Component : Software
* \brief Software component of ISO/IEC 14443-3 Type B
* \ingroup phpalI14443p3b2
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Init2(
                                  P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,                   /**< [In] Specifies the size of the data parameter structure. */
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2                         /**< [In] Pointer to the parameter structure of the underlying layer.*/
                                  );

/**
 * end of group phpalI14443p3b_Sw2 Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */


#ifdef NXPBUILD__PHPAL_I14443P3B2

/** \addtogroup phpalI14443p3b2 ISO/IEC 14443-3B
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-B contactless protocol.
*
* \b Note: The "Timing before the PCD SOF" <em>(see 7.1.7, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw2 layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phpalI14443p3b2/src/Sw/phpalI14443p3b_Sw2.h"

#define phpalI14443p3b_SetConfig2( pDataParams2,  wConfig2,  wValue2) \
        phpalI14443p3b_Sw_SetConfig2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, wConfig2, wValue2)

#define phpalI14443p3b_GetConfig2( pDataParams2,   wConfig2,  pValue2 ) \
        phpalI14443p3b_Sw_GetConfig2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2)

#define phpalI14443p3b_RequestB2(  pDataParams2, bNumSlots2, bAfi2, bExtAtqb2,  pAtqb2, pAtqbLen2) \
        phpalI14443p3b_Sw_RequestB2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, bNumSlots2, bAfi2, bExtAtqb2, pAtqb2, pAtqbLen2)

#define phpalI14443p3b_WakeUpB2( pDataParams2, bNumSlots2, bAfi2, bExtAtqb2, pAtqb2, pAtqbLen2) \
        phpalI14443p3b_Sw_WakeUpB2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, bNumSlots2, bAfi2, bExtAtqb2, pAtqb2, pAtqbLen2)

#define phpalI14443p3b_SlotMarker2( pDataParams2, bSlotNumber2, pAtqb2, pAtqbLen2) \
        phpalI14443p3b_Sw_SlotMarker2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, bSlotNumber2, pAtqb2, pAtqbLen2)

#define phpalI14443p3b_HaltB2( pDataParams2) \
        phpalI14443p3b_Sw_HaltB2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2)

#define phpalI14443p3b_Attrib2( pDataParams2, pAtqb2, bAtqbLen2, bFsdi2, bCid2, bDri2, bDsi2, pMbli2) \
        phpalI14443p3b_Sw_Attrib2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, pAtqb2, bAtqbLen2, bFsdi2, bCid2, bDri2, bDsi2, pMbli2)

#define phpalI14443p3b_ActivateCard2( pDataParams2, pPupi2, bPupiLength2, bNumSlots2, bAfi2, \
                                     bExtAtqb2, bFsdi2, bCid2, bDri2, bDsi2, pAtqb2,  pAtqbLen2, pMbli2, pMoreCardsAvailable2) \
        phpalI14443p3b_Sw_ActivateCard2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2,pPupi2, bPupiLength2, bNumSlots2,  bAfi2, bExtAtqb2, \
            bFsdi2, bCid2,  bDri2,  bDsi2, pAtqb2, pAtqbLen2,pMbli2, pMoreCardsAvailable2)

#define phpalI14443p3b_Exchange2( pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2) \
        phpalI14443p3b_Sw_Exchange2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2)

#define phpalI14443p3b_GetSerialNo2( pDataParams2, pPupi2) \
        phpalI14443p3b_Sw_GetSerialNo2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, pPupi2)

#define phpalI14443p3b_SetSerialNo2( pDataParams2, pPupi2) \
        phpalI14443p3b_Sw_SetSerialNo2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, pPupi2)

#define phpalI14443p3b_SetHigherLayerInf2( pDataParams2, pTxBuffer2,  wTxLength2, pRxBuffer2, wRxBufSize2) \
        phpalI14443p3b_Sw_SetHigherLayerInf2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, pTxBuffer2, wTxLength2, pRxBuffer2, wRxBufSize2)

#define phpalI14443p3b_GetHigherLayerResp2( pDataParams2, ppRxBuffer2, pRxLength2) \
        phpalI14443p3b_Sw_GetHigherLayerResp2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, ppRxBuffer2, pRxLength2)

#define phpalI14443p3b_GetProtocolParams2( pDataParams2, pCidEnabled2, pCid2, pNadSupported2, pFwi2, pFsdi2, pFsci2) \
        phpalI14443p3b_Sw_GetProtocolParams2((phpalI14443p3b_Sw_DataParams_t2 *)pDataParams2, pCidEnabled2, pCid2, pNadSupported2, pFwi2, pFsdi2, pFsci2)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/**
* \brief Set configuration value.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_SetConfig2(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig2,   /**< [In] Configuration Identifier. */
                                    VAR(uint16, ANFCRL_VAR) wValue2     /**< [In] Configuration Value. */
                                    );

/**
* \brief Get configuration value.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_GetConfig2(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig2,   /**< [In] Configuration Identifier. */
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2    /**< [Out] Configuration Value. */
                                    );

/**
* \brief Perform a ISO14443-3B Request command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_RequestB2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
                                   VAR(uint8, ANFCRL_VAR) bNumSlots2,   /**< [In] Number of slots. */
                                   VAR(uint8, ANFCRL_VAR) bAfi2,        /**< [In] AFI; Application Family Identifier. */
                                   VAR(uint8, ANFCRL_VAR) bExtAtqb2,    /**< [In] Enable Extended AtqB. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,     /**< [Out] AtqB; uint8[13]. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2     /**< [Out] length of ATQB (12/13 bytes). */
                                   );

/**
* \brief Perform a ISO14443-3B Wakeup command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_WakeUpB2(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layers parameter structure. */
                                  VAR(uint8, ANFCRL_VAR) bNumSlots2,    /**< [In] Number of slots. */
                                  VAR(uint8, ANFCRL_VAR) bAfi2,         /**< [In] AFI; Application Family Identifier. */
                                  VAR(uint8, ANFCRL_VAR) bExtAtqb2,     /**< [In] Enable Extended AtqB. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,      /**< [Out] AtqB; uint8[12/13]. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2    /**< [Out] length of ATQB (12/13 bytes). */
                                  );

/**
* \brief Perform a ISO14443-3B Slot-MARKER command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_SlotMarker2(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layers parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bSlotNumber2,   /**< [In] Slot Number. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,       /**< [Out] AtqB; uint8[12/13]. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2     /**< [Out] length of ATQB (12/13 bytes). */
                                     );

/**
* \brief Perform a ISO14443-3B Halt command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_HaltB2(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2  /**< [In] Pointer to this layers parameter structure. */
                                );

/**
* \brief Perform a ISO14443-3B Attrib command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Attrib2(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layers parameter structure. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,       /**< [In] Atqb from ReqB/WupB; uint8[12/13]. */
                                 VAR(uint8, ANFCRL_VAR) bAtqbLen2,      /**< [In] Length of Atqb. */
                                 VAR(uint8, ANFCRL_VAR) bFsdi2,         /**< [In] Frame Size Integer; 0-8. */
                                 VAR(uint8, ANFCRL_VAR) bCid2,          /**< [In] Card Identifier; 0-14. */
                                 VAR(uint8, ANFCRL_VAR) bDri2,          /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                 VAR(uint8, ANFCRL_VAR) bDsi2,          /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2        /**< [Out] MBLI byte; uint8. */
                                 );

/**
* \brief Perform ISO14443-3B ReqB or WupB and Anticollision/Select commands for all cascade levels.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* If bLenUidIn is '0' --> CardUid not given, a ReqB is performed.
* If CardUid is given, a WupB is performed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_ActivateCard2(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,              /**< [In] Pointer to this layers parameter structure. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2,                 /**< [In] Pointer to the known PUPI; uint8[4]. */
                                       VAR(uint8, ANFCRL_VAR) bPupiLength2,             /**< [In] Length of given PUPI, only a value of 0 or 4 is allowed. */
                                       VAR(uint8, ANFCRL_VAR) bNumSlots2,               /**< [In] Number of slots. */
                                       VAR(uint8, ANFCRL_VAR) bAfi2,                    /**< [In] AFI; Application Family Identifier. */
                                       VAR(uint8, ANFCRL_VAR) bExtAtqb2,                /**< [In] Enable Extended AtqB. */
                                       VAR(uint8, ANFCRL_VAR) bFsdi2,                   /**< [In] Frame Size Integer; 0-8. */
                                       VAR(uint8, ANFCRL_VAR) bCid2,                    /**< [In] Card Identifier; 0-14. */
                                       VAR(uint8, ANFCRL_VAR) bDri2,                    /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                       VAR(uint8, ANFCRL_VAR) bDsi2,                    /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,                 /**< [Out] AtqB; uint8[13]. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2,              /**< [Out] length of ATQB (12/13 bytes). */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2,                 /**< [Out] MBLI byte; uint8. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2    /**< [Out] Whether there are more cards in the field or not; uint8. */
                                       );

/**
* \brief Perform ISO14443-3B Data Exchange with Picc.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b wOption2 can be one of:\n
* \li #PH_EXCHANGE_DEFAULT2
* \li #PH_EXCHANGE_BUFFER_FIRST2
* \li #PH_EXCHANGE_BUFFER_CONT2
* \li #PH_EXCHANGE_BUFFER_LAST2
*
* Alternatively, the following bits can be combined:\n
* \li #PH_EXCHANGE_BUFFERED_BIT2
* \li #PH_EXCHANGE_LEAVE_BUFFER_BIT2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Exchange2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,      /**< [In] Pointer to this layers parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wOption2,        /**< [In] Option parameter. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,     /**< [In] Data to transmit. */
                                   VAR(uint16, ANFCRL_VAR) wTxLength2,      /**< [In] Length of data to transmit. */
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,   /**< [Out] Pointer to received data. */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2     /**< [Out] number of received data bytes. */
                                   );

/**
* \brief Retrieve the serial number.
* This function will provide 4 byte PUPI.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_USE_CONDITION2 No PUPI available.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_GetSerialNo2(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2       /**< [Out] Most recent PUPI. */
                                      );

/**
* \brief This function will update PUPI in this layer's parameter structure.
* This function must be called with valid PUPI.
* Once set the subsequent type B commands use this PUPI.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_SetSerialNo2(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2       /**< [In] 4 byte PUPI. */
                                      );

/**
* \brief Set higher layer information.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_USE_CONDITION2 Feature not available.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_SetHigherLayerInf2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,    /**< [In] Higher layer Information; Can be NULL if /c wTxLength2 is 0. */
    VAR(uint16, ANFCRL_VAR) wTxLength2,    /**< [In] Length of the Higher layer Information. Can be 0. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,    /**< [In] Higher layer response buffer. */
    VAR(uint16, ANFCRL_VAR) wRxBufSize2     /**< [In] Size of Higher layer response buffer. */
    );

/**
* \brief Get higher layer response.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_USE_CONDITION2 Feature not available.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_GetHigherLayerResp2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,     /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,  /**< [Out] Higher layer response. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2    /**< [Out] Length of Higher layer response. */
    );

/**
* \brief Retrieve the ISO14443-3B protocol parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_GetProtocolParams2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled2,      /**< [Out] Unequal '0' if Card Identifier is enabled. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid2,             /**< [Out] Card Identifier. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported2,    /**< [Out] Node Address Support; Unequal '0' if supported. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi2,             /**< [Out] Frame Waiting Integer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi2,            /**< [Out] PCD Frame Size Integer; 0-8. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci2             /**< [Out] PICC Frame Size Integer; 0-8. */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalI14443p3b2 ISO/IEC 14443-3B
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P3B2 */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3B2_H */
