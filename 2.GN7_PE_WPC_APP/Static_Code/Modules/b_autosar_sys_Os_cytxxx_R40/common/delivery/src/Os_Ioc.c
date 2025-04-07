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
**  SRC-MODULE: Os_Ioc.c                                                      **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR OS                                                    **
**                                                                            **
**  PURPOSE   : Provision of Ioc functionality.                               **
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
** 2.6.15    12-Aug-2022    YH.Han        Redmine #37085                      **
** 2.6.14    10-Aug-2022    JC.Kim        Redmine #36970                      **
** 2.6.11    10-Feb-2022    YH.Han        Redmine #34322                      **
** 2.6.10    17-Dec-2021    JH.Cho        Redmine #33481                      **
** 2.6.7     10-Nov-2020    JH.Cho        Redmine #26023                      **
** 2.6.3     04-Jun-2020    MJ.Woo        Redmine #21784                      **
** 2.4.3     27-Mar-2018    SH.Yoo        Redmine #12132                      **
** 2.3.1     13-Jul-2017    MJ.Woo        Redmine #9148                       **
** 2.1.1     10-Jan-2017    MJ.Woo        Redmine #7199                       **
** 2.0.13    30-Jun-2016    MJ.Woo        Redmine #4566, #5368                **
** 2.0.11    16-Feb-2016    JH.Lee        Redmine #3963                       **
**           22-Dec-2015    MJ.Woo        Redmine: #3684                      **
** 2.0.10    08-Dec-2015    SH.Yoo        Redmine: #3483                      **
** 2.0.9     13-Oct-2014    MJ.Woo        Redmine: #1427                      **
** 2.0.8     14-May-2014    SH.Yoo        TASK: xar~842, Redmine #936         **
** 2.0.8     27-Feb-2014    SH.Yoo        TASK: xar~842, Redmine #626         **
** 2.0.4     23-Oct-2013    DG.Lee        Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace:begin<RTE:IDP:Not a defect:No action planned> It is defined from statically defined value */
/* polyspace:begin<MISRA-C3:20.1:Not a defect:Justify with annotations> see MEMMAP003 of AUTOSAR */
/* polyspace:begin<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include <string.h> /* for using memcpy */
#include "Os.h"
#include "Os_Ram.h"
#include "Os_Multicore.h"
#include "Os_Error.h"
#if (OS_MULTICORE == STD_ON)
#include "Os_Arch_Multicore.h"
#include "Os_MulticoreMessage.h"
#endif
#include "Os_IocInternalTypes.h"
#include "Os_Ioc.h"
#include "Os_SystemCallTable.h"

/*******************************************************************************
**                      Global Data                                           **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define OS_START_SEC_CODE
#include "MemMap.h"

#if (OS_APPLICATION == STD_ON)
/*******************************************************************************
** Function Name        : Os_KernIocRead                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function read data through IOC                 **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : IocID                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : data                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaIocUnqueuedCfg, Os_Ioc_Count_Unqueued         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock(), memcpy()    **
*******************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_KernIocRead(uint32 IocID,
                                         P2VAR(uint8, AUTOMATIC, OS_VAR) data[])
{
  StatusType LddStatusReturn;
  P2CONST(Os_IocUnqueuedCfgType, AUTOMATIC, OS_CONST) LpCfg;
  P2CONST(Os_IocBufType, AUTOMATIC, OS_CONST) LpBuf;
  uint32 LulDataCount;

  /* check IOC ID */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_ID_ERROR(IocID, Os_Ioc_Count_Unqueued, LddStatusReturn);
  /* check null pointer */
  /* polyspace<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_INVALID_BUF_ERROR(data, LddStatusReturn);

  /* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if(LddStatusReturn == IOC_E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    Os_GetSpinlock(OS_IOCLOCKBASE_UNQUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2:Not a defect> */
    #endif
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* read IOC data */
    LpCfg = &Os_GaaIocUnqueuedCfg[IocID];
    for(LulDataCount = OS_ZERO; LulDataCount < LpCfg->ulDataCount;
                                                                 LulDataCount++)
    {
      LpBuf = &(LpCfg->pBuffer[LulDataCount]);
      /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      /* polyspace:begin<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
      /* polyspace<RTE: STD_LIB : Not a defect : No Action Planned > function is called with a valid arguments that are confirmed by testing */
      /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
      /* polyspace<MISRA-C3:D4.11:Not a defect:Justify with annotations> parameter is valid and verified manually */
      /* polyspace:begin<MISRA-C3:11.5:Not a defect:Justify with annotations> Type cast for memcpy is safe */
      /* polyspace:begin<MISRA-C3:11.8:Not a defect:Justify with annotations> Type cast for memcpy is safe */
      memcpy((uint8*)(data[LulDataCount]), (uint8*)(LpBuf->pIocBuf),
                                                  (Os_Size_T)LpBuf->ulDataSize);
      /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations>  It is used for consistency */
      /* polyspace:end<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
      /* polyspace:end<MISRA-C3:11.5:Not a defect:Justify with annotations> Type cast for memcpy is safe */
      /* polyspace:end<MISRA-C3:11.8:Not a defect:Justify with annotations> Type cast for memcpy is safe */
    }
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */

    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    Os_ReleaseSpinlock(OS_IOCLOCKBASE_UNQUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
  }
  /* polyspace:end<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */

  return LddStatusReturn;
}

