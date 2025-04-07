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
**  SRC-MODULE: Os_Alarm.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Alarm functionality.                             **
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
** 2.6.12    16-May-2022    JC.Kim        Redmine #35626                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #23813, #21784              **
** 2.6.2     13-Apr-2020    MJ.Woo        Redmine #22921                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     21-Mar-2019    SH.Yoo        Redmine #16633                      **
** 2.5.0     25-Jun-2018    SH.Yoo        Redmine #12780, #13008, #13150      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025, #12103, #12132      **
** 2.4.2     13-Mar-2018    MJ.Woo        Redmine #7001                       **
** 2.4.1     14-Sep-2017    MJ.Woo        Redmine #9937                       **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.12    14-Apr-2016    SH.Yoo        Redmine #4651                       **
** 2.0.11    16-Feb-2016    JH.Lee,MJ.Woo Redmine #3963                       **
** 2.0.9     13-Jul-2015    SH.Yoo        Redmine #2849                       **
**           10-Dec-2014    MJ.Woo        Redmine #494, #1189                 **
** 2.0.5     13-Dec-2013    MJ.Woo        CR: xar~212, TASK: xar~796          **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                                        CR: xar~179, TASK: xar~736          **
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
/* polyspace:begin<RTE : OBAI :Not a defect:Justify with annotations > configured array index */
/* polyspace-begin MISRA-C3:D4.14 [Not a defect:Medium] "Not received from external source" */
/* polyspace-begin MISRA-C3:8.7 [Not a defect:Low] "External visible functions" */
/* polyspace-begin MISRA-C3:11.3 [Justified:Medium] "To specify alarm action from undefined state, typecast to different point type is needed." */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */
#include "Os_Alarm.h"             /* Os Alarm header file */
#include "Os_Task.h"              /* Os Task header file */
#include "Os_Counter.h"           /* Os Counter header file */
#include "Os_Event.h"             /* Os Event header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Definition.h"        /* Os Definition header file */
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

