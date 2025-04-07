/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*============================================================================*/
/*                     HYUNDAI AUTOEVER SOFTWARE GROUP                        */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================
 * C Source:         %CanCM.c%
 * Instance:         RPL_1
 * %version:         1.1 %
 * %created_by:      ca027 %
 * %date_created:    2014/01/21 19:18:42 %
 *============================================================================*/
/* DESCRIPTION : AUTOSAR CAN Communication Manager                            */
/*============================================================================*/
/* FUNCTION COMMENT : Definition for CanCM main functions                     */
/*============================================================================*/
/* COPYRIGHT (C) HYUNDAI AUTOEVER 2013                                        */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*  REVISION |   DATE      |   CR ID / TASK ID             |      AUTHOR      */
/*----------------------------------------------------------------------------*/
/* 0.9       | 8/Jul/2013  |   xar~150 / xar~623           |  Kyung-Tae Kim   */
/* - Initial Creation                                                         */
/*----------------------------------------------------------------------------*/
/* 0.9.1     | 25/Sep/2013 |   xar~150 / xar~623           |  Kyung-Tae Kim   */
/* - modification : interface with BswM                                       */
/* - addition : direct interface with CanIf to control transmission           */
/* - CanCM_ComModeIndication is invoked first in CanCM_MainFunction()         */
/* - Check Network Active before enabling Reception DM Monitoring             */
/*----------------------------------------------------------------------------*/
/* 0.9.2     | 20/Jan/2014 |   xar~150 / xar~623           |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.0       | 20/May/2014 |   #1008                       |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.0.1     |16/Feb/2015 |    #2336                       |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.1       | 2/Mar/2015 |    #2291                       |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.2       |16/Mar/2015 |    #2335                       |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.2.1     | 02/Apr/2015 |   #2413                       |  Kyung-Tae Kim   */
/*----------------------------------------------------------------------------*/
/* 1.2.2     | 13/Apr/2015 |   #247                         |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.3       | 20/Apr/2015 |   #2500                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4       | 24/Jul/2015 |   #2573 #2554 #2840 #2763      |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.1     | 24/Aug/2015 |   #2997                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.2     | 16/Sep/2015 |   #3155                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.3     | 21/Sep/2015 |   #2720                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.4     | 11/Nov/2015 |   #3196                         |  Kyung-Tae Kim */
/*----------------------------------------------------------------------------*/
/* 1.4.5     | 17/Dec/2015 |   #2997                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.6     | 17/Dec/2015 |   #3815                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.7     | 10/Jun/2016 |   #5027                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.4.8     | 29/Aug/2016 |   #5880                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.11    | 22/Aug/2017 |   #7980 #9410                  |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.12    | 06/Sep/2017 |   #6168 #8515                  |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.12.1  | 24/Aug/2018 |   #13761                       |  Jeong-Su Lim   */
/*----------------------------------------------------------------------------*/
/* 1.5.13    | 13/Feb/2019 |   #15997                       |  Jeong-Su Lim   */
/*----------------------------------------------------------------------------*/
/* 1.5.15    | 12/Jan/2021 |   #27561                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.16    | 31/Aug/2021 |   #31834                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.17    | 29/Sep/2021 |   #32224                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.18    | 24/Dec/2021 |   #33397                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.19    | 21/Apr/2022 |   #35113                       |  Min-Uk Kim     */
/*----------------------------------------------------------------------------*/
/* 1.5.20    | 12/Aug/2022 |   #36983                       |  Min-Uk Kim     */
/*============================================================================*/

#include "ComM.h"
#include "CanIf.h"
#include "CanCM.h"               /* CanCM header file */
#include "CanCM_Ram.h"           /* CanCM Global RAM variables header file */
#include "CanCM_PCTypes.h"       /* Pre-compile time header file */
#include "SchM_CanCM.h"          /* CanCM SchM header file */

#include "BswM.h"

#include "Std_Types.h"

