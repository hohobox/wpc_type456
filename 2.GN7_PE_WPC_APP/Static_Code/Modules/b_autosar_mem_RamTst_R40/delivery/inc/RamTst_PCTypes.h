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
**  SRC-MODULE: RamTst_PCTypes.h                                              **
**                                                                            **
**  TARGET    : All                                                           **
**                                                                            **
**  PRODUCT   : AUTOSAR RamTst                                                **
**                                                                            **
**  PURPOSE   : Provision of pre-compile time parameters                      **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: no                                           **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/

/*******************************************************************************
**                      Revision History                                      **
********************************************************************************
** Revision  Date          By     Description                                 **
********************************************************************************
** 1.3.5     19-Aug-2022   YJ Yun           Redmine #36918                    **
** 1.2.5     16-May-2016   CY Song          RedMine #4902                     **
** 1.0.0     07-Jun-2013   CY Song          Initial Version                   **
*******************************************************************************/

#ifndef RAMTST_PCTYPES_H
#define RAMTST_PCTYPES_H
/*******************************************************************************
**              PRE-JUSTIFICATION BEGIN (MISRA-C RULE CHECKER)                **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.4 [Justified:Low] "Not a defect" */
/*
  polyspace:begin<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/
/* polyspace-begin MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */

/*******************************************************************************
**                      Include Section                                       **
*******************************************************************************/
#include "ComStack_Types.h"
#include "RamTst_Types.h"

/*******************************************************************************
**                       Global Data                                          **
*******************************************************************************/
/* polyspace-begin MISRA-C3:2.2 [Justified:Low] "Not a defect" */

/* Structure for configuring an algorithm */
typedef struct STag_RamTst_AlgParams
{

  /* Coverage of the defined RamTstAlgParams set */
  RamTst_AlgorithmType  ddRamTstAlgCoverage;

  /* Absolute maximum value for the number of cells that
   * NUMBER_OF_TESTED_CELLS and MAX_NUMBER_OF_TESTED_CELLS can be.
   */
  uint32 ulRamTstExtNumberOfTestedCells;

  /* maximum value for the number of cells that can be tested in one
   * cycle of a background test.
   */
  uint32 ulRamTstMaxNumberOfTestedCells;

  /* Initial value for a RAM variable, which can be changed by the function
   * "RamTst_ChangeNumberOfTestedCells"
   */
  uint32 ulRamTstNumberOfTestedCells;

  /* Number of RAM blocks configured */
  /* calculationFormula = Count of RamTstBlockParams contained in this
   * RamTstAlgParams container
   */
  uint16 usRamTstNumberOfBlocks;

  /* Index to the start of RamTest Blocks */
  uint16 usRamTstBlkIndex;

  /* Test Algorithm Parameter ID */
  uint8 ucRamTstAlgParamsId;

}RamTst_AlgParams;

/* Structure for block of RAM */
typedef struct STag_RamTst_BlockParams
{
  /* Pointer to Ram block status variable */
  P2VAR(RamTst_TestResultType, AUTOMATIC, RAMTST_CONFIG_DATA) pTestBlockStatus;

  /* Policy regarding destruction or non-destruction of memory content */
  RamTstTestPolicy ddRamTstPolicy;

  /* Block Start Address */
  P2VAR(RamTst_CellType, AUTOMATIC, RAMTST_CONFIG_DATA)  pRamTstStartAddress;

  /* Block End Address */
  uint32 ulRamTstEndAddress;

/* #if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON) */
  P2VAR(uint8, AUTOMATIC, RAMTST_CONFIG_DATA)  pRamTstCrcStartAddress_U8;
  
  P2VAR(RamTst_CrcSizeType, AUTOMATIC, RAMTST_CONFIG_DATA) pRamTstCrcEndAddress_CrcSize;
/* #endif*/

  /* Size of the Block  */
  /* (ulRamTstEndAddress - pRamTstStartAddress)/Ram Cell Size */
  uint32 ulRamBlockSize;

  /* Pattern to be filled into each memory cell after
   * destructive test of this block
   */
  /* Applicable only if destructive Mode is ON */
  uint32 ulRamTstFillPattern;

  /* ID of the RAM block */
  uint16 usRamTstBlockId;

}RamTst_BlockParams;

/* Structure for configuring an algorithm */
typedef struct STag_RamTst_BckGrdCrcRamVar
{
  /* Current BlockID */
  RamTst_NumberOfBlocksType ddRunningBlockID;

  /* Pending Number of Cells to be tested */
  RamTst_NumberOfTestedCellsType ddBalNumOfCells;

  /* Address Location from which the testing should continued */
  RamTst_CellType *pBckGrdAddress;

#if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON)
  uint8* pBckGrdCrcAddress_U8;
#endif

  /* Error Flag */
  boolean blBlkBckGrdTstError;

  /* Error Flag */
  boolean blGblBckGrdTstError;

#if(RAMTST_HIGH_COVERAGE_TEST_SELECTED == STD_ON)
  RamTst_CrcSizeType CrcInitialVal;
#endif

} RamTst_BckGrdCrcRamVar;

#define RAMTST_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array for Blocks */
extern CONST(RamTst_BlockParams, RAMTST_CONST)
                                        RamTst_GaaBlkParam[];
#define RAMTST_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

#define RAMTST_START_SEC_CONST_UNSPECIFIED
#include "MemMap.h"
/* Array for Algorithm Parameter */
extern CONST(RamTst_AlgParams, RAMTST_CONST)
                            RamTst_GaaAlgParam[];
#define RAMTST_STOP_SEC_CONST_UNSPECIFIED
#include "MemMap.h"

/*******************************************************************************
**                      Function Prototypes                                   **
*******************************************************************************/
/* polyspace-end MISRA-C3:20.1 [Not a defect:Low] "It is implemented according to autosar specification" */

/*******************************************************************************
**               PRE-JUSTIFICATION END (MISRA-C RULE CHECKER)                 **
*******************************************************************************/
/*
  polyspace:end<MISRA-C:8.12:Not a defect:Justify with annotations> No Impact of this rule violation
*/
/* polyspace-end MISRA-C3:2.2 [Justified:Low] "Not a defect" */
/* polyspace-end MISRA-C3:2.4 [Justified:Low] "Not a defect" */

#endif /* RAMTST_PCTYPES_H */
/*******************************************************************************
**                      End of File                                           **
*******************************************************************************/
