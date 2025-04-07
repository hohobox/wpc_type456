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
**  SRC-MODULE: Os_Arch_Interrupt.c                                           **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of interrupt specific functionality                 **
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
** 2.0.1     10-AUG-2020    JH.Cho        Redmine #24903                      **
** 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917 #24316               **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIP:Not a defect:Justify with annotations> Initialized at other location */
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:begin<RTE:SHF:Not a defect:Justify with annotations> Calculated access to outside bounds */
/* polyspace:begin<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "Pointer not access out of array" */
/* polyspace:begin<MISRA-C3:18.4:Not a defect:Justify with annotations> Operators on pointer is used for better performance */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Interrupt.h"
#include "Os_Arch_Multicore.h"
#include "Os_Arch_Context.h"
#include "Os_Ram.h"
#include "Os_Error.h"
#include "Os_Interrupt.h"         /* Os Interrupt header file */
#if (OS_RES_INT_SHARE == STD_ON)
#include "Os_Resource.h"
#endif
#if(OS_STACK_MONITORING == STD_ON)
#include "Os_Stack.h"
#endif
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"
#endif
#if ((OS_MEMORY_PROTECTION == STD_ON) && (OS_APP_MEMBLK_CNT != OS_ZERO))
#include "Os_Arch_MemPro.h"
#endif

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*****************************************************************************
 * Function             : Os_CAT2ISRHandler
 *
 * Service ID           : NA
 *
 * Description          : This function is used to handle Category2 interrupt
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LulIsrIdx : Index of Task/ISR info struct
 *
 * @return              : 1 - context-switch is necessary,
 *                        0 - context-switch is not necessary
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaStaticTask, Os_GpStaticTask,
 *                        Os_GpLinkTask, Os_GucNestingCAT2ISR,
 *                        Os_GusCallevelCheck, Os_GddISR2Lock, Os_GddISRLock,
 *                        Os_GblISRLock
 *
 *                        Function(s) invoked    :
 *                        ISR_OsIsrxx (CAT2 interrupt service routine)
 *                        Os_CheckStack(), Os_ReleaseResourceService(),
 *                        Os_SetTaskStackPointer()
 *
 * {Ref: SWR_OS_CYTXXX_001}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
