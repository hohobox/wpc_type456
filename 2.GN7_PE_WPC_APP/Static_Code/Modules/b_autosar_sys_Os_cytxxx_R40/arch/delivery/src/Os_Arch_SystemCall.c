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
**  SRC-MODULE: Os_Arch_SystemCall.c                                          **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of system call specific functionality               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: Yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 2.0.0     01-Jul-2020    JH.Cho        Redmine #24316                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:11.1 [Justified:Medium] "To meet system call interface" */
/* polyspace-begin MISRA-C3:11.4 [Justified:Medium] "To meet system call interface" */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To meet system call interface */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_SystemCallTable.h"
#include "Os_Arch_Interrupt.h"
#include "Os_Arch_Ram.h"
#include "Os_Arch_Except.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_ALARM == STD_ON)
/* function for GetAlarmBase() system call */
StatusType Os_SystemCallGetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)AlarmID, (uint32)Info, (uint32)0, (uint32)Os_KernGetAlarmBase);
  }
  else
  {
    LddStatusReturn = Os_KernGetAlarmBase(AlarmID, Info);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetAlarm() system call */
StatusType Os_SystemCallGetAlarm(AlarmType AlarmID,  TickRefType Tick)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)AlarmID, (uint32)Tick, (uint32)0, (uint32)Os_KernGetAlarm);
  }
  else
  {
    LddStatusReturn = Os_KernGetAlarm(AlarmID, Tick);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for SetRelAlarm() system call */
StatusType Os_SystemCallSetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)AlarmID, (uint32)Increment, (uint32)Cycle, (uint32)Os_KernSetRelAlarm);
  }
  else
  {
    LddStatusReturn = Os_KernSetRelAlarm(AlarmID, Increment, Cycle);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for SetAbsAlarm() system call */
StatusType Os_SystemCallSetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)AlarmID, (uint32)Start, (uint32)Cycle, (uint32)Os_KernSetAbsAlarm);
  }
  else
  {
    LddStatusReturn = Os_KernSetAbsAlarm(AlarmID, Start, Cycle);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for CancelAlarm() system call */
StatusType Os_SystemCallCanCelAlarm(AlarmType AlarmID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)AlarmID, (uint32)0, (uint32)0, (uint32)Os_KernCancelAlarm);
  }
  else
  {
    LddStatusReturn = Os_KernCancelAlarm(AlarmID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* (OS_ALARM == STD_ON) */

#if (OS_APPLICATION == STD_ON)
/* function for GetApplicationID() system call */
ApplicationType Os_SystemCallGetApplicationID(void)
{
  Os_OldLevel_T LddOldIntVal;
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddApplicationID = Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernGetApplicationID);
  }
  else
  {
    LddApplicationID = Os_KernGetApplicationID();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddApplicationID;
}

/* function for CheckObjectOwnership() system call */
ApplicationType Os_SystemCallCheckObjectOwnership(ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  Os_OldLevel_T LddOldIntVal;
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddApplicationID = Os_CallFuncKernelStack((uint32)ObjectType, (uint32)ObjectID, (uint32)0, (uint32)Os_KernCheckObjectOwnership);
  }
  else
  {
    LddApplicationID = Os_KernCheckObjectOwnership(ObjectType, ObjectID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddApplicationID;
}

#if ((OS_SCALABILITY_CLASS == OS_SC3) || (OS_SCALABILITY_CLASS == OS_SC4))
/* function for CheckObjectAccess() system call */
ObjectAccessType Os_SystemCallCheckObjectAccess(ApplicationType ApplID, ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  Os_OldLevel_T LddOldIntVal;
  ObjectAccessType LddAccessReturn = NO_ACCESS;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddAccessReturn = (ObjectAccessType)Os_CallFuncKernelStack((uint32)ApplID, (uint32)ObjectType, (uint32)ObjectID, (uint32)Os_KernCheckObjectAccess);
  }
  else
  {
    LddAccessReturn = Os_KernCheckObjectAccess(ApplID, ObjectType, ObjectID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddAccessReturn;
}

/* function for TerminateApplication() system call */
StatusType Os_SystemCallTerminateApplication(ApplicationType Application, RestartType RestartOption)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)Application, (uint32)RestartOption, (uint32)0, (uint32)Os_KernTerminateApplication);
  }
  else
  {
    LddStatusReturn = Os_KernTerminateApplication(Application, RestartOption);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for AllowAccess() system call */
StatusType Os_SystemCallAllowAccess(void)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernAllowAccess);
  }
  else
  {
    LddStatusReturn = Os_KernAllowAccess();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetApplicationState() system call */
StatusType Os_SystemCallGetApplicationState(ApplicationType Application, ApplicationStateRefType Value)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)Application, (uint32)Value, (uint32)0, (uint32)Os_KernGetApplicationState);
  }
  else
  {
    LddStatusReturn = Os_KernGetApplicationState(Application, Value);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* ((OS_SCALABILITY_CLASS == OS_SC3) || (OS_SCALABILITY_CLASS == OS_SC4)) */
#endif /* (OS_APPLICATION == STD_ON) */

#if (OS_MEMORY_PROTECTION == STD_ON)
#if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
/* function for CallTrustedFunction() system call */
StatusType Os_SystemCallCallTrustedFunction(TrustedFunctionIndexType FunctionIndex, TrustedFunctionParameterRefType FunctionParams)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)FunctionIndex, (uint32)FunctionParams, (uint32)0, (uint32)Os_KernCallTrustedFunction);
  }
  else
  {
    LddStatusReturn = Os_KernCallTrustedFunction(FunctionIndex, FunctionParams);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* (OS_TRUSTED_FUNC_COUNT != OS_ZERO) */

/* function for CheckISRMemoryAccess() system call */
AccessType Os_SystemCallCheckISRMemoryAccess(ISRType IsrID, MemoryStartAddressType Address, MemorySizeType Size)
{
  Os_OldLevel_T LddOldIntVal;
  AccessType LddAccessReturn = NO_ACCESS;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddAccessReturn = (AccessType)Os_CallFuncKernelStack((uint32)IsrID, (uint32)Address, (uint32)Size, (uint32)Os_KernCheckISRMemoryAccess);
  }
  else
  {
    LddAccessReturn = Os_KernCheckISRMemoryAccess(IsrID, Address, Size);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddAccessReturn;
}

/* function for CheckTaskMemoryAccess() system call */
AccessType Os_SystemCallCheckTaskMemoryAccess(TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
{
  Os_OldLevel_T LddOldIntVal;
  AccessType LddAccessReturn = NO_ACCESS;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddAccessReturn = (AccessType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)Address, (uint32)Size, (uint32)Os_KernCheckTaskMemoryAccess);
  }
  else
  {
    LddAccessReturn = Os_KernCheckTaskMemoryAccess(TaskID, Address, Size);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddAccessReturn;
}
#endif /* (OS_MEMORY_PROTECTION == STD_ON) */

#if (OS_COUNTER == STD_ON)
/* function for IncrementCounter() system call */
StatusType Os_SystemCallIncrementCounter(CounterType CounterID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)CounterID, (uint32)0, (uint32)0, (uint32)Os_KernIncrementCounter);
  }
  else
  {
    LddStatusReturn = Os_KernIncrementCounter(CounterID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetCounterValue() system call */
StatusType Os_SystemCallGetCounterValue(CounterType CounterID, TickRefType Value)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)CounterID, (uint32)Value, (uint32)0, (uint32)Os_KernGetCounterValue);
  }
  else
  {
    LddStatusReturn = Os_KernGetCounterValue(CounterID, Value);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetElapsedValue() system call */
StatusType Os_SystemCallGetElapsedValue(CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)CounterID, (uint32)Value, (uint32)ElapsedValue, (uint32)Os_KernGetElapsedValue);
  }
  else
  {
    LddStatusReturn = Os_KernGetElapsedValue(CounterID, Value, ElapsedValue);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* (OS_COUNTER == STD_ON) */

#if (OS_EVENT == STD_ON)
/* function for SetEvent() system call */
StatusType Os_SystemCallSetEvent(TaskType TaskID, EventMaskType Mask)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)Mask, (uint32)0, (uint32)Os_KernSetEvent);
  }
  else
  {
    LddStatusReturn = Os_KernSetEvent(TaskID, Mask);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for ClearEvent() system call */
StatusType Os_SystemCallClearEvent(EventMaskType Mask)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)Mask, (uint32)0, (uint32)0, (uint32)Os_KernClearEvent);
  }
  else
  {
    LddStatusReturn = Os_KernClearEvent(Mask);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetEvent() system call */
StatusType Os_SystemCallGetEvent(TaskType TaskID, EventMaskRefType Event)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)Event, (uint32)0, (uint32)Os_KernGetEvent);
  }
  else
  {
    LddStatusReturn = Os_KernGetEvent(TaskID, Event);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for WaitEvent() system call */
StatusType Os_SystemCallWaitEvent(EventMaskType Mask)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)Mask, (uint32)0, (uint32)0, (uint32)Os_KernWaitEvent);
  }
  else
  {
    LddStatusReturn = Os_KernWaitEvent(Mask);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /*(OS_EVENT == STD_ON) */

#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
/* function for GetISRID() system call */
ISRType Os_SystemCallGetISRID(void)
{
  Os_OldLevel_T LddOldIntVal;
  ISRType LddIsrId = INVALID_ISR;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddIsrId = Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernGetISRID);
  }
  else
  {
    LddIsrId = Os_KernGetISRID();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddIsrId;
}
#endif

