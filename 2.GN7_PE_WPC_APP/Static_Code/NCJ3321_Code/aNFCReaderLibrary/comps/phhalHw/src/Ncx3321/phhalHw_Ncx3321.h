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
*   @file    phhalHw_Ncx3321.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321 - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#ifndef PHHALHW_NCX3321_H
#define PHHALHW_NCX3321_H

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

#ifdef NXPBUILD__PHHAL_HW_NCX3321
#include <phhalHw.h>
#endif /*NXPBUILD__PHHAL_HW_NCX3321*/
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
#define PHHAL_HW_NCX3321_TX_RX_PRESCALER                 0x7FU  /* Tx and Rx Prescaler to 0x7F with 1 Etu ref*/

/**
Set EMD Modes
*/
#define PHHAL_HW_NCX3321_EMVCO_EMD_NO_BYTES ((uint32)1U << EMD_CONTROL_EMD_NOISE_BYTES_THRESHOLD_POS)
#define PHHAL_HW_NCX3321_EMVCO_ISO_NO_BYTES (0U << EMD_CONTROL_EMD_NOISE_BYTES_THRESHOLD_POS)
#define PHHAL_HW_NCX3321_EMVCO_EMD_TIMER    ((uint32)1U << EMD_CONTROL_EMD_TRANSMISSION_TIMER_USED_POS)

#define PHHAL_HW_NCX3321_EMD_3P0     (EMD_CONTROL_EMD_ENABLE_MASK | \
                                     EMD_CONTROL_EMD_TRANSMISSION_ERROR_ABOVE_NOISE_THRESHOLD_IS_NO_EMD_MASK | \
                                     PHHAL_HW_NCX3321_EMVCO_EMD_NO_BYTES | PHHAL_HW_NCX3321_EMVCO_EMD_TIMER)   /* EMVCO 3.0 */

#define PHHAL_HW_NCX3321_ISO_EMD     (EMD_CONTROL_EMD_ENABLE_MASK | \
                                     EMD_CONTROL_EMD_TRANSMISSION_ERROR_ABOVE_NOISE_THRESHOLD_IS_NO_EMD_MASK | \
                                     PHHAL_HW_NCX3321_EMVCO_ISO_NO_BYTES | PHHAL_HW_NCX3321_EMVCO_EMD_TIMER)

#define A_MODE                              0x01U
#define B_MODE                              0x02U
#define F_MODE                              0x04U

#define ACTIVE_A_MODE                       0x0100U
#define ACTIVE_B_MODE                       0x0200U
#define ACTIVE_F_MODE                       0x0400U
#define UNSUPPORTED_MODES                   0xF8F8U

#define PHHAL_HW_NCX3321_BIT_TYPEB                 0x03U   /**< Activates Type B communication mode. */
#define PHHAL_HW_NCX3321_BIT_FELICA                0x02U   /**< Activates FeliCa communication mode. */
#define PHHAL_HW_NCX3321_BIT_ISO18092              0x01U   /**< Activates ISO18092(with Sync Byte = 0xF0) communication mode. */
#define PHHAL_HW_NCX3321_BIT_MIFARE                0x00U   /**< Activates ISO/IEC 14443 type A communication mode. */
#define PHHAL_HW_NCX3321_SIGPRO_GENERAL_MAPPING    0x03U

#define PH_SIGPRO_FRAMING_NFC               0x01U
#define PH_NFC_SYNC_BYTE_DEF                0x1FU
#define PH_NINE_BIT_LEN_MASK                0x09U
#define PH_CRC_PRESET_SEL_NFC               0x02U


/**
Set Listen Parameter Constants
*/
#define PHHAL_HW_NCX3321_SET_LISTEN_LEN              24U
#define PHHAL_HW_NCX3321_SET_LISTEN_SENRES_LEN       2U
#define PHHAL_HW_NCX3321_SET_LISTEN_NFCID1_LEN       3U
#define PHHAL_HW_NCX3321_SET_LISTEN_SELRES_LEN       1U
#define PHHAL_HW_NCX3321_SET_LISTEN_POLLRES_LEN      18U
#define PHHAL_HW_NCX3321_SET_LISTEN_NFCID3_LEN       1U

/**
 * \name Field Reset state
 */
/*@{*/
#define PHHAL_FIELD_RESET_STATE_FIELD_OFF               0U     /**< Field Reset in switching OFF  */
#define PHHAL_FIELD_RESET_STATE_FIELD_OFF_WAIT          1U     /**< Field Reset in waiting time OFF  */
#define PHHAL_FIELD_RESET_STATE_FIELD_ON                2U     /**< Field Reset in switching ON*/
#define PHHAL_FIELD_RESET_STATE_FIELD_ON_WAIT           3U     /**< Field Reset in waiting time ON */
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
extern P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) xEventHandle;
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
* \brief NCX3321 implementation of Exchange.
*
* \sa phhalHw_Exchange
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Exchange(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,                                 /**< [In] Option parameter. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                              /**< [In] Data to transmit. */
    VAR(uint16, ANFCRL_VAR) wTxLength,                               /**< [In] Number of bytes to transmit. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                            /**< [Out] Pointer to received data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength                              /**< [Out] Number of received data bytes. */
    );

