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
*   @file    phalFelica.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlFelica - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalFelica Felica
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
#ifndef PHALFELICA_H
#define PHALFELICA_H

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
* @file           phalFelica.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALFELICA_VENDOR_ID                    43         /**< @brief AUTOSAR vendor ID*/
#define PHALFELICA_MODULE_ID                    255                /**< @brief AUTOSAR module ID*/
#define PHALFELICA_AR_RELEASE_MAJOR_VERSION     4       /**< @brief AUTOSAR release major version*/
#define PHALFELICA_AR_RELEASE_MINOR_VERSION     3       /**< @brief AUTOSAR release minor version*/
#define PHALFELICA_AR_RELEASE_REVISION_VERSION  1       /**< @brief AUTOSAR release revision*/
#define PHALFELICA_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALFELICA_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALFELICA_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALFELICA_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalFelica.h and  CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALFELICA_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALFELICA_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalFelica.h and  CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALFELICA_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALFELICA_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALFELICA_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalFelica.h and  CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW
/** \defgroup phalApplication Application Layer
* \brief Contains Application specific implementations for various contactless cards (MIFARE DESFire, MIFARE Classic, MIFARE Ultralight, FELICA and ICODE).
*/

/** \defgroup phalFelica_Sw Component : Software
* \ingroup phalFelica
* @{
*/

#define PHAL_FELICA_SW_ID   0x01U    /**< ID for Software alFelica layer */
/**
 * end of group phalFelica_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHAL_FELICA_SW */

#ifdef NXPBUILD__PHAL_FELICA

/** \addtogroup phalFelica Felica
* \ingroup phalApplication
* \brief These Components implement the Felica commands.
* @{
*/

/**
* \name Felica constant definitions
*/
/*@{*/
#define PHAL_FELICA_CONFIG_ADD_INFO     0x0000U     /**< Set or get the additional info word. */
/*@}*/

/**
* \name FELICA error codes
*/
/*@{*/
#define PHAL_FELICA_ERR_FELICA  ((phStatus_t)PH_ERR_CUSTOM_BEGIN + 0U) /**< General Felica error. */
/*@}*/

/**
* \name Felica max services
*/
/*@{*/
#define PHAL_FELICA_MAX_SERVICES    121U    /**< Maximum number of services. */
/*@}*/

/**
 * end of group phalFelica Felica
 * @}
 */
#endif /* NXPBUILD__PHAL_FELICA */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW

/** \addtogroup phalFelica_Sw Component : Software
* \ingroup phalFelica
* \brief These Components implement the Felica commands.
* @{
*/
typedef enum {
    PHAL_FELICA_CARD_STANDARD = 0,
    PHAL_FELICA_CARD_LITE,
    PHAL_FELICA_CARD_LITE_S,
    PHAL_FELICA_CARD_MOBILE,
    PHAL_FELICA_CARD_PLUG,
    PHAL_FELICA_CARD_UNKNOWN = 0xFF,
} FELICA_CARD_TYPE_t;

#endif /* NXPBUILD__PHAL_FELICA_SW */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW

/**
* \brief Private parameter structure
*/

typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                   /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelicaDataParams;    /**< Pointer to palFelica parameter structure. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymDataParams;
    VAR(uint16, ANFCRL_VAR) wAdditionalInfo;       /**< Holds the last error code sent by the VICC. */
    VAR(uint8, ANFCRL_VAR) bAuthenticate;      /**< Card is authenticated or not. */
    VAR(uint8, ANFCRL_VAR) sk[16];          /**< Session key for Read/Write with MAC. */
    VAR(uint8, ANFCRL_VAR) iv[16];          /**< IV key for Read/Write with MAC. */
} phalFelica_Sw_DataParams_t;

/**
 * end of group phalFelica_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_FELICA_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHAL_FELICA_SW

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phalFelica_Sw Component : Software
* \ingroup phalFelica
* \brief These Components implement the Felica commands.
* @{
*/
 
/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Sw_Init(
                              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,               /**< [In] Specifies the size of the data parameter structure. */
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelica_DataParams,             /**< [In] Pointer to palFelica parameter structure. */
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymDataParams               /**< [In] Pointer to CryptoSym parameter structure. */
                              );

/**
 * end of group phalFelica_Sw Component : Software
 * @}
 */
 
#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_FELICA_SW */

#ifdef NXPBUILD__PHAL_FELICA

