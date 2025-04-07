/*******************************************************************************
**  (C) 2021 HYUNDAI AUTOEVER Corp								              **
**  Confidential Proprietary Information. Distribution Limited. 			  **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: CanNm.c                                                       **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR CAN Network Management Protocol                       **
**                                                                            **
**  PURPOSE   : APIs implementation for CanNm module                          **
**              CanNm_LocalProcessMsgTimeOutTime                              **
**              CanNm_LocalGetNmStateTypeFromCanNmModeState                   **
**              CanNm_LocalStateChangeNotification                            **
**              CanNm_LocalNetworkModeEntry                                   **
**              CanNm_LocalRepeatMessageStateEntry                            **
**              CanNm_LocalNormalOperationStateEntry                          **
**              CanNm_LocalReadySleepStateEntry                               **
**              CanNm_LocalPrepareBusSleepModeEntry                           **
**              CanNm_LocalBusSleepModeEntry                                  **
**              CanNm_LocalNetworkModeExit                                    **
**              CanNm_LocalRepeatMessageStateExit                             **
**              CanNm_LocalNormalOperationStateExit                           **
**              CanNm_LocalReadySleepStateExit                                **
**              CanNm_LocalPrepareBusSleepModeExit                            **
**              CanNm_LocalBusSleepModeExit                                   **
**              CanNm_LocalBusSleepMode                                       **
**              CanNm_LocalPrepareBusSleepMode                                **
**              CanNm_LocalReadySleepState                                    **
**              CanNm_LocalNormalOperationState                               **
**              CanNm_LocalRepeatMessageState                                 **
**              CanNm_LocalProcessEIRATimer                                   **
**              CanNm_LocalProcessERATimer                                    **
**              CanNm_LocalProcessNmState                                     **
**              CanNm_LocalProcessNmMessage                                   **
**              CanNm_MainFunction                                            **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:  No                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                Description                      **
********************************************************************************
** 2.0.0     12-Nov-2018   JeongSu Lim       Initial version                  **
** 2.0.1     17-May-2019   JeongSu Lim       #16862, 16461                    **
** 2.0.2     15-May-2020   JeongSu Lim       #21327, 23387                    **
** 2.1.0.1   27-Nov-2020   Sanghoon Kim      #25246                           **
** 2.1.1.0   28-Jan-2021   Sanghoon Kim      #28031                           **
** 2.2.0.0   24-Sep-2021   HM Shin           #28765, 31794                    **
** 2.2.4.0   08-Jul-2022   Jaeho Yang        #33026, 36298, 36537             **
** 2.2.5.0   16-Aug-2022   HM Shin           #37036                           **
** 2.2.7.0   07-Oct-2022   Jaeho Yang        #37629                           **
** 2.3.0.0   31-Jan-2023   SM Kwon           #38978                           **
** 2.4.0.0   22-Aug-2023   JW Oh             #40502                           **
** 2.5.0.0   04-Nov-2023   JW Oh             #41382, 40500                    **
** 2.5.1.0   20-Dec-2024   SH Goh            #47658                           **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "CanNm.h"                /* CanNm API Header File */
#include "CanNm_Internal.h"       /* CanNm Internal Functions header file */

#include "Det.h"                  /* Det Header File */
#include "CanNm_Error.h"          /* Det Header File */

#include "SchM_CanNm.h"           /* Schedule Manager header file */
#include "Nm_Cbk.h"               /* NM CallBack Functions Header File */

#include "PduR_CanNm.h"           /* PduR Header File */

#include "CanIf.h"                /* CanIf Header File */

#include "Nm_Cfg.h"             /* Nm configuration header file */

/*******************************************************************************
**                      Version Information                                   **
*******************************************************************************/

/* AUTOSAR specification version information */
#define CANNM_C_AR_RELEASE_MAJOR_VERSION    4
#define CANNM_C_AR_RELEASE_MINOR_VERSION    0
#define CANNM_C_AR_RELEASE_REVISION_VERSION 3

/* CanNm software version information */
#define CANNM_C_SW_MAJOR_VERSION            2
#define CANNM_C_SW_MINOR_VERSION            5
#define CANNM_C_SW_PATCH_VERSION            1

/*******************************************************************************
**                      Version Check                                         **
*******************************************************************************/

#if (CANNM_AR_RELEASE_MAJOR_VERSION != CANNM_C_AR_RELEASE_MAJOR_VERSION)
#error "CanNm.c : Mismatch in Specification Major Version"
#endif

#if (CANNM_AR_RELEASE_MINOR_VERSION != CANNM_C_AR_RELEASE_MINOR_VERSION)
#error "CanNm.c : Mismatch in Specification Minor Version"
#endif

#if (CANNM_AR_RELEASE_REVISION_VERSION != CANNM_C_AR_RELEASE_REVISION_VERSION)
#error "CanNm.c : Mismatch in Specification Revision Version"
#endif

#if (CANNM_SW_MAJOR_VERSION != CANNM_C_SW_MAJOR_VERSION)
#error "CanNm.c : Mismatch in Software Major Version"
#endif

#if (CANNM_SW_MINOR_VERSION != CANNM_C_SW_MINOR_VERSION)
#error "CanNm.c : Mismatch in Software Minor Version"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/* polyspace-begin RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
#define CANNM_START_SEC_CODE
#include "MemMap.h"

static FUNC(void, CANNM_Code) CanNm_LocalProcessMsgTimeOutTime(void);

static FUNC(boolean, CANNM_CODE) CanNm_LocalGetNmStateTypeFromCanNmModeState(
  CanNm_ModeState LddCanNmModeState,
  P2VAR(Nm_StateType, AUTOMATIC, CANNM_VAR) LpNmState);

