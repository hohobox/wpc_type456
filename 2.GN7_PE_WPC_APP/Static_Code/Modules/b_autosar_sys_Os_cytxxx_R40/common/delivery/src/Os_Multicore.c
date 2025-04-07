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
**  SRC-MODULE: Os_Multicore.c                                                **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Multicore functionality.                         **
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
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.4.3     22-Mar-2018    SH.Yoo        Redmine #12025                      **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #5368                       **
** 2.0.4     23-Oct-2013    DG.Lee        CR: xar~179, TASK: xar~736          **
** 2.0.0     22-Jul-2013    JH.Son,SH.Yoo CR: xar~107, TASK: xar~543          **
**                          DG.Lee,MJ.Woo                                     **
** 1.0.0     26-Mar-2013    Son           Initial version                     **
*******************************************************************************/

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "Os_InternalTypes.h"     /* Os InternalTypes header file */
#include "Os_PortTypes.h"         /* Os PortTypes header file */
#include "Os_Ram.h"               /* Os Ram header file */
#include "Os_Error.h"             /* Os Error header file */
#include "Os_Arch_Multicore.h"    /* Os Multi-core header file */
#include "Os_MulticoreMessage.h"

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE: ABS_ADDR : Not a defect : Justify with annotations > Absolute address is needed to access MCU register */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : Os_SetSyncFirst                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for first synchronization     **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GucSync1, Os_Core_Count                          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock()              **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_SetSyncFirst(void)
{
  /* Get Spinlock for the core */
  Os_GetSpinlock(OS_SPIN_LOCK_ZERO);
  /* Increment Synchronization variable */
  Os_GucSync1++;
  /* Release Spinlock */
  Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);
  /* Wait in a while loop till all the cores are synchronized */
  do {
  } while (Os_GucSync1 < Os_Core_Count);
} /* End of Os_SetSyncFirst(void) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_SetSyncSecond                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for second synchronization    **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GucSync1, Os_Core_Count                          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock()              **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_SetSyncSecond(void)
{
  /* Get Spinlock for the core */
  Os_GetSpinlock(OS_SPIN_LOCK_ZERO);
  /* Increment Synchronization variable */
  Os_GucSync1++;
  /* Release Spinlock */
  Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);
  /*
   * Core is once synchronized during Os_SetSyncFirst().
   * This is the second sync
   */
  do {
  } while (Os_GucSync1 < (OS_SECOND_STEP * Os_Core_Count));
} /* End of Os_SetSyncSecond(void) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_WaitSyncShutDown                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for shutdown synchronization  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GucSync1, Os_Core_Count                          **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        OS_GET_CORE_ID(), Os_RecvDuringShutdown(),          **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_WaitSyncShutDown(void)
{
  CoreIDType OS_CORE_ID;

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /*
   * Core is already synchronized twice (Os_SetSyncFirst/Os_SetSyncSecond).
   * This is the Third sync
   */
  do {
    Os_RecvDuringShutdown(OS_CORE_ID);
  } while (Os_GucSync1 < (OS_THIRD_STEP * Os_Core_Count));
} /* End of Os_SetSyncShutDown(void) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_SetSyncCountShutDown                             **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for shutdown synchronization  **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy          : Non Re-entrant                                      **
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
**                        Os_GucSync1                                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock()              **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(void, OS_CODE) Os_SetSyncCountShutDown(void)
{
  /* Get Spinlock for the core */
  Os_GetSpinlock(OS_SPIN_LOCK_ZERO);

  /* Increment Synchronization variable */
  Os_GucSync1++;

  /* Release Spinlock */
  Os_ReleaseSpinlock(OS_SPIN_LOCK_ZERO);

} /* End of Os_SetSyncShutDown(void) */
#endif /* End of if (OS_MULTICORE == STD_ON) */

/*******************************************************************************
** Function Name        : Os_KernGetCoreID                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This Function is used for get core ID               **
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
** Remarks              : Global Variable(s)     :                            **
**                        None                                                **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        None                                                **
*******************************************************************************/
#if (OS_MULTICORE == STD_ON)
FUNC(CoreIdType, OS_CODE) Os_KernGetCoreID(void)
{
  /* TODO Error Check for E_OS_DISABLEDINT is not done as per OS093 */
  return (CoreIdType)(Os_MyCore());
}
#endif
#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:end<RTE: ABS_ADDR : Not a defect : Justify with annotations > Absolute address is needed to access MCU register */
/* polyspace:end<MISRA-C3:20.1> */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
