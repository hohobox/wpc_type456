/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  FILE-NAME: IoHwAb_Cfg.h                                                   **
**                                                                            **
**  MODULE-NAME: AUTOSAR I/O Hardware Abstraction Module                      **
**                                                                            **
**  NOTE: This file is auto generated, do not edit this file manually.        **
**                                                                            **
********************************************************************************

********************************************************************************
**                      Generation Tool Information                           **
********************************************************************************
**  Tool Version: 1.15.4                                                       **
**                                                                            **
**  Change History: Refer log file (use -l option to generate log file)       **
**                                                                            **
********************************************************************************
**                      File Generation Information                           **
*******************************************************************************/
/*
 * INPUT FILE:    D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_IoHwAb.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Ecud_Os.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Adc.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Dio.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Gpt.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Icu.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Mcu.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Ocu.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Port.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Pwm.arxml
 *                D:\00_Project\95_WPC_TYPE5\trunk\03.SW_DESIGN\4.SW_Integration\1.GN7_PE\2.GN7_PE_WPC_APP\Configuration\ECU\Mcal\Ecud_Spi.arxml
 * GENERATED ON: The time-stamp is removed
 */

#ifndef IOHWAB_CFG_H
#define IOHWAB_CFG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Std_Types.h"
#include "IoHwAb_Types.h"
#include "Det.h"
#include "Rte_Type.h"
#include "Dio.h"
#include "Port.h"
#include "Adc.h"
#include "Gpt.h"
#include "Pwm.h"
#include "Dem.h"

/*******************************************************************************
**                      Common Published Information                          **
*******************************************************************************/
#define IOHWAB_AR_RELEASE_MAJOR_VERSION                    (4)
#define IOHWAB_AR_RELEASE_MINOR_VERSION                    (0)
#define IOHWAB_AR_RELEASE_REVISION_VERSION                 (3)
#define IOHWAB_SW_MAJOR_VERSION                            (1)
#define IOHWAB_SW_MINOR_VERSION                            (15)
#define IOHWAB_SW_PATCH_VERSION                            (4)
#define IOHWAB_VENDOR_ID                                   ((uint16)76)
#define IOHWAB_MODULE_ID                                   ((uint16)254)

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/* Pre-compile option for Development Error Checking */
#define IOHWAB_DEV_ERROR_DETECT                       (STD_ON)

/* Pre-compile option for Version Info API */
#define IOHWAB_VERSION_INFO_API                       (STD_OFF)

/* Pre-compile option for Digtal Direct */
#define IOHWAB_USE_DIG_DIR                            (STD_ON)

/* Pre-compile option for Analog Input Direct */
#define IOHWAB_USE_ANA_IN_DIR                         (STD_ON)

/* Pre-compile option for PWM */
#define IOHWAB_USE_PWM                                (STD_ON)

/* Pre-compile option for Gpt */
#define IOHWAB_USE_GPT                                (STD_ON)

/* Pre-compile option for Icu */
#define IOHWAB_USE_ICU                                (STD_OFF)

/* Pre-compile option for Ocu */
#define IOHWAB_USE_OCU                                (STD_OFF)

/* Pre-compile option for IO Manager */
#define IOHWAB_USE_IO_MAN                             (STD_ON)

/* Pre-compile option for FastTimer in IO Manager */
#define IOHWAB_USE_IO_MAN_FASTTIMER                   (STD_OFF)

/* Pre-compile option for GptTimer in IO Manager */
#define IOHWAB_USE_IO_MAN_GPTTIMER                    (STD_ON)

/* Pre-compile option for Analog Input */
#define IOHWAB_USE_ANA_IN                             (STD_OFF)

/* Pre-compile option for Digital Input */
#define IOHWAB_USE_DIG_IN                             (STD_OFF)

/* Pre-compile option for using MC33972 */
#define IOHWAB_USE_MC33972                            (STD_OFF)

/* Pre-compile option for external interrupt in MC33972 */
#define IOHWAB_MC33972_EXTINT                         (STD_OFF)

/* Pre-compile option for Digital Output */
#define IOHWAB_USE_DIG_OUT                            (STD_OFF)

/* Pre-compile option for using L9826 */
#define IOHWAB_USE_L9826                              (STD_OFF)

/* Pre-compile option for diagnosis info in L9826 */
#define IOHWAB_USE_L9826_DIAG                         (STD_OFF)

/* Pre-compile option for using L99MC6 */
#define IOHWAB_USE_L99MC6                             (STD_OFF)

