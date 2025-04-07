/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2022
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
*   @file    phalVca.h
*   @version 1.0.0
*
*   @brief   AUTOSAR AlVca - AL API usage in common use cases.
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

#ifndef PHALVCA_H
#define PHALVCA_H

#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include <ph_Status.h>
#include "phhalHw.h"
#include "phpalMifare.h"
#include <CDD_AnfcRL_Cfg.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/

/**
* @file           phalVca.h
* @implements     DESIGN001, DESIGN002
*/
#define PHALVCA_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHALVCA_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHALVCA_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHALVCA_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHALVCA_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHALVCA_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHALVCA_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHALVCA_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHALVCA_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phalVca.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION   != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHALVCA_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHALVCA_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phalVca.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHALVCA_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHALVCA_SW_MINOR_VERSION  != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHALVCA_SW_PATCH_VERSION  != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phalVca.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA_SW
/**
 * \defgroup phalVca_Sw Component : Software
 * \ingroup phalVca
 * \brief Ncx3320 Virtual Card Architecture (R) component 
 * @{
 */
#define PHAL_VCA_SW_ID                                              0x01U    /**< ID for Software Virtual Card Architecture layer. */
/**
 * end of group phalVca_Sw Component : Software
 * @}
 */
#endif /*NXPBUILD__PHAL_VCA_SW*/

/** \defgroup phalVca Virtual Card Architecture (R)
 * \ingroup phcommon
 * \brief These Components implement the Virtual Card Architecture (R) commands.
 * @{
 */


/**
 * \defgroup phalVca_PC Proximity Check commands
 * \brief These Components implement the Virtual Card Architecture (R) commands for Proximity Check feature.
 * @{
 */
#ifdef NXPBUILD__PH_CRYPTOSYM
/**
* \name Option to be used for ProximityCheckNew command. 
*/
/*@{*/
#define PHAL_VCA_PC_RNDC_PROVIDED                                   0x00    /**< Option mask to indicate the Random number C is given by the user. */
#define PHAL_VCA_PC_RNDC_GENERATE                                   0x01    /**< Option mask to indicate the Random number C to be generated by the library. */
#define PHAL_VCA_PC_NORMAL_PROCESSING                               0x00    /**< Option mask to indicate VerifyProcessing should be Normal. */
#define PHAL_VCA_PC_RANDOM_PROCESSING                               0x02    /**< Option mask to indicate VerifyProcessing should be Random. */
/*@}*/
#endif /*NXPBUILD__PH_CRYPTOSYM*/
/**
 * end of group phalVca_PC
 * @}
 */
 
#ifdef NXPBUILD__PHAL_VCA
/**
* \name Custom Error Codes 
*/
/*@{*/
#define PHAL_VCA_ERR_CMD_INVALID                (PH_ERR_CUSTOM_BEGIN + 0U)  /**< VCA Invalid Command Error. */
#define PHAL_VCA_ERR_FORMAT                     (PH_ERR_CUSTOM_BEGIN + 1U)  /**< VCA Format Error. */
#define PHAL_VCA_ERR_AUTH                       (PH_ERR_CUSTOM_BEGIN + 2U)  /**< VCA MAC Error. */
#define PHAL_VCA_ERR_GEN                        (PH_ERR_CUSTOM_BEGIN + 3U)  /**< VCA GEN Error. */
#define PHAL_VCA_ERR_CMD_OVERFLOW               (PH_ERR_CUSTOM_BEGIN + 4U)  /**< VCA CMD Overflow Error. */
#define PHAL_VCA_ERR_COMMAND_ABORTED            (PH_ERR_CUSTOM_BEGIN + 5U)  /**< VCA Command Abort Error. */
#define PHAL_VCA_ERR_7816_GEN_ERROR             (PH_ERR_CUSTOM_BEGIN + 6U)  /**< VCA ISO 7816 Generic error. Check Additional Info. */
/*@}*/
#endif /*NXPBUILD__PHAL_VCA*/

/**
 * \defgroup phalVca_VC Virtual Card commands
 * \brief These Components implement the Virtual Card Architecture (R) commands for Virtual Card feature.
 * @{
 */
