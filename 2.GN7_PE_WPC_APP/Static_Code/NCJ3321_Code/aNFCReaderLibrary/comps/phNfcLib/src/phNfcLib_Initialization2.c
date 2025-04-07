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
*   @file    phNfcLib_Initialization2.c
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
#include <ph_Status2.h>

#ifdef NXPBUILD__PHNFCLIB2
#include "phNfcLib_Initialization2.h"
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phNfcLib_Initialization2.c
* @implements     DESIGN001, DESIGN002
*/
#define PHNFCLIB_INITIALIZATION_VENDOR_ID_C2                      43           /**< @brief AUTOSAR vendor ID*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2       4            /**< @brief AUTOSAR release major version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2       3            /**< @brief AUTOSAR release minor version*/
#define PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION_C2    1            /**< @brief AUTOSAR release revision*/
#define PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION_C2               1            /**< @brief The major version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION_C2               0            /**< @brief The minor version of the SW module*/
#define PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION_C2               0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/

/* Check if current file and phNfcLib_Initialization.h header file are of the same vendor */
#if (PHNFCLIB_INITIALIZATION_VENDOR_ID_C2 != PHNFCLIB_INITIALIZATION_VENDOR_ID2)
    #error "phNfcLib_Initialization2.c and phNfcLib_Initialization.h have different vendor ids"
#endif
/* Check if current file and phNfcLib_Initialization.h header file are of the same Autosar version */
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2    != PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION2) || \
     (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2    != PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION2) || \
     (PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION_C2 != PHNFCLIB_INITIALIZATION_AR_RELEASE_REVISION_VERSION2))
    #error "AutoSar Version Numbers of phNfcLib_Initialization2.c and phNfcLib_Initialization.h are different"
#endif
/* Check if current file and phNfcLib_Initialization.h header file are of the same Software version */
#if ((PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION_C2 != PHNFCLIB_INITIALIZATION_SW_MAJOR_VERSION2) || \
     (PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION_C2 != PHNFCLIB_INITIALIZATION_SW_MINOR_VERSION2) || \
     (PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION_C2 != PHNFCLIB_INITIALIZATION_SW_PATCH_VERSION2))
    #error "Software Version Numbers of phNfcLib_Initialization2.c and phNfcLib_Initialization.h are different"
#endif
#endif /* NXPBUILD__PHNFCLIB2 */
/** @} */
/*==================================================================================================
*                          LOCAL TYPEDEFS (STRUCTURES, UNIONS, ENUMS)
==================================================================================================*/


/*==================================================================================================
*                                       LOCAL MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHNFCLIB2
#if defined (NXPBUILD__PH_KEYSTORE_SW2) || defined(NXPBUILD__PH_KEYSTORE_NCx33202)
#define PH_NFCLIB_KEYSTORE_DATAPARAMS2    (&gphNfcLib_Params2.sKeyStore2)
#else
#define PH_NFCLIB_KEYSTORE_DATAPARAMS2 (NULL)
#endif

#ifdef NXPBUILD__PH_KEYSTORE_SW2
/**
 * Parameter for Keystore
 * Defines the number of key entries and key version pairs in sw keystore
 */
#define NUMBER_OF_KEYENTRIES2        2u
#define NUMBER_OF_KEYVERSIONPAIRS2   2u
#define NUMBER_OF_KUCENTRIES2        1u
#endif /* NXPBUILD__PH_KEYSTORE_SW2 */

#define PH_CHECK_NFCLIB_INIT_FCT2(status2,fct2)  {(status2) = (fct2); PH_BREAK_ON_FAILURE2(status2);}

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
#define SEED_COUNT_MFDF2      0x08
#define IID_KEY_COUNT2   0x13U   /* number of IID keys */
#define TMI_BUFFER_SIZE2 255     /* TMI Buffer Size */
#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4_SW2
#   define PTR_spalI14443p42 (&gphNfcLib_Params2.spalI14443p42)
#else
#   define PTR_spalI14443p42 NULL
#endif

#ifdef NXPBUILD__PH_KEYSTORE_SW2
#   define PTR_sKeyStore2 (&gphNfcLib_Params2.sKeyStore2)
#else
#   define PTR_sKeyStore2 NULL
#endif

