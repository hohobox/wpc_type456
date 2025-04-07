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
*   @file    phLog_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Log_Int - API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phLog Log
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


#ifndef PHLOG_INT_H
#define PHLOG_INT_H
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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phLog_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHLOG_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHLOG_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHLOG_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHLOG_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHLOG_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHLOG_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHLOG_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHLOG_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHLOG_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phLog_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHLOG_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHLOG_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHLOG_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phLog_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHLOG_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHLOG_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHLOG_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phLog_Int.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHLOG_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHLOG_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
* \brief Retrieve \ref phLog_RegisterEntry_t corresponding to given DataParams pointer
* \return pointer which points to Register Entry
*/
FUNC(phLog_RegisterEntry_t*, ANFCRL_CODE) phLog_GetRegisteredEntry(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams  /**< [In] The DataParams of the calling function. */
    );

/**
* \brief Add a new log entry containing raw data. \see phLog_LogEnty_t
*/
FUNC(void, ANFCRL_CODE) phLog_AddParam_Raw(
                        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] The DataParams of the calling function. */
                        VAR(uint8, ANFCRL_VAR) bLogType,       /**< [In] Type of Entry (one of the \c PH_LOG_LOGTYPE_* values). */
                        P2CONST(char, AUTOMATIC, ANFCRL_APPL_CONST) pName,     /**< [In] The Null-terminated name of the parameter. */
                        P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) pParam,    /**< [In] Pointer to the memory where the parameter resides. */
                        VAR(uint16, ANFCRL_VAR) wLength,       /**< [In] The length in bytes to the supplied buffer. */
                        VAR(uint8, ANFCRL_VAR) bDataType       /**< [In] Indicates the value type (either #PH_LOG_DATATYPE_BUFFER or #PH_LOG_DATATYPE_VALUE). */
                        );

#define ANFCRL_STOP_SEC_CODE
#if ((PHLOG_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHLOG_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}/* Extern C */
#endif
#endif  /* PHLOG_INT_H */