/***************************************************************************//**
 * Function Name        : Os_DoGetAlarmBase
 *
 * Service ID           : NA
 *
 * Description          : This service is used to read
 *                        the alarm base characteristics. The return value
 *                        <Info> is a structure in which the information
 *                        of data type AlarmBaseType is stored.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [out]           Info          Reference to structure of the alarm base
 * @param [in]            LblRemoteCall Call from another Core
 *                                      (range : OS_TRUE, OS_FALSE)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_ACCESS : Alarm is not accessible
 *
 * @pre                 : AlarmID should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticAlarm
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_DoGetAlarmBase(AlarmType AlarmID,
                                   AlarmBaseRefType Info, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  StatusType LenStatusReturn = E_OK;

  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, AlarmID,
                                                                 LblRemoteCall);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get the pointer to static counter structure */
  LpStaticCounter = (&Os_GaaStaticAlarm[AlarmID])->pStaticCounter;
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  if (LpStaticCounter->pHwCounter != NULL_PTR)
  {
    Info->ticksperbase = LpStaticCounter->pHwCounter->ddTicksPerBase;
  }
  else
  {
    Info->ticksperbase = OS_ONE;
  }
  /* polyspace:end<MISRA-C3:18.1> */
  Info->maxallowedvalue = LpStaticCounter->ddMaxAllowedValue;
  Info->mincycle = LpStaticCounter->ddMinCycle;
  return LenStatusReturn;
}
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernGetAlarmBase
 *
 * Service ID           : NA
 *
 * Description          : This service is used to read
 *                        the alarm base characteristics. The return value
 *                        <Info> is a structure in which the information
 *                        of data type AlarmBaseType is stored.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [out]           Info          Reference to structure of the alarm base
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : AlarmID is invalid
 *                        - E_OS_PARAM_POINTER : Info is a NULL_PTR
 *                        - E_OS_ACCESS : Alarm is not accessible
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_DoGetAlarmBase(), Os_SendGetAlarmBase()
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE)
Os_KernGetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETALARMBASE, LenStatusReturn);
  /* Check whether AlarmID is greater than number of Alarm count */
  OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Info, LenStatusReturn);
  /* Check whether Alarm can access the Application */
  OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, AlarmID);
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Check if new task belongs to same core */
    if (Os_GaaStaticAlarm[AlarmID].ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendActivateTask to schedule task on respective core */
      LenStatusReturn = Os_SendGetAlarmBase(AlarmID, Info);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Call Os_DoGetAlarmBase*/
      LenStatusReturn = Os_DoGetAlarmBase(AlarmID, Info, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Store the service ID of GetAlarmBase */
    OS_STORE_SERVICE(OSServiceId_GetAlarmBase);
    /* Store the parameter 1 - AlarmID */
    OS_STORE_PARAM1_ALARMID(AlarmID);
    /* Store the parameter 2 - Info */
    OS_STORE_PARAM2_INFO(Info);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
} /* End of GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info) */
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernGetAlarm
 *
 * Service ID           : NA
 *
 * Description          : The system service GetAlarm returns the relative
 *                        value in ticks before the alarm  expires.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [out]           Tick          Relative value in ticks before the alarm
 *                                      <AlarmID> expires.
 *                                      (range : 0 ~ MaxAllowdValue of Counter)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : AlarmID is invalid
 *                        - E_OS_PARAM_POINTER : Tick is a NULL_PTR
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_NOFUNC : Alarm is not used
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_SendGetAlarm(), Os_DoGetAlarm()
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernGetAlarm(AlarmType AlarmID, TickRefType Tick)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(GETALARM, LenStatusReturn);
  /* Check whether AlarmID is greater than number of Alarm count */
  OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Tick, LenStatusReturn);
  /* Check whether Alarm can access the Application */
  OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, AlarmID);
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* Check if Alarm belongs to same core */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpAlarm->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendGetAlarm to get remain alarm ticks on respective core */
      LenStatusReturn = Os_SendGetAlarm(AlarmID, Tick);
    } /* End of if (LpAlarm->ddCoreId != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoGetAlarm and get the return value */
      LenStatusReturn = Os_DoGetAlarm(AlarmID, Tick, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service ID of GetAlarm */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    OS_STORE_SERVICE(OSServiceId_GetAlarm);
    /* Store the parameter 1 - AlarmID */
    OS_STORE_PARAM1_ALARMID(AlarmID);
    /* Store the parameter 2 - Tick */
    OS_STORE_PARAM2_TICK(Tick);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
} /* End of GetAlarm(AlarmType AlarmID, TickRefType Tick) */
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernSetRelAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set the relative alarm.
 *                        After <increment> ticks have elapsed, the task
 *                        assigned to the alarm <AlarmID> is activated
 *                        or the assigned event (only for extended tasks)
 *                        is set or the alarm-callback routine is called.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            AlarmID    Reference to an alarm
 *                                   (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [in]            Increment  Relative value in ticks
 *                                   (range : 1 ~ MaxAllowdValue of Counter)
 * @param [in]            Cycle      Cycle value in case of cyclic alarm. In
 *                                   case of single alarms, cycle shall be zero.
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : AlarmID is invalid
 *                        - E_OS_VALUE : Increment or Cycle is invalid
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_STATE : Alarm is already in use
 *                        - E_OS_SYS_ALARMINUSE : Counter interrupt is nested
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_SendSetRelAlarm(), Os_DoSetRelAlarm()
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSetRelAlarm(AlarmType AlarmID,
                                             TickType Increment, TickType Cycle)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SETRELALARM, LenStatusReturn);
  /* Check whether AlarmID is greater than number of Alarm count */
  OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn);
  /* Check if increment is within the range of the
   *   maximum allowed value for the counter used by the alarm */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(AlarmID, Increment, LenStatusReturn);
  /* Check if cycle is greater than minimum value*/
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_ALARM_MIN_CYCLE_ERROR(AlarmID, Cycle, LenStatusReturn);
  /* Check whether Alarm can access the Application */
  OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, AlarmID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* Check if Alarm belongs to same core */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpAlarm->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendSetRelAlarm to set relative alarm on respective core */
      LenStatusReturn = Os_SendSetRelAlarm(AlarmID, Increment, Cycle);
    } /* End of if (LpAlarm->ddCoreId != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoSetRelAlarm and get the return value */
      LenStatusReturn = Os_DoSetRelAlarm(AlarmID, Increment, Cycle, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service Id of SetRelAlarm */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    OS_STORE_SERVICE(OSServiceId_SetRelAlarm);
    /* Store the parameter 1 - AlarmID */
    OS_STORE_PARAM1_ALARMID(AlarmID);
    /* Store the parameter 2 - Increment */
    OS_STORE_PARAM2_INCREMENT(Increment);
    /* Store the parameter 3 - Cycle */
    OS_STORE_PARAM3_CYCLE(Cycle);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
} /* End of SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
   **/
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernSetAbsAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set the absolute alarm.
 *                        When <start> ticks are reached, the configured
 *                        action takes place.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            AlarmID    Reference to an alarm
 *                                   (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [in]            Start      Absolute value in ticks
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 * @param [in]            Cycle      Cycle value in case of cyclic alarm. In
 *                                   case of single alarms, cycle shall be zero.
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : AlarmID is invalid
 *                        - E_OS_VALUE : Start or Cycle is invalid
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_STATE : Alarm is already in use
 *                        - E_OS_SYS_ALARMINUSE : Counter interrupt is nested
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_SendSetAbsAlarm(), Os_DoSetAbsAlarm()
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernSetAbsAlarm(AlarmType AlarmID, TickType Start,
                                                                 TickType Cycle)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SETABSALARM, LenStatusReturn);
  /* Check whether AlarmID is greater than number of Alarm count */
  OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn);
  /* Check if start is within the range of the maximum
   *   allowed value for the counter used by the alarm */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_ALARM_MAX_ALLOWED_ABS_VALUE_ERROR(AlarmID, Start, LenStatusReturn);
  /* Check if cycle is greater than minimum value*/
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  OS_CHECK_ALARM_MIN_CYCLE_ERROR(AlarmID, Cycle, LenStatusReturn);
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Check whether Alarm can access the Application */
  OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, AlarmID);

  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* Check if Alarm belongs to same core */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpAlarm->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendSetAbsAlarm to set absolute alarm on respective core */
      LenStatusReturn = Os_SendSetAbsAlarm(AlarmID, Start, Cycle);
    } /* End of if (LpAlarm->ddCoreId != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoSetAbsAlarm and get the return value */
      LenStatusReturn = Os_DoSetAbsAlarm(AlarmID, Start, Cycle, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service Id of SetAbsAlarm */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    OS_STORE_SERVICE(OSServiceId_SetAbsAlarm);
    /* Store the parameter 1 - AlarmID */
    OS_STORE_PARAM1_ALARMID(AlarmID);
    /* Store the parameter 2 - Start */
    OS_STORE_PARAM2_TICKSTART(Start);
    /* Store the parameter 3 - Cycle */
    OS_STORE_PARAM3_CYCLE(Cycle);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
} /* End of SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle) */
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_KernCancelAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to cancel the alarm
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : AlarmID is invalid
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_NOFUNC : Alarm is already Sleep
 *                        - E_OS_SYS_ALARMINUSE : Counter interrupt is nested
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_SendCancelAlarm(), Os_DoCancelAlarm()
 ******************************************************************************/
