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
*   @file    phacDiscLoop2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR ACDISCLOOP - API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phacDiscLoop Discovery Loop
*   @ingroup phac
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


#ifndef PHACDISCLOOP2_H
#define PHACDISCLOOP2_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#include <ph_Status2.h>
/* #define __DEBUG */
#include <CDD_AnfcRL_Cfg.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phacDiscLoop2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHACDISCLOOP_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHACDISCLOOP_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHACDISCLOOP_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHACDISCLOOP_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHACDISCLOOP_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHACDISCLOOP_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and AnfcRL_Cfg.h header file are of the same vendor */
#if (PHACDISCLOOP_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phacDiscLoop2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHACDISCLOOP_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phacDiscLoop2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and AnfcRL_Cfg.h header file are of the same software version */
#if ((PHACDISCLOOP_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHACDISCLOOP_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHACDISCLOOP_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phacDiscLoop2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2
/** \defgroup phac Activity Layer
* \brief This Layer Contains implementation of Discovery Loop component
*/

/** \defgroup phacDiscLoop_Sw Component : Software
* \ingroup phacDiscLoop
* \brief Software implementation of Discover loop component
* @{
*/
/**
 * ID for this layer (software implementation of Discover loop component).
 *
 * \ref phacDiscLoop_Sw_DataParams : wId is initialized with this ID in the
 * initialization function \ref phacDiscLoop_Sw_Init2.
 * */
#define PHAC_DISCLOOP_SW_ID2                                   0x01U

/**
 * Maximum cards supported per technologies in passive poll mode.
 *
 * By default maximum cards supported per technology is set to 1. Users can
 * change this value to support more cards.
 *
 * NOTE: Size of discovery loop data structure \ref phacDiscLoop_Sw_DataParams
 * will increase if this value is increased.
 * */
#define PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2                 0x03U

/**
 * Maximum cards supported per vicinity technologies in passive poll mode.
 *
 * By default maximum cards supported per vicinity technology is set to 1. Users can
 * change this value to support more cards.
 *
 * NOTE: Size of discovery loop data structure \ref phacDiscLoop_Sw_DataParams
 * will increase if this value is increased.
 * */
#define PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2        0x03U

/**
 * Configure the discovery loop to mimic the behavior of the PN7150
 * */
#define PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING2                0x01U

/**
 * Maximum (NFC + proprietary) technologies support in passive poll mode.
 *
 * Supported technologies are:\n
 * - Type A (As per NFC Activity 1.1 and EMVCo Specification 2.3.1a)\n
 * - Type B (As per NFC Activity 1.1 and EMVCo Specification 2.3.1a)\n
 * - Type F @ 212 kbps (As per NFC Activity 1.1)\n
 * - Type F @ 424 kbps (As per NFC Activity 1.1)\n
 * - Type V (ISO 15693) (As per NFC Activity draft specification)\n
 * */
#define PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2           0x05U

/**
* \name Supported NFC Activity versions.
* \brief Discovery loop support both NFC Activity version 1.0 and 1.1. By
* default discovery loop is configured for NFC Activity version 1.1. Use
* \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2 option
* to configure below values.
*/
/*@{*/
#define PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02                0x01U    /**< Supports NFC Activity version 1.0. */
#define PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12                0x02U    /**< Supports NFC Activity version 1.1. This is default. */
/*@}*/

/**
* \name Discovery loop return status codes.
*/
/*@{*/
/**
 * Discovery loop failure.
 *
 * This status can be returned by \ref phacDiscLoop_Run2 in poll and listen modes.
 * This is returned when discovery loop failed to proceed further due to an error
 * in lower layer. Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2
 * to get the actual error code from lower layer.
 * */
#define PHAC_DISCLOOP_FAILURE2                               0x0080U

/**
 * Indicates that collision is pending.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * collision resolution is disabled or when device limit is set to zero for a
 * detected technology.
 * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2
 * option to get collision pending status for all technologies.
 * */
#define PHAC_DISCLOOP_COLLISION_PENDING2                     0x0081U

/**
 * External RF field on.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * external RF is detected during RF collision avoidance (RFCA) procedure. On
 * getting this error application may restart \ref phacDiscLoop_Run2 in listen
 * mode if supported.
 * */
#define PHAC_DISCLOOP_EXTERNAL_RFON2                         0x0082U

/**
 * External RF field off.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in listen mode if external
 * RF is switched off during listen. On getting this error application may
 * restart discovery loop in poll mode or wait for a specific time for external
 * RF to turn ON.
 * */
#define PHAC_DISCLOOP_EXTERNAL_RFOFF2                        0x0083U

/**
 * No technologies detected.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode if no
 * technologies are detected during detection stage of passive polling.
 * */
#define PHAC_DISCLOOP_NO_TECH_DETECTED2                      0x0084U

/**
 * No card/device resolved.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode if no
 * card/device is resolved during collision resolution stage but that technology
 * was detected during technology detection stage of passive polling.
 * */
#define PHAC_DISCLOOP_NO_DEVICE_RESOLVED2                    0x0085U

/**
 * Low Power Card Detection (LPCD) succeeded but no technologies detected.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * LPCD is enabled and LPCD returned success but no technologies were detected
 * during technology detection stage of passive poll mode. This can be due to
 * false triggering of LPCD interrupt or LPCD triggered by a card/device not
 * supported by discovery loop.
 * */
#define PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2                 0x0086U

/**
 * Multiple Technologies detected.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * multiple technologies are detected during technology detection stage of
 * passive poll mode.\n
 *
 * To continue with collision resolution stage of one of the detected technology,
 * application can follow below steps:\n
 *
 * - Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
 * to get technologies detected.\n
 * - Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2
 * to configure passive polling for a single technology (one of the detected
 * technologies).\n
 * - Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2
 * option and #PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2 as value and start
 * \ref phacDiscLoop_Run2 to start passive poll mode in collision resolution phase.
 * */
#define PHAC_DISCLOOP_MULTI_TECH_DETECTED2                   0x0088U

/**
 * Multiple cards/devices resolved.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * multiple cards/devices are resolved during collision resolution stage of
 * passive poll mode when CON_DEVICES_LIMIT > 1.\n
 * - Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
 * to get the technology detected.\n
 * - Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND2
 * option to get number of devices/tags resolved.\n
 * - To activate a specific device/card from these resolved, application can use
 * \ref phacDiscLoop_ActivateCard2.
 * */
#define PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2                0x008AU

/**
 * Single card/device activated.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * a single card/device is successfully activated during activation stage.\n
 * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
 * to get the technology detected.
 * */
#define PHAC_DISCLOOP_DEVICE_ACTIVATED2                      0x008BU

/**
 * Active target activated.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in active poll mode when
 * a single active target is successfully activated during active polling.\n
 * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
 * to get the activated technology.
 * */
#define PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED2               0x008CU

/**
 * Passive target activated.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * a single passive target is successfully activated during passive polling.\n
 * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
 * to get the activated technology.
 * */
#define PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2              0x008DU

/**
 * Merged SEL_RES (Type A) with NFC-DEP and T4T support found.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in passive poll mode when
 * device/card is successfully activated till ISO 14443-3 and both T4T and
 * NFC DEP support is detected in SEL_RES/SAK. Then ATR_REQ or RATS is not sent
 * by discovery loop. On getting this status application can decide whether to
 * send ATR_REQ or RATS. This status is applicable only to Type A.
 * */
#define PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2                  0x008EU

/**
 * Activated in listen mode.
 *
 * This status is returned by \ref phacDiscLoop_Run2 in listen mode when it got
 * successfully activated in listen mode by another reader/initiator.\n
 * Application shall check \ref phacDiscLoop_TargetParams to validate the
 * received request (ATR_REQ/RATS), data rate and framing (active/passive) and
 * send the response.
 * */
#define PHAC_DISCLOOP_ACTIVATED_BY_PEER2                     0x008FU
/*@}*/


