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
**  SRC-MODULE: Os_Counter.c                                                  **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Counter functionality.                           **
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
** 2.6.9     11-Jan-2021    YH.Han        Redmine #27622                      **
** 2.6.5     15-Jul-2020    YH.Han        Redmine #24712                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.2     13-Apr-2020    MJ.Woo        Redmine #22921                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.5.0     25-Jun-2018    SH.Yoo        Redmine #13150                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025, #12132              **
** 2.4.2     05-Mar-2018    MJ.Woo        Redmine #7001                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #494, #1189                 **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     20-Aug-2013    MJ.Woo        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect:Medium] "Already verified value" */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Alarm.h"             /* Os Alarm header file */
#include "Os_Counter.h"           /* Os Counter header file */
#include "Os_Error.h"             /* Os Error header file */
#if (OS_MEMORY_PROTECTION == STD_ON)
#include "Os_Application.h"       /* Os Application header file */
#endif
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
#endif
#include "Os_Arch_Timer.h"
#include "Os_SystemCallTable.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/

#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Os_CounterTick                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function increments counter value and          **
**                        checks if any alarm expires.                        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : LpStaticCounter                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)  :                               **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_RemoveAlarmSet(), Os_InsertAlarm()               **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_CounterTick(P2CONST(Tdd_Os_StaticCounter,
                                           AUTOMATIC, OS_CONST) LpStaticCounter)
{
  TickType LddCurrentCount;
  P2VAR(Tdd_Os_Counter, AUTOMATIC, OS_VAR) LpCounter;
  StatusType LddStatusReturn = E_OK;

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get the pointer to counter */
  LpCounter = LpStaticCounter->pCounter;
  LddCurrentCount = LpCounter->ddCurrentCount;
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  /* Check whether counter has reached to maximum allowed value */
  if (LddCurrentCount == LpStaticCounter->ddMaxAllowedValue)
  {
    /* Reset the counter */
    LddCurrentCount = OS_ZERO;
  }
  else
  {
    /* Increment counter */
    LddCurrentCount++;
  }
  /* Copy the local counter value to RAM */
  LpCounter->ddCurrentCount = LddCurrentCount;

  #if (OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)
  LddStatusReturn = Os_ProcessAlarm(LpStaticCounter);
  #endif

  /* Return the value */
  return LddStatusReturn;
} /* End of Os_CounterTick(P2CONST(Tdd_Os_StaticCounter, AUTOMATIC,
   * OS_CONST) LpStaticCounter) */
#endif /* End of if (OS_COUNTER == STD_ON) */

/*******************************************************************************
** Function Name        : Os_DoGetCounterValue                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the current value       **
**                        of a counter.CounterId is the input parameter.      **
**                        value, is a reference (pointer) to the variable     **
**                        where the value of the counter is stored.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CounterID                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : value                                               **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
/* polyspace +2 MISRA-C3:8.7 [Not a defect:Low] "External visible function" */
FUNC(StatusType, OS_CODE) Os_DoGetCounterValue(CounterType CounterID,
                                       TickRefType Value, boolean LenRemoteCall)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  StatusType LenStatusReturn = E_OK;

  /* Check whether Counter is in use already */
  OS_CHECK_COUNTER_INUSE_ERROR(CounterID, &LenStatusReturn);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                      CounterID, LenRemoteCall);

  /* polyspace<RTE: UNR : Not a defect : No Action Planned > If multicore is not defined, this violation occurs. but this code has already been verified and no impact of this rule violation */
  /* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Boolean result is variant according to counter usage or multicore operation */
  if (LenStatusReturn == (StatusType)E_OK)
  {
    /* Pointer to static counter */
    LpStaticCounter = &Os_GaaStaticCounter[CounterID];
    #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<RTE: UNR : Not a defect : Justify with annotations> NULL pointer check */
    /* If Counter is a HW Counter, update counter tick from HW timer */
    if (LpStaticCounter->pHwCounter != NULL_PTR)
    {
      Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
    }
    #endif
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Copy the counter value */
    *Value = (LpStaticCounter->pCounter->ddCurrentCount);
  }

  return LenStatusReturn;
}
#endif