#if (OS_ALARM == STD_ON)
FUNC(StatusType, OS_CODE) Os_KernCancelAlarm(AlarmType AlarmID)
{
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Set the return status value to "E_OK" */
  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(CANCELALARM, LenStatusReturn);
  /* Check whether AlarmID is greater than number of Alarm count */
  OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn);
  /* Check whether Alarm can access the Application */
  OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(&LenStatusReturn, AlarmID);
  /* Check whether status return is E_OK */
  if (LenStatusReturn == E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* Check if Alarm belongs to same core */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpAlarm->ddCoreId != OS_CORE_ID)
    {
      /* Call Os_SendCancelAlarm to cancel alarm on respective core */
      LenStatusReturn = Os_SendCancelAlarm(AlarmID);
    } /* End of if (LpAlarm->ddCoreId != OS_CORE_ID) */
    else
    #endif
    {
      /* Call Os_DoCancelAlarm and get the return value */
      LenStatusReturn = Os_DoCancelAlarm(AlarmID, OS_FALSE);
    }
  } /* End of if (LenStatusReturn == E_OK) */
  #if (OS_STATUS == EXTENDED)
  if (LenStatusReturn != E_OK)
  {
    /* Store the service Id of CancelAlarm */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    OS_STORE_SERVICE(OSServiceId_CancelAlarm);
    /* Store the parameter 1 - AlarmID */
    OS_STORE_PARAM1_ALARMID(AlarmID);
    /* Call Error Hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_STATUS == EXTENDED) */
  /* Return the value */
  return (LenStatusReturn);
} /* End of CancelAlarm(AlarmType AlarmID) */
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_InsertAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to insert a alarm
 *                        object in the alarm object queue of
 *                        the counter it belongs to.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpAlarm    Pointer to an alarm object
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
FUNC(void, OS_CODE) Os_InsertAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC,
                                                                OS_VAR) LpAlarm)
{
  P2VAR(Tdd_Os_Counter, AUTOMATIC, OS_VAR) LpCounter;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpCurAlarm;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpPrevAlarm;

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get the pointer to counter */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  LpCounter = LpAlarm->pStaticAlarm->pCounter;
  /* Pointer to alarm object */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  LpCurAlarm = LpCounter->pHeadAlarm;
  /* Pointer to previous alarm */
  LpPrevAlarm = NULL_PTR;

  while ((LpCurAlarm != NULL_PTR) &&
                        ((LpCounter->ddCurrentCount == LpCurAlarm->ddAbsCount)))
  {
    /* Set the current alarm to previous alarm  */
    LpPrevAlarm = LpCurAlarm;
    /* Get the next entry to current alarm */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
    LpCurAlarm = LpCurAlarm->pNextAlarm;
  }

  if (LpAlarm->ddAbsCount <= LpCounter->ddCurrentCount)
  {
    while ((LpCurAlarm != NULL_PTR) &&
                         ((LpCounter->ddCurrentCount < LpCurAlarm->ddAbsCount)))
    {
      /* Set the current alarm to previous alarm  */
      LpPrevAlarm = LpCurAlarm;
      /* Get the next entry to current alarm */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LpCurAlarm = LpCurAlarm->pNextAlarm;
    }
    while ((LpCurAlarm != NULL_PTR) &&
                              ((LpCurAlarm->ddAbsCount <= LpAlarm->ddAbsCount)))
    {
      /* Set the current alarm to previous alarm  */
      LpPrevAlarm = LpCurAlarm;
      /* Get the next entry to current alarm */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LpCurAlarm = LpCurAlarm->pNextAlarm;
    }
  } /* End of if (LpAlarm->ddAbsCount <= LpCounter->ddCurrentCount) */
  else
  {
    while ((LpCurAlarm != NULL_PTR) &&
                             ((LpCurAlarm->ddAbsCount <= LpAlarm->ddAbsCount) &&
                          (LpCurAlarm->ddAbsCount > LpCounter->ddCurrentCount)))
    {
      /* Set the current alarm to previous alarm  */
      LpPrevAlarm = LpCurAlarm;
      /* Get the next entry to current alarm */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      LpCurAlarm = LpCurAlarm->pNextAlarm;
    }
  } /* End of else */

  /* Insert the Alarm and update the link list */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
  LpAlarm->pNextAlarm = LpCurAlarm;
  LpAlarm->pPrevAlarm = LpPrevAlarm;

  /* Check whether it reaches to end of the queue */
  if (LpCurAlarm != NULL_PTR)
  {
    /* Update the link list */
    LpCurAlarm->pPrevAlarm = LpAlarm;
  }

  /* Check whether previous alarm is equal to null pointer */
  if (LpPrevAlarm != NULL_PTR)
  {
    /* Add at the end of the queue or insert */
    LpPrevAlarm->pNextAlarm = LpAlarm;
  }
  else
  {
    /* Alarm have to be inserted at the head of the queue */
    LpCounter->pHeadAlarm = LpAlarm;
  }
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_InsertAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR)
   *LpAlarm) */
