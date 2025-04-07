/* polyspace +1 MISRA2012:1.1 [Not a defect:Low] "This rule is manually checked and has no impact." *//*******************************************************************************
**                                                                            **
**  (C) 2021 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  FILE-NAME : EcuM_Callout.c                                                **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR EcuM Module                                           **
**                                                                            **
**  PURPOSE   :  Callouts implementation for EcuM module                      **
**               EcuM_AL_DriverInitZero                                       **
**               EcuM_AL_DriverInitOne                                        **
**               EcuM_AL_DriverRestart                                        **
**               EcuM_AL_SetProgrammableInterrupts                            **
**               EcuM_OnGoOffOne                                              **
**               EcuM_OnGoOffTwo                                              **
**               EcuM_AL_SwitchOff                                            **
**               EcuM_AL_Reset                                                **
**               EcuM_EnableWakeupSources                                     **
**               EcuM_DisableWakeupSources                                    **
**               EcuM_CheckWakeup                                             **
**               EcuM_StartWakeupSources                                      **
**               EcuM_StopWakeupSources                                       **
**               EcuM_CheckValidation                                         **
**               EcuM_GenerateRamHash                                         **
**               EcuM_SleepActivity                                           **
**               EcuM_CheckRamHash                                            **
**               EcuM_DeterminePbConfiguration                                **
**               EcuM_ErrorHook                                               **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: yes                                       **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                              Revision History                              **
********************************************************************************
** Revision   Date          By            Description                         **
********************************************************************************
** 2.8.1      12-May-2023  Hyeonseok Park #40104                              **
** 2.8.0      19-Dec-2022   Joochan Kim   #37783                              **
** 2.7.1      30-Sep-2022   Joochan Kim   #37588                              **
** 2.6.7      03-Aug-2022   Joochan Kim   #36747                              **
**                                        Modify copyright comment            **
** 2.6.6      02-May-2022   Joochan Kim   #35032, 35211                       **
** 2.6.5      31-Mar-2022   Joochan Kim   #34412                              **
** 2.6.4      26-Jan-2022   Junho Cho     #34111                              **
** 2.5.9      25-Oct-2021   Junho Cho     #32580, #32615, #32730              **
** 2.5.8      15-Sep-2021   Junho Cho     #32188                              **
** 2.5.6      06-May-2021   Junho Cho     #29661                              **
** 2.5.4      08-Jan-2021   Manje Woo     #27588, #27589                      **
** 2.5.2      24-Nov-2020   Manje Woo     #26677                              **
** 2.4.0      02-Dec-2019   Junho Cho     Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA2012:20.1 [Justified:Low] "See MEMMAP003 of AUTOSAR" */
/* polyspace-begin MISRA2012:D4.5 [Justified:Low] "This code reviewed manually" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "EcuM.h"
#include "EcuM_Config.h"
#include "EcuM_Cbk.h"    /* ECU State Manager Callout-Callback Header File */
#include "EcuM_Generated_Callouts.h"
#include "EcuM_Ram.h"
#include "BswM_EcuM.h"
#include "Mcu.h"
#include "SchM_EcuM.h"
#include "Rte_EcuM.h"
#include "Nml_Integration.h" /* NML Integration */
#include "Nml_UsrCfg.h"      /* NML Integration */

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
#define RTE_ALLOW_CROSS_HEADER_INCLUSION
#include "Rte_EcuM_Slave1.h"
#endif

#if (OS_FPU_SUPPORT == STD_ON)
#include "Os_Arch_Regs.h"
#endif

#if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
#include "Gpt.h"
#endif
#include "HwResource.h"
#include "arm_ghs.h"

#if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
#include "LowPower_Callout.h"
#endif

#if (SWP_USE_DATALOG == STD_ON)
#include "CDD_DataLog.h"
#endif


#define RTE_ALLOW_CROSS_HEADER_INCLUSION // WPC_32_05
#include "Rte_IoHwAb.h"// WPC_32_05
//#include "EcuInfo.h" // WPC_51_03
//#include "LowPower_Callout.h"  // SWP 2.4.0

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/
#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT3BXX) || HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX))
#define ECUM_SCB_CCR_IC_Pos                      17U                                           /*!< SCB CCR: Instruction cache enable bit Position */
#define ECUM_SCB_CCR_IC_Msk                     (1UL << ECUM_SCB_CCR_IC_Pos)                   /*!< SCB CCR: Instruction cache enable bit Mask */
#define ECUM_SCB_SCR_SLEEPDEEP_Pos               2U                                            /*!< SCB SCR: SLEEPDEEP Position */
#define ECUM_SCB_SCR_SLEEPDEEP_Msk              (1UL << ECUM_SCB_SCR_SLEEPDEEP_Pos)            /*!< SCB SCR: SLEEPDEEP Mask */

/**
  brief  Structure type to access the System Control Block (SCB).
 */
