/*******************************************************************************
 * (c) NXP Semiconductors Bangalore / India
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
*   @file    phNxpNfcRdLib_Config.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NxpNfcRdLib_Config - NFC API usage in common use cases.
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
#ifndef PH_NXPNFCRDLIB_CONFIG_H
#define PH_NXPNFCRDLIB_CONFIG_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_NxpBuild.h>
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNxpNfcRdLib_Config.h
* @implements     DESIGN001, DESIGN002
*/
#define PHNXPNFCRDLIB_CONFIG_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHNXPNFCRDLIB_CONFIG_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHNXPNFCRDLIB_CONFIG_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHNXPNFCRDLIB_CONFIG_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHNXPNFCRDLIB_CONFIG_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHNXPNFCRDLIB_CONFIG_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHNXPNFCRDLIB_CONFIG_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHNXPNFCRDLIB_CONFIG_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHNXPNFCRDLIB_CONFIG_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phNxpNfcRdLib_Config.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHNXPNFCRDLIB_CONFIG_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHNXPNFCRDLIB_CONFIG_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHNXPNFCRDLIB_CONFIG_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNxpNfcRdLib_Config.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHNXPNFCRDLIB_CONFIG_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHNXPNFCRDLIB_CONFIG_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHNXPNFCRDLIB_CONFIG_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNxpNfcRdLib_Config.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/* Used in NFCLIB (Simplified API). */

/**< Maximum HAL Tx buffer size by allocated by Simplified API Layer. */
#ifndef PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE
#   define PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE                    300U
#endif

/**< Maximum HAL Rx buffer size by allocated by Simplified API Layer. */
#ifdef PH_NXPNFCRDLIB_CONFIG_NFC_FORUM_TEST
#define PH_NXPNFCRDLIB_CONFIG_RX_BUFFSIZE    					4400U	/**< Maximum HAL Rx buffer size by allocated by Simplified API Layer for NFC Forum testing. */
#else
#define PH_NXPNFCRDLIB_CONFIG_RX_BUFFSIZE    	 				600U	/**< Maximum HAL Rx buffer size by allocated by Simplified API Layer for ISO testing. */
#endif

#ifndef PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE
#   define PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE                 (PH_NXPNFCRDLIB_CONFIG_RX_BUFFSIZE)
#endif

#define PH_NXPNFCRDLIB_CONFIG_ATS_BUFF_LENGTH                    64U       /**< Maximum ATS response buffer length. */
#define PH_NXPNFCRDLIB_CONFIG_HCE_BUFF_LENGTH                    300U      /**< Buffer length for HCE used when UpdateBinary or Custom commands are supported. */

/* Used in Discovery Loop. */
#define PH_NXPNFCRDLIB_CONFIG_MAX_PROXIMITY_CARDS_SUPPORTED      0x01U    /**< Maximum proximity cards (Type A, Type B and Type F) detected by Discovery Loop. */
#define PH_NXPNFCRDLIB_CONFIG_MAX_VICINITY_CARDS_SUPPORTED       0x01U    /**< Maximum vicinity cards ISO15693 detected by Discovery Loop. */

/* Default guard times used in Discovery Loop and NFCLIB (Simplified API).
 * As per Nfc Forum Activity and EMVCo Specification. */
#define PH_NXPNFCRDLIB_CONFIG_TYPEA_GT                           5100U    /**< Guard time configuration for Type A poll in Micro seconds.*/
#define PH_NXPNFCRDLIB_CONFIG_TYPEB_GT                           5100U    /**< Guard time configuration for Type B poll in Micro seconds.*/
#define PH_NXPNFCRDLIB_CONFIG_TYPEF_GT                           20400U   /**< Guard time configuration for Type F poll in Micro seconds.*/
#define PH_NXPNFCRDLIB_CONFIG_B_TO_F_GT                          15300U   /**< Guard time configuration for Type F poll preceded by Type B poll. */
#define PH_NXPNFCRDLIB_CONFIG_TYPEV_GT                           5200U    /**< Guard time configuration for Type V poll in Micro seconds.*/

/* Used in Discovery Loop and NFCLIB (Simplified API) as per EMVCo Specification. */
#define PH_NXPNFCRDLIB_CONFIG_EMVCO_FIELD_OFF_DELAY_US           5100U    /**< Wait time tP as per EMVCo specification. Simplified API EMVCo profile uses                                                                                            this value for Card removal procedure. */
#define PH_NXPNFCRDLIB_CONFIG_EMVCO_REMOVAL_RETRY_COUNT          3U       /**< Poll command retry count used in removal procedure of EMVCo profile. */

/* TODO : Max retry of RATS and Attrib can be 2 in case of EMVCo. Need to check. */

/* EMVCo values used in PAL 14443-3a, PAL 14443-4a, PAL 14443-3b and Discovery Loop. */
#define PH_NXPNFCRDLIB_CONFIG_EMVCO_TMIN_RETRANSMISSION          3000U    /**< Tmin re-transmission used to re-transmit command in case of timeout error as per EMVCo 2.6 req 9.6.1.3.*/
#define PH_NXPNFCRDLIB_CONFIG_EMVCO_DEFAULT_RETRANSMISSION       PH_NXPNFCRDLIB_CONFIG_EMVCO_TMIN_RETRANSMISSION    /**< Default re-transmission time to re-transmit command in case of timeout error.*/
#define PH_NXPNFCRDLIB_CONFIG_EMVCO_RETRYCOUNT                   2U       /**< Retry count used to re-transmit command in case of timeout error as per EMVCo 2.6 req 9.6.1.3.*/

/* User should update this macro with expected NDEF length that can be read from the tag.
 * For which buffer of this length needs to be allocated properly by User and pass this buffer to phalTop_ReadNdef() API.
 * */
#define PH_NXPNFCRDLIB_CONFIG_MAX_NDEF_DATA                      0x100U    /**< Default value is 256 bytes, Maximum NDEF DATA that can be exchanged at a time, Application Buffer for NDEF Exchange should equal this */


/** \name HAL Ncx3320 macros
 */

/** \name Memory related constants
*/
/*@{*/
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_PRECACHED_255BYTES           0xFFU    /**< Maximum number of bytes to pre-cache into FIFO before triggering a command for 255 FIFO. */
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_PRECACHED_512BYTES           0x200U   /**< Maximum number of bytes to pre-cache into FIFO before triggering a command for 512 FIFO. */
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_DEFAULT_PRECACHED_BYTES      PH_NXPNFCRDLIB_CONFIG_NCx3320_PRECACHED_255BYTES /**< Default number of bytes to pre-cache into FIFO. */
/*@}*/

/**
* \name FIFO configuration values
*/
/*@{*/
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_VALUE_FIFOSIZE_255           0x0000U  /**< Configure FIFO-Size to 256 bytes */
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_VALUE_FIFOSIZE_512           0x0001U  /**< Configure FIFO-Size to 512 bytes */
#define PH_NXPNFCRDLIB_CONFIG_NCx3320_DEFAULT_FIFOSIZE             PH_NXPNFCRDLIB_CONFIG_NCx3320_VALUE_FIFOSIZE_255 /**< Default FIFO-Size */
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

#ifdef __cplusplus
}
#endif
#endif /* PH_NXPNFCRDLIB_CONFIG_H */