#ifdef NXPBUILD__PH_CRYPTOSYM
/**
* \name Option to be used for ISOSelect command when called for SAM X or S configuration. 
*/
/*@{*/
#define PHAL_VCA_ISO_SELECT_SELECTION_DF_NAME                       0x04    /**< Option mask to indicate the selection control as DFName. */
#define PHAL_VCA_ISO_SELECT_FCI_RETURNED                            0x00    /**< Option mask to indicate the return of FCI information. */
#define PHAL_VCA_ISO_SELECT_VARIANT_PART1                           0x00    /**< Option mask for complete VC selection in 1 part. */
#define PHAL_VCA_ISO_SELECT_VARIANT_PART2                           0x08    /**< Option mask for complete VC selection in 2 part. */
#define PHAL_VCA_ISO_SELECT_DIV_DISABLED                            0x00    /**< Default option mask to disable the diversification of VcSelect MAC or ENC key. */
#define PHAL_VCA_ISO_SELECT_ENC_KEY_DIV_INPUT                       0x01    /**< Option mask to perform diversification of VC SelectENC key using the diversification input provided. */
#define PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_INPUT                       0x02    /**< Option mask to perform diversification of VC SelectMAC key using the diversification input provided. */
#define PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_VCUID                       0x04    /**< Option mask to perform diversification of VC SelectMAC key using Virtual Card Identifier. */
#define PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_INPUT_VCUID                 0x06    /**< Option mask to perform diversification of VC SelectMAC key using Virtual Card Identifier*/
/*@}*/
#endif /*NXPBUILD__PH_CRYPTOSYM*/
/**
 * end of group phalVca_VC Virtual Card commands
 * @}
 */

/**
 * \defgroup phalVca_Utilities Utility
 * \brief These Components implement the Virtual Card Architecture (R) commands.
 * @{
 */
#ifdef NXPBUILD__PHAL_VCA
/**
* \name Option to configure some special operations 
*/
/*@{*/
#define PHAL_VCA_ADDITIONAL_INFO                                    0x0001  /**< Option for GetConfig / SetConfig to get / set additional info of a generic error. */
#define PHAL_VCA_WRAPPED_MODE                                       0x0002  /**< Option for GetConfig / SetConfig to get / set Wrapped mode. */
#define PHAL_VCA_TIMING_MODE                                        0x0003  /**< Option for GetConfig / SetConfig to get / set Timing measurements ON/OFF. */
#define PHAL_VCA_PC_LOWER_THRESHOLD                                 0x0004  /**< Option for GetConfig / SetConfig to Enable / Disable lower boundary(-20%) on threshold time. */
#define PHAL_VCA_PC_EXTENDED_APDU                                   0x0005  /**< Option for GetConfig / SetConfig to get / set current status of extended wrapping in ISO 7816-4 APDUs. */
/*@}*/
#endif /* NXPBUILD__PHAL_VCA */
/**
 * end of group phalVca_Utilities Utility
 * @}
 */


/**
 * end of group phalVca Virtual Card Architecture (R)
 * @}
 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA_SW
/**
 * \addtogroup phalVca_Sw Component : Software
 * \ingroup phalVca
 * \brief Ncx3320 Virtual Card Architecture (R) component 
 * @{
 */
/** \brief Enum defining VC states */
typedef enum
{
    VC_NOT_SELECTED                                                 = 0x00U, /**< State to indicate no VC selection. */
    VC_PROXIMITYFAILED                                              = 0x01U, /**< State to indicate Proximity Check Failure. */
    VC_PROXIMITYCHECK                                               = 0x02U, /**< State to indicate Proximity Check. */
    VC_DF_NOT_AUTH                                                  = 0x03U, /**< State to indicate DESFire PICC in not authenticated. */
    VC_DF_AUTH_D40                                                  = 0x04U, /**< State to indicate DESFire PICC in D40 authenticated. */
    VC_DF_AUTH_ISO                                                  = 0x05U, /**< State to indicate DESFire PICC in ISO authenticated. */
    VC_DF_AUTH_EV2                                                  = 0x06U, /**< State to indicate DESFire PICC in EV2 Authenticated. */
    VC_DF_AUTH_AES                                                  = 0x07U, /**< State to indicate DESFire PICC in AES Authenticated. */
    VC_MFP_AUTH_AES_SL1                                             = 0x08U, /**< State to indicate MIFARE Plus contactless IC PICC authenticated in Security Level 1. */
    VC_MFP_AUTH_AES_SL3                                             = 0x09U  /**< State to indicate MIFARE Plus PICC authenticated in Security Level 3. */
}phalVca_VirtualCardState;

/** \brief Enum defining PC states */
typedef enum
{
    PC_NO_PCHK_IN_PROGRESS                                          = 0x00U, /**< State to indicate there is no Proximity check in progress. */
    PC_PPC_IN_PROGRESS                                              = 0x01U, /**< State to indicate Proximity check preparation is in progress. */
    PC_PCHK_PREPARED                                                = 0x02U, /**< State to indicate Proximity check is prepared. */
    PC_PCHK_IN_PROGRESS                                             = 0x03U, /**< State to indicate Proximity check is in progress. */
    PC_WAITING_PC_VERIFICATION                                      = 0x04U, /**< State to indicate waiting of Proximity check verification . */
    PC_VPC_IN_PROGRESS                                              = 0x05U  /**< State to indicate Proximity check verification is in progress. */
}phalVca_ProximityCheckState;
/**
 * end of group phalVca_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHAL_VCA_SW */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA_SW
