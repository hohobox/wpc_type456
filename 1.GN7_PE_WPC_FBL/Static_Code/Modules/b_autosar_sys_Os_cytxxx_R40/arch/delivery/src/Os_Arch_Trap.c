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
**  SRC-MODULE: Os_Arch_Trap.c                                                **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Exception vector                                 **
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
** 2.4.0     04-Jun-2021    YH.Han        Redmine #29686                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #20861, #22057              **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:NIV:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:begin<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:begin<MISRA-C3:8.13:Not a defect:Justify with annotations> The pointer points const-qualified type */
/* polyspace:begin<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for vector table */
/* polyspace:begin<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.5:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:begin<MISRA-C3:11.6:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"
#include "Os_Ram.h"
#include "Os_Shutdown.h"
#include "Os_Multicore.h"
#include "Os_Kernel.h"
#include "Os_Error.h"
#include "Os_Arch_Except.h"
#include "Os_Arch_Interrupt.h"
#include "Os_Arch_MemPro.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

#define OS_START_SEC_EXCEPTION_VECTOR
#include "MemMap.h"

const T_IsrFuncPtr Os_ExceptionVectorTable[NUM_ELE_VECTOR_TABLE] =
{
    (T_IsrFuncPtr) &OS_MAIN_TOS,                  /* 0:   Top of Stack */
    (T_IsrFuncPtr) &Reset_Handler,                /* 1:   Reset Handler */
    (T_IsrFuncPtr) &Os_NMIHandler,                /* 2:   NMI Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 3:   Hard Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 4:   MPU Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 5:   Bus Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 6:   Usage Fault Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 7:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 8:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 9:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 10:  Reserved */
    (T_IsrFuncPtr) &Os_SVCallHandler,             /* 11:  SVCall Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 12:  Debug Monitor Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 13:  Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 14:  PendSV Handler */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 15:  SysTick Handler */
    /* External Interrupts */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 16:  IRQ0 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 17:  IRQ1 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 18:  IRQ2 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 19:  IRQ3 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 20:  IRQ4 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 21:  IRQ5 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 22:  IRQ6 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 23:  IRQ7 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 24:  IRQ8 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 25:  IRQ9 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 26:  IRQ10 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 27:  IRQ11 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 28:  IRQ12 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 29:  IRQ13 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 30:  IRQ14 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 31:  IRQ15 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 32 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 33 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 34 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 35 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 36 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 37 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 38 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 39 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 40 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 41 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 42 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 43 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 44 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 45 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 46 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 47 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 48 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 49 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 50 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 51 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 52 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 53 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 54 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 55 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 56 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 57 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 58 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 59 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 60 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 61 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 62 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 63 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 64 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 65 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 66 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 67 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 68 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 69 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 70 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 71 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 72 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 73 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 74 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 75 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 76 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 77 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 78 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 79 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 80 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 81 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 82 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 83 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 84 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 85 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 86 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 87 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 88 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 89 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 90 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 91 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 92 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 93 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 94 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 95 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 96 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 97 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 98 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 99 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 100 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 101 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 102 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 103 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 104 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 105 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 106 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 107 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 108 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 109 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 110 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 111 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 112 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 113 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 114 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 115 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 116 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 117 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 118 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 119 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 120 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 121 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 122 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 123 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 124 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 125 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 126 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 127 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 128 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 129 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 130 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 131 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 132 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 133 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 134 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 135 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 136 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 137 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 138 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 139 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 140 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 141 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 142 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 143 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 144 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 145 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 146 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 147 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 148 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 149 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 150 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 151 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 152 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 153 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 154 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 155 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 156 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 157 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 158 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 159 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 160 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 161 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 162 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 163 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 164 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 165 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 166 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 167 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 168 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 169 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 170 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 171 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 172 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 173 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 174 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 175 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 176 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 177 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 178 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 179 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 180 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 181 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 182 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 183 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 184 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 185 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 186 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 187 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 188 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 189 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 190 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 191 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 192 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 193 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 194 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 195 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 196 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 197 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 198 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 199 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 200 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 201 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 202 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 203 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 204 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 205 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 206 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 207 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 208 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 209 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 210 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 211 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 212 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 213 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 214 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 215 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 216 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 217 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 218 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 219 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 220 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 221 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 222 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 223 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 224 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 225 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 226 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 227 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 228 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 229 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 230 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 231 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 232 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 233 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 234 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 235 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 236 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 237 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 238 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 239 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 240 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 241 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 242 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 243 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 244 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 245 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 246 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 247 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 248 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 249 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 250 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 251 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 252 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 253 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 254 */
    (T_IsrFuncPtr) 0xFFFFFFFFu                    /* Reserved for user TRIM value */
};

