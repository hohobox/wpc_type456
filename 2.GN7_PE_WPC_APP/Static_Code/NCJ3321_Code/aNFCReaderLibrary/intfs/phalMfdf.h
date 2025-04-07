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
*   @file    phalMfdf.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdf - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdf MIFARE DESFire (R)
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
#ifndef PHALMFDF_H
#define PHALMFDF_H

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
#include "phhalHw.h"
#include "phpalMifare.h"
#include <ph_TypeDefs.h>
#include <ph_RefDefs.h>
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdf.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDF_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDF_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALMFDF_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALMFDF_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDF_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALMFDF_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALMFDF_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALMFDF_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALMFDF_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalMfdf.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALMFDF_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALMFDF_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdf.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALMFDF_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALMFDF_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALMFDF_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdf.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHAL_MFDF

/** \defgroup phalMfdf MIFARE DESFire (R)
* \ingroup phalApplication
* \brief These Functions implement the MIFARE DESFire(R) EV1 commands.
* @{
*/

#ifdef NXPBUILD__PH_NDA_MFDF

/**
* \name Authentication Modes 
*/
/*@{*/
#define PHAL_MFDF_AUTHENTICATE      0x0AU   /**< Backwards compatible Authentication; Mode = 0x0A. */
#define PHAL_MFDF_AUTHENTICATEISO   0x1AU   /**< ISO Authentication; 0x1A. */
#define PHAL_MFDF_AUTHENTICATEAES   0xAAU   /**< AES Authentication; 0xAA. */
/*@}*/

/**
* \name Diversification options to be used with ChangeKey and Authenticate 
*/
/*@{*/
#define PHAL_MFDF_NO_DIVERSIFICATION            0xFFFFU /**< No diversification. */
#define PHAL_MFDF_CHGKEY_DIV_NEW_KEY            0x0002U /**< Bit 1. Indicating diversification of new key required. */
#define PHAL_MFDF_CHGKEY_DIV_OLD_KEY            0x0004U /**< Bit 2 indicating old key was diversified. */
#define PHAL_MFDF_CHGKEY_DIV_NEW_KEY_ONERND     0x0008U /**< Bit 3 indicating new key diversification using one rnd. Default is two rounds. */
#define PHAL_MFDF_CHGKEY_DIV_OLD_KEY_ONERND     0x0010U /**< Bit 4 indicating old key diversification using one rnd. Default is two rounds. */
#define PHAL_MFDF_CHGKEY_DIV_METHOD_CMAC        0x0020U /**< Bit 5 indicating key diversification method based on CMAC. Default is Encryption method */

#define PHAL_MFDF_DIV_METHOD_ENCR               PH_CRYPTOSYM_DIV_MODE_DESFIRE       /**< Encryption based method of diversification. */
#define PHAL_MFDF_DIV_METHOD_CMAC               PH_CRYPTOSYM_DIV_MODE_MIFARE_PLUS   /**< CMAC based method of diversification. */
#define PHAL_MFDF_DIV_OPTION_2K3DES_FULL        PH_CRYPTOSYM_DIV_OPTION_2K3DES_FULL /**< Encryption based method, full key diversification. */
#define PHAL_MFDF_DIV_OPTION_2K3DES_HALF        PH_CRYPTOSYM_DIV_OPTION_2K3DES_HALF /**< Encryption based method, half key diversification. */
/*@}*/

#endif /* NXPBUILD__PH_NDA_MFDF */

/**
* \name Other Options for various Functions 
*/
/*@{*/
#define PHAL_MFDF_NOT_AUTHENTICATED     0xFFU   /**< No authentication. */

#ifdef NXPBUILD__PH_NDA_MFDF

#define PHAL_MFDF_SET_CONFIG_OPTION1    0x00U   /**< Option 1 Data is the configuration byte. */
#define PHAL_MFDF_SET_CONFIG_OPTION2    0x01U   /**< Option 2 Data is default key version and key. */
#define PHAL_MFDF_SET_CONFIG_OPTION3    0x02U   /**< Option 3 Data is user defined ATS. */

#endif /* NXPBUILD__PH_NDA_MFDF */

#define PHAL_MFDF_COMMUNICATION_PLAIN   0x00U   /**< Plain mode of communication. */
#define PHAL_MFDF_COMMUNICATION_MACD    0x10U   /**< MAC mode of communication. */
#define PHAL_MFDF_COMMUNICATION_ENC     0x30U   /**< Enciphered mode of communication. */

#ifdef NXPBUILD__PH_NDA_MFDF

#define PHAL_MFDF_ENABLE_LIMITEDCREDIT  0x01U   /**< Bit 0 set to 1 to enable Limited credit. */
#define PHAL_MFDF_ENABLE_FREE_GETVALUE  0x02U   /**< Bit 1 set to 1 to enable free get value. */

#endif /* NXPBUILD__PH_NDA_MFDF */

#define PHAL_MFDF_ADDITIONAL_INFO       0x00A1U  /**< Option for getconfig to get additional info of a generic error. */
/*@}*/

/**
* \name phalMfdf Custom Error Codes 
*/
/*@{*/
#define PHAL_MFDF_NO_CHANGES                    ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U)     /**< MF DF Response - No changes done to backup files. */
#define PHAL_MFDF_ERR_OUT_OF_EEPROM_ERROR       ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 1U)     /**< MF DF Response - Insufficient NV-Memory. */
#define PHAL_MFDF_ERR_NO_SUCH_KEY               ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 2U)     /**< MF DF Invalid key number specified. */
#define PHAL_MFDF_ERR_PERMISSION_DENIED         ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 3U)     /**< MF DF Current configuration/status does not allow the requested command. */
#define PHAL_MFDF_ERR_APPLICATION_NOT_FOUND     ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 4U)     /**< MF DF Requested AID not found on PICC. */
#define PHAL_MFDF_ERR_BOUNDARY_ERROR            ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 5U)     /**< MF DF Attempt to read/write data from/to beyond the files/record's limits. */
#define PHAL_MFDF_ERR_COMMAND_ABORTED           ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 6U)     /**< MF DF Previous cmd not fully completed. Not all frames were requested or provided by the PCD. */
#define PHAL_MFDF_ERR_COUNT                     ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 7U)     /**< MF DF Num. of APPLNS limited to 28. No additional applications possible. */
#define PHAL_MFDF_ERR_DUPLICATE                 ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 8U)     /**< MF DF File/Application with same number already exists. */
#define PHAL_MFDF_ERR_FILE_NOT_FOUND            ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 9U)     /**< MF DF Specified file number does not exist. */
#define PHAL_MFDF_ERR_PICC_CRYPTO               ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 10U)    /**< MF DF Crypto error returned by PICC. */
#define PHAL_MFDF_ERR_PARAMETER_ERROR           ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 11U)    /**< MF DF Parameter value error returned by PICC. */
#define PHAL_MFDF_ERR_DF_GEN_ERROR              ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 12U)    /**< MF DF DesFire Generic error. Check additional Info. */
#define PHAL_MFDF_ERR_DF_7816_GEN_ERROR         ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 13U)    /**< MF DF ISO 7816 Generic error. Check Additional Info. */
/*@}*/

