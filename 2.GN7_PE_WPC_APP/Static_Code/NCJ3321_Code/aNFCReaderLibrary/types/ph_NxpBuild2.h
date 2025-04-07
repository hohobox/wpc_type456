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
*   @file    ph_NxpBuild2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NxpBuild - COMMON API usage in common use cases.
*   @details Functions need to be implemented by application code. 
*
*   @addtogroup ph_NxpBuild NXP Build
*   @ingroup phothers
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

#ifndef PH_NXPBUILD2_H
#define PH_NXPBUILD2_H

#define NXPBUILD_CUSTOMER_HEADER_INCLUDED2	/* NIDEC_PORTING */

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#ifndef AUTOSAR_VER
#ifdef NXPBUILD_CUSTOMER_HEADER_INCLUDED2
#   include <ph_NxpBuild_App2.h>
#else /* NXPBUILD_CUSTOMER_HEADER_INCLUDED2 */
#    include "phAnfcLib2.h"
#endif /* NXPBUILD_CUSTOMER_HEADER_INCLUDED2 */
#else
#   include <AnfcRL_Build_App2.h>
#endif /* AUTOSAR_VER */
/* #define  NXPRDLIB_REM_GEN_INTFS2 */

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           ph_NxpBuild2.h
* @implements     DESIGN001, DESIGN002
*/
#define PH_NXPBUILD_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PH_NXPBUILD_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PH_NXPBUILD_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PH_NXPBUILD_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PH_NXPBUILD_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PH_NXPBUILD_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PH_NXPBUILD_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PH_NXPBUILD_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PH_NXPBUILD_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "ph_NxpBuild2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PH_NXPBUILD_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PH_NXPBUILD_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PH_NXPBUILD_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of ph_NxpBuild2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PH_NXPBUILD_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PH_NXPBUILD_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PH_NXPBUILD_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of ph_NxpBuild2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_NxpBuild NXP Build
* \ingroup phOthers
* \brief Controls build behaviour of components.
* @{
*/

/* NXPBUILD_DELETE: included code lines should be always removed from code */

/* NXP Build defines                            */
/* use #define to include components            */
/* comment out #define to exclude components    */

/* DEBUG2 build mode */

/*#define NXPBUILD__PH_DEBUG2*/                      /**< DEBUG2 build definition */

/* HAL components */

#if defined (NXPBUILD__PHHAL_HW_NCx33202) || \
	defined (NXPBUILD__PHHAL_HW_NCX33212)
#define NXPBUILD__PHHAL_HW2                  /**< Generic HAL definition */
#endif

#ifdef NXPBUILD__PHHAL_HW_NCx33202
	/* No active/target mode for NCx3320 */
	#undef NXPBUILD__PHHAL_HW_TARGET2
#endif /* NXPBUILD__PHHAL_HW_NCx33202 */

/* PAL ISO 14443-3A components */

#if defined (NXPBUILD__PHPAL_I14443P3A_SW2)
	#define NXPBUILD__PHPAL_I14443P3A2           /**< Generic PAL ISO 14443-3A definition */
#endif


/* PAL ISO 14443-3B components */

#if defined (NXPBUILD__PHPAL_I14443P3B_SW2)
	#define NXPBUILD__PHPAL_I14443P3B2           /**< Generic PAL ISO 14443-3B definition */
#endif
/* PAL ISO 14443-4A components */


#if defined (NXPBUILD__PHPAL_I14443P4A_SW2)
	#define NXPBUILD__PHPAL_I14443P4A2           /**< Generic PAL ISO 14443-4A definition */
#endif

/* PAL ISO 14443-4 components */

#if defined (NXPBUILD__PHPAL_I14443P4_SW2)
	#define NXPBUILD__PHPAL_I14443P42            /**< Generic PAL ISO 14443-4 definition */
#endif

/* PAL ISO 18092 Target component */

#if defined (NXPBUILD__PHPAL_I14443P4MC_SW2)
	#define NXPBUILD__PHPAL_I14443P4MC2             /**< Generic PAL ISO 18092 target definition */
#endif

/* PAL MIFARE product components */

#if defined (NXPBUILD__PHPAL_MIFARE_SW2)
    #define NXPBUILD__PHPAL_MIFARE2              /**< Generic PAL MIFARE product definition */
#endif

/* PAL ISO15693 ICode SLI components */

#if defined (NXPBUILD__PHPAL_SLI15693_SW2)
	#define NXPBUILD__PHPAL_SLI156932            /**< Generic PAL Sli 15693 definition */
#endif

/* PAL Felica components */

/*#define HANDLE_MULTIPLE_FELICA_CARD_RESP2 */   /**< Enable handling of multiple Felica card response */

#if defined (NXPBUILD__PHPAL_FELICA_SW2)
	#define NXPBUILD__PHPAL_FELICA2              /**< Generic PAL Felica definition */
#endif

/* AC discover loop component */

#if defined (NXPBUILD__PHAC_DISCLOOP_SW2)
    #define NXPBUILD__PHAC_DISCLOOP2             /**< Generic discovery loop component */
#endif


#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2)
	#define NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2	/**< Detect Passive TypeA Tags/Peers */
#endif

#if defined (NXPBUILD__PHAC_DISCLOOP_FELICA_TAGS2)
	#define NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
#endif

#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEB_BPRIME_TAGS2)
	#define NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2          /**< Detect TypeB Tags */
#endif

#if defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE2) || \
	defined (NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE2)
	#define NXPBUILD__PHAC_DISCLOOP_TARGET2      /**< Configure Target Mode */
#endif

/* AL Felica components */
#if defined (NXPBUILD__PHAL_FELICA_SW2)
	#define NXPBUILD__PHAL_FELICA2               /**< Generic AL Felica definition */
#endif

/* AL MIFARE Plus components */


/* AL MIFARE Plus EV1 components */


/* AL MIFARE DESFire Components */
#if defined (NXPBUILD__PHAL_MFDF_SW2)
	#define NXPBUILD__PHAL_MFDF2                  /**< Generic AL MIFARE Desfire definition */
#endif

/* AL MIFARE DESFire EVx contactless IC Components */
#if defined (NXPBUILD__PHAL_MFDFEVX_SW2)
    #define NXPBUILD__PHAL_MFDFEVX2                          /**< Generic AL MIFARE Desfire EVx definition */
#endif

/* AL MIFARE PRIME Ntag42XDna contactless IC components */

#if defined (NXPBUILD__PHAL_MFNTAG42XDNA_SW2)
    #define NXPBUILD__PHAL_MFNTAG42XDNA2            /**< Generic AL MIFARE Prime Ntag42XDna contactless IC definition */
#endif

/* CE T4AT Card Emulation components */
#if defined (NXPBUILD__PHCE_T4T_SW2)
	#define NXPBUILD__PHCE_T4T2                 /**< Generic HCE */
#endif

/* AL Virtual Card Architecture components */
#if defined (NXPBUILD__PHAL_VCA_SW2)
    #define NXPBUILD__PHAL_VCA2                              /**< Generic AL Virtual Card Architecture definition */
#endif

/* DL FPGA Box components */



/* DL Amplifier components */


/* DL Thermo stream components */


/* DL Oscilloscope components */


/* DL Master Amplifier Oscilloscope components */


/* DL Stepper components */


#if defined (NXPBUILD__PHAL_ICODE_SW2)
	#define NXPBUILD__PHAL_ICODE2               /**< Generic AL ICode definition */
#endif

/* AL P40 PrivateCommands components */


/* AL P40 PublicCommand components */


/* CID Manager components */
#if defined (NXPBUILD__PH_CIDMANAGER_SW2)
	#define NXPBUILD__PH_CIDMANAGER2             /**< Generic CID Manager definition */
#endif


/* Crypto components */

#if defined (NXPBUILD__PH_CRYPTOSYM_SW2)
	#define NXPBUILD__PH_CRYPTOSYM2                 /**< Generic Crypto Sym definition */
#endif

/* CryptoRng components */
#if defined (NXPBUILD__PH_CRYPTORNG_SW2)
	#define NXPBUILD__PH_CRYPTORNG2              /**< Generic CryptoRng definition */
#endif

/* KeyStore components */
#if defined (NXPBUILD__PH_KEYSTORE_SW2) || \
    defined (NXPBUILD__PH_KEYSTORE_NCx33202)
#define NXPBUILD__PH_KEYSTORE2               /**< Generic KeyStore definition */
#endif

/* TMIUtils component */
#define NXPBUILD__PH_TMIUTILS2

/* LN components */
#if defined (NXPBUILD__PHLN_LLCP_SW2)
#define NXPBUILD__PHLN_LLCP2               /**< Generic Link layer definition */
#endif

#if defined(NXPBUILD__PHHAL_HW_NCx33202)		|| \
	defined (NXPBUILD__PHHAL_HW_NCX33212)
#define PH_PLATFORM_HAS_ICFRONTEND2      /**< Platform has IC Front-end */
#endif

#ifdef NXPBUILD__PHPAL_MIFARE_SW2
    #if defined(NXPBUILD__PH_CRYPTOSYM_SW2) || defined(NXPBUILD__PH_CRYPTORNG_SW2)
        #define NXPBUILD__PH_NDA_MFDF2                           /**< MIFARE DESFire implementation under NDA */
    #endif

    #if defined(NXPBUILD__PH_TMIUTILS2) || defined(NXPBUILD__PHAL_VCA_SW2)
        #if defined(NXPBUILD__PH_CRYPTOSYM_SW2) || defined(NXPBUILD__PH_CRYPTORNG_SW2)
            #define NXPBUILD__PHAL_MFDFEVX_NDA2                  /**< MIFARE DESFire EVx build macro for IP Protection */
        #endif
    #endif
#endif /* NXPBUILD__PHPAL_MIFARE_SW2 */

/* Log component */

/*#define NXPBUILD__PH_LOG2*/

/* Enable/disable Debugging */
/*#define NXPBUILD__PH_DEBUG2*/

/**
 * end of group ph_NxpBuild NXP Build
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

#ifdef __cplusplus
} /* Extern C */
#endif /* __cplusplus */

#endif /* PH_NXPBUILD2_H */
