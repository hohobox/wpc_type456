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
**  SRC-MODULE: Os.c                                                          **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Os API.                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: No                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.9     11-Jan-2021    YH.Han        Redmine #27622                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #25772                      **
** 2.6.5     15-Jul-2020    YH.Han        Redmine #24712                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.6.0     11-Apr-2019    SH.Yoo        Redmine #17000                      **
** 2.5.0     26-Jun-2018    SH.Yoo        Redmine #12780                      **
** 2.4.2     19-Mar-2018    MJ.Woo        Redmine #10875                      **
** 2.4.1     10-Oct-2017    MJ.Woo        Redmine #9937, #10100               **
** 2.0.13    03-Jun-2016    MJ.Woo        Redmine #4566, #5368                **
** 2.0.11    18-Feb-2016    JH.Lee,MJ.Woo Redmine #3963, #3992                **
** 2.0.10    11-Dec-2015    SH.Yoo        Redmine #2140, #2141                **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.8     14-May-2014    SH.Yoo        TASK: xar~842, Redmine #935         **
**           14-Apr-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
**                          SH.Yoo        TASK: xar~842, Redmine #124         **
** 2.0.7     04-Feb-2014    SH.Yoo        TASK: xar~819, Redmine #587         **
**                          MJ.Woo        Redmine #589                        **
** 2.0.4     23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     20-Aug-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.1     13-Aug-2013    MJ.Woo        CR: xar~160, TASK: xar~655          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:begin<MISRA-C:2.1:Not a defect:Justify with annotations> Coexistence of assembly is needed for readability  */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "Os_Multicore.h"
#if (OS_MULTICORE == STD_ON)
#include "Os_Arch_Multicore.h"
#endif
#include "Os_Error.h"
#include "Os_PortTypes.h"
#if(!((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO)))
#include "Os_Arch_Interrupt.h"
#endif
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"
#endif
#include "Os_Interrupt.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
__asm("OS_LOCKTYPE_OS .equ 0");     /* Related to Interrupt API */
__asm("OS_LOCKTYPE_ALL .equ 1");    /* Related to Interrupt API */
__asm("OS_LOCKTYPE_NONEST .equ 2"); /* Related to Interrupt API */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_USERIF_START_SEC_CODE
#include "MemMap.h"

#if (OS_ALARM == STD_ON)

/***************************************************************************//**
 * Function Name        : GetAlarmBase
 *
 * Service ID           : OSServiceId_GetAlarmBase
 *
 * Description          : This service is used to the alarm base
 *                        characteristics.
 *                        The return <Info> is a structure in
 *                        which the information of data type AlarmBaseType
 *                        is stored.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
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
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetAlarmBase(AlarmType AlarmID, AlarmBaseRefType Info)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETALARMBASE(AlarmID, Info);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetAlarm
 *
 * Service ID           : OSServiceId_GetAlarm
 *
 * Description          : The system service GetAlarm returns the value
 *                        in ticks before the alarm expires.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
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
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetAlarm(AlarmType AlarmID, TickRefType Tick)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETALARM(AlarmID, Tick);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : SetRelAlarm
 *
 * Service ID           : OSServiceId_SetRelAlarm
 *
 * Description          : This service is used to set the relative alarm.
 *                        After <increment> ticks have elapsed,
 *                        the task assigned to the alarm <AlarmID>
 *                        is activated or the assigned event
 *                        (only for extended tasks)
 *                        is set or the alarm-callback routine is called.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
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
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE)
SetRelAlarm(AlarmType AlarmID, TickType Increment, TickType Cycle)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SETRELALARM(AlarmID, Increment, Cycle);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : SetAbsAlarm
 *
 * Service ID           : OSServiceId_SetAbsAlarm
 *
 * Description          : This service is used to set the absolute alarm.
 *                        When <start> ticks are reached,
 *                        the configured action takes place.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
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
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE)
SetAbsAlarm(AlarmType AlarmID, TickType Start, TickType Cycle)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SETABSALARM(AlarmID, Start, Cycle);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : CancelAlarm
 *
 * Service ID           : OSServiceId_CancelAlarm
 *
 * Description          : This service is used to cancel the alarm
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
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
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) CancelAlarm(AlarmType AlarmID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_CANCELALARM(AlarmID);

  return LddStatusReturn;
}

#endif /* (OS_ALARM == STD_ON) */

#if (OS_APPLICATION == STD_ON)

/***************************************************************************//**
 * Function Name        : GetApplicationID
 *
 * Service ID           : OSServiceId_GetApplicationID
 *
 * Description          : This Service returns the ID of running application.
 *
 * Sync/Async           : Synchronous
 *
 * Parameters           : None
 *
 * @return              : ApplicationType
 *                        - 0 ~ OS_APPLICATION_COUNT - 1 : No error
 *                        - INVALID_OSAPPLICATION : Interrupts are disabled
 *                          by user or it is called from wrong context
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(ApplicationType, OS_CODE) GetApplicationID(void)
{
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;

  LddApplicationID = OS_SYSCALL_GETAPPLICATIONID();

  return LddApplicationID;
}

/***************************************************************************//**
 * Function Name        : CheckObjectOwnership
 *
 * Service ID           : OSServiceId_CheckObjectOwnership
 *
 * Description          : This Service returns owner of the Object.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             ObjectType  Type of the following parameter
 *                                    (range : OBJECT_TASK, OBJECT_ISR,
 *                                     OBJECT_ALARM, OBJECT_RESOURCE,
 *                                     OBJECT_COUNTER, OBJECT_SCHEDULETABLE)
 * @param[in]             ObjectID    The object to be examined
 *                                    (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : ApplicationType
 *                        - 0 ~ OS_APPLICATION_COUNT - 1
 *                        - INVALID_OSAPPLICATION :
 *                            Interrupts are disabled by user or
 *                            It is called from wrong context or
 *                            <ObjectType> is not valid
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(ApplicationType, OS_CODE) CheckObjectOwnership
    (ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
/* polyspace:end<MISRA-C3:2.7> */
{
  ApplicationType LddApplicationID = INVALID_OSAPPLICATION;

  LddApplicationID = OS_SYSCALL_CHECKOBJECTOWNERSHIP(ObjectType, ObjectID);

  return LddApplicationID;
}

#endif /* (OS_APPLICATION == STD_ON) */

#if (OS_SCALABILITY_CLASS >= OS_SC3)

