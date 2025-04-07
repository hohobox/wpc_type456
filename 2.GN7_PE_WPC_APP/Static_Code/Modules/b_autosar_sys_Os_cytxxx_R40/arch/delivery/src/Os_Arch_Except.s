;*****************************************************************************
;                                                                            ;
;  (C) 2021 HYUNDAI AUTOEVER Corp.                                           ;
;  Confidential Proprietary Information. Distribution Limited.               ;
;  This source code is permitted to be used only in projects contracted      ;
;  with Hyundai Autoever, and any other use is prohibited.                   ;
;  If you use it for other purposes or change the source code,               ;
;  you may take legal responsibility.                                        ;
;  In this case, There is no warranty and technical support.                 ;
;                                                                            ;
;  SRC-MODULE: Os_Arch_Interrupt.c                                           ;
;                                                                            ;
;  TARGET    : CYTxxx                                                        ;
;                                                                            ;
;  PRODUCT   : AUTOSAR OS                                                    ;
;                                                                            ;
;  PURPOSE   : Provision of interrupt specific functionality                 ;
;                                                                            ;
;  PLATFORM DEPENDANT [yes/no]: Yes                                          ;
;                                                                            ;
;  TO BE CHANGED BY USER [yes/no]: No                                        ;
;                                                                            ;
;*****************************************************************************

;*****************************************************************************
;                      Revision History
;*****************************************************************************
; Revision  Date           By            Description
;*****************************************************************************
; 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      
; 2.4.1     20-Jan-2022    YH.Cho        Redmine #33850
; 2.4.0     20-Aug-2021    YH.Cho        Redmine #31652
; 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391
; 2.0.1     10-AUG-2020    JH.Cho        Redmine #24903
; 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917
; 1.1.0     24-Feb-2020    MJ.Woo        Redmine #20861
; 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913
;*****************************************************************************

;*****************************************************************************
;                      Include Section
;*****************************************************************************
#define VAR_CHECK
#include "Os_PCfg.h"
#undef VAR_CHECK

    ; exported symbols from this file
    .globl Os_GetFpscr
    .globl Os_SetFpscr
    .globl Os_ISRHandler
    .globl Os_SVCallHandler
    ;.globl Os_PendSVHandler
    .globl Os_UnusedExceptionHandler
    .globl Os_FaultHandler
    .globl Os_RamExceptionHandler
    .globl Os_RomExceptionHandler
    .globl Os_NMIHandler
    ;.globl Os_HardFaultHandler
    ;.globl Os_MPUFaultHandler
    ;.globl Os_BusFaultHandler
    ;.globl Os_UsageHandler
    ;.globl Os_SysTickHandler
    .globl Os_DoContextSwitch
    .globl Os_GetMSP
    .globl Os_SetMSP
    .globl Os_GetPSP
    .globl Os_SetPSP
    .globl Os_IrqGetVectNumber
    .globl Os_GetCONTROL
    .globl Os_SetCONTROL
    .globl Os_GetPRIMASK
    .globl Os_GetFAULTMASK
    .globl Os_CallFuncKernelStack

    ; imported symbols into this file
    .globl Os_GucInKernel
    .globl Os_GulKernelSP
    .globl Os_CAT1_Least_Priority
    .globl Os_GaaISRTable
    .globl Os_GaaCat1ISRTable
    .globl Os_GpStaticTask
    .globl Os_GucSchedReq
    .globl Os_CAT1_ISR_Count
    .globl Os_CAT2_ISR_Count
    .globl Os_GaaSyscallTable
    .globl Os_GucNestingCAT1ISR
    .globl Os_GucNestingCAT2ISR
    .globl Os_GaaSyscallTable
    .globl OS_COUNTER_ISRID
    .globl Os_CAT2ISRHandler
    .globl Os_TrapHandler
    .globl Os_UnusedHandler
    .globl Os_CallBackNMInterrupt
    .globl Os_Dispatch

    .set CPUSS_CMx_INTn_STATUS         0x40200100   ; (x: 4, 7_0)
    .set MASK_SYSTEM_INT_VALID         0x80000000
    .set MASK_SYSTEM_INT_IDX           0x000003FF
    .set OS_IPR_LSB                    0x00000005
    .set EXCEPTION_NUM_SYSTICK         0xF
    .set CORE_ID_MASK                  0x0100

;*****************************************************************************
;                      Functions
;*****************************************************************************

;*****************************************************************************
; Function             : Os_ISRHandler
; Service ID           : NA
; Description          : This function is a wrapper function for CAT1/CAT2
;                        interrupt handler
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     :
;                        Os_GaaCat1ISRTable, Os_GaaISRTable,
;                        Os_CAT1_Least_Priority, Os_GucInKernel,
;                        Os_GpStaticTask, OS_COUNTER_ISRID
;
;                        Function(s) invoked    :
;                        None
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_ISRHandler, $function

Os_ISRHandler:
    ; Disable Interrupt
    cpsid   f
    ;--------------------------------------------------------
    ; already a stack frame has been made (basic frame size: 0x20)
    ; {r0, r1, r2, r3, r12, lr(r14), ReturnAddress, xPSR} where msp/psp points to r0
    ;
    ; |         | <- old stack frame (msp/psp)
    ; |  xPSR   |
    ; |  return |
    ; |  lr     |
    ; |  r12    |
    ; |  r3     |
    ; |  r2     |
    ; |  r1     |
    ; |  r0     | <- new stack frame (msp/psp)
    ;--------------------------------------------------------
    tst        lr, #4                   ; context on PSP? (lr & 4)
    beq     _OSISR_SAVE_MSP_CTXT

