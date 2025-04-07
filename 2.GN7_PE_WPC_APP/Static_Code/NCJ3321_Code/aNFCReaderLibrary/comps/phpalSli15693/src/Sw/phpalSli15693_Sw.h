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
*   @file    phpalSli15693_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalSli15693 ISO/IEC 15693 
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
#ifndef PHPALSLI15693_SW_H
#define PHPALSLI15693_SW_H

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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli15693_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALSLI15693_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalSli15693_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALSLI15693_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalSli15693_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALSLI15693_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALSLI15693_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALSLI15693_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalSli15693_Sw.h and CDD_AnfcRL_Cfg.h are different"
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
#ifdef NXPBUILD__PHPAL_SLI15693_SW
#define ANFCRL_START_SEC_CODE
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Inventory(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint8, ANFCRL_VAR) bFlags,
                    VAR(uint8, ANFCRL_VAR) bAfi,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid
									  );
FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SendEof(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bOption,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_StayQuiet(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									  );

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Select(
                   P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
								   );

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_ResetToReady(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_Exchange(
                   P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                   VAR(uint16, ANFCRL_VAR) wOption,
                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                   VAR(uint16, ANFCRL_VAR) wTxLength,
                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
									 );

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_ActivateCard(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bOption,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_GetSerialNo(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SetSerialNo(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  VAR(uint8, ANFCRL_VAR) bUidLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_SetConfig(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    VAR(uint16, ANFCRL_VAR) wValue
									  );

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_GetConfig(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                    VAR(uint16, ANFCRL_VAR) wConfig,
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
									  );

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryRead(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bBlockNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryReadExtended(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bExtendedOptions,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
                  VAR(uint8, ANFCRL_VAR) bBlockNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryRead(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bBlockNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryReadExtended(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bExtendedOptions,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,
                  VAR(uint8, ANFCRL_VAR) bBlockNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfBlocks,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidOut,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) bUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) wLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryPageRead(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bPageNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfPages,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_FastInventoryPageRead(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                  VAR(uint8, ANFCRL_VAR) bFlags,
                  VAR(uint8, ANFCRL_VAR) bAfi,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength,
                  VAR(uint8, ANFCRL_VAR) bPageNo,
                  VAR(uint16, ANFCRL_VAR) wNoOfPages,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength
									);

FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_StayQuietPersistent(
                  P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
									);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALSLI15693_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_SLI15693_SW */

#ifdef __cplusplus
}
#endif
#endif /* PHPALSLI15693_SW_H */