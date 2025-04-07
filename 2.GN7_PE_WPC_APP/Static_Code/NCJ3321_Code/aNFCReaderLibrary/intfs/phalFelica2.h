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
*   @file    phalFelica2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlFelica - AL API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup phalFelica2 Felica
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
#ifndef PHALFELICA2_H
#define PHALFELICA2_H

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
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phalFelica2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALFELICA_VENDOR_ID2                    43         /**< @brief AUTOSAR vendor ID*/
#define PHALFELICA_MODULE_ID2                    255                /**< @brief AUTOSAR module ID*/
#define PHALFELICA_AR_RELEASE_MAJOR_VERSION2     4       /**< @brief AUTOSAR release major version*/
#define PHALFELICA_AR_RELEASE_MINOR_VERSION2     3       /**< @brief AUTOSAR release minor version*/
#define PHALFELICA_AR_RELEASE_REVISION_VERSION2  1       /**< @brief AUTOSAR release revision*/
#define PHALFELICA_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHALFELICA_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHALFELICA_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALFELICA_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phalFelica2.h and  CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALFELICA_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALFELICA_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalFelica2.h and  CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and  CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALFELICA_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALFELICA_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALFELICA_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalFelica2.h and  CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW2
/** \defgroup phalApplication Application Layer
* \brief Contains Application specific implementations for various contactless cards (MIFARE DESFire, MIFARE Classic, MIFARE Ultralight, FELICA and ICODE).
*/

/** \defgroup phalFelica_Sw2 Component : Software
* \ingroup phalFelica2
* @{
*/

#define PHAL_FELICA_SW_ID2   0x01U    /**< ID for Software alFelica layer */
/**
 * end of group phalFelica_Sw2 Component : Software
 * @}
 */
#endif /* NXPBUILD__PHAL_FELICA_SW2 */

#ifdef NXPBUILD__PHAL_FELICA2

/** \addtogroup phalFelica2 Felica
* \ingroup phalApplication
* \brief These Components implement the Felica commands.
* @{
*/

/**
* \name Felica constant definitions
*/
/*@{*/
#define PHAL_FELICA_CONFIG_ADD_INFO2     0x0000U     /**< Set or get the additional info word. */
/*@}*/

/**
* \name FELICA error codes
*/
/*@{*/
#define PHAL_FELICA_ERR_FELICA2  ((phStatus_t2)PH_ERR_CUSTOM_BEGIN2 + 0U) /**< General Felica error. */
/*@}*/

/**
* \name Felica max services
*/
/*@{*/
#define PHAL_FELICA_MAX_SERVICES2    121U    /**< Maximum number of services. */
/*@}*/

/**
 * end of group phalFelica2 Felica
 * @}
 */
#endif /* NXPBUILD__PHAL_FELICA2 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW2

/** \addtogroup phalFelica_Sw2 Component : Software
* \ingroup phalFelica2
* \brief These Components implement the Felica commands.
* @{
*/
typedef enum {
    PHAL_FELICA_CARD_STANDARD2 = 0,
    PHAL_FELICA_CARD_LITE2,
    PHAL_FELICA_CARD_LITE_S2,
    PHAL_FELICA_CARD_MOBILE2,
    PHAL_FELICA_CARD_PLUG2,
    PHAL_FELICA_CARD_UNKNOWN2 = 0xFF,
} FELICA_CARD_TYPE_t2;

#endif /* NXPBUILD__PHAL_FELICA_SW2 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_FELICA_SW2

/**
* \brief Private parameter structure
*/

typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId2;                   /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelicaDataParams2;    /**< Pointer to palFelica parameter structure. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymDataParams2;
    VAR(uint16, ANFCRL_VAR) wAdditionalInfo2;       /**< Holds the last error code sent by the VICC. */
    VAR(uint8, ANFCRL_VAR) bAuthenticate2;      /**< Card is authenticated or not. */
    VAR(uint8, ANFCRL_VAR) sk2[16];          /**< Session key2 for Read/Write with MAC. */
    VAR(uint8, ANFCRL_VAR) iv2[16];          /**< IV key2 for Read/Write with MAC. */
} phalFelica_Sw_DataParams_t2;

