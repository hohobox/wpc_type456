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
**  SRC-MODULE: RamTst_Internal.c                                             **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR RAMTST                                                **
**                                                                            **
**  PURPOSE   : Ram Test API Functionality                                    **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By       Description                               **
********************************************************************************
** 1.3.5     19-Aug-2022   YJ Yun     Redmine #36918                          **
** 1.3.3     30-Dec-2021   JHLim      Redmine #33332                          **
** 1.3.2     30-Dec-2020   CY Song    RedMine #27378                          **
** 1.2.7     22-Jun-2017   YJ Yun     Redmine #6835                           **
** 1.2.7     15-Nov-2015   CY Song    Redmine #6608                           **
** 1.2.5     16-May-2016   CY Song    RedMine #4902                           **
** 1.2.3     05-Oct-2015   CY Song    Correct Misra Rule Error                **
** 1.0.4     17-Oct-2014   CY Song    Rd#1452 Correct PolySpace               **
** 1.0.3     06-Dec-2013   CY Song  Add SchM_Enter_RamTst_RAM_PROTECTION,     **
**                                  SchM_Exit_RamTst_RAM_PROTECTION and Library*
** 1.0.0     07-Jun-2013   CY Song          Initial Version                   **
*******************************************************************************/

/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C:11.3 [Justified:Low] "No Impact of this rule violation (uint8 data needs to be extracted from a uint32 address. the code is verified manually)" */
/*
polyspace:begin<RTE: NIV : Not a defect : Justify with annotations > Cannot initialize because of Application variable
polyspace:begin<RTE: IDP : Not a defect : Justify with annotations > configured memory access index
*/
/* polyspace-begin MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */
/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "RamTst_Internal.h"       /* Ram Test Module Internal Header File */
#include "RamTst_PCTypes.h"       /* Ram Test Module Internal Header File */
#include "RamTst.h"               /* Ram Test Module Internal Header File */
#include "RamTst_Config.h"
#include "RamTst_Crc.h"
#include "RamTst_Ram.h"
#include "SchM_RamTst.h"          /* SchM header file for data protection API*/

#if(RAMTST_DEV_ERROR_DETECT == STD_ON)
#include "Det.h"                 /* Ram Test Module Header File */
#endif
#if(RAMTST_DEMERROR_REPORT == STD_ON)
#include "RamTst_Dem_Cfg.h"
#endif

/*******************************************************************************
**                      Global Data Types                                     **
*******************************************************************************/

/*******************************************************************************
**                      Function Definitions                                  **
*******************************************************************************/
#define RAMTST_START_SEC_CODE
#include "MemMap.h"

#if(RAMTST_LOW_COVERAGE_TEST_SELECTED == STD_ON)
static FUNC(boolean, RAMTST_CODE) RamTst_ParityBit(RamTst_CellType Ramcell);
#endif

#if(RAMTST_MEDIUM_COVERAGE_TEST_SELECTED == STD_ON)
static FUNC(boolean, RAMTST_CODE)
                              RamTst_PatternChk(RamTst_CellType* RamCellAddress,
                  RamTstTestPolicy RamBlockTstPolicy, uint32 RamTstFillPattern);
#endif

