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
*   @file    phalMfdfEVx_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdfEVx_Sw - AL API usage in common use cases.
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
#ifndef PHALMFDFEVX_SW_H
#define PHALMFDFEVX_SW_H


#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdfEVx_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDFEVX_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDFEVX_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALMFDFEVX_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALMFDFEVX_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDFEVX_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALMFDFEVX_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALMFDFEVX_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALMFDFEVX_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALMFDFEVX_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalMfdfEVx_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALMFDFEVX_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALMFDFEVX_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALMFDFEVX_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdfEVx_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALMFDFEVX_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALMFDFEVX_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALMFDFEVX_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdfEVx_Sw.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHALMFDFEVX_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
/* MIFARE DESFire EVx contactless IC secure messaging related commands. ------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Authenticate(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_AuthenticateISO(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_AuthenticateAES(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_AuthenticateEv2(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFirstAuth, VAR(uint16, ANFCRL_VAR) wOption,
    VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen, VAR(uint8, ANFCRL_VAR) bLenPcdCapsIn,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapsIn, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapsOut, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPdCapsOut);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Memory and Configuration management commands. ------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_FreeMem(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMemInfo);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Format(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_SetConfiguration(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
    VAR(uint8, ANFCRL_VAR) bDataLen);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetVersion(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVerInfo);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetCardUID(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bExchangeOption, VAR(uint8, ANFCRL_VAR) bOption,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength);




/* MIFARE DESFire EVx Key management commands. ---------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ChangeKey(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wOldKeyNo,
    VAR(uint16, ANFCRL_VAR) wOldKeyVer, VAR(uint16, ANFCRL_VAR) wNewKeyNo, VAR(uint16, ANFCRL_VAR) wNewKeyVer, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ChangeKeyEv2(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wOldKeyNo,
    VAR(uint16, ANFCRL_VAR) wOldKeyVer, VAR(uint16, ANFCRL_VAR) wNewKeyNo, VAR(uint16, ANFCRL_VAR) wNewKeyVer, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeyNoCard, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,
    VAR(uint8, ANFCRL_VAR) bDivLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_InitializeKeySet(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeyType);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_FinalizeKeySet(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo, VAR(uint8, ANFCRL_VAR) bKeySetVersion);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_RollKeySet(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySetNo);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetKeySettings(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySettings,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRespLen);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ChangeKeySettings(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeySettings);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetKeyVersion(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bKeyNo, VAR(uint8, ANFCRL_VAR) bKeySetNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeyVersion, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bRxLen);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Application management commands. -------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateApplication(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,
    VAR(uint8, ANFCRL_VAR) bKeySettings1, VAR(uint8, ANFCRL_VAR) bKeySettings2, VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName, VAR(uint8, ANFCRL_VAR) bISODFNameLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_DeleteApplication(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC, VAR(uint8, ANFCRL_VAR) bDAMMAC_Len);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateDelegatedApplication(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams, VAR(uint8, ANFCRL_VAR) bKeySettings1, VAR(uint8, ANFCRL_VAR) bKeySettings2, VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bKeySetValues,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName, VAR(uint8, ANFCRL_VAR) bISODFNameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_SelectApplication(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppId,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppId2);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetApplicationIDs(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pAidBuff,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumAIDs);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetDFNames(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFBuffer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFInfoLen);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetDelegatedInfo(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMSlot, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamSlotVer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pQuotaLimit, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFreeBlocks, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid);




/* MIFARE DESFire EVx File management commands. --------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateStdDataFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateBackupDataFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateValueFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo, VAR(uint8, ANFCRL_VAR) bCommSett,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLowerLmit, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUpperLmit, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue, VAR(uint8, ANFCRL_VAR) bLimitedCredit);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateLinearRecordFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsoFileId, VAR(uint8, ANFCRL_VAR) bCommSett, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateCyclicRecordFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsoFileId, VAR(uint8, ANFCRL_VAR) bCommSett, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec);

#ifdef  NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateTransactionMacFile(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint8, ANFCRL_VAR) bFileNo,
    VAR(uint8, ANFCRL_VAR) bCommSett,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,
	VAR(uint8, ANFCRL_VAR) bKeyType,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bTMKey,
	VAR(uint8, ANFCRL_VAR) bTMKeyVer);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_DeleteFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetFileIDs(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bNumFID);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetISOFileIDs(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFidBuffer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumFID);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetFileSettings(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFSBuffer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBufferLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetFileCounters(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileCounters, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ChangeFileSettings(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption,
    VAR(uint8, ANFCRL_VAR) bFileNo, VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, VAR(uint8, ANFCRL_VAR) bAddInfoLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddInfo);




/* MIFARE DESFire EVx Data management commands. --------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ReadData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bIns,
    VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLength, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_WriteData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns,
    VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetValue(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Credit(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_Debit(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_LimitedCredit(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ReadRecords(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns,
    VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecCount, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecSize, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_WriteRecord(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns,
    VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_UpdateRecord(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bCommOption, VAR(uint8, ANFCRL_VAR) bIns,
    VAR(uint8, ANFCRL_VAR) bFileNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecNo, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ClearRecordFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bFileNo);




/* MIFARE DESFire EVx Transaction management commands. -------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CommitTransaction(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_AbortTransaction(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CommitReaderID(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRI, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI);




/* MIFARE DESFire EVx ISO7816-4 commands. ---------------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoSelectFile(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint8, ANFCRL_VAR) bSelector,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname, VAR(uint8, ANFCRL_VAR) bDFnameLen, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFCI, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoReadBinary(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint8, ANFCRL_VAR) bOffset,
    VAR(uint8, ANFCRL_VAR) bSfid, VAR(uint32, ANFCRL_VAR) dwBytesToRead, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoUpdateBinary(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOffset, VAR(uint8, ANFCRL_VAR) bSfid,
    VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint32, ANFCRL_VAR) dwDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoReadRecords(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint8, ANFCRL_VAR) bRecNo,
    VAR(uint8, ANFCRL_VAR) bReadAllFromP1, VAR(uint8, ANFCRL_VAR) bSfid, VAR(uint32, ANFCRL_VAR) dwBytesToRead, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoAppendRecord(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSfid, VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint32, ANFCRL_VAR) dwDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoUpdateRecord(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bIns, VAR(uint8, ANFCRL_VAR) bRecNo,
    VAR(uint8, ANFCRL_VAR) bSfid, VAR(uint8, ANFCRL_VAR) bRefCtrl, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData, VAR(uint8, ANFCRL_VAR) bDataLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoGetChallenge(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer,
    VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, VAR(uint32, ANFCRL_VAR) dwLe, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRPICC1);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoExternalAuthenticate(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput, VAR(uint8, ANFCRL_VAR) bInputLen,
    VAR(uint8, ANFCRL_VAR) bExtendedLenApdu, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoInternalAuthenticate(
	P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,
    VAR(uint8, ANFCRL_VAR) bInputLen,
	VAR(uint8, ANFCRL_VAR) bExtendedLenApdu,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut,
	P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_IsoAuthenticate(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer,
    VAR(uint8, ANFCRL_VAR) bKeyNoCard, VAR(uint8, ANFCRL_VAR) bIsPICCkey);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Originality Check functions. ------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ReadSign(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bAddr, P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pSignature);




/* MIFARE DESFire EVx MIFARE Classic contactless IC functions. ---------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CreateMFCMapping(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bComOption, VAR(uint8, ANFCRL_VAR) bFileNo,
    VAR(uint8, ANFCRL_VAR) bFileOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCBlockList, VAR(uint8, ANFCRL_VAR) bMFCBlocksLen, VAR(uint8, ANFCRL_VAR) bRestoreSource, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense,
    VAR(uint8, ANFCRL_VAR) bMFCLicenseLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_RestoreTransfer(
		P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint8, ANFCRL_VAR) bCommOption,
		VAR(uint8, ANFCRL_VAR) bTargetFileNo,
		VAR(uint8, ANFCRL_VAR) bSourceFileNo);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_RestrictMFCUpdate(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCConfig,
    VAR(uint8, ANFCRL_VAR) bMFCConfigLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicense, VAR(uint8, ANFCRL_VAR) bMFCLicenseLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC);




/* MIFARE DESFire EVx POST Delivery Configuration function. ---------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_AuthenticatePDC(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bRfu, VAR(uint8, ANFCRL_VAR) bKeyNoCard, VAR(uint8, ANFCRL_VAR) wKeyNo,
    VAR(uint16, ANFCRL_VAR) wKeyVer, VAR(uint8, ANFCRL_VAR) bUpgradeInfo);
#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */




/* MIFARE DESFire EVx Miscellaneous functions. ----------------------------------------------------------------------------------------- */
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GetConfig(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_SetConfig(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wConfig, VAR(uint16, ANFCRL_VAR) wValue);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ResetAuthentication(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

#ifdef NXPBUILD__PHAL_MFDFEVX_NDA
FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GenerateDAMEncKey(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNoDAMEnc, VAR(uint16, ANFCRL_VAR) wKeyVerDAMEnc,
    VAR(uint16, ANFCRL_VAR) wKeyNoAppDAMDefault, VAR(uint16, ANFCRL_VAR) wKeyVerAppDAMDefault, VAR(uint8, ANFCRL_VAR) bAppDAMDefaultKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMEncKey);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GenerateDAMMAC(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bOption, VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC,
    VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDamParams, VAR(uint8, ANFCRL_VAR) bKeySettings1, VAR(uint8, ANFCRL_VAR) bKeySettings2,
    VAR(uint8, ANFCRL_VAR) bKeySettings3, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKeySetValues, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,
    VAR(uint8, ANFCRL_VAR) bISODFNameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncK, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_GenerateDAMMACSetConfig(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNoDAMMAC,
    VAR(uint16, ANFCRL_VAR) wKeyVerDAMMAC, VAR(uint16, ANFCRL_VAR) wOldDFNameLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOldISODFName, VAR(uint16, ANFCRL_VAR) wNewDFNameLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNewISODFName, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDAMMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CalculateTMV(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey,
    VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMI, VAR(uint32, ANFCRL_VAR) dwTMILen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMV);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_DecryptReaderID(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wKeyNoTMACKey,
    VAR(uint16, ANFCRL_VAR) wKeyVerTMACKey, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMC, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncTMRI, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTMRIPrev);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_ComputeMFCLicenseMAC(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wOption, VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyNo,
    VAR(uint16, ANFCRL_VAR) wMFCLicenseMACKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput, VAR(uint16, ANFCRL_VAR) wInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput, VAR(uint8, ANFCRL_VAR) bDivInputLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMFCLicenseMAC);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_CalculateMACSDM(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wSDMMacKeyNo,
    VAR(uint16, ANFCRL_VAR) wSDMMacKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData, VAR(uint16, ANFCRL_VAR) wInDataLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRespMac);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_DecryptSDMENCFileData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint8, ANFCRL_VAR) bSdmOption, VAR(uint16, ANFCRL_VAR) wEncKeyNo,
    VAR(uint16, ANFCRL_VAR) wEncKeyVer, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid, VAR(uint8, ANFCRL_VAR) bUidLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSDMReadCtr, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pEncdata, VAR(uint16, ANFCRL_VAR) wEncDataLen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdfEVx_Sw_DecryptSDMPICCData(P2VAR(phalMfdfEVx_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(uint16, ANFCRL_VAR) wKeyNo, VAR(uint16, ANFCRL_VAR) wKeyVer,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIndata, VAR(uint16, ANFCRL_VAR) wInDataLen, P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPlainData);

#endif /* NXPBUILD__PHAL_MFDFEVX_NDA */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDFEVX_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDFEVX_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* PHALMFDFEVX_SW_H */
