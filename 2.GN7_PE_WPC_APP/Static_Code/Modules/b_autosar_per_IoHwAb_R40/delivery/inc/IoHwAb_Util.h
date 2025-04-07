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
**  SRC-MODULE: IoHwAb_Util.h                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR IOHWAB                                                **
**                                                                            **
**  PURPOSE   : Time constant definitions for IOHWAB                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By             Description                         **
********************************************************************************
** 1.15.2    24-Mar-2022   Yangjin        #34768                              **
** 1.15.1    06-Dec-2021   Yangjin        #29174                              **
** 1.15.0.2  09-Sep-2021   Yangjin        #31974                              **
** 1.15.0    09-Sep-2021   Yangjin        #31974                              **
** 1.11.0    24-Sep-2020   Yangjin        #25514, #25515                      **
** 1.10.1    04-Aug-2020   Yangjin        #24902                              **
** 1.9.0     04-Jun-2020   Yangjin        #23696, #23742                      **
** 1.8.1     08-May-2020   Yangjin        #23096                              **
** 1.8.0     21-Apr-2020   Yangjin        #22141                              **
** 1.7.0     26-Nov-2019   Yangjin        #19730                              **
** 1.5.0     28-Aug-2019   Yangjin        #18753                              **
** 1.3.2     04-Jun-2019   Yangjin        #17709                              **
** 1.3.1     30-Apr-2019   Yangjin        #16955                              **
** 1.1.1     08-Aug-2018   Jongyoung      #13075                              **
** 1.1.0     05-Apr-2018   Jongyoung      #12280                              **
** 1.0.13    18-Sep-2017   Jongyoung      #9949, #9939                        **
** 1.0.12    05-Mar-2017   Jongyoung      #7764, #7328                        **
** 1.0.11    12-Jan-2017   Jongyoung      #7140                               **
** 1.0.10    11-Dec-2016   Jongyoung      #6845, #6929                        **
** 1.0.9     05-Dec-2016   Jongyoung      #5227, #6845                        **
** 1.0.8     19-Apr-2016   Jongyoung      #5613, #5686                        **
** 1.0.7     19-Apr-2016   Jongyoung      #4654, #4514                        **
*******************************************************************************/
/* polyspace-begin MISRA-C3:20.9 [Justified:Unset] "Not a defect" */
/* polyspace-begin MISRA-C3:10.7 [Justified:Low] "Validated by test cases. It works as intended." */

#ifndef IOHWAB_UTIL_H
#define IOHWAB_UTIL_H

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "IoHwAb_Cfg.h"

#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
#include "Reg_eSys_Stm.h"
#include "Reg_eSys_Rtc.h"
#include "Reg_eSys_SIUL.h"
#include "Reg_eSys_ADCDig.h"
#include "Reg_Macros.h"

#elif (defined(IOHWAB_MCAL_ST_SPC58XCX) || defined(IOHWAB_MCAL_ST_SPC58XHX))
#include "Reg_eSys_Stm.h"
#include "Reg_eSys_Rtc.h"
#include "Reg_eSys_SIUL.h"
#include "Reg_eSys_ADCDigv2.h"
#include "Reg_Macros.h"

#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
    || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) )
#include "Os_Arch_Regs.h"
#include "IfxPort_reg.h"
#include "IfxSrc_reg.h"

#elif (defined(IOHWAB_MCAL_CYPRESS_S6J32XX))
#include "s6j3200_ADC12B.h"
#include "Adc_Stream.h"
#include "s6j3200_RLT.h"

#elif (defined(IOHWAB_MCAL_CYPRESS_S6J33XX))
#include "s6j3300_ADC12B.h"
#include "Adc_Stream.h"
#include "s6j3300_RLT.h"

#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
#include "Adc_Internal.h"
#include "Adc_Data.h"

#elif (defined(IOHWAB_MCAL_FREESCALE_MPC574XR))
#include "Adc_Reg_eSys_Adcdig.h"
#include "Reg_eSys_Stm.h"
#include "Reg_eSys_Rtc.h"
#include "Reg_eSys_SIUL2.h"
#include "StdRegMacros.h"

