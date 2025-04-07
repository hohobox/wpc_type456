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
*   @file    phTools2.h
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
#ifndef PHTOOLS2_H
#define PHTOOLS2_H

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
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phTools2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHTOOLS_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHTOOLS_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHTOOLS_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHTOOLS_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHTOOLS_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHTOOLS_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHTOOLS_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHTOOLS_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHTOOLS_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phTools2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHTOOLS_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHTOOLS_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phTools2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHTOOLS_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHTOOLS_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHTOOLS_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phTools2.h and CDD_AnfcRL_Cfg.h are different"
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

#define PH_TOOLS_EVENT_IDLE2			0u
#define PH_TOOLS_EVENT_PENDING2		1u
#define PH_TOOLS_EVENT_OCCUR2		2u

#define PH_TOOLS_EVENT_MAX_DELAY2      (0xFFFFFFFFU)

/**
 * \brief Event Management Options
 * @{
 */
#define E_EVENT_OPT_NONE2                0x00u
#define E_EVENT_OPT_PEND_SET_ANY2        0x01u
#define E_EVENT_OPT_PEND_SET_ALL2        0x02u
#define E_EVENT_OPT_PEND_CLEAR_ON_EXIT2  0x04u
#define E_EVENT_OPT_POST_ISR2            0x08u
#define E_EVENT_OPT_CLR_ISR2             0x10u
/*@}*/

/**
* \name ToolsConfigs
*/
/*@{*/
#define PH_TOOLS_CRC16_PRESET_ISO14443A2 0x6363U     /**< CRC16 Preset for ISO14443-A. */
#define PH_TOOLS_CRC16_PRESET_ISO14443B2 0xFFFFU     /**< CRC16 Preset for ISO14443-B. */
#define PH_TOOLS_CRC16_PRESET_FELICA2    0x0000U     /**< CRC16 Preset for Felica. */
#define PH_TOOLS_CRC16_POLY_ISO144432    0x8408U     /**< CRC16 Polynomial for ISO14443. */
#define PH_TOOLS_CRC32_PRESET_DF82       0xFFFFFFFFU /**< CRC32 Preset for DesFire. */
#define PH_TOOLS_CRC32_POLY_DF82         0xEDB88320U /**< CRC32 Polynomial for DesFire. */
#define PH_TOOLS_CRC8_PRESET_EPC2        0xFFU       /**< Preset value for EPC CRC-8 generation. */
#define PH_TOOLS_CRC8_PRESET_UID2        0xFDU       /**< Preset value for UID CRC-8 generation. */
#define PH_TOOLS_CRC8_POLY_EPCUID2       0x1DU       /**< Polynomial for EPC/UID CRC-8 generation: x^8 + x^4 + x^3 + x^2 + 1 (MSB first). */
#define PH_TOOLS_CRC16_PRESET_EPCUID2    0xFFFFU     /**< Preset value for EPC/UID CRC-16 generation. */
#define PH_TOOLS_CRC16_POLY_EPCUID2      0x1021U     /**< Polynomial for EPC/UID CRC-16 generation: x^16 + x^12 + x^5 + 1 (MSB first). */
#define PH_TOOLS_CRC16_POLY_FELICA2      0x1021U     /**< Polynomial for Felica CRC-16 generation: x^16 + x^12 + x^5 + 1 (MSB first). */
#define PH_TOOLS_PARITY_OPTION_EVEN2         0x00U   /**< Encode/Decode even parity bits. */
#define PH_TOOLS_PARITY_OPTION_ODD2          0x01U   /**< Encode/Decode odd parity bits. */

#define PH_TOOLS_CRC_OPTION_DEFAULT2         0x00U   /**< Default CRC operation. */
#define PH_TOOLS_CRC_OPTION_OUPUT_INVERTED2  0x01U   /**< Inverts the bits after calculation. */
#define PH_TOOLS_CRC_OPTION_MSB_FIRST2       0x02U   /**< Calculates CRC with MSB(it) first. */
#define PH_TOOLS_CRC_OPTION_BITWISE2         0x04U   /**< Bitwise CRC, \c wDataLength2 represents the Bit length. */
#define PH_TOOLS_CRC_OPTION_MASK2            0x07U   /**< Mask of valid option bits. */
/*@}*/

