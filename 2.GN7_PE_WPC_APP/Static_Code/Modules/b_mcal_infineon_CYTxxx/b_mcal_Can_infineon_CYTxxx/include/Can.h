/** \brief Can.h
 **
 ** Top-level API of the Can driver module.
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

#ifndef CAN_H_INCLUDED
#define CAN_H_INCLUDED

/*==================[inclusions]============================================*/

#include <ComStack_Types.h>
#include <Can_GeneralTypes.h>
#include <Can_ControllerManager.h>
#include <Can_Cfg.h>
#include <Can_PBcfg.h>
#include <Can_Data.h>
#include <Can_Version.h>

/*==================[macros]================================================*/

/*------------------[AUTOSAR configuration SW version number check]---------*/
#if !defined( CAN_CFG_MAJOR_VERSION )
#  error CAN_CFG_MAJOR_VERSION not defined
#elif !defined( CAN_CFG_MINOR_VERSION )
#  error CAN_CFG_MINOR_VERSION not defined
#elif !defined( CAN_CFG_PATCH_VERSION )
#  error CAN_CFG_PATCH_VERSION not defined
#elif !CAN_SW_VERSION_CHECK( CAN_CFG_MAJOR_VERSION,    \
                             CAN_CFG_MINOR_VERSION,    \
                             CAN_CFG_PATCH_VERSION )
#  error AUTOSAR CAN configuration SW version number mismatch
#endif

/** API Service called with wrong parameter: pointer */
#define CAN_E_PARAM_POINTER 0x01u
/** API Service called with wrong parameter: handle */
#define CAN_E_PARAM_HANDLE 0x02u
/** API Service called with wrong parameter: DLC */
#define CAN_E_PARAM_DLC 0x03u
/** API Service called with wrong parameter: controller index */
#define CAN_E_PARAM_CONTROLLER 0x04u
/** API Service used without initialization of the module. */
#define CAN_E_UNINIT 0x05u
/** Invalid transition for the current mode. */
#define CAN_E_TRANSITION 0x06u
/** Received CAN message is lost. */
#define CAN_E_DATALOST 0x07u
/** API Service called with wrong parameter: baudrate index */
#define CAN_E_PARAM_BAUDRATE 0x08u
/** API Service called with wrong parameter: IcomConfigration ID. */
#define CAN_E_ICOM_CONFIG_INVALID 0x09u
/** Invalid configuration set selection. */
#define CAN_E_INIT_FAILED 0x0Au
/** API Service called with wrong parameter: CAN ID */
#define CAN_E_PARAM_ID 0x0Bu
/** Received CAN message cannot be identified. This error is probably caused by
 interference of some other software. */
#define CAN_E_UNKNOWN_DATA 0x0Cu
/** OS timer has refused its service. Timeout cannot be evaluated. */
#define CAN_E_OS_TIME_REFUSED 0x0Du
/** An uncorrectable bit error in message RAM is detected. */
#define CAN_E_UNCORRECTABLE_BIT_ERROR 0x0Eu
/** API Service called with parameter PduInfo->PduId set to the value which is
 reserved for driver internal usage. Reserved value is the highest possible value
 of PduId. Depending on its type, this is either 0xFF (uint8) or 0xFFFF (uint16). */
#define CAN_E_PARAM_PDUID 0x0Fu
/** Interrupt disable or enable violates nesting restrictions. */
#define CAN_E_IRQ_DEPTH 0x10u
/** The prescaler calculated by the changed clock is an unsettable value.
 Possible values are as follows
 Nominal Bit Rate Prescaler: 0x000-0x1FF
 Data Bit Rate Prescaler: 0x01-0x02(limitation by ISO-11898) */
#define CAN_E_CALC_PRESCALER 0x11u

