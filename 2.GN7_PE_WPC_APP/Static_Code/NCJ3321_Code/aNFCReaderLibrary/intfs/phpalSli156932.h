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
*   @file    phpalSli156932.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693 - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalSli156932 ISO/IEC 15693 
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
#ifndef PHPALSLI156932_H
#define PHPALSLI156932_H

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
#include "phhalHw2.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalSli156932.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALSLI15693_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalSli156932.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALSLI15693_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALSLI15693_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalSli156932.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALSLI15693_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALSLI15693_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALSLI15693_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalSli156932.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
/** \defgroup phpalSli15693_Sw2 Component : Software
* \brief Software component of ISO/IEC 15693 
* \ingroup phpalSli156932
* @{
*/

/**
 * ID for this layer (Software Sli15693 layer).
 *
 * \ref phpalSli15693_Sw_DataParams_t2::wId2 is initialized with this ID in the
 * initialization function \ref phpalSli15693_Sw_Init2.
 * */
#define PHPAL_SLI15693_SW_ID2   0x01U

/**
 * end of group phpalSli15693_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

#ifdef NXPBUILD__PHPAL_SLI156932
/** \addtogroup ph_Error Error Code Collection
* phpalSli156932 Custom Errors
* @{
*/

/**
* \name phpalSli156932 Error Codes
*/
/*@{*/
/**
 * ISO15693 specific error code from card.
 *
 * When a response is received from the VICC with the error flag
 * #PHPAL_SLI15693_FLAG_RESP_ERROR2 set, this error code returned by library.
 * The actual error code returned by VICC can be accessed via
 * \ref phpalSli15693_GetConfig2 using #PHPAL_SLI15693_CONFIG_ADD_INFO2 option.
 * */
#define PHPAL_SLI15693_ERR_ISO156932     ((phStatus_t2)PH_ERR_CUSTOM_BEGIN2 + 0U)
/*@}*/

/**
 * end of group ph_Error Error Code Collection
 * @}
 */


/** \defgroup phpalSli156932 ISO/IEC 15693 
* \ingroup phpalProtocol
* \brief These component implements the protocol layer (activation) commands of
* ISO/IEC 15693 vicinity protocol.
*
* This implementation is based on ISO/IEC 15693-3:2009(E) specification. This
* layer also implements all activation related custom commands of NXP's ICODE
* SLI series of tags.
*
* Different states of a VICC (Vicinity Integrated Circuit Card) and
* corresponding commands are shown below.
*
* \image html palSli15693_states.png
*
* \b Note: PERSISTENT QUIET state is supported only by few ICODE SLI tags (like
* ICODE SLIX2). Refer \ref phpalSli15693_Inventory2 "function documentation" for
* more information on commands.
* @{
*/

/**
* \name Configuration Types
* \anchor config_palsli
* \brief These options shall be used along with \ref phpalSli15693_SetConfig2 and
* \ref phpalSli15693_GetConfig2 to configure PAL Sli15693 layer.
*/
/*@{*/
/**
 * Set or get the flags field.
 *
 * This shall be used to set or get the value of \ref req_flags "request flag"
 * field used in the commands sent by the library.
 * */
#define PHPAL_SLI15693_CONFIG_FLAGS2           0x0000U

/**
 * Get the additional error info.
 *
 * When a response is received from the VICC with the error flag
 * #PHPAL_SLI15693_FLAG_RESP_ERROR2 set, library returns the custom error code
 * #PHPAL_SLI15693_ERR_ISO156932. This configuration option can be used to get
 * the actual error code returned by VICC.
 * */
#define PHPAL_SLI15693_CONFIG_ADD_INFO2        0x0001U

/**
 * Set or get the current timeout in microseconds.
 * */
#define PHPAL_SLI15693_CONFIG_TIMEOUT_US2      0x0002U

/**
 * Set or get the current timeout in milliseconds.
 * */
#define PHPAL_SLI15693_CONFIG_TIMEOUT_MS2      0x0003U

/**
 * Set or get the current TX Data rate
 */
#define PHPAL_SLI15693_CONFIG_TXDATARATE2       0x0004U

/**
 * Set or get the current RX Data rate
 */
#define PHPAL_SLI15693_CONFIG_RXDATARATE2       0x0005U

/*
 * Option to Get / Set the buffering of response data to be enabled or disabled.
 * By default this flag will be disabled.
 */
#define PHPAL_SLI15693_CONFIG_ENABLE_BUFFERING2    0x0007U
/*@}*/


/**
* \name EOF command options
* \anchor option_sendeof
* \brief Options for \ref phpalSli15693_SendEof2 "EOF" command.
*/
/*@{*/
/**
 * Send an EOF with timing configuration for an \ref phpalSli15693_Inventory2
 * "inventory" round.
 * */
#define PHPAL_SLI15693_EOF_NEXT_SLOT2                0x00U

/**
 * Send an EOF with timing configuration for \ref phpalSli15693_InventoryRead2
 * "INVENTORY READ" or \ref phpalSli15693_FastInventoryRead2 "fast inventory read"
 * or \ref phpalSli15693_InventoryPageRead2 "inventory page read" or \ref
 * phpalSli15693_FastInventoryPageRead2 "fast inventory page read".
 * */
#define PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2       0x01U

/**
 * Send an EOF with timing configuration for write alike commands without
 * long waiting time #PHPAL_SLI15693_TIMEOUT_LONG_US2.
 * */
#define PHPAL_SLI15693_EOF_WRITE_ALIKE2              0x02U

/**
 * Send an EOF with timing configuration for write alike commands with
 * long waiting time #PHPAL_SLI15693_TIMEOUT_LONG_US2.
 * */
#define PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2    0x03U
/*@}*/


/**
* \name Activate Card command options
*
* Options for \ref phpalSli15693_ActivateCard2 "activate card".
*/
/*@{*/
/**
 * Card will be in addressed state (i.e. SELECT command is not send) afteR
 * \ref phpalSli15693_ActivateCard2 "activate card" command.
 *
 * After activate card with this option, to bring VICC to SELECTED state,
 * \ref phpalSli15693_Select2 "select" command can be used.
 * */
#define PHPAL_SLI15693_ACTIVATE_ADDRESSED2   0x0000U

/**
 * Card will be in selected state (i.e. SELECT command is send) after
 * \ref phpalSli15693_ActivateCard2 "activate card" command.
 * */
#define PHPAL_SLI15693_ACTIVATE_SELECTED2    0x0001U

/**
 * Default option.
 *
 * Same as #PHPAL_SLI15693_ACTIVATE_ADDRESSED2.
 * */
#define PHPAL_SLI15693_ACTIVATE_DEFAULT2     0x0000U
/*@}*/


