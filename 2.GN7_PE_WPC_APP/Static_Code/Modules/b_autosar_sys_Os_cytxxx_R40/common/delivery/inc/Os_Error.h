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
**  SRC-MODULE: Os_Error.h                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for Os_Error.c file containing the declaration of **
**              Hook functionality related functions.                         **
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
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.9     11-Jan-2021    YH.Han        Redmine #27622                      **
** 2.6.8     25-Nov-2020    JH.Cho        Redmine #26808                      **
** 2.6.7     04-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24397                      **
** 2.6.3     01-Jun-2020    MJ.Woo        Redmine #23813, #21784              **
** 2.6.2     13-Apr-2020    MJ.Woo        Redmine #22921                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.5.0     26-Jun-2018    SH.Yoo        Redmine #12780                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025, #12132              **
** 2.4.2     13-Mar-2018    MJ.Woo        Redmine #7001                       **
** 2.4.0     14-Aug-2017    MJ.Woo        Redmine #4868                       **
** 2.3.1     13-Jul-2017    SH.Yoo        Redmine #8442, #9148                **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.1.0     05-Oct-2016    SH.Yoo        Redmine #5866                       **
** 2.0.13    03-Jun-2016    MJ.Woo        Redmine #4595, #4686, #4566, #5368  **
** 2.0.11    18-Feb-2016    JH.Lee        Redmine #3963, #3992                **
**           23-Dec-2015    MJ.Woo        Redmine #2057                       **
** 2.0.10    09-Dec-2015    SH.Yoo        Redmine #1661                       **
** 2.0.9     13-Jul-2015    SH.Yoo        Redmine #2849                       **
**           19-Mar-2014    SH.Yoo        Redmine #2349                       **
**           10-Dec-2014    MJ.Woo        Redmine #494, #1189, #1412          **
** 2.0.8     14-May-2014    SH.Yoo        TASK: xar~842, Redmine #936         **
** 2.0.4     14-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**                          DG.Lee                                            **
**                          MJ.Woo                                            **
** 2.0.3     16-Sep-2013    SH.Yoo        CR: xar~172, TASK: xar~691          **
** 2.0.2     03-Sep-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/


/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Inline functions are needed for performance and Macro definitions are needed for performance and file size  */
/* polyspace:begin<MISRA-C:8.1:Not a defect:Justify with annotations> Prototype declaration of inline function is not needed */
/* polyspace:begin<MISRA-C:8.5:Not a defect:Justify with annotations> Inline functions should be implemented in header file  */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
/* polyspace:begin<MISRA-C:19.10:Not a defect:Justify with annotations> Left operand cannot be enclosed in parentheses */
/* polyspace:begin<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-begin CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */

#ifndef OS_ERROR_H
#define OS_ERROR_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_ErrorExternal.h"
#include "Os_Arch_Interrupt.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

#if (OS_ERROR_HOOK == STD_ON)

/* Parameter 1s */
#define OS_STORE_PARAM1_FUNCTIONINDEX(Param_FunctionIndex)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.FunctionIndex =\
                                                        (Param_FunctionIndex);\
  } while(0)

#define OS_STORE_PARAM1_TASKID(Param_TaskID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.TaskID = (Param_TaskID);\
  } while(0)

#define OS_STORE_PARAM1_SCHEDTABLEID(Param_ScheduleTableID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.ScheduleTableID\
                                                   = (Param_ScheduleTableID);\
  } while(0)

#define OS_STORE_PARAM1_SCHEDTABLEID_FROM(Param_ScheduleTableID_From)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.ScheduleTableID_From =\
    (Param_ScheduleTableID_From);\
  } while(0)
#define OS_STORE_PARAM1_COUNTERID(Param_CounterID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.CounterID = \
    (Param_CounterID);\
  } while(0)

#define OS_STORE_PARAM1_APPLICATION(Param_Application)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.Application =\
                                                          (Param_Application);\
  } while(0)

#define OS_STORE_PARAM1_TASKIDREF(Param_TaskID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.TaskIDRef = (Param_TaskID);\
  } while(0)

#define OS_STORE_PARAM1_RESID(Param_ResID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.ResID = (Param_ResID);\
  } while(0)

#define OS_STORE_PARAM1_MASK(Param_Mask)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.Mask = (Param_Mask);\
  } while(0)

#define OS_STORE_PARAM1_ALARMID(Param_AlarmID)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.AlarmID = (Param_AlarmID);\
  } while(0)

#define OS_STORE_PARAM1_SPINLOCKID(Param_SpinlockId)\
  do{\
 Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam1.SpinlockId = \
                                                            (Param_SpinlockId);\
  } while(0)

/* Parameter 2s */
#define OS_STORE_PARAM2_FUNCTIONPARAMS(Param_FunctionParams)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.FunctionParams =\
                                                       (Param_FunctionParams);\
  } while(0)

#define OS_STORE_PARAM2_OFFSET(Param_Offset)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Offset = (Param_Offset);\
  } while(0)

#define OS_STORE_PARAM2_START(Param_Start)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Start = (Param_Start);\
  } while(0)

#define OS_STORE_PARAM2_SCHEDTABLEID_TO(Param_ScheduleTableID_To)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.ScheduleTableID_To =\
    (Param_ScheduleTableID_To);\
  } while(0)

#define OS_STORE_PARAM2_VALUE(Param_Value)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Value = (Param_Value);\
  } while(0)

#define OS_STORE_PARAM2_SCHEDULESTATUS(Param_ScheduleStatus)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.ScheduleStatus =\
                                                             (Param_ScheduleStatus);\
  } while(0)

#define OS_STORE_PARAM2_VALUEREF(Param_Value)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.ValueRef = (Param_Value);\
  } while(0)

#define OS_STORE_PARAM2_RESTARTOPTION(Param_RestartOption)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.RestartOption =\
                                                              (Param_RestartOption);\
  } while(0)

#define OS_STORE_PARAM2_APPVALUEREF(Param_Value)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.AppValueRef = (Param_Value);\
  } while(0)

#define OS_STORE_PARAM2_STATE(Param_State)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.State = (Param_State);\
  } while(0)

#define OS_STORE_PARAM2_MASK(Param_Mask)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Mask = (Param_Mask);\
  } while(0)

#define OS_STORE_PARAM2_EVENT(Param_Event)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Event = (Param_Event);\
  } while(0)

#define OS_STORE_PARAM2_INFO(Param_Info)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Info = (Param_Info);\
  } while(0)

#define OS_STORE_PARAM2_TICK(Param_Tick)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Tick = (Param_Tick);\
  } while(0)

#define OS_STORE_PARAM2_INCREMENT(Param_Increment)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Increment = (Param_Increment);\
  } while(0)

#define OS_STORE_PARAM2_TICKSTART(Param_TickStart)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.TickStart = (Param_TickStart);\
  } while(0)

#define OS_STORE_PARAM2_SUCCESS(Param_Success)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam2.Success = (Param_Success);\
  } while(0)

/* Parameter 3s */
#define OS_STORE_PARAM3_ELAPSEDVALUE(Param_ElapsedValue)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam3.ElapsedValue =\
                                                                (Param_ElapsedValue);\
  } while(0)
#define OS_STORE_PARAM3_CYCLE(Param_Cycle)\
  do{\
  Os_GddServiceCall[OS_CORE_ID].ddParameters.unParam3.Cycle = (Param_Cycle);\
  } while(0)

#else /* End of if (OS_ERROR_HOOK == STD_ON) */
/* Parameter 1s */
#define OS_STORE_PARAM1_FUNCTIONINDEX(FunctionIndex)
#define OS_STORE_PARAM1_TASKID(TaskID)
#define OS_STORE_PARAM1_SCHEDTABLEID(ScheduleTableID)
#define OS_STORE_PARAM1_SCHEDTABLEID_FROM(ScheduleTableID_From)
#define OS_STORE_PARAM1_COUNTERID(CounterID)
#define OS_STORE_PARAM1_APPLICATION(Application)
#define OS_STORE_PARAM1_TASKIDREF(TaskIDRef)
#define OS_STORE_PARAM1_RESID(ResID)
#define OS_STORE_PARAM1_MASK(Mask)
#define OS_STORE_PARAM1_ALARMID(AlarmID)
#define OS_STORE_PARAM1_SPINLOCKID(SpinlockId)

/* Parameter 2s */
#define OS_STORE_PARAM2_FUNCTIONPARAMS(FunctionParams)
#define OS_STORE_PARAM2_OFFSET(Offset)
#define OS_STORE_PARAM2_START(Start)
#define OS_STORE_PARAM2_SCHEDTABLEID_TO(ScheduleTableID_To)
#define OS_STORE_PARAM2_VALUE(Value)
#define OS_STORE_PARAM2_SCHEDULESTATUS(ScheduleStatus)
#define OS_STORE_PARAM2_VALUEREF(ValueRef)
#define OS_STORE_PARAM2_RESTARTOPTION(RestartOption)
#define OS_STORE_PARAM2_APPVALUEREF(Value)
#define OS_STORE_PARAM2_STATE(State)
#define OS_STORE_PARAM2_MASK(Mask)
#define OS_STORE_PARAM2_EVENT(Event)
#define OS_STORE_PARAM2_INFO(Info)
#define OS_STORE_PARAM2_TICK(Tick)
#define OS_STORE_PARAM2_INCREMENT(Increment)
#define OS_STORE_PARAM2_TICKSTART(TickStart)
#define OS_STORE_PARAM2_SUCCESS(Success)

