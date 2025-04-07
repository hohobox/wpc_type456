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
*   @file  phceT4T_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR CeT4T_Sw_Int - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phceT4T NFC Forum Type 4A Card Emulation
*   @ingroup phce
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

#ifndef PHCET4T_SW_INT_H
#define PHCET4T_SW_INT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <phceT4T.h>
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phceT4T_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHCET4T_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHCET4T_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHCET4T_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHCET4T_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHCET4T_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHCET4T_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file phceT4T_Sw_Int.h and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHCET4T_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phceT4T_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file phceT4T_Sw_Int.h and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHCET4T_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phceT4T_Sw_Int.h and phceT4T_Sw_Int.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHCET4T_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHCET4T_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHCET4T_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phceT4T_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* \name Data type to send
*/
#define PHCE_SEND_NO_DATA   0x00U
#define PHCE_SEND_DATA      0x01U
#define PHCE_SEND_WTX       0x02U

/**
* \name Status Word
*/
/*@{*/
/** Unsupported class byte in CPDU */
#define PHCE_T4T_ISO7816_UNSUPPORTED_CLASS            0x6E00U
/** Unsupported Instruction byte in CPDU */
#define PHCE_T4T_ISO7816_UNSUPPORTED_INSTRUCTION      0x6D00U
/** No precise diagnosis */
#define PHCE_T4T_ISO7816_NO_PRECISE_DIAGNOSIS         0x6F00U
/** Incorrect Parameter bytes in CPDU */
#define PHCE_T4T_ISO7816_ERR_PARAMETER                0x6A86U
/** Incorrect File Name or File ID in CPDU */
#define PHCE_T4T_ISO7816_FILE_NOT_FOUND               0x6A82U
/** Unsupported function */
#define PHCE_T4T_ISO7816_UNSUPPORTED_FUNC             0x6A81U
/** Length Error */
#define PHCE_T4T_ISO7816_ERR_LENGTH                   0x6700U
/** Memory Failure */
#define PHCE_T4T_ISO7816_ERR_MEMORY                   0x6581U
/**Command incompatible with file structure */
#define PHCE_T4T_ISO7816_ERR_INCOMPATIBLE_FILE_STRUCT 0x6981U
/** Command completed */
#define PHCE_T4T_ISO7816_SUCCESS                      0x9000U
/*@}*/

/**
* \name Instruction Byte
*/
/*@{*/
/**Select Instruction*/
#define PHCE_T4T_INS_SELECT      0xA4U
/**Read Instruction*/
#define PHCE_T4T_INS_READ        0xB0U
/**Update Instruction*/
#define PHCE_T4T_INS_UPDATE      0xD6U
/*@}*/

/**
* \name Command Type
*/
/*@{*/
/**Command with a short Length*/
#define PHCE_T4T_SHORT_LEN_CMD    0x00U
/**Command with Extended Length*/
#define PHCE_T4T_EXT_LEN_CMD      0x01U
/*@}*/
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
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetCcFile(
                                    P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCcFile,
                                    VAR(uint16, ANFCRL_VAR) wCcFileId,
                                    VAR(uint16, ANFCRL_VAR) wCcFileSize,
                                    VAR(uint16, ANFCRL_VAR) wCcContentLen
                                    );

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetNdefFile(
                                      P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNdefFile,
                                      VAR(uint16, ANFCRL_VAR) wNdefFileId,
                                      VAR(uint32, ANFCRL_VAR) dwNdefFileSize,
                                      VAR(uint32, ANFCRL_VAR) dwNdefContentLen
                                      );

#ifdef NXPBUILD__PHCE_T4T_PROPRIETARY
FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_SetProprietaryFile(
                                             P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                             P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFile,
                                             VAR(uint16, ANFCRL_VAR) wFileId,
                                             VAR(uint16, ANFCRL_VAR) wFileSize,
                                             VAR(uint16, ANFCRL_VAR) wContentLen
                                             );
#endif /* NXPBUILD__PHCE_T4T_PROPRIETARY */

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_Activate(
                                   P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                   );

FUNC(void, ANFCRL_CODE) phceT4T_Sw_Int_UpdateFile(
                               P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                               VAR(uint32, ANFCRL_VAR) dwDataLen
                               );

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_Select(
                                 P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                                 VAR(uint16, ANFCRL_VAR) wRxDataLen,
                                 P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord
                                 );

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_ReadBinary(
                                     P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                                     VAR(uint16, ANFCRL_VAR) wRxDataLen,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
                                     );

FUNC(phStatus_t, ANFCRL_CODE) phceT4T_Sw_Int_UpdateBinary(
                                       P2VAR(phceT4T_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                       VAR(uint16, ANFCRL_VAR) wOption,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxData,
                                       VAR(uint16, ANFCRL_VAR) wRxDataLen,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pStatusWord,
                                       P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppTxData,
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataLen
                                       );

FUNC(void, ANFCRL_CODE) phceT4T_Sw_Int_EventPoll(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

#define ANFCRL_STOP_SEC_CODE
#if ((PHCET4T_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHCET4T_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* PHCET4T_SW_INT_H */
