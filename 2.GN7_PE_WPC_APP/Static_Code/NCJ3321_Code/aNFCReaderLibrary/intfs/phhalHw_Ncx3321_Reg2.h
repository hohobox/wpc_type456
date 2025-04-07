/*******************************************************************************
 * (c) NXP Semiconductors Gratkorn / Austria
 * (c) NXP Semiconductors
 * (c) NXP B.V. 2020
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
*   @file    phhalHw_Ncx3321_Reg2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw_Ncx3321_Reg - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw_Ncx3321 component : Ncx3321
*   @ingroup phhalHw
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
#ifndef PHHALHW_NCX3321_REG2_H
#define PHHALHW_NCX3321_REG2_H

#ifdef __cplusplus
extern "C"{
#endif
/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw_Ncx3321_Reg2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_NCX3321_REG_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_NCX3321_REG_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_NCX3321_REG_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_NCX3321_REG_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_NCX3321_REG_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_NCX3321_REG_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHHALHW_NCX3321_REG_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_NCX3321_REG_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_NCX3321_REG_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw_Ncx3321_Reg2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_NCX3321_REG_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_REG_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_NCX3321_REG_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw_Ncx3321_Reg2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_NCX3321_REG_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_NCX3321_REG_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_NCX3321_REG_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw_Ncx3321_Reg2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/


/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#define MASK_TX_LASTBITS2                                                                                 0x07U    /**< The bits that are valid for TX_LATS_BITS field */
#define MASK_RX_LASTBITS2                                                                                 0x07U    /**< The bits that are valid for RX_LATS_BITS field */
#define MASK_RXWAIT2                                                                                      0xFFFFFU/**< Bitmask for RxWait bits. */


#define SYSTEM_CONFIG2                                                                                     0x0
#define SYSTEM_CONFIG_TX_NOV_CALIBRATE_POS2                                                               (8U)
#define SYSTEM_CONFIG_TX_NOV_CALIBRATE_MASK2                                                              (0x00000100U)  /**< 0-*/
#define SYSTEM_CONFIG_RFU_POS2                                                                            (7U)
#define SYSTEM_CONFIG_RFU_MASK2                                                                           (0x00000080U)  /**< 7-Reserved */
#define SYSTEM_CONFIG_15693_CHANGE_DATARATE_POS2                                                          (5U)
#define SYSTEM_CONFIG_15693_CHANGE_DATARATE_MASK2                                                         (0x00000060U)  /**< 0-0 - RFU
1 - Change Data Rate to 53kB/sec
2 -  Change Data Rate to 106kB/sec
3 -  Change Data Rate to 212kB/sec*/
#define SYSTEM_CONFIG_AUTO_RF_ON_OFF_POS2                                                                 (4U)
#define SYSTEM_CONFIG_AUTO_RF_ON_OFF_MASK2                                                                (0x00000010U)  /**< 0-*/
#define SYSTEM_CONFIG_AUTOCOLL_STATE_A_POS2                                                               (3U)
#define SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK2                                                              (0x00000008U)  /**< 0-*/
#define SYSTEM_CONFIG_SOFT_RESET_POS2                                                                     (2U)
#define SYSTEM_CONFIG_SOFT_RESET_MASK2                                                                    (0x00000004U)  /**< 0-*/
#define SYSTEM_CONFIG_MFC_CRYPTO_ON_POS2                                                                  (1U)
#define SYSTEM_CONFIG_MFC_CRYPTO_ON_MASK2                                                                 (0x00000002U)  /**< 8-If set to 1 the mfc-crypto bit is generated for end-/de-cryption*/
#define SYSTEM_CONFIG_PRBS_TYPE_POS2                                                                      (0U)
#define SYSTEM_CONFIG_PRBS_TYPE_MASK2                                                                     (0x00000001U)  /**< 20-Defines the PRBS type. If set to 1 PRBS15 is selected default value 0 selects PRBS9*/

#define EVENT_ENABLE2                                                                                      0x1
#define EVENT_ENABLE_RFU_POS2                                                                             (12U)
#define EVENT_ENABLE_RFU_MASK2                                                                            (0xFFFFF000U)  /**< 12-Enable the corresponding event*/
#define EVENT_ENABLE_CTS_EVENT_ENABLE_POS2                                                                (11U)
#define EVENT_ENABLE_CTS_EVENT_ENABLE_MASK2                                                               (0x00000800U)  /**< 11-Enable the corresponding event*/
#define EVENT_ENABLE_IDLE_EVENT_ENABLE_POS2                                                               (10U)
#define EVENT_ENABLE_IDLE_EVENT_ENABLE_MASK2                                                              (0x00000400U)  /**< 10-Enable the corresponding event*/
#define EVENT_ENABLE_LP_CALIBRATION_EVENT_ENABLE_POS2                                                     (9U)
#define EVENT_ENABLE_LP_CALIBRATION_EVENT_ENABLE_MASK2                                                    (0x00000200U)  /**< 9-Enable the corresponding event*/
#define EVENT_ENABLE_LPCD_EVENT_ENABLE_POS2                                                               (8U)
#define EVENT_ENABLE_LPCD_EVENT_ENABLE_MASK2                                                              (0x00000100U)  /**< 8-Enable the corresponding event*/
#define EVENT_ENABLE_AUTOCOLL_EVENT_ENABLE_POS2                                                           (7U)
#define EVENT_ENABLE_AUTOCOLL_EVENT_ENABLE_MASK2                                                          (0x00000080U)  /**< 7-Enable the corresponding event*/
#define EVENT_ENABLE_TIMER0_EVENT_ENABLE_POS2                                                             (6U)
#define EVENT_ENABLE_TIMER0_EVENT_ENABLE_MASK2                                                            (0x00000040U)  /**< 6-Enable the corresponding event*/
#define EVENT_ENABLE_TEMP_ERROR_EVENT_ENABLE_POS2                                                         (5U)
#define EVENT_ENABLE_TEMP_ERROR_EVENT_ENABLE_MASK2                                                        (0x00000020U)  /**< 5-Enable the corresponding event*/
#define EVENT_ENABLE_RFON_DET_EVENT_ENABLE_POS2                                                           (4U)
#define EVENT_ENABLE_RFON_DET_EVENT_ENABLE_MASK2                                                          (0x00000010U)  /**< 4-Enable the corresponding event*/
#define EVENT_ENABLE_RFOFF_DET_EVENT_ENABLE_POS2                                                          (3U)
#define EVENT_ENABLE_RFOFF_DET_EVENT_ENABLE_MASK2                                                         (0x00000008U)  /**< 3-Enable the corresponding event*/
#define EVENT_ENABLE_STANDBY_PREV_EVENT_ENABLE_POS2                                                       (2U)
#define EVENT_ENABLE_STANDBY_PREV_EVENT_ENABLE_MASK2                                                      (0x00000004U)  /**< 2-Enable the corresponding event*/
#define EVENT_ENABLE_GENERAL_ERROR_EVENT_ENABLE_POS2                                                      (1U)
#define EVENT_ENABLE_GENERAL_ERROR_EVENT_ENABLE_MASK2                                                     (0x00000002U)  /**< 1-Enable the corresponding event*/
#define EVENT_ENABLE_BOOT_EVENT_ENABLE_POS2                                                               (0U)
#define EVENT_ENABLE_BOOT_EVENT_ENABLE_MASK2                                                              (0x00000001U)  /**< 0-Enable the corresponding event*/

#define EVENT_STATUS2                                                                                      0x2
#define EVENT_STATUS_RFU_POS2                                                                             (12U)
#define EVENT_STATUS_RFU_MASK2                                                                            (0xFFFFF000U)  /**< 12-Reserved */
#define EVENT_STATUS_CTS_EVENT_POS2                                                                       (11U)
#define EVENT_STATUS_CTS_EVENT_MASK2                                                                      (0x00000800U)  /**< 11-Indicated the availability of CTS Event*/
#define EVENT_STATUS_IDLE_EVENT_POS2                                                                      (10U)
#define EVENT_STATUS_IDLE_EVENT_MASK2                                                                     (0x00000400U)  /**< 10-Indicated the availability of IDLE event.*/
#define EVENT_STATUS_LP_CALIBRATION_EVENT_POS2                                                            (9U)
#define EVENT_STATUS_LP_CALIBRATION_EVENT_MASK2                                                           (0x00000200U)  /**< 9-Indicated the availability of LP Calibration event*/
#define EVENT_STATUS_LPCD_EVENT_POS2                                                                      (8U)
#define EVENT_STATUS_LPCD_EVENT_MASK2                                                                     (0x00000100U)  /**< 8-Indicated the availability of LPCD event.*/
#define EVENT_STATUS_AUTOCOLL_EVENT_POS2                                                                  (7U)
#define EVENT_STATUS_AUTOCOLL_EVENT_MASK2                                                                 (0x00000080U)  /**< 7-Indicated the availability of Autocoll event*/
#define EVENT_STATUS_TIMER0_EVENT_POS2                                                                    (6U)
#define EVENT_STATUS_TIMER0_EVENT_MASK2                                                                   (0x00000040U)  /**< 6-Indicated the availability of Timer0 event*/
#define EVENT_STATUS_TEMP_ERROR_EVENT_POS2                                                                (5U)
#define EVENT_STATUS_TEMP_ERROR_EVENT_MASK2                                                               (0x00000020U)  /**< 5-Indicated the availability of Temp error*/
#define EVENT_STATUS_RFON_DET_EVENT_POS2                                                                  (4U)
#define EVENT_STATUS_RFON_DET_EVENT_MASK2                                                                 (0x00000010U)  /**< 4-Indicated the availability of RF ON detected*/
#define EVENT_STATUS_RFOFF_DET_EVENT_POS2                                                                 (3U)
#define EVENT_STATUS_RFOFF_DET_EVENT_MASK2                                                                (0x00000008U)  /**< 3-Indicated the availability of Boot event.RF OFF detected*/
#define EVENT_STATUS_STANDBY_PREV_EVENT_POS2                                                              (2U)
#define EVENT_STATUS_STANDBY_PREV_EVENT_MASK2                                                             (0x00000004U)  /**< 2-Indicated the availability of Standby Prevention reason.*/
#define EVENT_STATUS_GENERAL_ERROR_EVENT_POS2                                                             (1U)
#define EVENT_STATUS_GENERAL_ERROR_EVENT_MASK2                                                            (0x00000002U)  /**< 1-Indicated the availability of General Error event.*/
#define EVENT_STATUS_BOOT_EVENT_POS2                                                                      (0U)
#define EVENT_STATUS_BOOT_EVENT_MASK2                                                                     (0x00000001U)  /**< 0-Indicated the availability of Boot event.*/

#define EMD_CONTROL2                                                                                       0x3
#define EMD_CONTROL_EMD_RM_EMD_SENSITIVITY_POS2                                                           (10UL)
#define EMD_CONTROL_EMD_RM_EMD_SENSITIVITY_MASK2                                                          (0x00000C00UL)  /**< 10-RM EMD SENSITIVITY value that will be applied to SIGPRO_RM_CONFIG*/
#define EMD_CONTROL_EMD_TRANSMISSION_TIMER_USED_POS2                                                      (8U)
#define EMD_CONTROL_EMD_TRANSMISSION_TIMER_USED_MASK2                                                     (0x00000300U)  /**< 8-Timer used for RF communication. */
#define EMD_CONTROL_EMD_MISSING_CRC_IS_PROTOCOL_ERROR_TYPE_B_POS2                                         (7U)
#define EMD_CONTROL_EMD_MISSING_CRC_IS_PROTOCOL_ERROR_TYPE_B_MASK2                                        (0x00000080U)  /**< 7-Missing CRC treated as protocol error in case of Type B based communication*/
#define EMD_CONTROL_EMD_MISSING_CRC_IS_PROTOCOL_ERROR_TYPE_A_POS2                                         (6U)
#define EMD_CONTROL_EMD_MISSING_CRC_IS_PROTOCOL_ERROR_TYPE_A_MASK2                                        (0x00000040U)  /**< 6-Missing CRC treated as protocol error in case of Type A based communication*/
#define EMD_CONTROL_EMD_NOISE_BYTES_THRESHOLD_POS2                                                        (2U)
#define EMD_CONTROL_EMD_NOISE_BYTES_THRESHOLD_MASK2                                                       (0x0000003CU)  /**< 2-Defines the threshold under which transmission errors are treated as noise. Note: CRC bytes are NOT included/counted!*/
#define EMD_CONTROL_EMD_TRANSMISSION_ERROR_ABOVE_NOISE_THRESHOLD_IS_NO_EMD_POS2                           (1U)
#define EMD_CONTROL_EMD_TRANSMISSION_ERROR_ABOVE_NOISE_THRESHOLD_IS_NO_EMD_MASK2                          (0x00000002U)  /**< 1-Transmission errors with received byte length >= EMD_NOISE_BYTES_THRESHOLD is never treated as EMD (EMVCo 2.5 standard)*/
#define EMD_CONTROL_EMD_ENABLE_POS2                                                                       (0U)
#define EMD_CONTROL_EMD_ENABLE_MASK2                                                                      (0x00000001U)  /**< 0-EMD handling enabled*/

#define FELICA_EMD_CONTROL2                                                                                0x4
#define FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_POS2                                                  (24U)
#define FELICA_EMD_CONTROL_FELICA_EMD_RC_BYTE_VALUE_MASK2                                                 (0xFF000000U)  /**< 24-RC byte value that needs to be received to not treat the frame as EMD*/
#define FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_POS2                                                (16U)
#define FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MAX_MASK2                                               (0x00FF0000U)  /**< 16-Maximum Length byte value that needs to be received to not treat the frame as EMD*/
#define FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_POS2                                                (8U)
#define FELICA_EMD_CONTROL_FELICA_EMD_LENGTH_BYTE_MIN_MASK2                                               (0x0000FF00U)  /**< 8-Minimum Length byte value that needs to be received to not treat the frame as EMD*/
#define FELICA_EMD_CONTROL_RESERVED_POS2                                                                  (5U)
#define FELICA_EMD_CONTROL_RESERVED_MASK2                                                                 (0x000000E0U)  /**< 5-Reserved */
#define FELICA_EMD_CONTROL_FELICA_EMD_INTEGRITY_ERR_CHECK_ENABLE_POS2                                     (4U)
#define FELICA_EMD_CONTROL_FELICA_EMD_INTEGRITY_ERR_CHECK_ENABLE_MASK2                                    (0x00000010U)  /**< 4-FeliCa EMD handling enabled when integrity error is set*/
#define FELICA_EMD_CONTROL_FELICA_EMD_PROTOCOL_ERR_CHECK_ENABLE_POS2                                      (3U)
#define FELICA_EMD_CONTROL_FELICA_EMD_PROTOCOL_ERR_CHECK_ENABLE_MASK2                                     (0x00000008U)  /**< 3-FeliCa EMD handling enabled when protocol error is set*/
#define FELICA_EMD_CONTROL_FELICA_EMD_RC_CHECK_ENABLE_POS2                                                (2U)
#define FELICA_EMD_CONTROL_FELICA_EMD_RC_CHECK_ENABLE_MASK2                                               (0x00000004U)  /**< 2-RC byte check enabled for FeliCa EMD handling */
#define FELICA_EMD_CONTROL_FELICA_EMD_LEN_CHECK_ENABLE_POS2                                               (1U)
#define FELICA_EMD_CONTROL_FELICA_EMD_LEN_CHECK_ENABLE_MASK2                                              (0x00000002U)  /**< 1-Length byte check enabled for FeliCa EMD handling*/
#define FELICA_EMD_CONTROL_FELICA_EMD_ENABLE_POS2                                                         (0U)
#define FELICA_EMD_CONTROL_FELICA_EMD_ENABLE_MASK2                                                        (0x00000001U)  /**< 0-FeliCa EMD handling enabled*/

