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
*   @file    phhalHw.h
*   @version 1.0.0
*
*   @brief   AUTOSAR HalHw - HAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phhalHw Hardware Abstraction Layer
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
#ifndef PHHALHW_H
#define PHHALHW_H

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
#include <ph_NxpBuild.h>
#include <CDD_AnfcRL_Cfg.h>

#include "phTools.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phhalHw.h
* @implements     DESIGN001, DESIGN002
*/
#define PHHALHW_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHHALHW_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHHALHW_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHHALHW_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHHALHW_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHHALHW_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHHALHW_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHHALHW_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHHALHW_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phhalHw.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHHALHW_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHHALHW_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phhalHw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHHALHW_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHHALHW_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHHALHW_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phhalHw.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCx3320

/** \defgroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

#define PHHAL_HW_NCx3320_LDCON_NUM 52

extern CONST(uint8, ANFCRL_CONST) gkphhalHw_Ncx3320_LoadConfig[PHHAL_HW_NCx3320_LDCON_NUM]; /**< extern variable: EEPROM Addresses for the Register Set. */

/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */

#endif /* NXPBUILD__PHHAL_HW_NCx3320 */
/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW
/** \defgroup phhalHw Hardware Abstraction Layer
 * \brief These are the components which are used to abstract the
 * functionality of the physical reader device to a generic interface.
 *
 * HAL API usage in common use cases are described in the sequence diagrams below
 *
 * <strong>Reader mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple reader mode application.
 * \image html HAL_ReaderMode.png
 *
 * <strong>Passive initiator mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO 14443 Initiator in passive communication mode.
 * \image html HAL_passive_initiator.png
 *
 * <strong>Low power card detection(LPCD):</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO/IEC 14443-3a \n
 * reader that uses LPCD functionality of reader IC.
 * \image html HAL_Lpcd.png
 *
 * <strong>OSAL usage in HAL:</strong> This sequence diagram describes the usage of OS event
 * from within the HAL. \n
 * HAL uses OSAL call to wait for a CLIF event that is triggered by a CLIF interrupt.\n
 * \image html HAL_Osal.png
 *
 * @{
 */

/**
 * \name HAL events
 */
/*@{*/

#define E_EVENT_WAITING            0U
#define E_EVENT_RF                 (1U << 0U)     /**< Event posted by CLIF ISR once the interrupt line goes high to the CLIF HAL. */
#define E_EVENT_GT_EXP             (1U << 1U)     /**< Event posted by DAL timer once the Guard time is expired. */
#define E_EVENT_ABORT              (1U << 5U)     /**< Event posted by the application to shut down the reader library thread. */
/*@}*/

/**
 * \name HAL EMD detection state
 */
/*@{*/

#define PHHAL_EMD_DETECT_STATE_IDLE			0U     /**< HAL EMD detection in IDLE state  */
#define PHHAL_EMD_DETECT_RECEPTION			1U     /**< HAL EMD detection in reception state */
/*@}*/

/**
 * \name HAL EMD detection state
 */
/*@{*/

#define PHHAL_CHECK_FOR_EMD_STATE_IDLE			0U     /**< CheckForEmdError in IDLE state  */
#define PHHAL_CHECK_FOR_EMD_STATE_RECEPTION		1U     /**< CheckForEmdError in reception state */
#define PHHAL_CHECK_FOR_EMD_STATE_FINISH		2U	   /**< CheckForEmdError finish state */
/*@}*/


#define PHHAL_HW_ARRY_COLUMNS_SIZE       2U     /**< Size of Array Configuration identifier. */
/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW */

#ifdef NXPBUILD__PHHAL_HW_NCx3320

/** \addtogroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

#define PHHAL_HW_NCx3320_ID               0x01U    /**< ID for Ncx3320 HAL component. */

#define PHHAL_HW_NCx3320_DEFAULT_TIMEOUT  150U    /**< Default timeout in microseconds. */
#define PHHAL_HW_NCx3320_SHADOW_COUNT     0x0010U /**< Number of shadowed configurations. */

/**
 * \name LPCD Options
 * When configuring Filter ON then either of the below options should be provided by the User.
 * For more information refer AN11145 available at www.nxp.com/documents/application_note/AN11145.pdf
 */
/*@{*/
#define PHHAL_HW_NCx3320_FILTER_OPTION1   0x0100U  /**< Configure I and Q value for LPCD for stable detection and power saving. */
#define PHHAL_HW_NCx3320_FILTER_OPTION2   0x0200U  /**< Configure I and Q value for LPCD for higher detection range. */
/*@}*/

/**
 * \name Custom configuration
 */
/*@{*/
/** Configure FIFO-Size. */
#define PHHAL_HW_NCx3320_CONFIG_FIFOSIZE      (PH_CONFIG_CUSTOM_BEGIN)
/**
 * \brief Enable (#PH_ON) or disable (#PH_OFF) LoadReg Mode.
 *
 * If this mode is enabled (it's disabled by default) then LoadReg is used\n
 * if an operation mode changes instead of applying library constants.\n
 * This is useful if custom antenna configuration values are required to be applied.\n
 * The parameters for LoadReg are taken from \b pLoadRegConfig which is an input parameter\n
 * of \ref phhalHw_Ncx3320_Init. Refer there for a detailed description of \b pLoadRegConfig.
 */
#define PHHAL_HW_NCx3320_CONFIG_LOADREG_MODE  (PH_CONFIG_CUSTOM_BEGIN+1U)

/**
 * Configure the Water Level.
 */
#define PHHAL_HW_NCx3320_CONFIG_WATERLEVEL    (PH_CONFIG_CUSTOM_BEGIN+2U)

/**
 * Configure the Charge Pump.
 * For more information refer AN11145 available at www.nxp.com/documents/application_note/AN11145.pdf
 * Enable (#PH_ON) or Disable (#PH_OFF)
 */
#define PHHAL_HW_NCx3320_CONFIG_LPCD_CHARGEPUMP   (PH_CONFIG_CUSTOM_BEGIN+3U)

/**
 * Configure the LPCD Filter.
 * For more information refer AN11145 available at www.nxp.com/documents/application_note/AN11145.pdf
 * Enable (#PH_ON) or Disable (#PH_OFF)
 * NOTE : When configuring Filter with #PH_ON, it's mandatory to configure with either "PHHAL_HW_NCx3320_FILTER_OPTION1"
 * or "PHHAL_HW_NCx3320_FILTER_OPTION2" or'ed with #PH_ON by the user while calling phhalHw_SetConfig() API.
 */
#define PHHAL_HW_NCx3320_CONFIG_LPCD_FILTER   (PH_CONFIG_CUSTOM_BEGIN+4U)

/**
 * Configure the output amplitude of the transmitter.
 * NOTE : Use phhalHw_SetConfig() API with the following configuration values.
 * 0: TVDD -100 mV, 1: TVDD -250 mV, 2: TVDD -500 mV, 3: TVDD -1000 mV.
 * Any value outside the defined range will generate a PH_ERR_INVALID_PARAMETER error.
 */
#define PHHAL_HW_NCx3320_CONFIG_LPCD_CWAMP   (PH_CONFIG_CUSTOM_BEGIN+5U)

/**
 * Set amplitude of continuous wave carrier to the maximum.
 * Enable (#PH_ON) or Disable (#PH_OFF)
 */
#define PHHAL_HW_NCx3320_CONFIG_LPCD_CWMAX   (PH_CONFIG_CUSTOM_BEGIN+6U)

/*@}*/

/**
 * \name EEPROM addresses
 * Values for the registers to be loaded using Load Reg in phhalHw_Ncx3320_SetCardMode() Api.
 * These are used to load settings to set the baud rate of a technology
 */
/*@{*/
#define PHHAL_HW_NCx3320_EE_ADDR_I14443A_106          0x00C0U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443A_212          0x00D4U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443A_424          0x00E8U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443A_848          0x0100U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443B_106          0x0114U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443B_EMVCO_106    0x0254U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443B_212          0x0128U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443B_424          0x0140U
#define PHHAL_HW_NCx3320_EE_ADDR_I14443B_848          0x0154U
#define PHHAL_HW_NCx3320_EE_ADDR_FELICA_212           0x0168U
#define PHHAL_HW_NCx3320_EE_ADDR_FELICA_424           0x0180U
#define PHHAL_HW_NCx3320_EE_ADDR_I15693_HIGH          0x0194U
#define PHHAL_HW_NCx3320_EE_ADDR_I15693_FAST_HIGH     0x01A8U
/*@}*/

/**
 * \name Register Address from where the Load Reg will start loading the registers.
 */
/*@{*/
#define PHHAL_HW_NCx3320_REG_ADDR                     0x0028U
/*@}*/

/**
 * \name Number of Registers to be loaded by Load Reg.
 */
/*@{*/
#define PHHAL_HW_NCx3320_REG_NUM                      18U
/*@}*/

/**
 * \name EEPROM address higher byte[15:8] Mask and Position used for shifting the address.
 */
/*@{*/
#define PHHAL_HW_NCx3320_REG_EEADDR_HIGH_MASK         0x000000FFU
#define PHHAL_HW_NCx3320_REG_EEADDR_HIGH_RS_POS       8U
/*@}*/

/**
 * \name Macro to fill the Values in the array used for Load Reg. */
/*@{*/
#define PHHAL_HW_NCx3320_ARR_LDREG_FILL(EEADDR)                                                           \
    ((uint8)((EEADDR) >> PHHAL_HW_NCx3320_REG_EEADDR_HIGH_RS_POS) & PHHAL_HW_NCx3320_REG_EEADDR_HIGH_MASK), \
    ((uint8)(EEADDR)),                                                                                \
    ((uint8)(PHHAL_HW_NCx3320_REG_ADDR)),                                                               \
    ((uint8)(PHHAL_HW_NCx3320_REG_NUM))      /**< This macro to fill the Values in the array used for Load Reg. */
/*@}*/


/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321

/**
 * \defgroup phhalHw_Ncx3321 component : Ncx3321
 * \ingroup phhalHw
 * \brief Ncx3321 HAL component
 *
 * @{
 */

#define PHHAL_HW_NCX3321_ID                          0x0FU       /**< ID for NCX3321 HAL component. */
#define PHHAL_HW_NCX3321_DEFAULT_TIMEOUT             150U        /**< Default timeout in microseconds. */
#define PHHAL_HW_NCX3321_DEFAULT_TIMEOUT_MILLI       50U         /**< Default timeout in milliseconds. */
#define PHHAL_HW_NCX3321_SHADOW_COUNT                0x12U       /**< Ncx3321 Shadow Register count. */
#define INSTR_BUFFER_SIZE                           262U        /**< Used to form single TLV command. */
#define MAX_ISR_READ_BUFFER_SIZE                    22U         /**< Max response Bytes for a command. */
#define PHHAL_HW_NCX3321_DEFAULT_FELICA_EMD_REGISTER 0x00FF0019U  /**< FeliCa EMD Control register default value */
#define PH_NCX3321_EVT_RSP                           0x80U        /**< Mask for Event filed in the Response byte */

/**
* \name Event generated by NCX3321
*  Any of these events can be triggered by NCX3321 Synchronously or Asynchronously
*  based on previous command execution or based on the internal error events generated
*  by NCX3321 Reader IC.
*/
/*@{
 *
 * \anchor NCx3321_events
 */

#define PH_NCX3321_EVT_BOOT                          0x0001U      /**< Boot Event */
#define PH_NCX3321_EVT_GENERAL_ERROR                 0x0002U      /**< General Error Event */
#define PH_NCX3321_EVT_STANDBY_PREV                  0x0004U      /**< StandBy Prevented/aborted Event */
#define PH_NCX3321_EVT_RFOFF_DETECT                  0x0008U      /**< RF OFF Detection Event */
#define PH_NCX3321_EVT_RFON_DETECT                   0x0010U      /**< RF ON Detection Event */
#define PH_NCX3321_EVT_TX_OVERCURRENT_ERROR          0x0020U      /**< Current Error Event */
#define PH_NCX3321_EVT_TIMER                         0x0040U      /**< TIMER Event */
#define PH_NCX3321_EVT_AUTOCOLL                      0x0080U      /**< AUTOCOLL Event */
#define PH_NCX3321_EVT_LPCD                          0x0100U      /**< LPCD Event */
#define PH_NCX3321_EVT_LP_CALIB                      0x0200U      /**< LP Calibration Event */
#define PH_NCX3321_EVT_IDLE                          0x0400U      /**< Idle Event */
#define PH_NCX3321_EVT_CTS                           0x0800U      /**< CTS Event */
#define PH_NCX3321_EVT_RFU                           0x1000U      /**< RFU Event */
#define PH_NCX3321_EVT_UNEXPECTED                    0xFFFFF000U   /**< Unexpected Event */

/*@}*/

/**
* \name Boot status data of NCX3321
*  event data for PH_NCX3321_EVT_BOOT
*/
/*@{
 *
 * \anchor NCx3321_boot_status_data
 */

#define PH_NCX3321_BOOT_POR                          0x0001U      /**< Power-On-Reset */
#define PH_NCX3321_BOOT_WDG                          0x0004U      /**< Watchdog reset */
#define PH_NCX3321_BOOT_TEMP                         0x0008U      /**< Over Heat */
#define PH_NCX3321_BOOT_WUC                          0x0010U      /**< wake-up counter elapsed */
#define PH_NCX3321_BOOT_VDDIO_START                  0x0020U      /**< STANDBY entered with VDDIO LOSS */
#define PH_NCX3321_BOOT_VDDIO_LOSS                   0x0040U      /**< Loss of VDDIO */
#define PH_NCX3321_BOOT_SOFT_RESET                   0x0080U      /**< Soft reset */
#define PH_NCX3321_BOOT_LPDET                        0x1000U      /**< External RF field presence during STANDBY/SUSPEND */
#define PH_NCX3321_BOOT_GPIO0                        0x02000U     /**< Transition GPIO0 from low to high. */
#define PH_NCX3321_BOOT_GPIO1                        0x04000U     /**< Transition GPIO1 from low to high. */
#define PH_NCX3321_BOOT_GPIO2                        0x08000U     /**< Transition GPIO2 from low to high. */
#define PH_NCX3321_BOOT_GPIO3                        0x10000U     /**< Transition GPIO3 from low to high. */
#define PH_NCX3321_BOOT_SPI                          0x100000U    /**< SPI_NSS signal being pulled low */
#define PH_NCX3321_BOOT_RX_ULPDET                    0x400000U    /**< RX ULPDET resulted in boot in ULP-Standby mode */
#define PH_NCX3321_ULP_STANDBY                       0x4000000U   /**< Exit from ULP_STANDBY. */
/*@}*/

#define PH_ERR_NCX3321_NO_CTS_EVENT                  PH_ERR_CUSTOM_BEGIN      /**< Error returned by NCX3321 HAL indicating no CTS Event occurred. */

#define PHHAL_HW_MAX_DELAY                          (0xFFFFFFFFU)

#define PHHAL_HW_ABORT_EVT_TIMEOUT                  500U                    /**< Timeout for non-RF commands in milliseconds */

#define PHHAL_HW_WAIT_IRQ_LOW_TIMEOUT               500U                    /**< IRQ might stay high a little longer, timeout in microseconds for waiting for it to come down */


/**
 * end of group phhalHw_Ncx3321 component : Ncx3321
 * @}
 */

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef NXPBUILD__PHHAL_HW

