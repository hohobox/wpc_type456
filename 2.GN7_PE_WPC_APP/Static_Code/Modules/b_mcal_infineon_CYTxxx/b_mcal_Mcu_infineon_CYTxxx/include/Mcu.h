#ifndef MCU_H
# define MCU_H 1

/** \brief AUTOSAR MCU Driver
 **
 ** This file contains or includes all external identifiers of the AUTOSAR module MCU.
 **
 ** Do not edit this file manually.
 ** Any change might compromise the safety integrity level of
 ** the software partition it is contained in.
 **
 ** Product: SW-MCAL42-DRV
 **
 ** (c) 2017-2022, Cypress Semiconductor Corporation (an Infineon company) or
 ** an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 ** This software, including source code, documentation and related materials
 ** ("Software") is owned by Cypress Semiconductor Corporation or one of
 ** its affiliates ("Cypress") and is protected by and subject to worldwide
 ** patent protection (United States and foreign), United States copyright laws
 ** and international treaty provisions.  Therefore, you may use this Software
 ** only as provided in the license agreement accompanying the software package
 ** from which you obtained this Software ("EULA").
 ** If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 ** non-transferable license to copy, modify,
 ** and compile the Software source code solely for use in connection
 ** with Cypress's integrated circuit products.
 ** Any reproduction, modification, translation, compilation,
 ** or representation of this Software except as specified above is prohibited
 ** without the express written permission of Cypress.
 ** Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 ** EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT,
 ** IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 ** Cypress reserves the right to make changes to the Software without notice.
 ** Cypress does not assume any liability arising out of the application or
 ** use of the Software or any product or circuit described in the Software.
 ** Cypress does not authorize its products for use in any products
 ** where a malfunction or failure of the Cypress product may reasonably be
 ** expected to result in significant property damage,
 ** injury or death ("High Risk Product"). By including Cypress's product
 ** in a High Risk Product, the manufacturer of such system or application
 ** assumes all risk of such use and in doing so agrees to indemnify Cypress
 ** against all liability.
 */

/*==================[inclusions]=============================================*/

#include <Std_Types.h>     /* AUTOSAR standard types */
#include <Mcu_Types.h>     /* Module public types */
#include <Mcu_Cfg.h>       /* Generated MCU driver config */
#include <Mcu_PBcfg.h>     /* Generated MCU driver PB config */
#include <Mcu_Version.h>   /* Module version declarations */

/*==================[macros]=================================================*/

/*------------------[AUTOSAR configuration AR version number check]----------*/

#if !defined( MCU_GEN_AR_RELEASE_MAJOR_VERSION)
#  error MCU_GEN_AR_RELEASE_MAJOR_VERSION not defined
#elif !defined( MCU_GEN_AR_RELEASE_MINOR_VERSION)
#  error MCU_GEN_AR_RELEASE_MINOR_VERSION not defined
#elif !defined( MCU_GEN_AR_RELEASE_REVISION_VERSION)
#  error MCU_GEN_AR_RELEASE_REVISION_VERSION not defined
#elif ( ((MCU_AR_RELEASE_MAJOR_VERSION) != (MCU_GEN_AR_RELEASE_MAJOR_VERSION)) || \
        ((MCU_AR_RELEASE_MINOR_VERSION) != (MCU_GEN_AR_RELEASE_MINOR_VERSION)) || \
        ((MCU_AR_RELEASE_REVISION_VERSION) != (MCU_GEN_AR_RELEASE_REVISION_VERSION)) )
#  error AUTOSAR MCU configuration AR version number mismatch
#endif

/*------------------[AUTOSAR configuration SW version number check]----------*/

