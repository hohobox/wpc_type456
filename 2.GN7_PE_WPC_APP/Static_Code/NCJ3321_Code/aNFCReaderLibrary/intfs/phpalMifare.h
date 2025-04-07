/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2021
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
*   @file    phpalMifare.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palMifare - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalMifare MIFARE(R)
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

#ifndef PHPALMIFARE_H
#define PHPALMIFARE_H

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
* @file           phpalMifare.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALMIFARE_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALMIFARE_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALMIFARE_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALMIFARE_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALMIFARE_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALMIFARE_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALMIFARE_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALMIFARE_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALMIFARE_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalMifare.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALMIFARE_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALMIFARE_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALMIFARE_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalMifare.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALMIFARE_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALMIFARE_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALMIFARE_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalMifare.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_MIFARE_SW
/** \defgroup phpalMifare_Sw Component : Software
* \ingroup phpalMifare
* \brief Software component of MIFARE(R) Classic, MIFARE(R) Ultralight, MIFARE(R) DESFire and MIFARE(R) Plus
* @{
*/

#define PHPAL_MIFARE_SW_ID          0x02U    /**< ID for Software MIFARE layer. */

/**
 * end of group phpalMifare_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_MIFARE_SW */

#ifdef NXPBUILD__PHPAL_MIFARE
/** \addtogroup ph_Error Error Code Collection
* phpalMifare Custom Errors
* @{
*/

/**
* \name phpalMifare Error Codes
*/
/*@{*/
#define PHPAL_MIFARE_ERR_NAK0   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U)     /**< NAK 0 */
#define PHPAL_MIFARE_ERR_NAK1   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 1U)     /**< NAK 1 */
#define PHPAL_MIFARE_ERR_NAK4   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 2U)     /**< NAK 4 */
#define PHPAL_MIFARE_ERR_NAK5   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 3U)     /**< NAK 5 */
#define PHPAL_MIFARE_ERR_NAK6   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 4U)     /**< NAK 6 */
#define PHPAL_MIFARE_ERR_NAK7   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 5U)     /**< NAK 7 */
#define PHPAL_MIFARE_ERR_NAK8   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 6U)     /**< NAK 8 */
#define PHPAL_MIFARE_ERR_NAK9   ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 7U)     /**< NAK 9 */
/*@}*/

/**
 * end of group ph_Error Error Code Collection
 * @}
 */


/** \defgroup phpalMifare MIFARE(R)
* \ingroup phpalProtocol
* \brief These Components implement the MIFARE(R) Classic, MIFARE(R) Ultralight,
* MIFARE(R) DESFire and MIFARE(R) Plus products.
* @{
*/

/**
* \name Authenticate Options
*/
/*@{*/
#define PHPAL_MIFARE_KEYA               0x0AU   /**< MIFARE Classic Key Type A. */
#define PHPAL_MIFARE_KEYB               0x0BU   /**< MIFARE Classic Key Type B. */
#define PHPAL_MIFARE_KEY_LENGTH         0x06U   /**< Length of a MIFARE Classic key (for completeness). */
/*@}*/

#ifdef  NXPRDLIB_REM_GEN_INTFS

#define phpalMifare_ExchangeL3( pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)    \
        phpalMifare_Sw_ExchangeL3((phpalMifare_Sw_DataParams_t *)pDataParams,  wOption, pTxBuffer, wTxLength,ppRxBuffer, pRxLength)

#define phpalMifare_ExchangeL4( pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength) \
        phpalMifare_Sw_ExchangeL4((phpalMifare_Sw_DataParams_t *)pDataParams, wOption,pTxBuffer, wTxLength,  ppRxBuffer,pRxLength)

