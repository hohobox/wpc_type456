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
*   @file    phalMfdf_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlMfdf_Int - AL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phalMfdf MIFARE DESFire (R)
*   @ingroup phalApplication
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
#ifndef PHALMFDF_INT_H
#define PHALMFDF_INT_H

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
#include <phalMfdf.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalMfdf_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALMFDF_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALMFDF_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALMFDF_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALMFDF_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALMFDF_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALMFDF_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALMFDF_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALMFDF_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALMFDF_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalMfdf_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALMFDF_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALMFDF_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALMFDF_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalMfdf_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALMFDF_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALMFDF_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALMFDF_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalMfdf_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

/**
* \name MIFARE Desfire Native Commands
*/
/*@{*/

#define PHAL_MFDF_CMD_CREATE_APPLN              0xCAU    /**< MF DF Create Application cmd. */
#define PHAL_MFDF_CMD_SELECT_APPLN              0x5AU    /**< MF DF Select Application Cmd. */
#define PHAL_MFDF_CMD_GET_VERSION               0x60U    /**< MF DF Get Version cmd. */
#define PHAL_MFDF_CMD_CREATE_STD_DATAFILE       0xCDU    /**< MF DF Create Standard data file cmd. */
#define PHAL_MFDF_CMD_WRITE_DATA                0x3DU    /**< MF DF Write data cmd. */

/*@}*/

/**
* \name MIFARE Desfire Response Codes
*/
/*@{*/

#define PHAL_MFDF_RESP_OPERATION_OK                 0x00U    /**< MF DF Response - Successful operation. */
#define PHAL_MFDF_RESP_NO_CHANGES                   0x0CU    /**< MF DF Response - No changes done to backup files. */
#define PHAL_MFDF_RESP_ERR_OUT_OF_EEPROM_ERROR      0x0EU    /**< MF DF Response - Insufficient NV-Memory. */
#define PHAL_MFDF_RESP_ILLEGAL_COMMAND_CODE         0x1CU    /**< MF DF command code not supported. */
#define PHAL_MFDF_RESP_ERR_INTEGRITY_ERROR          0x1EU    /**< MF DF CRC or MAC does not match data padding bytes not valid. */
#define PHAL_MFDF_RESP_NO_SUCH_KEY                  0x40U    /**< MF DF Invalid key number specified. */
#define PHAL_MFDF_RESP_ERR_LENGTH_ERROR             0x7EU    /**< MF DF Length of command string invalid. */
#define PHAL_MFDF_RESP_PERMISSION_DENIED            0x9DU    /**< MF DF Current configuration/status does not allow the requested command. */
#define PHAL_MFDF_RESP_ERR_PARAMETER_ERROR          0x9EU    /**< MF DF Value of params invalid. */
#define PHAL_MFDF_RESP_APPLICATION_NOT_FOUND        0xA0U    /**< MF DF Requested AID not found on PICC. */
#define PHAL_MFDF_RESP_ERR_APPL_INTEGRITY_ERROR     0xA1U    /**< MF DF Unrecoverable error within application, application will be disabled. */
#define PHAL_MFDF_RESP_ERR_AUTHENTICATION_ERROR     0xAEU    /**< MF DF Current authentication status does not allow the requested cmd. */
#define PHAL_MFDF_RESP_ADDITIONAL_FRAME             0xAFU    /**< MF DF Additional data frame is expected to be sent. */
#define PHAL_MFDF_RESP_ERR_BOUNDARY_ERROR           0xBEU    /**< MF DF Attempt to read/write data from/to beyond the files/record's limits. */
#define PHAL_MFDF_RESP_ERR_PICC_INTEGRITY           0xC1U    /**< MF DF Unrecoverable error within PICC. PICC will be disabled. */
#define PHAL_MFDF_RESP_ERR_COMMAND_ABORTED          0xCAU    /**< MF DF Previous cmd not fully completed. Not all frames were requested or provided by the PCD. */
#define PHAL_MFDF_RESP_ERR_PIC_DISABLED             0xCDU    /**< MF DF PICC was disabled by an unrecoverable error. */
#define PHAL_MFDF_RESP_ERR_COUNT                    0xCEU    /**< MF DF Num. of applications limited to 28. No additional applications possible. */
#define PHAL_MFDF_RESP_ERR_DUPLICATE                0xDEU    /**< MF DF File/Application with same number already exists. */
#define PHAL_MFDF_RESP_ERR_EEPROM                   0xEEU    /**< MF DF Could not complete NV-Write operation due to loss of power. */
#define PHAL_MFDF_RESP_ERR_FILE_NOT_FOUND           0xF0U    /**< MF DF Specified file number does not exist. */
#define PHAL_MFDF_RESP_ERR_FILE_INTEGRITY           0xF1U    /**< MF DF Unrecoverable error within file. File will be disabled. */

/*@}*/

/**
* \name ISO 7816 Instructions
*/
/*@{*/
#define PHAL_MFDF_CMD_ISO7816_SELECT_FILE       0xA4U    /**< ISO Select File. */
#define PHAL_MFDF_CMD_ISO7816_READ_RECORDS      0xB2U    /**< ISO Read records. */
#define PHAL_MFDF_CMD_ISO7816_READ_BINARY       0xB0U    /**< ISO Read Binary. */
#define PHAL_MFDF_CMD_ISO7816_UPDATE_BINARY     0xD6U    /**< ISO UPDATE Binary. */
#define PHAL_MFDF_CMD_ISO7816_APPEND_RECORD     0xE2U    /**< ISO Append record. */
#define PHAL_MFDF_CMD_ISO7816_UPDATE_RECORD     0xD2U    /**< ISO Update record. */
#define PHAL_MFDF_CMD_ISO7816_GET_CHALLENGE     0x84U    /**< ISO Get challenge. */
#define PHAL_MFDF_CMD_ISO7816_EXT_AUTHENTICATE  0x82U    /**< ISO Ext. Authenticate. */
#define PHAL_MFDF_CMD_ISO7816_INT_AUTHENTICATE  0x88U    /**< ISO Int. Authenticate. */
/*@}*/

