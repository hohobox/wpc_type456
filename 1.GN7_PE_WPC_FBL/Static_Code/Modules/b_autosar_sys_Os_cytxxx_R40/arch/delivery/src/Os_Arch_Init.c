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
**  SRC-MODULE: Os_Arch_Init.c                                                **
**                                                                            **
**  TARGET    : CYTxxx                                                        **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of port specific functionality                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.4.4     22-Nov-2022    YH.Han        Redmine #38194                      **
** 2.4.3     10-Aug-2022    JC.Kim        Redmine #36748                      **
** 2.4.2     08-Feb-2022    YH.Han        Redmine #34108                      **
** 2.4.1     20-Jan-2022    YH.Cho        Redmine #33850                      **
** 2.4.0     20-Aug-2021    YH.Cho        Redmine #31652                      **
** 2.1.0     11-Dec-2020    JH.Cho        Redmine #26391                      **
** 2.0.1     10-AUG-2020    JH.Cho        Redmine #24903                      **
** 2.0.0     16-JUN-2020    JH.Cho        Redmine #23917 #24316               **
** 1.1.0     06-Mar-2020    MJ.Woo        Redmine #22057                      **
** 1.0.0     23-Dec-2019    MJ.Woo        Redmine #18913                      **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:18.1 [Justified:Medium] "Pointer not access out of array" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os RAM header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*****************************************************************************
 * Function Name        : OS_PORTINITIALIZE
 *
 * Service ID           : NA
 *
 * Description          : This service is used to initialize Port
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
 *                        Os_GulKernelSP, Os_Task_Count, Os_CAT2_ISR_Count,
 *                        Os_Core_Count, Os_GaaStaticTask, Os_GaaStack
 *
 *                        Function(s) invoked    :
 *                        None
 *
 * {Ref: SWR_OS_CYTXXX_009}
 *
 * @ingroup               OS_CYTXXX_ESDD_001
 ******************************************************************************/