/**
 * end of group phalMfdf MIFARE DESFire (R)
 * @}
 */

#endif /* NXPBUILD__PHAL_MFDF */

#ifdef NXPBUILD__PHAL_MFDF_SW

/**
* \defgroup phalMfdf_Sw Component : Software
* \ingroup phalMfdf
* \brief Software implementation of the MIFARE DESFire(R) EV1 commands 
* @{
*/

#define PHAL_MFDF_SW_ID 0x01U   /**< ID for Software MIFARE DESFire layer. */

/**
 * end of group phalMfdf_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_MFDF_SW */


#ifdef NXPBUILD__PHAL_MFDF

/** 
* \addtogroup phalMfdf MIFARE DESFire (R)
* @{
*/

/**
* \name PICC level Commands 
*/
/*@{*/


#ifdef NXPRDLIB_REM_GEN_INTFS

#define phalMfdf_CreateApplication(pDataParams,bOption,pAid,bKeySettings1,bKeySettings2,pISOFileId,pISODFName,bISODFNameLen) \
        phalMfdf_Sw_CreateApplication((phalMfdf_Sw_DataParams_t *)pDataParams,bOption,pAid,bKeySettings1,bKeySettings2,pISOFileId,pISODFName,bISODFNameLen)

#define phalMfdf_SelectApplication( pDataParams, pAppId) \
        phalMfdf_Sw_SelectApplication( (phalMfdf_Sw_DataParams_t *)pDataParams, pAppId)

#define phalMfdf_GetVersion(pDataParams, pVerInfo) \
        phalMfdf_Sw_GetVersion((phalMfdf_Sw_DataParams_t *)pDataParams, pVerInfo)

#define phalMfdf_CreateStdDataFile(pDataParams,bOption,bFileNo,pISOFileId,bCommSett,pAccessRights,pFileSize) \
        phalMfdf_Sw_CreateStdDataFile((phalMfdf_Sw_DataParams_t *)pDataParams,bOption,bFileNo,pISOFileId,bCommSett,pAccessRights,pFileSize)

#define phalMfdf_WriteData(pDataParams,bCommOption,bFileNo,pOffset,pTxData,pTxDataLen) \
        phalMfdf_Sw_WriteData((phalMfdf_Sw_DataParams_t *)pDataParams,bCommOption,bFileNo,pOffset,pTxData,pTxDataLen)

#define phalMfdf_IsoSelectFile(pDataParams,bOption,bSelector,pFid,pDFname,bDFnameLen,ppFCI,pwFCILen) \
        phalMfdf_Sw_IsoSelectFile((phalMfdf_Sw_DataParams_t *)pDataParams,bOption,bSelector,pFid,pDFname,bDFnameLen,ppFCI,pwFCILen)

#define phalMfdf_IsoReadBinary(pDataParams,wOption,bOffset,bSfid,bBytesToRead,ppRxBuffer,pBytesRead) \
        phalMfdf_Sw_IsoReadBinary((phalMfdf_Sw_DataParams_t *)pDataParams,wOption,bOffset,bSfid,bBytesToRead,ppRxBuffer,pBytesRead)

#define phalMfdf_IsoUpdateBinary(pDataParams,bOffset,bSfid,pData,bDataLen) \
        phalMfdf_Sw_IsoUpdateBinary((phalMfdf_Sw_DataParams_t *)pDataParams,bOffset,bSfid,pData,bDataLen)

#define phalMfdf_GetConfig(pDataParams, wConfig, pValue) \
        phalMfdf_Sw_GetConfig((phalMfdf_Sw_DataParams_t *)pDataParams, wConfig, pValue)

#define phalMfdf_SetConfig(pDataParams, wConfig, wValue) \
        phalMfdf_Sw_SetConfig((phalMfdf_Sw_DataParams_t *)pDataParams, wConfig, wValue)

#ifdef NXPBUILD__PH_NDA_MFDF

#define phalMfdf_DeleteApplication(pDataParams, pAid) \
        phalMfdf_Sw_DeleteApplication((phalMfdf_Sw_DataParams_t *)pDataParams, pAid)

#define phalMfdf_GetApplicationIDs(pDataParams, pAidBuff, pNumAIDs) \
        phalMfdf_Sw_GetApplicationIDs((phalMfdf_Sw_DataParams_t *)pDataParams, pAidBuff, pNumAIDs)

#define phalMfdf_GetDFNames(pDataParams, bOption, pDFBuffer, pDFInfoLen) \
        phalMfdf_Sw_GetDFNames((phalMfdf_Sw_DataParams_t *)pDataParams, bOption, pDFBuffer, pDFInfoLen)

#define phalMfdf_FormatPICC(pDataParams) \
        phalMfdf_Sw_FormatPICC((phalMfdf_Sw_DataParams_t *)pDataParams)

#define phalMfdf_FreeMem(pDataParams, pMemInfo) \
        phalMfdf_Sw_FreeMem((phalMfdf_Sw_DataParams_t *)pDataParams, pMemInfo)

#define phalMfdf_SetConfiguration(pDataParams, bOption, pData, bDataSize) \
        phalMfdf_Sw_SetConfiguration((phalMfdf_Sw_DataParams_t *)pDataParams, bOption, pData, bDataSize)

#define phalMfdf_GetCardUID(pDataParams, pUid) \
        phalMfdf_Sw_GetCardUID((phalMfdf_Sw_DataParams_t *)pDataParams, pUid)

#define phalMfdf_GetFileIDs(pDataParams, pResponse, bNumFIDs)\
        phalMfdf_Sw_GetFileIDs((phalMfdf_Sw_DataParams_t *)pDataParams, pResponse, bNumFIDs)

#define phalMfdf_GetISOFileIDs(pDataParams, pFidBuffer, pNumFIDs) \
        phalMfdf_Sw_GetISOFileIDs((phalMfdf_Sw_DataParams_t *)pDataParams, pFidBuffer, pNumFIDs)