/* Parameter 3s */
#define OS_STORE_PARAM3_ELAPSEDVALUE(ElapsedValue)
#define OS_STORE_PARAM3_CYCLE(Cycle)
#endif /* Error Hook */

#if (OS_CORE_COUNT > OS_ONE)
#define OS_CHECK_COUNTER_RESIDING_COUNTER_ERROR(CounterID,\
                                                OS_CORE_ID, LenStatusReturn)\
do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticCounter[(CounterID)].ddCoreID != (OS_CORE_ID)))\
  {\
    LenStatusReturn = E_OS_CORE;\
  }\
} while(0)

#else /* End of if (OS_CORE_COUNT > OS_ONE) */
#define OS_CHECK_COUNTER_RESIDING_COUNTER_ERROR(CounterID, OS_CORE_ID,\
                                                LenStatusReturn)
#endif /* End of if (OS_CORE_COUNT > OS_ONE) */

/* Context for Service Call */
#define OS_CONTEXT_NONE                         0x0000U
#define OS_CONTEXT_TASK                         0x0001U
#if (OS_CAT1_ISR_COUNT > OS_PRE_ZERO)
#define OS_CONTEXT_CAT1ISR                      0x0002U
#else
#define OS_CONTEXT_CAT1ISR                      0x0000U
#endif
#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
#define OS_CONTEXT_CAT2ISR                      0x0004U
#else
#define OS_CONTEXT_CAT2ISR                      0x0000U
#endif
#if (OS_ERROR_HOOK == STD_ON)
#define OS_CONTEXT_ERRORHOOK                    0x0008U
#else
#define OS_CONTEXT_ERRORHOOK                    0x0000U
#endif
#if (OS_PRETASK_HOOK == STD_ON)
#define OS_CONTEXT_PRETASKHOOK                  0x0010U
#else
#define OS_CONTEXT_PRETASKHOOK                  0x0000U
#endif
#if (OS_POSTTASK_HOOK == STD_ON)
#define OS_CONTEXT_POSTTASKHOOK                 0x0020U
#else
#define OS_CONTEXT_POSTTASKHOOK                 0x0000U
#endif
#if (OS_STARTUP_HOOK == STD_ON)
#define OS_CONTEXT_STARTUPHOOK                  0x0040U
#else
#define OS_CONTEXT_STARTUPHOOK                  0x0000U
#endif
#if (OS_SHUTDOWN_HOOK == STD_ON)
#define OS_CONTEXT_SHUTDOWNHOOK                 0x0080U
#else
#define OS_CONTEXT_SHUTDOWNHOOK                 0x0000U
#endif
#if (OS_CALLBACK_COUNT > OS_PRE_ZERO)
#define OS_CONTEXT_ALARMCALLBACK                0x0100U
#else
#define OS_CONTEXT_ALARMCALLBACK                0x0000U
#endif
#if (OS_PROTECTION_HOOK == STD_ON)
#define OS_CONTEXT_PROTECTIONHOOK               0x0200U
#else
#define OS_CONTEXT_PROTECTIONHOOK               0x0000U
#endif
#define OS_CONTEXT_ALL                          OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT1ISR |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK |\
                                                OS_CONTEXT_STARTUPHOOK |\
                                                OS_CONTEXT_SHUTDOWNHOOK |\
                                                OS_CONTEXT_ALARMCALLBACK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CONTEXT_HOOK                         (OS_CONTEXT_ERRORHOOK |\
                                                 OS_CONTEXT_PRETASKHOOK |\
                                                 OS_CONTEXT_POSTTASKHOOK |\
                                                 OS_CONTEXT_STARTUPHOOK |\
                                                 OS_CONTEXT_SHUTDOWNHOOK |\
                                                 OS_CONTEXT_PROTECTIONHOOK)

#define OS_CONTEXT_MASK                         0x3FFU

#if (OS_PRETASK_HOOK == STD_ON)
#define OS_PROCESS_PRETASKHOOK()\
  do{\
    OS_SET_KERNEL_FLAG();\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_PRETASKHOOK;\
    PreTaskHook();\
    Os_GusCallevelCheck[OS_CORE_ID] &= (uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_PRETASKHOOK);\
    OS_CLEAR_KERNEL_FLAG();\
  }while(0)
#else
#define OS_PROCESS_PRETASKHOOK()
#endif

#if (OS_POSTTASK_HOOK == STD_ON)
#define OS_PROCESS_POSTTASKHOOK()\
 do {\
    OS_SET_KERNEL_FLAG();\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_POSTTASKHOOK;\
    PostTaskHook();\
    Os_GusCallevelCheck[OS_CORE_ID] &= (uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_POSTTASKHOOK);\
    OS_CLEAR_KERNEL_FLAG();\
   }while(0)
#else
#define OS_PROCESS_POSTTASKHOOK()
#endif

#if (OS_STARTUP_HOOK == STD_ON)
#define OS_PROCESS_STARTUPHOOK()\
   do {\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_STARTUPHOOK;\
    StartupHook();\
    Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_STARTUPHOOK));\
   }while(0)
#else
#define OS_PROCESS_STARTUPHOOK()
#endif

#if (OS_APP_STARTUP_HOOK == STD_ON)
#define OS_PROCESS_APP_STARTUPHOOK(AppStartupHook)\
  do {\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_STARTUPHOOK;\
    AppStartupHook();\
    Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_STARTUPHOOK));\
  }while(0)

#else
#define OS_PROCESS_APP_STARTUPHOOK(AppStartupHook)
#endif

#if (OS_SHUTDOWN_HOOK == STD_ON)
#define OS_PROCESS_SHUTDOWNHOOK(Error)\
  do {\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_SHUTDOWNHOOK;\
    ShutdownHook(Error);\
    Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_SHUTDOWNHOOK));\
    }while(0)
#else
#define OS_PROCESS_SHUTDOWNHOOK(Error)
#endif

#if (OS_APP_SHUTDOWN_HOOK == STD_ON)
#define OS_PROCESS_APP_SHUTDOWNHOOK(AppShutdownHook, Error)\
  do {\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_SHUTDOWNHOOK;\
    AppShutdownHook(Error);\
    Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_SHUTDOWNHOOK));\
    }while(0)
#else
#define OS_PROCESS_APP_SHUTDOWNHOOK(AppShutdownHook, Error)
#endif

#if (OS_PROTECTION_HOOK == STD_ON)
#define OS_PROCESS_PROTECTIONHOOK(LenResult, Error)\
  do {\
    OS_SET_KERNEL_FLAG();\
    Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_PROTECTIONHOOK;\
    LenResult = ProtectionHook(Error);\
    Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)((uint16)0xFFFF & ~(uint16)OS_CONTEXT_PROTECTIONHOOK));\
    OS_CLEAR_KERNEL_FLAG();\
   }while(0)
#else
#define OS_PROCESS_PROTECTIONHOOK(LenResult, Error)
#endif

/* Checks if increment is within the range of the
 *   maximum allowed value for the counter used by the alarm */
#if (OS_ALARM == STD_ON)
#define OS_CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(AlarmID, Increment,\
                                               LenStatusReturn)\
  do {\
    if (((LenStatusReturn) == E_OK) && (((Increment) == OS_ZERO) ||\
                                      ((Increment) >\
                                      Os_GaaStaticAlarm[(AlarmID)].pStaticCounter->\
                                       ddMaxAllowedValue)))\
    {\
      LenStatusReturn = E_OS_VALUE;\
    }\
  } while(0)
#else /* End of if (OS_ALARM == STD_ON) */
#define OS_CHECK_ALARM_MAX_ALLOWED_VALUE_ERROR(AlarmID, Increment,\
                                               LenStatusReturn)
#endif /* End of if (OS_ALARM == STD_ON) */

#if (OS_STATUS == STANDARD)
#define OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn)
#define OS_CHECK_ISR_ID_ERROR(IsrID, LenStatusReturn)
#define OS_CHECK_TASK_ID_STATE_ERROR(TaskID, LenStatusReturn)
#define OS_CHECK_TASK_CALL_LEVEL_ERROR(LenStatusReturn)
#define OS_CHECK_ISR_CALL_LEVEL_ERROR(LenStatusReturn)
#define OS_CHECK_NOT_EXTENDED_TASK_ERROR(TaskID, LenStatusReturn)
/* FIXME: ManJe.Woo WaitEvent, ClearEvent should be prevented in basic task
 * both standard status and extended status(Defect List No.57)
 * Direct return seems to be bad... */
