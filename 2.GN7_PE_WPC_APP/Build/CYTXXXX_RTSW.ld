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
** 1.0.0.0     22-Apr-2021   JH Lim       Initial version                     **
** 1.0.0.1     22-Sep-2022   JC Kim       integration of linker scripts from  **
**                                        various MCU families                **
*******************************************************************************/

 /*
  * [Memory Layout for mobilgene Classic SWP] 
  * -----------------------------------------------------------------------------
  * | CM0+ [HSM]      | CM4 or CM7_0 [FBL] | CM4 or CM7_0 [RTSW]                |
  * | RAM : 40KB      | RAM : 40KB         | RAM : End of CM0+ ~ End of MCU     |
  * | ROM : 160KB     | ROM : 192KB        | ROM : End of FBL  ~ End of MCU     |
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
  *  - CODE_DB_SS[8KB]   : 0x103F_8000--0x1041_7FFF  (128KB)
  */
  
DEFAULTS
{
#if (defined(CYT2B9XX) || defined(CYT2BLXX))
  intvec_alignment = 1024
#elif (defined(CYT3BBXX) || defined(CYT4BBXX) || defined(CYT4BFXX))
  intvec_alignment = 128
#endif

  ecc_init_width = 8
  cm4_stack_reserve = 8K
  stack_reserve = (cm4_stack_reserve + (ecc_init_width - 1)) & (~((ecc_init_width - 1))) // Ensure that stack size is an integer multiple of ECC init width (round up)
  cm7_0_code_flash_reserve = 864K // (4032K/2 - 288K)/2 = 864K
  cm7_0_code_flash_offset = 160K
  cm4_code_flash_offset = 160K
  FBL_code_flash_offset = 192K
  self_itcm_size             = 16K
  self_dtcm_size             = 16K
  
#if defined(CYT2B9XX)
#if defined(_DualBank_)
  ROM_DB_LS_END    = 0x100F7FFF
#else
  ROM_SB_LS_END    = 0x101EFFFF
#endif
  SRAM0_START      = 0x08000000
  SRAM0_RTSW_START = 0x0800A000
  SRAM0_END        = 0x0801FFFF
  SRAM1_START      = 0x08020000
  SRAM1_END        = 0x0803FFFF
  
#elif defined(CYT2BLXX)
#if defined(_DualBank_)
  ROM_DB_LS_END    = 0x101F7FFF
#else
  ROM_SB_LS_END    = 0x103EFFFF
#endif
  SRAM0_START      = 0x08000000
  SRAM0_RTSW_START = 0x0800A000
  SRAM0_END        = 0x0803FFFF
  SRAM1_START      = 0x08040000
  SRAM1_END        = 0x0807FFFF
  
#elif defined(CYT3BBXX)
#if defined(_DualBank_)
  ROM_DB_LS_END    = 0x101F7FFF
#else
  ROM_SB_LS_END    = 0x103EFFFF
#endif
  SRAM0_START      = 0x28000000
  SRAM0_RTSW_START = 0x2800A000
  SRAM0_END        = 0x2807FFFF
  SRAM1_START      = 0x28080000
  SRAM1_END        = 0x280BFFFF
  
#elif defined(CYT4BBXX)
#if defined(_DualBank_)
  ROM_DB_LS_END    = 0x101F7FFF
#else
  ROM_SB_LS_END    = 0x103EFFFF
#endif
  SRAM0_START      = 0x28000000
  SRAM0_RTSW_START = 0x2800A000
  SRAM0_END        = 0x2807FFFF
  SRAM1_START      = 0x28080000
  SRAM1_END        = 0x280BFFFF
  
#elif defined(CYT4BFXX)
#if defined(_DualBank_)
  ROM_DB_LS_END    = 0x103F7FFF
#else
  ROM_SB_LS_END    = 0x107EFFFF
#endif
  SRAM0_START      = 0x28000000
  SRAM0_RTSW_START = 0x2800A000
  SRAM0_END        = 0x2807FFFF
  SRAM1_START      = 0x28080000
  SRAM1_END        = 0x280BFFFF
  SRAM2_START      = 0x280C0000
  SRAM2_END        = 0x280FFFFF
  
#else  
#endif
}


