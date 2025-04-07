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
*   @file    phNfcLib_Initialization2.h
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
#ifndef PHNFCLIB_INITIALIZATION2_H
#define PHNFCLIB_INITIALIZATION2_H

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
#ifdef NXPBUILD__PHNFCLIB2
#include <phNfcLib2.h>
#include <phacDiscLoop2.h>
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Initialization2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_INITIALIZATION_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_INITIALIZATION_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHNFCLIB_INITIALIZATION_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phNfcLib_Initialization2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_Initialization2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_Initialization2.h and CDD_AnfcRL_Cfg.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB2 */
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB2
#define PH_CHECK_NFCLIB_SUCCESS2(status2)         {if ((status2) != PH_ERR_SUCCESS2) {return (PH_NFCLIB_STATUS_INTERNAL_ERROR2);}}
#define PH_CHECK_NFCLIB_SUCCESS_FCT2(status2,fct2) {(status2) = (fct2); PH_CHECK_NFCLIB_SUCCESS2(status2);}

#define PH_NFCLIB_INT_TRANSMIT_OFF2                  0x00U
#define PH_NFCLIB_INT_TRANSMIT_ON2                   0x01U
#define PH_NFCLIB_INT_TRANSMIT_SUCCESS_CHAINING2     0x02U

/* By default invalid authentication status2 */
#define PH_NFCLIB_MFDF_NOT_AUTHENTICATED2             0xFFU   /**< No authentication. */
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
    eNfcLib_ResetState2 = 0,
    eNfcLib_InitializedState2 = 1,
    eNfcLib_ActivatedState2 = 2,
    eNfcLib_DeactOngoingState2 = 3,
    eNfcLib_LAST2 = 0x7F /* Where facilitated by compiler, promote to 8 bit number */
} phNfcLib_StateMachine_t2;
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
typedef phStatus_t2 (*pphNfcLib_Config_Profile2)(void);

/**
* \brief NFCLIB parameter structure
*/
typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId2;               /**< ID of this component, do not modify. */

    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBal2;               /**< Holds BAL context */

    #ifdef NXPBUILD__PHHAL_HW_NCx33202
    VAR(phhalHw_Ncx3320_DataParams_t2, ANFCRL_VAR) sHal2;               /**< HAL component holder */
    #endif /* NXPBUILD__PHHAL_HW_NCx33202 */

	#ifdef NXPBUILD__PHHAL_HW_NCX33212
  VAR(phhalHw_Ncx3321_DataParams_t2, ANFCRL_VAR) sHal2;               /**< HAL component holder */
	#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

    #ifdef NXPBUILD__PH_KEYSTORE_SW2
    VAR(phKeyStore_Sw_DataParams_t2, ANFCRL_VAR) sKeyStore2;          /**< SW Keystore component holder */
    #endif /* NXPBUILD__PH_KEYSTORE_SW2 */

    #ifdef NXPBUILD__PH_KEYSTORE_NCx33202
    VAR(phKeyStore_Ncx3320_DataParams_t2, ANFCRL_VAR) sKeyStore2;          /**< Ncx3320 HW Keystore component holder */
    #endif /* NXPBUILD__PH_KEYSTORE_NCx33202 */

    pphNfcLib_ErrCallbck2               pNfcLib_ErrCallbck2; /**< Call back in case of error in activation(applicable for activation profile #PH_NFCLIB_ACTIVATION_PROFILE_EMVCO2) */

    /* PAL Data Parameter Structures */

    #ifdef NXPBUILD__PHPAL_I14443P3A_SW2
    VAR(phpalI14443p3a_Sw_DataParams_t2, ANFCRL_VAR) spalI14443p3a2;      /* PAL ISO I14443-A component */
    #endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

    #ifdef NXPBUILD__PHPAL_I14443P3B_SW2
    VAR(phpalI14443p3b_Sw_DataParams_t2, ANFCRL_VAR) spalI14443p3b2;      /* PAL ISO I14443-B component */
    #endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

    #ifdef NXPBUILD__PHPAL_I14443P4A_SW2
    VAR(phpalI14443p4a_Sw_DataParams_t2, ANFCRL_VAR) spalI14443p4a2;      /* PAL ISO I14443-4A component */
    #endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

    #ifdef NXPBUILD__PHPAL_I14443P4_SW2
    VAR(phpalI14443p4_Sw_DataParams_t2, ANFCRL_VAR) spalI14443p42;       /* PAL ISO I14443-4 component */
    #endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

    #ifdef NXPBUILD__PHPAL_SLI15693_SW2
    VAR(phpalSli15693_Sw_DataParams_t2, ANFCRL_VAR) spalSli156932;       /* PAL ISO 15693 component */
    #endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

    #ifdef NXPBUILD__PHPAL_FELICA_SW2
    VAR(phpalFelica_Sw_DataParams_t2, ANFCRL_VAR) spalFelica2;         /* PAL Felica component */
    #endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    #ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
    VAR(phpalI14443p4mC_Sw_DataParams_t2, ANFCRL_VAR) spalI14443p4mC2;     /* PAL 14443-4mC Target component */

    VAR(pWtxTimerCallback_t2, ANFCRL_VAR) pWtxCallback2;       /**< Holds the function pointer of WTX callback */
    #endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

    #ifdef NXPBUILD__PHPAL_MIFARE_SW2
    VAR(phpalMifare_Sw_DataParams_t2, ANFCRL_VAR) spalMifare2;         /* PAL Mifare component */
    #endif /* NXPBUILD__PHPAL_MIFARE_SW2 */

    #ifdef NXPBUILD__PHAL_FELICA_SW2
    VAR(phalFelica_Sw_DataParams_t2, ANFCRL_VAR) salFelica2;          /* AL FeliCa component */
    #endif /* NXPBUILD__PHAL_FELICA_SW2 */

    #ifdef NXPBUILD__PHAL_ICODE_SW2
    VAR(phalICode_Sw_DataParams_t2, ANFCRL_VAR) salICode2;          /* ICode AL component */
    #endif /* NXPBUILD__PHAL_ICODE_SW2 */

    #ifdef NXPBUILD__PHAL_MFDF_SW2
    VAR(phalMfdf_Sw_DataParams_t2, ANFCRL_VAR) salMFDF2;            /* AL MIFARE DESFire contactless IC component */
    #endif /* NXPBUILD__PHAL_MFDF_SW2 */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
    VAR(phalMfdfEVx_Sw_DataParams_t2, ANFCRL_VAR) salMFDFEVx2;         /* AL MIFARE DESFire Ev2 contactless IC component */
	#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

    #ifdef NXPBUILD__PHAC_DISCLOOP_SW2
    VAR(phacDiscLoop_Sw_DataParams_t2, ANFCRL_VAR) sDiscLoop2;          /* Discovery loop component */
    #endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

    #ifdef NXPBUILD__PHCE_T4T_SW2
    VAR(phceT4T_Sw_DataParams_t2, ANFCRL_VAR) sceT4T2;             /* HCE component */
    #endif /* NXPBUILD__PHCE_T4T_SW2 */

    /* Crypto Data Parameter Structures */
    #ifdef NXPBUILD__PH_CRYPTOSYM_SW2
    VAR(phCryptoSym_Sw_DataParams_t2, ANFCRL_VAR) sCryptoSym2;          /* Crypto Sym component */
    #endif /* NXPBUILD__PH_CRYPTOSYM_SW2 */

    #ifdef NXPBUILD__PH_CRYPTORNG_SW2
    VAR(phCryptoRng_Sw_DataParams_t2, ANFCRL_VAR) sCryptoRng2;          /* Crypto Rng component */
    #endif /* NXPBUILD__PH_CRYPTORNG_SW2 */

} phNfcLib_DataParams_t2;

