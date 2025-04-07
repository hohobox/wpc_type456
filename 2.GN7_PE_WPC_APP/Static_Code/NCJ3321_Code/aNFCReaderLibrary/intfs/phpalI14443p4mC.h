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
*   @file    phpalI14443p4mC.c
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p4mC ISO/IEC 14443-4mC
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

#ifndef PHPALI14443P4MC_H
#define PHPALI14443P4MC_H

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
* @file           phpalI14443p4mC.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4MC_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4mC.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4MC_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4MC_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4MC_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4MC_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
/** \defgroup phpalI14443p4mC_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4mC
* \ingroup phpalI14443p4mC
* @{
*/
#define PHPAL_I14443P4MC_SW_ID                               0x01U        /**< ID for software I18092 MT component */

/**< Event posted by response time extension timer ISR. Reader library thread listens to this event and sends the RTOx packet. */
#ifndef E_EVT_RTO_TIMEOUT
#    define E_EVT_RTO_TIMEOUT         (1U << 3U)
#endif

#define PHPAL_I14443P4MC_WTX_TIMER_IDLE		0u
#define PHPAL_I14443P4MC_WTX_TIMER_PENDING	1u
#define PHPAL_I14443P4MC_WTX_TIMER_OCCUR	2u

/**
 * end of group phpalI14443p4mC_Sw Component : Software
 * @}
 */
#endif  /* NXPBUILD__PHPAL_I14443P4MC_SW */

#ifdef NXPBUILD__PHPAL_I14443P4MC
/** \defgroup phpalI14443p4mC ISO/IEC 14443-4mC
* \brief This component implements the PICC side of ISO/IEC 14443-4 Protocol.
* @{
*/

/**
* \name ISO14443-4 card mode data rates
*/
/*@{*/
#define PHPAL_I14443P4MC_106                  0x00U           /**< Set communication speed to 106 kbs. */
#define PHPAL_I14443P4MC_212                  0x01U           /**< Set communication speed to 212 kbs. */
#define PHPAL_I14443P4MC_424                  0x02U           /**< Set communication speed to 424 kbs. */
#define PHPAL_I14443P4MC_848                  0x04U           /**< Set communication speed to 848 kbs. */
/*@}*/

/**
* \name ISO14443-4 card mode states
*/
/*@{*/
#define PHPAL_I14443P4MC_STATE_NONE           0x00U          /**< Initialized State. */
#define PHPAL_I14443P4MC_STATE_ATS            0x01U          /**< State once we send successful ATS for RATS. */
#define PHPAL_I14443P4MC_STATE_PPS            0x02U          /**< State once we receive PPS Request. */
#define PHPAL_I14443P4MC_STATE_RX             0x03U          /**< Internal State once we are in Receive State. */
#define PHPAL_I14443P4MC_STATE_TX_I           0x04U          /**< State once we have received successful I (Information) Block. */
#define PHPAL_I14443P4MC_STATE_TX_R           0x05U          /**< State once we have received R Block. */
#define PHPAL_I14443P4MC_STATE_WTX            0x07U          /**< State once we have received S Block (WTX). */
#define PHPAL_I14443P4MC_STATE_DESELECT       0x08U          /**< State once we have received S Block (DESELECT). */
#define PHPAL_I14443P4MC_STATE_PARAMETERS     0x09U          /**< State once we have received S Block (PARAMETERS). */
#define PHPAL_I14443P4MC_STATE_RESEND         0x0AU          /**< State to handle errors, like in case of NAK. */
#define PHPAL_I14443P4MC_STATE_RXCHAINING     0x0BU          /**< State to handle RX Data Chaining. */
#define PHPAL_I14443P4MC_STATE_TXCHAINING     0x0CU          /**< State to handle TX Data Chaining. */
/*@}*/