FUNC(void, OS_CODE) OS_PORTINITIALIZE(void)
{
  #if (OS_EVENT == STD_ON)
  P2CONST(Tdd_Os_StaticTask, AUTOMATIC, OS_CONST) LpStaticTask;
  #endif
  #if ((OS_EVENT == STD_ON) || (OS_APPLICATION == STD_ON))
  P2CONST (Tdd_Os_Stack, AUTOMATIC, OS_CONST) LpStack;
  uint32 LulCount;
  #endif
  #if (OS_APPLICATION == STD_ON)
  P2CONST(Tdd_Os_Application, AUTOMATIC, OS_CONST) LpStaticApplication;
  #endif

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif
  OS_GET_CORE_ID(OS_CORE_ID);
  
  #if (OS_MULTICORE == STD_ON)
  if(OS_CORE_ID == OS_ZERO)
  {
    /* Set interrupt for core0 */
    OS_IPC_REG.INTR_STRUCT[OS_IC_0_IPC_INDEX].INTR_SET.B.NOTIFY = 1u;
    /* Set interrupt for core1 */
    OS_IPC_REG.INTR_STRUCT[OS_IC_1_IPC_INDEX].INTR_SET.B.NOTIFY = 1u;
  }
  #endif
  
  /** Initialize Kernel stack pointer */
  Os_GulKernelSP[OS_CORE_ID] = Os_GetMSP();
  Os_GulKernelSPBase[OS_CORE_ID] = Os_GetMSP();

  /* polyspace +4 MISRA-C3:14.3 [Justified:Medium] "It is determined by configuration" */
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > Value of OS_CORE_ID depends on Multi-Core */
  /* polyspace:begin<DEFECT:USELESS_IF:Not a defect:No Action Planned> Value of OS_CORE_ID depends on Multi-Core */
  /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "Value of OS_CORE_ID depends on Multi-Core" */
  if (OS_CORE_ID == OS_ZERO)
  {
    #if (OS_EVENT == STD_ON)
    /** Initialize stack pattern for Extended Task stack */
    LulCount = (Os_Task_Count + Os_CAT2_ISR_Count + Os_Core_Count);
    do
    {
      /* Decrement loop count */
      LulCount--;
      /* Take a pointer to Static Task */
      LpStaticTask = &Os_GaaStaticTask[LulCount];
      /* polyspace<RTE:IDP:Not a defect:Justify with annotations> configured memory access index */
      if (LpStaticTask->usType == OS_TASK_EXTENDED)
      {
        LpStack = &Os_GaaStack[LpStaticTask->ucStackIndex];
        /* Writing stack pattern at the bottom of stack area */
        /* polyspace<RTE:IDP:Not a defect:Justify with annotations> configured memory access index */
        /* polyspace +2 MISRA-C3:11.4 [Justified:Medium] "To handle the stack" */
        /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
        *(LpStack->pStackArea) = OS_STACK_PATTERN;
        /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
      }
    } while (LulCount != (uint32)OS_ZERO);
    #endif

    /**
     * Initialize Stack Pointer
     */
    #if(OS_APPLICATION == STD_ON)
    #if(OS_STACK_MONITORING == STD_ON)
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This is intended to handle stack address  */
    /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
    Os_GaaRamUserStack0[0] = OS_STACK_PATTERN;
    #endif
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
    /* polyspace +2 MISRA-C3:18.4 [Justified:Low] "This is intended to handle stack address" */
  	/* polyspace +2 MISRA-C3:11.4 [Justified:Medium] "To handle the stack" */
    Os_GulUserSPTop[OS_ZERO] = (uint32)&Os_GaaRamUserStack0[0];
    Os_GulUserSPBtm[OS_ZERO] = (uint32)Os_GulUserSPTop[OS_ZERO] + Os_User_Stack_Size;
    Os_GulUserSP[OS_ZERO] = Os_GulUserSPBtm[OS_ZERO];
    /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
    #if (OS_MULTICORE == STD_ON)
    #if(OS_STACK_MONITORING == STD_ON)
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    /* polyspace<MISRA-C:11.4:Not a defect:Justify with annotations> This is intended to handle stack address  */
    /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
    Os_GaaRamUserStack1[0] = OS_STACK_PATTERN;
    #endif
    /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
    /* polyspace +2 MISRA-C3:18.4 [Justified:Low] "This is intended to handle stack address" */
    /* polyspace +2 MISRA-C3:11.4 [Justified:Medium] "To handle the stack" */
    Os_GulUserSPTop[OS_ONE] = (uint32)&Os_GaaRamUserStack1[0];
    Os_GulUserSPBtm[OS_ONE] = (uint32)Os_GulUserSPTop[OS_ONE] + Os_User_Stack_Size;
    Os_GulUserSP[OS_ONE] = Os_GulUserSPBtm[OS_ONE];
    /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To handle the stack */
    #endif /* End of #if (OS_MULTICORE == STD_ON) */
    #else
    #if(OS_STACK_MONITORING == STD_ON)
    Os_GaaRamUserStack[0] = OS_STACK_PATTERN;
    #endif
    /* polyspace +2 MISRA-C3:11.4 [Justified:Medium] "To handle the stack" */
    Os_GulUserSPTop[OS_ZERO] = (uint32)&Os_GaaRamUserStack[0];
    /* polyspace +2 MISRA-C3:18.4 [Justified:Low] "This is intended to handle stack address" */
    Os_GulUserSPBtm[OS_ZERO] = (uint32)Os_GulUserSPTop[OS_ZERO] + Os_User_Stack_Size;
    Os_GulUserSP[OS_ZERO] = Os_GulUserSPBtm[OS_ZERO];
    #endif /* #if(OS_APPLICATION == STD_ON) */

    #if (OS_APPLICATION == STD_ON)
    LulCount = Os_Application_Count;
    do
    {
      LulCount--;

      LpStaticApplication = &Os_GaaStaticApplication[LulCount];
      /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
      LpStack = &Os_GaaStack[LpStaticApplication->ucStackIndex];
      /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
      /* polyspace-begin MISRA-C3:11.4 [Justified:Medium] "Conversion is needed for implementation" */
      /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      Os_GulOsAppSPTop[LulCount] = (uint32)LpStack->pStackArea;
      /* polyspace-end MISRA-C3:11.4 [Justified:Medium] "Conversion is needed for implementation" */
      /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Pointer arithmetic used to achieve better throughput. */
      /* polyspace-begin MISRA-C3:11.4 [Justified:Medium] "Conversion is needed for implementation" */
      /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      Os_GulOsAppSPBtm[LulCount] =
        (uint32)(&(((Os_StackType*)LpStack->pStackArea)[(Os_Sint_T)LpStack->usStackSize]));
      /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Pointer arithmetic used to achieve better throughput. */
      /* polyspace-end MISRA-C3:11.4 [Justified:Medium] "Conversion is needed for implementation" */
      /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      Os_GulOsAppSP[LulCount] = Os_GulOsAppSPBtm[LulCount];

      #if(OS_STACK_MONITORING == STD_ON)
      /* Writing stack pattern at the bottom of stack area */
      /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
      /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
      *(LpStack->pStackArea) = OS_STACK_PATTERN;
      #endif
      /* polyspace:end<MISRA-C3:D4.1> */
      /* polyspace:end<MISRA-C3:18.1> */
    }while(LulCount != OS_ZERO);
    #endif
  }
  /* polyspace:end<DEFECT : USELESS_IF : Not a defect : Justify with annotations > Value of OS_CORE_ID depends on Multi-Core */
  /* polyspace-end CERT-C:MSC12-C [Not a defect:Low] "Value of OS_CORE_ID depends on Multi-Core" */
  
  /* Enable divide by integer zero fault detection */
  OS_SCB_CCR.B.DIV_0_TRP = 1U;

  /* Enable system handlers - USAGE, BUS, MEM */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> To access registers */
  /* polyspace +3 MISRA-C3:11.4 [Justified:Medium] "To access registers" */
  *((volatile uint32 *)OS_ARM_M_SYSHANDLER_CTRL_ADDR) |= (OS_ARM_M_USAGE_F_ENA |
                                             OS_ARM_M_BUS_F_ENA | OS_ARM_M_MEM_F_ENA);
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> To access registers */

  /* Enable entering Thread mode with exceptions active because of a controlled return value */
  OS_SCB_CCR.B.NONBASETHRDENA = 1U;

  #if (OS_FPU_SUPPORT == STD_ON)
  OS_SCB_CPACR.B.CP10 = OS_SCB_CPACR_CP10_FULL_ACCESS;
  OS_SCB_CPACR.B.CP11 = OS_SCB_CPACR_CP11_FULL_ACCESS;

  OS_FPU_FPCCR.B.LSPEN = OS_FPU_FPCCR_LSPEN_DISABLE;
  OS_FPU_FPCCR.B.ASPEN = OS_FPU_FPCCR_ASPEN_DISABLE;

  __DSB();
  __ISB();
	
  /** Save initial FPSCR value */
  Os_GddTaskInitFPSCR = Os_GetFpscr();
  #else

  OS_SCB_CPACR.B.CP10 = OS_SCB_CPACR_CP10_ACCESS_DENIED;
  OS_SCB_CPACR.B.CP11 = OS_SCB_CPACR_CP11_ACCESS_DENIED;

  OS_FPU_FPCCR.B.LSPEN = OS_FPU_FPCCR_LSPEN_DISABLE;
  OS_FPU_FPCCR.B.ASPEN = OS_FPU_FPCCR_ASPEN_DISABLE;

  __DSB();
  __ISB();
  #endif /* if (OS_FPU_SUPPORT == STD_ON) */
}

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace-end MISRA-C3:18.1 */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
