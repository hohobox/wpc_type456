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
**  SRC-MODULE: Os_MulticoreMessage.c                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Inter-core Message functionality.                **
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
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.8     25-Nov-2020    JH.Cho        Redmine #26808                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     08-Apr-2020    JH.Cho        Redmine #22760                      **
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #10100                      **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     28-Mar-2017    SH.Yoo,JH.Lee Redmine #5967, #7906                **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4686, #4566, #5368         **
** 2.0.10    09-Dec-2015    SH.Yoo        Redmine #2659                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.6     08-Jan-2014    SH.Yoo        TASK: xar~810                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     15-Mar-2013    Son           Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE: NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:begin<RTE: IDP :Not a defect : Justify with annotations > configured memory access index */
/* polyspace:begin<MISRA-C:19.4:Not a defect:Justify with annotations> Definition for function redirection does not use parenthesised expression */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */


#if (OS_MULTICORE == STD_ON)

#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"
#include "string.h"               /* for memcpy */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* Message handlers
*/
typedef void (*Os_MessageHandler_T)(Os_MessageType *msg);

#if (OS_TASK == STD_ON)
#define OS_XC_RECVACTIVATETASK                 Os_RecvActivateTask
#define OS_XC_RECVGETTASKSTATE                 Os_RecvGetTaskState
#endif
#if (OS_EVENT == STD_ON)
#define OS_XC_RECVSETEVENT                     Os_RecvSetEvent
#define OS_XC_RECVGETEVENT                     Os_RecvGetEvent
#endif
#if (OS_ALARM == STD_ON)
#define OS_XC_RECVGETALARM                     Os_RecvGetAlarm
#define OS_XC_RECVGETALARMBASE                 Os_RecvGetAlarmBase
#define OS_XC_RECVSETRELALARM                  Os_RecvSetRelAlarm
#define OS_XC_RECVSETABSALARM                  Os_RecvSetAbsAlarm
#define OS_XC_RECVCANCELALARM                  Os_RecvCancelAlarm
#endif
#if (OS_COUNTER == STD_ON)
#define OS_XC_RECVGETCOUNTERVALUE              Os_RecvGetCounterValue
#define OS_XC_RECVGETELAPSEDCOUNTERVALUE       Os_RecvGetElapsedCounterValue
#endif
#if (OS_SCHEDTABLE == STD_ON)
#define OS_XC_RECVSTARTSCHEDULETABLEREL        Os_RecvStartScheduleTableRel
#define OS_XC_RECVSTARTSCHEDULETABLEABS        Os_RecvStartScheduleTableAbs
#define OS_XC_RECVNEXTSCHEDULETABLE            Os_RecvNextScheduleTable
#define OS_XC_RECVSTOPSCHEDULETABLE            Os_RecvStopScheduleTable
#define OS_XC_RECVGETSCHEDULETABLESTATUS       Os_RecvGetScheduleTableStatus
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
#define OS_XC_RECVSTARTSCHEDULETABLESYNCHRON   Os_RecvStartScheduleTableSynchron
#define OS_XC_RECVSETSCHEDULETABLEASYNC        Os_RecvSetScheduleTableAsync
#define OS_XC_RECVSYNCSCHEDULETABLE            Os_RecvSyncScheduleTable
#endif
#endif
#if (OS_SCALABILITY_CLASS >= OS_SC3)
#define OS_XC_RECVTERMINATEAPPLICATION         Os_RecvTerminateApplication
#define OS_XC_RECVGETAPPLICATIONSTATE          Os_RecvGetApplicationState
#endif
#define OS_XC_RECVSHUTDOWNCORE                 Os_RecvShutdownCore

#if (OS_APPLICATION == STD_ON)
#define OS_XC_RECVIOCPULLCB                    Os_RecvIocPullCB
#else
#define OS_XC_RECVIOCPULLCB                    NULL_PTR
#endif

#ifndef OS_XC_RECVACTIVATETASK
#define OS_XC_RECVACTIVATETASK          NULL_PTR
#endif

#ifndef OS_XC_RECVGETTASKSTATE
#define OS_XC_RECVGETTASKSTATE          NULL_PTR
#endif

#ifndef OS_XC_RECVSETEVENT
#define OS_XC_RECVSETEVENT            NULL_PTR
#endif

#ifndef OS_XC_RECVGETEVENT
#define OS_XC_RECVGETEVENT            NULL_PTR
#endif

#ifndef OS_XC_RECVGETALARM
#define OS_XC_RECVGETALARM            NULL_PTR
#endif

#ifndef OS_XC_RECVSETRELALARM
#define OS_XC_RECVSETRELALARM         NULL_PTR
#endif

#ifndef OS_XC_RECVSETABSALARM
#define OS_XC_RECVSETABSALARM         NULL_PTR
#endif