typedef struct
{
  uint32 ECUM_CPUID;                  /*!< Offset: 0x000 (R/ )  CPUID Base Register */
  uint32 ECUM_ICSR;                   /*!< Offset: 0x004 (R/W)  Interrupt Control and State Register */
  uint32 ECUM_VTOR;                   /*!< Offset: 0x008 (R/W)  Vector Table Offset Register */
  uint32 ECUM_AIRCR;                  /*!< Offset: 0x00C (R/W)  Application Interrupt and Reset Control Register */
  uint32 ECUM_SCR;                    /*!< Offset: 0x010 (R/W)  System Control Register */
  uint32 ECUM_CCR;                    /*!< Offset: 0x014 (R/W)  Configuration Control Register */
  uint8  ECUM_SHPR[12U];              /*!< Offset: 0x018 (R/W)  System Handlers Priority Registers (4-7, 8-11, 12-15) */
  uint32 ECUM_SHCSR;                  /*!< Offset: 0x024 (R/W)  System Handler Control and State Register */
  uint32 ECUM_CFSR;                   /*!< Offset: 0x028 (R/W)  Configurable Fault Status Register */
  uint32 ECUM_HFSR;                   /*!< Offset: 0x02C (R/W)  HardFault Status Register */
  uint32 ECUM_DFSR;                   /*!< Offset: 0x030 (R/W)  Debug Fault Status Register */
  uint32 ECUM_MMFAR;                  /*!< Offset: 0x034 (R/W)  MemManage Fault Address Register */
  uint32 ECUM_BFAR;                   /*!< Offset: 0x038 (R/W)  BusFault Address Register */
  uint32 ECUM_AFSR;                   /*!< Offset: 0x03C (R/W)  Auxiliary Fault Status Register */
  uint32 ECUM_ID_PFR[2U];             /*!< Offset: 0x040 (R/ )  Processor Feature Register */
  uint32 ECUM_ID_DFR;                 /*!< Offset: 0x048 (R/ )  Debug Feature Register */
  uint32 ECUM_ID_AFR;                 /*!< Offset: 0x04C (R/ )  Auxiliary Feature Register */
  uint32 ECUM_ID_MFR[4U];             /*!< Offset: 0x050 (R/ )  Memory Model Feature Register */
  uint32 ECUM_ID_ISAR[5U];            /*!< Offset: 0x060 (R/ )  Instruction Set Attributes Register */
  uint32 ECUM_RESERVED0[1U];
  uint32 ECUM_CLIDR;                  /*!< Offset: 0x078 (R/ )  Cache Level ID register */
  uint32 ECUM_CTR;                    /*!< Offset: 0x07C (R/ )  Cache Type register */
  uint32 ECUM_CCSIDR;                 /*!< Offset: 0x080 (R/ )  Cache Size ID Register */
  uint32 ECUM_CSSELR;                 /*!< Offset: 0x084 (R/W)  Cache Size Selection Register */
  uint32 ECUM_CPACR;                  /*!< Offset: 0x088 (R/W)  Coprocessor Access Control Register */
  uint32 ECUM_RESERVED3[93U];
  uint32 ECUM_STIR;                   /*!< Offset: 0x200 ( /W)  Software Triggered Interrupt Register */
  uint32 ECUM_RESERVED4[15U];
  uint32 ECUM_MVFR0;                  /*!< Offset: 0x240 (R/ )  Media and VFP Feature Register 0 */
  uint32 ECUM_MVFR1;                  /*!< Offset: 0x244 (R/ )  Media and VFP Feature Register 1 */
  uint32 ECUM_MVFR2;                  /*!< Offset: 0x248 (R/ )  Media and VFP Feature Register 2 */
  uint32 ECUM_RESERVED5[1U];
  uint32 ECUM_ICIALLU;                /*!< Offset: 0x250 ( /W)  I-Cache Invalidate All to PoU */
  uint32 ECUM_RESERVED6[1U];
  uint32 ECUM_ICIMVAU;                /*!< Offset: 0x258 ( /W)  I-Cache Invalidate by MVA to PoU */
  uint32 ECUM_DCIMVAC;                /*!< Offset: 0x25C ( /W)  D-Cache Invalidate by MVA to PoC */
  uint32 ECUM_DCISW;                  /*!< Offset: 0x260 ( /W)  D-Cache Invalidate by Set-way */
  uint32 ECUM_DCCMVAU;                /*!< Offset: 0x264 ( /W)  D-Cache Clean by MVA to PoU */
  uint32 ECUM_DCCMVAC;                /*!< Offset: 0x268 ( /W)  D-Cache Clean by MVA to PoC */
  uint32 ECUM_DCCSW;                  /*!< Offset: 0x26C ( /W)  D-Cache Clean by Set-way */
  uint32 ECUM_DCCIMVAC;               /*!< Offset: 0x270 ( /W)  D-Cache Clean and Invalidate by MVA to PoC */
  uint32 ECUM_DCCISW;                 /*!< Offset: 0x274 ( /W)  D-Cache Clean and Invalidate by Set-way */
  uint32 ECUM_RESERVED7[6U];
  uint32 ECUM_ITCMCR;                 /*!< Offset: 0x290 (R/W)  Instruction Tightly-Coupled Memory Control Register */
  uint32 ECUM_DTCMCR;                 /*!< Offset: 0x294 (R/W)  Data Tightly-Coupled Memory Control Registers */
  uint32 ECUM_AHBPCR;                 /*!< Offset: 0x298 (R/W)  AHBP Control Register */
  uint32 ECUM_CACR;                   /*!< Offset: 0x29C (R/W)  L1 Cache Control Register */
  uint32 ECUM_AHBSCR;                 /*!< Offset: 0x2A0 (R/W)  AHB Slave Control Register */
  uint32 ECUM_RESERVED8[1U];
  uint32 ECUM_ABFSR;                  /*!< Offset: 0x2A8 (R/W)  Auxiliary Bus Fault Status Register */
} ECUM_SCB_Type;

#define ECUM_SCS_BASE            (0xE000E000UL)                                      /*!< System Control Space Base Address */
#define ECUM_SCB_BASE            (ECUM_SCS_BASE +  0x0D00UL)                         /*!< System Control Block Base Address */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
#define ECUM_SCB                 ((ECUM_SCB_Type       *)     ECUM_SCB_BASE      )   /*!< SCB configuration struct */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

#define CPU_MPU_MEMORY_COUNT (8U)
#define ECUM_MPU_A_COUNT     (3U)

/* ECUM_MPU - Register Layout Typedef */
typedef struct {
  uint8  ECUM_RESERVED0[3472U];
  uint32 ECUM_TYPE;                  /**< MPU Type Register, offset: 0xD90 */
  uint32 ECUM_CTRL;                  /**< MPU Control Register, offset: 0xD94 */
  uint32 ECUM_RNR;                   /**< MPU Region Number Register, offset: 0xD98 */
  uint32 ECUM_RBAR;                  /**< MPU Region Base Address Register, offset: 0xD9C */
  uint32 ECUM_RASR;                  /**< MPU Region Attribute and Size Register, offset: 0xDA0 */
  struct {                           /* offset: 0xDA4, array step: 0x8 */
    uint32 ECUM_RBAR;                /**< Alias of RBAR0..Alias of RBAR2, array offset: 0xDA4, array step: 0x8 */
    uint32 ECUM_RASR;                /**< Alias of RASR0..Alias of RASR2, array offset: 0xDA8, array step: 0x8 */
  } ECUM_Alias[ECUM_MPU_A_COUNT];
} ECUM_MPU_Type;
/* ECUM_MPU - Peripheral instance base addresses */
/* Peripheral ECUM_MPU base address */
#define ECUM_MPU_BASE                             (0xE000E000UL)