#define OS_STOP_SEC_EXCEPTION_VECTOR
#include "MemMap.h"

#if (OS_MULTICORE == STD_ON)
#define OS_START_SEC_EXCEPTION_VECTOR_CORE1
#include "MemMap.h"

const T_IsrFuncPtr Os_ExceptionVectorTableCore1[NUM_ELE_VECTOR_TABLE] =
{
    (T_IsrFuncPtr) &OS_CORE1_TOS,                 /* 0:   Top of Stack */
    (T_IsrFuncPtr) &Reset_Handler_Core1,          /* 1:   Reset Handler */
    (T_IsrFuncPtr) &Os_NMIHandler,                /* 2:   NMI Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 3:   Hard Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 4:   MPU Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 5:   Bus Fault Handler */
    (T_IsrFuncPtr) &Os_FaultHandler,              /* 6:   Usage Fault Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 7:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 8:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 9:   Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 10:  Reserved */
    (T_IsrFuncPtr) &Os_SVCallHandler,             /* 11:  SVCall Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 12:  Debug Monitor Handler */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 13:  Reserved */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 14:  PendSV Handler */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 15:  SysTick Handler */
    /* External Interrupts */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 16:  IRQ0 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 17:  IRQ1 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 18:  IRQ2 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 19:  IRQ3 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 20:  IRQ4 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 21:  IRQ5 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 22:  IRQ6 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 23:  IRQ7 External interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 24:  IRQ8 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 25:  IRQ9 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 26:  IRQ10 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 27:  IRQ11 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 28:  IRQ12 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 29:  IRQ13 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 30:  IRQ14 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_ISRHandler,                /* 31:  IRQ15 Internal(software only) Interrupt */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 32 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 33 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 34 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 35 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 36 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 37 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 38 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 39 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 40 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 41 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 42 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 43 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 44 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 45 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 46 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 47 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 48 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 49 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 50 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 51 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 52 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 53 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 54 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 55 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 56 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 57 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 58 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 59 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 60 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 61 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 62 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 63 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 64 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 65 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 66 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 67 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 68 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 69 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 70 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 71 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 72 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 73 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 74 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 75 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 76 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 77 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 78 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 79 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 80 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 81 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 82 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 83 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 84 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 85 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 86 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 87 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 88 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 89 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 90 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 91 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 92 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 93 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 94 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 95 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 96 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 97 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 98 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 99 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 100 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 101 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 102 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 103 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 104 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 105 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 106 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 107 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 108 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 109 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 110 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 111 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 112 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 113 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 114 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 115 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 116 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 117 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 118 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 119 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 120 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 121 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 122 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 123 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 124 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 125 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 126 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 127 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 128 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 129 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 130 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 131 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 132 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 133 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 134 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 135 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 136 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 137 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 138 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 139 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 140 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 141 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 142 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 143 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 144 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 145 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 146 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 147 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 148 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 149 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 150 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 151 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 152 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 153 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 154 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 155 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 156 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 157 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 158 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 159 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 160 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 161 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 162 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 163 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 164 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 165 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 166 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 167 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 168 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 169 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 170 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 171 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 172 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 173 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 174 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 175 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 176 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 177 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 178 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 179 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 180 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 181 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 182 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 183 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 184 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 185 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 186 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 187 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 188 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 189 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 190 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 191 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 192 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 193 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 194 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 195 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 196 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 197 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 198 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 199 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 200 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 201 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 202 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 203 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 204 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 205 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 206 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 207 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 208 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 209 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 210 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 211 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 212 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 213 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 214 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 215 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 216 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 217 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 218 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 219 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 220 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 221 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 222 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 223 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 224 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 225 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 226 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 227 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 228 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 229 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 230 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 231 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 232 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 233 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 234 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 235 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 236 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 237 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 238 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 239 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 240 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 241 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 242 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 243 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 244 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 245 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 246 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 247 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 248 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 249 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 250 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 251 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 252 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 253 */
    (T_IsrFuncPtr) &Os_UnusedExceptionHandler,    /* 254 */
    (T_IsrFuncPtr) 0xFFFFFFFFu                    /* Reserved for user TRIM value */
};