#ifndef OS_XC_RECVCANCELALARM
#define OS_XC_RECVCANCELALARM         NULL_PTR
#endif

#ifndef OS_XC_RECVGETCOUNTERVALUE
#define OS_XC_RECVGETCOUNTERVALUE            NULL_PTR
#endif

#ifndef OS_XC_RECVGETELAPSEDCOUNTERVALUE
#define OS_XC_RECVGETELAPSEDCOUNTERVALUE            NULL_PTR
#endif

#ifndef OS_XC_RECVSTARTSCHEDULETABLEREL
#define OS_XC_RECVSTARTSCHEDULETABLEREL      NULL_PTR
#endif

#ifndef OS_XC_RECVSTARTSCHEDULETABLEABS
#define OS_XC_RECVSTARTSCHEDULETABLEABS      NULL_PTR
#endif

#ifndef OS_XC_RECVNEXTSCHEDULETABLE
#define OS_XC_RECVNEXTSCHEDULETABLE      NULL_PTR
#endif

#ifndef OS_XC_RECVSTOPSCHEDULETABLE
#define OS_XC_RECVSTOPSCHEDULETABLE       NULL_PTR
#endif

#ifndef OS_XC_RECVGETSCHEDULETABLESTATUS
#define OS_XC_RECVGETSCHEDULETABLESTATUS    NULL_PTR
#endif

#ifndef OS_XC_RECVSTARTSCHEDULETABLESYNCHRON
#define OS_XC_RECVSTARTSCHEDULETABLESYNCHRON  NULL_PTR
#endif

#ifndef OS_XC_RECVSETSCHEDULETABLEASYNC
#define OS_XC_RECVSETSCHEDULETABLEASYNC     NULL_PTR
#endif

#ifndef OS_XC_RECVSYNCSCHEDULETABLE
#define OS_XC_RECVSYNCSCHEDULETABLE       NULL_PTR
#endif

#ifndef OS_XC_RECVTERMINATEAPPLICATION
#define OS_XC_RECVTERMINATEAPPLICATION      NULL_PTR
#endif

#ifndef OS_XC_RECVGETAPPLICATIONSTATE
#define OS_XC_RECVGETAPPLICATIONSTATE     NULL_PTR
#endif

#ifndef OS_XC_RECVSHUTDOWNCORE
#define OS_XC_RECVSHUTDOWNCORE    NULL_PTR
#endif

#ifndef OS_XC_RECVGETALARMBASE
#define OS_XC_RECVGETALARMBASE NULL_PTR
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : Os_InitMessageQueue                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function initializes multicore message queue.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaInterCoreMsgQ                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void, OS_CODE) Os_InitMessageQueue(void)
{
  Os_MessageQueueType *mq;
  Os_Int_T i;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  mq = (Os_MessageQueueType*)&Os_GaaInterCoreMsgQ[Os_MyCore()];
  mq->fill = 0;
  mq->empty = 0;
  mq->msgCnt = 0;
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace:end<MISRA-C3:18.1> */

  for (i = 0; i < OS_N_MESSAGES; i++)
  {
    mq->buffer[i] = 0;
  }
}

/*******************************************************************************
** Function Name        : Os_SendMessageWait                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a message to other core    **
**                        and wait until message is returned.                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CoreID                                              **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaInterCoreMsgQ, Os_GblCoreShutdown             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendMessage(), Os_ReceiveMessage(),              **
**                        memcpy()                                            **
*******************************************************************************/
FUNC(StatusType, OS_CODE) Os_SendMessageWait(uint16 CoreID, Os_MessageType *msg)
{
  volatile uint32 *vMsgResultReady;
  Os_MessageQueueType *mq;
  Os_MessageType *mqmsg;
  uint16 MqFillReturn;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  mq = (Os_MessageQueueType*)&Os_GaaInterCoreMsgQ[CoreID];
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */

  /* Send the request to the other core.
   */
  MqFillReturn = Os_SendMessage(CoreID, msg);

  mqmsg = &mq->msg[MqFillReturn];
  vMsgResultReady = &mqmsg->resultReady;

  do
  {
    Os_ReceiveMessage((uint16)Os_MyCore());

    /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> variable is verified manually */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  	if(Os_GblCoreShutdown[CoreID] == OS_TRUE)
    {
      mqmsg->result = E_OS_SYS_CORE_IS_DOWN;
      *vMsgResultReady = OS_TRUE;
    }
  } while ( *vMsgResultReady == OS_FALSE );

  /* Update message parameter */
  /* polyspace:begin<RTE:STD_LIB:Not a defect:No Action Planned > function is called with a valid arguments that are confirmed by testing */
  /* polyspace<MISRA-C3:D4.11:Not a defect:Justify with annotations> parameter is valid and verified manually */
  memcpy(msg, mqmsg, sizeof(Os_MessageType));
  /* polyspace:end<RTE:STD_LIB:Not a defect:No Action Planned > function is called with a valid arguments that are confirmed by testing */

  return (StatusType)mqmsg->result;
}

