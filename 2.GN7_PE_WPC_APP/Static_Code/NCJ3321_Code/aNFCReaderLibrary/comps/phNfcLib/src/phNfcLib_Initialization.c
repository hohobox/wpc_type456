/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020-2023
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
*   @file    phNfcLib_Initialization.c
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

#ifdef NXPBUILD__PHNFCLIB
#include "phNfcLib_Initialization.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Initialization.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_INITIALIZATION_VENDOR_ID_C                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION_C    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION_C               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION_C               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION_C               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_Initialization.h header file are of the same vendor */
#if (PHNFCLIB_INITIALIZATION_VENDOR_ID_C != PHNFCLIB_INITIALIZATION_VENDOR_ID)
    #error "phNfcLib_Initialization.c and phNfcLib_Initialization.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_Initialization.h header file are of the same Autosar version */
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C    != PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION) || \
     (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C    != PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION) || \
     (PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION_C != PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phNfcLib_Initialization.c and phNfcLib_Initialization.h are different"
#endif
/* Check if current file and phNfcLib_Initialization.h header file are of the same Software version */
#if ((PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION_C != PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION) || \
     (PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION_C != PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION) || \
     (PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION_C != PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION))
    #error "Software Version Numbers of phNfcLib_Initialization.c and phNfcLib_Initialization.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB
#if defined (NXPBUILD__PH_KEYSTORE_SW) || defined(NXPBUILD__PH_KEYSTORE_NCx3320)
#define PH_NFCLIB_KEYSTORE_DATAPARAMS    (&gphNfcLib_Params.sKeyStore)
#else
#define PH_NFCLIB_KEYSTORE_DATAPARAMS (NULL)
#endif

#ifdef NXPBUILD__PH_KEYSTORE_SW
/**
 * Parameter for Keystore
 * Defines the number of key entries and key version pairs in sw keystore
 */
#define NUMBER_OF_KEYENTRIES        2u
#define NUMBER_OF_KEYVERSIONPAIRS   2u
#define NUMBER_OF_KUCENTRIES        1u
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#define PH_CHECK_NFCLIB_INIT_FCT(status,fct)  {(status) = (fct); PH_BREAK_ON_FAILURE(status);}

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
#define SEED_COUNT_MFDF      0x08
#define IID_KEY_COUNT   0x13U   /* number of IID keys */
#define TMI_BUFFER_SIZE 255     /* TMI Buffer Size */
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PHPAL_I14443P4_SW
#   define PTR_spalI14443p4 (&gphNfcLib_Params.spalI14443p4)
#else
#   define PTR_spalI14443p4 NULL
#endif

#ifdef NXPBUILD__PH_KEYSTORE_SW
#   define PTR_sKeyStore (&gphNfcLib_Params.sKeyStore)
#else
#   define PTR_sKeyStore NULL
#endif

#ifdef NXPBUILD__PH_CRYPTOSYM_SW
#   define PTR_sCryptoSym (&gphNfcLib_Params.sCryptoSym)
#else
#   define PTR_sCryptoSym NULL
#endif

#ifdef NXPBUILD__PH_CRYPTORNG_SW
#   define PTR_sCryptoRng (&gphNfcLib_Params.sCryptoRng)
#else
#   define PTR_sCryptoRng NULL
#endif

#ifdef NXPBUILD__PHAL_FELICA_SW
#   define PTR_salFelica (&gphNfcLib_Params.salFelica)
#else
#   define PTR_salFelica NULL
#endif

#ifdef NXPBUILD__PHAL_MFDF_SW
#   define PTR_salMFDF (&gphNfcLib_Params.salMFDF)
#else
#   define PTR_salMFDF NULL
#endif

#ifdef NXPBUILD__PHAL_ICODE_SW
#   define PTR_salICode (&gphNfcLib_Params.salICode)
#else
#   define PTR_salICode NULL
#endif

