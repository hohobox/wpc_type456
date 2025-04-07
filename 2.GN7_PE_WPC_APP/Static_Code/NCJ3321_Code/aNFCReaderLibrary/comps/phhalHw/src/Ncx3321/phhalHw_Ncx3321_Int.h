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
*   @file    phhalHw_Ncx3321_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Int - HAL API usage in common use cases.
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
#ifndef PHHALHW_NCX3321_INT_H
#define PHHALHW_NCX3321_INT_H

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
#include <phhalHw.h>
#include <phbalReg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup phhalHw_NCX3321_Int Internal
* \ingroup phhalHw_Ncx3321
* \brief Ncx3321 HAL Internal functions
* @{
*/

/**
 * \brief NCX3321 Specific event
 */
#define E_PHHAL_HW_EVT_SIG                    (1U << 7U)     /**< signals that EVT is sent by NCX3321. */


#define PHHAL_HW_NCX3321_RESET_DELAY_MICRO_SECS          5000u /**< Delay used in HW reset. */
#define PHHAL_HW_NCX3321_RESET_GUARDTIME_MICRO_SECS      1000u /**< Hardware ready timeout after HW reset. */


#define PHHAL_HW_NCX3321_TESTBUS_ENABLE_ADDR             0x00U /**< TODO: Update correct address. */
#define PHHAL_HW_NCX3321_TESTBUS_ENABLE_MASK             0x80U /**< TODO: Update correct mask. */
#define PHHAL_HW_NCX3321_EXCHANGE_HEADER_SIZE            5U    /**< 3- Bytes of T and L, and 2 Bytes; TxLastBit and RxConfig */
#define PHHAL_HW_NCX3321_TRANSMIT_HEADER_SIZE            5U    /**< 3- Bytes of T and L, and 2 Bytes; TxLastBit and RFU */

#define PHHAL_HW_NCX3321_INT_SPI_WRITE                   0x7FU /**< Direction Bit0 -> 0 - Write; 1 - Read. */
#define PHHAL_HW_NCX3321_INT_SPI_READ                    0xFFU /**< Direction Bit0 -> 0 - Write; 1 - Read. */

/* Timer configuration bits */


/* Timer config */
#define TIMER_FREQ                                      13.56          /**< Ncx3321 clk frequency.*/
#define TMR_RELOAD_VALUE_MASK                           (0x000FFFFFUL) /**< The reload mask for the timer, also the maximum value that can be loaded into the timer reload register.*/
#define PHHAL_HW_NCX3321_MAX_FREQ                        13560000U      /**< Ncx3321 clk Maximum frequency = 13.56 MHz.*/
#define PHHAL_HW_NCX3321_MIN_FREQ                        53000U         /**< Ncx3321 clk Minimum frequency = 53 KHz.*/
/* TODO : Check what is the MAX and MIN Time Delay w.r.t NCX3321 */
#define PHHAL_HW_NCX3321_MAX_TIME_DELAY_MS               19784U         /**< Ncx3321 Maximum Time Delay in millisecond = 19.78443396226.*/
#define PHHAL_HW_NCX3321_MIN_TIME_DELAY_US               1U             /**< Ncx3321 Minimum Time Delay in microsecond = 0.00001886792.*/
#define PHHAL_HW_NCX3321_CONVERSION_MS_SEC               1000U          /**< Millisecond to Sec (In denominator for calculation purpose) --> 1000.*/
#define PHHAL_HW_NCX3321_CONVERSION_US_SEC               1000000U       /**< MicroSec to Sec (In denominator for calculation purpose) --> 1000000.*/


#define PHHAL_HW_NCX3321_I14443_ADD_DELAY_US             15U            /**< Additional digital timeout delay for ISO14443. */
#define PHHAL_HW_NCX3321_I15693_ADD_DELAY_US             120U           /**< Additional digital timeout delay for ISO15693. */

#define PHHAL_HW_NCX3321_IDLE_EVENT_LENGTH               12U            /**< Length of IDLE Event.*/

/**
* \name Rf Datarate Values
*/
/*@{*/
#define PHHAL_HW_RF_DATARATE_NO_CHANGE                  0x00FFU         /**< Data rate no change. */
/*@}*/

/**
 * end of phhalHw_NCX3321_Int group
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
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif




/** \addtogroup phhalHw_NCX3321_Int Internal
* \ingroup phhalHw_Ncx3321
* \brief Ncx3321 HAL Internal functions
* @{
*/

/**
* \brief Reset all NCx3321 internal states function.
*/
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_ResetState(void);

/* Returns the RxBuffer pointer, length and size */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetRxBuffer(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                             /**< [Out] Pointer to HAL RX buffer.*/
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferLen,                          /**< [Out] Length of the buffer.*/
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxBufferSize                          /**< [Out] Size of the buffer.*/
    );

/* Returns the TxBuffer pointer, length and size */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetTxBuffer(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                             /**< [Out] Pointer to HAL TX buffer.*/
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferLen,                          /**< [Out] Length of the buffer.*/
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxBufferSize                          /**< [Out] Size of the buffer.*/
    );

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_TimerStart(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bTimer,                                   /**< [In] Timer Option.*/
    VAR(uint32, ANFCRL_VAR) dwStartCond,                             /**< [In] Start condition of Timer.*/
    VAR(uint32, ANFCRL_VAR) dwStopCond,                              /**< [In] Stop condition of Timer.*/
    VAR(uint32, ANFCRL_VAR) wPrescaler,                              /**< [In] Pre-scalar value of Timer.*/
    VAR(uint32, ANFCRL_VAR) dwLoadValue                              /**< [In] Re-Load value of Timer.*/
    );

/**
* \brief Internal set config function.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_UNSUPPORTED_PARAMETER Configuration is not supported or invalid.
* \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
* \retval #PH_ERR_PARAMETER_OVERFLOW Setting the parameter value would lead to an overflow.
*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetConfig_Int(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig,                               /**<[In] SetConfig option.*/
    VAR(uint16, ANFCRL_VAR) wValue                                 /**<[In] SetConfig value.*/
    );