/***************************************************************************//**
 * Function Name        : CheckObjectAccess
 *
 * Service ID           : OSServiceId_CheckObjectAccess
 *
 * Description          : This Service checks whether access can be granted
 *                        to the application for the specified Object.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             ApplID      OS-Application identifier
 *                                    (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             ObjectType  Type of the following parameter
 *                                    (range : OBJECT_TASK, OBJECT_ISR,
 *                                     OBJECT_ALARM, OBJECT_RESOURCE,
 *                                     OBJECT_COUNTER, OBJECT_SCHEDULETABLE)
 * @param[in]             ObjectID    The object to be examined
 *                                    (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : ObjectAccessType
 *                        - ACCESS: If the ApplID has access to the object
 *                        - NO_ACCESS: If the ApplID has no access to the object
 *                                     or Interrupts are disabled by user or
 *                                     It is called from wrong context or
 *                                     <ApplID> or <ObjectType> is not valid
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(ObjectAccessType, OS_CODE) CheckObjectAccess
    (ApplicationType ApplID,
     ObjectTypeType ObjectType, ObjectTypeIndex ObjectID)
{
  ObjectAccessType LddAccessReturn = NO_ACCESS;

  LddAccessReturn = OS_SYSCALL_CHECKOBJECTACCESS(ApplID, ObjectType, ObjectID);

  return LddAccessReturn;
}

/***************************************************************************//**
 * Function Name        : TerminateApplication
 *
 * Service ID           : OSServiceId_TerminateApplication
 *
 * Description          : This Service Terminates the specified application.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             Application   The identifier of the OS-Application to
 *                                      be terminated. If the caller belongs to
 *                                      <Application> the call results in a self
 *                                      termination.
 *                                      (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[in]             RestartOption Either RESTART for doing a restart of
 *                                      the OS-Application or NO_RESTART if
 *                                      OS-Application shall not be restarted.
 *                                      (range : RESTART, NO_RESTART)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : <Application> was not valid
 *                        - E_OS_VALUE : <RestartOption> was not valid
 *                        - E_OS_STATE : The state of <Application> does not
 *                                       allow terminating <Application>
 *                        - E_OS_LIMIT : RestartTask already activated
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) TerminateApplication
    (ApplicationType Application, RestartType RestartOption)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_TERMINATEAPPLICATION(Application, RestartOption);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : AllowAccess
 *
 * Service ID           : OSServiceId_AllowAccess
 *
 * Description          : This Service checks if access is to be granted
 *                        for application.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : StatusType
 *                        - E_OK : No errors
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_STATE : The OS-Application of the caller is
 *                          in the wrong state
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) AllowAccess(void)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_ALLOWACCESS();

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetApplicationState
 *
 * Service ID           : OSServiceId_GetApplicationState
 *
 * Description          : This Service is used to get the application state
 *                        from the given Application ID.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             Application    The OS-Application from which the
 *                                       state is requested
 *                                       (range : 0 ~ OS_APPLICATION_COUNT - 1)
 * @param[out]            Value          The current state of the application
 *                                       (range : APPLICATION_ACCESSIBLE,
 *                                                APPLICATION_RESTARTING,
 *                                                APPLICATION_TERMINATED)
 *
 * @return              : StatusType
 *                        - E_OK : No errors
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : <Application> is not valid
 *                        - E_OS_PARAM_POINTER : Value is a NULL_PTR
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
FUNC(StatusType, OS_CODE) GetApplicationState
    (ApplicationType Application, ApplicationStateRefType Value)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETAPPLICATIONSTATE(Application, Value);

  return LddStatusReturn;
}

#endif /* End of if (OS_SCALABILITY_CLASS >= OS_SC3) */


#if (OS_MEMORY_PROTECTION == STD_ON)

#if ((OS_SCALABILITY_CLASS != OS_SC3) && (OS_SCALABILITY_CLASS != OS_SC4))
#error "Os.c: Memory protection services supported in SC3 and SC4"
#endif

/***************************************************************************//**
 * Function Name        : CallTrustedFunction
 *
 * Service ID           : OSServiceId_CallTrustedFunction
 *
 * Description          : This service shall switch the processor into
 *                        privileged mode AND shall call the function
 *                        <FunctionIndex> out of a list of implementation
 *                        specific trusted functions.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             FunctionIndex  Index of the function to be called
 *                                       (range : 0 ~ OS_TRUSTED_FUNC_COUNT - 1)
 * @param[in]             FunctionParams Pointer to the parameters for the
 *                                       function - specified by the
 *                                       FunctionIndex - to be called.
 *                                       If no parameters are provided, a NULL
 *                                       pointer has to be passed.
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_SERVICEID : No function defined for this index
 *                        - E_OS_ACCESS : The Target trusted function is part of
 *                                        an OS-Application on another core
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
#if (OS_TRUSTED_FUNC_COUNT != OS_ZERO)
FUNC(StatusType, OS_CODE) CallTrustedFunction
    (TrustedFunctionIndexType FunctionIndex,
     TrustedFunctionParameterRefType FunctionParams)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn =
                  OS_SYSCALL_CALLTRUSTEDFUNCTION(FunctionIndex, FunctionParams);

  return LddStatusReturn;
}
#endif /* (OS_TRUSTED_FUNC_COUNT != OS_ZERO) */