#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
    || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
#include "Adc_Private.h"

#elif (defined(IOHWAB_MCAL_NXP_S32K14X))
#include "Os.h"
#include "StdRegMacros.h"
#include "Adc_Reg_eSys_Adc12bsarv2.h"

#elif (defined(IOHWAB_MCAL_NXP_S32G2X))
#include "Os.h"
#include "StdRegMacros.h"
#endif


/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.3 [Justified:Low] "whether this macro is used depends on the configurations." */
/* polyspace-begin MISRA-C3:2.5 [Justified:Low] "whether this macro is used depends on the configurations." */
/* Multiple to convert sec to msec */
#define IOHWAB_SEC_TO_MSEC      (1000u)

/* Multiple to convert msec to usec */
#define IOHWAB_MSEC_TO_USEC     (1000u)

/* Multiple to convert sec to usec */
#define IOHWAB_SEC_TO_USEC      (1000000u)

typedef uint32	IoHwAb_DelayUsecType;
typedef uint16	IoHwAb_DelayMsecType;
typedef float32 IoHwAb_DelaySecType;

typedef uint32	IoHwAb_StmTickType;
typedef uint32	IoHwAb_GptTickType;
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX))
/* polyspace:begin<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation */
typedef unsigned long long  IoHwAb_LongType;
/* polyspace:end<MISRA-C:1.1:Not a defect:Justify with annotations> No Impact of this rule violation */
#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
    || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) )
typedef uint32  IoHwAb_LongType;
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413) \
    || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
typedef uint8  IoHwAb_StmStatusType;
typedef uint32 IoHwAb_LongType;

#elif (defined(IOHWAB_MCAL_CYPRESS_S6J33XX) || defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) \
    || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
typedef uint32 IoHwAb_LongType;
#else
typedef uint32 IoHwAb_LongType;
#endif

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/

/*******************************************************************************
**                      Mcu Dependent Macros                                  **
*******************************************************************************/
/* polyspace:begin<MISRA-C:11.3:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:begin<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
/* Freescale Bolero */
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || (defined(IOHWAB_MCAL_ST_SPC58XCX)) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX))
#define IOHWAB_MCU_CLK_DIV      (4U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */
/* Upper limit of STM ticks */
#define IOHWAB_STM_TICK_MAX     ((IoHwAb_StmTickType) STM_CNT_MAX_VALUE)
/* Upper limit of GPT ticks */
#define IOHWAB_GPT_TICK_MAX     ((IoHwAb_GptTickType) RTC_API_RTCC_APIVAL_MAX_VALUE)
	
#define IOHWAB_ADC_ISR_ECH      (0x00000001U)

/* Bolero do not need.*/
/* #define IOHWAB_ADC_CONV_PROC(ADC_HWUNIT_NUM)  IOHWAB_NOP() */

/* Infineon AURIX */
#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) )
extern uint32 Os_GulStmClock;
#define IOHWAB_STM_FREQ_HZ      (Os_GulStmClock * 1000000)
#define IOHWAB_GPT_FREQ_HZ      (24414u)  /* GTM_FIXED_CLOCK_3 : 100MHz / 2^12 */

static inline uint32 IOHWAB_GET_TIMESTAMP(void)
{
  return (uint32)OS_STM0_TIM0.U;
}
#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xF0038984u

/* TC38X, TC39X */
#elif (defined(IOHWAB_MCAL_INFINEON_TC38X)) || (defined(IOHWAB_MCAL_INFINEON_TC39X))
extern uint32 Os_GulStmClock;
#define IOHWAB_STM_FREQ_HZ      (Os_GulStmClock * 1000000)
#define IOHWAB_GPT_FREQ_HZ      (24414u)  /* GTM_FIXED_CLOCK_3 : 100MHz / 2^12 */

static inline uint32 IOHWAB_GET_TIMESTAMP(void)
{
  return (uint32)OS_STM0_TIM0.U;
}
#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xF0038670u