/**
* \brief NCX3321 implementation of SetConfig.
*
* \sa phhalHw_SetConfig
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig,                                 /**< [In] Configuration Identifier. */
    VAR(uint16, ANFCRL_VAR) wValue                                   /**< [In] Configuration Value. */
    );

/**
* \brief NCX3321 implementation of GetConfig.
*
* \sa phhalHw_GetConfig
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_GetConfig(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig,                                 /**< [In] Configuration Identifier. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue                                 /**< [Out] Configuration Value. */
    );

#ifdef NXPBUILD__PHPAL_MIFARE_SW
/**
* \brief NCX3321 implementation of MfcAuthenticateKeyNo.
*
* \sa phhalHw_MfcAuthenticateKeyNo
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticateKeyNo(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                 /**< [In] Block-Number on card to authenticate to. */
    VAR(uint8, ANFCRL_VAR) bKeyType,                                 /**< [In] Either #PHHAL_HW_MFC_KEYA or #PHHAL_HW_MFC_KEYB. */
    VAR(uint16, ANFCRL_VAR) wKeyNo,                                  /**< [In] Key number to be used in authentication. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion,                             /**< [In] Key version to be used in authentication. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                                    /**< [In] Serial number of current cascade level; uint8[4]. */
    );

/**
* \brief NCX3321 implementation of MfcAuthenticate.
*
* \sa phhalHw_MfcAuthenticate
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_MfcAuthenticate(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                                 /**< [In] Block number. */
    VAR(uint8, ANFCRL_VAR) bKeyType,                                 /**< [In] Key type to be used KEY_A or KEY_B. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,                                   /**< [In] Key to be used for authentication. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                                    /**< [In] UID of the tag to be authenticated. */
    );
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

/**
* \brief NCX3321 implementation of ApplyProtocolSettings.
*
* \sa phhalHw_ApplyProtocolSettings
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_ApplyProtocolSettings(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bCardType                                 /**< [In] Type of card for which the HAL should be configured for. */
    );

/**
* \brief NCX3321 implementation of FieldOn.
*
* \sa phhalHw_FieldOn
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldOn(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of FieldOff.
*
* \sa phhalHw_FieldOff
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldOff(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of FieldReset.
*
* \sa phhalHw_FieldReset
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_FieldReset(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of Wait.
*
* \sa phhalHw_Wait
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Wait(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bUnit,                                    /**< [In] Unit of given timeout value (either #PHHAL_HW_TIME_MICROSECONDS or #PHHAL_HW_TIME_MILLISECONDS). */
    VAR(uint16, ANFCRL_VAR) wTimeout                                 /**< [In] Timeout value. */
    );
#if 0
/**
* \brief NCX3321 implementation of Listen.
*
* \sa phhalHw_Listen
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Listen(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                            /**< [Out] Pointer to received data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength                              /**< [Out] Number of received data bytes. */
    );
#endif

/**
* \brief NCX3321 implementation of Transmit.
*
* \sa phhalHw_Transmit
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Transmit(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,                                 /**< [In] Option parameter. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                              /**< [In] Data to transmit. */
    VAR(uint16, ANFCRL_VAR) wTxLength                                /**< [In] Number of bytes to transmit. */
    );

/**
* \brief NCX3321 implementation of Receive.
*
* \sa phhalHw_Receive
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Receive(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption,                                 /**< [In] Option parameter. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                            /**< [Out] Pointer to received data. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength                              /**< [Out] Number of received data bytes. */
    );

/**
* \brief NCX3321 implementation of Autocoll.
*
* \sa phhalHw_Autocoll
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Autocoll(
  P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wMode,                                   /**< [In] Autocoll Mode. */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                            /**< [Out] Pointer to received data. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,                             /**< [Out] Number of received data bytes. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams                            /**< [Out] Returned protocol parameter (framing, data rate). */
	);

/**
* \brief NCX3321 implementation LPCD.
*
* \sa phhalHw_Lpcd
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Lpcd(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 - Stop executing current Low-Power-Card-Detection mode.
*
* This only applies for LPCD. ULPCD cannot be stopped by sending this command.
*
* \sa phhalHw_Stop_Lpcd
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Stop_Lpcd(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of abort command.
*
* \sa phhalHw_AsyncAbort
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_AsyncAbort(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of EventWait command.
*
* \sa phhalHw_EventWait
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EventWait(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint32, ANFCRL_VAR) dwEventTimeout                           /**< [In] Event time out. */
    );

/**
* \brief NCX3321 implementation of EventConsume command.
*
* \sa phhalHw_EventConsume
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_EventConsume(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

/**
* \brief NCX3321 implementation of DeInit command.
*
* \sa phhalHw_DeInit
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_DeInit(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams         /**< [In] Pointer to this layer's parameter structure. */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /*NXPBUILD__PHHAL_HW_NCX3321*/

#ifdef __cplusplus
}
#endif
#endif  /* PHHALHW_NCX3321_H */