/***************************************************************************//**
 * Function Name        : CheckISRMemoryAccess
 *
 * Service ID           : OSServiceId_CheckISRMemoryAccess
 *
 * Description          : This service checks if a memory region is write
 *                        read/execute accessible and also returns information**
 *                        if the memory region is part of the stack space.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             IsrID    CAT2 ISR reference
 *                                 (range : OS_TASK_COUNT + OS_CORE_COUNT ~
 *                                          OS_TASK_COUNT + OS_CORE_COUNT
 *                                          + OS_CAT2_ISR_COUNT - 1)
 * @param[in]             Address  Start of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 * @param[in]             Size     Size of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 *
 * @return              : AccessType
 *                        - OS_READ_ONLY
 *                        - OS_READ_WRITE
 *                        - OS_EXECUTE
 *                        - NO_ACCESS : Interrupts are disabled by user or
 *                                      It is called from wrong context or
 *                                      <IsrID> is not valid
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
FUNC(AccessType, OS_CODE) CheckISRMemoryAccess
    (ISRType IsrID, MemoryStartAddressType Address, MemorySizeType Size)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
{
  AccessType LddAccessReturn = NO_ACCESS;

  LddAccessReturn = OS_SYSCALL_CHECKISRMEMORYACCESS(IsrID, Address, Size);

  return LddAccessReturn;
}

/***************************************************************************//**
 * Function Name        : CheckTaskMemoryAccess
 *
 * Service ID           : OSServiceId_CheckTaskMemoryAccess
 *
 * Description          : This service checks if a memory region is write
 *                        read/execute accessible and also returns information**
 *                        if the memory region is part of the stack space.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             TaskID   Task reference
 *                                 (range : 0 ~ OS_TASK_COUNT
 *                                              + OS_CORE_COUNT - 1)
 * @param[in]             Address  Start of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 * @param[in]             Size     Size of memory area
 *                                 (range : 0u ~ 0xFFFFFFFFu)
 *
 * @return              : AccessType
 *                        - OS_READ_ONLY
 *                        - OS_READ_WRITE
 *                        - OS_EXECUTE
 *                        - NO_ACCESS : Interrupts are disabled by user or
 *                                      It is called from wrong context or
 *                                      <TaskID> is not valid
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
FUNC(AccessType, OS_CODE) CheckTaskMemoryAccess
    (TaskType TaskID, MemoryStartAddressType Address, MemorySizeType Size)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
{
  AccessType LddAccessReturn = NO_ACCESS;

  LddAccessReturn = OS_SYSCALL_CHECKTASKMEMORYACCESS(TaskID, Address, Size);

  return LddAccessReturn;
}

#endif /* (OS_MEMORY_PROTECTION == STD_ON) */

#if (OS_COUNTER == STD_ON)

/***************************************************************************//**
 * Function Name        : IncrementCounter
 *
 * Service ID           : OSServiceId_IncrementCounter
 *
 * Description          : IncrementCounter() increments
 *                        the counter <CounterID> by one and returns E_OK.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             CounterID  The Counter to be incremented
 *                                   (range : 0 ~ OS_COUNTER_COUNT - 1)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : The CounterID was not valid or counter is
 *                                    implemented in hardware and can not be
 *                                    incremented by software
 *                        - E_OS_CORE : Called with parameters that require
 *                                      a cross core operation
 *                        - E_OS_ACCESS : Counter is not accessible
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) IncrementCounter(CounterType CounterID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_INCREMENTCOUNTER(CounterID);

  return LddStatusReturn;
}


/***************************************************************************//**
 * Function Name        : GetCounterValue
 *
 * Service ID           : OSServiceId_GetCounterValue
 *
 * Description          : This service is used to get the current value of
 *                        a counter.CounterId is the input parameter value,
 *                        is a reference (pointer) to the variable
 *                        where the value of the counter is stored.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             CounterID  The Counter which tick value should be read
 *                                   (range : 0 ~ OS_COUNTER_COUNT - 1)
 * @param[out]            Value      Contains the current tick value
 *                                   (range : 0 ~ MaxAllowdValue of Counter)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : The <CounterID> was not valid
 *                        - E_OS_PARAM_POINTER : <Value> is a NULL_PTR
 *                        - E_OS_ACCESS : Counter is not accessible
 *                        - E_OS_SYS_ALARMINUSE : Counter interrupt is nested
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetCounterValue
    (CounterType CounterID, TickRefType Value)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETCOUNTERVALUE(CounterID, Value);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetElapsedValue
 *
 * Service ID           : OSServiceId_GetElapsedValue
 *
 * Description          : This service is used to get the elapsed value
 *                        of a counter.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             CounterID    The Counter to be read
 *                                     (range : 0 ~ OS_COUNTER_COUNT - 1)
 * @param[in,out]         Value        in: the previously read tick value
 *                                     out: the current tick value
 *                                     (range : 0 ~ MaxAllowdValue of Counter)
 * @param[out]            ElapsedValue The difference to the previous read value
 *                                     (range : 0 ~ MaxAllowdValue of Counter)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : The <CounterID> was not valid
 *                        - E_OS_PARAM_POINTER : <Value> or <ElapsedValue>
 *                                               is a NULL_PTR
 *                        - E_OS_VALUE : The given <Value> was not valid
 *                        - E_OS_ACCESS : Counter is not accessible
 *                        - E_OS_SYS_ALARMINUSE : Counter interrupt is nested
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetElapsedValue
    (CounterType CounterID, TickRefType Value, TickRefType ElapsedValue)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETELAPSEDVALUE(CounterID, Value, ElapsedValue);

  return LddStatusReturn;
}

#endif /* (OS_COUNTER == STD_ON) */

#if (OS_EVENT == STD_ON)

/***************************************************************************//**
 * Function Name        : SetEvent
 *
 * Service ID           : OSServiceId_SetEvent
 *
 * Description          : This service is used to Set the events
 *                        of task <TaskID> according to the event mask <Mask>
 *                        Calling SetEvent causes the task <TaskID>
 *                        to be transferred to the ready state,
 *                        if it was waiting for at least one of the events
 *                        specified in <Mask>.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             TaskID    Reference to the task for which one or
 *                                  several events are to be set.
 *                                  (range : 0 ~ OS_TASK_COUNT
 *                                               + OS_CORE_COUNT - 1)
 * @param[in]             Mask      Mask of the events to be set
 *                                  (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : Task <TaskID> is invalid
 *                        - E_OS_ACCESS : Referenced task is no extended task
 *                                        or Task is not accessible
 *                        - E_OS_STATE : Events can not be set as the referenced
 *                                       task is in the suspended state
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) SetEvent(TaskType TaskID, EventMaskType Mask)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SETEVENT(TaskID, Mask);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : ClearEvent
 *
 * Service ID           : OSServiceId_ClearEvent
 *
 * Description          : The events of the extended task calling ClearEvent
 *                        are cleared according to the event mask <Mask>.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             Mask      Mask of the events to be cleared
 *                                  (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ACCESS : Call not from extended task
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) ClearEvent(EventMaskType Mask)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_CLEAREVENT(Mask);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetEvent
 *
 * Service ID           : OSServiceId_GetEvent
 *
 * Description          : This service returns the current state of all event
 *                        bits of the task.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             TaskID    Task whose event mask is to be returned
 *                                  (range : 0 ~ OS_TASK_COUNT
 *                                               + OS_CORE_COUNT - 1)
 * @param[out]            Event     Reference to the memory of the return data
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ID : Task <TaskID> is invalid
 *                        - E_OS_ACCESS : Referenced task is no extended task
 *                                        or Task is not accessible
 *                        - E_OS_PARAM_POINTER : <Event> is a NULL_PTR
 *                        - E_OS_STATE : Referenced task <TaskID> is in the
 *                                       suspended state
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
/* polyspace<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
FUNC(StatusType, OS_CODE) GetEvent(TaskType TaskID, EventMaskRefType Event)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETEVENT(TaskID, Event);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : WaitEvent
 *
 * Service ID           : OSServiceId_WaitEvent
 *
 * Description          : The state of the calling task is set to waiting
 *                        unless at least one of the events specified
 *                        in <Mask> has already been set.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param[in]             Mask      Mask of the events waited for
 *                                  (range : 0 ~ 0xFFFFFFFF)
 *
 * @return              : StatusType
 *                        - E_OK : No error
 *                        - E_OS_DISABLEDINT : Interrupts are disabled by user
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ACCESS : Calling task is not an extended task
 *                        - E_OS_RESOURCE : Calling task occupies resources
 *                        - E_OS_SPINLOCK : Calling task occupies spinlock
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) WaitEvent(EventMaskType Mask)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_WAITEVENT(Mask);

  return LddStatusReturn;
}

#endif /*(OS_EVENT == STD_ON) */

