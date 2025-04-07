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
**  SRC-MODULE: Os_Arch_Regs.h                                                **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Header file for CYTxxx related register                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]:       Yes                                    **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]:    No                                     **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.4.0     04-Jun-2021    YH.Han        Redmine #29686, #31652              **
** 2.3.0     26-Jan-2021    YH.Han        Redmine #27953                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 2.0.1     10-AUG-2020    JH.Cho        Redmine #24903, #25096              **
** 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:11.4 [Justified:Medium] "To access Registers" */
/* polyspace-begin MISRA-C3:19.2 [Justified:Low] "These unions are used to specify register" */
/* polyspace:begin<MISRA-C3:12.2:Not a defect:Justify with annotations> shift operation does not have any effect */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To access Registers */

#ifndef OS_ARCH_REGS_H_
#define OS_ARCH_REGS_H_

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/**
 * @addtogroup OS_CYTXXX_ESDD
 * @{ */

/** Macro for PRIV bit mask
 * \n{Ref: SWR_OS_CYTXXX_006} */
#define OS_MASK_MSR_PR                              (0x00004000U)

 /** Macro for base priority
 * \n{Ref: SWR_OS_CYTXXX_006} */
#define OS_MASK_BASEPRI                             (0x00000000U)

/** Macro for CPU_INT_VALID bit mask of the CPUSS_CMx_SYSTEM_INT_CTLn (x: 4, 7_0, 7_1)
 * \n{Ref: SWR_OS_CYTXXX_006} */
#define OS_MASK_CPU_INT_VALID                       (0x80000000U)

 /** Macro for valid LSB of IPR(i.e Priority should be shifted by this value)
 * \n{Ref: SWR_OS_CYTXXX_006} */
#define OS_IPR_LSB                                  (0x00000005U)


/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/** @} */

#if (OS_FPU_SUPPORT == STD_ON)
extern FUNC(uint32, OS_CODE) Os_GetFpscr(void);
extern void Os_SetFpscr(uint32 param);
#endif
extern uint32 Os_GetMSP(void);
extern void   Os_SetMSP(uint32 cortexM_msp);
extern uint32 Os_GetPSP(void);
extern void   Os_SetPSP(uint32 cortexM_psp);
extern uint32 Os_GetCONTROL(void);
extern uint32 Os_IrqGetVectNumber(void);

/*
 * Peripheral interconnect (PERI)
 */

/* Structure of PERI_DIV_CMD (Divider command) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 DIV_SEL        : 8;
    Os_Reg32 TYPE_SEL       : 2;
    Os_Reg32                : 6;
    Os_Reg32 PA_DIV_SEL     : 8;
    Os_Reg32 PA_TYPE_SEL    : 2;
    Os_Reg32                : 4;
    Os_Reg32 DISABLE        : 1;
    Os_Reg32 ENABLE         : 1;
  } B;
  sint32 I;
  uint32 U;
} OS_PERI_DIV_CMD_type;

/* PERI_DIV_CMD register */
#define OS_PERI_DIV_CMD               (*(volatile OS_PERI_DIV_CMD_type *)(0x40000400u))

/* PERI_PCLK_GR0_DIV_CMD register */
#define OS_PERI_PCLK_GR0_DIV_CMD      (*(volatile OS_PERI_DIV_CMD_type *)(0x40040000u))

/* PERI_PCLK_GR1_DIV_CMD register */
#define OS_PERI_PCLK_GR1_DIV_CMD      (*(volatile OS_PERI_DIV_CMD_type *)(0x40042000u))

/*
 * Peripheral interconnect (PERI)
 */

/* Structure of PERI_DIV_16_CTL (Divider control (for 16.0 divider)) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 EN             : 1;
    Os_Reg32                : 7;
    Os_Reg32 INT16_DIV      : 16;
    Os_Reg32                : 8;
  } B;
  sint32 I;
  uint32 U;
} OS_PERI_DIV_16_CTL_type;

/* PERI_DIV_16_CTL register */
#define OS_PERI_DIV_16_CTL0           (*(volatile OS_PERI_DIV_16_CTL_type *)(0x40001400u))

/* PERI_PCLK_GR1_DIV_16_CTL register */
#define OS_PERI_PCLK_GR0_DIV_16_CTL0  (*(volatile OS_PERI_DIV_16_CTL_type *)(0x40041400u))

/* PERI_PCLK_GR1_DIV_16_CTL register */
#define OS_PERI_PCLK_GR1_DIV_16_CTL0  (*(volatile OS_PERI_DIV_16_CTL_type *)(0x40043400u))

/* Structure of PERI_CLOCK_CTL (Clock control) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 DIV_SEL        : 5;
    Os_Reg32                : 3;
    Os_Reg32 TYPE_SEL       : 2;
    Os_Reg32                : 22;
  } B;
  sint32 I;
  uint32 U;
} OS_PERI_CLOCK_CTL_type;

#if (OS_PROCESSOR_SERIES == CYT2B7)
/* PERI_CLOCK_CTL107 register */
#define OS_PERI_CLOCK_CTL107  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DACu))
/* PERI_CLOCK_CTL108 register */
#define OS_PERI_CLOCK_CTL108  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DB0u))
#elif (OS_PROCESSOR_SERIES == CYT2B9)
/* PERI_CLOCK_CTL117 register */
#define OS_PERI_CLOCK_CTL117  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DD4u))
/* PERI_CLOCK_CTL118 register */
#define OS_PERI_CLOCK_CTL118  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DD8u))
#elif (OS_PROCESSOR_SERIES == CYT2BL)
/* PERI_CLOCK_CTL117 register */
#define OS_PERI_CLOCK_CTL117  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DD4u))
/* PERI_CLOCK_CTL118 register */
#define OS_PERI_CLOCK_CTL118  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40000DD8u))
#elif (OS_PROCESSOR_SERIES == CYT4BB)
/* PERI_PCLK_GR1_CLOCK_CTL114 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL114  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042DC8u))
/* PERI_PCLK_GR1_CLOCK_CTL115 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL115  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042DCCu))
/* PERI_PCLK_GR1_CLOCK_CTL116 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL116  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042DD0u))
/* PERI_PCLK_GR1_CLOCK_CTL117 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL117  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042DD4u))
#elif (OS_PROCESSOR_SERIES == CYT4BF)
/* PERI_PCLK_GR0_CLOCK_CTL13 register */
#define OS_PERI_PCLK_GR0_CLOCK_CTL13  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40040C34u))
/* PERI_PCLK_GR0_CLOCK_CTL14 register */
#define OS_PERI_PCLK_GR0_CLOCK_CTL14  (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40040C38u))
/* PERI_PCLK_GR1_CLOCK_CTL142 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL142 (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042E38u))
/* PERI_PCLK_GR1_CLOCK_CTL143 register */
#define OS_PERI_PCLK_GR1_CLOCK_CTL143 (*(volatile OS_PERI_CLOCK_CTL_type *)(0x40042E3Cu))
#else
#error "Specified MCU is not supported."
#endif