#if !defined( MCU_GEN_SW_MAJOR_VERSION)
#  error MCU_GEN_SW_MAJOR_VERSION not defined
#elif !defined( MCU_GEN_SW_MINOR_VERSION)
#  error MCU_GEN_SW_MINOR_VERSION not defined
#elif !defined( MCU_GEN_SW_PATCH_VERSION)
#  error MCU_GEN_SW_PATCH_VERSION not defined
#elif ( ((MCU_SW_MAJOR_VERSION) != (MCU_GEN_SW_MAJOR_VERSION)) || \
        ((MCU_SW_MINOR_VERSION) != (MCU_GEN_SW_MINOR_VERSION)) )
#  error AUTOSAR MCU configuration SW version number mismatch
#endif

/*------------------[AUTOSAR configuration additional check]-----------------*/

#if !defined(MCU_GEN_MODULE_ID)
#  error MCU_GEN_MODULE_ID not defined
#elif !defined(MCU_GEN_VENDOR_ID)
#  error MCU_GEN_VENDOR_ID not defined
#elif ( ((MCU_MODULE_ID) != (MCU_GEN_MODULE_ID)) || \
        ((MCU_VENDOR_ID) != (MCU_GEN_VENDOR_ID)) )
#  error AUTOSAR MCU configuation additional checks failed
#endif

/*------------------[Service IDs]--------------------------------------------*/

#ifdef MCU_API_SERVICE_INIT
#  error MCU_API_SERVICE_INIT is already defined
#else
/** \brief Mcu_Init service id */
#  define MCU_API_SERVICE_INIT 0x00U
#endif

#ifdef MCU_API_SERVICE_INIT_RAM_SECTION
#  error MCU_API_SERVICE_INIT_RAM_SECTION is already defined
#else
/** \brief Mcu_InitRamSection service id */
#  define MCU_API_SERVICE_INIT_RAM_SECTION 0x01U
#endif

#ifdef MCU_API_SERVICE_INIT_CLOCK
#  error MCU_API_SERVICE_INIT_CLOCK is already defined
#else
/** \brief Mcu_InitClock service id */
#  define MCU_API_SERVICE_INIT_CLOCK 0x02U
#endif

#ifdef MCU_API_SERVICE_DISTRIBUTE_PLL_CLOCK
#  error MCU_API_SERVICE_DISTRIBUTE_PLL_CLOCK is already defined
#else
/** \brief Mcu_DistributePllClock service id */
#  define MCU_API_SERVICE_DISTRIBUTE_PLL_CLOCK 0x03U
#endif

#ifdef MCU_API_SERVICE_GET_PLL_STATUS
#  error MCU_API_SERVICE_GET_PLL_STATUS is already defined
#else
/** \brief Mcu_GetPllStatus service id */
#  define MCU_API_SERVICE_GET_PLL_STATUS 0x04U
#endif

#ifdef MCU_API_SERVICE_GET_RESET_REASON
#  error MCU_API_SERVICE_GET_RESET_REASON is already defined
#else
/** \brief Mcu_GetResetReason service id */
#  define MCU_API_SERVICE_GET_RESET_REASON 0x05U
#endif

#ifdef MCU_API_SERVICE_GET_RESET_RAW_VALUE
#  error MCU_API_SERVICE_GET_RESET_RAW_VALUE is already defined
#else
/** \brief Mcu_GetResetRawValue service id */
#  define MCU_API_SERVICE_GET_RESET_RAW_VALUE 0x06U
#endif

#ifdef MCU_API_SERVICE_PERFORM_RESET
#  error MCU_API_SERVICE_PERFORM_RESET is already defined
#else
/** \brief Mcu_PerformReset service id */
#  define MCU_API_SERVICE_PERFORM_RESET 0x07U
#endif

#ifdef MCU_API_SERVICE_SET_MODE
#  error MCU_API_SERVICE_SET_MODE is already defined
#else
/** \brief Mcu_SetMode service id */
#  define MCU_API_SERVICE_SET_MODE 0x08U
#endif

