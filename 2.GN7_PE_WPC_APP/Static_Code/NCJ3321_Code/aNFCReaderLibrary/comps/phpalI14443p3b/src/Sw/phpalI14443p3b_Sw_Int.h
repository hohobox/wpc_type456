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
*   @file    phpalI14443p3b_Sw_Int.h
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

#ifndef PHPALI14443P3B_SW_INT_H
#define PHPALI14443P3B_SW_INT_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status.h>
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phpalI14443p3b_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P3B_SW_INT_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P3B_SW_INT_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHPALI14443P3B_SW_INT_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHPALI14443P3B_SW_INT_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P3B_SW_INT_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHPALI14443P3B_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P3B_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P3B_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P3B_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p3b_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P3B_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p3b_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P3B_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P3B_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P3B_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p3b_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
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

#define PHPAL_I14443P3B_SW_ATQB_TIME_US     600U     /**< TR0 + TR1 (ISO14443-2 9.2.5 75,5 + 94U,4 ~ 170 --> set 200 us). */
#define PHPAL_I14443P3B_SW_DELTA_POLL       17U      /**< T(B,POLL) (Digital Protocol Ver1.1 (Article 7.9.1.5) is 16.4ms = ~17ms). */
#define PHPAL_I14443P3B_SW_ATTRIB_TIME_US   4800U    /**< Answer to ATTRIB FWT (ISO14443-3 7.9.4.3). */

/** Anti-collision prefix code */
#define PHPAL_I14443P3B_SW_APF                      0x05U

/** Wakeup bit within PARAM byte */
#define PHPAL_I14443P3B_SW_PARAM_WUP_BIT            0x08U

/** Extended ATQB bit within PARAM byte */
#define PHPAL_I14443P3B_SW_PARAM_EXTATQB_BIT        0x10U

/** HaltB Command code */
#define PHPAL_I14443P3B_SW_HALT_CMD                 0x50U

/** HaltB Response code */
#define PHPAL_I14443P3B_SW_HALT_RESP                0x00U

/** ATTRIB Command code */
#define PHPAL_I14443P3B_SW_ATTRIB_CMD               0x1DU

/** ATTRIB parameter1 default value */
#define PHPAL_I14443P3B_SW_ATTRIB_PARAM1_DEFAULT    0x00U

/** FWI default value */
#define PHPAL_I14443P3B_SW_FWI_DEFAULT              0x04U

/** SFGI default value */
#define PHPAL_I14443P3B_SW_SFGI_DEFAULT             0x00U

/** FSCI default value */
#define PHPAL_I14443P3B_SW_FSCI_DEFAULT             0x02U

/** FTW min in microseconds */
#define PHPAL_I14443P3B_SW_FWT_MIN_US               303u

/** Time extension in microseconds for all commands.  */
#define PHPAL_I14443P3B_SW_EXT_TIME_US              63U

/** The minimum FSDI value as per EMVCo v3.0 - Requirements 5.9 */
#define PHPAL_I14443P3B_EMVCO_FRAMESIZE_MIN         8U

/** EMVCo:  Delta Time to support EMVCO Req */
#define PHPAL_I14443P3B_SW_FWT_EMVCO_MIN_US         29U

/** Minimum TxWait in case received TR2 value is (00)b. */
#define PHPAL_I14443P3B_SW_TXWAIT_US_TR2_0          133U

/** Minimum TxWait in case received TR2 value is (01)b. */
#define PHPAL_I14443P3B_SW_TXWAIT_US_TR2_1          246U

/** Minimum TxWait in case received TR2 value is (10)b. */
#define PHPAL_I14443P3B_SW_TXWAIT_US_TR2_2          397U

/** Minimum TxWait in case received TR2 value is (11)b. */
#define PHPAL_I14443P3B_SW_TXWAIT_US_TR2_3          699U

/** Default TxWait */
#define PHPAL_I14443P3B_SW_TXWAIT_US_DEFAULT        500U

/** Minimum TR2 Mask to extract TR2 value. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_MASK         0x06U

/** TR2 position. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_POS          1U

/** TR2 bit value (00)b. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_0      0U

/** TR2 bit value (01)b. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_1      1U

/** TR2 bit value (10)b. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_2      2U

/** TR2 bit value (11)b. */
#define PHPAL_I14443P3B_SW_MINIMUM_TR2_VALUE_3      3U

/** Delta TPCD max in microseconds */
#define PHPAL_I14443P3B_SW_DELTA_TPCD_US_MAX        16400U

/** Delta TPCD minimum in microseconds */
#define PHPAL_I14443P3B_SW_DELTA_TPCD_US_MIN        0U

/** Delta frame wait time (FWT) in microseconds = 49152/fc = 3625us.
 * Providing additional 65us delay for NFC Forum compliance.
 * */
#define PHPAL_I14443P3B_SW_DELTA_FWT_US             3690U

/** Delta TPCD used for exchange (in microseconds) */
#define PHPAL_I14443P3B_SW_DELTA_TPCD_US            1000U

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
#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P3B_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_START_SEC_CODE */

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/
 
/**
* \brief Perform a ISO14443-3B Request/Wakeup command.
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_RequestBEx(
                                        P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   	/**< [In] Pointer to this layers parameter structure. */
                                        VAR(uint8, ANFCRL_VAR) bIsWakeUp,                                         		/**< [In] Performs ReqB if \c bIsWakeUp=0 and WupB if \c bIsWakeUp=1. */
                                        VAR(uint8, ANFCRL_VAR) bNumSlots,                              					/**< [In] Number of slots. */
                                        VAR(uint8, ANFCRL_VAR) bAfi,                                   					/**< [In] AFI; Application Family Identifier. */
                                        VAR(uint8, ANFCRL_VAR) bExtAtqb,                               					/**< [In] Enable Extended AtqB. */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,                                	/**< [Out] AtqB; uint8[13]. */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen                                /**< [Out] Length of received ATQB (12/13 bytes) */
                                        );

/**
* \brief Check the received answer to Request/Wakeup/SlotMarker command.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_CheckATQBEx(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layers parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResp,                                     /**< [In] Pointer to memory which stores response. */
    VAR(uint16, ANFCRL_VAR) wRespLength,                                /**< [In] Response's length. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqb,                                     /**< [Out] Atqb received. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAtqbLen                                   /**< [Out] Atqb's length. */
    );

/**
* \brief Set the baud rate on the reader device.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_SetReaderBaudRateEx(
    P2VAR(phpalI14443p3b_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layers parameter structure. */
    );

/**
* \brief Decide which baud rate to use depending on the VICCs capabilities and the callers request.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p3b_Sw_DecideBaudRateEx(
    VAR(uint8, ANFCRL_VAR) bBitRateCapability,                        /**< [In] Bit rate capability. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDri,                  /**< [Out] Divisor Receive Integer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbDsi                   /**< [Out] Divisor Send Integer. */
    );

/**
 * end of group ph_Private (Private definitions)
 * @}
 */
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P3B_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P3B_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif /* ANFCRL_STOP_SEC_CODE */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHPALI14443P3A_SW_INT_H */
