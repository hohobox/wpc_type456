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
*   @file    phNfcLib_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib_Int - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
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

#ifndef PHNFCLIB_INT_H
#define PHNFCLIB_INT_H

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
* @file           phNfcLib_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHNFCLIB_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHNFCLIB_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phNfcLib_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHNFCLIB_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHNFCLIB_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHNFCLIB_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHNFCLIB_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHNFCLIB_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHNFCLIB_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB_PROFILES
/**
* \name FELICA error codes
*/
/*@{*/
#define PHAL_FELICA_ERR_FELICA  ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U) /**< General Felica error. */
/*@}*/

/*
 * ATQ codes
 */
#define PH_NFCLIB_ATQA_UL        0x4400U
#define PH_NFCLIB_ATQA_ULC       0x4400U
#define PH_NFCLIB_ATQA_MFC       0x0200U
#define PH_NFCLIB_ATQA_MFP_S     0x0400U
#define PH_NFCLIB_ATQA_MFP_X     0x4200U
#define PH_NFCLIB_ATQA_DESFIRE   0x4403U
#define PH_NFCLIB_ATQA_DESFIRE1  0x0403U
#define PH_NFCLIB_ATQA_JCOP      0x0400U
#define PH_NFCLIB_ATQA_MINI      0x0400U
#define PH_NFCLIB_ATQA_NPA       0x0800U

/*
 * SAK codes
 */
#define PH_NFCLIB_SAK_UL         0x00U
#define PH_NFCLIB_SAK_ULC        0x00U //ATQA and SAK for UL and ULC are same.
#define PH_NFCLIB_SAK_MINI       0x09U
#define PH_NFCLIB_SAK_MFC_1K     0x08U
#define PH_NFCLIB_SAK_MFC_4K     0x18U
#define PH_NFCLIB_SAK_MFP_2K_SL1 0x08U
#define PH_NFCLIB_SAK_MFP_4K_SL1 0x18U
#define PH_NFCLIB_SAK_MFP_2K_SL2 0x10U
#define PH_NFCLIB_SAK_MFP_4K_SL2 0x11U
#define PH_NFCLIB_SAK_MFP_2K_SL3 0x20U
#define PH_NFCLIB_SAK_MFP_4K_SL3 0x20U
#define PH_NFCLIB_SAK_DESFIRE    0x20U //0x24U
#define PH_NFCLIB_SAK_JCOP       0x28U
#define PH_NFCLIB_SAK_LAYER4     0x20U
#define PH_NFCLIB_SAK_MERGED     0x60U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/**
 * \brief NFC Felica StateMachine
 * \anchor NfcLib_StateMachine_for_Felica
 * Refer state machine for each mode defined above.
 */
typedef enum
{
    eNfcLib_Felica_IdleState = 0,
    eNfcLib_Felica_TransmitState = 1,
    eNfcLib_Felica_FinishState = 2
} phNfcLib_Felica_StateMachine_t;

/**
 * \brief NFC ISO15693 StateMachine
 * \anchor NfcLib_StateMachine_for_ISO15693
 * Refer state machine for each mode defined above.
 */
typedef enum
{
    eNfcLib_ISO15693_InitState = 0,
	eNfcLib_ISO15693_Timeout,
    eNfcLib_ISO15693_IdleState,
    eNfcLib_ISO15693_TransmitState,
    eNfcLib_ISO15693_WriteAlike,
    eNfcLib_ISO15693_FinishState
} phNfcLib_ISO15693_StateMachine_t;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

typedef phStatus_t (*pphNfcLib_Activate_Profile)(uint16_t wTechnologyMask);
typedef phStatus_t (*pphNfcLib_Deactivate_Profile)(void);
typedef phStatus_t (*pphNfcLib_Transmit)(void * const  pTxBuffer, uint16_t wTxBufferLength);

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/


/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHNFCLIB_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PH_NFCLIB_ISO_MFDF
FUNC(phStatus_t, ANFCRL_API) phNfcLib_MFDF_Transmit(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength);
#endif /* NXPBUILD__PH_NFCLIB_ISO_MFDF */

#ifdef NXPBUILD__PH_NFCLIB_FELICA
FUNC(phStatus_t, ANFCRL_API) phNfcLib_Felica_Transmit(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength);
#endif /* NXPBUILD__PH_NFCLIB_FELICA */

#ifdef NXPBUILD__PH_NFCLIB_ISO_15693
FUNC(phStatus_t, ANFCRL_API) phNfcLib_ISO15693_Transmit(
	CONSTP2VAR(void, AUTOMATIC, ANFCRL_DATA ) pTxBuffer,
	VAR(uint16_t, AUTOMATIC) wTxBufferLength);
#endif /* NXPBUILD__PH_NFCLIB_ISO_15693 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHNFCLIB_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB_PROFILES*/

#ifdef __cplusplus
}
#endif
#endif /* PHNFCLIB_INT_H */