#define phpalMifare_ExchangePc( pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength) \
        phpalMifare_Sw_ExchangePc((phpalMifare_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phpalMifare_ExchangeRaw( pDataParams, wOption, pTxBuffer, wTxLength, bTxLastBits, ppRxBuffer, pRxLength, pRxLastBits) \
        phpalMifare_Sw_ExchangeRaw((phpalMifare_Sw_DataParams_t *)pDataParams,wOption, pTxBuffer, wTxLength, bTxLastBits, ppRxBuffer, pRxLength,pRxLastBits)

#define phpalMifare_MfcAuthenticateKeyNo( pDataParams, bBlockNo, bKeyType, wKeyNo, wKeyVersion, pUid) \
        phpalMifare_Sw_MfcAuthenticateKeyNo((phpalMifare_Sw_DataParams_t *)pDataParams, bBlockNo, bKeyType, wKeyNo,wKeyVersion, pUid)

#define phpalMifare_MfcAuthenticate( pDataParams, bBlockNo, bKeyType, pKey, pUid) \
        phpalMifare_Sw_MfcAuthenticate((phpalMifare_Sw_DataParams_t *)pDataParams, bBlockNo, bKeyType, pKey, pUid)

#define phpalMifare_SetMinFdtPc(pDataParams,  wValue) \
        phpalMifare_Sw_SetMinFdtPc( (phpalMifare_Sw_DataParams_t *)pDataParams,wValue)

#define phpalMifare_GetConfig(pDataParams, wConfig, pValue) \
        phpalMifare_Sw_GetConfig((phpalMifare_Sw_DataParams_t *)pDataParams, wConfig, pValue)
#endif /* NXPRDLIB_REM_GEN_INTFS */
/**
 * end of group phpalMifare MIFARE(R)
 * @}
 */
#endif /* NXPBUILD__PHPAL_MIFARE */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_MIFARE_SW
/** \addtogroup phpalMifare_Sw Component : Software
* \ingroup phpalMifare
* \brief Software component of MIFARE(R) Classic, MIFARE(R) Ultralight, MIFARE(R) DESFire and MIFARE(R) Plus
* @{
*/

/**
* \brief Software PAL-MIFARE parameter structure
*/
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId;                       /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;             /**< Pointer to the parameter structure of the underlying HAL layer. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalI14443p4DataParams;     /**< Pointer to the parameter structure of the underlying ISO14443-4 layer. */
	/**
	 * Temporary Rx pointer and Rx Length for exchange if caller hasn't provided valid RxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) wRxLength;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer;
} phpalMifare_Sw_DataParams_t;

/**
 * end of group phpalMifare_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_MIFARE_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_MIFARE_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALMIFARE_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phpalMifare_Sw Component : Software
* \ingroup phpalMifare
* \brief Software component of MIFARE(R) Classic, MIFARE(R) Ultralight, MIFARE(R) DESFire and MIFARE(R) Plus
* @{
*/

/**
* \brief Initialize this layer.
*
* \b Remark: \c pPalI14443p4DataParams can be NULL in case \ref phpalMifare_ExchangeL4 and
* \ref phpalMifare_ExchangePc are not needed.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_Init(
                               P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                  /**< [In] Specifies the size of the data parameter structure. */
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams,                       /**< [In] Pointer to the parameter structure of the underlying HAL layer. */
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalI14443p4DataParams                /**< [In] Pointer to the parameter structure of the underlying ISO14443-4 layer. */
                               );

/**
 * end of group phpalMifare_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALMIFARE_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHPAL_MIFARE_SW */

#ifdef NXPBUILD__PHPAL_MIFARE
/** \addtogroup phpalMifare MIFARE(R)
* \ingroup phpalProtocol
* \brief These Components implement the MIFARE(R) Classic, MIFARE(R) Ultralight,
* MIFARE(R) DESFire and MIFARE(R) Plus products.
* @{
*/

#ifdef  NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalMifare/src/Sw/phpalMifare_Sw.h"
#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALMIFARE_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Perform ISO14443-3 Data Exchange with MIFARE product-based PICC.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \c wOption can be one of:\n
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
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_ExchangeL3(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] Option parameter. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,      /**< [In] Data to transmit. */
                                  VAR(uint16, ANFCRL_VAR) wTxLength,       /**< [In] Length of data to transmit. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] Pointer to received data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength      /**< [Out] number of received data bytes. */
                                  );

