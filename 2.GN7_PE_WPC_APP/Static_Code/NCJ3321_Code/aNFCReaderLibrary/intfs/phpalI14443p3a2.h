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
*   @file    phpalI14443p3a2.h
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

#ifndef PHPALI14443P3A2_H
#define PHPALI14443P3A2_H

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
* @file           phpalI14443p3a2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3A_VENDOR_ID2                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3A_MODULE_ID2                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3A_AR_RELEASE_REVISION_VERSION2  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3A_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3A_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3A_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3A_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3a2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3A_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3a2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3A_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3A_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3A_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3a2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
/** \defgroup phpalProtocol Protocol Abstraction Layer
* \brief Contains Hardware-Independent implementations of various contactless protocols.
*
*/

/** \defgroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/

#define PHPAL_I14443P3A_SW_ID2       0x01U    /**< ID for Software ISO14443-3A layer. */

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3A2
/** \defgroup phpalI14443p3a ISO/IEC 14443-3A
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-A contactless protocol.
* @{
*/

/** Cascade Level 1 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_12     0x93U

/** Cascade Level 2 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_22     0x95U

/** Cascade Level 3 code for ISO14443-3A anticollision/select command. */
#define PHPAL_I14443P3A_CASCADE_LEVEL_32     0x97U

/** Timeout after card selection in milliseconds.  */
#define PHPAL_I14443P3A_TIMEOUT_DEFAULT_MS2  10U

/**
* \name Poll Command
*/
/*@{*/
#define PHPAL_I14443P3A_USE_REQA2            0x00U         /**< Indicate REQA command to be used for Type A Polling*/
#define PHPAL_I14443P3A_USE_WUPA2            0x01U         /**< Indicate WakeupA command to be used for Type A Polling*/
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
#define PHPAL_I14443P3A_CONFIG_OPE_MODE2             0x001U

/**
 * Configure which command to be used for Type A Polling. \n
 * Possible values are\n
 *      #PHPAL_I14443P3A_USE_REQA2, \n
 *      #PHPAL_I14443P3A_USE_WUPA2, \n
 * Default value is #PHPAL_I14443P3A_USE_REQA2.
 * */
#define PHPAL_I14443P3A_CONFIG_POLL_CMD2             0x002U

/**
 * Configure timeout in microseconds. This shall be used by AL layers to set
 * timeout for commands.
 * */
#define PHPAL_I14443P3A_CONFIG_TIMEOUT_VALUE_US2     0x003U
/*@}*/

/**
* \name VASUP-A Command
*/
/*@{*/
/* The VASUP-A command format version 1.0 Fixed size of 5 bytes excluding 2 bytes CRC
* */
#define PHPAL_I14443P3A_VASUP_VERSION_012                        0x01U

/**
* The VASUP-A command format version 2.0 Variable size, maximum 20 bytes excluding 2 bytes CRC
* */
#define PHPAL_I14443P3A_VASUP_VERSION_022                        0x02U

/**
* Minimum size for VASUP-A command frame version 1.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_01_MIN_SIZE2                        5U

/**
* Maximum size for VASUP-A command frame version 1.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_01_MAX_SIZE2                        7U

/**
* Minimum size for VASUP-A command frame version 2.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_02_MIN_SIZE2                        6U

/**
* Maximum size for VASUP-A command frame version 2.0
* */
#define PHPAL_I14443P3A_VASUP_VERSION_02_MAX_SIZE2                        22U
/*@}*/

/**
 * end of group phpalI14443p3a ISO/IEC 14443-3A
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A2 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2

/** \addtogroup phpalI14443p3a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-3 Type A
* \ingroup phpalI14443p3a
* @{
*/
 
 /**
 * \brief State for ActivateCard
 */
typedef enum {
    PHPAL_I14443P3A_ACTCARD_IDLE2 = 0,
    PHPAL_I14443P3A_ACTCARD_REQA2,
    PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP_INIT2,
    PHPAL_I14443P3A_ACTCARD_ANTICOLLISION_LOOP2,
} I14443P3A_ACTCARD_StateType_t2;

/**
 * \brief State for AntiCollision
 */
