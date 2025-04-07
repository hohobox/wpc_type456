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
**  SRC-MODULE: Os_SchedTable.c                                               **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Schedule Table functionality.                    **
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
** 2.6.10    21-Dec-2021    JH.Cho        Redmine #33481                      **
**                          MJ.Woo                                            **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     13-Apr-2020    MJ.Woo        Redmine #22921                      **
** 2.5.0     25-Jun-2018    SH.Yoo        Redmine #13150                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025, #12103              **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    18-Feb-2016    MJ.Woo        Redmine #3992                       **
** 2.0.9     13-Jul-2015    SH.Yoo        Redmine #2849                       **
**           10-Dec-2014    MJ.Woo        Redmine #494, #1189                 **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Alarm.h"             /* Os Alarm header file */
#include "Os_SchedTable.h"        /* Os ScheduleTable header file */
#include "Os_Error.h"             /* Os Error header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
#endif
#include "Os_Counter.h"
#if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
#include "Os_Arch_Timer.h"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableRel(ScheduleTableType
                                              ScheduleTableID, TickType Offset);
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableAbs(ScheduleTableType
                                               ScheduleTableID, TickType Start);
FUNC(StatusType, OS_CODE)
                    Os_KernStopScheduleTable(ScheduleTableType ScheduleTableID);
FUNC(StatusType, OS_CODE) Os_KernNextScheduleTable(
  ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To);
FUNC(StatusType, OS_CODE) Os_KernGetScheduleTableStatus(
  ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus);
static FUNC(StatusType, OS_CODE) Os_StopSchedTabService(ScheduleTableType
                                                               ScheduleTableID);
static FUNC(StatusType, OS_CODE) Os_ProcessSchedTableEnd
                                            (ScheduleTableType ScheduleTableID);
#endif
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableSynchron(
                                             ScheduleTableType ScheduleTableID);
FUNC(StatusType, OS_CODE) Os_KernSyncScheduleTable
                            (ScheduleTableType ScheduleTableID, TickType Value);
FUNC(StatusType, OS_CODE) Os_KernSetScheduleTableAsync(
                                             ScheduleTableType ScheduleTableID);
static FUNC(TickType, OS_CODE) Os_GetMinValue(TickType LddMaxPeriod,
                                                        TickType LddDeviation);
#endif

