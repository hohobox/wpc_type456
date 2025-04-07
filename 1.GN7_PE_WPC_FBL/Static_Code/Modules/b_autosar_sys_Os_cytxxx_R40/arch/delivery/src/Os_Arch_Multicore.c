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
**  SRC-MODULE: Os_Arch_Multicore.c                                           **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Multicore specific functionality                 **
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
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:begin<MISRA-C:2.1:Not a defect:Justify with annotations> Coexistence of assembly is needed for readability  */
/* polyspace:begin<RTE: ABS_ADDR : Not a defect : Justify with annotations > Absolute address is needed to access MCU register */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/

#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_MulticoreMessage.h"
#include "Os_Arch_Interrupt.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
/* Macro for power control key */
#define OS_SYS_PWR_CTL_KEY_OPEN      (0x05FA)
#define OS_SYS_PWR_CTL_KEY_CLOSE     (0xFA05)

/* Macro for CM status */
#define OS_SYS_CM_STATUS_OFF         (0u)
#define OS_SYS_CM_STATUS_RESET       (1u)
#define OS_SYS_CM_STATUS_RETAINED    (2u)
#define OS_SYS_CM_STATUS_ENABLED     (3u)

/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
/*  Start address of the Cortex-M7_1 application */
#ifndef OS_CORTEX_M7_1_APPL_ADDR
/* This symbol is defined in the linker script */
/* polyspace:begin<MISRA-C3:21.2:Not a defect:Justify with annotations> below symbol is from MCU supplier. */
/* polyspace:begin<MISRA-C3:8.5:Not a defect:Justify with annotations> below symbol is from MCU supplier. */
/* polyspace:begin<MISRA-C3:8.6:Not a defect:Justify with annotations> below symbol is from MCU supplier. */
/* polyspace:begin<CERT-C:DCL37-C:Not a defect:Justify with annotations> below symbol is from MCU supplier. */
extern char *  __cm7_1_vector_base_linker_symbol;
#define OS_CORTEX_M7_1_APPL_ADDR      ((uint32) &__cm7_1_vector_base_linker_symbol)
/* polyspace:end<MISRA-C3:21.2> */
/* polyspace:end<MISRA-C3:8.5> */
/* polyspace:end<MISRA-C3:8.6> */
/* polyspace:end<CERT-C:DCL37-C> */
#endif
#endif /* End of if (OS_MULTICORE == STD_ON) */
/* polyspace:end<MISRA-C3:11.4> */
/* polyspace:end<ISO-17961:intptrconv> */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
#if (OS_MULTICORE == STD_ON)
static Std_ReturnType OS_IPC_Sema_Set(const uint32 gateIndex);
static void OS_IPC_Sema_Clear(const uint32 gateIndex);
#endif /* End of if (OS_MULTICORE == STD_ON) */
/*******************************************************************************
** Function Name        : Os_StartCore                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for start another core        **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : CoreID                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : None                                                **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_StartCore(CoreIdType CoreID)
{
  OS_CPUSS_CM7_1_PWR_CTL_type tPwrCtl1;

  if (CoreID == OS_ONE)
  {
    /* Adjust the vector address */
    OS_CPUSS_CM7_1_VECTOR_TABLE_BASE.U = OS_CORTEX_M7_1_APPL_ADDR;

    /* Enable the Power Control Key */
    tPwrCtl1.B.VECTKEYSTAT = OS_SYS_PWR_CTL_KEY_OPEN;
    tPwrCtl1.B.PWR_MODE = OS_SYS_CM_STATUS_ENABLED;
    OS_CPUSS_CM7_1_PWR_CTL.U = tPwrCtl1.U;

    OS_CPUSS_CM7_1_CTL.B.CPU_WAIT = 0u;
  }
} /* End of Os_StartCore(CoreIdType CoreID) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_TryToGetSpinlock                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : The Os_TryToGetSpinlock indicates if the spinlock   **
**                        has been occupied or not.                           **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** Output Parameters    : Success                                             **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_TryToGetSpinlock(SpinlockIdType SpinlockId,
                                                              boolean* Success)
{
  if (OS_IPC_Sema_Set(SpinlockId) == OS_ONE)
  {
    *Success = OS_FALSE;
  }
  else
  {
    *Success = OS_TRUE;
  }
}
#endif /* if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_GetSpinlock                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to get the spinlock         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_GetSpinlock(SpinlockIdType SpinlockId)
{
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> it do not cuase infinite loop */
  while(OS_IPC_Sema_Set(SpinlockId) == OS_ONE)
  {
  }
  /* polyspace:end<MISRA-C3:D4.14>  */
}
#endif /* if (OS_MULTICORE == STD_ON) */
/*******************************************************************************
** Function Name        : Os_ReleaseSpinlock                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to release the spinlock     **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : SpinlockId                                          **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_ReleaseSpinlock(SpinlockIdType SpinlockId)
{
  OS_IPC_Sema_Clear(SpinlockId);
}
#endif /* if (OS_MULTICORE == STD_ON) */
/*******************************************************************************
** Function Name        : Os_InterCoreInterruptHandler                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function handles the interrupt on other cores  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GpStaticTask, Os_GblInterCoreInt                 **
**                        Os_GaaStaticTask, Os_GpLinkTask                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ReceiveMessage(), Os_RunTask(),                  **
**                        Os_SetTaskStackPointer(),                           **
**                        Os_IsrEntryHook(), Os_IsrExitHook()                 **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_InterCoreInterruptHandler(void)
{
  CoreIDType OS_CORE_ID;

  OS_DISABLEINTERRUPTS();
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if (OS_PROFILING_HOOK == STD_ON)
  Os_IsrEntryHook(OS_CORE_ID, INVALID_ISR);
  #endif
  
  Os_GblInterCoreInt[OS_CORE_ID] = OS_TRUE;
  Os_ReceiveMessage(OS_CORE_ID);
  Os_GblInterCoreInt[OS_CORE_ID] = OS_FALSE;
  
  /* Check if any new Task is activated by another core */
  /* polyspace:begin<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace:begin<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
  if (Os_GpStaticTask[OS_CORE_ID] != &(Os_GaaStaticTask[Os_GpLinkTask[OS_CORE_ID]->ddTaskID]))
  /* polyspace:end<RTE: NIV : Not a defect : No Action Planned > variable is initialized and code is verified manually */
  /* polyspace:end<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
  {
    /* New task ready to be dispatched */
    OS_SAVECONTEXT();
  }

  #if (OS_PROFILING_HOOK == STD_ON)
  Os_IsrExitHook(OS_CORE_ID, INVALID_ISR);
  #endif
  OS_ENABLEINTERRUPTS();
} /* End of InterCoreInterruptHandler(void) */
#endif /* if (OS_MULTICORE == STD_ON) */