/*******************************************************************************
** Function Name        : Os_KernIocWrite                                     **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function read data through IOC                 **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : IocID, data                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaIocUnqueuedCfg, Os_Ioc_Count_Unqueued         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock(), memcpy()    **
*******************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_KernIocWrite(uint32 IocID,
                                CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  StatusType LddStatusReturn;
  P2CONST(Os_IocUnqueuedCfgType, AUTOMATIC, OS_CONST) LpCfg;
  P2CONST(Os_IocBufType, AUTOMATIC, OS_CONST) LpBuf;
  uint32 LulDataCount;

  /* check IOC ID */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_ID_ERROR(IocID, Os_Ioc_Count_Unqueued, LddStatusReturn);
  /* check null pointer */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_INVALID_BUF_ERROR(data, LddStatusReturn);

  /* polyspace:begin<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  if(LddStatusReturn == IOC_E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    Os_GetSpinlock(OS_IOCLOCKBASE_UNQUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
    /* read IOC data */
    LpCfg = &Os_GaaIocUnqueuedCfg[IocID];
    for(LulDataCount = OS_ZERO; LulDataCount < LpCfg->ulDataCount;
                                                                 LulDataCount++)
    {
      LpBuf = &(LpCfg->pBuffer[LulDataCount]);
      /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
      /* polyspace:begin<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
      /* polyspace<RTE: STD_LIB : Not a defect : No Action Planned > function is called with a valid arguments that are confirmed by testing */
      /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
      /* polyspace<MISRA-C3:D4.11:Not a defect:Justify with annotations> parameter is valid and verified manually */
      memcpy((uint8*)(LpBuf->pIocBuf), data[LulDataCount],
                                             (Os_Size_T)LpBuf->ulDataSize);
      /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations>  It is used for consistency */
      /* polyspace:end<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
    }
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    Os_ReleaseSpinlock(OS_IOCLOCKBASE_UNQUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
  }
  /* polyspace:end<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */

  return LddStatusReturn;
}

