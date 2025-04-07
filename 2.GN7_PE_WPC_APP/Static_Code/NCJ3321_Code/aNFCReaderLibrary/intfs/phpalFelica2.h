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
*   @file    phpalFelica2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalFelica - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalFelica2 Felica
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
#ifndef PHPALFELICA2_H
#define PHPALFELICA2_H

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
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalFelica2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALFELICA_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALFELICA_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALFELICA_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALFELICA_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALFELICA_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALFELICA_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALFELICA_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALFELICA_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALFELICA_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalFelica2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALFELICA_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALFELICA_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalFelica2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALFELICA_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALFELICA_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALFELICA_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalFelica2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_FELICA_SW2

/** \defgroup phpalFelica2 Felica
 * \ingroup phpalProtocol
 * \brief These Components implement the Felica (contactless) protocol.
 * @{
 */

/**
* \name Lengths
*/
/*@{*/
/** UID length in bytes. */
#define PHPAL_FELICA_IDM_LENGTH2     8U
/** PMm length in bytes. */
#define PHPAL_FELICA_PMM_LENGTH2     8U
/** Block length in bytes. */
#define PHPAL_FELICA_BLOCK_LENGTH2   4U
/** Number of bytes per page. */
#define PHPAL_FELICA_PAGE_LENGTH2    16U
/** Length of ATQC. */
#define PHPAL_FELICA_ATQC_LENGTH2    17U
/** Length of Request Data (RD) in ATQC. */
#define PHPAL_FELICA_RD_LENGTH2      2U
/** Maximum length of a transmission package. */
#define PHPAL_FELICA_TXLENGTH_MAX2   254U
/*@}*/

/**
 * end of group phpalFelica2 Felica
 * @}
 */
#endif /* NXPBUILD__PHPAL_FELICA2 */

#ifdef NXPBUILD__PHPAL_FELICA_SW2
/** \defgroup phpalFelica_Sw2 Component : Software
 * \brief Software component of Felica.
 * \ingroup phpalFelica2
 * @{
 */
#define PHPAL_FELICA_SW_ID2      0x01U    /**< ID for Software Felica layer */

/**
 * end of group phpalFelica_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef NXPBUILD__PHPAL_FELICA_SW2

/** \addtogroup phpalFelica2 Felica
 * \ingroup phpalProtocol
 * \brief These Components implement the Felica (contactless) protocol.
 * @{
 */

/**
* \name Definitions of the time slots for the ReqC command
*/
/*@{*/
#define PHPAL_FELICA_NUMSLOTS_12     0x00U    /**< Value for \c bNumSlots = 1. */
#define PHPAL_FELICA_NUMSLOTS_22     0x01U    /**< Value for \c bNumSlots = 2. */
#define PHPAL_FELICA_NUMSLOTS_42     0x03U    /**< Value for \c bNumSlots = 4. */
#define PHPAL_FELICA_NUMSLOTS_82     0x07U    /**< Value for \c bNumSlots = 8. */
#define PHPAL_FELICA_NUMSLOTS_162    0x0FU    /**< Value for \c bNumSlots = 16. */
/*@}*/

/**
* \name Preamble Lengths
*/
/*@{*/
#define PHPAL_FELICA_PREAMBLE_LEN_48BITS2    0x00U    /**< Preamble of 48 Bits. */
#define PHPAL_FELICA_PREAMBLE_LEN_56BITS2    0x02U    /**< Preamble of 56 Bits. */
#define PHPAL_FELICA_PREAMBLE_LEN_64BITS2    0x03U    /**< Preamble of 64 Bits. */
#define PHPAL_FELICA_PREAMBLE_LEN_72BITS2    0x04U    /**< Preamble of 72 Bits. */
/*@}*/

/**
* \name System Code
*/
/*@{*/
#define PHPAL_FELICA_SYSTEM_CODE_BYTE_02    0xFFU
#define PHPAL_FELICA_SYSTEM_CODE_BYTE_12    0xFFU
/*@}*/

/**
* \name Felica Parameters
*/
/*@{*/

/**
 * \brief Set / Get Request Code (RC).
 */
#define PHPAL_FELICA_CONFIG_RC2                      0x0000U