FUNC(uint8, OS_CODE) Os_CAT2ISRHandler(uint32 LulIsrIdx, uint32 LulNestOnEntry)
{
  register P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpNewISR;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpNewTaskISR;
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpPrevTaskISR;
  P2VAR(Tdd_Os_LinkTask, AUTOMATIC, OS_VAR) LpNewList;

  uint32 LulOldKernelSP;
  uint32 LulISRSP;
  uint32 LulISRSP_Sub;
  uint8 LucIsrReturn = OS_ZERO;
  uint16 LusCallevelCat2Isr = (uint16)OS_CONTEXT_CAT2ISR;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if (OS_RES_INT_SHARE == STD_ON)
  Os_OldLevel_T defaultPriority;
  #endif

  /* Get core ID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /** 1. Save Preempted Task */
  LpPrevTaskISR = Os_GpStaticTask[OS_CORE_ID];

  #if (OS_STACK_MONITORING == STD_ON)
  /* Call function to check if stack has overflowed */
  if(LulNestOnEntry == OS_ZERO)
  {
    Os_CheckStack(LpPrevTaskISR);
  }
  #endif

  LpNewISR = &Os_GaaStaticTask[LulIsrIdx];

  #if (OS_ISR_TP_TF == STD_ON)
  /* Start Time frame*/
  Os_StartTimeFrame(LpNewISR);
  #endif

  #if (OS_ISR_TP_EB == STD_ON)
  /* Call a function to Pause Execution budget */
  Os_PauseTimingProtection();

  /* Start execution budget monitoring*/
  if (LpNewISR->pStaticTimProtection != NULL_PTR)
  {
    TickType LddRequestedTime;

    LddRequestedTime = LpNewISR->pStaticTimProtection->ddExecutionBudget;
    if (LddRequestedTime != OS_ZERO)
    {
      Os_StartMonitor(LddRequestedTime, OS_EXEC_BUDGET,
          LpNewISR->pStaticTimProtection->ucTaskExeBudgetIndex);
    }
  } /* End of if (LpCurrentTask->pStaticTimProtection != NULL_PTR) */
  #endif

  /** 2. Insert new ISR into Ready Queue */
  LpNewList = LpNewISR->pLinkTask;
  LpNewList->pLinkList = Os_GpLinkTask[OS_CORE_ID];
  Os_GpLinkTask[OS_CORE_ID] = LpNewList;

  /** 3. Update Os_GpStaticTask and it's state */
  Os_GpStaticTask[OS_CORE_ID] = LpNewISR;
  Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = RUNNING;

  /* Update the currently running Application */
  #if(OS_APPLICATION == STD_ON)
  Os_GddAppId[OS_CORE_ID] = LpNewISR->ddAppId;
  #endif

  /* Increment the cat2 nesting count */
  Os_GucNestingCAT2ISR[OS_CORE_ID]++;
  if(Os_GucNestingCAT2ISR[OS_CORE_ID] == OS_ONE)
  {
    Os_GusCallevelCheck[OS_CORE_ID] |= LusCallevelCat2Isr;
  }

  #if (OS_PROFILING_HOOK == STD_ON)
  Os_GucInKernel[OS_CORE_ID]++;
  Os_IsrEntryHook(OS_CORE_ID, LpNewISR->ddTaskId);
  Os_GucInKernel[OS_CORE_ID]--;
  #endif

  /** 4. Change to user stack */
  LulOldKernelSP = Os_GulKernelSP[OS_CORE_ID];

  if ((LpPrevTaskISR->usType == OS_TASK_BASIC) ||
      (LpPrevTaskISR->usType == OS_ISR2))
  {
    /* polyspace-begin MISRA-C3:11.6 [Justified:Medium] "To save address data" */
    #if (OS_APPLICATION == STD_ON)
    if (LpPrevTaskISR->ddTaskId != OS_CORE_ID)
    {
      Os_GulOsAppSP[LpPrevTaskISR->ddAppId] = (uint32)Os_GetStackPointer(LpPrevTaskISR) - OS_CONTEXT_SIZE;
    }
    else
    #endif
    {
      Os_GulUserSP[OS_CORE_ID] = (uint32)Os_GetStackPointer(LpPrevTaskISR) - OS_CONTEXT_SIZE;
    }
    /* polyspace-end MISRA-C3:11.6 */
  }
  #if (OS_APPLICATION == STD_ON)
  LulISRSP = (uint32)Os_GulOsAppSP[LpNewISR->ddAppId];
  #else
  LulISRSP = (uint32)Os_GulUserSP[OS_CORE_ID];
  #endif

  /* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion is need" */
  LpNewISR->pContext->pPowerOnSP = (Os_StackType *)LulISRSP;
  LulISRSP_Sub = (uint32)((Os_StackType *)LulISRSP);
  /* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion is need" */
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "It is used for consistency" */
  LulISRSP = (uint32)(LulISRSP_Sub - OS_STACK_RSVD_SIZE * sizeof(uint32));
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "It is used for consistency" */
  LpNewISR->pContext->ulSP = LulISRSP;
  Os_GulKernelSP[OS_CORE_ID] = (uint32)Os_GetMSP();
  Os_SetMSP(LulISRSP);

  /** 5. Run CAT2 ISR
   *  - CAT2 ISR should be in a trusted OS applications for SC3/SC4 */
  OS_ENABLEINTERRUPTS();
  /* polyspace<RTE:COR:Not a defect:Justify with annotations> Function pointer initialized at other location */
  LpNewISR->pFuncEntry();
  OS_DISABLEINTERRUPTS();

  /** 6. Change to kernel stack */
  Os_SetMSP(Os_GulKernelSP[OS_CORE_ID]);
  Os_GulKernelSP[OS_CORE_ID] = LulOldKernelSP;

  #if (OS_PROFILING_HOOK == STD_ON)
  Os_GucInKernel[OS_CORE_ID]++;
  Os_IsrExitHook(OS_CORE_ID, LpNewISR->ddTaskId);
  Os_GucInKernel[OS_CORE_ID]--;
  #endif

  /* Decrement the cat2 nesting count */
  Os_GucNestingCAT2ISR[OS_CORE_ID]--;
  if(Os_GucNestingCAT2ISR[OS_CORE_ID] == OS_ZERO)
  {
    LusCallevelCat2Isr = ~LusCallevelCat2Isr;
    Os_GusCallevelCheck[OS_CORE_ID] &= LusCallevelCat2Isr;
  }

  #if (OS_STACK_MONITORING == STD_ON)
  /* Call function to check if stack has overflowed */
  Os_CheckStack(LpNewISR);
  #endif

  #if (OS_ISR_TP_EB == STD_ON)
  Os_StopExecutionBudget(LpNewISR);
  #endif

  /* FIXME: Not solved nested interrupt API situation */
  /* Check if interrupts are disabled */
  #if (OS_ISR_COUNT != OS_ZERO)
  #if (OS_CAT2_ISR_COUNT != OS_ZERO)
  if (Os_GddISR2Lock[OS_CORE_ID] != OS_ZERO)
  {
    Os_GddISR2Lock[OS_CORE_ID] = OS_ONE;
    /* restore the previous state */
    ResumeOSInterrupts();

    #if (OS_ERROR_HOOK == STD_ON)
    OS_PROCESS_ERROR(E_OS_DISABLEDINT);
    #endif
  }
  #endif
  if (Os_GddISRLock[OS_CORE_ID] != OS_ZERO)
  {
    if(Os_GblISRLock[OS_CORE_ID] == OS_TRUE){
      EnableAllInterrupts();
    }else{
      while(Os_GddISRLock[OS_CORE_ID] != OS_ZERO){
        ResumeAllInterrupts();
      }
    }
    #if (OS_ERROR_HOOK == STD_ON)
    OS_PROCESS_ERROR(E_OS_DISABLEDINT);
    #endif
  }
  #endif

  /* TODO: Please add test: Exit ISR without ReleaseResource when nested Resource */
  #if (OS_RES_INT_SHARE == STD_ON)
  if (LpNewISR->pTask->pResources != NULL_PTR)
  {
    defaultPriority = (Os_OldLevel_T)OS_INT_MIN_PRIORITY;
    Os_ResumeInterrupts(&defaultPriority);
    /* restore the previous state */
    Os_ReleaseResourceService(LpNewISR);
    #if (OS_ERROR_HOOK == STD_ON)
    OS_PROCESS_ERROR(E_OS_RESOURCE);
    #endif
  }
  #endif

  LpNewTaskISR = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];

  /** 7. Remove CAT2 ISR from Ready Queue if the ISR is not terminated
   *     by Stack Monitoring */
  if(LpNewISR == LpNewTaskISR)
  {
    Os_GpStaticTask[OS_CORE_ID]->pTask->ddState = SUSPENDED;
    LpNewList = Os_GpLinkTask[OS_CORE_ID]->pLinkList;
    Os_GpLinkTask[OS_CORE_ID] = LpNewList;

    LpNewTaskISR = &Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID];
  }

  /** 8. If there's higher priority Task, return non-zero */
  /** 9. If there's not higher priority Task, return zero */
  if(LulNestOnEntry == OS_ZERO)
  {
    if((LpNewTaskISR->usType != OS_ISR2) &&
       (LpPrevTaskISR->usType != OS_ISR2) &&
       (LpNewTaskISR != LpPrevTaskISR))
    {
      /* context-switch is necessary */
      #if (OS_MEMORY_PROTECTION == STD_ON)
      if(LpPrevTaskISR->pTask->ddState != SUSPENDED)
      #endif
      {
        #if (OS_POSTTASK_HOOK == STD_ON)
        /* Process PostTaskHook */
        OS_PROCESS_POSTTASKHOOK();
        #endif
        LpPrevTaskISR->pTask->ddState = READY;
        #if (OS_PROFILING_HOOK == STD_ON)
        /* FIXME: Need Os_GucInKernel[OS_CORE_ID]++; ??? */
        /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        Os_TaskPreemptionHook(OS_CORE_ID, LpPrevTaskISR->ddTaskId);
        /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "The function works differently depending on whether OsProfiler is used and whether Multi-Core is used" */
        #endif
      }

      LucIsrReturn = OS_ONE;
    }
    else
    {
      /* context-switch is not necessary */
      Os_GpStaticTask[OS_CORE_ID] = LpNewTaskISR;
      /* Restore previous Task or CAT2 ISR's stack base address */
      Os_SetTaskStackPointer();
      /* Update the currently running Application */
      #if(OS_APPLICATION == STD_ON)
      Os_GddAppId[OS_CORE_ID] = LpNewTaskISR->ddAppId;
      #endif

      #if ((OS_ISR_TP_EB == STD_ON) || (OS_TASK_TP_EB == STD_ON))
      if(LpNewTaskISR->pStaticTimProtection != NULL_PTR)
      {
        /* Continue Execution budget */
        Os_ContinueTimingProtection(LpNewTaskISR);
      }
      #endif /* End of if (OS_ISR_TP_EB == STD_ON) */
    }
  }
  else
  {
    /* Restore Os_GpStaticTask[OS_CORE_ID] */
    Os_GpStaticTask[OS_CORE_ID] = LpPrevTaskISR;
  }

  return LucIsrReturn;
}