/* CTRL Bit Fields */
#define ECUM_MPU_CTRL_ENABLE_MASK                 0x1U

#if (HWRESOURCE_MCU(HWRESOURCE_CYT4BFXX) && (SWP_USE_DUALM == STD_OFF))
/**
  brief  CYT4BF Memory region tables. (Single Bank)

  Region  Description                   Start       End           Size[KB]  permission                attribute                 execute              srd     enable
--------  ----------------------------  ----------  ----------  ----------  ------------------------  ------------------------  -------------------  ------  ----------
       0  BACKGROUND_REGION             0x0         0xFFFFFFFF     4194304  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_STR_ORD_DEV      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       1  CM7_SELF_ITCM_REGION          0x0         0x00003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       2  CODE_FLASH_REGION_ADDR_0      0x10000000  0x107FFFFF        8192  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       3  CODE_FLASH_REGION_ADDR_1      0x10800000  0x1081FFFF         192  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       4  WORK_FLASH_REGION_ADDR        0x14000000  0x1403FFFF         256  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       5  CM7_SELF_DTCM_REGION_ADDR     0x20000000  0x20003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       6  SRAM_REGION_ADDR              0x28000000  0x280FFFFF        1024  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       7  PERI_REGISTER_REGION_ADDR     0x40000000  0x43FFFFFF       65536  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_SHR_DEV          MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
*/
static const uint32 EcuM_Rbar[CPU_MPU_MEMORY_COUNT] = {0x00000000UL, 0x00000000UL, 0x10000000UL, 0x10800000UL, 0x14000000UL, 0x20000000UL, 0x28000000UL, 0x40000000UL};
static const uint32 EcuM_Rasr[CPU_MPU_MEMORY_COUNT] = {0x1100003FUL, 0x0102001BUL, 0x0502003DUL, 0x0502C023UL, 0x11020023UL, 0x1102001BUL, 0x01020027UL, 0x11010033UL};
#endif

#if (HWRESOURCE_MCU(HWRESOURCE_CYT4BFXX) && (SWP_USE_DUALM == STD_ON))
/**
  brief  CYT4BF Memory region tables. (Dual Bank)

  Region  Description                   Start       End           Size[KB]  permission                attribute                 execute              srd     enable
--------  ----------------------------  ----------  ----------  ----------  ------------------------  ------------------------  -------------------  ------  ----------
       0  BACKGROUND_REGION             0x0         0xFFFFFFFF     4194304  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_STR_ORD_DEV      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       1  CM7_SELF_ITCM_REGION          0x0         0x00003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       2  CODE_FLASH_REGION_ADDR_0      0x10000000  0x103FFFFF        4096  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       3  CODE_FLASH_REGION_ADDR_1      0x10400000  0x1040FFFF          96  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       4  WORK_FLASH_REGION_ADDR        0x14000000  0x1403FFFF         256  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       5  CM7_SELF_DTCM_REGION_ADDR     0x20000000  0x20003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       6  SRAM_REGION_ADDR              0x28000000  0x280FFFFF        1024  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       7  PERI_REGISTER_REGION_ADDR     0x40000000  0x43FFFFFF       65536  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_SHR_DEV          MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
*/
static const uint32 EcuM_Rbar[CPU_MPU_MEMORY_COUNT] = {0x00000000UL, 0x00000000UL, 0x10000000UL, 0x10400000UL, 0x14000000UL, 0x20000000UL, 0x28000000UL, 0x40000000UL};
static const uint32 EcuM_Rasr[CPU_MPU_MEMORY_COUNT] = {0x1100003FUL, 0x0102001BUL, 0x0502002BUL, 0x0502C021UL, 0x11020023UL, 0x1102001BUL, 0x01020027UL, 0x11010033UL};
#endif

#if ((HWRESOURCE_MCU(HWRESOURCE_CYT3BBXX) || HWRESOURCE_MCU(HWRESOURCE_CYT4BBXX)) && (SWP_USE_DUALM == STD_OFF))
/**
  brief  CYT4BB/3BB Memory region tables. (Single Bank)

  Region  Description                   Start       End           Size[KB]  permission                attribute                 execute              srd     enable
--------  ----------------------------  ----------  ----------  ----------  ------------------------  ------------------------  -------------------  ------  ----------
       0  BACKGROUND_REGION             0x0         0xFFFFFFFF     4194304  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_STR_ORD_DEV      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       1  CM7_SELF_ITCM_REGION          0x0         0x00003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       2  CODE_FLASH_REGION_ADDR_0      0x10000000  0x103FFFFF        4096  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       3  CODE_FLASH_REGION_ADDR_1      0x10400000  0x1040FFFF          64  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       4  WORK_FLASH_REGION_ADDR        0x14000000  0x1403FFFF         256  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       5  CM7_SELF_DTCM_REGION_ADDR     0x20000000  0x20003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       6  SRAM_REGION_ADDR              0x28000000  0x2807FFFF         768  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       7  PERI_REGISTER_REGION_ADDR     0x40000000  0x43FFFFFF       65536  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_SHR_DEV          MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
*/
static const uint32 EcuM_Rbar[CPU_MPU_MEMORY_COUNT] = {0x00000000UL, 0x00000000UL, 0x10000000UL, 0x10400000UL, 0x14000000UL, 0x20000000UL, 0x28000000UL, 0x40000000UL};
static const uint32 EcuM_Rasr[CPU_MPU_MEMORY_COUNT] = {0x1100003FUL, 0x0102001BUL, 0x0502002BUL, 0x0502001FUL, 0x11020023UL, 0x1102001BUL, 0x0102C027UL, 0x11010033UL};
#endif