#endif /* End of if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_RemoveAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to remove an alarm
 *                        from the alarm queue of the counter
 *                        it belongs to.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LpAlarm    Pointer to an alarm object
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
FUNC(void, OS_CODE) Os_RemoveAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC,
                                                                OS_VAR) LpAlarm)
{
  P2VAR(Tdd_Os_Counter, AUTOMATIC, OS_VAR) LpCounter;

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Get the pointer to counter */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  LpCounter = LpAlarm->pStaticAlarm->pCounter;

  /* Adjust the head of the queue if the removed alarm is at the head */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  if (LpAlarm == LpCounter->pHeadAlarm)
  {
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpCounter->pHeadAlarm = LpAlarm->pNextAlarm;
  }

  /* Build the link between the previous and next alarm in the queue */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  if (LpAlarm->pNextAlarm != NULL_PTR)
  {
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpAlarm->pNextAlarm->pPrevAlarm = LpAlarm->pPrevAlarm;
  }
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  if (LpAlarm->pPrevAlarm != NULL_PTR)
  {
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpAlarm->pPrevAlarm->pNextAlarm = LpAlarm->pNextAlarm;
  }
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_RemoveAlarm(P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR)
   *LpAlarm) */
#endif /* End of if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_RemoveAlarmSet
 *
 * Service ID           : NA
 *
 * Description          : This service is used to remove all alarm
 *                        from the alarm queue of the counter
 *                        it belongs to.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LpCounter    Pointer to a counter structure
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                                    None
 *
 *                        Function(s) invoked    :
 *                                    None
 ******************************************************************************/