/**
* \name Q Configs
*/
/*@{*/
#define PH_TOOLS_Q_MAX_ELEMENTS2             10U      /* Indicates maximum elements in the Q pool */
#define PH_TOOLS_Q_RESERVED_ELEMENTS2        2U       /* Indicates reserved elements in the Q pool for high priority tasks. */
/*@}*/

#define PH_TOOLS_Q_DATA_TO_BE_SENT2 		0x01U     /**< Message needs to be sent. */
#define PH_TOOLS_Q_RX_DATA2				PH_TOOLS_Q_DATA_TO_BE_SENT2 + 1U     /**< Message is received. */

#ifndef min_val2
#   define min_val2(X2,Y2) (((X2) < (Y2)) ? (X2) : (Y2))
#endif

#ifndef max_val2
#   define max_val2(X2,Y2) (((X2) > (Y2)) ? (X2) : (Y2))
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
    PH_TOOLS_Q_DATA_TO_BE_SENT2 = 0x01,  /**< Message needs to be sent. */
    PH_TOOLS_Q_RX_DATA2                  /**< Message is received. */
} phTools_Q_Type_t2;
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
typedef void (*phTools_PollFunc_t2)(void* pDataParams2);

/**
 * Event Handle.
 * @{
 */
typedef VAR(uint32, ANFCRL_VAR) phTools_Event_t2;
/*@}*/

/**
 * \brief Event Management Options
 * @{
 */
typedef VAR(uint8, ANFCRL_VAR) phTools_EventOpt_t2;
/*@}*/

/**
 * Event Management Object.
 * \brief Holds all parameters and status for management Event
 * @{
 */
typedef struct /* phTools_EventObj_t2 */
{
  VAR(phTools_Event_t2, ANFCRL_VAR) wEventHandle2;                       /**< Event Handler. */

  VAR(uint8, ANFCRL_VAR) bEventState2;                                /**< Event is pending or idle. */

  VAR(uint32, ANFCRL_VAR) wTimeToWait2;                              /**< Timeout of Event (in millisecond). */

  VAR(uint32, ANFCRL_VAR) wEventTimeStart2;                           /**< Store Start point of timer. */

  VAR(phStatus_t2, ANFCRL_VAR) dEventStatus2;                            /**< Return Event status. */

  VAR(phTools_PollFunc_t2, ANFCRL_VAR) pEventPollFunc2;                 /**< Function pointer of EventPoll function. */

  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pEventPollParams2;                            /**< Data parameters are used in EventPoll function. */

} phTools_EventObj_t2;
/*@}*/

/**
 * Event Bits
 * @{
 */
typedef VAR(uint32, ANFCRL_VAR) phTools_EventBits_t2;
/*@}*/

