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
*   @file    phpalI14443p4a.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4a - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4a ISO/IEC 14443-4A
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
#ifndef PHPALI14443P4A_H
#define PHPALI14443P4A_H

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
* @file           phpalI14443p4a.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4A_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4A_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4A_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4A_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4A_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4A_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4A_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4A_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4a.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4A_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4a.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4A_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4A_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4A_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4a.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components configure PHPAL_I14443P4A
* @{
*/

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

#define PHPAL_I14443P4A_CONFIG_OPE_MODE         0x01U

/**
 * Configure retry count for RATS command.\n
 * Possible values are\n
 *      #PHPAL_I14443P4A_RATS_RETRY_MIN, \n
 *      #PHPAL_I14443P4A_RATS_RETRY_MAX, \n
 *
 * Default value is #PHPAL_I14443P4A_RATS_RETRY_MAX.\n
 *
 * For mode #RD_LIB_MODE_EMVCO retry count should be 1.
 * */
#define PHPAL_I14443P4A_CONFIG_RATS_RETRY_COUNT 0x02U

/*@}*/

/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */

/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/
#define PHPAL_I14443P4A_SW_ID   0x01U    /**< ID for Software ISO14443-4A layer     */
/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */


#ifdef NXPBUILD__PHPAL_I14443P4A
/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components implement the additional ISO/IEC 14443-4 activation steps
* needed for ISO14443 Type-A cards.
* @{
*/

/**
* \name FSDI/FSCI Values
*/
/*@{*/
#define PHPAL_I14443P4A_NFC_FRAMESIZE_MAX 8U   /**< Maximum allowed FSDI/FSCI value as per NFC Forum Spec. */
/*@}*/

/**
* \name DRI/DSI Values
*/
/*@{*/
#define PHPAL_I14443P4A_DATARATE_106    0x00U   /**< DRI/DSI value for 106 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_212    0x01U   /**< DRI/DSI value for 212 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_424    0x02U   /**< DRI/DSI value for 424 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_848    0x03U   /**< DRI/DSI value for 848 kBit/s. */
/*@}*/

/**
* \name RATS Command Retry Values
*/
/*@{*/
#define PHPAL_I14443P4A_RATS_RETRY_MAX    1U   /**< Maximum retry value of RATS during transmission and timeout error.*/
#define PHPAL_I14443P4A_RATS_RETRY_MIN    0U   /**< Minimum retry value of RATS during transmission and timeout error.*/
/*@}*/

#ifdef NXPRDLIB_REM_GEN_INTFS

#define phpalI14443p4a_Rats( pDataParams,  bFsdi, bCid, pAts) \
        phpalI14443p4a_Sw_Rats((phpalI14443p4a_Sw_DataParams_t *)pDataParams, bFsdi, bCid, pAts)

#define phpalI14443p4a_Pps( pDataParams,  bDri, bDsi ) \
        phpalI14443p4a_Sw_Pps((phpalI14443p4a_Sw_DataParams_t *)pDataParams, bDri, bDsi)

#define phpalI14443p4a_ActivateCard( pDataParams, bFsdi, bCid,bDri, bDsi, pAts) \
        phpalI14443p4a_Sw_ActivateCard((phpalI14443p4a_Sw_DataParams_t *)pDataParams, bFsdi, bCid, bDri, bDsi, pAts)

#define phpalI14443p4a_GetProtocolParams( pDataParams,  pCidEnabled, pCid, pNadSupported,  pFwi,  pFsdi, pFsci ) \
        phpalI14443p4a_Sw_GetProtocolParams((phpalI14443p4a_Sw_DataParams_t *)pDataParams, pCidEnabled, pCid, pNadSupported, pFwi, pFsdi, pFsci)

#define phpalI14443p4a_SetConfig(pDataParams, wConfig,wValue) phpalI14443p4a_Sw_SetConfig((phpalI14443p4a_Sw_DataParams_t *)pDataParams, wConfig,wValue)

#endif /* NXPRDLIB_REM_GEN_INTFS */
/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
 * \brief State for ActivateCard
 */
typedef enum {
  PHPAL_I14443P4A_ACTCARD_IDLE = 0,
  PHPAL_I14443P4A_ACTCARD_RATS,
  PHPAL_I14443P4A_ACTCARD_PPS
} I14443P4A_ACTCARD_StateType_t;

/**
 * \brief State for Rats
 */
typedef enum {
  PHPAL_I14443P4A_RATS_IDLE = 0,
  PHPAL_I14443P4A_RATS_WAIT,
  PHPAL_I14443P4A_RATS_HALT,
  PHPAL_I14443P4A_RATS_SEND,
  PHPAL_I14443P4A_RATS_FWTCONFIG,
  PHPAL_I14443P4A_RATS_DESELSEND,
  PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT,
  PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT,
  PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS,
  PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US
} I14443P4A_RATS_StateType_t;

/**
 * \brief State for Pps
 */
typedef enum {
  PHPAL_I14443P4A_PPS_IDLE = 0,
  PHPAL_I14443P4A_PPS_EXCHANGE,
  PHPAL_I14443P4A_PPS_TXDATARATE,
  PHPAL_I14443P4A_PPS_RXDATARATE
} I14443P4A_PPS_StateType_t;

/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
* \brief Software PAL-ISO14443P4A parameter structure
 */
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId; /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams; /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) bCidSupported; /**< Cid Support indicator; Unequal '0' if supported. */
  VAR(uint8, ANFCRL_VAR) bNadSupported; /**< Nad Support indicator; Unequal '0' if supported. */
  VAR(uint8, ANFCRL_VAR) bCid; /**< Card Identifier; Ignored if bCidSupported is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bBitRateCaps; /**< TA(1) byte of ATS; ISO/IEC 14443-4:2008, Section 5.2.4. */
  VAR(uint8, ANFCRL_VAR) bFwi; /**< Frame Waiting Integer. */
  VAR(uint8, ANFCRL_VAR) bFsci; /**< PICC Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bFsdi; /**< (Current) PCD Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bDri; /**< (Current) Divisor Receive (PCD to PICC) Integer; 0-3; */
  VAR(uint8, ANFCRL_VAR) bDsi; /**< (Current) Divisor Send (PICC to PCD) Integer; 0-3; */
  VAR(uint8, ANFCRL_VAR) bOpeMode; /**< Operation mode. One of NFC, EMVCo, ISO.*/
  VAR(uint8, ANFCRL_VAR) bRetryCount; /**< Retry count for RATS command as per NFC Digital Protocol Version 1.1\n
	 For mode #RD_LIB_MODE_EMVCO retry count should be 1. */
	/* State variables for Non-Blocking */
  VAR(I14443P4A_ACTCARD_StateType_t, ANFCRL_VAR) eActCardState; /**< Handle state of ActivateCard function of I14443P4A. */
  VAR(I14443P4A_RATS_StateType_t, ANFCRL_VAR) eRatsState; /**< Handle state of Rats function of I14443P4A. */
  VAR(I14443P4A_PPS_StateType_t, ANFCRL_VAR) ePpsState; /**< Handle state of Pps function of I14443P4A. */
} phpalI14443p4a_Sw_DataParams_t;