/* Pre-compile option for using TLE7240SL */
#define IOHWAB_USE_TLE7240SL                          (STD_OFF)

/* Pre-compile option for diagnosis info in TLE7240SL */
#define IOHWAB_USE_TLE7240SL_DIAG                     (STD_OFF)

/* Pre-compile option for Input Supply Switch */
#define IOHWAB_USE_IN_SUP_SWT                         (STD_OFF)

/* Pre-compile option for Digital Supply Switch */
#define IOHWAB_USE_DIG_SUP_SWT                        (STD_OFF)

/* Pre-compile option for Digital Supply Switch in low power mode */
#define IOHWAB_USE_DIG_SUP_SWT_LP                     (STD_OFF)

/* Pre-compile option for Analog Supply Switch */
#define IOHWAB_USE_ANA_SUP_SWT                        (STD_OFF)

/* Pre-compile option for Voltage Monitoring */
#define IOHWAB_USE_VOL_MON                            (STD_OFF)

/* Pre-compile option for Low Power Flag */
#define IOHWAB_USE_LP_FLAG                            (STD_OFF)

/* Pre-compile option for Pm Module */
#define IOHWAB_USE_PM_MODULE                          (STD_OFF)

/* Pre-compile option for Dem Event Params */
#define IOHWAB_USE_DEM_EVENT                          (STD_ON)

/* Pre-compile option for Direct Access of Analog Input */
#define IOHWAB_USE_DIRECT_ACCESS_ANA_IN               (STD_OFF)


/* polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:begin<MISRA-C:9.14:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation */
/*******************************************************************************
**                      General                                               **
*******************************************************************************/
#define IOHWAB_MCAL_CYPRESS_CYT2B9XX                  

#define IOHWAB_GEN_NUM_PORT_PIN_CHS                   (21U)

#define IOHWAB_ADC_READDIRECT_MAX_DELAY               (10000U)

#define IOHWAB_E_BUSY                                 (DemConf_DemEventParameter_IOHWAB_E_BUSY)
#define IOHWAB_E_PROC_FAIL                            (DemConf_DemEventParameter_IOHWAB_E_PROC_FAIL)
#define IOHWAB_E_SETUP_FAIL                           (DemConf_DemEventParameter_IOHWAB_E_SETUP_FAIL)
#define IOHWAB_E_WRONG_PARAM                          (DemConf_DemEventParameter_IOHWAB_E_WRONG_PARAM)
#define IOHWAB_E_WRONG_SETTING                        (DemConf_DemEventParameter_IOHWAB_E_WRONG_SETTING)
#define IOHWAB_E_WRONG_STATE                          (DemConf_DemEventParameter_IOHWAB_E_WRONG_STATE)

typedef struct
{
  Dio_ChannelType ddDioChType;
  Port_PinType ddPortPinType;
  uint8 ucPolar;
  Port_PinDirectionType ddCfgPinDir;
}IoHwAb_GenInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_GenInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaGenInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Digital Direct                                        **
*******************************************************************************/
#define IOHWAB_DIGDIR_NUM_LGC                         (19U)