#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
FUNC(void, OS_CODE) Os_RemoveAlarmSet(P2VAR(Tdd_Os_Counter, AUTOMATIC,
                                                              OS_VAR) LpCounter)
{
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpLastAlarm;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  TickType LddCurrentAbsCount;

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Take the head in LpAlarm */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  LpAlarm = LpCounter->pHeadAlarm;
  /* Take the count of alarm in local */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  LddCurrentAbsCount = LpCounter->pHeadAlarm->ddAbsCount;

  /* Loop through all the alarms set at the same time */
  do
  {
    LpLastAlarm = LpAlarm;
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpAlarm = LpAlarm->pNextAlarm;
  } while ((LpAlarm != NULL_PTR) &&
                                  (LpAlarm->ddAbsCount == LddCurrentAbsCount));

  /* Update the head */
  LpCounter->pHeadAlarm = LpAlarm;

  if (LpAlarm != NULL_PTR)
  {
    /* Update the previous as NULL for Head */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpCounter->pHeadAlarm->pPrevAlarm = NULL_PTR;
  }
  LpLastAlarm->pNextAlarm = NULL_PTR;
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_RemoveAlarmSet(P2VAR(Tdd_Os_Counter, AUTOMATIC, OS_VAR)
   *LpCounter) */
#endif /* End of if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_AlarmActivateTask
 *
 * Service ID           : NA
 *
 * Description          : This service is used to activate the task on the
 *                        expiry of the alarm.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             LpAction    Pointer to action which takes place on
 *                                    expiry of alarm
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_ACCESS : Task is not accessible
 *                        - E_OS_LIMIT : Too many task activations
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_SendActivateTask(), Os_DoActivateTask()
 ******************************************************************************/
#if (((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) && (OS_TASK == STD_ON))
FUNC(StatusType, OS_CODE) Os_AlarmActivateTask(P2CONST(
                           Tdd_Os_ActivateTask, AUTOMATIC, OS_CONST) LpAction)
{
  P2CONST(Tdd_Os_ActivateTask, AUTOMATIC, OS_CONST) LpActivateTask;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if (OS_ERROR_HOOK == STD_ON)
  TaskType TaskID;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Pointer to action object is typecasted with the task to be activated */
  LpActivateTask = (P2CONST(Tdd_Os_ActivateTask, AUTOMATIC, OS_CONST))LpAction;
  #if (OS_MULTICORE == STD_ON)
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  if (LpActivateTask->pStaticTask->ddCoreId != OS_CORE_ID)
  {
    /* Call Os_SendActivateTask to schedule task on respective core */
    LenStatusReturn =Os_SendActivateTask(LpActivateTask->pStaticTask->ddTaskId);
  }
  else
  #endif /* End of if (OS_MULTICORE == STD_ON) */
  {
    /* polyspace:begin<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
    /* Call Os_DoActivateTask and get the return value */
    LenStatusReturn = Os_DoActivateTask(LpActivateTask->pStaticTask->ddTaskId,\
                                                                      OS_FALSE);
    /* polyspace:end<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
  }
  #if (OS_ERROR_HOOK == STD_ON)
  if (LenStatusReturn != E_OK)
  {
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    TaskID = LpActivateTask->pStaticTask->ddTaskId;
    /* Store the service ID of ActivateTask */
    OS_STORE_SERVICE(OSServiceId_ActivateTask);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of if (LenStatusReturn != E_OK) */
  #endif /* End of if (OS_ERROR_HOOK == STD_ON) */
  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_AlarmActivateTask(P2CONST(Tdd_Os_ActivateTask, AUTOMATIC,
   * OS_CONST) LpAction) */
#endif /* End of if (((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) &&
        *(OS_TASK == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_AlarmSetEvent
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set an event
 *                        on the expiry of the alarm.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             LpAction    Pointer to action which takes place on
 *                                    expiry of alarm
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_ACCESS : Referenced task is not accessible
 *                        - E_OS_STATE : Referenced task is in suspended state
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_SendSetEvent(), Os_DoSetEvent()
 ******************************************************************************/
#if (((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) && (OS_EVENT ==\
                                                             STD_ON))
FUNC(StatusType, OS_CODE) Os_AlarmSetEvent(P2CONST(
                           Tdd_Os_AlarmEvent, AUTOMATIC, OS_CONST) LpAction)
{
  P2CONST(Tdd_Os_AlarmEvent, AUTOMATIC, OS_CONST) LpSetEvent;
  StatusType LenStatusReturn;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if (OS_ERROR_HOOK == STD_ON)
  TaskType TaskID;
  EventMaskType Mask;
  #endif
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* Type cast the object with set event structure */
  LpSetEvent = (P2CONST(Tdd_Os_AlarmEvent, AUTOMATIC, OS_CONST))LpAction;
  #if (OS_MULTICORE == STD_ON)
  /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
  if (LpSetEvent->pStaticTask->ddCoreId != OS_CORE_ID)
  {
    /* Call Os_SendSetEvent to schedule task on respective core */
    LenStatusReturn = Os_SendSetEvent(LpSetEvent->pStaticTask,
                                      LpSetEvent->ddEventMask);
  }
  else
  #endif /* End of if (OS_MULTICORE == STD_ON) */
  {
    /* Call Os_DoSetEvent and get the return value */
    /* polyspace +2 RTE:NIP [Justified:Medium] "ptr points to a valid value and code is verified manually" */
    LenStatusReturn = Os_DoSetEvent(LpSetEvent->pStaticTask->ddTaskId,
                                    LpSetEvent->ddEventMask,
                                    OS_FALSE);
  }
  #if (OS_ERROR_HOOK == STD_ON)
  if (LenStatusReturn != E_OK)
  {
    /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually*/
    TaskID = LpSetEvent->pStaticTask->ddTaskId;
    Mask = LpSetEvent->ddEventMask;
    /* Store the service ID of SetEvent */
    OS_STORE_SERVICE(OSServiceId_SetEvent);
    /* Store the parameter 1 - TaskID */
    OS_STORE_PARAM1_TASKID(TaskID);
    /* Store the parameter 2 - Mask */
    OS_STORE_PARAM2_MASK(Mask);
    /* Report an error to error hook */
    OS_PROCESS_ERROR(LenStatusReturn);
  } /* End of else */
  #endif /* End of if (OS_ERROR_HOOK == STD_ON) */
  /* Return the value */
  return (LenStatusReturn);
  /* polyspace:end<MISRA-C3:18.1> */
} /* End of Os_AlarmSetEvent(P2CONST(Tdd_Os_AlarmEvent, AUTOMATIC,
   *OS_CONST) LpAction) */
#endif /* End of if (((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)) &&
        *(OS_EVENT == STD_ON)) */

/***************************************************************************//**
 * Function Name        : Os_AlarmCallback
 *
 * Service ID           : NA
 *
 * Description          : This service is used for callback function
 *                        on the expiry of the alarm.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             LpAction    Pointer to action which takes place on
 *                                    expiry of alarm
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        pAlarmCallBack()
 ******************************************************************************/
#if (OS_CALLBACK_COUNT > OS_PRE_ZERO)
FUNC(StatusType, OS_CODE) Os_AlarmCallback(P2CONST(
                           Tdd_Os_AlarmCallback, AUTOMATIC, OS_CONST) LpAction)
{
  P2CONST(Tdd_Os_AlarmCallback, AUTOMATIC, OS_CONST) LpAlarmCallback;
  Os_Sint_T LsiGlobalIE;

  /* Type cast the object with alarm call back structure */
  LpAlarmCallback =(P2CONST(Tdd_Os_AlarmCallback, AUTOMATIC, OS_CONST))LpAction;

  /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
  LsiGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();
  /* Process Alarm Callback */
  /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
  /* polyspace<RTE:COR:Not a defect:No Action Planned> function ptr points to a valid function and code is manually checked */
  /* polyspace +2 MISRA-C3:18.1 [Not a defect:Medium] "ptr points to a valid value and code is verified manually" */
  OS_PROCESS_ALARMCALLBACK(LpAlarmCallback->pAlarmCallBack);
  /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
  OS_RESTORE_INTERRUPTS(LsiGlobalIE);

  return (E_OK);
} /* End of Os_AlarmCallback(P2CONST(Tdd_Os_AlarmCallback, AUTOMATIC,
   *OS_CONST) LpAction) */
#endif /* End of if (OS_CALLBACK_COUNT > OS_PRE_ZERO) */

/***************************************************************************//**
 * Function Name        : Os_AlarmIncrementCounter
 *
 * Service ID           : NA
 *
 * Description          : This service is used to increment the counter
 *                        on expiry of the alarm
 *                        on the expiry of the alarm.
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Re-entrant
 *
 * @param[in]             LpAction    Pointer to action which takes place on
 *                                    expiry of alarm
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_LIMIT : Too many task activations
 *                        - E_OS_ACCESS : Referenced task is not accessible
 *                        - E_OS_STATE : Referenced task is in suspended state
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticCounter
 *
 *                        Function(s) invoked    :
 *                        Os_CounterTick()
 ******************************************************************************/
#if (OS_INCCOUNTER_COUNT > OS_PRE_ZERO)
FUNC(StatusType, OS_CODE) Os_AlarmIncrementCounter(P2CONST(
                           Tdd_Os_IncrementCounter, AUTOMATIC, OS_CONST) LpAction)
{
  P2CONST(Tdd_Os_IncrementCounter, AUTOMATIC, OS_CONST) LpIncrementCounter;
  StatusType LenStatusReturn;
  /* Pointer to action object Action is typecasted with the Counter to be
   *   incremented */
  LpIncrementCounter =
                (P2CONST(Tdd_Os_IncrementCounter, AUTOMATIC, OS_CONST))LpAction;
  /* polyspace-begin MISRA-C3:18.1 [Not a defect:Medium] "ptr points to a valid value and code is verified manually" */
  /* Increment the counter and get the Status */
  LenStatusReturn = Os_CounterTick
                        (&Os_GaaStaticCounter[LpIncrementCounter->ddCounterId]);
  /* polyspace-end MISRA-C3:18.1 */
  /* Return the value */
  return (LenStatusReturn);
} /* End of Os_AlarmIncrementCounter(P2CONST(Tdd_Os_IncrementCounter, AUTOMATIC,
   * OS_CONST) LpAction) */
#endif /* End of if (OS_INCCOUNTER_COUNT > OS_PRE_ZERO) */

#if (OS_ALARM == STD_ON)
/***************************************************************************//**
 * Function Name        : Os_DoGetAlarm
 *
 * Service ID           : NA
 *
 * Description          : Ths service returns the relative value in ticks
 *                        before the alarm expires.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [out]           Tick          Relative value in ticks before the alarm
 *                                      <AlarmID> expires.
 *                                      (range : 0 ~ MaxAllowdValue of Counter)
 * @param [in]            LblRemoteCall Call from another Core
 *                                      (range : OS_TRUE, OS_FALSE)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_NOFUNC : Alarm is not used
 *                        - E_OS_ACCESS : Alarm is not accessible
 *
 * @pre                 : StartOS() function should be called,
 *                        AlarmID should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) Os_DoGetAlarm(AlarmType AlarmID, TickRefType Tick,
    boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  StatusType LenStatusReturn = E_OK;

  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, AlarmID,
                                                                 LblRemoteCall);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > If multicore is not defined, this violation occurs. but this code has already been verified and no impact of this rule violation */
  if (LenStatusReturn == E_OK)
  #endif
  {
    /* Get the pointer to alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* Check whether alarm is active */
    if (LpAlarm->ucAlarmState == OS_ALARM_ACTIVE)
    {
      /* Get the pointer to static counter structure */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LpStaticCounter = LpAlarm->pStaticAlarm->pStaticCounter;

      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* If Counter is a HW Counter, update counter tick from HW timer */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually*/
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
      }
      #endif
      /* Check if absolute count of alarm is greater than current
       *   count of counter */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      if (LpAlarm->ddAbsCount >= LpStaticCounter->pCounter->ddCurrentCount)
      {
        /* Get the relative value in ticks before the alarm expires */
        /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
        *Tick = LpAlarm->ddAbsCount - LpStaticCounter->pCounter->ddCurrentCount;
      }
      else
      {
        /* Get the relative value in ticks before the alarm expires */
        /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
        *Tick = (LpStaticCounter->ddMaxAllowedValue
            - LpStaticCounter->pCounter->ddCurrentCount) +
          (LpAlarm->ddAbsCount + OS_ONE);
      } /* End of else */
    } /* End of if (LpAlarm->ucAlarmState == OS_ALARM_ACTIVE) */
    else
    {
      /* The Alarm is not active, return the proper error code */
      LenStatusReturn = E_OS_NOFUNC;
    }
  }


  return LenStatusReturn;
}