#ifdef NXPBUILD__PHPAL_I14443P3A_SW
#   define PTR_spalI14443p3a (&gphNfcLib_Params.spalI14443p3a)
#else
#   define PTR_spalI14443p3a NULL
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
static VAR(phalVca_Sw_IidTableEntry_t, ANFCRL_VAR) astIidTableEntry[IID_KEY_COUNT];  /**< Pointer to the Iid Table storage for the layer. */
static VAR(phalVca_Sw_CardTableEntry_t, ANFCRL_VAR) astCardTableEntry[IID_KEY_COUNT];/**< Pointer to the Card Table storage for the layer. */

static VAR(phCryptoSym_Sw_DataParams_t, ANFCRL_VAR) sCryptoEnc;
static VAR(phCryptoSym_Sw_DataParams_t, ANFCRL_VAR) sCryptoMac;
static VAR(phCryptoSym_Sw_DataParams_t, ANFCRL_VAR) sCryptoSymRng;
static VAR(phCryptoRng_Sw_DataParams_t, ANFCRL_VAR) sCryptoRngVar;
static VAR(phTMIUtils_t, ANFCRL_VAR) sTMI;
static VAR(phalVca_Sw_DataParams_t, ANFCRL_VAR) sVca;

static VAR(uint8, ANFCRL_VAR) aSeed_MFDF[SEED_COUNT_MFDF];
static VAR(uint8, ANFCRL_VAR) aTmi_Buffer[TMI_BUFFER_SIZE];
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PH_KEYSTORE_SW
/**
 * SW Key Structure Pointers
 */

static VAR(phKeyStore_Sw_KeyEntry_t, ANFCRL_VAR) gpKeyEntries[NUMBER_OF_KEYENTRIES];
static VAR(phKeyStore_Sw_KeyVersionPair_t, ANFCRL_VAR) gpKeyVersionPairs[NUMBER_OF_KEYVERSIONPAIRS * NUMBER_OF_KEYENTRIES];
static VAR(phKeyStore_Sw_KUCEntry_t, ANFCRL_VAR) gpKUCEntries[NUMBER_OF_KUCENTRIES];
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#ifdef NXPBUILD__PHCE_T4T_SW
/**
 * Application buffer. Used in phceT4T_Init. Its needed for data exchange
 * between application thread and reader library thread. Refer phceT4T_Init in
 * phceT4T.h for more info.
 * */
static VAR(uint8, ANFCRL_VAR) aAppHCEBuf[PH_NXPNFCRDLIB_CONFIG_HCE_BUFF_LENGTH];
#endif /* NXPBUILD__PHCE_T4T_SW */

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
static VAR(uint16, ANFCRL_VAR) wNumIidTableStorageEntriesVar = IID_KEY_COUNT;         /**< Number of possible Iid table entries in the storage. */
static VAR(uint16, ANFCRL_VAR) wNumCardTableStorageEntriesVar = IID_KEY_COUNT;        /**< Number of possible Card table entries in the storage. */
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PH_KEYSTORE_SW
/* Set the key for the MIFARE (R) Classic cards. */
static VAR(uint8, ANFCRL_VAR) gphNfcLib_Key[6] = { 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU };
#endif /* NXPBUILD__PH_KEYSTORE_SW */

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                      GLOBAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      GLOBAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

VAR(phNfcLib_DataParams_t, ANFCRL_VAR) gphNfcLib_Params;
VAR(phNfcLib_InternalState_t, ANFCRL_VAR) gphNfcLib_State;

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * This function will initialize Reader Library PAL Components
 */
static FUNC(phStatus_t, ANFCRL_CODE) phNfcLib_PAL_Init(void);

/**
 * This function will initialize Reader Library AL Components
 */
static FUNC(phStatus_t, ANFCRL_CODE) phNfcLib_AL_Init(void);

FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_SetContext(P2VAR(phNfcLib_AppContext_t, AUTOMATIC, ANFCRL_APPL_DATA) pAppContext)
{
    if (pAppContext == NULL)
    {
        return PH_NFCLIB_STATUS_INVALID_PARAMETER;
    }

	gphNfcLib_Params.pBal = pAppContext->pBalDataparams;
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
	gphNfcLib_Params.pWtxCallback = pAppContext->pWtxCallback;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

#ifdef NXPBUILD__PHHAL_HW_NCX3321
	gphNfcLib_Params.sHal.pHalPollFunc = pAppContext->pHalPollFunc;
#endif /*NXPBUILD__PHHAL_HW_NCX3321*/

	return PH_NFCLIB_STATUS_SUCCESS;
}

