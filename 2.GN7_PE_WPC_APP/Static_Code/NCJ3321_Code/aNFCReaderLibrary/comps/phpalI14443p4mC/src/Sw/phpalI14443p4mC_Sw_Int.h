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
*   @file    phpalI14443p4mC_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR palI14443p4mC_Sw_Int - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phpalI14443p4mC ISO/IEC 14443-4mC
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

#ifndef PHPALI14443P4MC_SW_INT_H
#define PHPALI14443P4MC_SW_INT_H
#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4mC_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4MC_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4MC_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4MC_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4MC_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4MC_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4MC_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4MC_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4mC_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4MC_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4mC_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4MC_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4MC_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4MC_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4mC_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** Macro used to Calculate FWT Value based on FWI. */
#define PHPAL_I14443P4MC_SW_CALCULATE_FWT_US(bFWI)                    \
	(PHPAL_I14443P4MC_SW_FWT_MIN_US*((uint32)1U << (bFWI)))

/** Check if PCB indicates WTX Request/Response */
#define PHPAL_I14443P4MC_SW_IS_WTX(bPcb)                              \
	((((bPcb) & PHPAL_I14443P4MC_SW_PCB_WTX) == PHPAL_I14443P4MC_SW_PCB_WTX) ? 1u : 0u)

/* Default values for parameters */
#define PHPALI14443P4MC_FSCI_DEFAULT        0x02U
#define PHPALI14443P4MC_FWI_DEFAULT         0x04U
#define PHPALI14443P4MC_SFGI_DEFAULT        0x00U
#define PHPALI14443P4MC_FSC_MAX_NFC_FORUM   0x08U
#define PHPALI14443P4MC_FSC_MIN_NFC_FORUM   0x02U

/* Command codes */
#define PHPALI14443P4MC_RATS_CMD            0xE0U
#define PHPALI14443P4MC_PPS_CMD             0xD0U
#define PHPALI14443P4MC_HALT_CMD            0x50U

/* Command lengths */
#define PHPALI14443P4MC_RATS_LEN            0x02U
#define PHPALI14443P4MC_PPS_LEN             0x01U
#define PHPALI14443P4MC_NFC_MAX_ATS_LEN     0x14U
#define PHPALI14443P4MC_NFC_MIN_ATS_LEN     0x05U

/* ATS command parameters index */
#define PHPALI14443P4MC_TL_IDX              0x00U
#define PHPALI14443P4MC_T0_IDX              0x01U
#define PHPALI14443P4MC_TA1_IDX             0x02U
#define PHPALI14443P4MC_TB1_IDX             0x03U
#define PHPALI14443P4MC_TC1_IDX             0x04U

/* PPS mask values */
#define PHPALI14443P4MC_PPS_PPS1_MASK       0x10U
#define PHPALI14443P4MC_VALID_PPS0_MASK     0xEFU
#define PHPALI14443P4MC_PPS_PPS2_MASK       0xF0U

/** Valid CID bits within CID field */
#define PHPALI14443P4MC_CID_MASK            0x0FU

/** Valid NAD bits within NAD field */
#define PHPALI14443P4MC_NAD_MASK            0x77U

/* Block mask values */
#define PHPALI14443P4MC_BLOCK_MASK          0xC0U
#define PHPALI14443P4MC_R_NAK_MASK          0x10U
#define PHPALI14443P4MC_BLOCKNUMBER_MASK    0x01U

/* Supported Block types */
#define PHPALI14443P4MC_BLOCK_I             0x02U
#define PHPALI14443P4MC_BLOCK_R             0x82U
#define PHPALI14443P4MC_BLOCK_S             0xC2U

/* Check CID presence in block */
#define PHPALI14443P4MC_BLOCK_HAS_CID       0x08U

/* Check chaining I-Block */
#define PHPALI14443P4MC_BLOCK_IS_CHAIN      0x10U

/* S-Block mask */
#define PHPALI14443P4MC_BLOCK_S_MASK        0x30U

/* S-Block commands */
#define PHPALI14443P4MC_BLOCK_S_DESELECT    0x00U
#define PHPALI14443P4MC_BLOCK_S_WTX         0x30U