/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Sw_Init(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                   /**< [In] Specifies the size of the data parameter structure. */
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                         /**< [In] Pointer to the parameter structure of the underlying layer.*/
                                  );
/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

#ifdef NXPBUILD__PHPAL_I14443P4A

/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components implement the additional ISO/IEC 14443-4 activation steps
* needed for ISO14443 Type-A cards.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw.h"
#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
/**
* \brief Perform a ISO14443-4A "Request Answer to Select" command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
\verbatim
[FSDI to FSD conversion]
---------------------------------------------------------------
FSDI         | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07  | 08  |
---------------------------------------------------------------
FSD (bytes)  | 16 | 24 | 32 | 40 | 48 | 64 | 96 | 128 | 256 |
---------------------------------------------------------------
\endverbatim
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Rats(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint8, ANFCRL_VAR) bFsdi,       /**< [In] Frame Size Integer; 0-8. */
                               VAR(uint8, ANFCRL_VAR) bCid,        /**< [In] Card Identifier; 0-14. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts       /**< [Out] Answer to Select; uint8[255]. */
                               );

/**
* \brief Perform a ISO14443-4A "Protocol and Parameter Selection" command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* The following values for \c bDri and \c bDsi are possible:\n
* \li #PHPAL_I14443P4A_DATARATE_106
* \li #PHPAL_I14443P4A_DATARATE_212
* \li #PHPAL_I14443P4A_DATARATE_424
* \li #PHPAL_I14443P4A_DATARATE_848
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_Pps(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                              VAR(uint8, ANFCRL_VAR) bDri,         /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                              VAR(uint8, ANFCRL_VAR) bDsi          /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                              );

/**
* \brief Perform ISO14443-4A Rats and Pps commands.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR Bcc invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_ActivateCard(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                       VAR(uint8, ANFCRL_VAR) bFsdi,       /**< [In] Frame Size Integer; 0-8. */
                                       VAR(uint8, ANFCRL_VAR) bCid,        /**< [In] Card Identifier; 0-14. */
                                       VAR(uint8, ANFCRL_VAR) bDri,        /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                       VAR(uint8, ANFCRL_VAR) bDsi,        /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts       /**< [Out] Answer to Select; uint8[255]. */
                                       );

/**
* \brief Retrieve the ISO14443-4A protocol parameters.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_GetProtocolParams(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled,      /**< [Out] Unequal '0' if Card Identifier is enabled. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid,             /**< [Out] Card Identifier. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported,    /**< [Out] Node Address Support; Unequal '0' if supported. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi,             /**< [Out] Frame Waiting Integer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi,            /**< [Out] PCD Frame Size Integer; 0-8. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci             /**< [Out] PICC Frame Size Integer; 0-8. */
    );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4a_SetConfig(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig,   /**< [In] Configuration Identifier. */
                                    VAR(uint16, ANFCRL_VAR) wValue     /**< [In] Configuration Value. */
                                   );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P4A */

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4A_H */
