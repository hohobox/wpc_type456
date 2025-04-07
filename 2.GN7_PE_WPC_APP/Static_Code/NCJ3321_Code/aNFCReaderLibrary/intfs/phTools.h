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
*   @file    phTools.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Tools - Common API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phTools Tools
*   @ingroup phcommon
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
#ifndef PHTOOLS_H
#define PHTOOLS_H

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
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTools.h
* @implements     DESIGN001, DESIGN002
*/
#define PHTOOLS_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHTOOLS_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHTOOLS_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHTOOLS_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHTOOLS_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHTOOLS_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHTOOLS_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHTOOLS_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHTOOLS_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phTools.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHTOOLS_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHTOOLS_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phTools.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHTOOLS_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHTOOLS_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHTOOLS_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phTools.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup phTools Tools
* \ingroup phcommon
* \brief This component implements tools that are necessary for many different software modules
* @{
*/

#define PH_TOOLS_EVENT_IDLE			0u
#define PH_TOOLS_EVENT_PENDING		1u
#define PH_TOOLS_EVENT_OCCUR		2u

#define PH_TOOLS_EVENT_MAX_DELAY      (0xFFFFFFFFU)

/**
 * \brief Event Management Options
 * @{
 */
#define E_EVENT_OPT_NONE                0x00u
#define E_EVENT_OPT_PEND_SET_ANY        0x01u
#define E_EVENT_OPT_PEND_SET_ALL        0x02u
#define E_EVENT_OPT_PEND_CLEAR_ON_EXIT  0x04u
#define E_EVENT_OPT_POST_ISR            0x08u
#define E_EVENT_OPT_CLR_ISR             0x10u
/*@}*/

/**
* \name ToolsConfigs
*/
/*@{*/
#define PH_TOOLS_CRC16_PRESET_ISO14443A 0x6363U     /**< CRC16 Preset for ISO14443-A. */
#define PH_TOOLS_CRC16_PRESET_ISO14443B 0xFFFFU     /**< CRC16 Preset for ISO14443-B. */
#define PH_TOOLS_CRC16_PRESET_FELICA    0x0000U     /**< CRC16 Preset for Felica. */
#define PH_TOOLS_CRC16_POLY_ISO14443    0x8408U     /**< CRC16 Polynomial for ISO14443. */
#define PH_TOOLS_CRC32_PRESET_DF8       0xFFFFFFFFU /**< CRC32 Preset for DesFire. */
#define PH_TOOLS_CRC32_POLY_DF8         0xEDB88320U /**< CRC32 Polynomial for DesFire. */
#define PH_TOOLS_CRC8_PRESET_EPC        0xFFU       /**< Preset value for EPC CRC-8 generation. */
#define PH_TOOLS_CRC8_PRESET_UID        0xFDU       /**< Preset value for UID CRC-8 generation. */
#define PH_TOOLS_CRC8_POLY_EPCUID       0x1DU       /**< Polynomial for EPC/UID CRC-8 generation: x^8 + x^4 + x^3 + x^2 + 1 (MSB first). */
#define PH_TOOLS_CRC16_PRESET_EPCUID    0xFFFFU     /**< Preset value for EPC/UID CRC-16 generation. */
#define PH_TOOLS_CRC16_POLY_EPCUID      0x1021U     /**< Polynomial for EPC/UID CRC-16 generation: x^16 + x^12 + x^5 + 1 (MSB first). */
#define PH_TOOLS_CRC16_POLY_FELICA      0x1021U     /**< Polynomial for Felica CRC-16 generation: x^16 + x^12 + x^5 + 1 (MSB first). */
#define PH_TOOLS_PARITY_OPTION_EVEN         0x00U   /**< Encode/Decode even parity bits. */
#define PH_TOOLS_PARITY_OPTION_ODD          0x01U   /**< Encode/Decode odd parity bits. */

#define PH_TOOLS_CRC_OPTION_DEFAULT         0x00U   /**< Default CRC operation. */
#define PH_TOOLS_CRC_OPTION_OUPUT_INVERTED  0x01U   /**< Inverts the bits after calculation. */
#define PH_TOOLS_CRC_OPTION_MSB_FIRST       0x02U   /**< Calculates CRC with MSB(it) first. */
#define PH_TOOLS_CRC_OPTION_BITWISE         0x04U   /**< Bitwise CRC, \c wDataLength represents the Bit length. */
#define PH_TOOLS_CRC_OPTION_MASK            0x07U   /**< Mask of valid option bits. */
/*@}*/

/**
* \name Q Configs
*/
/*@{*/
#define PH_TOOLS_Q_MAX_ELEMENTS             10U      /* Indicates maximum elements in the Q pool */
#define PH_TOOLS_Q_RESERVED_ELEMENTS        2U       /* Indicates reserved elements in the Q pool for high priority tasks. */
/*@}*/

#define PH_TOOLS_Q_DATA_TO_BE_SENT 		0x01U     /**< Message needs to be sent. */
#define PH_TOOLS_Q_RX_DATA				PH_TOOLS_Q_DATA_TO_BE_SENT + 1U     /**< Message is received. */

#ifndef min_val
#   define min_val(X,Y) (((X) < (Y)) ? (X) : (Y))
#endif

/**
 * end of group phTools Tools
 * @}
 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/** \addtogroup phTools Tools
* \ingroup phcommon
* \brief This component implements tools that are necessary for many different software modules
* @{
*/

/**
* \brief Type of Queue Message.
*/
#if 0
typedef enum{
    PH_TOOLS_Q_DATA_TO_BE_SENT = 0x01,  /**< Message needs to be sent. */
    PH_TOOLS_Q_RX_DATA                  /**< Message is received. */
} phTools_Q_Type_t;
#endif

/**
 * end of group phTools Tools
 * @}
 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/** \addtogroup phTools Tools
* \ingroup phcommon
* \brief This component implements tools that are necessary for many different software modules
* @{
*/

/**
*
* \brief Polling Event callback interface which will be called every time calling EventPend.
* \retval  None
*/
typedef void (*phTools_PollFunc_t)(void* pDataParams);

/**
 * Event Handle.
 * @{
 */
typedef VAR(uint32, ANFCRL_VAR) phTools_Event_t;
/*@}*/

/**
 * \brief Event Management Options
 * @{
 */
typedef VAR(uint8, ANFCRL_VAR) phTools_EventOpt_t;
/*@}*/

/**
 * Event Management Object.
 * \brief Holds all parameters and status for management Event
 * @{
 */
typedef struct /* phTools_EventObj_t */
{
  VAR(phTools_Event_t, ANFCRL_VAR) wEventHandle;                       /**< Event Handler. */

  VAR(uint8, ANFCRL_VAR) bEventState;                                /**< Event is pending or idle. */

  VAR(uint32, ANFCRL_VAR) wTimeToWait;                              /**< Timeout of Event (in millisecond). */

  VAR(uint32, ANFCRL_VAR) wEventTimeStart;                           /**< Store Start point of timer. */

  VAR(phStatus_t, ANFCRL_VAR) dEventStatus;                            /**< Return Event status. */

  VAR(phTools_PollFunc_t, ANFCRL_VAR) pEventPollFunc;                 /**< Function pointer of EventPoll function. */

  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pEventPollParams;                            /**< Data parameters are used in EventPoll function. */

} phTools_EventObj_t;
/*@}*/

/**
 * Event Bits
 * @{
 */
typedef VAR(uint32, ANFCRL_VAR) phTools_EventBits_t;
/*@}*/

/**
* \brief Queue structure of Message Queue.
*/
typedef struct phTools_Q
{
    void    * pSender;                /**< Sender of the message. As this is void pointer pointing to the sender's context,
                                           bSenderType determines the actual type of the sender to allow proper casting. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbData;                  /**< Content of the message, type of the content is given using bType. */
    VAR(uint32, ANFCRL_VAR) dwLength;                /**< Length of the message. */
    VAR(uint8, ANFCRL_VAR) bLlcpBuf[6];              /**< Buffer used to store LLCP formatted PDUs that needs to be sent while processing Message Queue. */
    VAR(uint8, ANFCRL_VAR) bLlcpData;                /**< This variable is used to decide if LLCP framed data should be sent or data from application. */
    struct phTools_Q *pNext;          /**< Pointer to next element in the list/queue. */
    VAR(uint16, ANFCRL_VAR) wFrameOpt;               /**< Frame Option can take PH_TRANSMIT_DEFAULT, PH_TRANSMIT_BUFFER_FIRST,
                                           PH_TRANSMIT_BUFFER_CONT, or PH_TRANSMIT_BUFFER_LAST. */
    VAR(uint8, ANFCRL_VAR) bSenderType;              /**< Type of the sender, used for proper casting of pSender. */
    VAR(uint8, ANFCRL_VAR) bType;                 /**< Message content type. It can be either data to be sent/received data. */
} phTools_Q_t;

/**
 * end of group phTools Tools
 * @}
 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phTools Tools
* \ingroup phcommon
* \brief This component implements tools that are necessary for many different software modules
* @{
*/

/**
* \name Q Configs
*/
/*@{*/
#if (PH_TOOLS_Q_MAX_ELEMENTS > 32U)
#   error "PH_TOOLS_Q_MAX_ELEMENTS can have a max value of 32."
#endif /* PH_TOOLS_Q_MAX_ELEMENTS > 32 */
/*@}*/

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventCreate(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_PollFunc_t, ANFCRL_VAR) pPollFunc, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPollFuncParam);

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventPend(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(uint32, ANFCRL_VAR) timeToWait, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToWait,
    P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags);

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventPost(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToPost,
    P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags);

