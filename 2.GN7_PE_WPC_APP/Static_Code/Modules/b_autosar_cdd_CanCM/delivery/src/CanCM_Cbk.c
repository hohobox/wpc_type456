/* polyspace:begin<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */
/*============================================================================*/
/*                     HYUNDAI AUTOEVER SOFTWARE GROUP                        */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================
 * C Source:         %CanCM_Cbk.c%
 * Instance:         RPL_1
 * %version:         0.9.2 %
 * %created_by:      ca027 %
 * %date_created:    2014/01/21 19:05:14 %
 *============================================================================*/
/* DESCRIPTION : AUTOSAR CAN Communication Manager                            */
/*============================================================================*/
/* FUNCTION COMMENT : Definition for CanCM Callback Functions                 */
/*============================================================================*/
/* COPYRIGHT (C) HYUNDAI AUTOEVER 2012                                        */
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
/*  REVISION |   DATE      |    CR ID / TASK ID             |      AUTHOR     */
/*----------------------------------------------------------------------------*/
/* 0.9       | 18/Jul/2013 |   xar~150 / xar~623            |  Kyung-Tae Kim  */
/* - Initial Draft                                                            */
/*----------------------------------------------------------------------------*/
/* 0.9.1     | 04/Nov/2013 |   xar~150 / xar~623            |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 0.9.2     | 20/Jan/2014 |   xar~150 / xar~623            |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.0       | 14/May/2014 |   Redmine Bug #921             |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.1       | 12/Jan/2015 |   Redmine Bug #921             |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2       | 16/Mar/2015 |   Improvement #2335            |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.2     | 13/Apr/2015 |   Improvement #247             |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.3     | 24/Aug/2015 |   Improvement  #2997           |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.4     | 16/Sep/2015 |   Feature #3155                |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.5     | 21/Sep/2015 |   Improvement #2720            |  Kyung-Tae Kim  */
/* - Changed BswM Interface                                                   */
/*----------------------------------------------------------------------------*/
/* 1.2.6     | 21/Sep/2015 |   Improvement #3254            |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.7     | 21/Sep/2015 |   #4743                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.2.8     | 22/Jun/2016 |   #5276                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.11    | 22/Aug/2017 |   #7980                        |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.12    | 21/Dec/2017 |   #10378                       |  Kyung-Tae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.13    | 13/Feb/2019 |   #15997                       |  Jeong-Su Lim   */
/*----------------------------------------------------------------------------*/
/* 1.5.14    | 27/Oct/2020 |   #25765                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.15    | 12/Jan/2021 |   #27561                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.16    | 31/Aug/2021 |   #31834                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.18    | 24/Dec/2021 |   #33397                       |  Seung-Jae Kim  */
/*----------------------------------------------------------------------------*/
/* 1.5.19    | 21/Apr/2022 |   #35113                       |  Min-Uk Kim     */
/*----------------------------------------------------------------------------*/
/* 1.5.20    | 12/Aug/2022 |   #36983                       |  Min-Uk Kim     */
/*============================================================================*/

#include "ComM.h"
#include "CanCM.h"            /* CanCM APIs header file */
#include "CanCM_Ram.h"        /* Global RAM variables header file */
#include "CanCM_PCTypes.h"
#include "CanCM_Cbk.h"
#include "BswM.h"
/* polyspace-begin MISRA-C3:17.3 [Not a defect:Justified] "This function has visible prototype" */
/* polyspace:begin<RTE: OBAI : Not a defect : No Action Planned > 
                                        Its boundary is pre-defined           */
#define CANCM_START_SEC_CODE
#include "MemMap.h"

