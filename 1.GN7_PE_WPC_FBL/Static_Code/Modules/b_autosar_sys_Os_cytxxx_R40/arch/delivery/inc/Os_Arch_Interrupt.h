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
**  SRC-MODULE: Os_Arch_Interrupt.h                                           **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related Interrupt API                  **
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
** 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:begin<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<MISRA-C3:D4.9:Not a defect:Justify with annotations> Function like macro is used to improve performance  */
/* polyspace:begin<MISRA-C3:8.4:Not a defect:Justify with annotations> Inline functions should be implemented in header file  */
/* polyspace:begin<MISRA-C3:8.11:Not a defect:Justify with annotations> The generator generates exact size of initializers */
/* polyspace:begin<MISRA-C3:9.5:Not a defect:Justify with annotations> The generator generates exact size of initializers */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-begin CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

#ifndef OS_ARCH_INTERRUPT_H_
#define OS_ARCH_INTERRUPT_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Multicore.h"
#include "Os_Arch_Regs.h"
#include "Os_PortTypes.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/**
 * @addtogroup OS_CYTXXX_ESDD
 * @{ */
/** Macro to define the lowest ISR priority value supported by the hardware
 *  \n{Ref: SWR_OS_CYTXXX_003} */
#define OS_INT_MIN_PRIORITY              (7U)

/** @} */

typedef void  (*T_IsrFuncPtr)(void);

#define OS_START_SEC_EXCEPTION_VECTOR
#include "MemMap.h"
extern const T_IsrFuncPtr Os_ExceptionVectorTable[NUM_ELE_VECTOR_TABLE];
#define OS_STOP_SEC_EXCEPTION_VECTOR
#include "MemMap.h"

#if (OS_MULTICORE == STD_ON)
#define OS_START_SEC_EXCEPTION_VECTOR_CORE1
#include "MemMap.h"
extern const T_IsrFuncPtr Os_ExceptionVectorTableCore1[NUM_ELE_VECTOR_TABLE];
#define OS_STOP_SEC_EXCEPTION_VECTOR_CORE1
#include "MemMap.h"
#endif /*(OS_MULTICORE == STD_ON)*/

#if (OS_ISR_COUNT != OS_PRE_ZERO)

#define OS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Tdd_Os_ISRPriority, OS_CONST) Os_GaaISRPriority[];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Tdd_Os_ISRIndex, OS_CONST) Os_GaaISRIndex[];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define OS_START_SEC_CONST_32
#include "MemMap.h"
#if (OS_MULTICORE == STD_OFF)
extern CONST(uint32, OS_CONST) OS_COUNTER_ISRID;
#else
extern CONST(uint32, OS_CONST) OS_COUNTER_ISRID[];
#endif
#define OS_STOP_SEC_CONST_32
#include "MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(uint16, OS_CONST) Os_GaaISRTable[];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define OS_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
extern CONST(Os_Cat1IsrPtrType, OS_CONST) Os_GaaCat1ISRTable[];
#define OS_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/*******************************************************************************
 * Function Name        : OS_DISABLEINTERRUPTS
 * Service ID           : NA
 * Description          : Disable External interrupts
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * Parameters           : None
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) OS_DISABLEINTERRUPTS(void)
{
  /* polyspace<MISRA-C3:D2.1:Not a defect:Justify with annotations> Green Hills provides support for the system registers used by the Cortex-M family */
  __CPS(__CPS_DISABLE, __CPS_F, __CPS_DEFAULT);
}

/*******************************************************************************
 * Function Name        : OS_ENABLEINTERRUPTS
 * Service ID           : NA
 * Description          : Enable External interrupts
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * Parameters           : None
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) OS_ENABLEINTERRUPTS(void)
{
  /* polyspace<MISRA-C3:D2.1:Not a defect:Justify with annotations> Green Hills provides support for the system registers used by the Cortex-M family */
  __CPS(__CPS_ENABLE, __CPS_F, __CPS_DEFAULT);
}