#define OS_CHECK_NOT_EXTENDED_RUNNING_ERROR(LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].usType !=\
         OS_TASK_EXTENDED))\
    {\
      return E_OK;\
    }\
  }while(0)
#define OS_CHECK_SUSPENDED_TASK_ERROR(TaskID, LenStatusReturn)
#define OS_CHECK_RESOURCE_ID_ERROR(ResID, LenStatusReturn)
#define OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn)
#define OS_CHECK_RESOURCE_ORDER_ON_RELEASE(LpResource, LenStatusReturn)
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_GET(LpResource, LenStatusReturn)
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(LpResource, LenStatusReturn)
#define OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn)
#define OS_CHECK_ALARM_MAX_ALLOWED_ABS_VALUE_ERROR(AlarmID, Start,\
                                                   LenStatusReturn)
#define OS_CHECK_ALARM_MIN_CYCLE_ERROR(AlarmID, Cycle, LenStatusReturn)
#define OS_CHECK_COUNTER_ID_ERROR(CounterID, LenStatusReturn)
#define OS_CHECK_COUNTER_KIND_ERROR(CounterID, LenStatusReturn)
#define OS_CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(CounterID, Value,\
                                                 LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, LenStatusReturn)
#define OS_CHECK_NEXT_SCHEDTABLE_ID_ERROR(ScheduleTableID_From,\
                              ScheduleTableID_To, LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_OFFSET_VALUE_ERROR(ScheduleTableID, Offset,\
                                               LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_TICK_VALUE(ScheduleTableID, Start,\
                                       LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_VALUE_ERROR(ScheduleTableID, Value,\
                                        LenStatusReturn)
#define OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_COUNTERS(ScheduleTableID_From,\
                                     ScheduleTableID_To, LenStatusReturn)
#define OS_CHECK_NEXT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID_From,\
                                            ScheduleTableID_To,LenStatusReturn)
#define OS_CHECK_EXPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)
#define OS_CHECK_SPINLOCK_ID_ERROR(SpinlockId, LenStatusReturn)
#define OS_CHECK_SPINLOCK_STATUS_ERROR(SpinlockId, LenStatusReturn)
#define OS_CHECK_SPINLOCK_DEADLOCK_ERROR(SpinlockId, LpTask,\
                                         LenStatusReturn)
#define OS_CHECK_SPINLOCK_STATE_ERROR(SpinlockId, LenStatusReturn)
#define OS_CHECK_SPINLOCK_RELEASE_ORDER_ERROR(SpinlockId, LenStatusReturn)
#define OS_CHECK_CORE_ID_ERROR(CoreID, LenStatusReturn)
#define OS_CHECK_STARTCORE_ORDER_ERROR(CoreID, LenStatusReturn)
#define OS_CHECK_CORE_ALREADY_STARTED_ERROR(CoreID, LenStatusReturn)
#define OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn)
#define OS_CHECK_TRUSTED_FUNCTION_INDEX(FunctionIndex, LenStatusReturn)
#define OS_CHECK_OBJECT_TYPE_ERROR(ObjectType, LenStatusReturn)
#define OS_CHECK_APPL_ID_ERROR(ApplID, LenStatusReturn)
#define OS_CHECK_OBJ_ACCESS_APPL_ID_ERROR(ApplID, LenStatusReturn)
#define OS_CHECK_APPLICATION_STATE(LenStatusReturn)
#define OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, TaskID)
#define OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, TaskID, \
                                                                     RemoteCall)
#define OS_CHECK_ISR_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, IsrID)
#define OS_CHECK_ISR_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, IsrID, \
                                                                     RemoteCall)
#define OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, AlarmID)
#define OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, AlarmID, \
                                                                     RemoteCall)
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, ResID)
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, ResID,\
                                                                     RemoteCall)
#define OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, CounterID)
#define OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, \
                                                          CounterID, RemoteCall)
#define OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, \
                                                                ScheduleTableID)
#define OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, \
                                                    ScheduleTableID, RemoteCall)
#define OS_CHECK_RESTART_VALUE_ERROR(LenStatusReturn, RestartOption)
#define OS_CHECK_CALLER_APPLICATION_ERROR(TargetApplication, LenStatusReturn)
#define OS_CHECK_APPL_CALLER_ACCESS_ERROR(Application, LenStatusReturn)
#define OS_CHECK_APPL_TERMINATED_STATE_ERROR(Application, LenStatusReturn)
#define OS_CHECK_STARTOS_ERROR(LenStatusReturn)
#define OS_CHECK_APPL_RESTART_STATE_ERROR(Application, LenStatusReturn,\
                                          RestartOption)
#define OS_CHECK_E_OS_CALLEVEL(Service, LenStatusReturn)
#define OS_SELF_TERMINATION_CHECK(LenStatusReturn, Application)
#define OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId)
#define OS_CHECK_ALARM_INUSE_ERROR(AlarmID, LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, LenStatusReturn)
#define OS_CHECK_COUNTER_INUSE_ERROR(CounterID, LenStatusReturn)
#define OS_CHECK_IOC_ID_ERROR(IocID, IocCount, LenStatusReturn)
#define OS_CHECK_IOC_INVALID_BUF_ERROR(IocBuf, LenStatusReturn)
#else /* else of #if (OS_STATUS == STANDARD) */

/* Available Call Levels for Each Service */
#define OS_CALLEVEL_ACTIVATETASK                OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_TERMINATETASK               OS_CONTEXT_TASK
#define OS_CALLEVEL_CHAINTASK                   OS_CONTEXT_TASK
#define OS_CALLEVEL_SCHEDULE                    OS_CONTEXT_TASK
#define OS_CALLEVEL_GETTASKID                   OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_GETTASKSTATE                OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK
#define OS_CALLEVEL_DISABLEALLINTERRUPTS        OS_CONTEXT_ALL
#define OS_CALLEVEL_ENABLEALLINTERRUPTS         OS_CONTEXT_ALL
#define OS_CALLEVEL_SUSPENDALLINTERRUPTS        OS_CONTEXT_ALL
#define OS_CALLEVEL_RESUMEALLINTERRUPTS         OS_CONTEXT_ALL
#define OS_CALLEVEL_SUSPENDOSINTERRUPTS         OS_CONTEXT_ALL
#define OS_CALLEVEL_RESUMEOSINTERRUPTS          OS_CONTEXT_ALL
#define OS_CALLEVEL_GETRESOURCE                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_RELEASERESOURCE             OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_SETEVENT                    OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_CLEAREVENT                  OS_CONTEXT_TASK
#define OS_CALLEVEL_GETEVENT                    OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK
#define OS_CALLEVEL_WAITEVENT                   OS_CONTEXT_TASK
#define OS_CALLEVEL_GETALARMBASE                OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK
#define OS_CALLEVEL_GETALARM                    OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK
#define OS_CALLEVEL_SETRELALARM                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_SETABSALARM                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_CANCELALARM                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETACTIVEAPPLICATIONMODE    OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK |\
                                                OS_CONTEXT_STARTUPHOOK |\
                                                OS_CONTEXT_SHUTDOWNHOOK
#define OS_CALLEVEL                             OS_CONTEXT_NONE
#define OS_CALLEVEL_SHUTDOWNOS                  OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_STARTUPHOOK
#define OS_CALLEVEL_GETAPPLICATIONID            OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK |\
                                                OS_CONTEXT_STARTUPHOOK |\
                                                OS_CONTEXT_SHUTDOWNHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_GETISRID                    OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_CALLTRUSTEDFUNCTION         OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_CHECKISRMEMORYACCESS        OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_CHECKTASKMEMORYACCESS       OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_CHECKOBJECTACCESS           OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_CHECKOBJECTOWNERSHIP        OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_STARTSCHEDULETABLEREL       OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_STARTSCHEDULETABLEABS       OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_STOPSCHEDULETABLE           OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_NEXTSCHEDULETABLE           OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_STARTSCHEDULETABLESYNCHRON  OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_SYNCSCHEDULETABLE           OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETSCHEDULETABLESTATUS      OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_SETSCHEDULETABLEASYNC       OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_INCREMENTCOUNTER            OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETCOUNTERVALUE             OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETELAPSEDVALUE             OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_TERMINATEAPPLICATION        OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK
#define OS_CALLEVEL_ALLOWACCESS                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETAPPLICATIONSTATE         OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_PRETASKHOOK |\
                                                OS_CONTEXT_POSTTASKHOOK |\
                                                OS_CONTEXT_STARTUPHOOK |\
                                                OS_CONTEXT_SHUTDOWNHOOK |\
                                                OS_CONTEXT_PROTECTIONHOOK