/** Can_Init() api service id */
#define CAN_ID_INIT 0x00u
/** Can_MainFunction_Write() api service id */
#define CAN_ID_MF_WRITE 0x01u
/** Can_SetControllerMode() api service id */
#define CAN_ID_SETCTRLMODE 0x03u
/** Can_DisableControllerInterrupts() api service id */
#define CAN_ID_DISABLECTRLINT 0x04u
/** Can_EnableControllerInterrupts() api service id */
#define CAN_ID_ENABLECTRLINT 0x05u
/** Can_Write() api service id */
#define CAN_ID_WRITE 0x06u
/** Can_GetVersionInfo() api service id */
#define CAN_ID_GETVERSIONINFO 0x07u
/** Can_MainFunction_Read() api service id */
#define CAN_ID_MF_READ 0x08u
/** Can_MainFunction_BusOff() api service id */
#define CAN_ID_MF_BUSOFF 0x09u
/** Can_MainFunction_Wakeup() api service id */
#define CAN_ID_MF_WAKEUP 0x0Au
/** Can_CheckWakeup() api service id */
#define CAN_ID_CHECKWAKEUP 0x0Bu
/** Can_MainFunction_MODE() api service id */
#define CAN_ID_MF_MODE 0x0Cu
/** Can_ChangeBaudrate() api service id */
#define CAN_ID_CHANGEBAUDRATE 0x0Du
/** Can_CheckBaudrate() api service id */
#define CAN_ID_CHECKBAUDRATE 0x0Eu
/** Can_SetBaudrate() api service id */
#define CAN_ID_SETBAUDRATE 0x0Fu
/** Can_SetIcomConfiguration() api service id */
#define CAN_ID_SETICOMCFG 0x0Fu
/** Can_DeInit() api service id */
#define CAN_ID_DEINIT 0x10u
/** Can_GetStatus() api service id */
#define CAN_ID_GETSTATUS 0x20u
/** Api service id of the interrupt service routine. */
#define CAN_ID_ISR 0x21u
/** Can_SetBaudrateInChangedClock() api service id */
#define CAN_ID_SETBAUDRATE_IN_CHANGED_CLOCK 0x22u
/** Value to set the driver compatibility to AUTOSAR 4.2.2. */
#define CAN_ASR_422_COMPATIBILITY 422u
/** Value to set the driver compatibility to AUTOSAR 4.0.3. */
#define CAN_ASR_403_COMPATIBILITY 403u
/** Bit mask to set or read the Error Passive status in return value of operation
 Can_GetStatus. */
#define CAN_STATUS_ERROR_PASSIVE CAN_CONTROLLER_ERRORSTATUS_ERROR_PASSIVE
/** Bit mask to set or read the RX Overflow status in return value of operation
 Can_GetStatus. */
#define CAN_STATUS_RX_OVERFLOW CAN_CONTROLLER_ERRORSTATUS_RX_OVERFLOW

/** \brief type for Can DEM status */
#define CAN_DEM_EVENT_STATUS_PASSED 0x00u  /* Can internal DEM status passed */
#define CAN_DEM_EVENT_STATUS_FAILED 0x01u  /* Can internal DEM status failed */

/*==================[type definitions]======================================*/

/*==================[external function declarations]========================*/

#define CAN_START_SEC_CODE_ASIL_B

#include "Can_MemMap.h"

/** \brief Can_DisableControllerInterrupts
 **
 ** This function disables all interrupts for this CAN controller.
 **
 ** \param [in] Controller   CAN controller for which interrupts shall be disabled.
 **
 */
extern FUNC(void, AUTOMATIC) Can_DisableControllerInterrupts
(
  VAR(uint8, AUTOMATIC) Controller
);

/** \brief Can_EnableControllerInterrupts
 **
 ** This function enables all allowed interrupts.
 **
 ** \param [in] Controller   CAN controller for which interrupts shall be re-enabled
 **
 */
extern FUNC(void, AUTOMATIC) Can_EnableControllerInterrupts
(
  VAR(uint8, AUTOMATIC) Controller
);

