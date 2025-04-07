/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018 - 2021
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
*   @file    phpalI14443p4.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4 - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4 ISO/IEC 14443-4
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
#ifndef PHPALI14443P4_H
#define PHPALI14443P4_H

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
#include "phhalHw.h"
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW

/** \defgroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

#define PHPAL_I14443P4_SW_ID        0x01U    /**< ID for Software ISO14443-4 layer */

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW */


#ifdef NXPBUILD__PHPAL_I14443P4

/** \addtogroup ph_Error Error Code Collection
* phpalI14443p4 Custom Errors
* @{
*/

/**
* \name phpalI14443p4 Error Codes
*/
/*@{*/
#define PHPAL_I14443P4_ERR_RECOVERY_FAILED  ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U)     /**< ISO14443-4 error recovery failed. */
#define PHPAL_I14443P4_ERR_RETRY_FAILED     ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 1U)     /**< ISO14443-4 error recovery failed. */
/*@}*/

/**
 * end of group ph_Error Error Code Collection
 * @}
 */

/** \defgroup phpalI14443p4 ISO/IEC 14443-4
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-4:2008(E) contactless protocol.
* @{
*/

#define PHPAL_I14443P4_CID_MAX          14U  /**< The last valid CID. */
#define PHPAL_I14443P4_FWI_MAX          14U  /**< The maximum allowed FWI value. */
#ifdef PH_NXPNFCRDLIB_CONFIG_NFC_FORUM_TEST
#define PHPAL_I14443P4_FRAMESIZE_MAX    12U   /**< The maximum allowed FSDI/FSCI value. */
#else
#define PHPAL_I14443P4_FRAMESIZE_MAX    8U   /**< The maximum allowed FSDI/FSCI value. */
#endif

/**
* \name ISO14443-4 Parameters
*/
/*@{*/
/**
* \brief Set / Get Block number.
*/
#define PHPAL_I14443P4_CONFIG_BLOCKNO           0x0000U
/**
* \brief Set / Get Card Identifier.
*
* \c wValue is parsed as follows:
* \verbatim
* CidEnabled = (wValue & 0xFF00U) ? 1 : 0;
* Cid = (wValue & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_CID               0x0001U
/**
* \brief Set / Get Node Address.
*
* \c wValue is parsed as follows:
* \verbatim
* NadEnabled = (wValue & 0xFF00U) ? 1 : 0;
* Nad = (wValue & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_NAD               0x0002U
/**
* \brief Set / Get Frame Waiting Integer.
*/
#define PHPAL_I14443P4_CONFIG_FWI               0x0003U
/**
* \brief Set / Get PCD & PICC Frame Size Integer.
*
* \c wValue is parsed as follows:
* \verbatim
* Fsdi = ((wValue & 0xFF00U) >> 8U);
* Fsci = (wValue & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_FSI               0x0004U
/**
* \brief Set / Get Maximum Retry Count.
*/
#define PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT     0x0005U

/**
* \brief Configure Operation mode.
*/

/**
 * Configure Operation Mode for this Layer. \n
 * Possible values are\n
 *      #RD_LIB_MODE_EMVCO, \n
 *      #RD_LIB_MODE_NFC, \n
 *      #RD_LIB_MODE_ISO,\n
 * Default value is #RD_LIB_MODE_NFC.
 * */
#define PHPAL_I14443P4_CONFIG_OPE_MODE          0x0006U
/*@}*/

#ifdef NXPRDLIB_REM_GEN_INTFS

#define phpalI14443p4_SetProtocol( pDataParams, bCidEnable,  bCid,  bNadEnable,   bNad, bFwi,  bFsdi, bFsci) \
         phpalI14443p4_Sw_SetProtocol((phpalI14443p4_Sw_DataParams_t *)pDataParams, bCidEnable, bCid, bNadEnable,bNad, bFwi, bFsdi,bFsci)