/**
 * \addtogroup phalVca_Sw Component : Software
 * \ingroup phalVca
 * \brief Ncx3320 Virtual Card Architecture (R) component 
 * @{
 */
/** \brief Structure for Card table */
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wIidIndex;                                                     /**< Index of the associated IID. */
    VAR(uint8, ANFCRL_VAR) bValid;                                                         /**< Indicates if an entry is valid or not */
    VAR(uint8, ANFCRL_VAR) pCardData[16];                                                  /**< Card Data received from the Card. */
} phalVca_Sw_CardTableEntry_t;

/** \brief Structure for IID table */
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wIidIndex;                                                     /**< Index of the associated IID. */
    VAR(uint16, ANFCRL_VAR) wKeyEncNumber;                                                 /**< Key number for Encryption key. */
    VAR(uint16, ANFCRL_VAR) wKeyEncVersion;                                                /**< Key version for Encryption key. */
    VAR(uint16, ANFCRL_VAR) wKeyMacNumber;                                                 /**< Key number for MAC key. */
    VAR(uint16, ANFCRL_VAR) wKeyMacVersion;                                                /**< Key version for MAC key. */
} phalVca_Sw_IidTableEntry_t;
/** \brief VCA Software parameter structure */
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                                            /**< Layer ID for this component, NEVER MODIFY! */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams;                          /**< Pointer to the parameter structure of the palMifare component. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                           /**< Pointer to the parameter structure of the KeyStore layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams;                             /**< Pointer to the parameter structure of the Crypto layer. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams;                          /**< Pointer to the parameter structure of the CryptoRng layer. */
    P2VAR(phalVca_Sw_CardTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pCardTable;             /**< Pointer to the Card Table of the layer. */
    P2VAR(phalVca_Sw_IidTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pIidTable;               /**< Pointer to the Iid Table of the layer. */
    VAR(uint16, ANFCRL_VAR) wCurrentCardTablePos;                                           /**< Position of current entry in the CardTable. */
    VAR(uint16, ANFCRL_VAR) wNumCardTableEntries;                                           /**< Number of Card table entries in the table. */
    VAR(uint16, ANFCRL_VAR) wNumIidTableEntries;                                            /**< Number of Iid table entries in the table. */
    VAR(uint16, ANFCRL_VAR) wCurrentIidIndex;                                               /**< Current index of the Iid sequence. */
    VAR(uint16, ANFCRL_VAR) wCurrentIidTablePos;                                            /**< Position of current entry in the Iid Table. */
    VAR(uint16, ANFCRL_VAR) wAdditionalInfo;                                                /**< Specific error codes for VC generic errors. */
    VAR(uint8, ANFCRL_VAR) bSessionAuthMACKey[16];                                        	/**< Session Keys for Authentication of MAC. */
    VAR(phalVca_VirtualCardState, ANFCRL_VAR) eVCState;                                     /**< Enum variable holding Virtual Card state. */
    VAR(phalVca_ProximityCheckState, ANFCRL_VAR) ePCState;                                  /**< Enum Variable holding Proximity Check state. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlDataParams;                                 /**< Pointer to the parameter structure of the MFDF EVx / MFP EVx component. */
    VAR(uint8, ANFCRL_VAR) bWrappedMode;                                                   	/**< Wrapped APDU mode. All native commands need to be sent wrapped in ISO 7816 APDUs. */
    VAR(uint8, ANFCRL_VAR) bExtendedLenApdu;                                              	/**< Extended length APDU. If set the native commands should be wrapped in extended format */
    VAR(uint8, ANFCRL_VAR) bOption; 														/**< bOption parameter for Timing measurements ON/OFF. */
    VAR(uint8, ANFCRL_VAR) bLowerBoundThreshold;                                          	/**< parameter for enable/disable the LowerBound threshold time calculation(-20%). */
} phalVca_Sw_DataParams_t;
/**
 * end of group phalVca_Sw Component : Software
 * @}
 */
#endif /* NXPBUILD__PHAL_VCA_SW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHAL_VCA_SW

#define ANFCRL_START_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/**
 * \addtogroup phalVca_Sw Component : Software
 * \ingroup phalVca
 * \brief Ncx3320 Virtual Card Architecture (R) component 
 * @{
 */
/**
 * \brief Initialization API for AL VCA / PC to communicate with direct reader and PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */

FUNC(phStatus_t, ANFCRL_CODE) phalVca_Sw_Init(
        P2VAR(phalVca_Sw_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                              /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                                         /**< [In] Specifies the size of the data parameter structure. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalMifareDataParams,                                        /**< [In] Pointer to the parameter structure of the palMifare layer. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,                                         /**< [In] Pointer to the parameter structure of the keyStore layer. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoDataParams,                                           /**< [In] Pointer to the parameter structure of the Crypto layer. */
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pCryptoRngDataParams,                                        /**< [In] Pointer to the parameter structure of the CryptoRng layer. */
        P2VAR(phalVca_Sw_IidTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pIidTableStorage,                      /**< [In] Pointer to the Iid Table storage for the layer. */
        VAR(uint16, ANFCRL_VAR) wNumIidTableStorageEntries,                                /**< [In] Number of possible Iid table entries in the storage. */
        P2VAR(phalVca_Sw_CardTableEntry_t, AUTOMATIC, ANFCRL_APPL_DATA) pCardTableStorage,                    /**< [In] Pointer to the Card Table storage for the layer. */
        VAR(uint16, ANFCRL_VAR) wNumCardTableStorageEntries                                /**< [In] Number of possible Card table entries in the storage. */
    );

/**
 * end of group phalVca_Sw Component : Software
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_VCA_SW */



#ifdef NXPBUILD__PHAL_VCA

#define ANFCRL_START_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phalVca Virtual Card Architecture (R)
 * \ingroup phcommon
 * \brief These Components implement the Virtual Card Architecture (R) commands.
 * @{
 */
/**
 * \addtogroup phalVca_VC Virtual Card commands
 * \brief These Components implement the Virtual Card Architecture (R) commands for Virtual Card feature.
 * @{
 */

/**
 * \brief Start Card Selection.
 * This command is used to start a VCS / VCSL sequence.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_StartCardSelection(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                      /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Finalize Card Selection.
 *
 * This command is used to finalize a VCS/VCSL sequence. The number of successfully detected IIDs is returned
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_FinalizeCardSelection(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pNumValidIids                                            /**< [Out] Number of valid IIDs detected during VCS/VCSL sequence execution. */
    );

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
 * \brief Performs a Select Virtual Card command (MIFARE Plus only).
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_SelectVc(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wValidIidIndex,                                            /**< [In] Index of valid IID, needs to be < pNumValidIids in FinalizeCardSelection call. */
        VAR(uint16, ANFCRL_VAR) wKeyNumber,                                                /**< [In] Key number of the MAC key used in SVC command. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion                                                /**< [In] Key version of the MAC key used in SVC command. */
    );
#endif /* NXPBUILD__PH_CRYPTOSYM */

/**
 * \brief Performs a Deselect Virtual Card command.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_DeselectVc(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams                                                  /**< [In] Pointer to this layer's parameter structure. */
    );

/**
 * \brief Performs a Virtual Card Support command (MIFARE Plus only).
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_VcSupport(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid,                                                     /**< [In] Installation Identifier (16 bytes). */
        VAR(uint16, ANFCRL_VAR) wKeyEncNumber,                                             /**< [In] Key number of the ENC key associated to the Iid. */
        VAR(uint16, ANFCRL_VAR) wKeyEncVersion,                                            /**< [In] Key version of the ENC key associated to the Iid. */
        VAR(uint16, ANFCRL_VAR) wKeyMacNumber,                                             /**< [In] Key number of the MAC key associated to the Iid. */
        VAR(uint16, ANFCRL_VAR) wKeyMacVersion                                             /**< [In] Key version of the MAC key associated to the Iid. */
    );

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
 * \brief Perform a Virtual Card Support (Last) command. This command performs the Virtual card support command in
 * ISO14443 Layer 3 activated state. This command is supported by MIFARE Ultralight EV1 contactless IC and Mifare Plus product only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_VcSupportLast(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIid,                                                     /**< [In] Installation Identifier (16 bytes). */
        VAR(uint8, ANFCRL_VAR) bLenCap,                                                    /**< [In] Length of the PCD caps (0-6). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPcdCapabilities,                                         /**< [In] PCD Capabilities (bLenCap bytes), ignored if bLenCap == 0. */
        VAR(uint16, ANFCRL_VAR) wKeyEncNumber,                                             /**< [In] Key number of the ENC key used in VCSL command. */
        VAR(uint16, ANFCRL_VAR) wKeyEncVersion,                                            /**< [In] Key version of the ENC key used in VCSL command. */
        VAR(uint16, ANFCRL_VAR) wKeyMacNumber,                                             /**< [In] Key number of the MAC key used in VCSL command. */
        VAR(uint16, ANFCRL_VAR) wKeyMacVersion                                             /**< [In] Key version of the MAC key used in VCSL command. */
    );
#endif /* NXPBUILD__PH_CRYPTOSYM */

/**
 * \brief Retrieve card information.
 * This command retrieves card information like UID and Info byte and the associated IID
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_GetIidInfo(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,               /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wValidIidIndex,                             /**< [In] Index of valid IID, needs to be < pNumValidIids in FinalizeCardSelection call. */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pIidIndex,               /**< [Out] Corresponding IID to the key pair where the MAC was matching in VCSL command call. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUidSize,               /**< [Out] Size of the VC UID (4 or 7 bytes). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVcUid, 					/**< [Out] VC UID (pVcUidSize bytes). */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInfo,                    /**< [Out] Info byte. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPdCapabilities           /**< [Out] PD Capabilities (2 bytes). */
    );

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
 * \brief PCD explicitly indicates which Virtual Card it wants to target by issuing this command.
 * Both PCD and the PD agree on which VC to use (if any) and they negotiate the capabilities that
 * they will use. This command is supported by MIFARE DESFire EV1 contactless IC, MIFARE DESFire EV2 contactless IC and MIFARE Plus EV1 contactless IC only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS on Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_IsoSelect(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                              /**< [In] Pointer to this layer's parameter structure which is of type phalVca_Sw_DataParams_t. */
        VAR(uint8, ANFCRL_VAR) bSelectionControl,                                        /**< [In] Value equals #PHAL_VCA_ISO_SELECT_SELECTION_DF_NAME which indicates VC Selection by DF name.
                                                                             *        Any other value results in PH_ERR_INVALID_PARAMETER.\n
                                                                             *
                                                                             *        Note: This parameter will be used for Software and Sam S mode only.
                                                                             *              For Sam X mode it can be neglected.
                                                                             */
        VAR(uint8, ANFCRL_VAR) bOption,                                                  /**< [In] Value equals #PHAL_VCA_ISO_SELECT_FCI_RETURNED which indicates FCI template is returned.
                                                                             *        Any other value results in PH_ERR_INVALID_PARAMETER.\n
                                                                             *        Note: This value will be used for Software mode only.\n\n
                                                                             *
                                                                             *         Sam S or X communication, The macros can be combined by oring.
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_DIV_DISABLED
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_ENC_KEY_DIV_INPUT
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_INPUT
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_VCUID
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_MAC_KEY_DIV_INPUT_VCUID
                                                                             *        \n
                                                                             *        The below ones are valid for Sam X only. To be used with the above ones.
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_VARIANT_PART1
                                                                             *          \arg #PHAL_VCA_ISO_SELECT_VARIANT_PART2
                                                                             */
        VAR(uint8, ANFCRL_VAR) bDFnameLen,                                               /**< [In] Length of the IID which is nothing but DFName string provided by the user. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDFname,                                                  /**< [In] This is the IID which is DFName string upto 16 Bytes. Valid only when bSelectionControl = 0x04. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                /**< [IN] Key diversification input. This is used for SAM Key diversification */
        VAR(uint8, ANFCRL_VAR) bDivInputLen,                                             /**< [IN] Key diversification input Length. */
        VAR(uint8, ANFCRL_VAR) bEncKeyNo,                                                /**< [IN] ENC Key number in Software or SAM keystore. */
        VAR(uint8, ANFCRL_VAR) bEncKeyVer,                                               /**< [IN] ENC Key version in Software or SAM keystore. */
        VAR(uint8, ANFCRL_VAR) bMacKeyNo,                                                /**< [IN] MAC Key number in Software or SAM keystore. */
        VAR(uint8, ANFCRL_VAR) bMacKeyVer,                                               /**< [IN] MAC Key version in Software or SAM keystore. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,                                                /**< [Out] Response as mentioned below. \n
                                                                             *          \c Software: Response received from PICC. \n
                                                                             *          \c SAM S   : 8 bytes MAC which should be used for ISOExternalAuthenticate +
                                                                             *                       Decrypted Virtual Card Data. (or) FileIdentifier
                                                                             *          \c SAM X   : Virtual Card Data or FCI.
                                                                             */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen                                                  /**< [Out] Response received from the PICC. */
    );

/**
 * \brief Depending on the VC configuration, the PCD might be required to subsequently (after IsoSelect execution)
 * authenticate itself via this command before the targeted VC becomes selected.
 * This command is supported by MIFARE DESFire EV1, MIFARE DESFire EV2 and MIFARE Plus EV1 only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS on Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_IsoExternalAuthenticate(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                              /**< [In] Pointer to this layer's parameter structure which is of type phalVca_Sw_DataParams_t. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData,                                                  /**< [In] Input buffer to be passed for authentication. \n
                                                                             *          \c Software: Response data (RndChl||VCData) of IsoSelect command. \n
                                                                             *          \c SAM S   : Response data (MAC + Decrypted VCData) of IsoSelect command. \n
                                                                             *          \c SAM X   : Not Applicable. This command is not supported for X mode.
                                                                             */
        VAR(uint16, ANFCRL_VAR) wKeyNumber,                                               /**< [In] Key number of the VCSelect MAC key. Only applicable for Software. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion                                               /**< [In] Key version of the VCSelect MAC key. Only applicable for Software. */
    );
