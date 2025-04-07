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
*   @file    phpalI14443p42.h
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
#ifndef PHPALI14443P42_H
#define PHPALI14443P42_H

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
#include "phhalHw2.h"
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p42.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p42.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p42.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p42.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW2

/** \defgroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

#define PHPAL_I14443P4_SW_ID2        0x01U    /**< ID for Software ISO14443-4 layer */

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */


#ifdef NXPBUILD__PHPAL_I14443P42

/** \addtogroup ph_Error Error Code Collection
* phpalI14443p4 Custom Errors
* @{
*/

/**
* \name phpalI14443p4 Error Codes
*/
/*@{*/
#define PHPAL_I14443P4_ERR_RECOVERY_FAILED2  ((phStatus_t2)PH_ERR_CUSTOM_BEGIN2 + 0U)     /**< ISO14443-4 error recovery failed. */
#define PHPAL_I14443P4_ERR_RETRY_FAILED2     ((phStatus_t2)PH_ERR_CUSTOM_BEGIN2 + 1U)     /**< ISO14443-4 error recovery failed. */
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

#define PHPAL_I14443P4_CID_MAX2          14U  /**< The last valid CID. */
#define PHPAL_I14443P4_FWI_MAX2          14U  /**< The maximum allowed FWI value. */
#ifdef PH_NXPNFCRDLIB_CONFIG_NFC_FORUM_TEST2
#define PHPAL_I14443P4_FRAMESIZE_MAX2    12U   /**< The maximum allowed FSDI/FSCI value. */
#else
#define PHPAL_I14443P4_FRAMESIZE_MAX2    8U   /**< The maximum allowed FSDI/FSCI value. */
#endif

/**
* \name ISO14443-4 Parameters
*/
/*@{*/
/**
* \brief Set / Get Block number.
*/
#define PHPAL_I14443P4_CONFIG_BLOCKNO2           0x0000U
/**
* \brief Set / Get Card Identifier.
*
* \c wValue2 is parsed as follows:
* \verbatim
* CidEnabled = (wValue2 & 0xFF00U) ? 1 : 0;
* Cid = (wValue2 & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_CID2               0x0001U
/**
* \brief Set / Get Node Address.
*
* \c wValue2 is parsed as follows:
* \verbatim
* NadEnabled = (wValue2 & 0xFF00U) ? 1 : 0;
* Nad = (wValue2 & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_NAD2               0x0002U
/**
* \brief Set / Get Frame Waiting Integer.
*/
#define PHPAL_I14443P4_CONFIG_FWI2               0x0003U
/**
* \brief Set / Get PCD & PICC Frame Size Integer.
*
* \c wValue2 is parsed as follows:
* \verbatim
* Fsdi = ((wValue2 & 0xFF00U) >> 8U);
* Fsci = (wValue2 & 0x00FFU);
* \endverbatim
*/
#define PHPAL_I14443P4_CONFIG_FSI2               0x0004U
/**
* \brief Set / Get Maximum Retry Count.
*/
#define PHPAL_I14443P4_CONFIG_MAXRETRYCOUNT2     0x0005U

/**
* \brief Configure Operation mode.
*/

/**
 * Configure Operation Mode for this Layer. \n
 * Possible values are\n
 *      #RD_LIB_MODE_EMVCO2, \n
 *      #RD_LIB_MODE_NFC2, \n
 *      #RD_LIB_MODE_ISO2,\n
 * Default value is #RD_LIB_MODE_NFC2.
 * */
#define PHPAL_I14443P4_CONFIG_OPE_MODE2          0x0006U
/*@}*/

#ifdef NXPRDLIB_REM_GEN_INTFS2

#define phpalI14443p4_SetProtocol2( pDataParams2, bCidEnable2,  bCid2,  bNadEnable2,   bNad2, bFwi2,  bFsdi2, bFsci2) \
         phpalI14443p4_Sw_SetProtocol2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2, bCidEnable2, bCid2, bNadEnable2,bNad2, bFwi2, bFsdi2,bFsci2)

#define phpalI14443p4_ResetProtocol2(pDataParams2) \
        phpalI14443p4_Sw_ResetProtocol2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2)

