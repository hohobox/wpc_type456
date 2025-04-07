/*******************************************************************************
 * (c) NXP Semiconductors Bangalore / India
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
  /**
*   @file    phDriver2.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Driver - DAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phDriver2 Driver Abstraction Layer (DAL)
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
#ifndef PHDRIVER2_H
#define PHDRIVER2_H

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/

#ifdef linux
#include <sys/types.h>
#endif

#if defined (PH_TYPEDEFS2_H)
#else /*PH_TYPEDEFS2_H*/

#if defined(__GNUC__ ) /* Toolchain with StdInt */
#    include <stdint.h>
#elif defined(__ICCARM__)
#   include "intrinsics.h"
#   include <stdint.h>
#elif defined(__CC_ARM)
#   include <stdint.h>
#endif

#endif /*PH_TYPEDEFS2_H*/
#include <CDD_AnfcRL_Cfg.h>
#include "phbalReg2.h"
#include "phDriver_Gpio2.h"
#include "phDriver_Timer2.h"
#include <ph_RefDefs2.h>

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
/**
* @file           phDriver2.h
* @implements     DESIGN001, DESIGN002
*/
#define PHDRIVER_VENDOR_ID2                    43           /**< @brief AUTOSAR vendor ID*/
#define PHDRIVER_MODULE_ID2                    255          /**< @brief AUTOSAR module ID*/
#define PHDRIVER_AR_RELEASE_MAJOR_VERSION2     4            /**< @brief AUTOSAR release major version*/
#define PHDRIVER_AR_RELEASE_MINOR_VERSION2     3            /**< @brief AUTOSAR release minor version*/
#define PHDRIVER_AR_RELEASE_REVISION_VERSION2  1            /**< @brief AUTOSAR release revision*/
#define PHDRIVER_SW_MAJOR_VERSION2             1            /**< @brief The major version of the SW module*/
#define PHDRIVER_SW_MINOR_VERSION2             0            /**< @brief The minor version of the SW module*/
#define PHDRIVER_SW_PATCH_VERSION2             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHDRIVER_VENDOR_ID2 != ANFCRL_CFG_VENDOR_ID)
    #error "phDriver2.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHDRIVER_AR_RELEASE_MAJOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHDRIVER_AR_RELEASE_MINOR_VERSION2    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHDRIVER_AR_RELEASE_REVISION_VERSION2 != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phDriver2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHDRIVER_SW_MAJOR_VERSION2 != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHDRIVER_SW_MINOR_VERSION2 != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHDRIVER_SW_PATCH_VERSION2 != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phDriver2.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** \defgroup phDriver2 Driver Abstraction Layer (DAL)
 *
 * \brief This component implements hardware drivers that are necessary for RdLib software modules
 * @{
 */
#ifndef  PH_STATUS2_H
/**
 * \brief phStatus_t2 is a signed short value, using the positive range.
 *
 * High byte: Category (group) Identifier.\n
 * Low byte : Error Specifier.
 */
#define PH_COMP_DRIVER2              0xF100U /**< DRIVER component code. */
#define PH_COMP_MASK2                0xFF00U /**< Component Mask for status code and component ID. */
#define PH_COMPID_MASK2              0x00FFU /**< ID Mask for component ID. */
#define PH_ERR_MASK2                 0x00FFU /**< Error Mask for status code. */
#define PH_COMP_GENERIC2             0x0000U /**< Generic Component Code. */

#endif
/*!
 \brief Generic Status codes

 All functions within the phDriver2 use these macro values as return codes.
 */
#define PH_DRIVER_SUCCESS2                 0x0000U /**< Function executed successfully. */
#define PH_DRIVER_TIMEOUT2                 0x0001U /**< No reply received, e.g. PICC removal. */
#define PH_DRIVER_ABORTED2                 0x0012U /**< Used when HAL ShutDown is called. */
#define PH_DRIVER_ERROR2                   0x0080U /**< Invalid Parameter, buffer overflow  or other configuration error. */
#define PH_DRIVER_FAILURE2                 0x0081U /**< Failed to perform the requested operation. */

/****************
 * Uncomment this Macro to drive SSEL pin by software
 * Used in case: Platform's SPI can't keep SSEL is active during transfer multiple 8-bit frame
 ************* */
/*#define PHDRIVER_SOFT_SSEL2*/

/******************************************************************
 * PIN Pull-Up/Pull-Down configurations.
 ******************************************************************/
#ifdef AUTOSAR_VER
#ifdef ANFCRL_HAL_HW_DEVICE_NCX3321
#define PHDRIVER_PIN_RESET_PULL_CFG2    PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_IRQ_PULL_CFG2      PH_DRIVER_PULL_DOWN2
#define PHDRIVER_PIN_NSS_PULL_CFG2      PH_DRIVER_PULL_UP2

#define PHDRIVER_PIN_WKUP_PULL_CFG2     PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_CLK_PULL_CFG2      PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_DWL_PULL_CFG2      PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_BUSY_PULL_CFG2     PH_DRIVER_PULL_UP2
#endif
#ifdef ANFCRL_HAL_HW_DEVICE_NCX3320
#define PHDRIVER_PIN_RESET_PULL_CFG2    PH_DRIVER_PULL_DOWN2
#define PHDRIVER_PIN_IRQ_PULL_CFG2      PH_DRIVER_PULL_UP2
#define PHDRIVER_PIN_NSS_PULL_CFG2      PH_DRIVER_PULL_UP2
#endif

/******************************************************************
 * IRQ PIN NVIC settings
 ******************************************************************/
#ifdef ANFCRL_HAL_HW_DEVICE_NCX3321
#define PIN_IRQ_TRIGGER_TYPE2      IRQ_TRIGGER_TYPE_RISINGEDGE2
#endif
#ifdef ANFCRL_HAL_HW_DEVICE_NCX3320
#define PIN_IRQ_TRIGGER_TYPE2      IRQ_TRIGGER_TYPE_FALLINGEDGE2   /*MISRA rule 20.9 line 470 phhalHw_Ncx3320_Int.h*/
#endif
/*****************************************************************
 * Front End Reset logic level settings
 ****************************************************************/
#define PH_DRIVER_SET_HIGH2            1u          /**< Logic High. */
#define PH_DRIVER_SET_LOW2             0u          /**< Logic Low. */

#ifdef ANFCRL_HAL_HW_DEVICE_NCX3321
#define RESET_POWERDOWN_LEVEL2         PH_DRIVER_SET_LOW2
#define RESET_POWERUP_LEVEL2           PH_DRIVER_SET_HIGH2
#endif
#ifdef ANFCRL_HAL_HW_DEVICE_NCX3320
#define RESET_POWERDOWN_LEVEL2         PH_DRIVER_SET_HIGH2
#define RESET_POWERUP_LEVEL2           PH_DRIVER_SET_LOW2
#endif

/*!
 \brief IRQ Properties
 IRQ Line level .
 */
#define PIN_IRQ_IDLE_HIGH2               PH_DRIVER_SET_HIGH2
#define PIN_IRQ_IDLE_LOW2                PH_DRIVER_SET_LOW2

#define IRQ_TRIGGER_TYPE_RISINGEDGE2     3U
#define IRQ_TRIGGER_TYPE_FALLINGEDGE2    4U
#endif /* AUTOSAR_VER*/

/*!
 \brief IRQ Signal value
 */
#if (PIN_IRQ_TRIGGER_TYPE2 == IRQ_TRIGGER_TYPE_RISINGEDGE2)
	#define PH_DRIVER_PIN_IRQ_ACTIVE2 		1u
	#define PH_DRIVER_PIN_IRQ_IDLE2 			0u
#elif (PIN_IRQ_TRIGGER_TYPE2 == IRQ_TRIGGER_TYPE_FALLINGEDGE2)
	#define PH_DRIVER_PIN_IRQ_ACTIVE2 		0u
	#define PH_DRIVER_PIN_IRQ_IDLE2 			1u
#else
	#error "Invalid combination"
#endif /* PIN_IRQ_TRIGGER_TYPE2 */

/**
 * end of group phDriver2 Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** \defgroup phDriver2 Driver Abstraction Layer (DAL)
 *
 * \brief This component implements hardware drivers that are necessary for RdLib software modules
 * @{
 */

#if defined (PH_TYPEDEFS2_H)
#else /*PH_TYPEDEFS2_H*/
/** \name Floating-Point Types
 */
/*@{*/
#ifndef __float32_t_defined
/**
 * \brief 32 bit floating point
 */
typedef float float32_t;
#endif
/*@}*/

#endif /*PH_TYPEDEFS2_H*/

#ifndef  PH_STATUS2_H
/**
 * \brief phStatus_t2 is a signed short value, using the positive range.
 *
 * High byte: Category (group) Identifier.\n
 * Low byte : Error Specifier.
 */
typedef VAR(uint16, ANFCRL_VAR) phStatus_t2;
#endif

/**
 * end of group phDriver2 Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/


#ifdef __cplusplus
}
#endif
#endif /* PHDRIVER2_H */