#if CAN_GET_VERSION_INFO_API == STD_ON
/** \brief Can_GetVersionInfo
 **
 ** This function returns the version information of this module.
 **
 ** \param [out] versioninfo   Pointer to where to store the version information of
 **                            this module.
 **
 */
extern FUNC(void, AUTOMATIC) Can_GetVersionInfo
(
  P2VAR(Std_VersionInfoType, AUTOMATIC, AUTOMATIC) versioninfo
);
#endif /* CAN_GET_VERSION_INFO_API == STD_ON */

/** \brief Can_InterruptHandler
 **
 ** Generic interrupt handler, that is called from the specific interrupt handlers.
 **
 ** \param [in] InterruptNum   Element number  of the controller that caused the interrupt.
 **
 */
extern FUNC(void, AUTOMATIC) Can_InterruptHandler
(
  VAR(uint8, AUTOMATIC) InterruptNum
);

#if defined( CAN_DECLARATION_MAINFUNCTION )
/** \brief Can_MainFunction_BusOff
 **
 ** This function performs the polling of bus-off events that are configured
 ** statically as 'to be polled'.
 **
 */
extern FUNC(void, AUTOMATIC) Can_MainFunction_BusOff(void);
#endif /* if defined( CAN_DECLARATION_MAINFUNCTION ) */

#if defined( CAN_DECLARATION_MAINFUNCTION )
/** \brief Can_MainFunction_Mode
 **
 ** This function performs the polling of CAN controller mode transitions.
 **
 */
extern FUNC(void, AUTOMATIC) Can_MainFunction_Mode(void);
#endif /* if defined( CAN_DECLARATION_MAINFUNCTION ) */

#if defined( CAN_DECLARATION_MAINFUNCTION )
/** \brief Can_MainFunction_Read
 **
 ** This function performs the polling of RX indications when CAN_RX_PROCESSING is
 ** set to POLLING.
 **
 */
extern FUNC(void, AUTOMATIC) Can_MainFunction_Read(void);
#endif /* if defined( CAN_DECLARATION_MAINFUNCTION ) */

#if defined( CAN_DECLARATION_MAINFUNCTION )
/** \brief Can_MainFunction_Wakeup
 **
 ** This function performs the polling of wake-up events that are configured
 ** statically as 'to be polled'.
 **
 */
extern FUNC(void, AUTOMATIC) Can_MainFunction_Wakeup(void);
#endif /* if defined( CAN_DECLARATION_MAINFUNCTION ) */

#if defined( CAN_DECLARATION_MAINFUNCTION )
/** \brief Can_MainFunction_Write
 **
 ** This function performs the polling of TX confirmation and TX cancellation
 ** confirmation when CAN_TX_PROCESSING is set to POLLING.
 **
 */
extern FUNC(void, AUTOMATIC) Can_MainFunction_Write(void);
#endif /* if defined( CAN_DECLARATION_MAINFUNCTION ) */

/** \brief Can_SetControllerMode
 **
 ** This function performs software triggered state transitions of the CAN
 ** controller State machine.
 **
 ** \return   CAN_OK: request accepted
 **           CAN_NOT_OK: request not accepted, a development error occurred
 ** 
 ** \param [in] Controller   CAN controller for which the status shall be changed
 ** \param [in] Transition   Transition value to request new CAN controller state
 */
extern FUNC(Can_ReturnType, AUTOMATIC) Can_SetControllerMode
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(Can_StateTransitionType, AUTOMATIC) Transition
);

/** \brief Can_Write
 **
 ** This function is called by CanIf to pass a CAN message to CanDrv for
 ** transmission.
 **
 ** \return   CAN_OK: Write command has been accepted
 **           CAN_NOT_OK: development error occurred
 **           CAN_BUSY: No TX hardware buffer available or preemptive call of
 **                     Can_Write that cannot be implemented reentrant
 ** 
 ** \param [in] Hth   Information which HW-transmit handle shall be used for
 **                   transmit. Implicitly this is also the information about
 **                   the controller to use because the Hth numbers are unique
 **                   inside one hardware unit.
 ** \param [in] PduInfo   Pointer to SDU user memory, DLC and Identifier.
 */