#define CLIF_RX_STATUS2                                                                                    0x5
#define CLIF_RX_STATUS_RESERVED_POS2                                                                      (27U)
#define CLIF_RX_STATUS_RESERVED_MASK2                                                                     (0xF8000000U)  /**< 27-Reserved*/
#define CLIF_RX_STATUS_RX_COLL_POS_POS2                                                                   (20U)
#define CLIF_RX_STATUS_RX_COLL_POS_MASK2                                                                  (0x07F00000U)  /**< 20-Status indicating the bit position of the first collision detected in the data bit. The value is valid only when RX_COLLISION_DETECTED==1. The value of the RX_BIT_ALIGN is also taken into account (RX_COLL_POS = physical bit position in the flow + RX_BIT_ALIGN value).Indicates the collision position in the first 8 bytes only. Can be used during the TypeA/ICODE/EPC anticollision procedure.0x00 - 1st bit 0x01 - 2nd bit...0x7F - 128th bit.The status register is not updated by the collision detected on stop or parity bit.*/
#define CLIF_RX_STATUS_RX_NUM_LAST_BITS_POS2                                                              (17U)
#define CLIF_RX_STATUS_RX_NUM_LAST_BITS_MASK2                                                             (0x000E0000U)  /**< 17-Status indicating the number of valid bits in the last byte written to the System RAM.0x0 - all bits are valid 0x1 - 1 bit is valid...0x7 - 7 bits are valid*/
#define CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_POS2                                                        (13U)
#define CLIF_RX_STATUS_RX_NUM_FRAMES_RECEIVED_MASK2                                                       (0x0001E000U)  /**< 13-Indicates the number of frames received. The value is updated after every normal frame reception in RX_MULTIPLE mode.The value is valid only if the bit RX_MULTIPLE_ENABLE==1.*/
#define CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_POS2                                                         (0U)
#define CLIF_RX_STATUS_RX_NUM_BYTES_RECEIVED_MASK2                                                        (0x00001FFFU)  /**< 0-Status indicating the number of bytes written to the System RAM.0x0000 - no data0x0001 - 1 byte...0x1000 - 4K bytes.0x1001 - 0x1FFF - not supported*/

#define CLIF_RX_STATUS_ERROR2                                                                              0x6
#define CLIF_RX_STATUS_ERROR_RESERVED_POS2                                                                (30U)
#define CLIF_RX_STATUS_ERROR_RESERVED_MASK2                                                               (0xC0000000U)  /**< 30-Reserved*/
#define CLIF_RX_STATUS_ERROR_EMD_DETECTED_IN_RXDEC_POS2                                                   (29U)
#define CLIF_RX_STATUS_ERROR_EMD_DETECTED_IN_RXDEC_MASK2                                                  (0x20000000U)  /**< 29-The high level indicates that the EMD was detected (in the SigPro or in the RxDecoder or in both) during the reception.*/
#define CLIF_RX_STATUS_ERROR_EMD_DETECTED_IN_SIGPRO_POS2                                                  (28U)
#define CLIF_RX_STATUS_ERROR_EMD_DETECTED_IN_SIGPRO_MASK2                                                 (0x10000000U)  /**< 28-The high level indicates that the EMD was detected on the Physical layer (in the SigPro) during the reception.*/
#define CLIF_RX_STATUS_ERROR_EXT_RFOFF_DETECTED_POS2                                                      (27U)
#define CLIF_RX_STATUS_ERROR_EXT_RFOFF_DETECTED_MASK2                                                     (0x08000000U)  /**< 27-The high level indicates that the external RF-field vanished during the reception.*/
#define CLIF_RX_STATUS_ERROR_RX_FRAME_MAXLEN_VIOL_POS2                                                    (26U)
#define CLIF_RX_STATUS_ERROR_RX_FRAME_MAXLEN_VIOL_MASK2                                                   (0x04000000U)  /**< 26-The high level indicates that the received frame length violated the configured maximum limit.*/
#define CLIF_RX_STATUS_ERROR_RX_FRAME_MINLEN_VIOL_POS2                                                    (25U)
#define CLIF_RX_STATUS_ERROR_RX_FRAME_MINLEN_VIOL_MASK2                                                   (0x02000000U)  /**< 25-The high level indicates that the received frame length violated the configured minimum limit.*/
#define CLIF_RX_STATUS_ERROR_RX_FRAME_LE_CRC_POS2                                                         (24U)
#define CLIF_RX_STATUS_ERROR_RX_FRAME_LE_CRC_MASK2                                                        (0x01000000U)  /**< 24-The high level indicates that the received frame length is less or equal to the expected CRC field length.*/
#define CLIF_RX_STATUS_ERROR_RX_NOT_FULL_BYTE_POS2                                                        (23U)
#define CLIF_RX_STATUS_ERROR_RX_NOT_FULL_BYTE_MASK2                                                       (0x00800000U)  /**< 23-The high level indicates that the last received character in the frame has less than 8 bits.*/
#define CLIF_RX_STATUS_ERROR_RX_MISSING_PARBIT_DETECTED_POS2                                              (22U)
#define CLIF_RX_STATUS_ERROR_RX_MISSING_PARBIT_DETECTED_MASK2                                             (0x00400000U)  /**< 22-The high level indicates that the last received character in the frame has 8 data bits but the expected parity bit is absent.*/
#define CLIF_RX_STATUS_ERROR_RX_MISSING_STOPBIT_DETECTED_POS2                                             (21U)
#define CLIF_RX_STATUS_ERROR_RX_MISSING_STOPBIT_DETECTED_MASK2                                            (0x00200000U)  /**< 21-The high level indicates that the last received character in the frame has 8 data bits but the expected stop bit is absent.*/
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_PARBIT_DETECTED_POS2                                            (20U)
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_PARBIT_DETECTED_MASK2                                           (0x00100000U)  /**< 20-The high level indicates that the collision was detected on the parity bit position.*/
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_STOPBIT_DETECTED_POS2                                           (19U)
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_STOPBIT_DETECTED_MASK2                                          (0x00080000U)  /**< 19- The high level indicates that the collision was detected on the stop bit position.*/
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_DETECTED_POS2                                                   (18U)
#define CLIF_RX_STATUS_ERROR_RX_COLLISION_DETECTED_MASK2                                                  (0x00040000U)  /**< 18-The high level indicates that the collision was detected during the frame reception.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_RXOVER_POS2                                                       (17U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_RXOVER_MASK2                                                      (0x00020000U)  /**< 17-The high level indicates that the frame reception was stopped by SGP_MSG_RXOVER_* message reception.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_RFOFF_POS2                                                        (16U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_RFOFF_MASK2                                                       (0x00010000U)  /**< 16-The high level indicates that the frame reception was interrupted by external RF-field vanishing event.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_ERR_POS2                                                          (15U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_ERR_MASK2                                                         (0x00008000U)  /**< 15-The high level indicates that the frame reception was stopped by detected communication error event.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_LEN_POS2                                                          (14U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_LEN_MASK2                                                         (0x00004000U)  /**< 14-The high level indicates that the frame reception was normally stopped by byte counter expiration event. Relates to the protocols where the LEN field is used in the frame format (Felica RM/CM, FWEC RM/CM).*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_INVPAR_POS2                                                       (13U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_INVPAR_MASK2                                                      (0x00002000U)  /**< 13-The high level indicates that the frame reception was normally stopped by the inverted parity detection event. Relates to the TypeA RM 212-848 kbps modes. 12 RX_STOP_ON_PATTERN R 0h The high level indicates that the frame reception was normally stopped by EOF pattern detection event. Relates to the TypeB RM/CM, B prime RM/CM modes.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_PATTERN_POS2                                                      (12U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_PATTERN_MASK2                                                     (0x00001000U)  /**< 12-The high level indicates that the frame reception was normally stopped by EOF pattern detection event. Relates to the TypeB RM/CM, B prime RM/CM modes.*/
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_ANTICOLL_POS2                                                     (11U)
#define CLIF_RX_STATUS_ERROR_RX_STOP_ON_ANTICOLL_MASK2                                                    (0x00000800U)  /**< 11-The high level indicates that the frame reception was normally stopped by collision detected on data bit position. Relates to the bit-oriented frame reception in TypeA RM 106 kbps mode during the anticollision procedure.*/
#define CLIF_RX_STATUS_ERROR_RX_CRC_ERROR_POS2                                                            (10U)
#define CLIF_RX_STATUS_ERROR_RX_CRC_ERROR_MASK2                                                           (0x00000400U)  /**< 10-The high level indicates that the CRC error is detected in the received frame.*/
#define CLIF_RX_STATUS_ERROR_RX_LEN_ERROR_POS2                                                            (9U)
#define CLIF_RX_STATUS_ERROR_RX_LEN_ERROR_MASK2                                                           (0x00000200U)  /**< 9-The high level is set if the received frame is shorter than the length stated in the received frame LEN field OR if the LEN parameter in the received frame violates the configured [RX_FRAME_MINLEN:RX_FRAME_MAX LEN] limits. Can assert only in the mode where the LEN field is used in the frame format (Felica RM/CM, FWEC RM/CM).*/
#define CLIF_RX_STATUS_ERROR_RX_SIGPRO_ERROR_POS2                                                         (8U)
#define CLIF_RX_STATUS_ERROR_RX_SIGPRO_ERROR_MASK2                                                        (0x00000100U)  /**< 8-The high level indicates that the communication error/errors were detected during the frame reception on physical layer(in the SigPro).*/
#define CLIF_RX_STATUS_ERROR_RX_PARITY_ERROR_POS2                                                         (7U)
#define CLIF_RX_STATUS_ERROR_RX_PARITY_ERROR_MASK2                                                        (0x00000080U)  /**< 7-The high level indicates that the parity error was detected during the frame reception.*/
#define CLIF_RX_STATUS_ERROR_RX_STOPBIT_ERROR_POS2                                                        (6U)
#define CLIF_RX_STATUS_ERROR_RX_STOPBIT_ERROR_MASK2                                                       (0x00000040U)  /**< 6-The high level indicates that the stop bit error (0 level instead of 1 on the stop bit position) was detected during the frame reception.*/
#define CLIF_RX_STATUS_ERROR_RX_WRITE_ERROR_POS2                                                          (5U)
#define CLIF_RX_STATUS_ERROR_RX_WRITE_ERROR_MASK2                                                         (0x00000020U)  /**< 5-The high level indicates that the error acknowledge status was received on the CLIF-system interface during the received frame transmission to the System RAM.*/
#define CLIF_RX_STATUS_ERROR_RX_BUFFER_OVFL_ERROR_POS2                                                    (4U)
#define CLIF_RX_STATUS_ERROR_RX_BUFFER_OVFL_ERROR_MASK2                                                   (0x00000010U)  /**< 4-The high level indicates that the data payload length in the received frame exceeds the 28 bytes limit. Relates to the PollReq procedure in the Felica RM mode only.*/
#define CLIF_RX_STATUS_ERROR_RX_LATENCY_ERROR_POS2                                                        (3U)
#define CLIF_RX_STATUS_ERROR_RX_LATENCY_ERROR_MASK2                                                       (0x00000008U)  /**< 3-The high level indicates that the write request flow was corrupted due to traffic congestion on the system interface during the received frame transmission to the System RAM.*/
#define CLIF_RX_STATUS_ERROR_RX_DATA_INTEGRITY_ERROR_POS2                                                 (2U)
#define CLIF_RX_STATUS_ERROR_RX_DATA_INTEGRITY_ERROR_MASK2                                                (0x00000004U)  /**< 2-The high level indicates that the data integrity corruption (parity/CRC/etc error)was detected in the received frame.*/
#define CLIF_RX_STATUS_ERROR_RX_PROTOCOL_ERROR_POS2                                                       (1U)
#define CLIF_RX_STATUS_ERROR_RX_PROTOCOL_ERROR_MASK2                                                      (0x00000002U)  /**< 1-The high level indicates that the protocol requirements violation (stop bit error,missing parity bit, not full byte received, etc) was detected in the received frame.*/
#define CLIF_RX_STATUS_ERROR_RX_CL_ERROR_POS2                                                             (0U)
#define CLIF_RX_STATUS_ERROR_RX_CL_ERROR_MASK2                                                            (0x00000001U)  /**< 0-The high level indicates that some protocol/data integrity error/errors were detected during the frame reception*/

#define CLIF_STATUS2                                                                                       0x7
#define CLIF_STATUS_RESERVED_POS2                                                                         (30U)
#define CLIF_STATUS_RESERVED_MASK2                                                                        (0xC0000000U)  /**< 30-Reserved */
#define CLIF_STATUS_CRC_OK_POS2                                                                           (29U)
#define CLIF_STATUS_CRC_OK_MASK2                                                                          (0x20000000U)  /**< 29-This bit indicates the status of the actual CRC calculation. If 1 the CRC is correct. meaning the CRC register has the value 0 or the residue value if inverted CRC is used. Note: This flag should only by evaluated at the end of a communication */
#define CLIF_STATUS_RX_SC_DETECTED_POS2                                                                   (28U)
#define CLIF_STATUS_RX_SC_DETECTED_MASK2                                                                  (0x10000000U)  /**< 28-Status signal indicating that a sub-carrier is detected.*/
#define CLIF_STATUS_RX_SOF_DETECTED_POS2                                                                  (27U)
#define CLIF_STATUS_RX_SOF_DETECTED_MASK2                                                                 (0x08000000U)  /**< 27-Status signal indicating that a SOF has been detected.*/
#define CLIF_STATUS_TX_RF_STATUS_POS2                                                                     (26U)
#define CLIF_STATUS_TX_RF_STATUS_MASK2                                                                    (0x04000000U)  /**< 26-If set to 1 this bit indicates that the drivers are turned on. meaning an RF-Field is created by the device itself. */
#define CLIF_STATUS_RF_DET_STATUS_POS2                                                                    (25U)
#define CLIF_STATUS_RF_DET_STATUS_MASK2                                                                   (0x02000000U)  /**< 25-If set to 1 this bit indicates that an external RF-Field is detected by the rf level detectors (after digital filtering) */
#define CLIF_STATUS_ADC_Q_CLIPPING_POS2                                                                   (24U)
#define CLIF_STATUS_ADC_Q_CLIPPING_MASK2                                                                  (0x01000000U)  /**< 24-Indicates that the Q-Channel ADC has clipped (value 0 or 63), This bit is reset with Rx-reset (enabling of receiver).*/
#define CLIF_STATUS_ADC_I_CLIPPING_POS2                                                                   (23U)
#define CLIF_STATUS_ADC_I_CLIPPING_MASK2                                                                  (0x00800000U)  /**< 23-Indicates that the I-Channel ADC has clipped (value 0 or 63), This bit is reset with Rx-reset (enabling of receiver).*/
#define CLIF_STATUS_RESERVED1_POS2                                                                        (12U)
#define CLIF_STATUS_RESERVED1_MASK2                                                                       (0x007FF000U)  /**< 12-22 Reserved */
#define CLIF_STATUS_TX_NO_DATA_ERROR_POS2                                                                 (11U)
#define CLIF_STATUS_TX_NO_DATA_ERROR_MASK2                                                                (0x00000800U)  /**< 11-This error flag is set to 1. in case a transmission is started but no data is available (register NumBytesToSend == 0). */
#define CLIF_STATUS_RF_ACTIVE_ERROR_CAUSE_POS2                                                            (8U)
#define CLIF_STATUS_RF_ACTIVE_ERROR_CAUSE_MASK2                                                           (0x00000700U)  /**< 8-This status flag indicates the cause of an NFC-Active error. Note: This bits are only valid when the RF_ACTIVE_ERROR_IRQ is raised and will be cleared as soon as the bit TX_RF_ENABLE is set to 1. 0* No Error. reset value 1 External field was detected on within TIDT timing 2 External field was detected on within TADT timing 3 No external field was detected within TADT timings 4 Peer did switch off RFField without but no Rx event was raised (no data received) 5 - 7 Reserved.*/
#define CLIF_STATUS_RESERVED2_POS2                                                                        (6U)
#define CLIF_STATUS_RESERVED2_MASK2                                                                       (0x000000C0U)  /**< 6-Reserved */
#define CLIF_STATUS_RX_ENABLE_POS2                                                                        (5U)
#define CLIF_STATUS_RX_ENABLE_MASK2                                                                       (0x00000020U)  /**< 5-This bit indicates if the RxDecoder is enabled. If 1 the RxDecoder was enabled by the Transceiver Unit and is now ready for data reception */
#define CLIF_STATUS_TX_ACTIVE_POS2                                                                        (4U)
#define CLIF_STATUS_TX_ACTIVE_MASK2                                                                       (0x00000010U)  /**< 4-This bit indicates activity of the TxEncoder. If 1 a transmission is ongoing otherwise the TxEncoder is in idle state.*/
#define CLIF_STATUS_RX_ACTIVE_POS2                                                                        (3U)
#define CLIF_STATUS_RX_ACTIVE_MASK2                                                                       (0x00000008U)  /**< 3-This bit indicates activity of the RxDecoder. If 1 a data reception is ongoing. otherwise the RxDecoder is in idle state. */
#define CLIF_STATUS_TRANSCEIVE_STATE_POS2                                                                 (0U)
#define CLIF_STATUS_TRANSCEIVE_STATE_MASK2                                                                (0x00000007U)  /**< 0-This registers hold the command bits 0* IDLE state 1 WaitTransmit state 2 Transmitting state 3 WaitReceive state 4 WaitForData state 5 Receiving state 6 LoopBack state 7 reserved*/

