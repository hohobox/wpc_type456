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
*   @file    phpalI14443p3a.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3a - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3a ISO/IEC 14443-3A
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

#ifndef PHPALI14443P3A_H
#define PHPALI14443P3A_H

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
* @file           phpalI14443p3a.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3A_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3A_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3A_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3A_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3A_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3A_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3A_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3A_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3a.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3A_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3a.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3A_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3A_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3A_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3a.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW
/** \defgroup phpalProtocol Protocol Abstraction Layer
* \brief Contains Hardware-Independent implementations of various contactless protocols.
*
*/

/** \defgroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/

#define PHPAL_I14443P3A_SW_ID       0x01U    /**< ID for Software ISO14443-3A layer. */

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3A
/** \defgroup phpalI14443p3a ISO/IEC 14443-3A
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-A contactless protocol.
* @{
*/

/** Cascade Level 1 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_1     0x93U

/** Cascade Level 2 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_2     0x95U

/** Cascade Level 3 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_3     0x97U

/** Timeout after card selection in milliseconds.  */
#define PHPAL_I14443P3A_TIMEOUT_DEFAULT_MS  10U

/**
* \name Poll Command
*/
/*@{*/
#define PHPAL_I14443P3A_USE_REQA            0x00U         /**< Indicate REQA command to be used for Type A Polling*/
#define PHPAL_I14443P3A_USE_WUPA            0x01U         /**< Indicate WakeupA command to be used for Type A Polling*/
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
#define PHPAL_I14443P3A_CONFIG_OPE_MODE             0x001U

/**
 * Configure which command to be used for Type A Polling. \n
 * Possible values are\n
 *      #PHPAL_I14443P3A_USE_REQA, \n
 *      #PHPAL_I14443P3A_USE_WUPA, \n
 * Default value is #PHPAL_I14443P3A_USE_REQA.
 * */
#define PHPAL_I14443P3A_CONFIG_POLL_CMD             0x002U

/**
 * Configure timeout in microseconds. This shall be used by AL layers to set
 * timeout for commands.
 * */
#define PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US     0x003U
/*@}*/

/**
* \name VASUP-A Command
*/
/*@{*/
/* The VASUP-A command format version 1.0 Fixed size of 5 bytes excluding 2 bytes CRC
* */
#define PHPAL_I14443P3A_VASUP_VERSION_01                        0x01U

/**
* The VASUP-A command format version 2.0 Variable size, maximum 20 bytes excluding 2 bytes CRC
* */
#define PHPAL_I14443P3A_VASUP_VERSION_02                        0x02U

/**
* Minimum size for VASUP-A command frame version 1.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_01_MIN_SIZE                        5U

/**
* Maximum size for VASUP-A command frame version 1.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_01_MAX_SIZE                        7U

/**
* Minimum size for VASUP-A command frame version 2.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_02_MIN_SIZE                        6U

/**
* Maximum size for VASUP-A command frame version 2.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_02_MAX_SIZE                        22U
/*@}*/

/**
 * end of group phpalI14443p3a ISO/IEC 14443-3A
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW

/** \addtogroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/
 
 /**
 * \brief State for ActivateCard
 */
typedef enum {
    PHPAL_I14443P3A_ACTCARD_IDLE = 0,
    PHPAL_I14443P3A_ACTCARD_REQA,
    PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT,
    PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP,
} I14443P3A_ACTCARD_StateType_t;

/**
 * \brief State for AntiCollision
 */
typedef enum {
    PHPAL_I14443P3A_ANTICOLL_IDLE = 0,
    PHPAL_I14443P3A_ANTICOLL_CONFIG1,
    PHPAL_I14443P3A_ANTICOLL_CONFIG2,
	PHPAL_I14443P3A_ANTICOLL_CONFIG3,
    PHPAL_I14443P3A_ANTICOLL_SENDCMD,
	PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH,
    PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT
} I14443P3A_ANTICOLL_StateType_t;

/**
 * \brief State for RequestAEx
 */
typedef enum {
	PHPAL_I14443P3A_REQAEX_IDLE = 0,
	PHPAL_I14443P3A_REQAEX_TXRATE,
	PHPAL_I14443P3A_REQAEX_RXRATE,
	PHPAL_I14443P3A_REQAEX_TIMEOUT,
	PHPAL_I14443P3A_REQAEX_GET_CONFIG,
	PHPAL_I14443P3A_REQAEX_SET_CONFIG,
	PHPAL_I14443P3A_REQAEX_SENDCMD,
	PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME
} I14443P3A_REQAEX_StateType_t;

/**
 * \brief State for Halt A
 */
typedef enum {
	PHPAL_I14443P3A_HALTA_IDLE = 0,
	PHPAL_I14443P3A_HALTA_TIMEOUT,
	PHPAL_I14443P3A_HALTA_CONFIG,
	PHPAL_I14443P3A_HALTA_SENDCMD
} I14443P3A_HALTA_StateType_t;