#ifdef MCU_API_SERVICE_GET_VERSION_INFO
#  error MCU_API_SERVICE_GET_VERSION_INFO is already defined
#else
/** \brief Mcu_GetVersionInfo service id */
#  define MCU_API_SERVICE_GET_VERSION_INFO 0x09U
#endif

#ifdef MCU_API_SERVICE_CHECK_CLOCK_STATUS
#  error MCU_API_SERVICE_CHECK_CLOCK_STATUS is already defined
#else
/** \brief Mcu_CheckClockStatus service id */
#  define MCU_API_SERVICE_CHECK_CLOCK_STATUS 0x20U
#endif

#ifdef MCU_API_SERVICE_CHECK_MODE_STATUS
#  error MCU_API_SERVICE_CHECK_MODE_STATUS is already defined
#else
/** \brief Mcu_CheckModeStatus service id */
#  define MCU_API_SERVICE_CHECK_MODE_STATUS 0x21U
#endif


/*------------------[Development errors]-------------------------------------*/

#ifdef MCU_E_PARAM_CONFIG
#  error MCU_E_PARAM_CONFIG is already defined
#else
/** \brief ConfigPtr is NULL */
#  define MCU_E_PARAM_CONFIG       0x0AU
#endif

#ifdef MCU_E_PARAM_CLOCK
#  error MCU_E_PARAM_CLOCK is already defined
#else
/** \brief ClockSetting value is incorrect or out of range */
#  define MCU_E_PARAM_CLOCK        0x0BU
#endif

#ifdef MCU_E_PARAM_MODE
#  error MCU_E_PARAM_MODE is already defined
#else
/** \brief Mcu Mode value is incorrect or out of range */
#  define MCU_E_PARAM_MODE         0x0CU
#endif

#ifdef MCU_E_PARAM_RAMSECTION
#  error MCU_E_PARAM_RAMSECTION is already defined
#else
/** \brief RamSection value is incorrect or out of range */
#  define MCU_E_PARAM_RAMSECTION   0x0DU
#endif

#ifdef MCU_E_PLL_NOT_LOCKED
#  error MCU_E_PLL_NOT_LOCKED is already defined
#else
/** \brief PLL not locked when calling Mcu_DistributePllClock() */
#  define MCU_E_PLL_NOT_LOCKED     0x0EU
#endif

#ifdef MCU_E_UNINIT
#  error MCU_E_UNINIT is already defined
#else
/** \brief Mcu_Init() was not called before calling any ohter api-function */
#  define MCU_E_UNINIT             0x0FU
#endif

#ifdef MCU_E_PARAM_POINTER
#  error MCU_E_PARAM_POINTER is already defined
#else
/** \brief Mcu_GetVersionInfo called with invalid pointer */
#  define MCU_E_PARAM_POINTER      0x10U
#endif

#ifdef MCU_E_INIT_FAILED
#  error MCU_E_INIT_FAILED is already defined
#else
/** \brief Mcu_Init called with wrong parameter */
#  define MCU_E_INIT_FAILED        0x11U
#endif

#ifdef MCU_E_CLOCK_FAILURE_FOR_CALLOUT
#  error MCU_E_CLOCK_FAILURE_FOR_CALLOUT is already defined
#else
/** \brief Detect a clock failure error */
#  define MCU_E_CLOCK_FAILURE_FOR_CALLOUT 0x40U
#endif

#ifdef MCU_E_RESET_FAILURE_FOR_CALLOUT
#  error MCU_E_RESET_FAILURE_FOR_CALLOUT is already defined
#else
/** \brief Detect a reset failure error */
#  define MCU_E_RESET_FAILURE_FOR_CALLOUT 0x41U
#endif

#ifdef MCU_E_RESET_NOT_PERFORMED
#  error MCU_E_RESET_NOT_PERFORMED is already defined
#else
/** \brief Mcu_PerformReset does not perform reset */
#  define MCU_E_RESET_NOT_PERFORMED                    0x60U
#endif

