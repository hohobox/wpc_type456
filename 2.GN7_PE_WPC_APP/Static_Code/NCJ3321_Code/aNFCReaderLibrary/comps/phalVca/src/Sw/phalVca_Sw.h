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
*   @file    phalVca_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca_Sw - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalVca Virtual Card Architecture (R)
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

#ifndef PHALVCA_SW_H
#define PHALVCA_SW_H

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
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalVca_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALVCA_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALVCA_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALVCA_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALVCA_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalVca_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALVCA_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALVCA_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALVCA_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALVCA_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALVCA_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca_Sw.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_StartCardSelection (P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_FinalizeCardSelection (P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumValidIids);

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SelectVc(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion);
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_DeselectVc(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_VcSupport(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint16, ANFCRL_VAR) wKeyEncNumber, VAR(uint16, ANFCRL_VAR) wKeyEncVersion,
    VAR(uint16, ANFCRL_VAR) wKeyMacNumber, VAR(uint16, ANFCRL_VAR) wKeyMacVersion);

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_VcSupportLast(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid, VAR(uint8, ANFCRL_VAR) bLenCap, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapabilities,
    VAR(uint16, ANFCRL_VAR) wKeyEncNumber, VAR(uint16, ANFCRL_VAR) wKeyEncVersion, VAR(uint16, ANFCRL_VAR) wKeyMacNumber, VAR(uint16, ANFCRL_VAR) wKeyMacVersion);
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_GetIidInfo(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wValidIidIndex, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pIidIndex, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUidSize,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInfo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPdCapabilities);

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_IsoSelect(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSelectionControl, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bDFnameLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFCI, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_IsoExternalAuthenticate(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion);
#endif /* NXPBUILD__PH_CRYPTOSYM */




#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_ProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, VAR(uint8, ANFCRL_VAR) bPps1, VAR(uint8, ANFCRL_VAR) bNumSteps,
    VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndRC);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_ProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
    VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_PrepareProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_PrepareProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption,  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_ProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndRC);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_ProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bGenerateRndC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC, VAR(uint8, ANFCRL_VAR) bNumSteps,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheck(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC, VAR(uint8, ANFCRL_VAR) bPps1, VAR(uint16, ANFCRL_VAR) wKeyNumber,
    VAR(uint16, ANFCRL_VAR) wKeyVersion);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheckNew(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
    VAR(uint16, ANFCRL_VAR) wRespLen, VAR(uint16, ANFCRL_VAR) wKeyNumber, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndCmdResp);
#endif /* NXPBUILD__PH_CRYPTOSYM */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Cmd_VerifyProximityCheckUtility(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdMac, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdResp);




FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetConfig(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_GetConfig(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetSessionKeyUtility(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey, VAR(uint8, ANFCRL_VAR) bAuthMode);

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_SetApplicationType(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlDataParams);

#ifdef NXPBUILD__PH_CRYPTOSYM
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_DecryptResponse(P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRandChal, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCData);

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* NXPBUILD__PH_CRYPTOSYM */

#endif

#ifdef __cplusplus
}
#endif

#endif /* PHALVCA_SW_H */
