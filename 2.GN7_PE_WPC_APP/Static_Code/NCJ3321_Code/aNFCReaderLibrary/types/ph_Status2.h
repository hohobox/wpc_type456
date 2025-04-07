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
*   @file    ph_Status2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Status - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup ph_Status Generic Definitions
*   @ingroup phothers
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
#ifndef PH_STATUS2_H
#define PH_STATUS2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "ph_TypeDefs2.h"
#include <CDD_AnfcRL_Cfg.h>

#ifndef NXPBUILD_DELETE2
#include "ph_NxpBuild2.h"
#endif /* NXPBUILD_DELETE2 */

#include <string.h>

#include <phLog2.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           ph_Status2.h
* @implements     DESIGN001, DESIGN002
*/
#define PH_STATUS_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PH_STATUS_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PH_STATUS_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PH_STATUS_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PH_STATUS_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PH_STATUS_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PH_STATUS_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PH_STATUS_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PH_STATUS_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "ph_Status2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PH_STATUS_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PH_STATUS_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PH_STATUS_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of ph_Status2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PH_STATUS_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PH_STATUS_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PH_STATUS_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of ph_Status2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_Error Error Code Collection
* \ingroup phOthers
* \brief Common Error Codes
* @{
*/

/**
* \name Success Codes
*/
/*@{*/
#define PH_ERR_SUCCESS2                  ((phStatus_t2)0x0000U) /**< Returned in case of no error. */
#define PH_ERR_SUCCESS_CHAINING2         ((phStatus_t2)0x0071U) /**< Rx chaining is not complete, further action needed. */
#define PH_ERR_SUCCESS_ACK2              ((phStatus_t2)0x0072U) /**< Received ACK packet for a previous transmitted packet. */
#define PH_ERR_SUCCESS_INCOMPLETE_BYTE2  ((phStatus_t2)0x0073U) /**< An incomplete byte was received. */
#define PH_ERR_SUCCESS_DESELECTED2       ((phStatus_t2)0x0074U) /**< DSL is sent for de-selection of target. */
#define PH_ERR_SUCCESS_RELEASED2         ((phStatus_t2)0x0075U) /**< RLS is sent for release of target. */
#define PH_ERR_SUCCESS_INFO_RECEIVED2    ((phStatus_t2)0x0076U) /**< Received I PDU in response for an I PDU. */
/*@}*/

/**
* \name Communication Errors
*/
/*@{*/
#define PH_ERR_IO_TIMEOUT2               ((phStatus_t2)0x0001U) /**< No reply received, e.g. PICC removal. */
#define PH_ERR_INTEGRITY_ERROR2          ((phStatus_t2)0x0002U) /**< Wrong CRC or parity detected. */
#define PH_ERR_COLLISION_ERROR2          ((phStatus_t2)0x0003U) /**< A collision occurred. */
#define PH_ERR_BUFFER_OVERFLOW2          ((phStatus_t2)0x0004U) /**< Attempt to write beyond buffer size. */
#define PH_ERR_FRAMING_ERROR2            ((phStatus_t2)0x0005U) /**< Invalid frame format. */
#define PH_ERR_PROTOCOL_ERROR2           ((phStatus_t2)0x0006U) /**< Received response violates protocol. */
#define PH_ERR_AUTH_ERROR2               ((phStatus_t2)0x0007U) /**< Authentication error. */
#define PH_ERR_READ_WRITE_ERROR2         ((phStatus_t2)0x0008U) /**< A Read or Write error occurred in RAM/ROM or Flash. */
#define PH_ERR_TEMPERATURE_ERROR2        ((phStatus_t2)0x0009U) /**< The RC sensors signal over heating. */
#define PH_ERR_RF_ERROR2                 ((phStatus_t2)0x000AU) /**< Error due to RF. */
#define PH_ERR_INTERFACE_ERROR2          ((phStatus_t2)0x000BU) /**< An error occurred in RC communication. */
#define PH_ERR_LENGTH_ERROR2             ((phStatus_t2)0x000CU) /**< A length error occurred. */
#define PH_ERR_RESOURCE_ERROR2           ((phStatus_t2)0x000DU) /**< An resource error. */
#define PH_ERR_TX_NAK_ERROR2             ((phStatus_t2)0x000EU) /**< TX Rejected sanely by the counterpart. */
#define PH_ERR_RX_NAK_ERROR2             ((phStatus_t2)0x000FU) /**< RX request Rejected sanely by the counterpart. */
#define PH_ERR_EXT_RF_ERROR2             ((phStatus_t2)0x0010U) /**< Error due to External RF. */
#define PH_ERR_NOISE_ERROR2              ((phStatus_t2)0x0011U) /**< EMVCo EMD Noise Error. */
#define PH_ERR_ABORTED2                  ((phStatus_t2)0x0012U) /**< Used when HAL Abort is called. */
#define PH_ERR_LPCD_ABORTED2             ((phStatus_t2)0x0013U) /**< LPCD is exited, without card detection. */
#define PH_ERR_INTERNAL_ERROR2           ((phStatus_t2)0x007FU) /**< An internal error occurred. */
#define PH_ERR_AUTH_DELAY2               ((phStatus_t2)0x00ADU) /**< Authentication Delay. */
/*@}*/

/**
* \name Parameter & Command Errors
*/
/*@{*/
#define PH_ERR_INVALID_DATA_PARAMS2      ((phStatus_t2)0x0020U) /**< Invalid data parameters supplied (layer id check failed). */
#define PH_ERR_INVALID_PARAMETER2        ((phStatus_t2)0x0021U) /**< Invalid parameter supplied. */
#define PH_ERR_PARAMETER_OVERFLOW2       ((phStatus_t2)0x0022U) /**< Reading/Writing a parameter would produce an overflow. */
#define PH_ERR_UNSUPPORTED_PARAMETER2    ((phStatus_t2)0x0023U) /**< Parameter not supported. */
#define PH_ERR_UNSUPPORTED_COMMAND2      ((phStatus_t2)0x0024U) /**< Command not supported. */
#define PH_ERR_USE_CONDITION2            ((phStatus_t2)0x0025U) /**< Condition of use not satisfied. */
#define PH_ERR_KEY2                      ((phStatus_t2)0x0026U) /**< A key error occurred. */
/*@}*/

/**
* \name Osal Errors
*/
/*@{*/
#define PH_ERR_OSAL_ERROR2               ((phStatus_t2)0x0027U) /**< Error occurred during initialization. */
#define PH_ERR_OSAL_FAILURE2             ((phStatus_t2)0x0028U) /**< OSAL failed to perform the requested operation. */
/*@}*/

/**
* \name Event Errors
*/
/*@{*/
#define PH_ERR_EVENT_ERROR2               ((phStatus_t2)0x0029U) /**< Error occurred during initialization. */
#define PH_ERR_EVENT_FAILURE2             ((phStatus_t2)0x0030U) /**< Event failed to perform the requested operation. */
/*@}*/

/**
* \name State Errors
*/
/*@{*/
#define PH_STATUS_INPROCESS2              ((phStatus_t2)0xE000U) /**< Status when operation is in progress. */
#define PH_STATUS_IDLE2                	 ((phStatus_t2)0xE001U) /**< Status when no operation. */
/*@}*/

/**
 * end of group ph_Error Error Code Collection
 * @}
 */


/** \defgroup phOthers Other
* \brief Contains all other components or definitions.
*
*/

/** \defgroup ph_Status Generic Definitions
* \ingroup phOthers
* \brief Contains definitions which are generic throughout the library
* @{
*/


/**
* \name Running Modes of Reader Library
*/
/*@{*/
#define RD_LIB_MODE_EMVCO2               0x01U /**< EMVCo Mode. */
#define RD_LIB_MODE_NFC2                 0x02U /**< NFC Forum Mode. */
#define RD_LIB_MODE_ISO2                 0x03U /**< ISO Mode. */
#define RD_LIB_MODE_FELICA2              0x04U /**< FeliCa Mode. */
/*@}*/

/**
* \name Boolean Values
*/
/*@{*/
#define PH_ON2                           0x0001U /**< Enabled. */
#define PH_OFF2                          0x0000U /**< Disabled. */
#define PH_SUPPORTED2                    0x0001U /**< Supported. */
#define PH_UNSUPPORTED2                  0x0000U /**< Not Supported. */
/*@}*/

/**
* \name Configuration
*/
/*@{*/
#define PH_CONFIG_CUSTOM_BEGIN2          0xE000U /**< Starting number of custom configs. */
/*@}*/

/**
* \name Component identifiers
*/
/*@{*/
#define PH_COMP_MASK2                    ((phStatus_t2)0xFF00U) /**< Component Mask for status code and component ID. */
#define PH_COMPID_MASK2                  (0x00FFU) /**< ID Mask for component ID. */
#define PH_ERR_MASK2                     (0x00FFU) /**< Error Mask for status code. */
#define PH_ERR_CUSTOM_BEGIN2             ((phStatus_t2)0x0080U) /**< Starting number of custom error codes. */
#define PH_COMP_GENERIC2                 (0x0000U) /**< Generic Component Code. */
#define PH_COMP_BAL2                     (0x0100U) /**< BAL Component Code. */
#define PH_COMP_HAL2                     (0x0200U) /**< HAL Component Code. */
#define PH_COMP_PAL_ISO14443P3A2         (0x0300U) /**< ISO14443-3A PAL-Component Code. */
#define PH_COMP_PAL_ISO14443P3B2         (0x0400U) /**< ISO14443-3B PAL-Component Code. */
#define PH_COMP_PAL_ISO14443P4A2         (0x0500U) /**< ISO14443-4A PAL-Component Code. */
#define PH_COMP_PAL_ISO14443P42          (0x0600U) /**< ISO14443-4 PAL-Component Code. */
#define PH_COMP_PAL_ISO14443P4MC2        (0x0610U) /**< ISO14443-4MC PAL-Component Code. */
#define PH_COMP_PAL_MIFARE2              (0x0700U) /**< MIFARE product PAL-Component Code. */
#define PH_COMP_PAL_FELICA2              (0x0800U) /**< Open FeliCa PAL-Component Code. */
#define PH_COMP_PAL_EPCUID2              (0x0900U) /**< ICode EPC/UID PAL-Component Code. */
#define PH_COMP_PAL_SLI156932            (0x0A00U) /**< ICode SLI/ISO15693 PAL-Component Code. */
#define PH_COMP_PAL_I14443P4MC2          (0x0F00U) /**< ISO 14443-4 Card mode protocol. */
#define PH_COMP_AL_MFP2                  (0x1200U) /**< MIFARE Plus contactless IC AL-Component Code. */
#define PH_COMP_AL_MFPEVX2               (0x2100U) /**< MIFARE Plus contactless IC EV1 AL-Component Code. */
#define PH_COMP_AL_VCA2                  (0x1300U) /**< Virtual Card Architecture AL-Component Code. */
#define PH_COMP_AL_FELICA2               (0x1400U) /**< Open FeliCa AL-Component Code. */
#define PH_COMP_AL_ICODE2                (0x1500U) /**< ICode AL-Component Code. */
#define PH_COMP_AL_MFDF2                 (0x1900U) /**< MIFARE DESFire EV1 contactless IC AL Component Code. */
#define PH_COMP_AL_MFDFEVX2              (0x2000U) /**< MIFARE DESFIRE EVx contactless IC(for Ev2, Ev3 and future versions) AL Component Code. */
#define PH_COMP_AL_MFDFLIGHT2            (0x2300U) /**< MIFARE Prime Match AL Component Code. */
#define PH_COMP_AL_MFNTAG42XDNA2         (0x2600U) /**< MIFARE Prime Ntag42XDna AL Component Code. */
#define PH_COMP_AL_P40CMDPRIV2           (0x1A00U) /**< P40 command libraryAL-Component Code. */
#define PH_COMP_AL_P40CMDPUB2            (0x1B00U) /**< P40 command libraryAL-Component Code. */
#define PH_COMP_AL_TOP2                  (0x1D00U) /**< Tag Operation AL component code  */
#define PH_COMP_DL_AMP2                  (0x3000U) /**< Amplifier DL-Component Code. */
#define PH_COMP_DL_THSTRM2               (0x3100U) /**< Thermostream DL-Component Code. */
#define PH_COMP_DL_OSCI2                 (0x3200U) /**< Oscilloscope DL-Component Code. */
#define PH_COMP_DL_RDFPGA2               (0x3300U) /**< Reader FPGA Box DL-Component Code. */
#define PH_COMP_DL_MSTAMPOSC2            (0x3400U) /**< Master Amplifier Oscilloscope DL-Component Code. */
#define PH_COMP_DL_STEPPER2              (0x3500U) /**< Stepper DL-Component Code. */
#define PH_COMP_AC_DISCLOOP2             (0x4000U) /**< Discovery Loop. */
#define PH_COMP_CE_T4T2                  (0x5000U) /**< Card Emulation T4T. */
#define PH_COMP_LN_LLCP2                 (0x6000U) /**< LLCP code. */
#define PH_COMP_NP_SNEP2                 (0x7000U) /**< SNEP Code. */
#define PH_COMP_CIDMANAGER2              (0xE000U) /**< Cid Manager Component Code. */
#define PH_COMP_CRYPTOSYM2               (0xE100U) /**< CryptoSym Component Code. */
#define PH_COMP_KEYSTORE2                (0xE200U) /**< KeyStore Component Code. */
#define PH_COMP_TOOLS2                   (0xE300U) /**< Tools Component Code. */
#define PH_COMP_CRYPTORNG2               (0xE400U) /**< CryptoRng Component Code. */
#define PH_COMP_TMIUTILS2                (0xE500U) /**< TMI Utilities Code. */
#define PH_COMP_LOG2                     (0xEF00U) /**< Log Component Code. */
#define PH_COMP_OSAL2                    (0xF000U) /**< OS AL component code. */
#define PH_COMP_DRIVER2                  (0xF100U) /**< External phDriver2 component code. */
/*@}*/

/**
* Macro for error handling of underlying layer and exit.
*/
#define PH_CHECK_SUCCESS2(status2)         {if ((status2) != PH_ERR_SUCCESS2) {return (status2);}}    /**< This macro return status code if return value is not equal PH_ERR_SUCCESS2 .*/
#define PH_CHECK_SUCCESS_FCT2(status2,fct2) {(status2) = (fct2); PH_CHECK_SUCCESS2(status2);}    /**< This macro compare status code with expected status code 'fct'. If they are equal, call macro PH_CHECK_SUCCESS2 .*/
#define PH_CHECK_SUCCESS_FCT_POS2(status2,fct2) {(status2) = (fct2);}    /**< This macro compare status code with expected status code 'fct'.*/

#define PH_CHECK_ABORT2(status2)         {if (((status2) & PH_ERR_MASK2) == PH_ERR_ABORTED2) {return (status2);}}    /**< This macro check if return status code is PH_ERR_ABORTED2 then return status value .*/
#define PH_CHECK_ABORT_FCT2(status2,fct2) {(status2) = (fct2); PH_CHECK_ABORT2(status2);}    /**< This macro compare return status code with expected status code 'fct'. If they are equal, call macro PH_CHECK_ABORT2 .*/

#define PH_BREAK_ON_FAILURE2(status2)     {if ((status2) != PH_ERR_SUCCESS2) {break;}}    /**< This macro check if status is not equal PH_ERR_SUCCES2 then call 'break' statement. */
#define PH_CHECK_FAILURE_FCT2(status2,fct2)  {(status2) = (fct2); PH_BREAK_ON_FAILURE2(status2);}    /**< This macro compare return status code with expected status code 'fct'. If they are equal, call macro PH_BREAK_ON_FAILURE2 .*/

#define PH_CHECK_INPROCESS_FCT2(status2,fct2)         {(status2) = (fct2); if ((status2) == PH_STATUS_INPROCESS2) {return (status2);}}    /**< This macro return status code if return value is equal PH_STATUS_INPROCESS2 .*/
/**
*  Macro for component-error-code adding of current layer.
*/
// NXP Patch 2024.10.11
#define PH_CHECK_INPROCESS_FCT_REDUCE2(status2,fct2)       \
{                                                \
	int iter2 = 0;                               \
	do {                                        \
		iter2++;                                 \
		(status2) = (fct2);                       \
		if ((status2) != PH_STATUS_INPROCESS2) {  \
			break;                              \
		}                                       \
	} while ((iter2 < 3));                       \
	if ((status2) == PH_STATUS_INPROCESS2) {      \
	return (status2);}}    /**< This macro return status code if return value is equal PH_STATUS_INPROCESS .*/

#define PH_ADD_COMPCODE2(stat2, code2)             \
    ((phStatus_t2)                               \
     (                                          \
         (                                      \
             ((stat2) == PH_ERR_SUCCESS2)         \
             ||                                 \
             (                                  \
                 0U                             \
                 !=                             \
                 ((stat2) & PH_COMP_MASK2)        \
                 )                              \
             )                                  \
         ?                                      \
         (                                      \
             (phStatus_t2)(stat2)                 \
             )                                  \
         : (                                    \
             (((phStatus_t2)(stat2)) & (PH_ERR_MASK2))           \
             |                                  \
             ((code2) & PH_COMP_MASK2))))

/** Return status for Values known at compile time. For variable status, use \ref PH_ADD_COMPCODE2 */
#define PH_ADD_COMPCODE_FIXED2(stat2,code2) \
    ((phStatus_t2)(((phStatus_t2)(stat2)) & PH_ERR_MASK2) \
        | ((code2) & PH_COMP_MASK2))

/**
*  Macro to get the component code or id using a pointer to a memory.
*/
#define PH_GET_COMPCODE2(pId2)            ( (*((uint16*)(pId2))) & PH_COMP_MASK2 )
#define PH_GET_COMPID2(pId2)              ( (uint8)(*((uint16*)(pId2))) )    /**< Macro to get the component id. */

/**
* \name Exchange Options
*/
/*@{*/
/**
Default exchange mode.
Combine with #PH_EXCHANGE_BUFFERED_BIT2 and
#PH_EXCHANGE_LEAVE_BUFFER_BIT2 to perform buffering.
\c ISO14443-4/ISO18092 specific:
Performs Tx/Rx chaining with the card.
Returns #PH_ERR_SUCCESS_CHAINING2 when RxBuffer is full and
does not ACK the last received block.
*/
#define PH_EXCHANGE_DEFAULT2             0x0000U

/**
\c ISO14443-4/ISO18092 specific:
Chains given data to card/Target.
Combine with #PH_EXCHANGE_BUFFERED_BIT2 and
#PH_EXCHANGE_LEAVE_BUFFER_BIT2 to perform buffering.
Does not receive any data.
*/
#define PH_EXCHANGE_TXCHAINING2          0x0001U

/**
\c ISO14443-4/ISO18092 specific:
Starts transmission with and R(ACK) block and
performs Rx chaining with the Card/Target.
Returns #PH_ERR_SUCCESS_CHAINING2 when RxBuffer is full and
does not ACK the last received block.
*/
#define PH_EXCHANGE_RXCHAINING2          0x0002U

/**
\c ISO14443-4/ISO18092 specific:
Starts transmission with and R(ACK) block and
performs Rx chaining with the card.
Completes Rx chaining with the card if RxBuffer is full.
*/
#define PH_EXCHANGE_RXCHAINING_BUFSIZE2  0x0003U

/** Mask for the above modes. All other bits are reserved. */
#define PH_EXCHANGE_MODE_MASK2           0x000FU

/** Mask for custom exchange bits. These 4 bits can be used for custom exchange behavior. */
#define PH_EXCHANGE_CUSTOM_BITS_MASK2    0x00F0U

/**
Does not clear the internal buffer before operation.
If this bit is set and data is transmitted,
the contents of the internal buffer are sent first.
*/
#define PH_EXCHANGE_LEAVE_BUFFER_BIT2    0x4000U

/**
Buffers Tx-Data into internal buffer
instead of transmitting it.
*/
#define PH_EXCHANGE_BUFFERED_BIT2        0x8000U

/**
The given data is the first part of a stream.
(Helper definition for buffering).
*/
#define PH_EXCHANGE_BUFFER_FIRST2   (PH_EXCHANGE_DEFAULT2 | PH_EXCHANGE_BUFFERED_BIT2)

/**
The given data is a subsequent part of a stream.
(Helper definition for buffering).
*/
#define PH_EXCHANGE_BUFFER_CONT2    (PH_EXCHANGE_DEFAULT2 | PH_EXCHANGE_BUFFERED_BIT2 | PH_EXCHANGE_LEAVE_BUFFER_BIT2)

/**
The given data is the last part of a stream.
(Helper definition for buffering).
*/
#define PH_EXCHANGE_BUFFER_LAST2    (PH_EXCHANGE_DEFAULT2 | PH_EXCHANGE_LEAVE_BUFFER_BIT2)

/**
Default transmit mode.
Combine with #PH_TRANSMIT_BUFFERED_BIT2 and
#PH_TRANSMIT_LEAVE_BUFFER_BIT to perform buffering.
*/
#define PH_TRANSMIT_DEFAULT2             0x0000U

/**
Perform Transmit Chaining.
Combine with #PH_TRANSMIT_BUFFERED_BIT2 and
#PH_TRANSMIT_LEAVE_BUFFER_BIT2 to perform buffering.
*/
#define PH_TRANSMIT_TXCHAINING2          0x0001U

/** Mask for the above modes. All other bits are reserved. */
#define PH_TRANSMIT_MODE_MASK2           0x000FU

/**
Does not clear the internal buffer before transmit operation.
If this bit is set and data is transmitted,
the contents of the internal buffer are sent first.
*/
#define PH_TRANSMIT_LEAVE_BUFFER_BIT2    0x4000U

/**
Buffers Tx-Data into internal buffer
instead of transmitting it.
*/
#define PH_TRANSMIT_BUFFERED_BIT2        0x8000U

/**
The given data is the first part of a stream.
(Helper definition for buffering).
*/
#define PH_TRANSMIT_BUFFER_FIRST2        (PH_TRANSMIT_DEFAULT2 | PH_TRANSMIT_BUFFERED_BIT2)

/**
The given data is a subsequent part of a stream.
(Helper definition for buffering).
*/
#define PH_TRANSMIT_BUFFER_CONT2         (PH_TRANSMIT_DEFAULT2 | PH_TRANSMIT_BUFFERED_BIT2 | PH_TRANSMIT_LEAVE_BUFFER_BIT2)

/**
The given data is the last part of a stream.
(Helper definition for buffering).
*/
#define PH_TRANSMIT_BUFFER_LAST2         (PH_TRANSMIT_DEFAULT2 | PH_TRANSMIT_LEAVE_BUFFER_BIT2)

/**
Perform Re-transmit of data stored in HAL Tx buffer.
Should not be combined with #PH_TRANSMIT_BUFFERED_BIT2 and #PH_TRANSMIT_LEAVE_BUFFER_BIT2.
This option should be used only in target / PICC mode.
*/
#define PH_TRANSMIT_PREV_FRAME2          0x1000U

/**
Default exchange mode.
\c ISO14443-4/ISO18092 specific:
Performs Rx chaining with the card.
Returns #PH_ERR_SUCCESS_CHAINING2 when RxBuffer is full and
does not ACK the last received block.
*/
#define PH_RECEIVE_DEFAULT2              0x0000U

/**
\c ISO14443-4/ISO18092 specific:
Starts transmission of ACK block and
performs Rx chaining with the card.
Returns #PH_ERR_SUCCESS_CHAINING2 when RxBuffer is full and
does not ACK the last received block.
*/
#define PH_RECEIVE_CHAINING2             0x0001U

/**
\c ISO14443-4/ISO18092 specific:
Starts transmission with ACK block and
performs Rx chaining with the card.
Completes Rx chaining with the card if RxBuffer is full.
*/
#define PH_RECEIVE_CHAINING_BUFSIZE2     0x0002U
/*@}*/

/**
 * end of group ph_Status Generic Definitions
 * @}
 */

/**
* \name Debug Definitions
*/
/*@{*/
#ifdef NXPBUILD__PH_DEBUG2
#   define PH_ASSERT_NULL2(a2) while((a2) == NULL) { ; }
#   define PH_ASSERT_NULL_PARAM2(a2,comp_code2)
#	define PH_ASSERT_NULL_DATA_PARAM2(dataparams2,comp_code2)
#endif /* NXPBUILD__PH_DEBUG2 */
#ifndef NXPBUILD__PH_DEBUG2
#   define PH_ASSERT_NULL2(a2) { /* Nothing to do */ }
#	define PH_ASSERT_NULL_PARAM2(a2,comp_code2) {if((a2) == NULL) {return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_PARAMETER2, (comp_code2));}}
#	define PH_ASSERT_NULL_DATA_PARAM2(dataparams2,comp_code2) {if((dataparams2) == NULL) {return PH_ADD_COMPCODE_FIXED2(PH_ERR_INVALID_DATA_PARAMS2, (comp_code2));}}
#endif /* NXPBUILD__PH_DEBUG2 */
/*@}*/
#define PH_UNUSED_VARIABLE2(x2) ((void)x2)

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
} /* Extern C */
#endif /* __cplusplus */

#endif /* PH_STATUS2_H */