/* Renesas RH850F1L */
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413))
#define IOHWAB_MCU_CLK_DIV      (6U)
#define IOHWAB_STM_FREQ_HZ      (8000000u) /* 8M/80 */
#define IOHWAB_GPT_FREQ_HZ      (8000000u) /* 8M/80 */

#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xFFFF9014UL

/* Renesas RH850F1K */
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM)) 
#define IOHWAB_MCU_CLK_DIV      (6U)
#define IOHWAB_STM_FREQ_HZ      (8000000u) /* 8M/80 */
#define IOHWAB_GPT_FREQ_HZ      (8000000u) /* 8M/80 */

#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xFFFEEA24UL

/* Cypress S6J3200 */
#elif (defined(IOHWAB_MCAL_CYPRESS_S6J32XX))
#define IOHWAB_MCU_CLK_DIV      (6U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */

#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xB48C0300UL /* ADC12B0_CDONEIRQ0 */

/* Cypress S6J3300 */
#elif (defined(IOHWAB_MCAL_CYPRESS_S6J33XX) )
#define IOHWAB_MCU_CLK_DIV      (6U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */
           
#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xB48C0300UL /* ADC12B0_CDONEIRQ0 */

/* Cypress CYT2B9XX, CYT4BBXX */
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
#define IOHWAB_MCU_CLK_DIV      (6U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */
           
#define IOHWAB_ADC_CONV_BASE_ADDRESS 0xB48C0300UL /* ADC12B0_CDONEIRQ0 */

/* Freescale MPC574XR */
#elif (defined(IOHWAB_MCAL_FREESCALE_MPC574XR))
#define IOHWAB_MCU_CLK_DIV      (4U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) 
#define IOHWAB_GPT_FREQ_HZ      (1000000u) 

#elif (defined(IOHWAB_MCAL_NXP_S32K14X))
#define IOHWAB_MCU_CLK_DIV      (4U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */
/* Upper limit of STM ticks */
#define IOHWAB_STM_TICK_MAX     ((IoHwAb_StmTickType) STM_CNT_MAX_VALUE)
/* Upper limit of GPT ticks */
#define IOHWAB_GPT_TICK_MAX     ((IoHwAb_GptTickType) RTC_API_RTCC_APIVAL_MAX_VALUE)

/* NXP S32G2X */
#elif (defined(IOHWAB_MCAL_NXP_S32G2X))
#define IOHWAB_MCU_CLK_DIV      (4U)
#define IOHWAB_STM_FREQ_HZ      (1000000u) /* 64M/64 */
#define IOHWAB_GPT_FREQ_HZ      (1000000u) /* 64M/64 */
/* Upper limit of STM ticks */
#define IOHWAB_STM_TICK_MAX     ((IoHwAb_StmTickType) STM_CNT_MAX_VALUE_U32)
/* Upper limit of GPT ticks */
#define IOHWAB_GPT_TICK_MAX     ((IoHwAb_GptTickType) RTC_API_RTCC_APIVAL_MAX_VALUE_U32)

#define IOHWAB_ADC_BASE         (0x401F8000u)
#define IOHWAB_ADC_ISR_OFFSET   (0x00000010u)
#define IOHWAB_ADC_ISR_ADDRESS  (IOHWAB_ADC_BASE + IOHWAB_ADC_ISR_OFFSET)
#define IOHWAB_ADC_HWUNIT_OFFSET (0x000F0000u)

/* TI TDA4X */
#elif (defined(IOHWAB_MCAL_TI_TDA4X))
#define IOHWAB_ADDRESS_ADC_STATUS_RAW 0x40200024UL /* ADC_STATUS_RAW Register */
#define IOHWAB_ADDRESS_ADC_STATUS 0x40200028UL  /* ADC_STATUS Register */