_OSISR_SAVE_PSP_CTXT:
    ;--------------------------------------------------------
    ; save preempted task's context into psp stack frame
    ; save other registers
    ; {r4-r11, r12, EXEC_RETURN} where psp points to r4
    ;
    ; |         |
    ; |  xPSR   |
    ; |  return |
    ; |  lr     |
    ; |  r12    |
    ; |  r3     |
    ; |  r2     |
    ; |  r1     |
    ; |  r0     | <- old stack frame (psp), 'current' lr is 0xFFFFFFFD(EXEC_RETURN)
    ; |  lr     |
    ; |  r12    |
    ; |  r11    |
    ; |  r10    |
    ; |  r9     |
    ; |  r8     |
    ; |  r7     |
    ; |  r6     |
    ; |  r5     |
    ; |  r4     | <- new stack frame (psp)
    ; #if (OS_FPU_SUPPORT == STD_ON)
    ; |  dummy  |
    ; |  FPSCR  |
    ; |  d15    |
    ; |  d14    |
    ; |  d13    |
    ; |  d12    |
    ; |  d11    |
    ; |  d10    |
    ; |  d9     |
    ; |  d8     |
    ; |  d7     |
    ; |  d6     |
    ; |  d5     |
    ; |  d4     |
    ; |  d3     |
    ; |  d2     |
    ; |  d1     |
    ; |  d0     | <- new stack frame (psp)
    ; #endif /* if (OS_FPU_SUPPORT == STD_ON) */
    ;--------------------------------------------------------
    mrs     r0,  psp
    mov     r12, r0
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmfd   r0!, {r4-r11, r12, lr}      ; save {EXEC_RETURN, psp, r11-r4} psp->r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     r0, r0, #4                  ; skip dummy
    sub     r0, r0, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [r0]                    ; Push FPSCR to stack
    vstmfd  r0!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    msr     psp, r0

    ;--------------------------------------------------------
    ; save preempted task's context into structure
    ;--------------------------------------------------------
    ldr     r2, _PtrGucNestingCAT1ISR   ; check Nesting CAT1
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r2, r2, r10
    .endif
    pop {r10}
    ldrb    r2, [r2]
    cmp     r2, #0
    bne     _OSISR_VALIDATE_AND_DECIDE_CATEGORY

    ldr     r2, _PtrGpOsStaticTask
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r2, r2, r3
    .endif
    pop {r10, r3}
    ldr     r2, [r2]
    ldr     r2, [r2]
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vstmea  r2!, {d0-d15}               ; save {d0-d15}
    str     r1, [r2]                    ; save FPSCR
    add     r2, r2, #4
    add     r2, r2, #4                  ; skip dummy
    .endif    
    stmea   r2!, {r4-r11, r12, lr}      ; save {r4-r11, psp, EXEC_RETURN} psp points to r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r0, r0, #176
    .else
    add     r0, r0, #40
    .endif
    ldmfd   r0, {r4-r11}                ; load stackframe into registers
    stmea   r2, {r4-r11}                ; save {r0, r1, r2, r3, r12, lr(r14), pc, xpsr}

    mov     r4, #0                      ; check if interrupt is occurs on interrupt entry
    b       _OSISR_CHECK_SWITCH_KSTACK

_OSISR_SAVE_MSP_CTXT:
    ;--------------------------------------------------------
    ; save other registers of handler mode
    ; {EXEC_RETURN, msp, r11-r4} msp->r4
    ;
    ; |         |
    ; |  xPSR   |
    ; |  return |
    ; |  lr     |
    ; |  r12    |
    ; |  r3     |
    ; |  r2     |
    ; |  r1     |
    ; |  r0     | <- old stack frame (msp), 'current' lr is 0xFFFFFFF1(EXEC_RETURN)
    ; |  lr     |
    ; |  sp     |
    ; |  r11    |
    ; |  r10    |
    ; |  r9     |
    ; |  r8     |
    ; |  r7     |
    ; |  r6     |
    ; |  r5     |
    ; |  r4     | <- new stack frame (msp)
    ; #if (OS_FPU_SUPPORT == STD_ON)
    ; |  dummy  |
    ; |  FPSCR  |
    ; |  d15    |
    ; |  d14    |
    ; |  d13    |
    ; |  d12    |
    ; |  d11    |
    ; |  d10    |
    ; |  d9     |
    ; |  d8     |
    ; |  d7     |
    ; |  d6     |
    ; |  d5     |
    ; |  d4     |
    ; |  d3     |
    ; |  d2     |
    ; |  d1     |
    ; |  d0     | <- new stack frame (psp)
    ; #endif /* if (OS_FPU_SUPPORT == STD_ON) */
    ;--------------------------------------------------------
    add     r0, sp, #24                      ; lr of old stack frame(return address)
    mov     r12, sp
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmfd   sp!, {r4-r11, r12, lr}      ; decending store lr(r14),sp,r11,...,r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     sp, sp, #4                  ; skip dummy
    sub     sp, sp, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [sp]                    ; Push FPSCR to stack
    vstmfd  sp!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    ;--------------------------------------------------------
    ; check if cat1 is nested
    ;--------------------------------------------------------
    ldr     r2, _PtrGucNestingCAT1ISR   ; check Nesting CAT1
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r2, r2, r10
    .endif
    pop {r10}
    ldrb    r2, [r2]
    cmp     r2, #0
    bne     _OSISR_VALIDATE_AND_DECIDE_CATEGORY	
    ;--------------------------------------------------------
    ; check if interrupt is occurs on interrupt entry
    ;--------------------------------------------------------
    mov     r4, #0
    ldr     r0, [r0]
    mov     r1, #Os_ISRHandler
    cmp     r1, r0
    beq     _OSISR_INTERRUPT_ON_ENTRY

    ;--------------------------------------------------------
    ; save preempted task's context into structure
    ;--------------------------------------------------------
    mov     r1, r4                      ; save r4
    mov     r0, sp
    ldr     r2, _PtrGpOsStaticTask
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r2, r2, r3
    .endif
    pop {r10, r3}
    ldr     r2, [r2]
    ldr     r2, [r2]
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r3}
    vstmea  r2!, {d0-d15}               ; save {d0-d15}
    vmrs    r3, fpscr                   ; Get FPSCR
    str     r3, [r2]                    ; save FPSCR
    add     r2, r2, #4
    add     r2, r2, #4                  ; skip dummy
    pop     {r3}
    .endif
    stmea   r2!, {r4-r11, r12, lr}      ; save {r4-r11, psp, EXEC_RETURN} psp points to r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r0, r0, #176
    .else
    add     r0, r0, #40
    .endif
    ldmfd   r0, {r4-r11}                ; load stackframe into registers
    stmea   r2, {r4-r11}                ; save {r0, r1, r2, r3, r12, lr(r14), pc, xpsr}

    mov     r4, r1                      ; restore r4
    b       _OSISR_CHECK_SWITCH_KSTACK

_OSISR_INTERRUPT_ON_ENTRY:
    ;--------------------------------------------------------
    ; interrupt occurs on entry
    ;--------------------------------------------------------
    mov     r4, #1
	
    ldr     r0, _PtrOsGulPSP
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r0, r0, r3
    .endif
    pop {r10, r3}
    mrs     r1, psp
    str     r1, [r0]

    ldr     r0, _PtrOsGulMSP
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r0, r0, r3
    .endif
    pop {r10, r3}
    mrs     r1, msp
    str     r1, [r0]