#if ((HWRESOURCE_MCU(HWRESOURCE_CYT3BBXX) || HWRESOURCE_MCU(HWRESOURCE_CYT4BBXX)) && (SWP_USE_DUALM == STD_ON))
/**
  brief  CYT4BB/3BB Memory region tables. (Dual Bank)

  Region  Description                   Start       End           Size[KB]  permission                attribute                 execute              srd     enable
--------  ----------------------------  ----------  ----------  ----------  ------------------------  ------------------------  -------------------  ------  ----------
       0  BACKGROUND_REGION             0x0         0xFFFFFFFF     4194304  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_STR_ORD_DEV      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       1  CM7_SELF_ITCM_REGION          0x0         0x00003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       2  CODE_FLASH_REGION_ADDR_0      0x10000000  0x101FFFFF        2048  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       3  CODE_FLASH_REGION_ADDR_1      0x10200000  0x10207FFF          32  MPU_ACCESS_P_PRIV_RO      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       4  WORK_FLASH_REGION_ADDR        0x14000000  0x1403FFFF         256  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       5  CM7_SELF_DTCM_REGION_ADDR     0x20000000  0x20003FFF          16  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
       6  SRAM_REGION_ADDR              0x28000000  0x2807FFFF         768  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_NORM_MEM_WT      MPU_INST_ACCESS_EN   0x00    MPU_ENABLE
       7  PERI_REGISTER_REGION_ADDR     0x40000000  0x43FFFFFF       65536  MPU_ACCESS_P_PRIV_RW      MPU_ATTR_SHR_DEV          MPU_INST_ACCESS_DIS  0x00    MPU_ENABLE
*/
static const uint32 EcuM_Rbar[CPU_MPU_MEMORY_COUNT] = {0x00000000UL, 0x00000000UL, 0x10000000UL, 0x10200000UL, 0x14000000UL, 0x20000000UL, 0x28000000UL, 0x40000000UL};
static const uint32 EcuM_Rasr[CPU_MPU_MEMORY_COUNT] = {0x1100003FUL, 0x0102001BUL, 0x05020029UL, 0x0502001DUL, 0x11020023UL, 0x1102001BUL, 0x0102C027UL, 0x11010033UL};
#endif

/**
  brief Specifies access permission of the MPU region

  Macro                         AP[26:24]  Description
  ----------------------------  ---------  ------------------------------------------------------------
  MPU_ACCESS_P_NO_ACCESS        000        All accesses generate a permission fault
  MPU_ACCESS_P_PRIV_RW          001        Access from privileged software only
  MPU_ACCESS_P_PRIV_RW_USER_RO  010        Writes by unprivileged software generate a permission fault
  MPU_ACCESS_P_FULL_ACCESS      011        Full access
  MPU_ACCESS_P_PRIV_RO          101        Reads by privileged software only
  MPU_ACCESS_P_RO               110        Read only, by privileged or unprivileged software


  brief Specifies attribute of the MPU region

  Macro                               TEX[21:19] C B S  Description
  ----------------------------------  ----------------  --------------------------------------------------------------------------
  MPU_ATTR_STR_ORD_DEV                000        0 0 0  Strongly-ordered, shareable
  MPU_ATTR_SHR_DEV                    000        0 1 0  Device, shareable
  MPU_ATTR_NORM_MEM_WT                000        1 0 0  Normal, Not shareable, Outer and inner write-through, No write allocate
  MPU_ATTR_NORM_SHR_MEM_WT            000        1 0 1  Normal, shareable,     Outer and inner write-through, No write allocate
  MPU_ATTR_NORM_MEM_WB                000        1 1 0  Normal, Not shareable, Outer and inner write-back,    No write allocate
  MPU_ATTR_NORM_SHR_MEM_WB            000        1 1 1  Normal, shareable,     Outer and inner write-back,    No write allocate
  MPU_ATTR_NORM_MEM_NC                001        0 0 0  Normal, Not shareable, Outer and inner non-cacheable
  MPU_ATTR_NORM_SHR_MEM_NC            001        0 0 1  Normal, shareable,     Outer and inner non-cacheable
  MPU_ATTR_NORM_MEM_WA                001        1 1 0  Normal, Not shareable, Outer and inner Write-Back, Write and read allocate
  MPU_ATTR_NORM_SHR_MEM_WA            001        1 1 1  Normal, shareable,     Outer and inner Write-Back, Write and read allocate
  MPU_ATTR_DEV                        002        0 0 0  Device, Not-shareable


  brief Attribute for different policy for outer and inter cache

  Macro                               TEX[21:19] C B S  Description
  ----------------------------------  ----------------  ---------------------------------------------------------------------------------------------------------------------------------
  MPU_ATTR_NORM_MEM_IN_NC_OUT_NC      004        0 0 0  Normal, Not-shareable, inner policy: Non-cachealbe,                          outer policy: Non-cacheable
  MPU_ATTR_NORM_MEM_IN_WA_OUT_NC      004        0 1 0  Normal, Not-shareable, inner policy: Write back,    write and read-Allocate, outer policy: Non-cacheable
  MPU_ATTR_NORM_MEM_IN_WT_OUT_NC      004        1 0 0  Normal, Not-shareable, inner policy: Write through, no Write-Allocate,       outer policy: Non-cacheable
  MPU_ATTR_NORM_MEM_IN_WB_OUT_NC      004        1 1 0  Normal, Not-shareable, inner policy: Write back,    no Write-Allocate,       outer policy: Non-cacheable
  MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_NC  004        0 0 1  Normal, shareable,     inner policy: Non-cachealbe,                          outer policy: Non-cacheable
  MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_NC  004        0 1 1  Normal, shareable,     inner policy: Write back,    write and read-Allocate, outer policy: Non-cacheable
  MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_NC  004        1 0 1  Normal, shareable,     inner policy: Write through, no Write-Allocate,       outer policy: Non-cacheable
  MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_NC  004        1 1 1  Normal, shareable,     inner policy: Write back,    no Write-Allocate,       outer policy: Non-cacheable
  MPU_ATTR_NORM_MEM_IN_NC_OUT_WA      005        0 0 0  Normal, Not-shareable, inner policy: Non-cachealbe,                          outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_MEM_IN_WA_OUT_WA      005        0 1 0  Normal, Not-shareable, inner policy: Write back,    write and read-Allocate, outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_MEM_IN_WT_OUT_WA      005        1 0 0  Normal, Not-shareable, inner policy: Write through, no Write-Allocate,       outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_MEM_IN_WB_OUT_WA      005        1 1 0  Normal, Not-shareable, inner policy: Write back,    no Write-Allocate,       outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WA  005        0 0 1  Normal, shareable,     inner policy: Non-cachealbe,                          outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WA  005        0 1 1  Normal, shareable,     inner policy: Write back,    write and read-Allocate, outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WA  005        1 0 1  Normal, shareable,     inner policy: Write through, no Write-Allocate,       outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WA  005        1 1 1  Normal, shareable,     inner policy: Write back,    no Write-Allocate,       outer policy: Write back,    write and read-Allocate
  MPU_ATTR_NORM_MEM_IN_NC_OUT_WT      006        0 0 0  Normal, Not-shareable, inner policy: Non-cachealbe,                          outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WA_OUT_WT      006        0 1 0  Normal, Not-shareable, inner policy: Write back,    write and read-Allocate, outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WT_OUT_WT      006        1 0 0  Normal, Not-shareable, inner policy: Write through, no Write-Allocate,       outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WB_OUT_WT      006        1 1 0  Normal, Not-shareable, inner policy: Write back,    no Write-Allocate,       outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WT  006        0 0 1  Normal, shareable,     inner policy: Non-cachealbe,                          outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WT  006        0 1 1  Normal, shareable,     inner policy: Write back,    write and read-Allocate, outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WT  006        1 0 1  Normal, shareable,     inner policy: Write through, no Write-Allocate,       outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WT  006        1 1 1  Normal, shareable,     inner policy: Write back,    no Write-Allocate,       outer policy: Write through, no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_NC_OUT_WB      007        0 0 0  Normal, Not-shareable, inner policy: Non-cachealbe,                          outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WA_OUT_WB      007        0 1 0  Normal, Not-shareable, inner policy: Write back,    write and read-Allocate, outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WT_OUT_WB      007        1 0 0  Normal, Not-shareable, inner policy: Write through, no Write-Allocate,       outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_MEM_IN_WB_OUT_WB      007        1 1 0  Normal, Not-shareable, inner policy: Write back,    no Write-Allocate,       outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_NC_OUT_WB  007        0 0 1  Normal, shareable,     inner policy: Non-cachealbe,                          outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WA_OUT_WB  007        0 1 1  Normal, shareable,     inner policy: Write back,    write and read-Allocate  outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WT_OUT_WB  007        1 0 1  Normal, shareable,     inner policy: Write through, no Write-Allocate,       outer policy: Write back,    no Write-Allocate
  MPU_ATTR_NORM_SHR_MEM_IN_WB_OUT_WB  007        1 1 1  Normal, shareable,     inner policy: Write back,    no Write-Allocate,       outer policy: Write back,    no Write-Allocate


  brief Specifies enable/disable of instruction access of the MPU region

  Macro                XN   Description
  -------------------  ---  -----------------------------
  MPU_INST_ACCESS_EN   0    Instruction fetches enabled
  MPU_INST_ACCESS_DIS  1    Instruction fetches disabled


  brief Specifies enable/disable of the MPU region

  Macro        ENABLE  Description
  -----------  ------  ------------
  MPU_DISABLE  0       Disable
  MPU_ENABLE   1       Enable

*/
#endif

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define ECUM_START_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : EcuM_AL_DriverInitZero                              **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities for   **
**                        loading the post-build configuration data. Note:    **
**                        Here only pre-compile and link-time configurable    **
**                        modules may be used.                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
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
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverInitZero                          **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitZero(void)
{
  #if (ECUM_DRIVER_INIT_ZERO == STD_ON)
  EcuM_Gen_AL_DriverInitZero();
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_AL_DriverInitOne                               **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities in    **
**                        case of a power on reset                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverInitOne                           **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverInitOne
  (P2CONST(EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_INIT_ONE == STD_ON)
  EcuM_Gen_AL_DriverInitOne(ConfigPtr);
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_AL_DriverRestart                               **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall provide driver initialization    **
**                        and other hardware-related startup activities in    **
**                        case of a power on reset.                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : ConfigPtr                                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)  : None                          **
**                        Function(s) invoked :                               **
**                        EcuM_Gen_AL_DriverRestart                           **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_DriverRestart
  (P2CONST (EcuM_ConfigType, AUTOMATIC, ECUM_APPL_CONST) ConfigPtr)
{
  #if (ECUM_DRIVER_RESTART == STD_ON)
  EcuM_Gen_AL_DriverRestart(ConfigPtr);
  #else
  ECUM_UNUSED_PTR(ConfigPtr);
  #endif
}

/*******************************************************************************
** Function Name        : EcuM_AL_SetProgrammableInterrupts                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF I state is about to be entered.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SetProgrammableInterrupts(void)
{
  /* Callout shall be filled by the system designer */
}