/**
* \name Timeouts.
*/
/*@{*/
/**
 * Timeout T1 in microseconds as defined in ISO/IEC 15693, 9.1.4.
 * */
#define PHPAL_SLI15693_TIMEOUT_SHORT_US2        324U

/**
 * Extended timeout value in microseconds for long timeouts.
 * */
#define PHPAL_SLI15693_TIMEOUT_LONG_US2      20000U
/*@}*/


/**
* \name Request Flags 1 to 4 according to ISO 15693.
* \anchor req_flags
*
* In a request, the field "flags" specifies the actions to be performed by
* the VICC. It consists of eight bits.
*/
/*@{*/
/**
 * Sub-carrier_flag.
 *
 * If set two sub-carriers shall be used (VICC to VCD). Else a single
 * sub-carrier frequency shall be used by the VICC.
 * */
#define PHPAL_SLI15693_FLAG_TWO_SUB_CARRIERS2    0x01U

/**
 * Data_rate_flag.
 *
 * If set high data rate shall be used (VICC to VCD). Else low data rate shall
 * be used.
 * */
#define PHPAL_SLI15693_FLAG_DATA_RATE2           0x02U

/**
 * Inventory_flag.
 *
 * Shall be set for inventory request. If set flags 5 to 8 meaning is as per
 * this \ref inv_set "list". If not set flags 5 to 8 meaning is defined by this
 * \ref inv_not_set "list".
 * */
#define PHPAL_SLI15693_FLAG_INVENTORY2           0x04U

/**
 * Protocol_Extension_flag.
 *
 * If set protocol format is extended. Reserved for future use. No supported
 * in current version.
 * */
#define PHPAL_SLI15693_FLAG_PROTOCOL_EXTENSION2  0x08U

/**
 * Inventory Read Extension Flag
 *
 * If set the additional features of inventory mentioned along with the command
 * will be performed by the VICC
 *
 * */
#define PHPAL_SLI15693_FLAG_INVENTORY_READ_EXTENSION2  0x80U

/**
 * Fast Data Rate Flag
 *
 * This flag is used to set the hardware RX Datarate to Fast_High (~53 kbps)
 * for Fast_Low (~13 kbps)
 *
 * */
#define PHPAL_SLI15693_FLAG_FAST_DATA_RATE2                  0x80U

/**
 * Extended Inventory Read Options Flag
 *
 * If set no user memory data are requested from the tag
 * If not set the tag will add the user memory blocks in the response as requested
 * in command
 * */
#define PHPAL_SLI15693_FLAG_SKIP_DATA2   0x10U

/**
 * Extended Inventory Read Options Flag
 * If set the complete UID is transmitted by the VICC to the reader irrespective of the mask
 * length
 */
#define PHPAL_SLI15693_FLAG_UID_MODE2    0x02U

/**
 * Extended Inventory Read Options Flag
 * If set the 16-bit CID will be transmitted in the command and only tags with the same CID
 * will respond
 */
#define PHPAL_SLI15693_FLAG_CID_COMPARE2           0x04U

/**
 * Extended Inventory Read Options Flag
 * If set the Custom ID(CID) is transmitted by the VICC to the reader
 */
#define PHPAL_SLI15693_FLAG_CID_RESPONSE2          0x08U

/**
 * Extended Inventory Read Options Flag
 * If set the VICC will go to quiet state after receiving the command
 *
 */
#define PHPAL_SLI15693_FLAG_QUIET2   0x20U

/**
 * Extended Inventory Read Options Flag
 * If set the VICC will go to quiet state after receiving the command
 *
 */
#define PHPAL_SLI15693_FLAG_PERSISTENT2   0x40U
/*@}*/


/**
* \name Request Flags 5 to 7 when inventory flag is not set.
* \anchor inv_not_set
*
* Flag 8 is RFU and shall be set to zero.
*/
/*@{*/
/**
 * Select_flag.
 *
 * If set only VICC in selected state shall respond. The Address_flag
 * #PHPAL_SLI15693_FLAG_ADDRESSED2 shall be set to 0 and the UID field will not
 * be included in the request. If not set Request shall be executed by any VICC
 * according to the setting of Address_flag #PHPAL_SLI15693_FLAG_ADDRESSED2.
 * */
#define PHPAL_SLI15693_FLAG_SELECTED2    0x10U

/**
 * Address_flag.
 *
 * If set request is addressed. UID field is included in request. It shall be
 * executed only by the VICC whose UID matches the UID specified in the request.
 * If not set request is not addressed. UID field is not included in request. It
 * shall be executed by any VICC.
 * */
#define PHPAL_SLI15693_FLAG_ADDRESSED2   0x20U

/**
 * Option_flag.
 *
 * Meaning is defined by the command description. It shall be set to 0 if not
 * otherwise defined by the command.
 * */
#define PHPAL_SLI15693_FLAG_OPTION2      0x40U
/*@}*/


/**
* \name Request Flags 5 to 7 when inventory flag is set.
* \anchor inv_set
*
* Flag 8 is RFU and shall be set to zero.
*/
/*@{*/
/**
 * Inventory flags mask.
 * */
#define PHPAL_SLI15693_MASK_INVENTORY_FLAGS2 0xF0U

/**
 * AFI_flag.
 *
 * If set AFI field is present in request. If not set AFI field is not present
 * in request.
 * */
#define PHPAL_SLI15693_FLAG_AFI2             0x10U

/**
 * Nb_slots_flag.
 *
 * If set Use 1 slot instead of 16 slots for inventory. If not set use 16 slots.
 * */
#define PHPAL_SLI15693_FLAG_NBSLOTS2         0x20U
/*@}*/


/**
* \name Response Flags 1 and 4 according to ISO15693.
*
* All others flags are RFU and shall not be interpreted.
*/
/*@{*/
/**
 * Error_flag.
 *
 * Error detected. Error code is in the "Error" field of response. When a
 * response is received from the VICC with the error flag set, library returns
 * the custom error code #PHPAL_SLI15693_ERR_ISO156932. The configuration option
 * #PHPAL_SLI15693_CONFIG_ADD_INFO2 can be used to get the actual \ref
 * error_codes "error code" returned by the VICC.
 * */
#define PHPAL_SLI15693_FLAG_RESP_ERROR2          0x01U

/**
 * Extension_flag.
 *
 * Protocol format is extended. Reserved for future use.
 * */
#define PHPAL_SLI15693_FLAG_RESP_EXTERNSION2     0x08U
/*@}*/