/*******************************************************************************
 * Function Name        : OS_DISABLE_AND_SAVE_INTERRUPTS
 * Service ID           : NA
 * Description          : set faultmask and return current state of faultmask
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * Parameters           : None
 * @return              : Previous faultmask state
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(Os_OldLevel_T, OS_CODE) OS_DISABLE_AND_SAVE_INTERRUPTS(void)
{
  Os_OldLevel_T LddOldVal = __MRS(__FAULTMASK);
  /* polyspace<MISRA-C3:D2.1:Not a defect:Justify with annotations> Green Hills provides support for the system registers used by the Cortex-M family */
  __CPS(__CPS_DISABLE, __CPS_F, __CPS_DEFAULT);
  __ISB();
  return LddOldVal;
}

/*******************************************************************************
 * Function Name        : OS_RESTORE_INTERRUPTS
 * Service ID           : NA
 * Description          : restore faultmask state with previous value
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * Parameters           : Previous faultmask state
 * @return              : None
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) OS_RESTORE_INTERRUPTS(Os_OldLevel_T LddOldVal)
{
  __MSR(__FAULTMASK, LddOldVal);
  __ISB();
}

/*******************************************************************************
 * Function Name        : Os_IntRestore
 * Service ID           : NA
 * Description          : Restores a FAULTMASK with previously-saved status.
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * @param [in]            os_p : Previously-saved interrupt status
 * @return              : Previous interrupt state
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        Os_CAT2_Max_Priority
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) Os_IntRestore(Os_IntStatus_T os_p)
{
  __MSR(__BASEPRI, os_p);
  __ISB();
}

/*******************************************************************************
 * Function Name        : Os_SetInterruptPriority
 * Service ID           : NA
 * Description          : Set priority of an interrupt
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * @param [in]            intval : priority of an interrupt
 * @return              : Previous interrupt priority
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(Os_IntStatus_T, OS_CODE) Os_SetInterruptPriority
                                                         (Os_IntStatus_T intval)
{
  Os_IntStatus_T oldval = __MRS(__BASEPRI);
  __MSR(__BASEPRI, intval);
  return oldval;
}

/***************************************************************************//**
 * Function Name        : Os_IntDisable
 *
 * Service ID           : NA
 *
 * Description          : Sets the IRQPLM to Os_CAT2_Max_Priority
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
 ******************************************************************************/
static inline FUNC(Os_IntStatus_T, OS_CODE) Os_IntDisable(void)
{
  Os_IntStatus_T intval;

  intval = Os_SetInterruptPriority((Os_IntStatus_T)Os_CAT2_Max_Priority << OS_IPR_LSB);
  __ISB();
  return intval;
}

/*****************************************************************************
 * Function Name        : Os_IntDisableAll
 * Service ID           : NA
 * Description          : Sets the BASEPRI to MAX ISR Priority value (to disable all
 *                        interrupts) and returns the previous state.
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non Re-entrant
 * Parameters           : None
 * @return              : Previous interrupt state
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(Os_IntStatus_T, OS_CODE) Os_IntDisableAll(void)
{
  Os_IntStatus_T intval;

  intval = Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
  __ISB();
  return intval;
}

/*****************************************************************************
 * Function Name        : Os_SuspendInterrupts
 * Service ID           : NA
 * Description          : This function is used by Os_KernSuspendInterrupts(),
 *                                                 SuspendOSInterrupts(),
 *                                                 Os_RunTask(),
 *                        "It disable at the specified level" both in the calling
 *                        context and in the current context.
 *                        No special mechanism is in place to avoid multiple
 *                        evaluations of the parameters.
 *                        However,
 *                        in practice each parameter is only used once.
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non re-entrant
 * @param [in]            lvl : New priority level
 * @param [out]           olp : Previous priority level
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) Os_SuspendInterrupts(Os_OldLevel_T* olp,
						                                             uint32 lvl)
{
  /* Get old priority level by setting highest priority */
  *olp = __MRS(__BASEPRI);
  if (*olp != 0u)
  {
    if (lvl != 0u)
    {
      if (lvl < *olp)  /* Cortex-M, BASEPRI=0 has no effect */
      {
        /* Set new priority level */
        (void)Os_SetInterruptPriority(lvl << OS_IPR_LSB);
      }
      else
      {
        /* Restore old priority level */
        (void)Os_SetInterruptPriority(*olp);
      }
    }
    else
    /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Below code is verified and not a defect. */
    {
      /* maintain highest priority */
      (void)Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
    }
  }
  else
  {
    if (lvl != 0u)
    {
      /* Set new priority level */
      (void)Os_SetInterruptPriority(lvl << OS_IPR_LSB);
    }
    else
    /* polyspace<RTE:UNR:Not a defect:Justify with annotations> Below code is verified and not a defect. */
    {
      (void)Os_SetInterruptPriority(OS_INT_MAX_PRIORITY << OS_IPR_LSB);
      /* maintain highest priority */
    }
  }
  __ISB();
}