#ifdef NXPBUILD__PH_CRYPTOSYM_SW2
#   define PTR_sCryptoSym2 (&gphNfcLib_Params2.sCryptoSym2)
#else
#   define PTR_sCryptoSym2 NULL
#endif

#ifdef NXPBUILD__PH_CRYPTORNG_SW2
#   define PTR_sCryptoRng2 (&gphNfcLib_Params2.sCryptoRng2)
#else
#   define PTR_sCryptoRng2 NULL
#endif

#ifdef NXPBUILD__PHAL_FELICA_SW2
#   define PTR_salFelica2 (&gphNfcLib_Params2.salFelica2)
#else
#   define PTR_salFelica2 NULL
#endif

#ifdef NXPBUILD__PHAL_MFDF_SW2
#   define PTR_salMFDF2 (&gphNfcLib_Params2.salMFDF2)
#else
#   define PTR_salMFDF2 NULL
#endif

#ifdef NXPBUILD__PHAL_ICODE_SW2
#   define PTR_salICode2 (&gphNfcLib_Params2.salICode2)
#else
#   define PTR_salICode2 NULL
#endif

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
#   define PTR_spalI14443p3a2 (&gphNfcLib_Params2.spalI14443p3a2)
#else
#   define PTR_spalI14443p3a2 NULL
#endif
/*==================================================================================================
*                                      LOCAL CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      LOCAL VARIABLES
==================================================================================================*/
#define ANFCRL_START_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
static VAR(phalVca_Sw_IidTableEntry_t2, ANFCRL_VAR) astIidTableEntry2[IID_KEY_COUNT2];  /**< Pointer to the Iid Table storage for the layer. */
static VAR(phalVca_Sw_CardTableEntry_t2, ANFCRL_VAR) astCardTableEntry2[IID_KEY_COUNT2];/**< Pointer to the Card Table storage for the layer. */

static VAR(phCryptoSym_Sw_DataParams_t2, ANFCRL_VAR) sCryptoEnc2;
static VAR(phCryptoSym_Sw_DataParams_t2, ANFCRL_VAR) sCryptoMac2;
static VAR(phCryptoSym_Sw_DataParams_t2, ANFCRL_VAR) sCryptoSymRng2;
static VAR(phCryptoRng_Sw_DataParams_t2, ANFCRL_VAR) sCryptoRngVar2;
static VAR(phTMIUtils_t, ANFCRL_VAR) sTMI2;
static VAR(phalVca_Sw_DataParams_t2, ANFCRL_VAR) sVca2;

static VAR(uint8, ANFCRL_VAR) aSeed_MFDF2[SEED_COUNT_MFDF2];
static VAR(uint8, ANFCRL_VAR) aTmi_Buffer2[TMI_BUFFER_SIZE2];
#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

#ifdef NXPBUILD__PH_KEYSTORE_SW2
/**
 * SW Key Structure Pointers
 */

static VAR(phKeyStore_Sw_KeyEntry_t2, ANFCRL_VAR) gpKeyEntries2[NUMBER_OF_KEYENTRIES2];
static VAR(phKeyStore_Sw_KeyVersionPair_t2, ANFCRL_VAR) gpKeyVersionPairs2[NUMBER_OF_KEYVERSIONPAIRS2 * NUMBER_OF_KEYENTRIES2];
static VAR(phKeyStore_Sw_KUCEntry_t2, ANFCRL_VAR) gpKUCEntries2[NUMBER_OF_KUCENTRIES2];
#endif /* NXPBUILD__PH_KEYSTORE_SW2 */

#ifdef NXPBUILD__PHCE_T4T_SW2
/**
 * Application buffer. Used in phceT4T_Init. Its needed for data exchange
 * between application thread and reader library thread. Refer phceT4T_Init in
 * phceT4T.h for more info.
 * */
static VAR(uint8, ANFCRL_VAR) aAppHCEBuf2[PH_NXPNFCRDLIB_CONFIG_HCE_BUFF_LENGTH2];
#endif /* NXPBUILD__PHCE_T4T_SW2 */

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#define ANFCRL_START_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
static VAR(uint16, ANFCRL_VAR) wNumIidTableStorageEntriesVar2 = IID_KEY_COUNT2;         /**< Number of possible Iid table entries in the storage. */
static VAR(uint16, ANFCRL_VAR) wNumCardTableStorageEntriesVar2 = IID_KEY_COUNT2;        /**< Number of possible Card table entries in the storage. */
#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