#if (OS_MULTICORE == STD_ON)
ISR(OsIsr_IC_ISR_0)
{
  Os_InterCoreInterruptHandler();
}

ISR(OsIsr_IC_ISR_1)
{
  Os_InterCoreInterruptHandler();
}
#endif /* if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_NotifyCore                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : NA                                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     : NA                         **
**                                                                            **
**                        Function(s) invoked    : NA                         **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_NotifyCore(uint32 core)
{
  if(core == 0)
  {
    OS_IPC_REG.INTR_STRUCT[OS_IC_0_IPC_INDEX].INTR_MASK.B.NOTIFY = 1u;
    (void)OS_IPC_REG.INTR_STRUCT[OS_IC_0_IPC_INDEX].INTR_MASK.U;
  }
  else if(core == 1)
  {
    OS_IPC_REG.INTR_STRUCT[OS_IC_1_IPC_INDEX].INTR_MASK.B.NOTIFY = 1u;
    (void)OS_IPC_REG.INTR_STRUCT[OS_IC_1_IPC_INDEX].INTR_MASK.U;
  }
  else
  {
    /* do_nothing */
  }
}
#endif /* if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_AckNotifyCore                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : NA                                                  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     : NA                         **
**                                                                            **
**                        Function(s) invoked    : NA                         **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_AckNotifyCore(uint32 core)
{
  if(core == 0)
  {
    OS_IPC_REG.INTR_STRUCT[OS_IC_0_IPC_INDEX].INTR_MASK.B.NOTIFY = 0u;
    (void)OS_IPC_REG.INTR_STRUCT[OS_IC_0_IPC_INDEX].INTR_MASK.U;
  }
  else if(core == 1)
  {
    OS_IPC_REG.INTR_STRUCT[OS_IC_1_IPC_INDEX].INTR_MASK.B.NOTIFY = 0u;
    (void)OS_IPC_REG.INTR_STRUCT[OS_IC_1_IPC_INDEX].INTR_MASK.U;
  }
  else
  {
    /* do_nothing */
  }
  *(volatile uint32 *)OS_ARM_M_IRQ_CLEAR_PENDING_START = (uint32)OS_CLEARPENDING_VALUE;   
}
#endif /* if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : OS_IPC_Sema_Set                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Attempt to lock a selected gate and return the      **
**                        status of the operation. This function attempts     **
**                        to lock a selected gate and checks if the operations**
**                        was successful.                                     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
static Std_ReturnType OS_IPC_Sema_Set(const uint32 gateIndex)
{
  Std_ReturnType LddStatusReturn = E_OK;

  /* Check to make sure the IPC channel is released
     If so, check if specific channel can be locked. */
  if(E_OK == OS_IPC_Drv_LockAcquire (os_semaIpcStruct))
  {
    /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */
    if(Os_GulSpinlocks[gateIndex] == 0u)
    {
      Os_GulSpinlocks[gateIndex] |= 1u;
      LddStatusReturn = E_OK;
    }
    else
    {
      LddStatusReturn = E_NOT_OK;//CY_IPC_SEMA_NOT_ACQUIRED;
    }
    /* polyspace:end<MISRA-C3:D4.14> */
    /* Release, but do not trigger a release event */
    (void) OS_IPC_Drv_LockRelease (os_semaIpcStruct, OS_IPC_NO_NOTIFICATION);
  }
  else
  {
    LddStatusReturn = E_NOT_OK;
  }
  return LddStatusReturn;
}
#endif  /* if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : OS_IPC_Sema_Clear                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Unlock a selected gate.                             **
**                        This function is used to unlock a selected gate.    **
**                        This operation is possible only if the selected     **
**                        gate has been locked by the same processor that     **
**                        tries to unlock                                     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : StartOs() function should be called                 **
**                                                                            **
**                                                                            **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
static void OS_IPC_Sema_Clear(const uint32 gateIndex)
{
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */
  Os_GulSpinlocks[gateIndex] = 0u;
  /* polyspace:end<MISRA-C3:D4.14> */
}
#endif /* if (OS_MULTICORE == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> Macro definitions are needed for performance and file size  */
/* polyspace:end<MISRA-C:2.1:Not a defect:Justify with annotations> Coexistence of assembly is needed for readability  */
/* polyspace:end<RTE: ABS_ADDR : Not a defect : Justify with annotations > Absolute address is needed to access MCU register */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