/**
 * end of group phalFelica_Sw2 Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAL_FELICA_SW2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHAL_FELICA_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phalFelica_Sw2 Component : Software
* \ingroup phalFelica2
* \brief These Components implement the Felica commands.
* @{
*/
 
/**
* \brief Initialize this layer.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Sw_Init2(
                              P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                              VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,               /**< [In] Specifies the size of the data2 parameter structure. */
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelica_DataParams2,             /**< [In] Pointer to palFelica parameter structure. */
                              P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoSymDataParams2               /**< [In] Pointer to CryptoSym parameter structure. */
                              );

/**
 * end of group phalFelica_Sw2 Component : Software
 * @}
 */
 
#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_FELICA_SW2 */

#ifdef NXPBUILD__PHAL_FELICA2

/** \addtogroup phalFelica2 Felica
* \ingroup phalApplication
* \brief These Components implement the Felica commands.
* @{
*/

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phalFelica2/src/Sw/phalFelica_Sw2.h"

#define phalFelica_RequestResponse2( pDataParams2, pMode2)\
        phalFelica_Sw_RequestResponse2((phalFelica_Sw_DataParams_t2 *)pDataParams2, pMode2)

#define phalFelica_RequestService2(pDataParams2, bTxNumServices2, pTxServiceList2, pRxNumServices2, pRxServiceList2) \
        phalFelica_Sw_RequestService2((phalFelica_Sw_DataParams_t2 *)pDataParams2, bTxNumServices2, pTxServiceList2, pRxNumServices2, pRxServiceList2)

#define phalFelica_Read2(pDataParams2, bNumServices2, pServiceList2, bTxNumBlocks2, pBlockList2, bBlockListLength2, pRxNumBlocks2, pBlockData2) \
        phalFelica_Sw_Read2((phalFelica_Sw_DataParams_t2 *)pDataParams2, bNumServices2, pServiceList2, bTxNumBlocks2, pBlockList2, bBlockListLength2, pRxNumBlocks2, pBlockData2)

#define phalFelica_Write2(pDataParams2,  bNumServices2, pServiceList2, bNumBlocks2, pBlockList2, bBlockListLength2, pBlockData2) \
        phalFelica_Sw_Write2((phalFelica_Sw_DataParams_t2 *)pDataParams2,  bNumServices2, pServiceList2, bNumBlocks2, pBlockList2, bBlockListLength2, pBlockData2)

#define phalFelica_GetConfig2( pDataParams2, wConfig2, pValue2) \
        phalFelica_Sw_GetConfig2((phalFelica_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2 )

#define phalFelica_ActivateCard2( pDataParams2, pSystemCode2, bTimeSlot2, pRxBuffer2, pRxLength2, pMoreCardsAvailable2) \
        phalFelica_Sw_ActivateCard2( (phalFelica_Sw_DataParams_t2 *)pDataParams2, pSystemCode2, bTimeSlot2, pRxBuffer2, pRxLength2, pMoreCardsAvailable2)

#define phalFelica_SearchService2(pDataParams2, serviceIndex2, pRxServiceCode2, pRxServiceCount2) \
		phalFelica_Sw_SearchService2((phalFelica_Sw_DataParams_t2*)pDataParams2, serviceIndex2, pRxServiceCode2, pRxServiceCount2)

#define phalFelica_RequestSystemCodes2(pDataParams2, pRxSystemCodes2, pRxSystemCount2) \
		phalFelica_Sw_RequestSystemCodes2((phalFelica_Sw_DataParams_t2*)pDataParams2, pRxSystemCodes2, pRxSystemCount2)

#else

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief When receiving the RequestResponse command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_RequestResponse2(
                                      P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,   /**< [In] Pointer to this layers parameter structure. */
                                      P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMode2       /**< [Out] Current Card Mode. (0, 1, 2). */
                                      );

/**
* \brief When receiving the RequestService command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_RequestService2(
                                     P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,        /**< [In] Pointer to this layers parameter structure. */
                                     VAR(uint8, ANFCRL_VAR) bTxNumServices2,   /**< [In] Number of services or areas within the command message. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxServiceList2,  /**< [In] Service code or area code list within the command message. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumServices2,  /**< [Out] Number of received services or areas. */
                                     P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceList2   /**< [Out] Received Service Key version or area version list, max 64 bytes. */
                                     );