#define IOHWAB_ADDRESS_GPIO0 0x00600000UL
#define IOHWAB_ADDRESS_GPIO1 0x00601000UL
#define IOHWAB_ADDRESS_GPIO2 0x00610000UL
#define IOHWAB_ADDRESS_GPIO3 0x00611000UL
#define IOHWAB_ADDRESS_GPIO4 0x00620000UL
#define IOHWAB_ADDRESS_GPIO5 0x00621000UL
#define IOHWAB_ADDRESS_GPIO6 0x00630000UL
#define IOHWAB_ADDRESS_GPIO7 0x00680000UL
#define IOHWAB_ADDRESS_WKUP_GPIO1 0x42100000UL
#define IOHWAB_ADDRESS_WKUP_GPIO0 0x42110000UL

#endif

/*******************************************************************************
**                      Upper limit ticks                                     **
*******************************************************************************/
#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
/* Upper limit of GPT time in sec */
#define IOHWAB_GPT_DELAY_MAX_SEC \
    ((IoHwAb_DelaySecType) IOHWAB_GPT_TICK_MAX / IOHWAB_GPT_FREQ_HZ)
#endif


/*******************************************************************************
**                      Convert STM ticks to time                             **
*******************************************************************************/
/* Convert STM ticks to time in sec */
static inline IoHwAb_DelaySecType IOHWAB_STM_TICK_TO_SEC(uint32 tick)
{
  return (((IoHwAb_DelaySecType) (tick)) / IOHWAB_STM_FREQ_HZ);
}

/* Convert STM ticks to time in msec */
static inline IoHwAb_DelayMsecType IOHWAB_STM_TICK_TO_MSEC(uint32 tick)
{
  return  ((IoHwAb_DelayMsecType) ((((IoHwAb_LongType)(tick))*IOHWAB_SEC_TO_MSEC) / IOHWAB_STM_FREQ_HZ));
}

/* Convert STM ticks to time in usec */
static inline IoHwAb_DelayUsecType IOHWAB_STM_TICK_TO_USEC(uint32 tick)
{
  return ((IoHwAb_DelayUsecType) ((((uint32)(tick))*IOHWAB_SEC_TO_USEC) / IOHWAB_STM_FREQ_HZ));
}

/*******************************************************************************
**                      Convert time to STM ticks                             **
*******************************************************************************/
/* Convert Time in sec to STM ticks */
static inline IoHwAb_StmTickType IOHWAB_SEC_TO_STM_TICK(uint32 input_time)
{
  return ((IoHwAb_StmTickType) ((input_time) * IOHWAB_STM_FREQ_HZ));
}

/* Convert Time in msec to STM ticks */
static inline IoHwAb_StmTickType IOHWAB_MSEC_TO_STM_TICK(uint32 input_time)
{
  return ((IoHwAb_StmTickType) (((IoHwAb_LongType)(input_time) * IOHWAB_STM_FREQ_HZ) / IOHWAB_SEC_TO_MSEC));
}

/* Convert Time in usec to STM ticks */
static inline IoHwAb_StmTickType IOHWAB_USEC_TO_STM_TICK(uint32 input_time)
{
  return ((IoHwAb_StmTickType) (((IoHwAb_LongType)(input_time) * IOHWAB_STM_FREQ_HZ) / IOHWAB_SEC_TO_USEC));
}

/*******************************************************************************
**                      Convert GPT ticks to time                             **
*******************************************************************************/
/* Convert GPT ticks to time in sec */
static inline IoHwAb_DelaySecType IOHWAB_GPT_TICK_TO_SEC(uint32 tick)
{
  return ((IoHwAb_DelaySecType) (tick) / IOHWAB_GPT_FREQ_HZ);
}

/* Convert GPT ticks to time in msec */
static inline IoHwAb_DelayMsecType IOHWAB_GPT_TICK_TO_MSEC(uint32 tick)
{
	return ((IoHwAb_DelayMsecType) (((IoHwAb_LongType)(tick)*IOHWAB_SEC_TO_MSEC) / IOHWAB_GPT_FREQ_HZ));
}