/**
* \defgroup DiscLoop_TechConfig Discovery loop technology bit map.
* \name Bit positions for different technologies.
*
* \brief Application can use these mask values to find the detected technology,
* collision pending status, bail out configuration etc.\n
*
* Example (Check for Type A detection in passive poll mode):\n
*  - \ref phacDiscLoop_GetConfig2 (pDataParams2, #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2)\n
*  - #PHAC_DISCLOOP_CHECK_ANDMASK2 (wTagsDetected2, #PHAC_DISCLOOP_POS_BIT_MASK_A2)\n
*/
/*@{*/
#define PHAC_DISCLOOP_POS_BIT_MASK_A2                          0x01U   /**< Position bit mask for Type A. */
#define PHAC_DISCLOOP_POS_BIT_MASK_B2                          0x02U   /**< Position bit mask for Type B. */
#define PHAC_DISCLOOP_POS_BIT_MASK_F2122                       0x04U   /**< Position bit mask for Type F212. */
#define PHAC_DISCLOOP_POS_BIT_MASK_F4242                       0x08U   /**< Position bit mask for Type F424. */
#define PHAC_DISCLOOP_POS_BIT_MASK_V2                          0x10U   /**< Position bit mask for Type V. */
#define PHAC_DISCLOOP_POS_BIT_MASK_VAS2                        0x40U   /**< Position bit mask for Type VAS. */
/*@}*/

/**
* \name Bit positions for active poll mode technologies.
*
* \brief Application can use these mask values to find the detected technology
* in active poll mode and to configure technologies to be detected in active
* poll mode.\n
*
* Example (Check for Active @ 106 kbps detection):\n
*  - \ref phacDiscLoop_GetConfig2 (pDataParams2, #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2)\n
*  - #PHAC_DISCLOOP_CHECK_ANDMASK2 (wTagsDetected2, #PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062)\n
*/
/*@{*/
#define PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062                    0x01U   /**< 106 Kbps Bit rate for Active Communication. */
#define PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122                    0x02U   /**< 212 Kbps Bit rate for Active Communication. */
#define PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242                    0x04U   /**< 424 Kbps Bit rate for Active Communication. */
/*@}*/

/**
* \name FeliCa data rates.
*/
/*@{*/
#define PHAC_DISCLOOP_CON_BITR_2122  PHAC_DISCLOOP_POS_BIT_MASK_F2122   /**< Configures 212 Kbps bit rate for Type F tag. */
#define PHAC_DISCLOOP_CON_BITR_4242  PHAC_DISCLOOP_POS_BIT_MASK_F4242   /**< Configures 424 Kbps bit rate for Type F tag. */
/*@}*/

/**
* \name Type A default parameters.
*/
/*@{*/
#define PHAC_DISCLOOP_I3P3A_MAX_ATQA_LENGTH2                   0x02U   /**< Answer to RequestA (ATQA) length for ISO 14443-3A card type. */
#define PHAC_DISCLOOP_I3P3A_MAX_UID_LENGTH2                    0x0AU   /**< Maximum UID length for 14443 Type A compliant tags. */
#define PHAC_DISCLOOP_I3P3A_SINGLE_SIZE_UID_LENGTH2            0x04U   /**< UID length for single size NFCID1 Type A compliant tags. */
#define PHAC_DISCLOOP_I3P3A_DOUBLE_SIZE_UID_LENGTH2            0x07U   /**< UID length for double size NFCID1 Type A compliant tags. */
#define PHAC_DISCLOOP_I3P3A_TRIPLE_SIZE_UID_LENGTH2            0x0AU   /**< UID length for triple size NFCID1 Type A compliant tags. */
#define PHAC_DISCLOOP_JEWEL_HR_LENGTH2                         0x02U   /**< Type 1 Tag Header ROM byte length. */
/*@}*/


/**
* \name Type B default parameters.
*/
/*@{*/
#define PHAC_DISCLOOP_I3P3B_PUPI_LENGTH2                       0x04U   /**< Device Identifier length for Type B tag. */
#define PHAC_DISCLOOP_I3P3B_MAX_ATQB_LENGTH2                     13U   /**< Maximum Answer to RequestB (ATQB) Response length. */
/*@}*/

/**
* \name Type F default parameters.
*/
/*@{*/
#define PHAC_DISCLOOP_FELICA_IDM_LENGTH2                       0x08U   /**< Manufacture ID (IDM) Length for FeliCa. */
#define PHAC_DISCLOOP_FELICA_PMM_LENGTH2                       0x08U   /**< Manufacturer Parameter (PMm) length for FeliCa. */
#define PHAC_DISCLOOP_FELICA_RD_LENGTH2                        0x02U   /**< Request Data (RD) length for FeliCa SENSF_RES. */
/*@}*/


/**
* \name Select Acknowledge (SAK) mask values for different Type A tags.
* \brief Application can use these mask values to detect the Type of tag
* from the SAK value.
*
* Usage:
\verbatim
  bTagType2 = (phacDiscLoop_Sw_DataParams->sTypeATargetInfo2.aTypeA_I3P32[0].aSak2 & 0x60U);
  bTagType2 = bTagType2 >> 5U;

  switch(bTagType2)
  {
  case PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK2:
      printf("\n\t\tType: Type 2 Tag\n");
      break;
  case PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK2:
      printf ("\n\t\tType: Type 4A Tag\n");
      break;
  case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK2:
      printf ("\n\t\tType: NFC_DEP\n");
      break;
  case PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK2:
      printf ("\n\t\tType: Type NFC_DEP and  4A Tag\n");
      break;
  default:
      break;
  }
\endverbatim
*/
/*@{*/
#define PHAC_DISCLOOP_TYPEA_TYPE2_TAG_CONFIG_MASK2               0x00U /**< Mask for determining for Type 2 tag. */
#define PHAC_DISCLOOP_TYPEA_TYPE4A_TAG_CONFIG_MASK2              0x01U /**< Mask for determining for Type 4A tag. */
#define PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TAG_CONFIG_MASK2        0x02U /**< Mask for determining for NFC DEP Protocol. */
#define PHAC_DISCLOOP_TYPEA_TYPE_NFC_DEP_TYPE4A_TAG_CONFIG_MASK2 0x03U /**< Mask for determining support for Type 4A and NFC DEP Protocol. */
/*@}*/

/**
 * \name Macros for checking set bit and set bit position.
 */
/*@{*/
/**
 * Logically AND value and mask, if the corresponding bit is set, then non
 * zero value is returned else zero is returned.
 *
 * Application can use this to check the detection technologies.
 *
 * Example (Check for Type B):\n
 *  - \ref phacDiscLoop_GetConfig2 (pDataParams2, #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2)\n
 *  - PHAC_DISCLOOP_CHECK_ANDMASK2(wTagsDetected2, #PHAC_DISCLOOP_POS_BIT_MASK_B2)\n
 * */
#define PHAC_DISCLOOP_CHECK_ANDMASK2(value2, mask2)          \
    (((value2) & (mask2)) != 0U)

/**
 * Get the first set bit position starting from least significant bit.
 *
 * Application can use this to check the bit position of detected technology.
 *
 * Example (Activation of device/tag at index 0, when \ref phacDiscLoop_Run2
 * returns #PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2):\n
 *  - \ref phacDiscLoop_GetConfig2 (pDataParams2, #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2, &wTagsDetected2);\n
 *  - PHAC_DISCLOOP_GET_BIT_POS2(wTagsDetected2, bTechType2);\n
 *  - \ref phacDiscLoop_ActivateCard2 (pDataParams2, (bTechType2 - 1), 0);
 * */
#define PHAC_DISCLOOP_GET_BIT_POS2(x2 , pos2)                 \
    {                                                      \
        (pos2) = 0;                                         \
        while(0u != (x2)){ (x2) >>= 1U; ++(pos2); }           \
        if ((pos2) == 0U) {return (PH_ERR_INTERNAL_ERROR2);} \
    }
/*@}*/