/** \addtogroup phhalHw Hardware Abstraction Layer
 * \brief These are the components which are used to abstract the
 * functionality of the physical reader device to a generic interface.
 *
 * HAL API usage in common use cases are described in the sequence diagrams below
 *
 * <strong>Reader mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple reader mode application.
 * \image html HAL_ReaderMode.png
 *
 * <strong>Passive initiator mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO 14443 Initiator in passive communication mode.
 * \image html HAL_passive_initiator.png
 *
 * <strong>Low power card detection(LPCD):</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO/IEC 14443-3a \n
 * reader that uses LPCD functionality of reader IC.
 * \image html HAL_Lpcd.png
 *
 * <strong>OSAL usage in HAL:</strong> This sequence diagram describes the usage of OS event
 * from within the HAL. \n
 * HAL uses OSAL call to wait for a CLIF event that is triggered by a CLIF interrupt.\n
 * \image html HAL_Osal.png
 *
 * @{
 */

/**
 * \name Communication configuration parameters \n
 *  These parameters are used to configure hardware/HAL
 *  in a particular manner before performing an operation.
 */
/*@{*/

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) Parity.\n
 *
 * */
#define PHHAL_HW_CONFIG_PARITY                    0x0000U

/**
 * Enable (#PH_ON) or disable (#PH_OFF) transmit CRC.\n
 *
 * */
#define PHHAL_HW_CONFIG_TXCRC                     0x0001U

/**
 * Enable (#PH_ON) or disable (#PH_OFF) receive CRC.\n
 *
 *
 * */
#define PHHAL_HW_CONFIG_RXCRC                     0x0002U

/**
 * Set number of valid bits for the last transmitted byte.
 * Valid range is 1 to 7
 * */
#define PHHAL_HW_CONFIG_TXLASTBITS                0x0003U

/**
 * Get number of valid bits of last received byte.
 * Valid range is 1 to 7
 * */
#define PHHAL_HW_CONFIG_RXLASTBITS                0x0004U

/**
 * Set Rx-Aligned Bits. Used for reception of bit oriented frames.
 * RxAlign defines the bit position for the first bit received to be stored in the FIFO.
 * Further received bits are stored at the following bit positions.
 * Used only for bitwise anti-collision at 106kbps. For all other modes it is set to logic 0.
 * */
#define PHHAL_HW_CONFIG_RXALIGN                   0x0005U

/**
 * Configure receiver deaf-time (time after a send where every reception is ignored) in microseconds.
 * This is the time for which the IC cannot receive any data after transmit.
 * */
#define PHHAL_HW_CONFIG_RXWAIT_US                 0x0006U

/**
 * Set Tx wait time (time between last RxIrq and Tx of succeeding frame) in microseconds.\n
 *
 * */
#define PHHAL_HW_CONFIG_TXWAIT_US                 0x0007U

/**
 * Configure data-rate and framing for transmission.\n
 * Use LSB for data-rate and MSB to specify framing.\n
 * MSB values can be #PHHAL_HW_RF_TYPE_A_FRAMING, #PHHAL_HW_RF_TYPE_B_FRAMING, #PHHAL_HW_RF_TYPE_F_FRAMING\n
 * LSB values can be #PHHAL_HW_RF_DATARATE_106, #PHHAL_HW_RF_DATARATE_212, #PHHAL_HW_RF_DATARATE_424, #PHHAL_HW_RF_DATARATE_848\n
 *
 * */
#define PHHAL_HW_CONFIG_TXDATARATE_FRAMING        0x0009U

/**
 * Enable or disable clearing of bits after collision.
 * Deprecated. Not used anymore.
 * */
#define PHHAL_HW_CONFIG_CLEARBITSAFTERCOLL        0x0008U

/**
 * Configure data-rate and framing for reception.
 * Use LSB for data-rate and MSB to specify framing.\n
 * MSB values can be #PHHAL_HW_RF_TYPE_A_FRAMING, #PHHAL_HW_RF_TYPE_B_FRAMING, #PHHAL_HW_RF_TYPE_F_FRAMING\n
 * LSB values can be #PHHAL_HW_RF_DATARATE_106, #PHHAL_HW_RF_DATARATE_212, #PHHAL_HW_RF_DATARATE_424, #PHHAL_HW_RF_DATARATE_848\n
 * */
#define PHHAL_HW_CONFIG_RXDATARATE_FRAMING        0x000AU

/**
 * Set modulation index (unit and value are hardware-dependent).\n
 *
 * Example values are \n
 * \li #PHHAL_HW_NCx3320_MODINDEX_I14443B \n
 * \li #PHHAL_HW_NCx3320_MODINDEX_I15693  \n
 *
 *
 * */
#define PHHAL_HW_CONFIG_MODINDEX                  0x000BU

/**
 * Enable (#PH_ON) or disable (#PH_OFF) 100% modulation.\n
 *
 * */
#define PHHAL_HW_CONFIG_ASK100                    0x000CU


/**
 * Enable (#PH_ON) or disable (#PH_OFF) transmit and receive CRC.\n
 *
 * */
#define PHHAL_HW_CONFIG_TRXCRC                    0x0011U

/**
 * Set Rx Wait with fixed value
 * Enable (#PH_ON) or disable (#PH_OFF) transmit and receive CRC.\n
 *
 * */
#define PHHAL_HW_CONFIG_REQAEX                    0x0012U

/**
 * Set RC timeout (in [us]).\n
 *
 * Note: Timers will be configured as FWT/FDT timers only after phhalHw_ApplyProtocolSettings() API is called.
 * */
#define PHHAL_HW_CONFIG_TIMEOUT_VALUE_US          0x000DU

/**
 * Set RC timeout (in [ms]).\n
 *
 * Note: Timers will be configured as FWT/FDT timers only after phhalHw_ApplyProtocolSettings() API is called.
 * */
#define PHHAL_HW_CONFIG_TIMEOUT_VALUE_MS          0x000EU

/**
 * Sub-carrier setting for ISO 15693.
 * Possible values are\n
 *     #PHHAL_HW_SUBCARRIER_SINGLE,\n
 *     #PHHAL_HW_SUBCARRIER_DUAL,\n
 *     #PHHAL_HW_SUBCARRIER_QUAD\n
 * */
#define PHHAL_HW_CONFIG_SUBCARRIER                0x000FU

/**
 * Set the field off time for field-reset ([ms]); \b Note: A value of \c 0 is not allowed.\n
 * Default value is #PHHAL_HW_FIELD_OFF_DEFAULT
 * */
#define PHHAL_HW_CONFIG_FIELD_OFF_TIME            0x0013U

/**
 * Set the field recovery time for field-reset ([ms]); \b Note: For ISO15693 operation, this should be at least set to \c 1ms.\n
 * Default value is #PHHAL_HW_FIELD_RECOVERY_DEFAULT
 * */
#define PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME       0x0014U

/**
 * Disable / Set the SOF symbol of a frame.
 * Sets the start of frame symbol for a frame for ISO 15693. The values can be one of:\n
 * \li #PH_OFF - Disable SoF\n
 * \li #PHHAL_HW_SYMBOL_I15693_SOF - SOF for ISO 15693. Automatically chosen between 1/256 and 1/4\n
 *
 * */
#define PHHAL_HW_CONFIG_SYMBOL_START              0x0015U

/**
 * Disable / Set the EOF symbol of a frame.
 * Sets the end of frame symbol for a frame for ICODE EPIC UID protocol.\n
 * #PH_OFF - Disable EoF\n
 * */
#define PHHAL_HW_CONFIG_SYMBOL_END                0x0016U

/**
 * Sets the CRC type for Tx(#PHHAL_HW_CONFIG_TXCRC) and Rx(#PHHAL_HW_CONFIG_RXCRC).
 * Values can be one of\n
 * #PHHAL_HW_CRCTYPE_CRC5,\n
 * #PHHAL_HW_CRCTYPE_CRC16\n
 * optionally combined with the following inversion option.\n
 * #PHHAL_HW_CRCOPTION_INVERTED.
 *
 * */
#define PHHAL_HW_CONFIG_CRCTYPE                   0x0017U

/**
 * Set TxWait (time between last RxIrq and transmit start of succeeding frame) in milliseconds.\n
 *
 * */
#define PHHAL_HW_CONFIG_TXWAIT_MS                 0x0018U

/**
 * Set the #PH_ON/#PH_OFF Jewel exchange mode.
 * This should be done by user before Jewel functions are called.
 * */
#define PHHAL_HW_CONFIG_JEWEL_MODE                0x0020U

/**
 * Get config to get the card type.
 * */
#define PHHAL_HW_CONFIG_CARD_TYPE                   0x0021U

/**
 * Disable MIFARE(R) Classic Crypto1.\n
 * Disables the MIFARE crypto1 in the IC. Only value PH_OFF is allowed.\n
 * The MIFARE Crypto1 will be enabled by the MFAuthent command. This bit cannot be set by software.
 * */
#define PHHAL_HW_CONFIG_DISABLE_MF_CRYPTO1        0x002EU

/**
 * Set/Get an offset value\n
 * A value at this offset on HAL Tx Buffer can be read or written by using\n
 * Get/Set(#PHHAL_HW_CONFIG_TXBUFFER) once the offset is set using this parameter.\n
 * Used by Protocol components.
 * */
#define PHHAL_HW_CONFIG_TXBUFFER_OFFSET           0x002FU

/**
 * Set/Get start position of RX buffer to be used (never changed by HAL).\n
 *
 * */
#define PHHAL_HW_CONFIG_RXBUFFER_STARTPOS         0x0030U

/**
 * Get size of Rx buffer set at HAL initialization. This is read-only parameter.\n
 * Used by protocols to know the Rx buffer size for chaining purposes.
 * */
#define PHHAL_HW_CONFIG_RXBUFFER_BUFSIZE          0x0031U

/**
 * Get size of TX buffer set at HAL initialization. This is read-only parameter.\n
 * Used by protocols to know the TxBuffer size.
 * */
#define PHHAL_HW_CONFIG_TXBUFFER_BUFSIZE          0x0032U

/**
 * Set/Get the amount of valid bytes in Tx buffer. \n
 *
 * */
#define PHHAL_HW_CONFIG_TXBUFFER_LENGTH           0x0033U

/**
 * Access the transmit buffer(TxBuffer) at the byte offset defined by #PHHAL_HW_CONFIG_TXBUFFER_OFFSET.\n
 * Used to get or set two bytes from/to a particular position in TxBuffer.\n
 * The position in transmit buffer is defined by setting TXBUFFER_OFFSET.\n
 * Used by protocol components.
 * */
#define PHHAL_HW_CONFIG_TXBUFFER                  0x0034U

/**
 * Sets, configures and start the guard time to send Poll commands. When SetConfig with this Key is performed timer is started
 * but will not wait till timer to expire. Exchange API should wait till this timer is expired before
 * transmitting Poll Frame. Also exchange API should stop this timer if there is any error in exchange API.
 * */
#define PHHAL_HW_CONFIG_POLL_GUARD_TIME_US        0x0035U

/**
 * Set/Reset minimum FDT (only for proximity check).\n
 * Used to set minimum frame delay time (timeout) in microseconds as required for proximity check\n
 * command of MIFARE Plus.
 *
 * */
#define PHHAL_HW_CONFIG_SETMINFDT                 0x0051U

/**
 * Get the status of external RF field. Returned values are #PH_ON or #PH_OFF.
 * Deprecated.
 * */
#define PHHAL_HW_CONFIG_EXT_RF_ON                 0x0052U

/**
 * Enable (#PH_ON) or disable (#PH_OFF) multiple reception.\n
 * Please refer to phpalFelica.h and phpalFelica_ReqC function documentation to know the
 * frame format in which the data is returned.
 * */
#define PHHAL_HW_CONFIG_RXMULTIPLE                0x0053U

/**
 * Get the status if active communication mode is #PH_ON / #PH_OFF.\n
 * Used by protocols to know the mode.
 *
 * */
#define PHHAL_HW_CONFIG_ACTIVEMODE                0x0054U

/**
 * Set/Reset MFHalted bit in MifNFCReg.\n
 *
 * When set, this indicates that the IC is set to HALT mode in card operation mode at 106 kBit.\n
 * Once set, when phhalHw_Autocoll API is called in card/target mode, will only accept WUPA/ALL_REQ command to respond.
 *
 * */
#define PHHAL_HW_CONFIG_MFHALTED                  0x0055U

/**
 * Enable/disable RF collision avoidance for passive communication mode. (#PH_ON or #PH_OFF).\n
 * This parameter should be set before \ref phhalHw_FieldOn to perform Initial RFCA.
 * By default after IC HAL initialization, this should be set to #PH_ON
 * */
#define PHHAL_HW_CONFIG_RFCA                      0x0056U

/**
 * Enable RF-ON interrupt\n
 *
 * This is typically used in card/target mode. When there is no external RF, this configuration is set in the HAL\n
 * and the controller can go into a wait state for the external RF-ON interrupt to occur.
 *
 * */
#define PHHAL_HW_CONFIG_RFON_INTERRUPT            0x0057U

/**
 * Get the framing and speed at which target is operating.\n
 * Read-only parameter.
 * RF data rate values in the LSB and framing in the MSB are returned.\n
 * MSB values can be #PHHAL_HW_RF_TYPE_A_FRAMING, #PHHAL_HW_RF_TYPE_B_FRAMING, #PHHAL_HW_RF_TYPE_F_FRAMING\n
 * LSB values can be #PHHAL_HW_RF_DATARATE_106, #PHHAL_HW_RF_DATARATE_212, #PHHAL_HW_RF_DATARATE_424\n
 *
 * */
#define PHHAL_HW_CONFIG_TARGET_DATARATE_FRAMING   0x0059U

/**
 * Configure operation mode for this Layer.\n
 * Values can be #RD_LIB_MODE_NFC or #RD_LIB_MODE_EMVCO
 *
 * */
#define PHHAL_HW_CONFIG_OPE_MODE                  0x005AU

/**
 * Enable/Disable handling start byte at 106kbps in NFCIP Mode of communication.\n
 * This is to tell the HAL to prepend the start byte as required for passive\n
 * communication mode at 106kbps.
 *
 * */
#define PHHAL_HW_CONFIG_NFCIP_STARTBYTE           0x005CU

/**
 * Enable symbol send (#PH_ON).\n
 *
 * */
#define PHHAL_HW_CONFIG_SET_SYMBOL_SEND           0x005DU

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) EMD error check for Emvco.\n
 * The EMD check should be enabled only after ISO 14443A/B layer 3\n
 * activation.
 *
 * */
#define PHHAL_HW_CONFIG_SET_EMD                   0x005EU

/**
 * Get the status of internal RF field. Returned values are #PH_ON or #PH_OFF.
 *
 * */
#define PHHAL_HW_CONFIG_INT_RF_ON                 0x005FU

/**
 * Set new Rx Threshold values for new EMD algorithm in case of the presence of a disturber.
 *
 * */
#define PHHAL_HW_CONFIG_EMD_RXTHRESHOLD           0x0060U

/**
 * Set receive gain values for new EMD algorithm in case of the presence of a disturber.
 *
 * */
#define PHHAL_HW_CONFIG_EMD_RECEIVEGAIN           0x0061U

/**
* Set prefilter value for in case of the presence of a disturber.
*
* */
#define PHHAL_HW_CONFIG_EMD_PREFILTER             0x0062U
/**
* Set high pass corner frequencies.
* Signals allow 4 different settings of the base band amplifier lower cut-off frequency from ~40 kHz to ~300 kHz.
*
* */
#define PHHAL_HW_CONFIG_EMD_RECEIVEHPCF           0x0063U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) EMD error check for discovery loop using phhalHw_DetectEMD function.
 * */
#define PHHAL_HW_CONFIG_EMD_MODE                  0x0064U

/**
 * Set new TIMEOUT_VALUE_MS for checking EMD.
 *
 * */