FUNC(phStatus_t, ANFCRL_CODE) phTools_EventClear(P2VAR(phTools_EventObj_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, VAR(phTools_EventOpt_t, ANFCRL_VAR) options, VAR(phTools_EventBits_t, ANFCRL_VAR) FlagsToClear,
    P2VAR(phTools_EventBits_t, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags);

/**
* \brief Calculate even or odd parity.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_EncodeParity(
                                VAR(uint8, ANFCRL_VAR) bOption,                /**< [In] Parity option; e.g. #PH_TOOLS_PARITY_OPTION_EVEN. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer,            /**< [In] Array to input data. */
                                VAR(uint16, ANFCRL_VAR) wInBufferLength,       /**< [In] Length of input data in bytes. */
                                VAR(uint8, ANFCRL_VAR) bInBufferBits,          /**< [In] Number of valid bits in last byte of pInBuffer. */
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize,        /**< [In] Size of the output buffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer,           /**< [Out] Output buffer. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength,    /**< [Out] Number of valid bytes in pOutBuffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits        /**< [Out] Number of valid bits in last byte of pOutBuffer. */
                                );

/**
* \brief Verify and Remove even or odd parity.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_DecodeParity(
                                VAR(uint8, ANFCRL_VAR) bOption,                /**< [In] Parity option; e.g. #PH_TOOLS_PARITY_OPTION_EVEN. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer,            /**< [In] Array to input data. */
                                VAR(uint16, ANFCRL_VAR) wInBufferLength,       /**< [In] Length of input data in bytes. */
                                VAR(uint8, ANFCRL_VAR) bInBufferBits,          /**< [In] Number of valid bits in last byte of pInBuffer. */
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize,        /**< [In] Size of the output buffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer,           /**< [Out] Output buffer. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength,    /**< [Out] Number of valid bytes in pOutBuffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits        /**< [Out] Number of valid bits in last byte of pOutBuffer. */
                                );