#define phalMfdf_GetFileSettings(pDataParams, bFileNo, pFSBuffer, bBufferLen) \
        phalMfdf_Sw_GetFileSettings((phalMfdf_Sw_DataParams_t *)pDataParams, bFileNo, pFSBuffer, bBufferLen)

#define phalMfdf_ChangeFileSettings(pDataParams, bOption, bFileNo, bCommSett, pAccessRights)\
        phalMfdf_Sw_ChangeFileSettings((phalMfdf_Sw_DataParams_t *)pDataParams, bOption, bFileNo, bCommSett, pAccessRights)

#define phalMfdf_CreateBackupDataFile(pDataParams,bOption,bFileNo,pISOFileId,bCommSett,pAccessRights,pFileSize) \
        phalMfdf_Sw_CreateBackupDataFile((phalMfdf_Sw_DataParams_t *)pDataParams,bOption,bFileNo,pISOFileId,bCommSett,pAccessRights,pFileSize)

#define phalMfdf_CreateValueFile(pDataParams,bFileNo, bCommSett, pAccessRights,pLowerLmit, pUpperLmit, pValue, bLimitedCredit) \
        phalMfdf_Sw_CreateValueFile((phalMfdf_Sw_DataParams_t *)pDataParams,bFileNo, bCommSett, pAccessRights, pLowerLmit, pUpperLmit, pValue, bLimitedCredit)

#define phalMfdf_CreateLinearRecordFile(pDataParams,  bOption,  bFileNo,  pIsoFileId, bCommSett, pAccessRights, pRecordSize, pMaxNoOfRec ) \
        phalMfdf_Sw_CreateLinearRecordFile((phalMfdf_Sw_DataParams_t *)pDataParams, bFileNo,  pIsoFileId, bCommSett, pAccessRights, pRecordSize, pMaxNoOfRec)

#define phalMfd_CreateCyclicRecordFile(pDataParams,bOption,bFileNo, pIsoFileId, bCommSett, pAccessRights,  pRecordSize, pMaxNoOfRec )\
        phalMfdf_Sw_CreateCyclicRecordFile((phalMfdf_Sw_DataParams_t *)pDataParams, bOption, bFileNo, pIsoFileId, bCommSett, pAccessRights, pRecordSize, pMaxNoOfRec)

#define phalMfdf_DeleteFile(pDataParams,bFileNo) \
        phalMfdf_Sw_DeleteFile((phalMfdf_Sw_DataParams_t *)pDataParams,bFileNo)

#define phalMfdf_ReadData(pDataParams, bOption, bFileNo,  pOffset,  pLength, ppRxdata, pRxdataLen) \
        phalMfdf_Sw_ReadData((phalMfdf_Sw_DataParams_t *)pDataParams, bOption, bFileNo,  pOffset,  pLength, ppRxdata, pRxdataLen)

