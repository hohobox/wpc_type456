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
*   @file    phpalMifare_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palMifare_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalMifare MIFARE(R)
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

#ifndef PHPALMIFARE_SW_H
#define PHPALMIFARE_SW_H

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
#include <CDD_AnfcRL_Cfg.h>
#ifndef NXPRDLIB_REM_GEN_INTFS
#   include <phpalMifare.h>
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalMifare_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALMIFARE_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALMIFARE_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALMIFARE_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALMIFARE_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALMIFARE_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALMIFARE_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALMIFARE_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalMifare_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALMIFARE_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalMifare_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALMIFARE_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALMIFARE_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALMIFARE_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalMifare_Sw.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeL3(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeL4(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangePc(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_ExchangeRaw(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wOption,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
  VAR(uint16, ANFCRL_VAR) wTxLength,
  VAR(uint8, ANFCRL_VAR) bTxLastBits,
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLastBits
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_MfcAuthenticateKeyNo(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint8, ANFCRL_VAR) bBlockNo,
  VAR(uint8, ANFCRL_VAR) bKeyType,
  VAR(uint16, ANFCRL_VAR) wKeyNo,
  VAR(uint16, ANFCRL_VAR) wKeyVersion,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
	);

FUNC(phStatus_t, ANFCRL_CODE)  phpalMifare_Sw_MfcAuthenticate(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint8, ANFCRL_VAR) bBlockNo,
  VAR(uint8, ANFCRL_VAR) bKeyType,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_SetMinFdtPc(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wValue
	);

FUNC(phStatus_t, ANFCRL_CODE) phpalMifare_Sw_GetConfig(
  P2VAR(phpalMifare_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
  VAR(uint16, ANFCRL_VAR) wConfig,
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
	);
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALMIFARE_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALMIFARE_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* PHPALMIFARE_SW_H */