#ifdef NXPBUILD__PH_KEYSTORE_SW2
/* Set the key for the MIFARE (R) Classic cards. */
static VAR(uint8, ANFCRL_VAR) gphNfcLib_Key2[6] = { 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU, 0xFFU };
#endif /* NXPBUILD__PH_KEYSTORE_SW2 */

#define ANFCRL_STOP_SEC_VAR_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
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
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

VAR(phNfcLib_DataParams_t2, ANFCRL_VAR) gphNfcLib_Params2;
VAR(phNfcLib_InternalState_t2, ANFCRL_VAR) gphNfcLib_State2;

#define ANFCRL_STOP_SEC_VAR_NO_INIT_UNSPECIFIED
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif
/*==================================================================================================
*                                   LOCAL FUNCTION PROTOTYPES
==================================================================================================*/

#define ANFCRL_START_SEC_CODE
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * This function will initialize Reader Library PAL Components
 */
static FUNC(phStatus_t2, ANFCRL_CODE) phNfcLib_PAL_Init2(void);

/**
 * This function will initialize Reader Library AL Components
 */
static FUNC(phStatus_t2, ANFCRL_CODE) phNfcLib_AL_Init2(void);

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_SetContext2(P2VAR(phNfcLib_AppContext_t2, AUTOMATIC, ANFCRL_APPL_DATA) pAppContext2)
{
    if (pAppContext2 == NULL)
    {
        return PH_NFCLIB_STATUS_INVALID_PARAMETER2;
    }

	gphNfcLib_Params2.pBal2 = pAppContext2->pBalDataparams2;
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
	gphNfcLib_Params2.pWtxCallback2 = pAppContext2->pWtxCallback2;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

#ifdef NXPBUILD__PHHAL_HW_NCX33212
	gphNfcLib_Params2.sHal2.pHalPollFunc2 = pAppContext2->pHalPollFunc2;
#endif /*NXPBUILD__PHHAL_HW_NCX33212*/

	return PH_NFCLIB_STATUS_SUCCESS2;
}

/**
 * This function will initialize Reader Library PAL Components
 */