#define phalMfdf_GetValue(pDataParams, bCommOption,  bFileNo,  pValue) \
        phalMfdf_Sw_GetValue((phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption, bFileNo, pValue)

#define phalMfdf_Credit( pDataParams, bCommOption, bFileNo, pValue) \
        phalMfdf_Sw_Credit( (phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption, bFileNo, pValue)

#define phalMfdf_Debit( pDataParams,bCommOption,  bFileNo, pValue) \
        phalMfdf_Sw_Debit((phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption,  bFileNo, pValue)

#define phalMfdf_LimitedCredit(  pDataParams,  bCommOption,  bFileNo, pValue ) \
        phalMfdf_Sw_LimitedCredit((phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption, bFileNo, pValue)

#define phalMfdf_WriteRecord(pDataParams, bCommOption, bFileNo, pOffset, pData, pDataLen) \
        phalMfdf_Sw_WriteRecord((phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption, bFileNo, pOffset, pData, pDataLen)

#define phalMfdf_ReadRecords(pDataParams, bCommOption, bFileNo, pOffset, pNumRec, pRecSize, ppRxdata, pRxdataLen) \
        phalMfdf_Sw_ReadRecords((phalMfdf_Sw_DataParams_t *)pDataParams, bCommOption, bFileNo, pOffset, pNumRec, pRecSize, ppRxdata, pRxdataLen)

#define phalMfdf_ClearRecordFile(pDataParams, bFileNo) \
        phalMfdf_Sw_ClearRecordFile((phalMfdf_Sw_DataParams_t *)pDataParams, bFileNo)

#define phalMfdf_CommitTransaction(pDataParams) \
        phalMfdf_Sw_CommitTransaction((phalMfdf_Sw_DataParams_t *)pDataParams)

#define phalMfdf_AbortTransaction(pDataParams) \
        phalMfdf_Sw_AbortTransaction((phalMfdf_Sw_DataParams_t *)pDataParams)

#define phalMfdf_IsoReadRecords(pDataParams,  wOption, bRecNo, bReadAllFromP1, bSfid, bBytesToRead, ppRxBuffer, pBytesRead) \
        phalMfdf_Sw_IsoReadRecords((phalMfdf_Sw_DataParams_t *)pDataParams, wOption, bRecNo, bReadAllFromP1, bSfid, bBytesToRead, ppRxBuffer, pBytesRead)

#define phalMfdf_IsoAppendRecord(pDataParams, bSfid,  pData, bDataLen) \
        phalMfdf_Sw_IsoAppendRecord((phalMfdf_Sw_DataParams_t *)pDataParams, bSfid, pData, bDataLen)

#define phalMfdf_IsoGetChallenge(pDataParams, wKeyNo, wKeyVer, bLe, pRPICC1) \
        phalMfdf_Sw_IsoGetChallenge((phalMfdf_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVer, bLe, pRPICC1)

#define phalMfdf_IsoExternalAuthenticate(pDataParams, pDataIn, bInputLen, pDataOut, pOutLen) \
        phalMfdf_Sw_IsoExternalAuthenticate((phalMfdf_Sw_DataParams_t *)pDataParams, pDataIn, bInputLen, pDataOut, pOutLen)

#define phalMfdf_IsoInternalAuthenticate(pDataParams,  pDataIn,  bInputLen, pDataOut,  pOutLen) \
        phalMfdf_Sw_IsoInternalAuthenticate((phalMfdf_Sw_DataParams_t *)pDataParams, pDataIn,  bInputLen, pDataOut, pOutLen)

#define phalMfdf_IsoAuthenticate(pDataParams,  wKeyNo,wKeyVer,bKeyNoCard, isPICCkey) \
        phalMfdf_Sw_IsoAuthenticate((phalMfdf_Sw_DataParams_t *)pDataParams, wKeyNo, wKeyVer, bKeyNoCard, isPICCkey)

#define phalMfdf_ResetAuthStatus(pDataParams) \
        phalMfdf_Sw_ResetAuthStatus((phalMfdf_Sw_DataParams_t *)pDataParams)

#endif /* NXPBUILD__PH_NDA_MFDF */

#endif /* NXPRDLIB_REM_GEN_INTFS */

#ifndef NXPRDLIB_REM_GEN_INTFS /* Without optimization */

/*@}*/

/**
 * end of group phalMfdf MIFARE DESFire (R)
 * @}
 */

#endif /* Without optimization */

#endif /* NXPBUILD__PHAL_MFDF */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHAL_MFDF_SW

/**
* \addtogroup phalMfdf_Sw Component : Software
* \ingroup phalMfdf
* \brief Software implementation of the MIFARE DESFire(R) EV1 commands 
* @{
*/

/**
* \brief struct phalMfdf_Sw_DataParams_t
*
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                               /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams;                                /**< Pointer to the parameter structure of the palMifare component. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                                 /**< Pointer to the parameter structure of the KeyStore layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsEnc;                                /**< Pointer to the parameter structure of the Crypto layer for encryption. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams;                                /**< Pointer to the parameter structure of the CryptoRng layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams;                                      /**< Pointer to the HAL parameters structure. */
    VAR(uint8, ANFCRL_VAR) bSessionKey[24];                                    /**< Session key for this authentication */
    VAR(uint8, ANFCRL_VAR) bKeyNo;                                             /**< key number against which this authentication is done */
    VAR(uint8, ANFCRL_VAR) bIv[16];                                            /**< Max size of IV can be 16 bytes */
    VAR(uint8, ANFCRL_VAR) bAuthMode;                                          /**< Authenticate (0x0A), AuthISO (0x1A), AuthAES (0xAA) */
    VAR(uint8, ANFCRL_VAR) pAid[3];                                            /**< Aid of the currently selected application */
    VAR(uint8, ANFCRL_VAR) bCryptoMethod;                                      /**< DES,3DES, 3K3DES or AES */
    VAR(uint8, ANFCRL_VAR) bWrappedMode;                                       /**< Wrapped APDU mode. All native commands need to be sent wrapped in ISO 7816 APDUs. */
    VAR(uint16, ANFCRL_VAR) wCrc;                                              /**< 2 Byte CRC initial value in Authenticate mode. */
    VAR(uint32, ANFCRL_VAR) dwCrc;                                             /**< 4 Byte CRC initial value in 0x1A, 0xAA mode. */
    VAR(uint16, ANFCRL_VAR) wAdditionalInfo;                                   /**< Specific error codes for MIFARE DESFire generic errors. */
    VAR(uint16, ANFCRL_VAR) wPayLoadLen;                                       /**< Amount of data to be read. Required for Enc read to verify CRC. */
    VAR(uint8, ANFCRL_VAR) bLastBlockBuffer[16];                               /**< Buffer to store last Block of encrypted data in case of chaining. */
    VAR(uint8, ANFCRL_VAR) bLastBlockIndex;                                    /**< Last Block Buffer Index. */
} phalMfdf_Sw_DataParams_t;

/**
 * end of group phalMfdf_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_MFDF_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHAL_MFDF_SW

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
* \addtogroup phalMfdf_Sw Component : Software
* \ingroup phalMfdf
* \brief Software implementation of the MIFARE DESFire(R) EV1 commands 
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Sw_Init(
                            P2VAR(phalMfdf_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                            VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,             /**< [In] Specifies the size of the data parameter structure */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,            /**< [In] Pointer to a palMifare component context. */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,             /**< [In] Pointer to Key Store data parameters. */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParamsEnc,            /**< [In] Pointer to a Crypto component context for encryption. */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,            /**< [In] Pointer to a CryptoRng component context. */
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams                   /**< [In] Pointer to the HAL parameters structure. */
                            );

/**
 * end of group phalMfdf_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_MFDF_SW */



#ifdef NXPBUILD__PHAL_MFDF

/** 
* \addtogroup phalMfdf MIFARE DESFire (R)
* @{
*/

/**
* \name PICC level Commands 
*/
/*@{*/
#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phalMfdf/src/Sw/phalMfdf_Sw.h"
#endif /* NXPRDLIB_REM_GEN_INTFS */
#ifndef NXPRDLIB_REM_GEN_INTFS /* Without optimization */

#define ANFCRL_START_SEC_CODE
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
/**
* \brief Creates new applications on the PICC
*
* bOption value can be \n
* \li 01 meaning wISOFileId is supplied \n
* \li 02 meaning pISODFName is present \n
* \li 03 meaning both wISOFileId and pISODFName are present \n
* \li 00 meaning both not present
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateApplication(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layers param structure */
                                      VAR(uint8, ANFCRL_VAR) bOption,          /**< [In] Option parameter. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid,           /**< [In] array of 3 bytes. */
                                      VAR(uint8, ANFCRL_VAR) bKeySettings1,    /**< [In] 1 byte. */
                                      VAR(uint8, ANFCRL_VAR) bKeySettings2,    /**< [In] 1 byte. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,     /**< [In] 2 bytes ISO File ID. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISODFName,     /**< [In] 1 to 16 Bytes. Can also be NULL. */
                                      VAR(uint8, ANFCRL_VAR) bISODFNameLen     /**< [In] Size of pISODFName if that is present. */
                                      );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0

/**
* \brief Permanently deactivates applications on the PICC
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_DeleteApplication(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAid        /**< [In] 3 byte array. LSB First. */
                                      );

/**
* \brief Returns application identifiers of all applications on the PICC
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetApplicationIDs(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAidBuff,   /**< [Out] should be = 96B. (3u * 28U) */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumAid     /**< [Out] Number of AIDs read. */
                                      );

/**
* \brief Returns the Dedicated File(DF) names
*
* \remarks
* The pDFBuffer will be filled with 3 byte AID + 2 byte ISO Fid + one DF Name
* at a time.If there are more DFs, then status PH_ERR_SUCCESS_CHAINING is returned.
* The caller should call this again with bOption = PH_EXCHANGE_RXCHAINING.
*
* CAUTION: This should not be called with AES or ISO authentication
* DOING SO WILL DAMAGE THE MIFARE DESFire IC-based contactless card
* \n
* bOption can be one of \n
* \li #PH_EXCHANGE_DEFAULT \n
* \li #PH_EXCHANGE_RXCHAINING
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_SUCCESS_CHAINING More DF Names to be returned
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetDFNames(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layers param structure. */
                               VAR(uint8, ANFCRL_VAR) bOption,         /**< [In] PH_EXCHANGE_DEFAULT or PH_EXCHANGE_RXCHAINING. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFBuffer,     /**< [Out] One DF Name at a time. Should be 21(3u+2+16U) bytes long. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bDFInfoLen     /**< [Out] The size of the DF info returned in this frame. */
                               );