/***************************************************************************//**
 * Function Name        : EnableAllInterrupts
 *
 * Service ID           : OSServiceId_EnableAllInterrupts
 *
 * Description          : This function is called to Enable All interrupts.
 *                        The function does not cause a de-scheduling.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddOldSuspendAll
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StopAllLockMonitor()
 *                        Os_IntRestore()
 ******************************************************************************/
FUNC(void, OS_CODE) EnableAllInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_IntStatus_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();
    /* Check if DisableAllInterrupts() is called */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
	/* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
    if(Os_GblISRLock[OS_CORE_ID] == OS_TRUE)
    {
      is = Os_GddOldSuspendAll[OS_CORE_ID];
      Os_GddISRLock[OS_CORE_ID] = OS_ZERO;
      Os_GblISRLock[OS_CORE_ID] = OS_FALSE;
      Os_IntRestore(is);

      #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
      /* Process timing protection */
      Os_StopAllLockMonitor();
      #endif
    }
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    (void)OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_ENABLEALLINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : DisableAllInterrupts
 *
 * Service ID           : OSServiceId_DisableAllInterrupts
 *
 * Description          : This function is called to Disable All interrupts.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddISR2Lock,
 *                        Os_GddOldSuspendAll
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StartAllLockMonitor()
 *                        Os_IntDisableAll()
 ******************************************************************************/
FUNC(void, OS_CODE) DisableAllInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_OldLevel_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();
    /* Check if DisableAll, SuspendAll and SuspendOs are not called */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if((Os_GddISRLock[OS_CORE_ID] == OS_ZERO)
       && (Os_GddISR2Lock[OS_CORE_ID] == OS_ZERO)
       && (Os_GblISRLock[OS_CORE_ID] == OS_FALSE))
    {
      #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
      /* Process timing protection */
      Os_StartAllLockMonitor();
      #endif

      is = (Os_OldLevel_T)Os_IntDisableAll();
      Os_GddISRLock[OS_CORE_ID] = OS_ONE;
      Os_GblISRLock[OS_CORE_ID] = OS_TRUE;
      Os_GddOldSuspendAll[OS_CORE_ID] = is;
    }
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    (void)OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_DISABLEALLINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : ResumeAllInterrupts
 *
 * Service ID           : OSServiceId_ResumeAllInterrupts
 *
 * Description          : This function is called to Resume All interrupts.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddOldSuspendAll
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StopAllLockMonitor()
 *                        Os_IntRestore()
 ******************************************************************************/
FUNC(void, OS_CODE) ResumeAllInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_IntStatus_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();

    /* Check if DisableAllInterrupts() is not called */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
    if(Os_GblISRLock[OS_CORE_ID] == OS_FALSE)
    {
      /* Check if SuspendAllInterrupts() is called */
      if(Os_GddISRLock[OS_CORE_ID] == OS_ONE)
      {
        is = Os_GddOldSuspendAll[OS_CORE_ID];
        Os_GddISRLock[OS_CORE_ID] = OS_ZERO;
        Os_IntRestore(is);

        #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
        /* Process timing protection */
        Os_StopAllLockMonitor();
        #endif
      }
      /* Check if SuspendAllInterrupts() is nested */
      else if(Os_GddISRLock[OS_CORE_ID] > 0)
      {
        Os_GddISRLock[OS_CORE_ID]--;
      }
      else
      /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
      {
        /* Do nothing */
      }
    }
    /* polyspace:end<RTE:UNR> */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_RESUMEALLINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : SuspendAllInterrupts
 *
 * Service ID           : OSServiceId_SuspendAllInterrupts
 *
 * Description          : This function is called to Suspend All interrupts.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddOldSuspendAll
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StartAllLockMonitor()
 *                        Os_IntDisableAll()
 ******************************************************************************/
FUNC(void, OS_CODE) SuspendAllInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_OldLevel_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();

    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* Check if DisableAllInterrupts() is not called */
    /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
    if(Os_GblISRLock[OS_CORE_ID] == OS_FALSE)
    {
      /* Check if SuspendAllInterrupts() is not called */
      if(Os_GddISRLock[OS_CORE_ID] == OS_ZERO)
      {
        #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
        /* Process timing protection */
        Os_StartAllLockMonitor();
        #endif

        is = (Os_OldLevel_T)Os_IntDisableAll();
        Os_GddISRLock[OS_CORE_ID] = OS_ONE;
        Os_GddOldSuspendAll[OS_CORE_ID] = is;
      }
      else if(Os_GddISRLock[OS_CORE_ID] < (uint8)OS_SUSPENDNESTLIMIT)
      {
        Os_GddISRLock[OS_CORE_ID]++;
      }
      else
      {
        /* Do nothing */
      }
    }
    /* polyspace:end<RTE:UNR> */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_SUSPENDALLINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : ResumeOSInterrupts
 *
 * Service ID           : OSServiceId_ResumeOSInterrupts
 *
 * Description          : This function is called to Resume CAT2 interrupts.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddISR2Lock,
 *                        Os_GddOldSuspendOs
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StopOsLockMonitor()
 *                        Os_IntRestore()
 ******************************************************************************/