static FUNC(phStatus_t2, ANFCRL_CODE) phNfcLib_PAL_Init2(void) {
  VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;

	/* Initialize the I14443-3A PAL layer */
#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalI14443p3a_Sw_Init2(&gphNfcLib_Params2.spalI14443p3a2,
						(uint16 )(sizeof(phpalI14443p3a_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

		/* Initialize the I14443-3B PAL  component */
#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalI14443p3b_Sw_Init2(&gphNfcLib_Params2.spalI14443p3b2,
						(uint16 )(sizeof(phpalI14443p3b_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

		/* Initialize the I14443-4A PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalI14443p4a_Sw_Init2(&gphNfcLib_Params2.spalI14443p4a2,
						(uint16 )(sizeof(phpalI14443p4a_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

		/* Initialize the I14443-4 PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalI14443p4_Sw_Init2(&gphNfcLib_Params2.spalI14443p42,
						(uint16 )(sizeof(phpalI14443p4_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

		/* Initialize the Mifare PAL component */
#ifdef NXPBUILD__PHPAL_MIFARE_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2, phpalMifare_Sw_Init2(
						&gphNfcLib_Params2.spalMifare2,
						(uint16)(sizeof(phpalMifare_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2,
						PTR_spalI14443p42
				));
#endif /* NXPBUILD__PHPAL_MIFARE_SW2 */

		/* Initialize PAL Felica PAL component */
#ifdef NXPBUILD__PHPAL_FELICA_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalFelica_Sw_Init2(&gphNfcLib_Params2.spalFelica2,
						(uint16 )(sizeof(phpalFelica_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

		/* Initialize the 15693 PAL component */
#ifdef NXPBUILD__PHPAL_SLI15693_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalSli15693_Sw_Init2(&gphNfcLib_Params2.spalSli156932,
						(uint16 )(sizeof(phpalSli15693_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2));
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

		/* Initialize 14443-4mC Target PAL component */
#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phpalI14443p4mC_Sw_Init2(
						&gphNfcLib_Params2.spalI14443p4mC2,
						(uint16)(sizeof(phpalI14443p4mC_Sw_DataParams_t2)),
						&gphNfcLib_Params2.sHal2,
						gphNfcLib_Params2.pWtxCallback2
				));
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

	return wStatus2;
}

/**
 * This function will initialize the Reader Library AL Components
 */
static FUNC(phStatus_t2, ANFCRL_CODE) phNfcLib_AL_Init2(void) {
  VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;

		/* Initialize AL Felica component */
#ifdef NXPBUILD__PHAL_FELICA_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalFelica_Sw_Init2( &gphNfcLib_Params2.salFelica2,
						(uint16)(sizeof(phalFelica_Sw_DataParams_t2)),
						&gphNfcLib_Params2.spalFelica2,
						PTR_sCryptoSym2));
#endif /* NXPBUILD__PHAL_FELICA_SW2 */

		/* Initialize AL Mifare DESFire component */
#ifdef NXPBUILD__PHAL_MFDF_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalMfdf_Sw_Init2(
						&gphNfcLib_Params2.salMFDF2,
						(uint16)(sizeof(phalMfdf_Sw_DataParams_t2)),
						&gphNfcLib_Params2.spalMifare2,
						PTR_sKeyStore2,
						PTR_sCryptoSym2,
						PTR_sCryptoRng2,
						&gphNfcLib_Params2.sHal2
				));
#endif /* NXPBUILD__PHAL_MFDF_SW2 */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
        /* init. crypto */
	PH_CHECK_SUCCESS_FCT2(wStatus2,phCryptoSym_Sw_Init2(
            &sCryptoEnc2,
			(uint16) sizeof(phCryptoSym_Sw_DataParams_t2),
            &gphNfcLib_Params2.sKeyStore2));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phCryptoSym_Sw_Init2(
				&sCryptoMac2,
				(uint16) sizeof(phCryptoSym_Sw_DataParams_t2),
				&gphNfcLib_Params2.sKeyStore2));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phCryptoSym_Sw_Init2(
				&sCryptoSymRng2,
				(uint16) sizeof(phCryptoSym_Sw_DataParams_t2),
				&gphNfcLib_Params2.sKeyStore2));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phCryptoRng_Sw_Init2(
				&sCryptoRngVar2,
				(uint16) sizeof(phCryptoRng_Sw_DataParams_t2),
				&sCryptoSymRng2));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phCryptoRng_Seed2(
				&sCryptoRngVar2,
				aSeed_MFDF2,
				8));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phTMIUtils_Init2(
				&sTMI2,
				&aTmi_Buffer2[0],
				TMI_BUFFER_SIZE2));

        /* Initialize the VCA component */
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalVca_Sw_Init2(
				&sVca2,
				(uint16) sizeof(phalVca_Sw_DataParams_t2),
				&gphNfcLib_Params2.spalMifare2,
				&gphNfcLib_Params2.sKeyStore2,
				&sCryptoEnc2,
				&sCryptoRngVar2,
				astIidTableEntry2,
				wNumIidTableStorageEntriesVar2,
				astCardTableEntry2,
				wNumCardTableStorageEntriesVar2
				));

        /* Initialize the MIFARE DESFire EV2 contactless IC component */
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalMfdfEVx_Sw_Init2(
				&gphNfcLib_Params2.salMFDFEVx2,
				(uint16) sizeof(phalMfdfEVx_Sw_DataParams_t2),
				&gphNfcLib_Params2.spalMifare2,
				&gphNfcLib_Params2.sKeyStore2,
				&sCryptoEnc2,
				&sCryptoMac2,
				&sCryptoRngVar2,
				&sTMI2,
				&sVca2,
				&gphNfcLib_Params2.sHal2));
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalVca_SetApplicationType2(
				&sVca2,
				&gphNfcLib_Params2.salMFDFEVx2));
#endif  /* NXPBUILD__PHAL_MFDFEVX_SW2 */

		/* Initialize the ISO ICODE AL component */
#ifdef NXPBUILD__PHAL_ICODE_SW2
	PH_CHECK_SUCCESS_FCT2(wStatus2,phalICode_Sw_Init2( &gphNfcLib_Params2.salICode2, (uint16)(sizeof(phalICode_Sw_DataParams_t2)), &gphNfcLib_Params2.spalSli156932, NULL, NULL, NULL));