/**
* \brief Discovery loop poll states to start with while in passive poll mode.\n
*
* \anchor phacDiscLoop_Sw_PollState
*
* Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2
* option to configure these states. Default discovery loop starts with
* #PHAC_DISCLOOP_POLL_STATE_DETECTION2 in passive poll mode.
*/
/*@{*/
#define PHAC_DISCLOOP_POLL_STATE_UNKNOWN2              ((uint16)0x0000U)     /**< Unknown. */
#define PHAC_DISCLOOP_POLL_STATE_DETECTION2            ((uint16)0x0001U)     /**< Starts passive poll mode in Technology Detection stage. */
#define PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2 ((uint16)0x0002U)     /**< Starts passive poll mode in Collision Resolution stage. */
#define PHAC_DISCLOOP_POLL_STATE_REMOVAL2              ((uint16)0x0003U)     /**< Starts passive poll mode in Card Removal stage (Only for EMVCo mode). */
/*@}*/

/**
 * end of group phacDiscLoop_Sw Component : Software
 * @}
 */

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef NXPBUILD__PHAC_DISCLOOP2
/** \addtogroup phacDiscLoop Discovery Loop
*  \brief Discovery loop component as per NFC Forum Activity Specification 1.1 and EMVCo Digital 2.6 specification.
*
*  Discovery loop implements poll mode based on NFC Activity Specification 1.1
*  (backward compatibility with version 1.0) and EMVCo Specification 2.6. Listen
*  mode is implemented based on NFC Activity Specification 1.1. Support for Type V
*  (ISO 15693) polling is included based on NFC Forum draft specification.
*
*<b>Poll_Mode</b>
*<em>This scenario depicts sequence for Poll_Mode.</em>
*\image html Poll_Mode.png
*
*<b>Listen_Mode</b>
*<em>This scenario depicts sequence for Listen_Mode.</em>
*\image html Listen_Mode.png
* @{
*/

/**
* \name Configuration Types
* \anchor configurations
* \brief These options shall be used along with \ref phacDiscLoop_SetConfig2 and
* \ref phacDiscLoop_GetConfig2 to set/get discovery loop configurations.
*/
/*@{*/
/**
 * Set/Get the guard time for Type A technology in microseconds for passive poll
 * mode.
 *
 * Default guard time is set to 5200 microseconds for Type A.
 * */
#define PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2                     0x00U

/**
 * Set/Get the guard time for Type B technology in microseconds for passive poll
 * mode.
 *
 * Default guard time is set to 5200 microseconds for Type B.
 * */
#define PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2                     0x01U

/**
 * Set/Get the guard time for Type F technology in microseconds for passive poll mode
 * when polling for Type B is preceded by polling for Type F.
 *
 * Default guard time is set to 20400 microseconds for Type F.
 * */
#define PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US2                     0x02U

/**
 * Set/Get the guard time for Type F technology in microseconds for passive poll mode
 * when polling for Type F is preceded by polling for Type B.
 *
 * Default guard time is set to 15300 microseconds for Type F.
 * */
#define PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US2                     0x03U

/**
 * Set/Get the guard time for Type V technology in microseconds for passive poll
 * mode.
 *
 * Default guard time is set to 5200 microseconds for Type V.
 * */
#define PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2                     0x04U

/**
 * Set/Get the guard time for Active poll mode in microseconds
 *
 * Default guard time is set to 5100 microseconds.
 * */
#define PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US2                     0x06U


/**
 * Set/Get the number of Type A devices/tags that can be detected in passive
 * poll mode.
 *
 * Default device limit is 1 for Type A. Maximum supported device limit is
 * #PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2               0x10U

/**
 * Set/Get the number of Type B devices/tags that can be detected in passive
 * poll mode.
 *
 * Default device limit is 1 for Type B. Maximum supported device limit is
 * #PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2               0x11U

/**
 * Set/Get the number of Type F devices/tags that can be detected in passive
 * poll mode.
 *
 * Default device limit is 1 for Type F. Maximum supported device limit is
 * #PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT2               0x12U

/**
 * Set/Get the number of Type V tags that can be detected in passive
 * poll mode.
 *
 * Default device limit is 1 for Type V. Maximum supported device limit is
 * #PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2               0x13U

/**
 * Returns the number of Type A devices/tags found in passive poll mode.
 *
 * This gives the number of Type A devices/tags found after \ref phacDiscLoop_Run2
 * in poll mode (#PHAC_DISCLOOP_ENTRY_POINT_POLL2).
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_TAGS_FOUND2                 0x20U

/**
 * Returns the number of Type B devices/tags found in passive poll mode.
 *
 * This gives the number of Type B devices/tags found after \ref phacDiscLoop_Run2
 * in poll mode (#PHAC_DISCLOOP_ENTRY_POINT_POLL2).
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_TAGS_FOUND2                 0x21U

/**
 * Returns the number of Type F devices/tags found in passive poll mode.
 *
 * This gives the number of Type F devices/tags found after \ref phacDiscLoop_Run2
 * in poll mode (#PHAC_DISCLOOP_ENTRY_POINT_POLL2).
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEF_TAGS_FOUND2                 0x22U

/**
 * Returns the number of Type V tags found in passive poll mode.
 *
 * This gives the number of Type V tags found after \ref phacDiscLoop_Run2
 * in poll mode (#PHAC_DISCLOOP_ENTRY_POINT_POLL2).
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEV_TAGS_FOUND2                 0x23U

/**
 * Returns if the activated Type B device/tag is compliant with ISO/IEC 14443-4 or not.
 *
 * In ISO mode this is used to take decision if tag is compliant with ISO/IEC 14443-4.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_SUPPORT_TYPE4B2             0x25U

/**
 * Set/Get Application Family Identifier (AFI) to be used for Type B in
 * passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_AFI_REQ2                    0x30U

/**
 * Enable or disable (#PH_ON2 or #PH_OFF2) extended ATQB (Answer to Request B)
 * option for Type B during passive poll mode.
 *
 * Default is #PH_OFF2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_EXTATQB2                    0x31U

/**
 * Sets the Frame Size Device Integer (FSDI) value for the Type B tags in
 * passive poll mode.
 *
 * Default is 0x08.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_FSDI2                       0x32U

/**
 * Sets the Card Identifier (CID) value for the Type B tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_CID2                        0x33U

/**
 * Sets the Node ADdress (NAD) value for the Type B tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_NAD2                        0x34U

/**
 * Sets the Divisor Receive Integer (DRI) for Type B tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_DRI2                        0x35U

/**
 * Sets the Divisor Send Integer (DSI) for Type B tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEB_DSI2                        0x36U

/**
 * Sets the Frame Size Device Integer (FSDI) for the 14443P4A tags in passive
 * poll mode.
 *
 * Default is 0x08.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_FSDI2                  0x40U

/**
 * Sets the Card Identifier (CID) for the 14443P4A tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_CID2                   0x41U

/**
 * Sets the Node ADdress (NAD) for the 14443P4A tags in passive poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_NAD2                   0x42U

/**
 * Sets the Divisor Receive Integer (DRI) for the 14443P4A tags in passive
 * poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DRI2                   0x43U

/**
 * Sets the Divisor Send Integer (DSI) for the 14443P4A tags in passive
 * poll mode.
 *
 * Default is 0.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEA_I3P4_DSI2                   0x44U

/**
 * Set/Get the baud rate of FeliCa in passive poll mode.
 *
 * #PHAC_DISCLOOP_CON_BITR_2122 - FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_CON_BITR_4242 - FeliCa @ 424 kbps.\n
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEF_CUR_BAUD2                   0x57U

/**
 * Configure ISO 15693 for high/low RX data rate
 *
 * #PHHAL_HW_RF_RX_DATARATE_HIGH2\n
 * #PHHAL_HW_RF_RX_DATARATE_LOW2\n
 *
 * Default is #PHHAL_HW_RF_RX_DATARATE_HIGH2.
 * */
#define PHAC_DISCLOOP_CONFIG_TYPEV_RX_DATA_RATE2               0x60U

/**
 * Enable/Disable Low Power Card Detection (LPCD) in passive poll mode (#PH_ON2
 * or #PH_OFF2).
 *
 * Default is #PH_OFF2.
 * */
#define PHAC_DISCLOOP_CONFIG_ENABLE_LPCD2                      0x80U