/**
* \name Response error codes according to ISO15693.
* \anchor error_codes
*
* Codes ranging from A0 - DF are custom command error codes.
*/
/*@{*/
/**
 * The command is not supported, i.e. the request code is not recognized.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_NOT_SUPPORTED2 0x01U

/**
 * The command is not recognized, for example: a format error occurred.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_FORMAT2        0x02U

/**
 * The command option is not supported.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_OPTION2        0x03U

/**
 * Error with no information given or a specific error code is not supported.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_GENERIC2       0x0FU

/**
 * The specified block is not available (doesn't exist).
 * */
#define PHPAL_SLI15693_FLAG_ERROR_BLOCK_NA2      0x10U

/**
 * The specified block is already locked and thus cannot be locked again.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_BLOCK_LOCKED12 0x11U

/**
 * The specified block is locked and its content cannot be changed.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_BLOCK_LOCKED22 0x12U

/**
 * The specified block was not successfully programmed.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_BLOCK_WRITE12  0x13U

/**
 * The specified block was not successfully locked.
 * */
#define PHPAL_SLI15693_FLAG_ERROR_BLOCK_WRITE22  0x14U

/**
 * \brief The baud rates supported by ISO15693 Tags
 */

/**
 * The default baud rate is 26kbps baud rate, is supported in both NFC and ISO mode
 */
#define PHPAL_SLI15693_26KBPS_DATARATE2          0x1AU

/**
 * 53kbps baud rate supported in TX and RX, but only RX is defined by ISO
 */
#define PHPAL_SLI15693_53KBPS_DATARATE2          0x1BU

/**
 * 106kbps baud rate supported in TX and RX, but only RX is defined by ISO
 */
#define PHPAL_SLI15693_106KBPS_DATARATE2         0x1CU

/**
 * 212kbps baud rate supported only in TX
 */
#define PHPAL_SLI15693_212KBPS_DATARATE2         0x1DU
/*@}*/


/**
* \name Lengths
*/
/*@{*/
/**
 * UID length in bytes.
 * */
#define PHPAL_SLI15693_UID_LENGTH2       0x08U

/**
 * Block length in bytes.
 * */
#define PHPAL_SLI15693_BLOCK_LENGTH2     0x04U

/**
 * Number of bytes per page.
 * */
#define PHPAL_SLI15693_PAGE_LENGTH2      0x10U
/*@}*/

/**
 * end of group phpalSli156932 ISO/IEC 15693 
 * @}
 */
#endif /* NXPBUILD__PHPAL_SLI156932 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
/** \addtogroup phpalSli15693_Sw2 Component : Software
* \brief Software component of ISO/IEC 15693 
* \ingroup phpalSli156932
* @{
*/

/**
 * \brief State for ActivateCard
 */
typedef enum {
	PHPAL_SLI15693_ACTCARD_START2 = 0,
	PHPAL_SLI15693_ACTCARD_INVENTORY2,
	PHPAL_SLI15693_ACTCARD_ONESLOT2,
	PHPAL_SLI15693_ACTCARD_SLOTMAKER2,
	PHPAL_SLI15693_ACTCARD_INVENTORY_LOOP2,
	PHPAL_SLI15693_ACTCARD_SENDEOF_LOOP2,
	PHPAL_SLI15693_ACTCARD_FINISH2,
	PHPAL_SLI15693_ACTCARD_SET_TIMEOUT2,
	PHPAL_SLI15693_ACTCARD_ACTIVATE_SELECTED2
} SLI15693_ACTCARD_StateType_t2;

/**
 * \brief State for Inventory
 */
typedef enum {
	PHPAL_SLI15693_INVENTORY_START2 = 0,
	PHPAL_SLI15693_INVENTORY_INIT2,
	PHPAL_SLI15693_INVENTORY_LOOP2,
	PHPAL_SLI15693_INVENTORY_FINISH2,
	PHHAL_SLI15693_INVENTORY_CONFIG_FAST_HIGH2,
	PHHAL_SLI15693_INVENTORY_CONFIG_FAST_LOW2,
	PHHAL_SLI15693_INVENTORY_CONFIG_FRAMING_SUCCESS2,
	PHPAL_SLI15693_INVENTORY_TIMEOUT_US2
} SLI15693_INVENTORY_StateType_t2;

/**
 * \brief State for SendEof
 */
typedef enum {
	PHPAL_SLI15693_SENDEOF_STATE_IDLE2 = 0,
	PHPAL_SLI15693_SENDEOF_STATE_WRITE_ALIKE_WITH_WAIT2,
	PHPAL_SLI15693_SENDEOF_STATE_GET_TIMEOUT2,
	PHPAL_SLI15693_SENDEOF_STATE_SET_TIMEOUT2,
	PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START12,
	PHPAL_SLI15693_SENDEOF_STATE_SEND2,
	PHPAL_SLI15693_SENDEOF_STATE_SET_SYMBOL_START22,
	PHPAL_SLI15693_SENDEOF_STATE_FINISH2
} SLI15693_SENDEOF_StateType_t2;

/**
 * \brief State for Exchange
 */
typedef enum {
	PHPAL_SLI15693_STATE_IDLE2 = 0,
	PHPAL_SLI15693_STATE_SET_TIMEOUT2,
	PHPAL_SLI15693_STATE_EXCHANGE2,
	PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_12,
	PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_22,
	PHPAL_SLI15693_STATE_EXCHANGE_WITHOUT_LEAVE_BUFFER_BIT_32
} SLI15693_EX_StateType_t2;

/**
 * end of group phpalSli15693_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
/** \addtogroup phpalSli15693_Sw2 Component : Software
* \brief Software component of ISO/IEC 15693 
* \ingroup phpalSli156932
* @{
*/