#ifdef MCU_E_SYSTEM_RESOURCE_UPDATE_NOT_COMPLETED
#  error MCU_E_SYSTEM_RESOURCE_UPDATE_NOT_COMPLETED is already defined
#else
/** \brief System resource update does not complete */
#  define MCU_E_SYSTEM_RESOURCE_UPDATE_NOT_COMPLETED   0x80U
#endif

/*------------------[Vendor specific definitions]----------------------------*/

#ifdef MCU_FLAGS_CLEAR_RESET_REASON
#error MCU_FLAGS_CLEAR_RESET_REASON is already defined
#else
/** \brief Flag for McuClearResetReasonRegister */
#define MCU_FLAGS_CLEAR_RESET_REASON  0x40U
#endif

#ifdef MCU_FLAGS_INIT_CLOCK
#error MCU_FLAGS_INIT_CLOCK is already defined
#else
/** \brief Flag for McuEnableDefaultClock */
#define MCU_FLAGS_INIT_CLOCK          0x80U
#endif

#ifdef MCU_RESET_RAW_VALUE_INVALID
#error MCU_RESET_RAW_VALUE_INVALID is already defined
#else
/** \brief Invalid value for raw reset reason */
#define MCU_RESET_RAW_VALUE_INVALID   0xFFFFFFFFU
#endif

/*==================[type definitions]=======================================*/
/*==================[external function declarations]=========================*/
#define MCU_START_SEC_CODE_ASIL_B
#include <Mcu_MemMap.h>

/** \brief Mcu_Init
 ** 
 ** This service initializes the MCU driver.
 **
 ** \pre  No execution of init is done before.
 **
 ** \param[in]  ConfigPtr  Pointer to MCU driver configuration set.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_Init( 
  P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST) ConfigPtr
);


/** \brief Mcu_InitRamSection
 **
 ** This service initializes the RAM section wise.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 ** \pre  pointer to configuration data must not be a NULL pointer.
 **
 ** \param[in]  RamSection  Selects RAM memory section provided in configuration set.
 */
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_InitRamSection( 
  VAR( Mcu_RamSectionType, AUTOMATIC ) RamSection
);


#if (MCU_INIT_CLOCK == STD_ON)
/** \brief Mcu_InitClock
 **
 ** This service initializes the PLL and other MCU specific clock options.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 ** \pre  pointer to configuration data must not be a NULL pointer.
 **
 ** \param[in]  ClockSetting  Clock setting.
 ** 
 ** \retval  E_OK      command has been accepted.
 ** \retval  E_NOT_OK  command has not been accepted.
 */
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_InitClock( 
  VAR( Mcu_ClockType, AUTOMATIC ) ClockSetting
);
#endif /* (MCU_INIT_CLOCK == STD_ON) */

#if (MCU_NO_PLL == STD_OFF)
/** \brief Mcu_DistributePllClock
 **
 ** This service activates the PLL clock to the MCU clock distribution.
 **
 ** \pre Mcu_Init() has already been called.
 ** \pre Mcu_InitClock() has to be called already.
 ** \pre DET has to be initialized already.
 ** \pre The status of PLL has been detected as locked by Mcu_GetPllStatus().
 ** 
 ** \retval  E_OK      command has been accepted.
 ** \retval  E_NOT_OK  command has not been accepted.
 */
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_DistributePllClock( void );
#endif /* (MCU_NO_PLL == STD_OFF) */


/** \brief Mcu_GetPllStatus
 **
 ** This service provides the lock status of the PLL.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 **
 ** \return  PLL status.
 */
extern FUNC( Mcu_PllStatusType, MCU_CODE ) 
Mcu_GetPllStatus( void );


/** \brief Mcu_GetResetReason
 **
 ** The service reads the reset type from the hardware, if supported.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 **
 ** \return  Reset reason.
 */
extern FUNC( Mcu_ResetType, MCU_CODE ) 
Mcu_GetResetReason( void );