/*******************************************************************************
 * Function Name        : Os_ResumeInterrupts
 * Service ID           : NA
 * Description          : This function is used by Os_KernResumeInterrupts()
 *                        It restores the old priority level both in the calling
 *                        context and in the current context.
 * Sync/Async           : Synchronous
 * Re-entrancy          : Non re-entrant
 * @param [in]            olp : Previous priority level
 * @return              : void
 * @pre                 : None
 * @remarks             : Global Variable(s)     :
 *                        None
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(void, OS_CODE) Os_ResumeInterrupts(const Os_OldLevel_T* olp)
{
  (void)Os_SetInterruptPriority((uint32)*(olp));
  __ISB();
}

/*****************************************************************************
 * Function Name        : Os_GetCurPrivMode
 *
 * Service ID           : NA
 *
 * Description          : This function is called to get current privilege level
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * Parameters           : None
 *
 * @return              : Current privilege mode
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_002
 ******************************************************************************/
static inline FUNC(Os_PrivModeType, OS_CODE) Os_GetCurPrivMode(void)
{
  Os_PrivModeType LenPrivMode;
  Os_Reg32 IPSR_val;
  Os_Reg32 CONTROL_val;
  CONST(Os_Reg32, OS_CONST) CONTROL_nPRIV_BIT = 0x1u;

  LenPrivMode = OS_PRIV_UNKNOWN;

  /* Get IPSR register */
  IPSR_val = __MRS(__IPSR);

  if(IPSR_val == OS_ZERO)
  {
    /* Thread Mode */
    CONTROL_val = __MRS(__CONTROL);
    if((CONTROL_val & CONTROL_nPRIV_BIT) == (Os_Reg32)OS_ONE)
    {
      /* CONTROL.nPRIV = 1 */
      LenPrivMode = OS_PRIV_USER;
    }
    else
    {
      /* CONTROL.nPRIV = 0 */
      LenPrivMode = OS_PRIV_SUPERVISOR;
    }
  }
  else
  {
    /* Handler Mode */
    LenPrivMode = OS_PRIV_SUPERVISOR;
  }
  return LenPrivMode;
}

#define OS_START_SEC_CODE
#include "MemMap.h"
extern FUNC(void, OS_CODE) Os_IntSetEnable(uint32 intrNum);
extern FUNC(void, OS_CODE) Os_IntSetDisable(uint32 intrNum);
extern FUNC(void, OS_CODE) Os_IntClearPend(uint32 intrNum);
extern FUNC(uint8, OS_CODE) Os_CAT2ISRHandler(uint32 LulIsrIdx,
                                                         uint32 LulNestOnEntry);

extern FUNC(boolean, OS_CODE) OS_NOT_IN_CAT1(void);
extern FUNC(boolean, OS_CODE) OS_IN_CAT1(void);
extern FUNC(Os_IntStatus_T, OS_CODE) Os_IntDisableConditional(void);
#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* OS_ARCH_INTERRUPT_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:end<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<MISRA-C3:D4.9:Not a defect:Justify with annotations> Function like macro is used to improve performance  */
/* polyspace:end<MISRA-C3:8.4:Not a defect:Justify with annotations> Inline functions should be implemented in header file  */
/* polyspace:end<MISRA-C3:8.11:Not a defect:Justify with annotations> The generator generates exact size of initializers */
/* polyspace:end<MISRA-C3:9.5:Not a defect:Justify with annotations> The generator generates exact size of initializers */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace-end CERT-C:PRE00-C [Not a defect:Low] "Function like macro is used to improve performance" */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