/* Convert GPT ticks to time in usec */
static inline IoHwAb_DelayUsecType IOHWAB_GPT_TICK_TO_USEC(uint32 tick)
{
  return ((IoHwAb_DelayUsecType) (((IoHwAb_LongType)(tick)*IOHWAB_SEC_TO_USEC) / IOHWAB_GPT_FREQ_HZ));
}

/*******************************************************************************
**                      Convert time to GPT ticks                             **
*******************************************************************************/
/* Convert Time in sec to GPT ticks */
static inline IoHwAb_GptTickType IOHWAB_SEC_TO_GPT_TICK(uint32 input_time)
{
  return ((IoHwAb_GptTickType) ((input_time) * IOHWAB_GPT_FREQ_HZ));
}

/* Convert Time in msec to GPT ticks */
static inline IoHwAb_GptTickType IOHWAB_MSEC_TO_GPT_TICK(uint32 input_time)
{
  return ((IoHwAb_GptTickType) (((IoHwAb_LongType)(input_time) * IOHWAB_GPT_FREQ_HZ) / IOHWAB_SEC_TO_MSEC));
}

/* Convert Time in usec to GPT ticks */
static inline IoHwAb_GptTickType IOHWAB_USEC_TO_GPT_TICK(uint32 input_time)
{
  return ((IoHwAb_GptTickType) (((IoHwAb_LongType)(input_time) * IOHWAB_GPT_FREQ_HZ) / IOHWAB_SEC_TO_USEC));
}


/*******************************************************************************
**                      Convert between GPT ans STM ticks                     **
*******************************************************************************/
/* Convert STM ticks to GPT ticks */
static inline IoHwAb_GptTickType IOHWAB_STM_TICK_TO_GPT_TICK(uint32 tick)
{
  return ((IoHwAb_GptTickType) (((IoHwAb_LongType)(tick) * IOHWAB_GPT_FREQ_HZ) / IOHWAB_STM_FREQ_HZ));
}

/* Convert GPT ticks to STM ticks */
static inline IoHwAb_StmTickType IOHWAB_GPT_TICK_TO_STM_TICK(uint32 tick)
{
  return ((IoHwAb_StmTickType) (((IoHwAb_LongType)(tick) * IOHWAB_STM_FREQ_HZ) / IOHWAB_GPT_FREQ_HZ));
}

/*******************************************************************************
**                      Current STM Clock in ticks or time                    **
*******************************************************************************/
/* Current STM Clock in ticks */
#if defined(IOHWAB_MCAL_FREESCALE_MPC560XB)
#define IOHWAB_STM_BASE_ADDRESS         (0xFFF3C004UL)
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return ((IoHwAb_StmTickType)(REG_READ32((uint32)IOHWAB_STM_BASE_ADDRESS)));
}

#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
    || defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X) )
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return ((IoHwAb_StmTickType) IOHWAB_GET_TIMESTAMP());
}
#elif (defined(IOHWAB_MCAL_FREESCALE_MPC574XR))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return ((IoHwAb_StmTickType) STM_GET_COUNTER());
}
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return ((IoHwAb_StmTickType)(*(volatile uint32*)(0xFFEC0004UL)));
}

#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return ((IoHwAb_StmTickType)(*(volatile uint32*)(0xFFD70004UL)));
}
#elif (defined(IOHWAB_MCAL_ST_SPC58XCX) || defined(IOHWAB_MCAL_ST_SPC58XHX))
  #if (REG_ESYS_STM_SW_MAJOR_VERSION > 1)
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return STM_CNT(0xF4068000UL);
}
  #else
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return STM_CNT(0);
}
  #endif

#elif (defined(IOHWAB_MCAL_CYPRESS_S6J32XX))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return RLT32_TMR;
}
#elif (defined(IOHWAB_MCAL_CYPRESS_S6J33XX))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return RLT0_TMR;
}
#elif (defined(IOHWAB_MCAL_CYPRESS_CYT2B9XX) || defined(IOHWAB_MCAL_CYPRESS_CYT4BBXX))
static inline IoHwAb_StmTickType IOHWAB_CURRENT_CLOCK_TICK(void)
{
  return (IoHwAb_StmTickType)0;
}
#endif