/* polyspace-begin MISRA-C3:17.3 [Not a defect:Justified] "This function has visible prototype" */
#if (STD_ON == CANCM_DEV_ERROR_DETECT)
#include "CanCM_Error.h"         /* CanCM DET header file */
#endif

static FUNC(void, CANCM_CODE) CanCM_GetFilteredAdcValue(
  VAR(uint16, CANCM_VAR) PrevValue,
  VAR(uint16, CANCM_VAR) RawValue,
  P2VAR(uint16, AUTOMATIC, CANCM_VAR) Result);

#if  (STD_ON == CANCM_WAKEUP_SUPPORT)
static FUNC(void, CANCM_CODE) CanCM_CheckRemoteWakeup(
  CanCM_ChannelType CanCmChannelId);
#endif

static FUNC(void, CANCM_CODE) CanCM_ReadBattery(
  P2VAR(uint16, AUTOMATIC, CANCM_VAR) pusAdcValue);

#define CANCM_START_SEC_CODE
#include "MemMap.h"
/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */
FUNC(void, CANCM_CODE) CanCM_Init(void)
{
  uint8 LucCount;

  for (LucCount = CANCM_ZERO; LucCount < CANCM_NUMBER_OF_CHANNELS; LucCount++)
  {
    /* Initialize Timers */
    CanCM_GddNTimerCounter[LucCount] = CANCM_ZERO;
    CanCM_GddETimerCounter[LucCount] = CANCM_ZERO;
    CanCM_GddRTimerCounter[LucCount] = CANCM_ZERO;
    /* Initialize Internal Status Variable */
    CanCM_GunFlagStatus[LucCount].ucMaskByte = CANCM_ZERO;
    /* Initialize Current Voltage Mode */
    CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_NORMAL;
    /* Initialize Current Network State */
    CanCM_GddCommStat[LucCount] = CANCM_COMM_STAT_INACTIVE;
    /* Initially Report the error to DEM with event id and
    DEM_EVENT_STATUS_PASSED */
    #if (STD_ON == CANCM_DEM_STATUS)
    Dem_ReportErrorStatus(CanCM_GaaChannelConfig[LucCount].ddEventId,
                          (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED);
    #endif
  }
  CanCM_GddBatVolFailCnt = CANCM_ZERO;
  CanCM_GusAdcSampleCnt  = CANCM_ZERO;
#if (STD_ON == CANCM_DEV_ERROR_DETECT)
  CanCM_GblCanCMStatus = CANCM_INITIALISED;
#endif
}
/* polyspace-end MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */
FUNC(void, CANCM_CODE) CanCM_MainFunction(void)
{
  uint8 LucCount;
  #if (STD_ON == CANCM_DEV_ERROR_DETECT)
  if (CANCM_UNINITIALISED == CanCM_GblCanCMStatus)
  {
    (void)Det_ReportError(CANCM_MODULE_ID, CANCM_INSTANCE_ID, CANCM_MAINFUNCTION_SID, CANCM_E_UNINIT);
  }
  else
  #endif
  {
    if ((CanCM_GusAdcSampleCnt % CANCM_ADC_SAMPLE_MOD) == CANCM_ZERO)
    {
      /* Read battery voltage */
      CanCM_ReadBattery(&CanCM_GddBatVol);
    }
    CanCM_GusAdcSampleCnt++;

    for (LucCount = CANCM_ZERO; LucCount < CANCM_NUMBER_OF_CHANNELS;LucCount++)
    {
      /* Check Wakeup */
#if  (STD_ON == CANCM_WAKEUP_SUPPORT)
      if ((CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucWakChkEnabled == CANCM_ONE) &&
          (CanCM_GaaChannelConfig[LucCount].ddWakSrc!= CANCM_INVALID))
      {
        CanCM_CheckRemoteWakeup(LucCount);
      }
#endif
      SchM_Enter_CanCM_MAIN_PROTECTION();
      /* Check if Reception DM Start timer is running */
      if (CANCM_ZERO != CanCM_GddRTimerCounter[LucCount])
      {
        /* Decrement the counter */
        CanCM_GddRTimerCounter[LucCount]--;
        if ((CANCM_ZERO == CanCM_GddRTimerCounter[LucCount]) &&
            (CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucDtcDisabled != CANCM_ONE) &&
            (CANCM_COMM_STAT_ACTIVE == CanCM_GddCommStat[LucCount]))
        {
          /*Notify BswM to enable Reception Deadline Monitoring */
          BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                           (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_ENABLED);
        }
      }
      /* Check if Network Activation Timer is running */
      if (CANCM_ZERO != CanCM_GddNTimerCounter[LucCount])
      {
        /* Decrement Network Activation Timer */
        CanCM_GddNTimerCounter[LucCount]--;
        /* Check if Network Activation Timer is expired */
        if (CANCM_ZERO == CanCM_GddNTimerCounter[LucCount])
        {
          if (CANCM_ZERO == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucVolFailed)
          {
            /* Notify BswM for Network Activation */
            BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                             (BswM_ModeType)CANCM_COMM_STAT_TX_ENABLED);
            CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucTxDisabled = CANCM_ZERO;
          }
          /* Change current COMM state to ACTIVE */
          CanCM_GddCommStat[LucCount] = CANCM_COMM_STAT_ACTIVE;
        }
      }

      /* Check if Voltage Error Delay timer is running */
      if (CANCM_ZERO != CanCM_GddETimerCounter[LucCount])
      {
        /* Decrement the counter */
        CanCM_GddETimerCounter[LucCount]--;
        if ((CANCM_ZERO == CanCM_GddETimerCounter[LucCount]) &&
            (CANCM_VOL_MODE_CRITICAL != CanCM_GddVolMod[LucCount]))
        {
          /* Enable transmit ability of CanIf */
          if ((uint8) E_OK == CanIf_SetBatteryVoltageMode(CanCM_GaaChannelConfig[LucCount].ucCanIfCtrlId, 
                                                          CANIF_SET_BATVOL_NORMAL))
          {
            /* Clear Voltage Failed Flag */
            CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucVolFailed = CANCM_ZERO;
          #if (STD_ON == CANCM_DEM_STATUS)
            /* Report the error to DEM with event id and
            DEM_EVENT_STATUS_PASSED */
            Dem_ReportErrorStatus(CanCM_GaaChannelConfig[LucCount].ddEventId,
                                  (Dem_EventStatusType)DEM_EVENT_STATUS_PASSED);
          #endif

            /* NM & App message transmission should be enabled in 
               Network Active and Network Start only */
            if ((CANCM_COMM_STAT_ACTIVE == CanCM_GddCommStat[LucCount]) ||
                (CANCM_COMM_STAT_START == CanCM_GddCommStat[LucCount]))
            {
              if (CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucNmDisabled == CANCM_ONE)
              {
                /* Notify BswM to invoke Nm_EnableCommunication() */
                BswM_RequestMode((BswM_UserType)CanCMBswmMVolInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                                 (BswM_ModeType)CANCM_VOL_MODE_NORMAL);
                CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucNmDisabled = CANCM_ZERO;
              }
              /* Check if Network Activation Timer is running */
              if ((CANCM_ONE == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucTxDisabled) &&
                  (CANCM_ZERO == CanCM_GddNTimerCounter[LucCount]))
              {
                /* Notify BswM to enable CAN transmission */
                BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                                 (BswM_ModeType)CANCM_COMM_STAT_TX_ENABLED);
                CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucTxDisabled = CANCM_ZERO;
              }
            }
          }
        }
      }
      SchM_Exit_CanCM_MAIN_PROTECTION();

      /* Voltage check for turning off or on Com Deadline Monitoring on abnormal voltage */
      #if (STD_ON == CANCM_DISABLE_DM_ON_ABNOMAL_VOLTAGE)
      /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
      #if (STD_OFF == CANCM_MONITORING_ABNORMAL_VOLTAGE)
      if ((CANCM_ZERO == CanCM_GaaChannelConfig[LucCount].ddAbnormalUpper) &&
          (CANCM_ZERO == CanCM_GaaChannelConfig[LucCount].ddAbnormalLower))
      {
        /* #8515 */
        /* Do nothing */
      }
      #else
      if ((CanCM_GddBatVol < CanCM_GaaChannelConfig[LucCount].ddAbnormalUpper) &&
          (CanCM_GddBatVol > CanCM_GaaChannelConfig[LucCount].ddAbnormalLower))
      {
        #if (STD_ON == CANCM_HYSTERESIS_SUPPORT)
        if ((CanCM_GddBatVol < (CanCM_GaaChannelConfig[LucCount].ddAbnormalUpper - CanCM_GaaChannelConfig[LucCount].ddHysteresis)) &&
            (CanCM_GddBatVol > (CanCM_GaaChannelConfig[LucCount].ddAbnormalLower + CanCM_GaaChannelConfig[LucCount].ddHysteresis)))
        #endif
        {
          /* Current battery voltage is in normal range */
          CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_NORMAL;
		  SchM_Enter_CanCM_MAIN_PROTECTION();
          /* Check if recording DTC on signal timeout is disabled */
          if ((CANCM_ONE == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucDtcDisabled) &&
              (CANCM_ZERO == CanCM_GddRTimerCounter[LucCount]) &&
              (CANCM_COMM_STAT_INACTIVE != CanCM_GddCommStat[LucCount]) &&
              (CANCM_COMM_STAT_SHUTDOWN != CanCM_GddCommStat[LucCount]))
          {
            /*Notify BswM to enable Reception Deadline Monitoring */
            BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                             (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_ENABLED);
            CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucDtcDisabled = CANCM_ZERO;
            
          }
		  SchM_Exit_CanCM_MAIN_PROTECTION();
        }
      }
      else
      {
        if (CanCM_GddVolMod[LucCount] != CANCM_VOL_MODE_CRITICAL)
        {
          /* #6168 */
          /* Current battery voltage is not in normal range */
          CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_ABNORMAL;
        }
        /* Check if recording DTC on signal timeout is disabled */
        if (CANCM_ZERO == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucDtcDisabled) 
        {
          SchM_Enter_CanCM_MAIN_PROTECTION();
          /* Notify BswM to disable Reception Deadline Monitoring */
          if (CanCM_GddCommStat[LucCount] != CANCM_COMM_STAT_START)
          {
            BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                             (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_DISABLED);
          }
          CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucDtcDisabled = CANCM_ONE;
          SchM_Exit_CanCM_MAIN_PROTECTION();
        }
      }
      #endif
      /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
      #endif
      /* Voltage check for turning off or on Com Tx on critical voltage */
      /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
      #if (STD_OFF == CANCM_MONITORING_CRITICAL_VOLTAGE)
      if ((CANCM_ZERO == CanCM_GaaChannelConfig[LucCount].ddCriticalUpper) &&
          (CANCM_ZERO == CanCM_GaaChannelConfig[LucCount].ddCriticalLower))
      {
        /* #8515 */
        /* Do nothing */
      }
      #else
      if ((CanCM_GddBatVol > CanCM_GaaChannelConfig[LucCount].ddCriticalUpper) ||
               (CanCM_GddBatVol < CanCM_GaaChannelConfig[LucCount].ddCriticalLower))
      {
        /* current battery voltage is in critical range */
        CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_CRITICAL;
        /* Check if CAN transmission is disabled */
        if (CANCM_ZERO == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucVolFailed)
        {
          /* Increment battery voltage failure count */
          CanCM_GddBatVolFailCnt++;
          /*Notify BswM to disable CAN transmission */
          BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                           (BswM_ModeType)CANCM_COMM_STAT_TX_DISABLED);
          CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucTxDisabled = CANCM_ONE;
          /* Disable transmit ability of CanIf */
          if ((uint8)E_OK == CanIf_SetBatteryVoltageMode(CanCM_GaaChannelConfig[LucCount].ucCanIfCtrlId,
                                                         CANIF_SET_BATVOL_CRITICAL))
          {
            /* Set flag for battery voltage failure */
            CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucVolFailed = CANCM_ONE;
            /* Notify to DEM */
          #if (STD_ON == CANCM_DEM_STATUS)
            /* Report the error to DEM with event id and
            DEM_EVENT_STATUS_FAILED */
            Dem_ReportErrorStatus(CanCM_GaaChannelConfig[LucCount].ddEventId,
                                  (Dem_EventStatusType)DEM_EVENT_STATUS_FAILED);
          #endif
            BswM_RequestMode((BswM_UserType)CanCMBswmMVolInd(CanCM_GaaChannelConfig[LucCount].ucChannelId),
                             (BswM_ModeType)CANCM_VOL_MODE_CRITICAL);
            CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucNmDisabled = CANCM_ONE;
          }
        }
        /* Check if Voltage Error Timer is running */
        if (CANCM_ZERO != CanCM_GddETimerCounter[LucCount])
        {
          /* Stop Voltage Error Timer because
          voltage entered critical range again */
          CanCM_GddETimerCounter[LucCount] = CANCM_ZERO;
        }
      }
      else
      {
        /* current battery voltage is not in critical range */
        if ((CANCM_ONE == CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucVolFailed) &&
            (CANCM_ZERO == CanCM_GddETimerCounter[LucCount]))
        {
#if (STD_ON == CANCM_HYSTERESIS_SUPPORT)
          if ((CanCM_GddBatVol < (CanCM_GaaChannelConfig[LucCount].ddCriticalUpper - CanCM_GaaChannelConfig[LucCount].ddHysteresis)) &&
              (CanCM_GddBatVol > (CanCM_GaaChannelConfig[LucCount].ddCriticalLower + CanCM_GaaChannelConfig[LucCount].ddHysteresis)))
#endif
          {
#if (STD_OFF == CANCM_DISABLE_DM_ON_ABNOMAL_VOLTAGE)
            /* Current battery voltage is in normal range */
            CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_NORMAL;
#else 
            /* #6168 */
            /* Current battery voltage is in abnormal range */
            CanCM_GddVolMod[LucCount] = CANCM_VOL_MODE_ABNORMAL;
#endif
            /* Start Voltage Error Timer */
            CanCM_GddETimerCounter[LucCount] =
            CanCM_GaaChannelConfig[LucCount].ddDelayTimeCritical;
          }
        }
      }
      #endif
      /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
    }
  }  
}
/* polyspace-end MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */

/* polyspace:begin<RTE: IDP : Not a defect : No Action Planned > 
                                        Its boundary is pre-defined           */

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */
FUNC(Std_ReturnType, CANCM_CODE) CanCM_GetCurrentVoltageMode(
  CanCM_ChannelType CanCmChannelId,
  P2VAR(CanCM_VolModType, AUTOMATIC, CANCM_APPL_DATA) VolModePtr)
{
  uint8 LucCount;
  VAR(Std_ReturnType, CANCM_VAR) LenStdRetVal;

  LenStdRetVal = E_OK;
  /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
  *VolModePtr = CANCM_VOL_MODE_UNDEFINED;

#if (STD_ON == CANCM_DEV_ERROR_DETECT)
  if (CANCM_UNINITIALISED == CanCM_GblCanCMStatus)
  {
    (void)Det_ReportError(CANCM_MODULE_ID, CANCM_INSTANCE_ID, CANCM_GETCURRENTVOLTAGEMODE_SID, CANCM_E_UNINIT);
    LenStdRetVal = E_NOT_OK;
  }
  else
#endif
  {
    for (LucCount = CANCM_ZERO; LucCount < CANCM_NUMBER_OF_CHANNELS; LucCount++)
    {
      if (CanCM_GaaChannelConfig[LucCount].ucChannelId == CanCmChannelId)
      {
        if (CanCM_GddETimerCounter[LucCount] != CANCM_ZERO)
        {
          /* #6168 */
          /* Current mode is CRITICAL because it is waiting to change 
             to NON-CRITICAL */
          *VolModePtr = CANCM_VOL_MODE_CRITICAL;
        }
        else{
          *VolModePtr = CanCM_GddVolMod[LucCount];
        }
      }
    }
  }
  
  if (*VolModePtr == CANCM_VOL_MODE_UNDEFINED)
  {
    LenStdRetVal = E_NOT_OK;
  }
  
  return LenStdRetVal;
}