#endif /* NXPBUILD__PHAL_ICODE_SW2 */

	return wStatus2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_Ncx3321_Init2(void)
{
  VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			== eNfcLib_ResetState2) {
#ifdef NXPBUILD__PHHAL_HW_NCX33212
		/* Initialize the Ncx3321 HAL component */
		PH_CHECK_SUCCESS_FCT2(wStatus2, phhalHw_Ncx3321_Init2(
			&gphNfcLib_Params2.sHal2,
			(uint16)(sizeof(phhalHw_Ncx3321_DataParams_t2)),
			gphNfcLib_Params2.pBal2,
			PH_NFCLIB_KEYSTORE_DATAPARAMS2,
			gphNfcLib_State2.bHalBufferTx2,
			PH_NXPNFCRDLIB_CONFIG_HAL_TX_BUFFSIZE2,
			gphNfcLib_State2.bHalBufferRx2,
			PH_NXPNFCRDLIB_CONFIG_HAL_RX_BUFFSIZE2
			));
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

	}

	return PH_NFCLIB_STATUS_SUCCESS2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_PAL_Init2(void)
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			== eNfcLib_ResetState2) {
		/* Perform Reader Library PAL Initialization */
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phNfcLib_PAL_Init2());
	}

	return PH_NFCLIB_STATUS_SUCCESS2;
}


FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_AL_Init2(void)
{
	VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			== eNfcLib_ResetState2) {
		/* Perform Reader Library AL Initialization */
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phNfcLib_AL_Init2());
	}

	return PH_NFCLIB_STATUS_SUCCESS2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_Init_DiscLoop_Sw_Init2(void) {
#if defined (NXPBUILD__PHCE_T4T_SW2) || defined(NXPBUILD__PH_KEYSTORE_SW2) || defined(NXPBUILD__PHAC_DISCLOOP_SW2)
  VAR(phStatus_t2, ANFCRL_VAR) wStatus2 = PH_ERR_SUCCESS2;
#endif

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			== eNfcLib_ResetState2) {
		/* Initialize the HCE component */
#ifdef NXPBUILD__PHCE_T4T_SW2
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phceT4T_Sw_Init2(
						&gphNfcLib_Params2.sceT4T2,
						(uint16)(sizeof(phceT4T_Sw_DataParams_t2)),
						&gphNfcLib_Params2.spalI14443p4mC2,
						aAppHCEBuf2,
						PH_NXPNFCRDLIB_CONFIG_HCE_BUFF_LENGTH2));
#endif /* NXPBUILD__PHCE_T4T_SW2 */

#ifdef NXPBUILD__PH_KEYSTORE_SW2
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phKeyStore_Sw_Init2(
						&gphNfcLib_Params2.sKeyStore2,
						(uint16)(sizeof(phKeyStore_Sw_DataParams_t2)),
						&gpKeyEntries2[0], NUMBER_OF_KEYENTRIES2,
						&gpKeyVersionPairs2[0], NUMBER_OF_KEYVERSIONPAIRS2,
						&gpKUCEntries2[0], NUMBER_OF_KUCENTRIES2));

		/* load a Key to the Store */
		/* Note: If You use Key number 0x00, be aware that in SAM
		 this Key is the 'Host authentication key' !!! */
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phKeyStore_FormatKeyEntry2(
				&gphNfcLib_Params2.sKeyStore2, 1, 0x6));

		/* Set Key Store */
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phKeyStore_SetKey2(
				&gphNfcLib_Params2.sKeyStore2, 1, 0, 0x6, &gphNfcLib_Key2[0], 0));
#endif /* NXPBUILD__PH_KEYSTORE_SW2 */

		/* Initialize the discover component */
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2, phacDiscLoop_Sw_Init2(&gphNfcLib_Params2.sDiscLoop2,
							(uint16 )(sizeof(phacDiscLoop_Sw_DataParams_t2)),
							&gphNfcLib_Params2.sHal2));

		/* Assign other layer parameters in discovery loop */
		gphNfcLib_Params2.sDiscLoop2.pHalDataParams2 = &gphNfcLib_Params2.sHal2;

#	ifdef NXPBUILD__PHPAL_I14443P3A_SW2
		gphNfcLib_Params2.sDiscLoop2.pPal1443p3aDataParams2 =
				&gphNfcLib_Params2.spalI14443p3a2;
#	endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#	ifdef NXPBUILD__PHPAL_I14443P3B_SW2
		gphNfcLib_Params2.sDiscLoop2.pPal1443p3bDataParams2 =
				&gphNfcLib_Params2.spalI14443p3b2;