#endif 
#endif /* NXPBUILD__PH_NDA_MFDF */

/**
* \brief Selects one particular application on the PICC for
* further access
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_SelectApplication(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAppId        /**< [In] 3 byte AppId. LSB First. */
                                      );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0

/**
* \brief Releases the PICC user memory
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_FormatPICC(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams   /**< [In] Pointer to this layers param structure. */
                               );

#endif
#endif /* NXPBUILD__PH_NDA_MFDF */

/**
* \brief Returns manufacturing related data of the PICC
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetVersion(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVerInfo   /**< [Out] 28bytes of version info. User has to parse this. */
                               );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0
/**
* \brief Returns free memory available on the PICC
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_FreeMem(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMemInfo   /**< [Out] 3 bytes memory info. LSB first. */
                               );

/**
* \brief Configures the card and pre personalized the card with a key, defines
* if the UID or the random ID is sent back during communication setup and
* configures the ATS string.
*
* \remarks
* bOption can be one of \n
* \li #PHAL_MFDF_SET_CONFIG_OPTION1 \n
* \li #PHAL_MFDF_SET_CONFIG_OPTION2 \n
* \li #PHAL_MFDF_SET_CONFIG_OPTION3 \n
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_SetConfiguration(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers param structure. */
                                     VAR(uint8, ANFCRL_VAR) bOption,       /**< [In] Option parameter. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,       /**< [In] max predictable is 24 bytes + 1 byte for
                                                            option 0x01. Minimum size is 1 byte for option 0x00
                                                            Unspecified size for option 0x02, if ATS is
                                                            set longer than 16 bytes. */
                                     VAR(uint8, ANFCRL_VAR) bDataLen       /**< [In] 8, 16 or 24 bytes. */
                                     );

/**
* \brief Returns the Unique ID of the PICC
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetCardUID(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid       /**< [Out] UID of the card. Buffer size should be 7 bytes. */
                               );

#endif 
#endif /* NXPBUILD__PH_NDA_MFDF */

/*@}*/

/**
* \name Application level Commands 
*/
/*@{*/

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0
/**
* \brief Returns the file IDs of all active files within the
* currently selected application
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetFileIDs(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,      /**< [Out] size = 32 bytes. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bNumFid    /**< [Out] Number of fidS read. */
                               );

/**
* \brief Get the ISO File IDs.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetISOFileIDs(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFidBuffer, /**< [Out] size = 64 bytes. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bNumFid     /**< [Out] Number of fidS read. */
                                  );

/**
* \brief Get information on the properties of a specific file
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetFileSettings(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                                    VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] file number. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFSBuffer,    /**< [Out] size = 17 bytes. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bBufferLen    /**< [Out] size of data put in pFSBuffer. */
                                    );

/**
* \brief Changes the access parameters of an existing file
* \remarks
* bOption can be one of \n
* \li #PHAL_MFDF_COMMUNICATION_ENC OR \n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
*
* bCommSett can be one of \n
* \li #PHAL_MFDF_COMMUNICATION_ENC OR \n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN or \n
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ChangeFileSettings(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layers param structure. */
                                       VAR(uint8, ANFCRL_VAR) bOption,         /**< [In] Indicates whether the settings to be sent enciphered or plain. */
                                       VAR(uint8, ANFCRL_VAR) bFileNo,         /**< [In] file number. */
                                       VAR(uint8, ANFCRL_VAR) bCommSett,       /**< [In] new communication settings for the file. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights  /**< [In] 2 byte access rights. */
                                       );

#endif
#endif /* NXPBUILD__PH_NDA_MFDF */

/**
* \brief Creates files for storage of plain unformatted user data within
* an existing application on the PICC
*
* \remarks
* If bOption==1U, it means pIsoFileId is present and is valid.
* If bOption=0, it means pIsoFileId is not present. \n
*
* Communication option (bCommSett) Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateStdDataFile(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layers param structure. */
                                      VAR(uint8, ANFCRL_VAR) bOption,          /**< [In] option parameter. 0x00 means wISOFileId is not provided. 0x01 means wISOFileId is provided and is valid */
                                      VAR(uint8, ANFCRL_VAR) bFileNo,          /**< [In] file number. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,     /**< [In] ISO File ID. */
                                      VAR(uint8, ANFCRL_VAR) bCommSett,        /**< [In] communication settings. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,  /**< [In] 2 byte access rights. Sent LSB first to PICC. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize       /**< [In] 3bytes. Sent LSB first to PICC. */
                                      );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0

/**
* \brief Creates files for the storage of plain unformatted user data within
* an existing application, additionally supporting the feature of an integrated
* backup mechanism.
*
* \remarks
* If bOption==1U, it means pIsoFileId is present and is valid.
* If bOption=0, it means pIsoFileId is not present. \n
*
* Communication option (bCommSett) Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateBackupDataFile(
                                         P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layers param structure. */
                                         VAR(uint8, ANFCRL_VAR) bOption,           /**< [In] option parameter. 0x00 means wISOFileId is not provided. 0x01 means wISOFileId is provided and is valid. */
                                         VAR(uint8, ANFCRL_VAR) bFileNo,           /**< [In] file number. */
                                         P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pISOFileId,      /**< [In] ISO File ID. */
                                         VAR(uint8, ANFCRL_VAR) bCommSett,         /**< [In] communication settings. */
                                         P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,   /**< [In] 2 byte access rights. Sent LSB first to PICC. */
                                         P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFileSize        /**< [In] 3bytes. Sent LSB first to PICC. */
                                         );

