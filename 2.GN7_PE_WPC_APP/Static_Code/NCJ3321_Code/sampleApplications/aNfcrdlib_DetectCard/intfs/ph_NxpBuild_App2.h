/*******************************************************************************
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2018-2019
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
 * INTELLECTUAL PROPERTY RIGHTS. NXP SHALL HAVE NO LIABILITY TO THE NXP CUS-TOMER, OR ITS
 * SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY FOR ANY DAMAGES, INCLUDING WITHOUT LIMITATION,
 * DAMAGES RESULTING OR ALLEGDED TO HAVE RESULTED FROM ANY DEFECT, ER-ROR OR OMMISSION IN THE NXP
 * SOFTWARE/SOURCE CODE, THIRD PARTY APPLICATION SOFTWARE AND/OR DOCUMENTATION, OR AS A RESULT OF ANY
 * INFRINGEMENT OF ANY INTELLECTUAL PROPERTY RIGHT OF ANY THIRD PARTY. IN NO EVENT SHALL NXP BE LIABLE
 * FOR ANY INCIDENTAL, INDIRECT, SPE-CIAL, EXEMPLARY, PUNITIVE, OR CONSEQUENTIAL DAMAGES (INCLUDING
 * LOST PROFITS) SUFFERED BY NXP CUSTOMER OR ITS SUBSIDIARIES, AFFILIATES, OR ANY OTHER THIRD PARTY
 * ARISING OUT OF OR RE-LATED TO THE NXP SOFTWARE/SOURCE CODE EVEN IF NXP HAS BEEN ADVISED OF THE
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

#ifndef PH_NXPBUILD_APP2_H
#define PH_NXPBUILD_APP2_H

/*********************************************************************************************************************************************************************************/
/* NIDEC_PORTING */

#define PHDRIVER_CYT2B9

#define NXPBUILD__PHHAL_HW_NCX33212
#define NXPBUILD__PHNFCLIB2
#define NXPBUILD__PHPAL_I14443P3A_SW2
#define NXPBUILD__PHPAL_I14443P4A_SW2
#define NXPBUILD__PHPAL_I14443P4_SW2
#define NXPBUILD__PHAC_DISCLOOP_SW2

/* Card Protection */
#define NXPBUILD__PHPAL_I14443P3B_SW2                        /**< PAL ISO 14443-3B SW Component is included. */
#define NXPBUILD__PHPAL_FELICA_SW2                           /**< PAL ISO FELICA SW Component is included. */
#define NXPBUILD__PHPAL_SLI15693_SW2                         /**< PAL ISO SLI15693 SW Component is included. */
// #define NXPBUILD__PHPAL_MIFARE_SW
// #define NXPBUILD__PHPAL_I14443P4MC_SW
/* Card Protection */

/* Define �߰� 20240701 */
#define M4_SRC_AR_MODULE_VENDOR_ID2          43
#define M4_SRC_AR_MODULE_ID2                 255
#define M4_SRC_AR_SPEC_VERSION_MAJOR2        4
#define M4_SRC_AR_SPEC_VERSION_MINOR2        3
#define M4_SRC_AR_SPEC_VERSION_PATCH2        1
#define M4_SRC_SW_VERSION_MAJOR2             1
#define M4_SRC_SW_VERSION_MINOR2             0
#define M4_SRC_SW_VERSION_PATCH2             0

#define AUTOSAR_OS_NOT_USED
#define DEV_ERROR_DETECT

// #define CPU_S32K144HFT0VLLT

#define DEBUG_ANALOG
// #define NXPBUILD__PH_LOG
// #define NXPBUILD__PH_LOG_EX
// #define PH_LIB_LOG_DISABLE

#define RFID_PROTECTION_V1
#define FULL_NFC
/* Define �߰� 20240701 */

/*********************************************************************************************************************************************************************************/

/** \defgroup ph_NxpBuild NXP Build
* \brief Controls the Inclusion of required components, Inclusion SRC/DATA within components and the Build Dependencies between the components
* @{
*/

#if !defined(NXPBUILD__PHHAL_HW_NCx33202) && !defined(NXPBUILD__PHHAL_HW_NCX33212)
#   error "Please add MACRO NXPBUILD__PHHAL_HW_NCx33202 or NXPBUILD__PHHAL_HW_NCX33212"
#endif

#ifdef NXPBUILD__PHPAL_I14443P4_SW2
#   ifdef NXPBUILD__PHPAL_I14443P4A_SW2
#       ifndef NXPBUILD__PHPAL_I14443P3A_SW2
#           error "Please add Component PAL_I14443P3A_SW in Project pre-processor setting."
#       endif /*NXPBUILD__PHPAL_I14443P3A_SW2*/
#   else
#       ifndef NXPBUILD__PHPAL_I14443P3B_SW2
#           error "Please add Component PAL_I14443P3B_SW in Project Pre-processor setting"
#       endif
#   endif
#else   /* ifndef NXPBUILD__PHPAL_I14443P4_SW2*/
#   ifdef NXPBUILD__PHPAL_I14443P4A_SW2
#       ifndef NXPBUILD__PHPAL_I14443P3A_SW2
#           error "Please add Component PAL_I14443P3A_SW in Project Pre-processor setting"
#       endif
#   else
#       if (!defined(NXPBUILD__PHPAL_I14443P3A_SW2))&&(!defined(NXPBUILD__PHPAL_I14443P3B_SW2))&&(!defined(NXPBUILD__PHPAL_FELICA_SW2))
#           error "Please add at least PAL_3A_SW, PAL_3B_SW or PAL_FELICA in Project Pre-processor setting"
#       endif
#   endif
#endif

#ifdef NXPBUILD__PHAL_FELICA_SW2
#   ifndef NXPBUILD__PHPAL_FELICA_SW2
#       error "Please add NXPBUILD__PHPAL_FELICA_SW2 in Project pre-processor setting"
#   endif
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2                           /**< If DiscLoop SW Component is included,  macros( & it's dependencies) to include/exclude SRC/DATA within Discloop is defined. */

    #define NXPBUILD__PHAC_DISCLOOP_LPCD2       /**< SRC to enable LPCD is included. */

    #ifdef  NXPBUILD__PHPAL_I14443P3A_SW2
        #define NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P3_TAGS2     /**< SRC/DATA to Detect/CollRes/Activate cards such as MFC, MFUL, MFP SL1 etc is included. */

        #if defined(NXPBUILD__PHPAL_I14443P4A_SW2) && defined(NXPBUILD__PHPAL_I14443P4_SW2)
            #define NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2  /**< SRC/DATA to Detect cards such as MFDF, MFP, T4AT NFC Forum Tag or Type A EMVCo is included. */
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
/** @}
* end of ph_NxpBuild
*/

#endif /* PH_NXPBUILD_APP2_H */