_OSISR_CHECK_SWITCH_KSTACK:
    ; Switch to Kernel Stack or not
    ; 1) Task, <occurs ISR> => no Switch
    ;    - Os_GucOsInKernel == 0, Os_GucOsInIsrStack == 0
    ; 2) CAT2 ISR, <occurs higher priority ISR> => Switch
    ;    - Os_GucOsInKernel == 0, Os_GucOsInIsrStack > 0
    ; 3) CAT1 ISR, <occurs higher priority CAT1 ISR> => no Switch
    ; 4) Interrupt is preempted by higher interrupt between Os_ISRHandler and "cpsid f" => no Switch

    ; Os_GucNestingCAT2ISR[0] == 0, skip to change to kernel stack
    ldr     r0, _PtrGucNestingCAT2ISR   ; CAT2 ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r0, r0,r10
    .endif
    pop {r10}
    ldrb    r0, [r0]
    cmp     r0, #0
    beq     _OSISR_VALIDATE_AND_DECIDE_CATEGORY

    ; Change to kernel stack from CAT2 ISR stack
    ldr     r0, _PtrGulInKernelSP
    push {r10,r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10,[r10]
    ands    r10,r10, CORE_ID_MASK
    lsr     r10,r10, 8          ; logical shift right by 8-bit
    mov     r3, #4
    mul     r3, r3, r10
    add     r0, r0, r3
    .endif
    pop {r10,r3}
    ldr     r0, [r0]
    str     sp, [r0, #-4]               ; store the CAT2 ISR's current sp
    sub     r0, r0, #4
    mov     sp, r0

    ;------------------------------------------------
    ; thread mode stack frame & context save are completed
    ; handler mode stack frame are completed
    ;------------------------------------------------
_OSISR_VALIDATE_AND_DECIDE_CATEGORY:
    mrs     r0, ipsr                    ; get isr vector number

    cmp     r0, EXCEPTION_NUM_SYSTICK   ; if (r0 == EXCEPTION_NUM_SYSTICK)
    beq     _OSISR_RUN_COUNTER          ;   goto _OSISR_RUN_COUNTER

    ldr     r1, _PtrGulIntPrioReg
    add     r1, r1, r0
    ldrb    r1, [r1]                    ; nvic_ipr = 0xE000E400 each with 8-bit(1-byte)
    lsr     r1, r1, OS_IPR_LSB          ; logical shift right by 5-bit

    ; r1 = priority
    ; if (CPUSS_CMx_INTn_STATUS[priority].SYSTEM_INT_VALID == TRUE)
    ;   IsrId = Os_GaaISRTable[CPUSS_CMx_INTn_STATUS[priority].SYSTEM_INT_IDX]
    ; else
    ;   goto _OSISR_RESTORE_CTXT
    lsl     r3, r1, #2                  ; r3 = priority * 4 (4byte address offset)
    ldr     r2, =CPUSS_CMx_INTn_STATUS  ; r2 = CPUSS_CMx_INTn_STATUS
    push {r10, r9}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r9, #0x400
    mul     r10, r10, r9
    add     r2, r2, r10
    .endif
    pop {r10, r9}
    ldr     r0, [r2, r3]                ; r0 = *(CPUSS_CMx_INTn_STATUS + (priority * 4))
    tst     r0, MASK_SYSTEM_INT_VALID   ; if ((r0 & MASK_SYSTEM_INT_VALID) == 0)
    beq     _OSISR_HANDLE_INVALID_ISR
    mov     r2, MASK_SYSTEM_INT_IDX     ; r2 = MASK_SYSTEM_INT_IDX
    ands    r3, r0, r2                  ; SYSTEM_INT_IDX(r3) = r0 & MASK_OF_SYSTEM_INT_IDX
    ldr     r2, _PtrGaaOsIsrTable       ; get value in the _PtrOsIsrTable -> address
    lsl     r3, r3, #1                  ; r3 = SYSTEM_INT_IDX * 2 (2byte address offset)
    ldrh    r0, [r2, r3]                ; get 2-byte value(IsrId) from Os_GaaISRTable

    ldr     r2, _PtrGusOsCat1Priority   ; get value in the _PtrOsCat1Priority -> address
    ldrh    r2, [r2]                    ; load with 16-bit, currently the value is 0
    cmp     r1, r2
    bgt     _OSISR_RUN_CAT2             ; if r1 > r2, then this interrupt is CAT2 interrupt

_OSISR_RUN_CAT1:
    ; Get CAT1 ISR's function pointer
    ldr     r1, _PtrFuncOsCat1IsrTable
    lsl     r0, r0, #2                  ; IsrId x 4 (r0 already setup above)
    ldr     r2, [r1, r0]                ; get handler pointer from Os_GaaCat1ISRTable

    ; Os_GucInKernel[0]++
    ldr     r1, _PtrGucOsInKernel       ; _PtrGucOsInKernel[0]=C0, _PtrGucOsInKernel[1]=C1
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop {r10}
    ldrb    r0, [r1]
    add     r0, r0, #1
    strb    r0, [r1]

    ; GucNestingCAT1ISR[0]++
    ldr     r1, _PtrGucNestingCAT1ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop {r10}
    ldrb    r0, [r1]
    add     r0, r0, #1
    strb    r0, [r1]

    ; call Cat1 Handler,  ("returns" to exit func)
    push    {lr, r10}                   ; r10 is just for preventing compile warning
    mov     lr, r2
    ; Enable Interrupt
    cpsie   f
    blx     lr
    ; Disable Interrupt
    cpsid   f
    pop     {lr, r10}

    ; Os_GucNestingCAT1ISR[0]--
    ldr     r1, _PtrGucNestingCAT1ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop {r10}
    ldrb    r0, [r1]
    add     r0, r0, #-1
    strb    r0, [r1]

    ; Os_GucInKernel[0]--
    ldr     r1, _PtrGucOsInKernel       ; _PtrGucOsInKernel[0]=C0, _PtrGucOsInKernel[1]=C1
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop {r10}
    ldrb    r0, [r1]
    add     r0, r0, #-1
    strb    r0, [r1]

    push    {lr, r10}                   ; r10 is just for preventing compile warning
    bl      Os_EnableBudgetTimer
    pop     {lr, r10}

    b      _OSISR_RESTORE_CTXT

_OSISR_RUN_COUNTER:
    ldr     r1, _PtrOsCounterIsrId      ; r1 = &OS_COUNTER_ISRID
    .if (OS_MULTICORE_FEATURE == 1)
    push    {r3, r10}
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r1, r1, r3

    ldr     r0, [r1]                    ; r0 = *r1

    pop     {r3, r10}
    .else
    ldr     r0, [r1]                    ; r0 = *r1
    .endif


_OSISR_RUN_CAT2:
    cmp     r4, #0                      ; Nested?
    beq    _OSISR_RUN_CAT2_HANDLER

_OSISR_RUN_CAT2_NESTED:
    ; Update Os_GpStaticTask -> SP when interrupt occurs on entry
    ldr     r2, _PtrGpOsStaticTask ; GpOsStaticTask
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r2, r2, r3
    .endif
    pop {r10, r3}
    ldr     r2, [r2] ;GpOsStaticTask[CoreId]
    ldr     r2, [r2] ;GpOsStaticTask[CoreId]->pContext

    ldr     r11, _PtrGucNestingCAT2ISR   ; CAT2 ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r11, r11, r10
    .endif
    pop {r10}
    ldrb    r11, [r11]
    cmp     r11, #0
    bne     _OSISR_SAVE_MSP_ON_GPSTATICTASK

_OSISR_SAVE_PSP_ON_GPSTATICTASK:      ; Os_GucNestingCAT2ISR == 0
    mrs     r12, psp
    b       _OSISR_SAVE_STACK_UPDATE

_OSISR_SAVE_MSP_ON_GPSTATICTASK:      ; Os_GucNestingCAT2ISR != 0
    ldr     r11, _PtrOsGulMSP
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r11, r11, r3
    .endif
    pop {r10, r3}
    ldr     r11, [r11]
    mov     r12, r11
    b       _OSISR_SAVE_STACK_UPDATE

_OSISR_SAVE_STACK_UPDATE:
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r12, r12, #208
    add     r2, r2,  #168 ; sp(dst)
    str     r12, [r2] 
    .else
    add     r12, r12, #72
    add     r2, r2,  #32 ; sp(dst)
    str     r12, [r2] 
    .endif

_OSISR_RUN_CAT2_HANDLER:
    mov     r1, r4                      ; interrupt occurs on entry (before 'cpsid f')?
    push    {lr, r10}                   ; r10 is just for preventing compile warning
    bl      Os_CAT2ISRHandler           ; with CAT2's ID r0 (already setup above)
    pop     {lr, r10}
    ;------------------------------------------------
    
    ;clear  _PtrOsSchedReq
    ;Os_CAT2ISRHandler return value (r0) is used instead of OsSchedReq 
    ldr     r1, _PtrOsSchedReq
    push    {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]                ; Get_CoreID
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop    {r10}
    mov     r2, #0
    strb    r2, [r1]

_OSISR_CLEAR_NVIC_PENDING:
    ldr     r5, =#0x000000ff
    ldr     r6, _PtrGulIntClearPendReg
    str     r5, [r6]

    ; if context-switch in CAT2 ISR is necessary, do dispatch
    ; else goto _OS_RESTORE_RETURN
    cmp     r0, #0                      ; r0 - 0
    beq     _OSISR_RESTORE_CTXT
    ldr     lr, _PtrFuncOsDispatch
    bx      lr                          ; no return

_OSISR_HANDLE_INVALID_ISR:
    cmp     r4, #0                      ; Nested on entry?
    bne     _OSISR_RESTORE_CTXT

    ldr     r1, _PtrGucNestingCAT1ISR   ; CAT1 ISR
    ldr     r2, _PtrGucNestingCAT2ISR   ; CAT2 ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    add     r2, r2, r10
    .endif
    pop {r10}
    ldrb    r1, [r1]
    cmp     r1, #0                      ; CAT1 Nested?
    bne     _OSISR_RESTORE_CTXT
    ldrb    r2, [r2]
    cmp     r2, #0                      ; CAT2 Nested?
    bne     _OSISR_RESTORE_CTXT

    ldr     r1, _PtrGpOsLinkTask        ; address of GpOsLinkTask
    ldr     r2, _PtrGpOsStaticTask      ; address of GpOsStaticTask
    push {r10, r3}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r10
    add     r1, r1, r3
    add     r2, r2, r3
    .endif
    pop {r10, r3}
    ldr     r1, [r1]                    ; GpOsLinkTask
    ldr     r2, [r2]                    ; GpOsStaticTask
    ldr     r2, [r2, #8]                ; GpOsStaticTask -> pLinkTask
    cmp     r1, r2                      ; GpOsStaticTask == GpOsLinkTask ?
    beq     _OSISR_RESTORE_CTXT
    ldr     lr, _PtrFuncOsDispatch      ; GpOsStaticTask != GpOsLinkTask, Os_Dispatch()
    bx      lr                          ; no return

_OSISR_RESTORE_CTXT:
    ; further optimization issues - late-arriving, tail-chaining
    tst        lr, #4                   ; context on PSP? (lr & 4)
    beq     _OSISR_RESTORE_MSP_CTXT

    ; pop-up manually saved thread mode stack frame
    mrs     r0,  psp
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  r0!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [r0]                    ; reload FPSCR
    vmsr    fpscr, r1
    add     r0, r0, #4
    add     r0, r0, #4                  ; skip dummy
    .endif
    ldmfd   r0!, {r4-r11, r12, lr}      ; reload SP->r12, discard it

    msr     psp, r0
    dsb
    isb
    bx      lr

_OSISR_RESTORE_MSP_CTXT:
    ; Os_GucNestingCAT1ISR[0] != 0, restore from kernel stack
    ldr     r0, _PtrGucNestingCAT1ISR   ; CAT1 ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r0, r0, r10
    .endif
    pop {r10}
    ldrb    r0, [r0]
    cmp     r0, #0
    bne     _OSISR_RESTORE_FROM_CURRENT_STACK

    ; Os_GucNestingCAT2ISR[0] == 0, restore from kernel stack
    ldr     r0, _PtrGucNestingCAT2ISR   ; CAT2 ISR
    push {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r0, r0, r10
    .endif
    pop {r10}
    ldrb    r0, [r0]
    cmp     r0, #0
    beq     _OSISR_RESTORE_FROM_CURRENT_STACK

    ; Change Stack to the original ISR'S
    ldr     r0, [sp]
    mov     sp, r0

_OSISR_RESTORE_FROM_CURRENT_STACK:
    ; pop-up manually saveed handler mode stack frame
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  sp!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [sp]                    ; reload FPSCR
    vmsr    fpscr, r1                   ; reload FPSCR
    add     sp, sp, #4
    add     sp, sp, #4                  ; skip dummy
    .endif
    ldmfd   sp!, {r4-r11, r12, lr}      ; reload SP->r12, and it will be discarded when exception returns

    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_ISRHandler                 ; end of Os_ISRHandler

; Label Address

.align 4

_PtrGaaOsIsrTable:         .word   Os_GaaISRTable ; 16-bit array
_PtrGucOsInKernel:         .word   Os_GucInKernel
_PtrFuncOsDispatch:        .word   Os_Dispatch
_PtrGulIntPrioReg:         .word   (0xE000E400 - 0x10) ; Interrupt Priority Registers
_PtrGulIntClearPendReg:    .word   (0xE000E280) ; Interrupt Clear-Pending Registers
_PtrGulInKernelSP:         .word   Os_GulKernelSP
_PtrGulInKernelSPBase:     .word   Os_GulKernelSPBase

_PtrGusOsCat1Priority:     .word   Os_CAT1_Least_Priority
_PtrFuncOsCat1IsrTable:    .word   Os_GaaCat1ISRTable
_PtrGucNestingCAT1ISR:     .word   Os_GucNestingCAT1ISR

_PtrFuncOsCat2IsrHandler:  .word   Os_CAT2ISRHandler
_PtrGucNestingCAT2ISR:     .word   Os_GucNestingCAT2ISR
_PtrOsCounterIsrId:        .word   OS_COUNTER_ISRID
_PtrOsGulPSP:              .word   Os_GulPSP
_PtrOsGulMSP:              .word   Os_GulMSP

;*****************************************************************************
; Function             : Os_SVCallHandler
; Service ID           : NA
; Description          : This function is called to handle system call
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : r0 - parameter1
;                        r1 - parameter2
;                        r2 - parameter3
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     :
;                        Os_GulKernelSP, Os_GpStaticTask
;                        Os_GucInKernel, Os_GucSchedReq, Os_GaaSyscallTable
;
;                        Function(s) invoked    :
;                        Os_KernXXX (OS System Call API)
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_SVCallHandler, $function

Os_SVCallHandler:

    ; Disable Interrupt
    cpsid   f

    ;--------------------------------------------------------
    ; already a stack frame has been made
    ; {r0, r1, r2, r3, r12, lr(r14), pc, xpsr} where psp -> r0
    ;--------------------------------------------------------

    ; context on PSP? (lr & 4)
    tst     lr, #4
    beq     _OSSVC_SAVE_MSP_CTXT

    ; save psp to r3
    mrs     r3,  psp
    ;--------------------------------------------------------
    ; save preempted task's context into stack frame
    ; save other registers
    ; {EXEC_RETURN, sp, r11-r4} psp->r4
    ;--------------------------------------------------------
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r2, r3}
    .else
    push    {r3}
    .endif
    mov     r12, r3
    stmfd   r3!, {r4-r11, r12, lr}      ; save {EXEC_RETURN, psp, r11-r4} psp->r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     r3, r3, #4                  ; skip dummy
    sub     r3, r3, #4
    vmrs    r2, fpscr                   ; Get FPSCR
    str     r2, [r3]                    ; Push FPSCR to stack
    vstmfd  r3!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    msr     psp, r3
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    pop     {r2, r3}
    .else
    pop     {r3}
    .endif

    b    _OSSVC_CHECK_SYSCALL

_OSSVC_SAVE_MSP_CTXT:
    ; save msp to r3
    mrs     r3,  msp
    ;--------------------------------------------------------
    ; save context of handler mode (ISR's)
    ; save other registers
    ; {EXEC_RETURN, sp, r11-r4} msp->r4
    ;--------------------------------------------------------
    mov     r12, sp
    stmfd   sp!, {r4-r11, r12, lr}
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r1}
    sub     sp, sp, #4                  ; skip dummy
    sub     sp, sp, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [sp]                    ; Push FPSCR to stack    
    vstmfd  sp!, {d0-d15}               ; Store VFP double-precision registers
    pop    {r1}
    .endif

    ;------------------------------------------------
    ; thread mode stack frame & context save are completed
    ; handler mode stack frame are completed
    ;------------------------------------------------

_OSSVC_CHECK_SYSCALL:
    ; get svc number to r3
    add     r3, r3, #0x18
    ldr     r3, [r3]
    mvn     r12, #0x01
    add     r3, r3, r12
    ldrb    r3, [r3]

    ; Check whether the Service ID is invalid
    cmp     r3, #68                     ;  OS_N_SYSCALL = 68
    bge     _OSSVC_RESTORE_RETURN

    ; Os_GucInKernel[OS_CORE_ID]++
    push    {r3,r10}
    ldr     r3, _PtrGucOsInKernel
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r3, r3, r10
    .endif
    ldrb    r12, [r3]
    add     r12, r12, #1
    strb    r12, [r3]
    pop     {r3,r10}

    ; Call System call API
    ; Parameters           : r0 - parameter1
    ;                        r1 - parameter2
    ;                        r2 - parameter3
    ldr     r12, _PtrOsSyscallTable
    lsl     r3, r3, #2                  ; Service ID x 4
    add     r12, r12, r3

    push    {lr, r10}                   ; save called mode, r10 is just for preventing compile warning
    ldr     lr, [r12]
    blx     lr                          ; (lr address)(r0,r1,r2) => r0 return
    pop     {lr, r10}                   ; restore called mode

    ; Os_GucInKernel[OS_CORE_ID]--
    ldr     r1, _PtrGucOsInKernel
    push    {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]                ; Get_CoreID
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop    {r10}
    ldrb    r2, [r1]
    add     r2, r2, #-1
    strb    r2, [r1]
    ;------------------------------------------------
    ; System call is finished at this time.
    ; If it is necessary to dispatch new Task, do it !!!
    ldr     r1, _PtrOsSchedReq
    push    {r10}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]                ; Get_CoreID
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    add     r1, r1, r10
    .endif
    pop    {r10}
    ldrb    r2, [r1]
    cmp     r2, #0
    beq     _OSSVC_RESTORE_RETURN      ; Os_GucSchedReq[OS_CORE_ID] is zero, do not dispatch
    cmp     r2, #4
    bne     _OSSVC_DISPATCH_SYSCALL

    ; Assume Only Task Can Reach This Code !!!
    ; Save preempted task's context (for the case of ActivateTask,...)
    ; Stack information -> Task Context block
    push    {r0}                        ; save return value
    ldr     r2, _PtrGpOsStaticTask
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r0, _PtrCoreid
    ldr     r0, [r0]                ; Get_CoreID
    ands    r0, r0, CORE_ID_MASK
    lsr     r0, r0, 8          ; logical shift right by 8-bit
    mov     r3, #0x4
    mul     r3, r3, r0
    add     r2, r2, r3
    .endif
    ldr     r2, [r2]
    ldr     r2, [r2]
    mrs     r0, psp                     ; task's context
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r1}
    vldmfd  r0!, {d0-d15}
    ldr     r1, [r0]                    ; load FPSCR
    vmsr    fpscr, r1
    add     r0, r0, #4
    add     r0, r0, #4                  ; skip dummy
    vstmea  r2!, {d0-d15}               ; save {d0-d15}
    str     r1, [r2]                    ; save FPSCR
    add     r2, r2, #4
    add     r2, r2, #4                  ; skip dummy
    pop     {r1}
    .endif
    ldmfd   r0!, {r4-r11, r12, lr}
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmea   r2!, {r4-r11, r12, lr}      ; save r4-r11, psp, lr
    ldmfd   r0, {r4-r11}                ; load stacframe into registers
    pop     {r4}                        ; restore return value r0 -> r4
    stmea   r2, {r4-r11}                ; save {r0, r1, r2, r3, r12, lr(r14), pc, xpsr}

_OSSVC_DISPATCH_SYSCALL:
    mov     r2, #0                      ; initialize Os_GucScheReq
    strb    r2, [r1]
    ldr     lr, _PtrFuncOsDispatch
    bx      lr                          ; no return

_OSSVC_RESTORE_RETURN:
    ; further optimization issues - late-arriving, tail-chaining
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OSSVC_RESTORE_FROM_CURRENT_STACK

    ; pop-up manually saved thread mode stack frame
    mrs     r1,  psp
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r2}
    vldmfd  r1!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r2, [r1]                    ; reload FPSCR
    vmsr    fpscr, r2                   ; reload FPSCR
    add     r1, r1, #4
    add     r1, r1, #4                  ; skip dummy
    pop     {r2}
    .endif
    ldmfd   r1!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    msr     psp, r1
    str     r0,  [r1]                   ; SVC return value r0
    dsb
    isb
    bx      lr

