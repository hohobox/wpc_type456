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
*   @file    phalVca_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca_Int - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalVca Virtual Card Architecture (R)
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

#ifndef PHALVCA_INT_H
#define PHALVCA_INT_H

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
* @file           phalVca_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALVCA_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALVCA_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALVCA_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALVCA_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalVca_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALVCA_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALVCA_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALVCA_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALVCA_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALVCA_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/**
* \name Virtual Card Architecture Commands 
*/
/* @{ */
#define PHAL_VCA_CMD_PPC                                0xF0U   /**< VCA Prepare Proximity Check command code. */
#define PHAL_VCA_CMD_PC                                 0xF2U   /**< VCA Proximity Check command code. */
#define PHAL_VCA_CMD_VPC                                0xFDU   /**< VCA Verify Proximity Check command code. */
#define PHAL_VCA_CMD_VCS                                0x42U   /**< VCA Virtual Card Support command code. */
#define PHAL_VCA_CMD_VCSL                               0x4BU   /**< VCA Virtual Card Support Last command code. */
#define PHAL_VCA_CMD_SVC                                0x40U   /**< VCA Select Virtual Card command code. */
#define PHAL_VCA_CMD_ISOSVC                             0xA4U   /**< IsoSelect Virtual Card command code .*/
#define PHAL_VCA_CMD_ISOEXT_AUTH                        0x82U   /**< IsoExternalAuthenticate Virtual Card command code. */
#define PHAL_VCA_CMD_DVC                                0x48U   /**< VCA DeselectVC command code. */
/*@}*/

/**
* \name Virtual Card Architecture Response Codes 
*/
/* @{ */
#define PHAL_VCA_RESP_ACK_ISO4                          0x90U   /*< VCA ACK (in ISO14443-4 mode). */
#define PHAL_VCA_RESP_ERR_CMD_INVALID                   0x0BU   /*< VCA Invalid Command Error. */
#define PHAL_VCA_RESP_ERR_FORMAT                        0x0CU   /*< VCA Format Error. */
#define PHAL_VCA_RESP_ERR_GEN                           0x0FU   /*< VCA Generic Error. */
#define PHAL_VCA_RESP_ERR_CMD_OVERFLOW                  0x07U   /*< VCA CMD Overflow Error. */
#define PHAL_VCA_RESP_ERR_COMMAND_ABORTED               0xCAU   /*< VCA Command Aborted Error. */
/* @} */

/**
* \name ISO 7816 VCA return Codes 
*/
/* @{ */
#define PHAL_VCA_ISO7816_SUCCESS                        0x9000U /**< Correct execution. */
#define PHAL_VCA_ISO7816_PC_SUCCESS                     0x9190U /**< Correct execution for PC commands. */
#define PHAL_VCA_ISO7816_ERR_WRONG_LENGTH               0x6700U /**< Wrong length. */
#define PHAL_VCA_ISO7816_ERR_INVALID_APPLN              0x6A82U /**< Application / file not found. */
#define PHAL_VCA_ISO7816_ERR_WRONG_PARAMS               0x6A86U /**< Wrong parameters P1 and/or P2. */
#define PHAL_VCA_ISO7816_ERR_WRONG_LC                   0x6A87U /**< Lc inconsistent with P1/p2. */
#define PHAL_VCA_ISO7816_ERR_WRONG_LE                   0x6C00U /**< Wrong Le. */
#define PHAL_VCA_ISO7816_ERR_NO_PRECISE_DIAGNOSTICS     0x6F00U /**< No precise diagnostics. */
#define PHAL_VCA_ISO7816_ERR_EOF_REACHED                0x6282U /**< End of File reached. */
#define PHAL_VCA_ISO7816_ERR_FILE_ACCESS                0x6982U /**< File access not allowed. */
#define PHAL_VCA_ISO7816_ERR_FILE_EMPTY                 0x6985U /**< File empty or access conditions not satisfied. */
#define PHAL_VCA_ISO7816_ERR_FILE_NOT_FOUND             0x6A82U /**< File not found. */
#define PHAL_VCA_ISO7816_ERR_MEMORY_FAILURE             0x6581U /**< Memory failure (unsuccessful update). */
#define PHAL_VCA_ISO7816_ERR_INCORRECT_PARAMS           0x6B00U /**< Wrong parameter p1 or p2. READ RECORDS. */
#define PHAL_VCA_ISO7816_ERR_WRONG_CLA                  0x6E00U /**< Wrong Class byte. */
#define PHAL_VCA_ISO7816_ERR_UNSUPPORTED_INS            0x6D00U /**< Instruction not supported. */
/* @} */