#define PHHAL_HW_CONFIG_EMD_TIMEOUT               0x0065U

/*@}*/

/**
 * \name IC specific configuration parameters
 * These are not applicable to all ICs and
 * are not mandatory to be implemented to
 * comply with this HAL specification.
 */
/*@{*/

/**
 * Sets the exchange time measurement mode in the IC. The values can be one of:\n
 * #PHHAL_HW_TIMING_MODE_OFF - Time measurement disabled\n
 * #PHHAL_HW_TIMING_MODE_FDT - Frame delay time to be measured\n
 * #PHHAL_HW_TIMING_MODE_COMM - Overall time to be measured\n
 * #PHHAL_HW_TIMING_MODE_OPTION_MASK - Additional option-mask for time measurement.\n
 * #PHHAL_HW_TIMING_MODE_OPTION_DEFAULT - The timing value is accumulated on each exchange until it gets retrieved by phhalHw_GetConfig.\n
 * #PHHAL_HW_TIMING_MODE_OPTION_AUTOCLEAR - Automatically resets the current timing value prior to any communication.
 *
 * */
#define PHHAL_HW_CONFIG_TIMING_MODE               0x8010U

/**
 * Retrieve elapsed time of receive timer ([us]).\n
 *
 * */
#define PHHAL_HW_CONFIG_TIMING_US                 0x8011U

/**
 * Retrieve elapsed time of receive timer ([ms]).\n
 *
 * */
#define PHHAL_HW_CONFIG_TIMING_MS                 0x8012U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) EMD error check for FeliCa.\n
 *
 * Note: Before Setting FELICA_EMD bit, OpeMode need to be configured to \ref RD_LIB_MODE_FELICA.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD                        0x8025U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) FeliCa EMD Length check based
 * on Maximum and Minimum Length configuration using \ref PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MAX
 * and \ref PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MIN respectively.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_CHECK              0x8026U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) FeliCa EMD Response Code check based
 * on Response code that can be configured using \ref PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_BYTE_VAL.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_CHECK               0x8027U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) FeliCa EMD Protocol error check.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_PROTOCOL_ERR_CHECK     0x8028U

/**
 * Enable (#PH_ON) or Disable (#PH_OFF) FeliCa EMD Integrity error check.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_INTEGRITY_ERR_CHECK    0x8029U

/**
 * Configure the Minimum Length Byte value that shall be used by the Reader IC
 * to receive under FeliCa EMD. Response containing Length Byte value lesser than the
 * configured value is treated as EMD error.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MIN           0x802AU

/**
 * Configure the Maximum Length Byte value that shall be used by the Reader IC
 * to receive under FeliCa EMD. Response containing Length Byte value greater than the
 * configured value is treated as EMD error.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_LEN_BYTE_MAX           0x802BU

/**
 * Configure the RC Byte value that shall be compared to the received RC byte value in
 * the received FeliCa Response, if comparison fails then Reader IC shall consider
 * the response as EMD error.\n
 * */
#define PHHAL_HW_CONFIG_SET_FELICA_EMD_RC_BYTE_VAL            0x802CU

/**
 * Configures the max. number of bytes which are pre-cached prior to command execution.\n
 * Bytes up to the maximum pre-cache limit can be written into the FIFO before the command is started.\n
 * The maximum pre-cache limit depends upon the FIFO size of the IC.\n
 * This will ensure faster transmission in comparison to starting the command and then writing the\n
 * parameters + data to the FIFO. Ncx3320 HALs provide such a functionality.\n
 *
 * */
#define PHHAL_HW_CONFIG_MAX_PRECACHED_BYTES       0x8035U

/**
 * Set the BAL connection type. The default value is always #PHHAL_HW_BAL_CONNECTION_RS232.\n
 * Other supported values are\n
 * #PHHAL_HW_BAL_CONNECTION_SPI\n
 * #PHHAL_HW_BAL_CONNECTION_I2C\n
 * */
#define PHHAL_HW_CONFIG_BAL_CONNECTION            0x8040U

/**
 * Bit rate for serial UART communication for NCx3320\n
 * valid values range from - #PHHAL_HW_RS232_BITRATE_9600 to\n
 * #PHHAL_HW_RS232_BITRATE_460800
 * */
#define PHHAL_HW_CONFIG_SERIAL_BITRATE            0x8041U

/**
 * Perform an RF-reset in case of a timeout (only for phhalHw_Exchange)\n
 * Valid values are #PH_ON, #PH_OFF
 * */
#define PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT        0x8050U

/**
 * Custom Configuration for Individual Reader IC.
 *
 * */
#define PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC     0x8060U

/**
 * Get any additional information that the HAL might provide
 * For example any specific error information.
 *
 * */
#define PHHAL_HW_CONFIG_ADDITIONAL_INFO           0x802FU

/*@}*/

#ifdef NXPBUILD__PHHAL_HW_NCX3321

/**
 * \defgroup phhalHw_Ncx3321 component : Ncx3321
 * \ingroup phhalHw
 * \brief Ncx3321 HAL component
 *
 * @{
 */

/**
 * Set NCX3321 CTS Event Status.
 * Valid values are #PH_ON, #PH_OFF
 * */
#define PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_STATUS   PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC

/**
 * Enable/Disable NCx3321 CTS Event through IRQ Pin.
 * Valid values are #PH_ON, #PH_OFF
 * */
#define PHHAL_HW_NCX3321_CONFIG_CTS_EVENT_ENABLE   PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC + 1U

/**
 * Enable/Disable NCX3321 LPCD Event
 * Valid values are #PH_ON, #PH_OFF.
 *
 * */
#define PHHAL_HW_NCX3321_CONFIG_LPCD_EVENT_ENABLE   PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC + 2U

/**
 * Configure the expected event when /ref phhalHw_EventWait
 * API is been called by User.
 *
 * Event the can be configured are /ref NCx3321_events
 * */
#define PHHAL_HW_NCX3321_CONFIG_EXPECTED_EVENT      PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC + 3U

/**
 * Set NCX3321 RF ON Event Status.
 * Valid values are #PH_ON, #PH_OFF
 * */
#define PHHAL_HW_NCX3321_CONFIG_RF_ON_EVENT_STATUS  PHHAL_HW_CONFIG_CUSTOM_READER_SPECIFIC + 4U

/**
 * end of group phhalHw_Ncx3321 component : Ncx3321
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

/**
 * \name Card Configuration
 */
/*@{*/
#define PHHAL_HW_CARDTYPE_CURRENT               0x0000U /**< Re-Apply settings for current communication mode. */
#define PHHAL_HW_CARDTYPE_ISO14443A             0x0001U /**< ISO/IEC 14443A mode. */
#define PHHAL_HW_CARDTYPE_ISO14443B             0x0002U /**< ISO/IEC 14443B mode. */
#define PHHAL_HW_CARDTYPE_FELICA_212            0x0003U /**< Felica (JIS X 6319) mode. */
#define PHHAL_HW_CARDTYPE_ISO15693              0x0004U /**< ISO/IEC 15693 mode. */
#define PHHAL_HW_CARDTYPE_FELICA_424            0x000AU /**< Felica mode at 424 baud. */
#define PHHAL_HW_CARDTYPE_UNKNOWN               0x00FFU /**< Unknown card type. */
/*@}*/

/**
 * \name CRC Values
 */
/*@{*/
#define PHHAL_HW_CRCTYPE_CRC5               0x0001U /**< 5 bit length, polynomial x^5+x^3+1U, preset value 01001b, residue 00000b. */
#define PHHAL_HW_CRCTYPE_CRC16              0x0002U /**< ISO/IEC 13239, 16 bit length, polynomial x^16+x^12+x^5+1U, preset value 0xFFFF, residue 0x1D0F. */
#define PHHAL_HW_CRCOPTION_INVERTED         0x0100U /**< To indicate that the CRC generated should be inverted. This should be ORed with the CRCTYPEs above. */
/*@}*/

/**
 * \name RF Data rate values
 */
/*@{*/
#define PHHAL_HW_RF_DATARATE_106                0x0000U /**< Data rate setting for 106 kBit/s. */
#define PHHAL_HW_RF_DATARATE_212                0x0001U /**< Data rate setting for 212 kBit/s. */
#define PHHAL_HW_RF_DATARATE_424                0x0002U /**< Data rate setting for 424 kBit/s. */
#define PHHAL_HW_RF_DATARATE_848                0x0003U /**< Data rate setting for 848 kBit/s. */

#define PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_256    0x000AU /**< Data rate setting for ISO15693 '1 out of 256' mode. */
#define PHHAL_HW_RF_TX_DATARATE_1_OUT_OF_4      0x000BU /**< Data rate setting for ISO15693 '1 out of 4' mode. */
#define PHHAL_HW_RF_RX_DATARATE_LOW             0x000CU /**< Data rate setting for ISO15693 low data rate at 6.6Kbits/s. */
#define PHHAL_HW_RF_RX_DATARATE_HIGH            0x000DU /**< Data rate setting for ISO15693 high data rate at 26Kbits/s. */
#define PHHAL_HW_RF_RX_DATARATE_FAST_LOW        0x000EU /**< Data rate setting for ISO15693 fast (low*2U = 13Kbits/s) data rate (FAST INVENTORY (PAGE) READ). */
#define PHHAL_HW_RF_RX_DATARATE_FAST_HIGH       0x000FU /**< Data rate setting for ISO15693 fast (high*2U = 53Kbits/s) data rate (FAST INVENTORY (PAGE) READ). */
#define PHHAL_HW_RF_I15693_53KBPS_DATARATE      0x001BU /**< Data rate setting for 53 kbps. Used for Testing */

/*@}*/

/**
 * \name RF Framing Mode Values
 */
/*@{*/
#define PHHAL_HW_RF_TYPE_A_FRAMING              0x0100U /**< Data rate setting for 106 kBit/s. */
#define PHHAL_HW_RF_TYPE_B_FRAMING              0x0200U /**< Data rate setting for 212 kBit/s. */
#define PHHAL_HW_RF_TYPE_F_FRAMING              0x0300U /**< Data rate setting for 424 kBit/s. */
#define PHHAL_HW_RF_TYPE_ACTIVE_FRAMING         0x0400U /**< Data rate setting for 848 kBit/s. */

#define PHHAL_HW_RF_DATARATE_OPTION_MASK        0x00FFU /**< Option-mask for data rate. */
#define PHHAL_HW_RF_FRAMING_OPTION_MASK         0xFF00U /**< Option-mask for framing. */
#define PHHAL_HW_RF_TYPE_A_START_BYTE           0xF0U   /**< Start byte used at passive 106kbps. */
/*@}*/

/**
 * \name Helper macros used for phhalHw_Autocoll.
 * Used to extract data rate and framing values.
 */
/*@{*/
#define PHHAL_HW_GETFRAMING( protParams ) ((protParams) >> 8U)
#define PHHAL_HW_GETBITRATE( protParams ) ((protParams) & 0x00FFU)
/*@}*/

/**
 * \name RF sub carrier Values
 */
/*@{*/
#define PHHAL_HW_SUBCARRIER_SINGLE  0x0000U /**< Sub carrier setting for ISO15693 single sub carrier. */
#define PHHAL_HW_SUBCARRIER_DUAL    0x0001U /**< Sub carrier setting for ISO15693 / EPC V2 dual sub carrier. */
#define PHHAL_HW_SUBCARRIER_QUAD    0x0002U /**< Sub carrier setting for EPC V2 quad sub carrier. */
/*@}*/

/**
 * \name Time units
 */
/*@{*/
#define PHHAL_HW_TIME_MICROSECONDS  0x0000U /**< Time in microseconds (us). */
#define PHHAL_HW_TIME_MILLISECONDS  0x0001U /**< Time in milliseconds (ms). */
/*@}*/

/**
 * \name Timing mode settings
 */
/*@{*/
#define PHHAL_HW_TIMING_MODE_OFF                0x0000U /**< Time measurement disabled. */
#define PHHAL_HW_TIMING_MODE_FDT                0x0001U /**< Measures time from Tx-end until Rx-begin. */
#define PHHAL_HW_TIMING_MODE_COMM               0x0002U /**< Measures the duration of the complete communication. */
#define PHHAL_HW_TIMING_MODE_OPTION_MASK        0xFF00U /**< Additional option-mask for time measurement. */
#define PHHAL_HW_TIMING_MODE_OPTION_DEFAULT     0x0000U /**< The timing value is accumulated on each exchange until it gets retrieved by \ref phhalHw_GetConfig. */
#define PHHAL_HW_TIMING_MODE_OPTION_AUTOCLEAR   0x0100U /**< Automatically resets the current timing value prior to any communication. */
/*@}*/

/**
 * EMD mode settings
 * EMDMode is OFF :
 * • EMD detection algorithm is not executed.
 * • settings in pDataParams->bEmdThreshold, pDataParams->bEmdReceiveGain, pDataParams->bEmdPreFilter and pDataParams->bEmdReceiveHpcf
 * are always ignored.
 *
 * EMDMode is DEFAULT enabled :
 * • EMD detection algorithm is executed.
 * • settings in pDataParams->bEmdThreshold, pDataParams->bEmdReceiveGain, pDataParams->bEmdPreFilter and pDataParams->bEmdReceiveHpcf
 * are only applied in case a disturber is detected.
 *
 * EMDMode is CUSTOM (NEW) enabled :
 * • EMD detection algorithm is NOT executed.
 * • settings in pDataParams->bEmdThreshold, pDataParams->bEmdReceiveGain, pDataParams->bEmdPreFilter and pDataParams->bEmdReceiveHpcf
 * are always applied.
 */
/*@{*/
#define PHHAL_HW_EMD_MODE_OFF        0x00U /**< EMDMode is OFF */
#define PHHAL_HW_EMD_MODE_DEFAULT    0x01U /**< EMDMode is DEFAULT enabled */
#define PHHAL_HW_EMD_MODE_CUSTOM     0x02U /**< EMDMode is CUSTOM (NEW) enabled */
/*@}*/


/**
 * \name Field reset default times
 */
/*@{*/
#define PHHAL_HW_FIELD_OFF_DEFAULT          0x0005U     /**< Default field-off time. */
#define PHHAL_HW_FIELD_RECOVERY_DEFAULT     0x0005U     /**< Default field-recovery time. */
/*@}*/

/**
 * \name Frame Symbols (use #PH_OFF to disable)
 */
/*@{*/
#define PHHAL_HW_SYMBOL_I15693_SOF          0x0005U /**< ISO15693 SOF (automatically chosen between 1/256 and 1/4). */
/*@}*/

/**
 * \name MIFARE Classic authenticate options
 */
/*@{*/
#define PHHAL_HW_MFC_KEYA               0x0AU   /**< MIFARE Classic key type A. */
#define PHHAL_HW_MFC_KEYB               0x0BU   /**< MIFARE Classic key type B. */
#define PHHAL_HW_MFC_KEY_LENGTH         0x06U   /**< Length of a MIFARE Classic key (for completeness). */
/*@}*/

/**
 * \name BAL Connection types
 */
/*@{*/
#define PHHAL_HW_BAL_CONNECTION_RS232   0x0000U     /**< Reader IC is connected via RS232. */
#define PHHAL_HW_BAL_CONNECTION_SPI     0x0001U     /**< Reader IC is connected via SPI. */
#define PHHAL_HW_BAL_CONNECTION_I2C     0x0002U     /**< Reader IC is connected via I2C. */
/*@}*/

/**
 * \name RS232 Bit rate Values
 */
