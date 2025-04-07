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
**  SRC-MODULE: Os_Arch_Timer.c                                               **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of timer specific functionality                     **
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
** 2.3.0     26-Jan-2021    YH.Han        Redmine #27953                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<RTE:OBAI:Not a defect:Justify with annotations> Configured array index */
/* polyspace:begin<MISRA-C3:8.4:Not a defect:Justify with annotations> External linkage is defined in other location */
/* polyspace:begin<MISRA-C3:8.7:Not a defect:Justify with annotations> Function may be referenced in other features */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_Arch_Timer.h"
#include "Os_Arch_Interrupt.h"
#include "Os_Ram.h"
#include "Os_Kernel.h"
#if (OS_TIMING_PROTECTION == STD_ON)
#include "Os_TimingProtection.h"
#include "Os_Error.h"
#include "Os_Arch_Context.h"
#include "Os_Arch_Regs.h"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
static FUNC(void, OS_CODE) Os_InitSysTick(void);
#endif

#if (OS_TIMING_PROTECTION == STD_ON)
static FUNC(void, OS_CODE) Os_InitTCPWM(void);
static FUNC(void, OS_CODE) Os_StartTCPWM(Os_TimerIdType LddFtmId, uint32 LulTimerCount);
static FUNC(void, OS_CODE) Os_StopTCPWM(Os_TimerIdType LddFtmId);
#endif

/*******************************************************************************
 * Function             : Os_InitTimer
 *
 * Service ID           : NA
 *
 * Description          : This function initializes the Hardware counter
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : Interrupt is disabled
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_InitSysTick(), Os_InitTimer0()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
FUNC(void, OS_CODE) Os_InitTimer(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
  /* Init SysTick Timer */
  Os_InitSysTick();
  #if (OS_MULTICORE == STD_ON)
  if (OS_CORE_ID == OS_ZERO)
  #endif
  {
    /* Init System Timer for Counter */
    Os_InitTimer0();
  }
  #if (OS_MULTICORE == STD_ON)
  if (OS_CORE_ID == OS_ONE)
  {
    /* Init System Timer for Counter */
    Os_InitTimer1();
  }
  #endif
  #endif /* #if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO) */

  #if (OS_TIMING_PROTECTION == STD_ON)
  /* Init TCPWM - TCPWM0 Group #2, Counter #1, #2 */
  Os_InitTCPWM();
  #endif /* #if (OS_TIMING_PROTECTION == STD_ON) */
}

/***************************************************************************//**
 * Function             : Os_GetCurrentTCPWM
 *
 * Service ID           : NA
 *
 * Description          : Get current TCPWM count
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddTimerId    TCPWM id
 *
 * @return              : Current TCPWM Tick
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(TickType, OS_CODE) Os_GetCurrentTCPWM(Os_TimerIdType LddTimerId)
{
  TickType LddCurrentCnt;

  switch (LddTimerId)
  {
    /* TCPWM0 Group #2, Counter #1 */
    case OS_TCPWM0_2_1:
      LddCurrentCnt = OS_TCPWM0_GRP2_CNT1_COUNTER;
      break;
    /* TCPWM0 Group #2, Counter #2 */
    case OS_TCPWM0_2_2:
      LddCurrentCnt = OS_TCPWM0_GRP2_CNT2_COUNTER;
      break;
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    /* TCPWM0 Group #2, Counter #3 */
    case OS_TCPWM0_2_3:
      LddCurrentCnt = OS_TCPWM0_GRP2_CNT3_COUNTER;
      break;
    /* TCPWM0 Group #2, Counter #4 */
    case OS_TCPWM0_2_4:
      LddCurrentCnt = OS_TCPWM0_GRP2_CNT4_COUNTER;
      break;
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    /* TCPWM1 Group #2, Counter #1 */
    case OS_TCPWM1_2_1:
      LddCurrentCnt = OS_TCPWM1_GRP2_CNT1_COUNTER;
      break;
    /* TCPWM1 Group #2, Counter #2 */
    case OS_TCPWM1_2_2:
      LddCurrentCnt = OS_TCPWM1_GRP2_CNT2_COUNTER;
      break;
    #endif
    default:
      LddCurrentCnt = (TickType)OS_ZERO;
      break;
  }

  return LddCurrentCnt;
}
#endif /* #if (OS_TIMING_PROTECTION == STD_ON) */

