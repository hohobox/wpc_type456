/*******************************************************************************
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
*   @file    ph_NxpBuild_Platform2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR NxpBuild_Platform - COMMON API usage in common use cases.
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
#ifndef PH_NXPBUILD_PLATFORM2_H
#define PH_NXPBUILD_PLATFORM2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/


/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           ph_NxpBuild_Platform2.h
* @implements     DESIGN001, DESIGN002
*/
#define PH_NXPBUILD_PLATFORM_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PH_NXPBUILD_PLATFORM_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PH_NXPBUILD_PLATFORM_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PH_NXPBUILD_PLATFORM_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PH_NXPBUILD_PLATFORM_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PH_NXPBUILD_PLATFORM_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PH_NXPBUILD_PLATFORM_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PH_NXPBUILD_PLATFORM_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PH_NXPBUILD_PLATFORM_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "ph_NxpBuild_Flatform.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PH_NXPBUILD_PLATFORM_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PH_NXPBUILD_PLATFORM_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PH_NXPBUILD_PLATFORM_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of ph_NxpBuild_Flatform.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PH_NXPBUILD_PLATFORM_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PH_NXPBUILD_PLATFORM_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PH_NXPBUILD_PLATFORM_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of ph_NxpBuild_Flatform.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/** \defgroup ph_NxpBuild NXP Build
* \brief Controls the Inclusion of required components, Inclusion SRC/DATA within components and the Build Dependencies between the components
* @{
*/

/* NXPBUILD_DELETE: included code lines should be always removed from code */

/* NXP BUILD DEFINES */
/* use #define to include components            */
/* comment out #define to exclude components    */


/* DEBUG2 build mode */
/*#define NXPBUILD__PH_DEBUG2*/                              /**< DEBUG2 build definition */


#define NXPRDLIB_REM_GEN_INTFS2

#define NXPBUILD__PHHAL_HW_NCX33212  /* NIDEC_PORTING */

/*********************************************************************************************************************************************************************************/

#if	defined(PHDRIVER_LPC1769NCx3320_BOARD) \
	|| defined(PHDRIVER_FRDM_K82FNCx3320_BOARD) \
	|| defined(PHDRIVER_FRDM_S32K144NCx3320_BOARD)\
	|| defined(PHDRIVER_FRDM_S32K116NCx3320_BOARD)
#	define NXPBUILD__PHHAL_HW_NCx33202
#endif

#if defined(PHDRIVER_LPC1769NCX3321_BOARD) \
	|| defined(PHDRIVER_FRDM_K82FNCX3321_BOARD) \
	|| defined(PHDRIVER_FRDM_S32K144NCX3321_BOARD)\
	|| defined(PHDRIVER_FRDM_S32K116NCX3321_BOARD)
#	define NXPBUILD__PHHAL_HW_NCX33212
#endif

#if	defined(NXPBUILD__PHHAL_HW_NCx33202)		|| \
	defined(NXPBUILD__PHHAL_HW_NCX33212)
	#define PH_PLATFORM_HAS_ICFRONTEND2     /**< Platform has IC Front-end */
#endif

/*********************************************************************************************************************************************************************************/

#define NXPBUILD__PHPAL_I14443P3A_SW2                        /**< PAL ISO 14443-3A SW Component is included. */

#define NXPBUILD__PHPAL_I14443P3B_SW2                        /**< PAL ISO 14443-3B SW Component is included. */

#define NXPBUILD__PHPAL_I14443P4A_SW2                        /**< PAL ISO 14443-4A SW Component is included. */

#define NXPBUILD__PHPAL_I14443P4_SW2                         /**< PAL ISO 14443-4 SW Component is included. */

#define NXPBUILD__PHPAL_MIFARE_SW2                           /**< PAL MIFARE SW Component is included */
/*#define NXPBUILD__PHPAL_MIFARE_STUB2*/                       /**< PAL MIFARE STUB Component is included */

#define NXPBUILD__PHPAL_FELICA_SW2                           /**< PAL Felica SW Component is included. */

#ifdef NXPBUILD__PHHAL_HW_NCX33212                            /**< If FE HAL is NCx3320, then exclude ISO14443 Card Mode PAL & ISO18092 Target Mode PAL, otherwise include as required. */
        #define NXPBUILD__PHPAL_I14443P4MC_SW2               /**< PAL ISO 14443-4 Card Mode SW Component is included. */
#endif /* NXPBUILD__PHHAL_HW_NCX33212 */

/*********************************************************************************************************************************************************************************/

#define NXPBUILD__PHAC_DISCLOOP_SW2                          /**< Discovery Loop Activity SW Component is included. */

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2                           /**< If DiscLoop SW Component is included,  macros( & it's dependencies) to include/exclude SRC/DATA within Discloop is defined. */

    #if defined (NXPBUILD__PHHAL_HW_NCx33202)
                #define NXPBUILD__PHAC_DISCLOOP_LPCD2        /**< SRC to enable LPCD is included. */
    #endif

    #ifdef  NXPBUILD__PHPAL_I14443P3A_SW2
        #define NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2     /**< SRC/DATA to Detect/CollRes/Activate cards such as MFC, MFUL, MFP SL1 etc is included. */
        #if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
            #define NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 /**< SRC/DATA to Detect cards such as MFDF, MFP, T4AT NFC Forum Tag or Type A EMVCo is included. */
        #endif
    #endif /* NXPBUILD__PHPAL_I14443P3A_SW2 */

    #ifdef NXPBUILD__PHPAL_FELICA_SW2
        #define NXPBUILD__PHAC_DISCLOOP_FELICA_TAGS2                /**< SRC/DATA to Detect FeliCa Cards is included. */
    #endif /* NXPBUILD__PHPAL_FELICA_SW2 */

    #ifdef NXPBUILD__PHPAL_I14443P3B_SW2
        #define NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P3B_TAGS2           /**< SRC/DATA to Detect Type B Cards that operate at Layer3 level is included */
        #ifdef NXPBUILD__PHPAL_I14443P4_SW2
            #define NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2       /**< SRC/DATA to Detect Type B Cards such as NFC Forum Type 4 Tags, EMVCo Type B Cards etc is included */
        #endif /* NXPBUILD__PHPAL_I14443P4_SW2 */
    #endif /* NXPBUILD__PHPAL_I14443P3B_SW2 */

    #ifdef NXPBUILD__PHPAL_SLI15693_SW2
        #define NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2                 /**< SRC/DATA to Detect Type V Cards such as ICODE SLI/SLIX/SLI2/Tesa Cards is included*/
    #endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

    #ifndef NXPBUILD__PHHAL_HW_NCx33202                               /**< If FE HAL is NCx3320, target mode is not supported at all, hence exclude those SRC, otherwise include as required */
        #ifdef NXPBUILD__PHHAL_HW_TARGET2
            #define NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_PASSIVE2   /**< SRC to Initialize Type A passive listen config and subsequently call HAL AutoColl is included. */
            #define NXPBUILD__PHAC_DISCLOOP_TYPEA_TARGET_ACTIVE2    /**< SRC to Initialize Type A active listen config and subsequently call HAL AutoColl is included. */
            #define NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_PASSIVE2/**< SRC to Initialize Type F212 passive listen config and subsequently call HAL AutoColl is included. */
            #define NXPBUILD__PHAC_DISCLOOP_TYPEF212_TARGET_ACTIVE2 /**< SRC to Initialize Type F212 active listen config and subsequently call HAL AutoColl is included. */
            #define NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_PASSIVE2/**< SRC to Initialize Type F424 passive listen config and subsequently call HAL AutoColl is included. */
            #define NXPBUILD__PHAC_DISCLOOP_TYPEF424_TARGET_ACTIVE2 /**< SRC to Initialize Type F424 active listen config and subsequently call HAL AutoColl is included. */
        #endif /* NXPBUILD__PHHAL_HW_TARGET2 */
    #endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

/*********************************************************************************************************************************************************************************/

#define NXPBUILD__PHNFCLIB2                                      /**< Simplified API Interface, If enabling this the entry point should be this component in the application */

#ifdef NXPBUILD__PHNFCLIB2
    #define NXPBUILD__PHNFCLIB_PROFILES2                         /**< Simplified API Interface to provide different profiles to user. */
    #ifdef NXPBUILD__PHNFCLIB_PROFILES2
        #define NXPBUILD__PH_NFCLIB_ISO2                         /**< Enable the ISO profile of Simplified API */
        /*#define NXPBUILD__PH_NFCLIB_NFC2*/                       /**< Enable the NFC profile of Simplified API */
    #endif /* NXPBUILD__PHNFCLIB_PROFILES2 */
#endif /* NXPBUILD__PHNFCLIB2 */

/*********************************************************************************************************************************************************************************/

/*#define NXPBUILD__PH_CIDMANAGER_SW2*/                            /**< CID Manager SW Component is included. */

#define NXPBUILD__PH_KEYSTORE_SW2                                /**< SW KeyStore Component is included. */

#if defined(NXPBUILD__PHHAL_HW_NCx33202) && !defined(NXPBUILD__PH_KEYSTORE_SW2)
    #define NXPBUILD__PH_KEYSTORE_NCx33202                         /**< NCx3320 KeyStore Component is included. */
#endif

#define NXPBUILD__PH_CRYPTOSYM_SW2                               /**< Crypto Symbols SW Component is included. */

#define NXPBUILD__PH_CRYPTORNG_SW2                               /**< Crypto RNG SW Component is included. */

#define NXPBUILD__PH_TMIUTILS2                                   /**< TMIUtils component */

#define NXPBUILD__PHAL_VCA_SW2                                   /**< Software Virtual Card Architecture */

/*********************************************************************************************************************************************************************************/

#ifdef NXPBUILD__PHPAL_FELICA_SW2
    #define NXPBUILD__PHAL_FELICA_SW2                            /**< AL FeliCa SW Component is included */
#endif /* NXPBUILD__PHPAL_FELICA_SW2 */

#ifdef NXPBUILD__PHPAL_MIFARE_SW2

    #define NXPBUILD__PHAL_MFDF_SW2                              /**< AL Mifare DesFire SW Component is included */
    #if defined(NXPBUILD__PH_CRYPTOSYM_SW2) || defined(NXPBUILD__PH_CRYPTORNG_SW2)
        #define NXPBUILD__PH_NDA_MFDF2                           /**< Mifare DESFire implementation under NDA */
    #endif

    #if defined(NXPBUILD__PH_TMIUTILS2) || defined(NXPBUILD__PHAL_VCA_SW2)
        #define NXPBUILD__PHAL_MFDFEV2_SW                       /**< AL MIFARE DESFire EV2 SW Component is included */
        /*#define RDR_LIB_PARAM_CHECK2*/                             /**< AL MIFARE DESFire EV2 parameter check compilation switch */
        #define NXPBUILD__PHAL_MFP_SW2                           /**< AL MIFARE Plus SW Component is included */
        #define NXPBUILD__PHAL_MFPEV1_SW2                        /**< AL MIFARE Plus EV1 SW Component is included */

        #if defined(NXPBUILD__PH_CRYPTOSYM_SW2) || defined(NXPBUILD__PH_CRYPTORNG_SW2)
            #define NXPBUILD__PH_NDA_MFDFEV22                    /**< Mifare DESFire EV2 implementation under NDA */
            #define NXPBUILD__PH_NDA_MFP2                        /**< Mifare Plus implementation under NDA */
            #define NXPBUILD__PH_NDA_MFPEV12                     /**< Mifare Plus EV1 implementation under NDA */
        #endif
    #endif
#endif /* NXPBUILD__PHPAL_MIFARE_SW2 */

#ifdef NXPBUILD__PHPAL_SLI15693_SW2
        #define NXPBUILD__PHAL_ICODE_SW2                         /**< ICode implementation is included */
        #define PHAL_ICODE_ENABLE_CHAINING2                      /**< ICode Chaining is implemented */
#endif /* NXPBUILD__PHPAL_SLI15693_SW2 */

#ifdef NXPBUILD__PHPAL_I14443P4MC_SW2
    #if !defined(PH_OSAL_NULLOS2)
        #define NXPBUILD__PHCE_T4T_SW2                           /**< AL HCE T2AT SW Component is included */
        /*#define NXPBUILD__PHCE_T4T_PROPRIETARY2*/                /**< SRC to handle HCE T4AT Proprietary Commands is included */
        /*#define NXPBUILD__PHCE_T4T_EXT_NDEF2 */                /**< SRC to handle Extended NDEF Support as per T4T spec 3.0 is included */
    #endif
#endif /* NXPBUILD__PHPAL_I14443P4MC_SW2 */

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

#endif /* PH_NXPBUILD_PLATFORM2_H */