/**
 * Returns the number of devices/tags found in passive poll mode.
 *
 * This gives the number of devices/tags found after \ref phacDiscLoop_Run2
 * in poll mode (#PHAC_DISCLOOP_ENTRY_POINT_POLL2).
 * */
#define PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND2                    0x81U

/**
 * Enable/Disable anti-collision support for Type A technology (#PH_ON2 or #PH_OFF2).
 *
 * Default is #PH_ON2.
 * */
#define PHAC_DISCLOOP_CONFIG_ANTI_COLL2                        0x88U

/**
 * Get the actual error code from lower layer when discovery loop returns
 * #PHAC_DISCLOOP_FAILURE2.
 * */
#define PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2                  0x85U

/**
 * Configure operation mode of discovery loop.
 *
 * #RD_LIB_MODE_EMVCO2 -> Run in EMVCO mode.\n
 * #RD_LIB_MODE_NFC2 -> Run in NFC mode. This is the default mode.\n
 *
 * Default is #RD_LIB_MODE_NFC2.
 * */
#define PHAC_DISCLOOP_CONFIG_OPE_MODE2                         0x82U

/**
 * Get collision pending status of polled technologies.
 *
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Collision pending for Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Collision pending for Type B.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Collision pending for FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Collision pending for FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Collision pending for Type V / ISO 15693.\n
 * */
#define PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2                0x83U

/**
 * Set the discovery loop state to start with while in poll mode.
 *
 * Refer \ref phacDiscLoop_Sw_PollState for all supported states.\n
 *
 * #PHAC_DISCLOOP_POLL_STATE_DETECTION2            -> Start with detection phase.\n
 * #PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2 -> Start with collision resolution.\n
 * #PHAC_DISCLOOP_POLL_STATE_REMOVAL2              -> Start with card removal phase (shall be used only in EMVCo mode).\n
 *
 * Default is #PHAC_DISCLOOP_POLL_STATE_DETECTION2. When \ref phacDiscLoop_Run2 gives
 * #PHAC_DISCLOOP_MULTI_TECH_DETECTED2 in poll mode, application shall select one technology
 * and start poll mode again in #PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2 state.
 * */
#define PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2                  0x84U

/**
 * Set/Get the bail out option for various technologies in passive poll mode.
 *
 * Default bail out is not set for any technology.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Bail out for Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Bail out for Type B.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Bail out for Type FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Bail out for Type FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Bail out for Type V / ISO 15693.\n
 * */
#define PHAC_DISCLOOP_CONFIG_BAIL_OUT2                         0x86U

/**
 * Returns the technologies that were detected during poll mode.
 *
 * Passive technologies:\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Detected Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Detected Type B.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Detected FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Detected FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Detected Type V / ISO 15693.\n
 *
 * Active technologies:\n
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062 -> Detected active target @ 106 kbps.\n
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122 -> Detected active target @ 212 kbps.\n
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242 -> Detected active target @ 424 kbps.\n
 * */
#define PHAC_DISCLOOP_CONFIG_TECH_DETECTED2                    0x87U

/**
 * Configure technologies to listen for in active listen mode.
 *
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Listen for Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Listen for Type B.[Reserved. Not supported currently]\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Listen for Type FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Listen for Type FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Listen for Type V / ISO 15693.[Reserved. Not supported currently]\n
 * */
#define PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2                 0x89U

/**
 * Configure technologies to be detected in passive poll mode.
 *
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062 -> Detect active target @ 106 kbps\n
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122 -> Detect active target @ 212 kbps\n
 * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242 -> Detect active target @ 424 kbps\n
 * */
#define PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2                0x8AU

/**
 * Configure technologies to listen for in passive listen mode.
 *
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Listen for Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Listen for Type B.[Reserved. Not supported currently]\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Listen for Type FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Listen for Type FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Listen for Type V / ISO 15693.[Reserved. Not supported currently]\n
 * */
#define PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2                 0x8BU

/**
 * Configure technologies to be detected in passive poll mode.
 *
 * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Detect Type A.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Detect Type B.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Detect Type FeliCa @ 212 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Detect Type FeliCa @ 424 kbps.\n
 * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Detect Type V / ISO 15693.\n
 * */
#define PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2                0x8CU

/**
 * Configure NFC activity version.
 *
 * #PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02 -> Run in Activity 1.0 mode.\n
 * #PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12 -> Run in Activity 1.1 mode. This is the default.\n
 * */
#define PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2                 0x8DU


/**
 * Configure AUTOCOLL retry count in listen mode.
 *
 * How many times to retry AUTOCOLL command if it fails. Default is 0. Supported
 * range is from 0 to 255.
 * */
#define PHAC_DISCLOOP_CONFIG_TARGET_RETRY_COUNT2               0x90U
/**
 * Configuration of the format byte of the VASUpA frame.
 *
 * Data format version '01', the VASUP-A command format version 1.0 Fixed size of 5 bytes excluding 2 bytes CRC.
 * Data format version '02', the VASUP-A command length can vary between 6 bytes to 20 bytes excluding 2 bytes CRC.
 * All other values are RFU.
 * */
#define PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2              0x91U

/**
 * Configure the discovery loop to mimic the behavior of the PN7150 .
 *
 * VAS polling only can be enabled to mimic the behavior of PN7150
 * VAS VAS Polling using discovery loop configuration identifier
 * "PH_NFCLIB_CONFIG_ACTIVATION_VAS_POLLING_IN_NFC_MODE" and set the
 * value to "PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING2". The discovery loop
 * must be configured to NFC Forum Activity Specification v1.0.
 * */
#define PHAC_DISCLOOP_CONFIG_VAS_POLLING_IN_NFC_MODE2          0x92U
/*@}*/

/**
 * end of group phacDiscLoop
 * @}
 */

#endif  /* NXPBUILD__PHAC_DISCLOOP2 */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHAC_DISCLOOP_SW2

/** \addtogroup phacDiscLoop_Sw Component : Software
* \ingroup phacDiscLoop
* \brief Software implementation of Discover loop component
* @{
*/

/**
* \brief Reader Library Profiles.
*
* \anchor phacDiscLoop_Profile
*
* This will be set and handled by the application.
*/
typedef enum {
    PHAC_DISCLOOP_PROFILE_UNKNOWN2 = 0,                                /**< Unknown. */
    PHAC_DISCLOOP_PROFILE_NFC2,                                        /**< NFC Forum Profile. */
    PHAC_DISCLOOP_PROFILE_EMVCO2,                                      /**< EMVCo Profile. */
    PHAC_DISCLOOP_PROFILE_ISO2,                                        /**< ISO Profile. */
    PHAC_DISCLOOP_PROFILE_NFC_AND_ACTIVE2                              /**< NFC Forum and Active Profile. */
 }phacDiscLoop_Profile_t2;