/*******************************************************************************
 * Function Name        : Os_GetTimeElapsedService
 *
 * Service ID           : NA
 *
 * Description          : This service is used to measure the time elapsed of
 *                        watchdog
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]           TimerType Budget Timer or Time Frame Timer
 * @param[in]           TimeElapsed Elapsed Time after measure
 *
 * @return              : TRUE - Timer is running, FALSE - Timer expired
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulBudgetTimerCount, Os_GulTFTimerCount
 *
 *                        Function(s) invoked    :
 *                        Os_CheckTimerExpired(), Os_GetElapsedTick()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(boolean, OS_CODE) Os_GetTimeElapsedService(uint8 TimerType,
                                                        TickRefType TimeElapsed)
{
  TickType LddLoadvalueTick;
  TickType LddCurrentTick;
  boolean LblReturnValue;
  boolean LblTimeExpired;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  LblReturnValue = OS_TRUE;
  *TimeElapsed = (TickType)OS_ZERO;

  if (TimerType == OS_BUDGET_WATCHDOG)
  {
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_1);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_3);
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_1);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM1_2_1);
    }
    #endif
    #else
    LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_1);
    #endif

    if (LblTimeExpired == OS_TRUE)
    {
      LblReturnValue = OS_FALSE;
    }
    else
    {
      LddLoadvalueTick = Os_GulBudgetTimerCount[OS_CORE_ID];
      #if (OS_MULTICORE == STD_ON)
      #if (OS_PROCESSOR_SERIES == CYT4BB)
      if (OS_CORE_ID == OS_ZERO)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT1_COUNTER;
      }
      else if (OS_CORE_ID == OS_ONE)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT3_COUNTER;
      }
      #elif (OS_PROCESSOR_SERIES == CYT4BF)
      if (OS_CORE_ID == OS_ZERO)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT1_COUNTER;
      }
      else if (OS_CORE_ID == OS_ONE)
      {
        LddCurrentTick = OS_TCPWM1_GRP2_CNT1_COUNTER;
      }
      #endif
      #else
      LddCurrentTick = OS_TCPWM0_GRP2_CNT1_COUNTER;
      #endif
      *TimeElapsed = Os_GetElapsedTick(LddLoadvalueTick, LddCurrentTick,
    		  OS_TCPWM_N_GRP2_CNT_MAX);
    }
  } /* End of if (TimerType == OS_BUDGET_WATCHDOG) */
  else
  {
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_2);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_4);
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_2);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM1_2_2);
    }
    #endif
    #else
    LblTimeExpired = Os_CheckTimerExpired(OS_TCPWM0_2_2);
    #endif

    if (LblTimeExpired == OS_TRUE)
    {
      LblReturnValue = OS_FALSE;
    }
    else
    {
      LddLoadvalueTick = Os_GulTFTimerCount[OS_CORE_ID];
      #if (OS_MULTICORE == STD_ON)
      #if (OS_PROCESSOR_SERIES == CYT4BB)
      if (OS_CORE_ID == OS_ZERO)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT2_COUNTER;
      }
      else if (OS_CORE_ID == OS_ONE)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT4_COUNTER;
      }
      #elif (OS_PROCESSOR_SERIES == CYT4BF)
      if (OS_CORE_ID == OS_ZERO)
      {
        LddCurrentTick = OS_TCPWM0_GRP2_CNT2_COUNTER;
      }
      else if (OS_CORE_ID == OS_ONE)
      {
        LddCurrentTick = OS_TCPWM1_GRP2_CNT2_COUNTER;
      }
      #endif
      #else
      LddCurrentTick = OS_TCPWM0_GRP2_CNT2_COUNTER;
      #endif
      *TimeElapsed = Os_GetElapsedTick(LddLoadvalueTick, LddCurrentTick,
    		  OS_TCPWM_N_GRP2_CNT_MAX);
    }
  } /* End of else */

  return LblReturnValue;
} /* End of Os_GetTimeElapsedService(uint8 TimerType, TickRefType TimeElapsed)
   **/
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*******************************************************************************
 * Function             : Os_InitSysTick
 *
 * Service ID           : NA
 *
 * Description          : This function initializes SysTick
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : Interrupt is disabled
 *
 * @remarks             : Global Variable(s)     :
 *
 *
 *                        Function(s) invoked    :
 *
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_HARDWARE_COUNTER_COUNT != OS_PRE_ZERO)
static FUNC(void, OS_CODE) Os_InitSysTick(void)
{
  OS_SYST_CSR.CLKSOURCE = OS_SYST_CSR_CLKSOURCE_PROCESSOR;
}
#endif

