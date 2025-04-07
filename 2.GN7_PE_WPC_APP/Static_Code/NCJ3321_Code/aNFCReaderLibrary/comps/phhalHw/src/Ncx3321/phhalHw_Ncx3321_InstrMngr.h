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
*   @file    phhalHw_Ncx3321_InstrMngr.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_InstMngr - HAL API usage in common use cases.
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
#ifndef PHHALHW_NCX3321_INSTRMNGR_H
#define PHHALHW_NCX3321_INSTRMNGR_H

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
* @file           phhalHw_Ncx3321_InstrMngr.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INSTMNGR_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INSTMNGR_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INSTMNGR_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321_InstMngr.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_InstMngr.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_INSTMNGR_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INSTMNGR_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INSTMNGR_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_InstMngr.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
/**
 * \brief Instruction Manager's command parameter structure
 */
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bCmd;               /**< In_Param - Command code*/
    VAR(uint8, ANFCRL_VAR) bQueue;             /**< In_Param - Flag to denote that Command is queuable*/
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxDataBuff;      /**< In_Param - Pointer to the Tx-Buffer*/
    VAR(uint16, ANFCRL_VAR) wTxDataLength;     /**< In_Param - No of Bytes in Tx-Buffer */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAddnData;        /**< In_Param - Points to additional data to be appended to Tx_Buffer;
                                     applicable for some commands like write eeprom, Exchange_RF_Data*/
    VAR(uint16, ANFCRL_VAR) wAddnDataLen;      /**< In_Param - Length of the additional data */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer;      /**< InOut_Param - Double pointer to send/retrieve, pointer to RxData in RxBuffer.
                                     For RF data and Read_EEprom response, the pointer to buffer in which data is
                                     to be sent is sent. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength;       /**< Out_Param - Pointer to Rx-length*/
}phhalHw_InstMngr_CmdParams_t;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * \brief Performs send and receive of TLV pkts over SPI in Command and response format
 *
 * This is a blocking call and Is a single interface to Instruction Manager. It converts
 * incoming NCX3321 Instructions into TLV format and queues in buffer. If queuing is not ON,
 * it sends individual TLV frames over SPI to NCX3321 and waits for RF Event. Part of
 * response is read in IRQ and remaining part of response is read, after RF event is received.
 *
 * If Queuing is ON, depending upon whether Instruction is queue-able Or not, it does handling
 * of Instruction, as below:
 * Exchange_RF_Data and TransmitRFData are the individual TLV instructions i.e.
 * can not be concatenated with any other instruction. if any instructions are queued, they
 * are sent before start queuing these.
 * If in Tx-Buffer, Instruction are already Queued, and latest instruction is not queue-able
 * then, incoming non-queue-able Instruction is appended to the Tx-buffer and all the
 * buffered Instructions are sent.
 * If multiple commands are cascaded, then response of only last transmitter TLV is returned back
 * to upper layers.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_BUFFER_OVERFLOW Internal receive buffer is too small for transmission or smaller than the response.
 * \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
 * \retval #PH_ERR_INTERNAL_ERROR unexpected code flow
 * \retval #PH_ERR_INVALID_PARAMETER wrong parameter
 * \retval Instructions specific return value received from NCX3321 as per Ncx3321 Instruction layer doc
 *
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_HandleCmd(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to Ncx3321 Hal layer's parameter structure. */
    P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams,       /**< [In] Pointer to Instruction Manager's Cmd parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOptions                               /**< [In] Buffering Options applicable for the RF Commands
                                                               like Exchange_RF_Data */
    );

/**
 * \brief Reads the given number of bytes into the buffer
 *
 *  IRQ line must be high, before calling this api
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Read(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to Ncx3321 Hal layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                            /**< [InOut] Pointer to Buffer to which data to be read into. */
    VAR(uint16, ANFCRL_VAR) wRxLength                              /**< [In] Number of Bytes to be read into the Buffer. */
    );

/**
 * \brief Sends the given number of bytes over SPI to NCX3321
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Send(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to Ncx3321 Hal layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                            /**< [In] Pointer to Buffer containing data to be sent. */
    VAR(uint16, ANFCRL_VAR) wTxLength,                             /**< [In] Number of Byte to be sent from the Buffer. */
    VAR(uint8, ANFCRL_VAR) bCheckIRQ                               /**< [In] Check IRQ status before sending Command to Reader. */
    );

/**
 * \brief Parses the Partial Response read in ISR and reads
 *  the remaining Bytes from Front end.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_InstMngr_ReadRsp(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,       /**< [In] Pointer to Ncx3321 Hal layer's parameter structure. */
    P2VAR(phhalHw_InstMngr_CmdParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pCmdParams        /**< [In] Pointer to Current Command Under-Process. */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INSTMNGR_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHHALHW_NCX3321_INSTRMNGR_H */