/*******************************************************************************
** Function Name        : Os_DoGetElapsedCounterValue                         **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the elapsed value       **
**                        of a counter                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CounterType CounterID, TickRefType Value,           **
**                             TickRefType ElapsedValue, boolean LenRemoteCall**
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ElapsedValue                                        **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
/* polyspace +2 MISRA-C3:8.7 [Not a defect:Low] "External visible function" */
FUNC(StatusType, OS_CODE) Os_DoGetElapsedCounterValue(CounterType CounterID,
             TickRefType Value, TickRefType ElapsedValue, boolean LenRemoteCall)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  TickType LddCurrentVal;
  TickType LddPreviousVal;
  StatusType LenStatusReturn = E_OK;

  /* Check whether Counter is in use already */
  OS_CHECK_COUNTER_INUSE_ERROR(CounterID, &LenStatusReturn);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn,
                                                    CounterID, LenRemoteCall);

  /* polyspace<RTE: UNR : Not a defect : No Action Planned > If multicore is not defined, this violation occurs. but this code has already been verified and no impact of this rule violation */
  /* polyspace<MISRA-C:13.7:Not a defect:Justify with annotations> Boolean result is variant according to counter usage or multicore operation */
  if (LenStatusReturn == (StatusType)E_OK)
  {
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Previous value is stored */
    LddPreviousVal = *Value;
    /* Get the counter descriptor */
    LpStaticCounter = &Os_GaaStaticCounter[CounterID];
    #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
    /* If Counter is a HW Counter, update counter tick from HW timer */
    /* polyspace<RTE: UNR : Not a defect : Justify with annotations> NULL pointer check */
    if (LpStaticCounter->pHwCounter != NULL_PTR)
    {
      Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
    }
    #endif
    /* Get the current counter value */
    LddCurrentVal = LpStaticCounter->pCounter->ddCurrentCount;
    /* Copy the counter value */
    *Value = LddCurrentVal;

    /* Check if LddCurrentVal is less than LddPreviousVal */
    if (LddCurrentVal < LddPreviousVal)
    {
      LddCurrentVal += LpStaticCounter->ddMaxAllowedValue + OS_ONE;
    }
    /* Copy its value in Elapsedvalue ref */
    *ElapsedValue = LddCurrentVal - LddPreviousVal;
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */
  }


  return LenStatusReturn;
}
#endif
/*******************************************************************************
** Function Name        : Os_KernIncrementCounter                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : IncrementCounter() increments the counter           **
**                        <CounterID> by one and returns E_OK.                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : CounterID                                           **
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
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_CounterTick()                                    **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernIncrementCounter(CounterType CounterID)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = (StatusType)E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
 /* Check for call from hook*/
  OS_CHECK_E_OS_CALLEVEL(INCREMENTCOUNTER, LenStatusReturn);
  /* Check whether CounterId is greater than number of Counter count */
  OS_CHECK_COUNTER_ID_ERROR(CounterID, &LenStatusReturn);
  /* Check whether it's hardware counter or software counter */
  /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
  OS_CHECK_COUNTER_KIND_ERROR(CounterID, LenStatusReturn);
  /* polyspace:end<RTE:UNR> */
  /* Check if API is called on another core */
  OS_CHECK_COUNTER_RESIDING_COUNTER_ERROR(CounterID, OS_CORE_ID,
    LenStatusReturn);
  /* Check whether counter can access the Application */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, CounterID);
  /* polyspace:begin<MISRA-C:13.7:Not a defect:Justify with annotations> This macro will be changed to inline function */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, \
                                                      CounterID, OS_FALSE);
  /* polyspace:end<MISRA-C:13.7:Not a defect:Justify with annotations> This macro will be changed to inline function */

  /* Check whether status return is E_OK */
  /* polyspace-begin RTE:UNR [Not a Defect] "status check" */
  if (LenStatusReturn == (StatusType)E_OK)
  {
    /* Pointer to static counter */
    LpStaticCounter = &Os_GaaStaticCounter[CounterID];
    /* Function called to increment count and to check if any alarm expires */
    (void)Os_CounterTick(LpStaticCounter);
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  else
  {
    /* Store the ServiceID of the Function */
    OS_STORE_SERVICE(OSServiceId_IncrementCounter);
    /* Store the parameter 1 - CounterID */
    OS_STORE_PARAM1_COUNTERID(CounterID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif
  /* polyspace-end RTE:UNR */

  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_KernIncrementCounter(CounterType CounterID) */
#endif /* End of if (OS_COUNTER == STD_ON) */


/*******************************************************************************
** Function Name        : Os_KernGetCounterValue                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the current value       **
**                        of a counter.CounterId is the input parameter.      **
**                        value, is a reference (pointer) to the variable     **
**                        where the value of the counter is stored.           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CounterID                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : value                                               **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetCounterValue(), Os_DoGetCounterValue()    **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetCounterValue(CounterType CounterID,
                                                              TickRefType Value)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETCOUNTERVALUE, LenStatusReturn);
  /* Check whether CounterId is greater than number of Counter count */
  OS_CHECK_COUNTER_ID_ERROR(CounterID, &LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Value, LenStatusReturn);
  /* Check whether counter can access the Application */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, CounterID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Check if Counter belongs to same core */
    if (Os_GaaStaticCounter[CounterID].ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendGetCounterValue to get counter tick on respective core */
      LenStatusReturn = Os_SendGetCounterValue(CounterID, Value);
    } /* End of if (LpStaticCounter->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoGetCounterValue and get the return value */
      LenStatusReturn = Os_DoGetCounterValue(CounterID, Value, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Stores the ServiceID of the function */
    OS_STORE_SERVICE(OSServiceId_GetCounterValue);
    /* Store the parameter 1 - CounterID */
    OS_STORE_PARAM1_COUNTERID(CounterID);
    /* Store the parameter 2 - Value */
    OS_STORE_PARAM2_VALUEREF(Value);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of GetCounterValue(CounterType CounterID, TickRefType Value) */
#endif /* End of if (OS_COUNTER == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetElapsedValue                              **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to get the elapsed value       **
**                        of a counter                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CounterID, Value                                    **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : ElapsedValue                                        **
**                                                                            **
** Return parameter     : StatusType                                          **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaStaticCounter                                 **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendGetElapsedCounterValue(),                    **
**                        Os_DoGetElapsedCounterValue()                       **
*******************************************************************************/
#if (OS_COUNTER == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetElapsedValue(CounterType CounterID,
                                    TickRefType Value, TickRefType ElapsedValue)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETELAPSEDVALUE, LenStatusReturn);
  /* Check whether CounterId is greater than number of Counter count */
  OS_CHECK_COUNTER_ID_ERROR(CounterID, &LenStatusReturn);
  /* Check for NULL_PTR */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > NULL pointer check */
  OS_CHECK_NULL_PTR(Value, LenStatusReturn);
  /* Check the previous value does not exceed the max allowed value of the
   *   counter */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(CounterID, Value, LenStatusReturn);
  /* Check for NULL_PTR */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > NULL pointer check */
  OS_CHECK_NULL_PTR(ElapsedValue, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> status check */
  /* Check whether counter can access the Application */
  OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, CounterID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Check if Counter belongs to same core */
    if (Os_GaaStaticCounter[CounterID].ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendGetElapsedCounterValue
       *  to get elapsed counter tick on respective core */
      LenStatusReturn = Os_SendGetElapsedCounterValue(CounterID,
                                                           Value, ElapsedValue);
    } /* End of if (LpStaticCounter->ddCoreID != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoGetElapsedCounterValue and get the return value */
      LenStatusReturn = Os_DoGetElapsedCounterValue(CounterID,
                                                 Value, ElapsedValue, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Stores the ServiceID of the function */
    OS_STORE_SERVICE(OSServiceId_GetElapsedValue);
    /* Store the parameter 1 - CounterID */
    OS_STORE_PARAM1_COUNTERID(CounterID);
    /* Store the parameter 2 - Value */
    OS_STORE_PARAM2_VALUEREF(Value);
    /* Store the parameter 3 - ElapsedValue */
    OS_STORE_PARAM3_ELAPSEDVALUE(ElapsedValue);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_STATUS == EXTENDED) */

  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of GetElapsedValue(CounterType CounterID, TickRefType Value,
   *TickRefType ElapsedValue) */
#endif /* End of if (OS_COUNTER == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-end MISRA-C3:D4.14 */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