FUNC(void, OS_CODE) ResumeOSInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_IntStatus_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* Check if DisableAllInterrupts() is not called */
    if(Os_GblISRLock[OS_CORE_ID] == OS_FALSE)
    {
      /* Check if SuspendOS is called and SuspendAll is not called */
      if((Os_GddISR2Lock[OS_CORE_ID] == OS_ONE)
          && (Os_GddISRLock[OS_CORE_ID] == OS_ZERO))
      {
        is = Os_GddOldSuspendOs[OS_CORE_ID];
        Os_GddISR2Lock[OS_CORE_ID] = OS_ZERO;
        Os_IntRestore(is);

        #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
        /* Process timing protection */
        Os_StopOsLockMonitor();
        #endif
      }
      /* Check if SuspendOSInterrupts() is nested */
      else if(Os_GddISR2Lock[OS_CORE_ID] > 0)
      {
        Os_GddISR2Lock[OS_CORE_ID]--;
      }
      else
      /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
      {
        /* Do nothing */
      }
    }
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_RESUMEOSINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : SuspendOSInterrupts
 *
 * Service ID           : OSServiceId_SuspendOSInterrupts
 *
 * Description          : This function is called to Suspend CAT2 interrupts.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)  :
 *                        Os_GblISRLock, Os_GddISRLock, Os_GddISR2Lock,
 *                        Os_GddOldSuspendOs
 *
 *                        Function(s) invoked : None
 *                        Os_GetCurPrivMode(), Os_StartOsLockMonitor()
 *                        Os_IntDisable()
 ******************************************************************************/
FUNC(void, OS_CODE) SuspendOSInterrupts(void)
{
  #if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  Os_Reg32 LddGlobalIE;
  Os_OldLevel_T is;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  if(Os_GetCurPrivMode() == OS_PRIV_SUPERVISOR)
  #endif
  {
    /* Current privilege level is supervisor */
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    LddGlobalIE = OS_DISABLE_AND_SAVE_INTERRUPTS();

    /* Check if DisableAllInterrupts() is not called */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if(Os_GblISRLock[OS_CORE_ID] == OS_FALSE)
    {
      /* Check if SuspendAll and SuspendOS are not called */
      if((Os_GddISRLock[OS_CORE_ID] == OS_ZERO)
          && (Os_GddISR2Lock[OS_CORE_ID] == OS_ZERO))
      {
        #if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
        /* Process timing protection */
        Os_StartOsLockMonitor();
        #endif

        is = (Os_OldLevel_T)Os_IntDisable();
        Os_GddISR2Lock[OS_CORE_ID] = OS_ONE;
        Os_GddOldSuspendOs[OS_CORE_ID] = is;
      }
      /* Check if SuspendOSInterrupts() is already called */
      else if (Os_GddISR2Lock[OS_CORE_ID] < (uint8)OS_SUSPENDNESTLIMIT)
      {
        Os_GddISR2Lock[OS_CORE_ID]++;
      }
      else
      {
        /* Do nothing */
      }
    }
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    OS_RESTORE_INTERRUPTS(LddGlobalIE);
  }
  #if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
  else
  {
    /* Current privilege level is not supervisor. Use system call! */
    OS_SYSCALL_SUSPENDOSINTERRUPTS();
  }
  #endif
  #endif
}

/***************************************************************************//**
 * Function Name        : GetISRID
 *
 * Service ID           : OSServiceId_GetISRID
 *
 * Description          : This service is used to return the Id of the ISR.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Parameters           : None
 *
 * @return              : ISRType
 *                        - OS_TASK_COUNT + OS_CORE_COUNT ~
 *                         OS_TASK_COUNT + OS_CORE_COUNT + OS_CAT2_ISR_COUNT - 1
 *                        - OS_INVALID_VALUE : Interrupts are disabled by user
 *                         or it is called from wrong context
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
FUNC(ISRType, OS_CODE) GetISRID(void)
{
  ISRType LddIsrId = INVALID_ISR;

  LddIsrId = OS_SYSCALL_GETISRID();

  return LddIsrId;
}
#endif

#if (OS_SPINLOCK == STD_ON)
/***************************************************************************//**
 * Function Name        : GetSpinlock
 *
 * Service ID           : OSServiceId_GetSpinlock
 *
 * Description          : GetSpinlock tries to occupy a spin-lock variable.
 *                        If the function returns, either the lock is
 *                        successfully taken or an error has occurred.
 *                        The spinlock mechanism is an active polling
 *                        mechanism.
 *                        The function does not cause a de-scheduling.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param [in]            SpinlockId    The value refers to the spinlock
 *                                      instance that shall be locked
 *                                      (range : 0 ~ OS_SPINLOCK_COUNT - 1)
 *
 * @return              : StatusType
 *                        - E_OK : No Error
 *                        - E_OS_ID : The <SpinlockId> is invalid
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ACCESS : The spinlock cannot be accessed
 *                        - E_OS_INTERFERENCE_DEADLOCK : A TASK tries to occupy
 *                          the spinlock while the lock is already occupied by
 *                          a TASK on the same core. This would cause a deadlock
 *                        - E_OS_NESTING_DEADLOCK : A TASK tries to occupy the
 *                          spinlock while holding a different spinlock in a way
 *                          that may cause a deadlock
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None TryToGetSpinlock()
 ******************************************************************************/
