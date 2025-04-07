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
**  SRC-MODULE: Os_Arch_Context.c                                             **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of port specific functionality                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.4.0     20-Aug-2021    YH.Han        Redmine #31652                      **
** 2.0.0     08-Jul-2020    JH.Cho        Redmine #24316                      **
** 1.1.0     10-Mar-2020    MJ.Woo        Redmine #22057, #22193              **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "Pointer not access out of array" */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_Application.h"       /* Os Application header file */
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"  /* Os TimerProtection header file */
#endif
#include "Os_Arch_Interrupt.h"
#include "Os_Task.h"
#include "Os_Stack.h"
#include "Os_Arch_Context.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_API_CODE
#include "MemMap.h"

#if (OS_APP_MEMBLK_CNT != OS_ZERO)
static FUNC(void, OS_CODE) Os_EndOfTask(void);
#endif

/***************************************************************************//**
 * Function             : Os_ErrorTerminateTask
 *
 * Service ID           : OSServiceId_Os_ErrorTerminateTask
 *
 * Description          : This function is called when Task
 *                        terminated without TerminateTask()
 *                        This function process E_OS_MISSINGEND
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameter            : None
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
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
/* polyspace +2 MISRA-C3:8.7 [Not a defect:Low] "External visible function" */
FUNC(void, OS_CODE) Os_ErrorTerminateTask(void)
{
  OS_SYSCALL_ERRORTERMINATETASK();
}

/*****************************************************************************
 * Function             : Os_EndOfTask
 *
 * Service ID           : NA
 *
 * Description          : This function is called when non-trusted Task
 *                        terminated without TerminateTask()
 *                        Switch to supervisor mode and process E_OS_MISSINGEND
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameter            : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_ErrorTerminateTask()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
static FUNC(void, OS_CODE) Os_EndOfTask(void)
{
  Os_ErrorTerminateTask();
}

#define OS_STOP_SEC_API_CODE
#include "MemMap.h"

#define OS_START_SEC_CODE
#include "MemMap.h"
/*****************************************************************************
 * Function Name        : Os_ReInitContext
 *
 * Service ID           : NA
 *
 * Description          : This service is used to initialize context
 *                        from LpStaticTask
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LpStaticTask : Pointer of Task/ISR info
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
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ReInitContext(P2CONST(
                           Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  LpStaticTask->pContext->ulLR = (uint32)&Os_EndOfTask;
  LpStaticTask->pContext->ulPSR = OS_TASK_INIT_PSR;
  LpStaticTask->pContext->ulPC  = (uint32)LpStaticTask->pFuncEntry;
  LpStaticTask->pContext->ulEXC_RETURN = OS_EXC_RETURN_THREAD_MODE;
  #if (OS_FPU_SUPPORT == STD_ON)
  LpStaticTask->pContext->ulFPSCR = Os_GddTaskInitFPSCR;
  #endif
}

/*******************************************************************************
 * Function             : Os_Dispatch
 *
 * Service ID           : NA
 *
 * Description          : This function is used to dispatch new Task
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameter            : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticTask, Os_GpLinkTask, Os_GucInKernel
 *
 *                        Function(s) invoked    :
 *                        Os_RunTask(), Os_DoContextSwitch(),
 *                        Os_SetTaskStackPointer()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) Os_Dispatch(void)
{

  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if (OS_APP_MEMBLK_CNT != OS_ZERO)
  uint32 LulCtrl;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Get new Task */
  /* polyspace<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
  LpStaticTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];


  /* Os_RunTask() */
  Os_GucInKernel[OS_CORE_ID]++;
  Os_SetTaskStackPointer();
  Os_RunTask();
  Os_GucInKernel[OS_CORE_ID]--;

  #if (OS_APP_MEMBLK_CNT != OS_ZERO)
  LulCtrl = __MRS(__CONTROL);
  /* If Application is non-trusted, set privileged mode to user */
  if (LpStaticTask->ddAppId < (ApplicationType)Os_Trusted_Start_Indx)
  {
	/* CTRL.nPRIV = 1 which means Thread mode has unprivileged access */
    LulCtrl |= 0x00000001u;
  }
  else
  {
	/* CTRL.nPRIV = 0 which means Thread mode has privileged access */
    LulCtrl &= 0xFFFFFFFEu;
  }
  __MSR(__CONTROL, LulCtrl);
  #endif

  /* Context-Switch */
  Os_DoContextSwitch(LpStaticTask->pContext);
}