#if (OS_SPINLOCK == STD_ON)
/* function for ReleaseSpinlock() system call */
StatusType Os_SystemCallReleaseSpinlock(SpinlockIdType SpinlockId)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)SpinlockId, (uint32)0, (uint32)0, (uint32)Os_KernReleaseSpinlock);
  }
  else
  {
    LddStatusReturn = Os_KernReleaseSpinlock(SpinlockId);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for TryToGetSpinlock() system call */
StatusType Os_SystemCallTryToGetSpinlock(SpinlockIdType SpinlockId,  P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)SpinlockId, (uint32)Success, (uint32)0, (uint32)Os_KernTryToGetSpinlock);
  }
  else
  {
    LddStatusReturn = Os_KernTryToGetSpinlock(SpinlockId, Success);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* End of if (OS_SPINLOCK == STD_ON) */

#if (OS_MULTICORE == STD_ON)
/* function for ShutdownAllCores() system call */
void Os_SystemCallShutdownAllCores(StatusType Error)
{
  Os_OldLevel_T LddOldIntVal;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    (void)Os_CallFuncKernelStack((uint32)Error, (uint32)0, (uint32)0, (uint32)Os_KernShutdownAllCores);
  }
  else
  {
    Os_KernShutdownAllCores(Error);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

/* function for GetActiveApplicationMode() system call */
AppModeType Os_SystemCallGetActiveApplicationMode(void)
{
  Os_OldLevel_T LddOldIntVal;
  AppModeType LddApplicationMode = OSDEFAULTAPPMODE;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddApplicationMode = Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernGetActiveApplicationMode);
  }
  else
  {
    LddApplicationMode = Os_KernGetActiveApplicationMode();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddApplicationMode;
}

/* function for StartOS() system call */
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
void Os_SystemCallStartOS(AppModeType Mode)
{
  Os_OldLevel_T LddOldIntVal;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    (void)Os_CallFuncKernelStack((uint32)Mode, (uint32)0, (uint32)0, (uint32)Os_KernStartOS);
  }
  else
  {
    Os_KernStartOS(Mode);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);
}

