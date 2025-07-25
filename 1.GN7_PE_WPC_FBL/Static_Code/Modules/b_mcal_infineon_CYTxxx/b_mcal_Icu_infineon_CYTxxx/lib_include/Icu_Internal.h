#ifndef ICU_INTERNAL_H
#define ICU_INTERNAL_H
/** \file Icu_Internal.h
 ** \brief AUTOSAR Icu ICU Driver
 **
 ** This file contains all architecture dependent Icu driver internal data
 ** and includes the needed derivative specifics.
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
#include <Icu_Types.h>
/*==================[macros]=================================================*/

/*==================[external function declarations]=========================*/

#define ICU_START_SEC_CODE_ASIL_B
#include <Icu_MemMap.h>

/** \brief Icu_CheckConfigPtr
 **
 **  This function checks the pointer of the configuration set.
 **
 **
 ** \param[in] ChannelPtr  Pointer of data stored configuration set information.
 **
 ** \return    If parameter ConfigPtr is a valid config set pointer, 
 **            return TRUE, else return FALSE.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckConfigPtr
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr
);

/** \brief Icu_DemReportEvent
 **
 ** This function implements to report DEM error.
 **
 **
 ** \return None.
 ** \param [in] ApiId       The type of Api id.
 ** \param [in] EventId     The type of event id.
 ** \param [in] EventStatus The status of event.
 **
 ** \return     None.
 */
extern FUNC(void, ICU_CODE) Icu_DemReportEvent
(
  VAR(uint8, AUTOMATIC) ApiId,
  VAR(uint8, AUTOMATIC) EventId,
  VAR(uint8, AUTOMATIC) EventStatus
);

/** \brief Icu_EnterCritiSec
 **
 ** This function enters exclusive area (call SchM module).
 **
 **
 ** \param[in] None.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_EnterCritiSec(void);

/** \brief Icu_ExitCritiSec
 **
 ** This function exits exclusive area (call SchM module).
 **
 **
 ** \param[in] None.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_ExitCritiSec(void);

/** \brief Icu_InitChannelState
 **
 ** This function initializes the extension state of configured each channel.
 **
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 **
 ** \return     None.
 ** */
extern FUNC(void, ICU_CODE) Icu_InitChannelState
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);

/** \brief Icu_Isr_Vector_Internal
 **
 ** Internal service of ICU interrupt routine.
 **
 ** \param[in] BaseAddress   Base address of channel.
 ** \param[in] ResourceIndex Logic resource index of TCPWM/GPIO channel
 **                          (defined by software generate source).
 ** \param[in] ResourceId    Physical resource identifier of GPIO channel
 **                          (read from property file).
 **                          For TCPWM channel, the value of this parameter
 **                          shall be always ICU_INVALID_RESOURCEID.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE)Icu_Isr_Vector_Internal
(
  volatile P2VAR(uint32, ICU_CONST, REGSPACE) BaseAddress,
  VAR(uint16, AUTOMATIC)                      ResourceIndex,
  VAR(uint16, AUTOMATIC)                      ResourceId
);

/** \brief Icu_DwIsr_Vector_Internal
 **
 ** Internal function of the DataWire ISR.
 **
 ** \param[in] BaseAddress   Base address of channel.
 ** \param[in] ResourceIndex Resource index of TCPWM peripheral.
 ** 
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE)Icu_DwIsr_Vector_Internal
(
  volatile P2VAR(Icu_DataWireRegType, ICU_CONST, REGSPACE) BaseAddress,
  VAR(uint16, AUTOMATIC)                                   ResourceIndex
);

/** \brief Icu_Init_Internal
 **
 ** This function initializes all configured channels of the ICU module.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_Init_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr
);

/** \brief Icu_DeInit_Internal
 **
 ** This function does the de-initialization of the ICU module.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_DeInit_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr
);

/** \brief Icu_SetMode_Internal
 **
 ** This function implements to set the mode of ICU module.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 ** \param[in] Mode        ICU_MODE_NORMAL: Normal operation, all used interrupts
 **                        are enabled according to the notification requests.
 **                        ICU_MODE_SLEEP: Reduced power mode. In sleep mode
 **                        only those notifications are available which are
 **                        configured as wakeup capable.
 ** \param[in] AcceptInSetMode   Acceptance of wakeup signal.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_SetMode_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  VAR(Icu_ModeType, AUTOMATIC)                       Mode,
  VAR(boolean, AUTOMATIC)                            AcceptInSetMode
);

/** \brief Icu_CheckWakeup_Internal
 **
 ** This function implements to check the wake-up capability of a channel.
 **
 ** \param[in] ConfigPtr    Configuration pointer to config data.
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 **
 ** \return    Return whether wakeup is detected.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckWakeup_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);

/** \brief Icu_StartGroup_Internal
 **
 ** This function starts group channel.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 ** \param[in] Group       Numeric identifier of the ICU channel group.
 **
 ** \return    none
 ** */