/***************************************************************************//**
 * Function Name        : Os_SetTaskStackPointer
 *
 * Service ID           : NA
 *
 * Description          : This service is used to set basic task or CAT2
 *                        Isr's stack base address
 *                        base address
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOs() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GpStaticTask, Os_GaaStaticTask, Os_GulOsAppSP,
 *                        Os_GulUserSP, Os_GaaStack
 *
 *                        Function(s) invoked    :
 *                        Os_GetStackPointer
 *
 * {Ref: SWR_OS_SPC58xx_006}
 *
 * @ingroup               OS_SPC58xx_ESDD_003
 *******************************************************************************/
FUNC(void, OS_CODE) Os_SetTaskStackPointer(void)
{
  /* Type of stacks                                                          */
  /*                                                                         */
  /* 1. system stack        : used by start-up code, OS kernel               */
  /* 2. user stack          : used by Basic Task (without OS-Application),   */
  /*                          Os_sleep Task (without/with OS-Application)    */
  /* 3. application stack   : used by Basic Task (with OS-Application)       */
  /* 4. extended task stack : used by extended task                          */

  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpPreTask;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpRunTask;
  #if (OS_EVENT == STD_ON)
  P2CONST(Tdd_Os_Stack, AUTOMATIC, OS_CONST) LpTaskStack;
  #endif

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  uint16 LusStackSize;
  uint32 LulUserSP;
  uint32 LulOsAppSP;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  LpPreTask = Os_GpStaticTask[OS_CORE_ID];
  /* polyspace +2 RTE:NIV [Justified:Medium] "Variable initialized at other location" */
  LpRunTask = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];

  if(LpPreTask != LpRunTask)
  {
    /* Basic task is preempted by other task */
    /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
    /* polyspace +3 RTE:NIV [Justified:Medium] "Variable initialized at other location" */
    if((LpPreTask->usType == OS_TASK_BASIC) &&
                                           (LpPreTask->pTask->ddState == READY))
    /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
    {
      /* polyspace-begin MISRA-C3:11.6 [Justified:Medium] "To save address data" */
      #if (OS_APPLICATION == STD_ON)
      if(LpPreTask->ddTaskId != OS_CORE_ID)
      {
        /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
        Os_GulOsAppSP[LpPreTask->ddAppId] =
                                        (uint32)Os_GetStackPointer(LpPreTask);
      }
      else
      #endif
      {
        Os_GulUserSP[OS_CORE_ID] = (uint32)Os_GetStackPointer(LpPreTask);
      }
      /* polyspace-end MISRA-C3:11.6 */
    }
  }
  if(LpRunTask->usType == OS_TASK_BASIC)
  {
    /* Task to be run is new task */
    /* polyspace +2 RTE:NIV [Justified:Medium] "Variable initialized at other location" */
    if(LpRunTask->pTask->ddState == OS_READY_AND_NEW)
    {
      #if (OS_APPLICATION == STD_ON)
      if(LpRunTask->ddTaskId != OS_CORE_ID)
      {
        /* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
        /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
        /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        LpRunTask->pContext->pPowerOnSP =
          (Os_StackType*)Os_GulOsAppSP[LpRunTask->ddAppId];
        LulOsAppSP = (uint32)((Os_StackType*)Os_GulOsAppSP[LpRunTask->ddAppId]);
        LpRunTask->pContext->ulSP =
         (uint32)(LulOsAppSP - (OS_STACK_RSVD_SIZE * sizeof(Os_StackType)));
        /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
        /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        /* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
      }
      else
      #endif
      {
        /* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion is need" */
        LpRunTask->pContext->pPowerOnSP = (Os_StackType*)Os_GulUserSP[OS_CORE_ID];
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "It is used for consistency" */
        /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
        /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        LulUserSP = (uint32)((Os_StackType*)Os_GulUserSP[OS_CORE_ID]);
        /* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion is need" */
        LpRunTask->pContext->ulSP =
         (uint32)(LulUserSP - (OS_STACK_RSVD_SIZE * sizeof(Os_StackType)));
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "It is used for consistency" */
        /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      }
    }
    /* Task to be run is previously preempted task */
    else if((LpRunTask->pTask->ddState == READY) ||
                                         (LpRunTask->pTask->ddState == RUNNING))
    {
      /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
      #if (OS_APPLICATION == STD_ON)
      if(LpRunTask->ddTaskId != OS_CORE_ID)
      {
        /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
        Os_GulOsAppSP[LpRunTask->ddAppId] =
                                        (uint32)LpRunTask->pContext->pPowerOnSP;
      }
      else
      #endif
      {
        Os_GulUserSP[OS_CORE_ID] = (uint32)LpRunTask->pContext->pPowerOnSP;
      }
      /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
    }
    else
    {
      /* Do nothing */
    }
  }
  else if(LpRunTask->usType == OS_ISR2)
  {
    /* polyspace:begin<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
    #if (OS_APPLICATION == STD_ON)
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    Os_GulOsAppSP[LpRunTask->ddAppId] = (uint32)LpRunTask->pContext->pPowerOnSP;
    #else
    Os_GulUserSP[OS_CORE_ID] = (uint32)LpRunTask->pContext->pPowerOnSP;
    #endif
    /* polyspace:end<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
  }
  else /* if(LpRunTask->usType == OS_TASK_EXTENDED) */
  {
    #if (OS_EVENT == STD_ON)
    /* polyspace +2 RTE:NIV [Justified:Medium] "Variable initialized at other location" */
    if(LpRunTask->pTask->ddState == OS_READY_AND_NEW)
    {
      /* Make Task's context for new Task */
      LpTaskStack = &Os_GaaStack[LpRunTask->ucStackIndex];
      /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
  	  LusStackSize = LpTaskStack->usStackSize - OS_STACK_RSVD_SIZE;
      LpRunTask->pContext->ulSP =
                   (uint32)(&LpTaskStack->pStackArea[LusStackSize]);
      /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
      /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
    }
    #endif
  }
} /* FUNC(void, OS_CODE) Os_SetTaskStackPointer(void) */

