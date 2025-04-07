/* polyspace +1 MISRA-C3:1.1 [Justified:Low] "No exceed the macro limits" */
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
**  SRC-MODULE: NvM_Process.c                                                 **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR NvM Module                                            **
**                                                                            **
**  PURPOSE   : Implementation of Internal functionality of NvM Module :      **
**              NvM_UpdateRamStateStatus                                      **
**              NvM_CalcBlkNumber                                             **
**              NvM_UpdateGlobalVars                                          **
**              NvM_EndProcessBlock                                           **
**              NvM_QueueSwap                                                 **
**              NvM_CRCSIDCancelJob                                           **
**              NvM_QueueCRCSIDblocks                                         **
**              NvM_CrcImmQueuePosClear                                       **
**              NvM_CrcStdQueuePosClear                                       **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision    Date           By          Description                         **
********************************************************************************
** 1.6.2       18-Aug-2022   Yun  YJ      Redmine #37103                      **
** 1.6.0       28-Mar-2022   Yun  YJ      Redmine #34586                      **
** 1.5.4       30-Dec-2021   JHLim        Redmine #33331                      **
** 1.5.1       30-Dec-2020   Yun YJ       Redmine #27374                      **
** 1.3.4       11-Sep-2017   Yun YJ       Redmine #9669                       **
** 1.3.3       16-Nov-2016   Song CY      Redmine #6680                       **
** 1.3.2       10-Oct-2016   Song CY      Redmine #6215                       **
** 1.3.0       25-Jul-2016   Song CY      Redmine #3883                       **
** 1.2.6       28-Jun-2016  Song CY       Redmine #5334                       **
** 1.2.3       24-Mar-2016   Song CY      Redmine #4276                       **
** 1.2.2       11-Feb-2016  Song CY       Redmine #4183                       **
** 1.2.1       12-Jan-2016   Song CY      Redmine 3857, Change QueueClesr     **
**                                        Position before Callback            **
** 1.1.8       02-Oct-2015   Song CY      Correct RunTime Error Violation     **
** 1.1.7       09-Jul-2015  Song CY       As per RedMine 2265, Change         **
**                                        CRC & SID Logic                     **
** 1.1.6       03-Mar-2015  Song CY       As per RedMine 2209, Avoid crc block**
**                                        of rom block in dataset             **
** 1.1.6                                  As per RedMine 2216, Remove version **
**                                        Information                         **
** 1.1.4       02-Dec-2014  Song CY       RedMine 1719, Update for PolySpace  **
** 1.1.0     18-Apr-2014   Song CY     RedMine718 Version is updated          **
** 1.0.9       17-Dec-2013    Song CY   Modify Cancel Defect                  **
** 1.0.8       30-Sep-2013    Song CY   Update for Library                    **
** 1.0.0       25-Jan-2013    CY Song     Initial version                     **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/*
  polyspace-begin MISRA-C3:1.1:Not a defect:Justify with annotations> Needed for AR/SW version check
  polyspace:begin<RTE:IDP:Not a defect:Justify with annotations > configured memory access index
  polyspace-begin MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification"
*/
/* polyspace-begin RTE:UNR [Justified:Low] "Not a defect" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "NvM.h"                    /* NvM header file */
#include "NvM_Ram.h"                /* Global variables header file */
#include "NvM_Config.h"
#include "NvM_Process.h"
#include "NvM_ScanQueue.h"          /* Internal function header file */
#if(NVM_DEMERROR_REPORT == STD_ON)
#include "NvM_Dem_Cfg.h"                            /* Dem header file */
#endif
#if(NVM_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                            /* Det header file */
#endif
/* Internal function header files */
#include "NvM_ReadAll.h"

#include "BswM_NvM.h"              /* BswM_NvM header file */
#include "SchM_NvM.h"              /* SchM_NvM header file */

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define NVM_START_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
** Function Name        : NvM_IsRamBlockStatusSupported                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This is the internal function that confirms whether **
**                        RamBlockStatus is supported                         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : Block Index                                         **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : E_OK, E_NOT_OK                                      **
**                                                                            **
** Preconditions        : NvM should be initialized                           **
**                                                                            **
** Remarks              :                                                     **
*******************************************************************************/
#if (NVM_RAMBLOCKSTATUS_SUPPORT == STD_ON)
FUNC(Std_ReturnType, NVM_CODE) NvM_IsRamBlockStatusSupported(NvM_BlockIdType BlockId)
{
  Std_ReturnType retVal = E_NOT_OK;
  
  if (BlockId >= NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
  {
    NVM_REPORT_ERROR(NVM_ISRAMBLOCKSTATUSSUPPORTED_SID, NVM_E_PARAM_BLOCK_ID);
  }
  else
  {
    /* [SWS_NvM_00240] The function NvM_SetRamBlockStatus shall only work on
     * NVRAM blocks with a permanently configured RAM block or on NVRAM blocks
     * configured to support explicit synchronization, that have
     * NvMBlockUseSetRamBlockStatus enabled and shall have no effect to other NVRAM
     * blocks.
     */      
#if (NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)
    if (
      (NvM_GaaBlkDescTbl[BlockId].usBlkParams & NVM_BLOCK_USE_SYNC_MECHANISM_ENABLE) 
      == NVM_BLOCK_USE_SYNC_MECHANISM_ENABLE)
    {
      retVal = E_OK;
    }
#endif

#if (NVM_RAM_BLOCK_DATA_ADDRESS == STD_ON)    
    if (NULL_PTR != NvM_GaaBlkDescTbl[BlockId].pRamBlkData)
    {
      retVal = E_OK;
    }
#endif

  }

  return retVal;
}

/*******************************************************************************
** Function Name        : NvM_UpdateRamStateStatus                            **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : This is the internal function to change the RAM     **
**                        status                                              **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : Status                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NvM should be initialized                           **
**                                                                            **
** Remarks              : Global Variable(s)     : NvM_GaaRamStatus,          **
**                        NvM_GpNvmBlkDescTbl, NvM_GddBlockIdx,               **
**                                                                            **
**                        Function(s) invoked:                                **
**                        SchM_Exit_NvM_RAM_STATUS_PROTECTION()               **
**                        SchM_Enter_NvM_RAM_STATUS_PROTECTION()              **
*******************************************************************************/

FUNC(void, NVM_CODE) NvM_UpdateRamStateStatus(NvM_BlockIdType BlockId, uint8 Status)
{
  if (BlockId >= NVM_TOTAL_NUM_OF_NVRAM_BLOCKS)
  {
    NVM_REPORT_ERROR(NVM_UPDATERAMSTATESTATUS_SID, NVM_E_PARAM_BLOCK_ID);
  }
  else
  {
    if (E_OK == NvM_IsRamBlockStatusSupported(BlockId))
    {
      if (
        (NVM_INVALID_UNCHANGED  == Status) ||
        (NVM_VALID_UNCHANGED    == Status) ||
        (NVM_VALID_CHANGED      == Status)
      )
      {
        SchM_Enter_NvM_RAM_STATUS_PROTECTION();
        NvM_GaaRamStatus[BlockId] = 
          (NvM_GaaRamStatus[BlockId] & NVM_CLEAR_RAM_INTERNAL_STATE) | Status;
        SchM_Exit_NvM_RAM_STATUS_PROTECTION();
      }
      else
      {
        NVM_REPORT_ERROR(NVM_UPDATERAMSTATESTATUS_SID, NVM_E_PARAM_DATA);
      }
    } 
  }
} /* End of function body */

#endif

/*******************************************************************************
** Function Name        : NvM_CalcBlkNumber                                   **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to be used to calculate the block number   **
**                        based on Block Management type.                     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LusBlkNumber                                        **
**                                                                            **
** Preconditions        : NvM should be initialized.                          **
**                                                                            **
** Remarks              : Global Variable(s)     : NvM_GenBlkMngmntType,      **
**                        NvM_GpNvmBlkDescTbl, NvM_GddReStatus,               **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
FUNC(uint16, NVM_CODE) NvM_CalcBlkNumber(void)
{
  uint16 LusBlkNumber;

  if (NvM_GpNvmBlkDescTbl != NULL_PTR)
  {
    uint8 LucIndex;

    #if(NVM_DATASET_PRESENT == STD_ON)
    if(NvM_GenBlkMngmntType == NVM_BLOCK_DATASET)
    {
      /* Update the index to value in RAM index field */
      if (NvM_GpNvmBlkDescTbl->DataSetIndexPos < NVM_NUM_OF_DATASET_BLOCKS)
      {
        LucIndex = NvM_GaaDataSetIndex[NvM_GpNvmBlkDescTbl->DataSetIndexPos];
      }
      else
      {
        LucIndex = 0U;      
        NVM_REPORT_ERROR(NVM_CALCRCSID_SID, NVM_E_BLOCK_CONFIG);        
      }                                                           
    }
    else
    #endif
    if(NvM_GenBlkMngmntType == NVM_BLOCK_REDUNDANT)
    {
      if (NvM_RedundantBlockStatus != NVM_REDUNDANT_NOT_CHECKED_BOTH_BLOCK)
      {
        if (NvM_RedundantBlockWriteOrder != NVM_REDUNDANT_SECOND_BLOCK)
        {
          /* Update the index to one for 2nd NV block of Redundant block */
          LucIndex = NVM_ONE;
        }
        else
        {
          LucIndex = NVM_ZERO;
        }
      }
      else
      {
        if (NvM_RedundantBlockWriteOrder != NVM_REDUNDANT_SECOND_BLOCK)
        {
          /*
           * Update the index to one for Native block and for 1st NV block of
           * Redundant block
           */
          LucIndex = NVM_ZERO;
        }
        else
        {
          LucIndex = NVM_ONE;
        }
      }
    }
    else /* (NvM_GenBlkMngmntType == NVM_BLOCK_NATIVE) */
    {
      LucIndex = NVM_ZERO;
    }
    
    LusBlkNumber = NvM_GpNvmBlkDescTbl->usNvBlkBaseNumber + LucIndex;
  }
  else
  {
    LusBlkNumber = NVM_ZERO;
    
    NVM_REPORT_ERROR(NVM_CALCRCSID_SID, NVM_E_PARAM_POINTER);
  }
  return(LusBlkNumber);

} /* End of function body */

/*******************************************************************************
** Function Name        : NvM_UpdateGlobalVars                                **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to be used to update global variables.     **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NvM should be initialized                           **
**                                                                            **
**                                                                            **
** Remarks              :Global Variable(s)     : NvM_GenBlkMngmntType,       **
**                       NvM_GpNvmBlkDescTbl                                  **
**                        Function(s) invoked   : None                        **
*******************************************************************************/
FUNC(void, NVM_CODE) NvM_UpdateGlobalVars(void)
{
  /* Update the commonly used Global variables */
  if (NvM_GpNvmBlkDescTbl != NULL_PTR)
  {
    NvM_GusBlockLength = NvM_GpNvmBlkDescTbl->usNvBlkDataLength;

    NvM_GenBlkMngmntType = NvM_GpNvmBlkDescTbl->enBlkMngmntType;

    if((NvM_GucState == NVM_READALL_SID) || (NvM_GucState == NVM_WRITEALL_SID))
    {
#if(NVM_RAM_BLOCK_DATA_ADDRESS == STD_ON)
      /* polyspace +3 MISRA-C3:11.5 [Not a defect:Low] "No Impact of this rule violation (AUTOSAR Standard : NVM455, EA087)" */	
      /* polyspace +2 CERT-C:EXP36-C [Justified:Low] "Implemented according to AUTOSAR specification NVM455,NVM454,NVM456,NVM539,NVM540, NVM734" */    
      NvM_GpBufferToRead = (uint8*)NvM_GpNvmBlkDescTbl->pRamBlkData;
      NvM_GpBufferToWrite = (const uint8*)NvM_GpNvmBlkDescTbl->pRamBlkData;
#endif
    }
    /* Clear the Redundant status flag  */
    NvM_RedundantBlockStatus = NVM_REDUNDANT_NOT_CHECKED_BOTH_BLOCK;
    NvM_RedundantBlockWriteOrder = NVM_REDUNDANT_FIRST_BLOCK;
  }
  else
  {
    #if(NVM_DEV_ERROR_DETECT == STD_ON)
    (void)Det_ReportError(NVM_MODULE_ID, NVM_INSTANCE_ID,
      NVM_CALCRCSID_SID, NVM_E_PARAM_POINTER);
    #endif
  }
} /* End of function body */

