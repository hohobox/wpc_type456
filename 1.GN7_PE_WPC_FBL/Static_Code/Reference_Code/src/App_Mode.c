/*******************************************************************************
**                                                                            **
**  (C) 2015 HYUNDAI AUTRON Co., Ltd.                                         **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  FILE-NAME : App_Mode.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Application Mode SWC                                  **
**                                                                            **
**  PURPOSE   : Sample SWC code for Application Mode                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
*******************************************************************************/

/*******************************************************************************
**                     Include Section                                        **
*******************************************************************************/
#include "Rte_SWC_AppMode.h"

/*******************************************************************************
**                      Global Data Declaration                               **
*******************************************************************************/
#define APP_MODE_USER 0u


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
uint8 AppMode_GucTestCount = 50u;
uint8 AppMode_GucWakeupCount = 0u;
uint8 AppMode_GucBusoffCount = 0u;
static Rte_ModeType_MDG_WakeupEvent AppMode_GddWakeupEvent = RTE_MODE_MDG_WakeupEvent_INITIAL_MODE;


static Rte_ModeType_MDG_ComMMode AppMode_GddComMMode_BCAN = RTE_MODE_MDG_ComMMode_NO_COM;
static Rte_ModeType_MDG_CanSMBORState AppMode_GddBORState_BCAN = RTE_MODE_MDG_CanSMBORState_COMPLETE;

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
/*******************************************************************************
** Function Name        : AppMode_InitCompleted                               **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when BSW Init Completed            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_InitCompleted(void)
{
  Rte_ModeType_MDG_InitState LddPrevInitState, LddNextInitState;
  (void)Rte_Mode_modeNotificationPort_InitState_InitState(&LddPrevInitState, &LddNextInitState);
  /* Condition when BSW initialization completed */
  if (LddNextInitState == RTE_MODE_MDG_InitState_COMPLETE)
  {
  }
  else
  {
    /* for MISRA-C:2012 15.7 */
  }
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"

/*******************************************************************************
** Function Name        : AppMode_EcuModeSwitched                             **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when EcuMode updated from BswM     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_EcuModeSwitched(void)
{
  Rte_ModeType_EcuMode LddPrevEcuMode, LddNextEcuMode;
  (void)Rte_Mode_modeNotificationPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);

  if (LddNextEcuMode == RTE_MODE_EcuMode_ECUM_STATE_RUN)
  {
    /* Condition when ECU state changed from STARTUP to RUN */
    if(AppMode_GddWakeupEvent == RTE_MODE_MDG_WakeupEvent_INITIAL_MODE)
    {
      /* first It need to the Run Request */
      (void)Rte_Call_clientPort_StateRequest_RequestRUN(APP_MODE_USER);

      /* This code is executed only once shortly after Rte_Start */
      (void)Rte_Write_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_FULL_COM);
    }
    /* Condition when ECU state changed from SLEEP to RUN */
    else
    {
    }
    /* When State is RTE_MODE_EcuMode_ECUM_STATE_RUN, execute last */
    (void)Rte_Call_clientPort_StateRequest_SetRunState();
  }
  /* FullCom Request for Integration Test */
  /* This action depends on Application Requirement, Modify Here */
}

#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"