/*******************************************************************************
** Function Name        : Os_SendMessage                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is sending a message and notifes      **
**                        to other core.                                      **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CoreID                                              **
**                                                                            **
** InOut parameter      : msg                                                 **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint16                                              **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaInterCoreMsgQ                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(),                                   **
**                        Os_NotifyCore(),                                    **
**                        Os_ReleaseSpinlock()                                **
*******************************************************************************/
FUNC(uint16, OS_CODE) Os_SendMessage(uint16 CoreID, const Os_MessageType *msg)
{
  Os_MessageQueueType *mq;
  boolean issend = OS_FALSE;
  uint16 MqFillReturn;

  MqFillReturn = OS_ZERO;
  /* Get the message queue descriptor for the target core  */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  mq = (Os_MessageQueueType*)&Os_GaaInterCoreMsgQ[CoreID];
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */

  do
  {
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* Lock message queue */
    Os_GetSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
    /* polyspace:end<MISRA-C3:2.2> */

    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if(mq->msgCnt < OS_N_MESSAGES)
    {
      /* Update the fill pointer to the next slot and force the write */
      /* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
      /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* polyspace-begin MISRA-C3:9.1 [Not a defect:High] "If param 1,2 is not initialized, it is not used." */
      /* polyspace:begin<DEFECT:NON_INIT_VAR:Not a defect:Justify with annotations> If param 1,2 is not initialized, it is not used */
      mq->msg[mq->fill].opcode = msg->opcode;
      mq->msg[mq->fill].parameter[0] = msg->parameter[0];
      mq->msg[mq->fill].parameter[1] = msg->parameter[1];
      mq->msg[mq->fill].parameter[2] = msg->parameter[2];
      /* polyspace:end<MISRA-C3:D4.1> */
      /* polyspace:end<MISRA-C3:18.1> */
      /* polyspace-end MISRA-C3:9.1 */
      /* polyspace:end<DEFECT:NON_INIT_VAR> */

      /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> boundary is limited to pre-defined range */
      mq->buffer[mq->fill] = (CoreIDType)Os_MyCore();
	  /* polyspace:end<MISRA-C3:18.1:Not a defect:Justify with annotations> boundary is limited to pre-defined range */
	  /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Defensive programming */
      if((msg->opcode != OS_IC_ShutdownCore) && (msg->opcode != OS_IC_IocPullCB))
      {
        mq->msg[mq->fill].result = E_OS_SYS_INTERCOREMSG;
        mq->msg[mq->fill].resultReady = OS_FALSE;
      }

      /* Return the fill value of the message queue currently being processed */
      MqFillReturn = mq->fill;

      /* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
      #if (OS_CORE_COUNT >= OS_THREE)
      mq->fill = ((mq->fill+OS_ONE) >= OS_N_MESSAGES) ?
                                                  OS_ZERO : (mq->fill+OS_ONE);
      #else
      mq->fill = OS_ZERO;
      #endif

      mq->msgCnt++;

      /* Inform the recipient that it has a message
       */
      Os_NotifyCore(CoreID);
      issend = OS_TRUE;
    }
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* Unlock message queue */
    Os_ReleaseSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
    /* polyspace:end<MISRA-C3:2.2> */
  } while (issend == OS_FALSE);
  return MqFillReturn;
}