/**
* \name ISO14443-4 card mode configuration parameters
*/
/*@{*/
#define PHPAL_I14443P4MC_CONFIG_WTX           0x0000U        /**< Enable/Disable WTX feature. */
#define PHPAL_I14443P4MC_CONFIG_WTX_VALUE     0x0001U        /**< Set the WTX value. */
#define PHPAL_I14443P4MC_CONFIG_BLOCKNO       0x0002U        /**< Get the value of current ISO14443-4 protocol block number. */
#define PHPAL_I14443P4MC_CONFIG_FSDI          0x0003U        /**< Get the FSDI value. */
#define PHPAL_I14443P4MC_CONFIG_MODE          0x0004U        /**< Set/Get the operation mode (#RD_LIB_MODE_NFC or #RD_LIB_MODE_ISO). */
#define PHPAL_I14443P4MC_CONFIG_FSD           0x0005U        /**< Get the current frame size (FSD) value. */
#define PHPAL_I14443P4MC_CONFIG_WT_PERCENTAGE 0x0006U        /**< Set/Get the percentage of actual time to be used in WTX timer. */
#define PHPAL_I14443P4MC_CONFIG_WT_DELTA      0x0007U        /**< Set/Get the delta time to be subtracted from the time in WTX timer. */
#define PHPAL_I14443P4MC_CONFIG_CID_PRESENCE  0x0008U        /**< Check if CID is present in current received block. 1 - Present; 0 - Not present. */
#define PHPAL_I14443P4MC_CONFIG_NAD_PRESENCE  0x0009U        /**< Check if NAD is present in current received I-block. 1 - Present; 0 - Not present. */
/*@}*/

/**
 * end of group phpalI14443p4mC ISO/IEC 14443-4mC
 * @}
 */
#endif/*NXPBUILD__PHPAL_I14443P4MC */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
/** \addtogroup phpalI14443p4mC_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4mC
* \ingroup phpalI14443p4mC
* @{
*/

/**
* \brief WTX timer call-back function type.
*/
typedef void(*pWtxTimerCallback_t)(void);

/**
* \brief ISO14443-4 card mode PAL parameter structure
*/
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId;                                /**< Layer ID for this component, NEVER MODIFY. */
  VAR(uint16, ANFCRL_VAR) wLastTxLen;                         /**< Length of last I block send. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;                       /**< Pointer to the parameter structure of underlying hardware component. */
  VAR(phTools_EventObj_t, ANFCRL_VAR) mcEventObj;
  VAR(uint8, ANFCRL_VAR) bDisableWtx;                        /**< WTX Disable (i.e. '0' if WTX enabled). */
  VAR(uint8, ANFCRL_VAR) bWtx;                               /**< Frame Waiting Time Extension. */
  VAR(uint8, ANFCRL_VAR) bFsdi;                              /**< FSDI parameter. */
  VAR(uint8, ANFCRL_VAR) bFsci;                              /**< ATS FSCI parameter. */
  VAR(uint8, ANFCRL_VAR) bDr;                                /**< ATS DR parameter. */
  VAR(uint8, ANFCRL_VAR) bDs;                                /**< ATS DS parameter. */
  VAR(uint8, ANFCRL_VAR) bUnequalDrDs;                       /**< DR and DS are different. */
  VAR(uint8, ANFCRL_VAR) bFwi;                               /**< ATS FWI parameter. */
  VAR(uint8, ANFCRL_VAR) bSfgi;                              /**< ATS SFGI parameter. */
  VAR(uint8, ANFCRL_VAR) bCidEnable;                         /**< CID, Enabled = 1 or Disabled. */
  VAR(uint8, ANFCRL_VAR) bCidPresence;                       /**< Flag to indicate CID presence in current command-response pair. */
  VAR(uint8, ANFCRL_VAR) bCid;                               /**< CID parameter. */
  VAR(uint8, ANFCRL_VAR) bNadEnable;                         /**< NAD, Enabled = 1 or Disabled. */
  VAR(uint8, ANFCRL_VAR) bNadPresence;                       /**< Flag to indicate NAD presence in current command-response pair. */
  VAR(uint8, ANFCRL_VAR) bNad;                               /**< NAD parameter. */
  VAR(uint8, ANFCRL_VAR) bStateNow;                          /**< Current state. */
  VAR(uint8, ANFCRL_VAR) bBlockNr;                           /**< Current block number. */
  VAR(uint8, ANFCRL_VAR) bChainingRx;                        /**< We are chaining Rx. */
  VAR(uint8, ANFCRL_VAR) bChainingTx;                        /**< We are chaining Tx. */
  VAR(uint8, ANFCRL_VAR) bOpMode;                            /**< Operating mode - ISO or NFC. */
  VAR(uint16, ANFCRL_VAR) wWtDelta;                           /**< Holds the configured delta time to be subtracted from the time in WTX timer. */
  VAR(uint8, ANFCRL_VAR) bWtPercentage;                      /**< Percentage of actual wait time to be used in WTX timer. */
  VAR(pWtxTimerCallback_t, ANFCRL_VAR) pWtxTimerCallback;         /**< Holds WTX timer call-back function address. */
  VAR(uint32, ANFCRL_VAR) dwWtxPeriod;                        /**< Frame Waiting Time Extension in microseconds */
  VAR(uint32, ANFCRL_VAR) dwWtxStart;                         /**< Starting point of WTX's timer */
  VAR(uint8, ANFCRL_VAR) bWtxTimerSts;                       /**< WTX's timer status*/
}phpalI14443p4mC_Sw_DataParams_t;

