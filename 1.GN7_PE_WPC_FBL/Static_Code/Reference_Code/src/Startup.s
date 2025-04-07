#define VAR_CHECK
#include "Os_PCfg.h"
#undef VAR_CHECK

CPUSS_IDENTITY                     .equ 0x40200000
CPUSS_CM4_OR_CM7_0_CTL             .equ 0x4020000c
CPUSS_CM7_1_CTL                    .equ 0x4020040c
CPUSS_CM7_2_CTL                    .equ 0x4020080c
CPUSS_CM7_3_CTL                    .equ 0x40200C0c
MASTER_ID_CM4_OR_CM7_0             .equ 14
MASTER_ID_CM7_1                    .equ 13
MASTER_ID_CM7_2                    .equ 7
MASTER_ID_CM7_3                    .equ 8

; WDT register addresses
WDT_CTL                            .equ 0x4026c000
WDT_LOWER_LIMIT                    .equ 0x4026c004
WDT_UPPER_LIMIT                    .equ 0x4026c008
WDT_WARN_LIMIT                     .equ 0x4026c00c
WDT_CONFIG                         .equ 0x4026c010
WDT_LOCK                           .equ 0x4026c040
WDT_SERVICE                        .equ 0x4026c044

; WDT register default values
WDT_LOWER_LIMIT_DEFAULT            .equ 0x00000000
WDT_UPPER_LIMIT_DEFAULT            .equ 0x10000000
WDT_WARN_LIMIT_DEFAULT             .equ 0x00000000
WDT_CONFIG_DEFAULT                 .equ 0x00000010

WDT_LOCK_CLR0                      .equ 0x1
WDT_LOCK_CLR1                      .equ 0x2
WDT_LOCK_SET01                     .equ 0x3

WDT_CTL_ENABLE                     .equ 0x80000001
WDT_CTL_DISABLE                    .equ 0x00000000

#if( defined(OS_AR_RELEASE_MINOR_VERSION) && OS_AR_RELEASE_MINOR_VERSION == 4)
VECTOR_TABLE                       .equ Os_ExceptionVectorTableCore0
#else
VECTOR_TABLE                       .equ Os_ExceptionVectorTable
#endif

.set     VTOR_REG, 0xE000ED08
.section ".START_CODE", "ax"
.globl   Reset_Handler

#if (OS_MULTICORE_FEATURE == 1)
#if (defined(OS_NUM_OF_CORES))
#if (OS_NUM_OF_CORES >= 4)
.globl   Reset_Handler_Core3
#endif

#if (OS_NUM_OF_CORES >= 3)
.globl   Reset_Handler_Core2
#endif
#endif

.globl   Reset_Handler_Core1
#endif
;*****************************************************************************
; Function             : Reset_Handler
; Service ID           : NA
; Description          : This function is reset handler for main-core
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : NA
; @return              : NA
; @pre                 : None
; @remarks             : NA
;*****************************************************************************
    .align 4
    .thumb2
    .type Reset_Handler, $function
    .size Reset_Handler, . - Reset_Handler
	