/*******************************************************************************
** Function Name        : Os_KernIocReceive                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function receive data through IOC              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : IocID                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : data                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaIocQueuedCfg, Os_Ioc_Count_Queued             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock(), memcpy()    **
*******************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_KernIocReceive(uint32 IocID,
                                         P2VAR(uint8, AUTOMATIC, OS_VAR) data[])
{
  StatusType LddStatusReturn;
  P2VAR(Os_IocQueuedCfgType, AUTOMATIC, OS_VAR) LpCfg;
  P2CONST(Os_IocBufType, AUTOMATIC, OS_CONST) LpBuf;
  uint32 LulDataCount;
  uint32 LulStartIdx;

  /* check IOC ID */
  /* polyspace<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_ID_ERROR(IocID, Os_Ioc_Count_Queued, LddStatusReturn);
  /* check null pointer */
  /* polyspace<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_INVALID_BUF_ERROR(data, LddStatusReturn);

  /* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<DEFECT : USELESS_IF : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "Value of LddStatusReturn depends on User-Configuration" */
  /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if(LddStatusReturn == IOC_E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* polyspace<MISRA-C3:10.7:Not a defect:Justify with annotations> composite expression is verified manually */
    Os_GetSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
    /* receive IOC data */
    LpCfg = &Os_GaaIocQueuedCfg[IocID];
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    if(LpCfg->ulQueueCount == OS_ZERO)
    {
      /* Queue is empty */
      LddStatusReturn = (StatusType)IOC_E_NO_DATA;
    }
    else
    {
      for(LulDataCount = OS_ZERO; LulDataCount < LpCfg->ulDataCount;
	                                                             LulDataCount++)
      {
        LpBuf = &(LpCfg->pBuffer[LulDataCount]);
        /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
        LulStartIdx = LpCfg->ulQueueRead * LpBuf->ulDataSize;

        /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
        /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Array index comes from constant value */
        /* polyspace:begin<RTE:OVFL:Not a defect:No action planned> It is defined from statically defined value */
        /* polyspace:begin<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
        /* polyspace:begin<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        /* polyspace:begin<MISRA-C3:11.5:Not a defect:Justify with annotations> Type cast for memcpy is safe */
        /* polyspace:begin<MISRA-C3:11.8:Not a defect:Justify with annotations> Type cast for memcpy is safe */
        /* polyspace<RTE:STD_LIB:Not a defect:No action planned> It is used for consistency */
        /* polyspace<MISRA-C3:D4.11:Not a defect:Justify with annotations> parameter is valid and verified manually */
        memcpy((uint8*)(data[LulDataCount]),
        		(uint8*)(&((uint8*)LpBuf->pIocBuf)[LulStartIdx]), (Os_Size_T)LpBuf->ulDataSize);
        /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        /* polyspace:end<RTE:OVFL:Not a defect:No action planned> It is defined from statically defined value */
        /* polyspace:end<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
        /* polyspace:end<MISRA-C:17.4:Not a defect:Justify with annotations> Array index comes from constant value */
        /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations>  It is used for consistency */
        /* polyspace:end<MISRA-C3:11.5:Not a defect:Justify with annotations> Type cast for memcpy is safe */
        /* polyspace:end<MISRA-C3:11.8:Not a defect:Justify with annotations> Type cast for memcpy is safe */
      }

      LpCfg->ulQueueRead = (LpCfg->ulQueueRead < (LpCfg->ulQueueLen - OS_ONE)) ?
                                        (LpCfg->ulQueueRead + OS_ONE) : OS_ZERO;
      LpCfg->ulQueueCount--;

      if(LpCfg->blDataLost == OS_TRUE)
      {
        LpCfg->blDataLost = OS_FALSE;
        LddStatusReturn = IOC_E_LOST_DATA;
      }
    }
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */

    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* polyspace<MISRA-C3:10.7:Not a defect:Justify with annotations> composite expression is verified manually */
    Os_ReleaseSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
  }
  /* polyspace:end<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:end<DEFECT : USELESS_IF : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace-end CERT-C:MSC12-C [Not a defect:Low] "Value of LddStatusReturn depends on User-Configuration" */
  /* polyspace:end<MISRA-C3:14.3> */
  return LddStatusReturn;
}

