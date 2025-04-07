/*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: Os_Debug.h                                                    **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS Improvement Code                                   **
**                                                                            **
**  PURPOSE   : Header file for Os_Debug.c file containing the                **
**              declaration of Debugging features related functions.          **
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
** 2.2.0     08-Sep-2023    HG.Kim        Redmine #42654                      **
** 2.1.1     03-Mar-2022    MJ.Woo        Redmine #34294                      **
** 2.1.0     21-Dec-2020    JH.Cho        Redmine #27287                      **
** 2.0.0     17-Jun-2020    JH.Cho        Redmine #24132, #24402              **  
** 1.0.0     25-Feb-2020    MJ.Woo        Redmine #20864                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/

#ifndef OS_DEBUG_H
#define OS_DEBUG_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Imp_Cfg.h"

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#if (OS_DEBUG_CPULOAD == STD_ON)
/** The maximum value of permill */
#define OS_FULL_PERMILLAGE      1000u
/** The maximum value of timestamp */
#define OS_TIMESTAMP_MAX        0xFFFFFFFFu
/* Max count of measurement */
#define OS_MEASURECOUNT_MAX     0xFFFFFFFFu
#endif

#if (OS_DEBUG_STACKDEPTH == STD_ON)
#define OS_STACK_EMPTY_PATTERN  0xEEEEEEEEu /* 'E'mpty */
#endif

/**
  * This structure holds the CPU and Interrupt Load value.
  */
typedef struct
{
  uint16 usCPULoad;     /**< Current CPU Load value */
  uint16 usCPULoadPeak; /**< CPU Load Peak value after value reset */
  uint16 usCPULoadMean; /**< CPU Load Mean value */
  uint16 usITLoad;      /**< Current Interrupt Load value */
  uint16 usITLoadPeak;  /**< Interrupt Load Peak value after value reset */
  uint16 usITLoadMean;  /**< Interrupt Load Mean value */
} Os_LoadType;

/* Counter controls */
/** Macro to define CYT2B7 */
#define CYT2B7 1
/** Macro to define CYT2B9 */
#define CYT2B9 2
/** Macro to define CYT2BL */
#define CYT2BL 3
/** Macro to define CYT4BB */
#define CYT4BB 4
/** Macro to define CYT4BF */
#define CYT4BF 5
/** Macro to define CYT6BJ */
#define CYT6BJ 6

/**
 * GPT Timer name | OS Timer name
 * -------------- | --------------------------
 * TCPWM_0_512    | TCPWM Group #2, Counter #0
 */
/** Count register of the TCPWM0 Group #2, Counter #0 */
#if (OS_PROCESSOR_SERIES == CYT2B7)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40390008u)
#elif (OS_PROCESSOR_SERIES == CYT2B9)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40390008u)
#elif (OS_PROCESSOR_SERIES == CYT2BL)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40390008u)
#elif (OS_PROCESSOR_SERIES == CYT4BB)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40590008u)
#elif (OS_PROCESSOR_SERIES == CYT4BF)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40590008u)
#elif (OS_PROCESSOR_SERIES == CYT6BJ)
/* polyspace +2 MISRA-C3:11.4 [Justified:Low] "Required for register access" */
#define OS_TCPWM0_GRP2_CNT0_COUNTER   (*(volatile uint32 *)0x40390008u)
#else
#error "Specified MCU is not supported."
#endif

#define OS_START_SEC_VAR_CLEARED_16
#include "MemMap.h"
/** This global variable used to save CPU load. */
extern VAR(uint16, OS_VAR) Os_GusCPULoad[OS_CORE_COUNT];
/** This global variable used to save Interrupt load. */
extern VAR(uint16, OS_VAR) Os_GusITLoad[OS_CORE_COUNT];
/** This global variable used to save peak CPU load. */
extern VAR(uint16, OS_VAR) Os_GusCPULoadPeak[OS_CORE_COUNT];
/** This global variable used to save peak Interrupt load. */
extern VAR(uint16, OS_VAR) Os_GusITLoadPeak[OS_CORE_COUNT];
/** This global variable used to save mean CPU load. */
extern VAR(uint16, OS_VAR) Os_GusCPULoadMean[OS_CORE_COUNT];
/** This global variable used to save mean Interrupt load. */
extern VAR(uint16, OS_VAR) Os_GusITLoadMean[OS_CORE_COUNT];
#define OS_STOP_SEC_VAR_CLEARED_16
#include "MemMap.h"

/*******************************************************************************
**                      Function Defination                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_DEBUG_CPULOAD == STD_ON)
extern FUNC(void, OS_CODE) Os_InitCPULoad(void);
extern FUNC(void, OS_CODE) Os_ITEntryForCPULoad(void);
extern FUNC(void, OS_CODE) Os_ITExitForCPULoad(void);

extern FUNC(void, OS_CODE) Os_SetIdleForCPULoad(void);
extern FUNC(void, OS_CODE) Os_MeasureCPULoad(void);
extern FUNC(void, OS_CODE) Os_ClearCPULoadPeak(void);
extern FUNC(void, OS_CODE) Os_ClearITLoadPeak(void);
extern FUNC(void, OS_CODE) Os_UserGetCPULoad(
		         P2VAR(Os_LoadType, AUTOMATIC, OS_VAR) LpLoad, boolean restart);
extern FUNC(void, OS_CODE) Os_ResetIdleEntry(void);
extern FUNC(void, OS_CODE) Os_DebugH2L(void);
extern FUNC(void, OS_CODE) Os_RestartMeanLoad(void);

/** Inline function for get current System Timer Tick */
static inline FUNC(uint32, OS_CODE) OS_GET_TIMESTAMP(void)
{
  return OS_TCPWM0_GRP2_CNT0_COUNTER;
}
#endif

#if (OS_DEBUG_STACKDEPTH == STD_ON)
extern FUNC(void, OS_CODE) Os_FillStackPattern(void);
extern FUNC(StatusType, OS_CODE) Os_GetMaxStackUsage(TaskType LddTaskId,
                                       uint32* pStackUsage, uint32* pStackSize);
#endif

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/

#endif /* OS_DEBUG_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