/**
* \brief When receiving the Read command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Read2(
                           P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,          /**< [In] Pointer to this layers parameter structure. */
                           VAR(uint8, ANFCRL_VAR) bNumServices2,       /**< [In] Number of Services. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList2,      /**< [In] List of Services. */
                           VAR(uint8, ANFCRL_VAR) bTxNumBlocks2,       /**< [In] Number of Blocks to send. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList2,        /**< [In] List of Blocks to read. */
                           VAR(uint8, ANFCRL_VAR) bBlockListLength2,   /**< [In] Number of Blocks to read. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxNumBlocks2,      /**< [Out] Number of received blocks2. */
                           P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2         /**< [Out] Received Block data2. */
                           );

/**
* \brief When receiving the Write command, the VICC shall respond.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Write2(
                            P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,         /**< [In] Pointer to this layers parameter structure. */
                            VAR(uint8, ANFCRL_VAR) bNumServices2,      /**< [In] Number of Services. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pServiceList2,     /**< [In] List of Services. */
                            VAR(uint8, ANFCRL_VAR) bNumBlocks2,        /**< [In] Number of Blocks to send. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockList2,       /**< [In] List of Blocks to write. */
                            VAR(uint8, ANFCRL_VAR) bBlockListLength2,  /**< [In] Number of Blocks to write. */
                            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2        /**< [In] Block data2 to write. */
                            );

/**
* \brief Perform a GetConfig command.
*
* \c wConfig2 can be one of:\n
* \li #PHAL_FELICA_CONFIG_ADD_INFO2
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_ERR_PROTOCOL_ERROR2 Invalid response received.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_GetConfig2(
                                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2, /**< [In] Pointer to this layers parameter structure. */
                                VAR(uint16, ANFCRL_VAR) wConfig2,   /**< [In] Configuration Identifier. */
                                P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2   /**< [Out] Configuration Value. */
                                );

/**
* \brief This command activates a Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b Note: SystemCode 0xFFFF is passed to poll for all Felica Tags irrespective of the SystemCode.
*          If SystemCode is specified then only corresponding Tag will be Polled and Activated.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_ActivateCard2(
                                    void* pDataParams2,              /**< [In] Pointer to this layer's parameter structure. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSystemCode2,          /**< [In] System-Code; uint8[2]. */
                                    VAR(uint8, ANFCRL_VAR) bTimeSlot2,          /**< [In] Number of timeslots to use. Refer to e.g. #PHPAL_FELICA_NUMSLOTS_1 for valid values. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2,            /**< [Out] 8 bytes NFCID2 + 8 bytes PAD; uint8[16]. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength2,            /**< [Out] Length of received data2. 0 or 16. */
                                    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pMoreCardsAvailable2   /**< [Out] Whether there are more cards in the field or not; uint8. */
                                    );

/**
* \brief This command reads the service codes in current system code of Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_SearchService2(
                                       void* pDataParams2,          /**< [In] Pointer to this layer's parameter structure. */
                                       VAR(uint16, ANFCRL_VAR) serviceIndex2,      /**< [In] Service index to read out. */
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCode2,  /**< [Out] Area or service code. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxServiceCount2   /**< [Out] 1: service code, 2: Area. */
                                       );

/**
* \brief This command reads the system codes of Felica card.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_RequestSystemCodes2(
                                       void* pDataParams2,           /**< [In] Pointer to this layer's parameter structure. */
                                       P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCodes2,   /**< [Out] Pointer to buffer contains Felica-card System Codes. */
                                       P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxSystemCount2     /**< [Out] Number of System Codes. */
                                       );

#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

/**
 * end of group phalFelica2 Felica
 * @}
 */

