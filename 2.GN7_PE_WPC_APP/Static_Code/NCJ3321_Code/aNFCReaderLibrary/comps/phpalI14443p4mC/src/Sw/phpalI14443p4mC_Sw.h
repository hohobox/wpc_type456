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
*   @file    phpalI14443p4mC_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC_Sw - PAL API usage in common use cases.
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

#ifndef PHPALI14443P4MC_SW_H
#define PHPALI14443P4MC_SW_H

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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4mC_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4MC_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4mC_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4MC_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4MC_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4MC_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4MC_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

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
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
* \brief Reset protocol parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_ResetProtocol(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams           /**< [In] Pointer to this layer's parameter structure */
	);

/**
* \brief Set Configuration.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_SetConfig(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure */
  VAR(uint16, ANFCRL_VAR) wConfig,                                       /**< [In] Configuration Identifier. */
  VAR(uint16, ANFCRL_VAR) wValue                                         /**< [In] Configuration Value. */
	);

/**
* \brief Get Configuration.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_GetConfig(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure */
  VAR(uint16, ANFCRL_VAR) wConfig,                                       /**< [In] Configuration Identifier. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                        /**< [Out]Configuration Value. */
	);

/**
* \brief Validates received RATS request and send ATS response.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Protocol Error.
* \retval Other Depending on implementation and under laying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Activate(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRats,                                        /**< [In] Pointer to RATS receive Buffer */
  VAR(uint8, ANFCRL_VAR) bRatsLength,                                   /**< [In] RATS receive Buffer Length*/
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts,                                         /**< [In] ATS to be sent */
  VAR(uint16, ANFCRL_VAR) wAtsLength                                    /**< [In] ATS length */
	);

/**
* \brief Perform receive operation and validate received block.
*
* Response to S-block and R-Block are send internally. Response to I-Block can
* be send using \ref phpalI14443p4mC_Sw_Transmit.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Receive(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure */
  VAR(uint16, ANFCRL_VAR) wOption,                                       /**< [In] Receive option */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                                  /**< [Out] Pointer to receive Buffer */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength                                    /**< [Out] Pointer to receive Buffer Length */
	);

/**
* \brief Transmit I-Block block
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Transmit(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layer's parameter structure */
  VAR(uint16, ANFCRL_VAR) wOption,                                       /**< [In] Transmit option */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                                    /**< [In] Pointer to Transmit Buffer */
  VAR(uint16, ANFCRL_VAR) wTxLength                                     /**< [In] Transmit Buffer Length */
	);

/**
* \brief Send WTX request and wait for WTX response.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Protocol Error.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Wtx(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams           /**< [In] Pointer to this layer's parameter structure */
	);
  
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4MC_SW_H */