typedef enum {
    PHPAL_I14443P3A_ANTICOLL_IDLE2 = 0,
    PHPAL_I14443P3A_ANTICOLL_CONFIG12,
    PHPAL_I14443P3A_ANTICOLL_CONFIG22,
	PHPAL_I14443P3A_ANTICOLL_CONFIG32,
    PHPAL_I14443P3A_ANTICOLL_SENDCMD2,
	PHPAL_I14443P3A_ANTICOLL_EXCHANGE_FINISH2,
    PHPAL_I14443P3A_ANTICOLL_SET_DEFAULT_CARD_TIMEOUT2
} I14443P3A_ANTICOLL_StateType_t2;

/**
 * \brief State for RequestAEx
 */
typedef enum {
	PHPAL_I14443P3A_REQAEX_IDLE2 = 0,
	PHPAL_I14443P3A_REQAEX_TXRATE2,
	PHPAL_I14443P3A_REQAEX_RXRATE2,
	PHPAL_I14443P3A_REQAEX_TIMEOUT2,
	PHPAL_I14443P3A_REQAEX_GET_CONFIG2,
	PHPAL_I14443P3A_REQAEX_SET_CONFIG2,
	PHPAL_I14443P3A_REQAEX_SENDCMD2,
	PHPAL_I14443P3A_REQAEX_RESTORE_RXWAITTIME2
} I14443P3A_REQAEX_StateType_t2;

/**
 * \brief State for Halt A
 */
typedef enum {
	PHPAL_I14443P3A_HALTA_IDLE2 = 0,
	PHPAL_I14443P3A_HALTA_TIMEOUT2,
	PHPAL_I14443P3A_HALTA_CONFIG2,
	PHPAL_I14443P3A_HALTA_SENDCMD2
} I14443P3A_HALTA_StateType_t2;

/**
 * \brief State for Halt A
 */