/**
* \brief Software Sli15693 PAL parameter structure
*/
typedef struct /* phpalSli15693_Sw_DataParams */
{
	/**
	 * ID for this component, not to be modified by user.
	 *
	 * This is initialized with #PHPAL_SLI15693_SW_ID2 in the initialization
	 * function \ref phpalSli15693_Sw_Init2. This is used for validating the
	 * data parameter structure and to make sure that APIs are called after
	 * initialization.
	 * */
  VAR(uint16, ANFCRL_VAR) wId2;

	/**
	 * Pointer to the HAL data parameter.
	 *
	 * This pointer is initialized with the address of HAL data parameter
	 * structure by \ref phpalSli15693_Sw_Init2.
	 * */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2;

	/**
	 * Holds the last error code sent by the VICC. But for Authentication
	 * Scenario contains the Flag Byte[non-error] as well.
	 *
	 * When a response is received from the VICC with the error flag
	 * #PHPAL_SLI15693_FLAG_RESP_ERROR2 set, the error code returned by VICC is
	 * stored here.
	 * */
  VAR(uint16, ANFCRL_VAR) wAdditionalInfo2;

	/**
	 * Flags.
	 *
	 * This holds the value of \ref req_flags "request flag" field used in the
	 * commands sent by the library.
	 * */
  VAR(uint8, ANFCRL_VAR) bFlags2;

	/**
	 * VICC's UID.
	 *
	 * This holds the value of VICC's Unique Identifier received during the
	 * inventory process, which always is of 8 bytes long.
	 * */
  VAR(uint8, ANFCRL_VAR) pUid2[8];

	/**
	 * VICC's UID length.
	 *
	 * This holds the value of VICC's UID length in bits. After successful
	 * inventory process, the complete UID length will be 64 bits.
	 * */
  VAR(uint8, ANFCRL_VAR) bUidBitLength2;

	/**
	 * Indicator of API to be in explicit Addressed mode
	 *
	 * This indicates that the api is explicitly asked to be used in addressed mode
	 * this parameter differentiate the understanding of explicitly addressed mode from the API like select
	 * and reset to ready which are implicitly addressed
	 * */
  VAR(uint8, ANFCRL_VAR) bExplicitlyAddressed2;

	/**
	 * Operation Mode. One of NFC, EMVCo, ISO.
	 */
  VAR(uint8, ANFCRL_VAR) bOpeMode2;

	/**
	 * Enable or disable the data buffering.
	 */
  VAR(uint8, ANFCRL_VAR) bBuffering2;

	/**
	 * Temporary Rx pointer for exchange if caller hasn't provided valid RxBuffer .
	 */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpRxBuff2;
	/**
	 * Temporary Rx length var for exchange if caller hasn't provided valid RxBuffer .
	 */
  VAR(uint16, ANFCRL_VAR) tmpRxLen2;
  VAR(uint8, ANFCRL_VAR) bAlICodeStateMachineState2;

  VAR(SLI15693_SENDEOF_StateType_t2, ANFCRL_VAR) eSendEofState2; /**< Handle state of SendEof function of SLI15693. */
  VAR(SLI15693_ACTCARD_StateType_t2, ANFCRL_VAR) eActCardState2; /**< Handle state of ActivateCard function of SLI15693. */
  VAR(SLI15693_INVENTORY_StateType_t2, ANFCRL_VAR) eInventoryState2; /**< Handle state of Inventory function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eStayQuietState2; /**< Handle state of StayQuiet function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eStayQuietPersistentState2; /**< Handle state of StayQuietPersistent function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eSelectState2; /**< Handle state of Select function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eResetToReadyState2; /**< Handle state of ResetToReady function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eExchangeState2; /**< Handle state of Exchange function of SLI15693. */
  VAR(SLI15693_EX_StateType_t2, ANFCRL_VAR) eSetConfigState2; /**< Handle state of SetConfig function of SLI15693. */

} phpalSli15693_Sw_DataParams_t2;

/**
 * end of group phpalSli15693_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_SLI15693_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phpalSli15693_Sw2 Component : Software
* \brief Software component of ISO/IEC 15693 
* \ingroup phpalSli156932
* @{
*/

/**
 * \brief Initialize PAL Sli15693 layer.
 *
 * This should be called before using any of the PAL Sli15693 APIs to do
 * initialization of the layer. This configures the Sli15693 PAL with default
 * configurations. Refer \ref config_palsli "configuration options" for
 * supported configurations and their default values.
 *
 * @param[in] pDataParams2    Pointer to PAL Sli15693 data parameter
 * structure \ref phpalSli15693_Sw_DataParams_t2.
 *
 * @param[in] wSizeOfDataParams2    Specifies the size of data parameter
 * structure \ref phpalSli15693_Sw_DataParams_t2.
 *
 * @param[in] pHalDataParams2    Pointer to the HAL data parameter structure.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_ERR_INVALID_DATA_PARAMS Invalid data parameter. Size of data
 *         parameter structure \ref phpalSli15693_Sw_DataParams_t2 specified in
 *         wSizeOfDataParams2 is wrong.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Sw_Init2(
                                 P2VAR(phpalSli15693_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                                 VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,
                                 P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2
                                 );

/**
 * end of group phpalSli15693_Sw2 Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */


#ifdef NXPBUILD__PHPAL_SLI156932

#define ANFCRL_START_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \addtogroup phpalSli156932 ISO/IEC 15693 
* \ingroup phpalProtocol
* \brief These component implements the protocol layer (activation) commands of
* ISO/IEC 15693 vicinity protocol.
*
* This implementation is based on ISO/IEC 15693-3:2009(E) specification. This
* layer also implements all activation related custom commands of NXP's ICODE
* SLI series of tags.
*
* Different states of a VICC (Vicinity Integrated Circuit Card) and
* corresponding commands are shown below.
*
* \image html palSli15693_states.png
*
* \b Note: PERSISTENT QUIET state is supported only by few ICODE SLI tags (like
* ICODE SLIX2). Refer \ref phpalSli15693_Inventory2 "function documentation" for
* more information on commands.
* @{
*/

#ifdef  NXPRDLIB_REM_GEN_INTFS2
#define phpalSli15693_Inventory2( pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, pDsfid2, pUid2) \
        phpalSli15693_Sw_Inventory2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bFlags2, bAfi2, pMask2,bMaskBitLength2, pDsfid2, pUid2)

#define phpalSli15693_SendEof2( pDataParams2, bOption2, pDsfid2, pUid2, pUidLength2, pData2, pDataLength2) \
        phpalSli15693_Sw_SendEof2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bOption2, pDsfid2, pUid2,pUidLength2, pData2, pDataLength2)

#define phpalSli15693_StayQuiet2( pDataParams2) \
        phpalSli15693_Sw_StayQuiet2((phpalSli15693_Sw_DataParams_t2*)pDataParams2)

#define phpalSli15693_Select2(pDataParams2) \
        phpalSli15693_Sw_Select2((phpalSli15693_Sw_DataParams_t2*)pDataParams2 )

#define phpalSli15693_ResetToReady2( pDataParams2) \
        phpalSli15693_Sw_ResetToReady2((phpalSli15693_Sw_DataParams_t2*)pDataParams2 )

#define phpalSli15693_Exchange2( pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2) \
        phpalSli15693_Sw_Exchange2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, wOption2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2 )

#define phpalSli15693_ActivateCard2( pDataParams2,  bOption2, bFlags2,  bAfi2, pMask2,  bMaskBitLength2, pDsfid2, pUid2, pMoreCardsAvailable2) \
        phpalSli15693_Sw_ActivateCard2((phpalSli15693_Sw_DataParams_t2*)pDataParams2,  bOption2, bFlags2, bAfi2, pMask2, bMaskBitLength2, pDsfid2, pUid2, pMoreCardsAvailable2)

