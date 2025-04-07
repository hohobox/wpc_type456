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
*   @file    phacDiscLoop_Sw_Int2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR acDiscLoop - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop Discovery Loop
*   @ingroup phac
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

/** \file
* This File contains all support functions that's needed by Discovery Loop
* for performing activities defined by NFC Forum.
*/

#ifndef PHACDISCLOOP_SW_INT2_H
#define PHACDISCLOOP_SW_INT2_H

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
#include <ph_Status2.h>
#include <phNxpNfcRdLib_Config2.h>

 
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop_Sw_Int2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_SW_INT_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_SW_INT_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_INT_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file phacDiscLoop_Sw_Int2.h and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHACDISCLOOP_SW_INT_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phacDiscLoop_Sw_Int2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file phacDiscLoop_Sw_Int2.h and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHACDISCLOOP_SW_INT_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop_Sw_Int2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHACDISCLOOP_SW_INT_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHACDISCLOOP_SW_INT_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHACDISCLOOP_SW_INT_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop_Sw_Int2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
#define PHAC_DISCLOOP_POLL_MAX_NFC_TECHS_SUPPORTED2            0x05U              /**< Maximum NFC Technologies support in Poll Mode. */
#define PHAC_DISCLOOP_ACT_POLL_MAX_TECHS_SUPPORTED2            0x03U              /**< Maximum NFC Technologies support in Active Poll Mode. */

/* Time extension to support EMVCO Requirement
* Emvco: case_id TB001
* measured delay between WUPA sequence and WUPB sequence
* during polling is less than t_P_MIN = 5100 microseconds */
#define PHAC_DISCLOOP_DELTA_TP_MIN2                            200U
/**
 * Single technology detected.
 *
 * This status is used in passive poll mode when a single NFC or proprietary
 * technology is detected during technology detection stage.
 * */
#define PHAC_DISCLOOP_TECH_DETECTED2                         0x0087U

/**
 * Single device/card resolved.
 *
 * This status is used in passive poll mode when a single NFC or proprietary
 * card/device is detected during technology detection stage and the same got
 * resolved in collision resolution phase.
 * */
#define PHAC_DISCLOOP_DEVICE_RESOLVED2                       0x0089U

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef phStatus_t2 (*pphacDiscLoop_Sw_DetTechs2) 	  (P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);
typedef phStatus_t2 (*pphacDiscLoop_Sw_Reslns2)         (P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2);
typedef phStatus_t2 (*pphacDiscLoop_Sw_DeviceActivate2) (P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(uint8, ANFCRL_VAR) bIndex2);
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ListenMode2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_Stop2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_PollMode2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivePollMode2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_TechDetectActivity2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bPasPollBailOut2,
    VAR(uint8, ANFCRL_VAR) bDetectConfig2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNumOfTechsDetect2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ColsnReslnActivity2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bTechType2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_ActivateDevice2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    VAR(uint8, ANFCRL_VAR) bTechType2,
    VAR(uint8, ANFCRL_VAR) bTagIndex2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_RfcaOff_FieldOn2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Int_FieldOn2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
    );

FUNC(uint8, ANFCRL_CODE) phacDiscLoop_Sw_Int_IsValidPollStatus2(
    VAR(phStatus_t2, ANFCRL_VAR) wStatus2
    );
#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_SW_INT_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_SW_INT_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef __cplusplus
}
#endif

#endif /* PHACDISCLOOP_SW_INT2_H */

