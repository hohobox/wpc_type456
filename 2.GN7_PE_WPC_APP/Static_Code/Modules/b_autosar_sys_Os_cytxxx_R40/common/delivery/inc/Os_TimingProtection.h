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
**  SRC-MODULE: Os_TimingProtection.h                                         **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for OS_TIMINGPROTECTION.c file containing the     **
**              declaration of Timer Protection functionality related         **
**              functions.                                                    **
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
** 2.4.0     17-Aug-2017    SH.Yoo        Redmine #9577                       **
** 2.3.0     09-Mar-2017    SH.Yoo        Redmine #7716                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.7     13-Feb-2014    SH.Yoo        TASK: xar~819, Redmine #587         **
** 2.0.4     18-Nov-2013    MJ.Woo        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

#ifndef OS_TIMINGPROTECTION_H
#define OS_TIMINGPROTECTION_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os.h"
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_Arch_TimingProtection.h"
#endif

#if (OS_TIMING_PROTECTION == STD_ON)
/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/
#define OS_TIMEFRAME_WATCHDOG               0
#define OS_BUDGET_WATCHDOG                  1
#define OS_INT_LOCK_INDEX                   0
#define OS_ALL_INT_LOCK_INDEX               1

/*******************************************************************************
**                      Macros                                                **
*******************************************************************************/
/* This macro stops Interrupt monitoring Timer*/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
#define Os_StopIntMonitor(LpStaticTask, LulIndex)\
  do{ \
    Os_UpdateTpStructure(LpStaticTask);\
  } while(0)
/* This macro stops Resource monitoring Timer*/
/* polyspace<MISRA-C:19.7:Not a defect:Justify with annotations> Function like macro is used to improve performance */
#define Os_StopResMonitor(LpStaticTask, LpResource)\
  do{\
    Os_UpdateTpStructure(LpStaticTask); \
  } while(0)
/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
#if ((OS_ALLINTLOCK_TP_EB == STD_ON) || (OS_INTLOCK_TP_EB == STD_ON))
extern FUNC(void, OS_CODE) Os_StartAllLockMonitor(void);

extern FUNC(void, OS_CODE) Os_StartOsLockMonitor(void);

extern FUNC(void, OS_CODE) Os_StopAllLockMonitor(void);

extern FUNC(void, OS_CODE) Os_StopOsLockMonitor(void);
#endif

extern FUNC(void, OS_CODE) Os_OsWdgHandler(void);

extern FUNC(void, OS_CODE) Os_TimeFrameHandler(void);

extern FUNC(boolean, OS_CODE) Os_GetTimeElapsedService(uint8 TimerType,
                                                      TickRefType TimeElapsed);

extern FUNC(void, OS_CODE) Os_StartTimer(uint8 TimerType,
                                                         TickType LddTickValue);

extern FUNC(void, OS_CODE) Os_StopTimer(uint8 TimerType);

#define OS_STOP_SEC_CODE
#include "MemMap.h"

#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */
#endif /* OS_TIMINGPROTECTION_H */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