#define phpalSli15693_GetSerialNo2( pDataParams2, pUid2,pUidLength2) \
        phpalSli15693_Sw_GetSerialNo2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, pUid2, pUidLength2 )

#define phpalSli15693_SetConfig2( pDataParams2, wConfig2, wValue2) \
        phpalSli15693_Sw_SetConfig2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, wConfig2, wValue2 )

#define phpalSli15693_GetConfig2( pDataParams2, wConfig2, pValue2) \
        phpalSli15693_Sw_GetConfig2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, wConfig2, pValue2 )

#define phpalSli15693_InventoryRead2( pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2, pData2, pDataLength2) \
        phpalSli15693_Sw_InventoryRead2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2, pData2, pDataLength2 )

#define phpalSli15693_InventoryReadExtended2( pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bExtendedOptions2, pCID2, bBlockNo2, wNoOfBlocks2, pCidOut2, pUid2, pUidLength2, pData2, pDataLength2) \
        phpalSli15693_Sw_InventoryReadExtended2((phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bExtendedOptions2, pCID2, bBlockNo2, wNoOfBlocks2, pCidOut2, pUid2, pUidLength2, pData2, pDataLength2)

#define phpalSli15693_FastInventoryRead2(pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2, pData2, pDataLength2 ) \
        phpalSli15693_Sw_FastInventoryRead2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pUid2, pUidLength2, pData2, pDataLength2 )

#define phpalSli15693_FastInventoryReadExtended2( pDataParams2, bFlags2, bAfi2, bExtendedOptions2, pCID2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pCidOut2, pUid2, pUidLength2, pData2, pDataLength2) \
        phpalSli15693_Sw_FastInventoryReadExtended2((phpalSli15693_Sw_DataParams_t2*) pDataParams2, bFlags2, bAfi2, bExtendedOptions2, pCID2, pMask2, bMaskBitLength2, bBlockNo2, wNoOfBlocks2, pCidOut2, pUid2, pUidLength2, pData2, pDataLength2)

#define phpalSli15693_InventoryPageRead2(pDataParams2,bFlags2,bAfi2,pMask2,bMaskBitLength2,bPageNo2,wNoOfPages2,pUid2,pUidLength2,pData2,pDataLength2) \
        phpalSli15693_Sw_InventoryPageRead2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bFlags2,bAfi2, pMask2, bMaskBitLength2,bPageNo2, wNoOfPages2, pUid2, pUidLength2, pData2, pDataLength2)

#define phpalSli15693_FastInventoryPageRead2(pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bPageNo2, wNoOfPages2, pUid2, pUidLength2, pData2, pDataLength2 ) \
        phpalSli15693_Sw_FastInventoryPageRead2((phpalSli15693_Sw_DataParams_t2*)pDataParams2, bFlags2, bAfi2, pMask2, bMaskBitLength2, bPageNo2, wNoOfPages2, pUid2, pUidLength2, pData2, pDataLength2 )

#define phpalSli15693_StayQuietPersistent2( pDataParams2) \
        phpalSli15693_Sw_StayQuietPersistent2((phpalSli15693_Sw_DataParams_t2*)pDataParams2)

#define phpalSli15693_SetSerialNo2( pDataParams2, pUid2,bUidLength) \
        phpalSli15693_Sw_SetSerialNo2((phpalSli15693_Sw_DataParams_t2 *) pDataParams2, pUid2,bUidLength)

#else

/**
* \brief Perform a ISO15693 Inventory command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the Inventory request, the VICC shall perform the
* anti-collision sequence. This is the fist command in the activation/detection
* sequence of VICC.
*
* When issuing the inventory command, the reader shall set the Nb_slots_flag
* #PHPAL_SLI15693_FLAG_NBSLOTS2 to the desired setting to select 1 slot or 16
* slots for the inventory process.
*
* The mask length indicates the number of significant bits of the mask value.
* It can have any value between 0 and 60 when 16 slots are used and any
* value between 0 and 64 when 1 slot is used. The mask value is contained in
* an integer number of bytes. If the mask length is not a multiple of 8 (bits),
* the mask value MSB shall be padded with the required number of null (set to 0)
* bits so that the mask value is contained in an integer number of bytes.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Inventory2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,      /**< [In] Pointer to this layers parameter structure. */
              VAR(uint8, ANFCRL_VAR) bFlags2,          /**< [In] \ref req_flags "Request flags" byte. */
              VAR(uint8, ANFCRL_VAR) bAfi2,            /**< [In] Application Family Identifier. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,         /**< [In] UID mask, holding known UID bits. */
              VAR(uint8, ANFCRL_VAR) bMaskBitLength2,  /**< [In] Number of UID bits within pMask2. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,        /**< [Out] Data Storage Format Identifier. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2           /**< [Out] Received UID. */
							);

/**
* \brief Send a ISO15693 EOF (End of Frame).
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When 16 slots are used in the inventory process, to switch to the next slot,
* the reader shall send an EOF with option #PHPAL_SLI15693_EOF_NEXT_SLOT2.
*
* To send EOF for write alike commands, #PHPAL_SLI15693_EOF_WRITE_ALIKE2 or
* #PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2 shall be used. For ICODE SLI custom
* commands like Inventory Read, #PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2 option
* shall be used.
*
* \c bOption2 can be one of:\n
* \li #PHPAL_SLI15693_EOF_NEXT_SLOT2
* \li #PHPAL_SLI15693_EOF_WRITE_ALIKE2
* \li #PHPAL_SLI15693_EOF_NEXT_SLOT_INV_READ2
* \li #PHPAL_SLI15693_EOF_WRITE_ALIKE_WITH_WAIT2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_INVALID_PARAMETER2 Invalid option
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SendEof2(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,        /**< [In] Pointer to this layers parameter structure. */
            VAR(uint8, ANFCRL_VAR) bOption2,           /**< [In] Option parameter. */
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,          /**< [Out] Data Storage Format Identifier. */
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,            /**< [Out] Received Uid */
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,      /**< [Out] Number of received UID bytes. */
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,           /**< [Out] Received data. */
            P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2     /**< [Out] Number of received data bytes. */
						);

/**
* \brief Perform a ISO15693 StayQuiet command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the Stay quiet command, the VICC shall enter the quiet state
* and shall not send back a response. There is no response to the stay quiet
* command.
*
* In quiet state, the VICC shall not process any request where Inventory_flag is
* set and the VICC shall process any addressed request. The VICC shall exit the
* quiet state when reset (power off), receiving a \ref phpalSli15693_Select2
* "select" request (It shall then go to the selected state if supported or
* return an error if not supported), receiving a \ref phpalSli15693_ResetToReady2
* "Reset to ready request" (It shall then go to the Ready state).
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_USE_CONDITION2 No UID available.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_StayQuiet2(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2    /**< [In] Pointer to this layers parameter structure. */
						);