/* Structure of TCPWM_GRP_CNT_CTRL (Counter control register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 AUTO_RELOAD_CC0      : 1;
    Os_Reg32 AUTO_RELOAD_CC1      : 1;
    Os_Reg32 AUTO_RELOAD_PERIOD   : 1;
    Os_Reg32 AUTO_RELOAD_LINE_SEL : 1;
    Os_Reg32 CC0_MATCH_UP_EN      : 1;
    Os_Reg32 CC0_MATCH_DOWN_EN    : 1;
    Os_Reg32 CC1_MATCH_UP_EN      : 1;
    Os_Reg32 CC1_MATCH_DOWN_EN    : 1;
    Os_Reg32 PWM_IMM_KILL         : 1;
    Os_Reg32 PWM_STOP_ON_KILL     : 1;
    Os_Reg32 PWM_SYNC_KILL        : 1;
    Os_Reg32                      : 1;
    Os_Reg32 PWM_DISABLE_MODE     : 2;
    Os_Reg32                      : 2;
    Os_Reg32 UP_DOWN_MODE         : 2;
    Os_Reg32 ONE_SHOT             : 1;
    Os_Reg32                      : 1;
    Os_Reg32 QUAD_ENCODING_MODE   : 2;
    Os_Reg32                      : 2;
    Os_Reg32 MODE                 : 3;
    Os_Reg32                      : 3;
    Os_Reg32 DBG_FREEZE_EN        : 1;
    Os_Reg32 ENABLED              : 1;
  } B;
  sint32 I;
  uint32 U;
} OS_TCPWM_GRP_CNT_CTRL_type;

/* Structure of TCPWM_GRP_CNT_TR_CMD (Counter trigger command register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 CAPTURE0       : 1;
    Os_Reg32                : 1;
    Os_Reg32 RELOAD         : 1;
    Os_Reg32 STOP           : 1;
    Os_Reg32 START          : 1;
    Os_Reg32 CAPTURE1       : 1;
    Os_Reg32                : 26;
  } B;
  sint32 I;
  uint32 U;
} OS_TCPWM_GRP_CNT_TR_CMD_type;

/* Structure of TCPWM_GRP_CNT_PERIOD (Counter period register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 PERIOD         : 32;
  } B;
  sint32 I;
  uint32 U;
} OS_TCPWM_GRP_CNT_PERIOD_type;

/* Structure of TCPWM_GRP_CNT_INTR (Interrupt request register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 TC             : 1;
    Os_Reg32 CC0_MATCH      : 1;
    Os_Reg32 CC1_MATCH      : 1;
    Os_Reg32                : 29;
  } B;
  sint32 I;
  uint32 U;
} OS_TCPWM_GRP_CNT_INTR_type;

/* Structure of TCPWM_GRP_CNT_INTR_MASK (Interrupt mask register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 TC             : 1;
    Os_Reg32 CC0_MATCH      : 1;
    Os_Reg32 CC1_MATCH      : 1;
    Os_Reg32                : 29;
  } B;
  sint32 I;
  uint32 U;
} OS_TCPWM_GRP_CNT_INTR_MASK_type;

/* OS_TCPWM0_GRP2_CNT1_CTRL */
#define OS_TCPWM0_GRP2_CNT1_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40390080u))

/* TCPWM0_GRP2_CNT1_COUNTER */
#define OS_TCPWM0_GRP2_CNT1_COUNTER   (*(volatile uint32 *)(0x40390088u))

/* TCPWM0_GRP2_CNT1_PERIOD */
#define OS_TCPWM0_GRP2_CNT1_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x403900A0u))

/* TCPWM0_GRP2_CNT1_TR_CMD */
#define OS_TCPWM0_GRP2_CNT1_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x403900C0u))

/* TCPWM0_GRP2_CNT1_INTR */
#define OS_TCPWM0_GRP2_CNT1_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x403900F0u))

/* TCPWM0_GRP2_CNT1_INTR_MASK */
#define OS_TCPWM0_GRP2_CNT1_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x403900F8u))

/* OS_TCPWM0_GRP2_CNT2_CTRL */
#define OS_TCPWM0_GRP2_CNT2_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40390100u))

/* TCPWM0_GRP2_CNT2_COUNTER */
#define OS_TCPWM0_GRP2_CNT2_COUNTER   (*(volatile uint32 *)(0x40390108u))

/* TCPWM0_GRP2_CNT2_PERIOD */
#define OS_TCPWM0_GRP2_CNT2_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x40390120u))

/* TCPWM0_GRP2_CNT2_TR_CMD */
#define OS_TCPWM0_GRP2_CNT2_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x40390140u))

/* TCPWM0_GRP2_CNT2_INTR */
#define OS_TCPWM0_GRP2_CNT2_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x40390170u))

/* TCPWM0_GRP2_CNT2_INTR_MASK */
#define OS_TCPWM0_GRP2_CNT2_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x40390178u))

#if (OS_PROCESSOR_SERIES == CYT4BB)
/* TCPWM0_GRP2_CNT3_CTRL */
#define OS_TCPWM0_GRP2_CNT3_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40390180u))

/* TCPWM0_GRP2_CNT3_COUNTER */
#define OS_TCPWM0_GRP2_CNT3_COUNTER   (*(volatile uint32 *)(0x40390188u))

/* TCPWM0_GRP2_CNT3_PERIOD */
#define OS_TCPWM0_GRP2_CNT3_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x403901A0u))

/* TCPWM0_GRP2_CNT3_TR_CMD */
#define OS_TCPWM0_GRP2_CNT3_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x403901C0u))

/* TCPWM0_GRP2_CNT3_INTR */
#define OS_TCPWM0_GRP2_CNT3_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x403901F0u))

/* TCPWM0_GRP2_CNT3_INTR_MASK */
#define OS_TCPWM0_GRP2_CNT3_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x403901F8u))

/* TCPWM0_GRP2_CNT4_CTRL */
#define OS_TCPWM0_GRP2_CNT4_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40390200u))

/* TCPWM0_GRP2_CNT4_COUNTER */
#define OS_TCPWM0_GRP2_CNT4_COUNTER   (*(volatile uint32 *)(0x40390208u))

