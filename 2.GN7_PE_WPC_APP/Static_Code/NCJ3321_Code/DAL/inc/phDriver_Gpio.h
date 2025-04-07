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
*   @file    phDriver_Gpio.h
*   @version 1.0.0
*
*   @brief   AUTOSAR Driver_Gpio - DAL API usage in common use cases.
*   @details Functions need to be implemented by application code.
*
*   @addtogroup phDriver Driver Abstraction Layer (DAL)
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
#ifndef PHDRIVER_GPIO_H
#define PHDRIVER_GPIO_H

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
* @file           phDriver_Gpio.h
* @implements     DESIGN001, DESIGN002
*/
#define PHDRIVER_GPIO_VENDOR_ID                    43           /**< @brief AUTOSAR vendor ID*/
#define PHDRIVER_GPIO_MODULE_ID                    255          /**< @brief AUTOSAR module ID*/
#define PHDRIVER_GPIO_AR_RELEASE_MAJOR_VERSION     4            /**< @brief AUTOSAR release major version*/
#define PHDRIVER_GPIO_AR_RELEASE_MINOR_VERSION     3            /**< @brief AUTOSAR release minor version*/
#define PHDRIVER_GPIO_AR_RELEASE_REVISION_VERSION  1            /**< @brief AUTOSAR release revision*/
#define PHDRIVER_GPIO_SW_MAJOR_VERSION             1            /**< @brief The major version of the SW module*/
#define PHDRIVER_GPIO_SW_MINOR_VERSION             0            /**< @brief The minor version of the SW module*/
#define PHDRIVER_GPIO_SW_PATCH_VERSION             0            /**< @brief The patch version of the SW module*/

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same vendor */
#if (PHDRIVER_GPIO_VENDOR_ID != ANFCRL_CFG_VENDOR_ID)
    #error "phDriver_Gpio.h and CDD_AnfcRL_Cfg.h have different vendor ids"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same Autosar version */
#if ((PHDRIVER_GPIO_AR_RELEASE_MAJOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MAJOR_VERSION) || \
    (PHDRIVER_GPIO_AR_RELEASE_MINOR_VERSION    != ANFCRL_CFG_AR_RELEASE_MINOR_VERSION) || \
    (PHDRIVER_GPIO_AR_RELEASE_REVISION_VERSION != ANFCRL_CFG_AR_RELEASE_REVISION_VERSION))
    #error "AutoSar Version Numbers of phDriver_Gpio.h and CDD_AnfcRL_Cfg.h are different"
#endif
/* Check if current file and CDD_AnfcRL_Cfg.h header file are of the same software version */
#if ((PHDRIVER_GPIO_SW_MAJOR_VERSION != ANFCRL_CFG_SW_MAJOR_VERSION) || \
    (PHDRIVER_GPIO_SW_MINOR_VERSION != ANFCRL_CFG_SW_MINOR_VERSION) || \
    (PHDRIVER_GPIO_SW_PATCH_VERSION != ANFCRL_CFG_SW_PATCH_VERSION))
    #error "Software Version Numbers of phDriver_Gpio.h and CDD_AnfcRL_Cfg.h are different"
#endif
/** @} */
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/*!
  \brief Pin pull-up and pull-down settings
*/
#define PH_DRIVER_PULL_DOWN                   0x00U /**< Pull-down selected. */
#define PH_DRIVER_PULL_UP                     0x01U /**< Pull-up selected. */

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/**
* \brief Port/GPIO PIN functionality.
*/
typedef enum{
    PH_DRIVER_PINFUNC_INPUT = 0x01u,        /**< Input pinpad. */
    PH_DRIVER_PINFUNC_OUTPUT,              /**< Output pinpad. */
    PH_DRIVER_PINFUNC_BIDIR,               /**< Bidirectional pinpad. */
    PH_DRIVER_PINFUNC_INTERRUPT            /**< Interrupt pin. */
} phDriver_Pin_Func_t;