#define OS_CALLEVEL_GETNUMBEROFACTIVATEDCORES   OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_GETCOREID                   OS_CONTEXT_ALL
#define OS_CALLEVEL_STARTCORE                   OS_CONTEXT_NONE
#define OS_CALLEVEL_STARTNONAUTOSARCORE         OS_CONTEXT_NONE
#define OS_CALLEVEL_GETSPINLOCK                 OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_RELEASESPINLOCK             OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_TRYTOGETSPINLOCK            OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR
#define OS_CALLEVEL_SHUTDOWNALLCORES            OS_CONTEXT_TASK |\
                                                OS_CONTEXT_CAT2ISR |\
                                                OS_CONTEXT_ERRORHOOK |\
                                                OS_CONTEXT_STARTUPHOOK
/* polyspace-begin MISRA-C3:20.10 [Not a defect:Low] "## preprocessor is needed to naming Callevel" */
#define OS_CHECK_E_OS_CALLEVEL(Service, LenStatusReturn)\
  (Os_CheckCallevel(OS_CALLEVEL_##Service, &(LenStatusReturn)))
/* polyspace-end MISRA-C3:20.10 */

#if ((OS_ERROR_HOOK == STD_ON) || (OS_APP_ERROR_HOOK == STD_ON))
#define OS_SELF_TERMINATION_CHECK(LenStatusReturn, Application)\
 do{\
  if(((LenStatusReturn) == E_OK) &&\
     ((Os_GusCallevelCheck[OS_CORE_ID] & OS_CONTEXT_ERRORHOOK)\
                                                      != (uint16)OS_ZERO) &&\
                                   (Os_GddAppId[OS_CORE_ID] != (Application)))\
  {\
    LenStatusReturn = E_OS_CALLEVEL;\
  }\
 } while(0)
#else
#define OS_SELF_TERMINATION_CHECK(LenStatusReturn, Application)
#endif

/* Check for Multiple StartOs call on the same core */
#define OS_CHECK_STARTOS_ERROR(LenStatusReturn) \
 do{\
  if (((LenStatusReturn) == E_OK) && (Os_GblStartOs[OS_CORE_ID] == OS_TRUE))\
  {\
    LenStatusReturn = E_OS_CALLEVEL;\
  }\
 } while(0)
#define OS_CHECK_INVALID_ADDRESS(Value, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) && ((Value) == NULL_PTR))\
  {\
    LenStatusReturn = E_OS_ILLEGAL_ADDRESS;\
  }\
 } while(0)
/* Task ID Error */
#if (OS_TASK == STD_ON)
#define OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (((TaskID) >= (Os_Task_Count + Os_Core_Count))\
        || ((TaskID) < Os_Core_Count)))\
  {\
    LenStatusReturn = E_OS_ID;\
  }\
 } while(0)
#else /* End of if (OS_TASK == STD_ON) */
#define OS_CHECK_TASK_ID_ERROR(TaskID, LenStatusReturn)
#endif /*#if(OS_TASK == STD_ON)*/

/* Task ID Error */
#if (OS_TASK == STD_ON)
#define OS_CHECK_TASK_ID_STATE_ERROR(TaskID, LenStatusReturn)\
  do{ \
    if (((LenStatusReturn) == E_OK) &&\
      (((TaskID) >= (Os_Task_Count + Os_Core_Count))\
       || ((TaskID) == OS_ZERO)))\
    {\
    LenStatusReturn = E_OS_ID;\
    }\
  } while(0)
#else /* End of if (OS_TASK == STD_ON) */
#define OS_CHECK_TASK_ID_STATE_ERROR(TaskID, LenStatusReturn)
#endif /*#if(OS_TASK == STD_ON)*/

/* Task Call Level Error */
#define OS_CHECK_TASK_CALL_LEVEL_ERROR(LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GucNestingCAT2ISR[OS_CORE_ID] != OS_ZERO))\
  {\
    LenStatusReturn = E_OS_CALLEVEL;\
  }\
 } while(0)


/* ISR Call Level Error */
#define OS_CHECK_ISR_CALL_LEVEL_ERROR(LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
   (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].usType != OS_ISR2))\
  {\
    LenStatusReturn = E_OS_CALLEVEL;\
  }\
 } while(0)
/* Check for extended Task */
#if (OS_TASK == STD_ON)
#define OS_CHECK_NOT_EXTENDED_TASK_ERROR(TaskID, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticTask[(TaskID)].usType != OS_TASK_EXTENDED))\
  {\
    LenStatusReturn = E_OS_ACCESS;\
  }\
 } while(0)
#else /* End of if (OS_TASK == STD_ON) */
#define OS_CHECK_NOT_EXTENDED_TASK_ERROR(TaskID, LenStatusReturn)
#endif /* End of if (OS_TASK == STD_ON) */

/* Check whether running task is extended */
#if (OS_TASK == STD_ON)
#define OS_CHECK_NOT_EXTENDED_RUNNING_ERROR(LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].usType !=\
       OS_TASK_EXTENDED))\
  {\
    LenStatusReturn = E_OS_ACCESS;\
  }\
 } while(0)
#else /* End of if (OS_TASK == STD_ON) */
#define OS_CHECK_NOT_EXTENDED_RUNNING_ERROR(LenStatusReturn)
#endif /* End of if (OS_TASK == STD_ON) */

/* Check if Task owns Resource */
#if (OS_RESOURCE == STD_ON)
#define OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        ((Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].pResources)\
         != NULL_PTR))\
    {\
      LenStatusReturn = E_OS_RESOURCE;\
    }\
  }while(0)
#else /* End of if (OS_RESOURCE == STD_ON) */
#define OS_CHECK_RUNNING_OWNS_REZ_ERROR(LenStatusReturn)
#endif /* End of if (OS_RESOURCE == STD_ON) */

/* Check for Alarm ID */
#if (OS_ALARM == STD_ON)
#define OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn)\
 do {\
  if (((LenStatusReturn) == E_OK) && ((AlarmID) >= Os_Alarm_Count))\
  {\
    LenStatusReturn = E_OS_ID;\
  }\
 } while(0)
#else /* End of if (OS_ALARM == STD_ON) */
#define OS_CHECK_ALARM_ID_ERROR(AlarmID, LenStatusReturn)
#endif /* End of if (OS_ALARM == STD_ON) */

/* Checks if increment is within the range of the
 *             maximum allowed value for the counter used by the alarm */
#if (OS_ALARM == STD_ON)
#define OS_CHECK_ALARM_MAX_ALLOWED_ABS_VALUE_ERROR(AlarmID, Start,\
                                                   LenStatusReturn)\
 do {\
  if (((LenStatusReturn) == E_OK) && ((Start) >\
                                    Os_GaaStaticAlarm[(AlarmID)].pStaticCounter->\
                                    ddMaxAllowedValue))\
  {\
    LenStatusReturn = E_OS_VALUE;\
  }\
 } while(0)
#else /* End of if (OS_ALARM == STD_ON) */
#define OS_CHECK_ALARM_MAX_ALLOWED_ABS_VALUE_ERROR(AlarmID, Start,\
                                                   LenStatusReturn)
#endif /* End of if (OS_ALARM == STD_ON) */

/* Checks if cycle is greater than minimum value*/
#if (OS_ALARM == STD_ON)
#define OS_CHECK_ALARM_MIN_CYCLE_ERROR(AlarmID, Cycle, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) && ((Cycle) != 0) &&\
      (((Cycle) >\
        Os_GaaStaticAlarm[(AlarmID)].pStaticCounter->ddMaxAllowedValue) ||\
       ((Cycle) <\
        Os_GaaStaticAlarm[(AlarmID)].pStaticCounter->ddMinCycle)))\
  {\
    LenStatusReturn = E_OS_VALUE;\
  }\
 } while(0)
#else /* End of if (OS_ALARM == STD_ON) */
#define OS_CHECK_ALARM_MIN_CYCLE_ERROR(AlarmID, Cycle, LenStatusReturn)
#endif /* End of if (OS_ALARM == STD_ON) */

/* Return an error if the task that attempt to get the resource that has a
 *   higher priority than the resource or the resource is already owned by
 *   another task */
#if (OS_RESOURCE == STD_ON)
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_GET(LpResource, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (((LpResource)->pOwner != NULL_PTR) ||\
       (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ulBasePriority >\
        (uint32)((LpResource)->ulCeilingPriority))))\
  {\
    LenStatusReturn = E_OS_ACCESS;\
  }\
 } while(0)
#else /* End of if (OS_RESOURCE == STD_ON) */
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_GET(LpResource, LenStatusReturn)
#endif /* End of if (OS_RESOURCE == STD_ON) */

/* Return an error if the task that attempt to get the resource has a higher
 *   priority than the resource */
#if (OS_RESOURCE == STD_ON)
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(LpResource, LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ulBasePriority >\
       (uint32)((LpResource)->ulCeilingPriority)))\
  {\
    LenStatusReturn = E_OS_ACCESS;\
  }\
 }while(0)
#else /* End of if (OS_RESOURCE == STD_ON) */
#define OS_CHECK_RESOURCE_PRIO_ERROR_ON_RELEASE(LpResource, LenStatusReturn)
#endif /* End of if (OS_RESOURCE == STD_ON) */