/* function for ShutdownOS() system call */
void Os_SystemCallShutdownOS(StatusType Error)
{
  Os_OldLevel_T LddOldIntVal;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    (void)Os_CallFuncKernelStack((uint32)Error, (uint32)0, (uint32)0, (uint32)Os_KernShutdownOS);
  }
  else
  {
    Os_KernShutdownOS(Error);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);
}

#if (OS_RESOURCE == STD_ON)
/* function for GetResource() system call */
StatusType Os_SystemCallGetResource(ResourceType ResID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ResID, (uint32)0, (uint32)0, (uint32)Os_KernGetResource);
  }
  else
  {
    LddStatusReturn = Os_KernGetResource(ResID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for ReleaseResource() system call */
StatusType Os_SystemCallReleaseResource(ResourceType ResID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ResID, (uint32)0, (uint32)0, (uint32)Os_KernReleaseResource);
  }
  else
  {
    LddStatusReturn = Os_KernReleaseResource(ResID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* (OS_RESOURCE == STD_ON) */

#if (OS_SCHEDTABLE == STD_ON)
/* function for StartScheduleTableRel() system call */
StatusType Os_SystemCallStartScheduleTableRel(ScheduleTableType ScheduleTableID, TickType Offset)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)Offset, (uint32)0, (uint32)Os_KernStartScheduleTableRel);
  }
  else
  {
    LddStatusReturn = Os_KernStartScheduleTableRel(ScheduleTableID, Offset);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for StartScheduleTableAbs() system call */
StatusType Os_SystemCallStartScheduleTableAbs(ScheduleTableType ScheduleTableID, TickType Start)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)Start, (uint32)0, (uint32)Os_KernStartScheduleTableAbs);
  }
  else
  {
    LddStatusReturn = Os_KernStartScheduleTableAbs(ScheduleTableID, Start);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for StopScheduleTable() system call */
StatusType Os_SystemCallStopScheduleTable(ScheduleTableType ScheduleTableID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)0, (uint32)0, (uint32)Os_KernStopScheduleTable);
  }
  else
  {
    LddStatusReturn = Os_KernStopScheduleTable(ScheduleTableID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for NextScheduleTable() system call */
StatusType Os_SystemCallNextScheduleTable(ScheduleTableType ScheduleTableID_From, ScheduleTableType ScheduleTableID_To)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID_From, (uint32)ScheduleTableID_To, (uint32)0, (uint32)Os_KernNextScheduleTable);
  }
  else
  {
    LddStatusReturn = Os_KernNextScheduleTable(ScheduleTableID_From, ScheduleTableID_To);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)