/**
 * This function will initialize Reader Library PAL Components
 */
static FUNC(phStatus_t, ANFCRL_CODE) phNfcLib_PAL_Init(void) {
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	/* Initialize the I14443-3A PAL layer */
#ifdef NXPBUILD__PHPAL_I14443P3A_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalI14443p3a_Sw_Init(&gphNfcLib_Params.spalI14443p3a,
						(uint16 )(sizeof(phpalI14443p3a_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

		/* Initialize the I14443-3B PAL  component */
#ifdef NXPBUILD__PHPAL_I14443P3B_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalI14443p3b_Sw_Init(&gphNfcLib_Params.spalI14443p3b,
						(uint16 )(sizeof(phpalI14443p3b_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */

		/* Initialize the I14443-4A PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4A_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalI14443p4a_Sw_Init(&gphNfcLib_Params.spalI14443p4a,
						(uint16 )(sizeof(phpalI14443p4a_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

		/* Initialize the I14443-4 PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalI14443p4_Sw_Init(&gphNfcLib_Params.spalI14443p4,
						(uint16 )(sizeof(phpalI14443p4_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

		/* Initialize the Mifare PAL component */
#ifdef NXPBUILD__PHPAL_MIFARE_SW
	PH_CHECK_SUCCESS_FCT(wStatus, phpalMifare_Sw_Init(
						&gphNfcLib_Params.spalMifare,
						(uint16)(sizeof(phpalMifare_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal,
						PTR_spalI14443p4
				));
#endif /* NXPBUILD__PHPAL_MIFARE_SW */

		/* Initialize PAL Felica PAL component */
#ifdef NXPBUILD__PHPAL_FELICA_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalFelica_Sw_Init(&gphNfcLib_Params.spalFelica,
						(uint16 )(sizeof(phpalFelica_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_FELICA_SW */

		/* Initialize the 15693 PAL component */
#ifdef NXPBUILD__PHPAL_SLI15693_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalSli15693_Sw_Init(&gphNfcLib_Params.spalSli15693,
						(uint16 )(sizeof(phpalSli15693_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal));
#endif /* NXPBUILD__PHPAL_SLI15693_SW */

		/* Initialize 14443-4mC Target PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phpalI14443p4mC_Sw_Init(
						&gphNfcLib_Params.spalI14443p4mC,
						(uint16)(sizeof(phpalI14443p4mC_Sw_DataParams_t)),
						&gphNfcLib_Params.sHal,
						gphNfcLib_Params.pWtxCallback
				));
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

	return wStatus;
}

/**
 * This function will initialize the Reader Library AL Components
 */
static FUNC(phStatus_t, ANFCRL_CODE) phNfcLib_AL_Init(void) {
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

		/* Initialize AL Felica component */
#ifdef NXPBUILD__PHAL_FELICA_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phalFelica_Sw_Init( &gphNfcLib_Params.salFelica,
						(uint16)(sizeof(phalFelica_Sw_DataParams_t)),
						&gphNfcLib_Params.spalFelica,
						PTR_sCryptoSym));
#endif /* NXPBUILD__PHAL_FELICA_SW */

		/* Initialize AL Mifare DESFire component */
#ifdef NXPBUILD__PHAL_MFDF_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phalMfdf_Sw_Init(
						&gphNfcLib_Params.salMFDF,
						(uint16)(sizeof(phalMfdf_Sw_DataParams_t)),
						&gphNfcLib_Params.spalMifare,
						PTR_sKeyStore,
						PTR_sCryptoSym,
						PTR_sCryptoRng,
						&gphNfcLib_Params.sHal
				));
#endif /* NXPBUILD__PHAL_MFDF_SW */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
        /* init. crypto */
	PH_CHECK_SUCCESS_FCT(wStatus,phCryptoSym_Sw_Init(
            &sCryptoEnc,
			(uint16) sizeof(phCryptoSym_Sw_DataParams_t),
            &gphNfcLib_Params.sKeyStore));
	PH_CHECK_SUCCESS_FCT(wStatus,phCryptoSym_Sw_Init(
				&sCryptoMac,
				(uint16) sizeof(phCryptoSym_Sw_DataParams_t),
				&gphNfcLib_Params.sKeyStore));
	PH_CHECK_SUCCESS_FCT(wStatus,phCryptoSym_Sw_Init(
				&sCryptoSymRng,
				(uint16) sizeof(phCryptoSym_Sw_DataParams_t),
				&gphNfcLib_Params.sKeyStore));
	PH_CHECK_SUCCESS_FCT(wStatus,phCryptoRng_Sw_Init(
				&sCryptoRngVar,
				(uint16) sizeof(phCryptoRng_Sw_DataParams_t),
				&sCryptoSymRng));
	PH_CHECK_SUCCESS_FCT(wStatus,phCryptoRng_Seed(
				&sCryptoRngVar,
				aSeed_MFDF,
				8));
	PH_CHECK_SUCCESS_FCT(wStatus,phTMIUtils_Init(
				&sTMI,
				&aTmi_Buffer[0],
				TMI_BUFFER_SIZE));

        /* Initialize the VCA component */
	PH_CHECK_SUCCESS_FCT(wStatus,phalVca_Sw_Init(
				&sVca,
				(uint16) sizeof(phalVca_Sw_DataParams_t),
				&gphNfcLib_Params.spalMifare,
				&gphNfcLib_Params.sKeyStore,
				&sCryptoEnc,
				&sCryptoRngVar,
				astIidTableEntry,
				wNumIidTableStorageEntriesVar,
				astCardTableEntry,
				wNumCardTableStorageEntriesVar
				));

        /* Initialize the MIFARE DESFire EV2 contactless IC component */
	PH_CHECK_SUCCESS_FCT(wStatus,phalMfdfEVx_Sw_Init(
				&gphNfcLib_Params.salMFDFEVx,
				(uint16) sizeof(phalMfdfEVx_Sw_DataParams_t),
				&gphNfcLib_Params.spalMifare,
				&gphNfcLib_Params.sKeyStore,
				&sCryptoEnc,
				&sCryptoMac,
				&sCryptoRngVar,
				&sTMI,
				&sVca,
				&gphNfcLib_Params.sHal));
	PH_CHECK_SUCCESS_FCT(wStatus,phalVca_SetApplicationType(
				&sVca,
				&gphNfcLib_Params.salMFDFEVx));
#endif  /* NXPBUILD__PHAL_MFDFEVX_SW */

		/* Initialize the ISO ICODE AL component */
#ifdef NXPBUILD__PHAL_ICODE_SW
	PH_CHECK_SUCCESS_FCT(wStatus,phalICode_Sw_Init( &gphNfcLib_Params.salICode, (uint16)(sizeof(phalICode_Sw_DataParams_t)), &gphNfcLib_Params.spalSli15693, NULL, NULL, NULL));
#endif /* NXPBUILD__PHAL_ICODE_SW */

	return wStatus;
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_Init_Ncx3321_Init(void)
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			== eNfcLib_ResetState) {
#ifdef NXPBUILD__PHHAL_HW_NCX3321
		/* Initialize the Ncx3321 HAL component */
		PH_CHECK_SUCCESS_FCT(wStatus, phhalHw_Ncx3321_Init(
			&gphNfcLib_Params.sHal,
			(uint16)(sizeof(phhalHw_Ncx3321_DataParams_t)),
			gphNfcLib_Params.pBal,
			PH_NFCLIB_KEYSTORE_DATAPARAMS,
			gphNfcLib_State.bHalBufferTx,
			PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE,
			gphNfcLib_State.bHalBufferRx,
			PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE
			));
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

	}

	return PH_NFCLIB_STATUS_SUCCESS;
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_Init_PAL_Init(void)
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			== eNfcLib_ResetState) {
		/* Perform Reader Library PAL Initialization */
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phNfcLib_PAL_Init());
	}

	return PH_NFCLIB_STATUS_SUCCESS;
}


FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_Init_AL_Init(void)
{
	VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			== eNfcLib_ResetState) {
		/* Perform Reader Library AL Initialization */
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phNfcLib_AL_Init());
	}

	return PH_NFCLIB_STATUS_SUCCESS;
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_Init_DiscLoop_Sw_Init(void) {
#if defined (NXPBUILD__PHCE_T4T_SW) || defined(NXPBUILD__PH_KEYSTORE_SW) || defined(NXPBUILD__PHAC_DISCLOOP_SW)
  VAR(phStatus_t, ANFCRL_VAR) wStatus = PH_ERR_SUCCESS;
#endif

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			== eNfcLib_ResetState) {
		/* Initialize the HCE component */
#ifdef NXPBUILD__PHCE_T4T_SW
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phceT4T_Sw_Init(
						&gphNfcLib_Params.sceT4T,
						(uint16)(sizeof(phceT4T_Sw_DataParams_t)),
						&gphNfcLib_Params.spalI14443p4mC,
						aAppHCEBuf,
						PH_NXPNFCRDLIB_CONFIG_HCE_BUFF_LENGTH));
#endif /* NXPBUILD__PHCE_T4T_SW */

#ifdef NXPBUILD__PH_KEYSTORE_SW
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phKeyStore_Sw_Init(
						&gphNfcLib_Params.sKeyStore,
						(uint16)(sizeof(phKeyStore_Sw_DataParams_t)),
						&gpKeyEntries[0], NUMBER_OF_KEYENTRIES,
						&gpKeyVersionPairs[0], NUMBER_OF_KEYVERSIONPAIRS,
						&gpKUCEntries[0], NUMBER_OF_KUCENTRIES));

		/* load a Key to the Store */
		/* Note: If You use Key number 0x00, be aware that in SAM
		 this Key is the 'Host authentication key' !!! */
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phKeyStore_FormatKeyEntry(
				&gphNfcLib_Params.sKeyStore, 1, 0x6));

		/* Set Key Store */
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phKeyStore_SetKey(
				&gphNfcLib_Params.sKeyStore, 1, 0, 0x6, &gphNfcLib_Key[0], 0));
