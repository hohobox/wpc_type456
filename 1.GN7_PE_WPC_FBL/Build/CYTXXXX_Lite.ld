/*******************************************************************************
**                                                                            **
**  (C) 2020~21 HYUNDAI AUTOEVER Co., Ltd.                                    **
**  Confidential Proprietary Information. Distribution Limited.               **
**  Do Not Copy Without Prior Permission                                      **
**                                                                            **
**  SRC-MODULE: CYT4BXXX_FBL.ld                                               **
**                                                                            **
**  TARGET    : TRAVEO II                                                     **
**                                                                            **
**  PRODUCT   : BOOTLOADER                                                    **
**                                                                            **
**  PURPOSE   : This file provides Linker commands for memory placements      **
**				driver software for TRAVEO II.               				  **
**                                                                            **
**  HARDWARE DEPENDANT [yes/no]: Yes                                          **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                             Revision History                               **
********************************************************************************
** Revision    Date          By           Description                         **
********************************************************************************
** 1.0.0.0     22-Apr-2021   JHLim        Initial version                     **
*******************************************************************************/

 /*
  * [Memory Layout for mobilgene Classic SWP] 
  * -----------------------------------------------------------------------------
  * | CM0+ [HSM]      | CM4 or CM7_0 [FBL] | CM4 or CM7_0 [RTSW]                |
  * | RAM : 40KB      | RAM : 40KB         | RAM : End of CM0+ ~ End of MCU     |
  * | ROM : 160KB     | ROM : 128KB        | ROM : End of FBL  ~ End of MCU     |
  * -----------------------------------------------------------------------------
  */

 /* [CODE Blocks Information of TV-II] 
  *  (SB : Single Bank, DB : Dual Bank, LS : Large Sector, SS : Small Sector)
  * 
  * {CYT2B7XX_1M}
  *  - SRAM0             : 0x0800_0000--0x0800_FFFF   (64KB) 
  *  - SRAM1             : 0x0801_0000--0x0801_FFFF   (64KB) 
  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x100E_FFFF  (960KB) 
  *  - CODE_SB_SS[8KB]   : 0x100F_0000--0x1010_FFFF  (128KB)
  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x1007_7FFF  (480KB) 
  *  - CODE_DB_SS[8KB]   : 0x1007_8000--0x1008_8000   (64KB)  
  *
  * {CYT2B9XX_2M}
  *  - SRAM0             : 0x0800_0000--0x0801_FFFF  (128KB) 
  *  - SRAM1             : 0x0802_0000--0x0803_FFFF  (128KB) 
  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x101E_FFFF (1984KB) 
  *  - CODE_SB_SS[8KB]   : 0x101F_0000--0x1020_FFFF  (128KB) 
  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x100F_7FFF  (992KB) 
  *  - CODE_DB_SS[8KB]   : 0x100F_8000--0x1010_7FFF   (64KB) 
  *  
  * {CYT2BLXX_4M}
  *  - SRAM0             : 0x0800_0000--0x0803_FFFF  (256KB) 
  *  - SRAM1             : 0x0804_0000--0x0807_FFFF  (256KB) 
  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x103E_FFFF (4032KB) 
  *  - CODE_SB_SS[8KB]   : 0x103F_0000--0x1040_FFFF  (128KB) 
  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x101F_7FFF (2016KB) 
  *  - CODE_DB_SS[8KB]   : 0x101F_8000--0x1020_7FFF   (64KB)   
  * 
  * {CYT3BB_4BB_4M}
  *  - SRAM0             : 0x2800_0000--0x2807_FFFF  (512KB)
  *  - SRAM1             : 0x2808_0000--0x280B_FFFF  (256KB)
  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x103E_FFFF (4032KB) 
  *  - CODE_SB_SS[8KB]   : 0x103F_0000--0x1040_FFFF  (128KB) 
  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x101F_7FFF (2016KB) 
  *  - CODE_DB_SS[8KB]   : 0x101F_8000--0x1020_7FFF   (64KB)   
  * 
  * {CYT4BFXX_8M}
  *  - SRAM0             : 0x2800_0000--0x2807_FFFF  (512KB)
  *  - SRAM1             : 0x2808_0000--0x280B_FFFF  (256KB)  
  *  - SRAM2             : 0x280C_0000--0x280F_FFFF  (256KB)  
  *  - CODE_SB_LS[32KB]  : 0x1000_0000--0x107E_FFFF (8128KB) 
  *  - CODE_SB_SS[8KB]   : 0x107F_0000--0x1082_FFFF  (256KB) 
  *  - CODE_DB_LS[32KB]  : 0x1000_0000--0x103F_7FFF (4064KB) 
  *  - CODE_DB_LS[8KB]   : 0x103F_8000--0x1041_7FFF  (128KB)
  */
