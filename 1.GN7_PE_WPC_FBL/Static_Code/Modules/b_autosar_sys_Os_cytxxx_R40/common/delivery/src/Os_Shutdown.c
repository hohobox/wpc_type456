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
**  SRC-MODULE: Os_Shutdown.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of  Shutdown functionality.                         **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]:                                              **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: No                                        **
**                                                                            **
*******************************************************************************/


/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date           By            Description                         **
********************************************************************************
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.4     08-Jul-2020    JH.Cho        Redmine #24398 #24397               **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.6.2     13-Apr-2020    MJ.Woo        Redmine #22921                      **
** 2.6.1     06-Mar-2020    MJ.Woo        Redmine #22246                      **
** 2.5.0     25-Jun-2018    SH.Yoo        Redmine #13150                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025                      **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.3.0     28-Mar-2017    SH.Yoo        Redmine #5967                       **
**           23-Mar-2017    JH.Lee        Redmine #7906                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
** 2.0.9     10-Dec-2014    MJ.Woo        Redmine #1189                       **
** 2.0.4     11-Nov-2013    SH.Yoo        CR: xar~179, TASK: xar~736          **
**           23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.2     03-Sep-2013    DG.Lee        CR: xar~168, TASK: xar~675          **
** 2.0.1     13-Aug-2013    MJ.Woo        CR: xar~160, TASK: xar~655          **
**                          DG.Lee                                            **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
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
#include "Os_Ram.h"               /* Os RAM header file */
#include "Os_Shutdown.h"          /* Os Shutdown header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Kernel.h"            /* Os Kernel header file */
#include "Os_Spinlock.h"          /* Os Spinlock header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#if (OS_MULTICORE == STD_ON)
#include "Os_MulticoreMessage.h"
#endif
#include "Os_SystemCallTable.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Os_ShutdownCore                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function is called to shutdown specific core   **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
**                                                                            **
** Input Parameters     : Error, ShutdownType                                 **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GaaCore, Os_GaaStaticAppHook,                    **
**                        Os_Application_Count, Os_GblCoreShutdown            **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SetSyncCountShutDown(), Os_WaitSyncShutDown(),   **
**                        ShutdownHook()                                      **
*******************************************************************************/
/* NOTE: Shutdown synchronized before global ShutdownHook and others */
FUNC(void, OS_CODE) Os_ShutdownCore(StatusType Error,
                                                   Os_ShutdownType ShutdownType)
{
  #if (OS_APP_SHUTDOWN_HOOK == STD_ON)
  P2CONST(Tdd_Os_ApplicationHook, AUTOMATIC, OS_CONST) LpApplication;
  uint8 LucAppCount;
  #endif
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  #if (OS_APP_SHUTDOWN_HOOK == STD_ON)
  /* Point to first application */
  LpApplication = &Os_GaaStaticAppHook[OS_ZERO];
  LucAppCount = OS_ZERO;

  /* Run through the while loop for all the applications */
  do
  {
    /* Check if startupHook is configured for the application */
    if (LpApplication->pShutDownHook != NULL_PTR)
    {
      /* Process Application ShutdownHook */
      OS_PROCESS_APP_SHUTDOWNHOOK(LpApplication->pShutDownHook, Error);
    }
    /* Point to next application */
    LucAppCount++;
    LpApplication++;
  } while (LucAppCount < Os_Application_Count);
  #endif /* End of if (OS_APP_SHUTDOWN_HOOK == STD_ON) */

  #if (OS_MULTICORE == STD_ON)
  /* Set a flag for core shutdown */
  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  Os_GblCoreShutdown[OS_CORE_ID] = OS_TRUE;

  Os_SetSyncCountShutDown();
  if (ShutdownType == OS_SHUTDOWN_SYNCHRONIZED)
  {
    /* Wait for Synchronization till all the cores shut down */
    Os_WaitSyncShutDown();
  }
  #else
  /* polyspace<RTE: UNR : Not a defect : Justify with annotations > NULL pointer check */
  OS_UNUSED(ShutdownType);
  #endif

  #if (OS_SHUTDOWN_HOOK == STD_ON)
  /* Process ShutdownHook */
  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  OS_PROCESS_SHUTDOWNHOOK(Error);
  #endif

  /* when using debugger, the "halt" mode can be exited,
   *   so this infinite loop is used only in this case */
  /* polyspace<RTE : NTL :Not a defect:Justify with annotations> Shutdown with infinite loop is intended instruction. */
  OS_INFINITELOOP();

} /* End of Os_ShutdownCore(StatusType Error) */

/*******************************************************************************
** Function Name        : ShutdownOS                                          **
**                                                                            **
** Service ID           : OSServiceId_ShutdownOS                              **
**                                                                            **
** Description          : This function is called when OS needs to be         **
**                        shutdown                                            **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :   N/A                      **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ShutdownOSService()                              **
*******************************************************************************/
/* NOTE: [OS617] ShutdownOS shall shutdown the core on which it was called. */
FUNC(void, OS_CODE) Os_KernShutdownOS(StatusType Error)
{
  StatusType LenStatusReturn;

  LenStatusReturn = E_OK;
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SHUTDOWNOS, LenStatusReturn);
  /* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  /* Check if the caller belongs to a non-trusted application: OS054*/
  OS_CHECK_CALLER_APPLICATION_ERROR(OS_INVALID_VALUE, &LenStatusReturn);
  /* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */

  if(LenStatusReturn == E_OK)
  {
    Os_ShutdownOSService(Error);
  }
} /* End of ShutdownOS(StatusType Error) */