/**
 * end of group 
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phpalI14443p4mC_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4mC
* \ingroup phpalI14443p4mC
* @{
*/

/**
* \brief Initializes this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Init(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                    /**< [In] Specifies the size of the data parameter structure. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams,                         /**< [In] Pointer to the parameter structure of the underlying layer.*/
  VAR(pWtxTimerCallback_t, ANFCRL_VAR) pWtxCallback                 /**< [In] Pointer to WTX timer call-back function */
    );

/**
* \brief De-Initializes this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_DeInit(
    P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams  /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * end of group phpalI14443p4mC_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif  /* NXPBUILD__PHPAL_I14443P4MC_SW */


#ifdef NXPBUILD__PHPAL_I14443P4MC
/** \addtogroup phpalI14443p4mC ISO/IEC 14443-4mC
* \brief This component implements the PICC side of ISO/IEC 14443-4 Protocol.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalI14443p4mC/src/Sw/phpalI14443p4mC_Sw.h"

#define phpalI14443p4mC_ResetProtocol( pDataParams) \
		phpalI14443p4mC_Sw_ResetProtocol((phpalI14443p4mC_Sw_DataParams_t *)pDataParams)

#define phpalI14443p4mC_Activate( pDataParams, pRats, wRatsLength, pAts, wAtsLength) \
		phpalI14443p4mC_Sw_Activate((phpalI14443p4mC_Sw_DataParams_t *)pDataParams, pRats, wRatsLength, pAts, wAtsLength)

#define phpalI14443p4mC_SetConfig( pDataParams, wConfig, wValue) \
		phpalI14443p4mC_Sw_SetConfig((phpalI14443p4mC_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#define phpalI14443p4mC_GetConfig( pDataParams, wConfig,pValue) \
		phpalI14443p4mC_Sw_GetConfig((phpalI14443p4mC_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#define phpalI14443p4mC_Receive( pDataParams, wOption, ppRxBuffer, pRxLength) \
		phpalI14443p4mC_Sw_Receive(( phpalI14443p4mC_Sw_DataParams_t *)pDataParams,  wOption, ppRxBuffer, pRxLength)

#define phpalI14443p4mC_Transmit( pDataParams, wOption,  pTxBuffer,  wTxLength) \
		phpalI14443p4mC_Sw_Transmit((phpalI14443p4mC_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength)

#define phpalI14443p4mC_Wtx( pDataParams ) \
		phpalI14443p4mC_Sw_Wtx((phpalI14443p4mC_Sw_DataParams_t *) pDataParams)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Reset protocol parameters.
*
* Removes any state information stored in previous runs.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_ResetProtocol(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams          /**< [In] Pointer to this layer's parameter structure. */
	);