extern FUNC(Can_ReturnType, AUTOMATIC) Can_Write
(
  VAR(Can_HwHandleType, AUTOMATIC) Hth,
  P2CONST(Can_PduType, AUTOMATIC, AUTOMATIC) PduInfo
);

#if CAN_CHANGE_BAUDRATE_API == STD_ON
/** \brief Can_ChangeBaudrate
 **
 ** This service shall change the baudrate of the CAN controller.
 ** 
 ** \return   E_OK: Service request accepted, baudrate change started
 **           E_NOT_OK: Service request not accepted
 ** \param [in] Controller   CAN Controller, whose baudrate shall be changed
 ** \param [in] Baudrate   Requested baudrate in kbps
 **
 */
extern FUNC(Std_ReturnType, AUTOMATIC) Can_ChangeBaudrate
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(uint16, AUTOMATIC) Baudrate
);
#endif /* CAN_CHANGE_BAUDRATE_API == STD_ON */

#if CAN_CHANGE_BAUDRATE_API == STD_ON
/** \brief Can_CheckBaudrate
 **
 ** This service shall check, if a certain CAN controller supports a requested
 ** baudrate.
 **
 ** \return   E_OK: Baudrate supported by the CAN Controller
 **           E_NOT_OK: Baudrate not supported / invalid CAN controller
 ** \param [in] Controller   CAN Controller to check for the support of a certain
 **                          baudrate
 ** \param [in] Baudrate   Baudrate to check in kbps
 **
 */
extern FUNC(Std_ReturnType, AUTOMATIC) Can_CheckBaudrate
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(uint16, AUTOMATIC) Baudrate
);
#endif /* CAN_CHANGE_BAUDRATE_API == STD_ON */

#if CAN_SET_BAUDRATE_API == STD_ON
/** \brief Can_SetBaudrate
 **
 ** This service shall set the baud rate configuration of the CAN controller.
 ** Depending on necessary baud rate modifications the controller might have to
 ** be reset.
 **
 ** \return   E_OK: Service request accepted, setting of (new) baud rate started
 **           E_NOT_OK: Service request not accepted
 ** \param [in] Controller   CAN controller, whose baud rate shall be set
 ** \param [in] BaudRateConfigID   references a baud rate configuration by ID (see
 **                                CanControllerBaudRateConfigID)
 **
 */
extern FUNC(Std_ReturnType, AUTOMATIC) Can_SetBaudrate
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(uint16, AUTOMATIC) BaudRateConfigID
);
#endif /* CAN_SET_BAUDRATE_API == STD_ON */

#if CAN_SET_BAUDRATE_IN_CHANGED_CLOCK_API == STD_ON
/** \brief Can_SetBaudrateInChangedClock
 **
 ** This service shall set the baud rate configuration of the CAN controller
 ** in the changed clock.
 ** Depending on necessary baud rate modifications the controller might have to
 ** be reset.
 **
 ** \return   E_OK: Service request accepted, setting of (new) baud rate started
 **           E_NOT_OK: Service request not accepted
 ** \param [in] Controller   CAN controller, whose baud rate shall be set
 ** \param [in] BaudRateConfigID   references a baud rate configuration by ID (see
 **                                CanControllerBaudRateConfigID)
 ** \param [in] ClockValue   Changed clock[MHz]
 **
 */
FUNC(Std_ReturnType, AUTOMATIC) Can_SetBaudrateInChangedClock
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(uint16, AUTOMATIC) BaudRateConfigID,
  VAR(Can_ClkFrequencyType, AUTOMATIC) ClockFrequency
);
#endif /* CAN_SET_BAUDRATE_IN_CHANGED_CLOCK_API == STD_ON */

/** \brief Can_Init
 **
 ** This function initializes the module.
 **
 ** \param [in] Config   Pointer to driver configuration.
 **
 */