/*******************************************************************************
** Function Name        : EcuM_OnGoOffOne                                     **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF I state is about to be entered.          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
** Remarks              : Global Variable(s)     : EcuM_GddState              **
**                        Function(s) invoked    : BswM_EcuM_CurrentState()   **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffOne(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_ONE;

  /* Indicate state change to BswM */
  BswM_EcuM_CurrentState(EcuM_GddState);
}

/*******************************************************************************
** Function Name        : EcuM_OnGoOffTwo                                     **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This call allows the system designer to notify that **
**                        the GO OFF II state is about to be entered.         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
** Remarks              : Global Variable(s)     : EcuM_GddState              **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_OnGoOffTwo(void)
{
  EcuM_GddState = ECUM_STATE_GO_OFF_TWO;
}

/*******************************************************************************
** Function Name        : EcuM_AL_SwitchOff                                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall take the code for shutting off   **
**                        the power supply of the ECU. If the ECU cannot      **
**                        unpower itself, a reset may be an adequate reaction.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
** Remarks              : Global Variable(s)     : EcuM_GddState              **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_SwitchOff(void)
{
  EcuM_GddState = ECUM_STATE_OFF;
}

/*******************************************************************************
** Function Name        : EcuM_AL_Reset                                       **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout shall take the code for shutting off   **
**                        the power supply of the ECU. If the ECU cannot      **
**                        unpower itself, a reset may be an adequate reaction.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : reset                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : EcuM_GddState              **
**                        Function(s) invoked    : Mcu_PerformReset()         **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_AL_Reset(EcuM_ResetType reset)
{
  EcuM_GddState = ECUM_STATE_RESET;

  if ((reset == ECUM_RESET_MCU) || (reset == ECUM_INVALID_SHUTDOWN))
  {
    Mcu_PerformReset();
  }
}

/*******************************************************************************
** Function Name        : EcuM_EnableWakeupSources                            **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The ECU Manager Module calls EcuM_EnableWakeupSource**
**                        to allow the system designer to notify wakeup       **
**                        sources defined in the wakeupSource bitfield that   **
**                        SLEEP will be entered and to adjust their source    **
**                        accordingly.                                        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
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
**                        EcuM_ClearWakeupEvent(), DataLog_SetSleepOKLog(),   **
**                        EcuM_H2LTransition_Callout_Swp(),                   **
**                        EcuM_H2LTransition_Callout_App()                    **
*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_EnableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  ECUM_UNUSED(wakeupSource);

  /* Clear All Wakeup Sources */
  EcuM_ClearWakeupEvent(ECUM_WKSOURCE_ALL_SOURCES);
  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_SetSleepOKLog();
  #endif

  #if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
  /* Callout For Platform */
  EcuM_H2LTransition_Callout_Swp();

  /* Callout For User */
  EcuM_H2LTransition_Callout_App();
  #endif

  /* Callout for NML */
  #ifdef NML_USE
  Nml_DeInitToSleep();
  #endif

}

