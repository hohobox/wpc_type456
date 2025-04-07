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
*   @file    phpalI14443p3b_Sw2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p3b - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p3b ISO/IEC 14443-3B
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


#ifndef PHPALI14443P3B_SW2_H
#define PHPALI14443P3B_SW2_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status2.h>
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b_Sw2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_SW_VENDOR_ID2                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_SW_MODULE_ID2                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION2     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION2     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION2  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3B_SW_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3b_Sw2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3b_Sw2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3B_SW_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3b_Sw2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define PHPAL_I14443P3B_NUMSLOTS_12      0x00U   /**< Use 1 slot for anti-collision. */
#define PHPAL_I14443P3B_NUMSLOTS_22      0x01U   /**< Use 2 slots for anti-collision. */
#define PHPAL_I14443P3B_NUMSLOTS_42      0x02U   /**< Use 4 slots for anti-collision. */
#define PHPAL_I14443P3B_NUMSLOTS_82      0x03U   /**< Use 8 slots for anti-collision. */
#define PHPAL_I14443P3B_NUMSLOTS_162     0x04U   /**< Use 16 slots for anti-collision. */

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
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetConfig2(
                                    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In]  */
                                    VAR(uint16, ANFCRL_VAR) wValue2      /**< [In]  */
                                   );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetConfig2(
                                    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In]  */
                                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2     /**< [In]  */
                                   );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_RequestB2(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      VAR(uint8, ANFCRL_VAR) bNumSlots2,
                                      VAR(uint8, ANFCRL_VAR) bAfi2,
                                      VAR(uint8, ANFCRL_VAR) bExtAtqb2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                      );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_WakeUpB2(
                                     P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                     VAR(uint8, ANFCRL_VAR) bNumSlots2,
                                     VAR(uint8, ANFCRL_VAR) bAfi2,
                                     VAR(uint8, ANFCRL_VAR) bExtAtqb2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                     );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SlotMarker2(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                        VAR(uint8, ANFCRL_VAR) bSlotNumber2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2
                                        );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_HaltB2(
                                   P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2
                                   );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Attrib2(
                                    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
                                    VAR(uint8, ANFCRL_VAR) bAtqbLen2,
                                    VAR(uint8, ANFCRL_VAR) bFsdi2,
                                    VAR(uint8, ANFCRL_VAR) bCid2,
                                    VAR(uint8, ANFCRL_VAR) bDri2,
                                    VAR(uint8, ANFCRL_VAR) bDsi2,
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2
                                    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_ActivateCard2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2,
    VAR(uint8, ANFCRL_VAR) bPupiLength2,
    VAR(uint8, ANFCRL_VAR) bNumSlotIndex2,
    VAR(uint8, ANFCRL_VAR) bAfi2,
    VAR(uint8, ANFCRL_VAR) bExtAtqb2,
    VAR(uint8, ANFCRL_VAR) bFsdi2,
    VAR(uint8, ANFCRL_VAR) bCid2,
    VAR(uint8, ANFCRL_VAR) bDri2,
    VAR(uint8, ANFCRL_VAR) bDsi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMbli2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable
    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_Exchange2(
                                      P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                      VAR(uint16, ANFCRL_VAR) wOption2,
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
                                      VAR(uint16, ANFCRL_VAR) wTxLength2,
                                      P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,
                                      P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
                                      );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetSerialNo2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetSerialNo2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPupi2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_SetHigherLayerInf2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,
    VAR(uint16, ANFCRL_VAR) wTxLength2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    VAR(uint16, ANFCRL_VAR) wRxBufSize2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetHigherLayerResp2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2
    );

FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p3b_Sw_GetProtocolParams2(
    P2VAR(phpalI14443p3b_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci2
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_SW_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P3B_SW_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3B_SW2_H */