/**
 * \brief Discovery entry points.\n
 *
 * \anchor phacDiscLoop_Sw_EntryPoints
 * This is an input parameter to \ref phacDiscLoop_Run2.
 */
 typedef enum {
     PHAC_DISCLOOP_ENTRY_POINT_POLL2 = 0,                               /**< Starts discovery loop in poll mode. */
     PHAC_DISCLOOP_ENTRY_POINT_LISTEN2                                  /**< Starts discovery loop in listen mode. */
 }phacDiscLoop_Sw_EntryPoints_t2;

 /**
 * \brief Technology bit position / sequence.\n
 *
 * \anchor phacDiscLoop_Sw_NfcTech
 */
 typedef enum {
     PHAC_DISCLOOP_TECH_TYPE_A2 = 0,                                    /**< Type A bit position. */
     PHAC_DISCLOOP_TECH_TYPE_B2,                                        /**< Type B bit position. */
     PHAC_DISCLOOP_TECH_TYPE_F2122,                                     /**< Type F @ 212 kbps bit position. */
     PHAC_DISCLOOP_TECH_TYPE_F4242,                                     /**< Type F @ 424 kbps bit position. */
     PHAC_DISCLOOP_TECH_TYPE_V2,                                        /**< Type V bit position. */
     PHAC_DISCLOOP_TECH_TYPE_UNKNOWN2                                   /**< Unknown. */
 }phacDiscLoop_Sw_NfcTech_t2;

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/**
* \brief Type A parameter structure
*
* \anchor phacDiscLoop_Sw_TypeA_Info
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bTotalTagsFound2;                                          /**< Number of type A tags found. */

    /** Structure info required for ISO/IEC 14443 communication */
    #ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
        struct /*phacDiscLoop_TypeA_I3P3*/
        {
            VAR(uint8, ANFCRL_VAR) aAtqa2[PHAC_DISCLOOP_I3P3A_MAX_ATQA_LENGTH2];       /**< ATQA received from ISO/IEC 14443A compliant device. */
            VAR(uint8, ANFCRL_VAR) aUid2[PHAC_DISCLOOP_I3P3A_MAX_UID_LENGTH2];         /**< Contains known UID bytes for the given cascade level. */
            VAR(uint8, ANFCRL_VAR) bUidSize2;                                         /**< Size of the UID that was received from the PICC. */
            VAR(uint8, ANFCRL_VAR) aSak2;                                             /**< Select acknowledge from the ISO/IEC 14443A type A card. */
            VAR(uint8, ANFCRL_VAR) bSleep2;                                           /**< 1 if device is in SLEEP mode else 0. */
        }aTypeA_I3P32[PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2];
    #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

    #ifdef  NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2
        /** Structure info required for ISO/IEC 14443-4 communication */

        struct /*phascDiscLoop_TypeA_I3P4*/
        {
            VAR(uint8, ANFCRL_VAR) bFsdi2;                                            /**< Frame size integer. */
            VAR(uint8, ANFCRL_VAR) bCid2;                                             /**< Card identifier. */
            VAR(uint8, ANFCRL_VAR) bNad2;                                             /**< Node ADdress. */
            VAR(uint8, ANFCRL_VAR) bDri2;                                             /**< Data Rate received by Initiator. */
            VAR(uint8, ANFCRL_VAR) bDsi2;                                             /**< Data Rate send by Initiator. */
            P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pAts2;                                           /**< Holds the answer to select response. */
        }sTypeA_I3P42;
    #endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_I3P4_TAGS2 */
} phacDiscLoop_Sw_TypeA_Info_t2;

/**
* \brief Type B parameter structure
*
* \anchor phacDiscLoop_Sw_TypeB_Info
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bTotalTagsFound2;                                          /**< Number of type B tags found. */
    VAR(uint8, ANFCRL_VAR) bAfiReq2;                                                  /**< Application file Identifier. */
    VAR(uint8, ANFCRL_VAR) bExtendedAtqBbit2;                                         /**< For coding b5 of PARAM of REQB:  b5=1 extended ATQB supported. */
    VAR(uint8, ANFCRL_VAR) bAdvFeaturesBit2;                                          /**< For coding b6 of PARAM of REQB:  b6=1 advanced features supported (NFC Forum). */
    VAR(uint8, ANFCRL_VAR) bFsdi2;                                                    /**< Frame size integer. Valid values: 0-12. */
    VAR(uint8, ANFCRL_VAR) bCid2;                                                     /**< Card identifier. Valid values 0-14. */
    VAR(uint8, ANFCRL_VAR) bNad2;                                                     /**< Node ADdress. */
    VAR(uint8, ANFCRL_VAR) bDri2;                                                     /**< Data Rate receive (PICC --> PCD) integer. Valid values: 0-3. */
    VAR(uint8, ANFCRL_VAR) bDsi2;                                                     /**< Data Rate send (PCD --> PICC) integer. Valid values: 0-3. */

    /** Structure for Type B (ISO/IEC 14443-B) tags */
    struct /*phacDiscLoop_TypeB_I3P3B*/
    {
        VAR(uint8, ANFCRL_VAR) aPupi2[PHAC_DISCLOOP_I3P3B_PUPI_LENGTH2];               /**< ISO/IEC 14443-3B Pseudo Unique PICC identifier. */
        VAR(uint8, ANFCRL_VAR) aAtqB2[PHAC_DISCLOOP_I3P3B_MAX_ATQB_LENGTH2];           /**< ATQB received from ISO/IEC 14443-3B compliant device. */
        VAR(uint8, ANFCRL_VAR) bAtqBLength2;                                          /**< Length of the ATQB response. */
        VAR(uint8, ANFCRL_VAR) bSupportType4B2;                                       /**< Indicates activated TypeB tag supports Type 4B Tag Platform or not. */
    } aTypeB_I3P32[PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2];

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2
    /** Type B ISO/IEC 14443-4B tag structure. */
    struct /*phacDiscLoop_TypeB_I3P4B*/
    {
        VAR(uint8, ANFCRL_VAR) bMbli2;                                                /**< Maximum Buffer Length Index (MBLI) is available on bits [3:0]. */
        VAR(uint8, ANFCRL_VAR) bParam12;                                              /**< Param1 for type B Attrib: \n
                                                                              Bit 2 ... SOF \n
                                                                              Bit 3 ... EOF \n
                                                                              Bit 4-5 ... Minimum TR1 \n
                                                                              Bit 6-7 ... Minimum TR0. \n
                                                                      */
    } sTypeB_I3P42;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_I3P4B_TAGS2 */
} phacDiscLoop_Sw_TypeB_Info_t2;

/**
* \brief Type F parameter structure
*
* \anchor phacDiscLoop_Sw_TypeF_Info
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bTotalTagsFound2;                                        /**< Number of type F tags found. */
    VAR(uint8, ANFCRL_VAR) aSystemCode2[2];                                         /**< System code. */
    VAR(uint8, ANFCRL_VAR) bTimeSlot2;                                              /**< Maximum number of time slots. */

    struct /*phacDiscLoop_TypeF_Tag_Info*/
    {
        VAR(uint8, ANFCRL_VAR) aIDmPMm2[PHAC_DISCLOOP_FELICA_IDM_LENGTH2 + PHAC_DISCLOOP_FELICA_PMM_LENGTH2]; /**< Manufacture ID + PMm. */
        VAR(uint8, ANFCRL_VAR) aRD2[2];                                                                     /**< Request Data received as response to FeliCa polling command. */
        VAR(uint8, ANFCRL_VAR) bBaud2;                                                                      /**< Baud rate which card support. */
    }aTypeFTag2[PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2];
} phacDiscLoop_Sw_TypeF_Info_t2;

/**
* \brief Type V parameter structure
*
* \anchor phacDiscLoop_Sw_TypeV_Info
*/
typedef struct
{
    VAR(uint8, ANFCRL_VAR) bTotalTagsFound2;                                          /**< Number of type V (ISO 15693) tags found. */
    VAR(uint8, ANFCRL_VAR) bFlag2;                                                    /**< Request flags byte. */

    struct  /*phacDiscLoop_TypeV*/
    {
        VAR(uint8, ANFCRL_VAR) bDsfid2;                                               /**< [Out] Data Storage Format Identifier. */
        VAR(uint8, ANFCRL_VAR) aUid2[8];                                              /**< [Out] UID Received from card */
    }aTypeV2[PHAC_DISCLOOP_CFG_MAX_VICINITY_CARDS_SUPPORTED2];
}phacDiscLoop_Sw_TypeV_Info_t2;

