/*******************************************************************************
**                                                                            **
** (C) 2021 HYUNDAI AUTOEVER Corp.                                            **
** Confidential Proprietary Information. Distribution Limited.                **
** This source code is permitted to be used only in projects contracted       **
** with Hyundai Autoever, and any other use is prohibited.                    **
** If you use it for other purposes or change the source code,                **
** you may take legal responsibility.                                         **
** In this case, There is no warranty and technical support.                  **
**                                                                            **
**  SRC-MODULE: Dcm_DslManageSecurity.c                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Diagnostic Communication Manager Module               **
**                                                                            **
**  PURPOSE   : Manage the security level in Dcm                              **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 2.14.0.0  30-Sep-2024   Haewon Seo     #48771                              **
*******************************************************************************/

/*******************************************************************************
**                           Include Section                                  **
*******************************************************************************/
#include "Dcm.h"
#include "Dcm_DslManageSecurity.h"
#include "Rte_Dcm.h"
#include "Dcm_Config.h"
#include "Dcm_Timer.h"
#include "Dcm_Ram.h"
#include "Dcm_DsdInternal.h"
#include "SchM_Dcm.h"

/*******************************************************************************
**                           Static functions declaration                     **
*******************************************************************************/
#define DCM_START_SEC_CODE
#include "MemMap.h"

#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(void, DCM_CODE) Dcm_InitSecurityAttemptCounterControl(
  Dcm_ConfigConstPtrType pConfig);
#endif

#ifdef SECURITY_SERVICE_ENABLED
static FUNC(boolean, DCM_CODE) Dcm_IsSecurityLevelIndexValid(
  uint8 SecLvlIdx);
#endif

#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(void, DCM_CODE) Dcm_InvokeGetSecurityAttemptCounter(
  Dcm_OpStatusType OpStatus);