/*******************************************************************************
** Function Name        : Os_ShutdownOSService                                **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This function is called when OS needs to be         **
**                        shutdown forcibly                                   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :   None                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ShutdownCore(), Os_ReleaseAllSpinlocks()         **
*******************************************************************************/
FUNC(void, OS_CODE) Os_ShutdownOSService(StatusType Error)
{
  /* Disable all interrupts */
  OS_DISABLEINTERRUPTS();

  #if (OS_SPINLOCK == STD_ON)
  /* Release all the spinlocks associated with the core */
  Os_ReleaseAllSpinlocks();
  #endif

  /* Call Os_ShutdownCore */
  Os_ShutdownCore(Error, OS_SHUTDOWN_INDIVIDUAL);
}

/*******************************************************************************
** Function Name        : Os_SynShutdownOSService                             **
**                                                                            **
** Service ID           : N/A                                                 **
**                                                                            **
** Description          : This function is called when OS needs to do         **
**                        synchronized shutdown forcibly                      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non re-entrant                                      **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :   None                     **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ShutdownCore(), Os_ReleaseAllSpinlocks(),        **
**                        Os_SendShutdownAllCores()                           **
*******************************************************************************/
FUNC(void, OS_CODE) Os_SyncShutdownOSService(StatusType Error)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  CoreIDType LddCoreCount;
  #endif

  /* Disable all interrupts */
  OS_DISABLEINTERRUPTS();

  #if (OS_SPINLOCK == STD_ON)
  /* Release all the spinlocks associated with the core */
  Os_ReleaseAllSpinlocks();
  #endif

  #if (OS_MULTICORE == STD_ON)
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* Send shutdown message to all cores. No answer is expected. */
  LddCoreCount = Os_Core_Count;
  /* polyspace<RTE : NTL :Not a defect:Justify with annotations> Shutdown with infinite loop is intended instruction. */
  do
  {
    LddCoreCount--;
    if (OS_CORE_ID != LddCoreCount)
    {
      Os_SendShutdownAllCores(LddCoreCount, Error);
    }
  } while (LddCoreCount != OS_ZERO);

  /* Call Os_ShutdownCore */
  Os_ShutdownCore(Error, OS_SHUTDOWN_SYNCHRONIZED);
  #else
  Os_ShutdownCore(Error, OS_SHUTDOWN_INDIVIDUAL);
  #endif
}

/*******************************************************************************
** Function Name        : ShutdownAllCores                                    **
**                                                                            **
** Service ID           : OSServiceId_ShutdownAllCores                        **
**                                                                            **
** Description          : This function is called when OS needs to be         **
**                        shutdown on all the cores                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Void                                                **
**                                                                            **
** Preconditions        : None                                                **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Os_GblShutdownFlag, Os_GucError, Os_GddAppId        **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_ShutdownCore(), Os_ReleaseAllSpinlocks(),        **
**                        Os_GenerateInt()                                    **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_KernShutdownAllCores(StatusType Error)
{
  CoreIDType OS_CORE_ID;
  CoreIDType LddCoreCount;
  StatusType LenStatusReturn;

  LenStatusReturn = E_OK;
  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);
  /* Check whether interrupts are not disabled by user */
  OS_CHECK_INTERRUPT_LOCK(&LenStatusReturn);
  /* Check for call level */
  OS_CHECK_E_OS_CALLEVEL(SHUTDOWNALLCORES, LenStatusReturn);
  /* polyspace:begin<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  /* Check if caller belongs to non trusted application  OS716*/
  OS_CHECK_CALLER_APPLICATION_ERROR(OS_INVALID_VALUE, &LenStatusReturn);
  /* polyspace:end<RTE: OBAI : Not a defect : Justify with annotations > configured array index */

  if(LenStatusReturn == E_OK)
  {
    /* Disable all interrupts */
    OS_DISABLEINTERRUPTS();

    #if (OS_SPINLOCK == STD_ON)
    /* Release all the spinlocks associated with the core */
    Os_ReleaseAllSpinlocks();
    #endif

    /* Send shutdown message to all cores. No answer is expected. */
    LddCoreCount = Os_Core_Count;
    /* polyspace<RTE : NTL :Not a defect:Justify with annotations> Shutdown with infinite loop is intended instruction. */
    do
    {
      LddCoreCount--;
      if (OS_CORE_ID != LddCoreCount)
      {
        Os_SendShutdownAllCores(LddCoreCount, Error);
      }
    } while (LddCoreCount != OS_ZERO);

    /* Call Os_ShutdownCore */
    Os_ShutdownCore(Error, OS_SHUTDOWN_SYNCHRONIZED);
  }
} /* End of ShutdownAllCores(StatusType Error) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/