/*******************************************************************************
** Function Name        : EcuM_DisableWakeupSources                           **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall set up the given wakeup source(s) **
**                        so that they are not able to wakeup the ECU.        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
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
**                        DataLog_SetWakeupEventLog(),                        **
**                        EcuM_L2HTransition_Callout_Swp(),                   **
**                        EcuM_L2HTransition_Callout_App()                    **
*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_DisableWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  ECUM_UNUSED(wakeupSource);

  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_SetWakeupEventLog();
  #endif

  #if (ECUM_LP_CALLOUT_ENABLED == STD_ON)
  /* Callout For Platform */
  EcuM_L2HTransition_Callout_Swp();

  /* Callout For User */
  EcuM_L2HTransition_Callout_App();

  #ifdef NML_USE
  /* Callout for NML */
  Nml_InitSleepToWakeup();
  #endif

  #endif
}



/*******************************************************************************
** Function Name        : EcuM_CheckWakeup                                    **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is called by the EcuM to poll a wakeup **
**                        source. It shall also be called by the ISR of a     **
**                        wakeup source to set up the PLL and check other     **
**                        wakeup sources that may be connected to the same    **
**                        interrupt.                                          **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
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
**                        Function(s) invoked    : Gpt_CheckWakeup            **
**                                                 EcuM_Gen_CheckWakeup       **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckWakeup
  (EcuM_WakeupSourceType wakeupSource)
{
  #if (ECUM_ALARM_CLOCK_PRESENT == STD_ON)
  if (wakeupSource == ECUM_ALARM_WAKEUP_SOURCE_ID)
  {
    SchM_Enter_EcuM_ALARM_TIME_PROTECTION();

    Gpt_CheckWakeup(wakeupSource);

    SchM_Exit_EcuM_ALARM_TIME_PROTECTION();
  }
  else
  #endif
  {
    /* Nml Integration */
    #ifdef NML_USE
      /* Callout for NML */
      Nml_EcuM_LogDataCallout(wakeupSource);
    #endif

    /* Wakeup Sequence */
    EcuM_Gen_CheckWakeup(wakeupSource);
  }
}

/*******************************************************************************
** Function Name        : EcuM_StartWakeupSources                             **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall start the given wakeup source(s)  **
**                        so that they are ready to perform wakeup validation.**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StartWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(wakeupSource);
}

/*******************************************************************************
** Function Name        : EcuM_StopWakeupSources                              **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : The callout shall stop the given wakeup source(s)   **
**                        after unsuccessful wakeup validation.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : EcuM_WakeupSourceType wakeupSource                  **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_StopWakeupSources
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(wakeupSource);
}

/*******************************************************************************
** Function Name        : EcuM_CheckValidation                                **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is called by the EcuM to validate a    **
**                        wakeup source. If a valid wakeup has been detected, **
**                        it shall be reported to EcuM via                    **
**                        EcuM_ValidateWakeupEvent().                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : wakeupSource                                        **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_CheckValidation
  (EcuM_WakeupSourceType wakeupSource)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(wakeupSource);
}

/*******************************************************************************
** Function Name        : EcuM_GenerateRamHash                                **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : Used just before Putting the ECU physically to sleep**
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_GenerateRamHash(void)
{
  /* Callout shall be filled by the system designer */
}

/*******************************************************************************
** Function Name        : EcuM_SleepActivity                                  **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is invoked periodically in all reduced **
**                        clock sleep modes. It is explicitly allowed to poll **
**                        wakeup sources from this callout and to call wakeup **
**                        notification functions to indicate the end of the   **
**                        sleep state to the ECU State Manager.               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_SleepActivity(void)
{
  /* Callout shall be filled by the system designer */
}

/*******************************************************************************
** Function Name        : EcuM_CheckRamHash                                   **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout is intended to provide a RAM integrity **
**                        test.                                               **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : uint8                                               **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(uint8, ECUM_CALLOUT_CODE) EcuM_CheckRamHash(void)
{
  return (1);
}

/*******************************************************************************
** Function Name        : EcuM_DeterminePbConfiguration                       **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : This callout should evaluate some condition,        **
**                        like port pin or NVRAM value, to determine which    **
**                        post-build configuration shall be used in the       **
**                        remainder of the startup process. It shall load     **
**                        this configuration data into a piece of memory that **
**                        is accessible by all BSW modules and shall return a **
**                        pointer to the EcuM post-build configuration as a   **
**                        base for all BSW module post-build configurations.  **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : EcuM_ConfigType*                                    **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        EcuM_GaaConfig                                      **
**                        Function(s) invoked    :                            **
*******************************************************************************/
const EcuM_ConfigType* EcuM_DeterminePbConfiguration(void)
{
  /* The return value is updated only for compilation purpose. Valid address of
   *   EcuM_GaaConfig structure needs to be provided here. MISRA Rule 11.3 is
   * not considered in this case */
  P2CONST(EcuM_ConfigType, ECUM_CONST, ECUM_CONST) LpConfigPtr;
  LpConfigPtr = &EcuM_GaaConfig[0];
  return (LpConfigPtr);
}

/*******************************************************************************
** Function Name        : EcuM_ErrorHook                                      **
**                                                                            **
** Service ID           : 0x00                                                **
**                                                                            **
** Description          : In unrecoverable error situations, the ECU State    **
**                        Manager will call this callout. It is up the        **
**                        system integrator to react accordingly              **
**                        (reset, halt, restart, safe state etc. )            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : reason                                              **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_ErrorHook(Std_ReturnType reason)
{
  /* Callout shall be filled by the system designer */
  ECUM_UNUSED(reason);
}

