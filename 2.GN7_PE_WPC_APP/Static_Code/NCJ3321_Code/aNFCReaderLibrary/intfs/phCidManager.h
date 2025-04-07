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
*   @file    phCidManager.h
*   @version 1.0.0
*
*   @brief   AUTOSAR CidManager - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phCidManager Cid Manager
*   @ingroup phcommon
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

#ifndef PHCIDMANAGER_H
#define PHCIDMANAGER_H

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
#include <CDD_AnfcRL_Cfg.h>
#include "phhalHw.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phCidManager.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCIDMANAGER_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHCIDMANAGER_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHCIDMANAGER_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHCIDMANAGER_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHCIDMANAGER_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCIDMANAGER_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCIDMANAGER_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCIDMANAGER_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phCidManager.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCIDMANAGER_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phCidManager.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCIDMANAGER_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCIDMANAGER_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCIDMANAGER_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phCidManager.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @}*/
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_CIDMANAGER
/** \defgroup phcommon Common Layer
* \brief Common Components without dependencies.
*
*/

/** \defgroup phCidManager Cid Manager
* \ingroup phcommon
* \brief Eases Multiple-Card-Management by providing and locking CIDs.
* @{
*/

#define PH_CIDMANAGER_LAST_CID  14U      /**< The last manageable CID. */

#ifdef NXPBUILD__PH_CIDMANAGER_SW
/** \defgroup phCidManager_Sw Component : Software
* \brief Software implementation of the Cid Manager
* @{
*/
#define PH_CIDMANAGER_SW_ID     0x01U   /**< ID for Software component. */
/**
 * end of group phCidManager_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_CIDMANAGER_SW */

/**
 * end of group phCidManager Cid Manager
 * @}
 */
#endif /* NXPBUILD__PH_CIDMANAGER */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PH_CIDMANAGER
/** \addtogroup phCidManager Cid Manager
* \ingroup phcommon
* \brief Eases Multiple-Card-Management by providing and locking CIDs.
* @{
*/

#ifdef NXPBUILD__PH_CIDMANAGER_SW
/** \addtogroup phCidManager_Sw Component : Software
* \brief Software implementation of the Cid Manager
*  @{
*/

/**
* \brief Cid Manager parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                   /**< Layer ID for this component, NEVER MODIFY! */
    VAR(uint8, ANFCRL_VAR) bCidList[PH_CIDMANAGER_LAST_CID];       /**< Contains a list of Cids, where a value
                                                    of /c 0 means free and a value of /c 1 means occupied. */
} phCidManager_Sw_DataParams_t;
/**
 * end of group phCidManager_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PH_CIDMANAGER_SW */

/**
 * end of group phCidManager Cid Manager
 * @}
 */
#endif /* NXPBUILD__PH_CIDMANAGER */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PH_CIDMANAGER

/** \addtogroup phCidManager Cid Manager
* \ingroup phcommon
* \brief Eases Multiple-Card-Management by providing and locking CIDs.
* @{
*/

#ifdef NXPBUILD__PH_CIDMANAGER_SW

#define ANFCRL_START_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup phCidManager_Sw Component : Software
* \brief Software implementation of the Cid Manager
*  @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCidManager_Sw_Init(
                                P2VAR(phCidManager_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams                   /**< [In] Specifies the size of the data parameter structure. */
                                );

/**
 * end of group phCidManager_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPBUILD__PH_CIDMANAGER_SW */

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phCidManager/src/Sw/phCidManager_Sw.h"

#define phCidManager_GetFreeCid(pDataParams, pCid) \
        phCidManager_Sw_GetFreeCid((phCidManager_Sw_DataParams_t *)pDataParams, pCid)

#define phCidManager_FreeCid(pDataParams, bCid) \
        phCidManager_Sw_FreeCid((phCidManager_Sw_DataParams_t *)pDataParams, bCid)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/**
* \brief Retrieve the lowest free Card Identifier.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_USE_CONDITION No free Cid available.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCidManager_GetFreeCid(
                                   P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layer's parameter structure. */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid       /**< [Out] Card Identifier */
                                   );

/**
* \brief Free an occupied Cid.
*
* Note: This should be called after discarding a card.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid or unoccupied Cid supplied.
*/
FUNC(phStatus_t, ANFCRL_CODE) phCidManager_FreeCid(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                                VAR(uint8, ANFCRL_VAR) bCid        /**< [In] Card Identifier */
                                );

#define ANFCRL_STOP_SEC_CODE
#if ((PHCIDMANAGER_AR_RELEASE_MAJOR_VERSION == 4) && (PHCIDMANAGER_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phCidManager Cid Manager
 * @}
 */

#endif /* NXPBUILD__PH_CIDMANAGER */

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /* PHCIDMANAGER_H */