/*******************************************************************************
** Function Name        : Os_KernIocSend                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function send data through IOC                 **
**                                                                            **
** Sync/Async           : Asynchronous                                        **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : IocID                                               **
**                                                                            **
** InOut parameter      : data                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaIocQueuedCfg, Os_Ioc_Count_Queued             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock(), memcpy()    **
*******************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_KernIocSend(uint32 IocID,
                                CONSTP2CONST(uint8, AUTOMATIC, OS_CONST) data[])
{
  StatusType LddStatusReturn;
  P2VAR(Os_IocQueuedCfgType, AUTOMATIC, OS_VAR) LpCfg;
  P2CONST(Os_IocBufType, AUTOMATIC, OS_CONST) LpBuf;
  uint32 LulDataCount;
  uint32 LulStartIdx;

  /* check IOC ID */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_ID_ERROR(IocID, Os_Ioc_Count_Queued, LddStatusReturn);
  /* check null pointer */
  /* polyspace<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_INVALID_BUF_ERROR(data, LddStatusReturn);

  /* polyspace:begin<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
  /* polyspace:begin<DEFECT : USELESS_IF : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "Value of LddStatusReturn depends on User-Configuration" */
  /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if(LddStatusReturn == IOC_E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* polyspace<MISRA-C3:10.7:Not a defect:Justify with annotations> composite expression is verified manually */
    Os_GetSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
    /* receive IOC data */
    LpCfg = &Os_GaaIocQueuedCfg[IocID];
    if(LpCfg->ulQueueCount >= LpCfg->ulQueueLen)
    {
      /* Queue is full */
      LpCfg->blDataLost = OS_TRUE;
      LddStatusReturn = (StatusType)IOC_E_LIMIT;
    }
    else
    {
      for(LulDataCount = OS_ZERO; LulDataCount < LpCfg->ulDataCount;
	                                                             LulDataCount++)
      {
        LpBuf = &(LpCfg->pBuffer[LulDataCount]);
        /* polyspace<RTE:NIV:Not a defect:No Action Planned> variable is initialized and code is verified manually */
        LulStartIdx = LpCfg->ulQueueWrite * LpBuf->ulDataSize;
        /* polyspace:begin<MISRA-C:10.1:Not a defect:Justify with annotations> It is used for consistency */
        /* polyspace<RTE:OVFL:Not a defect:No action planned> It is defined from statically defined value */
        /* polyspace<RTE:STD_LIB:Not a defect:No action planned> It is used for consistency */
        /* polyspace<RTE:NIP:Not a defect:No Action Planned> ptr points to a valid value and code is verified manually */
        /* polyspace<MISRA-C:17.4:Not a defect:Justify with annotations> Increment operator on pointer used to achieve better throughput */
        /* polyspace<MISRA-C3:D4.11:Not a defect:Justify with annotations> parameter is valid and verified manually */
        /* polyspace<MISRA-C3:11.5:Not a defect:Justify with annotations> Type cast for memcpy is safe */
        memcpy((uint8*)(&((uint8*)LpBuf->pIocBuf)[LulStartIdx]),
                              data[LulDataCount], (Os_Size_T)LpBuf->ulDataSize);
        /* polyspace:end<MISRA-C:10.1:Not a defect:Justify with annotations>  It is used for consistency */
      }
      LpCfg->ulQueueWrite =
        (LpCfg->ulQueueWrite < (LpCfg->ulQueueLen - OS_ONE)) ?
                                       (LpCfg->ulQueueWrite + OS_ONE) : OS_ZERO;
      LpCfg->ulQueueCount++;
    }
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* polyspace<MISRA-C3:10.7:Not a defect:Justify with annotations> composite expression is verified manually */
    Os_ReleaseSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
  }
  /* polyspace:end<RTE:UNR:Not a defect:No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:end<MISRA-C3:D4.1> */
  /* polyspace:end<MISRA-C3:18.1> */
  /* polyspace:end<DEFECT : USELESS_IF : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace:end<MISRA-C3:14.3> */

  return LddStatusReturn;
}

/*******************************************************************************
** Function Name        : Os_KernIocEmptyQueue                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function empty Queue                           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : IocID                                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : Std_ReturnType                                      **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaIocQueuedCfg, Os_Ioc_Count_Queued             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_GetSpinlock(), Os_ReleaseSpinlock()              **
*******************************************************************************/
FUNC(Std_ReturnType, OS_CODE) Os_KernIocEmptyQueue(uint32 IocID)
{
  StatusType LddStatusReturn;
  P2VAR(Os_IocQueuedCfgType, AUTOMATIC, OS_VAR) LpCfg;

  /* check IOC ID */
  /* polyspace<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  OS_CHECK_IOC_ID_ERROR(IocID, Os_Ioc_Count_Queued, LddStatusReturn);

  /* polyspace:begin<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace-begin CERT-C:MSC12-C [Not a defect:Low] "Value of LddStatusReturn depends on User-Configuration" */
  /* polyspace:begin<MISRA-C3:2.1:Not a defect:Justify with annotations> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<MISRA-C3:14.3:Not a defect:Justify with annotations> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:begin<DEFECT:DEAD_CODE:Not a defect:Justify with annotations> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  if(LddStatusReturn == IOC_E_OK)
  {
    #if (OS_MULTICORE == STD_ON)
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    /* polyspace<MISRA-C3:10.7:Not a defect:Justify with annotations> composite expression is verified manually */
    Os_GetSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
    /* polyspace:begin<MISRA-C3:D4.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* polyspace:begin<MISRA-C3:18.1:Not a defect:Justify with annotations> ptr points to a valid value and code is verified manually */
    /* receive IOC data */
    LpCfg = &Os_GaaIocQueuedCfg[IocID];
    LpCfg->ulQueueRead = OS_ZERO;
    LpCfg->ulQueueWrite = OS_ZERO;
    LpCfg->ulQueueCount = OS_ZERO;
    LpCfg->blDataLost = OS_FALSE;
    #if (OS_MULTICORE == STD_ON)
    /* polyspace<MISRA-C3:10.3:Not a defect:Justify with annotations> macro is not effected to result of expression */
    /* polyspace:begin<MISRA-C3:2.2:Not a defect:Justify with annotations> could be reached according to user configuration */
    Os_ReleaseSpinlock(OS_IOCLOCKBASE_QUEUED+IocID);
    /* polyspace:end<MISRA-C3:2.2> */
    #endif
    /* polyspace:end<MISRA-C3:D4.1> */
    /* polyspace:end<MISRA-C3:18.1> */
  }
  /* polyspace:end<RTE:UNR:Not a defect : No Action Planned> Because error check characteristic, unreachable code occurs. But this code has already been verified and no impact of this rule violation */
  /* polyspace:end<DEFECT : DEAD_CODE : Not a defect : Justify with annotations > Value of LddStatusReturn depends on User-Configuration */
  /* polyspace-end CERT-C:MSC12-C [Not a defect:Low] "Value of LddStatusReturn depends on User-Configuration" */
  /* polyspace:end<MISRA-C3:2.1> */
  /* polyspace:end<MISRA-C3:14.3> */
  /* polyspace:end<DEFECT:DEAD_CODE> */

  return LddStatusReturn;
}