/**
 * \brief State for Halt A
 */
typedef enum {
	PHPAL_I14443P3A_VASUPA_IDLE = 0,
	PHPAL_I14443P3A_VASUPA_CONFIG,
	PHPAL_I14443P3A_VASUPA_SENDCMD
} I14443P3A_VASUPA_StateType_t;

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW
/** \addtogroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/
 
/**
* \brief Software PAL-ISO14443P3A parameter structure
*/
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId;           /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams; /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) abUid[10];      /**< Array holding the activated UID. */
  VAR(uint8, ANFCRL_VAR) bUidLength;     /**< Length of UID stored in \c abUid. */
  VAR(uint8, ANFCRL_VAR) bUidComplete;   /**< Whether the UID is complete (\c 1) or not (\c 0). */
  VAR(uint8, ANFCRL_VAR) bOpeMode;       /**< Operation mode. One of NFC, EMVCo, ISO.*/
  VAR(uint8, ANFCRL_VAR) bPollCmd;       /**< Used to differentiate which command to send REQA or WakeUpA command for polling */
  VAR(I14443P3A_ACTCARD_StateType_t, ANFCRL_VAR) eActCardState;  /**< Handle state of ActivateCard function of I14443P3A. */
  VAR(I14443P3A_ANTICOLL_StateType_t, ANFCRL_VAR) eAntiCollState;  /**< Handle state of Anticollision function of I14443P3A. */
  VAR(I14443P3A_REQAEX_StateType_t, ANFCRL_VAR) eReqAExState;    /**< Handle state of RequestAEx function of I14443P3A. */
  VAR(I14443P3A_HALTA_StateType_t, ANFCRL_VAR) eHaltAState;    /**< Handle state of HaltA function of I14443P3A. */
  VAR(I14443P3A_VASUPA_StateType_t, ANFCRL_VAR) eVASUpAState;    /**< Handle state of VASUpA function of I14443P3A. */
} phpalI14443p3a_Sw_DataParams_t;

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/
 
/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Sw_Init(
                P2VAR(phpalI14443p3a_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                   /**< [In] Specifies the size of the data parameter structure. */
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                         /**< [In] Pointer to the parameter structure of the underlying layer. */
								);

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3A

/** \addtogroup phpalI14443p3a ISO/IEC 14443-3A
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-A contactless protocol.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phpalI14443p3a/src/Sw/phpalI14443p3a_Sw.h"

#define phpalI14443p3a_SetConfig( pDataParams, wConfig, wValue) \
        phpalI14443p3a_Sw_SetConfig((phpalI14443p3a_Sw_DataParams_t *) pDataParams, wConfig, wValue)

#define phpalI14443p3a_GetConfig( pDataParams, wConfig, pValue) \
        phpalI14443p3a_Sw_GetConfig((phpalI14443p3a_Sw_DataParams_t *) pDataParams, wConfig, pValue)

#define phpalI14443p3a_RequestA(  pDataParams,   pAtqa )\
        phpalI14443p3a_Sw_RequestA((phpalI14443p3a_Sw_DataParams_t *)pDataParams, pAtqa)

#define phpalI14443p3a_WakeUpA( pDataParams, pAtqa)\
        phpalI14443p3a_Sw_WakeUpA((phpalI14443p3a_Sw_DataParams_t *)pDataParams, pAtqa)

#define phpalI14443p3a_HaltA( pDataParams) \
        phpalI14443p3a_Sw_HaltA((phpalI14443p3a_Sw_DataParams_t *)pDataParams)

#define phpalI14443p3a_Anticollision(pDataParams, bCascadeLevel,  pUidIn, bNvbUidIn, pUidOut, pNvbUidOut) \
        phpalI14443p3a_Sw_Anticollision((phpalI14443p3a_Sw_DataParams_t *)pDataParams, bCascadeLevel, pUidIn, bNvbUidIn, pUidOut, pNvbUidOut)

#define phpalI14443p3a_Select( pDataParams, bCascadeLevel, pUidIn, pSak) \
        phpalI14443p3a_Sw_Select((phpalI14443p3a_Sw_DataParams_t *)pDataParams, bCascadeLevel, pUidIn, pSak)

#define phpalI14443p3a_ActivateCard( pDataParams, pUidIn, bLenUidIn, pUidOut, pLenUidOut, pSak, pMoreCardsAvailable) \
        phpalI14443p3a_Sw_ActivateCard((phpalI14443p3a_Sw_DataParams_t *)pDataParams, pUidIn, bLenUidIn, pUidOut, pLenUidOut, pSak, pMoreCardsAvailable)

#define phpalI14443p3a_Exchange( pDataParams, wOption,  pTxBuffer, wTxLength,  ppRxBuffer,  pRxLength) \
        phpalI14443p3a_Sw_Exchange((phpalI14443p3a_Sw_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phpalI14443p3a_GetSerialNo( pDataParams, pUidOut, pLenUidOut) \
        phpalI14443p3a_Sw_GetSerialNo((phpalI14443p3a_Sw_DataParams_t *)pDataParams, pUidOut, pLenUidOut)

#define phpalI14443p3a_VASUpA( pDataParams, bFormatByte, pCmdBytes, bLenCmdBytes, pAtqa) \
		phpalI14443p3a_Sw_VASUpA((phpalI14443p3a_Sw_DataParams_t *)pDataParams, bFormatByte, pCmdBytes, bLenCmdBytes, pAtqa)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_SetConfig(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Configuration Identifier. */
                  VAR(uint16, ANFCRL_VAR) wValue      /**< [In] Configuration Value. */
									);

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_GetConfig(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Configuration Identifier. */
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue      /**<[Out] Configuration Value. */
									);