#endif /* NXPBUILD__PH_CRYPTOSYM */

/**
 * end of group phalVca_VC Virtual Card commands
 * @}
 */


/**
 * \addtogroup phalVca_PC Proximity Check commands
 * \brief These Components implement the Virtual Card Architecture (R) commands for Proximity Check feature.
 * @{
 */

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
 * \brief Performs the whole Proximity Check command chain which calls all the three commands(PreparePC, ExecutePC and VerifyPC) together.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_ProximityCheck(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bGenerateRndC,                                              /**< [In] 0: RndC provided; 1: generate RndC; */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndC,                                                    /**< [In] Provided RndC (7 bytes), ignored if bGenerateRndC == 1. */
        VAR(uint8, ANFCRL_VAR) bPps1,                                                      /**< [In] Speed(PPS1). This indicates communication data rate between PD and PCD. */
        VAR(uint8, ANFCRL_VAR) bNumSteps,                                                  /**< [In] Number of ProximityCheck cycles; RFU, must be 1. */
        VAR(uint16, ANFCRL_VAR) wKeyNumber,                                                /**< [In] Proximity Check MAC Key number. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion,                                               /**< [In] Proximity Check MAC Key version. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUsedRndC                                                 /**< [Out] Used RndC (7 bytes), can be NULL. */
    );