/**
* \brief Perform a ISO15693 Select command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the Select command, if the UID is equal to its own UID, the
* VICC shall enter the selected state and shall send a response. If the UID is
* different to its own and in selected state, the VICC shall return to the Ready
* state and shall not send a response. If the UID is different to its own and
* not in selected state, the VICC shall remain in its state and shall not send
* a response.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_USE_CONDITION2 No UID available.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Select2(
            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2    /**< [In] Pointer to this layers parameter structure. */
						);

/**
* \brief Perform a ISO15693 ResetToReady command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving a Reset to ready command, the VICC shall return to the Ready
* state.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_ResetToReady2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2    /**< [In] Pointer to this layers parameter structure. */
							);

/**
* \brief Perform ISO15693 Data Exchange with VICC.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \c wOption2 can be one of:\n
* \li #PH_EXCHANGE_DEFAULT2
* \li #PH_EXCHANGE_BUFFER_FIRST2
* \li #PH_EXCHANGE_BUFFER_CONT2
* \li #PH_EXCHANGE_BUFFER_LAST2
*
* Alternatively, the following bits can be combined:\n
* \li #PH_EXCHANGE_BUFFERED_BIT2
* \li #PH_EXCHANGE_LEAVE_BUFFER_BIT2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_USE_CONDITION2 No UID available.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_Exchange2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,       /**< [In] Pointer to this layers parameter structure. */
              VAR(uint16, ANFCRL_VAR) wOption2,         /**< [In] Option parameter. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,      /**< [In] Data to transmit. Flags, IC MFC code and UID will be added automatically. */
              VAR(uint16, ANFCRL_VAR) wTxLength2,       /**< [In] Length of data to transmit. */
              P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,    /**< [Out] Pointer to received data. */
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2      /**< [Out] number of received data bytes. */
							);

/**
* \brief Perform ISO15693 ActivateCard command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* This function activates the first VICC detected during the collision
* resolution and optionally move it to selected state based on the wOption2
* specified.
*
* \c wOption2 can be one of:\n
* \li #PHPAL_SLI15693_ACTIVATE_DEFAULT2
* \li #PHPAL_SLI15693_ACTIVATE_SELECTED2
* \li #PHPAL_SLI15693_ACTIVATE_ADDRESSED2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_ActivateCard2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,             /**< [In] Pointer to this layers parameter structure. */
                VAR(uint8, ANFCRL_VAR) bOption2,                 /**< [In] Selected or addressed */
                VAR(uint8, ANFCRL_VAR) bFlags2,                  /**< [In] Request flags byte. */
                VAR(uint8, ANFCRL_VAR) bAfi2,                    /**< [In] Application Family Identifier. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,                  /**< [In] UID mask, holding known UID bits. */
                VAR(uint8, ANFCRL_VAR) bMaskBitLength2,          /**< [In] Number of UID bits within pMask2. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDsfid2,                 /**< [Out] Data Storage Format Identifier. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,                   /**< [Out]Received UID of first found card */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2     /**< [Out] If there are more cards available this value is different from zero.    */
								);

/**
* \brief Retrieve the serial number (UID).
*
* This API is used to get the UID of current VICC with which this layer is
* communicating.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_USE_CONDITION2 No UID available.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_GetSerialNo2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layers parameter structure. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,        /**< [Out] Buffer, holding the UID (8 bytes) */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2   /**< [Out] Length of received UID bytes. */
							);

/**
* \brief Set serial number (UID).
*
* When multiple VICCs are detected, this API shall be used to set a specific UID
* to this layer from the list of detected UIDs.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_INVALID_PARAMETER2 UID length invalid.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SetSerialNo2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layers parameter structure. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,        /**< [In] Buffer, holding the UID (8 bytes) */
              VAR(uint8, ANFCRL_VAR) bUidLength     /**< [In] Length of UID in bytes. */
							);

/**
* \brief Set value of the specified \ref config_palsli
* "configuration identifier".
*
* The SetConfig command is used to set values for the different configuration
* parameters of this layer.
*
* \c wConfig2 can be one of:\n
* \li #PHPAL_SLI15693_CONFIG_FLAGS2
* \li #PHPAL_SLI15693_CONFIG_ADD_INFO2
* \li #PHPAL_SLI15693_CONFIG_TIMEOUT_US2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Invalid wConfig2.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_SetConfig2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
              VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Item to configure. */
              VAR(uint16, ANFCRL_VAR) wValue2      /**< [In] Value to set. */
							);

/**
* \brief Get value of the specified \ref config_palsli
* "configuration identifier".
*
* The GetConfig command is used to  retrieve values of different configuration
* parameters of this layer.
*
* \c wConfig2 can be one of:\n
* \li #PHPAL_SLI15693_CONFIG_FLAGS2
* \li #PHPAL_SLI15693_CONFIG_ADD_INFO2
* \li #PHPAL_SLI15693_CONFIG_TIMEOUT_US2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Invalid wConfig2.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_GetConfig2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layers parameter structure. */
              VAR(uint16, ANFCRL_VAR) wConfig2,    /**< [In] Item to read. */
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2    /**< [In] Read value. */
							);

/**
* \brief Perform ICODE SLI InventoryRead command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the INVENTORY READ request, the ICODE SLI tag performs the same
* as the anti-collision sequence, with the difference that instead of the UID
* and the DSFID, the requested memory content is re-transmitted from the ICODE
* SLI. If an error is detected, the ICODE SLI tag remains silent.
*
* If the Option_flag #PHPAL_SLI15693_FLAG_OPTION2 is not set, n blocks of data
* are re-transmitted. If the Option_flag is set, n blocks of data and the part
* of the UID which is not part of the mask are re-transmitted. Additionally the
* slot number in case of 16 slots, are returned. Instead of padding with zeros
* up to the next byte boundary, the corresponding bits of the UID are returned.
*
* The number of bits of the re-transmitted UID can be calculated as follows:
*  - 16 slots: 60 bits (bit 64 to bit 4) - mask length rounded up to the
*    next byte boundary.
*  - 1 slot: 64 bits - mask length rounded up to the next byte boundary.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of blocks
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryRead2(
              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,      /**< [In] Pointer to this layers parameter structure. */
              VAR(uint8, ANFCRL_VAR) bFlags2,          /**< [In] \ref req_flags "Request flags" byte. */
              VAR(uint8, ANFCRL_VAR) bAfi2,            /**< [In] Application Family Identifier. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,         /**< [In] UID mask, holding known UID bits. */
              VAR(uint8, ANFCRL_VAR) bMaskBitLength2,  /**< [In] Number of UID bits within pMask2. */
              VAR(uint8, ANFCRL_VAR) bBlockNo2,        /**< [In] Block number of first block to read. */
              VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,    /**< [In] Number of blocks to read */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,          /**< [Out] Received UID */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,    /**< [Out] Number of received UID bytes. */
              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,         /**< [Out] Received data. */
              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2   /**< [Out] Number of received data bytes. */
							);