#define CLIF_TRANSCEIVE_CONTROL2                                                                           0x8
#define CLIF_TRANSCEIVE_CONTROL_RESERVED_POS2                                                             (16U)
#define CLIF_TRANSCEIVE_CONTROL_RESERVED_MASK2                                                            (0xFFFF0000U)  /**< 16-Reserved */
#define CLIF_TRANSCEIVE_CONTROL_TX_BITPHASE_POS2                                                          (8U)
#define CLIF_TRANSCEIVE_CONTROL_TX_BITPHASE_MASK2                                                         (0x0000FF00U)  /**< 8-15 Defines the number of 13.56MHz cycles used for adjustment of tx_wait to meet the FDT. */
#define CLIF_TRANSCEIVE_CONTROL_RESERVED1_POS2                                                            (4U)
#define CLIF_TRANSCEIVE_CONTROL_RESERVED1_MASK2                                                           (0x000000F0U)  /**< 4-14 Reserved */
#define CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_POS2                                                  (3U)
#define CLIF_TRANSCEIVE_CONTROL_TX_FRAMESTEP_ENABLE_MASK2                                                 (0x00000008U)  /**< 3-If set to 1. at every start of transmission. each byte of data is sent in a separate frame. SOF and EOF is appended to the data byte according to the framing settings. After one byte is transmitted. the TxEncoder waits for a new start trigger to continue with the next byte. */
#define CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_POS2                                                   (2U)
#define CLIF_TRANSCEIVE_CONTROL_RX_MULTIPLE_ENABLE_MASK2                                                  (0x00000004U)  /**< 2-If this bit is set to 1. the receiver is re-activated after the end of a reception. A status byte is written to the RAM containing all relevant status information of the frame. Note: Data in RAM is word aligned therefore empty bytes of a data Word in RAM are padded with 0x00 bytes. SW has to calculate the correct address for the following frame. */
#define CLIF_TRANSCEIVE_CONTROL_RESERVED2_POS2                                                            (0U)
#define CLIF_TRANSCEIVE_CONTROL_RESERVED2_MASK2                                                           (0x00000003U)  /**< 0-1 Reserved */

#define CLIF_TX_SYMBOL01_MOD2                                                                              0x9
#define CLIF_TX_SYMBOL01_MOD_RESERVED_POS2                                                                (24U)
#define CLIF_TX_SYMBOL01_MOD_RESERVED_MASK2                                                               (0xFF000000U)  /**< 24-Reserved */
#define CLIF_TX_SYMBOL01_MOD_TX_S01_MODWIDTH_POS2                                                         (16U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_MODWIDTH_MASK2                                                        (0x00FF0000U)  /**< 16-Specifies the length of a pulse for sending data of symbol 0/1. The length is given by the number of carrier clocks + 1. */
#define CLIF_TX_SYMBOL01_MOD_RESERVED1_POS2                                                               (9U)
#define CLIF_TX_SYMBOL01_MOD_RESERVED1_MASK2                                                              (0x0000FE00U)  /**< 9-Reserved */
#define CLIF_TX_SYMBOL01_MOD_TX_S01_MILLER_ENABLE_POS2                                                    (8U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_MILLER_ENABLE_MASK2                                                   (0x00000100U)  /**< 8-If set to 1. pulse modulation is applied according to modified miller coding. */
#define CLIF_TX_SYMBOL01_MOD_TX_S01_INV_ENV_POS2                                                          (7U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_INV_ENV_MASK2                                                         (0x00000080U)  /**< 7-If set to 1. the output envelope is inverted. */
#define CLIF_TX_SYMBOL01_MOD_TX_S01_ENV_TYPE_POS2                                                         (4U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_ENV_TYPE_MASK2                                                        (0x00000070U)  /**< 4-Specifies the type of envelope used for transmission of data packets. The selected envelope type is applied to the pseudo bit stream. 000b Direct output 001b Manchester code 010b Manchester code with subcarrier 011b BPSK 100b RZ (pulse of half bit length at beginning of second half of bit) 101b RZ (pulse of half bit length at beginning of bit) 110b Manchester tuple 111b RFU*/
#define CLIF_TX_SYMBOL01_MOD_TX_S01_SC_FREQ_POS2                                                          (3U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_SC_FREQ_MASK2                                                         (0x00000008U)  /**< 3-Specifies the frequency of the subcarrier. 0 424 kHz 1 848 kHz */
#define CLIF_TX_SYMBOL01_MOD_TX_S01_BIT_FREQ_POS2                                                         (0U)
#define CLIF_TX_SYMBOL01_MOD_TX_S01_BIT_FREQ_MASK2                                                        (0x00000007U)  /**< 0-Specifies the frequency of the bit-stream.  000b -> 1.695 MHz. 001b -> Reserved. 010b -> 26 kHz. 011b -> 53 kHz. 100b -> 106 kHz. 101b -> 212 kHz. 110b -> 424 kHz. 111b -> 848 kHz.*/

#define CLIF_TX_SYMBOL1_DEF2                                                                               0xA
#define CLIF_TX_SYMBOL1_DEF_TX_SYMBOL1_DEF_POS2                                                           (0U)
#define CLIF_TX_SYMBOL1_DEF_TX_SYMBOL1_DEF_MASK2                                                          (0xFFFFFFFFU)  /**< 0-Pattern definition for Symbol1 */

#define CLIF_TX_SYMBOL0_DEF2                                                                               0xB
#define CLIF_TX_SYMBOL0_DEF_TX_SYMBOL0_DEF_POS2                                                           (0U)
#define CLIF_TX_SYMBOL0_DEF_TX_SYMBOL0_DEF_MASK2                                                          (0xFFFFFFFFU)  /**< 0-Pattern definition for Symbol0*/

#define CLIF_TX_SYMBOL23_MOD2                                                                              0xC
#define CLIF_TX_SYMBOL23_MOD_RESERVED_POS2                                                                (24U)
#define CLIF_TX_SYMBOL23_MOD_RESERVED_MASK2                                                               (0xFF000000U)  /**< 24-Reserved */
#define CLIF_TX_SYMBOL23_MOD_TX_S23_MODWIDTH_POS2                                                         (16U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_MODWIDTH_MASK2                                                        (0x00FF0000U)  /**< 16-Specifies the length of a pulse for sending data of symbol 2/3. The length is given by the number of carrier clocks + 1.*/
#define CLIF_TX_SYMBOL23_MOD_RESERVED1_POS2                                                               (9U)
#define CLIF_TX_SYMBOL23_MOD_RESERVED1_MASK2                                                              (0x0000FE00U)  /**< 9-Reserved */
#define CLIF_TX_SYMBOL23_MOD_TX_S23_MILLER_ENABLE_POS2                                                    (8U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_MILLER_ENABLE_MASK2                                                   (0x00000100U)  /**< 8-If set to 1 pulse modulation is applied according to modified miller coding.*/
#define CLIF_TX_SYMBOL23_MOD_TX_S23_INV_ENV_POS2                                                          (7U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_INV_ENV_MASK2                                                         (0x00000080U)  /**< 7-If set to 1 the output envelope is inverted.*/
#define CLIF_TX_SYMBOL23_MOD_TX_S23_ENV_TYPE_POS2                                                         (4U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_ENV_TYPE_MASK2                                                        (0x00000070U)  /**< 4-Specifies the type of envelope used for transmission of data packets. The selected envelope type is applied to the pseudo bit stream. 000b Direct output 001b Manchester code 010b Manchester code with subcarrier 011b BPSK 100b RZ (pulse of half bit length at beginning of second half of bit) 101b RZ (pulse of half bit length at beginning of bit) 110b Manchester tuple 111b RFU*/
#define CLIF_TX_SYMBOL23_MOD_TX_S23_SC_FREQ_POS2                                                          (3U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_SC_FREQ_MASK2                                                         (0x00000008U)  /**< 3-Specifies the frequency of the subcarrier. 0 424 kHz 1 848 kHz*/
#define CLIF_TX_SYMBOL23_MOD_TX_S23_BIT_FREQ_POS2                                                         (0U)
#define CLIF_TX_SYMBOL23_MOD_TX_S23_BIT_FREQ_MASK2                                                        (0x00000007U)  /**< 0-Specifies the frequency of the bit-stream.  000b -> 1.695 MHz. 001b -> Reserved. 010b -> 26 kHz. 011b -> 53 kHz. 100b -> 106 kHz. 101b -> 212 kHz. 110b -> 424 kHz. 111b -> 848 kHz.*/

#define CLIF_TX_SYMBOL23_DEF2                                                                              0xD
#define CLIF_TX_SYMBOL23_DEF_RESERVED_POS2                                                                (24U)
#define CLIF_TX_SYMBOL23_DEF_RESERVED_MASK2                                                               (0xFF000000U)  /**< 24-Reserved */
#define CLIF_TX_SYMBOL23_DEF_TX_SYMBOL3_DEF_POS2                                                          (16U)
#define CLIF_TX_SYMBOL23_DEF_TX_SYMBOL3_DEF_MASK2                                                         (0x00FF0000U)  /**< 16-Pattern definition for Symbol3 */
#define CLIF_TX_SYMBOL23_DEF_RESERVED1_POS2                                                                (8U)
#define CLIF_TX_SYMBOL23_DEF_RESERVED1_MASK2                                                               (0x0000FF00U)  /**< 8-Reserved */
#define CLIF_TX_SYMBOL23_DEF_TX_SYMBOL2_DEF_POS2                                                          (0U)
#define CLIF_TX_SYMBOL23_DEF_TX_SYMBOL2_DEF_MASK2                                                         (0x000000FFU)  /**< 0-Pattern definition for Symbol2*/