/* Ncx3321 ISR callback */
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_ISR_Callback(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                /**< [In] Pointer to this layer's parameter structure. */
    );


FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetMinFdt(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wValue                                   /**< [In] #PH_ON or #PH_OFF. */
    );


FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_Retrieve_Data(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength
    );

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_ClearNSetRegFields(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint8, ANFCRL_VAR) bRegister,
    VAR(uint32, ANFCRL_VAR) dwMask,
    VAR(uint32, ANFCRL_VAR) dwPos,
    VAR(uint16, ANFCRL_VAR) wValue
    );

#ifdef PHDRIVER_SOFT_SSEL
/* Pull NSS high/low */
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_WriteSSEL(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams,                            /**< [In] Pointer to BAL layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bValue                                    /**< [In] DAL macros either PH_DRIVER_SET_LOW / PH_DRIVER_SET_HIGH shall be used. */
    );
#endif

/**
* \brief Starts the timer as part of the time out behaviour.
* \note uses timer 1
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTmo(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wTimeout,                                     /**< [In] Time out period. */
    VAR(uint8, ANFCRL_VAR) bUnit                                         /**< [In] The unit unit used for specifying the delay. */
    );


/* Ncx3321 Reset function */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_Reset(void);

/* Ncx3321 poll guard time callback */
FUNC(void, ANFCRL_CODE) phhalHw_Ncx3321_Int_GuardTimeCallBck(void);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdReg(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams
    );

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegBit(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wValue,
    VAR(uint32, ANFCRL_VAR) dwMaskValue
    );

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetConfig_FelicaEmdRegByte(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wValue,
    VAR(uint8, ANFCRL_VAR) bBytePos,
    VAR(uint32, ANFCRL_VAR) dwMaskValue
    );

/**
* \brief Apply card mode register settings (Tx and Rx Data Rate) according to given parameters.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetCardMode(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wTxDataRate,                             /**< [In] TX data rate to be used. */
    VAR(uint16, ANFCRL_VAR) wRxDataRate,                             /**< [In] RX data rate to be used. */
    VAR(uint16, ANFCRL_VAR) wSubcarrier                              /**< [In] Sub carrier to be used. */
    );

/**
 * \brief Returns the delay of the digital circuitry for the current protocol.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_GetDigiDelay(
	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
	VAR(uint8, ANFCRL_VAR) bIsTimeout, /**< [In] Whether the returned delay is added to a timeout (#PH_ON) or is used for measurement (#PH_OFF). */
	P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDelayUs /**< [Out] The digital delay in microseconds. */
);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetTxDataRateFraming(
	P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
	VAR(uint16, ANFCRL_VAR) wConfig,
	VAR(uint16, ANFCRL_VAR) wValue);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_SetRxDataRateFraming(
		P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
		VAR(uint16, ANFCRL_VAR) wConfig,
		VAR(uint16, ANFCRL_VAR) wValue);

/**
* \brief Used by Hal for waiting for desired Events to Occur.
* Function return when desired event Occur Or upon timeOut.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_ABORTED Current wait is aborted.
* \retval #PH_ERR_INTERNAL_ERROR Unexpected event occurred.
* \retval #PH_ERR_IO_TIMEOUT OSAL Timed-Out, resulting in PH_ERR_IO_TIMEOUT.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Int_EventWait(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,            /**<[In] DataParameter representing this layer. */
    VAR(uint32, ANFCRL_VAR) dwExpectedEvents,                             /**<[In] Specific Event we are waiting for. */
    VAR(uint32, ANFCRL_VAR) dwEventTimeOut,                               /**<[In] Time in MilliSeconds, for Events to occur. */
    VAR(uint8, ANFCRL_VAR) bPayLoadPresent,                               /**<[In] Specifies if pay load is to be returned using Pointer . */
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventReceived                             /**<[InOut] Returns Event received */
    );


/**
 * end of phhalHw_NCX3321_Int group
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_INT_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif  /* PHHALHW_NCX3321_INT_H */