FUNC(Std_ReturnType, CANCM_CODE) CanCM_GetCurrentNetworkState(
  NetworkHandleType CanCmChannelId,
  P2VAR(CanCM_CommStatType, AUTOMATIC, CANCM_APPL_DATA) CommStatPtr)
{
  VAR(Std_ReturnType, CANCM_VAR) LenStdRetVal = E_NOT_OK;
  uint8 LucCount;

#if (STD_ON == CANCM_DEV_ERROR_DETECT)
  if (CANCM_UNINITIALISED == CanCM_GblCanCMStatus)
  {
    (void)Det_ReportError(CANCM_MODULE_ID, CANCM_INSTANCE_ID, CANCM_GETCURRENTNETWORKSTATE_SID, CANCM_E_UNINIT);
  }
  else
#endif
  {
    for (LucCount = CANCM_ZERO; LucCount < CANCM_NUMBER_OF_CHANNELS; LucCount++)
    {
      if (CanCM_GaaChannelConfig[LucCount].ucChannelId == CanCmChannelId)
      {
        /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
        *CommStatPtr = CanCM_GddCommStat[LucCount];
        LenStdRetVal = E_OK;
      }
    }
  }
  
  return LenStdRetVal;
}
/* polyspace-end MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */


/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */
FUNC(void, CANCM_CODE) CanCM_GetVoltageFailCount(
  P2VAR(uint16, AUTOMATIC, CANCM_APPL_DATA) CountPtr)
{
  if (CountPtr != NULL_PTR)
  {
    /* polyspace +1 MISRA-C3:D4.14 [Not a defect: Justified] "Pointer is not a NULL and valid" */
    *CountPtr = CanCM_GddBatVolFailCnt;
  }
}
/* polyspace-end MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */


static FUNC(void, CANCM_CODE) CanCM_ReadBattery(
  P2VAR(uint16, AUTOMATIC, CANCM_VAR) pusAdcValue)
{
  VAR(IoHwAb_ValueType, CANCM_VAR) LddIoHwAbAdcValue = CANCM_ZERO;
  VAR(uint8, CANCM_VAR) LucCount;
  VAR(boolean, CANCM_VAR) LblNeedUpdate = CANCM_FALSE;

  for(LucCount = CANCM_ZERO; LucCount < CanCM_GddNumOfAdcGrp ;LucCount++)
  {
    VAR(IoHwAb_ValueType, CANCM_VAR) LddTempValue = CANCM_ZERO;
    
    /* polyspace<MISRA-C:8.1,10.1,8.4:Not a defect:Justify with annotations> No Impact of this rule violation */
    /* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > Its boundary is pre-defined */
    /* polyspace +1 MISRA-C3:8.2 [Not a defect:Justfied] "This is matched to function definition." */
    if (E_OK == IoHwAb_AnaInDirReadDirect((IoHwAb_IndexType)CanCM_GaaCanCMAdcGroup[LucCount],
                                          &LddTempValue,
                                          1))
    {
      (void)CanCM_GetFilteredAdcValue(CanCM_GaaCanCMAdcGroupVal[LucCount], 
                                      LddTempValue,
                                      &CanCM_GaaCanCMAdcGroupVal[LucCount]);
                                      
      if (LddIoHwAbAdcValue < CanCM_GaaCanCMAdcGroupVal[LucCount])
      {
        LddIoHwAbAdcValue = CanCM_GaaCanCMAdcGroupVal[LucCount];
      }
      
      LblNeedUpdate = CANCM_TRUE;
    }
    else
    {
#if (STD_ON == CANCM_DEV_ERROR_DETECT)
      /* polyspace +1 MISRA-C3:8.5 [Not a defect:Justfied] "No impact of this rule" */
      (void)Det_ReportError(CANCM_MODULE_ID,
                            CANCM_INSTANCE_ID,
                            CANCM_MAINFUNCTION_SID,
                            CANCM_E_READBATTERYFAIL);
#endif
    }
    /* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > Its boundary is pre-defined */
  }
  
  if (CANCM_TRUE == LblNeedUpdate)
  {
    *pusAdcValue = LddIoHwAbAdcValue;
  }
}