/**
 * \brief Get total number of response frame received.
 * Invalid if \ref phpalFelica_ReqC2 function called with slot number #PHPAL_FELICA_NUMSLOTS_12
 */
#define PH_PALFELICA_CONFIG_NUM_RESPONSE_FRAMES2     0x0001U

/**
 * \brief Set / Get Preamble Length.
 */
#define PHPAL_FELICA_PREAMBLE_LENGTH2                0x0002U

/*@}*/

/**
 * end of group phpalFelica2 Felica
 * @}
 */
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_FELICA_SW2

/** \addtogroup phpalFelica_Sw2 Component : Software
 * \brief Software component of Felica.
 * \ingroup phpalFelica2
 * @{
 */

/**
 * \brief State for ReqC
 */
typedef enum {
	PHPAL_FELICA_REQC_IDLE2 = 0,
	PHPAL_FELICA_REQC_TIMEOUT2,
	PHPAL_FELICA_REQC_CONFIG2,
	PHPAL_FELICA_REQC_EXCHANGE2,
	PHPAL_FELICA_REQC_EXCHANGE_FINISH2,
	PHPAL_FELICA_REQC_CHECK_LENGTH2
} FELICA_REQC_StateType_t2;

/**
 * \brief State for ActivateCard
 */
typedef enum {
	PHPAL_FELICA_ACTCARD_START2 = 0,
	PHPAL_FELICA_ACTCARD_REQC2,
	PHPAL_FELICA_ACTCARD_GET_FRAME_INFO2,
	PHPAL_FELICA_ACTCARD_CHECK_MORE_CARD_AVAILABILITY2,
	PHPAL_FELICA_ACTCARD_ANTICOLLITION2,
	PHPAL_FELICA_ACTCARD_FINISH2
} FELICA_ACTCARD_StateType_t2;

/**
 * \brief State for Exchange
 */
typedef enum {
	PHPAL_FELICA_EXCHANGE_SEND2 = 0,
	PHPAL_FELICA_EXCHANGE_PUTBUFFER2,
	PHPAL_FELICA_EXCHANGE_TIMEOUT2,
	PHPAL_FELICA_EXCHANGE_WAITRSP2
} FELICA_EXCHANGE_StateType_t2;

/**
 * end of group phpalFelica_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_FELICA_SW2

/** \addtogroup phpalFelica_Sw2 Component : Software
 * \brief Software component of Felica.
 * \ingroup phpalFelica2
 * @{
 */

/**
 * \brief Felica parameter structure
 */
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId2; /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2; /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) aIDmPMm2[PHPAL_FELICA_IDM_LENGTH2 + PHPAL_FELICA_PMM_LENGTH2 + PHPAL_FELICA_RD_LENGTH2]; /**< The Cards Manufacture ID (IDm), Manufacture Parameters (PMm) and Request Data length. */
  VAR(uint8, ANFCRL_VAR) bIDmPMmValid2; /**< Whether the stored IDm and PMm are valid (\c 1) or not (\c 0). */
  VAR(uint8, ANFCRL_VAR) bLength2; /**< Current data length, used internally for Exchange function. */
  VAR(uint8, ANFCRL_VAR) bRequestCode2; /**< Request code (RC) field of ReqC, default value is '0'. */
  VAR(uint8, ANFCRL_VAR) bTotalFrames2; /**< Holds total number of response frame received. Value ranges from 1 to N \n
	 Ignored if \ref phpalFelica_ReqC2 function called with slot number #PHPAL_FELICA_NUMSLOTS_12. */
  VAR(uint8, ANFCRL_VAR) bPreambleLen2; /**< Preamble length used for reception from tag. */

  VAR(FELICA_REQC_StateType_t2, ANFCRL_VAR) eReqCState2;  /**< Handle state of ReqC function of FELICA. */
  VAR(FELICA_ACTCARD_StateType_t2, ANFCRL_VAR) eActCardState2; /**< Handle state of ActivateCard function of FELICA. */
  VAR(FELICA_EXCHANGE_StateType_t2, ANFCRL_VAR) eExchangeState2; /**< Handle state of Exchange function of FELICA. */
} phpalFelica_Sw_DataParams_t2;