/*@{*/
#define PHHAL_HW_RS232_BITRATE_7200     0x0000U     /**< 7.200 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_9600     0x0001U     /**< 9.600 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_14400    0x0002U     /**< 14.400 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_19200    0x0003U     /**< 19.200 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_38400    0x0004U     /**< 38.400 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_57600    0x0005U     /**< 57.500 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_115200   0x0006U     /**< 115.200 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_128000   0x0007U     /**< 128.000 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_230400   0x0008U     /**< 230.400 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_460800   0x0009U     /**< 460.800 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_921600   0x000AU     /**< 921.600 kBit/s. */
#define PHHAL_HW_RS232_BITRATE_1228800  0x000BU     /**< 1.228.800 kBit/s. */
/*@}*/

/**
 * \name Min FDT values
 */
/*@{*/
#define PHHAL_HW_MINFDT_106_US        91+10         /**< (n * 128 + 84U) / 13.56; n = 9. */
#define PHHAL_HW_MINFDT_212_US        87+40         /**< (n * 128 + 148U) / 13.56; n = 8. */
#define PHHAL_HW_MINFDT_424_US        84+35         /**< (n * 128 + 116U) / 13.56; n = 8. */
#define PHHAL_HW_MINFDT_848_US        83+45         /**< (n * 128 + 100U) / 13.56; n = 8. */
/*@}*/

/**
 * \name Framing mode values
 */
/*@{*/
#define PHHAL_HW_I14443A_106_FRAMING        0x00U    /**< ISO/IEC 14443A/MIFARE and passive communication mode 106 kBit. */
#define PHHAL_HW_ACTIVE_MODE_FRAMING        0x01U    /**< Active communication mode. */
#define PHHAL_HW_FELICA_FRAMING             0x02U    /**< FeliCa and passive communication mode 212 and 424 kBit. */
#define PHHAL_HW_I14443B_FRAMING            0x03U    /**< ISO/IEC 14443B. */
/*@}*/

/**
 * \name Target Bit Coding
 */
/*@{*/
#define PHHAL_HW_EMULATE_TYPE_A_TARGET      0x0001U /**< Bit setting to emulate Type A target. */
#define PHHAL_HW_EMULATE_TYPE_B_TARGET      0x0002U /**< Bit setting to emulate Type B target. */
#define PHHAL_HW_EMULATE_TYPE_F_TARGET      0x0004U /**< Bit setting to emulate Type F target. */
/*@}*/

/**
 * \name Felica Response Frame Coding
 * Applicable when \ref PHHAL_HW_CONFIG_RXMULTIPLE is enable
 */
/*@{*/
#define PHHAL_HW_REQC_MIN_LEN                        19U  /**< Minimum length of valid ReqC response when multiple reception is enabled. */
#define PHHAL_HW_RESP_FRAME_SIZE                     32U  /**< Frame size of one felica response when multiple reception is enable. */
#define PHHAL_HW_STATUS_FRAME_LEN_BYTE_POS           28U  /**< Byte position where length information in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_ERR_BYTE_POS           29U  /**< Byte position where error information in felica response frame. */

#define PHHAL_HW_STATUS_FRAME_CL_ERR_POS        (1U << 0U)  /**< Bit position for contact less Error in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_DATA_ERR_POS      (1U << 1U)  /**< Bit position for data(CRC or Parity) error in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_PROT_ERR_POS      (1U << 2U)  /**< Bit position for protocol error in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_COLL_ERR_POS      (1U << 3U)  /**< Bit position for collision error in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_LEN_ERR_POS       (1U << 4U)  /**< Bit position for length error in felica response frame. */

#define PHHAL_HW_STATUS_FRAME_ERR_MASK             0x1FU  /**< Bit mask for error byte in felica response frame. */
#define PHHAL_HW_STATUS_FRAME_LEN_MASK             0x1FU  /**< Bit mask for Length byte in felica response frame. */
/*@}*/


/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW */
/*==================================================================================================
*                                             ENUMS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW
/** \addtogroup phhalHw Hardware Abstraction Layer
 * @{
 */

/**
 * \brief State for CardMode
 */
typedef enum
{
	PHHAL_CARDMODE_STATE_START = 0, /**< Indicate state in Non-blocking set card mode process. */
	PHHAL_CARDMODE_STATE_LOADPROTOCOL, /**< Indicate state in Non-blocking set card mode process. */
	PHHAL_CARDMODE_STATE_READ_E2, /**< Indicate state in Non-blocking set card mode process. */
	PHHAL_CARDMODE_STATE_LOAD_REG, /**< Indicate state in Non-blocking set card mode process. */
	PHHAL_CARDMODE_STATE_FINISH /**< Indicate state in Non-blocking set card mode process. */
} CARDMODE_StateType_t;

/**
 * \brief State for Transport Layer Management
 */
typedef enum
{
	PHHAL_TRANSPORT_STATE_IDLE = 0, /**< Transport layer in IDLE state */
	PHHAL_TRANSPORT_STATE_DATATX_IRQREQ, /**< Data transmission and request IRQ from FrontEnd. */
	PHHAL_TRANSPORT_STATE_DATATX_IRQWAIT, /**< Data transmission and wait IRQ response. */
	PHHAL_TRANSPORT_STATE_DATARX_IRQREQ, /**< Data receiving and request IRQ from FrontEnd. */
	PHHAL_TRANSPORT_STATE_DATARX_IRQWAIT, /**< Data receiving and wait IRQ response. */
	PHHAL_TRANSPORT_STATE_PROCESS_TIMEOUT, /**< Process timeout. */
	PHHAL_TRANSPORT_STATE_PROCESS_GETDATA /**< Process receiving data from buffer. */
} TM_StateType_t;
/**
 * \brief Status of Result for Transport Layer Management
 */
typedef enum
{
	PHHAL_TRANSPORT_STATUS_NORESULT = 0, /**< Indicate have no Result. */
	PHHAL_TRANSPORT_STATUS_CMD_EXECUTING, /**< Indicate Command transport is still executing. */
	PHHAL_TRANSPORT_STATUS_CMD_EXECUTED, /**< Indicate Command transport has been executed. */
	PHHAL_TRANSPORT_STATUS_DATA_TRANSFERING, /**< Indicate Data transport is still transferring. */
	PHHAL_TRANSPORT_STATUS_DATA_RECEIVED, /**< Indicate Data transport has been received. */
	PHHAL_TRANSPORT_STATUS_DATA_RECEIVE_ERR, /**< Indicate Data transport has been error. */
	PHHAL_TRANSPORT_STATUS_TIMEOUT /**< Indicate transport process has been timeout. */
} TM_StatusType_t;

/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW */

#ifdef NXPBUILD__PHHAL_HW_NCx3320

/** \addtogroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

/* LPCD Related */
typedef enum
{
	LPCD_CALIB_START = 0, /**< Indicate state in LPCD Non-blocking process */
	LPCD_CALIB_CMD_REQ, /**< Indicate state in LPCD Non-blocking process */
	LPCD_CALIB_CMD_WAITRSP, /**< Indicate state in LPCD Non-blocking process */
	LPCD_CALIB_FINISH /**< Indicate state in LPCD Non-blocking process */
} LPCD_CALIB_StateType_t;

/* Advanced LPCD related typedefs*/
typedef enum
{
	PH_LPCD_INIT = 0x00, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_START, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_CMD_PREPARE, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_CMD_START, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_CMD_WAIT_CONFIG_IRQ, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_CMD_WAIT, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_CMD_END, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_CONFIG_END, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_PREPARE, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_START, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_WAIT_CONFIG_IRQ, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_WAIT, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_LEAVE_STANDBY, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_EXECUTE_END, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_READY, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_INVALID, /**< Indicate state in advanced LPCD Non-blocking process */
	PH_LPCD_IDLE /**< Indicate state in advanced LPCD Non-blocking process */
} phLpcd_t;

/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */
/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW
/** \addtogroup phhalHw Hardware Abstraction Layer
 * @{
 */

/**
 *
 * \brief RF callback which will be called by ISR handler implementation in Platform Layer.
 * \retval  None
 */
typedef void (*ppRFCallBck_t)(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams);

/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW */

#ifdef NXPBUILD__PHHAL_HW_NCX3321

/**
 * \addtogroup phhalHw_Ncx3321 component : Ncx3321
 * \ingroup phhalHw
 * \brief Ncx3321 HAL component
 *
 * @{
 */

/**
 *
 * \brief Guard timer callback which will be called by ISR handler implementation in Platform Layer.
 * \retval  None
 */
typedef void (*ppTimerCallBck_t)(void);
/**
 * end of group phhalHw_Ncx3321 component : Ncx3321
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef NXPBUILD__PHHAL_HW_NCx3320

/** \addtogroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

/**
 * \brief LPCD structure to handle Non-Blocking Advanced LPCD
 */
typedef struct
{
  VAR(LPCD_CALIB_StateType_t, ANFCRL_VAR) bCalib_State; /**< State for LPCD Non-blocking processing */
  VAR(uint8, ANFCRL_VAR) bT4Config; /**< Data For LPCD Non-blocking processing */
  VAR(uint8, ANFCRL_VAR) bLpcdIload; /**< Data For LPCD Non-blocking processing */
  VAR(uint8, ANFCRL_VAR) bLpcdIndex; /**< Data For LPCD Non-blocking processing */
  VAR(uint8, ANFCRL_VAR) bLpcdMatrix[16][3]; /**< Data For LPCD Non-blocking processing */
  VAR(uint8, ANFCRL_VAR) bRxAnaBackup; /**< Data For LPCD Non-blocking processing */
} phhal_LPCD_Handle_t;

/**
 * \brief StateMachine structure to handle hw command
 */
typedef struct
{
  VAR(uint8, ANFCRL_VAR) bCommand_State;
  VAR(CARDMODE_StateType_t, ANFCRL_VAR) bCardMode_State;
  VAR(uint8, ANFCRL_VAR) bApplyProc_State;
  VAR(uint8, ANFCRL_VAR) bSetConfig_State;
  VAR(uint8, ANFCRL_VAR) bReceive_State;
  VAR(uint8, ANFCRL_VAR) bEmdDetect_State;
  VAR(uint8, ANFCRL_VAR) bCheckForEmd_State;
  VAR(uint8, ANFCRL_VAR) bWaitIrq_State;
  VAR(uint8, ANFCRL_VAR) bFieldReset_State;
  VAR(uint8, ANFCRL_VAR) bWait_State;
	/* Card Mode 17 bytes */
  VAR(uint8, ANFCRL_VAR) bTxConfig;
  VAR(uint8, ANFCRL_VAR) bRxConfig;
  VAR(uint16, ANFCRL_VAR) wEEAddress;
  VAR(uint8, ANFCRL_VAR) bRegAddress;
  VAR(uint8, ANFCRL_VAR) bNumBytes;
  VAR(uint8, ANFCRL_VAR) bRegister;
  VAR(uint32, ANFCRL_VAR) dwAddrIndex;
  P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pTxRegisterSet;
  P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pRxRegisterSet;
	/* Apply Protocols 8 bytes */
  P2CONST(uint16, AUTOMATIC, ANFCRL_APPL_CONST) pShadowDefault;
  VAR(uint16, ANFCRL_VAR) wShadowCount;
  VAR(uint16, ANFCRL_VAR) wBakDataRate;
  VAR(uint16, ANFCRL_VAR) wConfig;

  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpBuffer;
  VAR(uint16, ANFCRL_VAR) wTmpBufferLen;
  VAR(uint16, ANFCRL_VAR) wTmpBufferSize;
} phhal_CMD_Handle_t;

/**
 * \brief Ncx3320 HAL parameter structure
 */
typedef struct
{
  VAR(uint16, ANFCRL_VAR) wId; /**< Layer ID for this component, NEVER MODIFY!. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams; /**< Pointer to the lower layers parameter structure. */
  P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pLoadRegConfig; /**< Pointer to configuration buffer for LoadReg mode; Refer to \ref phhalHw_Ncx3320_Init. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer; /**< Pointer to global transmit buffer used by the Exchange() function. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer; /**< Pointer to global receive buffer used by the Exchange() function. */
  VAR(uint32, ANFCRL_VAR) dwTimingUs; /**< Current timing value. */
	/*
	 * 31...........24.........16.........8.......0
	 * |     RFU     | Version |   Derivative    |
	 * For more information on Version field refer VERSION register of NCx3320/NCx3320PLUS.
	 */
  VAR(uint32, ANFCRL_VAR) dwDerivative; /**< Derivative and Version of the Front End attached. */
  VAR(uint16, ANFCRL_VAR) wCfgShadow[PHHAL_HW_NCx3320_SHADOW_COUNT]; /**< Configuration shadow; Stores configuration for current card type. */
  VAR(uint16, ANFCRL_VAR) wTxBufSize; /**< Size of the global transmit buffer. */
  VAR(uint16, ANFCRL_VAR) wTxBufLen; /**< Number of valid bytes within the transmit buffer. */
  VAR(uint16, ANFCRL_VAR) wRxBufSize; /**< Size of the global receive buffer. */
  VAR(uint16, ANFCRL_VAR) wRxBufLen; /**< Number of valid bytes within the receive buffer. */
  VAR(uint16, ANFCRL_VAR) wRxBufStartPos; /**< Starting position within the global receive buffer. */
  VAR(uint16, ANFCRL_VAR) wMaxPrecachedBytes; /**< Holds the max. number of bytes which are pre-cached prior to command execution. */
  VAR(uint16, ANFCRL_VAR) wTimingMode; /**< Current timing measurement mode. */
  VAR(uint16, ANFCRL_VAR) wFieldOffTime; /**< Field-Off-Time in milliseconds. */
  VAR(uint16, ANFCRL_VAR) wFieldRecoveryTime; /**< Field-Recovery-Time in milliseconds. */
  VAR(uint16, ANFCRL_VAR) wAdditionalInfo; /**< Storage for additional error information. */
  VAR(uint16, ANFCRL_VAR) wPowerDownTimeMs; /**< Power-Down time in milliseconds if power-down mode is used. */
  VAR(uint16, ANFCRL_VAR) wDetectionTimeUs; /**< Detection time in microseconds if power-down mode is used. */
  VAR(uint16, ANFCRL_VAR) dwFdtPc; /**< Current timing value backup for PC. */
  VAR(uint8, ANFCRL_VAR) bLoadRegMode; /**< Whether LoadReg-Mode is enabled or not. */
  VAR(uint8, ANFCRL_VAR) bCardType; /**< Type of card for which the hal is configured for. */
  VAR(uint8, ANFCRL_VAR) bTimeoutUnit; /**< Unit of current timeout value (either #PHHAL_HW_TIME_MICROSECONDS or #PHHAL_HW_TIME_MILLISECONDS). */
  VAR(uint8, ANFCRL_VAR) bSymbolStart; /**< Preamble of a frame. */
  VAR(uint8, ANFCRL_VAR) bSymbolEnd; /**< Trailer symbol of a frame. */
  VAR(uint8, ANFCRL_VAR) bFifoSize; /**< Fifo-Size setting. */
  VAR(uint8, ANFCRL_VAR) bBalConnectionType; /**< Type of the underlying BAL connection. Refer to #PHHAL_HW_CONFIG_BAL_CONNECTION. */
  VAR(uint8, ANFCRL_VAR) bRfResetAfterTo; /**< Storage for #PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT setting. */
  VAR(uint8, ANFCRL_VAR) bMode; /**< One of the above LPCD modes. */
  VAR(uint8, ANFCRL_VAR) bI; /**< I-Channel value in case of no card on antenna. */
  VAR(uint8, ANFCRL_VAR) bQ; /**< Q-Channel value in case of no card on antenna. */
  VAR(uint8, ANFCRL_VAR) bTxiLoad; /**< Tx-iLoad value in case of no card on antenna. */
  VAR(uint8, ANFCRL_VAR) bIDelta; /**< The delta value used when configuring bIMin and bIMax*/
  VAR(uint8, ANFCRL_VAR) bQDelta; /**< The delta value used when configuring bQMin and bQMax */
  VAR(uint8, ANFCRL_VAR) bJewelActivated; /**< Set the PH_ON/PH_OFF Jewel exchange mode.*/
  VAR(uint8, ANFCRL_VAR) bOpeMode; /**< Operation mode. One of NFC, EMVCo, ISO.*/
  VAR(uint8, ANFCRL_VAR) bEmdNoiseMaxDataLen; /**< EMVCo EMD noise check length.*/
  VAR(uint8, ANFCRL_VAR) bRxMultiple; /**< Flag indicates whether RX multiple is to be enabled  or not. */
  VAR(uint8, ANFCRL_VAR) bNfcipMode; /**< Enable/Disable to handle start byte at 106kbps in NFCIP-1 mode. */
  VAR(uint8, ANFCRL_VAR) bCheckEmdErr; /**< Enable/Disable to perform Emvco EMD error check. */
  VAR(uint8, ANFCRL_VAR) bEmdMode; /**< Enable/Disable to perform EMD error check in discovery loop. */
  VAR(uint8, ANFCRL_VAR) bEmdTimeout; /**< Timeout threshold for EMD detection algorithm for polling loop. */
  VAR(uint8, ANFCRL_VAR) bEmdThreshold; /**< Rx Threshold for EMD detection algorithm for polling loop. */
  VAR(uint8, ANFCRL_VAR) bEmdReceiveGain; /**< Receive Gain for EMD detection algorithm for polling loop. */
  VAR(uint8, ANFCRL_VAR) bEmdPreFilter; /**< Receive Gain for EMD detection algorithm for polling loop. */
  VAR(uint8, ANFCRL_VAR) bEmdReceiveHpcf; /**< Set high pass corner frequencies. */
  VAR(uint8, ANFCRL_VAR) bPollGuardTimeFlag; /**< Poll Guard Time Flag. */
  VAR(uint8, ANFCRL_VAR) bLpcdOption; /**< Lpcd Option only available in NCx3320 */
  VAR(uint8, ANFCRL_VAR) bTxiDelta; /**< Set value for bIDelta, bQDelta when I, Q change in both directions*/
  VAR(uint8, ANFCRL_VAR) bTxiDirection; /**< Select Txi direction: negative or positive */
  VAR(uint8, ANFCRL_VAR) bTxiChannel; /**< Select Txi channel I or Q*/
  VAR(phhal_LPCD_Handle_t, ANFCRL_VAR) bSmLpcdParams; /**< StateMachine For LPCD Non-blocking processing handle */
  VAR(phhal_CMD_Handle_t, ANFCRL_VAR) bSmCmdParams; /**< StateMachine For HWCommand Non-blocking processing handle */

  VAR(phStatus_t, ANFCRL_VAR) uExStatus;
  VAR(uint8, ANFCRL_VAR) bNoData;
  VAR(uint8, ANFCRL_VAR) bIrq0WaitFor;
  VAR(uint8, ANFCRL_VAR) bIrq1WaitFor;
  VAR(uint8, ANFCRL_VAR) bSbBackup;
  VAR(uint16, ANFCRL_VAR) wTmpBufferLen;
  VAR(uint16, ANFCRL_VAR) wTmpBufferSize;
  VAR(uint16, ANFCRL_VAR) wTxLength;
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTmpBuffer;
} phhalHw_Ncx3320_DataParams_t;