typedef enum {
	PHPAL_I14443P3A_VASUPA_IDLE2 = 0,
	PHPAL_I14443P3A_VASUPA_CONFIG2,
	PHPAL_I14443P3A_VASUPA_SENDCMD2
} I14443P3A_VASUPA_StateType_t2;

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
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
  VAR(uint16, ANFCRL_VAR) wId2;           /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2; /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) abUid2[10];      /**< Array holding the activated UID. */
  VAR(uint8, ANFCRL_VAR) bUidLength2;     /**< Length of UID stored in \c abUid2. */
  VAR(uint8, ANFCRL_VAR) bUidComplete2;   /**< Whether the UID is complete (\c 1) or not (\c 0). */
  VAR(uint8, ANFCRL_VAR) bOpeMode2;       /**< Operation mode. One of NFC, EMVCo, ISO.*/
  VAR(uint8, ANFCRL_VAR) bPollCmd2;       /**< Used to differentiate which command to send REQA or WakeUpA command for polling */
  VAR(I14443P3A_ACTCARD_StateType_t2, ANFCRL_VAR) eActCardState2;  /**< Handle state of ActivateCard function of I14443P3A. */
  VAR(I14443P3A_ANTICOLL_StateType_t2, ANFCRL_VAR) eAntiCollState2;  /**< Handle state of Anticollision function of I14443P3A. */
  VAR(I14443P3A_REQAEX_StateType_t2, ANFCRL_VAR) eReqAExState2;    /**< Handle state of RequestAEx function of I14443P3A. */
  VAR(I14443P3A_HALTA_StateType_t2, ANFCRL_VAR) eHaltAState2;    /**< Handle state of HaltA function of I14443P3A. */
  VAR(I14443P3A_VASUPA_StateType_t2, ANFCRL_VAR) eVASUpAState2;    /**< Handle state of VASUpA function of I14443P3A. */
} phpalI14443p3a_Sw_DataParams_t2;

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2 == 0))
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
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Sw_Init2(
                P2VAR(phpalI14443p3a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,                   /**< [In] Specifies the size of the data parameter structure. */
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2                         /**< [In] Pointer to the parameter structure of the underlying layer. */
								);

/**
 * end of group phpalI14443p3a_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3A2

/** \addtogroup phpalI14443p3a ISO/IEC 14443-3A
* \ingroup phpalProtocol
* \brief These Components implement the ISO/IEC 14443-3 Type-A contactless protocol.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phpalI14443p3a/src/Sw/phpalI14443p3a_Sw2.h"

#define phpalI14443p3a_SetConfig2( pDataParams2, wConfig2, wValue2) \
        phpalI14443p3a_Sw_SetConfig2((phpalI14443p3a_Sw_DataParams_t2 *) pDataParams2, wConfig2, wValue2)

#define phpalI14443p3a_GetConfig2( pDataParams2, wConfig2, pValue2) \
        phpalI14443p3a_Sw_GetConfig2((phpalI14443p3a_Sw_DataParams_t2 *) pDataParams2, wConfig2, pValue2)

#define phpalI14443p3a_RequestA2(  pDataParams2,   pAtqa2 )\
        phpalI14443p3a_Sw_RequestA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pAtqa2)

#define phpalI14443p3a_WakeUpA2( pDataParams2, pAtqa2)\
        phpalI14443p3a_Sw_WakeUpA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pAtqa2)

#define phpalI14443p3a_HaltA2( pDataParams2) \
        phpalI14443p3a_Sw_HaltA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2)

#define phpalI14443p3a_Anticollision2(pDataParams2, bCascadeLevel2,  pUidIn2, bNvbUidIn2, pUidOut2, pNvbUidOut2) \
        phpalI14443p3a_Sw_Anticollision2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bCascadeLevel2, pUidIn2, bNvbUidIn2, pUidOut2, pNvbUidOut2)

#define phpalI14443p3a_Select2( pDataParams2, bCascadeLevel2, pUidIn2, pSak2) \
        phpalI14443p3a_Sw_Select2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bCascadeLevel2, pUidIn2, pSak2)

#define phpalI14443p3a_ActivateCard2( pDataParams2, pUidIn2, bLenUidIn2, pUidOut2, pLenUidOut2, pSak2, pMoreCardsAvailable2) \
        phpalI14443p3a_Sw_ActivateCard2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pUidIn2, bLenUidIn2, pUidOut2, pLenUidOut2, pSak2, pMoreCardsAvailable2)

#define phpalI14443p3a_Exchange2( pDataParams2, wOption2,  pTxBuffer2, wTxLength2,  ppRxBuffer2,  pRxLength2) \
        phpalI14443p3a_Sw_Exchange2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2)

#define phpalI14443p3a_GetSerialNo2( pDataParams2, pUidOut2, pLenUidOut2) \
        phpalI14443p3a_Sw_GetSerialNo2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, pUidOut2, pLenUidOut2)

#define phpalI14443p3a_VASUpA2( pDataParams2, bFormatByte2, pCmdBytes2, bLenCmdBytes2, pAtqa2) \
		phpalI14443p3a_Sw_VASUpA2((phpalI14443p3a_Sw_DataParams_t2 *)pDataParams2, bFormatByte2, pCmdBytes2, bLenCmdBytes2, pAtqa2)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_SetConfig2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Configuration Identifier. */
                  VAR(uint16, ANFCRL_VAR) wValue2      /**< [In] Configuration Value. */
									);

/**
* \brief Get configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_GetConfig2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Configuration Identifier. */
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2      /**<[Out] Configuration Value. */
									);

/**
* \brief Perform a ISO14443-3A Request command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b Note: The "Request Guard Time" <em>(see 6.2.2, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_RequestA2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layer's parameter structure. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2      /**< [Out] AtqA; uint8[2]. */
									);

/**
* \brief Perform a ISO14443-3A Wakeup command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b Note: The "Request Guard Time" <em>(see 6.2.2, ISO/IEC 14443-3:2009(E))</em> is mandatory and is
* neither implemented here nor implemented in every \ref phhalHw layer.\n
* Make sure that either the used HAL or the used application does comply to this rule.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_WakeUpA2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2       /**< [Out] AtqA; uint8[2]. */
								);