/***************************************************************************//**
 * Function             : Os_InitTCPWM
 *
 * Service ID           : NA
 *
 * Description          : This function initializes TCPWM 
 *                        (TCPWM0 Group #2, Counter #1, #2)
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : Interrupt is disabled
 *
 * @remarks             : Global Variable(s)     :
 *
 *
 *                        Function(s) invoked    :
 *
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
 #if (OS_TIMING_PROTECTION == STD_ON)  
static FUNC(void, OS_CODE) Os_InitTCPWM(void)
{
  /* CLK_PERI(80MHz) is set by CM0+ */

  #if (OS_PROCESSOR_SERIES == CYT2B7)
  /* Set PERI_CLOCK_CTL[107] for 'TCPWM0 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL107.U = 0x100u;
  /* Set PERI_CLOCK_CTL[108] for 'TCPWM0 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL108.U = 0x100u;
  #elif (OS_PROCESSOR_SERIES == CYT2B9)
  /* Set PERI_CLOCK_CTL[117] for 'TCPWM0 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL117.U = 0x100u;
  /* Set PERI_CLOCK_CTL[118] for 'TCPWM0 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL118.U = 0x100u;
  #elif (OS_PROCESSOR_SERIES == CYT2BL)
  /* Set PERI_CLOCK_CTL[117] for 'TCPWM0 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL117.U = 0x100u;
  /* Set PERI_CLOCK_CTL[118] for 'TCPWM0 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_CLOCK_CTL118.U = 0x100u;
  #elif (OS_PROCESSOR_SERIES == CYT4BB)
  /* Set PERI_PCLK_GR1_CLOCK_CTL[114] for 'TCPWM0 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL114.U = 0x100u;
  /* Set PERI_PCLK_GR1_CLOCK_CTL[115] for 'TCPWM0 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL115.U = 0x100u;
  /* Set PERI_PCLK_GR1_CLOCK_CTL[116] for 'TCPWM0 Group #2, Counter #3'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL116.U = 0x100u;
  /* Set PERI_PCLK_GR1_CLOCK_CTL[117] for 'TCPWM0 Group #2, Counter #4'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL117.U = 0x100u;
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  /* Set PERI_PCLK_GR0_CLOCK_CTL[13] for 'TCPWM0 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR0_CLOCK_CTL13.U = 0x100u;
  /* Set PERI_PCLK_GR0_CLOCK_CTL[14] for 'TCPWM0 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR0_CLOCK_CTL14.U = 0x100u;
  /* Set PERI_PCLK_GR1_CLOCK_CTL[142] for 'TCPWM1 Group #2, Counter #1'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL142.U = 0x100u;
  /* Set PERI_PCLK_GR1_CLOCK_CTL[143] for 'TCPWM1 Group #2, Counter #2'
   * TYPE_SEL: 1, DIV_SEL: 0 => Select PERI_DIV_16_CTL[0] */
  OS_PERI_PCLK_GR1_CLOCK_CTL143.U = 0x100u;
  #else
  #error "Specified MCU is not supported."
  #endif

  #if (OS_PROCESSOR_SERIES == CYT2B7)
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_DIV_16_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_DIV_CMD.U = 0x83FF0100u;
  #elif (OS_PROCESSOR_SERIES == CYT2B9)
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_DIV_16_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_DIV_CMD.U = 0x83FF0100u;
  #elif (OS_PROCESSOR_SERIES == CYT2BL)
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_DIV_16_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_DIV_CMD.U = 0x83FF0100u;
  #elif (OS_PROCESSOR_SERIES == CYT4BB)
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_PCLK_GR0_CLOCK_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_PCLK_GR0_DIV_CMD.U = 0x83FF0100u;  
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_PCLK_GR0_DIV_16_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_PCLK_GR0_DIV_CMD.U = 0x83FF0100u;  
  /* Set 79 to PERI_DIV_16_CTL[0].INT16_DIV
   * PCLK will be 80MHz(= 80MHz / (0+1)) */
  OS_PERI_PCLK_GR1_DIV_16_CTL0.B.INT16_DIV = 0u;
  /* Set 0x83FF0100 to PERI_DIV_CMD
   * DIV_SEL: 0, TYPE_SEL: 1, ENABLE: 1, etc: default
   * => Turn on PERI_DIV_16_CTL[0].EN */
  OS_PERI_PCLK_GR1_DIV_CMD.U = 0x83FF0100u;  
  #else
  #error "Specified MCU is not supported."
  #endif
}
#endif /* #if (OS_TIMING_PROTECTION == STD_ON) */

/*******************************************************************************
 * Function             : Os_StartTimerHw
 *
 * Service ID           : NA
 *
 * Description          : Start a timer interrupt
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            timerId    Timer interrupt channel id
 * @param [in]            timerCount Next relative Timer count for interrupt
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
FUNC(void, OS_CODE) Os_StartTimerHw(Os_TimerIdType timerId, uint32 timerCount)
{
  switch (timerId)
  {
    case OS_SYSTICK:
      /** 1. Program reload value */
      OS_SYST_RVR = timerCount - 1u;
      /** 2. Clear current value */
      OS_SYST_CVR = 0u;
      /** 3. Program Control and Status register */
      OS_SYST_CSR.TICKINT = STD_ON;
      OS_SYST_CSR.ENABLE = STD_ON;
      break;
    default:
      /* Do nothing */
      break;
  }
}

/***************************************************************************//**
 * Function             : Os_StartTCPWM
 *
 * Service ID           : NA
 *
 * Description          : Start specified TCPWM interrupt
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddTcpwmId, LulTimerCount
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_StartTCPWM(Os_TimerIdType LddTcpwmId, uint32 LulTimerCount)
{
  switch (LddTcpwmId)
  {
    case OS_TCPWM0_2_1:
      Os_StopTCPWM(OS_TCPWM0_2_1);
      OS_TCPWM0_GRP2_CNT1_CTRL.B.ENABLED = 1u;
      OS_TCPWM0_GRP2_CNT1_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM0_GRP2_CNT1_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM0_GRP2_CNT1_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM0_GRP2_CNT1_COUNTER = 0u;
      OS_TCPWM0_GRP2_CNT1_INTR_MASK.B.TC = 1u;
      OS_TCPWM0_GRP2_CNT1_TR_CMD.B.START = 1u;
      break;

    case OS_TCPWM0_2_2:
      Os_StopTCPWM(OS_TCPWM0_2_2);
      OS_TCPWM0_GRP2_CNT2_CTRL.B.ENABLED = 1u;
      OS_TCPWM0_GRP2_CNT2_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM0_GRP2_CNT2_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM0_GRP2_CNT2_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM0_GRP2_CNT2_COUNTER = 0u;
      OS_TCPWM0_GRP2_CNT2_INTR_MASK.B.TC = 1u;
      OS_TCPWM0_GRP2_CNT2_TR_CMD.B.START = 1u;
      break;

    #if (OS_PROCESSOR_SERIES == CYT4BB)
    case OS_TCPWM0_2_3:
      Os_StopTCPWM(OS_TCPWM0_2_3);
      OS_TCPWM0_GRP2_CNT3_CTRL.B.ENABLED = 1u;
      OS_TCPWM0_GRP2_CNT3_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM0_GRP2_CNT3_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM0_GRP2_CNT3_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM0_GRP2_CNT3_COUNTER = 0u;
      OS_TCPWM0_GRP2_CNT3_INTR_MASK.B.TC = 1u;
      OS_TCPWM0_GRP2_CNT3_TR_CMD.B.START = 1u;
      break;

    case OS_TCPWM0_2_4:
      Os_StopTCPWM(OS_TCPWM0_2_4);
      OS_TCPWM0_GRP2_CNT4_CTRL.B.ENABLED = 1u;
      OS_TCPWM0_GRP2_CNT4_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM0_GRP2_CNT4_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM0_GRP2_CNT4_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM0_GRP2_CNT4_COUNTER = 0u;
      OS_TCPWM0_GRP2_CNT4_INTR_MASK.B.TC = 1u;
      OS_TCPWM0_GRP2_CNT4_TR_CMD.B.START = 1u;
      break;
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    case OS_TCPWM1_2_1:
      Os_StopTCPWM(OS_TCPWM1_2_1);
      OS_TCPWM1_GRP2_CNT1_CTRL.B.ENABLED = 1u;
      OS_TCPWM1_GRP2_CNT1_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM1_GRP2_CNT1_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM1_GRP2_CNT1_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM1_GRP2_CNT1_COUNTER = 0u;
      OS_TCPWM1_GRP2_CNT1_INTR_MASK.B.TC = 1u;
      OS_TCPWM1_GRP2_CNT1_TR_CMD.B.START = 1u;
      break;

    case OS_TCPWM1_2_2:
      Os_StopTCPWM(OS_TCPWM1_2_2);
      OS_TCPWM1_GRP2_CNT2_CTRL.B.ENABLED = 1u;
      OS_TCPWM1_GRP2_CNT2_PERIOD.B.PERIOD = LulTimerCount;
      OS_TCPWM1_GRP2_CNT2_CTRL.B.DBG_FREEZE_EN = 1u;
      OS_TCPWM1_GRP2_CNT2_CTRL.B.ONE_SHOT = 1u;
      OS_TCPWM1_GRP2_CNT2_COUNTER = 0u;
      OS_TCPWM1_GRP2_CNT2_INTR_MASK.B.TC = 1u;
      OS_TCPWM1_GRP2_CNT2_TR_CMD.B.START = 1u;
      break;
    #endif

    default:
      break;    
  }
}
#endif /* #if (OS_TIMING_PROTECTION == STD_ON) */