#	endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#	ifdef NXPBUILD__PHPAL_I14443P4A_SW2
		gphNfcLib_Params2.sDiscLoop2.pPal1443p4aDataParams2 =
				&gphNfcLib_Params2.spalI14443p4a2;
#	endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#	ifdef NXPBUILD__PHPAL_I14443P4_SW2
		gphNfcLib_Params2.sDiscLoop2.pPal14443p4DataParams2 =
				&gphNfcLib_Params2.spalI14443p42;
#	endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

#	ifdef NXPBUILD__PHPAL_FELICA_SW2
		gphNfcLib_Params2.sDiscLoop2.pPalFelicaDataParams2 =
				&gphNfcLib_Params2.spalFelica2;
#	endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#	ifdef NXPBUILD__PHPAL_SLI15693_SW2
		gphNfcLib_Params2.sDiscLoop2.pPalSli15693DataParams2 =
				&gphNfcLib_Params2.spalSli156932;
#	endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */
		gphNfcLib_State2.bNfcLibState2 = eNfcLib_InitializedState2;
		gphNfcLib_State2.bProfileSelected2 = PH_NFCLIB_ACTIVATION_PROFILE_NFC2;
		gphNfcLib_State2.wConfiguredRFTech2 = PH_NFCLIB_TECHNOLOGY_DEFAULT2;
		gphNfcLib_State2.bActivateBlocking2 =
				PH_NFCLIB_ACTIVATION_BLOCKINGMODE_DEFAULT2;
		gphNfcLib_State2.bDeactBlocking2 =
				PH_NFCLIB_DEACTIVATION_BLOCKINGMODE_DEFAULT2;
		gphNfcLib_State2.bLPCDState2 = PH_OFF2;
		gphNfcLib_State2.bTxState2 = PH_NFCLIB_INT_TRANSMIT_OFF2;
		gphNfcLib_State2.bMergedSakPrio2 =
				PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432;
		gphNfcLib_State2.bAuthMode2 = PH_NFCLIB_MFDF_NOT_AUTHENTICATED2;
		gphNfcLib_Params2.pNfcLib_ErrCallbck2 = NULL;
	}
	return PH_NFCLIB_STATUS_SUCCESS2;
}

FUNC(phNfcLib_Status_t2, ANFCRL_CODE) phNfcLib_DeInit2(void) {
  VAR(phNfcLib_Status_t2, ANFCRL_VAR) dwStatus2 = PH_NFCLIB_STATUS_INVALID_STATE2;
  VAR(phStatus_t2, ANFCRL_VAR) wStatus2;

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			== eNfcLib_InitializedState2) {
		/* Perform HAL De-Init */
		PH_CHECK_NFCLIB_SUCCESS_FCT2(wStatus2,
				phhalHw_DeInit2(&gphNfcLib_Params2.sHal2));

		gphNfcLib_State2.bNfcLibState2 = eNfcLib_ResetState2;
		gphNfcLib_State2.bProfileSelected2 = PH_NFCLIB_ACTIVATION_PROFILE_NFC2;
		gphNfcLib_State2.wConfiguredRFTech2 = PH_NFCLIB_TECHNOLOGY_DEFAULT2;
		gphNfcLib_State2.bActivateBlocking2 =
				PH_NFCLIB_ACTIVATION_BLOCKINGMODE_DEFAULT2;
		gphNfcLib_State2.bDeactBlocking2 =
				PH_NFCLIB_DEACTIVATION_BLOCKINGMODE_DEFAULT2;
		gphNfcLib_State2.bLPCDState2 = PH_OFF2;
		gphNfcLib_State2.bTxState2 = PH_NFCLIB_INT_TRANSMIT_OFF2;
		gphNfcLib_State2.bMergedSakPrio2 =
				PH_NFCLIB_ACTIVATION_MERGED_SAK_PRIO_144432;
		gphNfcLib_State2.bAuthMode2 = PH_NFCLIB_MFDF_NOT_AUTHENTICATED2;
		gphNfcLib_Params2.pNfcLib_ErrCallbck2 = NULL;

		dwStatus2 = PH_NFCLIB_STATUS_SUCCESS2;
	}

	return dwStatus2;
}