#define OS_STOP_SEC_EXCEPTION_VECTOR_CORE1
#include "MemMap.h"
#endif
/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
FUNC(void, OS_CODE) Os_TrapHandler(Tdd_Os_ContextSwitch * LpAddr, 
                                                         Os_TrapType LulExcNum);
FUNC(Os_TrapInfoType, OS_CODE) Os_GetLastTrapInfo(uint8 LddCoreId);
FUNC(void, OS_CODE) Os_UnusedHandler(void);
#define OS_START_SEC_CODE
#include "MemMap.h"

/***************************************************************************
 * Function             : Os_GetLastTrapInfo
 *
 * Service ID           : NA
 *
 * Description          : If CoreID is invalid, return CORE0 trap info
 *
 * Sync/Async           : NA
 *
 * Re-entrancy          : Non Re-entrant
 *
 * @param [in]            LddCoreID - Current Core ID
 *
 * @return              : Last Trap info of current core
 *
 * @pre                 : None
 *
 * @remarks             : Global Variable(s)     :
 *                        Os_GddTrapInfo
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_006
 ******************************************************************************/
FUNC(Os_TrapInfoType, OS_CODE) Os_GetLastTrapInfo(uint8 LddCoreId)
{
  CoreIdType coreid;

  if (LddCoreId < Os_Core_Count)
  {
    coreid = LddCoreId;
  }
  else
  {
    coreid = OS_CORE_ZERO;
  }

  return Os_GddTrapInfo[coreid];
}

/***************************************************************************
 * Function             : Os_TrapHandler
 *
 * Service ID           : NA
 *
 * Description          : This service is used to exception handling
 *
 * Sync/Async           : NA
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
 *                        Os_GddTrapInfo, Os_GpStaticTask, Os_GusCallevelCheck
 *                        Os_GulKernelSP, Os_GulKernelSPBase, Os_GucInKernel
 *
 *                        Function(s) invoked    :
 *                        Os_ProtectionHookService(), Os_DoContextSwitch(),
 *                        Os_ShutdownOSService()
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_006
 ******************************************************************************/