#define BCAN_EN                                       (0U)
#define BCAN_ERR                                      (1U)
#define BCAN_RX                                       (2U)
#define BCAN_STB                                      (3U)
#define FAN1_PULSE                                    (4U)
#define FAN2_PULSE                                    (5U)
#define LCAN_EN                                       (6U)
#define LCAN_ERR                                      (7U)
#define LCAN_RX                                       (8U)
#define LCAN_STB                                      (9U)
#define NFC1_IRQ                                      (10U)
#define NFC1_WAKEUP                                   (11U)
#define NFC2_IRQ                                      (12U)
#define NFC2_WAKEUP                                   (13U)
#define VBAT_CTRL                                     (14U)
#define VBAT_SW_CTRL                                  (15U)
#define VCC33_CTRL                                    (16U)
#define WDT_CLEAR_PULSE                               (17U)
#define WDT_EN                                        (18U)

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_IndexType, IOHWAB_CONST)IoHwAb_GaaDigDirChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
/* Array of words for bidirectional module direction info */
extern VAR(Port_PinDirectionType, IOHWAB_VAR)IoHwAb_GaaDigDirPinDir[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


/*******************************************************************************
**                      Analog Input Direct                                   **
*******************************************************************************/
#define IOHWAB_ANAINDIR_NUM_ADC_GROUPS                (2U)

#define IOHWAB_ANAINDIR_NUM_LGC                       (2U)

#define IOHWAB_ANAINDIR_MAX_BUF_LENGTH                (1U)

#define IGN1_ADC                                      (0U)
#define VBAT_ADC                                      (1U)

typedef struct
{
  Adc_GroupType ddAdcGroupType;
  uint8 ucAdcGroupLength;
  uint8 ucAdcHwUnitId;
  uint8 ucAdcHwUnitNum;
#if (IOHWAB_USE_ANA_IN == STD_ON)
  uint8 ucAdcAllGroupId;
#endif /* (IOHWAB_USE_ANA_IN == STD_ON) */
}IoHwAb_AnaInDirInfoPropertyType;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(IoHwAb_AnaInDirInfoPropertyType, IOHWAB_CONST)IoHwAb_GaaAnaInDirInfos[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


#define IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(Adc_ValueGroupType, IOHWAB_VAR)IoHwAb_GaaAnaInDirAdcResults[][IOHWAB_ANAINDIR_MAX_BUF_LENGTH];
#define IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      IO Manager                                            **
*******************************************************************************/
/* /Gpt/Gpt/GptChannelConfigSet_0/GptChannelConfiguration_IOManager */
#define IOHWAB_IOM_GPT_TIMER_ID                       (GptConf_GptChannelConfiguration_GptChannelConfiguration_IOManager)

#define IOHWAB_IOM_GPT_TICKS_FOR_1US                  (1U)

#define IOHWAB_IOM_TASK_FG1                           (OsTask_BSW_FG1_IOManager)

#define IOHWAB_IOM_TASK_FG2                           (OsTask_BSW_FG2_IOManager)

#define IOHWAB_IOM_TASK_FG1_FUNC                      TASK(OsTask_BSW_FG1_IOManager)

#define IOHWAB_IOM_TASK_FG2_FUNC                      TASK(OsTask_BSW_FG2_IOManager)

#define IOHWAB_IOM_MULTI_ACT_DELAY                    (200U)


/*******************************************************************************
**                      Analog Input                                          **
*******************************************************************************/
#define IOHWAB_ADCHWUNIT_MAX_NUM                      (1U)

#define IOHWAB_START_SEC_VAR_CLEARED_8
#include "MemMap.h"
extern VAR(boolean, IOHWAB_VAR)IoHwAb_GblAnaInAdcIsBusy[];
#define IOHWAB_STOP_SEC_VAR_CLEARED_8
#include "MemMap.h"


/*******************************************************************************
**                      Digital Input                                         **
*******************************************************************************/


/*******************************************************************************
**                      Digital Output                                        **
*******************************************************************************/


/*******************************************************************************
**                      Input Supply                                          **
*******************************************************************************/


/*******************************************************************************
**                      Voltage Monitoring                                    **
*******************************************************************************/


/*******************************************************************************
**                      ICU                                                   **
*******************************************************************************/


/*******************************************************************************
**                      GPT                                                   **
*******************************************************************************/
#define IOHWAB_GPT_TIME_ELAPSED_API                   (STD_ON)

#define IOHWAB_GPT_TIME_REMAINING_API                 (STD_ON)

#define IOHWAB_GPT_ENABLE_DISABLE_NOTIFICATION_API    (STD_ON)

#define IOHWAB_GPT_NUM_LGC                            (1U)

#define IoHwAbGptLogical_GptTest                      (0U)

/* Gpt_StartTimer */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_StartTimerFuncPtr)(Gpt_ChannelType, Gpt_ValueType);
extern Gpt_StartTimerFuncPtr IoHwAb_GpGptStartTimer;

/* Gpt_StopTimer */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_StopTimerFuncPtr)(Gpt_ChannelType);
extern Gpt_StopTimerFuncPtr IoHwAb_GpGptStopTimer;

/* Gpt_GetTimeElapsed */
typedef P2FUNC(Gpt_ValueType, IOHWAB_CODE, Gpt_GetTimeElapsedFuncPtr)(Gpt_ChannelType);
extern Gpt_GetTimeElapsedFuncPtr IoHwAb_GpGptGetTimeElapsed;

/* Gpt_GetTimeRemaining */
typedef P2FUNC(Gpt_ValueType, IOHWAB_CODE, Gpt_GetTimeRemainingFuncPtr)(Gpt_ChannelType);
extern Gpt_GetTimeRemainingFuncPtr IoHwAb_GpGptGetTimeRemaining;