#endif /* NXPBUILD__PH_KEYSTORE_SW */

		/* Initialize the discover component */
#ifdef NXPBUILD__PHAC_DISCLOOP_SW
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus, phacDiscLoop_Sw_Init(&gphNfcLib_Params.sDiscLoop,
							(uint16 )(sizeof(phacDiscLoop_Sw_DataParams_t)),
							&gphNfcLib_Params.sHal));

		/* Assign other layer parameters in discovery loop */
		gphNfcLib_Params.sDiscLoop.pHalDataParams = &gphNfcLib_Params.sHal;

#	ifdef NXPBUILD__PHPAL_I14443P3A_SW
		gphNfcLib_Params.sDiscLoop.pPal1443p3aDataParams =
				&gphNfcLib_Params.spalI14443p3a;
#	endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#	ifdef NXPBUILD__PHPAL_I14443P3B_SW
		gphNfcLib_Params.sDiscLoop.pPal1443p3bDataParams =
				&gphNfcLib_Params.spalI14443p3b;
#	endif /* NXPBUILD__PHPAL_I14443P3B_SW */

#	ifdef NXPBUILD__PHPAL_I14443P4A_SW
		gphNfcLib_Params.sDiscLoop.pPal1443p4aDataParams =
				&gphNfcLib_Params.spalI14443p4a;