FUNC(StatusType, OS_CODE) GetSpinlock(SpinlockIdType SpinlockId)
{
  volatile StatusType LddStatusReturn = E_OK;
  TryToGetSpinlockType LddSuccess = TRYTOGETSPINLOCK_NOSUCCESS;

  while ((LddSuccess != TRYTOGETSPINLOCK_SUCCESS) && (LddStatusReturn == E_OK))
  {
    LddStatusReturn = TryToGetSpinlock(SpinlockId, &LddSuccess);
  }

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : ReleaseSpinlock
 *
 * Service ID           : OSServiceId_ReleaseSpinlock
 *
 * Description          : ReleaseSpinlock releases a spinlock variable
 *                        that was occupied before. Before terminating
 *                        a TASK all spinlock variables that have been
 *                        occupied with GetSpinlock() shall be released.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param [in]            SpinlockId    The value refers to the spinlock
 *                                      instance that shall be locked
 *                                      (range : 0 ~ OS_SPINLOCK_COUNT - 1)
 *
 * @return              : StatusType
 *                        - E_OK : No Error
 *                        - E_OS_ID : The <SpinlockId> is invalid
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ACCESS : The spinlock cannot be accessed
 *                        - E_OS_STATE : The Spinlock is not occupied
 *                        - E_OS_NOFUNC : Attempt to release a spinlock while
 *                          another spinlock has to be released before
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) ReleaseSpinlock(SpinlockIdType SpinlockId)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_RELEASESPINLOCK(SpinlockId);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : TryToGetSpinlock
 *
 * Service ID           : OSServiceId_TryToGetSpinlock
 *
 * Description          : The TryToGetSpinlockType indicates if the spinlock
 *                        has been occupied or not.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * @param [in]            SpinlockId    The value refers to the spinlock
 *                                      instance that shall be locked
 *                                      (range : 0 ~ OS_SPINLOCK_COUNT - 1)
 * @param [out]           Success       Returns if the lock has been occupied
 *                                      or not
 *                                      (range : TRYTOGETSPINLOCK_SUCCESS,
 *                                               TRYTOGETSPINLOCK_NOSUCCESS)
 *
 * @return              : StatusType
 *                        - E_OK : No Error
 *                        - E_OS_ID : The <SpinlockId> is invalid
 *                        - E_OS_CALLEVEL : It is called from wrong context
 *                        - E_OS_ACCESS : The spinlock cannot be accessed
 *                        - E_OS_INTERFERENCE_DEADLOCK : A TASK tries to occupy
 *                          the spinlock while the lock is already occupied by
 *                          a TASK on the same core. This would cause a deadlock
 *                        - E_OS_NESTING_DEADLOCK : A TASK tries to occupy the
 *                          spinlock while holding a different spinlock in a way
 *                          that may cause a deadlock
 *                        - E_OS_PARAM_POINTER : <Success> is a NULL_PTR
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) TryToGetSpinlock
    (SpinlockIdType SpinlockId,
     P2VAR(TryToGetSpinlockType, AUTOMATIC, OS_VAR) Success)
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_TRYTOGETSPINLOCK(SpinlockId, Success);

  return LddStatusReturn;
}

#endif /* End of if (OS_SPINLOCK == STD_ON) */


#if (OS_MULTICORE == STD_ON)

/***************************************************************************//**
 * Function Name        : ShutdownAllCores
 *
 * Service ID           : OSServiceId_ShutdownAllCores
 *
 * Description          : This function is called to shutdown all core.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : Error
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(void, OS_CODE) ShutdownAllCores(StatusType Error)
/* polyspace:end<MISRA-C3:2.7> */
{
  OS_SYSCALL_SHUTDOWNALLCORES(Error);
}

#endif /* End of if (OS_MULTICORE == STD_ON) */

/***************************************************************************//**
 * Function Name        : GetActiveApplicationMode
 *
 * Service ID           : OSServiceId_GetActiveApplicationMode
 *
 * Description          : This function returns the active application mode.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : None
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(AppModeType, OS_CODE) GetActiveApplicationMode(void)
{
  AppModeType LddApplicationMode = OSDEFAULTAPPMODE;

  LddApplicationMode = OS_SYSCALL_GETACTIVEAPPLICATIONMODE();

  return LddApplicationMode;
}

/***************************************************************************//**
 * Function Name        : StartOS
 *
 * Service ID           : OSServiceId_StartOS
 *
 * Description          : This function is called to start the Os.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : Mode
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : N/A
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
/* polyspace +2 MISRA-C3:D4.5 [Not a defect:Low] "Unique in OS name space" */
FUNC(void, OS_CODE) StartOS(AppModeType Mode)
/* polyspace:end<MISRA-C3:2.7> */
{
  OS_SYSCALL_STARTOS(Mode);
}

/***************************************************************************//**
 * Function Name        : ShutdownOS
 *
 * Service ID           : OSServiceId_ShutdownOS
 *
 * Description          : This function is called to shutdown the Os.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : Error
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(void, OS_CODE) ShutdownOS(StatusType Error)
/* polyspace:end<MISRA-C3:2.7> */
{
  OS_SYSCALL_SHUTDOWNOS(Error);
}

#if (OS_RESOURCE == STD_ON)

/***************************************************************************//**
 * Function Name        : GetResource
 *
 * Service ID           : OSServiceId_GetResource
 *
 * Description          : This Service is used to Get the resource.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ResID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetResource(ResourceType ResID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETRESOURCE(ResID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : ReleaseResource
 *
 * Service ID           : OSServiceId_ReleaseResource
 *
 * Description          : This Service is used to Release the resource.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ResID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) ReleaseResource(ResourceType ResID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_RELEASERESOURCE(ResID);

  return LddStatusReturn;
}

#endif /* (OS_RESOURCE == STD_ON) */

#if (OS_SCHEDTABLE == STD_ON)
/***************************************************************************//**
 * Function Name        : StartScheduleTableRel
 *
 * Service ID           : OSServiceId_StartScheduleTableRel
 *
 * Description          : This service does the processing of
 *                        the schedule table at "Offset" relative
 *                        to the "Now" value on the underlying counter.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID, Offset
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableRel
    (ScheduleTableType ScheduleTableID,
     TickType Offset)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_STARTSCHEDULETABLEREL(ScheduleTableID, Offset);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : StartScheduleTableAbs
 *
 * Service ID           : OSServiceId_StartScheduleTableAbs
 *
 * Description          : This service does the processing of
 *                        the schedule table at absolute value "Start" of
 *                        the underlying counter.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID, Start
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableAbs
    (ScheduleTableType ScheduleTableID,
     TickType Start)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_STARTSCHEDULETABLEABS(ScheduleTableID, Start);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : StopScheduleTable
 *
 * Service ID           : OSServiceId_StopScheduleTable
 *
 * Description          : This service changes the state of the schedule table**
 *                        to "Stopped" state.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) StopScheduleTable
    (ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_STOPSCHEDULETABLE(ScheduleTableID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : NextScheduleTable
 *
 * Service ID           : OSServiceId_NextScheduleTable
 *
 * Description          : This service does the processing of schedule table
 *                        <ScheduleTableID_To> <ScheduleTableID_From>.
 *                        Final Delay ticks after the Final Expiry Point
 *                        on <ScheduleTableID_From> is processed.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID_From, ScheduleTableID_To
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) NextScheduleTable
    (ScheduleTableType ScheduleTableID_From,
     ScheduleTableType ScheduleTableID_To)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn =
         OS_SYSCALL_NEXTSCHEDULETABLE(ScheduleTableID_From, ScheduleTableID_To);

  return LddStatusReturn;
}


#if (OS_SCHED_EXPLICIT_SYNC == STD_ON)

#if ((OS_SCALABILITY_CLASS != OS_SC2) && (OS_SCALABILITY_CLASS != OS_SC4))
#error "Os.c: Explicit schedule table sync supported in SC2 and SC4"
#endif

/***************************************************************************//**
 * Function Name        : StartScheduleTableSynchron
 *
 * Service ID           : OSServiceId_StartScheduleTableSynchron
 *
 * Description          : This service shall set the state of<ScheduleTableID>**
 *                        to SCHEDULETABLE_WAITING and start the processing
 *                        of schedule table <ScheduleTableID> after
 *                        the synchronization count of the schedule table
 *                        is set via SyncScheduleTable().
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) StartScheduleTableSynchron
    (ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_STARTSCHEDULETABLESYNCHRON(ScheduleTableID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : SyncScheduleTable
 *
 * Service ID           : OSServiceId_SyncScheduleTable
 *
 * Description          : This service is used to synchronize the processing
 *                       of the schedule table to the synchronization counter.**
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID, Value
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) SyncScheduleTable
    (ScheduleTableType ScheduleTableID,
     TickType Value)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SYNCSCHEDULETABLE(ScheduleTableID, Value);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : SetScheduleTableAsync
 *
 * Service ID           : OSServiceId_SetScheduleTableAsync
 *
 * Description          :This service stops sychronization of a scheduletable.**
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) SetScheduleTableAsync
    (ScheduleTableType ScheduleTableID)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SETSCHEDULETABLEASYNC(ScheduleTableID);

  return LddStatusReturn;
}

#endif /* End of if (OS_SCHED_EXPLICIT_SYNC == STD_ON) */