/***************************************************************************//**
 * Function Name        : Os_DoSetRelAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set the relative alarm.
 *                        After <increment> ticks have elapsed, the task
 *                        assigned to the alarm <AlarmID> is activated
 *                        or the assigned event (only for extended tasks)
 *                        is set or the alarm-callback routine is called.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            AlarmID    Reference to an alarm
 *                                   (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [in]            Increment  Relative value in ticks
 *                                   (range : 1 ~ MaxAllowdValue of Counter)
 * @param [in]            Cycle      Cycle value in case of cyclic alarm. In
 *                                   case of single alarms, cycle shall be zero.
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 * @param [in]            LblRemoteCall Call from another Core
 *                                      (range : OS_TRUE, OS_FALSE)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_STATE : Alarm is already in use
 *
 * @pre                 : StartOS() function should be called,
 *                        AlarmID, Increment and Cycle should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_InsertAlarm(), Os_GetNextTick(),
 *                        Os_AdjustTimerInterrupt()
 ******************************************************************************/
FUNC(StatusType, OS_CODE) Os_DoSetRelAlarm(AlarmType AlarmID,
                      TickType Increment, TickType Cycle, boolean LblRemoteCall)
{
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  TickType LddAbsCount;
  StatusType LenStatusReturn = E_OK;

  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Check whether Alarm is in use already */
  OS_CHECK_ALARM_INUSE_ERROR(AlarmID, &LenStatusReturn);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, AlarmID,
                                                               LblRemoteCall);

  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];
    /* Get the pointer to static counter structure */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    LpStaticCounter = LpAlarm->pStaticAlarm->pStaticCounter;

    /* Check whether alarm is active */
    if (LpAlarm->ucAlarmState == OS_ALARM_SLEEP)
    {
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* If Counter is a HW Counter, update counter tick from HW timer */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
      }
      #endif
      /* Get the value in ticks before the alarm expires */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LddAbsCount = Os_GetNextTick(LpStaticCounter->pCounter->ddCurrentCount,
                                 Increment, LpStaticCounter->ddMaxAllowedValue);
      /* polyspace:end<MISRA-C3:18.1> */
      /* Store the absolute count value */
      LpAlarm->ddAbsCount = LddAbsCount;
      /* Store the cycle value */
      LpAlarm->ddCycle = Cycle;
      /* Change state of the alarm to Active */
      LpAlarm->ucAlarmState = OS_ALARM_ACTIVE;
      /* The alarm is inserted in the alarm object list of counter */
      Os_InsertAlarm(LpAlarm);
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* Adjust timer interrupt to counter tick of first alarm */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
        Os_AdjustTimerInterrupt(
                              LpStaticCounter->pCounter->pHeadAlarm->ddAbsCount,
                                                   LpStaticCounter->pHwCounter);
        /* polyspace:end<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        /* polyspace:end<MISRA-C3:18.1> */
      }
      #endif
    } /* End of if (LpAlarm->ucAlarmState == OS_ALARM_SLEEP) */
    else
    {
      /* The alarm is in use, return the proper error code */
      LenStatusReturn = E_OS_STATE;
    }
  }

  return LenStatusReturn;
}