/* Check the order of release */
#if (OS_RESOURCE == STD_ON)
#define OS_CHECK_RESOURCE_ORDER_ON_RELEASE(LpResource, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].pTask->pResources\
       !=\
       (LpResource)))\
  {\
    LenStatusReturn = E_OS_NOFUNC;\
  }\
 } while(0)
#else /* End of if (OS_RESOURCE == STD_ON) */
#define OS_CHECK_RESOURCE_ORDER_ON_RELEASE(LpResource, LenStatusReturn)
#endif /* End of if (OS_RESOURCE == STD_ON) */

/* Check if previous value does not exceed the maxallowedvalue of counter */
#if (OS_COUNTER == STD_ON)
#define OS_CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(CounterID, Value,\
                                                 LenStatusReturn)\
 do{ if(((LenStatusReturn) == E_OK) && \
       (*(Value) > (&Os_GaaStaticCounter[(CounterID)])->ddMaxAllowedValue))\
   {\
     LenStatusReturn = E_OS_VALUE;\
   }\
 }while(0)
#else /* End of if (OS_COUNTER == STD_ON) */
#define OS_CHECK_COUNTER_MAX_ALLOWED_VALUE_ERROR(CounterID, Value,\
                                                 LenStatusReturn)
#endif /* End of if (OS_COUNTER == STD_ON) */

/* Check whether it's hardware counter or software counter */
#if (OS_COUNTER == STD_ON)
#define OS_CHECK_COUNTER_KIND_ERROR(CounterID, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticCounter[(CounterID)].pHwCounter != NULL_PTR))\
  {\
    LenStatusReturn = E_OS_ID;\
  }\
 } while(0)
#else /* End of if (OS_COUNTER == STD_ON) */
#define OS_CHECK_COUNTER_KIND_ERROR(CounterID, LenStatusReturn)
#endif /* End of if (OS_COUNTER == STD_ON) */

/* Check whether the ScheduleTableID_To is valid or not */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_NEXT_SCHEDTABLE_ID_ERROR(ScheduleTableID_From,\
                                          ScheduleTableID_To, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        (((ScheduleTableID_From) >= Os_Schedule_Count) || \
        ((ScheduleTableID_To) >= Os_Schedule_Count)))\
    {\
      LenStatusReturn = E_OS_ID;\
    }\
  } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_NEXT_SCHEDTABLE_ID_ERROR(ScheduleTableID_From,\
                                            ScheduleTableID_To, LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/* Check whether the Offset is zero or greater than OsCounterMaxAllowedValue
 *   of the underlying counter minus Initial Offset */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_SCHEDTABLE_OFFSET_VALUE_ERROR(ScheduleTableID, Offset,\
                                               LenStatusReturn)\
 do{\
   if(((LenStatusReturn) == E_OK) && (((Offset) == 0) || ((Offset) >\
  (Os_GaaStaticSchedTable[(ScheduleTableID)].pStaticCounter->\
                                                          ddMaxAllowedValue))))\
  {\
    LenStatusReturn = E_OS_VALUE;\
  }\
 } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_SCHEDTABLE_OFFSET_VALUE_ERROR(ScheduleTableID, Offset,\
                                               LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/* Check whether the Start is greater than OsCounterMaxAllowedValue of the
 *   underlying counter */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_SCHEDTABLE_TICK_VALUE(ScheduleTableID, Start,\
                                       LenStatusReturn)\
 do{\
   if ((LenStatusReturn == E_OK) &&\
       (((Start) > (Os_GaaStaticSchedTable[(ScheduleTableID)].pStaticCounter->\
                                                       ddMaxAllowedValue))))\
   {\
     LenStatusReturn = E_OS_VALUE;\
   }\
 } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_SCHEDTABLE_TICK_VALUE(ScheduleTableID, Start, LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/* Check whether the Value is greater than OsScheduleTableDuration of the
 *   ScheduleTable */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_SCHEDTABLE_VALUE_ERROR(ScheduleTableID, Value, LenStatusReturn)\
 do{\
 if(((LenStatusReturn) == E_OK) && (((Value) == 0) || \
   ((Value) > (Os_GaaStaticSchedTable[(ScheduleTableID)].ddSchedTblDuration))))\
   {\
     LenStatusReturn = E_OS_VALUE;\
   }\
 } while(0)

#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_SCHEDTABLE_VALUE_ERROR(ScheduleTableID, Value,\
                                        LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/* Check whether the Schedule table is implicitly synchronised */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)\
  do{\
    if ((LenStatusReturn == E_OK) && \
   (Os_GaaStaticSchedTable[(ScheduleTableID)].ucSynchStrategy ==\
                                                   OS_SCHEDTABLE_IMPLICIT_SYNC))\
   {\
     LenStatusReturn = E_OS_ID;\
   }\
  } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_IMPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/* Check whether it's driving by the same counter */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_SCHEDTABLE_COUNTERS(ScheduleTableID_From,\
                                     ScheduleTableID_To, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaStaticSchedTable[(ScheduleTableID_From)].pStaticCounter !=\
       Os_GaaStaticSchedTable[(ScheduleTableID_To)].pStaticCounter))\
  {\
    LenStatusReturn = E_OS_ID;\
  }\
 } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_SCHEDTABLE_COUNTERS(ScheduleTableID_From,\
                                     ScheduleTableID_To, LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#if(OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_NEXT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID_From,\
                                            ScheduleTableID_To,LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) &&\
       (Os_GaaStaticSchedTable[(ScheduleTableID_From)].ucSynchStrategy !=\
        Os_GaaStaticSchedTable[(ScheduleTableID_To)].ucSynchStrategy))\
   {\
     LenStatusReturn = E_OS_ID;\
   }\
 } while(0)
#else
#define OS_CHECK_NEXT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID_From,\
                                            ScheduleTableID_To,LenStatusReturn)
#endif
/* Check whether the Schedule table is explicitly synchronised */
#if (OS_SCHEDTABLE == STD_ON)
#define OS_CHECK_EXPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) && \
  (Os_GaaStaticSchedTable[(ScheduleTableID)].ucSynchStrategy ==\
                                    OS_SCHEDTABLE_EXPLICIT_SYNC))\
  {\
    LenStatusReturn = E_OS_ID;\
  }\
 } while(0)
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_EXPLICIT_SCHEDTABLE_STRATEGY_ERROR(ScheduleTableID,\
                                                    LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

/*Spinlock Id error*/
#define OS_CHECK_SPINLOCK_ID_ERROR(SpinlockId, LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) && ((SpinlockId) > Os_Spinlock_Count))\
   {\
     LenStatusReturn = E_OS_ID;\
   }\
 } while(0)

/*Check the status of the spinlock*/
#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_SPINLOCK_STATUS_ERROR(SpinlockId, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaSpinlock[(SpinlockId)].ddTaskId != OS_INVALID_VALUE))\
  {\
    if (Os_GaaStaticTask[Os_GaaSpinlock[(SpinlockId)].ddTaskId].ddCoreId ==\
        OS_CORE_ID)\
    {\
      LenStatusReturn = E_OS_INTERFERENCE_DEADLOCK;\
    }\
  }\
 } while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_SPINLOCK_STATUS_ERROR(SpinlockId, LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*Check the deadlock situation for the spinlock*/
#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_SPINLOCK_DEADLOCK_ERROR(SpinlockId, LpTask,\
                                         LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      ((LpTask)->ddSpinlock != OS_ZERO) &&\
      (((LpTask)->ddSpinlock > (SpinlockId)) ||\
       (((LpTask)->ddSpinlock) <\
        (Os_GaaStaticSpinlock[(SpinlockId)].ulMinSpinID)) ||\
      (((LpTask)->ddSpinlock) > (Os_GaaStaticSpinlock[(SpinlockId)].ulMaxSpinID))))\
  {\
    LenStatusReturn = E_OS_NESTING_DEADLOCK;\
  }\
 } while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_SPINLOCK_DEADLOCK_ERROR(SpinlockId, LpTask, LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*Check the state of the Spinlock*/
#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_SPINLOCK_STATE_ERROR(SpinlockId, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      ((Os_GaaSpinlock[(SpinlockId)].ddTaskId == OS_INVALID_VALUE) ||\
       (Os_GaaSpinlock[(SpinlockId)].ddTaskId !=\
        Os_GpLinkTask[OS_CORE_ID]->ddTaskID)))\
  {\
    LenStatusReturn = E_OS_STATE;\
  }\
 } while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_SPINLOCK_STATE_ERROR(SpinlockId, LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*Check the order of release of the Spinlock*/
#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_SPINLOCK_RELEASE_ORDER_ERROR(SpinlockId, LenStatusReturn)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      (Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock !=\
       (SpinlockId)))\
  {\
    LenStatusReturn = E_OS_NOFUNC;\
  }\
 } while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_SPINLOCK_RELEASE_ORDER_ERROR(SpinlockId, LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*Check the access of the Spinlock*/
#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_SPINLOCK_ACCESS_ERROR(SpinlockId, LulMask, LulSpinMask,\
                                       LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) && (((LulSpinMask) & (LulMask)) == OS_FALSE))\
   {\
     LenStatusReturn = E_OS_ACCESS;\
   }\
 } while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_SPINLOCK_ACCESS_ERROR(SpinlockId, LulMask, LulSpinMask,\
                                       LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

#if (OS_SPINLOCK == STD_ON)
#define OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) &&\
       ((Os_GaaTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID].ddSpinlock) !=\
        OS_ZERO))\
   {\
     LenStatusReturn = E_OS_SPINLOCK;\
   }\
 }while(0)