/**
 * end of group phpalFelica_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHPAL_FELICA_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phpalFelica_Sw2 Component : Software
 * \brief Software component of Felica.
 * \ingroup phpalFelica2
 * @{
 */

/**
 * \brief Initialize this layer.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Sw_Init2(
	P2VAR(phpalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
	VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2, /**< [In] Specifies the size of the data parameter structure. */
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2 /**< [In] Pointer to the parameter structure of the underlying layer. */
);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#include "../comps/phpalFelica/src/Sw/phpalFelica_Sw2.h"

#ifdef NXPRDLIB_REM_GEN_INTFS2

#define phpalFelica_ReqC2( pDataParams2, pSystemCode2, bTimeSlot2, ppRxBuffer2, pRxLength2) \
        phpalFelica_Sw_ReqC2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, pSystemCode2, bTimeSlot2, ppRxBuffer2, pRxLength2)

#define phpalFelica_ActivateCard2( pDataParams2, pIDmPMm2, bIDmPMmLength2,  pSystemCode2, \
                                  bTimeSlot2, pRxBuffer2, pRxLength2, pMoreCardsAvailable2) \
        phpalFelica_Sw_ActivateCard2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMm2, bIDmPMmLength2, pSystemCode2, bTimeSlot2, pRxBuffer2, pRxLength2, pMoreCardsAvailable2 )

#define phpalFelica_Exchange2( pDataParams2, wOption2, wN2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2) \
        phpalFelica_Sw_Exchange2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, wOption2, wN2, pTxBuffer2, wTxLength2, ppRxBuffer2, pRxLength2 )

#define phpalFelica_SetConfig2( pDataParams2, wConfig2, wValue2) \
        phpalFelica_Sw_SetConfig2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, wConfig2, wValue2)

#define phpalFelica_GetConfig2( pDataParams2, wConfig2, pValue2) \
        phpalFelica_Sw_GetConfig2((phpalFelica_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2)

#define phpalFelica_GetSerialNo2( pDataParams2, pIDmPMmOut2,  pLenIDmPMmOut2) \
        phpalFelica_Sw_GetSerialNo2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMmOut2, pLenIDmPMmOut2 )

#define phpalFelica_GetFrameInfo2(pDataParams2, bFrameNum2, pResponseBuffer2, pwStatus2, ppID2, pLen2) \
        phpalFelica_Sw_GetFrameInfo2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, bFrameNum2, pResponseBuffer2, pwStatus2, ppID2, pLen2)

#define phpalFelica_SetSerialNo2( pDataParams2, pIDmPMmIn2) \
        phpalFelica_Sw_SetSerialNo2( (phpalFelica_Sw_DataParams_t2 *)pDataParams2, pIDmPMmIn2)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * \brief Perform the Felica ReqC command.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
 *
 * \b Note: This function waits until all cards in all time slots have had time to reply even though only the first response is returned.\n
 * The formula used is <b><em>1208us * (n-1)</em></b> according to JIS X 6319-4:2005.
 *
 * Response format when bNumTimeSlots greater than #PHPAL_FELICA_NUMSLOTS_12
 * <pre>
 *   0                                                                           28         31
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *   |   LEN  |               PAYLOAD(MAX 19 BYTES)              |     PAD      |   STATUS   |
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * </pre>
 *
 * Format of Status Byte.
 * <pre>
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *   |      |              |      |L|  |  |  |  |                                          |
 *   |      |              |      |e|Co|Pr|Da|CL|                                          |
 *   | RFU  |     LEN      | RFU  |n|ll|ot|ta|Er|                  RFU                     |
 *   | [7:5]|     [4:0]    | [7:5]|E|De|Er|Er|ro|                                          |
 *   |      |              |      |r|t |r |r |r |                                          |
 *   |      |              |      |r|  |  |  |  |                                          |
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *   |<-------Byte 28----->|<------Byte 29----->|<------Byte 30----->|<------Byte 31------>|
 * </pre>
 *
 * Response format when bNumTimeSlots is #PHPAL_FELICA_NUMSLOTS_12
 * <pre>
 *   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *   |                   IDmPMm[16]                       |     RD[Optional]    |
 *   ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * </pre>
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_ReqC2(
        void* pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2, /**< [In] System-Code; uint8[2]. */
        VAR(uint8, ANFCRL_VAR) bTimeSlot2, /**< [In] Number of time slots to use. Refer to e.g. #PHPAL_FELICA_NUMSLOTS_12 for valid values. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2, /**< [Out] Pointer to the HAL Rx buffer. 32bytes / slot information in case of multiple slots or else a single response containing IDmPMm. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2 /**< [Out] Length of the content in the buffer. */
);