static FUNC(void, CANNM_CODE) CanNm_LocalStateChangeNotification(
  uint32 LulCanNmChannelIndex,
  CanNm_ModeState LddCanNmPreviousState,
  CanNm_ModeState LddCanNmCurrentState);

static FUNC(void, CANNM_CODE) CanNm_LocalNetworkModeEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageStateEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationStateEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepStateEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepModeEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepModeEntry(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalNetworkModeExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageStateExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationStateExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepStateExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepModeExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepModeExit(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepMode(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepMode(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepState(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationState(uint32 LulCanNmChannelIndex);

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageState(uint32 LulCanNmChannelIndex);
#if (CANNM_PNEIRACALCENABLED == STD_ON)
static FUNC(void, CANNM_CODE) CanNm_LocalProcessEIRATimer(void);
#endif
#if (CANNM_PNERACALCENABLED == STD_ON)
static FUNC(void, CANNM_CODE) CanNm_LocalProcessERATimer(void);
#endif
static FUNC(void, CANNM_CODE) CanNm_LocalProcessNmState(uint32 LulCanNmChannelIndex, CanNm_ModeState previousMode, CanNm_ModeState currentMode);

static FUNC(void, CANNM_CODE) CanNm_LocalProcessNmMessage(void);

/*******************************************************************************
** Function Name        : CanNm_LocalProcessMsgTimeOutTime                    **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get Nm State From CanNm Mode State                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GddNumberOfChannels                           **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        Nm_TxTimeoutException                               **
**                        CanSM_TxTimeoutException                            **
*******************************************************************************/

static FUNC(void, CANNM_Code) CanNm_LocalProcessMsgTimeOutTime(void)
{
  uint32 LulCanNmChannelIndex;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  for (LulCanNmChannelIndex = 0U; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
  {
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    SchM_Enter_CanNm_INTERNAL_STATUS();
    if (LpChannel->ddMsgTimeOutTime > 0)
    {
      LpChannel->ddMsgTimeOutTime--;

      if (LpChannel->ddMsgTimeOutTime == 0)
      {
        LpChannel->ddTxState = CANNM_TX_STATE_READY;
        SchM_Exit_CanNm_INTERNAL_STATUS();
        pfnNm_TxTimeoutException(LpStaticChannel->ddNmChannelHandle);
        #if (CANNM_GLOBALPNSUPPORT == STD_ON)
        pfnCanSM_TxTimeoutException(LpStaticChannel->ddNmChannelHandle);
        #endif
      }
      else
      {
        SchM_Exit_CanNm_INTERNAL_STATUS();
      }
    }
    else
    {
      SchM_Exit_CanNm_INTERNAL_STATUS();
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalGetNmStateTypeFromCanNmModeState         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Get Nm State From CanNm Mode State                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(boolean, CANNM_CODE) CanNm_LocalGetNmStateTypeFromCanNmModeState(
  CanNm_ModeState LddCanNmModeState,
  P2VAR(Nm_StateType, AUTOMATIC, CANNM_VAR) LpNmState)
{
  boolean LblResult = CANNM_TRUE;

  if (LddCanNmModeState == CANNM_BUS_SLEEP_MODE)
  {
    *LpNmState = NM_STATE_BUS_SLEEP;
  }
  else if (LddCanNmModeState == CANNM_PREPAREBUS_SLEEP_MODE)
  {
    *LpNmState = NM_STATE_PREPARE_BUS_SLEEP;
  }
  else if (LddCanNmModeState == CANNM_READY_SLEEP_STATE)
  {
    *LpNmState = NM_STATE_READY_SLEEP;
  }
  else if (LddCanNmModeState == CANNM_NORMAL_OPERATION_STATE)
  {
    *LpNmState = NM_STATE_NORMAL_OPERATION;
  }
  else if (LddCanNmModeState == CANNM_REPEAT_MESSAGE_STATE)
  {
    *LpNmState = NM_STATE_REPEAT_MESSAGE;
  }
  else if (LddCanNmModeState == CANNM_STATE_UNINIT)
  {
    *LpNmState = NM_STATE_UNINIT;
  }
  else
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
    LblResult = CANNM_FALSE;
  }

  return LblResult;
}

/*******************************************************************************
** Function Name        : CanNm_LocalStateChangeNotification                  **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Process State Change Notification                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblStateChangeIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_LocalGetNmStateTypeFromCanNmModeState         **
**                        Nm_StateChangeNotification                          **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalStateChangeNotification(
  uint32 LulCanNmChannelIndex,
  CanNm_ModeState LddCanNmPreviousState,
  CanNm_ModeState LddCanNmCurrentState)
{
  #if (CANNM_STATECHANGEINDENABLED == STD_ON)
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif

  if (pfnNm_StateChangeNotification != NULL_PTR)
  {
    NetworkHandleType LddNmNetworkHandle;
    Nm_StateType LddNmPreviousState;
    Nm_StateType LddNmCurrentState;
    boolean LblNmPreviousStateResult;
    boolean LblNmCurrentStateResult;

    LddNmNetworkHandle = LpStaticChannel->ddNmChannelHandle;

    LblNmPreviousStateResult = CanNm_LocalGetNmStateTypeFromCanNmModeState(LddCanNmPreviousState, &LddNmPreviousState);
    LblNmCurrentStateResult = CanNm_LocalGetNmStateTypeFromCanNmModeState(LddCanNmCurrentState, &LddNmCurrentState);

    /* Notify the upper layer */
    if ((LblNmPreviousStateResult == CANNM_TRUE) && (LblNmCurrentStateResult == CANNM_TRUE))
    {
      pfnNm_StateChangeNotification(LddNmNetworkHandle,
                                    LddNmPreviousState,
                                    LddNmCurrentState);
    }
  }
  #endif
}

/*******************************************************************************
** Function Name        : CanNm_LocalNetworkModeEntry                         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Network-Mode                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        Nm_NetworkMode                                      **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalNetworkModeEntry(uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif

  if ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) ||
           (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE) ||
           (LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    Nm_NetworkMode(LpStaticChannel->ddNmChannelHandle);

    LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
    LpChannel->enNtwkTimeOutTimerState = CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING;

    /* #40502 [SWS_CanNm_00341]
	If CanNm enter the NetworkMode, Receive of SRB, 
	Call of Coord Ready To Sleep Indication can be call continuously
	If there is no flag unset logic when Nm Msg with same SRB */
    if(LpChannel->blTxNmCoordinatorSleepReadyBit == CANNM_TRUE)
    {
  	  LpChannel->blTxNmCoordinatorSleepReadyBit = CANNM_FALSE;
    }
	if(LpChannel->blNmCoordinatorSlpRdyBtMsgReceived == CANNM_TRUE)
    {
      LpChannel->blNmCoordinatorSlpRdyBtMsgReceived = CANNM_FALSE;
      LpChannel->blNmCoordReadyToSleepIndicationCalled = CANNM_FALSE;
      LpChannel->blNmCoordReadyToCancellationCalled = CANNM_TRUE;
    }
	/* end of #40502 [SWS_CanNm_00341] */
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalRepeatMessageStateEntry                  **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Repeat-Message-State             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalStateChangeNotification                  **
**                        Nm_RemoteSleepCancellation                          **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageStateEntry(uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif

  if (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CanNm_ModeState LddPrevState;

    LddPrevState = LpChannel->ddModeStatus;

    /*Update the mode */
    LpChannel->ddModeStatus = CANNM_REPEAT_MESSAGE_STATE;

    CanNm_LocalStateChangeNotification(LulCanNmChannelIndex, LddPrevState, CANNM_REPEAT_MESSAGE_STATE);

    #if (CANNM_BUSLOADREDUCTIONENABLED == STD_ON)
    #if (CANNM_SINGLE_CHANNEL == STD_OFF)
    if (LpStaticChannel->blBusLoadRedActive == CANNM_TRUE)
    #endif
    {
      LpChannel->blBusLoadReductionEnabled = CANNM_FALSE;
    }
    #endif

    #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
	/* #40502 [SWS_CanNm_00152]
	If Remote Sleep Indication has been previously detected, and RMS is entered from NOS or RSS, 
	CanNm shall call the Nm_RemoteSleepCancellation() */
    if ((LpChannel->blRemoteSlpDetect == CANNM_TRUE)
	     && ((LddPrevState == CANNM_NORMAL_OPERATION_STATE) || (LddPrevState == CANNM_READY_SLEEP_STATE)))
    {
      LpChannel->blRemoteSlpDetect = CANNM_FALSE;
      pfnNm_RemoteSleepCancellation(LpStaticChannel->ddNmChannelHandle);
    }
    #endif
	/* end of #40502 [SWS_CanNm_00152] */

    LpChannel->ddRepeatMessageTime = LpStaticChannel->ddRepeatMsgTime;

    /*
     * [SWS_CanNm_00334]
     * When entering the Repeat Message State from Bus Sleep Mode or
     * Prepare Bus Sleep Mode because of CanNm_NetworkRequest() (active wakeup)
     * and if CanNmImmediateNmTransmissions is greater zero,
     * the NM PDUs shall be transmitted using CanNmImmediateNmCycleTime as cycle time
     */
    if ((CANNM_TRUE == LpChannel->blNetworkRequested)
        && (LpStaticChannel->ucNoOfImmediateNmTx > 0)
        && ((CANNM_BUS_SLEEP_MODE == LddPrevState) || (CANNM_PREPAREBUS_SLEEP_MODE == LddPrevState)))
    {
      LpChannel->ucNoOfImmediateNmTx = LpStaticChannel->ucNoOfImmediateNmTx;
      LpChannel->ddMsgCycleTime = 1;
    }
    else
    {
      LpChannel->ddMsgCycleTime = LpStaticChannel->ddMsgCycleOffset + 1;
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalNormalOperationStateEntry                **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Normal-Operation-State           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalStateChangeNotification                  **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationStateEntry(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CanNm_ModeState LddPrevState;
    #if ((CANNM_REMOTESLEEPINDENABLED == STD_ON) ||      \
         ((CANNM_BUSLOADREDUCTIONENABLED == STD_ON) &&   \
          (CANNM_SINGLE_CHANNEL == STD_OFF)))
    P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    #endif

    LddPrevState = LpChannel->ddModeStatus;

    /*Update the mode */
    LpChannel->ddModeStatus = CANNM_NORMAL_OPERATION_STATE;

    CanNm_LocalStateChangeNotification(LulCanNmChannelIndex, LddPrevState, CANNM_NORMAL_OPERATION_STATE);
    #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
    {
	  /* #40502 [SWS_CanNm_00150]
      Nm_RemoteSleepIndication() can be called if blRemoteSlpDetect flag is false */
      /* Start the remote sleep indication timer */
      LpChannel->ddRemoteSleepIndTime = LpStaticChannel->ddRemoteSleepIndTime;
      LpChannel->blRemoteSlpDetect = CANNM_FALSE;
	  /* end of #40502 [SWS_CanNm_00150] */
    }
    #endif

    if (LddPrevState == CANNM_READY_SLEEP_STATE)
    {
      LpChannel->ddMsgCycleTime = 1;
    }

    #if (CANNM_BUSLOADREDUCTIONENABLED == STD_ON)
    {
      #if (CANNM_SINGLE_CHANNEL == STD_OFF)
      if (LpStaticChannel->blBusLoadRedActive == CANNM_TRUE)
      #endif
      {
        LpChannel->blBusLoadReductionEnabled = CANNM_TRUE;
      }
    }
    #endif
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalReadySleepStateEntry                     **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Ready-Sleep-State                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalStateChangeNotification                  **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepStateEntry(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus == CANNM_READY_SLEEP_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CanNm_ModeState LddPrevState;

    LddPrevState = LpChannel->ddModeStatus;

    /*Update the mode */
    LpChannel->ddModeStatus = CANNM_READY_SLEEP_STATE;

    CanNm_LocalStateChangeNotification(LulCanNmChannelIndex, LddPrevState, CANNM_READY_SLEEP_STATE);

    LpChannel->ddMsgCycleTime = 0;
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalPrepareBusSleepModeEntry                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Prepare-Bus-Sleep-Mode           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalStateChangeNotification                  **
**                        Nm_PrepareBusSleepMode                              **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepModeEntry(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  if (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CanNm_ModeState LddPrevState;

    LddPrevState = LpChannel->ddModeStatus;

    /*Update the mode */
    LpChannel->ddModeStatus = CANNM_PREPAREBUS_SLEEP_MODE;

    CanNm_LocalStateChangeNotification(LulCanNmChannelIndex, LddPrevState, CANNM_PREPAREBUS_SLEEP_MODE);

    /* Notify the Upper Layer that Prepare Bus sleep mode has been entered */
    Nm_PrepareBusSleepMode(LpStaticChannel->ddNmChannelHandle);

	#if (CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
    /* [Change Wait Bus Sleep Timer API]  
     * If Changing T-Wait Bus Sleep API has been called, 
	 * CanNm_GulUserRequestTWaitBusSleepTime is not CANNM_TWBSINVALID value.
     */
    if(CanNm_GulUserRequestTWaitBusSleepTime != CANNM_CHANGETWAITBUSSLEEPINVALID){
    	LpChannel->ddWaitBusSleepTime = CanNm_GulUserRequestTWaitBusSleepTime;
    }else
	#endif
    {
    	/* Start wait Bus Sleep Timer */
    	LpChannel->ddWaitBusSleepTime = LpStaticChannel->ddWaitBusSleepTime;
    }

  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalBusSleepModeEntry                        **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Entry function for Bus-Sleep-Mode                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalStateChangeNotification                  **
**                        Nm_BusSleepMode                                     **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepModeEntry(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  if (LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    CanNm_ModeState LddPrevState;

    LddPrevState = LpChannel->ddModeStatus;
    /*Update the mode */
    LpChannel->ddModeStatus = CANNM_BUS_SLEEP_MODE;
    CanNm_LocalStateChangeNotification(LulCanNmChannelIndex, LddPrevState, CANNM_BUS_SLEEP_MODE);
    /* Notify the Upper Layer that Bus sleep mode has been entered */
    Nm_BusSleepMode(LpStaticChannel->ddNmChannelHandle);
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalNetworkModeExit                          **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Network-Mode                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalNetworkModeExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  if ((LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE) &&
           (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE) &&
           (LpChannel->ddModeStatus != CANNM_READY_SLEEP_STATE))
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    if ((LpStaticChannel->blActiveWakeupBitEnabled == CANNM_TRUE) && (LpChannel->blTxActiveWakeUpBit == CANNM_TRUE))
    {
      LpChannel->blTxActiveWakeUpBit = CANNM_FALSE;
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalRepeatMessageStateExit                   **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Repeat-Message-State              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblNodeDetectionEnabled                       **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageStateExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    LpChannel->ddRepeatMessageTime = 0U;
    #if (CANNM_NODEDETECTIONENABLED == STD_ON)
    LpChannel->blTxRepeatMessageRequested = CANNM_FALSE;
    #endif
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalNormalOperationStateExit                 **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Normal-Operation-State            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationStateExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
    /* Start the remote sleep indication timer */
    LpChannel->ddRemoteSleepIndTime = 0U;
    #endif
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalReadySleepStateExit                      **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Ready-Sleep-State                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepStateExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_READY_SLEEP_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalPrepareBusSleepModeExit                  **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Prepare-Bus-Sleep-Mode            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepModeExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_PREPAREBUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    LpChannel->ddWaitBusSleepTime = 0U;
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalBusSleepModeExit                         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Exit function for Bus-Sleep-Mode                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepModeExit(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_BUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalBusSleepMode                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Main function for Bus-Sleep-Mode                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalBusSleepMode(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_BUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalPrepareBusSleepMode                      **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Main function for Prepare-Bus-Sleep-Mode            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestBusSleepMode                        **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalPrepareBusSleepMode(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_PREPAREBUS_SLEEP_MODE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    if (LpChannel->ddWaitBusSleepTime > 0)
    {
      LpChannel->ddWaitBusSleepTime--;
    }

    if (LpChannel->ddWaitBusSleepTime == 0)
    {
      CanNm_IntRequestBusSleepMode(LulCanNmChannelIndex);
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalReadySleepState                          **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Main function for Normal-Operation-State            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        Nm_RemoteSleepIndication                            **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalReadySleepState(uint32 LulCanNmChannelIndex)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if (LpChannel->ddModeStatus != CANNM_READY_SLEEP_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    if (LpChannel->enNtwkTimeOutTimerState == CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING)
    {
      if (LpChannel->ddNtwkTimeOutTime > 0)
      {
        LpChannel->ddNtwkTimeOutTime--;
      }

      if (LpChannel->ddNtwkTimeOutTime == 0)
      {
        CanNm_IntRequestPrepareBusSleepMode(LulCanNmChannelIndex);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalNormalOperationState                     **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Main function for Normal-Operation-State            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblRemoteSleepIndEnabled                      **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        Nm_RemoteSleepIndication                            **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalNormalOperationState(uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  if (LpChannel->ddModeStatus != CANNM_NORMAL_OPERATION_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    if (LpChannel->enNtwkTimeOutTimerState == CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING)
    {
      if (LpChannel->ddNtwkTimeOutTime > 0)
      {
        LpChannel->ddNtwkTimeOutTime--;
      }

      if (LpChannel->ddNtwkTimeOutTime == 0)
      {
        CanNm_IntDetReportError(CANNM_MODULE_ID, (uint8)LulCanNmChannelIndex, CANNM_MAINFUNCTION_SID, CANNM_E_NETWORK_TIMEOUT);
        LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
      }
    }
    #if (CANNM_REMOTESLEEPINDENABLED == STD_ON)
    if (LpChannel->ddRemoteSleepIndTime > 0)
    {
      LpChannel->ddRemoteSleepIndTime--;

      if (LpChannel->ddRemoteSleepIndTime == 0)
      {
        LpChannel->blRemoteSlpDetect = CANNM_TRUE;

        pfnNm_RemoteSleepIndication(LpStaticChannel->ddNmChannelHandle);
      }
    }
    #endif
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalRepeatMessageState                       **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Main function for Repeat-Message-State              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        NA                                                  **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        CanNm_IntRequestNormalOperationState                **
**                        CanNm_IntRequestReadySleepState                     **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalRepeatMessageState(uint32 LulCanNmChannelIndex)
{
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
  
  #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
  LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
  #else
  LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
  #endif


  if (LpChannel->ddModeStatus != CANNM_REPEAT_MESSAGE_STATE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
  else
  {
    if (LpChannel->enNtwkTimeOutTimerState == CANNM_NETWORK_TIMEOUT_TIMER_STATE_RUNNING)
    {
      if (LpChannel->ddNtwkTimeOutTime > 0)
      {
        LpChannel->ddNtwkTimeOutTime--;
      }
      if (LpChannel->ddNtwkTimeOutTime == 0)
      {
        CanNm_IntDetReportError(CANNM_MODULE_ID, (uint8)LulCanNmChannelIndex, CANNM_MAINFUNCTION_SID, CANNM_E_NETWORK_TIMEOUT);
        LpChannel->ddNtwkTimeOutTime = LpStaticChannel->ddNtwkTimeOutTime;
      }
    }

    if (LpChannel->ddRepeatMessageTime > 0)
    {
      LpChannel->ddRepeatMessageTime--;
    }

    if (LpChannel->ddRepeatMessageTime == 0)
    {
      if (LpChannel->blNetworkRequested == CANNM_TRUE)
      {
        CanNm_IntRequestNormalOperationState(LulCanNmChannelIndex);
      }
      else
      {
        CanNm_IntRequestReadySleepState(LulCanNmChannelIndex);
      }
    }
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalProcessEIRATimer                         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Process EIRA Timer                                  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblPnEiraCalcEnabled                          **
**                        CanNm_GucPnInfoLength                               **
**                        CanNm_GaaPnEIRATimer                                **
**                        CanNm_GaaEIRA                                       **
**                                                                            **
**                        Function(s) invoked:                                **
**                        PduR_CanNmRxIndication                              **
*******************************************************************************/
#if (CANNM_PNEIRACALCENABLED == STD_ON)
static FUNC(void, CANNM_CODE) CanNm_LocalProcessEIRATimer(void)
{
  /* Do EIRATimer */
  uint16 LusIndex;
  boolean LblEIRAChanged = CANNM_FALSE;
  uint16 LusEiraTimerSize = (uint16)(CanNm_GucPnInfoLength * CANNM_EIGHT);

  for (LusIndex = CANNM_ZERO; LusIndex < LusEiraTimerSize; LusIndex++)
  {
    SchM_Enter_CanNm_INTERNAL_STATUS();
    if (CanNm_GaaPnEIRATimer[LusIndex] > CANNM_ZERO)
    {
      CanNm_GaaPnEIRATimer[LusIndex]--;

      if (CanNm_GaaPnEIRATimer[LusIndex] == CANNM_ZERO)
      {
        uint8 LucByteIndex;
        uint8 LucBitIndex;
        
        LucByteIndex = (uint8)(LusIndex / CANNM_EIGHT);
        LucBitIndex = (uint8)(LusIndex % CANNM_EIGHT);

        CanNm_GaaEIRA[LucByteIndex] &= ~(uint8)(CANNM_ONE << (CANNM_SEVEN - LucBitIndex));

        LblEIRAChanged = CANNM_TRUE;
      }
    }
    SchM_Exit_CanNm_INTERNAL_STATUS();
  }
  
  if (LblEIRAChanged == CANNM_TRUE)
  {
    PduInfoType LddPduInfo;

    LddPduInfo.SduLength = CanNm_GucPnInfoLength;
    LddPduInfo.SduDataPtr = CanNm_GaaEIRA;
    
    pfnPduR_CanNmRxIndication(CanNm_GddPduRCanNmRxIndicationEiraHandleId, &LddPduInfo);
  }
}
#endif
/*******************************************************************************
** Function Name        : CanNm_LocalProcessERATimer                          **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Process ERA Timer                                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GddNumberOfChannels                           **
**                        CanNm_GblPnEraCalcEnabled                           **
**                        CanNm_GucPnInfoLength                               **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
**                        PduR_CanNmRxIndication                              **
*******************************************************************************/
#if (CANNM_PNERACALCENABLED == STD_ON)
static FUNC(void, CANNM_CODE) CanNm_LocalProcessERATimer(void)
{
  uint32 LulCanNmChannelIndex;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;

  for (LulCanNmChannelIndex = 0U; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
  {
    uint16 LusIndex;
    boolean LblERAChanged = CANNM_FALSE;
    uint16 LusEraTimerSize = (uint16)(CanNm_GucPnInfoLength * CANNM_EIGHT);

    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];
    
    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    for (LusIndex = 0; LusIndex < LusEraTimerSize; LusIndex++)
    {
      SchM_Enter_CanNm_INTERNAL_STATUS();
      if (LpChannel->aaERATimer[LusIndex] > CANNM_ZERO)
      {
        LpChannel->aaERATimer[LusIndex]--;

        if (LpChannel->aaERATimer[LusIndex] == CANNM_ZERO)
        {
          uint8 LucByteIndex;
          uint8 LucBitIndex;

          LucByteIndex = (uint8)(LusIndex / CANNM_EIGHT);
          LucBitIndex = (uint8)(LusIndex % CANNM_EIGHT);

          LpChannel->aaERA[LucByteIndex] &= ~(uint8)(CANNM_ONE << (CANNM_SEVEN - LucBitIndex));

          LblERAChanged = CANNM_TRUE;
        }
      }
      SchM_Exit_CanNm_INTERNAL_STATUS();
    }

    if (LblERAChanged == CANNM_TRUE)
    {
      PduInfoType LddPduInfo;

      LddPduInfo.SduLength = CanNm_GucPnInfoLength;
      LddPduInfo.SduDataPtr = LpChannel->aaERA;

      pfnPduR_CanNmRxIndication(LpStaticChannel->ddPduRCanNmRxIndicationEraHandleId , &LddPduInfo);
    }
  }
}
#endif
/*******************************************************************************
** Function Name        : CanNm_LocalProcessNmState                           **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Process NM State                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : LulCanNmChannelIndex                                **
**                      : previousMode                                        **
**                      : currentMode                                         **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntDetReportError                             **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalProcessNmState(uint32 LulCanNmChannelIndex, CanNm_ModeState previousMode, CanNm_ModeState currentMode)
{
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

  if ((previousMode == CANNM_REPEAT_MESSAGE_STATE) && (currentMode == CANNM_NORMAL_OPERATION_STATE))
  {
    LpChannel->ddNmState = NM_STATE_NS_RMS;
  }
  else if ((previousMode == CANNM_READY_SLEEP_STATE) && (currentMode == CANNM_NORMAL_OPERATION_STATE))
  {
    LpChannel->ddNmState = NM_STATE_NS_RSS;
  }
  else if ((previousMode == CANNM_BUS_SLEEP_MODE) && (currentMode == CANNM_REPEAT_MESSAGE_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RMS_BSM;
  }
  else if ((previousMode == CANNM_PREPAREBUS_SLEEP_MODE) && (currentMode == CANNM_REPEAT_MESSAGE_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RMS_PBSM;
  }
  else if ((previousMode == CANNM_NORMAL_OPERATION_STATE) && (currentMode == CANNM_REPEAT_MESSAGE_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RMS_NS;
  }
  else if ((previousMode == CANNM_READY_SLEEP_STATE) && (currentMode == CANNM_REPEAT_MESSAGE_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RMS_RSS;
  }
  else if ((previousMode == CANNM_REPEAT_MESSAGE_STATE) && (currentMode == CANNM_READY_SLEEP_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RSS_RMS;
  }
  else if ((previousMode == CANNM_NORMAL_OPERATION_STATE) && (currentMode == CANNM_READY_SLEEP_STATE))
  {
    LpChannel->ddNmState = NM_STATE_RSS_NS;
  }
  else if ((previousMode == CANNM_READY_SLEEP_STATE) && (currentMode == CANNM_PREPAREBUS_SLEEP_MODE))
  {
    LpChannel->ddNmState = NM_STATE_PBSM_RSS;
  }
  else if ((previousMode == CANNM_PREPAREBUS_SLEEP_MODE) && (currentMode == CANNM_BUS_SLEEP_MODE))
  {
    LpChannel->ddNmState = NM_STATE_BSM_PBSM;
  }
  else
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
  }
}

/*******************************************************************************
** Function Name        : CanNm_LocalProcessNmMessage                         **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Process transmission of NM PDU                      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : NA                                                  **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GddNumberOfChannels                           **
**                        CanNm_GblPassiveModeEnabled                         **
**                                                                            **
**                        Function(s) invoked:                                **
**                        CanNm_IntTransmit                                   **
*******************************************************************************/

static FUNC(void, CANNM_CODE) CanNm_LocalProcessNmMessage(void)
{
  uint32 LulCanNmChannelIndex;
  P2CONST(CanNm_StaticChannel, AUTOMATIC, CANNM_CONST) LpStaticChannel;
  P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

  for (LulCanNmChannelIndex = 0U; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
  {
    boolean LblNeedCanNmTransmit = CANNM_FALSE;

    SchM_Enter_CanNm_INTERNAL_STATUS();
    LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

    #if(STD_ON == CANNM_VARIANT_POSTBUILD_SUPPORT)
    LpStaticChannel = &CanNm_GpStaticChannel[LulCanNmChannelIndex];
    #else
    LpStaticChannel = &CanNm_GaaStaticChannel[LulCanNmChannelIndex];
    #endif

    if (LpChannel->ddMsgCycleTime > 0)
    {
      LpChannel->ddMsgCycleTime--;

      if (LpChannel->ddMsgCycleTime == 0)
      {
        if ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) && (LpChannel->ucNoOfImmediateNmTx > 1))
        {
          LpChannel->ddMsgCycleTime = LpStaticChannel->ddImmMsgCycleTime;
        }
        else
        {
          LpChannel->ddMsgCycleTime = LpStaticChannel->ddMsgCycleTime;
        }

        LblNeedCanNmTransmit = CANNM_TRUE;
      }
    }

    if (LpChannel->blTransmissionRequestFailed == CANNM_TRUE)
    {
      LpChannel->blTransmissionRequestFailed = CANNM_FALSE;
      LblNeedCanNmTransmit = CANNM_TRUE;
    }

    SchM_Exit_CanNm_INTERNAL_STATUS();

    #if (CANNM_PASSIVEMODEENABLED == STD_OFF)
    if ((LpChannel->blCommunicationEnabled == CANNM_TRUE) &&
        (LblNeedCanNmTransmit == CANNM_TRUE))
    {

      /* #40502 [SWS_CanNm_00342]
	   * CanNm try to send the Single Nm Pdu of CanNm_SetSleepReadyBit() again,
       * if Msg is not sending in CanIf_Transmit() of CanNm_SetSleepReadyBit().
       * CanNm will try to transmit again in CanNm_LocalProcessNmMessage() in above situations.
       */
      #if(CANNM_PASSIVENODEENABLED != STD_ON)
      if ((LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE) || 
	      (LpChannel->ddModeStatus == CANNM_NORMAL_OPERATION_STATE))
      #else
	  /* [HMC Passive Node]
       * If CanNm State is NOS,
	   * CanNm should not send NM Message in Passive Node.
       */
      if (LpChannel->ddModeStatus == CANNM_REPEAT_MESSAGE_STATE)
      #endif
      {
        if (CanNm_IntTransmit(LulCanNmChannelIndex) == E_OK)
        {
        }
		/* end of #40502 [SWS_CanNm_00342] */
        else
        {
          LpChannel->blTransmissionRequestFailed = CANNM_TRUE;
        }
      }
    }
    #endif
  }
}

/*******************************************************************************
** Function Name        : CanNm_MainFunction                                  **
**                                                                            **
** Service ID           : 0x13                                                **
**                                                                            **
** Description          : Handles the CanNm states and the internal Timers    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-reentrant                                       **
**                                                                            **
** Input Parameters     : NA                                                  **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : NA                                                  **
**                                                                            **
** Return parameter     : NA                                                  **
**                                                                            **
** Preconditions        : CanNm Module should be initialized.                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GblInitStatus                                 **
**                        CanNm_GddNumberOfChannels                           **
**                                                                            **
**                        Function(s) invoked:                                **
**                        SchM_Enter_CanNm_INTERNAL_STATUS                    **
**                        SchM_Exit_CanNm_INTERNAL_STATUS                     **
**                        CanNm_IntDetReportError                             **
**                        CanNm_LocalProcessNmState                           **
**                        CanNm_LocalBusSleepModeExit                         **
**                        CanNm_LocalPrepareBusSleepModeExit                  **
**                        CanNm_LocalReadySleepStateExit                      **
**                        CanNm_LocalNetworkModeExit                          **
**                        CanNm_LocalNormalOperationStateExit                 **
**                        CanNm_LocalRepeatMessageStateExit                   **
**                        CanNm_LocalBusSleepModeEntry                        **
**                        CanNm_LocalPrepareBusSleepModeEntry                 **
**                        CanNm_LocalReadySleepStateEntry                     **
**                        CanNm_LocalNormalOperationStateEntry                **
**                        CanNm_LocalNetworkModeEntry                         **
**                        CanNm_LocalRepeatMessageStateEntry                  **
**                        CanNm_LocalBusSleepMode                             **
**                        CanNm_LocalPrepareBusSleepMode                      **
**                        CanNm_LocalReadySleepState                          **
**                        CanNm_LocalNormalOperationState                     **
**                        CanNm_LocalRepeatMessageState                       **
**                        CanNm_LocalProcessMsgTimeOutTime                    **
**                        CanNm_LocalProcessNmMessage                         **
**                        CanNm_LocalProcessERATimer                          **
**                        CanNm_LocalProcessEIRATimer                         **
*******************************************************************************/
FUNC(void, CANNM_CODE) CanNm_MainFunction(void)
{
  uint32 LulCanNmChannelIndex;

  if (CanNm_GblInitStatus == CANNM_FALSE)
  {
    CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_UNINIT);
  }
  else
  {
    for (LulCanNmChannelIndex = 0U; LulCanNmChannelIndex < CanNm_GddNumberOfChannels; LulCanNmChannelIndex++)
    {
      P2VAR(CanNm_Channel, AUTOMATIC, CANNM_VAR) LpChannel;

      SchM_Enter_CanNm_INTERNAL_STATUS();

      LpChannel = &CanNm_GaaChannel[LulCanNmChannelIndex];

      if (LpChannel->ddModeStatus != LpChannel->ddNextModeState)
      {
        CanNm_LocalProcessNmState(LulCanNmChannelIndex, LpChannel->ddModeStatus, LpChannel->ddNextModeState);

        switch (LpChannel->ddModeStatus)
        {
          case CANNM_BUS_SLEEP_MODE:
            CanNm_LocalBusSleepModeExit(LulCanNmChannelIndex);
            break;

          case CANNM_PREPAREBUS_SLEEP_MODE:
            CanNm_LocalPrepareBusSleepModeExit(LulCanNmChannelIndex);
            break;

          case CANNM_READY_SLEEP_STATE:
            CanNm_LocalReadySleepStateExit(LulCanNmChannelIndex);

            if (LpChannel->ddNextModeState == CANNM_PREPAREBUS_SLEEP_MODE)
            {
              CanNm_LocalNetworkModeExit(LulCanNmChannelIndex);
            }
            break;

          case CANNM_NORMAL_OPERATION_STATE:
            CanNm_LocalNormalOperationStateExit(LulCanNmChannelIndex);
            break;

          case CANNM_REPEAT_MESSAGE_STATE:
            CanNm_LocalRepeatMessageStateExit(LulCanNmChannelIndex);
            break;

          default:
            CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
            break;
        }

        switch (LpChannel->ddNextModeState)
        {
          case CANNM_BUS_SLEEP_MODE:
            CanNm_LocalBusSleepModeEntry(LulCanNmChannelIndex);
            break;

          case CANNM_PREPAREBUS_SLEEP_MODE:
            CanNm_LocalPrepareBusSleepModeEntry(LulCanNmChannelIndex);
            break;

          case CANNM_READY_SLEEP_STATE:
            CanNm_LocalReadySleepStateEntry(LulCanNmChannelIndex);
            break;

          case CANNM_NORMAL_OPERATION_STATE:
            CanNm_LocalNormalOperationStateEntry(LulCanNmChannelIndex);
            break;

          case CANNM_REPEAT_MESSAGE_STATE:
            if ((LpChannel->ddModeStatus == CANNM_BUS_SLEEP_MODE) ||
                (LpChannel->ddModeStatus == CANNM_PREPAREBUS_SLEEP_MODE))
            {
              CanNm_LocalNetworkModeEntry(LulCanNmChannelIndex);
            }

            CanNm_LocalRepeatMessageStateEntry(LulCanNmChannelIndex);
            break;

          default:
            CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
            break;
        }
      }

      switch (LpChannel->ddModeStatus)
      {
        case CANNM_BUS_SLEEP_MODE:
          CanNm_LocalBusSleepMode(LulCanNmChannelIndex);
          break;

        case CANNM_PREPAREBUS_SLEEP_MODE:
          CanNm_LocalPrepareBusSleepMode(LulCanNmChannelIndex);
          break;

        case CANNM_READY_SLEEP_STATE:
          CanNm_LocalReadySleepState(LulCanNmChannelIndex);
          break;

        case CANNM_NORMAL_OPERATION_STATE:
          CanNm_LocalNormalOperationState(LulCanNmChannelIndex);
          break;

        case CANNM_REPEAT_MESSAGE_STATE:
          CanNm_LocalRepeatMessageState(LulCanNmChannelIndex);
          break;

        default:
          CanNm_IntDetReportError(CANNM_MODULE_ID, CANNM_INSTANCE_ID, CANNM_MAINFUNCTION_SID, CANNM_E_INVALID_REQUEST);
          break;
      }

      SchM_Exit_CanNm_INTERNAL_STATUS();
    }
    
    #if (CANNM_PNEIRACALCENABLED == STD_ON)
    CanNm_LocalProcessEIRATimer();
    #endif
    #if (CANNM_PNERACALCENABLED == STD_ON)
    CanNm_LocalProcessERATimer();
    #endif

    CanNm_LocalProcessMsgTimeOutTime();

    CanNm_LocalProcessNmMessage();
       
  }
}
/*******************************************************************************
** Function Name        : CanNm_ChangeTWaitBusSleep                           **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : Change the whole channel CanNmWaitBusSleepTime      **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : TwaitBusSleep                    				            **
**                                                                            **
** InOut parameter      : N/A                                                 **
**                                                                            **
** Output Parameters    : N/A                                                 **
**                                                                            **
** Return parameter     : N/A                                                 **
**                                                                            **
** Preconditions        : N/A                                                 **
**                                                                            **
** Remarks              : Global Variable(s):                                 **
**                        CanNm_GulUserRequestTWaitBusSleepTime               **
**                                                                            **
**                        Function(s) invoked:                                **
*******************************************************************************/

/* [Change Wait Bus Sleep Timer API]  
 * Function definition of "CanNm_ChangeTWaitBusSleep()"
 */
#if(CANNM_CHANGETWAITBUSSLEEPENABLED == STD_ON)
FUNC(void, CANNM_CODE) CanNm_ChangeTWaitBusSleep(
	CONST(uint32, CANNM_CONST) TwaitBusSleep)
{
	CanNm_GulUserRequestTWaitBusSleepTime = (CanNm_LTimeType)(TwaitBusSleep/CANNM_MAINFUNCTIONPERIOD);

	return;
}
#endif

#define CANNM_STOP_SEC_CODE
#include "MemMap.h"
/* polyspace-end RTE:UNR, MISRA-C3:2.1,14.3, DEFECT:DEAD_CODE,USELESS_IF [Justified:Low] "No Impact of this rule violation" */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