/*******************************************************************************
** Function Name        : Os_KernStartScheduleTableRel                        **
**                                                                            **
** Service ID           : OSServiceId_StartScheduleTableRel                   **
**                                                                            **
** Description          : This service does the processing of the schedule    **
**                        table at "Offset" relative to the "Now" value on the**
**                        underlying counter.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Offset                             **
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
**                        Os_SendStartScheduleTableRel(),                     **
**                        Os_DoStartScheduleTableRel()                        **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableRel(ScheduleTableType
                                               ScheduleTableID, TickType Offset)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(STARTSCHEDULETABLEREL, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether the Offset is zero or greater than OsCounterMaxAllowedValue
   * of the underlying counter minus Initial Offset */
  OS_CHECK_SCHEDTABLE_OFFSET_VALUE_ERROR(ScheduleTableID, Offset,
                                                               LenStatusReturn);
  /* Check whether the Schedule table is implicitly synchronised */
  OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID, LenStatusReturn);
  /* Check whether Application can access the Scheduletable */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendStartScheduleTableRel and get the return value */
      LenStatusReturn = Os_SendStartScheduleTableRel(ScheduleTableID, Offset);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoStartScheduleTableRel and get the return value */
      LenStatusReturn = Os_DoStartScheduleTableRel(ScheduleTableID,
                                                              Offset, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_StartScheduleTableRel);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Store the parameter 2 - Offset */
    OS_STORE_PARAM2_OFFSET(Offset);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of StartScheduleTableRel(ScheduleTableType */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoStartScheduleTableRel                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service does the processing of the schedule    **
**                        table at "Offset" relative to the "Now" value on the**
**                        underlying counter.                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Offset, LblRemoteCall              **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertAlarm(), Os_GetNextTick(),                 **
**                        Os_AdjustTimerInterrupt()                           **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableRel(ScheduleTableType
                        ScheduleTableID, TickType Offset, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2CONST(Tdd_Os_ExpiryPoint, AUTOMATIC, OS_CONST) LpExpPoint;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  TickType LddDate;
  StatusType LenStatusReturn;

  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;

  /* Check whether a related alarm is in use already */
  OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, &LenStatusReturn);

  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  if(LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Get the pointer to the corresponding alarm associated with the
     * schedule table */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

    /* Check whether schedule table is already started */
    if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED)
    {
      /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
      LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];

      /* Get the pointer to the initial expiry point */
      LpExpPoint = LpStaticSchedTable->pExpiryPoint;
      /* Get the pointer to corresponding static counter associated with the
       *   schedule table */
      LpStaticCounter = LpStaticSchedTable->pStaticCounter;
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* If Counter is a HW Counter, update counter tick from HW timer */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
      }
      #endif
      /* Get the "offset" relative to the "now" value on the underlying
       *   counter into local variable */
      LddDate = Os_GetNextTick(LpStaticCounter->pCounter->ddCurrentCount,
             Offset + LpExpPoint->ddOffset, LpStaticCounter->ddMaxAllowedValue);
      /* Load the Offset at which the initial expiry point shall be processed */
      LpAlarm->ddAbsCount = LddDate;
      /* Update ddExpiryOffset for the ScheduleTable with First expiry offset */
      LpSchedTable->ddExpiryOffset = LpExpPoint->ddOffset;
      /* Start scheduleTable from 1st Index */
      LpSchedTable->ulIndex = OS_ZERO;
      /* Set the Schedule table state to running */
      LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
      /* Insert the alarm object */
      Os_InsertAlarm(LpAlarm);
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* Adjust timer interrupt to counter tick of first alarm */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_AdjustTimerInterrupt(
                              LpStaticCounter->pCounter->pHeadAlarm->ddAbsCount,
                                                   LpStaticCounter->pHwCounter);
      }
      #endif
    } /* End of if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED) */
    else
    {
      /* Set the value E_OS_STATE in the variable LenstatusReturn */
      LenStatusReturn = E_OS_STATE;
    }
  } /* End of if(LenStatusReturn == E_OK) */

  /* Return The value */
  return (LenStatusReturn);
}
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernStartScheduleTableAbs                        **
**                                                                            **
** Service ID           : OSServiceId_StartScheduleTableAbs                   **
**                                                                            **
** Description          : This service does the processing of the schedule    **
**                        table at absolute value "Start" of the underlying   **
**                        counter.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Start                              **
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
**                        Os_SendStartScheduleTableAbs(),                     **
**                        Os_DoStartScheduleTableAbs()                        **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableAbs(ScheduleTableType
                                                ScheduleTableID, TickType Start)
{
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(STARTSCHEDULETABLEABS, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether the Start is greater than OsCounterMaxAllowedValue of the
   *   underlying counter */
  OS_CHECK_SCHEDTABLE_TICK_VALUE(ScheduleTableID, Start, LenStatusReturn);
  /* Check whether Scheduletable can access the Application */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendStartScheduleTableAbs and get the return value */
      LenStatusReturn = Os_SendStartScheduleTableAbs(ScheduleTableID, Start);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoStartScheduleTableAbs and get the return value */
      LenStatusReturn = Os_DoStartScheduleTableAbs(ScheduleTableID,
                                                               Start, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_StartScheduleTableAbs);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Store the parameter 2 - Start */
    OS_STORE_PARAM2_START(Start);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of StartScheduleTableAbs(ScheduleTableType */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoStartScheduleTableAbs                          **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service does the processing of the schedule    **
**                        table at absolute value "Start" of the underlying   **
**                        counter.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Start, LblRemoteCall               **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertAlarm(), Os_GetNextTick(),                 **
**                        Os_AdjustTimerInterrupt()                           **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableAbs(ScheduleTableType
                         ScheduleTableID, TickType Start, boolean LblRemoteCall)
{
  StatusType LenStatusReturn;
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2CONST(Tdd_Os_ExpiryPoint, AUTOMATIC, OS_CONST) LpExpPoint;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  TickType LddDate;

  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;

  /* Check whether a related alarm is in use already */
  OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, &LenStatusReturn);

  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  if(LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
    /* Get the pointer to the corresponding alarm associated with the
     * schedule table */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

    /* Check whether schedule table is already started */
    if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED)
    {
      /* Get the pointer to corresponding static counter associated with the
       *    schedule table */
      LpStaticCounter = LpStaticSchedTable->pStaticCounter;
      /* Get the pointer to the initial expiry point */
      LpExpPoint = LpStaticSchedTable->pExpiryPoint;
      /* Get the "offset" relative to the absolute "Start" value on the
       * underlying counter into local variable */
      LddDate = Os_GetNextTick(Start, LpExpPoint->ddOffset,
                                            LpStaticCounter->ddMaxAllowedValue);
      /* Load the Offset at which the initial expiry point shall be
       *   processed */
      LpAlarm->ddAbsCount = LddDate;
      /* Update ddExpiryOffset for the ScheduleTable with First expiry
       * offset */
      LpSchedTable->ddExpiryOffset = LpExpPoint->ddOffset;
      /* Start scheduleTable from first Index */
      LpSchedTable->ulIndex = OS_ZERO;

      #if (OS_SCHED_IMPLICIT_SYNC == STD_ON)
      /* Check weather ScheduleTable is implicitly syncronised */
      if (LpStaticSchedTable->ucSynchStrategy == OS_SCHEDTABLE_IMPLICIT_SYNC)
      {
        /* Set the Schedule table state to running & Synchronous */
        LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
      }
      else
      #endif /* End of if (OS_SCHED_IMPLICIT_SYNC == STD_ON) */
      {
        /* Set the Schedule table state to running */
        LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
      }
      /* Insert the alarm object */
      Os_InsertAlarm(LpAlarm);
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
        /* Adjust timer interrupt to counter tick of first alarm */
        Os_AdjustTimerInterrupt(
                              LpStaticCounter->pCounter->pHeadAlarm->ddAbsCount,
                                                   LpStaticCounter->pHwCounter);
      }
      #endif
    } /* End of if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED) */
    else
    {
      /* Set the value E_OS_STATE in the variable LenStatusReturn  */
      LenStatusReturn = E_OS_STATE;
    }
  } /* End of if(LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of StartScheduleTableAbs(ScheduleTableType */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernStopScheduleTable                            **
**                                                                            **
** Service ID           : OSServiceId_StopScheduleTable                       **
**                                                                            **
** Description          : This service changes the state of the schedule      **
**                        table to "Stopped" state.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID                                     **
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
**                        Os_SendStopScheduleTable(),                         **
**                        Os_DoStopScheduleTable()                            **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE)
                     Os_KernStopScheduleTable(ScheduleTableType ScheduleTableID)
{
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(STOPSCHEDULETABLE, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether Application can access the Scheduletable */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /*Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendStopScheduleTable and get the return value */
      LenStatusReturn = Os_SendStopScheduleTable(ScheduleTableID);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoStopScheduleTable and get the return value */
      LenStatusReturn = Os_DoStopScheduleTable(ScheduleTableID, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_StopScheduleTable);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif
  /* Return the value */
  return (LenStatusReturn);
} /* End of StopScheduleTable(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoStopScheduleTable                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service changes the state of the schedule      **
**                        table to "Stopped" state.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, LblRemoteCall                      **
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
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_StopSchedTabService()                            **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE)
Os_DoStopScheduleTable(ScheduleTableType ScheduleTableID, boolean LblRemoteCall)
{
  StatusType LenStatusReturn;

  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;

  /* Check whether a related alarm is in use already */
  OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, &LenStatusReturn);

  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  if(LenStatusReturn == E_OK)
  {
    LenStatusReturn = Os_StopSchedTabService(ScheduleTableID);
  }

  return (LenStatusReturn);
} /* End of Os_StopSchedTabService(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_StopSchedTabService                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service changes the state of the schedule      **
**                        table to "Stopped" state.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID                                     **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetTaskLock(), Os_ReleaseTaskLock()              **
**                        Os_RemoveAlarm()                                    **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
static FUNC(StatusType, OS_CODE) Os_StopSchedTabService(ScheduleTableType
                                                                ScheduleTableID)
{
  StatusType LenStatusReturn;
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTableNext;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;

  /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
  LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
  /* Get the pointer to corresponding schedule table */
  LpStaticSchedTable = &Os_GaaStaticSchedTable[LpSchedTable->ddSchedTableId];
  /* Get the pointer to the corresponding alarm associated with the
   *   schedule table */
  LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

  /* Check whether schedule table is already stopped or not */
  if (LpAlarm->ucAlarmState != SCHEDULETABLE_STOPPED)
  {
    LenStatusReturn = E_OK;
    /* Set cycle of alarm to zero */
    LpAlarm->ddCycle = OS_ZERO;
    /* Remove the alam object from the queue from further processing of the
     *   expiry points associated to schedule table */
    Os_RemoveAlarm(LpAlarm);
    /* Set the Schedule table state to stopped */
    LpAlarm->ucAlarmState = SCHEDULETABLE_STOPPED;

    /* Check whether next schedule table exists or not */
    if ((LpSchedTable->ddNextSchedTable) != OS_INVALID_VALUE)
    {
      /* Get the pointer to next schedule table */
      LpStaticSchedTableNext =
                      &Os_GaaStaticSchedTable[(LpSchedTable->ddNextSchedTable)];
      /* If the schedule table has already set to next schedule table, set
       *   next schedule table to stopped */
      Os_GaaAlarm[LpStaticSchedTableNext->ddAlarmIndex].ucAlarmState =
                                                          SCHEDULETABLE_STOPPED;
      /* Update NextScheduleTable with invalid value */
      (LpSchedTable->ddNextSchedTable) = OS_INVALID_VALUE;
    } /* End of if ((LpSchedTable->ddNextSchedTable) != OS_INVALID_VALUE) */
  } /* End of if (LpAlarm->ucAlarmState != SCHEDULETABLE_STOPPED) */
  else
  {
    /* Set the value E_OS_NOFUNC in the variable LenStatusReturn */
    LenStatusReturn = E_OS_NOFUNC;
  }
  return (LenStatusReturn);
} /* End of Os_StopSchedTabService(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */


/*******************************************************************************
** Function Name        : Os_KernNextScheduleTable                            **
**                                                                            **
** Service ID           : OSServiceId_NextScheduleTable                       **
**                                                                            **
** Description          : This service does the processing of schedule table  **
**                        <ScheduleTableID_To> <ScheduleTableID_From>.Final   **
**                        Delay ticks after the Final Expiry Point on         **
**                        <ScheduleTableID_From> is processed.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID_From, ScheduleTableID_To            **
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
**                        Os_SendNextScheduleTable(),                         **
**                        Os_DoNextScheduleTable()                            **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernNextScheduleTable(
   ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(NEXTSCHEDULETABLE, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_NEXT_SCHEDTABLE_ID_ERROR(ScheduleTableID_From,ScheduleTableID_To,
                                                               LenStatusReturn);
  /* Check whether it is driven by the same counter */
  OS_CHECK_SCHEDTABLE_COUNTERS(ScheduleTableID_From, ScheduleTableID_To,
                                                               LenStatusReturn);
  /* Check whether both the sched are having same strategy */
  OS_CHECK_NEXT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID_From,
                                           ScheduleTableID_To, LenStatusReturn);
  /* Check whether Application can access the Scheduletable */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                          ScheduleTableID_From);
  /* Check whether Application can access the Scheduletable */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                            ScheduleTableID_To);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID_To];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendNextScheduleTable and get the return value */
      LenStatusReturn = Os_SendNextScheduleTable(ScheduleTableID_From,
                                                            ScheduleTableID_To);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoNextScheduleTable and get the return value */
      LenStatusReturn = Os_DoNextScheduleTable(ScheduleTableID_From,
                                                  ScheduleTableID_To, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_NextScheduleTable);
    /* Store the parameter 1 -ScheduleTableID_From */
    OS_STORE_PARAM1_SCHEDTABLEID_FROM(ScheduleTableID_From);
    /* Store the parameter 2 -ScheduleTableID_To */
    OS_STORE_PARAM2_SCHEDTABLEID_TO(ScheduleTableID_To);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of NextScheduleTable(ScheduleTableType ScheduleTableID_From,
   *ScheduleTableType ScheduleTableID_To) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoNextScheduleTable                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service does the processing of schedule table  **