/**
* \name MIFARE Desfire specific defines
*/
/*@{*/
#define PHAL_MFDF_MAXWRAPPEDAPDU_SIZE   0x37u   /**< Maximum size of wrapped APDU 55 bytes. */
#define PHAL_MFDF_MAXDFAPDU_SIZE        0x3Cu   /**< Maximum size of DESFire APDU 60 bytes. */
#define PHAL_MFDF_DFAPPID_SIZE          0x03u   /**< Size of MF DF application Id. */
#define PHAL_MFDF_DATA_BLOCK_SIZE       0x10u   /**< Data block size need for internal purposes. */
#define PHAL_MFDF_MAX_FRAME_SIZE        0x40u   /**< Max size in a ISO 14443-4 frame. */
/*@}*/

/**
* \name ISO 7816 DF return Codes
*/
/*@{*/
#define PHAL_MFDF_ISO7816_SUCCESS                       0x9000U /**< Correct execution. */
#define PHAL_MFDF_ISO7816_ERR_WRONG_LENGTH              0x6700U /**< Wrong length. */
#define PHAL_MFDF_ISO7816_ERR_INVALID_APPLN             0x6A82U /**< Application / file not found. */
#define PHAL_MFDF_ISO7816_ERR_WRONG_PARAMS              0x6A86U /**< Wrong parameters P1 and/or P2. */
#define PHAL_MFDF_ISO7816_ERR_WRONG_LC                  0x6A87U /**< Lc inconsistent with P1/p2. */
#define PHAL_MFDF_ISO7816_ERR_WRONG_LE                  0x6C00U /**< Wrong Le. */
#define PHAL_MFDF_ISO7816_ERR_NO_PRECISE_DIAGNOSTICS    0x6F00U /**< No precise diagnostics. */
#define PHAL_MFDF_ISO7816_ERR_EOF_REACHED               0x6282U /**< End of File reached. */
#define PHAL_MFDF_ISO7816_ERR_FILE_ACCESS               0x6982U /**< File access not allowed. */
#define PHAL_MFDF_ISO7816_ERR_FILE_EMPTY                0x6985U /**< File empty or access conditions not satisfied. */
#define PHAL_MFDF_ISO7816_ERR_FILE_NOT_FOUND            0x6A82U /**< Application / File not found. */
#define PHAL_MFDF_ISO7816_ERR_MEMORY_FAILURE            0x6581U /**< Memory failure (unsuccessful update). */
#define PHAL_MFDF_ISO7816_ERR_INCORRECT_PARAMS          0x6B00U /**< Wrong parameter p1 or p2. READ RECORDS. */
#define PHAL_MFDF_ISO7816_ERR_WRONG_CLA                 0x6E00U /**< Wrong Class byte. */
#define PHAL_MFDF_ISO7816_ERR_UNSUPPORTED_INS           0x6D00U /**< Instruction not supported. */
/*@}*/

#define PHAL_MFDF_WRAP_HDR_LEN      0x05U   /* Wrapped APDU header length */
#define PHAL_MFDF_WRAPPEDAPDU_CLA   0x90U   /* Wrapped APDU default class. */
#define PHAL_MFDF_WRAPPEDAPDU_P1    0x00U   /* Wrapped APDU default P1. */
#define PHAL_MFDF_WRAPPEDAPDU_P2    0x00U   /* Wrapped APDU default P2. */
#define PHAL_MFDF_WRAPPEDAPDU_LE    0x00U   /* Wrapped APDU default LE. */

/* To avoid unused variable warnings. */
#define PHAL_MFDF_UNUSED_VARIABLE(x) ((void)x);
#define PHAL_MFDF_UNUSED_ARRAY(x)  {for( ( (x)[0] ) = ( (x)[0] ) ; ( (x)[0] ) != ( (x)[0] ) ; );}

/**
 * end of group ph_Private (Private definitions)
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
#if ((PHALMFDF_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

FUNC(uint8, ANFCRL_CODE)	GetAlMfdfExchangeState(void);

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_ExchangeCmd(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /* Pointer to params data structure */
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,  /*  Pointer to mifare protocol layer */
                                VAR(uint8, ANFCRL_VAR) bWrappedMode,
                                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSendBuff,
                                VAR(uint16, ANFCRL_VAR) wCmdLen,
                                P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppResponse,
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxlen
                                );

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Int_ComputeErrorResponse(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    VAR(uint16, ANFCRL_VAR) wStatus
    );

FUNC(phStatus_t, ANFCRL_CODE) phalMfdf_Int_Send7816Apdu(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,
                                     VAR(uint8, ANFCRL_VAR) bOption,
                                     VAR(uint8, ANFCRL_VAR) bIns,
                                     VAR(uint8, ANFCRL_VAR) bP1,
                                     VAR(uint8, ANFCRL_VAR) bP2,
                                     VAR(uint8, ANFCRL_VAR) bLc,   /*  Length of Data sent with this cmd. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDataIn,  /*  Data In of Lc bytes. */
                                     VAR(uint8, ANFCRL_VAR) bLe,  /*  Length of expected response */
                                     P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppDataOut,  /*  Data received from the card. */
                                     P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLen  /*  Length of data returned. */
                                     );

#define ANFCRL_STOP_SEC_CODE
#if ((PHALMFDF_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHALMFDF_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
 * end of group ph_Private (Private definitions)
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* PHALMFDF_INT_H */