/**
 * \brief Performs the whole Proximity Check New command chain which calls all the three commands(PreparePC, PC and VerifyPC) together.
 * This command is supported by MIFARE DESFire EV2 and MIFARE Plus EV1 contactless IC product only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_ProximityCheckNew(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                              /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                  /**< [In] One of the below Option values. \n
                                                                             *          For Software and SAM S mode.
                                                                             *              \arg #PHAL_VCA_PC_RNDC_PROVIDED
                                                                             *              \arg #PHAL_VCA_PC_RNDC_GENERATE \n
                                                                             *
                                                                             *          For Sam X mode.
                                                                             *              \arg #PHAL_VCA_PC_NORMAL_PROCESSING
                                                                             *              \arg #PHAL_VCA_PC_RANDOM_PROCESSING
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC,                                                   /**< [In] One of the below contents.\n
                                                                             *          \c For Software mode and SAM S, if #PHAL_VCA_PC_RNDC_GENERATE the buffer can be null
                                                                             *             else the random number should be provided by the user.
                                                                             *
                                                                             *          \c For Sam X mode, the buffer will not be utilized as the random number
                                                                             *             will be generated by SAM.
                                                                             */
        VAR(uint8, ANFCRL_VAR) bNumSteps,                                                /**< [In] Number of ProximityCheck cycles. The value should be from 1 - 8. */
        VAR(uint16, ANFCRL_VAR) wKeyNumber,                                               /**< [In] Proximity Check MAC Key number in Software or SAM keystore. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion,                                              /**< [In] Proximity Check MAC Key version in Software or SAM keystore. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDivInput,                                                 /**< [In] Diversification input in case of SAM. */
        VAR(uint8, ANFCRL_VAR) bDivInputLen,                                               /**< [In] Diversification input length in case of SAM. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption,                                                  /**< [Out] Option field defining subsequent response content \n
                                                                             *          \c bit[0] of bOption denotes presence of PPS \n
                                                                             *          \c bit[1] of bOption denotes presence of ActBitRate
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                             /**< [Out] Published response time: time in microseconds. The PD will transmit the
                                                                            *          Cmd.ProximityCheck response as close as possible to this time.
                                                                            */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,                                                /**< [Out] The response received by the PICC. Can be \n
                                                                             *              \c Speed(PPS1). This indicates communication data rate between PD and PCD. OR \n
                                                                             *              \c ActBitRate information.
                                                                             */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen,                                                /**< [Out] Length of byte(s) available in Response buffer.
                                                                             *              \c One byte Speed(PPS1) OR \n
                                                                             *              \c N bytes of ActBitRate information.
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC                                                 /**< [Out] Combination of both pRndCmd(cumulative of 8 bytes of Random data sent from PCD) and
                                                                             *         pRndResp(cumulative of 8 bytes response data received from PD).
                                                                             */
    );

