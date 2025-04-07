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
*   @file    phpalFelica_Sw2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica_Sw - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalFelica Felica
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
#ifndef PHPALFELICA_SW2_H
#define PHPALFELICA_SW2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status2.h>
#include "phpalFelica_Sw_Int2.h"
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica_Sw2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_SW_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_SW_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALFELICA_SW_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalFelica_Sw2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALFELICA_SW_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalFelica_Sw2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALFELICA_SW_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALFELICA_SW_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALFELICA_SW_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalFelica_Sw2.h and CDD_AnfcRL_Cfg.h are different"
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
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_ReqC2(
                               P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                               VAR(uint8, ANFCRL_VAR) bNumTimeSlots2,
                               P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                               P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                               );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_ActivateCard2(
                                       P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2,
                                       VAR(uint8, ANFCRL_VAR) bIDmPMmLength2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,
                                       VAR(uint8, ANFCRL_VAR) bNumTimeSlots2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2
                                       );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_Exchange2(
                                   P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                   VAR(uint16, ANFCRL_VAR) wOption2,
                                   VAR(uint16, ANFCRL_VAR) wN2,  /* Number of node or block data */
                                   P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                   VAR(uint16, ANFCRL_VAR) wTxLength2,
                                   P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                   P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                   );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_SetConfig2(
                                    P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    VAR(uint16, ANFCRL_VAR) wConfig2,
                                    VAR(uint16, ANFCRL_VAR) wValue2
                                    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_GetConfig2(
                                    P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    VAR(uint16, ANFCRL_VAR) wConfig2,
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2
                                    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_GetSerialNo2(
                                      P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut2
                                      );

FUNC(phStatus_t2, ANFCRL_CODE)  phpalFelica_Sw_GetFrameInfo2(
                                        P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bFrameNum2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer2,
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus2,
                                        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen2
                                        );

FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_SetSerialNo2(
                                      P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2
                                      );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_SW_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALFELICA_SW2_H */