/**
* \brief CreateValueFile
*
* Creates files for the storage and manipulation of 32bit
* signed integer values within an existing application on the PICC.
* User provides the entire information in the valInfo buffer.
*
* Communication option (bCommSett) Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* bLimitedCredit values are one or combination of the following: \n
* \li #PHAL_MFDF_ENABLE_LIMITEDCREDIT
* \li #PHAL_MFDF_ENABLE_FREE_GETVALUE
* OR can be set to zero if none of above are desired.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateValueFile(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layers param structure. */
                                    VAR(uint8, ANFCRL_VAR) bFileNo,            /**< [In] file number. */
                                    VAR(uint8, ANFCRL_VAR) bCommSett,          /**< [In] communication settings. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,    /**< [In] 2 byte access rights. Sent LSB first to PICC. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLowerLmit,       /**< [In] 4 byte Lower limit value. Sent LSB first to PICC. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUpperLmit,       /**< [In] 4 byte Upper limit value. Sent LSB first to PICC. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue,           /**< [In] 4 byte Value. Sent LSB first to PICC. */
                                    VAR(uint8, ANFCRL_VAR) bLimitedCredit      /**< [In] Limited Credit and free getvalue setting. */
                                    );

/**
* \brief Creates files for multiple storage of structural similar
* data, for example for loyalty programs within an existing application.
* Once the file is filled, further writing is not possible unless it is
* cleared.
*
* \remarks
* If bOption==1U, it means pIsoFileId is present and is valid.
* If bOption==0U, it means pIsoFileId is not present. \n
*
* Communication option (bCommSett) Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateLinearRecordFile(
                                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layers param structure */
                                          VAR(uint8, ANFCRL_VAR) bOption,          /**< [In] Indicates ISO file ID is present or not. */
                                          VAR(uint8, ANFCRL_VAR) bFileNo,         /**< [In] Linear record file Number. */
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsoFileId,     /**< [In] 2 Byte IsoFileId. Sent LSB first to PICC. */
                                          VAR(uint8, ANFCRL_VAR) bCommSett,        /**< [In] communication settings. */
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights,  /**< [In] 2 byte access rights. Sent LSB first to PICC. */
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize,    /**< [In] 3 byte Record Size. Sent LSB first to PICC. */
                                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec     /**< [In] 3 byte Max Number of Records. Sent LSB first to PICC. */
                                          );

/**
* \brief Creates files for multiple storage of structural similar
* data, for example for logging transactions, within an existing application.
* Once the file is filled, the PICC automatically over writes the oldest record
* with the latest written one.
*
* \remarks
* If bOption==1U, it means pIsoFileId is present and is valid.
* If bOption==0U, it means pIsoFileId is not present. \n
*
* Communication option (bCommSett) Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CreateCyclicRecordFile(
                                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layers param structure */
                                           VAR(uint8, ANFCRL_VAR) bOption,         /**< [In] Indicates ISO file ID is present or not. */
                                           VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] Linear record File No. */
                                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsoFileId,    /**< [In] 2 Byte IsoFileId. Sent LSB first to PICC. */
                                           VAR(uint8, ANFCRL_VAR) bCommSett,       /**< [In] communication settings. */
                                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAccessRights, /**< [In] 2 byte access rights. Sent LSB first to PICC */
                                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecordSize,   /**< [In] 2 byte Record Size. Sent LSB first to PICC */
                                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMaxNoOfRec    /**< [In] 3 byte Max Number of Records. Sent LSB first to PICC */
                                          );

/**
* \brief Permanently deactivates a file within the file directory of the
* currently selected application.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_DeleteFile(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                               VAR(uint8, ANFCRL_VAR) bFileNo      /**< [In] 1 byte file number. */
                               );

#endif
#endif /* NXPBUILD__PH_NDA_MFDF */

/*@}*/

/**
* \name Data Manipulation Commands 
*/
/*@{*/

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0
/**
* \brief Reads data from standard data files or backup data files
*
* \remarks
*
* Chaining upto the size of the HAL Rx buffer is handled within this function.
* If more data is to be read, the user has to call this function again with
* bOption = PH_EXCHANGE_RXCHAINING | [one of the communication options below]
*
* \c Communication option (bOption) can be one of:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
* \li #PH_EXCHANGE_RXCHAINING | #PHAL_MFDF_COMMUNICATION_ENC
* (or OR'd with other two options when re-calling the API if PHAL_MFDF_INFO_MOREDATA is
* received)
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_SUCCESS_CHAINING indicating more data to be read.
* \retval Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ReadData(
                             P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers param structure. */
                             VAR(uint8, ANFCRL_VAR) bOption,       /**< [In] Is either plain or encrypted or MAC'd. */
                             VAR(uint8, ANFCRL_VAR) bFileNo,       /**< [In] 1 byte file number. */
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,     /**< [In] 3 bytes offset. LSB First. */
                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLength,     /**< [In] 3 bytes. length of data to be read. If 00, entire file will be read. */
                             P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata,   /**< [Out] Pointer to HAL Rx buffer returned back to user. */
                             P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen  /**< [Out] Pointer to Length of RxData. */
                             );

/**
* \brief Writes data to standard data files or backup data files
*
* \remarks
* Implements chaining to the card.
*
* \c Communication option (bCommOption) can be one of:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
#endif
#endif /* NXPBUILD__PH_NDA_MFDF */

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_WriteData(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                              VAR(uint8, ANFCRL_VAR) bCommOption,  /**< [In] Communication Mode. Plain, Mac'd or encrypted. */
                              VAR(uint8, ANFCRL_VAR) bFileNo,      /**< [In] 1 byte file number. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,    /**< [In] 3 bytes offset. LSB First. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxData,    /**< [in] Data to be written. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen  /**< [in] 3 bytes. length of data to be written. */
                              );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0
/**
* \brief Reads the currently stored value from value files.
*
* Communication option  Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetValue(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
        VAR(uint8, ANFCRL_VAR) bCommOption,    /**< [In] Communication option. */
        VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] 1 byte file number. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue        /**< [Out] 4 Byte array to store the value read out. LSB First. */
        );

/**
* \brief Increases a value stored in a Value File
*
* Communication option  Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Credit(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers param structure. */
                           VAR(uint8, ANFCRL_VAR) bCommOption, /**< [In] Communication option. */
                           VAR(uint8, ANFCRL_VAR) bFileNo,     /**< [In] 1 byte file number. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue     /**< [In] 4 byte value array. LSB first. */
                           );

/**
* \brief Decreases a value stored in a Value File
*
* Communication option  Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Debit(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                          VAR(uint8, ANFCRL_VAR) bCommOption,    /**< [In] communication option. Plain, Mac'd or encrypted. */
                          VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] 1 byte file number. */
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue        /**< [In] 4 byte value array. LSB first. */
                          );

