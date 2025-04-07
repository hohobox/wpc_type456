/*******************************************************************************
**                            HYUNDAI MOTORS GROUP                            **
**                                                                            **
**                            All rights reserved                             **
**                                                                            **
**            You can NOT use this sample code for Product Release            **
*******************************************************************************/
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#include "App_OsHook.h"
#include "EcuM.h"
#include "Os_Arch_Regs.h"
#if (OS_ERRM_USED == STD_ON)
#include "ErrM.h"
#endif
#include "Opf_OsProfiler.h"
#define T1AD_ENABLE_FUNCTION STD_OFF

#if(T1AD_ENABLE_FUNCTION == STD_ON)
#include "T1Ad.h"
#include "T1_AppInterface.h"
#define T1_ENABLE_WAITEVENT  STD_OFF
#endif
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

FUNC(void, OS_CODE) ErrorHook(StatusType Error)
{
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OS_MULTICORE == STD_ON)
  CoreIDType LddCoreId = GetCoreID();
  #endif
  /* Do not modify : Start */
  if (E_OS_LIMIT == Error)
  {
    #if (OPF_PROFILE_ENABLED == STD_ON)
    #if (OPF_MULTICORE_ENABLED == STD_ON)
    if (LddCoreId <= OS_CORE_TWO)
    #else
    #if (OS_MULTICORE == STD_ON)
    if (LddCoreId == OS_CORE_ZERO)
    #endif
    #endif
    {
      Opf_SetLimitErrorEvent();
    }
    #endif
  }
  #endif
  AppCallbackOnSystemError(Error);
  /* Do not modify : End */
}

FUNC(void, OS_CODE) PreTaskHook(void)
{
}

FUNC(void, OS_CODE) PostTaskHook(void)
{
}

FUNC(void, OS_CODE) StartupHook(void)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OS_MULTICORE == STD_ON)
  CoreIDType LddCoreId = GetCoreID();
  #else
  CoreIDType LddCoreId = (CoreIDType)OS_ZERO;
  #endif

  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_InitOsProfiler();
    Opf_StartOsProfiler();
  }
  #endif

  #if (OS_DEBUG_STACKDEPTH == STD_ON)
  Os_FillStackPattern();
  #endif

  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_InitCPULoad();
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_IsrEntryHook(CoreIDType LddCoreId, ISRType LddIsrId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetPreIsrEvent();
  }
  #endif

  /* CPU/Interrupt load */
  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ITEntryForCPULoad();
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    T1_START_Hook( LddCoreId, T1_START, LddIsrId);
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_IsrExitHook(CoreIDType LddCoreId, ISRType LddIsrId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetPostIsrEvent();
  }
  #endif

  /* CPU/Interrupt load */
  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ITExitForCPULoad();
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    T1_STOP_Hook( LddCoreId, T1_STOP, LddIsrId);
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) ShutdownHook(StatusType Error)
{
  /* Do not modify : Start */
  AppCallbackOnSystemError(Error);
  EcuM_Shutdown();
  /* Do not modify : End */
}

FUNC(void, OS_CODE) AppCallbackOnSystemError(StatusType ErrorId)
{
  if (ErrorId == E_OS_SYS_RAMECC)
  {
    /* RAM ECC Error occurred!!
     * All global variables are cleared before call this callback */
  }
  else
  {
    /* Do not modify : Start */
    Os_UpdateOsErrorInfo(ErrorId);
    #if (OS_ERRM_USED == STD_ON)
    ErrM_OsErrorNotification(ErrorId); // nidec modify
    #endif
    /* Do not modify : End */
  }
}