extern FUNC(void, ICU_CODE) Icu_StartGroup_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  VAR(Icu_GroupType, AUTOMATIC)                      Group
);

/** \brief Icu_StopGroup_Internal
 **
 ** This function stops group channel.
 **
 ** \param[in] ConfigPtr        Configuration pointer to config data.
 ** \param[in] Group            Numeric identifier of the ICU channel group.
 ** \param[in] WaitingTrigger   Whether channels of group are waiting trigger or not.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_StopGroup_Internal
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  VAR(Icu_GroupType, AUTOMATIC)                      Group,
  VAR(boolean, AUTOMATIC)                            WaitingTrigger
);

/** \brief Icu_CheckGroupChannels
 **
 ** This function implements to check group start condition.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 ** \param[in] Group       Numeric identifier of the ICU channel group.
 **
 ** \return    Returns group start condition is TRUE or FALSE.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckGroupChannels
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  VAR(Icu_GroupType, AUTOMATIC)                      Group
);

/** \brief Icu_CheckNewMeas
 **
 ** This function checks whether the new capture event occurred.
 ** Updates measurement information for Icu_GetInputState/Icu_GetDutyCycleValues/Icu_GetTimeElapsed.
 **
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 **
 ** \return    None.
 **
 ** */
extern FUNC(void, ICU_CODE) Icu_CheckNewMeas
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);

/** \brief Icu_UpdateInputState
 **
 ** This function updates the input state of a channel in edge detection mode.
 **
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 **
 ** \return    None.
 **
 ** */
extern FUNC(void, ICU_CODE) Icu_UpdateInputState
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);

/** \brief Icu_ClearIsr_Internal
 **
 ** This function implements to clear interrupt flag.
 **
 ** \param[in] BaseAddress    Base address of channel.
 ** \param[in] ResourceId     Resource Id. It is not used in TCPWM.
 **                           It is read from properties file.
 ** \param[in] IntrClrFlag    Interrupt clear flag.
 **
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE)Icu_ClearIsr_Internal
(
  volatile P2VAR(uint32, ICU_CONST, REGSPACE) BaseAddress,
  VAR(Icu_ResourceType, AUTOMATIC)            ResourceId,
  VAR(uint8, AUTOMATIC)                       IntrClrFlag
);

/** \brief Icu_ClearDwIsr_Internal
 **
 ** This function implements to clear DataWire interrupt flag.
 **
 ** \param[in] BaseAddress Base address of channel.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE)Icu_ClearDwIsr_Internal
(
  volatile P2VAR(Icu_DataWireRegType, ICU_CONST, REGSPACE) BaseAddress
);


/** \brief Icu_StartGroupChannel
 **
 ** This function starts group channel.
 **
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 ** \param[in] ChannelCtrl  Control the channel start or no start.
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_StartGroupChannel
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  VAR(Icu_ChannelCtrlType, AUTOMATIC) ChannelCtrl
);

/** \brief Icu_StopGroupChannel
 **
 ** This function stops group channel.
 **
 ** \param[in] ChannelPtr   Pointer to the channel configuration.
 ** \param[in] ChannelCtrl  Control the channel stop or no stop.
 ** 
 **
 ** \return    None.
 ** */