**                        <ScheduleTableID_To> <ScheduleTableID_From>.Final   **
**                        Delay ticks after the Final Expiry Point on         **
**                        <ScheduleTableID_From> is processed.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID_From, ScheduleTableID_To,           **
**                        LblRemoteCall                                       **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoNextScheduleTable(
   ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To,
                                                          boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTableFrom;
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTableNext;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTableFrom;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTableNext;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarmFrom;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarmTo;
  StatusType LenStatusReturn;

  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;

  /* Check whether a related alarm is in use already */
  OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID_From, &LenStatusReturn);

  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                           ScheduleTableID_From, LblRemoteCall);
  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                             ScheduleTableID_To, LblRemoteCall);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table with
     *   ScheduleTableID_From */
    LpStaticSchedTableFrom = &Os_GaaStaticSchedTable[ScheduleTableID_From];
    /* Get the pointer to the coresponding alarm */
    LpAlarmFrom = &Os_GaaAlarm[LpStaticSchedTableFrom->ddAlarmIndex];

    /* Check the current schedule table is stopped or already in the next
     *   state */
    if (LpAlarmFrom->ucAlarmState > SCHEDULETABLE_NEXT)
    {
      /* Get the pointer to corresponding Schedule Table with
       *   ScheduleTableID_To */
      LpStaticSchedTableNext = &Os_GaaStaticSchedTable[ScheduleTableID_To];
      /* Get the pointer to the coresponding alarm */
      LpAlarmTo = &Os_GaaAlarm[LpStaticSchedTableNext->ddAlarmIndex];

      /* Check the state of NextScheduletAble is Stopped or not */
      if (LpAlarmTo->ucAlarmState == SCHEDULETABLE_STOPPED)
      {
        /* Take ScheduleTable into Local variable */
        LpSchedTableFrom = &Os_GaaSchedTable[ScheduleTableID_From];
        /* Take ScheduleTable into Local variable */
        LpSchedTableNext = &Os_GaaSchedTable[ScheduleTableID_To];
        /* Get the pointer to corresponding Schedule Table with
         *   ScheduleTableID_To */
        LpStaticSchedTableNext = &Os_GaaStaticSchedTable[ScheduleTableID_To];

        /* Check whether requested schedule table has already next schedule
         *   table in place */
        if ((LpSchedTableFrom->ddNextSchedTable) != OS_INVALID_VALUE)
        {
          /* Get the pointer to next schedule table */
          LpStaticSchedTableNext =
                  &Os_GaaStaticSchedTable[(LpSchedTableFrom->ddNextSchedTable)];
          /* If the schedule table has already set to next schedule table, set
           *   next schedule table to stopped */
          Os_GaaAlarm[LpStaticSchedTableNext->ddAlarmIndex].ucAlarmState =
                                                          SCHEDULETABLE_STOPPED;
        } /* End of if ((LpSchedTableFrom->ddNextSchedTable) !=
           *OS_INVALID_VALUE) */
        /* Set the state of the next schedule table with SCHEDULETABLE_NEXT */
        LpAlarmTo->ucAlarmState = SCHEDULETABLE_NEXT;
        /* Store the next schedule table */
        LpSchedTableFrom->ddNextSchedTable = ScheduleTableID_To;
        /* Update ddExpiryOffset for ScheduleTable with first expiry offset */
        LpSchedTableNext->ddExpiryOffset =
                                 LpStaticSchedTableNext->pExpiryPoint->ddOffset;
        /* Update Alarm Expiry action for the ScheduleTable with
         *   Os_ProcessSchedTable */
        /* Start scheduleTable from first Index */
        LpSchedTableNext->ulIndex = OS_ZERO;
      } /* End of if (LpAlarmTo->ucAlarmState == SCHEDULETABLE_STOPPED) */
      else
      {
        /* If NextScheduleTable is having state other than stopped then return
         *   E_OS_STATE */
        LenStatusReturn = E_OS_STATE;
      }
    } /* End of if (LpAlarmFrom->ucAlarmState > SCHEDULETABLE_NEXT) */
    else
    {
      /* The schedule table is already stopped or in next state, Set the value
       *   E_OS_NOFUNC in the variable LenstatusReturn */
      LenStatusReturn = E_OS_NOFUNC;
    }
  } /* End of if (LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of NextScheduleTable(ScheduleTableType ScheduleTableID_From,
   *ScheduleTableType ScheduleTableID_To) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : StartScheduleTableSynchron                          **
**                                                                            **
** Service ID           : OSServiceId_StartScheduleTableSynchron              **
**                                                                            **
** Description          : This service shall set the state of                 **
**                        <ScheduleTableID> to SCHEDULETABLE_WAITING and start**
**                        the processing of schedule table <ScheduleTableID>  **
**                        after the synchronization count of the schedule     **
**                        table is set via SyncScheduleTable().               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID                                     **
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
**                        Os_SendStartScheduleTableSynchron(),                **
**                        Os_DoStartScheduleTableSynchron()                   **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernStartScheduleTableSynchron(
                                              ScheduleTableType ScheduleTableID)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(STARTSCHEDULETABLESYNCHRON, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether the Schedule table is implicitly synchronized */
  OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID, LenStatusReturn);
  /* Check whether Scheduletable can access the Application */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendStartScheduleTableSynchron and get the return value */
      LenStatusReturn = Os_SendStartScheduleTableSynchron(ScheduleTableID);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoStartScheduleTableSynchron and get the return value */
      LenStatusReturn = Os_DoStartScheduleTableSynchron(ScheduleTableID,
                                                                      OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_StartScheduleTableSynchron);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of StartScheduleTableSynchron(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoStartScheduleTableSynchron                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service shall set the state of                 **
**                        <ScheduleTableID> to SCHEDULETABLE_WAITING and start**
**                        the processing of schedule table <ScheduleTableID>  **
**                        after the synchronization count of the schedule     **
**                        table is set via SyncScheduleTable().               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, LblRemoteCall                      **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm,                **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoStartScheduleTableSynchron(
                                              ScheduleTableType ScheduleTableID,
                                              boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Get the pointer to the corresponding alarm associated with the
     *   schedule table */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

    /* Check whether schedule table is already stopped or not */
    if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED)
    {
      /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
      LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
      /* Update ddExpiryOffset for the ScheduleTable with First expiry offset */
      LpSchedTable->ddExpiryOffset = LpStaticSchedTable->pExpiryPoint->ddOffset;
      /* Update Alarm Expiry action for the ScheduleTable with
       *   Os_ProcessSchedTable*/
      /* Start scheduleTable from 1st Index */
      LpSchedTable->ulIndex = OS_ZERO;
      /* Set the Schedule table state to waiting */
      LpAlarm->ucAlarmState = SCHEDULETABLE_WAITING;
    } /* End of if (LpAlarm->ucAlarmState == SCHEDULETABLE_STOPPED) */
    else
    {
      /* The schedule table is not stopped, return the proper error code */
      LenStatusReturn = E_OS_STATE;
    }
  } /* End of if (LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of StartScheduleTableSynchron(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernSyncScheduleTable                            **
**                                                                            **
** Service ID           : OSServiceId_SyncScheduleTable                       **
**                                                                            **
** Description          : This service is used to synchronize the processing  **
**                        of the schedule table to the synchronization        **
**                        counter.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Value                              **
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
**                        Os_SendSyncScheduleTable(),                         **
**                        Os_DoSyncScheduleTable()                            **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSyncScheduleTable
                             (ScheduleTableType ScheduleTableID, TickType Value)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SYNCSCHEDULETABLE, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether the Schedule table is implicitly synchronized */
  OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID, LenStatusReturn);
  /* Check whether the value is greater than the OsScheduleTableDuration */
  OS_CHECK_SCHEDTABLE_VALUE_ERROR(ScheduleTableID, Value, LenStatusReturn);
  /* Check whether Scheduletable can access the Application */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendStartScheduleTableSynchron and get the return value */
      LenStatusReturn = Os_SendSyncScheduleTable(ScheduleTableID, Value);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoStartScheduleTableSynchron and get the return value */
      LenStatusReturn = Os_DoSyncScheduleTable(ScheduleTableID, Value,
                                                                      OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_SyncScheduleTable);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Store the parameter 2 - Value */
    OS_STORE_PARAM2_VALUE(Value);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
   **/
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoSyncScheduleTable                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to synchronize the processing  **
**                        of the schedule table to the synchronization        **
**                        counter.                                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Value, LblRemoteCall               **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertAlarm(), Os_RemoveAlarm(), Os_GetMinValue()**
**                        Os_UpdateHwCounter(), Os_GetNextTick(),             **
**                        Os_AdjustTimerInterrupt()                           **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoSyncScheduleTable
      (ScheduleTableType ScheduleTableID, TickType Value, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  StatusType LenStatusReturn;
  TickType LddDate;
  TickType LddOffSet;
  TickType LddCurrentCount;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether a related alarm is in use already */
  OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  /* Check whether any error(E_OS_ID) occured or not */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Get the pointer to the corresponding alarm associated with the
     *   schedule table */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

    /* Check the current schedule table is started */
    if (LpAlarm->ucAlarmState > SCHEDULETABLE_NEXT)
    {
      /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
      LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
      /* Get the pointer to corresponding static counter associated with the
       * schedule table */
      LpStaticCounter = LpStaticSchedTable->pStaticCounter;
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* If Counter is a HW Counter, update counter tick from HW timer */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
      }
      #endif

      /* Check whether schedule table is in waiting state */
      if (LpAlarm->ucAlarmState == SCHEDULETABLE_WAITING)
      {
        LddDate = Os_GetNextTick(LpStaticCounter->pCounter->ddCurrentCount,
                              (LpStaticSchedTable->ddSchedTblDuration - Value)
                                                 + LpSchedTable->ddExpiryOffset,
                                            LpStaticCounter->ddMaxAllowedValue);
        /* Store the Alarm count */
        LpAlarm->ddAbsCount = LddDate;
        /*Change the state of schedule table to running and synchronous */
        LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        /* Insert an alarm */
        Os_InsertAlarm(LpAlarm);
        #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
        /* Adjust timer interrupt to counter tick of first alarm */
        if (LpStaticCounter->pHwCounter != NULL_PTR)
        {
          Os_AdjustTimerInterrupt(
                              LpStaticCounter->pCounter->pHeadAlarm->ddAbsCount,
                                                   LpStaticCounter->pHwCounter);
        }
        #endif
      } /* End of if (LpAlarm->ucAlarmState == SCHEDULETABLE_WAITING) */
      else
      {
        /* Store current count of the counter in local variable */
        LddCurrentCount =
        LpStaticSchedTable->pStaticCounter->pCounter->ddCurrentCount;
        /* Current expiry point's (to be processed) offset from the
           start of the schedule table */
        LddOffSet = (LpSchedTable->ddExpiryOffset);
        /* Check if absolute count of alarm is greater than current count
           of counter */
        if (LpAlarm->ddAbsCount >= LddCurrentCount)
        {
          /* Get the synchronization count */
          LddOffSet -= (LpAlarm->ddAbsCount - LddCurrentCount);
        }
        else
        {
          /* Get the synchronization count */
          LddOffSet -= ((LpStaticSchedTable->pStaticCounter->ddMaxAllowedValue
                           - LddCurrentCount) + (LpAlarm->ddAbsCount + OS_ONE));
        }
        /* Check whether the absolute value of the deviation between
           schedule table value and the synchronization count is greater than
           or equal to the configured */
        if (((LddOffSet - Value) < (LpStaticSchedTable->ddExplictPrecision)) ||
            ((Value - LddOffSet) < (LpStaticSchedTable->ddExplictPrecision)))
        {
          /* Change the state of schedule table running and synchronous */
          LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_PRE;
        }
        else
        {
          /* Change the state of schedule table running and synchronous */
          LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
        }
         /* Check If needs to do advance or Retard */
        if (LddOffSet == Value)
        {
          /* Change the state of schedule table running and synchronous */
          LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
        }
        else
        {
          /* FIXME: ManJe.Woo 2013.03.18. SyncScheduleTable() Bug!
           * NOTE: Adjust the delay of next expiry point,
           *       not the delay of current expiry point!
           * Reference: [OS420], [OS421]
           */
          /* Update ssDeviation of ScheduleTable */
          LpSchedTable->ssDeviation = (sint32)(LddOffSet - Value);
          LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_REQ;
        }
      } /* End of else */
    } /* End of if (LpAlarm->ucAlarmState > SCHEDULETABLE_NEXT) */
    else
    {
      /* The schedule table is already stopped/waiting, return the proper
       * error code */
      LenStatusReturn = E_OS_STATE;
    }
  } /* End of if (LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of SyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
   **/
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernSetScheduleTableAsync                        **
**                                                                            **
** Service ID           : OSServiceId_SetScheduleTableAsync                   **
**                                                                            **
** Description          : This service stops sychronization of                **
**                        a scheduletable                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID                                     **
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
**                        Os_SendSetScheduleTableAsync(),                     **
**                        Os_DoSetScheduleTableAsync()                        **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSetScheduleTableAsync(
                                              ScheduleTableType ScheduleTableID)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SETSCHEDULETABLEASYNC, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check whether the Schedule table is implicitly synchronised */
  OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID, LenStatusReturn);
  /* Check whether Scheduletable can access the Application */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
	  /* Call Os_SendSetScheduleTableAsync and get the return value */
	  LenStatusReturn = Os_SendSetScheduleTableAsync(ScheduleTableID);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
    	/* Call Os_DoSetScheduleTableAsync and get the return value */
	  LenStatusReturn = Os_DoSetScheduleTableAsync(ScheduleTableID, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_SetScheduleTableAsync);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of SetScheduleTableAsync(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoSetScheduleTableAsync                          **
**                                                                            **
** Service ID           : OSServiceId_SetScheduleTableAsync                   **
**                                                                            **
** Description          : This service stops sychronization of                **
**                        a scheduletable                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, LblRemoteCall                      **
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
**                        Os_GaaAlarm, Os_GaaStaticSchedTable,                **
**                        Os_GaaSchedTable                                    **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoSetScheduleTableAsync(
                                              ScheduleTableType ScheduleTableID,
                                              boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule Table */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Get the pointer to the corresponding alarm associated with the
     *   schedule table */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];

    /* Check if state of ScheduleTable is not Running */
    if ((LpAlarm->ucAlarmState == SCHEDULETABLE_RUNNING) ||
        (LpAlarm->ucAlarmState > SCHEDULETABLE_WAITING))
    {
      /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
      LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
      /* Make the deviation to Zero to stop further Synchronisation */
      LpSchedTable->ssDeviation = OS_ZERO;
      /* Change the state of schedule table to running */
      LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
    } /* End of if ((LpAlarm->ucAlarmState == SCHEDULETABLE_RUNNING) || */
    else
    {
      /* The schedule table is already stopped/waiting, return the proper
       *   error code */
      LenStatusReturn = E_OS_STATE;
    }
  } /* End of if (LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of SetScheduleTableAsync(ScheduleTableType ScheduleTableID) */
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetScheduleTableStatus                       **
**                                                                            **
** Service ID           : OSServiceId_GetScheduleTableStatus                  **
**                                                                            **
** Description          : This service is used to return the status of the    **
**                        schedule table requested.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, ScheduleStatus                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ScheduleStatus                                      **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable                              **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetScheduleTableStatus(),                    **
**                        Os_DoGetScheduleTableStatus()                       **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetScheduleTableStatus(
   ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus)
{
  StatusType LenStatusReturn;

  #if (OS_MULTICORE == STD_ON)
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the status return value to no error i.e E_OK */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETSCHEDULETABLESTATUS, LenStatusReturn);
  /* Check whether the ScheduleTableID is valid or not */
  OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, &LenStatusReturn);
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(ScheduleStatus, LenStatusReturn);
  /* Check whether Scheduletable can access the Application */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn,
                                                               ScheduleTableID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];

    /* Check if ScheduleTable belongs to same core */
    if (LpStaticSchedTable->ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendGetScheduleTableStatus and get the return value */
      LenStatusReturn = Os_SendGetScheduleTableStatus(ScheduleTableID,
                                                                ScheduleStatus);
    } /* End of if (LpStaticSchedTable->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoGetScheduleTableStatus and get the return value */
      LenStatusReturn = Os_DoGetScheduleTableStatus(ScheduleTableID,
                                                      ScheduleStatus, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */

  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store the service id */
    OS_STORE_SERVICE(OSServiceId_GetScheduleTableStatus);
    /* Store the parameter 1 - ScheduleTableID */
    OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID);
    /* Store the parameter 2 - ScheduleStatus */
    OS_STORE_PARAM2_SCHEDULESTATUS(ScheduleStatus);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif

  /* Return the value */
  return (LenStatusReturn);
} /* End of GetScheduleTableStatus(ScheduleTableType ScheduleTableID,
   *ScheduleTableStatusRefType ScheduleStatus) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoGetScheduleTableStatus                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to return the status of the    **
**                        schedule table requested.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, ScheduleStatus,                    **
**                        LblRemoteCall                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ScheduleStatus                                      **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoGetScheduleTableStatus(
   ScheduleTableType ScheduleTableID, ScheduleTableStatusRefType ScheduleStatus,
   boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  StatusType LenStatusReturn;
  uint8 LucAlarmState;

  /* Set the status return value to E_OK */
  LenStatusReturn = E_OK;
  /* Check whether Application is accessible */
  OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                ScheduleTableID, LblRemoteCall);

  /* Check whether any error(E_OS_ID) occured or not */
  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to corresponding Schedule table table */
    LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
    /* Store the Schedule table state */
    LucAlarmState = Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex].ucAlarmState;
    #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)

    /* If SchedTable state is OS_SCHEDULETABLE_EXP_PRE return as Synchronous */
    if (LucAlarmState == OS_SCHEDULETABLE_EXP_PRE)
    {
      LucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }

    /* Else update it as Running */
    if ((LucAlarmState == OS_SCHEDULETABLE_EXP_DEV) ||
        (LucAlarmState == OS_SCHEDULETABLE_EXP_REQ))
    {
      LucAlarmState = SCHEDULETABLE_RUNNING;
    }
    #endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */
    /* Update the Alarm State*/
    *ScheduleStatus = LucAlarmState;
  } /* End of if (LenStatusReturn == E_OK) */

  /* Return the value */
  return (LenStatusReturn);
} /* End of GetScheduleTableStatus(ScheduleTableType ScheduleTableID,
   *ScheduleTableStatusRefType ScheduleStatus) */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_SyncSchedRunning                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to synchronize the running     **