/**
* \brief Target parameter structure
*
* \anchor phacDiscLoop_TargetParams
*/
typedef struct
{
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer2;                                              /**< Pointer to the Receive Buffer. */
    VAR(uint16, ANFCRL_VAR) wRxBufferLen2;                                            /**< Length of Data Present in Receive Buffer. */
    VAR(uint16, ANFCRL_VAR) wProtParams2;                                             /**< Frame mode and RX speed information. */
    VAR(uint8, ANFCRL_VAR) bRetryCount2;                                              /**< Retry count for AUTOCOLL in case of failure. Default is 0. */
}phacDiscLoop_Sw_TargetParams_t2;
/**
* \brief VAS parameter structure
*
* \anchor phacDiscLoop_Sw_VASTargetInfo
*/
typedef struct
{
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pCmdBytes2;                                              /**< Pointer to the command buffer that will be added in VAS frame. */
  VAR(uint8, ANFCRL_VAR) bLenCmdBytes2;                                             /**< Length of command. */
}phacDiscLoop_Sw_VASTargetInfo_t2;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
typedef enum
{
    CollisionResolutionA_Start2 = 0,
    CollisionResolutionA_WakeUpA_Run2 = 1,
    CollisionResolutionA_WakeUpA_End2 = 2,
    CollisionResolutionA_Device_Loop2 = 3,
    CollisionResolutionA_CascadeCode_Loop2 = 4,
    CollisionResolutionA_Anticollision_Loop2 = 5,
    CollisionResolutionA_Select2 = 6,
    CollisionResolutionA_CascadeCode_Loop_End2 = 7,
    CollisionResolutionA_HaltA2,
    CollisionResolutionA_RequestA2,
    CollisionResolutionA_Device_Loop_Check2,
    CollisionResolutionA_Finish2,
    CollisionResolutionA_Set_Txwait2
} DiscLoop_CollisionResolutionA_State_t2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
typedef enum {
	ColResolB_Start2 = 0,
	ColResolB_AppProtocol2,
	ColResolB_Symbol12,
	ColResolB_Symbol52,
	ColResolB_Symbol62,
	ColResolB_Symbol102,
	ColResolB_Symbol10A2,
	ColResolB_Symbol142,
	ColResolB_Symbol212,
	ColResolB_Symbol232,
	ColResolB_Symbol252,
} DiscLoop_ColResolB_State_t2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

/**
* \brief Discovery loop parameter structure
*
* \anchor phacDiscLoop_Sw_DataParams
*/
typedef struct
{
    /**
     * ID for this component, not to be modified.
     *
     * This is initialized with #PHAC_DISCLOOP_SW_ID2 in the initialization
     * function \ref phacDiscLoop_Sw_Init2. This is used for validating the data
     * parameter structure and to make sure that discovery loop APIs are
     * called after initialization.
     * */
    VAR(uint16, ANFCRL_VAR) wId2;

    /**
     * Technologies to poll for in passive mode.
     *
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Detect Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Detect Type B.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Detect Type FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Detect Type FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Detect Type V / ISO 15693.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2
     * option to configure above values.
     * */
    VAR(uint8, ANFCRL_VAR) bPasPollTechCfg2;

    /**
     * Technologies to poll for in active mode.
     *
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062 -> Detect active target @ 106 kbps\n
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122 -> Detect active target @ 212 kbps\n
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242 -> Detect active target @ 424 kbps\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ACT_POLL_TECH_CFG2
     * option to configure above values.
     * */
    VAR(uint8, ANFCRL_VAR) bActPollTechCfg2;

    /**
     * Bail out for various technologies in Passive mode.
     *
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Bail out for Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Bail out for Type B.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Bail out for Type FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Bail out for Type FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Bail out for Type V / ISO 15693.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_BAIL_OUT2 option
     * to configure above values.
     * */
    VAR(uint8, ANFCRL_VAR) bPasPollBailOut2;

    /**
     * Technologies to listen for in passive listen mode.
     *
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Listen for Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Listen for Type B. [Reserved. Not supported currently] \n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Listen for Type FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Listen for Type FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Listen for Type V / ISO 15693.[Reserved. Not supported currently]\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_PAS_LIS_TECH_CFG2
     * option to configure above values.
     * */
    VAR(uint8, ANFCRL_VAR) bPasLisTechCfg2;

    /**
     * Technologies to listen for in active listen mode.
     *
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Listen for Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Listen for Type B.[Reserved. Not supported currently] \n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Listen for Type FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Listen for Type FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Listen for Type V / ISO 15693.[Reserved. Not supported currently]\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ACT_LIS_TECH_CFG2
     * option to configure above values.
     * */
    VAR(uint8, ANFCRL_VAR) bActLisTechCfg2;

    /**
     * Discovery loop stage to start with while in poll mode.
     *
     * #PHAC_DISCLOOP_POLL_STATE_DETECTION2            -> Start with detection phase as per NFC Forum Activity Specification.\n
     * #PHAC_DISCLOOP_POLL_STATE_COLLISION_RESOLUTION2 -> Start with collision resolution as per NFC Forum Activity Specification.\n
     * #PHAC_DISCLOOP_POLL_STATE_REMOVAL2              -> Start with card removal phase (in EMVCo mode).\n
     *
     * When \ref phacDiscLoop_Run2 gives #PHAC_DISCLOOP_MULTI_TECH_DETECTED2 in poll mode, application
     * shall select one technology and start poll mode again in collision resolution state.
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_NEXT_POLL_STATE2
     * option to configure above states.
     * */
    VAR(uint16, ANFCRL_VAR) bPollState2;

    /**
     * Contains device limits for different technologies in passive poll mode.
     *
     * #PHAC_DISCLOOP_CONFIG_TYPEA_DEVICE_LIMIT2     -> Device limit for Type A.\n
     * #PHAC_DISCLOOP_CONFIG_TYPEB_DEVICE_LIMIT2     -> Device limit for Type B.\n
     * #PHAC_DISCLOOP_CONFIG_TYPEF_DEVICE_LIMIT2     -> Device limit for Type F.\n
     * #PHAC_DISCLOOP_CONFIG_TYPEV_DEVICE_LIMIT2     -> Device limit for Type V.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with above options to configure device limit.
     * Maximum device limit is #PHAC_DISCLOOP_CFG_MAX_CARDS_SUPPORTED2.
     * */
    VAR(uint8, ANFCRL_VAR) baPasConDevLim2[PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2];

    /**
     * Contains guard times for different technologies in passive poll mode.
     *
     * #PHAC_DISCLOOP_CONFIG_GTA_VALUE_US2         -> Guard time for Type A.\n
     * #PHAC_DISCLOOP_CONFIG_GTB_VALUE_US2         -> Guard time for Type B.\n
     * #PHAC_DISCLOOP_CONFIG_GTFB_VALUE_US2        -> Guard time for Type F. Guard time is applied when polling for Type B is preceded by polling for Type F.\n
     * #PHAC_DISCLOOP_CONFIG_GTBF_VALUE_US2        -> Guard time for Type F. Guard time is applied when polling for Type F is preceded by polling for Type B.\n
     * #PHAC_DISCLOOP_CONFIG_GTV_VALUE_US2         -> Guard time for Type V.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with above options to configure guard time.
     * */
    VAR(uint16, ANFCRL_VAR) waPasPollGTimeUs2[PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2];

    /**
     * Contains guard times for different technologies in Active poll mode.
     *
     * #PHAC_DISCLOOP_CONFIG_GT_ACTIVE_US2            -> Guard time for Active mode polling
     * Default value is 5100 micro seconds.
     *
     * Use \ref phacDiscLoop_SetConfig2 with above options to configure guard time.
     * */
    VAR(uint16, ANFCRL_VAR) wActPollGTimeUs2;

    /**
     * Flag to indicate whether collision is pending or not.
     *
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Type B.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Type V / ISO 15693.\n
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_COLLISION_PENDING2
     * option to get collision pending status.
     * */
    VAR(uint8, ANFCRL_VAR) bCollPend2;

    /**
     * Enable/Disable Low Power Card Detection.
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ENABLE_LPCD2 option
     * to #PH_ON2 / #PH_OFF2 LPCD.
     * */
    VAR(uint8, ANFCRL_VAR) bLpcdEnabled2;

    /**
     * Enable/Disable anti-collision for Type A for passive poll mode.
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ANTI_COLL2 option
     * to #PH_ON2 / #PH_OFF2 anti-collision.
     * */
    VAR(uint8, ANFCRL_VAR) bUseAntiColl2;

    /**
     * Operation mode of discovery loop.
     *
     * #RD_LIB_MODE_EMVCO2 -> Run in EMVCO mode as per the EMVCo 2.5 Digital specification.\n
     * #RD_LIB_MODE_NFC2   -> Run in NFC mode as per NFC Forum Activity Specification 1.1. This is the default mode.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_OPE_MODE2 option
     * to configure above modes.
     * */
    VAR(uint8, ANFCRL_VAR) bOpeMode2;

    /**
     * Number of cards detected in passive poll mode.
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_NR_TAGS_FOUND2
     * option to get number of tags.
     * */
    VAR(uint8, ANFCRL_VAR) bNumOfCards2;

    /**
     * Current FeliCa baud rate.
     * */
    VAR(uint8, ANFCRL_VAR) bFelicaBaud2;

    /**
     * Supported NFC Activity version.
     *
     * #PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_02 -> Run in NFC Forum Activity 1.0 mode.\n
     * #PHAC_DISCLOOP_NFC_ACTIVITY_VERSION_1_12 -> Run in NFC Forum Activity 1.1 mode. This is the default.\n
     *
     * Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_ACTIVITY_VERSION2
     * option to configure above modes.
     * */
    VAR(uint8, ANFCRL_VAR) bNfcActivityVersion2;

    /**
     * Detected technologies during poll mode.
     *
     * Passive technologies:\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_A2         -> Detected Type A.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_B2         -> Detected Type B.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F2122      -> Detected FeliCa @ 212 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_F4242      -> Detected FeliCa @ 424 kbps.\n
     * #PHAC_DISCLOOP_POS_BIT_MASK_V2         -> Detected Type V / ISO 15693.\n
     *
     * Active technologies:\n
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_1062   -> Detected active target @ 106 kbps.\n
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_2122   -> Detected active target @ 212 kbps.\n
     * #PHAC_DISCLOOP_ACT_POS_BIT_MASK_4242   -> Detected active target @ 424 kbps.\n
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_TECH_DETECTED2
     * option to get detected technologies.
     * */
    VAR(uint8, ANFCRL_VAR) bDetectedTechs2;

    /**
     * The configuration of the format byte of the VASUpA.
     *
     * Format byte:\n
     * 0x01U -> Data format version '01'\n
     * 0x02U -> Data format version '02'\n
     * All other values are RFU.
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2
     * option to get VASUpA format version.
     * */
    VAR(uint8, ANFCRL_VAR) bVASUpFormat2;

    /**
     * Configure the discovery loop to mimic the behavior of the PN7150.
     *
     * #PHAC_DISCLOOP_VAS_MIMIC_PN7150_POLLING2 -> mimic the PN7150 set\n
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_VASUP_A_FORMAT_BYTE2
     * to mimic the behavior of the PN7150.
     * */
    VAR(uint8, ANFCRL_VAR) bCfgVasPolling2;

    /**
     * Information gathered for VASUP-A command.
     *
     * */
    VAR(phacDiscLoop_Sw_VASTargetInfo_t2, ANFCRL_VAR) sVASTargetInfo2;

    /**
     * Hold error received from lower layer when \ref phacDiscLoop_Run2 returns #PHAC_DISCLOOP_FAILURE2.
     *
     * Use \ref phacDiscLoop_GetConfig2 with #PHAC_DISCLOOP_CONFIG_ADDITIONAL_INFO2
     * option to get error from lower layer.
     * */
    VAR(phStatus_t2, ANFCRL_VAR) wErrorCode2;

    /**
     * Pointer to the HAL data parameter.
     *
     * Application should initialize this pointer with address of HAL data
     * parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2;

    /**
     * Pointer to the 14443P3A layer PAL data parameter.
     *
     * Application should initialize this pointer with address of 14443P3A PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal1443p3aDataParams2;

    /**
     * Pointer to the FeliCa PAL data parameter.
     *
     * Application should initialize this pointer with address of FeliCa PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalFelicaDataParams2;

    /**
     * Pointer to the 14443P3B PAL data parameter.
     *
     * Application should initialize this pointer with address of 14443P3B PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal1443p3bDataParams2;

    /**
     * Pointer to the 14443P4 PAL data parameter.
     *
     * Application should initialize this pointer with address of 14443P4 PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal14443p4DataParams2;

    /**
     * Pointer to the 14443P4A PAL data parameter.
     *
     * Application should initialize this pointer with address of 14443P4A PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPal1443p4aDataParams2;

    /**
     * Pointer to the 15693 PAL data parameter.
     *
     * Application should initialize this pointer with address of 15693 PAL
     * data parameter structure.
     * */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pPalSli15693DataParams2;

    /**
     * Pointer to Passive Poll sequence mapping table.
     *
     * Application can initialize this pointer if different Polling sequence is required other than default.
     * */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPasTechPollSeq2;

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2)
    /**
     * Information gathered from TYPE A devices/tags in poll mode.
     *
     * Application can access this directly to get information like UID, UID size,
     * SAK etc. of all Type A devices/tags detected in poll mode.
     * */
    VAR(phacDiscLoop_Sw_TypeA_Info_t2, ANFCRL_VAR) sTypeATargetInfo2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2 */