/*******************************************************************************
** Function Name        : Os_ReceiveMessage                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Receives a message from other core.                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CoreID                                              **
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
**                        Os_GaaInterCoreMsgQ, Os_GaaMessageHandler           **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(),                                   **
**                        Os_AckNotifyCore(),                                 **
**                        Os_ReleaseSpinlock()                                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_ReceiveMessage(uint16 CoreID)
{
  Os_MessageQueueType *mq;
  Os_MessageType *msg;
  static CONST(Os_MessageHandler_T, OS_CONST) Os_GaaMessageHandler[OS_N_INTERCORE] =
  {
    Os_RecvUnknownCall,                     /*  0 */
    OS_XC_RECVACTIVATETASK,                 /*  1 */
    OS_XC_RECVGETTASKSTATE,                 /*  2 */
    OS_XC_RECVSETEVENT,                     /*  3 */
    OS_XC_RECVGETEVENT,                     /*  4 */
    OS_XC_RECVGETALARM,                     /*  5 */
    OS_XC_RECVGETALARMBASE,                 /*  6 */
    OS_XC_RECVSETRELALARM,                  /*  7 */
    OS_XC_RECVSETABSALARM,                  /*  8 */
    OS_XC_RECVCANCELALARM,                  /*  9 */
    OS_XC_RECVGETCOUNTERVALUE,              /* 10 */
    OS_XC_RECVGETELAPSEDCOUNTERVALUE,       /* 11 */
    OS_XC_RECVSTARTSCHEDULETABLEREL,        /* 12 */
    OS_XC_RECVSTARTSCHEDULETABLEABS,        /* 13 */
    OS_XC_RECVNEXTSCHEDULETABLE,            /* 14 */
    OS_XC_RECVSTOPSCHEDULETABLE,            /* 15 */
    OS_XC_RECVGETSCHEDULETABLESTATUS,       /* 16 */
    OS_XC_RECVSTARTSCHEDULETABLESYNCHRON,   /* 17 */
    OS_XC_RECVSETSCHEDULETABLEASYNC,        /* 18 */
    OS_XC_RECVSYNCSCHEDULETABLE,            /* 19 */
    OS_XC_RECVTERMINATEAPPLICATION,         /* 20 */
    OS_XC_RECVGETAPPLICATIONSTATE,          /* 21 */
    OS_XC_RECVSHUTDOWNCORE,                 /* 22 */
    OS_XC_RECVIOCPULLCB,                    /* 23 */
  };

  /* Get the message queue descriptor for the target core*/
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  mq = (Os_MessageQueueType*)&Os_GaaInterCoreMsgQ[CoreID];
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */

  /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
  /* Lock message queue */
  Os_GetSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
  /* polyspace:end<MISRA-C3:2.2> */

  /* Acknowledge the interrupt */
  Os_AckNotifyCore(CoreID);

  /* Process all messages in the queue.
  */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  while ( mq->msgCnt != 0 )
  {
    /* Process one message
    */
    msg = (Os_MessageType*)&(mq->msg[mq->empty]);
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (Os_GaaMessageHandler[msg->opcode] != NULL_PTR)
    {
      /* polyspace<RTE: COR : Not a defect : No Action Planned > function ptr points to a valid function and code is manually checked*/
      (*Os_GaaMessageHandler[msg->opcode])(msg);
    }
    else
    {
      msg->result = E_OS_CORE;
    }
    if((msg->opcode != OS_IC_ShutdownCore) && (msg->opcode != OS_IC_IocPullCB))
    {
      msg->resultReady = OS_TRUE;
    }

    /* Move to next message and force pointer write.
    */
    #if (OS_CORE_COUNT >= OS_THREE)
    mq->empty = ((mq->empty+OS_ONE) >= OS_N_MESSAGES) ?
                                                  OS_ZERO : (mq->empty+OS_ONE);
    #else
    mq->empty = OS_ZERO;
    #endif
    mq->msgCnt--;
  }

  /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
  /* Unlock message queue */
  Os_ReleaseSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
  /* polyspace:end<MISRA-C3:2.2> */
}

/*******************************************************************************
** Function Name        : Os_RecvDuringShutdown                               **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is used to handling received message  **
**                        while shutdown core.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CoreID                                              **
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
**                        Os_GaaInterCoreMsgQ                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(),                                   **
**                        Os_AckNotifyCore(),                                 **
**                        Os_ReleaseSpinlock()                                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_RecvDuringShutdown(uint16 CoreID)
{
  Os_MessageQueueType *mq;
  Os_MessageType *msg;
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */
  mq = (Os_MessageQueueType*)&Os_GaaInterCoreMsgQ[CoreID];
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> This typecast is needed in order to implement a common interface for multicore message */

  /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
  Os_GetSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
  Os_AckNotifyCore(CoreID);
  /* polyspace:end<MISRA-C3:2.2> */

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  while ( mq->msgCnt != 0 )
  {
    msg = (Os_MessageType*)&(mq->msg[mq->empty]);

    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (msg->opcode != OS_IC_ShutdownCore)
    {
      msg->result = E_OS_SYS_CORE_IS_DOWN;
      msg->resultReady = OS_TRUE;
    }

    /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because condition check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
    mq->empty = ((mq->empty+1) == OS_N_MESSAGES) ? 0 : (mq->empty+1);
    mq->msgCnt--;
  }

  /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
  Os_ReleaseSpinlock(OS_MESSAGEQLOCKBASE+CoreID);
  /* polyspace:end<MISRA-C3:2.2> */
}
#define OS_STOP_SEC_CODE
#include "MemMap.h"
#endif /* End of #if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP : Not a defect : Justify with annotations > configured memory access index */
/* polyspace:end<MISRA-C:19.4:Not a defect:Justify with annotations> Definition for function redirection does not use parenthesised expression */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
