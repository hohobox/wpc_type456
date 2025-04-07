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
*   @file    phpalI14443p4_Sw_Int2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalI14443p4_Sw_Int - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalI14443p4 ISO/IEC 14443-4
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


#ifndef PHPALI14443P4_SW_INT2_H
#define PHPALI14443P4_SW_INT2_H

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

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phpalI14443p4_Sw_Int2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALI14443P4_SW_INT_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALI14443P4_SW_INT_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHPALI14443P4_SW_INT_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHPALI14443P4_SW_INT_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHPALI14443P4_SW_INT_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHPALI14443P4_SW_INT_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHPALI14443P4_SW_INT_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHPALI14443P4_SW_INT_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALI14443P4_SW_INT_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phpalI14443p4_Sw_Int2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALI14443P4_SW_INT_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_INT_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALI14443P4_SW_INT_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalI14443p4_Sw_Int2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALI14443P4_SW_INT_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALI14443P4_SW_INT_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALI14443P4_SW_INT_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalI14443p4_Sw_Int2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

/** ISO 14443-4 Block Mask */
#define PHPAL_I14443P4_SW_BLOCK_MASK2            0xC0U

/** ISO 14443-4 I-Block */
#define PHPAL_I14443P4_SW_I_BLOCK2               0x00U
/** ISO 14443-4 I-Block RFU mask */
#define PHPAL_I14443P4_SW_I_BLOCK_RFU_MASK2      0x22U
/** ISO 14443-4 I-Block RFU bits */
#define PHPAL_I14443P4_SW_I_BLOCK_RFU_BITS2      0x02U

/** ISO 14443-4 R-Block */
#define PHPAL_I14443P4_SW_R_BLOCK2               0x80U
/** ISO 14443-4 R-Block RFU mask */
#define PHPAL_I14443P4_SW_R_BLOCK_RFU_MASK2      0x26U
/** ISO 14443-4 R-Block RFU bits */
#define PHPAL_I14443P4_SW_R_BLOCK_RFU_BITS2      0x22U

/** ISO 14443-4 S-Block */
#define PHPAL_I14443P4_SW_S_BLOCK2               0xC0U
/** ISO 14443-4 S-Block RFU mask */
#define PHPAL_I14443P4_SW_S_BLOCK_RFU_MASK2      0x07U
/** ISO 14443-4 S-Block RFU bits */
#define PHPAL_I14443P4_SW_S_BLOCK_RFU_BITS2      0x02U

/** Byte position of PCB byte */
#define PHPAL_I14443P4_SW_PCB_POS2               0x00U

/** Block number Bit within PCB */
#define PHPAL_I14443P4_SW_PCB_BLOCKNR2           0x01U

/** Bit within PCB which signals presence of NAD byte */
#define PHPAL_I14443P4_SW_PCB_NAD_FOLLOWING2     0x04U

/** Bit within PCB which signals presence of CID byte */
#define PHPAL_I14443P4_SW_PCB_CID_FOLLOWING2     0x08U

/** Bit within PCB which signals chaining */
#define PHPAL_I14443P4_SW_PCB_CHAINING2          0x10U

/** Bit within PCB which signals ACK */
#define PHPAL_I14443P4_SW_PCB_ACK2               0x00U

/** Bit within PCB which signals NAK */
#define PHPAL_I14443P4_SW_PCB_NAK2               0x10U

/** Bits within PCB which signal a DESELECT command */
#define PHPAL_I14443P4_SW_PCB_DESELECT2          0x00U

/** Bits within PCB which signal a WTX command */
#define PHPAL_I14443P4_SW_PCB_WTX2               0x30U

/** WTXM Bits of WTX INF byte */
#define PHPAL_I14443P4_SW_WTXM_BITS2             0x3FU

/** FWI default value */
#define PHPAL_I14443P4_SW_FWI_DEFAULT2           0x04U