#else /* End of if (OS_SPINLOCK == STD_ON) */
#define OS_CHECK_RUNNING_OWNS_SPINLOCK_ERROR(LenStatusReturn)
#endif /* End of if (OS_SPINLOCK == STD_ON) */

/*Check the StartCore Order*/
#if (OS_MULTICORE == STD_ON)
#define OS_CHECK_STARTCORE_ORDER_ERROR(CoreID, LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) && (Os_GblStartOs[(CoreID)] == OS_TRUE))\
   {\
     LenStatusReturn = E_OS_ACCESS;\
   }\
 } while(0)
#else /* End of if (OS_MULTICORE == STD_ON) */
#define OS_CHECK_STARTCORE_ORDER_ERROR(CoreID, LenStatusReturn)
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*Check if the Core has already started*/
#if (OS_MULTICORE == STD_ON)
#define OS_CHECK_CORE_ALREADY_STARTED_ERROR(CoreID, LenStatusReturn)\
do{\
 if (((LenStatusReturn) == E_OK) && (Os_GaaCore[(CoreID)].blCoreStatus == OS_TRUE))\
  {\
    LenStatusReturn = E_OS_STATE;\
  }\
} while(0)
#else /* End of if (OS_MULTICORE == STD_ON) */
#define OS_CHECK_CORE_ALREADY_STARTED_ERROR(CoreID, LenStatusReturn)
#endif /* End of if (OS_MULTICORE == STD_ON) */

#if (OS_TRUSTED_FUNC_COUNT != OS_PRE_ZERO)
#define OS_CHECK_TRUSTED_FUNCTION_INDEX(FunctionIndex, LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) && ((FunctionIndex) > Os_Trusted_Func_Count))\
   {\
     LenStatusReturn = E_OS_SERVICEID;\
   }\
 } while(0)
#define OS_CHECK_TRUSTED_FUNCTION_CORE(FunctionIndex, LenStatusReturn)\
 do{\
   if (((LenStatusReturn) == E_OK) && \
 		  (OS_CORE_ID != Os_GaaTrustedFunction[(FunctionIndex)].ddCoreID))\
   {\
     LenStatusReturn = E_OS_ACCESS;\
   }\
 } while(0)
#else
#define OS_CHECK_TRUSTED_FUNCTION_INDEX(FunctionIndex, LenStatusReturn)
#define OS_CHECK_TRUSTED_FUNCTION_CORE(FunctionIndex, LenStatusReturn)
#endif


#if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
#define OS_CHECK_ISR_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, IsrID)\
  do{\
    if(((LenStatusReturn)  == E_OK) && \
    ((OS_FULLACCESS & (Os_GaaStaticApplication \
    [Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask)) == OS_FALSE))\
    {\
      LenStatusReturn = E_OS_ACCESS;\
    }\
  } while(0)
#define OS_CHECK_ISR_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, IsrID, \
                                                                    RemoteCall)\
  do{\
    if((LenStatusReturn == E_OK) && \
      (((RemoteCall == OS_TRUE) ||\
         (Os_GaaStaticIsr[(IsrID)].ddAppId != Os_GddAppId[OS_CORE_ID])) &&\
         ((Os_GaaApplication[Os_GaaStaticTask[(IsrID)].ddAppId].ddState & 0x0F) != \
                                                  APPLICATION_ACCESSIBLE)))\
    {\
      LenStatusReturn = E_OS_ACCESS;\
    }\
  } while(0)

#else /* End of if ((OS_SCALABILITY_CLASS == SC3)||
                                              (OS_SCALABILITY_CLASS == SC4)) */
#define OS_CHECK_ISR_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, IsrID)
#define OS_CHECK_ISR_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, IsrID, \
                                                                     RemoteCall)
#endif /* End of if ((OS_SCALABILITY_CLASS == SC3)||
                                              (OS_SCALABILITY_CLASS == SC4)) */

#if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, ResID)\
  do{\
    if(((LenStatusReturn) == E_OK) && \
    ((Os_GaaResourceTable[(ResID)].ddAppAccesMask & (Os_GaaStaticApplication \
             [Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask)) == OS_FALSE))\
    {\
      LenStatusReturn = E_OS_ACCESS;\
    }\
  }while(0)
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, ResID,\
                                                                    RemoteCall)\
  do{\
    if(((LenStatusReturn) == E_OK) && \
      ((((RemoteCall) == OS_TRUE) || \
        (Os_GaaResourceTable[(ResID)].ddAppId != Os_GddAppId[OS_CORE_ID])) &&\
          ((Os_GaaApplication[Os_GaaResourceTable[(ResID)].ddAppId].ddState &0x0F)\
            != APPLICATION_ACCESSIBLE)))\
    {\
      LenStatusReturn = E_OS_ACCESS;\
    }\
  } while(0)

#else /* End of if ((OS_SCALABILITY_CLASS == SC3)||
                                              (OS_SCALABILITY_CLASS == SC4)) */
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, ResID)
#define OS_CHECK_RESOURCE_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, ResID,\
                                                                     RemoteCall)
#endif /* End of if ((OS_SCALABILITY_CLASS == SC3)||
                                              (OS_SCALABILITY_CLASS == SC4)) */

#if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
#define OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId)\
  do{\
    if(((LenStatusReturn) == E_OK) && \
    ((Os_GaaSpinlock[(SpinlockId)].ulAppAccessMask & (Os_GaaStaticApplication \
             [Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask)) == OS_FALSE))\
    {\
      LenStatusReturn = E_OS_ACCESS;\
  }\
 } while(0)
#else
#define OS_CHECK_SPINLOCK_APPLICATION_ACCESS(LenStatusReturn,SpinlockId)
#endif /* End of if (OS_SCALABILITY_CLASS > OS_SC2) */

/*Check the Object type*/
#define OS_CHECK_OBJECT_TYPE_ERROR(ObjectType, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) && ((ObjectType) > OBJECT_SCHEDULETABLE))\
    {\
      LenStatusReturn = NO_ACCESS;\
    }\
  } while(0)
/*Check the Object access Application ID*/
#define OS_CHECK_OBJ_ACCESS_APPL_ID_ERROR(Application, LenStatusReturn)\
  do{ if(((LenStatusReturn) == E_OK) && ((Application) >= Os_Application_Count))\
    {\
      LenStatusReturn = NO_ACCESS;\
    }\
  } while(0)
/* Check if Application ID is valid */
#define OS_CHECK_APPL_ID_ERROR(Application, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) && ((Application) >= Os_Application_Count))\
    {\
      LenStatusReturn = E_OS_ID;\
    }\
  } while(0)
#define OS_CHECK_APPLICATION_STATE(LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) && \
    ((Os_GaaApplication[Os_GddAppId[OS_CORE_ID]].ddState &\
                           (ApplicationStateType)0x0F)!= APPLICATION_RESTARTING))\
    {\
      LenStatusReturn = E_OS_STATE;\
    }\
  } while(0)

/* Error for OS507 */
#define OS_CHECK_APPL_TERMINATED_STATE_ERROR(Application, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        ((Os_GaaApplication[(Application)].ddState) == APPLICATION_TERMINATED))\
    {\
      LenStatusReturn = E_OS_STATE;\
    }\
  } while(0)
/* Error for OS508 */
#define OS_CHECK_APPL_CALLER_ACCESS_ERROR(Application, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        ((Os_GaaApplication[(Application)].ddState & (ApplicationStateType)0x0F) ==\
                                                       APPLICATION_RESTARTING) &&\
        ((Os_GddAppId[OS_CORE_ID] != (Application))))\
    {\
      LenStatusReturn = E_OS_STATE;\
    }\
  } while(0)
/* Error for OS548 */
#define OS_CHECK_APPL_RESTART_STATE_ERROR(Application,\
                                          LenStatusReturn, RestartOption)\
 do{\
  if (((LenStatusReturn) == E_OK) &&\
      ((Os_GaaApplication[(Application)].ddState & (ApplicationStateType)0x0F) ==\
                                                     APPLICATION_RESTARTING) &&\
      (Os_GddAppId[OS_CORE_ID] == (Application)) && ((RestartOption) == RESTART))\
  {\
    LenStatusReturn = E_OS_STATE;\
  }\
 } while(0)