/*****************************************************************************
 * Function Name        : Os_GetStackPointer
 *
 * Service ID           : NA
 *
 * Description          : This service is used to get stack pointer
 *                        from LpStaticTask
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LpStaticTask : Pointer of Task/ISR info
 *
 * @return              : Stack pointer
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
/* polyspace +2 MISRA-C3:20.7 [Justified:Low] "AUTOSAR compiler abstraction" */
FUNC(uint32*, OS_CODE) Os_GetStackPointer(P2CONST(
    Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  P2VAR(uint32, AUTOMATIC, OS_VAR) LpStackaddress;

  /* polyspace<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
  /* polyspace +3 RTE:NIP [Justified:Medium] "ptr points to a valid value and code is verified manually" */
  /* polyspace +2 MISRA-C3:11.6 [Justified:Medium] "To handle address data" */
  /* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion is need" */
  LpStackaddress = (uint32*)LpStaticTask->pContext->ulSP;
  /* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion is need" */

  if(LpStackaddress == (uint32*)0u)
  {
    /* polyspace +2 MISRA-C3:11.6 [Justified:Medium] "To indicate invalid address" */
    LpStackaddress = (uint32*)INVALID_STACK_POINTER;
  }

  return (LpStackaddress);
} /* End of Os_GetStackPointer(P2CONST( */

/*****************************************************************************
 * Function Name        : Os_GetStackSize
 *
 * Service ID           : NA
 *
 * Description          : This service is used to get current task's stack size
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpStaticTask : Pointer of Task/ISR info
 *
 * @return              : Stack Size
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStack
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
#if (OS_STACK_MONITORING == STD_ON)
FUNC(uint16, OS_CODE) Os_GetStackSize(P2CONST(
    Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  /* - user stack frame              */
  /*   : 8 bytes is reserved for     */
  /*     terminating task            */
  /* |--------------|                */
  /* |      LR      | -> reserved    */
  /* |--------------|                */
  /* |      BC      | -> reserved    */
  /* |--------------|                */
  /* |      ...     |                */
  /* |--------------|                */
  /* |      LR      |                */
  /* |--------------|                */
  /* |      BC      |                */
  /* |--------------|                */

  uint16 LusStackSize;

  if((LpStaticTask->usType == OS_TASK_BASIC) ||
     (LpStaticTask->usType == OS_TASK_EXTENDED))
  {
    /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> Configured array index */
    if(Os_GaaStack[LpStaticTask->ucStackIndex].usStackSize >
                                                     (uint16)OS_STACK_RSVD_SIZE)
    {
      LusStackSize = (Os_GaaStack[LpStaticTask->ucStackIndex].usStackSize)
    		  - (uint16)OS_STACK_RSVD_SIZE;
    }
    else
    /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
    {
      LusStackSize = (uint16)OS_ZERO;
    }
  }
  else
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Although it is unreachable code, fail-safety code is necessary. */
  {
    /* polyspace<RTE:OBAI:Not a defect:Justify with annotations> Configured array index */
    LusStackSize = (Os_GaaStack[LpStaticTask->ucStackIndex].usStackSize);
  }

  return (LusStackSize);
} /* End of Os_GetStackPointer(P2CONST( */
#endif /* End of if (OS_STACK_MONITORING == STD_ON) */