/** FSCI default value */
#define PHPAL_I14443P4_SW_FSCI_DEFAULT2          0x02U

/** FTW min in microseconds */
#define PHPAL_I14443P4_SW_FWT_MIN_US2            302U

/** FTW max in microseconds */
#define PHPAL_I14443P4_SW_FWT_MAX_US2            4949000U

/** FTW max in microseconds in NFC Mode */
#define PHPAL_I14443P4_SW_NFC_FWT_MAX_US2        4953000U

/** FTW max in microseconds in EMVCo Mode */
#define PHPAL_I14443P4_SW_EMVCO_FWT_MAX_US2      4954000U

/** S(DESELECT) FTW in microseconds */
#define PHPAL_I14443P4_SW_FWT_DESELECT_US2       5286U

/** Valid CID bits within CID field */
#define PHPAL_I14443P4_SW_CID_MASK2              0x0FU

/** I-Block transmission mode  */
#define PHPAL_I14443P4_SW_STATE_I_BLOCK_TX2      0x01U

/** I-Block reception mode  */
#define PHPAL_I14443P4_SW_STATE_I_BLOCK_RX2      0x02U

/** Exchange finished mode  */
#define PHPAL_I14443P4_SW_STATE_FINISHED2        0x0FU

/** An I-Block mode is re-transmitting */
#define PHPAL_I14443P4_SW_STATE_RETRANSMIT_BIT2  0x40U

/** An I-Block mode is chaining */
#define PHPAL_I14443P4_SW_STATE_CHAINING_BIT2    0x80U

/** Only 6 bits of the state are pure state codes */
#define PHPAL_I14443P4_SW_STATE_MASK2            0x0FU

/** Default Maximum Retry count for ISO/IEC 14443-4:2008(E) Rule 4 and 5 */
#define PHPAL_I14443P4_SW_MAX_RETRIES_DEFAULT2   2U

/** Time extension in microseconds for all commands.  */
#define PHPAL_I14443P4_EXT_TIME_US2              60U

/** EMVCo: Time extension to support EMVCO Req */
#define PHPAL_I14443P4_EMVCO_FWT_US2             30U

/** Power level Indication bit mask for INF of SWTX */
#define PHPAL_I14443P4_SW_S_BLOCK_INF_PLI_MASK2 0xC0U

/** FTW min in microseconds */
#define PHPAL_I14443P4_SW_FWT_MIN_US2            302U

/** Delta TPCD max in microseconds */
#define PHPAL_I14443P4_SW_DELTA_TPCD_US_MAX2     16400U

/** Delta TPCD minimum in microseconds */
#define PHPAL_I14443P4_SW_DELTA_TPCD_US_MIN2     0U

/** Delta frame wait time (FWT) in microseconds = 49152/fc */
#if defined(NXPBUILD__PHHAL_HW_NCx33202)
/** Note: Additional delay is required for NCx3320 Reader IC to PASS NFC Forum CR11 DP test suite v2.2.1 */
#define PHPAL_I14443P4_SW_DELTA_FWT_US2          4100U
#else
#define PHPAL_I14443P4_SW_DELTA_FWT_US2          3625U
#endif

/** Delta TPCD used for exchange (in microseconds) */
#define PHPAL_I14443P4_SW_DELTA_TPCD_US2         1000U

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
#if ((PHPALI14443P4_SW_INT_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_SW_INT_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

/**
* \brief Build I-Block frame header
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildIBlock2(
                                        VAR(uint8, ANFCRL_VAR) bCidEnabled2,    /**< [In] Set to != 0 to enable CID byte */
                                        VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] CID byte */
                                        VAR(uint8, ANFCRL_VAR) bNadEnabled2,    /**< [In] Set to != 0 to enable NAD byte */
                                        VAR(uint8, ANFCRL_VAR) bNad2,           /**< [In] NAD byte */
                                        VAR(uint8, ANFCRL_VAR) bPcbBlockNum2,   /**< [In] PCB block number bit */
                                        VAR(uint8, ANFCRL_VAR) bChaining2,      /**< [In] Set to != 0 if chaining bit should be set */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,    /**< [Out] transmit buffer */
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2    /**< [Out] number of bytes to send */
                                        );