static FUNC(void, CANCM_CODE) CanCM_GetFilteredAdcValue(
  VAR(uint16, CANCM_VAR) PrevValue,
  VAR(uint16, CANCM_VAR) RawValue, 
  P2VAR(uint16, AUTOMATIC, CANCM_VAR) Result)
{
  if (PrevValue >= RawValue)
  {
    *Result = RawValue + (uint16)((((uint32)PrevValue - (uint32)RawValue) * (uint32)CanCM_GucFiltConst ) >> 8);
  }
  else
  {
    *Result = RawValue - (uint16)((((uint32)RawValue - (uint32)PrevValue) * (uint32)CanCM_GucFiltConst ) >> 8);
  }
}

#if  (STD_ON == CANCM_WAKEUP_SUPPORT)
static FUNC(void, CANCM_CODE) CanCM_CheckRemoteWakeup(
  CanCM_ChannelType CanCmChannelId)
{
  IoHwAb_LevelType LddVal;

  LddVal = CANCM_ZERO;
  /*  polyspace<MISRA-C:8.1,10.1:Not a defect:Justify with annotations> No Impact of this rule violation */    
  (void)IoHwAb_DigDirReadDirect((IoHwAb_IndexType)CanCM_GaaChannelConfig[CanCmChannelId].ddWakPin, &LddVal);
  if (CANCM_ZERO == (uint8)LddVal)
  {
    CanCM_GunFlagStatus[CanCmChannelId].ddBitByteRecord.ucWakEvt = CANCM_ONE;
    (void)EcuM_CheckWakeup(CanCM_GaaChannelConfig[CanCmChannelId].ddWakSrc);
  }
  else
  {
    /* Nothing to do */
  }
}
/* polyspace:end<RTE: IDP : Not a defect : No Action Planned > Its boundary is pre-defined */
FUNC(void, CANCM_CODE) CanCM_CheckWakeup(
  EcuM_WakeupSourceType source)
{
  uint8 LucCount;
  IoHwAb_LevelType LddVal;
  
  LddVal = CANCM_ZERO;
  for (LucCount = CANCM_ZERO; LucCount < CANCM_NUMBER_OF_CHANNELS; LucCount++)
  {
    if ((CanCM_GaaChannelConfig[LucCount].ddWakSrc == source) &&
        (CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucWakEvt == CANCM_ONE))
    {
      CanCM_GunFlagStatus[LucCount].ddBitByteRecord.ucWakEvt = CANCM_ZERO;
      /*  polyspace:begin<MISRA-C:8.1,10.1:Not a defect:Justify with annotations> No Impact of this rule violation */    
      (void)IoHwAb_DigDirReadDirect((IoHwAb_IndexType)CanCM_GaaChannelConfig[LucCount].ddWakPin, &LddVal);
      /*  polyspace:end<MISRA-C:8.1,10.1:Not a defect:Justify with annotations> No Impact of this rule violation */    
      if (CANCM_ZERO == (uint8)LddVal)
      {
        (void)EcuM_SetWakeupEvent(source);
        (void)EcuM_ClearWakeupEvent(source);
      }
      else
      {
        /* Nothing to do */
      }
    }
    else
    {
      /* Nothing to do */
    }
  }
}
#endif

#define CANCM_STOP_SEC_CODE
#include "MemMap.h"

/* polyspace-end MISRA-C3:17.3 [Not a defect:Justified] "This function has visible prototype" */
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */

