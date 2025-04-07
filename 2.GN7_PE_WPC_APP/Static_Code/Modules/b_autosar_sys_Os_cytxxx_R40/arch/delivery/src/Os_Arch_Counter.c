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
**  SRC-MODULE: Os_Arch_Counter.c                                             **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of HW Counter specific functionality                **
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
** 2.4.1     20-Jan-2022    YH.Han        Redmine #33850                      **
** 2.0.0     08-Jul-2020    JH.Cho        Redmine #24316                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:begin<RTE:NIP:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Timer.h"
#include "Os_Arch_Regs.h"
#include "Os_Ram.h"
#include "Os_Gen.h"
#include "Os_Counter.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
 * Function             : Os_GetNextTick
 *
 * Service ID           : NA
 *
 * Description          : This function calculates the next tick from
 *                        current tick and distance.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LddCurrentTick Current tick
 * @param [in]            LddDistance    Distance from current tick
 * @param [in]            LddMaxAllowed  Maximum tick value
 *
 * @return              : Next tick value
 *
 * @pre                 : LddCurrentTick <= LddMaxAllowed,
 *                        LddDistance    <= LddMaxAllowed
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(TickType, OS_CODE) Os_GetNextTick(TickType LddCurrentTick,
				       TickType LddDistance,
				       TickType LddMaxAllowed)
{
  TickType LddNextTick;
  TickType LddRange = LddMaxAllowed + (TickType)OS_ONE;

  LddNextTick = LddCurrentTick + LddDistance;
  /* Check whether the offset is greater than the maximum allowed value
   * of the underlying counter */
  if (LddNextTick > LddMaxAllowed)
  {
    /** If value exceeds then adjust the offset */
    LddNextTick -= LddRange;
  }

  return LddNextTick;
}

/*******************************************************************************
 * Function             : Os_GetElapsedTick
 *
 * Service ID           : NA
 *
 * Description          : This function calculates the elapsed ticks between
 *                        previous and current tick.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LddPrevTick    Previous tick
 * @param [in]            LddCurrentTick Current tick
 * @param [in]            LddMaxAllowed  Maximum tick value
 *
 * @return              : Elapsed tick value
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(TickType, OS_CODE) Os_GetElapsedTick(TickType LddPrevTick,
					  TickType LddCurrentTick,
					  TickType LddMaxAllowed)
{
  TickType LddDistance;

  if (LddCurrentTick < LddPrevTick)
  {
    /* Increment counter -> overflow case */
    LddDistance = (LddMaxAllowed - (LddPrevTick - LddCurrentTick)) + OS_ONE;
  }
  else {
    LddDistance = LddCurrentTick - LddPrevTick;
  }

  return LddDistance;
}

#if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
/*******************************************************************************
 * Function             : Os_UpdateHwCounter
 *
 * Service ID           : NA
 *
 * Description          : Update counter tick
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [in]            LpHwCounter     Pointer of HW counter info
 *
 * @return              : void return but CurrentCounter is updated
 *
 * @pre                 : Os_InitTimer() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(void, OS_CODE) Os_UpdateHwCounter(P2CONST(Tdd_Os_HardwareCounter, AUTOMATIC,
                                                            OS_CONST) LpHwCounter)
{
  /* In case of reload timer, do nothing */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > NULL pointer check */
  OS_UNUSED_PTR(LpHwCounter);
}

/*******************************************************************************
 * Function             : Os_UpdateCountInCounterISR
 *
 * Service ID           : NA
 *
 * Description          : Update counter tick. This function is called in
 *                        timer interrupt that drive the counter.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Re-entrant
 *
 * @param [out]           LpStaticCounter Pointer of counter to be updated
 * @param [in]            LpHwCounter     Pointer of HW counter info
 *
 * @return              : void
 *
 * @pre                 : Os_InitTimer() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(void, OS_CODE) Os_UpdateCountInCounterISR(P2CONST(Tdd_Os_StaticCounter,
                                           AUTOMATIC, OS_CONST) LpStaticCounter,
                   P2CONST(Tdd_Os_HardwareCounter, AUTOMATIC, OS_CONST) LpHwCounter)
{
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> Already checked wheter it is NULL or not */
  /* polyspace +2 MISRA-C3:18.1 [Justified:Medium] "Pointer not access out of array" */
  LpStaticCounter->pCounter->ddCurrentCount = LpHwCounter->ddNextCount;
  /* polyspace:end<MISRA-C3:D4.14> */
}

/*******************************************************************************
 * Function             : Os_ResetTimer
 *
 * Service ID           : NA
 *
 * Description          : Set next count value and clear interrupt flag
 *                        If no Alarm, set next interrupt to MAX period
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LpStaticCounter Pointer of counter that has alarm info
 * @param [in]            LpHwCounter Pointer of HW counter info
 *
 * @return              : void
 *
 * @pre                 : Os_InitTimer() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_ClearTimerIntFlag()
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ResetTimer(CONSTP2CONST(Tdd_Os_StaticCounter, AUTOMATIC,
                                                      OS_CONST) LpStaticCounter,
              CONSTP2VAR(Tdd_Os_HardwareCounter, AUTOMATIC, OS_VAR) LpHwCounter)
{
  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> Already checked wheter it is NULL or not */
  /* Check whether next count has reached to maximum allowed value */
  if (LpHwCounter->ddNextCount == LpStaticCounter->ddMaxAllowedValue)
  {
    /* Reset the next count */
    LpHwCounter->ddNextCount = OS_ZERO;
  }
  else
  {
    /* Increment next count */
    LpHwCounter->ddNextCount++;
  }
  /* polyspace:end<MISRA-C3:D4.14> */

  Os_ClearTimerIntFlag(LpHwCounter->enChannelId);
} /* End of Os_ResetTimer() */

/*******************************************************************************
 * Function             : Os_AdjustTimerInterrupt
 *
 * Service ID           : NA
 *
 * Description          : Update next timer interrupt when new Alarm is inserted
 *                        at head.
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddNewAbsCount Counter Tick(Absolute) to be set next
 * @param [in]            LpHwCounter    Pointer of HW counter info
 *
 * @return              : void
 *
 * @pre                 : Os_InitTimer() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
#if ((OS_ALARM == STD_ON) || (OS_SCHEDTABLE == STD_ON))
FUNC(void, OS_CODE) Os_AdjustTimerInterrupt(TickType LddNewAbsCount,
                   P2CONST(Tdd_Os_HardwareCounter, AUTOMATIC, OS_CONST) LpHwCounter)
{
  /* In case of reload timer, do nothing */
  OS_UNUSED(LddNewAbsCount);
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > NULL pointer check */
  OS_UNUSED_PTR(LpHwCounter);
}
#endif

/*******************************************************************************
 * Function             : Os_StartHwCounter
 *
 * Service ID           : NA
 *
 * Description          : Initializes the info of hardware counter
 *                        and start timer interrupt
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddNanoSecPerTick Nanoseconds per 1 counter tick
 * @param [in, out]       LpHwCounter       Pointer of HW counter info
 *
 * @return              : void
 *
 * @pre                 : Os_InitTimer() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulStmClock
 *
 *                        Function(s) invoked    :
 *                        Os_StartTimerHw()
 *
 * {Ref: SWR_OS_CYTXXX_007}
 *
 * @ingroup               OS_CYTXXX_ESDD_004
 ******************************************************************************/
FUNC(void, OS_CODE) Os_StartHwCounter(TickType LddNanoSecPerTick,
                   P2VAR(Tdd_Os_HardwareCounter, AUTOMATIC, OS_VAR) LpHwCounter)
{
  /** TicksPerBase = STM_Ticks / Counter_Ticks
   *   = (STM_Ticks / sec) / (Counter_Ticks / sec)
   *   = (STM_Clock) / (1 / SecondsPerTick)
   *   = STM_Clock * SecondsPerTick
   *   = STM_Clock * NanoSecondsPerTick / 1000000000
   *   = Os_GulStmClock * 1000000 * NanoSecondsPerTick / 1000000000
   *   = Os_GulStmClock * NanoSecondsPerTick / 1000
   *
   * The STM_Clock Max frequency is 160MHz and TickType is 4byte in CYT2Bx.
   * So maximum valid value(not overflow) of LddNanoSecPerTick is 26843545.
   * Valid TicksPerBase value is an unsigned integer greater than or equal to 1.
   */
  TickType LddTicksPerBase = (Os_GulStmClock * LddNanoSecPerTick) /
                                                                OS_THOUSAND;
  TickType LddNextIntTick;

  /** If TicksPerBase is invalid, set as default value 1 */
  if (LddTicksPerBase < (TickType)OS_ONE)
  {
    LddTicksPerBase = (TickType)OS_ONE;
  }

  /* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> Already checked wheter it is NULL or not */
  LpHwCounter->ddTicksPerBase = LddTicksPerBase;
  /* polyspace:end<MISRA-C3:D4.14> */

  /** If Timer type is Reload Timer, interrupt will occur each OS Counter period */
  LddNextIntTick = LddTicksPerBase;
  LpHwCounter->ddNextCount = (TickType)OS_ONE;

  /** Start a Counter */
  Os_StartTimerHw(LpHwCounter->enChannelId, LddNextIntTick);
}
#endif /* (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> Variable initialized at other location */
/* polyspace:end<RTE:NIP:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