extern FUNC(void, AUTOMATIC) Can_Init
(
  P2CONST(Can_ConfigType, AUTOMATIC, AUTOMATIC) Config
);

#if CAN_PUBLIC_ICOM_SUPPORT == STD_ON
/** \brief Can_SetIcomConfiguration
 **
 ** This service shall change the Icom Configuration of a CAN controller to the 
 ** requested one.
 **
 ** \return   E_OK: driver succeeded in setting a configuration with a valid 
 **                 Configuration id
 **           E_NOT_OK: CAN driver failed to set a configuration with a valid 
 **                     Configuration id
 ** 
 ** \param [in] Controller   CAN controller for which the status shall be changed
 ** \param [in] ConfigurationId   Requested Configuration
 */
extern FUNC(Std_ReturnType, AUTOMATIC) Can_SetIcomConfiguration
(
  VAR(uint8, AUTOMATIC) Controller,
  VAR(IcomConfigIdType, AUTOMATIC) ConfigurationId
);
#endif /* CAN_PUBLIC_ICOM_SUPPORT == STD_ON */

#if CAN_DEINIT_API == STD_ON
/** \brief Can_DeInit
 **
 ** This function deinitializes the module.
 **
 */
FUNC(void, AUTOMATIC) Can_DeInit(void);
#endif /* CAN_DEINIT_API == STD_ON */

#if CAN_CHECK_WAKEUP_API == STD_ON
/** \brief Can_CheckWakeup
 **
 ** This function checks if a wakeup has occurred for the given controller.
 **
 ** \return   CAN_OK: A wakeup was detected for the given controller.
 **           CAN_NOT_OK: No wakeup was detected for the given controller.
 ** \param [in] Controller   Controller to be checked for a wakeup.
 **
 */
extern FUNC(Can_ReturnType, AUTOMATIC) Can_CheckWakeup
(
  VAR(uint8, AUTOMATIC) Controller
);
#endif /* CAN_CHECK_WAKEUP_API == STD_ON */

#if CAN_GET_STATUS_API == STD_ON
/** \brief Can_GetStatus
 **
 ** Get additional status information related to a CAN controller.
 ** 
 ** This service is an extension to the AUTOSAR CAN Driver specification. It polls
 ** for error_passive and RX_Overflow and returns the state information, which may
 ** be required by the application.
 ** 
 ** If RX_Overflow is already detected, it shall be reported to error callout
 ** handler.
 ** If CAN_DEV_ERROR_DETECT equals STD_ON, the error is reported to DET module too.
 **
 ** \return   BitField containing following independent flags: **
 **           0x00: status is undefined (e.g. the conditions above have not
 **                 occurred, or CAN controller is not in state STARTED)
 **           CAN_STATUS_ERROR_PASSIVE: This flag is returned as long as the error
 **                                     counters of the CAN macro indicate that the
 **                                     controller is in the error passive state.
 **                                     The status is updated on every
 **                                     Can_GetStatus() call.
 **           CAN_STATUS_RX_OVERFLOW: The update of the internal state for
 **                                   Can_GetStatus() happens every time new
 **                                   data has been received by this controller
 **                                   and has been processed by the corresponding
 **                                   function (Can_MainFunction_Read() call in
 **                                   case of polling mode configuration, or on
 **                                   every CAN RX interrupt in case of IRQ mode
 **                                   configuration). This flag is only returned
 **                                   once, if during subsequent calls to
 **                                   Can_GetStatus() no new RX overflow condition
 **                                   occurred.
 ** \param [in] Controller   Get status of CAN controller identified by ID.
 **
 */
extern FUNC(uint8, AUTOMATIC) Can_GetStatus
(
  VAR(uint8, AUTOMATIC) Controller
);
#endif /* CAN_GET_STATUS_API == STD_ON */

#define CAN_STOP_SEC_CODE_ASIL_B

#include "Can_MemMap.h"

#endif /**defined(CAN_H_INCLUDED)*/

/*==================[end of file]===========================================*/