/* Error for OS459 */
#define OS_CHECK_RESTART_VALUE_ERROR(LenStatusReturn, RestartOption)\
 do{\
  if (((LenStatusReturn) == E_OK) && ((RestartOption) >= OS_TWO))\
  {\
    LenStatusReturn = E_OS_VALUE;\
  }\
 } while(0)

#if (OS_APPLICATION == STD_ON)
/* Check if IOC ID is invalid */
#define OS_CHECK_IOC_ID_ERROR(IocID, IocCount, LenStatusReturn)\
  do{\
    if ((IocID) >= (IocCount))\
    {\
      LenStatusReturn = IOC_E_NOK;\
    }\
    else\
    {\
      LenStatusReturn = IOC_E_OK;\
    }\
  } while(0)
/* Check if IOC buffer is invalid (null pointer) */
#define OS_CHECK_IOC_INVALID_BUF_ERROR(IocBuf, LenStatusReturn)\
  do{\
    if (((LenStatusReturn) == E_OK) &&\
        ((IocBuf) == NULL_PTR))\
    {\
      LenStatusReturn = IOC_E_NOK;\
    }\
    else\
    {\
      LenStatusReturn = IOC_E_OK;\
    }\
  } while(0)
#else
#define OS_CHECK_IOC_ID_ERROR(IocID, IocCount, LenStatusReturn)
#define OS_CHECK_IOC_INVALID_BUF_ERROR(IocBuf, LenStatusReturn)
#endif

#endif /* end of #if (OS_STATUS == STANDARD) */



/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
extern FUNC(StatusType, OS_CODE) Os_CheckObjIDError(
                           ObjectTypeType ObjectType, ObjectTypeIndex ObjectID);

/* polyspace:begin<MISRA-C3:8.10:Not a defect:Justify with annotations> inline function is verified manually */
/* Check interrupts are not disabled */
static inline FUNC(void, OS_CODE) OS_CHECK_INTERRUPT_LOCK(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<RTE:UNR:Not a defect:Justify with annotations> check status */
  if ((*LpStatusReturn == E_OK) &&
      ((Os_GblISRLock[OS_CORE_ID] == OS_TRUE)
       #if (OS_ISR_COUNT >= OS_PRE_ONE)
       || (Os_GddISRLock[OS_CORE_ID] > OS_ZERO)
       || (Os_GddISR2Lock[OS_CORE_ID] > OS_ZERO)
       #endif
      ))
  {
    *LpStatusReturn = E_OS_DISABLEDINT;
  }
  /* polyspace:end<RTE:UNR> */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
}

/* Check call level */
static inline FUNC(void, OS_CODE) Os_CheckCallevel(uint16 LusCallevel,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if (*LpStatusReturn == E_OK)
  {
    /* polyspace<MISRA-C:10.1:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    /* polyspace<MISRA-C:12.6:Not a defect:Justify with annotations> This code is verified manually and has no impact */
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if ((OS_IN_CAT1() == OS_TRUE) ||
        (((Os_GusCallevelCheck[OS_CORE_ID]&(uint16)(~LusCallevel))
          &OS_CONTEXT_MASK) != OS_ZERO))
    {
      *LpStatusReturn = E_OS_CALLEVEL;
    }
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */
  }
}

/** Function for set kernel mode */
static inline FUNC(void, OS_CODE) OS_SET_KERNEL_FLAG(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  Os_GucInKernel[OS_CORE_ID]++;
}

/** Function for clear kernel mode */
static inline FUNC(void, OS_CODE) OS_CLEAR_KERNEL_FLAG(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  Os_GucInKernel[OS_CORE_ID]--;
}

#if (OS_CALLBACK_COUNT > OS_PRE_ZERO)
static inline FUNC(void, OS_CODE) OS_PROCESS_ALARMCALLBACK(P2FUNC(void, OS_VAR, AlarmCallBack)(void))
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  OS_SET_KERNEL_FLAG();
  Os_GusCallevelCheck[OS_CORE_ID] |= OS_CONTEXT_ALARMCALLBACK;
  /* polyspace +2 RTE:COR [Justified:Medium] "function ptr points to a valid function and code is manually checked" */
  AlarmCallBack();
  Os_GusCallevelCheck[OS_CORE_ID] &= ((uint16)(~(uint16)OS_CONTEXT_ALARMCALLBACK));
  OS_CLEAR_KERNEL_FLAG();
}
#else
#define OS_PROCESS_ALARMCALLBACK()
#endif

#if (OS_STATUS == EXTENDED)

/* Check whether task is in suspended state */
#if (OS_TASK == STD_ON)
static inline FUNC(void, OS_CODE) OS_CHECK_SUSPENDED_TASK_ERROR(TaskType TaskID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  /* polyspace<RTE: UNR : Not a defect : No Action Planned > Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if (((*LpStatusReturn) == E_OK))
  {
    if ((Os_GaaTask[(TaskID)].ddState == SUSPENDED) ||
        (Os_GaaTask[(TaskID)].ddState == OS_TASK_UNINITIALIZED))
    {
      *LpStatusReturn = E_OS_STATE;
    }
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
}
#else /* End of if (OS_TASK == STD_ON) */
#define OS_CHECK_SUSPENDED_TASK_ERROR(TaskID, LenStatusReturn)
#endif /* End of if (OS_TASK == STD_ON) */

#if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO)
static inline FUNC(void, OS_CODE) OS_CHECK_ISR_ID_ERROR(ISRType IsrID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  if ((*LpStatusReturn == E_OK) &&
      ((IsrID >= (Os_Task_Count + Os_CAT2_ISR_Count + Os_Core_Count)) ||
       (IsrID < (Os_Task_Count + Os_Core_Count))))
  {
    *LpStatusReturn = E_OS_ID;
  }
}
#else /* End of if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO) */
#define OS_CHECK_ISR_ID_ERROR(IsrID, LenStatusReturn)
#endif /* if (OS_CAT2_ISR_COUNT > OS_PRE_ZERO) */

/* Checks if alarm is in use already */
#if (OS_ALARM == STD_ON)
static inline FUNC(void, OS_CODE) OS_CHECK_ALARM_INUSE_ERROR(AlarmType AlarmID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  /* polyspace:begin<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  if ((*LpStatusReturn == E_OK) &&
      (Os_GaaStaticAlarm[(AlarmID)].pCounter->blAlarmInUse == (boolean)OS_TRUE))
  /* polyspace:end<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  {
    *LpStatusReturn = E_OS_SYS_ALARM_INUSE;
  }
  /* polyspace-end MISRA-C3:18.1 */
}
#else /* End of if (OS_ALARM == STD_ON) */
#define OS_CHECK_ALARM_INUSE_ERROR(AlarmID, LenStatusReturn)
#endif /* End of if (OS_ALARM == STD_ON) */

#if (OS_RESOURCE == STD_ON)
/* Check whether ResID is greater than number of Resource count */
static inline FUNC(void, OS_CODE) OS_CHECK_RESOURCE_ID_ERROR(ResourceType ResID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  if ((*LpStatusReturn == E_OK) && (ResID >= OS_Resource_Count))
  {
    *LpStatusReturn = E_OS_ID;
  }
}
#else /* End of if (OS_RESOURCE == STD_ON) */
#define OS_CHECK_RESOURCE_ID_ERROR(ResID, LenStatusReturn)
#endif /* End of if (OS_RESOURCE == STD_ON) */

#if (OS_COUNTER == STD_ON)
/* Check whether CounterId is greater than number of Counter count */
static inline FUNC(void, OS_CODE) OS_CHECK_COUNTER_ID_ERROR(CounterType CounterID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  if ((*LpStatusReturn == E_OK) && (CounterID >= Os_Counter_Count))
  {
    *LpStatusReturn = E_OS_ID;
  }
}

/* Checks if a Counter is in use already */
static inline FUNC(void, OS_CODE) OS_CHECK_COUNTER_INUSE_ERROR(CounterType CounterID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  /* polyspace:begin<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((*LpStatusReturn == E_OK) &&
       (Os_GaaStaticCounter[CounterID].pCounter->blAlarmInUse == (boolean)TRUE))
  /* polyspace:end<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
  {
    *LpStatusReturn = E_OS_SYS_ALARM_INUSE;
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:D4.14> */
  /* polyspace:end<MISRA-C3:18.1> */
}
#else /* End of if (OS_COUNTER == STD_ON) */
#define OS_CHECK_COUNTER_ID_ERROR(CounterID, LenStatusReturn)
#define OS_CHECK_COUNTER_INUSE_ERROR(CounterID, LenStatusReturn)
#endif /* End of if (OS_COUNTER == STD_ON) */

#if (OS_SCHEDTABLE == STD_ON)
/* Check whether the ScheduleTableID is valid or not */
inline FUNC(void, OS_CODE) OS_CHECK_SCHEDTABLE_ID_ERROR(
                                              ScheduleTableType ScheduleTableID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  if ((*LpStatusReturn == E_OK) && (ScheduleTableID >= Os_Schedule_Count))
  {
    *LpStatusReturn = E_OS_ID;
  }
}

/* Checks if a related Schedule Table is in use already */
inline FUNC(void, OS_CODE) OS_CHECK_SCHEDTABLE_INUSE_ERROR(
                                              ScheduleTableType ScheduleTableID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  if ((*LpStatusReturn == E_OK) &&
      (Os_GaaStaticAlarm[Os_GaaStaticSchedTable[ScheduleTableID].ddAlarmIndex]
       .pCounter->blAlarmInUse))
  {
    *LpStatusReturn = E_OS_SYS_ALARM_INUSE;
  }
  /* polyspace-end MISRA-C3:18.1 */
}
#else /* End of if (OS_SCHEDTABLE == STD_ON) */
#define OS_CHECK_SCHEDTABLE_ID_ERROR(ScheduleTableID, LenStatusReturn)
#define OS_CHECK_SCHEDTABLE_INUSE_ERROR(ScheduleTableID, LenStatusReturn)
#endif /* End of if (OS_SCHEDTABLE == STD_ON) */

#if (OS_MULTICORE == STD_ON)
/* Check whether the CoreID is valid or not */
inline FUNC(void, OS_CODE) OS_CHECK_CORE_ID_ERROR(CoreIDType CoreID,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  if ((*LpStatusReturn == E_OK) && (CoreID >= Os_Core_Count))
  {
    *LpStatusReturn = E_OS_ID;
  }
}
#else /* End of if (OS_MULTICORE == STD_ON) */
#define OS_CHECK_CORE_ID_ERROR(CoreID, LenStatusReturn)
#endif /* End of if (OS_MULTICORE == STD_ON) */

#if (OS_SCALABILITY_CLASS > OS_SC2)
static inline FUNC(void, OS_CODE) OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(
        P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn, TaskType LddTaskId)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((*LpStatusReturn == E_OK) &&
      ((Os_GaaStaticTask[LddTaskId].ddAppAccesMask &
       Os_GaaStaticApplication[Os_GddAppId[OS_CORE_ID]].usAppMask) == OS_FALSE))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
}