/***************************************************************************//**
 * Function Name        : Os_DoSetAbsAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set the absolute alarm.
 *                        When <start> ticks are reached, the configured
 *                        action takes place.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            AlarmID    Reference to an alarm
 *                                   (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [in]            Start      Absolute value in ticks
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 * @param [in]            Cycle      Cycle value in case of cyclic alarm. In
 *                                   case of single alarms, cycle shall be zero.
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 * @param [in]            LblRemoteCall Call from another Core
 *                                      (range : OS_TRUE, OS_FALSE)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_ACCESS : Alarm is not accessible
 *                        - E_OS_STATE : Alarm is already in use
 *
 * @pre                 : StartOS() function should be called,
 *                        AlarmID, Start and Cycle should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_InsertAlarm(), Os_AdjustTimerInterrupt()
 ******************************************************************************/
FUNC(StatusType, OS_CODE) Os_DoSetAbsAlarm(AlarmType AlarmID, TickType Start,
                                          TickType Cycle, boolean LblRemoteCall)
{
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
  P2CONST(Tdd_Os_StaticCounter, AUTOMATIC, OS_CONST) LpStaticCounter;
  #endif
  StatusType LenStatusReturn = E_OK;

  /* Check whether Alarm is in use already */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  OS_CHECK_ALARM_INUSE_ERROR(AlarmID, &LenStatusReturn);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, AlarmID,
                                                             LblRemoteCall);

  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* Check whether alarm is active */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if (LpAlarm->ucAlarmState == OS_ALARM_SLEEP)
    {
      /* Store Absolute count */
      LpAlarm->ddAbsCount = Start;
      /* Store cycle */
      LpAlarm->ddCycle = Cycle;
      /* Change state of the alarm to Active */
      LpAlarm->ucAlarmState = OS_ALARM_ACTIVE;
      /* The alarm is inserted in the alarm object list of counter */
      Os_InsertAlarm(LpAlarm);
      #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
      /* Get the pointer to counter */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LpStaticCounter = LpAlarm->pStaticAlarm->pStaticCounter;
      /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      if (LpStaticCounter->pHwCounter != NULL_PTR)
      {
        /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        Os_UpdateHwCounter(LpStaticCounter->pHwCounter);
        /* Adjust timer interrupt to counter tick of first alarm */
        /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
        Os_AdjustTimerInterrupt(
                              LpStaticCounter->pCounter->pHeadAlarm->ddAbsCount,
                                                   LpStaticCounter->pHwCounter);
        /* polyspace:end<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
        /* polyspace:end<MISRA-C3:18.1> */
      }
      #endif
    } /* End of if (LpAlarm->ucAlarmState == OS_ALARM_SLEEP) */
    else
    {
      /* The alarm is in use, return the proper error code */
      LenStatusReturn = E_OS_STATE;
    }
  }

  return LenStatusReturn;
}

/***************************************************************************//**
 * Function Name        : Os_DoCancelAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service is used to cancel the alarm
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            AlarmID       Reference to an alarm
 *                                      (range : 0 ~ OS_ALARM_COUNT - 1)
 * @param [in]            LblRemoteCall Call from another Core
 *                                      (range : OS_TRUE, OS_FALSE)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_NOFUNC : Alarm is already Sleep
 *                        - E_OS_ACCESS : Alarm is not accessible
 *
 * @pre                 : StartOS() function should be called,
 *                        AlarmID should be checked
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaAlarm
 *
 *                        Function(s) invoked    :
 *                        Os_RemoveAlarm()
 ******************************************************************************/
FUNC(StatusType, OS_CODE) Os_DoCancelAlarm(AlarmType AlarmID,
                                                          boolean LblRemoteCall)
{
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  StatusType LenStatusReturn = E_OK;

  /* Check whether Alarm is in use already */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  OS_CHECK_ALARM_INUSE_ERROR(AlarmID, &LenStatusReturn);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > status check */
  OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(&LenStatusReturn, AlarmID,
                                                             LblRemoteCall);

  if (LenStatusReturn == E_OK)
  {
    /* Get the pointer to static alarm structure */
    LpAlarm = &Os_GaaAlarm[AlarmID];

    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* verify the alarm is active  */
    if (LpAlarm->ucAlarmState == OS_ALARM_ACTIVE)
    {
      /* The alarm is removed from the alarm object list of counter */
      Os_RemoveAlarm(LpAlarm);
      /* State of the Alarm is changed to sleep */
      LpAlarm->ucAlarmState = OS_ALARM_SLEEP;
    } /* End of if (LpAlarm->ucAlarmState == OS_ALARM_ACTIVE) */
    else
    {
      /* The alarm is not in use, return the proper error code */
      LenStatusReturn = E_OS_NOFUNC;
    }
  }

  return LenStatusReturn;
}
#endif /* End of if (OS_ALARM == STD_ON) */