/*******************************************************************************
** Function Name        : EcuM_SetMode                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for Set Mcu Mode                       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : McuMode                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : EcuM_GulPllCnt             **
**                        Function(s) invoked    :                            **
**                        WdgStack_TransitHighToLow(),                        **
**                        Mcu_GetPllStatus(), WdgStack_TransitHighToLow(),    **
**                        Icu_SetMode(), Mcu_SetMode(), Mcu_InitClock(),      **
**                        EnableAllInterrupts(), DisableAllInterrupts(),      **
**                        Det_ReportError(), Mcu_PerformReset(),              **
**                        SuspendAllInterrupts(), ResumeAllInterrupts()       **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_SetMode
  (Mcu_ModeType McuMode)
{
  #if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
  boolean isMasterCore;
  EcuM_WakeupSourceType validatedWakeupEvent;
  isMasterCore = EcuM_IsMasterCore();
  #endif

	uint16 i;

  static EcuM_WakeupSourceType validatedWakeupEvents;// WPC_32_05
  //static uint8 toggle = 0;

  do
  {

    /* Disable Interrupts(instruction is equivalent to writing a 1 into PRIMASK)
     * It should be located before EnableAllInterrupts()
     */

      __CPS(__CPS_DISABLE, __CPS_I, __CPS_DEFAULT);
    EnableAllInterrupts();
    #if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
    if (isMasterCore == TRUE)
    {
      /* Master Core: Enter Low Power Mode */
      Mcu_SetMode(McuMode);
    }
    else
    {
      /* Sub Core: Enter Low Power Mode */
      ECUM_SCB->ECUM_SCR |= ECUM_SCB_SCR_SLEEPDEEP_Msk;
      __WFI();
    }
    #else
    Mcu_SetMode(McuMode);
    #endif
    /* Enable Interrupts(instruction is equivalent to writing a 0 into PRIMASK)
     * It should be located before Icu_SetMode(), because ICU ISR should be
     * executed before peripheral flag cleared by Icu_SetMode()
     */

    __CPS(__CPS_ENABLE, __CPS_I, __CPS_DEFAULT);
    __ISB();

    // deep sleep 중 wdt pulse 발생시키기위해서 추가함.
    validatedWakeupEvents = EcuM_GetValidatedWakeupEvents();
    if(validatedWakeupEvents == ECUM_WKSOURCE_NONE)
    {
      gs_EVTGEN_Active();

      // 아래 방식으로 40ms 주기로 toggle하고 port high기간 최소화 하면 소비전류 약 400ua
      IoHwAb_DigDirWriteDirect(Rte_PDAV_IoHwAbP_WDT_CLEAR_PULSE_1, IOHWAB_HIGH);  // rte 사용하지 않고 mcal 직접 사용함.

      // 1/8mhz = 125ns 1clock당
      // 100us / 0.125us = 800
      // for문이 있으므로 2clock에 추가로 몇클럭 더 먹는듯.
      // 그러므로 값을 변화해 가면서 실측을 통해서 정확한 값은 찾음
	    for(i=0;i<520;i++)  // 소비전류 감소를 위해서 wdt clear 가능한 최소 시간 동안만 high 유지
      {
		    __asm("nop");    // 실측 : 약 105us
	    }

      // The watchdog service signal (WD) must stay high for at least 100 μs. (TMP1210/11 data sheet)
      IoHwAb_DigDirWriteDirect(Rte_PDAV_IoHwAbP_WDT_CLEAR_PULSE_1, IOHWAB_LOW);  // rte 사용하지 않고 mcal 직접 사용함.

    }

    DisableAllInterrupts();
  }
  while(validatedWakeupEvents == ECUM_WKSOURCE_NONE);

  // Normal --> DeepSlee 진입시 호출됨. // ign on 엣지에도 호출되고 ign off 엣지에서도 호출되는듯.

  // SWP에 등록된 Wakeup Source에 의해서 wakeup 되면 여기서 계속 sleep할지 아니면 normal wakeup 할지 판단이 되지만
  // evtgen에 의해서 wakeup 되었을때는 cdd로 만든것이기 때문에 swp는 알지 못하고 ECUM_WKSOURCE_NONE 인 상태로 wakeup 된다.

  // 그러므로 evtgen에 의해서 wakeup 되었을때는 깨어나지 않고 계속
  // do while에 머무르면서 wdt clear pulse를 100us toggle 처리를 하도록 하자.
}

#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT3BXX) || HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX))
/*******************************************************************************
** Function Name        : EcuM_Enable_Pcache                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Enable PCache of each cores                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : McuMode                                             **
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
**                        None                                                **
*******************************************************************************/
static FUNC(void, ECUM_CALLOUT_CODE) EcuM_Enable_Pcache(void)
{
  __DSB();
  __ISB();
  ECUM_SCB->ECUM_ICIALLU = 0UL;                        /* invalidate I-Cache */
  __DSB();
  __ISB();
  ECUM_SCB->ECUM_CCR |=  (uint32)ECUM_SCB_CCR_IC_Msk;  /* enable I-Cache */
  __DSB();
  __ISB();
}
#endif

/***************************************************************************//**
 * Function Name        : EcuM_Enable_Dma
 *
 * Service ID           : NA
 *
 * Description          : Enable Dma for Fls
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
 *                        None
 *
 *                        Function(s) invoked    :
 *                        None
 ******************************************************************************/
static FUNC(void, ECUM_CALLOUT_CODE) EcuM_Enable_Dma(void)
{
  /* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  volatile uint32* dmactl = 0x402A0000;
  /* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  /* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  *dmactl |= 0x80000000U;
  /* polyspace:end<RTE:NIV> */
}