#	endif /* NXPBUILD__PHPAL_I14443P4A_SW */

#	ifdef NXPBUILD__PHPAL_I14443P4_SW
		gphNfcLib_Params.sDiscLoop.pPal14443p4DataParams =
				&gphNfcLib_Params.spalI14443p4;
#	endif /* NXPBUILD__PHPAL_I14443P4_SW */

#	ifdef NXPBUILD__PHPAL_FELICA_SW
		gphNfcLib_Params.sDiscLoop.pPalFelicaDataParams =
				&gphNfcLib_Params.spalFelica;
#	endif /* NXPBUILD__PHPAL_FELICA_SW */

#	ifdef NXPBUILD__PHPAL_SLI15693_SW
		gphNfcLib_Params.sDiscLoop.pPalSli15693DataParams =
				&gphNfcLib_Params.spalSli15693;
#	endif /* NXPBUILD__PHPAL_SLI15693_SW */

#endif /* NXPBUILD__PHAC_DISCLOOP_SW */
		gphNfcLib_State.bNfcLibState = eNfcLib_InitializedState;
		gphNfcLib_State.bProfileSelected = PH_NFCLIB_ACTIVATION_PROFILE_NFC;
		gphNfcLib_State.wConfiguredRFTech = PH_NFCLIB_TECHNOLOGY_DEFAULT;
		gphNfcLib_State.bActivateBlocking =
				PH_NFCLIB_ACTIVATION_BLOCKINGMODE_DEFAULT;
		gphNfcLib_State.bDeactBlocking =
				PH_NFCLIB_DEACTIVATION_BLOCKINGMODE_DEFAULT;
		gphNfcLib_State.bLPCDState = PH_OFF;
		gphNfcLib_State.bTxState = PH_NFCLIB_INT_TRANSMIT_OFF;
		gphNfcLib_State.bMergedSakPrio =
				PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_14443;
		gphNfcLib_State.bAuthMode = PH_NFCLIB_MFDF_NOT_AUTHENTICATED;
		gphNfcLib_Params.pNfcLib_ErrCallbck = NULL;
	}
	return PH_NFCLIB_STATUS_SUCCESS;
}