MEMORY
{
/* ROM allocations. total size : 288KB. 0x1000_0000--0x1004_7FFF */
  CM0_ROM_Reserved       : ORIGIN = 0x10000000, LENGTH = 0x28000     /* 160KB      - ROM for CM0 Executable */
  FBL_ROM_Reserved       : ORIGIN = 0x10028000, LENGTH = 0x30000     /* 192KB      - ROM for FBL */
#if defined(_DualBank_)
  CODE_FLASH             : ORIGIN = 0x10058000, LENGTH = ROM_DB_LS_END - 0x10058000
#else
  CODE_FLASH             : ORIGIN = 0x10058000, LENGTH = ROM_SB_LS_END - 0x10058000
#endif

  /* RAM allocations. total size : 40KB. 0x2800_A000--0x2801_3FFF */
  CM0_RAM_Reserved       : ORIGIN = SRAM0_START,      LENGTH = 0xA000      /* 40KB       - RAM for CM0 executable */

  /* Total Reserved SRAM Size 40KB, Retention Area should be set from 0x28014000-- (Reserved 80 KB) */
#if (defined(CYT2B9XX) || defined(CYT2BLXX) || defined(CYT3BBXX) || defined(CYT4BBXX))
  STARTUP_COMMAND        : ORIGIN = SRAM0_RTSW_START, LENGTH = 0x10        /* 16 Bytes      - RAM to store Startup command by application to retain control in Bootloader for re-programming */
  BTL_APPL_COMMON_RAM    : ORIGIN = 0x0800A010, LENGTH = 0x40        /* 64 Bytes      - Shared RAM between application to store Programming conditions */
  RAM_FLSDRV             : ORIGIN = 0x0800A050, LENGTH = 0xFB0       /* 3K 944 Bytes  - RAM for Flash driver executable */
  SRAM                   : ORIGIN = 0x0800B000, LENGTH = SRAM1_END - 0x0800B000       
#elif defined(CYT4BFXX)
  SRAM                   : ORIGIN = SRAM0_RTSW_START, LENGTH = SRAM2_END - SRAM0_RTSW_START
#endif
  
  SELF_ITCM              : ORIGIN = 0x00000000, LENGTH = 0x00004000 // 16 KB
  SELF_DTCM              : ORIGIN = 0x20000000, LENGTH = 0x00004000 // 16 KB
  CM7_0_ITCM             : ORIGIN = 0xa0000000, LENGTH = 0x00004000 // 16 KB      
  CM7_0_DTCM             : ORIGIN = 0xa0010000, LENGTH = 0x00004000 // 16 KB
}