/* R-Block ACK command */
#define PHPALI14443P4MC_BLOCK_R_PCB_ACK     0xA2U

/* Number of frame size table entries */
#define PHPALI14443P4MC_FS_INDEX            0x0DU

/* Number of data rate table entries */
#define PHPALI14443P4MC_DR_INDEX            0x04U

/** Byte position of PCB byte */
#define PHPAL_I14443P4MC_SW_PCB_POS               0x00U

/** ISO 14443-4 I-Block */
#define PHPAL_I14443P4MC_SW_I_BLOCK               0x00U
/** ISO 14443-4 I-Block constant bits mask */
#define PHPAL_I14443P4MC_SW_I_BLOCK_CONST_MASK    0x02U
/** ISO 14443-4 I-Block constant bits */
#define PHPAL_I14443P4MC_SW_I_BLOCK_CONST_BITS    0x02U

/** ISO 14443-4 R-Block */
#define PHPAL_I14443P4MC_SW_R_BLOCK               0x80U
/** ISO 14443-4 R-Block constant bits mask */
#define PHPAL_I14443P4MC_SW_R_BLOCK_CONST_MASK    0x24U
/** ISO 14443-4 R-Block constant bits(b6(1) and b3(0)) */
#define PHPAL_I14443P4MC_SW_R_BLOCK_CONST_BITS    0x20U

/** ISO 14443-4 S-Block */
#define PHPAL_I14443P4MC_SW_S_BLOCK               0xC0U
/** ISO 14443-4 S-Block constant bits mask */
#define PHPAL_I14443P4MC_SW_S_BLOCK_CONST_MASK    0x04U
/** ISO 14443-4 S-Block constant bits (b3(0)) */
#define PHPAL_I14443P4MC_SW_S_BLOCK_CONST_BITS    0x00U
/** ISO 14443-4 S-Block WTX Frame. */
#define PHPAL_I14443P4MC_SW_S_BLOCK_WTX_FRAME     0xF2U

/** Bit within PCB which signals presence of NAD byte */
#define PHPAL_I14443P4MC_SW_PCB_NAD_FOLLOWING     0x04U

/** Bit within PCB which signals presence of CID byte */
#define PHPAL_I14443P4MC_SW_PCB_CID_FOLLOWING     0x08U

/** Bit within PCB which signals chaining */
#define PHPAL_I14443P4MC_SW_PCB_CHAINING          0x10U

/** Bit within PCB which signals ACK */
#define PHPAL_I14443P4MC_SW_PCB_ACK               0x00U

/** Bit within PCB which signals NAK */
#define PHPAL_I14443P4MC_SW_PCB_NAK               0x10U

/** Bits within PCB which signal a DESELECT command */
#define PHPAL_I14443P4MC_SW_PCB_DESELECT          0x00U

/** Bits within PCB which signal a WTX command */
#define PHPAL_I14443P4MC_SW_PCB_WTX               0x30U

/** WTX Res RFU Mask of ISO 14443-4 S-Block */
#define PHPAL_I14443P4MC_SW_WTX_RFU_MASK          0xC0U

/** WTX value Mask of ISO 14443-4 S-Block */
#define PHPAL_I14443P4MC_SW_WTX_VALUE_MASK        0x3FU

/** WTX max value */
#define PHPAL_I14443P4MC_SW_MAX_WTX_VALUE         0x3BU

/** WTX min value */
#define PHPAL_I14443P4MC_SW_MIN_WTX_VALUE         0x01U

/** Minimum response waiting time, ISO/IEC 14443-4:2008 section 7.2 */
#define PHPAL_I14443P4MC_SW_FWT_MIN_US            302U

/** Maximum response waiting time, ISO/IEC 14443-4:2008 section 7.2 */
#define PHPAL_I14443P4MC_SW_FWT_MAX_US            4947968UL
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
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
* \brief Function to validate ISO/IEC 14443-4 frame.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR  Protocol Error.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_ValidateFrame(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                                /**< [In] Pointer to receive Buffer */
  VAR(uint16, ANFCRL_VAR) wRxLength,                                 /**< [In] Pointer to receive Buffer Length */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppPayload,                               /**< [Out] Pointer to pay load Buffer */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pPayloadLength                           /**< [Out] Pointer to pay load Buffer Length */
	);

