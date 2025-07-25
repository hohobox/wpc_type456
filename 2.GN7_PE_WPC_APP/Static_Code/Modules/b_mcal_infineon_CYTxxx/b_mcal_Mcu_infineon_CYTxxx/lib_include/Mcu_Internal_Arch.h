#ifndef MCU_INTERNAL_ARCH_H
# define MCU_INTERNAL_ARCH_H 1

/** \brief AUTOSAR Mcu Driver
 **
 ** This file contains the declaration of the AUTOSAR module Mcu function
 ** for processing architecture functionality.
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
#include <Mcu_Types.h>     /* Module public types */
#include <Mcu_Regs.h>      /* hardware dependent declarations. */

/*==================[macros]=================================================*/
/*==================[type definitions]=======================================*/
/*==================[external function declarations]=========================*/

#define MCU_START_SEC_CODE_ASIL_B
#include <Mcu_MemMap.h>

/** \brief Mcu_Init_Arch
 **
 ** This function initializes the Mcu driver.
 **
 ** \param[in]  McuConfigPtr  The pointer to configuration data.
 **
 ** \pre  McuConfigPtr shall not be a NULL pointer.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_Init_Arch(
  P2CONST( Mcu_ConfigType, AUTOMATIC, MCU_APPL_CONST ) McuConfigPtr
);

/** \brief Mcu_InitClock_Arch
 **
 ** This function initializes clock setting with specified clock configuration.
 **
 ** \param[in]  McuApiId              API ID.
 ** \param[in]  McuClockConfigPtr     The pointer to clock configuration data.
 **
 ** \retval  MCU_OK         Clock initialization is success.
 ** \retval  MCU_NOT_OK     Clock initialization is failed.
 */
extern FUNC( Mcu_ReturnType, MCU_CODE ) 
Mcu_InitClock_Arch(
  VAR( uint8, AUTOMATIC ) McuApiId,
  P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST ) McuClockConfigPtr
);


/** \brief Mcu_DistributePllClock_Arch
 **
 ** This function starts distribution of SSCG/PLL/FLL clock after SSCG/PLL/FLL clock is locked.
 **
 ** \param[in]  McuClockConfigPtr     The pointer to clock configuration data.
 **
 */
extern FUNC( void, MCU_CODE ) 
Mcu_DistributePllClock_Arch(
  P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST ) McuClockConfigPtr
);


/** \brief Mcu_GetPllStatus_Arch
 **
 ** This function returns current SSCG/PLL/FLL status.
 **
 ** \param[in]  McuClockConfigPtr     The pointer to clock configuration data.
 **
 ** \retval  MCU_PLL_LOCKED            SSCG/PLL/FLL is already locked.
 ** \retval  MCU_PLL_UNLOCKED          SSCG/PLL/FLL is not locked yet.
 ** \retval  MCU_PLL_STATUS_UNDEFINED  SSCG/PLL/FLL status is undefined.
 */
extern FUNC( Mcu_PllStatusType, MCU_CODE ) 
Mcu_GetPllStatus_Arch(
  P2CONST( Mcu_ClockConfigType, AUTOMATIC, MCU_APPL_CONST ) McuClockConfigPtr
);


/** \brief Mcu_SetPllFllSettingFlag_Arch
 **
 ** This function sets flag on whether clock is set by Mcu module.
 **
 ** \param[in]  SettingFlag  TRUE or FALSE.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_SetPllFllSettingFlag_Arch(
  VAR( boolean, AUTOMATIC ) SettingFlag
);


/** \brief Mcu_GetPllFllSettingFlag_Arch
 **
 ** This function gets flag on whether clock is set by Mcu module.
 **
 ** \retval TRUE   Clock setting by Mcu module is enable.
 ** \retval FALSE  Clock setting by Mcu module is disable.
 **
 */
extern FUNC( boolean, MCU_CODE ) 
Mcu_GetPllFllSettingFlag_Arch( void );


/** \brief Mcu_GetResetReason_Arch
 **
 ** This function returns the reset reason.
 **
 ** \pre  Mcu_UpdateResetReason is called before.
 **
 ** \return  Reset reason value.
 */
extern FUNC( Mcu_ResetType, MCU_CODE ) Mcu_GetResetReason_Arch( void );


/** \brief Mcu_GetResetRawValue_Arch
 **
 ** This function returns the reset reason raw value.
 **
 ** \pre  Mcu_UpdateResetReason is called before.
 **
 ** \return  Raw reset reason value.
 */
extern FUNC( Mcu_RawResetType, MCU_CODE ) Mcu_GetResetRawValue_Arch( void );


/** \brief Mcu_Reset_Arch
 **
 ** This function performs specified reset.
 **
 ** \param[in]  McuRegReset    Reset type value.
 ** \param[in]  ResetConfigPtr The pointer to the reset configuration.
 **
 ** \pre  McuRegReset is in valid range.
 */
extern FUNC( void, MCU_CODE ) Mcu_Reset_Arch(
  VAR( Mcu_RegResetType, AUTOMATIC ) McuRegReset,
  P2CONST( Mcu_ResetConfigType, AUTOMATIC, MCU_APPL_CONST ) McuResetConfigPtr
);