/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321

/**
 * \addtogroup phhalHw_Ncx3321 component : Ncx3321
 * \ingroup phhalHw
 * \brief Ncx3321 HAL component
 *
 * @{
 */

/**
 * \brief NCx3321 HAL Response buffer struct.
 * This structure holds all the response data was sent from NCx3321 HAL.
 */

typedef struct
{
    VAR(uint8, ANFCRL_VAR) bIsrBytesRead;                                  /**< Num of Bytes of response,to be read in ISR */
    VAR(uint8, ANFCRL_VAR) aISRReadBuf[MAX_ISR_READ_BUFFER_SIZE];          /**< Dual Buffer to used to read response, only one used once */
    VAR(uint8, ANFCRL_VAR) aISRReadBuf2[MAX_ISR_READ_BUFFER_SIZE];         /**< Dual Buffer to used to read response, only one used once   */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pHandlerModeBuffPtr;                          /**< Pointer pointing to active Buffer for reading resp in ISR */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsrBuffPtr;                                  /**< Pointer pointing to Buffer holding Instruction Response */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pIsrEvtBuffPtr;                               /**< Pointer pointing to buffer holding Event Response*/
}phIrqResp_t;

/**
 * \brief NCx3321 HAL component.
 * This structure holds all the data that are required for the NCx3321 HAL
 * operations.
 */

typedef struct
{
    VAR(uint16, ANFCRL_VAR) wId;                                       /**< Layer ID for this component, NEVER MODIFY! */
    VAR(uint8, ANFCRL_VAR) bBalConnectionType;                         /**< Type of the underlying BAL connection. Refer to #PHHAL_HW_CONFIG_BAL_CONNECTION. */
    VAR(uint8, ANFCRL_VAR) bRfca;                                      /**< Flag indicates whether RFCA is to be enabled or not (#PH_ON or #PH_OFF, default - #PH_ON). */

    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams;                              /**< Points to the underlying layer over which HAL is going to communicate */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams;                         /**< Pointer to the parameter structure of the keyStore layer. */

    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer;                                /**< Pointer to global transmit buffer used by the Exchange() function. */
    VAR(uint16, ANFCRL_VAR) wTxBufSize;                                /**< Size of the global transmit buffer. */
    VAR(uint16, ANFCRL_VAR) wTxBufLen;                                 /**< Number of valid bytes within the transmit buffer. */
    VAR(uint8, ANFCRL_VAR) wTxFwDataLen;
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer;                                /**< Pointer to global receive buffer used by the Exchange() function. */
    VAR(uint16, ANFCRL_VAR) wRxBufSize;                                /**< Size of the global receive buffer. */
    VAR(uint16, ANFCRL_VAR) wRxBufLen;                                 /**< Number of valid bytes within the receive buffer. */

    VAR(uint16, ANFCRL_VAR) wTxBufStartPos;                            /**< Starting position within the global transmit buffer (used if \b TxBuffer equals \b RxBuffer). */
    VAR(uint16, ANFCRL_VAR) wRxBufStartPos;                            /**< Starting position within the global receive buffer. */

    VAR(uint32, ANFCRL_VAR) dwTxWaitMs;                                /**< TxWaitMs shadow*/
    VAR(uint16, ANFCRL_VAR) dwFdtPc;                                   /**< Current timing value backup for PC*/

    VAR(uint16, ANFCRL_VAR) wFieldOffTime;                             /**< Field-Off-Time in milliseconds. */
    VAR(uint16, ANFCRL_VAR) wFieldRecoveryTime;                        /**< Field-Recovery-Time in milliseconds. */

    VAR(uint16, ANFCRL_VAR) wTargetMode;                               /**< Used to indicate the mode and speed at which Target is activated. Lower Byte indicates Speed and Higher Byte indicates Framing. */

    VAR(uint16, ANFCRL_VAR) wWakeupCounterInMs;                        /**<[In] Used value for wakeup counter in msecs, i.e. after this amount of time NCX3321 wakes up from standby. Maximum value is 2690. */

    VAR(uint16, ANFCRL_VAR) wLPCDWakeupCounterInMs;                    /**< Wakeup counter in msec for LPCD*/
    VAR(uint8, ANFCRL_VAR) bPollGuardTimeFlag;                         /**< Poll Guard Time Flag. */
    VAR(uint32, ANFCRL_VAR) wGuardTimeStart;                           /**< Start value of timer when start Poll Guard Time wait. */
    VAR(uint32, ANFCRL_VAR) wGuardTimePeriod;                          /**< Store Poll Guard Time period. */

    VAR(uint8, ANFCRL_VAR) bLpcdConfig;                                /**< LPCD Configuration to work in HW ULPCD or SW LPCD mode. */
    VAR(uint8, ANFCRL_VAR) bLpcdMode;                                  /**< LPCD Mode options either DEFAULT or POWERDOWN mode. */
    VAR(uint8, ANFCRL_VAR) bLpcdState;                                 /**< StateMachine for LPCD. */

    VAR(uint8, ANFCRL_VAR) bLpcdWakeUpCtrl;                            /**< Mask Controlling wake-up source for HW LPCD. */
    VAR(uint8, ANFCRL_VAR) bSymbolStart;                               /**< Preamble of a frame. */
    VAR(uint8, ANFCRL_VAR) bSymbolEnd;                                 /**< Trailer symbol of a frame. */
    VAR(uint8, ANFCRL_VAR) bRfResetAfterTo;                            /**< Storage for #PHHAL_HW_CONFIG_RFRESET_ON_TIMEOUT setting. */

    VAR(uint8, ANFCRL_VAR) bActiveMode;                                /**< Flag indicates whether Active mode is activated or not. */
    VAR(uint8, ANFCRL_VAR) bJewelActivated;                            /**< Set the PH_ON/PH_OFF Jewel exchange mode.*/
    VAR(uint8, ANFCRL_VAR) bCardType;                                  /**< Type of card for which the hal is configured for. */

    VAR(uint8, ANFCRL_VAR) bTimeoutUnit;                               /**< Unit of current timeout value (either #PHHAL_HW_TIME_MICROSECONDS or #PHHAL_HW_TIME_MILLISECONDS). */
    VAR(uint8, ANFCRL_VAR) bRxMultiple;                                /**< Flag indicates whether RX multiple is to be enabled  or not. */

    VAR(uint8, ANFCRL_VAR) bMfcCryptoEnabled;                          /**< Flag indicates whether the MFC Crypto is enabled or not. */
    VAR(uint8, ANFCRL_VAR) bCardMode;                                  /**< Flag indicates whether the SYSTEM_CONFIG_AUTOCOLL_STATE_A_MASK bit is set or not. */
#ifdef NXPBUILD__PHHAL_HW_NCX3321
    VAR(ppRFCallBck_t, ANFCRL_VAR) pRFISRCallback;                       /**< Application RF callback called by ISR handler. */
    VAR(ppTimerCallBck_t, ANFCRL_VAR) pTimerISRCallBack;                 /**< Guard timer callback called by ISR handler. */
    VAR(phTools_PollFunc_t, ANFCRL_VAR) pHalPollFunc;                    /**< Polling to check HAL's events . */
#endif
    VAR(uint8, ANFCRL_VAR) bOpeMode;                                   /**< Used to differentiate between EMVCO or Normal Mode of this layer */
    VAR(uint8, ANFCRL_VAR) bEmdFlag;                                   /**< Flag to Indicate Enable EMD Suppression*/
    VAR(uint32, ANFCRL_VAR) dwFelicaEmdReg;                            /**< FeliCa EMD configuration shadow register */

    VAR(uint16, ANFCRL_VAR) wCfgShadow[PHHAL_HW_NCX3321_SHADOW_COUNT];  /**< Configuration shadow; Stores configuration for current card type. */

    VAR(phTools_EventObj_t, ANFCRL_VAR) HwEventObj;                       /**< Handle for Event. */

    VAR(phIrqResp_t, ANFCRL_VAR) sIrqResp;                               /**< struct to be filled by ISR HAL Callback, contains minimal response read in ISR */

    VAR(uint8, ANFCRL_VAR) pInstrBuffer[INSTR_BUFFER_SIZE];            /**< Instruction buffer for forming single TLV command. */

    VAR(uint8, ANFCRL_VAR) bNonRF_Cmd;                                 /**< Command other then RF command*/

    VAR(uint8, ANFCRL_VAR) bExchAction;                                /**< Exchange action depend on Exchange option parameter*/

    VAR(uint8, ANFCRL_VAR) bCTSEvent;                                  /**< Flag indicating if CTS Event is received or not. */

    VAR(uint8, ANFCRL_VAR) bRFONEvent;                                 /**< Flag indicating if RF ON Event is received or not. */

    VAR(uint16, ANFCRL_VAR) wAdditionalInfo;                           /**< Storage for additional error information. */

    VAR(uint32, ANFCRL_VAR) dwEventStatus;                             /**< Storage for Event Status received as part of Event. */

    VAR(uint32, ANFCRL_VAR) dwGenError;                                /**< Storage for General Error received */

    VAR(uint32, ANFCRL_VAR) dwEventReceived;                           /**< Storage for Events received after previous operation. */

    VAR(uint32, ANFCRL_VAR) dwLpcdRefVal;                              /**< Storage for LPCD reference value received after LPCD calibration. */

    VAR(uint8, ANFCRL_VAR) bHFATTVal;                                  /**< Stores HFATT Value for ULPCD calibration and detection cycle. */

    VAR(uint8, ANFCRL_VAR) bNfcipMode;                                 /**< Enable/Disable to handle Start Byte at 106kbps in NFCIP-1 mode. */

    VAR(uint32, ANFCRL_VAR) dwExpectedEvent;                           /**< ExpectedEvent is used by Event Wait, to process cmd specific events. */

    VAR(phStatus_t, ANFCRL_VAR) wExchangeRfStatus;                     /**< Exchange RF status, that is used in PAL. */

    VAR(uint8, ANFCRL_VAR) bSendState;                                 /**< Non-Blocking Handle state for phhalHw_Ncx3321_Send */

    VAR(uint8, ANFCRL_VAR) bFieldResetState;                             /**< StateMachine For HWCommand Non-blocking processing handle */

    VAR(uint8, ANFCRL_VAR) bRegisterOpState;                             /**< StateMachine For Non-blocking register operations processing handle */

    VAR(uint8, ANFCRL_VAR) bSsTx1ConfigIsConfigured;                      /**< Indicate that value of CLIF_SS_TX1_RMCFG register has been configured */

    VAR(uint32, ANFCRL_VAR) dwSetSsTx1ConfigValue;                        /**< Storage for set CLIF_SS_TX1_RMCFG register value */

    VAR(uint8, ANFCRL_VAR) bSsTx2ConfigIsConfigured;                      /**< Indicate that value of CLIF_SS_TX2_RMCFG register has been configured */

    VAR(uint32, ANFCRL_VAR) dwSetSsTx2ConfigValue;                        /**< Storage for set CLIF_SS_TX2_RMCFG register value */

	} phhalHw_Ncx3321_DataParams_t;

/**
 * end of group phhalHw_Ncx3321 component : Ncx3321
 * @}
 */

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef NXPBUILD__PHHAL_HW

/** \addtogroup phhalHw Hardware Abstraction Layer
 * \brief These are the components which are used to abstract the
 * functionality of the physical reader device to a generic interface.
 *
 * HAL API usage in common use cases are described in the sequence diagrams below
 *
 * <strong>Reader mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple reader mode application.
 * \image html HAL_ReaderMode.png
 *
 * <strong>Passive initiator mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO 14443 Initiator in passive communication mode.
 * \image html HAL_passive_initiator.png
 *
 * <strong>Low power card detection(LPCD):</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO/IEC 14443-3a \n
 * reader that uses LPCD functionality of reader IC.
 * \image html HAL_Lpcd.png
 *
 * <strong>OSAL usage in HAL:</strong> This sequence diagram describes the usage of OS event
 * from within the HAL. \n
 * HAL uses OSAL call to wait for a CLIF event that is triggered by a CLIF interrupt.\n
 * \image html HAL_Osal.png
 *
 * @{
 */

/**
 * \brief HAL parameter structure
 */