#define phpalI14443p4_ResetProtocol(pDataParams) \
        phpalI14443p4_Sw_ResetProtocol((phpalI14443p4_Sw_DataParams_t *)pDataParams)

#define phpalI14443p4_Deselect( pDataParams) \
        phpalI14443p4_Sw_Deselect((phpalI14443p4_Sw_DataParams_t *)pDataParams)

#define  phpalI14443p4_PresCheck( pDataParams) \
        phpalI14443p4_Sw_PresCheck((phpalI14443p4_Sw_DataParams_t *)pDataParams)

#define phpalI14443p4_Exchange( pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength) \
        phpalI14443p4_Sw_Exchange((phpalI14443p4_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phpalI14443p4_SetConfig( pDataParams, wConfig, wValue) \
        phpalI14443p4_Sw_SetConfig((phpalI14443p4_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#define phpalI14443p4_GetConfig( pDataParams, wConfig, pValue) \
        phpalI14443p4_Sw_GetConfig((phpalI14443p4_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalI14443p4 ISO/IEC 14443-4
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4 */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW
/** \addtogroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

/**
 * \brief State for PresCheck
 */
typedef enum {
    PHPAL_I14443P4_PRESCHECK_SEND = 0,
    PHPAL_I14443P4_PRESCHECK_WAITRSP
} I14443P4_PRESCHECK_StateType_t;

/**
 * \brief State for Deselect
 */
typedef enum {
    PHPAL_I14443P4_DESEL_IDLE = 0,
    PHPAL_I14443P4_DESEL_SEND
} I14443P4_DESEL_StateType_t;

/**
 * \brief State for Iso message
 */
typedef enum {
    PHPAL_I14443P4_STATE_IDLE = 0,
    PHPAL_I14443P4_STATE_SEND_BLOCK,
	PHPAL_I14443P4_STATE_WAITRSP_BLOCK,
	PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE,
    PHPAL_I14443P4_STATE_DESEL,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS,
    PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS
} I14443P4_ISOMSG_StateType_t;

/**
 * \brief State for Exchange
 */
typedef enum {
    PHPAL_I14443P4_EXCHANGE_START = 0,
    PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX,
    PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX,
	PHPAL_I14443P4_EXCHANGE_ISO_HANDLING
} I14443P4_EXCHANGE_StateType_t;

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW

/** \addtogroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

/**
* \brief ISO14443-4 parameter structure
*/
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId;              /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;   /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) bStateNow;        /**< Current Exchange-State. */
  VAR(uint8, ANFCRL_VAR) bCidEnabled;      /**< Card Identifier Enabler; Unequal '0' if enabled. */
  VAR(uint8, ANFCRL_VAR) bCid;             /**< Card Identifier; Ignored if *pCidSupported is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bNadEnabled;      /**< Node Address Enabler; Unequal '0' if enabled. */
  VAR(uint8, ANFCRL_VAR) bNad;             /**< Node Address; Ignored if bNadEnabled is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bFwi;             /**< Frame Waiting Integer. */
  VAR(uint8, ANFCRL_VAR) bFsdi;            /**< PCD Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bFsci;            /**< PICC Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bPcbBlockNum;     /**< Current Block-Number; 0/1; */
  VAR(uint8, ANFCRL_VAR) bMaxRetryCount;   /**< Maximum Retry count for ISO/IEC 14443-4:2008(E) Rule 4 and 5. */
  VAR(uint8, ANFCRL_VAR) bOpeMode;         /**< Operation mode. One of NFC, EMVCo, ISO. */
	/**
	 * Temporary Tx pointer and Tx Length for exchange if caller hasn't provided valid TxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) wTmpTxLen;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpTxBuff;
	/**
	 * Temporary Rx pointer and Rx Length for exchange if caller hasn't provided valid RxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) wTmpRxLen;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuff;
	/* State variables for Non-Blocking */
  VAR(I14443P4_DESEL_StateType_t, ANFCRL_VAR) eDeselState;      /**< Handle state of Deselect function of I14443P4. */
  VAR(I14443P4_PRESCHECK_StateType_t, ANFCRL_VAR) ePresCheckState;  /**< Handle state of PresCheck function of I14443P4. */
  VAR(I14443P4_ISOMSG_StateType_t, ANFCRL_VAR) eIsoMsgState;    /**< Handle state of Iso message of I14443P4. */
  VAR(I14443P4_EXCHANGE_StateType_t, ANFCRL_VAR) eExchangeState;  /**< Handle state of Exchange function of I14443P4. */
} phpalI14443p4_Sw_DataParams_t;

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Init(
                                 P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                    /**< [In] Specifies the size of the data parameter structure. */
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                          /**< [In] Pointer to the parameter structure of the underlying layer. */
                                 );

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4_SW */



#ifdef NXPBUILD__PHPAL_I14443P4
/** \addtogroup phpalI14443p4 ISO/IEC 14443-4
* \ingroup phpalProtocol
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalI14443p4/src/Sw/phpalI14443p4_Sw.h"
#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Set the ISO14443-4 protocol parameters.
*
* This sets the protocol parameters for this layer.
* It is recommended to input this function with the parameters retrieved from either
* \ref phpalI14443p4a_GetProtocolParams or \ref phpalI14443p3b_GetProtocolParams respectively after card activation.
* \b Note: Refer to the ISO/IEC 14443-4:2008(E) specification for a detailed description of the parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_SetProtocol(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bCidEnable,      /**< [In] Enable usage of Card Identifier; Unequal '0' if enabled. */
                                     VAR(uint8, ANFCRL_VAR) bCid,            /**< [In] Card Identifier; Ignored if \c bCidEnable is equal '0'. */
                                     VAR(uint8, ANFCRL_VAR) bNadEnable,      /**< [In] Enabler usage of Node Address; Unequal '0' if enabled. */
                                     VAR(uint8, ANFCRL_VAR) bNad,            /**< [In] Node Address; Ignored if bNadEnabled is equal '0'. */
                                     VAR(uint8, ANFCRL_VAR) bFwi,            /**< [In] Frame Waiting Integer. */
                                     VAR(uint8, ANFCRL_VAR) bFsdi,           /**< [In] PCD Frame Size Integer; 0-8 */
                                     VAR(uint8, ANFCRL_VAR) bFsci            /**< [In] PICC Frame Size Integer; 0-8 */
                                     );

/**
* \brief Reset the ISO14443-4 protocol parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_ResetProtocol(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams   /**< [In] Pointer to this layer's parameter structure. */
                                       );

/**
* \brief Deselect ISO14443-4 card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Deselect(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams    /**< [In] Pointer to this layer's parameter structure. */
                                  );

/**
* \brief Perform presence check for current card. (Perform R(NAK) polling as defined in ISO 14443-4:2008(E)).
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_PresCheck(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams   /**< [In] Pointer to this layer's parameter structure. */
                                   );

/**
* \brief Perform ISO14443-4 Data Exchange with Picc.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
* Limitations: Not support BUFFERING OPTION & Size of TxBuffer do not exceed 256 bytes
*
* \b wOption can be only:\n
* \li #PH_EXCHANGE_DEFAULT
*
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Exchange(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] Option parameter. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,      /**< [In] Data to transmit. */
                                  VAR(uint16, ANFCRL_VAR) wTxLength,       /**< [In] Length of data to transmit. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] Pointer to received data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength      /**< [Out] number of received data bytes. */
                                  );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_SetConfig(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Configuration Identifier */
                                   VAR(uint16, ANFCRL_VAR) wValue      /**< [In] Configuration Value */
                                   );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_GetConfig(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Configuration Identifier */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue    /**< [Out] Configuration Value */
                                   );
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalI14443p4 ISO/IEC 14443-4
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4 */

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4_H */