static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterInitial(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterPending(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterCancel(
  uint8 SecLvlIdx);

static FUNC(boolean, DCM_CODE) Dcm_IsGetSecurityAttemptCountersPending(
  void);

static FUNC(void, DCM_CODE) Dcm_TriggerGetAttPending(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_ClearGetAttPending(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_InvokeSetSecurityAttemptCounter(
  Dcm_OpStatusType OpStatus);

static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterInitial(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterPending(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterCancel(
  uint8 SecLvlIdx);
#endif

#ifdef SECURITY_SERVICE_ENABLED
static FUNC(uint8, DCM_CODE) Dcm_ReadAttCounter(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_WriteAttCounter(
  uint8 SecLvlIdx, 
  uint8 AttCounter);
#endif

#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(boolean, DCM_CODE) Dcm_IsGetAttPending(
  uint8 SecLvlIdx);

static FUNC(void, DCM_CODE) Dcm_WriteGetAttPending(
  uint8 SecLvlIdx, 
  boolean GetAttPending);

static FUNC(void, DCM_CODE) Dcm_WriteSetAttPending(
  uint8 SecLvlIdx, 
  boolean SetAttPending);

static FUNC(uint8, DCM_CODE) Dcm_ReadGetAttPendingCount(
  void);

static FUNC(void, DCM_CODE) Dcm_WriteGetAttPendingCount(
  uint8 GetAttPendingCount);
#endif

/*******************************************************************************
**                           Functions definition                             **
*******************************************************************************/
/*******************************************************************************
** Function Name        : Dcm_InitManageSecurity                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize data for manage security level features  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_InitManageSecurity(
  Dcm_ConfigConstPtrType pConfig)
{
  #ifdef SECURITY_SERVICE_ENABLED
  Dcm_InitSecurityLevelState(pConfig);
  #endif

  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  Dcm_GblStartRestoreSecurityAttemptCounters = DCM_TRUE;
  Dcm_InitSecurityAttemptCounterControl(pConfig);
  #endif

  DCM_UNUSED(pConfig);
}

/*******************************************************************************
** Function Name        : Dcm_InitSecurityLevelState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize the value for the state of security level**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_SERVICE_ENABLED
FUNC(void, DCM_CODE) Dcm_InitSecurityLevelState(
  Dcm_ConfigConstPtrType pConfig)
{
  uint8 LucIdx;

  for (LucIdx = DCM_ZERO; LucIdx < DCM_NUM_OF_SECURITYLEVELCONFIG; LucIdx++)
  {
    Dcm_WriteAttCounter(LucIdx, DCM_ZERO);

    #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
    Dcm_WriteGetAttPending(LucIdx, DCM_FALSE);
    Dcm_WriteSetAttPending(LucIdx, DCM_FALSE);
    #endif
  }

  DCM_UNUSED(pConfig);
}
#endif

/*******************************************************************************
** Function Name        : Dcm_GetSecurityLevelIndex                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Getter function to get the current index            **
**                        of security level                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(uint8, DCM_CODE) Dcm_GetSecurityLevelIndex(void)
{
  uint8 SecLvlIdx = DCM_ZERO;

  #ifdef SECURITY_SERVICE_ENABLED
  SchM_Enter_Dcm_DATA_UPDATE();
  SecLvlIdx = Dcm_GucDspStIndex;
  SchM_Exit_Dcm_DATA_UPDATE();
  #endif

  return SecLvlIdx;
}

/*******************************************************************************
** Function Name        : Dcm_SetSecurityLevelIndex                           **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Setter function to set the current index            **
**                        of security level                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SetSecurityLevelIndex(
  uint8 SecLvlIdx)
{
  #ifdef SECURITY_SERVICE_ENABLED
  SchM_Enter_Dcm_DATA_UPDATE();
  Dcm_GucDspStIndex = SecLvlIdx;
  SchM_Exit_Dcm_DATA_UPDATE();
  #else
  DCM_UNUSED(SecLvlIdx);
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityLevelConfig                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the configuration of current security level     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_SecurityLevConfigConstPtrType                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(Dcm_SecurityLevConfigConstPtrType, DCM_CODE) Dcm_GetSecurityLevelConfig(
  void)
{
  Dcm_SecurityLevConfigConstPtrType pSecLvlCfg = NULL_PTR;

  #ifdef SECURITY_SERVICE_ENABLED
  pSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(Dcm_GetSecurityLevelIndex());
  #endif

  return pSecLvlCfg;
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityLevelConfigByIndex                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security configuration by index value       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Dcm_SecurityLevConfigConstPtrType                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(Dcm_SecurityLevConfigConstPtrType, DCM_CODE) Dcm_GetSecurityLevelConfigByIndex(
  uint8 SecLvlIdx)
{
  Dcm_SecurityLevConfigConstPtrType pSecLvlCfg = NULL_PTR;

  #ifdef SECURITY_SERVICE_ENABLED
  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    pSecLvlCfg = &Dcm_GaaSecurityLevConfig[SecLvlIdx];
  }
  #else
  DCM_UNUSED(SecLvlIdx);
  #endif

  return pSecLvlCfg;
}

/*******************************************************************************
** Function Name        : Dcm_IncSecurityAttemptCounterOfCurrentLevel         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Increase the security attempt counter value         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_IncSecurityAttemptCounterOfCurrentLevel(void)
{
  #ifdef SECURITY_SERVICE_ENABLED
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();
  
  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    uint8 AttCounter = Dcm_GetSecurityAttemptCounterOfCurrentLevel();
    Dcm_SecurityLevConfigConstPtrType pSecLvlCfg = Dcm_GetSecurityLevelConfig();

    if ((NULL_PTR != pSecLvlCfg) && 
        (AttCounter < pSecLvlCfg->ucSecNumMaxAttDelay))
    {
      AttCounter++;
      Dcm_SetSecurityAttemptCounterOfCurrentLevel(AttCounter);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_IsSecurityAttemptCounterExceeded                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the current security attempt counter value **
**                        is exceed the configured value or not               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_IsSecurityAttemptCounterExceeded(void)
{
  boolean Exceeded = DCM_FALSE;

  #ifdef SECURITY_SERVICE_ENABLED
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();

  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    uint8 AttCounter = Dcm_GetSecurityAttemptCounterOfCurrentLevel();
    Dcm_SecurityLevConfigConstPtrType pSecLvlCfg = Dcm_GetSecurityLevelConfig();

    if ((NULL_PTR != pSecLvlCfg) && 
        (pSecLvlCfg->ucSecNumMaxAttDelay <= AttCounter))
    {
      Exceeded = DCM_TRUE;
    }
  }
  #endif

  return Exceeded;
}

/*******************************************************************************
** Function Name        : Dcm_ResetSecurityAttemptCounterOfCurrentLevel       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Reset the value of security attempt counter         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_ResetSecurityAttemptCounterOfCurrentLevel(void)
{
  #ifdef SECURITY_SERVICE_ENABLED
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();
  Dcm_WriteAttCounter(SecLvlIdx, DCM_ZERO);
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityAttemptCounterOfCurrentLevel         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security attempt counter value of           **
**                        current security level                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(uint8, DCM_CODE) Dcm_GetSecurityAttemptCounterOfCurrentLevel(void)
{
  uint8 AttCounter = DCM_ZERO;

  #ifdef SECURITY_SERVICE_ENABLED
  AttCounter = Dcm_ReadAttCounter(Dcm_GetSecurityLevelIndex());
  #endif

  return AttCounter;
}

/*******************************************************************************
** Function Name        : Dcm_SetSecurityAttemptCounterOfCurrentLevel         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the security attempt counter value of           **
**                        current security level                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : AttCounter                                          **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterOfCurrentLevel(
  uint8 AttCounter)
{
  #ifdef SECURITY_SERVICE_ENABLED
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();
  Dcm_WriteAttCounter(SecLvlIdx, AttCounter);
  #else
  DCM_UNUSED(AttCounter);
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_StartRestoreSecurityAttemptCounters             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Restore the value of security attempt counter       **
**                        of all security level configured                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_StartRestoreSecurityAttemptCounters(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  /* @Trace: SWS_Dcm_01154 */
  Dcm_InvokeGetSecurityAttemptCounter(DCM_INITIAL);

  if (DCM_TRUE == Dcm_IsGetSecurityAttemptCountersPending())
  {
    Dcm_SecurityAccess_StartTimerExt(
      DCM_READ_ATTEMPT_COUNTER_TIMER
      , DCM_SECURITY_MAX_ATTEMPT_COUNTER_READOUT_TIME
      , Dcm_WaitRestoreSecurityAttemptCounters
      , Dcm_CancelRestoreSecurityAttemptCounters);
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_WaitRestoreSecurityAttemptCounters              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Pending process function in case restore            **
**                        security attempt counter value                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WaitRestoreSecurityAttemptCounters(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  if (DCM_TRUE == Dcm_IsGetSecurityAttemptCountersPending())
  {
    Dcm_InvokeGetSecurityAttemptCounter(DCM_PENDING);

    if (DCM_FALSE == Dcm_IsGetSecurityAttemptCountersPending())
    {
      Dcm_SecurityAccess_StopTimer(DCM_READ_ATTEMPT_COUNTER_TIMER);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_CancelRestoreSecurityAttemptCounters            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel process function in case restore             **
**                        security attempt counter value                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_CancelRestoreSecurityAttemptCounters(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  if (DCM_TRUE == Dcm_IsGetSecurityAttemptCountersPending())
  {
    /* @Trace: SWS_Dcm_01352 */
    Dcm_InvokeGetSecurityAttemptCounter(DCM_CANCEL);
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_RestoreSecurityAttemptCountersDone              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main function to process action in case all         **
**                        security attempt counters are restored successfully **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_RestoreSecurityAttemptCountersDone(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  uint8 LucIdx;
  uint8 LucAttCounter;
  uint32 LusDelayTime = DCM_ZERO;
  uint32 LusMaxDelayTime = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg;

  if (DCM_FALSE == Dcm_IsGetSecurityAttemptCountersPending())
  {
    for (LucIdx = DCM_ZERO; LucIdx < DCM_NUM_OF_SECURITYLEVELCONFIG; LucIdx++)
    {
      LusDelayTime = DCM_ZERO;
      LucAttCounter = Dcm_ReadAttCounter(LucIdx);
      LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(LucIdx);

      if ((NULL_PTR != LpSecLvlCfg) && 
          (LucAttCounter >= LpSecLvlCfg->ucSecNumMaxAttDelay))
      {
        /* @Trace: SWS_Dcm_01355 */
        /* Once all the AttemptCounter values have been successfully or
          unsuccessfully retrieved (all the Xxx_GetSecurityAttemptCounter()
          operations have been executed and have returned a final,
          non-PENDING error value or the operation chain has been cancelled),
          if at least one of the restored AttemptCounter values
          is greater than or equal to the DcmDspSecurityNumAttDelay
          configured for its corresponding DcmDspSecurityRow,
          the Dcm shall start the SecurityDelayTimer with the higher value
          of DcmDspSecurityDelayTimeOnBoot / DcmDspSecurityDelayTime
          of the according DcmDspSecurityRow.c() */
        LusDelayTime = LpSecLvlCfg->usSecDelayInvKey;
        if (LusDelayTime < (uint32)LpSecLvlCfg->usSecurityDelayTimeOnBoot)
        {
          LusDelayTime = (uint32)LpSecLvlCfg->usSecurityDelayTimeOnBoot;
        }
      }

      if (LusMaxDelayTime < LusDelayTime)
      {
        /* Set the index of security level 
        that started delay timer before ECU reset */
        Dcm_SetSecurityLevelIndex(LucIdx);

        LusMaxDelayTime = LusDelayTime;
      }
    }

    if (DCM_ZERO != LusMaxDelayTime)
    {
      Dcm_SecurityAccess_StartTimerExt(
        DCM_SECURITY_DELAY_TIMER
        , LusMaxDelayTime
        , NULL_PTR
        , Dcm_ResetAndInformSecurityAttemptCounter);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_IsSecurityAttemptCounterRestored                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if all security attempt coutners are restored **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : ServiceId, SubServiceId                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : pErrorCode                                          **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_IsSecurityAttemptCounterRestored(
  uint8 ServiceId, 
  uint8 SubServiceId, 
  Dcm_NrcPtrType pErrorCode)
{
  boolean Restored = DCM_TRUE;

  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  if ((DCM_TRUE == Dcm_IsGetSecurityAttemptCountersPending()) && 
      (DCM_SECURITYACCESS == ServiceId) && 
      ((uint8)DCM_ZERO != (SubServiceId & DCM_BIT0_AND_MASK)))
  {
    Restored = DCM_FALSE;

    if (pErrorCode != NULL_PTR)
    {
      /* @Trace: SWS_Dcm_01354 */
      *pErrorCode = DCM_E_CONDITIONSNOTCORRECT;
    }
  }
  #else
  DCM_UNUSED(ServiceId);
  DCM_UNUSED(SubServiceId);
  DCM_UNUSED(pErrorCode);
  #endif

  return Restored;
}

/*******************************************************************************
** Function Name        : Dcm_StartInformSecurityAttemptCounter               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Inform the new security attempt counter value       **
**                        to the application                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_StartInformSecurityAttemptCounter(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  /* Dcm_StartInformSecurityAttemptCounter() is called when below cases,
    Therefore the action in pending is different.
    [1] Delay_Timer expiration occurs (It is called by timeout callback of Delay_Timer)
      - Action in pending
        1) set Dcm_GaaSecLevState[SecLvlIdx].blSetAttPending = DCM_TRUE
        2) start the DCM_WRITE_ATTEMPT_COUNTER_TIMER for DCM_MAX_ATTEMPT_COUNTER_WRITEOUT_TIME
    [2] KEY OK or KEY NOK in SecurityAccess service
      - Action in pending
        1) set Dcm_GaaSecLevState[SecLvlIdx].blSetAttPending = DCM_TRUE
        2) start the pending opearation in the Dcm_SecurityAccessMainFunction()
  */
  Dcm_InvokeSetSecurityAttemptCounter(DCM_INITIAL);
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_WaitInformSecurityAttemptCounter                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Pending function in case set new security           **
**                        attempt counter value to the application            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WaitInformSecurityAttemptCounter(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    Dcm_InvokeSetSecurityAttemptCounter(DCM_PENDING);
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_CancelInformSecurityAttemptCounter              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel function in case set new security            **
**                        attempt counter value to the application            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_CancelInformSecurityAttemptCounter(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    Dcm_InvokeSetSecurityAttemptCounter(DCM_CANCEL);
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_WaitAndExtendInformSecurityAttemptCounter       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Pending function in case set new security           **
**                        attempt counter value to the application            **
**                        after delay timer is expired                        **   
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_WaitAndExtendInformSecurityAttemptCounter(void)
{
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  /* This function is called by pending callback of DCM_WRITE_ATTEMPT_COUNTER_TIMER
    after DCM_SECURITY_DELAY_TIMER is expired */
  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    Dcm_InvokeSetSecurityAttemptCounter(DCM_PENDING);

    if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
    {
      /* Restart DCM_WRITE_ATTEMPT_COUNTER_TIMER */
      Dcm_SecurityAccess_StartTimerExt(
        DCM_WRITE_ATTEMPT_COUNTER_TIMER
        , DCM_MAX_ATTEMPT_COUNTER_WRITEOUT_TIME
        , Dcm_WaitAndExtendInformSecurityAttemptCounter
        , NULL_PTR);
    }
    else
    {
      /* Stop DCM_WRITE_ATTEMPT_COUNTER_TIMER */
      Dcm_SecurityAccess_StopTimer(DCM_WRITE_ATTEMPT_COUNTER_TIMER);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_ResetAndInformSecurityAttemptCounter            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function update Dcm available timer                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                                                                            **
**                        Function(s) :                                       **
**                                                                            **
**                                                                            **
*******************************************************************************/
FUNC(void, DCM_CODE) Dcm_ResetAndInformSecurityAttemptCounter(void)
{
  #if ((DCM_STANDARD_SUPPORT != DCM_ES96590_SUPPORT)\
    && (DCM_STANDARD_SUPPORT != DCM_QZN04_SUPPORT))
  /* Reset the attempt counter of current security level */
  Dcm_ResetSecurityAttemptCounterOfCurrentLevel();
  
  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  /* @Trace : SWS_Dcm_01155 */
  /* Inform the applcation about the counter change */
  Dcm_StartInformSecurityAttemptCounter();

  /* Start DCM_WRITE_ATTEMPT_COUNTER_TIMER.
    DCM_WRITE_ATTEMPT_COUNTER_TIMER is continues until
    Xxx_SetSecurityAttemptCounter does not return DCM_E_PENDING */
  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    Dcm_SecurityAccess_StartTimerExt(
      DCM_WRITE_ATTEMPT_COUNTER_TIMER
      , DCM_MAX_ATTEMPT_COUNTER_WRITEOUT_TIME
      , Dcm_WaitAndExtendInformSecurityAttemptCounter
      , NULL_PTR);
  }
  #endif
  #endif
}

/*******************************************************************************
** Function Name        : Dcm_IsSetSecurityAttemptCountersPending             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the pending state of the set security         **
**                        attempt counter by index of security configuration  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
FUNC(boolean, DCM_CODE) Dcm_IsSetSecurityAttemptCountersPending(void)
{
  boolean SetAttPending = DCM_FALSE;

  #ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();

  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    SetAttPending = Dcm_GaaSecLevState[SecLvlIdx].blSetAttPending;
    SchM_Exit_Dcm_DATA_UPDATE();
  }
  #endif

  return SetAttPending;
}

/*******************************************************************************
** Function Name        : Dcm_InitSecurityAttemptCounterControl               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Initialize the value of security attempt counter    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : pConfig                                             **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(void, DCM_CODE) Dcm_InitSecurityAttemptCounterControl(
  Dcm_ConfigConstPtrType pConfig)
{
  Dcm_WriteGetAttPendingCount(DCM_ZERO);

  DCM_UNUSED(pConfig);
}
#endif

/*******************************************************************************
** Function Name        : Dcm_IsSecurityLevelIndexValid                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check whether the index of security configuration   **
**                        is valid or not                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_SERVICE_ENABLED
static FUNC(boolean, DCM_CODE) Dcm_IsSecurityLevelIndexValid(
  uint8 SecLvlIdx)
{
  boolean retVal = DCM_FALSE;

  if (SecLvlIdx < DCM_NUM_OF_SECURITYLEVELCONFIG)
  {
    retVal = DCM_TRUE;
  }

  return retVal;
}
#endif

/*******************************************************************************
** Function Name        : Dcm_InvokeGetSecurityAttemptCounter                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main function to get the security attempt counter   **
**                        for all security level                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(void, DCM_CODE) Dcm_InvokeGetSecurityAttemptCounter(
  Dcm_OpStatusType OpStatus)
{
  uint8 LucIdx;

  Dcm_Internal_GetSecurityAttemptCounterFunType GetSecurityAttemptCounterFun[] = 
  {
    Dcm_GetSecurityAttemptCounterInitial
    , Dcm_GetSecurityAttemptCounterPending
    , Dcm_GetSecurityAttemptCounterCancel
  };

  /* Invoke all GetSecurityAttemptCounterFun */
  for (LucIdx = DCM_ZERO; LucIdx < DCM_NUM_OF_SECURITYLEVELCONFIG; LucIdx++)
  {
    GetSecurityAttemptCounterFun[OpStatus](LucIdx);
  }

  Dcm_RestoreSecurityAttemptCountersDone();
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityAttemptCounterInitial                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security level attempt counter              **
**                        in case the operation status is DCM_INITIAL         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterInitial(
  uint8 SecLvlIdx)
{
  Std_ReturnType LddRetVal = E_NOT_OK;
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg = NULL_PTR;

  LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

  if ((NULL_PTR != LpSecLvlCfg)
    && (DCM_TRUE == LpSecLvlCfg->blAttemptCounterEnabled)
    && (NULL_PTR != LpSecLvlCfg->pGetSecurityAttemptCounterFun))
  {
    /* @Trace: SWS_Dcm_01154 */
    LddRetVal = LpSecLvlCfg->pGetSecurityAttemptCounterFun(
      DCM_INITIAL, &LucAttCounter);

    if (LddRetVal == DCM_E_PENDING)
    {
      /* @Trace: SWS_Dcm_01351 */
      Dcm_TriggerGetAttPending(SecLvlIdx);
    }
    else
    {
      /* @Trace: SWS_Dcm_01156 */
      Dcm_WriteAttCounter(
        SecLvlIdx,
        (LddRetVal == E_OK) ? LucAttCounter : LpSecLvlCfg->ucSecNumMaxAttDelay);
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityAttemptCounterPending                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security level attempt counter              **
**                        in case the operation status is DCM_PENDING         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterPending(
  uint8 SecLvlIdx)
{
  Std_ReturnType LddRetVal;
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg;

  if (DCM_TRUE == Dcm_IsGetAttPending(SecLvlIdx))
  {
    LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

    if (NULL_PTR != LpSecLvlCfg)
    {
      LddRetVal = LpSecLvlCfg->pGetSecurityAttemptCounterFun(
        DCM_PENDING, &LucAttCounter);

      if (LddRetVal != DCM_E_PENDING)
      {
        /* Clear pending operation for specific security level */
        Dcm_ClearGetAttPending(SecLvlIdx);

        /* @Trace: SWS_Dcm_01156 */
        Dcm_WriteAttCounter(
          SecLvlIdx,
          (LddRetVal == E_OK) ? LucAttCounter : LpSecLvlCfg->ucSecNumMaxAttDelay);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_GetSecurityAttemptCounterCancel                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security level attempt counter              **
**                        in case the operation status is DCM_CANCEL          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_GetSecurityAttemptCounterCancel(
  uint8 SecLvlIdx)
{
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg = NULL_PTR;

  if (DCM_TRUE == Dcm_IsGetAttPending(SecLvlIdx))
  {
    LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

    if (NULL_PTR != LpSecLvlCfg)
    {
      /* Do not check return value in case cancel */
      /* @Trace: SWS_Dcm_01352 */
      (void) LpSecLvlCfg->pGetSecurityAttemptCounterFun(
        DCM_CANCEL, &LucAttCounter);

      /* @Trace: SWS_Dcm_01353 */
      Dcm_ClearGetAttPending(SecLvlIdx);
      Dcm_WriteAttCounter(SecLvlIdx, LpSecLvlCfg->ucSecNumMaxAttDelay);
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_IsGetSecurityAttemptCountersPending             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check if the restore operation is remain            **
**                        pending state or not                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(boolean, DCM_CODE) Dcm_IsGetSecurityAttemptCountersPending(void)
{
  boolean LblRetVal = DCM_FALSE;

  if (DCM_ZERO != Dcm_ReadGetAttPendingCount())
  {
    LblRetVal = DCM_TRUE;
  }

  return LblRetVal;
}

/*******************************************************************************
** Function Name        : Dcm_TriggerGetAttPending                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Trigger the pending state of get                    **
**                        the security attempt counter operation              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_TriggerGetAttPending(
  uint8 SecLvlIdx)
{
  uint8 GetAttPendingCount = DCM_ZERO;
  
  Dcm_WriteGetAttPending(SecLvlIdx, DCM_TRUE);

  GetAttPendingCount = Dcm_ReadGetAttPendingCount();

  GetAttPendingCount++;
  Dcm_WriteGetAttPendingCount(GetAttPendingCount);
}

/*******************************************************************************
** Function Name        : Dcm_ClearGetAttPending                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Clear the pending state of get                      **
**                        the security attempt counter operation              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_ClearGetAttPending(
  uint8 SecLvlIdx)
{
  uint8 GetAttPendingCount = DCM_ZERO;

  Dcm_WriteGetAttPending(SecLvlIdx, DCM_FALSE);

  GetAttPendingCount = Dcm_ReadGetAttPendingCount();

  GetAttPendingCount--;
  Dcm_WriteGetAttPendingCount(GetAttPendingCount);
}

/*******************************************************************************
** Function Name        : Dcm_InvokeSetSecurityAttemptCounter                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Main function to set the security attempt counter   **
**                        for all security level                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : OpStatus                                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_InvokeSetSecurityAttemptCounter(
  Dcm_OpStatusType OpStatus)
{
  uint8 SecLvlIdx = Dcm_GetSecurityLevelIndex();

  Dcm_Internal_SetSecurityAttemptCounterFunType SetSecurityAttemptCounterFun[] = 
  {
    Dcm_SetSecurityAttemptCounterInitial
    , Dcm_SetSecurityAttemptCounterPending
    , Dcm_SetSecurityAttemptCounterCancel
  };

  /* @Trace: SWS_Dcm_01155 */
  SetSecurityAttemptCounterFun[OpStatus](SecLvlIdx);
}

/*******************************************************************************
** Function Name        : Dcm_SetSecurityAttemptCounterInitial                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the security level attempt counter              **
**                        in case the operation status is DCM_INITIAL         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterInitial(
  uint8 SecLvlIdx)
{
  Std_ReturnType LddRetVal;
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg = NULL_PTR;

  LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

  if ((NULL_PTR != LpSecLvlCfg) 
    && (DCM_TRUE == LpSecLvlCfg->blAttemptCounterEnabled)
    && (NULL_PTR != LpSecLvlCfg->pSetSecurityAttemptCounterFun))
  {
    LucAttCounter = Dcm_ReadAttCounter(SecLvlIdx);

    LddRetVal = LpSecLvlCfg->pSetSecurityAttemptCounterFun(
      DCM_INITIAL, LucAttCounter);

    if (DCM_E_PENDING == LddRetVal)
    {
      Dcm_WriteSetAttPending(SecLvlIdx, DCM_TRUE);
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_SetSecurityAttemptCounterPending                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Pending process function of set new security        **
**                        attempt counter value to the application            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterPending(
  uint8 SecLvlIdx)
{
  Std_ReturnType LddRetVal;
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg = NULL_PTR;

  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    LucAttCounter = Dcm_ReadAttCounter(SecLvlIdx);
    LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

    if (NULL_PTR != LpSecLvlCfg)
    {
      LddRetVal = LpSecLvlCfg->pSetSecurityAttemptCounterFun(
        DCM_PENDING, LucAttCounter);

      if (LddRetVal != DCM_E_PENDING)
      {
        Dcm_WriteSetAttPending(SecLvlIdx, DCM_FALSE);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : Dcm_SetSecurityAttemptCounterCancel                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Cancel process function of set new security         **
**                        attempt counter value to the application            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_SetSecurityAttemptCounterCancel(
  uint8 SecLvlIdx)
{
  uint8 LucAttCounter = DCM_ZERO;
  Dcm_SecurityLevConfigConstPtrType LpSecLvlCfg;

  if (DCM_TRUE == Dcm_IsSetSecurityAttemptCountersPending())
  {
    LucAttCounter = Dcm_ReadAttCounter(SecLvlIdx);
    LpSecLvlCfg = Dcm_GetSecurityLevelConfigByIndex(SecLvlIdx);

    if (NULL_PTR != LpSecLvlCfg)
    {
      (void) LpSecLvlCfg->pSetSecurityAttemptCounterFun(DCM_CANCEL, LucAttCounter);

      Dcm_WriteSetAttPending(SecLvlIdx, DCM_FALSE);
    }
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_ReadAttCounter                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the security attempt counter value              **
**                        by index of the security level configuration        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_SERVICE_ENABLED
static FUNC(uint8, DCM_CODE) Dcm_ReadAttCounter(
  uint8 SecLvlIdx)
{
  uint8 AttCounter = DCM_ZERO;

  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    AttCounter = Dcm_GaaSecLevState[SecLvlIdx].ucAttCounter;
    SchM_Exit_Dcm_DATA_UPDATE();
  }

  return AttCounter;
}

/*******************************************************************************
** Function Name        : Dcm_WriteAttCounter                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the security attempt counter value              **
**                        by index of the security level configuration        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx, AttCounter                               **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_WriteAttCounter(
  uint8 SecLvlIdx, 
  uint8 AttCounter)
{
  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    Dcm_GaaSecLevState[SecLvlIdx].ucAttCounter = AttCounter;
    SchM_Exit_Dcm_DATA_UPDATE();
  }
}
#endif

/*******************************************************************************
** Function Name        : Dcm_IsGetAttPending                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Check the pending state of the get security         **
**                        attempt counter by index of security configuration  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx                                           **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
#ifdef SECURITY_ATTEMPT_COUNTER_ENABLED
static FUNC(boolean, DCM_CODE) Dcm_IsGetAttPending(
  uint8 SecLvlIdx)
{
  boolean GetAttPending = DCM_FALSE;

  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    GetAttPending = Dcm_GaaSecLevState[SecLvlIdx].blGetAttPending;
    SchM_Exit_Dcm_DATA_UPDATE();
  }

  return GetAttPending;
}

/*******************************************************************************
** Function Name        : Dcm_WriteGetAttPending                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the pending state of get attempt counter        **
**                        operation by index of security configuration        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx, GetAttPending                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_WriteGetAttPending(
  uint8 SecLvlIdx, 
  boolean GetAttPending)
{
  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    Dcm_GaaSecLevState[SecLvlIdx].blGetAttPending = GetAttPending;
    SchM_Exit_Dcm_DATA_UPDATE();
  }

}

/*******************************************************************************
** Function Name        : Dcm_WriteSetAttPending                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the pending state of set attempt counter        **
**                        operation by index of security configuration        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : SecLvlIdx, SetAttPending                            **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_WriteSetAttPending(
  uint8 SecLvlIdx, 
  boolean SetAttPending)
{
  if (DCM_TRUE == Dcm_IsSecurityLevelIndexValid(SecLvlIdx))
  {
    SchM_Enter_Dcm_DATA_UPDATE();
    Dcm_GaaSecLevState[SecLvlIdx].blSetAttPending = SetAttPending;
    SchM_Exit_Dcm_DATA_UPDATE();
  }
}

/*******************************************************************************
** Function Name        : Dcm_ReadGetAttPendingCount                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Get the number pending state of get security        **
**                        attempt counter operation                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(uint8, DCM_CODE) Dcm_ReadGetAttPendingCount(void)
{
  uint8 GetAttPendingCount = DCM_FALSE;

  SchM_Enter_Dcm_DATA_UPDATE();
  GetAttPendingCount = Dcm_GddAttCounterControl.ucGetAttPendingCount;
  SchM_Exit_Dcm_DATA_UPDATE();

  return GetAttPendingCount;
}

/*******************************************************************************
** Function Name        : Dcm_WriteGetAttPendingCount                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Set the number pending state of get security        **
**                        attempt counter operation                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : GetAttPendingCount                                  **
**                                                                            **
** InOut Parameters     : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
**                                                                            **
*******************************************************************************/
static FUNC(void, DCM_CODE) Dcm_WriteGetAttPendingCount(
  uint8 GetAttPendingCount)
{
  SchM_Enter_Dcm_DATA_UPDATE();
  Dcm_GddAttCounterControl.ucGetAttPendingCount = GetAttPendingCount;
  SchM_Exit_Dcm_DATA_UPDATE();
}
#endif

#define DCM_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