/***************************************************************************//**
 * Function             : Os_StopTCPWM
 *
 * Service ID           : NA
 *
 * Description          : Stop TCPWM timer interrupt
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddTcpwmId    TCPWM interrupt channel id
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
static FUNC(void, OS_CODE) Os_StopTCPWM(Os_TimerIdType LddTcpwmId)
{
  switch (LddTcpwmId)
  {
    case OS_TCPWM0_2_1:
      OS_TCPWM0_GRP2_CNT1_TR_CMD.B.STOP = 1u;
      OS_TCPWM0_GRP2_CNT1_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM0_GRP2_CNT1_INTR.U;
      OS_TCPWM0_GRP2_CNT1_CTRL.B.ENABLED = 0u;
      break;

    case OS_TCPWM0_2_2:
      OS_TCPWM0_GRP2_CNT2_TR_CMD.B.STOP = 1u;
      OS_TCPWM0_GRP2_CNT2_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM0_GRP2_CNT2_INTR.U;
      OS_TCPWM0_GRP2_CNT2_CTRL.B.ENABLED = 0u;
      break;      

    #if (OS_PROCESSOR_SERIES == CYT4BB)
    case OS_TCPWM0_2_3:
      OS_TCPWM0_GRP2_CNT3_TR_CMD.B.STOP = 1u;
      OS_TCPWM0_GRP2_CNT3_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM0_GRP2_CNT3_INTR.U;
      OS_TCPWM0_GRP2_CNT3_CTRL.B.ENABLED = 0u;
      break;

    case OS_TCPWM0_2_4:
      OS_TCPWM0_GRP2_CNT4_TR_CMD.B.STOP = 1u;
      OS_TCPWM0_GRP2_CNT4_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM0_GRP2_CNT4_INTR.U;
      OS_TCPWM0_GRP2_CNT4_CTRL.B.ENABLED = 0u;
      break;      
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    case OS_TCPWM1_2_1:
      OS_TCPWM1_GRP2_CNT1_TR_CMD.B.STOP = 1u;
      OS_TCPWM1_GRP2_CNT1_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM1_GRP2_CNT1_INTR.U;
      OS_TCPWM1_GRP2_CNT1_CTRL.B.ENABLED = 0u;
      break;

    case OS_TCPWM1_2_2:
      OS_TCPWM1_GRP2_CNT2_TR_CMD.B.STOP = 1u;
      OS_TCPWM1_GRP2_CNT2_INTR.B.TC = 1u;
      /* You should read back the register to ensure the completion of register write access,
       * return from the interrupt after clearing the pending register. */
      (void)OS_TCPWM1_GRP2_CNT2_INTR.U;
      OS_TCPWM1_GRP2_CNT2_CTRL.B.ENABLED = 0u;
      break;      
    #endif

    default:
      break;
  }
}
#endif /* #if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function             : Os_CheckTimerExpired
 *
 * Service ID           : NA
 *
 * Description          : Check Timer interrupt flag was set
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            timerId    Timer channel id
 *
 * @return              : TRUE - Timer Interrupt flag set,
 *                        FALSE - Timer Interrupt flag not set
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
FUNC(boolean, OS_CODE) Os_CheckTimerExpired(Os_TimerIdType timerId)
{
  boolean isExpired;
  uint32 timerIntFlag;

  switch (timerId)
  {
    case OS_SYSTICK:
      timerIntFlag = OS_SYST_CSR.COUNTFLAG;
      break;

    case OS_TCPWM0_2_1:
      timerIntFlag = OS_TCPWM0_GRP2_CNT1_INTR.B.TC;
      break;

    case OS_TCPWM0_2_2:
      timerIntFlag = OS_TCPWM0_GRP2_CNT2_INTR.B.TC;
      break;

    #if (OS_PROCESSOR_SERIES == CYT4BB)
    case OS_TCPWM0_2_3:
      timerIntFlag = OS_TCPWM0_GRP2_CNT3_INTR.B.TC;
      break;

    case OS_TCPWM0_2_4:
      timerIntFlag = OS_TCPWM0_GRP2_CNT4_INTR.B.TC;
      break;
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    case OS_TCPWM1_2_1:
      timerIntFlag = OS_TCPWM1_GRP2_CNT1_INTR.B.TC;
      break;

    case OS_TCPWM1_2_2:
      timerIntFlag = OS_TCPWM1_GRP2_CNT2_INTR.B.TC;
      break;
    #endif

    default:
      timerIntFlag = OS_ZERO;
      break;
  }

  if (timerIntFlag != OS_ZERO)
  {
    isExpired = TRUE;
  }
  else
  {
    isExpired = FALSE;
  }

  return isExpired;
}