/*******************************************************************************
** Function Name        : NvM_EndProcessBlock                                 **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function to end the processing of any request.      **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : RequestResult                                       **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : NvM should be initialized                           **
**                                                                            **
** Remarks              : Global Variable(s)     : NvM_GucState,              **
**                        NvM_GaaRamStatus, NvM_GddBlockIdx, NvM_GucSubState, **
**                        NvM_GucReadAllState, NvM_GblHighPriorityRequest     **
**                        NvM_GucWriteAllSubState, NvM_GucNotifiedGlobalStatus**
**                        NvM_GddReStatus, NvM_GpNvmBlkDescTbl,               **
**                        NvM_GblRestoreFlag, NvM_GucWriteVerify              **
**                        NvM_GusIntegrityFailed, NvM_GusReqFailed            **
**                        Function(s) invoked    : Dem_ReportErrorStatus()    **
**                        SchM_Enter_NvM_RAM_STATUS_PROTECTION,               **
**                        SchM_Exit_NvM_RAM_STATUS_PROTECTION,                **
**                        BswM_NvM_CurrentBlockMode,NvM_CrcImmQueuePosClear   **
**                        NvM_CrcStdQueuePosClear                             **
*******************************************************************************/
FUNC(void, NVM_CODE) NvM_EndProcessBlock(NvM_RequestResultType
  RequestResult)
{
  P2CONST(NvM_BlkDescTbl, AUTOMATIC, NVM_CONST) LpBlkDescTbl;

  if (NvM_RedundantBlockOrderUndefined == NVM_TRUE)
  {
    NvM_RedundantBlockOrderUndefined = NVM_FALSE;    
    
    NvM_GucState = NVM_WRITEBLOCK_SID;
    NvM_GucSubState = NVM_WRITE_NVBLOCK;
    
    NvM_GpBufferToWrite = NvM_GpBufferToWriteOld;    
    NvM_RedundantBlockStatus = NVM_REDUNDANT_NOT_CHECKED_BOTH_BLOCK;
  }
  else if (NvM_GddBlockIdx < NvM_GusTotalNumOfBlock)
  {
    LpBlkDescTbl = &NvM_GaaBlkDescTbl[NvM_GddBlockIdx];
    /* Clear restoreFlag */
    NvM_GblRestoreFlag = (boolean)NVM_FALSE;
    if((NvM_GucState != NVM_READALL_SID) && (NvM_GucState != NVM_WRITEALL_SID))
    {
      #if(NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1)
      #if(NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON)
      if((NvM_GucState == NVM_WRITEBLOCK_SID) &&
      (LpBlkDescTbl->ucBlkJobPriority == NVM_IMM_PRIORITY))
      {
        /* Clear the Queue for the particular request */
        NvM_ImmQueuePosClear(NvM_GddBlockIdx);
      }
      else
      #endif
      {
        NvM_StdQueuePosClear(NvM_GddBlockIdx);
      }
      #endif
    }
    else
    {
      if(RequestResult != NVM_REQ_OK)
      {
#if (NVM_DYNAMIC_CONFIGURATION == STD_OFF)
        if ( 
          (NvM_GddBlockIdx == NVM_CONFIGURATION_BLOCK_ID) &&
          (NvM_GucState == NVM_READALL_SID)
        )
        {
          /* [NVM248] The job of the function NvM_ReadAll shall ignore a configuration ID 
           * mismatch and behave normal if NvMDynamicConfiguration == FALSE [NVM028]. */
        }
        else
#endif
        {         
          /* Update the Global status in case of ReadAll/WriteAll */
           NvM_GucNotifiedGlobalStatus = NVM_REQ_NOT_OK;
        }
      }
    }
    /* Update the block specific RAM status */
    SchM_Enter_NvM_RAM_STATUS_PROTECTION();
    {
      NvM_GaaRamStatus[NvM_GddBlockIdx] =
      ((NvM_GaaRamStatus[NvM_GddBlockIdx] & NVM_NOT_ERROR_BIT_MASK)
        | (RequestResult));       
    }
    SchM_Exit_NvM_RAM_STATUS_PROTECTION();
    #if(NVM_DEMERROR_REPORT == STD_ON)
    if((RequestResult == NVM_REQ_NOT_OK)
      #if(NVM_WRITE_VERIFICATION == STD_ON)
      && (NvM_GucWriteVerify == NVM_ZERO)
      #endif
    )
    {
      #if(NVM_DEMERROR_REPORT == STD_ON)
      /* Report failure of job request to DEM */
      Dem_ReportErrorStatus(NvM_GusReqFailed, DEM_EVENT_STATUS_FAILED);
      #endif
    }
    else if(RequestResult == NVM_REQ_INTEGRITY_FAILED)
    {
        #if(NVM_DEMERROR_REPORT == STD_ON)
        /* Report failure of job request to DEM */
        Dem_ReportErrorStatus(NvM_GusIntegrityFailed, DEM_EVENT_STATUS_FAILED);
        #endif
    }
    else
    {
      /* Else loop added to avoid QAC warning */
    }
    #endif

    if(((LpBlkDescTbl->usBlkParams) & NVM_BSWM_BLOCK_STATUS_INFORMATION) ==
      NVM_BSWM_BLOCK_STATUS_INFORMATION)
    {
      BswM_NvM_CurrentBlockMode(NvM_GddBlockIdx, RequestResult);
    }

    #if (NVM_SINGLE_BLOCK_CALLBACK == STD_ON)
    if(LpBlkDescTbl->pNvMNotification_BlockId != NULL_PTR)
    {
      /* Invoke the single block callback notification, if configured */
      /* polyspace<RTE: COR : Not a defect : No Action Planned > function ptr points to a valid function */
      (void)LpBlkDescTbl->pNvMNotification_BlockId (NvM_GucState, RequestResult);
    }
    #endif

    /* Clear the Redundant status flag  */
    NvM_RedundantBlockStatus = NVM_REDUNDANT_NOT_CHECKED_BOTH_BLOCK;
    NvM_RedundantBlockWriteOrder = NVM_REDUNDANT_FIRST_BLOCK;

    /* Clear sub state */
    NvM_GucSubState = NVM_SUB_IDLE;

    if((NvM_GucState != NVM_READALL_SID) && (NvM_GucState != NVM_WRITEALL_SID))
    {
      /* Clear the main state only in case of single block requests */
      NvM_GucState = NVM_IDLE;
    }
    #if((NVM_API_CONFIG_CLASS  !=  NVM_API_CONFIG_CLASS_1) && \
        (NVM_JOB_PRIORITIZATION == STD_ON) && (NVM_IMM_JOB_PRIORITY == STD_ON))
    if (NvM_GblHighPriorityRequest == (boolean)NVM_TRUE)
    {
      if (NvM_GucReadAllState != NVM_IDLE)
      {
        NvM_GucState = NVM_READALL_SID;
        NvM_GucReadAllState = NVM_READALL_INIT;
      }
      else if (NvM_GucWriteAllSubState != NVM_WRITE_ALL_IDLE)
      {
        NvM_GucState = NVM_WRITEALL_SID;
      }
      else
      {
        /* Else loop added to avoid QAC warning */
      }
      NvM_GblHighPriorityRequest = (boolean)NVM_FALSE;
    }
    #endif
  }
  else
  {
    /* Do Nothing */
  }
} /* End of function body */

