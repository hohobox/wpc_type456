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
*   @file    phpalI14443p4a2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4a - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4a ISO/IEC 14443-4A
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
#ifndef PHPALI14443P4A2_H
#define PHPALI14443P4A2_H

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
* @file           phpalI14443p4a2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4A_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4A_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4A_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4A_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4A_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4A_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4A_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4a2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4A_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4a2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4A_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4A_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4A_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4a2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components configure PHPAL_I14443P4A
* @{
*/

/**
* \name Configuration
*/
/*@{*/

/**
 * Configure Operation Mode for this Layer. \n
 * Possible values are\n
 *      #RD_LIB_MODE_EMVCO2, \n
 *      #RD_LIB_MODE_NFC2, \n
 *      #RD_LIB_MODE_ISO2,\n
 * Default value is #RD_LIB_MODE_NFC2.
 * */

#define PHPAL_I14443P4A_CONFIG_OPE_MODE2         0x01U

/**
 * Configure retry count for RATS command.\n
 * Possible values are\n
 *      #PHPAL_I14443P4A_RATS_RETRY_MIN2, \n
 *      #PHPAL_I14443P4A_RATS_RETRY_MAX2, \n
 *
 * Default value is #PHPAL_I14443P4A_RATS_RETRY_MAX2.\n
 *
 * For mode #RD_LIB_MODE_EMVCO2 retry count should be 1.
 * */
#define PHPAL_I14443P4A_CONFIG_RATS_RETRY_COUNT2 0x02U

/*@}*/

/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */

/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/
#define PHPAL_I14443P4A_SW_ID2   0x01U    /**< ID for Software ISO14443-4A layer     */
/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */


#ifdef NXPBUILD__PHPAL_I14443P4A2
/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components implement the additional ISO/IEC 14443-4 activation steps
* needed for ISO14443 Type-A cards.
* @{
*/

/**
* \name FSDI/FSCI Values
*/
/*@{*/
#define PHPAL_I14443P4A_NFC_FRAMESIZE_MAX2 8U   /**< Maximum allowed FSDI/FSCI value as per NFC Forum Spec. */
/*@}*/

/**
* \name DRI/DSI Values
*/
/*@{*/
#define PHPAL_I14443P4A_DATARATE_1062    0x00U   /**< DRI/DSI value for 106 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_2122    0x01U   /**< DRI/DSI value for 212 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_4242    0x02U   /**< DRI/DSI value for 424 kBit/s. */
#define PHPAL_I14443P4A_DATARATE_8482    0x03U   /**< DRI/DSI value for 848 kBit/s. */
/*@}*/

/**
* \name RATS Command Retry Values
*/
/*@{*/
#define PHPAL_I14443P4A_RATS_RETRY_MAX2    1U   /**< Maximum retry value of RATS during transmission and timeout error.*/
#define PHPAL_I14443P4A_RATS_RETRY_MIN2    0U   /**< Minimum retry value of RATS during transmission and timeout error.*/
/*@}*/

#ifdef NXPRDLIB_REM_GEN_INTFS2

#define phpalI14443p4a_Rats2( pDataParams2,  bFsdi2, bCid2, pAts2) \
        phpalI14443p4a_Sw_Rats2((phpalI14443p4a_Sw_DataParams_t2 *)pDataParams2, bFsdi2, bCid2, pAts2)

#define phpalI14443p4a_Pps2( pDataParams2,  bDri2, bDsi2 ) \
        phpalI14443p4a_Sw_Pps2((phpalI14443p4a_Sw_DataParams_t2 *)pDataParams2, bDri2, bDsi2)

#define phpalI14443p4a_ActivateCard2( pDataParams2, bFsdi2, bCid2,bDri2, bDsi2, pAts2) \
        phpalI14443p4a_Sw_ActivateCard2((phpalI14443p4a_Sw_DataParams_t2 *)pDataParams2, bFsdi2, bCid2, bDri2, bDsi2, pAts2)

#define phpalI14443p4a_GetProtocolParams2( pDataParams2,  pCidEnabled2, pCid2, pNadSupported2,  pFwi2,  pFsdi2, pFsci2 ) \
        phpalI14443p4a_Sw_GetProtocolParams2((phpalI14443p4a_Sw_DataParams_t2 *)pDataParams2, pCidEnabled2, pCid2, pNadSupported2, pFwi2, pFsdi2, pFsci2)

#define phpalI14443p4a_SetConfig2(pDataParams2, wConfig2,wValue2) phpalI14443p4a_Sw_SetConfig2((phpalI14443p4a_Sw_DataParams_t2 *)pDataParams2, wConfig2,wValue2)

#endif /* NXPRDLIB_REM_GEN_INTFS2 */
/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A2 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
 * \brief State for ActivateCard
 */
typedef enum {
  PHPAL_I14443P4A_ACTCARD_IDLE2 = 0,
  PHPAL_I14443P4A_ACTCARD_RATS2,
  PHPAL_I14443P4A_ACTCARD_PPS2
} I14443P4A_ACTCARD_StateType_t2;

/**
 * \brief State for Rats
 */
typedef enum {
  PHPAL_I14443P4A_RATS_IDLE2 = 0,
  PHPAL_I14443P4A_RATS_WAIT2,
  PHPAL_I14443P4A_RATS_HALT2,
  PHPAL_I14443P4A_RATS_SEND2,
  PHPAL_I14443P4A_RATS_FWTCONFIG2,
  PHPAL_I14443P4A_RATS_DESELSEND2,
  PHPAL_I14443P4A_RATS_SET_ACTIVATION_TIMEOUT2,
  PHPAL_I14443P4A_RATS_SET_HLTA_TIMEOUT2,
  PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_MS2,
  PHPAL_I14443P4A_RATS_SET_FW_TIMEOUT_VALUE_US2
} I14443P4A_RATS_StateType_t2;

/**
 * \brief State for Pps
 */
typedef enum {
  PHPAL_I14443P4A_PPS_IDLE2 = 0,
  PHPAL_I14443P4A_PPS_EXCHANGE2,
  PHPAL_I14443P4A_PPS_TXDATARATE2,
  PHPAL_I14443P4A_PPS_RXDATARATE2
} I14443P4A_PPS_StateType_t2;

/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
* \brief Software PAL-ISO14443P4A parameter structure
 */
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId2; /**< Layer ID for this component, NEVER MODIFY! */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2; /**< Pointer to the parameter structure of the underlying layer. */
  VAR(uint8, ANFCRL_VAR) bCidSupported2; /**< Cid Support indicator; Unequal '0' if supported. */
  VAR(uint8, ANFCRL_VAR) bNadSupported2; /**< Nad Support indicator; Unequal '0' if supported. */
  VAR(uint8, ANFCRL_VAR) bCid2; /**< Card Identifier; Ignored if bCidSupported2 is equal '0'. */
  VAR(uint8, ANFCRL_VAR) bBitRateCaps2; /**< TA(1) byte of ATS; ISO/IEC 14443-4:2008, Section 5.2.4. */
  VAR(uint8, ANFCRL_VAR) bFwi2; /**< Frame Waiting Integer. */
  VAR(uint8, ANFCRL_VAR) bFsci2; /**< PICC Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bFsdi2; /**< (Current) PCD Frame Size Integer; 0-8; */
  VAR(uint8, ANFCRL_VAR) bDri2; /**< (Current) Divisor Receive (PCD to PICC) Integer; 0-3; */
  VAR(uint8, ANFCRL_VAR) bDsi2; /**< (Current) Divisor Send (PICC to PCD) Integer; 0-3; */
  VAR(uint8, ANFCRL_VAR) bOpeMode2; /**< Operation mode. One of NFC, EMVCo, ISO.*/
  VAR(uint8, ANFCRL_VAR) bRetryCount2; /**< Retry count for RATS command as per NFC Digital Protocol Version 1.1\n
	 For mode #RD_LIB_MODE_EMVCO2 retry count should be 1. */
	/* State variables for Non-Blocking */
  VAR(I14443P4A_ACTCARD_StateType_t2, ANFCRL_VAR) eActCardState2; /**< Handle state of ActivateCard function of I14443P4A. */
  VAR(I14443P4A_RATS_StateType_t2, ANFCRL_VAR) eRatsState2; /**< Handle state of Rats function of I14443P4A. */
  VAR(I14443P4A_PPS_StateType_t2, ANFCRL_VAR) ePpsState2; /**< Handle state of Pps function of I14443P4A. */
} phpalI14443p4a_Sw_DataParams_t2;

/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
/** \defgroup phpalI14443p4a_Sw Component : Software
* \brief Software component of ISO/IEC 14443-4A
* \ingroup phpalI14443p4a
* @{
*/

/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Sw_Init2(
                                  P2VAR(phpalI14443p4a_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layer's parameter structure. */
                                  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                   /**< [In] Specifies the size of the data parameter structure. */
                                  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2                         /**< [In] Pointer to the parameter structure of the underlying layer.*/
                                  );
/**
 * end of group phpalI14443p4a_Sw Component : Software
 * @}
 */
#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4A2

/** \defgroup phpalI14443p4a ISO/IEC 14443-4A
* \ingroup phpalProtocol
* \brief These Components implement the additional ISO/IEC 14443-4 activation steps
* needed for ISO14443 Type-A cards.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phpalI14443p4a/src/Sw/phpalI14443p4a_Sw2.h"
#else

#define ANFCRL_START_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif
/**
* \brief Perform a ISO14443-4A "Request Answer to Select" command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
\verbatim
[FSDI to FSD conversion]
---------------------------------------------------------------
FSDI         | 00 | 01 | 02 | 03 | 04 | 05 | 06 | 07  | 08  |
---------------------------------------------------------------
FSD (bytes)  | 16 | 24 | 32 | 40 | 48 | 64 | 96 | 128 | 256 |
---------------------------------------------------------------
\endverbatim
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Rats2(
                               P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layer's parameter structure. */
                               VAR(uint8, ANFCRL_VAR) bFsdi2,       /**< [In] Frame Size Integer; 0-8. */
                               VAR(uint8, ANFCRL_VAR) bCid2,        /**< [In] Card Identifier; 0-14. */
                               P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts2       /**< [Out] Answer to Select; uint8[255]. */
                               );

/**
* \brief Perform a ISO14443-4A "Protocol and Parameter Selection" command.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* The following values for \c bDri2 and \c bDsi2 are possible:\n
* \li #PHPAL_I14443P4A_DATARATE_1062
* \li #PHPAL_I14443P4A_DATARATE_2122
* \li #PHPAL_I14443P4A_DATARATE_4242
* \li #PHPAL_I14443P4A_DATARATE_8482
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_Pps2(
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layer's parameter structure. */
                              VAR(uint8, ANFCRL_VAR) bDri2,         /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                              VAR(uint8, ANFCRL_VAR) bDsi2          /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                              );