/**
* \brief Queue structure of Message Queue.
*/
typedef struct phTools_Q2
{
    void    * pSender2;                /**< Sender of the message. As this is void pointer pointing to the sender's context,
                                           bSenderType2 determines the actual type of the sender to allow proper casting. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pbData2;                  /**< Content of the message, type of the content is given using bType2. */
    VAR(uint32, ANFCRL_VAR) dwLength2;                /**< Length of the message. */
    VAR(uint8, ANFCRL_VAR) bLlcpBuf2[6];              /**< Buffer used to store LLCP formatted PDUs that needs to be sent while processing Message Queue. */
    VAR(uint8, ANFCRL_VAR) bLlcpData2;                /**< This variable is used to decide if LLCP framed data should be sent or data from application. */
    struct phTools_Q2 *pNext2;          /**< Pointer to next element in the list/queue. */
    VAR(uint16, ANFCRL_VAR) wFrameOpt2;               /**< Frame Option can take PH_TRANSMIT_DEFAULT, PH_TRANSMIT_BUFFER_FIRST,
                                           PH_TRANSMIT_BUFFER_CONT, or PH_TRANSMIT_BUFFER_LAST. */
    VAR(uint8, ANFCRL_VAR) bSenderType2;              /**< Type of the sender, used for proper casting of pSender2. */
    VAR(uint8, ANFCRL_VAR) bType2;                 /**< Message content type. It can be either data to be sent/received data. */
} phTools_Q_t2;

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
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION2 == 0))
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
#if (PH_TOOLS_Q_MAX_ELEMENTS2 > 32U)
#   error "PH_TOOLS_Q_MAX_ELEMENTS2 can have a max value of 32."
#endif /* PH_TOOLS_Q_MAX_ELEMENTS2 > 32 */
/*@}*/

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventCreate2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_PollFunc_t2, ANFCRL_VAR) pPollFunc2, P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPollFuncParam2);

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventPend2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(uint32, ANFCRL_VAR) timeToWait2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToWait2,
    P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2);

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventPost2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToPost2,
    P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2);

FUNC(phStatus_t2, ANFCRL_CODE) phTools_EventClear2(P2VAR(phTools_EventObj_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, VAR(phTools_EventOpt_t2, ANFCRL_VAR) options2, VAR(phTools_EventBits_t2, ANFCRL_VAR) FlagsToClear2,
    P2VAR(phTools_EventBits_t2, AUTOMATIC, ANFCRL_APPL_DATA) pCurrFlags2);

/**
* \brief Calculate even or odd parity.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_EncodeParity2(
                                VAR(uint8, ANFCRL_VAR) bOption2,                /**< [In] Parity option; e.g. #PH_TOOLS_PARITY_OPTION_EVEN2. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer2,            /**< [In] Array to input data. */
                                VAR(uint16, ANFCRL_VAR) wInBufferLength2,       /**< [In] Length of input data in bytes. */
                                VAR(uint8, ANFCRL_VAR) bInBufferBits2,          /**< [In] Number of valid bits in last byte of pInBuffer2. */
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize2,        /**< [In] Size of the output buffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer2,           /**< [Out] Output buffer. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength2,    /**< [Out] Number of valid bytes in pOutBuffer2. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits2        /**< [Out] Number of valid bits in last byte of pOutBuffer2. */
                                );

/**
* \brief Verify and Remove even or odd parity.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_DecodeParity2(
                                VAR(uint8, ANFCRL_VAR) bOption2,                /**< [In] Parity option; e.g. #PH_TOOLS_PARITY_OPTION_EVEN2. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInBuffer2,            /**< [In] Array to input data. */
                                VAR(uint16, ANFCRL_VAR) wInBufferLength2,       /**< [In] Length of input data in bytes. */
                                VAR(uint8, ANFCRL_VAR) bInBufferBits2,          /**< [In] Number of valid bits in last byte of pInBuffer2. */
                                VAR(uint16, ANFCRL_VAR) wOutBufferSize2,        /**< [In] Size of the output buffer. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBuffer2,           /**< [Out] Output buffer. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferLength2,    /**< [Out] Number of valid bytes in pOutBuffer2. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOutBufferBits2        /**< [Out] Number of valid bits in last byte of pOutBuffer2. */
                                );

/**
* \brief Calculate a CRC 5
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc52(
                                 VAR(uint8, ANFCRL_VAR) bOption2,       /**< [In] Specifies whether the output should be inverted or not. */
                                 VAR(uint8, ANFCRL_VAR) bPreset2,       /**< [In] Preset used for CRC calculation, */
                                 VAR(uint8, ANFCRL_VAR) bPolynom2,      /**< [In] Polynomial used for reduction*/
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,       /**< [In] Array to input data. */
                                 VAR(uint16, ANFCRL_VAR) wDataLength2,  /**< [In] Length of input data. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2         /**< [Out] Resulting CRC. */
                                 );