DEFAULTS
{
  intvec_alignment = 1024
  ecc_init_width = 8
  cm4_stack_reserve = 1k
  stack_reserve = (cm4_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
}

MEMORY
{
  /* ROM allocations. total size : 192KB. 0x1002_8000--0x1005_7FFF */
  CM0_ROM_Reserved       : ORIGIN = 0x10000000, LENGTH = 0x28000     /* 160KB      - ROM for CM0 Executable */
    /*  FBL total size              : 192KB   . 0x1002_8000--0x1005_7FFF */
  FBL_RESET	             : ORIGIN = 0x10028000, LENGTH = 0x400              /* 1K Bytes  - FBL Reset Vector */
  FBL_CODE               : ORIGIN = 0x10028400, LENGTH = 0x30000 - 0x400  /* 191KB     - FBL Executable */
    /*  APPL total size (DualBank)  : 3840KB  . 0x1005_8000--0x1041_7FFF */
  APPL_RSVD              : ORIGIN = 0x10058000, LENGTH = 0x3C0000           /* 3840KB for Application Executable */

  /* RAM allocations. total size : 40KB. 0x0800_A000--0x0801_3FFF */
  CM0_RAM_Reserved       : ORIGIN = 0x08000000, LENGTH = 0xA000      /* 40KB       - RAM for CM0 executable */
  
    /*  SRAM total size             : 52KB    . 0x2800_A000--0x2801_6FFF */
  STARTUP_COMMAND        : ORIGIN = 0x0800A000, LENGTH = 0x10        /* 16 Bytes      - RAM to store Startup command by application to retain control in Bootloader for re-programming */
  BTL_APPL_COMMON_RAM    : ORIGIN = 0x0800A010, LENGTH = 0x40        /* 64 Bytes      - Shared RAM between application to store Programming conditions */
  RAM_FLSDRV             : ORIGIN = 0x0800A050, LENGTH = 0xFB0       /* 3K 944 Bytes  - RAM for Flash driver executable */
  SRAM                   : ORIGIN = 0x0800B000, LENGTH = 0xC000      /* 48K Bytes     - SRAM */
  SRAM_RST_NO_CLEAR_BTL  : ORIGIN = 0x08017000, LENGTH = 0x1000      /* 4K Bytes     - Ram for debug variables for FBL */
}

SECTIONS
{
  /* ROM SECTIONS */
   /* When M0+ HSM "activate" M4 core, Vector Table Start Address should be located at CM4_VECTOR_TABLE_BASE register (0x10028000)
    * WHen M4 FBL "jump" M4 RTSW, Reset Handler StartAddress should be located at RTSW Start Address (0x10058000)
    */ 
  .vector.EXCEPTION              ALIGN(intvec_alignment): > FBL_RESET
  .picbase                                              : > .

  
  MAINSW_MODULE_INFO                               0x10028800  : > .
  MAINSW_CRC                                       0x10028810  : > .
  MAINSW_SIGNATURE                      PAD(512)   0x10028900  : > .
  .ASW_SECURITY_KEY                                0x10028B00  : > . /* 코드 분석시 32byte 사용함. */
  
  /* [수평공지][R40/R44][Wdg] CYTxxx SW Reset 이후 WDT에 의한 이중 Reset 방지 건 적용 시작 */
  /*.text                                            0x10028C00  : > . */ /* app 시작 주소 */
  .START_CODE                                       0x10028C00  : > .
  .text                                                 : > .
  /* [수평공지][R40/R44][Wdg] CYTxxx SW Reset 이후 WDT에 의한 이중 Reset 방지 건 적용 끝 */
  
  .ghtws.text                                           : > .    /* For Green Hills Compiler */
  .intercall                                            : > .
  .interfunc                                            : > .
  .fixaddr                                              : > .
  .fixtype                                              : > .
  .secinfo                                              : > .
  .robase                                               : > .
  .rodata                                               : > .
  .syscall                                  ALIGN(8)    : > .
  .ROM.data        ROM(.data)               ALIGN(8)    : > .
  .LIB_CODE                                ALIGN(4K)    : { *(".text.OS_API_CODE") } > .
  .ROM.BTL_CFLS_CODE    ROM(.BTL_CFLS_CODE) ALIGN(8)    : > .

  .EcucPartition_Main_CODE                 ALIGN(32)    : { *(".text.EcucPartition_Main_CODE")
                                                            *(".text.EcucPartition_Sub_CODE")
                                                            *(".text.DEFAULT_CODE")
                                                            *(".text.DEFAULT_CALLOUT_CODE")
                                                            *(".text.RTE_CODE")
                                                            *(".text.DCM_CODE")
                                                            *(".text.CANTP_CODE")
															*(".text.FOTA_CODE")
															*(".text.CRYPTO_76_HAEMODULE_SEC_CODE")} > .
															
  HSM_DRIVER_SECTION_CODE					ALIGN(8)    : > . 
  .EcucPartition_Main_CONST                ALIGN(32)    : { *(".rodata.EcucPartition_Main_ROM_CONST")
                                                            *(".rodata.DEFAULT_ROM_CONST*")
                                                            *(".rodata.CRYPTO_76_HAEMODULE_ROM_CONST_UNSPECIFIED")} > .                                                       
  HSM_DRIVER_SECTION_RODATA			ALIGN(8)            : > .
  
  FBL_VERSION_INFO                           0x10057FE0 : > . /* 010D_01 */ /* The last region of the FBL, 0x20 (32 bytes) is reserved as the Version Info area*/
  
  /* RAM SECTIONS */
  .BTL_CFLS_CODE                           ALIGN(8)     : > RAM_FLSDRV

  .sram_base       ALIGN(8)                             : > SRAM
  .stack           ALIGN(8)          PAD(stack_reserve) : > .
  .OS_STACK_CORE0  ALIGN(8)                     CLEAR   : {  *(".bss.OS_RAM_STACK_CORE0_CLEARED_UNSPECIFIED") } > .
  
  .bss             ALIGN(8)                     CLEAR   : {  *(".bss.EcucPartition_Main_RAM_VAR_CLEARED*")
                                                             *(".bss.DEFAULT_RAM_VAR_CLEARED*")
                                                             *(".bss.DEFAULT_SAFETY_VAR_CLEARED*")
                                                             *(".bss.RTE_RAM_VAR_CLEARED*")
                                                             *(".bss.*RAM_VAR*CLEARED*")
                                                             *(".bss.*RAM_VAR*INIT*")
                                                             *(".bss.NVM_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED")
                                                             *(".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED*")
                                                             *(".bss.CRYPTO_76_HAEMODULE_RAM_VAR_CLEARED_UNSPECIFIED")
                                                             *("HSM_DRIVER_SECTION_BSS")
                                                             *("HSM_DRIVER_SECTION_CTX") } > .
                                                             
  HSM_DRIVER_SECTION_BSS	ALIGN(8) CLEAR : > .
  HSM_DRIVER_SECTION_CTX	ALIGN(8) CLEAR : > .
  .bss_noclear                                NOCLEAR   : { *(".bss.DEFAULT_RAM_VAR_NO_INIT*")
                                                            *(".bss.DEFAULT_RAM_VAR_SAVED_ZONE*")
                                                            *(".bss.*NO_INIT*")
                                                            *(".bss.*VAR*NO_CLEAR*")
                                                            *(".bss.*VAR*SAVED*")
                                                            *(".bss.*SAVED_ZONE") } > .
															
  .BTL_RS_DATA                             PAD(512)  NOCLEAR   : > .

  .intvec_ram      ALIGN(intvec_alignment)        NOCLEAR      : > .
  .pidbase                                        ALIGN(16)    : > .
  .data                                           ALIGN(32)    : {   *(".data")
								     								 *(".feeInitArea_data")
                                                                     *(".data.EcucPartition_Main_RAM_VAR_INIT*")
                                                                     *(".data.DEFAULT_RAM_VAR_INIT*")
                                                        			 *(".data.*VAR_INIT*")
                                                                     *(".data.CRYPTO_76_HAEMODULE_RAM_VAR_INIT_UNSPECIFIED")
                                                                     *("HSM_DRIVER_SECTION_DATA") } > .
  OS_MAIN_BOS = addr(.stack);
  OS_MAIN_TOS = addr(.stack)+sizeof(.stack);

  __Mem_76_Pfls_RomStart         = ADDR(.ROM.BTL_CFLS_CODE);
  __Mem_76_Pfls_RomEnd           = ADDR(.ROM.BTL_CFLS_CODE) + SIZEOF(.ROM.BTL_CFLS_CODE);
  __Mem_76_Pfls_RomSize          = ((ENDADDR(.ROM.BTL_CFLS_CODE) - ADDR(.ROM.BTL_CFLS_CODE))%8==0)?((ENDADDR(.ROM.BTL_CFLS_CODE) - ADDR(.ROM.BTL_CFLS_CODE))/8):((ENDADDR(.ROM.BTL_CFLS_CODE) - ADDR(.ROM.BTL_CFLS_CODE))/8)+1;
  __Mem_76_Pfls_RamCode          = ADDR(.BTL_CFLS_CODE);

  __LD_BTL_RS_ADDR = ADDR(SRAM_RST_NO_CLEAR_BTL);
  __LD_BTL_RS_SIZE = ENDADDR(SRAM_RST_NO_CLEAR_BTL) - ADDR(SRAM_RST_NO_CLEAR_BTL);

  __ghs_romstart = MEMADDR(FBL_RESET);
  __ghs_romend   = MEMENDADDR(FBL_CODE);
  __ghs_ramstart = MEMADDR(STARTUP_COMMAND);
  __ghs_ramend   = MEMENDADDR(SRAM);

  __ghsbegin_stack = ADDR(.stack);
  __ghsend_stack = ENDADDR(.stack);
  __ghsbegin_robase = ADDR(.robase);
    
  __ghsbegin_picbase     = 0;
  __ghsbegin_robase      = 0;
  __ghsbegin_pidbase     = 0;
  __ghs_rombootcodestart = MEMADDR(FBL_RESET);
  __ghs_rombootcodeend   = MEMENDADDR(FBL_CODE);
  __ghs_rambootcodestart = 0;
  __ghs_rambootcodeend   = 0;


}

/*******************************************************************************
**                               End of File                                  **
*******************************************************************************/