FUNC(void*, ANFCRL_CODE) phNfcLib_GetDataParams2 (VAR(uint16, ANFCRL_VAR) wComponent2) {
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataparam2 = NULL;

	if (((phNfcLib_StateMachine_t2) gphNfcLib_State2.bNfcLibState2)
			!= eNfcLib_ResetState2) {
		switch (wComponent2) {
#ifdef NXPBUILD__PHHAL_HW2
		case PH_COMP_HAL2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sHal2;
			break;
#endif /* NXPBUILD__PHHAL_HW2 */

#ifdef NXPBUILD__PHPAL_I14443P3A_SW2
		case PH_COMP_PAL_ISO14443P3A2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalI14443p3a2;
			break;
#endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P3B_SW2
		case PH_COMP_PAL_ISO14443P3B2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalI14443p3b2;
			break;
#endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4A_SW2
		case PH_COMP_PAL_ISO14443P4A2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalI14443p4a2;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4A_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4_SW2
		case PH_COMP_PAL_ISO14443P42:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalI14443p42;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4_SW2 */

#ifdef NXPBUILD__PHPAL_MIFARE_SW2
			case PH_COMP_PAL_MIFARE2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalMifare2;
			break;
#endif /* NXPBUILD__PHPAL_MIFARE_SW2 */

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
		case PH_COMP_PAL_SLI156932:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalSli156932;
			break;
#endif /* NXPBUILD__PHPAL_SLI15693_SW2*/

#ifdef NXPBUILD__PHPAL_FELICA_SW2
		case PH_COMP_PAL_FELICA2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalFelica2;
			break;
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
			case PH_COMP_PAL_I14443P4MC2:
			pDataparam2 = (void *) &gphNfcLib_Params2.spalI14443p4mC2;
			break;
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

#ifdef NXPBUILD__PHAL_MFDF_SW2
			case PH_COMP_AL_MFDF2:
			pDataparam2 = (void *) &gphNfcLib_Params2.salMFDF2;
			break;
#endif /* NXPBUILD__PHAL_MFDF_SW2 */

#ifdef NXPBUILD__PHAL_MFDFEVX_SW2
			case PH_COMP_AL_MFDFEVX2:
			pDataparam2 = (void *) &gphNfcLib_Params2.salMFDFEVx2;
			break;
#endif /* NXPBUILD__PHAL_MFDFEVX_SW2 */

#ifdef NXPBUILD__PHAL_FELICA_SW2
		case PH_COMP_AL_FELICA2:
			pDataparam2 = (void *) &gphNfcLib_Params2.salFelica2;
			break;
#endif /* NXPBUILD__PHAL_FELICA_SW2 */

#ifdef NXPBUILD__PHAL_ICODE_SW2
		case PH_COMP_AL_ICODE2:
			pDataparam2 = (void *) &gphNfcLib_Params2.salICode2;
			break;
#endif /* NXPBUILD__PHAL_ICODE_SW2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
		case PH_COMP_AC_DISCLOOP2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sDiscLoop2;
			break;
#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef NXPBUILD__PHCE_T4T_SW2
			case PH_COMP_CE_T4T2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sceT4T2;
			break;
#endif /* NXPBUILD__PHCE_T4T_SW2 */

#if defined(NXPBUILD__PH_KEYSTORE_SW2) || defined(NXPBUILD__PH_KEYSTORE_NCx33202)
		case PH_COMP_KEYSTORE2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sKeyStore2;
			break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW2 */

#ifdef NXPBUILD__PH_CRYPTOSYM_SW2
		case PH_COMP_CRYPTOSYM2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sCryptoSym2;
			break;
#endif /* NXPBUILD__PH_CRYPTOSYM_SW2 */

#ifdef NXPBUILD__PH_CRYPTORNG_SW2
			case PH_COMP_CRYPTORNG2:
			pDataparam2 = (void *) &gphNfcLib_Params2.sCryptoRng2;
			break;
#endif /* NXPBUILD__PH_CRYPTORNG_SW2 */

		default:
			/* Do nothing. pDataparam2 is already null. */
			break;
		}
	}
	return pDataparam2;
}

#define ANFCRL_STOP_SEC_CODE
#if ((PHNFCLIB_INITIALIZATION_AR_RELEASE_MAJOR_VERSION_C2 == 4) && (PHNFCLIB_INITIALIZATION_AR_RELEASE_MINOR_VERSION_C2 == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHNFCLIB2 */

#ifdef __cplusplus
}
#endif