/**
* \brief Function to validate ISO14443-4 I-Block.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR  Protocol Error.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidIBlock(
  VAR(uint8, ANFCRL_VAR) bOpMode,                                    /**< [In] Operating mode of library (NFC or ISO) */
  VAR(uint8, ANFCRL_VAR) bCheckCid,                                  /**< [In] Enable/Disable CID Checking*/
  VAR(uint8, ANFCRL_VAR) bCid,                                       /**< [In] CID Value*/
  VAR(uint8, ANFCRL_VAR) bCheckNad,                                  /**< [In] Enable/Disable NAD Checking*/
  VAR(uint8, ANFCRL_VAR) bNad,                                       /**< [In] NAD Value */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                                /**< [In] Pointer to receive Buffer */
  VAR(uint16, ANFCRL_VAR) wRxLength                                  /**< [In] Receive Buffer Length*/
	);

/**
* \brief Function to validate ISO14443-4 R-Block
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR  Protocol Error.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidRBlock(
  VAR(uint8, ANFCRL_VAR) bOpMode,                                    /**< [In] Operating mode of library (NFC or ISO) */
  VAR(uint8, ANFCRL_VAR) bCheckCid,                                  /**< [In] Enable/Disable CID */
  VAR(uint8, ANFCRL_VAR) bCid,                                       /**< [In] CID Value*/
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                                /**< [In] Pointer to receive Buffer */
  VAR(uint16, ANFCRL_VAR) wRxLength                                  /**< [In] Receive Buffer Length*/
	);

/**
* \brief Function to validate ISO14443-4 S-Block
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR  Protocol Error.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_IsValidSBlock(
  VAR(uint8, ANFCRL_VAR) bOpMode,                                    /**< [In] Operating mode of library (NFC or ISO) */
  VAR(uint8, ANFCRL_VAR) bCheckCid,                                  /**< [In] Enable/Disable CID */
  VAR(uint8, ANFCRL_VAR) bCid,                                       /**< [In] CID Value*/
  VAR(uint8, ANFCRL_VAR) bWtx,                                       /**< [In] Value of WTX */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                                /**< [In] Pointer to receive Buffer */
  VAR(uint16, ANFCRL_VAR) wRxLength                                  /**< [In] Receive Buffer Length */
	);

/**
* \brief Function to get PDU header Length.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_GetPduHeaderLength(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure */
  VAR(uint8, ANFCRL_VAR) bNadInclude,                                /**< [In] NAD Present or not in current frame */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pProtLength                               /**< [Out] Pointer protocol Length */
	);

/**
* \brief Validate PPS Request and send PPS Response.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other errors depends on lower layers.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_PpsRes(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPps,                                     /**< [In] Pointer to PPS Response Buffer */
  VAR(uint8, ANFCRL_VAR) bPpsLength                                 /**< [In] Length of PPS receive Buffer */
	);

/**
* \brief Perform a ISO14443-4 S-Block Deselect Response.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other errors depends on lower layers.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_DslRes(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams       /**< [In] Pointer to this layer's parameter structure */
	);

/**
* \brief Function to send ACK.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other errors depends on lower layers.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_Ack(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams       /**< [In] Pointer to this layer's parameter structure */
	);

/**
* \brief Function to handle Receive Chaining
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other errors depends on lower layers.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_HandleRxChaining(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,      /**< [In] Pointer to this layer's parameter structure */
  VAR(uint16, ANFCRL_VAR) wOption,                                   /**< [In] Receive option */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,                              /**< [Out] Pointer to receive Buffer */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength                                /**< [Out] Pointer to receive Buffer Length */
	);

/**
* \brief Function to start WTX timer.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other errors depends on lower layers.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalI14443p4mC_Sw_Int_StartWtxTimer(
  P2VAR(phpalI14443p4mC_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams       /**< [In] Pointer to this layer's parameter structure */
	);

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4MC_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALI14443P4MC_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4MC_SW_INT_H */