/** \addtogroup phalFelica Felica
* \ingroup phalApplication
* \brief These Components implement the Felica commands.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS
#include "../comps/phalFelica/src/Sw/phalFelica_Sw.h"

#define phalFelica_RequestResponse( pDataParams, pMode)\
        phalFelica_Sw_RequestResponse((phalFelica_Sw_DataParams_t *)pDataParams, pMode)

#define phalFelica_RequestService(pDataParams, bTxNumServices, pTxServiceList, pRxNumServices, pRxServiceList) \
        phalFelica_Sw_RequestService((phalFelica_Sw_DataParams_t *)pDataParams, bTxNumServices, pTxServiceList, pRxNumServices, pRxServiceList)

#define phalFelica_Read(pDataParams, bNumServices, pServiceList, bTxNumBlocks, pBlockList, bBlockListLength, pRxNumBlocks, pBlockData) \
        phalFelica_Sw_Read((phalFelica_Sw_DataParams_t *)pDataParams, bNumServices, pServiceList, bTxNumBlocks, pBlockList, bBlockListLength, pRxNumBlocks, pBlockData)

#define phalFelica_Write(pDataParams,  bNumServices, pServiceList, bNumBlocks, pBlockList, bBlockListLength, pBlockData) \
        phalFelica_Sw_Write((phalFelica_Sw_DataParams_t *)pDataParams,  bNumServices, pServiceList, bNumBlocks, pBlockList, bBlockListLength, pBlockData)

#define phalFelica_GetConfig( pDataParams, wConfig, pValue) \
        phalFelica_Sw_GetConfig((phalFelica_Sw_DataParams_t *)pDataParams, wConfig, pValue )

#define phalFelica_ActivateCard( pDataParams, pSystemCode, bTimeSlot, pRxBuffer, pRxLength, pMoreCardsAvailable) \
        phalFelica_Sw_ActivateCard( (phalFelica_Sw_DataParams_t *)pDataParams, pSystemCode, bTimeSlot, pRxBuffer, pRxLength, pMoreCardsAvailable)

#define phalFelica_SearchService(pDataParams, serviceIndex, pRxServiceCode, pRxServiceCount) \
		phalFelica_Sw_SearchService((phalFelica_Sw_DataParams_t*)pDataParams, serviceIndex, pRxServiceCode, pRxServiceCount)

#define phalFelica_RequestSystemCodes(pDataParams, pRxSystemCodes, pRxSystemCount) \
		phalFelica_Sw_RequestSystemCodes((phalFelica_Sw_DataParams_t*)pDataParams, pRxSystemCodes, pRxSystemCount)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief When receiving the RequestResponse command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestResponse(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMode       /**< [Out] Current Card Mode. (0, 1, 2). */
                                      );

/**
* \brief When receiving the RequestService command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestService(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,        /**< [In] Pointer to this layers parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bTxNumServices,   /**< [In] Number of services or areas within the command message. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxServiceList,  /**< [In] Service code or area code list within the command message. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumServices,  /**< [Out] Number of received services or areas. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceList   /**< [Out] Received Service Key version or area version list, max 64 bytes. */
                                     );

/**
* \brief When receiving the Read command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Read(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,          /**< [In] Pointer to this layers parameter structure. */
                           VAR(uint8, ANFCRL_VAR) bNumServices,       /**< [In] Number of Services. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,      /**< [In] List of Services. */
                           VAR(uint8, ANFCRL_VAR) bTxNumBlocks,       /**< [In] Number of Blocks to send. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,        /**< [In] List of Blocks to read. */
                           VAR(uint8, ANFCRL_VAR) bBlockListLength,   /**< [In] Number of Blocks to read. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumBlocks,      /**< [Out] Number of received blocks. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData         /**< [Out] Received Block data. */
                           );

/**
* \brief When receiving the Write command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Write(
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,         /**< [In] Pointer to this layers parameter structure. */
                            VAR(uint8, ANFCRL_VAR) bNumServices,      /**< [In] Number of Services. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList,     /**< [In] List of Services. */
                            VAR(uint8, ANFCRL_VAR) bNumBlocks,        /**< [In] Number of Blocks to send. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList,       /**< [In] List of Blocks to write. */
                            VAR(uint8, ANFCRL_VAR) bBlockListLength,  /**< [In] Number of Blocks to write. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData        /**< [In] Block data to write. */
                            );

/**
* \brief Perform a GetConfig command.
*
* \c wConfig can be one of:\n
* \li #PHAL_FELICA_CONFIG_ADD_INFO
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_GetConfig(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layers parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig,   /**< [In] Configuration Identifier. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue   /**< [Out] Configuration Value. */
                                );