#if (HWRESOURCE_FAMILY(HWRESOURCE_CYT3BXX) || HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX))
/*******************************************************************************
** Function Name        : EcuM_Enable_MPU                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Enable MPU of each cores                            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : McuMode                                             **
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
**                        None                                                **
*******************************************************************************/
static FUNC(void, ECUM_CALLOUT_CODE) EcuM_Enable_MPU(void)
{
  /* Peripheral ECUM_MPU base pointer */
  volatile ECUM_MPU_Type *ECUM_MPU = ((ECUM_MPU_Type *)ECUM_MPU_BASE);
  uint8 EcuM_LddRegionNum = 0U;
  __DMB();

  /* Set default memory regions */
    for (EcuM_LddRegionNum = 0U; EcuM_LddRegionNum < CPU_MPU_MEMORY_COUNT; EcuM_LddRegionNum++)
    {
        ECUM_MPU->ECUM_RNR  = EcuM_LddRegionNum;
        ECUM_MPU->ECUM_RBAR = EcuM_Rbar[EcuM_LddRegionNum];
        ECUM_MPU->ECUM_RASR = EcuM_Rasr[EcuM_LddRegionNum];
    }
    /* Enable MPU */
    ECUM_MPU->ECUM_CTRL |= ECUM_MPU_CTRL_ENABLE_MASK;

    __DSB();
    __ISB();

}
#endif

/*******************************************************************************
** Function Name        : EcuM_PreInit                                        **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for before EcuM Init                   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : McuMode                                             **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : EcuM_GddResetReason        **
**                        Function(s) invoked    :                            **
*******************************************************************************/
FUNC(void, ECUM_CALLOUT_CODE) EcuM_PreInit(void)
{
  /* Set default reset reason */
  EcuM_GddResetReason = MCU_POWER_ON_RESET;

  #if (HWRESOURCE_FAMILY(HWRESOURCE_CYT3BXX) || HWRESOURCE_FAMILY(HWRESOURCE_CYT4BXX))
  /* Enable PCache */
  EcuM_Enable_Pcache();

  /* Enable FPU */
  #if (OS_FPU_SUPPORT == STD_ON)
  OS_SCB_CPACR.B.CP10 = OS_SCB_CPACR_CP10_FULL_ACCESS;
  OS_SCB_CPACR.B.CP11 = OS_SCB_CPACR_CP11_FULL_ACCESS;

  OS_FPU_FPCCR.B.LSPEN = OS_FPU_FPCCR_LSPEN_DISABLE;
  OS_FPU_FPCCR.B.ASPEN = OS_FPU_FPCCR_ASPEN_DISABLE;

  __DSB();
  __ISB();
  #endif

  EcuM_Enable_MPU();
  #endif

  /* Enable DMA */
  EcuM_Enable_Dma();
}

/*******************************************************************************
** Function Name        : EcuM_PostInit                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Callout used for after Mcal Init                    **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : McuMode                                             **
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
FUNC(void, ECUM_CALLOUT_CODE) EcuM_PostInit(void)
{
}

/*******************************************************************************
** Function Name        : EcuM_RequestSleep                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Integration Code For Request Sleep using Release    **
**                        Run API                                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : user                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     : EcuM_GpEcuMConfigPtr       **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        EcuM_SelectShutdownTarget(),                        **
**                        DataLog_SetSleepConditionLog(), EcuM_ReleaseRUN()   **
*******************************************************************************/
FUNC(Std_ReturnType, ECUM_CALLOUT_CODE) EcuM_RequestSleep
  (EcuM_UserType user)
{
  Std_ReturnType LddStdRetVal = E_NOT_OK;

  /* polyspace-begin MISRA2012:D4.14 [Justified:Medium] "Pointer is initialized in EcuM_Init" */
  (void)EcuM_SelectShutdownTarget(ECUM_STATE_SLEEP,
                                  EcuM_GpEcuMConfigPtr->ucEcuMDefaultSleepMode);
  /* polyspace-end MISRA2012:D4.14 */

  #if (SWP_USE_DATALOG == STD_ON)
  DataLog_SetSleepConditionLog();
  #endif
  
  /* Callout for NML */
  #ifdef NML_USE
  Nml_PrepareSleep();
  #endif
  
  LddStdRetVal = EcuM_ReleaseRUN(user);

  return LddStdRetVal;
}

/*******************************************************************************
** Function Name        : EcuM_RequestReset                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Integration Code For Request Reset using Release    **
**                        Run API                                             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : user                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    : EcuM_SelectShutdownTarget  **
**                                                 EcuM_ReleaseRUN            **
*******************************************************************************/
FUNC(Std_ReturnType, ECUM_CALLOUT_CODE) EcuM_RequestReset
  (EcuM_UserType user)
{
  Std_ReturnType LddStdRetVal = E_NOT_OK;

  (void)EcuM_SelectShutdownTarget(ECUM_STATE_RESET, ECUM_RESET_MCU);

  LddStdRetVal = EcuM_ReleaseRUN(user);

  return LddStdRetVal;
}

/*******************************************************************************
** Function Name        : EcuM_RequestOff                                     **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Integration Code For Request Off using Release Run  **
**                        API                                                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Reentrancy           : Reentrant                                           **
**                                                                            **
** Input Parameters     : user                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType (E_OK or E_NOT_OK)                   **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                                            **
**                        Function(s) invoked    : EcuM_SelectShutdownTarget  **
**                                                 EcuM_ReleaseRUN            **
*******************************************************************************/
FUNC(Std_ReturnType, ECUM_CALLOUT_CODE) EcuM_RequestOff
  (EcuM_UserType user)
{
  Std_ReturnType LddStdRetVal = E_NOT_OK;

  (void)EcuM_SelectShutdownTarget(ECUM_STATE_OFF, 0);

  LddStdRetVal = EcuM_ReleaseRUN(user);

  return LddStdRetVal;
}

#if (ECUM_MULTI_CORE_SUPPORT == STD_ON)
/* polyspace-begin MISRA2012:8.4 [Justified:Low] "Reserved function" */
/*******************************************************************************
** Function Name        : EcuM_MainFunction1                                  **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Runnable of Service SW Component EcuM_Slave1        **
**                                                                            **
** Sync/Async           : Sync                                                **
**                                                                            **
** Reentrancy           : None                                                **
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
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        EcuM_MainFunction()                                 **
*******************************************************************************/
FUNC(void, ECUM_CODE) EcuM_MainFunction1(void)
{
  EcuM_MainFunction();
}
#endif


#define ECUM_STOP_SEC_CALLOUT_CODE
#include "MemMap.h"
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA2012:20.1 */
/* polyspace-end MISRA2012:D4.5 */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