SECTIONS
{
    .START_CODE                          ALIGN(4)                : > CODE_FLASH
    .vector.EXCEPTION                    ALIGN(intvec_alignment) : > .
    .picbase                                                     : > .
   
    MAINSW_MODULE_INFO                               0x10058800  : > .
    MAINSW_CRC                                       0x10058810  : > .
    MAINSW_SIGNATURE                      PAD(512)   0x10058900  : > .
    .ASW_SECURITY_KEY                                0x10058B00  : > .
	 
	  .MEM_CHK_ID                                    0x10058C00    : > . /* RomTst */
    .MEM_CHK_CRC                                   0x10058C0C    : > . /* RomTst */
    .MEM_CHECK                                     0x10058C20    : > . /* RomTst */
	
    OEUK_PUBKEY					                            0x10059000	 : > . /*size : 0x104(260byte) 이나 0x200 확보함. */
    VERSION_BLK_HEADER                              0x10059200   : > . /* size 0x200 (app 0x100, fbl 0x100) */
     
    .text                                           0x10059400   : > . /* app 시작 주소 */
    .ghtws.text                                                  : > .    /* For Green Hills Compiler */
    .intercall                                                   : > .
    .interfunc                                                   : > .
    .fixaddr                                                     : > .
    .fixtype                                                     : > .
    .secinfo                                                     : > .
    .robase                                                      : > .
    .rodata                                                      : > .
    .syscall                                         ALIGN(8)    : > .
    .ROM.data        ROM(.data)                                  : > .
     
     HSM_DRIVER_SECTION_CODE							         : > .
     
    .LIB_CODE                                       ALIGN(4K)    : { *(".text.OS_API_CODE") } > .
    .EcucPartition_Main_CODE                        ALIGN(32)    : { *(".text.EcucPartition_Main_CODE")
                                                                     *(".text.EcucPartition_Sub_CODE")
                                                                     *(".text.DEFAULT_CODE")
                                                                     *(".text.DEFAULT_CALLOUT_CODE")
                                                                     *(".text.RTE_CODE")
																	 *(".text.OSEKNM_CODE")
                                                                     *(".text.DCM_CODE")
																	 *(".text.DEM_CODE")
                                                                     *(".text.CANTP_CODE")
                                                                     *(".text.DATALOG_CODE")
                                                                     *(".text.CRYPTO_76_HAEMODULE_SEC_CODE")
                                                                     *(".text.FOTA_CODE")}> .
                                                                     
    .EcucPartition_Main_CONST                       ALIGN(32)    : { *(".rodata.EcucPartition_Main_ROM_CONST")
                                                                     *(".rodata.DEFAULT_ROM_CONST*") 
                                                                     *(".rodata.CRYPTO_76_HAEMODULE_ROM_CONST_UNSPECIFIED") } > .
                                                                     
    HSM_DRIVER_SECTION_RODATA						ALIGN(8)     : > .                                                                 
                                                                     
    .vector.EXCEPTION_Core1              ALIGN(intvec_alignment) : > .
    
    .EcucPartition_Sub1_CODE                        ALIGN(32)    : { *(".text.EcucPartition_Sub1_CODE") } > .
    .EcucPartition_Sub1_CONST                       ALIGN(32)    : { *(".rodata.EcucPartition_Sub1_ROM_CONST") } > .


    .BTL_APPL_RS_DATA ALIGN(4) NOCLEAR                  		 : > STARTUP_COMMAND
    .APPIF_COMMON_RAM ALIGN(4) NOCLEAR                  		 : > BTL_APPL_COMMON_RAM
    //.DATALOG_RMBA_AREA ALIGN(8) CLEAR                            : { *(".bss.DATALOG_RMBA*") } > DATALOG_RMBA_AREA

	 //VERSION_BLK_TRAILER                             0x101f0000   : > .

    .sram_base_cm7_0                    ALIGN(ecc_init_width)    : > SRAM
    .stack     ALIGN(ecc_init_width)    PAD(stack_reserve)       : > .
    .OS_STACK_CORE0  ALIGN(8K)                            CLEAR   : { *(".bss.OS_RAM_STACK_CORE0_CLEARED_UNSPECIFIED") } > .
    .bss             ALIGN(8)                            CLEAR   : { *(".bss.EcucPartition_Main_RAM_VAR_CLEARED*")
                                                                     *(".bss.DEFAULT_RAM_VAR_CLEARED*")
                                                                     *(".bss.DEFAULT_SAFETY_VAR_CLEARED*")
                                                                     *(".bss.RTE_RAM_VAR_CLEARED*")
																	                                   *(".bss.NVM_RAM_VAR_CLEARED_ALIGNED_ADDR_UNSPECIFIED")
                                                                     *(".bss.DEFAULT_RAM_VAR_POWER_ON_CLEARED*")
								     *(".bss.NML_RAM_VAR_CLEARED*") /* Add Nml */
                                                                     *(".bss.CRYPTO_76_HAEMODULE_RAM_VAR_CLEARED_UNSPECIFIED")                                                                     
                                                                     *("HSM_DRIVER_SECTION_BSS")
                                                                     *("HSM_DRIVER_SECTION_CTX") } > .
                                                                     
    .DATALOG_RMBA_AREA  								ALIGN(4) : {*(".bss.DATALOG_RMBA_*")} > .                                                                 

    .CTRLRAM_RAM_VAR_NO_INIT_BEGIN 	ALIGN(64K)         NOCLEAR : > .
    .CTRLRAM_RAM_VAR_POWER_ON_CLEARED_8                NOCLEAR : > .
    .CTRLRAM_RAM_VAR_POWER_ON_CLEARED_16               NOCLEAR : > .
    .CTRLRAM_RAM_VAR_POWER_ON_CLEARED_32               NOCLEAR : > .
    .CTRLRAM_RAM_VAR_POWER_ON_CLEARED_UNSPECIFIED      NOCLEAR : > .
    .CTRLRAM_RAM_VAR_NO_INIT_END                       NOCLEAR : > .
    .CTRLRAM_RAM_VAR_NO_INIT_8                         NOCLEAR : > .
    .CTRLRAM_RAM_VAR_NO_INIT_16                        NOCLEAR : > .
    .CTRLRAM_RAM_VAR_NO_INIT_32                        NOCLEAR : > .
    .CTRLRAM_RAM_VAR_NO_INIT_UNSPECIFIED               NOCLEAR : > .                                                                 
    .bss_noclear                                       NOCLEAR   : { *(".bss.DEFAULT_RAM_VAR_NO_INIT*")
                                                                     *(".bss.DEFAULT_RAM_VAR_SAVED_ZONE*")
                                                                     *(".bss.NML_RAM_VAR_NO_INIT*") /* Add Nml */
                                                                     *(".bss.*NO_INIT*")
                                                                     *(".bss.*SAVED_ZONE") } > .
                                                                     
    .intvec_ram      ALIGN(intvec_alignment)        NOCLEAR      : > .
    .pidbase                                        ALIGN(16)    : > .
    .data                                           ALIGN(32)    : {  *(".data")
                                                                      *(".data.EcucPartition_Main_RAM_VAR_INIT*")
                                                                      *(".data.DEFAULT_RAM_VAR_INIT*")
                                                                      *(".data.CRYPTO_76_HAEMODULE_RAM_VAR_INIT_UNSPECIFIED*")
																	  *("HSM_DRIVER_SECTION_DATA")} > .
                                                                     
    .sram_base_cm7_1 ALIGN(ecc_init_width)                       : > .
    .stack_cm7_1     ALIGN(ecc_init_width)    PAD(stack_reserve) : > .
    .OS_STACK_CORE1  ALIGN(8K)                           CLEAR   : { *(".bss.OS_RAM_STACK_CORE1_CLEARED_UNSPECIFIED") } > .
    .bss_cm7_1       ALIGN(8)                            CLEAR   : { *(".bss.EcucPartition_Sub1_RAM_VAR_CLEARED*") } > .
    .data_cm7_1      ALIGN(32)                                   : { *(".data.EcucPartition_Sub1_RAM_VAR_INIT*") } > .

    OS_MAIN_BOS = addr(.stack);
    OS_MAIN_TOS = addr(.stack)+sizeof(.stack);
    OS_CORE1_BOS = addr(.stack_cm7_1);
    OS_CORE1_TOS = addr(.stack_cm7_1)+sizeof(.stack_cm7_1);

    .dtcm_base                                                   : > SELF_DTCM
    .itcm_base                                                   : > SELF_ITCM

    OS_MAIN_BOS = addr(.stack);
    OS_MAIN_TOS = addr(.stack)+sizeof(.stack);

    __ghs_romstart = MEMADDR(CODE_FLASH);
    __ghs_romend   = MEMENDADDR(CODE_FLASH);
    __ghs_ramstart = MEMADDR(SRAM);
    __ghs_ramend   = MEMENDADDR(SRAM);

    __ghsbegin_stack = ADDR(.stack);
    __ghsend_stack = ENDADDR(.stack);
    __ghsbegin_robase = ADDR(.robase);
  
    __ecc_init_sram_start_address = MEMADDR(SRAM);
    __ecc_init_sram_end_address = MEMENDADDR(SRAM);

    __ghsbegin_picbase     = 0;
    __ghsbegin_robase      = 0;
    __ghsbegin_pidbase     = 0;
    __ghs_rombootcodestart = MEMADDR(CODE_FLASH);
    __ghs_rombootcodeend   = MEMENDADDR(CODE_FLASH);
    __ghs_rambootcodestart = 0;
    __ghs_rambootcodeend   = 0;

#if (defined(CYT2B9XX) || defined(CYT2BLXX))
    __cm4_rom_start = 0x10000000 + cm4_code_flash_offset + FBL_code_flash_offset;
    __cm4_vector_base_linker_symbol = (__cm4_rom_start + intvec_alignment - 1) & ~(intvec_alignment - 1);
	
#elif (defined(CYT3BBXX) || defined(CYT4BBXX) || defined(CYT4BFXX))
    __cm7_0_rom_start = 0x10000000 + cm7_0_code_flash_offset + FBL_code_flash_offset; // +288 KB
	__cm7_0_vector_base_linker_symbol = (__cm7_0_rom_start + intvec_alignment - 1) & ~(intvec_alignment - 1);
	
#if (defined(CYT4BBXX) || defined(CYT4BFXX))
    __cm7_1_rom_start = __cm7_0_rom_start + cm7_0_code_flash_reserve;
	__cm7_1_vector_base_linker_symbol = (__cm7_1_rom_start + intvec_alignment - 1) & ~(intvec_alignment - 1);
#endif
#endif

    __ecc_init_sram_start_address = MEMADDR(SRAM);
    __ecc_init_sram_end_address   = MEMENDADDR(SRAM) - 1;
    __ecc_init_dtcm_start_address = MEMADDR(SELF_DTCM);
    __ecc_init_dtcm_end_address   = MEMENDADDR(SELF_DTCM) - 1;
    __ecc_init_itcm_start_address = MEMADDR(SELF_ITCM);
    __ecc_init_itcm_end_address   = MEMENDADDR(SELF_ITCM) - 1;
}