FUNC(void, OS_CODE) Os_TrapHandler(Tdd_Os_ContextSwitch * LpAddr, 
  	                                                      Os_TrapType LulExcNum)
{
  #if (OS_PROTECTION_HOOK == STD_ON)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpNewTaskISR;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID = Os_MyCore();
  #endif
  StatusType LddFatalerror = E_OS_PROTECTION_EXCEPTION;

  /* Save exception information */
  Os_GddTrapInfo[OS_CORE_ID].enTrapClass = LulExcNum;
  Os_GddTrapInfo[OS_CORE_ID].HFSR = OS_SBC_HFSR.U;
  Os_GddTrapInfo[OS_CORE_ID].CFSR = OS_SBC_CFSR.U;
  /* polyspace-begin MISRA-C3:11.3 [Justified:Medium] "To handle saved context" */
  /* polyspace-begin MISRA-C3:11.8 [Justified:Medium] "To handle saved context" */
  /* polyspace-begin MISRA-C3:D4.14 [Justified:Medium] "To handle saved context" */  
  Os_GddTrapInfo[OS_CORE_ID].ExecCtxt  = *((Tdd_Os_ContextSwitch *)LpAddr);
  /* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion is need" */
  Os_GddTrapInfo[OS_CORE_ID].pExecAddr = (MemoryStartAddressType)(LpAddr->ulPC);
  /* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion is need" */
  /* polyspace-end MISRA-C3:11.8 */
  /* polyspace-end MISRA-C3:11.3 */
  /* polyspace-end MISRA-C3:D4.14 */
  if (((OS_SBC_CFSR.B.MemManage & OS_MMFSR_ERROR_MASK) != OS_ZERO) &&
                   ((OS_SBC_CFSR.B.MemManage & OS_MMFSR_VALID_MASK) != OS_ZERO))
  {
    Os_GddTrapInfo[OS_CORE_ID].pMMFAR = (MemoryStartAddressType)OS_SBC_MMFAR;
  }
  else
  {
    Os_GddTrapInfo[OS_CORE_ID].pMMFAR =
                                     (MemoryStartAddressType)OS_INVALID_ADDRESS;
  }

  if (((OS_SBC_CFSR.B.BusFault & OS_BFSR_ERROR_MASK) != OS_ZERO) &&
                     ((OS_SBC_CFSR.B.BusFault & OS_BFSR_VALID_MASK) != OS_ZERO))
  {
    Os_GddTrapInfo[OS_CORE_ID].pBFAR = (MemoryStartAddressType)OS_SBC_BFAR;
  }
  else
  {
    Os_GddTrapInfo[OS_CORE_ID].pBFAR =
                                     (MemoryStartAddressType)OS_INVALID_ADDRESS;
  }

  #if (OS_PROTECTION_HOOK == STD_ON)
  #if (OS_MEMORY_PROTECTION == STD_ON)
  if (LulExcNum == OS_TRAP_MEMORY_MNG_FAULT)
  {
    LddFatalerror = E_OS_PROTECTION_MEMORY;
  }
  #endif
  (void)Os_ProtectionHookService(LddFatalerror);
  /* Running Task or ISR was killed. Need Context switching */
  LpNewTaskISR = Os_GpStaticTask[OS_CORE_ID];
	/* polyspace:begin<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Checking of NULL_PTR is for fail-safety */
  if (LpNewTaskISR == NULL_PTR)
  {
    /* Never returns! */
    Os_SyncShutdownOSService(LddFatalerror);
  }
	/* polyspace:end<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Checking of NULL_PTR is for fail-safety */
  else if (LpNewTaskISR->usType != OS_ISR2)
  {
    Os_GusCallevelCheck[OS_CORE_ID] = (uint16)OS_CONTEXT_NONE;

    /* Discard kernel stack(stacked by ISR) */
    Os_GulKernelSP[OS_CORE_ID] = Os_GulKernelSPBase[OS_CORE_ID];
  }
  else
  {
    Os_GusCallevelCheck[OS_CORE_ID] = (uint16)OS_CONTEXT_CAT2ISR;
  }
  Os_GucInKernel[OS_CORE_ID] = (uint8)OS_ZERO;

  Os_DoContextSwitch(LpNewTaskISR->pContext);
  #else
  /* Never returns! */
  Os_SyncShutdownOSService(LddFatalerror);
  #endif
}

/***************************************************************************
 * Function             : Os_UnusedHandler
 *
 * Service ID           : NA
 *
 * Description          : This service is used to unused exception handling
 *
 * Sync/Async           : NA
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
 *                        Os_GddTrapInfo, Os_GpStaticTask, Os_GusCallevelCheck
 *                        Os_GulKernelSP, Os_GulKernelSPBase, Os_GucInKernel
 *
 *                        Function(s) invoked    :
 *                        Os_ProtectionHookService(), Os_DoContextSwitch(),
 *                        Os_ShutdownOSService()
 *
 * {Ref: SWR_OS_CYTXXX_003}
 *
 * @ingroup               OS_CYTXXX_ESDD_006
 ******************************************************************************/
FUNC(void, OS_CODE) Os_UnusedHandler(void)
{
  StatusType LddFatalerror = E_OS_SYS_PANIC;

  /* This routine should not be called because the exception is not registered */

  /* Never returns! */
  Os_ShutdownOSService(LddFatalerror);
}

#define OS_STOP_SEC_EXCEPTION_VECTOR
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE:NIV:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:ABS_ADDR:Not a defect:Justify with annotations> MCU register access */
/* polyspace:end<RTE:IDP:Not a defect:Justify with annotations> Configured memory access index */
/* polyspace:end<MISRA-C3:8.13:Not a defect:Justify with annotations> The pointer points const-qualified type */
/* polyspace:end<MISRA-C3:11.1:Not a defect:Justify with annotations> Conversion is needed for vector table */
/* polyspace:end<MISRA-C3:11.4:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.5:Not a defect:Justify with annotations> Conversion is needed for implementation */
/* polyspace:end<MISRA-C3:11.6:Not a defect:Justify with annotations> Cast is needed for implementation */
/* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