typedef struct
{
#ifdef NXPBUILD__PHHAL_HW_NCx3320
  VAR(phhalHw_Ncx3320_DataParams_t, ANFCRL_VAR) sHal; /**< HAL component holder for Ncx3320. */
#endif /* NXPBUILD__PHHAL_HW_NCx3320*/
#ifdef NXPBUILD__PHHAL_HW_NCX3321
  VAR(phhalHw_Ncx3321_DataParams_t, ANFCRL_VAR) sHal; /**< HAL component holder for Ncx3321. */
#endif /* NXPBUILD__PHHAL_HW_NCX3321*/
} phhalHw_Nfc_Ic_DataParams_t;

/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* NXPBUILD__PHHAL_HW */
/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#ifdef NXPBUILD__PHHAL_HW_NCx3320

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

/**
 * \brief Initialize the HAL component.
 *
 * A note on <b>pLoadRegConfig</b>:\n
 * This is used if #PHHAL_HW_NCx3320_CONFIG_LOADREG_MODE is enabled.\n
 * It is defined as follows:
 \code
 Index (n*4 + 0U) 0 : EEPROM Register Address High
 Index (n*4 + 1U) 1 : EEPROM Register Address Low
 Index (n*4 + 2U) 2 : Register Address
 Index (n*4 + 3U) 3 : Number of Registers to be updated.
 \endcode
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3320_Init(P2VAR(phhalHw_Ncx3320_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
                VAR(uint16, ANFCRL_VAR) wSizeOfDataParams, /**< [In] Specifies the size of the data parameter structure. */
                P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams, /**< [In] Pointer to the lower layers parameter structure. */
                P2CONST(uint8, AUTOMATIC, ANFCRL_APPL_CONST) pLoadRegConfig, /**< [In] Pointer to configuration buffer for LoadReg mode; See description above. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, /**< [In] Pointer to global transmit buffer used by the phhalHw_Exchange() function. */
                VAR(uint16, ANFCRL_VAR) wTxBufSize, /**< [In] Size of the global transmit buffer. */
                P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, /**< [In] Pointer to global receive buffer used by the phhalHw_Exchange() function. */
                VAR(uint16, ANFCRL_VAR) wRxBufSize /**< [In] Size of the global receive buffer. Specify the buffer +1 byte, because one byte is reserved for SPI communication. */
								);

/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */

/** \addtogroup phhalHw_Ncx3320 component : Ncx3320
 * \ingroup phhalHw
 * \brief NCx3320 Reader HAL
 *
 * \b Note: This HAL takes care the "Request Guard Time".
 * \see phpalI14443p3a_RequestA
 * \see phpalI14443p3a_WakeUpA
 * @{
 */

#include "phhalHw_Ncx3320_Reg.h"
#include "phhalHw_Ncx3320_Cmd.h"

/**
 * end of group phhalHw_Ncx3320 component : Ncx3320
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW_NCx3320 */

#ifdef NXPBUILD__PHHAL_HW_NCX3321

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/**
 * \addtogroup phhalHw_Ncx3321 component : Ncx3321
 * \ingroup phhalHw
 * \brief Ncx3321 HAL component
 *
 * @{
 */

/**
 * \brief Initializes the NCX3321 HAL component.
 * This function has to be called as part of the initialization of the
 * HAL layer of the application that intends to use the PN517 as the reader
 * IC front end.
 */

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_Init(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,                /**<[In] Pointer to data parameter of this HAL layer */
    VAR(uint16, ANFCRL_VAR) wSizeOfDataParams,                               /**<[In] Size of the data parameter of the structure that was passed */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams,                                    /**<[In] Pointer to the lower layer parameter(BAL) structure */
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams,                               /**< [In] Pointer to the parameter structure of the keyStore layer. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,                                      /**<[In] Pointer to global transmit buffer that will be used by Exchange() */
    VAR(uint16, ANFCRL_VAR) wTxBufSize,                                      /**<[In] size of the global transmit buffer */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer,                                      /**<[In] Pointer to global receive buffer that will be used by Exchange() */
    VAR(uint16, ANFCRL_VAR) wRxBufSize                                       /**<[In] Size of the global receive buffer  */
    );

/**
 * \brief NCX3321 implementation of phhalHw_SetListenParameters
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Ncx3321_SetListenParameters(
    P2VAR(phhalHw_Ncx3321_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pSensRes,                         /**< [In] 2 bytes. */
    /** [In] 3 bytes; The first NfcId1 byte is fixed to \c 08h and the check byte is calculated automatically. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pNfcId1,
    VAR(uint8, ANFCRL_VAR) bSelRes,                            /**< [In] 1 byte. */
    /** [In] 2 bytes (shall be 01h, FEh) + 6 bytes NfcId2 + 8 bytes Pad + 2 bytes SystemCode. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pPollingResp,
    VAR(uint8, ANFCRL_VAR) bNfcId3                             /**< [In] 1 byte. */
    );

/**
 * end of group phhalHw_Ncx3321 component : Ncx3321
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif  /* NXPBUILD__PHHAL_HW_NCX3321 */

#ifdef NXPBUILD__PHHAL_HW

#define ANFCRL_START_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

/** \addtogroup phhalHw Hardware Abstraction Layer
 * \brief These are the components which are used to abstract the
 * functionality of the physical reader device to a generic interface.
 *
 * HAL API usage in common use cases are described in the sequence diagrams below
 *
 * <strong>Reader mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple reader mode application.
 * \image html HAL_ReaderMode.png
 *
 * <strong>Passive initiator mode:</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO 14443 Initiator in passive communication mode.
 * \image html HAL_passive_initiator.png
 *
 * <strong>Low power card detection(LPCD):</strong> This sequence diagram describes the usage of HAL APIs to
 * implement a simple ISO/IEC 14443-3a \n
 * reader that uses LPCD functionality of reader IC.
 * \image html HAL_Lpcd.png
 *
 * <strong>OSAL usage in HAL:</strong> This sequence diagram describes the usage of OS event
 * from within the HAL. \n
 * HAL uses OSAL call to wait for a CLIF event that is triggered by a CLIF interrupt.\n
 * \image html HAL_Osal.png
 *
 * @{
 */

/**
 * \brief Initialize the HAL component.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Nfc_IC_Init(
  P2VAR(phhalHw_Nfc_Ic_DataParams_t, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wSizeOfDataParams, /**< [In] Specifies the size of the data parameter structure. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pBalDataParams, /**< [In] Pointer to the lower layers parameter structure. */
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pKeyStoreDataParams, /**< [In] Pointer to configuration buffer for LoadReg mode; See description above. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, /**< [In] Pointer to global transmit buffer used by the phhalHw_Exchange() function. */
  VAR(uint16, ANFCRL_VAR) wTxBufSize, /**< [In] Size of the global transmit buffer. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pRxBuffer, /**< [In] Pointer to global receive buffer used by the phhalHw_Exchange() function. */
  VAR(uint16, ANFCRL_VAR) wRxBufSize /**< [In] Size of the global receive buffer. Specify the buffer +1 byte, because one byte is reserved for SPI communication. */
);

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Exchange_GetStatus(void);
#ifdef NXPBUILD__PHHAL_HW

/*
 * Below #defines remove the generic HAL interface file phhalHw.c from compiling there by
 * saving some code space.
 * This is enabled by defining NXPRDLIB_REM_GEN_INTFS in the project settings during compilation.
 */
#if defined  (NXPRDLIB_REM_GEN_INTFS) && \
    defined (NXPBUILD__PHHAL_HW_NCx3320)
#include "phhalHw_Ncx3320_Cmd.h"
#include "../comps/phhalHw/src/Ncx3320/phhalHw_Ncx3320.h"