FUNC(phNfcLib_Status_t, ANFCRL_CODE) phNfcLib_DeInit(void) {
  VAR(phNfcLib_Status_t, ANFCRL_VAR) dwStatus = PH_NFCLIB_STATUS_INVALID_STATE;
  VAR(phStatus_t, ANFCRL_VAR) wStatus;

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			== eNfcLib_InitializedState) {
		/* Perform HAL De-Init */
		PH_CHECK_NFCLIB_SUCCESS_FCT(wStatus,
				phhalHw_DeInit(&gphNfcLib_Params.sHal));

		gphNfcLib_State.bNfcLibState = eNfcLib_ResetState;
		gphNfcLib_State.bProfileSelected = PH_NFCLIB_ACTIVATION_PROFILE_NFC;
		gphNfcLib_State.wConfiguredRFTech = PH_NFCLIB_TECHNOLOGY_DEFAULT;
		gphNfcLib_State.bActivateBlocking =
				PH_NFCLIB_ACTIVATION_BLOCKINGMODE_DEFAULT;
		gphNfcLib_State.bDeactBlocking =
				PH_NFCLIB_DEACTIVATION_BLOCKINGMODE_DEFAULT;
		gphNfcLib_State.bLPCDState = PH_OFF;
		gphNfcLib_State.bTxState = PH_NFCLIB_INT_TRANSMIT_OFF;
		gphNfcLib_State.bMergedSakPrio =
				PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_14443;
		gphNfcLib_State.bAuthMode = PH_NFCLIB_MFDF_NOT_AUTHENTICATED;
		gphNfcLib_Params.pNfcLib_ErrCallbck = NULL;

		dwStatus = PH_NFCLIB_STATUS_SUCCESS;
	}

	return dwStatus;
}

