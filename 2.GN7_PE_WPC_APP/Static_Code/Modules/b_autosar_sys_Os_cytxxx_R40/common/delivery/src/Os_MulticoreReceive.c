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
**  SRC-MODULE: Os_MulticoreReceive.c                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Inter-core Message receiving functionality.      **
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
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #10100                      **
** 2.0.13    03-Jun-2016    MJ.Woo        Redmine #4566, #5368                **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.6     08-Jan-2014    SH.Yoo        TASK: xar~810                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.1     13-Aug-2013    MJ.Woo        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    SH.Yoo        CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     15-Mar-2013    Son           Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<MISRA-C:11.3:Not a defect:Justify with annotations> This is to access registers which are assigned to absolute address  */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */


#if (OS_MULTICORE == STD_ON)

#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"
#include "Os_Shutdown.h"          /* Os Shutdown header file */

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
#include "Os_Ioc.h"               /* Os IOC Pull CB header file */
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
** Function Name        : Os_RecvUnknownCall                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is an UnknownCall message handler.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_RecvUnknownCall(Os_MessageType *msg)
{
  msg->result = E_OS_NOFUNC;
}

/*******************************************************************************
** Function Name        : Os_RecvActivateTask                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is an ActivateTask message handler.   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_DoActivateTask()                                 **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(void, OS_CODE) Os_RecvActivateTask(Os_MessageType *msg)
{
  /* Do the task activation and put the result code in the message
  */
  msg->result = Os_DoActivateTask((TaskType)msg->parameter[0], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetTaskState                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetTaskState message handler.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaTask                                          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_TASK == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetTaskState(Os_MessageType *msg)
{
  TaskType task;
  TaskStateType State;

  /* Get the task state */
  task = (TaskType)msg->parameter[0];
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index and message is checked by sender */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  State = ((Os_GaaTask[task].ddState) & OS_TASK_STATUS);
  if (State == OS_TASK_UNINITIALIZED)
  {
    State = SUSPENDED;
  }
  msg->parameter[0] = State;
  msg->result = E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvSetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a SetEvent message handler.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_DoSetEvent()                                     **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(void, OS_CODE) Os_RecvSetEvent(Os_MessageType *msg)
{
  /* Do the event-setting and put the result code in the message
  */
  msg->result = Os_DoSetEvent((TaskType)msg->parameter[0], \
                                     (EventMaskType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetEvent                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetEvent message handler.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticTask                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_DoGetEvent()                                     **
*******************************************************************************/
#if (OS_EVENT == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetEvent(Os_MessageType *msg)
{
  /* Get the event and get the result code
  */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  msg->result = Os_DoGetEvent((TaskType)msg->parameter[0], \
                                           (EventMaskRefType)msg->parameter[1]);
  /* polyspace:end<CERT-C:INT36-C> */
  /* polyspace:end<ISO-17961:intptrconv> */
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetAlarm                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetAlarm message handler.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoGetAlarm()                                     **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetAlarm(Os_MessageType *msg)
{
  /* Get the alarm delta and put the result code in the message
   */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  msg->result = Os_DoGetAlarm((AlarmType)msg->parameter[0], \
                                       (TickRefType)msg->parameter[1], OS_TRUE);
  /* polyspace:end<CERT-C:INT36-C> */
  /* polyspace:end<ISO-17961:intptrconv> */
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetAlarmBase                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetAlarmBase message handler.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoGetAlarmBase()                                 **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetAlarmBase(Os_MessageType *msg)
{
  /* Get the alarm delta and put the result code in the message
   */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  msg->result = Os_DoGetAlarmBase((AlarmType)msg->parameter[0], \
                                  (AlarmBaseRefType)msg->parameter[1], OS_TRUE);
  /* polyspace:end<ISO-17961:intptrconv> */
  /* polyspace:end<CERT-C:INT36-C> */
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvSetRelAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a SetRelAlarm message handler.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoSetRelAlarm()                                  **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(void, OS_CODE) Os_RecvSetRelAlarm(Os_MessageType *msg)
{
  /* Set an alarm at a relative time and put the result code in the message
   */
  msg->result = Os_DoSetRelAlarm((AlarmType)msg->parameter[0], \
             (TickType)msg->parameter[1], (TickType)msg->parameter[2], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvSetAbsAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a SetAbsAlarm message handler.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoSetAbsAlarm()                                  **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(void, OS_CODE) Os_RecvSetAbsAlarm(Os_MessageType *msg)
{
  /* Set an alarm at a absolute time and put the result code in the message
   */
  msg->result = Os_DoSetAbsAlarm((AlarmType)msg->parameter[0], \
             (TickType)msg->parameter[1], (TickType)msg->parameter[2], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvCancelAlarm                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a CancelAlarm message handler.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoCancelAlarm()                                  **
*******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(void, OS_CODE) Os_RecvCancelAlarm(Os_MessageType *msg)
{
  /* Cancel the alarm and put the result code in the message
   */
  msg->result = Os_DoCancelAlarm((AlarmType)msg->parameter[0], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetCounterValue                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetCounterValue message handler. **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoGetCounterValue()                              **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetCounterValue(Os_MessageType *msg)
{
  /* Get the counter value and put the result code in the message
  */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  msg->result = Os_DoGetCounterValue((CounterType)msg->parameter[0], \
                                       (TickRefType)msg->parameter[1], OS_TRUE);
  /* polyspace:end<CERT-C:INT36-C> */
  /* polyspace:end<ISO-17961:intptrconv> */
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetElapsedCounterValue                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetElapsedCounterValue message   **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoGetElapsedCounterValue()                       **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetElapsedCounterValue(Os_MessageType *msg)
{
  /* Get the counter value and put the result code in the message
  */
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  msg->result = Os_DoGetElapsedCounterValue((CounterType)msg->parameter[0], \
      (TickRefType)msg->parameter[1], (TickRefType)msg->parameter[2], OS_TRUE);
  /* polyspace:end<ISO-17961:intptrconv> */
  /* polyspace:end<CERT-C:INT36-C> */
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvStartScheduleTableAbs                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a StartScheduleTableAbs message    **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoStartScheduleTableAbs()                        **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(void, OS_CODE) Os_RecvStartScheduleTableAbs(Os_MessageType *msg)
{
  /* Start a schedule table at a relative or absolute time
   * and put the result code in the message
   */
  msg->result = Os_DoStartScheduleTableAbs((ScheduleTableType)msg->parameter[0],
                                          (TickType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvStartScheduleTableRel                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a StartScheduleTableRel message    **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoStartScheduleTableRel()                           **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(void, OS_CODE) Os_RecvStartScheduleTableRel(Os_MessageType *msg)
{
  /* Start a schedule table at a relative or absolute time
   * and put the result code in the message
   */
  msg->result = Os_DoStartScheduleTableRel((ScheduleTableType)msg->parameter[0],
                                          (TickType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvNextScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a NextScheduleTable message        **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoNextScheduleTable()                            **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(void, OS_CODE) Os_RecvNextScheduleTable(Os_MessageType *msg)
{
  /* Chain a schedule table to an already-active schedule table
   */
  msg->result = Os_DoNextScheduleTable((ScheduleTableType)msg->parameter[0],\
                (ScheduleTableType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvStopScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a StopScheduleTable message        **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoStopScheduleTable()                            **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(void, OS_CODE) Os_RecvStopScheduleTable(Os_MessageType *msg)
{
  /* Stop a schedule table immediately
   * and put the result code in in the message
   */
  msg->result = Os_DoStopScheduleTable((ScheduleTableType)msg->parameter[0],\
                OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetScheduleTableStatus                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetScheduleTableStatus message   **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        None                                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(void, OS_CODE) Os_RecvGetScheduleTableStatus(Os_MessageType *msg)
{
  /* Get the schedule table status */
  msg->result = Os_DoGetScheduleTableStatus(
                        (ScheduleTableType)msg->parameter[0],\
                        (ScheduleTableStatusRefType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvStartScheduleTableSynchron                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a StartScheduleTableSynchron       **
**                        message handler.                                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoStartScheduleTableSynchron()                   **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(void, OS_CODE) Os_RecvStartScheduleTableSynchron(Os_MessageType *msg)
{
  /* Start a schedule table at a relative or absolute time
   * and put the result code in the message
   */
  msg->result = Os_DoStartScheduleTableSynchron(
                                 (ScheduleTableType)msg->parameter[0], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvSetScheduleTableAsync                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a SetScheduleTableAsync message    **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoSetScheduleTableAsync()                        **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(void, OS_CODE) Os_RecvSetScheduleTableAsync(Os_MessageType *msg)
{
  /* Set a schedule table to the aysynchronous state
   * and put the result code in the message
   */
  msg->result = Os_DoSetScheduleTableAsync((ScheduleTableType)msg->parameter[0],
                                                                       OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvSyncScheduleTable                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a SyncScheduleTable message        **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoSyncScheduleTable()                            **
*******************************************************************************/
#if ((OS_SCHEDTABLE == STD_ON) && (OS_SCHED_EXPLICIT_SYNC == STD_ON))
FUNC(void, OS_CODE) Os_RecvSyncScheduleTable(Os_MessageType *msg)
{
  /* Synchronise a schedule table to the given global time
   * and put the result code in the message
   */
  msg->result = Os_DoSyncScheduleTable((ScheduleTableType)msg->parameter[0],\
                (TickType)msg->parameter[1], OS_TRUE);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvTerminateApplication                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a TerminateApplication message     **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoTerminateApplication()                         **
*******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(void, OS_CODE) Os_RecvTerminateApplication(Os_MessageType *msg)
{
  /* Do the task activation and put the result code in the message
   */
  msg->result = Os_DoTerminateApplication((ApplicationType)msg->parameter[0],\
                                                (RestartType)msg->parameter[1]);
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvGetApplicationState                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a GetApplicationState message      **
**                        handler.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        None                                                **
*******************************************************************************/
#if (OS_SCALABILITY_CLASS >= OS_SC3)
FUNC(void, OS_CODE) Os_RecvGetApplicationState(Os_MessageType *msg)
{
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  Os_DoGetApplicationState((ApplicationType)msg->parameter[0],
		  (ApplicationStateRefType)msg->parameter[1]);
  /* polyspace:end<CERT-C:INT36-C> */
  msg->result = E_OK;
}
#endif

/*******************************************************************************
** Function Name        : Os_RecvShutdownCore                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a ShutdownCore message handler.    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_ReleaseSpinlock(), Os_ShutdownCore()             **
*******************************************************************************/
/* polyspace +2 MISRA-C3:8.13 [Justified:Low] "Receive message handler format should be followed" */
FUNC(void, OS_CODE) Os_RecvShutdownCore(Os_MessageType *msg)
{
  /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
  /* Call Os_ShutdownCore */
  Os_ReleaseSpinlock(OS_MESSAGEQLOCKBASE+Os_MyCore());
  Os_ShutdownCore((StatusType)msg->parameter[0], OS_SHUTDOWN_SYNCHRONIZED);
  /* polyspace:end<MISRA-C3:2.2> */
}

/*******************************************************************************
** Function Name        : Os_RecvIocPullCB                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is a IocPullCB message handler        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : msg                                                 **
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
**                        Os_DoIocPullCB()                                    **
*******************************************************************************/
#if (OS_APPLICATION == STD_ON)
FUNC(void, OS_CODE) Os_RecvIocPullCB(Os_MessageType *msg)
{
  /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
  Os_DoIocPullCB((void (*)(void))msg->parameter[0],
                                            (ApplicationType)msg->parameter[1]);
  /* polyspace:end<CERT-C:INT36-C> */
}
#endif


#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of #if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<MISRA-C:11.3:Not a defect:Justify with annotations> This is to access registers which are assigned to absolute address  */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