/**
* \brief This command activates a Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b Note: SystemCode 0xFFFF is passed to poll for all Felica Tags irrespective of the SystemCode.
*          If SystemCode is specified then only corresponding Tag will be Polled and Activated.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ActivateCard(
                                    void* pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode,          /**< [In] System-Code; uint8[2]. */
                                    VAR(uint8, ANFCRL_VAR) bTimeSlot,          /**< [In] Number of timeslots to use. Refer to e.g. #PHPAL_FELICA_NUMSLOTS_1 for valid values. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,            /**< [Out] 8 bytes NFCID2 + 8 bytes PAD; uint8[16]. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,            /**< [Out] Length of received data. 0 or 16. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable   /**< [Out] Whether there are more cards in the field or not; uint8. */
                                    );

/**
* \brief This command reads the service codes in current system code of Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_SearchService(
                                       void* pDataParams,          /**< [In] Pointer to this layer's parameter structure. */
                                       VAR(uint16, ANFCRL_VAR) serviceIndex,      /**< [In] Service index to read out. */
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCode,  /**< [Out] Area or service code. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCount   /**< [Out] 1: service code, 2: Area. */
                                       );

/**
* \brief This command reads the system codes of Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_RequestSystemCodes(
                                       void* pDataParams,           /**< [In] Pointer to this layer's parameter structure. */
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCodes,   /**< [Out] Pointer to buffer contains Felica-card System Codes. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCount     /**< [Out] Number of System Codes. */
                                       );

#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS */

/**
 * end of group phalFelica Felica
 * @}
 */

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief This function is the simple form of phalFelica_Read function.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b blocks	: block array.
* \b blockCount: number of block in array blocks.
* \b pBlockData	: pBlockData is output of data block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ReadBlocks(
                              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 8 blocks */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes */
                              );

/**
* \brief This function is the simple form of phalFelica_Write function.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b blocks	: block array.
* \b blockCount: number of block in array blocks.
* \b pBlockData	: pBlockData is output of data block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_WriteBlocks(
                              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 8 blocks */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes */
                              );

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
* \brief This function generate MAC for Felica card.
*
* \b data	: block byte data with size = datalen.
* \b datalen: datalen is multiple of 8 (8, 16, 24).
* \b key    : Triple DES key, size = 16.
* \b iv		: iv length is 8.
* \b mac	: MAC is output data. MAC length is 8.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Generate_Mac(
    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) data,
    VAR(uint8, ANFCRL_VAR) datalen,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) key,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) iv,
    VAR(uint8, ANFCRL_VAR) flip_key,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) mac);


/**
* \brief This function read a number of data blocks with integrity check.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b blocks	: block array.
* \b blockCount: number of block in array blocks.
* \b pBlockData	: pBlockData is output of data blocks.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_ReadBlocksWithMac(
                              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks,
                VAR(uint8, ANFCRL_VAR) blockCount, /* max 7 blocks */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 * blockCount bytes */
                              );

/**
* \brief This function write one data block with additional integrity check.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b block	: a block value.
* \b pBlockData	: pBlockData is output of data block.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_WriteBlockWithMac(
                              P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
                VAR(uint8, ANFCRL_VAR) block,
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData /* buffer 16 bytes */
                              );

/**
* \brief This command protect Felica card (for FelicaLite and FelicaLite-S only) by Memory configuration block (MC) to read only (RO) or by password.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b pPassword	: block byte data with size = bPassLength.
* \b bPassLength: bPassLength >= 16.
* \b bProtectOptions: the value is combined from one of options below:
* 		 1: Read After Authentication Protect for FeliCa Lite-S only;
* 		 2: write protect system blocks 82,83,84,86,87;
* 		 4: Read only protect.
* 		 8: Protect write with MAC.
* \b bFromBlock	: bFromBlock from 0 to 13.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Protect(
    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword,
    VAR(uint8, ANFCRL_VAR) bPassLength,
    VAR(uint8, ANFCRL_VAR) bProtectOptions,
    VAR(uint8, ANFCRL_VAR) bFromBlock
		);

/**
* \brief This command Authenticate Felica card (for FelicaLite and FelicaLite-S only).
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* \b pPassword	: block byte data with size = bPassLength.
* \b bPassLength: bPassLength >= 16.
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t, ANFCRL_CODE) phalFelica_Authenticate(
    P2VAR(phalFelica_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword, /* length >= 16 */
    VAR(uint8, ANFCRL_VAR) bPassLength
		);

#endif /* NXPBUILD__PH_CRYPTOSYM */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHAL_FELICA */

#ifdef __cplusplus
}  /* Extern C */
#endif /* __cplusplus */

#endif /* PHALFELICA_H */