/**
* \brief Validates received RATS request and send ATS response.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* The user has to call \ref phpalI14443p4mC_Receive() once this function has
* returned with success status.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_EXT_RF_ERROR External field turned OFF.
* \retval #PH_ERR_PROTOCOL_ERROR Protocol Error, RATS is invalid.
* \retval #PH_ERR_INVALID_PARAMETER Invalid input parameter, ATS is invalid.
* \retval Other depending on implementation and underlying components.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Activate(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRats,            /**< [In] Pointer to received RATS request */
  VAR(uint8, ANFCRL_VAR) bRatsLength,       /**< [In] RATS Length*/
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts,             /**< [In] ATS to be sent */
  VAR(uint16, ANFCRL_VAR) wAtsLength        /**< [In] ATS length */
	);

/**
* \brief Perform receive operation and validate received block.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* Used to receive the next command from PCD after the Activate() is successful.
* Responses to S-block and R-Block are sent internally. Response to I-Block can
* be sent using \ref phpalI14443p4mC_Transmit.
* This function also handles PPS request sent from the reader by sending
* a PPS response. An I-Frame received from the reader is returned back to the
* user.
* Handles DESELECT by sending DESELECT response
* Starts WTx timer before returning with the valid received packet to the caller
*
*
* \c wOption can be one of:\n
* \li #PH_RECEIVE_DEFAULT
* \li #PH_RECEIVE_CHAINING
* \li #PH_RECEIVE_CHAINING_BUFSIZE
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_SUCCESS_CHAINING RX chaining incomplete.
* \retval #PH_ERR_SUCCESS_DESELECTED Card got DESELECTED.
* \retval #PH_ERR_EXT_RF_ERROR External field turned OFF.
* \retval #PH_ERR_BUFFER_OVERFLOW Buffer overflow.
* \retval Other depending on implementation and underlying components.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Receive(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wOption,           /**< [In] Option parameter. */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,      /**< [Out] Pointer to received data. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength        /**< [Out] Number of received data bytes. */
	);

/**
* \brief Transmit I-Block block
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* This function transmits an information block.
* Stops the WTx timer if it is running.
*
*
* \c wOption can be one of:\n
* \li #PH_TRANSMIT_DEFAULT
* \li #PH_TRANSMIT_BUFFER_FIRST
* \li #PH_TRANSMIT_BUFFER_CONT
* \li #PH_TRANSMIT_BUFFER_LAST
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_EXT_RF_ERROR External field turned OFF.
* \retval #PH_ERR_BUFFER_OVERFLOW buffer overflow.
* \retval Other depending on implementation and underlying components.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Transmit(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wOption,           /**< [In] Option parameter. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,        /**< [In] I-Block data to transmit. */
  VAR(uint16, ANFCRL_VAR) wTxLength         /**< [In] Length of data to transmit. */
	);

/**
* \brief Sends WTX request and receive WTX response.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
*  Wait time extension request is sent by this function and this will block
*  till it receives a response from the external reader.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Protocol Error.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Wtx(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams          /**< [In] Pointer to this layer's parameter structure */
	);

/**
* \brief Set configuration parameter.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_SetConfig(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wConfig,           /**< [In] Configuration identifier. */
  VAR(uint16, ANFCRL_VAR) wValue             /**< [In] Configuration value. */
	);

/**
* \brief Get configuration parameter.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_GetConfig(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wConfig,           /**< [In] Configuration identifier. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue            /**< [Out] Configuration value. */
	);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */
/**
 * end of group phpalI14443p4mC ISO/IEC 14443-4mC
 * @}
 */

#endif/*NXPBUILD__PHPAL_I14443P4MC */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P4MC_H */