/**
* \brief Perform ISO14443-4 Data Exchange with MIFARE product-based PICC.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \c wOption can be one of:\n
* \li #PH_EXCHANGE_DEFAULT
* \li #PH_EXCHANGE_TXCHAINING
* \li #PH_EXCHANGE_RXCHAINING
* \li #PH_EXCHANGE_RXCHAINING_BUFSIZE
*
* Additionally, the following options are also available:\n
* \li #PH_EXCHANGE_BUFFER_FIRST
* \li #PH_EXCHANGE_BUFFER_CONT
* \li #PH_EXCHANGE_BUFFER_LAST
*
* Alternatively to the FIRST/CONT/LAST options, the following bits can be combined:\n
* \li #PH_EXCHANGE_BUFFERED_BIT
* \li #PH_EXCHANGE_LEAVE_BUFFER_BIT
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_ExchangeL4(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] Option parameter. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,      /**< [In] Data to transmit. */
                                  VAR(uint16, ANFCRL_VAR) wTxLength,       /**< [In] Length of data to transmit. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] Pointer to received data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength      /**< [Out] number of received data bytes. */
                                  );

/**
* \brief Perform Proximity-Check Data Exchange with MIFARE product-based PICC.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b Note: The \c wOption parameter is currently RFU.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_ExchangePc(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] Option parameter. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,      /**< [In] Data to transmit. */
                                  VAR(uint16, ANFCRL_VAR) wTxLength,       /**< [In] Length of data to transmit. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] Pointer to received data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength      /**< [Out] number of received data bytes. */
                                  );

/**
* \brief Perform Raw (No CRC, No Parity) Data Exchange with MIFARE product-based PICC.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \c wOption can be one of:\n
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
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_ExchangeRaw(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wOption,        /**< [In] Option parameter. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,     /**< [In] Data to transmit. */
                                   VAR(uint16, ANFCRL_VAR) wTxLength,      /**< [In] Length of input data. */
                                   VAR(uint8, ANFCRL_VAR) bTxLastBits,     /**< [In] Number of valid bits of last byte (Tx). */
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,   /**< [Out] Pointer to received data. */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,    /**< [Out] Number of received data bytes including incomplete byte. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLastBits    /**< [Out] Number of valid bits of last byte (Rx). */
                                   );

/**
* \brief Perform MIFARE Classic Authenticate command with Picc using a key number.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_IO_TIMEOUT Error in authentication.
* \retval #PH_ERR_AUTH_ERROR Error in authentication.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_MfcAuthenticateKeyNo(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,       /**< [In] Block-Number on card to authenticate to. */
    VAR(uint8, ANFCRL_VAR) bKeyType,       /**< [In] Either #PHPAL_MIFARE_KEYA or #PHPAL_MIFARE_KEYB */
    VAR(uint16, ANFCRL_VAR) wKeyNo,        /**< [In] Key number to be used in authentication. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion,   /**< [In] Key version to be used in authentication. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid          /**< [In] Serial number of current cascade level; uint8[4]. */
    );

/**
* \brief Perform MIFARE Classic Authenticate command with Picc using a key.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_IO_TIMEOUT Error in authentication.
* \retval #PH_ERR_AUTH_ERROR Error in authentication.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_MfcAuthenticate(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                       VAR(uint8, ANFCRL_VAR) bBlockNo,    /**< [In] Block-Number on card to authenticate to. */
                                       VAR(uint8, ANFCRL_VAR) bKeyType,    /**< [In] Either #PHPAL_MIFARE_KEYA or #PHPAL_MIFARE_KEYB */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,      /**< [In] Key to be used in authentication. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid       /**< [In] Serial number of current cascade level; uint8[4]. */
                                       );

/**
* \brief Perform Setting min FDT for Proximity check
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_IO_TIMEOUT Error in authentication.
* \retval #PH_ERR_AUTH_ERROR Error in authentication.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_SetMinFdtPc(
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                 VAR(uint16, ANFCRL_VAR) wValue      /**< [In] Option parameter. '1' for setting '0' for resetting*/
                                 );

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_GetConfig(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                   VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Configuration Identifier */
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue    /**< [Out] Configuration Value */
                                   );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALMIFARE_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalMifare MIFARE(R)
 * @}
 */

#endif /* NXPBUILD__PHPAL_MIFARE */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALMIFARE_H */