/**
* \brief Calculate a CRC 8
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc82(
                                 VAR(uint8, ANFCRL_VAR) bOption2,       /**< [In] Specifies whether the output should be inverted or not. */
                                 VAR(uint8, ANFCRL_VAR) bPreset2,       /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC8_PRESET_UID2. */
                                 VAR(uint8, ANFCRL_VAR) bPolynom2,      /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC8_POLY_EPCUID2. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,       /**< [In] Array to input data. */
                                 VAR(uint16, ANFCRL_VAR) wDataLength2,  /**< [In] Length of input data. */
                                 P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2         /**< [Out] Resulting CRC. */
                                 );

/**
* \brief Calculate a CRC 16
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc162(
                                  VAR(uint8, ANFCRL_VAR) bOption2,      /**< [In] Specifies whether the output should be inverted or not. */
                                  VAR(uint16, ANFCRL_VAR) wPreset2,     /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC16_PRESET_ISO14443A2. */
                                  VAR(uint16, ANFCRL_VAR) wPolynom2,    /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC16_POLY_ISO144432. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,      /**< [In] Array to input data. */
                                  VAR(uint16, ANFCRL_VAR) wDataLength2, /**< [In] Length of input data. */
                                  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2       /**< [Out] Resulting CRC. */
                                  );

/**
* \brief Calculate a CRC 32
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_CalculateCrc322(
                                  VAR(uint8, ANFCRL_VAR) bOption2,      /**< [In] Specifies whether the output should be inverted or not. */
                                  VAR(uint32, ANFCRL_VAR) dwPreset2,    /**< [In] Preset used for CRC calculation, e.g. #PH_TOOLS_CRC32_PRESET_DF82. */
                                  VAR(uint32, ANFCRL_VAR) dwPolynom2,   /**< [In] Polynomial used for reduction, e.g. #PH_TOOLS_CRC32_POLY_DF82. */
                                  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,      /**< [In] Array to input data. */
                                  VAR(uint16, ANFCRL_VAR) wDataLength2, /**< [In] Length of input data. */
                                  P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2       /**< [Out] Resulting CRC. */
                                  );

/**
* \brief Calculate a CRC_B
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_ComputeCrc_B2(
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData2,        /**< [In] Array to input data. */
                                VAR(uint32, ANFCRL_VAR) dwLength2,     /**< [In] Length of input data. */
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCrc2          /**< [Out] Resulting Two byte CRC. */
                                );

/**
* \brief The function gets the Version of the Firmware of DUT.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Command successfully executed.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid frame or unexpected receive data length or command code mismatch.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phTools_GetVersion2(
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProductVer2,          /**< [OUT] Product Version. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pMajor2,              /**< [OUT] Major Version. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMinor2,               /**< [OUT] Minor Version. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPatch_Dev2,          /**< [OUT] Development/Patch Version. */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVersionString2,       /**< [OUT] Version String. */
                              P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pVersionStringLen2    /**< [OUT] Version String Length. */
                              );

/**
* \brief To copy a block of data from a source address to a destination address.
*/
FUNC(void, ANFCRL_CODE) phTools_memcpy2(
                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) dest2,      /**< [OUT] Pointer to the destination array where the content is to be copied. */
                    P2CONST(void, AUTOMATIC, ANFCRL_APPL_CONST) src2,    /**< [IN] Pointer to the source of data to be copied. */
                    VAR(uint32, ANFCRL_VAR) num2                       /**< [IN] Number of bytes to copy.. */
                    );

/**
* \brief To generate a random number.
* \return pseudo-random integer on 0..32767
*/
FUNC(uint32, ANFCRL_CODE) phTools_rand2(void);

/**
* \brief To set seeds the pseudo-random number generator used by rand() with the value seed2.
*/
FUNC(void, ANFCRL_CODE) phTools_srand2(
           VAR(uint32, ANFCRL_VAR) seed2 /**< [IN] Seed value */
				   );

/**
 * end of group phTools Tools
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHTOOLS_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHTOOLS_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHTOOLS2_H */