#define phpalI14443p4_Deselect2( pDataParams2) \
        phpalI14443p4_Sw_Deselect2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2)

#define  phpalI14443p4_PresCheck2( pDataParams2) \
        phpalI14443p4_Sw_PresCheck2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2)

#define phpalI14443p4_Exchange2( pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2) \
        phpalI14443p4_Sw_Exchange2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2)

#define phpalI14443p4_SetConfig2( pDataParams2, wConfig2, wValue2) \
        phpalI14443p4_Sw_SetConfig2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2, wConfig2, wValue2)

#define phpalI14443p4_GetConfig2( pDataParams2, wConfig2, pValue2) \
        phpalI14443p4_Sw_GetConfig2((phpalI14443p4_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2)

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalI14443p4 ISO/IEC 14443-4
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P42 */


/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW2
/** \addtogroup phpalI14443p4_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4
* \ingroup phpalI14443p4
* @{
*/

/**
 * \brief State for PresCheck
 */
typedef enum {
    PHPAL_I14443P4_PRESCHECK_SEND2 = 0,
    PHPAL_I14443P4_PRESCHECK_WAITRSP2
} I14443P4_PRESCHECK_StateType_t2;

/**
 * \brief State for Deselect
 */
typedef enum {
    PHPAL_I14443P4_DESEL_IDLE2 = 0,
    PHPAL_I14443P4_DESEL_SEND2
} I14443P4_DESEL_StateType_t2;

/**
 * \brief State for Iso message
 */
typedef enum {
    PHPAL_I14443P4_STATE_IDLE2 = 0,
    PHPAL_I14443P4_STATE_SEND_BLOCK2,
	PHPAL_I14443P4_STATE_WAITRSP_BLOCK2,
	PHPAL_I14443P4_STATE_DISPATCHER_RETURNCASE2,
    PHPAL_I14443P4_STATE_DESEL2,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_MS2,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_VALUE_US2,
    PHPAL_I14443P4_STATE_SET_WTX_TIMEOUT_SUCCESS2,
    PHPAL_I14443P4_STATE_WAITRSP_SEND_DESELECT2,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_MS2,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_VALUE_US2,
    PHPAL_I14443P4_STATE_RESTORE_WTX_TIMEOUT_SUCCESS2
} I14443P4_ISOMSG_StateType_t2;

/**
 * \brief State for Exchange
 */
typedef enum {
    PHPAL_I14443P4_EXCHANGE_START2 = 0,
    PHPAL_I14443P4_EXCHANGE_I_BLOCK_TX2,
    PHPAL_I14443P4_EXCHANGE_I_BLOCK_RX2,
	PHPAL_I14443P4_EXCHANGE_ISO_HANDLING2
} I14443P4_EXCHANGE_StateType_t2;

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4_SW2

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
  VAR(uint16, ANFCRL_VAR) wId2;              /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2;   /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) bStateNow2;        /**< Current Exchange-State. */
  VAR(uint8, ANFCRL_VAR) bCidEnabled2;      /**< Card Identifier Enabler; Unequal '0' if enabled. */
  VAR(uint8, ANFCRL_VAR) bCid2;             /**< Card Identifier; Ignored if *pCidSupported is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bNadEnabled2;      /**< Node Address Enabler; Unequal '0' if enabled. */
  VAR(uint8, ANFCRL_VAR) bNad2;             /**< Node Address; Ignored if bNadEnabled2 is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bFwi2;             /**< Frame Waiting Integer. */
  VAR(uint8, ANFCRL_VAR) bFsdi2;            /**< PCD Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bFsci2;            /**< PICC Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bPcbBlockNum2;     /**< Current Block-Number; 0/1; */
  VAR(uint8, ANFCRL_VAR) bMaxRetryCount2;   /**< Maximum Retry count for ISO/IEC 14443-4:2008(E) Rule 4 and 5. */
  VAR(uint8, ANFCRL_VAR) bOpeMode2;         /**< Operation mode. One of NFC, EMVCo, ISO. */
	/**
	 * Temporary Tx pointer and Tx Length for exchange if caller hasn't provided valid TxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) wTmpTxLen2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpTxBuff2;
	/**
	 * Temporary Rx pointer and Rx Length for exchange if caller hasn't provided valid RxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) wTmpRxLen2;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuff2;
	/* State variables for Non-Blocking */
  VAR(I14443P4_DESEL_StateType_t2, ANFCRL_VAR) eDeselState2;      /**< Handle state of Deselect function of I14443P4. */
  VAR(I14443P4_PRESCHECK_StateType_t2, ANFCRL_VAR) ePresCheckState2;  /**< Handle state of PresCheck function of I14443P4. */
  VAR(I14443P4_ISOMSG_StateType_t2, ANFCRL_VAR) eIsoMsgState2;    /**< Handle state of Iso message of I14443P4. */
  VAR(I14443P4_EXCHANGE_StateType_t2, ANFCRL_VAR) eExchangeState2;  /**< Handle state of Exchange function of I14443P4. */
} phpalI14443p4_Sw_DataParams_t2;

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION2 == 0))
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
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_Init2(
                                 P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,                    /**< [In] Specifies the size of the data parameter structure. */
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2                          /**< [In] Pointer to the parameter structure of the underlying layer. */
                                 );