#define phhalHw_Exchange(pDataParams ,wOption, pTxBuffer, wTxLength ,ppRxBuffer ,pRxLength) \
		phhalHw_Ncx3320_Exchange((phhalHw_Ncx3320_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phhalHw_ApplyProtocolSettings(pDataParams, bMode) \
		phhalHw_Ncx3320_ApplyProtocolSettings((phhalHw_Ncx3320_DataParams_t *)pDataParams, bMode)

#define phhalHw_DetectEMD(pDataParams) \
		phhalHw_Ncx3320_DetectEMD((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_SetConfig(pDataParams, wConfig, wValue) \
        phhalHw_Ncx3320_SetConfig((phhalHw_Ncx3320_DataParams_t *)pDataParams, wConfig, wValue)

#define phhalHw_GetConfig(pDataParams, wConfig, pValue) \
		phhalHw_Ncx3320_GetConfig((phhalHw_Ncx3320_DataParams_t *)pDataParams, wConfig, pValue)

#define phhalHw_FieldOn(pDataParams) \
		phhalHw_Ncx3320_FieldOn((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_FieldOff(pDataParams) \
		phhalHw_Ncx3320_FieldOff((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_FieldReset(pDataParams) \
		phhalHw_Ncx3320_FieldReset((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_Wait(pDataParams, bUnit, wTimeout) \
		phhalHw_Ncx3320_Wait((phhalHw_Ncx3320_DataParams_t *)pDataParams, bUnit, wTimeout)

#define phhalHw_Lpcd(pDataParams) \
		phhalHw_Ncx3320_Cmd_Lpcd((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_DeInit(pDataParams) \
		phhalHw_Ncx3320_DeInit((phhalHw_Ncx3320_DataParams_t *)pDataParams)

#define phhalHw_MfcAuthenticateKeyNo(pDataParams,bBlockNo,bKeyType,wKeyNo,wKeyVersion,pUid) \
			phhalHw_Ncx3320_MfcAuthenticateKeyNo((phhalHw_Ncx3320_DataParams_t *)pDataParams,bBlockNo,bKeyType,wKeyNo,wKeyVersion,pUid)

#define	phhalHw_MfcAuthenticate(pDataParams,bBlockNo,bKeyType,pKey,pUid) \
			phhalHw_Ncx3320_MfcAuthenticate((phhalHw_Ncx3320_DataParams_t *)pDataParams,bBlockNo,bKeyType,pKey,pUid)

#endif

#endif /* NXPBUILD__PHHAL_HW */

#if defined  (NXPRDLIB_REM_GEN_INTFS) && \
		defined (NXPBUILD__PHHAL_HW_NCX3321)
#include "../comps/phhalHw/src/Ncx3321/phhalHw_Ncx3321.h"

#define phhalHw_Exchange(pDataParams,wOption,pTxBuffer,wTxLength,ppRxBuffer,pRxLength) \
		phhalHw_Ncx3321_Exchange((phhalHw_Ncx3321_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength, ppRxBuffer, pRxLength)

#define phhalHw_ApplyProtocolSettings(pDataParams, bMode) \
		phhalHw_Ncx3321_ApplyProtocolSettings((phhalHw_Ncx3321_DataParams_t *)pDataParams, bMode)

#define phhalHw_SetConfig(pDataParams, wConfig, wValue) \
		phhalHw_Ncx3321_SetConfig((phhalHw_Ncx3321_DataParams_t *)pDataParams, wConfig, wValue)

#ifdef NXPBUILD__PHPAL_MIFARE_SW
#define phhalHw_MfcAuthenticateKeyNo(pDataParams, bBlockNo, bKeyType, wKeyNo, wKeyVersion,pUid) \
		phhalHw_Ncx3321_MfcAuthenticateKeyNo((phhalHw_Ncx3321_DataParams_t *)pDataParams,bBlockNo, bKeyType, wKeyNo, wKeyVersion, pUid)

#define phhalHw_MfcAuthenticate(  pDataParams, bBlockNo, bKeyType, pKey, pUid) \
		phhalHw_Ncx3321_MfcAuthenticate((phhalHw_Ncx3321_DataParams_t *)pDataParams,bBlockNo,bKeyType, pKey,pUid)
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

#define phhalHw_GetConfig(pDataParams, wConfig, pValue) \
		phhalHw_Ncx3321_GetConfig((phhalHw_Ncx3321_DataParams_t *)pDataParams, wConfig, pValue)

#define phhalHw_FieldOn(pDataParams) \
		phhalHw_Ncx3321_FieldOn((phhalHw_Ncx3321_DataParams_t *)pDataParams)

#define phhalHw_FieldOff(pDataParams) \
		phhalHw_Ncx3321_FieldOff((phhalHw_Ncx3321_DataParams_t *)pDataParams)

#define phhalHw_FieldReset(pDataParams) \
		phhalHw_Ncx3321_FieldReset((phhalHw_Ncx3321_DataParams_t *)pDataParams)

#define phhalHw_Wait(pDataParams, bUnit, wTimeout) \
		phhalHw_Ncx3321_Wait((phhalHw_Ncx3321_DataParams_t *)pDataParams, bUnit, wTimeout)

#define phhalHw_Transmit(pDataParams, wOption, pTxBuffer, wTxLength) \
		phhalHw_Ncx3321_Transmit((phhalHw_Ncx3321_DataParams_t *)pDataParams, wOption, pTxBuffer, wTxLength)

#define phhalHw_Receive(pDataParams, wOption, ppRxBuffer, pRxLength) \
		phhalHw_Ncx3321_Receive((phhalHw_Ncx3321_DataParams_t *)pDataParams, wOption, ppRxBuffer, pRxLength)

#define phhalHw_Lpcd(pDataParams) \
		phhalHw_Ncx3321_Lpcd((phhalHw_Ncx3321_DataParams_t *)pDataParams)
#if 0
#define phhalHw_AsyncAbort(pDataParams) \
		phhalHw_Ncx3321_AsyncAbort((phhalHw_Ncx3321_DataParams_t *)pDataParams)
#endif

#define phhalHw_Autocoll(pDataParams, wMode, ppRxBuffer, pRxLength, pProtParams) \
		phhalHw_Ncx3321_Autocoll((phhalHw_Ncx3321_DataParams_t *)pDataParams, wMode, ppRxBuffer,  pRxLength, pProtParams)

#define phhalHw_DeInit(pDataParams) \
		phhalHw_Ncx3321_DeInit((phhalHw_Ncx3321_DataParams_t *)pDataParams)
#if 0
#define phhalHw_EventWait(pDataParams, dwEventTimeout)  \
		phhalHw_Ncx3321_EventWait((phhalHw_Ncx3321_DataParams_t *)pDataParams, dwEventTimeout)

#define phhalHw_EventConsume(pDataParams)  \
		phhalHw_Ncx3321_EventConsume((phhalHw_Ncx3321_DataParams_t *) pDataParams)
#endif

#endif

#ifdef NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD
/**
 * \brief Perform Hybrid Low-Power-Card-Detection.
 *
 * It returns PH_ERR_SUCESSS until card presented.
 *
 * This feature is only available on NCx3320 currently
 *
 * This function runs at asynchronous mode.
 * Note: IC specific API has to be called to configure required parameters for LPCD before calling this function.
 * Example - phhalHw_Ncx3320_Cmd_Lpcd_SetConfig for NCx3320 has to be called to configure LPCD.
 *
 * A typical sequence in which this API is called is given below\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3320_Init();
 * \li HAL specific LPCD configuration - #phhalHw_Ncx3320_Cmd_Lpcd_SetConfig (pHal, bLPCD_MODE, I_Value, Q_Value, wPowerDownTimeMs, wDetectionTimeUs);
 * \li Start LPCD - #phhalHw_HybridLPCD (pHal); This blocks until a card comes in the field or due to disturbance in the field.
 * \li Upon LPCD return - #phhalHw_ApplyProtocolSettings (pHal, PHHAL_HW_CARDTYPE_ISO14443A);
 * \li Turn ON the field - phhalHw_FieldOn();
 * \li Wait for initial guard time - #phhalHw_Wait (pHal, 5100, PHHAL_HW_TIME_MICROSECONDS);
 * \li Start card activation and subsequent card read/write command exchanges.
 * \li Turn OFF the field - phhalHw_FieldOff();
 * \li Termination of the application flow.
 *
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Card present or after (phAppHybridLpcdCnt) times LPCP cycles
 * \retval #PH_STATUS_INPROCESS Waiting IRQ for event raise.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_HybridLPCD(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);
#endif /* NXPBUILD__PHHAL_HW_NCx3320_HYBRID_LPCD */

#ifndef NXPRDLIB_REM_GEN_INTFS /* Without optimization */
/**
 * \brief Perform data exchange with target/PICC in initiator/PCD mode.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * This is a non-blocking exchange for sending data function to be used by all PAL components of reader, initiator.
 * Frame step option unsupported for Jewel protocol. So it shall not be set using a SetConfig - #PHHAL_HW_CONFIG_JEWEL_MODE
 * It is recommended that the Tx Buffer pointer supplied to this function is word aligned (word alignment specific to the micro-controller platform where this is used)
 * This function runs at asynchronous mode, it shall not support BUFFERING options (PH_EXCHANGE_BUFFERED_BIT, PH_EXCHANGE_LEAVE_BUFFER_BIT) and Maximum Tx Buffer is 256 bytes.
 *
 * Before this function is called, it is expected that the user/upper layer has performed\n
 * \li BAL initialization (where applicable)
 * \li HAL initialization - Example phhalHw_Ncx3320_Init(); or phhalHw_Ncx3321_Init();
 * \li Load the protocol -  phhalHw_ApplyProtocolSettings()
 * \li Field ON          -  phhalHw_FieldOn(); or phhalHw_FieldReset()
 * \li Wait for initial guard time using phhalHw_Wait() in case phhalHw_FieldOn() was called earlier
 * \li Set or modify any configuration parameters using phhalHw_SetConfig()
 * \li Call phhalHw_Exchange() with relevant protocol command/data.
 *
 * \b wOption can be only:\n
 * \li #PH_EXCHANGE_DEFAULT
 *
 * Please refer to #PHHAL_HW_CONFIG_PARITY from where all the configuration parameters are defined that will
 * affect the behavior of this API.
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_INVALID_PARAMETER \b wOption is invalid.
 * \retval #PH_ERR_SUCCESS_INCOMPLETE_BYTE Operation successful, incomplete byte received; Retrieve number of valid bits of last byte with #PHHAL_HW_CONFIG_RXLASTBITS.
 * \retval #PH_ERR_IO_TIMEOUT No response detected within the configured time frame.
 * \retval #PH_ERR_INTEGRITY_ERROR Response received but CRC or parity is invalid.
 * \retval #PH_ERR_COLLISION_ERROR Response received but a collision occurred; Retrieve number of valid bits of last byte with #PHHAL_HW_CONFIG_RXLASTBITS.
 * \retval #PH_ERR_BUFFER_OVERFLOW Internal receive buffer is too small for transmission or smaller than the response.
 * \retval #PH_ERR_FRAMING_ERROR Frame format is either invalid for configured protocol or corrupted.
 * \retval #PH_ERR_PROTOCOL_ERROR Frame format is definitely invalid for configured protocol or received response by Type 1 Tag is less than 4 Bytes.
 * \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
 * \retval #PH_ERR_EXT_RF_ERROR External RF is ON during this exchange or if peer RF did not turn ON within Tadt in Active Mode.
 * \retval #PH_ERR_READ_WRITE_ERROR Hardware problem.
 * \retval #PH_ERR_TEMPERATURE_ERROR Hardware problem.
 * \retval #PH_ERR_INTERFACE_ERROR Hardware problem.
 * \retval #PH_ERR_INTERNAL_ERROR Unexpected Hardware problem or Software logic that should never be executed.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Exchange(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wOption, /**< [In] Option parameter, only value PH_EXCHANGE_DEFAULT accepted. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer, /**< [In] Data to transmit. */
  VAR(uint16, ANFCRL_VAR) wTxLength, /**< [In] Number of bytes to transmit. */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer, /**< [Out] Pointer to received data. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength /**< [Out] Number of received data bytes. */
);

/**
 * \brief phhalHw_Wait function waits/loops until the input time value is elapsed.\n
 *
 * This function is the same as #phhalHw_Wait (legacy version), but it only support for non-blocking mode.
 * It returns PH_ERR_SUCESSS until time value is elapsed.
 *
 * A typical sequence in which this API is called is given below\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init();
 * \li HAL initialization - Example phhalHw_Ncx3321_Init();
 * \li Load the protocol -  phhalHw_ApplyProtocolSettings();
 * \li Field ON          -  phhalHw_FieldOn();
 * \li Wait for initial guard time - #phhalHw_Wait (pHal, 5100, PHHAL_HW_TIME_MICROSECONDS);
 * \li Send/Receive protocol commands
 * \li Field Reset       - phhalHw_FieldReset();
 * \li Restart activation commands followed by other protocol commands.
 * \li Field OFF         - phhalHw_FieldOff();
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful. Raised event "no wait".
 * \retval #PH_STATUS_INPROCESS Waiting IRQ for event raise.
 * \retval #PH_ERR_INVALID_PARAMETER \b bUnit is invalid.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Wait(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint8, ANFCRL_VAR) bUnit, /**< [In] Unit of given timeout value (either #PHHAL_HW_TIME_MICROSECONDS or #PHHAL_HW_TIME_MILLISECONDS). */
  VAR(uint16, ANFCRL_VAR) wTimeout /**< [In] Timeout value. */
);

/**
* \brief Used to configure the IC to NFC target or card mode based on the configured option.
* Before calling this API \ref phhalHw_FieldOff API should be called.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* This is a blocking call that waits for reception of polling frames for the technologies mentioned in the wMode bit map and
* terminates with a response having command buffer received from an external reader/initiator.
* After target / PICC activation, the CRC is validated and removed before handing over the received
* frame to the caller.
* If target is activated in Active communication mode, then Auto RF-OFF is enabled by this API.
* The technologies mentioned in wMode or a combination of these depends on the hardware capability.\n
*
* Note: If #PHHAL_HW_CONFIG_MFHALTED configuration parameter is set then this function will only respond to WUPA/ALL_REQ.
*
* IC specific phhalHw_XXX_SetListenParameters API has to be called to configure the NFC Type A, Type B(Optional) and
* Type F responses in the IC before calling this function.
*
* The LSB and MSB of wMode has to be coded as follows.\n
* <pre>
*      | - - - - - - - - - - - - - - - - - - - - - - - -|
*  bit |  7 | 6 | 5 | 4 | 3 |   2    |   1     |   0    |
*      | - - - - - - - - - - - - - - - - - - - - - - - -|
*  Val |  x | x | x | x | x | Type F |  Type B | Type A |
*      | - - - - - - - - - - - - - - - - - - - - - - - -|
* </pre>
*
* The LSB codes target/PICC technology supported for NFC passive technology and MSB codes target/PICC technology supported for NFC active technology\n
*
*
* A typical sequence in which this API is called in a target/PICC use case is given below\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
* \li HAL initialization - Example phhalHw_Ncx3321_Init();
* \li HAL specific listen mode configuration - Example #phhalHw_Ncx3321_SetListenParameters (pHal, pSENS_RES, pNfcId1, bSelelctResponse, pFelicaResponse, bNfcId3);
* \li Field OFF         - phhalHw_FieldOff();
* \li Start target mode -  #phhalHw_Autocoll (pHal, 0x05, &pResponse, &wRxlen, &wProtParams);
* \li if (pResponse is valid ATR_REQ) then #phhalHw_Transmit (pHal, PH_EXCHANGE_DEFAULT, pATR_RES, wATR_len);
* \li Receive the next command - #phhalHw_Receive (pHal, 0x00, &pResponse, &wRxLen);
* \li Other response/command exchanges
* \li Termination of the target flow.
*
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_IO_TIMEOUT No response received.
* \retval #PH_ERR_EXT_RF_ERROR External RF was OFF when this API is called or switched OFF before active/passive activation.
* \retval #PH_ERR_PROTOCOL_ERROR Protocol error.
* \retval #PH_ERR_INTEGRITY_ERROR Response received but CRC or Parity is invalid.
* \retval #PH_ERR_BUFFER_OVERFLOW Internal receive buffer is too small for transmission or smaller than the response.
* \retval #PH_ERR_FRAMING_ERROR Frame format is either invalid for configured protocol or corrupted.
* \retval #PH_ERR_PROTOCOL_ERROR Frame format is definitely invalid for configured protocol.
* \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
* \retval #PH_ERR_READ_WRITE_ERROR Hardware problem.
* \retval #PH_ERR_TEMPERATURE_ERROR Hardware problem.
* \retval #PH_ERR_INTERFACE_ERROR Communication error.
* \retval #PH_ERR_UNSUPPORTED_COMMAND Target Mode is not supported by the Front End/Nfc Controller
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Autocoll(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wMode,         /**< [In] Bitmap of the modes that this will support in target/card emulation mode. */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,  /**< [Out] Pointer to received data after Activation. It can be an error frame or ATR_REQ/RATS. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength,   /**< [Out] Number of received data bytes. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pProtParams  /**< [Out] Contains frame mode in the MSB Byte and Rx speed information in the LSB Byte.
									   MSB value can be one of #PHHAL_HW_RF_TYPE_A_FRAMING, #PHHAL_HW_RF_TYPE_B_FRAMING, #PHHAL_HW_RF_TYPE_F_FRAMING.\n
									   LSB value can be one of #PHHAL_HW_RF_DATARATE_106, #PHHAL_HW_RF_DATARATE_212, #PHHAL_HW_RF_DATARATE_424, #PHHAL_HW_RF_DATARATE_848. */
);

/**
 * \brief Stop executing current Low-Power-Card-Detection mode.
 *
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting SwitchModeNormal to complete operation.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Stop_Lpcd(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Perform Low-Power-Card-Detection.
 *
 * This function is the same as #phhalHw_Lpcd (legacy version), but it only support for non-blocking mode.
 * It returns PH_ERR_SUCESSS until card presented.
 *
 * this function runs at asynchronous mode.
 * Note: IC specific API has to be called to configure required parameters for LPCD before calling this function.
 * Example - phhalHw_Ncx3320_Cmd_Lpcd_SetConfig for NCx3320 has to be called to configure LPCD.
 *
 * A typical sequence in which this API is called is given below\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3320_Init();
 * \li HAL specific LPCD configuration - #phhalHw_Ncx3320_Cmd_Lpcd_SetConfig (pHal, bLPCD_MODE, I_Value, Q_Value, wPowerDownTimeMs, wDetectionTimeUs);
 * \li Start LPCD - #phhalHw_Lpcd (pHal); This blocks until a card comes in the field or due to disturbance in the field.
 * \li Upon LPCD return - #phhalHw_ApplyProtocolSettings (pHal, PHHAL_HW_CARDTYPE_ISO14443A);
 * \li Turn ON the field - phhalHw_FieldOn();
 * \li Wait for initial guard time - #phhalHw_Wait (pHal, 5100, PHHAL_HW_TIME_MICROSECONDS);
 * \li Start card activation and subsequent card read/write command exchanges.
 * \li Turn OFF the field - phhalHw_FieldOff();
 * \li Termination of the application flow.
 *
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Card present.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ for event raise.
 * \retval #PH_ERR_IO_TIMEOUT No card found.
 * \retval Other Depending on implementation and underlying component.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Lpcd(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Configure reader IC for a particular reader/initiator protocol.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * Used to apply hardware settings for a particular protocol for reader, initiator modes.
 * Example: ISO 14443-3A, ISO 14443-3B, ISO 18092 initiator etc. For target or card emulation phhalHw_Autocoll
 * should be used. An IC specific configuration for setting antenna type before applying protocol settings
 * may be required during development phase and this should be managed by IC specific HALs.
 *
 *
 * \b bMode can be:\n
 * \li #PHHAL_HW_CARDTYPE_CURRENT
 * \li #PHHAL_HW_CARDTYPE_ISO14443A
 * \li #PHHAL_HW_CARDTYPE_ISO14443B
 * \li #PHHAL_HW_CARDTYPE_FELICA_212
 * \li #PHHAL_HW_CARDTYPE_ISO15693
 * \li #PHHAL_HW_CARDTYPE_FELICA_424
 *
 *
 * Before this function is called, it is expected that the user/upper layer has performed\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3321_Init();
 *
 * Only after calling this function, the RF field has to be turned ON
 * using phhalHw_FieldOn() or phhalHw_FieldReset()
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_INVALID_PARAMETER \b bCardType is invalid or not supported.
 * \retval #PH_ERR_INTERFACE_ERROR Hardware problem.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_ApplyProtocolSettings(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint8, ANFCRL_VAR) bMode /**< [In] Mode in which the IC hardware is to be configured. */
);

/**
 * \brief Adaptive EMD detection algorithm.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * In noisy environments, it is possible for the NCx3320 to mistake external disturber signals for actual data bytes.
 * This caused the original reader library to stay stuck in reception state. A algorithm have been developed to improve this situation.
 * It will be improvements in the behavior of the software. User can activate/deactivate it through a SetConfig call. The current state of the functionality (activated/deactivated) should be returned
 * using HAL GetConfig call
 *
 * Before this function is called, it is expected that the user/upper layer has performed\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3320_Init();
 * \li Apply Protocol
 * Calling this function after the RF field has to be turned ON
 * using phhalHw_FieldOn()
 *
 * Timeout should be configured. Default implementation has 10ms timeout.
 * The user should be able to define the new Threshold values in case of the presence of a disturber.
 * The user should be able to define the new Receiver gain values in case of the presence of a disturber
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_INVALID_PARAMETER \b is invalid parameter or not supported.
 * \retval #PH_ERR_INTERFACE_ERROR Hardware problem.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_DetectEMD(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Setup configuration parameter.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * All mandatory configuration parameters are to be implemented
 * to be compliant to generic HAL specification \n
 * Refer #PHHAL_HW_CONFIG_PARITY and subsequent configuration parameters that can be set using this API.
 *
 * This operation is performed by user application or upper layer to set/change the behavior of the
 * HAL APIs.
 * For example - To enable parity during phhalHw_Exchange(), \n
 * #phhalHw_SetConfig (pHal, PHHAL_HW_CONFIG_PARITY, PH_ON); needs to be called.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_UNSUPPORTED_PARAMETER Configuration is not supported or invalid.
 * \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
 * \retval #PH_ERR_PARAMETER_OVERFLOW Setting the parameter value would lead to an overflow.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_SetConfig(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wConfig, /**< [In] Configuration identifier. */
  VAR(uint16, ANFCRL_VAR) wValue /**< [In] Configuration value. */
);

/**
 * \brief Setup configuration of Multiple parameters.
 *
 * All mandatory configuration parameters are to be implemented
 * to be compliant to generic HAL specification \n
 * Refer #PHHAL_HW_CONFIG_PARITY and subsequent configuration parameters that can be set using this API.
 *
 * This operation is performed by user application or upper layer to set/change the behavior of the
 * HAL APIs.
 * For example - To apply multiple configuration, while configuring reader for RequestA() , \n
 * #phhalHw_SetConfigMultiple (pHal, NumOfConfigs, arryConfig[NumOfConfigs][NumOfConfigs]); needs to be called.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_UNSUPPORTED_PARAMETER Configuration is not supported or invalid.
 * \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
 * \retval #PH_ERR_PARAMETER_OVERFLOW Setting the parameter value would lead to an overflow.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */

FUNC(phStatus_t, ANFCRL_CODE) phhalHw_SetConfigMultiple(
	P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
	VAR(uint16, ANFCRL_VAR) wNumOfConfigs, /**< [In] No of Configuration identifier passed. */
	uint16 (*arr2dConfig)[PHHAL_HW_ARRY_COLUMNS_SIZE]/**< [In] Array Configuration identifier in form of key-value pair. */
);

/**
 * \brief Get configuration parameter.
 *
 * All mandatory configuration parameters are to be implemented
 * to be compliant to generic HAL specification. \n
 * Refer #PHHAL_HW_CONFIG_PARITY and subsequent configuration parameters whose value can be read using this API.
 *
 * This operation is performed by user application or upper layer to get the value of a configuration parameter
 * of the HAL.
 * For example - To get the number of last bits received during phhalHw_Exchange(), \n
 * #phhalHw_GetConfig (pHal, PHHAL_HW_CONFIG_RXLASTBITS, &wLastBits);  needs to be called.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_UNSUPPORTED_PARAMETER Configuration is not supported or invalid.
 * \retval #PH_ERR_INVALID_PARAMETER Parameter value is invalid.
 * \retval #PH_ERR_PARAMETER_OVERFLOW The parameter value is larger than the range of \b pValue.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_GetConfig(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wConfig, /**< [In] Configuration identifier. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pValue /**< [Out] Configuration value. */
);

/**
 * \brief Switch ON the RF-field.
 *
 * This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
 * This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
 *
 * If the configuration parameter #PHHAL_HW_CONFIG_RFCA is set, it performs
 * initial RF collision avoidance(I-RFCA) in initiator/reader mode before switching ON the field.\n
 * If parameter #PHHAL_HW_CONFIG_RFCA is not set, field ON is done without performing RFCA.\n
 *
 * This API shall be called only after \ref phhalHw_ApplyProtocolSettings.
 * An example sequence is given below \n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3321_Init();
 * \li Load the protocol -  #phhalHw_ApplyProtocolSettings ();
 * \li Field ON          -  phhalHw_FieldOn();
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 * \retval #PH_ERR_RF_ERROR External RF is detected during RF Collision avoidance when RFCA is enabled.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldOn(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Switch off the RF-field.
 *
 * If this API is called when communication mode is "active initiator",
 * this will reset the Auto-RF OFF behavior of the active initiator mode\n
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldOff(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Used to asynchronously stop HAL waiting for RF event and exit from HAL.
 *
 * Note: This function will post an 'abort' event which is used by the HAL to move into 'Idle' state and exit from polling for RF Event.
 * The functions that were waiting for a HAL event will return #PH_ERR_ABORTED error code once this function is executed.
 *
 * This function shall be called in a task other than the task where reader library is running.
 * This API can be called at any time after the HAL has been initialized and any of the HAL operations like transmit, receive, exchange,
 * autocoll are in progress.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_AsyncAbort(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Perform RF-Reset.
 *
 * Switches OFF, waits for a configured time, and then turns the RF back to ON.\n
 * This is expected to retain the protocol settings that were applied before calling this function.
 * The time to wait before RF ON is configured using a SetConfig call.
 *
 * #PHHAL_HW_CONFIG_FIELD_OFF_TIME (in milliseconds) can be set to a particular value
 * to keep the field OFF for the configured time value before turning it ON.
 *
 * #PHHAL_HW_CONFIG_FIELD_RECOVERY_TIME (in milliseconds) can be set to a particular value
 * to wait for RF recovery time after field is switched ON.
 *
 * A typical sequence in which this API is called is given below\n
 * \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
 * \li HAL initialization - Example phhalHw_Ncx3321_Init();
 * \li Load the protocol -  phhalHw_ApplyProtocolSettings();
 * \li Field ON          -  phhalHw_FieldOn();
 * \li Wait for initial guard time - phhalHw_Wait();
 * \li Send/Receive protocol commands
 * \li Field reset       - phhalHw_FieldReset();
 * \li Restart activation commands followed by other protocol commands.
 * \li Field OFF         - phhalHw_FieldOff();
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_INTERFACE_ERROR Communication error.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_FieldReset(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

/**
 * \brief Used to wait any event generate in Hal.
 *
 * This is a blocking call that waits for any event generated in Hal.
 * Except in No Rtos case, the tread will be suspended and will be resumed if any event is generated.
 *
 * Before calling this function, the interrupt have to enabled.
 *
 * A typical sequence in which this API is called is given below\n
 * \li BAL initialization (where applicable)     - Example   - phPlatform_Init();
 * \li Field OFF                                 - Example   - phhalHw_FieldOff();
 * \li Consume all the Hal events                            - phhalHw_EventConsume()
 * \li Set Config to wait for external Rf On.    - Example   - phhalHw_SetConfig(); for PHHAL_HW_CONFIG_RFON_INTERRUPT
 * \li Event Wait.                                           - phhalHw_EventWait();
 * \li Set Config OFF for external Rf On.        - Example   - phhalHw_SetConfig(); for PHHAL_HW_CONFIG_RFON_INTERRUPT
 * \li Proceed further according to the Interrupt enabled.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 * \retval #PH_ERR_IO_TIMEOUT No Event generated
 * \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
 * \retval #PH_ERR_INVALID_DATA_PARAMS Parameter structure size is invalid.
 * \retval #PH_ERR_UNSUPPORTED_COMMAND Command not supported.
 * \retval #PH_ERR_INVALID_PARAMETER Invalid handle for events is provided.
 */
#if 0
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_EventWait(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams, /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint32, ANFCRL_VAR) dwEventTimeout /**< [In] Timeout for Event in milliseconds. */
);
#endif

/**
* \brief Used to transmit data. This is a generic transmit-only function that can be used in initiator/PCD and target modes.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* In the initiator/reader mode, the FWT timer starts after last bit transmitted to handle timeout and
* is automatically stopped after first bit is received in a phhalHw_Receive() function call.
*
* Note: <em>Special behavior:</em> To use phhalHw_Transmit API in target mode \ref phhalHw_Autocoll
* API shall be executed before.
*
* \b wOption can be one of:\n
* \li #PH_TRANSMIT_DEFAULT
* \li #PH_TRANSMIT_PREV_FRAME
*
* \b If wOption can be combined with:\n
* \li #PH_TRANSMIT_BUFFERED_BIT
* \li #PH_TRANSMIT_LEAVE_BUFFER_BIT
*
* NOTE : #PH_TRANSMIT_PREV_FRAME cannot be combined with any of the buffering options above.
*
* A typical sequence in which this API is called in initiator mode is given below\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init();
* \li HAL initialization - Example phhalHw_Ncx3321_Init();
* \li Load the protocol -  phhalHw_ApplyProtocolSettings();
* \li Field ON          -  phhalHw_FieldOn();
* \li Wait for initial guard time - #phhalHw_Wait (pHal, 5100, PHHAL_HW_TIME_MICROSECONDS);
* \li Transmit the ATR_REQ - #phhalHw_Transmit (pHal, PH_EXCHANGE_DEFAULT, pATR_REQ, wATR_len);
* \li Receive the response - #phhalHw_Receive (pHal, 0x00, &pResponse, &wRxLen);
* \li Other command exchanges
* \li Field OFF         - phhalHw_FieldOff();
*
* A typical sequence in which this API is called in target/PICC mode is given below\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
* \li HAL initialization - Example phhalHw_Ncx3321_Init();
* \li HAL specific listen mode configuration - Example #phhalHw_Ncx3321_SetListenParameters (pHal, pSENS_RES, pNfcId1, bSelelctResponse, pFelicaResponse, bNfcId3);
* \li Start target mode -  #phhalHw_Autocoll (pHal, 0x05, &pResponse, &wRxlen, &wProtParams);
* \li if (pResponse is valid ATR_REQ) then #phhalHw_Transmit (pHal, PH_TRANSMIT_DEFAULT, pATR_RES, wATR_len);
* \li Receive the response - #phhalHw_Receive (pHal, 0x00, &pResponse, &wRxLen);
* \li Other response/command exchanges
* \li Termination of the target flow.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_INVALID_PARAMETER wOption parameter is invalid.
* \retval #PH_ERR_INTERFACE_ERROR Communication error.
* \retval #PH_ERR_EXT_RF_ERROR In active mode if External RF is present during this transmit or in passive target mode
*                              if external field is not present before initiating this transmit.
* \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
* \retval #PH_ERR_INTERNAL_ERROR If transmission was not successful due to some Hardware or Memory alignment issues.
* \retval #PH_ERR_BUFFER_OVERFLOW If the buffer provided by PAL or Application to HAL exceeds the HAL Tx Buffer and other
                                  platform specific reasons.
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Transmit(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,   /**< [In] Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wOption,     /**< [In] Option parameter. */
  P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pTxBuffer,  /**< [In] Data to transmit. */
  VAR(uint16, ANFCRL_VAR) wTxLength    /**< [In] Number of bytes to transmit. */
	);

/**
* \brief Used to receive data. Can be used in initiator/PCD and target/PICC Modes.
*
* This is a part (an API) of non-blocking mechanism designed for Automotive Environment.
* This function runs at asynchronous mode. It returns PH_STATUS_INPROCESS when operation is not completed.
*
* Note: <em>Special behavior:</em> To use phhalHw_Receive API in target Mode, phhalHw_Autocoll API shall be executed
* previously. In target mode this API will wait for receive interrupt or external RF OFF interrupt (in case of passive mode).
*
* \b wOption is RFU and should be set to 0x00
*
* A typical sequence in which this API is called in initiator mode is given below\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
* \li HAL initialization - Example phhalHw_Ncx3321_Init();
* \li Load the protocol -  phhalHw_ApplyProtocolSettings();
* \li Field ON          -  phhalHw_FieldOn()
* \li Wait for initial guard time - #phhalHw_Wait (pHal, 5100, PHHAL_HW_TIME_MICROSECONDS);
* \li Transmit the ATR_REQ - #phhalHw_Transmit (pHal, PH_EXCHANGE_DEFAULT, pATR_REQ, wATR_len);
* \li Receive the response - #phhalHw_Receive (pHal, 0x00, &pResponse, &wRxLen);
* \li Other command exchanges
* \li Field OFF         - phhalHw_FieldOff();
*
* A typical sequence in which this API is called in target/PICC mode is given below\n
* \li BAL initialization (where applicable) - Example - phbalReg_Serial_Init()
* \li HAL initialization - Example phhalHw_Ncx3321_Init();
* \li HAL specific listen mode configuration - Example #phhalHw_Ncx3321_SetListenParameters (pHal, pSENS_RES, pNfcId1, bSelelctResponse, pFelicaResponse, bNfcId3);
* \li Start target mode -  #phhalHw_Autocoll (pHal, 0x05, &pResponse, &wRxlen, &wProtParams);
* \li if (pResponse is valid RATS) then #phhalHw_Transmit (pHal, PH_EXCHANGE_DEFAULT, pATS, wATS_len);
* \li Receive the response - #phhalHw_Receive (pHal, 0x00, &pResponse, &wRxLen);
* \li Other response/command exchanges
* \li Termination of the target flow.
*
* \return Status code
* \retval #PH_ERR_SUCCESS Operation successful.
* \retval #PH_STATUS_INPROCESS Waiting IRQ to complete operation.
* \retval #PH_ERR_INVALID_PARAMETER The option provided is invalid.
* \retval #PH_ERR_IO_TIMEOUT No response detected within the configured time frame.
* \retval #PH_ERR_INTEGRITY_ERROR Response received but CRC or parity is invalid.
* \retval #PH_ERR_COLLISION_ERROR Response received but a collision occurred; Retrieve number of valid bits of last byte
*                                 with #PHHAL_HW_CONFIG_RXLASTBITS.
* \retval #PH_ERR_BUFFER_OVERFLOW Internal receive buffer is smaller than the received response.
* \retval #PH_ERR_FRAMING_ERROR Frame format is either invalid for configured protocol or corrupted.
* \retval #PH_ERR_PROTOCOL_ERROR Frame format is definitely invalid for configured protocol.
* \retval #PH_ERR_ABORTED Returned when this API exits after phhalHw_AsyncAbort API is called from another thread.
* \retval #PH_ERR_EXT_RF_ERROR In passive target mode, external reader/initiator switched OFF its field before/during reception
*                              or if peer RF did not turn ON within Tadt in Active Mode.
* \retval #PH_ERR_READ_WRITE_ERROR Hardware problem.
* \retval #PH_ERR_TEMPERATURE_ERROR Hardware problem.
* \retval #PH_ERR_INTERFACE_ERROR Communication error.
* \retval #PH_ERR_INTERNAL_ERROR Unexpected Hardware problem (like in active mode if modem state is WAIT_RECIEVE but the internal RF field is ON).
*/
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_Receive(
  P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,     /**< [In]  Pointer to this layer's parameter structure. */
  VAR(uint16, ANFCRL_VAR) wOption,       /**< [In]  Option parameter. RFU. Should be set to 0x00. */
  P2VAR(uint8*, AUTOMATIC, ANFCRL_APPL_DATA) ppRxBuffer,  /**< [Out] Pointer to received data. */
  P2VAR(uint16, AUTOMATIC, ANFCRL_APPL_DATA) pRxLength    /**< [Out] Number of received data bytes. */
	);

/**
 * \brief De-initializes the contactless IC HAL.
 *
 * Note: This API resets the HAL context data.
 * The Tx and Rx buffers are made invalid
 * The connection to BAL is made invalid
 * All contactless IP interrupts are disabled.
 * No other HAL APIs can be called after de-initializing the HAL till the phhalHw_<IC>_Init() function is called.
 *
 * This API shall be called during the application termination sequence to de-initialize the HAL.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_DeInit(P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams /**< [In] Pointer to this layer's parameter structure. */
);

#ifdef NXPBUILD__PHPAL_MIFARE_SW
/**
 * \brief Mifare Authenticate command by KeyNo from KeyStore.
 *
 *
 * This API shall be called to authenticate with PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_MfcAuthenticateKeyNo(
    void* pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,               /**< [In] Block Number. */
    VAR(uint8, ANFCRL_VAR) bKeyType,               /**< [In] Key Type. */
    VAR(uint16, ANFCRL_VAR) wKeyNo,                /**< [In] Key Number. */
    VAR(uint16, ANFCRL_VAR) wKeyVersion,           /**< [In] Key Version. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                  /**< [In] Uid; uint8[4]. */
    );

/**
 * \brief Mifare Authenticate command by pKey.
 *
 *
 * This API shall be called to authenticate with PICC.
 *
 * \return Status code
 * \retval #PH_ERR_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phhalHw_MfcAuthenticate(
    P2VAR(void, AUTOMATIC, ANFCRL_APPL_DATA) pDataParams,              /**< [In] Pointer to this layer's parameter structure. */
    VAR(uint8, ANFCRL_VAR) bBlockNo,                /**< [In] Block Number. */
    VAR(uint8, ANFCRL_VAR) bKeyType,                /**< [In] Key Type. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pKey,                  /**< [In] Key. */
    P2VAR(uint8, AUTOMATIC, ANFCRL_APPL_DATA) pUid                   /**< [In] Uid; uint8[4]. */
    );
#endif /*NXPBUILD__PHPAL_MIFARE_SW*/

/**
 * end of group phhalHw Hardware Abstraction Layer
 * @}
 */
#endif /* Without optimization */

#define ANFCRL_STOP_SEC_CODE
#if ((PHHALHW_AR_RELEASE_MAJOR_VERSION == 4) && (PHHALHW_AR_RELEASE_MINOR_VERSION == 0))
 #include <MemMap.h>
#else
 #include <AnfcRL_MemMap.h>
#endif

#endif /* NXPBUILD__PHHAL_HW */

#ifdef __cplusplus
}
#endif
#endif /* PHHALHW_H */