/*******************************************************************************
** Function Name        : AppMode_WakeupEventValidated                        **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when wakeup event occurs           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_WakeupEventValidated(void)
{
  Rte_ModeType_MDG_WakeupEvent LddPrevWakeupEvent;
  Rte_ModeType_EcuMode LddPrevEcuMode;
  Rte_ModeType_EcuMode LddNextEcuMode;
  Rte_ModeType_EcuMode LddCurrEcuMode;

  (void)Rte_Mode_modeNotificationPort_WakeupEvent_WakeupEvent(&LddPrevWakeupEvent, &AppMode_GddWakeupEvent);
  LddCurrEcuMode = Rte_Mode_modeNotificationPort_EcuMode_EcuMode(&LddPrevEcuMode, &LddNextEcuMode);
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"

/*******************************************************************************
** Function Name        : AppMode_ComMModeSwitched_BCAN                    **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when ComM Mode switched            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_ComMModeSwitched_BCAN(void)
{
  Rte_ModeType_MDG_ComMMode LddPrevBusState, LddNextBusState;
  (void)Rte_Mode_modeNotificationPort_ComMMode_BCAN_ComMMode_BCAN(&LddPrevBusState, &LddNextBusState);

  /* Conditions when Com Mode No Com switched */
  if (LddNextBusState == RTE_MODE_MDG_ComMMode_NO_COM)
  {
  }
  /* Conditions when Com Mode Silent Com switched */
  else if (LddNextBusState == RTE_MODE_MDG_ComMMode_SILENT_COM)
  {
  }
  /* Conditions when Com Mode Full Com switched */
  else if (LddNextBusState == RTE_MODE_MDG_ComMMode_FULL_COM)
  {
  }
  else
  {
    /* for MISRA-C:2012 15.7 */
  }
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"
/*******************************************************************************
** Function Name        : AppMode_CanSMBORStateSwitched_BCAN               **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Runnable invoked when CanSM Busoff Recovery State   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/

#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_CanSMBORStateSwitched_BCAN(void)
{
  Rte_ModeType_MDG_CanSMBORState LddPrevState;
  (void)Rte_Mode_modeNotificationPort_CanSMBORState_BCAN_CanSMBORState_BCAN(&LddPrevState, &AppMode_GddBORState_BCAN);
  /* Conditions when bus-off recovery started */
  if (AppMode_GddBORState_BCAN == RTE_MODE_MDG_CanSMBORState_START)
  {
  }
  /* Conditions when bus-off recovery completed */
  else if (AppMode_GddBORState_BCAN == RTE_MODE_MDG_CanSMBORState_COMPLETE)
  {
  }
  else
  {
    /* for MISRA-C:2012 15.7 */
  }
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"

/*******************************************************************************
** Function Name        : AppMode_Test                                        **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          : Test application runnable                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#define SWC_AppMode_START_SEC_CODE
#include "SWC_AppMode_MemMap.h"
FUNC(void,AppMode_CODE) AppMode_Test(void)
{
	static uint8 AppMode_GucTestCase = 0u;
	static uint8 AppMode_WdgTestCase = 0u;
	static uint16 WdgCounter = 0u;
	
    switch (AppMode_GucTestCase)
    {
    case 1: /* ECU RUN Request */
      (void)Rte_Call_clientPort_StateRequest_RequestRUN(APP_MODE_USER);
      (void)Rte_Write_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_FULL_COM);
      AppMode_GucTestCase = 0;
      break;
    case 2: /* ECU OFF Request */
      (void)Rte_Write_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_NO_COM);
      (void)Rte_Call_clientPort_StateRequest_RequestOff(APP_MODE_USER);
      AppMode_GucTestCase = 0;
      break;
    case 3: /* ECU RESET Request */
      (void)Rte_Write_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_NO_COM);
      (void)Rte_Call_clientPort_StateRequest_RequestReset(APP_MODE_USER);
      AppMode_GucTestCase = 0;
      break;
    case 4: /* NO COM Request */
      (void)Rte_Write_modeRequestPort_ComMMode_BCAN_ComMMode_BCAN(COMM_MODE_NO_COM);
      AppMode_GucTestCase = 0;
      break;
    case 5: /* Sleep Request */
      /* Check that All CommMode are NO_COM) */
      (void)Rte_Call_clientPort_StateRequest_RequestSleep(APP_MODE_USER);
      AppMode_GucTestCase = 0;
      break;


    default:
      /* for MISRA-C:2012 16.4 */
      break;
    }
}
#define SWC_AppMode_STOP_SEC_CODE
#include "SWC_AppMode_MemMap.h"