/**
* \brief PIN Interrupt configuration.
*/
typedef enum{
    PH_DRIVER_INTERRUPT_LEVELZERO = 0x01u,   /**< Interrupt when level zero. */
    PH_DRIVER_INTERRUPT_LEVELONE,           /**< Interrupt when level one. */
    PH_DRIVER_INTERRUPT_RISINGEDGE,         /**< Interrupt on rising edge. */
    PH_DRIVER_INTERRUPT_FALLINGEDGE,        /**< Interrupt on falling edge. */
    PH_DRIVER_INTERRUPT_EITHEREDGE         /**< Interrupt on either edge. */
} phDriver_Interrupt_Config_t;

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/

/**
*
* \brief Interrupt callback interface which will be called when interrupt is triggered on IRQ Pin.
* \retval  None
*/
typedef void (*pphDriver_InterruptCallBck_t)(void);

/**
* \brief Port/GPIO PIN configuration.
*/
typedef struct{
    VAR(uint8, ANFCRL_VAR) bPullSelect; /**< PH_DRIVER_PULL_DOWN for pull-down, PH_DRIVER_PULL_UP for pull-up selection. */
    VAR(uint8, ANFCRL_VAR) bOutputLogic; /**< Set default output logic either 1 or 0, used in case of output. */
    VAR(phDriver_Interrupt_Config_t, ANFCRL_VAR) eInterruptConfig;    /**< Interrupt Pin configuration. */
} phDriver_Pin_Config_t;

/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/
#define ANFCRL_START_SEC_CODE
#if ((PHDRIVER_GPIO_AR_RELEASE_MAJOR_VERSION == 4) && (PHDRIVER_GPIO_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

/** \defgroup phDriver Driver Abstraction Layer (DAL)
*
* \brief This component implements hardware drivers that are necessary for RdLib software modules
* @{
*/
/********************************************************************************
 * PORT/GPIO PIN API's
 *******************************************************************************/

/**
 * \brief Configures the Gpio/Port pin for the specified configuration.
 *
 * @param[in] dwPinNumber  Gpio/Port pin number that needs to be configured.
 * @param[in] ePinFunc     Whether Gpio/Port Pin needs to be configured as Input/Output/Interrupt pin.
 * @param[in] pPinConfig   Pin configurations.
 *
 * @return Status of the API
 * @retval #PH_DRIVER_SUCCESS Operation successful.
 */
FUNC(phStatus_t, ANFCRL_CODE) phDriver_PinConfig(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc, P2VAR(phDriver_Pin_Config_t, AUTOMATIC, ANFCRL_APPL_DATA) pPinConfig);

/**
 * \brief Read the state of the Gpio pin, in case of interrupt pin it will return interrupt status.
 *
 * @param[in] dwPinNumber  Gpio/Port pin number to read.
 * @param[in] ePinFunc     Whether Gpio/Port Pin that needs to be read is Output or Interrupt pin.
 *
 * @return Status of the Gpio/Interrupt status either 1 or 0.
 */
FUNC(uint8, ANFCRL_CODE) phDriver_PinRead(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(phDriver_Pin_Func_t, ANFCRL_VAR) ePinFunc);

/**
 * \brief Write to the Gpio/Port pin.
 *
 * @param[in] dwPinNumber  Gpio/Port pin number to write.
 * @param[in] bValue       Either 1 or 0 to write to Gpio/Port pin .
 *
 * @return Nothing
 */
FUNC(void, ANFCRL_CODE) phDriver_PinWrite(VAR(uint32, ANFCRL_VAR) dwPinNumber, VAR(uint8, ANFCRL_VAR) bValue);

/**
 * \brief Clear interrupt status.
 * @param[in] dwPinNumber  Interrupt Pin number to clear interrupt status.
 *
 * @return  Nothing
 */
#ifndef AUTOSAR_VER
FUNC(void, ANFCRL_CODE) phDriver_PinClearIntStatus(VAR(uint32, ANFCRL_VAR) dwPinNumber);
#endif /* AUTOSAR_VER */
/**
 * end of group phDriver Driver Abstraction Layer (DAL)
 * @}
 */

#define ANFCRL_STOP_SEC_CODE
#if ((PHDRIVER_GPIO_AR_RELEASE_MAJOR_VERSION == 4) && (PHDRIVER_GPIO_AR_RELEASE_MINOR_VERSION == 0))
	#include <MemMap.h>
#else
	#include <AnfcRL_MemMap.h>
#endif

#ifdef __cplusplus
}
#endif
#endif /* PHDRIVER_GPIO_H */