/**
 * \brief "PrepareProximityCheckNew" command shall prepare the card by generating the Option, publish response time and optional PPS.
 * This command is supported by MIFARE DESFire EV2 and Mifare Plus Ev1 product only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_PrepareProximityCheckNew(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pOption,                                                  /**< [Out] Option field defining subsequent response content \n
                                                                             *          \c bit[0] of bOption denotes presence of PPS \n
                                                                             *          \c bit[1] of bOption denotes presence of ActBitRate
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                             /**< [Out] Published response time: time in microseconds. The PD will transmit the Cmd.ProximityCheck response as close as possible to this time. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,                                                /**< [Out] The response received by the PICC. Can be \n
                                                                             *              \c Speed(PPS1). This indicates communication data rate between PD and PCD. OR \n
                                                                             *              \c ActBitRate information.
                                                                             */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRespLen                                                 /**< [Out] Length of byte(s) available in Response buffer.
                                                                             *              \c One byte Speed(PPS1) OR \n
                                                                             *              \c N bytes of ActBitRate information.
                                                                             */
    );

/**
 * \brief This new command is implemented to support VCA for MIFARE DESFire Ev2 and Mifare Plus EV1. Proximity Device answers with
 * a prepared random number at the published response time in Command "PrepareProximityCheckNew". So "ProximityCheckNew"
 * command may be repeated up to 8 times splitting the random number for different time measurements.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_ExecuteProximityCheckNew(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                                 /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bGenerateRndC,                                            /**< [In] One of the below Option values.
                                                                             *              \arg #PHAL_VCA_PC_RNDC_PROVIDED
                                                                             *              \arg #PHAL_VCA_PC_RNDC_GENERATE
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPrndC,                                                   /**< [In] Provided RndC (8 bytes), ignored if bGenerateRndC == #PHAL_VCA_PC_RNDC_GENERATE. */
        VAR(uint8, ANFCRL_VAR) bNumSteps,                                                /**< [In] Number of ProximityCheck cycles. Will be one of the below sequence. \n
                                                                             *          \c Steps = 8: Only one iteration is made, All 8 random bytes in one Cmd.ProximityCheck. \n
                                                                             *          \c Steps = 7: Sends the first 7 random bytes in one Cmd.ProximityCheck and the remaining random
                                                                             *                        byte in another one. \n
                                                                             *          \c Steps = 6: 6 in one Cmd.ProximityCheck and remaining 2 in Second. \n
                                                                             *          \c Steps = 5: 5 in one Cmd.ProximityCheck and remaining 3 in Second. \n
                                                                             *          \c Steps = 4: 4 in one Cmd.ProximityCheck and remaining 4 in Second. \n
                                                                             *          \c Steps = 3: 3 in one Cmd.ProximityCheck, 3 in Second and remaining 2 in Third. \n
                                                                             *          \c Steps = 2: 2 in one Cmd.ProximityCheck, 2 in Second, 2 in Third and remaining 2 in fourth. \n
                                                                             *          \c Steps = 1: Sends 8 Cmd.ProximityCheck with one random byte for each Exchange.
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                             /**< [In] Published response time: time in microseconds. The PD will transmit the
                                                                             *        Cmd.ProximityCheck response as close as possible to this time.
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCumRndRC                                                 /**< [Out] Combination of both pRndCmd(cumulative of 8 bytes of Random data sent from PCD)
                                                                             *         and pRndResp(cumulative of 8 bytes response data received from PD).
                                                                             */
    );