/*******************************************************************************
** Function Name        : RamTst_ParityBit                                    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get parity of number Ramcell.           **
**                        It returns 1 if Ramcell has odd parity, and         **
**                        It returns 0 if Ramcell has even parity             **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : RamTst_CellType                                     **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                        Function(s) invoked    :                            **
*******************************************************************************/
#if(RAMTST_LOW_COVERAGE_TEST_SELECTED == STD_ON)
static FUNC(boolean, RAMTST_CODE) RamTst_ParityBit(RamTst_CellType Ramcell)
{
  boolean paritybit = (boolean)RAMTST_FALSE;
  RamTst_CellType CellVal = Ramcell;

  SchM_Enter_RamTst_RAM_PROTECTION();

  while (CellVal > RAMTST_ZERO)
  {
    if (paritybit != RAMTST_ZERO)
    {
      paritybit = (boolean)RAMTST_FALSE;
    }
    else
    {
      paritybit = (boolean)RAMTST_TRUE;
    }
    CellVal = CellVal & (CellVal - RAMTST_ONE);
  }

  SchM_Exit_RamTst_RAM_PROTECTION();

  return paritybit;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_ParityBitBckGrdTst                           **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get parity of number Ramcell.           **
**                        It returns RAMTST_PASSED if parity is correct       **
**                        It returns RAMTST_FAILED if parity is wrong         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : uint16                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                RamTst_GddBckGrdTstRamVar   **
**                                                RamTst_GaaBlkParam          **
**                        Function(s) invoked    :                            **
**                                                 Dem_ReportErrorStatus      **
*******************************************************************************/
#if(RAMTST_LOW_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_ParityBitBckGrdTst(RamTst_CellType * RamTstStrtAddress,
                                RamTst_NumberOfTestedCellsType RamTstNumOfCells)
{
 boolean LblRamCellTstResult;
 RamTst_CellType* LpAddress;
 RamTst_NumberOfBlocksType LddBlockIdx;
 RamTst_NumberOfTestedCellsType NumOfCells = RamTstNumOfCells;
 /* polyspace-begin ISO-17961:intptrconv [Justified:Low] "Function must convert from unsigned integer (address) to pointer type" */
 /* Pointer Initialized with Address of type RamTst_CellType */
 LpAddress = (RamTst_CellType*)RamTstStrtAddress;
 LddBlockIdx = RamTst_GddBckGrdTstRamVar.ddRunningBlockID - RAMTST_ONE;
 do
 {
    /* Invoke ParityBit Check API */
    /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address */
    LblRamCellTstResult = RamTst_ParityBit(*LpAddress);
    #if(RAMTST_PARITY_BIT == EVEN_PARITY)
    if(LblRamCellTstResult != RAMTST_ZERO)
    #endif
    #if(RAMTST_PARITY_BIT == ODD_PARITY)
    if(LblRamCellTstResult != RAMTST_ONE)
    #endif
    {
      /* Global Test Status is Failed */
      RamTst_GddBckGrdTstRamVar.blGblBckGrdTstError = RAMTST_FAILED;
      /* Block Test Status is Failed */
      RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_FAILED;

      if (RamTst_GulNumberOfBlocks > LddBlockIdx)
      {
        /* If atleast one Cell fails the Block status changed to NOT_OK */
        *RamTst_GaaBlkParam[LddBlockIdx].pTestBlockStatus =
                                                      RAMTST_RESULT_NOT_OK;
      }
      #if(RAMTST_DEMERROR_REPORT == STD_ON)
      /* Raise DEM Error and set the RamTst_GddTestStatus to Failed */
      Dem_ReportErrorStatus(RamTst_GusRamFailure, DEM_EVENT_STATUS_FAILED);
      #endif

      #if(RAMTST_TEST_ERROR_NOTIFICATION_SUPPORT == STD_ON)
      /* CallErrorNotification API */
      RAMTST_TEST_ERROR_NOTIFICATION();
      #endif
    }
    else
    {
      /* Block Test Status is Passed */
      RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_PASSED;
    }

    /* Point to next data byte */
    LpAddress=&LpAddress[RAMTST_ONE];
    /* Decrement Cell Count */
    NumOfCells--;

 }while (NumOfCells != RAMTST_ZERO);

 /* Save the Next Address */
 RamTst_GddBckGrdTstRamVar.pBckGrdAddress = LpAddress;
 /* polyspace-end ISO-17961:intptrconv [Justified:Low] "Function must convert from unsigned integer (address) to pointer type" */
 return LblRamCellTstResult;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_RunParityBitTst                              **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get parity of number Ramcell.           **
**                        It returns RAMTST_PASSED if parity is correct       **
**                        It returns RAMTST_FAILED if parity is wrong         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : uint16                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GaaBlkParam         **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(RAMTST_LOW_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_RunParityBitTst
                                       (RamTst_NumberOfBlocksType RamTstBlockId)
{
  uint8 LucParaId;
  uint32 LulEndAddr;

  boolean LblRamCellTstResult;
  RamTst_CellType* LpAddress;

  LblRamCellTstResult = RAMTST_FAILED;
  LucParaId = (uint8)RamTstBlockId - RAMTST_ONE;
  if (LucParaId < RamTst_GulNumberOfBlocks)
  {
    LpAddress =
            RamTst_GaaBlkParam[LucParaId].pRamTstStartAddress;
    LulEndAddr = RamTst_GaaBlkParam[LucParaId].ulRamTstEndAddress;
    do
    {
      /* Invoke ParityBit Check API */
      /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address  */
      LblRamCellTstResult = RamTst_ParityBit(*LpAddress);
      #if(RAMTST_PARITY_BIT == EVEN_PARITY)
      if(LblRamCellTstResult == RAMTST_ZERO)
      #endif
      #if(RAMTST_PARITY_BIT == ODD_PARITY)
      if(LblRamCellTstResult == RAMTST_ONE)
      #endif
      {
        LblRamCellTstResult = RAMTST_PASSED;
      }
      else
      {
        LblRamCellTstResult = RAMTST_FAILED;
      }

      /* If at least one cell fails return Error */
      if(LblRamCellTstResult == RAMTST_FAILED)
      {
        /* End the Loop */
        break;
      }
      else
      {
        /* Point to next data byte */
        LpAddress=&LpAddress[RAMTST_ONE];
      }

    }while ((uint32)LpAddress < LulEndAddr);
  }
  else
  {
    #if(RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
    RAMTST_RUNPARITYBITTST_SID, RAMTST_E_STATUS_FAILURE);
    #endif
  }

  return LblRamCellTstResult;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_PatternChk                                   **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to check the ram pattern test              **
**                        It returns 1 if Ramcell pattern check passed        **
**                        It returns 0 if Ramcell pattern check failed        **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : RamTst_CellType, RamBlockTstPolicy, uint32          **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     : None                       **
**                        Function(s) invoked    : None                       **
*******************************************************************************/
#if(RAMTST_MEDIUM_COVERAGE_TEST_SELECTED == STD_ON)
static FUNC(boolean, RAMTST_CODE) RamTst_PatternChk(RamTst_CellType* RamCellAddress,
                   RamTstTestPolicy RamBlockTstPolicy, uint32 RamTstFillPattern)
{
  volatile RamTst_CellType LddRamcellBckup;
  boolean LblRamCellTstResult;
  volatile RamTst_CellType* CellAddress;
  volatile RamTst_CellType*  CellAddress2;
  LblRamCellTstResult = RAMTST_FAILED;

  if (RamCellAddress != NULL_PTR)
  {
    SchM_Enter_RamTst_RAM_PROTECTION();
    /* Restore the CELL content if block test policy is non destructive */
    if(RamBlockTstPolicy == RAMTEST_NON_DESTRUCTIVE)
    {
      /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address  */
      LddRamcellBckup = *RamCellAddress;
    }
    else
    {
      /* fill RamTst_FillPattern in the cell content */
      LddRamcellBckup = RamTstFillPattern;
    }
     /* polyspace-begin ISO-17961:intptrconv [Justified:Low] "Function must convert from pointer type to unsigned integer (address) to handle memory" */
    if ((uint32)&CellAddress != (uint32)RamCellAddress)
    {
      /* polyspace-end ISO-17961:intptrconv [Justified:Low] "Function must convert from pointer type to unsigned integer (address) to handle memory" */
      CellAddress = RamCellAddress;
      /* WRITE RAM PATTERN 0 */
      /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address  */
      *CellAddress = RAMTST_PATTERN_TYPE_1;

      RAMTST_NOP();

      /* VERIFY WRITTEN RAM PATTERN */
      if (*CellAddress == RAMTST_PATTERN_TYPE_1)
      {
        /* WRITE RAM PATTERN 1 */
        *CellAddress = RAMTST_PATTERN_TYPE_2;

        RAMTST_NOP();

        /* VERIFY WRITTEN RAM PATTERN */
        if(*CellAddress == RAMTST_PATTERN_TYPE_2)
        {
          #if(RAMTST_CHK_TRANS_ONETOZERO == STD_ON)
          /* WRITE RAM PATTERN 0 */
          *CellAddress = RAMTST_PATTERN_ZERO;

          RAMTST_NOP();

          /* VERIFY WRITTEN RAM PATTERN */
          if(*CellAddress == RAMTST_PATTERN_ZERO)
          {
            LblRamCellTstResult = RAMTST_PASSED;
          }
          #else
          LblRamCellTstResult = RAMTST_PASSED;
          #endif
        }
      }
      /* Restore the cell content */
      *CellAddress = LddRamcellBckup;
    }
    else
    {
      CellAddress2 = RamCellAddress;
      /* WRITE RAM PATTERN 0 */
      /* polyspace<MISRA-C:21.1:Not a defect:No action planned> Configured memory address  */
      *CellAddress2 = RAMTST_PATTERN_TYPE_1;

      RAMTST_NOP();

      /* VERIFY WRITTEN RAM PATTERN */
      if(RAMTST_PATTERN_TYPE_1 == *CellAddress2)
      {
        /* WRITE RAM PATTERN 1 */
        *CellAddress2 = RAMTST_PATTERN_TYPE_2;

        RAMTST_NOP();

        /* VERIFY WRITTEN RAM PATTERN */
        if(RAMTST_PATTERN_TYPE_2 == *CellAddress2)
        {
          #if(RAMTST_CHK_TRANS_ONETOZERO == STD_ON)
          /* WRITE RAM PATTERN 0 */
          *CellAddress2 = RAMTST_PATTERN_ZERO;

          RAMTST_NOP();

          /* VERIFY WRITTEN RAM PATTERN */
          if(RAMTST_PATTERN_ZERO == *CellAddress2)
          {
            LblRamCellTstResult = RAMTST_PASSED;
          }
          #else
          LblRamCellTstResult = RAMTST_PASSED;
          #endif
        }
      }
      /* Restore the cell content */
      *CellAddress2 = LddRamcellBckup;
    }
    SchM_Exit_RamTst_RAM_PROTECTION();
  }
  return(LblRamCellTstResult);
}
#endif
/*******************************************************************************
** Function Name        : RamTst_PatternChkBckGrdTst                          **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get parity of number Ramcell.           **
**                        It returns RAMTST_PASSED if test is correct         **
**                        It returns RAMTST_FAILED if test is wrong           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : RamTst_NumberOfBlocksType                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GddBckGrdTstRamVar  **
**                                                 RamTst_GaaBlkParam         **
**                        Function(s) invoked    :                            **
**                                                 Dem_ReportErrorStatus      **
*******************************************************************************/
#if(RAMTST_MEDIUM_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_PatternChkBckGrdTst(RamTst_CellType *RamTstStrtAddress,
                                RamTst_NumberOfTestedCellsType RamTstNumOfCells)
{
  boolean LblRamCellTstResult;
  RamTst_CellType* LpAddress;
  RamTst_NumberOfBlocksType LddBlockIdx;
  RamTst_NumberOfTestedCellsType NumOfCells = RamTstNumOfCells;


  /* Pointer Initialized with Address of type RamTst_CellType */
  LblRamCellTstResult = RAMTST_FAILED;
  /* polyspace-begin ISO-17961:intptrconv CERT-C:EXP36-C [Justified:Low] "Function must convert from unsigned integer (address) to pointer type to handle memory" */
  /* polyspace +2 MISRA-C3:11.5 [Justified:Low] "Not a defect" */
  LpAddress = (RamTst_CellType*)RamTstStrtAddress;
  /* polyspace-end ISO-17961:intptrconv CERT-C:EXP36-C [Justified:Low] "Function must convert from unsigned integer (address) to pointer type to handle memory"" */
  LddBlockIdx = RamTst_GddBckGrdTstRamVar.ddRunningBlockID - RAMTST_ONE;
  do
  {
    if (LddBlockIdx < RamTst_GulNumberOfBlocks)
    {
      SchM_Enter_RamTst_PATTERN_CHECK_PROTECT();
      /* Invoke Pattern check API */
      LblRamCellTstResult = RamTst_PatternChk(LpAddress,
              RamTst_GaaBlkParam[LddBlockIdx].ddRamTstPolicy,
              RamTst_GaaBlkParam[LddBlockIdx].ulRamTstFillPattern);
      SchM_Exit_RamTst_PATTERN_CHECK_PROTECT();
      if(LblRamCellTstResult != RAMTST_ONE)
      {
        /* Block Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_FAILED;

        /* Global Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blGblBckGrdTstError = RAMTST_FAILED;

        /* If atleast one Cell fails the Block status changed to NOT_OK */
        *RamTst_GaaBlkParam[LddBlockIdx].pTestBlockStatus =
                                                      RAMTST_RESULT_NOT_OK;

        #if(RAMTST_DEMERROR_REPORT == STD_ON)
        /* Raise DEM Error and set the RamTst_GddTestStatus to Failed */
        Dem_ReportErrorStatus(RamTst_GusRamFailure, DEM_EVENT_STATUS_FAILED);
        #endif

        #if(RAMTST_TEST_ERROR_NOTIFICATION_SUPPORT == STD_ON)
        /* CallErrorNotification API */
        RAMTST_TEST_ERROR_NOTIFICATION();
        #endif
      }
      else
      {
        /* Block Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_PASSED;
      }

      /* Move to Next Cell */
      /* Point to next data byte */
      LpAddress=&LpAddress[RAMTST_ONE];
      /* Decrement Cell Count */
      NumOfCells--;
    }
    else
    {
      #if(RAMTST_DEV_ERROR_DETECT == STD_ON)
      /* Report to DET */
      (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
      RAMTST_PATTERNCHKBCKGRDTST_SID, RAMTST_E_STATUS_FAILURE);
      #endif
      NumOfCells = RAMTST_ZERO;
    }
  }while (NumOfCells != RAMTST_ZERO);

  /* Save the Next Address */
  /* polyspace-begin ISO-17961:intptrconv [Justified:Low] "Function must convert from pointer type to unsigned integer (address) to handle memory" */
  RamTst_GddBckGrdTstRamVar.pBckGrdAddress = LpAddress;
  /* polyspace-end ISO-17961:intptrconv [Justified:Low] "Function must convert from pointer type to unsigned integer (address) to handle memory" */
  return LblRamCellTstResult;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_RunPatternChk                                **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get parity of number Ramcell.           **
**                        It returns RAMTST_PASSED if test is correct         **
**                        It returns RAMTST_FAILED if test is wrong           **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : RamTst_NumberOfBlocksType                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GaaBlkParam         **
**                        Function(s) invoked    : None                       **
**                                                                            **
*******************************************************************************/
#if(RAMTST_MEDIUM_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_RunPatternChk(
                                       RamTst_NumberOfBlocksType RamTstBlockId)
{
  uint8 LucParaId;

  uint32 LulEndAddr;
  boolean LblRamCellTstResult;
  RamTst_CellType* LpAddress;

  LucParaId = (uint8)RamTstBlockId - RAMTST_ONE;
  LblRamCellTstResult = RAMTST_FAILED;

  if (LucParaId < RamTst_GulNumberOfBlocks)
  {
    LpAddress =
            RamTst_GaaBlkParam[LucParaId].pRamTstStartAddress;
    LulEndAddr = RamTst_GaaBlkParam[LucParaId].ulRamTstEndAddress;
    do
    {
      /* Invoke Pattern check API */
      LblRamCellTstResult = RamTst_PatternChk(LpAddress,
         RamTst_GaaBlkParam[LucParaId].ddRamTstPolicy,
         RamTst_GaaBlkParam[LucParaId].ulRamTstFillPattern);
      if(LblRamCellTstResult == RAMTST_ONE)
      {
        LblRamCellTstResult = RAMTST_PASSED;
        /* Point to next data byte */
        LpAddress=&LpAddress[RAMTST_ONE];
      }
      else
      {
        LblRamCellTstResult = RAMTST_FAILED;
        break;
      }

    } while ((uint32)LpAddress < LulEndAddr);
  }
  else
  {
    #if(RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
    RAMTST_RUNPATTERNCHK_SID, RAMTST_E_STATUS_FAILURE);
    #endif
  }
  return LblRamCellTstResult;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_RunCrcTst                                    **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get CRC of Block.                       **
**                        It returns RAMTST_PASSED if parity is correct       **
**                        It returns RAMTST_FAILED if parity is wrong         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : uint16                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GaaBlkParam         **
**                                                                            **
**                        Function(s) invoked    :                            **
**                                                 RamTst_CalculateCRC8       **
**                                                 RamTst_CalculateCRC8H2F    **
**                                                 RamTst_CalculateCRC16      **
**                                                 RamTst_CalculateCRC32      **
*******************************************************************************/
#if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_RunCrcTst
                                       (RamTst_NumberOfBlocksType RamTstBlockId)
{
  uint8 blockIdx;
  boolean ramCellTstResult;
  
  P2VAR(uint8, AUTOMATIC, RAMTST_APPL_DATA) pStartAddress_U8;    
  P2VAR(RamTst_CrcSizeType, AUTOMATIC, RAMTST_APPL_DATA) pEndAddress_CrcSize;  

  uint32 ramBlockSize;
  RamTst_CrcSizeType ramBlockCalCrc_CrcSize;

  ramCellTstResult = RAMTST_FAILED;
  blockIdx = (uint8)RamTstBlockId - RAMTST_ONE;
  if (blockIdx < RamTst_GulNumberOfBlocks)
  {
    if (NULL_PTR != RamTst_GaaBlkParam[blockIdx].pRamTstCrcStartAddress_U8)
    {
      pStartAddress_U8 = RamTst_GaaBlkParam[blockIdx].pRamTstCrcStartAddress_U8;
      pEndAddress_CrcSize = RamTst_GaaBlkParam[blockIdx].pRamTstCrcEndAddress_CrcSize;
      
      ramBlockSize = (uint32)pEndAddress_CrcSize - (uint32)pStartAddress_U8;
      ramBlockCalCrc_CrcSize = RAMTST_CALCULATE_CRC(pStartAddress_U8, ramBlockSize,
                                          RAMTST_CRC_INITIAL_VALUE, (boolean)RAMTST_TRUE);
      /* fetch the CRC Calculated from the End of Block. 
       * Type of pRamTstCrcEndAddress_CrcSize is RamTst_CrcSizeType */
      if(ramBlockCalCrc_CrcSize == *pEndAddress_CrcSize)
      {
        ramCellTstResult = RAMTST_PASSED;
      }
      else
      {
        ramCellTstResult = RAMTST_FAILED;
      }
    }
    else
    {
      RAMTST_REPORT_ERROR(RAMTST_RUNCRCTST_SID, RAMTST_E_STATUS_FAILURE);
    }
  }
  else
  {
    RAMTST_REPORT_ERROR(RAMTST_RUNCRCTST_SID, RAMTST_E_STATUS_FAILURE);
  }

  return ramCellTstResult;
}
#endif
/*******************************************************************************
** Function Name        : RamTst_CrcBckGrdTst                                 **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Function to get CRC of Block.                       **
**                        It returns RAMTST_PASSED if parity is correct       **
**                        It returns RAMTST_FAILED if parity is wrong         **
**                                                                            **
** Sync/Async           : Synchronous                                         **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : uint16                                              **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : boolean                                             **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                RamTst_GddBckGrdTstRamVar   **
**                                                RamTst_GaaBlkParam          **
**                        Function(s) invoked    :                            **
**                                                 RamTst_CalculateCRC8       **
**                                                 Dem_ReportErrorStatus      **
**                                                 RamTst_CalculateCRC8H2F    **
**                                                 RamTst_CalculateCRC16      **
**                                                 RamTst_CalculateCRC32      **
*******************************************************************************/
#if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON)
FUNC(boolean, RAMTST_CODE) RamTst_CrcBckGrdTst(uint8 *RamTstStrtAddress,
                                RamTst_NumberOfTestedCellsType RamTstNumOfCells)
{
  boolean ramCellTstResult;
  uint8* pStartAddress_U8;
  uint32 ramBlockSize;
  boolean crcIsFirstCall;
  RamTst_NumberOfTestedCellsType blockIdx;
  RamTst_CrcSizeType ramBlockCalCrc_CrcSize;

  pStartAddress_U8 = RamTstStrtAddress;
  ramCellTstResult = RAMTST_FAILED;

  /* in case CRC, RamTstNumOfCells is count in bytes */
  ramBlockSize = RamTstNumOfCells;
  blockIdx = (uint32)RamTst_GddBckGrdTstRamVar.ddRunningBlockID -  RAMTST_ONE;
  
  if ((NULL_PTR != pStartAddress_U8) && (blockIdx < RamTst_GulNumberOfBlocks))
  {
    if(pStartAddress_U8 != RamTst_GaaBlkParam[blockIdx].pRamTstCrcStartAddress_U8)
    {
      crcIsFirstCall = (boolean)RAMTST_FALSE;
    }
    else
    {
      crcIsFirstCall = (boolean)RAMTST_TRUE;
    }
    ramBlockCalCrc_CrcSize = RAMTST_CALCULATE_CRC(pStartAddress_U8, ramBlockSize,
                  RamTst_GddBckGrdTstRamVar.CrcInitialVal, crcIsFirstCall);

    /* Type of CrcInitialVal is RamTst_CrcSizeType */
    RamTst_GddBckGrdTstRamVar.CrcInitialVal = ramBlockCalCrc_CrcSize;
    
    /* Note
     * Because CRC is calculated in bytes, pAddress_u8 must be uint8 type.
     * LulRamBlockSize is also in bytes.
     *
     * CRC calculated till this address
     * */
    pStartAddress_U8 = &pStartAddress_U8[ramBlockSize];

    /* Save the Next Address */
    RamTst_GddBckGrdTstRamVar.pBckGrdCrcAddress_U8 = pStartAddress_U8;

    /* Block Finished Condition */
    if((uint32)pStartAddress_U8 == (uint32)RamTst_GaaBlkParam[blockIdx].pRamTstCrcEndAddress_CrcSize)
    {
      /* fetch the CRC Calculated from the End of Block. 
       * pRamTstCrcEndAddress_CrcSize is CrcCellType */
      if(ramBlockCalCrc_CrcSize == *RamTst_GaaBlkParam[blockIdx].pRamTstCrcEndAddress_CrcSize)
      {
        ramCellTstResult = RAMTST_PASSED;
        /* Block Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_PASSED;
      }
      else
      {
        ramCellTstResult = RAMTST_FAILED;
        /* Block Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError = RAMTST_FAILED;

        /* Global Test Status is Failed */
        RamTst_GddBckGrdTstRamVar.blGblBckGrdTstError = RAMTST_FAILED;

        /* If atleast one Cell fails the Block status changed to NOT_OK */
        *RamTst_GaaBlkParam[blockIdx].pTestBlockStatus =
                                                      RAMTST_RESULT_NOT_OK;

#if(RAMTST_DEMERROR_REPORT == STD_ON)
        /* Raise DEM Error and set the RamTst_GddTestStatus to Failed */
        Dem_ReportErrorStatus(RamTst_GusRamFailure, DEM_EVENT_STATUS_FAILED);
#endif

#if(RAMTST_TEST_ERROR_NOTIFICATION_SUPPORT == STD_ON)
        /* CallErrorNotification API */
        RAMTST_TEST_ERROR_NOTIFICATION();
#endif
      }
    }
  }
  else
  {
#if(RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
    RAMTST_CRCBCKGRDTST_SID, RAMTST_E_STATUS_FAILURE);
#endif
  }

  return ramCellTstResult;
}
#endif

/*******************************************************************************
** Function Name        : RamTst_SetBlockResult                               **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Internal Function to set the block test status      **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : None                                                **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GddBckGrdTstRamVar  **
**                                                 RamTst_GaaBlkParam         **
**                        Function(s) invoked    :                            **
**                                                                            **
*******************************************************************************/
FUNC(void, RAMTST_CODE) RamTst_SetBlockResult(void)
{
  RamTst_NumberOfBlocksType LddBlkID;

  LddBlkID = RamTst_GddBckGrdTstRamVar.ddRunningBlockID - RAMTST_ONE;
  if (LddBlkID < RamTst_GulNumberOfBlocks)
  {
    if((RamTst_GddBckGrdTstRamVar.blBlkBckGrdTstError != RAMTST_FAILED) &&
    (*RamTst_GaaBlkParam[LddBlkID].pTestBlockStatus != RAMTST_RESULT_NOT_OK))
    {
      /* Set the Block Status to OK */
      *RamTst_GaaBlkParam[LddBlkID].pTestBlockStatus = RAMTST_RESULT_OK;
    }
    else
    {
      /* Set the Block Status to OK */
      *RamTst_GaaBlkParam[LddBlkID].pTestBlockStatus = RAMTST_RESULT_NOT_OK;
    }
  }
  else
  {
    #if(RAMTST_DEV_ERROR_DETECT == STD_ON)
    /* Report to DET */
    (void)Det_ReportError(RAMTST_MODULE_ID, RAMTST_INSTANCE_ID,
    RAMTST_SETBLOCKRESULT_SID, RAMTST_E_STATUS_FAILURE);
    #endif
  }
}

/*******************************************************************************
** Function Name        : RamTst_SetOverAllResult                             **
**                                                                            **
** Service ID           : None                                                **
**                                                                            **
** Description          : Internal Function to set the over all test status   **
**                                                                            **
** Sync/Async           : NA                                                  **
**                                                                            **
** Re-entrancy           : Non-Reentrant, Non-Interruptible                   **
**                                                                            **
** Input Parameters     : RamTst_NumberOfBlocksType                           **
**                                                                            **
** InOut parameter      : None                                                **
**                                                                            **
** Output Parameters    : None                                                **
**                                                                            **
** Return parameter     : None                                                **
**                                                                            **
** Preconditions        : The Ram Test module must be initialized             **
**                                                                            **
** Remarks              : Global Variable(s)     :                            **
**                                                 RamTst_GddBckGrdTstRamVar  **
**                                                 RamTst_GaaBlkParam         **
**                                                 RamTst_GddTestStatus       **
**                        Function(s) invoked    : None                       **
**                                                                            **
*******************************************************************************/
FUNC(void, RAMTST_CODE) RamTst_SetOverAllResult
                                             (RamTst_NumberOfBlocksType BlockId)
{
  /* Restart from Starting of Block */
  RamTst_GddBckGrdTstRamVar.ddRunningBlockID = BlockId;

  /* Starting Block Size */
  RamTst_GddBckGrdTstRamVar.ddBalNumOfCells =
                  RamTst_GaaBlkParam[BlockId - RAMTST_ONE].ulRamBlockSize;
  RamTst_GddBckGrdTstRamVar.pBckGrdAddress =
                  RamTst_GaaBlkParam[BlockId - RAMTST_ONE].pRamTstStartAddress;
#if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON)
    RamTst_GddBckGrdTstRamVar.pBckGrdCrcAddress_U8 =
                  RamTst_GaaBlkParam[BlockId - RAMTST_ONE].pRamTstCrcStartAddress_U8;
#endif

  if(RamTst_GddBckGrdTstRamVar.blGblBckGrdTstError != RAMTST_FAILED)
  {
    #if(RAMTST_TEST_COMPLETED_NOTIFICATION_SUPPORT == STD_ON)
    /* If No error Indicated then Call Test Completed Notification */
    RAMTST_TEST_COMPLETED_NOTIFICATION();
    #endif
    RamTst_GddTestStatus = RAMTST_RESULT_OK;
  }
  else
  {
    /* If atleast one cell fails the overall result set to NOT_OK */
    RamTst_GddTestStatus = RAMTST_RESULT_NOT_OK;
  }
}

#define RAMTST_STOP_SEC_CODE
#include "MemMap.h"

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */

/* polyspace-end MISRA-C:11.3 [Justified:Low] "No Impact of this rule violation (uint8 data needs to be extracted from a uint32 address. the code is verified manually)" */
/*
polyspace:end<RTE: NIV : Not a defect : Justify with annotations > Cannot initialize because of Application variable
polyspace:end<RTE: IDP : Not a defect : Justify with annotations > configured memory access index
*/

/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