/* function for StartScheduleTableSynchron() system call */
StatusType Os_SystemCallStartScheduleTableSynchron(ScheduleTableType ScheduleTableID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)0, (uint32)0, (uint32)Os_KernStartScheduleTableSynchron);
  }
  else
  {
    LddStatusReturn = Os_KernStartScheduleTableSynchron(ScheduleTableID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for SyncScheduleTable() system call */
StatusType Os_SystemCallSyncScheduleTable(ScheduleTableType ScheduleTableID, TickType Value)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)Value, (uint32)0, (uint32)Os_KernSyncScheduleTable);
  }
  else
  {
    LddStatusReturn = Os_KernSyncScheduleTable(ScheduleTableID, Value);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for SetScheduleTableAsync() system call */
StatusType Os_SystemCallSetScheduleTableAsync(ScheduleTableType ScheduleTableID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)0, (uint32)0, (uint32)Os_KernSetScheduleTableAsync);
  }
  else
  {
    LddStatusReturn = Os_KernSetScheduleTableAsync(ScheduleTableID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */

/* function for GetScheduleTableStatus() system call */
StatusType Os_SystemCallGetScheduleTableStatus(ScheduleTableType ScheduleTableID,  ScheduleTableStatusRefType ScheduleStatus)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)ScheduleTableID, (uint32)ScheduleStatus, (uint32)0, (uint32)Os_KernGetScheduleTableStatus);
  }
  else
  {
    LddStatusReturn = Os_KernGetScheduleTableStatus(ScheduleTableID, ScheduleStatus);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#if (OS_TASK == STD_ON)
/* function for ActivateTask() system call */
StatusType Os_SystemCallActivateTask(TaskType TaskID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)0, (uint32)0, (uint32)Os_KernActivateTask);
  }
  else
  {
    LddStatusReturn = Os_KernActivateTask(TaskID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for TerminateTask() system call */
StatusType Os_SystemCallTerminateTask(void)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernTerminateTask);
  }
  else
  {
    LddStatusReturn = Os_KernTerminateTask();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for ChainTask() system call */
StatusType Os_SystemCallChainTask(TaskType TaskID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)0, (uint32)0, (uint32)Os_KernChainTask);
  }
  else
  {
    LddStatusReturn = Os_KernChainTask(TaskID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for Schedule() system call */
StatusType Os_SystemCallSchedule(void)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernSchedule);
  }
  else
  {
    LddStatusReturn = Os_KernSchedule();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetTaskID() system call */
StatusType Os_SystemCallGetTaskID(TaskRefType TaskID)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)0, (uint32)0, (uint32)Os_KernGetTaskID);
  }
  else
  {
    LddStatusReturn = Os_KernGetTaskID(TaskID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for GetTaskState() system call */
StatusType Os_SystemCallGetTaskState(TaskType TaskID, TaskStateRefType State)
{
  Os_OldLevel_T LddOldIntVal;
  StatusType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)TaskID, (uint32)State, (uint32)0, (uint32)Os_KernGetTaskState);
  }
  else
  {
    LddStatusReturn = Os_KernGetTaskState(TaskID, State);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}
