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
*   @file    phpalSli15693_Sw_Int.h
*   @version 1.0.0
*
*   @brief   AUTOSAR PalSli15693_Sw_Int - PAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phpalSli15693 ISO/IEC 15693 
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
#ifndef PHPALSLI15693_SW_INT_H
#define PHPALSLI15693_SW_INT_H

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
* @file           phpalSli15693_Sw_Int.h
* @implements     DESIGN001, DESIGN002
*/
#define PHPALSLI15693_SW_INT_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHPALSLI15693_SW_INT_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHPALSLI15693_SW_INT_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHPALSLI15693_SW_INT_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHPALSLI15693_SW_INT_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHPALSLI15693_SW_INT_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHPALSLI15693_SW_INT_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHPALSLI15693_SW_INT_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHPALSLI15693_SW_INT_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phpalSli15693_Sw_Int.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHPALSLI15693_SW_INT_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHPALSLI15693_SW_INT_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHPALSLI15693_SW_INT_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phpalSli15693_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHPALSLI15693_SW_INT_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHPALSLI15693_SW_INT_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHPALSLI15693_SW_INT_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phpalSli15693_Sw_Int.h and CDD_AnfcRL_Cfg.h are different"
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

/**
* \name Constants
*/
/*@{*/
/** IC Manufacturer Code of NXP. */
#define PHPAL_SLI15693_SW_NXP_MFG_CODE              0x04U
/** Time extension in microseconds for all commands.  */
#define PHPAL_SLI15693_SW_EXT_TIME_US               60U
/** Waiting time T1 in us (ISO/IEC15693, 9.1.4.) */
#define PHPAL_SLI15693_SW_T1_WAITING_TIME           324U
/** Waiting time T2 in us (ISO/IEC15693, 9.1.4.) */
#define PHPAL_SLI15693_SW_T2_WAITING_TIME           310U
/** UID length in bits when complete. */
#define PHPAL_SLI15693_SW_UID_COMPLETE              64U
/** Default flags (DATA_RATE and INVENTORY BIT is set). */
#define PHPAL_SLI15693_SW_FLAGS_DEFAULT             0x06U
/** Slot timeout */
#define PHPAL_SLI15693_SW_TIMEOUT_SLOT_US           PHPAL_SLI15693_SW_T1_WAITING_TIME + PHPAL_SLI15693_SW_T2_WAITING_TIME
/** Nominal Response Time for High Data Rate */
#define PHPAL_SLI15693_SW_HIGH_NRT_US               3928U
/** Nominal Response Time for Fast High Data Rate */
#define PHPAL_SLI15693_SW_FASTHIGH_NRT_US           1964U
/** Nominal Response Time for Low Data Rate */
#define PHPAL_SLI15693_SW_LOW_NRT_US                15709U
/** Nominal Response Time for Fast Low Data Rate */
#define PHPAL_SLI15693_SW_FASTLOW_NRT_US            7855U
/** Start of Frame Time for High Data Rate */
#define PHPAL_SLI15693_SW_HIGH_SOF_US               152U
/** Start of Frame  Time for Fast High Data Rate */
#define PHPAL_SLI15693_SW_FASTHIGH_SOF_US           76U
/** Start of Frame Time for Low Data Rate */
#define PHPAL_SLI15693_SW_LOW_SOF_US                605U
/** Start of Frame  Time for Fast Low Data Rate */
#define PHPAL_SLI15693_SW_FASTLOW_SOF_US            303U

/*@}*/

/**
* \name Mandatory commands
*/
/*@{*/
/** Anti-collision inventory cmd code */
#define PHPAL_SLI15693_SW_CMD_INVENTORY        0x01U
/** Stay Quiet cmd code */
#define PHPAL_SLI15693_SW_CMD_STAY_QUIET       0x02U
/*@}*/

/**
* \name Optional commands
*/
/*@{*/
/** Select cmd code */
#define PHPAL_SLI15693_SW_CMD_SELECT            0x25U
/** Reset to ready cmd code */
#define PHPAL_SLI15693_SW_CMD_RESET_TO_READY    0x26U
/*@}*/