Reset_Handler:
  /* Allow write access to Vector Table Offset Register and ITCM/DTCM configuration register (CPUSS_CM7_X_CTL.PPB_LOCK[3] and CPUSS_CM7_X_CTL.PPB_LOCK[1:0]) */
    /* first check master identity (CM7_0 or CM7_1?) */
    LDR  r1, =CPUSS_IDENTITY          
    LDR  r0, [r1]
    LSR  r0, r0, #8
    AND  r0, r0, #0xf

    /* load address of corresponding CPUSS_CM7_X_CTL */
    #if (OS_MULTICORE_FEATURE == 1)
    #if (defined (OS_NUM_OF_CORES))
    #if (OS_NUM_OF_CORES >= 4)
    TEQ  r0, #MASTER_ID_CM7_3
    IT  EQ
    LDREQ  r1, =CPUSS_CM7_3_CTL
    #endif
    
    #if (OS_NUM_OF_CORES >= 3)
    TEQ  r0, #MASTER_ID_CM7_2
    IT EQ
    LDREQ  r1, =CPUSS_CM7_2_CTL
    #endif
    #endif /* ifdef OS_NUM_OF_CORES */
    
    TEQ  r0, #MASTER_ID_CM7_1
    IT EQ
    LDREQ  r1, =CPUSS_CM7_1_CTL
    #endif /* if (OS_MULTICORE_FEATURE == 1) */

    TEQ  r0, #MASTER_ID_CM4_OR_CM7_0
    IT EQ
    LDREQ  r1, =CPUSS_CM4_OR_CM7_0_CTL

    LDR  r0, [r1]
    BIC  r0, r0, #0xb
    STR  r0, [r1]
    DSB

    /* Initialize WDT registers to default value, which prevents unexpected reset by watchdog
     * When executed as below, WDT timeout period is set to 1 second.
     */
    ; Release a write lock for WDT registers
    ldr  r1, =WDT_LOCK
    ldr  r0, =WDT_LOCK_CLR0
    str  r0, [r1]
    ldr  r0, =WDT_LOCK_CLR1
    str  r0, [r1]
    
    ; Diable WDT counter
    ldr  r1, =WDT_CTL
    ldr  r0, =WDT_CTL_DISABLE
    str  r0, [r1]
    
    ; Set WDT registers to default values
    ldr  r1, =WDT_LOWER_LIMIT
    ldr  r0, =WDT_LOWER_LIMIT_DEFAULT
    str  r0, [r1]
    ldr  r1, =WDT_UPPER_LIMIT
    ldr  r0, =WDT_UPPER_LIMIT_DEFAULT
    str  r0, [r1]
    ldr  r1, =WDT_WARN_LIMIT
    ldr  r0, =WDT_WARN_LIMIT_DEFAULT
    str  r0, [r1]
    ldr  r1, =WDT_CONFIG
    ldr  r0, =WDT_CONFIG_DEFAULT
    str  r0, [r1]
    
    ; Enable WDT counter
    ldr  r1, =WDT_CTL
    ldr  r0, =WDT_CTL_ENABLE
    str  r0, [r1]

    ; Service WDT counter
    ldr  r1, =WDT_SERVICE
    mov  r0, #0x1
    str  r0, [r1]
    
    ; Enable write lock for WDT registers
    ldr  r1, =WDT_LOCK
    ldr  r0, =WDT_LOCK_SET01
    str  r0, [r1]

    ldr  r0, =VTOR_REG
    ldr  r1, =VECTOR_TABLE
    str  r1,[r0]
    DSB
    b    _start_T ; oh_well_lets_loop_forever is invoked in crt0.arm gh libstartup
   .endf Reset_Handler

#if (OS_MULTICORE_FEATURE == 1)
;*****************************************************************************
; Function             : Reset_Handler_Core1
; Service ID           : NA
; Description          : This function is reset handler for sub-core
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : NA
; @return              : NA
; @pre                 : None
; @remarks             : NA
;*****************************************************************************
    .align 4
    .thumb2
    .type Reset_Handler_Core1, $function
    .size Reset_Handler_Core1, . - Reset_Handler_Core1
	
Reset_Handler_Core1:
    ldr  r0, =VTOR_REG
    ldr  r1, =Os_ExceptionVectorTableCore1
    str  r1,[r0]
    bl   main
    .endf Reset_Handler_Core1

#if (defined (OS_NUM_OF_CORES))
#if (OS_NUM_OF_CORES >= 3)
;*****************************************************************************
; Function             : Reset_Handler_Core2
; Service ID           : NA
; Description          : This function is reset handler for sub-core
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : NA
; @return              : NA
; @pre                 : None
; @remarks             : NA
;*****************************************************************************
    .align 4
    .thumb2
    .type Reset_Handler_Core2, $function
    .size Reset_Handler_Core2, . - Reset_Handler_Core2

Reset_Handler_Core2:
    ldr  r0, =VTOR_REG
    ldr  r1, =Os_ExceptionVectorTableCore2
    str  r1,[r0]
    bl   main
    .endf Reset_Handler_Core2

#if (OS_NUM_OF_CORES >= 4)
;*****************************************************************************
; Function             : Reset_Handler_Core3
; Service ID           : NA
; Description          : This function is reset handler for sub-core
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : NA
; @return              : NA
; @pre                 : None
; @remarks             : NA
;*****************************************************************************
    .align 4
    .thumb2
    .type Reset_Handler_Core3, $function
    .size Reset_Handler_Core3, . - Reset_Handler_Core3

Reset_Handler_Core3:
    ldr  r0, =VTOR_REG
    ldr  r1, =Os_ExceptionVectorTableCore3
    str  r1,[r0]
    bl   main
    .endf Reset_Handler_Core3

#endif
#endif
#endif
#endif