extern FUNC(void, ICU_CODE) Icu_StopGroupChannel
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  VAR(Icu_ChannelCtrlType, AUTOMATIC)                       ChannelCtrl
);

/** \brief Icu_GetChannelStatus
 **
 ** This function gets the channel status each channel for checking.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 ** \param[out] CheckChannelStatusPtr  Pointer to return the internal state.
 **
 ** \return     None.
 ** */
extern FUNC(void, ICU_CODE) Icu_GetChannelStatus
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  P2VAR  (Icu_CheckChannelStatusType, AUTOMATIC, ICU_APPL_DATA) CheckChannelStatusPtr
);

/** \brief Icu_CheckDMAChannelStatus
 **
 ** This function check DW channel status.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 ** \param[in]  DriverState  Current driver initial state.
 **
 ** \return     Return DW channel status.
 **             TRUE:  Channel status is valid. 
 **             FALSE: Channel status is invalid.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckDMAChannelStatus
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  VAR(Icu_DriverStatusType, AUTOMATIC)                      DriverState
);

/** \brief Icu_InitDMAChannel
 **
 ** This function initialize or de-initializes DW channel.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 ** \param[in]  InitFlag     Initializes or de-initializes DW.
 **
 ** \return     None.
 ** */
extern FUNC(void, ICU_CODE) Icu_InitDMAChannel
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  VAR(boolean, AUTOMATIC) InitFlag
);

/** \brief Icu_InitDMAChannel_Internal
 **
 ** This function initializes or de-initializes DW channel.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 ** \param[in]  InitFlag     Initializes or de-initializes DW.
 **
 ** \return     None.
 ** */
extern FUNC(void, ICU_CODE) Icu_InitDMAChannel_Internal
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr,
  VAR(boolean, AUTOMATIC)                                   InitFlag
);


/** \brief Icu_WakeupOverflowInterrupt
 **
 ** This function wakes up overflow interrupt of channel.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 **
 ** \return     None.
 ** */
extern FUNC(void, ICU_CODE)Icu_WakeupOverflowInterrupt
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);


/** \brief Icu_CheckGroupChannelsWaitTrigger
 **
 ** This function implements to check if channels of group are waiting trigger.
 **
 ** \param[in] ConfigPtr   Configuration pointer to config data.
 ** \param[in] Group       Numeric identifier of the ICU channel group.
 **
 ** \return    Returns channels of group are waiting trigger or not.
 **            TRUE:  channels are waiting trigger.
 **            FALSE: channels aren't waiting trigger.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckGroupChannelsWaitTrigger
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr,
  VAR(Icu_GroupType, AUTOMATIC)                      Group
);

/** \brief Icu_CheckChannelHWstatus
 **
 ** This function checks whether HW status match SW status.
 **
 ** \param[in]  ChannelPtr   Pointer to the channel configuration.
 **
 ** \return     Returns channel is waiting trigger or not.
 **             TRUE:  HW status matches SW status.
 **             FALSE: HW status doesn't match SW status.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckChannelHWstatus
(
  P2CONST(Icu_ChannelConfigType, AUTOMATIC, ICU_APPL_CONST) ChannelPtr
);

/** \brief Icu_CheckWaitTrigger
 **
 ** This function checks whether driver is waiting trigger.
 **
 **
 ** \param[in] ConfigPtr Configuration pointer to config data.
 **
 ** \return    Returns channels of configuration are waiting trigger or not.
 **            TRUE:  channels are waiting trigger.
 **            FALSE: channels aren't waiting trigger.
 ** */
extern FUNC(boolean, ICU_CODE) Icu_CheckWaitTrigger
(
  P2CONST(Icu_ConfigType, AUTOMATIC, ICU_APPL_CONST) ConfigPtr
);


#define ICU_STOP_SEC_CODE_ASIL_B
#include <Icu_MemMap.h>
/*==================[internal constants]=====================================*/

/*==================[external data]==========================================*/

/*==================[internal data]==========================================*/

/*==================[external function definitions]==========================*/

/*==================[internal function definitions]==========================*/
#endif/* ifndef ICU_INTERNAL_H */
/*==================[end of file]============================================*/