#if (OS_ISR_COUNT != OS_PRE_ZERO)
/*****************************************************************************
 * Function             : Os_IntSetEnable
 * Service ID           : NA
 * Description          : Enable System Interrupt (external interrupts)
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * @param [in]          : intrNum - core irq input line number
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
FUNC(void, OS_CODE) Os_IntSetEnable(uint32 intrNum)
{
  uint32 irqNum;
  volatile uint32 *irqEnSetAddr = (volatile uint32 *)OS_ARM_M_IRQ_EN_SET_START;

  irqNum = intrNum;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  while ((irqNum >= 32U) && (irqEnSetAddr < (uint32 *) OS_ARM_M_IRQ_EN_SET_END))
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  {
      irqNum -= 32U;
      irqEnSetAddr++;
  }
  *((volatile uint32 *) (irqEnSetAddr)) = ((uint32) 1 << irqNum); /* Write 0 has no effect */
}

/*****************************************************************************
 * Function             : Os_IntSetDisable
 * Service ID           : NA
 * Description          : Disable System Interrupt (external interrupts)
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * @param [in]          : intrNum - core irq input line number
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 * {Ref: SWR_OS_S32K_003}
 *
 * @ingroup               OS_S32K_ESDD_002
 ******************************************************************************/
/* polyspace-begin MISRA-C3:D4.14 [Not a defect:Medium] "Not received from external source" */
FUNC(void, OS_CODE) Os_IntSetDisable(uint32 intrNum)
{
  uint32 irqNum;
  volatile uint32 *irqEnSetAddr = (volatile uint32 *)OS_ARM_M_IRQ_EN_CLR_START;
  
  irqNum = intrNum;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  while ((irqNum >= 32U) && (irqEnSetAddr < (uint32 *) OS_ARM_M_IRQ_EN_CLR_END))
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  {
      irqNum -= 32U;
      irqEnSetAddr++;
  }
  *((volatile uint32 *) (irqEnSetAddr)) = ((uint32) 1 << irqNum); /* Write 0 has no effect */
}
/* polyspace-end MISRA-C3:D4.14 */

