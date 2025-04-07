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
**  SRC-MODULE: Os_Stack.c                                                    **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of  Stack functionality                             **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.3.0     28-Mar-2017    SH.Yoo        Redmine #5967                       **
** 2.3.0     23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.1.0     05-Oct-2016    SH.Yoo        Redmine #5866                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189, #1311                **
** 2.0.7     21-Jan-2014    MJ.Woo        TASK: xar~819, Redmine #558         **
** 2.0.3     17-Sep-2013    SH.Yoo        CR: xar~172, TASK: xar~691          **
** 2.0.2     19-Aug-2013    SH.Yoo        CR: xar~168, TASK: xar~675          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     10-Jan-2013    JH.Son,SH.Yoo Initial version                     **
**                          DG.Lee,MJ.Woo                                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Stack.h"             /* Os Stack header file */
#include "Os_TimingProtection.h"  /* Os TimerProtection header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_Shutdown.h"          /* Os Shutdown header file */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"
/*******************************************************************************
** Function Name        : OS_CheckStack                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This service is used to measure the stack of the    **
**                        task                                                **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : LpStaticTask                                        **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : StartOS() function should be called                 **
**                                                                            **
** Remarks              : Global Variable(s)     :  Os_GaaStack,              **
**                        Os_GulOsAppSPTop, Os_GulUserSPTop                   **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetStackPointer(),                               **
**                        Os_ProtectionHookService(),                         **
**                        Os_SyncShutdownOSService()                          **
*******************************************************************************/
#if(OS_STACK_MONITORING == STD_ON)
FUNC(void, OS_CODE) Os_CheckStack(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
                                                         OS_CONST) LpStaticTask)
{
  P2VAR(Os_StackType, AUTOMATIC, OS_VAR) LpStackTop;
  P2VAR(Os_StackType, AUTOMATIC, OS_VAR) LpStackBtm;
  P2VAR(uint32, AUTOMATIC, OS_VAR) LpStackaddress;
  boolean LblStackFailed = OS_FALSE;

  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Get the stack area for the current running task/ISR */
  LpStackaddress = Os_GetStackPointer(LpStaticTask);

  #if (OS_EVENT == STD_ON)
  /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
  /* polyspace<RTE:IDP:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if(LpStaticTask->usType == OS_TASK_EXTENDED)
  {
    /* Store the top address of the task stack area in the local pointer */
    /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> configured array index */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> configured array index */
    LpStackTop = (Os_GaaStack[LpStaticTask->ucStackIndex].pStackArea);
    /* Store the bottom address of the task stack area in the local pointer */
    /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
    /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Pointer arithmatic used to achieve better throughput.*/
    LpStackBtm = &LpStackTop[Os_GetStackSize(LpStaticTask)];
    /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
  }
  else /* BASIC TASK, CAT2 ISR */
  #endif /* End of #if (OS_EVENT == STD_ON) */
  {
    #if (OS_APPLICATION == STD_ON)
    /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
    if(LpStaticTask->ddTaskId != OS_CORE_ID)
    {
      /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LpStackBtm = LpStaticTask->pContext->pPowerOnSP;


      /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
      /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
      /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> This is intended to handle stack address  */
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      /* polyspace:begin<CERT-C:INT36-C:Not a defect:Justify with annotations> Conversion is needed for implementation */
      LpStackTop = (Os_StackType*)Os_GulOsAppSPTop[LpStaticTask->ddAppId];
      /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      /* polyspace:end<CERT-C:INT36-C> */

    }
    else
    #endif
    {
      /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
      /* polyspace<RTE: NIP : Not a defect : No Action Planned > ptr points to a valid value and code is verified manually*/
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
      LpStackBtm = LpStaticTask->pContext->pPowerOnSP;
      /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
      /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> This is intended to handle stack address  */
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
      /* polyspace-begin CERT-C:INT36-C [Justified:Low] "This conversion is need" */
      LpStackTop = (Os_StackType*)Os_GulUserSPTop[OS_CORE_ID];
      /* polyspace-end CERT-C:INT36-C [Justified:Low] "This conversion is need" */
      /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
    }
  }

  /* polyspace<RTE: ABS_ADDR : Not a defect : Justify with annotations > This is intended to check invalid address */
  /* polyspace<MISRA-C:11.3:Not a defect:Justify with annotations> This is intended to check invalid address  */
  /* polyspace:begin<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  if (LpStackaddress == (uint32*)INVALID_STACK_POINTER)
  /* polyspace:end<ISO-17961:intptrconv:Not a defect:Justify with annotations> Conversion is needed for implementation */
  {
    /* If stack pointer is invalid, just check a stack pattern */
    /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
    /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
    /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if((*(Os_StackType*)(LpStackTop)) != OS_STACK_PATTERN)
    {
      LblStackFailed = OS_TRUE;
    }
  }
  else
  {
    /* Check stack range and a stack pattern */
    if(((LpStackaddress) > (Os_StackType*)(LpStackBtm)) ||
             ((LpStackaddress) < (Os_StackType*)(LpStackTop)) ||
    /* polyspace<RTE:NIV:Not a defect:Justify with annotations> variable is initialized and code is verified manually */
    /* polyspace<RTE: IDP : Not a defect : Justify with annotations > configured memory access index */
    /* polyspace<MISRA-C:1.1:Not a defect:Justify with annotations> It is necessary for 64bit data */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
                          ((*(Os_StackType*)(LpStackTop)) != OS_STACK_PATTERN))
    {
      LblStackFailed = OS_TRUE;
    }
  }

  if (LblStackFailed == OS_TRUE)
  {
    #if (OS_PROTECTION_HOOK == STD_ON)
    {
      (void)Os_ProtectionHookService(E_OS_STACKFAULT);
    }
    #else
    /*
     * NTC.9 : The called function ShutdownOS (in the current context)
     *         either contains an error or does not terminate
     * Description: As per requirement OS425, ShutdownOS() shall
     *              enter an endless loop, thus this warning is encountered.
     */
    Os_SyncShutdownOSService(E_OS_STACKFAULT);
    #endif
  }
} /* End of Os_CheckStack(P2CONST(Tdd_Os_StaticTask, AUTOMATIC,
   *OS_CONST) LpStaticTask) */
#endif /* End of if (OS_STACK_MONITORING == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