/**
 * \brief "VerifyProximityCheckNew" command verifies all random numbers received after execution of command "ExecuteProximityCheckNew" using cryptographic methods.
 * This command is supported by MIFARE DESFire EV2 and Mifare Plus Ev1 product only.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 *  \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_VerifyProximityCheckNew(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                              /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint8, ANFCRL_VAR) bOption,                                                  /**< [In] Option field defining subsequent response content \n
                                                                             *          \c bit[0] of bOption denotes presence of PPS \n
                                                                             *          \c bit[1] of bOption denotes presence of ActBitRate
                                                                             */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPubRespTime,                                             /**< [In] Published response time: time in microseconds. The PD will transmit the Cmd.ProximityCheck response as close as possible to this time. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pResponse,                                                /**< [In] The response received by the PICC. Can be \n
                                                                             *              \c Speed(PPS1). This indicates communication data rate between PD and PCD. OR \n
                                                                             *              \c ActBitRate information.
                                                                             */
        VAR(uint16, ANFCRL_VAR) wRespLen,                                                  /**< [In] Length of bytes available in Response buffer. */
        VAR(uint16, ANFCRL_VAR) wKeyNumber,                                               /**< [In] Proximity Check MAC Key number. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion,                                              /**< [In] Proximity Check MAC Key version. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRndCmdResp                                               /**< [Out] Combination of both pRndCmd(cumulative of 8 bytes of Random data sent from PCD)
                                                                             *         and pRndResp(cumulative of 8 bytes response data received from PD).
                                                                             */
    );