/* polyspace-begin MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */
FUNC(void, CANCM_CODE) CanCM_ComModeIndication (
  NetworkHandleType ComMChannelId,
  ComM_ModeType comm_state)
{
  if (ComMChannelId >= COMM_TOTAL_CHANNELS)
  {
#if (STD_ON == CANCM_DEV_ERROR_DETECT)
          (void)Det_ReportError(CANCM_MODULE_ID,
                                CANCM_INSTANCE_ID,
                                CANCM_COMMODEINDICATION_SID,
                                CANCM_E_INVALID_REQUEST);
#endif
  }
  else
  {
    NetworkHandleType LucChannelIndex;
    LucChannelIndex = CanCM_GaaCanCMComMChannelMap[ComMChannelId];
    /* polyspace-begin CERT-C:MSC12-C [Not a defect:Justified] "The value is generated by Generator." */
    /* polyspace-begin MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
    if (LucChannelIndex == (NetworkHandleType)CANCM_INVALID_CHANNEL)
    {
      /* Do nothing because channel is invalid */
    }
    /* polyspace-end MISRA-C3:14.3,2.1, DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
    /* polyspace-end CERT-C:MSC12-C [Not a defect:Justified] "The value is generated by Generator." */
    else if (comm_state == COMM_NO_COMMUNICATION)
    {
#if  (STD_ON == CANCM_WAKEUP_SUPPORT)
      CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucWakChkEnabled = CANCM_ONE;
#endif
      if (CANCM_COMM_STAT_SHUTDOWN  == CanCM_GddCommStat[LucChannelIndex])
      {
        /* CAN Network is in Bus Sleep Mode */
        CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_INACTIVE;
        /* reset Reception DM Start timer */
        CanCM_GddRTimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* Disable reception for Com module */
        BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_RX_DISABLED);
        
      }
      else if (CANCM_COMM_STAT_INACTIVE != CanCM_GddCommStat[LucChannelIndex])
      {
        /* CAN Network is in Bus Sleep Mode */
        CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_INACTIVE;
        /* Network is switched into Network Inactive without touching *
        *  Network Shutdown                                           *
        *  Reset Reception DM Start timer                             */
        CanCM_GddRTimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* reset Network Activation timer */
        CanCM_GddNTimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* reset Voltage Error Delay timer */
        CanCM_GddETimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* Disable reception for Com module */
        BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_RX_DISABLED);
        /* Disable Com transmission */
        BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_TX_DISABLED);
        CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucTxDisabled = CANCM_ONE;
      }
      else
      {
        /* Do nothing */
      }
    }
    else if (comm_state == COMM_SILENT_COMMUNICATION)
    {
      if (CANCM_COMM_STAT_ACTIVE == CanCM_GddCommStat[LucChannelIndex])
      {
        CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_SHUTDOWN;
        /* reset Network Activation timer */
        CanCM_GddNTimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* reset Voltage Error Delay timer */
        CanCM_GddETimerCounter[LucChannelIndex] = CANCM_ZERO;
        /* Disable Com transmission */
        BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_TX_DISABLED);
        CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucTxDisabled = CANCM_ONE;
        BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_DISABLED);
      }
    }
    else if (comm_state == COMM_FULL_COMMUNICATION)
    {
#if  (STD_ON == CANCM_WAKEUP_SUPPORT)
      CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucWakChkEnabled = CANCM_ZERO;
#endif
      if ((CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucNmDisabled == CANCM_ONE) &&
          (CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucVolFailed == CANCM_ZERO))
      {
        /* Nm could not be enabled because voltage was recovered during
           Network Shutdown or Inactive */
        /* Notify BswM to invoke Nm_EnableCommunication() */
        BswM_RequestMode((BswM_UserType)CanCMBswmMVolInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_VOL_MODE_NORMAL);
        CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucNmDisabled = CANCM_ZERO;     
      }
      
      if (CANCM_COMM_STAT_SHUTDOWN == CanCM_GddCommStat[LucChannelIndex])
      {
        /* Change current COMM state to ACTIVE */
        CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_ACTIVE;
        /* Transition to Network Inactive has been canceled.
           Notify BswM for Network Activation                 */
        BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_TX_ENABLED);
        CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucTxDisabled = CANCM_ZERO;
        if (CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucDtcDisabled == CANCM_ZERO)  
        {
          /*Notify BswM to enable Reception Deadline Monitoring */
          BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                           (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_ENABLED);
        }
      }
      else if (CANCM_COMM_STAT_INACTIVE == CanCM_GddCommStat[LucChannelIndex])
      {
        /* Change Current Network State */
        CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_START;
        /* Network Activation Timer shall be started */
        CanCM_GddNTimerCounter[LucChannelIndex] = CanCM_GaaChannelConfig[LucChannelIndex].ddActivationTime;
        /* Notify BswM for Com Reception to be enabled */
        BswM_RequestMode((BswM_UserType)CanCMBswmMRxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
                         (BswM_ModeType)CANCM_COMM_STAT_RX_ENABLED_DM_DISABLED);
		/* polyspace-begin MISRA-C3:14.3,2.1 [Not a defect:Justified] "The value is generated by Generator." */
		/* polyspace-begin DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
		if (CANCM_ZERO == CanCM_GddNTimerCounter[LucChannelIndex])
		{
			if (CANCM_ZERO == CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucVolFailed)
			{
				/* Notify BswM to enable CAN transmission */
	            BswM_RequestMode((BswM_UserType)CanCMBswmMTxInd(CanCM_GaaChannelConfig[LucChannelIndex].ucChannelId),
	                             (BswM_ModeType)CANCM_COMM_STAT_TX_ENABLED);
				CanCM_GunFlagStatus[LucChannelIndex].ddBitByteRecord.ucTxDisabled = CANCM_ZERO;
			}
			/* Change Current Network State to ACTIVE because of 0 ActivationTime*/
			CanCM_GddCommStat[LucChannelIndex] = CANCM_COMM_STAT_ACTIVE;
		}
		/* polyspace-end MISRA-C3:14.3,2.1 [Not a defect:Justified] "The value is generated by Generator." */
		/* polyspace-end DEFECT:DEAD_CODE [Not a defect:Justified] "The value is generated by Generator." */
		
        /* Start Reception DM Start timer */
        CanCM_GddRTimerCounter[LucChannelIndex] = CanCM_GaaChannelConfig[LucChannelIndex].ddTimeoutStartTime;
        /* In order to start CAN Transmission ASAP if voltage is normal and
        previously error */
        CanCM_GddETimerCounter[LucChannelIndex] = CANCM_TWO;
        CanCM_GddVolMod[LucChannelIndex] = CANCM_VOL_MODE_NORMAL;
      }
      else
      {
        /* Do nothing */
      }
     
    }
    else{
      /* invalid comm state */
    }
  }
}
/* polyspace-end MISRA-C3:8.4 [Not a defect:Justfied] "This is not a static function." */

#define CANCM_STOP_SEC_CODE
#include "MemMap.h"


/* polyspace:end<RTE: OBAI : Not a defect : No Action Planned > 
                                        Its boundary is pre-defined           */
/* polyspace-end MISRA-C3:17.3 [Not a defect:Justified] "This function has visible prototype" */
/* polyspace:end<MISRA-C3:1.1:Not a defect:Justify with annotations> The number of macros doesn't matter. */