/*****************************************************************************
 * Function             : Os_IntClearPend
 * Service ID           : NA
 * Description          : Clear System Interrupt pending state(external interrupts)
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * @param [in]          : intrNum - core irq input line number
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
FUNC(void, OS_CODE) Os_IntClearPend(uint32 intrNum)
{
  uint32 irqNum;
  volatile uint32 *irqEnSetAddr = (volatile uint32 *)OS_ARM_M_IRQ_CLEAR_PENDING_START;

  irqNum = intrNum;
  /* polyspace-begin MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  while ((irqNum >= 32U) && (irqEnSetAddr < (uint32 *) OS_ARM_M_IRQ_CLEAR_PENDING_END))
  /* polyspace-end MISRA-C3:2.2 [Not a defect:Low] "This code depends on MCU package" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > This code depends on MCU package */
  {
      irqNum -= 32U;
      irqEnSetAddr++;
  }
  *((volatile uint32 *) (irqEnSetAddr)) = ((uint32) 1 << irqNum); /* Write 0 has no effect */
}

/*****************************************************************************
 * Function             : Os_SetISRPriority
 *
 * Service ID           : NA
 *
 * Description          : This function is called to initialize interrupt
 *                        requests and set the priorities of interrupts
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GaaISRIndex, Os_GaaISRPriority
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_002}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
FUNC(void, OS_CODE) Os_SetISRPriority(void)
{
  P2CONST(Tdd_Os_ISRPriority, AUTOMATIC, OS_CONST) LpISRPriority;
  P2CONST(Tdd_Os_ISRIndex, AUTOMATIC, OS_CONST) LpISRIndex;
  uint8 LucIsrCount;
  uint16 isrNumber;
  uint8 LucIdxICER;
  volatile uint32 *LpIrqClrSetAddr;
  CONSTP2VAR(OS_NVIC_IPR_type, OS_CONST, REGSPACE) NVIC_IPR_ADDR =
                                        (OS_NVIC_IPR_type *)OS_ARM_M_IRQ_IPR_START;
  /* Address of the priority register for OS HW Counter(SysTick) */
  /* polyspace +2 MISRA-C3:20.7 [Justified:Low] "AUTOSAR compiler abstraction" */
  CONSTP2VAR(volatile uint32, REGSPACE, OS_CONST) OS_HW_COUNTER_PRI_ADDR = OS_SHPR3_ADDR;
  /* LSB of Priority of system handler 15(SysTick exception) in SHPR3 */
  CONST(uint32, OS_CONST) OS_HW_COUNTER_PRI_SHIFT = 29u;
  uint32 LulISRPrioryti_Sub;

  LpISRIndex = &Os_GaaISRIndex[Os_MyCore()];
  LucIsrCount = LpISRIndex->ucIsrCount;
  LpISRPriority = &Os_GaaISRPriority[LpISRIndex->ucIsrStartIdx];

  /* Disable all IRQ (NVIC_ICER0[31:0] ~ NVIC_ICER14[31:0], NVIC_ICER15[15:0]) */
  LucIdxICER = OS_ZERO;
  LpIrqClrSetAddr = (volatile uint32 *)OS_ARM_M_IRQ_EN_CLR_START;
  while (LucIdxICER < 15)
  {
    *LpIrqClrSetAddr = 0xFFFFFFFFu;
    LpIrqClrSetAddr++;
    LucIdxICER++;
  }
  *LpIrqClrSetAddr = 0x0000FFFFu;

  while (LucIsrCount != OS_ZERO)
  {
    if (LpISRPriority->pICRAddress == OS_HW_COUNTER_PRI_ADDR)
    {
      /* Set SysTick exception priority */
      LulISRPrioryti_Sub = ((uint32)LpISRPriority->usISRPriorityMask << OS_HW_COUNTER_PRI_SHIFT);
      *(LpISRPriority->pICRAddress) |= LulISRPrioryti_Sub;
    }
    else
    {
      /** Configure the mapping of system interrupt to one of the eight external
       *  ARM Coretex-M CPU interrupts according to interrupt priority. */
      *(LpISRPriority->pICRAddress) = LpISRPriority->usISRPriorityMask;
      /** Enable the system interrupt */
      *(LpISRPriority->pICRAddress) |= OS_MASK_CPU_INT_VALID;
    }

    /* MISRA Rule   : 17.4
     *   Message      : Increment or decrement operation performed on pointer.
     *   Reason       : Increment operator used to achieve better throughput.
     *   Verification : However, part of the code is verified manually
     *                  and it is not having any impact.
     */
    LpISRPriority++;
    LucIsrCount--;
  }

  /** Set NVIC Priority of IRQ */
  /* polyspace-begin MISRA-C3:13.2 [Justified:Medium] "It's verified no side effect" */
  /* External Interrupt (IRQ0 ~ IRQ7) */
  NVIC_IPR_ADDR[ 0u] = 0u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 1u] = 1u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 2u] = 2u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 3u] = 3u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 4u] = 4u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 5u] = 5u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 6u] = 6u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 7u] = 7u << OS_IPR_LSB;
  /* Internal (software only) Interrupt (IRQ8 ~ IRQ15) */
  NVIC_IPR_ADDR[ 8u] = 0u << OS_IPR_LSB;
  NVIC_IPR_ADDR[ 9u] = 1u << OS_IPR_LSB;
  NVIC_IPR_ADDR[10u] = 2u << OS_IPR_LSB;
  NVIC_IPR_ADDR[11u] = 3u << OS_IPR_LSB;
  NVIC_IPR_ADDR[12u] = 4u << OS_IPR_LSB;
  NVIC_IPR_ADDR[13u] = 5u << OS_IPR_LSB;
  NVIC_IPR_ADDR[14u] = 6u << OS_IPR_LSB;
  NVIC_IPR_ADDR[15u] = 7u << OS_IPR_LSB;
  /* polyspace-end MISRA-C3:13.2 */

  /** Enable NVIC IRQ */
  for (isrNumber = 0u; isrNumber < OS_ARM_M_NUM_NVIC_EXTERNAL; isrNumber++)
  {
    Os_IntClearPend(isrNumber);
    Os_IntSetEnable(isrNumber);
  }
}
#endif /* End of #if (OS_ISR_COUNT != OS_PRE_ZERO) */

/*****************************************************************************
 * Function             : Os_RaisePriority
 *
 * Service ID           : NA
 *
 * Description          : This function is called to raise priority.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpResource Pointer of Resource structure
 * @param [in]            LulHwPrio  Hardware Priority that to be raised
 *
 * @return              : New Priority
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_002}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
#if (OS_RES_INT_SHARE == STD_ON)
FUNC(uint32, OS_CODE) Os_RaisePriority
        (P2VAR(Tdd_Os_Resource, AUTOMATIC, OS_VAR) LpResource, uint32 LulHwPrio)
{
  uint32 LulCurPrio;
  uint32 LulNewPrio;

  LulCurPrio = Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
  LulCurPrio >>= OS_IPR_LSB;

  LulNewPrio = LulCurPrio;
  LpResource->ulOwnerPrevHwPrio = LulCurPrio;
  if ((LulCurPrio == 0U) || (LulHwPrio < LulCurPrio))
  {
    LulNewPrio = LulHwPrio;
    /* Set new priority */
    (void)Os_SetInterruptPriority(LulHwPrio << OS_IPR_LSB);
  }
  else
  {
    /* Restore original priority */
    (void)Os_SetInterruptPriority(LulCurPrio << OS_IPR_LSB);
  }
  __ISB();

  return LulNewPrio;
}
#endif

