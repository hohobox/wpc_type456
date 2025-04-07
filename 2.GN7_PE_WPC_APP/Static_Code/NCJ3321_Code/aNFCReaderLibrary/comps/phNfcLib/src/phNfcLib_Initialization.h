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
*   @file    phNfcLib_Initialization.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NfcLib_Initialization - NFC API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup nfc_lib NXP NFC Library Top Level API
*   @ingroup grpsApi
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
#ifndef PHNFCLIB_INITIALIZATION_H
#define PHNFCLIB_INITIALIZATION_H

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
#ifdef NXPBUILD__PHNFCLIB
#include <phNfcLib.h>
#include <phacDiscLoop.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Initialization.h
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_INITIALIZATION_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_INITIALIZATION_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHNFCLIB_INITIALIZATION_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phNfcLib_Initialization.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_Initialization.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_Initialization.h and CDD_AnfcRL_Cfg.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB */
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB
#define PH_CHECK_NFCLIB_SUCCESS(status)         {if ((status) != PH_ERR_SUCCESS) {return (PH_NFCLIB_STATUS_INTERNAL_ERROR);}}
#define PH_CHECK_NFCLIB_SUCCESS_FCT(status,fct) {(status) = (fct); PH_CHECK_NFCLIB_SUCCESS(status);}

#define PH_NFCLIB_INT_TRANSMIT_OFF                  0x00U
#define PH_NFCLIB_INT_TRANSMIT_ON                   0x01U
#define PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING     0x02U

/* By default invalid authentication status */
#define PH_NFCLIB_MFDF_NOT_AUTHENTICATED             0xFFU   /**< No authentication. */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
/**
 * \brief NFC LIB StateMachine
 * \anchor NfcLib_StateMachine_for_LIB
 * Refer state machine for each mode defined above.
 */
typedef enum
{
    eNfcLib_ResetState = 0,
    eNfcLib_InitializedState = 1,
    eNfcLib_ActivatedState = 2,
    eNfcLib_DeactOngoingState = 3,
    eNfcLib_LAST = 0x7F /* Where facilitated by compiler, promote to 8 bit number */
} phNfcLib_StateMachine_t;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef phStatus_t (*pphNfcLib_Config_Profile)(void);

/**
* \brief NFCLIB parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;               /**< ID of this component, do not modify. */

    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBal;               /**< Holds BAL context */

    #ifdef NXPBUILD__PHHAL_HW_NCx3320
    VAR(phhalHw_Ncx3320_DataParams_t, ANFCRL_VAR) sHal;               /**< HAL component holder */
    #endif /* NXPBUILD__PHHAL_HW_NCx3320 */

	#ifdef NXPBUILD__PHHAL_HW_NCX3321
  VAR(phhalHw_Ncx3321_DataParams_t, ANFCRL_VAR) sHal;               /**< HAL component holder */
	#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

    #ifdef NXPBUILD__PH_KEYSTORE_SW
    VAR(phKeyStore_Sw_DataParams_t, ANFCRL_VAR) sKeyStore;          /**< SW Keystore component holder */
    #endif /* NXPBUILD__PH_KEYSTORE_SW */

    #ifdef NXPBUILD__PH_KEYSTORE_NCx3320
    VAR(phKeyStore_Ncx3320_DataParams_t, ANFCRL_VAR) sKeyStore;          /**< Ncx3320 HW Keystore component holder */
    #endif /* NXPBUILD__PH_KEYSTORE_NCx3320 */

    pphNfcLib_ErrCallbck               pNfcLib_ErrCallbck; /**< Call back in case of error in activation(applicable for activation profile #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO) */

    /* PAL Data Parameter Structures */

    #ifdef NXPBUILD__PHPAL_I14443P3A_SW
    VAR(phpalI14443p3a_Sw_DataParams_t, ANFCRL_VAR) spalI14443p3a;      /* PAL ISO I14443-A component */
    #endif /* NXPBUILD__PHPAL_I14443P3A_SW */

    #ifdef NXPBUILD__PHPAL_I14443P3B_SW
    VAR(phpalI14443p3b_Sw_DataParams_t, ANFCRL_VAR) spalI14443p3b;      /* PAL ISO I14443-B component */
    #endif /* NXPBUILD__PHPAL_I14443P3B_SW */

    #ifdef NXPBUILD__PHPAL_I14443P4A_SW
    VAR(phpalI14443p4a_Sw_DataParams_t, ANFCRL_VAR) spalI14443p4a;      /* PAL ISO I14443-4A component */
    #endif /* NXPBUILD__PHPAL_I14443P4A_SW */

    #ifdef NXPBUILD__PHPAL_I14443P4_SW
    VAR(phpalI14443p4_Sw_DataParams_t, ANFCRL_VAR) spalI14443p4;       /* PAL ISO I14443-4 component */
    #endif /* NXPBUILD__PHPAL_I14443P4_SW */

    #ifdef NXPBUILD__PHPAL_SLI15693_SW
    VAR(phpalSli15693_Sw_DataParams_t, ANFCRL_VAR) spalSli15693;       /* PAL ISO 15693 component */
    #endif /* NXPBUILD__PHPAL_SLI15693_SW */

    #ifdef NXPBUILD__PHPAL_FELICA_SW
    VAR(phpalFelica_Sw_DataParams_t, ANFCRL_VAR) spalFelica;         /* PAL Felica component */
    #endif /* NXPBUILD__PHPAL_FELICA_SW */

    #ifdef NXPBUILD__PHPAL_I14443P4MC_SW
    VAR(phpalI14443p4mC_Sw_DataParams_t, ANFCRL_VAR) spalI14443p4mC;     /* PAL 14443-4mC Target component */

    VAR(pWtxTimerCallback_t, ANFCRL_VAR) pWtxCallback;       /**< Holds the function pointer of WTX callback */
    #endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

    #ifdef NXPBUILD__PHPAL_MIFARE_SW
    VAR(phpalMifare_Sw_DataParams_t, ANFCRL_VAR) spalMifare;         /* PAL Mifare component */
    #endif /* NXPBUILD__PHPAL_MIFARE_SW */

    #ifdef NXPBUILD__PHAL_FELICA_SW
    VAR(phalFelica_Sw_DataParams_t, ANFCRL_VAR) salFelica;          /* AL FeliCa component */
    #endif /* NXPBUILD__PHAL_FELICA_SW */

    #ifdef NXPBUILD__PHAL_ICODE_SW
    VAR(phalICode_Sw_DataParams_t, ANFCRL_VAR) salICode;          /* ICode AL component */
    #endif /* NXPBUILD__PHAL_ICODE_SW */

    #ifdef NXPBUILD__PHAL_MFDF_SW
    VAR(phalMfdf_Sw_DataParams_t, ANFCRL_VAR) salMFDF;            /* AL MIFARE DESFire contactless IC component */
    #endif /* NXPBUILD__PHAL_MFDF_SW */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
    VAR(phalMfdfEVx_Sw_DataParams_t, ANFCRL_VAR) salMFDFEVx;         /* AL MIFARE DESFire Ev2 contactless IC component */
	#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

    #ifdef NXPBUILD__PHAC_DISCLOOP_SW
    VAR(phacDiscLoop_Sw_DataParams_t, ANFCRL_VAR) sDiscLoop;          /* Discovery loop component */
    #endif /* NXPBUILD__PHAC_DISCLOOP_SW */

    #ifdef NXPBUILD__PHCE_T4T_SW
    VAR(phceT4T_Sw_DataParams_t, ANFCRL_VAR) sceT4T;             /* HCE component */
    #endif /* NXPBUILD__PHCE_T4T_SW */

    /* Crypto Data Parameter Structures */
    #ifdef NXPBUILD__PH_CRYPTOSYM_SW
    VAR(phCryptoSym_Sw_DataParams_t, ANFCRL_VAR) sCryptoSym;          /* Crypto Sym component */
    #endif /* NXPBUILD__PH_CRYPTOSYM_SW */

    #ifdef NXPBUILD__PH_CRYPTORNG_SW
    VAR(phCryptoRng_Sw_DataParams_t, ANFCRL_VAR) sCryptoRng;          /* Crypto Rng component */
    #endif /* NXPBUILD__PH_CRYPTORNG_SW */

} phNfcLib_DataParams_t;