/**
* \brief Calculate a CRC 5
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc5(
                                 VAR(uint8, ANFCRL_VAR) bOption,       /**< [In] Specifies whether the output should be inverted or not. */
                                 VAR(uint8, ANFCRL_VAR) bPreset,       /**< [In] Preset used for CRC calculation, */
                                 VAR(uint8, ANFCRL_VAR) bPolynom,      /**< [In] Polynomial used for reduction*/
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,       /**< [In] Array to input data. */
                                 VAR(uint16, ANFCRL_VAR) wDataLength,  /**< [In] Length of input data. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc         /**< [Out] Resulting CRC. */
                                 );

/**
* \brief Calculate a CRC 8
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc8(
                                 VAR(uint8, ANFCRL_VAR) bOption,       /**< [In] Specifies whether the output should be inverted or not. */
                                 VAR(uint8, ANFCRL_VAR) bPreset,       /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC8_PRESET_UID. */
                                 VAR(uint8, ANFCRL_VAR) bPolynom,      /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC8_POLY_EPCUID. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,       /**< [In] Array to input data. */
                                 VAR(uint16, ANFCRL_VAR) wDataLength,  /**< [In] Length of input data. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc         /**< [Out] Resulting CRC. */
                                 );

/**
* \brief Calculate a CRC 16
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc16(
                                  VAR(uint8, ANFCRL_VAR) bOption,      /**< [In] Specifies whether the output should be inverted or not. */
                                  VAR(uint16, ANFCRL_VAR) wPreset,     /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC16_PRESET_ISO14443A. */
                                  VAR(uint16, ANFCRL_VAR) wPolynom,    /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC16_POLY_ISO14443. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,      /**< [In] Array to input data. */
                                  VAR(uint16, ANFCRL_VAR) wDataLength, /**< [In] Length of input data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pCrc       /**< [Out] Resulting CRC. */
                                  );