**                        ScheduleTable.                                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : ScheduleTableID, Value ,LddOffSet                   **
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
**                        Os_GaaStaticSchedTable, Os_GaaSchedTable,           **
**                        Os_GaaAlarm                                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertAlarm(), Os_GetMinValue()                  **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
FUNC(void, OS_CODE) Os_SyncSchedRunning(ScheduleTableType ScheduleTableID,
                                              TickType Value,TickType LddOffSet)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  P2CONST(Tdd_Os_ExpiryPoint, AUTOMATIC, OS_CONST) LpExpPoint;
  TickType LddCurrentCount;
  TickType LddValue;
  TickType LddDate;
  TickType LddDeviation;
  TickType LddDeviate;


  /* Get the pointer to corresponding Schedule Table */
  LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
  /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
  LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];
  /* Get the pointer to the corresponding alarm associated with the
     *   schedule table */
  LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];
  /* Get the pointer to corresponding static counter associated with the
       *   schedule table */
  LpStaticCounter = LpStaticSchedTable->pStaticCounter;

  /* Get the pointer to the initial expiry point associated with the
   *   schedule table */
  LpExpPoint = LpStaticSchedTable->pExpiryPoint + (LpSchedTable->ulIndex);

  /* Store current count of the counter in local variable */
  LddCurrentCount =
                   LpStaticSchedTable->pStaticCounter->pCounter->ddCurrentCount;
  /* Check whether the current synchronization count is greater
   *   than or lesser than the synchronization count passed */
  if (LddOffSet < Value) /* Advance */
  {
    /* Get the difference between the current synchronization count
     *   Value and the synchronization count passed */
    LddDeviation = Value - LddOffSet;
    /* Call function to get Min value for Advance */
    LddValue = Os_GetMinValue(LpExpPoint->ddMaxAdvancePeriod,
                                                          LddDeviation);
    /* Update ssDeviation of ScheduleTable */
    LpSchedTable->ssDeviation = (sint32)(LddDeviation - LddValue);
    /* Update ddAbsCount for alarm */
    LddDate = LpAlarm->ddAbsCount + LddValue;
  } /* End of if (LddOffSet < Value) */
  else /* Retard */
  {
    /* Get the difference between the synchronization count passed
     *   Value and the current synchronization count */
    LddDeviation = LddOffSet - Value;
    /* Call function to get Min value for Retard */
    LddValue = Os_GetMinValue
                          (LpExpPoint->ddMaxRetardPeriod, LddDeviation);
    /* Update ssDeviation of ScheduleTable */
    LpSchedTable->ssDeviation = (sint32)(LddValue - LddDeviation);
    /* Check if Deviation is possible with the given value with current
     *   count when alarm absolute count is greater than current count
     * */
    if ((LpAlarm->ddAbsCount > LddCurrentCount) &&
                  (LddValue >= (LpAlarm->ddAbsCount - LddCurrentCount)))
    {
      LddDeviate = (LpAlarm->ddAbsCount - LddCurrentCount) - OS_ONE;
      /* Update ssDeviation of ScheduleTable */
      LpSchedTable->ssDeviation -= (sint32)(LddValue - LddDeviate);
      /* Update LddValue */
      LddValue = LddDeviate;
    } /* End of if ((LpAlarm->ddAbsCount > LddCurrentCount) && */

    /* Check if Deviation is possible with the given value with current
     *   count when alarm absolute count is less than current count */
    if (LpAlarm->ddAbsCount < LddCurrentCount)
    {
      LddDeviate =
                (LpStaticSchedTable->pStaticCounter->ddMaxAllowedValue -
                               LddCurrentCount) + (LpAlarm->ddAbsCount);

      if (LddValue >= LddDeviate)
      {
        /* Update ssDeviation of ScheduleTable */
        LpSchedTable->ssDeviation -= (sint32)(LddValue - LddDeviate);
        /* LddValue */
        LddValue = LddDeviate;
      } /* End of if (LddValue >= LddDeviate) */
    } /* End of if (LpAlarm->ddAbsCount < LddCurrentCount) */

    /* Check whether ddAbsCount is less than LddValue */
    if (LpAlarm->ddAbsCount < LddValue)
    {
      LddDate = LpStaticCounter->ddMaxAllowedValue -
                                              (LddValue - LpAlarm->ddAbsCount);
    }
    /* Else update the value */
    else
    {
      LddDate = LpAlarm->ddAbsCount - LddValue;
    }
  } /* End of else */

  /* Check whether LddDate is greater than Maximum allwed value for
   *   Counter */
  if (LddDate > LpStaticCounter->ddMaxAllowedValue)
  {
    /* If value exceeds then adjust the offset */
    LddDate -= LpStaticCounter->ddMaxAllowedValue + OS_ONE;
  }
  /* Load value into Alarm */
  LpAlarm->ddAbsCount = LddDate;

  /* Change state of the ScheduleTable */
  if (LpSchedTable->ssDeviation == OS_ZERO)
  {
    if (LpAlarm->ucAlarmState == OS_SCHEDULETABLE_EXP_PRE)
    {
      /* Change the state of schedule table running and synchronous */
      LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }
    else
    {
      /* Else do not change the state */
      LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_DEV;
    }
  } /* End of if (LpSchedTable->ssDeviation == OS_ZERO) */
  else if (LpAlarm->ucAlarmState != OS_SCHEDULETABLE_EXP_PRE)
  {
    /* Change the state of schedule table running and synchronous */
    LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_REQ;
  }
  else
  {
    /* To avoid QAC warning */
  }
  /* Insert an alarm */
  Os_InsertAlarm(LpAlarm);
}
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_GetMinValue                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function returns minimum value between 2 values**
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : LddMaxPeriod,  LddDeviation                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : TickType                                            **
**                                                                            **
** Preconditions        : The Os must be initialized                          **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
static FUNC(TickType, OS_CODE) Os_GetMinValue(TickType LddMaxPeriod,
                                                          TickType LddDeviation)
{
  TickType LddValue;

  /* Check if Deviation is less than LddMaxPeriod */
  if (LddDeviation < LddMaxPeriod)
  {
    /* Update LddValue with deviation */
    LddValue = LddDeviation;
  }
  else
  {
    /* Update LddValue with LddMaxPeriod */
    LddValue = LddMaxPeriod;
  }
  /* Return the Minimum value */
  return (LddValue);
} /* End of Os_GetMinValue(TickType LddMaxPeriod, TickType LddDeviation) */
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ProcessSchedTable                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to processs the necessary      **
**                        actions associated with an expiry point of the      **
**                        schedule and reload the alarm delay with the offset **
**                        of the next expiry point.                           **
**                        Alarm cycle time is updated as per next expiry      **
**                        point of the scheduletable                          **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : pAction                                             **
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
**                        Os_GaaStaticSchedTable, Os_GaaAlarm                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetMinValue(), Os_InsertAlarm(),                 **
**                        Os_AlarmActivateTask(), Os_AlarmSetEvent(),         **
**                        Os_ProcessSchedTableEnd()                           **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_ProcessSchedTable
                   (P2CONST(Tdd_Os_SchedTable, AUTOMATIC, OS_CONST) pAction)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2CONST(Tdd_Os_Action, AUTOMATIC, OS_CONST) LpAction;
  P2CONST(Tdd_Os_ExpiryPoint, AUTOMATIC, OS_VAR) LpExpiryPoint;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  Tdd_Os_ActivateTask actionTask;
  Tdd_Os_AlarmEvent actionEvent;
  #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
  TickType LddValue;
  sint32 LscValue;
  #endif
  StatusType LenStatusReturn;
  uint32 LulIndex;
  uint8 LucCount;
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Get the pointer to corresponding schedule table */
  LpSchedTable = (P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR))pAction;
  /* Get the static ScheduleTable */
  LpStaticSchedTable = &Os_GaaStaticSchedTable[LpSchedTable->ddSchedTableId];
  /* Get the pointer to corresponding alarm of the schedule table */
  LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];
  /* Get the Expiry point  index value */
  LulIndex = (LpSchedTable->ulIndex);

  if (LulIndex < (LpStaticSchedTable->ulExpiryCount))
  {
    /* Get the pointer to corresponding expiry point */
    LpExpiryPoint = LpStaticSchedTable->pExpiryPoint;
    LpExpiryPoint += LulIndex;
    /* Get the number of actions associated with expiry counts */
    LucCount = LpExpiryPoint->ucCount;
    /* Get the pointer to first action point */
    LpAction = LpExpiryPoint->pAction;

    /* Loop until all the actions associated with expiry counts are processed */
    while (LucCount != OS_ZERO)
    {
      /* Invoke the corresponding action associated with the expiry point and
       *   store the return value */
      if (LpAction->enActionType == OS_ACTION_ACTIVATETASK)
      {
        actionTask.pActivateTaskFunc = &Os_AlarmActivateTask;
        actionTask.pStaticTask = LpAction->pStaticTask;

        LenStatusReturn |= Os_AlarmActivateTask(&actionTask);
      }
      #if (OS_EVENT == STD_ON)
      else if (LpAction->enActionType == OS_ACTION_SETEVENT)
      {
        actionEvent.pAlarmEventFunc = &Os_AlarmSetEvent;
        actionEvent.pStaticTask = LpAction->pStaticTask;
        actionEvent.ddEventMask = LpAction->ddEventMask;

        LenStatusReturn |= Os_AlarmSetEvent(&actionEvent);
      }
      #endif
      else
      {
        LenStatusReturn = E_NOT_OK;
      }
      /* Decrement the number of actions associated with the expiry count */
      LucCount--;
      /* Increment pointer to point to next action associated with the expiry
       *   point */
      LpAction++;
    }

    /* Get the pointer to next expiry point */
    LpExpiryPoint++;
    /* Initialize value of alarm */
    LpAlarm->ddCycle = OS_ZERO;

    #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)

    /* Check whether Schedule Table needs to be synchronised */
    if (LpAlarm->ucAlarmState > SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
    {
      /* Check if deviation is ZERO */
      if (LpSchedTable->ssDeviation == OS_ZERO)
      {
        /* Change the state of schedule table running and synchronous */
        LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
      }
      else
      {
        /* Get the Deviation */
        LscValue = LpSchedTable->ssDeviation;

        if (LscValue > OS_ZERO) /* Advance */
        {
          /* Call function to get Min value for Advance */
          LddValue = Os_GetMinValue(LpExpiryPoint->ddMaxAdvancePeriod,
              (TickType)LscValue);
          /* Update the deviation */
          LpSchedTable->ssDeviation -= (sint32)LddValue;
          /* Update Cycle for alarm */
          LpAlarm->ddCycle = LddValue;
        } /* End of if (LscValue > OS_ZERO) */
        else                    /* Retard */
        {
          /* Take Mod value of LscValue */
          LscValue = LscValue * (OS_MINUS_ONE);
          /* Call function to get Min value for Advance */
          LddValue = Os_GetMinValue(LpExpiryPoint->ddMaxRetardPeriod,
              (TickType)LscValue);
          /* Update the deviation */
          LpSchedTable->ssDeviation += (sint32)LddValue;
          /* Update Cycle for alarm */
          LpAlarm->ddCycle -= LddValue;
        } /* End of else */

        if ((TickType)LscValue < LpStaticSchedTable->ddExplictPrecision)
        {
          /* Change the state of schedule table running and synchronous */
          LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_PRE;
        }
      } /* End of else */
    } /* End of if (LpAlarm->ucAlarmState >
     *SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS) */
    #endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */
    LpAlarm->ddCycle += LpExpiryPoint->ddOffset;
    /* Update the Offset of next expiry point to be processed from start */
    LpSchedTable->ddExpiryOffset += LpAlarm->ddCycle;
    /* Point to the next expiry point */
    LpSchedTable->ulIndex++;
  } /* End of if (LulIndex < (LpStaticSchedTable->ulExpiryCount)) */
  else
  {
    /* Call Os_ProcessSchedTableEnd for the last expiry point */
    LenStatusReturn = Os_ProcessSchedTableEnd(LpSchedTable->ddSchedTableId);
  } /* End of else */
                                  /* Return the value */
  return (LenStatusReturn);
} /* End of Os_ProcessSchedTable(P2CONST(Tdd_Os_SchedTable,
   *AUTOMATIC, */
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_ProcessSchedTableEnd                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used for Processing of last expiry  **
**                        last expiry point.                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : NA                                                  **
**                                                                            **
** Input Parameters     : ScheduleTableID                                     **
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
**                        Os_GaaStaticSchedTable, Os_GaaSchedTable            **
**                        Os_GaaAlarm                                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_InsertAlarm(), Os_GetMinValue(),                 **
**                        Os_AlarmActivateTask(), Os_AlarmSetEvent()          **
*******************************************************************************/
#if (OS_SCHEDTABLE == STD_ON)
static FUNC(StatusType, OS_CODE) Os_ProcessSchedTableEnd
                                             (ScheduleTableType ScheduleTableID)
{
  P2CONST(Tdd_Os_StaticSchedTable, AUTOMATIC, OS_CONST) LpStaticSchedTable;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  P2CONST(Tdd_Os_ExpiryPoint, AUTOMATIC, OS_VAR) LpExpiryPoint;
  P2VAR(Tdd_Os_SchedTable, AUTOMATIC, OS_VAR) LpSchedTable;
  P2CONST(Tdd_Os_Action, AUTOMATIC, OS_CONST) LpAction;
  Tdd_Os_ActivateTask actionTask;
  Tdd_Os_AlarmEvent actionEvent;
  TickType LddValue;
  #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
  sint32 LscValue;
  #endif
  StatusType LenStatusReturn;
  uint8 LucCount;

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Get the static ScheduleTable */
  LpStaticSchedTable = &Os_GaaStaticSchedTable[ScheduleTableID];
  /* Get the pointer to corresponding Schedule Table with ScheduleTableID */
  LpSchedTable = &Os_GaaSchedTable[ScheduleTableID];

  /* Get the pointer to corresponding alarm of the schedule table */
  LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];
  /* Set the alarm cycle to zero */
  (LpAlarm->ddCycle) = OS_ZERO;

  /* Check if ScheduleTable is Periodic */
  if ((LpStaticSchedTable->blPeriodic) == OS_FALSE)
  {
    /* Reset the state of the current schedule table to stopped */
    LpAlarm->ucAlarmState = SCHEDULETABLE_STOPPED;
  }
  else
  {
    /* Points to first expiry point */
    LpExpiryPoint = LpStaticSchedTable->pExpiryPoint;
    #if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
    /* Check whether Schedule Table Syncronization Strategy is Explicit */
    if (LpAlarm->ucAlarmState > SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS)
    {
      /* Get the Deviation */
      LscValue = LpSchedTable->ssDeviation;
      /* Check if LscValue is ZERO */
      if (LscValue != OS_ZERO)
      {
        if (LscValue > OS_ZERO) /* Advance */
        {
          /* Call function to get Min value for Advance */
          LddValue = Os_GetMinValue(
                       LpExpiryPoint->ddMaxAdvancePeriod, (TickType)LscValue);
          /* Update the deviation */
          LpSchedTable->ssDeviation -= (sint32)LddValue;
          /* Update Cycle for alarm */
          LpAlarm->ddCycle += LddValue;
        } /* End of if (LscValue > OS_ZERO) */
        else                    /* Retard */
        {
          /* Take Mod value of LscValue */
          LscValue = LscValue * (OS_MINUS_ONE);
          /* Call function to get Min value for Advance */
          LddValue = Os_GetMinValue(
                        LpExpiryPoint->ddMaxRetardPeriod, (TickType)LscValue);
          /* Update the deviation */
          LpSchedTable->ssDeviation += (sint32)LddValue;
          /* Update Cycle for alarm */
          LpAlarm->ddCycle -= LddValue;
        } /* End of else */
      } /* End of if (LscValue != OS_ZERO) */
      /* Check if LscValue is less than Precision */
      if ((TickType)LscValue < LpStaticSchedTable->ddExplictPrecision)
      {
        /* Change the state of schedule table running and synchronous */
        LpAlarm->ucAlarmState = OS_SCHEDULETABLE_EXP_PRE;
      }
    } /* End of if (LpAlarm->ucAlarmState >
         *SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS) */
    #endif /* #if(OS_SCHED_EXPLICIT_SYNC == STD_ON) */

    /* Check if any Expiry point is configured at the start */
    if (LpExpiryPoint->ddOffset != OS_ZERO)
    {
      /* Update Cycle with Expiry point offset */
      LpAlarm->ddCycle += LpExpiryPoint->ddOffset;
      /* Save the next expiry point index */
      LpSchedTable->ulIndex = OS_ZERO;
      /* Update the Offset of next expiry point to be processed from start */
      LpSchedTable->ddExpiryOffset = LpAlarm->ddCycle;
    } /* End of if (LpExpiryPoint->ddOffset != OS_ZERO) */
    else
    {
      /* Point to the first expiry point*/
      LpSchedTable->ulIndex = OS_ZERO;
      /* Get the number of actions associated with expiry counts */
      LucCount = LpExpiryPoint->ucCount;
      /* Get the pointer to first action point */
      LpAction = LpExpiryPoint->pAction;

      /* Loop until all the actions associated with expiry counts are
       *   processed */
      while (LucCount != OS_ZERO)
      {
        /* Invoke the corresponding action associated with the expiry point
         *   and store the return value */
        if (LpAction->enActionType == OS_ACTION_ACTIVATETASK)
        {
          actionTask.pActivateTaskFunc = &Os_AlarmActivateTask;
          actionTask.pStaticTask = LpAction->pStaticTask;

          LenStatusReturn |= Os_AlarmActivateTask(&actionTask);
        }
        #if (OS_EVENT == STD_ON)
        else if (LpAction->enActionType == OS_ACTION_SETEVENT)
        {
          actionEvent.pAlarmEventFunc = &Os_AlarmSetEvent;
          actionEvent.pStaticTask = LpAction->pStaticTask;
          actionEvent.ddEventMask = LpAction->ddEventMask;

          LenStatusReturn |= Os_AlarmSetEvent(&actionEvent);
        }
        #endif
        else
        {
          LenStatusReturn = E_NOT_OK;
        }
        /* Decrement the number of actions associated with the expiry count */
        LucCount--;
        /* Increment the pointer to point to next action associated with the
         *   expiry point */
        LpAction++;
      }

      /* Get the pointer to next expiry point */
      LpExpiryPoint++;
      /* Update cycle with next expiry point */
      LpAlarm->ddCycle += LpExpiryPoint->ddOffset;
      /* Update the Offset of next expiry point to be processed from start */
      LpSchedTable->ddExpiryOffset += LpAlarm->ddCycle;
      /* Point to the next expiry point */
      LpSchedTable->ulIndex++;
    } /* End of else */
  } /* End of else */

  /* Check whether next schedule table exists or not */
  if ((LpSchedTable->ddNextSchedTable) != OS_INVALID_VALUE)
  {
    LpStaticSchedTable =
                    &Os_GaaStaticSchedTable[(LpSchedTable->ddNextSchedTable)];
    /* Get the pointer to Alarm object */
    LpAlarm = &Os_GaaAlarm[LpStaticSchedTable->ddAlarmIndex];
    #if (OS_SCHED_IMPLICIT_SYNC == STD_ON)

    /* Check weather ScheduleTable is implicitly syncronised */
    if (LpStaticSchedTable->ucSynchStrategy == OS_SCHEDTABLE_IMPLICIT_SYNC)
    {
      /* Set the Schedule table state to running & Synchronous */
      LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING_AND_SYNCHRONOUS;
    }
    else
    #endif /* End of if (OS_SCHED_IMPLICIT_SYNC == STD_ON) */
    {
      /* Set the Schedule table state to running */
      LpAlarm->ucAlarmState = SCHEDULETABLE_RUNNING;
    }
    /* Pointer to the NextScheduleTable is removed */
    (LpSchedTable->ddNextSchedTable) = OS_INVALID_VALUE;
    /* Get the pointer to first expiry point */
    LpExpiryPoint = LpStaticSchedTable->pExpiryPoint;
    /* XXX: ManJe.Woo 2013.03.18. Counter offset Bug!
     * NOTE: Count 1(MaxAllowedValue to 0) is not calculated.
     */
    LddValue = LpStaticSchedTable->pStaticCounter->pCounter->ddCurrentCount
                                                  + (LpExpiryPoint->ddOffset);

    /* Check whether the offset is greater than the maximum allowed value
     *   of the underlying counter */
    if (LddValue > LpStaticSchedTable->pStaticCounter->ddMaxAllowedValue)
    {
      /* If value exceeds then adjust the offset */
      LddValue -= (LpStaticSchedTable->pStaticCounter->ddMaxAllowedValue
                                                                    + OS_ONE);
    }

    LpAlarm->ddAbsCount = LddValue;
    /* Insert an alarm */
    Os_InsertAlarm(LpAlarm);
  } /* End of if ((LpSchedTable->ddNextSchedTable) != OS_INVALID_VALUE) */
  return(LenStatusReturn);
}
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