#endif /* NXPBUILD__PH_CRYPTOSYM */

/**
 * \brief It does all the operations as is which the above API "phalVca_VerifyProximityCheckNew" does. It is specially designed to fulfil the requirements for REC.
 * It directly sends the MAC and receive it without any further operations on the sent MAC and the received MAC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_VerifyProximityCheckUtility(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                                              /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdMac,                                                  /**< [In] 8 bytes Command MAC, to be sent directly to the PICC */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdResp                                                  /**< [Out] 8 bytes Response MAC received from PICC */
    );
/**
 * end of group phalVca_PC Proximity Check commands
 * @}
 */

/**
 * \addtogroup phalVca_Utilities Utility
 * \brief These Components implement the Virtual Card Architecture (R) commands.
 * @{
 */
/**
 * \brief Perform a SetConfig command where a particular configuration item vis. Error code can be set in VC structure.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetConfig(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,               /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig,  									/**< [In] wConfig can be one of the following.
                                                                             *          \arg #PHAL_VCA_ADDITIONAL_INFO
                                                                             *          \arg #PHAL_VCA_WRAPPED_MODE
                                                                             *          \arg #PHAL_VCA_TIMING_MODE
                                                                             *          \arg #PHAL_VCA_PC_LOWER_THRESHOLD
                                                                             *          \arg #PHAL_VCA_PC_EXTENDED_APDU
                                                                             */
        VAR(uint16, ANFCRL_VAR) wValue                                      /**< [In] Value for the mentioned configuration. */
    );

/**
 * \brief Perform a GetConfig command where a particular configuration item vis. Error code can be retrieved from VC structure.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_GetConfig(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,               /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wConfig,             						/**< [In] wConfig can be one of the following.
                                                                             *          \arg #PHAL_VCA_ADDITIONAL_INFO
                                                                             *          \arg #PHAL_VCA_WRAPPED_MODE
                                                                             *          \arg #PHAL_VCA_TIMING_MODE
                                                                             *          \arg #PHAL_VCA_PC_LOWER_THRESHOLD
                                                                             *          \arg #PHAL_VCA_PC_EXTENDED_APDU
                                                                             */
        P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue                   /**< [Out] Value for the mentioned configuration. */
    );

/**
 * \brief This is a utility API which passes card type specific session key to VCA
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetSessionKeyUtility(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                              /**< [In] Pointer to this layer's parameter structure. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSessionKey,                             /**< [In] 16 bytes Session Key */
        VAR(uint8, ANFCRL_VAR) bAuthMode                                                   /**< [In] Current Authentication Mode (Card type specific) */
    );

/**
 * \brief This is a utility API which sets the application type(MIFARE DESFire Ev2, MFP Ev1 etc) in the VCA structure
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_SetApplicationType(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pAlDataParams
        );

#ifdef NXPBUILD__PH_CRYPTOSYM
/**
 * \brief This is a utility API which decrypt the response data(32 bytes) of IsoSelect
 * to get the RndChal and VCData(INFO||PDCap1||VCUID||ZeroPadding)
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phalVca_DecryptResponse(
        P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                              /**< [In] Pointer to this layer's parameter structure. */
        VAR(uint16, ANFCRL_VAR) wKeyNo,                                                    /**< [In] Key number of the VCSelect ENC key. */
        VAR(uint16, ANFCRL_VAR) wKeyVersion,                                               /**< [In] Key version of the VCSelect ENC key. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pInData,                                 /**< [In] Input data to be decrypted. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRandChal,                               /**< [Out] Random Challenge. */
        P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pVCData                                  /**< [Out] Decrypted VC Data. */
    );
#endif /* NXPBUILD__PH_CRYPTOSYM */

/**
 * end of group phalVca_Utilities Utility
 * @}
 */

/**
 * end of group phalVca Virtual Card Architecture (R)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHALVCA_AR_RELEASE_MAJOR_VERSION == 4) && (PHALVCA_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAL_VCA */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHALVCA_H */
