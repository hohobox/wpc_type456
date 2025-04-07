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
*   @file    phpalI14443p4a_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4a_Sw_Int - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4a ISO/IEC 14443-4A
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
#ifndef PHPALI14443P4A_SW_INT_H
#define PHPALI14443P4A_SW_INT_H

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
* @file           phpalI14443p4a_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4A_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4A_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4A_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4A_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4A_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4A_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4A_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4A_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4A_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4a_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4A_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4A_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4A_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4a_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4A_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4A_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4A_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4a_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

/** HaltA Command code. */
#define PHPAL_I14443P4A_SW_HALT_CMD             0x50U

/** Rats Command code. */
#define PHPAL_I14443P4A_SW_RATS                 0xE0U

/** PPS Command code. */
#define PHPAL_I14443P4A_SW_PPSS                 0xD0U

/** PPS0 code. */
#define PHPAL_I14443P4A_SW_PPS0                 0x11U

/** ISO 14443-4 S-Block. */
#define PHPAL_I14443P4A_SW_S_BLOCK              0xC0U

/** ISO 14443-4 S-Block RFU bits. */
#define PHPAL_I14443P4A_SW_S_BLOCK_RFU_BITS     0x02U

/** Bit within PCB which signals presence of CID byte .*/
#define PHPAL_I14443P4A_SW_PCB_CID_FOLLOWING    0x08U

/** Bits within PCB which signal a DESELECT command. */
#define PHPAL_I14443P4A_SW_PCB_DESELECT         0x00U

/** Activation FTW in microseconds. */
#define PHPAL_I14443P4A_SW_FWT_ACTIVATION_US    5286U

/** Position of T0 within ATS. */
#define PHPAL_I14443P4A_SW_ATS_T0               1U

/** Bit which signals TA(1) presence. */
#define PHPAL_I14443P4A_SW_ATS_TA1_PRESENT      0x10U

/** Bit which signals TB(1) presence. */
#define PHPAL_I14443P4A_SW_ATS_TB1_PRESENT      0x20U

/** Bit which signals TC(1) presence. */
#define PHPAL_I14443P4A_SW_ATS_TC1_PRESENT      0x40U

/** Bit within TC(1) which signals NAD support. */
#define PHPAL_I14443P4A_SW_ATS_TC1_NAD_SUPPORT  0x01U

/** Bit within TC(1) which signals CID support. */
#define PHPAL_I14443P4A_SW_ATS_TC1_CID_SUPPORT  0x02U

/** FWI default value. */
#define PHPAL_I14443P4A_SW_FWI_DEFAULT          0x04U

/** SFGI default value. */
#define PHPAL_I14443P4A_SW_SFGI_DEFAULT         0x00U

/** FSCI default value. */
#define PHPAL_I14443P4A_SW_FSCI_DEFAULT         0x02U

/** FTW min in microseconds. */
#define PHPAL_I14443P4A_SW_FWT_MIN_US           303U

/** Wait time for halt command in microseconds. */
#define PHPAL_I14443P4A_SW_HALT_TIME_US         1100U

/** Time extension in microseconds for all commands.  */
#define PHPAL_I14443P4A_SW_EXT_TIME_US          60U

/** The maximum allowed FSDI/FSCI value as per ISO and EMVCo v3.0 */
#define PHPAL_I14443P4A_FRAMESIZE_MAX           8U

/** The minimum FSDI value as per EMVCo v3.0 - Requirements 5.9 */
#define PHPAL_I14443P4A_EMVCO_FRAMESIZE_MIN     8U

/* Delta SFGT as per EMVCo v3.0 and NFC Forum Digital Protocol v1.1 */
#define PHPAL_I14443P4A_DELTA_SFGT_US           29U

/** Delta TPCD max in microseconds */
#define PHPAL_I14443P4A_SW_DELTA_TPCD_US_MAX    16400U

/** Delta TPCD minimum in microseconds */
#define PHPAL_I14443P4A_SW_DELTA_TPCD_US_MIN    0U

/** Delta frame wait time (FWT) in microseconds = 49152/fc = 3625us.
 * Providing additional 15us delay for NFC Forum compliance.
 * */
#define PHPAL_I14443P4A_SW_DELTA_FWT_US         3640U

/** Delta TPCD used for exchange (in microseconds) */
#define PHPAL_I14443P4A_SW_DELTA_TPCD_US        1000U

/**
 * end of group ph_Private (Private definitions)
 * @}
 */

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

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4A_SW_INT_H */
