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
*   @file    phpalI14443p4_Sw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4 ISO/IEC 14443-4
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


#ifndef PHPALI14443P4_SW_H
#define PHPALI14443P4_SW_H

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
* @file           phpalI14443p4_Sw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_SW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_SW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4_SW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4_Sw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4_SW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4_Sw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4_SW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4_SW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4_Sw.h and CDD_AnfcRL_Cfg.h are different"
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

/* ReturnCase for Dispatcher */
typedef enum {
    INITIAL_CASE = 0,
    TXMODE_NORMAL_SWITH_TO_RXMODE               = 11,
    TXMODE_NORMAL_FINISH                        = 12,
    TXMODE_ABNORMAL_TIMEOUT_RETRY2RCV_IBLOCK    = 13,
    TXMODE_NORMAL_NEXT_TRANSMISSION             = 14,
    TXMODE_ABNORMAL_RE_TRANSMISSION             = 15,

    RXMODE_NORMAL_RECEIVING_IBLOCK              = 21,
    RXMODE_NORMAL_FINISH                        = 22,
    RXMODE_ABNORMAL_SEND_RACK_FOR_RETRY         = 23,
    RXMODE_NORMAL_SEND_RACK_FOR_RECEIVING       = 24,
    RXMODE_ABNORMAL_BUFFER_OVERFLOW             = 25,

    PROCESS_CMD_SWTX                            = 30,
    HANDLING_ERROR_PROTOCOL                     = 90,
    HANDLING_ERROR_MAX_RETRY_OCCURS             = 91,

} I14443P4_DISPATCHER_RETURNCASE_t;
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
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_SetProtocol(
                                        P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                        VAR(uint8, ANFCRL_VAR) bCidEnable,
                                        VAR(uint8, ANFCRL_VAR) bCid,
                                        VAR(uint8, ANFCRL_VAR) bNadEnable,
                                        VAR(uint8, ANFCRL_VAR) bNad,
                                        VAR(uint8, ANFCRL_VAR) bFwi,
                                        VAR(uint8, ANFCRL_VAR) bFsdi,
                                        VAR(uint8, ANFCRL_VAR) bFsci
                                        );

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_ResetProtocol(
                  P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    								);

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Deselect(
                                     P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                     );

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_PresCheck(
                                      P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
                                      );


/*
* New function non-blocking ISO Exchange.
* This function do exchange message for ISO 14443 Layer 4
*                 Not support BUFFERING OPTION
*                 TxBuffer do not exceed 256 bytes
*
* ppRxBuffer: receive buffer
*
* return         phStatus_t
*
*          PH_STATUS_INPROCESS: State machine for handling command is in progress
*          Other value as blocking return
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_Exchange(
                                     P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     VAR(uint16, ANFCRL_VAR) wOption,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,
                                     VAR(uint16, ANFCRL_VAR) wTxLength,
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
                                     );

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_SetConfig(
                                      P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      VAR(uint16, ANFCRL_VAR) wValue
                                      );

FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4_Sw_GetConfig(
                                      P2VAR(phpalI14443p4_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                      VAR(uint16, ANFCRL_VAR) wConfig,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue
                                      );


#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_SW_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4_SW_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4_SW_H */
