/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2022
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
*   @file    phTMIUtils.h
*   @version 1.0.0
*
*   @brief   AUTOSAR TMIUtils - Common API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phTMIUtils TMI Utilities
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

#ifndef PHTMIUTILS_H
#define PHTMIUTILS_H

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
#include <ph_TypeDefs.h>
#include <CDD_AnfcRL_Cfg.h>

#ifdef NXPBUILD__PH_TMIUTILS
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTMIUtils.h
* @implements     DESIGN001, DESIGN002
*/
#define PHTMIUTILS_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHTMIUTILS_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHTMIUTILS_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHTMIUTILS_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHTMIUTILS_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHTMIUTILS_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHTMIUTILS_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHTMIUTILS_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHTMIUTILS_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phTMIUtils.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHTMIUTILS_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHTMIUTILS_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phTMIUtils.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHTMIUTILS_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHTMIUTILS_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHTMIUTILS_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phTMIUtils.h and CDD_AnfcRL_Cfg.h are different"
#endif
#endif /* NXPBUILD__PH_TMIUTILS */
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PH_TMIUTILS
/** \defgroup phTMIUtils TMI Utilities
* \ingroup phcommon
*
* \brief This layer provides Utilities for operating on transaction MAC.
* @{
*/

/**
* \name Activate TMI options
*/
/*@{*/
#define PH_TMIUTILS_DEACTIVATE_TMI     0x00U   /**< Deactivate TMI collection. */
#define PH_TMIUTILS_ACTIVATE_TMI       0x01U   /**< Activate TMI collection. */
#define PH_TMIUTILS_PAUSE_TMI          0x02U   /**< Pause TMI collection. */
#define PH_TMIUTILS_RESUME_TMI         0x03U   /**< Resume Paused TMI collection. */
#define PH_TMIUTILS_RESET_TMI          0x04U   /**< Reset TMI collection Buffer Index to 0. */
/*@}*/

/**
* \name Configuration Options
*/
/*@{*/
#define PH_TMIUTILS_TMI_STATUS          0x01U   /**< Config Option for TMI Status.*/
#define PH_TMIUTILS_TMI_OFFSET_LENGTH   0x02U   /**< Config option for Length offset in TMI Length */
#define PH_TMIUTILS_TMI_BUFFER_INDEX    0x04U   /**< Config option for buffer index */
#define PH_TMIUTILS_TMI_OFFSET_VALUE    0x08U   /**< Config option for buffer index */
/*@}*/

/**
* \name Flags for CollectTMI
*/
/*@{*/
#define PH_TMIUTILS_NO_PADDING          0x00U   /**< Flag indicating that padding is not required.*/
#define PH_TMIUTILS_READ_INS            0x01U   /**< Flag indicating that instruction is Read Operation.*/
#define PH_TMIUTILS_ZEROPAD_CMDBUFF     0x02U   /**< Flag to indicate zero padding after Cmd buffer */
#define PH_TMIUTILS_ZEROPAD_DATABUFF    0x04U   /**< Flag to indicate zero padding after Data buffer */
/*@}*/

/**
 * end of group phTMIUtils TMI Utilities
 * @}
 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** \addtogroup phTMIUtils TMI Utilities
* \ingroup phcommon
*
* \brief This layer provides Utilities for operating on transaction MAC.
* @{
*/

/**
* \brief Definition of a single Log entry
*/
typedef struct
{
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMIBuffer;                                       /**< Pointer to TMI Buffer. */
    VAR(uint32, ANFCRL_VAR) dwTMIBufLen;                                        /**< Length of TMI Buffer. */
    VAR(uint32, ANFCRL_VAR) dwTMIbufIndex;                                      /**< Pointer indicating the TMI Buffer fill index. */
    VAR(uint8, ANFCRL_VAR) bTMIStatus;                                         /**< Indicates whether TMI collection is PH_ON or PH_OFF. */
    VAR(uint32, ANFCRL_VAR) dwOffsetInTMI;                                      /**< Indicates the offset in TMI buffer where the Length field is stored in case of unspecified length read. */
} phTMIUtils_t;

/**
 * end of group phTMIUtils TMI Utilities
 * @}
 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phTMIUtils TMI Utilities
* \ingroup phcommon
*
* \brief This layer provides Utilities for operating on transaction MAC.
* @{
*/

/**
* \brief Initialize TMIUtils component
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/

FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_Init(
                           P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMIBuffer,        /**< [In] TMI Buffer. */
                           VAR(uint32, ANFCRL_VAR) dwBufLen            /**< [In] length of Buffer. */
                           );
/**
* \brief Activate TMI Collection
*
* \c bOption can be one of:\n
* \li #PH_TMIUTILS_DEACTIVATE_TMI
* \li #PH_TMIUTILS_ACTIVATE_TMI
* \li #PH_TMIUTILS_PAUSE_TMI
* \li #PH_TMIUTILS_RESUME_TMI
* \li #PH_TMIUTILS_RESET_TMI
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid Parameter.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_ActivateTMICollection(
                                             P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers parameter structure. */
                                             VAR(uint8, ANFCRL_VAR) bOption                /**< [In] Option field. */
                                             );

/**
* \brief Get TMI buffer
*
* \c bOption can be combination of:\n
* \li #PH_TMIUTILS_READ_INS
* \li #PH_TMIUTILS_ZEROPAD_CMDBUFF
* \li #PH_TMIUTILS_ZEROPAD_DATABUFF
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid Parameter.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_GetTMI(
                              P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                              P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTMIBuffer,       /**< [Out] Pointer to TMI Buffer. */
                              P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwTMILen            /**< [Out] pointer to length of TMI Buffer collected during previous transaction. */
                              );

/**
* \brief Collect TMI
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid Parameter.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_CollectTMI(
                                 P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers parameter structure. */
                                 VAR(uint8, ANFCRL_VAR) bOption,               /**< [In] Option field. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBuff,          /**< [In] Cmd Buffer. */
                                 VAR(uint16, ANFCRL_VAR) wCmdLen,           /**< [In] length of Cmd Buffer */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,               /**< [In] Data Buffer. */
                                 VAR(uint32, ANFCRL_VAR) dwDataLen,            /**< [In] length of Data Buffer */
                                 VAR(uint16, ANFCRL_VAR) wBlockSize            /**< [In] Block Size */
                                 );

/**
* \brief SetConfig
*
* Sets the #PH_TMIUTILS_TMI_OFFSET_LENGTH
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid Parameter.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_SetConfig(
                                P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig,               /**< [In] Config Option. */
                                VAR(uint32, ANFCRL_VAR) dwValue                 /**< [In] Value field. */
                                );

/**
* \brief GetConfig
*
* Gets the TMI status #PH_TMIUTILS_TMI_STATUS
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER Invalid Parameter.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTMIUtils_GetConfig(
                                P2VAR(phTMIUtils_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig,               /**< [In] Config Option. */
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pValue                /**< [Out] Read value. */
                                );

/**
 * end of group phTMIUtils TMI Utilities
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHTMIUTILS_AR_RELEASE_MAJOR_VERSION == 4) && (PHTMIUTILS_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PH_TMIUTILS */

#ifdef __cplusplus
}
#endif
#endif  /* PHTMIUTILS_H */
