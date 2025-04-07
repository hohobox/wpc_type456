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
*   @file    phpalFelica_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica_Sw_Int - PAL API usage in common use cases.
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
#ifndef PHPALFELICA_SW_INT_H
#define PHPALFELICA_SW_INT_H

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
* @file           phpalFelica_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALFELICA_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALFELICA_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalFelica_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALFELICA_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALFELICA_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALFELICA_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalFelica_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALFELICA_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALFELICA_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALFELICA_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalFelica_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
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

/**
* \name Felica Command Codes
*/
/*@{*/
#define PHPAL_FELICA_SW_CMD_REQC            0x00U   /**< RequestC. */
#define PHPAL_FELICA_SW_CMD_REQ_RESP        0x04U   /**< Request Response. */
#define PHPAL_FELICA_SW_CMD_REQ_SERVICE     0x02U   /**< Request Service. */
#define PHPAL_FELICA_SW_CMD_READ            0x06U   /**< Read. */
#define PHPAL_FELICA_SW_CMD_WRITE           0x08U   /**< Write. */
#define PHPAL_FELICA_SW_CMD_SEARCH_SERVICE  0x0AU   /**< Search Service Code. */
#define PHPAL_FELICA_SW_CMD_REQ_SYSTEM_CODE 0x0CU   /**< Request System Code. */
#define PHPAL_FELICA_SW_CMD_AUTH1           0x10U   /**< Authentication1. */
#define PHPAL_FELICA_SW_CMD_AUTH2           0x12U   /**< Authentication2. */
#define PHPAL_FELICA_SW_CMD_READ_SECF       0x14U   /**< Read from secure file, DES encryption. */
#define PHPAL_FELICA_SW_CMD_WRITE_SECF      0x16U   /**< Write to secure file, DES encryption. */
#define PHPAL_FELICA_SW_CMD_GET_SYS_STATUS  0x38U   /**< Get System Status. */
#define PHPAL_FELICA_SW_CMD_REQ_SPEC_VERSION 0x3CU  /**< Request Specification Version. */
#define PHPAL_FELICA_SW_CMD_RESET_MODE      0x3EU   /**< Reset Mode to mode0. */
#define PHPAL_FELICA_SW_CMD_REQ_SERVICE_V2  0x32U   /**< Request Service V2. */
#define PHPAL_FELICA_SW_CMD_AUTH1_V2        0x40U   /**< Authentication1 V2. */
#define PHPAL_FELICA_SW_CMD_AUTH2_V2        0x42U   /**< Authentication2 V2. */
#define PHPAL_FELICA_SW_CMD_READ_SECF_V2    0x44U   /**< Read from secure file V2, AES encryption. */
#define PHPAL_FELICA_SW_CMD_WRITE_SECF_V2   0x46U   /**< Write to secure file V2, AES encryption. */
#define PHPAL_FELICA_SW_CMD_UPDATE_RAND_ID  0x4CU   /**< Update Random ID, AES encryption. */

#define PHPAL_FELICA_SW_RSP_REQC            0x01U   /**< Response to RequestC. */
#define PHPAL_FELICA_SW_LEN_BYTE_SIZE       0x01U   /**< Size of Length byte in RequestC response. */
#define PHPAL_FELICA_SW_RESP_REQC_SIZE      0x01U   /**< Length of Response byte in RequestC response. */
/*@}*/

/**
* \name Flags
*/
/*@{*/
/** Error Flag. */
#define PHPAL_FELICA_SW_FLAG_ERROR      0x01U
/** Addressed Flag. */
#define PHPAL_FELICA_SW_FLAG_ADDRESSED  0x20U
/** Selected Flag. */
#define PHPAL_FELICA_SW_FLAG_SELECTED   0x10U
/*@}*/

/**
* \name Values
*/
/*@{*/
/** Stored UID is valid. */
#define PHPAL_FELICA_SW_IDMPMM_VALID    0x01U
/** Stored UID is not valid. */
#define PHPAL_FELICA_SW_IDMPMM_INVALID  0x00U
/** Size of one Felica Response Frame. */
#define PHPAL_FELICA_SW_RESP_FRAME_SIZE 32U
/*@}*/

/** 
* \name Timing constants
*/
/*@{*/
#define PHPAL_FELICA_SW_TIME_T_US           302U
#define PHPAL_FELICA_SW_EXT_TIME_US         500U    /**< Time extension in microseconds for all commands.  */

#define PHPAL_FELICA_SW_T_DELAY_US              2417U    /**< NFC Forum Digital Protocol Technical Specification v1.1 : Appendix A.4 */
#define PHPAL_FELICA_SW_T_TIMESLOT_US           1208U    /**< NFC Forum Digital Protocol Technical Specification v1.1 : Appendix A.4 */
#define PHPAL_FELICA_SW_T_DELTA_F_POLL_US       1U       /**< NFC Forum Digital Protocol Technical Specification v1.1 : Appendix A.4 */

#define PHPAL_FELICA_SW_TR1_48BITS_AT212_US            227U     /**< NFC Forum Digital Protocol Technical Specification v1.1 : 8.1.2 */
#define PHPAL_FELICA_SW_TR1_56BITS_AT212_US            255U
#define PHPAL_FELICA_SW_TR1_64BITS_AT212_US            302U
#define PHPAL_FELICA_SW_TR1_72BITS_AT212_US            340U

#define PHPAL_FELICA_SW_TR1_48BITS_AT424_US            114U     /**< NFC Forum Digital Protocol Technical Specification v1.1 : 8.1.2 */
#define PHPAL_FELICA_SW_TR1_56BITS_AT424_US            128U
#define PHPAL_FELICA_SW_TR1_64BITS_AT424_US            151U
#define PHPAL_FELICA_SW_TR1_72BITS_AT424_US            170U

/*@}*/

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
#endif /* PHPALFELICA_SW_INT_H */