#define CLIF_TX_SYMBOL_CONFIG2                                                                             0xE
#define CLIF_TX_SYMBOL_CONFIG_RESERVED_POS2                                                               (31U)
#define CLIF_TX_SYMBOL_CONFIG_RESERVED_MASK2                                                              (0x80000000U)  /**< 31-Reserved */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_LEN_POS2                                                   (27U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_LEN_MASK2                                                  (0x78000000U)  /**< 27-Specifies the number of bits issued for symbol 1 burst. The 3 bits encode a range from 8 to 256 bit length: 0000b 8 bit 0001b 12 bit 0010b 16 bit 0011b 24 bit 0100b 32 bit 0101b 40 bit 0110b 48 bit 0111b 64 bit 1000b 80 bit 1001b 96 bit 1010b 112 bit 1011b 128 bit 1100b 160 bit 1101b 192 bit 1110b 224 bit 1111b 256 bit*/
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_TYPE_POS2                                                  (26U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_TYPE_MASK2                                                 (0x04000000U)  /**< 26-Specifies the type of the burst of Symbol1 (logical zero / logical one) */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_ONLY_POS2                                                  (25U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_ONLY_MASK2                                                 (0x02000000U)  /**< 25-If set to 1. Symbol1 consists only of a burst and no symbol pattern */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_ENABLE_POS2                                                (24U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_BURST_ENABLE_MASK2                                               (0x01000000U)  /**< 24-If set to 1. the burst of Symbol0 of the length defined in bit field SYMBOL1_BURST_LEN is enabled         */
#define CLIF_TX_SYMBOL_CONFIG_RESERVED1_POS2                                                              (23U)
#define CLIF_TX_SYMBOL_CONFIG_RESERVED1_MASK2                                                             (0x00800000U)  /**< 23-Reserved */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_LEN_POS2                                                   (19U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_LEN_MASK2                                                  (0x00780000U)  /**< 19-Specifies the number of bits issued for symbol 0 burst. The 3 bits encode a range from 8 to 256 bit length: 0000b 8 bit 0001b 12 bit 0010b 16 bit 0011b 24 bit 0100b 32 bit 0101b 40 bit 0110b 48 bit 0111b 64 bit 1000b 80 bit 1001b 96 bit 1010b 112 bit 1011b 128 bit 1100b 160 bit 1101b 192 bit 1110b 224 bit 1111b 256 bit*/
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_TYPE_POS2                                                  (18U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_TYPE_MASK2                                                 (0x00040000U)  /**< 18-Specifies the type of the burst of Symbol0 (logical zero / logical one) */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_ONLY_POS2                                                  (17U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_ONLY_MASK2                                                 (0x00020000U)  /**< 17-If set to 1. Symbol0 consists only of a burst and no symbol pattern */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_ENABLE_POS2                                                (16U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_BURST_ENABLE_MASK2                                               (0x00010000U)  /**< 16-If set to 1. the burst of Symbol0 of the length defined in bit field SYMBOL0_BURST_LEN is enabled */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL3_LEN_POS2                                                         (13U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL3_LEN_MASK2                                                        (0x0000E000U)  /**< 13-Specifies the number of valid bits of the symbol definition of Symbol3. The range is from 1 bit (value 0000) to 8 bit (value 111) */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL2_LEN_POS2                                                         (10U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL2_LEN_MASK2                                                        (0x00001C00U)  /**< 10-Specifies the number of valid bits of the symbol definition of Symbol2. The range is from 1 bit (value 0000) to 8bit (value 111) */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_LEN_POS2                                                         (5U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL1_LEN_MASK2                                                        (0x000003E0U)  /**< 5-Specifies the number of valid bits of the symbol definition of Symbol1. The range is from 1 bit (value 0000) to 31 bits (value 11110) */
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_LEN_POS2                                                         (0U)
#define CLIF_TX_SYMBOL_CONFIG_TX_SYMBOL0_LEN_MASK2                                                        (0x0000001FU)  /**< 0-Specifies the number of valid bits of the symbol definition of Symbol0. The range is from 1 bit (value 0000) to 31 bits (value 11110)*/

#define CLIF_TX_FRAME_CONFIG2                                                                              0xF
#define CLIF_TX_FRAME_CONFIG_RESERVED_POS2                                                                (19U)
#define CLIF_TX_FRAME_CONFIG_RESERVED_MASK2                                                               (0xFFF80000U)  /**< 19-Reserved */
#define CLIF_TX_FRAME_CONFIG_TX_DATA_CODE_TYPE_POS2                                                       (16U)
#define CLIF_TX_FRAME_CONFIG_TX_DATA_CODE_TYPE_MASK2                                                      (0x00070000U)  /**< 16-Specifies the type of encoding of data to be used 000b No special code 001b 1 out of 4 code [I-Code SLI] 010b 1 out of 256 code [I-Code SLI] 011b Pulse interval encoding (PIE) [I-Code EPC-V2] 100b 2bit tuple code (intended only for test purpose) 101-111b Reserved */
#define CLIF_TX_FRAME_CONFIG_TX_STOPBIT_TYPE_POS2                                                         (13U)
#define CLIF_TX_FRAME_CONFIG_TX_STOPBIT_TYPE_MASK2                                                        (0x0000E000U)  /**< 13-Enables the stop bit (logic 1) and extra guard time (logic 1). The value 0 disables transmission of stop-bits. 000b no stop-bit. no EGT 001b stop-bit. no EGT 010b stop-bit + 1 EGT 011b stop-bit + 2 EGT 100b stop-bit + 3 EGT 101b stop-bit + 4 EGT 110b stop-bit + 5 EGT 111b stop-bit + 6 EGT */
#define CLIF_TX_FRAME_CONFIG_TX_STARTBIT_ENABLE_POS2                                                      (12U)
#define CLIF_TX_FRAME_CONFIG_TX_STARTBIT_ENABLE_MASK2                                                     (0x00001000U)  /**< 12-If set to 1. a start-bit (logic 0) will be send */
#define CLIF_TX_FRAME_CONFIG_TX_MSB_FIRST_POS2                                                            (11U)
#define CLIF_TX_FRAME_CONFIG_TX_MSB_FIRST_MASK2                                                           (0x00000800U)  /**< 11-If set to 1. data bytes are interpreted MSB first for data transmission */
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_LAST_INV_ENABLE_POS2                                               (10U)
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_LAST_INV_ENABLE_MASK2                                              (0x00000400U)  /**< 10-If set to 1. the parity bit of last sent data byte is inverted */
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_TYPE_POS2                                                          (9U)
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_TYPE_MASK2                                                         (0x00000200U)  /**< 9-Defines the type of the parity bit 0 Even Parity is calculated 1 Odd parity is calculated       */
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_POS2                                                        (8U)
#define CLIF_TX_FRAME_CONFIG_TX_PARITY_ENABLE_MASK2                                                       (0x00000100U)  /**< 8-If set to 1. a parity bit is calculated and appended to each byte transmitted. If the Transmission Of Data Is Enabled and TX_NUM_BYTES_2_SEND is zero. then a NO_DATA_ERROR occurs. */
#define CLIF_TX_FRAME_CONFIG_RESERVED1_POS2                                                               (5U)
#define CLIF_TX_FRAME_CONFIG_RESERVED1_MASK2                                                              (0x000000E0U)  /**< 5-Reserved */
#define CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_POS2                                                          (4U)
#define CLIF_TX_FRAME_CONFIG_TX_DATA_ENABLE_MASK2                                                         (0x00000010U)  /**< 4-If set to 1. transmission of data is enabled otherwise only symbols are transmitted. */
#define CLIF_TX_FRAME_CONFIG_TX_STOP_SYMBOL_POS2                                                          (2U)
#define CLIF_TX_FRAME_CONFIG_TX_STOP_SYMBOL_MASK2                                                         (0x0000000CU)  /**< 2-Defines which pattern symbol is sent as frame stop-symbol 00b No symbol is sent 01b Symbol1 is sent 10b Symbol2 is sent 11b Symbol3 is sent */
#define CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_POS2                                                         (0U)
#define CLIF_TX_FRAME_CONFIG_TX_START_SYMBOL_MASK2                                                        (0x00000003U)  /**< 0-Defines which symbol pattern is sent as frame start-symbol 00b No symbol pattern is sent 01b Symbol0 is sent 10b Symbol1 is sent 11b Symbol2 is sent*/

#define CLIF_TX_DATA_MOD2                                                                                  0x10
#define CLIF_TX_DATA_MOD_RESERVED_POS2                                                                    (25U)
#define CLIF_TX_DATA_MOD_RESERVED_MASK2                                                                   (0xFE000000U)  /**< 25-Reserved*/
#define CLIF_TX_DATA_MOD_TX_ICODE_DATA_MODWIDTH_ENABLE_POS2                                               (24U)
#define CLIF_TX_DATA_MOD_TX_ICODE_DATA_MODWIDTH_ENABLE_MASK2                                              (0x01000000U)  /**< 24-Enables modulation width of icode data. Width of modulation is defined by the TX_DATA_MODWIDTH field. When 1, we should have TX_DATA_ENV_TYPE=0 and TX_DATA_INV_ENV=0*/
#define CLIF_TX_DATA_MOD_TX_DATA_MODWIDTH_POS2                                                            (16U)
#define CLIF_TX_DATA_MOD_TX_DATA_MODWIDTH_MASK2                                                           (0x00FF0000U)  /**< 16-Specifies the length of a pulse for sending data with miller pulse modulation enabled. The length is given by the number of carrier clocks + 1.*/
#define CLIF_TX_DATA_MOD_RESERVED1_POS2                                                                   (9U)
#define CLIF_TX_DATA_MOD_RESERVED1_MASK2                                                                  (0x0000FE00U)  /**< 9-Reserved*/
#define CLIF_TX_DATA_MOD_TX_DATA_MILLER_ENABLE_POS2                                                       (8U)
#define CLIF_TX_DATA_MOD_TX_DATA_MILLER_ENABLE_MASK2                                                      (0x00000100U)  /**< 8-If set to 1 pulse modulation is applied according to modified miller coding*/
#define CLIF_TX_DATA_MOD_TX_DATA_INV_ENV_POS2                                                             (7U)
#define CLIF_TX_DATA_MOD_TX_DATA_INV_ENV_MASK2                                                            (0x00000080U)  /**< 7-If set to 1 the output envelope is inverted*/
#define CLIF_TX_DATA_MOD_TX_DATA_ENV_TYPE_POS2                                                            (4U)
#define CLIF_TX_DATA_MOD_TX_DATA_ENV_TYPE_MASK2                                                           (0x00000070U)  /**< 4-Specifies the type of envelope used for transmission of data packets. The selected envelope type is applied to the pseudo bit stream. 000b Direct output 001b Manchester code 010b Manchester code with subcarrier 011b BPSK 100b RZ (pulse of half bit length at beginning of second half of bit) 101b RZ (pulse of half bit length at beginning of bit) 110b Manchester tuple coding 111b RFU*/
#define CLIF_TX_DATA_MOD_TX_DATA_SC_FREQ_POS2                                                             (3U)
#define CLIF_TX_DATA_MOD_TX_DATA_SC_FREQ_MASK2                                                            (0x00000008U)  /**< 3-Specifies the frequency of the subcarrier. 0 424 kHz 1 848 kHz*/
#define CLIF_TX_DATA_MOD_TX_DATA_BIT_FREQ_POS2                                                            (0U)
#define CLIF_TX_DATA_MOD_TX_DATA_BIT_FREQ_MASK2                                                           (0x00000007U)  /**< 0-Specifies the frequency of the bit-stream.  000b -> 1.695 MHz. 001b -> Reserved. 010b -> 26 kHz. 011b -> 53 kHz. 100b -> 106 kHz. 101b -> 212 kHz. 110b -> 424 kHz. 111b -> 848 kHz.*/

#define CLIF_TX_WAIT2                                                                                      0x11
#define CLIF_TX_WAIT_RESERVED_POS2                                                                        (28U)
#define CLIF_TX_WAIT_RESERVED_MASK2                                                                       (0xF0000000U)  /**< 28-Reserved */
#define CLIF_TX_WAIT_TX_WAIT_VALUE_POS2                                                                   (8U)
#define CLIF_TX_WAIT_TX_WAIT_VALUE_MASK2                                                                  (0x0FFFFF00U)  /**< 8-Defines the tx_wait timer reload value. Note: If set to 00000h the tx_wait guard time is disabled Note: This bit is set by HW a protocol is detected in automatic mode detection*/
#define CLIF_TX_WAIT_TX_WAIT_PRESCALER_POS2                                                               (0U)
#define CLIF_TX_WAIT_TX_WAIT_PRESCALER_MASK2                                                              (0x000000FFU)  /**< 0-Defines the prescaler reload value for the tx_wait timer. Note: This bit is set by HW a protocol is  detected in automatic mode detection*/

#define CLIF_CRC_TX_CONFIG2                                                                                0x12
#define CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_VALUE_POS2                                                       (16U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_VALUE_MASK2                                                      (0xFFFF0000U)  /**< 16-Arbitrary preset value for the Tx-Encoder CRC calculation. */
#define CLIF_CRC_TX_CONFIG_RESERVED_POS2                                                                  (7U)
#define CLIF_CRC_TX_CONFIG_RESERVED_MASK2                                                                 (0x0000FF80U)  /**< 7-Reserved */
#define CLIF_CRC_TX_CONFIG_TX_CRC_BYTE2_ENABLE_POS2                                                       (6U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_BYTE2_ENABLE_MASK2                                                      (0x00000040U)  /**< 6-If set. the CRC is calculated from the 2nd byte onwards (intended for HID). Note that this option is used in the Tx-Encoder.           */
#define CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_POS2                                                         (3U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_PRESET_SEL_MASK2                                                        (0x00000038U)  /**< 3-Preset value of the CRC register for the Tx-Encoder. For a CRC calculation using 5bits. only the LSByte is used. 000b* 0000h. reset value 001b  6363h 010b A671h 011b  FFFFh 100b 0012h 101b E012h 110b RFU 111b Use arbitrary preset value TX_CRC_PRESET_VALUE*/
#define CLIF_CRC_TX_CONFIG_TX_CRC_TYPE_POS2                                                               (2U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_TYPE_MASK2                                                              (0x00000004U)  /**< 2-Controls the type of CRC calculation for the Tx-Encoder 0* 16bit CRC calculation. reset value 1 5bit CRC calculation */
#define CLIF_CRC_TX_CONFIG_TX_CRC_INV_POS2                                                                (1U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_INV_MASK2                                                               (0x00000002U)  /**< 1-Controls the sending of an inverted CRC value by the Tx-Encoder 0* Not inverted CRC checksum. reset value 1 Inverted CRC checksum */
#define CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_POS2                                                             (0U)
#define CLIF_CRC_TX_CONFIG_TX_CRC_ENABLE_MASK2                                                            (0x00000001U)  /**< 0-If set to one. the Tx-Encoder will compute and transmit a CRC.*/

#define CLIF_TX_UNDERSHOOT_CONFIG2                                                                         0x13
#define CLIF_TX_UNDERSHOOT_CONFIG_RESERVED_POS2                                                           (0U)
#define CLIF_TX_UNDERSHOOT_CONFIG_RESERVED_MASK2                                                          (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_TX_OVERSHOOT_CONFIG2                                                                          0x14
#define CLIF_TX_OVERSHOOT_CONFIG_RESERVED_POS2                                                            (0U)
#define CLIF_TX_OVERSHOOT_CONFIG_RESERVED_MASK2                                                           (0xFFFFFFFFU)  /**< 0-Reserved */

#define CLIF_SS_TX_CFG2                                                                                    0x15
#define CLIF_SS_TX_CFG_RESERVED_POS2                                                                      (14U)
#define CLIF_SS_TX_CFG_RESERVED_MASK2                                                                     (0xFFFFC000U)  /**< 14-Reserved*/
#define CLIF_SS_TX_CFG_TX2_USE_TX1_CONF_POS2                                                              (13U)
#define CLIF_SS_TX_CFG_TX2_USE_TX1_CONF_MASK2                                                             (0x00002000U)  /**< 13-When 1, the tx1 configuration is used also for tx2: all CLIF_SS_TX2_* registers are discarded and configurations from corresponding CLIF_SS_TX1 register is used.*/
#define CLIF_SS_TX_CFG_RESERVED1_POS2                                                                     (6U)
#define CLIF_SS_TX_CFG_RESERVED1_MASK2                                                                    (0x00001FC0U)  /**< 6-Reserved*/
#define CLIF_SS_TX_CFG_TX2_CLK_MODE_DEFAULT_POS2                                                          (3U)
#define CLIF_SS_TX_CFG_TX2_CLK_MODE_DEFAULT_MASK2                                                         (0x00000038U)  /**< 3-TX2 clk mode without field (RM and CM)*/
#define CLIF_SS_TX_CFG_TX1_CLK_MODE_DEFAULT_POS2                                                          (0U)
#define CLIF_SS_TX_CFG_TX1_CLK_MODE_DEFAULT_MASK2                                                         (0x00000007U)  /**< 0-TX1 clk mode without field (RM and CM)*/

#define CLIF_SS_TX1_RMCFG2                                                                                 0x16U
#define CLIF_SS_TX1_RMCFG_RESERVED_POS2                                                                   (25U)
#define CLIF_SS_TX1_RMCFG_RESERVED_MASK2                                                                  (0xFE000000U)  /**< 25-Reserved*/
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_TRANS_RM_POS2                                                      (22U)
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_TRANS_RM_MASK2                                                     (0x01C00000U)  /**< 22-TX1 clock mode in RM during transition*/
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_MOD_RM_POS2                                                        (19U)
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_MOD_RM_MASK2                                                       (0x00380000U)  /**< 19-TX1 clock mode of modulated wave in RM*/
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_CW_RM_POS2                                                         (16U)
#define CLIF_SS_TX1_RMCFG_TX1_CLK_MODE_CW_RM_MASK2                                                        (0x00070000U)  /**< 16-TX1 clock mode of unmodulated wave in RM*/
#define CLIF_SS_TX1_RMCFG_TX1_AMP_MOD_RM_POS2                                                             (8U)
#define CLIF_SS_TX1_RMCFG_TX1_AMP_MOD_RM_MASK2                                                            (0x0000FF00U)  /**< 8-TX1 amplitude of modulated wave in RM*/
#define CLIF_SS_TX1_RMCFG_TX1_AMP_CW_RM_POS2                                                              (0U)
#define CLIF_SS_TX1_RMCFG_TX1_AMP_CW_RM_MASK2                                                             (0x000000FFU)  /**< 0-TX1 amplitude of unmodulated wave in RM*/

#define CLIF_SS_TX2_RMCFG2                                                                                 0x17U
#define CLIF_SS_TX2_RMCFG_RESERVED_POS2                                                                   (25U)
#define CLIF_SS_TX2_RMCFG_RESERVED_MASK2                                                                  (0xFE000000U)  /**< 25-Reserved*/
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_TRANS_RM_POS2                                                      (22U)
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_TRANS_RM_MASK2                                                     (0x01C00000U)  /**< 22-TX2 clock mode in RM during transition*/
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_MOD_RM_POS2                                                        (19U)
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_MOD_RM_MASK2                                                       (0x00380000U)  /**< 19-TX2 clock mode of modulated wave in RM*/
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_CW_RM_POS2                                                         (16U)
#define CLIF_SS_TX2_RMCFG_TX2_CLK_MODE_CW_RM_MASK2                                                        (0x00070000U)  /**< 16-TX2 clock mode of unmodulated wave in RM*/
#define CLIF_SS_TX2_RMCFG_TX2_AMP_MOD_RM_POS2                                                             (8U)
#define CLIF_SS_TX2_RMCFG_TX2_AMP_MOD_RM_MASK2                                                            (0x0000FF00U)  /**< 8-TX2 amplitude of modulated wave in RM*/
#define CLIF_SS_TX2_RMCFG_TX2_AMP_CW_RM_POS2                                                              (0U)
#define CLIF_SS_TX2_RMCFG_TX2_AMP_CW_RM_MASK2                                                             (0x000000FFU)  /**< 0-TX2 amplitude of unmodulated wave in RM*/

#define CLIF_SIGPRO_CONFIG2                                                                                0x1D
#define CLIF_SIGPRO_CONFIG_RESERVED_POS2                                                                  (0U)
#define CLIF_SIGPRO_CONFIG_RESERVED_MASK2                                                                 (0xFFFFFFFFU)  /**< 0-RFU*/

#define CLIF_SIGPRO_RM_CONFIG2                                                                             0x1F
#define CLIF_SIGPRO_RM_CONFIG_RESERVED_POS2                                                               (0U)
#define CLIF_SIGPRO_RM_CONFIG_RESERVED_MASK2                                                              (0xFFFFFFFFU)  /**< 0-RFU*/

#define CLIF_SIGPRO_RM_PATTERN2                                                                            0x20
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_POS2                                                       (16U)
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_MASK2                                                      (0xFFFF0000U)  /**< 16-Sync pattern for Felica. LSB transmitted last*/
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_EXT4_POS2                                                  (15U)
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_EXT4_MASK2                                                 (0x00008000U)  /**< 15-extend Felica sync pattern with 16 leading 0s*/
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_EXT2_POS2                                                  (14U)
#define CLIF_SIGPRO_RM_PATTERN_RM_SYNC_PATTERN_EXT2_MASK2                                                 (0x00004000U)  /**< 14-extend Felica sync pattern with 8 leading 0s*/
#define CLIF_SIGPRO_RM_PATTERN_RM_RECEIVE_TILL_END_POS2                                                   (13U)
#define CLIF_SIGPRO_RM_PATTERN_RM_RECEIVE_TILL_END_MASK2                                                  (0x00002000U)  /**< 13-do not stop the reception before RxDecoder sends a stop command*/
#define CLIF_SIGPRO_RM_PATTERN_RESERVED_POS2                                                              (12U)
#define CLIF_SIGPRO_RM_PATTERN_RESERVED_MASK2                                                             (0x00001000U)  /**< 12-Reserved*/
#define CLIF_SIGPRO_RM_PATTERN_RM_SOF_PATTERN_POS2                                                        (0U)
#define CLIF_SIGPRO_RM_PATTERN_RM_SOF_PATTERN_MASK2                                                       (0x00000FFFU)  /**< 0-SOF pattern for Type B. LSB transmitted last or Start Byte pattern for NFC passive.*/

#define CLIF_SIGPRO_RM_ENABLES2                                                                            0x21
#define CLIF_SIGPRO_RM_ENABLES_RESERVED_POS2                                                              (0U)
#define CLIF_SIGPRO_RM_ENABLES_RESERVED_MASK2                                                             (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_SIGPRO_RM_TECH2                                                                               0x22
#define CLIF_SIGPRO_RM_TECH_RESERVED_POS2                                                                 (17U)
#define CLIF_SIGPRO_RM_TECH_RESERVED_MASK2                                                                (0xFFFE0000U)  /**< 17-Reserved*/
#define CLIF_SIGPRO_RM_TECH_RM_MF_GAIN_POS2                                                               (15U)
#define CLIF_SIGPRO_RM_TECH_RM_MF_GAIN_MASK2                                                              (0x00018000U)  /**< 15-Defines the gain of the Matched-Filters*/
#define CLIF_SIGPRO_RM_TECH_RESERVED1_POS2                                                                (0U)
#define CLIF_SIGPRO_RM_TECH_RESERVED1_MASK2                                                               (0x00007FFFU)  /**< 0-Reserved*/

#define CLIF_SIGPRO_NOISE_CONFIG12                                                                         0x23
#define CLIF_SIGPRO_NOISE_CONFIG1_RESERVED_POS2                                                           (0U)
#define CLIF_SIGPRO_NOISE_CONFIG1_RESERVED_MASK2                                                          (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_SIGPRO_NOISE_CONFIG22                                                                         0x24
#define CLIF_SIGPRO_NOISE_CONFIG2_RESERVED_POS2                                                           (0U)
#define CLIF_SIGPRO_NOISE_CONFIG2_RESERVED_MASK2                                                          (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_RX_PROTOCOL_CONFIG2                                                                           0x25
#define CLIF_RX_PROTOCOL_CONFIG_RESERVED_POS2                                                             (6U)
#define CLIF_RX_PROTOCOL_CONFIG_RESERVED_MASK2                                                            (0xFFFFFFC0U)  /**< 6-Reserved*/
#define CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_POS2                                                         (3U)
#define CLIF_RX_PROTOCOL_CONFIG_RX_BIT_ALIGN_MASK2                                                        (0x00000038U)  /**< 3-Defines the position of the 1st received data bit in the formed data byte.000b - 0 position...111b - 7th position*/
#define CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_TYPE_POS2                                                       (2U)
#define CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_TYPE_MASK2                                                      (0x00000004U)  /**< 2-0 - data + parity bits contain even number of 1. 1 - data + parity bits contain odd number of 1. Valid if cfg_rx_parity_enable_i ==1.*/
#define CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_POS2                                                     (1U)
#define CLIF_RX_PROTOCOL_CONFIG_RX_PARITY_ENABLE_MASK2                                                    (0x00000002U)  /**< 1-If set to 1, the bit following last data bit in the frame character is considered as parity bit.*/
#define CLIF_RX_PROTOCOL_CONFIG_RESERVED1_POS2                                                            (0U)
#define CLIF_RX_PROTOCOL_CONFIG_RESERVED1_MASK2                                                           (0x00000001U)  /**< 0-Reserved.*/

#define CLIF_RX_FRAME_LENGTH2                                                                              0x26
#define CLIF_RX_FRAME_LENGTH_RESERVED_POS2                                                                (31U)
#define CLIF_RX_FRAME_LENGTH_RESERVED_MASK2                                                               (0x80000000U)  /**< 31-Reserved*/
#define CLIF_RX_FRAME_LENGTH_RX_FRAME_MAXLEN_POS2                                                         (16U)
#define CLIF_RX_FRAME_LENGTH_RX_FRAME_MAXLEN_MASK2                                                        (0x7FFF0000U)  /**< 16-Maximal number of received [DATA + CRC] bits in the frame. The violation of the maximum length limit can be also configured as an Error/EMD condition. If the max length violation is configured as error - the frame reception is stopped in case of maximum length limit exceeding. Otherwise the reception is continued.0x0000 - 1 bit...0x7FFF - 32K bits*/
#define CLIF_RX_FRAME_LENGTH_RESERVED1_POS2                                                               (15U)
#define CLIF_RX_FRAME_LENGTH_RESERVED1_MASK2                                                              (0x00008000U)  /**< 15-Reserved*/
#define CLIF_RX_FRAME_LENGTH_RX_FRAME_MINLEN_POS2                                                         (0U)
#define CLIF_RX_FRAME_LENGTH_RX_FRAME_MINLEN_MASK2                                                        (0x00007FFFU)  /**< 0-Minimal number of received [DATA + CRC] bits in the frame. The violation of the minimum length limit can be also configured as an Error/EMD condition.The parameter also defines the number of received[DATA + CRC] bits before which any of the EOF pattern or INVPAR stop condition events are ignored.0x0000 - 1 bit...0x7FFF - 32K bits*/

#define CLIF_RX_ERROR_CONFIG2                                                                              0x27
#define CLIF_RX_ERROR_CONFIG_RESERVED_POS2                                                                (0U)
#define CLIF_RX_ERROR_CONFIG_RESERVED_MASK2                                                               (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_RXCTRL_STATUS2                                                                                0x28
#define CLIF_RXCTRL_STATUS_RXCTRL_RESERVED_POS2                                                           (9U)
#define CLIF_RXCTRL_STATUS_RXCTRL_RESERVED_MASK2                                                          (0xFFFFFE00U)  /**< 9-Reserved*/
#define CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_POS2                                                         (3U)
#define CLIF_RXCTRL_STATUS_RXCTRL_HF_ATT_VAL_MASK2                                                        (0x000001F8U)  /**< 3-8 HF attenuator value*/
#define CLIF_RXCTRL_STATUS_RXCTRL_RESERVED1_POS2                                                          (0U)
#define CLIF_RXCTRL_STATUS_RXCTRL_RESERVED1_MASK2                                                         (0x00000007U)  /**< 0-Reserved*/

#define CLIF_SIGPRO_IIR_CONFIG12                                                                           0x29
#define CLIF_SIGPRO_IIR_CONFIG1_RESERVED_POS2                                                             (0U)
#define CLIF_SIGPRO_IIR_CONFIG1_RESERVED_MASK2                                                            (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_SIGPRO_IIR_CONFIG02                                                                           0x2A
#define CLIF_SIGPRO_IIR_CONFIG0_RESERVED_POS2                                                             (0U)
#define CLIF_SIGPRO_IIR_CONFIG0_RESERVED_MASK2                                                            (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_DGRM_DAC_FILTER2                                                                              0x2B
#define CLIF_DGRM_DAC_FILTER_RESERVED_POS2                                                                (0U)
#define CLIF_DGRM_DAC_FILTER_RESERVED_MASK2                                                               (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_DGRM_CONFIG2                                                                                  0x2C
#define CLIF_DGRM_CONFIG_RESERVED_POS2                                                                    (0U)
#define CLIF_DGRM_CONFIG_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_DGRM_BBA2                                                                                     0x2D
#define CLIF_DGRM_BBA_RESERVED_POS2                                                                       (17U)
#define CLIF_DGRM_BBA_RESERVED_MASK2                                                                      (0xFFFE0000U)  /**< 17-31 Reserved*/
#define CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_POS2                                                               (14U)
#define CLIF_DGRM_BBA_DGRM_BBA_MIN_VAL_MASK2                                                              (0x0001C000U)  /**< 14-16 Defines the minimum value of BBA gain. */
#define CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_POS2                                                               (11U)
#define CLIF_DGRM_BBA_DGRM_BBA_MAX_VAL_MASK2                                                              (0x00003800U)  /**< 11-13 Defines the maximum value of BBA gain.*/
#define CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_POS2                                                              (8U)
#define CLIF_DGRM_BBA_DGRM_BBA_INIT_VAL_MASK2                                                             (0x00000700U)  /**< 8-10 Defines initial value of BBA gain. If BBA fast and slow modes are disabled, this value defines the forced value.*/
#define CLIF_DGRM_BBA_RESERVED1_POS2                                                                      (0U)
#define CLIF_DGRM_BBA_RESERVED1_MASK2                                                                     (0x000000FFU)  /**< 0-7 Reserved */

#define CLIF_DGRM_DCO2                                                                                     0x2E
#define CLIF_DGRM_DCO_RESERVED_POS2                                                                       (0U)
#define CLIF_DGRM_DCO_RESERVED_MASK2                                                                      (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_DGRM_HF_ATT2                                                                                  0x2F
#define CLIF_DGRM_HF_ATT_RESERVED_POS2                                                                    (0U)
#define CLIF_DGRM_HF_ATT_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_DGRM_RSSI2                                                                                    0x30
#define CLIF_DGRM_RSSI_RESERVED_POS2                                                                      (30U)
#define CLIF_DGRM_RSSI_RESERVED_MASK2                                                                     (0xC0000000U)  /**< 30-Reserved*/
#define CLIF_DGRM_RSSI_DGRM_SIGNAL_DETECT_TH_OVR_POS2                                                     (29U)
#define CLIF_DGRM_RSSI_DGRM_SIGNAL_DETECT_TH_OVR_MASK2                                                    (0x20000000U)  /**< 29-Enables the override of signal detect threshold. Override value is set based on DGRM_SIGNAL_DETECT_TH_OVR_VAL.*/
#define CLIF_DGRM_RSSI_RESERVED1_POS2                                                                     (23U)
#define CLIF_DGRM_RSSI_RESERVED1_MASK2                                                                    (0x1F800000U)  /**< 23-28 Reserved*/
#define CLIF_DGRM_RSSI_DGRM_RSSI_HYST_POS2                                                                (17U)
#define CLIF_DGRM_RSSI_DGRM_RSSI_HYST_MASK2                                                               (0x007E0000U)  /**< 17-Hysteresis value for RSSI target*/
#define CLIF_DGRM_RSSI_DGRM_RSSI_TARGET_POS2                                                              (7U)
#define CLIF_DGRM_RSSI_DGRM_RSSI_TARGET_MASK2                                                             (0x0001FF80U)  /**< 7-RSSI target value*/
#define CLIF_DGRM_RSSI_DGRM_SIGNAL_DETECT_TH_OVR_VAL_POS2                                                 (0U)
#define CLIF_DGRM_RSSI_DGRM_SIGNAL_DETECT_TH_OVR_VAL_MASK2                                                (0x0000007FU)  /**< 0-Defines the override value for signal detect threshold when DGRM_SIGNAL_DETECT_TH_OVR is set.*/

#define CLIF_CRC_RX_CONFIG2                                                                                0x31
#define CLIF_CRC_RX_CONFIG_RX_CRC_PRESET_VALUE_POS2                                                       (16U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_PRESET_VALUE_MASK2                                                      (0xFFFF0000U)  /**< 16-Arbitrary preset value for the Rx-Decoder CRC calculation. */
#define CLIF_CRC_RX_CONFIG_RESERVED_POS2                                                                  (8U)
#define CLIF_CRC_RX_CONFIG_RESERVED_MASK2                                                                 (0x0000FF00U)  /**< 8-Reserved */
#define CLIF_CRC_RX_CONFIG_RX_FORCE_CRC_WRITE_POS2                                                        (7U)
#define CLIF_CRC_RX_CONFIG_RX_FORCE_CRC_WRITE_MASK2                                                       (0x00000080U)  /**< 7-If set. the Rx-Decoder will send to the RAM the CRC bits as well.*/
#define CLIF_CRC_RX_CONFIG_RX_CRC_ALLOW_BITS_POS2                                                         (6U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_ALLOW_BITS_MASK2                                                        (0x00000040U)  /**< 6-If activated the frame with length =< CRC_length will be always sent to the System RAM as is, without CRC bits removal.*/
#define CLIF_CRC_RX_CONFIG_RX_CRC_PRESET_SEL_POS2                                                         (3U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_PRESET_SEL_MASK2                                                        (0x00000038U)  /**< 3-Preset value of the CRC register for the Rx-Decoder. For a CRC calculation using 5bits only the LSByte is used. 000b* 0000h reset value Note that this configuration is set by the Mode detector for FeliCa. 001b  6363h Note that this configuration is set by the Mode detector for ISO14443 type A. 010b  A671h 011b FFFFh Note that this configuration is set by the Mode detector for ISO14443 type B. 100b 0012h 101b E012h 110b RFU 111b Use arbitrary preset value RX_CRC_PRESET_VALUE*/
#define CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_POS2                                                               (2U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_TYPE_MASK2                                                              (0x00000004U)  /**< 2-Controls the type of CRC calculation for the Rx-Decoder 0* 16bit CRC calculation. reset value 1 5bit CRC calculation */
#define CLIF_CRC_RX_CONFIG_RX_CRC_INV_POS2                                                                (1U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_INV_MASK2                                                               (0x00000002U)  /**< 1-Controls the comparison of the CRC checksum for the Rx-Decoder 0* Not inverted CRC value: 0000h reset value Note that this nit is cleared by the Mode detector for ISO14443 type A and FeliCa. 1 Inverted CRC value: F0B8h Note that this bit is set by the Mode detector for ISO14443 type B.*/
#define CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_POS2                                                             (0U)
#define CLIF_CRC_RX_CONFIG_RX_CRC_ENABLE_MASK2                                                            (0x00000001U)  /**< 0-If set. the Rx-Decoder will check the CRC for correctness. Note that this bit is set by the Mode Detector. when ISO14443 type B. or FeliCa (212 or 424kBd) is detected.*/

#define CLIF_RX_WAIT2                                                                                      0x32
#define CLIF_RX_WAIT_RESERVED_POS2                                                                        (28U)
#define CLIF_RX_WAIT_RESERVED_MASK2                                                                       (0xF0000000U)  /**< 28-Reserved */
#define CLIF_RX_WAIT_RX_WAIT_VALUE_POS2                                                                   (8U)
#define CLIF_RX_WAIT_RX_WAIT_VALUE_MASK2                                                                  (0x0FFFFF00U)  /**< 8-Defines the rx_wait timer reload value. Note: If set to 00000h the rx_wait guard time is disabled */
#define CLIF_RX_WAIT_RX_WAIT_PRESCALER_POS2                                                               (0U)
#define CLIF_RX_WAIT_RX_WAIT_PRESCALER_MASK2                                                              (0x000000FFU)  /**< 0-Defines the prescaler reload value for the rx_wait timer.*/

#define CLIF_DCOC_CONFIG2                                                                                  0x33
#define CLIF_DCOC_CONFIG_RESERVED_POS2                                                                    (0U)
#define CLIF_DCOC_CONFIG_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_RXM_CTRL2                                                                                     0x35
#define CLIF_RXM_CTRL_RESERVED_POS2                                                                       (0U)
#define CLIF_RXM_CTRL_RESERVED_MASK2                                                                      (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_ANA_AGC_DCO_CTRL2                                                                             0x36
#define CLIF_ANA_AGC_DCO_CTRL_RESERVED_POS2                                                               (0U)
#define CLIF_ANA_AGC_DCO_CTRL_RESERVED_MASK2                                                              (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_SIGPRO_CM_CONFIG2                                                                             0x37
#define CLIF_SIGPRO_CM_CONFIG_RESERVED_POS2                                                               (0U)
#define CLIF_SIGPRO_CM_CONFIG_RESERVED_MASK2                                                              (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_GCM_CONFIG22                                                                                  0x38
#define CLIF_GCM_CONFIG2_RESERVED_POS2                                                                    (0U)
#define CLIF_GCM_CONFIG2_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_GCM_CONFIG12                                                                                  0x39
#define CLIF_GCM_CONFIG1_RESERVED_POS2                                                                    (0U)
#define CLIF_GCM_CONFIG1_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_GCM_CONFIG02                                                                                  0x3A
#define CLIF_GCM_CONFIG0_RESERVED_POS2                                                                    (0U)
#define CLIF_GCM_CONFIG0_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_SS_TX1_CMCFG2                                                                                 0x3B
#define CLIF_SS_TX1_CMCFG_RESERVED_POS2                                                                   (22U)
#define CLIF_SS_TX1_CMCFG_RESERVED_MASK2                                                                  (0xFFC00000U)  /**< 22-Reserved*/
#define CLIF_SS_TX1_CMCFG_TX1_CLK_MODE_MOD_CM_POS2                                                        (19U)
#define CLIF_SS_TX1_CMCFG_TX1_CLK_MODE_MOD_CM_MASK2                                                       (0x00380000U)  /**< 19-TX1 clock mode of modulated wave in CM*/
#define CLIF_SS_TX1_CMCFG_TX1_CLK_MODE_CW_CM_POS2                                                         (16U)
#define CLIF_SS_TX1_CMCFG_TX1_CLK_MODE_CW_CM_MASK2                                                        (0x00070000U)  /**< 16-TX1 clock mode of unmodulated wave in CM*/
#define CLIF_SS_TX1_CMCFG_TX1_AMP_MOD_CM_POS2                                                             (8U)
#define CLIF_SS_TX1_CMCFG_TX1_AMP_MOD_CM_MASK2                                                            (0x0000FF00U)  /**< 8-TX1 amplitude of modulated wave in CM*/
#define CLIF_SS_TX1_CMCFG_TX1_AMP_CW_CM_POS2                                                              (0U)
#define CLIF_SS_TX1_CMCFG_TX1_AMP_CW_CM_MASK2                                                             (0x000000FFU)  /**< 0-TX1 amplitude of unmodulated wave in CM*/

#define CLIF_SS_TX2_CMCFG2                                                                                 0x3C
#define CLIF_SS_TX2_CMCFG_RESERVED_POS2                                                                   (22U)
#define CLIF_SS_TX2_CMCFG_RESERVED_MASK2                                                                  (0xFFC00000U)  /**< 22-Reserved*/
#define CLIF_SS_TX2_CMCFG_TX2_CLK_MODE_MOD_CM_POS2                                                        (19U)
#define CLIF_SS_TX2_CMCFG_TX2_CLK_MODE_MOD_CM_MASK2                                                       (0x00380000U)  /**< 19-TX2 clock mode of modulated wave in CM*/
#define CLIF_SS_TX2_CMCFG_TX2_CLK_MODE_CW_CM_POS2                                                         (16U)
#define CLIF_SS_TX2_CMCFG_TX2_CLK_MODE_CW_CM_MASK2                                                        (0x00070000U)  /**< 16-TX2 clock mode of unmodulated wave in CM*/
#define CLIF_SS_TX2_CMCFG_TX2_AMP_MOD_CM_POS2                                                             (8U)
#define CLIF_SS_TX2_CMCFG_TX2_AMP_MOD_CM_MASK2                                                            (0x0000FF00U)  /**< 8-TX2 amplitude of modulated wave in CM*/
#define CLIF_SS_TX2_CMCFG_TX2_AMP_CW_CM_POS2                                                              (0U)
#define CLIF_SS_TX2_CMCFG_TX2_AMP_CW_CM_MASK2                                                             (0x000000FFU)  /**< 0-TX2 amplitude of unmodulated wave in CM*/

#define CLIF_TIMER0_CONFIG2                                                                                0x3D
#define CLIF_TIMER0_CONFIG_RESERVED_POS2                                                                  (9U)
#define CLIF_TIMER0_CONFIG_RESERVED_MASK2                                                                 (0xFFFFFE00U)  /**< 9-Reserved */
#define CLIF_TIMER0_CONFIG_T0_START_NOW_POS2                                                              (8U)
#define CLIF_TIMER0_CONFIG_T0_START_NOW_MASK2                                                             (0x00000100U)  /**< 8-T0_START_EVENT: If set. the timer T0 is started immediately. */
#define CLIF_TIMER0_CONFIG_RESERVED1_POS2                                                                 (7U)
#define CLIF_TIMER0_CONFIG_RESERVED1_MASK2                                                                (0x00000080U)  /**< 7-Reserved */
#define CLIF_TIMER0_CONFIG_T0_ONE_SHOT_MODE_POS2                                                          (6U)
#define CLIF_TIMER0_CONFIG_T0_ONE_SHOT_MODE_MASK2                                                         (0x00000040U)  /**< 6-When set to 1 the counter value does not reload again until the counter value has reached zero*/
#define CLIF_TIMER0_CONFIG_T0_PRESCALE_SEL_POS2                                                           (3U)
#define CLIF_TIMER0_CONFIG_T0_PRESCALE_SEL_MASK2                                                          (0x00000038U)  /**< 3-Controls frequency/period of the timer T0 when the prescaler is activated in T0_MODE_SEL. 000b* 6.78MHz counter 001b 3.39MHz counter 010b 1.70MHz counter 011b 848kHz counter 100b 424kHz counter 101b 212kHz counter 110b 106kHz counter 111b 53kHz counter   */
#define CLIF_TIMER0_CONFIG_T0_MODE_SEL_POS2                                                               (2U)
#define CLIF_TIMER0_CONFIG_T0_MODE_SEL_MASK2                                                              (0x00000004U)  /**< 2-Configuration of the timer T0 clock. 0b* Prescaler is disabled: the timer frequency matches CLIF clock frequency (13.56MHz). 1b Prescaler is enabled: the timer operates on the prescaler signal frequency (chosen by T0_PRESCALE_SEL).*/
#define CLIF_TIMER0_CONFIG_T0_RELOAD_ENABLE_POS2                                                          (1U)
#define CLIF_TIMER0_CONFIG_T0_RELOAD_ENABLE_MASK2                                                         (0x00000002U)  /**< 1-If set to 0.the timer T0 will stop on expiration. 0* After expiration the timer T0 will stop counting. i.e.. remain zero. reset value. 1 After expiration the timer T0 will reload its preset value and continue counting down. */
#define CLIF_TIMER0_CONFIG_T0_ENABLE_POS2                                                                 (0U)
#define CLIF_TIMER0_CONFIG_T0_ENABLE_MASK2                                                                (0x00000001U)  /**< 0-Enables the timer T0*/

#define CLIF_TIMER0_RELOAD2                                                                                0x3E
#define CLIF_TIMER0_RELOAD_RESERVED_POS2                                                                  (20U)
#define CLIF_TIMER0_RELOAD_RESERVED_MASK2                                                                 (0xFFF00000U)  /**< 20-Reserved */
#define CLIF_TIMER0_RELOAD_T0_RELOAD_VALUE_POS2                                                           (0U)
#define CLIF_TIMER0_RELOAD_T0_RELOAD_VALUE_MASK2                                                          (0x000FFFFFU)  /**< 0-Reload value of the timer T0. */

#define CLIF_TIMER1_CONFIG2                                                                                0x3F
#define CLIF_TIMER1_CONFIG_RESERVED_POS2                                                                  (31U)
#define CLIF_TIMER1_CONFIG_RESERVED_MASK2                                                                 (0x80000000U)  /**< 31-Reserved */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_POS2                                                     (30U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_STARTED_MASK2                                                    (0x40000000U)  /**< 30-T1_STOP_EVENT: If set. the timer T1 is stopped when a data reception begins (1st bit is received). */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_TX_STARTED_POS2                                                     (29U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_TX_STARTED_MASK2                                                    (0x20000000U)  /**< 29-T1_STOP_EVENT: If set. the timer T1 is stopped when a data transmission begins. */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_ON_EXT_POS2                                                      (28U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_ON_EXT_MASK2                                                     (0x10000000U)  /**< 28-T1_STOP_EVENT: If set. the timer T1 is stopped when the external RF field is detected. */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_OFF_EXT_POS2                                                     (27U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_OFF_EXT_MASK2                                                    (0x08000000U)  /**< 27-T1_STOP_EVENT: If set. the timer T1 is stopped when the external RF field vanishes. */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_ON_INT_POS2                                                      (26U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_ON_INT_MASK2                                                     (0x04000000U)  /**< 26-T1_STOP_EVENT: If set. the timer T1 is stopped when the internal RF field is turned on. */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_OFF_INT_POS2                                                     (25U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RF_OFF_INT_MASK2                                                    (0x02000000U)  /**< 25-T1_STOP_EVENT: If set. the timer T1 is stopped when the internal RF field is turned off. */
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_ENDED_POS2                                                       (24U)
#define CLIF_TIMER1_CONFIG_T1_STOP_ON_RX_ENDED_MASK2                                                      (0x01000000U)  /**< 24-T1_STOP_EVENT: If set the timer T1 is stopped when an activity on RX is detected.*/
#define CLIF_TIMER1_CONFIG_RESERVED1_POS2                                                                 (18U)
#define CLIF_TIMER1_CONFIG_RESERVED1_MASK2                                                                (0x00FC0000U)  /**< 18-Reserved */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RX_STARTED_POS2                                                    (17U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RX_STARTED_MASK2                                                   (0x00020000U)  /**< 17-T1_START_EVENT: If set. the timer T1 is started when a data reception begins (1st bit is received). */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RX_ENDED_POS2                                                      (16U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RX_ENDED_MASK2                                                     (0x00010000U)  /**< 16-T1_START_EVENT: If set. the timer T1 is started when a data reception ends. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_STARTED_POS2                                                    (15U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_STARTED_MASK2                                                   (0x00008000U)  /**< 15-T1_START_EVENT: If set. the timer T1 is started when a data transmission begins.   */
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_POS2                                                      (14U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_ENDED_MASK2                                                     (0x00004000U)  /**< 14-T1_START_EVENT: If set. the timer T1 is started when a data transmission ends. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_ON_EXT_POS2                                                     (13U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_ON_EXT_MASK2                                                    (0x00002000U)  /**< 13-T1_START_EVENT: If set. the timer T1 is started when the external RF field is detected. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_OFF_EXT_POS2                                                    (12U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_OFF_EXT_MASK2                                                   (0x00001000U)  /**< 12-T1_START_EVENT: If set. the timer T1 is started when the external RF field is not detected any more. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_ON_INT_POS2                                                     (11U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_ON_INT_MASK2                                                    (0x00000800U)  /**< 11-T1_START_EVENT: If set. the timer T1 is started when an internal RF field is turned on. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_OFF_INT_POS2                                                    (10U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_RF_OFF_INT_MASK2                                                   (0x00000400U)  /**< 10-T1_START_EVENT: If set. the timer T1 is started when an internal RF field is turned off. */
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_POS2                                                  (9U)
#define CLIF_TIMER1_CONFIG_T1_START_ON_TX_FRAMESTEP_MASK2                                                 (0x00000200U)  /**< 9-T1_START_EVENT: If set. the timer T1 is started when an activity on Frame-step is detected.*/
#define CLIF_TIMER1_CONFIG_T1_START_NOW_POS2                                                              (8U)
#define CLIF_TIMER1_CONFIG_T1_START_NOW_MASK2                                                             (0x00000100U)  /**< 8-T1_START_EVENT: If set. the timer T1 is started immediately. */
#define CLIF_TIMER1_CONFIG_RESERVED2_POS2                                                                  (7U)
#define CLIF_TIMER1_CONFIG_RESERVED2_MASK2                                                                 (0x00000080U)  /**< 7-Reserved */
#define CLIF_TIMER1_CONFIG_T1_ONE_SHOT_MODE_POS2                                                          (6U)
#define CLIF_TIMER1_CONFIG_T1_ONE_SHOT_MODE_MASK2                                                         (0x00000040U)  /**< 6-When set to 1 the counter value does not reload again until the counter value has reached zero*/
#define CLIF_TIMER1_CONFIG_T1_PRESCALE_SEL_POS2                                                           (3U)
#define CLIF_TIMER1_CONFIG_T1_PRESCALE_SEL_MASK2                                                          (0x00000038U)  /**< 3-Controls frequency/period of the timer T1 when the prescaler is activated by T1_MODE_SEL. 000b* 6.78MHz counter 001b 3.39MHz counter 010b 1.70MHz counter 011b 848kHz counter 100b 424kHz counter 101b 212kHz counter 110b 106kHz counter 111b 53kHz counter */
#define CLIF_TIMER1_CONFIG_T1_MODE_SEL_POS2                                                               (2U)
#define CLIF_TIMER1_CONFIG_T1_MODE_SEL_MASK2                                                              (0x00000004U)  /**< 2-If set. the timer T1 is started the prescaler for the timer T1 is enabled. 0* Prescaler is disabled: the timer frequency matches CLIF clock frequency (13.56MHz). 1 Prescaler is enabled: the timer operates on the prescaler signal frequency (chosen by T1_PRESCALE_SEL). */
#define CLIF_TIMER1_CONFIG_T1_RELOAD_ENABLE_POS2                                                          (1U)
#define CLIF_TIMER1_CONFIG_T1_RELOAD_ENABLE_MASK2                                                         (0x00000002U)  /**< 1-If set to 0.the timer T1 will stop on expiration. 0* After expiration the timer T1 will stop counting. i.e.. remain zero. reset value. 1 After expiration the timer T1 will reload its preset value and continue counting down. */
#define CLIF_TIMER1_CONFIG_T1_ENABLE_POS2                                                                 (0U)
#define CLIF_TIMER1_CONFIG_T1_ENABLE_MASK2                                                                (0x00000001U)  /**< 0-Enables the timer T1*/

#define CLIF_TIMER1_RELOAD2                                                                                0x40
#define CLIF_TIMER1_RELOAD_RESERVED_POS2                                                                  (20U)
#define CLIF_TIMER1_RELOAD_RESERVED_MASK2                                                                 (0xFFF00000U)  /**< 20-Reserved */
#define CLIF_TIMER1_RELOAD_T1_RELOAD_VALUE_POS2                                                           (0U)
#define CLIF_TIMER1_RELOAD_T1_RELOAD_VALUE_MASK2                                                          (0x000FFFFFU)  /**< 0-Reload value of the timer T1.*/

#define CLIF_ANA_RX_CTRL2                                                                                  0x43
#define CLIF_ANA_RX_CTRL_RESERVED_POS2                                                                    (0U)
#define CLIF_ANA_RX_CTRL_RESERVED_MASK2                                                                   (0xFFFFFFFFU)  /**< 0-Reserved*/

#define CLIF_RX_EMD_0_CONFIG2                                                                              0x48
#define CLIF_RX_EMD_0_CONFIG_RESERVED_POS2                                                                (0U)
#define CLIF_RX_EMD_0_CONFIG_RESERVED_MASK2                                                               (0xFFFFFFFFU)  /**< 0-Reserved*/

#define LPCD_CALIBRATE_CTRL2                                                                               0x50
#define LPCD_CALIBRATE_CTRL_FREEZE_VALUES_POS2                                                            (30U)
#define LPCD_CALIBRATE_CTRL_FREEZE_VALUES_MASK2                                                           (0x40000000U)  /**< 30-Freeze the RSSI Target and hysteresis values into UserArea*/
#define LPCD_CALIBRATE_CTRL_RFU_POS2                                                                      (24U)
#define LPCD_CALIBRATE_CTRL_RFU_MASK2                                                                     (0x3F000000U)  /**< 24-Reserved*/
#define LPCD_CALIBRATE_CTRL_RSSI_HYSTERESIS_POS2                                                          (16U)
#define LPCD_CALIBRATE_CTRL_RSSI_HYSTERESIS_MASK2                                                         (0x00FF0000U)  /**< 16-[REG] Value to be set in CLIF_DGRM_RSSI_REG_DGRM_RSSI_HYST used for calibration*/
#define LPCD_CALIBRATE_CTRL_RSSI_TARGET_POS2                                                              (0U)
#define LPCD_CALIBRATE_CTRL_RSSI_TARGET_MASK2                                                             (0x0000FFFFU)  /**< 0-[REG] Value to be set in CLIF_DGRM_RSSI_REG_DGRM_RSSI_TARGET used for calibration*/

#define IQ_CHANNEL_VALS2                                                                                   0x51
#define IQ_CHANNEL_VALS_Q_CHANNEL_VAL_POS2                                                                (16U)
#define IQ_CHANNEL_VALS_Q_CHANNEL_VAL_MASK2                                                               (0xFFFF0000U)  /**< 16-Q Channel value*/
#define IQ_CHANNEL_VALS_I_CHANNEL_VAL_POS2                                                                (0U)
#define IQ_CHANNEL_VALS_I_CHANNEL_VAL_MASK2                                                               (0x0000FFFFU)  /**< 0-I Channel value*/

#define PAD_CONFIG2                                                                                        0x52
#define PAD_CONFIG_RESERVED_POS2                                                                          (7U)
#define PAD_CONFIG_RESERVED_MASK2                                                                         (0x0000FF80U)  /**< 7-RESERVED*/
#define PAD_CONFIG_AUX3_OUTPUT_VAL_POS2                                                                   (6U)
#define PAD_CONFIG_AUX3_OUTPUT_VAL_MASK2                                                                  (0x00000040U)  /**< 6-Output value for AUX3*/
#define PAD_CONFIG_AUX2_OUTPUT_VAL_POS2                                                                   (5U)
#define PAD_CONFIG_AUX2_OUTPUT_VAL_MASK2                                                                  (0x00000020U)  /**< 5-Output value for AUX2*/
#define PAD_CONFIG_AUX1_OUTPUT_VAL_POS2                                                                   (4U)
#define PAD_CONFIG_AUX1_OUTPUT_VAL_MASK2                                                                  (0x00000010U)  /**< 4-Output value for AUX1*/
#define PAD_CONFIG_GPIO3_OUTPUT_VAL_POS2                                                                  (3U)
#define PAD_CONFIG_GPIO3_OUTPUT_VAL_MASK2                                                                 (0x00000008U)  /**< 3-Output value for GPIO3*/
#define PAD_CONFIG_GPIO2_OUTPUT_VAL_POS2                                                                  (2U)
#define PAD_CONFIG_GPIO2_OUTPUT_VAL_MASK2                                                                 (0x00000004U)  /**< 2-Output value for GPIO2*/
#define PAD_CONFIG_GPIO1_OUTPUT_VAL_POS2                                                                  (1U)
#define PAD_CONFIG_GPIO1_OUTPUT_VAL_MASK2                                                                 (0x00000002U)  /**< 1-Output value for GPIO1*/
#define PAD_CONFIG_GPIO0_OUTPUT_VAL_POS2                                                                  (0U)
#define PAD_CONFIG_GPIO0_OUTPUT_VAL_MASK2                                                                 (0x00000001U)  /**< 0-Output value for GPIO0*/

#define GENERAL_STATUS2                                                                                    0x53
#define GENERAL_STATUS_LPCD_CALIBRATION_STATUS_POS2                                                       (31UL)
#define GENERAL_STATUS_LPCD_CALIBRATION_STATUS_MASK2                                                      (0x80000000UL)  /**< 31-LPD Calibration Status 0 - Calibration Not Done, 1- Calibration Done*/
#define GENERAL_STATUS_TXNOV_CALIBRATION_STATUS_POS2                                                      (0UL)
#define GENERAL_STATUS_TXNOV_CALIBRATION_STATUS_MASK2                                                     (0x00000001UL)  /**< 0-TXNOV Calibration Status 0 - Calibration Not Done, 1- Calibration Done*/

#define TXLDO_VDDPA_CONFIG2                                                                                0x54
#define TXLDO_VDDPA_CONFIG_RESERVED_POS2                                                                  (8U)
#define TXLDO_VDDPA_CONFIG_RESERVED_MASK2                                                                 (0xFFFFFF00U)  /**< 8-Reserved*/
#define TXLDO_VDDPA_CONFIG_VDDPA_CONFIG_POS2                                                              (0U)
#define TXLDO_VDDPA_CONFIG_VDDPA_CONFIG_MASK2                                                             (0x000000FFU)  /**< 0-Configures the VDDPA to the value set*/

#define GENERAL_ERROR_STATUS2                                                                              0x55
#define GENERAL_ERROR_STATUS_RFU_POS2                                                                     (3U)
#define GENERAL_ERROR_STATUS_RFU_MASK2                                                                    (0xFFFFFFF8U)  /**< 3-Reserved*/
#define GENERAL_ERROR_STATUS_TXLDO_ERROR_POS2                                                             (2U)
#define GENERAL_ERROR_STATUS_TXLDO_ERROR_MASK2                                                            (0x00000004U)  /**< 2-*/
#define GENERAL_ERROR_STATUS_CLOCK_ERROR_POS2                                                             (1U)
#define GENERAL_ERROR_STATUS_CLOCK_ERROR_MASK2                                                            (0x00000002U)  /**< 1-*/
#define GENERAL_ERROR_STATUS_GPADC_ERROR_POS2                                                             (0U)
#define GENERAL_ERROR_STATUS_GPADC_ERROR_MASK2                                                            (0x00000001U)  /**< 0-*/

#define TXLDO_VOUT_CURR2                                                                                   0x56
#define TXLDO_VOUT_CURR_TXLDO_CURRENT_POS2                                                                (8U)
#define TXLDO_VOUT_CURR_TXLDO_CURRENT_MASK2                                                               (0x00FFFF00U)  /**< 8-Incdicates the TXLDO Current*/
#define TXLDO_VOUT_CURR_VDDPA_VOUT_POS2                                                                   (0U)
#define TXLDO_VOUT_CURR_VDDPA_VOUT_MASK2                                                                  (0x000000FFU)  /**< 0-Indicates the current VDDPA Voltage configured*/

#define PCRM_CLIF_DAC2                                                                                 	0x57
#define PCRM_CLIF_DAC_RESERVED_POS2                                                                   (28U)
#define PCRM_CLIF_DAC_RESERVED_MASK2                                                                  (0xF0000000U)  /**< 28-reserved*/
#define PCRM_CLIF_DAC_TUNING_DAC_2_OFFSET_CTRL_POS2                                                   (24U)
#define PCRM_CLIF_DAC_TUNING_DAC_2_OFFSET_CTRL_MASK2                                                  (0x0F000000U)  /**< 24-x111=2V, x110=3V,x100=3.45V,x000=3.8V*/
#define PCRM_CLIF_DAC_TUNING_DAC_2_CTRL_POS2                                                          (17U)
#define PCRM_CLIF_DAC_TUNING_DAC_2_CTRL_MASK2                                                         (0x00FE0000U)  /**< 17-Output voltage of DAC2 according to 1/128 TUNING_DAC_2_CTRL  Range in V*/
#define PCRM_CLIF_DAC_TUNING_DAC_2_PD_POS2                                                            (16U)
#define PCRM_CLIF_DAC_TUNING_DAC_2_PD_MASK2                                                           (0x00010000U)  /**< 16-0=DAC Turned off, 1=DAC enabled*/
#define PCRM_CLIF_DAC_RESERVED1_POS2                                                                  (12U)
#define PCRM_CLIF_DAC_RESERVED1_MASK2                                                                 (0x0000F000U)  /**< 12-reserved*/
#define PCRM_CLIF_DAC_TUNING_DAC_1_OFFSET_CTRL_POS2                                                   (8U)
#define PCRM_CLIF_DAC_TUNING_DAC_1_OFFSET_CTRL_MASK2                                                  (0x00000F00U)  /**< 8-x111=2V, x110=3V,x100=3.45V,x000=3.8V*/
#define PCRM_CLIF_DAC_TUNING_DAC_1_CTRL_POS2                                                          (1U)
#define PCRM_CLIF_DAC_TUNING_DAC_1_CTRL_MASK2                                                         (0x000000FEU)  /**< 1-Output voltage of DAC1 according to 1/128 TUNING_DAC_1_CTRL  Range in V*/
#define PCRM_CLIF_DAC_TUNING_DAC_1_PD_POS2                                                            (0U)
#define PCRM_CLIF_DAC_TUNING_DAC_1_PD_MASK2                                                           (0x00000001U)  /**< 0-0=DAC Turned off, 1=DAC enabled*/

#define PCRM_PMU_ANA_SMPS_CTRL2                                                                        0x58
#define PCRM_PMU_ANA_SMPS_CTRL_RESERVED_POS2                                                          (30U)
#define PCRM_PMU_ANA_SMPS_CTRL_RESERVED_MASK2                                                         (0xC0000000U)  /**< 30-reserved*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_MAXDT_SEL_POS2                                                    (27U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_MAXDT_SEL_MASK2                                                   (0x38000000U)  /**< 27-SMPS max duty cycle value, valid when SMPS_MAX_DTC_BYPASS is set*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_MAXDT_SEL_BYPASS_POS2                                             (26U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_MAXDT_SEL_BYPASS_MASK2                                            (0x04000000U)  /**< 26-SMPS max duty cycle lookup table bypass */
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_GM_POS2                                                           (24U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_GM_MASK2                                                          (0x03000000U)  /**< 24-SMPS Gm set up*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_RSENSE_POS2                                                       (22U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_RSENSE_MASK2                                                      (0x00C00000U)  /**< 22-SMPS R sense set up*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SOFT_START_POS2                                                   (20U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SOFT_START_MASK2                                                  (0x00300000U)  /**< 20-SMPS Soft Start set up*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SAWTOOTHGEN_POS2                                                  (17U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SAWTOOTHGEN_MASK2                                                 (0x000E0000U)  /**< 17-SMPS Sawtooth generator set up*/
#define PCRM_PMU_ANA_SMPS_CTRL_RESERVED1_POS2                                                         (14U)
#define PCRM_PMU_ANA_SMPS_CTRL_RESERVED1_MASK2                                                        (0x0001C000U)  /**< 14-reserved*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_PROT_UNDERSHOOT_VTH_POS2                                          (12U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_PROT_UNDERSHOOT_VTH_MASK2                                         (0x00003000U)  /**< 12-SMPS */
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SPARE_0_POS2                                                  (10U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_SPARE_0_MASK2                                                 (0x00000C00U)  /**< 10-SMPS */
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_PID_POS2                                                          (7U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_PID_MASK2                                                         (0x00000380U)  /**< 7-SMPS PID filter set up*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_VDDBOOST_VOUT_SEL_POS2                                            (1U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_VDDBOOST_VOUT_SEL_MASK2                                           (0x0000007EU)  /**< 1-SMPS Output voltage selection*/
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_EN_POS2                                                           (0U)
#define PCRM_PMU_ANA_SMPS_CTRL_SMPS_EN_MASK2                                                          (0x00000001U)  /**< 0-SMPS enable*/

#define CLIF_RXM_FREQ2                                                                                     0x59
#define CLIF_RXM_FREQ_RXM_FREQ_REG_VALID_POS2                                                             (31U)
#define CLIF_RXM_FREQ_RXM_FREQ_REG_VALID_MASK2                                                            (0x80000000U)  /**< 31-CLIF_RXM_FREQ_REG fields are valid*/
#define CLIF_RXM_FREQ_RESERVED_POS2                                                                       (25U)
#define CLIF_RXM_FREQ_RESERVED_MASK2                                                                      (0x7E000000U)  /**< 25-Reserved*/
#define CLIF_RXM_FREQ_RXM_FREQ_POS2                                                                       (16U)
#define CLIF_RXM_FREQ_RXM_FREQ_MASK2                                                                      (0x01FF0000U)  /**< 16-frequence difference between the last two consecutive measures at 1.7 MHz (multiple of 13.56MHz/4096). Signed. 2-Complement coded.*/
#define CLIF_RXM_FREQ_RESERVED1_POS2                                                                      (9U)
#define CLIF_RXM_FREQ_RESERVED1_MASK2                                                                     (0x0000FE00U)  /**< 9-Reserved*/
#define CLIF_RXM_FREQ_RXM_PHASE_POS2                                                                      (0U)
#define CLIF_RXM_FREQ_RXM_PHASE_MASK2                                                                     (0x000001FFU)  /**< 0-phase value from CORDIC*/

#define CLIF_RXM_RSSI2                                                                                     0x5A
#define CLIF_RXM_RSSI_RESERVED_POS2                                                                       (23U)
#define CLIF_RXM_RSSI_RESERVED_MASK2                                                                      (0xFF800000U)  /**< 23-Reserved*/
#define CLIF_RXM_RSSI_RXM_RSSI_FROZEN_POS2                                                                (22U)
#define CLIF_RXM_RSSI_RXM_RSSI_FROZEN_MASK2                                                               (0x00400000U)  /**< 22-The RSSI value is not currently updated*/
#define CLIF_RXM_RSSI_RXM_FRQ_OK_POS2                                                                     (21U)
#define CLIF_RXM_RSSI_RXM_FRQ_OK_MASK2                                                                    (0x00200000U)  /**< 21-The carrier frequency detected is OK.*/
#define CLIF_RXM_RSSI_RXM_RSSI_REG_VALID_POS2                                                             (20U)
#define CLIF_RXM_RSSI_RXM_RSSI_REG_VALID_MASK2                                                            (0x00100000U)  /**< 20-CLIF_RXM_RSSI_REG fields are valid*/
#define CLIF_RXM_RSSI_RXM_HFATT_POS2                                                                      (14U)
#define CLIF_RXM_RSSI_RXM_HFATT_MASK2                                                                     (0x000FC000U)  /**< 14-HFAtt latched with RSSI*/
#define CLIF_RXM_RSSI_RXM_RSSI_POS2                                                                       (0U)
#define CLIF_RXM_RSSI_RXM_RSSI_MASK2                                                                      (0x00003FFFU)  /**< 0-RSSI value*/

#define PMU_TEMP_REG2                                                                                      0x5B
#define PMU_TEMP_REG_PMU_TEMPERATURE_POS2                                                                 (0U)
#define PMU_TEMP_REG_PMU_TEMPERATURE_MASK2                                                                (0x0000FFFFU)  /**< 0-PMU temperature*/

#define INTERPOLATED_RSSI_REG2                                                                             0x5C
#define INTERPOLATED_RSSI_REG_INTERPOLATED_RSSI_POS2                                                      (0U)
#define INTERPOLATED_RSSI_REG_INTERPOLATED_RSSI_MASK2                                                     (0xFFFFFFFFU)  /**< 0-Calculated Interpolated RSSI*/

#define TX_NOV_CALIBRATE_AND_STORE_VAL_REG2                                                                0x5D
#define TX_NOV_CALIBRATE_AND_STORE_VAL_REG_RFU_POS2                                                       (2U)
#define TX_NOV_CALIBRATE_AND_STORE_VAL_REG_RFU_MASK2                                                      (0xFFFFFFFCU)  /**< 2-Reserved*/
#define TX_NOV_CALIBRATE_AND_STORE_VAL_REG_TX_NOV_CALIBRATE_STORE_POS2                                    (0U)
#define TX_NOV_CALIBRATE_AND_STORE_VAL_REG_TX_NOV_CALIBRATE_STORE_MASK2                                   (0x00000003U)  /**< 0-Perform TX_NOV Calibration and store in User Area*/

#define REG_DPC_CONFIG2                                                                                    0x5E
#define REG_DPC_CONFIG_ACCESS_POS2                                                                        (31U)
#define REG_DPC_CONFIG_ACCESS_MASK2                                                                       (0x80000000U)  /**< 31-Enable the DPC enable / disable control via register */
#define REG_DPC_ENABLE_DISABLE_POS2                                                                       (0U)
#define REG_DPC_ENABLE_MASK2                                                                              (0x00000001U)  /**< 0-DPC enabled / DPC disabled */

#define CLIF_SS_TX1_RTRANS02                                                                               0x80
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS3_POS2                                                           (24U)
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS3_MASK2                                                          (0xFF000000U)  /**< 24-TX1 rising transition value 3*/
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS2_POS2                                                           (16U)
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS2_MASK2                                                          (0x00FF0000U)  /**< 16-TX1 rising transition value 2*/
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS1_POS2                                                           (8U)
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS1_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 rising transition value 1*/
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS0_POS2                                                           (0U)
#define CLIF_SS_TX1_RTRANS0_TX1_SS_RTRANS0_MASK2                                                          (0x000000FFU)  /**< 0-TX1 rising transition value 0*/

#define CLIF_SS_TX1_RTRANS12                                                                               0x81
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS7_POS2                                                           (24U)
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS7_MASK2                                                          (0xFF000000U)  /**< 24-TX1 rising transition value 7*/
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS6_POS2                                                           (16U)
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS6_MASK2                                                          (0x00FF0000U)  /**< 16-TX1 rising transition value 6*/
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS5_POS2                                                           (8U)
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS5_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 rising transition value 5*/
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS4_POS2                                                           (0U)
#define CLIF_SS_TX1_RTRANS1_TX1_SS_RTRANS4_MASK2                                                          (0x000000FFU)  /**< 0-TX1 rising transition value 4*/

#define CLIF_SS_TX1_RTRANS22                                                                               0x82
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS11_POS2                                                          (24U)
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS11_MASK2                                                         (0xFF000000U)  /**< 24-TX1 rising transition value 11*/
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS10_POS2                                                          (16U)
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS10_MASK2                                                         (0x00FF0000U)  /**< 16-TX1 rising transition value 10*/
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS9_POS2                                                           (8U)
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS9_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 rising transition value 9*/
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS8_POS2                                                           (0U)
#define CLIF_SS_TX1_RTRANS2_TX1_SS_RTRANS8_MASK2                                                          (0x000000FFU)  /**< 0-TX1 rising transition value 8*/

#define CLIF_SS_TX1_RTRANS32                                                                               0x83
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS15_POS2                                                          (24U)
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS15_MASK2                                                         (0xFF000000U)  /**< 24-TX1 rising transition value 15*/
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS14_POS2                                                          (16U)
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS14_MASK2                                                         (0x00FF0000U)  /**< 16-TX1 rising transition value 14*/
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS13_POS2                                                          (8U)
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS13_MASK2                                                         (0x0000FF00U)  /**< 8-TX1 rising transition value 13*/
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS12_POS2                                                          (0U)
#define CLIF_SS_TX1_RTRANS3_TX1_SS_RTRANS12_MASK2                                                         (0x000000FFU)  /**< 0-TX1 rising transition value 12*/

#define CLIF_SS_TX2_RTRANS02                                                                               0x84
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS3_POS2                                                           (24U)
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS3_MASK2                                                          (0xFF000000U)  /**< 24-TX2 rising transition value 3*/
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS2_POS2                                                           (16U)
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS2_MASK2                                                          (0x00FF0000U)  /**< 16-TX2 rising transition value 2*/
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS1_POS2                                                           (8U)
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS1_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 rising transition value 1*/
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS0_POS2                                                           (0U)
#define CLIF_SS_TX2_RTRANS0_TX2_SS_RTRANS0_MASK2                                                          (0x000000FFU)  /**< 0-TX2 rising transition value 0*/

#define CLIF_SS_TX2_RTRANS12                                                                               0x85
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS7_POS2                                                           (24U)
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS7_MASK2                                                          (0xFF000000U)  /**< 24-TX2 rising transition value 7*/
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS6_POS2                                                           (16U)
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS6_MASK2                                                          (0x00FF0000U)  /**< 16-TX2 rising transition value 6*/
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS5_POS2                                                           (8U)
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS5_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 rising transition value 5*/
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS4_POS2                                                           (0U)
#define CLIF_SS_TX2_RTRANS1_TX2_SS_RTRANS4_MASK2                                                          (0x000000FFU)  /**< 0-TX2 rising transition value 4*/

#define CLIF_SS_TX2_RTRANS22                                                                               0x86
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS11_POS2                                                          (24U)
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS11_MASK2                                                         (0xFF000000U)  /**< 24-TX2 rising transition value 11*/
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS10_POS2                                                          (16U)
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS10_MASK2                                                         (0x00FF0000U)  /**< 16-TX2 rising transition value 10*/
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS9_POS2                                                           (8U)
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS9_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 rising transition value 9*/
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS8_POS2                                                           (0U)
#define CLIF_SS_TX2_RTRANS2_TX2_SS_RTRANS8_MASK2                                                          (0x000000FFU)  /**< 0-TX2 rising transition value 8*/

#define CLIF_SS_TX2_RTRANS32                                                                               0x87
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS15_POS2                                                          (24U)
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS15_MASK2                                                         (0xFF000000U)  /**< 24-TX2 rising transition value 15*/
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS14_POS2                                                          (16U)
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS14_MASK2                                                         (0x00FF0000U)  /**< 16-TX2 rising transition value 14*/
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS13_POS2                                                          (8U)
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS13_MASK2                                                         (0x0000FF00U)  /**< 8-TX2 rising transition value 13*/
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS12_POS2                                                          (0U)
#define CLIF_SS_TX2_RTRANS3_TX2_SS_RTRANS12_MASK2                                                         (0x000000FFU)  /**< 0-TX2 rising transition value 12*/

#define CLIF_SS_TX1_FTRANS02                                                                               0x88
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS3_POS2                                                           (24U)
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS3_MASK2                                                          (0xFF000000U)  /**< 24-TX1 falling transition value 3*/
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS2_POS2                                                           (16U)
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS2_MASK2                                                          (0x00FF0000U)  /**< 16-TX1 falling transition value 2*/
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS1_POS2                                                           (8U)
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS1_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 falling transition value 1*/
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS0_POS2                                                           (0U)
#define CLIF_SS_TX1_FTRANS0_TX1_SS_FTRANS0_MASK2                                                          (0x000000FFU)  /**< 0-TX1 falling transition value 0*/

#define CLIF_SS_TX1_FTRANS12                                                                               0x89
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS7_POS2                                                           (24U)
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS7_MASK2                                                          (0xFF000000U)  /**< 24-TX1 falling transition value 7*/
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS6_POS2                                                           (16U)
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS6_MASK2                                                          (0x00FF0000U)  /**< 16-TX1 falling transition value 6*/
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS5_POS2                                                           (8U)
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS5_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 falling transition value 5*/
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS4_POS2                                                           (0U)
#define CLIF_SS_TX1_FTRANS1_TX1_SS_FTRANS4_MASK2                                                          (0x000000FFU)  /**< 0-TX1 falling transition value 4*/

#define CLIF_SS_TX1_FTRANS22                                                                               0x8A
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS11_POS2                                                          (24U)
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS11_MASK2                                                         (0xFF000000U)  /**< 24-TX1 falling transition value 11*/
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS10_POS2                                                          (16U)
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS10_MASK2                                                         (0x00FF0000U)  /**< 16-TX1 falling transition value 10*/
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS9_POS2                                                           (8U)
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS9_MASK2                                                          (0x0000FF00U)  /**< 8-TX1 falling transition value 9*/
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS8_POS2                                                           (0U)
#define CLIF_SS_TX1_FTRANS2_TX1_SS_FTRANS8_MASK2                                                          (0x000000FFU)  /**< 0-TX1 falling transition value 8*/

#define CLIF_SS_TX1_FTRANS32                                                                               0x8B
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS15_POS2                                                          (24U)
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS15_MASK2                                                         (0xFF000000U)  /**< 24-TX1 falling transition value 15*/
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS14_POS2                                                          (16U)
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS14_MASK2                                                         (0x00FF0000U)  /**< 16-TX1 falling transition value 14*/
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS13_POS2                                                          (8U)
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS13_MASK2                                                         (0x0000FF00U)  /**< 8-TX1 falling transition value 13*/
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS12_POS2                                                          (0U)
#define CLIF_SS_TX1_FTRANS3_TX1_SS_FTRANS12_MASK2                                                         (0x000000FFU)  /**< 0-TX1 falling transition value 12*/

#define CLIF_SS_TX2_FTRANS02                                                                               0x8C
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS3_POS2                                                           (24U)
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS3_MASK2                                                          (0xFF000000U)  /**< 24-TX2 falling transition value 3*/
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS2_POS2                                                           (16U)
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS2_MASK2                                                          (0x00FF0000U)  /**< 16-TX2 falling transition value 2*/
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS1_POS2                                                           (8U)
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS1_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 falling transition value 1*/
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS0_POS2                                                           (0U)
#define CLIF_SS_TX2_FTRANS0_TX2_SS_FTRANS0_MASK2                                                          (0x000000FFU)  /**< 0-TX2 falling transition value 0*/

#define CLIF_SS_TX2_FTRANS12                                                                               0x8D
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS7_POS2                                                           (24U)
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS7_MASK2                                                          (0xFF000000U)  /**< 24-TX2 falling transition value 7*/
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS6_POS2                                                           (16U)
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS6_MASK2                                                          (0x00FF0000U)  /**< 16-TX2 falling transition value 6*/
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS5_POS2                                                           (8U)
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS5_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 falling transition value 5*/
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS4_POS2                                                           (0U)
#define CLIF_SS_TX2_FTRANS1_TX2_SS_FTRANS4_MASK2                                                          (0x000000FFU)  /**< 0-TX2 falling transition value 4*/

#define CLIF_SS_TX2_FTRANS22                                                                               0x8E
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS11_POS2                                                          (24U)
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS11_MASK2                                                         (0xFF000000U)  /**< 24-TX2 falling transition value 11*/
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS10_POS2                                                          (16U)
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS10_MASK2                                                         (0x00FF0000U)  /**< 16-TX2 falling transition value 10*/
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS9_POS2                                                           (8U)
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS9_MASK2                                                          (0x0000FF00U)  /**< 8-TX2 falling transition value 9*/
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS8_POS2                                                           (0U)
#define CLIF_SS_TX2_FTRANS2_TX2_SS_FTRANS8_MASK2                                                          (0x000000FFU)  /**< 0-TX2 falling transition value 8*/

#define CLIF_SS_TX2_FTRANS32                                                                               0x8F
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS15_POS2                                                          (24U)
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS15_MASK2                                                         (0xFF000000U)  /**< 24-TX2 falling transition value 15*/
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS14_POS2                                                          (16U)
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS14_MASK2                                                         (0x00FF0000U)  /**< 16-TX2 falling transition value 14*/
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS13_POS2                                                          (8U)
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS13_MASK2                                                         (0x0000FF00U)  /**< 8-TX2 falling transition value 13*/
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS12_POS2                                                          (0U)
#define CLIF_SS_TX2_FTRANS3_TX2_SS_FTRANS12_MASK2                                                         (0x000000FFU)  /**< 0-TX2 falling transition value 12*/

#define ULPCD_VDDPA_CTRL_EEPROM2                                                                           0x04BFU
#define DPC_CONFIG_EEPROM2                                                                                 0x076U

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
}
#endif
#endif /* PHHALHW_NCX3321_REG2_H */