/***************************************************************************//**
 * Function Name        : GetScheduleTableStatus
 *
 * Service ID           : OSServiceId_GetScheduleTableStatus
 *
 * Description          : This service is used to return the status of
 *                        the schedule table requested.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : ScheduleTableID, ScheduleStatus
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) GetScheduleTableStatus
    (ScheduleTableType ScheduleTableID,
     ScheduleTableStatusRefType ScheduleStatus)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn =
             OS_SYSCALL_GETSCHEDULETABLESTATUS(ScheduleTableID, ScheduleStatus);

  return LddStatusReturn;
}

#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#if (OS_TASK == STD_ON)

/***************************************************************************//**
 * Function Name        : ActivateTask
 *
 * Service ID           : OSServiceId_ActivateTask
 *
 * Description          : This Service transfers the TaskID from
 *                        suspended state into the ready state.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : TaskID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) ActivateTask(TaskType TaskID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_ACTIVATETASK(TaskID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : TerminateTask
 *
 * Service ID           : OSServiceId_TerminateTask
 *
 * Description          : This service causes the termination of
 *                        the calling task. The calling task is transferred
 *                        from the running state into the suspended state
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : None
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) TerminateTask(void)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_TERMINATETASK();

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : ChainTask
 *
 * Service ID           : OSServiceId_ChainTask
 *
 * Description          : This service causes the termination of the calling
 *                        task. After termination of the calling tasks
 *                        a succeeding task <TaskID> is activated.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : TaskID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) ChainTask(TaskType TaskID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_CHAINTASK(TaskID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : Schedule
 *
 * Service ID           : OSServiceId_Schedule
 *
 * Description          : This service checks if a higher-priority task is
 *                        ready, the internal resource of the task is released**
 *                        the current task is put into the ready state and
 *                        the higher-priority task is executed.
 *                        Otherwise the calling task is continued.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : None
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
FUNC(StatusType, OS_CODE) Schedule(void)
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_SCHEDULE();

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetTaskID
 *
 * Service ID           : OSServiceId_GetTaskID
 *
 * Description          : This service is used to get the task id from
 *                        the task descriptor.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : TaskID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
/* polyspace<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
FUNC(StatusType, OS_CODE) GetTaskID(TaskRefType TaskID)
/* polyspace:end<MISRA-C3:2.7> */
{
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETTASKID(TaskID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : GetTaskState
 *
 * Service ID           : OSServiceId_GetTaskState
 *
 * Description          : This service is used to get the taskstate from
 *                        the given tasked.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : TaskID, State
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : StatusType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(StatusType, OS_CODE) GetTaskState
    (TaskType TaskID, TaskStateRefType State)
/* polyspace:end<MISRA-C3:2.7> */
{
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
  StatusType LddStatusReturn = E_OK;

  LddStatusReturn = OS_SYSCALL_GETTASKSTATE(TaskID, State);

  return LddStatusReturn;
}
#endif /* (OS_TASK == STD_ON) */


/***************************************************************************//**
 * Function Name        : GetNumberOfActivatedCores
 *
 * Service ID           : OS_ServiceID_GetNumberOfActivatedCores
 *
 * Description          : The function returns the number of cores activated
 *                        by the StartCore function.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Input Parameters     : None
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : uint32
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GucActivateCore
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(uint32, OS_CODE) GetNumberOfActivatedCores(void)
{
  return (Os_GucActivateCore);
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

/***************************************************************************//**
 * Function Name        : GetCoreID
 *
 * Service ID           : OS_ServiceID_GetCoreID
 *
 * Description          : The function returns a unique core identifier.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Input Parameters     : None
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : CoreIdType
 *
 * @pre                 : NA
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_MyCore()
 ******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(CoreIdType, OS_CODE) GetCoreID(void)
{
  CoreIdType LddCoreId = OS_CORE_ID_MASTER;

  LddCoreId = OS_SYSCALL_GETCOREID();

  return LddCoreId;
}
#endif /* End of if (OS_MULTICORE == STD_ON) */

/***************************************************************************//**
 * Function Name        : StartCore
 *
 * Service ID           : NA
 *
 * Description          : The function starts the core
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Reentrant
 *
 * Input Parameters     : CoreID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : Status
 *
 * @return              : Void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :  Os_GblStartOs, Os_GaaCore
 *
 *                        Function(s) invoked    :  Os_StartCore()
 *                        Os_GetSpinlock(),
 *                        Os_ReleaseSpinlock()
 ******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) StartCore(CoreIDType CoreID, StatusType *Status)
{
  StatusType LddStatusReturn;

  LddStatusReturn = E_OK;

  Os_GetSpinlock(OS_SPIN_LOCK_ZERO);

  /* Check whether CoreID is greater than number of core count */
  OS_CHECK_CORE_ID_ERROR(CoreID, &LddStatusReturn);
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Check if call is made after StartOS */
  OS_CHECK_STARTCORE_ORDER_ERROR(CoreID, LddStatusReturn);
  /* Check if Core is already started */
  OS_CHECK_CORE_ALREADY_STARTED_ERROR(CoreID, LddStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Status, LddStatusReturn);

  if (LddStatusReturn == E_OK)
  {
    Os_GaaCore[CoreID].blCoreStatus = OS_TRUE;
    /* Start another core actually */
    Os_StartCore(CoreID);
  }

  Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);

  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  if(Status != NULL_PTR)
  {
    *Status = LddStatusReturn;
  }
} /* End of StartCore(CoreIDType CoreID, StatusType *Status) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/***************************************************************************//**
 * Function Name        : StartNonAutosarCore
 *
 * Service ID           : NA
 *
 * Description          : The function starts a non AUTOSAR core
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Reentrant
 *
 * Input Parameters     : CoreID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : Status
 *
 * @return              : Void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :  Os_GblStartOs, Os_GaaCore
 *
 *                        Function(s) invoked    :  Os_StartCore()
 *                        Os_GetSpinlock(),
 *                        Os_ReleaseSpinlock()
 *
 ******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) StartNonAutosarCore(CoreIDType CoreID, StatusType *Status)
{
  StatusType LddStatusReturn;

  LddStatusReturn = E_OK;

  Os_GetSpinlock(OS_SPIN_LOCK_ZERO);

  /* Check whether CoreID is greater than number of core count */
  OS_CHECK_CORE_ID_ERROR(CoreID, &LddStatusReturn);
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* Check if Core is already started */
  OS_CHECK_CORE_ALREADY_STARTED_ERROR(CoreID, LddStatusReturn);
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  /* Check for NULL_PTR */
  OS_CHECK_NULL_PTR(Status, LddStatusReturn);

  if (LddStatusReturn == E_OK)
  {
    Os_GaaCore[CoreID].blCoreStatus = OS_TRUE;
    /* Start another core actually */
    Os_StartCore(CoreID);
  }

  Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);

  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  if(Status != NULL_PTR)
  {
    *Status = LddStatusReturn;
  }
} /* End of StartNonAutosarCore(CoreIDType CoreID, StatusType *Status) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

#if (OS_APPLICATION == STD_ON)
/***************************************************************************//**
 * Function Name        : IocRead
 *
 * Service ID           : IOCServiceId_IOC_Read
 *
 * Description          : This service is used to read data through IOC
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : IocID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : data
 *
 * @return              : Std_ReturnType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(Std_ReturnType, OS_CODE) IocRead(uint32 IocID,
                                      P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
/* polyspace:end<MISRA-C3:2.7> */
{
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace*/
  Std_ReturnType LddStatusReturn = IOC_E_OK;

  LddStatusReturn = OS_SYSCALL_IOCREAD(IocID, data);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : IocWrite
 *
 * Service ID           : IOCServiceId_IOC_Write
 *
 * Description          : This service is used to write data through IOC
 *
 * Sync/Async           : Asynchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : IocID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : data
 *
 * @return              : Std_ReturnType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(Std_ReturnType, OS_CODE) IocWrite(uint32 IocID,
                                 CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
/* polyspace:end<MISRA-C3:2.7> */
{
  Std_ReturnType LddStatusReturn = IOC_E_OK;

  LddStatusReturn = OS_SYSCALL_IOCWRITE(IocID, data);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : IocReceive
 *
 * Service ID           : IOCServiceId_IOC_Receive
 *
 * Description          : This service is used to receive data through IOC
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : IocID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : data
 *
 * @return              : Std_ReturnType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace */
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(Std_ReturnType, OS_CODE) IocReceive(uint32 IocID,
                                      P2VAR(uint8, AUTOMATIC, OS_CONST) data[])
/* polyspace:end<MISRA-C:16.7:Not a defect:Justify with annotations> This pointer is modified by syscall but not visible in polyspace */
/* polyspace:end<MISRA-C3:2.7> */
{
  Std_ReturnType LddStatusReturn = IOC_E_OK;

  LddStatusReturn = OS_SYSCALL_IOCRECEIVE(IocID, data);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : IocSend
 *
 * Service ID           : IOCServiceId_IOC_Send
 *
 * Description          : This service is used to send data through IOC
 *
 * Sync/Async           : Asynchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : IocID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : data
 *
 * @return              : Std_ReturnType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(Std_ReturnType, OS_CODE) IocSend(uint32 IocID,
                                 CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
/* polyspace:end<MISRA-C3:2.7> */
{
  Std_ReturnType LddStatusReturn = IOC_E_OK;

  LddStatusReturn = OS_SYSCALL_IOCSEND(IocID, data);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : IocEmptyQueue
 *
 * Service ID           : IOCServiceId_IOC_EmptyQueue
 *
 * Description          : This service is used to empty Queue
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : IocID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : Std_ReturnType
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(Std_ReturnType, OS_CODE) IocEmptyQueue(uint32 IocID)
/* polyspace:end<MISRA-C3:2.7> */
{
  Std_ReturnType LddStatusReturn = IOC_E_OK;

  LddStatusReturn = OS_SYSCALL_IOCEMPTYQUEUE(IocID);

  return LddStatusReturn;
}

/***************************************************************************//**
 * Function Name        : Os_IocPullCB
 *
 * Service ID           : OSServiceId_Os_IocPullCB
 *
 * Description          : This service is used to pull IOC callback function
 *
 * Sync/Async           : Asynchronous
 *
 * Re-entrancy          : Re-entrancy
 *
 * Input Parameters     : pIocPullCB, recvAppID
 *
 * InOut parameter      : None
 *
 * Output Parameters    : None
 *
 * @return              : None
 *
 * @pre                 : StartOS() API should be invoked
 *
 * @remarks             : Global Variable(s)  : None
 *                        Function(s) invoked : None
 ******************************************************************************/
/* polyspace:begin<MISRA-C3:2.7:Not a defect:Justify with annotations> parameter is used according to MCU */
FUNC(void, OS_CODE) Os_IocPullCB(P2FUNC(void, OS_CONST, pIocPullCB) (void),
    ApplicationType recvAppID)
/* polyspace:end<MISRA-C3:2.7> */
{
  OS_SYSCALL_IOCPULLCB(pIocPullCB, recvAppID);
}
#endif /* if (OS_APPLICATION == STD_ON) */

#define OS_USERIF_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:end<MISRA-C:2.1:Not a defect:Justify with annotations> Coexistence of assembly is needed for readability  */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