/**
* \brief Perform a ISO14443-3A Request command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b Note: The "Request Guard Time" <em>(see 6.2.2, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_RequestA(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa      /**< [Out] AtqA; uint8[2]. */
									);

/**
* \brief Perform a ISO14443-3A Wakeup command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b Note: The "Request Guard Time" <em>(see 6.2.2, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_WakeUpA(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa       /**< [Out] AtqA; uint8[2]. */
								);

/**
* \brief Perform a ISO14443-3A Halt command.
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
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_HaltA(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams  /**< [In] Pointer to this layer's parameter structure. */
								);

/**
* \brief Perform a ISO14443-3A Anticollision or Select command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* bNvbUidIn != 0x40: Perform Anticollision command.\n
* bNvbUidIn = 0x40: Perform Select command.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR Bcc invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Anticollision(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
                    VAR(uint8, ANFCRL_VAR) bCascadeLevel,  /**< [In] cascade level code.  */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,       /**< [In] known Uid, can be NULL; uint8[0-4]. */
                    VAR(uint8, ANFCRL_VAR) bNvbUidIn,      /**< [In] number of valid bits of UidIn. MSB codes the valid bytes, LSB codes the valid bits.  */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,      /**< [Out] complete Uid; uint8[4]. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNvbUidOut    /**< [Out] number of valid bits of UidOut. MSB codes the valid bytes, LSB codes the valid bits.  */
										);

/**
* \brief Perform a ISO14443-3A Select command.
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
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Select(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                  VAR(uint8, ANFCRL_VAR) bCascadeLevel, /**< [In] cascade level code. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,      /**< [In] Uid; uint8[4]. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak         /**< [Out] Select Acknowledge; uint8. */
									);

/**
* \brief Perform ISO14443-3A ReqA or WupA and Anticollision/Select commands for all cascade levels.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* If bLenUidIn is '0' --> CardUid not given, a ReqA is performed.
* If CardUid is given, a WupA is performed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR Bcc invalid.
* \retval #PH_ERR_LENGTH_ERROR Given \c pUidIn is not complete.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_ActivateCard(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn,                /**< [In] known Uid, can be NULL if bLenUidIn is 0; uint8[4/7/10]. */
                    VAR(uint8, ANFCRL_VAR) bLenUidIn,               /**< [In] Length of known Uid; 0/4/7/10. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,               /**< [Out] complete Uid; uint8[10]. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut,            /**< [Out] Length of Uid; 4/7/10. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak,                  /**< [Out] Select Acknowledge; uint8. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable    /**< [Out] Whether there are more cards in the field or not; uint8. */
										);

/**
* \brief Perform ISO14443-3A Data Exchange with Picc.
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
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_Exchange(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layer's parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] Option parameter. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,      /**< [In] Data to transmit. */
                  VAR(uint16, ANFCRL_VAR) wTxLength,       /**< [In] Length of data to transmit. */
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] Pointer to received data. */
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength      /**< [Out] number of received data bytes. */
									);

/**
* \brief Retrieve the serial number.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION No Serial number available at the moment.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_GetSerialNo(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut,    /**< [Out] Last Uid; uint8[10]. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut  /**< [Out] Length of Uid; 4/7/10. */
									);

/**
* \brief Perform a ISO14443-3A VAS wake UP.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
* This is used to support Enhanced Contactless Polling by including the VASUP-A command in the Discovery Loop.
*
* \b bFormatByte can be either '01' or '02'. Other values are RFU.\n
* \b pCmdBytes except the Command and Format Byte.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval #PH_ERR_UNSUPPORTED_COMMAND VAS polling not supported in ISO mode.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3a_VASUpA(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layer's parameter structure. */
                VAR(uint8, ANFCRL_VAR) bFormatByte,  /**< [In] Format Byte of VASUP-A command. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes,  /**< [In] Pointer to an array with the rest of the VASUP-A Command bytes. */
                VAR(uint8, ANFCRL_VAR) bLenCmdBytes,  /**< [In] Length of VASUP-A Command bytes */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa      /**< [Out] RFU. */
								);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phpalI14443p3a ISO/IEC 14443-3A
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P3A */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3A_H */