/** \brief Mcu_CheckModeConfig_Arch
 **
 ** This function checks compatibility of some configuration parameters.
 **
 ** \param[in]  ModeConfigPtr  The pointer to Mode configuration.
 */
extern FUNC( Mcu_ReturnType, MCU_CODE ) 
Mcu_CheckModeConfig_Arch(
  P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST ) ModeConfigPtr
);


/** \brief Mcu_SetMode_Arch
 **
 ** This function sets MCU to specified mode.
 **
 ** \param[in]  McuModeConfigPtr  The pointer to Mode configuration.
 **
 ** \pre  McuModeConfigPtr shall not be a NULL pointer.
 */
extern FUNC( Mcu_ReturnType, MCU_CODE ) 
Mcu_SetMode_Arch(
  P2CONST( Mcu_ModeConfigType, AUTOMATIC, MCU_APPL_CONST ) McuModeConfigPtr
);


/** \brief Mcu_InitRamSection_Arch
 **
 ** This function initializes RAM section with specified RAM configuration.
 **
 ** \param[in]  McuRamConfigPtr  The pointer to RAM configuration.
 **
 ** \pre  McuRamConfigPtr shall not be a NULL pointer.
 */
extern FUNC( Std_ReturnType, MCU_CODE ) 
Mcu_InitRamSection_Arch(
  P2CONST( Mcu_RamConfigType, AUTOMATIC, MCU_APPL_CONST ) McuRamConfigPtr
);


/** \brief Mcu_CheckModeStatus_Arch
 **
 ** This function checks mode status.
 **
 ** \param[in]  McuModeConfigPtr      The pointer to mode configuration data.
 ** \param[out] McuStatusPtr          The pointer to store the status.
 **
 ** \pre  McuModeConfigPtr shall not be a NULL pointer.
 */
extern FUNC( Mcu_ReturnType, MCU_CODE ) 
Mcu_CheckModeStatus_Arch(
  P2CONST( Mcu_ModeConfigType, MCU_CONST, MCU_APPL_CONST ) McuModeConfigPtr,
  P2VAR( Mcu_StatusType, AUTOMATIC, MCU_APPL_DATA ) McuStatusPtr
);


/** \brief Mcu_CheckClockStatus_Arch
 **
 ** This function checks clock status.
 **
 ** \param[in]  McuClockConfigPtr      The pointer to clock configuration data.
 **
 ** \pre  McuClockConfigPtr shall not be a NULL pointer.
 */
extern FUNC( Mcu_ReturnType, MCU_CODE ) 
Mcu_CheckClockStatus_Arch(
  P2CONST( Mcu_ClockConfigType, MCU_CONST, MCU_APPL_CONST ) McuClockConfigPtr
);


/** \brief Mcu_GetVersionInfo_Arch
 **
 ** This function returns version information of MCU driver.
 **
 ** \param[out]  McuVersionInfoPtr  The pointer to store the version information.
 **
 ** \pre  McuVersionInfoPtr shall not be a NULL pointer.
 */
extern FUNC( void, MCU_CODE ) 
Mcu_GetVersionInfo_Arch(
  P2VAR( Std_VersionInfoType, AUTOMATIC, MCU_APPL_DATA ) McuVersionInfoPtr
);


/** \brief Mcu_EnterCriticalSection
 **
 ** This function calls function for entering critical section.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_EnterCriticalSection( void );


/** \brief Mcu_ExitCriticalSection
 **
 ** This function calls function for exiting critical section.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_ExitCriticalSection( void );


/** \brief Mcu_DemReportClockFailure
 **
 ** This function reports to DEM that clock failure error has occurred.
 
 ** \param[in]  ApiId  Id of the service that detected the error.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_DemReportClockFailure(
  VAR( uint8, AUTOMATIC ) ApiId
);


/** \brief Mcu_DemReportClockSuccess
 **
 ** This function reports to DEM that no clock failure error has occurred.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_DemReportClockSuccess( void );


/** \brief Mcu_DemReportResetFailure
 **
 ** This function reports to DEM that reset failure error has occurred.
 
 ** \param[in]  ApiId  Id of the service that detected the error.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_DemReportResetFailure(
  VAR( uint8, AUTOMATIC ) ApiId
);


/** \brief Mcu_DemReportResetSuccess
 **
 ** This function reports to DEM that no reset failure error has occurred.
 **
 */
extern FUNC( void, MCU_CODE ) Mcu_DemReportResetSuccess( void );


#define MCU_STOP_SEC_CODE_ASIL_B
#include <Mcu_MemMap.h>

/*==================[internal function declarations]=========================*/
/*==================[external constants]=====================================*/
/*==================[internal constants]=====================================*/
/*==================[external data]==========================================*/
/*==================[internal data]==========================================*/
/*==================[external function definitions]==========================*/
/*==================[internal function definitions]==========================*/

# endif /* if !defined( MCU_INTERNAL_ARCH_H ) */
/*==================[end of file]============================================*/