#if defined(NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2)
    /**
     * Information gathered from TYPE F devices/tags in poll mode.
     *
     * Application can access this directly to get information like ID, Baud rate,
     * etc. of all Type F devices/tags detected in poll mode.
     * */
    VAR(phacDiscLoop_Sw_TypeF_Info_t2, ANFCRL_VAR) sTypeFTargetInfo2;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
    /**
     * Information gathered from TYPE B devices/tags in poll mode.
     *
     * Application can access this directly to get information like PUPI, ATQB,
     * ATQB length etc. of all Type B devices/tags detected in poll mode.
     * */
    VAR(phacDiscLoop_Sw_TypeB_Info_t2, ANFCRL_VAR) sTypeBTargetInfo2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
    /**
     * Information gathered from TYPE V (15693) devices/tags in poll mode.
     *
     * Application can access this directly to get information like UID, DSFID,
     * etc. of all Type V devices/tags detected in poll mode.
     * */
    VAR(phacDiscLoop_Sw_TypeV_Info_t2, ANFCRL_VAR) sTypeVTargetInfo2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TARGET2
    /**
     * Information gathered from listen mode.
     *
     * Application can access this directly to get information like Request
     * received, Request length etc. from AUTOCOLL in listen mode.
     * */
    VAR(phacDiscLoop_Sw_TargetParams_t2, ANFCRL_VAR) sTargetParams2;
#endif  /* NXPBUILD__PHAC_DISCLOOP_TARGET2  */

	VAR(uint8, ANFCRL_VAR) bDiscLoopRunState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopColsnReslnActivityState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopTechDetectActivityState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopPollModeState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopSwIntFieldOnState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopSwIntRfcaOffFieldOnState2;

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEA_TAGS2
	VAR(uint8, ANFCRL_VAR) bDiscLoopActivateAState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopDetTechTypeAState2;
	VAR(DiscLoop_CollisionResolutionA_State_t2, ANFCRL_VAR) bDiscLoopCollisionResolutionAState2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TARGET2 */

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEB_TAGS2
	VAR(DiscLoop_ColResolB_State_t2, ANFCRL_VAR) bCollResBState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopActivateBState2;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEF_TAGS2
	VAR(uint8, ANFCRL_VAR) bDiscLoopCollisionResolutionFState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopActivateFState2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopSendSensFReq2;
	VAR(uint8, ANFCRL_VAR) bDiscLoopDetTechTypeF2;
#endif

#ifdef NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2
	VAR(uint8, ANFCRL_VAR) bDiscLoopCollisionResolutionVState2;
#endif /* NXPBUILD__PHAC_DISCLOOP_TYPEV_TAGS2 */
}phacDiscLoop_Sw_DataParams_t2;
/**
 * end of group phacDiscLoop_Sw Component : Software
 * @}
 */

 #endif /* NXPBUILD__PHAC_DISCLOOP2 */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef NXPBUILD__PHAC_DISCLOOP_SW2

#define ANFCRL_START_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phacDiscLoop_Sw Component : Software
* \ingroup phacDiscLoop
* \brief Software implementation of Discover loop component
* @{
*/
/**
 * \brief Initialize discovery  loop.
 * \anchor initialization
 * This should be called before using any of the discovery loop functions to do
 * the initialization of discovery loop component. This configures discovery loop
 * with default configurations. Refer \ref configurations "configuration options"
 * for supported configurations and their default values.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_ERR_INVALID_PARAMETER2 Invalid option/response received.
 * \retval other Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Sw_Init2(
    P2VAR(phacDiscLoop_Sw_DataParams_t2, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,    /**< [In] Pointer to discovery loop parameter structure. */
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams2,                    /**< [In] Specifies the size of the discovery data parameter structure. */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pHalDataParams2                          /**< [In] Pointer to HAL parameter structure. */
    );
