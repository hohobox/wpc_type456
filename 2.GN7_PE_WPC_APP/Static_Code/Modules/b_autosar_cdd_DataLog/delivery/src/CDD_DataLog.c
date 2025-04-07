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
**  SRC-MODULE: CDD_DataLog.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : DataLog CDD                                                   **
**                                                                            **
**  PURPOSE   : Provision of functions for DataLog                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.0.0     06-Apr-2023    MJ.Woo        JIRA CP44-789                       **
** 1.1.2     04-Aug-2022    YH.Han        Redmine #36976                      **
** 1.1.1     16-Dec-2021    MJ.Woo        Redmine #33425                      **
** 1.1.0     07-Jun-2021    MJ.Woo        Redmine #29944                      **
** 1.0.1     09-Dec-2020    MJ.Woo        Redmine #26970                      **
** 1.0.0     17-Nov-2020    MJ.Woo        Redmine #25497                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CDD_DataLog.h"
#include "SchM_DataLog.h"
#include "NvM.h"
#include "Det.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/**
* @addtogroup DATALOG_ESDD_008
* @{ */
#define DATALOG_RMBA_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
/** Log data to store in non-volatile memory
 * This variable must be placed in a RAM area that can be read by
 * Read Memory By Address service of Dcm */
uint32 DataLog_NvLog;
#define DATALOG_RMBA_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if (SWP_USE_DATALOG == STD_ON)

#define DATALOG_START_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"
/** Current Log Data */
DataLog_DataType DataLog_Data = {
  0u,                   /* ComMMode */
  TRUE,                 /* LpAllowNvM */
  DATALOG_ECUM_STARTUP, /* EcuMMode */
  0u,                   /* WakeupEvent */
  FALSE,                /* SleepOK */
  FALSE,                /* RunOK */
  FALSE,                /* ViolationComMMode */
  FALSE,                /* ViolationNvMMode */
  DATALOG_SEQ_INIT,     /* SleepSequence */
  MCU_RESET_UNDEFINED,  /* ResetReason */
};
#define DATALOG_STOP_SEC_VAR_INIT_UNSPECIFIED
#include "MemMap.h"

#define DATALOG_START_SEC_VAR_CLEARED_32
#include "MemMap.h"
/** DataLog_SleepDelayCount is used to check how long SLEEP has been delayed.
 * Overflow can occur after about 4971 days(MainFunction period: 100ms) */
static uint32 DataLog_SleepDelayCount;
/** DataLog_WakeupDelayCount is used to check how long RUN has been delayed
 * after wakeup.
 * Overflow can occur after about 4971 days(MainFunction period: 100ms) */
static uint32 DataLog_WakeupDelayCount;
#define DATALOG_STOP_SEC_VAR_CLEARED_32
#include "MemMap.h"

#if defined(NvMBlock_DataLog) /* NvM R44 */
  #define DATALOG_NVMBLOCK_ID NvMBlock_DataLog
#elif  defined(NvMConf_NvMBlockDescriptor_NvMBlock_DataLog) /* NvM R40 */
  #define DATALOG_NVMBLOCK_ID NvMConf_NvMBlockDescriptor_NvMBlock_DataLog
#else
  #error "Check configuration for NvMBlock_DataLog"
#endif

#endif /* End of #if (SWP_USE_DATALOG == STD_ON) */
/** @}  */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define DATALOG_START_SEC_CODE
#include "MemMap.h"

/**
* @addtogroup DATALOG_ESDD_004
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_ComMMode
 *
 * Service ID           : 0x01
 *
 * Description          : Saving the ComM Mode to the DataLog
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            channel ComM channel ID
 *
 * @param [in]            mode    ComM Mode
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_ComMMode(NetworkHandleType channel, ComM_ModeType mode)
{
  #if (SWP_USE_DATALOG == STD_ON)
  if (channel <= DATALOG_COMM_CHANNEL_ID_MAX)
  {
    if (mode == COMM_NO_COMMUNICATION)
    {
      DataLog_Data.ComMMode = DataLog_Data.ComMMode & (~(((uint32)0x01u << channel)));
    }
    else
    {
      DataLog_Data.ComMMode = DataLog_Data.ComMMode | ((uint32)0x01u << channel);
    }
  }
  else
  {
    (void)Det_ReportError(DATALOG_MODULE_ID, DATALOG_INSTANCE_ID,
        DATALOG_COMMODE_SID, DATALOG_E_COMM_CHANNEL_OUT_OF_RANGE);
  }
  #else
  DATALOG_UNUSED(channel);
  DATALOG_UNUSED(mode);
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_NvMLowPowerAllow
 *
 * Service ID           : 0x02
 *
 * Description          : Saving the NvM LowPowerAllow state to the DataLog
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            allow    Current NvM LowPowerAllow state
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_NvMLowPowerAllow(boolean allow)
{
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_Data.LpAllowNvM = allow;
  #else
  DATALOG_UNUSED(allow);
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_EcuMMode
 *
 * Service ID           : 0x03
 *
 * Description          : Saving the EcuM Mode to the DataLog
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            mode    Current EcuM Mode
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_EcuMMode(DataLog_EcuMModeType mode)
{
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_Data.EcuMMode = mode;
  #else
  DATALOG_UNUSED(mode);
  #endif
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_008
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_GetSleepSequence
 *
 * Service ID           : 0x04
 *
 * Description          : This function provides Sleep and Wakeup sequence
 *                        information
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : DataLog_SleepSeqType
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(DataLog_SleepSeqType, DATALOG_CODE) DataLog_GetSleepSequence(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  return DataLog_Data.SleepSequence;
  #else
  return DATALOG_SEQ_INIT;
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_SetSleepSequence
 *
 * Service ID           : 0x05
 *
 * Description          : This function sets Sleep and Wakeup sequence
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            seq    Sleep/Wakeup sequence to be set
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetSleepSequence(DataLog_SleepSeqType seq)
{
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_Data.SleepSequence = seq;
  #else
  DATALOG_UNUSED(seq);
  #endif
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_004
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_SetSleepConditionLog
 *
 * Service ID           : 0x06
 *
 * Description          : It clear previous SLEEP related data and
 *                        updates SLEEP condition in DataLog_Data
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_SleepSequence, DataLog_Data, DataLog_NvLog,
 *                        DataLog_SleepDelayCount, DataLog_WakeupDelayCount
 *
 *                        Function(s) invoked    :
 *                        SchM_Enter_DataLog_DATA_PROTECTION(),
 *                        SchM_Exit_DataLog_DATA_PROTECTION(),
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetSleepConditionLog(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  /* To prevent clearing DataLog_SleepDelayCount when multiple sleep request */
  if (DataLog_Data.SleepSequence != DATALOG_SEQ_SLEEP_REQ)
  {
    SchM_Enter_DataLog_DATA_PROTECTION();
    DataLog_Data.SleepSequence = DATALOG_SEQ_SLEEP_REQ;
    /* Clear WakeupEvent before new sleep */
    DataLog_Data.WakeupEvent = 0u;
    /* Clear SleepOK before new sleep */
    DataLog_Data.SleepOK = FALSE;
    /* Clear ComMMode violation before new sleep */
    DataLog_Data.ViolationComMMode = FALSE;
    /* Clear NvMMode violation before new sleep */
    DataLog_Data.ViolationNvMMode = FALSE;

    DataLog_SleepDelayCount = 0u;
    DataLog_WakeupDelayCount = 0u;

    /* When requesting sleep, non NO_COM ComM channels exists */
    if (DataLog_Data.ComMMode != 0u)
    {
      DataLog_Data.ViolationComMMode = TRUE;
      DataLog_NvLog |= DATALOG_ERROR_COMM_MODE;
      (void)Det_ReportError(DATALOG_MODULE_ID, DATALOG_INSTANCE_ID,
          DATALOG_SETSLEEPCONDITIONLOG_SID, DATALOG_E_COMM_MODE);
    }
    /* When requesting sleep, a running NvM job exists */
    if (DataLog_Data.LpAllowNvM == FALSE)
    {
      DataLog_Data.ViolationNvMMode = TRUE;
      DataLog_NvLog |= DATALOG_ERROR_NVM_MODE;
      (void)Det_ReportError(DATALOG_MODULE_ID, DATALOG_INSTANCE_ID,
          DATALOG_SETSLEEPCONDITIONLOG_SID, DATALOG_E_NVM_MODE);
    }
    SchM_Exit_DataLog_DATA_PROTECTION();
  }
  #endif
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_005
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_SetSleepOKLog
 *
 * Service ID           : 0x07
 *
 * Description          : It sets SleepOK to DataLog_Data.
 *                        It means that all BswM SLEEP related Rule conditions
 *                        have been passed
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetSleepOKLog(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_Data.SleepSequence = DATALOG_SEQ_H2L;
  DataLog_Data.SleepOK = TRUE;
  #endif
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_006
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_SetWakeupEventLog
 *
 * Service ID           : 0x08
 *
 * Description          : It updates Wakeup event in DataLog_Data
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_Data
 *
 *                        Function(s) invoked    :
 *                        EcuM_GetValidatedWakeupEvents()
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetWakeupEventLog(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_Data.SleepSequence = DATALOG_SEQ_L2H;
  DataLog_Data.WakeupEvent = EcuM_GetValidatedWakeupEvents();
  #endif
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_001
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_MainFunction
 *
 * Service ID           : 0x00
 *
 * Description          : It works periodically(100ms) to check for errors in
 *                        Sleep/Wakeup related logs and changes in CustomData
 *                        and save them to NvM.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : NvM_ReadAll() should be done
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_InitStatus, DataLog_NvLog, DataLog_PrevNvLog,
 *                        DataLog_SleepSequence, DataLog_Data,
 *                        DataLog_SleepDelayCount, DataLog_WakeupDelayCount
 *
 *                        Function(s) invoked    :
 *                        SchM_Enter_DataLog_DATA_PROTECTION(),
 *                        SchM_Exit_DataLog_DATA_PROTECTION(),
 *                        EcuM_GetResetReason(), NvM_WriteBlock()
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_MainFunction(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  Std_ReturnType result;
  uint32 buffer;
  NvM_RequestResultType nvmResult;
  static DataLog_InitStatusType DataLog_InitStatus = DATALOG_INIT_NONE;
  /* Used to check for changes to a previously saved NvLog value */
  static uint32 DataLog_PrevNvLog;

  /* Initialize DataLog */
  if ((DataLog_InitStatus == DATALOG_INIT_NONE) &&
      (DataLog_Data.EcuMMode == DATALOG_ECUM_RUN))
  {
    DataLog_Data.RunOK = TRUE;
    (void)EcuM_GetResetReason(&DataLog_Data.ResetReason);
    /* Copy DataLog_NvLog(Updated in NvM_ReadAll) to previous log variable */
    DataLog_PrevNvLog = DataLog_NvLog;
    DataLog_InitStatus = DATALOG_INIT_COMPLETED;
  }

  /* Check and Update Sleep/Wakeup log */
  SchM_Enter_DataLog_DATA_PROTECTION();
  switch (DataLog_Data.SleepSequence)
  {
    /* Enter Sleep delayed */
    case DATALOG_SEQ_SLEEP_REQ:
      DataLog_SleepDelayCount++;
      if (DataLog_SleepDelayCount == DATALOG_DELAY_SLEEP_LIMIT)
      {
        DataLog_Data.SleepSequence = DATALOG_SEQ_SLEEP_DELAYED;
        DataLog_NvLog |= DATALOG_ERROR_SLEEP_DELAY;
        (void)Det_ReportError(DATALOG_MODULE_ID, DATALOG_INSTANCE_ID,
            DATALOG_MAINFUNCTION_SID, DATALOG_E_SLEEP_DELAY);
      }
      break;

    /* Enter Sleep delay exceeds the limit */
    case DATALOG_SEQ_SLEEP_DELAYED:
      DataLog_SleepDelayCount++;
      break;

    /* Normal Wakeup */
    case DATALOG_SEQ_L2H:
    /* Incomplete wakeup */
    case DATALOG_SEQ_RUN_DELAYED:
      /* Wakeup and RUN OK */
      if (DataLog_Data.EcuMMode == DATALOG_ECUM_RUN)
      {
        DataLog_Data.SleepSequence = DATALOG_SEQ_RUN;
        DataLog_Data.RunOK = TRUE;
      }
      /* Wakeup but RUN NOT OK */
      else
      {
        DataLog_WakeupDelayCount++;
        if (DataLog_WakeupDelayCount == DATALOG_DELAY_WAKEUP_LIMIT)
        {
          DataLog_Data.RunOK = FALSE;
          DataLog_Data.SleepSequence = DATALOG_SEQ_RUN_DELAYED;
          DataLog_NvLog |= DATALOG_ERROR_WAKEUP_DELAY;
          (void)Det_ReportError(DATALOG_MODULE_ID, DATALOG_INSTANCE_ID,
              DATALOG_MAINFUNCTION_SID, DATALOG_E_WAKEUP_DELAY);
        }
      }
      break;
    default:
      /* Do nothing */
      break;
  }
  SchM_Exit_DataLog_DATA_PROTECTION();

  /* Save updated log to NvM */
  if (DataLog_PrevNvLog != DataLog_NvLog)
  {
    result = NvM_GetErrorStatus(DATALOG_NVMBLOCK_ID, &nvmResult);
    if ((result == E_OK) && (nvmResult != NVM_REQ_PENDING))
    {
      buffer = DataLog_PrevNvLog;
      DataLog_PrevNvLog = DataLog_NvLog;
      result = NvM_WriteBlock(DATALOG_NVMBLOCK_ID, &DataLog_PrevNvLog);
      if (result != E_OK)
      {
        /* If NvM_WriteBlock failed, revert to backup data */
        DataLog_PrevNvLog = buffer;
      }
    }
  }
  #endif /* End of #if (SWP_USE_DATALOG == STD_ON) */
}
/** @}  */

/**
* @addtogroup DATALOG_ESDD_008
* @{ */
/***************************************************************************//**
 * Function Name        : DataLog_GetCustomData
 *
 * Service ID           : 0x09
 *
 * Description          : Get CustomData from NvLog
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : uint16 CustomData
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_NvLog
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(uint16, DATALOG_CODE) DataLog_GetCustomData(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  uint16 customData;

  customData = (uint16)((DataLog_NvLog >> 16) & 0x0000FFFFu);
  return customData;
  #else
  return 0u;
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_SetCustomData
 *
 * Service ID           : 0x0A
 *
 * Description          : This function sets CustomData to NvLog
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            customData : Data to be saved
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_NvLog
 *
 *                        Function(s) invoked    :
 *                        SchM_Enter_DataLog_DATA_PROTECTION(),
 *                        SchM_Exit_DataLog_DATA_PROTECTION()
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetCustomData(uint16 customData)
{
  #if (SWP_USE_DATALOG == STD_ON)
  uint32 buffer = 0u;

  SchM_Enter_DataLog_DATA_PROTECTION();
  buffer = (uint32)customData << 16;
  DataLog_NvLog &= 0x0000FFFFu;            /* Clear Custom Data field */
  DataLog_NvLog |= (buffer & 0xFFFF0000u); /* Set Custom Data */
  SchM_Exit_DataLog_DATA_PROTECTION();
  #else
  DATALOG_UNUSED(customData);
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_GetNvLog
 *
 * Service ID           : 0x0B
 *
 * Description          : Get NvLog(with custom data)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Paramameters         : None
 *
 * @return              : uint32 NvLog
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_NvLog
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(uint32, DATALOG_CODE) DataLog_GetNvLog(void)
{
  #if (SWP_USE_DATALOG == STD_ON)
  return DataLog_NvLog;
  #else
  return 0u;
  #endif
}

/***************************************************************************//**
 * Function Name        : DataLog_SetNvLog
 *
 * Service ID           : 0x0C
 *
 * Description          : This function sets NvLog(with custom data)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            nvlog : Data to be saved
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        DataLog_NvLog
 *
 *                        Function(s) invoked    :
 *                        SchM_Enter_DataLog_DATA_PROTECTION(),
 *                        SchM_Exit_DataLog_DATA_PROTECTION()
 ******************************************************************************/
FUNC(void, DATALOG_CODE) DataLog_SetNvLog(uint32 nvlog)
{
  #if (SWP_USE_DATALOG == STD_ON)
  SchM_Enter_DataLog_DATA_PROTECTION();
  DataLog_NvLog = nvlog;
  SchM_Exit_DataLog_DATA_PROTECTION();
  #else
  DATALOG_UNUSED(nvlog);
  #endif
}
/** @}  */

#define DATALOG_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<MISRA-C3:1.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
