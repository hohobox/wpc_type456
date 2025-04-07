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
*   @file    phalMfdfEVx_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx_Sw_Int - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdfEVx MIFARE DESFire EVx
*   @ingroup phalApplication
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
#ifndef PHALMFDFEVX_SW_INT_H
#define PHALMFDFEVX_SW_INT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <Compiler.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALMFDFEVX_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalMfdfEVx_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALMFDFEVX_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdfEVx_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALMFDFEVX_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALMFDFEVX_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALMFDFEVX_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdfEVx_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_CardExchange(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wBufferOption, VAR(uint16, ANFCRL_VAR) wTotDataLen,
    VAR(uint8, ANFCRL_VAR) bExchangeLE, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPiccRetCode);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_SendDataToPICC(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bIns,
	VAR(uint8, ANFCRL_VAR) bCommOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmd,
	VAR(uint16, ANFCRL_VAR) wCmdLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
	VAR(uint16, ANFCRL_VAR) wDataLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bLastChunk,
	VAR(uint16, ANFCRL_VAR) wLastChunkLen,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_SendDataAndAddDataToPICC(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bIns, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmd,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddData, VAR(uint16, ANFCRL_VAR) wAddDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GetData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ReadData_Plain(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_Plain(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bIns, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, VAR(uint8, ANFCRL_VAR) bCommOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ReadData_Enc(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff, VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_Enc(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bIns,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen,
	VAR(uint8, ANFCRL_VAR) bPaddingOption,
	VAR(uint8, ANFCRL_VAR) bCommOption,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
	VAR(uint16, ANFCRL_VAR) wDataLen);

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_Write_New(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint16, ANFCRL_VAR) wDataLen);

FUNC(void, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ResetAuthStatus(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_IsoRead(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bCmdBuff,
    VAR(uint16, ANFCRL_VAR) wCmdLen, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(void, ANFCRL_CODE) phalMfdfEVx_Sw_Int_TruncateMac(P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMac);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeIv (VAR(uint8, ANFCRL_VAR) bIsResponse, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTi, VAR(uint16, ANFCRL_VAR) wCmdCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GetFrameLength(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFSD, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pFSC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ISOGetData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff, VAR(uint16, ANFCRL_VAR) wCmdLen,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_DecryptSDMData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIv,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInputOutputData, VAR(uint16, ANFCRL_VAR) wInputDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeSDMSessionVectors(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wSrcKeyNo, VAR(uint16, ANFCRL_VAR) wSrcKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_GenerateSDMSessionKeysAES(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption,
    VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCUID, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessMacKey);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Int_ComputeSDMIV(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessEncKey,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIV);

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* PHALMFDFEVX_SW_INT_H */