/**
 * end of group phpalI14443p4_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */



#ifdef NXPBUILD__PHPAL_I14443P42
/** \addtogroup phpalI14443p4 ISO/IEC 14443-4
* \ingroup phpalProtocol
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phpalI14443p4/src/Sw/phpalI14443p4_Sw2.h"
#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION2 == 0))
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
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_SetProtocol2(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,        /**< [In] Pointer to this layer's parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bCidEnable2,      /**< [In] Enable usage of Card Identifier; Unequal '0' if enabled. */
                                     VAR(uint8, ANFCRL_VAR) bCid2,            /**< [In] Card Identifier; Ignored if \c bCidEnable2 is equal '0'. */
                                     VAR(uint8, ANFCRL_VAR) bNadEnable2,      /**< [In] Enabler usage of Node Address; Unequal '0' if enabled. */
                                     VAR(uint8, ANFCRL_VAR) bNad2,            /**< [In] Node Address; Ignored if bNadEnabled2 is equal '0'. */
                                     VAR(uint8, ANFCRL_VAR) bFwi2,            /**< [In] Frame Waiting Integer. */
                                     VAR(uint8, ANFCRL_VAR) bFsdi2,           /**< [In] PCD Frame Size Integer; 0-8 */
                                     VAR(uint8, ANFCRL_VAR) bFsci2            /**< [In] PICC Frame Size Integer; 0-8 */
                                     );

/**
* \brief Reset the ISO14443-4 protocol parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_ResetProtocol2(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2   /**< [In] Pointer to this layer's parameter structure. */
                                       );

/**
* \brief Deselect ISO14443-4 card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Deselect2(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2    /**< [In] Pointer to this layer's parameter structure. */
                                  );

/**
* \brief Perform presence check for current card. (Perform R(NAK) polling as defined in ISO 14443-4:2008(E)).
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_PresCheck2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2   /**< [In] Pointer to this layer's parameter structure. */
                                   );

/**
* \brief Perform ISO14443-4 Data Exchange with Picc.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
* Limitations: Not support BUFFERING OPTION & Size of TxBuffer do not exceed 256 bytes
*
* \b wOption2 can be only:\n
* \li #PH_EXCHANGE_DEFAULT
*
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Exchange2(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption2,         /**< [In] Option parameter. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,      /**< [In] Data to transmit. */
                                  VAR(uint16, ANFCRL_VAR) wTxLength2,       /**< [In] Length of data to transmit. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,    /**< [Out] Pointer to received data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2      /**< [Out] number of received data bytes. */
                                  );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_SetConfig2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Configuration Identifier */
                                   VAR(uint16, ANFCRL_VAR) wValue2      /**< [In] Configuration Value */
                                   );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_GetConfig2(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Configuration Identifier */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2    /**< [Out] Configuration Value */
                                   );
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalI14443p4 ISO/IEC 14443-4
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P42 */

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P42_H */