#define PHAL_VCA_IID_SIZE                               16U     /**< Size of the Installation Identifier. */
#define PHAL_VCA_CMD_SIZE                               20U     /**< Size of the Virtual Card Command */
#define PHAL_VCA_PC_RND_LEN                             7U      /**< Size of the Proximity Check Random numbers. */
#define PHAL_VCA_PC_RND_LEN_NEW                         8U      /**< Size of the New Proximity Check Random numbers. */
#define PHAL_VCA_AUTH_RND_LEN                           32U     /**< Size of Iso Select random challenge. */
#define PHAL_VCA_MAXWRAPPEDAPDU_SIZE                    0x37u   /**< Maximum size of wrapped APDU 55 bytes. */

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
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
 * \brief Evaluate if the received response is erroneous.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ComputeErrorResponse(
        VAR(uint16, ANFCRL_VAR) wNumBytesReceived,                             /**< [In] Number of bytes received from the card. */
        VAR(uint8, ANFCRL_VAR) bStatus                                         /**< [In] Status byte received from the card. */
    );

/**
 * \brief Evaluate if the received response is erroneus.This is used if the error code needs to be set to VC param structure
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ComputeErrorResponse_Extended(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                     /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wStatus                                        /**< [In] Status byte received from the card. */
    );

/**
 * \brief Perform a Prepare Proximity Check command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_PrepareProximityCheck(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams                             /**< [In] Pointer to a palMifare component context. */
    );

/**
 * \brief Perform a Prepare Proximity Check new command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_PrepareProximityCheckNew(
        P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                  /**< [In] Pointer to a palMifare component context. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption,                                      /**< [Out] Option field defining subsequent response content \n
                                                                 *          \c bit[0] of bOption denotes presence of PPS \n
                                                                 *          \c bit[1] of bOption denotes presence of ActBitRate
                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                  /**< [Out] Published response time: time in microseconds. The PD will transmit the
                                                                 *         Cmd.ProximityCheck response as close as possible to this time.
                                                                 */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,                                    /**< [Out] The response received by the PICC. Can be \n
                                                                 *              \c Speed(PPS1). This indicates communication data rate between PD and PCD. OR \n
                                                                 *              \c ActBitRate information.
                                                                 */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen                                     /**< [Out] Length of byte(s) available in Response buffer.
                                                                 *              \c One byte Speed(PPS1) OR \n
                                                                 *              \c N bytes of ActBitRate information.
                                                                 */
    );

/**
 * \brief Perform a Proximity Check command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ProximityCheck(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,                                /**< [In] Pointer to a palMifare component context. */
        VAR(uint8, ANFCRL_VAR) bNumSteps,                                          /**< [In] Number of steps for the PC (1..7). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC,                                            /**< [In] RndC[7]. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC                                            /**< [Out] RndRC[14]. */
    );

/**
 * \brief Perform a Proximity Check command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_ProximityCheckNew(
        P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                      /**< [In] Pointer to a palMifare component context. */
        VAR(uint8, ANFCRL_VAR) bNumSteps,                                          /**< [In] Number of steps for the PC (1..7). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                     /**< [In] Published response time. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC,                                            /**< [In] RndC[7]. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndRC                                            /**< [Out] RndRC[14]. */
    );

/**
 * \brief Command to frame the Data complaint to ISO-7816 wrapped mode for Proximity Check commands
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_Int_SendISOWrappedCmd(
        P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff,
        VAR(uint8, ANFCRL_VAR) bLc,
        P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen
    );

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif

#endif /* PHALVCA_INT_H */
