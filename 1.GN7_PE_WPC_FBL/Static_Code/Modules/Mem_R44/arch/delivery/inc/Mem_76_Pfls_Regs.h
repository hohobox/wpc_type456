/*******************************************************************************
**                                                                            **
**  (C) 2022 HYUNDAI AUTOEVER Corp.                                           **
**  Confidential Proprietary Information. Distribution Limited.               **
**  This source code is permitted to be used only in projects contracted      **
**  with Hyundai Autoever, and any other use is prohibited.                   **
**  If you use it for other purposes or change the source code,               **
**  you may take legal responsibility.                                        **
**  In this case, There is no warranty and technical support.                 **
**                                                                            **
**  SRC-MODULE: Mem_76_Pfls_Regs.h                                            **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR Memory Driver                                         **
**                                                                            **
**  PURPOSE   : Provide all marcos for internal module                        **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By                        Description              **
********************************************************************************
** 1.0.0     13-Sep-2022   LinhTT36                  Redmine #35543           **
*******************************************************************************/
#ifndef MEM_76_PFLS_REGS_H
#define MEM_76_PFLS_REGS_H

/*******************************************************************************
**                      Include Section                                       **
********************************************************************************/

/*******************************************************************************
**                             Macro Definition                               **
*******************************************************************************/
typedef struct stc_WDT_LOCK_field
{
  uint32    u2WDT_LOCK:2;
  uint32              :30;
} stc_WDT_LOCK_field;
typedef struct stc_WDT_SERVICE_field {
  uint32                         u1SERVICE:1;
  uint32                         :31;
} stc_WDT_SERVICE_field;

#define SRSS_WDG_LOCK_BASE          0x4026C040UL
#define SRSS_WDG_LOCK               ((volatile stc_WDT_LOCK_field *)SRSS_WDG_LOCK_BASE)

#define SRSS_WDG_SERVICE_BASE          0x4026C044UL
#define SRSS_WDG_SERVICE               ((volatile stc_WDT_SERVICE_field *)SRSS_WDG_SERVICE_BASE)

#define MEM_76_PFLS_REG(ADDR)                               (*(volatile uint32 *)(ADDR))

#define MEM_76_PFLS_SS_ADDRESS_MASK                               ((uint32)0x107F0000UL)

/* Macro for accessing flash module registers */
#define MEM_76_PFLS_IPC_STRUCT1_DATA0                             ((uint32)0x4022002CUL)

#define MEM_76_PFLS_IPC_STRUCT1_NOTIFY                            ((uint32)0x40220028UL)
#define MEM_76_PFLS_IPC_STRUCT_ACQUIRE                            ((uint32)0x40220020UL)
#define MEM_76_PFLS_IPC_STRUCT1_RELEASE                           ((uint32)0x40220024UL)
#define MEM_76_PFLS_STRUCT1_LOCK_STATUS                           ((uint32)0x4022003CUL)
#define MEM_76_PFLS_FLASHC_MAIN_FLASH_SAFETY                      ((uint32)0x4024F400UL)
#define MEM_76_PFLS_FLASHC_STATUS                                 ((uint32)0x4024F404UL)
#define MEM_76_PFLS_CM0P_SCS_ISER                                 ((uint32)0xe000E100UL)
#define MEM_76_PFLS_CM0P_SCS_ICER                                 ((uint32)0xe000E180UL)
/* NVIC Interrupt Priority Register 0 */
#define MEM_76_PFLS_CM0P_SCS_IPR0                                 ((uint32)0xE000E400UL)
/* Control */
#define FLASHC_FLASH_CTL                                  ((uint32)0x40240000UL)

/* Macros for flash IRQ handlings */
/* Value for enabling IRQ0 and IRQ1 */
#define MEM_76_PFLS_VALUE__NVIC_ISER__IRQ0_1                      ((uint32)0x00000003UL)
/* Value for disabling all IRQs but IRQ0 and IRQ1 */
#define MEM_76_PFLS_VALUE__NVIC_ICER__NOT_IRQ0_1                  ((uint32)0xFFFFFFFCUL)
/* Assigns higher priority to IRQ1 than IRQ0 */
#define MEM_76_PFLS_VALUE__NVIC_IPR0__1_HIGHER_0                  ((uint32)0x00000040UL)

#define MEM_76_PFLS_VALUE_RELEASE_IPC_STRUCT                      ((uint32)0xFFFFFFFFUL)

#define MEM_76_PFLS_WRITE_SUCCESS                                 ((uint32)0xA0000000UL)
#define MEM_76_PFLS_ERASE_SUCCESS                                 ((uint32)0xA0000000UL)
#define MEM_76_PFLS_ACQUIRED_MASK                                 ((uint32)0x80000000UL)
#define MEM_76_PFLS_SUCCESS_MASK                                  ((uint32)0x80000000UL)
#define MEM_76_PFLS_WRITE_512_CFG                                 ((uint32)0x00000009UL)
#define MEM_76_PFLS_WRITE_32_CFG                                  ((uint32)0x00000005UL)
#define MEM_76_PFLS_WRITE_8_CFG                                   ((uint32)0x00000003UL)
#define MEM_76_PFLS_BLOCKING                                      ((uint32)0x00000100UL)
#define MEM_76_PFLS_SKIP_BLANK_CHECK                              ((uint32)0x00010000UL)
#define MEM_76_PFLS_FLASH_BANK_MASK                               ((uint32)0x00001000UL)
#define MEM_76_PFLS_FLASH_MAP_MASK                                ((uint32)0x00000100UL)

#define MEM_76_PFLS_NUM_8                                                            8UL
#define MEM_76_PFLS_NUM_32                                                          32UL
#define MEM_76_PFLS_NUM_512                                                        512UL
#define MEM_76_PFLS_OPCODE_BIT                                                      24UL
#define MEM_76_PFLS_ERASE_SECTOR_OPCODE                                    (uint8)0x14UL
#define MEM_76_PFLS_PROGRAM_ROW_OPCODE                                     (uint8)0x06UL

#if(MEM_76_PFLS_SUPPORT_MCU == MEM_76_PFLS_MCU_CYT6BJX)
#define MEM_76_PFLS_ERASE2_SECTOR_OPCODE                                   (uint8)0x1CUL
#define MEM_76_PFLS_PROGRAM2_ROW_OPCODE                                    (uint8)0x09UL
#define MEM_76_PFLS_FLASHC1_MAIN_FLASH_SAFETY                     ((uint32)0x4025F400UL)
#endif

/* Macro for one Large Sector's size */
#define MEM_76_PFLS_CFLASH_LS_SIZE                                             (0x8000U)
/* Macro for one Small Sector's size */
#define MEM_76_PFLS_CFLASH_SS_SIZE                                             (0x2000U)

#define MEM_76_PFLS_SINGLE_BANK_MODE                                                 0UL

#define MEM_76_PFLS_DUAL_BANK_MODE                                                   1UL

#define MEM_76_PFLS_RESERVED_VAL                                                 (0x00U)

#define MEM_76_PFLS_CFLASH_LS_START_ADDRESS                       ((uint32)0x10000000UL)

#endif