/*****************************************************************************
 * Function             : Os_OriginalPriority
 *
 * Service ID           : NA
 *
 * Description          : This function is called to enable interrupts
 *                        when Resource is released.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpResource Pointer of Resource structure
 *
 * @return              : New Priority
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_002}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
#if (OS_RES_INT_SHARE == STD_ON)
FUNC(uint32, OS_CODE) Os_OriginalPriority
                          (P2VAR(Tdd_Os_Resource, AUTOMATIC, OS_VAR) LpResource)
{
  uint32 LulCurPrio;
  uint32 LulNewPrio;

  LulCurPrio = Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
  LulCurPrio >>= OS_IPR_LSB;

  LulNewPrio = LulCurPrio;
  if ((LpResource->ulOwnerPrevHwPrio == 0U) || (LulCurPrio < LpResource->ulOwnerPrevHwPrio))
  {
    LulNewPrio = LpResource->ulOwnerPrevHwPrio;
    /* Set new priority */
    (void)Os_SetInterruptPriority(LulNewPrio << OS_IPR_LSB);
  }
  else
  {
    /* Restore original priority */
    (void)Os_SetInterruptPriority(LulCurPrio << OS_IPR_LSB);
  }
  __ISB();


  return LulNewPrio;
}
#endif

/***************************************************************************//**
 * Function             : OS_NOT_IN_CAT1
 *
 * Service ID           : NA
 *
 * Description          : return true, if current context is not CAT1 ISR
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
 *
 * @return              : True/False
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_S32K14X_002}
 *
 * @ingroup               OS_S32K14X_ESDD_002
 ******************************************************************************/
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
FUNC(boolean, OS_CODE) OS_NOT_IN_CAT1(void)
{
  boolean Ldd_OsNotInCat1;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType LddCoreId = GetCoreID();
  #else
  CoreIDType LddCoreId = (CoreIDType)OS_ZERO;
  #endif
  
#if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  if (Os_GucNestingCAT1ISR[OS_CORE_ID] == (uint8)OS_ZERO)
  {
    Ldd_OsNotInCat1 = OS_TRUE;
  }
  else
  {
    Ldd_OsNotInCat1 = OS_FALSE; 
  }
#else
  Ldd_OsNotInCat1 = OS_TRUE; 
#endif
  
  return Ldd_OsNotInCat1;
}
#endif