/**
 * end of group phacDiscLoop_Sw Component : Software
 * @}
 */
 #define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHAC_DISCLOOP_SW2 */

#ifdef NXPRDLIB_REM_GEN_INTFS2
#include "../comps/phacDiscLoop/src/Sw/phacDiscLoop_Sw2.h"

#define phacDiscLoop_Run2(pDataParams2, bEntryPoint2) \
        phacDiscLoop_Sw_Run2((phacDiscLoop_Sw_DataParams_t2 *)pDataParams2, bEntryPoint2)

#define phacDiscLoop_GetConfig2(pDataParams2, wConfig2, pValue2) \
        phacDiscLoop_Sw_GetConfig2((phacDiscLoop_Sw_DataParams_t2 *)pDataParams2, wConfig2, pValue2)

#define phacDiscLoop_SetConfig2(pDataParams2, wConfig2, wValue2) \
        phacDiscLoop_Sw_SetConfig2((phacDiscLoop_Sw_DataParams_t2 *)pDataParams2, wConfig2, wValue2)

#define phacDiscLoop_ActivateCard2(pDataParams2, bTagType2, bTagIndex2) \
        phacDiscLoop_Sw_ActivateCard2((phacDiscLoop_Sw_DataParams_t2 *)pDataParams2, bTagType2, bTagIndex2)

#define phacDiscLoop_CfgPollSeq(pDataParams2, pDiscloopCfgPollSeq2) \
        phacDiscLoop_Sw_CfgPollSeq2((phacDiscLoop_Sw_DataParams_t2 *)pDataParams2, pDiscloopCfgPollSeq2)
#endif /* NXPRDLIB_REM_GEN_INTFS2 */

#ifdef NXPBUILD__PHAC_DISCLOOP2

#ifndef NXPRDLIB_REM_GEN_INTFS2
#define ANFCRL_START_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2 == 0))
    #include <MemMap.h>
#else
    #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phacDiscLoop Discovery Loop
 *  \ingroup phac
 *  \brief Discovery loop component as per NFC Forum Activity Specification 1.1 and EMVCo Digital 2.6 specification.
 *  @{
 */

/**
 * \brief Starts the discovery loop in poll mode or listen mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
 *
 * Use \ref phacDiscLoop_SetConfig2 with \ref configurations "configuration options"
 * to modify poll mode and listen mode settings of discovery loop.
 *
 * \return Status code
 * \retval #PHAC_DISCLOOP_FAILURE2 Discovery loop failure due to error from lower layer.
 * \retval #PHAC_DISCLOOP_COLLISION_PENDING2 Indicates that collision is pending.
 * \retval #PHAC_DISCLOOP_EXTERNAL_RFON2 External RF field on.
 * \retval #PHAC_DISCLOOP_EXTERNAL_RFOFF2 External RF field off.
 * \retval #PHAC_DISCLOOP_NO_TECH_DETECTED2 No technologies detected.
 * \retval #PHAC_DISCLOOP_NO_DEVICE_RESOLVED2 No card/device resolved.
 * \retval #PHAC_DISCLOOP_LPCD_NO_TECH_DETECTED2 LPCD succeeded but no technologies detected..
 * \retval #PHAC_DISCLOOP_MULTI_TECH_DETECTED2 Multiple Technologies detected.
 * \retval #PHAC_DISCLOOP_MULTI_DEVICES_RESOLVED2 Multiple cards/devices resolved.
 * \retval #PHAC_DISCLOOP_DEVICE_ACTIVATED2 Single card/device activated.
 * \retval #PHAC_DISCLOOP_ACTIVE_TARGET_ACTIVATED2 Active target activated..
 * \retval #PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2 Passive target activated.
 * \retval #PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2 Merged SAK with NFC-DEP and T4T support found.
 * \retval #PHAC_DISCLOOP_ACTIVATED_BY_PEER2 Activated in listen mode.
 * \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_Run2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,                /**< [In] Pointer to discovery loop parameter structure. */
  VAR(phacDiscLoop_Sw_EntryPoints_t2, ANFCRL_VAR) bEntryPoint2                /**< [In] Entry point to start discovery loop. Refer \ref phacDiscLoop_Sw_EntryPoints for supported list of entry points. */
    );

/**
 * \brief Set discovery loop \ref configurations "configuration" value.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful.
 * \retval #PH_ERR_INVALID_PARAMETER2 Invalid option/response received.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_SetConfig2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,                /**< [In] Pointer to discovery loop parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig2,                  /**< [In] Configuration identifier. */
    VAR(uint16, ANFCRL_VAR) wValue2                    /**< [In] Configuration value. */
    );

/**
 * \brief Get discovery loop \ref configurations "configuration" value.
 * \return Status code
 * \retval #PH_ERR_SUCCESS2 Operation successful
 * \retval #PH_ERR_INVALID_PARAMETER2 Invalid option/response received
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_GetConfig2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,                /**< [In] Pointer to discovery loop parameter structure. */
    VAR(uint16, ANFCRL_VAR) wConfig2,                  /**< [In] Configuration identifier. */
    P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue2                   /**< [Out] Configuration value. */
    );

/**
 * \brief Activates the given tag type with given index.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function run at asynchronous mode. It returns PH_STATUS_INPROCESS2 when operation is not completed.
 *
 * \return Status code
 * \retval #PHAC_DISCLOOP_DEVICE_ACTIVATED2 Single card/device activated.
 * \retval #PHAC_DISCLOOP_PASSIVE_TARGET_ACTIVATED2 Passive target activated.
 * \retval #PHAC_DISCLOOP_MERGED_SEL_RES_FOUND2 Merged SAK with NFC-DEP and T4T support found.
 * \retval #PH_ERR_INVALID_PARAMETER2 If invalid index or card type was given
 * \retval #PH_STATUS_INPROCESS2 Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_ActivateCard2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,                /**< [In] Pointer to discovery loop parameter structure. */
    VAR(uint8, ANFCRL_VAR) bTagType2,                  /**< [In] Tag type \ref phacDiscLoop_Sw_NfcTech. */
    VAR(uint8, ANFCRL_VAR) bTagIndex2                  /**< [In] The tag index to be activated. */
    );

/**
 * \brief Configures the Discovery loop Passive Polling loop Sequence.
 *
 * \b pDiscloopCfgPollSeq2 should be a byte array of length \ref PHAC_DISCLOOP_PASS_POLL_MAX_TECHS_SUPPORTED2.
 *
 * Note: Polling technology sequence shall be with in the defined technology bit map as per DiscLoop_TechConfig.\n
 *        Same technology should not be repeated in the configuration array.
 * Note: Use \ref phacDiscLoop_SetConfig2 with #PHAC_DISCLOOP_CONFIG_PAS_POLL_TECH_CFG2 to either enable or disable particular \n
 *        technology in Passive Polling.
 * \return Status code
 * \retval #PH_ERR_INVALID_PARAMETER2 If invalid polling sequence was given.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t2, ANFCRL_CODE) phacDiscLoop_CfgPollSeq2(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams2,                /**< [In] Pointer to discovery loop parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pDiscloopCfgPollSeq2      /**< [In] Discovery loop polling loop sequence pointer. */
    );

/**
 * end of group phacDiscLoop Discovery Loop
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHACDISCLOOP_AR_RELEASE_MAJOR_VERSION2 == 4) && (PHACDISCLOOP_AR_RELEASE_MINOR_VERSION2 == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#endif /* NXPRDLIB_REM_GEN_INTFS2 */

#endif /* NXPBUILD__PHAC_DISCLOOP2 */

#ifdef __cplusplus
} /* Extern C */
#endif

#endif /* PHACDISCLOOP2_H */