_OSSVC_RESTORE_FROM_CURRENT_STACK:
    ; pop-up manually saved handler mode stack frame
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    push    {r1}
    vldmfd  sp!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [sp]                    ; reload FPSCR
    vmsr    fpscr, r1                   ; reload FPSCR
    add     sp, sp, #4
    add     sp, sp, #4                  ; skip dummy
    pop     {r1}
    .endif
    ldmfd   sp!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    str     r0, [sp]                    ; SVC return value r0
    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_SVCallHandler


; Label Address

.align 4

_PtrGpOsStaticTask:  .word  Os_GpStaticTask
_PtrGpOsLinkTask:    .word  Os_GpLinkTask
_PtrOsSchedReq:      .word  Os_GucSchedReq
_PtrOsSyscallTable:  .word  Os_GaaSyscallTable
_PtrCoreid:          .word  (0x40200000)

;*****************************************************************************
; Function             : Os_DoContextSwitch
; Service ID           : NA
; Description          : This OS HAL shall provide an API that is called to dispatch
;                        a new task
;                        1) Restore saved context
;                        2) Return from exception
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : LpContext - Pointer of saved context(Tdd_Os_ContextSwitch)
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     : None
;
;
;                        Function(s) invoked    : None
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_DoContextSwitch, $function

Os_DoContextSwitch:
    ; restore kernel stack pointer
    ldr     r1, _PtrGulInKernelSPBase
    push {r10,r9}
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r9, #4
    mul     r9, r9, r10
    add     r1, r1, r9
    .endif
    pop {r10,r9}
    ldr     r1, [r1]
    msr     msp, r1

    ;--------------------------------------------------------
    ; make a stack frame
    ; {r0, r1, r2, r3, r12, lr(r14), pc, xpsr} where sp -> r0
    ;--------------------------------------------------------
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r9, r0, #176               ; ulR0 address (16*8 + 4*1 + 4*1 + 4*10 = 176)
    .else
    add     r9, r0, #40                 ; ulR0 address
    .endif
    ldmfd   r9, {r1-r8}                 ; r0-r3, r12, lr, pc, psr
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    ldr     r9, [r0, #168]               ; sp(dst)
    ldr     lr, [r0, #172]               ; EXC_RETURN
    .else
    ldr     r9, [r0, #32]               ; sp(dst)
    ldr     lr, [r0, #36]               ; EXC_RETURN
    .endif
    stmfd   r9!, {r1-r8}                ; r0-r3, r12, lr, pc, psr -> exception return stack frame
    mov     r1, r9

    ; reload the others register
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r2, r0, #136
    .else
    mov     r2, r0
    .endif
    ldmfd   r2, {r4-r11}                ; r4-r11
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    add     r2, r0, #128
    ldr     r3, [r2]                    ; reload FPSCR
    vmsr    fpscr, r3                   ; reload FPSCR
    vldmfd  r0, {d0-d15}                ; Load VFP double-precision registers
    .endif
    ; further optimization issues - late-arriving, tail-chaining
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OS_CONTEXT_USE_MSP
    msr     psp, r1  ; Use PSP
    b       _OS_CONTEXT_JUMPTO_LR
_OS_CONTEXT_USE_MSP:
    msr     msp, r1 ; Use MSP
_OS_CONTEXT_JUMPTO_LR:    
    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_DoContextSwitch

;*****************************************************************************
; Function             : Os_FaultHandler
; Service ID           : NA
; Description          : This function is for handling Configurable Fault
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     :
;
;
;                        Function(s) invoked    :
;                        Os_TrapHandler()
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_FaultHandler, $function

Os_FaultHandler:
    ;--------------------------------------------------------
    ; already a stack frame has been made
    ; {r0, r1, r2, r3, r12, lr(r14), pc, xpsr} where msp/psp -> r0
    ;--------------------------------------------------------
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OSFAULT_SAVE_MSP_CTXT

    ; save preempted task's context into stack frame
    ;--------------------------------------------------------
    ; save other registers
    ; {EXEC_RETURN, sp, r11-r4} psp->r4
    ;--------------------------------------------------------
    mrs     r0,  psp
    mov     r12, r0
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmfd   r0!, {r4-r11, r12, lr}      ; save {EXEC_RETURN, psp, r11-r4} psp->r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     r0, r0, #4                  ; skip dummy
    sub     r0, r0, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [r0]                    ; Push FPSCR to stack
    vstmfd  r0!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    msr     psp, r0
    b       _OSFAULT_TYPE_HANDLE

_OSFAULT_SAVE_MSP_CTXT:
    ;--------------------------------------------------------
    ; save other registers of handler mode
    ; {EXEC_RETURN, msp, r11-r4} msp->r4
    ;--------------------------------------------------------
    mov     r12, sp
    stmfd   sp!, {r4-r11, r12, lr}
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     sp, sp, #4                  ; skip dummy
    sub     sp, sp, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [sp]                    ; Push FPSCR to stack    
    vstmfd  sp!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    mov     r0, sp
_OSFAULT_TYPE_HANDLE:
    push    {lr, r10}                   ; r10 is just for preventing compile warning
    mrs     r1, ipsr                    ; get isr vector number
    ldr     lr, _PtrFuncOsTrapHandler
    blx     lr
    pop     {lr, r10}

_OSFAULT_RETURN_PROCESSOR:
    ; further optimization issues - late-arriving, tail-chaining
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OSFAULT_RESTORE_CTXT

    ; pop-up manually saved thread mode stack frame
    mrs     r0, psp
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  r0!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [r0]                    ; reload FPSCR
    vmsr    fpscr, r1
    add     r0, r0, #4
    add     r0, r0, #4                  ; skip dummy
    .endif
    ldmfd   r0!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    msr     psp, r0
    dsb
    isb
    bx      lr

_OSFAULT_RESTORE_CTXT:
    ; pop-up manually saved handler mode stack frame
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  sp!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [sp]                    ; reload FPSCR
    vmsr    fpscr, r1
    add     sp, sp, #4
    add     sp, sp, #4                  ; skip dummy
    .endif
    ldmfd   sp!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_FaultHandler

; Label Address

.align 4

_PtrFuncOsTrapHandler:    .word   Os_TrapHandler

;*****************************************************************************
; Function             : Os_UnusedExceptionHandler
; Service ID           : NA
; Description          : This function is for handling Unused Exception
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     :
;
;
;                        Function(s) invoked    :
;                        Os_UnusedHandler()
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_UnusedExceptionHandler, $function

Os_UnusedExceptionHandler:
    ;--------------------------------------------------------
    ; already a stack frame has been made
    ; {r0, r1, r2, r3, r12, lr(r14), pc, xpsr} where msp/psp -> r0
    ;--------------------------------------------------------
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OSUNUSED_SAVE_CTXT

    ;--------------------------------------------------------
    ; save preempted task's context into stack frame
    ; save other registers
    ; {EXEC_RETURN, sp, r11-r4} psp->r4
    ;--------------------------------------------------------
    mrs     r0,  psp
    mov     r12, r0
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmfd   r0!, {r4-r11, r12, lr}      ; save {EXEC_RETURN, psp, r11-r4} psp->r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     r0, r0, #4                  ; skip dummy
    sub     r0, r0, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [r0]                    ; Push FPSCR to stack
    vstmfd  r0!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    msr     psp, r0
    b       _OSUNUSED_HANDLE

_OSUNUSED_SAVE_CTXT:
    ;--------------------------------------------------------
    ; save other registers of handler mode
    ; {EXEC_RETURN, msp, r11-r4} msp->r4
    ;--------------------------------------------------------
    mov     r12, sp
    stmfd   sp!, {r4-r11, r12, lr}
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     sp, sp, #4                  ; skip dummy
    sub     sp, sp, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [sp]                    ; Push FPSCR to stack
    vstmfd  sp!, {d0-d15}               ; Store VFP double-precision registers
    .endif

_OSUNUSED_HANDLE:
    push    {lr, r10}                   ; r10 is just for preventing compile warning
    ldr     lr, _PtrFuncOsUnusedHandler
    blx     lr
    pop     {lr, r10}

_OSUNUSED_RETURN:
    ; further optimization issues - late-arriving, tail-chaining
    tst        lr, #4                   ; context on PSP? (lr & 4)
    beq     _OSUNUSED_RETURN_HANDLER

    ; pop-up manually saved thread mode stack frame
    mrs     r0, psp
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  r0!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [r0]                    ; reload FPSCR
    vmsr    fpscr, r1
    add     r0, r0, #4
    add     r0, r0, #4                  ; skip dummy
    .endif
    ldmfd   r0!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    msr     psp, r0
    bx      lr

_OSUNUSED_RETURN_HANDLER:
    ; pop-up manually saveed handler mode stack frame
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  sp!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [sp]                    ; reload FPSCR
    vmsr    fpscr, r1                   ; reload FPSCR
    add     sp, sp, #4
    add     sp, sp, #4                  ; skip dummy
    .endif
    ldmfd   sp!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_UnusedExceptionHandler

; Label Address

.align 4

_PtrFuncOsUnusedHandler:  .word   Os_UnusedHandler

;*****************************************************************************
; Function             : Os_NMIHandler
; Service ID           : NA
; Description          : This function is for handling NMI Exception
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 :
; @remarks             : Global Variable(s)     :
;
;
;                        Function(s) invoked    :
;                        Os_CallBackNMInterrupt()
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_NMIHandler, $function

Os_NMIHandler:
    ;--------------------------------------------------------
    ; already a stack frame has been made
    ; {r0, r1, r2, r3, r12, lr(r14), pc, xpsr} where msp/psp -> r0
    ;--------------------------------------------------------
    tst     lr, #4                      ; context on PSP? (lr & 4)
    beq     _OSNMI_SAVE_CTXT

    ;--------------------------------------------------------
    ; save preempted task's context into stack frame
    ; save other registers
    ; {EXEC_RETURN, sp, r11-r4} psp->r4
    ;--------------------------------------------------------
    mrs     r0,  psp
    mov     r12, r0
    add     r12, r12, #32               ; for making stack frame on dispatching
    stmfd   r0!, {r4-r11, r12, lr}      ; save {EXEC_RETURN, psp, r11-r4} psp->r4
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     r0, r0, #4                  ; skip dummy
    sub     r0, r0, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [r0]                    ; Push FPSCR to stack
    vstmfd  r0!, {d0-d15}               ; Store VFP double-precision registers
    .endif
    msr     psp, r0
    b       _OSNMI_HANDLE

_OSNMI_SAVE_CTXT:
    ;--------------------------------------------------------
    ; save other registers of handler mode
    ; {EXEC_RETURN, msp, r11-r4} msp->r4
    ;--------------------------------------------------------
    mov     r12, sp
    stmfd   sp!, {r4-r11, r12, lr}
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    sub     sp, sp, #4                  ; skip dummy
    sub     sp, sp, #4
    vmrs    r1, fpscr                   ; Get FPSCR
    str     r1, [sp]                    ; Push FPSCR to stack
    vstmfd  sp!, {d0-d15}               ; Store VFP double-precision registers
    .endif

_OSNMI_HANDLE:
    push    {lr, r10}                   ; r10 is just for preventing compile warning
    ldr     lr, _PtrFuncOsCallBackNMInterrupt
    blx     lr
    pop     {lr, r10}

_OSNMI_RETURN:
    ; further optimization issues - late-arriving, tail-chaining
    tst        lr, #4                   ; context on PSP? (lr & 4)
    beq     _OSNMI_RETURN_HANDLER

    ; pop-up manually saved thread mode stack frame
    mrs     r0, psp
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  r0!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [r0]                    ; reload FPSCR
    vmsr    fpscr, r1
    add     r0, r0, #4
    add     r0, r0, #4                  ; skip dummy
    .endif
    ldmfd   r0!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    msr     psp, r0
    bx      lr

_OSNMI_RETURN_HANDLER:
    ; pop-up manually saveed handler mode stack frame
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vldmfd  sp!, {d0-d15}               ; reload VFP double-precision registers
    ldr     r1, [sp]                    ; reload FPSCR
    vmsr    fpscr, r1                   ; reload FPSCR
    add     sp, sp, #4
    add     sp, sp, #4                  ; skip dummy
    .endif
    ldmfd   sp!, {r4-r11, r12, lr}      ; reload SP->r12, discard it
    dsb
    isb
    bx      lr                          ; return to pre-interrupt context

    .endf Os_NMIHandler

; Label Address

.align 4

_PtrFuncOsCallBackNMInterrupt:  .word   Os_CallBackNMInterrupt

;*****************************************************************************
; Function             : Os_GetMSP
; Service ID           : NA
; Description          : This function is to get MSP (main stack pointer)
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetMSP, $function

Os_GetMSP:
    mrs     r0, msp
    bx      lr

    .endf Os_GetMSP

;*****************************************************************************
; Function             : Os_SetMSP
; Service ID           : NA
; Description          : This function is to set MSP register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : stack pointer to be set in MSP
; @return              : None
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_SetMSP, $function

Os_SetMSP:
    msr     msp, r0
    isb
    bx      lr

    .endf Os_SetMSP

;*****************************************************************************
; Function             : Os_GetPSP
; Service ID           : NA
; Description          : This function is to get PSP (processor stack pointer)
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : void
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetPSP, $function

Os_GetPSP:
    mrs     r0, psp
    bx      lr

    .endf Os_GetPSP

;*****************************************************************************
; Function             : Os_SetPSP
; Service ID           : NA
; Description          : This function is to set PSP register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : stack pointer to be set in PSP
; @return              : None
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_SetPSP, $function

Os_SetPSP:
    msr     psp, r0
    isb
    bx      lr

    .endf Os_SetPSP

;*****************************************************************************
; Function             : Os_GetCONTROL
; Service ID           : NA
; Description          : This function is to get CONTROL register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : CONTROL register
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetCONTROL, $function

Os_GetCONTROL:

    mrs     r0, control
    bx      lr

    .endf Os_GetCONTROL

;*****************************************************************************
; Function             : Os_SetCONTROL
; Service ID           : NA
; Description          : This function is to set CONTROL register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : value to be set in CONTROL register
; @return              : None
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_SetCONTROL, $function

Os_SetCONTROL:
    msr     control, r0
    bx      lr

    .endf Os_SetCONTROL

;*****************************************************************************
; Function             : Os_GetPRIMASK
; Service ID           : NA
; Description          : This function is to get PRIMASK register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : PRIMASK register
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetPRIMASK, $function

Os_GetPRIMASK:
    mrs     r0, primask
    bx      lr

    .endf Os_GetPRIMASK

;*****************************************************************************
; Function             : Os_GetFAULTMASK
; Service ID           : NA
; Description          : This function is to get FAULTMASK register
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : FAULTMASK register
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetFAULTMASK, $function

Os_GetFAULTMASK:
    mrs     r0, faultmask
    bx      lr

    .endf Os_GetFAULTMASK

;*****************************************************************************
; Function             : Os_IrqGetVectNumber
; Service ID           : NA
; Description          : This function is to get vector number of exception
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : None
; @return              : vector number of exception
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_IrqGetVectNumber, $function

Os_IrqGetVectNumber:
    mrs     r0, ipsr    ; get isr vector number
    bx      lr

    .endf Os_IrqGetVectNumber

;*****************************************************************************
; Function             : Os_CallFuncKernelStack
; Service ID           : NA
; Description          : This function is to call function with chainging to
;                        kernel stack
;
; Sync/Async           : NA
; Re-entrancy          : Non Re-entrant
; Parameters           : param0 (r0)
;                        param1 (r1)
;                        param2 (r2)
;                        function pointer (r3)
; @return              : vector number of exception
; @pre                 : None
; @remarks             : Global Variable(s)     :
;                        Function(s) invoked    :
;
; {Ref: SWR_OS_CYTXXX_003}
;
; @ingroup               OS_CYTXXX_ESDD_006
;*****************************************************************************
    .section ".OS_TEXT_CODE"
    .text
    .align 4
    .thumb2
    .type Os_CallFuncKernelStack, $function

Os_CallFuncKernelStack:
    push    {r4, r5, r6, lr}            ; r6 for 8-bytes align
    ldr     r4, _PtrGulInKernelSP
    push    {r10, r9} 
    .if (OS_MULTICORE_FEATURE == 1)
    ldr     r10, _PtrCoreid
    ldr     r10, [r10]
    ands    r10, r10, CORE_ID_MASK
    lsr     r10, r10, 8          ; logical shift right by 8-bit
    mov     r9, #4
    mul     r10, r10, r9
    add     r4, r4, r10
    .endif
    pop    {r10, r9} 
    ldr     r4, [r4]
    mov     lr, r3                      ; get function to be called
    mov     r5, r13                     ; save current stack pointer
    mov     r13, r4                     ; change stack pointer to kernel stack pointer
    blx     lr                          ; call function
    mov     r13, r5                     ; restore stack pointer
    pop     {r4, r5, r6, lr}
    bx      lr

    .endf Os_CallFuncKernelStack

;/*****************************************************************************
; * Function             : Os_GetFpscr
; *
; * Description          : Read FPSCR register
; *
; * @param [in]          : None
; *
; * @return              : FPSCR register in R0
; *
; * @ingroup             :
; ******************************************************************************/
    .section ".OS_API_CODE"
    .text
    .align 4
    .thumb2
    .type Os_GetFpscr, $function
Os_GetFpscr:
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vmrs    r0, fpscr
    .endif
    bx      lr

    .endf Os_GetFpscr

;/*****************************************************************************
; * Function             : Os_SetFpscr
; *
; * Description          : Write FPSCR register
; *
; * @param [in]          : R0 - parameter to be written FPSCR
; *
; * @return              : None
; *
; * @ingroup             :
; ******************************************************************************/
    .section ".OS_API_CODE"
    .text
    .align 4
    .thumb2
    .type Os_SetFpscr, $function
Os_SetFpscr:
    .if (OS_FPU_SUPPORT_FEATURE == 1)
    vmsr    fpscr, r0
    .endif
    bx      lr

    .endf Os_SetFpscr

    .end