FUNC(void*, ANFCRL_CODE) phNfcLib_GetDataParams (VAR(uint16, ANFCRL_VAR) wComponent) {
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataparam = NULL;

	if (((phNfcLib_StateMachine_t) gphNfcLib_State.bNfcLibState)
			!= eNfcLib_ResetState) {
		switch (wComponent) {
#ifdef NXPBUILD__PHHAL_HW
		case PH_COMP_HAL:
			pDataparam = (void *) &gphNfcLib_Params.sHal;
			break;
#endif /* NXPBUILD__PHHAL_HW */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW
		case PH_COMP_PAL_ISO14443P3A:
			pDataparam = (void *) &gphNfcLib_Params.spalI14443p3a;
			break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW
		case PH_COMP_PAL_ISO14443P3B:
			pDataparam = (void *) &gphNfcLib_Params.spalI14443p3b;
			break;
#endif /* NXPBUILD__PHPAL_I14443P3B_SW */

#ifdef NXPBUILD__PHPAL_I14443P4A_SW
		case PH_COMP_PAL_ISO14443P4A:
			pDataparam = (void *) &gphNfcLib_Params.spalI14443p4a;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4A_SW */

#ifdef NXPBUILD__PHPAL_I14443P4_SW
		case PH_COMP_PAL_ISO14443P4:
			pDataparam = (void *) &gphNfcLib_Params.spalI14443p4;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW */

#ifdef NXPBUILD__PHPAL_MIFARE_SW
			case PH_COMP_PAL_MIFARE:
			pDataparam = (void *) &gphNfcLib_Params.spalMifare;
			break;
#endif /* NXPBUILD__PHPAL_MIFARE_SW */

#ifdef NXPBUILD__PHPAL_SLI15693_SW
		case PH_COMP_PAL_SLI15693:
			pDataparam = (void *) &gphNfcLib_Params.spalSli15693;
			break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW*/

#ifdef NXPBUILD__PHPAL_FELICA_SW
		case PH_COMP_PAL_FELICA:
			pDataparam = (void *) &gphNfcLib_Params.spalFelica;
			break;
#endif /* NXPBUILD__PHPAL_FELICA_SW */

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW
			case PH_COMP_PAL_I14443P4MC:
			pDataparam = (void *) &gphNfcLib_Params.spalI14443p4mC;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW */

#ifdef NXPBUILD__PHAL_MFDF_SW
			case PH_COMP_AL_MFDF:
			pDataparam = (void *) &gphNfcLib_Params.salMFDF;
			break;
#endif /* NXPBUILD__PHAL_MFDF_SW */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW
			case PH_COMP_AL_MFDFEVX:
			pDataparam = (void *) &gphNfcLib_Params.salMFDFEVx;
			break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW */

#ifdef NXPBUILD__PHAL_FELICA_SW
		case PH_COMP_AL_FELICA:
			pDataparam = (void *) &gphNfcLib_Params.salFelica;
			break;
#endif /* NXPBUILD__PHAL_FELICA_SW */

#ifdef NXPBUILD__PHAL_ICODE_SW
		case PH_COMP_AL_ICODE:
			pDataparam = (void *) &gphNfcLib_Params.salICode;
			break;
#endif /* NXPBUILD__PHAL_ICODE_SW */

#ifdef NXPBUILD__PHAC_DISCLOOP_SW
		case PH_COMP_AC_DISCLOOP:
			pDataparam = (void *) &gphNfcLib_Params.sDiscLoop;
			break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW */

#ifdef NXPBUILD__PHCE_T4T_SW
			case PH_COMP_CE_T4T:
			pDataparam = (void *) &gphNfcLib_Params.sceT4T;
			break;
#endif /* NXPBUILD__PHCE_T4T_SW */

#if defined(NXPBUILD__PH_KEYSTORE_SW) || defined(NXPBUILD__PH_KEYSTORE_NCx3320)
		case PH_COMP_KEYSTORE:
			pDataparam = (void *) &gphNfcLib_Params.sKeyStore;
			break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW
		case PH_COMP_CRYPTOSYM:
			pDataparam = (void *) &gphNfcLib_Params.sCryptoSym;
			break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW */

#ifdef NXPBUILD__PH_CRYPTORNG_SW
			case PH_COMP_CRYPTORNG:
			pDataparam = (void *) &gphNfcLib_Params.sCryptoRng;
			break;
#endif /* NXPBUILD__PH_CRYPTORNG_SW */

		default:
			/* Do nothing. pDataparam is already null. */
			break;
		}
	}
	return pDataparam;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB */

#ifdef __cplusplus
}
#endif