/**
* \brief Perform ISO14443-4A Rats and Pps commands.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval #PH_ERR_FRAMING_ERROR2 Bcc invalid.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_ActivateCard2(
                                       P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,  /**< [In] Pointer to this layer's parameter structure. */
                                       VAR(uint8, ANFCRL_VAR) bFsdi2,       /**< [In] Frame Size Integer; 0-8. */
                                       VAR(uint8, ANFCRL_VAR) bCid2,        /**< [In] Card Identifier; 0-14. */
                                       VAR(uint8, ANFCRL_VAR) bDri2,        /**< [In] Divisor Receive (PCD to PICC) Integer; 0-3. */
                                       VAR(uint8, ANFCRL_VAR) bDsi2,        /**< [In] Divisor Send (PICC to PCD) Integer; 0-3. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts2       /**< [Out] Answer to Select; uint8[255]. */
                                       );

/**
* \brief Retrieve the ISO14443-4A protocol parameters.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_GetProtocolParams2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCidEnabled2,      /**< [Out] Unequal '0' if Card Identifier is enabled. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCid2,             /**< [Out] Card Identifier. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNadSupported2,    /**< [Out] Node Address Support; Unequal '0' if supported. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFwi2,             /**< [Out] Frame Waiting Integer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsdi2,            /**< [Out] PCD Frame Size Integer; 0-8. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pFsci2             /**< [Out] PICC Frame Size Integer; 0-8. */
    );

/**
* \brief Set configuration parameter.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4a_SetConfig2(
                                    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                                    VAR(uint16, ANFCRL_VAR) wConfig2,   /**< [In] Configuration Identifier. */
                                    VAR(uint16, ANFCRL_VAR) wValue2     /**< [In] Configuration Value. */
                                   );

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4A_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4A_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phpalI14443p4a ISO/IEC 14443-4A
 * @}
 */

#endif /* NXPBUILD__PHPAL_I14443P4A2 */

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4A2_H */
