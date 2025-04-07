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
**  SRC-MODULE: Os_MulticoreSend.c                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Inter-core Message sending functionality.        **
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
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.11    10-Feb-2022    YH.Han        Redmine #34322                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     08-Apr-2020    JH.Cho        Redmine #22760                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #10100                      **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4566, #5368                **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.6     08-Jan-2014    SH.Yoo        TASK: xar~810                       **
** 2.0.5     13-Dec-2013    MJ.Woo        CR: xar~212, TASK: xar~796          **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     20-Aug-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    SH.Yoo        CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     15-Mar-2013    Son           Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */


#if (OS_MULTICORE == STD_ON)
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"

#if (OS_TASK == STD_ON)
#include "Os_Task.h"              /* Os Task header file */
#endif
#if (OS_EVENT == STD_ON)
#include "Os_Event.h"             /* Os Event header file */
#endif
#if (OS_ALARM == STD_ON)
#include "Os_Alarm.h"             /* Os Alarm header file */
#endif
#if (OS_COUNTER == STD_ON)
#include "Os_Counter.h"           /* Os Counter header file */
#endif
#if (OS_SCHEDTABLE == STD_ON)
#include "Os_SchedTable.h"        /* Os ScheduleTable header file */
#endif
#if (OS_APPLICATION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Os_SendActivateTask                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending an ActivateTask message    **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : TaskID                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendActivateTask(TaskType TaskID)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_ActivateTask;
  msg.parameter[0] = (uint32)TaskID;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;
  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured memory access index */
  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticTask[TaskID].ddCoreId, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetTaskState                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetTaskState message     **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : t                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetTaskState
(P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) t, TaskStateRefType out)
{
  Os_MessageType msg;
  StatusType result;

  msg.opcode = OS_IC_GetTaskState;
  msg.parameter[0] = (uint32)t->ddTaskId;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  result = Os_SendMessageWait(t->ddCoreId, &msg);

  /* polyspace<MISRA-C:9.1:Not a defect:Justify with annotations> value msg is assigned by Os_SendMessageWait function  */
  /* polyspace<RTE: NIVL : Not a defect:Justify with annotations>  No Impact of this rule violation */
  /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
  *out = (TaskStateType)(msg.parameter[0]);

  return result;
}
#endif

/*******************************************************************************
** Function Name        : Os_SendSetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a SetEvent message         **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : t, e                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendSetEvent
(P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) t, EventMaskType e)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_SetEvent;
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  msg.parameter[0] = (uint32)t->ddTaskId;
  msg.parameter[1] = (uint32)e;
  msg.parameter[2] = (uint32)OS_ZERO;
  /* polyspace<RTE: NIVL : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  return Os_SendMessageWait(t->ddCoreId, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetEvent message         **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : TaskID                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : Event                                               **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetEvent
                                       (TaskType TaskID, EventMaskRefType Event)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_GetEvent;
  msg.parameter[0] = (uint32)TaskID;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[1] = (uint32)Event;
  /* polyspace:end<ISO-17961:intptrconv> */
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticTask[TaskID].ddCoreId, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetAlarm                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetAlarm message         **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetAlarm(AlarmType a, TickRefType out)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_GetAlarm;
  msg.parameter[0] = (uint32)a;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[1] = (uint32)out;
  /* polyspace:end<ISO-17961:intptrconv> */
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticAlarm[a].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetAlarmBase                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetAlarmBase message     **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetAlarmBase(AlarmType AlarmID, \
                                                          AlarmBaseRefType Info)
{
  Os_MessageType msg;
  StatusType result;

  msg.opcode = OS_IC_GetAlarmBase;
  msg.parameter[0] = (uint32)AlarmID;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[1] = (uint32)Info;
  /* polyspace:end<ISO-17961:intptrconv> */
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  result = Os_SendMessageWait(Os_GaaStaticAlarm[AlarmID].ddCoreID, &msg);
  return result;
}
#endif

/*******************************************************************************
** Function Name        : Os_SendSetRelAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a SetRelAlarm message      **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a, inc, cyc                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendSetRelAlarm(AlarmType a, TickType inc,
                                                                   TickType cyc)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_SetRelAlarm;
  msg.parameter[0] = (uint32)a;
  msg.parameter[1] = (uint32)inc;
  msg.parameter[2] = (uint32)cyc;

  /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticAlarm[a].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendSetAbsAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a SetAbsAlarm message      **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a, start, cyc                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendSetAbsAlarm(AlarmType a, TickType Start,
                                                                   TickType cyc)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_SetAbsAlarm;
  msg.parameter[0] = (uint32)a;
  msg.parameter[1] = (uint32)Start;
  msg.parameter[2] = (uint32)cyc;

  /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticAlarm[a].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendCancelAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a CancelAlarm message      **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendCancelAlarm(AlarmType a)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_CancelAlarm;
  msg.parameter[0] = (uint32)a;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  return Os_SendMessageWait(Os_GaaStaticAlarm[a].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetCounterValue                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetCounterValue message  **
**                        and waits until message is returned.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : c                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetCounterValue(CounterType c, TickRefType out)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_GetCounterValue;
  msg.parameter[0] = (uint32)c;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[1] = (uint32)out;
  /* polyspace:end<ISO-17961:intptrconv> */
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  return Os_SendMessageWait(Os_GaaStaticCounter[c].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetElapsedCounterValue                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetElapsedCounterValue   **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : c                                                   **
**                                                                            **
** InOut parameter      : Value                                               **
**                                                                            **
** Output Parameters    : ElapsedValue                                        **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetElapsedCounterValue(CounterType c,
                                    TickRefType Value, TickRefType ElapsedValue)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_GetElapsedCounterValue;
  msg.parameter[0] = (uint32)c;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[1] = (uint32)Value;
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> To contain variable generally, msg.parameter[] uses uint32 type */
  msg.parameter[2] = (uint32)ElapsedValue;
  /* polyspace:end<ISO-17961:intptrconv> */

  return Os_SendMessageWait(Os_GaaStaticCounter[c].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendStartScheduleTableRel                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a StartScheduleTable       **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s, Offset, rel                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableRel(ScheduleTableType s,
                                                   TickType Offset)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_StartScheduleTableRel;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)Offset;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendStartScheduleTableAbs                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a StartScheduleTable       **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s, start, rel                                      **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableAbs(ScheduleTableType s,
                                                   TickType Start)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_StartScheduleTableAbs;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)Start;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif


/*******************************************************************************
** Function Name        : Os_SendNextScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a NextScheduleTable        **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : sc, sn                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendNextScheduleTable
(
  ScheduleTableType sc,   /* Currently-running schedule table */
  ScheduleTableType sn    /* Schedule table to chain */
)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_ChainScheduleTable;
  msg.parameter[0] = (uint32)sc;
  msg.parameter[1] = (uint32)sn;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[sc].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendStopScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a StopScheduleTable        **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendStopScheduleTable(ScheduleTableType s)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_StopScheduleTable;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetScheduleTableStatus                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetScheduleTableStatus   **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_SendGetScheduleTableStatus(ScheduleTableType s,
                                                 ScheduleTableStatusRefType out)
{
  Os_MessageType msg;
  StatusType result;

  msg.opcode = OS_IC_GetScheduleTableStatus;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)out;
  msg.parameter[2] = (uint32)OS_ZERO;

  result = Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);

  return result;
}
#endif

/*******************************************************************************
** Function Name        : Os_SendStartScheduleTableSynchron                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending                            **
**                        a StartScheduleTableSynchron message and waits      **
**                        until message is returned.                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(StatusType, OS_CODE) Os_SendStartScheduleTableSynchron(ScheduleTableType s)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_StartScheduleTableSynchron;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendSetScheduleTableAsync                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a SetScheduleTableAsync    **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(StatusType, OS_CODE) Os_SendSetScheduleTableAsync(ScheduleTableType s)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_SetScheduleTableAsync;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendSyncScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a SyncScheduleTable        **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : s, globalTime                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(StatusType, OS_CODE) Os_SendSyncScheduleTable(ScheduleTableType s,
                                                            TickType globalTime)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_SyncScheduleTable;
  msg.parameter[0] = (uint32)s;
  msg.parameter[1] = (uint32)globalTime;
  msg.parameter[2] = (uint32)OS_ZERO;

  return Os_SendMessageWait(Os_GaaStaticSchedTable[s].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendTerminateApplication                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a TerminateApplication     **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a, restart                                          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticApplication                             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(StatusType, OS_CODE) Os_SendTerminateApplication(ApplicationType a,
                                                            RestartType restart)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_TerminateApplication;
  msg.parameter[0] = (uint32)a;
  msg.parameter[1] = (uint32)restart;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  return Os_SendMessageWait(Os_GaaStaticApplication[a].ddCoreID, &msg);
}
#endif

/*******************************************************************************
** Function Name        : Os_SendGetApplicationState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a GetApplicationState      **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : a                                                   **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : out                                                 **
**                                                                            **
** Return parameter     : none                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(void, OS_CODE) Os_SendGetApplicationState(ApplicationType Application,
                                                    ApplicationStateRefType out)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_GetApplicationState;
  msg.parameter[0] = (uint32)Application;
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> For implementation, conversion from function pointer to void pointer is needed to represent function address */
  msg.parameter[1] = (uint32)out;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE:NTC:Not a defect:No Action Planned> below function will be terminated by other core */
  (void)Os_SendMessageWait(Os_GaaStaticApplication[Application].ddCoreID, &msg);

}
#endif

/*******************************************************************************
** Function Name        : Os_SendShutdownAllCores                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function sends a shutdown message              **
**                        to other cores.                                     **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CoreID, Error                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessage()                                    **
*******************************************************************************/
FUNC(void, OS_CODE) Os_SendShutdownAllCores(uint16 CoreID, StatusType Error)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_ShutdownCore;
  msg.result = 0;
  msg.parameter[0] = Error;
  msg.parameter[1] = (uint32)OS_ZERO;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE: NTC : Not a defect:Justify with annotations> It waits other cores response. */
  (void)Os_SendMessage(CoreID, &msg);
}

/*******************************************************************************
** Function Name        : Os_SendIocPullCB                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a IocPullCB                **
**                        message and waits until message is returned.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : pIocPullCB, recvAppID                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessageWait()                                **
*******************************************************************************/
#if (OS_APPLICATION == STD_ON)
FUNC(void, OS_CODE) Os_SendIocPullCB(P2FUNC(void, OS_CONST, pIocPullCB) (void),
    ApplicationType recvAppID)
{
  Os_MessageType msg;

  msg.opcode = OS_IC_IocPullCB;
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> For implementation, conversion from function pointer to void pointer is needed to represent function address */
  msg.parameter[0] = (uint32)pIocPullCB;
  msg.parameter[1] = (uint32)recvAppID;
  msg.parameter[2] = (uint32)OS_ZERO;

  /* polyspace<RTE: NTC : Not a defect:Justify with annotations> It waits other cores response. */
  (void)Os_SendMessage(Os_GaaStaticApplication[recvAppID].ddCoreID, &msg);
}
#endif


#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of #if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