/**
* \brief Allows a limited increase of a value stored in a Value File
* without having full credit permissions to the file.
*
* Communication option  Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_LimitedCredit(
                          P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,    /**< [In] Pointer to this layers param structure. */
                          VAR(uint8, ANFCRL_VAR) bCommOption,   /**< [In] communication option. Plain, Mac'd or encrypted. */
                          VAR(uint8, ANFCRL_VAR) bFileNo,       /**< [In] 1 byte file number. */
                          P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pValue       /**< [In] 4 byte value array. LSB first. */
                          );

/**
* \brief Writes data to a record in a Cyclic or Linear Record File.
*
* \remarks
* Implements chaining to the card.
* The data provided on pData will be chained to the card
* by sending data upto the frame size of the MIFARE DESFire PICC, at a time.
*
* Communication option  Possible Values are:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_WriteRecord(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                                VAR(uint8, ANFCRL_VAR) bCommOption,    /**< [In] Communication option. Plain, Mac'd or enc. */
                                VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] 1 byte file number. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,      /**< [In] 3 bytes offset. LSB First. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,        /**< [In] data to be written. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen      /**< [In] 3 bytes. length of data to be written. */
                                );

/**
* \brief Reads out a set of complete records from a Cyclic or Linear Record File.
*
* \remarks
* The read records command reads and stores data in the rxbuffer upto the rxbuffer size before returning
* to the user. The rxbuffer is configured during the HAL init and this is specified by the user.
*
* Chaining upto the size of the HAL Rx buffer is handled within this function.
* If more data is to be read, the user has to call this function again with
* bCommOption = PH_EXCHANGE_RXCHAINING | [one of the communication options below]
*
* \c Communication option (bCommOption) can be one of:\n
* \li #PHAL_MFDF_COMMUNICATION_PLAIN
* \li #PHAL_MFDF_COMMUNICATION_ENC
* \li #PHAL_MFDF_COMMUNICATION_MACD
* \li #PH_EXCHANGE_RXCHAINING | #PHAL_MFDF_COMMUNICATION_ENC
* (or OR'd with other two options when re-calling the API if PH_ERR_SUCCESS_CHAINING is
* received)
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_SUCCESS_CHAINING indicating more data to be read.
* \retval Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ReadRecords(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                                VAR(uint8, ANFCRL_VAR) bCommOption,    /**< [In] communication option. */
                                VAR(uint8, ANFCRL_VAR) bFileNo,        /**< [In] 1 byte file number */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOffset,      /**< [In] 3 bytes offset to the record. LSB First. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumRec,      /**< [In] 3 bytes LSB first. Number of records to be read. If 0x00 00 00, then all the records are read. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRecSize,     /**< [In] Record size. 3Bytes LSB first. */
                                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxdata,    /**< [Out] pointer to the HAL buffer that stores the read data. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxdataLen   /**< [Out] number of bytes read (= number of records read * size of record). */
                                );

/**
* \brief Resets a Cyclic or Linear Record File.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ClearRecordFile(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers param structure. */
                                    VAR(uint8, ANFCRL_VAR) bFileNo     /**< [In] 1 byte file number. */
                                    );

/**
* \brief Validates all previous write access' on Backup Data files, value
* files and record files within one application.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_CommitTransaction(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams    /**< [In] Pointer to this layers param structure. */
                                      );

/**
* \brief Invalidates all previous write access' on Backup Data files, value
* files and record files within one application.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_AbortTransaction(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layers param structure. */
                                     );
#endif /**/
#endif /* NXPBUILD__PH_NDA_MFDF */

/*@}*/

/**
* \name ISO 7816 COMMANDS 
*/
/*@{*/

/**
* \brief ISO Select
*
* \remarks
* bSelector = 0x00 => Selection by 2 byte file Id. \n
* bSelector = 0x02 => Select EF under current DF. Fid = EF id \n
* bSelector = 0x04 => Selection by DF Name. DFName and len is then valid \n
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoSelectFile(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers param structure. */
                                  VAR(uint8, ANFCRL_VAR) bOption, /**< FCI is returned. If 0x0C no FCI returned. */
                                  VAR(uint8, ANFCRL_VAR) bSelector, /**< [In] bSelector equals either 0x00 or 0x02 or 0x04. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFid,       /**< [In] two byte file id. Send LSB first. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,    /**< [In] DFName upto 16 bytes. valid only when bOption = 0x04. */
                                  VAR(uint8, ANFCRL_VAR) bDFnameLen,   /**< [In] Length of DFName string provided by the user. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppFCI,     /**< [Out] File control information. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwFCILen   /**< [Out] Length of FCI returned. */
                                  );

/**
* \brief ISO Read Binary
* \c wOption can be one of:\n
* \li #PH_EXCHANGE_DEFAULT
* \li #PH_EXCHANGE_RXCHAINING
*
* If status of #PH_ERR_SUCCESS_CHAINING is returned
* Recall this function with wOption PH_EXCHANGE_RXCHAINING to
* get remaining data.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_SUCCESS_CHAINING operation success with chaining.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoReadBinary(
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to this layers param structure. */
                                  VAR(uint16, ANFCRL_VAR) wOption,         /**< [In] #PH_EXCHANGE_DEFAULT or #PH_EXCHANGE_RXCHAINING. */
                                  VAR(uint8, ANFCRL_VAR) bOffset,          /**< [In] Offset from where to read. */
                                  VAR(uint8, ANFCRL_VAR) bSfid,            /**< [In] Short ISO File Id.
                                                                      Bit 7 should be 1 to indicate Sfid is supplied.
                                                                      Else it is treated as MSB of 2Byte offset. */
                                  VAR(uint8, ANFCRL_VAR) bBytesToRead,     /**< [In] number of bytes to read. If 0, then entire file to be read. */
                                  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,    /**< [Out] buffer where the read bytes will be stored. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead     /**< [Out] number of bytes read. */
                                  );

/**
* \brief Iso Update Binary
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoUpdateBinary(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers param structure. */
                                    VAR(uint8, ANFCRL_VAR) bOffset,    /**< [In] Offset from where to write. */
                                    VAR(uint8, ANFCRL_VAR) bSfid,      /**< [In] Short ISO File Id.
                                                        Bit 7 should be 1 to indicate Sfid is supplied
                                                        Else it is treated as MSB of 2Byte offset. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,    /**< [In] data to be written. */
                                    VAR(uint8, ANFCRL_VAR) bDataLen    /**< [In] number of bytes to write. */
                                    );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0