/* TCPWM0_GRP2_CNT4_PERIOD */
#define OS_TCPWM0_GRP2_CNT4_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x40390220u))

/* TCPWM0_GRP2_CNT4_TR_CMD */
#define OS_TCPWM0_GRP2_CNT4_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x40390240u))

/* TCPWM0_GRP2_CNT4_INTR */
#define OS_TCPWM0_GRP2_CNT4_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x40390270u))

/* TCPWM0_GRP2_CNT4_INTR_MASK */
#define OS_TCPWM0_GRP2_CNT4_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x40390278u))
#elif (OS_PROCESSOR_SERIES == CYT4BF)
/* TCPWM1_GRP2_CNT1_CTRL */
#define OS_TCPWM1_GRP2_CNT1_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40590080u))

/* TCPWM1_GRP2_CNT1_COUNTER */
#define OS_TCPWM1_GRP2_CNT1_COUNTER   (*(volatile uint32 *)(0x40590088u))

/* TCPWM1_GRP2_CNT1_PERIOD */
#define OS_TCPWM1_GRP2_CNT1_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x405900A0u))

/* TCPWM1_GRP2_CNT1_TR_CMD */
#define OS_TCPWM1_GRP2_CNT1_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x405900C0u))

/* TCPWM1_GRP2_CNT1_INTR */
#define OS_TCPWM1_GRP2_CNT1_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x405900F0u))

/* TCPWM1_GRP2_CNT1_INTR_MASK */
#define OS_TCPWM1_GRP2_CNT1_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x405900F8u))

/* TCPWM1_GRP2_CNT2_CTRL */
#define OS_TCPWM1_GRP2_CNT2_CTRL      (*(volatile OS_TCPWM_GRP_CNT_CTRL_type *)(0x40590100u))

/* TCPWM1_GRP2_CNT2_COUNTER */
#define OS_TCPWM1_GRP2_CNT2_COUNTER   (*(volatile uint32 *)(0x40590108u))

/* TCPWM1_GRP2_CNT2_PERIOD */
#define OS_TCPWM1_GRP2_CNT2_PERIOD    (*(volatile OS_TCPWM_GRP_CNT_PERIOD_type *)(0x40590120u))

/* TCPWM1_GRP2_CNT2_TR_CMD */
#define OS_TCPWM1_GRP2_CNT2_TR_CMD    (*(volatile OS_TCPWM_GRP_CNT_TR_CMD_type *)(0x40590140u))

/* TCPWM1_GRP2_CNT2_INTR */
#define OS_TCPWM1_GRP2_CNT2_INTR      (*(volatile OS_TCPWM_GRP_CNT_INTR_type *)(0x40590170u))

/* TCPWM1_GRP2_CNT2_INTR_MASK */
#define OS_TCPWM1_GRP2_CNT2_INTR_MASK (*(volatile OS_TCPWM_GRP_CNT_INTR_MASK_type *)(0x40590178u))
#endif

/* Max counter value of TCPWM0_GRP2 and TCMWP1_GRP2 */
#define OS_TCPWM_N_GRP2_CNT_MAX        (0xFFFFFFFFu)

/*
 * SBC (System Control Block)
 */

/* Structure of HFSR (Hard Fault Status Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32                : 1;
    Os_Reg32 VECTTBL        : 1;
    Os_Reg32                : 28;
    Os_Reg32 FORCED         : 1;
    Os_Reg32 DEBUGEVT       : 1;
  } B;
  sint32 I;
  uint32 U;
} OS_SBC_HFSR_type;

/* HFSR register */
#define OS_SBC_HFSR          (*(volatile OS_SBC_HFSR_type *)(0xE000ED2Cu))

/* Structure of CFSR (Configurable Fault Status Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 MemManage      : 8;  /* MemManage */
    Os_Reg32 BusFault       : 8;  /* BusFault */
    Os_Reg32 UsageFault     : 16; /* UsageFault */
  } B;
  sint32 I;
  uint32 U;
} OS_SBC_CFSR_type;

/* CFSR register */
#define OS_SBC_CFSR          (*(volatile OS_SBC_CFSR_type *)(0xE000ED28u))

/* Mask for MMFSR error bit */
#define OS_MMFSR_ERROR_MASK  0x3Fu

/* Mask for MMFSR valid bit */
#define OS_MMFSR_VALID_MASK  0x80u

/* MMFAR register */
#define OS_SBC_MMFAR        (*(volatile uint32 *) 0xE000ED34u)

/* Mask for BFSR error bit */
#define OS_BFSR_ERROR_MASK   0x3Fu

/* Mask for BFSR valid bit */
#define OS_BFSR_VALID_MASK   0x80u

/* BFAR register */
#define OS_SBC_BFAR         (*(volatile uint32 *) 0xE000ED38u)


/** Address of the System Handler Priority Register 3 */
#define OS_SHPR3_ADDR   ((volatile uint32 *)0xE000ED20u)

/* Structure of CCR (Configuration and Control Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 NONBASETHRDENA      : 1;  /* NONBASETHRDENA */
    Os_Reg32 USERSETMPEND        : 1;  /* USERSETMPEND */
    Os_Reg32                     : 1;  /* Reserved */
    Os_Reg32 UNALIGN_TRP         : 1;  /* UNALIGN_TRP */
    Os_Reg32 DIV_0_TRP           : 1;  /* DIV_0_TRP */
    Os_Reg32                     : 3;  /* Reserved */
    Os_Reg32 BFHFNMIGN           : 1;  /* BFHFNMIGN */
    Os_Reg32 STKALIGN            : 1;  /* STKALIGN */
    Os_Reg32                     : 6;  /* Reserved */
    Os_Reg32 DC                  : 1;  /* DC */
    Os_Reg32 IC                  : 1;  /* IC */
    Os_Reg32 BP                  : 1;  /* BP */
    Os_Reg32                     : 13; /* Reserved */
  } B;
  sint32 I;
  uint32 U;
} OS_SCB_CCR_type;

/* CFSR register */
#define OS_SCB_CCR          (*(volatile OS_SCB_CCR_type *)(0xE000ED14u))

/* Structure of AIRCR (Application Interrupt and Reset Control Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 VECTRESET           : 1;  /* VECTRESET */
    Os_Reg32 VECTCLRACTIVE       : 1;  /* VECTCLRACTIVE */
    Os_Reg32 SYSRESETREQ         : 1;  /* SYSRESETREQ */
    Os_Reg32                     : 5;  /* Reserved */
    Os_Reg32 PRIGROUP            : 3;  /* PRIGROUP */
    Os_Reg32                     : 4;  /* Reserved */
    Os_Reg32 ENDIANNESS          : 1;  /* ENDIANNESS */
    Os_Reg32 VECTKEY             : 16; /* VECTKEY */
  } B;
  sint32 I;
  uint32 U;
} OS_SCB_AIRCR_type;

