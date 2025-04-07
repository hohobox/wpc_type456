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
*   @file    phacDiscLoop_Sw2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop Discovery Loop
*   @ingroup phac
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

/** \file
* This File contains all functions that's needed by Discovery Loop
* for Starting the discovery loop, Set & Get Configuration and Card Activation.
*/

#ifndef PHACDISCLOOP_SW2_H
#define PHACDISCLOOP_SW2_H

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
#include <phNxpNfcRdLib_Config2.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file phacDiscLoop_Sw2.h and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phacDiscLoop_Sw2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file phacDiscLoop_Sw2.h and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHACDISCLOOP_SW_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHACDISCLOOP_SW_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHACDISCLOOP_SW_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHACDISCLOOP_SW_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#define PHAC_DISCLOOP_SW_TYPEF_MAX_TSN2                          16U    /**< Maximum time slot number for Type F. */
#define PHAC_DISCLOOP_SW_I3P4_MAX_CID2                           14U    /**< Maximum permissible size of CID(Card IDentifier). */
#define PHAC_DISCLOOP_SW_I3P4_MAX_DSI2                            3U    /**< Maximum permissible size of DSI(Divisor Send Integer). */
#define PHAC_DISCLOOP_SW_I3P4_MAX_DRI2                            3U    /**< Maximum permissible size of DRI(Divisor Receive Integer). */

/* Default device limit for poll technologies */
#define PHAC_DISCLOOP_TYPEA_DEFAULT_DEVICE_LIMIT2              0x01U    /**< The default value loaded for device limit for Type A tags. */
#define PHAC_DISCLOOP_TYPEB_DEFAULT_DEVICE_LIMIT2              0x01U    /**< Default value for maximum number of TypeB tags that can be detected. */
#define PHAC_DISCLOOP_TYPEF_DEFAULT_DEVICE_LIMIT2              0x01U    /**< Default value for maximum number of TypeF tags that can be detected. */
#define PHAC_DISCLOOP_TYPEV_DEFAULT_DEVICE_LIMIT2              0x01U    /**< Default value loaded for device limit for Type V tags is equal to #PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED. */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/**
 * \brief Function to start the discovery loop
 *
 * \return Error code
 * \retval #PH_ERR_SUCCESS2
 * \retval Other errors depends on component.
 *         For more info about various components present refer
 *         NFCReaderlibrary.chm,
 *         "Component identifiers" under the section "Generic Definitions".
 *         For info about Error Codes Refer "Error Code Collection"
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Run2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,            /**< [In] pointer to this layer's parameter structure. */
  VAR(phacDiscLoop_Sw_EntryPoints_t2, ANFCRL_VAR) bEntryPoint2                                    /**< [In] Entry point to start Discovery Loop. */
    );

/**
 * \brief   Function to Get the configuration value
 *
 * \return  Error code
 *
 * \retval #PH_ERR_SUCCESS2         operation successful
 * \retval #PH_ERR_PROTOCOL_ERROR2  Invalid option/response received
 * \retval Other errors depends on component.
 *         For more info about various components present refer
 *         NFCReaderlibrary.chm,
 *         "Component identifiers" under the section "Generic Definitions".
 *         For info about Error Codes Refer "Error Code Collection"
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_GetConfig2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,           /**< [In] Pointer to this layer's parameter structure */
    VAR(uint16, ANFCRL_VAR) wConfig2,                                      /**< [In] Configuration identifier */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2                                       /**< [Out] Configuration value */
    );

/**
 * \brief Function to Set the configuration value
 *
 * \return Error code
 * \retval #PH_ERR_SUCCESS2            operation successful
 * \retval #PH_ERR_INVALID_PARAMETER2  Invalid option/response received
 * \retval Other errors depends on component.
 *         For more info about various components present refer
 *         NFCReaderlibrary.chm,
 *         "Component identifiers" under the section "Generic Definitions".
 *         For info about Error Codes Refer "Error Code Collection"
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_SetConfig2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,           /**< [In] Pointer to this layer's parameter structure */
    VAR(uint16, ANFCRL_VAR) wConfig2,                                      /**< [In] Configuration identifier */
    VAR(uint16, ANFCRL_VAR) wValue2                                        /**< [In] Configuration value */
    );

/**
 * \brief Activates the given tag type with given index
 *
 * \return Error code
 * \retval #PH_ERR_SUCCESS2      On success
 * \retval #PH_ERR_INVALID_PARAMETER2  If invalid index or card type was given
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_ActivateCard2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,           /**< [In] Pointer to this layer's parameter structure */
    VAR(uint8, ANFCRL_VAR) bTechType2,                                      /**< [In] Tag type could be Type A,B or F */
    VAR(uint8, ANFCRL_VAR) bTagIndex2                                      /**< [In] The tag which has to be activated */
    );

/**
 * \brief Function to Configure the Discovery loop Passive Polling loop Sequence.
 *
 * \return Error code
 * \retval #PH_ERR_SUCCESS2            operation successful
 * \retval #PH_ERR_INVALID_PARAMETER2  Invalid option/response received
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_CfgPollSeq2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,      /**< [In] Pointer to discovery loop parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiscloopCfgPollSeq2            /**< [In] Discovery loop polling loop sequence pointer. */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_SW_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif

#endif /* PHACDISCLOOP_SW2_H */