/*****************************************************************************
 * Function             : Os_ClearTimerIntFlag
 *
 * Service ID           : NA
 *
 * Description          : Clear Timer interrupt flag in register
 *
 * Sync/Async           : Synchronous
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            timerId    Timer interrupt channel id
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
FUNC(void, OS_CODE) Os_ClearTimerIntFlag(Os_TimerIdType timerId)
{
  switch (timerId)
  {
    case OS_SYSTICK:
      OS_SYST_CSR.COUNTFLAG = 0u;
      break;

    case OS_TCPWM0_2_1:
      OS_TCPWM0_GRP2_CNT1_INTR.B.TC = 1u;
      break;

    case OS_TCPWM0_2_2:
      OS_TCPWM0_GRP2_CNT2_INTR.B.TC = 1u;
      break;

    #if (OS_PROCESSOR_SERIES == CYT4BB)
    case OS_TCPWM0_2_3:
      OS_TCPWM0_GRP2_CNT3_INTR.B.TC = 1u;
      break;

    case OS_TCPWM0_2_4:
      OS_TCPWM0_GRP2_CNT4_INTR.B.TC = 1u;
      break;
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    case OS_TCPWM1_2_1:
      OS_TCPWM1_GRP2_CNT1_INTR.B.TC = 1u;
      break;

    case OS_TCPWM1_2_2:
      OS_TCPWM1_GRP2_CNT2_INTR.B.TC = 1u;
      break;
    #endif

    default:
      /* Do nothing */
      break;
  }
}


/***************************************************************************
 * Function Name        : Os_StartTimer
 *
 * Service ID           : NA
 *
 * Description          : This service is used to start the timer based on the
 *                        channel passed
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]           TimerType Budget Timer or Time Frame Timer
 * @param[in]           LddTickValue Timer interrupt period
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GulBudgetTimerCount, Os_GulTFTimerCount
 *
 *                        Function(s) invoked    :
 *                        Os_StartTimer()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_StartTimer(uint8 TimerType, TickType LddTickValue)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  if (TimerType == OS_BUDGET_WATCHDOG)
  {
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StartTCPWM(OS_TCPWM0_2_1, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT1_COUNTER;
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StartTCPWM(OS_TCPWM0_2_3, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT3_COUNTER;
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StartTCPWM(OS_TCPWM0_2_1, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT1_COUNTER;
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StartTCPWM(OS_TCPWM1_2_1, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM1_GRP2_CNT1_COUNTER;
    }
    #endif
    #else
    Os_StartTCPWM(OS_TCPWM0_2_1, LddTickValue);
    Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT1_COUNTER;
    #endif
  }
  else
  {
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StartTCPWM(OS_TCPWM0_2_2, LddTickValue);
      Os_GulTFTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT2_COUNTER;
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StartTCPWM(OS_TCPWM0_2_4, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT4_COUNTER;
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StartTCPWM(OS_TCPWM0_2_2, LddTickValue);
      Os_GulTFTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT2_COUNTER;
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StartTCPWM(OS_TCPWM1_2_2, LddTickValue);
      Os_GulBudgetTimerCount[OS_CORE_ID] = OS_TCPWM1_GRP2_CNT2_COUNTER;
    }
    #endif
    #else
    Os_StartTCPWM(OS_TCPWM0_2_2, LddTickValue);
    Os_GulTFTimerCount[OS_CORE_ID] = OS_TCPWM0_GRP2_CNT2_COUNTER;
    #endif
  }
} /* End of Os_StartTimer(uint8 TimerType, TickType LddTickValue) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function Name        : Os_StopTimer
 *
 * Service ID           : NA
 *
 * Description          : This service is used to stop the timer based on the
 *                        channel passed
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param[in]           TimerType Budget Timer or Time Frame Timer
 *
 * @return              : void
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_StopTimerHw()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 ******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_StopTimer(uint8 TimerType)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  if (TimerType == OS_BUDGET_WATCHDOG)
  {
    /* Stop the timer */
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StopTCPWM(OS_TCPWM0_2_1);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StopTCPWM(OS_TCPWM0_2_3);
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StopTCPWM(OS_TCPWM0_2_1);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StopTCPWM(OS_TCPWM1_2_1);
    }
    #endif
    #else
    Os_StopTCPWM(OS_TCPWM0_2_1);
    #endif
  }
  else
  {
    /* Stop the timer */
    #if (OS_MULTICORE == STD_ON)
    #if (OS_PROCESSOR_SERIES == CYT4BB)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StopTCPWM(OS_TCPWM0_2_2);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StopTCPWM(OS_TCPWM0_2_4);
    }
    #elif (OS_PROCESSOR_SERIES == CYT4BF)
    if (OS_CORE_ID == OS_ZERO)
    {
      Os_StopTCPWM(OS_TCPWM0_2_2);
    }
    else if (OS_CORE_ID == OS_ONE)
    {
      Os_StopTCPWM(OS_TCPWM1_2_2);
    }
    #endif
    #else
    Os_StopTCPWM(OS_TCPWM0_2_2);
    #endif
  }
} /* End of Os_StopTimer(uint8 TimerType) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */


/*****************************************************************************
 * Function Name        : Os_TimingBudgetIsr
 *
 * Service ID           : NA
 *
 * Description          : This service is used to service TPS budget interrupt
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GblTPSFlag
 *
 *                        Function(s) invoked    :
 *                        Os_ClearTimerIntFlag()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 *******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
#if ((OS_TASK_TP_EB == STD_ON) || (OS_ISR_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_TimingBudgetIsr(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if(OS_ISR_COUNT > OS_ZERO)
  Os_OldLevel_T LddDefaultLevel = (Os_OldLevel_T) OS_INT_MIN_PRIORITY; /* jsjang_mod */
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if ((Os_GddFaultyTask[OS_CORE_ID] != INVALID_TASK) &&
      (Os_GaaTask[Os_GddFaultyTask[OS_CORE_ID]].ddState == SUSPENDED))
  {
    Os_GddFaultyTask[OS_CORE_ID] = INVALID_TASK;
  }
  else
  {
    Os_GblTPSFlag[OS_CORE_ID] = OS_TRUE;
  }

  #if (OS_MULTICORE == STD_ON)
  #if (OS_PROCESSOR_SERIES == CYT4BB)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_3);
  }
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM1_2_1);
  }
  #endif
  #else
  Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  #endif
} /* End of Os_TimingBudgetIsr(void) */
#endif /* End of if ((OS_TASK_TP_EB == STD_ON) || (OS_ISR_TP_EB == STD_ON)) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function Name        : Os_TimingBudgetIsrCore1
 *
 * Service ID           : NA
 *
 * Description          : This service is used to service TPS budget interrupt for Core1
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GblTPSFlag
 *
 *                        Function(s) invoked    :
 *                        Os_ClearTimerIntFlag()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 *******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
#if ((OS_TASK_TP_EB == STD_ON) || (OS_ISR_TP_EB == STD_ON))
FUNC(void, OS_CODE) Os_TimingBudgetIsrCore1(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if(OS_ISR_COUNT > OS_ZERO)
  Os_OldLevel_T LddDefaultLevel = (Os_OldLevel_T) OS_INT_MIN_PRIORITY; /* jsjang_mod */
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if ((Os_GddFaultyTask[OS_CORE_ID] != INVALID_TASK) &&
      (Os_GaaTask[Os_GddFaultyTask[OS_CORE_ID]].ddState == SUSPENDED))
  {
    Os_GddFaultyTask[OS_CORE_ID] = INVALID_TASK;
  }
  else
  {
    Os_GblTPSFlag[OS_CORE_ID] = OS_TRUE;
  }

  #if (OS_MULTICORE == STD_ON)
  #if (OS_PROCESSOR_SERIES == CYT4BB)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_3);
  }
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM1_2_1);
  }
  #endif
  #else
  Os_ClearTimerIntFlag(OS_TCPWM0_2_1);
  #endif
} /* End of Os_TimingBudgetIsr(void) */
#endif /* End of if ((OS_TASK_TP_EB == STD_ON) || (OS_ISR_TP_EB == STD_ON)) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function Name        : Os_TimeFrameIsr
 *
 * Service ID           : NA
 *
 * Description          : TPS time frame interrupt service routine
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_TimeFrameHandler(), Os_ClearTimerIntFlag()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 *******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
#if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON))
FUNC(void, OS_CODE) Os_TimeFrameIsr(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  Os_TimeFrameHandler();

  #if (OS_MULTICORE == STD_ON)
  #if (OS_PROCESSOR_SERIES == CYT4BB)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_4);
  }
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM1_2_2);
  }
  #endif
  #else
  Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  #endif
} /* End of Os_TimeFrameIsr(void) */
#endif /* ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON)) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function Name        : Os_TimeFrameIsrCore1
 *
 * Service ID           : NA
 *
 * Description          : TPS time frame interrupt service routine for Core1
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *
 * @remarks             : Global Variable(s)     :
 *                        None
 *
 *                        Function(s) invoked    :
 *                        Os_TimeFrameHandler(), Os_ClearTimerIntFlag()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 *******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