/**
 * \brief This command activates a Felica card.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
 *
 * \b Note: If an IDm is passed to this function, it is stored as the current IDm and no real activation is done.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_ActivateCard2(
        void* pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2, /**< [In] IDm followed by PMm; If supplied it is stored and no real activation is done. */
        VAR(uint8, ANFCRL_VAR) bIDmPMmLength2, /**< [In] IDm length; 0 or 16. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2, /**< [In] System-Code; uint8[2]. */
        VAR(uint8, ANFCRL_VAR) bTimeSlot2, /**< [In] Number of timeslots to use. Refer to e.g. #PHPAL_FELICA_NUMSLOTS_12 for valid values. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2, /**< [Out] 8 bytes NFCID2 + 8 bytes PAD; uint8[16]. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2, /**< [Out] Length of received data. 0 or 16. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2 /**< [Out] Whether there are more cards in the field or not; uint8. */
);

/**
 * \brief Exchange data with the Picc.
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
 * \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_Exchange2(
        void* pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wOption2, /**< [In] Option parameter. */
        VAR(uint16, ANFCRL_VAR) wN2, /**< [In] N to calculate the response timeout. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2, /**< [In] Data to transmit; Length and IDm is added automatically. */
        VAR(uint16, ANFCRL_VAR) wTxLength2, /**< [In] Length of data to transmit. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2, /**< [Out] Pointer to received data; Length, response code and IDm are removed automatically. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2 /**< [Out] number of received data bytes. */
);

/**
 * \brief Set configuration parameter.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_SetConfig2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig2, /**< [In] Configuration Identifier. */
        VAR(uint16, ANFCRL_VAR) wValue2 /**< [In] Configuration Value. */
);

/**
 * \brief Get configuration parameter.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_GetConfig2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig2, /**< [In] Configuration Identifier. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2 /**< [Out] Configuration Value. */
);
/**
 * \brief As the card receives the Get Serial Number command, it shall respond with that one.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_ERR_USE_CONDITION No Serial number available at the moment.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_GetSerialNo2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMmOut2, /**< [Out] Last Uid (IDm + PMm); uint8[16]. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLenIDmPMmOut2 /**< [Out] Length of Uid; 0 or 16. */
);

/**
 * \brief This function will provide information of given frame number(1 to N).
 * It will provide pointer to IDmPMm if frame status is #PH_ERR_SUCCESS2.
 * \b pwStatus2 can be one of:\n
 * \li #PH_ERR_SUCCESS2
 * \li #PH_ERR_PROTOCOL_ERROR2
 * \li #PH_ERR_COLLISION_ERROR2
 * \li #PH_ERR_INTEGRITY_ERROR2
 * \li #PH_ERR_LENGTH_ERROR2
 *
 * \b Note: This function is only valid when function \ref phpalFelica_ReqC2 is called with slot number greater than #PHPAL_FELICA_NUMSLOTS_12.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_GetFrameInfo2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bFrameNum2, /**< [In] Frame number. Frame number 0 is invalid. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponseBuffer2, /**< [In] The pointer to the entire Felica response as obtained from ReqC API. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pwStatus2, /**< [Out] Frame status. Status will be Success, or one of collision, length, integrity, protocol errors. */
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppID2, /**< [Out] Pointer to IDmPMm in case of wStatus being success. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pLen2 /**< [Out] Length of IDmPMm data. 2 Request Data (RD) bytes are optional. This will indicate exact length. */
);

/**
 * \brief This function will update IDmPMm in this layer's parameter structure.
 * This function must be call after card or device is activated.
 *
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phpalFelica_SetSerialNo2(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIDmPMm2 /**< [In] 16 byte IDmPMm. */
);

/**
 * end of group phpalFelica_Sw2 Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */



#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef __cplusplus
}
#endif
#endif /* PHPALFELICA2_H */