/*******************************************************************************
** Function Name        : NvM_QueueSwap                                       **
**                                                                            **
** Service ID           : NA                                                  **
**                                                                            **
** Description          : Function is to  Swap the request in the Queue       **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy          : Non-Reentrant                                       **
**                                                                            **
** Input Parameters     : RequestResult                                       **
**                                                                            **
** InOut parameter      : QueEnDis, QueStartPos                               **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : LucStdQueStartPos                                   **
**                                                                            **
** Preconditions        : NvM should be initialized                           **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                                                                            **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(NVM_BLOCK_USE_SYNC_MECHANISM == STD_ON)

FUNC(uint8, NVM_CODE) NvM_QueueSwap(uint8 QueStartPos, uint8 QueEnDis,
  P2VAR(NvM_JobQueue, AUTOMATIC, NVM_APPL_DATA)LpQueueBuffer)
{
  uint8 LucTempIndx;
  uint8 LucTempIndx2;
  uint8 LucStdQueStartPos;

  LucTempIndx =
    LpQueueBuffer[QueStartPos].ucNextIndex;

  LucStdQueStartPos = LucTempIndx;

  LpQueueBuffer[QueStartPos].ucPreviousIndex =
     LpQueueBuffer[QueStartPos].ucNextIndex;

  LucTempIndx2 = LpQueueBuffer[LucTempIndx].ucNextIndex;
  LpQueueBuffer[LucTempIndx].ucNextIndex =
    QueStartPos;

  if(QueEnDis > NVM_TWO)
  {
    LpQueueBuffer[QueStartPos].ucNextIndex = LucTempIndx2;
    LpQueueBuffer[LucTempIndx2].ucPreviousIndex = QueStartPos;
  } /* Checking and updating the local variables */

  return(LucStdQueStartPos);
} /* End of function body */

#endif

#define NVM_STOP_SEC_CODE 
#include "MemMap.h"
/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end RTE:UNR [Justified:Low] "Not a defect" */
/*
  polyspace-end MISRA-C3:1.1:Not a defect:Justify with annotations> Needed for AR/SW version check
  polyspace:end<RTE:IDP:Not a defect:Justify with annotations > configured memory access index
  polyspace-end MISRA-C3:20.1 [Justified:Low] "Implemented according to AUTOSAR specification"
*/

/*******************************************************************************
**                          End of File                                       **
*******************************************************************************/