/* polyspace<MISRA-C3:5.1:Not a defect:Justify with annotations> macro is unique */
static inline FUNC(void, OS_CODE) OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(
        P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn, TaskType LddTaskId,
                                boolean LblRemoteCall)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((*LpStatusReturn == E_OK) &&
       (((LblRemoteCall == OS_TRUE) ||
         (Os_GaaStaticTask[LddTaskId].ddAppId != Os_GddAppId[OS_CORE_ID])) &&
        ((Os_GaaApplication[Os_GaaStaticTask[LddTaskId].ddAppId].ddState &
                        (ApplicationStateType)0x0F) > APPLICATION_ACCESSIBLE)))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
}
#else /* Else of if (OS_SCALABILITY_CLASS > OS_SC2) */
#define OS_CHECK_TASK_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn,TaskID)
#define OS_CHECK_TASK_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn,TaskID,\
                                            RemoteCall)    OS_UNUSED(RemoteCall)
#endif /* End of (OS_SCALABILITY_CLASS > OS_SC2) */

#if((OS_SCALABILITY_CLASS > OS_SC2) && (OS_TRUSTED_START_INDX != OS_ZERO))
static inline FUNC(void, OS_CODE) OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                                              AlarmType AlarmID)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  /* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((*LpStatusReturn == E_OK) &&
      ((Os_GaaStaticAlarm[(AlarmID)].ddAppAccesMask &
      (Os_GaaStaticApplication[Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask))
                                                                   == OS_FALSE))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
  /* polyspace:end<RTE:NIV> */
  /* polyspace:end<MISRA-C3:D4.14> */
}

static inline FUNC(void, OS_CODE) OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                                              AlarmType AlarmID,
                                                             boolean RemoteCall)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> index is valid and verified manually */
  if ((*LpStatusReturn == E_OK) &&
      (((RemoteCall == OS_TRUE) ||
        (Os_GaaStaticAlarm[AlarmID].ddAppId != Os_GddAppId[OS_CORE_ID])) &&
       ((Os_GaaApplication[Os_GaaStaticAlarm[AlarmID].ddAppId].ddState
                                     & (uint8)0x0F) != APPLICATION_ACCESSIBLE)))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
  /* polyspace:end<MISRA-C3:D4.14> */
}

static inline FUNC(void, OS_CODE) OS_CHECK_CALLER_APPLICATION_ERROR(
                                              ApplicationType TargetApplication,
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  if (((*LpStatusReturn) == E_OK) &&
       (Os_GaaStaticApplication[Os_GddAppId[OS_CORE_ID]].ucType ==
        OS_NON_TRUSTED) &&
       (Os_GddAppId[OS_CORE_ID] != (TargetApplication)))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
}

static inline FUNC(void, OS_CODE) OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                                          CounterType CounterID)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  /* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> index is valid and verified manually */
  if(((*LpStatusReturn) == E_OK) &&
    ((Os_GaaStaticCounter[(CounterID)].ddAppAccesMask & (Os_GaaStaticApplication
               [Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask)) == OS_FALSE))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
  /* polyspace:end<RTE:NIV> */
  /* polyspace:end<MISRA-C3:D4.14> */
}

static inline FUNC(void, OS_CODE) OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                                          CounterType CounterID,
                                                             boolean RemoteCall)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> index is valid and verified manually */
  if(((*LpStatusReturn) == E_OK) &&
        (((RemoteCall == OS_TRUE) ||
          (Os_GaaStaticCounter[(CounterID)].ddAppId != Os_GddAppId[OS_CORE_ID])) &&
    ((Os_GaaApplication[Os_GaaStaticCounter[(CounterID)].ddAppId].ddState & (uint8)0x0F)!=
                                                        APPLICATION_ACCESSIBLE)))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
  /* polyspace:end<MISRA-C3:D4.14> */
}

static inline FUNC(void, OS_CODE) OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                              ScheduleTableType ScheduleTableID)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  if(((*LpStatusReturn) == E_OK) && ((Os_GaaStaticAlarm
    [Os_GaaStaticSchedTable[(ScheduleTableID)].ddAlarmIndex].ddAppAccesMask &
    (Os_GaaStaticApplication[Os_GpStaticTask[OS_CORE_ID]->ddAppId].usAppMask))
    == OS_FALSE))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
}

static inline FUNC(void, OS_CODE) OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(
                            P2VAR(StatusType, AUTOMATIC, OS_VAR) LpStatusReturn,
                                              ScheduleTableType ScheduleTableID,
                                                             boolean RemoteCall)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "index is valid and verified manually" */
  if(((*LpStatusReturn) == E_OK) &&
        (((RemoteCall == OS_TRUE) ||
    (Os_GaaStaticAlarm[Os_GaaStaticSchedTable[(ScheduleTableID)].ddAlarmIndex].ddAppId
    != Os_GddAppId[OS_CORE_ID])) &&
         ((Os_GaaApplication[Os_GaaStaticAlarm[Os_GaaStaticSchedTable
       [(ScheduleTableID)].ddAlarmIndex].ddAppId].ddState & 0x0Fu) !=
                                                       APPLICATION_ACCESSIBLE)))
  {
    *LpStatusReturn = E_OS_ACCESS;
  }
  /* polyspace-end MISRA-C3:18.1 */
}
#else
#define OS_CHECK_ALARM_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, AlarmID)
#define OS_CHECK_ALARM_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, AlarmID, \
                                            RemoteCall)    OS_UNUSED(RemoteCall)
#define OS_CHECK_CALLER_APPLICATION_ERROR(TargetApplication, LpStatusReturn)
#define OS_CHECK_COUNTER_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, CounterID)
#define OS_CHECK_COUNTER_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, \
                                 CounterID, RemoteCall)    OS_UNUSED(RemoteCall)
#define OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_SELF_CORE(LenStatusReturn, \
                                                                ScheduleTableID)
#define OS_CHECK_SCHEDTABLE_APPLICATION_ACCESS_CROSS_CORE(LenStatusReturn, \
                                                    ScheduleTableID, RemoteCall)
#endif /* End of if((OS_SCALABILITY_CLASS > OS_SC2) &&
                                          (OS_TRUSTED_START_INDX != OS_ZERO)) */
/* polyspace:end<MISRA-C3:D4.1> */

#endif /* if (OS_STATUS == EXTENDED) */
#endif /* OS_ERROR_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Inline functions are needed for performance and Macro definitions are needed for performance and file size  */
/* polyspace:end<MISRA-C:8.1:Not a defect:Justify with annotations> Prototype declaration of inline function is not needed */
/* polyspace:end<MISRA-C:8.5:Not a defect:Justify with annotations> Inline functions should be implemented in header file  */
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
/* polyspace:end<MISRA-C:19.10:Not a defect:Justify with annotations> Left operand cannot be enclosed in parentheses */
/* polyspace:end<RTE : IDP :Not a defect:Justify with annotations> configured memory access index */
/* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
/* polyspace-end CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