/*******************************************************************************
** Function Name        : Os_DoIocPullCB                                      **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function pull IOC callback function            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : pIocPullCB, recvAppID                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GddAppId                                         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        pIocPullCB()                                        **
*******************************************************************************/
FUNC(void, OS_CODE) Os_DoIocPullCB(
    P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID)
{
  ApplicationType backupAppID;
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* Get The coreID */
  OS_GET_CORE_ID(OS_CORE_ID);

  /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
  /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
  /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
  backupAppID = Os_GddAppId[OS_CORE_ID];
  Os_GddAppId[OS_CORE_ID] = recvAppID;

  if(pIocPullCB != NULL_PTR){
    /* polyspace<RTE: COR : Not a defect : No Action Planned > function ptr points to a valid function and code is manually checked*/
    pIocPullCB();
  }
  Os_GddAppId[OS_CORE_ID] = backupAppID;
}

/*******************************************************************************
** Function Name        : Os_KernIocPullCB                                    **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This function pull IOC callback function            **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Re-entrant                                          **
**                                                                            **
** Input Parameters     : pIocPullCB, recvAppID                               **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : void                                                **
**                                                                            **
** Preconditions        : NA                                                  **
**                                                                            **
** Remarks              : Global Variable(s) :                                **
**                        Os_GaaStaticApplication                             **
**                                                                            **
**                        Function(s) invoked    :                            **
**                        Os_SendIocPullCB(), Os_DoIocPullCB()                **
*******************************************************************************/
FUNC(void, OS_CODE) Os_KernIocPullCB(
		P2FUNC(void, OS_CONST, pIocPullCB) (void), ApplicationType recvAppID)
{
  #if (OS_MULTICORE == STD_ON)
  CoreIDType OS_CORE_ID;
  #endif

  /* polyspace<RTE:UNR:Not a defect:No Action Planned> NULL pointer check */
  if(pIocPullCB != NULL_PTR){
    /* Get The coreID */
    OS_GET_CORE_ID(OS_CORE_ID);
    /* Set the return status value to "E_OK" */

    /* Store the static task corresponding to TaskID in local pointer */
    #if (OS_MULTICORE == STD_ON)
    /* Check if new task belongs to same core */
    /* polyspace<RTE: OBAI : Not a defect : Justify with annotations > configured array index */
    /* polyspace<MISRA-C3:D4.1:Not a defect:Justify with annotations> index is valid and verified manually */
    /* polyspace<MISRA-C3:18.1:Not a defect:Justify with annotations> index is valid and verified manually */
    if (Os_GaaStaticApplication[recvAppID].ddCoreID != OS_CORE_ID)
    {
      /* Call Os_SendActivateTask to schedule task on respective core */
      Os_SendIocPullCB(pIocPullCB, recvAppID);
    } /* End of if (LpStaticTask->ddCoreId != OS_CORE_ID) */
    else
    #endif /* End of if (OS_MULTICORE == STD_ON) */
    {
      /* Call Os_DoIocPullCB */
      Os_DoIocPullCB(pIocPullCB, recvAppID);
    }
  }
}
#endif /* if (OS_APPLICATION == STD_ON) */

#define OS_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**              PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                  **
*******************************************************************************/
/* polyspace:end<RTE:IDP:Not a defect:No action planned> It is defined from statically defined value */
/* polyspace:end<MISRA-C3:20.1> */
/* polyspace:end<MISRA-C3:D4.14:Not a defect:Justify with annotations> "Already verified value" */

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
