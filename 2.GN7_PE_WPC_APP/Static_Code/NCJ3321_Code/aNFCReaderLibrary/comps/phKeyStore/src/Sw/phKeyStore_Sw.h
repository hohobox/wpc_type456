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
*   @file    phKeyStore_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR KeyStore_Sw - API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phKeyStore KeyStore
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

#ifndef PHKEYSTORE_SW_H
#define PHKEYSTORE_SW_H

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
#ifndef NXPRDLIB_REM_GEN_INTFS
#   include <phKeyStore.h>
#endif

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phKeyStore_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHKEYSTORE_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHKEYSTORE_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHKEYSTORE_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHKEYSTORE_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHKEYSTORE_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHKEYSTORE_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHKEYSTORE_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phKeyStore_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHKEYSTORE_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phKeyStore_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHKEYSTORE_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHKEYSTORE_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHKEYSTORE_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phKeyStore_Sw.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_FormatKeyEntry(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wNewKeyType
                                );


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKey(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                VAR(uint16, ANFCRL_VAR) wKeyType,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                );


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKeyAtPos(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wPos,
                                VAR(uint16, ANFCRL_VAR) wKeyType,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKey,
                                VAR(uint16, ANFCRL_VAR) wNewKeyVersion
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetKUC(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetFullKeyEntry(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wNoOfKeys,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wNewRefNoKUC,
                                VAR(uint16, ANFCRL_VAR) wNewKeyType,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeys,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNewKeyVersionList
                                );


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKeyEntry(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wKeyVersionBufSize,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersion,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wKeyVersionLength,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKey(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wKeyNo,
                                VAR(uint16, ANFCRL_VAR) wKeyVersion,
                                VAR(uint8, ANFCRL_VAR) bKeyBufSize,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pKeyType
                                );


FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetConfig(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                VAR(uint16, ANFCRL_VAR) wValue
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_SetConfigStr(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBuffer,
                                VAR(uint16, ANFCRL_VAR) wBufferLength
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetConfig(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetConfigStr(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wConfig,
                                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppBuffer,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLength
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_ChangeKUC(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                VAR(uint32, ANFCRL_VAR) dwLimit
                                );

FUNC(phStatus_t, ANFCRL_CODE) phKeyStore_Sw_GetKUC(
                                P2VAR(phKeyStore_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                VAR(uint16, ANFCRL_VAR) wRefNoKUC,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwLimit,
                                P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pdwCurVal
                                );
#define ANFCRL_STOP_SEC_CODE
#if ((PHKEYSTORE_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHKEYSTORE_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHKEYSTORE_SW_H */