#endif /* (OS_TASK == STD_ON) */

#if (OS_MULTICORE == STD_ON)
/* function for GetCoreID() system call */
CoreIdType Os_SystemCallGetCoreID(void)
{
  Os_OldLevel_T LddOldIntVal;
  CoreIdType LddCoreID = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddCoreID = (StatusType)Os_CallFuncKernelStack((uint32)0, (uint32)0, (uint32)0, (uint32)Os_KernGetCoreID);
  }
  else
  {
    LddCoreID = Os_KernGetCoreID();
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddCoreID;
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

#if (OS_APPLICATION == STD_ON)
/* function for IocRead() system call */
Std_ReturnType Os_SystemCallIocRead(uint32 IocID, P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
{
  Os_OldLevel_T LddOldIntVal;
  Std_ReturnType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)IocID, (uint32)data, (uint32)0, (uint32)Os_KernIocRead);
  }
  else
  {
    LddStatusReturn = Os_KernIocRead(IocID, data);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for IocWrite() system call */
Std_ReturnType Os_SystemCallIocWrite(uint32 IocID, CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  Os_OldLevel_T LddOldIntVal;
  Std_ReturnType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)IocID, (uint32)data, (uint32)0, (uint32)Os_KernIocWrite);
  }
  else
  {
    LddStatusReturn = Os_KernIocWrite(IocID, data);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for IocReceive() system call */
Std_ReturnType Os_SystemCallIocReceive(uint32 IocID, P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
{
  Os_OldLevel_T LddOldIntVal;
  Std_ReturnType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)IocID, (uint32)data, (uint32)0, (uint32)Os_KernIocReceive);
  }
  else
  {
    LddStatusReturn = Os_KernIocReceive(IocID, data);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for IocSend() system call */
Std_ReturnType Os_SystemCallIocSend(uint32 IocID, CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  Os_OldLevel_T LddOldIntVal;
  Std_ReturnType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)IocID, (uint32)data, (uint32)0, (uint32)Os_KernIocSend);
  }
  else
  {
    LddStatusReturn = Os_KernIocSend(IocID, data);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for IocEmptyQueue() system call */
Std_ReturnType Os_SystemCallIocEmptyQueue(uint32 IocID)
{
  Os_OldLevel_T LddOldIntVal;
  Std_ReturnType LddStatusReturn = E_OK;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    LddStatusReturn = (StatusType)Os_CallFuncKernelStack((uint32)IocID, (uint32)0, (uint32)0, (uint32)Os_KernIocEmptyQueue);
  }
  else
  {
    LddStatusReturn = Os_KernIocEmptyQueue(IocID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);

  return LddStatusReturn;
}

/* function for IocPullCB() system call */
void Os_SystemCallIocPullCB(P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID)
{
  Os_OldLevel_T LddOldIntVal;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  LddOldIntVal = OS_DISABLE_AND_SAVE_INTERRUPTS();
  Os_GucInKernel[OS_CORE_ID]++;
  if((Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO) && (Os_GucInKernel[OS_CORE_ID] == OS_ZERO))
  {
    (void)Os_CallFuncKernelStack((uint32)pIocPullCB, (uint32)recvAppID, (uint32)0, (uint32)Os_KernIocPullCB);
  }
  else
  {
    Os_KernIocPullCB(pIocPullCB, recvAppID);
  }
  Os_GucInKernel[OS_CORE_ID]--;
  OS_RESTORE_INTERRUPTS(LddOldIntVal);
}
#endif /* (OS_APPLICATION == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-end MISRA-C3:11.1 */
/* polyspace-end MISRA-C3:11.4 */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To meet system call interface */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