/**
* \brief Iso Read Records
*
* \c wOption can be one of:\n
* \li #PH_EXCHANGE_DEFAULT
* \li #PH_EXCHANGE_RXCHAINING
*
* If status of #PH_ERR_SUCCESS_CHAINING is returned
* Recall this function with wOption PH_EXCHANGE_RXCHAINING to
* get remaining data.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoReadRecords(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                     /**< [In] Pointer to this layers param structure. */
        VAR(uint16, ANFCRL_VAR) wOption,                       /**< [In] #PH_EXCHANGE_DEFAULT or #PH_EXCHANGE_RXCHAINING. */
        VAR(uint8, ANFCRL_VAR) bRecNo,                         /**< [In] Record to read / from where to read. */
        VAR(uint8, ANFCRL_VAR) bReadAllFromP1,                 /**< [In] Whether to read all records from P1 or just one. */
        VAR(uint8, ANFCRL_VAR) bSfid,                          /**< [In] Short ISO File Id bits 0..4 only code this value. */
        VAR(uint8, ANFCRL_VAR) bBytesToRead,                   /**< [In] number of bytes to read. Multiple of record size. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                   /**< [Out] buffer where the read bytes will be stored. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pBytesRead                   /**< [Out] number of bytes read. */
        );

/**
* \brief Iso Append record
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoAppendRecord(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                                    VAR(uint8, ANFCRL_VAR) bSfid,          /**< [In] Short Iso File Id bits 0..4 only code this value. Either 0 or sfid. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,        /**< [In] data to write. */
                                    VAR(uint8, ANFCRL_VAR) bDataLen        /**< [In] number of bytes to write. */
                                    );

/**
* \brief GetChallenge
*
* \remarks
*
* THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
*
* Returns the random number from the PICC. Size depends on the key type
* referred by wKeyNo and wKeyVer
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoGetChallenge(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers param structure. */
                                    VAR(uint16, ANFCRL_VAR) wKeyNo,    /**< [In] Key number in key store. */
                                    VAR(uint16, ANFCRL_VAR) wKeyVer,   /**< [In] Key version in key store. */
                                    VAR(uint8, ANFCRL_VAR) bLe,        /**< [In] Length of expected challenge RPICC1. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRPICC1   /**< [Out] RPICC1 returned from PICC. */
                                    );

/**
* \brief Iso External Authenticate
*
* \remarks
*
* THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
*
* pInput should have \n
* \li Reference to crypto algorithm - 1 Byte 00 => context defined, 02=>2K3DES, 04=>3k3DES, 09=>AES128
* \li Card master key flag - 1 Byte:  0x00 if card master key, 0x01 otherwise.
* \li key number on card - 1 Byte: 0x0 to 0xD
* \li length of random number : 1 Byte
* \li Random number generated by PCD : 8 or 16 bytes. Not required for Sam non X mode.
* \li Random number returned by GetChallenge command : 8 Bytes or 16 Bytes
* \li key number : 2 bytes
* \li key version : 2 bytes
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoExternalAuthenticate(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers param structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,   /**< [In] Input data. */
    VAR(uint8, ANFCRL_VAR) bInputLen,  /**< [In] Length of pInput. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut, /**< [Out] Returns Rnd number PCD2 in sam non x mode. Nothing in S/W mode. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen   /**< [Out] Length of data returned in pDataOut. */
    );


/**
* \brief Iso Internal Authenticate
*
* \remarks
*
* THIS COMMAND IS NOT SUPPORTED IN SAM-X Configuration.
*
* pInput should have \n
* \li Reference to crypto algorithm - 1 Byte. 02 = 2kDES, 03 = 3k3des, 09=AES, 00 = context defined.
* \li Card master key flag - 1 Byte:  0x00 if card master key, 0x01 otherwise.
* \li key number on card - 1 Byte: 0x0 to 0xD
* \li length of random number : 1 Byte
* \li Random number Rpcd2 : 8 Bytes or 16 Bytes
* \li key number : 2 bytes
* \li key version : 2 bytes
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoInternalAuthenticate(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers param structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInput,   /**< [In] Input data. */
    VAR(uint8, ANFCRL_VAR) bInputLen,  /**< [In] Length of pInput. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataOut, /**< [Out] RRPICC2||RPCD2 after decryption in S/W mode. Nothing in Sam non x mode. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutLen   /**< [Out] Length of data returned in pDataOut. */
    );

/**
* \brief Perform Iso authentication GetChallenge, External Authenticate &
* Internal Authenticate of a MIFARE DESFire PICC
*
* Internally performs the three pass Iso authentication by calling
* GetChallenge \n
* External Authenticate \n
* Internal Authenticate \n
* Generates and stores the session key \n
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_IsoAuthenticate(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers param structure. */
                                    VAR(uint16, ANFCRL_VAR) wKeyNo,        /**< [In] MIFARE DESFire key number or SAM Key entry number. */
                                    VAR(uint16, ANFCRL_VAR) wKeyVer,       /**< [In] Key version. */
                                    VAR(uint8, ANFCRL_VAR) bKeyNoCard,     /**< [In] Key number on card. 0x0 to 0xD. */
                                    VAR(uint8, ANFCRL_VAR) bIsPICCkey      /**< [In] Is it PICC Master key? 1=YES. */
                                    );

#endif
#endif /* NXPBUILD__PH_NDA_MFDF */

/*@}*/

/**
* \name Miscellaneous functions 
*/
/*@{*/

/**
* \brief Perform a GetConfig command.
*
* \c wConfig can be one of:\n
* \li #PHAL_MFDF_ADDITIONAL_INFO
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_GetConfig(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,  /**< [In] Pointer to this layers parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wConfig,    /**< [In] Item to read. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue    /**< [Out] Read value. */
                              );

/**
* \brief Perform a SetConfig command.
*
* \c wConfig can:\n
* \li #PHAL_MFDF_ADDITIONAL_INFO
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_SetConfig(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wConfig,     /**< [In] Item to set. */
                              VAR(uint16, ANFCRL_VAR) wValue       /**< [In] Value to set. */
                              );

#ifdef NXPBUILD__PH_NDA_MFDF
#if 0

/**
* \brief Resets Authentication status.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ResetAuthStatus(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layers param structure. */
                                    );
#endif
#endif /* NXPBUILD__PH_NDA_MFDF */
/*@}*/

/**
 * end of group phalMfdf MIFARE DESFire (R)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDF_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* Without optimization */

#endif /* NXPBUILD__PHAL_MFDF */

#ifdef __cplusplus
}
#endif

#endif /* PHALMFDF_H */