/* CFSR register */
#define OS_SCB_AIRCR       (*(volatile OS_SCB_AIRCR_type *)(0xE000ED0Cu))

/* Structure of CPACR (Coprocessor Access Control Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32                     : 20;  /* Reserved */
    Os_Reg32 CP11                : 2;
    Os_Reg32 CP10                : 2;
    Os_Reg32                     : 8;   /* Reserved */
  } B;
  sint32 I;
  uint32 U;
} OS_SCB_CPACR_type;

#define OS_SCB_CPACR          (*(volatile OS_SCB_CPACR_type *)(0xE000ED88u))

#define OS_SCB_CPACR_CP10_ACCESS_DENIED     0x00u
#define OS_SCB_CPACR_CP10_PRIVILEGED_ACCSS  0x01u
#define OS_SCB_CPACR_CP10_RESERVED          0x02u
#define OS_SCB_CPACR_CP10_FULL_ACCESS       0x03u
#define OS_SCB_CPACR_CP11_ACCESS_DENIED     0x00u
#define OS_SCB_CPACR_CP11_PRIVILEGED_ACCSS  0x01u
#define OS_SCB_CPACR_CP11_RESERVED          0x02u
#define OS_SCB_CPACR_CP11_FULL_ACCESS       0x03u

/* Structure of FPCCR (Floating-point Context Control Register) register */
typedef volatile union
{
  struct
  {
    Os_Reg32 LSPACT              : 1;
    Os_Reg32 USER                : 1;
    Os_Reg32                     : 1;   /* Reserved */
    Os_Reg32 THREAD              : 1;
    Os_Reg32 HFRDY               : 1;
    Os_Reg32 MMRDY               : 1;
    Os_Reg32 BFRDY               : 1;
    Os_Reg32                     : 1;   /* Reserved */
    Os_Reg32 MONRDY              : 1;
    Os_Reg32                     : 21;   /* Reserved */
    Os_Reg32 LSPEN               : 1;
    Os_Reg32 ASPEN               : 1;
  } B;
  sint32 I;
  uint32 U;
} OS_FPU_FPCCR_type;

#define OS_FPU_FPCCR          (*(volatile OS_FPU_FPCCR_type *)(0xE000EF34u))

#define OS_FPU_FPCCR_LSPEN_DISABLE          0x00u
#define OS_FPU_FPCCR_LSPEN_ENABLE           0x01u
#define OS_FPU_FPCCR_ASPEN_DISABLE          0x00u
#define OS_FPU_FPCCR_ASPEN_ENABLE           0x01u

/*
 * SYSTICK (The System Timer)
 */

/** Structure of SysTick Control and Status Register */
typedef volatile struct
{
  Os_Reg32 ENABLE         : 1;  /**< Enables the counter */
  Os_Reg32 TICKINT        : 1;  /**< Enables SysTick exception request */
  Os_Reg32 CLKSOURCE      : 1;  /**< Indicates the clock source:
                                     0 = external clock, 1 = processor clock */
  Os_Reg32 reserved1      : 13;
  Os_Reg32 COUNTFLAG      : 1;  /**< Returns 1 if timer counted to 0
                                     since last time this was read */
  Os_Reg32 reserved2      : 15;
} OS_SYST_CSR_type;

/** SysTick Control and Status Register */
#define OS_SYST_CSR     (*(volatile OS_SYST_CSR_type *)0xE000E010u)
/** Processor clock value of the SYST_CSR */
#define OS_SYST_CSR_CLKSOURCE_PROCESSOR     (1u)

/** SysTick Reload Value Register(Valid only 24bit) */
#define OS_SYST_RVR     (*(volatile uint32 *)0xE000E014u)

/** SysTick Current Value Register(Valid only 24bit) */
#define OS_SYST_CVR     (*(volatile uint32 *)0xE000E018u)

/*
 * IPC (Inter Process Communication)
 */