#define ANFCRL_START_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/**
* \brief This function is the simple form of phalFelica_Read2 function.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b blocks2	: block2 array.
* \b blockCount2: number of block2 in array blocks2.
* \b pBlockData2	: pBlockData2 is output of data2 block2.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_ReadBlocks2(
                              P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks2,
                VAR(uint8, ANFCRL_VAR) blockCount2, /* max 8 blocks2 */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2 /* buffer 16 * blockCount2 bytes */
                              );

/**
* \brief This function is the simple form of phalFelica_Write2 function.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b blocks2	: block2 array.
* \b blockCount2: number of block2 in array blocks2.
* \b pBlockData2	: pBlockData2 is output of data2 block2.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_WriteBlocks2(
                              P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks2,
                VAR(uint8, ANFCRL_VAR) blockCount2, /* max 8 blocks2 */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2 /* buffer 16 * blockCount2 bytes */
                              );

#ifdef NXPBUILD__PH_CRYPTOSYM2
/**
* \brief This function generate MAC for Felica card.
*
* \b data2	: block2 byte data2 with size = datalen2.
* \b datalen2: datalen2 is multiple of 8 (8, 16, 24).
* \b key2    : Triple DES key2, size = 16.
* \b iv2		: iv2 length is 8.
* \b mac2	: MAC is output data2. MAC length is 8.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Generate_Mac2(
    P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) data2,
    VAR(uint8, ANFCRL_VAR) datalen2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) key2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) iv2,
    VAR(uint8, ANFCRL_VAR) flip_key2,
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) mac2);


/**
* \brief This function read a number of data2 blocks2 with integrity check.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b blocks2	: block2 array.
* \b blockCount2: number of block2 in array blocks2.
* \b pBlockData2	: pBlockData2 is output of data2 blocks2.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_ReadBlocksWithMac2(
                              P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) blocks2,
                VAR(uint8, ANFCRL_VAR) blockCount2, /* max 7 blocks2 */
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2 /* buffer 16 * blockCount2 bytes */
                              );

/**
* \brief This function write one data2 block2 with additional integrity check.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b block2	: a block2 value.
* \b pBlockData2	: pBlockData2 is output of data2 block2.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_WriteBlockWithMac2(
                              P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
                VAR(uint8, ANFCRL_VAR) block2,
                              P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pBlockData2 /* buffer 16 bytes */
                              );

/**
* \brief This command protect Felica card (for FelicaLite and FelicaLite-S only) by Memory configuration block2 (MC) to read only (RO) or by password.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b pPassword2	: block2 byte data2 with size = bPassLength2.
* \b bPassLength2: bPassLength2 >= 16.
* \b bProtectOptions2: the value is combined from one of options below:
* 		 1: Read After Authentication Protect for FeliCa Lite-S only;
* 		 2: write protect system blocks2 82,83,84,86,87;
* 		 4: Read only protect.
* 		 8: Protect write with MAC.
* \b bFromBlock2	: bFromBlock2 from 0 to 13.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Protect2(
    P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword2,
    VAR(uint8, ANFCRL_VAR) bPassLength2,
    VAR(uint8, ANFCRL_VAR) bProtectOptions2,
    VAR(uint8, ANFCRL_VAR) bFromBlock2
		);

/**
* \brief This command Authenticate Felica card (for FelicaLite and FelicaLite-S only).
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
*
* \b pPassword2	: block2 byte data2 with size = bPassLength2.
* \b bPassLength2: bPassLength2 >= 16.
* \return Status code
* \retval #PH_ERR_SUCCESS2 Operation successful.
* \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
* \retval Other Depending on implementation and underlying component.
*/
FUNC(phStatus_t2, ANFCRL_CODE) phalFelica_Authenticate2(
    P2VAR(phalFelica_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPassword2, /* length >= 16 */
    VAR(uint8, ANFCRL_VAR) bPassLength2
		);

#endif /* NXPBUILD__PH_CRYPTOSYM2 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALFELICA_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHALFELICA_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif
#endif /* NXPBUILD__PHAL_FELICA2 */

#ifdef __cplusplus
}  /* Extern C */
#endif /* __cplusplus */

#endif /* PHALFELICA2_H */