/* Gpt_DisableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_DisableNotificationFuncPtr)(Gpt_ChannelType);
extern Gpt_DisableNotificationFuncPtr IoHwAb_GpGptDisableNotification;

/* Gpt_EnableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Gpt_EnableNotificationFuncPtr)(Gpt_ChannelType);
extern Gpt_EnableNotificationFuncPtr IoHwAb_GpGptEnableNotification;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Gpt_ChannelType, IOHWAB_CONST)IoHwAb_GaaGptChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      PWM                                                   **
*******************************************************************************/
#define IOHWAB_PWM_SET_DUTY_CYCLE_API                 (STD_ON)

#define IOHWAB_PWM_SET_PERIOD_AND_DUTY_API            (STD_ON)

#define IOHWAB_PWM_SET_OUTPUT_TO_IDLE_API             (STD_ON)

#define IOHWAB_PWM_GET_OUTPUT_STATE_API               (STD_ON)

#define IOHWAB_PWM_NOTIFICATION_SUPPORTED             (STD_ON)

#define IOHWAB_PWM_NUM_LGC                            (6U)

#define AmberIND1                                     (0U)
#define AmberIND2                                     (1U)
#define FANPWM1                                       (2U)
#define FANPWM2                                       (3U)
#define GreenIND1                                     (4U)
#define GreenIND2                                     (5U)

/* Pwm_SetDutyCycle */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetDutyCycleFuncPtr)(Pwm_ChannelType, uint16);
extern Pwm_SetDutyCycleFuncPtr IoHwAb_GpPwmSetDutyCycle;

/* Pwm_SetPeriodAndDuty */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetPeriodAndDutyFuncPtr)(Pwm_ChannelType, Pwm_PeriodType, uint16);
extern Pwm_SetPeriodAndDutyFuncPtr IoHwAb_GpPwmSetPeriodAndDuty;

/* Pwm_SetOutputToIdle */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_SetOutputToIdleFuncPtr)(Pwm_ChannelType);
extern Pwm_SetOutputToIdleFuncPtr IoHwAb_GpPwmSetOutputToIdle;

/* Pwm_GetOutputState */
typedef P2FUNC(Pwm_OutputStateType, IOHWAB_CODE, Pwm_GetOutputStateFuncPtr)(Pwm_ChannelType);
extern Pwm_GetOutputStateFuncPtr IoHwAb_GpPwmGetOutputState;

/* Pwm_DisableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_DisableNotificationFuncPtr)(Pwm_ChannelType);
extern Pwm_DisableNotificationFuncPtr IoHwAb_GpPwmDisableNotification;

/* Pwm_EnableNotification */
typedef P2FUNC(void, IOHWAB_CODE, Pwm_EnableNotificationFuncPtr)(Pwm_ChannelType, Pwm_EdgeNotificationType);
extern Pwm_EnableNotificationFuncPtr IoHwAb_GpPwmEnableNotification;

#define IOHWAB_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Pwm_ChannelType, IOHWAB_CONST)IoHwAb_GaaPwmChIdx[];
#define IOHWAB_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      OCU                                                   **
*******************************************************************************/


/*******************************************************************************
**                      ETC                                                   **
*******************************************************************************/
typedef struct
{
  /* 10ms Error, Recovery, Normal Counter */
  uint8 uc10msErrorCnt;
  uint8 uc10msRecoveryCnt;
  uint8 uc10msNormalCnt;

  /* ActivateTask, ChainTask */
  uint8 ucAcqEndToFG1;
  uint8 ucOnTimerToFG1;
  uint8 ucOnTimerToFG2;
  uint8 uc10msToFG2;
  uint8 ucFG1ToFG2;
  uint8 ucFG2ToFG1;

  /* Task, ISR, Function Called */
  uint8 uc10msCalled;
  uint8 ucFG1Called;
  uint8 ucFG2Called;
  uint8 ucConvertAllChannelsCalled;
  uint8 ucStartTimerCalled;
  uint8 ucOnTimerCalled;
  uint8 ucAllGrNfCalled[IOHWAB_ADCHWUNIT_MAX_NUM];
}IoHwAb_IOManagerCounterType;

#define IOHWAB_START_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"
extern VAR(IoHwAb_IOManagerCounterType, IOHWAB_VAR)IoHwAb_GstIOManagerCounter;
#define IOHWAB_STOP_SEC_VAR_CLEARED_UNSPECIFIED
#include "MemMap.h"


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/* polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:end<MISRA-C:9.14:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> No Impact of this rule violation */
#endif /* IOHWAB_CFG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