/* Structure of IPC_STRUCT_ACQUIRE register */
typedef volatile union
{
  struct
  {
    Os_Reg32 P              :1;
    Os_Reg32 NS             :1;
    Os_Reg32                :2;
    Os_Reg32 PC             :4;
    Os_Reg32 MS             :4;
    Os_Reg32                :19;
    Os_Reg32 SUCCESS        :1;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_ACQUIRE_type;

/* Structure of IPC_STRUCT_RELEASE register */
typedef volatile union
{
  struct
  {
    Os_Reg32 INTR_RELEASE   :16;
    Os_Reg32                :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_RELEASE_type;

/* Structure of IPC_STRUCT_NOTIFY register */
typedef volatile union
{
  struct{
    Os_Reg32 INTR_NOTIFY    :16;
    Os_Reg32                :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_NOTIFY_type;

/* Structure of IPC_STRUCT_DATA0 register */
typedef volatile union
{
  struct{
    Os_Reg32 DATA           :32;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_DATA0_type;

/* Structure of IPC_STRUCT_DATA1 register */
typedef volatile union
{
  struct{
    Os_Reg32 DATA           :32;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_DATA1_type;

/* Structure of IPC_STRUCT_LOCK_STATUS register */
typedef volatile union
{
  struct
  {
    Os_Reg32 P              :1;
    Os_Reg32 NS             :1;
    Os_Reg32                :2;
    Os_Reg32 PC             :4;
    Os_Reg32 MS             :4;
    Os_Reg32                :19;
    Os_Reg32 ACQUIRED       :1;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_STRUCT_LOCK_STATUS_type;

/* Structure of IPC_STRUCT register */
typedef struct
{
  OS_IPC_STRUCT_ACQUIRE_type       ACQUIRE;          /*!< 0x00000000 IPC acquire */
  OS_IPC_STRUCT_RELEASE_type       RELEASE;          /*!< 0x00000004 IPC release */
  OS_IPC_STRUCT_NOTIFY_type        NOTIFY;           /*!< 0x00000008 IPC notification */
  OS_IPC_STRUCT_DATA0_type         DATA0;            /*!< 0x0000000C IPC data 0 */
  OS_IPC_STRUCT_DATA1_type         DATA1;            /*!< 0x00000010 IPC data 1 */
  Os_Reg32                         Reserved[2];
  OS_IPC_STRUCT_LOCK_STATUS_type   LOCK_STATUS;      /*!< 0x0000001C IPC lock status */
} OS_IPC_STRUCT_type;


/* Structure of IPC_INTR_STRUCT_INTR register */
typedef volatile union
{
  struct{
    Os_Reg32 RELEASE        :16;
    Os_Reg32 NOTIFY         :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_INTR_STRUCT_INTR_type;

/* Structure of IPC_INTR_STRUCT_INTR_SET register */
typedef volatile union{
  struct
  {
    Os_Reg32 RELEASE        :16;
    Os_Reg32 NOTIFY         :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_INTR_STRUCT_INTR_SET_type;

/* Structure of IPC_INTR_STRUCT_INTR_MASK register */
typedef volatile union
{
  struct
  {
    Os_Reg32 RELEASE        :16;
    Os_Reg32 NOTIFY         :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_INTR_STRUCT_INTR_MASK_type;

/* Structure of IPC_INTR_STRUCT_INTR_MASKED register */
typedef volatile union
{
  struct
  {
    Os_Reg32 RELEASE        :16;
    Os_Reg32 NOTIFY         :16;
  } B;
  sint32 I;
  uint32 U;
} OS_IPC_INTR_STRUCT_INTR_MASKED_type;

/* Structure of IPC_INTR_STRUCT register */
typedef struct
{
  OS_IPC_INTR_STRUCT_INTR_type        INTR;             /*!< 0x00000000 Interrupt */
  OS_IPC_INTR_STRUCT_INTR_SET_type    INTR_SET;         /*!< 0x00000004 Interrupt set */
  OS_IPC_INTR_STRUCT_INTR_MASK_type   INTR_MASK;        /*!< 0x00000008 Interrupt mask */
  OS_IPC_INTR_STRUCT_INTR_MASKED_type INTR_MASKED;      /*!< 0x0000000C Interrupt masked */
  Os_Reg32                            Reserved[4];
} OS_IPC_INTR_STRUCT_type;                               /*!< Size = 32 (0x20) */


/* Structure of IPC register */
typedef struct
{
  OS_IPC_STRUCT_type              STRUCT[16];         /*!< 0x00000000 IPC structure */
  Os_Reg32                        Reserved[896];
  OS_IPC_INTR_STRUCT_type         INTR_STRUCT[16];    /*!< 0x00001000 IPC interrupt structure */
} OS_IPC_type;                                           /*!< Size = 4608 (0x1200) */

/* IPC Base Address */
#define IPC_BASE        0x40220000UL

/* IPC Register expressed as address */
#define OS_IPC_ADDR     ((volatile OS_IPC_type*)IPC_BASE)

/* IPC Register expressed as pointer */
#define OS_IPC_REG      (*(volatile OS_IPC_type*)IPC_BASE)

/*
 * CPUSS (CPU subsystem)
 */
/* Structure of CPUSS_CM7_1_PWR_CTL register */
typedef volatile union
{
  struct
  {
    Os_Reg32 PWR_MODE       :2;
    Os_Reg32                :14;
    Os_Reg32 VECTKEYSTAT    :16;
  } B;
  sint32 I;
  uint32 U;
} OS_CPUSS_CM7_1_PWR_CTL_type;

#define OS_CPUSS_CM7_1_PWR_CTL       (*(volatile OS_CPUSS_CM7_1_PWR_CTL_type *) 0x40201210u)

/* Structure of CPUSS_CM7_1_VECTOR_TABLE_BASE register */
typedef volatile union
{
  struct
  {
    Os_Reg32                :7;
    Os_Reg32 ADDR25         :25;
  } B;
  sint32 I;
  uint32 U;
} OS_CPUSS_CM7_1_VECTOR_TABLE_BASE_type;

/* CM7_1_VECTOR_TABLE_BASE Register */
#define OS_CPUSS_CM7_1_VECTOR_TABLE_BASE (*(volatile OS_CPUSS_CM7_1_VECTOR_TABLE_BASE_type *) 0x40200600u)

/* Structure of CPUSS_CM7_1_CTL register */
typedef volatile union
{
  struct
  {
    Os_Reg32 PPB_LOCK           :4;
    Os_Reg32 CPU_WAIT           :1;
    Os_Reg32                    :3;
    Os_Reg32 INIT_TCM_EN        :2;
    Os_Reg32 INIT_RMW_EN        :2;
    Os_Reg32                    :4;
    Os_Reg32 ITCM_ECC_EN        :1;
    Os_Reg32 ITCM_ECC_INJ_EN    :1;
    Os_Reg32 ITCM_READ_WS       :1;
    Os_Reg32 ITCM_ECC_CHECK_DIS :1;
    Os_Reg32 DTCM_ECC_EN        :1;
    Os_Reg32 DTCM_ECC_INJ_EN    :1;
    Os_Reg32 DTCM_READ_WS       :1;
    Os_Reg32 TCMC_EN            :1;
    Os_Reg32 IOC_MASK           :1;
    Os_Reg32 DZC_MASK           :1;
    Os_Reg32 OFC_MASK           :1;
    Os_Reg32 UFC_MASK           :1;
    Os_Reg32 IXC_MASK           :1;
    Os_Reg32                    :2;
    Os_Reg32 IDC_MASK           :1;
  } B;
  sint32 I;
  uint32 U;
} OS_CPUSS_CM7_1_CTL_type;

/* CM7_1_CTL Register */
#define OS_CPUSS_CM7_1_CTL           (*(volatile OS_CPUSS_CM7_1_CTL_type *) 0x4020040Cu)


#if (OS_PROCESSOR_SERIES == CYT2B7)
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        8u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   7u
#elif (OS_PROCESSOR_SERIES == CYT2B9)
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        8u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   7u
#elif (OS_PROCESSOR_SERIES == CYT2BL)
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        8u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   7u
#elif (OS_PROCESSOR_SERIES == CYT4BB)
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        16u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   15u
#elif (OS_PROCESSOR_SERIES == CYT4BF)
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        16u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   15u
#else
/* maximum number of MPU regison supported */
#define OS_MPU_MAX_NUM                        8u
/* MPU Region number that is reserved for stack */
#define OS_MPU_REGION_STACK                   7u
#endif

/* MPU Type Register Definitions */
#define OS_MPU_TYPE_IREGION_POS               16u                                           /*!< MPU TYPE: IREGION Position */
#define OS_MPU_TYPE_IREGION_MSK               (0xFFu << OS_MPU_TYPE_IREGION_POS)           /*!< MPU TYPE: IREGION Mask */

#define OS_MPU_TYPE_DREGION_POS               8u                                            /*!< MPU TYPE: DREGION Position */
#define OS_MPU_TYPE_DREGION_MSK               (0xFFu << OS_MPU_TYPE_DREGION_POS)           /*!< MPU TYPE: DREGION Mask */

#define OS_MPU_TYPE_SEPARATE_POS              0u                                            /*!< MPU TYPE: SEPARATE Position */
#define OS_MPU_TYPE_SEPARATE_MSK              (1u << OS_MPU_TYPE_SEPARATE_POS)             /*!< MPU TYPE: SEPARATE Mask */

/* MPU Control Register Definitions */
#define OS_MPU_CTRL_PRIVDEFENA_POS            2u                                            /*!< MPU CTRL: PRIVDEFENA Position */
#define OS_MPU_CTRL_PRIVDEFENA_MSK            (1u << OS_MPU_CTRL_PRIVDEFENA_POS)           /*!< MPU CTRL: PRIVDEFENA Mask */

#define OS_MPU_CTRL_HFNMIENA_POS              1u                                            /*!< MPU CTRL: HFNMIENA Position */
#define OS_MPU_CTRL_HFNMIENA_MSK              (1u << OS_MPU_CTRL_HFNMIENA_POS)             /*!< MPU CTRL: HFNMIENA Mask */

#define OS_MPU_CTRL_ENABLE_POS                0u                                            /*!< MPU CTRL: ENABLE Position */
#define OS_MPU_CTRL_ENABLE_MSK                (1u << OS_MPU_CTRL_ENABLE_POS)               /*!< MPU CTRL: ENABLE Mask */

/* MPU Region Number Register Definitions */
#define OS_MPU_RNR_REGION_POS                 0u                                            /*!< MPU RNR: REGION Position */
#define OS_MPU_RNR_REGION_MSK                 (0xFFu << OS_MPU_RNR_REGION_POS)             /*!< MPU RNR: REGION Mask */

/* MPU Region Base Address Register Definitions */
#define OS_MPU_RBAR_ADDR_POS                  5u                                            /*!< MPU RBAR: ADDR Position */
#define OS_MPU_RBAR_ADDR_MSK                  (0x07FFFFFFu << OS_MPU_RBAR_ADDR_POS)        /*!< MPU RBAR: ADDR Mask */

#define OS_MPU_RBAR_VALID_POS                 4u                                            /*!< MPU RBAR: VALID Position */
#define OS_MPU_RBAR_VALID_MSK                 (0x1u << OS_MPU_RBAR_VALID_POS)              /*!< MPU RBAR: VALID Mask */

#define OS_MPU_RBAR_REGION_POS                0u                                            /*!< MPU RBAR: REGION Position */
#define OS_MPU_RBAR_REGION_MSK                (0xFu << OS_MPU_RBAR_REGION_POS)             /*!< MPU RBAR: REGION Mask */

/* MPU Region Attribute and Size Register Definitions */
#define OS_MPU_RASR_XN_POS                    28u                                           /*!< MPU RASR: ATTRS.XN Position */
#define OS_MPU_RASR_XN_MSK                    (0x1u << OS_MPU_RASR_XN_POS)                 /*!< MPU RASR: ATTRS.XN Mask */

#define OS_MPU_RASR_AP_POS                    24u                                           /*!< MPU RASR: ATTRS.AP Position */
#define OS_MPU_RASR_AP_MSK                    (0x7u << OS_MPU_RASR_AP_POS)                 /*!< MPU RASR: ATTRS.AP Mask */

#define OS_MPU_RASR_TEX_POS                   19u                                           /*!< MPU RASR: ATTRS.TEX Position */
#define OS_MPU_RASR_TEX_MSK                   (0x7u << OS_MPU_RASR_TEX_POS)                /*!< MPU RASR: ATTRS.TEX Mask */

#define OS_MPU_RASR_S_POS                     18u                                           /*!< MPU RASR: ATTRS.S Position */
#define OS_MPU_RASR_S_MSK                     (0x1u << OS_MPU_RASR_S_POS)                  /*!< MPU RASR: ATTRS.S Mask */

#define OS_MPU_RASR_C_POS                     17u                                           /*!< MPU RASR: ATTRS.C Position */
#define OS_MPU_RASR_C_MSK                     (0x1u << OS_MPU_RASR_C_POS)                  /*!< MPU RASR: ATTRS.C Mask */

#define OS_MPU_RASR_B_POS                     16u                                           /*!< MPU RASR: ATTRS.B Position */
#define OS_MPU_RASR_B_MSK                     (0x1u << OS_MPU_RASR_B_POS)                  /*!< MPU RASR: ATTRS.B Mask */

#define OS_MPU_RASR_ATTRS_POS                 16u                                           /*!< MPU RASR: MPU Region Attribute field Position */
#define OS_MPU_RASR_ATTRS_MSK                 (0xFFFFu << OS_MPU_RASR_ATTRS_POS)           /*!< MPU RASR: MPU Region Attribute field Mask */

#define OS_MPU_RASR_SRD_POS                   8u                                            /*!< MPU RASR: Sub-Region Disable Position */
#define OS_MPU_RASR_SRD_MSK                   (0xFFu << OS_MPU_RASR_SRD_POS)    

#define OS_MPU_RASR_SIZE_POS                  1u                                            /*!< MPU RASR: Region Size Field Position */
#define OS_MPU_RASR_SIZE_MSK                  (0x1Fu << OS_MPU_RASR_SIZE_POS)              /*!< MPU RASR: Region Size Field Mask */

#define OS_MPU_RASR_ENABLE_POS                0u                                            /*!< MPU RASR: Region enable bit Position */
#define OS_MPU_RASR_ENABLE_MSK                (0x1u << OS_MPU_RASR_ENABLE_POS)             /*!< MPU RASR: Region enable bit Disable Mask */

/** Specifies status of APIs of this driver */
typedef enum
{
  OS_CY_MPU_SUCCESS = 0u, /**< The API completed in success */
  OS_CY_MPU_FAILURE,     /**< The API finished in failure */
} os_cy_en_mpu_status_t;

/** Specifies enable/disable of the MPU */
typedef enum
{
  OS_CY_MPU_GLOBAL_DISABLE = (0u),                 /**< Disable  */
  OS_CY_MPU_GLOBAL_ENABLE  = (OS_MPU_CTRL_ENABLE_MSK), /**< Enable  */
} os_cy_en_mpu_global_en_t;

/** Specifies region size of the MPU region */
typedef enum
{
  OS_CY_MPU_SIZE_2B    = (0x00u << OS_MPU_RASR_SIZE_POS), /**< Invalid value */
  OS_CY_MPU_SIZE_4B    = (0x01u << OS_MPU_RASR_SIZE_POS), /**< Invalid value */
  OS_CY_MPU_SIZE_8B    = (0x02u << OS_MPU_RASR_SIZE_POS), /**< Invalid value */
  OS_CY_MPU_SIZE_16B   = (0x03u << OS_MPU_RASR_SIZE_POS), /**< Invalid value */
  OS_CY_MPU_SIZE_32B   = (0x04u << OS_MPU_RASR_SIZE_POS), /**< 32 Byte (Only for M4/M7) */
  OS_CY_MPU_SIZE_64B   = (0x05u << OS_MPU_RASR_SIZE_POS), /**< 64 Byte (Only for M4/M7) */
  OS_CY_MPU_SIZE_128B  = (0x06u << OS_MPU_RASR_SIZE_POS), /**< 128 Byte (Only for M4/M7) */
  OS_CY_MPU_SIZE_256B  = (0x07u << OS_MPU_RASR_SIZE_POS), /**< 256 Byte */
  OS_CY_MPU_SIZE_512B  = (0x08u << OS_MPU_RASR_SIZE_POS), /**< 512 Byte */
  OS_CY_MPU_SIZE_1KB   = (0x09u << OS_MPU_RASR_SIZE_POS), /**< 1K Byte */
  OS_CY_MPU_SIZE_2KB   = (0x0Au << OS_MPU_RASR_SIZE_POS), /**< 2K Byte */
  OS_CY_MPU_SIZE_4KB   = (0x0Bu << OS_MPU_RASR_SIZE_POS), /**< 4K Byte */
  OS_CY_MPU_SIZE_8KB   = (0x0Cu << OS_MPU_RASR_SIZE_POS), /**< 8K Byte */
  OS_CY_MPU_SIZE_16KB  = (0x0Du << OS_MPU_RASR_SIZE_POS), /**< 16K Byte */
  OS_CY_MPU_SIZE_32KB  = (0x0Eu << OS_MPU_RASR_SIZE_POS), /**< 32K Byte */
  OS_CY_MPU_SIZE_64KB  = (0x0Fu << OS_MPU_RASR_SIZE_POS), /**< 64K Byte */
  OS_CY_MPU_SIZE_128KB = (0x10u << OS_MPU_RASR_SIZE_POS), /**< 128K Byte */
  OS_CY_MPU_SIZE_256KB = (0x11u << OS_MPU_RASR_SIZE_POS), /**< 256K Byte */
  OS_CY_MPU_SIZE_512KB = (0x12u << OS_MPU_RASR_SIZE_POS), /**< 512K Byte */
  OS_CY_MPU_SIZE_1MB   = (0x13u << OS_MPU_RASR_SIZE_POS), /**< 1M Byte */
  OS_CY_MPU_SIZE_2MB   = (0x14u << OS_MPU_RASR_SIZE_POS), /**< 2M Byte */
  OS_CY_MPU_SIZE_4MB   = (0x15u << OS_MPU_RASR_SIZE_POS), /**< 4M Byte */
  OS_CY_MPU_SIZE_8MB   = (0x16u << OS_MPU_RASR_SIZE_POS), /**< 8M Byte */
  OS_CY_MPU_SIZE_16MB  = (0x17u << OS_MPU_RASR_SIZE_POS), /**< 16M Byte */
  OS_CY_MPU_SIZE_32MB  = (0x18u << OS_MPU_RASR_SIZE_POS), /**< 32M Byte */
  OS_CY_MPU_SIZE_64MB  = (0x19u << OS_MPU_RASR_SIZE_POS), /**< 64M Byte */
  OS_CY_MPU_SIZE_128MB = (0x1Au << OS_MPU_RASR_SIZE_POS), /**< 128M Byte */
  OS_CY_MPU_SIZE_256MB = (0x1Bu << OS_MPU_RASR_SIZE_POS), /**< 256M Byte */
  OS_CY_MPU_SIZE_512MB = (0x1Cu << OS_MPU_RASR_SIZE_POS), /**< 512M Byte */
  OS_CY_MPU_SIZE_1GB   = (0x1Du << OS_MPU_RASR_SIZE_POS), /**< 1G Byte */
  OS_CY_MPU_SIZE_2GB   = (0x1Eu << OS_MPU_RASR_SIZE_POS), /**< 2G Byte */
  OS_CY_MPU_SIZE_4GB   = (0x1Fu << OS_MPU_RASR_SIZE_POS), /**< 4G Byte, Invalid value */
} os_cy_en_mpu_region_size_t;

/** Specifies access permission of the MPU region */
typedef enum
{
  OS_CY_MPU_ACCESS_P_NO_ACCESS       = (0x0u << OS_MPU_RASR_AP_POS), /**< All accesses generate a permission fault  */
  OS_CY_MPU_ACCESS_P_PRIV_RW         = (0x1u << OS_MPU_RASR_AP_POS), /**< Access from privileged software only  */
  OS_CY_MPU_ACCESS_P_PRIV_RW_USER_RO = (0x2u << OS_MPU_RASR_AP_POS), /**< Writes by unprivileged software generate a permission fault  */
  OS_CY_MPU_ACCESS_P_FULL_ACCESS     = (0x3u << OS_MPU_RASR_AP_POS), /**< Full access  */
  OS_CY_MPU_ACCESS_P_PRIV_RO         = (0x5u << OS_MPU_RASR_AP_POS), /**< Reads by privileged software only  */
  OS_CY_MPU_ACCESS_P_RO              = (0x6u << OS_MPU_RASR_AP_POS), /**< Read only, by privileged or unprivileged software  */
} os_cy_en_mpu_access_p_t;

/** Specifies attribute of the MPU region */
typedef enum
{
  OS_CY_MPU_ATTR_STR_ORD_DEV               = ((0x0u << OS_MPU_RASR_TEX_POS)), /**< Strongly-ordered, shareable. */
  OS_CY_MPU_ATTR_SHR_DEV                   = ((0x0u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK), /**< Device,           shareable. */

  OS_CY_MPU_ATTR_NORM_MEM_WT               = ((0x0u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK), /**< Normal,           Not shareable, Outer and inner write-through. No write allocate. */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_WT           = ((0x0u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_S_MSK), /**< Normal,           shareable,     Outer and inner write-through. No write allocate. */
  OS_CY_MPU_ATTR_NORM_MEM_WB               = ((0x0u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK), /**< Normal,           Not shareable, Outer and inner write-back. No write allocate. */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_WB           = ((0x0u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal,           shareable,     Outer and inner write-back. No write allocate. */

  OS_CY_MPU_ATTR_NORM_MEM_NC               = ((0x1u << OS_MPU_RASR_TEX_POS)), /**< Normal,           Not shareable, Outer and inner non-cacheable. */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_NC           = ((0x1u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_S_MSK), /**< Normal,           shareable,     Outer and inner non-cacheable. */
  OS_CY_MPU_ATTR_NORM_MEM_WA               = ((0x1u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK), /**< Normal,           Not shareable, Outer and inner Write-Back. Write and read allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_WA           = ((0x1u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal,           shareable,     Outer and inner Write-Back. Write and read allocate */

  OS_CY_MPU_ATTR_DEV                       = ((0x2u << OS_MPU_RASR_TEX_POS)), /**< Device,           Not-shareable, */

  /* Attribute for different policy for outer and inter cache. */
  OS_CY_MPU_ATTR_NORM_MEM_IN_NC_OUT_NC     = ((0x4u << OS_MPU_RASR_TEX_POS)), /**< Normal, Not-shareable. inner policy: Non-cachealbe,                      outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WA_OUT_NC     = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, write and read-Allocate outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WT_OUT_NC     = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK), /**< Normal, Not-shareable. inner policy: Write through, no Write-Allocate,   outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WB_OUT_NC     = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, no Write-Allocate,      outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_NC = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Non-cachealbe,                      outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_NC = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, write and read-Allocate outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_NC = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write through, no Write-Allocate,   outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_NC = ((0x4u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, no Write-Allocate,      outer policy: Non-cacheable */
  OS_CY_MPU_ATTR_NORM_MEM_IN_NC_OUT_WA     = ((0x5u << OS_MPU_RASR_TEX_POS)), /**< Normal, Not-shareable. inner policy: Non-cachealbe,                      outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WA_OUT_WA     = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, write and read-Allocate outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WT_OUT_WA     = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK), /**< Normal, Not-shareable. inner policy: Write through, no Write-Allocate,   outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WB_OUT_WA     = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK                 ), /**< Normal, Not-shareable. inner policy: Write back, no Write-Allocate,      outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WA = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Non-cachealbe,                      outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WA = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, write and read-Allocate outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WA = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write through, no Write-Allocate,   outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WA = ((0x5u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, no Write-Allocate,      outer policy: Write back, write and read-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_NC_OUT_WT     = ((0x6u << OS_MPU_RASR_TEX_POS)), /**< Normal, Not-shareable. inner policy: Non-cachealbe,                      outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WA_OUT_WT     = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, write and read-Allocate outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WT_OUT_WT     = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK), /**< Normal, Not-shareable. inner policy: Write through, no Write-Allocate,   outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WB_OUT_WT     = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, no Write-Allocate,      outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WT = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Non-cachealbe,                      outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WT = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, write and read-Allocate outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WT = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write through, no Write-Allocate,   outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WT = ((0x6u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, no Write-Allocate,      outer policy: Write through, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_NC_OUT_WB     = ((0x7u << OS_MPU_RASR_TEX_POS)), /**< Normal, Not-shareable. inner policy: Non-cachealbe,                      outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WA_OUT_WB     = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, write and read-Allocate outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WT_OUT_WB     = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK), /**< Normal, Not-shareable. inner policy: Write through, no Write-Allocate,   outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_MEM_IN_WB_OUT_WB     = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK), /**< Normal, Not-shareable. inner policy: Write back, no Write-Allocate,      outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WB = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Non-cachealbe,                      outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WB = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, write and read-Allocate outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WB = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write through, no Write-Allocate,   outer policy: Write back, no Write-Allocate */
  OS_CY_MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WB = ((0x7u << OS_MPU_RASR_TEX_POS) | OS_MPU_RASR_C_MSK | OS_MPU_RASR_B_MSK | OS_MPU_RASR_S_MSK), /**< Normal, shareable.     inner policy: Write back, no Write-Allocate,      outer policy: Write back, no Write-Allocate */
} os_cy_en_mpu_attr_t;

/** Specifies enable/disable of instruction access of the MPU region */
typedef enum
{
  OS_CY_MPU_INST_ACCESS_EN  = (0u),                /**< Instruction fetches enabled  */
  OS_CY_MPU_INST_ACCESS_DIS = (OS_MPU_RASR_XN_MSK), /**< Instruction fetches disabled */
} os_cy_en_mpu_execute_n_t;

/** Specifies enable/disable of the MPU region */
typedef enum
{
  OS_CY_MPU_DISABLE = (0u),                    /**< Disable  */
  OS_CY_MPU_ENABLE  = (OS_MPU_RASR_ENABLE_MSK), /**< Enable  */
} os_cy_en_mpu_region_en_t;

typedef struct
{
  volatile const uint32 ulType;             /*!< Offset: 0x000 (R/ )  MPU Type Register */
  volatile uint32 ulCtrl;                   /*!< Offset: 0x004 (R/W)  MPU Control Register */
  volatile uint32 ulRnr;                    /*!< Offset: 0x008 (R/W)  MPU Region RNRber Register */
  volatile uint32 ulRbar;                   /*!< Offset: 0x00C (R/W)  MPU Region Base Address Register */
  volatile uint32 ulRasr;                   /*!< Offset: 0x010 (R/W)  MPU Region Attribute and Size Register */
  volatile uint32 ulRbar_a1;                /*!< Offset: 0x014 (R/W)  MPU Alias 1 Region Base Address Register */
  volatile uint32 ulRasr_a1;                /*!< Offset: 0x018 (R/W)  MPU Alias 1 Region Attribute and Size Register */
  volatile uint32 ulRbar_a2;                /*!< Offset: 0x01C (R/W)  MPU Alias 2 Region Base Address Register */
  volatile uint32 ulRasr_a2;                /*!< Offset: 0x020 (R/W)  MPU Alias 2 Region Attribute and Size Register */
  volatile uint32 ulRbar_a3;                /*!< Offset: 0x024 (R/W)  MPU Alias 3 Region Base Address Register */
  volatile uint32 ulRasr_a3;                /*!< Offset: 0x028 (R/W)  MPU Alias 3 Region Attribute and Size Register */
} OS_MPU_Type;

#define OS_MPU_BASE          (0xE000ED90u)                    /*!< Memory Protection Unit */
#define OS_MPU               (*(volatile OS_MPU_Type* ) OS_MPU_BASE)     /*!< Memory Protection Unit */

#endif /* OS_ARCH_REGS_H_ */

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-end MISRA-C3:11.4 */
/* polyspace-end MISRA-C3:19.2 */
/* polyspace:end<MISRA-C3:12.2> */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To access Registers */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