/**
* \brief Perform a ISO14443-3A Halt command.
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
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_HaltA2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2  /**< [In] Pointer to this layer's parameter structure. */
								);

/**
* \brief Perform a ISO14443-3A Anticollision or Select command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* bNvbUidIn2 != 0x40: Perform Anticollision command.\n
* bNvbUidIn2 = 0x40: Perform Select command.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR2 Bcc invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Anticollision2(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,     /**< [In] Pointer to this layer's parameter structure. */
                    VAR(uint8, ANFCRL_VAR) bCascadeLevel2,  /**< [In] cascade level code.  */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,       /**< [In] known Uid, can be NULL; uint8[0-4]. */
                    VAR(uint8, ANFCRL_VAR) bNvbUidIn2,      /**< [In] number of valid bits of UidIn. MSB codes the valid bytes, LSB codes the valid bits.  */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,      /**< [Out] complete Uid; uint8[4]. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNvbUidOut2    /**< [Out] number of valid bits of UidOut. MSB codes the valid bytes, LSB codes the valid bits.  */
										);

/**
* \brief Perform a ISO14443-3A Select command.
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
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Select2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layer's parameter structure. */
                  VAR(uint8, ANFCRL_VAR) bCascadeLevel2, /**< [In] cascade level code. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,      /**< [In] Uid; uint8[4]. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2         /**< [Out] Select Acknowledge; uint8. */
									);

/**
* \brief Perform ISO14443-3A ReqA or WupA and Anticollision/Select commands for all cascade levels.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* If bLenUidIn2 is '0' --> CardUid not given, a ReqA is performed.
* If CardUid is given, a WupA is performed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR2 Bcc invalid.
* \retval #PH_ERR_LENGTH_ERROR2 Given \c pUidIn2 is not complete.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_ActivateCard2(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,              /**< [In] Pointer to this layer's parameter structure. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidIn2,                /**< [In] known Uid, can be NULL if bLenUidIn2 is 0; uint8[4/7/10]. */
                    VAR(uint8, ANFCRL_VAR) bLenUidIn2,               /**< [In] Length of known Uid; 0/4/7/10. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,               /**< [Out] complete Uid; uint8[10]. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2,            /**< [Out] Length of Uid; 4/7/10. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSak2,                  /**< [Out] Select Acknowledge; uint8. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2    /**< [Out] Whether there are more cards in the field or not; uint8. */
										);

/**
* \brief Perform ISO14443-3A Data Exchange with Picc.
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
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_Exchange2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,       /**< [In] Pointer to this layer's parameter structure. */
                  VAR(uint16, ANFCRL_VAR) wOption2,         /**< [In] Option parameter. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,      /**< [In] Data to transmit. */
                  VAR(uint16, ANFCRL_VAR) wTxLength2,       /**< [In] Length of data to transmit. */
                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,    /**< [Out] Pointer to received data. */
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2      /**< [Out] number of received data bytes. */
									);

/**
* \brief Retrieve the serial number.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_USE_CONDITION No Serial number available at the moment.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_GetSerialNo2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidOut2,    /**< [Out] Last Uid; uint8[10]. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenUidOut2  /**< [Out] Length of Uid; 4/7/10. */
									);

/**
* \brief Perform a ISO14443-3A VAS wake UP.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
* This is used to support Enhanced Contactless Polling by including the VASUP-A command in the Discovery Loop.
*
* \b bFormatByte2 can be either '01' or '02'. Other values are RFU.\n
* \b pCmdBytes2 except the Command and Format Byte.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_UNSUPPORTED_COMMAND VAS polling not supported in ISO mode.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3a_VASUpA2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layer's parameter structure. */
                VAR(uint8, ANFCRL_VAR) bFormatByte2,  /**< [In] Format Byte of VASUP-A command. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes2,  /**< [In] Pointer to an array with the rest of the VASUP-A Command bytes. */
                VAR(uint8, ANFCRL_VAR) bLenCmdBytes2,  /**< [In] Length of VASUP-A Command bytes */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqa2      /**< [Out] RFU. */
								);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3A_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalI14443p3a ISO/IEC 14443-3A
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P3A2 */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3A2_H */