/**
* \name Custom commands
*/
/*@{*/
/** Inventory read cmd code */
#define PHPAL_SLI15693_SW_CMD_INVENTORY_READ            0xA0U
/** Fast inventory read cmd code */
#define PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_READ       0xA1U
/** Inventory page read cmd code */
#define PHPAL_SLI15693_SW_CMD_INVENTORY_PAGE_READ       0xB0U
/** Fast inventory page read cmd code */
#define PHPAL_SLI15693_SW_CMD_FAST_INVENTORY_PAGE_READ  0xB1U
/** Stay quiet persistent cmd code */
#define PHPAL_SLI15693_SW_CMD_STAY_QUIET_PERSISTENT     0xBCU
/** ICODE command code for ExtendedGetSystemInformation command. */
#define PHPAL_SLI15693_SW_CMD_EXTENDED_GET_SYSTEM_INFORMATION  0x3BU
/** Begin Code for Custom command  as per ISO 15693 */
#define PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_BEGIN     0x9FU
/** End Code for Custom command  as per ISO 15693 */
#define PHPAL_SLI15693_SW_CUSTOM_CMD_CODE_END       0xE0U
/* Macro to represent the command's MaskBitLen as extended. */
#define PHPAL_SLI15693_SW_FLAG_INVENTORY_READ_EXTENSION			0x80U
/* Maximum blocks supported by I15693 specification. */
#define PHPAL_SLI15693_SW_MAX_BLOCKS							256U
/*@}*/

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
#if ((PHPALSLI15693_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALSLI15693_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup ph_Private (Private definitions)
* \ingroup phOthers
* @{
*/

/**
 * \brief Perform all kinds of Inventory commands.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryEx(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
										/** [In] defines which way of (Fast)Inventory(Page)Read is done.\n
										* \c bCmd bits are defined as follows:\n
										* \li b1 = 0 -> InventoryRead
										* \li b1 = 1 -> InventoryPageRead
										* \li b2 = 0 -> normal
										* \li b2 = 1 -> FAST */
                    VAR(uint8, ANFCRL_VAR) bCmd,
                    VAR(uint8, ANFCRL_VAR) bFlags,             /**< [In] Request flags byte. */
                    VAR(uint8, ANFCRL_VAR) bAfi,               /**< [In] Application Family Identifier. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,            /**< [In] UID mask, holding known UID bits. */
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,     /**< [In] Number of UID bits within pMask. */
                    VAR(uint8, ANFCRL_VAR) bPage_Block_No,           /**< [In] Block number of first block to read. */
                    VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks,       /**< [In] Number of blocks to read */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,             /**< [Out] Received Uid */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,       /**< [Out]  Number of received UID bytes. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,            /**< [Out]  Received data. */
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength          /**< [Out]  Number of received data bytes. */
										);


/**
* \brief Perform Inventory Read Extended mode
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phpalSli15693_Sw_InventoryExt(
                    P2VAR(phpalSli15693_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layers parameter structure. */
										/** [In] defines which way of (Fast)Inventory(Page)Read is done.\n
										* \c bOption bits are defined as follows:\n
										* \li b1 = 0 -> InventoryRead
										* \li b1 = 1 -> InventoryPageRead
										* \li b2 = 0 -> normal
										* \li b2 = 1 -> FAST */
                    VAR(uint8, ANFCRL_VAR) bCmd,
                    VAR(uint8, ANFCRL_VAR) bFlags,             /**< [In] Request flags byte. */
                    VAR(uint8, ANFCRL_VAR) bAfi,               /**< [In] Application Family Identifier. */
                    VAR(uint8, ANFCRL_VAR) bExtended,          /**< [In] Extended mode */
                    VAR(uint8, ANFCRL_VAR) bExtendedOptions,   /**< [In] Features of the extended mode */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCID,             /**< [In] Two byte CID -> if marked in extended options */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMask,            /**< [In] UID mask, holding known UID bits. */
                    VAR(uint8, ANFCRL_VAR) bMaskBitLength,     /**< [In] Number of UID bits within pMask. */
                    VAR(uint8, ANFCRL_VAR) bPage_Block_No,           /**< [In] Block number of first block to read. */
                    VAR(uint16, ANFCRL_VAR) wNoOfPages_Blocks,       /**< [In] Number of blocks to read */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCIDOut,          /**< [Out] Received CID. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid,             /**< [Out] Received Uid */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUidLength,       /**< [Out]  Number of received UID bytes. */
                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pData,            /**< [Out]  Received data. */
                    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pDataLength          /**< [Out]  Number of received data bytes. */
										);

/**
 * end of group ph_Private (Private definitions)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHPALSLI15693_SW_INT_AR_RELEASE_MAJOR_VERSION == 4) && (PHPALSLI15693_SW_INT_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHPALSLI15693_SW_INT_H */