/**
 * \brief NFC LIB State
 * \anchor NfcLib_State
 */
typedef struct
{
    VAR(phNfcLib_StateMachine_t, ANFCRL_VAR) bNfcLibState;                                         /* State of the NfcLib takes value from enum phNfcLib_StateMachine_t */
    VAR(uint8, ANFCRL_VAR) bProfileSelected;                                     /* Tells about the selected profile takes value ISO, NFC, EMVCO */
    VAR(uint8, ANFCRL_VAR) bActivateBlocking;                                    /* Tells the blocking #PH_ON or #PH_OFF feature of Activation */
    VAR(uint8, ANFCRL_VAR) bDeactBlocking;                                       /* Tells the blocking #PH_ON or #PH_OFF feature of DeActivation */
    VAR(uint8, ANFCRL_VAR) bMergedSakPrio;                                       /* Tells the priority to perform activation of the card in case Merged Sak is received */
    VAR(uint8, ANFCRL_VAR) bLPCDState;                                           /* Tells the LPCD #PH_ON or #PH_OFF performance */
    VAR(uint8, ANFCRL_VAR) bTxState;                                             /* Tells the TX state of nfclib, if 1 then only receive can be performed */
    VAR(uint16, ANFCRL_VAR) wConfiguredRFTech;                                    /* Tells the configured RF Tech that was used for current activation cycle */
    P2VAR(phNfcLib_PeerInfo_t, AUTOMATIC, ANFCRL_APPL_DATA) pPeerInfo;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer;                                           /* Pointer to the RX */
    VAR(uint16, ANFCRL_VAR) wRxLength;                                            /* Stores the length of the received Data */
    VAR(uint16, ANFCRL_VAR) wRxDataPoin;                                         /* Points to the starting address of the rx buffer to perform Chaining */
    VAR(uint8, ANFCRL_VAR) bHalBufferTx[PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE];  /* HAL TX buffer. */
    VAR(uint8, ANFCRL_VAR) bHalBufferRx[PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE];  /* HAL RX buffer. */
    VAR(uint8, ANFCRL_VAR) bWrappedMode;                                          /* Tells about the Mifare Desfire Wrapped Mode Status */
    VAR(uint8, ANFCRL_VAR) bAuthMode;                                             /* Tells about the Mifare Desfire Auth Mode */
    VAR(uint16, ANFCRL_VAR) wActivatedUIDLength;                                  /* Length of the activated UID */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pActivatedUid;                                        /* Contains the pointer of the activated Uid */

} phNfcLib_InternalState_t;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(phNfcLib_DataParams_t, ANFCRL_VAR) gphNfcLib_Params;
extern VAR(phNfcLib_InternalState_t, ANFCRL_VAR) gphNfcLib_State;
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* NXPBUILD__PHNFCLIB */

#ifdef __cplusplus
}
#endif
#endif /* PHNFCLIB_INITIALIZATION_H */