/***************************************************************************//**
 * Function Name        : Os_ProcessAlarm
 *
 * Service ID           : NA
 *
 * Description          : This service checks alarm expires and
 *                        process alarm action
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpStaticCounter    Pointer to static counter structure
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_LIMIT : Too many task activations
 *                        - E_OS_ACCESS : Referenced task is not accessible
 *                        - E_OS_STATE : Referenced task is in suspended state
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_RemoveAlarm(), pAlarmExpFunc(),
 *                        Os_GetNextTick(), Os_InsertAlarm(),
 *                        Os_IntDisableConditional(), Os_IntRestore()
 ******************************************************************************/
#if (OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON)
FUNC(StatusType, OS_CODE) Os_ProcessAlarm(P2CONST(Tdd_Os_StaticCounter,
                                           AUTOMATIC, OS_CONST) LpStaticCounter)
{
  TickType LddCurrentCount;
  TickType LddCount;
  P2VAR(Tdd_Os_Alarm, AUTOMATIC, OS_VAR) LpAlarm;
  P2CONST(Tdd_Os_StaticAlarm, AUTOMATIC, OS_CONST) LpStaticAlarm;
  P2VAR(Tdd_Os_Counter, AUTOMATIC, OS_VAR) LpCounter;
  StatusType LddStatusReturn = E_OK;
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  Os_IntStatus_T LddIntLevel;
  #endif

  /* Get the pointer to counter */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpCounter = LpStaticCounter->pCounter;
  LddCurrentCount = LpCounter->ddCurrentCount;
  /* polyspace:end<MISRA-C3:18.1> */

  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  /* SuspendOSInterrupts */
  LddIntLevel = Os_IntDisableConditional();
  #endif

  /* Check if the counter has reached the next alarm activation date */
  /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  LpAlarm = LpCounter->pHeadAlarm;

  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  while ((LpAlarm != NULL_PTR) && (LpAlarm->ddAbsCount == LddCurrentCount))
  {
    /* Get the time object from the queue */
    Os_RemoveAlarm(LpAlarm);

    /* Get the pointer to Static Alarm */
    /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
    /* polyspace:begin<RTE: COR : Not a defect : No Action Planned > function ptr points to a valid function and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    LpStaticAlarm = LpAlarm->pStaticAlarm;
     
    if(LpStaticAlarm->pActivateTask != NULL_PTR)
    {
      LddStatusReturn |= LpStaticAlarm->pActivateTask->pActivateTaskFunc(LpStaticAlarm->pActivateTask);
    }
    else if(LpStaticAlarm->pAlarmEvent != NULL_PTR)
    {
      LddStatusReturn |= LpStaticAlarm->pAlarmEvent->pAlarmEventFunc(LpStaticAlarm->pAlarmEvent);
    }
    else if(LpStaticAlarm->pIncrementCounter != NULL_PTR)
    {
      LddStatusReturn |= LpStaticAlarm->pIncrementCounter->pIncrementCounterFunc(LpStaticAlarm->pIncrementCounter);
    }
    else if(LpStaticAlarm->pAlarmCallback != NULL_PTR)
    {
      LddStatusReturn |= LpStaticAlarm->pAlarmCallback->pAlarmCallbackFunc(LpStaticAlarm->pAlarmCallback);
    }
    else if(LpStaticAlarm->pSchedTable != NULL_PTR)
    {
      LddStatusReturn |= LpStaticAlarm->pSchedTable->pSchedTableFunc(LpStaticAlarm->pSchedTable);
    }
    else
    {
      LddStatusReturn = E_NOT_OK;
    }
    /* polyspace:end<MISRA-C3:18.1> */
    /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually */
    /* polyspace:end<RTE: COR : Not a defect : No Action Planned > function ptr points to a valid function and code is verified manually */

    /* Rearm the alarm if needed   */
    if (LpAlarm->ddCycle != OS_ZERO)
    {
      /* If the cycle is not zero, the new count is computed by adding the
       *   cycle to the current count */
      LddCount = Os_GetNextTick(LpAlarm->ddAbsCount, LpAlarm->ddCycle,
                                            LpStaticCounter->ddMaxAllowedValue);

      /* Assign the computed value to Alarm's ddAbsCount */
      LpAlarm->ddAbsCount = LddCount;
      /* Put back Alarm in the alarm queue of the counter it belongs to */
      Os_InsertAlarm(LpAlarm);
    } /* End of if (LpAlarm->ddCycle != OS_ZERO) */
    else
    {
      /* If Cycle is zero then change state of the alarm */
      LpAlarm->ucAlarmState = OS_ALARM_SLEEP;
    }

    #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
    /* ResumeOSInterrupts */
    Os_IntRestore(LddIntLevel);
    #endif

    /* Execute pending Cat2 ISR here */

    #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
    /* SuspendOSInterrupts */
    LddIntLevel = Os_IntDisableConditional();
    #endif

    /* Get the next alarm to raise */
    /* polyspace<RTE: NIP : Not a defect : No Action Planned >  ptr points to a valid value and code is verified manually */
    LpAlarm = LpCounter->pHeadAlarm;
  } /* End of while ((LpAlarm != NULL_PTR) && (LpAlarm->ddAbsCount == ... */

  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  /* ResumeOSInterrupts */
  Os_IntRestore(LddIntLevel);
  #endif

  return LddStatusReturn;
}
#endif /* #if(OS_ALARM == STD_ON)||(OS_SCHEDTABLE == STD_ON) */
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<RTE : NIV :Not a defect:Justify with annotations> variable is initialized and code is verified manually. */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations > configured memory access index */
/* polyspace:end<RTE : OBAI :Not a defect:Justify with annotations > configured array index */
/* polyspace-end MISRA-C3:D4.14 */
/* polyspace-end MISRA-C3:8.7 */
/* polyspace-end MISRA-C3:11.3 */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