/**
* \brief Perform ICODE SLI InventoryRead command in extended mode.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the INVENTORY READ EXTENDED request, the ICODE SLI tag performs the same
* as the anti-collision sequence, with the difference that instead of the UID
* and the DSFID, the requested memory content is re-transmitted from the ICODE
* SLI. If an error is detected, the ICODE SLI tag remains silent.
*
* If the Option_flag #PHPAL_SLI15693_FLAG_OPTION2 is not set, n blocks of data
* are re-transmitted. If the Option_flag is set, n blocks of data and the part
* of the UID which is not part of the mask are re-transmitted. Additionally the
* slot number in case of 16 slots, are returned. Instead of padding with zeros
* up to the next byte boundary, the corresponding bits of the UID are returned.
*
* The number of bits of the re-transmitted UID can be calculated as follows:
*  - 16 slots: 60 bits (bit 64 to bit 4) - mask length rounded up to the
*    next byte boundary.
*  - 1 slot: 64 bits - mask length rounded up to the next byte boundary.
*
*
* Depending on different values of Extended Options the api behaves differently
* b1 - 0 --> Label responds independent from the EAS status
* b1 - 1 --> Only labels will respond which have the EAS enabled
* b2 - 0 --> UID will be transmitted as in regular mode
* b2 - 1 --> Complete UID will be transmitted
* b3 - 0 --> No CID is transmitted in the command
* b3 - 1 --> 16 bits CID will be transmitted in the command and only matching tags should reply
* b4 - 0 --> CID will not be transmitted in the response from the tag
* b4 - 1 --> CID will be transmitted in the response from the tag
* b5 - 0 --> tag will add the user memory block in the response as requested
* b5 - 1 --> no user memory data is requested from the tag
* b6 & b7 - 00 --> Remain in current state
* b6 & b7 - 10 --> Go to quiet state after response
* b6 & b7 - 01 --> Go to persistent quiet state after response
* b6 & b7 - 11 --> Only tags in the PERSISTENT QUIET state will respond to the command
* b8 - 0 --> RFU
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of blocks
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryReadExtended2(
                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,      /**< [In] Pointer to this layers parameter structure. */
                  VAR(uint8, ANFCRL_VAR) bFlags2,          /**< [In] \ref req_flags "Request flags" byte. */
                  VAR(uint8, ANFCRL_VAR) bAfi2,            /**< [In] Application Family Identifier. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,         /**< [In] UID mask, holding known UID bits. */
                  VAR(uint8, ANFCRL_VAR) bMaskBitLength2,  /**< [In] Number of UID bits within pMask2. */
                  VAR(uint8, ANFCRL_VAR) bExtendedOptions2,   /**< [In] Features of the extended mode */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,          /**< [In] Two byte CID -> if marked in extended options */
                  VAR(uint8, ANFCRL_VAR) bBlockNo2,        /**< [In] Block number of first block to read. */
                  VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,    /**< [In] Number of blocks to read */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,       /**< [Out] Received CustomId */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,          /**< [Out] Received UID */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,    /**< [Out] Number of received UID bytes. */
                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,         /**< [Out] Received data. */
                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2   /**< [Out] Number of received data bytes. */
									);

/**
* \brief Perform ICODE SLI FastInventoryRead command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the FAST INVENTORY READ command the ICODE SLI tag behaves the
* same as the \ref phpalSli15693_InventoryRead2 "INVENTORY READ" command with the
* exceptions that the data rate in the direction ICODE SLI tag to the reader is
* twice than defined in ISO/IEC 15693-3 depending on the Datarate_flag 53 kbit
* (high data rate) or 13 kbit (low data rate).
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of blocks
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryRead2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layers parameter structure. */
                VAR(uint8, ANFCRL_VAR) bFlags2,             /**< [In] \ref req_flags "Request flags" byte. */
                VAR(uint8, ANFCRL_VAR) bAfi2,               /**< [In] Application Family Identifier. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,            /**< [In] UID mask, holding known UID bits. */
                VAR(uint8, ANFCRL_VAR) bMaskBitLength2,     /**< [In] Number of UID bits within pMask2. */
                VAR(uint8, ANFCRL_VAR) bBlockNo2,           /**< [In] Block number of first block to read. */
                VAR(uint16, ANFCRL_VAR) wNoOfBlocks2,       /**< [In] Number of blocks to read */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,             /**< [Out] Received UID */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,       /**< [Out]  Number of received UID bytes. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,            /**< [Out]  Received data. */
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2      /**< [Out]  Number of received data bytes. */
								);