/**
 * \brief NFC LIB State
 * \anchor NfcLib_State
 */
typedef struct
{
    VAR(phNfcLib_StateMachine_t2, ANFCRL_VAR) bNfcLibState2;                                         /* State of the NfcLib takes value from enum phNfcLib_StateMachine_t2 */
    VAR(uint8, ANFCRL_VAR) bProfileSelected2;                                     /* Tells about the selected profile takes value ISO, NFC, EMVCO */
    VAR(uint8, ANFCRL_VAR) bActivateBlocking2;                                    /* Tells the blocking #PH_ON2 or #PH_OFF2 feature of Activation */
    VAR(uint8, ANFCRL_VAR) bDeactBlocking2;                                       /* Tells the blocking #PH_ON2 or #PH_OFF2 feature of DeActivation */
    VAR(uint8, ANFCRL_VAR) bMergedSakPrio2;                                       /* Tells the priority to perform activation of the card in case Merged Sak is received */
    VAR(uint8, ANFCRL_VAR) bLPCDState2;                                           /* Tells the LPCD #PH_ON2 or #PH_OFF2 performance */
    VAR(uint8, ANFCRL_VAR) bTxState2;                                             /* Tells the TX state of nfclib, if 1 then only receive can be performed */
    VAR(uint16, ANFCRL_VAR) wConfiguredRFTech2;                                    /* Tells the configured RF Tech that was used for current activation cycle */
    P2VAR(phNfcLib_PeerInfo_t2, AUTOMATIC, ANFCRL_APPL_DATA) pPeerInfo2;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2;                                           /* Pointer to the RX */
    VAR(uint16, ANFCRL_VAR) wRxLength2;                                            /* Stores the length of the received Data */
    VAR(uint16, ANFCRL_VAR) wRxDataPoin2;                                         /* Points to the starting address of the rx buffer to perform Chaining */
    VAR(uint8, ANFCRL_VAR) bHalBufferTx2[PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE2];  /* HAL TX buffer. */
    VAR(uint8, ANFCRL_VAR) bHalBufferRx2[PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE2];  /* HAL RX buffer. */
    VAR(uint8, ANFCRL_VAR) bWrappedMode2;                                          /* Tells about the Mifare Desfire Wrapped Mode Status */
    VAR(uint8, ANFCRL_VAR) bAuthMode2;                                             /* Tells about the Mifare Desfire Auth Mode */
    VAR(uint16, ANFCRL_VAR) wActivatedUIDLength2;                                  /* Length of the activated UID */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pActivatedUid2;                                        /* Contains the pointer of the activated Uid */

} phNfcLib_InternalState_t2;
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/
extern VAR(phNfcLib_DataParams_t2, ANFCRL_VAR) gphNfcLib_Params2;
extern VAR(phNfcLib_InternalState_t2, ANFCRL_VAR) gphNfcLib_State2;
/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#endif /* NXPBUILD__PHNFCLIB2 */

#ifdef __cplusplus
}
#endif
#endif /* PHNFCLIB_INITIALIZATION2_H */