/**
* \brief Build R(ACK) / R(NAK) frames
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildRBlock2(
                                        VAR(uint8, ANFCRL_VAR) bCidEnabled2,    /**< [In] Set to != 0 to enable CID byte */
                                        VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] CID byte */
                                        VAR(uint8, ANFCRL_VAR) bPcbBlockNum2,   /**< [In] PCB block number bit */
                                        VAR(uint8, ANFCRL_VAR) bIsAck2,         /**< [In] Set to != 0 if an ACK should be generated */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,    /**< [Out] transmit buffer */
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2    /**< [Out] number of bytes to send */
                                        );

/**
* \brief Build S-Block frames
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_BuildSBlock2(
                                        VAR(uint8, ANFCRL_VAR) bCidEnabled2,    /**< [In] Set to != 0 to enable CID byte */
                                        VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] CID byte */
                                        VAR(uint8, ANFCRL_VAR) bIsWtx2,         /**< [In] Set to != 0 if a WTX frame should be generated */
                                        VAR(uint8, ANFCRL_VAR) bWtxm2,          /**< [In] WTXM bits, used if /ref bIsWtx2 is set */
                                        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,    /**< [Out] transmit buffer */
                                        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pTxLength2    /**< [Out] number of bytes to send */
                                        );

/**
* \brief Check if received I-Block is valid.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Block invalid.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidIBlock2(
    VAR(uint8, ANFCRL_VAR) bCheckCid2,      /**< [In] Set to != 0 to enable CID check */
    VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] Current CID for comparison */
    VAR(uint8, ANFCRL_VAR) bCheckNad2,      /**< [In] Set to != 0 to enable NAD check */
    VAR(uint8, ANFCRL_VAR) bNad2,           /**< [In] Current NAD for comparison */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,    /**< [In] Received data */
    VAR(uint16, ANFCRL_VAR) wRxLength2      /**< [In] Number of received data bytes */
    );

/**
* \brief Check if received R-Block is valid.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Block invalid.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidRBlock2(
    VAR(uint8, ANFCRL_VAR) bCheckCid2,      /**< [In] Set to != 0 to enable CID check */
    VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] Current CID for comparison */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,    /**< [In] Received data */
    VAR(uint16, ANFCRL_VAR) wRxLength2      /**< [In] Number of received data bytes */
    );

/**
* \brief Check if received S-Block is valid.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Block invalid.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsValidSBlock2(
    VAR(uint8, ANFCRL_VAR) bCheckCid2,      /**< [In] Set to != 0 to enable CID check */
    VAR(uint8, ANFCRL_VAR) bCid2,           /**< [In] Current CID for comparison */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,    /**< [In] Received data */
    VAR(uint16, ANFCRL_VAR) wRxLength2      /**< [In] Number of received data bytes */
    );

/**
* \brief Perform actual exchanging and take care about error handling etc.
*
* Checks response and performs state transition and complete error & WTX handling if necessary.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phpalI14443p4_Sw_IsoHandling2(
    P2VAR(phpalI14443p4_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint16, ANFCRL_VAR) wOption2,                               /**< [In] option parameter. */
    VAR(uint8, ANFCRL_VAR) bRetryCount2,                            /**< [In] number of already performed retry. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer2,                            /**< [In] data to transmit */
    VAR(uint16, ANFCRL_VAR) wTxLength2,                             /**< [In] length of input data */
    P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer2,                          /**< [Out] Pointer to received data */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2                            /**< [In] Received data bytes */
    );

/**
 * end of group ph_Private (Private definitions)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALI14443P4_SW_INT_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHPALI14443P4_SW_INT_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALI14443P4_SW_INT2_H */