FUNC(void, OS_CODE) Os_TaskActivationHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_ACTIVATED);
  }
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    T1_ACTIVATION_Hook( LddCoreId, T1_ACTIVATION, LddTaskId);
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskTerminationHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_SUSPENDED);
  }
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    T1_STOP_Hook(LddCoreId, T1_STOP, LddTaskId);
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskPreemptionHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_READY);
  }
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskRunningHook(CoreIDType LddCoreId, TaskType LddTaskId, TaskStateType LddTaskState)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  OpfRecModeType LddOpfMode;
  LddOpfMode = Opf_GetOsProfilerRecMode();

  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    /* Check restart */
    if (LddOpfMode == OPF_RECMODE_RESTART)
    {
      Opf_RestartOsProfiler();
    }
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_RUNNING);
  }
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    if(LddTaskState == OS_READY_AND_WAITING)
      #if(T1_ENABLE_WAITEVENT == STD_ON)
        T1_RESUME_Hook(LddCoreId, T1_RESUME, LddTaskId);
      #else
        T1_START_Hook(LddCoreId, T1_START, LddTaskId);
      #endif
    else if(LddTaskState == OS_READY_AND_NEW)
      T1_START_Hook(LddCoreId, T1_START, LddTaskId);
  #endif  /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskWaitingHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_WAITING);
  }
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    #if(T1_ENABLE_WAITEVENT == STD_ON)
      T1_WAIT_Hook(LddCoreId, T1_WAIT, LddTaskId); // <-- 2019.07.04 inwon.kang edit from MDS
    #else
      T1_STOP_Hook(LddCoreId, T1_STOP, LddTaskId);
    #endif
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskReleaseHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
  /* Do not modify : Start */
  #if (OPF_PROFILE_ENABLED == STD_ON)
  #if (OPF_MULTICORE_ENABLED == STD_ON)
  if (LddCoreId <= OS_CORE_TWO)
  #else
  #if (OS_MULTICORE == STD_ON)
  if (LddCoreId == OS_CORE_ZERO)
  #endif
  #endif
  {
    Opf_SetTaskEvent((OpfTaskIDType)LddTaskId, OPF_TASK_READY);
  }
  #endif

  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
    #if(T1_ENABLE_WAITEVENT == STD_ON)
      T1_RELEASE_Hook(LddCoreId, T1_RELEASE, LddTaskId);
    #else
      T1_ACTIVATION_Hook(LddCoreId, T1_ACTIVATION, LddTaskId);
    #endif
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_TaskKillHook(CoreIDType LddCoreId, TaskType LddTaskId)
{
}

FUNC(void, OS_CODE) Os_IsrKillHook(CoreIDType LddCoreId, ISRType LddIsrId)
{
  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_ITExitForCPULoad();
  #endif
}

FUNC(void, OS_CODE) Os_IdleEntryHook(CoreIDType LddCoreId)
{
  /* Do not modify : Start */
  /* T1 Integration */
  #if(T1AD_ENABLE_FUNCTION == STD_ON)
  	T1_AppBackgroundHandler();
  #endif /* T1 Integration */
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_IdleExitHook(CoreIDType LddCoreId)
{
}

FUNC(void, OS_CODE) Os_PreRamInitCallout(void)
{
}

FUNC(void, OS_CODE) Os_PostRamInitCallout(void)
{
  /* Do not modify : Start */
  #if (OS_FPU_SUPPORT == STD_ON)
  OS_SCB_CPACR.B.CP10 = OS_SCB_CPACR_CP10_FULL_ACCESS;
  OS_SCB_CPACR.B.CP11 = OS_SCB_CPACR_CP11_FULL_ACCESS;

  OS_FPU_FPCCR.B.LSPEN = OS_FPU_FPCCR_LSPEN_DISABLE;
  OS_FPU_FPCCR.B.ASPEN = OS_FPU_FPCCR_ASPEN_DISABLE;

  __DSB();
  __ISB();
  #endif
  /* Do not modify : End */
}

FUNC(void, OS_CODE) Os_MeasureCPULoadRun(void)
{
  /* Do not modify : Start */
  #if (OS_DEBUG_CPULOAD == STD_ON)
  Os_MeasureCPULoad();
  #endif
  /* Do not modify : End */
}

FUNC(ProtectionReturnType, OS_CODE) ProtectionHook(StatusType Fatalerror)
{
  ProtectionReturnType LddReturn;

  LddReturn = PRO_SHUTDOWN;

  /* Do not modify : Start */
  if (LddReturn != PRO_SHUTDOWN)
  {
    AppCallbackOnSystemError(Fatalerror);
  }

  return LddReturn;
  /* Do not modify : End */
}

#define OS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