#if (!defined (IOHWAB_MCAL_NXP_S32K14X)) && (!defined (IOHWAB_MCAL_NXP_S32G2X))
/* Current STM Clock in sec */
static inline IoHwAb_DelaySecType IOHWAB_CURRENT_CLOCK_SEC(void)
{
  return (IOHWAB_STM_TICK_TO_SEC(IOHWAB_CURRENT_CLOCK_TICK()));
}
/* Current STM Clock in msec */
static inline IoHwAb_DelayMsecType IOHWAB_CURRENT_CLOCK_MSEC(void)
{
  return (IOHWAB_STM_TICK_TO_MSEC(IOHWAB_CURRENT_CLOCK_TICK()));
}

/* Current STM Clock in usec */
static inline IoHwAb_DelayUsecType IOHWAB_CURRENT_CLOCK_USEC(void)
{
  return (IOHWAB_STM_TICK_TO_USEC(IOHWAB_CURRENT_CLOCK_TICK()));
}

#endif
/*******************************************************************************
**                      DIO Util                                              **
*******************************************************************************/

/*******************************************************************************
**                      For MISRA-C                                           **
*******************************************************************************/
static inline void IOHWAB_UNUSED16 (uint16 unused_var)
{
  if(unused_var != (uint16) 0){
  }
}
static inline void IOHWAB_UNUSED8 (uint8 unused_var)
{
  if(unused_var != (uint8) 0){
  }
}
/*
  inline functions
*/
/*******************************************************************************
** Function Name        : IoHwAb_Nop                                          **
**                                                                            **
** Service ID           : Not yet defined                                     **
**                                                                            **
** Description          :                                                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
static inline FUNC(void, IOHWAB_CODE)IoHwAb_Nop(void)
{
#if (defined(IOHWAB_MCAL_FREESCALE_MPC560XB) || defined(IOHWAB_MCAL_ST_SPC58XCX) \
  || defined(IOHWAB_MCAL_ST_SPC58XHX) || defined(IOHWAB_MCAL_FREESCALE_MPC574XR) \
  || defined(IOHWAB_MCAL_NXP_S32K14X) || defined(IOHWAB_MCAL_NXP_S32G2X))
  __asm("  nop");
#elif (defined(IOHWAB_MCAL_INFINEON_TC21X) || defined(IOHWAB_MCAL_INFINEON_TC22X) \
    || defined(IOHWAB_MCAL_INFINEON_TC23X) || defined(IOHWAB_MCAL_INFINEON_TC26X) \
    || defined(IOHWAB_MCAL_INFINEON_TC27X) || defined(IOHWAB_MCAL_INFINEON_TC29X) \
	|| defined(IOHWAB_MCAL_INFINEON_TC38X) || defined(IOHWAB_MCAL_INFINEON_TC39X))
  __nop();
#elif (defined(IOHWAB_MCAL_RENESAS_RH850F1L) || defined(IOHWAB_MCAL_RENESAS_RH850F1L_413)\
    || defined(IOHWAB_MCAL_RENESAS_RH850F1K) || defined(IOHWAB_MCAL_RENESAS_RH850F1KM))
  __asm("nop");
#else
#endif
}
/* polyspace:end<MISRA-C:19.7:Not a defect:Justify with annotations> No Impact of this rule violation */
/* polyspace:end<MISRA-C:11.3:Not a defect:Justify with annotations> No Impact of this rule violation */
#endif /* IOHWAB_UTIL_H */
/* polyspace-end MISRA-C3:2.3 [Justified:Low] "whether this macro is used depends on the configurations." */
/* polyspace-end MISRA-C3:2.5 [Justified:Low] "whether this macro is used depends on the configurations." */
/* polyspace-end MISRA-C3:20.9 [Justified:Unset] "Not a defect" */
/* polyspace-end MISRA-C3:10.7 [Justified:Low] "Validated by test cases. It works as intended." */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