#if ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON))
FUNC(void, OS_CODE) Os_TimeFrameIsrCore1(void)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  OS_GET_CORE_ID(OS_CORE_ID);
  #endif

  Os_TimeFrameHandler();

  #if (OS_MULTICORE == STD_ON)
  #if (OS_PROCESSOR_SERIES == CYT4BB)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_4);
  }
  #elif (OS_PROCESSOR_SERIES == CYT4BF)
  if (OS_CORE_ID == OS_ZERO)
  {
    Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  }
  else if (OS_CORE_ID == OS_ONE)
  {
    Os_ClearTimerIntFlag(OS_TCPWM1_2_2);
  }
  #endif
  #else
  Os_ClearTimerIntFlag(OS_TCPWM0_2_2);
  #endif
} /* End of Os_TimeFrameIsr(void) */
#endif /* ((OS_ISR_TP_TF == STD_ON) || (OS_TASK_TP_TF == STD_ON)) */
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

/*****************************************************************************
 * Function Name        : Os_EnableBudgetTimer
 *
 * Service ID           : NA
 *
 * Description          : Check budget violation and Excute the budget handler
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * Parameters           : None
 *
 * @return              : void
 *
 * @pre                 : StartOS() function should be called
 *                        Interrupt should be disabled
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GblTPSFlag, Os_GucInKernel,
 *                        Os_GpStaticTask, Os_GulKernelSP, Os_GulKernelSPBase
 *
 *                        Function(s) invoked    :
 *                        Os_OsWdgHandler(), Os_DoContextSwitch()
 *
 * {Ref: SWR_OS_CYTXXX_006}
 *
 * @ingroup               OS_CYTXXX_ESDD_005
 *******************************************************************************/
#if (OS_TIMING_PROTECTION == STD_ON)
FUNC(void, OS_CODE) Os_EnableBudgetTimer(void)
{
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpNewTaskISR;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  #if(OS_ISR_COUNT > OS_ZERO)
  Os_OldLevel_T LddDefaultLevel = (Os_OldLevel_T) OS_INT_MIN_PRIORITY;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  if ((Os_GblTPSFlag[OS_CORE_ID] == OS_TRUE) &&
      (Os_GucNestingCAT1ISR[OS_CORE_ID] == (uint8)OS_ZERO))
  {
    Os_GblTPSFlag[OS_CORE_ID] = OS_FALSE;

    /* Jump to watchdog handler. Previous Task or ISR will be killed */
    Os_OsWdgHandler();
    Os_GddFaultyTask[OS_CORE_ID] = INVALID_TASK;
    /* Running Task or ISR was killed. Need Context switching */
    LpNewTaskISR = Os_GpStaticTask[OS_CORE_ID];
    if (LpNewTaskISR->usType != OS_ISR2)
    {
      Os_GusCallevelCheck[OS_CORE_ID] = (uint16)OS_CONTEXT_NONE;
#if(OS_ISR_COUNT > OS_ZERO)
      /* Set lowest priority */
      Os_ResumeInterrupts(&LddDefaultLevel);
#endif
      /* Discard kernel stack(stacked by ISR) */
      Os_GulKernelSP[OS_CORE_ID] = Os_GulKernelSPBase[OS_CORE_ID];
    }
    else
    {
      Os_GusCallevelCheck[OS_CORE_ID] = (uint16)OS_CONTEXT_CAT2ISR;
    }
    Os_GucInKernel[OS_CORE_ID] = (uint8)OS_ZERO;
    Os_GucSchedReq[OS_CORE_ID] = (uint8)OS_ZERO;

    if(Os_GucKillCAT2ISR[OS_CORE_ID] == (uint8)OS_ZERO)
    {
      Os_DoContextSwitch(LpNewTaskISR->pContext);
    }
    else
    {
      /* Need to go to the killed ISR to solve nesting problem */
      Os_DoContextSwitch(LpNewTaskISR->pContext);
    }
  }
}
#else
/* polyspace<MISRA-C3:8.5:Not a defect:Justify with annotations> This function is defined in .s. So external definition is not visible in Polyspace  */
extern FUNC(void, OS_CODE) Os_EnableBudgetTimer(void);
FUNC(void, OS_CODE) Os_EnableBudgetTimer(void) {} // Empty function for being referenced by Os_Arch_Except.s
#endif /* End of if (OS_TIMING_PROTECTION == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<RTE:OBAI:Not a defect:Justify with annotations> Configured array index */
/* polyspace:end<MISRA-C3:8.4:Not a defect:Justify with annotations> External linkage is defined in other location */
/* polyspace:end<MISRA-C3:8.7:Not a defect:Justify with annotations> Function may be referenced in other features */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