/***************************************************************************//**
 * Function             : OS_IN_CAT1
 *
 * Service ID           : NA
 *
 * Description          : return true, if current context is CAT1 ISR 
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]          : void
 *
 * @return              : True/False
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_S32K14X_002}
 *
 * @ingroup               OS_S32K14X_ESDD_002
 ******************************************************************************/
FUNC(boolean, OS_CODE) OS_IN_CAT1(void)
{
  boolean Ldd_OsInCat1;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType LddCoreId = GetCoreID();
  #else
  CoreIDType LddCoreId = (CoreIDType)OS_ZERO;
  #endif
  
#if ((OS_ISR_COUNT != OS_PRE_ZERO) || (OS_MULTICORE == STD_ON))
  if (Os_GucNestingCAT1ISR[OS_CORE_ID] > (uint8)OS_ZERO)
  {
    Ldd_OsInCat1 = OS_TRUE;
  }
  else
  {
    Ldd_OsInCat1 = OS_FALSE; 
  }
#else
  Ldd_OsInCat1 = OS_FALSE; 
#endif
  
  return Ldd_OsInCat1;
}

/***************************************************************************//**
 * Function Name        : Os_IntDisableConditional
 *
 * Service ID           : NA
 *
 * Description          : If current priority is less than Os_CAT2_Max_Priority,
 *                        sets the BASEPRI to Os_CAT2_Max_Priority
 *                        (to disable CAT2 ISR) and returns the previous state.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : Previous interrupt state
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_CAT2_Max_Priority
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_S32K14X_003}
 *
 * @ingroup               OS_S32K14X_ESDD_002
 ******************************************************************************/
FUNC(Os_IntStatus_T, OS_CODE) Os_IntDisableConditional(void)
{
  Os_IntStatus_T intval;

  /* Get old priority level by setting highest priority */
  intval = Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
  if (intval > Os_CAT2_Max_Priority)
  {
    (void)Os_SetInterruptPriority((Os_IntStatus_T)Os_CAT2_Max_Priority << OS_IPR_LSB);
  }
  else
  {
    (void)Os_SetInterruptPriority(intval << OS_IPR_LSB);
  }
  __ISB();
  return intval;
}

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIP:Not a defect:Justify with annotations> Initialized at other location */
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:end<RTE:SHF:Not a defect:Justify with annotations> Calculated access to outside bounds */
/* polyspace:end<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-end MISRA-C3:18.1 */
/* polyspace:end<MISRA-C3:18.4:Not a defect:Justify with annotations> Operators on pointer is used for better performance */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