/*****************************************************************************
 * Function Name        : OS_REMOVECONTEXT
 *
 * Service ID           : NA
 *
 * Description          : This service is used to removing used context
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpStaticTask : Pointer of Task/ISR info
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
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_003
 ******************************************************************************/
#if ((OS_PROTECTION_HOOK == STD_ON) || (OS_APPLICATION == STD_ON))
FUNC(void, OS_CODE) OS_REMOVECONTEXT(P2CONST(
                           Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask)
{
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> configured variable */
  if (LpStaticTask->usType == OS_ISR2)
  {
    #if 0 /* jsjang_remove */
    /* Write 0 to INTC_EOIR0 to restore priority of preempted ISR */
    OS_INTC_EOIR0 = (uint32)OS_ZERO;
    #endif
  }
  /* polyspace:end<MISRA-C3:D4.14> */
}
#endif

/***************************************************************************//**
 * Function Name        : OS_STARTUPCONTEXT
 *
 * Service ID           : NA
 *
 * Description          : This service is used to load the context only of the first Task
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
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
 *
 * {Ref: SWR_OS_S32K14X_006}
 *
 * @ingroup               OS_S32K14X_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) OS_STARTUPCONTEXT(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  OS_GET_CORE_ID(OS_CORE_ID);
  
  Os_GucSchedReq[OS_CORE_ID] = CONTEXT_SWITCHING_STARTUP;
}

/***************************************************************************//**
 * Function Name        : OS_LOADCONTEXT
 *
 * Service ID           : NA
 *
 * Description          : This service is used to load the context
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
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
 *
 * {Ref: SWR_OS_S32K14X_006}
 *
 * @ingroup               OS_S32K14X_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) OS_LOADCONTEXT(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  OS_GET_CORE_ID(OS_CORE_ID);
  
  Os_GucSchedReq[OS_CORE_ID] = CONTEXT_SWITCHING_LOAD;
}

/***************************************************************************//**
 * Function Name        : OS_SAVECONTEXT
 *
 * Service ID           : NA
 *
 * Description          : This service is used to save the context
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
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
 *
 * {Ref: SWR_OS_S32K14X_006}
 *
 * @ingroup               OS_S32K14X_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) OS_SAVECONTEXT(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  OS_GET_CORE_ID(OS_CORE_ID);
  
  Os_GucSchedReq[OS_CORE_ID] = CONTEXT_SWITCHING_SAVE;
}

/***************************************************************************//**
 * Function Name        : OS_RELOADCONTEXT
 *
 * Service ID           : NA
 *
 * Description          : This service is used to reload the context
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
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
 *
 * {Ref: SWR_OS_S32K14X_006}
 *
 * @ingroup               OS_S32K14X_ESDD_003
 ******************************************************************************/
FUNC(void, OS_CODE) OS_RELOADCONTEXT(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  OS_GET_CORE_ID(OS_CORE_ID);
  
  Os_GucSchedReq[OS_CORE_ID] = CONTEXT_SWITCHING_RELOAD;
}

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-end MISRA-C3:18.1 */
/* polyspace:end<MISRA-C3:18.4:Not a defect:Justify with annotations> Operators on pointer is used for better performance */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
