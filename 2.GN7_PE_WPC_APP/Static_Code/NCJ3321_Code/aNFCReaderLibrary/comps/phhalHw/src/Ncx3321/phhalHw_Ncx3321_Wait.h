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
*   @file    phhalHw_Ncx3321_Wait.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Wait - HAL API usage in common use cases.
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
#ifndef PHHALHW_NCX3321_WAIT_H
#define PHHALHW_NCX3321_WAIT_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <Compiler.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Wait.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_WAIT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_WAIT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_WAIT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321_Wait.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_WAIT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Wait.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_WAIT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_WAIT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_WAIT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Wait.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define PH_EVENT_TIMEOUT               ((phStatus_t)0x0001U)

#define PHHAL_HW_NCX3321_EXCHANGE_CMD_TIMEOUT      10000U

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
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
* \brief Waits for the interrupts to occur, this is a blocking call.
* The function does not return back until RF interrupt occurs.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_ABORTED Current wait is aborted.
* \retval #PH_ERR_IO_TIMEOUT TimeOut Occurred.
*/

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_WaitIrq(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,            /**<[In] DataParameter representing this layer. */
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) pReceivedEvents                            /**<[InOut] Return received Events. */
    );

/**
* \brief Used by Hal for waiting for desired Events to Occur.
* Function return when desired event Occur Or upon timeOut.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_ABORTED Current wait is aborted.
* \retval #PH_ERR_INTERNAL_ERROR Unexpected event occurred.
* \retval #PH_ERR_IO_TIMEOUT TimeOut Occurred.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_WaitForEvent(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,            /**<[In] DataParameter representing this layer. */
    VAR(uint32, ANFCRL_VAR) dwEvtsWaitFor,                               /**<[In] Specific Events we are waiting for. */
    VAR(uint32, ANFCRL_VAR) dwEvtsTimeOut,                               /**<[In] Time in Millisecond, for Events to occur. */
    VAR(uint8, ANFCRL_VAR) bPayloadPresnt,                               /**<[In] Specifies if payload is to be returned using Pointer . */
    P2VAR(uint32, AUTOMATIC, ANFCRL_APPL_DATA) dwEventsReceived,                          /**<[InOut] Returns Event received */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppEvtPayLoad                               /**<[InOut] Contains the pointer to payload data of the Events */
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_NCX3321_WAIT_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_NCX3321_WAIT_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHHALHW_NCX3321_WAIT_H */