/**
* \brief Calculate a CRC 32
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_CalculateCrc32(
                                  VAR(uint8, ANFCRL_VAR) bOption,      /**< [In] Specifies whether the output should be inverted or not. */
                                  VAR(uint32, ANFCRL_VAR) dwPreset,    /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC32_PRESET_DF8. */
                                  VAR(uint32, ANFCRL_VAR) dwPolynom,   /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC32_POLY_DF8. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,      /**< [In] Array to input data. */
                                  VAR(uint16, ANFCRL_VAR) wDataLength, /**< [In] Length of input data. */
                                  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pCrc       /**< [Out] Resulting CRC. */
                                  );

/**
* \brief Calculate a CRC_B
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_ComputeCrc_B(
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,        /**< [In] Array to input data. */
                                VAR(uint32, ANFCRL_VAR) dwLength,     /**< [In] Length of input data. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc          /**< [Out] Resulting Two byte CRC. */
                                );

/**
* \brief The function gets the Version of the Firmware of DUT.
* \return Status code
* \retval #PH_ERR_SUCCESS Command successfully executed.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid frame or unexpected receive data length or command code mismatch.
*/
FUNC(phStatus_t, ANFCRL_CODE) phTools_GetVersion(
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProductVer,          /**< [OUT] Product Version. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pMajor,              /**< [OUT] Major Version. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMinor,               /**< [OUT] Minor Version. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPatch_Dev,          /**< [OUT] Development/Patch Version. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionString,       /**< [OUT] Version String. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pVersionStringLen    /**< [OUT] Version String Length. */
                              );

/**
* \brief To copy a block of data from a source address to a destination address.
*/
FUNC(void, ANFCRL_CODE) phTools_memcpy(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) dest,      /**< [OUT] Pointer to the destination array where the content is to be copied. */
                    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) src,    /**< [IN] Pointer to the source of data to be copied. */
                    VAR(uint32, ANFCRL_VAR) num                       /**< [IN] Number of bytes to copy.. */
                    );

/**
* \brief To generate a random number.
* \return pseudo-random integer on 0..32767
*/
FUNC(uint32, ANFCRL_CODE) phTools_rand(void);

/**
* \brief To set seeds the pseudo-random number generator used by rand() with the value seed.
*/
FUNC(void, ANFCRL_CODE) phTools_srand(
           VAR(uint32, ANFCRL_VAR) seed /**< [IN] Seed value */
				   );

/**
 * end of group phTools Tools
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHTOOLS_H */