/**
* \brief Perform ICODE SLI FastInventoryRead command in extended mode.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the FAST INVENTORY READ command the ICODE SLIX2 \ DNA tag behaves the
* same as the \ref phpalSli15693_InventoryReadExtended2 "INVENTORY READ EXTENDED" command
* with the exceptions that the data rate in the direction ICODE SLIX2 \ DNA tag to the reader is
* twice than defined in ISO/IEC 15693-3 depending on the Datarate_flag 53 kbit
* (high data rate) or 13 kbit (low data rate).
*
* If the Option_flag #PHPAL_SLI15693_FLAG_OPTION2 is not set, n blocks of data
* are re-transmitted. If the Option_flag is set, n blocks of data and the part
* of the UID which is not part of the mask are re-transmitted. Additionally the
* slot number in case of 16 slots, are returned. Instead of padding with zeros
* up to the next byte boundary, the corresponding bits of the UID are returned.
*
* The number of bits of the re-transmitted UID can be calculated as follows:
*  - 16 slots: 60 bits (bit 64 to bit 4) - mask length rounded up to the
*    next byte boundary.
*  - 1 slot: 64 bits - mask length rounded up to the next byte boundary.
*
*
* Depending on different values of Extended Options the api behaves differently
* b1 - 0 --> Label responds independent from the EAS status
* b1 - 1 --> Only labels will respond which have the EAS enabled
* b2 - 0 --> UID will be transmitted as in regular mode
* b2 - 1 --> Complete UID will be transmitted
* b3 - 0 --> No CID is transmitted in the command
* b3 - 1 --> 16 bits CID will be transmitted in the command and only matching tags should reply
* b4 - 0 --> CID will not be transmitted in the response from the tag
* b4 - 1 --> CID will be transmitted in the response from the tag
* b5 - 0 --> tag will add the user memory block in the response as requested
* b5 - 1 --> no user memory data is requested from the tag
* b6 & b7 - 00 --> Remain in current state
* b6 & b7 - 10 --> Go to quiet state after response
* b6 & b7 - 01 --> Go to persistent quiet state after response
* b6 & b7 - 11 --> Only tags in the PERSISTENT QUIET state will respond to the command
* b8 - 0 --> RFU
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of blocks
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryReadExtended2(
                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,        /**< [In] Pointer to this layers parameter structure. */
                     VAR(uint8, ANFCRL_VAR) bFlags2,            /**< [In] Request flags byte. */
                     VAR(uint8, ANFCRL_VAR) bAfi2,              /**< [In] Application Family Identifier. */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,           /**< [In] UID mask, holding known UID bits. */
                     VAR(uint8, ANFCRL_VAR) bMaskBitLength2,    /**< [In] Number of UID bits within pMask2. */
                     VAR(uint8, ANFCRL_VAR) bExtendedOptions2,  /**< [In] Extended options */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID2,            /**< [In] Two byte CID -> if marked in extended options */
                     VAR(uint8, ANFCRL_VAR) bBlockNo2,          /**< [In] Block Number from where start reading */
                     VAR(uint16, ANFCRL_VAR) wNumOfBlocks,     /**< [In] Number of blocks to read */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,         /**< [Out] Received CID. */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,            /**< [Out] Received UID. */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,      /**< [Out] Received UID Length. */
                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,           /**< [Out] Received Data. */
                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2     /**< [Out] Received Data Length. */
									   );

/**
* \brief Perform ICODE SLI InventoryPageRead command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the Inventory Page Read request, the ICODE SLI tag performs the
* same as in the anti-collision sequence, with the difference that instead of
* the UID and the DSFID the requested memory content is re-transmitted from the
* tag.
*
* If an error is detected the ICODE SLI tag remains silent.
*
* If the Option_flag #PHPAL_SLI15693_FLAG_OPTION2 is not set, n pages of data
* including page protection status (password protection condition) are
* re-transmitted. If the Option_flag is set, n pages (4 blocks = 16 byte) of
* data including page protection status (password protection condition) and the
* part of the UID which is not part of the mask are re-transmitted. Additionally
* the slot number in case of 16 slots, are returned.
*
* The number of bits of the re-transmitted UID can be calculated as follows:
*  - 16 slots: 60 bits (bit 64 to bit 4) - mask length rounded up to the
*    next byte boundary.
*  - 1 slot: 64 bits - mask length rounded up to the next byte boundary.
*
*  If a requested page is protected with the Read password and the valid Read
*  password has not been transmitted before, the page is not read and only
*  protection status (0x0F) is returned.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of pages
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_InventoryPageRead2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layers parameter structure. */
                VAR(uint8, ANFCRL_VAR) bFlags2,             /**< [In] \ref req_flags "Request flags" byte. */
                VAR(uint8, ANFCRL_VAR) bAfi2,               /**< [In] Application Family Identifier. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,            /**< [In] UID mask, holding known UID bits. */
                VAR(uint8, ANFCRL_VAR) bMaskBitLength2,     /**< [In] Number of UID bits within pMask2. */
                VAR(uint8, ANFCRL_VAR) bPageNo2,            /**< [In] Block number of first page to read. */
                VAR(uint16, ANFCRL_VAR) wNoOfPages2,        /**< [In] Number of pages to read */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,             /**< [Out] Received UID */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,       /**< [Out] Number of received UID bytes. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,            /**< [Out] Received data. */
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2      /**< [Out] Number of received data bytes. */
								);

/**
* \brief Perform ICODE SLI FastInventoryPageRead command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* When receiving the Fast Inventory Page Read command the ICODE SLI tag behaves
* the same as in the \ref phpalSli15693_InventoryPageRead2 "Inventory Page Read"
* command with the exceptions that the data rate in the direction of tag to the
* reader is twice as defined in ISO/IEC 15693-3, depending on the datarate_flag
* 53 kbit (high data rate) or 13 kbit (low data rate).

* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PHPAL_SLI15693_ERR_ISO156932 error response from VICC.
* \retval #PH_ERR_INVALID_PARAMETER2 mask length or flag or number of pages
*         invalid.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_FastInventoryPageRead2(
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layers parameter structure. */
                VAR(uint8, ANFCRL_VAR) bFlags2,             /**< [In] \ref req_flags "Request flags" byte. */
                VAR(uint8, ANFCRL_VAR) bAfi2,               /**< [In] Application Family Identifier. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask2,            /**< [In] UID mask, holding known UID bits. */
                VAR(uint8, ANFCRL_VAR) bMaskBitLength2,     /**< [In] Number of UID bits within pMask2. */
                VAR(uint8, ANFCRL_VAR) bPageNo2,            /**< [In] Block number of first page to read. */
                VAR(uint16, ANFCRL_VAR) wNoOfPages2,        /**< [In] Number of pages to read */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid2,             /**< [Out] Received UID */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength2,       /**< [Out] Number of received UID bytes. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,            /**< [Out] Received data. */
                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength2      /**< [Out] Number of received data bytes. */
								);

/**
* \brief Perform ICODE SLI Stay quite persistent command.
*
* When receiving the STAY QUIET PERSISTENT command, the tag enters the
* persistent quiet state and will not send back a response.
*
* The STAY QUIET PERSISTENT command provides the same behavior as the mandatory
* \ref phpalSli15693_StayQuiet2 "STAY QUIET" command with the only difference at
* a reset (power off), the tag will turn to the ready state, if the power off
* time is exceeding the persistent time. Refer the corresponding ICODE SLI tag
* specification for the value of persistent time.
*
* The tag will exit the persistent quiet state when:
* - reset (power off) exceeding the persistent time.
* - receiving a SELECT request. It shall then go to the Selected state.
* - receiving a RESET TO READY request. It shall then go to the Ready state.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_USE_CONDITION2 No UID available.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalSli15693_StayQuietPersistent2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2           /**< [In] Pointer to this layers parameter structure. */
    );

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalSli156932 ISO/IEC 15693 
 * @}
 */

#ifdef  NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phpalSli156932/src/Sw/phpalSli15693_Sw2.h"
#endif  /* NXPRDLIB_REM_GEN_INTFS2 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALSLI15693_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHPAL_SLI156932 */

#ifdef __cplusplus
}
#endif
#endif /* PHPALSLI156932_H */