/** \brief Mcu_GetResetRawValue
 **
 ** The service reads the reset type from the hardware register, if supported.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 */
extern FUNC( Mcu_RawResetType, MCU_CODE ) 
Mcu_GetResetRawValue( void );


#if (MCU_PERFORM_RESET_API == STD_ON)
/** \brief Mcu_PerformReset
 **
 ** The service performs a microcontroller reset.
 **
 ** \pre  Mcu_Init() has to be called already.
 ** \pre  DET has to be initialized already.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_PerformReset( void );
#endif /* (MCU_PERFORM_RESET_API == STD_ON) */


/** \brief Mcu_SetMode
 **
 ** This service activates the MCU power modes.
 **
 ** \pre  Mcu_Init() has already been called.
 ** \pre  DET has to be initialized already.
 ** \pre  pointer to configuration data must not be a NULL pointer.
 **
 ** \param[in]  McuMode  Set different MCU power modes configured in the configuration set.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_SetMode( 
  VAR( Mcu_ModeType, AUTOMATIC ) McuMode
);


#if (MCU_VERSION_INFO_API == STD_ON)
/** \brief Mcu_GetVersionInfo
 **
 ** This service returns the version information of this module.
 **
 ** \param[out]  versioninfo  Pointer to where to store the version information of this module.
 **
 ** \pre  DET has to be initialized already.
 ** \pre  versioninfo must not be a NULL pointer.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_GetVersionInfo( 
  P2VAR( Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA) versioninfo
);
#endif /* (MCU_VERSION_INFO_API == STD_ON) */


#if (MCU_SAFETY_FUNCTION_API == STD_ON)
/** \brief Mcu_CheckClockStatus
 **
 ** This service checks registers with clock configuration.
 **
 ** \pre Mcu_Init() has already been called.
 ** \pre Mcu_InitClock() has to be called already.
 ** \pre DET has to be initialized already.
 **
 ** \param[in]   ClockSettingId   The value of Clock setting id.
 **
 ** \retval  E_OK           Check processing is no error occurred.
 ** \retval  E_NOT_OK       Check processing is error occurred.
 **/
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_CheckClockStatus(
  VAR( Mcu_ClockType, AUTOMATIC ) ClockSettingId
);


/** \brief Mcu_CheckModeStatus
 **
 ** This service checks registers with mode configuration.
 **
 ** \pre Mcu_Init() has already been called.
 ** \pre DET has to be initialized already.
 **
 ** \param[in]   ModeSettingId    Id of mode setting.
 ** \param[out]  StatusPtr        The pointer to store the status.
 **
 ** \retval  E_OK           Check processing is no error occurred.
 ** \retval  E_NOT_OK       Check processing is error occurred.
 **/
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_CheckModeStatus(
  VAR( Mcu_ModeType, AUTOMATIC ) ModeSettingId,
  P2VAR( Mcu_StatusType, AUTOMATIC, MCU_APPL_DATA ) StatusPtr
);
#endif /* (MCU_SAFETY_FUNCTION_API == STD_ON) */


/** \brief Mcu_Lvd_Int_Common
 **
 ** This function handles the LVD interrupts.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_Lvd_Int_Common( void );


/** \brief Mcu_GetHwInfo
 **
 ** This function returns the HW information.
 */
extern FUNC_P2CONST( Mcu_HwInfoType, MCU_APPL_CONST, MCU_CODE ) 
Mcu_GetHwInfo( void );


#define MCU_STOP_SEC_CODE_ASIL_B
#include <Mcu_MemMap.h>

/*==================[internal function declarations]=========================*/
/*==================[external constants]=====================================*/
/*==================[internal constants]=====================================*/
/*==================[external data]==========================================*/
/*==================[internal data]==========================================*/
/*==================[external function definitions]==========================*/
/*==================[internal function definitions]==========================*/

# endif /* if !defined( MCU_H ) */
/*==================[end of file]============================================*/
